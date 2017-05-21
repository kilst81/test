#pragma once

#include <vector>
#include <fstream>

using namespace std ;


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

	bool upSoul ( SB_EXP& exp_, int factor_ )
	{
		unsigned __int64 needEXP = exp_.getNeedEXP ( nSoulUpCount, factor_ ) ;
		if ( ! needEXP ) return false ;

		if ( bSoul ) {
			if ( ! nBody ) return false ;
			bSoul = false ;

			--nBody ;
		}
		else {
			bSoul = true ;
		}

		exp_.useEXP ( needEXP ) ;

		++nSoul ;
		++nSoulUpCount ;

		return true ;
	}

	bool upBody ( SB_EXP& exp_, int factor_ )
	{
		unsigned __int64 needEXP = exp_.getNeedEXP ( nBodyUpCount, factor_ ) ;
		if ( ! needEXP ) return false ;

		if ( bBody ) {
			if ( ! nSoul ) return false ;
			bBody = false ;

			--nSoul ;
		}
		else {
			bBody = true ;
		}

		exp_.useEXP ( needEXP ) ;

		++nBody ;
		++nBodyUpCount ;

		return true ;
	}

	void print ()
	{
		cout << "[SOUL: " << nSoul << " ] , [BODY: " << nBody << " ]" << " - " << nSoulUpCount << " , " << nBodyUpCount << endl ;
	}

};


struct SB_Skill
{
	int nIndex = { 0 } ;
	int nLevel = { 0 } ;
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

	map<int, int> m_mapSkill ;
};


class StatusSoulBody
{
private :
	SB_EXP m_EXP ;
	int m_nFactor = { 0 } ;
	SB_Atom m_velfor ;
	SB_Atom m_perint ;
	SB_Atom m_tenend ;
	SB_Atom m_spegra ;

public :
	void pushEXP ( unsigned __int64 exp_ ) { m_EXP.addEXP ( exp_ ) ; }

	bool upVelocity ()		{ return m_velfor.upSoul ( m_EXP, m_nFactor ) ; }
	bool upForce ()			{ return m_velfor.upBody ( m_EXP, m_nFactor ) ; }
	
	bool upPerspicacity ()	{ return m_perint.upSoul ( m_EXP, m_nFactor) ; }
	bool upIntelligence ()	{ return m_perint.upBody ( m_EXP, m_nFactor ) ; }
	
	bool upTenacity ()		{ return m_tenend.upSoul ( m_EXP, m_nFactor ) ; }
	bool upEndurance ()		{ return m_tenend.upBody ( m_EXP, m_nFactor ) ; }
	
	bool upSpecificity ()	{ return m_spegra.upSoul ( m_EXP, m_nFactor ) ; }
	bool upGrace ()			{ return m_spegra.upBody ( m_EXP, m_nFactor ) ; }


	void print ()
	{
		cout << "----------------------------------" << endl ;
		m_EXP.print () ;
		cout << "----------------------------------" << endl ;
		m_velfor.print () ;
		m_perint.print () ;
		m_tenend.print () ;
		m_spegra.print () ;
		cout << "==================================" << endl ;
	}

};