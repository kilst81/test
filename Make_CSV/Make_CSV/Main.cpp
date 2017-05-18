

#include <fstream>
#include <iostream>

#include <stdio.h>
#include <io.h>
#include <conio.h>
#include <vector>
#include <map>

using namespace std ;

#define MAX_SIZE 1000


class ReadTable
{
private:
	struct _read_table
	{
		vector<string> row ;
	};

	string m_FileName ;
	string m_TableName ;
	
	_read_table m_Type ;
	_read_table m_Head ;
	vector<_read_table> m_Data ;

public:
	string getFileName () const { return m_FileName ; }
	string getTableName () const { return m_TableName ; }

public:
	void setFileName ( string filename_ )
	{
		m_FileName = filename_ ;

		string::size_type pos = m_FileName.find ( "." ) ;

		m_TableName = m_FileName.substr ( 0, pos ) ;
	}

	void _read ( _read_table& table_, char* pstr_ )
	{
		char *ptr = strtok ( pstr_, "," );

		while ( ptr != NULL ) {
			table_.row.emplace_back ( ptr ) ;
			ptr = strtok ( NULL, "," );
		}
	}

	void read ( string filename_ )
	{
		char inputString[MAX_SIZE];
		cout << endl ;
		ifstream inFile ( filename_ );

		if ( ! inFile.eof () ) inFile.getline ( inputString, 100 );
		_read ( m_Type, inputString ) ;

		if ( ! inFile.eof () ) inFile.getline ( inputString, 100 );
		_read ( m_Head, inputString ) ;

		print () ;

		inFile.close ();
	}

	void print ()
	{
		cout << "FileName : " << m_FileName.c_str () << endl ;

		cout << "Type spec" << endl ;
		for ( auto it : m_Type.row ) {
			cout.fill ( ' ' ) ;
			cout.width ( 16 ) ;
			cout << it.c_str () ;
		}
		cout << endl ;

		cout << "Head spec" << endl ;
		for ( auto it : m_Head.row ) {
			cout.fill ( ' ' ) ;
			cout.width ( 16 ) ;
			cout << it.c_str () ;
		}
		cout << endl ;
	}

	friend ofstream& operator << ( ofstream& lhs_, const ReadTable& rhs_ )
	{
		/*
		struct table_info_data
		{
			int index ;
			enum_type_char type_char ;
			int data_int ;
			string data_str ;
			float data_float ;
			vector<float> list ;
		};
		*/

		string table_data = rhs_.getTableName () ;
		table_data += "_data" ;
		lhs_ << "struct " << table_data.c_str () << endl ;
		lhs_ << "{" << endl ;

		for ( int nI = 0 ; nI < rhs_.m_Type.row.size () ; ++nI ) {
			if ( strcmp( rhs_.m_Type.row[nI].c_str (), "enum" ) ) {
				lhs_ << "\t" << rhs_.m_Type.row[nI].c_str () << " " << rhs_.m_Head.row[nI].c_str () << " ;" << endl ;
			}
			else {
				string enum_type = "enum_" ;
				enum_type += rhs_.m_Head.row[nI] ;
				lhs_ << "\t" << enum_type.c_str () << " " << rhs_.m_Head.row[nI].c_str () << " ;" << endl ;
			}
		}

		lhs_ << "};" << endl ;
		lhs_ << endl ;

		/*
		struct table_info
		{
			map<int, table_info_data> data ;

			void add ( char* pstr_ )
			{
				table_info_data temp ;

				char *ptr = nullptr ;

				ptr = strtok ( pstr_, "," ) ;
				temp.index = atoi ( ptr ) ;

				ptr = strtok ( NULL, "," ) ;
				string test = ptr ;
				temp.type_char = read_type_char::GetType ( test ) ;

				ptr = strtok ( NULL, "," ) ;
				temp.data_int = atoi ( ptr ) ;

				ptr = strtok ( NULL, "," ) ;
				temp.data_str = ptr ;

				ptr = strtok ( NULL, "," ) ;
				temp.data_float = atof ( ptr ) ;

				ptr = strtok ( NULL, "\"" ) ;
				push ( temp.list, ptr ) ;

				data[temp.index] = temp ;
			}

			table_info_data& operator [] ( int idx_ )
			{
				return data[idx_] ;
			}
		};
		*/

		lhs_ << "struct " << rhs_.getTableName ().c_str () << endl ;
		lhs_ << "{" << endl ;

		lhs_ << "\t" << "map<" << rhs_.m_Type.row[0].c_str () << ", " << table_data.c_str () << "> data ;" << endl ;
		lhs_ << "\t" << endl ;
		lhs_ << "\t" << "void add ( char* pstr_ )" << endl ;
		lhs_ << "\t" << "{" << endl ;
		lhs_ << "\t" << "\t" << table_data.c_str () << " temp ;" << endl ;
		lhs_ << "\t" << "\t" << "char *ptr = nullptr ;" << endl ;
		lhs_ << "\t" << "\t" << endl ;

		lhs_ << "\t" << "\t" << "ptr = strtok ( pstr_, \",\" ) ;" << endl ;
		lhs_ << "\t" << "\t" << "_Push ( temp." << rhs_.m_Head.row[0].c_str () << ", ptr ) ;" << endl ;
		for ( int nI = 1 ; nI < rhs_.m_Type.row.size () ; ++nI ) {
			lhs_ << "\t" << "\t" << "ptr = strtok ( NULL, \",\" ) ;" << endl ;

			if ( strcmp ( rhs_.m_Type.row[nI].c_str (), "enum" ) ) {
				lhs_ << "\t" << "\t" << "_Push ( temp." << rhs_.m_Head.row[nI].c_str () << ", ptr ) ;" << endl ;
			}
			else {
				string read_type = "read_" ;
				read_type += rhs_.m_Head.row[nI] ;
				lhs_ << "\t" << "\t" << "temp." << rhs_.m_Head.row[nI].c_str () << " = " << read_type.c_str () << "::GetType ( ptr ) ;" << endl ;
			}
		}
		lhs_ << "\t" << "\t" << endl ;
		lhs_ << "\t" << "\t" << "data[temp." << rhs_.m_Head.row[0].c_str () << "] = temp ;" << endl ;
		lhs_ << "\t" << "}" << endl ;

		lhs_ << "};" << endl ;
		lhs_ << endl ;

		return lhs_ ;
	}

};

class ReadType
{
private:
	struct _read_type
	{
		string type ;
		string value ;
	};

	string m_FileName ;
	string m_TypeName ;
	vector<_read_type> m_Data ;

public:
	string getFileName () { return m_FileName ; }
	string getTypeName () { return m_TypeName ; }

public:
	void setFileName ( string filename_ )
	{
		m_FileName = filename_ ;
	}

	void read ( string filename_ )
	{
		char inputString[MAX_SIZE];
		cout << endl ;
		ifstream inFile ( filename_ );

		if ( ! inFile.eof () ) inFile.getline ( inputString, 100 );

		char *ptr = nullptr ;

		ptr = strtok ( inputString, "," ) ;
		m_TypeName = ptr ;

		_read_type temp ;
		while ( ! inFile.eof () ) {
			inFile.getline ( inputString, 100 );
			if ( ! strlen ( inputString ) ) break ;

			ptr = strtok ( inputString, "," ) ;
			temp.type = ptr ;

			ptr = strtok ( NULL, "," ) ;
			temp.value = ptr ;

			m_Data.push_back ( temp ) ;
		}

		print () ;

		inFile.close ();
	}

	void print ()
	{
		cout << "FileName : " << m_FileName.c_str () << endl ;
		cout << "TypeName : " << m_TypeName.c_str () << endl ;

		for ( auto& it : m_Data ) {
			cout << it.type.c_str () << "\t" << it.value.c_str () << endl ;
		}
	}

	friend ofstream& operator << ( ofstream& lhs_, const ReadType& rhs_ )
	{
		/*
		enum enum_type_char
		{
			enum_type_char_none = 0,
			CHAR_A = 100,
			CHAR_B = 200,
			CHAR_C = 300,
		};
		*/
		string enum_type = "enum_" ;
		enum_type += rhs_.m_TypeName ;
		lhs_ << "enum " << enum_type.c_str () << endl ;
		lhs_ << "{" << endl ;

		string enum_type_none = enum_type ;
		enum_type_none += "_none" ;
		lhs_ << "\t" << enum_type_none.c_str () << " = 0," << endl ;

		for ( auto& it : rhs_.m_Data ) {
			lhs_ << "\t" << it.type.c_str () << " = " << it.value.c_str () << "," << endl ;
		}

		lhs_ << "};" << endl ;
		lhs_ << endl ;

		/*
		struct read_type_char
		{
			static enum_type_char GetType ( string type_ )
			{
				if ( ! type_.compare ( "CHAR_A" ) ) return CHAR_A ;
				if ( ! type_.compare ( "CHAR_B" ) ) return CHAR_B ;
				if ( ! type_.compare ( "CHAR_C" ) ) return CHAR_C ;

				return enum_type_char_none ;
			}
		};
		*/

		string read_type = "read_" ;
		read_type += rhs_.m_TypeName ;
		lhs_ << "struct " << read_type.c_str () << endl ;
		lhs_ << "{" << endl ;

		lhs_ << "\t" << "static " << enum_type.c_str () << " GetType ( string type_ )" << endl ;
		lhs_ << "\t" << "{" << endl ;

		for ( auto& it : rhs_.m_Data ) {
			lhs_ << "\t\t" << "if ( ! type_.compare ( \"" << it.type.c_str () << "\" ) ) return " << it.type.c_str () << " ;" << endl ;
		}
		lhs_ << "\t\t" << endl ;
		lhs_ << "\t\t" << "return " << enum_type_none.c_str () << " ;" << endl ;

		lhs_ << "\t" << "}" << endl ;

		lhs_ << "};" << endl ;
		lhs_ << endl ;


		return lhs_ ;
	}

};


class HeaderType
{
private :
	string m_HeaderName = { "OUT\\type.h" } ;
	map<string, ReadType> m_mapType ;

public:
	string getHeaderName () { return m_HeaderName ; }

public :
	void setHeaderName ( string name_ )
	{
		m_HeaderName = "OUT\\" ;
		m_HeaderName += name_ ;
		m_HeaderName += ".h" ;
	}

	void push ( ReadType object_ )
	{
		m_mapType[object_.getTypeName ()] = object_ ;
	}

	void make ()
	{
		string file = m_HeaderName ;
		ofstream fout ( file.c_str (), ios::out ) ;

		fout << "#pragma once" << endl ;
		fout << endl ;
		fout << "#include <string>" << endl ;
		fout << "using namespace std ;" << endl ;
		fout << endl ;

		for ( auto& it : m_mapType ) {
			fout << it.second ;
		}

		fout.close () ;
	}

};

class HeaderTable
{
private :
	string m_HeaderName = { "OUT\\head.h" } ;
	HeaderType m_Type_H ;
	map<string, ReadTable> m_mapTable ;

public :
	void setTableHeaderName ( string name_ )
	{
		m_HeaderName = "OUT\\" ;
		m_HeaderName += name_ ;
		m_HeaderName += ".h" ;
	}

	void setTypeHeaderName ( string name_ )
	{
		m_Type_H.setHeaderName ( name_ ) ;
	}

	void push ( ReadType object_ )
	{
		m_Type_H.push ( object_ ) ;
	}

	void push ( ReadTable object_ )
	{
		m_mapTable[object_.getTableName ()] = object_ ;
	}

	void make ()
	{
		m_Type_H.make () ;

		ofstream fout ( m_HeaderName.c_str (), ios::out ) ;

		fout << "#pragma once" << endl ;
		fout << endl ;
		fout << "#include \"" << m_Type_H.getHeaderName ().c_str () << "\"" << endl ;
		fout << "#include <vector>" << endl ;
		fout << "#include <map>" << endl ;
		fout << endl ;

		fout << "template< class _T_ >" << endl ;
		fout << "void _Push ( vector<_T_>& list_, char* pstr_ )" << endl ;
		fout << "{" << endl ;
		fout << "\t" << "char *ptr = strtok ( pstr_, \",\" ) ;" << endl ;
		fout << "\t" << endl ;
		fout << "\t" << "while ( ptr != NULL ) {" << endl ;
		fout << "\t" << "\t" << "if ( strstr ( typeid( _T_ ).name (), \"int\" ) ) list_.emplace_back ( atoi ( ptr ) ) ;" << endl ;
		fout << "\t" << "\t" << "else if ( strstr ( typeid( _T_ ).name (), \"float\" ) ) list_.emplace_back ( atof ( ptr ) ) ;" << endl ;
		fout << "\t" << "\t" << endl ;
		fout << "\t" << "\t" << "ptr = strtok ( NULL, \",\" ) ;" << endl ;
		fout << "\t" << "}" << endl ;
		fout << "}" << endl ;
		fout << endl ;

		fout << "template< class _T_ >" << endl ;
		fout << "void _Push ( _T_& data_, char* pstr_ )" << endl ;
		fout << "{" << endl ;
		fout << "\t" << "if ( strstr ( typeid( _T_ ).name (), \"int\" ) ) data_ = atoi ( pstr_ ) ;" << endl ;
		fout << "\t" << "else if ( strstr ( typeid( _T_ ).name (), \"float\" ) ) data_ = atof ( pstr_ ) ;" << endl ;
		fout << "}" << endl ;
		fout << endl ;

		fout << "void _Push ( string& data_, char* pstr_ )" << endl ;
		fout << "{" << endl ;
		fout << "\t" << "data_ = pstr_ ;" << endl ;
		fout << "}" << endl ;
		fout << endl ;

		for ( auto& it : m_mapTable ) {
			fout << it.second ;
		}

		fout.close () ;
	}

};


/*
class CSV_Converter
{
	char inputString[MAX_SIZE];

	table_info temp ;

public :
	void loadTable ( string filename_ )
	{
		cout << endl ;
		ifstream inFile ( filename_ );

		int nCount = 0 ;

		while ( !inFile.eof () ) {

			inFile.getline ( inputString, 100 );

			if ( 1 < nCount++ && strlen( inputString ) ) temp.add ( inputString ) ;

			// cout << inputString << endl;
		}

		print () ;

		inFile.close ();
	}

	void loadType ( string filename_ )
	{
		cout << endl ;
		ifstream inFile ( filename_ );

		int nCount = 0 ;

		while ( !inFile.eof () ) {

			inFile.getline ( inputString, 100 );

			if ( 1 < nCount++ && strlen ( inputString ) ) temp.add ( inputString ) ;

			// cout << inputString << endl;
		}

		print () ;

		inFile.close ();
	}


	void print ()
	{
		for ( auto it : temp.data ) {
			cout << it.second.index << " , " ;
			cout << it.second.type_char << " , " ;
			cout << it.second.data_int << " , " ;
			cout << it.second.data_str.c_str () << " , " ;
			cout << it.second.data_float << " , " ;

			cout << "\" " ;
			for ( auto it2 : it.second.list ) {
				cout << it2 << " , " ;
			}
			cout << "\"" << endl ;
		}
	}

};
*/

enum test_test
{
	test_111,
};

int main ( int argc, char *argv[] )
{
	cout << typeid( int ).name () << endl ;
	cout << typeid( float ).name () << endl ;
	cout << typeid( string ).name () << endl ;
	cout << typeid( test_test ).name () << endl ;

	// HeaderType csvType ;
	HeaderTable csvTable ;

	if ( 2 < argc ) {
		csvTable.setTableHeaderName ( argv[1] ) ;
		csvTable.setTypeHeaderName ( argv[2] ) ;
	}
	else {
		csvTable.setTableHeaderName ( "head" ) ;
		csvTable.setTypeHeaderName ( "type" ) ;
	}
	
	_finddata_t fd;
	intptr_t handle;
	int result = 1;
	handle = _findfirst ( ".\\CSV\\*.*", &fd );  //현재 폴더 내 모든 파일을 찾는다.

	if ( handle == -1 ) {
		printf ( "There were no files.\n" );
		return 0 ;
	}

	while ( result != -1 ) {
		string path = "CSV\\" ;
		string name = path + fd.name ;

		if ( string::npos != name.find ( "table" ) )
		{
			ReadTable readTable ;
			readTable.setFileName ( fd.name ) ;
			readTable.read ( name ) ;

			csvTable.push ( readTable ) ;
		}

		if ( string::npos != name.find ( "type" ) ) {
			ReadType readType ;
			readType.setFileName ( fd.name ) ;
			readType.read ( name ) ;

			csvTable.push ( readType ) ;
		}

		printf ( "File: %s\n", fd.name );
		result = _findnext ( handle, &fd );
	}

	_findclose ( handle );


	csvTable.make () ;


	/*
	table_info testmake ;

	char inputString[MAX_SIZE];
	cout << endl ;

	ifstream inFile ( "CSV\\info_table.CSV" );

	if ( ! inFile.eof () ) inFile.getline ( inputString, 100 );
	if ( ! inFile.eof () ) inFile.getline ( inputString, 100 );

	while ( ! inFile.eof () ) {
		inFile.getline ( inputString, 100 );
		if ( ! strlen ( inputString ) ) break ;

		testmake.add ( inputString ) ;
	}

	inFile.close ();

	for ( auto& it : testmake.data )
	{
		cout << it.second.index << " , " << it.second.type_char << " , " << it.second.data_str << endl ;
	}
	// */

	return 0 ;
}