#ifndef FLOOR_H
#define FLOOR_H
#include "stdafx.h"
#include "BaseObject.h"

class Floor :
	public BaseObject
{
public:
	Floor(const char *texture);
	void Draw();
};
#endif