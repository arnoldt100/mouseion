# =====================================================================================
# 
#        Filename:  mpl_library.cmake
# 
#     Description:  
# 
#          Author:  Arnold N. Tharrington (), arnoldt@ornl.gov
#    Organization:  ORNL-National Center of Computational Sciences
# 
#  =====================================================================================


# ===  MACRO     ======================================================================
#         Name:  enable_building_mpl
#  Description:  Defines key environmental variables enabalng the
#                building of the mpl library.
# 
#  Arguments: top_level - The top level of the main CmakeLists.txt file.
#             minimum_cmake_version - The minumum cmake version for building mpl
#             cmake_c_compiler - The C compiler for building c sources
#             cmake_cxx_compiler - The C++ compiler for building C++ sources
#             install_prefix - The root location to install the library.
#             install_bin_directory - The location to install binaraies
#             install_include_directory - The location to install header files
#             install_lib_directory - The location to install the actual library
#             mpl_top_level - The top level of the mpl package
#             boost_top_level - The top level of the boost package
# =====================================================================================
macro (enable_building_mpl minimum_cmake_version
       cxx_standard
       cmake_c_compiler 
       cmake_cxx_compiler
       install_prefix
       install_bin_directory
       install_include_directory
       install_lib_directory
       mpl_top_level
       boost_top_level)

    set(ENV{MPL_MINIMUM_CMAKE_VERSION} ${minimum_cmake_version}) 
    set(ENV{MPL_CXX_STANDARD} ${cxx_standard})
    set(ENV{MPL_CMAKE_C_COMPILER} ${cmake_c_compiler})
    set(ENV{MPL_CMAKE_CXX_COMPILER} ${cmake_cxx_compiler})
    set(ENV{MPL_INSTALL_PREFIX} ${install_prefix})
    set(ENV{MPL_INSTALL_BIN_DIRECTORY} ${install_bin_directory}) 
    set(ENV{MPL_INSTALL_INCLUDE_DIRECTORY} ${install_include_directory})
    set(ENV{MPL_INSTALL_LIB_DIRECTORY} ${install_lib_directory})
    set(ENV{MPL_LOG_FILE} "mpl_log.txt")
    set(ENV{MPL_TOP_LEVEL} ${mpl_top_level})
    set(ENV{MPL_BOOST_TOP_LEVEL} ${boost_top_level})
endmacro()
