#ifndef SQUIRREL_HPP
#define SQUIRREL_HPP

#include "npc.hpp"

struct Squirrel final : public NPC {
    Squirrel(int x, int y);
    Squirrel(std::istream &is);

    void print() override;
    void save(std::ostream &os) override;
    
    bool accept(std::shared_ptr<NPC> attacker) override;
    bool visit_Werewolf(std::shared_ptr<Werewolf> other) override;
    bool visit_Druid(std::shared_ptr<Druid> other) override;

    /*
    bool is_squirrel() const override;

    bool fight(std::shared_ptr<Squirrel> other) override;
    bool fight(std::shared_ptr<Werewolf> other) override;
    bool fight(std::shared_ptr<Druid> other) override;
    */
    
    friend std::ostream &operator<<(std::ostream &os, Squirrel &squirrel);
};

#endif