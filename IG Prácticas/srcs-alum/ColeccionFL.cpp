#include "ColeccionFL.hpp"

// activa todas las fuentes de luz en el cauce fijo
//   (antes de eso activa iluminación y la configura)
void ColeccionFL::activar() {
    glEnable(GL_LIGHTING);     //Activa la iluminacion
    for(int i=0; i<fuentes.size(); i++){
        fuentes[i]->activar(i);
        //std::cout << "Activando Luz "<< i << std::endl;
    }
}

void ColeccionFL::desactivar() {

    for(int i=0; i<fuentes.size(); i++){
        fuentes[i]->desactivar(i);
        //std::cout << "Desactivando luz " << i << std::endl;
    }
    glDisable(GL_LIGHTING);
}
