/**
 * ProjectSettings loads from file and operates with project settings.
 */

#ifndef PROJECTSETTINGS_H
#define PROJECTSETTINGS_H

#include "project/FileHandler.h"
#include "core/math/Vector2.h"

#define KNOT_PROJECTSETTINGS_FILENAME "project"
#define KNOT_PROJECTSETTINGS_EXTENSION ".lua"

class ProjectSettings : public FileHandler {

	CLASS(ProjectSettings, FileHandler);

	public:
		ProjectSettings(std::string dir);
		virtual ~ProjectSettings() = default;

		virtual std::string to_string();

	// Project name
	public:
		void set_project_name(const std::string & project_name);
		std::string get_project_name();

	private:
		std::string project_name;

	// Window size
	public:
		void set_window_size(const Vector2 & window_size);
		Vector2 get_window_size();

	private:
		Vector2 window_size;

};

#endif