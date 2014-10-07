#ifndef UTILITY_H
#define UTILITY_H
#include "stdafx.h"
GLuint LoadShaders(const char * vertex_file_path,const char * fragment_file_path);
GLuint loadBMP_custom(const char * imagepath, GLuint textureID);
bool loadOBJ(
	const char * path, 
	std::vector<glm::vec3> & out_vertices, 
	std::vector<glm::vec2> & out_uvs,
	std::vector<glm::vec3> & out_normals
);
#endif