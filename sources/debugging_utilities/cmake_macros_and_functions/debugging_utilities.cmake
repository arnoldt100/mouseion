# =====================================================================================
# 
#        Filename:  debugging_utilities.cmake
# 
#     Description:  
# 
#          Author:  Arnold N. Tharrington (), arnoldt@ornl.gov
#    Organization:  ORNL-National Center of Computational Sciences
# 
#  =====================================================================================


# ===  MACRO     ======================================================================
#         Name:  enable_building_debugging_utilities_library
#  Description:  Defines key environmental variables enabling the
#                building of the debugging utilities library.
# 
#  Arguments: 
#             install_lib_directory - The location to install the actual library
#             install_include_directory - The location to install header files
#             install_bin_directory - The location to install binaraies
#             cxx_standard - The C++ standard to build the library and binaries
#             logfilepath - The path to the logging file
# =====================================================================================
macro ( enable_building_debugging_utilities_library install_lib_directory
        install_include_directory
        install_bin_directory 
        cmake_c_compiler 
        cmake_cxx_compiler 
        cxx_standard
        logfilepath)

    set(debugging_utilities_install_lib_directory "${install_lib_directory}")
    set(debugging_utilities_install_include_directory "${install_include_directory}")
    set(debugging_utilities_install_bin_directory "${install_bin_directory}" )
    set(debugging_utilities_cmake_c_compiler "${cmake_c_compiler}")
    set(debugging_utilities_cmake_cxx_compiler "${cmake_cxx_compiler}")
    set(debugging_utilities_cxx_standard "${cxx_standard}" )
    set(debugging_utilities_logfilepath "${logfilepath}")
endmacro()
