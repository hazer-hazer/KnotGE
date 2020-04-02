/**
 * WindowManager
 * 
 * Operates with window. Now it's only used for single window,
 * but in the future it will nice wrapper for multiple windows.
 * 
 * So... It's possible to use multiple windows,
 * but Engine is not targeted to it right now then just create a new
 * one window and use it everywhere.
 */

#ifndef WINDOWMANAGER_H
#define WINDOWMANAGER_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "core/Object.h"
#include "core/Color.h"

struct Window : public Object {

	CLASS(Window, Object);

	Window(int width,
		   int height,
		   const std::string & title,
		   uint32_t style = Window::Style::None);

	virtual ~Window() = default;
	
	enum Style {
		None = 0,
		Fullscreen = 1 << 0,
		Resizable = 1 << 1,
		Borderless = 1 << 2
	};

	GLFWwindow * context;

	bool is_open();
	
	void close();

	void clear(const Color & color);
};

class WindowManager : public Object {
	
	CLASS(WindowManager, Object);

	// Singleton
	private:
		WindowManager();
		virtual ~WindowManager() = default;

	public:
		WindowManager(const WindowManager &) 					= delete;
		WindowManager & operator = (const WindowManager &) 		= delete;
		WindowManager(WindowManager &&) 						= delete;
		WindowManager & operator = (WindowManager &&) 			= delete;

		static WindowManager & get_instance();

	public:
		Window * create_window(int width, int height, const std::string & title, uint32_t style = Window::Style::None);

};

#endif // WINDOWMANAGER_H