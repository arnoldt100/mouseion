# =====================================================================================
# 
#        Filename:  generic_abstract_factory.cmake
# 
#     Description:  
# 
#          Author:  Arnold N. Tharrington (), arnoldt@ornl.gov
#    Organization:  ORNL-National Center of Computational Sciences
# 
#  =====================================================================================


# ===  MACRO     ======================================================================
#         Name:  enable_building_generic_abstract_factory_library
#  Description:  Defines key variables enabling the
#                building of the generic_abstract_factory library.
# 
#  Arguments: 
#             install_lib_directory - The location to install the actual library
#             install_include_directory - The location to install header files
#             install_bin_directory - The location to install binaraies
#             cmake_c_compiler - The c compiler to build the library
#             cmake_cxx_compiler - The c++ compiler to build the library
#             cxx_standard - The C++ standard to build the library and binaries
# =====================================================================================
macro ( enable_building_generic_abstract_factory_library install_lib_directory
        install_include_directory
        install_bin_directory
        cmake_c_compiler 
        cmake_cxx_compiler 
        cxx_standard)

    set(generic_abstract_factory_install_lib_directory ${install_lib_directory})
    set(generic_abstract_factory_install_include_directory ${install_include_directory})
    set(generic_abstract_factory_install_bin_directory ${install_bin_directory})
    set(generic_abstract_factory_cmake_cxx_compiler ${cmake_cxx_compiler})
    set(generic_abstract_factory_cmake_c_compiler ${cmake_c_compiler})
    set(generic_abstract_factory_cxx_standard ${cxx_standard})
endmacro()

