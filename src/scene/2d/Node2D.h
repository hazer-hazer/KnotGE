#ifndef NODE2D_H
#define NODE2D_H

#include "scene/Node.h"

typedef std::function<void(void)> DrawFunction;

class Node2D : public Node {

	CLASS(Node2D, Node);

	public:
		Node2D();
		virtual ~Node2D() = default;
			
	// Draw Function
	public:
		void set_draw(DrawFunction draw);
		DrawFunction get_draw();

	private:
		DrawFunction _draw;
};

#endif // NODE2D_H