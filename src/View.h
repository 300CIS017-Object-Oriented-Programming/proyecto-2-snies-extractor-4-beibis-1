#ifndef VIEW_H
#define VIEW_H
#include "SNIESController.h"
/*Todo el codigo va entre estas guardas*/
#include "SNIESController.h"
#include <cctype>

using namespace std;

class View
{
private:
    SNIESController controlador;
    bool validarEntrada(string&, bool);
    void organizarAnios(string &, string &);
    bool validarEntradaYN(); 

public:
    View();
    ~View();
    bool mostrarPantallaBienvenido();
    void mostrarDatosExtra();
    void buscarPorPalabraClaveYFormacion();
    void salir();    
    bool isConvetibleToInt(const string &);
    



};

#endif