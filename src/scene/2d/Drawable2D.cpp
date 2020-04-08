#include "scene/2d/Drawable2D.h"

Drawable2D::Drawable2D(){
	on("_draw", [=](){
		if(_draw != nullptr){
			_draw();
		}
	});
}

// Draw
void Drawable2D::set_draw(DrawFunction draw_func){
	_draw = draw_func;
}

DrawFunction Drawable2D::get_draw(){
	return _draw;
}