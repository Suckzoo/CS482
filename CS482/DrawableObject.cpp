#include "stdafx.h"
#include "DrawableObject.h"

DrawableObject::DrawableObject() :
	m_pVertexArray(0),
	m_pVertexBuffer(0),
	m_pNormalBuffer(0),
	m_pUVBuffer(0),
	m_pTexture(0)
{

}

DrawableObject::~DrawableObject()
{
	
}