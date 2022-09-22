/**********************************************************************************
// Object (C�digo Fonte)
//
// Cria��o:     01 Out 2007
// Atualiza��o: 14 Ago 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Essa � a classe base para todos objetos do jogo.
//
//              Um objeto do jogo � qualquer coisa que poss�mos querer desenhar
//              ou interagir dentro do jogo. Por exemplo, um soldado, um pr�dio,
//              um proj�til, uma forma geom�trica, etc.
//
**********************************************************************************/

#include "Object.h"
#include "Engine.h"

// -------------------------------------------------------------------------------
// Inicializa��o de vari�veis est�ticas da classe

Window* & Object::window   = Engine::window;           // ponteiro para a janela
float   & Object::gameTime = Engine::frameTime;        // tempo do �ltimo quadro

// -------------------------------------------------------------------------------

Object::Object() : x(0.0f), y(0.0f), z(0.5f)
{
}

// -------------------------------------------------------------------------------

Object::~Object()
{
}

// -------------------------------------------------------------------------------