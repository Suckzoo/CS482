#pragma once


class Application;
struct GLFWwindow;

class Window
{
protected:
	static const int m_dWidth = 1024;
	static const int m_dHeight = 768;
	GLFWwindow *m_pGLFWWindow;
	Application *m_pApplication;
public:
	Window();
	~Window();
	void Initialize();
	void SwapBuffers();
	int GetKey(int key);
	int ShouldClose();
	
	void SetApplication(Application *application){ m_pApplication = application; }
	Application *GetApplication(){ return m_pApplication; }
	int GetWidth() { return m_dWidth; }
	int GetHeight() { return m_dHeight; }
	GLFWwindow* getWindow() { return m_pGLFWWindow;}

	static void OnKeyEvent(GLFWwindow* window, int key, int scancode, int action, int mods);
	static void OnMouseEvent(GLFWwindow* window, int button, int action, int mods);
	static void OnCursorEvent(GLFWwindow* window, double xoffset, double yoffset);
};