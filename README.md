Integrantes: _Maria Lucía Castillo García, Juliana González Sánchez y Ana Daniela Paredes Tovar _


**1.1 Descripción General**

En la Pontificia Universidad Javeriana de Cali, dentro el proceso de creación de nuevos programas de pregrado y posgrado, quienes están elaborando la propuesta de nuevos programas deben analizar a partir de los datos reportados en el SNIES la posible demanda a partir de los datos históricos que registra el SNIES. Recordando que el Sistema Nacional de Información de la Educación Superior (SNIES) en Colombia es quien se encarga de recopilar una gran cantidad de datos sobre las instituciones de educación superior y los programas académicos que ofrecen. 

Dentro del análisis de estos datos, están especialmente los relacionados con la inscripción, admisión, matrícula y graduación, es crucial para la toma de decisiones informadas en el ámbito educativo. Por ejemplo, el análisis de las tendencias en la matrícula y graduación puede revelar áreas de mejora en el diseño curricular de nuevos programas, asegurando que sean relevantes y atractivos para los estudiantes. Así mismo, el análisis de datos históricos y tendencias puede ayudar a las instituciones a tomar decisiones estratégicas sobre la apertura de nuevos programas, la modificación de programas existentes o la asignación de recursos. 

Por lo que, el presente proyecto tiene como propósito desarrollar un programa en C++ que ayude a las personas encargadas a extraer y consolidar la información a realizar este proceso rápidamente sin tener que procesar los datos manualmente. 

***
**1.2 Descripción del Proyecto SNIES**

En el desarrollo del proyecto, se implementaron diversas clases en C++. Entre ellas, la clase _Consolidado_ que se encarga de manejar la consolidación de datos, permitiendo una estructura organizada para la información extraída. La clase de _ProgramaAcademico_ que representan los programas académicos, integrando la lógica necesaria para gestionar sus características y relaciones.

[En donde se ven los links van las imágenes que están en el PDF]
![[Pasted image 20241023224606.png]]
Consolidado.h


![[{610F84C1-7E56-4449-9704-8EF04283712F}.png]]

![[{AD61081B-6357-45A1-91BC-E311B1034477}.png]]
![[{3A2111C8-B0F4-40BE-A968-881927F9581A}.png]]
![[{EC1E5BA5-C50C-457F-B6EC-0C368B3ED378}.png]]
![[{977BFB7E-9082-4D50-8D1A-91C5A49A566D}.png]]
ProgramaAcademico.h


Por otro lado, tenemos el _Gestor_ que funciona como una clase base para manejar diferentes tipos de archivos. De ella derivan las clases hijas _GestorCSV_, _GestorTXT_ y _GestorJSON_, que se especializan en la lectura y escritura de datos en diferentes formatos.

![[{406CA49B-7A2F-4FB2-9A3C-2B25047EEA45}.png]]
Gestor.h

![[{3A5BFB46-E43F-4A24-9201-EE2996D224F2}.png]]
GestorCsv.h


![[{01659871-BC83-40D1-9E0F-FC98EACD84F0}.png]]
GestorJson.h

![[{F013FEEF-1497-4F6E-AEF9-9305392595C5}.png]]
GestorTxt.h


Además, tenemos el _View_ que permite visualizar los resultados de los análisis, proporcionando una interfaz amigable para los usuarios. Y el _Settings_ que lo utilizamos para gestionar constantes, evitando así el uso de "números mágicos" en el código, lo que mejora su legibilidad y mantenibilidad.

![[{0F7AEF96-EF6D-4612-B7F1-4858EDA21886}.png]]
View.h


![[{D1FCC634-CE58-4A2B-AAB4-113CAF48DE02}.png]]
Settings.h


Ya por último tenemos el _SNIESController_ quien se encarga de controlar la interacción con el SNIES, facilitando la conexión y la gestión de datos necesarios para el análisis.
![[{ADB41C4E-4F89-4933-8D93-252A77C0887A}.png]]
Controller.h 

A través de estas clases, el proyecto buscó optimizar el proceso de análisis y decisión en la creación de nuevos programas académicos, contribuyendo a la mejora continua en la educación superior.

****
**2. Funcionamiento del proyecto**

[En donde se ven los links van las imágenes que están en el PDF]
![[{29A2D6E2-F812-4DE4-B159-668C218E152F}.png]]

![[{509B60D3-F0AB-4758-B3B6-9CA2721D457A}.png]]

RESULTADOS: 

![[{2204969C-A2B2-45BF-B1F7-F1970DE0E620}.png]]

![[{314162EF-2EE4-4B1F-B7CB-3DA0A26BFB35}.png]]


EXTRAS: 
![[{BF2B2E9D-40DD-4BFC-B18D-68F2785CE0A2}.png]]

![[{932502A4-C0AA-43B8-A6BA-832CB0A7DE91}.png]]

![[{80598FDA-99FD-424F-B3B6-EB459C5BE64B}.png]]

![[{BB7DA1A4-00D7-40E5-821B-4AF104AA4943}.png]]
![[{73D5611D-FF6D-44CF-AE19-0EBFAD0E8C0B}.png]]
![[{F8CC64DC-5F9C-468E-B2A6-200DB542E007}.png]]
![[{5B776D0D-2387-4F42-A378-7F4B0CD0DA4F}.png]]



****
**2.1 Cumplimiento de los requerimientos**

- **Búsqueda de columnas importantes
![[Pasted image 20241023231948.png]]

![[Pasted image 20241023231958.png]]





- **Delimitador y eliminación de números mágicos
![[Pasted image 20241023232028.png]]


- **Generar archivos de salida en formato *CSV, *TXT* y *JSON*, aplicando polimorfismo y herencia para gestionar los diferentes formatos de salida.**
Gestor:
![[Pasted image 20241023232131.png]]
GestorCsv:
![[Pasted image 20241023232140.png]]
GestorJson: 
![[Pasted image 20241023232151.png]]
GestorTXT:
![[Pasted image 20241023232207.png]]


**** 

**Link al video explicativo:**

https://youtu.be/ROt_RzHWEyg


**Diagrama UML:**
```mermaid
classDiagram
    class View {
        -SNIESController controlador
        -bool validarEntrada(string&, bool)
        -void organizarAnios(string&, string&)
        -bool validarEntradaYN()
    
        +View()
        +~View()
        +bool mostrarPantallaBienvenido()
        +void mostrarDatosExtra()
        +void buscarPorPalabraClaveYFormacion()
        +void salir()
        +bool isConvetibleToInt(const string&)
    }

    class Settings {
        +static const std::string ADMITIDOS_FILE_PATH
        +static const std::string MATRICULADOS_FILE_PATH
        +static const std::string INSCRITOS_FILE_PATH
        +static const std::string PROGRAMAS_FILTRAR_FILE_PATH
        +static const std::string BASE_PATH
        +static char DELIMITADOR
        +static const int COLUMNAS_INFO_CONSOLIDADOS
        +static const int DATOS_ACADEM_DEMOGRAF
    }

    class ProgramaAcademico {
        -int codigoDeLaInstitucion
        -int iesPadre
        -string institucionDeEducacionSuperiorIes
        -string principalOSeccional
        -int idSectorIes
        -string sectorIes
        -int idCaracter
        -string caracterIes
        -int codigoDelDepartamentoIes
        -string departamentoDeDomicilioDeLaIes
        -int codigoDelMunicipioIes
        -string municipioDeDomicilioDeLaIes
        -int codigoSniesDelPrograma
        -string programaAcademico
        -int idNivelAcademico
        -string nivelAcademico
        -int idNivelDeFormacion
        -string nivelDeFormacion
        -int idMetodologia
        -string metodologia
        -int idArea
        -string areaDeConocimiento
        -int idNucleo
        -string nucleoBasicoDelConocimientoNbc
        -int idCineCampoAmplio
        -string descCineCampoAmplio
        -int idCineCampoEspecifico
        -string descCineCampoEspecifico
        -int idCineCodigoDetallado
        -string descCineCodigoDetallado
        -int codigoDelDepartamentoPrograma
        -string departamentoDeOfertaDelPrograma
        -int codigoDelMunicipioPrograma
        -string municipioDeOfertaDelPrograma
        -vector consolidados
    
        +ProgramaAcademico()
        +~ProgramaAcademico()
        +setCodigoDeLaInstitucion(int)
        +setIesPadre(int)
        +setInstitucionDeEducacionSuperiorIes(string)
        +setPrincipalOSeccional(string)
        +setIdSectorIes(int)
        +setSectorIes(string)
        +setIdCaracter(int)
        +setCaracterIes(string)
        +setCodigoDelDepartamentoIes(int)
        +setDepartamentoDeDomicilioDeLaIes(string)
        +setCodigoDelMunicipioIes(int)
        +setMunicipioDeDomicilioDeLaIes(string)
        +setCodigoSniesDelPrograma(int)
        +setProgramaAcademico(string)
        +setIdNivelAcademico(int)
        +setNivelAcademico(string)
        +setIdNivelDeFormacion(int)
        +setNivelDeFormacion(string)
        +setIdMetodologia(int)
        +setMetodologia(string)
        +setIdArea(int)
        +setAreaDeConocimiento(string)
        +setIdNucleo(int)
        +setNucleoBasicoDelConocimientoNbc(string)
        +setIdCineCampoAmplio(int)
        +setDescCineCampoAmplio(string)
        +setIdCineCampoEspecifico(int)
        +setDescCineCampoEspecifico(string)
        +setIdCineCodigoDetallado(int)
        +setDescCineCodigoDetallado(string)
        +setCodigoDelDepartamentoPrograma(int)
        +setDepartamentoDeOfertaDelPrograma(string)
        +setCodigoDelMunicipioPrograma(int)
        +setMunicipioDeOfertaDelPrograma(string)
        +getCodigoDeLaInstitucion()
        +getIesPadre()
        +getInstitucionDeEducacionSuperiorIes()
        +getPrincipalOSeccional()
        +getIdSectorIes()
        +getSectorIes()
        +getIdCaracter()
        +getCaracterIes()
        +getCodigoDelDepartamentoIes()
        +getDepartamentoDeDomicilioDeLaIes()
        +getCodigoDelMunicipioIes()
        +getMunicipioDeDomicilioDeLaIes()
        +getCodigoSniesDelPrograma()
        +getProgramaAcademico()
        +getIdNivelAcademico()
        +getNivelAcademico()
        +getIdNivelDeFormacion()
        +getIdMetodologia()
        +getMetodologia()
        +getIdArea()
        +getAreaDeConocimiento()
        +getIdNucleo()
        +getNucleoBasicoDelConocimientoNbc()
        +getIdCineCampoAmplio()
        +getDescCineCampoAmplio()
        +getIdCineCampoEspecifico()
        +getDescCineCampoEspecifico()
        +getIdCineCodigoDetallado()
        +getDescCineCodigoDetallado()
        +getCodigoDelDepartamentoPrograma()
        +getDepartamentoDeOfertaDelPrograma()
        +getCodigoDelMunicipioPrograma()
        +getMunicipioDeOfertaDelPrograma()
        +getConsolidado()
        ~ProgramaAcademico()
    }

    class GestorTXT {
        +GestorTxt()
        +bool crearArchivo(string, map<int, ProgramaAcademico*>, vector<string>)
        +bool crearArchivoBuscados(string, list<ProgramaAcademico*>, vector<string>)
        +bool crearArchivoExtra(string, vector<vector<string>>)
    }

    class GestorJson {
        +GestorJson()
        +bool crearArchivo(string, map<int, ProgramaAcademico*>, vector<string>)
        +bool crearArchivoBuscados(string, list<ProgramaAcademico*>, vector<string>)
        +bool crearArchivoExtra(string, vector<vector<string>>)
    }

    class GestorCsv {
        +GestorCsv()
        +vector<int> leerProgramasCsv(string)
        +vector<vector<string>> leerArchivoPrimera(string, string, vector<int>)
        +vector<vector<string>> leerArchivoSegunda(string, string, vector<int>)
        +vector<vector<string>> leerArchivo(string, string, vector<int>, int)
        +bool crearArchivo(string, map<int, ProgramaAcademico*>, vector<string>)
        +bool crearArchivoBuscados(string, list<ProgramaAcademico*>, vector<string>)
        +bool crearArchivoExtra(string, vector<vector<string>>)
    }

    class Gestor {
        <<Abstract>>
        +virtual bool crearArchivo(string &ruta, map<int, ProgramaAcademico* > &mapadeProgramasAcademicos, vector<string> etiquetasColumnas) = 0;
        +virtual bool crearArchivoBuscados(string &ruta, list<ProgramaAcademico *> &programasBuscados, vector<string> etiquetasColumnas) = 0;
        +virtual bool crearArchivoExtra(std::string &ruta, vector<vector<string>> datosAImprimir) = 0;
        +virtual ~Gestor() = default
    }

    class Consolidado {
        -int inscritos
        -int admitidos
        -int matriculadosPrimerSemestre
        -int matriculados
        -int graduados
        -int idSexo
        -string sexo
        -int ano
        -int semestre
    
        +setIdSexo(int)
        +setSexo(string)
        +setAno(int)
        +setSemestre(int)
        +getIdSexo()
        +getSexo()
        +getAno()
        +getSemestre()
        +setInscritos(int)
        +setAdmitidos(int)
        +setMatriculadosPrimerSemestre(int)
        +setMatriculados(int)
        +setGraduados(int)
        +getInscritos()
        +getAdmitidos()
        +getMatriculadosPrimerSemestre()
        +getMatriculados()
        +getGraduados()
    }

    class SNIESController {
        -map programasAcademicos
        -GestorCsv gestorCsvObj
        -vector etiquetasColumnas
        -string rutaProgramasCsv
        -string rutaAdmitidos
        -string rutaGraduados
        -string rutaInscritos
        -string rutaMatriculados
        -string rutaMatriculadosPrimerSemestre
        -string rutaOutput
        +SNIESController()
        +SNIESController(string&, string&, string&, string&, string&, string&, string&)
        +~SNIESController()
        +void procesarDatosCsv(string &ano1, string &ano2)
        +void calcularDatosExtra(bool)
        +void buscarProgramas(bool, string&, int)
    }

    class Main {
        +int main()
    }

    Main ..> View: usa
    View --> SNIESController: tiene
    SNIESController --> Gestor: tiene
    SNIESController o-- ProgramaAcademico: tiene varios
    GestorCsv --|> Gestor : es un
    GestorJson --|> Gestor : es un
    GestorTXT --|> Gestor : es un
    ProgramaAcademico o-- Consolidado : tiene varios
    SNIESController ..> Settings: usa
    ProgramaAcademico ..> Settings: usa
    Gestor ..> Settings: usa
