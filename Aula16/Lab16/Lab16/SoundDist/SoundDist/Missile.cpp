/**********************************************************************************
// Missile (C�digo Fonte)
// 
// Cria��o:     07 Fev 2013
// Atualiza��o: 19 Set 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   M�sseis usados em SoundDist
//
**********************************************************************************/

#include "SoundDist.h"
#include "Missile.h"
#include "Explosion.h"

// ---------------------------------------------------------------------------------

Missile::Missile(Image * img, TileSet * explosion)
{
    explodSet = explosion;
    sprite = new Sprite(img);
    BBox(new Point(x, y));
    vel = 400;
}

// ---------------------------------------------------------------------------------

Missile::~Missile()
{
    delete sprite;
}

// ---------------------------------------------------------------------------------

void Missile::OnCollision(Object * obj)
{
    // toca som de explos�o
    SoundDist::audio->Volume(EXPLOSION, y / window->Height());
    SoundDist::audio->Play(EXPLOSION);

    // inica anima��o de explos�o
    Explosion * explo = new Explosion(explodSet);
    explo->MoveTo(x, y, Layer::FRONT);
    SoundDist::scene->Add(explo, STATIC);

    // remove m�ssil da cena
    SoundDist::scene->Delete(this, MOVING);
}

// ---------------------------------------------------------------------------------

void Missile::Update()
{
    // objeto se move no eixo y
    Translate(0, -vel * gameTime);

    // remove m�sseis que saem da janela
    if (Y() < 0)
        SoundDist::scene->Delete();
}

// ---------------------------------------------------------------------------------
