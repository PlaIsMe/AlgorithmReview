#include <iostream>

// [] => delcare function
// () => pass parameters
// By reference: [&]
// By value: [=]

// print data
int main() {
    // print data (void lamda)
    [] (const int value) { 
        std::cout<< value <<std::endl; 
    } (6);

    // Increase data by 10 (int lamda   )
    int increase = [] (int increase_value) -> int { 
        return increase_value + 10; 
    } (1);

    // Increase data by reference
    int input_value = 6;
    [&] {
        input_value += 2;
        std::cout<< input_value << std::endl;
    } ();

    // create new address, copy the input value and paste into new address
    [=]() mutable {
        input_value += 2;
        std::cout<< input_value << std::endl;
    } ();

    return 0;
}