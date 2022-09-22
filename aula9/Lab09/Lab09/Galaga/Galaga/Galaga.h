/**********************************************************************************
// Galaga (Arquivo de Cabe�alho)
//
// Cria��o:     23 Set 2011
// Atualiza��o: 18 Ago 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Usa a classe Scene para gerenciar muitos objetos na tela
//
**********************************************************************************/

#include "Game.h"
#include "Scene.h"
#include "Sprite.h"

// ------------------------------------------------------------------------------

class Galaga : public Game
{
private:
    Sprite * backg = nullptr;
    Sprite * title = nullptr;

public:
    static Scene * scene;

    void Init();
    void Update();
    void Draw();
    void Finalize();
};

// ------------------------------------------------------------------------------
