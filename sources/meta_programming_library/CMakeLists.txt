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
include( ${CMAKE_CURRENT_LIST_DIR}/primitives/cmake_macros_and_functions/primitives.cmake)
include( ${CMAKE_CURRENT_LIST_DIR}/generic_visitor/cmake_macros_and_functions/generic_visitor.cmake)

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

enable_building_generic_visitor_library("${mouseion_install_lib_directory}"
                                        "${mouseion_install_include_directory}"
                                        "${mouseion_install_bin_directory}"
                                        "${mouseion_cmake_c_compiler}"
                                        "${mouseion_cmake_cxx_compiler}"
                                        "${mouseion_cxx_standard}")

enable_building_generic_abstract_factory_library("${mouseion_install_lib_directory}"
                                                 "${mouseion_install_include_directory}"
                                                 "${mouseion_install_bin_directory}"
                                                 "${mouseion_cmake_c_compiler}"
                                                 "${mouseion_cmake_cxx_compiler}"
                                                 "${mouseion_cxx_standard}")

#-----------------------------------------------------
# Add the subdirectory for creating the unit tests.
# 
#-----------------------------------------------------
add_subdirectory(primitives)
add_subdirectory(typelist_aliases)
add_subdirectory(generic_foreach_loop)
add_subdirectory(generic_visitor)
add_subdirectory(generic_object_factory)
add_subdirectory(generic_class_generation)
add_subdirectory(generic_abstract_factory)



    
