#include <tcframe/spec.hpp>
#include <bits/stdc++.h>
using namespace tcframe;
using namespace std;

const int TMAX = 3e5;
const int NMAX = 1e5;

class ProblemSpec : public BaseProblemSpec {
protected:
    int N;
    vector<int> X, Y;
    string ans;

    void InputFormat() {
        LINE(N);
        LINE(X % SIZE(N));
        LINE(Y % SIZE(N));
    }

    void OutputFormat() {
        LINE(ans);
    }

    void GradingConfig() {
        TimeLimit(2);
        MemoryLimit(256);
    }

    void Constraints() {
        CONS(CheckConstraint(X, 1, N));
        CONS(CheckConstraint(Y, 1, N));
    }

private:
    bool CheckConstraint(vector<int>& v, int low, int high) {
        for (int x : v) {
            if (x < low || x > high) {
                return false;
            }
        }
        return true;
    }
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
    void SampleTestCase1() {
        Input({
            "8",
            "2 3 4 5 6 5 1 4",
            "1 2 3 4 5 6 5 4"
        });
        Output({
            "Sabi"
        });
    }
    void BeforeTestCase() {
        X.clear();
        Y.clear();
    }

    void TestCases() {
        for (int i = 0; i < 30; i++) {
            CASE(N = NMAX, generateTestCases(X, Y, 1, N));
        }
        for (int i = 0; i < 5; i++) {
            CASE(N = 100, generateTestCases(X, Y, 1, N));
            CASE(N = 500, generateTestCases(X, Y, 1, N));
            CASE(N = 1000, generateTestCases(X, Y, 1, N));
            CASE(N = 10000, generateTestCases(X, Y, 1, N));
            CASE(N = 50000, generateTestCases(X, Y, 1, N));
        }
        CASE(N = 7, X = {1, 7, 1, 4, 4, 5, 6}, Y = {1, 1, 4, 4, 5, 7, 6});
        CASE(N = 2, X = {1, 1}, Y = {1, 2});
        CASE(N = 5, X = {1, 1, 3, 3, 5}, Y = {1, 1, 3, 3, 5});
        CASE(N = 3, X = {1, 2, 3}, Y = {3, 2, 1});
        CASE(N = 10, X = {7, 7, 1, 1, 6, 4, 8, 10, 5, 3}, Y = {3, 7, 5, 6, 10, 1, 4, 7, 8, 1});
        CASE(N = 10, X = {10, 9, 6, 1, 8, 6, 6, 4, 1, 5}, Y = {6, 1, 10, 6, 4, 9, 6, 8, 1, 5});
        CASE(N = 10, X = {6, 2, 2, 9, 3, 2, 10, 6, 7, 1}, Y = {2, 3, 10, 2, 2, 6, 6, 1, 7, 9});
        CASE(N = 5, X = {1, 3, 3, 5, 1}, Y = {1, 1, 3, 5, 3});
    }

private:
    void generateTestCases(vector<int>& A, vector<int>& B, int low, int high) {
        A.resize(high);
        for (int i = 0; i < high; i++) {
            A[i] = rnd.nextInt(low, high);
        }
        B = A;
        rnd.shuffle(B.begin(), B.end());
    }
};