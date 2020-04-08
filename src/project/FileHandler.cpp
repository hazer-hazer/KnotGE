#include "project/FileHandler.h"

FileHandler::FileHandler(const std::string & path){
	this->path = path;

	// Set types metatables to use some c++ classes inside lua scripts
	sol::usertype<Vector2> sol_vector2;
	sol_vector2 = lua.new_usertype<Vector2>("Vector2", sol::constructors<Vector2(), Vector2(double, double)>());
}

void FileHandler::load(){
	lua.open_libraries(sol::lib::base);

	auto result = lua.safe_script_file(path, sol::script_pass_on_error);

	if(!result.valid()){
		sol::error err = result;
		error(std::string(err.what()));
	}
}