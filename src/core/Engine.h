#ifndef ENGINE_H
#define ENGINE_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "core/Object.h"
#include "core/WindowManager.h"
#include "core/Input.h"
#include "core/Timer.h"

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