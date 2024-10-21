#ifndef GESTOR_TXT_H
#define GESTOR_TXT_H

#include "Gestor.h"
#include <fstream>

using namespace std;

class GestorTxt : public Gestor
{
public:
    GestorTxt() = default;
    bool crearArchivo(string &ruta, map<int, ProgramaAcademico *> &mapadeProgramasAcademicos, vector<string> etiquetasColumnas) override;
    bool crearArchivoBuscados(string &ruta, list<ProgramaAcademico *> &programasBuscados, vector<string> etiquetasColumnas) override;
    bool crearArchivoExtra(string &ruta, vector<vector<string>> datosAImprimir) override;
};

#endif
