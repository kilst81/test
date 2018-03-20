#pragma once

#include "in_type.h"
#include <vector>
#include <map>

template< class _T_ >
void _Push ( vector<_T_>& list_, char* pstr_ )
{
	if ( !pstr_ ) return ;
	char *ptr = strtok ( pstr_, "," ) ;
	
	while ( ptr != NULL ) {
		if ( strstr ( typeid( _T_ ).name (), "int" ) ) list_.emplace_back ( ( pstr_ ) ? atoi ( pstr_ ) : 0 ) ;
		else if ( strstr ( typeid( _T_ ).name (), "float" ) ) list_.emplace_back ( ( pstr_ ) ? atof ( pstr_ ) : 0.0 ) ;
		
		ptr = strtok ( NULL, "," ) ;
	}
}

template< class _T_ >
void _Push ( _T_& data_, char* pstr_ )
{
	if ( strstr ( typeid( _T_ ).name (), "int" ) ) data_ = ( pstr_ ) ? atoi ( pstr_ ) : 0 ;
	else if ( strstr ( typeid( _T_ ).name (), "float" ) ) data_ = ( pstr_ ) ? atof ( pstr_ ) : 0.0 ;
}

void _Push ( string& data_, char* pstr_ )
{
	data_ = pstr_ ;
}

struct table_CharacterStat_data
{
	int Index ;
	string Description ;
	int Size ;
	float Radious ;
	int AccrueExp ;
	int MaxHp ;
	int Atk ;
	float AtkSpeed ;
	float Speed ;
	float Sight ;
	int Recovery ;
};

struct table_CharacterStat
{
	map<int, table_CharacterStat_data> data ;
	
	void add ( char* pstr_ )
	{
		table_CharacterStat_data temp ;
		char* context = nullptr ;
		char* ptr = nullptr ;
		
		ptr = strtok_s ( pstr_, ",", &context ) ;
		_Push ( temp.Index, ptr ) ;
		if ( ',' == *context ) { _Push ( temp.Description, nullptr ) ; ++context ; }
		else { ptr = strtok_s ( NULL, ",", &context ) ; _Push ( temp.Description, ptr ) ; }
		if ( ',' == *context ) { _Push ( temp.Size, nullptr ) ; ++context ; }
		else { ptr = strtok_s ( NULL, ",", &context ) ; _Push ( temp.Size, ptr ) ; }
		if ( ',' == *context ) { _Push ( temp.Radious, nullptr ) ; ++context ; }
		else { ptr = strtok_s ( NULL, ",", &context ) ; _Push ( temp.Radious, ptr ) ; }
		if ( ',' == *context ) { _Push ( temp.AccrueExp, nullptr ) ; ++context ; }
		else { ptr = strtok_s ( NULL, ",", &context ) ; _Push ( temp.AccrueExp, ptr ) ; }
		if ( ',' == *context ) { _Push ( temp.MaxHp, nullptr ) ; ++context ; }
		else { ptr = strtok_s ( NULL, ",", &context ) ; _Push ( temp.MaxHp, ptr ) ; }
		if ( ',' == *context ) { _Push ( temp.Atk, nullptr ) ; ++context ; }
		else { ptr = strtok_s ( NULL, ",", &context ) ; _Push ( temp.Atk, ptr ) ; }
		if ( ',' == *context ) { _Push ( temp.AtkSpeed, nullptr ) ; ++context ; }
		else { ptr = strtok_s ( NULL, ",", &context ) ; _Push ( temp.AtkSpeed, ptr ) ; }
		if ( ',' == *context ) { _Push ( temp.Speed, nullptr ) ; ++context ; }
		else { ptr = strtok_s ( NULL, ",", &context ) ; _Push ( temp.Speed, ptr ) ; }
		if ( ',' == *context ) { _Push ( temp.Sight, nullptr ) ; ++context ; }
		else { ptr = strtok_s ( NULL, ",", &context ) ; _Push ( temp.Sight, ptr ) ; }
		if ( ',' == *context ) { _Push ( temp.Recovery, nullptr ) ; ++context ; }
		else { ptr = strtok_s ( NULL, ",", &context ) ; _Push ( temp.Recovery, ptr ) ; }
		
		data[temp.Index] = temp ;
	}
	
	const table_CharacterStat_data& operator [] ( int key_ )
	{
		map<int, table_CharacterStat_data>::iterator it = data.find ( key_ ) ;
		
		return ( it == data.end () ) ? table_CharacterStat_data () : it->second ;
	}
	
};

class TableBase
{
public :
	table_CharacterStat CharacterStat ;
	
	template< class _T_ >
	void load ( _T_& table_, string file_ )
	{
		char inputString[100] ;
		ifstream inFile ( file_ ) ;
		
		if ( ! inFile.eof () ) inFile.getline ( inputString, 100 ) ; // type load
		if ( ! inFile.eof () ) inFile.getline ( inputString, 100 ) ; // head load
		
		while ( ! inFile.eof () ) {
			inFile.getline ( inputString, 100 ) ;
			if ( ! strlen ( inputString ) ) break ;
			
			table_.add ( inputString ) ;
		}
	}
	
	void load ( string path_ )
	{
		load ( CharacterStat, path_ + "\\table_CharacterStat.CSV" ) ;
	}
};
