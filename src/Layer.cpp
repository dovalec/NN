#include "Layer.h"

Layer::Layer() {
    mId = 0;
}

Layer::~Layer() {
    
}

bool Layer::check() {
    if (mNodes.size() == 0) {
         std::cout << "Error at Layer[ " << mId << "] - No nodes." << std::endl; 
         return false
    }
    
    
    for (VecNodeIter iter = mNodes.begin() ; iter != mNodes.end() ; iter++) {
        Node & node = *iter;
       if (!node.check())
        return false;
    }
    
    return true;
}


void Layer::setSize(int size) {
    mNodes.resize(size);
}

bool Layer::check() {
    if (mNodes.size() == 0) {
         std::cout << "Error at Layer[ " << mId << "] - No Nodes." << std::endl; 
         return false
    }
    
    
    for (VecNodeIter iter = mNodes.begin() ; iter != mNodes.end() ; iter++) {
        Node & node = *iter;
       if (!node.check())
        return false;
    }
    
    return true;
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



