/**********************************************************************************
// InputKeys
// 
// Cria��o:     12 Abr 2014
// Atualiza��o: 25 Jul 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Demonstra como usar a Window Procedure para capturar o  
//              pressionamento e a libera��o de teclas e assim poder us�-las 
//              para controlar o jogo.
//
**********************************************************************************/

// inclui tipos b�sicos e fun��es da API Win32
#define WIN32_LEAN_AND_MEAN
#include <windows.h>                    // inclui fun��es do windows
#include <windowsx.h>                   // inclui fun��es extras do windows
#include "Resources.h"                  // defini��es dos recursos utilizados

//--------------------------------------------------------------------------------
// constantes e vari�veis globais

int windowWidth = 800;                  // largura da janela
int windowHeight = 300;                 // altura da janela
bool fullScreen = false;                // tela cheia ou modo janela

const unsigned MaxInputLength = 64;     // tamanho m�ximo do texto
char msg[MaxInputLength] = { 0 };       // mensagem do sistema
bool vkKeys[256] = { 0 };               // estado das teclas

//--------------------------------------------------------------------------------

// prot�tipo do procedimento da janela
LRESULT CALLBACK WinProc (HWND, UINT, WPARAM, LPARAM);

//--------------------------------------------------------------------------------

// programa principal
int APIENTRY WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
     HWND         hwnd;                // identificador da janela
     MSG          msg;                 // mensagem
     WNDCLASS     wndclass;            // classe da janela

     // definindo uma classe de janela chamada "GameWindow" 
     wndclass.style = CS_HREDRAW | CS_VREDRAW;
     wndclass.lpfnWndProc = WinProc;
     wndclass.cbClsExtra = 0;
     wndclass.cbWndExtra = 0;
     wndclass.hInstance = hInstance;
     wndclass.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON));
     wndclass.hCursor = LoadCursor(hInstance, MAKEINTRESOURCE(IDC_CURSOR));
     wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
     wndclass.lpszMenuName = NULL;
     wndclass.lpszClassName = "GameWindow";

     // Registrando a classe "GameWindow"
     if (!RegisterClass(&wndclass))
     {
         MessageBox(NULL, "Erro na cria��o da janela!", "Game", MB_ICONERROR);
         return 0;
     }

     int windowStyle = WS_OVERLAPPED | WS_SYSMENU;

     // tela cheia ou janela
     if (fullScreen)
     {
         windowWidth = GetSystemMetrics(SM_CXSCREEN);
         windowHeight = GetSystemMetrics(SM_CYSCREEN);
         windowStyle = WS_POPUP;
     }

     // criando uma janela baseada na classe "GameWindow"
     // � necess�rio usar CreateWindowEx para usar AdjustWindowRectEx
     hwnd = CreateWindowEx(
         NULL,                              // estilos extras
         "GameWindow",                      // nome da "window class"
         "Keyboard Input",                  // t�tulo da janela
         windowStyle,                       // estilo da janela
         CW_USEDEFAULT,                     // posi��o x inicial
         CW_USEDEFAULT,                     // posi��o y inicial
         windowWidth,                       // largura da janela
         windowHeight,                      // altura da janela
         NULL,                              // identificador do objeto pai
         NULL,                              // identificador do menu
         hInstance,                         // identificador da aplica��o
         NULL);                             // par�metros de cria��o

     if (!fullScreen)
     {
         // ret�ngulo com o tamanho da �rea cliente desejada
         RECT winRect = { 0, 0, windowWidth, windowHeight };

         // ajuste do tamanho da janela
         AdjustWindowRectEx(&winRect,
             GetWindowStyle(hwnd),
             GetMenu(hwnd) != NULL,
             GetWindowExStyle(hwnd));

         // atualiza posi��o da janela
         int windowPosX = GetSystemMetrics(SM_CXSCREEN) / 2 - (winRect.right - winRect.left) / 2;
         int windowPosY = GetSystemMetrics(SM_CYSCREEN) / 2 - (winRect.bottom - winRect.top) / 2;

         // redimensiona janela com uma chamada a MoveWindow
         MoveWindow(
             hwnd,                          // identificador da janela
             windowPosX,                    // posi��o x
             windowPosY,                    // posi��o y
             winRect.right - winRect.left,  // largura
             winRect.bottom - winRect.top,  // altura
             TRUE);                         // repintar
     }

     // mostra e atualiza a janela
     ShowWindow(hwnd, nCmdShow);
     UpdateWindow(hwnd);
     
     // Tratamento de mensagens destinadas a janela da aplica��o
     while (GetMessage(&msg, NULL, 0, 0))
     {
          TranslateMessage(&msg);
          DispatchMessage(&msg);
     }

     // fim do programa
     return int(msg.wParam);
}

//-------------------------------------------------------------------------------

// procedimento da janela
LRESULT CALLBACK WinProc (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
     HDC         hdc;       // representa o dispositivo gr�fico
     PAINTSTRUCT ps;        // guarda regi�o invalidada da janela
     RECT        rect;      // regi�o ret�ngular
     
     switch (message)
     {
     // janela perdeu o foco
     case WM_KILLFOCUS:
         strcpy_s(msg, MaxInputLength, "Volte Logo!");
         InvalidateRect(hwnd, NULL, TRUE);
         return 0;

     // janela recebeu o foco
     case WM_SETFOCUS:
         strcpy_s(msg, MaxInputLength, "Bem vindo!");
         InvalidateRect(hwnd, NULL, TRUE);
         return 0;

     // processa teclas pressionadas
     case WM_KEYDOWN:
         vkKeys[wParam] = true;
         InvalidateRect(hwnd, NULL, TRUE);           
         return 0;

     // processa teclas liberadas
     case WM_KEYUP:
         vkKeys[wParam] = false;
         InvalidateRect(hwnd, NULL, TRUE);          
         return 0;

     case WM_PAINT:
         hdc = BeginPaint(hwnd, &ps);
         GetClientRect(hwnd, &rect);

         if (vkKeys[VK_CONTROL])
             DrawText(hdc, "CTRL", -1, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
         if (vkKeys[VK_LEFT])
             DrawText(hdc, "LEFT", -1, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
         if (vkKeys[VK_RIGHT])
             DrawText(hdc, "RIGHT", -1, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
         if (vkKeys[VK_UP])
             DrawText(hdc, "UP", -1, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
         if (vkKeys[VK_DOWN])
             DrawText(hdc, "DOWN", -1, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
         if (vkKeys[VK_ESCAPE])
             DrawText(hdc, "ESC", -1, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
         if (vkKeys[VK_RETURN])
             DrawText(hdc, "ENTER", -1, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
         if (vkKeys[VK_SPACE])
             DrawText(hdc, "SPACE", -1, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);

         rect.bottom -= 100;
         DrawText(hdc, msg, -1, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
         EndPaint(hwnd, &ps);
         return 0;
          
     case WM_DESTROY:
         PostQuitMessage(0);
         return 0;
     }
     return DefWindowProc(hwnd, message, wParam, lParam);
}

//-------------------------------------------------------------------------------