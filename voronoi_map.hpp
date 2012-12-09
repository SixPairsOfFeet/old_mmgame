/*
* Copyright (c) 2012 by Joseph Marshall
*
* Permission to use, copy, modify, and distribute this software for any
* purpose without fee is hereby granted, provided that this entire notice
* is included in all copies of any software which is or includes a copy
* or modification of this software and in all copies of the supporting
* documentation for such software.
* THIS SOFTWARE IS BEING PROVIDED "AS IS", WITHOUT ANY EXPRESS OR IMPLIED
* WARRANTY.  IN PARTICULAR, NEITHER THE AUTHORS NOR AT&T MAKE ANY
* REPRESENTATION OR WARRANTY OF ANY KIND CONCERNING THE MERCHANTABILITY
* OF THIS SOFTWARE OR ITS FITNESS FOR ANY PARTICULAR PURPOSE.
*/

#include <stdlib.h>
#include <vector>
#include <list>
#include <glm/glm.hpp>

using namespace std;
using namespace glm;

class Site {
public:
    ivec2 pos;
    list<ivec2> verts;

    Site()=default;
    Site(const ivec2 pos) : pos(pos) {};
    Site & operator=(const Site&) = delete;
    Site(const Site&) = delete;

    ivec2 center();
};


class Map {
    int num_points, width, height;
    int minX, minY;

    void gen(vector<ivec2>&);
public:
    vector<Site> sites;
    Map(vector<ivec2> &points,
        float minX, float maxX,
        float minY, float maxY);
    Map & operator=(const Map&) = delete;
    Map(const Map&) = delete;

    void pprint();
};

