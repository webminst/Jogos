/**********************************************************************************
// Player (Arquivo de Cabe�alho)
// 
// Cria��o:     21 Dez 2012
// Atualiza��o: 18 Ago 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Player do jogo Galaga
//
**********************************************************************************/

#ifndef _GALAGA_PLAYER_H_
#define _GALAGA_PLAYER_H_

// ---------------------------------------------------------------------------------
// Inclus�es

#include "Types.h"              // tipos espec�ficos da engine
#include "Object.h"             // interface de object
#include "Sprite.h"             // interface de sprites

// ---------------------------------------------------------------------------------

class Player : public Object
{
private:
    Sprite * sprite;            // sprite do player
    Image  * missile;           // imagem do m�ssil
    float vel;                  // velocidade horizontal do player
    bool keyCtrl;               // controla pressionamento de tecla

public:
    Player();
    ~Player();

    void Update();
    void Draw();
};

// ---------------------------------------------------------------------------------

inline void Player::Draw()
{ sprite->Draw(x,y,z); }

// ---------------------------------------------------------------------------------

#endif