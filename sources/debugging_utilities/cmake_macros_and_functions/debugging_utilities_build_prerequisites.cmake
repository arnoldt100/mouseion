 # =====================================================================================
 #
 #       Filename:  debugging_utilities_build_prerequisites.cmake
 #
 #    Description:  This function verifies the build prerequisites for package 
 #                  debugging_utilities are met.
 #
 # =====================================================================================

#-----------------------------------------------------
# This function verifies the key environmental       -
# variables are set.                                 -
#                                                    -
#                                                    -
#-----------------------------------------------------
function(verify_debugging_utilities_build_prerequisites_are_set)


    # Ensure that variable "debugging_utilities_logfilepath" is defined.
    if (NOT DEFINED debugging_utilities_logfilepath) 
        message (FATAL_ERROR "debugging_utilities_logfilepath is not defined.")
    endif()

    set(my_message "Verifying \"debugging_utilities' build prerequisities\" are satisfied.")
    log_message_to_file( ${debugging_utilities_logfilepath} "---")
    log_message_to_file( ${debugging_utilities_logfilepath} ${my_message})

    # Again verfying that variable 'debugging_utilities_logfilepath' is defined ... repeated
    # for consistency.
    mouseion_test_variable_is_defined("debugging_utilities_logfilepath" "${debugging_utilities_logfilepath}")

    # Verify variable debugging_utilities_install_lib_directory is defined,
    mouseion_test_variable_is_defined("debugging_utilities_install_lib_directory" "${debugging_utilities_logfilepath}")

    # Verify variable debugging_utilities_install_include_directory defined.
    mouseion_test_variable_is_defined("debugging_utilities_install_include_directory" "${debugging_utilities_logfilepath}")

    # Verify variable debugging_utilities_install_bin_directory defined.
    mouseion_test_variable_is_defined("debugging_utilities_install_bin_directory" "${debugging_utilities_logfilepath}")

    # Verify variable debugging_utilities_cmake_c_compiler defined.
    mouseion_test_variable_is_defined("debugging_utilities_cmake_c_compiler" "${debugging_utilities_logfilepath}")

    # Verify variable debugging_utilities_cmake_cxx_compiler defined.
    mouseion_test_variable_is_defined("debugging_utilities_cmake_cxx_compiler" "${debugging_utilities_logfilepath}")

    # Verify variable debugging_utilities_cxx_standard defined.
    mouseion_test_variable_is_defined("debugging_utilities_cxx_standard" "${debugging_utilities_logfilepath}")

    set(my_message "Package \"debugging_utilities' build prerequisities\" are satisfied.")
    log_message_to_file( ${debugging_utilities_logfilepath} ${my_message})
    log_message_to_file( ${debugging_utilities_logfilepath} "---\n")

endfunction()
