#ifndef WINDOW_H
#define WINDOW_H
#include "stdafx.h"
class Window {
private:
	std::unique_ptr<GLFWwindow> m_pWindow;
public:
	Window();
	void swapBuffers();
};
#endif