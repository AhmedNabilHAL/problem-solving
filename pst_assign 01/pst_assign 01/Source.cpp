#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <utility>
#include <algorithm>
#include <queue>
#include <string>
#include <stack>
#include <unordered_set>
using namespace std;

deque<queue<int>> ans;
unordered_set<int> teams[1001];
int t, n, num;
char op[8];
int search_teams(){
	int i;
	for (i = 0; i < n; i++){
		if (teams[i].count(num))
			break;
	}
	for (int j = 0; j < ans.size(); j++){
		if (teams[i].count(ans[j].front()))
			return j;
	}
		
	return -1;
}
int main(){
	int k = 1;
	while (scanf("%d", &t), t){
		for (int i = 0; i < t; i++){
			scanf("%d", &n);
			for (int j = 0; j < n; ++j){
				int x;
				scanf("%d", &x);
				teams[i].insert(x);
			}
		}
		printf("Scenario #%d\n", k);
		while (scanf("%s", op), op[0] != 'S'){
			if (op[0] == 'E'){
				scanf("%d", &num);
				int y = search_teams();
				if (y != -1)
					ans[y].push(num);
				else{
					queue<int> z; z.push(num);
					ans.push_front(z);
				}
			}
			else{
				if (ans.size()){
					if (!ans[ans.size() - 1].empty()){
						printf("%d\n", ans[ans.size() - 1].front());
						ans[ans.size() - 1].pop();
					}
					if (ans[ans.size() - 1].empty() && !ans.empty())
						ans.pop_back();
				}
			}
		}
		ans.clear();
		for (int i = 0; i < t; i++)
			teams[i].clear();
		k++;
		printf("\n");
	}
	return 0;
}
string reversed(string s){
	string str = "";
	string word = "";
	for (int i = 0; i < s.length(); i++){
		if (s[i] != ' ')
			word.push_back(s[i]);
		else{
			reverse(word.begin(), word.end());
			word.push_back(' ');
			str += word;
			word = "";
		}
	}
	reverse(word.begin(), word.end());
	word.push_back('\n');
	str += word;
	word = "";
	return str;
}
void empty_stack(stack<int> &st){
	while (!st.empty())
		st.pop();
}
bool is_possible_stack(stack<int> st, int nxt){
	if (st.empty())
		return true;
	if (st.top() == nxt){
		st.pop();
		return is_possible_stack(st, nxt + 1);
	}
	return false;
}
bool is_possible(queue<int> q, stack<int> st, int nxt){
	if (q.empty())
		return is_possible_stack(st, nxt);
	if (st.empty()){
		if (q.front() == nxt){
			q.pop();
			return is_possible(q, st, nxt + 1);
		}
		else{
			st.push(q.front());
			q.pop();
			return is_possible(q, st, nxt);
		}
	}
	if (q.front() == nxt){
		q.pop();
		return is_possible(q, st, nxt + 1);
	}
	else if (st.top() == nxt){
		st.pop();
		return is_possible(q, st, nxt + 1);
	}
	st.push(q.front());
	q.pop();
	return is_possible(q, st, nxt);
}
string print_stack(vector<string> path, int n){
	if (n == path.size())
		return "/\n";
	return '/' + path[n] + print_stack(path, n + 1);
}
string add_one(string s, int n){
	static string it = s;
	if (n == 0)
		return s;
	if (s[n - 1] == 'z'){
		it[n - 1] = 'a';
		return add_one(s, n - 1);
	}
	else{
		it[n - 1] += 1;
		return it;
	}
}
bool is_two(string s){
	int n = 0;
	if (s[0] == 't') n++;
	if (s[1] == 'w') n++;
	if (s[2] == 'o') n++;
	return (n >= 2) ? 1 : 0;
}
void problem_A(){
	int q; deque<int> dq1, dq2; bool rev = true;
	scanf("%d", &q);
	char op[10];
	int n = 0;
	for (int i = 0; i < q; ++i){
		scanf("%s", op);

		if (op[0] == 'b'){
			if (dq1.size() == 0)
				printf("No job for Ada?\n");
			else{

				if (rev){
					printf("%d\n", dq1.back());
					dq1.pop_back();
					dq2.pop_front();
				}
				else{
					printf("%d\n", dq2.back());
					dq2.pop_back();
					dq1.pop_front();
				}
			}
		}
		else if (op[0] == 'f'){
			if (dq1.size() == 0)
				printf("No job for Ada?\n");
			else{

				if (rev){
					printf("%d\n", dq1.front());
					dq1.pop_front();
					dq2.pop_back();
				}
				else{
					printf("%d\n", dq2.front());
					dq2.pop_front();
					dq1.pop_back();
				}
			}
		}
		else if (op[0] == 'r'){
			rev = !rev;
		}
		else if (op[0] == 'p'){
			scanf("%d", &n);
			if (rev){
				dq1.push_back(n);
				dq2.push_front(n);
			}
			else{
				dq2.push_back(n);
				dq1.push_front(n);
			}
		}
		else{
			scanf("%d", &n);
			if (rev){
				dq1.push_front(n);
				dq2.push_back(n);
			}
			else {
				dq2.push_front(n);
				dq1.push_back(n);
			}
		}
	}

}
void problem_B(){
	const int N = 1e5 + 5;
	pair <int, int> pts[N];
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i){
		int n;
		scanf("%d", &n);
		for (int j = 0; j < n; ++j)
		{
			scanf("%d%d", &pts[j].first, &pts[j].second);
			pts[j].second *= -1;
		}
		sort(pts, pts + n);
		for (int j = 0; j < n; ++j)
		{
			printf("%d %d\n", pts[j].first, pts[j].second * -1);
		}
	}
}
void problem_C(){
	string s, t;
	cin >> s >> t;
	s = add_one(s, s.size());
	if (s == t)
		cout << "No such string\n";
	else
		cout << s << endl;
}
void problem_D(){
	int t;
	cin >> t;
	string num;
	for (int i = 0; i < t; i++){
		cin >> num;
		if (num.length() > 3)
			cout << 3 << endl;
		else if (is_two(num))
			cout << 2 << endl;
		else
			cout << 1 << endl;
	}
}
void problem_E(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	if (n % 4)
		cout << "===\n";
	else{
		int a = 0, c = 0, g = 0, t = 0;
		int each = n / 4;

		for (int i = 0; i < s.length(); i++){
			if (s[i] == 'A')
				a++;
			else if (s[i] == 'C')
				c++;
			else if (s[i] == 'G')
				g++;
			else  if (s[i] == 'T')
				t++;
		}
		if (a > each || c > each || g > each || t > each){
			cout << "===\n";
			return;
		}
		for (int i = 0; i < s.length(); i++){
			if (s[i] == '?')
			if (a < each){
				a++; s[i] = 'A';
			}
			else if (c < each){
				c++; s[i] = 'C';
			}
			else if (g < each){
				g++; s[i] = 'G';
			}
			else if (t < each){
				t++; s[i] = 'T';
			}
		}
		cout << s << endl;
	}
}
void problem_F(){
	vector<string> path; int n; string cmd, p;
	cin >> n;
	for (int i = 0; i < n; ++i){
		cin >> cmd;
		if (cmd[0] == 'p'){
			cout << print_stack(path, 0);
		}
		else if (cmd[0] == 'c'){
			cin >> p; string s = ""; p += '/';
			if (p[0] == '/'){
				path.clear();
				for (int i = 1, j = 0; i < p.length(); ++i){

					if (p[i] != '/'){
						s += p[i];
					}
					else{
						if (s == "..")
							path.pop_back();
						else
							path.push_back(s);
						s = "";
					}
				}
			}
			else{
				for (int i = 0, j = 0; i < p.length(); ++i){
					if (p[i] != '/'){
						s += p[i];
					}
					else{
						if (s == "..")
							path.pop_back();
						else
							path.push_back(s);
						s = "";
					}
				}
			}
		}
	}
}
void problem_G(){
	string s;
	cin >> s;
	vector<int> nums;
	for (int i = 0; i < s.length(); i++){
		if (isdigit(s[i]))
			nums.push_back((int)s[i] - (int)'0');
	}
	sort(nums.begin(), nums.end());
	for (int i = 0; i < nums.size(); ++i){
		cout << nums[i];
		if (i != nums.size() - 1)
			cout << '+';
	}
	cout << endl;
}
void problem_H(){
	int n;

	int nxt = 1, x;
	while (scanf("%d", &n), n){
		queue<int> q;
		stack<int> st;
		while (n--){
			cin >> x;
			q.push(x);
		}
		if (is_possible(q, st, nxt))
			cout << "yes\n";
		else cout << "no\n";
	}
}
void problem_I(){
	int n;
	string seq;
	stack<int> br;
	cin >> n;
	getline(cin, seq);
	while (n--){
		bool b = false;
		getline(cin, seq);
		for (int i = 0; i < seq.size(); ++i){
			if (seq[i] == '(')
				br.push(0);
			else if (seq[i] == '[')
				br.push(1);
			else if ((seq[i] == ')' && br.empty()) || (seq[i] == ']' && br.empty())){
				cout << "No\n";
				b = true;
				break;
			}
			else if (seq[i] == ')'){
				if (br.top() == 0)
					br.pop();
				else{
					cout << "No\n";
					b = true;
					break;
				}
			}
			else if (seq[i] == ']'){
				if (br.top() == 1)
					br.pop();
				else{
					cout << "No\n";
					b = true;
					break;
				}
			}
		}
		if (br.empty() && !b)
			cout << "Yes\n";
		else if (!b)
			cout << "No\n";
		empty_stack(br);
	}
}
void problem_J(){
	int n, k;
	vector<int> v;
	cin >> n;
	cin >> k;
	while (n--){
		int y;
		cin >> y;
		v.push_back(y);
	}
	sort(v.begin(), v.end());
	int team = 0;
	int ans = 0;
	for (int i = 0; i < v.size(); ++i){
		if (v[i] <= 5 - k)
			team++;
		if (team == 3)
		{
			ans++;
			team = 0;
		}
	}
	cout << ans << endl;
}
void problem_K(){
	deque<int> dq;
	vector<int> seq;
	int n = 0;
	while (scanf("%d", &n), n){
		for (int i = 1; i <= n; ++i)
			dq.push_back(i);
		while (dq.size() >= 2){
			seq.push_back(dq[0]);
			dq.pop_front();
			dq.push_back(dq[0]);
			dq.pop_front();
		}
		printf("Discarded cards:");
		for (int i = 0; i < seq.size() - 1 && seq.size(); ++i)
			printf(" %d,", seq[i]);
		if (seq.size())
			printf(" %d\n", seq[seq.size() - 1]);
		else
			printf("\n");
		if (dq.size())
			printf("Remaining card: %d\n", dq[0]);
		else
			printf("Remaining card:\n");
		seq.clear();
		dq.clear();
	}
}
void problem_L(){
	string sent;
	while (true){
		getline(cin, sent);
		if (cin.eof())
		{
			cout << reversed(sent);
			break;
		}
		cout << reversed(sent);
	}
}
void problem_M(){
	priority_queue<pair<int, int>> pq;
	vector <string> names;
	int n;
	scanf("%d", &n);
	string name;
	string status;
	for (int i = 0; i < n; i++){
		cin >> name >> status;
		names.push_back(name); //r w c m cp
		if (status[2] == 't'){
			pq.push({ 4, -i });
		}
		else if (status[2] == 'm' || status[2] == 'i'){
			pq.push({ 3, -i });
		}
		else if (status[2] == 'n'){
			pq.push({ 2, -i });
		}
		else{
			pq.push({ 1, -i });
		}
	}
	while (!pq.empty()){
		cout << names[-pq.top().second] << endl;
		pq.pop();
	}
}