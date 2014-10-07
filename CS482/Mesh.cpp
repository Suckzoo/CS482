#include "stdafx.h"
#include "Mesh.h"
#include "Utility.h"
Mesh::Mesh(const char* objName)
{
	std::vector<glm::vec3> vertices;
	std::vector<glm::vec2> uvs;
	std::vector<glm::vec3> normals;
	if(!loadOBJ(objName, vertices, uvs, normals)) std::runtime_error("Fuck you!");
	btConvexHullShape* shape = new btConvexHullShape();
	for(auto it = vertices.begin(); it != vertices.end(); it++) {
		glm::vec3 v = *it;
		shape->addPoint(btVector3(v.x,v.y,v.z));
	}
	btDefaultMotionState* motionstate = new btDefaultMotionState(btTransform(btQuaternion(0,0,0,1), btVector3(1,0,3)));
	m_pPosition = btVector3(1,0,3);
	m_pRotation = btQuaternion(0,0,0,1);
	btVector3 localInertia;
	shape->calculateLocalInertia(10, localInertia);
	btRigidBody::btRigidBodyConstructionInfo rigidCI(10,motionstate,shape,localInertia);
	m_pRigidBody = new btRigidBody(rigidCI);
	m_pRigidBody->setRestitution(1.0);
	
	glGenVertexArrays(1, &m_pVertexArray);
	glGenBuffers(1, &m_pVertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, m_pVertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3)*vertices.size(), &vertices[0], GL_STREAM_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glGenBuffers(1, &m_pUVBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, m_pUVBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec2)*uvs.size(), &uvs[0], GL_STREAM_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glGenBuffers(1, &m_pNormalBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, m_pNormalBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3)*normals.size(), &normals[0], GL_STREAM_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(m_pVertexArray);
	// 1rst attribute buffer : vertices
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, m_pVertexBuffer);
	glVertexAttribPointer(
		0,                  // attribute
		3,                  // size
		GL_FLOAT,           // type
		GL_FALSE,           // normalized?
		0,                  // stride
		(void*)0            // array buffer offset
		);

	// 2nd attribute buffer : UVs
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, m_pUVBuffer);
	glVertexAttribPointer(
		1,                                // attribute
		2,                                // size
		GL_FLOAT,                         // type
		GL_FALSE,                         // normalized?
		0,                                // stride
		(void*)0                          // array buffer offset
		);

	// 3rd attribute buffer : normals
	glEnableVertexAttribArray(2);
	glBindBuffer(GL_ARRAY_BUFFER, m_pNormalBuffer);
	glVertexAttribPointer(
		2,                                // attribute
		3,                                // size
		GL_FLOAT,                         // type
		GL_FALSE,                         // normalized?
		0,                                // stride
		(void*)0                          // array buffer offset
		);
	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	m_pNumVertices = vertices.size();
	glGenTextures(1, &m_pTexture);
	m_pTexture = loadBMP_custom("D:\\Projects\\CS482\\CS482\\res\\mesh.bmp",m_pTexture);
}

void Mesh::Draw()
{
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, this->m_pTexture);
	glBindVertexArray(m_pVertexArray);
	glDrawArrays(GL_TRIANGLES, 0, m_pNumVertices*3);
}