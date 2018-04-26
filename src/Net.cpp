#include "Net.h"

#include <cstdlib>

Net::Net() {
    mId = std::rand();
    std::cout << "Constructed Net: " << mId << std::endl; 
}
 
Net::~Net() {

}

bool Net::check() {
    
    std::cout << "Checking Net[" << mId << "]" << std::endl; 
         
    if (mId == -1) {
         std::cout << "Error at Net[" << mId << "] - No id." << std::endl; 
         return false;
    }
    
    if (mLayers.size() == 0) {
         std::cout << "Error at Net[" << mId << "] - No layer." << std::endl; 
         return false;
    }
    
    
    for (VecLayerIter iter = mLayers.begin() ; iter != mLayers.end() ; iter++) {
        Layer & layer = *iter;
       if (!layer.check())
        return false;
    }
    
    return true;
}

void Net::feedForward(VecFloat & feed) {
   mLayers.front().feedForward(feed);
}

void Net::init(VecTopology & topology) {
    int numLayers = topology.size();
        
    for (int n = 0; n < numLayers ; n++) {
        mLayers.push_back(Layer());
    }

    Layer dummyLayer;
    mLayers[0].init(topology[0], true, false, dummyLayer, mLayers[1]);
    
    for (int n = 1; n < mLayers.size()-1 ; n++) {
        mLayers[n].init(topology[n], false, false, mLayers[n-1], mLayers[n+1]);
    }
    
    mLayers[numLayers-1].init(topology[numLayers-1], false, true, mLayers[numLayers-2], dummyLayer);    
    
}

void Net::calc() {
    std::cout << "Calc Net[ " << mId << " ]" << std::endl; 
    for (VecLayerIter iter = mLayers.begin() ; iter != mLayers.end() ; iter++) {
        Layer & layer = *iter;
        layer.calc();
    }   
}
 
void Net::debug() {
    std::cout << "Net[ " << mId << " ]" << std::endl; 
    for (VecLayerIter iter = mLayers.begin() ; iter != mLayers.end() ; iter++) {
        Layer & layer = *iter;
        layer.debug();
    }   
}