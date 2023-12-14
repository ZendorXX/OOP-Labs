#include <gtest/gtest.h>
#include "npc.cpp"
#include "squirrel.cpp"
#include "werewolf.cpp"
#include "druid.cpp"

TEST(FightTest, SquirrelAttackWerewolf) {
    std::shared_ptr<NPC> squirrel = std::make_shared<Squirrel>(0, 0);
    std::shared_ptr<NPC> werewolf = std::make_shared<Werewolf>(1, 1);
    bool success = werewolf->accept(squirrel);
    ASSERT_TRUE(success);
}

TEST(FightTest, SquirrelAttackWerewolfAndDruid) {
    std::shared_ptr<NPC> squirrel = std::make_shared<Squirrel>(0, 0);
    std::shared_ptr<NPC> werewolf = std::make_shared<Werewolf>(1, 1);
    std::shared_ptr<NPC> druid = std::make_shared<Druid>(2, 2);
    bool success = werewolf->accept(squirrel) and druid->accept(squirrel);
    ASSERT_TRUE(success);
}

TEST(FightTest, WerewolfAttackDruid) {
    std::shared_ptr<NPC> werewolf = std::make_shared<Werewolf>(1, 1);
    std::shared_ptr<NPC> druid = std::make_shared<Druid>(2, 2);
    bool success = druid->accept(werewolf);
    ASSERT_TRUE(success);
}

TEST(FightTest, DruidAttackWerewolf) {
    std::shared_ptr<NPC> werewolf = std::make_shared<Werewolf>(1, 1);
    std::shared_ptr<NPC> druid = std::make_shared<Druid>(2, 2);
    bool success = werewolf->accept(druid);
    ASSERT_FALSE(success);
}

TEST(FightTest, DruidAttackSquirrel) {
    std::shared_ptr<NPC> squirrel = std::make_shared<Squirrel>(0, 0);
    std::shared_ptr<NPC> druid = std::make_shared<Druid>(2, 2);
    bool success = squirrel->accept(druid);
    ASSERT_FALSE(success);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}