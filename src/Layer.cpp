#include "Layer.h"

Layer::Layer() {
    mId = -1;
}

Layer::~Layer() {
    
}

bool Layer::check() {
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


void Layer::init(int size, Layer & prevLayer) {
    setSize(size);
    
    VecNodes & prevNodes = prevLayer.getNodes();
    
    for (VecNodeIter iter = mNodes.begin(),  ; iter != mNodes.end() ; iter++) {
        Node & myNode = *iter;
    
        for (VecNodeIter prevIter = prevNodes.begin(),  ; prevIter != prevNodes.end() ; prevIter++) {
            
        
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
        node.setId( mId + cid );
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
    std::cout << "Layer[ " << mId << "]" << std::endl; 
    for (VecNodeIter iter = mNodes.begin() ; iter != mNodes.end() ; iter++) {
        Node & node = *iter;
        node.debug();
    }
}



