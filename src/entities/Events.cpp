#include "Events.hpp"
#include <stdexcept>

Event::Event(EventType type, std::size_t magnitude){
    this->type = type;
    if(magnitude ==0){
        throw std::invalid_argument("Event::magnitude must be positive");
    }

    this->magnitude = magnitude;
}

EventType Event::get_type() const{
    return this->type;
}
std::size_t Event::get_magnitude() const{
    return this->magnitude;
}