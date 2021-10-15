//add to bottom;

#ifdef ENABLE_HWID_BAN_SYSTEM
bool DESC_MANAGER::HardwareBanKontrol(const char* cHWInfo)
{
	char szHW[255 + 1];
	DBManager::instance().EscapeString(szHW, sizeof(szHW), cHWInfo, strlen(cHWInfo));

	std::unique_ptr<SQLMsg> pMsg(DBManager::instance().DirectQuery("SELECT COUNT(*) FROM account.hw_ban WHERE hw_id = '%s'", szHW));
	if (!pMsg->uiSQLErrno)
	{
		MYSQL_ROW row = mysql_fetch_row(pMsg->Get()->pSQLResult);
		BYTE bAdet = 0;
		str_to_number(bAdet, row[0]);
		if (bAdet > 0)
		{
			return true;
		}
	}

	return false;
}
#endif