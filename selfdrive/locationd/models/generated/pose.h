#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_1506195149131963127);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_7697979825393261245);
void pose_H_mod_fun(double *state, double *out_6822266201757739684);
void pose_f_fun(double *state, double dt, double *out_1948814540219812874);
void pose_F_fun(double *state, double dt, double *out_8951443110773343828);
void pose_h_4(double *state, double *unused, double *out_7758283624105186369);
void pose_H_4(double *state, double *unused, double *out_974184395005780963);
void pose_h_10(double *state, double *unused, double *out_7394438859301058746);
void pose_H_10(double *state, double *unused, double *out_2376123439446719646);
void pose_h_13(double *state, double *unused, double *out_8336612566633508624);
void pose_H_13(double *state, double *unused, double *out_4186458220338113764);
void pose_h_14(double *state, double *unused, double *out_2143117866505763143);
void pose_H_14(double *state, double *unused, double *out_4937425251345265492);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}