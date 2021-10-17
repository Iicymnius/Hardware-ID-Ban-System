//find;

void CInputAuth::Login(LPDESC d, const char* c_pData)

//find in function;

	if (g_bNoMoreClient)

//add above;

#ifdef ENABLE_HWID_BAN_SYSTEM
	if (DESC_MANAGER::instance().HardwareBanKontrol(pinfo->cHWInfo))
	{
		sys_log(0, "HW_BAN: [%s] Mac: [%s]", pinfo->login, pinfo->cHWInfo);
		LoginFailure(d, "HW_BAN");
		return;
	}
#endif
