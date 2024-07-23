#include <iostream>
#include <string>

using namespace std;

bool esCaracterValido(char caracter)
{
    string letras = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZáéíóúüñÁÉÍÓÚÜÑ";

    if (caracter == ' ' || caracter == '\n')
    {
        cout << "NO VALIDO\n";
        return false;
    }

    if (caracter == '\361' || caracter == '\321') // ñ y Ñ en hexadecimal
    {
        cout << "El caracter es valido.\n";
        return true;
    }

    if (letras.find(caracter) == string::npos) // find() busca el carácter actual en la cadena letras
    {
        cout << "NO VALIDO\n";
        return false;
    }

    cout << "El caracter es valido.\n";
    return true; // Retorna true solo si el caracter es una letra
}

int main()
{
    char caracter;
    bool valido;

    do
    {
        cout << "Por favor, ingresa un caracter: ";
        cin >> caracter;

        valido = esCaracterValido(caracter);
    } while (!valido); // Repite mientras el carácter no sea válido

    return 0;
}
