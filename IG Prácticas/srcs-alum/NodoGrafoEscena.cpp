#include "NodoGrafoEscena.hpp"
#include "aux.hpp"

/*EntradaNGE::EntradaNGE(MallaInd * pObjeto){
  tipoE = 0;
  objeto = pObjeto;
}*/

EntradaNGE::EntradaNGE(Objeto3D * pObjeto, int n){
  tipoE = 0;
  objeto = pObjeto;
  numero = n;

}

EntradaNGE::EntradaNGE(const Matriz4f & pMatriz){
  tipoE = 1;
  matriz = new Matriz4f(pMatriz);
  numero = -1;
}

EntradaNGE::EntradaNGE(MaterialEstandar * pMaterial){
  tipoE = 2;
  material = pMaterial;
}

void NodoGrafoEscena::visualizarGL(ContextoVis & cv) {
  glMatrixMode(GL_MODELVIEW);
  glPushMatrix();

  for (unsigned i = 0; i < entradas.size(); i++){
    if (entradas[i].tipoE == 0){
      if (entradas[i].numero == 0){
        cv.setNumero(0);
        entradas[i].objeto->visualizarGL(cv);
      }
      if (entradas[i].numero == 1){
        cv.setNumero(1);
        entradas[i].objeto->visualizarGL(cv);
      }
      if (entradas[i].numero == 2){
        cv.setNumero(2);
        entradas[i].objeto->visualizarGL(cv);
      }
      if (entradas[i].numero == 3){
        cv.setNumero(3);
        entradas[i].objeto->visualizarGL(cv);
      }
      if (entradas[i].numero == 4){
        cv.setNumero(4);
        entradas[i].objeto->visualizarGL(cv);
      }
      if (entradas[i].numero == 5){
        cv.setNumero(5);
        entradas[i].objeto->visualizarGL(cv);
      }

      entradas[i].objeto->visualizarGL(cv);
    }
    else if  (entradas[i].tipoE == 1){
      glMatrixMode(GL_MODELVIEW);
      glMultMatrixf(*(entradas[i].matriz));
    }
    else {
      cv.pilaMateriales.activarMaterial(entradas[i].material);
    }
  }
  glMatrixMode(GL_MODELVIEW);
  glPopMatrix();
}

void NodoGrafoEscena::agregar(EntradaNGE * entrada){
  entradas.push_back(*entrada);
}

/*void NodoGrafoEscena::agregar(MallaInd * pObjeto){
  entradas.push_back(*new EntradaNGE(pObjeto));
}*/

void NodoGrafoEscena::agregar(Objeto3D * pObjeto, int n){
  entradas.push_back(* new EntradaNGE(pObjeto, n));
}

void NodoGrafoEscena::agregar(MaterialEstandar * pMaterial){
	entradas.push_back(*new EntradaNGE(pMaterial));
}

void NodoGrafoEscena::agregar(const Matriz4f & pMatriz){
  entradas.push_back(* new EntradaNGE(pMatriz));
}

EntradaNGE NodoGrafoEscena::entrada(int i){
  return entradas[i];
}

void NodoGrafoEscena::calcularNormales(){
  for(int i = 0; i < entradas.size(); i++){
    if(entradas[i].tipoE == 0){
        ((MallaInd*)entradas[i].objeto)->calcularNormales();
    }
  }
}

void NodoGrafoEscena::modoSeleccion(){
    int identificador = 0;
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    ContextoVis cv;
    cv.modoVisu = modoSolido;
    glColor3ub(identificador,0,0);

    for (int i=0; i<entradas.size(); ++i){
        if (entradas[i].tipoE == '1'){
            glMultMatrixf(*(entradas[i].matriz));
        }
        else if (entradas[i].tipoE == '0'){
        	if(identificador == 0)
                ((NodoGrafoEscena*)entradas[i].objeto)->modoSeleccion();
            else
            	entradas[i].objeto->visualizarGL(cv);
        }

    }

    glMatrixMode (GL_MODELVIEW);
    glPopMatrix();
}
