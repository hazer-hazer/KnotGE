/**
 * ScriptFile loads script that can be binded to Node.
 */

#ifndef SCRIPTFILE_H
#define SCRIPTFILE_H

#include "project/FileHandler.h"

#define KNOT_SCRIPTFILE_EXTENSION ".lua"

class ScriptFile : public FileHandler {

	CLASS(ScriptFile, FileHandler);

	public:
		ScriptFile(const std::string & path);
		virtual ~ScriptFile() = default;

};

#endif