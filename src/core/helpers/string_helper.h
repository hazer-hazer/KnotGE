/**
 * Bunch of useful functions for working with strings
 */

// Trim
static inline std::string ltrim(std::string & str){
	str.erase(str.begin(), std::find_if(str.begin(), str.end(), [](int ch){
		return !std::isspace(ch);
	}));
	return str;
}

static inline std::string rtrim(std::string & str){
	str.erase(std::find_if(str.rbegin(), str.rend(), [](int ch){
		return !std::isspace(ch);
	}).base(), str.end());
	return str;
}

static inline std::string trim(std::string & str){
	ltrim(str);
	rtrim(str);
	return str;
}