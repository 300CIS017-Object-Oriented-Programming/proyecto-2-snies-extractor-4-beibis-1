#ifndef GESTOR_JSON_H
#define GESTOR_JSON_H

#include "Gestor.h"
#include <fstream>

using namespace std;

class GestorJson : public Gestor
{
public:
    GestorJson() = default;
    bool crearArchivo(string &ruta, map<int, ProgramaAcademico *> &mapadeProgramasAcademicos, vector<string> &etiquetasColumnas) override;
    bool crearArchivoBuscados(string &ruta, list<ProgramaAcademico *> &programasBuscados, vector<string> &etiquetasColumnas) override;
    bool crearArchivoExtra(string &ruta, vector<vector<string>> &datosAImprimir) override;
};

#endif
