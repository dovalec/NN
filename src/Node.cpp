#include "Node.h"
#include "Wire.h"

 Node::Node() {
     mOutput = 0;
     mBias = 0;
 }
 
Node::~Node() {

}

void Node::setBias(float bias) {
    mBias = bias;
}

void Node::clac() {
    float sum = mBias;
    for ( VecWireIter iter = mWires.begin() ; iter != mWires.end() ; iter++)
    {
        Wire * wire = *iter; 
        sum += wire->getWeight() * wire->getNode()->getOutput();
    }
}