#include "Player.hpp"
#include <stdexcept>

// Constructor: creates a Player in a valid state or fails fast.
Player::Player(int health, int max_health, int starting_room){
    // max_health must always be positive (entity invariant)
    if(max_health <= 0)
        throw std::invalid_argument("Max health must be positive.");
    
    this->max_health = max_health;
    
    // Normalize or reject initial health to preserve invariants
    if(health > max_health) 
        this->health = max_health;
    else if(health < 0)
        throw std::invalid_argument("Health must be positive.");
    else 
        this->health = health;

    // Initial position (validated by use cases / map, not here)
    this->current_room = starting_room;
}

// Applies damage while ensuring health never goes below zero.
void Player::take_damage(int damage){
    // Guard against invalid input
    if (damage < 0)
        throw std::invalid_argument("Damage must be positive.");

    this->health -= damage;

    // Enforce lower bound invariant
    if(this->health < 0) 
        this->health = 0;
}

// Derived state: alive if health is greater than zero.
bool Player::is_alive() const{
    return this->health > 0;
}

// Applies healing while ensuring health never exceeds max_health.
void Player::heal(int amount){
    // Guard against invalid input
    if (amount < 0)
        throw std::invalid_argument("Heal amount must be positive.");

    this->health += amount;

    // Enforce upper bound invariant
    if(this->health > this->max_health) 
        this->health = this->max_health;
}

// Read-only accessors.
int Player::get_health() const{
    return this->health;
}

int Player::get_max_health() const{
    return this->max_health;
}

int Player::get_current_room() const{
    return this->current_room;
}

// Updates player position; movement rules handled by use cases.
void Player::set_current_room(int room){
    this->current_room = room;
}
