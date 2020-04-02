#include "core/Timer.h"

Timer::Timer(){}

Time Timer::elapsed() const {
	return Time::now() - time;
}

Time Timer::restart(){
	Time elapsed_time = elapsed();
	time = Time::now();
	return elapsed_time;
}