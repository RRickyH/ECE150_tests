#include <iostream>
#include <cassert>
#include "project_2.cpp"

// test log(10) for n = 1
std::string test_case_0( ) {
    if ( log10( 1 ) == 0) {
        return "";
    } else {
        return "log10( 1 ) == " + std::to_string( log10(1)) + " | Expected: n = 0";
    }
}


// 	// test the pattern function
// std::cout << "Testing pattern" << std::endl << std::endl;
//
// 	std::cout << "Test Case 1: n = 0" << std::endl;
// 	pattern( 0 );
// 	std::cout << std::endl;
//
// 	std::cout << "Test Case 2: n = 1" << std::endl;
// 	pattern( 1 );
// 	std::cout << std::endl;
//
// 	std::cout << "Test Case 3: n = 4" << std::endl;
// 	pattern( 4 );
// 	std::cout << std::endl;
//
// 	std::cout << "-------------------------------------------" << std::endl;
//
// 	// test the log10 function
// 	std::cout << "Testing log10" << std::endl << std::endl;
//
// 	if ( log10( 10 ) == 1 ) {
// 		std::cout << "Passed Test Case 1" << std::endl;
// 	} else {
// 		std::cout << "Failed Test Case 1" << std::endl;
// 		std::cout << "\tlog10( 10 ) == " << log10( 10 ) << std::endl;
// 	}
//
// 	if ( log10( 100 ) == 2 ) {
//                 std::cout << "Passed Test Case 2" << std::endl;
//         } else {
//                 std::cout << "Failed Test Case 2" << std::endl;
//                 std::cout << "\tlog10( 100 ) == " << log10( 100 ) << std::endl;
//         }
//
// 	if ( log10( 4294967294 ) == 9 ) {
//                 std::cout << "Passed Test Case 3" << std::endl;
//         } else {
//                 std::cout << "Failed Test Case 3" << std::endl;
//                 std::cout << "\tlog10( 4294967294 ) == " << log10( 4294967294 ) << std::endl;
//         }
//
// 	std::cout << "-------------------------------------------" << std::endl;
//
// 	// test the count function
// 	std::cout << "Testing count" << std::endl << std::endl;
//
// 	if ( count( 0b00000000U, 1 ) == 0 ) {
//                 std::cout << "Passed Test Case 1" << std::endl;
//         } else {
//                 std::cout << "Failed Test Case 1" << std::endl;
//                 std::cout << "\tcount( 0b00000000U, 1 ) == " << count( 0b00000000U, 1 ) << std::endl;
//         }
//
//         if ( count( 0b11111111U, 1 ) == 8 ) {
//                 std::cout << "Passed Test Case 2" << std::endl;
//         } else {
//                 std::cout << "Failed Test Case 2" << std::endl;
//                 std::cout << "\tcount( 0b11111111U, 1 ) == " << count( 0b11111111U, 1 ) << std::endl;
//         }
//
//         if ( count( 0b10001000U, 0 ) == 30 ) {
//                 std::cout << "Passed Test Case 3" << std::endl;
//         } else {
//                 std::cout << "Failed Test Case 3" << std::endl;
//                 std::cout << "\tcount( 0b10001000U, 30 ) == " << count( 0b10001000U, 30 ) << std::endl;
//         }
//
// 	std::cout << "-------------------------------------------" << std::endl;
//
// 	// test the swap_bytes function
// 	std::cout << "Testing swap_bytes" << std::endl << std::endl;
//
// 	if ( swap_bytes( 0U, 0U, 0U ) == 0 ) {
// 		std::cout << "Passed Test Case 1" << std::endl;
// 	} else {
// 		std::cout << "Failed Test Case 1" << std::endl;
// 		std::cout << "\tswap_bytes( 0U, 0U, 0U ) == " << std::hex << swap_bytes( 0U, 0U, 0U) << std::endl;
// 	}
//
// 	if ( swap_bytes( 0xAABBCCDDU, 0U, 3U ) == 0xDDBBCCAAU ) {
//                 std::cout << "Passed Test Case 2" << std::endl;
//         } else {
//                 std::cout << "Failed Test Case 2" << std::endl;
//                 std::cout << "\tswap_bytes( 0xAABBCCDDU, 0U, 3U ) == " << std::hex << swap_bytes( 0xAABBCCDDU, 0U, 3U) << std::endl;
//         }
//
// 	if ( swap_bytes( 0xAABBCCDDU, 1U, 2U ) == 0xAACCBBDDU ) {
//                 std::cout << "Passed Test Case 3" << std::endl;
//         } else {
//                 std::cout << "Failed Test Case 3" << std::endl;
//                 std::cout << "\tswap_bytes( 0xAABBCCDDU, 1U, 2U ) == " << std::hex << swap_bytes( 0xAABBCCDDU, 1U, 2) << std::endl;
//         }
// 	std::cout << "-------------------------------------------" << std::endl;
// 	return 0;