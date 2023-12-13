#include "vector.h"
#include "VectorFunc.hpp"
#include <iostream>

int main(){
    vector<int> vec(4);
    vec.pushback(4);
    vec.append(2,4);
    vec.reserve(8);
    
    for (int i =0; i< vec.Size(); ++i){
        std::cout<<vec[i]<<"\n";
    }
    std::cout<<"_____________________________________________\n";
    vec.pop();
    vec.pop(2);
    
    for (int i =0; i< vec.Size(); ++i){
        std::cout<<vec[i]<<"\n";
    }
    std::cout<<"_____________________________________________\n";
    vector<int> vec2;
    vec2.pushback(1);
    vec = vec2;
    for (int i =0; i< vec.Size(); ++i){
        std::cout<<vec[i]<<"\n";
    }
}