#pragma once

#include <string>
using namespace std ;

enum enum_type_Buff
{
	enum_type_Buff_none = 0,
	BUFF_SLOW_TYPE_A = 1,
	BUFF_KNOCKDOWN = 2,
	BUFF_AIR = 3,
	BUFF_SPEED_UP_BY_SERVER = 4,
	BUFF_KNOCKBACK = 5,
	BUFF_SHIELD = 6,
	BUFF_INVINCIBILITY = 7,
	BUFF_SLOW_TYPE_B = 8,
	BUFF_STUN_TYPE_A = 9,
	BUFF_ZERO_FLY_OBJECT = 10,
	BUFF_ATTACK_POWER_UP_1 = 11,
	BUFF_ATTACK_POWER_UP_2 = 12,
	BUFF_ATTACK_POWER_UP_3 = 13,
	BUFF_ATTACK_POWER_UP_4 = 14,
	BUFF_ATTACK_POWER_UP_5 = 15,
	BUFF_PUSH = 16,
	BUFF_PLASMA_EFFECT = 17,
	BUFF_RANDMARK_EFFECT = 18,
	BUFF_CONFUSION = 19,
	BUFF_DOT_HEAL = 20,
	BUFF_DKL_ANTI_DOT_HEAL = 21,
	BUFF_DKL_ANTI_DOT_DAMAGE = 22,
	BUFF_DKL_SLOW = 23,
	BUFF_DKL_SLOW_ATK = 24,
	BUFF_CMS_BUBBLE = 25,
};

struct read_type_Buff
{
	static enum_type_Buff GetType ( string type_ )
	{
		if ( ! type_.compare ( "BUFF_SLOW_TYPE_A" ) ) return BUFF_SLOW_TYPE_A ;
		if ( ! type_.compare ( "BUFF_KNOCKDOWN" ) ) return BUFF_KNOCKDOWN ;
		if ( ! type_.compare ( "BUFF_AIR" ) ) return BUFF_AIR ;
		if ( ! type_.compare ( "BUFF_SPEED_UP_BY_SERVER" ) ) return BUFF_SPEED_UP_BY_SERVER ;
		if ( ! type_.compare ( "BUFF_KNOCKBACK" ) ) return BUFF_KNOCKBACK ;
		if ( ! type_.compare ( "BUFF_SHIELD" ) ) return BUFF_SHIELD ;
		if ( ! type_.compare ( "BUFF_INVINCIBILITY" ) ) return BUFF_INVINCIBILITY ;
		if ( ! type_.compare ( "BUFF_SLOW_TYPE_B" ) ) return BUFF_SLOW_TYPE_B ;
		if ( ! type_.compare ( "BUFF_STUN_TYPE_A" ) ) return BUFF_STUN_TYPE_A ;
		if ( ! type_.compare ( "BUFF_ZERO_FLY_OBJECT" ) ) return BUFF_ZERO_FLY_OBJECT ;
		if ( ! type_.compare ( "BUFF_ATTACK_POWER_UP_1" ) ) return BUFF_ATTACK_POWER_UP_1 ;
		if ( ! type_.compare ( "BUFF_ATTACK_POWER_UP_2" ) ) return BUFF_ATTACK_POWER_UP_2 ;
		if ( ! type_.compare ( "BUFF_ATTACK_POWER_UP_3" ) ) return BUFF_ATTACK_POWER_UP_3 ;
		if ( ! type_.compare ( "BUFF_ATTACK_POWER_UP_4" ) ) return BUFF_ATTACK_POWER_UP_4 ;
		if ( ! type_.compare ( "BUFF_ATTACK_POWER_UP_5" ) ) return BUFF_ATTACK_POWER_UP_5 ;
		if ( ! type_.compare ( "BUFF_PUSH" ) ) return BUFF_PUSH ;
		if ( ! type_.compare ( "BUFF_PLASMA_EFFECT" ) ) return BUFF_PLASMA_EFFECT ;
		if ( ! type_.compare ( "BUFF_RANDMARK_EFFECT" ) ) return BUFF_RANDMARK_EFFECT ;
		if ( ! type_.compare ( "BUFF_CONFUSION" ) ) return BUFF_CONFUSION ;
		if ( ! type_.compare ( "BUFF_DOT_HEAL" ) ) return BUFF_DOT_HEAL ;
		if ( ! type_.compare ( "BUFF_DKL_ANTI_DOT_HEAL" ) ) return BUFF_DKL_ANTI_DOT_HEAL ;
		if ( ! type_.compare ( "BUFF_DKL_ANTI_DOT_DAMAGE" ) ) return BUFF_DKL_ANTI_DOT_DAMAGE ;
		if ( ! type_.compare ( "BUFF_DKL_SLOW" ) ) return BUFF_DKL_SLOW ;
		if ( ! type_.compare ( "BUFF_DKL_SLOW_ATK" ) ) return BUFF_DKL_SLOW_ATK ;
		if ( ! type_.compare ( "BUFF_CMS_BUBBLE" ) ) return BUFF_CMS_BUBBLE ;
		
		return enum_type_Buff_none ;
	}
};

enum enum_type_Char
{
	enum_type_Char_none = 0,
	ULTRA_MAN = 0,
	COSMOS = 1,
	GOMORA = 2,
	ZETTON = 3,
	ZERO = 4,
	MEPHILAS = 5,
	BELIAL = 6,
	MEBIUS = 7,
	TIGA = 8,
	DARKLUGIEL = 9,
};

struct read_type_Char
{
	static enum_type_Char GetType ( string type_ )
	{
		if ( ! type_.compare ( "ULTRA_MAN" ) ) return ULTRA_MAN ;
		if ( ! type_.compare ( "COSMOS" ) ) return COSMOS ;
		if ( ! type_.compare ( "GOMORA" ) ) return GOMORA ;
		if ( ! type_.compare ( "ZETTON" ) ) return ZETTON ;
		if ( ! type_.compare ( "ZERO" ) ) return ZERO ;
		if ( ! type_.compare ( "MEPHILAS" ) ) return MEPHILAS ;
		if ( ! type_.compare ( "BELIAL" ) ) return BELIAL ;
		if ( ! type_.compare ( "MEBIUS" ) ) return MEBIUS ;
		if ( ! type_.compare ( "TIGA" ) ) return TIGA ;
		if ( ! type_.compare ( "DARKLUGIEL" ) ) return DARKLUGIEL ;
		
		return enum_type_Char_none ;
	}
};

enum enum_type_EXP
{
	enum_type_EXP_none = 0,
	EXP_SOLO = 1,
	EXP_AREA = 2,
	EXP_ALL = 3,
};

struct read_type_EXP
{
	static enum_type_EXP GetType ( string type_ )
	{
		if ( ! type_.compare ( "EXP_SOLO" ) ) return EXP_SOLO ;
		if ( ! type_.compare ( "EXP_AREA" ) ) return EXP_AREA ;
		if ( ! type_.compare ( "EXP_ALL" ) ) return EXP_ALL ;
		
		return enum_type_EXP_none ;
	}
};

enum enum_type_PlayObject
{
	enum_type_PlayObject_none = 0,
	GOLD = 1,
	EXP = 2,
	POTION = 3,
	POTION_DOT = 4,
	TOWER = 5,
	HEAL = 6,
	OIL_TRUCK = 7,
	OIL_AREA = 8,
	SOL_HEAD = 9,
	OIL_CAN = 10,
	FIRE_BOTTLE = 11,
};

struct read_type_PlayObject
{
	static enum_type_PlayObject GetType ( string type_ )
	{
		if ( ! type_.compare ( "GOLD" ) ) return GOLD ;
		if ( ! type_.compare ( "EXP" ) ) return EXP ;
		if ( ! type_.compare ( "POTION" ) ) return POTION ;
		if ( ! type_.compare ( "POTION_DOT" ) ) return POTION_DOT ;
		if ( ! type_.compare ( "TOWER" ) ) return TOWER ;
		if ( ! type_.compare ( "HEAL" ) ) return HEAL ;
		if ( ! type_.compare ( "OIL_TRUCK" ) ) return OIL_TRUCK ;
		if ( ! type_.compare ( "OIL_AREA" ) ) return OIL_AREA ;
		if ( ! type_.compare ( "SOL_HEAD" ) ) return SOL_HEAD ;
		if ( ! type_.compare ( "OIL_CAN" ) ) return OIL_CAN ;
		if ( ! type_.compare ( "FIRE_BOTTLE" ) ) return FIRE_BOTTLE ;
		
		return enum_type_PlayObject_none ;
	}
};

enum enum_type_Team
{
	enum_type_Team_none = 0,
	ULTRA = 1,
	MONSTER = 2,
	NEUTRAL = 3,
	RANDOM = 4,
};

struct read_type_Team
{
	static enum_type_Team GetType ( string type_ )
	{
		if ( ! type_.compare ( "ULTRA" ) ) return ULTRA ;
		if ( ! type_.compare ( "MONSTER" ) ) return MONSTER ;
		if ( ! type_.compare ( "NEUTRAL" ) ) return NEUTRAL ;
		if ( ! type_.compare ( "RANDOM" ) ) return RANDOM ;
		
		return enum_type_Team_none ;
	}
};

enum enum_type_Work
{
	enum_type_Work_none = 0,
	INSTANT = 1,
	USE = 2,
	OBJECT = 3,
};

struct read_type_Work
{
	static enum_type_Work GetType ( string type_ )
	{
		if ( ! type_.compare ( "INSTANT" ) ) return INSTANT ;
		if ( ! type_.compare ( "USE" ) ) return USE ;
		if ( ! type_.compare ( "OBJECT" ) ) return OBJECT ;
		
		return enum_type_Work_none ;
	}
};

