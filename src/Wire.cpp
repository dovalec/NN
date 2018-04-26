#include "Wire.h"
#include "Node.h"

#include <cstdlib>

Wire::Wire() {
    mId = std::rand();
    std::cout << "Constructed Wire: " << mId << std::endl; 
         
    mpNode = NULL;
    mWeight = 0;
    mDeltaWeight = 0;
}

Wire::~Wire() {
    
}

void Wire::setNode( Node * pNode) {
    mpNode = pNode;
}
    
bool Wire::check() {
    
    std::cout << "Checking Wire[" << mId << "]" << std::endl; 
    
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
    std::cout << "\t\t\t\tWire[ " << mId << " ] " << mWeight << " " << mDeltaWeight << std::endl; 
}