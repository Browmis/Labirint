#include <iostream>

using namespace std ;

int q[1000]/* очередь*/ , t  , h , l[1000][1000] /*лабиринт*/ , n /*размер лабиринта*/ , height[1000] , width[1000] ;
bool u[1000][1000] ; //массив для хранения отмеченных точек 

void push ( int l ) //начало очереди
{
     q[t] = l ;
     t++ ;
}

int pop ()
{
    return q[h++] ;
}

int front ()
{
    return q[h] ;
}

int size ()
{
    return t-h ;
}

void clear ()
{
     t = 0 ;
     h = 0 ;
}

void bfs ( int l[1000][1000] ) //начало поиска
{
	int i = 0 , j = 0 , sh = 0 , vis = 0 , r1 = 0 , r2 = 0 , k ;
	push ( l[0][0] ) ;
	k = size() ;
	while ( k > 0 )
	{
		i = height[r1] ;
		j = width[r2] ;
		if ( l[i][j+1] == 0 && u[i][j+1] != true ) { push( l[i][j+1] ) ; sh++ ; width[sh] == j+1 ; }
		if ( l[i+1][j] == 0 && u[i+1][j] != true ) { push( l[i+1][j] ) ; vis++ ; height[vis] == i+1 ; }
		if ( l[i][j-1] == 0 && u[i][j-1] != true ) { push( l[i][j-1] ) ; sh++ ; width[sh] == j-1 ; }
		if ( l[i-1][j] == 0 && u[i-1][j] != true ) { push( l[i][j+1] ) ; vis++ ; height[vis] == i-1 ; }
		u[i][j] == true ;
		pop() ;
		k = size() ;
		r1++ ;
		r2++ ;
	}
}

int main()
{
	cin >> n ; //размер лабиринта
	for ( int i = 0 ; i < n ; i++ )
	{
		for ( int j = 0 ; j < n ; j++ )
		{
			u[i][j] == false ;
		}
	}
	for ( int i = 0 ; i < n ; i++ ) //стенка лабиринта
	{
		l[0][i] = 1 ;
		l[i][0] = 0 ;
		l[n-1][i] = 1 ;
		l[i][n-1] = 0 ;
	}
	for ( int i = 1 ; i < n-1 ; i++) //лабиринт (1 - стенка , 0 - проход )
	{
		for ( int j = 1 ; j < n-1 ;j++)
		{
			cin >> l[i][j] ;
		}
	}
	bfs(l);
	if ( u[n-2][n-2] == true) cout << "yes" ; else
	cout << "no" ;
	return 0 ;
}
