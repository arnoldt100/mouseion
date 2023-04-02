
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

 
# ===  MACRO     ======================================================================
#         Name:  enable_mouseion_debug_flags
#  Description:  Enables debug flags for target
# 
#  Arguments: MY_TARGET; The target to enable the debug flags.
# =====================================================================================

macro(enable_mouseion_debug_flags MY_TARGET)

    target_compile_options(${MY_TARGET}
        PRIVATE $<$ENV{MOUSEION_DEBUG_VALID_VALUES}:-DMOUSEION_DBG_VALID_VALUES>)
endmacro()
