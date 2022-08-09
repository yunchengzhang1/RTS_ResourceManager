//
// Created by AZ on 8/8/2022.
//

#include "Runner.h"


void Runner::Run(string file){
    //if there is file in, do file in

    //entering user interface: select from command
    //INSERT NODE
    //REMOVE NODE
    //PRINT NODE
    //OUTPUT NODE
    //QUIT
}

//create INSERT_Node as a main function
bool Runner::INSERT_Node(string item, string resource){
    //check if there exists Node with the same item key/name:
        //if exists Node with the same item key/name,
            //check if resource repeats
            //if true, print "this is a duplicate
            //else false, Node add a new resource: INSERT_Link
            //also set usable = true
        //else: new item:
            //create new Node object and append to nodes
}
//create DELETE_Node as a main function
bool Runner::DELETE_Node(string item){
    //check if there exists Node with the same item key/name:
        //if exists Node with the same item key/name
            //remove Node with the key from list
            //now search through rest of the nodes for Links
                //if found link, destroy it
                //on link destroyed, if that Node no longer has a link, set usable = false
}