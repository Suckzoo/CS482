#ifndef SIMULATIONOBJECT_H
#define SIMULATIONOBJECT_H
#include "stdafx.h"
class SimulationObject
{
protected:
	btRigidBody* m_pRigidBody;
	btVector3 m_pPosition;
	btQuaternion m_pRotation;
public:
	SimulationObject();
	btRigidBody* getRigidBody();
	btVector3 getPosition();
	btQuaternion getRotation();
	void setPosition(btVector3 &pos);
	void setRotation(btQuaternion &rot);
	void addToDynamicsWorld(btDiscreteDynamicsWorld* dynamicsWorld);
	void updateSimulation();
};
#endif