#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<time.h>

using namespace std;

int main()
{
    int timesteps = 30;
    int volatility = 2;  //2 %
    int max_simulations = 5000;
    float starting_price = 600;
    float path[max_simulations][timesteps+1];
    // Timesteps + 1 is for the starting price at Day 0 to be at the start of every array
    /*Your Code Here*/

    int i, j;

    for (i=0; i < 5000; i++)
    {
        path[i][0] = 600;
    }

    srand(time(0));

    for (j=1; j < 31; j++)
    {
        for(i=0; i < 5000; i++)
        {
            float F = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/0.04));

            F = F - 0.02;
            path[i][j] = path[i][j-1]*(1 + F);
        }

    }


    /*You need to sample different paths using simulations and store them in a 2D array of Float type*/
    ofstream outputfile;
    outputfile.open("paths.txt");

    for(int i = 0; i<max_simulations; i++)
    {
        for(int j = 0; j<(timesteps+1); j++)
        {
            outputfile<<path[i][j]<<" ";
        }
        outputfile<<endl;
    }
    outputfile.close();


}
