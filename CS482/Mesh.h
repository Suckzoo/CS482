#ifndef MESH_H
#define MESH_H
#include "stdafx.h"
#include "BaseObject.h"
class Mesh :
	public BaseObject
{
public:
	Mesh(const char* objName);
	void Draw();
};
#endif