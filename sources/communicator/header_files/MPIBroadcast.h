#ifndef  MPIBroadcast_INC
#define  MPIBroadcast_INC

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//
#include "mpi.h"

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//

namespace COMMUNICATOR
{

template<typename T>
class MPI_Broadcast;

template<>
class MPI_Broadcast<int>
{
    public:
    static int Broadcast(const int data_to_broadcast,
                         const MPI_Comm mpi_comm, const int root);

}; // -----  end of class MPI_BROADCAST  -----


}; // namespace COMMUNICATOR

#endif   // ----- #ifndef MPIBroadcast_INC  -----
