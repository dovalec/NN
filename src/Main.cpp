#include <iostream>
#include "Net.h"

int main(void) {
    std::cout << "NN" << std::endl;
    Net nn;

    VecTopology topology;
    topology.push_back(3);
    topology.push_back(4);
    topology.push_back(5);
    topology.push_back(5);
    topology.push_back(4);
    
    nn.init(topology);
    
    return 0;
}
