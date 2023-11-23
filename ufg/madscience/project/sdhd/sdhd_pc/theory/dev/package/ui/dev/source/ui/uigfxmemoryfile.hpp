// File Line: 28
// RVA: 0xA274B0
_BOOL8 __fastcall UFG::UIGfxMemoryFile::IsValid(UFG::UIGfxMemoryFile *this)
{
  return this->Valid;
}

// File Line: 34
// RVA: 0xA28330
__int64 __fastcall UFG::UIGfxMemoryFile::Tell(UFG::UIGfxMemoryFile *this)
{
  return (unsigned int)this->FileIndex;
}

// File Line: 35
// RVA: 0xA274D0
__int64 __fastcall UFG::UIGfxMemoryFile::LTell(UFG::UIGfxMemoryFile *this)
{
  return this->FileIndex;
}

// File Line: 37
// RVA: 0xA26280
__int64 __fastcall UFG::UIGfxMemoryFile::GetLength(ANTLR3_INPUT_STREAM_struct *input)
{
  return (unsigned int)input->charPositionInLine;
}

// File Line: 38
// RVA: 0xA274C0
__int64 __fastcall UFG::UIGfxMemoryFile::LGetLength(UFG::UIGfxMemoryFile *this)
{
  return this->FileSize;
}

// File Line: 41
// RVA: 0xA26080
bool __fastcall UFG::UIGfxMemoryFile::Close(UFG::UIGfxMemoryFile *this)
{
  this->Valid = 0;
  return 0;
}

// File Line: 57
// RVA: 0xA28090
__int64 __fastcall UFG::UIGfxMemoryFile::Read(UFG::UIGfxMemoryFile *this, char *pbufer, unsigned int numBytes)
{
  __int64 FileIndex; // rcx
  int FileSize; // r8d

  FileIndex = this->FileIndex;
  FileSize = this->FileSize;
  if ( (int)(FileIndex + numBytes) > FileSize )
    numBytes = FileSize - FileIndex;
  if ( (int)numBytes > 0 )
  {
    memmove(pbufer, &this->FileData[FileIndex], (int)numBytes);
    this->FileIndex += numBytes;
  }
  return numBytes;
}

// File Line: 74
// RVA: 0xA28300
__int64 __fastcall UFG::UIGfxMemoryFile::SkipBytes(UFG::UIGfxMemoryFile *this, unsigned int numBytes)
{
  int FileIndex; // r8d
  int FileSize; // r9d

  FileIndex = this->FileIndex;
  FileSize = this->FileSize;
  if ( (int)(FileIndex + numBytes) > FileSize )
    numBytes = FileSize - FileIndex;
  this->FileIndex = FileIndex + numBytes;
  return numBytes;
}

// File Line: 86
// RVA: 0xA24930
__int64 __fastcall UFG::UIGfxMemoryFile::BytesAvailable(UFG::UIGfxMemoryFile *this)
{
  return (unsigned int)(this->FileSize - this->FileIndex);
}

// File Line: 91
// RVA: 0xA281C0
__int64 __fastcall UFG::UIGfxMemoryFile::Seek(UFG::UIGfxMemoryFile *this, unsigned int offset, int origin)
{
  int v3; // r8d
  __int64 result; // rax

  if ( origin )
  {
    v3 = origin - 1;
    if ( v3 )
    {
      if ( v3 == 1 )
      {
        result = this->FileSize - offset;
        this->FileIndex = result;
        return result;
      }
    }
    else
    {
      this->FileIndex += offset;
    }
    return (unsigned int)this->FileIndex;
  }
  else
  {
    this->FileIndex = offset;
    return offset;
  }
}

// File Line: 108
// RVA: 0xA25DF0
char __fastcall UFG::UIGfxMemoryFile::ChangeSize(UFG::UIGfxMemoryFile *this, int newSize)
{
  this->FileSize = newSize;
  return 1;
}

// File Line: 115
// RVA: 0xA23150
void __fastcall UFG::UIGfxMemoryFile::UIGfxMemoryFile(
        UFG::UIGfxMemoryFile *this,
        const char *pFileName,
        const char *pBuffer,
        int buffSize)
{
  bool v8; // al

  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::File,2>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::File::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&UFG::UIGfxMemoryFile::`vftable;
  UFG::qString::qString(&this->FilePath);
  UFG::qString::Set(&this->FilePath, pFileName);
  this->FileData = pBuffer;
  this->FileSize = buffSize;
  this->FileIndex = 0;
  v8 = pFileName && pBuffer && buffSize > 0;
  this->Valid = v8;
}

