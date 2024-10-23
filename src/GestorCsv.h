#ifndef GESTOR_CSV_H
#define GESTOR_CSV_H

#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <sstream>
#include <list>
#include <algorithm>
#include "Gestor.h"


using namespace std;

class GestorCsv : public Gestor
{
public:
    GestorCsv() = default;
    vector<int> leerProgramasCsv(string &ruta);
    vector<vector<string>> leerArchivoPrimera(string &rutaBase, string &ano, vector<int> &codigosSnies);
    vector<vector<string>> leerArchivoSegunda(string &rutaBase, string &ano, vector<int> &codigosSnies);
    vector<vector<string>> leerArchivo(string &rutaBase, string &ano, vector<int> &codigosSnies, int colmunaCodigoSnies);
    bool crearArchivo(string &ruta, map<int, ProgramaAcademico *> &mapadeProgramasAcademicos, vector<string> etiquetasColumnas) override;
    bool crearArchivoBuscados(string &ruta, list<ProgramaAcademico *> &programasBuscados, vector<string> etiquetasColumnas) override;
    bool crearArchivoExtra(string &ruta, vector<vector<string>> datosAImprimir) override;
};

#endif