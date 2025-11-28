#include <iostream>
#include "LogHandler.h"
#include <restinio/all.hpp>
#include <json_dto/pub.hpp>

using route_collection_t = std::vector< LogHandler >;
namespace rr = restinio::router;
using router_t = rr::express_router_t<>;

//=========================*/
// HTTP handler class
//=========================*/
static LogHandler route_logger;

class RouteHandler
{
public:
	explicit RouteHandler(route_collection_t & routes)
		: m_routes(routes)
	{}

	auto on_get_route(const restinio::request_handle_t& req, rr::route_params_t) const
	{
		auto resp = init_resp(req->create_response());

		if (route_logger.queue_empty()) {
			resp.header().status_line(restinio::status_no_content());
			return resp.done();
		}

		std::string result = route_logger.get_route();

		resp.set_body(result);


		return resp.done();
	}

	auto on_post_route(const restinio::request_handle_t& req, rr::route_params_t) const
	{
		auto resp = init_resp(req->create_response());


		if (req->body().empty()) {
			resp.header().status_line(restinio::status_no_content());
			return resp.done();
		}

		route_logger.post_route(req->body());


		return resp.done();

	}

private:
	route_collection_t & m_routes;


	template < typename RESP >
	static RESP init_resp(RESP resp)
	{
		resp
			.append_header("Server", "RESTinio sample server /v.0.6")
			.append_header_date_field()
			.append_header("Content-Type", "text/plain; charset=utf-8");
		return resp;
	}

	static void mark_as_bad_request(auto & resp)
	{
		resp.header().status_line(restinio::status_bad_request());
	}
};

//=========================*/
// Router setup
//=========================*/
auto server_handler(route_collection_t & route_collection)
{
	auto router = std::make_unique<router_t>();
	auto handler = std::make_shared<RouteHandler>(std::ref(route_collection));

	auto by = [&](auto method) {
		using namespace std::placeholders;
		return std::bind(method, handler, _1, _2);
	};


	router->http_get("/get_route", by(&RouteHandler::on_get_route));

	router->http_post("/new_route", by(&RouteHandler::on_post_route));


	return router;
}

//=========================*/
// Main entry point
//=========================*/
int main()
{
	using namespace std::chrono;

	try
	{
		using traits_t = restinio::traits_t<
			restinio::asio_timer_manager_t,
			restinio::single_threaded_ostream_logger_t,
			router_t >;

		route_collection_t route{

		};

		//=========================*/
		// Run server
		// IMPORTANT:
		//   - "0.0.0.0" means server listens on ALL network interfaces.
		//   - Use Pi's IP + port 8080 to connect from another device.
		//=========================*/
		restinio::run(
			restinio::on_this_thread<traits_t>()
				.address("0.0.0.0")
				.port(8080)
				.request_handler(server_handler(route))
				.read_next_http_message_timelimit(10s)
				.write_http_response_timelimit(1s)
				.handle_request_timeout(1s));
	}
	catch(const std::exception & ex)
	{
		std::cerr << "Error: " << ex.what() << std::endl;
		return 1;
	}

	return 0;
}
