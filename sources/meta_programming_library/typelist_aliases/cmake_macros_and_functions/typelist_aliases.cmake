# =====================================================================================
# 
#        Filename:  typelist_aliases.cmake
# 
#     Description:  
# 
#          Author:  Arnold N. Tharrington (), arnoldt@ornl.gov
#    Organization:  ORNL-National Center of Computational Sciences
# 
#  =====================================================================================


# ===  MACRO     ======================================================================
#         Name:  enable_building_typelist_aliases_library
#  Description:  Defines key variables enabling the
#                building of the typelist_aliases library.
# 
#  Arguments: top_level - The top level of the main CmakeLists.txt file.
#             minimum_cmake_version - The minumum cmake version for building typelist_aliases
#             cmake_c_compiler - The C compiler for building c sources
#             cmake_cxx_compiler - The C++ compiler for building C++ sources
#             install_prefix - The root location to install the library.
#             install_bin_directory - The location to install binaries
#             install_include_directory - The location to install header files
#             install_lib_directory - The location to install the actual library
#             boost_top_level - The top level of the boost package
# =====================================================================================
macro (enable_building_typelist_aliases_library 
       install_lib_directory
       install_include_directory
       install_bin_directory
       cmake_c_compiler 
       cmake_cxx_compiler
       cxx_standard
       boost_top_level)

    set(typelist_aliases_minimum_cmake_version ${minimum_cmake_version}) 
    set(typelist_aliases_cxx_standard ${cxx_standard})
    set(typelist_aliases_cmake_c_compiler ${cmake_c_compiler})
    set(typelist_aliases_cmake_cxx_compiler ${cmake_cxx_compiler})
    set(typelist_aliases_install_bin_directory ${install_bin_directory}) 
    set(typelist_aliases_install_include_directory ${install_include_directory})
    set(typelist_aliases_install_lib_directory ${install_lib_directory})
    set(typelist_aliases_boost_top_level ${boost_top_level})
endmacro()
