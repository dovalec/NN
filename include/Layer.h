#pragma once
#include <vector>

#include "Node.h"

class Layer {
public:    
    Layer();
    virtual ~Layer();

    inline int getSize() {
        return mNodes.size();
    }
    
    Node & getNode(int n);

private:
    std::vector<Node> mNodes;
};