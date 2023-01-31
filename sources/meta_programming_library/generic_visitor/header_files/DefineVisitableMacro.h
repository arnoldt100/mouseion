#ifndef  DefineVistableMacro_INC
#define  DefineVistableMacro_INC

#define DEFINE_VISITABLE() \
    ReturnType Accept(MPL::BaseVisitor & guest) override \
{ \
    return AcceptImpl( *this, guest); \
} \

#endif   // ----- #ifndef DefineVistableMacro_INC  ----- 
