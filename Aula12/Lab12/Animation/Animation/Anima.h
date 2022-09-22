/**********************************************************************************
// AnimaMax (Arquivo de Cabe�alho)
//
// Cria��o:     10 Abr 2012
// Atualiza��o: 27 Ago 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Exemplo de uso da classe Animation
//
**********************************************************************************/

#ifndef _ANIMA_H_
#define _ANIMA_H_

// ---------------------------------------------------------------------------------
// Inclus�es

#include "Explosion.h"
#include "Fire.h"
#include "Game.h"
#include "Run.h"
#include "Scene.h"
#include "Sprite.h"
#include "TileSet.h"

// ------------------------------------------------------------------------------

class Anima : public Game
{
private:
    Sprite* backg = nullptr;                // sprite de fundo

    TileSet* tilesetExplosion = nullptr;    // folha de sprites da explos�o
    TileSet* tilesetFire = nullptr;         // folha de sprites do fogo
    TileSet* tilesetRun = nullptr;         // folha de sprites do personagem correndo

    Explosion* explosion = nullptr;         // explos�o
    Fire* fire = nullptr;                   // fogo
    Run* run = nullptr;                     // personagem correndo

public:
    static Scene* scene;                // gerenciador de cena

    void Init();                        // inicializa jogo
    void Update();                      // atualiza l�gica do jogo
    void Draw();                        // desenha jogo
    void Finalize();                    // finaliza jogo
};

// ---------------------------------------------------------------------------------

#endif