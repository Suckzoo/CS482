#include "stdafx.h"
#include "Application.h"
#include "Program.h"
#include "Floor.h"
#include "Utility.h"
#include "Mesh.h"

#include <GL/glfw3.h>
#include <glm/matrix.hpp>
#include <glm/gtc/matrix_transform.hpp>

Room* chosenRoom;

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
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	m_pWindow.reset(new Window);
	m_pWorld.clear();
	Room* room = new Room();
	Camera* camera = new Camera();
	camera->setPosition(glm::vec3(0,0,0));
	camera->setDirection(glm::vec3(0,1,0));
	chosenRoom = room;
	chosenRoom->switchChoice();
	chosenRoom->setCamera(camera);
	room->AddObject(new Floor("D:\\Projects\\CS482\\CS482\\res\\floor.bmp"));
	m_pWorld.push_back(room);
	Program* realProgram = new Program("RealWorldProgram.vertexshader","RealWorldProgram.fragmentshader");
	m_pPrograms["Real"] = realProgram;
	std::vector<std::string> names;
	names.push_back("VP");
	names.push_back("M");
	names.push_back("MITM");
	names.push_back("myTexture");
	Mesh* m = new Mesh("D:\\Projects\\CS482\\CS482\\res\\cube.obj");
	m->setPosition(btVector3(0,0,3));
	chosenRoom->AddObject(m);
	realProgram->Use();
	realProgram->FindUniform(names);
	names.clear();
	//Program* TVProgram = new Program("FrameBufferProgram.vertexshader","FrameBufferProgram.fragmentshader");
	//m_pPrograms["InTV"] = TVProgram;
}


void Application::Run()
{
	do
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glClearColor(0.0f,0.4f,0.7f,1.0f);
		glfwSetCursorPos(m_pWindow->getWindow(),1024/2,768/2);
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
	if(action == GLFW_PRESS || action == GLFW_REPEAT) {
		Camera* camera = chosenRoom->getCamera();
		glm::vec3 posVector = camera->getDirection();
		glm::vec3 stepVector = glm::vec3(posVector.x,posVector.y,0);
		glm::vec3 perpVector = glm::vec3(-posVector.y,posVector.x,0);
		stepVector = glm::normalize(stepVector);
		perpVector = glm::normalize(perpVector);
		switch(key) {
		case 'W':
			camera->setPosition(camera->getPosition() + (stepVector*0.05f));
			break;
		case 'A':
			camera->setPosition(camera->getPosition() + (perpVector*0.05f));
			break;
		case 'S':
			camera->setPosition(camera->getPosition() - (stepVector*0.05f));
			break;
		case 'D':
			camera->setPosition(camera->getPosition() - (perpVector*0.05f));
			break;
		};
		printf("=======================\n");
		printf("(%lf, %lf, %lf)\n",stepVector);
		printf("(%lf, %lf, %lf)\n",perpVector);
		printf("(%lf, %lf, %lf)\n",camera->getPosition().x,camera->getPosition().y,camera->getPosition().z);
		printf("=======================\n");
	}
}


void Application::DispatchMouseEvent(int button, int action, int mods)
{
}


void Application::DispatchCursorEvent(int xoffset, int yoffset)
{
	double dx = (double)xoffset - (1024.0/2.0);
	double dy = (double)yoffset - (768.0/2.0);
	printf("%lf %lf\n",dx,dy);
	chosenRoom->getCamera()->addAngleByXAxis((-dy)/1000.0);
	chosenRoom->getCamera()->addAngleByZAxis((-dx)/1000.0);
}