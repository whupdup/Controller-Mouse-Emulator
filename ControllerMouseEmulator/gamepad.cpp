#include "gamepad.h"
#include <cmath>

#define MAX_THUMBSTICK	32767
#define MIN_THUMBSTICK	0.015f

Gamepad::Gamepad() : Gamepad(0) {}

Gamepad::Gamepad(int inputNum) {
	this->inputNum = inputNum;

	lastA = false;
	lastB = false;
	lastX = false;
	lastY = false;
	lastLB = false;
	lastRB = false;
	lastLStick = false;
	lastRStick = false;
}

void Gamepad::update() {
	ZeroMemory(&state, sizeof(XINPUT_STATE));
	XInputGetState(inputNum, &state);

	lThumbX = (float)state.Gamepad.sThumbLX / MAX_THUMBSTICK;
	lThumbY = (float)state.Gamepad.sThumbLY / MAX_THUMBSTICK;

	rThumbX = (float)state.Gamepad.sThumbRX / MAX_THUMBSTICK;
	rThumbY = (float)state.Gamepad.sThumbRY / MAX_THUMBSTICK;

	if (abs(lThumbX) <= MIN_THUMBSTICK)
		lThumbX = 0;
	if (abs(lThumbY) <= MIN_THUMBSTICK)
		lThumbY = 0;

	if (abs(rThumbX) <= MIN_THUMBSTICK)
		rThumbX = 0;
	if (abs(rThumbY) <= MIN_THUMBSTICK)
		rThumbY = 0;
}

void Gamepad::updateInput() {
	lastA = aDown();
	lastB = bDown();
	lastX = xDown();
	lastY = yDown();
	lastLB = lbDown();
	lastRB = rbDown();
	lastLStick = lsDown();
	lastRStick = rsDown();
}

bool Gamepad::aPressed() {
	return !lastA && aDown();
}

bool Gamepad::bPressed() {
	return !lastB && bDown();
}

bool Gamepad::xPressed() {
	return !lastX && xDown();
}

bool Gamepad::yPressed() {
	return !lastY && yDown();
}

bool Gamepad::lbPressed() {
	return !lastLB && lbDown();
}

bool Gamepad::rbPressed() {
	return !lastRB && rbDown();
}

bool Gamepad::lsPressed() {
	return !lastLStick && lsDown();
}

bool Gamepad::rsPressed() {
	return !lastRStick && rsDown();
}

bool Gamepad::aDown() {
	return (state.Gamepad.wButtons & XINPUT_GAMEPAD_A) != 0;
}

bool Gamepad::bDown() {
	return (state.Gamepad.wButtons & XINPUT_GAMEPAD_B) != 0;
}

bool Gamepad::xDown() {
	return (state.Gamepad.wButtons & XINPUT_GAMEPAD_X) != 0;
}

bool Gamepad::yDown() {
	return (state.Gamepad.wButtons & XINPUT_GAMEPAD_Y) != 0;
}

bool Gamepad::lbDown() {
	return (state.Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_SHOULDER) != 0;
}

bool Gamepad::rbDown() {
	return (state.Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_SHOULDER) != 0;
}

bool Gamepad::lsDown() {
	return (state.Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_THUMB) != 0;
}

bool Gamepad::rsDown() {
	return (state.Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_THUMB) != 0;
}

bool Gamepad::aReleased() {
	return lastA && !aDown();
}

bool Gamepad::bReleased() {
	return lastB && !bDown();
}

bool Gamepad::xReleased() {
	return lastX && !xDown();
}

bool Gamepad::yReleased() {
	return lastY && !yDown();
}

bool Gamepad::lbReleased() {
	return lastLB && !lbDown();
}

bool Gamepad::rbReleased() {
	return lastRB && !rbDown();
}

bool Gamepad::lsReleased() {
	return lastLStick && !lsDown();
}

bool Gamepad::rsReleased() {
	return lastRStick && !rsDown();
}

float Gamepad::getLThumbX() {
	return lThumbX;
}

float Gamepad::getLThumbY() {
	return lThumbY;
}

float Gamepad::getRThumbX() {
	return rThumbX;
}

float Gamepad::getRThumbY() {
	return rThumbY;
}