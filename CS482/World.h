#ifndef ROOM_H
#define ROOM_H
#include "stdafx.h"
#include "BaseObject.h"
#include "Renderer.h"
#include "Camera.h"
#include <map>
class Room;
class Television;

class Television
	: public BaseObject
{
private:
	Room* m_pLinkedRoom;
public:
	Television();
	Television(Room* room);
	Room* getLinkedRoom();
	void setLinkedRoom();
	void Draw();
};

class Room
{
private:
	std::list <BaseObject*> m_pObjects;
	std::list <Television*> m_pTelevisions;
	btDiscreteDynamicsWorld* m_pDynamicsWorld;
	bool m_pChosenRoom;
	Camera* m_pCamera;
public:
	Room();
	virtual ~Room();
	void AddObject(BaseObject* object);
	void AddTelevision(Television* television);
	void Draw();
	void UpdateSimulation();
	void Render();
	void switchChoice();
	bool isChosen();
	Camera* getCamera();
	void setCamera(Camera* camera);
};
//Room contains TVs, objects, dynamic world, Wall texture, etc....
#endif