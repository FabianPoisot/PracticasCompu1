//
// Created by Fabian on 15/11/2022.
//

#ifndef CARGAELECTRICA_GRUPO_H
#define CARGAELECTRICA_GRUPO_H

#include <string>
#include <array>
class Grupo {

public:
    Grupo () {
        NombreGrupo = 1;
        pKGrupo = 1;
        CargaGrupo = 1;
    }
    Grupo (std::string Nombre, float pkGrupo, int cargaGrupo) {
        NombreGrupo = Nombre;
        pKGrupo = pkGrupo;
        CargaGrupo = cargaGrupo;
    }
    std::string getNombre();
    float getPk();
    int getCargagrupo();


private:
    std::string NombreGrupo;
    float pKGrupo;
    int CargaGrupo;
};


#endif //CARGAELECTRICA_GRUPO_H