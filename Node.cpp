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
    INSERT_Link(resource);
    usable = true;
}

Node& Node::operator=(const Node& rhs){
    item=rhs.item;
    resources = rhs.resources;
    usable = rhs.usable;
    return *this;
}


//add a new related resource
void Node::INSERT_Link(string resource){
    if (SEARCH_Link(resource) == 0){
        Node tempNode(resource);
        //use emplace to avoid copy of obj
        resources.emplace(resource, tempNode);
    }
}
//look for a related resource
bool Node::SEARCH_Link(string resource){
    auto it = resources.find(resource);
    if (it == resources.end()){
        return false; //not found
    }
    else{
        return true; //found
    }
}
//search, then delete a related resource
bool Node::DELETE_Link(string resource){
    resources.erase(resource);
    return true;
}

string Node::get_item(){
    return item;
}

vector<string> Node::get_resources(){
    auto itr = resources.begin();
    vector<string> result;
    for (itr; itr != resources.end(); itr++){
        result.push_back(itr->first);
    }
    return result;
}
bool Node::get_usable(){
    return usable;
}

int Node::get_resources_size(){
    return resources.size();
}

void Node::set_item(string it){
    item = it;
}
void Node::set_usable(bool u){
    usable = u;
}
