#include "aux.hpp"
#include "tuplasg.hpp"   // Tupla3f
#include "practicas.hpp"
#include "practica3.hpp"
#include "matrices-tr.hpp"
#include <vector>
#include <cstring>

unsigned objeto_activo3 = 0;
unsigned grado_activo = 0;
std::vector<std::string> g = {"movimiento del Sol.", "movimiento de la Tierra.", "movimiento de Marte.",
                        "movimiento de la Luna.","oscilación de la Luna.", "movimiento de Fobos.",
                        "oscilación de Fobos.", "movimiento de Deimos.", "oscilación de Deimos."};
unsigned grados = g.size();
bool desactivado3 = true;

FuentePosicional * fuentePosicional_p3 = NULL;
FuenteDireccional * fuenteDireccional_p3 = NULL;

ColeccionFL *fuentes_p3 = NULL;

Raiz * sol;

void P3_Inicializar( int argc, char *argv[] ){

  sol = new Raiz();


  fuentes_p3 = new ColeccionFL;

  glEnable(GL_RESCALE_NORMAL);

  fuentePosicional_p3 = new FuentePosicional(Tupla3f(0,2,5));
  fuenteDireccional_p3 = new FuenteDireccional(0,0);

  fuentes_p3->fuentes.push_back(fuentePosicional_p3);
  fuentes_p3->fuentes.push_back(fuenteDireccional_p3);
}


bool P3_FGE_PulsarTeclaNormal( unsigned char tecla ){
  if (tecla == 'o' || tecla == 'O'){
    objeto_activo3 = 0;

    return true;
  }
  if (tecla == 'a' || tecla == 'A'){
    desactivado3 = !desactivado3;
    if (desactivado3)
      std::cout << "Se desactivan las animaciones." << std::endl;
    else
      std::cout << "Se activan las animaciones." << std::endl;

    //glutIdleFunc(FGE_Desocupado);

    return true;
  }

  if (tecla == 'g' || tecla == 'G'){
    grado_activo++;
    grado_activo = grado_activo%grados;

    std::cout << "Activar " << g[grado_activo] << std::endl;

    return true;
  }

  if (tecla == 'r' || tecla == 'R'){
    for (int i = 0; i < sol->numParametros(); i++){
      sol->leerPtrParametro(i)->reset();
    }

    return true;
  }

  if (tecla == '<' || tecla == '<'){
    if (desactivado3){
      sol->leerPtrParametro(grado_activo)->decrementar();
      std::cout << "Decrementar " << sol->leerPtrParametro(grado_activo)->leer_descripcion() << " a " <<
      sol->leerPtrParametro(grado_activo)->leer_valor_actual() << std::endl;
    }
    else{
      sol->leerPtrParametro(grado_activo)->decelerar();
      std::cout << "Decelerar " << sol->leerPtrParametro(grado_activo)->leer_descripcion() << " a " <<
      sol->leerPtrParametro(grado_activo)->leer_velocidad_actual() << std::endl;
    }
    return true;
  }

  if (tecla == '>' || tecla == '>'){
    if (desactivado3){
      sol->leerPtrParametro(grado_activo)->incrementar();
      std::cout << "Incrementar " << sol->leerPtrParametro(grado_activo)->leer_descripcion() << " a " <<
      sol->leerPtrParametro(grado_activo)->leer_valor_actual() << std::endl;
    }
    else{
      sol->leerPtrParametro(grado_activo)->acelerar();
      std::cout << "Acelerar " << sol->leerPtrParametro(grado_activo)->leer_descripcion() << " a " <<
      sol->leerPtrParametro(grado_activo)->leer_velocidad_actual() << std::endl;
    }
    return true;
  }

   return false ;
}

bool P3_FGE_Desocupado(){
  if (desactivado3)
    return false;

  fuentes_p3->activar();
  sol->siguienteCuadro();
  fuentes_p3->desactivar();

  glutPostRedisplay();

  return true;
}

void P3_DibujarObjetos( ContextoVis & cv ){
  if (objeto_activo3 == 0){
    fuentes_p3->activar();
    sol->visualizarGL(cv);
    fuentes_p3->desactivar();
  }
}
