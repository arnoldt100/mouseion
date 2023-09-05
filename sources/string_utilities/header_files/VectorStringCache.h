#ifndef STRING_UTILITIES_VectorStringCache_INC
#define STRING_UTILITIES_VectorStringCache_INC
//! \file VectorStringCache.h

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <vector>
#include <string>
#include <cstddef>
#include <memory>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//

namespace STRING_UTILITIES
{

//! \brief  Caches or stores a vector of strings.
class VectorStringCache
{
    public:
        // ====================  LIFECYCLE     =======================================

        VectorStringCache ();   // constructor

        explicit VectorStringCache(const std::vector<std::string> & str_vec); 

        VectorStringCache(std::size_t ncpv_length,
                          std::unique_ptr<std::size_t[]> ncpv_array,
                          std::size_t ca_length,
                          std::unique_ptr<char[]> ca_array);

        VectorStringCache (const VectorStringCache & other);   // copy constructor

        VectorStringCache (VectorStringCache && other);   // copy-move constructor

        ~VectorStringCache ();  // destructor

        // ====================  ACCESSORS     =======================================
        //! \brief Returns the length of the array that stores the number  
        //!        of characters per element in the string vector.
        std::size_t getNumberCharactersPerVectorArrayLength() const;

        //! \brief Returns the length of the array that stores all the characters
        //!        in the vector of strings.
        std::size_t getCharacterArrayLength() const;

        //! \brief Returns the array of the number characters per vector element.
        std::unique_ptr<std::size_t[]> getArrayOfNumberCharactersPerVector() const;

        std::unique_ptr<char[]> getArrayOfCharacters() const;

        //! \brief Returns a string vector of the keys.
        std::vector<std::string> getKeyStringVector() const;

        //! \brief Returns a string vector of the values.
        std::vector<std::string> getValueStringVector() const;

        //! \brief Prints contents to  stndard out.
        void printToStdOut() const;

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        VectorStringCache& operator= ( const VectorStringCache &other ); // assignment operator

        VectorStringCache& operator= ( VectorStringCache && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================
        std::size_t ncpvLength_;
        std::unique_ptr<std::size_t[]> numberCharactersPerVectorElement_;

        std::size_t caLength_; 
        std::unique_ptr<char[]> charactersArray_;

}; // -----  end of class VectorStringCache  -----


}; // namespace STRING_UTILITIES

#endif // STRING_UTILITIES_VectorStringCache_INC
