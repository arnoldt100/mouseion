#ifndef  MOUSEION_Factory_INC
#define  MOUSEION_Factory_INC


//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <map>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "DefaultFactoryError.hpp"

namespace MPL
{

// =====================================================================================
//        Class:  Factory
//  Description:  
//  =====================================================================================
template <class AbstractProduct,
          typename IdentifierType,
          typename ProductCreator,      
          template<typename,class> class FactoryErrorPolicy = DefaultFactoryError>
class Factory : public FactoryErrorPolicy<IdentifierType, AbstractProduct>
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
        bool registerFactory(const IdentifierType & id, ProductCreator creator)
        {
            auto const element_registered = associations_.insert(AssocMap::value_type(id,creator)).second;
            return element_registered;
        }

        bool unregisterFactory(const IdentifierType & id)
        {
            auto element_removed = false;
            auto const nm_elements_removed = associations_.erase(id);
            if (nm_elements_removed == 1)
            {
                element_removed = true;
            }
            return element_removed;
        }


        AbstractProduct* createObject (IdentifierType const & id)
        {
            typename AssocMap::const_iterator it = associations_.find(id);
            if ( it != associations_.end())
            {
                return it.second();
            }
            return OnUnknownType(id);
        }		// -----  end of method Factory<T>::createObject  ----- 


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
        using AssocMap = std::map<IdentifierType,ProductCreator>;
        AssocMap associations_;

        // ====================  DATA MEMBERS  =======================================


}; // -----  end of class Factory  -----


}; // namespace MPL

#endif   // ----- #ifndef MOUSEION_Factory_INC  ----- 
