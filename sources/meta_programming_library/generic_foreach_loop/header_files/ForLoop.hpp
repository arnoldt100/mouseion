#ifndef  MPL_ForLoop_INC
#define  MPL_ForLoop_INC

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
template< int N_initial, int N_final, int N, int delta_N, template<int I> class Wrapper>
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

        void operator()()
        {
            if constexpr ( (N_initial <= N) && (N <= N_final )  )
            {
                // Instantiate an instance of the Wrapper for the N'th iteration
                // and do operation.
                Wrapper<N> member;
                member();
                
                // Call ForLoop for next ieration.
                ForLoop<N_initial,N_final,N+delta_N,delta_N,Wrapper> a_forloop;
                a_forloop();
            }
        }


    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class ForLoop  -----


// =====================================================================================
//        Class:  ForLoop
//  Description:  
// =====================================================================================
template<int N_initial, int N_final, int N, typename TypeList, template<int I> class Wrapper>
class ForLoopOverTypeList
{
    public:
        // ====================  LIFECYCLE     =======================================

        ForLoopOverTypeList () // constructor
        {
            return;
        }

        ForLoopOverTypeList (const ForLoopOverTypeList & other) // copy constructor
        {
            if ( this != &other)
            {
            }
            return;
        }

        ForLoopOverTypeList (ForLoopOverTypeList && other)   // copy-move constructor
        {
            if ( this != &other)
            {
            }
            return;
        }

        ~ForLoopOverTypeList ()  // destructor
        {
            return;
        }

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        ForLoopOverTypeList& operator= ( const ForLoopOverTypeList &other ) // assignment operator
        {
            if ( this != &other)
            {
            }
            return *this;
        }

        ForLoopOverTypeList& operator= ( ForLoopOverTypeList && other ) // assignment-move operator
        {
            if ( this != &other)
            {
            }
            return *this;
        }

        void operator()()
        {
            if constexpr ( (N_initial <= N) && (N <= N_final )  )
            {
                // Instantiate an instance of the Wrapper for the N'th iteration
                // and do operation.
                Wrapper<N> member;
                member();
                
                // Call ForLoopOverTypeList for next ieration.
                ForLoopOverTypeList<N_initial,N_final,N+1,TypeList,Wrapper> a_forloop;
                a_forloop();
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

#endif   /* ----- #ifndef MPL_ForLoop_INC  ----- */
