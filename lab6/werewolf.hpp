#ifndef WEREWOLF_HPP
#define WEREWOLF_HPP

struct Werewolf : public NPC {
    Werewolf(int x, int y);
    Werewolf(std::istream &is);

    void print() override;
    void save(std::ostream &os) override;
    bool is_werewolf() const override;

    bool fight(std::shared_ptr<Werewolf> other) override;
    bool fight(std::shared_ptr<Werewolf> other) override;
    bool fight(std::shared_ptr<Druid> other) override;
    friend std::ostream &operator<<(std::ostream &os, Werewolf &werewolf);
};

#endif