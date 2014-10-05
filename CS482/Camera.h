#ifndef CAMERA_H
#define CAMERA_H
#include "stdafx.h"
class Camera {
private:
	glm::vec3 m_pPosition;
	glm::vec3 m_pDirection;
public:
	Camera();
	Camera(glm::vec3 position, glm::vec3 direction);
	void setPosition(glm::vec3 position);
	void setDirection(glm::vec3 direction);
	void addAngleByXAxis(float angle);
	void addAngleByZAxis(float angle);
	glm::vec3 getPosition();
	glm::vec3 getDirection();
	glm::mat4 getVPMatrix();
};
#endif