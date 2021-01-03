#ifndef DY_STL_ALGOBASE_INCLUDE
#define DY_STL_ALGOBASE_INCLUDE 1 

#include "dy_algobase.h"
namespace DyNum 
{

  /**
   *  @brief Swaps the contents of two iterators.
   *  @ingroup mutating_algorithms
   *  @param  __a  An iterator.
   *  @param  __b  Another iterator.
   *  @return   Nothing.
   *
   *  This function swaps the values pointed to by two iterators, not the
   *  iterators themselves.
  */
  template<typename _ForwardIterator1, typename _ForwardIterator2> 
  inline void 
  iter_swap(_ForwardIterator1 __a, _ForwardIterator2 __b)
  {
    swap(*__a, *__b); 
  }

  /**
   * @brief Swap the elements of two sequence 
   * @param __first1 A forward iterator 
   * @param __last1 A forward iterator 
   * @param _first2 A forward iterator 
   * @return A iterator equal to @p first2+(last1-first1).
   * 
   * Swaps each element in the range @p [first1.alst1) with the 
   * corresponding element in the range @p [first2, (last1-first1)). 
   * The ranges must no overlap. 
  */
  template<typename _ForwardIterator1, typename _ForwardInterator2> 
    _ForwardInterator2
    swap_ranges(_ForwardIterator1 __first1, _ForwardIterator1 __last1,
    _ForwardInterator2 __first2)
    {
      for(; __first1!=__last1; ++__first1, (void)++__first2)
        DyNum::iter_swap(__first1, __first2); 
      return __first2; 
    }
    
  
} // namespace DyNum 

















#endif //GAURD 