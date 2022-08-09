#include "Runner.h"

using namespace std;

int main() {
    cout<< "RTS Resource Manager"<<endl;



    //for testing
    Node test_node("ore");
    cout<<test_node.get_item()<<endl;

    Node test_node1("bullet", "ore");
    vector<string> testnode1_resources = test_node1.get_resources();
    cout<<test_node1.get_item()<<endl;


    return 0;
}


