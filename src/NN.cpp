#include "NN.h"
#include <iostream>

NN::NN() {
    
}

NN::~NN() {

}

void NN::feedForward(VecFloat & feed) {
   mLayers.front().feedForward(feed);
}

void NN::init(int numLayers) {
    mLayers.resize(numLayers);
}