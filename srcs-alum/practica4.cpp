#include "aux.hpp"
#include "tuplasg.hpp"   // Tupla3f
#include "practicas.hpp"
#include "practica4.hpp"
#include "practica1.hpp"
#include "matrices-tr.hpp"
#include <vector>
#include <cstring>
#include "Escena.hpp"

FuentePosicional * fuentePosicional = NULL;
FuenteDireccional * fuenteDireccional = NULL;

ColeccionFL *fuentes = NULL;


int angulo = 0, objeto_activo4 = 0;

Escena *esc;

void P4_Inicializar( int argc, char *argv[] ){

  esc = new Escena();

  fuentes = new ColeccionFL;

  glEnable(GL_RESCALE_NORMAL);

	fuentePosicional = new FuentePosicional(Tupla3f(0,2,5));
	fuenteDireccional = new FuenteDireccional(0,0);

	fuentes->fuentes.push_back(fuentePosicional);
	fuentes->fuentes.push_back(fuenteDireccional);
	}


  bool P4_FGE_PulsarTeclaNormal(  unsigned char tecla ){

  	if(tecla == 'G' || tecla == 'g'){
  		angulo++;
  		angulo%=2;
  	}
  	if(tecla == '<'){
        fuenteDireccional->variarAngulo(angulo,-0.1);
        fuentes->activar();
        return true;
    }
    if(tecla == '>'){
      fuenteDireccional->variarAngulo(angulo,0.1);
      fuentes->activar();
      return true;
    }

  	return false;
  }

void P4_DibujarObjetos( ContextoVis & cv ){
  if (objeto_activo4 == 0){
    fuentes->activar();
    esc->visualizarGL(cv);
    fuentes->desactivar();
  }
}
