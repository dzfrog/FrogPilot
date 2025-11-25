#include "pose.h"

namespace {
#define DIM 18
#define EDIM 18
#define MEDIM 18
typedef void (*Hfun)(double *, double *, double *);
const static double MAHA_THRESH_4 = 7.814727903251177;
const static double MAHA_THRESH_10 = 7.814727903251177;
const static double MAHA_THRESH_13 = 7.814727903251177;
const static double MAHA_THRESH_14 = 7.814727903251177;

/******************************************************************************
 *                      Code generated with SymPy 1.14.0                      *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_1506195149131963127) {
   out_1506195149131963127[0] = delta_x[0] + nom_x[0];
   out_1506195149131963127[1] = delta_x[1] + nom_x[1];
   out_1506195149131963127[2] = delta_x[2] + nom_x[2];
   out_1506195149131963127[3] = delta_x[3] + nom_x[3];
   out_1506195149131963127[4] = delta_x[4] + nom_x[4];
   out_1506195149131963127[5] = delta_x[5] + nom_x[5];
   out_1506195149131963127[6] = delta_x[6] + nom_x[6];
   out_1506195149131963127[7] = delta_x[7] + nom_x[7];
   out_1506195149131963127[8] = delta_x[8] + nom_x[8];
   out_1506195149131963127[9] = delta_x[9] + nom_x[9];
   out_1506195149131963127[10] = delta_x[10] + nom_x[10];
   out_1506195149131963127[11] = delta_x[11] + nom_x[11];
   out_1506195149131963127[12] = delta_x[12] + nom_x[12];
   out_1506195149131963127[13] = delta_x[13] + nom_x[13];
   out_1506195149131963127[14] = delta_x[14] + nom_x[14];
   out_1506195149131963127[15] = delta_x[15] + nom_x[15];
   out_1506195149131963127[16] = delta_x[16] + nom_x[16];
   out_1506195149131963127[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_7697979825393261245) {
   out_7697979825393261245[0] = -nom_x[0] + true_x[0];
   out_7697979825393261245[1] = -nom_x[1] + true_x[1];
   out_7697979825393261245[2] = -nom_x[2] + true_x[2];
   out_7697979825393261245[3] = -nom_x[3] + true_x[3];
   out_7697979825393261245[4] = -nom_x[4] + true_x[4];
   out_7697979825393261245[5] = -nom_x[5] + true_x[5];
   out_7697979825393261245[6] = -nom_x[6] + true_x[6];
   out_7697979825393261245[7] = -nom_x[7] + true_x[7];
   out_7697979825393261245[8] = -nom_x[8] + true_x[8];
   out_7697979825393261245[9] = -nom_x[9] + true_x[9];
   out_7697979825393261245[10] = -nom_x[10] + true_x[10];
   out_7697979825393261245[11] = -nom_x[11] + true_x[11];
   out_7697979825393261245[12] = -nom_x[12] + true_x[12];
   out_7697979825393261245[13] = -nom_x[13] + true_x[13];
   out_7697979825393261245[14] = -nom_x[14] + true_x[14];
   out_7697979825393261245[15] = -nom_x[15] + true_x[15];
   out_7697979825393261245[16] = -nom_x[16] + true_x[16];
   out_7697979825393261245[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_6822266201757739684) {
   out_6822266201757739684[0] = 1.0;
   out_6822266201757739684[1] = 0.0;
   out_6822266201757739684[2] = 0.0;
   out_6822266201757739684[3] = 0.0;
   out_6822266201757739684[4] = 0.0;
   out_6822266201757739684[5] = 0.0;
   out_6822266201757739684[6] = 0.0;
   out_6822266201757739684[7] = 0.0;
   out_6822266201757739684[8] = 0.0;
   out_6822266201757739684[9] = 0.0;
   out_6822266201757739684[10] = 0.0;
   out_6822266201757739684[11] = 0.0;
   out_6822266201757739684[12] = 0.0;
   out_6822266201757739684[13] = 0.0;
   out_6822266201757739684[14] = 0.0;
   out_6822266201757739684[15] = 0.0;
   out_6822266201757739684[16] = 0.0;
   out_6822266201757739684[17] = 0.0;
   out_6822266201757739684[18] = 0.0;
   out_6822266201757739684[19] = 1.0;
   out_6822266201757739684[20] = 0.0;
   out_6822266201757739684[21] = 0.0;
   out_6822266201757739684[22] = 0.0;
   out_6822266201757739684[23] = 0.0;
   out_6822266201757739684[24] = 0.0;
   out_6822266201757739684[25] = 0.0;
   out_6822266201757739684[26] = 0.0;
   out_6822266201757739684[27] = 0.0;
   out_6822266201757739684[28] = 0.0;
   out_6822266201757739684[29] = 0.0;
   out_6822266201757739684[30] = 0.0;
   out_6822266201757739684[31] = 0.0;
   out_6822266201757739684[32] = 0.0;
   out_6822266201757739684[33] = 0.0;
   out_6822266201757739684[34] = 0.0;
   out_6822266201757739684[35] = 0.0;
   out_6822266201757739684[36] = 0.0;
   out_6822266201757739684[37] = 0.0;
   out_6822266201757739684[38] = 1.0;
   out_6822266201757739684[39] = 0.0;
   out_6822266201757739684[40] = 0.0;
   out_6822266201757739684[41] = 0.0;
   out_6822266201757739684[42] = 0.0;
   out_6822266201757739684[43] = 0.0;
   out_6822266201757739684[44] = 0.0;
   out_6822266201757739684[45] = 0.0;
   out_6822266201757739684[46] = 0.0;
   out_6822266201757739684[47] = 0.0;
   out_6822266201757739684[48] = 0.0;
   out_6822266201757739684[49] = 0.0;
   out_6822266201757739684[50] = 0.0;
   out_6822266201757739684[51] = 0.0;
   out_6822266201757739684[52] = 0.0;
   out_6822266201757739684[53] = 0.0;
   out_6822266201757739684[54] = 0.0;
   out_6822266201757739684[55] = 0.0;
   out_6822266201757739684[56] = 0.0;
   out_6822266201757739684[57] = 1.0;
   out_6822266201757739684[58] = 0.0;
   out_6822266201757739684[59] = 0.0;
   out_6822266201757739684[60] = 0.0;
   out_6822266201757739684[61] = 0.0;
   out_6822266201757739684[62] = 0.0;
   out_6822266201757739684[63] = 0.0;
   out_6822266201757739684[64] = 0.0;
   out_6822266201757739684[65] = 0.0;
   out_6822266201757739684[66] = 0.0;
   out_6822266201757739684[67] = 0.0;
   out_6822266201757739684[68] = 0.0;
   out_6822266201757739684[69] = 0.0;
   out_6822266201757739684[70] = 0.0;
   out_6822266201757739684[71] = 0.0;
   out_6822266201757739684[72] = 0.0;
   out_6822266201757739684[73] = 0.0;
   out_6822266201757739684[74] = 0.0;
   out_6822266201757739684[75] = 0.0;
   out_6822266201757739684[76] = 1.0;
   out_6822266201757739684[77] = 0.0;
   out_6822266201757739684[78] = 0.0;
   out_6822266201757739684[79] = 0.0;
   out_6822266201757739684[80] = 0.0;
   out_6822266201757739684[81] = 0.0;
   out_6822266201757739684[82] = 0.0;
   out_6822266201757739684[83] = 0.0;
   out_6822266201757739684[84] = 0.0;
   out_6822266201757739684[85] = 0.0;
   out_6822266201757739684[86] = 0.0;
   out_6822266201757739684[87] = 0.0;
   out_6822266201757739684[88] = 0.0;
   out_6822266201757739684[89] = 0.0;
   out_6822266201757739684[90] = 0.0;
   out_6822266201757739684[91] = 0.0;
   out_6822266201757739684[92] = 0.0;
   out_6822266201757739684[93] = 0.0;
   out_6822266201757739684[94] = 0.0;
   out_6822266201757739684[95] = 1.0;
   out_6822266201757739684[96] = 0.0;
   out_6822266201757739684[97] = 0.0;
   out_6822266201757739684[98] = 0.0;
   out_6822266201757739684[99] = 0.0;
   out_6822266201757739684[100] = 0.0;
   out_6822266201757739684[101] = 0.0;
   out_6822266201757739684[102] = 0.0;
   out_6822266201757739684[103] = 0.0;
   out_6822266201757739684[104] = 0.0;
   out_6822266201757739684[105] = 0.0;
   out_6822266201757739684[106] = 0.0;
   out_6822266201757739684[107] = 0.0;
   out_6822266201757739684[108] = 0.0;
   out_6822266201757739684[109] = 0.0;
   out_6822266201757739684[110] = 0.0;
   out_6822266201757739684[111] = 0.0;
   out_6822266201757739684[112] = 0.0;
   out_6822266201757739684[113] = 0.0;
   out_6822266201757739684[114] = 1.0;
   out_6822266201757739684[115] = 0.0;
   out_6822266201757739684[116] = 0.0;
   out_6822266201757739684[117] = 0.0;
   out_6822266201757739684[118] = 0.0;
   out_6822266201757739684[119] = 0.0;
   out_6822266201757739684[120] = 0.0;
   out_6822266201757739684[121] = 0.0;
   out_6822266201757739684[122] = 0.0;
   out_6822266201757739684[123] = 0.0;
   out_6822266201757739684[124] = 0.0;
   out_6822266201757739684[125] = 0.0;
   out_6822266201757739684[126] = 0.0;
   out_6822266201757739684[127] = 0.0;
   out_6822266201757739684[128] = 0.0;
   out_6822266201757739684[129] = 0.0;
   out_6822266201757739684[130] = 0.0;
   out_6822266201757739684[131] = 0.0;
   out_6822266201757739684[132] = 0.0;
   out_6822266201757739684[133] = 1.0;
   out_6822266201757739684[134] = 0.0;
   out_6822266201757739684[135] = 0.0;
   out_6822266201757739684[136] = 0.0;
   out_6822266201757739684[137] = 0.0;
   out_6822266201757739684[138] = 0.0;
   out_6822266201757739684[139] = 0.0;
   out_6822266201757739684[140] = 0.0;
   out_6822266201757739684[141] = 0.0;
   out_6822266201757739684[142] = 0.0;
   out_6822266201757739684[143] = 0.0;
   out_6822266201757739684[144] = 0.0;
   out_6822266201757739684[145] = 0.0;
   out_6822266201757739684[146] = 0.0;
   out_6822266201757739684[147] = 0.0;
   out_6822266201757739684[148] = 0.0;
   out_6822266201757739684[149] = 0.0;
   out_6822266201757739684[150] = 0.0;
   out_6822266201757739684[151] = 0.0;
   out_6822266201757739684[152] = 1.0;
   out_6822266201757739684[153] = 0.0;
   out_6822266201757739684[154] = 0.0;
   out_6822266201757739684[155] = 0.0;
   out_6822266201757739684[156] = 0.0;
   out_6822266201757739684[157] = 0.0;
   out_6822266201757739684[158] = 0.0;
   out_6822266201757739684[159] = 0.0;
   out_6822266201757739684[160] = 0.0;
   out_6822266201757739684[161] = 0.0;
   out_6822266201757739684[162] = 0.0;
   out_6822266201757739684[163] = 0.0;
   out_6822266201757739684[164] = 0.0;
   out_6822266201757739684[165] = 0.0;
   out_6822266201757739684[166] = 0.0;
   out_6822266201757739684[167] = 0.0;
   out_6822266201757739684[168] = 0.0;
   out_6822266201757739684[169] = 0.0;
   out_6822266201757739684[170] = 0.0;
   out_6822266201757739684[171] = 1.0;
   out_6822266201757739684[172] = 0.0;
   out_6822266201757739684[173] = 0.0;
   out_6822266201757739684[174] = 0.0;
   out_6822266201757739684[175] = 0.0;
   out_6822266201757739684[176] = 0.0;
   out_6822266201757739684[177] = 0.0;
   out_6822266201757739684[178] = 0.0;
   out_6822266201757739684[179] = 0.0;
   out_6822266201757739684[180] = 0.0;
   out_6822266201757739684[181] = 0.0;
   out_6822266201757739684[182] = 0.0;
   out_6822266201757739684[183] = 0.0;
   out_6822266201757739684[184] = 0.0;
   out_6822266201757739684[185] = 0.0;
   out_6822266201757739684[186] = 0.0;
   out_6822266201757739684[187] = 0.0;
   out_6822266201757739684[188] = 0.0;
   out_6822266201757739684[189] = 0.0;
   out_6822266201757739684[190] = 1.0;
   out_6822266201757739684[191] = 0.0;
   out_6822266201757739684[192] = 0.0;
   out_6822266201757739684[193] = 0.0;
   out_6822266201757739684[194] = 0.0;
   out_6822266201757739684[195] = 0.0;
   out_6822266201757739684[196] = 0.0;
   out_6822266201757739684[197] = 0.0;
   out_6822266201757739684[198] = 0.0;
   out_6822266201757739684[199] = 0.0;
   out_6822266201757739684[200] = 0.0;
   out_6822266201757739684[201] = 0.0;
   out_6822266201757739684[202] = 0.0;
   out_6822266201757739684[203] = 0.0;
   out_6822266201757739684[204] = 0.0;
   out_6822266201757739684[205] = 0.0;
   out_6822266201757739684[206] = 0.0;
   out_6822266201757739684[207] = 0.0;
   out_6822266201757739684[208] = 0.0;
   out_6822266201757739684[209] = 1.0;
   out_6822266201757739684[210] = 0.0;
   out_6822266201757739684[211] = 0.0;
   out_6822266201757739684[212] = 0.0;
   out_6822266201757739684[213] = 0.0;
   out_6822266201757739684[214] = 0.0;
   out_6822266201757739684[215] = 0.0;
   out_6822266201757739684[216] = 0.0;
   out_6822266201757739684[217] = 0.0;
   out_6822266201757739684[218] = 0.0;
   out_6822266201757739684[219] = 0.0;
   out_6822266201757739684[220] = 0.0;
   out_6822266201757739684[221] = 0.0;
   out_6822266201757739684[222] = 0.0;
   out_6822266201757739684[223] = 0.0;
   out_6822266201757739684[224] = 0.0;
   out_6822266201757739684[225] = 0.0;
   out_6822266201757739684[226] = 0.0;
   out_6822266201757739684[227] = 0.0;
   out_6822266201757739684[228] = 1.0;
   out_6822266201757739684[229] = 0.0;
   out_6822266201757739684[230] = 0.0;
   out_6822266201757739684[231] = 0.0;
   out_6822266201757739684[232] = 0.0;
   out_6822266201757739684[233] = 0.0;
   out_6822266201757739684[234] = 0.0;
   out_6822266201757739684[235] = 0.0;
   out_6822266201757739684[236] = 0.0;
   out_6822266201757739684[237] = 0.0;
   out_6822266201757739684[238] = 0.0;
   out_6822266201757739684[239] = 0.0;
   out_6822266201757739684[240] = 0.0;
   out_6822266201757739684[241] = 0.0;
   out_6822266201757739684[242] = 0.0;
   out_6822266201757739684[243] = 0.0;
   out_6822266201757739684[244] = 0.0;
   out_6822266201757739684[245] = 0.0;
   out_6822266201757739684[246] = 0.0;
   out_6822266201757739684[247] = 1.0;
   out_6822266201757739684[248] = 0.0;
   out_6822266201757739684[249] = 0.0;
   out_6822266201757739684[250] = 0.0;
   out_6822266201757739684[251] = 0.0;
   out_6822266201757739684[252] = 0.0;
   out_6822266201757739684[253] = 0.0;
   out_6822266201757739684[254] = 0.0;
   out_6822266201757739684[255] = 0.0;
   out_6822266201757739684[256] = 0.0;
   out_6822266201757739684[257] = 0.0;
   out_6822266201757739684[258] = 0.0;
   out_6822266201757739684[259] = 0.0;
   out_6822266201757739684[260] = 0.0;
   out_6822266201757739684[261] = 0.0;
   out_6822266201757739684[262] = 0.0;
   out_6822266201757739684[263] = 0.0;
   out_6822266201757739684[264] = 0.0;
   out_6822266201757739684[265] = 0.0;
   out_6822266201757739684[266] = 1.0;
   out_6822266201757739684[267] = 0.0;
   out_6822266201757739684[268] = 0.0;
   out_6822266201757739684[269] = 0.0;
   out_6822266201757739684[270] = 0.0;
   out_6822266201757739684[271] = 0.0;
   out_6822266201757739684[272] = 0.0;
   out_6822266201757739684[273] = 0.0;
   out_6822266201757739684[274] = 0.0;
   out_6822266201757739684[275] = 0.0;
   out_6822266201757739684[276] = 0.0;
   out_6822266201757739684[277] = 0.0;
   out_6822266201757739684[278] = 0.0;
   out_6822266201757739684[279] = 0.0;
   out_6822266201757739684[280] = 0.0;
   out_6822266201757739684[281] = 0.0;
   out_6822266201757739684[282] = 0.0;
   out_6822266201757739684[283] = 0.0;
   out_6822266201757739684[284] = 0.0;
   out_6822266201757739684[285] = 1.0;
   out_6822266201757739684[286] = 0.0;
   out_6822266201757739684[287] = 0.0;
   out_6822266201757739684[288] = 0.0;
   out_6822266201757739684[289] = 0.0;
   out_6822266201757739684[290] = 0.0;
   out_6822266201757739684[291] = 0.0;
   out_6822266201757739684[292] = 0.0;
   out_6822266201757739684[293] = 0.0;
   out_6822266201757739684[294] = 0.0;
   out_6822266201757739684[295] = 0.0;
   out_6822266201757739684[296] = 0.0;
   out_6822266201757739684[297] = 0.0;
   out_6822266201757739684[298] = 0.0;
   out_6822266201757739684[299] = 0.0;
   out_6822266201757739684[300] = 0.0;
   out_6822266201757739684[301] = 0.0;
   out_6822266201757739684[302] = 0.0;
   out_6822266201757739684[303] = 0.0;
   out_6822266201757739684[304] = 1.0;
   out_6822266201757739684[305] = 0.0;
   out_6822266201757739684[306] = 0.0;
   out_6822266201757739684[307] = 0.0;
   out_6822266201757739684[308] = 0.0;
   out_6822266201757739684[309] = 0.0;
   out_6822266201757739684[310] = 0.0;
   out_6822266201757739684[311] = 0.0;
   out_6822266201757739684[312] = 0.0;
   out_6822266201757739684[313] = 0.0;
   out_6822266201757739684[314] = 0.0;
   out_6822266201757739684[315] = 0.0;
   out_6822266201757739684[316] = 0.0;
   out_6822266201757739684[317] = 0.0;
   out_6822266201757739684[318] = 0.0;
   out_6822266201757739684[319] = 0.0;
   out_6822266201757739684[320] = 0.0;
   out_6822266201757739684[321] = 0.0;
   out_6822266201757739684[322] = 0.0;
   out_6822266201757739684[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_1948814540219812874) {
   out_1948814540219812874[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_1948814540219812874[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_1948814540219812874[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_1948814540219812874[3] = dt*state[12] + state[3];
   out_1948814540219812874[4] = dt*state[13] + state[4];
   out_1948814540219812874[5] = dt*state[14] + state[5];
   out_1948814540219812874[6] = state[6];
   out_1948814540219812874[7] = state[7];
   out_1948814540219812874[8] = state[8];
   out_1948814540219812874[9] = state[9];
   out_1948814540219812874[10] = state[10];
   out_1948814540219812874[11] = state[11];
   out_1948814540219812874[12] = state[12];
   out_1948814540219812874[13] = state[13];
   out_1948814540219812874[14] = state[14];
   out_1948814540219812874[15] = state[15];
   out_1948814540219812874[16] = state[16];
   out_1948814540219812874[17] = state[17];
}
void F_fun(double *state, double dt, double *out_8951443110773343828) {
   out_8951443110773343828[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_8951443110773343828[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_8951443110773343828[2] = 0;
   out_8951443110773343828[3] = 0;
   out_8951443110773343828[4] = 0;
   out_8951443110773343828[5] = 0;
   out_8951443110773343828[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_8951443110773343828[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_8951443110773343828[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_8951443110773343828[9] = 0;
   out_8951443110773343828[10] = 0;
   out_8951443110773343828[11] = 0;
   out_8951443110773343828[12] = 0;
   out_8951443110773343828[13] = 0;
   out_8951443110773343828[14] = 0;
   out_8951443110773343828[15] = 0;
   out_8951443110773343828[16] = 0;
   out_8951443110773343828[17] = 0;
   out_8951443110773343828[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_8951443110773343828[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_8951443110773343828[20] = 0;
   out_8951443110773343828[21] = 0;
   out_8951443110773343828[22] = 0;
   out_8951443110773343828[23] = 0;
   out_8951443110773343828[24] = 0;
   out_8951443110773343828[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_8951443110773343828[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_8951443110773343828[27] = 0;
   out_8951443110773343828[28] = 0;
   out_8951443110773343828[29] = 0;
   out_8951443110773343828[30] = 0;
   out_8951443110773343828[31] = 0;
   out_8951443110773343828[32] = 0;
   out_8951443110773343828[33] = 0;
   out_8951443110773343828[34] = 0;
   out_8951443110773343828[35] = 0;
   out_8951443110773343828[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_8951443110773343828[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_8951443110773343828[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_8951443110773343828[39] = 0;
   out_8951443110773343828[40] = 0;
   out_8951443110773343828[41] = 0;
   out_8951443110773343828[42] = 0;
   out_8951443110773343828[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_8951443110773343828[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_8951443110773343828[45] = 0;
   out_8951443110773343828[46] = 0;
   out_8951443110773343828[47] = 0;
   out_8951443110773343828[48] = 0;
   out_8951443110773343828[49] = 0;
   out_8951443110773343828[50] = 0;
   out_8951443110773343828[51] = 0;
   out_8951443110773343828[52] = 0;
   out_8951443110773343828[53] = 0;
   out_8951443110773343828[54] = 0;
   out_8951443110773343828[55] = 0;
   out_8951443110773343828[56] = 0;
   out_8951443110773343828[57] = 1;
   out_8951443110773343828[58] = 0;
   out_8951443110773343828[59] = 0;
   out_8951443110773343828[60] = 0;
   out_8951443110773343828[61] = 0;
   out_8951443110773343828[62] = 0;
   out_8951443110773343828[63] = 0;
   out_8951443110773343828[64] = 0;
   out_8951443110773343828[65] = 0;
   out_8951443110773343828[66] = dt;
   out_8951443110773343828[67] = 0;
   out_8951443110773343828[68] = 0;
   out_8951443110773343828[69] = 0;
   out_8951443110773343828[70] = 0;
   out_8951443110773343828[71] = 0;
   out_8951443110773343828[72] = 0;
   out_8951443110773343828[73] = 0;
   out_8951443110773343828[74] = 0;
   out_8951443110773343828[75] = 0;
   out_8951443110773343828[76] = 1;
   out_8951443110773343828[77] = 0;
   out_8951443110773343828[78] = 0;
   out_8951443110773343828[79] = 0;
   out_8951443110773343828[80] = 0;
   out_8951443110773343828[81] = 0;
   out_8951443110773343828[82] = 0;
   out_8951443110773343828[83] = 0;
   out_8951443110773343828[84] = 0;
   out_8951443110773343828[85] = dt;
   out_8951443110773343828[86] = 0;
   out_8951443110773343828[87] = 0;
   out_8951443110773343828[88] = 0;
   out_8951443110773343828[89] = 0;
   out_8951443110773343828[90] = 0;
   out_8951443110773343828[91] = 0;
   out_8951443110773343828[92] = 0;
   out_8951443110773343828[93] = 0;
   out_8951443110773343828[94] = 0;
   out_8951443110773343828[95] = 1;
   out_8951443110773343828[96] = 0;
   out_8951443110773343828[97] = 0;
   out_8951443110773343828[98] = 0;
   out_8951443110773343828[99] = 0;
   out_8951443110773343828[100] = 0;
   out_8951443110773343828[101] = 0;
   out_8951443110773343828[102] = 0;
   out_8951443110773343828[103] = 0;
   out_8951443110773343828[104] = dt;
   out_8951443110773343828[105] = 0;
   out_8951443110773343828[106] = 0;
   out_8951443110773343828[107] = 0;
   out_8951443110773343828[108] = 0;
   out_8951443110773343828[109] = 0;
   out_8951443110773343828[110] = 0;
   out_8951443110773343828[111] = 0;
   out_8951443110773343828[112] = 0;
   out_8951443110773343828[113] = 0;
   out_8951443110773343828[114] = 1;
   out_8951443110773343828[115] = 0;
   out_8951443110773343828[116] = 0;
   out_8951443110773343828[117] = 0;
   out_8951443110773343828[118] = 0;
   out_8951443110773343828[119] = 0;
   out_8951443110773343828[120] = 0;
   out_8951443110773343828[121] = 0;
   out_8951443110773343828[122] = 0;
   out_8951443110773343828[123] = 0;
   out_8951443110773343828[124] = 0;
   out_8951443110773343828[125] = 0;
   out_8951443110773343828[126] = 0;
   out_8951443110773343828[127] = 0;
   out_8951443110773343828[128] = 0;
   out_8951443110773343828[129] = 0;
   out_8951443110773343828[130] = 0;
   out_8951443110773343828[131] = 0;
   out_8951443110773343828[132] = 0;
   out_8951443110773343828[133] = 1;
   out_8951443110773343828[134] = 0;
   out_8951443110773343828[135] = 0;
   out_8951443110773343828[136] = 0;
   out_8951443110773343828[137] = 0;
   out_8951443110773343828[138] = 0;
   out_8951443110773343828[139] = 0;
   out_8951443110773343828[140] = 0;
   out_8951443110773343828[141] = 0;
   out_8951443110773343828[142] = 0;
   out_8951443110773343828[143] = 0;
   out_8951443110773343828[144] = 0;
   out_8951443110773343828[145] = 0;
   out_8951443110773343828[146] = 0;
   out_8951443110773343828[147] = 0;
   out_8951443110773343828[148] = 0;
   out_8951443110773343828[149] = 0;
   out_8951443110773343828[150] = 0;
   out_8951443110773343828[151] = 0;
   out_8951443110773343828[152] = 1;
   out_8951443110773343828[153] = 0;
   out_8951443110773343828[154] = 0;
   out_8951443110773343828[155] = 0;
   out_8951443110773343828[156] = 0;
   out_8951443110773343828[157] = 0;
   out_8951443110773343828[158] = 0;
   out_8951443110773343828[159] = 0;
   out_8951443110773343828[160] = 0;
   out_8951443110773343828[161] = 0;
   out_8951443110773343828[162] = 0;
   out_8951443110773343828[163] = 0;
   out_8951443110773343828[164] = 0;
   out_8951443110773343828[165] = 0;
   out_8951443110773343828[166] = 0;
   out_8951443110773343828[167] = 0;
   out_8951443110773343828[168] = 0;
   out_8951443110773343828[169] = 0;
   out_8951443110773343828[170] = 0;
   out_8951443110773343828[171] = 1;
   out_8951443110773343828[172] = 0;
   out_8951443110773343828[173] = 0;
   out_8951443110773343828[174] = 0;
   out_8951443110773343828[175] = 0;
   out_8951443110773343828[176] = 0;
   out_8951443110773343828[177] = 0;
   out_8951443110773343828[178] = 0;
   out_8951443110773343828[179] = 0;
   out_8951443110773343828[180] = 0;
   out_8951443110773343828[181] = 0;
   out_8951443110773343828[182] = 0;
   out_8951443110773343828[183] = 0;
   out_8951443110773343828[184] = 0;
   out_8951443110773343828[185] = 0;
   out_8951443110773343828[186] = 0;
   out_8951443110773343828[187] = 0;
   out_8951443110773343828[188] = 0;
   out_8951443110773343828[189] = 0;
   out_8951443110773343828[190] = 1;
   out_8951443110773343828[191] = 0;
   out_8951443110773343828[192] = 0;
   out_8951443110773343828[193] = 0;
   out_8951443110773343828[194] = 0;
   out_8951443110773343828[195] = 0;
   out_8951443110773343828[196] = 0;
   out_8951443110773343828[197] = 0;
   out_8951443110773343828[198] = 0;
   out_8951443110773343828[199] = 0;
   out_8951443110773343828[200] = 0;
   out_8951443110773343828[201] = 0;
   out_8951443110773343828[202] = 0;
   out_8951443110773343828[203] = 0;
   out_8951443110773343828[204] = 0;
   out_8951443110773343828[205] = 0;
   out_8951443110773343828[206] = 0;
   out_8951443110773343828[207] = 0;
   out_8951443110773343828[208] = 0;
   out_8951443110773343828[209] = 1;
   out_8951443110773343828[210] = 0;
   out_8951443110773343828[211] = 0;
   out_8951443110773343828[212] = 0;
   out_8951443110773343828[213] = 0;
   out_8951443110773343828[214] = 0;
   out_8951443110773343828[215] = 0;
   out_8951443110773343828[216] = 0;
   out_8951443110773343828[217] = 0;
   out_8951443110773343828[218] = 0;
   out_8951443110773343828[219] = 0;
   out_8951443110773343828[220] = 0;
   out_8951443110773343828[221] = 0;
   out_8951443110773343828[222] = 0;
   out_8951443110773343828[223] = 0;
   out_8951443110773343828[224] = 0;
   out_8951443110773343828[225] = 0;
   out_8951443110773343828[226] = 0;
   out_8951443110773343828[227] = 0;
   out_8951443110773343828[228] = 1;
   out_8951443110773343828[229] = 0;
   out_8951443110773343828[230] = 0;
   out_8951443110773343828[231] = 0;
   out_8951443110773343828[232] = 0;
   out_8951443110773343828[233] = 0;
   out_8951443110773343828[234] = 0;
   out_8951443110773343828[235] = 0;
   out_8951443110773343828[236] = 0;
   out_8951443110773343828[237] = 0;
   out_8951443110773343828[238] = 0;
   out_8951443110773343828[239] = 0;
   out_8951443110773343828[240] = 0;
   out_8951443110773343828[241] = 0;
   out_8951443110773343828[242] = 0;
   out_8951443110773343828[243] = 0;
   out_8951443110773343828[244] = 0;
   out_8951443110773343828[245] = 0;
   out_8951443110773343828[246] = 0;
   out_8951443110773343828[247] = 1;
   out_8951443110773343828[248] = 0;
   out_8951443110773343828[249] = 0;
   out_8951443110773343828[250] = 0;
   out_8951443110773343828[251] = 0;
   out_8951443110773343828[252] = 0;
   out_8951443110773343828[253] = 0;
   out_8951443110773343828[254] = 0;
   out_8951443110773343828[255] = 0;
   out_8951443110773343828[256] = 0;
   out_8951443110773343828[257] = 0;
   out_8951443110773343828[258] = 0;
   out_8951443110773343828[259] = 0;
   out_8951443110773343828[260] = 0;
   out_8951443110773343828[261] = 0;
   out_8951443110773343828[262] = 0;
   out_8951443110773343828[263] = 0;
   out_8951443110773343828[264] = 0;
   out_8951443110773343828[265] = 0;
   out_8951443110773343828[266] = 1;
   out_8951443110773343828[267] = 0;
   out_8951443110773343828[268] = 0;
   out_8951443110773343828[269] = 0;
   out_8951443110773343828[270] = 0;
   out_8951443110773343828[271] = 0;
   out_8951443110773343828[272] = 0;
   out_8951443110773343828[273] = 0;
   out_8951443110773343828[274] = 0;
   out_8951443110773343828[275] = 0;
   out_8951443110773343828[276] = 0;
   out_8951443110773343828[277] = 0;
   out_8951443110773343828[278] = 0;
   out_8951443110773343828[279] = 0;
   out_8951443110773343828[280] = 0;
   out_8951443110773343828[281] = 0;
   out_8951443110773343828[282] = 0;
   out_8951443110773343828[283] = 0;
   out_8951443110773343828[284] = 0;
   out_8951443110773343828[285] = 1;
   out_8951443110773343828[286] = 0;
   out_8951443110773343828[287] = 0;
   out_8951443110773343828[288] = 0;
   out_8951443110773343828[289] = 0;
   out_8951443110773343828[290] = 0;
   out_8951443110773343828[291] = 0;
   out_8951443110773343828[292] = 0;
   out_8951443110773343828[293] = 0;
   out_8951443110773343828[294] = 0;
   out_8951443110773343828[295] = 0;
   out_8951443110773343828[296] = 0;
   out_8951443110773343828[297] = 0;
   out_8951443110773343828[298] = 0;
   out_8951443110773343828[299] = 0;
   out_8951443110773343828[300] = 0;
   out_8951443110773343828[301] = 0;
   out_8951443110773343828[302] = 0;
   out_8951443110773343828[303] = 0;
   out_8951443110773343828[304] = 1;
   out_8951443110773343828[305] = 0;
   out_8951443110773343828[306] = 0;
   out_8951443110773343828[307] = 0;
   out_8951443110773343828[308] = 0;
   out_8951443110773343828[309] = 0;
   out_8951443110773343828[310] = 0;
   out_8951443110773343828[311] = 0;
   out_8951443110773343828[312] = 0;
   out_8951443110773343828[313] = 0;
   out_8951443110773343828[314] = 0;
   out_8951443110773343828[315] = 0;
   out_8951443110773343828[316] = 0;
   out_8951443110773343828[317] = 0;
   out_8951443110773343828[318] = 0;
   out_8951443110773343828[319] = 0;
   out_8951443110773343828[320] = 0;
   out_8951443110773343828[321] = 0;
   out_8951443110773343828[322] = 0;
   out_8951443110773343828[323] = 1;
}
void h_4(double *state, double *unused, double *out_7758283624105186369) {
   out_7758283624105186369[0] = state[6] + state[9];
   out_7758283624105186369[1] = state[7] + state[10];
   out_7758283624105186369[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_974184395005780963) {
   out_974184395005780963[0] = 0;
   out_974184395005780963[1] = 0;
   out_974184395005780963[2] = 0;
   out_974184395005780963[3] = 0;
   out_974184395005780963[4] = 0;
   out_974184395005780963[5] = 0;
   out_974184395005780963[6] = 1;
   out_974184395005780963[7] = 0;
   out_974184395005780963[8] = 0;
   out_974184395005780963[9] = 1;
   out_974184395005780963[10] = 0;
   out_974184395005780963[11] = 0;
   out_974184395005780963[12] = 0;
   out_974184395005780963[13] = 0;
   out_974184395005780963[14] = 0;
   out_974184395005780963[15] = 0;
   out_974184395005780963[16] = 0;
   out_974184395005780963[17] = 0;
   out_974184395005780963[18] = 0;
   out_974184395005780963[19] = 0;
   out_974184395005780963[20] = 0;
   out_974184395005780963[21] = 0;
   out_974184395005780963[22] = 0;
   out_974184395005780963[23] = 0;
   out_974184395005780963[24] = 0;
   out_974184395005780963[25] = 1;
   out_974184395005780963[26] = 0;
   out_974184395005780963[27] = 0;
   out_974184395005780963[28] = 1;
   out_974184395005780963[29] = 0;
   out_974184395005780963[30] = 0;
   out_974184395005780963[31] = 0;
   out_974184395005780963[32] = 0;
   out_974184395005780963[33] = 0;
   out_974184395005780963[34] = 0;
   out_974184395005780963[35] = 0;
   out_974184395005780963[36] = 0;
   out_974184395005780963[37] = 0;
   out_974184395005780963[38] = 0;
   out_974184395005780963[39] = 0;
   out_974184395005780963[40] = 0;
   out_974184395005780963[41] = 0;
   out_974184395005780963[42] = 0;
   out_974184395005780963[43] = 0;
   out_974184395005780963[44] = 1;
   out_974184395005780963[45] = 0;
   out_974184395005780963[46] = 0;
   out_974184395005780963[47] = 1;
   out_974184395005780963[48] = 0;
   out_974184395005780963[49] = 0;
   out_974184395005780963[50] = 0;
   out_974184395005780963[51] = 0;
   out_974184395005780963[52] = 0;
   out_974184395005780963[53] = 0;
}
void h_10(double *state, double *unused, double *out_7394438859301058746) {
   out_7394438859301058746[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_7394438859301058746[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_7394438859301058746[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_2376123439446719646) {
   out_2376123439446719646[0] = 0;
   out_2376123439446719646[1] = 9.8100000000000005*cos(state[1]);
   out_2376123439446719646[2] = 0;
   out_2376123439446719646[3] = 0;
   out_2376123439446719646[4] = -state[8];
   out_2376123439446719646[5] = state[7];
   out_2376123439446719646[6] = 0;
   out_2376123439446719646[7] = state[5];
   out_2376123439446719646[8] = -state[4];
   out_2376123439446719646[9] = 0;
   out_2376123439446719646[10] = 0;
   out_2376123439446719646[11] = 0;
   out_2376123439446719646[12] = 1;
   out_2376123439446719646[13] = 0;
   out_2376123439446719646[14] = 0;
   out_2376123439446719646[15] = 1;
   out_2376123439446719646[16] = 0;
   out_2376123439446719646[17] = 0;
   out_2376123439446719646[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_2376123439446719646[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_2376123439446719646[20] = 0;
   out_2376123439446719646[21] = state[8];
   out_2376123439446719646[22] = 0;
   out_2376123439446719646[23] = -state[6];
   out_2376123439446719646[24] = -state[5];
   out_2376123439446719646[25] = 0;
   out_2376123439446719646[26] = state[3];
   out_2376123439446719646[27] = 0;
   out_2376123439446719646[28] = 0;
   out_2376123439446719646[29] = 0;
   out_2376123439446719646[30] = 0;
   out_2376123439446719646[31] = 1;
   out_2376123439446719646[32] = 0;
   out_2376123439446719646[33] = 0;
   out_2376123439446719646[34] = 1;
   out_2376123439446719646[35] = 0;
   out_2376123439446719646[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_2376123439446719646[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_2376123439446719646[38] = 0;
   out_2376123439446719646[39] = -state[7];
   out_2376123439446719646[40] = state[6];
   out_2376123439446719646[41] = 0;
   out_2376123439446719646[42] = state[4];
   out_2376123439446719646[43] = -state[3];
   out_2376123439446719646[44] = 0;
   out_2376123439446719646[45] = 0;
   out_2376123439446719646[46] = 0;
   out_2376123439446719646[47] = 0;
   out_2376123439446719646[48] = 0;
   out_2376123439446719646[49] = 0;
   out_2376123439446719646[50] = 1;
   out_2376123439446719646[51] = 0;
   out_2376123439446719646[52] = 0;
   out_2376123439446719646[53] = 1;
}
void h_13(double *state, double *unused, double *out_8336612566633508624) {
   out_8336612566633508624[0] = state[3];
   out_8336612566633508624[1] = state[4];
   out_8336612566633508624[2] = state[5];
}
void H_13(double *state, double *unused, double *out_4186458220338113764) {
   out_4186458220338113764[0] = 0;
   out_4186458220338113764[1] = 0;
   out_4186458220338113764[2] = 0;
   out_4186458220338113764[3] = 1;
   out_4186458220338113764[4] = 0;
   out_4186458220338113764[5] = 0;
   out_4186458220338113764[6] = 0;
   out_4186458220338113764[7] = 0;
   out_4186458220338113764[8] = 0;
   out_4186458220338113764[9] = 0;
   out_4186458220338113764[10] = 0;
   out_4186458220338113764[11] = 0;
   out_4186458220338113764[12] = 0;
   out_4186458220338113764[13] = 0;
   out_4186458220338113764[14] = 0;
   out_4186458220338113764[15] = 0;
   out_4186458220338113764[16] = 0;
   out_4186458220338113764[17] = 0;
   out_4186458220338113764[18] = 0;
   out_4186458220338113764[19] = 0;
   out_4186458220338113764[20] = 0;
   out_4186458220338113764[21] = 0;
   out_4186458220338113764[22] = 1;
   out_4186458220338113764[23] = 0;
   out_4186458220338113764[24] = 0;
   out_4186458220338113764[25] = 0;
   out_4186458220338113764[26] = 0;
   out_4186458220338113764[27] = 0;
   out_4186458220338113764[28] = 0;
   out_4186458220338113764[29] = 0;
   out_4186458220338113764[30] = 0;
   out_4186458220338113764[31] = 0;
   out_4186458220338113764[32] = 0;
   out_4186458220338113764[33] = 0;
   out_4186458220338113764[34] = 0;
   out_4186458220338113764[35] = 0;
   out_4186458220338113764[36] = 0;
   out_4186458220338113764[37] = 0;
   out_4186458220338113764[38] = 0;
   out_4186458220338113764[39] = 0;
   out_4186458220338113764[40] = 0;
   out_4186458220338113764[41] = 1;
   out_4186458220338113764[42] = 0;
   out_4186458220338113764[43] = 0;
   out_4186458220338113764[44] = 0;
   out_4186458220338113764[45] = 0;
   out_4186458220338113764[46] = 0;
   out_4186458220338113764[47] = 0;
   out_4186458220338113764[48] = 0;
   out_4186458220338113764[49] = 0;
   out_4186458220338113764[50] = 0;
   out_4186458220338113764[51] = 0;
   out_4186458220338113764[52] = 0;
   out_4186458220338113764[53] = 0;
}
void h_14(double *state, double *unused, double *out_2143117866505763143) {
   out_2143117866505763143[0] = state[6];
   out_2143117866505763143[1] = state[7];
   out_2143117866505763143[2] = state[8];
}
void H_14(double *state, double *unused, double *out_4937425251345265492) {
   out_4937425251345265492[0] = 0;
   out_4937425251345265492[1] = 0;
   out_4937425251345265492[2] = 0;
   out_4937425251345265492[3] = 0;
   out_4937425251345265492[4] = 0;
   out_4937425251345265492[5] = 0;
   out_4937425251345265492[6] = 1;
   out_4937425251345265492[7] = 0;
   out_4937425251345265492[8] = 0;
   out_4937425251345265492[9] = 0;
   out_4937425251345265492[10] = 0;
   out_4937425251345265492[11] = 0;
   out_4937425251345265492[12] = 0;
   out_4937425251345265492[13] = 0;
   out_4937425251345265492[14] = 0;
   out_4937425251345265492[15] = 0;
   out_4937425251345265492[16] = 0;
   out_4937425251345265492[17] = 0;
   out_4937425251345265492[18] = 0;
   out_4937425251345265492[19] = 0;
   out_4937425251345265492[20] = 0;
   out_4937425251345265492[21] = 0;
   out_4937425251345265492[22] = 0;
   out_4937425251345265492[23] = 0;
   out_4937425251345265492[24] = 0;
   out_4937425251345265492[25] = 1;
   out_4937425251345265492[26] = 0;
   out_4937425251345265492[27] = 0;
   out_4937425251345265492[28] = 0;
   out_4937425251345265492[29] = 0;
   out_4937425251345265492[30] = 0;
   out_4937425251345265492[31] = 0;
   out_4937425251345265492[32] = 0;
   out_4937425251345265492[33] = 0;
   out_4937425251345265492[34] = 0;
   out_4937425251345265492[35] = 0;
   out_4937425251345265492[36] = 0;
   out_4937425251345265492[37] = 0;
   out_4937425251345265492[38] = 0;
   out_4937425251345265492[39] = 0;
   out_4937425251345265492[40] = 0;
   out_4937425251345265492[41] = 0;
   out_4937425251345265492[42] = 0;
   out_4937425251345265492[43] = 0;
   out_4937425251345265492[44] = 1;
   out_4937425251345265492[45] = 0;
   out_4937425251345265492[46] = 0;
   out_4937425251345265492[47] = 0;
   out_4937425251345265492[48] = 0;
   out_4937425251345265492[49] = 0;
   out_4937425251345265492[50] = 0;
   out_4937425251345265492[51] = 0;
   out_4937425251345265492[52] = 0;
   out_4937425251345265492[53] = 0;
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

void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_4, H_4, NULL, in_z, in_R, in_ea, MAHA_THRESH_4);
}
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_10, H_10, NULL, in_z, in_R, in_ea, MAHA_THRESH_10);
}
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_13, H_13, NULL, in_z, in_R, in_ea, MAHA_THRESH_13);
}
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_14, H_14, NULL, in_z, in_R, in_ea, MAHA_THRESH_14);
}
void pose_err_fun(double *nom_x, double *delta_x, double *out_1506195149131963127) {
  err_fun(nom_x, delta_x, out_1506195149131963127);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_7697979825393261245) {
  inv_err_fun(nom_x, true_x, out_7697979825393261245);
}
void pose_H_mod_fun(double *state, double *out_6822266201757739684) {
  H_mod_fun(state, out_6822266201757739684);
}
void pose_f_fun(double *state, double dt, double *out_1948814540219812874) {
  f_fun(state,  dt, out_1948814540219812874);
}
void pose_F_fun(double *state, double dt, double *out_8951443110773343828) {
  F_fun(state,  dt, out_8951443110773343828);
}
void pose_h_4(double *state, double *unused, double *out_7758283624105186369) {
  h_4(state, unused, out_7758283624105186369);
}
void pose_H_4(double *state, double *unused, double *out_974184395005780963) {
  H_4(state, unused, out_974184395005780963);
}
void pose_h_10(double *state, double *unused, double *out_7394438859301058746) {
  h_10(state, unused, out_7394438859301058746);
}
void pose_H_10(double *state, double *unused, double *out_2376123439446719646) {
  H_10(state, unused, out_2376123439446719646);
}
void pose_h_13(double *state, double *unused, double *out_8336612566633508624) {
  h_13(state, unused, out_8336612566633508624);
}
void pose_H_13(double *state, double *unused, double *out_4186458220338113764) {
  H_13(state, unused, out_4186458220338113764);
}
void pose_h_14(double *state, double *unused, double *out_2143117866505763143) {
  h_14(state, unused, out_2143117866505763143);
}
void pose_H_14(double *state, double *unused, double *out_4937425251345265492) {
  H_14(state, unused, out_4937425251345265492);
}
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt) {
  predict(in_x, in_P, in_Q, dt);
}
}

const EKF pose = {
  .name = "pose",
  .kinds = { 4, 10, 13, 14 },
  .feature_kinds = {  },
  .f_fun = pose_f_fun,
  .F_fun = pose_F_fun,
  .err_fun = pose_err_fun,
  .inv_err_fun = pose_inv_err_fun,
  .H_mod_fun = pose_H_mod_fun,
  .predict = pose_predict,
  .hs = {
    { 4, pose_h_4 },
    { 10, pose_h_10 },
    { 13, pose_h_13 },
    { 14, pose_h_14 },
  },
  .Hs = {
    { 4, pose_H_4 },
    { 10, pose_H_10 },
    { 13, pose_H_13 },
    { 14, pose_H_14 },
  },
  .updates = {
    { 4, pose_update_4 },
    { 10, pose_update_10 },
    { 13, pose_update_13 },
    { 14, pose_update_14 },
  },
  .Hes = {
  },
  .sets = {
  },
  .extra_routines = {
  },
};

ekf_lib_init(pose)
