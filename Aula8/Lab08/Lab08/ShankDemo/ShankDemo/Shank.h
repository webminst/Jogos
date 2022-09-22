/**********************************************************************************
// Shank (Arquivo de Cabe�alho)
//
// Cria��o:     21 Dez 2012
// Atualiza��o: 14 Ago 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Define personagem Shank como um objeto do jogo
//
**********************************************************************************/

#ifndef _SHANKDEMO_SHANK_H_
#define _SHANKDEMO_SHANK_H_

// ---------------------------------------------------------------------------------
// Inclus�es

#include "Types.h"             // tipos espec�ficos da engine
#include "Object.h"            // interface de object
#include "Sprite.h"            // interface de sprites

// ---------------------------------------------------------------------------------

class Shank : public Object
{
private:
    Sprite * sprite;

public:
    Shank();
    ~Shank();

    void Update();
    void Draw();
};

// ---------------------------------------------------------------------------------

#endif