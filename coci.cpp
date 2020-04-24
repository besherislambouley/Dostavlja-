/*
 * https://github.com/luciocf/Problems/blob/master/COCI/COCI%202017-2018/dostavljac.cpp
*/
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#include <bits/stdc++.h>
using namespace std;
#define sqr 547
#define mid (l+r)/2
#define pb push_back
#define ppb pop_back
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define ins insert
#define era erase
#define C continue
#define mem(dp,i) memset(dp,i,sizeof(dp))
#define mset multiset
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef short int si;
typedef long double ld;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pi> vpi;
typedef vector<pll> vpll;
const ll inf=1e18;
const ll mod=1e9+7;
const ld pai=acos(-1);
int n , m ;
vi v[509] ;
int a[509] ;
int dp[509][509][2] ;
void dfs ( int node , int p ) {
	for ( int i = 1 ; i <= m ; i ++ ) dp[node][i][0] = dp[node][i][1] = a[node] ;
	for ( auto u : v[node] ) {
		if ( u == p ) C ;
		dfs ( u , node ) ;
		for ( int i = m ; i >= 1 ; i -- ) {
			for ( int j = 0 ; j <= i ; j ++ ) {
				if ( i-j-1 >= 0 ) dp[node][i][0] = max ( dp[node][i][0] , max ( dp[u][j][1] , dp[u][j][0] ) + dp[node][i-j-1][1] ) ;
				if ( i-j-2 >= 0 ) dp[node][i][0] = max ( dp[node][i][0] , dp[u][j][1] + dp[node][i-j-2][0] ) ,
						  dp[node][i][1] = max ( dp[node][i][1] , dp[u][j][1] + dp[node][i-j-2][1] ) ;
			}
		}
	}
}
int main () {
	cin >> n >> m ;
	for ( int i = 0 ; i < n ; i ++ ) cin >> a[i] ;
	for ( int i = 0 ; i < n-1 ; i ++ ) {
		int a , b ;
		cin >> a >> b ;
		a -- , b -- ;
		v[a] .pb ( b ) ;
		v[b] .pb ( a ) ;	
	}
	dfs ( 0 , 0 ) ;
	cout << max ( dp[0][m][0] , dp[0][m][1] ) << endl ; 
}
