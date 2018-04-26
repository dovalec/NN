#include "Layer.h"

Layer::Layer() {

}

Layer::~Layer() {
    
}

void Layer::feedForward(VecFloat & feed) {
    if ( getSize() != feed.size() ) {
        std::cout << "Feed size are different" << std::endl;
        return;
    }

    int numVals = feed.size();
    for (int n=0;n<numVals;n++) {
        Node & node = getNode(n);
        node.setBias( feed[n] );
    }
    

}


