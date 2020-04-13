#include "scene/2d/Node2D.h"

Node2D::Node2D(){
	on("_draw", [=](){
		if(_draw != nullptr){
			_draw();
		}
	});
}

// Draw
void Node2D::set_draw(DrawFunction draw_func){
	_draw = draw_func;
}

DrawFunction Node2D::get_draw(){
	return _draw;
}