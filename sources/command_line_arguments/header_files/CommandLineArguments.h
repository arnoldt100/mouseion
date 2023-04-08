#ifndef COMMANDLINEARGUMENTS_INC
#define COMMANDLINEARGUMENTS_INC

//! @file CommandLineArguments.hpp
//!
//! Contains the class CommandLineArguments declarations.

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <string>
#include <vector>

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//

namespace COMMANDLINE
{

//!  CommandLineArguments is an abstration of the prgram's command line arguments.
class CommandLineArguments
{
    public:
        /* ====================  LIFECYCLE     ======================================= */

        CommandLineArguments();

        //! @param [in] argc The number of command line arguments.
        //! @param [in] argv The command line arguments.
        CommandLineArguments( const int argc, char const * const *const & argv);

        CommandLineArguments( const CommandLineArguments &other ); /* Copy constructor */

        CommandLineArguments( CommandLineArguments && other ); /* Move-Copy constructor */

        ~CommandLineArguments(); /* destructor */

        /* ====================  ACCESSORS     ======================================= */

        //! Reforms the command line arguments as argc and argv.
        //!
        //! @param [out] argc The number of command line arguments.
        //! @param [out] argv The command line arguments.
        void reformCommandLineArguments(int & argc, char** & argv) const;


        //! Returns true if the command line argument stored in str is found, otherwise false is returned.
        //!
        //! @param [in] str The argument to check for existence in the command line.
        //! @retval bool

        bool verifyArgumentInCommandLine( const std::string & str ) const;

        /* ====================  MUTATORS      ======================================= */

        //! Resets the object so that no command line arguments are stored.
        void reset();

        /* ====================  OPERATORS     ======================================= */

        CommandLineArguments&
        operator=( const CommandLineArguments &other ); /* Assignment operator */

        CommandLineArguments&
        operator=(  CommandLineArguments && other ); /* Move-Assignment operator */

    protected:
        /* ====================  METHODS       ======================================= */

        /* ====================  DATA MEMBERS  ======================================= */

    private:
        /* ====================  METHODS       ======================================= */

        /* ====================  DATA MEMBERS  ======================================= */

        //! The number of command line arguments
        std::size_t _numberOfArguments;

        //! Stores the command line arguments.
        std::vector<std::string> _commandLineArguments;

}; /* -----  end of class CommandLineArguments  ----- */


}; /* namespace COMMANDLINE */

#endif /* COMMANDLINEARGUMENTS_INC */


