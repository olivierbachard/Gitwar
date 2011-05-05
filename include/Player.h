#ifndef PLAYER_H
#define PLAYER_H

#include <string>

using namespace std;

class Player
{
    public:
        Player(string name);
        virtual ~Player();
        int getLife();
        string getName();
        void lose();
        bool isDead();
        void pichenette(Player *victime);

    protected:
    private:
        int m_life;
        string m_name;
};

#endif // PLAYER_H
