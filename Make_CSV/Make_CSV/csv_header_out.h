#pragma once

#include "csv_type_out.h"
#include <vector>
#include <map>

template< class _T_ >
void _Push ( vector<_T_>& list_, char* pstr_ )
{
	char *ptr = strtok ( pstr_, "," );

	while ( ptr != NULL ) {
		if ( strstr ( typeid( _T_ ).name (), "int" ) ) list_.emplace_back ( atoi ( ptr ) ) ;
		else if ( strstr ( typeid( _T_ ).name (), "float" ) ) list_.emplace_back ( atof ( ptr ) ) ;

		ptr = strtok ( NULL, "," );
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

struct table_info_data
{
	int index ;
	enum_type_char type_char ;
	int data_int ;
	string data_str ;
	float data_float ;
	vector<float> list ;
};

struct table_info
{
	map<int, table_info_data> data ;

	void add ( char* pstr_ )
	{
		table_info_data temp ;

		char *ptr = nullptr ;

		ptr = strtok ( pstr_, "," ) ;
		_Push ( temp.index, ptr ) ;

		ptr = strtok ( NULL, "," ) ;
		temp.type_char = read_type_char::GetType( ptr ) ;
		
		ptr = strtok ( NULL, "," ) ;
		_Push ( temp.data_int, ptr ) ;
		// temp.data_int = atoi ( ptr ) ;

		ptr = strtok ( NULL, "," ) ;
		_Push ( temp.data_str, ptr ) ;

		ptr = strtok ( NULL, "," ) ;
		temp.data_float = atof ( ptr ) ;

		ptr = strtok ( NULL, "\"" ) ;
		_Push ( temp.list, ptr ) ;

		data[temp.index] = temp ;
	}

	table_info_data& operator [] ( int idx_ )
	{
		return data[idx_] ;
	}
};

