/**********************************************************************************
// FPSCounter
// 
// Cria��o:     04 Mai 2014
// Atualiza��o: 10 Ago 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Ilustra utiliza��o da classe Timer e Game para controlar 
//              a taxa de atualiza��o e desenho de quadros em um jogo.
//
**********************************************************************************/

#include "Resources.h"
#include "Engine.h"
#include "Game.h"
#include "Timer.h"
#include <sstream>
using std::stringstream;

// ------------------------------------------------------------------------------

class FPSCounter : public Game
{
private:

public:
    void Init();
    void Update();
    void Draw();
    void Finalize();
};

// ------------------------------------------------------------------------------

void FPSCounter::Init()
{
}

// ------------------------------------------------------------------------------

void FPSCounter::Update()
{
    if (window->KeyDown(VK_ESCAPE))
        window->Close();
} 

// ------------------------------------------------------------------------------

void FPSCounter::Draw()
{    
} 

// ------------------------------------------------------------------------------

void FPSCounter::Finalize()
{
}


// ------------------------------------------------------------------------------
//                                  WinMain                                      
// ------------------------------------------------------------------------------

int APIENTRY WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, 
                     _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
    // <------------ Inicio da medi��o ---------------------
    Timer t;
    t.Start();
    // cria engine
    Engine * engine = new Engine();

    // configura a janela
    engine->window->Mode(WINDOWED);
    engine->window->Size(960, 540);
    engine->window->Color(240, 240, 140);
    engine->window->Title("FPSCounter");
    engine->window->Icon(IDI_ICON);
    engine->window->Cursor(IDC_CURSOR);

    // configura dispositivo gr�fico
    engine->graphics->VSync(true);

    float tempoTranscorrido = t.Elapsed();
    stringstream texto;
    texto << "Tempo decorrido: " << tempoTranscorrido << "\n";
    OutputDebugString(texto.str( ).c_str());
    // <------------ Fim da medi��o --------------------------
    // inicia o jogo
    int status = engine->Start(new FPSCounter());
    
    // destr�i a engine  
    delete engine;
    return status;
}

// ----------------------------------------------------------------------------

