#include "project_3.hpp"

#include <iostream>
#include <cassert>
#include <stdlib.h>

int main();
void test_geometric();
void print_array( double array[], std::size_t cap );

int main(){
	test_geometric();
	return 0;
}

void test_geometric(){

	// test case 1: test simple, small values of a ratio and capacity
	double *test_array_1{ geometric( 1, 2, 4 ) };
	double a_expected_1[4]{ 1, 2, 4, 8 };
	bool passed{ true };

	for ( std::size_t i{0}; i < 4; i++ ){
		if ( a_expected_1[i] != test_array_1[i]){
			passed = false;
		}
	}
	if (!passed){
		std::cout << "TEST CASE 1 FAILED" << std::endl;
		system("Color 04");
		std::cout << "geometric( 1, 2, 4 ): ";
		print_array( test_array_1, 4 );
		std::cout << std::endl;

		std::cout << "expected: ";
		print_array( a_expected_1, 4 );
		std::cout << std::endl << std::endl;
	} else {
		std::cout << "TEST CASE 1 PASSED" << std::endl;
	}
}

void print_array( double array[], std::size_t cap ){
	assert( cap > 0 );
	std::cout << "[ ";

	for ( std::size_t i{0}; i < cap - 1; i++ ){
		std::cout << array[i] << ", ";
	}

	std::cout << array[cap - 1] << " ]" << std::endl;
}
