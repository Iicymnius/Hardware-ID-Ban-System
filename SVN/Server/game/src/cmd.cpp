//find;

ACMD(do_clear_affect);

//add below;

#ifdef ENABLE_HWID_BAN_SYSTEM
ACMD(do_hardware_ban);
#endif

//find again;

	{ "do_clear_affect",		do_clear_affect,		0,			POS_DEAD,	GM_LOW_WIZARD	},

//add below;

#ifdef ENABLE_HWID_BAN_SYSTEM
	{ "hw_ba",					do_inputall,			0,			POS_DEAD,	GM_IMPLEMENTOR	},
	{ "hw_ban",					do_hardware_ban,		0,			POS_DEAD,	GM_IMPLEMENTOR	},
#endif