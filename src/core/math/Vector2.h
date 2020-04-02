#ifndef VECTOR2_H
#define VECTOR2_H

#include <cmath>
#include <string>

struct Vector2 {
	double x = 0;
	double y = 0;

	Vector2() : x(0.f), y(0.f) {};
	Vector2(double nx, double ny) : x(nx), y(ny) {};

	Vector2 operator * (const double & num){
		return Vector2(x * num, y * num);
	}

	Vector2 & operator *= (const double & num){
		x *= num;
		y *= num;
		return *this;
	}

	Vector2 & operator *= (const Vector2 & v){
		x *= v.x;
		y *= v.y;
		return *this;
	}

	double distance_to(Vector2 p);
	void move(Vector2 p);

	std::string to_string();
};

#endif