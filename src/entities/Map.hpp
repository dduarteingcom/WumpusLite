#pragma once
#include <cstddef>
#include <unordered_set>
#include <vector>
#include "Events.hpp"
#include <optional>

class Map{
    public:
        using RoomId = std::size_t;

        explicit Map(std::size_t room_count);

        void connect(RoomId a, RoomId b);
        bool isAdjacent(RoomId a, RoomId b) const;
        std::vector<RoomId> neighbors(RoomId room) const;
        std::size_t room_count(void) const;

        void place_event(RoomId room, Event ev);
        bool has_event(RoomId room) const;
        const Event* get_event(RoomId room) const;
    private:
        // Graph: room -> set of adjacent rooms
        std::vector<std::unordered_set<RoomId>> adjacency;

        // Contents: room -> optional event
        std::vector<std::optional<Event>> events;
};