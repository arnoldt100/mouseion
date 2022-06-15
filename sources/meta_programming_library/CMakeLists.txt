# This CMakeLists.txt file creates the library libmpl.a
# and its unit tests. To add source files, simply append the appropiate variable
# mpl_header_files or mpl_implementation_files.
#
# The target for the library is mpl.
#
# The following properties are set for the target mpl.
#
#   Property                            Value                                               Description
#----------------------------------------------------------------------------------------------------------------------------
# mpl_include                           ${CMAKE_CURRENT_SOURCE_DIR}/header_files            The location of the mpl header files.

#-----------------------------------------------------
# Here we define some variables.                     -
# that are critical for building and deploying.      -
#-----------------------------------------------------
set(mouseion_cmake_cxx_compiler $ENV{MOUSEION_CMAKE_CXX_COMPILER})
set(mouseion_cxx_standard $ENV{MOUSEION_CXX_STANDARD})
set(mouseion_cmake_c_compiler $ENV{MOUSEION_CMAKE_C_COMPILER})
set(mouseion_install_prefix $ENV{MOUSEION_INSTALL_PREFIX})
set(mouseion_install_bin_directory $ENV{MOUSEION_INSTALL_BIN_DIRECTORY})
set(mouseion_install_include_directory $ENV{MOUSEION_INSTALL_INCLUDE_DIRECTORY})
set(mouseion_install_lib_directory $ENV{MOUSEION_INSTALL_LIB_DIRECTORY})
set(mouseion_boost_top_level $ENV{MOUSEION_BOOST_TOP_LEVEL}  )

#-----------------------------------------------------
# Make available the project cmake modules.          -
#                                                    -
#-----------------------------------------------------
include( ${CMAKE_CURRENT_LIST_DIR}/cmake_macros_and_functions/mpl_build_prerequisites.cmake )
include( ${CMAKE_CURRENT_LIST_DIR}/generic_foreach_loop/cmake_macros_and_functions/generic_foreach_loop.cmake)
include( ${CMAKE_CURRENT_LIST_DIR}/generic_object_factory/cmake_macros_and_functions/generic_object_factory.cmake)
include( ${CMAKE_CURRENT_LIST_DIR}/typelist_aliases/cmake_macros_and_functions/typelist_aliases.cmake)
include( ${CMAKE_CURRENT_LIST_DIR}/generic_class_generation/cmake_macros_and_functions/generic_class_generation.cmake)

# ----------------------------------------------------
# Here we define variables which indicate where
# to install the foreach_loop libraries,
# header files, and associated binariers.
# 
# ----------------------------------------------------
enable_building_generic_foreach_loop_library("${mouseion_install_lib_directory}"
                                             "${mouseion_install_include_directory}"
                                             "${mouseion_install_bin_directory}"
                                             "${mouseion_cmake_c_compiler}"
                                             "${mouseion_cmake_cxx_compiler}"
                                             "${mouseion_cxx_standard}")

enable_building_generic_object_factory_library("${mouseion_install_lib_directory}"
                                               "${mouseion_install_include_directory}"
                                               "${mouseion_install_bin_directory}"
                                               "${mouseion_cmake_c_compiler}"
                                               "${mouseion_cmake_cxx_compiler}"
                                               "${mouseion_cxx_standard}")

enable_building_typelist_aliases_library("${mouseion_install_lib_directory}"
                                         "${mouseion_install_include_directory}"
                                         "${mouseion_install_bin_directory}"
                                         "${mouseion_cmake_c_compiler}"
                                         "${mouseion_cmake_cxx_compiler}"
                                         "${mouseion_cxx_standard}"
                                         "${mouseion_boost_top_level}" )

enable_building_generic_class_generation_library("${mouseion_install_lib_directory}"
                                                 "${mouseion_install_include_directory}"
                                                 "${mouseion_install_bin_directory}"
                                                 "${mouseion_cmake_c_compiler}"
                                                 "${mouseion_cmake_cxx_compiler}"
                                                 "${mouseion_cxx_standard}")

enable_building_primitives_library("${mouseion_install_lib_directory}"
                                    "${mouseion_install_include_directory}"
                                    "${mouseion_install_bin_directory}"
                                    "${mouseion_cmake_c_compiler}"
                                    "${mouseion_cmake_cxx_compiler}"
                                    "${mouseion_cxx_standard}")

#-----------------------------------------------------
# Add the subdirectory for creating the unit tests.
# 
#-----------------------------------------------------
add_subdirectory(generic_foreach_loop)
add_subdirectory(typelist_aliases)
add_subdirectory(generic_object_factory)
add_subdirectory(generic_class_generation)
add_subdirectory(primitives)

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
    #   typelist_aliases  target header files.           -
    #                                                    -
    # We get the path to the above header files.         -
    #-----------------------------------------------------
    get_target_property(mm_include_dir memory_management memory_management_include)
    get_target_property(my_typelist_aliases_include_dir typelist_aliases typelist_aliases_include)
    get_target_property(my_generic_class_generation_include_dir generic_class_generation generic_class_generation_include)


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
         header_files/ConcreteFactory.hpp
         header_files/OpNewFactoryUnit.hpp
         header_files/AbstractFactoryUnit.hpp
         header_files/AbstractFactory.hpp
         header_files/BaseVisitable.hpp
         header_files/BaseVisitor.h
         header_files/DefaultCatchAll.hpp
         header_files/DefineVisitableMacro.h
         header_files/ErrorUnknownVisitor.h
         header_files/Visitor.hpp
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
         implementation_files/ConcreteFactory.cpp
         implementation_files/OpNewFactoryUnit.cpp
         implementation_files/AbstractFactoryUnit.cpp
         implementation_files/AbstractFactory.cpp
         implementation_files/BaseVisitable.cpp
         implementation_files/BaseVisitor.cpp
         implementation_files/DefaultCatchAll.cpp
         implementation_files/DefineVisitableMacro.cpp
         implementation_files/ErrorUnknownVisitor.cpp
         implementation_files/Visitor.cpp
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
                           PRIVATE ${my_typelist_aliases_include_dir}
                           PRIVATE ${my_generic_class_generation_include_dir}
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
                       PUBLIC typelist_aliases
                       PUBLIC generic_class_generation
                       ${Boost_LIBRARIES} )

#-----------------------------------------------------
# Here we set the properties on target               -
#                                                    -
#-----------------------------------------------------
set_target_properties(${target} PROPERTIES
                      CXX_STANDARD ${mpl_cxx_standard}
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
