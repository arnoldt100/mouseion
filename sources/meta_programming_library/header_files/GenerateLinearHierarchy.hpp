#ifndef  MOUSEION_GenerateLinearHierarchy_INC
#define  MOUSEION_GenerateLinearHierarchy_INC

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "MPLAliases.hpp"
#include "EmptyType.h"

namespace MPL
{

// =====================================================================================
//        Class:  GenerateLinearHierarchy
//  Description:  The primary template
//  ====================================================================================
template<
         template<typename,typename> typename Unit,
         typename TypeListSize,
         typename L, 
         class Root = EmpytyType
        >
class GenerateLinearHierarchy : public Unit<
                                            mpl_front<L>,
                                            GenerateLinearHierarchy<Unit,mpl_rest_size<L>,mpl_rest<L>,Root>
                                           > 
{

}; // -----  end of class GenerateLinearHierarchy  -----



// =====================================================================================
//        Class:  GenerateLinearHierarchy
//  Description:  The end of recursion template.
//  ====================================================================================
template<
         template <typename,typename> class Unit,
         typename L,
         class Root>
class GenerateLinearHierarchy <
                                Unit,
                                mpl_size_1,
                                L,
                                Root
                              > :
    public Unit<mpl_front<L>,Root>
{

};
// -----  end of class GenerateLinearHierarchy  -----


}; // namespace MPL

#endif   // ----- #ifndef MOUSEION_GenerateLinearHierarchy_INC  ----- 
