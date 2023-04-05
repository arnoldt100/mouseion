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

#-----------------------------------------------------
# Add the subdirectory for creating the unit tests.
# 
#-----------------------------------------------------

# ----------------------------------------------------
# This sectian builds the target primitives.
# 
# ----------------------------------------------------
include( ${CMAKE_CURRENT_LIST_DIR}/primitives/cmake_macros_and_functions/primitives.cmake)
enable_building_primitives_library("${mouseion_install_lib_directory}"
                                    "${mouseion_install_include_directory}"
                                    "${mouseion_install_bin_directory}"
                                    "${mouseion_cmake_c_compiler}"
                                    "${mouseion_cmake_cxx_compiler}"
                                    "${mouseion_cxx_standard}"
                                    "${mouseion_log_file}")
add_subdirectory(primitives)

# ----------------------------------------------------
# (End of section)
# ----------------------------------------------------

# ----------------------------------------------------
# This sectian builds the target typelist_aliases.
# 
# ----------------------------------------------------
include( ${CMAKE_CURRENT_LIST_DIR}/typelist_aliases/cmake_macros_and_functions/typelist_aliases.cmake)
enable_building_typelist_aliases_library("${mouseion_install_lib_directory}"
                                         "${mouseion_install_include_directory}"
                                         "${mouseion_install_bin_directory}"
                                         "${mouseion_cmake_c_compiler}"
                                         "${mouseion_cmake_cxx_compiler}"
                                         "${mouseion_cxx_standard}"
                                         "${mouseion_boost_top_level}"
                                         "${mouseion_log_file}")
add_subdirectory(typelist_aliases)
# ----------------------------------------------------
# (end section) 
# ----------------------------------------------------

# ----------------------------------------------------
# This sectian builds the target typelist_aliases.
# 
# ----------------------------------------------------
include( ${CMAKE_CURRENT_LIST_DIR}/generic_foreach_loop/cmake_macros_and_functions/generic_foreach_loop.cmake)
enable_building_generic_foreach_loop_library("${mouseion_install_lib_directory}"
                                             "${mouseion_install_include_directory}"
                                             "${mouseion_install_bin_directory}"
                                             "${mouseion_cmake_c_compiler}"
                                             "${mouseion_cmake_cxx_compiler}"
                                             "${mouseion_cxx_standard}"
                                             "${mouseion_log_file}")
add_subdirectory(generic_foreach_loop)
# ----------------------------------------------------
# (end section) 
# ----------------------------------------------------

# ----------------------------------------------------
# This sectian builds the target generic_visitor target
# 
# ----------------------------------------------------
include( ${CMAKE_CURRENT_LIST_DIR}/generic_visitor/cmake_macros_and_functions/generic_visitor.cmake)
enable_building_generic_visitor_library("${mouseion_install_lib_directory}"
                                        "${mouseion_install_include_directory}"
                                        "${mouseion_install_bin_directory}"
                                        "${mouseion_cmake_c_compiler}"
                                        "${mouseion_cmake_cxx_compiler}"
                                        "${mouseion_cxx_standard}"
                                        "${mouseion_log_file}")

add_subdirectory(generic_visitor)
# ----------------------------------------------------
# (end section) 
# ----------------------------------------------------

# ----------------------------------------------------
# This sectian builds the target generic_object_factory
# 
# ----------------------------------------------------
include( ${CMAKE_CURRENT_LIST_DIR}/generic_object_factory/cmake_macros_and_functions/generic_object_factory.cmake)
enable_building_generic_object_factory_library("${mouseion_install_lib_directory}"
                                        "${mouseion_install_include_directory}"
                                        "${mouseion_install_bin_directory}"
                                        "${mouseion_cmake_c_compiler}"
                                        "${mouseion_cmake_cxx_compiler}"
                                        "${mouseion_cxx_standard}"
                                        "${mouseion_log_file}")

add_subdirectory(generic_object_factory)
# ----------------------------------------------------
# (end section) 
# ----------------------------------------------------

# ----------------------------------------------------
# This sectian builds the target generic_class_generation.
# 
# ----------------------------------------------------

include( ${CMAKE_CURRENT_LIST_DIR}/generic_class_generation/cmake_macros_and_functions/generic_class_generation.cmake)
enable_building_generic_class_generation_library ("${mouseion_install_lib_directory}"
                                                 "${mouseion_install_include_directory}"
                                                 "${mouseion_install_bin_directory}"
                                                 "${mouseion_cmake_c_compiler}"
                                                 "${mouseion_cmake_cxx_compiler}"
                                                 "${mouseion_cxx_standard}"
                                                 "${mouseion_log_file}")
add_subdirectory(generic_class_generation)

# ----------------------------------------------------
# (End section) 
# ----------------------------------------------------

# ----------------------------------------------------
# This sectian builds the target generic_abstract_factory
# 
# ----------------------------------------------------
include( ${CMAKE_CURRENT_LIST_DIR}/generic_abstract_factory/cmake_macros_and_functions/generic_abstract_factory.cmake)
enable_building_generic_abstract_factory_library("${mouseion_install_lib_directory}"
                                                 "${mouseion_install_include_directory}"
                                                 "${mouseion_install_bin_directory}"
                                                 "${mouseion_cmake_c_compiler}"
                                                 "${mouseion_cmake_cxx_compiler}"
                                                 "${mouseion_cxx_standard}"
                                                 "${mouseion_log_file}")
add_subdirectory(generic_abstract_factory)
# ----------------------------------------------------
# (End section) 
# ----------------------------------------------------



    
