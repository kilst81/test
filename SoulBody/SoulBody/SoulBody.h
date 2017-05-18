#pragma once

#include <vector>
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


struct SB_NeedEXP
{
	int Index = {} ;
	vector<unsigned __int64> EXP ;
};


struct SB_Atom
{
	bool bSoul = false ;
	bool bBody = false ;
	int nSoulNeedIndex ;
	int nBodyNeedIndex ;
	vector<unsigned __int64> vSoulNeedEXP ;
	vector<unsigned __int64> vBodyNeedEXP ;
	unsigned __int64 nSoulNeedEXP = { 1000 } ;
	unsigned __int64 nBodyNeedEXP = { 1000 } ;
	int nSoul = { 0 } ;
	int nBody = { 0 } ;

	bool upSoul ()
	{
		if ( bSoul ) {
			if ( ! nBody ) return false ;
			bSoul = false ;

			--nBody ;
		}
		else {
			bSoul = true ;
		}

		++nSoul ;

		return true ;
	}

	bool upBody ()
	{
		if ( bBody ) {
			if ( ! nSoul ) return false ;
			bBody = false ;

			--nSoul ;
		}
		else {
			bBody = true ;
		}

		++nBody ;

		return true ;
	}

	void print ()
	{
		cout << "[SOUL: " << nSoul << " ] , [BODY: " << nBody << " ]" << endl ;
	}

};


class StatusSoulBody
{
	unsigned __int64 EXP = {} ;
	SB_Atom velfor ;
	SB_Atom perint ;
	SB_Atom tenend ;
	SB_Atom spegra ;

	bool upVelocity ()		{ return velfor.upSoul () ; }
	bool upForce ()			{ return velfor.upBody () ; }

	bool upPerspicacity ()	{ return perint.upSoul () ; }
	bool upIntelligence ()	{ return perint.upBody () ; }

	bool upTenacity ()		{ return tenend.upSoul () ; }
	bool upEndurance ()		{ return tenend.upBody () ; }

	bool upSpecificity ()	{ return spegra.upSoul () ; }
	bool upGrace ()			{ return spegra.upBody () ; }



};