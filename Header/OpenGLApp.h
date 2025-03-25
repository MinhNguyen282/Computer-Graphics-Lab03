#ifndef OPENGLAPP_H
#define OPENGLAPP_H

#include <GL/glut.h>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class ShapeManager;
class ContextMenu;

class OpenGLApp{
protected:
	int width, height;
	const char* title;
	OpenGLApp(int w, int h, const char* t);
public:
	virtual ~OpenGLApp();
	OpenGLApp(OpenGLApp &other) = delete;
	void operator=(const OpenGLApp&) = delete;
	void run(int argc, char** argv);

	static OpenGLApp* getInstance();
	static void displayCallback();
	static void reshapeCallback(int w, int h);
	static void keyboardCallback(unsigned char key, int x, int y);
	static void updateCallback();
	static void mouseCallback(int button, int state, int x, int y);
	void addShapes(int type);
protected:
	virtual void init();
	virtual void display();
	virtual void reshape(int w, int h);
	virtual void keyboard(unsigned char key, int x, int y);
	virtual void update();
	virtual void mouse(int button, int state, int x, int y);
private:
	static OpenGLApp* app;
	ContextMenu* contextMenu;
	ShapeManager* shapeManager;
	bool isAddingShape;
	int shapeType;
	map<int, int> clickedTimes;
	vector<int> params;
};

#endif // !OPENGLAPP_G
