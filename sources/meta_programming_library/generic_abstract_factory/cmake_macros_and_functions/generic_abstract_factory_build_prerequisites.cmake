#-----------------------------------------------------
# This function verifies the key                     -
# variables are set.                                 -
#                                                    -
#                                                    -
#-----------------------------------------------------
function(verify_generic_abstract_factory_build_prerequisites_are_set)

    #-----------------------------------------------------
    # Verify variable                                    -
    # generic_abstract_factory_logfilepath is            -
    # defined.                                           -
    #-----------------------------------------------------
    if (NOT DEFINED generic_abstract_factory_logfilepath)
        message(FATAL_ERROR "generic_abstract_factory_logfilepath is not defined" )
    endif()

    #-----------------------------------------------------
    # Verify environmental variable                      -
    # generic_abstract_factory_cmake_cxx_compiler is     -
    # defined.                                           -
    #-----------------------------------------------------
    mouseion_test_variable_is_defined("generic_abstract_factory_cmake_cxx_compiler" "${generic_abstract_factory_logfilepath}" )

    #-----------------------------------------------------
    # Verify environmental variable                      -
    # generic_abstract_factory_cmake_c_compiler is       -
    # defined.                                           -
    #-----------------------------------------------------
    mouseion_test_variable_is_defined("generic_abstract_factory_cmake_c_compiler" "${generic_abstract_factory_logfilepath}" )

    #-----------------------------------------------------
    # Verify environmental variable                      -
    # generic_abstract_factory_install_bin_directory is  -
    # defined.                                           -
    #-----------------------------------------------------
    mouseion_test_variable_is_defined("generic_abstract_factory_install_bin_directory" "${generic_abstract_factory_logfilepath}" )

    #-----------------------------------------------------
    # Verify environmental variable                      -
    # generic_abstract_factory_install_include_directory -
    # is defined.                                        -
    #-----------------------------------------------------
    mouseion_test_variable_is_defined("generic_abstract_factory_install_include_directory" "${generic_abstract_factory_logfilepath}" )

    #-----------------------------------------------------
    # Verify environmental variable                      -
    # generic_abstract_factory_install_lib_directory is  -
    # defined.                                           -
    #-----------------------------------------------------
    mouseion_test_variable_is_defined("generic_abstract_factory_install_lib_directory" "${generic_abstract_factory_logfilepath}" )

endfunction()
