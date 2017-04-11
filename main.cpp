#include <iostream>
#include "odometry.h"
using namespace std;
int main() {

    odometry od;
    od.set(3,4,30,3,4);
    double acc[3];
    od.push(acc,3);
    cout<<acc[2]<<endl;
    return 0;
}