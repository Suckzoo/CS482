#include "stdafx.h"
#include "World.h"
#include "Program.h"
#include <glm/gtx/quaternion.hpp>
#include <glm/gtc/matrix_transform.hpp>
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

void Room::Draw(Program* p)
{
	BaseObject* b;
	for(auto it = this->m_pObjects.begin(); it != this->m_pObjects.end(); it++)
	{
		b = *it;
		glm::vec3 position = glm::vec3(b->getPosition().x,b->getPosition().y,b->getPosition().z);
		glm::quat rotation = glm::quat(b->getRotation().x,b->getRotation().y,b->getRotation().z,b->getRotation().w);
		glm::mat4 M = glm::translate(glm::mat4(1.0f), position) * glm::toMat4(rotation);
		glUniformMatrix4fv((*p)("M"), 1, GL_FALSE, &M[0][0]);
		glm::mat4 MITM = glm::transpose(glm::inverse(M));
		glUniformMatrix4fv((*p)("MITM"), 1, GL_FALSE, &MITM[0][0]);
		glUniform1i((*p)("TextureSampler"), 0);
		b->Draw();
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

void Room::Render(Program* p)
{
	if(this->m_pChosenRoom) {
		p->Use();
		glUniformMatrix4fv((*p)("VP"), 1, GL_FALSE, &this->m_pCamera->getVPMatrix());
		Draw(p);
	}
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

Room::~Room()
{
}