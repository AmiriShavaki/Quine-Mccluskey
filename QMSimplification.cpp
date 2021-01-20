#include <iostream>
#include <string>
#include <algorithm> //using reverse and count and find
#include <utility> //using pair
#include <vector>
#include <set>

using namespace std;

const int MAX_VARIABLE = 100;

string decimalToBinary(int a, const int n) {
	string res;
	for (int i = 0; i < n; i++) {
		res += a % 2 + '0';
		a /= 2;
	}
	reverse(res.begin(), res.end());
	return res;
}

string decimalToBinary(vector < int > v, const int n) {
	string res = decimalToBinary(v[0], n);
	for (int i = 1; i < v.size(); i++) {
		string tmpBinary = decimalToBinary(v[i], n);
		for (int j = 0; j < n; j++) {
			if (tmpBinary[j] != res[j]) {
				res[j] = '-';
			}
		}
	}
	return res;
}

string numberToString(int n) {
	if (!n) {
		return "0";
	}
	string res;
	while (n) {
		res += n % 10 + '0';
		n /= 10;
	}
	reverse(res.begin(), res.end());
	return res;
}

string vecIntJoin(const vector < int > v) {
	string res;
	for (int i = 0; i < v.size(); i++) {
		res += numberToString(v[i]);
		res += (i != v.size() - 1 ? ", " : "");
	}
	return res;
}

vector < vector < pair < vector < int > , bool > > > partition(const vector < pair < int, bool > > minTerms,
const int n) {
	vector < vector < pair < vector < int > , bool > > > res;
	res.resize(n + 1);
	for (int i = 0; i < minTerms.size(); i++) {
		string binary = decimalToBinary(minTerms[i].first, n);
		
		vector < int > vecTmp; 
		vecTmp.push_back(minTerms[i].first);
		
		res[count(binary.begin(), binary.end(), '1')].push_back(make_pair(vecTmp, minTerms[i].second));
	}
	
	cout << "\n\nPartitioning result:\n\n";
	for (int i = 0; i < res.size(); i++) {
		if (!res[i].empty()) {
			cout << res[i].size() << " groups found with " << i << " 1s:\n";
			for (int j = 0; j < res[i].size(); j++) {
				cout << "Minterm " << vecIntJoin(res[i][j].first) << "   " << 
				decimalToBinary(res[i][j].first, n) << (res[i][j].second ? "\n" : " (don\'t care)\n");
			}
		}
	}
	
	return res;
}

int dif(const string s1, const string s2, const int n) {
	int res = 0;
	for (int i = 0; i < n; i++) {
		res += s1[i] != s2[i];
	}
	return res;
}

bool isPartOf(vector < int > &a, vector < int > &b) {
	for (int i = 0; i < a.size(); i++) {
		bool flg = false;
		for (int j = 0; j < b.size(); j++) {
			if (a[i] == b[j]) {
				flg = true;
			}
		}
		if (!flg) {
			return false;
		}
	}
	return true;
}

bool partition(vector < vector < vector < pair < vector < int > , bool > > > > &tbl, const int n) {
	bool flg = false;
	
	vector < vector < pair < vector < int > , bool > > > res;
	res.resize(n + 1);
	
	set < string > mark;
	
	for (int i = 0; i < n; i++) { //i = number of 1s each minterm of first group have
		for (int j = 0; j < tbl.back()[i].size(); j++) {
			for (int k = 0; k < tbl.back()[i + 1].size(); k++) {
				if (dif(decimalToBinary(tbl.back()[i][j].first, n),
				decimalToBinary(tbl.back()[i+1][k].first, n), n) == 1) {
					//cout << decimalToBinary(tbl.back()[i][j].first, n) << " " << decimalToBinary(tbl.back()[i+1][k].first, n) << endl;
					pair < vector < int >, bool > newLine;
					for (int l = 0; l < tbl.back()[i][j].first.size(); l++) {
						newLine.first.push_back(tbl.back()[i][j].first[l]);
					}
					for (int l = 0; l < tbl.back()[i+1][k].first.size(); l++) {
						if (find(newLine.first.begin(), newLine.first.end(), 
						tbl.back()[i+1][k].first[l]) == newLine.first.end()) {
							newLine.first.push_back(tbl.back()[i+1][k].first[l]);
						}
					}
					newLine.second = tbl.back()[i][j].second || tbl.back()[i+1][k].second;
					
					if (mark.find(decimalToBinary(newLine.first, n)) == mark.end()) {					
						res[i].push_back(newLine);
						mark.insert(decimalToBinary(newLine.first, n));
					}
	
					flg = true;
				}
			}
		}
	}
		
	if (flg) {
		cout << "\n\nPrime implicants partitioning result:\n\n";	
		for (int i = 0; i < res.size(); i++) {
			if (!res[i].empty()) {
				cout << res[i].size() << " groups found with " << i << " 1s:\n";
				for (int j = 0; j < res[i].size(); j++) {
					cout << "Minterm " << vecIntJoin(res[i][j].first) << "   " << 
					decimalToBinary(res[i][j].first, n) << (res[i][j].second ? "\n" : " (don\'t care)\n");
				}
			}
		}
		tbl.push_back(res);
	}
	return flg;
}

bool backtrack(vector < vector < int > > &pImps, set < int > &essentialImps,
set < int > &uncoveredMinTerms, const int i, vector < int > &pickedImps, vector < int > tmp,
int pickedCnt = 0, int ind = 0) {
	if (i == pickedCnt) {
		set < int > tmpSet = uncoveredMinTerms;
		for (int j = 0; j < tmp.size(); j++) {
			for (int k = 0; k < pImps[tmp[j]].size(); k++) {
				tmpSet.erase(pImps[tmp[j]][k]);
			}
		}
		if (tmpSet.empty()) {
			pickedImps = tmp;
		}
		/*cout << "\n\nDEBUG" << "i:" << i << "\n";
		for (int j = 0; j < tmp.size(); j++) {
			cout << "  tmp[j]:  " << tmp[j] << "   " << endl;
			for (int k = 0; k < pImps[tmp[j]].size(); k++) {
				cout << pImps[tmp[j]][k] << "  ";
			}
		}		
		cout << "\nDEBUG\n\n";*/
		return tmpSet.empty();
	} else if (ind >= pImps.size()) {
		return false;
	}
	bool res1 = backtrack(pImps, essentialImps, uncoveredMinTerms, i, pickedImps, tmp, pickedCnt, ind + 1);
	bool res2 = false;
	if (essentialImps.find(ind + 1) == essentialImps.end()) {
		tmp.push_back(ind);
		res2 = backtrack(pImps, essentialImps, uncoveredMinTerms, i, pickedImps, tmp, pickedCnt + 1, ind + 1);
	}
	return res1 || res2;
}

void bestPick(vector < vector < int > > &pImps, set < int > &essentialImps,
set < int > &uncoveredMinTerms, vector < int > &pickedImps, vector < int > &tmp) {
	for (int i = 1; i <= pImps.size() - essentialImps.size(); i++) {
		if (backtrack(pImps, essentialImps, uncoveredMinTerms, i, pickedImps, tmp)) {
			return;
		}
	}
}

int main() {
	cout << "Enter number of variables: ";
	int n;
	cin >> n;
	
	set < int > uncoveredMinTerms;
	cout << "Enter number corresponding to each of the Minterms (or enter -1 to get next step):\n";
	vector < pair < int, bool > > minTerms;
	int buf;
	cin >> buf;
	while (buf != -1) {
		minTerms.push_back(make_pair(buf, true));
		uncoveredMinTerms.insert(buf);
		cin >> buf;
	}
	
	cout << "Enter number corresponding to each of the don\'t cares (or enter -1 to get next step):\n";
	cin >> buf;
	while (buf != -1) {
		minTerms.push_back(make_pair(buf, false));
		cin >> buf;
	}	
	
	vector < vector < pair < vector < int > , bool > > > tbl0 = partition(minTerms, n);
	vector < vector < vector < pair < vector < int > , bool > > > > tbl;
	tbl.push_back(tbl0);
	while (partition(tbl, n)) {;}
	
	vector < vector < int > > pImps;
	
	for (int i = tbl.size() - 1; i >= 0; i--) { //Each table 
		for (int j = 0; j < tbl[i].size(); j++) { //Each group
			for (int k = 0; k < tbl[i][j].size(); k++) { //Each line
				if (tbl[i][j][k].second) {
					bool flg = false;
					for (int l = 0; l < pImps.size(); l++) {
						if (isPartOf(tbl[i][j][k].first, pImps[l])) {
							flg = true;
						}
					}
					if (!flg) {
						pImps.push_back(tbl[i][j][k].first);
					}
				}
			}
		}
	}
	cout << "\n\nList of prime implicants:\n\n";
	for (int i = 0; i < pImps.size(); i++) {
		cout << "PI" << numberToString(i + 1) << ": " << vecIntJoin(pImps[i]) << endl; 
	}
	
	int mp[MAX_VARIABLE];
	fill(mp, mp + MAX_VARIABLE, -2);
	set < int > essentialImps;
	cout << "\n    ";
	for (int i = 0; i < minTerms.size(); i++) {
		if (minTerms[i].second) {
			cout << " ";
			string s = numberToString(minTerms[i].first);
			if (s.size() == 1) {
				cout << " ";
			}
			cout << s << " ";
		}
	} cout << endl;
	for (int i = 0; i < pImps.size(); i++) {
		if (i < 9) {
			cout << "PI" << i + 1 << " ";
		} else {
			cout << "PI" << i + 1;
		}
		for (int j = 0; j < minTerms.size(); j++) {
			if (!minTerms[j].second) {
				continue;
			}
			if (find(pImps[i].begin(), pImps[i].end(), minTerms[j].first) != pImps[i].end()) {
				cout << "  * ";
				if (mp[minTerms[j].first] == -2) {
					mp[minTerms[j].first] = i;
				} else {
					mp[minTerms[j].first] = -1;
				}
			} else {
				cout << "    ";
			}
		}
		cout << endl;
	}
	for (int i = 0; i < MAX_VARIABLE; i++) {
		if (mp[i] > -1) {
			essentialImps.insert(mp[i] + 1);
			for (int j = 0; j < pImps[mp[i]].size(); j++) {
				uncoveredMinTerms.erase(pImps[mp[i]][j]);
			}
		}
	}
	for (set <int>::iterator it = essentialImps.begin(); it != essentialImps.end(); it++) {
		cout << "PI" << *it << " is an essential implicant\n";
	}
	for (set <int>::iterator it = uncoveredMinTerms.begin(); it != uncoveredMinTerms.end(); it++) {
		cout << "Minterm " << *it << " is not covered under essential implicants\n";
	}
	if (uncoveredMinTerms.empty()) {
		return 0;
	}
	
	cout << "\n    ";
	for (set <int>::iterator it = uncoveredMinTerms.begin(); it != uncoveredMinTerms.end(); it++) {
		cout << " ";
		string s = numberToString(*it);
		if (s.size() == 1) {
			cout << " ";
		}
		cout << s << " ";
	} cout << endl;
	for (int i = 0; i < pImps.size(); i++) {
		if (essentialImps.find(i + 1) != essentialImps.end()) {
			continue;
		}
		if (i < 9) {
			cout << "PI" << i + 1 << " ";
		} else {
			cout << "PI" << i + 1;
		}
		for (set <int>::iterator it = uncoveredMinTerms.begin(); it != uncoveredMinTerms.end(); it++) {
			if (find(pImps[i].begin(), pImps[i].end(), *it) != pImps[i].end()) {
				cout << "  * ";
			} else {
				cout << "    ";
			}
		}
		cout << endl;
	}
	
	cout << "\nEssential implicants:\n";
	for (set <int>::iterator it = essentialImps.begin(); it != essentialImps.end();) {
		cout << "PI" << *it;
		it++;
		cout << (it != essentialImps.end() ? ", " : "\n");
	}
	
	vector < int > pickedImps;
	vector < int > tmp;
	bestPick(pImps, essentialImps, uncoveredMinTerms, pickedImps, tmp);
	cout << "\nPicked non-essential implicants:\n";
	for (int i = 0; i < pickedImps.size(); i++) {
		cout << "PI" << pickedImps[i] + 1 << (i != pickedImps.size() - 1 ? ", " : "\n");
	}
}
