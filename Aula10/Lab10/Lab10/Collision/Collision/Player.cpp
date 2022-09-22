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

#include "Breakout.h"
#include "Player.h"
#include "Ball.h"

// ---------------------------------------------------------------------------------

Player::Player()
{
    // tamanho do player � 100x20
    //BBox(new Rect(0, 0, 99, 19));

    // bounding box alternativa: experimente usar 
    // uma combina��o de ret�ngulos e c�rculos

    Mixed * mixed = new Mixed();
    //
    Circle * cLeft = new Circle(10.0f);
    cLeft->MoveTo(0.0f, 0.0f);

    Circle * cRight = new Circle(10.0f);
    cRight->MoveTo(80.0f, 0.0f);

    Rect * rect = new Rect(0.0f, 0.0f, 80.0f, 20.0f);
    rect->MoveTo(10, 0);
    //
    mixed->Insert(cLeft);
    mixed->Insert(cRight);
    mixed->Insert(rect);
    //
    BBox(mixed);

    // sprite do jogador
    sprite = new Sprite("Resources/Player.png");

    // centraliza o jogador
    MoveTo(window->CenterX() - sprite->Width() / 2.0f, 
           window->Height() - 30.0f, 
           Layer::FRONT);

    // velocidade do jogador
    vel = 500; 

    // estado inicial do jogo
    state = STOPED;

    // tipo do objeto
    type = PLAYER;

}

// ---------------------------------------------------------------------------------

Player::~Player()
{
    delete sprite;
}

// ---------------------------------------------------------------------------------

void Player::OnCollision(Object * obj)
{
    // bola colidiu com o player
    if (obj->Type() == BALL)
    {
        Ball* ball = (Ball*)obj;

        // Se a bola vem da diagonal esquerda
        if ((ball->X() <= X()) && (ball->Y() <= Y()) && (ball->velX > 0))
        {
            ball->velY = -ball->velY;
            ball->velX = -ball->velX;
        }
        // Se a bola vem da diagonal direita
        else if ((ball->X() >= (X() + sprite->Width() - ball->Width())) && (ball->Y() <= Y()) && (ball->velX < 0))
        {
            ball->velY = -ball->velY;
            ball->velX = -ball->velX;
        }
        // quando a bola bate na lateral esquerda ou direita
        else if (((ball->X() <= X()) || (ball->X() >= (X() + sprite->Width() - ball->Width()))) && (ball->Y() > Y()))
        {
            ball->velX = -ball->velX;
        }
        // Se a bola bate na superf�cie de cima ou estiver dentro do jogador
        else
        {
            ball->MoveTo(ball->X(), Y() - ball->Height() - 2.0f);
            ball->velY = -ball->velY;
        }
    }
}

// ---------------------------------------------------------------------------------

void Player::Update()
{
    // inicia o jogo com barra de espa�o
    if (state == STOPED && window->KeyDown(VK_SPACE))
        state = PLAYING;

    // desloca jogador horizontalmente
    if (window->KeyDown(VK_RIGHT))
        Translate(vel * gameTime, 0);
    if (window->KeyDown(VK_LEFT))
        Translate(-vel * gameTime, 0);

    // mant�m jogador dentro da janela (tam. da barra: 100x20)
    if (x < 0)
        MoveTo(0.0f, y);
    if (x + sprite->Width() > window->Width())
        MoveTo(float(window->Width() - sprite->Width()), y);
}

// ---------------------------------------------------------------------------------
