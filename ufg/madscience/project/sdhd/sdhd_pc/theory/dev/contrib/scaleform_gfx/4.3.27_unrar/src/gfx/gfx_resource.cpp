// File Line: 30
// RVA: 0x8B1E80
void __fastcall Scaleform::Render::RenderBuffer::AddRef(Scaleform::GFx::Resource *this)
{
  _InterlockedExchangeAdd(&this->RefCount.Value, 1u);
}

// File Line: 37
// RVA: 0x8FE6A0
void __fastcall Scaleform::GFx::Resource::Release(Scaleform::GFx::Resource *this)
{
  Scaleform::GFx::Resource *v1; // rbx
  Scaleform::GFx::ResourceLibBase *v2; // rcx

  v1 = this;
  if ( !_InterlockedDecrement(&this->RefCount.Value) )
  {
    v2 = this->pLib;
    if ( v2 )
    {
      v2->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v2->vfptr, (unsigned int)v1);
      v1->pLib = 0i64;
    }
    v1->vfptr->__vecDelDtor(v1, 1u);
  }
}

// File Line: 77
// RVA: 0x89C5E0
void __fastcall Scaleform::GFx::ResourceLib::ResourceLib(Scaleform::GFx::ResourceLib *this, bool debug)
{
  Scaleform::GFx::ResourceLib *v2; // rbx
  Scaleform::GFx::ResourceWeakLib *v3; // rdi
  Scaleform::GFx::ResourceWeakLib *v4; // rax
  Scaleform::GFx::ResourceWeakLib *v5; // rax

  v2 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::GFx::ResourceLib,2>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::ResourceLib::`vftable;
  v3 = 0i64;
  this->PinSet.pTable = 0i64;
  this->DebugFlag = debug;
  v4 = (Scaleform::GFx::ResourceWeakLib *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(
                                            Scaleform::Memory::pGlobalHeap,
                                            80ui64,
                                            0i64);
  if ( v4 )
  {
    Scaleform::GFx::ResourceWeakLib::ResourceWeakLib(v4, v2);
    v3 = v5;
  }
  v2->pWeakLib = v3;
}

// File Line: 92
// RVA: 0x89C690
void __fastcall Scaleform::GFx::ResourceLib::ResourceSlot::ResourceSlot(Scaleform::GFx::ResourceLib::ResourceSlot *this, Scaleform::GFx::ResourceWeakLib *plib, Scaleform::GFx::ResourceKey *key)
{
  Scaleform::GFx::ResourceKey *v3; // rdi
  Scaleform::GFx::ResourceWeakLib *v4; // rsi
  Scaleform::GFx::ResourceLib::ResourceSlot *v5; // rbx
  Scaleform::Render::RenderBuffer *v6; // rcx
  Scaleform::GFx::ResourceKey::KeyInterface *v7; // rcx

  v3 = key;
  v4 = plib;
  v5 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::GFx::ResourceLib::ResourceSlot,2>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::ResourceLib::ResourceSlot::`vftable;
  this->pLib.pObject = 0i64;
  this->Key.pKeyInterface = 0i64;
  this->Key.hKeyData = 0i64;
  Scaleform::String::String(&this->ErrorMessage);
  Scaleform::Event::Event(&v5->ResolveComplete, 0, 0);
  if ( v4 )
    Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)v4);
  v6 = (Scaleform::Render::RenderBuffer *)v5->pLib.pObject;
  if ( v6 )
    Scaleform::RefCountImpl::Release(v6);
  v5->pLib.pObject = v4;
  v5->State = 0;
  v5->pResource = 0i64;
  if ( v3->pKeyInterface )
    v3->pKeyInterface->vfptr->AddRef(v3->pKeyInterface, v3->hKeyData);
  v7 = v5->Key.pKeyInterface;
  if ( v7 )
    v7->vfptr->Release(v7, v5->Key.hKeyData);
  v5->Key.pKeyInterface = v3->pKeyInterface;
  v5->Key.hKeyData = v3->hKeyData;
}

// File Line: 101
// RVA: 0x8A7410
void __fastcall Scaleform::GFx::ResourceLib::ResourceSlot::~ResourceSlot(Scaleform::GFx::ResourceLib::ResourceSlot *this)
{
  Scaleform::GFx::ResourceLib::ResourceSlot *v1; // rdi
  Scaleform::GFx::Resource *volatile v2; // rsi
  Scaleform::GFx::ResourceLibBase *v3; // rcx
  Scaleform::GFx::ResourceKey::KeyInterface *v4; // rcx
  Scaleform::Render::RenderBuffer *v5; // rcx
  _RTL_CRITICAL_SECTION *lpCriticalSection; // [rsp+48h] [rbp+10h]

  v1 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::ResourceLib::ResourceSlot::`vftable;
  lpCriticalSection = &this->pLib.pObject->ResourceLock.cs;
  EnterCriticalSection(lpCriticalSection);
  if ( v1->State )
  {
    if ( v1->pResource )
    {
      v2 = v1->pResource;
      if ( !_InterlockedDecrement(&v2->RefCount.Value) )
      {
        v3 = v2->pLib;
        if ( v3 )
        {
          v3->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v3->vfptr, (unsigned int)v2);
          v2->pLib = 0i64;
        }
        v2->vfptr->__vecDelDtor(v2, 1u);
      }
    }
  }
  else
  {
    Scaleform::HashSetBase<Scaleform::GFx::ResourceWeakLib::ResourceNode,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp,Scaleform::AllocatorGH<Scaleform::GFx::ResourceWeakLib::ResourceNode,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::ResourceWeakLib::ResourceNode,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp>>::RemoveAlt<Scaleform::GFx::ResourceKey>(
      (Scaleform::HashSetBase<Scaleform::GFx::ResourceWeakLib::ResourceNode,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp,Scaleform::AllocatorGH<Scaleform::GFx::ResourceWeakLib::ResourceNode,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::ResourceWeakLib::ResourceNode,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp> > *)&v1->pLib.pObject->Resources.pTable,
      &v1->Key);
  }
  LeaveCriticalSection(lpCriticalSection);
  Scaleform::Event::~Event(&v1->ResolveComplete);
  if ( !_InterlockedDecrement((volatile signed __int32 *)((v1->ErrorMessage.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  v4 = v1->Key.pKeyInterface;
  if ( v4 )
    v4->vfptr->Release(v4, v1->Key.hKeyData);
  v5 = (Scaleform::Render::RenderBuffer *)v1->pLib.pObject;
  if ( v5 )
    Scaleform::RefCountImpl::Release(v5);
  Scaleform::RefCountImplCore::~RefCountImplCore((Scaleform::RefCountImplCore *)&v1->vfptr);
}

// File Line: 155
// RVA: 0x903910
void __fastcall Scaleform::GFx::ResourceLib::ResourceSlot::Resolve(Scaleform::GFx::ResourceLib::ResourceSlot *this, Scaleform::GFx::Resource *pres)
{
  Scaleform::GFx::Resource *v2; // rdi
  Scaleform::GFx::ResourceLib::ResourceSlot *v3; // rbx
  Scaleform::HashSetBase<Scaleform::GFx::ResourceWeakLib::ResourceNode,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp,Scaleform::AllocatorGH<Scaleform::GFx::ResourceWeakLib::ResourceNode,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::ResourceWeakLib::ResourceNode,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp> > *v4; // r14
  __int64 v5; // rcx
  signed __int64 v6; // rax
  signed __int64 v7; // rax
  _RTL_CRITICAL_SECTION *v8; // [rsp+40h] [rbp+8h]

  v2 = pres;
  v3 = this;
  v8 = &this->pLib.pObject->ResourceLock.cs;
  EnterCriticalSection(v8);
  _InterlockedExchangeAdd(&v2->RefCount.Value, 1u);
  v3->pResource = v2;
  v3->State = 1;
  v4 = (Scaleform::HashSetBase<Scaleform::GFx::ResourceWeakLib::ResourceNode,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp,Scaleform::AllocatorGH<Scaleform::GFx::ResourceWeakLib::ResourceNode,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::ResourceWeakLib::ResourceNode,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp> > *)v3->pLib.pObject;
  if ( !v4[8].pTable )
    goto LABEL_10;
  v5 = (__int64)v3->Key.pKeyInterface;
  if ( v5 )
    v5 = (*(__int64 (__fastcall **)(__int64, void *))(*(_QWORD *)v5 + 32i64))(v5, v3->Key.hKeyData);
  v6 = Scaleform::HashSetBase<Scaleform::GFx::ResourceWeakLib::ResourceNode,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp,Scaleform::AllocatorGH<Scaleform::GFx::ResourceWeakLib::ResourceNode,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::ResourceWeakLib::ResourceNode,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp>>::findIndexCore<Scaleform::GFx::ResourceKey>(
         v4 + 8,
         &v3->Key,
         v5 & v4[8].pTable->SizeMask);
  if ( v6 >= 0 )
    v7 = (signed __int64)&v4[8].pTable[2 * (v6 + 1)];
  else
LABEL_10:
    v7 = 0i64;
  *(_QWORD *)(v7 + 8) = v2;
  *(_DWORD *)v7 = 0;
  v2->pLib = (Scaleform::GFx::ResourceLibBase *)&v3->pLib.pObject->vfptr;
  Scaleform::Event::SetEvent(&v3->ResolveComplete);
  LeaveCriticalSection(v8);
}

// File Line: 185
// RVA: 0x8B9820
void __fastcall Scaleform::GFx::ResourceLib::ResourceSlot::CancelResolve(Scaleform::GFx::ResourceLib::ResourceSlot *this, const char *perrorMessage)
{
  const char *v2; // rdi
  Scaleform::GFx::ResourceLib::ResourceSlot *v3; // rsi
  _RTL_CRITICAL_SECTION *v4; // rbx

  v2 = perrorMessage;
  v3 = this;
  v4 = &this->pLib.pObject->ResourceLock.cs;
  EnterCriticalSection(v4);
  v3->State = 2;
  Scaleform::String::operator=(&v3->ErrorMessage, v2);
  Scaleform::HashSetBase<Scaleform::GFx::ResourceWeakLib::ResourceNode,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp,Scaleform::AllocatorGH<Scaleform::GFx::ResourceWeakLib::ResourceNode,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::ResourceWeakLib::ResourceNode,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp>>::RemoveAlt<Scaleform::GFx::ResourceKey>(
    (Scaleform::HashSetBase<Scaleform::GFx::ResourceWeakLib::ResourceNode,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp,Scaleform::AllocatorGH<Scaleform::GFx::ResourceWeakLib::ResourceNode,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::ResourceWeakLib::ResourceNode,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp> > *)&v3->pLib.pObject->Resources.pTable,
    &v3->Key);
  Scaleform::Event::SetEvent(&v3->ResolveComplete);
  LeaveCriticalSection(v4);
}

// File Line: 207
// RVA: 0x91A240
Scaleform::GFx::Resource *__fastcall Scaleform::GFx::ResourceLib::BindHandle::WaitForResolve(Scaleform::GFx::ResourceLib::BindHandle *this)
{
  Scaleform::GFx::ResourceLib::BindHandle *v1; // rbx
  Scaleform::GFx::Resource *result; // rax
  Scaleform::GFx::Resource *v3; // rsi
  Scaleform::GFx::Resource *v4; // rdi

  v1 = this;
  if ( this->State == 1 )
  {
    _InterlockedExchangeAdd(&this->pResource->RefCount.Value, 1u);
    result = this->pResource;
  }
  else if ( this->State == 4 )
  {
    result = 0i64;
  }
  else
  {
    v3 = this->pResource;
    Scaleform::Event::Wait((Scaleform::Event *)&v3[2].pLib, 0xFFFFFFFF);
    if ( *(_QWORD *)&v3[1].RefCount.Value )
      _InterlockedExchangeAdd((volatile signed __int32 *)(*(_QWORD *)&v3[1].RefCount.Value + 8i64), 1u);
    v4 = *(Scaleform::GFx::Resource **)&v3[1].RefCount.Value;
    if ( v4 )
    {
      v1->State = 1;
      v1->pResource = v4;
      _InterlockedExchangeAdd(&v4->RefCount.Value, 1u);
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v3);
      result = v4;
    }
    else
    {
      v1->State = 4;
      result = 0i64;
    }
  }
  return result;
}

// File Line: 254
// RVA: 0x89C790
void __fastcall Scaleform::GFx::ResourceWeakLib::ResourceWeakLib(Scaleform::GFx::ResourceWeakLib *this, Scaleform::GFx::ResourceLib *pstrongLib)
{
  Scaleform::GFx::ResourceLib *v2; // rdi
  Scaleform::GFx::ResourceWeakLib *v3; // rbx
  signed int v4; // eax
  __int64 v5; // rdi
  Scaleform::MemoryHeap *v6; // rcx
  int v7; // [rsp+30h] [rbp-48h]
  __int64 v8; // [rsp+38h] [rbp-40h]
  __int64 v9; // [rsp+40h] [rbp-38h]
  __int64 v10; // [rsp+48h] [rbp-30h]
  __int64 v11; // [rsp+50h] [rbp-28h]
  __int64 v12; // [rsp+58h] [rbp-20h]
  __int64 v13; // [rsp+60h] [rbp-18h]
  __int64 v14; // [rsp+68h] [rbp-10h]

  v2 = pstrongLib;
  v3 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::GFx::ResourceLibBase,2>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::ResourceLibBase::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::ResourceWeakLib::`vftable;
  Scaleform::Lock::Lock(&this->ResourceLock, 0);
  v3->Resources.pTable = 0i64;
  v3->pImageHeap.pObject = 0i64;
  v3->pStrongLib = v2;
  if ( !v2 || (v4 = 4096, !v2->DebugFlag) )
    v4 = 0;
  v14 = 0i64;
  v7 = v4 | 4;
  v8 = 64i64;
  v9 = 4096i64;
  v10 = 0i64;
  v11 = -1i64;
  v12 = 0i64;
  v13 = 5i64;
  v5 = (*(__int64 (__fastcall **)(Scaleform::MemoryHeap *, const char *, int *))&Scaleform::Memory::pGlobalHeap->vfptr->gap8[24])(
         Scaleform::Memory::pGlobalHeap,
         "_ResourceLib_Images",
         &v7);
  v6 = v3->pImageHeap.pObject;
  if ( v6 )
    ((void (__cdecl *)(Scaleform::MemoryHeap *))v6->vfptr->Release)(v6);
  v3->pImageHeap.pObject = (Scaleform::MemoryHeap *)v5;
}

// File Line: 275
// RVA: 0x8A7510
void __fastcall Scaleform::GFx::ResourceWeakLib::~ResourceWeakLib(Scaleform::GFx::ResourceWeakLib *this)
{
  Scaleform::GFx::ResourceWeakLib *v1; // r14
  _RTL_CRITICAL_SECTION *v2; // rbx
  signed __int64 v3; // rdi
  Scaleform::HashSetBase<Scaleform::GFx::ResourceWeakLib::ResourceNode,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp,Scaleform::AllocatorGH<Scaleform::GFx::ResourceWeakLib::ResourceNode,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::ResourceWeakLib::ResourceNode,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp> >::TableType *v4; // rdx
  unsigned __int64 v5; // rax
  Scaleform::HashSetBase<Scaleform::GFx::ResourceWeakLib::ResourceNode,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp,Scaleform::AllocatorGH<Scaleform::GFx::ResourceWeakLib::ResourceNode,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::ResourceWeakLib::ResourceNode,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp> >::TableType *v6; // rcx
  __int64 v7; // rcx
  __int64 v8; // r9
  __int64 v9; // rdx
  unsigned __int64 v10; // r8
  _QWORD *v11; // rdx
  Scaleform::MemoryHeap *v12; // rcx
  __int64 v13; // rcx
  signed __int64 v14; // rdx
  __m128i v15; // [rsp+30h] [rbp-28h]

  v1 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::ResourceWeakLib::`vftable;
  v2 = &this->ResourceLock.cs;
  EnterCriticalSection(&this->ResourceLock.cs);
  v3 = (signed __int64)&v1->Resources;
  v4 = v1->Resources.pTable;
  if ( v4 )
  {
    v5 = 0i64;
    v6 = v4 + 1;
    do
    {
      if ( v6->EntryCount != -2i64 )
        break;
      ++v5;
      v6 += 2;
    }
    while ( v5 <= v4->SizeMask );
    v15.m128i_i64[0] = (__int64)&v1->Resources;
    v15.m128i_i64[1] = v5;
  }
  else
  {
    v15 = 0ui64;
  }
  _mm_store_si128(&v15, v15);
  v7 = v15.m128i_i64[1];
  v8 = v15.m128i_i64[0];
  while ( v8 )
  {
    v9 = *(_QWORD *)v8;
    if ( !*(_QWORD *)v8 || v7 > *(_QWORD *)(v9 + 8) )
      break;
    *(_QWORD *)(*(_QWORD *)(32 * v7 + v9 + 40) + 16i64) = 0i64;
    v10 = *(_QWORD *)(*(_QWORD *)v8 + 8i64);
    if ( v7 <= (signed __int64)v10 && ++v7 <= v10 )
    {
      v11 = (_QWORD *)(32 * v7 + *(_QWORD *)v8 + 16i64);
      do
      {
        if ( *v11 != -2i64 )
          break;
        ++v7;
        v11 += 4;
      }
      while ( v7 <= v10 );
    }
  }
  LeaveCriticalSection(v2);
  v12 = v1->pImageHeap.pObject;
  if ( v12 )
    ((void (__cdecl *)(Scaleform::MemoryHeap *))v12->vfptr->Release)(v12);
  if ( *(_QWORD *)v3 )
  {
    v13 = 0i64;
    v14 = *(_QWORD *)(*(_QWORD *)v3 + 8i64) + 1i64;
    do
    {
      if ( *(_QWORD *)(*(_QWORD *)v3 + v13 + 16) != -2i64 )
        *(_QWORD *)(*(_QWORD *)v3 + v13 + 16) = -2i64;
      v13 += 32i64;
      --v14;
    }
    while ( v14 );
    if ( *(_QWORD *)v3 )
      ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
    *(_QWORD *)v3 = 0i64;
  }
  Scaleform::Lock::~Lock(v2);
  Scaleform::RefCountImplCore::~RefCountImplCore((Scaleform::RefCountImplCore *)&v1->vfptr);
}

// File Line: 313
// RVA: 0x8B7FB0
__int64 __fastcall Scaleform::GFx::ResourceWeakLib::BindResourceKey(Scaleform::GFx::ResourceWeakLib *this, Scaleform::GFx::ResourceLib::BindHandle *phandle, Scaleform::GFx::ResourceKey *k)
{
  Scaleform::GFx::ResourceKey *v3; // rdi
  Scaleform::GFx::ResourceLib::BindHandle *v4; // rsi
  Scaleform::GFx::ResourceWeakLib *v5; // r15
  Scaleform::Lock *v6; // rbx
  Scaleform::GFx::ResourceLib::ResourceSlot *v7; // rbp
  __int64 v8; // rcx
  signed __int64 v9; // rax
  signed __int64 v10; // r8
  __int64 v11; // rdx
  signed __int32 v12; // eax
  unsigned int v13; // edi
  Scaleform::GFx::Resource *v14; // rcx
  Scaleform::GFx::ResourceLib::ResourceSlot *v15; // rax
  Scaleform::GFx::ResourceLib::ResourceSlot *v16; // rax
  __int64 v17; // rax
  Scaleform::GFx::ResourceWeakLib::ResourceNode node; // [rsp+28h] [rbp-40h]
  Scaleform::GFx::ResourceLib::ResourceSlot *v20; // [rsp+70h] [rbp+8h]
  Scaleform::Lock *v21; // [rsp+88h] [rbp+20h]

  v3 = k;
  v4 = phandle;
  v5 = this;
  v6 = &this->ResourceLock;
  v21 = &this->ResourceLock;
  EnterCriticalSection(&this->ResourceLock.cs);
  v7 = 0i64;
  if ( v5->Resources.pTable )
  {
    v8 = v3->pKeyInterface ? (__int64)v3->pKeyInterface->vfptr->GetHashCode(v3->pKeyInterface, v3->hKeyData) : 0i64;
    v9 = Scaleform::HashSetBase<Scaleform::GFx::ResourceWeakLib::ResourceNode,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp,Scaleform::AllocatorGH<Scaleform::GFx::ResourceWeakLib::ResourceNode,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::ResourceWeakLib::ResourceNode,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp>>::findIndexCore<Scaleform::GFx::ResourceKey>(
           (Scaleform::HashSetBase<Scaleform::GFx::ResourceWeakLib::ResourceNode,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp,Scaleform::AllocatorGH<Scaleform::GFx::ResourceWeakLib::ResourceNode,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::ResourceWeakLib::ResourceNode,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp> > *)&v5->Resources.pTable,
           v3,
           v8 & v5->Resources.pTable->SizeMask);
    if ( v9 >= 0 )
    {
      v10 = (signed __int64)&v5->Resources.pTable[2 * (v9 + 1)];
      if ( v10 )
      {
        if ( *(_DWORD *)v10 )
        {
          v14 = *(Scaleform::GFx::Resource **)(v10 + 8);
          v4->pResource = v14;
          v4->State = 2;
          Scaleform::Render::RenderBuffer::AddRef(v14);
          v13 = v4->State;
          goto LABEL_21;
        }
        v11 = *(_QWORD *)(v10 + 8);
        v12 = *(_DWORD *)(v11 + 8);
        if ( v12 )
        {
          while ( v12 != _InterlockedCompareExchange((volatile signed __int32 *)(v11 + 8), v12 + 1, v12) )
          {
            v12 = *(_DWORD *)(v11 + 8);
            if ( !v12 )
              goto LABEL_13;
          }
          v4->pResource = *(Scaleform::GFx::Resource **)(v10 + 8);
          v13 = 1;
          v6 = v21;
          goto LABEL_20;
        }
LABEL_13:
        Scaleform::HashSetBase<Scaleform::GFx::ResourceWeakLib::ResourceNode,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp,Scaleform::AllocatorGH<Scaleform::GFx::ResourceWeakLib::ResourceNode,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::ResourceWeakLib::ResourceNode,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp>>::RemoveAlt<Scaleform::GFx::ResourceKey>(
          (Scaleform::HashSetBase<Scaleform::GFx::ResourceWeakLib::ResourceNode,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp,Scaleform::AllocatorGH<Scaleform::GFx::ResourceWeakLib::ResourceNode,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::ResourceWeakLib::ResourceNode,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp> > *)&v5->Resources.pTable,
          v3);
        v6 = v21;
      }
    }
  }
  v15 = (Scaleform::GFx::ResourceLib::ResourceSlot *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(
                                                       Scaleform::Memory::pGlobalHeap,
                                                       152ui64,
                                                       0i64);
  v20 = v15;
  if ( v15 )
  {
    Scaleform::GFx::ResourceLib::ResourceSlot::ResourceSlot(v15, v5, v3);
    v7 = v16;
  }
  if ( v7 )
  {
    node.Type = 1;
    node.pResolver = v7;
    v17 = Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp::operator()(
            (Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp *)&v20,
            &node);
    Scaleform::HashSetBase<Scaleform::GFx::ResourceWeakLib::ResourceNode,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp,Scaleform::AllocatorGH<Scaleform::GFx::ResourceWeakLib::ResourceNode,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::ResourceWeakLib::ResourceNode,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp>>::add<Scaleform::GFx::ResourceWeakLib::ResourceNode>(
      (Scaleform::HashSetBase<Scaleform::GFx::ResourceWeakLib::ResourceNode,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp,Scaleform::AllocatorGH<Scaleform::GFx::ResourceWeakLib::ResourceNode,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::ResourceWeakLib::ResourceNode,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp> > *)&v5->Resources.pTable,
      &v5->Resources,
      &node,
      v17);
    v4->pResource = (Scaleform::GFx::Resource *)v7;
    v13 = 3;
LABEL_20:
    v4->State = v13;
    goto LABEL_21;
  }
  v13 = 4;
LABEL_21:
  LeaveCriticalSection(&v6->cs);
  return v13;
}

// File Line: 401
// RVA: 0x8EFDB0
void __fastcall Scaleform::GFx::ResourceWeakLib::PinResource(Scaleform::GFx::ResourceWeakLib *this, Scaleform::GFx::Resource *pres)
{
  Scaleform::GFx::Resource *v2; // rsi
  Scaleform::GFx::ResourceWeakLib *v3; // rdi
  _RTL_CRITICAL_SECTION *v4; // rbx
  Scaleform::GFx::ResourceLib *v5; // rdi
  Scaleform::HashSetBase<Scaleform::GFx::Resource *,Scaleform::GFx::ResourceLib::ResourcePtrHashFunc,Scaleform::GFx::ResourceLib::ResourcePtrHashFunc,Scaleform::AllocatorGH<Scaleform::GFx::Resource *,2>,Scaleform::HashsetEntry<Scaleform::GFx::Resource *,Scaleform::GFx::ResourceLib::ResourcePtrHashFunc> > *v6; // rdi
  Scaleform::HashSetBase<Scaleform::GFx::Resource *,Scaleform::GFx::ResourceLib::ResourcePtrHashFunc,Scaleform::GFx::ResourceLib::ResourcePtrHashFunc,Scaleform::AllocatorGH<Scaleform::GFx::Resource *,2>,Scaleform::HashsetEntry<Scaleform::GFx::Resource *,Scaleform::GFx::ResourceLib::ResourcePtrHashFunc> > v7; // rbp
  signed __int64 v8; // rax
  Scaleform::Lock *v9; // [rsp+50h] [rbp+8h]
  Scaleform::GFx::Resource *key; // [rsp+58h] [rbp+10h]

  key = pres;
  v2 = pres;
  v3 = this;
  v4 = &this->ResourceLock.cs;
  v9 = &this->ResourceLock;
  EnterCriticalSection(&this->ResourceLock.cs);
  v5 = v3->pStrongLib;
  if ( v5 )
  {
    v6 = (Scaleform::HashSetBase<Scaleform::GFx::Resource *,Scaleform::GFx::ResourceLib::ResourcePtrHashFunc,Scaleform::GFx::ResourceLib::ResourcePtrHashFunc,Scaleform::AllocatorGH<Scaleform::GFx::Resource *,2>,Scaleform::HashsetEntry<Scaleform::GFx::Resource *,Scaleform::GFx::ResourceLib::ResourcePtrHashFunc> > *)&v5->PinSet.pTable;
    v7.pTable = v6->pTable;
    if ( !v6->pTable
      || (v8 = Scaleform::HashSetBase<Scaleform::GFx::Resource *,Scaleform::GFx::ResourceLib::ResourcePtrHashFunc,Scaleform::GFx::ResourceLib::ResourcePtrHashFunc,Scaleform::AllocatorGH<Scaleform::GFx::Resource *,2>,Scaleform::HashsetEntry<Scaleform::GFx::Resource *,Scaleform::GFx::ResourceLib::ResourcePtrHashFunc>>::findIndexCore<Scaleform::GFx::Resource *>(
                 v6,
                 &key,
                 v7.pTable->SizeMask & ((unsigned __int64)v2 ^ ((unsigned __int64)v2 >> 6))),
          v8 < 0)
      || !&v7.pTable[v8 + 1].SizeMask )
    {
      Scaleform::HashSetBase<Scaleform::GFx::Resource *,Scaleform::GFx::ResourceLib::ResourcePtrHashFunc,Scaleform::GFx::ResourceLib::ResourcePtrHashFunc,Scaleform::AllocatorGH<Scaleform::GFx::Resource *,2>,Scaleform::HashsetEntry<Scaleform::GFx::Resource *,Scaleform::GFx::ResourceLib::ResourcePtrHashFunc>>::add<Scaleform::GFx::Resource *>(
        v6,
        v6,
        &key,
        (unsigned __int64)v2 ^ ((unsigned __int64)v2 >> 6));
      _InterlockedExchangeAdd(&v2->RefCount.Value, 1u);
      v4 = &v9->cs;
    }
  }
  LeaveCriticalSection(v4);
}

// File Line: 420
// RVA: 0x9164A0
void __fastcall Scaleform::GFx::ResourceWeakLib::UnpinResource(Scaleform::GFx::ResourceWeakLib *this, Scaleform::GFx::Resource *pres)
{
  Scaleform::GFx::Resource *v2; // rsi
  Scaleform::GFx::ResourceWeakLib *v3; // rdi
  _RTL_CRITICAL_SECTION *v4; // rbx
  Scaleform::HashSetBase<Scaleform::GFx::Resource *,Scaleform::GFx::ResourceLib::ResourcePtrHashFunc,Scaleform::GFx::ResourceLib::ResourcePtrHashFunc,Scaleform::AllocatorGH<Scaleform::GFx::Resource *,2>,Scaleform::HashsetEntry<Scaleform::GFx::Resource *,Scaleform::GFx::ResourceLib::ResourcePtrHashFunc> > *v5; // rcx
  Scaleform::GFx::Resource *v6; // rbx
  Scaleform::GFx::ResourceLibBase *v7; // rcx
  Scaleform::Lock *v8; // [rsp+40h] [rbp+8h]
  Scaleform::GFx::Resource *key; // [rsp+48h] [rbp+10h]

  key = pres;
  v2 = pres;
  v3 = this;
  v4 = &this->ResourceLock.cs;
  v8 = &this->ResourceLock;
  EnterCriticalSection(&this->ResourceLock.cs);
  v5 = (Scaleform::HashSetBase<Scaleform::GFx::Resource *,Scaleform::GFx::ResourceLib::ResourcePtrHashFunc,Scaleform::GFx::ResourceLib::ResourcePtrHashFunc,Scaleform::AllocatorGH<Scaleform::GFx::Resource *,2>,Scaleform::HashsetEntry<Scaleform::GFx::Resource *,Scaleform::GFx::ResourceLib::ResourcePtrHashFunc> > *)v3->pStrongLib;
  if ( v5 )
  {
    Scaleform::HashSetBase<Scaleform::GFx::Resource *,Scaleform::GFx::ResourceLib::ResourcePtrHashFunc,Scaleform::GFx::ResourceLib::ResourcePtrHashFunc,Scaleform::AllocatorGH<Scaleform::GFx::Resource *,2>,Scaleform::HashsetEntry<Scaleform::GFx::Resource *,Scaleform::GFx::ResourceLib::ResourcePtrHashFunc>>::RemoveAlt<Scaleform::GFx::Resource *>(
      v5 + 3,
      &key);
    if ( !_InterlockedDecrement(&v2->RefCount.Value) )
    {
      v6 = key;
      v7 = key->pLib;
      if ( v7 )
      {
        v7->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v7->vfptr, (unsigned int)key);
        v6->pLib = 0i64;
      }
      v6->vfptr->__vecDelDtor(v6, 1u);
    }
    v4 = &v8->cs;
  }
  LeaveCriticalSection(v4);
}

// File Line: 433
// RVA: 0x916340
void __fastcall Scaleform::GFx::ResourceWeakLib::UnpinAll(Scaleform::GFx::ResourceWeakLib *this)
{
  Scaleform::GFx::ResourceWeakLib *v1; // r14
  _RTL_CRITICAL_SECTION *v2; // rbx
  Scaleform::GFx::ResourceLib *v3; // rsi
  signed __int64 v4; // rsi
  __int64 v5; // rdx
  unsigned __int64 v6; // rbx
  _QWORD *v7; // rax
  __int64 v8; // rdi
  __int64 v9; // rdi
  __int64 v10; // rcx
  unsigned __int64 v11; // rcx
  _QWORD *v12; // rax
  Scaleform::GFx::ResourceLib *v13; // rbx
  Scaleform::HashSetBase<Scaleform::GFx::Resource *,Scaleform::GFx::ResourceLib::ResourcePtrHashFunc,Scaleform::GFx::ResourceLib::ResourcePtrHashFunc,Scaleform::AllocatorGH<Scaleform::GFx::Resource *,2>,Scaleform::HashsetEntry<Scaleform::GFx::Resource *,Scaleform::GFx::ResourceLib::ResourcePtrHashFunc> >::TableType *v14; // rax
  __int64 v15; // rcx
  signed __int64 v16; // rdx
  Scaleform::HashSetBase<Scaleform::GFx::Resource *,Scaleform::GFx::ResourceLib::ResourcePtrHashFunc,Scaleform::GFx::ResourceLib::ResourcePtrHashFunc,Scaleform::AllocatorGH<Scaleform::GFx::Resource *,2>,Scaleform::HashsetEntry<Scaleform::GFx::Resource *,Scaleform::GFx::ResourceLib::ResourcePtrHashFunc> >::TableType *v17; // rax
  Scaleform::Lock *v18; // [rsp+50h] [rbp+8h]

  v1 = this;
  v2 = &this->ResourceLock.cs;
  v18 = &this->ResourceLock;
  EnterCriticalSection(&this->ResourceLock.cs);
  v3 = v1->pStrongLib;
  if ( v3 )
  {
    v4 = (signed __int64)&v3->PinSet;
    v5 = *(_QWORD *)v4;
    v6 = 0i64;
    if ( *(_QWORD *)v4 )
    {
      v7 = (_QWORD *)(v5 + 16);
      do
      {
        if ( *v7 != -2i64 )
          break;
        ++v6;
        v7 += 2;
      }
      while ( v6 <= *(_QWORD *)(v5 + 8) );
    }
    else
    {
      v4 = 0i64;
    }
    while ( v4 )
    {
      v8 = *(_QWORD *)v4;
      if ( !*(_QWORD *)v4 || (signed __int64)v6 > *(_QWORD *)(v8 + 8) )
        break;
      v9 = *(_QWORD *)(v8 + 16 * v6 + 24);
      if ( !_InterlockedDecrement((volatile signed __int32 *)(v9 + 8)) )
      {
        v10 = *(_QWORD *)(v9 + 16);
        if ( v10 )
        {
          (*(void (__fastcall **)(__int64, __int64))(*(_QWORD *)v10 + 8i64))(v10, v9);
          *(_QWORD *)(v9 + 16) = 0i64;
        }
        (**(void (__fastcall ***)(__int64, signed __int64))v9)(v9, 1i64);
      }
      v11 = *(_QWORD *)(*(_QWORD *)v4 + 8i64);
      if ( (signed __int64)v6 <= (signed __int64)v11 && ++v6 <= v11 )
      {
        v12 = (_QWORD *)(*(_QWORD *)v4 + 16 * (v6 + 1));
        do
        {
          if ( *v12 != -2i64 )
            break;
          ++v6;
          v12 += 2;
        }
        while ( v6 <= v11 );
      }
    }
    v13 = v1->pStrongLib;
    v14 = v13->PinSet.pTable;
    if ( v14 )
    {
      v15 = 0i64;
      v16 = v14->SizeMask + 1;
      do
      {
        v17 = v13->PinSet.pTable;
        if ( v17[v15 + 1].EntryCount != -2i64 )
          v17[v15 + 1].EntryCount = -2i64;
        ++v15;
        --v16;
      }
      while ( v16 );
      if ( v13->PinSet.pTable )
        ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      v13->PinSet.pTable = 0i64;
    }
    v2 = &v18->cs;
  }
  LeaveCriticalSection(v2);
}

// File Line: 454
// RVA: 0x8FFC70
void __fastcall Scaleform::GFx::ResourceWeakLib::RemoveResourceOnRelease(Scaleform::GFx::ResourceWeakLib *this, Scaleform::GFx::Resource *pres)
{
  Scaleform::GFx::Resource *v2; // rsi
  Scaleform::GFx::ResourceWeakLib *v3; // r14
  _RTL_CRITICAL_SECTION *v4; // rbx
  Scaleform::GFx::ResourceKey *v5; // rax
  Scaleform::GFx::ResourceKey *v6; // r15
  signed __int64 v7; // rdi
  __int64 v8; // rcx
  signed __int64 v9; // rax
  Scaleform::GFx::ResourceKey *v10; // rax
  __int64 v11; // [rsp+28h] [rbp-30h]
  __int64 v12; // [rsp+30h] [rbp-28h]

  v2 = pres;
  v3 = this;
  v4 = &this->ResourceLock.cs;
  EnterCriticalSection(&this->ResourceLock.cs);
  v5 = v2->vfptr->GetKey(v2, (Scaleform::GFx::ResourceKey *)&v11);
  v6 = v5;
  v7 = 0i64;
  if ( v3->Resources.pTable )
  {
    v8 = v5->pKeyInterface ? (__int64)v5->pKeyInterface->vfptr->GetHashCode(v5->pKeyInterface, v5->hKeyData) : 0i64;
    v9 = Scaleform::HashSetBase<Scaleform::GFx::ResourceWeakLib::ResourceNode,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp,Scaleform::AllocatorGH<Scaleform::GFx::ResourceWeakLib::ResourceNode,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::ResourceWeakLib::ResourceNode,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp>>::findIndexCore<Scaleform::GFx::ResourceKey>(
           (Scaleform::HashSetBase<Scaleform::GFx::ResourceWeakLib::ResourceNode,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp,Scaleform::AllocatorGH<Scaleform::GFx::ResourceWeakLib::ResourceNode,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::ResourceWeakLib::ResourceNode,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp> > *)&v3->Resources.pTable,
           v6,
           v8 & v3->Resources.pTable->SizeMask);
    if ( v9 >= 0 )
      v7 = (signed __int64)&v3->Resources.pTable[2 * (v9 + 1)];
  }
  if ( v11 )
    (*(void (__fastcall **)(__int64, __int64))(*(_QWORD *)v11 + 16i64))(v11, v12);
  if ( v7 )
  {
    if ( !*(_DWORD *)v7 && *(Scaleform::GFx::Resource **)(v7 + 8) == v2 )
    {
      v10 = v2->vfptr->GetKey(v2, (Scaleform::GFx::ResourceKey *)&v11);
      Scaleform::HashSetBase<Scaleform::GFx::ResourceWeakLib::ResourceNode,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp,Scaleform::AllocatorGH<Scaleform::GFx::ResourceWeakLib::ResourceNode,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::ResourceWeakLib::ResourceNode,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp>>::RemoveAlt<Scaleform::GFx::ResourceKey>(
        (Scaleform::HashSetBase<Scaleform::GFx::ResourceWeakLib::ResourceNode,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp,Scaleform::AllocatorGH<Scaleform::GFx::ResourceWeakLib::ResourceNode,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::ResourceWeakLib::ResourceNode,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp> > *)&v3->Resources.pTable,
        v10);
      if ( v11 )
        (*(void (__fastcall **)(__int64, __int64))(*(_QWORD *)v11 + 16i64))(v11, v12);
    }
  }
  LeaveCriticalSection(v4);
}

// File Line: 503
// RVA: 0x89C520
void __fastcall Scaleform::GFx::ResourceFileInfo::ResourceFileInfo(Scaleform::GFx::ResourceFileInfo *this)
{
  Scaleform::GFx::ResourceFileInfo *v1; // rbx

  v1 = this;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountNTSImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountNTSImpl::`vftable;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountNTSImpl,2>::`vftable;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountBaseNTS<Scaleform::GFx::ResourceFileInfo,2>::`vftable;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::GFx::ResourceFileInfo::`vftable;
  Scaleform::String::String(&this->FileName);
  v1->Format = 1;
  v1->pExporterInfo = 0i64;
}

// File Line: 509
// RVA: 0x89C490
void __fastcall Scaleform::GFx::ResourceFileInfo::ResourceFileInfo(Scaleform::GFx::ResourceFileInfo *this, Scaleform::GFx::ResourceFileInfo *src)
{
  Scaleform::GFx::ResourceFileInfo *v2; // rbx
  Scaleform::GFx::ResourceFileInfo *v3; // rdi

  v2 = src;
  v3 = this;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountNTSImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountNTSImpl::`vftable;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountNTSImpl,2>::`vftable;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountBaseNTS<Scaleform::GFx::ResourceFileInfo,2>::`vftable;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::GFx::ResourceFileInfo::`vftable;
  Scaleform::String::String(&this->FileName, &src->FileName);
  v3->Format = v2->Format;
  v3->pExporterInfo = v2->pExporterInfo;
}

// File Line: 535
// RVA: 0x89C5A0
void __fastcall Scaleform::GFx::ResourceKey::ResourceKey(Scaleform::GFx::ResourceKey *this, Scaleform::GFx::ResourceKey *src)
{
  Scaleform::GFx::ResourceKey *v2; // rdi
  Scaleform::GFx::ResourceKey *v3; // rbx

  v2 = this;
  v3 = src;
  if ( src->pKeyInterface )
    src->pKeyInterface->vfptr->AddRef(src->pKeyInterface, src->hKeyData);
  v2->pKeyInterface = v3->pKeyInterface;
  v2->hKeyData = v3->hKeyData;
}

