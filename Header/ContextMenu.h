#ifndef CONTEXTMENU_H
#define CONTEXTMENU_H

#include <GL/glut.h>

using namespace std;

class OpenGLApp;

class ContextMenu {
private:
	int menuId;
public:
	ContextMenu();
	~ContextMenu();
	void attachToMouse(int button);
	static void menuCallback(int value);
};

#endif // !CONTEXTMENU_H
