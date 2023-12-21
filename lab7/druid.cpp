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

std::ostream &operator<<(std::ostream &os, Druid &druid) {
    os << "druid: " << *static_cast<NPC *>(&druid) << std::endl;
    return os;
}