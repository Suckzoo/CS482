#ifndef ROOM_H
#define ROOM_H
#include "stdafx.h"
#include "BaseObject.h"
class Room;
class Television;

class Television
	: public BaseObject
{
private:
	Room* m_pLinkedRoom;
public:
	Room* getLinkedRoom();
};
class Room
{
private:
	std::list <BaseObject> m_pObjects;
	std::list <Television> m_pTelevisions;
public:
	std::list<BaseObject> *getObjectList();
	std::list<Television> *getTelevisionList();
	void AddObject(BaseObject* object);
	void AddTelevision(Television* television);
};
//Room contains TVs, objects, dynamic world, Wall texture, etc....
#endif