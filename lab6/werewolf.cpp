#include "squirrel.hpp"
#include "werewolf.hpp"
#include "druid.hpp"

Werewolf::Werewolf(int x, int y) : NPC(WerewolfType, x, y) {}
Werewolf::Werewolf(std::istream &is) : NPC(WerewolfType, is) {}

void Werewolf::print() {
    std::cout << *this;
}

void Werewolf::save(std::ostream &os) {
    os << WerewolfType << std::endl;
    NPC::save(os);
}

bool Werewolf::is_werewolf() const {
    return true;
}

bool Werewolf::fight(std::shared_ptr<Werewolf> other) {
    fight_notify(other, false);
    return false;
}

bool Werewolf::fight(std::shared_ptr<Werewolf> other) {
    fight_notify(other, false);
    return false;
}

bool Werewolf::fight(std::shared_ptr<Druid> other) {
    fight_notify(other, true);
    return true;
}

std::ostream &operator<<(std::ostream &os, Werewolf &werewolf) {
    os << "werewolf: " << *static_cast<NPC *>(&werewolf) << std::endl;
    return os;
}