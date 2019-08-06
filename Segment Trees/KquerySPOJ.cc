// Guntas Singh
// Thapar University
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<pair<ll,ll>> arr;
ll l[300000],r[3000000],k[3000000],perm[3000000],ans[3000000];
ll segtree[4*20000 + 1];
bool compare(pair<ll,ll> a, pair<ll,ll> b){
	return a.first<b.first;
}

bool compare1(ll a,ll b){
	return k[a]<k[b];
}

void build(ll ss,ll se,ll idx){
	if(ss==se){
		segtree[idx]=1;
		return;
	}
	ll mid = (ss+se)/2;
	build(ss,mid,2*idx);
	build(mid + 1, se, 2*idx + 1);
	segtree[idx]=segtree[2*idx] + segtree[2*idx + 1];
	return;
}

void update(ll id,ll ss,ll se,ll idx){
	if(ss==se){
		if(ss==id){
			segtree[idx]=0;
		}
		return;
	}
	ll mid = (ss+se)/2;
	if(id<=mid){
		update(id,ss,mid,2*idx);
	}
	else{
		update(id,mid + 1,se, 2*idx + 1);
	}
	segtree[idx]=segtree[2*idx]+segtree[2*idx+1];
	return;
}

ll sum(ll l,ll r,ll ss, ll se, ll idx){
	// No overlap;
	if(l>se || r<ss){
		return 0;
	}
	// complete overlap;
	if(ss>=l && se<=r){
		return segtree[idx];
	}
	ll mid = (ss + se)/2;
	ll left = sum(l,r,ss,mid,2*idx);
	ll right = sum(l,r,mid + 1,se , 2*idx + 1);
	return left + right;
}


int main(){
ll N,Q,pos=0;
scanf("%lld",&N);
build(0,N-1,1);
for(ll i=0;i<N;i++){
	ll a;
	scanf("%lld",&a);
	arr.push_back(make_pair(a,i));
}
sort(arr.begin(),arr.end(),compare);

scanf("%lld",&Q);
ll q=Q;
ll i=0;
while(Q--){
scanf("%lld",&l[i]);
scanf("%lld",&r[i]);
scanf("%lld",&k[i]);
perm[i]=i;
++i;
}
sort(perm,perm+q,compare1);


for(ll i=0;i<q;i++){
	ll j=perm[i];
	while(pos<N && arr[pos].first<=k[j]){
		update(arr[pos].second,0,N-1,1);
		pos++;
	}
	ans[j]=sum(l[j]-1,r[j]-1,0,N-1,1);
}
for(ll i=0;i<q;i++){
	printf("%lld",ans[i]);
	printf("\n");
}
}