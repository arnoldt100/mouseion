# This CMakeLists.txt file creates the library libtypelist_aliases.a
# and its unit tests. To add source files, simply append the appropiate variable
# typelist_aliases_header_files or typelist_aliases_implementation_files.
#
# The target for the library is typelist_aliases.
#
# The following properties are set for the target typelist_aliases.
#
#   Property                            Value                                               Description
#----------------------------------------------------------------------------------------------------------------------------
# typelist_aliases_include              ${CMAKE_CURRENT_SOURCE_DIR}/header_files            The path to the header files    


#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#                                                                 @
# CMake preamble section.                                         @
#                                                                 @
#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

    #-----------------------------------------------------
    # Define the project.                                -
    #                                                    -
    #-----------------------------------------------------
    set(my_project_name "typelist_aliases")
    project(${my_project_name})

    #-----------------------------------------------------
    # Define the target name.                            -
    #                                                    -
    #-----------------------------------------------------
    set(target ${my_project_name})

    # ----------------------------------------------------
    # Include all macros and functions. 
    # 
    # ----------------------------------------------------
    include(${CMAKE_CURRENT_SOURCE_DIR}/cmake_macros_and_functions/typelist_aliases_build_prerequisites.cmake)

    # ----------------------------------------------------
    #  Verify that all build prerequisites are met for
    #  building the typelist_aliases library.
    #
    # ----------------------------------------------------
    verify_typelist_aliases_build_prerequisites()

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
    set (typelist_aliases_header_files
        header_files/MPLAliases.hpp )

    #-----------------------------------------------------
    # Here we define the variable                        -
    # command_line_arguments_implementation_files.       -
    # A list of implementation files is stored in this   -
    # variable.                                          -
    #                                                    -
    #-----------------------------------------------------
    set (typelist_aliases_implementation_files
         implementation_files/MPLAliases.cpp )

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
               PRIVATE ${typelist_aliases_header_files} ${typelist_aliases_implementation_files} )

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
# Here we set the properties on target               -
#                                                    -
#-----------------------------------------------------
set_target_properties(${target} PROPERTIES
                      typelist_aliases_include ${CMAKE_CURRENT_SOURCE_DIR}/header_files
                      PUBLIC_HEADER "${typelist_aliases_header_files}" )

install( TARGETS ${target}
         ARCHIVE DESTINATION <where to install library> 
         PUBLIC_HEADER DESTINATION <where to install headers> )

#-----------------------------------------------------
# Add the subdirectory for creating the unit tests.  -
#                                                    -
#-----------------------------------------------------
# add_subdirectory(unit_tests)
