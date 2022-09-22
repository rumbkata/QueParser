#include "Number.h"

Number::Number(const int &value)
{
    this->value = value;
}

int Number::eval() const
{
    return value;
}