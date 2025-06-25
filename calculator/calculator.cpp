#include <cmath>
#include <string>
#include "calculator.h"


void Calculator::Set(Number n){
    result_ = n;
}

Number Calculator::GetNumber() const{
    return result_;
}

void Calculator::Add(Number n){
    result_ += n;
}

void Calculator::Sub(Number n){
    result_ -= n;
}

void Calculator::Div(Number n){
    result_ /= n;
}

void Calculator::Mul(Number n){
    result_ *= n;
}

void Calculator::Pow(Number n){
    result_ = std::pow(result_, n);
}

void Calculator::Save(){
    memory_ = result_;
    saved_ = true;
}

void Calculator::Load(){
    result_ = memory_;
}

bool Calculator::HasMem() const{
    return saved_;
}

std::string Calculator::GetNumberRepr() const{
    return std::to_string(result_);
}
