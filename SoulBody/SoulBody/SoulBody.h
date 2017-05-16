#pragma once


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


struct SB_Atom
{
	bool bSoul = false ;
	bool bBody = false ;
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


struct SB_Data
{
	SB_Atom velfor ;
	SB_Atom perint ;
	SB_Atom tenend ;
	SB_Atom spegra ;
};


class SoulBody
{


};