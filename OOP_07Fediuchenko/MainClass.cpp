#include <iostream>
#include <string>
#include "String.h"
using namespace std;

int main()
{
	String s("StringTest");
	const char* p = s.c_str();
	s = p;
	cout << s.c_str() << endl;

	String ss("Test"); ss += ss; cout << ss << endl;
	

	// Testing constructors
	// Test char*
	cout << "<<<<<<<<<<<<< #1 Testing Constructors >>>>>>>>>>>>>>\n";
	const char* char1 = "I am char*";

	const String str1(char1);
	cout << "str_1(char_1): " << str1 << endl;

	// Test char
	const char ch1 = 'c';

	String str2(ch1);
	cout << "str_2(ch1): " << str2 << endl;

	// Test string
	const string string1 = "I am string";

	String str3(string1);
	cout << "str_3(string_1): " << str3 << endl;

	// Test String
	String str4("I am String");

	String str5(str4, 3);
	cout << "str_5(str_4, 3): " << str5 << endl;

	// Testing convertors and one selector
	cout << "\n<<<<<<<<<<<<< #2 Testing public methods >>>>>>>>>>>>>>\n";

	// Convertors
	cout << "str_5.STL_string(): " << str5.STL_string() << endl;
	cout << "str_5.c_str(): " << str5.c_str() << endl;

	// Length of String
	cout << "str_5.length(): " << str5.length() << endl;

	// Empty
	cout << "Is str_5 empty: ";
	cout << (str5.empty() ? "Yes\n" : "No\n");

	// Clear
	str5.clear();
	cout << "Clear str_5 !!!\nIs str_5 empty now: ";
	cout << (str5.empty() ? "Yes\n" : "No\n");

	// Testing operators
	cout << "\n<<<<<<<<<<<<< #3 Testing operators >>>>>>>>>>>>>>\n";

	str2 = str1;
	cout << "str_2 = str_1: " << str2 << endl;

	cout << (str2 == str1 ? "str_2 == str_1" : "str_2 != str_1") << endl;

	// Call convertion
	str2 = string1;
	cout << "str_2 = string_1: " << str2 << endl;

	str2 = char1;
	cout << "str_2 = char_1: " << str2 << endl;

	str2 = ch1;
	cout << "str_2 = ch_1: " << str2 << endl;

	// Test [] operators
	try
	{
		cout << "str_3[-1]: ";
		str3[-1];
		cout << endl;
	}
	catch (String::BadString& e)
	{
		e.diagnose();
	}

	try
	{
		cout << "str_3[2]";
		str3[2];
		cout << endl;
	}
	catch (String::BadString& e)
	{
		e.diagnose();
	}

	try
	{
		cout << "str_4[-1]";
		str4[-1];
		cout << endl;
	}
	catch (String::BadString& e)
	{
		e.diagnose();
	}

	try
	{
		cout << "str_4[2]";
		str4[2];
		cout << endl;
	}
	catch (String::BadString& e)
	{
		e.diagnose();
	}

	// Testing comparetion operators
	String str6("123");
	String str7("1234");
	String str8("123");
	String str9("1234");

	cout << (str6 > str7 ? "str_6 > str_7" : "str_6 < str_7") << endl;
	cout << (str6 <= str8 ? "str_6 <= str_8" : "str_6 > str_8") << endl;
	cout << (str7 >= str9 ? "str_7 >= str_9" : "str_7 < str_9") << endl;


	cout << "str_6 += string_1: " << (str6 += string1) << endl;

	cout << "str_7 += char_1: " << (str7 += char1) << endl;

	cout << "str_8 += ch_1: " << (str8 += ch1) << endl;

	str9 = str9 + str9;
	cout << "str_9 = str_9 + str_9: " << str9 << endl;

	return 0;
}
