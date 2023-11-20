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
__int64 __fastcall UFG::UIGfxMemoryFile::Read(UFG::UIGfxMemoryFile *this, char *pbufer, int numBytes)
{
  UFG::UIGfxMemoryFile *v3; // rdi
  __int64 v4; // rcx
  int v5; // ebx
  int v6; // er8

  v3 = this;
  v4 = this->FileIndex;
  v5 = numBytes;
  v6 = v3->FileSize;
  if ( (signed int)v4 + v5 > v6 )
    v5 = v6 - v4;
  if ( v5 > 0 )
  {
    memmove(pbufer, &v3->FileData[v4], v5);
    v3->FileIndex += v5;
  }
  return (unsigned int)v5;
}

// File Line: 74
// RVA: 0xA28300
__int64 __fastcall UFG::UIGfxMemoryFile::SkipBytes(UFG::UIGfxMemoryFile *this, int numBytes)
{
  int v2; // er8
  int v3; // er9

  v2 = this->FileIndex;
  v3 = this->FileSize;
  if ( v2 + numBytes > v3 )
    numBytes = v3 - v2;
  this->FileIndex = v2 + numBytes;
  return (unsigned int)numBytes;
}

// File Line: 86
// RVA: 0xA24930
__int64 __fastcall UFG::UIGfxMemoryFile::BytesAvailable(UFG::UIGfxMemoryFile *this)
{
  return (unsigned int)(this->FileSize - this->FileIndex);
}

// File Line: 91
// RVA: 0xA281C0
__int64 __fastcall UFG::UIGfxMemoryFile::Seek(UFG::UIGfxMemoryFile *this, int offset, int origin)
{
  int v3; // er8
  __int64 result; // rax

  if ( origin )
  {
    v3 = origin - 1;
    if ( v3 )
    {
      if ( v3 == 1 )
      {
        result = (unsigned int)(this->FileSize - offset);
        this->FileIndex = result;
        return result;
      }
    }
    else
    {
      this->FileIndex += offset;
    }
    result = (unsigned int)this->FileIndex;
  }
  else
  {
    this->FileIndex = offset;
    result = (unsigned int)offset;
  }
  return result;
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
void __fastcall UFG::UIGfxMemoryFile::UIGfxMemoryFile(UFG::UIGfxMemoryFile *this, const char *pFileName, const char *pBuffer, int buffSize)
{
  int v4; // ebp
  const char *v5; // r14
  const char *v6; // rdi
  UFG::UIGfxMemoryFile *v7; // rsi
  bool v8; // al

  v4 = buffSize;
  v5 = pBuffer;
  v6 = pFileName;
  v7 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::File,2>::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::File::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&UFG::UIGfxMemoryFile::`vftable';
  UFG::qString::qString(&this->FilePath);
  UFG::qString::Set(&v7->FilePath, v6);
  v7->FileData = v5;
  v7->FileSize = v4;
  v7->FileIndex = 0;
  v8 = v6 && v5 && v4 > 0;
  v7->Valid = v8;
}

