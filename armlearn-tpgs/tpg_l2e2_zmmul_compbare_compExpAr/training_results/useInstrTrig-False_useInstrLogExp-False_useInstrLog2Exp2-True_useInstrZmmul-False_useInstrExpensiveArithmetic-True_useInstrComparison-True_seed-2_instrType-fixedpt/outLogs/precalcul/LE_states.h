// ===== Graph Traversal Mapping =====
// [0] -> [T0]
// ===================================

#ifndef SEEDS_H
#define SEEDS_H

#include "../codegen/externHeader.h"

#define NB_SEED 10
#define NB_VALUES_PER_CLASS 10
#define NB_CLASSES 1

// cartesianTarget
static const fixedpt dataSourcesLE_0[NB_SEED] = {-7318602, 14571775, 3036528, -14483694, 9580934, -13228960, -3247754, -11129896, -7611313, 5497073};
static const fixedpt dataSourcesLE_1[NB_SEED] = {2368032, 18790580, -9688184, 88871, -18746733, 11062047, -5128764, -11618510, 15965853, -13745838};
static const fixedpt dataSourcesLE_2[NB_SEED] = {20937568, 17343733, 23664255, 3448279, 18849113, 6491494, 24650672, 2448282, 21130008, 10293693};
// cartesianHand
static const fixedpt dataSourcesLE_3[1] = { 0 };
static const fixedpt dataSourcesLE_4[1] = { 22675456 };
static const fixedpt dataSourcesLE_5[1] = { 17498112 };
// cartesianDiff
static const fixedpt dataSourcesLE_6[NB_SEED] = {-7318602, 14571775, 3036528, -14483694, 9580934, -13228960, -3247754, -11129896, -7611313, 5497073};
static const fixedpt dataSourcesLE_7[NB_SEED] = {-20307423, -3884875, -32363640, -22586584, -41422189, -11613408, -27804220, -34293966, -6709602, -36421294};
static const fixedpt dataSourcesLE_8[NB_SEED] = {3439456, -154378, 6166143, -14049832, 1351001, -11006617, 7152560, -15049829, 3631896, -7204418};
// motorPos
static const fixedpt dataSourcesLE_9[1] = { 134217728 };
static const fixedpt dataSourcesLE_10[1] = { 134217728 };
static const fixedpt dataSourcesLE_11[1] = { 134217728 };
static const fixedpt dataSourcesLE_12[1] = { 134217728 };
static const fixedpt dataSourcesLE_13[1] = { 33554432 };
static const fixedpt dataSourcesLE_14[1] = { 16777216 };

static const uint32_t seeds[NB_SEED] = {0, 2, 1, 5, 9, 8, 4, 7, 6, 3};
static const unsigned int ids_graph_traversals[NB_SEED] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

#endif // SEEDS_H
