#include "common.hpp"

INTPOS::INTPOS(int y, int x)
:y(y), x(x) 
{
    
}

INTPOS INTPOS::operator+=(const INTPOS &right)
{
    this->y += right.y;
    this->x += right.x;

    return *this;
}

INTPOS INTPOS::operator-=(const INTPOS &right)
{
    this->y -= right.y;
    this->x -= right.x;

    return *this;
}

const INTPOS INTPOS::operator+(const INTPOS &right) const
{
    INTPOS result = *this;
    result += right; 
    return result; 
}

const INTPOS INTPOS::operator-(const INTPOS &right) const
{
    INTPOS result = *this;
    result -= right; 
    return result; 
}

INTSIZE::INTSIZE(int height, int width)
:height(height), width(width)
{
    
}

INTSIZE INTSIZE::operator+=(const INTSIZE &right)
{
    this->height += right.height;
    this->width += right.width;

    return *this;
}

INTSIZE INTSIZE::operator-=(const INTSIZE &right)
{
    this->height -= right.height;
    this->width -= right.width;

    return *this;
}

const INTSIZE INTSIZE::operator+(const INTSIZE &right) const
{
    INTSIZE result;
    result += right;
    return result;
}

const INTSIZE INTSIZE::operator-(const INTSIZE &right) const
{
    INTSIZE result;
    result -= right;
    return result;
}