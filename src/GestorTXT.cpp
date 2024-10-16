#include "GestorTXT.h"

bool GestorTxt::crearArchivo(string &ruta, map<int, ProgramaAcademico *> &mapadeProgramasAcademicos, vector<string> etiquetasColumnas)
{
    // Verificar si se creó exitosamente el archivo
    bool estadoCreacion = false;
    string rutaCompleta = ruta + "resultados.txt";
    ofstream archivoResultados(rutaCompleta);
    if (archivoResultados.is_open())
    {
        // Se imprime en el archivo las etiquetas (Primera fila)
        for (int i = 0; i < etiquetasColumnas.size(); i++)
        {
            archivoResultados << etiquetasColumnas[i] << "    ";  // Usamos espacios en lugar de ";"
        }
        archivoResultados << "GRADUADOS    INSCRITOS    MATRICULADOS    NEOS" << endl;

        map<int, ProgramaAcademico *>::iterator it;
    
        for (it = mapadeProgramasAcademicos.begin(); it != mapadeProgramasAcademicos.end(); it++)
        {
            // Se imprimen los 8 consolidados
            for (int i = 0; i < 8; i++) {
                archivoResultados << (it->second)->getCodigoDeLaInstitucion() << "    ";
                archivoResultados << (it->second)->getIesPadre() << "    ";
                archivoResultados << (it->second)->getInstitucionDeEducacionSuperiorIes() << "    ";
                archivoResultados << (it->second)->getPrincipalOSeccional() << "    ";
                archivoResultados << (it->second)->getIdSectorIes() << "    ";
                archivoResultados << (it->second)->getSectorIes() << "    ";
                archivoResultados << (it->second)->getIdCaracter() << "    ";
                archivoResultados << (it->second)->getCaracterIes() << "    ";
                archivoResultados << (it->second)->getCodigoDelDepartamentoIes() << "    ";
                archivoResultados << (it->second)->getDepartamentoDeDomicilioDeLaIes() << "    ";
                archivoResultados << (it->second)->getCodigoDelMunicipioIes() << "    ";
                archivoResultados << (it->second)->getMunicipioDeDomicilioDeLaIes() << "    ";
                archivoResultados << (it->second)->getCodigoSniesDelPrograma() << "    ";
                archivoResultados << (it->second)->getProgramaAcademico() << "    ";
                archivoResultados << (it->second)->getIdNivelAcademico() << "    ";
                archivoResultados << (it->second)->getNivelAcademico() << "    ";
                archivoResultados << (it->second)->getIdNivelDeFormacion() << "    ";
                archivoResultados << (it->second)->getNivelDeFormacion() << "    ";
                archivoResultados << (it->second)->getIdMetodologia() << "    ";
                archivoResultados << (it->second)->getMetodologia() << "    ";
                archivoResultados << (it->second)->getIdArea() << "    ";
                archivoResultados << (it->second)->getAreaDeConocimiento() << "    ";
                archivoResultados << (it->second)->getIdNucleo() << "    ";
                archivoResultados << (it->second)->getNucleoBasicoDelConocimientoNbc() << "    ";
                archivoResultados << (it->second)->getIdCineCampoAmplio() << "    ";
                archivoResultados << (it->second)->getDescCineCampoAmplio() << "    ";
                archivoResultados << (it->second)->getIdCineCampoEspecifico() << "    ";
                archivoResultados << (it->second)->getDescCineCampoEspecifico() << "    ";
                archivoResultados << (it->second)->getIdCineCodigoDetallado() << "    ";
                archivoResultados << (it->second)->getDescCineCodigoDetallado() << "    ";
                archivoResultados << (it->second)->getCodigoDelDepartamentoPrograma() << "    ";
                archivoResultados << (it->second)->getDepartamentoDeOfertaDelPrograma() << "    ";
                archivoResultados << (it->second)->getCodigoDelMunicipioPrograma() << "    ";
                archivoResultados << (it->second)->getMunicipioDeOfertaDelPrograma() << "    ";

                // Imprimimos la información del consolidado: (ID SEXO;SEXO;AÑO;SEMESTRE;ADMITIDOS;GRADUADOS;INSCRITOS;MATRICULADOS;NEOS)
                
                Consolidado *consolidadoActual = (it->second)->getConsolidado(i);
                archivoResultados << consolidadoActual->getIdSexo() << "    ";
                archivoResultados << consolidadoActual->getSexo() << "    ";
                archivoResultados << consolidadoActual->getAno() << "    ";
                archivoResultados << consolidadoActual->getSemestre() << "    ";
                archivoResultados << consolidadoActual->getAdmitidos() << "    ";
                archivoResultados << consolidadoActual->getGraduados() << "    ";
                archivoResultados << consolidadoActual->getInscritos() << "    ";
                archivoResultados << consolidadoActual->getMatriculados() << "    ";
                archivoResultados << consolidadoActual->getMatriculadosPrimerSemestre();

                // Saltamos de línea para la siguiente fila
                archivoResultados << endl;
            }
        }

        // Cambiamos el valor del booleano si logramos llegar hasta este punto
        estadoCreacion = true;
        // Imprimimos ruta donde quedó el archivo
        cout << "Archivo Creado en: " << rutaCompleta << endl;
    }

    archivoResultados.close();
    return estadoCreacion;
}


bool GestorTxt::crearArchivoBuscados(string &ruta, list<ProgramaAcademico *> &programasBuscados, vector<string> etiquetasColumnas)
{
    // Este bool nos ayudará a saber si se creó exitosamente el archivo
    bool estadoCreacion = false;
    string rutaCompleta = ruta + "buscados.txt";  // Cambiamos la extensión a .txt
    ofstream archivoBuscados(rutaCompleta);
    if (archivoBuscados.is_open())
    {
        // Imprimimos en el archivo las etiquetas (Primera fila)
        for (int i = 0; i < etiquetasColumnas.size(); i++)
        {
            archivoBuscados << etiquetasColumnas[i] << "\t";  // Usamos tabulaciones en lugar de ';'
        }
        archivoBuscados << "GRADUADOS\tINSCRITOS\tMATRICULADOS\tNEOS" << endl;

        list<ProgramaAcademico *>::iterator it;
        for (it = programasBuscados.begin(); it != programasBuscados.end(); it++) {
            // Imprimir 8 consolidados del programa
            for (int i = 0; i < 8; i++) {
                archivoBuscados << (*it)->getCodigoDeLaInstitucion() << "\t";
                archivoBuscados << (*it)->getIesPadre() << "\t";
                archivoBuscados << (*it)->getInstitucionDeEducacionSuperiorIes() << "\t";
                archivoBuscados << (*it)->getPrincipalOSeccional() << "\t";
                archivoBuscados << (*it)->getIdSectorIes() << "\t";
                archivoBuscados << (*it)->getSectorIes() << "\t";
                archivoBuscados << (*it)->getIdCaracter() << "\t";
                archivoBuscados << (*it)->getCaracterIes() << "\t";
                archivoBuscados << (*it)->getCodigoDelDepartamentoIes() << "\t";
                archivoBuscados << (*it)->getDepartamentoDeDomicilioDeLaIes() << "\t";
                archivoBuscados << (*it)->getCodigoDelMunicipioIes() << "\t";
                archivoBuscados << (*it)->getMunicipioDeDomicilioDeLaIes() << "\t";
                archivoBuscados << (*it)->getCodigoSniesDelPrograma() << "\t";
                archivoBuscados << (*it)->getProgramaAcademico() << "\t";
                archivoBuscados << (*it)->getIdNivelAcademico() << "\t";
                archivoBuscados << (*it)->getNivelAcademico() << "\t";
                archivoBuscados << (*it)->getIdNivelDeFormacion() << "\t";
                archivoBuscados << (*it)->getNivelDeFormacion() << "\t";
                archivoBuscados << (*it)->getIdMetodologia() << "\t";
                archivoBuscados << (*it)->getMetodologia() << "\t";
                archivoBuscados << (*it)->getIdArea() << "\t";
                archivoBuscados << (*it)->getAreaDeConocimiento() << "\t";
                archivoBuscados << (*it)->getIdNucleo() << "\t";
                archivoBuscados << (*it)->getNucleoBasicoDelConocimientoNbc() << "\t";
                archivoBuscados << (*it)->getIdCineCampoAmplio() << "\t";
                archivoBuscados << (*it)->getDescCineCampoAmplio() << "\t";
                archivoBuscados << (*it)->getIdCineCampoEspecifico() << "\t";
                archivoBuscados << (*it)->getDescCineCampoEspecifico() << "\t";
                archivoBuscados << (*it)->getIdCineCodigoDetallado() << "\t";
                archivoBuscados << (*it)->getDescCineCodigoDetallado() << "\t";
                archivoBuscados << (*it)->getCodigoDelDepartamentoPrograma() << "\t";
                archivoBuscados << (*it)->getDepartamentoDeOfertaDelPrograma() << "\t";
                archivoBuscados << (*it)->getCodigoDelMunicipioPrograma() << "\t";
                archivoBuscados << (*it)->getMunicipioDeOfertaDelPrograma() << "\t";

                // Imprimimos la información del consolidado: (ID SEXO;SEXO;AÑO;SEMESTRE;ADMITIDOS;GRADUADOS;INSCRITOS;MATRICULADOS;NEOS)
                Consolidado *consolidadoActual = (*it)->getConsolidado(i);
                archivoBuscados << consolidadoActual->getIdSexo() << "\t";
                archivoBuscados << consolidadoActual->getSexo() << "\t";
                archivoBuscados << consolidadoActual->getAno() << "\t";
                archivoBuscados << consolidadoActual->getSemestre() << "\t";
                archivoBuscados << consolidadoActual->getAdmitidos() << "\t";
                archivoBuscados << consolidadoActual->getGraduados() << "\t";
                archivoBuscados << consolidadoActual->getInscritos() << "\t";
                archivoBuscados << consolidadoActual->getMatriculados() << "\t";
                archivoBuscados << consolidadoActual->getMatriculadosPrimerSemestre();
                // Saltamos de línea para la siguiente fila
                archivoBuscados << endl;
            }
        }

        estadoCreacion = true;
        cout << "Archivo Creado en: " << rutaCompleta << endl;
    }

    archivoBuscados.close();
    return estadoCreacion;
}

bool GestorTxt::crearArchivoExtra(string &ruta, vector<vector<string>> datosAImprimir)
{
    // Este bool nos ayudará a saber si se creó el archivo exitosamente
    bool estadoCreacion = false;
    string rutaCompleta = ruta + "extras.txt";  // Cambiamos la extensión a .txt
    ofstream archivoExtra(rutaCompleta);
    if (archivoExtra.is_open())
    {
        // Imprimimos la matriz de datos que queremos imprimir
        for (int i = 0; i < datosAImprimir.size(); i++)
        {
            // Imprimimos cada fila
            for (int j = 0; j < datosAImprimir[i].size(); j++)
            {
                // Imprimimos cada dato separado por tabulaciones
                archivoExtra << datosAImprimir[i][j];
                if (j != (datosAImprimir[i].size() - 1))
                {
                    archivoExtra << "\t";  // Usamos tabulación en lugar de ';'
                }
            }
            // Saltamos de línea al terminar una fila
            archivoExtra << endl;
        }

        // Cambiamos el valor del booleano si logramos llegar hasta este punto
        estadoCreacion = true;
        // Imprimimos la ruta donde quedó el archivo
        cout << "Archivo Creado en: " << rutaCompleta << endl;
    }

    archivoExtra.close();
    return estadoCreacion;
}
