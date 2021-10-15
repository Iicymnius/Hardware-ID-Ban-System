//find;

				TAccountTable& r = d->GetAccountTable();

//add above;

#ifdef ENABLE_HWID_BAN_SYSTEM
				{
					char szHwid[255 * 2 + 1];
					DBManager::instance().EscapeString(szHwid, sizeof(szHwid), pinfo->cHWInfo, strlen(pinfo->cHWInfo));
					std::auto_ptr<SQLMsg> anan(DBManager::instance().DirectQuery("SELECT hw_id FROM account.hw_id_list WHERE login = '%s' and hw_id = '%s'", pinfo->login, szHwid));
					if (anan->Get()->uiNumRows == 0)
					{
						DBManager::instance().DirectQuery("INSERT IGNORE INTO account.hw_id_list SET login = '%s', hw_id = '%s'", pinfo->login, szHwid);
					}
				}
#endif