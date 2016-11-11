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
		int getI() 
		{
			return i;
		}
		int getJ() 
		{
			return j;
		}
		Point *getTop ()
		{
			return new Point(i - 2, j);
		}
		Point *getBottom ()
		{
			return new Point(i + 2, j);
		}
		Point *getLeft ()
		{
			return new Point(i, j - 2);
		}
		Point *getRight ()
		{
			return new Point(i, j + 2);	
		}
		void print()
		{
			cout <<i<<" "<<j<<endl;
		}


	private:
		int i; //Свойство
		int j; //свойство
};
//проверяет есть ли заданая точка в лабиринте
bool check (int size, Point *point)
{
	int i = point->getI();
	int j = point->getJ();
	if (i < 0 ) return false;
	if (j < 0 ) return false;
	if (i > size ) return false;
	if (j > size ) return false;
	return true;
}

void fillLabirint(int **labirint, int size)
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


//нужно получить соседнюю точку 
//есле нету соседа возвращаем ту же точку
Point *getNeighbor (int **labirint, int size, Point *current)
{
	Point *top = current->getTop();
	if (check(size, top)) 
		if (labirint[top->getI()][top->getJ()] == 0)
		{
			return top;
		}
	Point *bottom = current->getBottom();
	if (check(size, bottom)) 
		if (labirint[bottom->getI()][bottom->getJ()] == 0)
		{
			return bottom;
		}
	Point *left = current->getLeft();
	if (check(size, left)) 
		if (labirint[left->getI()][left->getJ()] == 0)
		{
			return left;
		}
	Point *right = current->getRight();
	if (check(size, right)) 
		if (labirint[right->getI()][right->getJ()] == 0)
		{
			return right;
		}
	return current;
}

bool equals(Point *a, Point *b)
{
	if (a->getI() != b->getI())
		return false;
	if (a->getJ() != b->getJ())
		return false;
	return true;
}
void breakWall (int **labirint, Point *a, Point *b)
{
	a->print();
	b->print();
	int i = (a->getI() + b->getI()) / 2;
	int j = (a->getJ() + b->getJ()) / 2;
	cout <<"\t"<<i<<" "<<j<<endl;
	labirint[i][j] = 0;
}

void dfs (int **labirint, int size, stack<Point *> &Stack)
{
	Point *currentPoint = Stack.top();
	while ( !Stack.empty() )
	{
		currentPoint = Stack.top();
		//отмечаем текущею точку
		labirint[currentPoint->getI()][currentPoint->getJ()] = 1;
		//убираем текущею точку из стека
		Stack.pop();
		//добавляем всех соседей в стек
		while( !equals(currentPoint, getNeighbor(labirint, size, currentPoint)))
		{
			Stack.push(getNeighbor(labirint, size, currentPoint));
			labirint[Stack.top()->getI()][Stack.top()->getJ()] = 2;
		}
		breakWall(labirint, currentPoint, Stack.top());
	}

}


int main()
{
	int n = 3;
	int size = n * 2 + 1;
	int **labirint = new int* [size];
	for ( int i = 0; i < (size); i ++)
	{
		labirint[i] = new int [size];
	}
	stack <Point *> Stack;
	Stack.push (new Point(1,1));
	fillLabirint(labirint, size);
	dfs(labirint, size, Stack);
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

