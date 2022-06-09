# This CMakeLists.txt file creates the library lib__library__.a
# and its unit tests. To add source files, simply append the appropiate variable
# mpl_header_files or mpl_implementation_files.
#
# The target for the library is mpl.
#
# The following properties are set for the target mpl.
#
#   Property                            Value                                               Description
#----------------------------------------------------------------------------------------------------------------------------
#


#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#                                                                 @
# CMake preamble section.                                         @
#                                                                 @
#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

    #-----------------------------------------------------
    # Define the project.                                -
    #                                                    -
    #-----------------------------------------------------
    set(my_project_name "mpl")
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
    #                                                    -
    # We get the path to the above header files.         -
    #-----------------------------------------------------
    get_target_property(mm_include_dir memory_management memory_management_include)

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
    set (mpl_header_files
         header_files/EmptyList.h
         header_files/NullType.h
         header_files/EmptyType.h
         header_files/MPLAliases.hpp
         header_files/DefaultFactoryError.hpp
         header_files/Factory.hpp
         header_files/ConcreteFactory.hpp
         header_files/OpNewFactoryUnit.hpp
         header_files/AbstractFactoryUnit.hpp
         header_files/AbstractFactory.hpp
         header_files/GenerateScatteredHierarchy.hpp
         header_files/GenerateLinearHierarchy.hpp
         header_files/BaseVisitable.hpp
         header_files/BaseVisitor.h
         header_files/DefaultCatchAll.hpp
         header_files/DefineVisitableMacro.h
         header_files/ErrorUnknownVisitor.h
         header_files/Visitor.hpp
         header_files/RegisterObjectFactories.hpp
         header_files/Command.hpp )

    #-----------------------------------------------------
    # Here we define the variable                        -
    # command_line_arguments_implementation_files.       -
    # A list of implementation files is stored in this   -
    # variable.                                          -
    #                                                    -
    #-----------------------------------------------------
    set (mpl_implementation_files
         implementation_files/EmptyList.cpp
         implementation_files/NullType.cpp
         implementation_files/EmptyType.cpp
         implementation_files/MPLAliases.cpp
         implementation_files/DefaultFactoryError.cpp
         implementation_files/Factory.cpp 
         implementation_files/ConcreteFactory.cpp
         implementation_files/OpNewFactoryUnit.cpp
         implementation_files/AbstractFactoryUnit.cpp
         implementation_files/AbstractFactory.cpp
         implementation_files/GenerateScatteredHierarchy.cpp
         implementation_files/GenerateLinearHierarchy.cpp
         implementation_files/BaseVisitable.cpp
         implementation_files/BaseVisitor.cpp
         implementation_files/DefaultCatchAll.cpp
         implementation_files/DefineVisitableMacro.cpp
         implementation_files/ErrorUnknownVisitor.cpp
         implementation_files/Visitor.cpp
         implementation_files/RegisterObjectFactories.cpp
         implementation_files/Command.cpp )

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
    PRIVATE ${mpl_header_files} ${mpl_implementation_files} )

#-----------------------------------------------------
# Add the directory header_files to search for       -
# header files.                                      -
#                                                    -
#-----------------------------------------------------
target_include_directories(${target} 
                           PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/header_files
                           PRIVATE ${mm_include_dir}
                           PRIVATE ${Boost_INCLUDE_DIR} )

#-----------------------------------------------------
# Enable compile warnings.                           -
#                                                    -
#-----------------------------------------------------
enable_compile_warnings(${target})

#-----------------------------------------------------
# The libraries to use when linking to target.       -
#                                                    -
#-----------------------------------------------------
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries( ${target}
                       PUBLIC Threads::Threads
                       PUBLIC memory_management
                       ${Boost_LIBRARIES} )

#-----------------------------------------------------
# Here we set the properties on target               -
#                                                    -
#-----------------------------------------------------
set_target_properties(${target} PROPERTIES
                      mpl_include ${CMAKE_CURRENT_SOURCE_DIR}/header_files
                      PUBLIC_HEADER "${mpl_header_files}" )

install( TARGETS ${target}
         ARCHIVE DESTINATION ${mpl_install_lib_directory} 
         PUBLIC_HEADER DESTINATION ${mpl_install_include_directory} )

#-----------------------------------------------------
# Add the subdirectory for creating the unit tests.  -
#                                                    -
#-----------------------------------------------------
# add_subdirectory(unit_tests)
