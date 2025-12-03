#pragma once
#include <winsock2.h>
#include "windows.h"

enum Color {
    WHITE = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,
    GRAY = FOREGROUND_INTENSITY
};
