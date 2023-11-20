// File Line: 14
// RVA: 0x48DA90
void __fastcall UFG::SocialLogData_NewHighScore::SocialLogData_NewHighScore(UFG::SocialLogData_NewHighScore *this, unsigned __int64 timeStamp, int leaderboardId, int score)
{
  int v4; // ebp
  int v5; // edi
  unsigned __int64 v6; // rbx
  UFG::SocialLogData_NewHighScore *v7; // rsi

  v4 = score;
  v5 = leaderboardId;
  v6 = timeStamp;
  v7 = this;
  UFG::SocialLogData::SocialLogData((UFG::SocialLogData *)&this->vfptr);
  v7->vfptr = (UFG::OSuiteMessageVtbl *)&UFG::SocialLogData_NewHighScore::`vftable';
  v7->m_iHasSent = 0;
  v7->m_aData = 0i64;
  v7->m_iCommId = 0;
  v7->m_iTimeStamp = v6;
  v7->m_iLeaderboardId = v5;
  v7->m_iScore = v4;
}

// File Line: 22
// RVA: 0x491590
void __fastcall UFG::SocialLogData_NewHighScore::~SocialLogData_NewHighScore(UFG::SocialLogData_NewHighScore *this)
{
  UFG::SocialLogData_NewHighScore *v1; // rbx
  char *v2; // rcx

  v1 = this;
  this->vfptr = (UFG::OSuiteMessageVtbl *)&UFG::SocialLogData_NewHighScore::`vftable';
  v2 = this->m_aData;
  if ( v2 )
    operator delete[](v2);
  UFG::SocialLogData::~SocialLogData((UFG::SocialLogData *)&v1->vfptr);
}

// File Line: 38
// RVA: 0x4BA830
char *__fastcall UFG::SocialLogData_NewHighScore::Serialize(UFG::SocialLogData_NewHighScore *this)
{
  UFG::SocialLogData_NewHighScore *v1; // rdi
  char *v2; // rcx
  int v3; // eax
  UFG::allocator::free_link *v4; // rax
  UFG::allocator::free_link *v5; // rbx
  int v6; // ecx
  int v7; // ecx
  char v9[4]; // [rsp+20h] [rbp-28h]
  char v10[8]; // [rsp+28h] [rbp-20h]
  int v; // [rsp+50h] [rbp+8h]
  UFG::SocialLogData::CommId source; // [rsp+58h] [rbp+10h]
  int v13; // [rsp+60h] [rbp+18h]
  int v14; // [rsp+68h] [rbp+20h]

  v1 = this;
  v2 = this->m_aData;
  if ( v2 )
    operator delete[](v2);
  v3 = v1->vfptr->Size((UFG::OSuiteMessage *)&v1->vfptr);
  v4 = UFG::qMalloc(v3, "SocialLogData_NewHighScore", 0i64);
  source = v1->m_iCommId;
  v5 = v4;
  *(_QWORD *)v10 = v1->m_iTimeStamp;
  v6 = v1->m_iLeaderboardId;
  v1->m_aData = (char *)v4;
  v13 = v6;
  v7 = v1->m_iScore;
  v = 0;
  v14 = v7;
  *(_DWORD *)v9 = v1->m_iHasSent;
  UFG::qEndianSwapBytes((char *)&v, 4u);
  UFG::qEndianSwapBytes((char *)&source, 4u);
  UFG::qEndianSwapBytes(v10, 8u);
  UFG::qEndianSwapBytes((char *)&v13, 4u);
  UFG::qEndianSwapBytes((char *)&v14, 4u);
  UFG::qEndianSwapBytes(v9, 4u);
  UFG::qMemCopy(v5, &v, 4u);
  UFG::qMemCopy((char *)&v5->mNext + 4, &source, 4u);
  UFG::qMemCopy(&v5[1], v10, 8u);
  UFG::qMemCopy(&v5[2], &v13, 4u);
  UFG::qMemCopy((char *)&v5[2].mNext + 4, &v14, 4u);
  UFG::qMemCopy(&v5[3], v9, 4u);
  return v1->m_aData;
}

// File Line: 83
// RVA: 0x49B7F0
void __fastcall UFG::SocialLogData_NewHighScore::Deserialize(UFG::SocialLogData_NewHighScore *this, char *data)
{
  char *v2; // r15
  char *v3; // rbx

  v2 = (char *)this;
  v3 = data;
  UFG::qMemCopy(&this->m_iVersion, data, 4u);
  UFG::qMemCopy(v2 + 44, v3 + 4, 4u);
  UFG::qMemCopy(v2 + 48, v3 + 8, 8u);
  UFG::qMemCopy(v2 + 56, v3 + 16, 4u);
  UFG::qMemCopy(v2 + 60, v3 + 20, 4u);
  UFG::qMemCopy(v2 + 192, v3 + 24, 4u);
  UFG::qEndianSwapBytes(v2 + 40, 4u);
  UFG::qEndianSwapBytes(v2 + 44, 4u);
  UFG::qEndianSwapBytes(v2 + 48, 8u);
  UFG::qEndianSwapBytes(v2 + 56, 4u);
  UFG::qEndianSwapBytes(v2 + 60, 4u);
  UFG::qEndianSwapBytes(v2 + 192, 4u);
}

// File Line: 115
// RVA: 0x48D850
void __fastcall UFG::SocialLogData_AwardAchieved::SocialLogData_AwardAchieved(UFG::SocialLogData_AwardAchieved *this, unsigned __int64 timeStamp, int leaderboardId, int score)
{
  int v4; // ebp
  int v5; // edi
  unsigned __int64 v6; // rbx
  UFG::SocialLogData_AwardAchieved *v7; // rsi

  v4 = score;
  v5 = leaderboardId;
  v6 = timeStamp;
  v7 = this;
  UFG::SocialLogData::SocialLogData((UFG::SocialLogData *)&this->vfptr);
  v7->vfptr = (UFG::OSuiteMessageVtbl *)&UFG::SocialLogData_AwardAchieved::`vftable';
  v7->m_aData = 0i64;
  v7->m_iCommId = 1;
  v7->m_iTimeStamp = v6;
  v7->m_iLeaderboardId = v5;
  v7->m_iScore = v4;
}

// File Line: 123
// RVA: 0x4914D0
void __fastcall UFG::SocialLogData_AwardAchieved::~SocialLogData_AwardAchieved(UFG::SocialLogData_AwardAchieved *this)
{
  UFG::SocialLogData_AwardAchieved *v1; // rbx
  char *v2; // rcx

  v1 = this;
  this->vfptr = (UFG::OSuiteMessageVtbl *)&UFG::SocialLogData_AwardAchieved::`vftable';
  v2 = this->m_aData;
  if ( v2 )
    operator delete[](v2);
  UFG::SocialLogData::~SocialLogData((UFG::SocialLogData *)&v1->vfptr);
}

// File Line: 138
// RVA: 0x4BA2E0
char *__fastcall UFG::SocialLogData_AwardAchieved::Serialize(UFG::SocialLogData_AwardAchieved *this)
{
  UFG::SocialLogData_AwardAchieved *v1; // rdi
  char *v2; // rcx
  int v3; // eax
  UFG::allocator::free_link *v4; // rax
  UFG::allocator::free_link *v5; // rbx
  int v6; // ecx
  int v7; // ecx
  char v9[8]; // [rsp+20h] [rbp-28h]
  int v; // [rsp+50h] [rbp+8h]
  UFG::SocialLogData::CommId source; // [rsp+58h] [rbp+10h]
  int v12; // [rsp+60h] [rbp+18h]
  int v13; // [rsp+68h] [rbp+20h]

  v1 = this;
  v2 = this->m_aData;
  if ( v2 )
    operator delete[](v2);
  v3 = v1->vfptr->Size((UFG::OSuiteMessage *)&v1->vfptr);
  v4 = UFG::qMalloc(v3, "SocialLogData_AwardAchieved", 0i64);
  source = v1->m_iCommId;
  v5 = v4;
  *(_QWORD *)v9 = v1->m_iTimeStamp;
  v6 = v1->m_iLeaderboardId;
  v1->m_aData = (char *)v4;
  v12 = v6;
  v7 = v1->m_iScore;
  v = 0;
  v13 = v7;
  UFG::qEndianSwapBytes((char *)&v, 4u);
  UFG::qEndianSwapBytes((char *)&source, 4u);
  UFG::qEndianSwapBytes(v9, 8u);
  UFG::qEndianSwapBytes((char *)&v12, 4u);
  UFG::qEndianSwapBytes((char *)&v13, 4u);
  UFG::qMemCopy(v5, &v, 4u);
  UFG::qMemCopy((char *)&v5->mNext + 4, &source, 4u);
  UFG::qMemCopy(&v5[1], v9, 8u);
  UFG::qMemCopy(&v5[2], &v12, 4u);
  UFG::qMemCopy((char *)&v5[2].mNext + 4, &v13, 4u);
  return v1->m_aData;
}

// File Line: 179
// RVA: 0x49B450
void __fastcall UFG::SocialLogData_AwardAchieved::Deserialize(UFG::SocialLogData_AwardAchieved *this, char *data)
{
  char *v2; // r14
  char *v3; // rbx

  v2 = (char *)this;
  v3 = data;
  UFG::qMemCopy(&this->m_iVersion, data, 4u);
  UFG::qMemCopy(v2 + 44, v3 + 4, 4u);
  UFG::qMemCopy(v2 + 48, v3 + 8, 8u);
  UFG::qMemCopy(v2 + 56, v3 + 16, 4u);
  UFG::qMemCopy(v2 + 60, v3 + 20, 4u);
  UFG::qEndianSwapBytes(v2 + 40, 4u);
  UFG::qEndianSwapBytes(v2 + 44, 4u);
  UFG::qEndianSwapBytes(v2 + 48, 8u);
  UFG::qEndianSwapBytes(v2 + 56, 4u);
  UFG::qEndianSwapBytes(v2 + 60, 4u);
}

// File Line: 213
// RVA: 0x48D8D0
void __fastcall UFG::SocialLogData_BeatChallenge::SocialLogData_BeatChallenge(UFG::SocialLogData_BeatChallenge *this, unsigned __int64 timeStamp, int leaderboardId, int score, UFG::OnlineId *srcOnlineId, UFG::qString *srcOnlineName, UFG::OnlineId *dstOnlineId, UFG::qString *dstOnlineName)
{
  int v8; // esi
  int v9; // edi
  unsigned __int64 v10; // rbx
  UFG::SocialLogData_BeatChallenge *v11; // r14

  v8 = score;
  v9 = leaderboardId;
  v10 = timeStamp;
  v11 = this;
  UFG::SocialLogData::SocialLogData((UFG::SocialLogData *)&this->vfptr);
  v11->vfptr = (UFG::OSuiteMessageVtbl *)&UFG::SocialLogData_BeatChallenge::`vftable';
  v11->m_iHasSent = 0;
  v11->m_aData = 0i64;
  v11->m_iCommId = 3;
  v11->m_iTimeStamp = v10;
  v11->m_iLeaderboardId = v9;
  v11->m_iScore = v8;
  v11->m_cSrcOnlineId.m_SteamId.m_steamid.m_unAll64Bits = srcOnlineId->m_SteamId.m_steamid.m_unAll64Bits;
  UFG::qString::Set(&v11->m_sSrcOnlineName, srcOnlineName->mData, srcOnlineName->mLength, 0i64, 0);
  v11->m_cDstOnlineId.m_SteamId.m_steamid.m_unAll64Bits = dstOnlineId->m_SteamId.m_steamid.m_unAll64Bits;
  UFG::qString::Set(&v11->m_sDstOnlineName, dstOnlineName->mData, dstOnlineName->mLength, 0i64, 0);
}

// File Line: 225
// RVA: 0x491510
void __fastcall UFG::SocialLogData_BeatChallenge::~SocialLogData_BeatChallenge(UFG::SocialLogData_BeatChallenge *this)
{
  UFG::SocialLogData_BeatChallenge *v1; // rbx
  char *v2; // rcx

  v1 = this;
  this->vfptr = (UFG::OSuiteMessageVtbl *)&UFG::SocialLogData_BeatChallenge::`vftable';
  v2 = this->m_aData;
  if ( v2 )
    operator delete[](v2);
  UFG::SocialLogData::~SocialLogData((UFG::SocialLogData *)&v1->vfptr);
}

// File Line: 233
// RVA: 0x4C8F50
signed __int64 __fastcall UFG::SocialLogData_BeatChallenge::VariableBindingListSize(UFG::SocialLogData_Challenge *this)
{
  return 148i64;
}

// File Line: 245
// RVA: 0x4BA410
char *__fastcall UFG::SocialLogData_BeatChallenge::Serialize(UFG::SocialLogData_BeatChallenge *this)
{
  UFG::SocialLogData_BeatChallenge *v1; // rdi
  char *v2; // rcx
  int v3; // eax
  UFG::allocator::free_link *v4; // rax
  UFG::allocator::free_link *v5; // rbx
  char *v6; // rbx
  char v8[4]; // [rsp+20h] [rbp-79h]
  char v9[8]; // [rsp+28h] [rbp-71h]
  __int64 v10; // [rsp+30h] [rbp-69h]
  UFG::qString v11; // [rsp+38h] [rbp-61h]
  UFG::qString v12; // [rsp+60h] [rbp-39h]
  UFG::qString v13; // [rsp+88h] [rbp-11h]
  UFG::qString result; // [rsp+B0h] [rbp+17h]
  int v; // [rsp+100h] [rbp+67h]
  UFG::SocialLogData::CommId source; // [rsp+108h] [rbp+6Fh]
  int v17; // [rsp+110h] [rbp+77h]
  int v18; // [rsp+118h] [rbp+7Fh]

  v10 = -2i64;
  v1 = this;
  v2 = this->m_aData;
  if ( v2 )
    operator delete[](v2);
  v3 = v1->vfptr->Size((UFG::OSuiteMessage *)&v1->vfptr);
  v4 = UFG::qMalloc(v3, "SocialLogData_BeatChallenge", 0i64);
  v5 = v4;
  v1->m_aData = (char *)v4;
  v = 0;
  source = v1->m_iCommId;
  *(_QWORD *)v9 = v1->m_iTimeStamp;
  v17 = v1->m_iLeaderboardId;
  v18 = v1->m_iScore;
  UFG::OnlineId::ToString(&v1->m_cSrcOnlineId, &result);
  UFG::qString::qString(&v12, &v1->m_sSrcOnlineName);
  UFG::OnlineId::ToString(&v1->m_cDstOnlineId, &v13);
  UFG::qString::qString(&v11, &v1->m_sDstOnlineName);
  *(_DWORD *)v8 = v1->m_iHasSent;
  UFG::qEndianSwapBytes((char *)&v, 4u);
  UFG::qEndianSwapBytes((char *)&source, 4u);
  UFG::qEndianSwapBytes(v9, 8u);
  UFG::qEndianSwapBytes((char *)&v17, 4u);
  UFG::qEndianSwapBytes((char *)&v18, 4u);
  UFG::qEndianSwapBytes(v8, 4u);
  UFG::qMemCopy(v5, &v, 4u);
  UFG::qMemCopy((char *)&v5->mNext + 4, &source, 4u);
  UFG::qMemCopy(&v5[1], v9, 8u);
  UFG::qMemCopy(&v5[2], &v17, 4u);
  UFG::qMemCopy((char *)&v5[2].mNext + 4, &v18, 4u);
  UFG::qMemCopy(&v5[3], result.mData, 0x20u);
  UFG::qMemCopy(&v5[7], v12.mData, 0x20u);
  UFG::qMemCopy(&v5[11], v13.mData, 0x20u);
  UFG::qMemCopy(&v5[15], v11.mData, 0x20u);
  UFG::qMemCopy(&v5[19], v8, 4u);
  v6 = v1->m_aData;
  UFG::qString::~qString(&v11);
  UFG::qString::~qString(&v13);
  UFG::qString::~qString(&v12);
  UFG::qString::~qString(&result);
  return v6;
}

// File Line: 302
// RVA: 0x49B540
void __fastcall UFG::SocialLogData_Challenge::Deserialize(UFG::SocialLogData_Challenge *this, char *data)
{
  char *v2; // rbx
  char *v3; // rdi
  const void *v4; // rdx
  __int64 v5; // rbx
  __int64 *v6; // rcx
  __int64 **v7; // rax
  __int64 *v8; // rcx
  __int64 **v9; // rax
  __int64 *v10; // [rsp+20h] [rbp-81h]
  __int64 **v11; // [rsp+28h] [rbp-79h]
  unsigned __int64 dest; // [rsp+30h] [rbp-71h]
  __int64 *v13; // [rsp+38h] [rbp-69h]
  __int64 **v14; // [rsp+40h] [rbp-61h]
  unsigned __int64 v15; // [rsp+48h] [rbp-59h]
  char v16; // [rsp+58h] [rbp-49h]
  char text; // [rsp+80h] [rbp-21h]
  char v18; // [rsp+A8h] [rbp+7h]
  __int64 v19; // [rsp+108h] [rbp+67h]

  v2 = data;
  v3 = (char *)this;
  UFG::qMemCopy(&this->m_iVersion, data, 4u);
  UFG::qMemCopy(v3 + 44, v2 + 4, 4u);
  UFG::qMemSet(&dest, 0, 0x21u);
  UFG::qMemSet(&text, 0, 0x21u);
  UFG::qMemSet(&v16, 0, 0x21u);
  UFG::qMemSet(&v18, 0, 0x21u);
  UFG::qMemCopy(v3 + 48, v2 + 8, 8u);
  UFG::qMemCopy(v3 + 56, v2 + 16, 4u);
  UFG::qMemCopy(v3 + 60, v2 + 20, 4u);
  UFG::qMemCopy(&dest, v2 + 24, 0x20u);
  UFG::qMemCopy(&text, v2 + 56, 0x20u);
  UFG::qMemCopy(&v16, v2 + 88, 0x20u);
  UFG::qMemCopy(&v18, v2 + 120, 0x20u);
  v4 = v2 + 152;
  v5 = v19;
  UFG::qMemCopy((void *)(v19 + 192), v4, 4u);
  UFG::qEndianSwapBytes(v3 + 40, 4u);
  UFG::qEndianSwapBytes(v3 + 44, 4u);
  UFG::qEndianSwapBytes(v3 + 48, 8u);
  UFG::qEndianSwapBytes(v3 + 56, 4u);
  UFG::qEndianSwapBytes(v3 + 60, 4u);
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
  UFG::qString::Set((UFG::qString *)(v5 + 88), &text);
  v13 = (__int64 *)&v13;
  v14 = &v13;
  LODWORD(v15) = 0;
  HIDWORD(v10) &= 0xFF0FFFFF;
  HIBYTE(v10) = 0;
  HIDWORD(v10) &= 0xFFF00000;
  v15 = UFG::qToUInt64(&v16, 0i64);
  *(_QWORD *)(v5 + 144) = v15;
  v8 = v13;
  v9 = v14;
  v13[1] = (__int64)v14;
  *v9 = v8;
  v13 = (__int64 *)&v13;
  v14 = &v13;
  UFG::qString::Set((UFG::qString *)(v5 + 152), &v18);
}

// File Line: 360
// RVA: 0x48D9B0
void __fastcall UFG::SocialLogData_Challenge::SocialLogData_Challenge(UFG::SocialLogData_Challenge *this, unsigned __int64 timeStamp, int leaderboardId, int score, UFG::OnlineId *srcOnlineId, UFG::qString *srcOnlineName, UFG::OnlineId *dstOnlineId, UFG::qString *dstOnlineName)
{
  int v8; // esi
  int v9; // edi
  unsigned __int64 v10; // rbx
  UFG::SocialLogData_Challenge *v11; // r14

  v8 = score;
  v9 = leaderboardId;
  v10 = timeStamp;
  v11 = this;
  UFG::SocialLogData::SocialLogData((UFG::SocialLogData *)&this->vfptr);
  v11->vfptr = (UFG::OSuiteMessageVtbl *)&UFG::SocialLogData_Challenge::`vftable';
  v11->m_iHasBeaten = 0;
  v11->m_aData = 0i64;
  v11->m_iCommId = 4;
  v11->m_iTimeStamp = v10;
  v11->m_iLeaderboardId = v9;
  v11->m_iScore = v8;
  v11->m_cSrcOnlineId.m_SteamId.m_steamid.m_unAll64Bits = srcOnlineId->m_SteamId.m_steamid.m_unAll64Bits;
  UFG::qString::Set(&v11->m_sSrcOnlineName, srcOnlineName->mData, srcOnlineName->mLength, 0i64, 0);
  v11->m_cDstOnlineId.m_SteamId.m_steamid.m_unAll64Bits = dstOnlineId->m_SteamId.m_steamid.m_unAll64Bits;
  UFG::qString::Set(&v11->m_sDstOnlineName, dstOnlineName->mData, dstOnlineName->mLength, 0i64, 0);
}

// File Line: 372
// RVA: 0x491550
void __fastcall UFG::SocialLogData_Challenge::~SocialLogData_Challenge(UFG::SocialLogData_Challenge *this)
{
  UFG::SocialLogData_Challenge *v1; // rbx
  char *v2; // rcx

  v1 = this;
  this->vfptr = (UFG::OSuiteMessageVtbl *)&UFG::SocialLogData_Challenge::`vftable';
  v2 = this->m_aData;
  if ( v2 )
    operator delete[](v2);
  UFG::SocialLogData::~SocialLogData((UFG::SocialLogData *)&v1->vfptr);
}

// File Line: 392
// RVA: 0x4BA620
char *__fastcall UFG::SocialLogData_Challenge::Serialize(UFG::SocialLogData_Challenge *this)
{
  UFG::SocialLogData_Challenge *v1; // rdi
  char *v2; // rcx
  int v3; // eax
  UFG::allocator::free_link *v4; // rax
  UFG::allocator::free_link *v5; // rbx
  char *v6; // rbx
  char v8[4]; // [rsp+20h] [rbp-79h]
  char v9[8]; // [rsp+28h] [rbp-71h]
  __int64 v10; // [rsp+30h] [rbp-69h]
  UFG::qString v11; // [rsp+38h] [rbp-61h]
  UFG::qString v12; // [rsp+60h] [rbp-39h]
  UFG::qString v13; // [rsp+88h] [rbp-11h]
  UFG::qString result; // [rsp+B0h] [rbp+17h]
  int v; // [rsp+100h] [rbp+67h]
  UFG::SocialLogData::CommId source; // [rsp+108h] [rbp+6Fh]
  int v17; // [rsp+110h] [rbp+77h]
  int v18; // [rsp+118h] [rbp+7Fh]

  v10 = -2i64;
  v1 = this;
  v2 = this->m_aData;
  if ( v2 )
    operator delete[](v2);
  v3 = v1->vfptr->Size((UFG::OSuiteMessage *)&v1->vfptr);
  v4 = UFG::qMalloc(v3, "SocialLogData_Challenge", 0i64);
  v5 = v4;
  v1->m_aData = (char *)v4;
  v = 0;
  source = v1->m_iCommId;
  *(_QWORD *)v9 = v1->m_iTimeStamp;
  v17 = v1->m_iLeaderboardId;
  v18 = v1->m_iScore;
  UFG::OnlineId::ToString(&v1->m_cSrcOnlineId, &result);
  UFG::qString::qString(&v12, &v1->m_sSrcOnlineName);
  UFG::OnlineId::ToString(&v1->m_cDstOnlineId, &v13);
  UFG::qString::qString(&v11, &v1->m_sDstOnlineName);
  *(_DWORD *)v8 = v1->m_iHasBeaten;
  UFG::qEndianSwapBytes((char *)&v, 4u);
  UFG::qEndianSwapBytes((char *)&source, 4u);
  UFG::qEndianSwapBytes(v9, 8u);
  UFG::qEndianSwapBytes((char *)&v17, 4u);
  UFG::qEndianSwapBytes((char *)&v18, 4u);
  UFG::qEndianSwapBytes(v8, 4u);
  UFG::qMemCopy(v5, &v, 4u);
  UFG::qMemCopy((char *)&v5->mNext + 4, &source, 4u);
  UFG::qMemCopy(&v5[1], v9, 8u);
  UFG::qMemCopy(&v5[2], &v17, 4u);
  UFG::qMemCopy((char *)&v5[2].mNext + 4, &v18, 4u);
  UFG::qMemCopy(&v5[3], result.mData, 0x20u);
  UFG::qMemCopy(&v5[7], v12.mData, 0x20u);
  UFG::qMemCopy(&v5[11], v13.mData, 0x20u);
  UFG::qMemCopy(&v5[15], v11.mData, 0x20u);
  UFG::qMemCopy(&v5[19], v8, 4u);
  v6 = v1->m_aData;
  UFG::qString::~qString(&v11);
  UFG::qString::~qString(&v13);
  UFG::qString::~qString(&v12);
  UFG::qString::~qString(&result);
  return v6;
}

