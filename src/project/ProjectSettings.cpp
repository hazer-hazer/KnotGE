#include "project/ProjectSettings.h"

ProjectSettings::ProjectSettings(std::string dir)
: FileHandler(dir + "/" + KNOT_PROJECTSETTINGS_FILENAME + KNOT_PROJECTSETTINGS_EXTENSION) {
	load();

	set_project_name( get<char*>("project_name") );
	set_window_size( get<Vector2>("window_size") );
}

// Project name
void ProjectSettings::set_project_name(const std::string & project_name){
	this->project_name = project_name;
}

std::string ProjectSettings::get_project_name(){
	return project_name;
}

// Window size
void ProjectSettings::set_window_size(const Vector2 & window_size){
	this->window_size = window_size;
}

Vector2 ProjectSettings::get_window_size(){
	return window_size;
}

std::string ProjectSettings::to_string(){
	std::string settings_str;

	settings_str += "project_name: " + project_name + "\n";
	settings_str += "window_size: " + window_size.to_string() + "\n";

	return settings_str;
}