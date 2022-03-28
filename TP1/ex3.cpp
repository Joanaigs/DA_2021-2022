// By: Gonçalo Leão

#include "exercises.h"
#include <vector>;
using namespace std;

bool changeMakingBF(unsigned int C[], unsigned int Stock[], unsigned int n, unsigned int T, unsigned int usedCoins[]) {

    for (int i = 0; i < n; i++) {
        if (C[i] > T || Stock[i] == 0) return false;
        else {
            T -= C[i];
            Stock[i]--;
            if (T == 0) {
                usedCoins[i]++;
                Stock[i]--;
                break;
            } else if (!changeMakingBF(C, Stock, n, T, usedCoins)) {
                Stock[i]++;
                T += C[i];
            } else {
                usedCoins[i]++;
                return true;
            }
        }
    }
}

/// TESTS ///
#include <gtest/gtest.h>

TEST(TP1_Ex3, hasBFChangeCanonical) {
    unsigned int C[] = {1,2,5,10};
    unsigned int Stock[] = {1,1,1,1};
    unsigned int n = 4;
    unsigned int usedCoins[4]={0};

    EXPECT_EQ(changeMakingBF(C,Stock,n,13,usedCoins), true);
    EXPECT_EQ(usedCoins[0], 1);
    EXPECT_EQ(usedCoins[1], 1);
    EXPECT_EQ(usedCoins[2], 0);
    EXPECT_EQ(usedCoins[3], 1);

    for (int i = 0; i < n; i++) {
        usedCoins[i] = 0;
    }

    unsigned int Stock2[] = {1,2,4,2};
    EXPECT_EQ(changeMakingBF(C,Stock2,n,38,usedCoins), true);
    EXPECT_EQ(usedCoins[0], 1);
    EXPECT_EQ(usedCoins[1], 1);
    EXPECT_EQ(usedCoins[2], 3);
    EXPECT_EQ(usedCoins[3], 2);
}

TEST(TP1_Ex3, hasBFChangeNonCanonical) {
    unsigned int C[] = {1,4,5};
    unsigned int Stock[] = {2,2,1};
    unsigned int n = 3;
    unsigned int usedCoins[3]={0};

    EXPECT_EQ(changeMakingBF(C,Stock,n,6,usedCoins), true);
    EXPECT_EQ(usedCoins[0], 1);
    EXPECT_EQ(usedCoins[1], 0);
    EXPECT_EQ(usedCoins[2], 1);

    for (int i = 0; i < n; i++) {
        usedCoins[i] = 0;
    }
    EXPECT_EQ(changeMakingBF(C,Stock,n,8,usedCoins), true);
    EXPECT_EQ(usedCoins[0], 0);
    EXPECT_EQ(usedCoins[1], 2);
    EXPECT_EQ(usedCoins[2], 0);
}

TEST(TP1_Ex3, hasNoBFChange) {
    unsigned int C[] = {1,2,5,10};
    unsigned int Stock[] = {0,1,1,1};
    unsigned int n = 4;
    unsigned int usedCoins[4]={0};

    EXPECT_EQ(changeMakingBF(C,Stock,n,18,usedCoins), false);
    EXPECT_EQ(changeMakingBF(C,Stock,n,1,usedCoins), false);
}