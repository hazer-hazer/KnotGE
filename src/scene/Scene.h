#ifndef SCENE_H
#define SCENE_H

#include "scene/Node.h"

class Scene : public Object {

	CLASS(Scene, Object);

	public:
		Scene();
		virtual ~Scene() = default;

	// Root
	public:
		void set_root(Node * root);
		Node * get_root() const;

	private:
		Node * root;

	public:
		// Go through tree starting at given root
		// and calling given function with casted Node.
		// This is a universal way to do each cycle step like process, draw and etc.
		template <typename T>
		void through_tree(Node * node, std::function<void(T*)> each){
			node->each_child([this, each](Node * n){
				through_tree(n, each);
			});
			// Go through childs at first and then apply `each` for current
			T * casted = dynamic_cast <T*> (node);
			if(casted != nullptr){
				each(casted);
			}
		}
		template <typename T>
		void through_tree(std::function<void(T*)> each){
			through_tree(root, each);
		}
};

#endif