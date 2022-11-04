//
// Created by Fabian on 03/11/2022.
//

#include <array>
#include <cmath>
#ifndef PUNTOS_PUNTO_H
#define PUNTOS_PUNTO_H

#include <iostream>
#include <array>


class Punto2D {
public:
    void SetPosicion(float x, float y);
    void Trasladar(float temp1, float temp2);
    void RotarRespectoAlOrigen(float temp1);
    void Escalar(float temp1, float temp2);
    float GetX();
    float GetY();

private:
    std::array <float, 2> Posicion {};
    std::array < std::array <float,2>, 2> Operacion {};

};

#endif //PUNTOS_PUNTO_H