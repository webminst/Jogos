/**********************************************************************************
// Engine (Arquivo de Cabe�alho)
//
// Cria��o:     15 Mai 2014
// Atualiza��o: 08 Ago 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   A fun��o da Engine � rodar jogos criados a partir da classe
//              abstrata Game. Todo jogo deve ser uma classe derivada de Game
//              e portanto deve implementar as fun��es membro Init, Update, Draw
//              e Finalize, que ser�o chamadas pelo motor em um la�o de tempo real.
//              Para usar a classe Engine, o programador deve criar uma inst�ncia
//              e chamar o m�todo Start(), passando um objeto derivado de Game.
//
**********************************************************************************/

#ifndef _PROGJOGOS_ENGINE_H_
#define _PROGJOGOS_ENGINE_H_

// ---------------------------------------------------------------------------------

#include "Game.h"                      // implementa��o do jogo
#include "Window.h"                    // janela do jogo
#include "Graphics.h"                  // hardware gr�fico

// ---------------------------------------------------------------------------------

class Engine
{
private:
    int Loop();                        // inicia la�o principal do jogo

public:
    static Game     * game;            // jogo a ser executado
    static Window   * window;          // janela do jogo
    static Graphics * graphics;        // dispositivo gr�fico

    Engine();                          // construtor
    ~Engine();                         // destrutor

    int Start(Game* level);            // inicia a execu��o do jogo
};

// ---------------------------------------------------------------------------------

#endif