// File Line: 75
// RVA: 0xCF370
void __fastcall UFG::HddFileContainer::HddFileContainer(UFG::HddFileContainer *this)
{
  UFG::qList<UFG::HddSaveFile,UFG::HddSaveFile,1,0> *v1; // [rsp+28h] [rbp+10h]

  *(_QWORD *)&this->TotalFileSize = 0i64;
  v1 = &this->FileList;
  v1->mNode.mPrev = &v1->mNode;
  v1->mNode.mNext = &v1->mNode;
}

// File Line: 80
// RVA: 0xCF4A0
UFG::HddSaveFile *__fastcall UFG::HddFileContainer::Add(UFG::HddFileContainer *this, const char *fName, void *data, unsigned int fSize, UFG::eHDD_SAVE_FILE_TYPE fType)
{
  unsigned int v5; // edi
  void *v6; // rsi
  const char *v7; // rbp
  UFG::HddFileContainer *v8; // rbx
  char *v9; // rax
  __int64 v10; // rax
  __int64 v11; // rdx
  UFG::qNode<UFG::HddSaveFile,UFG::HddSaveFile> *v12; // rax

  v5 = fSize;
  v6 = data;
  v7 = fName;
  v8 = this;
  v9 = UFG::qMalloc(0xD0ui64, "HddFile", 0i64);
  if ( v9 )
  {
    UFG::HddSaveFile::HddSaveFile((UFG::HddSaveFile *)v9, v7, v6, v5, fType);
    v11 = v10;
  }
  else
  {
    v11 = 0i64;
  }
  v8->TotalFileSize += *(_DWORD *)(v11 + 104);
  ++v8->ContainerCount;
  v12 = v8->FileList.mNode.mPrev;
  v12->mNext = (UFG::qNode<UFG::HddSaveFile,UFG::HddSaveFile> *)v11;
  *(_QWORD *)v11 = v12;
  *(_QWORD *)(v11 + 8) = (char *)v8 + 8;
  v8->FileList.mNode.mPrev = (UFG::qNode<UFG::HddSaveFile,UFG::HddSaveFile> *)v11;
  v8->currentFile = (UFG::HddSaveFile *)v8->FileList.mNode.mNext;
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
  UFG::qNode<UFG::HddSaveFile,UFG::HddSaveFile> *v1; // rax
  UFG::HddFileContainer *v2; // rbx
  UFG::qList<UFG::HddSaveFile,UFG::HddSaveFile,1,0> *i; // rcx

  v1 = this->FileList.mNode.mNext;
  v2 = this;
  for ( i = &this->FileList; v1 != (UFG::qNode<UFG::HddSaveFile,UFG::HddSaveFile> *)i; v1 = v1->mNext )
    ;
  UFG::qList<UFG::HddSaveFile,UFG::HddSaveFile,1,0>::DeleteNodes(i);
  *(_QWORD *)&v2->TotalFileSize = 0i64;
}

