#ifndef TIMER_H
#define TIMER_H

#include "core/Object.h"
#include "core/Time.h"

class Timer : public Object {

	public:	
		Timer();
		virtual ~Timer() = default;

		Time elapsed() const;
		Time restart();

	private:
		Time time;
};

#endif