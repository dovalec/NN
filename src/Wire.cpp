#include "Wire.h"
#include "Node.h"


Wire::Wire() {
    mId = -1;
    mpNode = NULL;
    mWeight = 0;
}

Wire::~Wire() {
    
}

void Wire::setNode( Node * pNode) {
    mpNode = pNode;
}
    
bool Wire::check() {
    
    if (mId == -1) {
         std::cout << "Error at Wire[" << mId << "] - No id." << std::endl; 
         return false;
    }
    
    if (mpNode == NULL) {
         std::cout << "Error at Wire[" << mId << "] - No node attached." << std::endl; 
         return false;
    }
    
    return true;
}

void Wire::debug() {
    std::cout << "Wire[ " << mId << "] " << mWeight << std::endl; 
}