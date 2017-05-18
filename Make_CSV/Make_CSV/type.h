#pragma once

#include <string>
using namespace std ;

enum enum_type_char
{
	enum_type_char_none = 0,
	CHAR_X = 100,
	CHAR_Y = 200,
	CHAR_Z = 300,
};

struct read_type_char
{
	static enum_type_char GetType ( string type_ )
	{
		if ( ! type_.compare ( "CHAR_X" ) ) return CHAR_X ;
		if ( ! type_.compare ( "CHAR_Y" ) ) return CHAR_Y ;
		if ( ! type_.compare ( "CHAR_Z" ) ) return CHAR_Z ;
		
		return enum_type_char_none ;
	}
};

enum enum_type_make
{
	enum_type_make_none = 0,
	CHAR_X = 100,
	CHAR_Y = 200,
	CHAR_Z = 300,
	MAKE_11 = 11,
	MAKE_22 = 22,
	MAKE_33 = 33,
};

struct read_type_make
{
	static enum_type_make GetType ( string type_ )
	{
		if ( ! type_.compare ( "CHAR_X" ) ) return CHAR_X ;
		if ( ! type_.compare ( "CHAR_Y" ) ) return CHAR_Y ;
		if ( ! type_.compare ( "CHAR_Z" ) ) return CHAR_Z ;
		if ( ! type_.compare ( "MAKE_11" ) ) return MAKE_11 ;
		if ( ! type_.compare ( "MAKE_22" ) ) return MAKE_22 ;
		if ( ! type_.compare ( "MAKE_33" ) ) return MAKE_33 ;
		
		return enum_type_make_none ;
	}
};

enum enum_type_temp
{
	enum_type_temp_none = 0,
	CHAR_X = 100,
	CHAR_Y = 200,
	CHAR_Z = 300,
	MAKE_11 = 11,
	MAKE_22 = 22,
	MAKE_33 = 33,
	TEMP_AAA = 1243,
	TEMP_BBB = 54325,
	TEMP_CCC = 654,
	TEMP_DDD = 7567,
};

struct read_type_temp
{
	static enum_type_temp GetType ( string type_ )
	{
		if ( ! type_.compare ( "CHAR_X" ) ) return CHAR_X ;
		if ( ! type_.compare ( "CHAR_Y" ) ) return CHAR_Y ;
		if ( ! type_.compare ( "CHAR_Z" ) ) return CHAR_Z ;
		if ( ! type_.compare ( "MAKE_11" ) ) return MAKE_11 ;
		if ( ! type_.compare ( "MAKE_22" ) ) return MAKE_22 ;
		if ( ! type_.compare ( "MAKE_33" ) ) return MAKE_33 ;
		if ( ! type_.compare ( "TEMP_AAA" ) ) return TEMP_AAA ;
		if ( ! type_.compare ( "TEMP_BBB" ) ) return TEMP_BBB ;
		if ( ! type_.compare ( "TEMP_CCC" ) ) return TEMP_CCC ;
		if ( ! type_.compare ( "TEMP_DDD" ) ) return TEMP_DDD ;
		
		return enum_type_temp_none ;
	}
};

