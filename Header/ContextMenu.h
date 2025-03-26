#ifndef CONTEXTMENU_H
#define CONTEXTMENU_H

#include <GL/glut.h>
#include <vector>
#include <string>

using namespace std;

class OpenGLApp;

class ContextMenu {
private:
	int menuId;
	vector<string> menuItems;
	void rebuildMenu();
public:
	ContextMenu();
	~ContextMenu();
	void attachToMouse(int button);
	static void menuCallback(int value);
	void updateMenuItems(const vector<string> &items);
};

#endif // !CONTEXTMENU_H
