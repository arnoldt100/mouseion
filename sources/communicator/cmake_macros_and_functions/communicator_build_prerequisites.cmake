#-----------------------------------------------------
# This function verifies the key environmental       -
# variables are set.                                 -
#                                                    -
#                                                    -
#-----------------------------------------------------
function(verify_key_environmental_are_set)

    #-----------------------------------------------------
    # Verify  variable                                   -
    # communicator_install_lib_directory                 -
    # defined.                                           -
    #-----------------------------------------------------
   # Ensure that variable "communicator_logfilepath" is defined.
    if (NOT DEFINED communicator_logfilepath) 
        message (FATAL_ERROR "communicator_logfilepath is not defined.")
    endif()
    
    #-----------------------------------------------------
    # Verify variable communicator_install_lib_directory defined.
    #-----------------------------------------------------
    mouseion_test_variable_is_defined("communicator_install_lib_directory" "${communicator_logfilepath}")

    #-----------------------------------------------------
    # Verify variable                                    -
    # communicator_install_include_directory             -
    # defined.                                           -
    #-----------------------------------------------------
    mouseion_test_variable_is_defined("communicator_install_include_directory" "${communicator_logfilepath}")

    #-----------------------------------------------------
    # Verify variable                                    -
    # communicator_install_bin_directory                 -
    # defined.                                           -
    #-----------------------------------------------------
    mouseion_test_variable_is_defined("communicator_install_bin_directory" "${communicator_logfilepath}")

    #-----------------------------------------------------
    # Verify variable                                    -
    # communicator_cmake_cxx_compiler                    -
    # defined.                                           -
    #-----------------------------------------------------
    mouseion_test_variable_is_defined("communicator_cmake_cxx_compiler" "${communicator_logfilepath}")

    #-----------------------------------------------------
    # Verify variable                                    -
    # communicator_cmake_c_compiler                      -
    # defined.                                           -
    #-----------------------------------------------------
    mouseion_test_variable_is_defined("communicator_cmake_c_compiler" "${communicator_logfilepath}")

    #-----------------------------------------------------
    # Verify variable                                    -
    # communicator_cxx_standard                          -
    # defined.                                           -
    #-----------------------------------------------------
    mouseion_test_variable_is_defined("communicator_cxx_standard" "${communicator_logfilepath}")

endfunction()
