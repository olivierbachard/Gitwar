#include "Object.h"
#include <iostream>

using namespace std;

Object::Object(string name)
{
	m_name = name;
	m_used = false;
}

Object::~Object()
{
    //dtor
}

string Object::getName()
{
	return m_name;
}

bool Object::getUsed()
{
	return m_used;
}

bool Object::setUsed(bool b)
{	
	if(b == m_used) {
		return false;
	}
	else{	
		m_used = b;
		return true;
	}
}
