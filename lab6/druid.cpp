#include "squirrel.hpp"
#include "werewolf.hpp"
#include "druid.hpp"

Druid::Druid(int x, int y) : NPC(DruidType, x, y) {}
Druid::Druid(std::istream &is) : NPC(DruidType, is) {}

void Druid::print() {
    std::cout << *this;
}

void Druid::save(std::ostream &os) {
    os << DruidType << std::endl;
    NPC::save(os);
}

bool Druid::accept(std::shared_ptr<NPC> attacker) {
    return attacker->visit_Druid(std::dynamic_pointer_cast<Druid>(shared_from_this()));
}

/*
bool Druid::is_druid() const {
    return true;
}

bool Druid::fight(std::shared_ptr<Squirrel> other) {
    fight_notify(other, false);
    return false;
}

bool Druid::fight(std::shared_ptr<Werewolf> other) {
    fight_notify(other, false);
    return false;
}

bool Druid::fight(std::shared_ptr<Druid> other) {
    fight_notify(other, false);
    return false;
}
*/

std::ostream &operator<<(std::ostream &os, Druid &druid) {
    os << "druid: " << *static_cast<NPC *>(&druid) << std::endl;
    return os;
}