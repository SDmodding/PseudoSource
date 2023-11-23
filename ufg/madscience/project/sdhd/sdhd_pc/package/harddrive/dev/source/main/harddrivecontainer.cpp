// File Line: 75
// RVA: 0xCF370
void __fastcall UFG::HddFileContainer::HddFileContainer(UFG::HddFileContainer *this)
{
  *(_QWORD *)&this->TotalFileSize = 0i64;
  this->FileList.mNode.mPrev = &this->FileList.mNode;
  this->FileList.mNode.mNext = &this->FileList.mNode;
}

// File Line: 80
// RVA: 0xCF4A0
UFG::HddSaveFile *__fastcall UFG::HddFileContainer::Add(
        UFG::HddFileContainer *this,
        const char *fName,
        void *data,
        unsigned int fSize,
        UFG::eHDD_SAVE_FILE_TYPE fType)
{
  char *v9; // rax
  __int64 v10; // rax
  __int64 v11; // rdx
  UFG::qNode<UFG::HddSaveFile,UFG::HddSaveFile> *mPrev; // rax

  v9 = UFG::qMalloc(0xD0ui64, "HddFile", 0i64);
  if ( v9 )
  {
    UFG::HddSaveFile::HddSaveFile((UFG::HddSaveFile *)v9, fName, data, fSize, fType);
    v11 = v10;
  }
  else
  {
    v11 = 0i64;
  }
  this->TotalFileSize += *(_DWORD *)(v11 + 104);
  ++this->ContainerCount;
  mPrev = this->FileList.mNode.mPrev;
  mPrev->mNext = (UFG::qNode<UFG::HddSaveFile,UFG::HddSaveFile> *)v11;
  *(_QWORD *)v11 = mPrev;
  *(_QWORD *)(v11 + 8) = &this->FileList;
  this->FileList.mNode.mPrev = (UFG::qNode<UFG::HddSaveFile,UFG::HddSaveFile> *)v11;
  this->currentFile = (UFG::HddSaveFile *)this->FileList.mNode.mNext;
  return (UFG::HddSaveFile *)v11;
}

// File Line: 133
// RVA: 0xCF640
bool __fastcall UFG::HddFileContainer::IsEndOfList(UFG::HddFileContainer *this)
{
  return this->currentFile == (UFG::HddSaveFile *)&this->FileList;
}

// File Line: 153
// RVA: 0xCF650
void __fastcall UFG::HddFileContainer::SetCurrentFileToNext(UFG::HddFileContainer *this)
{
  this->currentFile = (UFG::HddSaveFile *)this->currentFile->mNext;
}

// File Line: 157
// RVA: 0xCF610
void __fastcall UFG::HddFileContainer::EmptyContainer(UFG::HddFileContainer *this)
{
  UFG::qNode<UFG::HddSaveFile,UFG::HddSaveFile> *mNext; // rax
  UFG::qList<UFG::HddSaveFile,UFG::HddSaveFile,1,0> *i; // rcx

  mNext = this->FileList.mNode.mNext;
  for ( i = &this->FileList; mNext != (UFG::qNode<UFG::HddSaveFile,UFG::HddSaveFile> *)i; mNext = mNext->mNext )
    ;
  UFG::qList<UFG::HddSaveFile,UFG::HddSaveFile,1,0>::DeleteNodes(i);
  *(_QWORD *)&this->TotalFileSize = 0i64;
}

