#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

//Stone Wall
int StoneSolution(vector<int> &H) {
	int count = 0;
	vector<int> wall;
	wall.push_back(0);
	for (int h : H)
	{
		while (wall.back()>h)
			wall.pop_back();

		if (wall.back()<h) { 
			 wall.push_back(h); 
			 count++; 
			 } 
		
	}  
	return  count; 
} 

//sort
void sortTest() {
	vector<int> v = { 1,5,2,6,5,4,3,2,0 };
    sort(v.begin(), v.end() );
	for (int i = 0; i < v.size(); ++i) {
		cout << "\n elem is " << v[i];
	}
	cin.get();

	int t[5] = { 5,2,6,3,4 };
	
}

int MaxProductOfThree(vector<int> v) {
	sort(v.begin(), v.end());
	int end = v[v.size() - 1] * v[v.size() - 2] * v[v.size() - 3];
	int beg = v[0] * v[1] * v[v.size() - 1];
	return max(end, beg);
}

int MaxProductOfThree2(vector<int> v) {
	sort(v.begin(), v.end());
	vector<int>::iterator it = v.end();
	int lst1 = *(it - 1);
	int lst2 = *(it-2);
	int lst3 = *(it-3);

	int beg = v[0] * v[1] * lst1;
	int end = lst1*lst2*lst3;
		
	return max(end, beg);
}


void testMax() {
	vector<int> h = { -8,-8,5,7,9,8,7,4,8, 10 };
	int res = MaxProductOfThree2(h);
	cout << "max is " << res;
	cin.get();

}



void testStone() {
	vector<int> h = { 8,8,5,7,9,8,7,4,8 };

}

//greatest common divisor
int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

void testGcd() {
	int a = 27;
	int b = 18;
	int gcd_t = gcd(a, b);
	cout << "gcd is " << gcd_t;
	cin.get();
}

/*
int sqrt_helper(int n, int min, int max);
//square root
int sqrt(int n) { 
	return sqrt_helper(n, 1, n); 
};

int sqrt_helper(int n, int min, int max) { 
	if (max < min) return -1; 
	int guess = (min + max) / 2; 
	if (guess *guess == n) { 
		return guess; 
	}
	else if (guess * guess < n) { 
		return sqrt_helper(n, guess + 1, max); 
		}
	else { 
		return sqrt_helper(n, min, guess - 1); 
	}
};
*/

//equilibrium of index
int indexEquilibrium(vector<int> v) {
	// return 3 for [3,2,-5,1]
	int sum_prefix = 0;
	int sum_suffix = 0;
	int N = v.size();
	//int i, j;
	for (int i = 0; i < N; i++) {
		// Check if is is the equilibrium point
		sum_prefix = 0;
		for (int j = 0; j < i; j++) {
			sum_prefix += v[j];
		}
		sum_suffix = 0;
		for (int j = i + 1; j < N; j++) {
			sum_suffix += v[j];
			// Compute suffix sum
		}
		if (sum_prefix == sum_suffix)
			return i;
	}
	return -1;
}



void testIndex() {
	vector<int > vt= {3,2,-5,1};
	int res = indexEquilibrium(vt);
	cout << "eq is " << res;
	cin.get();
}

///*
//Dominator
int dominator(vector<int> v) {
	//if only 1 element return 0
	if (v.size() == 1) return 0;


	map<int, int> mymap;
	int mid = v.size() / 2;

	for (int i = 0; i < v.size(); ++i) {
		//check if element exists
		if (mymap.count(v[i]) == 0) {
			mymap.insert(pair<int, int> (v[i], 1));
		}
		else {
			mymap[v[i]]= mymap[v[i]]+1;
			if (mymap[v[i]] > mid) return i; //change to i for pos
		}
	}
	//check the middle size of vector
	
	//get all unique elements
	//vector<int> keys;
	
	return -1;//change to -1
}

//test dominator

void testDominator() {
	vector<int> vt = { 3,4,3, 2,3,-1, 3,3 };
	vector<int> vs = { 1 };
	int res = dominator(vs);
	cout << "dominator is " << res;
	cin.get();
}
//*/

int eqLeader(vector<int> v) {
//#define max 1000000001

	int N = v.size();
	int cnter = 0;
	for (int i = 0; i < N; ++i) {
		vector<int> lhs;
		vector<int> rhs;
		
		//create two temp vectors
		for (int j = 0; j < i + 1; ++j) {
			lhs.push_back(v[j]);
		}
		for (int k = i + 1; k < N; ++k) {
			rhs.push_back(v[k]);
		}
		int eq1 = dominator(lhs);
		int eq2 = dominator(rhs);
		if (eq1 >= 0 && eq2 >= 0) {
			if (lhs[eq1] == rhs[eq2]) {
				cnter++;
			}
		}
	}
	return cnter;
}

void testeqLeader() {
	vector<int> vt = {4,3,4,4,4,2};
	int res = eqLeader(vt);
	cout << "eq leader " << res;
	cin.get();
}

//faster Eq Leader
int solution(vector<int> &A) {
	vector<int> B;
	for (int i = 0; i < (int)A.size(); i++) {
		if (!B.empty() && A[i] != A[B.back()])
			B.pop_back();
		else
			B.push_back(i);
	}

	if (B.empty()) return 0;

	int count = 0;
	for (int a : A) {
		if (a == A[B.back()])
			count++;
	}
	if (count <= (int)A.size() / 2)
		return 0;

	int leader = A[B.back()];
	int n = A.size();
	int countEqui = 0;
	int countLeaders = 0;

	for (int i = 0; i<n; i++) { 
		if (A[i] = leader) countLeaders++; 
		if (count - countLeaders >(n - i - 1) / 2 && countLeaders>(i + 1) / 2)
		countEqui++;
	}
	return countEqui;
}

int JavaEqLeader(vector<int> &A) {
	int leader ;
	int countofLeader = 0;

	vector<int> B;
	//push each elem and compare to next
	for (int i = 0; i < (int)A.size(); i++) {
		if (B.empty() || A[i] == B.back())
			B.push_back(A[i]);
		else
			B.pop_back();
	}
	cout << "B is " << B.back(); cin.get();
	if (!B.empty()) {
		int candidate = B.back();
		for (int i = 0; i < (int)A.size(); ++i) {
			if (A[i] == candidate) {
				countofLeader++;
			}
		}
		cout << "count leader is " << countofLeader; cin.get();
		if (countofLeader > (int)A.size() / 2) {
			leader = candidate;
		}
		else return 0; //no leader
	}
	else return 0; //stack is empty

	int countEqui = 0;
	int countOfLeaderRight = 0;
	int countOfLeaderLeft = countofLeader;

	for (int i = (int)A.size() - 1; i >= 0; i--) {
		if (A[i] == leader){
			countOfLeaderRight++;
			countOfLeaderLeft--;
		}

		if (countOfLeaderLeft > i / 2 && countOfLeaderRight > ((int)A.size() - i) / 2) {
			countEqui++;
		}
	}
	return countEqui;
	//return B;


}

void testJavaLeader() {
	vector<int> vt = { 4,3,4,4,4,2 };
	cout << "java leader " << JavaEqLeader(vt);
	cin.get();
}

//minimal average slice

int minSlice(vector<int> v) {
	int N = v.size();
	double min = 10000;
	int minIndex = 0;

	for (int i = 0; i < N - 2; ++i) {
		if (i < N - 3) {
			double av2 = (v[i] + v[i + 1]) / 2.0;
			if (av2 < min) {
				min = av2;
				minIndex = i;
			}
			double av3 = (v[i] + v[i + 1] + v[i + 2]) / 3.0;
			if (av3 < min) {
				min = av3;
				minIndex = i;
			}
		}
			
		else {
			double av2 = (v[i] + v[i + 1]) / 2.0;
			if (av2 < min) {
				min = av2;
				minIndex = i;
			}
			double av3 = (v[i] + v[i + 1] + v[i + 2]) / 3.0;
			if (av3 < min) {
				min = av3;
				minIndex = i;
			}
			double av22 = (v[i+1] + v[i + 2]) / 2.0;
			if (av22 < min) {
				min = av22;
				minIndex = i+1;
			}

		}

	}
	return minIndex;
}

void testMinSlice() {
	vector<int> vt = { 4,2,2, 5,1,5,8};
	cout << "min slice " << minSlice(vt);
	cin.get();
}

//genes
vector<int> geomCount(string s, vector<int> p, vector<int> q) {
	map<char, int> mymap = {
		{'A', 1},
		{'C',2 },
		{'G',3},
		{'T',4}
	};

	int N = s.size();
	int M = p.size();
	vector<int> res;

	for (int i = 0; i < M; i++) {
		int pi = p[i];
		int qi = q[i];
		int min = 4;
		for (int j = pi; j <= qi; j++) {
			if (mymap[s[j]] < min) min = mymap[s[j]];
		}
		res.push_back(min);
	}
	return res;

}

vector<int> geomCount2(string s, vector<int> p, vector<int> q) {
	map<char, int> mymap = {
		{ 'A', 1 },
		{ 'C',2 },
		{ 'G',3 },
		{ 'T',4 }
	};

	int N = s.size();
	int M = p.size();
	vector<int> res;

	vector<int> A = { 0 };
	vector<int> C = { 0 };
	vector<int> G = { 0 };

	int Acnter = 0;
	int Ccnter = 0;
	int Gcnter = 0;

	for (int i = 0; i < N; ++i) {
		if (s[i] == 'A') Acnter++;
		if (s[i] == 'C') Ccnter++;
		if (s[i] == 'G') Gcnter++;
		A.push_back(Acnter);
		C.push_back(Ccnter);
		G.push_back(Gcnter);
	}

	for (int i = 0; i < M; i++) {
		int pi = p[i];
		int qi = q[i];
		int min = 4;
		if (A[qi+1] - A[pi] > 0) 	min = 1;					
		else if (C[qi+1] - C[pi] > 0) min = 2;
		else if (G[qi+1] - G[pi] > 0) min = 3;
		res.push_back(min);

	}

	return res;

}


void testGen(){}


int disc(vector<int> A) {
	int n = A.size();
	if (!n)	return 0;

	vector<int> startCount, stopCount;

	startCount.assign(n, 0);
	stopCount.assign(n, 0);

	for (int i = 0; i<n; i++) {
		startCount[(long)i - A[i]<0 ? 0 : (long)i - A[i]]++; 
		stopCount[(long)i + A[i] >n - 1 ? n - 1 : (long)i + A[i]]++;
	}

	int intersect = startCount[0] * (startCount[0] - 1) / 2;
	int active = startCount[0] - stopCount[0];
	for (int i = 1; i < n; i++) {
		intersect += active += startCount[i] - stopCount[i];
		if (intersect > 10000000)return -1;
	}
}

int number_of_disc_intersections(const vector<int> &A) {
	int sum = 0;
	vector<int> start(A.size(), 0);
	vector<int> end(A.size(), 0);

	for (unsigned int i = 0; i<A.size(); i++) {
		if ((int)i<A[i]) start[0]++;
		else start[i - A[i]]++;
		if (i + A[i] >= A.size())   end[A.size() - 1]++;
		else                    end[i + A[i]]++;
	}
	int active = 0;
	for (unsigned int i = 0; i<A.size(); i++) {
		sum += active*start[i] + (start[i] * (start[i] - 1)) / 2;
		if (sum>10000000) return -1;
		active += start[i] - end[i];
	}
	return sum;
}

//triangle

int triangle(vector<int> &A) {
	// write your code in C++14 (g++ 6.2.0)
	int N = A.size();
	if (N<3) return 0;

	sort(A.begin(), A.end());

	for (int i = 0; i<N - 2; ++i) {
		if (A[i] + A[i + 1]>A[i + 2]) return 1;
	}
	return 0;
}

//returns non zero array
int nonzeroslice(vector<int> A) {
	int N = A.size();
	int max = -1;

	vector<int> temp;
	int sum = 0;
	for (int i = 0; i < N; i++) {
		if (A[i] >= 0) {
			sum += A[i];
			if (sum > max) max = sum;
		}
		else {
			sum = 0;
		}
	}
	return max;
}

void testnon() {
	vector<int> vt = { 1,2,-3, 4,5,-6 };
	vector<int> vs= { -8, 3, 0, 5, -3, 12 };
	vector<int> vd = { -1, 2, 1, 2, 0, 2,1, -3, 4, 3,0,-1};
	vector<int> vx = { 2,-5,3,0,-6 ,10};
	int res = nonzeroslice(vx);
	cout << " non zero " << res;
	cin.get();
}

/*
class node
{
public:
	int data;
	node* next;
};
*/

class Solution {
//private node structure
private:
	struct node{
		int data;
		node* next; //pointer to next element
	};
	node *topvalue;
	int count; //count of elements
	int maxnum; //maximum number of elements
	int stackData;
public:
	Solution(int data) : topvalue(NULL), maxnum(data), count(0) {}

	~Solution() { //destructor
		node *current = topvalue;
		//need to delete all vallue
		while (!current == NULL) {
			node *next = current->next;
			delete current;
			current = next;

		}
	}
		
	void push(int value);
	

	int top();
	

	void pop();
	

	void begin(){}
	

	bool rollback() {
	}

	bool commit() {
	}


};

//implementation
void Solution::push(int value) {
	if (count == maxnum)
		cout << "stack is full";
	else
	{
		node *newTop = new node;
		if (topvalue == NULL)
		{
			newTop->data = value;
			newTop->next = NULL;
			topvalue = newTop;
			count++;
		}
		else
		{
			newTop->data = value;
			newTop->next = topvalue;
			topvalue = newTop;
			count++;
		}
	}
}

int Solution::top() {
	if (topvalue == NULL) {
		return 0;
	}
	return topvalue->data;
}

void Solution::pop() {
	if (topvalue == NULL)
		cout << "nothing to pop";
	else
	{
		node * old = topvalue;
		topvalue = topvalue->next;
		count--;
		delete(old);
	}
}

#include <set>
int elevator(vector<int> &A, vector<int> &B, int M, int X, int Y) {
	// write your code in C++14 (g++ 6.2.0)
	
	int total_weight = 0;
	int count_ppl = 0;	
	set<int> floors; //unique set of floors
	int count_stops = 0;
	int N = A.size();
	int index = 1;

	//for each person in the queue
	while (index<N){
		//check if both conditions hold
		
		if (count_ppl + 1 > X || total_weight + A[index] > Y) {
			//elevator isfull
			//add the number of stops
			count_stops += (int)floors.size() + 1;//
			//clear all temp variables
			floors.clear();
			total_weight = 0;
			count_ppl = 0;
			//add the person who could not get in
			//total_weight += A[i];
			//count_ppl++;
			//floors.insert(B[i]);

		}
		
			//add to weight
			total_weight += A[index];
			count_ppl++;
			floors.insert(B[index]);
			index++;
		
	}

	//last run
	if (floors.size() > 0) {
		count_stops+= (int)floors.size() + 1;//
	}


	return count_stops;
}

void testStack() {
	Solution stack(5);
	stack.push(3);
	int res = stack.top();
	cout << "res is " << res;
	cin.get();
}

int main() {
	
	testStack();
	testnon();
	testMinSlice();
	testJavaLeader();
	testeqLeader();
	testDominator();
	testIndex();
	testGcd();
	//sortTest();
	testMax();
	return 0;	
}