#include "View.h"

View::View()
{
    // NEW quitar estas variables de aquí y del constructor del SNIESController
    //  estas constantes las leerá el SNIESController del archivo de Settings.h
    //  Completar el archivo con el resto de constantes necesarias
    string ruta1 = string("inputs/programas.csv");
    string ruta2 = string("inputs/admitidos");
    string ruta3 = string("inputs/graduados");
    string ruta4 = string("inputs/inscritos");
    string ruta5 = string("inputs/matriculados");
    string ruta6 = string("inputs/matriculadosPrimerSemestre");
    string ruta7 = string("outputs/");
    controlador = SNIESController(ruta1, ruta2, ruta3, ruta4, ruta5, ruta6, ruta7);
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


bool View::validarEntrada(string& entrada, bool esAno = false)
{
    while (true)
    {
        if (esAno)
        {
            if (isConvetibleToInt(entrada))
            {
                return true;
            }
            else
            {
                cout << "El valor ingresado fue inválido. Por favor, ingrese un año válido: ";
                cin >> entrada;
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
                cout << "Entrada no válida. Por favor ingrese 'Y' o 'N'." << endl;
            }
        }
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
    if (validarEntrada(userAnswer, false))
    {
        parametrizacionBool = true;

        string userText;
        cout << "A continuación se procesarán los datos de los programas académicos seleccionados en /programas.csv..." << endl;

        string anio1;
        string ano2;
        string anoAux;
        cout << "Escriba el primer año de búsqueda: ";
        cin >> anio1;
        validarEntrada(anio1, true); 
        cout << endl;
        cout << "Escriba el segundo año de búsqueda: ";
        cin >> ano2;
        validarEntrada(ano2, true); 
        cout << endl;

            organizarAnios(anio1, ano2);

        cout << "Procesando datos ..." << endl;
        controlador.procesarDatosCsv(anio1, ano2);
        cout << "Datos procesados con éxito!" << endl;
    }
    return parametrizacionBool;
}

void View::salir()
{
    cout << "Cerrando programa..." << endl;
    cout << "Recuerde revisar la carpeta de outputs para los archivos .csv exportados" << endl;
    cout << "Programa Cerrado con exito!" << endl;
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
    cout << "Desea Convertir los datos a un archivo CSV?(Y/N): " << endl;

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