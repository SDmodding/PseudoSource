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
  Scaleform::GFx::ResourceLibBase *pLib; // rcx

  if ( !_InterlockedDecrement(&this->RefCount.Value) )
  {
    pLib = this->pLib;
    if ( pLib )
    {
      pLib->vfptr[1].__vecDelDtor(pLib, (unsigned int)this);
      this->pLib = 0i64;
    }
    this->vfptr->__vecDelDtor(this, 1i64);
  }
}

// File Line: 77
// RVA: 0x89C5E0
void __fastcall Scaleform::GFx::ResourceLib::ResourceLib(Scaleform::GFx::ResourceLib *this, bool debug)
{
  Scaleform::GFx::ResourceWeakLib *v3; // rdi
  Scaleform::GFx::ResourceWeakLib *v4; // rax
  Scaleform::GFx::ResourceWeakLib *v5; // rax

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
                                            80i64,
                                            0i64);
  if ( v4 )
  {
    Scaleform::GFx::ResourceWeakLib::ResourceWeakLib(v4, this);
    v3 = v5;
  }
  this->pWeakLib = v3;
}

// File Line: 92
// RVA: 0x89C690
void __fastcall Scaleform::GFx::ResourceLib::ResourceSlot::ResourceSlot(
        Scaleform::GFx::ResourceLib::ResourceSlot *this,
        Scaleform::GFx::Resource *plib,
        Scaleform::GFx::ResourceKey *key)
{
  Scaleform::Render::RenderBuffer *pObject; // rcx
  Scaleform::GFx::ResourceKey::KeyInterface *pKeyInterface; // rcx

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
  Scaleform::Event::Event(&this->ResolveComplete, 0, 0);
  if ( plib )
    Scaleform::Render::RenderBuffer::AddRef(plib);
  pObject = (Scaleform::Render::RenderBuffer *)this->pLib.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  this->pLib.pObject = (Scaleform::GFx::ResourceWeakLib *)plib;
  this->State = Resolve_InProgress;
  this->pResource = 0i64;
  if ( key->pKeyInterface )
    key->pKeyInterface->vfptr->AddRef(key->pKeyInterface, key->hKeyData);
  pKeyInterface = this->Key.pKeyInterface;
  if ( pKeyInterface )
    pKeyInterface->vfptr->Release(pKeyInterface, this->Key.hKeyData);
  this->Key.pKeyInterface = key->pKeyInterface;
  this->Key.hKeyData = key->hKeyData;
}

// File Line: 101
// RVA: 0x8A7410
void __fastcall Scaleform::GFx::ResourceLib::ResourceSlot::~ResourceSlot(
        Scaleform::GFx::ResourceLib::ResourceSlot *this)
{
  Scaleform::GFx::Resource *volatile pResource; // rsi
  Scaleform::GFx::ResourceLibBase *pLib; // rcx
  Scaleform::GFx::ResourceKey::KeyInterface *pKeyInterface; // rcx
  Scaleform::Render::RenderBuffer *pObject; // rcx
  Scaleform::Lock *lpCriticalSection; // [rsp+48h] [rbp+10h]

  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::ResourceLib::ResourceSlot::`vftable;
  lpCriticalSection = &this->pLib.pObject->ResourceLock;
  EnterCriticalSection(&lpCriticalSection->cs);
  if ( this->State )
  {
    if ( this->pResource )
    {
      pResource = this->pResource;
      if ( !_InterlockedDecrement(&pResource->RefCount.Value) )
      {
        pLib = pResource->pLib;
        if ( pLib )
        {
          pLib->vfptr[1].__vecDelDtor(pLib, (unsigned int)pResource);
          pResource->pLib = 0i64;
        }
        pResource->vfptr->__vecDelDtor(pResource, 1u);
      }
    }
  }
  else
  {
    Scaleform::HashSetBase<Scaleform::GFx::ResourceWeakLib::ResourceNode,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp,Scaleform::AllocatorGH<Scaleform::GFx::ResourceWeakLib::ResourceNode,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::ResourceWeakLib::ResourceNode,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp>>::RemoveAlt<Scaleform::GFx::ResourceKey>(
      &this->pLib.pObject->Resources,
      &this->Key);
  }
  LeaveCriticalSection(&lpCriticalSection->cs);
  Scaleform::Event::~Event(&this->ResolveComplete);
  if ( !_InterlockedDecrement((volatile signed __int32 *)((this->ErrorMessage.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  pKeyInterface = this->Key.pKeyInterface;
  if ( pKeyInterface )
    pKeyInterface->vfptr->Release(pKeyInterface, this->Key.hKeyData);
  pObject = (Scaleform::Render::RenderBuffer *)this->pLib.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
}

// File Line: 155
// RVA: 0x903910
void __fastcall Scaleform::GFx::ResourceLib::ResourceSlot::Resolve(
        Scaleform::GFx::ResourceLib::ResourceSlot *this,
        Scaleform::GFx::Resource *pres)
{
  Scaleform::GFx::ResourceWeakLib *pObject; // r14
  unsigned __int64 pKeyInterface; // rcx
  signed __int64 v6; // rax
  __int64 v7; // rax
  Scaleform::Lock *p_ResourceLock; // [rsp+40h] [rbp+8h]

  p_ResourceLock = &this->pLib.pObject->ResourceLock;
  EnterCriticalSection(&p_ResourceLock->cs);
  _InterlockedExchangeAdd(&pres->RefCount.Value, 1u);
  this->pResource = pres;
  this->State = Resolve_Success;
  pObject = this->pLib.pObject;
  if ( !pObject->Resources.pTable )
    goto LABEL_6;
  pKeyInterface = (unsigned __int64)this->Key.pKeyInterface;
  if ( pKeyInterface )
    pKeyInterface = (*(__int64 (__fastcall **)(unsigned __int64, void *))(*(_QWORD *)pKeyInterface + 32i64))(
                      pKeyInterface,
                      this->Key.hKeyData);
  v6 = Scaleform::HashSetBase<Scaleform::GFx::ResourceWeakLib::ResourceNode,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp,Scaleform::AllocatorGH<Scaleform::GFx::ResourceWeakLib::ResourceNode,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::ResourceWeakLib::ResourceNode,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp>>::findIndexCore<Scaleform::GFx::ResourceKey>(
         &pObject->Resources,
         &this->Key,
         pKeyInterface & pObject->Resources.pTable->SizeMask);
  if ( v6 >= 0 )
    v7 = (__int64)&pObject->Resources.pTable[2 * v6 + 2];
  else
LABEL_6:
    v7 = 0i64;
  *(_QWORD *)(v7 + 8) = pres;
  *(_DWORD *)v7 = 0;
  pres->pLib = this->pLib.pObject;
  Scaleform::Event::SetEvent(&this->ResolveComplete);
  LeaveCriticalSection(&p_ResourceLock->cs);
}

// File Line: 185
// RVA: 0x8B9820
void __fastcall Scaleform::GFx::ResourceLib::ResourceSlot::CancelResolve(
        Scaleform::GFx::ResourceLib::ResourceSlot *this,
        const char *perrorMessage)
{
  Scaleform::Lock *p_ResourceLock; // rbx

  p_ResourceLock = &this->pLib.pObject->ResourceLock;
  EnterCriticalSection(&p_ResourceLock->cs);
  this->State = Resolve_Fail;
  Scaleform::String::operator=(&this->ErrorMessage, perrorMessage);
  Scaleform::HashSetBase<Scaleform::GFx::ResourceWeakLib::ResourceNode,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp,Scaleform::AllocatorGH<Scaleform::GFx::ResourceWeakLib::ResourceNode,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::ResourceWeakLib::ResourceNode,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp>>::RemoveAlt<Scaleform::GFx::ResourceKey>(
    &this->pLib.pObject->Resources,
    &this->Key);
  Scaleform::Event::SetEvent(&this->ResolveComplete);
  LeaveCriticalSection(&p_ResourceLock->cs);
}

// File Line: 207
// RVA: 0x91A240
Scaleform::GFx::Resource *__fastcall Scaleform::GFx::ResourceLib::BindHandle::WaitForResolve(
        Scaleform::GFx::ResourceLib::BindHandle *this)
{
  Scaleform::GFx::Resource *pResource; // rsi
  Scaleform::GFx::Resource *v4; // rdi

  if ( this->State == RS_Available )
  {
    _InterlockedExchangeAdd(&this->pResource->RefCount.Value, 1u);
    return this->pResource;
  }
  else if ( this->State == RS_Error )
  {
    return 0i64;
  }
  else
  {
    pResource = this->pResource;
    Scaleform::Event::Wait((Scaleform::Event *)&pResource[2].pLib, 0xFFFFFFFF);
    if ( *(_QWORD *)&pResource[1].RefCount.Value )
      _InterlockedExchangeAdd((volatile signed __int32 *)(*(_QWORD *)&pResource[1].RefCount.Value + 8i64), 1u);
    v4 = *(Scaleform::GFx::Resource **)&pResource[1].RefCount.Value;
    if ( v4 )
    {
      this->State = RS_Available;
      this->pResource = v4;
      _InterlockedExchangeAdd(&v4->RefCount.Value, 1u);
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)pResource);
      return v4;
    }
    else
    {
      this->State = RS_Error;
      return 0i64;
    }
  }
}

// File Line: 254
// RVA: 0x89C790
void __fastcall Scaleform::GFx::ResourceWeakLib::ResourceWeakLib(
        Scaleform::GFx::ResourceWeakLib *this,
        Scaleform::GFx::ResourceLib *pstrongLib)
{
  int v4; // eax
  Scaleform::MemoryHeap *v5; // rdi
  Scaleform::MemoryHeap *pObject; // rcx
  int v7; // [rsp+30h] [rbp-48h] BYREF
  __int64 v8; // [rsp+38h] [rbp-40h]
  __int64 v9; // [rsp+40h] [rbp-38h]
  __int64 v10; // [rsp+48h] [rbp-30h]
  __int64 v11; // [rsp+50h] [rbp-28h]
  __int64 v12; // [rsp+58h] [rbp-20h]
  __int64 v13; // [rsp+60h] [rbp-18h]
  __int64 v14; // [rsp+68h] [rbp-10h]

  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::GFx::ResourceLibBase,2>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::ResourceLibBase::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::ResourceWeakLib::`vftable;
  Scaleform::Lock::Lock(&this->ResourceLock, 0);
  this->Resources.pTable = 0i64;
  this->pImageHeap.pObject = 0i64;
  this->pStrongLib = pstrongLib;
  if ( !pstrongLib || (v4 = 4096, !pstrongLib->DebugFlag) )
    v4 = 0;
  v14 = 0i64;
  v7 = v4 | 4;
  v8 = 64i64;
  v9 = 4096i64;
  v10 = 0i64;
  v11 = -1i64;
  v12 = 0i64;
  v13 = 5i64;
  v5 = (Scaleform::MemoryHeap *)(*(__int64 (__fastcall **)(Scaleform::MemoryHeap *, const char *, int *))&Scaleform::Memory::pGlobalHeap->vfptr->gap8[24])(
                                  Scaleform::Memory::pGlobalHeap,
                                  "_ResourceLib_Images",
                                  &v7);
  pObject = this->pImageHeap.pObject;
  if ( pObject )
    pObject->vfptr->Release(pObject);
  this->pImageHeap.pObject = v5;
}

// File Line: 275
// RVA: 0x8A7510
void __fastcall Scaleform::GFx::ResourceWeakLib::~ResourceWeakLib(Scaleform::GFx::ResourceWeakLib *this)
{
  Scaleform::Lock *p_ResourceLock; // rbx
  Scaleform::HashSet<Scaleform::GFx::ResourceWeakLib::ResourceNode,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp,Scaleform::AllocatorGH<Scaleform::GFx::ResourceWeakLib::ResourceNode,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::ResourceWeakLib::ResourceNode,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp> > *p_Resources; // rdi
  Scaleform::HashSetBase<Scaleform::GFx::ResourceWeakLib::ResourceNode,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp,Scaleform::AllocatorGH<Scaleform::GFx::ResourceWeakLib::ResourceNode,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::ResourceWeakLib::ResourceNode,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp> >::TableType *pTable; // rdx
  unsigned __int64 v5; // rax
  Scaleform::HashSetBase<Scaleform::GFx::ResourceWeakLib::ResourceNode,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp,Scaleform::AllocatorGH<Scaleform::GFx::ResourceWeakLib::ResourceNode,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::ResourceWeakLib::ResourceNode,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp> >::TableType *v6; // rcx
  signed __int64 v7; // rcx
  Scaleform::HashSetBase<Scaleform::GFx::ResourceWeakLib::ResourceNode,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp,Scaleform::AllocatorGH<Scaleform::GFx::ResourceWeakLib::ResourceNode,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::ResourceWeakLib::ResourceNode,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp> >::TableType *v8; // rdx
  unsigned __int64 SizeMask; // r8
  Scaleform::HashSetBase<Scaleform::GFx::ResourceWeakLib::ResourceNode,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp,Scaleform::AllocatorGH<Scaleform::GFx::ResourceWeakLib::ResourceNode,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::ResourceWeakLib::ResourceNode,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp> >::TableType *v10; // rdx
  Scaleform::MemoryHeap *pObject; // rcx
  __int64 v12; // rcx
  __int64 v13; // rdx
  Scaleform::HashSet<Scaleform::GFx::ResourceWeakLib::ResourceNode,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp,Scaleform::AllocatorGH<Scaleform::GFx::ResourceWeakLib::ResourceNode,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::ResourceWeakLib::ResourceNode,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp> > *v14; // [rsp+30h] [rbp-28h]
  unsigned __int64 v15; // [rsp+38h] [rbp-20h]

  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::ResourceWeakLib::`vftable;
  p_ResourceLock = &this->ResourceLock;
  EnterCriticalSection(&this->ResourceLock.cs);
  p_Resources = &this->Resources;
  pTable = this->Resources.pTable;
  if ( pTable )
  {
    v5 = 0i64;
    v6 = pTable + 1;
    do
    {
      if ( v6->EntryCount != -2i64 )
        break;
      ++v5;
      v6 += 2;
    }
    while ( v5 <= pTable->SizeMask );
    v14 = &this->Resources;
    v15 = v5;
  }
  else
  {
    v14 = 0i64;
    v15 = 0i64;
  }
  v7 = v15;
  while ( v14 )
  {
    v8 = v14->pTable;
    if ( !v14->pTable || v7 > (signed __int64)v8->SizeMask )
      break;
    *(_QWORD *)(v8[2 * v7 + 2].SizeMask + 16) = 0i64;
    SizeMask = v14->pTable->SizeMask;
    if ( v7 <= (__int64)SizeMask && ++v7 <= SizeMask )
    {
      v10 = &v14->pTable[2 * v7 + 1];
      do
      {
        if ( v10->EntryCount != -2i64 )
          break;
        ++v7;
        v10 += 2;
      }
      while ( v7 <= SizeMask );
    }
  }
  LeaveCriticalSection(&p_ResourceLock->cs);
  pObject = this->pImageHeap.pObject;
  if ( pObject )
    pObject->vfptr->Release(pObject);
  if ( p_Resources->pTable )
  {
    v12 = 0i64;
    v13 = p_Resources->pTable->SizeMask + 1;
    do
    {
      if ( p_Resources->pTable[v12 + 1].EntryCount != -2i64 )
        p_Resources->pTable[v12 + 1].EntryCount = -2i64;
      v12 += 2i64;
      --v13;
    }
    while ( v13 );
    if ( p_Resources->pTable )
      ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
    p_Resources->pTable = 0i64;
  }
  Scaleform::Lock::~Lock(&p_ResourceLock->cs);
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
}

// File Line: 313
// RVA: 0x8B7FB0
__int64 __fastcall Scaleform::GFx::ResourceWeakLib::BindResourceKey(
        Scaleform::GFx::ResourceWeakLib *this,
        Scaleform::GFx::ResourceLib::BindHandle *phandle,
        Scaleform::GFx::ResourceKey *k)
{
  Scaleform::Lock *p_ResourceLock; // rbx
  Scaleform::GFx::ResourceLib::ResourceSlot *v7; // rbp
  unsigned __int64 v8; // rcx
  signed __int64 v9; // rax
  Scaleform::HashSetBase<Scaleform::GFx::ResourceWeakLib::ResourceNode,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp,Scaleform::AllocatorGH<Scaleform::GFx::ResourceWeakLib::ResourceNode,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::ResourceWeakLib::ResourceNode,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp> >::TableType *v10; // r8
  unsigned __int64 v11; // rdx
  signed __int32 v12; // eax
  Scaleform::GFx::ResourceLib::ResolveState State; // edi
  Scaleform::GFx::Resource *SizeMask; // rcx
  Scaleform::GFx::ResourceLib::ResourceSlot *v15; // rax
  Scaleform::GFx::ResourceLib::ResourceSlot *v16; // rax
  __int64 v17; // rax
  Scaleform::GFx::ResourceWeakLib::ResourceNode node; // [rsp+28h] [rbp-40h] BYREF
  Scaleform::GFx::ResourceLib::ResourceSlot *v20; // [rsp+70h] [rbp+8h] BYREF
  Scaleform::Lock *v21; // [rsp+88h] [rbp+20h]

  p_ResourceLock = &this->ResourceLock;
  v21 = &this->ResourceLock;
  EnterCriticalSection(&this->ResourceLock.cs);
  v7 = 0i64;
  if ( this->Resources.pTable )
  {
    v8 = k->pKeyInterface ? k->pKeyInterface->vfptr->GetHashCode(k->pKeyInterface, k->hKeyData) : 0i64;
    v9 = Scaleform::HashSetBase<Scaleform::GFx::ResourceWeakLib::ResourceNode,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp,Scaleform::AllocatorGH<Scaleform::GFx::ResourceWeakLib::ResourceNode,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::ResourceWeakLib::ResourceNode,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp>>::findIndexCore<Scaleform::GFx::ResourceKey>(
           &this->Resources,
           k,
           v8 & this->Resources.pTable->SizeMask);
    if ( v9 >= 0 )
    {
      v10 = &this->Resources.pTable[2 * v9 + 2];
      if ( v10 )
      {
        if ( LODWORD(v10->EntryCount) )
        {
          SizeMask = (Scaleform::GFx::Resource *)v10->SizeMask;
          phandle->pResource = SizeMask;
          phandle->State = RS_WaitingResolve;
          Scaleform::Render::RenderBuffer::AddRef(SizeMask);
          State = phandle->State;
          goto LABEL_21;
        }
        v11 = v10->SizeMask;
        v12 = *(_DWORD *)(v11 + 8);
        if ( v12 )
        {
          while ( v12 != _InterlockedCompareExchange((volatile signed __int32 *)(v11 + 8), v12 + 1, v12) )
          {
            v12 = *(_DWORD *)(v11 + 8);
            if ( !v12 )
              goto LABEL_13;
          }
          phandle->pResource = (Scaleform::GFx::Resource *)v10->SizeMask;
          State = RS_Available;
          p_ResourceLock = v21;
          goto LABEL_20;
        }
LABEL_13:
        Scaleform::HashSetBase<Scaleform::GFx::ResourceWeakLib::ResourceNode,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp,Scaleform::AllocatorGH<Scaleform::GFx::ResourceWeakLib::ResourceNode,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::ResourceWeakLib::ResourceNode,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp>>::RemoveAlt<Scaleform::GFx::ResourceKey>(
          &this->Resources,
          k);
        p_ResourceLock = v21;
      }
    }
  }
  v15 = (Scaleform::GFx::ResourceLib::ResourceSlot *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(
                                                       Scaleform::Memory::pGlobalHeap,
                                                       152i64,
                                                       0i64);
  v20 = v15;
  if ( v15 )
  {
    Scaleform::GFx::ResourceLib::ResourceSlot::ResourceSlot(v15, (Scaleform::GFx::Resource *)this, k);
    v7 = v16;
  }
  if ( v7 )
  {
    node.Type = Node_Resolver;
    node.pResolver = v7;
    v17 = Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp::operator()(
            (Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp *)&v20,
            &node);
    Scaleform::HashSetBase<Scaleform::GFx::ResourceWeakLib::ResourceNode,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp,Scaleform::AllocatorGH<Scaleform::GFx::ResourceWeakLib::ResourceNode,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::ResourceWeakLib::ResourceNode,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp>>::add<Scaleform::GFx::ResourceWeakLib::ResourceNode>(
      &this->Resources,
      &this->Resources,
      &node,
      v17);
    phandle->pResource = (Scaleform::GFx::Resource *)v7;
    State = RS_NeedsResolve;
LABEL_20:
    phandle->State = State;
    goto LABEL_21;
  }
  State = RS_Error;
LABEL_21:
  LeaveCriticalSection(&p_ResourceLock->cs);
  return (unsigned int)State;
}

// File Line: 401
// RVA: 0x8EFDB0
void __fastcall Scaleform::GFx::ResourceWeakLib::PinResource(
        Scaleform::GFx::ResourceWeakLib *this,
        Scaleform::GFx::Resource *pres)
{
  Scaleform::Lock *p_ResourceLock; // rbx
  Scaleform::GFx::ResourceLib *pStrongLib; // rdi
  Scaleform::HashSetBase<Scaleform::GFx::Resource *,Scaleform::GFx::ResourceLib::ResourcePtrHashFunc,Scaleform::GFx::ResourceLib::ResourcePtrHashFunc,Scaleform::AllocatorGH<Scaleform::GFx::Resource *,2>,Scaleform::HashsetEntry<Scaleform::GFx::Resource *,Scaleform::GFx::ResourceLib::ResourcePtrHashFunc> > *p_PinSet; // rdi
  Scaleform::HashSetBase<Scaleform::GFx::Resource *,Scaleform::GFx::ResourceLib::ResourcePtrHashFunc,Scaleform::GFx::ResourceLib::ResourcePtrHashFunc,Scaleform::AllocatorGH<Scaleform::GFx::Resource *,2>,Scaleform::HashsetEntry<Scaleform::GFx::Resource *,Scaleform::GFx::ResourceLib::ResourcePtrHashFunc> > v7; // rbp
  signed __int64 v8; // rax
  Scaleform::Lock *v9; // [rsp+50h] [rbp+8h]
  Scaleform::GFx::Resource *key; // [rsp+58h] [rbp+10h] BYREF

  key = pres;
  p_ResourceLock = &this->ResourceLock;
  v9 = &this->ResourceLock;
  EnterCriticalSection(&this->ResourceLock.cs);
  pStrongLib = this->pStrongLib;
  if ( pStrongLib )
  {
    p_PinSet = &pStrongLib->PinSet;
    v7.pTable = p_PinSet->pTable;
    if ( !p_PinSet->pTable
      || (v8 = Scaleform::HashSetBase<Scaleform::GFx::Resource *,Scaleform::GFx::ResourceLib::ResourcePtrHashFunc,Scaleform::GFx::ResourceLib::ResourcePtrHashFunc,Scaleform::AllocatorGH<Scaleform::GFx::Resource *,2>,Scaleform::HashsetEntry<Scaleform::GFx::Resource *,Scaleform::GFx::ResourceLib::ResourcePtrHashFunc>>::findIndexCore<Scaleform::GFx::Resource *>(
                 p_PinSet,
                 &key,
                 v7.pTable->SizeMask & ((unsigned __int64)pres ^ ((unsigned __int64)pres >> 6))),
          v8 < 0)
      || !&v7.pTable[v8 + 1].SizeMask )
    {
      Scaleform::HashSetBase<Scaleform::GFx::Resource *,Scaleform::GFx::ResourceLib::ResourcePtrHashFunc,Scaleform::GFx::ResourceLib::ResourcePtrHashFunc,Scaleform::AllocatorGH<Scaleform::GFx::Resource *,2>,Scaleform::HashsetEntry<Scaleform::GFx::Resource *,Scaleform::GFx::ResourceLib::ResourcePtrHashFunc>>::add<Scaleform::GFx::Resource *>(
        p_PinSet,
        p_PinSet,
        &key,
        (unsigned __int64)pres ^ ((unsigned __int64)pres >> 6));
      _InterlockedExchangeAdd(&pres->RefCount.Value, 1u);
      p_ResourceLock = v9;
    }
  }
  LeaveCriticalSection(&p_ResourceLock->cs);
}

// File Line: 420
// RVA: 0x9164A0
void __fastcall Scaleform::GFx::ResourceWeakLib::UnpinResource(
        Scaleform::GFx::ResourceWeakLib *this,
        Scaleform::GFx::Resource *pres)
{
  Scaleform::Lock *p_ResourceLock; // rbx
  Scaleform::GFx::ResourceLib *pStrongLib; // rcx
  Scaleform::GFx::Resource *v6; // rbx
  Scaleform::GFx::ResourceLibBase *pLib; // rcx
  Scaleform::Lock *v8; // [rsp+40h] [rbp+8h]
  Scaleform::GFx::Resource *key; // [rsp+48h] [rbp+10h] BYREF

  key = pres;
  p_ResourceLock = &this->ResourceLock;
  v8 = &this->ResourceLock;
  EnterCriticalSection(&this->ResourceLock.cs);
  pStrongLib = this->pStrongLib;
  if ( pStrongLib )
  {
    Scaleform::HashSetBase<Scaleform::GFx::Resource *,Scaleform::GFx::ResourceLib::ResourcePtrHashFunc,Scaleform::GFx::ResourceLib::ResourcePtrHashFunc,Scaleform::AllocatorGH<Scaleform::GFx::Resource *,2>,Scaleform::HashsetEntry<Scaleform::GFx::Resource *,Scaleform::GFx::ResourceLib::ResourcePtrHashFunc>>::RemoveAlt<Scaleform::GFx::Resource *>(
      &pStrongLib->PinSet,
      &key);
    if ( !_InterlockedDecrement(&pres->RefCount.Value) )
    {
      v6 = key;
      pLib = key->pLib;
      if ( pLib )
      {
        pLib->vfptr[1].__vecDelDtor(pLib, (unsigned int)key);
        v6->pLib = 0i64;
      }
      v6->vfptr->__vecDelDtor(v6, 1u);
    }
    p_ResourceLock = v8;
  }
  LeaveCriticalSection(&p_ResourceLock->cs);
}

// File Line: 433
// RVA: 0x916340
void __fastcall Scaleform::GFx::ResourceWeakLib::UnpinAll(Scaleform::GFx::ResourceWeakLib *this)
{
  Scaleform::Lock *p_ResourceLock; // rbx
  Scaleform::GFx::ResourceLib *pStrongLib; // rsi
  Scaleform::HashSetUncached<Scaleform::GFx::Resource *,Scaleform::GFx::ResourceLib::ResourcePtrHashFunc,Scaleform::GFx::ResourceLib::ResourcePtrHashFunc,Scaleform::AllocatorGH<Scaleform::GFx::Resource *,2> > *p_PinSet; // rsi
  Scaleform::HashSetBase<Scaleform::GFx::Resource *,Scaleform::GFx::ResourceLib::ResourcePtrHashFunc,Scaleform::GFx::ResourceLib::ResourcePtrHashFunc,Scaleform::AllocatorGH<Scaleform::GFx::Resource *,2>,Scaleform::HashsetEntry<Scaleform::GFx::Resource *,Scaleform::GFx::ResourceLib::ResourcePtrHashFunc> >::TableType *pTable; // rdx
  unsigned __int64 v6; // rbx
  Scaleform::HashSetBase<Scaleform::GFx::Resource *,Scaleform::GFx::ResourceLib::ResourcePtrHashFunc,Scaleform::GFx::ResourceLib::ResourcePtrHashFunc,Scaleform::AllocatorGH<Scaleform::GFx::Resource *,2>,Scaleform::HashsetEntry<Scaleform::GFx::Resource *,Scaleform::GFx::ResourceLib::ResourcePtrHashFunc> >::TableType *v7; // rax
  Scaleform::HashSetBase<Scaleform::GFx::Resource *,Scaleform::GFx::ResourceLib::ResourcePtrHashFunc,Scaleform::GFx::ResourceLib::ResourcePtrHashFunc,Scaleform::AllocatorGH<Scaleform::GFx::Resource *,2>,Scaleform::HashsetEntry<Scaleform::GFx::Resource *,Scaleform::GFx::ResourceLib::ResourcePtrHashFunc> >::TableType *v8; // rdi
  unsigned __int64 SizeMask; // rdi
  __int64 v10; // rcx
  unsigned __int64 v11; // rcx
  Scaleform::HashSetBase<Scaleform::GFx::Resource *,Scaleform::GFx::ResourceLib::ResourcePtrHashFunc,Scaleform::GFx::ResourceLib::ResourcePtrHashFunc,Scaleform::AllocatorGH<Scaleform::GFx::Resource *,2>,Scaleform::HashsetEntry<Scaleform::GFx::Resource *,Scaleform::GFx::ResourceLib::ResourcePtrHashFunc> >::TableType *v12; // rax
  Scaleform::GFx::ResourceLib *v13; // rbx
  Scaleform::HashSetBase<Scaleform::GFx::Resource *,Scaleform::GFx::ResourceLib::ResourcePtrHashFunc,Scaleform::GFx::ResourceLib::ResourcePtrHashFunc,Scaleform::AllocatorGH<Scaleform::GFx::Resource *,2>,Scaleform::HashsetEntry<Scaleform::GFx::Resource *,Scaleform::GFx::ResourceLib::ResourcePtrHashFunc> >::TableType *v14; // rax
  __int64 v15; // rcx
  __int64 v16; // rdx
  Scaleform::HashSetBase<Scaleform::GFx::Resource *,Scaleform::GFx::ResourceLib::ResourcePtrHashFunc,Scaleform::GFx::ResourceLib::ResourcePtrHashFunc,Scaleform::AllocatorGH<Scaleform::GFx::Resource *,2>,Scaleform::HashsetEntry<Scaleform::GFx::Resource *,Scaleform::GFx::ResourceLib::ResourcePtrHashFunc> >::TableType *v17; // rax
  Scaleform::Lock *v18; // [rsp+50h] [rbp+8h]

  p_ResourceLock = &this->ResourceLock;
  v18 = &this->ResourceLock;
  EnterCriticalSection(&this->ResourceLock.cs);
  pStrongLib = this->pStrongLib;
  if ( pStrongLib )
  {
    p_PinSet = &pStrongLib->PinSet;
    pTable = p_PinSet->pTable;
    v6 = 0i64;
    if ( p_PinSet->pTable )
    {
      v7 = pTable + 1;
      do
      {
        if ( v7->EntryCount != -2i64 )
          break;
        ++v6;
        ++v7;
      }
      while ( v6 <= pTable->SizeMask );
    }
    else
    {
      p_PinSet = 0i64;
    }
    while ( p_PinSet )
    {
      v8 = p_PinSet->pTable;
      if ( !p_PinSet->pTable || (signed __int64)v6 > (signed __int64)v8->SizeMask )
        break;
      SizeMask = v8[v6 + 1].SizeMask;
      if ( !_InterlockedDecrement((volatile signed __int32 *)(SizeMask + 8)) )
      {
        v10 = *(_QWORD *)(SizeMask + 16);
        if ( v10 )
        {
          (*(void (__fastcall **)(__int64, unsigned __int64))(*(_QWORD *)v10 + 8i64))(v10, SizeMask);
          *(_QWORD *)(SizeMask + 16) = 0i64;
        }
        (**(void (__fastcall ***)(unsigned __int64, __int64))SizeMask)(SizeMask, 1i64);
      }
      v11 = p_PinSet->pTable->SizeMask;
      if ( (__int64)v6 <= (__int64)v11 && ++v6 <= v11 )
      {
        v12 = &p_PinSet->pTable[v6 + 1];
        do
        {
          if ( v12->EntryCount != -2i64 )
            break;
          ++v6;
          ++v12;
        }
        while ( v6 <= v11 );
      }
    }
    v13 = this->pStrongLib;
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
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      v13->PinSet.pTable = 0i64;
    }
    p_ResourceLock = v18;
  }
  LeaveCriticalSection(&p_ResourceLock->cs);
}

// File Line: 454
// RVA: 0x8FFC70
void __fastcall Scaleform::GFx::ResourceWeakLib::RemoveResourceOnRelease(
        Scaleform::GFx::ResourceWeakLib *this,
        Scaleform::GFx::Resource *pres)
{
  Scaleform::Lock *p_ResourceLock; // rbx
  Scaleform::GFx::ResourceKey *v5; // rax
  Scaleform::GFx::ResourceKey *v6; // r15
  Scaleform::HashSetBase<Scaleform::GFx::ResourceWeakLib::ResourceNode,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp,Scaleform::AllocatorGH<Scaleform::GFx::ResourceWeakLib::ResourceNode,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::ResourceWeakLib::ResourceNode,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp> >::TableType *v7; // rdi
  __int64 v8; // rcx
  signed __int64 v9; // rax
  Scaleform::GFx::ResourceKey *v10; // rax
  __int64 v11; // [rsp+28h] [rbp-30h] BYREF
  __int64 v12; // [rsp+30h] [rbp-28h]

  p_ResourceLock = &this->ResourceLock;
  EnterCriticalSection(&this->ResourceLock.cs);
  v5 = pres->vfptr->GetKey(pres, &v11);
  v6 = v5;
  v7 = 0i64;
  if ( this->Resources.pTable )
  {
    v8 = v5->pKeyInterface ? v5->pKeyInterface->vfptr->GetHashCode(v5->pKeyInterface, v5->hKeyData) : 0i64;
    v9 = Scaleform::HashSetBase<Scaleform::GFx::ResourceWeakLib::ResourceNode,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp,Scaleform::AllocatorGH<Scaleform::GFx::ResourceWeakLib::ResourceNode,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::ResourceWeakLib::ResourceNode,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp>>::findIndexCore<Scaleform::GFx::ResourceKey>(
           &this->Resources,
           v6,
           v8 & this->Resources.pTable->SizeMask);
    if ( v9 >= 0 )
      v7 = &this->Resources.pTable[2 * v9 + 2];
  }
  if ( v11 )
    (*(void (__fastcall **)(__int64, __int64))(*(_QWORD *)v11 + 16i64))(v11, v12);
  if ( v7 )
  {
    if ( !LODWORD(v7->EntryCount) && (Scaleform::GFx::Resource *)v7->SizeMask == pres )
    {
      v10 = pres->vfptr->GetKey(pres, &v11);
      Scaleform::HashSetBase<Scaleform::GFx::ResourceWeakLib::ResourceNode,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp,Scaleform::AllocatorGH<Scaleform::GFx::ResourceWeakLib::ResourceNode,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::ResourceWeakLib::ResourceNode,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp>>::RemoveAlt<Scaleform::GFx::ResourceKey>(
        &this->Resources,
        v10);
      if ( v11 )
        (*(void (__fastcall **)(__int64, __int64))(*(_QWORD *)v11 + 16i64))(v11, v12);
    }
  }
  LeaveCriticalSection(&p_ResourceLock->cs);
}

// File Line: 503
// RVA: 0x89C520
void __fastcall Scaleform::GFx::ResourceFileInfo::ResourceFileInfo(Scaleform::GFx::ResourceFileInfo *this)
{
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountNTSImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountNTSImpl::`vftable;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountNTSImpl,2>::`vftable;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountBaseNTS<Scaleform::GFx::ResourceFileInfo,2>::`vftable;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::GFx::ResourceFileInfo::`vftable;
  Scaleform::String::String(&this->FileName);
  this->Format = File_Unknown;
  this->pExporterInfo = 0i64;
}

// File Line: 509
// RVA: 0x89C490
void __fastcall Scaleform::GFx::ResourceFileInfo::ResourceFileInfo(
        Scaleform::GFx::ResourceFileInfo *this,
        Scaleform::GFx::ResourceFileInfo *src)
{
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountNTSImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountNTSImpl::`vftable;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountNTSImpl,2>::`vftable;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountBaseNTS<Scaleform::GFx::ResourceFileInfo,2>::`vftable;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::GFx::ResourceFileInfo::`vftable;
  Scaleform::String::String(&this->FileName, &src->FileName);
  this->Format = src->Format;
  this->pExporterInfo = src->pExporterInfo;
}

// File Line: 535
// RVA: 0x89C5A0
void __fastcall Scaleform::GFx::ResourceKey::ResourceKey(
        Scaleform::GFx::ResourceKey *this,
        Scaleform::GFx::ResourceKey *src)
{
  if ( src->pKeyInterface )
    src->pKeyInterface->vfptr->AddRef(src->pKeyInterface, src->hKeyData);
  this->pKeyInterface = src->pKeyInterface;
  this->hKeyData = src->hKeyData;
}

