#include "Net.h"


Net::Net() {
    
}

Net::~Net() {

}

bool Net::check() {
    if (mLayers.size() == 0) {
         std::cout << "Error at Net[ " << mId << "] - No layerד." << std::endl; 
         return false
    }
    
    
    for (VecLayerIter iter = mLayers.begin() ; iter != mLayers.end() ; iter++) {
        Layer & layer = *iter;
       if (!layer.check())
        return false;
    }
    
    return true;
}

void Net::setId(int id) {
    mId = id;   
    
    int cid = 0;
    for (VecLayerIter iter = mLayers.begin() ; iter != mLayers.end() ; iter++) {
        Layer & layer = *iter;
        layer.setId( mId + cid );
        cid++;
    }
}

void Net::feedForward(VecFloat & feed) {
   mLayers.front().feedForward(feed);
}

void Net::init(VecTopology & topology) {
    int numLayers = topology.size();
    mLayers.resize(numLayers);
    
    for (int n = 0; n < numLayers ; n++) {
        mLayers[n].setSize(topology[n]);
    }
}

void Net::debug() {
    std::cout << "Net[ " << mId << "]" << std::endl; 
    for (VecLayerIter iter = mLayers.begin() ; iter != mLayers.end() ; iter++) {
        Layer & layer = *iter;
        layer.debug();
    }   
}