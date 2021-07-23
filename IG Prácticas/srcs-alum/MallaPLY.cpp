#include "MallaPLY.hpp"
#include <cstring>


MallaPLY::MallaPLY(const std::string & nombre_arch){
  std::vector<float> auxv;
  std::vector<int> auxc;

  char* aux = new char[nombre_arch.length() + 1];
  std::strcpy(aux, nombre_arch.c_str());

  ply::read(aux, auxv, auxc);

  for (int i = 0; i < auxv.size(); i = i + 3)
    ver.push_back(Tupla3f(auxv[i], auxv[i + 1], auxv[i + 2]));

  for (int i = 0; i < auxc.size(); i = i + 3)
    tri.push_back(Tupla3i(auxc[i], auxc[i + 1], auxc[i + 2]));

  num_ver = ver.size();
  num_tri = tri.size();
}
