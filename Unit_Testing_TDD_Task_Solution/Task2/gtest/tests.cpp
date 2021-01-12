#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "../DatabaseWrapper.h"
#include "../UserActions.h"

class MockDatabaseWrapper: public DatabaseWrapper
{
public:
    MOCK_METHOD(void, connect, (string hostname, string hostaddr, string username, string dbname, string password), (override));
    MOCK_METHOD(void, disconnect, (), (override));
    MOCK_METHOD(string, executeNonTransactionalQuery, (string query), (override));
    MOCK_METHOD(string, executeTransactionalQuery, (string query), (override));
    MOCK_METHOD(void, commit, (), (override));

    virtual ~MockDatabaseWrapper();
};

/*
class DatabaseWrapperPlaceholder : public DatabaseWrapper
{
public:
	DatabaseWrapperPlaceholder() {}

	void connect(std::string hostname, std::string hostaddr, std::string username, std::string dbname, std::string password) {}
	void disconnect() {}
	std::string executeNonTransactionalQuery(std::string query)
	{
		return string("");
	}
	std::string executeTransactionalQuery(std::string query)
	{
		return string("");
	}
	void commit(){}

	~DatabaseWrapperPlaceholder() {}
};
*/

TEST(UserActions, actions)
{
	auto databaseMock = std::make_unique<MockDatabaseWrapper>();

    EXPECT_CALL(*databaseMock, executeNonTransactionalQuery("DOES USER OF " + to_string(42) + " ID EXISTS")).Times(1);
    EXPECT_CALL(*databaseMock, executeTransactionalQuery("CHANGE USERNAME OF USER ID " + to_string(42) + " TO codespaghettifier")).Times(1);
    EXPECT_CALL(*databaseMock, executeTransactionalQuery("CHANGE PASSWORD OF USER ID " + to_string(42) + " TO letmein")).Times(1);
    EXPECT_CALL(*databaseMock, executeTransactionalQuery("CHANGE EMAIL OF USER ID " + to_string(42) + " TO codespaghettifier@example.com")).Times(1);
    EXPECT_CALL(*databaseMock, executeTransactionalQuery("PAY " + to_string(420) + " CREDITS TO USER OF ID " + to_string(42))).Times(1);
    EXPECT_CALL(*databaseMock, executeTransactionalQuery("SET " + to_string(123) + " PRIVILIGES TO USER OF ID " + to_string(42))).Times(1);

    EXPECT_CALL(*databaseMock, connect("localhost", "127.0.0.1", "user", "root", "toor")).Times(1);
    EXPECT_CALL(*databaseMock, commit()).Times(5);
    EXPECT_CALL(*databaseMock, disconnect()).Times(1);

    auto userA = std::make_unique<UserActions>(new MockDatabaseWrapper);

    userA->isIdValid(42);
    userA->changeUsername(42, "codespaghettifier");
    userA->changePassword(42, "letmein");
    userA->changeEmail(42, "codespaghettifier@example.com");
    userA->payCredits(42, 420);
    userA->setPriviliges(42, std::vector<int>(123));

}
