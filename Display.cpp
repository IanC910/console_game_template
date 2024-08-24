
#include <string>
#include <cstdlib>

#include "Display.h"

Display::Display(int width, int height) {
    this->width = width;
    this->height = height;

    screenArray = new wchar_t[width * height];
    consoleHandle = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);

    setBlank();
}

void Display::activate() {
    SetConsoleActiveScreenBuffer(consoleHandle);
}

int Display::getHeight() {
    return height;
}

int Display::getWidth() {
    return width;
}

bool Display::isPointOnScreen(int row, int col) {
    return row < height && row >= 0 && col < width && col >= 0;
}

void Display::write(int row, int col, wchar_t symbol) {
    if(isPointOnScreen(row, col)) {
        screenArray[width * row + col] = symbol;
    }
}

void Display::write(int row, int col, std::string s) {
    for (int j = 0; j < s.size(); j++) {
        this->write(row, col + j, s[j]);
    }
}

void Display::setBlank() {
    memset(screenArray, 0, (width * height) * sizeof(wchar_t));
}

void Display::update() {
    screenArray[width * height - 1] = '\0';
    DWORD numBytesWritten = 0;
    WriteConsoleOutputCharacter(consoleHandle, screenArray, width * height, {0, 0}, &numBytesWritten);
}