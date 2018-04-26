#include "Layer.h"

#include <cstdlib>

Layer::Layer() {
    mId = std::rand();
    std::cout << "Constructed Layer: " << mId<< std::endl; 
}

Layer::~Layer() {
    
}

bool Layer::check() {
    
    std::cout << "Checking Layer[" << mId << "]" << std::endl; 
    
    if (mId == -1) {
         std::cout << "Error at Layer[" << mId << "] - No id." << std::endl; 
         return false;
    }
    
    if (mNodes.size() == 0) {
         std::cout << "Error at Layer[ " << mId << "] - No nodes." << std::endl; 
         return false;
    }
    
    
    for (VecNodeIter iter = mNodes.begin() ; iter != mNodes.end() ; iter++) {
        Node & node = *iter;
       if (!node.check())
        return false;
    }
    
    return true;
}
 

void Layer::init(int size, bool isInput, bool isOutput, Layer & prevLayer, Layer & nextLayer) {
    setSize(size);
    
    
    for (VecNodeIter iter = mNodes.begin() ; iter != mNodes.end() ; iter++) {
        Node & node = *iter;
        
        node.setInputOrOutput(isInput, isOutput);
                
        node.getWires().resize(prevLayer.getSize());
        VecWire & nodeWires = node.getWires();
         
        VecNode & prevNodes = prevLayer.getNodes();
        VecNodeIter prevIter = prevNodes.begin();
        VecWireIter wireIter = nodeWires.begin();
        
        for ( ; prevIter != prevNodes.end() ; prevIter++ , wireIter++) {        
            Node & prevNode = *prevIter;
            Wire & wire = * wireIter;
            wire.setNode((Node*)&prevNode);
        }
    } 

}

void Layer::setSize(int size) {
    for (int n = 0; n < size ; n++) {
        mNodes.push_back(Node());
    }

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

void Layer::setBias(float bias) {
    for (VecNodeIter iter = mNodes.begin() ; iter != mNodes.end() ; iter++) {
        Node & node = *iter;
        node.setBias(bias);
    }
}

void Layer::calc() {
    std::cout << "Calc Layer[ " << mId << " ]" << std::endl; 
    for (VecNodeIter iter = mNodes.begin() ; iter != mNodes.end() ; iter++) {
        Node & node = *iter;
        node.calc();
    }
}


void Layer::debug() {
    std::cout << "\t\tLayer[ " << mId << " ]" << std::endl; 
    for (VecNodeIter iter = mNodes.begin() ; iter != mNodes.end() ; iter++) {
        Node & node = *iter;
        node.debug();
    }
}



