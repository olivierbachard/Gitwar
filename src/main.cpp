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
    Object *potionDInvincibilite = new Object("Potion d'invincibilité");
	
    while(true)
    {	
	olivier->acquerirObjet(*potionDInvincibilite);
	olivier->utiliserObjet("Potion d'invincibilité");
	olivier->allerANewYork();

	while(sylvain->getLife() > 0) {
		olivier->attaqueZatniktel(sylvain);
	}

        if(sylvain->isDead())
        {
            cout << "Sylvain est mort...\n" << endl;
            winner = olivier;
            loser = sylvain;
            break;
        }
        else if(olivier->isDead())
        {
            cout << "Olivier est mort...\n" << endl;
            winner = sylvain;
            loser = olivier;
            break;
        }
        else
        {
            cout << "HP de Sylvain: " << sylvain->getLife() << endl;
            cout << "HP de Olivier: " << olivier->getLife() << endl;
            cout << endl;
        }

    }


    cout << "**** " << winner->getName() << " gagne le combat ! ****" << endl;
    loser->lose();

    delete olivier, olivier = NULL;
    delete sylvain, sylvain = NULL;
    delete potionDInvincibilite, potionDInvincibilite = NULL;

    return 0;

}
