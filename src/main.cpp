#include  <iostream> 
#include "dynum.h"
#include "dyArray.h"
int main()
{
    std::printf("Start alloc"); 
     
    void* ptr = DY_ALLOC(10); 

    printf("New allocated pointer: %p\n", ptr); 
    printf("Free the new ptr: \n");
    DY_FREE(ptr); 
    printf("size of int: %d\n", sizeof(int)); 
    int a[3] = {1, 2, 3}; 
    printf("access a[4]: %d", a[2]);
     

}