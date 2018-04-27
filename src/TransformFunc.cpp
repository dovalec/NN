#include "TransformFunc.h"
#include <math.h>
#include <stdlib.h> 

TransformFunc::TransformFunc() {
    mType = TF_TANH;
}

TransformFunc::~TransformFunc() {

}

float TransformFunc::transform(float x) {

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
    }
}

float TransformFunc::transformcDeriv(float x) {
    return 1.0f - x*x; 
}
