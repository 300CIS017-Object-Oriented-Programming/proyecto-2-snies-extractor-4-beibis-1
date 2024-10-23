#include "Settings.h"

// Inicialización de las variables estáticas fuera de la clase.

  const std::string Settings::BASE_PATH = "C:/SNIES_EXTRACTOR/inputs/";
  const std::string Settings::PROGRAMAS_FILTRAR_FILE_PATH = Settings::BASE_PATH + "programas.csv";
  const std::string Settings::ADMITIDOS_FILE_PATH = Settings::BASE_PATH + "admitidos";
  const std::string Settings::MATRICULADOS_FILE_PATH = Settings::BASE_PATH + "matriculados";
  const std::string Settings::INSCRITOS_FILE_PATH = Settings::BASE_PATH + "inscritos";
  const char Settings::DELIMITADOR = ';';
  const int Settings::COLUMNAS_INFO_CONSOLIDADOS = 8;
  const int Settings::DATOS_ACADEM_DEMOGRAF = 4;
  const int Settings::COLUMNA_13 = 13;
  const int Settings::COLUMNA_12 = 12;
  const int Settings::FILAS_RESTANTES = 3; 


