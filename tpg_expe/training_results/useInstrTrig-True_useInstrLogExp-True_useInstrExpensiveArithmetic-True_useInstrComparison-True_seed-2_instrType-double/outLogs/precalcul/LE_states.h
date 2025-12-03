// ===== Graph Traversal Mapping =====
// [0] -> [T0]
// [1] -> [T0 -> T1 -> T2]
// ===================================

#ifndef SEEDS_H
#define SEEDS_H

#include "../codegen/externHeader.h"

#define NB_SEED 20
#define NB_VALUES_PER_CLASS 10
#define NB_CLASSES 2

// cartesianTarget
static const typeInf dataSourcesLE_0[NB_SEED] = {-111.673, -169.829, 46.3337, -109.715, 7.28119, 83.8787, 146.193, 341.787, 103.737, 222.348, -116.139, -224.715, -201.858, -49.5568, -283.109, 17.6541, -37.5123, -210.585, 274.529, -221.004};
static const typeInf dataSourcesLE_1[NB_SEED] = {36.1333, -177.284, -147.83, -89.479, -98.7086, -209.745, -286.052, -270.124, 194.078, 286.722, 243.62, -177.599, 168.793, -78.2587, 46.4441, -10.6552, -276.199, -300.964, 293.713, 1.35608};
static const typeInf dataSourcesLE_2[NB_SEED] = {319.482, 37.3578, 361.088, 243.116, 344.971, 157.069, 287.615, 160.784, 351.447, 264.644, 322.418, 94.0515, 99.0523, 376.139, 432.044, 491.77, 68.9334, 338.876, 158.914, 52.6166};
// cartesianHand
static const typeInf dataSourcesLE_3[1] = { 4.23728e-14 };
static const typeInf dataSourcesLE_4[1] = { 346 };
static const typeInf dataSourcesLE_5[1] = { 267 };
// cartesianDiff
static const typeInf dataSourcesLE_6[NB_SEED] = {-111.673, -169.829, 46.3337, -109.715, 7.28119, 83.8787, 146.193, 341.787, 103.737, 222.348, -116.139, -224.715, -201.858, -49.5568, -283.109, 17.6541, -37.5123, -210.585, 274.529, -221.004};
static const typeInf dataSourcesLE_7[NB_SEED] = {-309.867, -523.284, -493.83, -435.479, -444.709, -555.745, -632.052, -616.124, -151.922, -59.2785, -102.38, -523.599, -177.207, -424.259, -299.556, -356.655, -622.199, -646.964, -52.2867, -344.644};
static const typeInf dataSourcesLE_8[NB_SEED] = {52.4819, -229.642, 94.0879, -23.8841, 77.9712, -109.931, 20.6146, -106.216, 84.4467, -2.35563, 55.4183, -172.948, -167.948, 109.139, 165.044, 224.77, -198.067, 71.8762, -108.086, -214.383};
// motorPos
static const typeInf dataSourcesLE_9[1] = { 2048 };
static const typeInf dataSourcesLE_10[1] = { 2048 };
static const typeInf dataSourcesLE_11[1] = { 2048 };
static const typeInf dataSourcesLE_12[1] = { 2048 };
static const typeInf dataSourcesLE_13[1] = { 512 };
static const typeInf dataSourcesLE_14[1] = { 256 };

static const uint32_t seeds[NB_SEED] = {0, 7, 1, 13, 22, 3, 9, 11, 15, 2, 6, 14, 8, 4, 18, 19, 16, 12, 10, 5};
static const unsigned int ids_graph_traversals[NB_SEED] = {0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 0, 0, 0, 1, 0, 1, 1};

#endif // SEEDS_H
