#ifndef TIME_H
#define TIME_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "core/Object.h"

// TODO: operator overloading for every case

class Time : public Object {

	CLASS(Time, Object);

	public:
		Time(double time = Time::Zero);
		virtual ~Time() = default;

		static double Zero;
		static Time now();

		void set(const double & seconds);

		double seconds() const;
		int32_t millis() const;
		int64_t micros() const;

		Time & operator = (const double & time);

		friend Time operator + (const Time & lt, const Time & rt); 
		friend Time operator - (const Time & lt, const Time & rt); 

	private:
		double time;
};

#endif