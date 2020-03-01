#include <bits/stdc++.h>
using namespace std;
const int N = 1000;
vector<int> adj[N];

bool *latogatvag;

//int comp
bool compare(int i,int j) {

    int v1=0, v2=0;

	for (int x : adj[i]) {
		if (!latogatvag[x])
			v1++;
	}

	for (int x : adj[j]) {
		if (!latogatvag[x])
			v2++;
	}

    return (v1<v2);
}

//MVR
void MVR(vector<int>* adj,bool* latogatva ){
    latogatvag = latogatva;
    sort(adj->begin(), adj->end(), compare);
}


void dfsUtil(int u, int csomopont, bool latogatva[],
			vector<pair<int, int> > bejart_ut, int parent, int it)
{
	int c = 0;

	for (int i = 0; i < csomopont; i++)
		if (latogatva[i])
			c++;

	if (c == csomopont)
		return;

	latogatva[u] = true;

	bejart_ut.push_back({ parent, u });

	for (int x : adj[u]) {

		if (!latogatva[x])
			dfsUtil(x, csomopont, latogatva, bejart_ut, u, it + 1);
	}

	for (auto y : bejart_ut){
            cout<<y.first<<" ";
	}
	cout<<endl;


	for (auto y : bejart_ut)
		if (y.second == u)
			dfsUtil(y.first, csomopont, latogatva,
					bejart_ut, u, it + 1);
}


void dfsUtil2(int u, int csomopont, bool latogatva[],
			vector<pair<int, int> > bejart_ut, int parent, int it)
{
	int c = 0;


	for (int i = 0; i < csomopont; i++)
		if (latogatva[i])
			c++;

	if (c == csomopont)
		return;

	latogatva[u] = true;

	bejart_ut.push_back({ parent, u });

	MVR(adj,latogatva);

	for (int x : adj[u]) {

		if (!latogatva[x])
			dfsUtil(x, csomopont, latogatva, bejart_ut, u, it + 1);
	}

	for (auto y : bejart_ut){
            cout<<y.first<<" ";
	}
	cout<<endl;


	for (auto y : bejart_ut)
		if (y.second == u)
			dfsUtil2(y.first, csomopont, latogatva,
					bejart_ut, u, it + 1);
}


void dfs2(int csomopont)
{
	bool latogatva[csomopont];

	vector<pair<int, int> > bejart_ut;

	for (int i = 0; i < csomopont; i++)
		latogatva[i] = false;

	dfsUtil2(0, csomopont, latogatva, bejart_ut, -1, 0);
}


void dfs(int csomopont)
{
	bool latogatva[csomopont];

	vector<pair<int, int> > bejart_ut;

	for (int i = 0; i < csomopont; i++)
		latogatva[i] = false;

	dfsUtil(0, csomopont, latogatva, bejart_ut, -1, 0);
}

void hozzaadEl(int u, int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}

int main()
{
	int csomopont = 13, edge = 13, keresett=0;
    int tipus=0;

	hozzaadEl(0, 1);
	hozzaadEl(0, 2);
	hozzaadEl(0, 3);
	hozzaadEl(1, 6);
	hozzaadEl(1, 7);
	hozzaadEl(1, 8);
	hozzaadEl(2, 4);
	hozzaadEl(2, 5);
	hozzaadEl(4, 10);
	hozzaadEl(5, 10);
	hozzaadEl(3, 9);
	hozzaadEl(9, 11);
	hozzaadEl(11, 12);

	cout<<"1. Simple Backtrack"<<endl;
	cout<<"2. Backtrack + MVR"<<endl;
	cin>>tipus;

    if (tipus == 1)
        dfs(csomopont);
	if (tipus == 2)
        dfs2(csomopont);

	return 0;
}
