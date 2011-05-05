#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player
{
    public:
        Player(std::string name);
        virtual ~Player();
        int getLife();
        std::string getName();
        void lose();
        bool isDead();
        void pichenette(Player *victime);

    protected:
    private:
        int m_life;
        std::string m_name;
};

#endif // PLAYER_H
