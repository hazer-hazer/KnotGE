#ifndef ENGINE_H
#define ENGINE_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "core/Object.h"
#include "core/Window.h"
#include "core/Input.h"
#include "core/Timer.h"
#include "servers/VisualServer.h"
#include "project/ProjectFile.h"

class Engine : public Object {
	
	CLASS(Engine, Object);

	// Singleton
	private:
		Engine();
		virtual ~Engine() = default;

	public:
		Engine(const Engine &) 					= delete;
		Engine & operator = (const Engine &) 	= delete;
		Engine(Engine &&) 						= delete;
		Engine & operator = (Engine &&) 		= delete;

		static Engine & get_instance();

	public:
		void init(int argc, const char * argv[]);

	// Window
	private:
		Window * window;

	// Framerate
	public:
		double get_fps();

	private:
		double fps;
		Timer loop_timer;

	public:
		void launch();
};

#endif