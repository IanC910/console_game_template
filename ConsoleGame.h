#pragma once

#include "Display.h"

class ConsoleGame {
public:
	ConsoleGame(int width, int height);

	void run();
	void mainMenu();
	void mainGameLoop();

private:
	double deltaTime = 0;

	Display* display = nullptr;

	enum gameState_t {
		MAIN_MENU,
		MAIN_GAME_LOOP,
		QUITTING
	} gameState = MAIN_MENU;
};

