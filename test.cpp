#define CATCH_CONFIG_FAST_COMPILE
#include "catch.hpp"
#include "player.h"
#include "ship.h"
#include <string>

TEST_CASE("Player")
{
    Player pl;
    SECTION( "Score- Proper handling" )
    {
        {
        INFO("Score should be a positive number");
        REQUIRE(pl.getScore() == 0);
        }
        {
        pl.addScore((unsigned int)5);
        INFO("Score should increase for every new hit");
        REQUIRE(pl.getScore() == 5);
        }
        {
        pl.addScore(-5);
        INFO("Score should not be allowed to decrease");
        REQUIRE(pl.getScore() != -5);
        }
        {
        auto currScore = pl.getScore();
        unsigned int oppShipLength = 4;
        pl.addScore(oppShipLength);
        INFO("Score should equal opponent's ship length");
        REQUIRE(pl.getScore() == oppShipLength+currScore);
        }
    }
    SECTION("Name - Proper assignment"){
        std::string _plName = "Player 1";
        Player p2(_plName);
        {
        INFO("getName should return player name");
        REQUIRE(p2.getName() == _plName);
        }
        {
        INFO("getName should return player name");
        REQUIRE(pl.getName() != "");
        }
    }
}
TEST_CASE("Ship")
{
    Ship sh1;
    Ship sh2(5);
    SECTION( "Default ship values" )
    {
        {
        INFO("Ship should by default float");
        REQUIRE(sh1.aFloat());
        }
        {
        INFO("Ship by default should be size one");
        REQUIRE(sh1.getSize() == 1);
        }
        {
        INFO("Ship of any size more than zero should be afloat");
        REQUIRE(sh2.aFloat());
        }
        {
        Ship sh3(0);
        INFO("Ship of size zero should not be afloat");
        REQUIRE(!(sh3.aFloat()));
        }
    }
    SECTION("Ship - Damage"){
        {
        sh1.aHit();
        INFO("getName should return player name");
        REQUIRE(!(sh1.aFloat()));
        }
        {
        sh2.aHit();
        INFO("Ship should not sink if size is greater than damage dealt");
        REQUIRE(sh2.aFloat());
        }
    }
}
/*
score should be positive number
    >0
score should add 1 when a new block is hit
    getScore+1 == addScore?
when player name is entered

    */
