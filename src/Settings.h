/**
 * @file Settings.h
 * @brief Este archivo de encabezado define la clase Settings, que contiene variables de ruta de archivo constantes estáticas.
 *
 * La clase Settings se utiliza para almacenar rutas de archivos como constantes estáticas. Estas rutas están destinadas para su uso
 * en toda la aplicación, permitiendo un acceso fácil a las ubicaciones de varios archivos de entrada.
 *
 * Las siguientes constantes estáticas están definidas:
 * - ADMITIDOS_FILE_PATH: Ruta al archivo de entrada "admitidos".
 * - MATRICULADOS_FILE_PATH: Ruta al archivo de entrada "matriculados".
 * - INSCRITOS_FILE_PATH: Ruta al archivo de entrada "inscritos".
 * - PROGRAMAS_FILTRAR_FILE_PATH: Ruta al archivo de entrada "programas filtrar".
 *
 * Nota: Las constantes estáticas deben definirse fuera de la clase para asignar memoria a ellas.
 *
 *
 */

#ifndef SETTINGS_H
#define SETTINGS_H

#include <string>

class Settings
{
public:
    // Declaración de las variables estáticas como constantes.
    static const std::string ADMITIDOS_FILE_PATH;
    static const std::string MATRICULADOS_FILE_PATH;
    static const std::string INSCRITOS_FILE_PATH;
    static const std::string PROGRAMAS_FILTRAR_FILE_PATH;
    static const std::string BASE_PATH;
    static const char DELIMITADOR;
    static const int COLUMNAS_INFO_CONSOLIDADOS;
    static const int DATOS_ACADEM_DEMOGRAF;

};

#endif // SETTINGS_H