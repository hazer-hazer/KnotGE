#include "servers/VisualServer.h"

VisualServer::VisualServer(){

}

VisualServer & VisualServer::get_instance(){
	static VisualServer instance;
	return instance;
}

// Window
void VisualServer::set_window(Window * window){
	this->window = window;
}

Window * VisualServer::get_window() const {
	return window;
}