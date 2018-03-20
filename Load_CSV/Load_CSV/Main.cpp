

#include <fstream>
#include <iostream>

#include <stdio.h>
#include <io.h>
#include <conio.h>
#include <vector>
#include <map>

using namespace std ;

#define MAX_SIZE 1000

#include "OUT\in_head.h"

/*
class TableBase
{
public:
	table_buff character ;

public:
	template< class _T_ >
	void load ( _T_& table_, string file_ )
	{
		char inputString[MAX_SIZE];
		ifstream inFile ( file_ );

		if ( ! inFile.eof () ) inFile.getline ( inputString, 100 ); // type load
		if ( ! inFile.eof () ) inFile.getline ( inputString, 100 ); // head load

		while ( ! inFile.eof () ) {
			inFile.getline ( inputString, 100 );
			if ( ! strlen ( inputString ) ) break ;

			table_.add ( inputString ) ;
		}
	}

	void load ( string path_ )
	{
		load ( character, path_ + "\\table_character.CSV" ) ;
	}

	void print ()
	{
		for ( auto& it : character.data ) {
			cout << it.second.index << " , " << endl ;
		}
	}

};
*/

int main ()
{
	TableBase base ;

	base.load ( "CSV" ) ;

	return 0 ;

	/*
	_finddata_t fd;
	intptr_t handle;
	int result = 1;
	handle = _findfirst ( ".\\CSV\\*.*", &fd );  //현재 폴더 내 모든 파일을 찾는다.

	if ( handle == -1 ) {
		printf ( "There were no files.\n" );
		return 0 ;
	}

	while ( result != -1 ) {
		printf ( "File: %s\n", fd.name );
		result = _findnext ( handle, &fd );
	}

	_findclose ( handle );


	table_buff testmake ;

	char inputString[MAX_SIZE];
	cout << endl ;

	ifstream inFile ( "CSV\\table_character.CSV" );

	if ( ! inFile.eof () ) inFile.getline ( inputString, 100 );
	if ( ! inFile.eof () ) inFile.getline ( inputString, 100 );

	while ( ! inFile.eof () ) {
		inFile.getline ( inputString, 100 );
		if ( ! strlen ( inputString ) ) break ;

		testmake.add ( inputString ) ;
	}

	inFile.close ();

	for ( auto& it : testmake.data ) {
		cout << it.second.index << " , " << endl ;
	}

	cout << testmake[99].index << endl ;
	cout << testmake[98].index << endl ;
	cout << testmake[97].index << endl ;
	cout << testmake[96].index << endl ;

	return 0 ;
	*/
}


