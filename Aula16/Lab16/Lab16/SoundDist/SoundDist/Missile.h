/**********************************************************************************
// Missile (Arquivo de Cabe�alho)
// 
// Cria��o:     07 Fev 2013
// Atualiza��o: 19 Set 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   M�sseis usados em SoundDist
//
**********************************************************************************/

#ifndef _SOUNDDIST_MISSILE_H_
#define _SOUNDDIST_MISSILE_H_

// ---------------------------------------------------------------------------------
// Inclus�es

#include "Types.h"                                  // tipos espec�ficos da engine
#include "Object.h"                                 // interface de object
#include "Sprite.h"                                 // interface de sprites
#include "Image.h"                                  // interface de image
#include "TileSet.h"                                // interface de tileset

// ---------------------------------------------------------------------------------

class Missile : public Object
{
private:
    TileSet * explodSet;                            // folha de sprites da explos�o                
    Sprite * sprite;                                // sprite do m�ssil
    float vel;                                      // velocidade do m�ssil

public:
    Missile(Image * img, TileSet * explosion);      // construtor
    ~Missile();                                     // destrutor

    void OnCollision(Object * obj);                 // resolu��o da colis�o
    void Update();                                  // atualiza��o do objeto
    void Draw();                                    // desenho do objeto
};

// ---------------------------------------------------------------------------------
// Fun��es Membro Inline
inline void Missile::Draw()
{  sprite->Draw(x, y, z); }

// ---------------------------------------------------------------------------------

#endif