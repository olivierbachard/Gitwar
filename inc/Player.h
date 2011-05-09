#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "Object.h"

class Player
{
    public:
        Player(std::string name);
        virtual ~Player();
        int getLife();
        std::string getName();
        void lose();
        bool isDead();
        bool isPureEnergy();
        void pichenette(Player *victime);
        void allerANewYork(void);
        void attaqueZatniktel(Player *victime);
        void deprimer(void);
        void acquerirObjet(Object objet);
        void utiliserObjet(std::string objet);

    protected:
    private:
        void changeLifeTo(int newLife);
        void changeLifeBy(int stepLife);

        int m_life;
        bool isEnergy;
        std::string m_name;
        std::vector<Object> m_objets;
};

#endif // PLAYER_H
