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

template<int N_initial, int N_final, int N, typename TypeList, template<int I> class Wrapper>
class ForLoopOverTypeListNext
{
    public:

        void operator()()
        {
            if constexpr ( (N_initial <= N) && (N <= N_final )  )
            {
                // Instantiate an instance of the Wrapper for the N'th iteration
                // and do functor call.
                Wrapper<N> member;
                member();
               
                // Compute the increment.
                constexpr auto dN = ( N_initial <= N_final ) ? 1 : -1;

                // Call ForLoopOverTypeList for next ieration.
                ForLoopOverTypeListNext<N_initial,N_final,N+dN,TypeList,Wrapper> a_forloop;
                a_forloop();
            }
            return;
        }
}; // -----  end of class ForLoopOverTypeListNext  -----

template<int N_initial, int N_final, typename TypeList, template<int I> class Wrapper>
class ForLoopOverTypeList
{
    public:

        void operator()()
        {
            // Compute the index for the wrapper functor call.
            constexpr auto N = ( N_initial <= N_final ) ? N_initial : N_final;

            if constexpr ( (N_initial <= N) && (N <= N_final )  )
            {
                // Compute the increment.
                constexpr auto dN = ( N_initial <= N_final ) ? 1 : -1;

                // Instantiate an instance of the Wrapper for the N'th iteration
                // and do functor call.
                Wrapper<N> member;
                member();

                // Call ForLoopOverTypeListNext for next ieration.
                ForLoopOverTypeListNext<N_initial,N_final,N+dN,TypeList,Wrapper> a_forloop;
                a_forloop();
            }
            return;
        }

}; // -----  end of class ForLoopOverTypeList  -----



}; // namespace MPL

#endif   /* ----- #ifndef MPL_ForLoop_INC  ----- */
