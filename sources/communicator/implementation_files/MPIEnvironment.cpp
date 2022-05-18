//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <iostream>
#include <cstdlib>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//
#include "mpi.h"

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "MPIInitException.h"
#include "MPIInitializedException.h"
#include "MPIFinalizedException.h"
#include "MPIEnvironment.h"
#include "Pointer2d.hpp"
#include "copy_2d_char_array.h"

namespace COMMUNICATOR {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

MPIEnvironment::MPIEnvironment() :
    COUNTERCLASSES::ClassInstanceLimiter<MPIEnvironment,MAX_MPIENVIRONMENT_INSTANCES>()
{
    this->changeMPIState_<COMMUNICATOR::NullMPIEnvironment>();
    return;
}

MPIEnvironment::~MPIEnvironment()
{
    return;
}

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

void MPIEnvironment::enableEnvironment() 
{
    this->mpistate_->enable(this);
    return;
}

void MPIEnvironment::enableEnvironment(int const & argc, char const * const * const & argv) 
{
    this->mpistate_->enable(this,argc,argv);
    return;
}

void MPIEnvironment::disableEnvironment() 
{
    this->mpistate_->disable();
    return;
}
//============================= OPERATORS ====================================

//============================= STATIC =======================================

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PROTECTED ////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PRIVATE //////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================
void MPIEnvironment::enable_(int const & argc, char const * const * const & argv) 
{

    // Verify that the MPI environment is not already initialized. If
    // the MPI environment is not initialized, the call MPI_Init.
    try
    {
        int flag;
        int mpi_return_code = MPI_Initialized( &flag );
        if (flag)
        {
            throw COMMUNICATOR::MPIInitializedException();
        }

        int tmp_argc = argc;
        char** tmp_argv = nullptr;

        STRING_UTILITIES::copy_2d_char_array(tmp_argc,argv,tmp_argv);
        mpi_return_code = MPI_Init(&tmp_argc,&tmp_argv);

        if (mpi_return_code != MPI_SUCCESS)
        {
            throw COMMUNICATOR::MPIInitException();
        }
    }
    catch(COMMUNICATOR::MPIInitializedException const & my_mpi_exception)
    {
        std::cout << my_mpi_exception.what() << std::endl;
        std::abort();
    }
    catch (COMMUNICATOR::MPIInitException const & my_mpi_exception)
    {
        std::cout << my_mpi_exception.what() << std::endl;
        std::abort();
    }
    return;
}

void MPIEnvironment::disable_()
{
    try 
    {
        int mpi_return_code = MPI_Finalize();
        if (mpi_return_code != MPI_SUCCESS)
        {
            throw COMMUNICATOR::MPIFinalizedException();
        }
    }
    catch(COMMUNICATOR::MPIFinalizedException const & my_mpi_exception)
    {
        std::cout << my_mpi_exception.what() << std::endl;
        std::abort();
    }
    return;
}

void MPIEnvironment::enable_()
{

    // Verify that the MPI environment is not already initialized. If
    // the MPI environment is not initialized, the call MPI_Init.
    try
    {
        int flag;
        int mpi_return_code = MPI_Initialized( &flag );
        if (flag)
        {
            throw COMMUNICATOR::MPIInitializedException();
        }

        int tmp_argc = 0;
        char** tmp_argv = nullptr;

        mpi_return_code = MPI_Init(&tmp_argc,&tmp_argv);

        if (mpi_return_code != MPI_SUCCESS)
        {
            throw COMMUNICATOR::MPIInitException();
        }
    }
    catch(COMMUNICATOR::MPIInitializedException const & my_mpi_exception)
    {
        std::cout << my_mpi_exception.what() << std::endl;
        std::abort();
    }
    catch (COMMUNICATOR::MPIInitException const & my_mpi_exception)
    {
        std::cout << my_mpi_exception.what() << std::endl;
        std::abort();
    }
    return;
}


//============================= OPERATORS ====================================


} /* namespace COMMUNICATOR */
