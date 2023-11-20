// File Line: 29
// RVA: 0x143F40
UFG::TidoFilePackage *__fastcall UFG::TidoFilePackage::Create(void *const *in_hFile, const wchar_t *in_pszPackageName, unsigned int in_uHeaderSize, unsigned int in_uBlockAlign, char **out_pHeaderBuffer)
{
  __int64 v5; // rbx
  const wchar_t *v6; // rbp
  void *const *v7; // r14
  int v8; // eax
  int v9; // esi
  char *v11; // rdi
  bool v12; // zf
  __int64 v13; // rbx
  char v14; // [rsp+30h] [rbp-448h]
  char *v15; // [rsp+38h] [rbp-440h]
  char *v16; // [rsp+40h] [rbp-438h]
  __int64 v17; // [rsp+48h] [rbp-430h]
  __int64 v18; // [rsp+50h] [rbp-428h]
  char dest; // [rsp+60h] [rbp-418h]
  char Dst; // [rsp+61h] [rbp-417h]

  v18 = -2i64;
  v5 = in_uHeaderSize;
  v6 = in_pszPackageName;
  v7 = in_hFile;
  v8 = AK::MemoryMgr::CreatePool(0i64, in_uHeaderSize + 96, in_uHeaderSize + 96, 9u, in_uBlockAlign);
  v9 = v8;
  if ( v8 == -1 )
    return 0i64;
  v11 = (char *)AK::MemoryMgr::GetBlock(v8);
  v15 = v11;
  v16 = &v14;
  v12 = &v11[v5] == 0i64;
  v13 = (__int64)&v11[v5];
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
    *(void **)(v13 + 56) = *v7;
    *(_DWORD *)(v13 + 68) = 0;
    *(_DWORD *)(v13 + 80) = v9;
    *(_QWORD *)(v13 + 88) = v11;
    *(_DWORD *)(v13 + 64) = ++`UFG::TidoFilePackage::TidoFilePackage::`2::s_uPackageID;
    *(_QWORD *)(v13 + 72) = 0i64;
  }
  dest = 0;
  memset(&Dst, 0, 0x3FFui64);
  UFG::qWideStringCopy(&dest, v6);
  *(_DWORD *)(v13 + 68) = UFG::qStringHash32(&dest, 0xFFFFFFFF);
  *out_pHeaderBuffer = v11;
  return (UFG::TidoFilePackage *)v13;
}

// File Line: 66
// RVA: 0x144980
void __fastcall UFG::TidoFilePackage::Destroy(UFG::TidoFilePackage *this)
{
  int v1; // ebx
  void *v2; // rdi

  v1 = this->m_poolID;
  v2 = this->m_pToRelease;
  this->vfptr->__vecDelDtor(this, 0);
  if ( v1 != -1 )
  {
    if ( v2 )
      AK::MemoryMgr::ReleaseBlock(v1, v2);
    AK::MemoryMgr::DestroyPool(v1);
  }
}

