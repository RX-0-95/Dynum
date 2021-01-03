#ifndef DY_ARRAY_INCLUDE
#define DY_ARRAY_INCLUDE 1
#include <stdexcept> //no except
#include <utility>
//#include <bits/stl_algobase.h>
//#include <bits/range_access.h>
#include "dynum.h"
#include "dy_stl_algobase.h"

namespace DyNum
{
   
    //dynum array class, hold data in t
    template <typename _Tp, size_t _Nm>
    struct __array_traits
    {
        typedef _Tp _Type[_Nm];
        typedef std::__is_swappable<_Tp> _Is_swappable;
        typedef std::__is_nothrow_swappable<_Tp> _Is_nothrow_swappable;
       
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
        typedef std::true_type _Is_swappable;
        typedef std::true_type _Is_nothrow_swappable;

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
        typedef value_type*     pointer;
        typedef const value_type*   const_pointer;
        typedef value_type&   reference;
        typedef const value_type&   const_reference;
        typedef value_type*   iterator;
        typedef const value_type *const_iterator;
        typedef std::size_t size_type;
        typedef std::ptrdiff_t difference_type;
        typedef std::reverse_iterator<iterator> reverse_iterator;
        typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

        //support for zero size array
        typedef DyNum::__array_traits<_Tp, _Nm> _AT_Type;
        typename _AT_Type::_Type _M_elems; 
  
        //No explicit constructor/copy/descructor for aggregate type 

        void fill(const value_type& __u)
        {std::fill_n(begin(), size(), __u); }

        void 
        swap(array& __other)
        noexcept(_AT_Type::_Is_nothrow_swappable::value)
        {DyNum::swap_ranges(begin(), end(), __other.begin());}

        //Iterators 
        constexpr iterator 
        begin()noexcept
        {return iterator(data());}
        
        constexpr const_iterator 
        begin()const noexcept
        {return const_iterator(data());}

        constexpr iterator 
        end() noexcept
        {return iterator(data() + _Nm); }

        constexpr const_iterator 
        end() const noexcept 
        {return const_iterator(data() + _Nm);}

        constexpr reverse_iterator
        rbegin() noexcept 
        {return reverse_iterator(end());} 

        constexpr const_reverse_iterator
        rbegin() const noexcept
        {return const_reverse_iterator(end());}

        constexpr reverse_iterator
        rend() noexcept
        {return reverse_iterator(begin());}

        constexpr const_reverse_iterator
        rend()const noexcept
        {return const_reverse_iterator(begin());} 

        constexpr const_iterator
        cbegin() const noexcept
        {return const_iterator(data());}

        constexpr const_iterator
        cend()const noexcept
        {return const_iterator(data() + _Nm);}

        constexpr const_reverse_iterator
        crbegin() const noexcept
        {return const_reverse_iterator(end());}

        constexpr const_reverse_iterator
        crend() const noexcept
        {return const_reverse_iterator(begin());}

        constexpr pointer
        data() noexcept
        {return _AT_Type::_S_ptr(_M_elems);}

        constexpr const_pointer 
        data() const noexcept 
        {return _AT_Type::_S_ptr(_M_elems);}

        //Capcacity 
        constexpr size_type 
        size() const noexcept 
        {return _Nm; }

        constexpr size_type
        max_size() const noexcept
        {return _Nm;}

        constexpr bool 
        empty() const noexcept
        {return size() == 0;}

        //Element acces 
        constexpr reference 
        operator[] (size_type __n) noexcept
        {return _AT_Type::_S_ref(_M_elems, __n); }

        constexpr const_reference
        operator[] (size_type __n)const noexcept 
        {return _AT_Type::_S_ref(_M_elems, __n); }

        constexpr reference
        at(size_type __n)
        {
            if(__n >= _Nm)
                std::__throw_out_of_range_fmt(__N("array::at:__n(which is %zu)" ">=_Nm (which is %zu)"),
                __n, _Nm);
            return _AT_Type::_S_ref(_M_elems, __n); 
        }

        constexpr const_reference
        at(size_t __n) const
        {
            return __n<_Nm ? _AT_Type::_S_ref(_M_elems, __n)
                : (std::__throw_out_of_range_fmt(__N("array const ::at:__n(which is %zu)" ">=_Nm (which is %zu)"),
                __n, _Nm),
            _AT_Type::_S_ref(_M_elems, 0));
        }

        constexpr reference
        front() noexcept
        {return *begin();}

        constexpr const_reference
        front() const noexcept
        {return *begin();}

        constexpr reference
        back() noexcept 
        {return _Nm? *(end()-1):*end();} 

        constexpr const_reference
        back() const noexcept
        { return _Nm? *(end()-1):*end();} 

      
    };
    
    //Array comparisons 
    template<typename _Tp, std::size_t  _Nm> 
    inline bool
    operator==(const array<_Tp,_Nm>&__one, const array<_Tp,_Nm>& __two)
    {return std::equal(__one.begin(), __one.end(), __two.begin());}

    template<typename _Tp, std::size_t _Nm> 
    inline bool 
    operator!=(const array<_Tp, _Nm>&__one, const array<_Tp, _Nm>&__two)
    {return !(__one==__two); }

    template <typename _Tp, std::size_t _Nm> 
    inline bool 
    operator<(const array<_Tp, _Nm>& __a, const array<_Tp, _Nm>& __b)
    {
        return std::lexicographical_compare(__a.begin(), __a.end(), 
        __b.begin(), __b.end()); 
    }

    template <typename _Tp, std::size_t _Nm> 
    inline bool 
    operator>(const array<_Tp, _Nm> __a, const array<_Tp, _Nm> __b)
    {return __b <__a; }

    template<typename _Tp, std::size_t _Nm> 
    inline bool 
    operator<= (const array<_Tp, _Nm> __a, const array<_Tp, _Nm> __b)
    {return !(__a > __b);}


    template<typename _Tp, std::size_t _Nm> 
    inline bool 
    operator>= (const array<_Tp, _Nm> __a, const array<_Tp, _Nm> __b)
    {return !(__a < __b);}

    //Specialiuzed algorithms 
    template<typename _Tp, std::size_t _Nm> 
    inline 
    
    #if __cplusplus > 201402L
        typename enable_if<
        DyNum::__array_traits<_Tp, _Nm>::_Is_swappable::value>::type
    #else
        void 
    #endif
        swap(array<_Tp, _Nm>& __one, array<_Tp, _Nm> &__two)
        noexcept
        {__one.swap(__two);}










} // namespace DyNum

#endif//DY_ARRAY_INCLUDE