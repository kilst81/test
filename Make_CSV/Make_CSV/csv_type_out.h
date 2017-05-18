#pragma once

#include <string>
using namespace std ;

enum enum_type_char
{
	enum_type_char_none = 0,
	CHAR_A = 100,
	CHAR_B = 200,
	CHAR_C = 300,
};

struct read_type_char
{
	static enum_type_char GetType ( char* pstr_ )
	{
		if ( ! strcmp ( pstr_, "CHAR_A" ) ) return CHAR_A ;
		if ( ! strcmp ( pstr_, "CHAR_B" ) ) return CHAR_B ;
		if ( ! strcmp ( pstr_, "CHAR_C" ) ) return CHAR_C ;

		return enum_type_char_none ;
	}
};
