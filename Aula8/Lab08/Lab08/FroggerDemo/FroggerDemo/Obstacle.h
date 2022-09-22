/**********************************************************************************
// Obstacle (Arquivo de Cabe�alho)
// 
// Cria��o:     19 Dez 2012
// Atualiza��o: 14 Ago 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Obst�culos do jogo Frogger
//
**********************************************************************************/

#ifndef _FROGGER_OBSTACLE_H_
#define _FROGGER_OBSTACLE_H_

// ---------------------------------------------------------------------------------
// Inclus�es

#include "Types.h"            // tipos espec�ficos da engine
#include "Object.h"           // interface de object
#include "Sprite.h"           // interface de sprites
#include "Image.h"            // interface de image

// ---------------------------------------------------------------------------------

class Obstacle : public Object
{
private:
    Sprite * sprite;
    float vel;

public:
    Obstacle(Image * img, float speed);
    ~Obstacle();

    void Update();
    void Draw();
};

// ---------------------------------------------------------------------------------
// Fun��es Membro Inline

inline void Obstacle::Draw()
{ sprite->Draw(x,y,z); }

// ---------------------------------------------------------------------------------

#endif