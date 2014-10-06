#ifndef UTILITY_H
#define UTILITY_H
#include "stdafx.h"
GLuint LoadShaders(const char * vertex_file_path,const char * fragment_file_path);
GLuint loadBMP_custom(const char * imagepath,GLuint textureID);
#endif