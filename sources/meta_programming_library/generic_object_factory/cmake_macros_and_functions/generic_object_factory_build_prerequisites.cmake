#-----------------------------------------------------
# This function verifies the key environmental
# variables are set for the target generic_object_factory.
#
#-----------------------------------------------------
function(verify_generic_object_factory_build_prerequisites_are_set)

    #-----------------------------------------------------
    # Verify environmental variable 
    # generic_object_factory_install_bin_directory is 
    # defined.
    #-----------------------------------------------------
    if (DEFINED generic_object_factory_install_bin_directory)
        message("generic_object_factory_install_bin_directory=${generic_object_factory_install_bin_directory}")
    else()
        message( FATAL_ERROR "The environmental generic_object_factory_install_bin_directory is not defined. This \
        variable defines the location to install generic_object_factory binaries." )
    endif()

    #-----------------------------------------------------
    # Verify environmental variable
    # generic_object_factory_install_include_directory is
    # defined.
    #-----------------------------------------------------
    if ( DEFINED ENV{generic_object_factory_install_include_directory} )
        message("generic_object_factory_install_include_directory=$ENV{generic_object_factory_install_include_directory}")
    else()
        message( FATAL_ERROR "The environmental generic_object_factory_install_include_directory is not defined. This \
        variable defines the location to install mouseion header files." )
    endif()

    #-----------------------------------------------------
    # Verify environmental variable
    # generic_object_factory_install_lib_directory is 
    # defined.
    #-----------------------------------------------------
    if ( DEFINED ENV{generic_object_factory_install_lib_directory} )
        message("generic_object_factory_install_lib_directory=$ENV{generic_object_factory_install_lib_directory}")
    else()
        message( FATAL_ERROR "The environmental generic_object_factory_install_lib_directory is not defined. This \
        variable defines the location to install mouseion libraries." )
    endif()

endfunction()
