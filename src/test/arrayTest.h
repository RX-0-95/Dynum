#ifndef DYNUM_TEST_ARRAYTEST_INLCUDE
#define DYNUM_TEST_ARRAYTEST_INLCUDE


#include <iostream> 
#include <stdlib.h> 
#include "dyArray.h"

void testArray()
{
    printf("Test DyArray \n");
    std::printf("Start alloc");  
 
    printf("size of int: %d\n", sizeof(int)); 
    int a[3] = {1, 2, 3}; 
    printf("access a[4]: %d\n", a[2]);
    
    DyNum::array<int, 4> b = {1,5,5,5}; 
    const int const_a = 3; 
    printf("const varable a: %d\n", const_a); 
    printf("const cask const variable a\n"); 
    int& casked_const_a = const_cast<int&> (const_a); 
     
    printf("casked const_a: %d\n", casked_const_a);
    casked_const_a  = 4; 
    printf("const_a: %d\n", const_a); 
    const_cast<int&> (const_a) = 14;
    
    printf("change casked const_a: %d\n", casked_const_a);

    DyNum::array<int, 4> dyarr = {1 ,2 ,5,4}; 
    printf("size of array: %d\n", dyarr.size());
    dyarr[2] = 12; 
    printf("%d\n", dyarr[2]); 


    printf("Access iterator: \n"); 
    DyNum::array<int, 4> test_arr = {1,2,3,4}; 
    printf("Test Array pointer: %p\n", test_arr); 
    printf("Begin iterator: %p\n",test_arr.begin()); 
    printf("End of iterator: %p\n", test_arr.end());

    const auto it_begin = test_arr.begin(); 
    printf("Const iterator %p\n", it_begin);

    const auto it_end = test_arr.end();
    printf("Const iterator %p\n", it_end);

    printf("Reverse begin iterator %p\n", test_arr.rbegin()); 
    printf("Reverse end iterator %p\n", test_arr.rend());

    printf("Test at out of range: \n");\
    try{
        test_arr.at(4); 
    }
    catch(std::out_of_range& oor){
        std::cerr<<"Out of Range error: "<<oor.what() <<'\n'; 
    }

    printf("Test at: %d\n", test_arr.at(2)); 
    
    printf("Test const at outof range: \n");
    
    DyNum::array<int, 4> const const_test_arr = {5,6,7,8}; 
   
    
    try{
        const int const_at = const_test_arr.at(4); 
    }
    catch(std::out_of_range& oor){
        std::cerr<<"Const out of Range error: "<<oor.what()<<"\n";
    }

 
    
    printf("End of test");
}


#endif 