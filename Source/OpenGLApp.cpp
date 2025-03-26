#include "../Header/OpenGLApp.h"
#include "../Header/ContextMenu.h"
#include "../Header/ShapeManager.h"
#include "../Header/ShapeFactory.h"
#include "../Header/Shapes/Line.h"

// Static instance of the application
OpenGLApp* OpenGLApp::app = nullptr;

// Constructor
OpenGLApp::OpenGLApp(int w, int h, const char* t) {
	width = w;
	height = h;
	title = t;
	isAddingShape = false;
	shapeType = 0;

	// Initialize the clicked times
	clickedTimes[0] = 4; //Line
	clickedTimes[1] = 6; //Triangle
	clickedTimes[2] = 4; //Rectangle
	clickedTimes[3] = 4; //Circle
}

// Add shape
void OpenGLApp::addShapes(int type) {
	isAddingShape = true;
	shapeType = type;
}

// Destructor
OpenGLApp::~OpenGLApp() {
	delete contextMenu;
}

// Get the instance of the application
inline OpenGLApp* OpenGLApp::getInstance() {
	if (app == nullptr) {
		app = new OpenGLApp(800, 600, "OpenGL Application");
	}
	return app;
}

// Static callback wrappers for GLUT
void OpenGLApp::displayCallback() {
	OpenGLApp::getInstance()->display();
}

void OpenGLApp::reshapeCallback(int w, int h) {
	OpenGLApp::getInstance()->reshape(w, h);
}

void OpenGLApp::keyboardCallback(unsigned char key, int x, int y) {
	OpenGLApp::getInstance()->keyboard(key, x, y);
}

void OpenGLApp::updateCallback() {
	OpenGLApp::getInstance()->update();
}

void OpenGLApp::mouseCallback(int button, int state, int x, int y) {
	OpenGLApp::getInstance()->mouse(button, state, x, y);
}

void OpenGLApp::specialKeyboardCallback(int key, int x, int y) {
	OpenGLApp::getInstance()->specialKeyboard(key, x, y);
}

//Initialize the application
void OpenGLApp::init() {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, width, 0.0, height);
	glClear(GL_COLOR_BUFFER_BIT);

	// Create the context menu
	contextMenu = new ContextMenu();
	contextMenu->updateMenuItems({ "Line", "Triangle", "Rectangle", "Circle" });
	contextMenu->attachToMouse(GLUT_RIGHT_BUTTON);

	// Create the shape manager
	shapeManager = new ShapeManager();
}

// Display the application
void OpenGLApp::display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(2.0);
	glFlush();
	shapeManager->drawAll();
	glutSwapBuffers();
}

// Reshape the application
void OpenGLApp::reshape(int width, int height) {
	glViewport(0, 0, width, height);
}

// Keyboard event
void OpenGLApp::keyboard(unsigned char key, int x, int y) {
	switch (key) {
	case 27:
		exit(0);
		break;
	// case '+'
	case '+':
		cout << "Scaling up\n";
		shapeManager->scale(selectedShape, 1.1, 1.1);
		break;
	case '-':
		shapeManager->scale(selectedShape, 0.9, 0.9);
		break;
	case 'L':
		shapeManager->rotate(selectedShape, 3.14/180.0);
		break;
	case 'R':
		shapeManager->rotate(selectedShape, -3.14/180.0);
		break;
	}
}

// Special keyboard event
void OpenGLApp::specialKeyboard(int key, int x, int y) {
	switch (key)
	{
	case GLUT_KEY_DOWN:
		cout << "Down\n";
		shapeManager->translate(selectedShape, 0, -10);
		break;
	case GLUT_KEY_UP:
		cout << "Up\n";
		shapeManager->translate(selectedShape, 0, 10);
		break;
	case GLUT_KEY_LEFT:
		cout << "Left\n";
		shapeManager->translate(selectedShape, -10, 0);
		break;
	case GLUT_KEY_RIGHT:
		cout << "Right\n";
		shapeManager->translate(selectedShape, 10, 0);
		break;
	default:
		break;
	}
}

// Update the application
void OpenGLApp::update() {
	if (params.size() == clickedTimes[shapeType]) {
		isAddingShape = false;
		cout << "Shape added" << ' ';
		for (const auto& x : params) cout << x << ' ';

		vector<string> items = { "Line", "Triangle", "Rectangle", "Circle" };
		auto shape = ShapeFactory::createShape(shapeType, params);
		shapeManager->addShape(std::move(shape));

		vector<string> names = shapeManager->getShapeNames();
		items.insert(items.end(), names.begin(), names.end());
		contextMenu->updateMenuItems(items);
		params.clear();
	}
	glutPostRedisplay();
}

// Mouse event
void OpenGLApp::mouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		if (isAddingShape) {
			cout << "Adding shape: " << x << " " << height - y << endl;
			params.push_back(x);
			params.push_back(height - y);
		}
	}
}

// Run the application
void OpenGLApp::run(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(width, height);
	glutInitWindowPosition(50, 50);
	glutCreateWindow(title);

	init();
	glutDisplayFunc(OpenGLApp::displayCallback);
	glutKeyboardFunc(OpenGLApp::keyboardCallback);
	glutSpecialFunc(OpenGLApp::specialKeyboardCallback);
	glutIdleFunc(OpenGLApp::updateCallback);
	glutMouseFunc(OpenGLApp::mouseCallback);
	glutMainLoop();
}

// Get the context menu
const ContextMenu* OpenGLApp::getContextMenu() const {
	return contextMenu;
}

// Handle the context menu callback
void OpenGLApp::handleMenuCallback(const string& item) {
	if (item == "Line") {
		addShapes(0);
	}
	else if (item == "Triangle") {
		addShapes(1);
	}
	else if (item == "Rectangle") {
		addShapes(2);
	}
	else if (item == "Circle") {
		addShapes(3);
	}
	else {
		//parse the string to get the index
		int index = stoi(item.substr(item.find_last_of(' ') + 1));
		cout << "Selected shape: " << index << endl;
		selectedShape = index;
	}
}