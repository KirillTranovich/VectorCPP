#pragma once 
#include "vector.h"
#include <iostream>

template <typename T>
vector<T>::vector(){
    size = 0;
    rsize = size;
    Array = new T[0];
}

template <typename T>
vector<T>::vector(int size){
    this->size = size;
    rsize = size;
    Array = new T[size];
}

//template <typename T>
//T& vector<T>::pushback(T input){
//    T* ArrayCopy = Array;
//    if (rsize<size+1){
//        rsize = size+1;
//        Array = new T[rsize];
//    }
//    for (int i=0;i< size;++i)
//        *(Array+i)=*(ArrayCopy+i);
//    Array[size] = input;
//    delete[] ArrayCopy;
//    ++size;
//    return Array[size];
//}

template <typename T>
T& vector<T>::pushback(T input){
    if (rsize<=size){
        if (Array != nullptr){
        T* ArrayCopy = Array;
        rsize = size+1;
        Array = new T[rsize];
        for (int i=0;i< size;++i)
            *(Array+i)=*(ArrayCopy+i);
        Array[size] = input;
        delete[] ArrayCopy;
        Array[size]=input;
        }
        else{
            rsize = size+1;
            Array = new T[rsize];
            Array[size] = input;
        }
    }
    ++size;
    return Array[size];
}

template <typename T>
T& vector<T>::append(int index,T input){
    if (rsize<=size)
        rsize=size+1;
    if (Array != nullptr){
        T *ArrayCopy = Array;
        Array = new T[rsize];
        for (int i=0;i< size+1;++i){
            if (i<index)
            Array[i]=ArrayCopy[i];
            else if(i>index)
            Array[i]=ArrayCopy[i-1];
        }
        delete[] ArrayCopy;
    }
    else{
        rsize = size+1;
        Array = new T[rsize];
        Array[size] = input;
    }
    ++size;
    return Array[index]=input;
}

template <typename T>
T& vector<T>::operator[](int index){
    return Array[index];
}

template <typename T>
T& vector<T>::operator[](int index) const{
    return Array[index];
}

template <typename T>
vector<T> vector<T>::operator=(const vector<T> &NewArray){
    size=NewArray.Size();
    rsize=size;
    delete[] Array;
    Array = new T[size];
    for (int i = 0; i<size;++i)
        *(Array+i) = NewArray[i];
    return *this;
}

template <typename T>
T vector<T>::pop(int index ){
    if (rsize==size)
        rsize=size-1;
    T *ArrayCopy = Array;
    Array = new T[rsize];
    for (int i=0;i< size-1;++i)
        if (i<index)
        Array[i]=ArrayCopy[i];
        else if(i>index)
        Array[i]=ArrayCopy[i+1];
    delete[] ArrayCopy;
    --size;
    --rsize;
    return Array[index];
}
template <typename T>
T vector<T>::pop(){
    return pop(size-1);
}

template <typename T>
vector<T> vector<T>::reserve(int size){
    if (size>this->size){
        T *ArrayCopy = Array;
        Array = new T[size];
        for (int i=0;i< size;++i)
            *(Array+i)=*(ArrayCopy+i);
        delete[] ArrayCopy;
        rsize=size;
        }
    return *this;

}