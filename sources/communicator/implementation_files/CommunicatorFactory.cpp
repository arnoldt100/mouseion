//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "CommunicatorFactory.h"

namespace COMMUNICATOR {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

CommunicatorFactory::CommunicatorFactory()
{
    return;
}

CommunicatorFactory::CommunicatorFactory(const CommunicatorFactory & other)
{
    if (  this != &other ) 
    {

    }
    return;
}

CommunicatorFactory::CommunicatorFactory(CommunicatorFactory && other)
{
    if (  this != &other ) 
    {

    }
    return;
}

CommunicatorFactory::~CommunicatorFactory() 
{
    return;
}

//============================= ACCESSORS ====================================

std::unique_ptr<COMMUNICATOR::Communicator> 
CommunicatorFactory::createWorldCommunicator() const
{
    return this->createWorldCommunicator_();
}

std::unique_ptr<COMMUNICATOR::Communicator> 
CommunicatorFactory::createNullWorldCommunicator() const
{
    return this->createNullWorldCommunicator_();
}

std::unique_ptr<COMMUNICATOR::Communicator> 
CommunicatorFactory::cloneCommunicator(std::unique_ptr<COMMUNICATOR::Communicator> const & other) const
{
    return this->cloneCommunicator_(other);
}

std::unique_ptr<COMMUNICATOR::Communicator> 
CommunicatorFactory::cloneCommunicator(std::shared_ptr<COMMUNICATOR::Communicator> const & other) const
{
    return this->cloneCommunicator_(other);
}

std::unique_ptr<COMMUNICATOR::Communicator>
    	CommunicatorFactory::createCommunicator(std::unique_ptr<COMMUNICATOR::Communicator> const & other) const
{
	return this->createCommunicator_(other);
}
//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

CommunicatorFactory& 
CommunicatorFactory::operator=(const CommunicatorFactory& other)
{
    if (this != &other)
    {

    }
    return *this;
}

CommunicatorFactory& 
CommunicatorFactory::operator=(CommunicatorFactory&& other)
{
    if (this != &other)
    {

    }
    return *this;
}

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PROTECTED ////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PRIVATE //////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
    
//============================= LIFECYCLE ====================================

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================


} // namespace COMMUNICATOR
