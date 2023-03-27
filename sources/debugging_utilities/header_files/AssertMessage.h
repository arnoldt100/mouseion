#ifndef DEBUGGING_AssertMessage_INC
#define DEBUGGING_AssertMessage_INC

//! @file AssertMessage.h

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <cassert>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//

namespace DEBUGGING
{

#define assertm(exp, msg) assert(((void)msg, exp))

}; // namespace DEBUGGING

#endif // DEBUGGING_AssertMessage_INC
