#ifndef DRAWABLEOBJECT_H
#define DRAWABLEOBJECT_H
#include "stdafx.h"
class DrawableObject
{
protected:
	GLuint m_pVertexArray;
	GLuint m_pVertexBuffer;
	GLuint m_pIndexBuffer;
	GLuint m_pNormalBuffer;
	GLuint m_pUVBuffer;
	GLuint m_pTexture;

public:
	DrawableObject();
	virtual ~DrawableObject();
	virtual void Draw() = NULL;
};
#endif