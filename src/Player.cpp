#include "Player.h"
#include <iostream>

using namespace std;

Player::Player(string name)
{
    this->m_life = 100;
    this->m_name = name;
}

Player::~Player()
{
    //dtor
}

int Player::getLife()
{
    return m_life;
}

string Player::getName()
{
    return m_name;
}

void Player::lose()
{
    cout << this->m_name << " s'est trop fait bouillavé la face !" << endl;
}

bool Player::isDead()
{
    if( this->m_life <= 0)
    {
        return true;
    }
    else {
        return false;
    }
}

void Player::attaqueZatniktel(Player *victime)
{
	cout << this->m_name << " envoie un coup de Zat'nik'tel à " << victime->m_name << "!" << endl;
    	victime->m_life -= 5;
}

void Player::acquerirObjet(Object objet)
{
	m_objets.push_back(objet);
}

void Player::utiliserObjet(string objet)
{
	bool ok = false;
	for(unsigned int i = 0; i < m_objets.size(); i++)
	{
		if (m_objets[i].getName() == objet) {
			if(m_objets.at(i).setUsed(true)) {
				ok = true;
				cout << m_name << " utilise l'objet " << m_objets[i].getName() << endl;
				break;
			}
		}
	}

	if(!ok) {
		cout << "Oula tu essaie de tricher, c'est pas bien! Tu ne peux pas utiliser cet objet" << endl;
	}
	
}

void Player::pichenette(Player *victime)
{
    cout << this->m_name << " met une grosse pichenette à " << victime->m_name << "!" << endl;
    victime->m_life -= 2;

}

void Player::allerANewYork(void)
{
    if (m_name == "Olivier")
    {
	cout << m_name << " fait la boulette d'aller à New-York. Il le paye le prix fort !" << endl;

	for(unsigned int i=0; i<m_objets.size();i++)
	{
		if( (m_objets[i].getName() == "Potion d'invincibilité") && m_objets[i].getUsed() )
		{
			cout << "Cependant, " << m_name << " est invincible, il ne craint ni personne, pas même un voyage à New York !" << endl;
			break;
		}
		else
		{
        		m_life = 0;
		}
	}
    }
    else
    {
        cout << m_name << " passe quelques jours à New-York. Il se repose bien." << endl;
        m_life = 100;
    }
}
