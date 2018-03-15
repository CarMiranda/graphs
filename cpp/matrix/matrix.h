/* 
 * File:   matrix.h
 * Author: carlos
 *
 * Created on March 3, 2018, 9:51 PM
 */

#ifndef MATRIX_H
#define MATRIX_H

#include <set>
#include "vector.h"

class matrix {
public:
    matrix();
    matrix(const int);
    matrix(const int, const double);
    matrix(const int, const int);
    matrix(const int, const int, const double);
    
    const int rank() const;
    const std::set<vector> kernel() const;
    const std::set<vector> eigenvalues() const;
    const std::set<vector> eigenvectors() const;
    
    const matrix& transpose(const bool);
    const matrix& invert(const bool);
    const matrix& add(const matrix&);
    const matrix& subtract(const matrix&);
    const matrix& multiply(const matrix&);
    const matrix& element_multiply(const double);
    const matrix& element_multiply(const matrix&);
    const matrix& element_divide(const matrix&);
    
    double operator[](const int) const;
    friend const matrix& operator+(const matrix&, const matrix&) const;
    friend const matrix& operator-(const matrix&, const matrix&) const;
    friend const matrix& operator*(const matrix&, const matrix&) const;
    friend const matrix& operator/(const matrix&, const matrix&) const;
    
private:
    std::vector<vector> m;
};

#endif /* MATRIX_H */
