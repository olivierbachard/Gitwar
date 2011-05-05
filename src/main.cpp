#include <iostream>
#include <vector>
#include <string>

#include "Player.h"

using namespace std;

int main()
{
    cout << "**** Let's fight begin! ****" << endl;
    cout << "============================" << endl;

    Player *olivier = new Player("Olivier");
    Player *sylvain = new Player("Sylvain");
    Player *winner;
    Player *loser;

    while(true)
    {
        olivier->pichenette(sylvain);

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

    return 0;

}
