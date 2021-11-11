#pragma once

#define ctrl(x) ((x) & 0x1f)
#define SAFE_DELETE(p) if(p) { delete (p); (p) = NULL; }
#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))


struct INTPOS {
    int x;
    int y;
};