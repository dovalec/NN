#pragma once
#include <vector>
#include <iostream>

#include "Node.h"
#include "Common.h"

typedef std::vector<Node> VecNode;
typedef std::vector<Node>::iterator VecNodeIter;

class Layer {
public:    
    Layer();
    virtual ~Layer();

    inline int getSize() {
        return mNodes.size();
    }

    void feedForward(VecFloat & feed);     
    inline Node & getNode(int n) {
        return mNodes[n]; 
    }

private:
    VecNode mNodes;
};