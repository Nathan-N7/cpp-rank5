#include "Array.hpp"

template <typename T>
Array<T>::Array() : _data(NULL), _size(0) {

}

template <typename T>
Array<T>::Array(unsigned int n) : _size(n) {
    if (n == 0)
        _data = NULL;
    else
        _data = new T[n]();
}

template <typename T>
Array<T>::~Array() {
    delete[] _data;
}

template <typename T>
Array<T>::Array(const Array& other) : _data(NULL), _size(other._size) {
    if (_size > 0) {
        _data = new T[_size];
        for (unsigned int i = 0; i < _size; i++)
            _data[i] = other._data[i];
    }
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other) {
    if (this != &other) {
        delete[] _data;

        _size = other._size;

        if (_size > 0) {
            _data = new T[_size];
            for (unsigned int i = 0; i < _size; i++) {
                _data[i] = other._data[i];
            }
        } else {
            _data = NULL;
        }
    }
    return *this;
}

template <typename T>
T& Array<T>::operator[](unsigned int index) {
    if (index >= _size)
        throw std::exception();
    return _data[index];
}

template <typename T>
unsigned int Array<T>::size() const {
    return _size;
}