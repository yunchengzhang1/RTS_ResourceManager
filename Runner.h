//
// Created by AZ on 8/8/2022.
//
#include <iostream>
#include <fstream>
#include "Node.h"
#ifndef RTS_RESOURCEMANAGER_RUNNER_H
#define RTS_RESOURCEMANAGER_RUNNER_H


class Runner {
private:
    map<string, Node> nodes;
public:
    void Run(string file);

    //create INSERT_Node as a main function
    bool INSERT_Node(string item, string resource);
    //create DELETE_Node as a main function
    bool DELETE_Node(string item);

    //Terminal UI function

    //file output

};


#endif //RTS_RESOURCEMANAGER_RUNNER_H
