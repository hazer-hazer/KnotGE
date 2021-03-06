#include "core/Input.h"

Input::Input(){}

Input & Input::get_instance(){
	static Input instance;
	return instance;
}

// Debug
#define str(a) std::to_string(a)

void key_event_callback(GLFWwindow * context, int key, int scancode, int action, int mods){

	Input::get_instance().print("key_event_callback " + str(key) + " " + str(scancode)
												+ " " + str(action) + " " + str(mods));

	// Debug
	if(key == 256){
		Input::get_instance().get_window()->close();
	}
}

void mouse_event_callback(GLFWwindow * context, double xpos, double ypos){
	Input::get_instance().emit("mouse_moved");
}

// Window
void Input::set_window(Window * window){
	this->window = window;

	// Keyboard
	glfwSetKeyCallback(window->context, key_event_callback);
	
	// Mouse
	glfwSetCursorPosCallback(window->context, mouse_event_callback);
}

Window * Input::get_window() const {
	return window;
}

void Input::process_input(){
	if(window == nullptr){
		throw "Failed to poll events, Input's window was not set";
	}
}

// TODO: Return 0, 0 if cursor is disabled
V2d Input::get_mouse_position() const {
	V2d pos;
	glfwGetCursorPos(window->context, &pos.x, &pos.y);
	return pos;
}