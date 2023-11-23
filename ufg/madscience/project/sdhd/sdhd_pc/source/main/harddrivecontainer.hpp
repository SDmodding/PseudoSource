// File Line: 95
// RVA: 0xCF3A0
void __fastcall UFG::HddSaveFile::HddSaveFile(
        UFG::HddSaveFile *this,
        const char *fileName,
        void *data,
        unsigned int fileSize,
        UFG::eHDD_SAVE_FILE_TYPE fileType)
{
  char *v9; // rax

  this->mPrev = this;
  this->mNext = this;
  UFG::qString::qString(&this->mFileName);
  UFG::qString::qString(&this->mReferenceFileName);
  UFG::qString::qString(&this->mDescription);
  UFG::qString::qString(&this->mTitle);
  UFG::qString::Set(&this->mFileName, fileName);
  this->mFileType = fileType;
  this->mFileSize = fileSize;
  v9 = UFG::qMalloc(fileSize, "Hdd File Data", 0i64);
  this->mData = v9;
  this->mAdjustFileSize = 0;
  if ( data )
    UFG::qMemCopy(v9, data, fileSize);
}

