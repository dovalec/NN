#pragma once
#include <vector>

#include "Node.h"

class Layer {
public:    
    Layer();
    virtual ~Layer();

private:
    std::vector<Node> mNodes;
};