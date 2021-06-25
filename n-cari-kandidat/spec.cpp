#include <tcframe/spec.hpp>
#include <bits/stdc++.h>
using namespace tcframe;
using namespace std;
using ll = long long;

class ProblemSpec : public BaseProblemSpec {
protected:
    const int NMAX = 5e4;
    const int QMAX = 5e4;

    int N, Q;
    vector<int> A;
    vector<int> L, R, QL, QR;
    vector<int> ans;

    void InputFormat() {
        LINE(N);
        LINE(A % SIZE(N));
        LINE(Q);
        LINES(L, R, QL, QR) % SIZE(Q);
    }

    void OutputFormat() {
        LINES(ans) % SIZE(Q);
    }

    void GradingConfig() {
        TimeLimit(2);
        MemoryLimit(256);
    }

    void Constraints() {
        CONS(1 <= N && N <= NMAX);
        CONS(1 <= Q && Q <= QMAX);
        CONS(valid_pos(N, A, NMAX));
        CONS(valid_pos(Q, L, N));
        CONS(valid_pos(Q, R, N));
        CONS(valid_pos(Q, QL, N));
        CONS(valid_pos(Q, QR, N));
        CONS(valid_range(L, R));
        CONS(valid_range(QL, QR));
    }

private:
    bool valid_pos(int sz, const vector<int>& vec, int mx){
        if (sz != vec.size()) return 0;
        for (auto x : vec){
            if (x < 1 || x > mx) return 0;
        }
        return 1;
    }
    bool valid_range(const vector<int>& l, const vector<int>& r){
        if (l.size() != r.size()) return 0;
        int len = l.size();
        for (int i=0;i<len;i++){
            if (l[i] > r[i]) return 0;
        }
        return 1;
    }
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
    void SampleTestCase1() {
        Input({
            "8",
            "7 1 7 1 6 3 5 5",
            "5",
            "1 4 1 1",
            "3 8 2 2",
            "1 8 2 2",
            "1 8 1 1",
            "1 8 1 8"
        });
        Output({
            "0",
            "1",
            "3",
            "2",
            "5"
        });
    }
    void BeforeTestCase() {
        A.clear();
        L.clear();
        R.clear();
        QL.clear();
        QR.clear();
        ans.clear();
    }

    void TestCases() {
        for (int i=0;i<10;i++){   
            int mx = rnd.nextInt(1, 10);
            CASE(N = NMAX, Q = QMAX, make_random_query(N, Q, A, L, R, QL, QR, mx, rnd.nextInt(1, NMAX), rnd.nextInt(0, NMAX - mx)));
        }
        for (int i=0;i<3;i++){   
            int mx = rnd.nextInt(1, NMAX);
            CASE(N = NMAX, Q = QMAX, make_random_query(N, Q, A, L, R, QL, QR, mx, rnd.nextInt(1, 1000), rnd.nextInt(0, NMAX - mx)));
        }
        for (int i=0;i<3;i++){   
            int mx = rnd.nextInt(1, NMAX);
            CASE(N = NMAX, Q = QMAX, make_random_cornerseg(N, Q, A, L, R, QL, QR, mx, rnd.nextInt(1, 1000), rnd.nextInt(0, NMAX - mx)));
        }
        for (int i=0;i<5;i++){   
            int mx = rnd.nextInt(1, NMAX);
            CASE(N = NMAX, Q = QMAX, make_random_cornermos(N, Q, A, L, R, QL, QR, mx, rnd.nextInt(1, 1000), rnd.nextInt(0, NMAX - mx)));
        }
        for (int i=0;i<3;i++){   
            int mx = rnd.nextInt(1, NMAX / 100);
            CASE(N = NMAX, Q = QMAX, make_random_query(N, Q, A, L, R, QL, QR, mx, rnd.nextInt(1, 1000), rnd.nextInt(0, NMAX - mx)));
        }
        for (int i=0;i<3;i++){   
            int mx = rnd.nextInt(1, NMAX / 100);
            CASE(N = NMAX, Q = QMAX, make_random_cornerseg(N, Q, A, L, R, QL, QR, mx, rnd.nextInt(1, 1000), rnd.nextInt(0, NMAX - mx)));
        }
        for (int i=0;i<5;i++){   
            int mx = rnd.nextInt(1, NMAX / 100);
            CASE(N = NMAX, Q = QMAX, make_random_cornermos(N, Q, A, L, R, QL, QR, mx, rnd.nextInt(1, 1000), rnd.nextInt(0, NMAX - mx)));
        }
    }

private:
    void make_random_query(int n, int q, vector<int>& A, vector<int>& L, vector<int>& R, vector<int>& QL, vector<int>& QR, int MXA, int MXQ, int BASEA){
        for (int i=0;i<n;i++){
            A.push_back(BASEA + rnd.nextInt(1, MXA));
        }
        for (int i=0;i<q;i++){
            int a = rnd.nextInt(1, NMAX);
            int b = rnd.nextInt(1, NMAX);
            if (a > b) swap(a, b);
            L.push_back(a);
            R.push_back(b);
        }
        for (int i=0;i<q;i++){
            int mx = min(MXQ, R[i] - L[i] + 1);
            int a = rnd.nextInt(1, mx);
            int b = rnd.nextInt(1, mx);
            if (a > b) swap(a, b);
            QL.push_back(a);
            QR.push_back(b);
        }
    }
    void make_random_cornerseg(int n, int q, vector<int>& A, vector<int>& L, vector<int>& R, vector<int>& QL, vector<int>& QR, int MXA, int MXQ, int BASEA){
        for (int i=0;i<n;i++){
            A.push_back(BASEA + rnd.nextInt(1, MXA));
        }
        for (int i=0;i<q;i++){
            int a = rnd.nextInt(1, 10000);
            int b = rnd.nextInt(NMAX - 10000 + 1, NMAX);
            if (a > b) swap(a, b);
            L.push_back(a);
            R.push_back(b);
        }
        for (int i=0;i<q;i++){
            int mx = min(MXQ, R[i] - L[i] + 1);
            int a = rnd.nextInt(1, mx);
            int b = rnd.nextInt(1, mx);
            if (a > b) swap(a, b);
            QL.push_back(a);
            QR.push_back(b);
        }
    }
    void make_random_cornermos(int n, int q, vector<int>& A, vector<int>& L, vector<int>& R, vector<int>& QL, vector<int>& QR, int MXA, int MXQ, int BASEA){
        for (int i=0;i<n;i++){
            A.push_back(BASEA + rnd.nextInt(1, MXA));
        }
        int bsz = sqrt(n) + 1;
        for (int i=1;i<=q;i++){
            int posl = 1LL * i * n / q;
            if (i == 1 || ((posl - 1) / bsz) != ((L.back() - 1) / bsz)){
                if (!R.empty()) R.back() = n;
                R.push_back(posl);
            } else{
                R.push_back(max(posl, min(R.back() + rnd.nextInt(0, 2 * bsz), n)));
            }
            L.push_back(posl);
        }
        for (int i=0;i<q;i++){
            int mx = min(MXQ, R[i] - L[i] + 1);
            int a = rnd.nextInt(1, mx);
            int b = rnd.nextInt(1, mx);
            if (a > b) swap(a, b);
            QL.push_back(a);
            QR.push_back(b);
        }
    }
};