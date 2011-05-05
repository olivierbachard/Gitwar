#include <iostream>
#include <time.h>
#include <vector>
#include <string>
#include "include/Player.h"

using namespace std;

int main()
{
    cout << "**** Let's fight begin! ****" << endl;
    cout << "============================" << endl;

    Player *olivier = new Player("Olivier");
    Player *sylvain = new Player("Sylvain");
    Player *winner;
    Player *loser;

    vector<Player*> players;
    players.push_back(olivier);
    players.push_back(sylvain);

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


        struct timespec req = {0};
        req.tv_sec = 0;
        req.tv_nsec = 400000000L;
        nanosleep(&req, (struct timespec *)NULL);
    }

    cout << "**** " << winner->getName() << " gagne le combat ! ****" << endl;
    loser->lose();

    return 0;

}
