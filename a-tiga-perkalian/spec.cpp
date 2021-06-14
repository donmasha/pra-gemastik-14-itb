#include <tcframe/spec.hpp>
#include <bits/stdc++.h>
using namespace tcframe;
using namespace std;

class ProblemSpec : public BaseProblemSpec {
protected:
    const int NMAX = 1e5;
    const int AMAX = 1e6;

    int N;
    vector<int> A;
    vector<long long> ans;

    void InputFormat() {
        LINE(N);
        LINE(A);
    }

    void OutputFormat() {
        LINE(ans);
    }

    void GradingConfig() {
        TimeLimit(1);
        MemoryLimit(64);
    }

    void Constraints() {
        CONS(1 <= N && N <= NMAX);
        CONS(CheckConstraint(A, -AMAX, AMAX));
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
            "6",
            "-4 9 10 13 -9 2"
        });
        Output({
            "1170 -1170",
        });
    }
    void BeforeTestCase() {
        A.clear();
        ans.clear();
    }

    void TestCases() {
        for (int i = 0; i < 5; i++) {
            CASE(N = rnd.nextInt(1, NMAX / 100), generateTestCases(N, A, -AMAX / 100000, AMAX / 100000));
        }
        for (int i = 0; i < 5; i++) {
            CASE(N = rnd.nextInt(NMAX / 100, NMAX / 10), generateTestCases(N, A, -AMAX / 1000, AMAX / 1000));
        }
        for (int i = 0; i < 15; i++) {
            CASE(N = rnd.nextInt(1, NMAX), generateTestCases(N, A, -AMAX, AMAX));
        }
        for (int i = 0; i < 5; i++) {
            CASE(N = NMAX, generateTestCases(N, A, -AMAX, AMAX));
        }
        CASE(N = NMAX, generateTestCases(N, A, -AMAX, -AMAX));
    }

private:
    void generateTestCases(int N, vector<int>& A, int low, int high) {
        A.resize(N);
        for (int i = 0; i < N; i++) {
            A[i] = rnd.nextInt(low, high);
        }
    }
};