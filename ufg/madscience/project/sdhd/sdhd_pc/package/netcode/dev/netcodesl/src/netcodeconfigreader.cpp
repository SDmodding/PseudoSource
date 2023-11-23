// File Line: 13
// RVA: 0x1466F90
__int64 dynamic_initializer_for__gNetcodeConfigReader__()
{
  netcodeSL::netcodeConfigReader::netcodeConfigReader(&gNetcodeConfigReader);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gNetcodeConfigReader__);
}

// File Line: 37
// RVA: 0x15D660
void __fastcall netcodeSL::netcodeConfigReader::netcodeConfigReader(netcodeSL::netcodeConfigReader *this)
{
  this->InactivityTimeout = 60000;
  *(_DWORD *)&this->DebugOutputToDebug = 0x1000000;
  *(_WORD *)&this->EnableGameClientConnections = 1;
  *(_DWORD *)&this->EnableAutoJoinInvite = 1;
  this->UserControlledMatchmakingJoinGame = 0;
  this->PS3SysutilSlot = 3;
  this->AutoDiscoveryListenPort = "10105";
  this->GameClientConnectionPort = "10666";
  this->BombdServerListenPort = "10104";
  this->ServerSecret = &customCaption;
  *(_QWORD *)&this->mTitleParameters.mEnvironment = 0i64;
  this->mTitleParameters.mLanguage = TITLEPARAM_LANG_ENG;
  this->mTitleParameters.mTitleId[0] = 0;
  strncpy_s(this->mTitleParameters.mClientLibVersion, 0x10ui64, "3.4.20", 0xFFFFFFFFFFFFFFFFui64);
  this->mTitleParameters.mTrackingId[0] = 0;
  this->mVOIPType = VOIP_SERVER_BASED;
  this->mUseDefaultServiceList = 1;
  this->mBombdServiceOverride = 0i64;
  *(_QWORD *)this->PS3CommunicationID = 0i64;
  *(_QWORD *)&this->PS3CommunicationID[8] = 0i64;
  *(_QWORD *)&this->PS3CommunicationID[16] = 0i64;
  *(_QWORD *)&this->PS3CommunicationID[24] = 0i64;
  *(_QWORD *)&this->PS3CommunicationID[32] = 0i64;
  *(_QWORD *)&this->PS3CommunicationID[40] = 0i64;
  *(_QWORD *)&this->PS3CommunicationID[48] = 0i64;
  *(_QWORD *)&this->PS3CommunicationID[56] = 0i64;
  strncpy_s(this->PS3BombdServerIP, 0x100ui64, "127.0.0.1", 0x100ui64);
  strncpy_s(this->PS3BombdServerPort, 0x10ui64, "10104", 0x10ui64);
  strncpy_s(this->PS3RegionCode, 0x20ui64, &customCaption, 0x20ui64);
}

