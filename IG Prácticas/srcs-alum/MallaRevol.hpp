#ifndef IG_MALLAREVOL_HPP
#define IG_MALLAREVOL_HPP


#include "MallaInd.hpp"
#include "file_ply_stl.hpp"

class MallaRevol : public MallaInd{
public:
  MallaRevol(const std::string & nombre_arch, unsigned int nperfiles, bool crear_tapas, bool cerrar_malla);
  MallaRevol(const std::string & nombre_arch, unsigned int nperfiles, bool crear_tapas, bool cerrar_malla, bool texturas);
};

#endif
