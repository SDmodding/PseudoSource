// File Line: 182
// RVA: 0x904AC0
__int64 __fastcall Scaleform::File::SeekToBegin(Scaleform::File *this)
{
  return ((__int64 (__fastcall *)(Scaleform::File *, _QWORD, _QWORD))this->vfptr[14].__vecDelDtor)(this, 0i64, 0i64);
}

// File Line: 288
// RVA: 0x9833D0
const char *__fastcall Scaleform::DelegatedFile::GetFilePath(Scaleform::DelegatedFile *this)
{
  return (const char *)((__int64 (*)(void))this->pFile.pObject->vfptr[1].__vecDelDtor)();
}

// File Line: 291
// RVA: 0x9983E0
bool __fastcall Scaleform::DelegatedFile::IsValid(Scaleform::SysFile *this)
{
  Scaleform::File *v1; // rcx

  v1 = this->pFile.pObject;
  return v1 && ((unsigned __int8 (*)(void))v1->vfptr[2].__vecDelDtor)();
}

// File Line: 296
// RVA: 0x998650
void __fastcall Scaleform::DelegatedFile::LTell(hkSubStreamWriter *this)
{
  ((void (*)(void))this->m_childStream->vfptr[2].__first_virtual_table_function__)();
}

// File Line: 298
// RVA: 0x7EB9D0
hkDataClassImpl *__fastcall StructArrayImplementation::Object::getClass(StructArrayImplementation::Object *this)
{
  return (hkDataClassImpl *)((__int64 (*)(void))this->m_impl->vfptr[6].__vecDelDtor)();
}

// File Line: 309
// RVA: 0x9B6620
__int64 __fastcall SSClassUnion::is_metaclass(SSClassUnion *this)
{
  return ((__int64 (*)(void))this->i_common_class_p->vfptr->is_metaclass)();
}

// File Line: 311
// RVA: 0x95B820
__int64 __fastcall Scaleform::DelegatedFile::BytesAvailable(Scaleform::DelegatedFile *this)
{
  return ((__int64 (*)(void))this->pFile.pObject->vfptr[12].__vecDelDtor)();
}

// File Line: 313
// RVA: 0x999380
__int64 __fastcall Scaleform::Render::TextureImage::Map(Scaleform::Render::TextureImage *this, Scaleform::Render::ImageData *pdata, __int64 mipLevel, __int64 levelCount)
{
  return ((__int64 (__fastcall *)(Scaleform::Render::Texture *volatile , Scaleform::Render::ImageData *, __int64, __int64))this->pTexture.Value->vfptr[13].__vecDelDtor)(
           this->pTexture.Value,
           pdata,
           mipLevel,
           levelCount);
}

// File Line: 316
// RVA: 0x9BB680
SSClassDescBase *__fastcall Scaleform::DelegatedFile::Seek(SSClassUnion *this)
{
  return (SSClassDescBase *)((__int64 (*)(void))this->i_common_class_p->vfptr->get_item_type)();
}

// File Line: 317
// RVA: 0x9985E0
SSClass *__fastcall SSClassUnion::get_key_class(SSClassUnion *this)
{
  return (SSClass *)((__int64 (*)(void))this->i_common_class_p->vfptr->get_key_class)();
}

// File Line: 422
// RVA: 0x8E80C0
__int64 __fastcall Scaleform::MemoryFile::LTell(Scaleform::MemoryFile *this)
{
  return this->FileIndex;
}

// File Line: 425
// RVA: 0x8E8090
__int64 __fastcall Scaleform::MemoryFile::LGetLength(Scaleform::MemoryFile *this)
{
  return this->FileSize;
}

// File Line: 428
// RVA: 0x8BD1A0
bool __fastcall Scaleform::MemoryFile::Close(Scaleform::MemoryFile *this)
{
  this->Valid = 0;
  return 0;
}

// File Line: 444
// RVA: 0x8F85E0
__int64 __fastcall Scaleform::MemoryFile::Read(Scaleform::MemoryFile *this, char *pbufer, int numBytes)
{
  Scaleform::MemoryFile *v3; // rdi
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

// File Line: 461
// RVA: 0x910B90
__int64 __fastcall Scaleform::MemoryFile::SkipBytes(Scaleform::MemoryFile *this, int numBytes)
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

// File Line: 473
// RVA: 0x8B8930
__int64 __fastcall Scaleform::MemoryFile::BytesAvailable(Scaleform::MemoryFile *this)
{
  return (unsigned int)(this->FileSize - this->FileIndex);
}

// File Line: 478
// RVA: 0x904A10
__int64 __fastcall Scaleform::MemoryFile::Seek(Scaleform::MemoryFile *this, int offset, int origin)
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

// File Line: 490
// RVA: 0x8E80A0
__int64 __fastcall UFG::UIGfxMemoryFile::LSeek(Scaleform::GFx::ZLibFile *this, __int64 offset, __int64 origin)
{
  return ((signed int (__fastcall *)(Scaleform::GFx::ZLibFile *, __int64, __int64))this->vfptr[14].__vecDelDtor)(
           this,
           offset,
           origin);
}

// File Line: 495
// RVA: 0x8BA510
char __fastcall Scaleform::MemoryFile::ChangeSize(Scaleform::MemoryFile *this, int newSize)
{
  this->FileSize = newSize;
  return 1;
}

// File Line: 514
// RVA: 0x89A760
void __fastcall Scaleform::MemoryFile::MemoryFile(Scaleform::MemoryFile *this, const char *pfileName, const char *pBuffer, int buffSize)
{
  int v4; // esi
  const char *v5; // rbp
  const char *v6; // rbx
  Scaleform::MemoryFile *v7; // rdi
  bool v8; // al

  v4 = buffSize;
  v5 = pBuffer;
  v6 = pfileName;
  v7 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::File,2>::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::File::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::MemoryFile::`vftable';
  Scaleform::String::String(&this->FilePath, pfileName);
  v7->FileData = v5;
  v7->FileSize = v4;
  v7->FileIndex = 0;
  v8 = v6 && v5 && v4 > 0;
  v7->Valid = v8;
}

