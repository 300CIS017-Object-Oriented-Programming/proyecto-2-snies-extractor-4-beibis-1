#include "SNIESController.h"

using namespace std;

SNIESController::SNIESController(string &nuevaRutaProgramasCSV, string &nuevaRutaAdmitidos, string &nuevaRutaGraduados, string &nuevaRutaInscritos, string &nuevaRutaMatriculadosc, string &nuevaRutaMatriculadosPrimerSemestre, string &nuevaRutaOutput)
{
    // FIXME quitar los parámetros de las rutas de los parametros del constructor, usar el archivo de settings.h para poner las constantes
    gestorCsvObj = GestorCsv();
    rutaProgramasCSV = nuevaRutaProgramasCSV;
    rutaAdmitidos = nuevaRutaAdmitidos;
    rutaGraduados = nuevaRutaGraduados;
    rutaInscritos = nuevaRutaInscritos;
    rutaMatriculados = nuevaRutaMatriculadosc;
    rutaMatriculadosPrimerSemestre = nuevaRutaMatriculadosPrimerSemestre;
    rutaOutput = nuevaRutaOutput;
}

SNIESController::~SNIESController()
{
    for (auto &pair : programasAcademicos)
    {
        ((pair).second)->~ProgramaAcademico();
        delete pair.second;
    }
}

void SNIESController::procesarDatosCsv(string &ano1, string &ano2)
{
    vector<int> codigosSnies;
    vector<vector<string>> programasAcademicosVector;
    // int posicion; //unused
    int columna;
    // cout << "antes leer programas csv" << endl;
    codigosSnies = gestorCsvObj.leerProgramasCsv(rutaProgramasCSV);
    // cout << "despues leer programas csv" << endl;
    programasAcademicosVector = gestorCsvObj.leerArchivoPrimera(rutaAdmitidos, ano1, codigosSnies);
    // cout << "despues leer archivos Primera" << endl;
    vector<string> etiquetasColumnas = programasAcademicosVector[0];
    map<string, int> columnasMap;
    for (int j = 0; j < etiquetasColumnas.size(); ++j)
    {
        columnasMap[etiquetasColumnas[j]] = j;
    }

    // Procesar los datos
    for (int i = 1; i < programasAcademicosVector.size(); i += Settings::DATOS_ACADEM_DEMOGRAF)
    {
        ProgramaAcademico *programaAcademico = new ProgramaAcademico();

        programaAcademico->setCodigoDeLaInstitucion(stoi(programasAcademicosVector[i][columnasMap["CÓDIGO DE LA INSTITUCIÓN"]]));

        programaAcademico->setIesPadre(stoi(programasAcademicosVector[i][columnasMap["IES_PADRE"]]));

        programaAcademico->setPrincipalOSeccional(programasAcademicosVector[i][columnasMap["TIPO IES"]]);

        programaAcademico->setIdSectorIes(stoi(programasAcademicosVector[i][columnasMap["ID SECTOR IES"]]));

        programaAcademico->setSectorIes(programasAcademicosVector[i][columnasMap["SECTOR IES"]]);

        programaAcademico->setIdCaracter(stoi(programasAcademicosVector[i][columnasMap["ID CARACTER"]]));

        programaAcademico->setCaracterIes(programasAcademicosVector[i][columnasMap["CARACTER IES"]]);

        programaAcademico->setCodigoDelDepartamentoIes(stoi(programasAcademicosVector[i][columnasMap["CÓDIGO DEL DEPARTAMENTO (IES)"]]));

        programaAcademico->setDepartamentoDeDomicilioDeLaIes(programasAcademicosVector[i][columnasMap["DEPARTAMENTO DE DOMICILIO DE LA IES"]]);

        programaAcademico->setCodigoDelMunicipioIes(stoi(programasAcademicosVector[i][columnasMap["CÓDIGO DEL MUNICIPIO IES"]]));

        programaAcademico->setMunicipioDeDomicilioDeLaIes(programasAcademicosVector[i][columnasMap["MUNICIPIO DE DOMICILIO DE LA IES"]]);

        programaAcademico->setCodigoSniesDelPrograma(stoi(programasAcademicosVector[i][columnasMap["CÓDIGO SNIES DEL PROGRAMA"]]));

        programaAcademico->setProgramaAcademico(programasAcademicosVector[i][columnasMap["PROGRAMA ACADÉMICO"]]);

        programaAcademico->setIdNivelAcademico(stoi(programasAcademicosVector[i][columnasMap["ID NIVEL ACADÉMICO"]]));

        programaAcademico->setNivelAcademico(programasAcademicosVector[i][columnasMap["NIVEL ACADÉMICO"]]);

        programaAcademico->setIdNivelDeFormacion(stoi(programasAcademicosVector[i][columnasMap["ID NIVEL DE FORMACIÓN"]]));

        programaAcademico->setNivelDeFormacion(programasAcademicosVector[i][columnasMap["NIVEL DE FORMACIÓN"]]);

        programaAcademico->setIdMetodologia(stoi(programasAcademicosVector[i][columnasMap["ID METODOLOGÍA"]]));

        programaAcademico->setMetodologia(programasAcademicosVector[i][columnasMap["METODOLOGÍA"]]);

        programaAcademico->setIdArea(stoi(programasAcademicosVector[i][columnasMap["ID ÁREA DE CONOCIMIENTO"]]));

        programaAcademico->setAreaDeConocimiento(programasAcademicosVector[i][columnasMap["ÁREA DE CONOCIMIENTO"]]);

        programaAcademico->setIdNucleo(stoi(programasAcademicosVector[i][columnasMap["ID NÚCLEO"]]));

        programaAcademico->setNucleoBasicoDelConocimientoNbc(programasAcademicosVector[i][columnasMap["NÚCLEO BÁSICO DEL CONOCIMIENTO (NBC)"]]);

        programaAcademico->setIdCineCampoAmplio(stoi(programasAcademicosVector[i][columnasMap["ID CINE CAMPO AMPLIO"]]));

        programaAcademico->setDescCineCampoAmplio(programasAcademicosVector[i][columnasMap["DESC CINE CAMPO AMPLIO"]]);

        programaAcademico->setIdCineCampoEspecifico(stoi(programasAcademicosVector[i][columnasMap["ID CINE CAMPO ESPECIFICO"]]));

        programaAcademico->setDescCineCampoEspecifico(programasAcademicosVector[i][columnasMap["DESC CINE CAMPO ESPECIFICO"]]);

        programaAcademico->setIdCineCodigoDetallado(stoi(programasAcademicosVector[i][columnasMap["ID CINE CODIGO DETALLADO"]]));

        programaAcademico->setDescCineCodigoDetallado(programasAcademicosVector[i][columnasMap["DESC CINE CODIGO DETALLADO"]]);

        programaAcademico->setCodigoDelDepartamentoPrograma(stoi(programasAcademicosVector[i][columnasMap["CÓDIGO DEL DEPARTAMENTO (PROGRAMA)"]]));

        programaAcademico->setDepartamentoDeOfertaDelPrograma(programasAcademicosVector[i][columnasMap["DEPARTAMENTO DE OFERTA DEL PROGRAMA"]]);

        programaAcademico->setCodigoDelMunicipioPrograma(stoi(programasAcademicosVector[i][columnasMap["CÓDIGO DEL MUNICIPIO (PROGRAMA)"]]));

        programaAcademico->setMunicipioDeOfertaDelPrograma(programasAcademicosVector[i][columnasMap["MUNICIPIO DE OFERTA DEL PROGRAMA"]]);

        // Aquí puedes continuar con las demás asignaciones

        Consolidado *consolidado[4];
        for (int m = 0; m < Settings::DATOS_ACADEM_DEMOGRAF; ++m)
        {
            consolidado[m] = new Consolidado();
            consolidado[m]->setIdSexo(stoi(programasAcademicosVector[i + m][columnasMap["ID SEXO"]]));
            consolidado[m]->setSexo(programasAcademicosVector[i + m][columnasMap["SEXO"]]);
            consolidado[m]->setAno(stoi(programasAcademicosVector[i + m][columnasMap["AÑO"]]));
            consolidado[m]->setSemestre(stoi(programasAcademicosVector[i + m][columnasMap["SEMESTRE"]]));
            consolidado[m]->setAdmitidos(stoi(programasAcademicosVector[i + m][columnasMap["ADMITIDOS"]]));
            programaAcademico->setConsolidado(consolidado[m], m);
        }

        programasAcademicos.emplace(programaAcademico->getCodigoSniesDelPrograma(), programaAcademico);
    }
    // cout << "despues crear programas academicos" << endl;
    programasAcademicosVector = gestorCsvObj.leerArchivoSegunda(rutaAdmitidos, ano2, codigosSnies);
    // cout << "despues leer archivos segunda" << endl;
    for (int j = 0; j < programasAcademicosVector.size(); j += Settings::DATOS_ACADEM_DEMOGRAF)
    {
        map<int, ProgramaAcademico *>::iterator it = programasAcademicos.find(stoi(programasAcademicosVector[j][0]));
        if (it != programasAcademicos.end())
        {
            ProgramaAcademico *programa = it->second;

            Consolidado *consolidado[4];
            for (int m = 0; m < Settings::DATOS_ACADEM_DEMOGRAF; ++m)
            {
                consolidado[m] = new Consolidado();
                consolidado[m]->setIdSexo(stoi(programasAcademicosVector[j + m][1]));
                consolidado[m]->setSexo(programasAcademicosVector[j + m][2]);
                consolidado[m]->setAno(stoi(programasAcademicosVector[j + m][3]));
                consolidado[m]->setSemestre(stoi(programasAcademicosVector[j + m][4]));
                consolidado[m]->setAdmitidos(stoi(programasAcademicosVector[j + m][5]));
                programa->setConsolidado(consolidado[m], m + 4);
            }
        }
    }
    // cout << "despues crear todos los consolidados" << endl;
    programasAcademicosVector = gestorCsvObj.leerArchivo(rutaGraduados, ano1, codigosSnies, 13);

    for (int k = 0; k < programasAcademicosVector.size(); k += Settings::DATOS_ACADEM_DEMOGRAF)
    {
        map<int, ProgramaAcademico *>::iterator it = programasAcademicos.find(stoi(programasAcademicosVector[k][0]));
        if (it != programasAcademicos.end())
        {
            ProgramaAcademico *programa = it->second;

            for (int m = 0; m < Settings::DATOS_ACADEM_DEMOGRAF; ++m)
            {
                Consolidado *consolidado = programa->getConsolidado(m);
                consolidado->setGraduados(stoi(programasAcademicosVector[k + m][1]));
            }
        }
    }

    programasAcademicosVector = gestorCsvObj.leerArchivo(rutaGraduados, ano2, codigosSnies, 13);

    for (int k = 0; k < programasAcademicosVector.size(); k += Settings::DATOS_ACADEM_DEMOGRAF)
    {
        map<int, ProgramaAcademico *>::iterator it = programasAcademicos.find(stoi(programasAcademicosVector[k][0]));
        if (it != programasAcademicos.end())
        {
            ProgramaAcademico *programa = it->second;

            for (int m = 0; m < Settings::DATOS_ACADEM_DEMOGRAF; ++m)
            {
                Consolidado *consolidado = programa->getConsolidado(m + 4);
                consolidado->setGraduados(stoi(programasAcademicosVector[k + m][1]));
            }
        }
    }

    programasAcademicosVector = gestorCsvObj.leerArchivo(rutaInscritos, ano1, codigosSnies, 12);
    for (int k = 0; k < programasAcademicosVector.size(); k += Settings::DATOS_ACADEM_DEMOGRAF)
    {
        map<int, ProgramaAcademico *>::iterator it = programasAcademicos.find(stoi(programasAcademicosVector[k][0]));
        if (it != programasAcademicos.end())
        {
            ProgramaAcademico *programa = it->second;

            for (int m = 0; m < Settings::DATOS_ACADEM_DEMOGRAF; ++m)
            {
                Consolidado *consolidado = programa->getConsolidado(m);
                consolidado->setInscritos(stoi(programasAcademicosVector[k + m][1]));
            }
        }
    }

    if (ano2 == "2022")
    {
        columna = 12;
    }
    else
    {
        columna = 13;
    }

    programasAcademicosVector = gestorCsvObj.leerArchivo(rutaInscritos, ano2, codigosSnies, columna);

    for (int k = 0; k < programasAcademicosVector.size(); k += Settings::DATOS_ACADEM_DEMOGRAF)
    {
        map<int, ProgramaAcademico *>::iterator it = programasAcademicos.find(stoi(programasAcademicosVector[k][0]));
        if (it != programasAcademicos.end())
        {
            ProgramaAcademico *programa = it->second;

            for (int m = 0; m < Settings::DATOS_ACADEM_DEMOGRAF; ++m)
            {
                Consolidado *consolidado = programa->getConsolidado(m + 4);
                consolidado->setInscritos(stoi(programasAcademicosVector[k + m][1]));
            }
        }
    }

    programasAcademicosVector = gestorCsvObj.leerArchivo(rutaMatriculados, ano1, codigosSnies, 13);

    for (int k = 0; k < programasAcademicosVector.size(); k += 4)
    {
        map<int, ProgramaAcademico *>::iterator it = programasAcademicos.find(stoi(programasAcademicosVector[k][0]));
        if (it != programasAcademicos.end())
        {
            ProgramaAcademico *programa = it->second;

            for (int m = 0; m < Settings::DATOS_ACADEM_DEMOGRAF; ++m)
            {
                Consolidado *consolidado = programa->getConsolidado(m);
                consolidado->setMatriculados(stoi(programasAcademicosVector[k + m][1]));
            }
        }
    }

    programasAcademicosVector = gestorCsvObj.leerArchivo(rutaMatriculados, ano2, codigosSnies, 13);

    for (int k = 0; k < programasAcademicosVector.size(); k += Settings::DATOS_ACADEM_DEMOGRAF)
    {
        map<int, ProgramaAcademico *>::iterator it = programasAcademicos.find(stoi(programasAcademicosVector[k][0]));
        if (it != programasAcademicos.end())
        {
            ProgramaAcademico *programa = it->second;

            for (int m = 0; m < Settings::DATOS_ACADEM_DEMOGRAF; ++m)
            {
                Consolidado *consolidado = programa->getConsolidado(m + 4);
                consolidado->setMatriculados(stoi(programasAcademicosVector[k + m][1]));
            }
        }
    }

    programasAcademicosVector = gestorCsvObj.leerArchivo(rutaMatriculadosPrimerSemestre, ano1, codigosSnies, 13);

    for (int k = 0; k < programasAcademicosVector.size(); k += Settings::DATOS_ACADEM_DEMOGRAF)
    {
        map<int, ProgramaAcademico *>::iterator it = programasAcademicos.find(stoi(programasAcademicosVector[k][0]));
        if (it != programasAcademicos.end())
        {
            ProgramaAcademico *programa = it->second;

            for (int m = 0; m < Settings::DATOS_ACADEM_DEMOGRAF; ++m)
            {
                Consolidado *consolidado = programa->getConsolidado(m);
                consolidado->setMatriculadosPrimerSemestre(stoi(programasAcademicosVector[k + m][1]));
            }
        }
    }

    programasAcademicosVector = gestorCsvObj.leerArchivo(rutaMatriculadosPrimerSemestre, ano2, codigosSnies, 13);

    for (int k = 0; k < programasAcademicosVector.size(); k += Settings::DATOS_ACADEM_DEMOGRAF)
    {
        map<int, ProgramaAcademico *>::iterator it = programasAcademicos.find(stoi(programasAcademicosVector[k][0]));
        if (it != programasAcademicos.end())
        {
            ProgramaAcademico *programa = it->second;

            for (int m = 0; m < Settings::DATOS_ACADEM_DEMOGRAF; ++m)
            {
                Consolidado *consolidado = programa->getConsolidado(m + 4);
                consolidado->setMatriculadosPrimerSemestre(stoi(programasAcademicosVector[k + m][1]));
            }
        }
    }

    int opcion;
    cout << "Desea generar un archivo CSV (1), Desea generar un archivo TXT (2) o Desea generar un archivo JSON (3)" << endl;
    cin >> opcion;

    if (opcion == 1)
    {
        GestorCsv *gestorObjAux = new GestorCsv();
        gestorObjAux->crearArchivo(rutaOutput, programasAcademicos, etiquetasColumnas);
    }
    else if (opcion == 2)
    {
        GestorTxt *gestorObjAux = new GestorTxt();
        gestorObjAux->crearArchivo(rutaOutput, programasAcademicos, etiquetasColumnas);
    }
    else
    {
        GestorJson *gestorObjAux = new GestorJson();
        gestorObjAux->crearArchivo(rutaOutput, programasAcademicos, etiquetasColumnas);
    }
}

void SNIESController::calcularDatosExtra(bool flag)
{
    vector<vector<string>> matrizFinal;
    vector<vector<string>> matrizEtiquetas1;
    vector<vector<string>> matrizEtiquetas2;
    vector<vector<string>> matrizEtiquetas3;
    vector<string> etiquetas1 = {"Suma Estudiantes Matriculados de Programas Seleccionados (Presencial o Virtual) Primer año", "Suma Estudiantes Matriculados de Programas Seleccionados (Presencial o Virtual)"};
    matrizEtiquetas1.push_back(etiquetas1);
    vector<string> etiquetas2 = {"Codigo Snies", "Nombre del Programa", "Nombre del Institucion", "Diferencial porcentual anual de NEOS"};
    matrizEtiquetas2.push_back(etiquetas2);
    vector<string> etiquetas3 = {"Codigo Snies", " Nombre del Programa sin NEOS en los ultimos 3 semestres"};
    matrizEtiquetas3.push_back(etiquetas3);
    vector<string> datosEtiquetas1;
    vector<string> datosEtiquetas2;
    int sumaPrimerAno = 0;
    int sumaSegundoAno = 0;

    for (map<int, ProgramaAcademico *>::iterator it = programasAcademicos.begin(); it != programasAcademicos.end(); ++it)
    {
        int neosPrimerAno = 0;
        int neosSegundoAno = 0;
        int diferenciaNeos = 0;
        ProgramaAcademico *programa = it->second;
        int idMetodologiaBuscada = programa->getIdMetodologia();
        if (idMetodologiaBuscada == 1 || idMetodologiaBuscada == 3)
        {
            for (int i = 0; i < Settings::DATOS_ACADEM_DEMOGRAF; ++i)
            {
                Consolidado *consolidado = programa->getConsolidado(i);
                int matriculados = consolidado->getMatriculados();
                sumaPrimerAno += matriculados;
            }

            for (int i = 0; i < Settings::DATOS_ACADEM_DEMOGRAF; ++i)
            {
                Consolidado *consolidado = programa->getConsolidado(i + 4);
                int matriculados = consolidado->getMatriculados();
                sumaSegundoAno += matriculados;
            }
        }
        for (int i = 0; i < Settings::DATOS_ACADEM_DEMOGRAF; ++i)
        {
            Consolidado *consolidado = programa->getConsolidado(i);
            int numNeos = consolidado->getMatriculadosPrimerSemestre();
            neosPrimerAno += numNeos;
        }

        for (int i = 0; i < Settings::DATOS_ACADEM_DEMOGRAF; ++i)
        {
            Consolidado *consolidado = programa->getConsolidado(i + 4);
            int numNeos = consolidado->getMatriculadosPrimerSemestre();
            neosSegundoAno += numNeos;
        }

        if (neosPrimerAno != 0)
        {
            diferenciaNeos = ((neosSegundoAno - neosPrimerAno) * 100) / neosPrimerAno;
        }
        else
        {
            diferenciaNeos = 0;
        }
        datosEtiquetas2 = {to_string(programa->getCodigoSniesDelPrograma()), programa->getProgramaAcademico(), programa->getInstitucionDeEducacionSuperiorIes(), to_string(diferenciaNeos)};
        matrizEtiquetas2.push_back(datosEtiquetas2);
        int SumaNeosPrimerSemestre;
        int SumaNeosSegundoSemestre;
        int SumaNeosTercerSemestre;
        int SumaNeosCuartoSemestre;
        for (int i = 0; i < Settings::DATOS_ACADEM_DEMOGRAF; ++i)
        {
            Consolidado *consolidados[8];
            if (i == 0)
            {
                consolidados[0] = programa->getConsolidado(i);
                consolidados[1] = programa->getConsolidado(i + 2);
                int neosHombres = consolidados[0]->getMatriculadosPrimerSemestre();
                int neosMujeres = consolidados[1]->getMatriculadosPrimerSemestre();
                SumaNeosPrimerSemestre = neosHombres + neosMujeres;
            }
            else if (i == 1)
            {
                consolidados[2] = programa->getConsolidado(i);
                consolidados[3] = programa->getConsolidado(i + 2);
                int neosHombres = consolidados[2]->getMatriculadosPrimerSemestre();
                int neosMujeres = consolidados[3]->getMatriculadosPrimerSemestre();
                SumaNeosSegundoSemestre = neosHombres + neosMujeres;
            }
            else if (i == 2)
            {
                consolidados[4] = programa->getConsolidado(i + 2);
                consolidados[5] = programa->getConsolidado(i + 4);
                int neosHombres = consolidados[4]->getMatriculadosPrimerSemestre();
                int neosMujeres = consolidados[5]->getMatriculadosPrimerSemestre();
                SumaNeosTercerSemestre = neosHombres + neosMujeres;
            }
            else if (i == 3)
            {
                consolidados[6] = programa->getConsolidado(i + 2);
                consolidados[7] = programa->getConsolidado(i + 4);
                int neosHombres = consolidados[6]->getMatriculadosPrimerSemestre();
                int neosMujeres = consolidados[7]->getMatriculadosPrimerSemestre();
                SumaNeosCuartoSemestre = neosHombres + neosMujeres;
            }
        }

        if ((SumaNeosPrimerSemestre == 0 && SumaNeosSegundoSemestre == 0 && SumaNeosTercerSemestre == 0) || (SumaNeosSegundoSemestre == 0 && SumaNeosTercerSemestre == 0 && SumaNeosCuartoSemestre == 0))
        {
            etiquetas3 = {to_string(programa->getCodigoSniesDelPrograma()),
                          programa->getProgramaAcademico()};
        }
    }
    etiquetas1 = {to_string(sumaPrimerAno), to_string(sumaSegundoAno)};
    matrizEtiquetas1.push_back(etiquetas1);
    matrizFinal.insert(matrizFinal.end(), matrizEtiquetas1.begin(), matrizEtiquetas1.end());
    matrizFinal.insert(matrizFinal.end(), matrizEtiquetas2.begin(), matrizEtiquetas2.end());
    matrizFinal.insert(matrizFinal.end(), matrizEtiquetas3.begin(), matrizEtiquetas3.end());

    for (const auto &fila : matrizFinal)
    {
        for (size_t i = 0; i < fila.size(); ++i)
        {
            cout << fila[i];
            if (i < fila.size() - 1)
            {
                cout << ";";
            }
        }
        cout << endl;
    }

    if (flag)
    {
        int opcion;
        cout << "Desea generar un archivo CSV (1), Desea generar un archivo TXT (2) o Desea generar un archivo JSON (3)" << endl;
        cin >> opcion;

        if (opcion == 1)
        {
            GestorCsv *gestorObjAux = new GestorCsv();
            gestorObjAux->crearArchivoExtra(rutaOutput, matrizFinal);
        }
        else if (opcion == 2)
        {
            GestorTxt *gestorObjAux = new GestorTxt();
            gestorObjAux->crearArchivoExtra(rutaOutput, matrizFinal);
        }
        else
        {
            GestorJson *gestorObjAux = new GestorJson();
            gestorObjAux->crearArchivoExtra(rutaOutput, matrizFinal);
        }
    }
}

void SNIESController::imprimirTodosLosDatos() // FUN DE PRUEBA
{
    // Iteramos sobre el mapa de programas académicos
    for (auto it = programasAcademicos.begin(); it != programasAcademicos.end(); ++it)
    {
        ProgramaAcademico *programa = it->second;

        cout << "Codigo de la Institución: " << programa->getCodigoDeLaInstitucion() << endl;
        cout << "IES Padre: " << programa->getIesPadre() << endl;
        cout << "Institucion de Educación Superior: " << programa->getInstitucionDeEducacionSuperiorIes() << endl;
        cout << "Principal o Seccional: " << programa->getPrincipalOSeccional() << endl;
        cout << "Sector IES: " << programa->getSectorIes() << endl;
        cout << "Código SNIES del Programa: " << programa->getCodigoSniesDelPrograma() << endl;
        cout << "Programa Académico: " << programa->getProgramaAcademico() << endl;
        cout << "Nivel Académico: " << programa->getNivelAcademico() << endl;
        cout << "Nivel de Formación: " << programa->getNivelDeFormacion() << endl;
        cout << "Metodología: " << programa->getMetodologia() << endl;
        cout << "Área de Conocimiento: " << programa->getAreaDeConocimiento() << endl;

        // Iteramos sobre el mapa de consoliddos
        for (int i = 0; i < Settings::COMUNAS_INFO_CONSOLIDADOS; ++i)
        {
            Consolidado *consolidado = programa->getConsolidado(i);
            ;
            if (consolidado != nullptr)
            {
                cout << "Consolidado del año " << it->first << ":" << endl; // it->first es la clave (el año)
                cout << "    Sexo: " << consolidado->getSexo() << endl;
                cout << "    Año: " << consolidado->getAno() << endl;
                cout << "    Semestre: " << consolidado->getSemestre() << endl;
                cout << "    Inscritos: " << consolidado->getInscritos() << endl;
                cout << "    Admitidos: " << consolidado->getAdmitidos() << endl;
                cout << "    Matriculados: " << consolidado->getMatriculados() << endl;
                cout << "    Graduados: " << consolidado->getGraduados() << endl;
                cout << "    Matriculados Primer Semestre: " << consolidado->getMatriculadosPrimerSemestre() << endl;
            }
        }
        cout << "---------------------------------" << endl;
    }
}