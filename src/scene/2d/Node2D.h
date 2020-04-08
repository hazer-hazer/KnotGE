#ifndef NODE2D_H
#define NODE2D_H

#include "scene/2d/Drawable2D.h"

/**
 * Node2D - Drawable2D + tranformable
 */
class Node2D : public Drawable2D {

	CLASS(Node2D, Drawable2D);

	public:
		Node2D();
		virtual ~Node2D() = default;
			
};

#endif // NODE2D_H