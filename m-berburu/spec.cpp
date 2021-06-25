#include <tcframe/spec.hpp>
#include <bits/stdc++.h>
using namespace tcframe;
using namespace std;
using ll = long long;

class ProblemSpec : public BaseProblemSpec {
protected:
    const int NMAX = 2e5;
    const int CMAX = 1e9;

    int N;
    vector<int> C, A;
    ll ans;

    void InputFormat() {
        LINE(N);
        LINE(C % SIZE(N));
        LINE(A % SIZE(N));
    }

    void OutputFormat() {
        LINE(ans);
    }

    void GradingConfig() {
        TimeLimit(1);
        MemoryLimit(128);
    }

    void Constraints() {
        CONS(1 <= N && N <= NMAX);
        CONS(valid_pos(N, C, CMAX));
        CONS(valid_pos(N, A, N));
    }

private:
    bool valid_pos(int sz, const vector<int>& vec, int mx){
        if (sz != vec.size()) return 0;
        for (auto x : vec){
            if (x < 1 || x > mx) return 0;
        }
        return 1;
    }
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
    void SampleTestCase1() {
        Input({
            "5",
            "2 2 2 2 2",
            "1 1 1 1 1"
        });
        Output({
            "2"
        });
    }
    void SampleTestCase2() {
        Input({
            "5",
            "1 2 3 2 10",
            "1 3 4 3 3"
        });
        Output({
            "3"
        });
    }
    void SampleTestCase3() {
        Input({
            "4",
            "1 10 2 10",
            "2 4 2 2"
        });
        Output({
            "10"
        });
    }
    void SampleTestCase4() {
        Input({
            "7",
            "1 1 1 1 1 1 1",
            "2 2 2 3 6 7 6"
        });
        Output({
            "2"
        });
    }
    void BeforeTestCase() {
        C.clear();
        A.clear();
    }

    void TestCases() {
        for (int i = 0; i < 1; i++) {
            CASE(N = 1, make_random_query(N, C, A)); 
        }
        for (int i = 0; i < 3; i++) {
            CASE(N = rnd.nextInt(1, NMAX), make_random_query(N, C, A, rnd.nextInt(1, 5))); 
        }
        for (int i = 0; i < 5; i++) {
            CASE(N = NMAX, make_random_query(N, C, A, rnd.nextInt(1, 5), 1e9, 1e9)); 
        }
        for (int i = 0; i < 10; i++) {
            CASE(N = NMAX, make_random_query(N, C, A, rnd.nextInt(1, 5), 1e9)); 
        }
        for (int i = 0; i < 10; i++) {
            CASE(N = NMAX, make_random_query(N, C, A, rnd.nextInt(1, 5), 1e9, 1e8)); 
        }
    }

private:
    void make_random_query(int n, vector<int>& c, vector<int>& a, int loop_chance = 1, int mxc = 1e9, int mnc = 1){
        for (int i=0;i<n;i++){
            c.push_back(rnd.nextInt(mnc, mxc));
        }
        for (int i=0;i<n;i++){
            int id = i + 1;
            int chance = rnd.nextInt(1, 10);
            if (chance <= loop_chance) a.push_back(id);
            else a.push_back(rnd.nextInt(1, n));
        }
    }
};