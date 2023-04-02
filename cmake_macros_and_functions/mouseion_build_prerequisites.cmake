#-----------------------------------------------------
# This function verifies the key environmental       -
# variables are set.                                 -
#                                                    -
#                                                    -
#-----------------------------------------------------
function(verify_mouseion_build_prerequisites_are_met)

    # Ensure that environment variable "MOUSEION_LOG_FILE" is defined.
    if( NOT DEFINED ENV{MOUSEION_LOG_FILE})
        message( FATAL_ERROR "The environment variable MOUSEION_LOG_FILE is not defined. This \
        variable defines the file location where MOUSEION CMAKE log files are written." )
    endif()

    set(my_message "Verifying \"mouseion\" build prerequisities are satisfied.")
    log_message_to_file($ENV{MOUSEION_LOG_FILE} "---")
    log_message_to_file($ENV{MOUSEION_LOG_FILE} ${my_message})

    #-----------------------------------------------------
    # Verify environment variable                        -
    # MOUSEION_LOG_FILE is defined.                      -
    #-----------------------------------------------------
    mouseion_test_env_variable_is_defined("MOUSEION_LOG_FILE" "$ENV{MOUSEION_LOG_FILE}" )

    #-----------------------------------------------------
    # Verify environmental variable MOUSEION_TOP_LEVEL is-
    # defined.                                           -
    #-----------------------------------------------------
    mouseion_test_env_variable_is_defined("MOUSEION_TOP_LEVEL" "$ENV{MOUSEION_LOG_FILE}" )

    #-----------------------------------------------------
    # Verify environmental variable                      -
    # MOUSEION_CMAKE_CXX_COMPILER is defined.            -
    #-----------------------------------------------------
    mouseion_test_env_variable_is_defined("MOUSEION_CMAKE_CXX_COMPILER" "$ENV{MOUSEION_LOG_FILE}" )

    #-----------------------------------------------------
    # Verify environmental variable                      -
    # MOUSEION_CMAKE_C_COMPILER is defined.              -
    #-----------------------------------------------------
    mouseion_test_env_variable_is_defined("MOUSEION_CMAKE_C_COMPILER" "$ENV{MOUSEION_LOG_FILE}" )

    #-----------------------------------------------------
    # Verify environmental variable                      -
    # MOUSEION_INSTALL_PREFIX  is defined.               -
    #                                                    -
    #-----------------------------------------------------
    mouseion_test_env_variable_is_defined("MOUSEION_INSTALL_PREFIX" "$ENV{MOUSEION_LOG_FILE}" )

    #-----------------------------------------------------
    # Verify environmental variable                      -
    # MOUSEION_INSTALL_BIN_DIRECTORY is defined.         -
    #-----------------------------------------------------
    mouseion_test_env_variable_is_defined("MOUSEION_INSTALL_BIN_DIRECTORY" "$ENV{MOUSEION_LOG_FILE}" )

    #-----------------------------------------------------
    # Verify environmental variable                      -
    # MOUSEION_INSTALL_INCLUDE_DIRECTORY is defined.     -
    #-----------------------------------------------------
    mouseion_test_env_variable_is_defined("MOUSEION_INSTALL_INCLUDE_DIRECTORY" "$ENV{MOUSEION_LOG_FILE}" )
    
    #-----------------------------------------------------
    # Verify environmental variable                      -
    # MOUSEION_INSTALL_LIB_DIRECTORY is defined.         -
    #-----------------------------------------------------
    mouseion_test_env_variable_is_defined("MOUSEION_INSTALL_LIB_DIRECTORY" "$ENV{MOUSEION_LOG_FILE}" )

    #-----------------------------------------------------
    # Verify environment variable                        -
    # MOUSEION_BOOST_TOP_LEVEL is defined.               -
    #-----------------------------------------------------
    mouseion_test_env_variable_is_defined("MOUSEION_BOOST_TOP_LEVEL" "$ENV{MOUSEION_LOG_FILE}" )

    # ----------------------------------------------------
    # Verify environment variable
    # MOUSEION_DEBUG_VALID_VALUES is defined
    # 
    # ----------------------------------------------------
    mouseion_test_env_variable_is_defined("MOUSEION_DEBUG_VALID_VALUES" "$ENV{MOUSEION_LOG_FILE}" )

    set(my_message "Package \"mouseion\" build prerequisities are satisfied.")
    log_message_to_file($ENV{MOUSEION_LOG_FILE} ${my_message})
    log_message_to_file($ENV{MOUSEION_LOG_FILE} "---\n")
endfunction()
