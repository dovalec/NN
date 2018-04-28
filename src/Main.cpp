#include <iostream>
#include "Net.h"

#include <cstdlib>
#include <stdio.h>

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
    nn.check();
    
    VecFloat feed;;
    feed.push_back(0.1f);
    feed.push_back(0.2f);
    feed.push_back(0.4f);
    
    
    VecFloat target;
    target.push_back(0.4f);
    target.push_back(0.5f);
    target.push_back(0.9f);
    target.push_back(0.3f);

    int trainCount = 100;
    while(trainCount--) {
        nn.feedForward(feed);
        nn.backProp(target);
        std::cout << "Avg error: " <<  nn.avgError() << std::endl;
        //printf("AvgError: %f\n", nn.avgError());

    }
    
    //nn.debug();
    return 0;
}
