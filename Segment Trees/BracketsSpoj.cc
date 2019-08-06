#include <iostream>
using namespace std;

class Brackets{
public:
	int UOP;
	int UCP;
};

void buildTree(Brackets * Segtree, char arr[], int curidx, int ss, int se){
	
	if(ss == se){
		if(arr[ss] == '('){
			Segtree[curidx].UOP = 1;
			Segtree[curidx].UCP = 0;
		}
		else{
			Segtree[curidx].UCP = 1;
			Segtree[curidx].UOP = 0;
		}
		return;
}

	int mid = (ss + se)/2;
	buildTree(Segtree, arr, 2*curidx + 1, ss, mid);
	buildTree(Segtree, arr, 2*curidx + 2, mid + 1, se);
	
	// Merge Step;
	int matches = min(Segtree[2*curidx + 1].UOP,Segtree[2*curidx + 2].UCP);
	Segtree[curidx].UOP = Segtree[2*curidx + 1].UOP + Segtree[2*curidx + 2].UOP - matches;
	Segtree[curidx].UCP = Segtree[2*curidx + 1].UCP + Segtree[2*curidx + 2].UCP - matches;
	return;
}

void update(Brackets * Segtree, char arr[], int curidx, int ss, int se, int idx){
	// Base case
	if(ss == se && ss == idx){
		Segtree[curidx].UOP = 1 - Segtree[curidx].UOP;
		Segtree[curidx].UCP = 1 - Segtree[curidx].UCP;
		return;
	}
	
	int mid = (ss + se)/2;
	
	if(mid >= idx){
		update(Segtree, arr, 2*curidx + 1, ss, mid, idx);
	}
	else{
		update(Segtree, arr, 2*curidx + 2, mid + 1, se, idx);
	}
	int matches = min(Segtree[2*curidx + 1].UOP,Segtree[2*curidx + 2].UCP);
	Segtree[curidx].UOP = Segtree[2*curidx + 1].UOP + Segtree[2*curidx + 2].UOP - matches;
	Segtree[curidx].UCP = Segtree[2*curidx + 1].UCP + Segtree[2*curidx + 2].UCP - matches;
	return;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t = 10;
	int T = 1;
	while(t--){
		int len;
		scanf("%d", &len);
		char str[30001];
		scanf("%s", str);
		Brackets Segtree[120001];
		buildTree(Segtree, str, 0, 0, len - 1);
		int m;
		scanf("%d", &m);
		printf("Test %d:\n", T);
		for(int i = 0; i < m; i++){
			int q;
			cin>>q;
			if(q == 0){

				if(Segtree[0].UOP == 0 && Segtree[0].UCP == 0){
					printf("YES\n");
				}
				else{
					printf("NO\n");
				}
			}
			else{
				update(Segtree, str, 0,0,len - 1, q - 1);
			}
		}
		T++;
	}
	
	return 0;
}