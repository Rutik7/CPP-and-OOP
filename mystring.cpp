//implementing own string class
#include <iostream>
//using namespace std;
class Mystring
{
private:
	char * res;
	unsigned int len;



	void Myswap(Mystring& str1, Mystring& str2)
	{
		std::swap(str1.res,str2.res);
		std::swap(str1.len,str2.len);
	}

public:
	Mystring() : res(nullptr) , len(0)
	{

	}

	Mystring(const char* str) 
	{
		len = strlen(str);
		res = new char[len+1];
		strcpy(res,str);
	}

	Mystring(const Mystring& str)
	{
		len = str.len;
		res = new char[len+1];
		strcpy(res,str.res);
	}

	/*Mystring& operator=(const Mystring & str)
	{
		if(this != &str)  // checking the case str2 = str2;
		{
			delete[] res;
			len = str.len;
			res = new char[len+1];
			strcpy(res,str.res);
		}
		return *this;
	}*/ // eraley here suppose new memory allocation was failed and we delete the resources first 
	// so there is better way to this 
	// get a copy of object which want to copy and swap with this object

	Mystring& operator=(Mystring str)
	{
		Myswap(*this,str);
		return *this;
	}
	
	unsigned int length()
	{
		return len;
	}

	~Mystring()
	{
		if(res)
		{
			delete[] res;
			res = nullptr;
			len = 0;
		}
	}

	friend std::ostream& operator<<(std::ostream& out, const Mystring& str);
	friend std::istream& operator>>(std::istream& in, Mystring& str);
	
};

std::ostream& operator<<(std::ostream& out, const Mystring& str)
{
	out<<str.res;
	return out;
}

std::istream& operator>>(std::istream& in, Mystring& str)
{
	char buffer[1000];
	in>>buffer;
	delete[] str.res;

	str.len = strlen(buffer);
	str.res = new char[str.len + 1];
	strcpy(str.res,buffer);

	//in>>str.res;
	return in;
}

int main()
{
	Mystring str1;	//default constructor
	Mystring str2 = "hello"; // parameterised constructor
	Mystring str3 = str2;   //copy constructor
	str3 = str2;			//copy Assignment Operator


	std::cout<<str2<<std::endl;
	std::cin>>str1;
	return 0;
}