#include "project/ProjectFile.h"

#include <iostream>

ProjectFile::ProjectFile(const std::string & path, std::map <std::string, std::string> default_mask){
	this->path = path;

	// Open file
	file.open(path, std::ios::in | std::ios::out);

	if(file.fail()){
		error("Failed to load file");
	}

	// Set default variables, so if some of them are determined in file
	// then they will be replaced
	vars = default_mask;

	// Parse
	std::string line;
	while(std::getline(file, line)){
		if(trim(line) == ""){
			continue;
		}

		std::size_t assign_pos = line.find('=');
		std::string key = line.substr(0, assign_pos - 1);
		std::string val = line.substr(assign_pos + 1);

		key = trim(key);
		val = trim(val);

		vars[key] = val;
	}
}

std::string ProjectFile::get_string_val(const std::string & name){
	return vars[name];
}

std::map <std::string, std::string> ProjectFile::get_vars(){
	return vars;
}