#include "Runner.h"

using namespace std;

int main(int argc, char** argv) {
    cout<< "RTS Resource Manager"<<endl;
    Runner manager;
    manager.Run(argv[1]);
    cout<<"Exiting RTS Resource Manager, Thank You for Using!"<<endl;

    return 0;
}


