#include <bits/stdc++.h>
#include <tcframe/spec.hpp>

using namespace std;
using namespace tcframe;
using ll = long long;

const int NMAX = 1e5;

class ProblemSpec : public BaseProblemSpec {
protected:
    int N, M;
    vector<int> U, V;
    vector<int> ans;

    void InputFormat() {
        LINE(N, M);
        LINES(U, V) % SIZE(M);
    }

    void OutputFormat() {
        LINE(ans % SIZE(N));
    }

    void GradingConfig() {
        TimeLimit(2);
        MemoryLimit(256);
    }

    void Constraints() {
        CONS(1 <= N && N <= NMAX);
        CONS(1 <= M && M <= NMAX);
        CONS(U.size() == M);
        CONS(V.size() == M);
        CONS(eachElementBetween(U, 1, N));
        CONS(eachElementBetween(V, 1, N));
    }

private:
    bool eachElementBetween(const vector<int>& v, int lo, int hi) {
        for (int x : v) {
            if (x < lo || x > hi) {
                return false;
            }
        }
        return true;
    }

    // bool noDoubleEdge(const vector<int> &u, const vector<int>& v) {
  	// 	int len = u.size();
  	// 	vector<set<int>> st(NMax + 5);
  	// 	for (int i = 0; i < len; i++) {
  	// 		if (st[u[i]].find(v[i]) != st[u[i]].end()) return false;
  	// 		st[u[i]].insert(v[i]);
  	// 	}
  	// 	return true;
    // }

    // bool noSelfLoop(const vector<int>& u, const vector<int>& v) {
    // 	int len = u.size();
    // 	for (int i = 0; i < len; i++) {
    // 		if (u[i] == v[i]) return false;
    // 	}
    // 	return true;
    // }
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
    void SampleTestCase1() {
    	Input({
            "5 4",
            "4 2",
            "1 4",
            "3 5",
            "1 3"
    	});
    	Output({
            "1 3 4 2 5"
    	});
    }
    void SampleTestCase2() {
    	Input({
            "3 2",
            "1 2",
            "1 3"
    	});
    	Output({
            "1 2 3"
    	});
    }
    void SampleTestCase3() {
    	Input({
            "5 5",
            "1 4",
            "3 4",
            "5 4",
            "3 2",
            "1 5"
    	});
    	Output({
            "1 4 3 2 5"
    	});
    }
    void SampleTestCase4() {
    	Input({
            "10 10",
            "1 4",
            "6 8",
            "2 5",
            "3 7",
            "9 4",
            "5 6",
            "3 4",
            "8 10",
            "8 9",
            "1 10"

    	});
    	Output({
            "1 4 3 7 9 8 6 5 2 10"
    	});
    }

    void BeforeTestCase() {
        U.clear();
        V.clear();
        ans.clear();
    }

    void TestCases() {
        for (int i=0;i<10;i++){
            CASE(N = rnd.nextInt(1, NMAX), M = rnd.nextInt(N - 1, NMAX), randomConGraph(N, M, U, V));
        }
        CASE(N = 300, randomCompleteGraph(N, M, U, V));
        for (int i=0;i<10;i++){
            CASE(N = NMAX, M = NMAX, randomConGraph(N, M, U, V));
        }
        for (int i=0;i<10;i++){
            CASE(N = NMAX, M = NMAX - 1, randomConGraph(N, M, U, V));
        }
    }

private:
    void renumber(int n, vector<int>& u, vector<int>& v) {
        vector<int> permutation;
        for (int i = 1; i <= n; i++) {
            permutation.push_back(i);
        }
        rnd.shuffle(permutation.begin(), permutation.end());
        for (int i = 0; i < (int) u.size(); i++) {
            u[i] = permutation[u[i] - 1];
            v[i] = permutation[v[i] - 1];
        }
    }
    void randomTree(int n, vector<int>& u, vector<int>& v) {
		for (int i = 1; i < n; i++) {
		    u.push_back(i + 1);
		    v.push_back(rnd.nextInt(1, i));
		}
		renumber(n, u, v);
	}
    void linearTree(int n, vector<int>& u, vector<int>& v) {
		for (int i = 2; i <= n; i++) {
		    u.push_back(i);
		    v.push_back(i - 1);
		}
		renumber(n, u, v);
	}
    void randomConGraph(int n, int m, vector<int>& u, vector<int>& v){
        randomTree(n, u, v);
        for (int i=0;i<m - (n - 1);i++){
            int a = rnd.nextInt(1, n);
            int b = rnd.nextInt(1, n);
            u.push_back(a);
            v.push_back(b);
        }
    }
    void randomCompleteGraph(int n, int& m, vector<int>& u, vector<int>& v){
        for (int i=1;i<=n;i++){
            for (int j=1;j<=n;j++){
                u.push_back(i);
                v.push_back(j);
            }
        }
        m = u.size();
    }
};