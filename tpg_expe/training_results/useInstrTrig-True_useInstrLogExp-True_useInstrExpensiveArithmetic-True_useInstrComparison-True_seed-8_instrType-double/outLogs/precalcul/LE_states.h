// ===== Graph Traversal Mapping =====
// [0] -> [T0]
// [1] -> [T0 -> T4 -> T15 -> T9]
// ===================================

#ifndef SEEDS_H
#define SEEDS_H

#include "../codegen/externHeader.h"

#define NB_SEED 20
#define NB_VALUES_PER_CLASS 10
#define NB_CLASSES 2

// cartesianTarget
static const typeInf dataSourcesLE_0[NB_SEED] = {-218.303, 386.096, 130.398, 210.446, 297.032, 2.45344, -130.851, 154.475, -170.74, 356.329, 51.8152, 33.3246, 165.83, -49.2896, 179.373, -153.584, 364.29, 63.7503, 234.426, 48.2548};
static const typeInf dataSourcesLE_1[NB_SEED] = {101.615, -153.031, -354.128, -83.411, -206.479, -199.914, -132.466, -103.904, -172.848, -69.7425, 62.7435, 433.633, -290.648, 77.311, 210.542, 249.251, 58.6148, -320.494, -16.5693, 259.176};
static const typeInf dataSourcesLE_2[NB_SEED] = {328.961, 62.8544, 323.803, 179.744, 297.774, 83.4992, 175.409, 14.5939, 222.01, 196.679, 310.653, 174.506, 60.0316, 215.58, 361.114, 333.557, 170.556, 308.858, 57.2436, 170.001};
// cartesianHand
static const typeInf dataSourcesLE_3[1] = { 4.23728e-14 };
static const typeInf dataSourcesLE_4[1] = { 346 };
static const typeInf dataSourcesLE_5[1] = { 267 };
// cartesianDiff
static const typeInf dataSourcesLE_6[NB_SEED] = {-218.303, 386.096, 130.398, 210.446, 297.032, 2.45344, -130.851, 154.475, -170.74, 356.329, 51.8152, 33.3246, 165.83, -49.2896, 179.373, -153.584, 364.29, 63.7503, 234.426, 48.2548};
static const typeInf dataSourcesLE_7[NB_SEED] = {-244.385, -499.031, -700.128, -429.411, -552.479, -545.914, -478.466, -449.904, -518.848, -415.743, -283.257, 87.6334, -636.648, -268.689, -135.458, -96.7485, -287.385, -666.494, -362.569, -86.8238};
static const typeInf dataSourcesLE_8[NB_SEED] = {61.961, -204.146, 56.8032, -87.2563, 30.7735, -183.501, -91.5912, -252.406, -44.9899, -70.3208, 43.6527, -92.494, -206.968, -51.42, 94.1137, 66.5575, -96.4437, 41.8576, -209.756, -96.9987};
// motorPos
static const typeInf dataSourcesLE_9[1] = { 2048 };
static const typeInf dataSourcesLE_10[1] = { 2048 };
static const typeInf dataSourcesLE_11[1] = { 2048 };
static const typeInf dataSourcesLE_12[1] = { 2048 };
static const typeInf dataSourcesLE_13[1] = { 512 };
static const typeInf dataSourcesLE_14[1] = { 256 };

static const uint32_t seeds[NB_SEED] = {0, 9, 1, 22, 13, 4, 6, 18, 10, 2, 5, 23, 14, 3, 11, 12, 24, 8, 15, 7};
static const unsigned int ids_graph_traversals[NB_SEED] = {0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 0, 0, 0, 1, 0, 1, 1};

#endif // SEEDS_H
