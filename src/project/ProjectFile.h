/**
 * Base class for all project files except script files.
 */

#ifndef PROJECTFILE_H
#define PROJECTFILE_H

#include <fstream>
#include <map>
#include <sstream>

#include "core/Object.h"
#include "core/helpers/string_helper.h"

class ProjectFile : public Object {

	CLASS(ProjectFile, Object);

	public:
		ProjectFile(const std::string & path, std::map <std::string, std::string> default_mask = {});
		virtual ~ProjectFile() = default;

		std::string get_string_val(const std::string & name);

		template <typename T>
		T get(const std::string & name){
			std::stringstream found( get_string_val(name) );

			T orig;
			if(!( found >> orig )){
				error("Unable to convert variable");
			}
			return orig;
		}

		// TODO `set`
		
		std::map <std::string, std::string> get_vars();

	private:
		std::string path;
		std::fstream file;

		std::map <std::string, std::string> vars;
};

#endif