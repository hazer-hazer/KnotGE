#include "scene/Scene.h"

Scene::Scene(){}

// Root
void Scene::set_root(Node * root){
	this->root = root;
}

Node * Scene::get_root() const {
	return root;
}

