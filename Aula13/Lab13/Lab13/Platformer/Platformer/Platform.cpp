/**********************************************************************************
// Platform (C�digo Fonte)
// 
// Cria��o:     21 Abr 2012
// Atualiza��o: 02 Set 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Plataformas do jogo
//
**********************************************************************************/

#include "Platform.h"

// ---------------------------------------------------------------------------------

Platform::Platform(float posX, float posY, uint platType)
{
    if (platType == SMALL)
    {
        platform = new Sprite("Resources/SmallGray.png");
    }
    else if (platType == MEDIUM)
    {
        platform = new Sprite("Resources/MediumGray.png");
    }
    else
    {
        platform = new Sprite("Resources/LongGray.png");
    }

    bbox = new Rect(-1.0f * platform->Width() / 2.0f,
                    -1.0f * platform->Height() / 2.0f,
                    +1.0f * platform->Width() / 2.0f,
                    +1.0f * platform->Height() / 2.0f);

    MoveTo(posX, posY);
}

// ---------------------------------------------------------------------------------

Platform::~Platform()
{
    delete platform;
}

// -------------------------------------------------------------------------------

void Platform::Update()
{
    Translate(-200.0f * gameTime, 0);
}

// -------------------------------------------------------------------------------
