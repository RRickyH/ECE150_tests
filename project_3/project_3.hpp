#ifndef PROJECT_3_HPP
#define PROJECT_3_HPP

#include <iostream>

// function declarations for functions expected in project_3.cpp
double power( double base, int power );

double *geometric( double a, double ratio, std::size_t cap );

double *cross_correlation(
                double array0[], std::size_t cap0, double array1[], std::size_t cap1
                );

std::size_t shift_duplicates( int array[], std::size_t capacity );

void deallocate( double *&ptr, bool is_array, std::size_t capacity );

#endif
