#include "Node.h"
#include "Wire.h"

 Node::Node() {
     mId = 0;
     mOutput = 0;
     mBias = 0;
     
 }
 
Node::~Node() {

}

bool Node::check() {
    if (mId == -1) {
         std::cout << "Error at Node[" << mId << "] - No id." << std::endl; 
         return false;
    }
    
    
    if (mWires.size() == 0) {
         std::cout << "Error at Node[" << mId << "] - No Wires." << std::endl; 
         return false;
    }
    
    
    for (VecWireIter iter = mWires.begin() ; iter != mWires.end() ; iter++) {
        Wire * pWire = *iter;
       if (!pWire->check())
        return false;
    }
    
    return true;
}

void Node::setId(int id) {
    mId = id;   
    
    int cid = 0;
    for ( VecWireIter iter = mWires.begin() ; iter != mWires.end() ; iter++)
    {
        Wire * wire = *iter; 
        wire->setId( mId + cid );
        cid++;
    }
}

void Node::setBias(float bias) {
    mBias = bias;
}

void Node::calc() {
    float sum = mBias;
    for ( VecWireIter iter = mWires.begin() ; iter != mWires.end() ; iter++)
    {
        Wire * pWire = *iter; 
        sum += pWire->getWeight() * pWire->getNode()->getOutput();
    }
}

    
void Node::debug() {
    std::cout << "Node[ " << mId << "] " << mOutput << std::endl; 
    for ( VecWireIter iter = mWires.begin() ; iter != mWires.end() ; iter++)
    {
        Wire * pWire = *iter; 
        pWire->debug();
    }
}

