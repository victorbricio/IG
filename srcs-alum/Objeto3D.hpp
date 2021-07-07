#ifndef IG_OBJETO3D_HPP
#define IG_OBJETO3D_HPP

#include <string>
#include "practicas.hpp"
#include "aux.hpp"

class Objeto3D {
protected:
  std::string nombre_obj;

public:
  std::string nombre();

  virtual void visualizarGL(ContextoVis & cv) = 0;
};

#endif
