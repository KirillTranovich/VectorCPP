#pragma once
template<typename T>
class vector{
public:
    vector();
    vector(int size);

    int Size()const {
        return size;
    }

    T& pushback(T input);
    T& append(int index,T input);
    T pop();
    T pop(int index);
    vector<T> reserve(int size);    
    
    T& operator[](int index);
    T& operator[](int index) const;
    vector<T> operator=(const vector<T> & NewArray);
private:
    int rsize;
    int size;
    T *Array;
};