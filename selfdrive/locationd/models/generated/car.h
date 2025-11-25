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
void car_err_fun(double *nom_x, double *delta_x, double *out_5789016104638959634);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_2114092178249116758);
void car_H_mod_fun(double *state, double *out_627878828374656716);
void car_f_fun(double *state, double dt, double *out_1305717728670895028);
void car_F_fun(double *state, double dt, double *out_8542181060080239781);
void car_h_25(double *state, double *unused, double *out_6155566602907018448);
void car_H_25(double *state, double *unused, double *out_8625677019422657663);
void car_h_24(double *state, double *unused, double *out_2986924554783287993);
void car_H_24(double *state, double *unused, double *out_7595359270308025391);
void car_h_30(double *state, double *unused, double *out_1310325322793628059);
void car_H_30(double *state, double *unused, double *out_2904376712795277198);
void car_h_26(double *state, double *unused, double *out_4332404548287328776);
void car_H_26(double *state, double *unused, double *out_4884173700548601439);
void car_h_27(double *state, double *unused, double *out_4947792578797019583);
void car_H_27(double *state, double *unused, double *out_5079140024595702109);
void car_h_29(double *state, double *unused, double *out_3652054674887665173);
void car_H_29(double *state, double *unused, double *out_2394145368480885014);
void car_h_28(double *state, double *unused, double *out_6307420109806389411);
void car_H_28(double *state, double *unused, double *out_7476544385550415588);
void car_h_31(double *state, double *unused, double *out_9033952133807552864);
void car_H_31(double *state, double *unused, double *out_8656322981299618091);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}