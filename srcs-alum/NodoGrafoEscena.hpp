#ifndef NODOGRAFOESCENA_HPP
#define NODOGRAFOESCENA_HPP

#include "Objeto3D.hpp"
#include "MallaInd.hpp"
#include "matrices-tr.hpp"
#include "aux.hpp"
#include <vector>
#include <cstring>

struct EntradaNGE{
  unsigned char tipoE;
  int numero;
  union{
    Objeto3D * objeto;
    Matriz4f * matriz;
    MaterialEstandar * material;
  };

  //EntradaNGE(MallaInd * pObjeto);
  EntradaNGE(Objeto3D * pObjeto, int n);
  EntradaNGE(const Matriz4f & pMatriz);
  EntradaNGE(MaterialEstandar * pMaterial);
};

class NodoGrafoEscena : public Objeto3D {
protected:
  std::vector<EntradaNGE> entradas;
public:
  virtual void visualizarGL(ContextoVis & cv);
  void agregar(EntradaNGE * entrada);
  //void agregar(MallaInd * pObjeto);
  void agregar(Objeto3D * pObjeto,int n);
  void agregar(const Matriz4f & pMatriz);
  void agregar(MaterialEstandar * pMaterial);
  EntradaNGE entrada(int i);
  void calcularNormales();
  void modoSeleccion();
};


#endif
