/**********************************************************************************
// Scene (Arquivo de Cabe�alho)
// 
// Cria��o:     16 Mar 2012
// Atualiza��o: 18 Ago 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Define uma classe para gerenciar o cen�rio do jogo.
//                
//              Um gerenciador de cena � respons�vel por guardar os objetos 
//              da cena, atualizando-os e desenhando-os de forma mais pr�tica. 
//              Ele pode ser usado tamb�m para percorrer a lista de objetos para 
//              realizar algum processamento individual nos objetos.
//
**********************************************************************************/

#ifndef _PROGJOGOS_SCENE_H_
#define _PROGJOGOS_SCENE_H_

// ---------------------------------------------------------------------------------
// Inclus�es

#include <list>                         // lista da biblioteca SLT 
using std::list;                        // acessa list sem precisar do std::
class Object;                           // declara��o avan�ada

// ---------------------------------------------------------------------------------

class Scene
{
private:
    list <Object*> objects;             // lista de objetos 
    list <Object*>::iterator next;      // iterador para pr�ximo elemento da lista
    list <Object*>::iterator it;        // iterador para elemento atual
    
public:
    Scene();                            // construtor
    ~Scene();                           // destrutor da cena

    void Add(Object * obj);             // adiciona um objeto a lista
    void Update();                      // atualiza todos os objetos da cena
    void Draw();                        // desenha todos os objetos da cena
    
    void Begin();                       // inicia percurso na lista de objetos
    Object * Next();                    // retorna pr�ximo objeto da lista
    void Remove();                      // remove �ltimo objeto retornado por Next()
};

// ---------------------------------------------------------------------------------

#endif