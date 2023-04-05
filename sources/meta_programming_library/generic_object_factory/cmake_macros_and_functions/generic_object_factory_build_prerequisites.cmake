#-----------------------------------------------------
# This function verifies the key environmental
# variables are set for the target generic_object_factory.
#
#-----------------------------------------------------
function(verify_generic_object_factory_build_prerequisites_are_set)

   # Ensure that variable "mpi_communicator_logfilepath" is defined.
    if (NOT DEFINED generic_object_factory_logfilepath) 
        message (FATAL_ERROR "generic_object_factory_logfilepath is not defined.")
    endif()
    
    #-----------------------------------------------------
    # Verify environmental variable
    # generic_object_factory_install_lib_directory is 
    # defined.
    #-----------------------------------------------------
    mouseion_test_variable_is_defined("generic_object_factory_install_lib_directory" "${generic_object_factory_logfilepath}")
    
    #-----------------------------------------------------
    # Verify environmental variable
    # generic_object_factory_install_include_directory is
    # defined.
    #-----------------------------------------------------
    mouseion_test_variable_is_defined("generic_object_factory_install_include_directory" "${generic_object_factory_logfilepath}")

    #-----------------------------------------------------
    # Verify environmental variable 
    # generic_object_factory_install_bin_directory is 
    # defined.
    #-----------------------------------------------------
    mouseion_test_variable_is_defined("generic_object_factory_install_bin_directory" "${generic_object_factory_logfilepath}")

    #-----------------------------------------------------
    # Verify environmental variable 
    # generic_object_factory_cmake_cxx_compiler is 
    # defined.
    #-----------------------------------------------------
    mouseion_test_variable_is_defined("generic_object_factory_cmake_cxx_compiler" "${generic_object_factory_logfilepath}")
    
    #-----------------------------------------------------
    # Verify environmental variable 
    # generic_object_factory_cmake_c_compiler is 
    # defined.
    #-----------------------------------------------------
    mouseion_test_variable_is_defined("generic_object_factory_cmake_c_compiler" "${generic_object_factory_logfilepath}")

    #-----------------------------------------------------
    # Verify environmental variable 
    # generic_object_factory_cxx_standard is 
    # defined.
    #-----------------------------------------------------
    mouseion_test_variable_is_defined("generic_object_factory_cxx_standard" "${generic_object_factory_logfilepath}")
endfunction()
