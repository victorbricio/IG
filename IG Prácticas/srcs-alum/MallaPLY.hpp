#ifndef IG_MALLAPLY_HPP
#define IG_MALLAPLY_HPP

#include "MallaInd.hpp"
#include "file_ply_stl.hpp"

class MallaPLY : public MallaInd{
public:
  MallaPLY(const std::string & nombre_arch);
};

#endif
