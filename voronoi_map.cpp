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

#include "voronoi_map.hpp"
#include "voronoi.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <glm/glm.hpp>

using namespace std;
using namespace glm;


ivec2 Site::center() {
    vec2 center;
    for (auto &v : verts) {
        center += v;
    }
    return ivec2(center/static_cast<float>(verts.size())+.5f);
}

Map::Map(vector<ivec2> &points,
         float minX, float maxX,
         float minY, float maxY) :
    sites(points.size()),
    num_points(points.size()),
    width(maxX-minX), height(maxY-minY),
    minX(minX), minY(minY)
{

//    for (int i=0; i<10; i++) { // 10 ?!?!
//        if (i != 0) {
//            for (int i=0; i<num_points; i++) {
//                points[i] = sites[i].center();
//            }
//        }
        gen(points);
  //  }
}

void Map::gen(vector<ivec2>& points) {
    voronoi::Voronoi v(points, minX, width + minX, minY, height + minY);

    int i = 0;
    for (auto &vsite : v.sites) {
        auto site = &sites[i];
        site->pos = points[i];
        site->verts.clear();

        ivec4 tmp_ = vsite.edges.back();
        ivec2 first(tmp_.x, tmp_.y);
        site->verts.push_back(first);
        ivec2 last(tmp_.z, tmp_.w);
        if (first != last)
            site->verts.push_back(last);


        vsite.edges.pop_back();

        // Convert edges to a single loop of vertices.
        bool reversed = false;
        int md = 1;
        while (vsite.edges.size() > 0) {
            bool found = false;
            int idx = 0;
            for (auto &e : vsite.edges) {
                ivec2 exy(e.x, e.y);
                ivec2 ezw(e.z, e.w);

                ivec2 d = exy-last;
                if (abs(d.x) < md && abs(d.y) < md) {
                    if (reversed) {
                        if (ezw != site->verts.front())
                            site->verts.emplace_front(ezw);
                    } else {
                        if (ezw != site->verts.back())
                            site->verts.emplace_back(ezw);
                    }
                    last = ezw;
                    found = true;
                    break;
                }

                d = ezw-last;
                if (abs(d.x) < md && abs(d.y) < md) {
                    if (reversed) {
                        if (exy != site->verts.front())
                            site->verts.emplace_front(exy);
                    } else {
                        if (exy != site->verts.back())
                            site->verts.emplace_back(exy);
                    }
                    last = exy;
                    found = true;
                    break;
                }
                idx ++;
            }

            if (found) { 
                vsite.edges.erase(vsite.edges.begin()+idx);
            } else {
                if (reversed) {
                    // TODO we shouldn't get dangling edges like this!
                    // Here we try to recover from it and snap to the next
                    // closest edge point.
                    md ++;
                    continue;
                }
                last = first;
                reversed = true;
            }
            md = 1;
        }
        if (site->verts.front() == site->verts.back()) {
            site->verts.pop_back();
        }
        i ++;
    }
}

void Map::pprint() {
    for (auto &s : sites) {
        cout << s.pos.x << "," << s.pos.y << endl;
    }
    for (auto &s : sites) {
        cout << "|" << endl;
        for (auto &v : s.verts) {
            cout << v.x << "," << v.y << endl;
        }
    }
}
