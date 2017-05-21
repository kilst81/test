
#include <iostream>
#include <random>

using namespace std ;

int getRandomNumber ( int min, int max )
{
	//< 1단계. 시드 설정
	random_device rn;
	/*
	mt19937_64 rnd( rn () );
	/*/
	default_random_engine rnd ( rn () );
	// */
	

	//< 2단계. 분포 설정 ( 정수 )
	uniform_int_distribution<int> dist0 ( min, max );
	bernoulli_distribution dist1 ( 0.3 );
	binomial_distribution<> dist2 ( 14, 0.2 );
	geometric_distribution<int> dist3 ( 0.7 );
	negative_binomial_distribution<> dist4 ( 2, 0.4 );
	poisson_distribution<int> dist5 ( 4.1 );
	exponential_distribution<> dist6 ( 1 );
	gamma_distribution<> dist7 ( 2.0, 2.0 );
	normal_distribution<double> dist8 ( 5.0, 2.0 );
	discrete_distribution<int> dist9 = { 18, 2000, 3000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 18, 2000, 3000, 10000, 10000, 10000, 10000, 10000, 10000, 10000 };

	discrete_distribution<int> dist10 = { 1, 2 };

	//< 3단계. 값 추출
	return dist10 ( rn );
}

int main ()
{
	int min = 0;
	int max = 10;

	int count0 = 0 ;
	int count1 = 0 ;

	for ( int i = 0 ; i < 10000; i++ ) {
		if ( getRandomNumber ( min, max ) ) {
			++count1 ;
		}
		else {
			++count0 ;
		}
		// cout << getRandomNumber ( min, max ) << endl;
	}

	cout << count0 << endl ;
	cout << count1 << endl ;


	return 0 ;
}

