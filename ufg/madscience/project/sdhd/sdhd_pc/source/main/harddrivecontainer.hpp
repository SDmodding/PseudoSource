// File Line: 95
// RVA: 0xCF3A0
void __fastcall UFG::HddSaveFile::HddSaveFile(UFG::HddSaveFile *this, const char *fileName, void *data, unsigned int fileSize, UFG::eHDD_SAVE_FILE_TYPE fileType)
{
  unsigned int v5; // ebp
  void *v6; // r14
  const char *v7; // rdi
  UFG::HddSaveFile *v8; // rsi
  char *v9; // rax

  v5 = fileSize;
  v6 = data;
  v7 = fileName;
  v8 = this;
  this->mPrev = (UFG::qNode<UFG::HddSaveFile,UFG::HddSaveFile> *)&this->mPrev;
  this->mNext = (UFG::qNode<UFG::HddSaveFile,UFG::HddSaveFile> *)&this->mPrev;
  UFG::qString::qString(&this->mFileName);
  UFG::qString::qString(&v8->mReferenceFileName);
  UFG::qString::qString(&v8->mDescription);
  UFG::qString::qString(&v8->mTitle);
  UFG::qString::Set(&v8->mFileName, v7);
  v8->mFileType = fileType;
  v8->mFileSize = v5;
  v9 = UFG::qMalloc(v5, "Hdd File Data", 0i64);
  v8->mData = v9;
  v8->mAdjustFileSize = 0;
  if ( v6 )
    UFG::qMemCopy(v9, v6, v5);
}

