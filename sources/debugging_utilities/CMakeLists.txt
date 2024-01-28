# This CMakeLists.txt file creates the library libdebugging_utilities.a
# and its unit tests. To add source files, simply append the appropiate variable
# debugging_utilities_header_files or debugging_utilities_implementation_files.
#
# The target for the library is debugging_utilities. 
#
# The following properties are set for the target debugging_utilities:
#
#   Property                            Value                                               Description
#----------------------------------------------------------------------------------------------------------------------------
#   debugging_utilities_include      ${CMAKE_CURRENT_SOURCE_DIR}/header_files            The location of the header files.
#   PUBLIC_HEADER                       ${debugging_utilities_header_files}
#
# The build will abort unless the following variables are defined to
# install the library archive, header files, and unit tests:
#   debugging_utilities_install_lib_directory
#   debugging_utilities_install_include_directory
#   debugging_utilities_install_bin_directory


#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#                                                                 @
# CMake preamble section.                                         @
#                                                                 @
#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

    #-----------------------------------------------------
    # Define the project.                                -
    #                                                    -
    #-----------------------------------------------------
    set(my_project_name "debugging_utilities")
    project(${my_project_name})

    #-----------------------------------------------------
    # Define the target name.                            -
    #                                                    -
    #-----------------------------------------------------
    set(target ${my_project_name})

    #-----------------------------------------------------
    # Set various variables for include directories.     -
    #                                                    -
    #-----------------------------------------------------

    #-----------------------------------------------------
    # Include various functions and macros.              -
    #                                                    -
    #-----------------------------------------------------
    include(cmake_macros_and_functions/debugging_utilities_build_prerequisites.cmake)

    #-----------------------------------------------------
    # Verify key variables are set.                      -
    #                                                    -
    #-----------------------------------------------------
    verify_debugging_utilities_build_prerequisites_are_set()

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
    # debugging_utilities_header_files.                  -
    # A list of header files is stored in                -
    # this variable.                                     -
    #                                                    -
    #-----------------------------------------------------
    set (debugging_utilities_header_files
         header_files/AssertMessage.h
         header_files/BaseException.h
         header_files/AssertValidValueForType.hpp)

    #-----------------------------------------------------
    # Here we define the variable                        -
    # debugging_utilities_implementation_files.          -
    # A list of implementation files is stored in this   -
    # variable.                                          -
    #                                                    -
    #-----------------------------------------------------
    set (debugging_utilities_implementation_files
         implementation_files/AssertMessage.cpp
         implementation_files/BaseException.cpp
         implementation_files/AssertValidValueForType.cpp)

#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#                                                                 @
# End of defining the sources and header files associated         @
# with the debugging_utilities targets.                           @
#                                                                 @
#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

#-----------------------------------------------------
# Add the library associated with target             -
# debugging_utilities.                               -
#                                                    -
#-----------------------------------------------------
add_library( ${target} STATIC 
             "")

# ----------------------------------------------------
# Add dependencies on other targets.
# 
# ----------------------------------------------------

#-----------------------------------------------------
#                                                    -
# We associate the source files with the target.     -
#                                                    -
#-----------------------------------------------------
target_sources(${target}
               PRIVATE ${debugging_utilities_header_files} ${debugging_utilities_implementation_files} )

#-----------------------------------------------------
# Add the directory header_files to search for       -
# header files.                                      -
#                                                    -
#-----------------------------------------------------
target_include_directories(${target} 
                           PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/header_files)

#-----------------------------------------------------
# Set the list of libraries to link against.         -
#                                                    -
#-----------------------------------------------------
# target_link_libraries(...) 

#-----------------------------------------------------
# Enable compile warnings.                           -
#                                                    -
#-----------------------------------------------------
enable_mouseion_compile_warnings(${target})

#-----------------------------------------------------
# Here we set the properties on target               -
#                                                    -
#-----------------------------------------------------
set_target_properties(${target} PROPERTIES
                      debugging_utilities_include ${CMAKE_CURRENT_SOURCE_DIR}/header_files
                      CXX_STANDARD ${debugging_utilities_cxx_standard}
                      PUBLIC_HEADER "${debugging_utilities_header_files}" )

install( TARGETS ${target}
         ARCHIVE DESTINATION ${debugging_utilities_install_lib_directory}
         PUBLIC_HEADER DESTINATION ${debugging_utilities_install_include_directory} )

