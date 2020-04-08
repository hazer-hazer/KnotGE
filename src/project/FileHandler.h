/**
 * 
 * Base class for all classes that need to bind file.
 * 
 * Note: FileHandler must be inherited by another different FileHandlers,
 * not by Objects that need to have access to file.
 * Example: Node can have binded script file, but does not inherit it
 * 
 * It provides full API to work with .lua file (variables get/set, functions and etc.)
 * 
 */

#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#define SOL_ALL_SAFETIES_ON 1
#include <sol/sol.hpp>

#include "project/c_assert.h"
#include "core/Object.h"

#include "core/math/Vector2.h"

class FileHandler : public Object {

	CLASS(FileHandler, Object);

	public:
		FileHandler(const std::string & path);
		virtual ~FileHandler() = default;

	public:
		void load();

	public:
		void set_path(const std::string & path);
		std::string get_path();

	private:
		std::string path;
		

	private:
		sol::state lua;

	// Get 
	public:
		template <typename T>
		T get(std::string varname){
			return lua.get<T>(varname);
		}

};

#endif