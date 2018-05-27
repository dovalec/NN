#include "Node.h"
#include "Layer.h"
#include <stdio.h>
#include <cstdlib>

#include <cmath>


Node::Node() {
     mId = std::rand();
     //std::cout << "Constructed Node: " << mId << std::endl; 
         
    reset();

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
    mWeights.clear();
    mDeltaWeights.clear();

    for (int n=0 ; n < nextLayerSize ; n++)
    {
        float w = ((float)rand() / (float)(RAND_MAX >> 1)) - 1.0f;
        mWeights.push_back(w);
        mDeltaWeights.push_back(0.0f);
    }

}
void Node::feedForward(Layer * prevLayer, int i) {
    //std::cout << "Feed forward Node[ " << mId << " ]" << std::endl; 
    
    float act=activation(prevLayer, i);
    mOutputVal = mTransFunc.transform(act);
    //mOutputVal = act;
    
    //std::cout << mId << ":" << mOutputVal << std::endl;
}


float Node::activation(Layer * prevLayer, int i) {
    
    VecNode & prevNodes = prevLayer->getNodes();

    float sum = 0.0f;

    for ( int n=0 ; n < prevNodes.size() ; n++)
    {
        Node * prevNode = prevNodes[n];
        sum += prevNode->getOutput() * prevNode->getWeight(i);
        //std::cout << sum << std::endl;

    }
    
    return sum;
}

float Node::activationNormal(Layer * prevLayer, int i) {
    float sum = 0;
    VecNode & prevNodes = prevLayer->getNodes();

    float sumWeights = 0.0f;
    for ( int n=0 ; n < prevNodes.size() ; n++)
    {   
        sumWeights += prevNodes[n]->getWeight(i);
    }

    for ( int n=0 ; n < prevNodes.size() ; n++)
    {
        Node * prevNode = prevNodes[n];
        sum += prevNode->getOutput() * (prevNode->getWeight(i) / sumWeights);
    }
    
    return sum;
}


void Node::debug() {
    std::cout << "\t\t\tNode[ " << mId << " ] " << mOutputVal << std::endl; 
}

void Node::reset() {

    mOutputVal = 0;
     mGradient = 0;
     mBias = 0;
     mTransFunc.setType(TF_ABS);
     
}
