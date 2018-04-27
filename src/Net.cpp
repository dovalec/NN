#include "Net.h"

#include <cstdlib>

Net::Net() {
    mId = std::rand();
    mError = 0;

    std::cout << "Constructed Net: " << mId << std::endl; 

}
 
Net::~Net() {
    std::cout << "Destruct Net: " << mId << std::endl; 

    for (int n=0;n<mLayers.size() ; n++)
        delete mLayers[n];
}


void Net::backProp() {

}

float Net::rmse() {

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

void Net::input(VecFloat & in) {
   mLayers.front()->input(in);
}

void Net::target(VecFloat & target) {
   mLayers.back()->target(target);
}


void Net::init(VecTopology & topology) {
    int numLayers = topology.size();
        
    for (int n = 0; n < numLayers ; n++) {
        mLayers.push_back(new Layer());
    }

    mLayers[0]->init(topology[0], true, false, NULL, mLayers[1]);
    
    for (int n = 1; n < mLayers.size()-1 ; n++) {
        mLayers[n]->init(topology[n], false, false, mLayers[n-1], mLayers[n+1]);
    }
    
    mLayers[numLayers-1]->init(topology[numLayers-1], false, true, mLayers[numLayers-2], NULL);    
    
}

void Net::calc() {
    std::cout << "Calc Net[ " << mId << " ]" << std::endl; 
    for (VecLayerIter iter = mLayers.begin() ; iter != mLayers.end() ; iter++) {
        Layer * layer = *iter;
        layer->calc();
    }   
}
 
void Net::debug() {
    std::cout << "Net[ " << mId << " ]" << std::endl; 
    for (VecLayerIter iter = mLayers.begin() ; iter != mLayers.end() ; iter++) {
        Layer * layer = *iter;
        layer->debug();
    }   
}