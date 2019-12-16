#include<iostream.h>
#include<conio.h>
class voter
{
	protected:
		int id[1000],wardno[1000],voted[1000];
		char gender[1000];
	public:
		int n;
		voter();
		void showdata(int id1);

};
class cand
{
	protected:
		int can[5];
	public:
		cand();
};
class voting:public voter,public cand
{
	private:
		int voterid,big,big2,majority;
	public:
		int cast();
		void count();
		void declare();
};
void voter::voter()
{
	int i,check=0,j;
	cout<<"\nenter no.of voters";
	cin>>n;
	for(i=0;i<n;i++)
	{
		cout<<"\nEnter"<<i+1<<"voter details:";
		cout<<"\nEnter voterid:";
		cin>>id[i];
		for(j=0;j<i;j++)
		{
			if(id[j]==id[i])
				check=1;
		}
		if(check==1)
		{
			cout<<"\nThis voter id already registered";
			i--;
			check=0;
		}
		else
		{
			cout<<"\nEnter wardno:";
			cin>>wardno[i];
			cout<<"\nEnter gender:";
			cin>>gender[i];
			voted[i]=0;
		}

	}
}
void cand::cand()
{
	int m;
	for(m=0;m<5;m++)
		can[m]=0;
}
void voter::showdata(int id1)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(id[i]==id1)
		{
			cout<<"\nwardno is:"<<wardno[i]<<"\ngender is:"<<gender[i];
		}
	}
}
int voting::cast()
{
	int k,ch,voterid=0;
	int j=6;
	cout<<"\nenter voter id:";
	cin>>voterid;
	for(k=0;k<n;k++)
	{
		if(voted[k]!=0 && id[k]==voterid)
		{
			cout<<"\nyour voting is over ";
		}
		else if(id[k]==voterid && voted[k]==0)
		{
			voted[k]=1;
			voter::showdata(voterid);
			cout<<"\nCOMPANIES ARE";
			cout<<"\n1\tACER";
			cout<<"\n2\tHP";
			cout<<"\n3\tDELL";
			cout<<"\n4\tSONY";
			cout<<"\n5\tAPPLE";
			cout<<"\nEnter your choice";
			cin>>ch;
			switch(ch)
			{
				case 1:
					can[0]++;
					break;
				case 2:
					can[1]++;
					break;
				case 3:
					can[2]++;
					break;
				case 4:
					can[3]++;
					break;
				case 5:
					can[4]++;
					break;
				default:
					cout<<"\nEnter valid choice";
			}
		}
		else
			cout<<" ";
	}
	return j;
}
void voting::count()
{
	big=0,big2=0,majority=0;
	int i;
	big=can[0];
	for(i=1;i<5;i++)
	{
		if(can[i]>big)
			big=can[i];
	}
	for(i=0;i<5 ;i++)
	{
		if(can[i]>big2 && can[i]!=big)
			big2=can[i];
	}
	majority=big-big2;
}
void voting::declare()
{
	if(big==can[0] && big>=1)
		cout<<"\nWINNER IS ACER";
	if(big==can[1] && big>=1)
		cout<<"\nWINNER IS HP";
	if(big==can[2] && big>=1)
		cout<<"\nWINNER IS DELL";
	if(big==can[3] && big>=1)
		cout<<"\nWINNER IS SONY";
	if(big==can[4] && big>=1)
		cout<<"\nWINNER IS APPLE";
	cout<<"\nvotes are"<<big<<"\nmajority is "<<majority;
}
int main()
{
	clrscr();
	cout<<"\nEnter voter details:";
	voting v1;
	int j=0,close;
	clrscr();
	while(j!=1)
	{
		  v1.cast();
		  cout<<"\nenter 1 if voting is over else enter 0";
		  cin>>close;
		  if(close==1)
			j=1;
	}
	v1.count();
	v1.declare();
	getch();
	return 0;
}
