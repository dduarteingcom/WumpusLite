#include "Map.hpp"
#include <stdexcept>

Map::Map(std::size_t room_count){
    adjacency.resize(room_count);
    events.resize(room_count);
}

void Map::connect(RoomId a, RoomId b){
    std::size_t n = room_count();
    if(a>=n || b >=n){
        throw std::invalid_argument("Map::connect: RoomID exceeds number of rooms");
    }
    if (a == b){
        throw std::invalid_argument("Map::connect: cannot connect a room to itself");
    }
    adjacency[a].insert(b);
    adjacency[b].insert(a);
}

bool Map::isAdjacent(RoomId a , RoomId b) const{
    std::size_t n = room_count();

    if(a>=n || b >=n){
        throw std::invalid_argument("Map::isAdjacent: RoomID exceeds number of rooms");
    }

    return adjacency[a].count(b) == 1;
}

std::vector<Map::RoomId> Map::neighbors(RoomId room) const{
    std::size_t n = room_count();
    if(room >=n){
        throw std::invalid_argument("Map::neighbors: RoomID exceeds number of rooms");
    }

    std::size_t num_neighbors = adjacency[room].size();
    std::vector<RoomId> v;
    v.reserve(num_neighbors);

    for(RoomId neighbor : adjacency[room]){
        v.push_back(neighbor);
    }
    return v;
}

std::size_t Map::room_count(void) const{
    return adjacency.size();
}

void Map::place_event(RoomId room, Event ev){
    std::size_t n = room_count();
    if(room >=n){
        throw std::invalid_argument("Map::place_event: RoomID exceeds number of rooms");
    }
    if (events[room].has_value()) {
        throw std::logic_error("Map::place_event: room already has an event");
    }
    events[room] = ev;
}

bool Map::has_event(RoomId room) const{
    std::size_t n = room_count();
    if (room >= n) {
        throw std::invalid_argument("Map::has_event: invalid RoomId");
    }

    return events[room].has_value();
}

const Event* Map::get_event(RoomId room) const{
    std::size_t n = room_count();
    if (room >= n) {
        throw std::invalid_argument("Map::get_event: invalid RoomId");
    }

    if (!events[room].has_value()) {
        return nullptr;
    }

    return &events[room].value();
}