// File Line: 48
// RVA: 0x982EB0
signed __int64 __fastcall Scaleform::UnopenedFile::GetErrorCode(Scaleform::UnopenedFile *this)
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
signed __int64 __fastcall hkpSingleShapeContainer::getNextKey(hkServerDebugDisplayHandler *this)
{
  return 0xFFFFFFFFi64;
}

// File Line: 74
// RVA: 0x945900
void __fastcall Scaleform::SysFile::SysFile(Scaleform::SysFile *this)
{
  Scaleform::SysFile *v1; // rdi
  __int64 v2; // rax
  Scaleform::File *v3; // rbx
  Scaleform::File *v4; // rcx

  v1 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::File,2>::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::File::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::DelegatedFile::`vftable';
  this->pFile.pObject = 0i64;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::SysFile::`vftable';
  v2 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
         Scaleform::Memory::pGlobalHeap,
         16i64);
  v3 = (Scaleform::File *)v2;
  if ( v2 )
  {
    *(_QWORD *)v2 = &Scaleform::RefCountImplCore::`vftable';
    *(_DWORD *)(v2 + 8) = 1;
    *(_QWORD *)v2 = &Scaleform::RefCountImpl::`vftable';
    *(_QWORD *)v2 = &Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable';
    *(_QWORD *)v2 = &Scaleform::RefCountBase<Scaleform::File,2>::`vftable';
    *(_QWORD *)v2 = &Scaleform::File::`vftable';
    *(_QWORD *)v2 = &Scaleform::UnopenedFile::`vftable';
  }
  else
  {
    v3 = 0i64;
  }
  v4 = v1->pFile.pObject;
  if ( v4 && !_InterlockedDecrement(&v4->RefCount) && v4 )
    v4->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v4->vfptr, 1u);
  v1->pFile.pObject = v3;
}

// File Line: 92
// RVA: 0x945880
void __fastcall Scaleform::SysFile::SysFile(Scaleform::SysFile *this, Scaleform::String *path, int flags, int mode)
{
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::File,2>::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::File::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::DelegatedFile::`vftable';
  this->pFile.pObject = 0i64;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::SysFile::`vftable';
  Scaleform::SysFile::Open(this, path, flags, mode);
}

// File Line: 100
// RVA: 0x99CD60
char __fastcall Scaleform::SysFile::Open(Scaleform::SysFile *this, Scaleform::String *path, int flags, int mode)
{
  int v4; // ebx
  int v5; // er14
  Scaleform::String *v6; // rdi
  Scaleform::SysFile *v7; // rsi
  Scaleform::FILEFile *v8; // rax
  Scaleform::File *v9; // rbp
  Scaleform::File *v10; // rax
  Scaleform::File *v11; // rdi
  Scaleform::File *v12; // rcx
  Scaleform::BufferedFile *v13; // rax
  Scaleform::File *v14; // rax
  Scaleform::File *v15; // rcx
  char result; // al
  __int64 v17; // rdi
  Scaleform::File *v18; // rcx

  v4 = mode;
  v5 = flags;
  v6 = path;
  v7 = this;
  v8 = (Scaleform::FILEFile *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                Scaleform::Memory::pGlobalHeap,
                                56i64);
  v9 = 0i64;
  if ( v8 )
  {
    Scaleform::FILEFile::FILEFile(v8, v6, v5, v4);
    v11 = v10;
  }
  else
  {
    v11 = 0i64;
  }
  v12 = v7->pFile.pObject;
  if ( v12 && !_InterlockedDecrement(&v12->RefCount) && v12 )
    v12->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v12->vfptr, 1u);
  v7->pFile.pObject = v11;
  if ( v11 && ((unsigned __int8 (__fastcall *)(Scaleform::File *))v11->vfptr[2].__vecDelDtor)(v11) )
  {
    if ( v5 & 0x20 )
    {
      v13 = (Scaleform::BufferedFile *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                         Scaleform::Memory::pGlobalHeap,
                                         56i64);
      if ( v13 )
      {
        Scaleform::BufferedFile::BufferedFile(v13, v7->pFile.pObject);
        v9 = v14;
      }
      v15 = v7->pFile.pObject;
      if ( v15 && !_InterlockedDecrement(&v15->RefCount) )
      {
        if ( v15 )
          v15->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v15->vfptr, 1u);
      }
      v7->pFile.pObject = v9;
    }
    result = 1;
  }
  else
  {
    v17 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
            Scaleform::Memory::pGlobalHeap,
            16i64);
    if ( v17 )
    {
      *(_QWORD *)v17 = &Scaleform::RefCountImplCore::`vftable';
      *(_DWORD *)(v17 + 8) = 1;
      *(_QWORD *)v17 = &Scaleform::RefCountImpl::`vftable';
      *(_QWORD *)v17 = &Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable';
      *(_QWORD *)v17 = &Scaleform::RefCountBase<Scaleform::File,2>::`vftable';
      *(_QWORD *)v17 = &Scaleform::File::`vftable';
      *(_QWORD *)v17 = &Scaleform::UnopenedFile::`vftable';
    }
    else
    {
      v17 = 0i64;
    }
    v18 = v7->pFile.pObject;
    if ( v18 && !_InterlockedDecrement(&v18->RefCount) && v18 )
      v18->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v18->vfptr, 1u);
    v7->pFile.pObject = (Scaleform::File *)v17;
    result = 0;
  }
  return result;
}

// File Line: 131
// RVA: 0x982E90
__int64 __fastcall Scaleform::SysFile::GetErrorCode(Scaleform::SysFile *this)
{
  Scaleform::File *v1; // rcx
  __int64 result; // rax

  v1 = this->pFile.pObject;
  if ( v1 )
    result = ((__int64 (*)(void))v1->vfptr[8].__vecDelDtor)();
  else
    result = 4097i64;
  return result;
}

// File Line: 142
// RVA: 0x961310
char __fastcall Scaleform::SysFile::Close(Scaleform::SysFile *this)
{
  Scaleform::SysFile *v1; // rdi
  __int64 v2; // rbx
  Scaleform::File *v3; // rcx

  v1 = this;
  if ( !((unsigned __int8 (__cdecl *)(Scaleform::SysFile *))this->vfptr[2].__vecDelDtor)(this) )
    return 0;
  ((void (*)(void))v1->pFile.pObject->vfptr[19].__vecDelDtor)();
  v2 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
         Scaleform::Memory::pGlobalHeap,
         16i64);
  if ( v2 )
  {
    *(_QWORD *)v2 = &Scaleform::RefCountImplCore::`vftable';
    *(_DWORD *)(v2 + 8) = 1;
    *(_QWORD *)v2 = &Scaleform::RefCountImpl::`vftable';
    *(_QWORD *)v2 = &Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable';
    *(_QWORD *)v2 = &Scaleform::RefCountBase<Scaleform::File,2>::`vftable';
    *(_QWORD *)v2 = &Scaleform::File::`vftable';
    *(_QWORD *)v2 = &Scaleform::UnopenedFile::`vftable';
  }
  else
  {
    v2 = 0i64;
  }
  v3 = v1->pFile.pObject;
  if ( v3 && !_InterlockedDecrement(&v3->RefCount) )
  {
    if ( v3 )
      v3->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v3->vfptr, 1u);
  }
  v1->pFile.pObject = (Scaleform::File *)v2;
  return 1;
}

