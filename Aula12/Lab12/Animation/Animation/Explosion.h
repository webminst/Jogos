/**********************************************************************************
// Explosion (Arquivo de Cabe�alho)
//
// Cria��o:     20 Jan 2013
// Atualiza��o: 27 Ago 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Anima��o de uma explos�o
//
**********************************************************************************/

#ifndef _ANIMA_EXPLOSION_H_
#define _ANIMA_EXPLOSION_H_

// ---------------------------------------------------------------------------------
// Inclus�es

#include "Animation.h"                  // anima��o de sprites
#include "Object.h"                     // interface de Object
#include "Types.h"                      // tipos espec�ficos da engine

// ---------------------------------------------------------------------------------

class Explosion : public Object
{
private:
    Animation* anim;                   // anima��o de explos�o

public:
    Explosion(TileSet* tiles);         // construtor
    ~Explosion();                       // destrutor

    void Update();                      // atualiza��o do objeto
    void Draw();                        // desenho do objeto
};

// ---------------------------------------------------------------------------------
// Fun��o Membro Inline

inline void Explosion::Draw()
{
    anim->Draw(x, y, z);
}

// ---------------------------------------------------------------------------------

#endif