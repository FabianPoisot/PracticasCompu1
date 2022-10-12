#include <iostream>
#include <array>

// Añadir std para fácil llamado de funciones
using namespace std;

//// Declaración de funciones
//Definimos un template (un tipo de dato) para nuestra matriz
template <typename matriz>
void LlenarMatriz(matriz & miMatriz);

template <typename matriz>
void ImprimirMatriz(matriz & miMatriz);

template <typename matriz>
void GaussJordan(matriz & miMatriz);

template <typename matriz>
void ImprimirSolucion(matriz & miMatriz);


int main()
{
    // Definimos el número de variables de nuestro sistema
    const int variables = 3;
    // El número de columnas será el número de variables más su solición para cada ecuación
    const int columnas = variables + 1;

    // Inicializamos la matriz que vamos a ocupar
    array <array<float, columnas>, variables> miMatriz = { 0 };

    // Pedimos al usuario que llene la matriz
    LlenarMatriz(miMatriz);

    // Aplicamos el método de Gauss-Jordan sobre nuestra matriz
    GaussJordan(miMatriz);

    // Imprimimos la solución de la matriz
    ImprimirSolucion(miMatriz);

    return 0; // Indicamos que salimos del programa con éxito
}

/*
Llena 'miMatriz' con valores ingresados por el usuario para cada elemento.
No regresa ningún valor.
*/
template <typename matriz>
void LlenarMatriz(matriz & miMatriz)
{
    int variables = miMatriz.size();
    for (int i = 0; i < variables; i++) {
        for (int j = 0; j <= variables; j++) {
            cout << "Valor elemento [" << i << "][" << j << "]: ";
            cin >> miMatriz[i][j];
        }
    }
}

/*
Imprime cada elemento de 'miMatriz' emulando una matriz con corchetes cuadrados.
No regresa ningún valor.
*/
template <typename matriz>
void ImprimirMatriz(matriz & miMatriz)
{
    int variables = miMatriz.size();
    for (int i = 0; i < variables; i++) {
        cout << "[ ";
        for (int j = 0; j < variables + 1; j++)
            cout << miMatriz[i][j] << '\t';
        cout << "]\n";
    }
}

/*
Imprime en pantalla la solución para cada variable del sistema de ecuaciones correspondiente a los valores en 'miMatriz'.
No regresa ningún valor.
*/
template <typename matriz>
void ImprimirSolucion(matriz & miMatriz)
{
    // Creamos un Array del número de filas que tenemos
    const int variables = 3;
    array <float, variables> Resultados = { 0 };
    for (int i = 0; i < miMatriz.size(); i++) {
        Resultados[i]= miMatriz[i][miMatriz.size()];
        if (miMatriz[i][i] == 0){
            if (miMatriz[i][miMatriz.size()] == 0){
                cout << "\n" << "Hay infinitas soluciones";
                return;
            }
            else cout << "\n" << "No hay solucion al sistema";
            return;
        }
    }
    // Imprimimos las soluciones
    cout << "\n" << "Solución:" << "\n";
    for (int i = 0; i < miMatriz.size(); i++) {
        cout << "x" << i << " = " << Resultados[i] << "\n";
    }

}

/*
Implementa el algoritmo de Gauss-Jordan sobre 'miMatriz', finalizando en ella la solución del algoritmo.
No regresa ningún valor.
*/
template <typename matriz>
void GaussJordan(matriz & miMatriz)
{
    // Declaramos tres variables como apoyo para la suma de filas y cambiarlas de ser necesario.
    int fila =1;
    float temp = 0;
    int sumafila = 0;
    for (int i = 0; i < miMatriz.size() ; i++) {
        fila = 1;
        // Si nuestro pivote es 0 cambiamos las filas
        while (miMatriz[i][i] == 0 && fila < miMatriz.size()){
            for (int j = 0; j <= miMatriz.size(); j++) {
                temp = miMatriz[i][j];
                miMatriz[i][j] = miMatriz[fila][j];
                miMatriz[fila][j] = temp;
            }
            fila ++;
        }
        // Si todas las filas tienen pivote = 0 se pasa al siguiente pivote
        if (fila == miMatriz.size() ){
            continue;
        }

        temp = miMatriz[i][i];
        // Dividimos toda la fila entre el valor del pivote
        for (int j = i; j <= miMatriz.size(); j++) {
            miMatriz[i][j] = (miMatriz[i][j]/temp);
        }
        sumafila = 0;
        // Sumamos a cada fila para obtener ceros arriba y abajo de nuestro pivote.
        for (int j = 0; j < (miMatriz.size() - 1); j++) {
            sumafila +=1;
            temp = miMatriz[(i+sumafila) % miMatriz.size()][i];
            if (temp != 0){
                for (int k = i; k <= miMatriz.size() ; k++) {
                    miMatriz[((i+sumafila) % miMatriz.size())][k] += -1*temp*miMatriz[i][k];
                }
            }

        }

    }

}