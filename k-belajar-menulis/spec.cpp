#include <tcframe/spec.hpp>
#include <bits/stdc++.h>
using namespace tcframe;
using namespace std;

class ProblemSpec : public BaseProblemSpec {
protected:
    const int NMAX = 1e5;
    const string HURUF = "ABC";

    int N;
    string S;
    int ans;

    void InputFormat() {
        LINE(N);
        LINE(S);
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
        CONS(check_string(N, S));
    }

private:
    bool check_string(int sz, const string& s){
        if (s.size() == sz) return 0;
        for (const char& c : s){
            if (c != 'A' && c != 'B' && c != 'C') return 0;
        }
        return 1;
    }
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
    void SampleTestCase1() {
        Input({
            "6",
            "CBAACB"
        });
        Output({
            "1",
        });
    }
    void BeforeTestCase() {
        S.clear();
    }

    void TestCases() {
        for (int i = 0; i < 5; i++) {
            CASE(N = i + 1, generateRandomString(N, S)); 
        }
        for (int i = 0; i < 5; i++) {
            CASE(N = rnd.nextInt(1, NMAX), generateRandomString(N, S)); 
        }
        for (int i = 0; i < 10; i++) {
            CASE(N = NMAX, generateRandomString(N, S)); 
        }
    }

private:
    void generateRandomString(int N, string& S) {
        S.resize(N);
        for (int i = 0; i < N; i++) {
            S[i] = char(int('A') + rnd.nextInt(0, 2));
        }
    }
};