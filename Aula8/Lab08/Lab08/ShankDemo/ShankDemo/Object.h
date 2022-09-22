/**********************************************************************************
// Object (Arquivo de Cabe�alho)
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

#ifndef _PROGJOGOS_OBJECT_H_
#define _PROGJOGOS_OBJECT_H_

// -----------------------------------------------------------------------------

#include "Types.h"                  // usando os tipos personalizados da engine
#include "Window.h"                 // janela usada para o jogo

// -----------------------------------------------------------------------------

class Object
{
public:
    static Window* & window;        // janela do jogo 
    static float   & gameTime;      // tempo do �ltimo quadro
    float x, y, z;                  // coordenadas do objeto 

public:
    Object();                       // construtor padr�o
    virtual ~Object();              // destrutor virtual

    // ------------------------
    // fun��es virtuais    
    // ------------------------
    // podem ser sobrescritas na classe derivada
    // e chamadas corretamente mesmo usando um
    // ponteiro para a classe base

    // move o objeto por (deltaX, deltaY, deltaZ)
    virtual void Translate(float dx, float dy, float dz = 0.0f);

    // move o objeto para as coordenadas (x,y,z) indicadas
    virtual void MoveTo(float px, float py, float pz);

    // move o objeto para as coordenadas (x,y) indicadas
    virtual void MoveTo(float px, float py);

    // ------------------------
    // fun��es virtuais puras    
    // ------------------------     
    // devem ser obrigatoriamente sobrescritas na classe derivada

    // atualiza estado do objeto
    virtual void Update() = 0;

    // desenha o objeto na tela
    virtual void Draw() = 0;
};

// -----------------------------------------------------------------------------
// M�todos Inline

// move o objeto por (deltaX, deltaY, deltaZ)
inline void Object::Translate(float dx, float dy, float dz)
{ x += dx; y += dy; z += dz; }

// move o objeto para as coordenadas (x,y,z) indicadas
inline void Object::MoveTo(float px, float py, float pz)
{ x = px; y = py; z = pz; }

// move o objeto para as coordenadas (x,y) indicadas
inline void Object::MoveTo(float px, float py)
{ x = px; y = py; }

// -----------------------------------------------------------------------------

#endif


