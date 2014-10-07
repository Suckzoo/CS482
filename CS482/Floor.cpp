#include "stdafx.h"
#include "Floor.h"
#include "Utility.h"

Floor::Floor(const char* texture)
{
	btCollisionShape* shape = new btStaticPlaneShape(btVector3(0,0,1), -1);
	btDefaultMotionState* motionstate = new btDefaultMotionState(btTransform(btQuaternion(0,0,0,1), btVector3(0,0,-1)));
	btRigidBody::btRigidBodyConstructionInfo info(0, motionstate, shape, btVector3(0,0,0));
	m_pRigidBody = new btRigidBody(info);
	m_pRigidBody->setRestitution(1.0);
	const float vertex[18] =
	{
		-10,-10,-1,
		10,-10,-1,
		10,10,-1,
		10,10,-1,
		-10,10,-1,
		-10,-10,-1
	};
	const float normal[18] =
	{
		0,0,1,
		0,0,1,
		0,0,1,
		0,0,1,
		0,0,1,
		0,0,1
	};
	const float uv[12] =
	{
		-1,-1,
		1,-1,
		1,1,
		1,1,
		-1,1,
		-1,-1
	};
	glGenVertexArrays(1, &m_pVertexArray);
	glGenBuffers(1, &m_pVertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, m_pVertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertex), vertex, GL_STREAM_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glGenBuffers(1, &m_pUVBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, m_pUVBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(uv), uv, GL_STREAM_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glGenBuffers(1, &m_pNormalBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, m_pNormalBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(normal), normal, GL_STREAM_DRAW);
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
	glGenTextures(1, &m_pTexture);
	m_pTexture = loadBMP_custom(texture,m_pTexture);
	m_pNumVertices = 18;
	m_pPosition = btVector3(0,0,0);
	m_pRotation = btQuaternion(0,0,0,1);
}
void Floor::Draw() 
{
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, this->m_pTexture);
	glBindVertexArray(m_pVertexArray);
	glDrawArrays(GL_TRIANGLES, 0, m_pNumVertices);
}