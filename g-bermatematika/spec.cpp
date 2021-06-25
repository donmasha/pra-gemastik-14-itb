#include <bits/stdc++.h>
#include <tcframe/spec.hpp>

using namespace std;
using namespace tcframe;

const int MAX = 1e9;

class ProblemSpec : public BaseProblemSpec {
protected:
    int X, Y, N;
    int ans;

    void InputFormat() {
        LINE(X, Y);
    }

    void OutputFormat() {
        LINE(ans);
    }

    void GradingConfig() {
        TimeLimit(1);
        MemoryLimit(256);
    }

    void Constraints() {
        CONS(1 <= X && X <= MAX);
        CONS(1 <= Y && Y <= MAX);
    }
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
    void SampleTestCase1() {
        Input({
            "6 10"
        });
        Output({
            "2"
        });
    }

    void TestCases() {
        CASE(X = 6, Y = 30);
        CASE(X = 1, Y = 1);
        CASE(X = 2, Y = 2);
        CASE(X = 2, Y = 10);
        CASE(X = 2, Y = 130);

        CASE(X = 10, Y = 17);
        CASE(X = 21, Y = 31);
        CASE(X = 5, Y = 10);
        CASE(X = 1924, Y = 5834);
        CASE(X = 9911, Y = 666013);

        CASE(X = 69, Y = 4295);
        CASE(X = 948248258, Y = 533435433);
        CASE(X = 953, Y = 1349);
        CASE(X = 999999973, Y = 800000007);
        CASE(X = 112342324, Y = 524224233);

        CASE(X = 1021211, Y = 59555555);
        CASE(X = 1000000000, Y = 1000000000);
        CASE(X = 199999943, Y = 999999973);
        CASE(X = 2, Y = 999999973);
        CASE(X = 199999973, Y = 99999937);

        CASE(X = 851187514, Y = 983401693);
        CASE(X = 414459569, Y = 161124945);
        CASE(X = 588854730, Y = 468415815);
        CASE(X = 573707893, Y = 93108818);
        CASE(X = 21184942, Y = 66889);

        CASE(X = 69, Y = 420);

        for (int i = 0; i < 50; i++) {
            CASE(X = rnd.nextInt(100000000, 900000000), Y = rnd.nextInt(100000000, 900000000));
        }
    }
};