/**********************************************************************************
// Sound Distance (Arquivo de Cabe�alho)
// 
// Cria��o:     14 Out 2011
// Atualiza��o: 19 Set 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Ajusta volume pela dist�ncia do som
//
**********************************************************************************/

#ifndef _SOUNDDIST_H_
#define _SOUNDDIST_H_

// ------------------------------------------------------------------------------

#include "Game.h"
#include "Font.h"
#include "Audio.h"
#include "Scene.h"
#include "Sprite.h"
#include "Player.h"
#include "Bar.h"
#include "Resources.h"
#include <sstream>
using std::stringstream;

// ------------------------------------------------------------------------------

enum Sounds {PULSE, EXPLOSION};

// ------------------------------------------------------------------------------

class SoundDist : public Game
{
private:
    Sprite * backg = nullptr;       // background do jogo

    bool keyCtrl  = false;          // controle de teclas    
    bool viewBBox = false;          // visualiza bounding box

public:
    static Audio * audio;           // sistema de �udio    
    static Scene * scene;           // cema do jogo

    void Init();                    // inicializa jogo
    void Update();                  // atualiza l�gica do jogo
    void Draw();                    // desenha jogo
    void Finalize();                // finaliza jogo
};

// ------------------------------------------------------------------------------

#endif