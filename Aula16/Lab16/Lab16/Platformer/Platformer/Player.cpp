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
#include "Platformer.h"

// ---------------------------------------------------------------------------------

Player::Player()
{
    tileset = new TileSet("Resources/GravityGuy.png", 32, 48, 5, 10);
    anim = new Animation(tileset, 0.120f, true);

    // sequ�ncias de anima��o do player
    uint invert[4] = {6,7,8,9};
    uint normal[4] = {1,2,3,4};

    anim->Add(INVERTED, invert, 4);
    anim->Add(NORMAL, normal, 4);

    // cria bounding box
    BBox(new Rect(-1.0f * tileset->TileWidth() / 2.0f, 
                  -1.0f * tileset->TileHeight() / 2.0f, 
                   tileset->TileWidth() / 2.0f,
                   tileset->TileHeight() / 2.0f));
    
    // inicializa estado do player
    gravity = NORMAL;
    keyCtrl = false;    

    // posi��o inicial
    MoveTo(window->CenterX(), 24.0f, Layer::FRONT);

    // frequ�ncia inicial da m�sica
    frequency = 1.0f;
}

// ---------------------------------------------------------------------------------

Player::~Player()
{
    delete anim;
    delete tileset;    
}

// ---------------------------------------------------------------------------------

void Player::OnCollision(Object * obj)
{
    // mant�m personagem na posi��o correta em cima da plataforma
    if (gravity == NORMAL)
    {
        frequency += 0.15f * gameTime;
        MoveTo(window->CenterX(), obj->Y() - 32);
    }
    else
    {
        frequency -= 0.15f * gameTime;
        MoveTo(window->CenterX(), obj->Y() + 32);
    }

    // limita a frequ�ncia entre 0.9 e 1.1
    if (frequency > 1.1f)
    {
        frequency = 1.1f;
    }
    else if (frequency < 0.9)
    {
        frequency = 0.9f;
    }

    // modifica a frequ�ncia da m�sica
    Platformer::audio->Frequency(MUSIC, frequency);

    // ----------------------------------------------------------
    // Processa teclas pressionadas
    // ----------------------------------------------------------
    // jogador s� pode alterar a gravidade enquanto estiver
    // em cima de uma plataforma, n�o � poss�vel a mudan�a no ar

    if (keyCtrl && window->KeyDown(VK_SPACE))
    {
        keyCtrl = false;
        gravity = !gravity;

        // toca efeito sonoro 
        Platformer::audio->Play(TRANSITION);

        // tira player da plataforma para evitar 
        // detec��o de colis�o no quadro seguinte
        if (gravity == NORMAL)
            Translate(0, 12);
        else
            Translate(0 , -12);
    }
    else if (window->KeyUp(VK_SPACE))
    {
        keyCtrl = true;
    }
}

// ---------------------------------------------------------------------------------

void Player::Update()
{
    // ----------------------------------------------------
    // a��o da gravidade sobre o personagem
    // ----------------------------------------------------
    if (gravity == NORMAL)    
        Translate(0, 300 * gameTime);
    else
        Translate(0, -300 * gameTime);

    // atualiza anima��o
    anim->Select(gravity);
    anim->NextFrame();
}

// ---------------------------------------------------------------------------------