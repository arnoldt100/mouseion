#ifndef  MOUSEION_GenerateScatteredHierarchy_INC
#define  MOUSEION_GenerateScatteredHierarchy_INC

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

namespace MPL
{

    // =====================================================================================
    //        Class:  GenerateScatteredHierarchy
    //  Description:  Primary template.
    //  =====================================================================================
    template
    <
        template<typename> typename Unit, 
        typename TypeListSize,
        typename TypeList
    >
    class GenerateScatteredHierarchy : public Unit<mpl_front<TypeList>>,
                                       public mpl_size<TypeList>,
                                       public GenerateScatteredHierarchy<Unit,mpl_rest_size<TypeList>,mpl_rest<TypeList>> 
    {
        public:
            // ====================  LIFECYCLE     =======================================

            //--------------------------------------------------------------------------------------
            //       Class:  GenerateScatteredHierarchy
            //      Method:  GenerateScatteredHierarchy :: GenerateScatteredHierarchy
            // 
            //--------------------------------------------------------------------------------------
            GenerateScatteredHierarchy ()
            {
                return;
            }   // constructor

            GenerateScatteredHierarchy (const GenerateScatteredHierarchy & other)   // copy constructor
            {
                if (this != &other)
                {

                }
                return;
            }

            GenerateScatteredHierarchy (GenerateScatteredHierarchy && other)   // copy-move constructor
            {
                if (this != &other)
                {

                }
                return;
            }

            virtual ~GenerateScatteredHierarchy ()  // destructor
            {
                return;
            }

            // ====================  ACCESSORS     =======================================

            // ====================  MUTATORS      =======================================

            // ====================  OPERATORS     =======================================

            GenerateScatteredHierarchy& operator= ( const GenerateScatteredHierarchy &other ) // assignment operator
            {
                if ( this != &other )
                {

                }
                return *this;
            }

            GenerateScatteredHierarchy& operator= ( GenerateScatteredHierarchy && other ) // assignment-move operator
            {
                if ( this != &other )
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

    }; // -----  end of class GenerateScatteredHierarchy  -----


    // =====================================================================================
    //        Class:  GenerateScatteredHierarchy
    //  Description:  Partial specialization wheb TypeList has size 0.
    //  =====================================================================================
    template
    <
        template<typename> typename Unit, 
        typename TypeList
    >
    class GenerateScatteredHierarchy<Unit,mpl_size_0, TypeList> 
    {
        public: 
            GenerateScatteredHierarchy ()
            {
                return;
            }   // constructor
            
            GenerateScatteredHierarchy (const GenerateScatteredHierarchy & other)   // copy constructor
            {
                if (this != &other)
                {

                }
                return;
            }

            GenerateScatteredHierarchy (GenerateScatteredHierarchy && other)   // copy-move constructor
            {
                if (this != &other)
                {

                }
                return;
            }

            virtual ~GenerateScatteredHierarchy ()  // destructor
            {
                return;
            }

            // ====================  ACCESSORS     =======================================

            // ====================  MUTATORS      =======================================

            // ====================  OPERATORS     =======================================

            GenerateScatteredHierarchy& operator= ( const GenerateScatteredHierarchy &other ) // assignment operator
            {
                if ( this != &other )
                {

                }
                return *this;
            }

            GenerateScatteredHierarchy& operator= ( GenerateScatteredHierarchy && other ) // assignment-move operator
            {
                if ( this != &other )
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

    };

}; // namespace MPL


#endif   // ----- #ifndef MOUSEION_GenerateScatteredHierarchy_INC  ----- 
