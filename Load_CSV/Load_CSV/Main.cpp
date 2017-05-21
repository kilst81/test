

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


class TableBase
{
private:
	table_character m_character ;

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
		load ( m_character, path_ + "\\table_character.CSV" ) ;

		/*
		string folder = path_ ;
		
		folder += "\\*.*" ;

		_finddata_t fd;
		intptr_t handle;
		int result = 1;
		handle = _findfirst ( folder.c_str (), &fd ) ;

		if ( handle == -1 ) {
			printf ( "There were no files.\n" );
			return 0 ;
		}

		while ( result != -1 ) {
			string path = path_ + "\\" ;
			string name = path + fd.name ;

			if ( string::npos != name.find ( "table_character" ) ) load ( m_character, name ) ;

			printf ( "File: %s\n", fd.name );
			result = _findnext ( handle, &fd );
		}

		_findclose ( handle );
		*/
	}

	void print ()
	{
		for ( auto& it : m_character.data ) {
			cout << it.second.index << " , " << it.second.type_race << " , " << it.second.type_nature << " , " << it.second.life << endl ;
		}
	}

};


int main ()
{
	TableBase base ;

	base.load ( "CSV" ) ;
	base.print () ;

	return 0 ;

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


	table_character testmake ;

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
		cout << it.second.index << " , " << it.second.type_race << " , " << it.second.type_nature << " , " << it.second.life << endl ;
	}

	cout << testmake[99].index << endl ;
	cout << testmake[98].index << endl ;
	cout << testmake[97].index << endl ;
	cout << testmake[96].index << endl ;

	return 0 ;
}


