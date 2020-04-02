#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H

#include <string>
#include <map>
#include <vector>
#include <functional>

typedef std::function<void()> EventMethod;

typedef std::map <std::string, std::vector <EventMethod>> EventStack;

class EventHandler {
	public:
		EventHandler();
		virtual ~EventHandler();

		void on(std::string name, EventMethod method);
		void emit(std::string name);
		void clear_events(std::string name);
		bool event_exists(std::string name);

		std::size_t get_events_count();
		std::size_t get_event_functions_count(const std::string & name);

	private:
		EventStack events;
};
#endif // EVENTHANDLER_H
