#pragma once

#include <Windows.h>
#include <string>

class Display {
public:

    Display(int width, int height);

    void activate();

    int getHeight();

    int getWidth();

    bool isPointOnScreen(int row, int col);

    void write(int row, int col, wchar_t symbol);

    void write(int row, int col, std::string);

    void setBlank();

    void update();

private:
    int width;
    int height;

    wchar_t* screenArray;
    HANDLE consoleHandle;
};

