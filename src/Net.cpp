#include "Net.h"

#include <cstdlib>
#include <cmath>

Net::Net() {
    mId = std::rand();
    mError = 0;

    std::cout << "Constructed Net: " << mId << std::endl; 

    mAvgErrorFactor = 100;

}
 
Net::~Net() {
    std::cout << "Destruct Net: " << mId << std::endl; 

    for (int n=0;n<mLayers.size() ; n++)
        delete mLayers[n];
}


void Net::backProp(VecFloat & targetVals) {

   rmse();
   gradient();

}

void Net::rmse() {

    mError = 0;
    
    VecFloat & target = mLayers.back()->getTarget();
    VecNode & outpuNodes = mLayers.back()->getNodes();
    
    int targetSize = target.size();
    
    for (int n=0;n<targetSize;n++)
    {
        float delta = target[n] - outpuNodes[n]->getOutput();
        mError += delta * delta;
    }

    mError /= (float)targetSize;
    mError = sqrt(mError);

    mAvgError += (mAvgError * mAvgErrorFactor + mAvgError) / (mAvgErrorFactor + 1.0);
    
}


void Net::gradient() {
    mLayers.back()->gradientTarget();

    for (int n=mLayers.size()-2 ; n > 0 ; n--) {
        Layer * layer = mLayers[n];
        Layer * next = mLayers[n+1];
        layer->gradientHidden(next);
    }      
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
        Layer * layer = *iter;
       if (!layer->check())
        return false;
    }
    
    return true;
}

void Net::feedForward(VecFloat & in) {
   mLayers[0]->setOutputVal(in);

   std::cout << "Feed forward Net[ " << mId << " ]" << std::endl;

    int numLayers = mLayers.size();
    for (int n=1;n<numLayers;n++) {
        mLayers[n]->feedForward(mLayers[n-1]);
    }   
}

void Net::target(VecFloat & target) {
   mLayers.back()->target(target);
}


void Net::init(VecTopology & topology) {
    int numLayers = topology.size();
        
    for (int n = 0; n < numLayers ; n++) {
        Layer * layer = new Layer();
        layer->init(topology[n]);
        mLayers.push_back(layer);
    }

    
    for (int n = 0; n < mLayers.size()-1 ; n++) {
        mLayers[n]->connect( mLayers[n+1]);
    }
    
}
 
void Net::debug() {
    std::cout << "Net[ " << mId << " ]" << std::endl; 
    for (VecLayerIter iter = mLayers.begin() ; iter != mLayers.end() ; iter++) {
        Layer * layer = *iter;
        layer->debug();
    }   
}