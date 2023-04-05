#-----------------------------------------------------
# This function verifies the key environmental       -
# variables are set.                                 -
#                                                    -
#-----------------------------------------------------
function(verify_primitives_build_prerequisites_are_set)

    # Ensure that variable "primitives_logfilepath" is defined.
    if (NOT DEFINED primitives_logfilepath) 
        message (FATAL_ERROR "Variable primitives_logfilepath is not defined.")
    endif()
    set(my_message "Verifying package \"primitives\" build prerequisities are satisfied.")
    mouseion_log_message_to_file(${primitives_logfilepath} "---")
    mouseion_log_message_to_file(${primitives_logfilepath} ${my_message})

    #-----------------------------------------------------
    # Verify environmental variable                      -
    # primitives_cmake_cxx_compiler is                   -
    # defined.                                           -
    #-----------------------------------------------------
    mouseion_test_variable_is_defined( "primitives_cmake_cxx_compiler" ${primitives_logfilepath})

    #-----------------------------------------------------
    # Verify environmental variable                      -
    # primitives_cmake_c_compiler is defined.            -
    #-----------------------------------------------------
    mouseion_test_variable_is_defined( "primitives_cmake_c_compiler" ${primitives_logfilepath})

    #-----------------------------------------------------
    # Verify environmental variable                      -
    # primitives_install_bin_directory is                -
    # defined.                                           -
    #-----------------------------------------------------
    mouseion_test_variable_is_defined( "primitives_install_bin_directory" ${primitives_logfilepath})

    #-----------------------------------------------------
    # Verify environmental variable                      -
    # primitives_install_include_directory is            -
    # defined.                                           -
    #-----------------------------------------------------
    mouseion_test_variable_is_defined( "primitives_install_include_directory" ${primitives_logfilepath})

    #-----------------------------------------------------
    # Verify environmental variable                      -
    # primitives_install_lib_directory is                -
    # defined.                                           -
    #-----------------------------------------------------
    mouseion_test_variable_is_defined( "primitives_install_lib_directory" ${primitives_logfilepath})

    set(my_message "Package \"primitives\" build prerequisities are satisfied.")
    mouseion_log_message_to_file(${primitives_logfilepath} ${my_message})
    mouseion_log_message_to_file(${primitives_logfilepath} "---\n")

endfunction()

