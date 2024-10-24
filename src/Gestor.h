#ifndef GESTOR_ARCHIVOS_H
#define GESTOR_ARCHIVOS_H

#include <string>
#include <map>
#include <list>
#include <vector>
#include "ProgramaAcademico.h"
#include "Consolidado.h"
#include "Settings.h"

using namespace std;

class Gestor {
public:
    virtual bool crearArchivo(string &ruta, map<int, ProgramaAcademico *> &mapadeProgramasAcademicos, vector<string> &etiquetasColumnas) = 0;
    virtual bool crearArchivoBuscados(string &ruta, list<ProgramaAcademico *> &programasBuscados, vector<string> &etiquetasColumnas) = 0;
    virtual bool crearArchivoExtra(std::string &ruta, vector<vector<string>> &datosAImprimir) = 0;
    virtual ~Gestor() = default;
};

#endif
