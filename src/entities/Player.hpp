#pragma once

class Player{
    public:
        Player(int health, int max_health, int starting_room);

        // Entity behavior
        void take_damage(int damage);
        void heal(int amount);
        bool is_alive() const;

        // Queries
        int get_health() const;
        int get_max_health() const;
        int get_current_room() const;

        // Minimal mutation
        void set_current_room(int room);


    private:
    int health;
    int max_health;
    int current_room;
};