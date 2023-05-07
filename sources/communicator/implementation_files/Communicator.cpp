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
bool Communicator::iAmMasterProcess() const
{
    const std::size_t my_world_rank = this->getCommunicatorRank();
    return ( my_world_rank == MASTER_TASK_ID ? true : false);
}

//============================= MUTATORS =====================================

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
                            Communicator const  & aCommunicator)
{
    MEMORY_MANAGEMENT::Array1d<char> my_char_array_factory;
    MEMORY_MANAGEMENT::Array1d<std::size_t> my_int_array_factory;

    // Get the maximum length of tag with respect to the communicator group.
    auto tag_length = tag.length();
    auto tag_length_maximum = aCommunicator._getMaximum(tag_length);

    // Form and c string with length tag_length + 1, and 
    // then copy the tag in a c string.
    auto tag_length_maximum_adj = tag_length_maximum  + 1;

    char* tag_ptr = my_char_array_factory.createArray(tag,
                                                      tag_length_maximum_adj);

    // Gather all the tags into a char* array.
    std::size_t offset_size;
    std::size_t* start_offsets_ptr = nullptr;
    std::size_t* end_offsets_ptr = nullptr;
    char* all_tags_ptr = aCommunicator._allGather(
                             tag_ptr,
                             static_cast<std::size_t> (tag_length_maximum_adj),
                             offset_size,
                             start_offsets_ptr,
                             end_offsets_ptr);


    // Form vector string array of the hostnames.
    std::vector<std::string> aHostnameVec =
        STRING_UTILITIES::convert_sequence_of_chars_to_vector_string(offset_size,
                                                                     start_offsets_ptr,
                                                                     end_offsets_ptr,
                                                                     const_cast<char* >(all_tags_ptr) );

    // Form global map.
    std::size_t counter = 0;
    std::map<std::string, std::size_t> aGlobalTagMap;
    for (auto it : aHostnameVec )
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
    
// #####   EXPORTED FUNCTION DEFINITIONS  #########################################

template<>
std::vector<std::string> gatherData(
       std::string const & data_to_gather,
       Communicator const  & aCommunicator,
       const std::size_t task_id_gather_data)
{
    std::vector<std::string> gathered_data;
    gathered_data = aCommunicator.gatherString(data_to_gather,task_id_gather_data);
    return gathered_data;
};

template<>
std::vector<int> gatherData(
       int const & data_to_gather,
       Communicator const  & aCommunicator,
       const std::size_t task_id_gather_data)
{

    std::vector<int> gathered_data;
    gathered_data = aCommunicator.gatherInt(data_to_gather,
                                            task_id_gather_data);

    return gathered_data;
};

template<>
bool getGlobalStatus( bool const & data_to_transform,
                      Communicator const & aCommunicator)
{
    const bool out = aCommunicator.getGlobalStatus(data_to_transform);
    return out;
}

template<>
std::string broadcast(std::string const & data_to_broadcast,
                      Communicator const & aCommunicator,
					  const std::size_t bcast_rank)
{
    auto const master_task_id = static_cast<int>(bcast_rank);
    if (aCommunicator.sameCommunicatorRank(master_task_id))
    {
        std::cout << "Broadcasting data " << data_to_broadcast.c_str() << std::endl;
    }
    const auto broadcasted_data = aCommunicator.broadcastStdString(data_to_broadcast,bcast_rank);

    return broadcasted_data;

}

template<>
void resetHostName(std::shared_ptr<Communicator> & aCommunicator, std::string const & name)
{
    aCommunicator->resetName(name);
    return;
}


} /* namespace COMMUNICATOR */
