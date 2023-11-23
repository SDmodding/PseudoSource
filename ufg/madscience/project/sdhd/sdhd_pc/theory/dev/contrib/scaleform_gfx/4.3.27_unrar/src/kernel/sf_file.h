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
  return (const char *)((__int64 (__fastcall *)(Scaleform::File *))this->pFile.pObject->vfptr[1].__vecDelDtor)(this->pFile.pObject);
}

// File Line: 291
// RVA: 0x9983E0
bool __fastcall Scaleform::DelegatedFile::IsValid(Scaleform::SysFile *this)
{
  Scaleform::File *pObject; // rcx

  pObject = this->pFile.pObject;
  return pObject && ((unsigned __int8 (__fastcall *)(Scaleform::File *))pObject->vfptr[2].__vecDelDtor)(pObject);
}

// File Line: 296
// RVA: 0x998650
void __fastcall Scaleform::DelegatedFile::LTell(hkSubStreamWriter *this)
{
  this->m_childStream->vfptr[2].__first_virtual_table_function__(this->m_childStream);
}

// File Line: 298
// RVA: 0x7EB9D0
hkDataClassImpl *__fastcall StructArrayImplementation::Object::getClass(StructArrayImplementation::Object *this)
{
  return (hkDataClassImpl *)((__int64 (__fastcall *)(StructArrayImplementation *))this->m_impl->vfptr[6].__vecDelDtor)(this->m_impl);
}

// File Line: 309
// RVA: 0x9B6620
__int64 __fastcall SSClassUnion::is_metaclass(SSClassUnion *this)
{
  return ((__int64 (__fastcall *)(SSClassUnaryBase *))this->i_common_class_p->vfptr->is_metaclass)(this->i_common_class_p);
}

// File Line: 311
// RVA: 0x95B820
__int64 __fastcall Scaleform::DelegatedFile::BytesAvailable(Scaleform::DelegatedFile *this)
{
  return ((__int64 (__fastcall *)(Scaleform::File *))this->pFile.pObject->vfptr[12].__vecDelDtor)(this->pFile.pObject);
}

// File Line: 313
// RVA: 0x999380
__int64 __fastcall Scaleform::Render::TextureImage::Map(
        Scaleform::Render::TextureImage *this,
        Scaleform::Render::ImageData *pdata,
        __int64 mipLevel,
        __int64 levelCount)
{
  return ((__int64 (__fastcall *)(Scaleform::Render::Texture *volatile, Scaleform::Render::ImageData *, __int64, __int64))this->pTexture.Value->Scaleform::Render::Image::vfptr[13].__vecDelDtor)(
           this->pTexture.Value,
           pdata,
           mipLevel,
           levelCount);
}

// File Line: 316
// RVA: 0x9BB680
SSClassDescBase *__fastcall Scaleform::DelegatedFile::Seek(SSClassUnion *this)
{
  return this->i_common_class_p->vfptr->get_item_type(this->i_common_class_p);
}

// File Line: 317
// RVA: 0x9985E0
SSClass *__fastcall SSClassUnion::get_key_class(SSClassUnion *this)
{
  return this->i_common_class_p->vfptr->get_key_class(this->i_common_class_p);
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
__int64 __fastcall Scaleform::MemoryFile::Read(Scaleform::MemoryFile *this, char *pbufer, unsigned int numBytes)
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

// File Line: 461
// RVA: 0x910B90
__int64 __fastcall Scaleform::MemoryFile::SkipBytes(Scaleform::MemoryFile *this, unsigned int numBytes)
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

// File Line: 473
// RVA: 0x8B8930
__int64 __fastcall Scaleform::MemoryFile::BytesAvailable(Scaleform::MemoryFile *this)
{
  return (unsigned int)(this->FileSize - this->FileIndex);
}

// File Line: 478
// RVA: 0x904A10
__int64 __fastcall Scaleform::MemoryFile::Seek(Scaleform::MemoryFile *this, unsigned int offset, int origin)
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

// File Line: 490
// RVA: 0x8E80A0
__int64 __fastcall UFG::UIGfxMemoryFile::LSeek(Scaleform::GFx::ZLibFile *this, __int64 offset, __int64 origin)
{
  return ((int (__fastcall *)(Scaleform::GFx::ZLibFile *, __int64, __int64))this->vfptr[14].__vecDelDtor)(
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
void __fastcall Scaleform::MemoryFile::MemoryFile(
        Scaleform::MemoryFile *this,
        const char *pfileName,
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
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::MemoryFile::`vftable;
  Scaleform::String::String(&this->FilePath, pfileName);
  this->FileData = pBuffer;
  this->FileSize = buffSize;
  this->FileIndex = 0;
  v8 = pfileName && pBuffer && buffSize > 0;
  this->Valid = v8;
}

