#include "Vector2.h"

double Vector2::distance_to(Vector2 p){
	return sqrt( pow(p.x - x, 2) + pow(p.y - y, 2) );
}

void Vector2::move(Vector2 p){
	x += p.x;
	y += p.y;
}

std::string Vector2::to_string(){
	return std::to_string(x) + ":" + std::to_string(y);
}