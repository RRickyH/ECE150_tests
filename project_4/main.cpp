#include "p_4_header.hpp"

#include <iostream>
#include <fstream>
#include <cassert>

void test_compare( char str1[], char str2[], char expected ){
	int result{ compare(str1, str2) };
	bool has_passed{ true };

	has_passed = (expected == '+' && !(result > 0)) ? false : has_passed;
	has_passed = (expected == '0' && !(result == 0)) ? false : has_passed;
	has_passed = (expected == '-' && !(result < 0)) ? false : has_passed;
	
	if (has_passed){
		std::cout << "compare test passed" << std::endl;	
	} else {
		std::cout << "COMPARE TEST FAILED" << std::endl;
		std::cout << str1 << " " << str2 << " " << result;
	}
	return;
}

void test_distance( char str1[], char str2[], unsigned int expected ){
	unsigned int result{ distance(str1, str2) };
        bool has_passed{ true };

        has_passed = result != expected ? false : has_passed;
        
        if (has_passed){
                std::cout << "distance test passed" << std::endl;
        } else {
                std::cout << "DISTANCE TEST FAILED" << std::endl;
                std::cout << str1 << " " << str2 << " " << result;
        }
	return;
}

void test_is_sorted( char* word_array[], std::size_t capacity, int expected ){
	unsigned int result{ is_sorted(word_array, capacity) };
        bool has_passed{ true };

        has_passed = result != expected ? false : has_passed;

        if (has_passed){
                std::cout << "is_sorted test passed" << std::endl;
        } else {
                std::cout << "IS_SORTED TEST FAILED" << std::endl;
             	for ( std::size_t i{}; i < capacity; i++ ){
			std::cout << "\t" << word_array[i] << std::endl;
		}
		std::cout << "\t" << result << " Expected: " << expected << std::endl;
        }
	return;
}

void test_insert( char* word_array[], std::size_t capacity, char* expected[]){                bool has_passed{ true };
	
	for ( std::size_t i{}; i < capacity; i++ ){
		if ( compare(word_array[i], expected[i]) != 0 ){
			has_passed = false;
			break;
		}
	}

	if (has_passed){                                                                              std::cout << "insert test passed" << std::endl;
	} else {                                                                                      std::cout << "INSERT TEST FAILED" << std::endl;
		for ( std::size_t i{}; i < capacity; i++ ){
			std::cout << "\t" << word_array[i] << "\t" << expected[i] << std::endl;}
	}
        return;
}

char** allocate_word_array( std::size_t capacity ){
	char** array;
	
	array = new char*[capacity]{};
	array[0] = new char[capacity*21]{};

	for ( std::size_t i{1}; i < capacity; i++){
		array[i] = array[i - 1] + 21;
	}

	return array;
}

/// @brief This main is used for testing. Feel free to modify the contents.
/// @remark This file is replaced with a testing main when you submit your project.
int main() {
    std::size_t const WIDTH{ 20 }; // set the maximum number of letters in a word
     
    char **test_words{};            // empty word array
    std::size_t num_test_words{};   // number of words (will be modified when a file is read)

    // populate the word array, and update the number of words
    read_words_from_file("test_words.txt", test_words, num_test_words, WIDTH );

      //////////////////////
     // Function Testing //
    //////////////////////
    char test_string[21] {"cat"};

    // length
    std::cout << "The length of " << test_string << " is " << length(test_string) << std::endl;
    
    // comapare
    test_compare("", "test", '-');
    test_compare("test", "", '+');
    test_compare("", "", '0');
    test_compare("cat", "category", '-');
    test_compare("category", "cat", '+');
    test_compare("cheese", "cheese", '0');
    test_compare("banana", "jam", '-');

	// assign

    // distance
    test_distance("", "strung", 6);
    test_distance("dare", "", 4);
    test_distance("try", "cry", 1);
    test_distance("cry", "try", 1);
    test_distance("chime", "crime", 1);
    test_distance("test", "tease", 2);
    test_distance("care", "car", 1);
   
    // is sorted
    test_is_sorted(test_words, num_test_words, 9);
    assign(test_words[9], "xenial");
    test_is_sorted(test_words, num_test_words, 10);
    assign(test_words[3], "hamburger");
    test_is_sorted(test_words, num_test_words, 4);
    assign(test_words[1], "");
    test_is_sorted(test_words, num_test_words, 1);
    

    // insert tests
	std::size_t capacity{5};
	char** test_array{allocate_word_array(capacity)};
	char** a_expected{allocate_word_array(capacity)};

	assign(test_array[0], ""); 		assign(a_expected[0], "");
	assign(test_array[1], "apple"); 	assign(a_expected[1], "apple");
	assign(test_array[2], "bob"); 		assign(a_expected[2], "bob");
	assign(test_array[3], "dida"); 		assign(a_expected[3], "cheese");
	assign(test_array[4], "cheese"); 	assign(a_expected[4], "dida");

	test_insert(test_array, capacity, a_expected);

	free_word_array(test_array);
	free_word_array(a_expected);

    // deallocate
    free_word_array(test_words);

    return 0;
}


/// @brief Reads words from a text file, allocates and populates a word array, and modifies the number of words
/// @remark You will need to understand how memory is allocated in order to delete memory in free_word_array
/// @param filename the name of the file to be opened
/// @param word_array given a word array pointer, allocates the word array
/// @param num_words updates (pass by reference) the number of words found in the file
/// @param width the maximum number of letters in a word
void read_words_from_file( 
    char const *filename, 
    char **&word_array,
    std::size_t &num_words, 
    std::size_t  width
) {

    // Attempt to open the file
    std::ifstream file{ filename };
    if (!file.is_open()) {
        std::cout << "[ERROR] " << filename << " not found or could not open file" << std::endl;
    }
    assert( file.is_open() );

    // Read the number of words from the first line of the file
    file >> num_words;

    // Ignore the newline '\n' character after the number
    file.ignore();

    /// Allocate memory and initialize the word array
    word_array = new char*[num_words]{};                // pointers to individual words
    word_array[0] = new char[num_words*(width + 1)]{};  // contiguous list of all words

    for ( std::size_t k{ 1 }; k < num_words; ++k ) {    // connect the individual word pointers
        word_array[k] = word_array[k - 1] + width + 1;
    }


    // Read from the file into the word array
    for ( std::size_t k{ 0 }; k < num_words; ++k ) {
        file >> word_array[k];
    }

    file.close();
}
