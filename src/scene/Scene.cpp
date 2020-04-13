#include "scene/Scene.h"

Scene::Scene(){}

// Root
void Scene::set_root(Node * root){
	this->root = root;
}

Node * Scene::get_root() const {
	return root;
}

void Scene::set_pause(bool pause){
	_paused = pause;
}

bool Scene::is_paused() const {
	return _paused;
}