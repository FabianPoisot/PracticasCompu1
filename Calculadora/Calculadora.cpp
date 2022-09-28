#include <iostream>


//Fabián Poisot Palacios 27 de septiembre del 2022
//UNAM ENES Juriquilla

using namespace std;

int main()
{
    // Se definen las variables. Dos números y un caracter. 
    float numero1 = 0, numero2 = 0, resultado = 0;
    char operacion = 'a';
    
    // Se imprime el mensaje de salida. 
    cout << "$ ./ Calculadora \n \n";
    cout << "Este programa hace operaciones basicas entre dos numeros.\n";
    
    // Se le pide al usuario que escriba las variables y se guardan
    cout << "Primer numero: ";
    cin >> numero1;
    
    cout << "Operacion: ";
    cin >> operacion;
    
    cout << "Segundo numero: ";
    cin >> numero2;
    
    cout << "\n";
    
    // Se escriben las condicionales para realizar la operación deseada.
    
    if (operacion == '+'){
        resultado = numero1 + numero2;
    } 
    else if (operacion == '-'){
        resultado = numero1 - numero2;
    }
    else if (operacion == '*'){
        resultado = numero1 * numero2;
    }
    else if (operacion == '/'){
        resultado = numero1 / numero2;
    }
    else if (operacion == '%'){
        resultado = (int)numero1 % (int)numero2;
    }
    
    // Se imprime la operación solicitada.
    cout << "Resultado: \n";
    cout << numero1 << " " << operacion << " " << numero2 << " = " << resultado;
    
    return 0;
}
