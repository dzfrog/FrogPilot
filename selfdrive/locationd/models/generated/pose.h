#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_286554823530916308);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_61539773135089930);
void pose_H_mod_fun(double *state, double *out_5951487745039434469);
void pose_f_fun(double *state, double dt, double *out_3196225065518721106);
void pose_F_fun(double *state, double dt, double *out_1970636867034735721);
void pose_h_4(double *state, double *unused, double *out_4780830717175456004);
void pose_H_4(double *state, double *unused, double *out_2179680535195526897);
void pose_h_10(double *state, double *unused, double *out_135423843922526497);
void pose_H_10(double *state, double *unused, double *out_5295779974263124150);
void pose_h_13(double *state, double *unused, double *out_1822547114212723940);
void pose_H_13(double *state, double *unused, double *out_1032593290136805904);
void pose_h_14(double *state, double *unused, double *out_80795115449031259);
void pose_H_14(double *state, double *unused, double *out_1783560321143957632);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}