/**
 * Window 
 *
 * Window struct is just a wrapper for glfw Window.
 * It doesn't store anything except of static usability things.
 */

#ifndef WINDOW_H
#define WINDOW_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "core/Object.h"
#include "core/Color.h"
#include "core/math/Vector2.h"

#define WINDOW_DEFAULT_STYLE 1

// TODO: Window events (e.g. `resized`)

struct Window : public Object {

	CLASS(Window, Object);

	Window(const int & width,
		   const int & height,
		   const std::string & title,
		   const uint8_t & style = WINDOW_DEFAULT_STYLE);

	virtual ~Window() = default;
	
	/**
	 * Window Style
	 * Each bit for special window style status
	 * Some statuses overlap over, like Default automatically sets everything to default
	 * and None set everything to 0.
	 *
	 * Default = Resizable | !Fullscreen | !Borderless | !AlwaysOnTop
	 * So... Defaul is just `Resizable` that equals `1`
	 */
	enum Style {
		None = 0,
		Resizable = 1 << 0,
		Fullscreen = 1 << 1,
		Borderless = 1 << 2,
		AlwaysOnTop = 1 << 3
	};

	GLFWwindow * context;

	void destroy();

	bool is_open();
	
	void close(const bool & close_opt = true);

	void clear(const Color & color);

	void set_title(const char * title);

	// Visibility
	bool is_visible() const;
	void set_visible(const bool & visible = true);
	void show();
	void hide();
	void toggle();

	// Size
	void set_size(const V2i & size);
	V2i get_size() const;

	// Style methods
	void set_style(const uint8_t & style);

	void set_resizable(const bool & resizable = true);
	void set_fullscreen(const bool & fullscreen = true);
	void set_borderless(const bool & borderless = true);
	void set_always_on_top(const bool & always_on_top = true);

	bool is_fullscreen() const;

	// Opacity
	void set_opacity(const float & opacity);

	// Callbacks
	static void size_callback(GLFWwindow * window, int width, int height){
		void * ctx_ptr = glfwGetWindowUserPointer(window);
		if (Window * win_ptr = static_cast<Window*>(ctx_ptr)){
			win_ptr->emit("resized");
		}
	}
	static void framebuffer_callback(GLFWwindow * window, int width, int height){
		glViewport(0, 0, width, height);
	}
};

#endif