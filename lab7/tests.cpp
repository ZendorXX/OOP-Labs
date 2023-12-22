#include <gtest/gtest.h>
#include "npc.cpp"
#include "druid.cpp"
#include "werewolf.cpp"
#include "squirrel.cpp"
#include "visitor.hpp"

std::shared_ptr<NPC> squirrel = std::make_shared<Squirrel>(21, 17);
std::shared_ptr<NPC> werewolf = std::make_shared<Werewolf>(20, 16);
std::shared_ptr<NPC> druid = std::make_shared<Druid>(100, 17);
std::shared_ptr<Visitor> squirrel_visitor = std::make_shared<SquirrelVisitor>();
std::shared_ptr<Visitor> werewolf_visitor = std::make_shared<WerewolfVisitor>();
std::shared_ptr<Visitor> druid_visitor = std::make_shared<DruidVisitor>();

TEST(VisitorTest, Squirrel) {
    ASSERT_FALSE(squirrel_visitor->visit(std::static_pointer_cast<Squirrel>(squirrel)));
    ASSERT_TRUE(squirrel_visitor->visit(std::static_pointer_cast<Werewolf>(werewolf)));
    ASSERT_TRUE(squirrel_visitor->visit(std::static_pointer_cast<Druid>(druid)));
}

TEST(VisitorTest, Werewolf) {
    ASSERT_FALSE(werewolf_visitor->visit(std::static_pointer_cast<Squirrel>(squirrel)));
    ASSERT_FALSE(werewolf_visitor->visit(std::static_pointer_cast<Werewolf>(werewolf)));
    ASSERT_TRUE(werewolf_visitor->visit(std::static_pointer_cast<Druid>(druid)));
}

TEST(VisitorTest, Druid) {
    ASSERT_FALSE(druid_visitor->visit(std::static_pointer_cast<Squirrel>(squirrel)));
    ASSERT_FALSE(druid_visitor->visit(std::static_pointer_cast<Werewolf>(werewolf)));
    ASSERT_FALSE(druid_visitor->visit(std::static_pointer_cast<Druid>(druid)));
}

TEST(AcceptTest, Squirrel) {
    ASSERT_FALSE(squirrel->accept(squirrel));
    ASSERT_TRUE(werewolf->accept(squirrel));
    ASSERT_TRUE(druid->accept(squirrel));    
}

TEST(AcceptTest, Werewolf) {
    ASSERT_FALSE(squirrel->accept(werewolf));
    ASSERT_FALSE(werewolf->accept(werewolf));
    ASSERT_TRUE(druid->accept(werewolf));
}

TEST(AcceptTest, Druid) {
    ASSERT_FALSE(squirrel->accept(druid));
    ASSERT_FALSE(werewolf->accept(druid));
    ASSERT_FALSE(druid->accept(druid));
}

TEST(DistanceTest, IsClose) {
    ASSERT_FALSE(squirrel->is_close(druid));
    ASSERT_FALSE(druid->is_close(werewolf));
    ASSERT_TRUE(werewolf->is_close(squirrel));
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}