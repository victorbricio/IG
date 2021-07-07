#ifndef IG_MALLAIND_HPP
#define IG_MALLAIND_HPP

#include "Objeto3D.hpp"
#include "tuplasg.hpp"
#include <vector>
#include <cstring>
using namespace std;


class MallaInd : public Objeto3D {
protected:
  std::vector<Tupla3f> vertices_normales;
  std::vector<Tupla3f> caras_normales;

  unsigned int num_ver, num_tri;
  std::vector<Tupla3f> ver;
  std::vector<Tupla3i> tri;
  std::vector<Tupla3f> baricentros;

  int num_caras_normales;
  int num_vertices_normales;

  std::vector<Tupla2f> tabla_textura;

public:
  void HacerMallaInd(std::vector<Tupla3f> v, std::vector<Tupla3i> t, int nv, int nt);
  virtual void visualizarGL(ContextoVis & cv);
  void visualizarBE(ContextoVis & cv);
  void obtenerNormalesCaras();
  void obtenerNormalesVertices();
  void calcularNormales();
  void visualizarCarasNormales();
  void Baricentros();
};

#endif
