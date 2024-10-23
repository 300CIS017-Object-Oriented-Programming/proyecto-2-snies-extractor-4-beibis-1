#include "GestorJson.h"

bool GestorJson::crearArchivo(string &ruta, map<int, ProgramaAcademico *> &mapadeProgramasAcademicos, vector<string> etiquetasColumnas)
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
            archivoResultados << "    \"CodigoDeLaInstitucion\": \"" << (it->second)->getCodigoDeLaInstitucion() << "\"," << endl;
            archivoResultados << "    \"IesPadre\": \"" << (it->second)->getIesPadre() << "\"," << endl;
            archivoResultados << "    \"InstitucionDeEducacionSuperiorIes\": \"" << (it->second)->getInstitucionDeEducacionSuperiorIes() << "\"," << endl;
            archivoResultados << "    \"PrincipalOSeccional\": \"" << (it->second)->getPrincipalOSeccional() << "\"," << endl;
            archivoResultados << "    \"IdSectorIes\": \"" << (it->second)->getIdSectorIes() << "\"," << endl;
            archivoResultados << "    \"SectorIes\": \"" << (it->second)->getSectorIes() << "\"," << endl;
            archivoResultados << "    \"IdCaracter\": \"" << (it->second)->getIdCaracter() << "\"," << endl;
            archivoResultados << "    \"CaracterIes\": \"" << (it->second)->getCaracterIes() << "\"," << endl;
            archivoResultados << "    \"CodigoDelDepartamentoIes\": \"" << (it->second)->getCodigoDelDepartamentoIes() << "\"," << endl;
            archivoResultados << "    \"DepartamentoDeDomicilioDeLaIes\": \"" << (it->second)->getDepartamentoDeDomicilioDeLaIes() << "\"," << endl;
            archivoResultados << "    \"CodigoDelMunicipioIes\": \"" << (it->second)->getCodigoDelMunicipioIes() << "\"," << endl;
            archivoResultados << "    \"MunicipioDeDomicilioDeLaIes\": \"" << (it->second)->getMunicipioDeDomicilioDeLaIes() << "\"," << endl;
            archivoResultados << "    \"CodigoSniesDelPrograma\": \"" << (it->second)->getCodigoSniesDelPrograma() << "\"," << endl;
            archivoResultados << "    \"ProgramaAcademico\": \"" << (it->second)->getProgramaAcademico() << "\"," << endl;
            archivoResultados << "    \"IdNivelAcademico\": \"" << (it->second)->getIdNivelAcademico() << "\"," << endl;
            archivoResultados << "    \"NivelAcademico\": \"" << (it->second)->getNivelAcademico() << "\"," << endl;
            archivoResultados << "    \"IdNivelDeFormacion\": \"" << (it->second)->getIdNivelDeFormacion() << "\"," << endl;
            archivoResultados << "    \"NivelDeFormacion\": \"" << (it->second)->getNivelDeFormacion() << "\"," << endl;
            archivoResultados << "    \"IdMetodologia\": \"" << (it->second)->getIdMetodologia() << "\"," << endl;
            archivoResultados << "    \"Metodologia\": \"" << (it->second)->getMetodologia() << "\"," << endl;
            archivoResultados << "    \"IdArea\": \"" << (it->second)->getIdArea() << "\"," << endl;
            archivoResultados << "    \"AreaDeConocimiento\": \"" << (it->second)->getAreaDeConocimiento() << "\"," << endl;
            archivoResultados << "    \"IdNucleo\": \"" << (it->second)->getIdNucleo() << "\"," << endl;
            archivoResultados << "    \"NucleoBasicoDelConocimientoNbc\": \"" << (it->second)->getNucleoBasicoDelConocimientoNbc() << "\"," << endl;

            // Lista de consolidados
            archivoResultados << "    \"Consolidados\": [" << endl;

            for (int i = 0; i < Settings::COLUMNAS_INFO_CONSOLIDADOS; i++)
            {
                Consolidado *consolidadoActual = (it->second)->getConsolidado(i);
                archivoResultados << "      {" << endl;
                archivoResultados << "        \"IdSexo\": \"" << consolidadoActual->getIdSexo() << "\"," << endl;
                archivoResultados << "        \"Sexo\": \"" << consolidadoActual->getSexo() << "\"," << endl;
                archivoResultados << "        \"Ano\": " << consolidadoActual->getAno() << "," << endl;
                archivoResultados << "        \"Semestre\": " << consolidadoActual->getSemestre() << "," << endl;
                archivoResultados << "        \"Admitidos\": " << consolidadoActual->getAdmitidos() << "," << endl;
                archivoResultados << "        \"Graduados\": " << consolidadoActual->getGraduados() << "," << endl;
                archivoResultados << "        \"Inscritos\": " << consolidadoActual->getInscritos() << "," << endl;
                archivoResultados << "        \"Matriculados\": " << consolidadoActual->getMatriculados() << "," << endl;
                archivoResultados << "        \"MatriculadosPrimerSemestre\": " << consolidadoActual->getMatriculadosPrimerSemestre() << endl;
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


bool GestorJson::crearArchivoBuscados(string &ruta, list<ProgramaAcademico *> &programasBuscados, vector<string> etiquetasColumnas) {
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
            archivoBuscados << "        \"codigo_de_la_institucion\": \"" << (*it)->getCodigoDeLaInstitucion() << "\"," << endl;
            archivoBuscados << "        \"ies_padre\": \"" << (*it)->getIesPadre() << "\"," << endl;
            archivoBuscados << "        \"institucion_de_educacion_superior\": \"" << (*it)->getInstitucionDeEducacionSuperiorIes() << "\"," << endl;
            archivoBuscados << "        \"principal_o_seccional\": \"" << (*it)->getPrincipalOSeccional() << "\"," << endl;
            archivoBuscados << "        \"id_sector\": \"" << (*it)->getIdSectorIes() << "\"," << endl;
            archivoBuscados << "        \"sector\": \"" << (*it)->getSectorIes() << "\"," << endl;
            archivoBuscados << "        \"id_caracter\": \"" << (*it)->getIdCaracter() << "\"," << endl;
            archivoBuscados << "        \"caracter\": \"" << (*it)->getCaracterIes() << "\"," << endl;
            archivoBuscados << "        \"codigo_departamento\": \"" << (*it)->getCodigoDelDepartamentoIes() << "\"," << endl;
            archivoBuscados << "        \"departamento_domicilio\": \"" << (*it)->getDepartamentoDeDomicilioDeLaIes() << "\"," << endl;
            archivoBuscados << "        \"codigo_municipio\": \"" << (*it)->getCodigoDelMunicipioIes() << "\"," << endl;
            archivoBuscados << "        \"municipio_domicilio\": \"" << (*it)->getMunicipioDeDomicilioDeLaIes() << "\"," << endl;
            archivoBuscados << "        \"codigo_snies_programa\": \"" << (*it)->getCodigoSniesDelPrograma() << "\"," << endl;
            archivoBuscados << "        \"programa_academico\": \"" << (*it)->getProgramaAcademico() << "\"," << endl;
            archivoBuscados << "        \"id_nivel_academico\": \"" << (*it)->getIdNivelAcademico() << "\"," << endl;
            archivoBuscados << "        \"nivel_academico\": \"" << (*it)->getNivelAcademico() << "\"," << endl;
            archivoBuscados << "        \"id_nivel_formacion\": \"" << (*it)->getIdNivelDeFormacion() << "\"," << endl;
            archivoBuscados << "        \"nivel_formacion\": \"" << (*it)->getNivelDeFormacion() << "\"," << endl;
            archivoBuscados << "        \"id_metodologia\": \"" << (*it)->getIdMetodologia() << "\"," << endl;
            archivoBuscados << "        \"metodologia\": \"" << (*it)->getMetodologia() << "\"," << endl;
            archivoBuscados << "        \"id_area\": \"" << (*it)->getIdArea() << "\"," << endl;
            archivoBuscados << "        \"area_de_conocimiento\": \"" << (*it)->getAreaDeConocimiento() << "\"," << endl;
            archivoBuscados << "        \"id_nucleo\": \"" << (*it)->getIdNucleo() << "\"," << endl;
            archivoBuscados << "        \"nucleo_basico\": \"" << (*it)->getNucleoBasicoDelConocimientoNbc() << "\"," << endl;
            archivoBuscados << "        \"id_cine_campo_amplio\": \"" << (*it)->getIdCineCampoAmplio() << "\"," << endl;
            archivoBuscados << "        \"desc_cine_campo_amplio\": \"" << (*it)->getDescCineCampoAmplio() << "\"," << endl;
            archivoBuscados << "        \"id_cine_campo_especifico\": \"" << (*it)->getIdCineCampoEspecifico() << "\"," << endl;
            archivoBuscados << "        \"desc_cine_campo_especifico\": \"" << (*it)->getDescCineCampoEspecifico() << "\"," << endl;
            archivoBuscados << "        \"id_cine_codigo_detallado\": \"" << (*it)->getIdCineCodigoDetallado() << "\"," << endl;
            archivoBuscados << "        \"desc_cine_codigo_detallado\": \"" << (*it)->getDescCineCodigoDetallado() << "\"," << endl;
            archivoBuscados << "        \"codigo_departamento_programa\": \"" << (*it)->getCodigoDelDepartamentoPrograma() << "\"," << endl;
            archivoBuscados << "        \"departamento_oferta_programa\": \"" << (*it)->getDepartamentoDeOfertaDelPrograma() << "\"," << endl;
            archivoBuscados << "        \"codigo_municipio_programa\": \"" << (*it)->getCodigoDelMunicipioPrograma() << "\"," << endl;
            archivoBuscados << "        \"municipio_oferta_programa\": \"" << (*it)->getMunicipioDeOfertaDelPrograma() << "\"," << endl;

            // Información del consolidado
            for (int i = 0; i < Settings::COLUMNAS_INFO_CONSOLIDADOS; i++) {
                Consolidado *consolidadoActual = (*it)->getConsolidado(i);
                archivoBuscados << "        \"consolidado_" << i << "\": {" << endl;
                archivoBuscados << "            \"id_sexo\": \"" << consolidadoActual->getIdSexo() << "\"," << endl;
                archivoBuscados << "            \"sexo\": \"" << consolidadoActual->getSexo() << "\"," << endl;
                archivoBuscados << "            \"ano\": \"" << consolidadoActual->getAno() << "\"," << endl;
                archivoBuscados << "            \"semestre\": \"" << consolidadoActual->getSemestre() << "\"," << endl;
                archivoBuscados << "            \"admitidos\": \"" << consolidadoActual->getAdmitidos() << "\"," << endl;
                archivoBuscados << "            \"graduados\": \"" << consolidadoActual->getGraduados() << "\"," << endl;
                archivoBuscados << "            \"inscritos\": \"" << consolidadoActual->getInscritos() << "\"," << endl;
                archivoBuscados << "            \"matriculados\": \"" << consolidadoActual->getMatriculados() << "\"," << endl;
                archivoBuscados << "            \"matriculados_primer_semestre\": \"" << consolidadoActual->getMatriculadosPrimerSemestre() << "\"" << endl;
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


bool GestorJson::crearArchivoExtra(string &ruta, vector<vector<string>> datosAImprimir)
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

