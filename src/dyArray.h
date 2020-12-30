#ifndef DY_ARRAY_INCLUDE
#define DY_ARRAY_INCLUDE 1
#include <stdexcept> //no except
#include <utility>
#include <bits/stl_algobase.h>
#include <bits/range_access.h>
#include <array>

namespace DyNum
{
    //dynum array class, hold data in t
    template <typename _Tp, size_t _Nm>
    struct __array_traits
    {
        typedef _Tp _Type[_Nm];
        typedef std::__is_swappable<_Tp> _Is_swappable;
        typedef std::__is_nothrow_swappable<_Tp> __is_nothrow_swappable;

        static constexpr _Tp&
        _S_ref(const _Type& __t, std::size_t __n) noexcept
        {return const_cast<_Tp&>(__t[__n]);}

        static constexpr _Tp* 
        _S_ptr(const _Type& __t)noexcept
        {return const_cast<_Tp*> (__t);}
    };

    template <typename _Tp>
    struct __array_traits<_Tp, 0>
    {
        struct _Type
        {
        };
        typedef std::true_type _is_swappable;
        typedef std::true_type is_nothrow_swappable;

        static constexpr _Tp &_S_ref(const _Type &, std::size_t) noexcept
        {
            return *static_cast<_Tp *>(nullptr);
        }

        static constexpr _Tp *_S_ptr(const _Type &) noexcept
        {
            return nullptr;
        }
    };

    /**
     * @brief container for storing fixed array 
     * 
     * @tparam Tp Type of element
     * 
     * @tparam N Number of elemnts 
     * 
     **/
    template <typename _Tp, std::size_t _Nm>
    struct array
    {
        typedef _Tp value_type;
        typedef value_type *pointer;
        typedef const value_type *const_pointer;
        typedef value_type &reference;
        typedef const value_type *const_reference;
        typedef value_type *iterator;
        typedef const value_type *const_iterator;
        typedef std::size_t size_type;
        typedef std::ptrdiff_t difference_type;
        typedef std::reverse_iterator<iterator> reverse_iterator;
        typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

        //support for zero size array
        typedef __array_traits<_Tp, _Nm> _AT_Type;
        typename _AT_Type::_Type _M_elems;

        //No explicit constructor/copy/descructor for aggregate type 

        void fill(const value_type& __u)
        {
            
        }

        void 
        swap(array& __other)
        {}

        //Iterators 
        constexpr iterator 
        begin()noexcept
        {}

        constexpr const_iterator 
        begin()const noexcept
        {}

        constexpr iterator 
        end() noexcept
        {}

        constexpr const_iterator 
        end() const noexcept 
        {}

        constexpr reverse_iterator
        rbegin() noexcept 
        {} 

        constexpr const_reverse_iterator
        rbegin() const noexcept
        {}

        constexpr reverse_iterator
        rend() noexcept
        {}

        constexpr const_reverse_iterator
        rend()const noexcept
        {} 


        //Capcacity 
        constexpr size_type 
        size() const noexcept {return _Nm; }

        





      
    };
    


} // namespace DyNum

#endif