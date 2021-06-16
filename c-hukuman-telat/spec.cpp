#include <tcframe/spec.hpp>
#include <bits/stdc++.h>
using namespace tcframe;
using namespace std;

class ProblemSpec : public BaseProblemSpec {
protected:
    const int NMAX = 1e5;
    const int PMAX = 1e9;
    const int QMAX = 1e5;
    const int XMAX = 1e9;

    int P, N;
    vector<int> A;
    int Q;
    vector<int> X;
    vector<int> ans;

    void InputFormat() {
        LINE(P, N);
        LINE(A);
        LINE(Q);
        LINES(X) % SIZE(Q);
    }

    void OutputFormat() {
        LINES(ans) % SIZE(Q);
    }

    void GradingConfig() {
        TimeLimit(2);
        MemoryLimit(128);
    }

    void Constraints() {
        CONS(1 <= P && P <= PMAX);
        CONS(1 <= N && N <= NMAX);
        CONS(CheckConstraint(A, 1, PMAX));
        CONS(CheckConstraint(X, 0, XMAX));
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
            "4 6",
            "4 2 1 2 1 2",
            "5",
            "0",
            "1",
            "2",
            "3",
            "4"
        });
        Output({
            "0",
            "0",
            "1",
            "1",
            "1"
        });
    }

    void BeforeTestCase() {
        A.clear();
        X.clear();
        ans.clear();
    }

    void TestCases() {
        for (int i = 0; i < 5; i++) {
            CASE(P = rnd.nextInt(10, 100),
                 N = rnd.nextInt(P, 1000),
                 generateRandomArray(N, A, 1, P),
                 Q = rnd.nextInt(10, 100),
                 generateRandomXFromA(N, A, Q, X));
        }
        for (int i = 0; i < 5; i++) {
            CASE(P = rnd.nextInt(100, 1000),
                 N = rnd.nextInt(P, 1000),
                 generateRandomArray(N, A, 1, P),
                 Q = rnd.nextInt(100, 1000),
                 generateRandomXFromA(N, A, Q, X));
        }
        CASE(P = rnd.nextInt(100, 1000),
                N = rnd.nextInt(P, 1000),
                generateRandomArray(N, A, 100, P),
                Q = rnd.nextInt(100, 1000),
                generateRandomArray(Q, X, 0, 0));
        CASE(P = rnd.nextInt(100, 1000),
                N = rnd.nextInt(P, 1000),
                generateRandomArray(N, A, 1, P),
                Q = rnd.nextInt(100, 1000),
                generateRandomArray(Q, X, P, P + 1));
        for (int i = 0; i < 5; i++) {
            CASE(P = PMAX,
                 N = NMAX,
                 generateRandomArray(N, A, 1, P),
                 Q = QMAX,
                 generateRandomXFromA(N, A, Q, X));
        }
        for (int i = 0; i < 5; i++) {
            CASE(P = NMAX / 100,
                 N = NMAX,
                 generateRandomArray(N, A, 1, P),
                 Q = QMAX,
                 generateRandomXFromA(N, A, Q, X));
        }
        for (int i = 0; i < 5; i++) {
            CASE(P = NMAX / 100,
                 N = NMAX,
                 generateRandomArray(N, A, 1, P),
                 Q = QMAX,
                 generateRandomArray(Q, X, 0, P));
        }
    }

private:
    void generateRandomArray(int N, vector<int>& A, int low, int high) {
        A.resize(N);
        for (int i = 0; i < N; i++) {
            A[i] = rnd.nextInt(low, high);
        }
    }

    void generateRandomXFromA(int N, vector<int>& A, int Q, vector<int>& X) {
        X.resize(Q);
        for (int i = 0; i < Q; i++) {
            X[i] = A[rnd.nextInt(0, N - 1)];
        }
    }
};