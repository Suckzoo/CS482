#include "stdafx.h"
#include "Program.h"
#include "Utility.h"

Program::Program(const char *vertexFilePath, const char *fragmentFilePath)
{
	m_uProgram = LoadShaders(vertexFilePath, fragmentFilePath);
}


Program::~Program()
{
	glDeleteProgram(m_uProgram);
}


unsigned int Program::operator () (const std::string &it)
{
	return m_Uniform[it];
}


void Program::FindUniform(std::vector<std::string> &names)
{
	m_Uniform.clear();

	for(auto it = names.begin(); it != names.end(); it++)
	{
		m_Uniform[*it] = glGetUniformLocation(m_uProgram, it->c_str());
	}
}


void Program::Use()
{
	glUseProgram(m_uProgram);
}