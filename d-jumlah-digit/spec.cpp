#include <tcframe/spec.hpp>
#include <bits/stdc++.h>
using namespace tcframe;
using namespace std;

mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());

class ProblemSpec : public BaseProblemSpec {
protected:
    const long long BMAX = 1e18;
    const long long DMAX = 19;

    long long L, R;
    long long P, Q;
    int ans;

    void InputFormat() {
        LINE(L, R);
        LINE(P, Q);
    }

    void OutputFormat() {
        LINE(ans);
    }

    void GradingConfig() {
        TimeLimit(2);
        MemoryLimit(512);
    }

    void Constraints() {
        CONS(1 <= L && L <= R && R <= BMAX);
        CONS(1 <= P && P <= Q && Q <= DMAX);
    }
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
    void SampleTestCase1() {
        Input({
            "10 50",
            "1 1"
        });
        Output({
            "20",
        });
    }

    void SampleTestCase2() {
        Input({
            "1 10",
            "1 2"
        });
        Output({
            "46",
        });
    }

    void SampleTestCase3() {
        Input({
            "13518012 16518012",
            "1 2"
        });
        Output({
            "3632",
        });
    }

    void BeforeTestCase() {
        // do nothing
    }

    void TestCases() {
        for (int i = 0; i < 50; i++) {
            CASE(generateLeftRight(L, R, 1, BMAX), generateLeftRight(P, Q, 1, DMAX));
        }
    }

private:
    void generateLeftRight(long long& X, long long& Y, long long low, long long high) {
        long long A = low + rng32() % (high - low + 1);
        long long B = low + rng32() % (high - low + 1);
        if (A > B) swap(A, B);
        X = A, Y = B;
    }
};