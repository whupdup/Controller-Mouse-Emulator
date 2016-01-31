#ifndef GAMEPAD_H
#define GAMEPAD_H

#include <Windows.h>
#include <XInput.h>

#pragma comment(lib, "XInput")

class Gamepad {
	public:
		Gamepad();
		Gamepad(int);

		void update();
		void updateInput();

		bool aPressed();
		bool bPressed();
		bool xPressed();
		bool yPressed();
		bool lbPressed();
		bool rbPressed();
		bool lsPressed();
		bool rsPressed();

		bool aDown();
		bool bDown();
		bool xDown();
		bool yDown();
		bool lbDown();
		bool rbDown();
		bool lsDown();
		bool rsDown();

		bool aReleased();
		bool bReleased();
		bool xReleased();
		bool yReleased();
		bool lbReleased();
		bool rbReleased();
		bool lsReleased();
		bool rsReleased();

		float getLThumbX();
		float getLThumbY();
		float getRThumbX();
		float getRThumbY();
	private:
		XINPUT_STATE state;
		int inputNum;

		bool lastA, lastB, lastX, lastY;
		bool lastLB, lastRB;
		bool lastLStick, lastRStick;

		float lThumbX, lThumbY;
		float rThumbX, rThumbY;
};

#endif