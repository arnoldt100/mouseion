#ifndef  MOUSEION_Factory_INC
#define  MOUSEION_Factory_INC


//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//

namespace MPL
{

// =====================================================================================
//        Class:  Factory
//  Description:  
//  =====================================================================================
template <class AbstractProduct,
          typename IdentifierType,
          typename ProductCreator,      
          template<typename,class> class FactoryErrorPolicy>
class Factory
{
    public:
        // ====================  LIFECYCLE     =======================================

        //--------------------------------------------------------------------------------------
        //       Class:  Factory
        //      Method:  Factory :: Factory
        // Description:  
        // 
        //  Parameters: 
        //
        //      Return:
        //--------------------------------------------------------------------------------------
        Factory ()
        {
            return;
        }   // constructor

        Factory (const Factory & other)   // copy constructor
        {
            return;
        }		// -----  end of method Factory::Factory  -----

        Factory (Factory && other)   // copy-move constructor
        {
            return;
        }		// -----  end of method Factory::Factory  -----

        ~Factory ()  // destructor
        {
            return;
        }

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        Factory& operator= ( const Factory &other )
        {
            if (this != &other)
            {

            }
            return *this;
        } // assignment operator

        Factory& operator= ( Factory && other ) // assignment-move operator
        {
            if (this != &other)
            {

            }
            return *this;
        }

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class Factory  -----


}; // namespace MPL

#endif   // ----- #ifndef MOUSEION_Factory_INC  ----- 
