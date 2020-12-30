//---------------------------------------------------------------------------
//[SECTION] INCLUDES 
//---------------------------------------------------------------------------
#include "dynum.h"

//sysetm includes 
#include <ctype.h> 
#include <stdio.h>  //sscanf, printf 
#include <stdlib.h> //malloc 
#include <stddef.h> //size_t 
//---------------------------------------------------------------------------
//[SECTION] CONTEXT AND MEMORY ALLOCATORS 
//---------------------------------------------------------------------------

#ifndef DY_DISABLE_DEFAULT_ALLOCATORS
static void* MallocWrapper(size_t size, void* user_data) {return malloc(size);}
static void  FreeWrapper (void* ptr, void*user_data) {free(ptr);} 
#else

#endif //DY_DISABLE_DEFAULT_ALLOCATORS

static void* (*DYAllocatorAllocFunc)(size_t size, void* user_data) = MallocWrapper;
static void  (*DYAllocatorFreeFunc)(void* ptr, void* user_data) = FreeWrapper; 
static void* DYAllocatorUserData = NULL; 

//DY_ALLOC() =  dynum::MemAlloc() 
void* DyNum::MemAlloc(size_t size)
{
    return DYAllocatorAllocFunc(size, DYAllocatorUserData); 
}
//DY_FREE() = DyNum::MemFree()
void DyNum::MemFree(void* ptr)
{
    DYAllocatorFreeFunc(ptr, DYAllocatorUserData);
}
