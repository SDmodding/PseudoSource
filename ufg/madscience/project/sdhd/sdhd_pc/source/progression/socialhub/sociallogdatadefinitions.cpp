// File Line: 14
// RVA: 0x48DA90
void __fastcall UFG::SocialLogData_NewHighScore::SocialLogData_NewHighScore(
        UFG::SocialLogData_NewHighScore *this,
        unsigned __int64 timeStamp,
        int leaderboardId,
        int score)
{
  UFG::SocialLogData::SocialLogData(this);
  this->vfptr = (UFG::OSuiteMessageVtbl *)&UFG::SocialLogData_NewHighScore::`vftable;
  this->m_iHasSent = 0;
  this->m_aData = 0i64;
  this->m_iCommId = CommId_NewHighScore;
  this->m_iTimeStamp = timeStamp;
  this->m_iLeaderboardId = leaderboardId;
  this->m_iScore = score;
}

// File Line: 22
// RVA: 0x491590
void __fastcall UFG::SocialLogData_NewHighScore::~SocialLogData_NewHighScore(UFG::SocialLogData_NewHighScore *this)
{
  char *m_aData; // rcx

  this->vfptr = (UFG::OSuiteMessageVtbl *)&UFG::SocialLogData_NewHighScore::`vftable;
  m_aData = this->m_aData;
  if ( m_aData )
    operator delete[](m_aData);
  UFG::SocialLogData::~SocialLogData(this);
}

// File Line: 38
// RVA: 0x4BA830
char *__fastcall UFG::SocialLogData_NewHighScore::Serialize(UFG::SocialLogData_NewHighScore *this)
{
  char *m_aData; // rcx
  int v3; // eax
  char *v4; // rax
  char *v5; // rbx
  int m_iLeaderboardId; // ecx
  int m_iScore; // ecx
  char v9[4]; // [rsp+20h] [rbp-28h] BYREF
  char v10[8]; // [rsp+28h] [rbp-20h] BYREF
  int v; // [rsp+50h] [rbp+8h] BYREF
  UFG::SocialLogData::CommId source; // [rsp+58h] [rbp+10h] BYREF
  int v13; // [rsp+60h] [rbp+18h] BYREF
  int v14; // [rsp+68h] [rbp+20h] BYREF

  m_aData = this->m_aData;
  if ( m_aData )
    operator delete[](m_aData);
  v3 = this->vfptr->Size(this);
  v4 = (char *)UFG::qMalloc(v3, "SocialLogData_NewHighScore", 0i64);
  source = this->m_iCommId;
  v5 = v4;
  *(_QWORD *)v10 = this->m_iTimeStamp;
  m_iLeaderboardId = this->m_iLeaderboardId;
  this->m_aData = v4;
  v13 = m_iLeaderboardId;
  m_iScore = this->m_iScore;
  v = 0;
  v14 = m_iScore;
  *(_DWORD *)v9 = this->m_iHasSent;
  UFG::qEndianSwapBytes((char *)&v, 4u);
  UFG::qEndianSwapBytes((char *)&source, 4u);
  UFG::qEndianSwapBytes(v10, 8u);
  UFG::qEndianSwapBytes((char *)&v13, 4u);
  UFG::qEndianSwapBytes((char *)&v14, 4u);
  UFG::qEndianSwapBytes(v9, 4u);
  UFG::qMemCopy(v5, &v, 4u);
  UFG::qMemCopy(v5 + 4, &source, 4u);
  UFG::qMemCopy(v5 + 8, v10, 8u);
  UFG::qMemCopy(v5 + 16, &v13, 4u);
  UFG::qMemCopy(v5 + 20, &v14, 4u);
  UFG::qMemCopy(v5 + 24, v9, 4u);
  return this->m_aData;
}

// File Line: 83
// RVA: 0x49B7F0
void __fastcall UFG::SocialLogData_NewHighScore::Deserialize(UFG::SocialLogData_NewHighScore *this, char *data)
{
  UFG::qMemCopy(&this->m_iVersion, data, 4u);
  UFG::qMemCopy(&this->m_iCommId, data + 4, 4u);
  UFG::qMemCopy(&this->m_iTimeStamp, data + 8, 8u);
  UFG::qMemCopy(&this->m_iLeaderboardId, data + 16, 4u);
  UFG::qMemCopy(&this->m_iScore, data + 20, 4u);
  UFG::qMemCopy(&this->m_iHasSent, data + 24, 4u);
  UFG::qEndianSwapBytes((char *)&this->m_iVersion, 4u);
  UFG::qEndianSwapBytes((char *)&this->m_iCommId, 4u);
  UFG::qEndianSwapBytes((char *)&this->m_iTimeStamp, 8u);
  UFG::qEndianSwapBytes((char *)&this->m_iLeaderboardId, 4u);
  UFG::qEndianSwapBytes((char *)&this->m_iScore, 4u);
  UFG::qEndianSwapBytes((char *)&this->m_iHasSent, 4u);
}

// File Line: 115
// RVA: 0x48D850
void __fastcall UFG::SocialLogData_AwardAchieved::SocialLogData_AwardAchieved(
        UFG::SocialLogData_AwardAchieved *this,
        unsigned __int64 timeStamp,
        int leaderboardId,
        int score)
{
  UFG::SocialLogData::SocialLogData(this);
  this->vfptr = (UFG::OSuiteMessageVtbl *)&UFG::SocialLogData_AwardAchieved::`vftable;
  this->m_aData = 0i64;
  this->m_iCommId = CommId_AwardAchieved;
  this->m_iTimeStamp = timeStamp;
  this->m_iLeaderboardId = leaderboardId;
  this->m_iScore = score;
}

// File Line: 123
// RVA: 0x4914D0
void __fastcall UFG::SocialLogData_AwardAchieved::~SocialLogData_AwardAchieved(UFG::SocialLogData_AwardAchieved *this)
{
  char *m_aData; // rcx

  this->vfptr = (UFG::OSuiteMessageVtbl *)&UFG::SocialLogData_AwardAchieved::`vftable;
  m_aData = this->m_aData;
  if ( m_aData )
    operator delete[](m_aData);
  UFG::SocialLogData::~SocialLogData(this);
}

// File Line: 138
// RVA: 0x4BA2E0
char *__fastcall UFG::SocialLogData_AwardAchieved::Serialize(UFG::SocialLogData_AwardAchieved *this)
{
  char *m_aData; // rcx
  int v3; // eax
  char *v4; // rax
  char *v5; // rbx
  int m_iLeaderboardId; // ecx
  int m_iScore; // ecx
  char v9[8]; // [rsp+20h] [rbp-28h] BYREF
  int v; // [rsp+50h] [rbp+8h] BYREF
  UFG::SocialLogData::CommId source; // [rsp+58h] [rbp+10h] BYREF
  int v12; // [rsp+60h] [rbp+18h] BYREF
  int v13; // [rsp+68h] [rbp+20h] BYREF

  m_aData = this->m_aData;
  if ( m_aData )
    operator delete[](m_aData);
  v3 = this->vfptr->Size(this);
  v4 = (char *)UFG::qMalloc(v3, "SocialLogData_AwardAchieved", 0i64);
  source = this->m_iCommId;
  v5 = v4;
  *(_QWORD *)v9 = this->m_iTimeStamp;
  m_iLeaderboardId = this->m_iLeaderboardId;
  this->m_aData = v4;
  v12 = m_iLeaderboardId;
  m_iScore = this->m_iScore;
  v = 0;
  v13 = m_iScore;
  UFG::qEndianSwapBytes((char *)&v, 4u);
  UFG::qEndianSwapBytes((char *)&source, 4u);
  UFG::qEndianSwapBytes(v9, 8u);
  UFG::qEndianSwapBytes((char *)&v12, 4u);
  UFG::qEndianSwapBytes((char *)&v13, 4u);
  UFG::qMemCopy(v5, &v, 4u);
  UFG::qMemCopy(v5 + 4, &source, 4u);
  UFG::qMemCopy(v5 + 8, v9, 8u);
  UFG::qMemCopy(v5 + 16, &v12, 4u);
  UFG::qMemCopy(v5 + 20, &v13, 4u);
  return this->m_aData;
}

// File Line: 179
// RVA: 0x49B450
void __fastcall UFG::SocialLogData_AwardAchieved::Deserialize(UFG::SocialLogData_AwardAchieved *this, char *data)
{
  UFG::qMemCopy(&this->m_iVersion, data, 4u);
  UFG::qMemCopy(&this->m_iCommId, data + 4, 4u);
  UFG::qMemCopy(&this->m_iTimeStamp, data + 8, 8u);
  UFG::qMemCopy(&this->m_iLeaderboardId, data + 16, 4u);
  UFG::qMemCopy(&this->m_iScore, data + 20, 4u);
  UFG::qEndianSwapBytes((char *)&this->m_iVersion, 4u);
  UFG::qEndianSwapBytes((char *)&this->m_iCommId, 4u);
  UFG::qEndianSwapBytes((char *)&this->m_iTimeStamp, 8u);
  UFG::qEndianSwapBytes((char *)&this->m_iLeaderboardId, 4u);
  UFG::qEndianSwapBytes((char *)&this->m_iScore, 4u);
}

// File Line: 213
// RVA: 0x48D8D0
void __fastcall UFG::SocialLogData_BeatChallenge::SocialLogData_BeatChallenge(
        UFG::SocialLogData_BeatChallenge *this,
        unsigned __int64 timeStamp,
        int leaderboardId,
        int score,
        UFG::OnlineId *srcOnlineId,
        UFG::qString *srcOnlineName,
        UFG::OnlineId *dstOnlineId,
        UFG::qString *dstOnlineName)
{
  UFG::SocialLogData::SocialLogData(this);
  this->vfptr = (UFG::OSuiteMessageVtbl *)&UFG::SocialLogData_BeatChallenge::`vftable;
  this->m_iHasSent = 0;
  this->m_aData = 0i64;
  this->m_iCommId = CommId_BeatChallenge;
  this->m_iTimeStamp = timeStamp;
  this->m_iLeaderboardId = leaderboardId;
  this->m_iScore = score;
  this->m_cSrcOnlineId.m_SteamId.m_steamid.m_unAll64Bits = srcOnlineId->m_SteamId.m_steamid.m_unAll64Bits;
  UFG::qString::Set(&this->m_sSrcOnlineName, srcOnlineName->mData, srcOnlineName->mLength, 0i64, 0);
  this->m_cDstOnlineId.m_SteamId.m_steamid.m_unAll64Bits = dstOnlineId->m_SteamId.m_steamid.m_unAll64Bits;
  UFG::qString::Set(&this->m_sDstOnlineName, dstOnlineName->mData, dstOnlineName->mLength, 0i64, 0);
}

// File Line: 225
// RVA: 0x491510
void __fastcall UFG::SocialLogData_BeatChallenge::~SocialLogData_BeatChallenge(UFG::SocialLogData_BeatChallenge *this)
{
  char *m_aData; // rcx

  this->vfptr = (UFG::OSuiteMessageVtbl *)&UFG::SocialLogData_BeatChallenge::`vftable;
  m_aData = this->m_aData;
  if ( m_aData )
    operator delete[](m_aData);
  UFG::SocialLogData::~SocialLogData(this);
}

// File Line: 233
// RVA: 0x4C8F50
__int64 __fastcall UFG::SocialLogData_BeatChallenge::VariableBindingListSize(UFG::SocialLogData_Challenge *this)
{
  return 148i64;
}

// File Line: 245
// RVA: 0x4BA410
char *__fastcall UFG::SocialLogData_BeatChallenge::Serialize(UFG::SocialLogData_BeatChallenge *this)
{
  char *m_aData; // rcx
  int v3; // eax
  char *v4; // rbx
  char *v5; // rbx
  char v7[4]; // [rsp+20h] [rbp-79h] BYREF
  char v8[8]; // [rsp+28h] [rbp-71h] BYREF
  __int64 v9; // [rsp+30h] [rbp-69h]
  UFG::qString v10; // [rsp+38h] [rbp-61h] BYREF
  UFG::qString v11; // [rsp+60h] [rbp-39h] BYREF
  UFG::qString v12; // [rsp+88h] [rbp-11h] BYREF
  UFG::qString result; // [rsp+B0h] [rbp+17h] BYREF
  int v; // [rsp+100h] [rbp+67h] BYREF
  UFG::SocialLogData::CommId source; // [rsp+108h] [rbp+6Fh] BYREF
  int m_iLeaderboardId; // [rsp+110h] [rbp+77h] BYREF
  int m_iScore; // [rsp+118h] [rbp+7Fh] BYREF

  v9 = -2i64;
  m_aData = this->m_aData;
  if ( m_aData )
    operator delete[](m_aData);
  v3 = this->vfptr->Size(this);
  v4 = (char *)UFG::qMalloc(v3, "SocialLogData_BeatChallenge", 0i64);
  this->m_aData = v4;
  v = 0;
  source = this->m_iCommId;
  *(_QWORD *)v8 = this->m_iTimeStamp;
  m_iLeaderboardId = this->m_iLeaderboardId;
  m_iScore = this->m_iScore;
  UFG::OnlineId::ToString(&this->m_cSrcOnlineId, &result);
  UFG::qString::qString(&v11, &this->m_sSrcOnlineName);
  UFG::OnlineId::ToString(&this->m_cDstOnlineId, &v12);
  UFG::qString::qString(&v10, &this->m_sDstOnlineName);
  *(_DWORD *)v7 = this->m_iHasSent;
  UFG::qEndianSwapBytes((char *)&v, 4u);
  UFG::qEndianSwapBytes((char *)&source, 4u);
  UFG::qEndianSwapBytes(v8, 8u);
  UFG::qEndianSwapBytes((char *)&m_iLeaderboardId, 4u);
  UFG::qEndianSwapBytes((char *)&m_iScore, 4u);
  UFG::qEndianSwapBytes(v7, 4u);
  UFG::qMemCopy(v4, &v, 4u);
  UFG::qMemCopy(v4 + 4, &source, 4u);
  UFG::qMemCopy(v4 + 8, v8, 8u);
  UFG::qMemCopy(v4 + 16, &m_iLeaderboardId, 4u);
  UFG::qMemCopy(v4 + 20, &m_iScore, 4u);
  UFG::qMemCopy(v4 + 24, result.mData, 0x20u);
  UFG::qMemCopy(v4 + 56, v11.mData, 0x20u);
  UFG::qMemCopy(v4 + 88, v12.mData, 0x20u);
  UFG::qMemCopy(v4 + 120, v10.mData, 0x20u);
  UFG::qMemCopy(v4 + 152, v7, 4u);
  v5 = this->m_aData;
  UFG::qString::~qString(&v10);
  UFG::qString::~qString(&v12);
  UFG::qString::~qString(&v11);
  UFG::qString::~qString(&result);
  return v5;
}

// File Line: 302
// RVA: 0x49B540
void __fastcall UFG::SocialLogData_Challenge::Deserialize(UFG::SocialLogData_Challenge *this, char *data)
{
  char *v4; // rdx
  __int64 v5; // rbx
  __int64 *v6; // rcx
  __int64 **v7; // rax
  __int64 *v8; // rcx
  __int64 **v9; // rax
  __int64 *v10; // [rsp+20h] [rbp-81h] BYREF
  __int64 **v11; // [rsp+28h] [rbp-79h]
  unsigned __int64 dest; // [rsp+30h] [rbp-71h] BYREF
  __int64 *v13; // [rsp+38h] [rbp-69h] BYREF
  __int64 **v14; // [rsp+40h] [rbp-61h]
  unsigned __int64 v15; // [rsp+48h] [rbp-59h]
  char v16[40]; // [rsp+58h] [rbp-49h] BYREF
  char text[40]; // [rsp+80h] [rbp-21h] BYREF
  char v18[88]; // [rsp+A8h] [rbp+7h] BYREF
  __int64 v19; // [rsp+108h] [rbp+67h]

  UFG::qMemCopy(&this->m_iVersion, data, 4u);
  UFG::qMemCopy(&this->m_iCommId, data + 4, 4u);
  UFG::qMemSet(&dest, 0, 0x21u);
  UFG::qMemSet(text, 0, 0x21u);
  UFG::qMemSet(v16, 0, 0x21u);
  UFG::qMemSet(v18, 0, 0x21u);
  UFG::qMemCopy(&this->m_iTimeStamp, data + 8, 8u);
  UFG::qMemCopy(&this->m_iLeaderboardId, data + 16, 4u);
  UFG::qMemCopy(&this->m_iScore, data + 20, 4u);
  UFG::qMemCopy(&dest, data + 24, 0x20u);
  UFG::qMemCopy(text, data + 56, 0x20u);
  UFG::qMemCopy(v16, data + 88, 0x20u);
  UFG::qMemCopy(v18, data + 120, 0x20u);
  v4 = data + 152;
  v5 = v19;
  UFG::qMemCopy((void *)(v19 + 192), v4, 4u);
  UFG::qEndianSwapBytes((char *)&this->m_iVersion, 4u);
  UFG::qEndianSwapBytes((char *)&this->m_iCommId, 4u);
  UFG::qEndianSwapBytes((char *)&this->m_iTimeStamp, 8u);
  UFG::qEndianSwapBytes((char *)&this->m_iLeaderboardId, 4u);
  UFG::qEndianSwapBytes((char *)&this->m_iScore, 4u);
  UFG::qEndianSwapBytes((char *)(v5 + 192), 4u);
  v10 = (__int64 *)&v10;
  v11 = &v10;
  dest &= 0xFF0FFFFF00000000ui64;
  HIBYTE(dest) = 0;
  HIDWORD(dest) &= 0xFFF00000;
  dest = UFG::qToUInt64((const char *)&dest, 0i64);
  *(_QWORD *)(v5 + 80) = dest;
  v6 = v10;
  v7 = v11;
  v10[1] = (__int64)v11;
  *v7 = v6;
  v10 = (__int64 *)&v10;
  v11 = &v10;
  UFG::qString::Set((UFG::qString *)(v5 + 88), text);
  v13 = (__int64 *)&v13;
  v14 = &v13;
  LODWORD(v15) = 0;
  HIDWORD(v10) &= 0xFF0FFFFF;
  HIBYTE(v10) = 0;
  HIDWORD(v10) &= 0xFFF00000;
  v15 = UFG::qToUInt64(v16, 0i64);
  *(_QWORD *)(v5 + 144) = v15;
  v8 = v13;
  v9 = v14;
  v13[1] = (__int64)v14;
  *v9 = v8;
  v13 = (__int64 *)&v13;
  v14 = &v13;
  UFG::qString::Set((UFG::qString *)(v5 + 152), v18);
}

// File Line: 360
// RVA: 0x48D9B0
void __fastcall UFG::SocialLogData_Challenge::SocialLogData_Challenge(
        UFG::SocialLogData_Challenge *this,
        unsigned __int64 timeStamp,
        int leaderboardId,
        int score,
        UFG::OnlineId *srcOnlineId,
        UFG::qString *srcOnlineName,
        UFG::OnlineId *dstOnlineId,
        UFG::qString *dstOnlineName)
{
  UFG::SocialLogData::SocialLogData(this);
  this->vfptr = (UFG::OSuiteMessageVtbl *)&UFG::SocialLogData_Challenge::`vftable;
  this->m_iHasBeaten = 0;
  this->m_aData = 0i64;
  this->m_iCommId = CommId_Challenge;
  this->m_iTimeStamp = timeStamp;
  this->m_iLeaderboardId = leaderboardId;
  this->m_iScore = score;
  this->m_cSrcOnlineId.m_SteamId.m_steamid.m_unAll64Bits = srcOnlineId->m_SteamId.m_steamid.m_unAll64Bits;
  UFG::qString::Set(&this->m_sSrcOnlineName, srcOnlineName->mData, srcOnlineName->mLength, 0i64, 0);
  this->m_cDstOnlineId.m_SteamId.m_steamid.m_unAll64Bits = dstOnlineId->m_SteamId.m_steamid.m_unAll64Bits;
  UFG::qString::Set(&this->m_sDstOnlineName, dstOnlineName->mData, dstOnlineName->mLength, 0i64, 0);
}

// File Line: 372
// RVA: 0x491550
void __fastcall UFG::SocialLogData_Challenge::~SocialLogData_Challenge(UFG::SocialLogData_Challenge *this)
{
  char *m_aData; // rcx

  this->vfptr = (UFG::OSuiteMessageVtbl *)&UFG::SocialLogData_Challenge::`vftable;
  m_aData = this->m_aData;
  if ( m_aData )
    operator delete[](m_aData);
  UFG::SocialLogData::~SocialLogData(this);
}

// File Line: 392
// RVA: 0x4BA620
char *__fastcall UFG::SocialLogData_Challenge::Serialize(UFG::SocialLogData_Challenge *this)
{
  char *m_aData; // rcx
  int v3; // eax
  char *v4; // rbx
  char *v5; // rbx
  char v7[4]; // [rsp+20h] [rbp-79h] BYREF
  char v8[8]; // [rsp+28h] [rbp-71h] BYREF
  __int64 v9; // [rsp+30h] [rbp-69h]
  UFG::qString v10; // [rsp+38h] [rbp-61h] BYREF
  UFG::qString v11; // [rsp+60h] [rbp-39h] BYREF
  UFG::qString v12; // [rsp+88h] [rbp-11h] BYREF
  UFG::qString result; // [rsp+B0h] [rbp+17h] BYREF
  int v; // [rsp+100h] [rbp+67h] BYREF
  UFG::SocialLogData::CommId source; // [rsp+108h] [rbp+6Fh] BYREF
  int m_iLeaderboardId; // [rsp+110h] [rbp+77h] BYREF
  int m_iScore; // [rsp+118h] [rbp+7Fh] BYREF

  v9 = -2i64;
  m_aData = this->m_aData;
  if ( m_aData )
    operator delete[](m_aData);
  v3 = this->vfptr->Size(this);
  v4 = (char *)UFG::qMalloc(v3, "SocialLogData_Challenge", 0i64);
  this->m_aData = v4;
  v = 0;
  source = this->m_iCommId;
  *(_QWORD *)v8 = this->m_iTimeStamp;
  m_iLeaderboardId = this->m_iLeaderboardId;
  m_iScore = this->m_iScore;
  UFG::OnlineId::ToString(&this->m_cSrcOnlineId, &result);
  UFG::qString::qString(&v11, &this->m_sSrcOnlineName);
  UFG::OnlineId::ToString(&this->m_cDstOnlineId, &v12);
  UFG::qString::qString(&v10, &this->m_sDstOnlineName);
  *(_DWORD *)v7 = this->m_iHasBeaten;
  UFG::qEndianSwapBytes((char *)&v, 4u);
  UFG::qEndianSwapBytes((char *)&source, 4u);
  UFG::qEndianSwapBytes(v8, 8u);
  UFG::qEndianSwapBytes((char *)&m_iLeaderboardId, 4u);
  UFG::qEndianSwapBytes((char *)&m_iScore, 4u);
  UFG::qEndianSwapBytes(v7, 4u);
  UFG::qMemCopy(v4, &v, 4u);
  UFG::qMemCopy(v4 + 4, &source, 4u);
  UFG::qMemCopy(v4 + 8, v8, 8u);
  UFG::qMemCopy(v4 + 16, &m_iLeaderboardId, 4u);
  UFG::qMemCopy(v4 + 20, &m_iScore, 4u);
  UFG::qMemCopy(v4 + 24, result.mData, 0x20u);
  UFG::qMemCopy(v4 + 56, v11.mData, 0x20u);
  UFG::qMemCopy(v4 + 88, v12.mData, 0x20u);
  UFG::qMemCopy(v4 + 120, v10.mData, 0x20u);
  UFG::qMemCopy(v4 + 152, v7, 4u);
  v5 = this->m_aData;
  UFG::qString::~qString(&v10);
  UFG::qString::~qString(&v12);
  UFG::qString::~qString(&v11);
  UFG::qString::~qString(&result);
  return v5;
}

