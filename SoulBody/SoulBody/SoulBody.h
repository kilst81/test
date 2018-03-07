#pragma once

#include <vector>
#include <fstream>

using namespace std ;


enum ret
{
	_ok = 0,

	_sb_not_enough_exp,
	_sb_not_enough_soul,
	_sb_not_enough_body,
};

enum type_atom
{
	atom_velocity = 0,
	atom_perspicacity,
	atom_tenacity,
	atom_specificity,

	atom_force,
	atom_intelligence,
	atom_endurance,
	atom_grace,
};



class SB_EXP
{
private :
	static vector<unsigned __int64> s_vNeedEXP ;

public :
	static void LoadTable ( string path_ )
	{
		char inputString[255];
		char* output = nullptr ;
		ifstream inFile ( path_ );

		while ( ! inFile.eof () ) {
			inFile.getline ( inputString, 255 );

			char *ptr = nullptr ;

			ptr = strtok_s ( inputString, ",", &output ) ;

			do {
				s_vNeedEXP.push_back ( atoll ( ptr ) ) ;
				ptr = strtok_s ( NULL, ",", &output ) ;
			} while ( ptr ) ;
		}
	}
	static void Print ()
	{
		for ( auto it : s_vNeedEXP ) {
			cout << it << endl ;
		}
	}


private :
	unsigned __int64 m_nLiveEXP = { 0 } ;

public :
	void addEXP ( unsigned __int64 add_ )
	{
		m_nLiveEXP += add_ ;
	}

	bool useEXP ( int index_, int factor_ = 0 )
	{
		unsigned __int64 needEXP = getNeedEXP ( index_, factor_ ) ;

		if ( ! needEXP ) return false ;
		if ( m_nLiveEXP < needEXP ) return false ;
		
		m_nLiveEXP -= needEXP ;

		return true ;
	}

	void useEXP ( unsigned __int64 exp_ )
	{
		m_nLiveEXP -= exp_ ;
	}

	unsigned __int64 getNeedEXP ( int index_, int factor_ = 0 )
	{
		double factor = factor_ / 1000 ;
		unsigned __int64 needEXP = static_cast<unsigned __int64>( s_vNeedEXP[index_] - s_vNeedEXP[index_] * factor ) ;

		if ( m_nLiveEXP < needEXP ) return 0 ;

		return needEXP ;
	}


	void print ()
	{
		cout << "EXP : " << m_nLiveEXP << endl ;
	}

};

vector<unsigned __int64> SB_EXP::s_vNeedEXP ;

struct SB_Atom
{
	int nSoulUpCount = { 0 } ;
	int nBodyUpCount = { 0 } ;

	bool bSoul = false ;
	bool bBody = false ;
	int nSoul = { 0 } ;
	int nBody = { 0 } ;

	ret upSoul ( SB_EXP& exp_, int factor_ )
	{
		unsigned __int64 needEXP = exp_.getNeedEXP ( nSoulUpCount, factor_ ) ;
		if ( ! needEXP ) return ret::_sb_not_enough_exp ;

		if ( bSoul ) {
			if ( ! nBody ) return ret::_sb_not_enough_body ;
			bSoul = false ;

			--nBody ;
		}
		else {
			bSoul = true ;
		}

		exp_.useEXP ( needEXP ) ;

		++nSoul ;
		++nSoulUpCount ;

		return ret::_ok ;
	}

	ret upBody ( SB_EXP& exp_, int factor_ )
	{
		unsigned __int64 needEXP = exp_.getNeedEXP ( nBodyUpCount, factor_ ) ;
		if ( ! needEXP ) return ret::_sb_not_enough_exp ;

		if ( bBody ) {
			if ( ! nSoul ) return ret::_sb_not_enough_soul ;
			bBody = false ;

			--nSoul ;
		}
		else {
			bBody = true ;
		}

		exp_.useEXP ( needEXP ) ;

		++nBody ;
		++nBodyUpCount ;

		return ret::_ok ;
	}

	void print ( string soul_ = "SOUL", string body_ = "BODY" )
	{
		cout << "[" << soul_.c_str () << ": " ;
		cout.fill ( ' ' ) ;
		cout.width ( 3 ) ;
		cout << nSoul << " ] , [" << body_.c_str () << ": " ;
		cout.fill ( ' ' ) ;
		cout.width ( 3 ) ;
		cout << nBody << " ]" << " - " ;
		cout.fill ( ' ' ) ;
		cout.width ( 3 ) ;
		cout << nSoulUpCount << " , " ;
		cout.fill ( ' ' ) ;
		cout.width ( 3 ) ;
		cout << nBodyUpCount << endl ;
	}

};


enum type_skill
{
	skill_none,

	skill_fighter_smash, 
	skill_fighter_jump,
	skill_fighter_rage,

	skill_mage_fireball,
	skill_mage_arrow,
	skill_mage_icestorm,

	skill_rouge_shot,
	skill_rouge_guide,
	skill_rouge_quickshot,
};


struct SB_Skill
{
	type_atom	eType ;
	int			nLevel = { 0 } ;
};


class StatusAncestor
{
private :
	int m_velcity = { 0 } ;
	int m_percity = { 0 } ;
	int m_tencity = { 0 } ;
	int m_specity = { 0 } ;

	int m_force = { 0 } ;
	int m_intce = { 0 } ;
	int m_endce = { 0 } ;
	int m_grace = { 0 } ;

	map<type_skill, SB_Skill> m_mapSkill ;
};


class StatusSoulBody
{
private :
	SB_EXP	m_EXP ;
	int		m_nFactor = { 0 } ;
	SB_Atom m_velfor ;
	SB_Atom m_perint ;
	SB_Atom m_tenend ;
	SB_Atom m_spegra ;


public :
	void pushEXP ( unsigned __int64 exp_ ) { m_EXP.addEXP ( exp_ ) ; }

	ret upVelocity ()		{ return m_velfor.upSoul ( m_EXP, m_nFactor ) ; }
	ret upForce ()			{ return m_velfor.upBody ( m_EXP, m_nFactor ) ; }
	ret upPerspicacity ()	{ return m_perint.upSoul ( m_EXP, m_nFactor ) ; }
	ret upIntelligence ()	{ return m_perint.upBody ( m_EXP, m_nFactor ) ; }
	ret upTenacity ()		{ return m_tenend.upSoul ( m_EXP, m_nFactor ) ; }
	ret upEndurance ()		{ return m_tenend.upBody ( m_EXP, m_nFactor ) ; }
	ret upSpecificity ()	{ return m_spegra.upSoul ( m_EXP, m_nFactor ) ; }
	ret upGrace ()			{ return m_spegra.upBody ( m_EXP, m_nFactor ) ; }


	void print ()
	{
		cout << "----------------------------------" << endl ;
		m_EXP.print () ;
		cout << "----------------------------------" << endl ;
		m_velfor.print ( "Velcity", "Force" ) ;
		m_perint.print ( "Percity", "Intce" ) ;
		m_tenend.print ( "Tencity", "Endce" ) ;
		m_spegra.print ( "Specity", "Grace" ) ;
		cout << "==================================" << endl ;
	}

};

