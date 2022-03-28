// By: Gonçalo Leão

#include "exercises.h"

int maxSubsequence(int A[], unsigned int n, unsigned int &i, unsigned int &j) {
    int maxSum=0;
    for(int k=0; k<n; k++){
        int sum=0;
        for(int l=k; l<n; l++){
            sum+= A[l];
            if(sum>maxSum) {
                maxSum = sum;
                i=k;
                j=l;
            }
        }
    }
    return maxSum;
}


/// TESTS ///
#include <gtest/gtest.h>

TEST(TP1_Ex2, maxSubsequence) {
    int A[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    unsigned int n = 9;
    unsigned int i, j;
    EXPECT_EQ(maxSubsequence(A,n,i,j), 6);
    EXPECT_EQ(i, 3);
    EXPECT_EQ(j, 6);
}