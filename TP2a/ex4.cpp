#include "exercises.h"
#include <algorithm>;

using namespace std;

bool Activity::operator==(const Activity &a2) const {
    return start == a2.start && finish == a2.finish;
}

bool Activity::overlaps(const Activity &a2) const {
    return (start < a2.finish) && (a2.start < finish);
}

bool cmp(Activity a1, Activity a2){
    return a1.finish<a2.finish;
}

bool helper(std::vector<Activity> &A, std::vector<Activity> &Result){
    if(A.empty())
        return true;
    Activity temp=A[0];
    if(Result.empty())
        Result.push_back(temp);
    else if(!temp.overlaps(Result[Result.size()-1]))
        Result.push_back(temp);
    A.erase(A.begin());
    return helper(A, Result);
}

std::vector<Activity> activitySelectionBacktracking(std::vector<Activity> A) {
    sort(A.begin(), A.end(), cmp);
    std::vector<Activity> Result;
    helper(A, Result);
    return Result;
}

/// TESTS ///
#include <gtest/gtest.h>
#include <gmock/gmock.h>

bool noOverlaps(const std::vector<Activity> &acts) {
    for(unsigned int i = 0; i < acts.size(); i++) {
        Activity A1 = acts.at(i);
        for(unsigned int j = i + 1; j < acts.size(); j++) {
            Activity A2 = acts.at(j);
            if(A1.overlaps(A2)) return false;
        }
    }
    return true;
}

TEST(TP2_Ex4, activityScheduling) {
    std::vector<Activity> A = {{10,20}, {30, 35}, {5, 15}, {10, 40}, {40, 50}};
    std::vector<Activity> V = activitySelectionBacktracking(A);
    EXPECT_EQ(V.size(), 3 );
    EXPECT_EQ(noOverlaps(V), true);
}