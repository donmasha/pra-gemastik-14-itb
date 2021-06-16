#include <tcframe/spec.hpp>
#include <bits/stdc++.h>
using namespace tcframe;
using namespace std;

class ProblemSpec : public BaseProblemSpec {
protected:
    const int NMAX = 1e5;
    const long long AMAX = 1e18;

    int N;
    vector<long long> A, B;
    vector<long long> ans;

    void InputFormat() {
        LINE(N);
        LINES(A, B) % SIZE(N);
    }

    void OutputFormat() {
        LINES(ans) % SIZE(N);
    }

    void GradingConfig() {
        TimeLimit(1);
        MemoryLimit(128);
    }

    void Constraints() {
        CONS(1 <= N && N <= NMAX);
        CONS(CheckConstraint(A, 1, AMAX));
        CONS(CheckConstraint(B, 1, AMAX));
    }

private:
    bool CheckConstraint(vector<long long>& v, long long low, long long high) {
        for (auto x : v) {
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
            "5",
            "7 5",
            "8 4",
            "2 3",
            "5 3",
            "13518012 16518012"
        });
        Output({
            "2",
            "0",
            "1",
            "1",
            "3000000"
        });
    }
    void BeforeTestCase() {
        A.clear(); B.clear();
        ans.clear();
    }

    void TestCases() {
        for (int i = 0; i < 5; i++) {
            CASE(N = NMAX, generateRandomArray(N, A, 1, AMAX), generateRandomArray(N, B, 1, AMAX));
        }
    }

private:
    void generateRandomArray(int N, vector<long long>& A, long long low, long long high) {
        A.resize(N);
        for (int i = 0; i < N; i++) {
            A[i] = rnd.nextLongLong(low, high);
        }
    }
};