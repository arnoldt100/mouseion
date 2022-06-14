#-----------------------------------------------------
# This function verifies the                         -
# variables are set.                                 -
#                                                    -
#                                                    -
#-----------------------------------------------------
function(verify_typelist_aliases_build_prerequisites)

    #-----------------------------------------------------
    # Verify environmental variable
    # typelist_aliases_cxx_standard is defined.
    #-----------------------------------------------------
    if (DEFINED typelist_aliases_cxx_standard)
        message("typelist_aliases_minimum_cmake_version=${typelist_aliases_cxx_standard}")
    else()
        message( FATAL_ERROR "The variable typelist_aliases_cxx_standard is not defined. This \
        variable defines the cxx standard for compiling typelist_aliases." )
    endif()

    #-----------------------------------------------------
    # Verify environmental variable
    # typelist_aliases_cmake_cxx_compiler is defined.
    #-----------------------------------------------------
    if (DEFINED typelist_aliases_cmake_cxx_compiler)
        message("typelist_aliases_cmake_cxx_compiler=${typelist_aliases_cmake_cxx_compiler}")
    else()
        message( FATAL_ERROR "The variable typelist_aliases_cmake_cxx_compiler is not defined. This \
        variable defines the C++ compiler for compiling typelist_aliases." )
    endif()

    #-----------------------------------------------------
    # Verify environmental variable
    # typelist_aliases_cmake_c_compiler is defined.
    #-----------------------------------------------------
    if (DEFINED typelist_aliases_cmake_c_compiler)
        message("typelist_aliases_cmake_c_compiler=${typelist_aliases_cmake_c_compiler}")
    else()
        message( FATAL_ERROR "The variable typelist_aliases_cmake_c_compiler is not defined. This \
        variable defines the c compiler for compiling typelist_aliases." )
    endif()

    #-----------------------------------------------------
    # Verify environmental variable
    # typelist_aliases_install_bin_directory is defined.
    #-----------------------------------------------------
    if (DEFINED typelist_aliases_install_bin_directory)
        message("typelist_aliases_install_bin_directory=${typelist_aliases_install_bin_directory}")
    else()
        message( FATAL_ERROR "The variable typelist_aliases_install_bin_directory is not defined. This \
        variable defines the location to install typelist_aliases binaries." )
    endif()

    #-----------------------------------------------------
    # Verify environmental variable
    # typelist_aliases_install_include_directory is 
    # defined.
    #-----------------------------------------------------
    if ( DEFINED typelist_aliases_install_include_directory )
        message("typelist_aliases_install_include_directory=${typelist_aliases_install_include_directory}")
    else()
        message( FATAL_ERROR "The variable typelist_aliases_install_include_directory is not defined. This \
        variable defines the location to install typelist_aliases header files." )
    endif()

    #-----------------------------------------------------
    # Verify environmental variable
    # typelist_aliases_install_lib_directory is defined.
    #-----------------------------------------------------
    if ( DEFINED typelist_aliases_install_lib_directory )
        message("typelist_aliases_install_lib_directory=${typelist_aliases_install_lib_directory}")
    else()
        message( FATAL_ERROR "The variable typelist_aliases_install_lib_directory is not defined. This \
        variable defines the location to install typelist_aliases libraries." )
    endif()

    #-----------------------------------------------------
    # Verify environment variable
    # typelist_aliases_boost_top_level is defined.
    #-----------------------------------------------------
    if( DEFINED typelist_aliases_boost_top_level)
        message("typelist_aliases_boost_top_level=${typelist_aliases_boost_top_level}")
    else()
        message( FATAL_ERROR "The variable typelist_aliases_boost_top_level is not defined. This \
        variable defines the location to BOOST top level." )
    endif()

endfunction()
