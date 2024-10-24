#include "View.h"

View::View()
{
    controlador = SNIESController();
}

View::~View()
{
    controlador.~SNIESController();
}

bool View::isConvetibleToInt(const string &str)
{
    if (str.empty()) 
    {
        return false;
    }

    try
    {
        size_t pos = 0;
        stoi(str, &pos); 
        return pos == str.length();
    }
    catch (const invalid_argument &)
    {
        return false;
    }
    catch (const out_of_range &)
    {
        return false;
    }
}

bool View::mostrarPantallaBienvenido()
{
    bool parametrizacionBool = false;

    cout << "Bienvenido al SNIES-Extractor!" << endl;
    cout << "=========================================" << endl;
    cout << "Recuerde que para el correcto funcionamiento del programa tuvo que haber parametrizado" << endl;
    cout << "Antes la carpeta SNIES_EXTRACTOR en el disco duro C:, con sus respectivas carpetas inputs y outputs" << endl;
    cout << "y todos los archivo CSV del SNIES." << endl;

    string userAnswer;
    try
    {
        if (validarEntrada(userAnswer, false))
        {
            parametrizacionBool = true;

            string userText;
            cout << "A continuación se procesarán los datos de los programas académicos seleccionados en /programas.csv..." << endl;

            string anio1;
            string ano2;
            cout << "Escriba el primer año de búsqueda: ";
            cin >> anio1;
            if (!validarEntrada(anio1, true))
            {
                // Lanzar una excepción si el año no es válido
                throw invalid_argument("El primer año ingresado no es válido.");
            }
            cout << endl;

            cout << "Escriba el segundo año de búsqueda: ";
            cin >> ano2;
            if (!validarEntrada(ano2, true))
            {
                // Lanzar una excepción si el segundo año no es válido
                throw invalid_argument("El segundo año ingresado no es válido.");
            }
            cout << endl;

            organizarAnios(anio1, ano2);

            cout << "Procesando datos ..." << endl;
            controlador.procesarDatosCsv(anio1, ano2);
            cout << "Datos procesados con éxito!" << endl;
        }
    }
    catch (const invalid_argument& e)
    {
        // Manejo de excepciones de argumentos inválidos
        cerr << "Error: " << e.what() << endl;
        parametrizacionBool = false; // Indicar que la parametrización no se completó con éxito
    }
    catch (...)
    {
        // Manejo de cualquier otra excepción no específica
        cerr << "Se produjo un error desconocido." << endl;
        parametrizacionBool = false;
    }

    return parametrizacionBool;
}

void View::salir()
{
    cout << "Cerrando programa..." << endl;
    cout << "Recuerde revisar la carpeta de outputs para los archivos .csv exportados" << endl;
    cout << "Programa Cerrado con exito!" << endl;
}


bool View::validarEntrada(string& entrada, bool esAno = false)
{
    while (true)
    {
        try
        {
            if (esAno)
            {
                if (isConvetibleToInt(entrada))
                {
                    return true;
                }
                else
                {
                    // Lanzar una excepción si la entrada no es convertible a un número entero
                    throw invalid_argument("El valor ingresado no es un año válido.");
                }
            }
            else
            {
                cout << "Si ya hizo esto, escriba 'Y', de lo contrario 'N', y presione Enter: ";
                cin >> entrada;
                entrada[0] = static_cast<char>(tolower(entrada[0]));

                if (entrada[0] == 'y' || entrada[0] == 'n')
                {
                    return entrada[0] == 'y';
                }
                else
                {
                    // Lanzar una excepción si la entrada no es 'Y' o 'N'
                    throw invalid_argument("Entrada no válida. Debe ser 'Y' o 'N'.");
                }
            }
        }
        catch (const invalid_argument& e)
        {
            // Captura de excepciones de argumentos inválidos
            cerr << "Error: " << e.what() << endl;

            // Pedir al usuario que ingrese nuevamente en caso de error
            if (esAno)
            {
                cout << "Por favor, ingrese un año válido: ";
            }
            else
            {
                cout << "Por favor, ingrese 'Y' o 'N': ";
            }
            cin >> entrada;
        }
        catch (...)
        {
            // Captura de cualquier otra excepción no específica
            cerr << "Se produjo un error desconocido." << endl;
            return false; // Salir en caso de error no manejado
        }
    }
}

bool View:: validarEntradaYN() {
    char opcion;
    bool flag = false;

    while (!flag) {
        cin >> opcion;
        opcion = tolower(opcion);

        if (opcion == 'y') {
            flag = true;
        }
        else if (opcion == 'n') {
            flag = false;
            break;
        }
        else {
            cout << "Entrada inválida. Por favor ingrese 'Y' o 'N': " << endl;
        }
    }

    return flag;
}


void View::mostrarDatosExtra() {
    cout << "A continuación vamos a mostrar datos relevantes de los programas académicos seleccionados" << "\n"
         << endl;
    cout << "Desea Convertir los datos a un archivo CSV, TXT O JSON?(Y/N): " << endl;

    bool opcionYN = validarEntradaYN();
    controlador.calcularDatosExtra(opcionYN);

}



void View::buscarPorPalabraClaveYFormacion()
{
    char opcionYN = 'y', opcionCSV;
    string palabraClave;
    bool convertirCSV;
    int idFormacionAcademica;

    while (opcionYN == 'y')
    {
        cout << "Desea hacer una búsqueda por palabra clave del nombre del programa(Y/N): " << endl;
        cin >> opcionYN;
        cout << "\n";
        opcionYN = tolower(opcionYN);

        if (opcionYN == 'y')
        {
            cout << "Deseas convertir convertir los datos del programa académico a un CSV?(Y/N): " << endl;
            cin >> opcionCSV;
            cout << "\n";
            opcionCSV = tolower(opcionCSV);

            if (opcionCSV == 'y')
            {
                convertirCSV = true;
            }

            else
            {
                convertirCSV = false;
            }

            cout << "Escriba la palabra clave para buscar los programas por nombre:" << endl;
            cin >> palabraClave;
            cout << endl;

            cout << "Seleccione un nivel de formación para filtrar: \n 1->Especializacion Universitaria\n 2->Maestria\n 3->Doctorado\n 4->Formacion Tecnica Profesional \n 5->Tecnologico\n 6->Universitario\n 7->Especializacion Tecnico Profesional\n 8->Especializacion Tecnologica\n 10->Especializacion Medico Quirurgica\n " << endl;
            cin >> idFormacionAcademica;
            cout << "\n";
            while ((idFormacionAcademica > 10) || (idFormacionAcademica == 9) || (idFormacionAcademica < 1))
            {
                cout << "Seleccione una opcion entre 1-10 excluyendo el 9\n"
                     << endl;
                cin >> idFormacionAcademica;
            }

            controlador.buscarProgramas(convertirCSV, palabraClave, idFormacionAcademica);
        }
    }
}

void View:: organizarAnios(string &anio1, string &anio2) {
    if (stoi(anio2) < stoi(anio1)) {
        string anoAux = anio1; 
        anio1 = anio2;
        anio2 = anoAux; 

    }
}