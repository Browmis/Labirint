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
//тут хранится стенки
int labirint [n + 2][n + 2] =  {{1, 1, 1, 1, 1, 1, 1},
					  			{1, 0, 0, 1, 1, 1, 1},
					  			{1, 1, 0, 0, 0, 1, 1},
					  			{1, 1, 0, 0, 0, 1, 1},
					  			{1, 1, 0, 0, 0, 0, 1},
					  			{1, 1, 1, 1, 1, 0, 1},
					  			{1, 1, 1, 1, 1, 1, 1}};

// тут хранится были ли мы там
int marked [n+2][n+2] = 	{{1, 1, 1, 1, 1, 1, 1},
					  		{1, 0, 0, 0, 0, 0, 1},
					  		{1, 0, 0, 0, 0, 0, 1},
					  		{1, 0, 0, 0, 0, 0, 1},
					  		{1, 0, 0, 0, 0, 0, 1},
					  		{1, 0, 0, 0, 0, 0, 1},
					  		{1, 1, 1, 1, 1, 1, 1}};





//эта функиця выполняет ТОЛЬКО поиск в ширину
void bfs(queue <Point *> &Queue) {
	
	while(!Queue.empty()) {
		//cout << "while starting\n";
		//получаем первую точку в очереди
		Point *firstPoint = Queue.front();
		//получать кординаты firstpoint
		int i = firstPoint->getI() ;
		int j = firstPoint->getJ() ;
		
		//ищем всех соседей и добавляем в очередь
		for (int i1 = i - 1; i1 <= i + 1; i1 ++) {
			for (int j1 = j - 1; j1 <= j + 1; j1 ++) {
				
				//проверяем можно ли туда идти
				if ( ( i - i1) * ( j - j1) == 0 )
					// проверяем стенку
					if (labirint[i1][j1] == 0) {
						//cout << i1 << ", " << j1 << ", " << marked[i1][j1] << "-this is marked!!!!" << endl;
						//проверяем нет ли её в очереди
						if (marked[i1][j1] == 0) { //создаем экземпляр класса point 
							Point *newFound = new Point(i1, j1);
							//отмечаем точку
							marked[i1][j1] = 1;
							//cout << "we are in marked " << i1 << " " << j1 << endl;
							//добавляем точку в очередь
							Queue.push(newFound);
							cout << Queue.size() << endl ;
						}
					}
			}
		}
		//убираем первую точку в очереди
		Queue.pop();
	}

	
}


int main() {
	//добавляем стартовую точку в очередь
	Point startPoint(1, 1);
	queue<Point *> Queue;
	marked [1][1] = 1;
	//Указатели и ссылки
	Queue.push(&startPoint); 	//& - эта операция по вытаскиванию ссылки
								//(или адреса, или как на примере машины - номер машины)

	//запускаем поиск в ширину
	bfs (Queue ) ;
	if (marked[n][n] == true) 
		cout << "Yes"; 
	else
		cout << "No";

	
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