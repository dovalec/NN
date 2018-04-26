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
    
    VecFloat inputs;
    inputs.push_back(0.1f);
    inputs.push_back(0.2f);
    inputs.push_back(0.4f);
    
    nn.feedForward(inputs);
    
    int trainCount = 100;
    while(trainCount--) {
        nn.calc();
        nn.debug();
    }
    
    return 0;
}
