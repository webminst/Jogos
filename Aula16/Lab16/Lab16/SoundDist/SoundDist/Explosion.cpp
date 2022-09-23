/**********************************************************************************
// Explosion (C�digo Fonte)
//
// Cria��o:     07 Fev 2013
// Atualiza��o: 19 Set 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Anima��o de uma explos�o
//
**********************************************************************************/

#include "SoundDist.h"
#include "Explosion.h"

// ---------------------------------------------------------------------------------

Explosion::Explosion(TileSet * tiles)
{
    anim = new Animation(tiles, 0.015f, false);
    //BBox(new Circle(12.0f));
}

// ---------------------------------------------------------------------------------

Explosion::~Explosion()
{
    delete anim;
}

// ---------------------------------------------------------------------------------

void Explosion::Update()
{
    anim->NextFrame();
    if (anim->Inactive())
        SoundDist::scene->Delete();    
}

// ---------------------------------------------------------------------------------