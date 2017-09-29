#include<bits/stdc++.h>
using namespace std;



typedef pair<vector<vector<int> > , int> state;
vector<vector<int> > destination (3,vector<int>(3));
vector<vector<int> > source (3,vector<int>(3));
map<vector<vector<int> > ,bool> visited;
map<vector<vector<int> > , vector<vector<int> > >parent;


int getinvcount(int arr[])
{
    int inv_count = 0;
    for (int i = 0; i < 9 - 1; i++)
        for (int j = i+1; j < 9; j++)
             if (arr[j] && arr[i] &&  arr[i] > arr[j])
                  inv_count++;
    return inv_count;
}


bool issolvable(vector<vector<int> > puzzle)
{
	int ar[8];
	int p=0;
	for(int i=0;i<3;++i )
	{
		for(int j=0;j<3;++j)
		{
			ar[p++]=puzzle[i][j];
		}
	}
	int invcount =getinvcount(ar);


    return (invcount%2 == 0);
}


bool visit(vector<vector<int> > a)
{
	if(visited[a]==true)
		return true;
	else
		return false;
}


bool isvalid(int x,int y)
{
	if(x>=0&&x<=2&&y>=0&&y<=2) return true;
	return false;
}


int manhattan(state a)
{
	vector<vector<int> > tmp=a.first;
	int total=a.second;

	for(int i=0;i<3;++i)
	{
		for(int j=0;j<3;++j)
		{
			if(tmp[i][j]!=0)
			{
				for(int u=0;u<3;++u)
				{
					for(int v=0;v<3;++v)
					{
						if(destination[u][v]==tmp[i][j])
						total+=abs(u-i)+abs(v-j);
					}
				}
			}
		}
	}
	return total;
}


vector<vector<vector<int> > > possible_moves(vector<vector<int> > st)
{
	vector<vector<vector<int> > > lst;
	int dx[]={-1,1,0,0};
	int dy[]={0,0,-1,1};
	int x,y;
	for(int i=0;i<3;++i)
	{
		for(int j=0;j<3;++j)
		{
			if(st[i][j]==0)
			{
				x=i;
				y=j;
			}
		}
	}
	for(int i=0;i<4;++i)
	{
		vector<vector<int> > d=st;
		int newx=x+dx[i];
		int newy=y+dy[i];
		if(isvalid(newx,newy))
		{ 
			swap(d[newx][newy],d[x][y]);
			lst.push_back(d);
		}

	}
	return lst;

}


struct cmp
{

	bool operator( ) (state a, state b)
	{
		int d1=manhattan(a);
		int d2=manhattan(b);
		return d1>d2;
	}
};


void print_ans(vector<vector<int> > v)
{
	if(parent.count(v))
	{
		print_ans(parent[v]);
	}
	for(int i=0;i<3;++i)
	{
		for(int j=0;j<3;++j)
		{
			cout<<v[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
    return;
}


void solve()
{

	priority_queue<state,vector<state>,cmp> pq;
	pq.push(state(source,0));

	while(!pq.empty())
		{
			state s=pq.top();
			vector<vector<int> > st=s.first;
			int moves=s.second;

			pq.pop();
			visited[st]=true;
			if(st==destination)
			{
				print_ans(st);
				break;
			}


			vector<vector<vector<int> > > adjacents=possible_moves(st);
			vector<vector<vector<int> > >::iterator it;
			for( it=adjacents.begin();it!=adjacents.end();it++)
			{
                vector<vector<int> > p=*it;
				if(!visit(p))
				{
					pq.push(state(p,moves+1));
					parent.insert(pair<vector<vector<int> > ,vector<vector<int> > > (p,st));
				}
			}


		}
		return ;
}





int main()
{
	int p=1;
	
	for(int i=0;i<3;++i)
	{
		for(int j=0;j<3;++j)
		{
			if(i==j&&j==2)
				destination[i][j]=0;
			else
				destination[i][j]=p++;
		}
	}
	for(int i=0;i<3;++i)
	{
		for(int j=0;j<3;++j)
		{
			cin>>source[i][j];
		}
	}
	if(issolvable(source))
	{
	cout<<"sequence of moves: "<<endl;
		solve();
	}
	else cout<<"puzzle is not solvable"<<endl;
	return 0;

}



