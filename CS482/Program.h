#ifndef PROGRAM_H
#define PROGRAM_H
#include "stdafx.h"

class Program
{
protected:
	GLuint m_uProgram;
	std::map<std::string, GLuint> m_Uniform;

public:
	Program(const char *vertexFilePath, const char *fragmentFilePath);
	~Program();

	unsigned int operator () (const std::string &it);
	void FindUniform(std::vector<std::string> &names);
	void Use();
};
#endif