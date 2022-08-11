//
// Created by AZ on 8/8/2022.
//

#include "Runner.h"


void Runner::Run(string file_name){
    //if there is file in, do file in
    cout<<"start running "<<file_name<<endl;
    ifstream inFile;
    inFile.open(file_name);
    if (inFile.is_open()){//if file is open, read in nodes to map
        cout<<"file "<< file_name <<" found, converting data to nodes..." <<endl;
        string item, resource;
        while(inFile >> item >> resource){
            // insert read-in nodes
            INSERT_Node(item, resource);
        }
    }
    else{//if file is not open, ask user if continue the program
        cout<<"file not found, would you still like to continue with the program? Y/N"<<endl;
        alive = stay_alive();
    }

    while (alive){
        //entering user interface: select from command
        cout<<"Please select from the following commands (one letter):"<<endl<<
        "I[INSERT]   R[REMOVE]   D[DISPLAY]   O[OUTPUT]   Q[QUIT]"<<endl<<"> ";
        char input;
        cin>> input;
        input = tolower(input);
        cout<<input<<endl;
        switch(input) {
            case 'i':         //INSERT NODE
                insert_query();
                break;
            case 'r':        //REMOVE NODE
                delete_query();
                break;
            case 'd':        //DISPLAY NODE
                display_nodes();
                break;
            case 'o':        //OUTPUT NODE
                output_file();
                break;
            case 'q':        //QUIT
                alive = false;
                break;
        }
    }

}

//create INSERT_Node as a main function
bool Runner::INSERT_Node(string item, string resource){
    //check if there exists Node with the same item key/name:
    auto itr = nodes.find(item);
        //if exists Node with the same item key/name,
        if (itr != nodes.end()){
            //check if resource repeats
            bool found_resource = itr->second.SEARCH_Link(resource);
            //if true, print "this is a duplicate
            if (found_resource){
                cout<<"duplicated Node, resource already exists!"<<endl;
            }
            //else false, Node add a new resource: INSERT_Link
            else{
                itr->second.INSERT_Link(resource);
                //also set usable = true
                itr->second.set_usable(true);
            }
        }
            //else: new item:
        else {
            //create new Node object and emplace to nodes
            Node new_node(item, resource);
            nodes.emplace(item, new_node);
        }
}
//create DELETE_Node as a main function
bool Runner::DELETE_Node(string item){
    //check if there exists Node with the same item key/name:
    auto itr = nodes.find(item);
        //if exists Node with the same item key/name
    if (itr != nodes.end()) {
        //remove Node with the key from list
        nodes.erase(item);
        //now search through rest of the nodes for Links
        auto it_remain = nodes.begin();
        for (it_remain; it_remain!=nodes.end(); it_remain++){
            //if found link, destroy it
            it_remain->second.DELETE_Link(item);
            //on link destroyed, if that Node no longer has a link, set usable = false
        }
        return true;
    }
    return false;
}

bool Runner:: stay_alive(){
    char yn;
    cin>> yn;
    yn = tolower(yn);
    switch(yn) {
        case 'y':
            return true;
        case 'n':
            return false;
    }
}

void Runner::display_nodes(){
    auto nodes_itr = nodes.begin();
    for (nodes_itr; nodes_itr != nodes.end(); nodes_itr++){
        cout<<nodes_itr->first<<" -> ";
        vector<string> resources = nodes_itr->second.get_resources();
        for (int i=0; i<resources.size(); i++){
            cout<<resources[i]<<" ";
        }
        cout<<endl;
    }
}
bool Runner::insert_query(){
    string item, resource;
    cout<< "Type in your ITEM and RESOURCE in such order: \"turret bullets\""<<endl<<">";
    cin >> item >> resource;
    while (true){
        if (item != "" && resource !=""){
            return INSERT_Node(item, resource);
        }
        else{
            cout<<"please input in the exact format: \"turret bullets\""<<endl;
            cout<<"would you still like to continue with INSERT? Y/N"<<endl;
            bool yn = stay_alive();
            if (!yn){// if yn is false, return false and exit out INSERT
                return yn;
            }
        }
    }
}
bool Runner::delete_query(){
    string item;
    cout<< "Type in the item you wish to delete: "<<endl<<">";
    cin >> item;
    while (true){
        bool delete_success = DELETE_Node(item);
        if (delete_success == true){
            return true;
        }
        else{
            cout<<"keyword/item not found, would you still like to continue with DELETE? Y/N"<<endl;
            bool yn = stay_alive();
            if (!yn){// if yn is false, return false and exit out DELETE
                return yn;
            }
        }
    }
}
void Runner::output_file(){
    ofstream ofile;
    string filename;
    cout<<"type in the filename you would prefer: ";
    cin>> filename;
    string oname = filename + ".txt";
    ofile.open(oname);
    auto nodes_itr = nodes.begin();
    for (nodes_itr; nodes_itr != nodes.end(); nodes_itr++){
        ofile<<nodes_itr->first<<" ";
        vector<string> resources = nodes_itr->second.get_resources();
        for (int i=0; i<resources.size(); i++){
            ofile<<resources[i]<<" ";
        }
        ofile<<endl;
    }
}