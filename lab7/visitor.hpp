#pragma once
#include "npc.hpp"
#include "druid.hpp"
#include "werewolf.hpp"
#include "squirrel.hpp"

class Visitor {
public:
    virtual bool visit(const std::shared_ptr<NPC>&) const = 0;
};

class SquirrelVisitor final : public Visitor {
    bool visit(const std::shared_ptr<NPC>& npc) const override {
        bool result{};
        switch (npc->get_type()) {
            case NpcType::SquirrelType:
                result = false;
                break;

            case NpcType::WerewolfType:
                result = true;
                break;
            
            case NpcType::DruidType:
                result = true;
                break;
        }
        return result;
    }
};

class WerewolfVisitor final : public Visitor {
    bool visit(const std::shared_ptr<NPC>& npc) const override {
        bool result{};
        switch (npc->get_type()) {
            case NpcType::SquirrelType:
                result = false;
                break;

            case NpcType::WerewolfType:
                result = false;
                break;
            
            case NpcType::DruidType:
                result = true;
                break;
        }
        return result;
    }
};

class DruidVisitor final : public Visitor {
public:
    bool visit(const std::shared_ptr<NPC>& npc) const override {
        bool result{};
        switch (npc->get_type()) {
            case NpcType::SquirrelType:
                result = false;
                break;

            case NpcType::WerewolfType:
                result = false;
                break;
            
            case NpcType::DruidType:
                result = false;
                break;
        }
        return result;
    }
};

class VisitorFactory {
public:
    static std::shared_ptr<Visitor> CreateVisitor(const NpcType& type) {
        std::shared_ptr<Visitor> result;
        switch (type) {
            case NpcType::DruidType:
                result = std::static_pointer_cast<Visitor>(std::make_shared<DruidVisitor>());
                break;

            case NpcType::WerewolfType:
                result = std::static_pointer_cast<Visitor>(std::make_shared<WerewolfVisitor>());
                break;

            case NpcType::SquirrelType:
                result = std::static_pointer_cast<Visitor>(std::make_shared<SquirrelVisitor>());
                break;
            default:
                break;
        }
        return result;
    }
};
