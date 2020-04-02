#include "core/Engine.h"

// GLFW Error callback
void glfw_error_callback(int error, const char* description){
	Engine::get_instance().error(description);
}

Engine::Engine(){
	if(!glfwInit()){
		error("Failed to initialize GLFW");
	}

	glfwSetErrorCallback( glfw_error_callback );
	
	// Prevent using OpenGL not version 3
	// Not for production, just for dev
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);

	window = WindowManager::get_instance().create_window(640, 360, "TITLE", Window::Style::Fullscreen);

	Input::get_instance().set_window(window);
}

Engine & Engine::get_instance(){
	static Engine instance;
	return instance;
}

double Engine::get_fps(){
	return fps;
}

void Engine::launch(){
	Input & input = Input::get_instance();

	// Debug
	input.on("mouse_moved", [&input](){
		input.print("mouse_moved " + input.get_mouse_position().to_string());
	});
	
	loop_timer.restart();

	// Note: No Object events inside main loop !

	while(window->is_open()){
		window->clear(Color::BLACK);

		glfwSwapBuffers(window->context);

		input.poll_events();

		fps = 1.0 / loop_timer.restart().seconds();
	}
}