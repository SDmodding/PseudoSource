// File Line: 117
// RVA: 0x149D50
// attributes: thunk
UFG::BIGFileIndex *__fastcall WWiseOSFileWrapper::Open(
        const char *filename,
        UFG::qFileAccessType access_type,
        bool warn_if_fail,
        void (__fastcall *callback)(UFG::qFileOp *, void *),
        void *callback_param)
{
  return UFG::StreamFileWrapper::Open(filename, access_type, warn_if_fail, callback, callback_param);
}

// File Line: 138
// RVA: 0x143D80
void __fastcall WWiseOSFileWrapper::Close(void *hFile)
{
  if ( hFile )
    UFG::StreamFileWrapper::Close(hFile);
}

// File Line: 191
// RVA: 0x145DC0
// attributes: thunk
__int64 __fastcall WWiseOSFileWrapper::GetFileSize(void *hFile)
{
  return UFG::StreamFileWrapper::GetFileSizeRaw(hFile);
}

// File Line: 286
// RVA: 0x14AE70
__int64 __fastcall WWiseOSFileWrapper::Read(
        void *hFile,
        void *buffer,
        __int64 size,
        __int64 seek_offset,
        UFG::qFileSeekType seek_type,
        void (__fastcall *callback)(UFG::qFileOp *, void *),
        void *callback_param,
        WWiseOSFileWrapper::QUEUE_CLASS priority,
        unsigned int audio_priority)
{
  UFG::BIGFileSize fileSize; // [rsp+50h] [rbp-18h] BYREF

  fileSize.compressed_size = size;
  fileSize.load_offset = 0;
  fileSize.compressed_extra = 0;
  fileSize.uncompressed_size = size;
  return UFG::StreamFileWrapper::Read(
           hFile,
           priority,
           buffer,
           &fileSize,
           seek_offset,
           seek_type,
           callback,
           callback_param,
           audio_priority);
}

