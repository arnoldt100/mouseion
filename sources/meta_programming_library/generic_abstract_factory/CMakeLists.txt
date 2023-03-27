# This CMakeLists.txt file creates the library libgeneric_abstract_factory.a
# and its unit tests. To add source files, simply append the appropiate variable
# generic_abstract_factory_header_files or generic_abstract_factory_implementation_files.
#
# The target for the library is generic_abstract_factory.
#
# The following properties are set for the target generic_abstract_factory.
#
#   Property                            Value                                               Description
#----------------------------------------------------------------------------------------------------------------------------
# generic_abstract_factory_include     ${CMAKE_CURRENT_SOURCE_DIR}/header_files             The path to the header files for package
#                                                                                           generic_abstract_factory.


#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#                                                                 @
# CMake preamble section.                                         @
#                                                                 @
#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

    #-----------------------------------------------------
    # Define the project.                                -
    #                                                    -
    #-----------------------------------------------------
    set(my_project_name "generic_abstract_factory")
    project(${my_project_name})

    #-----------------------------------------------------
    # Define the target name.                            -
    #                                                    -
    #-----------------------------------------------------
    set(target ${my_project_name})

    #-----------------------------------------------------
    # This library needs access to the following header  -
    # files:                                             -
    #                                                    -
    #   memory_management target header files            -
    #   typelist_aliases  target header files.           -
    #                                                    -
    # We get the path to the above header files.         -
    #-----------------------------------------------------
    get_target_property(mm_include_dir memory_management memory_management_include)
    get_target_property(my_typelist_aliases_include_dir typelist_aliases typelist_aliases_include)
    get_target_property(my_generic_class_generation_include_dir generic_class_generation generic_class_generation_include)

    # ----------------------------------------------------
    # Include all macros and functions.
    #
    # ----------------------------------------------------
    include(${CMAKE_CURRENT_SOURCE_DIR}/cmake_macros_and_functions/generic_abstract_factory_build_prerequisites.cmake)

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
    set (generic_abstract_factory_header_files
         header_files/ConcreteFactory.hpp
         header_files/OpNewFactoryUnit.hpp
         header_files/AbstractFactoryUnit.hpp
         header_files/AbstractFactory.hpp
         header_files/AbstractFactoryUtilities.hpp)

    #-----------------------------------------------------
    # Here we define the variable                        -
    # command_line_arguments_implementation_files.       -
    # A list of implementation files is stored in this   -
    # variable.                                          -
    #                                                    -
    #-----------------------------------------------------
    set (generic_abstract_factory_implementation_files
         implementation_files/ConcreteFactory.cpp
         implementation_files/OpNewFactoryUnit.cpp
         implementation_files/AbstractFactoryUnit.cpp
         implementation_files/AbstractFactory.cpp
         implementation_files/AbstractFactoryUtilities.cpp)

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
    PRIVATE ${generic_abstract_factory_header_files} ${generic_abstract_factory_implementation_files} )

#-----------------------------------------------------
# Add the directory header_files to search for       -
# header files.                                      -
#                                                    -
#-----------------------------------------------------
target_include_directories(${target} 
                           PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/header_files
                           PRIVATE ${mm_include_dir}
                           PRIVATE ${my_typelist_aliases_include_dir}
                           PRIVATE ${my_generic_class_generation_include_dir}
                           PRIVATE ${Boost_INCLUDE_DIR} )

#-----------------------------------------------------
# Enable compile warnings.                           -
#                                                    -
#-----------------------------------------------------
enable_mouseion_compile_warnings(${target})

#-----------------------------------------------------
# The libraries to use when linking to target.       -
#                                                    -
#-----------------------------------------------------
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries( ${target}
                       PUBLIC Threads::Threads
                       PUBLIC memory_management
                       PUBLIC typelist_aliases
                       PUBLIC generic_class_generation
                       ${Boost_LIBRARIES} )

#-----------------------------------------------------
# Here we set the properties on target               -
#                                                    -
#-----------------------------------------------------
set_target_properties(${target} PROPERTIES
                      CXX_STANDARD ${generic_abstract_factory_cxx_standard}
                      generic_abstract_factory_include ${CMAKE_CURRENT_SOURCE_DIR}/header_files
                      PUBLIC_HEADER "${generic_abstract_factory_header_files}" )

install( TARGETS ${target}
         ARCHIVE DESTINATION ${generic_abstract_factory_install_lib_directory} 
         PUBLIC_HEADER DESTINATION ${generic_abstract_factory_install_include_directory} )

#-----------------------------------------------------
# Add the subdirectory for creating the unit tests.  -
#                                                    -
#-----------------------------------------------------
# add_subdirectory(unit_tests)
