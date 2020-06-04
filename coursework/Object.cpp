#include "Object.h"

unsigned int Object::getID() const { return _id; }

std::string Object::uniqueArguments() const
{
    return "";
}

bool Object::operator==(const Object& other) { return (this->_id == other._id); }
