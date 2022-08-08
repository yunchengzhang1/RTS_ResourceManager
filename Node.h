//
// Created by AZ on 8/7/2022.
//

#ifndef RTS_RESOURCEMANAGER_NODE_H
#define RTS_RESOURCEMANAGER_NODE_H

#include <string>
#include <vector>
#include <map>

using namespace std;

class Node {
private:
    // the for this item to be usable
    string item;
    // it relies on the resource
    // map that contains the resource/dependency node
    map<string, Node> *resources = new map<string, Node>;
    // is it usable or not
    bool usable;

public:
    //add node when there is a resource
    Node(string it);
    Node(string it, string resource);

    ~Node() {}

    Node& operator=(const Node& rhs);
    //create INSERT_Node as a main function
    //create DELETE_Node as a main function

    //add a new related resource
    void INSERT_Link(string resource);
    //look for a related resource
    bool SEARCH_Link(string resource);
    //search, then delete a related resource
    bool DELETE_Link(string resource);

    string get_item();
    vector<string> get_resources();
    bool get_usable();

    void set_item(string item);
    void set_usable(bool u);


};


#endif //RTS_RESOURCEMANAGER_NODE_H
