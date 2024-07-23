#include <iostream>
#include <string>
#include <cstring>

using namespace std;

bool esCadena(string cadena)
{
    string letras = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZáéíóúüñÁÉÍÓÚÜÑ";
    int longitud = cadena.length();

    if (longitud == 0 || cadena[0] == ' ' || cadena[longitud - 1] == ' ' || longitud > 10)
    {
        return false;
    }

    for (int i = 0; i < longitud; i++)
    {
        if (cadena[i] == ' ' && cadena[i + 1] == ' ')
        {
            return false;
        }

        if (cadena[i] == '\361' || cadena[i] == '\321') // ñ y Ñ en hexadecimal
        {
            continue;
        }

        if (letras.find(cadena[i]) == string::npos && cadena[i] != ' ')
        {
            cout << "NO VALIDO\n";
            return false;
        }
    }

    cout << "La cadena es valida.\n";
    return true;
}

int main()
{
    string cadena;
    cout << "Ingrese una cadena: ";
    getline(cin, cadena);

    while (!esCadena(cadena))
    {
        cout << "Ingrese una cadena: ";
        getline(cin, cadena);
    }

    return 0;
}
