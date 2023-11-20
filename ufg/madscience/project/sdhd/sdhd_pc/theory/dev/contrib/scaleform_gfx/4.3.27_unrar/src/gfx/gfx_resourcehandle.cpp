// File Line: 34
// RVA: 0x8A7370
void __fastcall Scaleform::GFx::ResourceBinding::~ResourceBinding(Scaleform::GFx::ResourceBinding *this)
{
  Scaleform::GFx::ResourceBinding *v1; // rbx

  v1 = this;
  Scaleform::GFx::ResourceBinding::Destroy(this);
  Scaleform::Lock::~Lock(&v1->ResourceLock.cs);
}

// File Line: 39
// RVA: 0x8C6DD0
void __fastcall Scaleform::GFx::ResourceBinding::Destroy(Scaleform::GFx::ResourceBinding *this)
{
  Scaleform::GFx::ResourceBinding *v1; // rbp
  volatile unsigned int v2; // eax
  __int64 v3; // rsi
  Scaleform::GFx::ResourceBindData *volatile v4; // rdi
  Scaleform::GFx::Resource *v5; // rbx
  Scaleform::GFx::ResourceLibBase *v6; // rcx

  v1 = this;
  if ( this->pResources )
  {
    v2 = this->ResourceCount;
    v3 = v2;
    v4 = this->pResources;
    if ( v2 )
    {
      do
      {
        v5 = v4->pResource.pObject;
        if ( v4->pResource.pObject && !_InterlockedDecrement(&v5->RefCount.Value) )
        {
          v6 = v5->pLib;
          if ( v6 )
          {
            v6->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v6->vfptr, (unsigned int)v5);
            v5->pLib = 0i64;
          }
          v5->vfptr->__vecDelDtor(v5, 1u);
        }
        ++v4;
        --v3;
      }
      while ( v3 );
    }
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v1->pResources);
    v1->pResources = 0i64;
  }
}

// File Line: 53
// RVA: 0x906430
void __fastcall Scaleform::GFx::ResourceBinding::SetBindData(Scaleform::GFx::ResourceBinding *this, unsigned int index, Scaleform::GFx::ResourceBindData *bd)
{
  Scaleform::GFx::ResourceBindData *v3; // r13
  unsigned int v4; // er12
  Scaleform::GFx::ResourceBinding *v5; // r14
  unsigned int v6; // er12
  Scaleform::MemoryHeap *v7; // rcx
  __int64 v8; // rdi
  signed __int64 v9; // rdx
  Scaleform::MemoryHeapVtbl *v10; // rax
  Scaleform::GFx::ResourceBindData *volatile v11; // rax
  __int64 v12; // r15
  _QWORD *v13; // rcx
  volatile unsigned int v14; // edi
  volatile unsigned int v15; // eax
  __int64 v16; // rbp
  Scaleform::GFx::ResourceBindData *volatile v17; // rsi
  Scaleform::GFx::Resource *v18; // rdi
  Scaleform::GFx::ResourceLibBase *v19; // rcx
  Scaleform::GFx::ResourceBindData *v20; // rsi
  Scaleform::GFx::Resource *v21; // rdi
  Scaleform::GFx::ResourceLibBase *v22; // rcx
  unsigned int v23; // [rsp+88h] [rbp+10h]
  _RTL_CRITICAL_SECTION *v24; // [rsp+90h] [rbp+18h]

  v23 = index;
  v3 = bd;
  v4 = index;
  v5 = this;
  v24 = &this->ResourceLock.cs;
  EnterCriticalSection(&this->ResourceLock.cs);
  v6 = (v4 + 16) & 0xFFFFFFF0;
  if ( v6 > v5->ResourceCount )
  {
    v7 = v5->pHeap;
    v8 = v6;
    v9 = 16i64 * v6;
    v10 = v5->pHeap->vfptr;
    if ( v5->pResources )
    {
      v12 = (__int64)v10->Alloc(v7, v9, 0i64);
      v13 = (_QWORD *)v12;
      if ( v6 )
      {
        do
        {
          if ( v13 )
          {
            *v13 = 0i64;
            v13[1] = 0i64;
          }
          v13 += 2;
          --v8;
        }
        while ( v8 );
      }
      v14 = 0;
      if ( v5->ResourceCount )
      {
        do
        {
          Scaleform::GFx::ResourceBindData::operator=(
            (Scaleform::GFx::ResourceBindData *)(16i64 * v14 + v12),
            &v5->pResources[v14]);
          ++v14;
        }
        while ( v14 < v5->ResourceCount );
      }
      v15 = v5->ResourceCount;
      v16 = v15;
      v17 = v5->pResources;
      if ( v15 )
      {
        do
        {
          v18 = v17->pResource.pObject;
          if ( v17->pResource.pObject && !_InterlockedDecrement(&v18->RefCount.Value) )
          {
            v19 = v18->pLib;
            if ( v19 )
            {
              v19->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v19->vfptr, (unsigned int)v18);
              v18->pLib = 0i64;
            }
            v18->vfptr->__vecDelDtor(v18, 1u);
          }
          ++v17;
          --v16;
        }
        while ( v16 );
      }
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v5->pResources);
      v5->pResources = (Scaleform::GFx::ResourceBindData *volatile )v12;
    }
    else
    {
      v5->pResources = (Scaleform::GFx::ResourceBindData *volatile )v10->Alloc(v7, v9, 0i64);
      v11 = v5->pResources;
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
    v5->ResourceCount = v6;
  }
  v20 = &v5->pResources[v23];
  if ( v3->pResource.pObject )
    _InterlockedExchangeAdd(&v3->pResource.pObject->RefCount.Value, 1u);
  v21 = v20->pResource.pObject;
  if ( v20->pResource.pObject && !_InterlockedDecrement(&v21->RefCount.Value) )
  {
    v22 = v21->pLib;
    if ( v22 )
    {
      v22->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v22->vfptr, (unsigned int)v21);
      v21->pLib = 0i64;
    }
    v21->vfptr->__vecDelDtor(v21, 1u);
  }
  v20->pResource.pObject = v3->pResource.pObject;
  v20->pBinding = v3->pBinding;
  LeaveCriticalSection(v24);
}

// File Line: 97
// RVA: 0x8DDA20
void __fastcall Scaleform::GFx::ResourceBinding::GetResourceData_Locked(Scaleform::GFx::ResourceBinding *this, Scaleform::GFx::ResourceBindData *pdata, unsigned int index)
{
  unsigned int v3; // edi
  Scaleform::GFx::ResourceBindData *v4; // rsi
  Scaleform::GFx::ResourceBinding *v5; // rbx
  Scaleform::GFx::ResourceBindData *v6; // rdx
  Scaleform::GFx::ResourceBindData *v7; // rdx
  char v8; // di
  Scaleform::GFx::Resource *v9; // rdi
  Scaleform::GFx::ResourceLibBase *v10; // rcx
  __int64 v11; // rbx
  Scaleform::GFx::ResourceLibBase *v12; // rcx
  char v13; // [rsp+20h] [rbp-38h]
  Scaleform::GFx::Resource *v14; // [rsp+30h] [rbp-28h]
  Scaleform::GFx::ResourceBinding *v15; // [rsp+38h] [rbp-20h]
  Scaleform::GFx::ResourceBindData src; // [rsp+40h] [rbp-18h]
  _RTL_CRITICAL_SECTION *v17; // [rsp+60h] [rbp+8h]

  v3 = index;
  v4 = pdata;
  v5 = this;
  v17 = &this->ResourceLock.cs;
  EnterCriticalSection(&this->ResourceLock.cs);
  if ( v3 >= v5->ResourceCount )
  {
    src.pResource.pObject = 0i64;
    src.pBinding = 0i64;
    v7 = &src;
    v8 = 2;
  }
  else
  {
    v6 = &v5->pResources[v3];
    v14 = 0i64;
    if ( v6->pResource.pObject )
      _InterlockedExchangeAdd(&v6->pResource.pObject->RefCount.Value, 1u);
    v14 = v6->pResource.pObject;
    v15 = v6->pBinding;
    v7 = (Scaleform::GFx::ResourceBindData *)&v14;
    v8 = 1;
  }
  Scaleform::GFx::ResourceBindData::operator=(v4, v7);
  if ( v8 & 2 )
  {
    v8 &= 0xFDu;
    v13 = v8;
    if ( src.pResource.pObject )
    {
      if ( !_InterlockedDecrement(&src.pResource.pObject->RefCount.Value) )
      {
        v9 = src.pResource.pObject;
        v10 = src.pResource.pObject->pLib;
        if ( v10 )
        {
          v10->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v10->vfptr, (unsigned int)src.pResource.pObject);
          v9->pLib = 0i64;
        }
        v9->vfptr->__vecDelDtor(v9, 1u);
      }
      v8 = v13;
    }
  }
  if ( v8 & 1 && v14 && !_InterlockedDecrement(&v14->RefCount.Value) )
  {
    v11 = (__int64)v14;
    v12 = v14->pLib;
    if ( v12 )
    {
      v12->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v12->vfptr, (unsigned int)v14);
      *(_QWORD *)(v11 + 16) = 0i64;
    }
    (**(void (__fastcall ***)(__int64, signed __int64))v11)(v11, 1i64);
  }
  LeaveCriticalSection(v17);
}

