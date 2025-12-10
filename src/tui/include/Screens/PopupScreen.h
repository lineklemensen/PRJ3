#pragma once
#include "Route.h"
#include "Screen.h"


class PopupScreen : public Screen {
public:
    explicit PopupScreen(const Route& route);
    void print() override;
};
