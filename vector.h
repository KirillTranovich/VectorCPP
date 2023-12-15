#pragma once
#include <iostream>

template<typename T>
class vector{
public:
    vector();
    vector(unsigned size);

    unsigned Size()const {
        return size;
    }

    T& pushback(T input);
    T& append(unsigned index,T input);
    T pop();
    T pop(unsigned index);
    vector<T> reserve(unsigned size);    
    
    T& operator[](unsigned index);
    T& operator[](unsigned index) const;
    vector<T> operator=(const vector<T> & NewArray);
private:
    unsigned rsize;
    unsigned size;
    T *Array;
};

template <typename T>
vector<T>::vector(){
    size = 0;
    rsize = size;
    Array = new T[0];
}

template <typename T>
vector<T>::vector(unsigned size){
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
    if (rsize=size){
        if (Array != nullptr){
        T* ArrayCopy = Array;
        rsize = size+1;
        Array = new T[rsize];
        for (int i=0;i< size;++i)
            *(Array+i)=*(ArrayCopy+i);
        Array[size] = input;
        delete[] ArrayCopy;
        }
        else{
            rsize = 1;
            Array = new T[rsize];
        }
    }
    else if (rsize<size)
        throw std::runtime_error("How did size became bigger than space?!\n");
    
    Array[size] = input;
    ++size;
    return Array[size];
}

template <typename T>
T& vector<T>::append(unsigned index,T input){
    if (rsize=size)
        rsize=size+1;
    else if (rsize<size)
        throw std::runtime_error("How did size became bigger than space?!\n");

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
        rsize = 1;
        Array = new T[rsize];
    }
    ++size;
    return Array[index]=input;
}

template <typename T>
T& vector<T>::operator[](unsigned index){
    return Array[index];
}

template <typename T>
T& vector<T>::operator[](unsigned index) const{
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
T vector<T>::pop(unsigned index ){
    if (rsize==size)
        rsize=size-1;
    else if (rsize<size)
        throw std::runtime_error("How did size became bigger than space?!\n");
    T *ArrayCopy = Array;
    Array = new T[rsize];
    for (int i=0;i< size-1;++i)
        if (i<index)
        Array[i]=ArrayCopy[i];
        else if(i>index)
        Array[i]=ArrayCopy[i+1];
    delete[] ArrayCopy;\
    if (rsize>=size)
        --rsize;
    --size;
    
    return Array[index];
}
template <typename T>
T vector<T>::pop(){
    return pop(size-1);
}

template <typename T>
vector<T> vector<T>::reserve(unsigned size){
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