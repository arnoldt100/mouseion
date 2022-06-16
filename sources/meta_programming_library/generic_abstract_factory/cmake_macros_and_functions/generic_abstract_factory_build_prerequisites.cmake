#-----------------------------------------------------
# This function verifies the key                     -
# variables are set.                                 -
#                                                    -
#                                                    -
#-----------------------------------------------------
function(verify_generic_abstract_factory_build_prerequisites_are_set)


    #-----------------------------------------------------
    # Verify environmental variable                      -
    # generic_abstract_factory_cmake_cxx_compiler is     -
    # defined.                                           -
    #-----------------------------------------------------
    if (DEFINED generic_abstract_factory_cmake_cxx_compiler)
        message("generic_abstract_factory_cmake_cxx_compiler=${generic_abstract_factory_cmake_cxx_compiler}")
    else()
        message( FATAL_ERROR "The variable generic_abstract_factory_cmake_cxx_compiler is not defined. This \
        variable defines the C++ compiler for compiling the generic_abstract_factory library." )
    endif()

    #-----------------------------------------------------
    # Verify environmental variable                      -
    # generic_abstract_factory_cmake_c_compiler is       -
    # defined.                                           -
    #-----------------------------------------------------
    if (DEFINED generic_abstract_factory_cmake_c_compiler)
        message("generic_abstract_factory_cmake_c_compiler=${generic_abstract_factory_cmake_c_compiler}")
    else()
        message( FATAL_ERROR "The variable generic_abstract_factory_cmake_c_compiler is not defined. This \
        variable defines the c compiler for compiling generic_abstract_factory library." )
    endif()

    #-----------------------------------------------------
    # Verify environmental variable                      -
    # generic_abstract_factory_install_bin_directory is  -
    # defined.                                           -
    #-----------------------------------------------------
    if (DEFINED generic_abstract_factory_install_bin_directory)
        message("generic_abstract_factory_install_bin_directory=${generic_abstract_factory_install_bin_directory}")
    else()
        message( FATAL_ERROR "The variable generic_abstract_factory_install_bin_directory is not defined. This \
        variable defines the location to install generic_abstract_factory binaries." )
    endif()

    #-----------------------------------------------------
    # Verify environmental variable                      -
    # generic_abstract_factory_install_include_directory -
    # is defined.                                        -
    #-----------------------------------------------------
    if ( DEFINED generic_abstract_factory_install_include_directory )
        message("generic_abstract_factory_install_include_directory=${generic_abstract_factory_install_include_directory}")
    else()
        message( FATAL_ERROR "The variable generic_abstract_factory_install_include_directory is not defined. This \
        variable defines the location to install generic_abstract_factory header files." )
    endif()

    #-----------------------------------------------------
    # Verify environmental variable                      -
    # generic_abstract_factory_install_lib_directory is  -
    # defined.                                           -
    #-----------------------------------------------------
    if ( DEFINED generic_abstract_factory_install_lib_directory )
        message("generic_abstract_factory_install_lib_directory=${generic_abstract_factory_install_lib_directory}")
    else()
        message( FATAL_ERROR "The variable generic_abstract_factory_install_lib_directory is not defined. This \
        variable defines the location to install generic_abstract_factory libraries." )
    endif()

endfunction()
