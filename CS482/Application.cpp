#include "Application.h"

Application::Application() :
	m_pWindow(0)
{
}
void Application::run() {
	m_pWindow.reset(new Window);
	while(1) {
		m_pWindow->swapBuffers();
		glfwPollEvents();
	}
}