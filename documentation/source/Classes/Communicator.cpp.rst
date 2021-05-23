.. _Communicator source target:

.. default-domain:: cpp

.. namespace:: COMMUNICATOR

##########################
Communicator Documentation
##########################

The base class for the communicator classes. This
class is an abstract base class. 

======================
Interface Header Files
======================

**C++ Include Files**

* #include <string>
* #include <vector>
* #include <memory>
* #include <map>
* #include <cstring>
* #include <iostream>

**External Library Files**

**Project Include Files**

==========================
Implementaion Header Files
==========================

**C++ Include Files**

**External Library Files**

**Project Include Files**

* #include "Communicator.h"
* #include "Array1d.hpp"
* #include "Array1dChar.hpp"
* #include "convert_sequence_of_chars_to_vector_string.h"

===============================
Communicator.h Global Variables
===============================

================================
Communicator Class Documentation
================================

.. class:: Communicator

--------------
Public Members
--------------

^^^^^^^^^
Lifecycle
^^^^^^^^^

    .. function:: Communicator()

       The default constructor.

    .. function:: Communicator( const Communicator &other )

        The copy constructor.

    .. function:: Communicator(Communicator && other) 

        The copy-move constructor.

    .. function:: virtual ~Communicator()=0

        The destructor.

^^^^^^^^^
Accessors
^^^^^^^^^

    No public accessors

^^^^^^^^^
Operators
^^^^^^^^^

    .. function:: Communicator& operator=( Communicator const & other)

        The assignment operator.

    .. function:: Communicator& operator=( Communicator && other)

        The assignment-move operator.

^^^^^^^^
Mutators
^^^^^^^^

-----------------
Protected Members
-----------------

    No protected members

.. Commented out. 
.. ^^^^^^^^^
.. Lifecycle
.. ^^^^^^^^^
..
.. ^^^^^^^^^
.. Accessors
.. ^^^^^^^^^
.. 
.. ^^^^^^^^^
.. Operators
.. ^^^^^^^^^
.. 
.. ^^^^^^^^^
.. Mutators
.. ^^^^^^^^^
.. 
.. ^^^^^^^^^^^^
.. Data Members
.. ^^^^^^^^^^^^

---------------
Private Members
---------------

    No private members

.. Commented out. 
.. ^^^^^^^^^
.. Lifecycle
.. ^^^^^^^^^
..
.. ^^^^^^^^^
.. Accessors
.. ^^^^^^^^^
.. 
.. ^^^^^^^^^
.. Operators
.. ^^^^^^^^^
.. 
.. ^^^^^^^^^
.. Mutators
.. ^^^^^^^^^
.. 
.. ^^^^^^^^^^^^
.. Data Members
.. ^^^^^^^^^^^^
