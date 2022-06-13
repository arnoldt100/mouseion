#-----------------------------------------------------
# This function verifies the key environmental       -
# variables are set.                                 -
#                                                    -
#                                                    -
#-----------------------------------------------------
function(verify_key_environmental_are_set)


    #-----------------------------------------------------
    # Verify environmental variable                      -
    # generic_foreach_loop_cmake_cxx_compiler is         -
    # defined.                                           -
    #-----------------------------------------------------
    if (DEFINED generic_foreach_loop_cmake_cxx_compiler)
        message("generic_foreach_loop_cmake_cxx_compiler=${generic_foreach_loop_cmake_cxx_compiler}")
    else()
        message( FATAL_ERROR "The variable generic_foreach_loop_cmake_cxx_compiler is not defined. This \
        variable defines the C++ compiler for compiling the generic_foreach_loop library." )
    endif()

    #-----------------------------------------------------
    # Verify environmental variable                      -
    # generic_foreach_loop_cmake_c_compiler is defined.  -
    #-----------------------------------------------------
    if (DEFINED generic_foreach_loop_cmake_c_compiler)
        message("generic_foreach_loop_cmake_c_compiler=${generic_foreach_loop_cmake_c_compiler}")
    else()
        message( FATAL_ERROR "The variable generic_foreach_loop_cmake_c_compiler is not defined. This \
        variable defines the c compiler for compiling generic_foreach_loop library." )
    endif()

    #-----------------------------------------------------
    # Verify environmental variable                      -
    # generic_foreach_loop_install_bin_directory is      -
    # defined.                                           -
    #-----------------------------------------------------
    if (DEFINED generic_foreach_loop_install_bin_directory)
        message("generic_foreach_loop_install_bin_directory=${generic_foreach_loop_install_bin_directory}")
    else()
        message( FATAL_ERROR "The variable generic_foreach_loop_install_bin_directory is not defined. This \
        variable defines the location to install generic_foreach_loop binaries." )
    endif()

    #-----------------------------------------------------
    # Verify environmental variable                      -
    # generic_foreach_loop_install_include_directory is  -
    # defined.                                           -
    #-----------------------------------------------------
    if ( DEFINED generic_foreach_loop_install_include_directory )
        message("generic_foreach_loop_install_include_directory=${generic_foreach_loop_install_include_directory}")
    else()
        message( FATAL_ERROR "The variable generic_foreach_loop_install_include_directory is not defined. This \
        variable defines the location to install generic_foreach_loop header files." )
    endif()

    #-----------------------------------------------------
    # Verify environmental variable                      -
    # generic_foreach_loop_install_lib_directory is      -
    # defined.                                           -
    #-----------------------------------------------------
    if ( DEFINED generic_foreach_loop_install_lib_directory )
        message("generic_foreach_loop_install_lib_directory=${generic_foreach_loop_install_lib_directory}")
    else()
        message( FATAL_ERROR "The variable generic_foreach_loop_install_lib_directory is not defined. This \
        variable defines the location to install generic_foreach_loop libraries." )
    endif()

endfunction()
