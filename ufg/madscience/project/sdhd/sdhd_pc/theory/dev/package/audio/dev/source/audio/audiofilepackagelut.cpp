// File Line: 34
// RVA: 0x141300
void __fastcall UFG::AudioFilePackageLUT::~AudioFilePackageLUT(UFG::AudioFilePackageLUT *this)
{
  this->vfptr = (UFG::AudioFilePackageLUTVtbl *)&UFG::AudioFilePackageLUT::`vftable;
}

// File Line: 43
// RVA: 0x14C610
signed __int64 __fastcall UFG::AudioFilePackageLUT::Setup(
        UFG::AudioFilePackageLUT *this,
        char *in_pData,
        unsigned int in_uHeaderSize)
{
  char *v3; // r11
  char *v4; // r10
  UFG::AudioFilePackageLUT::StringMap *v6; // rdx
  UFG::AudioFilePackageLUT::FileLUT *v7; // rdx

  v3 = in_pData + 12;
  v4 = in_pData + 16;
  if ( in_uHeaderSize < *((unsigned int *)in_pData + 4)
                      + 24i64
                      + *((unsigned int *)in_pData + 3)
                      + (unsigned __int64)*((unsigned int *)in_pData + 5)
    || !*((_DWORD *)in_pData + 2) )
  {
    return 2i64;
  }
  v6 = (UFG::AudioFilePackageLUT::StringMap *)(in_pData + 24);
  this->m_pLangMap = v6;
  v7 = (UFG::AudioFilePackageLUT::FileLUT *)((char *)v6 + *(unsigned int *)v3);
  this->m_pSoundBanks = v7;
  this->m_pStmFiles = (UFG::AudioFilePackageLUT::FileLUT *)((char *)v7 + *(unsigned int *)v4);
  return 1i64;
}

// File Line: 108
// RVA: 0x148E50
UFG::AudioFilePackageLUT::FileLUT *__fastcall UFG::AudioFilePackageLUT::LookupFile(
        UFG::AudioFilePackageLUT *this,
        unsigned int in_uID,
        UFG::AudioFilePackageLUT::FileLUT *in_pLut,
        bool in_bIsLanguageSpecific)
{
  signed int v4; // r9d
  signed int v5; // r10d
  UFG::AudioFilePackageLUT::FileLUT *v6; // rbx
  int v7; // eax
  unsigned int m_uNumFiles; // ecx

  v4 = 0;
  v5 = in_pLut->m_uNumFiles - 1;
  v6 = in_pLut + 1;
  while ( 1 )
  {
    v7 = v4 + (v5 - v4) / 2;
    m_uNumFiles = v6[6 * v7].m_uNumFiles;
    if ( m_uNumFiles <= in_uID )
      break;
    v5 = v7 - 1;
LABEL_6:
    if ( v4 > v5 )
      return 0i64;
  }
  if ( m_uNumFiles < in_uID )
  {
    v4 = v7 + 1;
    goto LABEL_6;
  }
  return &v6[6 * v7];
}

// File Line: 181
// RVA: 0x146640
signed __int64 __fastcall UFG::AudioFilePackageLUT::GetSoundBankID(
        UFG::AudioFilePackageLUT *this,
        const wchar_t *in_pszBankName)
{
  __int64 v2; // rax
  unsigned __int64 v3; // rax
  unsigned __int64 v4; // rsi
  __int64 v5; // rcx
  signed __int64 v6; // rcx
  void *v7; // rsp
  void *v8; // rsp
  unsigned __int64 v9; // rbx
  __int64 v10; // rax
  __int64 v11; // rbx
  __int16 *v12; // rax
  __int16 _Dst[4]; // [rsp+20h] [rbp+0h] BYREF

  if ( !this->m_pSoundBanks )
    return 0xFFFFFFFFi64;
  v2 = -1i64;
  do
    ++v2;
  while ( in_pszBankName[v2] );
  v3 = (unsigned int)(v2 + 1);
  v4 = (unsigned int)v3;
  v3 *= 2i64;
  v5 = v3 + 15;
  if ( v3 + 15 <= v3 )
    v5 = 0xFFFFFFFFFFFFFF0i64;
  v6 = v5 & 0xFFFFFFFFFFFFFFF0ui64;
  v7 = alloca(v6);
  v8 = alloca(v6);
  v9 = v4 - 1;
  v10 = -1i64;
  do
    ++v10;
  while ( in_pszBankName[v10] );
  if ( v9 >= v10 + 1 )
  {
    v11 = -1i64;
    do
      ++v11;
    while ( in_pszBankName[v11] );
    v9 = v11 + 1;
  }
  wcsncpy_s((unsigned __int16 *)_Dst, v4, in_pszBankName, v9);
  v12 = _Dst;
  _Dst[v9] = 0;
  if ( _Dst[0] )
  {
    while ( *v12 != 0x2E )
    {
      if ( !*++v12 )
        return AK::SoundEngine::GetIDFromString((const wchar_t *)_Dst);
    }
    *v12 = 0;
  }
  return AK::SoundEngine::GetIDFromString((const wchar_t *)_Dst);
}

// File Line: 210
// RVA: 0x145DD0
__int64 __fastcall UFG::AudioFilePackageLUT::StringMap::GetID(
        UFG::AudioFilePackageLUT::StringMap *this,
        const wchar_t *in_pszString)
{
  unsigned __int64 v2; // rbx
  __int64 v5; // rdx
  unsigned __int64 v6; // rdx
  unsigned __int64 v7; // rcx
  signed __int64 v8; // rcx
  void *v9; // rsp
  void *v10; // rsp
  unsigned __int64 v11; // rdi
  __int64 v12; // rax
  __int64 v13; // rdi
  unsigned __int64 i; // rdx
  __int16 v15; // cx
  signed int v16; // r11d
  signed int v17; // r10d
  int v18; // r9d
  char *v19; // rcx
  char *v20; // r8
  unsigned __int16 v21; // dx
  int v22; // eax
  __int16 _Dst[8]; // [rsp+20h] [rbp+0h] BYREF

  v2 = -1i64;
  v5 = -1i64;
  do
    ++v5;
  while ( in_pszString[v5] );
  v6 = v5 + 1;
  v7 = 2 * v6 + 15;
  if ( v7 <= 2 * v6 )
    v7 = 0xFFFFFFFFFFFFFF0i64;
  v8 = v7 & 0xFFFFFFFFFFFFFFF0ui64;
  v9 = alloca(v8);
  v10 = alloca(v8);
  v11 = v6 - 1;
  v12 = -1i64;
  do
    ++v12;
  while ( in_pszString[v12] );
  if ( v11 >= v12 + 1 )
  {
    v13 = -1i64;
    do
      ++v13;
    while ( in_pszString[v13] );
    v11 = v13 + 1;
  }
  wcsncpy_s((unsigned __int16 *)_Dst, v6, in_pszString, v11);
  _Dst[v11] = 0;
  do
    ++v2;
  while ( _Dst[v2] );
  for ( i = 0i64; i < v2; ++i )
  {
    v15 = _Dst[i];
    if ( (unsigned __int16)(v15 - 65) <= 0x19u )
      _Dst[i] = v15 + 32;
  }
  v16 = 0;
  v17 = this->m_uNumStrings - 1;
  while ( 1 )
  {
    v18 = v16 + (v17 - v16) / 2;
    v19 = (char *)this + this[2 * v18 + 1].m_uNumStrings;
    v20 = (char *)((char *)_Dst - v19);
    while ( 1 )
    {
      v21 = *(_WORD *)v19;
      if ( *(_WORD *)v19 != *(_WORD *)&v20[(_QWORD)v19] )
        break;
      v19 += 2;
      if ( !v21 )
      {
        v22 = 0;
        goto LABEL_23;
      }
    }
    v22 = v21 < *(_WORD *)&v20[(_QWORD)v19] ? -1 : 1;
LABEL_23:
    if ( !v22 )
      return this[2 * v18 + 2].m_uNumStrings;
    if ( v22 <= 0 )
      v16 = v18 + 1;
    else
      v17 = v18 - 1;
    if ( v16 > v17 )
      return 0i64;
  }
}

