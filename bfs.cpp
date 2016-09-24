#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <queue>
#include <string>

using namespace std;

class Point {
	public:
		Point(int I, int J) {
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


//Блок переменных
const int n = 5;//Размер матрицы

int labirint [n + 2][n + 2] =  {{1, 1, 1, 1, 1, 1, 1},
					  			{1, 0, 0, 1, 1, 1, 1},
					  			{1, 1, 0, 0, 0, 1, 1},
					  			{1, 1, 0, 0, 0, 1, 1},
					  			{1, 1, 0, 0, 0, 0, 1},
					  			{1, 1, 1, 1, 1, 0, 1},
					  			{1, 1, 1, 1, 1, 1, 1}};


bool marked [n+2][n+2] ;


queue<Point *> Queue;


//эта функиця выполняет ТОЛЬКО поиск в ширину
void bfs() {

	
	while(!Queue.empty()) {
		//получаем первую точку в очереди
		Point *firstPoint = Queue.front();
		//ищем всех соседей и добавляем в очередь
		for ( int i1 = -1 ; i < n+2 ; i1++ )
		{
			for ( int j1 = -1 ; j < n+2 ; j1++)
			{
				if ( ( i - i1 ) * ( j - j1 ) == 0)
				{
					if ( labirint [i1][j1] == 0)
					{
						if ( marked [i1][j1] == 0 )
						{
							Queue.push(&firstPoint) ;
						}
					}
				}
			}
		}
		//отмечаем первую точку в массиве marked как помеченную
		marked [i][j] = 1 ;
		//убираем первую точку в очереди
		Queue.pop(&firstPoint) ;;

	}

	
}


int main() {
	//добавляем стартовую точку в очередь
	Point startPoint(0, 0);

	//Указатели и ссылки
	Queue.push(&startPoint); 	//& - эта операция по вытаскиванию ссылки
								//(или адреса, или как на примере машины - номер машины)

	//запускаем поиск в ширину
	bfs();
	
	return 0;
}

/**
5x5     marked 
стенка
1111111
1001111   11000
1100011   00000
1100011   00000
1100001   00000
1111101   00000
1111111   

queue = массив точек
[
	{i:1, j:1},

]











*/