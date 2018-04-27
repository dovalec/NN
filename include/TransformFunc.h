#pragma once

enum TransFuncType { TF_ATAN_PI, TF_ATAN, TF_EXP, TF_SQRT, TF_ERF_SQRT, TF_TANH, TF_ABS };

class TransformFunc {
    TransformFunc();
    ~TransformFunc();

    float transform(float x);
    float transformcDeriv(float x);

private:
    TransFuncType mType;
};