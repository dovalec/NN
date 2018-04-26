#include "Wire.h"
#include "Node.h"


Wire::Wire() {
    mId = 0;
}

Wire::~Wire() {
    
}

void Wire::setNode( Node * pNode) {
    mpNode = pNode;
}
    
void Wire::debug() {
    std::cout << "Wire[ " << mId << "] " << mWeight << std::endl; 
}