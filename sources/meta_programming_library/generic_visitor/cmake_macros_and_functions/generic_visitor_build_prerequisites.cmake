#-----------------------------------------------------
# This function verifies the key                     -
# variables are set.                                 -
#                                                    -
#-----------------------------------------------------
function(verify_generic_visitor_build_prerequisites_are_set)

    #-----------------------------------------------------
    # Verify environmental variable                      -
    # generic_visitor_cmake_cxx_compiler is              -
    # defined.                                           -
    #-----------------------------------------------------
    if (DEFINED generic_visitor_cmake_cxx_compiler)
        message("generic_visitor_cmake_cxx_compiler=${generic_visitor_cmake_cxx_compiler}")
    else()
        message( FATAL_ERROR "The variable generic_visitor_cmake_cxx_compiler is not defined. This \
        variable defines the C++ compiler for compiling the generic_visitor library." )
    endif()

    #-----------------------------------------------------
    # Verify environmental variable                      -
    # generic_visitor_cmake_c_compiler is defined.       -
    #-----------------------------------------------------
    if (DEFINED generic_visitor_cmake_c_compiler)
        message("generic_visitor_cmake_c_compiler=${generic_visitor_cmake_c_compiler}")
    else()
        message( FATAL_ERROR "The variable generic_visitor_cmake_c_compiler is not defined. This \
        variable defines the c compiler for compiling generic_visitor library." )
    endif()

    #-----------------------------------------------------
    # Verify environmental variable                      -
    # generic_visitor_install_bin_directory is           -
    # defined.                                           -
    #-----------------------------------------------------
    if (DEFINED generic_visitor_install_bin_directory)
        message("generic_visitor_install_bin_directory=${generic_visitor_install_bin_directory}")
    else()
        message( FATAL_ERROR "The variable generic_visitor_install_bin_directory is not defined. This \
        variable defines the location to install generic_visitor binaries." )
    endif()

    #-----------------------------------------------------
    # Verify environmental variable                      -
    # generic_visitor_install_include_directory is       -
    # defined.                                           -
    #-----------------------------------------------------
    if ( DEFINED generic_visitor_install_include_directory )
        message("generic_visitor_install_include_directory=${generic_visitor_install_include_directory}")
    else()
        message( FATAL_ERROR "The variable generic_visitor_install_include_directory is not defined. This \
        variable defines the location to install generic_visitor header files." )
    endif()

    #-----------------------------------------------------
    # Verify environmental variable                      -
    # generic_visitor_install_lib_directory is           -
    # defined.                                           -
    #-----------------------------------------------------
    if ( DEFINED generic_visitor_install_lib_directory )
        message("generic_visitor_install_lib_directory=${generic_visitor_install_lib_directory}")
    else()
        message( FATAL_ERROR "The variable generic_visitor_install_lib_directory is not defined. This \
        variable defines the location to install generic_visitor libraries." )
    endif()

endfunction()

