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

    bool
    getGlobalStatus(const bool & data_to_reduce) const
    {
        return this->_getGlobalStatus(data_to_reduce);
    }

    std::string
    broadcastStdString(const std::string & data_to_broadcast, const std::size_t bcast_rank) const
    {
        return this->_broadcastStdString(data_to_broadcast,bcast_rank);
    }

    std::map<std::string,std::string>
    broadcastStdMap(const std::map<std::string,std::string> & a_map, const std::size_t bcast_rank) const
    {
        return this->broadcastStdMap_(a_map,bcast_rank);
    }

    //===== MUTATORS =======
    void
    initializeWorldCommunicator()
    {
        this->_initializeWorldCommunicator();
        return;
    }

    void
    resetName(const std::string & name)
    {
        this->resetName_(name);
        return;
    }

    void 
    freeCommunicator()
    {
        this->freeCommunicator_();
        return;
    }

    COMMUNICATOR::Communicator* 
    duplicateCommunicator() const
    {
        return this->_duplicateCommunicator();
    }

    // :TODO:05/21/2022 02:17:12 PM:: This needs tp return a communicator.
    void 
    createSubcommunicator(const std::string & tag)
    {
        this->_createSubcommunicator(tag);
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
    _getSizeofCommunicator(const std::string & id) const=0;

    virtual std::size_t 
    _getMaximum(std::size_t const aValue) const=0;

    virtual int 
    _getCommunicatorRank() const=0;

    virtual COMMUNICATOR::Communicator*
    _duplicateCommunicator() const =0;

    virtual char*
    _allGather(char const * aCString,
               const std::size_t aLengthMaximum,
               std::size_t & offset_size, 
               std::size_t* & start_offsets_ptr,
               std::size_t* & end_offsets_ptr) const=0;

    virtual char*
    _gather(const std::size_t task_id_gather_data,
            char const * aCString,
            const std::size_t aLengthMaximum,
            std::size_t & offset_size, 
            std::size_t* & start_offsets_ptr,
            std::size_t* & end_offsets_ptr) const=0;

    virtual std::unique_ptr< char[] >
    _gather(const std::size_t task_id_gather_data,
            const std::unique_ptr<char[]> & aCString,
            const std::size_t aLengthMaximum,
            std::size_t & offset_size, 
            std::unique_ptr<std::size_t[]> & start_offsets_ptr,
            std::unique_ptr<std::size_t[]> & end_offsets_ptr) const=0;

    virtual std::vector<std::string>
    _gatherString(const std::string & data_to_gather,
                  const std::size_t task_id_gather_data) const=0;


    virtual std::vector<int>
    _gatherInt(const int & data_to_gather,
               const std::size_t task_id_gather_data) const=0;

    virtual bool
    _getGlobalStatus(const bool & data_to_reduce) const=0;


    template<typename T>
    T _getGlobalStatusCustomReduction( T const & data_to_transform) const; 

    virtual std::string
    _broadcastStdString(const std::string & data_to_broadcast, 
                        const std::size_t bcast_rank=COMMUNICATOR::MASTER_TASK_ID) const=0;

    virtual std::map<std::string,std::string>
    broadcastStdMap_( const std::map<std::string,std::string> & a_map, const std::size_t bcast_rank) const=0;

    //===== MUTATORS =======
    virtual void
    _initializeWorldCommunicator()=0;

    // :TODO:05/21/2022 02:17:12 PM:: This needs to return a communicator.
    virtual void
    _createSubcommunicator(const std::string & tag)=0;

    virtual void 
    freeCommunicator_()=0;

    virtual void
    resetName_(const std::string & name)=0;

    //===== STATIC =======
    static constexpr std::size_t MAX_HOSTNAME_LENGTH=100;
};

} // namespace MPICOMMUNICATOR

#endif /* COMMUNICATOR_HEADER_FILES_COMMUNICATOR_H_ */
