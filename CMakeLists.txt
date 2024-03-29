#-----------------------------------------------------
# Check that the cmake minimum version is            -
# satisfied.                                         -
#                                                    -
#-----------------------------------------------------
cmake_minimum_required(VERSION $ENV{MOUSEION_MINIMUM_CMAKE_VERSION})

#-----------------------------------------------------
# Define the project.                                -
#                                                    -
#-----------------------------------------------------
project(mouseion)

# This CMakeLists.txt file creates the library libmouseion.a
# and its unit tests. To add source files, simply append the appropiate variable
# mouseion_header_files or mouseion_implementation_files.
#
# The target for the library is mouseion.
#
# The following properties are set for the target mouseion.
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
    set(my_project_name "mouseion")
    project(${my_project_name})

    #-----------------------------------------------------
    # Define the target name.                            -
    #                                                    -
    #-----------------------------------------------------
    set(target ${my_project_name})

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


#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#                                                                 @
# End of defining the sources and header files associated         @
# with the mouseion targets.                                      @
#                                                                 @
#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

#-----------------------------------------------------
# Add the library associated with target             -
# mouseion.                                          -
#                                                    -
#-----------------------------------------------------

#-----------------------------------------------------
# Make available the project cmake modules.          -
#                                                    -
#-----------------------------------------------------
include( ${CMAKE_CURRENT_SOURCE_DIR}/cmake_macros_and_functions/mouseion_test_variable.cmake)
include( ${CMAKE_CURRENT_SOURCE_DIR}/cmake_macros_and_functions/mouseion_build_prerequisites.cmake )
include( ${CMAKE_CURRENT_SOURCE_DIR}/cmake_macros_and_functions/enable_mouseion_compile_warnings.cmake )
include( ${CMAKE_CURRENT_SOURCE_DIR}/cmake_macros_and_functions/enable_mouseion_debug_flags.cmake )
include( ${CMAKE_CURRENT_SOURCE_DIR}/cmake_macros_and_functions/mouseion_log_message.cmake )

#-----------------------------------------------------
# Check that key environmental variables are set.    -
#                                                    -
#-----------------------------------------------------
verify_mouseion_build_prerequisites_are_met()

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
set(mouseion_boost_top_level $ENV{MOUSEION_INSTALL_LIB_DIRECTORY})
set(mouseion_log_file $ENV{MOUSEION_LOG_FILE})
set(mouseion_debug_valid_values ${MOUSEION_DEBUG_VALID_VALUES}  )

#-----------------------------------------------------
# Call the macro that enables building of            -
# debugging_utilities target.                        -
#                                                    -
#-----------------------------------------------------
include( ${CMAKE_CURRENT_SOURCE_DIR}/sources/debugging_utilities/cmake_macros_and_functions/debugging_utilities.cmake)
enable_building_debugging_utilities_library( "${mouseion_install_lib_directory}"
                                             "${mouseion_install_include_directory}"
                                             "${mouseion_install_bin_directory}" 
                                             "${mouseion_cmake_c_compiler}"
                                             "${mouseion_cmake_cxx_compiler}"
                                             "${mouseion_cxx_standard}"
                                             "${mouseion_log_file}")
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/sources/debugging_utilities)

#-----------------------------------------------------
# Here we define variables which indicate where      -
# to install the counterclass libraries,             -
# header files, and associated binaries.             -
#                                                    -
#-----------------------------------------------------
set(counterclass_install_lib_directory ${mouseion_install_lib_directory})
set(counterclass_install_include_directory ${mouseion_install_include_directory})
set(counterclass_install_bin_directory ${mouseion_install_bin_directory})
set(counterclass_cxx_standard ${mouseion_cxx_standard})


#-----------------------------------------------------
# Call the macro that enables building of command    -
# line arguments target.                             -
#                                                    -
#-----------------------------------------------------
include( ${CMAKE_CURRENT_SOURCE_DIR}/sources/command_line_arguments/cmake_macros_and_functions/command_line_arguments.cmake)
enable_building_command_line_arguments_library( "${mouseion_install_lib_directory}"
                                                "${mouseion_install_include_directory}"
                                                "${mouseion_install_bin_directory}" 
                                                "${mouseion_cmake_c_compiler}" 
                                                "${mouseion_cmake_cxx_compiler}" 
                                                "${mouseion_cxx_standard}"
                                                "${mouseion_log_file}")

#-----------------------------------------------------
# Add the subdirectories for the various             -
# libraries.                                         -
#                                                    -
#-----------------------------------------------------

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/sources/counter_classes)

# ----------------------------------------------------
# This section builds target memory_management. 
# 
# ----------------------------------------------------
include( ${CMAKE_CURRENT_SOURCE_DIR}/sources/CPU_memory_management/cmake_macros_and_functions/memory_management.cmake)
enable_building_memory_management_library("${mouseion_install_lib_directory}" 
                                          "${mouseion_install_include_directory}"
                                          "${mouseion_install_bin_directory}"
                                          "${mouseion_cmake_c_compiler}" 
                                          "${mouseion_cmake_cxx_compiler}" 
                                          "${mouseion_cxx_standard}"
                                          "${mouseion_log_file}")
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/sources/CPU_memory_management)
# ----------------------------------------------------
# (End section)
# ----------------------------------------------------

# ----------------------------------------------------
# This section builds target string_utilities. 
# 
# ----------------------------------------------------
#-----------------------------------------------------
# Here we define variables which indicate where      -
# to install the string_utilities libraries,         -
# header files, and associated binaries.             -
#                                                    -
#-----------------------------------------------------
include( ${CMAKE_CURRENT_SOURCE_DIR}/sources/string_utilities/cmake_macros_and_functions/string_utilities.cmake)
enable_building_string_utilities_library("${mouseion_install_lib_directory}" 
                                          "${mouseion_install_include_directory}"
                                          "${mouseion_install_bin_directory}"
                                          "${mouseion_cmake_c_compiler}" 
                                          "${mouseion_cmake_cxx_compiler}" 
                                          "${mouseion_cxx_standard}"
                                          "${mouseion_log_file}")
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/sources/string_utilities)
# ----------------------------------------------------
# (End section)
# ----------------------------------------------------

# ----------------------------------------------------
# This section builds target communicator. 
# 
# ----------------------------------------------------
include( ${CMAKE_CURRENT_SOURCE_DIR}/sources/communicator/cmake_macros_and_functions/communicator.cmake)
enable_building_communicator_library("${mouseion_install_lib_directory}" 
                                     "${mouseion_install_include_directory}"
                                     "${mouseion_install_bin_directory}"
                                     "${mouseion_cmake_c_compiler}" 
                                     "${mouseion_cmake_cxx_compiler}" 
                                     "${mouseion_cxx_standard}"
                                     "${mouseion_log_file}")
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/sources/communicator)
# ----------------------------------------------------
# (End section)
# 
# ----------------------------------------------------

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/sources/meta_programming_library)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/sources/command_line_arguments)
