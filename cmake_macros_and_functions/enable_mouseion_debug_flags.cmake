
#  =====================================================================================
# 
#        Filename:  enable_mouseion_debug_flags.cmake
# 
#     Description:  
# 
#          Author:  Arnold N. Tharrington (), arnoldt@ornl.gov
#    Organization:  ORNL-National Center of Computational Sciences
# 
#  =====================================================================================

 
# ===  FUNCTION  ======================================================================
#         Name:  enable_mouseion_debug_flags
#  Description:  Enables debug flags for target
# 
#  Arguments: MY_TARGET; The target to enable the debug flags.
# =====================================================================================

function(enable_mouseion_debug_flags MY_TARGET)

    set(my_debug_flags "-DMOUSEION_DBG")
    set(my_debug_mouseion 0)

    # Check if we are debugging for valid values
    if ( $ENV{MOUSEION_DEBUG_VALID_VALUES} )
        set(my_debug_mouseion 1)
        string(APPEND my_debug_flags " -DMOUSEION_DBG_VALID_VALUES") 
    endif()

    # Set debug compile options for target.
    target_compile_options(${MY_TARGET}
        PRIVATE $<${my_debug_mouseion}:${my_debug_flags}>)
endfunction()
