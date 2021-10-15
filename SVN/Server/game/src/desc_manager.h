//find;

private:
	bool				m_bDisconnectInvalidCRC;

//add above;

#ifdef ENABLE_HWID_BAN_SYSTEM
	bool			HardwareBanKontrol(const char* cHWInfo);
#endif