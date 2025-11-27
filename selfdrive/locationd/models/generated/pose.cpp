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
void err_fun(double *nom_x, double *delta_x, double *out_286554823530916308) {
   out_286554823530916308[0] = delta_x[0] + nom_x[0];
   out_286554823530916308[1] = delta_x[1] + nom_x[1];
   out_286554823530916308[2] = delta_x[2] + nom_x[2];
   out_286554823530916308[3] = delta_x[3] + nom_x[3];
   out_286554823530916308[4] = delta_x[4] + nom_x[4];
   out_286554823530916308[5] = delta_x[5] + nom_x[5];
   out_286554823530916308[6] = delta_x[6] + nom_x[6];
   out_286554823530916308[7] = delta_x[7] + nom_x[7];
   out_286554823530916308[8] = delta_x[8] + nom_x[8];
   out_286554823530916308[9] = delta_x[9] + nom_x[9];
   out_286554823530916308[10] = delta_x[10] + nom_x[10];
   out_286554823530916308[11] = delta_x[11] + nom_x[11];
   out_286554823530916308[12] = delta_x[12] + nom_x[12];
   out_286554823530916308[13] = delta_x[13] + nom_x[13];
   out_286554823530916308[14] = delta_x[14] + nom_x[14];
   out_286554823530916308[15] = delta_x[15] + nom_x[15];
   out_286554823530916308[16] = delta_x[16] + nom_x[16];
   out_286554823530916308[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_61539773135089930) {
   out_61539773135089930[0] = -nom_x[0] + true_x[0];
   out_61539773135089930[1] = -nom_x[1] + true_x[1];
   out_61539773135089930[2] = -nom_x[2] + true_x[2];
   out_61539773135089930[3] = -nom_x[3] + true_x[3];
   out_61539773135089930[4] = -nom_x[4] + true_x[4];
   out_61539773135089930[5] = -nom_x[5] + true_x[5];
   out_61539773135089930[6] = -nom_x[6] + true_x[6];
   out_61539773135089930[7] = -nom_x[7] + true_x[7];
   out_61539773135089930[8] = -nom_x[8] + true_x[8];
   out_61539773135089930[9] = -nom_x[9] + true_x[9];
   out_61539773135089930[10] = -nom_x[10] + true_x[10];
   out_61539773135089930[11] = -nom_x[11] + true_x[11];
   out_61539773135089930[12] = -nom_x[12] + true_x[12];
   out_61539773135089930[13] = -nom_x[13] + true_x[13];
   out_61539773135089930[14] = -nom_x[14] + true_x[14];
   out_61539773135089930[15] = -nom_x[15] + true_x[15];
   out_61539773135089930[16] = -nom_x[16] + true_x[16];
   out_61539773135089930[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_5951487745039434469) {
   out_5951487745039434469[0] = 1.0;
   out_5951487745039434469[1] = 0.0;
   out_5951487745039434469[2] = 0.0;
   out_5951487745039434469[3] = 0.0;
   out_5951487745039434469[4] = 0.0;
   out_5951487745039434469[5] = 0.0;
   out_5951487745039434469[6] = 0.0;
   out_5951487745039434469[7] = 0.0;
   out_5951487745039434469[8] = 0.0;
   out_5951487745039434469[9] = 0.0;
   out_5951487745039434469[10] = 0.0;
   out_5951487745039434469[11] = 0.0;
   out_5951487745039434469[12] = 0.0;
   out_5951487745039434469[13] = 0.0;
   out_5951487745039434469[14] = 0.0;
   out_5951487745039434469[15] = 0.0;
   out_5951487745039434469[16] = 0.0;
   out_5951487745039434469[17] = 0.0;
   out_5951487745039434469[18] = 0.0;
   out_5951487745039434469[19] = 1.0;
   out_5951487745039434469[20] = 0.0;
   out_5951487745039434469[21] = 0.0;
   out_5951487745039434469[22] = 0.0;
   out_5951487745039434469[23] = 0.0;
   out_5951487745039434469[24] = 0.0;
   out_5951487745039434469[25] = 0.0;
   out_5951487745039434469[26] = 0.0;
   out_5951487745039434469[27] = 0.0;
   out_5951487745039434469[28] = 0.0;
   out_5951487745039434469[29] = 0.0;
   out_5951487745039434469[30] = 0.0;
   out_5951487745039434469[31] = 0.0;
   out_5951487745039434469[32] = 0.0;
   out_5951487745039434469[33] = 0.0;
   out_5951487745039434469[34] = 0.0;
   out_5951487745039434469[35] = 0.0;
   out_5951487745039434469[36] = 0.0;
   out_5951487745039434469[37] = 0.0;
   out_5951487745039434469[38] = 1.0;
   out_5951487745039434469[39] = 0.0;
   out_5951487745039434469[40] = 0.0;
   out_5951487745039434469[41] = 0.0;
   out_5951487745039434469[42] = 0.0;
   out_5951487745039434469[43] = 0.0;
   out_5951487745039434469[44] = 0.0;
   out_5951487745039434469[45] = 0.0;
   out_5951487745039434469[46] = 0.0;
   out_5951487745039434469[47] = 0.0;
   out_5951487745039434469[48] = 0.0;
   out_5951487745039434469[49] = 0.0;
   out_5951487745039434469[50] = 0.0;
   out_5951487745039434469[51] = 0.0;
   out_5951487745039434469[52] = 0.0;
   out_5951487745039434469[53] = 0.0;
   out_5951487745039434469[54] = 0.0;
   out_5951487745039434469[55] = 0.0;
   out_5951487745039434469[56] = 0.0;
   out_5951487745039434469[57] = 1.0;
   out_5951487745039434469[58] = 0.0;
   out_5951487745039434469[59] = 0.0;
   out_5951487745039434469[60] = 0.0;
   out_5951487745039434469[61] = 0.0;
   out_5951487745039434469[62] = 0.0;
   out_5951487745039434469[63] = 0.0;
   out_5951487745039434469[64] = 0.0;
   out_5951487745039434469[65] = 0.0;
   out_5951487745039434469[66] = 0.0;
   out_5951487745039434469[67] = 0.0;
   out_5951487745039434469[68] = 0.0;
   out_5951487745039434469[69] = 0.0;
   out_5951487745039434469[70] = 0.0;
   out_5951487745039434469[71] = 0.0;
   out_5951487745039434469[72] = 0.0;
   out_5951487745039434469[73] = 0.0;
   out_5951487745039434469[74] = 0.0;
   out_5951487745039434469[75] = 0.0;
   out_5951487745039434469[76] = 1.0;
   out_5951487745039434469[77] = 0.0;
   out_5951487745039434469[78] = 0.0;
   out_5951487745039434469[79] = 0.0;
   out_5951487745039434469[80] = 0.0;
   out_5951487745039434469[81] = 0.0;
   out_5951487745039434469[82] = 0.0;
   out_5951487745039434469[83] = 0.0;
   out_5951487745039434469[84] = 0.0;
   out_5951487745039434469[85] = 0.0;
   out_5951487745039434469[86] = 0.0;
   out_5951487745039434469[87] = 0.0;
   out_5951487745039434469[88] = 0.0;
   out_5951487745039434469[89] = 0.0;
   out_5951487745039434469[90] = 0.0;
   out_5951487745039434469[91] = 0.0;
   out_5951487745039434469[92] = 0.0;
   out_5951487745039434469[93] = 0.0;
   out_5951487745039434469[94] = 0.0;
   out_5951487745039434469[95] = 1.0;
   out_5951487745039434469[96] = 0.0;
   out_5951487745039434469[97] = 0.0;
   out_5951487745039434469[98] = 0.0;
   out_5951487745039434469[99] = 0.0;
   out_5951487745039434469[100] = 0.0;
   out_5951487745039434469[101] = 0.0;
   out_5951487745039434469[102] = 0.0;
   out_5951487745039434469[103] = 0.0;
   out_5951487745039434469[104] = 0.0;
   out_5951487745039434469[105] = 0.0;
   out_5951487745039434469[106] = 0.0;
   out_5951487745039434469[107] = 0.0;
   out_5951487745039434469[108] = 0.0;
   out_5951487745039434469[109] = 0.0;
   out_5951487745039434469[110] = 0.0;
   out_5951487745039434469[111] = 0.0;
   out_5951487745039434469[112] = 0.0;
   out_5951487745039434469[113] = 0.0;
   out_5951487745039434469[114] = 1.0;
   out_5951487745039434469[115] = 0.0;
   out_5951487745039434469[116] = 0.0;
   out_5951487745039434469[117] = 0.0;
   out_5951487745039434469[118] = 0.0;
   out_5951487745039434469[119] = 0.0;
   out_5951487745039434469[120] = 0.0;
   out_5951487745039434469[121] = 0.0;
   out_5951487745039434469[122] = 0.0;
   out_5951487745039434469[123] = 0.0;
   out_5951487745039434469[124] = 0.0;
   out_5951487745039434469[125] = 0.0;
   out_5951487745039434469[126] = 0.0;
   out_5951487745039434469[127] = 0.0;
   out_5951487745039434469[128] = 0.0;
   out_5951487745039434469[129] = 0.0;
   out_5951487745039434469[130] = 0.0;
   out_5951487745039434469[131] = 0.0;
   out_5951487745039434469[132] = 0.0;
   out_5951487745039434469[133] = 1.0;
   out_5951487745039434469[134] = 0.0;
   out_5951487745039434469[135] = 0.0;
   out_5951487745039434469[136] = 0.0;
   out_5951487745039434469[137] = 0.0;
   out_5951487745039434469[138] = 0.0;
   out_5951487745039434469[139] = 0.0;
   out_5951487745039434469[140] = 0.0;
   out_5951487745039434469[141] = 0.0;
   out_5951487745039434469[142] = 0.0;
   out_5951487745039434469[143] = 0.0;
   out_5951487745039434469[144] = 0.0;
   out_5951487745039434469[145] = 0.0;
   out_5951487745039434469[146] = 0.0;
   out_5951487745039434469[147] = 0.0;
   out_5951487745039434469[148] = 0.0;
   out_5951487745039434469[149] = 0.0;
   out_5951487745039434469[150] = 0.0;
   out_5951487745039434469[151] = 0.0;
   out_5951487745039434469[152] = 1.0;
   out_5951487745039434469[153] = 0.0;
   out_5951487745039434469[154] = 0.0;
   out_5951487745039434469[155] = 0.0;
   out_5951487745039434469[156] = 0.0;
   out_5951487745039434469[157] = 0.0;
   out_5951487745039434469[158] = 0.0;
   out_5951487745039434469[159] = 0.0;
   out_5951487745039434469[160] = 0.0;
   out_5951487745039434469[161] = 0.0;
   out_5951487745039434469[162] = 0.0;
   out_5951487745039434469[163] = 0.0;
   out_5951487745039434469[164] = 0.0;
   out_5951487745039434469[165] = 0.0;
   out_5951487745039434469[166] = 0.0;
   out_5951487745039434469[167] = 0.0;
   out_5951487745039434469[168] = 0.0;
   out_5951487745039434469[169] = 0.0;
   out_5951487745039434469[170] = 0.0;
   out_5951487745039434469[171] = 1.0;
   out_5951487745039434469[172] = 0.0;
   out_5951487745039434469[173] = 0.0;
   out_5951487745039434469[174] = 0.0;
   out_5951487745039434469[175] = 0.0;
   out_5951487745039434469[176] = 0.0;
   out_5951487745039434469[177] = 0.0;
   out_5951487745039434469[178] = 0.0;
   out_5951487745039434469[179] = 0.0;
   out_5951487745039434469[180] = 0.0;
   out_5951487745039434469[181] = 0.0;
   out_5951487745039434469[182] = 0.0;
   out_5951487745039434469[183] = 0.0;
   out_5951487745039434469[184] = 0.0;
   out_5951487745039434469[185] = 0.0;
   out_5951487745039434469[186] = 0.0;
   out_5951487745039434469[187] = 0.0;
   out_5951487745039434469[188] = 0.0;
   out_5951487745039434469[189] = 0.0;
   out_5951487745039434469[190] = 1.0;
   out_5951487745039434469[191] = 0.0;
   out_5951487745039434469[192] = 0.0;
   out_5951487745039434469[193] = 0.0;
   out_5951487745039434469[194] = 0.0;
   out_5951487745039434469[195] = 0.0;
   out_5951487745039434469[196] = 0.0;
   out_5951487745039434469[197] = 0.0;
   out_5951487745039434469[198] = 0.0;
   out_5951487745039434469[199] = 0.0;
   out_5951487745039434469[200] = 0.0;
   out_5951487745039434469[201] = 0.0;
   out_5951487745039434469[202] = 0.0;
   out_5951487745039434469[203] = 0.0;
   out_5951487745039434469[204] = 0.0;
   out_5951487745039434469[205] = 0.0;
   out_5951487745039434469[206] = 0.0;
   out_5951487745039434469[207] = 0.0;
   out_5951487745039434469[208] = 0.0;
   out_5951487745039434469[209] = 1.0;
   out_5951487745039434469[210] = 0.0;
   out_5951487745039434469[211] = 0.0;
   out_5951487745039434469[212] = 0.0;
   out_5951487745039434469[213] = 0.0;
   out_5951487745039434469[214] = 0.0;
   out_5951487745039434469[215] = 0.0;
   out_5951487745039434469[216] = 0.0;
   out_5951487745039434469[217] = 0.0;
   out_5951487745039434469[218] = 0.0;
   out_5951487745039434469[219] = 0.0;
   out_5951487745039434469[220] = 0.0;
   out_5951487745039434469[221] = 0.0;
   out_5951487745039434469[222] = 0.0;
   out_5951487745039434469[223] = 0.0;
   out_5951487745039434469[224] = 0.0;
   out_5951487745039434469[225] = 0.0;
   out_5951487745039434469[226] = 0.0;
   out_5951487745039434469[227] = 0.0;
   out_5951487745039434469[228] = 1.0;
   out_5951487745039434469[229] = 0.0;
   out_5951487745039434469[230] = 0.0;
   out_5951487745039434469[231] = 0.0;
   out_5951487745039434469[232] = 0.0;
   out_5951487745039434469[233] = 0.0;
   out_5951487745039434469[234] = 0.0;
   out_5951487745039434469[235] = 0.0;
   out_5951487745039434469[236] = 0.0;
   out_5951487745039434469[237] = 0.0;
   out_5951487745039434469[238] = 0.0;
   out_5951487745039434469[239] = 0.0;
   out_5951487745039434469[240] = 0.0;
   out_5951487745039434469[241] = 0.0;
   out_5951487745039434469[242] = 0.0;
   out_5951487745039434469[243] = 0.0;
   out_5951487745039434469[244] = 0.0;
   out_5951487745039434469[245] = 0.0;
   out_5951487745039434469[246] = 0.0;
   out_5951487745039434469[247] = 1.0;
   out_5951487745039434469[248] = 0.0;
   out_5951487745039434469[249] = 0.0;
   out_5951487745039434469[250] = 0.0;
   out_5951487745039434469[251] = 0.0;
   out_5951487745039434469[252] = 0.0;
   out_5951487745039434469[253] = 0.0;
   out_5951487745039434469[254] = 0.0;
   out_5951487745039434469[255] = 0.0;
   out_5951487745039434469[256] = 0.0;
   out_5951487745039434469[257] = 0.0;
   out_5951487745039434469[258] = 0.0;
   out_5951487745039434469[259] = 0.0;
   out_5951487745039434469[260] = 0.0;
   out_5951487745039434469[261] = 0.0;
   out_5951487745039434469[262] = 0.0;
   out_5951487745039434469[263] = 0.0;
   out_5951487745039434469[264] = 0.0;
   out_5951487745039434469[265] = 0.0;
   out_5951487745039434469[266] = 1.0;
   out_5951487745039434469[267] = 0.0;
   out_5951487745039434469[268] = 0.0;
   out_5951487745039434469[269] = 0.0;
   out_5951487745039434469[270] = 0.0;
   out_5951487745039434469[271] = 0.0;
   out_5951487745039434469[272] = 0.0;
   out_5951487745039434469[273] = 0.0;
   out_5951487745039434469[274] = 0.0;
   out_5951487745039434469[275] = 0.0;
   out_5951487745039434469[276] = 0.0;
   out_5951487745039434469[277] = 0.0;
   out_5951487745039434469[278] = 0.0;
   out_5951487745039434469[279] = 0.0;
   out_5951487745039434469[280] = 0.0;
   out_5951487745039434469[281] = 0.0;
   out_5951487745039434469[282] = 0.0;
   out_5951487745039434469[283] = 0.0;
   out_5951487745039434469[284] = 0.0;
   out_5951487745039434469[285] = 1.0;
   out_5951487745039434469[286] = 0.0;
   out_5951487745039434469[287] = 0.0;
   out_5951487745039434469[288] = 0.0;
   out_5951487745039434469[289] = 0.0;
   out_5951487745039434469[290] = 0.0;
   out_5951487745039434469[291] = 0.0;
   out_5951487745039434469[292] = 0.0;
   out_5951487745039434469[293] = 0.0;
   out_5951487745039434469[294] = 0.0;
   out_5951487745039434469[295] = 0.0;
   out_5951487745039434469[296] = 0.0;
   out_5951487745039434469[297] = 0.0;
   out_5951487745039434469[298] = 0.0;
   out_5951487745039434469[299] = 0.0;
   out_5951487745039434469[300] = 0.0;
   out_5951487745039434469[301] = 0.0;
   out_5951487745039434469[302] = 0.0;
   out_5951487745039434469[303] = 0.0;
   out_5951487745039434469[304] = 1.0;
   out_5951487745039434469[305] = 0.0;
   out_5951487745039434469[306] = 0.0;
   out_5951487745039434469[307] = 0.0;
   out_5951487745039434469[308] = 0.0;
   out_5951487745039434469[309] = 0.0;
   out_5951487745039434469[310] = 0.0;
   out_5951487745039434469[311] = 0.0;
   out_5951487745039434469[312] = 0.0;
   out_5951487745039434469[313] = 0.0;
   out_5951487745039434469[314] = 0.0;
   out_5951487745039434469[315] = 0.0;
   out_5951487745039434469[316] = 0.0;
   out_5951487745039434469[317] = 0.0;
   out_5951487745039434469[318] = 0.0;
   out_5951487745039434469[319] = 0.0;
   out_5951487745039434469[320] = 0.0;
   out_5951487745039434469[321] = 0.0;
   out_5951487745039434469[322] = 0.0;
   out_5951487745039434469[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_3196225065518721106) {
   out_3196225065518721106[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_3196225065518721106[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_3196225065518721106[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_3196225065518721106[3] = dt*state[12] + state[3];
   out_3196225065518721106[4] = dt*state[13] + state[4];
   out_3196225065518721106[5] = dt*state[14] + state[5];
   out_3196225065518721106[6] = state[6];
   out_3196225065518721106[7] = state[7];
   out_3196225065518721106[8] = state[8];
   out_3196225065518721106[9] = state[9];
   out_3196225065518721106[10] = state[10];
   out_3196225065518721106[11] = state[11];
   out_3196225065518721106[12] = state[12];
   out_3196225065518721106[13] = state[13];
   out_3196225065518721106[14] = state[14];
   out_3196225065518721106[15] = state[15];
   out_3196225065518721106[16] = state[16];
   out_3196225065518721106[17] = state[17];
}
void F_fun(double *state, double dt, double *out_1970636867034735721) {
   out_1970636867034735721[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_1970636867034735721[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_1970636867034735721[2] = 0;
   out_1970636867034735721[3] = 0;
   out_1970636867034735721[4] = 0;
   out_1970636867034735721[5] = 0;
   out_1970636867034735721[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_1970636867034735721[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_1970636867034735721[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_1970636867034735721[9] = 0;
   out_1970636867034735721[10] = 0;
   out_1970636867034735721[11] = 0;
   out_1970636867034735721[12] = 0;
   out_1970636867034735721[13] = 0;
   out_1970636867034735721[14] = 0;
   out_1970636867034735721[15] = 0;
   out_1970636867034735721[16] = 0;
   out_1970636867034735721[17] = 0;
   out_1970636867034735721[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_1970636867034735721[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_1970636867034735721[20] = 0;
   out_1970636867034735721[21] = 0;
   out_1970636867034735721[22] = 0;
   out_1970636867034735721[23] = 0;
   out_1970636867034735721[24] = 0;
   out_1970636867034735721[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_1970636867034735721[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_1970636867034735721[27] = 0;
   out_1970636867034735721[28] = 0;
   out_1970636867034735721[29] = 0;
   out_1970636867034735721[30] = 0;
   out_1970636867034735721[31] = 0;
   out_1970636867034735721[32] = 0;
   out_1970636867034735721[33] = 0;
   out_1970636867034735721[34] = 0;
   out_1970636867034735721[35] = 0;
   out_1970636867034735721[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_1970636867034735721[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_1970636867034735721[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_1970636867034735721[39] = 0;
   out_1970636867034735721[40] = 0;
   out_1970636867034735721[41] = 0;
   out_1970636867034735721[42] = 0;
   out_1970636867034735721[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_1970636867034735721[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_1970636867034735721[45] = 0;
   out_1970636867034735721[46] = 0;
   out_1970636867034735721[47] = 0;
   out_1970636867034735721[48] = 0;
   out_1970636867034735721[49] = 0;
   out_1970636867034735721[50] = 0;
   out_1970636867034735721[51] = 0;
   out_1970636867034735721[52] = 0;
   out_1970636867034735721[53] = 0;
   out_1970636867034735721[54] = 0;
   out_1970636867034735721[55] = 0;
   out_1970636867034735721[56] = 0;
   out_1970636867034735721[57] = 1;
   out_1970636867034735721[58] = 0;
   out_1970636867034735721[59] = 0;
   out_1970636867034735721[60] = 0;
   out_1970636867034735721[61] = 0;
   out_1970636867034735721[62] = 0;
   out_1970636867034735721[63] = 0;
   out_1970636867034735721[64] = 0;
   out_1970636867034735721[65] = 0;
   out_1970636867034735721[66] = dt;
   out_1970636867034735721[67] = 0;
   out_1970636867034735721[68] = 0;
   out_1970636867034735721[69] = 0;
   out_1970636867034735721[70] = 0;
   out_1970636867034735721[71] = 0;
   out_1970636867034735721[72] = 0;
   out_1970636867034735721[73] = 0;
   out_1970636867034735721[74] = 0;
   out_1970636867034735721[75] = 0;
   out_1970636867034735721[76] = 1;
   out_1970636867034735721[77] = 0;
   out_1970636867034735721[78] = 0;
   out_1970636867034735721[79] = 0;
   out_1970636867034735721[80] = 0;
   out_1970636867034735721[81] = 0;
   out_1970636867034735721[82] = 0;
   out_1970636867034735721[83] = 0;
   out_1970636867034735721[84] = 0;
   out_1970636867034735721[85] = dt;
   out_1970636867034735721[86] = 0;
   out_1970636867034735721[87] = 0;
   out_1970636867034735721[88] = 0;
   out_1970636867034735721[89] = 0;
   out_1970636867034735721[90] = 0;
   out_1970636867034735721[91] = 0;
   out_1970636867034735721[92] = 0;
   out_1970636867034735721[93] = 0;
   out_1970636867034735721[94] = 0;
   out_1970636867034735721[95] = 1;
   out_1970636867034735721[96] = 0;
   out_1970636867034735721[97] = 0;
   out_1970636867034735721[98] = 0;
   out_1970636867034735721[99] = 0;
   out_1970636867034735721[100] = 0;
   out_1970636867034735721[101] = 0;
   out_1970636867034735721[102] = 0;
   out_1970636867034735721[103] = 0;
   out_1970636867034735721[104] = dt;
   out_1970636867034735721[105] = 0;
   out_1970636867034735721[106] = 0;
   out_1970636867034735721[107] = 0;
   out_1970636867034735721[108] = 0;
   out_1970636867034735721[109] = 0;
   out_1970636867034735721[110] = 0;
   out_1970636867034735721[111] = 0;
   out_1970636867034735721[112] = 0;
   out_1970636867034735721[113] = 0;
   out_1970636867034735721[114] = 1;
   out_1970636867034735721[115] = 0;
   out_1970636867034735721[116] = 0;
   out_1970636867034735721[117] = 0;
   out_1970636867034735721[118] = 0;
   out_1970636867034735721[119] = 0;
   out_1970636867034735721[120] = 0;
   out_1970636867034735721[121] = 0;
   out_1970636867034735721[122] = 0;
   out_1970636867034735721[123] = 0;
   out_1970636867034735721[124] = 0;
   out_1970636867034735721[125] = 0;
   out_1970636867034735721[126] = 0;
   out_1970636867034735721[127] = 0;
   out_1970636867034735721[128] = 0;
   out_1970636867034735721[129] = 0;
   out_1970636867034735721[130] = 0;
   out_1970636867034735721[131] = 0;
   out_1970636867034735721[132] = 0;
   out_1970636867034735721[133] = 1;
   out_1970636867034735721[134] = 0;
   out_1970636867034735721[135] = 0;
   out_1970636867034735721[136] = 0;
   out_1970636867034735721[137] = 0;
   out_1970636867034735721[138] = 0;
   out_1970636867034735721[139] = 0;
   out_1970636867034735721[140] = 0;
   out_1970636867034735721[141] = 0;
   out_1970636867034735721[142] = 0;
   out_1970636867034735721[143] = 0;
   out_1970636867034735721[144] = 0;
   out_1970636867034735721[145] = 0;
   out_1970636867034735721[146] = 0;
   out_1970636867034735721[147] = 0;
   out_1970636867034735721[148] = 0;
   out_1970636867034735721[149] = 0;
   out_1970636867034735721[150] = 0;
   out_1970636867034735721[151] = 0;
   out_1970636867034735721[152] = 1;
   out_1970636867034735721[153] = 0;
   out_1970636867034735721[154] = 0;
   out_1970636867034735721[155] = 0;
   out_1970636867034735721[156] = 0;
   out_1970636867034735721[157] = 0;
   out_1970636867034735721[158] = 0;
   out_1970636867034735721[159] = 0;
   out_1970636867034735721[160] = 0;
   out_1970636867034735721[161] = 0;
   out_1970636867034735721[162] = 0;
   out_1970636867034735721[163] = 0;
   out_1970636867034735721[164] = 0;
   out_1970636867034735721[165] = 0;
   out_1970636867034735721[166] = 0;
   out_1970636867034735721[167] = 0;
   out_1970636867034735721[168] = 0;
   out_1970636867034735721[169] = 0;
   out_1970636867034735721[170] = 0;
   out_1970636867034735721[171] = 1;
   out_1970636867034735721[172] = 0;
   out_1970636867034735721[173] = 0;
   out_1970636867034735721[174] = 0;
   out_1970636867034735721[175] = 0;
   out_1970636867034735721[176] = 0;
   out_1970636867034735721[177] = 0;
   out_1970636867034735721[178] = 0;
   out_1970636867034735721[179] = 0;
   out_1970636867034735721[180] = 0;
   out_1970636867034735721[181] = 0;
   out_1970636867034735721[182] = 0;
   out_1970636867034735721[183] = 0;
   out_1970636867034735721[184] = 0;
   out_1970636867034735721[185] = 0;
   out_1970636867034735721[186] = 0;
   out_1970636867034735721[187] = 0;
   out_1970636867034735721[188] = 0;
   out_1970636867034735721[189] = 0;
   out_1970636867034735721[190] = 1;
   out_1970636867034735721[191] = 0;
   out_1970636867034735721[192] = 0;
   out_1970636867034735721[193] = 0;
   out_1970636867034735721[194] = 0;
   out_1970636867034735721[195] = 0;
   out_1970636867034735721[196] = 0;
   out_1970636867034735721[197] = 0;
   out_1970636867034735721[198] = 0;
   out_1970636867034735721[199] = 0;
   out_1970636867034735721[200] = 0;
   out_1970636867034735721[201] = 0;
   out_1970636867034735721[202] = 0;
   out_1970636867034735721[203] = 0;
   out_1970636867034735721[204] = 0;
   out_1970636867034735721[205] = 0;
   out_1970636867034735721[206] = 0;
   out_1970636867034735721[207] = 0;
   out_1970636867034735721[208] = 0;
   out_1970636867034735721[209] = 1;
   out_1970636867034735721[210] = 0;
   out_1970636867034735721[211] = 0;
   out_1970636867034735721[212] = 0;
   out_1970636867034735721[213] = 0;
   out_1970636867034735721[214] = 0;
   out_1970636867034735721[215] = 0;
   out_1970636867034735721[216] = 0;
   out_1970636867034735721[217] = 0;
   out_1970636867034735721[218] = 0;
   out_1970636867034735721[219] = 0;
   out_1970636867034735721[220] = 0;
   out_1970636867034735721[221] = 0;
   out_1970636867034735721[222] = 0;
   out_1970636867034735721[223] = 0;
   out_1970636867034735721[224] = 0;
   out_1970636867034735721[225] = 0;
   out_1970636867034735721[226] = 0;
   out_1970636867034735721[227] = 0;
   out_1970636867034735721[228] = 1;
   out_1970636867034735721[229] = 0;
   out_1970636867034735721[230] = 0;
   out_1970636867034735721[231] = 0;
   out_1970636867034735721[232] = 0;
   out_1970636867034735721[233] = 0;
   out_1970636867034735721[234] = 0;
   out_1970636867034735721[235] = 0;
   out_1970636867034735721[236] = 0;
   out_1970636867034735721[237] = 0;
   out_1970636867034735721[238] = 0;
   out_1970636867034735721[239] = 0;
   out_1970636867034735721[240] = 0;
   out_1970636867034735721[241] = 0;
   out_1970636867034735721[242] = 0;
   out_1970636867034735721[243] = 0;
   out_1970636867034735721[244] = 0;
   out_1970636867034735721[245] = 0;
   out_1970636867034735721[246] = 0;
   out_1970636867034735721[247] = 1;
   out_1970636867034735721[248] = 0;
   out_1970636867034735721[249] = 0;
   out_1970636867034735721[250] = 0;
   out_1970636867034735721[251] = 0;
   out_1970636867034735721[252] = 0;
   out_1970636867034735721[253] = 0;
   out_1970636867034735721[254] = 0;
   out_1970636867034735721[255] = 0;
   out_1970636867034735721[256] = 0;
   out_1970636867034735721[257] = 0;
   out_1970636867034735721[258] = 0;
   out_1970636867034735721[259] = 0;
   out_1970636867034735721[260] = 0;
   out_1970636867034735721[261] = 0;
   out_1970636867034735721[262] = 0;
   out_1970636867034735721[263] = 0;
   out_1970636867034735721[264] = 0;
   out_1970636867034735721[265] = 0;
   out_1970636867034735721[266] = 1;
   out_1970636867034735721[267] = 0;
   out_1970636867034735721[268] = 0;
   out_1970636867034735721[269] = 0;
   out_1970636867034735721[270] = 0;
   out_1970636867034735721[271] = 0;
   out_1970636867034735721[272] = 0;
   out_1970636867034735721[273] = 0;
   out_1970636867034735721[274] = 0;
   out_1970636867034735721[275] = 0;
   out_1970636867034735721[276] = 0;
   out_1970636867034735721[277] = 0;
   out_1970636867034735721[278] = 0;
   out_1970636867034735721[279] = 0;
   out_1970636867034735721[280] = 0;
   out_1970636867034735721[281] = 0;
   out_1970636867034735721[282] = 0;
   out_1970636867034735721[283] = 0;
   out_1970636867034735721[284] = 0;
   out_1970636867034735721[285] = 1;
   out_1970636867034735721[286] = 0;
   out_1970636867034735721[287] = 0;
   out_1970636867034735721[288] = 0;
   out_1970636867034735721[289] = 0;
   out_1970636867034735721[290] = 0;
   out_1970636867034735721[291] = 0;
   out_1970636867034735721[292] = 0;
   out_1970636867034735721[293] = 0;
   out_1970636867034735721[294] = 0;
   out_1970636867034735721[295] = 0;
   out_1970636867034735721[296] = 0;
   out_1970636867034735721[297] = 0;
   out_1970636867034735721[298] = 0;
   out_1970636867034735721[299] = 0;
   out_1970636867034735721[300] = 0;
   out_1970636867034735721[301] = 0;
   out_1970636867034735721[302] = 0;
   out_1970636867034735721[303] = 0;
   out_1970636867034735721[304] = 1;
   out_1970636867034735721[305] = 0;
   out_1970636867034735721[306] = 0;
   out_1970636867034735721[307] = 0;
   out_1970636867034735721[308] = 0;
   out_1970636867034735721[309] = 0;
   out_1970636867034735721[310] = 0;
   out_1970636867034735721[311] = 0;
   out_1970636867034735721[312] = 0;
   out_1970636867034735721[313] = 0;
   out_1970636867034735721[314] = 0;
   out_1970636867034735721[315] = 0;
   out_1970636867034735721[316] = 0;
   out_1970636867034735721[317] = 0;
   out_1970636867034735721[318] = 0;
   out_1970636867034735721[319] = 0;
   out_1970636867034735721[320] = 0;
   out_1970636867034735721[321] = 0;
   out_1970636867034735721[322] = 0;
   out_1970636867034735721[323] = 1;
}
void h_4(double *state, double *unused, double *out_4780830717175456004) {
   out_4780830717175456004[0] = state[6] + state[9];
   out_4780830717175456004[1] = state[7] + state[10];
   out_4780830717175456004[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_2179680535195526897) {
   out_2179680535195526897[0] = 0;
   out_2179680535195526897[1] = 0;
   out_2179680535195526897[2] = 0;
   out_2179680535195526897[3] = 0;
   out_2179680535195526897[4] = 0;
   out_2179680535195526897[5] = 0;
   out_2179680535195526897[6] = 1;
   out_2179680535195526897[7] = 0;
   out_2179680535195526897[8] = 0;
   out_2179680535195526897[9] = 1;
   out_2179680535195526897[10] = 0;
   out_2179680535195526897[11] = 0;
   out_2179680535195526897[12] = 0;
   out_2179680535195526897[13] = 0;
   out_2179680535195526897[14] = 0;
   out_2179680535195526897[15] = 0;
   out_2179680535195526897[16] = 0;
   out_2179680535195526897[17] = 0;
   out_2179680535195526897[18] = 0;
   out_2179680535195526897[19] = 0;
   out_2179680535195526897[20] = 0;
   out_2179680535195526897[21] = 0;
   out_2179680535195526897[22] = 0;
   out_2179680535195526897[23] = 0;
   out_2179680535195526897[24] = 0;
   out_2179680535195526897[25] = 1;
   out_2179680535195526897[26] = 0;
   out_2179680535195526897[27] = 0;
   out_2179680535195526897[28] = 1;
   out_2179680535195526897[29] = 0;
   out_2179680535195526897[30] = 0;
   out_2179680535195526897[31] = 0;
   out_2179680535195526897[32] = 0;
   out_2179680535195526897[33] = 0;
   out_2179680535195526897[34] = 0;
   out_2179680535195526897[35] = 0;
   out_2179680535195526897[36] = 0;
   out_2179680535195526897[37] = 0;
   out_2179680535195526897[38] = 0;
   out_2179680535195526897[39] = 0;
   out_2179680535195526897[40] = 0;
   out_2179680535195526897[41] = 0;
   out_2179680535195526897[42] = 0;
   out_2179680535195526897[43] = 0;
   out_2179680535195526897[44] = 1;
   out_2179680535195526897[45] = 0;
   out_2179680535195526897[46] = 0;
   out_2179680535195526897[47] = 1;
   out_2179680535195526897[48] = 0;
   out_2179680535195526897[49] = 0;
   out_2179680535195526897[50] = 0;
   out_2179680535195526897[51] = 0;
   out_2179680535195526897[52] = 0;
   out_2179680535195526897[53] = 0;
}
void h_10(double *state, double *unused, double *out_135423843922526497) {
   out_135423843922526497[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_135423843922526497[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_135423843922526497[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_5295779974263124150) {
   out_5295779974263124150[0] = 0;
   out_5295779974263124150[1] = 9.8100000000000005*cos(state[1]);
   out_5295779974263124150[2] = 0;
   out_5295779974263124150[3] = 0;
   out_5295779974263124150[4] = -state[8];
   out_5295779974263124150[5] = state[7];
   out_5295779974263124150[6] = 0;
   out_5295779974263124150[7] = state[5];
   out_5295779974263124150[8] = -state[4];
   out_5295779974263124150[9] = 0;
   out_5295779974263124150[10] = 0;
   out_5295779974263124150[11] = 0;
   out_5295779974263124150[12] = 1;
   out_5295779974263124150[13] = 0;
   out_5295779974263124150[14] = 0;
   out_5295779974263124150[15] = 1;
   out_5295779974263124150[16] = 0;
   out_5295779974263124150[17] = 0;
   out_5295779974263124150[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_5295779974263124150[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_5295779974263124150[20] = 0;
   out_5295779974263124150[21] = state[8];
   out_5295779974263124150[22] = 0;
   out_5295779974263124150[23] = -state[6];
   out_5295779974263124150[24] = -state[5];
   out_5295779974263124150[25] = 0;
   out_5295779974263124150[26] = state[3];
   out_5295779974263124150[27] = 0;
   out_5295779974263124150[28] = 0;
   out_5295779974263124150[29] = 0;
   out_5295779974263124150[30] = 0;
   out_5295779974263124150[31] = 1;
   out_5295779974263124150[32] = 0;
   out_5295779974263124150[33] = 0;
   out_5295779974263124150[34] = 1;
   out_5295779974263124150[35] = 0;
   out_5295779974263124150[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_5295779974263124150[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_5295779974263124150[38] = 0;
   out_5295779974263124150[39] = -state[7];
   out_5295779974263124150[40] = state[6];
   out_5295779974263124150[41] = 0;
   out_5295779974263124150[42] = state[4];
   out_5295779974263124150[43] = -state[3];
   out_5295779974263124150[44] = 0;
   out_5295779974263124150[45] = 0;
   out_5295779974263124150[46] = 0;
   out_5295779974263124150[47] = 0;
   out_5295779974263124150[48] = 0;
   out_5295779974263124150[49] = 0;
   out_5295779974263124150[50] = 1;
   out_5295779974263124150[51] = 0;
   out_5295779974263124150[52] = 0;
   out_5295779974263124150[53] = 1;
}
void h_13(double *state, double *unused, double *out_1822547114212723940) {
   out_1822547114212723940[0] = state[3];
   out_1822547114212723940[1] = state[4];
   out_1822547114212723940[2] = state[5];
}
void H_13(double *state, double *unused, double *out_1032593290136805904) {
   out_1032593290136805904[0] = 0;
   out_1032593290136805904[1] = 0;
   out_1032593290136805904[2] = 0;
   out_1032593290136805904[3] = 1;
   out_1032593290136805904[4] = 0;
   out_1032593290136805904[5] = 0;
   out_1032593290136805904[6] = 0;
   out_1032593290136805904[7] = 0;
   out_1032593290136805904[8] = 0;
   out_1032593290136805904[9] = 0;
   out_1032593290136805904[10] = 0;
   out_1032593290136805904[11] = 0;
   out_1032593290136805904[12] = 0;
   out_1032593290136805904[13] = 0;
   out_1032593290136805904[14] = 0;
   out_1032593290136805904[15] = 0;
   out_1032593290136805904[16] = 0;
   out_1032593290136805904[17] = 0;
   out_1032593290136805904[18] = 0;
   out_1032593290136805904[19] = 0;
   out_1032593290136805904[20] = 0;
   out_1032593290136805904[21] = 0;
   out_1032593290136805904[22] = 1;
   out_1032593290136805904[23] = 0;
   out_1032593290136805904[24] = 0;
   out_1032593290136805904[25] = 0;
   out_1032593290136805904[26] = 0;
   out_1032593290136805904[27] = 0;
   out_1032593290136805904[28] = 0;
   out_1032593290136805904[29] = 0;
   out_1032593290136805904[30] = 0;
   out_1032593290136805904[31] = 0;
   out_1032593290136805904[32] = 0;
   out_1032593290136805904[33] = 0;
   out_1032593290136805904[34] = 0;
   out_1032593290136805904[35] = 0;
   out_1032593290136805904[36] = 0;
   out_1032593290136805904[37] = 0;
   out_1032593290136805904[38] = 0;
   out_1032593290136805904[39] = 0;
   out_1032593290136805904[40] = 0;
   out_1032593290136805904[41] = 1;
   out_1032593290136805904[42] = 0;
   out_1032593290136805904[43] = 0;
   out_1032593290136805904[44] = 0;
   out_1032593290136805904[45] = 0;
   out_1032593290136805904[46] = 0;
   out_1032593290136805904[47] = 0;
   out_1032593290136805904[48] = 0;
   out_1032593290136805904[49] = 0;
   out_1032593290136805904[50] = 0;
   out_1032593290136805904[51] = 0;
   out_1032593290136805904[52] = 0;
   out_1032593290136805904[53] = 0;
}
void h_14(double *state, double *unused, double *out_80795115449031259) {
   out_80795115449031259[0] = state[6];
   out_80795115449031259[1] = state[7];
   out_80795115449031259[2] = state[8];
}
void H_14(double *state, double *unused, double *out_1783560321143957632) {
   out_1783560321143957632[0] = 0;
   out_1783560321143957632[1] = 0;
   out_1783560321143957632[2] = 0;
   out_1783560321143957632[3] = 0;
   out_1783560321143957632[4] = 0;
   out_1783560321143957632[5] = 0;
   out_1783560321143957632[6] = 1;
   out_1783560321143957632[7] = 0;
   out_1783560321143957632[8] = 0;
   out_1783560321143957632[9] = 0;
   out_1783560321143957632[10] = 0;
   out_1783560321143957632[11] = 0;
   out_1783560321143957632[12] = 0;
   out_1783560321143957632[13] = 0;
   out_1783560321143957632[14] = 0;
   out_1783560321143957632[15] = 0;
   out_1783560321143957632[16] = 0;
   out_1783560321143957632[17] = 0;
   out_1783560321143957632[18] = 0;
   out_1783560321143957632[19] = 0;
   out_1783560321143957632[20] = 0;
   out_1783560321143957632[21] = 0;
   out_1783560321143957632[22] = 0;
   out_1783560321143957632[23] = 0;
   out_1783560321143957632[24] = 0;
   out_1783560321143957632[25] = 1;
   out_1783560321143957632[26] = 0;
   out_1783560321143957632[27] = 0;
   out_1783560321143957632[28] = 0;
   out_1783560321143957632[29] = 0;
   out_1783560321143957632[30] = 0;
   out_1783560321143957632[31] = 0;
   out_1783560321143957632[32] = 0;
   out_1783560321143957632[33] = 0;
   out_1783560321143957632[34] = 0;
   out_1783560321143957632[35] = 0;
   out_1783560321143957632[36] = 0;
   out_1783560321143957632[37] = 0;
   out_1783560321143957632[38] = 0;
   out_1783560321143957632[39] = 0;
   out_1783560321143957632[40] = 0;
   out_1783560321143957632[41] = 0;
   out_1783560321143957632[42] = 0;
   out_1783560321143957632[43] = 0;
   out_1783560321143957632[44] = 1;
   out_1783560321143957632[45] = 0;
   out_1783560321143957632[46] = 0;
   out_1783560321143957632[47] = 0;
   out_1783560321143957632[48] = 0;
   out_1783560321143957632[49] = 0;
   out_1783560321143957632[50] = 0;
   out_1783560321143957632[51] = 0;
   out_1783560321143957632[52] = 0;
   out_1783560321143957632[53] = 0;
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
void pose_err_fun(double *nom_x, double *delta_x, double *out_286554823530916308) {
  err_fun(nom_x, delta_x, out_286554823530916308);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_61539773135089930) {
  inv_err_fun(nom_x, true_x, out_61539773135089930);
}
void pose_H_mod_fun(double *state, double *out_5951487745039434469) {
  H_mod_fun(state, out_5951487745039434469);
}
void pose_f_fun(double *state, double dt, double *out_3196225065518721106) {
  f_fun(state,  dt, out_3196225065518721106);
}
void pose_F_fun(double *state, double dt, double *out_1970636867034735721) {
  F_fun(state,  dt, out_1970636867034735721);
}
void pose_h_4(double *state, double *unused, double *out_4780830717175456004) {
  h_4(state, unused, out_4780830717175456004);
}
void pose_H_4(double *state, double *unused, double *out_2179680535195526897) {
  H_4(state, unused, out_2179680535195526897);
}
void pose_h_10(double *state, double *unused, double *out_135423843922526497) {
  h_10(state, unused, out_135423843922526497);
}
void pose_H_10(double *state, double *unused, double *out_5295779974263124150) {
  H_10(state, unused, out_5295779974263124150);
}
void pose_h_13(double *state, double *unused, double *out_1822547114212723940) {
  h_13(state, unused, out_1822547114212723940);
}
void pose_H_13(double *state, double *unused, double *out_1032593290136805904) {
  H_13(state, unused, out_1032593290136805904);
}
void pose_h_14(double *state, double *unused, double *out_80795115449031259) {
  h_14(state, unused, out_80795115449031259);
}
void pose_H_14(double *state, double *unused, double *out_1783560321143957632) {
  H_14(state, unused, out_1783560321143957632);
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
