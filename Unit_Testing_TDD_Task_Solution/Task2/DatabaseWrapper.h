#pragma once
#include <string>
using namespace std;


class DatabaseWrapper
{
public:
	virtual ~DatabaseWrapper() {}
	virtual void connect(string hostname, string hostaddr, string username, string dbname, string password) = 0;
	virtual void disconnect() = 0;
	virtual string executeNonTransactionalQuery(string query) = 0;
	virtual string executeTransactionalQuery(string query) = 0;
	virtual void commit() = 0;
protected:
};
