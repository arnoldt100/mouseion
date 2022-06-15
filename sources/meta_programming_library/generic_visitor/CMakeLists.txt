# This CMakeLists.txt file creates the library libgeneric_visitor.a
# and its unit tests. To add source files, simply append the appropiate variable
# generic_visitor_header_files or generic_visitor_implementation_files.
#
# The target for the library is generic_visitor.
#
# The following properties are set for the target generic_visitor.
#
#   Property                            Value                                               Description
#----------------------------------------------------------------------------------------------------------------------------
# generic_visitor_include               ${CMAKE_CURRENT_SOURCE_DIR}/header_files            The path to the package header 
#                                                                                           files


#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#                                                                 @
# CMake preamble section.                                         @
#                                                                 @
#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

    #-----------------------------------------------------
    # Define the project.                                -
    #                                                    -
    #-----------------------------------------------------
    set(my_project_name "generic_visitor")
    project(${my_project_name})

    #-----------------------------------------------------
    # Define the target name.                            -
    #                                                    -
    #-----------------------------------------------------
    set(target ${my_project_name})

    # ----------------------------------------------------
    # Include all macros and functions 
    # ----------------------------------------------------
    include(${CMAKE_CURRENT_SOURCE_DIR}/cmake_macros_and_functions/generic_visitor_build_prerequisites.cmake)

    #-----------------------------------------------------
    # This library needs access to the following header
    # files:
    # 
    #   primitives target header files
    #
    # We get the path to the above header files.
    #----------------------------------------------------- 
    get_target_property(my_primitives_include_dir primitives primitives_include)

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

    # ----------------------------------------------------
    # Verify that the generic_visitor build prerequisites
    # met.
    # ----------------------------------------------------
    verify_generic_visitor_build_prerequisites_are_set()

    #-----------------------------------------------------
    # Here we define the variable                        -
    # command_line_arguments_header_files.               -
    # A list of header files is stored in                -
    # this variable.                                     -
    #                                                    -
    #-----------------------------------------------------
    set (generic_visitor_header_files
         <list of header files> )

    #-----------------------------------------------------
    # Here we define the variable                        -
    # command_line_arguments_implementation_files.       -
    # A list of implementation files is stored in this   -
    # variable.                                          -
    #                                                    -
    #-----------------------------------------------------
    set (generic_visitor_implementation_files
         <list of implementation files> )

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
    PRIVATE ${generic_visitor_header_files} ${generic_visitor_implementation_files} )

#-----------------------------------------------------
# Add the directory header_files to search for       -
# header files.                                      -
#                                                    -
#-----------------------------------------------------
target_include_directories(${target} 
                           PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/header_files
                           PRIVATE ${my_primitives_include_dir} )

#-----------------------------------------------------
# The libraries to use when linking to target.
#
#-----------------------------------------------------
target_link_libraries(${target}
                      PUBLIC primitives)

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
                      generic_visitor_include ${CMAKE_CURRENT_SOURCE_DIR}/header_files
                      PUBLIC_HEADER "${generic_visitor_header_files}" )

install( TARGETS ${target}
         ARCHIVE DESTINATION ${generic_visitor_install_lib_directory} 
         PUBLIC_HEADER DESTINATION ${generic_visitor_install_include_directory} )

#-----------------------------------------------------
# Add the subdirectory for creating the unit tests.  -
#                                                    -
#-----------------------------------------------------
add_subdirectory(unit_tests)
