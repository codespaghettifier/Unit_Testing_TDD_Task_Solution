#pragma once
#include "DatabaseWrapper.h"

#include <vector>

class UserActions
{
public:
	UserActions(DatabaseWrapper* database);
	~UserActions();
	bool isIdValid(int userId) const;
	void changeUsername(int userId, string newUsername);
	void changePassword(int userId, string newPassword);
	void changeEmail(int userId, string newEmail);
	void payCredits(int userId, int creditAmount);
	void setPriviliges(int userId, vector<int> priviligesIdsToSet);

private:
	DatabaseWrapper* _database;
};

