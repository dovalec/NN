#include "Layer.h"

Layer::Layer() {
    mId = -1;
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
    mNodes.resize(size);
}

void Layer::setId(int id) {
    mId = id;   
    
    int cid = 0;
    for (VecNodeIter iter = mNodes.begin() ; iter != mNodes.end() ; iter++) {
        Node & node = *iter;
        node.setId( mId/10 + (mId/10)*cid );
        cid++;
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

void Layer::calc() {
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



