#include <iostream>
#include <vector>
#include <string>

#include "Player.h"
#include "Object.h"


using namespace std;

int main()
{
    cout << "**** Let's fight begin! ****" << endl;
    cout << "============================" << endl;

    Player *olivier = new Player("Olivier");
    Player *sylvain = new Player("Sylvain");
    Player *winner;
    Player *loser;
    Object potionDInvincibilite("Potion d'invincibilité");

    while(!sylvain->isDead() && !olivier->isDead())
    {
        olivier->acquerirObjet(potionDInvincibilite);
        olivier->utiliserObjet("Potion d'invincibilité");
        olivier->allerANewYork();
        olivier->attaqueZatniktel(sylvain);

        if (!olivier->isDead() && sylvain->isPureEnergy())
        {
            cout << "Olivier se retrouve tout seul comme un con." << endl;
            olivier->deprimer();
        }

        cout << "HP de Sylvain: " << sylvain->getLife() << endl;
        cout << "HP de Olivier: " << olivier->getLife() << endl;
        cout << endl;
    }

    if(sylvain->isDead())
    {
        winner = olivier;
        loser = sylvain;
    }
    else if(olivier->isDead())
    {
        winner = sylvain;
        loser = olivier;
    }

    cout << loser->getName() << " est mort...\n" << endl;
    cout << "**** " << winner->getName() << " gagne le combat ! ****" << endl;
    loser->lose();

    delete olivier, olivier = NULL;
    delete sylvain, sylvain = NULL;

    return 0;

}
