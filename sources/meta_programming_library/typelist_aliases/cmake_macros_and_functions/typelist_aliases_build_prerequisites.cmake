#-----------------------------------------------------
# This function verifies the                         -
# variables are set.                                 -
#                                                    -
#                                                    -
#-----------------------------------------------------
function(verify_typelist_aliases_build_prerequisites)

    # Ensure that variable "typelist_aliases_logfilepath" is defined.
    if (NOT DEFINED typelist_aliases_logfilepath) 
        message (FATAL_ERROR "Variable typelist_aliases_logfilepath is not defined.")
    endif()
    set(my_message "Verifying package \"typelist_aliases\" build prerequisities are satisfied.")
    mouseion_log_message_to_file(${typelist_aliases_logfilepath} "---")
    mouseion_log_message_to_file(${typelist_aliases_logfilepath} ${my_message})

    #-----------------------------------------------------
    # Verify environmental variable
    # typelist_aliases_cxx_standard is defined.
    #-----------------------------------------------------
    mouseion_test_variable_is_defined( "typelist_aliases_cxx_standard" ${typelist_aliases_logfilepath})

    #-----------------------------------------------------
    # Verify environmental variable
    # typelist_aliases_cmake_cxx_compiler is defined.
    #-----------------------------------------------------
    mouseion_test_variable_is_defined( "typelist_aliases_cmake_cxx_compiler" ${typelist_aliases_logfilepath} )

    #-----------------------------------------------------
    # Verify environmental variable
    # typelist_aliases_cmake_c_compiler is defined.
    #-----------------------------------------------------
    mouseion_test_variable_is_defined( "typelist_aliases_cmake_c_compiler" ${typelist_aliases_logfilepath})

    #-----------------------------------------------------
    # Verify environmental variable
    # typelist_aliases_install_bin_directory is defined.
    #-----------------------------------------------------
    mouseion_test_variable_is_defined( "typelist_aliases_install_bin_directory" ${typelist_aliases_logfilepath})

    #-----------------------------------------------------
    # Verify environmental variable
    # typelist_aliases_install_include_directory is 
    # defined.
    #-----------------------------------------------------
    mouseion_test_variable_is_defined( "typelist_aliases_install_include_directory" ${typelist_aliases_logfilepath})

    #-----------------------------------------------------
    # Verify environmental variable
    # typelist_aliases_install_lib_directory is defined.
    #-----------------------------------------------------
    mouseion_test_variable_is_defined( "typelist_aliases_install_lib_directory" ${typelist_aliases_logfilepath})

    #-----------------------------------------------------
    # Verify environment variable
    # typelist_aliases_boost_top_level is defined.
    #-----------------------------------------------------
    mouseion_test_variable_is_defined( "typelist_aliases_boost_top_level" ${typelist_aliases_logfilepath})

    set(my_message "Package \"typelist_aliases\" build prerequisities are satisfied.")
    mouseion_log_message_to_file(${typelist_aliases_logfilepath} ${my_message})
    mouseion_log_message_to_file(${typelist_aliases_logfilepath} "---\n")
endfunction()
