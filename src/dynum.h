#pragma once 

#ifndef DYNUM_INCLUDE
#define DYNUM_INCLUDE 

#include <float.h> 
#include<string.h> 
#include<stddef.h> 

#define DYNUM_VERSION "0.0.1"


//Define attributes of all API symbols decleartion (for DLL under windows )
#ifndef DYNUM_API 
#define DYNUM_API
#endif 

//Helper Marcos
#ifndef DY_ASSERT
#include<assert.h>  
#define DY_ASSERT(_EXPR)    assert(_EXPR) 
#endif 



namespace DyNum
{
    //Memory allocators 
    DYNUM_API void* MemAlloc(size_t size); 
    DYNUM_API void MemFree(void* ptr);
}//end of DyNum namespace 



//---------------------------------------------------------------------------
//Helpers: Memory allocations marcos 
//DY_ALLOC(), DY_FREE(), DY_NEW(), DY_PLACEMENT_NEW, DY_DELETE() 
#define DY_ALLOC(_SIZE) DyNum::MemAlloc(_SIZE)
#define DY_FREE(_PTR)   DyNum::MemFree(_PTR) 

//---------------------------------------------------------------------------










#endif //define DYNUM INCLUDE 