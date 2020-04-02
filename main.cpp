#include "core/Engine.h"

#include <iostream>

using std::cout;
using std::endl;

int main() {
	try{
		Engine & engine = Engine::get_instance();

		engine.launch();
	}catch(std::string message){
		cout << message << endl;
	}catch(const char * message){
		cout << message << endl;
	}

	glfwTerminate();
    return 0;
}