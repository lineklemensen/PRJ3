#pragma once
#include <json_dto\pub.hpp>

//=========================*/
// Example data structure
//=========================*/
struct route_t
{
    route_t() = default;

    route_t(std::string author, std::string title)
        : m_author{ std::move(author) }, m_title{ std::move(title) }
    {}

    template < typename JSON_IO >
    void json_io(JSON_IO & io)
    {
        io
            & json_dto::mandatory("author", m_author)
            & json_dto::mandatory("title", m_title);
    }

    std::string m_author;
    std::string m_title;
};
