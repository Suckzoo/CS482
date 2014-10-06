#include "stdafx.h"
#include "World.h"

Room::Room() :
	m_pObjects(std::list<BaseObject*>()),
	m_pTelevisions(std::list<Television*>()),
	m_pChosenRoom(false)
{
	btBroadphaseInterface* broadphase = new btDbvtBroadphase();
	btDefaultCollisionConfiguration* collisionConfiguration = new btDefaultCollisionConfiguration();
	btCollisionDispatcher* dispatcher = new btCollisionDispatcher(collisionConfiguration);
	btSequentialImpulseConstraintSolver* solver = new btSequentialImpulseConstraintSolver();
	m_pDynamicsWorld = new btDiscreteDynamicsWorld(dispatcher, broadphase, solver, collisionConfiguration);
}

void Room::AddObject(BaseObject* object)
{
	this->m_pObjects.push_back(object);
}

void Room::AddTelevision(Television* television)
{
	this->m_pTelevisions.push_back(television);
}

void Room::Draw()
{
	for(auto it = this->m_pObjects.begin(); it != this->m_pObjects.end(); it++)
	{
	}
}

void Room::UpdateSimulation()
{
	m_pDynamicsWorld->stepSimulation(1/60.f, 10);
	for(auto it = this->m_pObjects.begin(); it != this->m_pObjects.end(); it++)
	{
		(*it)->updateSimulation();
	}
}

void Room::Render()
{
	if(this->m_pChosenRoom) Draw();
	UpdateSimulation();
}

void Room::switchChoice()
{
	this->m_pChosenRoom = !this->m_pChosenRoom;
}

bool Room::isChosen()
{
	return this->m_pChosenRoom;
}

Camera* Room::getCamera()
{
	return this->m_pCamera;
}

void Room::setCamera(Camera* camera)
{
	this->m_pCamera = camera;
}