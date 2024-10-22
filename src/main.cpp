#include "View.h"

int main() {
    View menu;
    bool archivosParametrizados = menu.mostrarPantallaBienvenido();
    if (archivosParametrizados) {
        menu.mostrarDatosExtra();
        menu.buscarPorPalabraClaveYFormacion();
    }
    menu.salir();
    return 0;
}