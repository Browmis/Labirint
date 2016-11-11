#include <iostream>
#include <stack>

using namespace std;

class Point {
	public:
		Point(int I, int J) 
		{
			i = I;
			j = J;
		}

		int getI() {
			return i;
		}
		int getJ() {
			return j;
		}

	private:
		int i; //Свойство
		int j; //свойство
};
void fill_labirint(int **labirint, int size)
{
	for (int i = 0; i < size; i ++)
	{
		for (int j = 0; j < size; j ++)
		{
			if ( i % 2 != 0 && j % 2 != 0) 
				labirint[i][j] = 0;
			else
				labirint[i][j] = 1; 
		}
	}
}
void print (int **labirint, int size)
{
	for (int i = 0; i < size; i ++)
	{
		if (i % 2 == 0)
			for ( int j = 0; j < size; j ++)
			{
				if (labirint[i][j] != 0)
					cout << "-";
				else
					cout << " ";
			}
		else
			for ( int j = 0; j < size; j ++)
			{
				if (labirint[i][j] != 0)
					cout << "|";
				else
					cout << " ";
			}
		cout << endl;

	}
	
}

void generator (int **labirint, int n, stack<Point *> &Stack)
{




}


int main()
{
	int n = 3;
	int size = n * 2 + 1;
	int **labirint = new int* [2 * n + 1];
	for ( int i = 0; i < (2 * n + 1); i ++)
	{
		labirint[i] = new int [2 * n + 1];
	}
	stack <Point *> Stack; 
	Stack.push (new Point(1,1));
	fill_labirint(labirint, size);
	generator(labirint, n, Stack);
	print(labirint, size);
	return 0;
}

/*
marker		array
0000		1111111
0000		1010101					
0000		1111111
0000		1010101
0000		1111111	
			1010101	
			1111111		
			*/	

