//! \file Communicator.h

#ifndef COMMUNICATOR_HEADER_FILES_COMMUNICATOR_H_
#define COMMUNICATOR_HEADER_FILES_COMMUNICATOR_H_

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <cstring>
#include <iostream>

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//

namespace COMMUNICATOR {

static constexpr std::size_t MASTER_TASK_ID=0;

class Communicator
{
public:
    //===== LIFECYCLE ======
    Communicator();

    virtual ~Communicator()=0;

    Communicator(Communicator const & other) = delete;

    Communicator(Communicator&& other);

    //===== DATA MEMBERS ===

    //===== ACCESSORS ======
    void 
    synchronizationPoint() const;

    int 
    getCommunicatorRank() const;

    bool
    sameCommunicatorRank( const int aRank) const;

    bool iAmMasterProcess() const;

    std::vector<std::string>
    gatherString(const std::string & data_to_gather,
                 const std::size_t task_id_gather_data) const;

    std::vector<int>
    gatherInt(const int & data_to_gather,
              const std::size_t task_id_gather_data) const;

    std::string
    broadcastStdString(const std::string & data_to_broadcast, const std::size_t bcast_rank) const;

    std::map<std::string,std::string>
    broadcastStdMap(const std::map<std::string,std::string> & a_map, const std::size_t bcast_rank) const;

    //===== MUTATORS =======
    void
    initializeWorldCommunicator();

    void
    resetName(const std::string & name);

    void 
    freeCommunicator();

    COMMUNICATOR::Communicator* 
    duplicateCommunicator() const
    {
        return this->duplicateCommunicator_();
    }

    // :TODO:05/21/2022 02:17:12 PM:: This needs to return a communicator.
    void 
    createSubcommunicator(const std::string & tag)
    {
        this->createSubcommunicator_(tag);
    }


    //===== OPERATORS ======
    Communicator& operator=(Communicator const & other) = delete;

    virtual Communicator& operator=(Communicator && other)=0;

    //===== STATIC FUNCTIONS ======
    static std::map<std::string, std::size_t>
    formGlobalMap(std::string const & tag,
                  Communicator const  & aCommunicator);

protected:

private:
    //===== ACCESSORS ======
    virtual void synchronizationPoint_() const=0;

    virtual std::size_t
    getSizeofCommunicator_() const=0;

    virtual std::size_t 
    getMaximum_(std::size_t const aValue) const=0;

    virtual int 
    getCommunicatorRank_() const=0;

    virtual COMMUNICATOR::Communicator*
    duplicateCommunicator_() const =0;

    virtual char*
    allGather_(char const * aCString,
               const std::size_t aLengthMaximum,
               std::size_t & offset_size, 
               std::size_t* & start_offsets_ptr,
               std::size_t* & end_offsets_ptr) const=0;

    virtual char*
    gather_(const std::size_t task_id_gather_data,
            char const * aCString,
            const std::size_t aLengthMaximum,
            std::size_t & offset_size, 
            std::size_t* & start_offsets_ptr,
            std::size_t* & end_offsets_ptr) const=0;

    virtual std::unique_ptr< char[] >
    gather_(const std::size_t task_id_gather_data,
            const std::unique_ptr<char[]> & aCString,
            const std::size_t aLengthMaximum,
            std::size_t & offset_size, 
            std::unique_ptr<std::size_t[]> & start_offsets_ptr,
            std::unique_ptr<std::size_t[]> & end_offsets_ptr) const=0;

    virtual std::vector<std::string>
    gatherString_(const std::string & data_to_gather,
                  const std::size_t task_id_gather_data) const=0;

    virtual std::vector<int>
    gatherInt_(const int & data_to_gather,
               const std::size_t task_id_gather_data) const=0;

    virtual std::string
    broadcastStdString_(const std::string & data_to_broadcast, 
                        const std::size_t bcast_rank=COMMUNICATOR::MASTER_TASK_ID) const=0;

    virtual std::map<std::string,std::string>
    broadcastStdMap_( const std::map<std::string,std::string> & a_map, const std::size_t bcast_rank) const=0;

    //===== MUTATORS =======
    virtual void
    initializeWorldCommunicator_()=0;

    // :TODO:05/21/2022 02:17:12 PM:: This needs to return a communicator.
    virtual void
    createSubcommunicator_(const std::string & tag)=0;

    virtual void 
    freeCommunicator_()=0;

    virtual void
    resetName_(const std::string & name)=0;

private:


};

} // namespace MPICOMMUNICATOR

#endif /* COMMUNICATOR_HEADER_FILES_COMMUNICATOR_H_ */
