// CS482.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "Application.h"

int _tmain(int argc, _TCHAR* argv[])
{
	Application *app = new Application();
	app->run();
	return 0;
}