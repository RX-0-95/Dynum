#ifndef DY_ALGORITHM_TEST_INCLUDE  
#define DY_ALGORITHM_TEST_INCLUDE  1
#include<iostream> 
#include "dy_algobase.h"
#include "dy_sort.h"
#include "dy_stl_algobase.h"
#include "dyArray.h"
#include <algorithm> 
void dy_algorithm_test()
{
    printf("Start Test Algorithms\n"); 
    {
        printf("swap test start:\n");
        float s_a = 4.5; 
        float s_b = 5.9; 
        DyNum::swap(s_a, s_b); 
        DY_ASSERT(s_a==(float)5.9&&s_b==(float)4.5);
        printf("passe swap test\n");
    }
    
    

}



#endif //guard 