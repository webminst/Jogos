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

#include "Alien.h"

// ---------------------------------------------------------------------------------

Alien::Alien(string filename)
{
    sprite = new Sprite(filename);
    vel = 80.0f;
}

// ---------------------------------------------------------------------------------

Alien::~Alien()
{
    delete sprite;
}

// ---------------------------------------------------------------------------------

void Alien::Update()
{
    // desloca alien
    x += vel * gameTime;

    // mant�m os alien�genas dentro da janela
    // tamanho das imagens � 28x30

    // alien saindo pela esquerda
    if (x + sprite->Width() < 0)
        x = float(window->Width());

    // alien saindo pela direita
    if (x > window->Width())
        x = float(-sprite->Width());
}

// ---------------------------------------------------------------------------------
