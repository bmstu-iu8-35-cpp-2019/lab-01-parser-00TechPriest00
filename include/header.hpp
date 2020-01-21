 // Copyright 2018 Fedorov james.sayfer2015@yandex.ru

#ifndef INCLUDE_HEADER_HPP_
#define INCLUDE_HEADER_HPP_

#include <string.h> 
#include <map>
#include <stdexcept>
#include <cstdlib>
#include <stdio.h>
#include "stdafx.h"
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <utility>
#include <cstdlib>
#include <iomanip>
#include <any>
#include <fstream>


<<<<<<< HEAD
class Json{
=======
class Json
{
>>>>>>> f68bcc9e75661087c0679ca46998fd794d5f7e7e
private:
	std::any _data;

public:
<<<<<<< HEAD
	explicit Json(const std::string& a){
		int pos = 0;
		int n = a.length();
		for (int i = pos; pos < n; ++i){
			if (a[pos] == ' ' || a[pos] == '\n' || a[pos] == '\t'){
				++pos;
				continue;}
			if (a[pos] == '['){
				++pos;
				_data = parse_array(a, pos);
				auto pam = std::any_cast<std::vector<std::any>>(_data);
				break;}
			if (a[pos] == '{'){
				++pos;
				_data = parse_obj(a, pos);
				break;}
=======
	explicit Json(const std::string& a)
	{
		int pos = 0;
		int n = a.length();
		for (int i = pos; pos < n; ++i)
		{
			if (a[pos] == ' ' || a[pos] == '\n' || a[pos] == '\t')
			{
				++pos;
				continue;
			}
			if (a[pos] == '[')
			{
				++pos;
				_data = parse_array(a, pos);
				auto pam = std::any_cast<std::vector<std::any>>(_data);
				break;
			}
			if (a[pos] == '{')
			{
				++pos;
				_data = parse_obj(a, pos);
				break;
			}
>>>>>>> f68bcc9e75661087c0679ca46998fd794d5f7e7e
		}
	}


<<<<<<< HEAD
	explicit Json(std::any a){
		try{
			_data = std::any_cast<std::map<std::string, std::any>>(a);}
		catch (...){
			throw std::logic_error("Íå îáúåêò");}
	}

	bool is_obj() const{
		if (_data.type() == typeid(std::map<std::string, std::any>)){
			return true;}
		else{
			return false;}
	}

	bool is_array() const{
		if (_data.type() == typeid(std::vector<std::any>)){
			return true;}
		else{
			return false;}
=======
	explicit Json(std::any a)
	{
		try
		{
			_data = std::any_cast<std::map<std::string, std::any>>(a);
		}
		catch (...)
		{
			throw std::logic_error("Íå îáúåêò");
		}
	}

	bool is_obj() const
	{
		if (_data.type() == typeid(std::map<std::string, std::any>))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool is_array() const
	{
		if (_data.type() == typeid(std::vector<std::any>))
		{
			return true;
		}
		else
		{
			return false;
		}
>>>>>>> f68bcc9e75661087c0679ca46998fd794d5f7e7e
	}



<<<<<<< HEAD
	std::any operator[](const std::string& v){
		if (is_obj()){
			return (std::any_cast<std::map<std::string, std::any>>(_data))[v];}
		else{
			throw std::logic_error("Íå îáúåêò");}
	}


	std::any operator[](int ind){
		if (is_array()){
			auto pam = std::any_cast<std::vector<std::any>>(_data);
			return pam[ind];}
		else{
			throw std::logic_error("Íå îáúåêò");}
	}


	std::map<std::string, std::any> parse_obj(const std::string& a, int& pos){
=======
	std::any operator[](const std::string& v)
	{
		if (is_obj())
		{
			return (std::any_cast<std::map<std::string, std::any>>(_data))[v];
		}
		else
		{
			throw std::logic_error("Íå îáúåêò");
		}
	}


	std::any operator[](int ind)
	{
		if (is_array())
		{
			auto pam = std::any_cast<std::vector<std::any>>(_data);
			return pam[ind];
		}
		else
		{
			throw std::logic_error("Íå îáúåêò");
		}
	}


	std::map<std::string, std::any> parse_obj(const std::string& a, int& pos)
	{
>>>>>>> f68bcc9e75661087c0679ca46998fd794d5f7e7e
		int n = a.length();
		std::map<std::string, std::any> obj;
		std::string condition = "v/end";
		std::string v = "";
<<<<<<< HEAD
		while (n>pos){
			while (n>pos){
				if ((a[pos] == ' ') || (a[pos] == '\n') || (a[pos] == '\t')){
					++pos;}
				else{
					break;}
			}
			if (a[pos] == ','){
				if (condition == "com/end"){
					++pos;
					condition = "v/end";
					continue;}
				else{
					throw std::invalid_argument("jj");}
			}
			if (a[pos] == '"'){
				if (condition == "v/end"){
					++pos;
					condition = "findCol";
					v = parse_string(a, pos);}
				else{
					if (condition == "findVal"){
						++pos;
						condition = "com/end";
						std::string value = parse_string(a, pos);
						obj.insert(make_pair(v, value));}
					else{
						throw std::invalid_argument("aa");}
				}
			}
			if (isdigit(a[pos])){
				if (condition == "findVal"){
					condition = "com/end";
					float value = parse_number(a, pos);
					obj.insert(make_pair(v, value));}
				else{
					throw std::invalid_argument("bb");}
			}

			if (isalpha(a[pos])){
				if (condition == "findVal"){
					condition = "com/end";
					bool value = parse_bool(a, pos);
					obj.insert(make_pair(v, value));}
				else{
					throw std::invalid_argument("cc");}
			}
			if (a[pos] == '['){
				if (condition == "findVal"){
					++pos;
					condition = "com/end";
					std::vector<std::any> value = parse_array(a, pos);
					obj.insert(make_pair(v, value));}
				else{
					throw std::invalid_argument("dd");}
			}
			if (a[pos] == ':'){
				if (condition == "findCol"){
					++pos;
					condition = "findVal";}
				else{
					throw std::invalid_argument("ee");}
			}
			if (a[pos] == '{'){
				if (condition == "findVal"){
					++pos;
					condition = "com/end";
					std::map<std::string, std::any> value = parse_obj(a, pos);
					obj.insert(make_pair(v, value));}
				else{
					throw std::invalid_argument("ff");}
			}
			if (a[pos] == '}'){
				if ((condition == "v/end") || (condition == "com/end")){
					++pos;
					return obj;}
				else{
					throw std::invalid_argument("gg");}
			}
		}
		throw std::invalid_argument("aaaa");;}


	float parse_number(const std::string& s, int& pos){
		int n = s.length();
		std::string str = "";
		while (n>pos){
			while (n>pos){
				if (s[pos] == ' ' || s[pos] == '\n' || s[pos] == '\t'){
					++pos;}
				else{
					break;}
			}
			if ((isdigit(s[pos]) == false) && (s[pos] != '.')){
				if (str == ""){
					throw std::invalid_argument("hh");}
				break;}
			str = str + s[pos];
			++pos;}
		return ::atof(str.c_str());}


	float parse_bool(const std::string& s, int& pos){
		int n = s.length();
		std::string str = "";
		while (n>pos){
			while (n>pos){
				if (s[pos] == ' ' || s[pos] == '\n' || s[pos] == '\t'){
					++pos;}
				else{
					break;}
			}
			if (isalpha(s[pos]) == false){
				if (str == ""){
					throw std::invalid_argument("ii");}
				break;}
			str = str + s[pos];
			++pos;

			if (str.length() == 5 && str == "false"){
				return false;}
			if (str.length() == 4 && str == "true"){
				return true;}
			if ((str.length() == 4) && (str != "false")){
				throw std::invalid_argument("bbbb");}
			if (str.length() == 5 && str != "false"){
				throw std::invalid_argument("aaaa");}
		}
		return ::atof(str.c_str());}


	std::string parse_string(const std::string& s, int& pos){
		int n = s.length();
		std::string str = "";
		while (n>pos){
			while (n>pos){
				if (s[pos] == ' ' || s[pos] == '\n' || s[pos] == '\t'){
					++pos;}
				else{
					break;}
			}
			if (s[pos] == '"'){
				if (str == ""){
					throw std::invalid_argument("ii");}
				++pos;
				break;}
			str = str + s[pos];
			++pos;}
		return str;}


	std::vector<std::any> parse_array(const std::string& s, int& pos){
		int n = s.length();
		std::vector<std::any> arr;
		std::string condition = "findVal";
		while (n>pos){
			while (n>pos){
				if ((s[pos] == ' ') || (s[pos] == '\n') || (s[pos] == '\t')){
					++pos;}
				else{
					break;}
			}
			if (isalpha(s[pos])){
				if (condition == "findVal"){
					bool value = parse_bool(s, pos);
					arr.push_back(value);
					condition = "com/end";}
				else{
					throw std::invalid_argument("eeee");}
			}
			if (isdigit(s[pos])){
				if (condition == "findVal"){
					float value = parse_number(s, pos);
					arr.push_back(value);
					condition = "com/end";}
				else{
					throw std::invalid_argument("cccc");}
			}
			if (s[pos] == '"'){
				if (condition == "findVal"){
					++pos;}
			}
			if (s[pos] == ','){
				if (condition == "com/end"){
					condition = "findVal";
					++pos;}
				else{
					throw std::invalid_argument("bbbb");}
			}

			if (s[pos] == ']'){
				++pos;
				return arr;}
			if (s[pos] == '{'){
				if (condition == "findVal"){
					++pos;
					arr.push_back(parse_obj(s, pos));}
				else{
					throw std::invalid_argument("dddd");}
			}
		}
		throw std::invalid_argument("gggg");}


	Json parse(const std::string& s){
		int n = s.length();
		int pos = 0;
		while (n>pos){
			if (s[pos] == ' ' || s[pos] == '\n' || s[pos] == '\t'){
				++pos;
				continue;}
			if (s[pos] == '['){
				++pos;
				_data = parse_array(s, pos);
				auto pam = std::any_cast<std::vector<std::any>>(_data);
				break;}
			if (s[pos] == '{'){
				++pos;
				_data = parse_obj(s, pos);
				break;}
		}
		return *this;}

	Json parseFile(char* path_to_file){
=======
		while (n>pos)
		{
			while (n>pos)
			{
				if ((a[pos] == ' ') || (a[pos] == '\n') || (a[pos] == '\t'))
				{
					++pos;
				}
				else
				{
					break;
				}
			}
			if (a[pos] == ',')
			{
				if (condition == "com/end")
				{
					++pos;
					condition = "v/end";
					continue;
				}
				else
				{
					throw std::invalid_argument("jj");
				}
			}
			if (a[pos] == '"')
			{
				if (condition == "v/end")
				{
					++pos;
					condition = "findCol";
					v = parse_string(a, pos);
				}
				else
				{
					if (condition == "findVal")
					{
						++pos;
						condition = "com/end";
						std::string value = parse_string(a, pos);
						obj.insert(make_pair(v, value));
					}
					else
					{
						throw std::invalid_argument("aa");
					}
				}
			}
			if (isdigit(a[pos]))
			{
				if (condition == "findVal")
				{
					condition = "com/end";
					float value = parse_number(a, pos);
					obj.insert(make_pair(v, value));
				}
				else
				{
					throw std::invalid_argument("bb");
				}
			}

			if (isalpha(a[pos]))
			{
				if (condition == "findVal")
				{
					condition = "com/end";
					bool value = parse_bool(a, pos);
					obj.insert(make_pair(v, value));
				}
				else
				{
					throw std::invalid_argument("cc");
				}
			}
			if (a[pos] == '[')
			{
				if (condition == "findVal")
				{
					++pos;
					condition = "com/end";
					std::vector<std::any> value = parse_array(a, pos);
					obj.insert(make_pair(v, value));
				}
				else
				{
					throw std::invalid_argument("dd");
				}
			}
			if (a[pos] == ':')
			{
				if (condition == "findCol")
				{
					++pos;
					condition = "findVal";
				}
				else
				{
					throw std::invalid_argument("ee");
				}
			}
			if (a[pos] == '{')
			{
				if (condition == "findVal")
				{
					++pos;
					condition = "com/end";
					std::map<std::string, std::any> value = parse_obj(a, pos);
					obj.insert(make_pair(v, value));
				}
				else
				{
					throw std::invalid_argument("ff");
				}
			}
			if (a[pos] == '}')
			{
				if ((condition == "v/end") || (condition == "com/end"))
				{
					++pos;
					return obj;
				}
				else
				{
					throw std::invalid_argument("gg");
				}
			}
		}
		throw std::invalid_argument("aaaa");;
	}


	float parse_number(const std::string& s, int& pos)
	{
		int n = s.length();
		std::string str = "";
		while (n>pos)
		{
			while (n>pos)
			{
				if (s[pos] == ' ' || s[pos] == '\n' || s[pos] == '\t')
				{
					++pos;
				}
				else
				{
					break;
				}
			}
			if ((isdigit(s[pos]) == false) && (s[pos] != '.'))
			{
				if (str == "")
				{
					throw std::invalid_argument("hh");
				}
				break;
			}
			str = str + s[pos];
			++pos;
		}
		return ::atof(str.c_str());
	}


	float parse_bool(const std::string& s, int& pos)
	{
		int n = s.length();
		std::string str = "";
		while (n>pos)
		{
			while (n>pos)
			{
				if (s[pos] == ' ' || s[pos] == '\n' || s[pos] == '\t')
				{
					++pos;
				}
				else
				{
					break;
				}
			}
			if (isalpha(s[pos]) == false)
			{
				if (str == "")
				{
					throw std::invalid_argument("ii");
				}
				break;
			}
			str = str + s[pos];
			++pos;

			if (str.length() == 5 && str == "false")
			{
				return false;
			}
			if (str.length() == 4 && str == "true")
			{
				return true;
			}
			if ((str.length() == 4) && (str != "false"))
			{
				throw std::invalid_argument("bbbb");
			}
			if (str.length() == 5 && str != "false")
			{
				throw std::invalid_argument("aaaa");
			}
		}
		return ::atof(str.c_str());
	}


	std::string parse_string(const std::string& s, int& pos)
	{
		int n = s.length();
		std::string str = "";
		while (n>pos)
		{
			while (n>pos)
			{
				if (s[pos] == ' ' || s[pos] == '\n' || s[pos] == '\t')
				{
					++pos;
				}
				else
				{
					break;
				}
			}
			if (s[pos] == '"')
			{
				if (str == "")
				{
					throw std::invalid_argument("ii");
				}
				++pos;
				break;
			}
			str = str + s[pos];
			++pos;
		}
		return str;
	}


	std::vector<std::any> parse_array(const std::string& s, int& pos)
	{
		int n = s.length();
		std::vector<std::any> arr;
		std::string condition = "findVal";
		while (n>pos)
		{
			while (n>pos)
			{
				if ((s[pos] == ' ') || (s[pos] == '\n') || (s[pos] == '\t'))
				{
					++pos;
				}
				else
				{
					break;
				}
			}
			if (isalpha(s[pos]))
			{
				if (condition == "findVal")
				{
					bool value = parse_bool(s, pos);
					arr.push_back(value);
					condition = "com/end";
				}
				else
				{
					throw std::invalid_argument("eeee");
				}
			}
			if (isdigit(s[pos]))
			{
				if (condition == "findVal")
				{
					float value = parse_number(s, pos);
					arr.push_back(value);
					condition = "com/end";
				}
				else
				{
					throw std::invalid_argument("cccc");
				}
			}
			if (s[pos] == '"')
			{
				if (condition == "findVal")
				{
					++pos;
				}
			}
			if (s[pos] == ',')
			{
				if (condition == "com/end")
				{
					condition = "findVal";
					++pos;
				}
				else
				{
					throw std::invalid_argument("bbbb");
				}
			}

			if (s[pos] == ']')
			{
				++pos;
				return arr;
			}
			if (s[pos] == '{')
			{
				if (condition == "findVal")
				{
					++pos;
					arr.push_back(parse_obj(s, pos));
				}
				else
				{
					throw std::invalid_argument("dddd");
				}
			}
		}
		throw std::invalid_argument("gggg");
	}


	Json parse(const std::string& s)
	{
		int n = s.length();
		int pos = 0;
		while (n>pos)
		{
			if (s[pos] == ' ' || s[pos] == '\n' || s[pos] == '\t')
			{
				++pos;
				continue;
			}
			if (s[pos] == '[')
			{
				++pos;
				_data = parse_array(s, pos);
				auto pam = std::any_cast<std::vector<std::any>>(_data);
				break;
			}
			if (s[pos] == '{')
			{
				++pos;
				_data = parse_obj(s, pos);
				break;
			}
		}
		return *this;
	}

	Json parseFile(char* path_to_file)
	{
>>>>>>> f68bcc9e75661087c0679ca46998fd794d5f7e7e
		FILE *f;
		f = fopen(path_to_file, "r");
		std::ifstream fin(path_to_file);
		std::string s = "";
		fin >> s;
		fclose(f);
<<<<<<< HEAD
		return parse(s);}
=======
		return parse(s);
	}
>>>>>>> f68bcc9e75661087c0679ca46998fd794d5f7e7e
};
#endif // INCLUDE_HEADER_HPP_
