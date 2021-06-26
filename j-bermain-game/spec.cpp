#include <tcframe/spec.hpp>
#include <bits/stdc++.h>
using namespace tcframe;
using namespace std;

const int TMAX = 1e4;
const long long LMAX = 1e18;

class ProblemSpec : public BaseProblemSpec {
protected:
    int TC;
    vector<long long> L, R, ans;

    void InputFormat() {
        LINE(TC);
        LINES(L, R) % SIZE(TC);
    }

    void OutputFormat() {
        LINES(ans) % SIZE(TC);
    }

    void GradingConfig() {
        TimeLimit(2);
        MemoryLimit(128);
    }

    void Constraints() {
        CONS(1 <= TC && TC <= TMAX);
        CONS(CheckConstraint1(L, 2LL, LMAX));
        CONS(CheckConstraint1(R, 2LL, LMAX));
        CONS(CheckConstraint2(L, R));
    }

private:
    bool CheckConstraint1(vector<long long>& v, long long low, long long high) {
        for (long long x : v) {
            if (x < low || x > high) {
                return false;
            }
        }
        return true;
    }

    bool CheckConstraint2(vector<long long>& v1, vector<long long>& v2) {
        int n = (int) v1.size();
        for (int i = 0; i < n; i++) {
            if (v1[i] > v2[i]) {
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
            "2",
            "2 3",
            "3 5"
        });
        Output({
            "1",
            "0"
        });
    }
    void BeforeTestCase() {
        L.clear();
        R.clear();
    }

    void TestCases() {
        CASE(TC = 10, L = {999999999999999999LL, 3, 4, 5, 6, 7, 69, 9, 10, 2684354560}, R = {1000000000000000000LL, 4, 5, 6, 7, 8, 100, 10, 2021, 2684354561});
        CASE(TC = 10, L = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2}, R = {2, 3, 4, 1000000, 1000000000, 1000000000000, 69, 1000000000000000, 1000000000000000000, 999999999999999999});
        for (int i = 0; i < 5; i++) {
            CASE(TC = TMAX, generateTestCases(TC, L, R, 2, LMAX));
        }
    }

private:
    void generateTestCases(int N, vector<long long>& A, vector<long long>& B, long long low, long long high) {
        A.resize(N);
        B.resize(N);
        for (int i = 0; i < N; i++) {
            long long u = rnd.nextLongLong(low, high);
            long long v = rnd.nextLongLong(low, high);
            if (u > v) swap(u, v);
            A[i] = u;
            B[i] = v;
        }
    }
};