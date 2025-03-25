#include "../Header/ContextMenu.h"
#include "../Header/OpenGLApp.h"
#include <iostream>

ContextMenu::ContextMenu()
{
	menuId = glutCreateMenu(ContextMenu::menuCallback);
	glutAddMenuEntry("Line", 0);
	glutAddMenuEntry("Triangle", 1);
	glutAddMenuEntry("Rectangle", 2);
	glutAddMenuEntry("Circle", 3);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
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
	switch (value)
	{
	case 0:
		OpenGLApp::getInstance()->addShapes(0);
		break;
	case 1:
		OpenGLApp::getInstance()->addShapes(1);
		break;
	case 2:
		cout << "Rectangle selected" << endl;
		break;
	case 3:
		cout << "Circle selected" << endl;
		break;
	}
}