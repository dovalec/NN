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

    bool check();
    
    void setId(int id);
    
    void setSize(int size);
    
    inline int getSize() {
        return mNodes.size();
    }

    void feedForward(VecFloat & feed);     
    inline Node & getNode(int n) {
        return mNodes[n]; 
    }
    
    void calc();
    void debug();

private:
    VecNode mNodes;
    int mId;
};