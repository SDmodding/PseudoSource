// File Line: 48
// RVA: 0x982EB0
__int64 __fastcall Scaleform::UnopenedFile::GetErrorCode(Scaleform::UnopenedFile *this)
{
  return 4097i64;
}

// File Line: 57
// RVA: 0x9985F0
unsigned __int64 __fastcall UFG::UIGfxFileOpener::GetFileModifyTime(CAkBusFXContext *this)
{
  return -1i64;
}

// File Line: 60
// RVA: 0x9C30B0
__int64 __fastcall hkpSingleShapeContainer::getNextKey(hkServerDebugDisplayHandler *this)
{
  return 0xFFFFFFFFi64;
}

// File Line: 74
// RVA: 0x945900
void __fastcall Scaleform::SysFile::SysFile(Scaleform::SysFile *this)
{
  __int64 v2; // rax
  Scaleform::File *v3; // rbx
  Scaleform::File *pObject; // rcx

  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::File,2>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::File::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::DelegatedFile::`vftable;
  this->pFile.pObject = 0i64;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::SysFile::`vftable;
  v2 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
         Scaleform::Memory::pGlobalHeap,
         16i64);
  v3 = (Scaleform::File *)v2;
  if ( v2 )
  {
    *(_QWORD *)v2 = &Scaleform::RefCountImplCore::`vftable;
    *(_DWORD *)(v2 + 8) = 1;
    *(_QWORD *)v2 = &Scaleform::RefCountImpl::`vftable;
    *(_QWORD *)v2 = &Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable;
    *(_QWORD *)v2 = &Scaleform::RefCountBase<Scaleform::File,2>::`vftable;
    *(_QWORD *)v2 = &Scaleform::File::`vftable;
    *(_QWORD *)v2 = &Scaleform::UnopenedFile::`vftable;
  }
  else
  {
    v3 = 0i64;
  }
  pObject = this->pFile.pObject;
  if ( pObject && !_InterlockedDecrement(&pObject->RefCount) )
    pObject->vfptr->__vecDelDtor(pObject, 1u);
  this->pFile.pObject = v3;
}

// File Line: 92
// RVA: 0x945880
void __fastcall Scaleform::SysFile::SysFile(Scaleform::SysFile *this, Scaleform::String *path, int flags, int mode)
{
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::File,2>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::File::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::DelegatedFile::`vftable;
  this->pFile.pObject = 0i64;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::SysFile::`vftable;
  Scaleform::SysFile::Open(this, path, flags, mode);
}

// File Line: 100
// RVA: 0x99CD60
char __fastcall Scaleform::SysFile::Open(Scaleform::SysFile *this, Scaleform::String *path, int flags, int mode)
{
  Scaleform::FILEFile *v8; // rax
  Scaleform::File *v9; // rbp
  Scaleform::File *v10; // rax
  Scaleform::File *v11; // rdi
  Scaleform::File *pObject; // rcx
  Scaleform::BufferedFile *v13; // rax
  Scaleform::File *v14; // rax
  Scaleform::File *v15; // rcx
  Scaleform::File *v17; // rdi
  Scaleform::File *v18; // rcx

  v8 = (Scaleform::FILEFile *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                Scaleform::Memory::pGlobalHeap,
                                56i64);
  v9 = 0i64;
  if ( v8 )
  {
    Scaleform::FILEFile::FILEFile(v8, path, flags, mode);
    v11 = v10;
  }
  else
  {
    v11 = 0i64;
  }
  pObject = this->pFile.pObject;
  if ( pObject && !_InterlockedDecrement(&pObject->RefCount) )
    pObject->vfptr->__vecDelDtor(pObject, 1u);
  this->pFile.pObject = v11;
  if ( v11 && ((unsigned __int8 (__fastcall *)(Scaleform::File *))v11->vfptr[2].__vecDelDtor)(v11) )
  {
    if ( (flags & 0x20) != 0 )
    {
      v13 = (Scaleform::BufferedFile *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                         Scaleform::Memory::pGlobalHeap,
                                         56i64);
      if ( v13 )
      {
        Scaleform::BufferedFile::BufferedFile(v13, this->pFile.pObject);
        v9 = v14;
      }
      v15 = this->pFile.pObject;
      if ( v15 )
      {
        if ( !_InterlockedDecrement(&v15->RefCount) )
          v15->vfptr->__vecDelDtor(v15, 1u);
      }
      this->pFile.pObject = v9;
    }
    return 1;
  }
  else
  {
    v17 = (Scaleform::File *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                               Scaleform::Memory::pGlobalHeap,
                               16i64);
    if ( v17 )
    {
      v17->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
      v17->RefCount = 1;
      v17->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
      v17->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable;
      v17->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::File,2>::`vftable;
      v17->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::File::`vftable;
      v17->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::UnopenedFile::`vftable;
    }
    else
    {
      v17 = 0i64;
    }
    v18 = this->pFile.pObject;
    if ( v18 && !_InterlockedDecrement(&v18->RefCount) )
      v18->vfptr->__vecDelDtor(v18, 1u);
    this->pFile.pObject = v17;
    return 0;
  }
}

// File Line: 131
// RVA: 0x982E90
__int64 __fastcall Scaleform::SysFile::GetErrorCode(Scaleform::SysFile *this)
{
  Scaleform::File *pObject; // rcx

  pObject = this->pFile.pObject;
  if ( pObject )
    return ((__int64 (__fastcall *)(Scaleform::File *))pObject->vfptr[8].__vecDelDtor)(pObject);
  else
    return 4097i64;
}

// File Line: 142
// RVA: 0x961310
char __fastcall Scaleform::SysFile::Close(Scaleform::SysFile *this)
{
  Scaleform::File *v2; // rbx
  Scaleform::File *pObject; // rcx

  if ( !((unsigned __int8 (__fastcall *)(Scaleform::SysFile *))this->vfptr[2].__vecDelDtor)(this) )
    return 0;
  ((void (__fastcall *)(Scaleform::File *))this->pFile.pObject->Scaleform::DelegatedFile::vfptr[19].__vecDelDtor)(this->pFile.pObject);
  v2 = (Scaleform::File *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                            Scaleform::Memory::pGlobalHeap,
                            16i64);
  if ( v2 )
  {
    v2->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
    v2->RefCount = 1;
    v2->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
    v2->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable;
    v2->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::File,2>::`vftable;
    v2->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::File::`vftable;
    v2->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::UnopenedFile::`vftable;
  }
  else
  {
    v2 = 0i64;
  }
  pObject = this->pFile.pObject;
  if ( pObject )
  {
    if ( !_InterlockedDecrement(&pObject->RefCount) )
      pObject->vfptr->__vecDelDtor(pObject, 1u);
  }
  this->pFile.pObject = v2;
  return 1;
}

