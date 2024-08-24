// SOLID.cpp : Defines the entry point for the console application.
//

#pragma region HEADERS
#include "stdafx.h"
#include<iostream>
using namespace std;
#include<vector>
#include<string>
#pragma endregion HEADERS

/// <summary>
/// this is the example for the Dependeny Inversion Principle
/// Here in this example DBProcessor is highly dependent on the DB class.
/// Dependency principle suggests that HIGH LEVEL/LOW level should depend on the abstractions rather concrete classes.
/// To fix it,We can create an abstract class for DB and DBProcessor would be dependent on the Abstract class.
/// </summary>
/// 

#ifdef _DEPENDENCY_INVERSION_FAULTY_CLASS
class DB
{
	string m_data;
public:
	void InsertValues(string val)
	{
		m_data = val;
		cout << m_data << endl;

	}
};
class DBProcessor
{
public:
	void ProcessData(vector<string>str, DB& database)
	{
		for (auto i : str)
		{
			database.InsertValues(i);
		}
	}
};

int main()
{
	vector<string>m_Name = { "apple","ball","cat" };
	DB *m_Db= new DB();
	DBProcessor *m_Processor= new DBProcessor();
	m_Processor.ProcessData(m_Name, *m_Db);
	delete m_Db, m_Processor;
}
#endif

//After Using Dependency Inversion Principle
#ifdef  USING_DEPENDENCY_INVERSION_PRINCIPLE


class IDatabase
{
public:
	virtual void InsertValues(string val)=0;
};


class DB :public IDatabase
{
	string m_data;
public:
	virtual void InsertValues(string val)
	{
		m_data = val;
		cout << m_data << endl;
	}

};
class DBProcessor
{
public:
	void ProcessData(vector<string>str, IDatabase& database)
	{
		for (auto i : str)
		{
			database.InsertValues(i);			
		}
	}
};

int main()
{
	vector<string>m_Name = { "apple","ball","cat" };
	IDatabase* m_db = new DB();
	DBProcessor* m_processor = new DBProcessor();
	m_processor->ProcessData(m_Name, *m_db);
	delete m_db, m_processor;

}
#endif   USING_DEPENDENCY_INVERSION_PRINCIPLE
