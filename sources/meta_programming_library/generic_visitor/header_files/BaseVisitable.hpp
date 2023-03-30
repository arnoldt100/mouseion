#ifndef  MOUSEION_BaseVisitable_INC
#define  MOUSEION_BaseVisitable_INC

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "DefaultCatchAll.hpp"
#include "BaseVisitor.h"
#include "Visitor.hpp"

namespace MPL
{

// =====================================================================================
//        Class:  BaseVisitable
//  Description:  
//  =====================================================================================
template<typename R = void,
         template <typename, class> class CatchAll = DefaultCatchAll >
class BaseVisitable
{
    public:
        // ====================  USING ALIASES =======================================
        using ReturnType = R;

        // ====================  LIFECYCLE     =======================================

        //--------------------------------------------------------------------------------------
        //       Class:  BaseVisitable
        //      Method:  BaseVisitable :: BaseVisitable
        // Description:  
        // 
        //  Parameters: 
        //
        //      Return:
        //--------------------------------------------------------------------------------------
        BaseVisitable ()   // constructor
        {
            return;
        }

        BaseVisitable (const BaseVisitable & other) // copy constructor
        {
            if (this != &other)
            {

            }
            return;
        }

        BaseVisitable (BaseVisitable && other) // copy-move constructor
        {
            if (this != &other)
            {

            }
            return;
        }

        virtual ~BaseVisitable ()=0;  // destructor

        // ====================  ACCESSORS     =======================================
        virtual R Accept(BaseVisitor& ) = 0;

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        BaseVisitable& operator= ( const BaseVisitable &other ) // assignment operator
        {
            if (this != &other)
            {
        
            }
            return *this;
        }

        BaseVisitable& operator= ( BaseVisitable && other ) // assignment-move operator
        {
            if (this != &other)
            {
        
            }
            return *this;
        }

    protected:
        // ====================  METHODS       =======================================
        template<class T>
        static ReturnType AcceptImpl(T& visited, BaseVisitor& guest)
        {
            if ( Visitor<T,R>* p = dynamic_cast<Visitor<T,R>*>(&guest) )
            {
                return p->visit(visited);
            }
            return CatchAll<R,T>::OnUnknownVisitor(visited,guest);
        }

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class BaseVisitable  -----

template<typename R,
         template <typename, class> class CatchAll
         >
BaseVisitable<R,CatchAll>::~BaseVisitable ()  // destructor
{
    return;
}

}; // namespace MPL

#endif   // ----- #ifndef MOUSEION_BaseVisitable_INC  ----- 
