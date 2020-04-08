#ifndef DRAWABLE2D_H
#define DRAWABLE2D_H

#include "scene/Node.h"

typedef std::function<void(void)> DrawFunction;

class Drawable2D : public Node {

	CLASS(Drawable2D, Node);

	public:
		Drawable2D();
		virtual  ~Drawable2D() = default;
	
	// Draw Function
	public:
		void set_draw(DrawFunction draw);
		DrawFunction get_draw();

	private:
		DrawFunction _draw;

};

#endif