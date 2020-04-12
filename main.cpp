#include "core/Engine.h"
#include "project/ProjectFile.h"

#include <iostream>

int main(int argc, const char * argv[]) {
	using namespace std;

	try{
		Engine & engine = Engine::get_instance();
		engine.init(argc, argv);

		engine.launch();
	}catch(std::string message){
		cout << message << endl;
	}
	
    return 0;
}