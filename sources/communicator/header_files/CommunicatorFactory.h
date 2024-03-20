/*
 * CommunicatorFactory.h
 *
 *  Created on: 12/05/18
 *      Authors: Arnold Tharrington
 */

#ifndef COMMUNICATOR_COMMUNICATORFACTORY_H_ 
#define COMMUNICATOR_COMMUNICATORFACTORY_H_ 

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <memory>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "Communicator.h"

namespace COMMUNICATOR {

class CommunicatorFactory 
{

public:
    //===== LIFECYCLE ======
    CommunicatorFactory();

    CommunicatorFactory(const CommunicatorFactory& other);

    CommunicatorFactory(CommunicatorFactory && other); 

    virtual ~CommunicatorFactory()=0;

    //===== ACCESSORS ======
    std::unique_ptr<COMMUNICATOR::Communicator> createWorldCommunicator() const;

    std::unique_ptr<COMMUNICATOR::Communicator> createNullWorldCommunicator() const;

    std::unique_ptr<COMMUNICATOR::Communicator>
    	createCommunicator(std::unique_ptr<COMMUNICATOR::Communicator> const & other) const;

    std::unique_ptr<COMMUNICATOR::Communicator> 
    cloneCommunicator(std::unique_ptr<COMMUNICATOR::Communicator> const & other) const;

    std::unique_ptr<COMMUNICATOR::Communicator> 
    cloneCommunicator(std::shared_ptr<COMMUNICATOR::Communicator> const & other) const;

    //===== MUTATORS =======

    //===== OPERATORS ======
    CommunicatorFactory& operator=(CommunicatorFactory const & other);

    CommunicatorFactory& operator=(CommunicatorFactory && other);

protected:
    //===== LIFECYCLE ======

    //===== DATA MEMBERS ===

    //===== ACCESSORS ======

    //===== MUTATORS =======

    //===== OPERATORS ======

private:
    //===== LIFECYCLE ======

    //===== DATA MEMBERS ===

    //===== ACCESSORS ======
    virtual std::unique_ptr<COMMUNICATOR::Communicator> 
    createWorldCommunicator_() const=0;

    virtual std::unique_ptr<COMMUNICATOR::Communicator> 
    createNullWorldCommunicator_() const=0;

    virtual std::unique_ptr<COMMUNICATOR::Communicator> 
    cloneCommunicator_(std::unique_ptr<COMMUNICATOR::Communicator> const & other) const=0;

    virtual std::unique_ptr<COMMUNICATOR::Communicator> 
    cloneCommunicator_(std::shared_ptr<COMMUNICATOR::Communicator> const & other) const=0;

    virtual std::unique_ptr<COMMUNICATOR::Communicator>
    	createCommunicator_(std::unique_ptr<COMMUNICATOR::Communicator> const & other) const=0;

    //===== MUTATORS =======

    //===== OPERATORS ======


};

} /* namespace COMMUNICATOR */

#endif /* COMMUNICATOR_COMMUNICATORFACTORY_H_  */
