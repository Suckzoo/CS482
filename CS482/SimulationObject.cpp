#include "stdafx.h"
#include "SimulationObject.h"

SimulationObject::SimulationObject() :
	m_pRigidBody(NULL),
	m_pPosition(btVector3(0,0,0)),
	m_pRotation(btQuaternion(0,0,0,1))
{
}

void SimulationObject::setPosition(btVector3 &pos)
{
	this->m_pPosition = pos;
	btTransform trans;
	this->m_pRigidBody->getMotionState()->getWorldTransform(trans);
	trans.setOrigin(this->m_pPosition);
	this->m_pRigidBody->getMotionState()->setWorldTransform(trans);
}

void SimulationObject::setRotation(btQuaternion &rot)
{
	this->m_pRotation = rot;
	btTransform trans;
	this->m_pRigidBody->getMotionState()->getWorldTransform(trans);
	trans.setRotation(this->m_pRotation);
	this->m_pRigidBody->getMotionState()->setWorldTransform(trans);
}

btRigidBody* SimulationObject::getRigidBody()
{
	return this->m_pRigidBody;
}

btVector3 SimulationObject::getPosition()
{
	return this->m_pPosition;
}

btQuaternion SimulationObject::getRotation()
{
	return this->m_pRotation;
}

void SimulationObject::addToDynamicsWorld(btDiscreteDynamicsWorld* dynamicsWorld)
{
	dynamicsWorld->addRigidBody(this->m_pRigidBody);
}

void SimulationObject::updateSimulation()
{
	btTransform trans;
	this->m_pRigidBody->getMotionState()->getWorldTransform(trans);
	this->m_pPosition = trans.getOrigin();
	this->m_pRotation = trans.getRotation();
	this->m_pRigidBody->activate();
}