// File Line: 13
// RVA: 0x1466F90
__int64 dynamic_initializer_for__gNetcodeConfigReader__()
{
  netcodeSL::netcodeConfigReader::netcodeConfigReader(&gNetcodeConfigReader);
  return atexit(dynamic_atexit_destructor_for__gNetcodeConfigReader__);
}

// File Line: 37
// RVA: 0x15D660
void __fastcall netcodeSL::netcodeConfigReader::netcodeConfigReader(netcodeSL::netcodeConfigReader *this)
{
  netcodeSL::netcodeConfigReader *v1; // rbx

  this->InactivityTimeout = 60000;
  *(_DWORD *)&this->DebugOutputToDebug = 0x1000000;
  *(_WORD *)&this->EnableGameClientConnections = 1;
  *(_DWORD *)&this->EnableAutoJoinInvite = 1;
  this->UserControlledMatchmakingJoinGame = 0;
  this->PS3SysutilSlot = 3;
  v1 = this;
  this->AutoDiscoveryListenPort = "10105";
  this->GameClientConnectionPort = "10666";
  this->BombdServerListenPort = "10104";
  this->ServerSecret = &customWorldMapCaption;
  *(_QWORD *)&this->mTitleParameters.mEnvironment = 0i64;
  this->mTitleParameters.mLanguage = 0;
  this->mTitleParameters.mTitleId[0] = 0;
  strncpy_s(this->mTitleParameters.mClientLibVersion, 0x10ui64, "3.4.20", 0xFFFFFFFFFFFFFFFFui64);
  v1->mTitleParameters.mTrackingId[0] = 0;
  v1->mVOIPType = 1;
  v1->mUseDefaultServiceList = 1;
  v1->mBombdServiceOverride = 0i64;
  *(_QWORD *)v1->PS3CommunicationID = 0i64;
  *(_QWORD *)&v1->PS3CommunicationID[8] = 0i64;
  *(_QWORD *)&v1->PS3CommunicationID[16] = 0i64;
  *(_QWORD *)&v1->PS3CommunicationID[24] = 0i64;
  *(_QWORD *)&v1->PS3CommunicationID[32] = 0i64;
  *(_QWORD *)&v1->PS3CommunicationID[40] = 0i64;
  *(_QWORD *)&v1->PS3CommunicationID[48] = 0i64;
  *(_QWORD *)&v1->PS3CommunicationID[56] = 0i64;
  strncpy_s(v1->PS3BombdServerIP, 0x100ui64, "127.0.0.1", 0x100ui64);
  strncpy_s(v1->PS3BombdServerPort, 0x10ui64, "10104", 0x10ui64);
  strncpy_s(v1->PS3RegionCode, 0x20ui64, &customWorldMapCaption, 0x20ui64);
}

