/**
 * Object is the base class for all Engine system classes
 */

#ifndef OBJECT_H
#define OBJECT_H

#include <iostream>
#include "core/EventHandler.h"


class Object : public EventHandler {

	#define CLASS(m_class, m_parent) \
	public: \
		virtual std::string get_class(){ \
			return #m_class; \
		} \
		virtual std::string get_parent_class(){ \
			return #m_parent; \
		} \
		virtual std::string print(std::string message, bool print = true){ \
			message = std::string("[")+ #m_class +"]: " + message; \
			if(print){ \
				std::cout << message << std::endl; \
			} \
			return message; \
		}

	CLASS(Object, EventHandler);

	public:
		Object();
		virtual ~Object() = default;

		void error(std::string message, bool thr = true);

		virtual std::string to_string();
};

#endif