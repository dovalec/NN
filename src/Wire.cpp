#include "Wire.h"
#include "Node.h"


Wire::Wire() {

}

Wire::~Wire() {
    
}

void Wire::setNode( Node * pNode) {
    mpNode = pNode;
}
    