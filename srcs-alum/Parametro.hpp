#ifndef PARAMETRO_HPP
#define PARAMETRO_HPP

#include <cstring>
#include <functional>
#include "matrices-tr.hpp"

typedef std::function< Matriz4f( float )> TFuncionCMF;

class Parametro{
private:
  const std::string descripcion;
  Matriz4f * const ptr_mat;
  const TFuncionCMF fun_calculo_matriz;
  const bool acotado;
  const float c, s, f;
  float valor_norm, velocidad;

public:
  Parametro(const std::string & p_descripcion, Matriz4f * p_ptr_mat,
    TFuncionCMF p_fcm, bool p_acotado, float p_c, float p_s, float p_f);

  void siguiente_cuadro();
  void reset();
  void incrementar();
  void decrementar();
  void acelerar();
  void decelerar();
  float leer_valor_actual();
  float leer_velocidad_actual();
  std::string leer_descripcion();

};

#endif
