#pragma once
#include "npc.hpp"
#include "visitor.hpp"

class Druid final : public NPC {
public:
    Druid(int x, int y);
    Druid(std::istream& is);

    virtual bool accept(const std::shared_ptr<NPC>& attacker) const override;

    void print() override;
    void save(std::ostream& os) override;

    friend std::ostream& operator<<(std::ostream& os, Druid& druid);
};