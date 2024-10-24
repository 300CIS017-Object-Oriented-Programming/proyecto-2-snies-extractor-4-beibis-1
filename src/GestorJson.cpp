#include "GestorJson.h"

bool GestorJson::crearArchivo(string &ruta, map<int, ProgramaAcademico *> &mapadeProgramasAcademicos, vector<string> &etiquetasColumnas)
{
    // Verificar si se creó exitosamente el archivo
    bool estadoCreacion = false;
    string rutaCompleta = ruta + "resultados.json";
    ofstream archivoResultados(rutaCompleta);
    if (archivoResultados.is_open())
    {
        archivoResultados << "[" << endl;

        map<int, ProgramaAcademico *>::iterator it;
        bool esPrimero = true; // Para controlar la coma entre objetos se leen todos los programas del mapa para imprimirlos en el archivo
        for (it = mapadeProgramasAcademicos.begin(); it != mapadeProgramasAcademicos.end(); it++) {
            if (!esPrimero) {
                archivoResultados << "," << endl; 
                
            }
            esPrimero = false;

            archivoResultados << "  {" << endl;
            archivoResultados << R"(    "CodigoDeLaInstitucion": ")" << (it->second)->getCodigoDeLaInstitucion() << "\"," << endl;
            archivoResultados << R"(    "IesPadre": ")" << (it->second)->getIesPadre() << "\"," << endl;
            archivoResultados << R"(    "InstitucionDeEducacionSuperiorIes": ")" << (it->second)->getInstitucionDeEducacionSuperiorIes() << "\"," << endl;
            archivoResultados << R"(    "PrincipalOSeccional": ")" << (it->second)->getPrincipalOSeccional() << "\"," << endl;
            archivoResultados << R"(    "IdSectorIes": ")" << (it->second)->getIdSectorIes() << "\"," << endl;
            archivoResultados << R"(    "SectorIes": ")" << (it->second)->getSectorIes() << "\"," << endl;
            archivoResultados << R"(    "IdCaracter": ")" << (it->second)->getIdCaracter() << "\"," << endl;
            archivoResultados << R"(    "CaracterIes": ")" << (it->second)->getCaracterIes() << "\"," << endl;
            archivoResultados << R"(    "CodigoDelDepartamentoIes": ")" << (it->second)->getCodigoDelDepartamentoIes() << "\"," << endl;
            archivoResultados << R"(    "DepartamentoDeDomicilioDeLaIes": ")" << (it->second)->getDepartamentoDeDomicilioDeLaIes() << "\"," << endl;
            archivoResultados << R"(    "CodigoDelMunicipioIes": ")" << (it->second)->getCodigoDelMunicipioIes() << "\"," << endl;
            archivoResultados << R"(    "MunicipioDeDomicilioDeLaIes": ")" << (it->second)->getMunicipioDeDomicilioDeLaIes() << "\"," << endl;
            archivoResultados << R"(    "CodigoSniesDelPrograma": ")" << (it->second)->getCodigoSniesDelPrograma() << "\"," << endl;
            archivoResultados << R"(    "ProgramaAcademico": ")" << (it->second)->getProgramaAcademico() << "\"," << endl;
            archivoResultados << R"(    "IdNivelAcademico": ")" << (it->second)->getIdNivelAcademico() << "\"," << endl;
            archivoResultados << R"(    "NivelAcademico": ")" << (it->second)->getNivelAcademico() << "\"," << endl;
            archivoResultados << R"(    "IdNivelDeFormacion": ")" << (it->second)->getIdNivelDeFormacion() << "\"," << endl;
            archivoResultados << R"(    "NivelDeFormacion": ")" << (it->second)->getNivelDeFormacion() << "\"," << endl;
            archivoResultados << R"(    "IdMetodologia": ")" << (it->second)->getIdMetodologia() << "\"," << endl;
            archivoResultados << R"(    "Metodologia": ")" << (it->second)->getMetodologia() << "\"," << endl;
            archivoResultados << R"(    "IdArea": ")" << (it->second)->getIdArea() << "\"," << endl;
            archivoResultados << R"(    "AreaDeConocimiento": ")" << (it->second)->getAreaDeConocimiento() << "\"," << endl;
            archivoResultados << R"(    "IdNucleo": ")" << (it->second)->getIdNucleo() << "\"," << endl;
            archivoResultados << R"(    "NucleoBasicoDelConocimientoNbc": ")" << (it->second)->getNucleoBasicoDelConocimientoNbc() << "\"," << endl;

            // Lista de consolidados
            archivoResultados << "    \"Consolidados\": [" << endl;

            for (int i = 0; i < Settings::COLUMNAS_INFO_CONSOLIDADOS; i++)
            {
                Consolidado *consolidadoActual = (it->second)->getConsolidado(i);
                archivoResultados << "      {" << endl;
                archivoResultados << R"(        "IdSexo": ")" << consolidadoActual->getIdSexo() << "\"," << endl;
                archivoResultados << R"(        "Sexo": ")" << consolidadoActual->getSexo() << "\"," << endl;
                archivoResultados << R"(        "Ano": )" << consolidadoActual->getAno() << "," << endl;
                archivoResultados << R"(        "Semestre": )" << consolidadoActual->getSemestre() << "," << endl;
                archivoResultados << R"(        "Admitidos": )" << consolidadoActual->getAdmitidos() << "," << endl;
                archivoResultados << R"(        "Graduados": )" << consolidadoActual->getGraduados() << "," << endl;
                archivoResultados << R"(        "Inscritos": )" << consolidadoActual->getInscritos() << "," << endl;
                archivoResultados << R"(        "Matriculados": )" << consolidadoActual->getMatriculados() << "," << endl;
                archivoResultados << R"(        "MatriculadosPrimerSemestre": )" << consolidadoActual->getMatriculadosPrimerSemestre() << endl;
                archivoResultados << "      }" << (i < 7 ? "," : "") << endl; // Coma entre consolidados, excepto el último
            }

            archivoResultados << "    ]" << endl; // Cierra lista de consolidados
            archivoResultados << "  }"; // Cierra objeto de programa académico
        }

        archivoResultados << endl << "]" << endl; // Cierra el array de programas académicos

        estadoCreacion = true;
        cout << "Archivo Creado en: " << rutaCompleta << endl;
    }

    archivoResultados.close();
    return estadoCreacion;
}


bool GestorJson::crearArchivoBuscados(string &ruta, list<ProgramaAcademico *> &programasBuscados, vector<string> &etiquetasColumnas) {
    bool estadoCreacion = false;
    string rutaCompleta = ruta + "buscados.json";
    ofstream archivoBuscados(rutaCompleta);

    if (archivoBuscados.is_open()) {
        archivoBuscados << "[" << endl;  // Inicio del array JSON

        list<ProgramaAcademico *>::iterator it;
        bool primero = true;  // Controlar coma entre objetos
        for (it = programasBuscados.begin(); it != programasBuscados.end(); it++) {
            if (!primero) {
                archivoBuscados << "," << endl; 
            }
            primero = false;

            archivoBuscados << "    {" << endl;  // Inicio del objeto
            archivoBuscados << R"(        "codigo_de_la_institucion": ")" << (*it)->getCodigoDeLaInstitucion() << "\"," << endl;
            archivoBuscados << R"(        "ies_padre": ")" << (*it)->getIesPadre() << "\"," << endl;
            archivoBuscados << R"(        "institucion_de_educacion_superior": ")" << (*it)->getInstitucionDeEducacionSuperiorIes() << "\"," << endl;
            archivoBuscados << R"(        "principal_o_seccional": ")" << (*it)->getPrincipalOSeccional() << "\"," << endl;
            archivoBuscados << R"(        "id_sector": ")" << (*it)->getIdSectorIes() << "\"," << endl;
            archivoBuscados << R"(        "sector": ")" << (*it)->getSectorIes() << "\"," << endl;
            archivoBuscados << R"(        "id_caracter": ")" << (*it)->getIdCaracter() << "\"," << endl;
            archivoBuscados << R"(        "caracter": ")" << (*it)->getCaracterIes() << "\"," << endl;
            archivoBuscados << R"(        "codigo_departamento": ")" << (*it)->getCodigoDelDepartamentoIes() << "\"," << endl;
            archivoBuscados << R"(        "departamento_domicilio": ")" << (*it)->getDepartamentoDeDomicilioDeLaIes() << "\"," << endl;
            archivoBuscados << R"(        "codigo_municipio": ")" << (*it)->getCodigoDelMunicipioIes() << "\"," << endl;
            archivoBuscados << R"(        "municipio_domicilio": ")" << (*it)->getMunicipioDeDomicilioDeLaIes() << "\"," << endl;
            archivoBuscados << R"(        "codigo_snies_programa": ")" << (*it)->getCodigoSniesDelPrograma() << "\"," << endl;
            archivoBuscados << R"(        "programa_academico": ")" << (*it)->getProgramaAcademico() << "\"," << endl;
            archivoBuscados << R"(        "id_nivel_academico": ")" << (*it)->getIdNivelAcademico() << "\"," << endl;
            archivoBuscados << R"(        "nivel_academico": ")" << (*it)->getNivelAcademico() << "\"," << endl;
            archivoBuscados << R"(        "id_nivel_formacion": ")" << (*it)->getIdNivelDeFormacion() << "\"," << endl;
            archivoBuscados << R"(        "nivel_formacion": ")" << (*it)->getNivelDeFormacion() << "\"," << endl;
            archivoBuscados << R"(        "id_metodologia": ")" << (*it)->getIdMetodologia() << "\"," << endl;
            archivoBuscados << R"(        "metodologia": ")" << (*it)->getMetodologia() << "\"," << endl;
            archivoBuscados << R"(        "id_area": ")" << (*it)->getIdArea() << "\"," << endl;
            archivoBuscados << R"(        "area_de_conocimiento": ")" << (*it)->getAreaDeConocimiento() << "\"," << endl;
            archivoBuscados << R"(        "id_nucleo": ")" << (*it)->getIdNucleo() << "\"," << endl;
            archivoBuscados << R"(        "nucleo_basico": ")" << (*it)->getNucleoBasicoDelConocimientoNbc() << "\"," << endl;
            archivoBuscados << R"(        "id_cine_campo_amplio": ")" << (*it)->getIdCineCampoAmplio() << "\"," << endl;
            archivoBuscados << R"(        "desc_cine_campo_amplio": ")" << (*it)->getDescCineCampoAmplio() << "\"," << endl;
            archivoBuscados << R"(        "id_cine_campo_especifico": ")" << (*it)->getIdCineCampoEspecifico() << "\"," << endl;
            archivoBuscados << R"(        "desc_cine_campo_especifico": ")" << (*it)->getDescCineCampoEspecifico() << "\"," << endl;
            archivoBuscados << R"(        "id_cine_codigo_detallado": ")" << (*it)->getIdCineCodigoDetallado() << "\"," << endl;
            archivoBuscados << R"(        "desc_cine_codigo_detallado": ")" << (*it)->getDescCineCodigoDetallado() << "\"," << endl;
            archivoBuscados << R"(        "codigo_departamento_programa": ")" << (*it)->getCodigoDelDepartamentoPrograma() << "\"," << endl;
            archivoBuscados << R"(        "departamento_oferta_programa": ")" << (*it)->getDepartamentoDeOfertaDelPrograma() << "\"," << endl;
            archivoBuscados << R"(        "codigo_municipio_programa": ")" << (*it)->getCodigoDelMunicipioPrograma() << "\"," << endl;
            archivoBuscados << R"(        "municipio_oferta_programa": ")" << (*it)->getMunicipioDeOfertaDelPrograma() << "\"," << endl;

            // Información del consolidado
            for (int i = 0; i < Settings::COLUMNAS_INFO_CONSOLIDADOS; i++) {
                Consolidado *consolidadoActual = (*it)->getConsolidado(i);
                archivoBuscados << "        \"consolidado_" << i << "\": {" << endl;
                archivoBuscados << R"(            "id_sexo": ")" << consolidadoActual->getIdSexo() << "\"," << endl;
                archivoBuscados << R"(            "sexo": ")" << consolidadoActual->getSexo() << "\"," << endl;
                archivoBuscados << R"(            "ano": ")" << consolidadoActual->getAno() << "\"," << endl;
                archivoBuscados << R"(            "semestre": ")" << consolidadoActual->getSemestre() << "\"," << endl;
                archivoBuscados << R"(            "admitidos": ")" << consolidadoActual->getAdmitidos() << "\"," << endl;
                archivoBuscados << R"(            "graduados": ")" << consolidadoActual->getGraduados() << "\"," << endl;
                archivoBuscados << R"(            "inscritos": ")" << consolidadoActual->getInscritos() << "\"," << endl;
                archivoBuscados << R"(            "matriculados": ")" << consolidadoActual->getMatriculados() << "\"," << endl;
                archivoBuscados << R"(            "matriculados_primer_semestre": ")" << consolidadoActual->getMatriculadosPrimerSemestre() << "\"" << endl;
                archivoBuscados << "        }"; // Cierre del objeto consolidado
                if (i < 7) {  // Evitar la coma después del último consolidado
                    archivoBuscados << ",";
                }
                archivoBuscados << endl;
            }
            archivoBuscados << "    }";  // Cierre del objeto del programa
        }

        archivoBuscados << endl << "]";  // Cierre del array JSON
        estadoCreacion = true;
        cout << "Archivo creado en: " << rutaCompleta << endl;
    }

    archivoBuscados.close();
    return estadoCreacion;
}


bool GestorJson::crearArchivoExtra(string &ruta, vector<vector<string>> &datosAImprimir)
{
    // Verificar creación si la creación del archivo fue exitosa
    bool estadoCreacion = false;
    string rutaCompleta = ruta + "extras.json";  // 
    ofstream archivoExtra(rutaCompleta);

    if (archivoExtra.is_open()) {
  
        archivoExtra << "[" << endl;

        for (int i = 0; i < datosAImprimir.size(); i++) {
            archivoExtra << "  {" << endl;  // Abrir un objeto JSON para cada fila

            for (int j = 0; j < datosAImprimir[i].size(); j++)
            {
// Se escribe cada dato como una clave-valor en formato JSON
                archivoExtra << "    \"columna" << j+1 << "\": \"" << datosAImprimir[i][j] << "\"";

                if (j != (datosAImprimir[i].size() - 1))
                {
                    archivoExtra << ",";
                }
                archivoExtra << endl;
            }

            archivoExtra << "  }";  // Cerrar el objeto JSON para la fila actual
            if (i != datosAImprimir.size() - 1)
            {
                archivoExtra << ",";  // Añadimos una coma entre objetos JSON
            }
            archivoExtra << endl;
        }

        archivoExtra << "]" << endl;  
        estadoCreacion = true;
        
        cout << "Archivo JSON creado en: " << rutaCompleta << endl;
    }

    archivoExtra.close();
    return estadoCreacion;
}

