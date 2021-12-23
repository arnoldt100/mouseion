#ifndef __filepreprocessordefine__
#define __filepreprocessordefine__

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
//        Class:  Type2Type
//  Description:  
//  =====================================================================================
template <typename T>
class Type2Type
{
    public:
        // ====================  LIFECYCLE     =======================================

        //--------------------------------------------------------------------------------------
        //       Class:  Type2Type
        //      Method:  Type2Type :: Type2Type
        // Description:  
        // 
        //  Parameters: 
        //
        //      Return:
        //--------------------------------------------------------------------------------------
        Type2Type ()   // constructor
        {
            return;
        }

        Type2Type (const Type2Type & other) // copy constructor
        {
            return;
        }

        Type2Type (Type2Type && other) // copy-move constructor
        {
            return;
        }
        
        ~Type2Type () // destructor
        {
            return;
        }

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        Type2Type& operator= ( const Type2Type &other ) // assignment operator
        {
            if (this != &other)
            {

            }
            return *this;
        } // assignment operator

        Type2Type& operator= ( Type2Type && other ) // assignment-move operator
        {
            if (this != &other)
            {

            }
            return *this;
        } // assignment operator

        // ====================  METHODS       =======================================
        using OriginalType = T;

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class Type2Type  -----


}; // namespace MPL

#endif // __filepreprocessordefine__
