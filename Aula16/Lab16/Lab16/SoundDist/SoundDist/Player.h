/**********************************************************************************
// Player (Arquivo de Cabe�alho)
// 
// Cria��o:     07 Fev 2013
// Atualiza��o: 19 Set 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Player usado em SoundDistance
//
**********************************************************************************/

#ifndef _SOUNDDIST_PLAYER_H_
#define _SOUNDDIST_PLAYER_H_

// ---------------------------------------------------------------------------------
// Inclus�es

#include "Types.h"          // tipos espec�ficos da engine
#include "Object.h"         // interface de object
#include "Sprite.h"         // interface de sprites

// ---------------------------------------------------------------------------------

class Player : public Object
{
private:
    Sprite  * sprite;       // sprite do player
    Image   * missile;      // imagem do m�ssil
    TileSet * explo;        // quadros da explos�o
    float vel;              // velocidade horizontal do player
    bool keyCtrl;           // controla pressionamento de tecla

public:
    Player();               // construtor
    ~Player();              // destrutor

    void Update();          // atualiza��o
    void Draw();            // desenho
};

// ---------------------------------------------------------------------------------

inline void Player::Draw()
{ sprite->Draw(x, y, z); }

// ---------------------------------------------------------------------------------

#endif