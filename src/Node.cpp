#include "Node.h"
#include "Wire.h"

 Node::Node() {
     mId = 0;
     mOutput = 0;
     mBias = 0;
     
     mInput = false;
     mOutput = false;
     
 }
 
Node::~Node() {

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
        Wire & wire = *iter;
       if (!wire.check())
        return false;
    }
    
    return true;
}

void Node::setInputOrOutput(bool input, bool output) {
    mInput = input;
    mOutput = output;
}

void Node::setId(int id) {
    mId = id;   
    
    int cid = 0;
    for ( VecWireIter iter = mWires.begin() ; iter != mWires.end() ; iter++)
    {
        Wire & wire = *iter; 
        wire.setId( mId/10 + (mId/10)*cid );
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
        Wire & wire = *iter; 
        sum += wire.getWeight() * wire.getNode()->getOutput();
    }
}

    
void Node::debug() {
    std::cout << "\t\t\tNode[ " << mId << " ] " << mOutput << std::endl; 
    for ( VecWireIter iter = mWires.begin() ; iter != mWires.end() ; iter++)
    {
        Wire & wire = *iter; 
        wire.debug();
    }
}

