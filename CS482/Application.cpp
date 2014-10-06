#include "stdafx.h"
#include "Application.h"
#include "Program.h"

#include <GL/glfw3.h>
#include <glm/matrix.hpp>
#include <glm/gtc/matrix_transform.hpp>

Application::Application()
	: m_fCursorx(0),
	m_fCursory(0)
{
}


Application::~Application()
{
}


void Application::Initialize()
{
	m_pWindow.reset(new Window);
	m_pWorld.clear();
	Program* realProgram = new Program("RealWorldProgram.vertexshader","RealWorldProgram.fragmentshader");
	std::vector<std::string> names;
	names.push_back("VP");
	names.push_back("M");
	names.push_back("MITM");
	names.push_back("TextureSampler");
	realProgram->FindUniform(names);
	m_pPrograms["Real"] = realProgram;
	names.clear();
	Program* TVProgram = new Program("FrameBufferProgram.vertexshader","FrameBufferProgram.fragmentshader");
	m_pPrograms["InTV"] = TVProgram;
}


void Application::Run()
{
	do
	{
		for(auto it = m_pWorld.begin(); it != m_pWorld.end(); it++)
		{
			Room* r = *it;
			r->Render(m_pPrograms["Real"]);
		}
		m_pWindow->SwapBuffers();
		glfwPollEvents();
	} while(m_pWindow->GetKey(GLFW_KEY_ESCAPE) != GLFW_PRESS && !m_pWindow->ShouldClose());
}


void Application::DispatchKeyEvent(int key, int scancode, int action, int mods)
{
}


void Application::DispatchMouseEvent(int button, int action, int mods)
{
}


void Application::DispatchCursorEvent(int xoffset, int yoffset)
{
}