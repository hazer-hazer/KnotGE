#include "core/WindowManager.h"

// Window

Window::Window(int width, int height, const std::string & title, uint32_t style){
	GLFWmonitor * monitor = nullptr;

	if(style >> 1){
		print("FULLSCREEN");
	}

	print("Style " + std::to_string(style));

	context = glfwCreateWindow(width, height, title.c_str(), monitor, nullptr);

	if(context == nullptr){
		error("Failed to create window");
	}

	glfwMakeContextCurrent(context);

	// Init glad
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
		error("Failed to initialize GLAD");
	}
}

bool Window::is_open(){
	return !glfwWindowShouldClose(context);
}

void Window::close(){
	glfwSetWindowShouldClose(context, GLFW_TRUE);
}

void Window::clear(const Color & color){
	glClear(GL_COLOR_BUFFER_BIT);
}

// WindowManager

WindowManager::WindowManager(){}

WindowManager & WindowManager::get_instance(){
	static WindowManager instance;
	return instance;
}

Window * WindowManager::create_window(int width, int height, const std::string & title, uint32_t style){
	return new Window(width, height, title, style);
}