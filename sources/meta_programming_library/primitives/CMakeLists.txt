# This CMakeLists.txt file creates the library libprimitives.a
# and its unit tests. To add source files, simply append the appropiate variable
# primitives_header_files or primitives_implementation_files.
#
# The target for the library is primitives.
#
# The following properties are set for the target primitives.
#
#   Property                            Value                                               Description
#----------------------------------------------------------------------------------------------------------------------------
# primitives_include


#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#                                                                 @
# CMake preamble section.                                         @
#                                                                 @
#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

    #-----------------------------------------------------
    # Define the project.                                -
    #                                                    -
    #-----------------------------------------------------
    set(my_project_name "primitives")
    project(${my_project_name})

    #-----------------------------------------------------
    # Define the target name.                            -
    #                                                    -
    #-----------------------------------------------------
    set(target ${my_project_name})

    # ----------------------------------------------------
    # Include primitives macros and functions.
    #
    # ----------------------------------------------------
    include("${CMAKE_CURRENT_SOURCE_DIR/cmake_macros_and_functions/primitives_build_prerequisites.cmake}")

    # ----------------------------------------------------
    # Verify that build prerequisites are met for building
    # primitives library. 
    # ----------------------------------------------------
    verify_primitives_build_prerequisites_are_set()

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
    # command_line_arguments_header_files.               -
    # A list of header files is stored in                -
    # this variable.                                     -
    #                                                    -
    #-----------------------------------------------------
    set (primitives_header_files
         header_files/NullType.h
         implementation_files/EmptyType.h )

    #-----------------------------------------------------
    # Here we define the variable                        -
    # command_line_arguments_implementation_files.       -
    # A list of implementation files is stored in this   -
    # variable.                                          -
    #                                                    -
    #-----------------------------------------------------
    set (primitives_implementation_files
         implementation_files/NullType.cpp
         implementation_files/EmptyType.cpp )

#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#                                                                 @
# End of defining the sources and header files associated         @
# with the command_line_arguments targets.                        @
#                                                                 @
#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

#-----------------------------------------------------
# Add the library associated with target             -
# command_line_arguments.                            -
#                                                    -
#-----------------------------------------------------
add_library( ${target} STATIC 
             "")

#-----------------------------------------------------
#                                                    -
# We associate the source files with the target.     -
#                                                    -
#-----------------------------------------------------
target_sources(${target}
               PRIVATE ${primitives_header_files} ${primitives_implementation_files} )

#-----------------------------------------------------
# Add the directory header_files to search for       -
# header files.                                      -
#                                                    -
#-----------------------------------------------------
target_include_directories(${target} 
                           PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/header_files )

#-----------------------------------------------------
# Enable compile warnings.                           -
#                                                    -
#-----------------------------------------------------
enable_compile_warnings(${target})

#-----------------------------------------------------
# The libraries to use when linking to target.       -
#                                                    -
# The target link command is commented out for, as of-
# the current primitive library, no external         -
# libraries need be linked against.                  -  
#-----------------------------------------------------
# target_link_libraries( ${target}
#                        <libraries to link against> )

#-----------------------------------------------------
# Here we set the properties on target               -
#                                                    -
#-----------------------------------------------------
set_target_properties(${target} PROPERTIES
                      primitives_include ${CMAKE_CURRENT_SOURCE_DIR}/header_files
                      PUBLIC_HEADER "${primitives_header_files}" )

install( TARGETS ${target}
         ARCHIVE DESTINATION  ${primitives_install_lib_directory}
         PUBLIC_HEADER DESTINATION ${primitives_install_include_directory} )

#-----------------------------------------------------
# Add the subdirectory for creating the unit tests.  -
#                                                    -
#-----------------------------------------------------
# add_subdirectory(unit_tests)
