/**********************************************************************************
// Ball (Arquivo de Cabe�alho)
// 
// Cria��o:     22 Dez 2012
// Atualiza��o: 02 Set 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Bola do jogo Breakout
//
**********************************************************************************/

#include "Ball.h"
#include "Block.h"
#include "Breakout.h"

// ---------------------------------------------------------------------------------

Ball::Ball(Player * p)
{
    // guarda jogador
    player = p;

    // tamanho da bola � 12x12
    //BBox(new Rect(0, 0, 11, 11));
    
    // bounding box alternativa: experimente  
    //usar o c�rculo no lugar do ret�ngulo
    BBox(new Circle(6));

    // cria sprite da bola
    sprite  = new Sprite("Resources/Ball.png");

    // tamanho do player � 100x20
    MoveTo(player->X() + 50.0f - sprite->Width()/2.0f, 
           player->Y() - sprite->Height() - 2.0f, 
           Layer::FRONT);

    // velocidades iniciais
    velX = 300.0f;
    velY = -300.0f;

    // tipo do objeto
    type = BALL;
}

// ---------------------------------------------------------------------------------

Ball::~Ball()
{
    delete sprite;
}

// ---------------------------------------------------------------------------------

void Ball::OnCollision(Object * obj)
{
    // bola colide com bloco
    if (obj->Type() == BLOCK)
        Breakout::scene->Delete(obj, STATIC);

    // experimente deixar o bloco cair em vez de remov�-lo da cena
    //    ((Block*) obj)->velY = 200.0f;



}

// ---------------------------------------------------------------------------------

void Ball::Update()
{
    if (player->state == PLAYING)
    {
        Translate(velX * gameTime, velY * gameTime);

        // se o jogador n�o rebater, a bola � reiniciada
        if (y + sprite->Height() > window->Height())
            player->state = STOPED;
    }
    else
    {
        // mova para posi��o acima do player e o acompanhe
        MoveTo(player->X() + 50.0f - sprite->Width() / 2.0f, player->Y() - sprite->Height() - 2.0f, Layer::FRONT);
    }
        

    // mant�m a bola dentro da tela (tam. da bola: 12x12)
    if (x < 0)
    {
        MoveTo(0.0f, y);
        velX = -velX;
    }
    if (x + sprite->Width() > window->Width())
    {
        MoveTo(float(window->Width() - sprite->Width()), y);
        velX = -velX;
    }
    if (y < 0)
    {
        MoveTo(x, 0.0f);
        velY = -velY;
    }
    if (y + sprite->Height() > window->Height())
    {
        MoveTo(x, float(window->Height() - sprite->Height()));
        velY = -velY;
    }
}

// ---------------------------------------------------------------------------------
