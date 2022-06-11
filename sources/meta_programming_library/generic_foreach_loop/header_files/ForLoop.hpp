#ifndef __filepreprocessordefine__
#define __filepreprocessordefine__

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <memory>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//

namespace MPL
{

// =====================================================================================
//        Class:  ForLoop
//  Description:  
// =====================================================================================
template< int N_start, int N_final, int N, int delta_N, template<int I> class Wrapper, typename ...Args>
class ForLoop
{
    public:
        // ====================  LIFECYCLE     =======================================

        ForLoop () // constructor
        {
            return;
        }

        ForLoop (const ForLoop & other) // copy constructor
        {
            if ( this != &other)
            {
            }
            return;
        }

        ForLoop (ForLoop && other)   // copy-move constructor
        {
            if ( this != &other)
            {
            }
            return;
        }

        ~ForLoop ()  // destructor
        {
            return;
        }

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        ForLoop& operator= ( const ForLoop &other ) // assignment operator
        {
            if ( this != &other)
            {
            }
            return *this;
        }

        ForLoop& operator= ( ForLoop && other ) // assignment-move operator
        {
            if ( this != &other)
            {
            }
            return *this;
        }

        void operator()(Args&... args)
        {
            if constexpr ( N_final != N  )
            {
                // Instantiate an instance of the Wrapper for the N'th iteration
                // and do operation.
                Wrapper<N> member;
                member(args...);
                
                // Call ForLoop for next ieration.
                ForLoop<N_start,N_final,N+delta_N,delta_N,Wrapper,Args ...> a_forloop;
                a_forloop(args...);
            }
        }


    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class ForLoop  -----

}; // namespace MPL

#endif // __filepreprocessordefine__
