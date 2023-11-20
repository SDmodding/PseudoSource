// File Line: 476
// RVA: 0xA341B0
void __fastcall UFG::HDDmanager::AddSaveDataFileName(UFG::HDDmanager *this, const char *pFileName)
{
  const char *v2; // rsi
  UFG::HDDmanager *v3; // rbx
  UFG::qString *v4; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v5; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v6; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v7; // rax

  v2 = pFileName;
  v3 = this;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&this->mSaveDataFileMutex);
  v4 = (UFG::qString *)UFG::qMalloc(0x28ui64, "HDDmanager", 0i64);
  if ( v4 )
  {
    UFG::qString::qString(v4, v2);
    v6 = v5;
  }
  else
  {
    v6 = 0i64;
  }
  v7 = v3->mSaveDataFiles.mNode.mPrev;
  v7->mNext = v6;
  v6->mPrev = v7;
  v6->mNext = &v3->mSaveDataFiles.mNode;
  v3->mSaveDataFiles.mNode.mPrev = v6;
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&v3->mSaveDataFileMutex);
}

// File Line: 484
// RVA: 0xA345D0
void __fastcall UFG::HDDmanager::ResetSaveDataFileNameList(UFG::HDDmanager *this)
{
  _RTL_CRITICAL_SECTION *v1; // rdi
  UFG::HDDmanager *v2; // rbx
  signed __int64 v3; // rbx
  __int64 *i; // rax
  __int64 v5; // r8
  _QWORD *v6; // rdx

  v1 = (_RTL_CRITICAL_SECTION *)&this->mSaveDataFileMutex;
  v2 = this;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&this->mSaveDataFileMutex);
  v3 = (signed __int64)&v2->mSaveDataFiles;
  for ( i = *(__int64 **)(v3 + 8); i != (__int64 *)v3; i = *(__int64 **)(v3 + 8) )
  {
    v5 = *i;
    v6 = (_QWORD *)i[1];
    *(_QWORD *)(v5 + 8) = v6;
    *v6 = v5;
    *i = (__int64)i;
    i[1] = (__int64)i;
  }
  UFG::qMutex::Unlock(v1);
}

// File Line: 492
// RVA: 0x4ABFE0
__int64 __fastcall UFG::HDDmanager::IsFileNameInList(UFG::HDDmanager *this, const char *pFileName)
{
  _RTL_CRITICAL_SECTION *v2; // r14
  const char *v3; // rbp
  UFG::HDDmanager *v4; // rdi
  unsigned __int8 v5; // si
  UFG::qNode<UFG::qString,UFG::qString> *v6; // rbx
  signed __int64 v7; // rdi

  v2 = (_RTL_CRITICAL_SECTION *)&this->mSaveDataFileMutex;
  v3 = pFileName;
  v4 = this;
  v5 = 0;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&this->mSaveDataFileMutex);
  v6 = v4->mSaveDataFiles.mNode.mNext;
  v7 = (signed __int64)&v4->mSaveDataFiles;
  if ( v6 != (UFG::qNode<UFG::qString,UFG::qString> *)v7 )
  {
    while ( (unsigned int)UFG::qStringCompare(v3, (const char *)v6[1].mNext, -1) )
    {
      v6 = v6->mNext;
      if ( v6 == (UFG::qNode<UFG::qString,UFG::qString> *)v7 )
        goto LABEL_6;
    }
    v5 = 1;
  }
LABEL_6:
  UFG::qMutex::Unlock(v2);
  return v5;
}

