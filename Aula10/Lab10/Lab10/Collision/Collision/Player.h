/**********************************************************************************
// Player (Arquivo de Cabe�alho)
// 
// Cria��o:     22 Dez 2012
// Atualiza��o: 20 Ago 2021
// Compilador:  Visual C++ 14
//
// Descri��o:   Player do jogo Breakout
//
**********************************************************************************/

#ifndef _BREAKOUT_PLAYER_H_
#define _BREAKOUT_PLAYER_H_

// ---------------------------------------------------------------------------------
// Inclus�es

#include "Types.h"                      // tipos espec�ficos da engine
#include "Object.h"                     // interface de Object
#include "Sprite.h"                     // interface de Sprites

// ---------------------------------------------------------------------------------
// Constantes Globais

enum PLAYERSTATE {PLAYING, STOPED};    

// ---------------------------------------------------------------------------------

class Player : public Object
{
private:
    Sprite * sprite;                    // sprite do jogador       
    float vel;                          // velocidade do jogador

public:
    uint state;                         // estado do jogo

    Player();                           // construtor
    ~Player();                          // destrutor

    void OnCollision(Object * obj);     // tratamento de colis�o
    void Update();                      // atualiza��o do objeto
    void Draw();                        // desenho do objeto
};

// ---------------------------------------------------------------------------------

inline void Player::Draw()
{ sprite->Draw(x,y,z); }

// ---------------------------------------------------------------------------------

#endif