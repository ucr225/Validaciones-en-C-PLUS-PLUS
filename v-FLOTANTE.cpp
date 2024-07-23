#include <iostream>
#include <string>
#include <cmath>

using namespace std;

bool esFlotante(string cadena)
{
    float valor;
    char temp;

    if (cadena[0] == ' ' || cadena[cadena.length() - 1] == ' ' || cadena[cadena.length() - 1] == '.')
    {
        cin.clear();
        return false;
    }

    int elementosLeidos = sscanf(cadena.c_str(), "%f%c", &valor, &temp);

    float valorRedondeado = roundf(valor * 10000) / 10000;

    if ((elementosLeidos == 1 || (elementosLeidos > 1 && temp == '\n')) &&
        valor >= -999999999.0 && valor <= 999999999.0 &&
        valor == valorRedondeado)
    {
        return true;
    }
    else
    {
        cin.clear();
        return false;
    }
}

int main()
{
    string cadena;
    bool valido = false;
    float numero = 0;

    while (!valido)
    {
        cout << "Ingrese un número con decimales: ";
        getline(cin, cadena);

        if (esFlotante(cadena))
        {
            cout << "La cadena es un número flotante válido.\n";

            numero = stof(cadena);

            //cout << "El numero flotante es: " << fixed << setprecision(2) << numero << "\n";

            valido = true;
        }
        else
        {
            cout << "La cadena NO es un número flotante válido.\n";
        }
    }

    return 0;
}
