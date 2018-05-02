#include "Node.h"
#include "Wire.h"
#include "Layer.h"

#include <cstdlib>
#include "TransformFunc.h"

Node::Node() {
     mId = std::rand();
     //std::cout << "Constructed Node: " << mId << std::endl; 
         
     mOutputVal = 0;
     mGradient = 0;
     mBias = 0;
     
     
 }
 
Node::~Node() {

    //std::cout << "Destruct Node: " << mId << std::endl; 

    for (int n=0;n<mOutWires.size() ; n++)
        delete mOutWires[n];
}

bool Node::check() {
    
    std::cout << "Checking Node[" << mId << "]" << std::endl; 
    
    if (mId == -1) {
         std::cout << "Error at Node[" << mId << "] - No id." << std::endl; 
         return false;
    }
    
    
    if (mOutWires.size() == 0 && mInWires.size() == 0) {
          std::cout << "Error at Node[" << mId << "] - No IN/OUT WiIes." << std::endl; 
          return false;
    }
    
    
    for (VecWireIter iter = mOutWires.begin() ; iter != mOutWires.end() ; iter++) {
        Wire * wire = *iter;
       if (!wire->check())
        return false;
    }
    
    return true;
}

void Node::setBias(float bias) {
    mBias = bias;
}

void Node::feedForward(Layer * prevLayer) {
    //std::cout << "Feed forward Node[ " << mId << " ]" << std::endl; 
    
    float sum = 0;
    VecNode & prevNodes = prevLayer->getNodes();

    //std::cout << prevNodes.size() << " " << mInWires.size() << std::endl;
    for ( int n=0 ; n < prevNodes.size() ; n++)
    {
        Node * prevNode = prevNodes[n];
        Wire * inWire = mInWires[n]; 
        sum += prevNode->getOutput() * inWire->getWeight();
    }
    
    TransformFunc trans;
    mOutputVal = trans.transform(sum);
    
}

void Node::debug() {
    std::cout << "\t\t\tNode[ " << mId << " ] " << mOutputVal << std::endl; 
    for ( VecWireIter iter = mOutWires.begin() ; iter != mOutWires.end() ; iter++)
    {
        Wire * wire = *iter; 
        wire->debug();
    }
}

