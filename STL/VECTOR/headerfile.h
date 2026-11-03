#ifndef MY_VECTOR_H
#define MY_VECTOR_H

template <typename T>
class Vector {
private:
    T* arr;
    int sz;
    int cap;

    void grow() {
        int newCap = cap * 2;
        T* temp = new T[newCap];

        for (int i = 0; i < sz; i++) {
            temp[i] = arr[i];
        }

        delete[] arr;
        arr = temp;
        cap = newCap;
    }

public:
    Vector() {
        sz = 0;
        cap = 2;
        arr = new T[cap];
    }

    void push_back(T value) {
        if (sz == cap) {
            grow();
        }

        arr[sz] = value;
        sz++;
    }

    void pop_back() {
        if (sz > 0) {
            sz--;
        }
    }

    int size() const {
        return sz;
    }

    int capacity() const {
        return cap;
    }

    T& operator[](int index) {
        return arr[index];
    }

    Vector(const Vector&) = delete;
    Vector& operator=(const Vector&) = delete;

    ~Vector() {
        delete[] arr;
    }
};

#endif
