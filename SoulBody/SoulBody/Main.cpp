

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

	discrete_distribution<int> dist = { 3, 1, 3, 1, 1, 2, 1, 2 };

	//< 3단계. 값 추출
	return dist ( rn );
}

int upSoulBody ( StatusSoulBody& object_, int choice_ )
{
	ret result ;

	switch ( choice_ ) {
	case 0: result = object_.upVelocity () ;	 break ;
	case 1: result = object_.upPerspicacity () ; break ;
	case 2: result = object_.upTenacity () ;	 break ;
	case 3: result = object_.upSpecificity () ;	 break ;
	case 4: result = object_.upForce () ;		 break ;
	case 5: result = object_.upIntelligence () ; break ;
	case 6: result = object_.upEndurance () ;	 break ;
	case 7: result = object_.upGrace () ;		 break ;
	}

	if ( ret::_ok == result ) return -1 ;

	switch ( choice_ ) {
	case 0: return ( ret::_sb_not_enough_body == result ) ? 4 : 0 ;
	case 1: return ( ret::_sb_not_enough_body == result ) ? 5 : 1 ;
	case 2: return ( ret::_sb_not_enough_body == result ) ? 6 : 2 ;
	case 3: return ( ret::_sb_not_enough_body == result ) ? 7 : 3 ;
	case 4: return ( ret::_sb_not_enough_soul == result ) ? 0 : 4 ;
	case 5: return ( ret::_sb_not_enough_soul == result ) ? 1 : 5 ;
	case 6: return ( ret::_sb_not_enough_soul == result ) ? 2 : 6 ;
	case 7: return ( ret::_sb_not_enough_soul == result ) ? 3 : 7 ;
	}
}

// std::map<std::string, std::string> g_pages;
StatusSoulBody test ;
std::mutex g_pages_mutex;

void up_exp ()
{
	int nSecondGoal = 60 * 24;
	int nSecond = 0;
	while ( 1 ) {
		if (nSecond++ == nSecondGoal) break;
		std::this_thread::sleep_for ( std::chrono::seconds ( 1 ) );

		g_pages_mutex.lock () ;
		test.pushEXP ( 1000000 ) ;
		g_pages_mutex.unlock () ;
	}
}

void up_soulbody ()
{
	int nChoice = -1 ;
	while ( 1 ) {
		std::this_thread::sleep_for ( std::chrono::milliseconds ( 100 ) );
		if ( -1 == nChoice ) nChoice = getChoice () ;

		g_pages_mutex.lock () ;
		nChoice = upSoulBody ( test, nChoice ) ;
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
