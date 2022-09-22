/**********************************************************************************
// Block (Arquivo de Cabe�alho)
// 
// Cria��o:     22 Dez 2012
// Atualiza��o: 20 Ago 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Bloco do jogo Breakout
//
**********************************************************************************/

#ifndef _BREAKOUT_BLOCK_H_
#define _BREAKOUT_BLOCK_H_

// ---------------------------------------------------------------------------------
// Inclus�es

#include "Types.h"              // tipos espec�ficos da engine
#include "Object.h"             // interface de Object
#include "Sprite.h"             // interface de Sprites

// ---------------------------------------------------------------------------------

class Block : public Object
{
private:
    Sprite * sprite;            // sprite do bloco

public:
    float velX;                 // velocidade horizontal
    float velY;                 // velocidade vertical

    Block(Image * img);         // construtor
    ~Block();                   // destrutor

    void Update();              // atualiza��o do objeto
    void Draw();                // desenho do objeto
};

// ---------------------------------------------------------------------------------

inline void Block::Draw()
{ sprite->Draw(x,y,z); }

// ---------------------------------------------------------------------------------

#endif