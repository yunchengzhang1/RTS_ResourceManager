//
// Created by AZ on 8/7/2022.
//

#include "Node.h"


//add node when there is a resource
Node::Node(string it){
    item = it;
    usable = true;
}
Node::Node(string it, string resource){
    item = it;
    usable = true;
}

Node& Node::operator=(const Node& rhs){
    item=rhs.item;
    resources = rhs.resources;
    usable = rhs.usable;
    return *this;
}
//create INSERT_Node as a main function
//create DELETE_Node as a main function

//add a new related resource
void Node::INSERT_Link(string resource){

}
//look for a related resource
bool Node::SEARCH_Link(string resource){

}
//search, then delete a related resource
bool Node::DELETE_Link(string resource){

}

string Node::get_item(){

}
vector<string> Node::get_resources(){

}
bool Node::get_usable(){

}

void Node::set_item(string item){

}
void Node::set_usable(bool u){

}
