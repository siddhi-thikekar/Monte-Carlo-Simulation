#include<bits/stdc++.h>
#include<math.h>

using namespace std;

#define N 10000						// Total Number of points in textfile.txt, dont change it!

float* get_my_file()				// Function to read textfile.txt
{
	float* a; 
	a = new float [N];
	fstream newfile;
	newfile.open("testfile.txt",ios::in);

   	if (newfile.is_open())
   	{   
		string tp;
		int i=0;
		while(getline(newfile, tp))
		{
			a[i]=stof(tp);
			i++;
		}
		newfile.close();
  	}
  	else
  	{
  		cout<<"File not read!!\n";
  	}

  return a;

}

void bollinger_bands(float* input)
{
	float mean[N],sd[N],ub,lb;
	int list[N],count=0;
	for(int i=0;i<10;i++)
	{
		mean[i]=0;
		sd[i]=0;
	}
	float sum=0;
	for(int i=0;i<10;i++)
	{
		sum=sum+input[i];
	}
	for(int i=9;i<N;i++)
	{
		mean[i]=sum/10;
		sum=sum-input[i-9]+input[i+1];
	}
	for(int i=9;i<N;i++)
	{
		sum=0;
		for(int j=0;j<10;j++)
		{
			sum =sum + pow((mean[i]-input[i-j]),2);
		}
		sd[i]=sqrt(sum/9);		
	}
	for(int i=9;i<N;i++)
	{
		lb=mean[i]-2*sd[i];
		ub=mean[i]+2*sd[i];
		if(input[i]<lb || input[i]>ub)
		  list[count++]=i+1;		   
	}	
	cout<<endl<<" Outlier list by Bollinger Bands method is given below:"<<endl;
    for(int i=0;i<count;i++)
     cout<< list[i]<<"  ";	
}
void slo(float* input)
{
	float slope[N],sum=0,mean,sd,ub,lb;
	slope[0]=0;
	for(int i=1;i<N;i++)
	{
		slope[i]=input[i]-input[i-1];
		sum=sum+slope[i];
	}
	mean=sum/N;
	sum=0;
	for(int i=0;i<N;i++)
	{
		sum=sum+pow((mean-slope[i]),2);		
	}
	sd=sqrt(sum/(N-1));
	ub=mean+3.5*sd;
	lb=mean-3.5*sd;
	int list[N],count=0;
	for(int i=0;i<N;i++)
	{
		if(input[i]<lb || input[i]>ub)
		 list[count++]=i+1;
	}
	
    cout<<endl<<endl<<" Outlier list by slope method is given below:"<<endl;
    for(int i=0;i<count;i++)
     cout<< list[i]<<"  ";
	
	
}

int main()
{
	float* input = get_my_file();
	// Uncomment the code below to check if the file is successfully printed to the console
	float* temp = input;
	for(int i = 0; i < N; i++)
	{
		cout<<*temp<<endl;
		temp++;
	}
	
	bollinger_bands(input);
	slo(input);
	return 0;
}
