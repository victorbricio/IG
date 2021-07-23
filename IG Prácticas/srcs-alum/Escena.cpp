#include "Escena.hpp"

MallaRevol *peon;
MallaRevol *lata;
MallaRevol *tapa_superior;
MallaRevol *tapa_inferior;

Escena::Escena(){
  agregar(MAT_Escalado(0.13,0.13,0.13));
  agregar(new CocaCola(), -1);
  agregar(MAT_Traslacion(0.0,1.4,4.0));
  agregar(new Peones(), -1);


}

Peones::Peones(){
  peon = new MallaRevol("../plys/peon.ply",100,true,false,false);
  agregar(new MaterialPeonMadera());
  agregar(peon, -1);
  agregar(MAT_Traslacion(3,0,0));
  agregar(new MaterialPeonBlanco());
  agregar(peon, -1);
  agregar(MAT_Traslacion(3,0,0));
  agregar(new MaterialPeonNegro());
  agregar(peon, -1);

  this->calcularNormales();
}

CocaCola::CocaCola(){
  lata = new MallaRevol("../plys/lata-pcue.ply",100, false, false, true);
  tapa_superior = new MallaRevol("../plys/lata-psup.ply",100, true, false, true);
  tapa_inferior = new MallaRevol("../plys/lata-pinf.ply",100, true, false, true);
  agregar(MAT_Escalado(5,5,5));
  agregar(new MaterialTapasLata());
  agregar(tapa_superior, -1);
  agregar(new MaterialTapasLata());
  agregar(tapa_inferior, -1);
  agregar(new MaterialLata());
  agregar(lata, -1);
  this->calcularNormales();
}
