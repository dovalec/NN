#include "Wire.h"
#include "Node.h"

#include <cstdlib>

Wire::Wire() {
    mId = std::rand();
    //std::cout << "Constructed Wire: " << mId << std::endl; 
         
    mInNode = NULL;
    mOutNode = NULL;
    
    mWeight = (float)std::rand() / (float)RAND_MAX;
    mDeltaWeight = 1.0;
}

Wire::~Wire() {
    //std::cout << "Destruct Wire: " << mId << std::endl; 

}

void Wire::setInNode( Node * node) {
    mInNode = node;
}
    
void Wire::setOutNode( Node * node) {
    mOutNode = node;
}

bool Wire::check() {
    
    std::cout << "Checking Wire[" << mId << "]" << std::endl; 
    
    if (mId == -1) {
         std::cout << "Error at Wire[" << mId << "] - No id." << std::endl; 
         return false;
    }
    
    if (mInNode == NULL) {
         std::cout << "Error at Wire[" << mId << "] - No IN node attached." << std::endl; 
         return false;
    }
    

    if (mOutNode == NULL) {
         std::cout << "Error at Wire[" << mId << "] - No OUT node attached." << std::endl; 
         return false;
    }
    
    return true;
}

void Wire::debug() {
    std::cout << "\t\t\t\tWire[ " << mId << " ] " << mWeight << " " << mDeltaWeight << std::endl; 
}