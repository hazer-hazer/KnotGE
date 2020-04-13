#ifndef VECTOR2_H
#define VECTOR2_H

#include <cmath>
#include <string>

template <typename T>
struct V2 {
	T x = 0;
	T y = 0;

	V2() : x(0), y(0) {};
	V2(T nx, T ny) : x(nx), y(ny) {};

	V2 operator * (const T & num){
		return V2(x * num, y * num);
	}

	V2 & operator *= (const T & num){
		x *= num;
		y *= num;
		return *this;
	}

	V2 & operator *= (const V2 & v){
		x *= v.x;
		y *= v.y;
		return *this;
	}

	T distance_to(V2 p){
		return sqrt( pow(p.x - x, 2) + pow(p.y - y, 2) );
	}

	void move(V2 p){
		x += p.x;
		y += p.y;
	}

	std::string to_string(){
		return std::to_string(x) + ":" + std::to_string(y);
	}
};

typedef V2 <int> V2i;
typedef V2 <float> V2f;
typedef V2 <double> V2d;

// For JacyScript Type V2 is always V2<float>
typedef V2 <float> Vector2;

#endif