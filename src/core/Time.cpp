#include "core/Time.h"

double Time::Zero = glfwGetTime();

Time::Time(double time){
	this->time = time;
}

Time Time::now(){
	return Time( glfwGetTime() );
}

double Time::seconds() const {
	return time;
}

int32_t Time::millis() const {
	return (int32_t)(time * 1e+3);
}

int64_t Time::micros() const {
	return (int64_t)(time * 1e+6);
}

Time & Time::operator = (const double & time){
	this->time = time;
	return *this;
}

Time operator + (const Time & lt, const Time & rt){
	return Time(lt.seconds() + rt.seconds());
}

Time operator - (const Time & lt, const Time & rt){
	return Time(lt.seconds() - rt.seconds());
}
