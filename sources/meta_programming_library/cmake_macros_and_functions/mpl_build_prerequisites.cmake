#-----------------------------------------------------
# This function verifies the key environmental       -
# variables are set.                                 -
#                                                    -
#                                                    -
#-----------------------------------------------------
function(verify_key_environmental_are_set)

    #-----------------------------------------------------
    # Verify environmental variable MPL_TOP_LEVEL is     -
    # defined.                                           -
    #-----------------------------------------------------
    if(DEFINED ENV{MPL_TOP_LEVEL})
        message("MPL_TOP_LEVEL=$ENV{MPL_TOP_LEVEL}")
    else()
        message( FATAL_ERROR "The environmental MPL_TOP_LEVEL is not defined. This \
        variable defines the top level directory of the mouseion package." )
    endif()

    #-----------------------------------------------------
    # Verify environmental variable                      -
    # MPL_CMAKE_CXX_COMPILER is defined.                 -
    #-----------------------------------------------------
    if (DEFINED ENV{MPL_CMAKE_CXX_COMPILER})
        message("MPL_CMAKE_CXX_COMPILER=$ENV{MPL_CMAKE_CXX_COMPILER}")
    else()
        message( FATAL_ERROR "The environmental MPL_CMAKE_CXX_COMPILER is not defined. This \
        variable defines the C++ compiler for compiling mouseion." )
    endif()

    #-----------------------------------------------------
    # Verify environmental variable                      -
    # MPL_CMAKE_C_COMPILER is defined.                   -
    #-----------------------------------------------------
    if (DEFINED ENV{MPL_CMAKE_C_COMPILER})
        message("MPL_CMAKE_C_COMPILER=$ENV{MPL_CMAKE_C_COMPILER}")
    else()
        message( FATAL_ERROR "The environmental MPL_CMAKE_C_COMPILER is not defined. This \
        variable defines the c compiler for compiling mouseion." )
    endif()

    #-----------------------------------------------------
    # Verify environmental variable                      -
    # MPL_INSTALL_PREFIX  is defined.                    -
    #                                                    -
    #-----------------------------------------------------
    if (DEFINED ENV{MPL_INSTALL_PREFIX})
        message("MPL_INSTALL_PREFIX=$ENV{MPL_INSTALL_PREFIX}")
    else()
        message( FATAL_ERROR "The environmental MPL_INSTALL_PREFIX is not defined. This \
        variable defines the root location to install mouseion." )
    endif()

    #-----------------------------------------------------
    # Verify environmental variable                      -
    # MPL_INSTALL_BIN_DIRECTORY is defined.              -
    #-----------------------------------------------------
    if (DEFINED ENV{MPL_INSTALL_BIN_DIRECTORY})
        message("MPL_INSTALL_BIN_DIRECTORY=$ENV{MPL_INSTALL_BIN_DIRECTORY}")
    else()
        message( FATAL_ERROR "The environmental MPL_INSTALL_BIN_DIRECTORY is not defined. This \
        variable defines the location to install mouseion binaries." )
    endif()

    #-----------------------------------------------------
    # Verify environmental variable                      -
    # MPL_INSTALL_INCLUDE_DIRECTORY is defined.          -
    #-----------------------------------------------------
    if ( DEFINED ENV{MPL_INSTALL_INCLUDE_DIRECTORY} )
        message("MPL_INSTALL_INCLUDE_DIRECTORY=$ENV{MPL_INSTALL_INCLUDE_DIRECTORY}")
    else()
        message( FATAL_ERROR "The environmental MPL_INSTALL_INCLUDE_DIRECTORY is not defined. This \
        variable defines the location to install mouseion header files." )
    endif()

    #-----------------------------------------------------
    # Verify environmental variable                      -
    # MPL_INSTALL_LIB_DIRECTORY is defined.              -
    #-----------------------------------------------------
    if ( DEFINED ENV{MPL_INSTALL_LIB_DIRECTORY} )
        message("MPL_INSTALL_LIB_DIRECTORY=$ENV{MPL_INSTALL_LIB_DIRECTORY}")
    else()
        message( FATAL_ERROR "The environmental MPL_INSTALL_LIB_DIRECTORY is not defined. This \
        variable defines the location to install mouseion libraries." )
    endif()

    #-----------------------------------------------------
    # Verify environment variable                        -
    # MPL_BOOST_TOP_LEVEL is defined.                    -
    #-----------------------------------------------------
    if( DEFINED ENV{MPL_BOOST_TOP_LEVEL})
        message("MPL_BOOST_TOP_LEVEL=$ENV{MPL_BOOST_TOP_LEVEL}")
    else()
        message( FATAL_ERROR "The environmental MPL_BOOST_TOP_LEVEL is not defined. This \
        variable defines the location to BOOST top level." )
    endif()

endfunction()
