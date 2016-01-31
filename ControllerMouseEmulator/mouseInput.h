#ifndef MOUSEINPUT_H
#define MOUSEINPUT_H

#define WINVER 0x0500
#include <Windows.h>

class MouseInput {
	public:
		MouseInput();

		void moveMouse(int, int);
		void scrollWheel(int);

		void setLeftMouseDown(bool);
		void setRightMouseDown(bool);
		void setMiddleMouseDown(bool);
	private:
		INPUT input;
		POINT mousePos;
};

#endif