/*
 * Communicator.cpp
 *
 *  Created on: Oct 15, 2018
 *      Author: arnoldt
 */

#include "Communicator.h"
#include "Array1d.hpp"
#include "Array1dChar.hpp"
#include "convert_sequence_of_chars_to_vector_string.h"

namespace COMMUNICATOR
{

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

Communicator::Communicator()
{
    return;
}

Communicator::~Communicator()
{
    return;
}

Communicator::Communicator(Communicator&& other)
{
    if (this != &other)
    {
        *this = std::move(other);
    }
    return;
}

//============================= ACCESSORS ====================================
std::size_t
Communicator::getSizeofCommunicator() const
{
    return this->getSizeofCommunicator_();
}

void 
Communicator::synchronizationPoint() const
{
   return this->synchronizationPoint_();
}

int 
Communicator::getCommunicatorRank() const
{
    return this->getCommunicatorRank_();
}

bool Communicator::sameCommunicatorRank( const int aRank) const
{
    const int my_world_rank = this->getCommunicatorRank();
    return ( aRank == my_world_rank ? true : false);
}

bool Communicator::iAmMasterProcess() const
{
    const std::size_t my_world_rank = this->getCommunicatorRank();
    return ( my_world_rank == MASTER_TASK_ID ? true : false);
}

std::vector<std::string>
Communicator::gatherString(const std::string & data_to_gather,
                           const std::size_t task_id_gather_data) const
{
        return this->gatherString_(data_to_gather,task_id_gather_data);
}

std::vector<int>
Communicator::gatherInt(const int & data_to_gather,
                        const std::size_t task_id_gather_data) const
{
    return this->gatherInt_(data_to_gather,task_id_gather_data);
}

std::string
Communicator::broadcastStdString(const std::string & data_to_broadcast, const std::size_t bcast_rank) const
{
    return this->broadcastStdString_(data_to_broadcast,bcast_rank);
}

std::map<std::string,std::string>
Communicator::broadcastStdMap(const std::map<std::string,std::string> & a_map, const std::size_t bcast_rank) const
{
    return this->broadcastStdMap_(a_map,bcast_rank);
}

//============================= MUTATORS =====================================

void
Communicator::initializeWorldCommunicator()
{
    this->initializeWorldCommunicator_();
    return;
}

void
Communicator::resetHostName(const std::string & name)
{
    this->resetName_(name);
    return;
}


void 
Communicator::freeCommunicator()
{
    this->freeCommunicator_();
    return;
}

//============================= OPERATORS ====================================

Communicator& Communicator::operator=(Communicator && other)
{
    if (this != &other)
    {
        
    }
    return *this;
}


//============================= OPERATORS ====================================

//============================= STATIC FUNCTIONS =============================
std::map<std::string, std::size_t>
Communicator::formGlobalMap(std::string const & tag,
                            Communicator const & aCommunicator)
{
    MEMORY_MANAGEMENT::Array1d<char> my_char_array_factory;
    MEMORY_MANAGEMENT::Array1d<std::size_t> my_int_array_factory;

    // Get the maximum length of tag with respect to the communicator group.
    auto tag_length = tag.length();
    auto tag_length_maximum = aCommunicator.getMaximum_(tag_length);

    // Form and c string with length tag_length + 1, and 
    // then copy the tag in a c string.
    auto tag_length_maximum_adj = tag_length_maximum  + 1;

    char* tag_ptr = my_char_array_factory.createArray(tag,
                                                      tag_length_maximum_adj);

    // Gather all the tags into a char* array.
    std::size_t offset_size;
    std::size_t* start_offsets_ptr = nullptr;
    std::size_t* end_offsets_ptr = nullptr;
    char* all_tags_ptr = aCommunicator.allGather_(
                             tag_ptr,
                             static_cast<std::size_t> (tag_length_maximum_adj),
                             offset_size,
                             start_offsets_ptr,
                             end_offsets_ptr);


    // Form vector string array of all of the tags.
    std::vector<std::string> aTagVec =
        STRING_UTILITIES::convert_sequence_of_chars_to_vector_string(offset_size,
                                                                     start_offsets_ptr,
                                                                     end_offsets_ptr,
                                                                     const_cast<char* >(all_tags_ptr) );

    // Form global map.
    std::size_t counter = 0;
    std::map<std::string, std::size_t> aGlobalTagMap;
    for (auto it : aTagVec )
    {
        auto it2 = aGlobalTagMap.find(it);
        if (it2 == aGlobalTagMap.end())
        {
                aGlobalTagMap[it] = counter;
                ++counter;
        }
    }

    my_char_array_factory.destroyArray(all_tags_ptr);
    my_char_array_factory.destroyArray(tag_ptr);

    my_int_array_factory.destroyArray(start_offsets_ptr);
    my_int_array_factory.destroyArray(end_offsets_ptr);

    return aGlobalTagMap ;
}

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PROTECTED ////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PRIVATE //////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
    
} /* namespace COMMUNICATOR */
