#-----------------------------------------------------
# This function verifies the key environmental       -
# variables are set.                                 -
#                                                    -
#                                                    -
#-----------------------------------------------------
function(verify_primitives_build_prerequisites_are_set)

    #-----------------------------------------------------
    # Verify environmental variable                      -
    # primitives_cmake_cxx_compiler is         -
    # defined.                                           -
    #-----------------------------------------------------
    if (DEFINED primitives_cmake_cxx_compiler)
        message("primitives_cmake_cxx_compiler=${primitives_cmake_cxx_compiler}")
    else()
        message( FATAL_ERROR "The variable primitives_cmake_cxx_compiler is not defined. This \
        variable defines the C++ compiler for compiling the primitives library." )
    endif()

    #-----------------------------------------------------
    # Verify environmental variable                      -
    # primitives_cmake_c_compiler is defined.  -
    #-----------------------------------------------------
    if (DEFINED primitives_cmake_c_compiler)
        message("primitives_cmake_c_compiler=${primitives_cmake_c_compiler}")
    else()
        message( FATAL_ERROR "The variable primitives_cmake_c_compiler is not defined. This \
        variable defines the c compiler for compiling primitives library." )
    endif()

    #-----------------------------------------------------
    # Verify environmental variable                      -
    # primitives_install_bin_directory is      -
    # defined.                                           -
    #-----------------------------------------------------
    if (DEFINED primitives_install_bin_directory)
        message("primitives_install_bin_directory=${primitives_install_bin_directory}")
    else()
        message( FATAL_ERROR "The variable primitives_install_bin_directory is not defined. This \
        variable defines the location to install primitives binaries." )
    endif()

    #-----------------------------------------------------
    # Verify environmental variable                      -
    # primitives_install_include_directory is  -
    # defined.                                           -
    #-----------------------------------------------------
    if ( DEFINED primitives_install_include_directory )
        message("primitives_install_include_directory=${primitives_install_include_directory}")
    else()
        message( FATAL_ERROR "The variable primitives_install_include_directory is not defined. This \
        variable defines the location to install primitives header files." )
    endif()

    #-----------------------------------------------------
    # Verify environmental variable                      -
    # primitives_install_lib_directory is      -
    # defined.                                           -
    #-----------------------------------------------------
    if ( DEFINED primitives_install_lib_directory )
        message("primitives_install_lib_directory=${primitives_install_lib_directory}")
    else()
        message( FATAL_ERROR "The variable primitives_install_lib_directory is not defined. This \
        variable defines the location to install primitives libraries." )
    endif()

endfunction()
