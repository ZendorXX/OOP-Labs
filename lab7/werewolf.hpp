#ifndef WEREWOLF_HPP
#define WEREWOLF_HPP

struct Werewolf final : public NPC {
    Werewolf(int x, int y);
    Werewolf(std::istream &is);

    void print() override;
    void save(std::ostream &os) override;

    bool accept(std::shared_ptr<NPC> attacker) override;
    bool visit_Druid(std::shared_ptr<Druid> other) override;

    friend std::ostream &operator<<(std::ostream &os, Werewolf &werewolf);
};

#endif