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
		else if ( strstr ( typeid( _T_ ).name (), "bool" ) ) list_.emplace_back ( ( '0' == pstr_[0] ) ? 0 : 1 ) ;
		
		ptr = strtok ( NULL, "," ) ;
	}
}

template< class _T_ >
void _Push ( _T_& data_, char* pstr_ )
{
	if ( strstr ( typeid( _T_ ).name (), "int" ) ) data_ = ( pstr_ ) ? atoi ( pstr_ ) : 0 ;
	else if ( strstr ( typeid( _T_ ).name (), "float" ) ) data_ = ( pstr_ ) ? atof ( pstr_ ) : 0.0 ;
	else if ( strstr ( typeid( _T_ ).name (), "bool" ) ) data_ = ( '0' == pstr_[0] ) ? 0 : 1 ;
}

void _Push ( string& data_, char* pstr_ ) ;

struct table_Buff_data
{
	int Index ;
	enum_type_Buff type_Buff ;
	float Duration ;
	float Value ;
	int Stack ;
};

struct table_Buff
{
	map<int, table_Buff_data> data ;
	
	void add ( char* pstr_ )
	{
		table_Buff_data temp ;
		char* context = nullptr ;
		char* ptr = nullptr ;
		
		ptr = strtok_s ( pstr_, ",", &context ) ;
		_Push ( temp.Index, ptr ) ;
		if ( ',' == *context ) { temp.type_Buff = read_type_Buff::GetType ( ptr ) ; ++context ; }
		else { ptr = strtok_s ( NULL, ",", &context ) ; temp.type_Buff = read_type_Buff::GetType ( ptr ) ; }
		if ( ',' == *context ) { _Push ( temp.Duration, nullptr ) ; ++context ; }
		else { ptr = strtok_s ( NULL, ",", &context ) ; _Push ( temp.Duration, ptr ) ; }
		if ( ',' == *context ) { _Push ( temp.Value, nullptr ) ; ++context ; }
		else { ptr = strtok_s ( NULL, ",", &context ) ; _Push ( temp.Value, ptr ) ; }
		if ( ',' == *context ) { _Push ( temp.Stack, nullptr ) ; ++context ; }
		else { ptr = strtok_s ( NULL, ",", &context ) ; _Push ( temp.Stack, ptr ) ; }
		
		data[temp.Index] = temp ;
	}
	
	const table_Buff_data& operator [] ( int key_ )
	{
		map<int, table_Buff_data>::iterator it = data.find ( key_ ) ;
		
		return ( it == data.end () ) ? table_Buff_data () : it->second ;
	}
	
};

struct table_Building_data
{
	int Index ;
	string Desc ;
	enum_type_Team type_Team ;
	bool IsSwap ;
	bool IsAttack ;
	int EXP ;
	int Cool ;
	float ActiveTime ;
	float ActiveCool ;
};

struct table_Building
{
	map<int, table_Building_data> data ;
	
	void add ( char* pstr_ )
	{
		table_Building_data temp ;
		char* context = nullptr ;
		char* ptr = nullptr ;
		
		ptr = strtok_s ( pstr_, ",", &context ) ;
		_Push ( temp.Index, ptr ) ;
		if ( ',' == *context ) { _Push ( temp.Desc, nullptr ) ; ++context ; }
		else { ptr = strtok_s ( NULL, ",", &context ) ; _Push ( temp.Desc, ptr ) ; }
		if ( ',' == *context ) { temp.type_Team = read_type_Team::GetType ( ptr ) ; ++context ; }
		else { ptr = strtok_s ( NULL, ",", &context ) ; temp.type_Team = read_type_Team::GetType ( ptr ) ; }
		if ( ',' == *context ) { _Push ( temp.IsSwap, nullptr ) ; ++context ; }
		else { ptr = strtok_s ( NULL, ",", &context ) ; _Push ( temp.IsSwap, ptr ) ; }
		if ( ',' == *context ) { _Push ( temp.IsAttack, nullptr ) ; ++context ; }
		else { ptr = strtok_s ( NULL, ",", &context ) ; _Push ( temp.IsAttack, ptr ) ; }
		if ( ',' == *context ) { _Push ( temp.EXP, nullptr ) ; ++context ; }
		else { ptr = strtok_s ( NULL, ",", &context ) ; _Push ( temp.EXP, ptr ) ; }
		if ( ',' == *context ) { _Push ( temp.Cool, nullptr ) ; ++context ; }
		else { ptr = strtok_s ( NULL, ",", &context ) ; _Push ( temp.Cool, ptr ) ; }
		if ( ',' == *context ) { _Push ( temp.ActiveTime, nullptr ) ; ++context ; }
		else { ptr = strtok_s ( NULL, ",", &context ) ; _Push ( temp.ActiveTime, ptr ) ; }
		if ( ',' == *context ) { _Push ( temp.ActiveCool, nullptr ) ; ++context ; }
		else { ptr = strtok_s ( NULL, ",", &context ) ; _Push ( temp.ActiveCool, ptr ) ; }
		
		data[temp.Index] = temp ;
	}
	
	const table_Building_data& operator [] ( int key_ )
	{
		map<int, table_Building_data>::iterator it = data.find ( key_ ) ;
		
		return ( it == data.end () ) ? table_Building_data () : it->second ;
	}
	
};

struct table_BuildingStat_data
{
	int Index ;
	string Desc ;
	enum_type_Team type_Team ;
	int Point ;
	int State ;
	bool IsSwap ;
	bool IsAttack ;
	int Cool ;
	float ActiveTime ;
	float ActiveCool ;
	float HP ;
	float AD ;
	float DD ;
	float PD ;
	float AttackSpeed ;
	float AttackRange ;
};

struct table_BuildingStat
{
	map<int, table_BuildingStat_data> data ;
	
	void add ( char* pstr_ )
	{
		table_BuildingStat_data temp ;
		char* context = nullptr ;
		char* ptr = nullptr ;
		
		ptr = strtok_s ( pstr_, ",", &context ) ;
		_Push ( temp.Index, ptr ) ;
		if ( ',' == *context ) { _Push ( temp.Desc, nullptr ) ; ++context ; }
		else { ptr = strtok_s ( NULL, ",", &context ) ; _Push ( temp.Desc, ptr ) ; }
		if ( ',' == *context ) { temp.type_Team = read_type_Team::GetType ( ptr ) ; ++context ; }
		else { ptr = strtok_s ( NULL, ",", &context ) ; temp.type_Team = read_type_Team::GetType ( ptr ) ; }
		if ( ',' == *context ) { _Push ( temp.Point, nullptr ) ; ++context ; }
		else { ptr = strtok_s ( NULL, ",", &context ) ; _Push ( temp.Point, ptr ) ; }
		if ( ',' == *context ) { _Push ( temp.State, nullptr ) ; ++context ; }
		else { ptr = strtok_s ( NULL, ",", &context ) ; _Push ( temp.State, ptr ) ; }
		if ( ',' == *context ) { _Push ( temp.IsSwap, nullptr ) ; ++context ; }
		else { ptr = strtok_s ( NULL, ",", &context ) ; _Push ( temp.IsSwap, ptr ) ; }
		if ( ',' == *context ) { _Push ( temp.IsAttack, nullptr ) ; ++context ; }
		else { ptr = strtok_s ( NULL, ",", &context ) ; _Push ( temp.IsAttack, ptr ) ; }
		if ( ',' == *context ) { _Push ( temp.Cool, nullptr ) ; ++context ; }
		else { ptr = strtok_s ( NULL, ",", &context ) ; _Push ( temp.Cool, ptr ) ; }
		if ( ',' == *context ) { _Push ( temp.ActiveTime, nullptr ) ; ++context ; }
		else { ptr = strtok_s ( NULL, ",", &context ) ; _Push ( temp.ActiveTime, ptr ) ; }
		if ( ',' == *context ) { _Push ( temp.ActiveCool, nullptr ) ; ++context ; }
		else { ptr = strtok_s ( NULL, ",", &context ) ; _Push ( temp.ActiveCool, ptr ) ; }
		if ( ',' == *context ) { _Push ( temp.HP, nullptr ) ; ++context ; }
		else { ptr = strtok_s ( NULL, ",", &context ) ; _Push ( temp.HP, ptr ) ; }
		if ( ',' == *context ) { _Push ( temp.AD, nullptr ) ; ++context ; }
		else { ptr = strtok_s ( NULL, ",", &context ) ; _Push ( temp.AD, ptr ) ; }
		if ( ',' == *context ) { _Push ( temp.DD, nullptr ) ; ++context ; }
		else { ptr = strtok_s ( NULL, ",", &context ) ; _Push ( temp.DD, ptr ) ; }
		if ( ',' == *context ) { _Push ( temp.PD, nullptr ) ; ++context ; }
		else { ptr = strtok_s ( NULL, ",", &context ) ; _Push ( temp.PD, ptr ) ; }
		if ( ',' == *context ) { _Push ( temp.AttackSpeed, nullptr ) ; ++context ; }
		else { ptr = strtok_s ( NULL, ",", &context ) ; _Push ( temp.AttackSpeed, ptr ) ; }
		if ( ',' == *context ) { _Push ( temp.AttackRange, nullptr ) ; ++context ; }
		else { ptr = strtok_s ( NULL, ",", &context ) ; _Push ( temp.AttackRange, ptr ) ; }
		
		data[temp.Index] = temp ;
	}
	
	const table_BuildingStat_data& operator [] ( int key_ )
	{
		map<int, table_BuildingStat_data>::iterator it = data.find ( key_ ) ;
		
		return ( it == data.end () ) ? table_BuildingStat_data () : it->second ;
	}
	
};

struct table_CharacterStat_data
{
	int Index ;
	enum_type_Char type_Char ;
	enum_type_Team type_Team ;
	int LevelMax ;
	int Level ;
	float Size ;
	float Radius ;
	int AccrueExp ;
	float Sight ;
	int Rise ;
	float HP ;
	float HPRate ;
	float HPRegen ;
	float MP ;
	float MPRate ;
	float MPRegen ;
	float AD ;
	float AP ;
	float DD ;
	float PD ;
	float DDIgnore ;
	float PDIgnore ;
	float DDReduce ;
	float PDReduce ;
	float DDPierce ;
	float PDPierce ;
	float AttackSpeed ;
	float AttackRange ;
	float HitRadius ;
	float MoveSpeed ;
	float CoolTimeRate ;
	float CriticalRate ;
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
		if ( ',' == *context ) { temp.type_Char = read_type_Char::GetType ( ptr ) ; ++context ; }
		else { ptr = strtok_s ( NULL, ",", &context ) ; temp.type_Char = read_type_Char::GetType ( ptr ) ; }
		if ( ',' == *context ) { temp.type_Team = read_type_Team::GetType ( ptr ) ; ++context ; }
		else { ptr = strtok_s ( NULL, ",", &context ) ; temp.type_Team = read_type_Team::GetType ( ptr ) ; }
		if ( ',' == *context ) { _Push ( temp.LevelMax, nullptr ) ; ++context ; }
		else { ptr = strtok_s ( NULL, ",", &context ) ; _Push ( temp.LevelMax, ptr ) ; }
		if ( ',' == *context ) { _Push ( temp.Level, nullptr ) ; ++context ; }
		else { ptr = strtok_s ( NULL, ",", &context ) ; _Push ( temp.Level, ptr ) ; }
		if ( ',' == *context ) { _Push ( temp.Size, nullptr ) ; ++context ; }
		else { ptr = strtok_s ( NULL, ",", &context ) ; _Push ( temp.Size, ptr ) ; }
		if ( ',' == *context ) { _Push ( temp.Radius, nullptr ) ; ++context ; }
		else { ptr = strtok_s ( NULL, ",", &context ) ; _Push ( temp.Radius, ptr ) ; }
		if ( ',' == *context ) { _Push ( temp.AccrueExp, nullptr ) ; ++context ; }
		else { ptr = strtok_s ( NULL, ",", &context ) ; _Push ( temp.AccrueExp, ptr ) ; }
		if ( ',' == *context ) { _Push ( temp.Sight, nullptr ) ; ++context ; }
		else { ptr = strtok_s ( NULL, ",", &context ) ; _Push ( temp.Sight, ptr ) ; }
		if ( ',' == *context ) { _Push ( temp.Rise, nullptr ) ; ++context ; }
		else { ptr = strtok_s ( NULL, ",", &context ) ; _Push ( temp.Rise, ptr ) ; }
		if ( ',' == *context ) { _Push ( temp.HP, nullptr ) ; ++context ; }
		else { ptr = strtok_s ( NULL, ",", &context ) ; _Push ( temp.HP, ptr ) ; }
		if ( ',' == *context ) { _Push ( temp.HPRate, nullptr ) ; ++context ; }
		else { ptr = strtok_s ( NULL, ",", &context ) ; _Push ( temp.HPRate, ptr ) ; }
		if ( ',' == *context ) { _Push ( temp.HPRegen, nullptr ) ; ++context ; }
		else { ptr = strtok_s ( NULL, ",", &context ) ; _Push ( temp.HPRegen, ptr ) ; }
		if ( ',' == *context ) { _Push ( temp.MP, nullptr ) ; ++context ; }
		else { ptr = strtok_s ( NULL, ",", &context ) ; _Push ( temp.MP, ptr ) ; }
		if ( ',' == *context ) { _Push ( temp.MPRate, nullptr ) ; ++context ; }
		else { ptr = strtok_s ( NULL, ",", &context ) ; _Push ( temp.MPRate, ptr ) ; }
		if ( ',' == *context ) { _Push ( temp.MPRegen, nullptr ) ; ++context ; }
		else { ptr = strtok_s ( NULL, ",", &context ) ; _Push ( temp.MPRegen, ptr ) ; }
		if ( ',' == *context ) { _Push ( temp.AD, nullptr ) ; ++context ; }
		else { ptr = strtok_s ( NULL, ",", &context ) ; _Push ( temp.AD, ptr ) ; }
		if ( ',' == *context ) { _Push ( temp.AP, nullptr ) ; ++context ; }
		else { ptr = strtok_s ( NULL, ",", &context ) ; _Push ( temp.AP, ptr ) ; }
		if ( ',' == *context ) { _Push ( temp.DD, nullptr ) ; ++context ; }
		else { ptr = strtok_s ( NULL, ",", &context ) ; _Push ( temp.DD, ptr ) ; }
		if ( ',' == *context ) { _Push ( temp.PD, nullptr ) ; ++context ; }
		else { ptr = strtok_s ( NULL, ",", &context ) ; _Push ( temp.PD, ptr ) ; }
		if ( ',' == *context ) { _Push ( temp.DDIgnore, nullptr ) ; ++context ; }
		else { ptr = strtok_s ( NULL, ",", &context ) ; _Push ( temp.DDIgnore, ptr ) ; }
		if ( ',' == *context ) { _Push ( temp.PDIgnore, nullptr ) ; ++context ; }
		else { ptr = strtok_s ( NULL, ",", &context ) ; _Push ( temp.PDIgnore, ptr ) ; }
		if ( ',' == *context ) { _Push ( temp.DDReduce, nullptr ) ; ++context ; }
		else { ptr = strtok_s ( NULL, ",", &context ) ; _Push ( temp.DDReduce, ptr ) ; }
		if ( ',' == *context ) { _Push ( temp.PDReduce, nullptr ) ; ++context ; }
		else { ptr = strtok_s ( NULL, ",", &context ) ; _Push ( temp.PDReduce, ptr ) ; }
		if ( ',' == *context ) { _Push ( temp.DDPierce, nullptr ) ; ++context ; }
		else { ptr = strtok_s ( NULL, ",", &context ) ; _Push ( temp.DDPierce, ptr ) ; }
		if ( ',' == *context ) { _Push ( temp.PDPierce, nullptr ) ; ++context ; }
		else { ptr = strtok_s ( NULL, ",", &context ) ; _Push ( temp.PDPierce, ptr ) ; }
		if ( ',' == *context ) { _Push ( temp.AttackSpeed, nullptr ) ; ++context ; }
		else { ptr = strtok_s ( NULL, ",", &context ) ; _Push ( temp.AttackSpeed, ptr ) ; }
		if ( ',' == *context ) { _Push ( temp.AttackRange, nullptr ) ; ++context ; }
		else { ptr = strtok_s ( NULL, ",", &context ) ; _Push ( temp.AttackRange, ptr ) ; }
		if ( ',' == *context ) { _Push ( temp.HitRadius, nullptr ) ; ++context ; }
		else { ptr = strtok_s ( NULL, ",", &context ) ; _Push ( temp.HitRadius, ptr ) ; }
		if ( ',' == *context ) { _Push ( temp.MoveSpeed, nullptr ) ; ++context ; }
		else { ptr = strtok_s ( NULL, ",", &context ) ; _Push ( temp.MoveSpeed, ptr ) ; }
		if ( ',' == *context ) { _Push ( temp.CoolTimeRate, nullptr ) ; ++context ; }
		else { ptr = strtok_s ( NULL, ",", &context ) ; _Push ( temp.CoolTimeRate, ptr ) ; }
		if ( ',' == *context ) { _Push ( temp.CriticalRate, nullptr ) ; ++context ; }
		else { ptr = strtok_s ( NULL, ",", &context ) ; _Push ( temp.CriticalRate, ptr ) ; }
		
		data[temp.Index] = temp ;
	}
	
	const table_CharacterStat_data& operator [] ( int key_ )
	{
		map<int, table_CharacterStat_data>::iterator it = data.find ( key_ ) ;
		
		return ( it == data.end () ) ? table_CharacterStat_data () : it->second ;
	}
	
};

struct table_EXP_data
{
	int Index ;
	int EXP ;
	enum_type_EXP type_EXP ;
	float Distance ;
	float Rate ;
};

struct table_EXP
{
	map<int, table_EXP_data> data ;
	
	void add ( char* pstr_ )
	{
		table_EXP_data temp ;
		char* context = nullptr ;
		char* ptr = nullptr ;
		
		ptr = strtok_s ( pstr_, ",", &context ) ;
		_Push ( temp.Index, ptr ) ;
		if ( ',' == *context ) { _Push ( temp.EXP, nullptr ) ; ++context ; }
		else { ptr = strtok_s ( NULL, ",", &context ) ; _Push ( temp.EXP, ptr ) ; }
		if ( ',' == *context ) { temp.type_EXP = read_type_EXP::GetType ( ptr ) ; ++context ; }
		else { ptr = strtok_s ( NULL, ",", &context ) ; temp.type_EXP = read_type_EXP::GetType ( ptr ) ; }
		if ( ',' == *context ) { _Push ( temp.Distance, nullptr ) ; ++context ; }
		else { ptr = strtok_s ( NULL, ",", &context ) ; _Push ( temp.Distance, ptr ) ; }
		if ( ',' == *context ) { _Push ( temp.Rate, nullptr ) ; ++context ; }
		else { ptr = strtok_s ( NULL, ",", &context ) ; _Push ( temp.Rate, ptr ) ; }
		
		data[temp.Index] = temp ;
	}
	
	const table_EXP_data& operator [] ( int key_ )
	{
		map<int, table_EXP_data>::iterator it = data.find ( key_ ) ;
		
		return ( it == data.end () ) ? table_EXP_data () : it->second ;
	}
	
};

struct table_ItemDrop_data
{
	int Index ;
	int Code ;
	string Desc ;
	int ItemCode ;
	int Count ;
	float Rate ;
};

struct table_ItemDrop
{
	map<int, table_ItemDrop_data> data ;
	
	void add ( char* pstr_ )
	{
		table_ItemDrop_data temp ;
		char* context = nullptr ;
		char* ptr = nullptr ;
		
		ptr = strtok_s ( pstr_, ",", &context ) ;
		_Push ( temp.Index, ptr ) ;
		if ( ',' == *context ) { _Push ( temp.Code, nullptr ) ; ++context ; }
		else { ptr = strtok_s ( NULL, ",", &context ) ; _Push ( temp.Code, ptr ) ; }
		if ( ',' == *context ) { _Push ( temp.Desc, nullptr ) ; ++context ; }
		else { ptr = strtok_s ( NULL, ",", &context ) ; _Push ( temp.Desc, ptr ) ; }
		if ( ',' == *context ) { _Push ( temp.ItemCode, nullptr ) ; ++context ; }
		else { ptr = strtok_s ( NULL, ",", &context ) ; _Push ( temp.ItemCode, ptr ) ; }
		if ( ',' == *context ) { _Push ( temp.Count, nullptr ) ; ++context ; }
		else { ptr = strtok_s ( NULL, ",", &context ) ; _Push ( temp.Count, ptr ) ; }
		if ( ',' == *context ) { _Push ( temp.Rate, nullptr ) ; ++context ; }
		else { ptr = strtok_s ( NULL, ",", &context ) ; _Push ( temp.Rate, ptr ) ; }
		
		data[temp.Index] = temp ;
	}
	
	const table_ItemDrop_data& operator [] ( int key_ )
	{
		map<int, table_ItemDrop_data>::iterator it = data.find ( key_ ) ;
		
		return ( it == data.end () ) ? table_ItemDrop_data () : it->second ;
	}
	
};

struct table_PlayObject_data
{
	int Index ;
	string Desc ;
	enum_type_Work type_Work ;
	enum_type_PlayObject type_PlayObject ;
	float Radius ;
	int Value ;
	float ValueActive ;
	int LifeTime ;
	bool IsAttack ;
	float HP ;
	float AD ;
	float DD ;
	float PD ;
	float AttackSpeed ;
	float AttackRange ;
};

struct table_PlayObject
{
	map<int, table_PlayObject_data> data ;
	
	void add ( char* pstr_ )
	{
		table_PlayObject_data temp ;
		char* context = nullptr ;
		char* ptr = nullptr ;
		
		ptr = strtok_s ( pstr_, ",", &context ) ;
		_Push ( temp.Index, ptr ) ;
		if ( ',' == *context ) { _Push ( temp.Desc, nullptr ) ; ++context ; }
		else { ptr = strtok_s ( NULL, ",", &context ) ; _Push ( temp.Desc, ptr ) ; }
		if ( ',' == *context ) { temp.type_Work = read_type_Work::GetType ( ptr ) ; ++context ; }
		else { ptr = strtok_s ( NULL, ",", &context ) ; temp.type_Work = read_type_Work::GetType ( ptr ) ; }
		if ( ',' == *context ) { temp.type_PlayObject = read_type_PlayObject::GetType ( ptr ) ; ++context ; }
		else { ptr = strtok_s ( NULL, ",", &context ) ; temp.type_PlayObject = read_type_PlayObject::GetType ( ptr ) ; }
		if ( ',' == *context ) { _Push ( temp.Radius, nullptr ) ; ++context ; }
		else { ptr = strtok_s ( NULL, ",", &context ) ; _Push ( temp.Radius, ptr ) ; }
		if ( ',' == *context ) { _Push ( temp.Value, nullptr ) ; ++context ; }
		else { ptr = strtok_s ( NULL, ",", &context ) ; _Push ( temp.Value, ptr ) ; }
		if ( ',' == *context ) { _Push ( temp.ValueActive, nullptr ) ; ++context ; }
		else { ptr = strtok_s ( NULL, ",", &context ) ; _Push ( temp.ValueActive, ptr ) ; }
		if ( ',' == *context ) { _Push ( temp.LifeTime, nullptr ) ; ++context ; }
		else { ptr = strtok_s ( NULL, ",", &context ) ; _Push ( temp.LifeTime, ptr ) ; }
		if ( ',' == *context ) { _Push ( temp.IsAttack, nullptr ) ; ++context ; }
		else { ptr = strtok_s ( NULL, ",", &context ) ; _Push ( temp.IsAttack, ptr ) ; }
		if ( ',' == *context ) { _Push ( temp.HP, nullptr ) ; ++context ; }
		else { ptr = strtok_s ( NULL, ",", &context ) ; _Push ( temp.HP, ptr ) ; }
		if ( ',' == *context ) { _Push ( temp.AD, nullptr ) ; ++context ; }
		else { ptr = strtok_s ( NULL, ",", &context ) ; _Push ( temp.AD, ptr ) ; }
		if ( ',' == *context ) { _Push ( temp.DD, nullptr ) ; ++context ; }
		else { ptr = strtok_s ( NULL, ",", &context ) ; _Push ( temp.DD, ptr ) ; }
		if ( ',' == *context ) { _Push ( temp.PD, nullptr ) ; ++context ; }
		else { ptr = strtok_s ( NULL, ",", &context ) ; _Push ( temp.PD, ptr ) ; }
		if ( ',' == *context ) { _Push ( temp.AttackSpeed, nullptr ) ; ++context ; }
		else { ptr = strtok_s ( NULL, ",", &context ) ; _Push ( temp.AttackSpeed, ptr ) ; }
		if ( ',' == *context ) { _Push ( temp.AttackRange, nullptr ) ; ++context ; }
		else { ptr = strtok_s ( NULL, ",", &context ) ; _Push ( temp.AttackRange, ptr ) ; }
		
		data[temp.Index] = temp ;
	}
	
	const table_PlayObject_data& operator [] ( int key_ )
	{
		map<int, table_PlayObject_data>::iterator it = data.find ( key_ ) ;
		
		return ( it == data.end () ) ? table_PlayObject_data () : it->second ;
	}
	
};

struct table_PlayObjectDrop_data
{
	int Index ;
	int IndexBuilding ;
	int IndexPlayObject ;
	string Desc ;
	int Count ;
	float DropRate ;
};

struct table_PlayObjectDrop
{
	map<int, table_PlayObjectDrop_data> data ;
	
	void add ( char* pstr_ )
	{
		table_PlayObjectDrop_data temp ;
		char* context = nullptr ;
		char* ptr = nullptr ;
		
		ptr = strtok_s ( pstr_, ",", &context ) ;
		_Push ( temp.Index, ptr ) ;
		if ( ',' == *context ) { _Push ( temp.IndexBuilding, nullptr ) ; ++context ; }
		else { ptr = strtok_s ( NULL, ",", &context ) ; _Push ( temp.IndexBuilding, ptr ) ; }
		if ( ',' == *context ) { _Push ( temp.IndexPlayObject, nullptr ) ; ++context ; }
		else { ptr = strtok_s ( NULL, ",", &context ) ; _Push ( temp.IndexPlayObject, ptr ) ; }
		if ( ',' == *context ) { _Push ( temp.Desc, nullptr ) ; ++context ; }
		else { ptr = strtok_s ( NULL, ",", &context ) ; _Push ( temp.Desc, ptr ) ; }
		if ( ',' == *context ) { _Push ( temp.Count, nullptr ) ; ++context ; }
		else { ptr = strtok_s ( NULL, ",", &context ) ; _Push ( temp.Count, ptr ) ; }
		if ( ',' == *context ) { _Push ( temp.DropRate, nullptr ) ; ++context ; }
		else { ptr = strtok_s ( NULL, ",", &context ) ; _Push ( temp.DropRate, ptr ) ; }
		
		data[temp.Index] = temp ;
	}
	
	const table_PlayObjectDrop_data& operator [] ( int key_ )
	{
		map<int, table_PlayObjectDrop_data>::iterator it = data.find ( key_ ) ;
		
		return ( it == data.end () ) ? table_PlayObjectDrop_data () : it->second ;
	}
	
};

struct table_Skill_data
{
	int Index ;
	enum_type_Char type_Char ;
	int Level ;
	int MPCost ;
	float Power ;
	float APRate ;
};

struct table_Skill
{
	map<int, table_Skill_data> data ;
	
	void add ( char* pstr_ )
	{
		table_Skill_data temp ;
		char* context = nullptr ;
		char* ptr = nullptr ;
		
		ptr = strtok_s ( pstr_, ",", &context ) ;
		_Push ( temp.Index, ptr ) ;
		if ( ',' == *context ) { temp.type_Char = read_type_Char::GetType ( ptr ) ; ++context ; }
		else { ptr = strtok_s ( NULL, ",", &context ) ; temp.type_Char = read_type_Char::GetType ( ptr ) ; }
		if ( ',' == *context ) { _Push ( temp.Level, nullptr ) ; ++context ; }
		else { ptr = strtok_s ( NULL, ",", &context ) ; _Push ( temp.Level, ptr ) ; }
		if ( ',' == *context ) { _Push ( temp.MPCost, nullptr ) ; ++context ; }
		else { ptr = strtok_s ( NULL, ",", &context ) ; _Push ( temp.MPCost, ptr ) ; }
		if ( ',' == *context ) { _Push ( temp.Power, nullptr ) ; ++context ; }
		else { ptr = strtok_s ( NULL, ",", &context ) ; _Push ( temp.Power, ptr ) ; }
		if ( ',' == *context ) { _Push ( temp.APRate, nullptr ) ; ++context ; }
		else { ptr = strtok_s ( NULL, ",", &context ) ; _Push ( temp.APRate, ptr ) ; }
		
		data[temp.Index] = temp ;
	}
	
	const table_Skill_data& operator [] ( int key_ )
	{
		map<int, table_Skill_data>::iterator it = data.find ( key_ ) ;
		
		return ( it == data.end () ) ? table_Skill_data () : it->second ;
	}
	
};

class TableBase
{
public :
	table_Buff Buff ;
	table_Building Building ;
	table_BuildingStat BuildingStat ;
	table_CharacterStat CharacterStat ;
	table_EXP EXP ;
	table_ItemDrop ItemDrop ;
	table_PlayObject PlayObject ;
	table_PlayObjectDrop PlayObjectDrop ;
	table_Skill Skill ;
	
	template< class _T_ >
	void load ( _T_& table_, string file_ )
	{
		char inputString[1000] ;
		ifstream inFile ( file_ ) ;
		
		if ( ! inFile.eof () ) inFile.getline ( inputString, 1000 ) ; // type load
		if ( ! inFile.eof () ) inFile.getline ( inputString, 1000 ) ; // head load
		
		while ( ! inFile.eof () ) {
			inFile.getline ( inputString, 1000 ) ;
			if ( ! strlen ( inputString ) ) break ;
			
			table_.add ( inputString ) ;
		}
	}
	
	void load ( string path_ )
	{
		load ( Buff, path_ + "\\table_Buff.CSV" ) ;
		load ( Building, path_ + "\\table_Building.CSV" ) ;
		load ( BuildingStat, path_ + "\\table_BuildingStat.CSV" ) ;
		load ( CharacterStat, path_ + "\\table_CharacterStat.CSV" ) ;
		load ( EXP, path_ + "\\table_EXP.CSV" ) ;
		load ( ItemDrop, path_ + "\\table_ItemDrop.csv" ) ;
		load ( PlayObject, path_ + "\\table_PlayObject.csv" ) ;
		load ( PlayObjectDrop, path_ + "\\table_PlayObjectDrop.csv" ) ;
		load ( Skill, path_ + "\\table_Skill.CSV" ) ;
	}
};
