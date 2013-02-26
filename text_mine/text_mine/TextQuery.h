#pragma once
#include <vector>
#include <set>
#include <map>
using namespace std;
/*
*1��vector�洢�ļ���ÿһ��
*2��set�д洢ĳһkey���ֵ�����
*3����map�洢<key="����"��value="set">
*
*/

class TextQuery{
public:
	//TextQuery(){};
	typedef std::vector<std::string>::const_iterator  const_iter;
	typedef std::vector<std::string>::size_type line_no;	
	void read_file(std::ifstream & );
	std::set<line_no> run_query( const std::string &) const;
	void display(std::ostream &, std::set<line_no> &);
	std::string text_line(line_no ln)  const{
		return lines_of_text[ln]; 
	};
	line_no size() const{
		return lines_of_text.size();
	}
	virtual ~TextQuery(void) {}
private:
	void store_file(std::ifstream&);
	void build_map(void);
	std::vector<std::string>   lines_of_text;
	std::map<std::string, std::set<line_no>>  word_maps; 
};








