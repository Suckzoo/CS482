#include "stdafx.h"
#include "Camera.h"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/rotate_vector.hpp>
Camera::Camera() :
	m_pPosition(glm::vec3(0,0,0)),
	m_pDirection(glm::vec3(0,1,0))
{

}

Camera::Camera(glm::vec3 position, glm::vec3 direction) :
	m_pPosition(position),
	m_pDirection(direction)
{

}

void Camera::setPosition(glm::vec3 position)
{
	this->m_pPosition = position;
}

void Camera::setDirection(glm::vec3 direction)
{
	glm::vec3 dir_normalized = this->m_pDirection;
	dir_normalized = glm::normalize(dir_normalized);
	double dv = glm::dot(dir_normalized, glm::vec3(0,0,1));
	dv = acos(dv);
	if(dv < glm::pi<double>()/18.0) return;
	this->m_pDirection = direction;
}

void Camera::addAngleByZAxis(float angle)
{
	glm::vec3 v = m_pDirection;
	glm::mat4 r = glm::rotate<float, glm::precision::highp> (glm::mat4(1.0f),angle,glm::vec3(0,0,1));
	v = glm::vec3(r * glm::vec4(v,0));
	v = glm::normalize(v);
	if(fabs(glm::dot<float>(v, glm::vec3(0,0,1)))>0.90) {
		return;
	}
	this->m_pDirection = v;
}

void Camera::addAngleByXAxis(float angle)
{
	glm::vec3 v = m_pDirection;
	glm::mat4 r = glm::rotate<float, glm::precision::highp> (glm::mat4(1.0f),angle,glm::vec3(1,0,0));
	v = glm::vec3(r * glm::vec4(v,0));
	v = glm::normalize(v);
	printf("%lf\n",v.z);
	if(fabs(glm::dot<float>(v, glm::vec3(0,0,1)))>0.90) {
		return;
	}
	this->m_pDirection = v;
}

glm::vec3 Camera::getPosition()
{
	return this->m_pPosition;
}

glm::vec3 Camera::getDirection()
{
	return this->m_pDirection;
}

glm::mat4 Camera::getVPMatrix()
{
	glm::vec3 e = this->m_pPosition;
	glm::vec3 c = e + this->m_pDirection;
	glm::mat4 v = glm::lookAt(e,c,glm::vec3(0,0,1));
	glm::mat4 p;
	double fov = 43.0 * glm::pi<double>() / 180.0;
	p = glm::perspective<double>(fov, 4.0/3.0, 0.5, 100);
	return p * v;
}