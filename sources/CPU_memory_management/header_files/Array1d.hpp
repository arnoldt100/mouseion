//! \file Array1d.hpp

#ifndef  Array1d_INC
#define  Array1d_INC

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <new>
#include <iostream>
#include <vector>
#include <memory>
#include <string>

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "MemoryExceptionDeletingNullPointer.hpp"
#include "AllocatingArrayDimensionToNonPositiveSize.hpp"

namespace MEMORY_MANAGEMENT
{

/*
 * =====================================================================================
 *        Class:  Array1d
 *  Description: The primary class specialization of the Array1d template. This
 *  class is noncopyable. 
 * =====================================================================================
 */
template < typename T >
class Array1d
{
    public:
        /* ====================  LIFECYCLE     ======================================= */
        Array1d(); /* constructor */

        Array1d( Array1d const & other)=delete;

        ~Array1d();

        /* ====================  ACCESSORS     ======================================= */
        
        /*
         *--------------------------------------------------------------------------------------
         *       Class:  Array1d
         *      Method:  createArray
         * Description: Creates a pointer array of type T with "dim1" number of elements.
         *
         * Return: T*  
         *
         * Arguments: nm_elements; type std::size_t; The number of elements in the pointer array.
         *--------------------------------------------------------------------------------------
         */
        T* createArray ( std::size_t const nm_elements ) const ;


        /*
         *--------------------------------------------------------------------------------------
         *       Class:  Array1d<T>
         *      Method:  Array1d<T> :: createVectorOfUniquePointers
         * Description: Creates a vector of unique pointers of type T. 
         *
         * Return std::vector<std::unique_ptr<T> >
         *
         * Arguments: number_of_elements; type std::size_t; The length of the vector.
         *
         *--------------------------------------------------------------------------------------
         */
        std::vector<std::unique_ptr<T>>
        createVectorOfUniquePointers(std::size_t const  number_of_elements) const;

        /*
         *--------------------------------------------------------------------------------------
         *       Class:  Array1d
         *      Method:  destroyArray
         * Description:  Frees the memory associated with pointer "a_ptr".
         *
         * Return:  void 
         *
         * Arguments: a_ptr; type T*; a_ptr is a pointer array of type T.
         *--------------------------------------------------------------------------------------
         */
        void destroyArray( T * & a_ptr ) const
        {
            try 
            {
                if (a_ptr == nullptr)
                {
                    std::string error_message("Error in Array1d<T>::destroyArray.");
                    throw MEMORY_MANAGEMENT::MemoryExceptionDeletingNullPointer<T>(error_message);
                }
                delete [] a_ptr;
                a_ptr=nullptr;
            }
            catch ( MEMORY_MANAGEMENT::MemoryExceptionDeletingNullPointer<T> const & ExceptObj ) 
            {
                std::cout << ExceptObj.what() << std::endl;
            }
            return;
        } /* -----  end of method destroyArray  ----- */

        /*
         *--------------------------------------------------------------------------------------
         *       Class:  Array1d<T>
         *      Method:  Array1d :: createPointerArrayFromVector
         * Description:  Creates a 1d pointer array from a vector. The number of elements of T*
         *               is the length of the vector.
         *
         * Return: T* with the number of elements equal to the length of the vector. 
         *
         * Arguments: vec; type std::vector<T>; The vector which elements are copied to the
         *             pointer array
         *--------------------------------------------------------------------------------------
         */
        T* createPointerArrayFromVector(std::vector<T> const & vec) const
        {

            using vector_size_type = typename std::vector<T>::size_type;
            
            // Get the number of elements of the vector.
            vector_size_type len = vec.size();

            if (len <= 0)
            {
                std::string error_message("Error in function Array1d<T>::createPointerArrayFromVector");
                throw MEMORY_MANAGEMENT::AllocatingArrayDimensionToNonPositiveSize<T>(error_message);
            }

            // Allocate pointer and fill with elements from vector.
            const Array1d<T> array_factory_1d;
            T* a_ptr = array_factory_1d.createArray(len);

            for (vector_size_type ip=0; ip < len; ++ip)
            {
                a_ptr[ip] = vec[ip];
            }

            return a_ptr;
        }/* -----  end of method Array1d<T>::createPointerArrayFromVector  ----- */
 
        //! \brief Creates a 1d unique_ptr from an iterable object.
        //!
        //! \tparam Iterable_t The type of iterable object.
        //! \tparam pointer_t The type of object managed by the unique_ptr.
        //! \param iterator The iterable object which contains data to be copied to the
        //!                 1D unique_ptr.
        //! \returss A unique_ptr that manages a array of type pointer_t.
        template<typename Iterable_t,typename pointer_t >
        std::unique_ptr<pointer_t[]> create1DUniquePointerFromIterator(const Iterable_t & iterator) const
        {
                std::unique_ptr<pointer_t[]> value = std::make_unique<pointer_t[]>(iterator.size());
                std::size_t ip = 0;
                for ( const auto & nm : iterator )
                {
                    value[ip] = static_cast<pointer_t>(nm);  
                    ++ip;
                }
                return value;
        }

        //! Creates a 1d array by copying from 1d array src_array.
        //!
        //! \param[in] src_array The array to copy from.
        //! \param[in] len The length of src_array.
        //! \return A 1d array that is a copy of dst_array.
        T* copyArray(T const * const & src_array,
                     const std::size_t & len) const
        {
            T* dst_array = nullptr;
            if (len > 0)
            {
                dst_array = this->createArray(len);
                for (std::size_t ip = 0; ip < len; ++ip)
                {
                    dst_array[ip] = src_array[ip];
                }
            }
            return dst_array;
        }
        /* ====================  MUTATORS      ======================================= */

        /* ====================  OPERATORS     ======================================= */
        Array1d& operator=(Array1d const & other)=delete;

    protected:
        /* ====================  METHODS       ======================================= */

        /* ====================  DATA MEMBERS  ======================================= */

    private:
        /* ====================  METHODS       ======================================= */

        /* ====================  DATA MEMBERS  ======================================= */

}; /* ----------  end of template class Array1d  ---------- */



//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================
template<typename T>
Array1d<T>::Array1d() /* constructor */
{
    return;
}

template<typename T>
Array1d<T>::~Array1d()
{
    return;
}

//============================= ACCESSORS ====================================
template <typename T>
T*
Array1d<T>::createArray( std::size_t const nm_elements ) const
{
    T * aPointerArray_ptr= nullptr;
    try 
    {
        if (nm_elements <= 0)
        {
            std::string error_message("Error in function Array1d<T>::createArray");
            throw MEMORY_MANAGEMENT::AllocatingArrayDimensionToNonPositiveSize<T>(error_message);
        }

        aPointerArray_ptr = new T[nm_elements];
        if ( aPointerArray_ptr == nullptr )
        {
            throw std::bad_alloc();
        }
    }
    catch ( std::bad_alloc const & ExceptObj )
    {
        std::cout << "Pointer 1d array allocation failed: " << ExceptObj.what() << std::endl;
    }
    catch( MEMORY_MANAGEMENT::AllocatingArrayDimensionToNonPositiveSize<T> const & ExceptObj )
    {
        std::cout << ExceptObj.what() << std::endl;
        std::abort();
    }
    return aPointerArray_ptr;
}  /* -----  end of method createArray  ----- */


template <typename T>
std::vector<std::unique_ptr<T>>
Array1d<T>::createVectorOfUniquePointers(std::size_t const number_of_elements) const
{
    std::vector<std::unique_ptr<T>> a_vector;
    for (std::size_t ip=0; ip < number_of_elements; ++ip)
    {
        a_vector.push_back( std::unique_ptr<T>(new T) );
    }
    return a_vector;
} /* -----  end of method Array1d<T>::createVectorOfUniquePointers  ----- */


//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PROTECTED ////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PRIVATE //////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
    
//============================= LIFECYCLE ====================================

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================


};		/* -----  end of namespace MEMORY_MANAGEMENT  ----- */



#endif   /* ----- #ifndef Array1d_INC  ----- */
