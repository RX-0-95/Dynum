#ifndef DY_ALGOBASE_INCLUDE
#define DY_ALGOBASE_INCLUDE
#include <type_traits>


using namespace std;  
namespace  DyNum 
{
    /**
   *  @brief Swaps two values.
   *  @param  __a  A thing of arbitrary type.
   *  @param  __b  Another thing of arbitrary type.
   *  @return   Nothing.
  */
    #if __cplusplus > 201402L 
    #define _DYNUM_MOVE(__val)  std::move(__val)
    #define _DYNUM_FORWARD(__val) std::forward(__val)
    #else
    #define _DYNUM_MOVE(__val) (__val) 
    #define _DYBYN_FORWARD(__val) (__val)
    #endif// __cplusplus > 201402L 

    template <typename _Tp> 
    inline void 
    swap(_Tp&__a, _Tp&__b)
    {
        _Tp __tmp = _DYNUM_MOVE(__a); 
        __a = _DYNUM_MOVE(__b); 
        __b = _DYNUM_MOVE(__tmp); 
    }

    

    
} // namespace  DyNum 







#endif //DY_ALGOBASE_INCLUDE