// File Line: 29
// RVA: 0x143F40
UFG::TidoFilePackage *__fastcall UFG::TidoFilePackage::Create(
        void **in_hFile,
        const wchar_t *in_pszPackageName,
        unsigned int in_uHeaderSize,
        unsigned int in_uBlockAlign,
        char **out_pHeaderBuffer)
{
  __int64 v5; // rbx
  int Pool; // eax
  int v9; // esi
  char *Block; // rdi
  bool v12; // zf
  __int64 v13; // rbx
  char v14; // [rsp+30h] [rbp-448h] BYREF
  char *v15; // [rsp+38h] [rbp-440h]
  char *v16; // [rsp+40h] [rbp-438h]
  __int64 v17; // [rsp+48h] [rbp-430h]
  __int64 v18; // [rsp+50h] [rbp-428h]
  char dest[1024]; // [rsp+60h] [rbp-418h] BYREF

  v18 = -2i64;
  v5 = in_uHeaderSize;
  Pool = AK::MemoryMgr::CreatePool(0i64, in_uHeaderSize + 96, in_uHeaderSize + 96, 9u, in_uBlockAlign);
  v9 = Pool;
  if ( Pool == -1 )
    return 0i64;
  Block = (char *)AK::MemoryMgr::GetBlock(Pool);
  v15 = Block;
  v16 = &v14;
  v12 = &Block[v5] == 0i64;
  v13 = (__int64)&Block[v5];
  v17 = v13;
  if ( v12 )
  {
    v13 = 0i64;
  }
  else
  {
    *(_QWORD *)(v13 + 8) = 0i64;
    *(_QWORD *)v13 = &UFG::TidoFilePackage::`vftable;
    *(_QWORD *)(v13 + 16) = &UFG::AudioFilePackageLUT::`vftable;
    *(_WORD *)(v13 + 24) = 0;
    *(_QWORD *)(v13 + 32) = 0i64;
    *(_QWORD *)(v13 + 40) = 0i64;
    *(_QWORD *)(v13 + 48) = 0i64;
    *(_QWORD *)(v13 + 56) = *in_hFile;
    *(_DWORD *)(v13 + 68) = 0;
    *(_DWORD *)(v13 + 80) = v9;
    *(_QWORD *)(v13 + 88) = Block;
    *(_DWORD *)(v13 + 64) = ++`UFG::TidoFilePackage::TidoFilePackage::`2::s_uPackageID;
    *(_QWORD *)(v13 + 72) = 0i64;
  }
  memset(dest, 0, sizeof(dest));
  UFG::qWideStringCopy(dest, in_pszPackageName);
  *(_DWORD *)(v13 + 68) = UFG::qStringHash32(dest, 0xFFFFFFFF);
  *out_pHeaderBuffer = Block;
  return (UFG::TidoFilePackage *)v13;
}

// File Line: 66
// RVA: 0x144980
void __fastcall UFG::TidoFilePackage::Destroy(UFG::TidoFilePackage *this)
{
  int m_poolID; // ebx
  void *m_pToRelease; // rdi

  m_poolID = this->m_poolID;
  m_pToRelease = this->m_pToRelease;
  this->vfptr->__vecDelDtor(this, 0i64);
  if ( m_poolID != -1 )
  {
    if ( m_pToRelease )
      AK::MemoryMgr::ReleaseBlock(m_poolID, m_pToRelease);
    AK::MemoryMgr::DestroyPool(m_poolID);
  }
}

