// File Line: 34
// RVA: 0x8A7370
void __fastcall Scaleform::GFx::ResourceBinding::~ResourceBinding(Scaleform::GFx::ResourceBinding *this)
{
  Scaleform::GFx::ResourceBinding::Destroy(this);
  Scaleform::Lock::~Lock(&this->ResourceLock.cs);
}

// File Line: 39
// RVA: 0x8C6DD0
void __fastcall Scaleform::GFx::ResourceBinding::Destroy(Scaleform::GFx::ResourceBinding *this)
{
  volatile unsigned int ResourceCount; // eax
  __int64 v3; // rsi
  Scaleform::GFx::ResourceBindData *volatile pResources; // rdi
  Scaleform::GFx::Resource *pObject; // rbx
  Scaleform::GFx::ResourceLibBase *pLib; // rcx

  if ( this->pResources )
  {
    ResourceCount = this->ResourceCount;
    v3 = ResourceCount;
    pResources = this->pResources;
    if ( ResourceCount )
    {
      do
      {
        pObject = pResources->pResource.pObject;
        if ( pResources->pResource.pObject && !_InterlockedDecrement(&pObject->RefCount.Value) )
        {
          pLib = pObject->pLib;
          if ( pLib )
          {
            pLib->vfptr[1].__vecDelDtor(pLib, (unsigned int)pObject);
            pObject->pLib = 0i64;
          }
          pObject->vfptr->__vecDelDtor(pObject, 1u);
        }
        ++pResources;
        --v3;
      }
      while ( v3 );
    }
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, this->pResources);
    this->pResources = 0i64;
  }
}

// File Line: 53
// RVA: 0x906430
void __fastcall Scaleform::GFx::ResourceBinding::SetBindData(
        Scaleform::GFx::ResourceBinding *this,
        unsigned int index,
        Scaleform::GFx::ResourceBindData *bd)
{
  unsigned int v6; // r12d
  Scaleform::MemoryHeap *pHeap; // rcx
  __int64 v8; // rdi
  __int64 v9; // rdx
  Scaleform::MemoryHeapVtbl *vfptr; // rax
  Scaleform::GFx::ResourceBindData *volatile v11; // rax
  Scaleform::GFx::ResourceBindData *v12; // r15
  Scaleform::GFx::ResourceBindData *v13; // rcx
  volatile unsigned int i; // edi
  volatile unsigned int ResourceCount; // eax
  __int64 v16; // rbp
  Scaleform::GFx::ResourceBindData *volatile pResources; // rsi
  Scaleform::GFx::Resource *pObject; // rdi
  Scaleform::GFx::ResourceLibBase *pLib; // rcx
  Scaleform::GFx::ResourceBindData *v20; // rsi
  Scaleform::GFx::Resource *v21; // rdi
  Scaleform::GFx::ResourceLibBase *v22; // rcx
  Scaleform::Lock *p_ResourceLock; // [rsp+90h] [rbp+18h]

  p_ResourceLock = &this->ResourceLock;
  EnterCriticalSection(&this->ResourceLock.cs);
  v6 = (index + 16) & 0xFFFFFFF0;
  if ( v6 > this->ResourceCount )
  {
    pHeap = this->pHeap;
    v8 = v6;
    v9 = 16i64 * v6;
    vfptr = this->pHeap->vfptr;
    if ( this->pResources )
    {
      v12 = (Scaleform::GFx::ResourceBindData *)vfptr->Alloc(pHeap, v9, 0i64);
      v13 = v12;
      if ( v6 )
      {
        do
        {
          if ( v13 )
          {
            v13->pResource.pObject = 0i64;
            v13->pBinding = 0i64;
          }
          ++v13;
          --v8;
        }
        while ( v8 );
      }
      for ( i = 0; i < this->ResourceCount; ++i )
        Scaleform::GFx::ResourceBindData::operator=(&v12[i], &this->pResources[i]);
      ResourceCount = this->ResourceCount;
      v16 = ResourceCount;
      pResources = this->pResources;
      if ( ResourceCount )
      {
        do
        {
          pObject = pResources->pResource.pObject;
          if ( pResources->pResource.pObject && !_InterlockedDecrement(&pObject->RefCount.Value) )
          {
            pLib = pObject->pLib;
            if ( pLib )
            {
              pLib->vfptr[1].__vecDelDtor(pLib, (unsigned int)pObject);
              pObject->pLib = 0i64;
            }
            pObject->vfptr->__vecDelDtor(pObject, 1u);
          }
          ++pResources;
          --v16;
        }
        while ( v16 );
      }
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, this->pResources);
      this->pResources = v12;
    }
    else
    {
      this->pResources = (Scaleform::GFx::ResourceBindData *volatile)vfptr->Alloc(pHeap, v9, 0i64);
      v11 = this->pResources;
      if ( v6 )
      {
        do
        {
          if ( v11 )
          {
            v11->pResource.pObject = 0i64;
            v11->pBinding = 0i64;
          }
          ++v11;
          --v8;
        }
        while ( v8 );
      }
    }
    this->ResourceCount = v6;
  }
  v20 = &this->pResources[index];
  if ( bd->pResource.pObject )
    _InterlockedExchangeAdd(&bd->pResource.pObject->RefCount.Value, 1u);
  v21 = v20->pResource.pObject;
  if ( v20->pResource.pObject && !_InterlockedDecrement(&v21->RefCount.Value) )
  {
    v22 = v21->pLib;
    if ( v22 )
    {
      v22->vfptr[1].__vecDelDtor(v22, (unsigned int)v21);
      v21->pLib = 0i64;
    }
    v21->vfptr->__vecDelDtor(v21, 1u);
  }
  v20->pResource.pObject = bd->pResource.pObject;
  v20->pBinding = bd->pBinding;
  LeaveCriticalSection(&p_ResourceLock->cs);
}

// File Line: 97
// RVA: 0x8DDA20
void __fastcall Scaleform::GFx::ResourceBinding::GetResourceData_Locked(
        Scaleform::GFx::ResourceBinding *this,
        Scaleform::GFx::ResourceBindData *pdata,
        volatile unsigned int index)
{
  Scaleform::GFx::ResourceBindData *v6; // rdx
  Scaleform::GFx::ResourceBindData *p_src; // rdx
  char v8; // di
  Scaleform::GFx::Resource *pObject; // rdi
  Scaleform::GFx::ResourceLibBase *pLib; // rcx
  __int64 v11; // rbx
  __int64 v12; // rcx
  char v13; // [rsp+20h] [rbp-38h]
  __int64 v14[2]; // [rsp+30h] [rbp-28h] BYREF
  Scaleform::GFx::ResourceBindData src; // [rsp+40h] [rbp-18h] BYREF
  Scaleform::Lock *p_ResourceLock; // [rsp+60h] [rbp+8h]

  p_ResourceLock = &this->ResourceLock;
  EnterCriticalSection(&this->ResourceLock.cs);
  if ( index >= this->ResourceCount )
  {
    src.pResource.pObject = 0i64;
    src.pBinding = 0i64;
    p_src = &src;
    v8 = 2;
  }
  else
  {
    v6 = &this->pResources[index];
    v14[0] = 0i64;
    if ( v6->pResource.pObject )
      _InterlockedExchangeAdd(&v6->pResource.pObject->RefCount.Value, 1u);
    v14[0] = (__int64)v6->pResource.pObject;
    v14[1] = (__int64)v6->pBinding;
    p_src = (Scaleform::GFx::ResourceBindData *)v14;
    v8 = 1;
  }
  Scaleform::GFx::ResourceBindData::operator=(pdata, p_src);
  if ( (v8 & 2) != 0 )
  {
    v8 &= ~2u;
    v13 = v8;
    if ( src.pResource.pObject )
    {
      if ( !_InterlockedDecrement(&src.pResource.pObject->RefCount.Value) )
      {
        pObject = src.pResource.pObject;
        pLib = src.pResource.pObject->pLib;
        if ( pLib )
        {
          pLib->vfptr[1].__vecDelDtor(pLib, (unsigned int)src.pResource.pObject);
          pObject->pLib = 0i64;
        }
        pObject->vfptr->__vecDelDtor(pObject, 1u);
      }
      v8 = v13;
    }
  }
  if ( (v8 & 1) != 0 && v14[0] && !_InterlockedDecrement((volatile signed __int32 *)(v14[0] + 8)) )
  {
    v11 = v14[0];
    v12 = *(_QWORD *)(v14[0] + 16);
    if ( v12 )
    {
      (*(void (__fastcall **)(__int64, __int64))(*(_QWORD *)v12 + 8i64))(v12, v14[0]);
      *(_QWORD *)(v11 + 16) = 0i64;
    }
    (**(void (__fastcall ***)(__int64, __int64))v11)(v11, 1i64);
  }
  LeaveCriticalSection(&p_ResourceLock->cs);
}

