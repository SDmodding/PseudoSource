// File Line: 476
// RVA: 0xA341B0
void __fastcall UFG::HDDmanager::AddSaveDataFileName(UFG::HDDmanager *this, const char *pFileName)
{
  UFG::qString *v4; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v5; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v6; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *mPrev; // rax

  UFG::qMutex::Lock((LPCRITICAL_SECTION)&this->mSaveDataFileMutex);
  v4 = (UFG::qString *)UFG::qMalloc(0x28ui64, "HDDmanager", 0i64);
  if ( v4 )
  {
    UFG::qString::qString(v4, pFileName);
    v6 = v5;
  }
  else
  {
    v6 = 0i64;
  }
  mPrev = this->mSaveDataFiles.mNode.mPrev;
  mPrev->mNext = v6;
  v6->mPrev = mPrev;
  v6->mNext = &this->mSaveDataFiles.mNode;
  this->mSaveDataFiles.mNode.mPrev = v6;
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&this->mSaveDataFileMutex);
}

// File Line: 484
// RVA: 0xA345D0
void __fastcall UFG::HDDmanager::ResetSaveDataFileNameList(UFG::HDDmanager *this)
{
  _RTL_CRITICAL_SECTION *p_mSaveDataFileMutex; // rdi
  UFG::qList<UFG::qString,UFG::qString,1,0> *p_mSaveDataFiles; // rbx
  UFG::qList<UFG::qString,UFG::qString,1,0> *i; // rax
  UFG::qNode<UFG::qString,UFG::qString> *mPrev; // r8
  UFG::qNode<UFG::qString,UFG::qString> *mNext; // rdx

  p_mSaveDataFileMutex = (_RTL_CRITICAL_SECTION *)&this->mSaveDataFileMutex;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&this->mSaveDataFileMutex);
  p_mSaveDataFiles = &this->mSaveDataFiles;
  for ( i = (UFG::qList<UFG::qString,UFG::qString,1,0> *)p_mSaveDataFiles->mNode.mNext;
        i != p_mSaveDataFiles;
        i = (UFG::qList<UFG::qString,UFG::qString,1,0> *)p_mSaveDataFiles->mNode.mNext )
  {
    mPrev = i->mNode.mPrev;
    mNext = i->mNode.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    i->mNode.mPrev = &i->mNode;
    i->mNode.mNext = &i->mNode;
  }
  UFG::qMutex::Unlock(p_mSaveDataFileMutex);
}

// File Line: 492
// RVA: 0x4ABFE0
__int64 __fastcall UFG::HDDmanager::IsFileNameInList(UFG::HDDmanager *this, const char *pFileName)
{
  _RTL_CRITICAL_SECTION *p_mSaveDataFileMutex; // r14
  unsigned __int8 v5; // si
  UFG::qNode<UFG::qString,UFG::qString> *mNext; // rbx
  UFG::qList<UFG::qString,UFG::qString,1,0> *p_mSaveDataFiles; // rdi

  p_mSaveDataFileMutex = (_RTL_CRITICAL_SECTION *)&this->mSaveDataFileMutex;
  v5 = 0;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&this->mSaveDataFileMutex);
  mNext = this->mSaveDataFiles.mNode.mNext;
  p_mSaveDataFiles = &this->mSaveDataFiles;
  if ( mNext != (UFG::qNode<UFG::qString,UFG::qString> *)p_mSaveDataFiles )
  {
    while ( (unsigned int)UFG::qStringCompare(pFileName, (const char *)mNext[1].mNext, -1) )
    {
      mNext = mNext->mNext;
      if ( mNext == (UFG::qNode<UFG::qString,UFG::qString> *)p_mSaveDataFiles )
        goto LABEL_6;
    }
    v5 = 1;
  }
LABEL_6:
  UFG::qMutex::Unlock(p_mSaveDataFileMutex);
  return v5;
}

