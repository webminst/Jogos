/**********************************************************************************
// Player (C�digo Fonte)
// 
// Cria��o:     20 Abr 2012
// Atualiza��o: 02 Set 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Define uma classe para o jogador
//
**********************************************************************************/

#include "Player.h"

// ---------------------------------------------------------------------------------

Player::Player()
{
    tileset = new TileSet("Resources/GravityGuy.png", 32, 48, 5, 10);
    anim = new Animation(tileset, 0.120f, true);

    uint sequenceNormal[4] = { 1, 2, 3, 4 };
    uint sequenceInvert[4] = { 6, 7, 8, 9 };

    anim->Add(INVERTED, sequenceInvert, 4);
    anim->Add(NORMAL, sequenceNormal, 4);

    bbox = new Rect(-1.0f * tileset->TileWidth() / 2.0f,
                    -1.0f * tileset->TileHeight() / 2.0f,
                    +1.0f * tileset->TileWidth() / 2.0f,
                    +1.0f * tileset->TileHeight() / 2.0f);

    MoveTo(window->CenterX(), 24.0f, 0.0f);
}

// ---------------------------------------------------------------------------------

Player::~Player()
{
    delete tileset;
    delete anim;
    delete bbox;
}

// ---------------------------------------------------------------------------------

void Player::OnCollision(Object * obj)
{
    // mant�m personagem na posi��o correta em cima da plataforma
    if (gravity == NORMAL)
        MoveTo(window->CenterX(), obj->Y() - 32);
    else
        MoveTo(window->CenterX(), obj->Y() + 32);

    // jogador s� pode alterar a gravidade enquanto estiver
    // em cima de uma plataforma, n�o � poss�vel a mudan�a no ar
    if (keyCtrl && window->KeyDown(VK_SPACE))
    {
        keyCtrl = false;
        gravity = !gravity;
        anim->Select(gravity);

        // tira player da plataforma para evitar
        // detec��o de colis�o no quadro seguinte
        if (gravity == NORMAL)
            Translate(0, 12);
        else
            Translate(0, -12);
    }
    else if (window->KeyUp(VK_SPACE))
    {
        keyCtrl = true;
    }
}

// ---------------------------------------------------------------------------------

void Player::Update()
{
    anim->NextFrame();

    // a��o da gravidade sobre o personagem
    if (gravity == NORMAL)
        Translate(0, 300 * gameTime);
    else
        Translate(0, -300 * gameTime);
}

// ---------------------------------------------------------------------------------