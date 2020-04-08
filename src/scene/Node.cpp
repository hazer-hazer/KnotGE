#include "scene/Node.h"

Node::Node(){
}

// Ready Function
void Node::set_ready(ReadyFunction ready_func){
	_ready = ready_func;
}

ReadyFunction Node::get_ready(){
	return _ready;
}

// Process Function
void Node::set_process(ProcessFunction process_func){
	_process = process_func;
}

ProcessFunction Node::get_process(){
	return _process;
}

// Children

// Insert a child as a pair of its name and object
void Node::add_child(Node * child){
	if(this == child){
		throw NODE_ADD_CHILD_THIS_EXCEPTION;
	}
    child->parent = this;
	children.push_back(child);
}

// Get Children as map <string, Node *>
NodeChildren Node::get_children(){
	return children;
}

void Node::each_child(std::function<void(Node *)> each){
	for(auto n : children){
		each(n);
	}
}

// Get Children as vector
NodeChildrenMap Node::get_children_map(){
    NodeChildrenMap map;
	for(auto child : children){
		map.insert({ child->get_name(), child });
	}
	return map;
}

bool Node::has_child_with_name(std::string name){
	for(auto child : children){
		if(child->get_name() == name){
			return true;
		}
	}
	return false;
}

std::string Node::get_name(){
	return name;
}

void Node::set_name(std::string name){
	// Avoid siblings' similar names
	// TODO: Add auto-naming instead of `return`
	if(parent != nullptr && parent->has_child_with_name(name)){
		return;
	}
	this->name = name;
}

void Node::set_name(){
	set_name(get_class());
}