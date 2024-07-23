#include <iostream>
#include <string>
#include <cctype>

using namespace std;

bool esEntero(string cadena)
{
    int menos = 0;
    int longitud = cadena.length();
    int soloCeros = 1;

    if (longitud == 0 || cadena[0] == '\0')
    {
        cout << "ESTIMADO USUARIO, NO INGRESO NINGUN VALOR! \n";
        cin.clear();
        return false;
    }

    if (cadena[0] == '-')
    {
        menos++;
    }

    for (int i = menos; i < longitud; i++)
    {
        if (longitud == 1 && cadena[i] == '0')
        {
            return true;
        }

        if (!isdigit(cadena[i]) || (cadena[0] == '0' && menos == 0) || longitud > 9 || cadena[0] == ' ' || cadena[longitud - 1] == ' ' || longitud == 0 || menos > 1)
        {
            cin.clear();
            return false;
        }
    }

    return true;
}

int main()
{
    bool valido = false;
    string cadena;

    while (!valido)
    {
        cout << "Ingrese un numero de maximo 9 digitos: ";
        getline(cin, cadena);

        if (esEntero(cadena))
        {
            cout << "Los datos ingresados numeros son enteros.\n";

            long long int numero = stoll(cadena); // enteros MUCHO mas grandes
            cout << " El numero es: " << numero << "\n";

            valido = true; // como es valido el valor cambia entonces ya no se vuelve a pedir la cadena
        }
        else
        {
            cout << "NO valido, por favor ingrese su numero entero sin ceros al inicio/un numero mas corto/un numeros sin decimales\n";
            cin.clear();
        }
    }

    return 0;
}
