#include  <iostream> 
#include "dynum.h"
#include "dyArray.h"
#include <array> 
int main()
{
    std::printf("Start alloc"); 
     
    void* ptr = DY_ALLOC(10); 

    printf("New allocated pointer: %p\n", ptr); 
    printf("Free the new ptr: \n");
    DY_FREE(ptr); 
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

}