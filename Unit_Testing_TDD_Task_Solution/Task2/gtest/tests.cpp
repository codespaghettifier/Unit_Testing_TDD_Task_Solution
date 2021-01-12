#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "../DatabaseWrapper.h"
#include "../UserActions.h"

class MockDatabaseWrapper: public DatabaseWrapper
{
public:
    virtual ~MockDatabaseWrapper();
    MOCK_METHOD(void,connect,(string hostname, string hostaddr, string username, string dbname, string password),(override));
    MOCK_METHOD(void,disconnect,(),(override));
    MOCK_METHOD(string,executeNonTransactionalQuery,(string query),(override));
    MOCK_METHOD(string,executeTransactionalQuery,(string query),(override));
    MOCK_METHOD(void,commit,(),(override));
};
