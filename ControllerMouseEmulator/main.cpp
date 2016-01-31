#include <iostream>
#include "mouseInput.h"
#include "gamepad.h"

#define MAX_MOUSE_SPEED	20.0f
#define SPEED_INCREMENT	5.0f

int main(int argc, char ** argv) {
	std::cout << "Starting Controller Mouse Emulator" << std::endl;

	float mouseSpeed = 15;
	float scrollSpeed = 25;

	MouseInput mouseInput;
	Gamepad gamepad;
	int dx, dy;
	int sy;

	while (true) {
		gamepad.update();

		dx = (int)(gamepad.getLThumbX() * mouseSpeed);
		dy = (int)(-gamepad.getLThumbY() * mouseSpeed);

		sy = (int)(gamepad.getRThumbY() * scrollSpeed);

		mouseInput.moveMouse(dx, dy);
		mouseInput.scrollWheel(sy);

		if (gamepad.aPressed())
			mouseInput.setLeftMouseDown(true);
		else if (gamepad.aReleased())
			mouseInput.setLeftMouseDown(false);

		if (gamepad.bPressed())
			mouseInput.setRightMouseDown(true);
		else if (gamepad.bReleased())
			mouseInput.setRightMouseDown(false);

		if (gamepad.rsPressed())
			mouseInput.setMiddleMouseDown(true);
		else if (gamepad.rsReleased())
			mouseInput.setMiddleMouseDown(false);

		if (gamepad.rbPressed() && mouseSpeed < MAX_MOUSE_SPEED) {
			mouseSpeed += SPEED_INCREMENT;
			std::cout << "Mouse speed: " << mouseSpeed << std::endl;
		}

		if (gamepad.lbPressed() && mouseSpeed > SPEED_INCREMENT) {
			mouseSpeed -= SPEED_INCREMENT;
			std::cout << "Mouse speed: " << mouseSpeed << std::endl;
		}

		gamepad.updateInput();

		Sleep(15);
	}

	return 0;
}