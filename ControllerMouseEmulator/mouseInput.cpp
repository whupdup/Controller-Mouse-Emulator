#include "mouseInput.h"

MouseInput::MouseInput() {
	input.type = INPUT_MOUSE;
	input.mi.dx = 0;
	input.mi.dy = 0;
	input.mi.mouseData = 0;
	input.mi.dwFlags = MOUSEEVENTF_ABSOLUTE;
	input.mi.time = 0;
	input.mi.dwExtraInfo = 0;
}

void MouseInput::moveMouse(int dx, int dy) {
	GetCursorPos(&mousePos);

	mousePos.x += dx;
	mousePos.y += dy;

	SetCursorPos(mousePos.x, mousePos.y);
}

void MouseInput::scrollWheel(int speed) {
	input.mi.dwFlags = (MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_WHEEL);
	input.mi.mouseData = speed;

	SendInput(1, &input, sizeof(INPUT));
}

void MouseInput::setLeftMouseDown(bool mouseDown) {
	if (mouseDown)
		input.mi.dwFlags = (MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_LEFTDOWN);
	else
		input.mi.dwFlags = (MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_LEFTUP);

	SendInput(1, &input, sizeof(INPUT));
}

void MouseInput::setRightMouseDown(bool mouseDown) {
	if (mouseDown)
		input.mi.dwFlags = (MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_RIGHTDOWN);
	else
		input.mi.dwFlags = (MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_RIGHTUP);

	SendInput(1, &input, sizeof(INPUT));
}

void MouseInput::setMiddleMouseDown(bool mouseDown) {
	if (mouseDown)
		input.mi.dwFlags = (MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_MIDDLEDOWN);
	else
		input.mi.dwFlags = (MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_MIDDLEUP);

	SendInput(1, &input, sizeof(INPUT));
}