/**********************************************************************************
// Ball (Arquivo de Cabe�alho)
// 
// Cria��o:     22 Dez 2012
// Atualiza��o: 18 Ago 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Bola do jogo Breakout
//
**********************************************************************************/

#include "Ball.h"

// ---------------------------------------------------------------------------------

Ball::Ball(Player* p)
{
	sprite = new Sprite("Resources/Ball.png");
	player = p;

	startGame = false;

	velocidadeX = -200.0f;
	velocidadeY = -200.0f;

	// Posi��o inicial da bola
	MoveTo(player->x + (player->tamanhoX / 2) - (sprite->Width() / 2), player->y - sprite->Height());
}

Ball::~Ball()
{
	delete sprite;
}

// ---------------------------------------------------------------------------------

void Ball::Update()
{
	// Detecta pressionamento da barra de espa�o
	if (window->KeyDown(VK_SPACE))
	{
		startGame = true;
	}

	// Se o jogo come�ar
	if (startGame)
	{
		// Desloca a bola pela janela
		Translate(velocidadeX * gameTime, velocidadeY * gameTime);
	}
	else
	{
		// Movimenta a bola sobre o jogador
		MoveTo(player->x + (player->tamanhoX / 2) - (sprite->Width() / 2), player->y - sprite->Height());
	}

	// Mant�m a bola dentro da janela
	if (x < 0)
	{
		velocidadeX = -velocidadeX;
	}
	if (x + sprite->Width() > window->Width())
	{
		velocidadeX = -velocidadeX;
	}
	if (y < 0)
	{
		velocidadeY = -velocidadeY;
	}
	if (y + sprite->Height() > window->Height())
	{
		velocidadeY = -velocidadeY;
	}
}

void Ball::Draw()
{
	sprite->Draw(x, y, z);
}

// ---------------------------------------------------------------------------------
