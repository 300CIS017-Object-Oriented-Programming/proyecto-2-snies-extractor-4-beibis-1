#include "GestorCsv.h"

vector<int> GestorCsv::leerProgramasCsv(const string &ruta)
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
            getline(streamLinea, dato, Settings:: DELIMITADOR);
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

        while (getline(streamFila, dato, Settings:: DELIMITADOR))
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

            while (getline(streamFila, dato, Settings:: DELIMITADOR))
            {
                filaTemporal.push_back(dato);
                indiceColumna++;
            }

            if (filaTemporal.size() > Settings::COLUMNA_12 && filaTemporal[12] != "Sin programa especifico")
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

    while (getline(streamFila, dato, Settings:: DELIMITADOR))
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

        while (getline(streamFila, dato, Settings:: DELIMITADOR))
        {
            filaTemporal.push_back(dato);
            indiceColumna++;
        }

        if (filaTemporal.size() > Settings::COLUMNA_12 && filaTemporal[12] != "Sin programa especifico")
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
            while ((getline(streamFila, dato, Settings:: DELIMITADOR)) && (columnaArchivo < (colmunaCodigoSnies + 1)))
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
                while (getline(streamFila, dato, Settings:: DELIMITADOR))
                {
                }
                vectorFila[columnaVector] = dato;
                matrizResultado.push_back(vectorFila);

                // Leer las otras 3 filas
                for (int i = 0; i < Settings::FILAS_RESTANTES; i++)
                {
                    getline(archivoSegundo, fila);
                    streamFila = stringstream(fila);
                    columnaArchivo = 0;
                    columnaVector = 0;
                    while (getline(streamFila, dato, Settings:: DELIMITADOR))
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
           
        }
    }

    archivoSegundo.close();
   
    return matrizResultado;
}

bool GestorCsv::crearArchivo(string &ruta, map<int, ProgramaAcademico *> &mapadeProgramasAcademicos, vector<string> &etiquetasColumnas)
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
            archivoResultados << etiquetasColumnas[i] << Settings:: DELIMITADOR;
        }
        archivoResultados << "GRADUADOS;INSCRITOS;MATRICULADOS;NEOS" << endl;

        // Leemos todos los programas del mapa para imprimirlos en el archivo
        for (map<int, ProgramaAcademico *>::iterator it = mapadeProgramasAcademicos.begin(); it != mapadeProgramasAcademicos.end(); it++)
        {
            // Imprimimos cada uno de los 8 consolidados por programa
            for (int i = 0; i < Settings::COLUMNAS_INFO_CONSOLIDADOS; i++)
            {
                // Imprimimos toda la información base del programa academico
                archivoResultados << (it->second)->getCodigoDeLaInstitucion() << Settings:: DELIMITADOR;
                archivoResultados << (it->second)->getIesPadre() << Settings:: DELIMITADOR;
                archivoResultados << (it->second)->getInstitucionDeEducacionSuperiorIes() << Settings:: DELIMITADOR;
                archivoResultados << (it->second)->getPrincipalOSeccional() << Settings:: DELIMITADOR;
                archivoResultados << (it->second)->getIdSectorIes() << Settings:: DELIMITADOR;
                archivoResultados << (it->second)->getSectorIes() << Settings:: DELIMITADOR;
                archivoResultados << (it->second)->getIdCaracter() << Settings:: DELIMITADOR;
                archivoResultados << (it->second)->getCaracterIes() << Settings::DELIMITADOR;
                archivoResultados << (it->second)->getCodigoDelDepartamentoIes() << Settings:: DELIMITADOR;
                archivoResultados << (it->second)->getDepartamentoDeDomicilioDeLaIes() << Settings:: DELIMITADOR;
                archivoResultados << (it->second)->getCodigoDelMunicipioIes() << Settings:: DELIMITADOR;
                archivoResultados << (it->second)->getMunicipioDeDomicilioDeLaIes() << Settings:: DELIMITADOR;
                archivoResultados << (it->second)->getCodigoSniesDelPrograma() << Settings:: DELIMITADOR;
                archivoResultados << (it->second)->getProgramaAcademico() << Settings:: DELIMITADOR;
                archivoResultados << (it->second)->getIdNivelAcademico() << Settings:: DELIMITADOR;
                archivoResultados << (it->second)->getNivelAcademico() << Settings:: DELIMITADOR;
                archivoResultados << (it->second)->getIdNivelDeFormacion() << Settings:: DELIMITADOR;
                archivoResultados << (it->second)->getNivelDeFormacion() << Settings:: DELIMITADOR;
                archivoResultados << (it->second)->getIdMetodologia() << Settings:: DELIMITADOR;
                archivoResultados << (it->second)->getMetodologia() << Settings:: DELIMITADOR;
                archivoResultados << (it->second)->getIdArea() << Settings:: DELIMITADOR;
                archivoResultados << (it->second)->getAreaDeConocimiento() << Settings:: DELIMITADOR;
                archivoResultados << (it->second)->getIdNucleo() << Settings:: DELIMITADOR;
                archivoResultados << (it->second)->getNucleoBasicoDelConocimientoNbc() << Settings:: DELIMITADOR;
                archivoResultados << (it->second)->getIdCineCampoAmplio() << Settings:: DELIMITADOR;
                archivoResultados << (it->second)->getDescCineCampoAmplio() << Settings:: DELIMITADOR;
                archivoResultados << (it->second)->getIdCineCampoEspecifico() << Settings:: DELIMITADOR;
                archivoResultados << (it->second)->getDescCineCampoEspecifico() << Settings:: DELIMITADOR;
                archivoResultados << (it->second)->getIdCineCodigoDetallado() << Settings:: DELIMITADOR;
                archivoResultados << (it->second)->getDescCineCodigoDetallado() << Settings:: DELIMITADOR;
                archivoResultados << (it->second)->getCodigoDelDepartamentoPrograma() << Settings:: DELIMITADOR;
                archivoResultados << (it->second)->getDepartamentoDeOfertaDelPrograma() << Settings:: DELIMITADOR;
                archivoResultados << (it->second)->getCodigoDelMunicipioPrograma() << Settings:: DELIMITADOR;
                archivoResultados << (it->second)->getMunicipioDeOfertaDelPrograma() << Settings:: DELIMITADOR;

                // Imprimimos la información del consolidado: (ID SEXO;SEXO;AÑO;SEMESTRE;ADMITIDOS;GRADUADOS;INSCRITOS;MATRICULADOS;NEOS)
                Consolidado *consolidadoActual = (it->second)->getConsolidado(i);
                archivoResultados << consolidadoActual->getIdSexo() << Settings:: DELIMITADOR;
                archivoResultados << consolidadoActual->getSexo() << Settings:: DELIMITADOR;
                archivoResultados << consolidadoActual->getAno() << Settings:: DELIMITADOR;
                archivoResultados << consolidadoActual->getSemestre() << Settings:: DELIMITADOR;
                archivoResultados << consolidadoActual->getAdmitidos() << Settings:: DELIMITADOR;
                archivoResultados << consolidadoActual->getGraduados() << Settings:: DELIMITADOR;
                archivoResultados << consolidadoActual->getInscritos() << Settings:: DELIMITADOR;
                archivoResultados << consolidadoActual->getMatriculados() << Settings:: DELIMITADOR;
                archivoResultados << consolidadoActual->getMatriculadosPrimerSemestre();
                // Saltamos de linea para la siguiente fila
                archivoResultados << endl;
            }
        }

        // Cambiamos el valor del booleano si logramos llegar hasta este punto
        estadoCreacion = true;

        cout << "Archivo Creado en: " << rutaCompleta << endl;
    }

    archivoResultados.close();
    return estadoCreacion;
}

bool GestorCsv::crearArchivoBuscados(string &ruta, list<ProgramaAcademico *> &programasBuscados, vector<string> &etiquetasColumnas)
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
            archivoBuscados << etiquetasColumnas[i] << Settings:: DELIMITADOR;
        }
        archivoBuscados << "GRADUADOS;INSCRITOS;MATRICULADOS;NEOS" << endl;

        list<ProgramaAcademico *>::iterator it;
        // Leemos todos los programas de la lista de los programas buscados para imprimirlos
        for (it = programasBuscados.begin(); it != programasBuscados.end(); it++)
        {
            // Imprimimos los 8 consolidados del programa
            for (int i = 0; i < Settings::COLUMNAS_INFO_CONSOLIDADOS; i++)
            {
                // Imprimimos la informacion base del programa
                archivoBuscados << (*it)->getCodigoDeLaInstitucion() << Settings:: DELIMITADOR;
                archivoBuscados << (*it)->getIesPadre() << Settings:: DELIMITADOR;
                archivoBuscados << (*it)->getInstitucionDeEducacionSuperiorIes() << Settings:: DELIMITADOR;
                archivoBuscados << (*it)->getPrincipalOSeccional() << Settings:: DELIMITADOR;
                archivoBuscados << (*it)->getIdSectorIes() << Settings:: DELIMITADOR;
                archivoBuscados << (*it)->getSectorIes() << Settings:: DELIMITADOR;
                archivoBuscados << (*it)->getIdCaracter() << Settings:: DELIMITADOR;
                archivoBuscados << (*it)->getCaracterIes() << Settings:: DELIMITADOR;
                archivoBuscados << (*it)->getCodigoDelDepartamentoIes() << Settings:: DELIMITADOR;
                archivoBuscados << (*it)->getDepartamentoDeDomicilioDeLaIes() << Settings:: DELIMITADOR;
                archivoBuscados << (*it)->getCodigoDelMunicipioIes() << Settings:: DELIMITADOR;
                archivoBuscados << (*it)->getMunicipioDeDomicilioDeLaIes() << Settings:: DELIMITADOR;
                archivoBuscados << (*it)->getCodigoSniesDelPrograma() << Settings:: DELIMITADOR;
                archivoBuscados << (*it)->getProgramaAcademico() << Settings:: DELIMITADOR;
                archivoBuscados << (*it)->getIdNivelAcademico() << Settings:: DELIMITADOR;
                archivoBuscados << (*it)->getNivelAcademico() << Settings:: DELIMITADOR;
                archivoBuscados << (*it)->getIdNivelDeFormacion() << Settings:: DELIMITADOR;
                archivoBuscados << (*it)->getNivelDeFormacion() << Settings:: DELIMITADOR;
                archivoBuscados << (*it)->getIdMetodologia() << Settings:: DELIMITADOR;
                archivoBuscados << (*it)->getMetodologia() << Settings:: DELIMITADOR;
                archivoBuscados << (*it)->getIdArea() << Settings:: DELIMITADOR;
                archivoBuscados << (*it)->getAreaDeConocimiento() << Settings:: DELIMITADOR;
                archivoBuscados << (*it)->getIdNucleo() << Settings:: DELIMITADOR;
                archivoBuscados << (*it)->getNucleoBasicoDelConocimientoNbc() << Settings:: DELIMITADOR;
                archivoBuscados << (*it)->getIdCineCampoAmplio() << Settings:: DELIMITADOR;
                archivoBuscados << (*it)->getDescCineCampoAmplio() << Settings:: DELIMITADOR;
                archivoBuscados << (*it)->getIdCineCampoEspecifico() << Settings:: DELIMITADOR;
                archivoBuscados << (*it)->getDescCineCampoEspecifico() << Settings:: DELIMITADOR;
                archivoBuscados << (*it)->getIdCineCodigoDetallado() << Settings:: DELIMITADOR;
                archivoBuscados << (*it)->getDescCineCodigoDetallado() << Settings:: DELIMITADOR;
                archivoBuscados << (*it)->getCodigoDelDepartamentoPrograma() << Settings:: DELIMITADOR;
                archivoBuscados << (*it)->getDepartamentoDeOfertaDelPrograma() << Settings:: DELIMITADOR;
                archivoBuscados << (*it)->getCodigoDelMunicipioPrograma() << Settings:: DELIMITADOR;
                archivoBuscados << (*it)->getMunicipioDeOfertaDelPrograma() << Settings:: DELIMITADOR;

                // Imprimimos la información del consolidado: (ID SEXO;SEXO;AÑO;SEMESTRE;ADMITIDOS;GRADUADOS;INSCRITOS;MATRICULADOS;NEOS)
                Consolidado *consolidadoActual = (*it)->getConsolidado(i);
                archivoBuscados << consolidadoActual->getIdSexo() << Settings:: DELIMITADOR;
                archivoBuscados << consolidadoActual->getSexo() << Settings:: DELIMITADOR;
                archivoBuscados << consolidadoActual->getAno() << Settings:: DELIMITADOR;
                archivoBuscados << consolidadoActual->getSemestre() << Settings:: DELIMITADOR;
                archivoBuscados << consolidadoActual->getAdmitidos() << Settings:: DELIMITADOR;
                archivoBuscados << consolidadoActual->getGraduados() << Settings:: DELIMITADOR;
                archivoBuscados << consolidadoActual->getInscritos() << Settings:: DELIMITADOR;
                archivoBuscados << consolidadoActual->getMatriculados() << Settings:: DELIMITADOR;
                archivoBuscados << consolidadoActual->getMatriculadosPrimerSemestre();
                // Saltamos de linea para la siguiente fila
                archivoBuscados << endl;
            }
        }

        // Cambiamos el valor del booleano si logramos llegar hasta este punto
        estadoCreacion = true;
        cout << "Archivo Creado en: " << rutaCompleta << endl;
    }

    archivoBuscados.close();
    return estadoCreacion;
}

bool GestorCsv::crearArchivoExtra(string &ruta, vector<vector<string>> &datosAImprimir)
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
                    archivoExtra << Settings:: DELIMITADOR;
                }
            }
            // Saltamos de linea al terminar una fila
            archivoExtra << endl;
        }

        // Cambiamos el valor del booleano si logramos llegar hasta este punto
        estadoCreacion = true;

        cout << "Archivo Creado en: " << rutaCompleta << endl;
    }

    archivoExtra.close();
    return estadoCreacion;
}