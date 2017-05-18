#pragma once

#include <string>
using namespace std ;

enum enum_type_nature
{
	enum_type_nature_none = 0,
	MALE = 1,
	LADY = 2,
};

struct read_type_nature
{
	static enum_type_nature GetType ( string type_ )
	{
		if ( ! type_.compare ( "MALE" ) ) return MALE ;
		if ( ! type_.compare ( "LADY" ) ) return LADY ;
		
		return enum_type_nature_none ;
	}
};

enum enum_type_race
{
	enum_type_race_none = 0,
	HUMAN = 1,
	ELF = 2,
	DWARF = 3,
};

struct read_type_race
{
	static enum_type_race GetType ( string type_ )
	{
		if ( ! type_.compare ( "HUMAN" ) ) return HUMAN ;
		if ( ! type_.compare ( "ELF" ) ) return ELF ;
		if ( ! type_.compare ( "DWARF" ) ) return DWARF ;
		
		return enum_type_race_none ;
	}
};

