//find;

ACMD(do_clear_affect)
{
	ch->ClearAffect(true);
}

//add below;

#ifdef ENABLE_HWID_BAN_SYSTEM
ACMD(do_hardware_ban)
{
	if (quest::CQuestManager::instance().GetEventFlag("hw_ban_disable") == 1)
	{
		ch->ChatPacket(CHAT_TYPE_INFO, "Sistem şuan için devre dışı.");
		return;
	}

	char arg1[256], arg2[256];
	two_arguments(argument, arg1, sizeof(arg1), arg2, sizeof(arg2));

	if (!*arg1 || 0 == arg1[0] || !*arg2 || 0 == arg2[0])
	{
		ch->ChatPacket(CHAT_TYPE_INFO, "Ban atmak için <isim> ban");
		ch->ChatPacket(CHAT_TYPE_INFO, "Ban açmak için <hesap id> unban");
		return;
	}

	const std::string& IslemSec = std::string(arg2);
	if (IslemSec == "ban")
	{
		LPCHARACTER tch = CHARACTER_MANAGER::instance().FindPC(arg1);
		if (tch)
		{
			std::unique_ptr<SQLMsg> pMsg(DBManager::instance().DirectQuery("SELECT login FROM account.account WHERE id = '%u'", tch->GetAID()));
			if (pMsg->Get()->uiNumRows != 0)
			{
				MYSQL_ROW row = mysql_fetch_row(pMsg->Get()->pSQLResult);

				char login[32];
				snprintf(login, sizeof(login), "%s", row[0]);

				std::unique_ptr<SQLMsg> pMsg1(DBManager::instance().DirectQuery("SELECT hw_id FROM account.hw_id_list WHERE login = '%s'", login));
				if (pMsg1->Get()->uiNumRows != 0)
				{
					MYSQL_ROW row = mysql_fetch_row(pMsg1->Get()->pSQLResult);

					char hw_id[32];
					snprintf(hw_id, sizeof(hw_id), "%s", row[0]);

					std::unique_ptr<SQLMsg> pMsg2(DBManager::instance().DirectQuery("SELECT hw_id FROM account.hw_ban WHERE hw_id = '%s'", hw_id));
					if (pMsg2->Get()->uiNumRows == 0)
					{
						DBManager::instance().DirectQuery("INSERT INTO account.hw_ban(hw_id) VALUES('%s');", hw_id);
						tch->GetDesc()->DelayedDisconnect(3);
					}
				}
				else
				{
					ch->ChatPacket(CHAT_TYPE_INFO, "Bu oyuncu HWID listesinde ekli değil.");
				}
			}
			else
			{
				ch->ChatPacket(CHAT_TYPE_INFO, "Bir hata oluştu.");
			}
		}
		else
		{
			ch->ChatPacket(CHAT_TYPE_INFO, "Bu oyuncu oyunda değil.");
		}
	}
	else if (IslemSec == "unban")
	{
		std::unique_ptr<SQLMsg> pMsg(DBManager::instance().DirectQuery("SELECT hw_id FROM account.hw_id_list WHERE login = '%s'", arg1));
		if (pMsg->Get()->uiNumRows != 0)
		{
			MYSQL_ROW row = mysql_fetch_row(pMsg->Get()->pSQLResult);

			char hw_id[32];
			snprintf(hw_id, sizeof(hw_id), "%s", row[0]);

			std::unique_ptr<SQLMsg> pMsg1(DBManager::instance().DirectQuery("SELECT hw_id FROM account.hw_ban WHERE hw_id = '%s'", hw_id));
			if (pMsg1->Get()->uiNumRows != 0)
			{
				DBManager::instance().DirectQuery("DELETE FROM account.hw_ban WHERE hw_id = '%s'", hw_id);
			}
			else
			{
				ch->ChatPacket(CHAT_TYPE_INFO, "Bu hesap banlı değil.");
			}
		}
		else
		{
			ch->ChatPacket(CHAT_TYPE_INFO, "Bir hata oluştu.");
		}
	}
}
#endif