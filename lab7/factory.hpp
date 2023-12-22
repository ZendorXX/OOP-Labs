#pragma once
#include "npc.hpp"
#include "druid.hpp"
#include "werewolf.hpp"
#include "squirrel.hpp"
#include "observer.hpp"

class Factory {
public:
    static std::shared_ptr<NPC> CreateNPC(const NpcType& type, int x, int y) {
        std::shared_ptr<NPC> result;
        if (type > NpcType::UnknownType && type < NpcType::Max) {
            switch (type) {
                case NpcType::SquirrelType:
                    result = std::static_pointer_cast<NPC>(std::make_shared<Squirrel>(x, y));
                    break;

                case NpcType::WerewolfType:
                    result = std::static_pointer_cast<NPC>(std::make_shared<Werewolf>(x, y));
                    break;

                case NpcType::DruidType:
                    result = std::static_pointer_cast<NPC>(std::make_shared<Druid>(x, y));
                    break;

                default:
                    break;
            }
        } else {
            std::string err = "unexpected NPC type: " + type;
            throw std::runtime_error(err);
        }

        if (result) {
            result->subscribe(TextObserver::get());
            result->subscribe(FileObserver::get());
        }

        return result;
    }

    static std::shared_ptr<NPC> CreateNPC(std::istream& is) {
        std::shared_ptr<NPC> result;
        int type{0};
        if (is >> type && type > NpcType::UnknownType && type < NpcType::Max) {
            switch (type) {
                case NpcType::SquirrelType:
                    result = std::static_pointer_cast<NPC>(std::make_shared<Squirrel>(is));
                    break;

                case NpcType::WerewolfType:
                    result = std::static_pointer_cast<NPC>(std::make_shared<Werewolf>(is));
                    break;

                case NpcType::DruidType:
                    result = std::static_pointer_cast<NPC>(std::make_shared<Druid>(is));
                    break;

                default:
                    break;
            }
        } else {
            std::string err = "unexpected NPC type: " + type;
            throw std::runtime_error(err);
        }
        
        if (result) {
            result->subscribe(TextObserver::get());
            result->subscribe(FileObserver::get());
        }

        return result;
    }
};




