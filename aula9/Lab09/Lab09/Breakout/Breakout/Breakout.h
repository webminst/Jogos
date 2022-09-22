/**********************************************************************************
// D3DBreakout (Arquivo de Cabe�alho)
//
// Cria��o:     26 Mar 2012
// Atualiza��o: 18 Ago 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Exerc�cio sobre uso da classe Scene para gerenciar objetos
//
**********************************************************************************/

#include "Game.h"
#include "Sprite.h"
#include "Scene.h"
#include "Resources.h"
#include "Player.h"
#include "Ball.h"


// ------------------------------------------------------------------------------

class Breakout : public Game
{
private:
    Sprite * backg;             // plano de fundo
    Player * player;            // jogador
    Ball * ball;                // bola

    Image * tile1;              // bloco verde
    Image * tile2;              // bloco cinza
    Image * tile3;              // bloco vermelho
    Image * tile4;              // bloco roxo
    Image * tile5;              // bloco amarelo

public:
    static Scene * scene;       // cena do jogo

    void Init();                // inicializa��o
    void Update();              // atualiza��o
    void Draw();                // desenho
    void Finalize();            // finaliza��o
};

// ------------------------------------------------------------------------------
