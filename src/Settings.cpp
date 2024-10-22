#include "Settings.h"

// Inicialización de las variables estáticas fuera de la clase.
const std::string Settings::BASE_PATH = "C:/SNIES_EXTRACTOR/inputs/";
const std::string Settings::PROGRAMAS_FILTRAR_FILE_PATH = Settings::BASE_PATH + "programas.csv";
const std::string Settings::ADMITIDOS_FILE_PATH = Settings::BASE_PATH + "admitidos";
const std::string Settings::MATRICULADOS_FILE_PATH = Settings::BASE_PATH + "matriculados";
const std::string Settings::INSCRITOS_FILE_PATH = Settings::BASE_PATH + "inscritos";
const char Settings::delimitador = ';';