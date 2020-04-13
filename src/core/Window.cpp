#include "core/Window.h"

#include <iostream>

// Window

Window::Window(const int & width,
			   const int & height,
			   const std::string & title,
			   const uint8_t & style)
{
	context = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);

	set_style(style);

	glfwMakeContextCurrent(context);

	// Set window pointer to this class
    glfwSetWindowUserPointer(context, this);

	if(context == nullptr){
		error("Failed to create window");
		glfwTerminate();
	}

	// Callbacks
	glfwSetWindowSizeCallback(context, Window::size_callback);
	glfwSetFramebufferSizeCallback(context, Window::framebuffer_callback);
}

void Window::destroy(){
	glfwDestroyWindow(context);
}

bool Window::is_open(){
	return !glfwWindowShouldClose(context);
}

void Window::close(const bool & close_opt){
	glfwSetWindowShouldClose(context, close_opt ? GLFW_TRUE : GLFW_FALSE);
}

void Window::clear(const Color & color){
	glClear(GL_COLOR_BUFFER_BIT);
}

void Window::set_title(const char * title){
	glfwSetWindowTitle(context, title);
}

// Visibility
bool Window::is_visible() const {
	return glfwGetWindowAttrib(context, GLFW_VISIBLE) == GLFW_TRUE;
}

void Window::set_visible(const bool & visible){
	if(visible == is_visible()){
		return;
	}
	toggle();
}

void Window::show(){
	glfwShowWindow(context);
}

void Window::hide(){
	glfwHideWindow(context);
}

void Window::toggle(){
	is_visible() ? hide() : show();
}

// Size
void Window::set_size(const V2i & size){
	glfwSetWindowSize(context, size.x, size.y);
}

V2i Window::get_size() const {
	V2i size;
	glfwGetWindowSize(context, &size.x, &size.y);
	return size;
}

// Style methods
void Window::set_style(const uint8_t & style){
	set_resizable(style & Window::Style::Resizable);

	set_fullscreen(style & Window::Style::Fullscreen);

	set_borderless(style & Window::Style::Borderless);

	set_always_on_top(style & Window::Style::AlwaysOnTop);
}

void Window::set_resizable(const bool & resizable){
	glfwSetWindowAttrib(context, GLFW_RESIZABLE, resizable ? GLFW_TRUE : GLFW_FALSE);
}

void Window::set_fullscreen(const bool & fullscreen){
	if(is_fullscreen() == fullscreen){
		return;
	}

	if(fullscreen){
		GLFWmonitor * monitor = glfwGetPrimaryMonitor();
		const GLFWvidmode * mode = glfwGetVideoMode(monitor);
		glfwSetWindowMonitor(context, monitor, 0, 0, mode->width, mode->height, mode->refreshRate);
	}else{
		int xpos, ypos,
			width, height;
		glfwGetWindowPos(context, &xpos, &ypos);
		glfwGetWindowSize(context, &width, &height);
		glfwSetWindowMonitor(context, nullptr, xpos, ypos, width, height, 0);
	}
}

void Window::set_borderless(const bool & borderless){
	glfwSetWindowAttrib(context, GLFW_DECORATED, borderless ? GLFW_FALSE : GLFW_TRUE);
}

void Window::set_always_on_top(const bool & always_on_top){
	glfwSetWindowAttrib(context, GLFW_FLOATING, always_on_top ? GLFW_TRUE : GLFW_FALSE);
}

bool Window::is_fullscreen() const {
	return glfwGetWindowMonitor(context) != nullptr;
}

// Opacity
void Window::set_opacity(const float & opacity){
	glfwSetWindowOpacity(context, opacity);
}