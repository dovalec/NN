#pragma once

enum TransFuncType { TF_ATAN_PI, TF_ATAN, TF_EXP, TF_SQRT, TF_ERF_SQRT, TF_TANH, TF_ABS };

class TransformFunc {
public:
    TransformFunc();
    virtual ~TransformFunc();

public:
    float transform(float x);
    float transformDeriv(float x);

private:
    TransFuncType mType;
};