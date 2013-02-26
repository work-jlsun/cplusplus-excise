#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include "TextQuery.h"
#include "query.h"
using namespace std;



ifstream& open_file(ifstream &in, const string &file){
	in.close(); //close in case it was already open
	in.clear();	// clear ant existing errors
	in.open(file.c_str());	//open the file we were given
	return in;
}


int _tmain(int argc, _TCHAR* argv[])
{

	TextQuery tq;
	string filename;
	ifstream infile;
	cout << "enter the mind name\n" << endl;
	cin >> filename;
	//getline(cin,filename);
	if( !open_file(infile, filename) ){
		cout << "open file error'\n" << endl;
		return -1;
	}
	tq.read_file(infile);
	query q = query("fiery") & query("bird") | query("wind");
	std::set<TextQuery::line_no> locs = q.eval(tq);	
	tq.display(cout,locs);
	/*
	while(true){
		cout << "enter the word to query:";
		string s;
		cin >> s;
		if (!cin || s == "q") break;
		set<TextQuery::line_no> locs = tq.run_query(s);
		tq.display(cout,locs);
	}	
	*/
	string s;
	cin >> s;
	return 0;
}

