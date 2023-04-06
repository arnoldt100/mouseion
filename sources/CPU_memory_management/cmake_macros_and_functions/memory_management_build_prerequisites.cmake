#-----------------------------------------------------
# This function verifies the key environmental
# variables are set for the target memory_management.
#
#-----------------------------------------------------
function(verify_memory_management_build_prerequisites_are_set)

   # Ensure that variable "mpi_communicator_logfilepath" is defined.
    if (NOT DEFINED memory_management_logfilepath) 
        message (FATAL_ERROR "memory_management_logfilepath is not defined.")
    endif()
    
    #-----------------------------------------------------
    # Verify environmental variable
    # memory_management_install_lib_directory is 
    # defined.
    #-----------------------------------------------------
    mouseion_test_variable_is_defined("memory_management_install_lib_directory" "${memory_management_logfilepath}")
    
    #-----------------------------------------------------
    # Verify environmental variable
    # memory_management_install_include_directory is
    # defined.
    #-----------------------------------------------------
    mouseion_test_variable_is_defined("memory_management_install_include_directory" "${memory_management_logfilepath}")

    #-----------------------------------------------------
    # Verify environmental variable 
    # memory_management_install_bin_directory is 
    # defined.
    #-----------------------------------------------------
    mouseion_test_variable_is_defined("memory_management_install_bin_directory" "${memory_management_logfilepath}")

    #-----------------------------------------------------
    # Verify environmental variable 
    # memory_management_cmake_cxx_compiler is 
    # defined.
    #-----------------------------------------------------
    mouseion_test_variable_is_defined("memory_management_cmake_cxx_compiler" "${memory_management_logfilepath}")
    
    #-----------------------------------------------------
    # Verify environmental variable 
    # memory_management_cmake_c_compiler is 
    # defined.
    #-----------------------------------------------------
    mouseion_test_variable_is_defined("memory_management_cmake_c_compiler" "${memory_management_logfilepath}")

    #-----------------------------------------------------
    # Verify environmental variable 
    # memory_management_cxx_standard is 
    # defined.
    #-----------------------------------------------------
    mouseion_test_variable_is_defined("memory_management_cxx_standard" "${memory_management_logfilepath}")
endfunction()
