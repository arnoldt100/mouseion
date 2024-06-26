# This CMakeLists.txt file creates the library libmpi_communicator.a
# and its unit tests. To add source files, simply append the appropiate variable
# communicator_header_files or communicator_implementation_files.
#
# The target for the library is communicator.
#
# The following properties are set for the target :
#
#   Property                            Value                                               Description
#----------------------------------------------------------------------------------------------------------------------------
#   communicator_include                ${CMAKE_CURRENT_SOURCE_DIR}/header_files            The location of the header files.
#   PUBLIC_HEADER                       ${communicator_header_files}                        The list of headers files associated with this librarry.
#
# The build will abort unless the following variables are defined to
# install the library archive, header files, and unit tests:
#   communicator_install_lib_directory
#   communicator_install_include_directory
#   communicator_install_bin_directory
#   communicator_cxx_standard

#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#                                                                 @
# CMake preamble section.                                         @
#                                                                 @
#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

    #-----------------------------------------------------
    # Define the project.                                -
    #                                                    -
    #-----------------------------------------------------
    set(my_project_name "communicator")
    project(${my_project_name})

    #-----------------------------------------------------
    # Define the target name.                            -
    #                                                    -
    #-----------------------------------------------------
    set(target ${my_project_name})

    #-----------------------------------------------------
    # Include various functions and macros.              -
    #                                                    -
    #-----------------------------------------------------
    include(cmake_macros_and_functions/communicator_build_prerequisites.cmake)

    #-----------------------------------------------------
    # Verify key variables are set.                      -
    #                                                    -
    #-----------------------------------------------------
    verify_key_environmental_are_set()

    #-----------------------------------------------------
    # This library needs access to the following header  -
    # files:                                             -
    #                                                    -
    #   memory_management target header files            -
    #   string_utilities target header files             -
    #                                                    -
    # We get the path to the above header files.         -
    #-----------------------------------------------------
    get_target_property(my_mm_include memory_management memory_management_include)
    get_target_property(my_su_include string_utilities string_utilities_include)
    get_target_property(my_cc_include counterclass counterclass_include)

#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#                                                                 @
# End of CMake preamble section.                                  @
#                                                                 @
#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#                                                                 @
# Here we define the sources and header files associated          @
# with the various targets.                                       @
#                                                                 @
#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

    #-----------------------------------------------------
    # Here we define the variable                        -
    # communicator_header_files.                         -
    # A list of header files is stored in                -
    # this variable.                                     -
    #                                                    -
    #-----------------------------------------------------
    set (communicator_header_files
         header_files/MasterProcess.h
         header_files/create_master_process_tag.hpp
         header_files/create_communicator_rank_tag.hpp
         header_files/create_communicator_size_tag.hpp
         header_files/create_communicator_embryo.hpp
         header_files/CommunicatorRank.h
         header_files/CommunicatorSize.h
         header_files/CommunicatorFactory.h
         header_files/Communicator.h
         header_files/CommunicatorEmbryo.h
         header_files/is_communicator_type.hpp)

    #-----------------------------------------------------
    # Here we define the variable                        -
    # communicator_implementation_files.                 -
    # A list of implementation files is stored in this   -
    # variable.                                          -
    #                                                    -
    #-----------------------------------------------------
    set (communicator_implementation_files
         implementation_files/MasterProcess.cpp
         implementation_files/create_master_process_tag.cpp
         implementation_files/create_communicator_rank_tag.cpp
         implementation_files/create_communicator_size_tag.cpp
         implementation_files/create_communicator_embryo.cpp
         implementation_files/CommunicatorRank.cpp
         implementation_files/CommunicatorSize.cpp
         implementation_files/CommunicatorFactory.cpp
         implementation_files/Communicator.cpp
         implementation_files/CommunicatorEmbryo.cpp
         implementation_files/is_communicator_type.cpp)

#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#                                                                 @
# End of defining the sources and header files associated         @
# with the communicator targets.                                  @
#                                                                 @
#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

#-----------------------------------------------------
# Add the library associated with target             -
# communicator.                                      -
#                                                    -
#-----------------------------------------------------
add_library( ${target} STATIC 
             "")

#-----------------------------------------------------
# Enable compile warnings.                           -
#                                                    -
#-----------------------------------------------------
enable_mouseion_compile_warnings(${target})

#-----------------------------------------------------
#                                                    -
# We associate the source files with the target.     -
#                                                    -
#-----------------------------------------------------
target_sources(${target}
               PRIVATE ${communicator_header_files} ${communicator_implementation_files} )

#-----------------------------------------------------
# Add the directory header_files to search for       -
# header files.                                      -
#                                                    -
#-----------------------------------------------------
target_include_directories(${target} 
                           PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/header_files
                           PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/header_files/details
                           PRIVATE ${my_su_include}
                           PRIVATE ${my_mm_include}
                           PRIVATE ${my_cc_include})

#-----------------------------------------------------
# The libraries to use when linking to target.       -
#                                                    -
#-----------------------------------------------------
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries( ${target}
                       PUBLIC Threads::Threads
                       PUBLIC string_utilities
                       PUBLIC memory_management 
                       PUBLIC counterclass)

#-----------------------------------------------------
# Here we set the properties on target               -
#                                                    -
#-----------------------------------------------------
set_target_properties(${target} PROPERTIES
                      communicator_include ${CMAKE_CURRENT_SOURCE_DIR}/header_files
                      CXX_STANDARD ${communicator_cxx_standard}
                      PUBLIC_HEADER "${communicator_header_files}" )

install(TARGETS ${target}
        ARCHIVE DESTINATION ${communicator_install_lib_directory}
        PUBLIC_HEADER DESTINATION ${communicator_install_include_directory} )

#-----------------------------------------------------
# Add the subdirectory for creating the unit tests.  -
#                                                    -
#-----------------------------------------------------
add_subdirectory(unit_tests)
