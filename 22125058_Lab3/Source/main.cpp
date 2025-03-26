#include "Header/OpenGLApp.h"

int main(int argc, char** argv) {
	try {
		OpenGLApp::getInstance()->run(argc, argv);
	}
	catch (const exception& e) {
		cerr << e.what() << endl;
	}
	return 0;
}