#pragma once

#include <cmath>
#include <stdlib.h> 
#include <algorithm>    // std::max

enum TransFuncType { TF_ATAN_PI, TF_ATAN, TF_EXP, TF_SQRT, TF_ERF_SQRT, TF_TANH, TF_ABS, TF_RELU };

class TransformFunc {
public:
    TransformFunc();
    virtual ~TransformFunc();

public:
    
    inline float transform(float x) {
        switch(mType) {
            case TF_ATAN_PI:
                return atan(M_PI*x/2)*2/M_PI;

            case TF_ATAN:
                return atan(x);          

            case TF_EXP:
                return 1/(1+exp(-x));    

            case TF_SQRT:
                return 1/sqrt(1 + x*x);   

            case TF_ERF_SQRT:
                return erf(sqrt(M_PI)*x/2.0);

            case TF_TANH:
                return tanh(x);          

            case TF_ABS:
                return x/(1+abs(x));    

            case TF_RELU:
                if (x>0)
                {
                    return 1;
                }
                else {
                    return -1;
                }
                //return std::max(x,0.0f);        
        }
    }

    inline float transformDeriv(float x) {
        return 1 - x*x; 
    }


    void setType(TransFuncType type) {
        mType = type;
    }
private:
    TransFuncType mType;
};