#include "car.h"

namespace {
#define DIM 9
#define EDIM 9
#define MEDIM 9
typedef void (*Hfun)(double *, double *, double *);

double mass;

void set_mass(double x){ mass = x;}

double rotational_inertia;

void set_rotational_inertia(double x){ rotational_inertia = x;}

double center_to_front;

void set_center_to_front(double x){ center_to_front = x;}

double center_to_rear;

void set_center_to_rear(double x){ center_to_rear = x;}

double stiffness_front;

void set_stiffness_front(double x){ stiffness_front = x;}

double stiffness_rear;

void set_stiffness_rear(double x){ stiffness_rear = x;}
const static double MAHA_THRESH_25 = 3.8414588206941227;
const static double MAHA_THRESH_24 = 5.991464547107981;
const static double MAHA_THRESH_30 = 3.8414588206941227;
const static double MAHA_THRESH_26 = 3.8414588206941227;
const static double MAHA_THRESH_27 = 3.8414588206941227;
const static double MAHA_THRESH_29 = 3.8414588206941227;
const static double MAHA_THRESH_28 = 3.8414588206941227;
const static double MAHA_THRESH_31 = 3.8414588206941227;

/******************************************************************************
 *                      Code generated with SymPy 1.14.0                      *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_5789016104638959634) {
   out_5789016104638959634[0] = delta_x[0] + nom_x[0];
   out_5789016104638959634[1] = delta_x[1] + nom_x[1];
   out_5789016104638959634[2] = delta_x[2] + nom_x[2];
   out_5789016104638959634[3] = delta_x[3] + nom_x[3];
   out_5789016104638959634[4] = delta_x[4] + nom_x[4];
   out_5789016104638959634[5] = delta_x[5] + nom_x[5];
   out_5789016104638959634[6] = delta_x[6] + nom_x[6];
   out_5789016104638959634[7] = delta_x[7] + nom_x[7];
   out_5789016104638959634[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_2114092178249116758) {
   out_2114092178249116758[0] = -nom_x[0] + true_x[0];
   out_2114092178249116758[1] = -nom_x[1] + true_x[1];
   out_2114092178249116758[2] = -nom_x[2] + true_x[2];
   out_2114092178249116758[3] = -nom_x[3] + true_x[3];
   out_2114092178249116758[4] = -nom_x[4] + true_x[4];
   out_2114092178249116758[5] = -nom_x[5] + true_x[5];
   out_2114092178249116758[6] = -nom_x[6] + true_x[6];
   out_2114092178249116758[7] = -nom_x[7] + true_x[7];
   out_2114092178249116758[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_627878828374656716) {
   out_627878828374656716[0] = 1.0;
   out_627878828374656716[1] = 0.0;
   out_627878828374656716[2] = 0.0;
   out_627878828374656716[3] = 0.0;
   out_627878828374656716[4] = 0.0;
   out_627878828374656716[5] = 0.0;
   out_627878828374656716[6] = 0.0;
   out_627878828374656716[7] = 0.0;
   out_627878828374656716[8] = 0.0;
   out_627878828374656716[9] = 0.0;
   out_627878828374656716[10] = 1.0;
   out_627878828374656716[11] = 0.0;
   out_627878828374656716[12] = 0.0;
   out_627878828374656716[13] = 0.0;
   out_627878828374656716[14] = 0.0;
   out_627878828374656716[15] = 0.0;
   out_627878828374656716[16] = 0.0;
   out_627878828374656716[17] = 0.0;
   out_627878828374656716[18] = 0.0;
   out_627878828374656716[19] = 0.0;
   out_627878828374656716[20] = 1.0;
   out_627878828374656716[21] = 0.0;
   out_627878828374656716[22] = 0.0;
   out_627878828374656716[23] = 0.0;
   out_627878828374656716[24] = 0.0;
   out_627878828374656716[25] = 0.0;
   out_627878828374656716[26] = 0.0;
   out_627878828374656716[27] = 0.0;
   out_627878828374656716[28] = 0.0;
   out_627878828374656716[29] = 0.0;
   out_627878828374656716[30] = 1.0;
   out_627878828374656716[31] = 0.0;
   out_627878828374656716[32] = 0.0;
   out_627878828374656716[33] = 0.0;
   out_627878828374656716[34] = 0.0;
   out_627878828374656716[35] = 0.0;
   out_627878828374656716[36] = 0.0;
   out_627878828374656716[37] = 0.0;
   out_627878828374656716[38] = 0.0;
   out_627878828374656716[39] = 0.0;
   out_627878828374656716[40] = 1.0;
   out_627878828374656716[41] = 0.0;
   out_627878828374656716[42] = 0.0;
   out_627878828374656716[43] = 0.0;
   out_627878828374656716[44] = 0.0;
   out_627878828374656716[45] = 0.0;
   out_627878828374656716[46] = 0.0;
   out_627878828374656716[47] = 0.0;
   out_627878828374656716[48] = 0.0;
   out_627878828374656716[49] = 0.0;
   out_627878828374656716[50] = 1.0;
   out_627878828374656716[51] = 0.0;
   out_627878828374656716[52] = 0.0;
   out_627878828374656716[53] = 0.0;
   out_627878828374656716[54] = 0.0;
   out_627878828374656716[55] = 0.0;
   out_627878828374656716[56] = 0.0;
   out_627878828374656716[57] = 0.0;
   out_627878828374656716[58] = 0.0;
   out_627878828374656716[59] = 0.0;
   out_627878828374656716[60] = 1.0;
   out_627878828374656716[61] = 0.0;
   out_627878828374656716[62] = 0.0;
   out_627878828374656716[63] = 0.0;
   out_627878828374656716[64] = 0.0;
   out_627878828374656716[65] = 0.0;
   out_627878828374656716[66] = 0.0;
   out_627878828374656716[67] = 0.0;
   out_627878828374656716[68] = 0.0;
   out_627878828374656716[69] = 0.0;
   out_627878828374656716[70] = 1.0;
   out_627878828374656716[71] = 0.0;
   out_627878828374656716[72] = 0.0;
   out_627878828374656716[73] = 0.0;
   out_627878828374656716[74] = 0.0;
   out_627878828374656716[75] = 0.0;
   out_627878828374656716[76] = 0.0;
   out_627878828374656716[77] = 0.0;
   out_627878828374656716[78] = 0.0;
   out_627878828374656716[79] = 0.0;
   out_627878828374656716[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_1305717728670895028) {
   out_1305717728670895028[0] = state[0];
   out_1305717728670895028[1] = state[1];
   out_1305717728670895028[2] = state[2];
   out_1305717728670895028[3] = state[3];
   out_1305717728670895028[4] = state[4];
   out_1305717728670895028[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8100000000000005*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_1305717728670895028[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_1305717728670895028[7] = state[7];
   out_1305717728670895028[8] = state[8];
}
void F_fun(double *state, double dt, double *out_8542181060080239781) {
   out_8542181060080239781[0] = 1;
   out_8542181060080239781[1] = 0;
   out_8542181060080239781[2] = 0;
   out_8542181060080239781[3] = 0;
   out_8542181060080239781[4] = 0;
   out_8542181060080239781[5] = 0;
   out_8542181060080239781[6] = 0;
   out_8542181060080239781[7] = 0;
   out_8542181060080239781[8] = 0;
   out_8542181060080239781[9] = 0;
   out_8542181060080239781[10] = 1;
   out_8542181060080239781[11] = 0;
   out_8542181060080239781[12] = 0;
   out_8542181060080239781[13] = 0;
   out_8542181060080239781[14] = 0;
   out_8542181060080239781[15] = 0;
   out_8542181060080239781[16] = 0;
   out_8542181060080239781[17] = 0;
   out_8542181060080239781[18] = 0;
   out_8542181060080239781[19] = 0;
   out_8542181060080239781[20] = 1;
   out_8542181060080239781[21] = 0;
   out_8542181060080239781[22] = 0;
   out_8542181060080239781[23] = 0;
   out_8542181060080239781[24] = 0;
   out_8542181060080239781[25] = 0;
   out_8542181060080239781[26] = 0;
   out_8542181060080239781[27] = 0;
   out_8542181060080239781[28] = 0;
   out_8542181060080239781[29] = 0;
   out_8542181060080239781[30] = 1;
   out_8542181060080239781[31] = 0;
   out_8542181060080239781[32] = 0;
   out_8542181060080239781[33] = 0;
   out_8542181060080239781[34] = 0;
   out_8542181060080239781[35] = 0;
   out_8542181060080239781[36] = 0;
   out_8542181060080239781[37] = 0;
   out_8542181060080239781[38] = 0;
   out_8542181060080239781[39] = 0;
   out_8542181060080239781[40] = 1;
   out_8542181060080239781[41] = 0;
   out_8542181060080239781[42] = 0;
   out_8542181060080239781[43] = 0;
   out_8542181060080239781[44] = 0;
   out_8542181060080239781[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_8542181060080239781[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_8542181060080239781[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_8542181060080239781[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_8542181060080239781[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_8542181060080239781[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_8542181060080239781[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_8542181060080239781[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_8542181060080239781[53] = -9.8100000000000005*dt;
   out_8542181060080239781[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_8542181060080239781[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_8542181060080239781[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_8542181060080239781[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_8542181060080239781[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_8542181060080239781[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_8542181060080239781[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_8542181060080239781[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_8542181060080239781[62] = 0;
   out_8542181060080239781[63] = 0;
   out_8542181060080239781[64] = 0;
   out_8542181060080239781[65] = 0;
   out_8542181060080239781[66] = 0;
   out_8542181060080239781[67] = 0;
   out_8542181060080239781[68] = 0;
   out_8542181060080239781[69] = 0;
   out_8542181060080239781[70] = 1;
   out_8542181060080239781[71] = 0;
   out_8542181060080239781[72] = 0;
   out_8542181060080239781[73] = 0;
   out_8542181060080239781[74] = 0;
   out_8542181060080239781[75] = 0;
   out_8542181060080239781[76] = 0;
   out_8542181060080239781[77] = 0;
   out_8542181060080239781[78] = 0;
   out_8542181060080239781[79] = 0;
   out_8542181060080239781[80] = 1;
}
void h_25(double *state, double *unused, double *out_6155566602907018448) {
   out_6155566602907018448[0] = state[6];
}
void H_25(double *state, double *unused, double *out_8625677019422657663) {
   out_8625677019422657663[0] = 0;
   out_8625677019422657663[1] = 0;
   out_8625677019422657663[2] = 0;
   out_8625677019422657663[3] = 0;
   out_8625677019422657663[4] = 0;
   out_8625677019422657663[5] = 0;
   out_8625677019422657663[6] = 1;
   out_8625677019422657663[7] = 0;
   out_8625677019422657663[8] = 0;
}
void h_24(double *state, double *unused, double *out_2986924554783287993) {
   out_2986924554783287993[0] = state[4];
   out_2986924554783287993[1] = state[5];
}
void H_24(double *state, double *unused, double *out_7595359270308025391) {
   out_7595359270308025391[0] = 0;
   out_7595359270308025391[1] = 0;
   out_7595359270308025391[2] = 0;
   out_7595359270308025391[3] = 0;
   out_7595359270308025391[4] = 1;
   out_7595359270308025391[5] = 0;
   out_7595359270308025391[6] = 0;
   out_7595359270308025391[7] = 0;
   out_7595359270308025391[8] = 0;
   out_7595359270308025391[9] = 0;
   out_7595359270308025391[10] = 0;
   out_7595359270308025391[11] = 0;
   out_7595359270308025391[12] = 0;
   out_7595359270308025391[13] = 0;
   out_7595359270308025391[14] = 1;
   out_7595359270308025391[15] = 0;
   out_7595359270308025391[16] = 0;
   out_7595359270308025391[17] = 0;
}
void h_30(double *state, double *unused, double *out_1310325322793628059) {
   out_1310325322793628059[0] = state[4];
}
void H_30(double *state, double *unused, double *out_2904376712795277198) {
   out_2904376712795277198[0] = 0;
   out_2904376712795277198[1] = 0;
   out_2904376712795277198[2] = 0;
   out_2904376712795277198[3] = 0;
   out_2904376712795277198[4] = 1;
   out_2904376712795277198[5] = 0;
   out_2904376712795277198[6] = 0;
   out_2904376712795277198[7] = 0;
   out_2904376712795277198[8] = 0;
}
void h_26(double *state, double *unused, double *out_4332404548287328776) {
   out_4332404548287328776[0] = state[7];
}
void H_26(double *state, double *unused, double *out_4884173700548601439) {
   out_4884173700548601439[0] = 0;
   out_4884173700548601439[1] = 0;
   out_4884173700548601439[2] = 0;
   out_4884173700548601439[3] = 0;
   out_4884173700548601439[4] = 0;
   out_4884173700548601439[5] = 0;
   out_4884173700548601439[6] = 0;
   out_4884173700548601439[7] = 1;
   out_4884173700548601439[8] = 0;
}
void h_27(double *state, double *unused, double *out_4947792578797019583) {
   out_4947792578797019583[0] = state[3];
}
void H_27(double *state, double *unused, double *out_5079140024595702109) {
   out_5079140024595702109[0] = 0;
   out_5079140024595702109[1] = 0;
   out_5079140024595702109[2] = 0;
   out_5079140024595702109[3] = 1;
   out_5079140024595702109[4] = 0;
   out_5079140024595702109[5] = 0;
   out_5079140024595702109[6] = 0;
   out_5079140024595702109[7] = 0;
   out_5079140024595702109[8] = 0;
}
void h_29(double *state, double *unused, double *out_3652054674887665173) {
   out_3652054674887665173[0] = state[1];
}
void H_29(double *state, double *unused, double *out_2394145368480885014) {
   out_2394145368480885014[0] = 0;
   out_2394145368480885014[1] = 1;
   out_2394145368480885014[2] = 0;
   out_2394145368480885014[3] = 0;
   out_2394145368480885014[4] = 0;
   out_2394145368480885014[5] = 0;
   out_2394145368480885014[6] = 0;
   out_2394145368480885014[7] = 0;
   out_2394145368480885014[8] = 0;
}
void h_28(double *state, double *unused, double *out_6307420109806389411) {
   out_6307420109806389411[0] = state[0];
}
void H_28(double *state, double *unused, double *out_7476544385550415588) {
   out_7476544385550415588[0] = 1;
   out_7476544385550415588[1] = 0;
   out_7476544385550415588[2] = 0;
   out_7476544385550415588[3] = 0;
   out_7476544385550415588[4] = 0;
   out_7476544385550415588[5] = 0;
   out_7476544385550415588[6] = 0;
   out_7476544385550415588[7] = 0;
   out_7476544385550415588[8] = 0;
}
void h_31(double *state, double *unused, double *out_9033952133807552864) {
   out_9033952133807552864[0] = state[8];
}
void H_31(double *state, double *unused, double *out_8656322981299618091) {
   out_8656322981299618091[0] = 0;
   out_8656322981299618091[1] = 0;
   out_8656322981299618091[2] = 0;
   out_8656322981299618091[3] = 0;
   out_8656322981299618091[4] = 0;
   out_8656322981299618091[5] = 0;
   out_8656322981299618091[6] = 0;
   out_8656322981299618091[7] = 0;
   out_8656322981299618091[8] = 1;
}
#include <eigen3/Eigen/Dense>
#include <iostream>

typedef Eigen::Matrix<double, DIM, DIM, Eigen::RowMajor> DDM;
typedef Eigen::Matrix<double, EDIM, EDIM, Eigen::RowMajor> EEM;
typedef Eigen::Matrix<double, DIM, EDIM, Eigen::RowMajor> DEM;

void predict(double *in_x, double *in_P, double *in_Q, double dt) {
  typedef Eigen::Matrix<double, MEDIM, MEDIM, Eigen::RowMajor> RRM;

  double nx[DIM] = {0};
  double in_F[EDIM*EDIM] = {0};

  // functions from sympy
  f_fun(in_x, dt, nx);
  F_fun(in_x, dt, in_F);


  EEM F(in_F);
  EEM P(in_P);
  EEM Q(in_Q);

  RRM F_main = F.topLeftCorner(MEDIM, MEDIM);
  P.topLeftCorner(MEDIM, MEDIM) = (F_main * P.topLeftCorner(MEDIM, MEDIM)) * F_main.transpose();
  P.topRightCorner(MEDIM, EDIM - MEDIM) = F_main * P.topRightCorner(MEDIM, EDIM - MEDIM);
  P.bottomLeftCorner(EDIM - MEDIM, MEDIM) = P.bottomLeftCorner(EDIM - MEDIM, MEDIM) * F_main.transpose();

  P = P + dt*Q;

  // copy out state
  memcpy(in_x, nx, DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
}

// note: extra_args dim only correct when null space projecting
// otherwise 1
template <int ZDIM, int EADIM, bool MAHA_TEST>
void update(double *in_x, double *in_P, Hfun h_fun, Hfun H_fun, Hfun Hea_fun, double *in_z, double *in_R, double *in_ea, double MAHA_THRESHOLD) {
  typedef Eigen::Matrix<double, ZDIM, ZDIM, Eigen::RowMajor> ZZM;
  typedef Eigen::Matrix<double, ZDIM, DIM, Eigen::RowMajor> ZDM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, EDIM, Eigen::RowMajor> XEM;
  //typedef Eigen::Matrix<double, EDIM, ZDIM, Eigen::RowMajor> EZM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, 1> X1M;
  typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> XXM;

  double in_hx[ZDIM] = {0};
  double in_H[ZDIM * DIM] = {0};
  double in_H_mod[EDIM * DIM] = {0};
  double delta_x[EDIM] = {0};
  double x_new[DIM] = {0};


  // state x, P
  Eigen::Matrix<double, ZDIM, 1> z(in_z);
  EEM P(in_P);
  ZZM pre_R(in_R);

  // functions from sympy
  h_fun(in_x, in_ea, in_hx);
  H_fun(in_x, in_ea, in_H);
  ZDM pre_H(in_H);

  // get y (y = z - hx)
  Eigen::Matrix<double, ZDIM, 1> pre_y(in_hx); pre_y = z - pre_y;
  X1M y; XXM H; XXM R;
  if (Hea_fun){
    typedef Eigen::Matrix<double, ZDIM, EADIM, Eigen::RowMajor> ZAM;
    double in_Hea[ZDIM * EADIM] = {0};
    Hea_fun(in_x, in_ea, in_Hea);
    ZAM Hea(in_Hea);
    XXM A = Hea.transpose().fullPivLu().kernel();


    y = A.transpose() * pre_y;
    H = A.transpose() * pre_H;
    R = A.transpose() * pre_R * A;
  } else {
    y = pre_y;
    H = pre_H;
    R = pre_R;
  }
  // get modified H
  H_mod_fun(in_x, in_H_mod);
  DEM H_mod(in_H_mod);
  XEM H_err = H * H_mod;

  // Do mahalobis distance test
  if (MAHA_TEST){
    XXM a = (H_err * P * H_err.transpose() + R).inverse();
    double maha_dist = y.transpose() * a * y;
    if (maha_dist > MAHA_THRESHOLD){
      R = 1.0e16 * R;
    }
  }

  // Outlier resilient weighting
  double weight = 1;//(1.5)/(1 + y.squaredNorm()/R.sum());

  // kalman gains and I_KH
  XXM S = ((H_err * P) * H_err.transpose()) + R/weight;
  XEM KT = S.fullPivLu().solve(H_err * P.transpose());
  //EZM K = KT.transpose(); TODO: WHY DOES THIS NOT COMPILE?
  //EZM K = S.fullPivLu().solve(H_err * P.transpose()).transpose();
  //std::cout << "Here is the matrix rot:\n" << K << std::endl;
  EEM I_KH = Eigen::Matrix<double, EDIM, EDIM>::Identity() - (KT.transpose() * H_err);

  // update state by injecting dx
  Eigen::Matrix<double, EDIM, 1> dx(delta_x);
  dx  = (KT.transpose() * y);
  memcpy(delta_x, dx.data(), EDIM * sizeof(double));
  err_fun(in_x, delta_x, x_new);
  Eigen::Matrix<double, DIM, 1> x(x_new);

  // update cov
  P = ((I_KH * P) * I_KH.transpose()) + ((KT.transpose() * R) * KT);

  // copy out state
  memcpy(in_x, x.data(), DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
  memcpy(in_z, y.data(), y.rows() * sizeof(double));
}




}
extern "C" {

void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_25, H_25, NULL, in_z, in_R, in_ea, MAHA_THRESH_25);
}
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<2, 3, 0>(in_x, in_P, h_24, H_24, NULL, in_z, in_R, in_ea, MAHA_THRESH_24);
}
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_30, H_30, NULL, in_z, in_R, in_ea, MAHA_THRESH_30);
}
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_26, H_26, NULL, in_z, in_R, in_ea, MAHA_THRESH_26);
}
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_27, H_27, NULL, in_z, in_R, in_ea, MAHA_THRESH_27);
}
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_29, H_29, NULL, in_z, in_R, in_ea, MAHA_THRESH_29);
}
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_28, H_28, NULL, in_z, in_R, in_ea, MAHA_THRESH_28);
}
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_31, H_31, NULL, in_z, in_R, in_ea, MAHA_THRESH_31);
}
void car_err_fun(double *nom_x, double *delta_x, double *out_5789016104638959634) {
  err_fun(nom_x, delta_x, out_5789016104638959634);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_2114092178249116758) {
  inv_err_fun(nom_x, true_x, out_2114092178249116758);
}
void car_H_mod_fun(double *state, double *out_627878828374656716) {
  H_mod_fun(state, out_627878828374656716);
}
void car_f_fun(double *state, double dt, double *out_1305717728670895028) {
  f_fun(state,  dt, out_1305717728670895028);
}
void car_F_fun(double *state, double dt, double *out_8542181060080239781) {
  F_fun(state,  dt, out_8542181060080239781);
}
void car_h_25(double *state, double *unused, double *out_6155566602907018448) {
  h_25(state, unused, out_6155566602907018448);
}
void car_H_25(double *state, double *unused, double *out_8625677019422657663) {
  H_25(state, unused, out_8625677019422657663);
}
void car_h_24(double *state, double *unused, double *out_2986924554783287993) {
  h_24(state, unused, out_2986924554783287993);
}
void car_H_24(double *state, double *unused, double *out_7595359270308025391) {
  H_24(state, unused, out_7595359270308025391);
}
void car_h_30(double *state, double *unused, double *out_1310325322793628059) {
  h_30(state, unused, out_1310325322793628059);
}
void car_H_30(double *state, double *unused, double *out_2904376712795277198) {
  H_30(state, unused, out_2904376712795277198);
}
void car_h_26(double *state, double *unused, double *out_4332404548287328776) {
  h_26(state, unused, out_4332404548287328776);
}
void car_H_26(double *state, double *unused, double *out_4884173700548601439) {
  H_26(state, unused, out_4884173700548601439);
}
void car_h_27(double *state, double *unused, double *out_4947792578797019583) {
  h_27(state, unused, out_4947792578797019583);
}
void car_H_27(double *state, double *unused, double *out_5079140024595702109) {
  H_27(state, unused, out_5079140024595702109);
}
void car_h_29(double *state, double *unused, double *out_3652054674887665173) {
  h_29(state, unused, out_3652054674887665173);
}
void car_H_29(double *state, double *unused, double *out_2394145368480885014) {
  H_29(state, unused, out_2394145368480885014);
}
void car_h_28(double *state, double *unused, double *out_6307420109806389411) {
  h_28(state, unused, out_6307420109806389411);
}
void car_H_28(double *state, double *unused, double *out_7476544385550415588) {
  H_28(state, unused, out_7476544385550415588);
}
void car_h_31(double *state, double *unused, double *out_9033952133807552864) {
  h_31(state, unused, out_9033952133807552864);
}
void car_H_31(double *state, double *unused, double *out_8656322981299618091) {
  H_31(state, unused, out_8656322981299618091);
}
void car_predict(double *in_x, double *in_P, double *in_Q, double dt) {
  predict(in_x, in_P, in_Q, dt);
}
void car_set_mass(double x) {
  set_mass(x);
}
void car_set_rotational_inertia(double x) {
  set_rotational_inertia(x);
}
void car_set_center_to_front(double x) {
  set_center_to_front(x);
}
void car_set_center_to_rear(double x) {
  set_center_to_rear(x);
}
void car_set_stiffness_front(double x) {
  set_stiffness_front(x);
}
void car_set_stiffness_rear(double x) {
  set_stiffness_rear(x);
}
}

const EKF car = {
  .name = "car",
  .kinds = { 25, 24, 30, 26, 27, 29, 28, 31 },
  .feature_kinds = {  },
  .f_fun = car_f_fun,
  .F_fun = car_F_fun,
  .err_fun = car_err_fun,
  .inv_err_fun = car_inv_err_fun,
  .H_mod_fun = car_H_mod_fun,
  .predict = car_predict,
  .hs = {
    { 25, car_h_25 },
    { 24, car_h_24 },
    { 30, car_h_30 },
    { 26, car_h_26 },
    { 27, car_h_27 },
    { 29, car_h_29 },
    { 28, car_h_28 },
    { 31, car_h_31 },
  },
  .Hs = {
    { 25, car_H_25 },
    { 24, car_H_24 },
    { 30, car_H_30 },
    { 26, car_H_26 },
    { 27, car_H_27 },
    { 29, car_H_29 },
    { 28, car_H_28 },
    { 31, car_H_31 },
  },
  .updates = {
    { 25, car_update_25 },
    { 24, car_update_24 },
    { 30, car_update_30 },
    { 26, car_update_26 },
    { 27, car_update_27 },
    { 29, car_update_29 },
    { 28, car_update_28 },
    { 31, car_update_31 },
  },
  .Hes = {
  },
  .sets = {
    { "mass", car_set_mass },
    { "rotational_inertia", car_set_rotational_inertia },
    { "center_to_front", car_set_center_to_front },
    { "center_to_rear", car_set_center_to_rear },
    { "stiffness_front", car_set_stiffness_front },
    { "stiffness_rear", car_set_stiffness_rear },
  },
  .extra_routines = {
  },
};

ekf_lib_init(car)
