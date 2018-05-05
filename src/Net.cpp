#include "Net.h"

#include <cstdlib>
#include <cmath>

Net::Net() {
    mId = std::rand();
    mError = 0;
    mAvgError = 1.0;
    mAvgErrorFactor = 100;

    //std::cout << "Constructed Net: " << mId << std::endl; 

  
}
 
Net::~Net() {
    //std::cout << "Destruct Net: " << mId << std::endl; 

    for (int n=0;n<mLayers.size() ; n++)
        delete mLayers[n];
}


void Net::backProp(VecFloat & target) {

   calcRmse(target);
   calcGradients(target);
   updateWeights();

}

void Net::calcRmse(VecFloat & target) {

    mError = 0;
    
    VecNode & outpuNodes = mLayers.back()->getNodes();
    
    int targetSize = target.size();
    
    for (int n=0;n<targetSize;n++)
    {
        float delta = target[n] - outpuNodes[n]->getOutput();
        mError += delta * delta;
    }

    mError /= (float)targetSize - 1;
    mError = sqrt(mError);

    mAvgError = (mAvgError * mAvgErrorFactor + mError) / (mAvgErrorFactor + 1.0);
    
}


void Net::calcGradients(VecFloat & target) {
    mLayers.back()->gradientTarget(target);

    for (int n=mLayers.size()-2 ; n > 0 ; n--) {
        Layer * layer = mLayers[n];
        Layer * next = mLayers[n+1];
        layer->gradientHidden(next);
    }      
}

void Net::updateWeights() {
    for (int n=mLayers.size()-1 ; n > 0 ; n--) {
        Layer * layer = mLayers[n];
        Layer * prevLayer = mLayers[n-1];
        layer->updateWeights(prevLayer);
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

   //std::cout << "Feed forward Net[ " << mId << " ]" << std::endl;

    int numLayers = mLayers.size();
    for (int n=1;n<numLayers;n++) {
        mLayers[n]->feedForward(mLayers[n-1]);
    }   
}


void Net::init(VecTopology & topology) {
    int numLayers = topology.size();
        
    for (int n = 0; n < numLayers ; n++) {
        Layer * layer = new Layer();
        layer->init(topology[n]);
        mLayers.push_back(layer);
    }


    for (int n = 0; n < mLayers.size()-1 ; n++) {
        mLayers[n]->initWeights( mLayers[n+1]->getSize());
    }
    
}
 
void Net::debug() {
    std::cout << "Net[ " << mId << " ]" << std::endl; 
    for (VecLayerIter iter = mLayers.begin() ; iter != mLayers.end() ; iter++) {
        Layer * layer = *iter;
        layer->debug();
    }   
}