#include "Layer.h"

#include <cstdlib>

Layer::Layer() {
    mId = std::rand();
    std::cout << "Constructed Layer: " << mId<< std::endl; 
}

Layer::~Layer() {
    std::cout << "Destruct Layer: " << mId<< std::endl; 

    for (int n=0;n<mNodes.size() ; n++)
        delete mNodes[n];
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
        Node * node = *iter;
       if (!node->check())
        return false;
    }
    
    return true;
}
 

void Layer::init(int size, bool isInput, bool isOutput, Layer * prevLayer, Layer * nextLayer) {
    setSize(size);
    
    
    for (VecNodeIter iter = mNodes.begin() ; iter != mNodes.end() ; iter++) {
        Node * node = *iter;
        
        node->setInputOrOutput(isInput, isOutput);
                
        VecWire & nodeWires = node->getWires();
        if (prevLayer) {
            for (int n=0;n<prevLayer->getSize() ; n++) 
            {
                Node * prevNode = prevLayer->getNode(n);
                Wire * wire = new Wire();
                wire->setNode(prevNode);
                nodeWires.push_back(wire);
            }
        }
         
    } 

}

void Layer::setSize(int size) {
    for (int n = 0; n < size ; n++) {
        mNodes.push_back(new Node());
    }
}



void Layer::input(VecFloat & in) {
    if ( getSize() != in.size() ) {
        std::cout << "Input size is different" << std::endl;
        return;
    }

    int numVals = in.size();
    for (int n=0;n<numVals;n++) {
        Node * node = getNode(n);
        node->setBias( in[n] );
    }
    
}

void Layer::target(VecFloat & target) {
    if ( getSize() != target.size() ) {
        std::cout << "target size is different" << std::endl;
        return;
    }

    // int numVals = target.size();
    // for (int n=0;n<numVals;n++) {
    //     Node * node = getNode(n);
    //     node->setBias( in[n] );
    // }
    
}

void Layer::setBias(float bias) {
    for (VecNodeIter iter = mNodes.begin() ; iter != mNodes.end() ; iter++) {
        Node * node = *iter;
        node->setBias(bias);
    }
}

void Layer::calc() {
    std::cout << "Calc Layer[ " << mId << " ]" << std::endl; 
    for (VecNodeIter iter = mNodes.begin() ; iter != mNodes.end() ; iter++) {
        Node * node = *iter;
        node->calc();
    }
}


void Layer::debug() {
    std::cout << "\t\tLayer[ " << mId << " ]" << std::endl; 
    for (VecNodeIter iter = mNodes.begin() ; iter != mNodes.end() ; iter++) {
        Node * node = *iter;
        node->debug();
    }
}



