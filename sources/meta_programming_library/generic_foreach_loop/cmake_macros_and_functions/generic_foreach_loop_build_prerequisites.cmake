#-----------------------------------------------------
# This function verifies the key environmental       -
# variables are set.                                 -
#                                                    -
#                                                    -
#-----------------------------------------------------
function(verify_generic_foreach_loop_build_prerequisites_are_set)


    #-----------------------------------------------------
    # Verify environmental variable                      -
    # generic_foreach_logfilepath is                     -
    # defined.                                           -
    #-----------------------------------------------------
    if (DEFINED generic_foreach_logfilepath)
        message("generic_foreach_logfilepath=${generic_foreach_logfilepath}")
    else()
        message( FATAL_ERROR "The variable generic_foreach_logfilepath is not defined. This \
        variable defines the log file for compiling the generic_foreach_loop library." )
    endif()

    #-----------------------------------------------------
    # Verify environmental variable                      -
    # generic_foreach_loop_cmake_cxx_compiler is         -
    # defined.                                           -
    #-----------------------------------------------------
    mouseion_test_variable_is_defined("generic_foreach_loop_cmake_cxx_compiler" "${generic_foreach_logfilepath}")

    #-----------------------------------------------------
    # Verify environmental variable                      -
    # generic_foreach_loop_cmake_c_compiler is defined.  -
    #-----------------------------------------------------
    mouseion_test_variable_is_defined("generic_foreach_loop_cmake_c_compiler" "${generic_foreach_logfilepath}")

    #-----------------------------------------------------
    # Verify environmental variable                      -
    # generic_foreach_loop_install_bin_directory is      -
    # defined.                                           -
    #-----------------------------------------------------
    mouseion_test_variable_is_defined("generic_foreach_loop_install_bin_directory" "${generic_foreach_logfilepath}")

    #-----------------------------------------------------
    # Verify environmental variable                      -
    # generic_foreach_loop_install_include_directory is  -
    # defined.                                           -
    #-----------------------------------------------------
    mouseion_test_variable_is_defined("generic_foreach_loop_install_include_directory" "${generic_foreach_logfilepath}")

    #-----------------------------------------------------
    # Verify environmental variable                      -
    # generic_foreach_loop_install_lib_directory is      -
    # defined.                                           -
    #-----------------------------------------------------
    mouseion_test_variable_is_defined("generic_foreach_loop_install_lib_directory" "${generic_foreach_logfilepath}")

endfunction()
