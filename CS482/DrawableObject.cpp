#include "stdafx.h"
#include "DrawableObject.h"

DrawableObject::DrawableObject() :
	m_pVertexArray(0),
	m_pVertexBuffer(0),
	m_pNormalBuffer(0),
	m_pUVBuffer(0),
	m_pTexture(0),
	m_pNumVertices(0)
{

}

DrawableObject::~DrawableObject()
{
	
}

void DrawableObject::Draw()
{
	/*glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, this->m_pTexture);
	glBindVertexArray(m_pVertexArray);
	glDrawArrays(GL_TRIANGLES, 0, m_pNumVertices);*/
}