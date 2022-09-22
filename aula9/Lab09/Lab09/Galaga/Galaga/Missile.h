/**********************************************************************************
// Missile (Arquivo de Cabe�alho)
// 
// Cria��o:     21 Dez 2012
// Atualiza��o: 18 Ago 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   M�sseis do jogo Galaga
//
**********************************************************************************/

#ifndef _GALAGA_MISSILE_H_
#define _GALAGA_MISSILE_H_

// ---------------------------------------------------------------------------------
// Inclus�es

#include "Types.h"              // tipos espec�ficos da engine
#include "Object.h"             // interface de object
#include "Sprite.h"             // interface de sprites
#include "Image.h"              // interface de image

// ---------------------------------------------------------------------------------

class Missile : public Object
{
private:
    Sprite * sprite;
    float vel;

public:
    Missile(Image * img);
    ~Missile();

    void Update();
    void Draw();
};

// ---------------------------------------------------------------------------------
// Fun��es Membro Inline
inline void Missile::Draw()
{  sprite->Draw(x,y,z); }

// ---------------------------------------------------------------------------------

#endif