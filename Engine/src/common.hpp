#pragma once

#define ctrl(x) ((x)&0x1f)
#define SAFE_DELETE(p) \
    if (p)             \
    {                  \
        delete (p);    \
        (p) = NULL;    \
    }
#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))

#define MAX_HEIGHT 20
#define MAX_WIDTH 80

#define MAX_FPS 20

class INTPOS
{
public:
    int y;
    int x;

public:
    INTPOS(int y = 0, int x = 0);
    INTPOS operator+=(const INTPOS &right);
    INTPOS operator-=(const INTPOS &right);
    const INTPOS operator+(const INTPOS &right) const;
    const INTPOS operator-(const INTPOS &right) const;
};

class INTSIZE
{
public:
    int height;
    int width;

public:
    INTSIZE(int height = 0, int width = 0);
    INTSIZE operator+=(const INTSIZE &right);
    INTSIZE operator-=(const INTSIZE &right);
    const INTSIZE operator+(const INTSIZE &right) const;
    const INTSIZE operator-(const INTSIZE &right) const;
};
