#include "Layer.h"

#include <cstdlib>

Layer::Layer() {
    mId = std::rand();
    //std::cout << "Constructed Layer: " << mId<< std::endl; 
}

Layer::~Layer() {
    //std::cout << "Destruct Layer: " << mId<< std::endl; 

    for (int n=0;n<mNodes.size() ; n++)
        delete mNodes[n];
}

bool Layer::check() {
    
    std::cout << "Checking Layer[" << mId << "]" << std::endl; 
    
    if (mId == -1) {
         std::cout << "Error at Layer[" << mId << "] - No id." << std::endl; 
         return false;
    }
    
    if (mNodes.size() == 0) {
         std::cout << "Error at Layer[ " << mId << "] - No nodes." << std::endl; 
         return false;
    }
    
    
    for (VecNodeIter iter = mNodes.begin() ; iter != mNodes.end() ; iter++) {
        Node * node = *iter;
       if (!node->check())
        return false;
    }
    
    return true;
}
 

void Layer::init(int size) {
    for (int n = 0; n < size ; n++) {

        Node * node = new Node();
        mNodes.push_back(node);
    }
}

void Layer::connect(Layer * nextLayer) {
    
    
    for (VecNodeIter iter = mNodes.begin() ; iter != mNodes.end() ; iter++) {
        Node * node = *iter;
        
        VecWire & nodeOutWires = node->getOutWires();
        
        for (int n=0;n<nextLayer->getSize() ; n++) 
        {
            Node * nextNode = nextLayer->getNode(n);
            Wire * wire = new Wire();
            wire->setInNode(node);
            wire->setOutNode(nextNode);
            nodeOutWires.push_back(wire);

            VecWire & nextInWires = nextNode->getInWires();
            nextInWires.push_back(wire);
        
        }
    }
        

}


void Layer::setOutputVal(VecFloat & in) {
    if ( getSize() != in.size() ) {
        std::cout << "Input size is different" << std::endl;
        return;
    }

    int numVals = in.size();
    for (int n=0;n<numVals;n++) {
        Node * node = getNode(n);
        node->setOutput( in[n] );
    }
    
}

void Layer::gradientTarget(VecFloat & target) {

    if ( getSize() != target.size() ) {
        std::cout << "Error Target size != Layer size" << std::endl;
        return;
    }

    for (int n=0;n < mNodes.size() ; n++) {
        float delta = target[n] - mNodes[n]->getOutput();
        float gradient = delta * mTransformFunc.transformDeriv(mNodes[n]->getOutput());
        
    } 
}

void Layer::gradientHidden(Layer * nextLayer) {
   

    int numNodes = mNodes.size();

    for (int n=0;n < numNodes ; n++) {
        float dow = sumDow(mNodes[n], nextLayer);
        float gradient = dow * mTransformFunc.transformDeriv(mNodes[n]->getOutput());
        mNodes[n]->setGradient(gradient);
    } 

}

float Layer::sumDow(Node * node, Layer * nextLayer) {
    
    float sum = 0.0f;

    int numNodes = nextLayer->getSize();
    for (int n=0;n < numNodes; n++) {
        Node * nextNode = nextLayer->getNode(n);
        sum += node->getOutWire(n)->getWeight() * nextNode->gradient();
    }

    return sum;
}

void Layer::updateWeights(Layer * prevLayer) {

    float ETA = 0.15;
    float ALPHA = 0.5;

    for (int n=0;n<mNodes.size();n++) {
        Node * node = mNodes[n];
        for (int p = 0 ; p<prevLayer->getSize() ; p++)
        {
            Node * prevNode = prevLayer->getNode(p);
            float oldDelta = prevNode->getOutWire(n)->getDeltaWeight();
            float newDelta = ETA * prevNode->getOutput() * node->gradient() + ALPHA * oldDelta;

            prevNode->getOutWire(n)->setDeltaWeight(newDelta);
            prevNode->getOutWire(n)->setWeight(prevNode->getOutWire(n)->getWeight() + newDelta );
        }
    }
}

void Layer::setBias(float bias) {
    mNodes.back()->setOutput(bias);
}

void Layer::feedForward(Layer * prevLayer) {
    //std::cout << "Feed forward Layer[ " << mId << " ]" << std::endl; 
    for (int n=0; n < mNodes.size() ; n++) {
        Node * node = mNodes[n];
        node->feedForward(prevLayer);
    }
}


void Layer::debug() {
    std::cout << "\t\tLayer[ " << mId << " ]" << std::endl; 
    for (VecNodeIter iter = mNodes.begin() ; iter != mNodes.end() ; iter++) {
        Node * node = *iter;
        node->debug();
    }
}



