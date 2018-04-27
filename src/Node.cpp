#include "Node.h"
#include "Wire.h"

#include <cstdlib>

Node::Node() {
     mId = std::rand();
     std::cout << "Constructed Node: " << mId << std::endl; 
         
     mOutputVal = 0;
     mBias = 0;
     
     mInput = false;
     mOutput = false;
     
 }
 
Node::~Node() {

    std::cout << "Destruct Node: " << mId << std::endl; 

    for (int n=0;n<mWires.size() ; n++)
        delete mWires[n];
}

bool Node::check() {
    
    std::cout << "Checking Node[" << mId << "]" << std::endl; 
    
    if (mId == -1) {
         std::cout << "Error at Node[" << mId << "] - No id." << std::endl; 
         return false;
    }
    
    
    if (mInput == false && mWires.size() == 0) {
         std::cout << "Error at Node[" << mId << "] - No Wires." << std::endl; 
         return false;
    }
    
    
    for (VecWireIter iter = mWires.begin() ; iter != mWires.end() ; iter++) {
        Wire * wire = *iter;
       if (!wire->check())
        return false;
    }
    
    return true;
}

void Node::setInputOrOutput(bool input, bool output) {
    mInput = input;
    mOutput = output;
}


void Node::setBias(float bias) {
    mBias = bias;
}

void Node::calc() {
    std::cout << "Calc Node[ " << mId << " ]" << std::endl; 
    
    float sum = 0;
    for ( VecWireIter iter = mWires.begin() ; iter != mWires.end() ; iter++)
    {
        Wire * wire = *iter; 
        sum += wire->getWeight() * wire->getNode()->getOutput();
    }
    
    mOutputVal = mBias + sum;
    
}

void Node::debug() {
    std::cout << "\t\t\tNode[ " << mId << " ] " << mOutputVal << std::endl; 
    for ( VecWireIter iter = mWires.begin() ; iter != mWires.end() ; iter++)
    {
        Wire * wire = *iter; 
        wire->debug();
    }
}

