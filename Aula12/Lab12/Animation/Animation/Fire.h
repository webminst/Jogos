/**********************************************************************************
// Explosion (Arquivo de Cabe�alho)
//
// Cria��o:     20 Jan 2013
// Atualiza��o: 27 Ago 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Anima��o de um fogo
//
**********************************************************************************/

#ifndef _ANIMA_FIRE_H_
#define _ANIMA_FIRE_H_

// ---------------------------------------------------------------------------------
// Inclus�es

#include "Types.h"                      // tipos espec�ficos da engine
#include "Object.h"                     // interface de Object
#include "Animation.h"                  // anima��o de sprites

// ---------------------------------------------------------------------------------

class Fire : public Object
{
private:
    Animation* anim;                    // anima��o de explos�o

public:
    Fire(TileSet* tiles);               // construtor
    ~Fire();                            // destrutor

    void Update();                      // atualiza��o do objeto
    void Draw();                        // desenho do objeto
};

// ---------------------------------------------------------------------------------
// Fun��o Membro Inline

inline void Fire::Draw()
{
    anim->Draw(x, y, z);
}

// ---------------------------------------------------------------------------------

#endif