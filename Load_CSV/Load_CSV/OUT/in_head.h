#pragma once

#include "OUT\in_type.h"
#include <vector>
#include <map>

template< class _T_ >
void _Push ( vector<_T_>& list_, char* pstr_ )
{
	char *ptr = strtok ( pstr_, "," ) ;
	
	while ( ptr != NULL ) {
		if ( strstr ( typeid( _T_ ).name (), "int" ) ) list_.emplace_back ( atoi ( ptr ) ) ;
		else if ( strstr ( typeid( _T_ ).name (), "float" ) ) list_.emplace_back ( atof ( ptr ) ) ;
		
		ptr = strtok ( NULL, "," ) ;
	}
}

template< class _T_ >
void _Push ( _T_& data_, char* pstr_ )
{
	if ( strstr ( typeid( _T_ ).name (), "int" ) ) data_ = atoi ( pstr_ ) ;
	else if ( strstr ( typeid( _T_ ).name (), "float" ) ) data_ = atof ( pstr_ ) ;
}

void _Push ( string& data_, char* pstr_ )
{
	data_ = pstr_ ;
}

struct table_character_data
{
	int index ;
	enum_type_race type_race ;
	enum_type_nature type_nature ;
	int velcity ;
	int percity ;
	int tencity ;
	int specity ;
	int force ;
	int intce ;
	int endce ;
	int grace ;
	float life ;
};

struct table_character
{
	map<int, table_character_data> data ;
	
	void add ( char* pstr_ )
	{
		table_character_data temp ;
		char *ptr = nullptr ;
		
		ptr = strtok ( pstr_, "," ) ;
		_Push ( temp.index, ptr ) ;
		ptr = strtok ( NULL, "," ) ;
		temp.type_race = read_type_race::GetType ( ptr ) ;
		ptr = strtok ( NULL, "," ) ;
		temp.type_nature = read_type_nature::GetType ( ptr ) ;
		ptr = strtok ( NULL, "," ) ;
		_Push ( temp.velcity, ptr ) ;
		ptr = strtok ( NULL, "," ) ;
		_Push ( temp.percity, ptr ) ;
		ptr = strtok ( NULL, "," ) ;
		_Push ( temp.tencity, ptr ) ;
		ptr = strtok ( NULL, "," ) ;
		_Push ( temp.specity, ptr ) ;
		ptr = strtok ( NULL, "," ) ;
		_Push ( temp.force, ptr ) ;
		ptr = strtok ( NULL, "," ) ;
		_Push ( temp.intce, ptr ) ;
		ptr = strtok ( NULL, "," ) ;
		_Push ( temp.endce, ptr ) ;
		ptr = strtok ( NULL, "," ) ;
		_Push ( temp.grace, ptr ) ;
		ptr = strtok ( NULL, "," ) ;
		_Push ( temp.life, ptr ) ;
		
		data[temp.index] = temp ;
	}
	
	const table_character_data& operator [] ( int key_ )
	{
		map<int, table_character_data>::iterator it = data.find ( key_ ) ;
		
		return ( it == data.end () ) ? table_character_data () : it->second ;
	}
	
};

