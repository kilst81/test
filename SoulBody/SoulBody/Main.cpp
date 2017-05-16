

#include <iostream>
using namespace std ;

#include "SoulBody.h"


int main ()
{
	SB_Atom test ;

	char input ;

	while ( 1 ) {
		cin >> input ;

		switch ( input )
		{
		case '+':
			if ( ! test.upSoul () ) cout << "Fail Up" << endl ;
			break ;
		case '-':
			if ( ! test.upBody () ) cout << "Fail Up" << endl ;
			break ;
		}

		test.print () ;
	}

	return 0 ;
}