#ifndef DRUID_HPP
#define DRUID_HPP

struct Druid final : public NPC {
    Druid(int x, int y);
    Druid(std::istream &is);

    void print() override;
    void save(std::ostream &os) override;

    bool accept(std::shared_ptr<NPC> attacker) override;

    friend std::ostream &operator<<(std::ostream &os, Druid &druid);
};

#endif