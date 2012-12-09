#ifndef EXTRACTOR_H
#define EXTRACTOR_H

#include "entity.h"

class Extractor : public Entity
{
public:
    Extractor();

    virtual void step(float dt);
    virtual void render();
};

#endif // EXTRACTOR_H
