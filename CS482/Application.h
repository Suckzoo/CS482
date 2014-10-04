#ifndef APPLICATION_H
#define APPLICATION_H
#include "stdafx.h"
#include "Window.h"
class Application {
private:
	std::shared_ptr<Window> m_pWindow;
public:
	Application();
	void run();
};
#endif