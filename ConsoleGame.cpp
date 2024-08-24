
#include <iostream>
#include <chrono>
#include <cstdlib>
#include <string>
#include <Windows.h>

#include "Display.h"

#include "ConsoleGame.h"

ConsoleGame::ConsoleGame(int width, int height) {
    display = new Display(width, height);
}

void ConsoleGame::run() {
    display->activate();

    while (true) {
        switch (gameState) {
        case MAIN_MENU:
            mainMenu();
            break;

        case MAIN_GAME_LOOP:
            mainGameLoop();
            break;

        case QUITTING:
            return;

        default:
            return;
        }
    }
}

void ConsoleGame::mainMenu() {
    display->setBlank();

    while (gameState == MAIN_MENU) {
        int screenHeight = display->getHeight();
        int screenWidth = display->getWidth();

        display->write(screenHeight / 2 + 0, screenWidth / 2 - 2,   "Game");
        display->write(screenHeight / 2 + 1, screenWidth / 2 - 11,  "Press 'Enter' to Start");
        display->write(screenHeight / 2 + 2, screenWidth / 2 - 8,   "Press 'Q' to Quit");

        if (GetAsyncKeyState(VK_RETURN)) {
            gameState = MAIN_GAME_LOOP;
            return;
        }

        if (GetAsyncKeyState('Q')) {
            gameState = QUITTING;
            return;
        }

        display->update();
    }
}

void ConsoleGame::mainGameLoop() {
    display->setBlank();

    while (gameState == MAIN_GAME_LOOP) {
        auto timeStart = std::chrono::system_clock::now();

        if (GetAsyncKeyState(VK_ESCAPE)) {
            gameState = MAIN_MENU;
            return;
        }







        display->update();

        auto timeEnd = std::chrono::system_clock::now();
        long long deltaTimeUs = std::chrono::duration_cast<std::chrono::microseconds>(timeEnd - timeStart).count();
        deltaTime = (double)deltaTimeUs / 1000000.0f;
    }
}

