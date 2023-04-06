#-----------------------------------------------------
# This function verifies the key 
# variables are set for the target string_utilities.
#
#-----------------------------------------------------
function(verify_string_utilities_build_prerequisites_are_set)

   # Ensure that variable "mpi_communicator_logfilepath" is defined.
    if (NOT DEFINED string_utilities_logfilepath) 
        message (FATAL_ERROR "string_utilities_logfilepath is not defined.")
    endif()
    
    #-----------------------------------------------------
    # Verify environmental variable
    # string_utilities_install_lib_directory is 
    # defined.
    #-----------------------------------------------------
    mouseion_test_variable_is_defined("string_utilities_install_lib_directory" "${string_utilities_logfilepath}")
    
    #-----------------------------------------------------
    # Verify environmental variable
    # string_utilities_install_include_directory is
    # defined.
    #-----------------------------------------------------
    mouseion_test_variable_is_defined("string_utilities_install_include_directory" "${string_utilities_logfilepath}")

    #-----------------------------------------------------
    # Verify environmental variable 
    # string_utilities_install_bin_directory is 
    # defined.
    #-----------------------------------------------------
    mouseion_test_variable_is_defined("string_utilities_install_bin_directory" "${string_utilities_logfilepath}")

    #-----------------------------------------------------
    # Verify environmental variable 
    # string_utilities_cmake_cxx_compiler is 
    # defined.
    #-----------------------------------------------------
    mouseion_test_variable_is_defined("string_utilities_cmake_cxx_compiler" "${string_utilities_logfilepath}")
    
    #-----------------------------------------------------
    # Verify environmental variable 
    # string_utilities_cmake_c_compiler is 
    # defined.
    #-----------------------------------------------------
    mouseion_test_variable_is_defined("string_utilities_cmake_c_compiler" "${string_utilities_logfilepath}")

    #-----------------------------------------------------
    # Verify environmental variable 
    # string_utilities_cxx_standard is 
    # defined.
    #-----------------------------------------------------
    mouseion_test_variable_is_defined("string_utilities_cxx_standard" "${string_utilities_logfilepath}")
endfunction()
