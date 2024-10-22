#include "GestorCsv.h"

vector<int> GestorCsv::leerProgramasCsv(string &ruta)
{
    vector<int> codigosSniesRetorno;
    ifstream archivoProgramasCsv(ruta);
    if (!(archivoProgramasCsv.is_open()))
    {
        cout << "Archivo " << ruta << " no se pudo abrir correctamente" << endl;
    }
    else
    {
        string linea;
        string dato;
        // Saltarse la primera linea
        getline(archivoProgramasCsv, linea);
        // Leer los programas
        while (getline(archivoProgramasCsv, linea))
        {
            stringstream streamLinea(linea);
            getline(streamLinea, dato, Settings::delimitador);
            codigosSniesRetorno.push_back(stoi(dato));
        }
    }
    archivoProgramasCsv.close();
    return codigosSniesRetorno;
}

vector<vector<string>> GestorCsv::leerArchivoPrimera(string &rutaBase, string &ano, vector<int> &codigosSnies)
{
    vector<vector<string>> matrizResultado;
    string rutaCompleta = rutaBase + ano + ".csv";
    ifstream archivoPrimero(rutaCompleta);
    if (!(archivoPrimero.is_open()))
    {
        cout << "Archivo " << rutaCompleta << " no se pudo abrir correctamente" << endl;
    }
    else
    {
        string fila;
        string dato;
        vector<string> vectorFila;
        stringstream streamFila;
        vector<int> posicionesInteres;
        vector<int>::iterator it;

        getline(archivoPrimero, fila);
        streamFila = stringstream(fila);
        int indiceColumna = 0;

        while (getline(streamFila, dato, Settings::delimitador))
        {
            if (dato == "CÓDIGO DE LA INSTITUCIÓN" ||
                dato == "IES_PADRE" ||
                dato == "INSTITUCIÓN DE EDUCACIÓN SUPERIOR (IES)" ||
                dato == "TIPO IES" ||
                dato == "ID SECTOR IES" ||
                dato == "SECTOR IES" ||
                dato == "ID CARACTER" ||
                dato == "CARACTER IES" ||
                dato == "CÓDIGO DEL DEPARTAMENTO (IES)" ||
                dato == "DEPARTAMENTO DE DOMICILIO DE LA IES" ||
                dato == "CÓDIGO DEL MUNICIPIO IES" ||
                dato == "MUNICIPIO DE DOMICILIO DE LA IES" ||
                dato == "CÓDIGO SNIES DEL PROGRAMA" ||
                dato == "PROGRAMA ACADÉMICO" ||
                dato == "NÚCLEO BÁSICO DEL CONOCIMIENTO (NBC)" ||
                dato == "ID NIVEL ACADÉMICO" ||
                dato == "NIVEL ACADÉMICO" ||
                dato == "ID NIVEL DE FORMACIÓN" ||
                dato == "NIVEL DE FORMACIÓN" ||
                dato == "ID METODOLOGÍA" ||
                dato == "METODOLOGÍA" ||
                dato == "ID ÁREA DE CONOCIMIENTO" ||
                dato == "ÁREA DE CONOCIMIENTO" ||
                dato == "ID NÚCLEO" ||
                dato == "ID CINE CAMPO AMPLIO" ||
                dato == "DESC CINE CAMPO AMPLIO" ||
                dato == "ID CINE CAMPO ESPECIFICO" ||
                dato == "DESC CINE CAMPO ESPECIFICO" ||
                dato == "ID CINE CODIGO DETALLADO" ||
                dato == "DESC CINE CODIGO DETALLADO" ||
                dato == "CÓDIGO DEL DEPARTAMENTO (PROGRAMA)" ||
                dato == "DEPARTAMENTO DE OFERTA DEL PROGRAMA" ||
                dato == "CÓDIGO DEL MUNICIPIO (PROGRAMA)" ||
                dato == "MUNICIPIO DE OFERTA DEL PROGRAMA" ||
                dato == "ID SEXO" ||
                dato == "SEXO" ||
                dato == "AÑO" ||
                dato == "SEMESTRE" ||
                dato == "ADMITIDOS")
            {

                posicionesInteres.push_back(indiceColumna);
                vectorFila.push_back(dato);
            }
            indiceColumna++;
        }

        matrizResultado.push_back(vectorFila);

        while (getline(archivoPrimero, fila))
        {
            vectorFila.clear();
            streamFila = stringstream(fila);
            indiceColumna = 0;
            vector<string> filaTemporal;

            while (getline(streamFila, dato, Settings::delimitador))
            {
                filaTemporal.push_back(dato);
                indiceColumna++;
            }

            if (filaTemporal.size() > 12 && filaTemporal[12] != "Sin programa especifico")
            {
                it = find(codigosSnies.begin(), codigosSnies.end(), stoi(filaTemporal[12]));
            }
            else
            {
                it = codigosSnies.end();
            }

            if (it != codigosSnies.end())
            {
                for (int pos : posicionesInteres)
                {
                    if (pos < filaTemporal.size())
                    {
                        vectorFila.push_back(filaTemporal[pos]);
                    }
                }
                matrizResultado.push_back(vectorFila);
            }
        }
    }

    archivoPrimero.close();
    return matrizResultado;
}

vector<vector<string>> GestorCsv::leerArchivoSegunda(string &rutaBase, string &ano, vector<int> &codigosSnies)
{
    vector<vector<string>> matrizResultado;
    string rutaCompleta = rutaBase + ano + ".csv";
    ifstream archivoSegundo(rutaCompleta);

    if (!(archivoSegundo.is_open()))
    {
        cout << "Archivo " << rutaCompleta << " no se pudo abrir correctamente" << endl;
        return matrizResultado;
    }

    string fila;
    string dato;
    vector<string> vectorFila;
    stringstream streamFila;
    vector<int> posicionesInteres;
    vector<int>::iterator it;

    getline(archivoSegundo, fila);
    streamFila = stringstream(fila);
    int indiceColumna = 0;

    while (getline(streamFila, dato, Settings::delimitador))
    {
        if (dato == "CÓDIGO SNIES DEL PROGRAMA" ||
            dato == "ID SEXO" ||
            dato == "SEXO" ||
            dato == "AÑO" ||
            dato == "SEMESTRE" ||
            dato == "ADMITIDOS")
        {
            posicionesInteres.push_back(indiceColumna);
            vectorFila.push_back(dato);
        }
        indiceColumna++;
    }

    while (getline(archivoSegundo, fila))
    {
        vectorFila.clear();
        streamFila = stringstream(fila);
        indiceColumna = 0;
        vector<string> filaTemporal;

        while (getline(streamFila, dato, Settings::delimitador))
        {
            filaTemporal.push_back(dato);
            indiceColumna++;
        }

        if (filaTemporal.size() > 12 && filaTemporal[12] != "Sin programa especifico")
        {
            it = find(codigosSnies.begin(), codigosSnies.end(), stoi(filaTemporal[12]));
        }
        else
        {
            it = codigosSnies.end();
        }

        if (it != codigosSnies.end())
        {

            for (int pos : posicionesInteres)
            {
                if (pos < filaTemporal.size())
                {
                    vectorFila.push_back(filaTemporal[pos]);
                }
            }
            matrizResultado.push_back(vectorFila);
        }
    }

    archivoSegundo.close();
    return matrizResultado;
}

vector<vector<string>> GestorCsv::leerArchivo(string &rutaBase, string &ano, vector<int> &codigosSnies, int colmunaCodigoSnies)
{
    vector<vector<string>> matrizResultado;
    string rutaCompleta = rutaBase + ano + ".csv";
    ifstream archivoSegundo(rutaCompleta);
    if (!(archivoSegundo.is_open()))
    {
        cout << "Archivo " << rutaCompleta << " no se pudo abrir correctamente" << endl;
    }
    else
    {
        string fila;
        string dato;
        vector<string> vectorFila(2);
        stringstream streamFila;
        int columnaArchivo;
        int columnaVector;
        vector<int>::iterator it;

        // Nos saltamos las etiquetas para no interferir en el bucle
        getline(archivoSegundo, fila);

        // Leemos las filas
        while (getline(archivoSegundo, fila))
        {
            streamFila = stringstream(fila);
            columnaArchivo = 0;
            columnaVector = 0;
            while ((getline(streamFila, dato, Settings::delimitador)) && (columnaArchivo < (colmunaCodigoSnies + 1)))
            {
                if (columnaArchivo == colmunaCodigoSnies)
                {
                    vectorFila[columnaVector] = dato;
                    columnaVector++;
                }
                columnaArchivo++;
            }

            // Verificamos que la fila no sea una fila de error
            if (vectorFila[0] != "Sin programa especifico")
            {
                it = find(codigosSnies.begin(), codigosSnies.end(), stoi(vectorFila[0]));
            }
            else
            {
                it = codigosSnies.end();
            }

            // Verificar si hace parte de los programas que me interesan
            if (it != codigosSnies.end()) // Caso cuando SI es parte de los que me interesan
            {
                // Terminar de leer primera fila
                while (getline(streamFila, dato, Settings::delimitador))
                {
                }
                vectorFila[columnaVector] = dato;
                matrizResultado.push_back(vectorFila);

                // Leer las otras 3 filas
                for (int i = 0; i < 3; i++)
                {
                    getline(archivoSegundo, fila);
                    streamFila = stringstream(fila);
                    columnaArchivo = 0;
                    columnaVector = 0;
                    while (getline(streamFila, dato, Settings::delimitador))
                    {
                        if (columnaArchivo == colmunaCodigoSnies)
                        {
                            vectorFila[columnaVector] = dato;
                            columnaVector++;
                        }
                        columnaArchivo++;
                    }
                    vectorFila[columnaVector] = dato;
                    matrizResultado.push_back(vectorFila);
                }
            }
            else // Caso cuando NO es parte de los que me interesan
            {
                /*// Saltarme las 3 siguientes filas con mismo codigo Snies
                for (int j = 0; j < 3; j++)
                {
                    getline(archivoSegundo, fila);
                }*/
            }
        }
    }

    /*
    Ejemplo de matrizResultado: (No tendría las etiquetas incluidas)
    CodigoSnies;DatoExtradelArchivo
    12;5
    */
    archivoSegundo.close();
    /*// Imprimir matriz resultado para verificaciones
    for (int h = 0; h < matrizResultado.size(); h++)
    {
        for (int k = 0; k < matrizResultado[h].size(); k++)
        {
            cout << matrizResultado[h][k];
            if (k != (matrizResultado[h].size() - 1))
            {
                cout << Settings:: delimitador;
            }
        }
        cout << endl;
    }*/
    return matrizResultado;
}

bool GestorCsv::crearArchivo(string &ruta, map<int, ProgramaAcademico *> &mapadeProgramasAcademicos, vector<string> etiquetasColumnas)
{
    // Este bool nos ayudará a saber si se creo exitosamente el archivo
    bool estadoCreacion = false;
    string rutaCompleta = ruta + "resultados.csv";
    ofstream archivoResultados(rutaCompleta);
    if (archivoResultados.is_open())
    {
        // Imprimimos en el archivo las etiquetas (Primera fila)
        for (int i = 0; i < etiquetasColumnas.size(); i++)
        {
            archivoResultados << etiquetasColumnas[i] << Settings::delimitador;
        }
        archivoResultados << "GRADUADOS;INSCRITOS;MATRICULADOS;NEOS" << endl;

        map<int, ProgramaAcademico *>::iterator it;
        // Leemos todos los programas del mapa para imprimirlos en el archivo
        for (it = mapadeProgramasAcademicos.begin(); it != mapadeProgramasAcademicos.end(); it++)
        {
            // Imprimimos cada uno de los 8 consolidados por programa
            for (int i = 0; i < Settings::COMUNAS_INFO_CONSOLIDADOS; i++)
            {
                // Imprimimos toda la información base del programa academico
                archivoResultados << (it->second)->getCodigoDeLaInstitucion() << Settings::delimitador;
                archivoResultados << (it->second)->getIesPadre() << Settings::delimitador;
                archivoResultados << (it->second)->getInstitucionDeEducacionSuperiorIes() << Settings::delimitador;
                archivoResultados << (it->second)->getPrincipalOSeccional() << Settings::delimitador;
                archivoResultados << (it->second)->getIdSectorIes() << Settings::delimitador;
                archivoResultados << (it->second)->getSectorIes() << Settings::delimitador;
                archivoResultados << (it->second)->getIdCaracter() << Settings::delimitador;
                archivoResultados << (it->second)->getCaracterIes() << Settings::delimitador;
                archivoResultados << (it->second)->getCodigoDelDepartamentoIes() << Settings::delimitador;
                archivoResultados << (it->second)->getDepartamentoDeDomicilioDeLaIes() << Settings::delimitador;
                archivoResultados << (it->second)->getCodigoDelMunicipioIes() << Settings::delimitador;
                archivoResultados << (it->second)->getMunicipioDeDomicilioDeLaIes() << Settings::delimitador;
                archivoResultados << (it->second)->getCodigoSniesDelPrograma() << Settings::delimitador;
                archivoResultados << (it->second)->getProgramaAcademico() << Settings::delimitador;
                archivoResultados << (it->second)->getIdNivelAcademico() << Settings::delimitador;
                archivoResultados << (it->second)->getNivelAcademico() << Settings::delimitador;
                archivoResultados << (it->second)->getIdNivelDeFormacion() << Settings::delimitador;
                archivoResultados << (it->second)->getNivelDeFormacion() << Settings::delimitador;
                archivoResultados << (it->second)->getIdMetodologia() << Settings::delimitador;
                archivoResultados << (it->second)->getMetodologia() << Settings::delimitador;
                archivoResultados << (it->second)->getIdArea() << Settings::delimitador;
                archivoResultados << (it->second)->getAreaDeConocimiento() << Settings::delimitador;
                archivoResultados << (it->second)->getIdNucleo() << Settings::delimitador;
                archivoResultados << (it->second)->getNucleoBasicoDelConocimientoNbc() << Settings::delimitador;
                archivoResultados << (it->second)->getIdCineCampoAmplio() << Settings::delimitador;
                archivoResultados << (it->second)->getDescCineCampoAmplio() << Settings::delimitador;
                archivoResultados << (it->second)->getIdCineCampoEspecifico() << Settings::delimitador;
                archivoResultados << (it->second)->getDescCineCampoEspecifico() << Settings::delimitador;
                archivoResultados << (it->second)->getIdCineCodigoDetallado() << Settings::delimitador;
                archivoResultados << (it->second)->getDescCineCodigoDetallado() << Settings::delimitador;
                archivoResultados << (it->second)->getCodigoDelDepartamentoPrograma() << Settings::delimitador;
                archivoResultados << (it->second)->getDepartamentoDeOfertaDelPrograma() << Settings::delimitador;
                archivoResultados << (it->second)->getCodigoDelMunicipioPrograma() << Settings::delimitador;
                archivoResultados << (it->second)->getMunicipioDeOfertaDelPrograma() << Settings::delimitador;

                // Imprimimos la información del consolidado: (ID SEXO;SEXO;AÑO;SEMESTRE;ADMITIDOS;GRADUADOS;INSCRITOS;MATRICULADOS;NEOS)
                Consolidado *consolidadoActual = (it->second)->getConsolidado(i);
                archivoResultados << consolidadoActual->getIdSexo() << Settings::delimitador;
                archivoResultados << consolidadoActual->getSexo() << Settings::delimitador;
                archivoResultados << consolidadoActual->getAno() << Settings::delimitador;
                archivoResultados << consolidadoActual->getSemestre() << Settings::delimitador;
                archivoResultados << consolidadoActual->getAdmitidos() << Settings::delimitador;
                archivoResultados << consolidadoActual->getGraduados() << Settings::delimitador;
                archivoResultados << consolidadoActual->getInscritos() << Settings::delimitador;
                archivoResultados << consolidadoActual->getMatriculados() << Settings::delimitador;
                archivoResultados << consolidadoActual->getMatriculadosPrimerSemestre();
                // Saltamos de linea para la siguiente fila
                archivoResultados << endl;
            }
        }

        // Cambiamos el valor del booleano si logramos llegar hasta este punto
        estadoCreacion = true;
        // Imprimimos ruta donde quedo el archivo
        cout << "Archivo Creado en: " << rutaCompleta << endl;
    }

    archivoResultados.close();
    return estadoCreacion;
}

bool GestorCsv::crearArchivoBuscados(string &ruta, list<ProgramaAcademico *> &programasBuscados, vector<string> etiquetasColumnas)
{
    // Este bool nos ayudará a saber si se creo exitosamente el archivo
    bool estadoCreacion = false;
    string rutaCompleta = ruta + "buscados.csv";
    ofstream archivoBuscados(rutaCompleta);
    if (archivoBuscados.is_open())
    {

        // Imprimimos en el archivo las etiquetas (Primera fila)
        for (int i = 0; i < etiquetasColumnas.size(); i++)
        {
            archivoBuscados << etiquetasColumnas[i] << Settings::delimitador;
        }
        archivoBuscados << "GRADUADOS;INSCRITOS;MATRICULADOS;NEOS" << endl;

        list<ProgramaAcademico *>::iterator it;
        // Leemos todos los programas de la lista de los programas buscados para imprimirlos
        for (it = programasBuscados.begin(); it != programasBuscados.end(); it++)
        {
            // Imprimimos los 8 consolidados del programa
            for (int i = 0; i < Settings::COMUNAS_INFO_CONSOLIDADOS; i++)
            {
                // Imprimimos la informacion base del programa
                archivoBuscados << (*it)->getCodigoDeLaInstitucion() << Settings::delimitador;
                archivoBuscados << (*it)->getIesPadre() << Settings::delimitador;
                archivoBuscados << (*it)->getInstitucionDeEducacionSuperiorIes() << Settings::delimitador;
                archivoBuscados << (*it)->getPrincipalOSeccional() << Settings::delimitador;
                archivoBuscados << (*it)->getIdSectorIes() << Settings::delimitador;
                archivoBuscados << (*it)->getSectorIes() << Settings::delimitador;
                archivoBuscados << (*it)->getIdCaracter() << Settings::delimitador;
                archivoBuscados << (*it)->getCaracterIes() << Settings::delimitador;
                archivoBuscados << (*it)->getCodigoDelDepartamentoIes() << Settings::delimitador;
                archivoBuscados << (*it)->getDepartamentoDeDomicilioDeLaIes() << Settings::delimitador;
                archivoBuscados << (*it)->getCodigoDelMunicipioIes() << Settings::delimitador;
                archivoBuscados << (*it)->getMunicipioDeDomicilioDeLaIes() << Settings::delimitador;
                archivoBuscados << (*it)->getCodigoSniesDelPrograma() << Settings::delimitador;
                archivoBuscados << (*it)->getProgramaAcademico() << Settings::delimitador;
                archivoBuscados << (*it)->getIdNivelAcademico() << Settings::delimitador;
                archivoBuscados << (*it)->getNivelAcademico() << Settings::delimitador;
                archivoBuscados << (*it)->getIdNivelDeFormacion() << Settings::delimitador;
                archivoBuscados << (*it)->getNivelDeFormacion() << Settings::delimitador;
                archivoBuscados << (*it)->getIdMetodologia() << Settings::delimitador;
                archivoBuscados << (*it)->getMetodologia() << Settings::delimitador;
                archivoBuscados << (*it)->getIdArea() << Settings::delimitador;
                archivoBuscados << (*it)->getAreaDeConocimiento() << Settings::delimitador;
                archivoBuscados << (*it)->getIdNucleo() << Settings::delimitador;
                archivoBuscados << (*it)->getNucleoBasicoDelConocimientoNbc() << Settings::delimitador;
                archivoBuscados << (*it)->getIdCineCampoAmplio() << Settings::delimitador;
                archivoBuscados << (*it)->getDescCineCampoAmplio() << Settings::delimitador;
                archivoBuscados << (*it)->getIdCineCampoEspecifico() << Settings::delimitador;
                archivoBuscados << (*it)->getDescCineCampoEspecifico() << Settings::delimitador;
                archivoBuscados << (*it)->getIdCineCodigoDetallado() << Settings::delimitador;
                archivoBuscados << (*it)->getDescCineCodigoDetallado() << Settings::delimitador;
                archivoBuscados << (*it)->getCodigoDelDepartamentoPrograma() << Settings::delimitador;
                archivoBuscados << (*it)->getDepartamentoDeOfertaDelPrograma() << Settings::delimitador;
                archivoBuscados << (*it)->getCodigoDelMunicipioPrograma() << Settings::delimitador;
                archivoBuscados << (*it)->getMunicipioDeOfertaDelPrograma() << Settings::delimitador;

                // Imprimimos la información del consolidado: (ID SEXO;SEXO;AÑO;SEMESTRE;ADMITIDOS;GRADUADOS;INSCRITOS;MATRICULADOS;NEOS)
                Consolidado *consolidadoActual = (*it)->getConsolidado(i);
                archivoBuscados << consolidadoActual->getIdSexo() << Settings::delimitador;
                archivoBuscados << consolidadoActual->getSexo() << Settings::delimitador;
                archivoBuscados << consolidadoActual->getAno() << Settings::delimitador;
                archivoBuscados << consolidadoActual->getSemestre() << Settings::delimitador;
                archivoBuscados << consolidadoActual->getAdmitidos() << Settings::delimitador;
                archivoBuscados << consolidadoActual->getGraduados() << Settings::delimitador;
                archivoBuscados << consolidadoActual->getInscritos() << Settings::delimitador;
                archivoBuscados << consolidadoActual->getMatriculados() << Settings::delimitador;
                archivoBuscados << consolidadoActual->getMatriculadosPrimerSemestre();
                // Saltamos de linea para la siguiente fila
                archivoBuscados << endl;
            }
        }

        // Cambiamos el valor del booleano si logramos llegar hasta este punto
        estadoCreacion = true;
        // Imprimimos ruta donde quedo el archivo
        cout << "Archivo Creado en: " << rutaCompleta << endl;
    }

    archivoBuscados.close();
    return estadoCreacion;
}

bool GestorCsv::crearArchivoExtra(string &ruta, vector<vector<string>> datosAImprimir)
{
    // Este bool nos ayudará a saber si se creo el archivo exitosamente
    bool estadoCreacion = false;
    string rutaCompleta = ruta + "extras.csv";
    ofstream archivoExtra(rutaCompleta);
    if (archivoExtra.is_open())
    {
        // Imprimimos la matriz de datos que queremos imprimir
        for (int i = 0; i < datosAImprimir.size(); i++)
        {
            // Imprimimos cada fila
            for (int j = 0; j < datosAImprimir[i].size(); j++)
            {
                // Imprimimos cada dato separado por Settings:: delimitador
                archivoExtra << datosAImprimir[i][j];
                if (j != (datosAImprimir[i].size() - 1))
                {
                    archivoExtra << Settings::delimitador;
                }
            }
            // Saltamos de linea al terminar una fila
            archivoExtra << endl;
        }

        // Cambiamos el valor del booleano si logramos llegar hasta este punto
        estadoCreacion = true;
        // Imprimimos ruta donde quedo el archivo
        cout << "Archivo Creado en: " << rutaCompleta << endl;
    }

    archivoExtra.close();
    return estadoCreacion;
}