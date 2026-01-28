#pragma once
#include <cstddef>

enum class EventType{
    Heal,
    Damage
};

class Event{
    public:
        Event(EventType type, std::size_t magnitude);

        EventType get_type() const;
        std::size_t get_magnitude() const;
    private:
        EventType type;
        std::size_t magnitude;
};