// ===== Graph Traversal Mapping =====
// [0] -> [T0]
// [1] -> [T0 -> T2]
// ===================================

#ifndef SEEDS_H
#define SEEDS_H

#include "../codegen/externHeader.h"

#define NB_SEED 20
#define NB_VALUES_PER_CLASS 10
#define NB_CLASSES 2

// cartesianTarget
static const fixedpt dataSourcesLE_0[NB_SEED] = {14148078, -16522888, 13273053, -10788540, 12027277, -20489782, 13951039, -20241878, 1258115, -7497153, 2788548, -15988129, -11068812, 9945247, 2830952, 10813128, -1838911, 14098489, -862974, -9055206};
static const fixedpt dataSourcesLE_1[NB_SEED] = {4818767, 2658555, -17224720, 5021827, -20348412, -7402349, 15392600, -3002598, -12017457, 15124660, -3735912, -15696499, 237747, -14213595, -455504, 15864925, -4401285, 519278, -1266148, 16941099};
static const fixedpt dataSourcesLE_2[NB_SEED] = {5116895, 24382435, 15486557, 15826831, 21441634, 12283247, 22807097, 11813418, 17097094, 12025812, 21187158, 17218962, 12096114, 15197275, 27770312, 14361492, 25639953, 25436276, 37314920, 23368462};
// cartesianHand
static const fixedpt dataSourcesLE_3[1] = { 0 };
static const fixedpt dataSourcesLE_4[1] = { 22675456 };
static const fixedpt dataSourcesLE_5[1] = { 17498112 };
// cartesianDiff
static const fixedpt dataSourcesLE_6[NB_SEED] = {14148078, -16522888, 13273053, -10788540, 12027277, -20489782, 13951039, -20241878, 1258115, -7497153, 2788548, -15988129, -11068812, 9945247, 2830952, 10813128, -1838911, 14098489, -862974, -9055206};
static const fixedpt dataSourcesLE_7[NB_SEED] = {-17856688, -20016900, -39900176, -17653628, -43023868, -30077805, -7282855, -25678054, -34692913, -7550795, -26411368, -38371955, -22437708, -36889051, -23130960, -6810530, -27076741, -22156177, -23941604, -5734356};
static const fixedpt dataSourcesLE_8[NB_SEED] = {-12381216, 6884323, -2011554, -1671280, 3943522, -5214864, 5308985, -5684693, -401017, -5472299, 3689046, -279149, -5401997, -2300836, 10272200, -3136619, 8141841, 7938164, 19816808, 5870350};
// motorPos
static const fixedpt dataSourcesLE_9[1] = { 134217728 };
static const fixedpt dataSourcesLE_10[1] = { 134217728 };
static const fixedpt dataSourcesLE_11[1] = { 134217728 };
static const fixedpt dataSourcesLE_12[1] = { 134217728 };
static const fixedpt dataSourcesLE_13[1] = { 33554432 };
static const fixedpt dataSourcesLE_14[1] = { 16777216 };

static const uint32_t seeds[NB_SEED] = {0, 12, 1, 19, 14, 6, 5, 16, 8, 3, 4, 20, 13, 2, 9, 11, 21, 7, 15, 10};
static const unsigned int ids_graph_traversals[NB_SEED] = {0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 0, 0, 0, 1, 0, 1, 1};

#endif // SEEDS_H
