/**********************************************************************************
// Engine (C�digo Fonte)
//
// Cria��o:     15 Mai 2014
// Atualiza��o: 20 Ago 2021
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

#include "Engine.h"
#include <windows.h>
#include <sstream>
using std::stringstream;

// ------------------------------------------------------------------------------
// Inicializa��o de vari�veis est�ticas da classe

Game     * Engine::game     = nullptr;        // jogo em execu��o
Window   * Engine::window   = nullptr;        // janela do jogo
Graphics * Engine::graphics = nullptr;        // dispositivo gr�fico

// -------------------------------------------------------------------------------

Engine::Engine()
{
    window     = new Window();
    graphics   = new Graphics();
}

// -------------------------------------------------------------------------------

Engine::~Engine()
{
    delete game;
    delete graphics;
    delete window;
}

// -----------------------------------------------------------------------------

int Engine::Start(Game * level)
{
    game = level;

    // cria janela do jogo
    if (!window->Create())
    {
        MessageBox(nullptr, "Falha na cria��o da janela", "Engine", MB_OK);
        return EXIT_FAILURE;
    }

    // inicializa dispositivo gr�fico
    if (!graphics->Initialize(window))
    {
        MessageBox(window->Id(), "Falha na inicializa��o do dispositivo gr�fico", "Engine", MB_OK);
        return EXIT_FAILURE;
    }

    return Loop();
}

// -------------------------------------------------------------------------------

int Engine::Loop()
{
    // inicializa��o do jogo
    game->Init();

    // mensagens do Windows
    MSG  msg = { 0 };

    // la�o principal do jogo
    do
    {
        // testa se tem mensagem do windows para tratar
        if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        else
        {            
            // atualiza��o do jogo 
            game->Update();

            // limpa a tela para o pr�ximo quadro
            graphics->Clear();

            // desenha o jogo
            game->Draw();

            // apresenta o jogo na tela (troca backbuffer/frontbuffer)
            graphics->Present();
            
            // controle de FPS (quebra galho)
            Sleep(16); 
        }

    } while (msg.message != WM_QUIT);

    // finaliza��o do jogo
    game->Finalize();

    // encerra aplica��o
    return int(msg.wParam);
}

// -----------------------------------------------------------------------------
