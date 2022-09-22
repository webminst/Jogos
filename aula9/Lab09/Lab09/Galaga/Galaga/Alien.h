/**********************************************************************************
// Alien (Arquivo de Cabe�alho)
// 
// Cria��o:     21 Dez 2012
// Atualiza��o: 18 Ago 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Alien�gena do jogo Galaga
//
**********************************************************************************/

#ifndef _GALAGA_ALIEN_H_
#define _GALAGA_ALIEN_H_

// ---------------------------------------------------------------------------------
// Inclus�es

#include "Types.h"          // tipos espec�ficos da engine
#include "Object.h"         // interface de object
#include "Sprite.h"         // interface de sprites
#include <string>           // string da biblioteca STL
using std::string;          // usa string sem std::

// ---------------------------------------------------------------------------------

class Alien : public Object
{
private:
    Sprite * sprite;
    float vel;

public:
    Alien(string filename);
    ~Alien();

    void Update();
    void Draw();
};

// ---------------------------------------------------------------------------------

inline void Alien::Draw()
{ sprite->Draw(x,y,z); }

// ---------------------------------------------------------------------------------

#endif