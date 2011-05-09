#ifndef OBJECT_H
#define OBJECT_H

#include <string>

class Object
{
    public:
        Object(std::string name);
        virtual ~Object();
        std::string getName();
        bool getUsed();
        bool setUsed(bool b);

    protected:
    private:
        std::string m_name;
        bool m_used;
};

#endif // OBJECT_H
