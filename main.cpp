#include "core/Engine.h"
#include "project/ProjectSettings.h"

#include <iostream>

int main() {
	using namespace std;

	try{
		ProjectSettings settings(".");

		cout << "ProjectSettings: \n" << settings.to_string() << endl;

		// Engine & engine = Engine::get_instance();

		// engine.launch();
	}catch(std::string message){
		cout << message << endl;
	}catch(const char * message){
		cout << message << endl;
	}

	glfwTerminate();
    return 0;
}