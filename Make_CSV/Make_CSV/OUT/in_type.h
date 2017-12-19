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

enum enum_type_GameItem
{
	enum_type_GameItem_none = 0,
	GOLD = 10001,
	GEM = 10002,
	UC = 10003,
	KEY = 10004,
	BOX_1 = 10005,
	BOX_2 = 10006,
	BOX_3 = 10007,
};

struct read_type_GameItem
{
	static enum_type_GameItem GetType ( string type_ )
	{
		if ( ! type_.compare ( "GOLD" ) ) return GOLD ;
		if ( ! type_.compare ( "GEM" ) ) return GEM ;
		if ( ! type_.compare ( "UC" ) ) return UC ;
		if ( ! type_.compare ( "KEY" ) ) return KEY ;
		if ( ! type_.compare ( "BOX_1" ) ) return BOX_1 ;
		if ( ! type_.compare ( "BOX_2" ) ) return BOX_2 ;
		if ( ! type_.compare ( "BOX_3" ) ) return BOX_3 ;
		
		return enum_type_GameItem_none ;
	}
};

enum enum_type_PlayItem
{
	enum_type_PlayItem_none = 0,
	PLAY_GOLD = 1,
	PLAY_EXP = 2,
	PLAY_HEAL = 3,
	PLAY_HEAL_DOT = 4,
	PLAY_TOWER = 5,
	PLAY_HEAL_INSTANT = 6,
};

struct read_type_PlayItem
{
	static enum_type_PlayItem GetType ( string type_ )
	{
		if ( ! type_.compare ( "PLAY_GOLD" ) ) return PLAY_GOLD ;
		if ( ! type_.compare ( "PLAY_EXP" ) ) return PLAY_EXP ;
		if ( ! type_.compare ( "PLAY_HEAL" ) ) return PLAY_HEAL ;
		if ( ! type_.compare ( "PLAY_HEAL_DOT" ) ) return PLAY_HEAL_DOT ;
		if ( ! type_.compare ( "PLAY_TOWER" ) ) return PLAY_TOWER ;
		if ( ! type_.compare ( "PLAY_HEAL_INSTANT" ) ) return PLAY_HEAL_INSTANT ;
		
		return enum_type_PlayItem_none ;
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
	NONE = 0,
	INSTANT = 1,
	USE = 2,
	USE_WAY = 3,
};

struct read_type_Work
{
	static enum_type_Work GetType ( string type_ )
	{
		if ( ! type_.compare ( "NONE" ) ) return NONE ;
		if ( ! type_.compare ( "INSTANT" ) ) return INSTANT ;
		if ( ! type_.compare ( "USE" ) ) return USE ;
		if ( ! type_.compare ( "USE_WAY" ) ) return USE_WAY ;
		
		return enum_type_Work_none ;
	}
};

