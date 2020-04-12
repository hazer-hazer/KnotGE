#ifndef INPUT_H
#define INPUT_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "core/Window.h"
#include "core/Object.h"
#include "core/math/Vector2.h"

class Input : public Object {

	CLASS(Input, Object);

	// Singleton
	private:
		Input();
		virtual ~Input() = default;

	public:
		Input(const Input &) 					= delete;
		Input & operator = (const Input &) 		= delete;
		Input(Input &&) 						= delete;
		Input & operator = (Input &&) 			= delete;

		static Input & get_instance();

	// Window
	public:
		void set_window(Window * window);
		Window * get_window() const;

	private:
		Window * window;

	// Events
	// Poll events must be called after setting window
	public:
		void process_input();

		// void key_event_callback(GLFWwindow * window, int key, int scancode, int action, int mods);

	// Mouse
	public:
		Vector2 get_mouse_position() const;
};

#endif // INPUT_H