#include <bits/stdc++.h>
#include <tcframe/spec.hpp>

using namespace std;
using namespace tcframe;

const int NMAX = 1e6;
const int XMAX = 9;

class ProblemSpec : public BaseProblemSpec {
protected:
    int X, Y, N;
    int ans;

    void InputFormat() {
        LINE(X, Y, N);
    }

    void OutputFormat() {
        LINE(ans);
    }

    void GradingConfig() {
        TimeLimit(2);
        MemoryLimit(256);
    }

    void Constraints() {
        CONS(1 <= X && X <= XMAX);
        CONS(1 <= Y && Y <= XMAX);
        CONS(1 <= N && N <= NMAX);
    }
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
    void SampleTestCase1() {
        Input({
            "1 3 5"
        });
        Output({
            "15"
        });
    }

    void SampleTestCase2() {
        Input({
            "1 8 2"
        });
        Output({
            "0"
        });
    }

    void TestCases() {
        CASE(X = 1, Y = 3, N = 5);
        CASE(X = 1, Y = 8, N = 2);
        CASE(X = 3, Y = 4, N = 10);
        CASE(X = 3, Y = 4, N = 20);
        CASE(X = 3, Y = 4, N = 30);
        CASE(X = 3, Y = 4, N = 50);
        CASE(X = 3, Y = 4, N = 100);
        CASE(X = 9, Y = 8, N = 500);
        CASE(X = 9, Y = 8, N = 600);
        CASE(X = 9, Y = 8, N = 700);
        CASE(X = 9, Y = 8, N = 800);
        CASE(X = 9, Y = 8, N = 900);
        CASE(X = 9, Y = 8, N = 1000);
        for (int i = 0; i < 5; i++) {
            CASE(X = rnd.nextInt(1, 9), Y = rnd.nextInt(1, 9), N = 10000);
        }
        for (int i = 0; i < 5; i++) {
            CASE(X = rnd.nextInt(1, 9), Y = rnd.nextInt(1, 9), N = 20000);
        }
        CASE(X = 6, Y = 9, N = 1000000);
        for (int i = 0; i < 5; i++) {
            CASE(X = rnd.nextInt(1, 9), Y = rnd.nextInt(1, 9), N = 50000);
        }
        for (int i = 0; i < 5; i++) {
            CASE(X = rnd.nextInt(1, 9), Y = rnd.nextInt(1, 9), N = 100000);
        }
        for (int i = 0; i < 5; i++) {
            CASE(X = rnd.nextInt(1, 9), Y = rnd.nextInt(1, 9), N = 500000);
        }
        for (int i = 0; i < 10; i++) {
            CASE(X = rnd.nextInt(1, 9), Y = rnd.nextInt(1, 9), N = 1000000);
        }
    }
};