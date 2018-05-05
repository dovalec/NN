#include "Node.h"
#include "Layer.h"
#include <stdio.h>
#include <cstdlib>

#include <cmath>


Node::Node() {
     mId = std::rand();
     //std::cout << "Constructed Node: " << mId << std::endl; 
         
     mOutputVal = 0;
     mGradient = 0;
     mBias = 0;
     mTransFunc.setType(TF_EXP);
     
 }
 
Node::~Node() {

    //std::cout << "Destruct Node: " << mId << std::endl; 
}

bool Node::check() {
    
    std::cout << "Checking Node[" << mId << "]" << std::endl; 
    
    if (mId == -1) {
         std::cout << "Error at Node[" << mId << "] - No id." << std::endl; 
         return false;
    }
    
    
    return true;
}

void Node::setBias(float bias) {
    mBias = bias;
}

void Node::initWeights(int nextLayerSize) {
    for (int n=0 ; n < nextLayerSize ; n++)
    {
        float w = (float)rand() / (float)RAND_MAX;
        //printf("%f\n",w);
        mWeights.push_back(w);
        mDeltaWeights.push_back(0);
    }
}
void Node::feedForward(Layer * prevLayer, int i) {
    //std::cout << "Feed forward Node[ " << mId << " ]" << std::endl; 
    
    float act=activation(prevLayer, i);
    mOutputVal = transfer(act);
}

float Node::transfer(float activation) {
    return mTransFunc.transform(activation);
}

float Node::activation(Layer * prevLayer, int i) {
    float sum = 0;
    VecNode & prevNodes = prevLayer->getNodes();

    for ( int n=0 ; n < prevNodes.size() ; n++)
    {
        Node * prevNode = prevNodes[n];
        sum += prevNode->getOutput() * prevNode->getWeight(i);
    }
    
    return sum;
}

void Node::debug() {
    std::cout << "\t\t\tNode[ " << mId << " ] " << mOutputVal << std::endl; 
    
}

