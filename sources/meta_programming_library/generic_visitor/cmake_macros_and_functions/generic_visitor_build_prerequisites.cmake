#-----------------------------------------------------
# This function verifies the key                     -
# variables are set.                                 -
#                                                    -
#-----------------------------------------------------
function(verify_generic_visitor_build_prerequisites_are_set)

    # Ensure that variable "generic_visitor_logfilepath" is defined.
    if (NOT DEFINED generic_visitor_logfilepath) 
        message (FATAL_ERROR "generic_visitor_logfilepath is not defined.")
    endif()

    #-----------------------------------------------------
    # Verify environmental variable                      -
    # generic_visitor_cmake_cxx_compiler is              -
    # defined.                                           -
    #-----------------------------------------------------
    mouseion_test_variable_is_defined("generic_visitor_cmake_cxx_compiler" "${generic_visitor_logfilepath}")

    #-----------------------------------------------------
    # Verify environmental variable                      -
    # generic_visitor_cmake_c_compiler is defined.       -
    #-----------------------------------------------------
    mouseion_test_variable_is_defined("generic_visitor_cmake_c_compiler" "${generic_visitor_logfilepath}")

    #-----------------------------------------------------
    # Verify environmental variable                      -
    # generic_visitor_install_bin_directory is           -
    # defined.                                           -
    #-----------------------------------------------------
    mouseion_test_variable_is_defined("generic_visitor_install_bin_directory" "${generic_visitor_logfilepath}")

    #-----------------------------------------------------
    # Verify environmental variable                      -
    # generic_visitor_install_include_directory is       -
    # defined.                                           -
    #-----------------------------------------------------
    mouseion_test_variable_is_defined("generic_visitor_install_include_directory" "${generic_visitor_logfilepath}")

    #-----------------------------------------------------
    # Verify environmental variable                      -
    # generic_visitor_install_lib_directory is           -
    # defined.                                           -
    #-----------------------------------------------------
    mouseion_test_variable_is_defined("generic_visitor_install_lib_directory" "${generic_visitor_logfilepath}")

endfunction()

