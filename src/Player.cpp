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

void Player::pichenette(Player *victime)
{
    cout << this->m_name << " met une grosse pichenette à " << victime->m_name << "!" << endl;
    victime->m_life -= 2;

}
