#include "../Header/ContextMenu.h"
#include "../Header/OpenGLApp.h"
#include <iostream>

ContextMenu::ContextMenu()
{
	rebuildMenu();
}

void ContextMenu::rebuildMenu()
{
	if (menuId != 0)
	{
		glutDestroyMenu(menuId);
	}
	menuId = glutCreateMenu(menuCallback);
	for (int i = 0; i < menuItems.size(); i++)
	{
		glutAddMenuEntry(menuItems[i].c_str(), i);
	}
}

void ContextMenu::updateMenuItems(const vector<string> &items)
{
	menuItems = items;
	rebuildMenu();
}

ContextMenu::~ContextMenu()
{
	glutDestroyMenu(menuId);
}

void ContextMenu::attachToMouse(int button)
{
	glutAttachMenu(button);
}

void ContextMenu::menuCallback(int value)
{
	OpenGLApp* app = OpenGLApp::getInstance();
	string item = app->getContextMenu()->menuItems[value];
	app->handleMenuCallback(item);
}