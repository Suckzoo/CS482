#pragma once

#include "Window.h"
#include "Renderer.h"
#include <GL/glfw3.h>
//#include "World.h"
//#include "ViewRenderer.h"
//#include "SimulationRenderer.h"


class Application
{
protected:
	int m_fCursorx, m_fCursory;
	std::list<Renderer *> m_Renderer;
	//std::shared_ptr<World> m_pWorld;
	std::shared_ptr<Window> m_pWindow;
	//std::shared_ptr<SimulationRenderer> m_pSimulator;
	//std::shared_ptr<ViewRenderer> m_pView;

	//btCollisionWorld::ClosestRayResultCallback *PerformRayTest(double x, double y);

public:
	Application();
	~Application();
	void Initialize();
	void Run();
	void DispatchKeyEvent(int key, int scancode, int action, int mods);
	void DispatchMouseEvent(int button, int action, int mods);
	void DispatchCursorEvent(int xoffset, int yoffset);
};