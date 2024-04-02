#include "VectorN.h"
#include <iostream>
#include <sstream>

// Конструктори
VectorN::VectorN() : N(0), a(nullptr) {}
VectorN::VectorN(int size, double* values) : N(size), a(new double[size]) {
    for (int i = 0; i < N; ++i) {
        a[i] = values[i];
    }
}
VectorN::VectorN(const VectorN& other) : N(other.N), a(new double[other.N]) {
    for (int i = 0; i < N; ++i) {
        a[i] = other.a[i];
    }
}
VectorN::~VectorN() {
    delete[] a;
}



// SET GET
void VectorN::SetA(double* values) {
    delete[] a;
    a = new double[N];
    for (int i = 0; i < N; ++i) {
        a[i] = values[i];
    }
}
void VectorN::SetN(int value) {
    N = value;
}

int VectorN::GetN() const { return N; }
double* VectorN::GetA() const { return a; }

// operator =
VectorN& VectorN::operator=(const VectorN& other) {
    if (this == &other)
        return *this;

    int N = other.N;
    double* otherA = other.a;
    double* newA = new double[N];

    for (int i = 0; i < N; ++i) {
        newA[i] = otherA[i];
    }
    delete[] a;
    a = newA;
    N = other.N;

    return *this;
}

// operator +
VectorN VectorN::operator+(const VectorN& other) const {
    if (N != other.N)
        throw std::invalid_argument("Vectors must have the same dimensions for addition");
    double* resultValues = new double[N];
    for (int i = 0; i < N; ++i)
        resultValues[i] = a[i] + other.a[i];
    VectorN result(N, resultValues);
    delete[] resultValues;
    return result;
}

// operator -
VectorN VectorN::operator-(const VectorN& other) const {
    if (N != other.N)
        throw std::invalid_argument("Vectors must have the same dimensions for subtraction");
    double* resultValues = new double[N];
    for (int i = 0; i < N; ++i)
        resultValues[i] = a[i] - other.a[i];
    VectorN result(N, resultValues);
    delete[] resultValues;
    return result;
}

// operator *
VectorN VectorN::operator*(const VectorN& other) const {
    if (N != other.N)
        throw std::invalid_argument("Vectors must have the same dimensions for dot product");

    double result = 0;
    for (int i = 0; i < N; ++i)
        result += a[i] * other.a[i];

    double* resultValues = new double[1];
    resultValues[0] = result;
    VectorN resultVector(1, resultValues);
    delete[] resultValues;

    return resultVector;
}

// operator ++
VectorN& VectorN::operator++() {
    for (int i = 0; i < N; ++i)
        ++a[i];
    return *this;
}

// operator ++int
VectorN VectorN::operator++(int) {
    VectorN temp(*this);
    operator++();
    return temp;
}

// operator --
VectorN& VectorN::operator--() {
    for (int i = 0; i < N; ++i)
        --a[i];
    return *this;
}

// operator --int
VectorN VectorN::operator--(int) {
    VectorN temp(*this);
    operator--();
    return temp;
}

// String
VectorN::operator string() const {
    stringstream oss;
    oss << " N = " << N << endl;
    oss << " a = ";
    for (int i = 0; i < N; ++i) {
        oss << a[i];
        if (i != N - 1)
            oss << ", ";
    }
    oss << endl;
    return oss.str();
}

std::ostream& operator<<(std::ostream& out, const VectorN& vector) {
    out << " N = " << vector.N << std::endl;
    out << " a = ";
    for (int i = 0; i < vector.N; ++i) {
        out << vector.a[i];
        if (i != vector.N - 1)
            out << ", ";
    }
    out << std::endl;
    return out;
}

std::istream& operator>>(std::istream& in, VectorN& vector) {
    int size;
    in >> size;
    double* values = new double[size];
    for (int i = 0; i < size; ++i) {
        in >> values[i];
    }
    vector.SetN(size);
    vector.SetA(values);
    delete[] values;
    return in;
}
