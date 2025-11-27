#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_err_fun(double *nom_x, double *delta_x, double *out_8907845008944078404);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_4172994092626456785);
void car_H_mod_fun(double *state, double *out_7912902925809263636);
void car_f_fun(double *state, double dt, double *out_7674876308033374527);
void car_F_fun(double *state, double dt, double *out_172949326157607372);
void car_h_25(double *state, double *unused, double *out_4840953675774243879);
void car_H_25(double *state, double *unused, double *out_7407568483608966924);
void car_h_24(double *state, double *unused, double *out_6551340126369418031);
void car_H_24(double *state, double *unused, double *out_10823150067959969);
void car_h_30(double *state, double *unused, double *out_4683767007423114734);
void car_H_30(double *state, double *unused, double *out_490878142117350169);
void car_h_26(double *state, double *unused, double *out_8800597068605143650);
void car_H_26(double *state, double *unused, double *out_7297672271226528468);
void car_h_27(double *state, double *unused, double *out_2718125110402927885);
void car_H_27(double *state, double *unused, double *out_8735073331156919711);
void car_h_29(double *state, double *unused, double *out_2079361686614417083);
void car_H_29(double *state, double *unused, double *out_19353202197042015);
void car_h_28(double *state, double *unused, double *out_3680916407010921261);
void car_H_28(double *state, double *unused, double *out_8985340875852694929);
void car_h_31(double *state, double *unused, double *out_1746874250702051284);
void car_H_31(double *state, double *unused, double *out_7376922521732006496);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}