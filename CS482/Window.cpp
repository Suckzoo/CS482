#include "stdafx.h"
#include "Window.h"

#include "Application.h"
#include <GL/glfw3.h>


Window::Window()
	: m_pGLFWWindow(NULL),
	m_pApplication(NULL)
{
	GLenum value;

	//Initialize GLFW
	if(!glfwInit()) {
		throw std::exception("Failed to initialize GLFW\n");
	}
	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_RESIZABLE,GL_FALSE);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Open a window and create its OpenGL context
	m_pGLFWWindow = glfwCreateWindow(m_dWidth, m_dHeight, "Television Teleport", NULL, NULL);
	if(m_pGLFWWindow == NULL)
	{
		throw std::exception("Failed to initialize window");
	}
	glfwMakeContextCurrent(m_pGLFWWindow);
	glewExperimental = true; // Needed for core profile
	value = glewInit();
	if(value != GLEW_OK)
	{
		fprintf(stderr, "Failed to initialize GLEW: %s\n", glewGetErrorString(value));
		throw std::runtime_error("Fuck you!");
	}
	glfwSetWindowUserPointer(m_pGLFWWindow, this);
	glfwSetKeyCallback(m_pGLFWWindow, OnKeyEvent);
	glfwSetMouseButtonCallback(m_pGLFWWindow, OnMouseEvent);
	glfwSetCursorPosCallback(m_pGLFWWindow, OnCursorEvent);
}


Window::~Window()
{
}


void Window::Initialize()
{
	//glfwSwapInterval(1);
	glClearColor(0.5f, .5f, .5f, 1.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	glEnable(GL_CULL_FACE);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}


void Window::SwapBuffers()
{
	glfwSwapBuffers(m_pGLFWWindow);
}


int Window::GetKey(int key)
{
	return glfwGetKey(m_pGLFWWindow, key);
}


int Window::ShouldClose()
{
	return glfwWindowShouldClose(m_pGLFWWindow);
}


void Window::OnKeyEvent(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	Window *ptr;

	ptr = (Window *)glfwGetWindowUserPointer(window);
	ptr->GetApplication()->DispatchKeyEvent(key, scancode, action, mods);
}


void Window::OnMouseEvent(GLFWwindow* window, int button, int action, int mods)
{
	Window *ptr;

	ptr = (Window *)glfwGetWindowUserPointer(window);
	ptr->GetApplication()->DispatchMouseEvent(button, action, mods);
}


void Window::OnCursorEvent(GLFWwindow* window, double xoffset, double yoffset)
{
	Window *ptr;

	ptr = (Window *)glfwGetWindowUserPointer(window);
	ptr->GetApplication()->DispatchCursorEvent((int)xoffset, (int)yoffset);
}