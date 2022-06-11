#-----------------------------------------------------
# This function verifies the key environmental       -
# variables are set.                                 -
#                                                    -
#                                                    -
#-----------------------------------------------------
function(verify_key_environmental_are_set)


    #-----------------------------------------------------
    # Verify environmental variable                      -
    # foreach_loop_cmake_cxx_compiler is defined.        -
    #-----------------------------------------------------
    if (DEFINED foreach_loop_cmake_cxx_compiler)
        message("foreach_loop_cmake_cxx_compiler=${foreach_loop_cmake_cxx_compiler}")
    else()
        message( FATAL_ERROR "The variable foreach_loop_cmake_cxx_compiler is not defined. This \
        variable defines the C++ compiler for compiling the foreach_loop library." )
    endif()

    #-----------------------------------------------------
    # Verify environmental variable                      -
    # foreach_loop_cmake_c_compiler is defined.          -
    #-----------------------------------------------------
    if (DEFINED foreach_loop_cmake_c_compiler)
        message("foreach_loop_cmake_c_compiler=${foreach_loop_cmake_c_compiler}")
    else()
        message( FATAL_ERROR "The variable foreach_loop_cmake_c_compiler is not defined. This \
        variable defines the c compiler for compiling foreach_loop library." )
    endif()

    #-----------------------------------------------------
    # Verify environmental variable                      -
    # foreach_loop_install_bin_directory is defined.     -
    #-----------------------------------------------------
    if (DEFINED foreach_loop_install_bin_directory)
        message("foreach_loop_install_bin_directory=${foreach_loop_install_bin_directory}")
    else()
        message( FATAL_ERROR "The variable foreach_loop_install_bin_directory is not defined. This \
        variable defines the location to install foreach_loop binaries." )
    endif()

    #-----------------------------------------------------
    # Verify environmental variable                      -
    # foreach_loop_install_include_directory is defined. -
    #-----------------------------------------------------
    if ( DEFINED foreach_loop_install_include_directory )
        message("foreach_loop_install_include_directory=${foreach_loop_install_include_directory}")
    else()
        message( FATAL_ERROR "The variable foreach_loop_install_include_directory is not defined. This \
        variable defines the location to install foreach_loop header files." )
    endif()

    #-----------------------------------------------------
    # Verify environmental variable                      -
    # foreach_loop_install_lib_directory is defined.     -
    #-----------------------------------------------------
    if ( DEFINED foreach_loop_install_lib_directory )
        message("foreach_loop_install_lib_directory=${foreach_loop_install_lib_directory}")
    else()
        message( FATAL_ERROR "The variable foreach_loop_install_lib_directory is not defined. This \
        variable defines the location to install foreach_loop libraries." )
    endif()

    #-----------------------------------------------------
    # Verify environment variable                        -
    # foreach_loop_boost_top_level is defined.           -
    #-----------------------------------------------------
    if( DEFINED ENV{foreach_loop_boost_top_level})
        message("foreach_loop_boost_top_level=${foreach_loop_boost_top_level}")
    else()
        message( FATAL_ERROR "The variable foreach_loop_boost_top_level is not defined. This \
        variable defines the location to BOOST top level." )
    endif()

endfunction()
