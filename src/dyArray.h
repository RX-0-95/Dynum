#ifndef     DY_ARRAY_INCLUDE
#define     DY_ARRAY_INCLUDE 1 
#include <stdexcept> //no except  
#include <utility> 
#include <bits/stl_algobase.h> 
#include <bits/range_access.h>
#include <array> 


namespace DyNum 
{
    //dynum array class, hold data in t
    template<typename _Tp, size_t _Nm> 
    struct __array_traits 
    {
        typedef _Tp _Type[_Nm]; 
        typedef std::__is_swappable<_Tp> _Is_swappable;
        typedef std::__is_nothrow_swappable<_Tp> __is_nothrow_swappable; 
    };
    
    template <typename _Tp> 
    struct  __array_traits<_Tp, 0> 
    {
        struct  _Type{};
        typedef std::true_type _is_swappable ;
        typedef std::true_type is_nothrow_swappable;

        static constexpr _Tp& _S_ref(const _Type&, std::size_t) noexcept 
        { return *static_cast<_Tp*>(nullptr);  }
        
        static constexpr _Tp* _S_ptr(const _Type&) noexcept
        {return nullptr; }
        
    };
    

} // namespace dynum




#endif 