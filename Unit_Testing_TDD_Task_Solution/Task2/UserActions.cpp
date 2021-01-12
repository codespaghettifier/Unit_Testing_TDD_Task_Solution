#include "UserActions.h"

UserActions::UserActions(DatabaseWrapper* database) : _database{database}
{
	_database->connect("localhost", "127.0.0.1", "user", "root", "toor");
}

UserActions::~UserActions()
{
	_database->disconnect();
}

bool UserActions::isIdValid(int userId) const
{
	const auto queryResult = _database->executeNonTransactionalQuery("DOES USER OF " + to_string(userId) + " ID EXISTS");
	const auto isIdValid = userId % 2 ? true : false; // dummy evaluating if id exists in db
	return isIdValid;
}

void UserActions::changeUsername(int userId, string newUsername)
{
	_database->executeTransactionalQuery("CHANGE USERNAME OF USER ID " + to_string(userId));
	_database->commit();
}

void UserActions::changePassword(int userId, string newPassword)
{
	_database->executeTransactionalQuery("CHANGE PASSWORD OF USER ID " + to_string(userId));
	_database->commit();
}

void UserActions::changeEmail(int userId, string newEmail)
{
	_database->executeTransactionalQuery("CHANGE EMAIL OF USER ID " + to_string(userId));
	_database->commit();
}
void UserActions::payCredits(int userId, int creditAmount)
{
	_database->executeTransactionalQuery("PAY " + to_string(creditAmount) + " CREDITS TO USER OF ID " + to_string(userId));
	_database->commit();
}

void UserActions::setPriviliges(int userId, vector<int> priviligesIdsToSet)
{
	for (auto priviligeId : priviligesIdsToSet)
		_database->executeTransactionalQuery("SET " + to_string(priviligeId) + " PRIVILIGES TO USER OF ID " + to_string(userId));
	_database->commit();
}