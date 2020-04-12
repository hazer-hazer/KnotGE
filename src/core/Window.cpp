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

	if(context == nullptr){
		error("Failed to create window");
		glfwTerminate();
	}
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

bool Window::is_fullscreen(){
	return glfwGetWindowMonitor(context) != nullptr;
}