#ifndef SNIES_CONTROLLER_H
#define SNIES_CONTROLLER_H
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <list>
#include "ProgramaAcademico.h"
#include "Consolidado.h"
#include "Gestor.h"
#include "GestorCsv.h"
#include "GestorJson.h"
#include "GestorTXT.h"
#include "Settings.h"

using namespace std;

class SNIESController
{

private:
    map<int, ProgramaAcademico *> programasAcademicos;
    GestorCsv gestorCsvObj;
    vector<string> etiquetasColumnas;
    string rutaProgramasCSV;
    string rutaAdmitidos;
    string rutaGraduados;
    string rutaInscritos;
    string rutaMatriculados;
    string rutaMatriculadosPrimerSemestre;
    string rutaOutput;

public:
    SNIESController();
    ~SNIESController();
    void procesarDatosCsv(string &, string &);
    void calcularDatosExtra(bool);
    void buscarProgramas(bool, string &, int);

};

#endif