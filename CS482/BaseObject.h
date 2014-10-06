#ifndef BASEOBJECT_H
#define BASEOBJECT_H
#include "stdafx.h"
#include "DrawableObject.h"
#include "SimulationObject.h"
class BaseObject :
	public DrawableObject, public SimulationObject
{
public:
	BaseObject();
	virtual ~BaseObject();
};
#endif