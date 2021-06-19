.. _MPIBroadcast source target:

.. default-domain:: cpp

.. namespace:: COMMUNICATOR

##########################
MPIBroadcast Documentation
##########################

This class provides an interface to the MPI broadcast calls.

======================
Interface Header Files
======================

**C++ Include Files**

**External Library Files**

* #include "mpi.h"

**Project Include Files**



==========================
Implementaion Header Files
==========================

**C++ Include Files**

**External Library Files**

**Project Include Files**

* #include "Array1d.hpp"
* #include "MPIBroadcast.h"

===============================
MPIBroadcast.h Global Variables
===============================

================================
MPIBroadcast Class Documentation
================================

.. class:: MPIBroadcast

--------------
Public Members
--------------

^^^^^^^^^^^^^^^^
Static Functions
^^^^^^^^^^^^^^^^

    .. function:: static int MPIBroadcast::Broadcast(const int data_to_broadcast, const MPI_Comm mpi_comm, const std::size_t bcast_rank)

        Broadcasts a single integer to all other ranks in communicator *mpi_comm*.
        
        :param int data_to_broadcast: The data to be broadcasted.
        :param std::size_t bcast_rank: The rank of communicator doing the broadcasting.
        :return: The broadcasted data.
        :rtype: int
