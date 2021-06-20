#include <bits/stdc++.h>
#include <tcframe/spec.hpp>

using namespace std;
using namespace tcframe;

const int AMAX = 1e9;
const int NMAX = 1e5;

class ProblemSpec : public BaseProblemSpec {
protected:
    int N, ans;
    vector<int> A;

    void InputFormat() {
        LINE(N);
        LINE(A % SIZE(N));
    }

    void OutputFormat() {
        LINE(ans);
    }

    void GradingConfig() {
        TimeLimit(1);
        MemoryLimit(256);
    }

    void Constraints() {
        CONS(2 <= N && N <= NMAX);
        CONS(eachElementBetween(A, 1, AMAX));
    }

private:
    bool eachElementBetween(const vector<int>& ve, int lo, int hi) {
        for (auto& e : ve) {
            if (e < lo || e > hi) return false;
        }
        return true;
    }
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
    void SampleTestCase1() {
        Input({
            "3",
            "2 1 1"
        });
        Output({
            "1"
        });
    }

    void SampleTestCase2() {
        Input({
            "15",
            "3 2 1 3 5 4 5 5 4 1 3 3 2 3 1"
        });
        Output({
            "5"
        });
    }

    void BeforeTestCase() {
        A.clear();
    }

    void TestCases() {
        CASE(N = 2, A = {1, 1});
        CASE(N = 3, A = {1000, 1001, 1000});
        CASE(N = 6, A = {1, 2, 3, 4, 5, 1});
        CASE(N = 10, A = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1});
        for (int i = 0; i < 5; i++) {
            CASE(N = rnd.nextInt(5, 20), randomArrayWithTwoMin(1000));
        }
        for (int i = 0; i < 5; i++) {
            CASE(N = rnd.nextInt(100, 1000), randomArrayWithTwoMin(1000000));
        }
        for (int i = 0; i < 5; i++) {
            CASE(N = rnd.nextInt(3, 5), randomArrayWithTwoMin(135182));
        }
        for (int i = 0; i < 20; i++) {
            CASE(N = rnd.nextInt(10000, 50000), randomArrayWithTwoMin(69));
        }
        for (int i = 0; i < 20; i++) {
            CASE(N = rnd.nextInt(50000, 100000), randomArrayWithTwoMin(999999999));
        }
        for (int i = 0; i < 10; i++) {
            CASE(N = NMAX, randomArrayWithTwoMin(500001));
        }
    }

private:
    void randomArrayWithTwoMin(int mn) {
        int choose = rnd.nextInt(2, 1000);
        if (choose > N) choose = N;
        for (int i = 0; i < choose; i++) {
            A.push_back(mn);
        }
        for (int i = choose; i < N; i++) {
            int x = rnd.nextInt(mn + 1, AMAX);
            A.push_back(x);
        }
        rnd.shuffle(A.begin(), A.end());
    }
};