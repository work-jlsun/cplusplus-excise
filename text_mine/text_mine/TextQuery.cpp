#include "StdAfx.h"
#include "TextQuery.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
//using namespace std;
void  TextQuery::read_file(std::ifstream & is){
	store_file(is);
	build_map();
}

std::set<TextQuery::line_no> TextQuery::run_query( const std::string &query_word) const {
	//std::set<int> line_nums;
	map<string,set<line_no>>::const_iterator iter = word_maps.find(query_word);
	if ( iter == word_maps.end()){
		return	set<line_no>();
	}else{
		return iter->second;
	}
}

/*
*read lines from files
*/
void TextQuery::store_file(std::ifstream &is){
	string s;
	while ( std::getline(is,s) ){
		lines_of_text.push_back(s);
	}
}


void TextQuery::build_map(void){
	string word;
	for(line_no n= 0; n!= lines_of_text.size(); n++){	
		istringstream line(lines_of_text[n]);
		while ( line >> word ){
			word_maps[word].insert(n);
		}
	}
}


/*
*diaplay the result
*/

void TextQuery::display(std::ostream &os, std::set<line_no> &locs){
	for(std::set<line_no>::const_iterator iter = locs.begin(); iter != locs.end(); iter++){
		os << "[" << (*iter) << "]" << ":" 
		   <<text_line(*iter) << std::endl;;
	}
}
