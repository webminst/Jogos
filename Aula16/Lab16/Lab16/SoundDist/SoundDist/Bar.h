/**********************************************************************************
// Bar (Arquivo de Cabe�alho)
// 
// Cria��o:     07 Fev 2013
// Atualiza��o: 19 Set 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Barra utilizada em SoundDist
//
**********************************************************************************/

#ifndef _SOUNDDIST_BAR_H_
#define _SOUNDDIST_BAR_H_

// ---------------------------------------------------------------------------------
// Inclus�es

#include "Types.h"                  // tipos espec�ficos da engine
#include "Object.h"                 // interface de object
#include "Sprite.h"                 // interface de sprites
#include <string>                   // string da biblioteca STL
using std::string;                  // usa string sem std::

// ---------------------------------------------------------------------------------

class Bar : public Object
{
private:
    Sprite * sprite;                // sprite do objeto

public:
    Bar();                          // construtor
    ~Bar();                         // destrutor

    void Update();                  // atualiza��o do objeto
    void Draw();                    // desenho do objeto
};

// ---------------------------------------------------------------------------------

inline void Bar::Draw()
{ sprite->Draw(x, y, z); }

// ---------------------------------------------------------------------------------

#endif