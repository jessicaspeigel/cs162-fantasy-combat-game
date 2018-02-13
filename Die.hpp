/****************************************************
** Author: Jessica Speigel
** Assignment: cs162_fantasy_combat_game
** Date: 02/12/2018
** Description: header for die class
****************************************************/

#ifndef CS162_FANTASY_COMBAT_GAME_DIE_HPP
#define CS162_FANTASY_COMBAT_GAME_DIE_HPP

class Die
{
    protected:
        int sides;
        int rollValue;

    public:
        Die(int sides = 6);
        virtual ~Die();
        virtual int roll();
        int getSides();
        void setSides(int sides);
        int getRollValue();
};

#endif //CS162_FANTASY_COMBAT_GAME_DIE_HPP
