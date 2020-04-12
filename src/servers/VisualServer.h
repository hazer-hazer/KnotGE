#ifndef VISUALSERVER_H
#define VISUALSERVER_H

#include "core/Object.h"
#include "core/Window.h"

class VisualServer : public Object {

	CLASS(VisualServer, Object);

	// Singleton
	private:
		VisualServer();
		virtual ~VisualServer() = default;

	public:
		VisualServer(const VisualServer &) 					= delete;
		VisualServer & operator = (const VisualServer &) 	= delete;
		VisualServer(VisualServer &&) 						= delete;
		VisualServer & operator = (VisualServer &&) 		= delete;

		static VisualServer & get_instance();


	// Window
	public:
		void set_window(Window * window);
		Window * get_window() const;

	private:
		Window * window;

};

#endif