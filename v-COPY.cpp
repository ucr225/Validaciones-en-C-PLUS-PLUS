#include <iostream>
#include <csignal>

using namespace std;

int main() 
{ 
    // Se ignora la señal, se escribe eso
    signal(SIGINT, SIG_IGN); 

    cout << "Presiona CTRL+C para que veas que no puedes salir del programa\n"; 

    while(true) ; 

    return 0; 
} 
