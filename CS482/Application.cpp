#include "stdafx.h"
#include "Application.h"

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
	/*m_pWorld.reset(new World);
	
	m_pWindow->Initialize();
	m_pWindow->SetApplication(this);
	m_pWorld->m_Object.push_back(new MeshObject("res/mesh.obj", "res/mesh.bmp", true));
	m_pWorld->m_Object.push_back(new Domino);

	m_pSimulator.reset(new SimulationRenderer);
	m_pView.reset(new ViewRenderer);

	m_Renderer.push_back(m_pSimulator.get());
	m_Renderer.push_back(m_pView.get());

	for(auto it = m_Renderer.begin(); it != m_Renderer.end(); it++)
	{
		(*it)->Register(m_pWorld, m_pWindow);
		(*it)->Initialize();
	}*/
}


void Application::Run()
{
	do
	{
		for(auto it = m_Renderer.begin(); it != m_Renderer.end(); it++)
		{
			(*it)->Render();
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