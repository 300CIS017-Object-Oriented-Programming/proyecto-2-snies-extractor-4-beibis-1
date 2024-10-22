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
            getline(streamLinea, dato, Settings:: delimitador);
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
        int columna;
        vector<int>::iterator it;

        // Primera iteracion del ciclo para guardar las etiquetas
        getline(archivoPrimero, fila);
        vectorFila = vector<string>(39);
        streamFila = stringstream(fila);
        columna = 0;
        while ((getline(streamFila, dato, Settings:: delimitador)))
        {
            vectorFila[columna] = dato;
            columna++;
        }
        matrizResultado.push_back(vectorFila);

        // Leer el resto del archivo
        while (getline(archivoPrimero, fila))
        {
            streamFila = stringstream(fila);
            columna = 0;
            while ((getline(streamFila, dato, Settings:: delimitador)) && (columna < 13))
            {
                vectorFila[columna] = dato;
                columna++;
            }

            // Verificamos que la fila no sea una fila de error
            if (vectorFila[12] != "Sin programa especifico")
            {
                it = find(codigosSnies.begin(), codigosSnies.end(), stoi(vectorFila[12]));
            }
            else
            {
                it = codigosSnies.end();
            }

            // Verificar si hace parte de los programas que me interesan
            if (it != codigosSnies.end()) // Caso donde si estaba dentro de los programas que me interesan
            {
                // Termino de leer y guardar primera fila
                vectorFila[columna] = dato; // Guardamos el dato que habiamos geteado justo antes de hacer la verificacion
                columna++;
                while ((getline(streamFila, dato, Settings:: delimitador)))
                {
                    vectorFila[columna] = dato;
                    columna++;
                }
                matrizResultado.push_back(vectorFila);

                // Leo y guardo filas restantes
                for (int j = 0; j < 3; j++)
                {
                    getline(archivoPrimero, fila);
                    streamFila = stringstream(fila);
                    columna = 0;
                    while ((getline(streamFila, dato, Settings:: delimitador)))
                    {
                        vectorFila[columna] = dato;
                        columna++;
                    }
                    matrizResultado.push_back(vectorFila);
                }
            }
            // Si es de los programas que no me interesan, sigo a la siguiente fila, sin guardar la fila en la matriz de resultados
        }
    }

    archivoPrimero.close();

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

vector<vector<string>> GestorCsv::leerArchivoSegunda(string &rutaBase, string &ano, vector<int> &codigosSnies)
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
        vector<string> vectorFila(6);
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
            while ((getline(streamFila, dato, Settings:: delimitador)) && (columnaArchivo < 13))
            {
                if (columnaArchivo == 12)
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
                // Termino de leer y guardar primera fila
                columnaArchivo++; // Esto se debe a la iteracion en que hacemos getline sin subirle a la columaArchivo porque nos salimos del bucle
                while (getline(streamFila, dato, Settings:: delimitador))
                {
                    if (columnaArchivo >= 34)
                    {
                        vectorFila[columnaVector] = dato;
                        columnaVector++;
                    }
                    columnaArchivo++;
                }
                matrizResultado.push_back(vectorFila);

                // Leer las otras 3 filas
                for (int i = 0; i < 3; i++)
                {
                    getline(archivoSegundo, fila);
                    streamFila = stringstream(fila);
                    columnaArchivo = 0;
                    columnaVector = 0;
                    while (getline(streamFila, dato, Settings:: delimitador))
                    {
                        if ((columnaArchivo >= 34) || (columnaArchivo == 12))
                        {
                            vectorFila[columnaVector] = dato;
                            columnaVector++;
                        }
                        columnaArchivo++;
                    }
                    matrizResultado.push_back(vectorFila);
                }
            }
            // Cuando no me interesa no hago nada
        }
    }

    /*
    Ejemplo de matrizResultado: (No tendría las etiquetas incluidas)
    CodigoSnies;IdSexo;SexoString;Ano;Semestre;Admitidos
    1; 1; Masculino; 2022; 1, 56
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
            while ((getline(streamFila, dato, Settings:: delimitador)) && (columnaArchivo < (colmunaCodigoSnies + 1)))
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
                while (getline(streamFila, dato, Settings:: delimitador))
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
                    while (getline(streamFila, dato, Settings:: delimitador))
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
            archivoResultados << etiquetasColumnas[i] << Settings:: delimitador;
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
                archivoResultados << (it->second)->getCodigoDeLaInstitucion() << Settings:: delimitador;
                archivoResultados << (it->second)->getIesPadre() << Settings:: delimitador;
                archivoResultados << (it->second)->getInstitucionDeEducacionSuperiorIes() << Settings:: delimitador;
                archivoResultados << (it->second)->getPrincipalOSeccional() << Settings:: delimitador;
                archivoResultados << (it->second)->getIdSectorIes() << Settings:: delimitador;
                archivoResultados << (it->second)->getSectorIes() << Settings:: delimitador;
                archivoResultados << (it->second)->getIdCaracter() << Settings:: delimitador;
                archivoResultados << (it->second)->getCaracterIes() << Settings:: delimitador;
                archivoResultados << (it->second)->getCodigoDelDepartamentoIes() << Settings:: delimitador;
                archivoResultados << (it->second)->getDepartamentoDeDomicilioDeLaIes() << Settings:: delimitador;
                archivoResultados << (it->second)->getCodigoDelMunicipioIes() << Settings:: delimitador;
                archivoResultados << (it->second)->getMunicipioDeDomicilioDeLaIes() << Settings:: delimitador;
                archivoResultados << (it->second)->getCodigoSniesDelPrograma() << Settings:: delimitador;
                archivoResultados << (it->second)->getProgramaAcademico() << Settings:: delimitador;
                archivoResultados << (it->second)->getIdNivelAcademico() << Settings:: delimitador;
                archivoResultados << (it->second)->getNivelAcademico() << Settings:: delimitador;
                archivoResultados << (it->second)->getIdNivelDeFormacion() << Settings:: delimitador;
                archivoResultados << (it->second)->getNivelDeFormacion() << Settings:: delimitador;
                archivoResultados << (it->second)->getIdMetodologia() << Settings:: delimitador;
                archivoResultados << (it->second)->getMetodologia() << Settings:: delimitador;
                archivoResultados << (it->second)->getIdArea() << Settings:: delimitador;
                archivoResultados << (it->second)->getAreaDeConocimiento() << Settings:: delimitador;
                archivoResultados << (it->second)->getIdNucleo() << Settings:: delimitador;
                archivoResultados << (it->second)->getNucleoBasicoDelConocimientoNbc() << Settings:: delimitador;
                archivoResultados << (it->second)->getIdCineCampoAmplio() << Settings:: delimitador;
                archivoResultados << (it->second)->getDescCineCampoAmplio() << Settings:: delimitador;
                archivoResultados << (it->second)->getIdCineCampoEspecifico() << Settings:: delimitador;
                archivoResultados << (it->second)->getDescCineCampoEspecifico() << Settings:: delimitador;
                archivoResultados << (it->second)->getIdCineCodigoDetallado() << Settings:: delimitador;
                archivoResultados << (it->second)->getDescCineCodigoDetallado() << Settings:: delimitador;
                archivoResultados << (it->second)->getCodigoDelDepartamentoPrograma() << Settings:: delimitador;
                archivoResultados << (it->second)->getDepartamentoDeOfertaDelPrograma() << Settings:: delimitador;
                archivoResultados << (it->second)->getCodigoDelMunicipioPrograma() << Settings:: delimitador;
                archivoResultados << (it->second)->getMunicipioDeOfertaDelPrograma() << Settings:: delimitador;

                // Imprimimos la información del consolidado: (ID SEXO;SEXO;AÑO;SEMESTRE;ADMITIDOS;GRADUADOS;INSCRITOS;MATRICULADOS;NEOS)
                Consolidado *consolidadoActual = (it->second)->getConsolidado(i);
                archivoResultados << consolidadoActual->getIdSexo() << Settings:: delimitador;
                archivoResultados << consolidadoActual->getSexo() << Settings:: delimitador;
                archivoResultados << consolidadoActual->getAno() << Settings:: delimitador;
                archivoResultados << consolidadoActual->getSemestre() << Settings:: delimitador;
                archivoResultados << consolidadoActual->getAdmitidos() << Settings:: delimitador;
                archivoResultados << consolidadoActual->getGraduados() << Settings:: delimitador;
                archivoResultados << consolidadoActual->getInscritos() << Settings:: delimitador;
                archivoResultados << consolidadoActual->getMatriculados() << Settings:: delimitador;
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
            archivoBuscados << etiquetasColumnas[i] << Settings:: delimitador;
        }
        archivoBuscados << "GRADUADOS;INSCRITOS;MATRICULADOS;NEOS" << endl;

        list<ProgramaAcademico *>::iterator it;
        // Leemos todos los programas de la lista de los programas buscados para imprimirlos
        for (it = programasBuscados.begin(); it != programasBuscados.end(); it++)
        {
            // Imprimimos los 8 consolidados del programa
            for (int i = 0; i < Settings:: COMUNAS_INFO_CONSOLIDADOS; i++)
            {
                // Imprimimos la informacion base del programa
                archivoBuscados << (*it)->getCodigoDeLaInstitucion() << Settings:: delimitador;
                archivoBuscados << (*it)->getIesPadre() << Settings:: delimitador;
                archivoBuscados << (*it)->getInstitucionDeEducacionSuperiorIes() << Settings:: delimitador;
                archivoBuscados << (*it)->getPrincipalOSeccional() << Settings:: delimitador;
                archivoBuscados << (*it)->getIdSectorIes() << Settings:: delimitador;
                archivoBuscados << (*it)->getSectorIes() << Settings:: delimitador;
                archivoBuscados << (*it)->getIdCaracter() << Settings:: delimitador;
                archivoBuscados << (*it)->getCaracterIes() << Settings:: delimitador;
                archivoBuscados << (*it)->getCodigoDelDepartamentoIes() << Settings:: delimitador;
                archivoBuscados << (*it)->getDepartamentoDeDomicilioDeLaIes() << Settings:: delimitador;
                archivoBuscados << (*it)->getCodigoDelMunicipioIes() << Settings:: delimitador;
                archivoBuscados << (*it)->getMunicipioDeDomicilioDeLaIes() << Settings:: delimitador;
                archivoBuscados << (*it)->getCodigoSniesDelPrograma() << Settings:: delimitador;
                archivoBuscados << (*it)->getProgramaAcademico() << Settings:: delimitador;
                archivoBuscados << (*it)->getIdNivelAcademico() << Settings:: delimitador;
                archivoBuscados << (*it)->getNivelAcademico() << Settings:: delimitador;
                archivoBuscados << (*it)->getIdNivelDeFormacion() << Settings:: delimitador;
                archivoBuscados << (*it)->getNivelDeFormacion() << Settings:: delimitador;
                archivoBuscados << (*it)->getIdMetodologia() << Settings:: delimitador;
                archivoBuscados << (*it)->getMetodologia() << Settings:: delimitador;
                archivoBuscados << (*it)->getIdArea() << Settings:: delimitador;
                archivoBuscados << (*it)->getAreaDeConocimiento() << Settings:: delimitador;
                archivoBuscados << (*it)->getIdNucleo() << Settings:: delimitador;
                archivoBuscados << (*it)->getNucleoBasicoDelConocimientoNbc() << Settings:: delimitador;
                archivoBuscados << (*it)->getIdCineCampoAmplio() << Settings:: delimitador;
                archivoBuscados << (*it)->getDescCineCampoAmplio() << Settings:: delimitador;
                archivoBuscados << (*it)->getIdCineCampoEspecifico() << Settings:: delimitador;
                archivoBuscados << (*it)->getDescCineCampoEspecifico() << Settings:: delimitador;
                archivoBuscados << (*it)->getIdCineCodigoDetallado() << Settings:: delimitador;
                archivoBuscados << (*it)->getDescCineCodigoDetallado() << Settings:: delimitador;
                archivoBuscados << (*it)->getCodigoDelDepartamentoPrograma() << Settings:: delimitador;
                archivoBuscados << (*it)->getDepartamentoDeOfertaDelPrograma() << Settings:: delimitador;
                archivoBuscados << (*it)->getCodigoDelMunicipioPrograma() << Settings:: delimitador;
                archivoBuscados << (*it)->getMunicipioDeOfertaDelPrograma() << Settings:: delimitador;

                // Imprimimos la información del consolidado: (ID SEXO;SEXO;AÑO;SEMESTRE;ADMITIDOS;GRADUADOS;INSCRITOS;MATRICULADOS;NEOS)
                Consolidado *consolidadoActual = (*it)->getConsolidado(i);
                archivoBuscados << consolidadoActual->getIdSexo() << Settings:: delimitador;
                archivoBuscados << consolidadoActual->getSexo() << Settings:: delimitador;
                archivoBuscados << consolidadoActual->getAno() << Settings:: delimitador;
                archivoBuscados << consolidadoActual->getSemestre() << Settings:: delimitador;
                archivoBuscados << consolidadoActual->getAdmitidos() << Settings:: delimitador;
                archivoBuscados << consolidadoActual->getGraduados() << Settings:: delimitador;
                archivoBuscados << consolidadoActual->getInscritos() << Settings:: delimitador;
                archivoBuscados << consolidadoActual->getMatriculados() << Settings:: delimitador;
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
                    archivoExtra << Settings:: delimitador;
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