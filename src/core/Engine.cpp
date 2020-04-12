#include "core/Engine.h"

#include <iostream>

// GLFW Error callback
static inline void glfw_error_callback(int error, const char * description){
	Engine::get_instance().error(description);
}

Engine & Engine::get_instance(){
	static Engine instance;
	return instance;
}

Engine::Engine(){
}

const std::map <std::string, std::string> default_project_settings = {
	{ "name", "noname" },
	{ "window_width", "640" },
	{ "window_height", "360" },
	{ "window_style", "1" }
};

void Engine::init(int argc, const char * argv[]){

	if(!glfwInit()){
		error("Failed to initialize GLFW");
	}

	glfwSetErrorCallback( glfw_error_callback );
	
	// Prevent using OpenGL not version 3
	// Not for production, just for dev
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	if(argc == 1){
		error("Please specify path to project");
	}

	// Load project settings
	ProjectFile project_settings(argv[1], default_project_settings);

	uint8_t window_style = project_settings.get<uint8_t>("window_style");

	// Window intialization
	window = new Window(project_settings.get<int>("window_width"),
						project_settings.get<int>("window_height"),
						project_settings.get<std::string>("name"),
						window_style);


	// Init glad
	if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)){
		error("Failed to initialize GLAD");
	}

	// Set window to all classes where it used	
	VisualServer::get_instance().set_window(window);
	Input::get_instance().set_window(window);
}

double Engine::get_fps(){
	return fps;
}

void Engine::launch(){
	Input & input = Input::get_instance();
	
	loop_timer.restart();

	// Note: No Object events inside main loop !

	// TODO: Framerate limit
	
	while(window->is_open()){
		input.process_input();

		window->clear(Color::BLACK);


		glfwSwapBuffers(window->context);

		glfwPollEvents();

		fps = 1.0 / loop_timer.restart().seconds();
	}

	glfwTerminate();
}