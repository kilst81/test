

#include <iostream>
#include <random>
#include <map>
#include <thread>
#include <mutex>

using namespace std ;


#include <windows.h>

void ClearScreen ()
{
	HANDLE                     hStdOut;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD                      count;
	DWORD                      cellCount;
	COORD                      homeCoords = { 0, 0 };

	hStdOut = GetStdHandle ( STD_OUTPUT_HANDLE );
	if ( hStdOut == INVALID_HANDLE_VALUE ) return;

	/* Get the number of cells in the current buffer */
	if ( !GetConsoleScreenBufferInfo ( hStdOut, &csbi ) ) return;
	cellCount = csbi.dwSize.X *csbi.dwSize.Y;

	/* Fill the entire buffer with spaces */
	if ( !FillConsoleOutputCharacter (
		hStdOut,
		( TCHAR ) ' ',
		cellCount,
		homeCoords,
		&count
	) ) return;

	/* Fill the entire buffer with the current colors and attributes */
	if ( !FillConsoleOutputAttribute (
		hStdOut,
		csbi.wAttributes,
		cellCount,
		homeCoords,
		&count
	) ) return;

	/* Move the cursor home */
	SetConsoleCursorPosition ( hStdOut, homeCoords );
}



#include "SoulBody.h"

int getChoice ()
{
	//< 1단계. 시드 설정
	random_device rn;
	/*
	mt19937_64 rnd( rn () );
	/*/
	default_random_engine rnd ( rn () );
	// */

	discrete_distribution<int> dist = { 10, 1, 10, 1, 1, 1, 1, 1 };

	//< 3단계. 값 추출
	return dist ( rn );
}

void upSoulBody ( StatusSoulBody& object_, int choice_ )
{
	switch ( choice_ ) {
	case 0: object_.upVelocity () ; break ;
	case 1: object_.upPerspicacity () ; break ;
	case 2: object_.upTenacity () ; break ;
	case 3: object_.upSpecificity () ; break ;

	case 4: object_.upForce () ; break ;
	case 5: object_.upIntelligence () ; break ;
	case 6: object_.upEndurance () ; break ;
	case 7: object_.upGrace () ; break ;
	}
}

// std::map<std::string, std::string> g_pages;
StatusSoulBody test ;
std::mutex g_pages_mutex;

void up_exp ()
{
	while ( 1 ) {
		// std::this_thread::sleep_for ( std::chrono::seconds ( 1 ) );

		g_pages_mutex.lock () ;
		test.pushEXP ( 1000 ) ;
		g_pages_mutex.unlock () ;
	}
}

void up_soulbody ()
{
	while ( 1 ) {
		// std::this_thread::sleep_for ( std::chrono::seconds ( 1 ) );

		g_pages_mutex.lock () ;
		upSoulBody ( test, getChoice () ) ;
		g_pages_mutex.unlock () ;

		ClearScreen () ;
		test.print () ;
	}
}


int main ()
{
	SB_EXP::LoadTable ( "EXPTable.csv" ) ;
	// SB_EXP::Print () ;

	std::thread t1 ( up_exp ) ;
	std::thread t2 ( up_soulbody ) ;
	t1.join () ;
	t2.join () ;


	

	/*
	char input ;
	while ( 1 ) {
		cin >> input ;

		switch ( input )
		{
		case '+':
			test.upVelocity () ;
			break ;
		case '-':
			test.upForce () ;
			break ;
		case '*':
			test.pushEXP ( 1000000 ) ;
			break ;
		}

		test.print () ;
	}
	*/

	return 0 ;
}
