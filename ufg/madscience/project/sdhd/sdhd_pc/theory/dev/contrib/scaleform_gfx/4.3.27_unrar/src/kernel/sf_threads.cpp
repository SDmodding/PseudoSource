// File Line: 32
// RVA: 0x9470F0
void __fastcall Scaleform::Waitable::Waitable(Scaleform::Waitable *this, bool enable)
{
  Scaleform::Waitable *v2; // rbx
  Scaleform::Waitable::HandlerArray *v3; // rax

  v2 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::Waitable,2>::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Waitable::`vftable';
  if ( enable )
  {
    v3 = (Scaleform::Waitable::HandlerArray *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                                Scaleform::Memory::pGlobalHeap,
                                                72i64);
    if ( v3 )
      Scaleform::Waitable::HandlerArray::HandlerArray(v3);
  }
  else
  {
    v3 = 0i64;
  }
  v2->pHandlers = v3;
}

// File Line: 41
// RVA: 0x94DB70
void __fastcall Scaleform::Waitable::~Waitable(Scaleform::Waitable *this)
{
  Scaleform::Waitable *v1; // rbx
  Scaleform::Waitable::HandlerArray *v2; // rcx

  v1 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Waitable::`vftable';
  v2 = this->pHandlers;
  if ( v2 )
    Scaleform::Waitable::HandlerArray::Release(v2);
  v1->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable';
}

// File Line: 47
// RVA: 0x9551C0
bool __fastcall Scaleform::Waitable::AddWaitHandler(Scaleform::Waitable *this, void (__fastcall *handler)(void *), void *pdata)
{
  void *v3; // rbp
  void (__fastcall *v4)(void *); // r14
  Scaleform::Waitable *v5; // rdi
  Scaleform::Waitable::HandlerArray *v6; // rax
  _RTL_CRITICAL_SECTION *v7; // rsi
  Scaleform::ArrayDataBase<Scaleform::Waitable::HandlerStruct,Scaleform::AllocatorGH<Scaleform::Waitable::HandlerStruct,2>,Scaleform::ArrayConstPolicy<0,16,1> > *v8; // rdi
  unsigned __int64 v9; // rbx
  unsigned __int64 v10; // r8
  Scaleform::Waitable::HandlerStruct *v11; // rdx

  v3 = pdata;
  v4 = handler;
  v5 = this;
  v6 = this->pHandlers;
  if ( !v6 )
    return (char)v6;
  v7 = &v6->HandlersLock.cs;
  EnterCriticalSection(&v6->HandlersLock.cs);
  v8 = (Scaleform::ArrayDataBase<Scaleform::Waitable::HandlerStruct,Scaleform::AllocatorGH<Scaleform::Waitable::HandlerStruct,2>,Scaleform::ArrayConstPolicy<0,16,1> > *)&v5->pHandlers->Handlers.Data.Data;
  v9 = v8->Size + 1;
  if ( v9 >= v8->Size )
  {
    if ( v9 > v8->Policy.Capacity )
    {
      v10 = v9 + (v9 >> 2);
      goto LABEL_7;
    }
  }
  else if ( v9 < v8->Policy.Capacity >> 1 )
  {
    v10 = v8->Size + 1;
LABEL_7:
    Scaleform::ArrayDataBase<Scaleform::Waitable::HandlerStruct,Scaleform::AllocatorGH<Scaleform::Waitable::HandlerStruct,2>,Scaleform::ArrayConstPolicy<0,16,1>>::Reserve(
      v8,
      v8,
      v10);
    goto LABEL_8;
  }
LABEL_8:
  v8->Size = v9;
  v11 = &v8->Data[v9 - 1];
  if ( v11 )
  {
    v11->Handler = v4;
    v11->pUserData = v3;
  }
  LeaveCriticalSection(v7);
  LOBYTE(v6) = 1;
  return (char)v6;
}

// File Line: 68
// RVA: 0x9AA710
Scaleform::Waitable::HandlerArray *__fastcall Scaleform::Waitable::RemoveWaitHandler(Scaleform::Waitable *this, void (__fastcall *handler)(void *), void *pdata)
{
  void (__fastcall *v3)(void *); // rbx
  void (__fastcall *v4)(void *); // rsi
  Scaleform::Waitable *v5; // rdi
  Scaleform::Waitable::HandlerArray *result; // rax
  unsigned __int8 v7; // bp
  _RTL_CRITICAL_SECTION *v8; // r14
  unsigned int v9; // ecx
  Scaleform::Waitable::HandlerArray *v10; // rdi
  unsigned __int64 v11; // rdx
  __int64 v12; // rax
  void (__fastcall **v13)(void *); // rax
  unsigned __int64 v14; // r8
  signed __int64 v15; // r8
  signed __int64 v16; // rcx

  v3 = (void (__fastcall *)(void *))pdata;
  v4 = handler;
  v5 = this;
  result = this->pHandlers;
  if ( result )
  {
    v7 = 0;
    v8 = &result->HandlersLock.cs;
    EnterCriticalSection(&result->HandlersLock.cs);
    v9 = 0;
    v10 = v5->pHandlers;
    v11 = v10->Handlers.Data.Size;
    if ( v11 )
    {
      v12 = 0i64;
      while ( 1 )
      {
        v13 = &v10->Handlers.Data.Data[v12].Handler;
        if ( *v13 == v4 && v13[1] == v3 )
          break;
        v12 = ++v9;
        if ( v9 >= v11 )
          goto LABEL_12;
      }
      v14 = v10->Handlers.Data.Size;
      if ( v14 == 1 )
      {
        Scaleform::ArrayData<Scaleform::Waitable::HandlerStruct,Scaleform::AllocatorGH<Scaleform::Waitable::HandlerStruct,2>,Scaleform::ArrayConstPolicy<0,16,1>>::Resize(
          &v10->Handlers.Data,
          0i64);
      }
      else
      {
        v15 = v14 - v9 - 1;
        v16 = (signed __int64)&v10->Handlers.Data.Data[v9];
        memmove((void *)v16, (const void *)(v16 + 16), 16 * v15);
        --v10->Handlers.Data.Size;
      }
      v7 = 1;
    }
LABEL_12:
    LeaveCriticalSection(v8);
    result = (Scaleform::Waitable::HandlerArray *)v7;
  }
  return result;
}

// File Line: 89
// RVA: 0x9A78D0
void __fastcall Scaleform::Waitable::HandlerArray::Release(Scaleform::Waitable::HandlerArray *this)
{
  Scaleform::Waitable::HandlerArray *v1; // rbx

  v1 = this;
  if ( !_InterlockedDecrement(&this->RefCount.Value) && this )
  {
    DeleteCriticalSection(&this->HandlersLock.cs);
    if ( v1->Handlers.Data.Data )
      ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v1);
  }
}

// File Line: 95
// RVA: 0x95DA20
void __fastcall Scaleform::Waitable::HandlerArray::CallWaitHandlers(Scaleform::Waitable::HandlerArray *this)
{
  Scaleform::Waitable::HandlerArray *v1; // rsi
  _RTL_CRITICAL_SECTION *v2; // rbx
  unsigned __int64 v3; // rax
  unsigned __int64 v4; // rdi
  __int64 v5; // rsi
  Scaleform::ArrayData<Scaleform::Waitable::HandlerStruct,Scaleform::AllocatorGH<Scaleform::Waitable::HandlerStruct,2>,Scaleform::ArrayConstPolicy<0,16,1> > v6; // [rsp+28h] [rbp-20h]

  v1 = this;
  v2 = &this->HandlersLock.cs;
  EnterCriticalSection(&this->HandlersLock.cs);
  v3 = v1->Handlers.Data.Size;
  if ( v3 )
  {
    if ( v3 == 1 )
    {
      v1->Handlers.Data.Data->Handler(v1->Handlers.Data.Data->pUserData);
    }
    else
    {
      v4 = 0i64;
      v6.Data = 0i64;
      *(_OWORD *)&v6.Size = 0ui64;
      Scaleform::ArrayData<Scaleform::Waitable::HandlerStruct,Scaleform::AllocatorGH<Scaleform::Waitable::HandlerStruct,2>,Scaleform::ArrayConstPolicy<0,16,1>>::Append(
        &v6,
        v1->Handlers.Data.Data,
        v1->Handlers.Data.Size);
      if ( v6.Size > 0 )
      {
        v5 = 0i64;
        do
        {
          v6.Data[v5].Handler(v6.Data[v5].pUserData);
          ++v4;
          ++v5;
        }
        while ( v4 < v6.Size );
      }
      if ( v6.Data )
        ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
    }
  }
  LeaveCriticalSection(v2);
}

// File Line: 120
// RVA: 0x95DB10
void __fastcall Scaleform::Waitable::CallWaitHandlers(void *hdata)
{
  JUMPOUT(*((_QWORD *)hdata + 2), 0i64, Scaleform::Waitable::HandlerArray::CallWaitHandlers);
}

// File Line: 127
// RVA: 0x952D30
bool __fastcall Scaleform::Waitable::Acquire(Scaleform::Waitable *this, unsigned int delay)
{
  unsigned int v2; // er13
  unsigned int v3; // esi
  Scaleform::Waitable **v4; // rbx
  __int64 v5; // rdi
  Scaleform::Waitable **v6; // rcx
  unsigned int v7; // esi
  Scaleform::Waitable *v8; // rdi
  Scaleform::Waitable::HandlerArray *v9; // rax
  _RTL_CRITICAL_SECTION *v10; // r14
  Scaleform::ArrayDataBase<Scaleform::Waitable::HandlerStruct,Scaleform::AllocatorGH<Scaleform::Waitable::HandlerStruct,2>,Scaleform::ArrayConstPolicy<0,16,1> > *v11; // rdi
  unsigned __int64 v12; // rbx
  unsigned __int64 v13; // r8
  signed __int64 v14; // rbx
  signed __int64 v15; // rdx
  bool v16; // zf
  _QWORD *v17; // rdx
  Scaleform::Waitable **v18; // rbx
  __int64 v19; // rdi
  unsigned int v20; // er15
  unsigned int v21; // ebx
  Scaleform::Waitable **v22; // rdi
  __int64 v23; // r14
  Scaleform::Waitable **v24; // rdi
  __int64 v25; // r14
  __int64 v26; // rdx
  unsigned int v27; // edx
  signed __int64 v28; // rdi
  Scaleform::Waitable *v29; // rbx
  Scaleform::Waitable::HandlerArray *v30; // rax
  _RTL_CRITICAL_SECTION *v31; // r14
  unsigned int v32; // ecx
  Scaleform::Waitable::HandlerArray *v33; // rbx
  unsigned __int64 v34; // rdx
  Scaleform::Waitable::HandlerStruct *v35; // r8
  __int64 v36; // rax
  signed __int64 v37; // rax
  unsigned __int64 v38; // r8
  unsigned __int64 v39; // rax
  signed __int64 v40; // r8
  signed __int64 v41; // rcx
  Scaleform::AcquireInterface_AcquireDesc v43; // [rsp+20h] [rbp-79h]
  Scaleform::Event v44; // [rsp+40h] [rbp-59h]
  Scaleform::Lock *v45; // [rsp+A0h] [rbp+7h]
  _QWORD *v46; // [rsp+A8h] [rbp+Fh]
  __int64 v47; // [rsp+B0h] [rbp+17h]
  unsigned int v48; // [rsp+100h] [rbp+67h]
  Scaleform::Waitable *v49; // [rsp+110h] [rbp+77h]
  _QWORD *v50; // [rsp+118h] [rbp+7Fh]

  v47 = -2i64;
  v2 = delay;
  v49 = this;
  v3 = 0;
  v4 = &v49;
  while ( 1 )
  {
    v5 = ((__int64 (*)(void))(*v4)->vfptr[2].__vecDelDtor)();
    if ( (*(unsigned __int8 (__fastcall **)(__int64))(*(_QWORD *)v5 + 16i64))(v5) )
      break;
    ++v3;
    ++v4;
    if ( v3 >= 1 )
      goto LABEL_6;
  }
  (*(void (__fastcall **)(__int64))(*(_QWORD *)v5 + 24i64))(v5);
  if ( v3 != -1 )
    return v3 == 0;
LABEL_6:
  if ( !v2 )
  {
    v3 = -1;
    return v3 == 0;
  }
  v44.RefCount = 1;
  v44.pHandlers = 0i64;
  v44.vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Event::`vftable'{for `Scaleform::Waitable'};
  v44.vfptr = (Scaleform::AcquireInterfaceVtbl *)&Scaleform::Event::`vftable'{for `Scaleform::AcquireInterface'};
  Scaleform::Mutex::Mutex(&v44.StateMutex, 1, 0);
  Scaleform::WaitCondition::WaitCondition(&v44.StateWaitCondition);
  v44.State = 0;
  v44.Temporary = 0;
  v6 = &v49;
  v43.pWaitList = &v49;
  v43.WaitCount = 1;
  v43.pEvent = &v44;
  v43.pAcquireList = 0i64;
  v7 = 0;
  while ( 1 )
  {
    v8 = v6[v7];
    v9 = v8->pHandlers;
    if ( !v9 )
      break;
    v10 = &v9->HandlersLock.cs;
    EnterCriticalSection(&v9->HandlersLock.cs);
    v11 = (Scaleform::ArrayDataBase<Scaleform::Waitable::HandlerStruct,Scaleform::AllocatorGH<Scaleform::Waitable::HandlerStruct,2>,Scaleform::ArrayConstPolicy<0,16,1> > *)&v8->pHandlers->Handlers.Data.Data;
    v12 = v11->Size + 1;
    if ( v12 >= v11->Size )
    {
      if ( v12 <= v11->Policy.Capacity )
        goto LABEL_16;
      v13 = v12 + (v12 >> 2);
    }
    else
    {
      if ( v12 >= v11->Policy.Capacity >> 1 )
        goto LABEL_16;
      v13 = v11->Size + 1;
    }
    Scaleform::ArrayDataBase<Scaleform::Waitable::HandlerStruct,Scaleform::AllocatorGH<Scaleform::Waitable::HandlerStruct,2>,Scaleform::ArrayConstPolicy<0,16,1>>::Reserve(
      v11,
      v11,
      v13);
LABEL_16:
    v11->Size = v12;
    v14 = 16 * v12;
    v15 = (signed __int64)&v11->Data[-1];
    v16 = v14 + v15 == 0;
    v17 = (_QWORD *)(v14 + v15);
    v50 = v17;
    v46 = v17;
    if ( !v16 )
    {
      *v17 = Scaleform::AcquireInterface_OneOfMultipleWaitHandler;
      v17[1] = &v43;
    }
    LeaveCriticalSection(v10);
    if ( ++v7 >= v43.WaitCount )
    {
      v3 = 0;
      v18 = &v49;
      while ( 1 )
      {
        v19 = ((__int64 (*)(void))(*v18)->vfptr[2].__vecDelDtor)();
        if ( (*(unsigned __int8 (__fastcall **)(__int64))(*(_QWORD *)v19 + 16i64))(v19) )
          break;
        ++v3;
        ++v18;
        if ( v3 >= 1 )
          goto LABEL_26;
      }
      (*(void (__fastcall **)(__int64))(*(_QWORD *)v19 + 24i64))(v19);
      if ( v3 != -1 )
      {
        Scaleform::AcquireInterface_AcquireDesc::RemoveHandlers(
          &v43,
          Scaleform::AcquireInterface_OneOfMultipleWaitHandler);
        Scaleform::Event::~Event(&v44);
        return v3 == 0;
      }
LABEL_26:
      v48 = 0;
      v20 = v2;
      if ( v2 != -1 )
        v48 = Scaleform::Timer::GetTicksMs();
      v21 = 0;
      v22 = &v49;
      while ( 1 )
      {
        v23 = ((__int64 (*)(void))(*v22)->vfptr[2].__vecDelDtor)();
        if ( (*(unsigned __int8 (__fastcall **)(__int64))(*(_QWORD *)v23 + 16i64))(v23) )
          break;
        ++v21;
        ++v22;
        if ( v21 >= 1 )
        {
          v21 = -1;
          goto LABEL_33;
        }
      }
      (*(void (__fastcall **)(__int64))(*(_QWORD *)v23 + 24i64))(v23);
      if ( v21 != -1 )
        goto LABEL_45;
LABEL_33:
      if ( Scaleform::Event::Wait(&v44, v2) )
      {
        do
        {
          v21 = 0;
          v24 = &v49;
          while ( 1 )
          {
            v25 = ((__int64 (*)(void))(*v24)->vfptr[2].__vecDelDtor)();
            if ( (*(unsigned __int8 (__fastcall **)(__int64))(*(_QWORD *)v25 + 16i64))(v25) )
              break;
            ++v21;
            ++v24;
            if ( v21 >= 1 )
            {
              v21 = -1;
              goto LABEL_39;
            }
          }
          (*(void (__fastcall **)(__int64))(*(_QWORD *)v25 + 24i64))(v25);
          if ( v21 != -1 )
            break;
LABEL_39:
          if ( v2 != -1 )
          {
            v26 = timeGetTime();
            if ( TimerOverrideInstance )
              LODWORD(v26) = TimerOverrideInstance->vfptr->GetTicksMs(TimerOverrideInstance, v26);
            v27 = v26 - v48;
            if ( v27 >= v2 )
              break;
            v20 = v2 - v27;
          }
        }
        while ( Scaleform::Event::Wait(&v44, v20) );
      }
LABEL_45:
      Scaleform::AcquireInterface_AcquireDesc::RemoveHandlers(
        &v43,
        Scaleform::AcquireInterface_OneOfMultipleWaitHandler);
      Scaleform::Event::~Event(&v44);
      v3 = v21;
      return v3 == 0;
    }
    v6 = v43.pWaitList;
  }
  if ( v7 )
  {
    v28 = v7;
    do
    {
      --v7;
      --v28;
      v29 = v6[v28];
      v30 = v29->pHandlers;
      if ( v30 )
      {
        v31 = &v30->HandlersLock.cs;
        v45 = &v30->HandlersLock;
        EnterCriticalSection(&v30->HandlersLock.cs);
        v32 = 0;
        v33 = v29->pHandlers;
        v34 = v33->Handlers.Data.Size;
        if ( v34 )
        {
          v35 = v33->Handlers.Data.Data;
          v36 = 0i64;
          while ( 1 )
          {
            v37 = v36;
            if ( v35[v37].Handler == Scaleform::AcquireInterface_OneOfMultipleWaitHandler && v35[v37].pUserData == &v43 )
              break;
            v36 = ++v32;
            if ( v32 >= v34 )
              goto LABEL_63;
          }
          v38 = v33->Handlers.Data.Size;
          if ( v38 == 1 )
          {
            v39 = v33->Handlers.Data.Policy.Capacity;
            if ( v39 & 0xFFFFFFFFFFFFFFFEui64 && !v39 )
            {
              if ( v33->Handlers.Data.Data )
              {
                ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
                v33->Handlers.Data.Data = 0i64;
              }
              v33->Handlers.Data.Policy.Capacity = 0i64;
            }
            v33->Handlers.Data.Size = 0i64;
          }
          else
          {
            v40 = v38 - v32 - 1;
            v41 = (signed __int64)&v33->Handlers.Data.Data[v32];
            memmove((void *)v41, (const void *)(v41 + 16), 16 * v40);
            --v33->Handlers.Data.Size;
          }
        }
LABEL_63:
        LeaveCriticalSection(v31);
        v6 = v43.pWaitList;
      }
    }
    while ( v7 );
  }
  v44.vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Event::`vftable'{for `Scaleform::Waitable'};
  v44.vfptr = (Scaleform::AcquireInterfaceVtbl *)&Scaleform::Event::`vftable'{for `Scaleform::AcquireInterface'};
  Scaleform::WaitCondition::~WaitCondition(&v44.StateWaitCondition);
  Scaleform::Mutex::~Mutex(&v44.StateMutex);
  v44.vfptr = (Scaleform::AcquireInterfaceVtbl *)&Scaleform::AcquireInterface::`vftable';
  v44.vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Waitable::`vftable';
  if ( v44.pHandlers )
    Scaleform::Waitable::HandlerArray::Release(v44.pHandlers);
  v44.vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable';
  v3 = 0;
  return v3 == 0;
}

// File Line: 145
// RVA: 0x9C2700
void __fastcall Scaleform::Waitable_SingleWaitHandler(void *hdata)
{
  Scaleform::Event **v1; // rbx

  v1 = (Scaleform::Event **)hdata;
  if ( (*(unsigned __int8 (**)(void))(**(_QWORD **)hdata + 8i64))() )
    Scaleform::Event::PulseEvent(v1[1]);
}

// File Line: 154
// RVA: 0x9C2410
char __fastcall Scaleform::Waitable::Wait(Scaleform::Waitable *this, unsigned int delay)
{
  unsigned int v2; // ebx
  Scaleform::Waitable *v3; // rsi
  unsigned int v5; // er15
  char v6; // r14
  unsigned int v7; // edi
  __int64 v8; // rdx
  unsigned int v9; // edx
  __int64 pdata; // [rsp+8h] [rbp-41h]
  Scaleform::Event v11; // [rsp+20h] [rbp-29h]

  v2 = delay;
  v3 = this;
  if ( ((unsigned __int8 (*)(void))this->vfptr[1].__vecDelDtor)() )
    return 1;
  if ( !v2 )
    return 0;
  v11.RefCount = 1;
  v5 = 0;
  v11.pHandlers = 0i64;
  v11.vfptr = (Scaleform::AcquireInterfaceVtbl *)&Scaleform::Event::`vftable'{for `Scaleform::AcquireInterface'};
  Scaleform::Mutex::Mutex(&v11.StateMutex, 1, 0);
  Scaleform::WaitCondition::WaitCondition(&v11.StateWaitCondition);
  v11.State = 0;
  v11.Temporary = 0;
  if ( Scaleform::Waitable::AddWaitHandler(v3, Scaleform::Waitable_SingleWaitHandler, &pdata) )
  {
    if ( ((unsigned __int8 (__fastcall *)(Scaleform::Waitable *))v3->vfptr[1].__vecDelDtor)(v3) )
    {
      Scaleform::Waitable::RemoveWaitHandler(v3, Scaleform::Waitable_SingleWaitHandler, &pdata);
      v6 = 1;
    }
    else
    {
      v6 = 0;
      v7 = v2;
      if ( v2 != -1 )
        v5 = Scaleform::Timer::GetTicksMs();
      if ( (unsigned __int8)Scaleform::Event::Wait(&v11, v2) )
      {
        while ( !((unsigned __int8 (__fastcall *)(Scaleform::Waitable *))v3->vfptr[1].__vecDelDtor)(v3) )
        {
          if ( v2 != -1 )
          {
            v8 = timeGetTime();
            if ( TimerOverrideInstance )
              LODWORD(v8) = TimerOverrideInstance->vfptr->GetTicksMs(TimerOverrideInstance, v8);
            v9 = v8 - v5;
            if ( v9 >= v2 )
              goto LABEL_21;
            v7 = v2 - v9;
          }
          if ( !(unsigned __int8)Scaleform::Event::Wait(&v11, v7) )
            goto LABEL_21;
        }
        v6 = 1;
      }
LABEL_21:
      Scaleform::Waitable::RemoveWaitHandler(v3, Scaleform::Waitable_SingleWaitHandler, &pdata);
    }
  }
  else
  {
    v6 = 0;
  }
  v11.vfptr = (Scaleform::AcquireInterfaceVtbl *)&Scaleform::Event::`vftable'{for `Scaleform::AcquireInterface'};
  Scaleform::WaitCondition::~WaitCondition(&v11.StateWaitCondition);
  Scaleform::Mutex::~Mutex(&v11.StateMutex);
  v11.vfptr = (Scaleform::AcquireInterfaceVtbl *)&Scaleform::AcquireInterface::`vftable';
  v11.vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Waitable::`vftable';
  if ( v11.pHandlers )
    Scaleform::Waitable::HandlerArray::Release(v11.pHandlers);
  return v6;
}

// File Line: 215
// RVA: 0x97FC10
Scaleform::DefaultAcquireInterface *__fastcall Scaleform::DefaultAcquireInterface::GetDefaultAcquireInterface()
{
  if ( !(_S2_12 & 1) )
  {
    _S2_12 |= 1u;
    stru_1424523F8.vfptr = (Scaleform::AcquireInterfaceVtbl *)&Scaleform::DefaultAcquireInterface::`vftable';
    atexit(Scaleform::DefaultAcquireInterface::GetDefaultAcquireInterface_::_2_::_dynamic_atexit_destructor_for__di__);
  }
  return &stru_1424523F8;
}

// File Line: 296
// RVA: 0x948CD0
void __fastcall Scaleform::AcquireInterface_AcquireList::~AcquireInterface_AcquireList(Scaleform::AcquireInterface_AcquireList *this)
{
  if ( this->pList != this->StaticList )
    ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
}

// File Line: 321
// RVA: 0x9A9CC0
void __fastcall Scaleform::AcquireInterface_AcquireDesc::RemoveHandlers(Scaleform::AcquireInterface_AcquireDesc *this, void (__fastcall *handler)(void *))
{
  void (__fastcall *v2)(void *); // r14
  Scaleform::AcquireInterface_AcquireDesc *v3; // rbx
  __int64 v4; // rdi
  Scaleform::Waitable *v5; // rsi
  Scaleform::Waitable::HandlerArray *v6; // rax
  _RTL_CRITICAL_SECTION *v7; // rbp
  unsigned int v8; // ecx
  Scaleform::Waitable::HandlerArray *v9; // rsi
  unsigned __int64 v10; // rdx
  __int64 v11; // rax
  Scaleform::Waitable::HandlerStruct *v12; // r8
  signed __int64 v13; // rax
  unsigned __int64 v14; // r8
  signed __int64 v15; // r8
  signed __int64 v16; // rcx

  v2 = handler;
  v3 = this;
  v4 = 0i64;
  if ( this->WaitCount )
  {
    do
    {
      v5 = v3->pWaitList[v4];
      v6 = v5->pHandlers;
      if ( v6 )
      {
        v7 = &v6->HandlersLock.cs;
        EnterCriticalSection(&v6->HandlersLock.cs);
        v8 = 0;
        v9 = v5->pHandlers;
        v10 = v9->Handlers.Data.Size;
        if ( v10 )
        {
          v11 = 0i64;
          v12 = v9->Handlers.Data.Data;
          while ( 1 )
          {
            v13 = v11;
            if ( v12[v13].Handler == v2 && v12[v13].pUserData == v3 )
              break;
            v11 = ++v8;
            if ( v8 >= v10 )
              goto LABEL_12;
          }
          v14 = v9->Handlers.Data.Size;
          if ( v14 == 1 )
          {
            Scaleform::ArrayData<Scaleform::Waitable::HandlerStruct,Scaleform::AllocatorGH<Scaleform::Waitable::HandlerStruct,2>,Scaleform::ArrayConstPolicy<0,16,1>>::Resize(
              &v9->Handlers.Data,
              0i64);
          }
          else
          {
            v15 = v14 - v8 - 1;
            v16 = (signed __int64)&v9->Handlers.Data.Data[v8];
            memmove((void *)v16, (const void *)(v16 + 16), 16 * v15);
            --v9->Handlers.Data.Size;
          }
        }
LABEL_12:
        LeaveCriticalSection(v7);
      }
      v4 = (unsigned int)(v4 + 1);
    }
    while ( (unsigned int)v4 < v3->WaitCount );
  }
}

// File Line: 329
// RVA: 0x9531F0
void __fastcall Scaleform::AcquireInterface_MultipleWaitHandler(void *pdata)
{
  _QWORD *v1; // rsi
  Scaleform::Waitable::HandlerArray *v2; // rbx
  unsigned int v3; // edi
  __int64 v4; // rcx
  __int64 v5; // rdi
  volatile signed __int32 *v6; // rax
  Scaleform::Waitable::HandlerArray *v7; // [rsp+40h] [rbp+8h]

  v1 = pdata;
  v2 = 0i64;
  v3 = 0;
  if ( *((_DWORD *)pdata + 2) )
  {
    while ( 1 )
    {
      v4 = *(_QWORD *)(v1[3] + 8i64 * v3);
      if ( !(*(unsigned __int8 (__cdecl **)(__int64))(*(_QWORD *)v4 + 8i64))(v4) )
        break;
      if ( ++v3 >= *((_DWORD *)v1 + 2) )
        goto LABEL_4;
    }
  }
  else
  {
LABEL_4:
    v5 = v1[2];
    Scaleform::Mutex::DoLock((Scaleform::Mutex *)(v5 + 40));
    *(_BYTE *)(v5 + 32) = 1;
    *(_BYTE *)(v5 + 33) = 1;
    Scaleform::WaitCondition::NotifyAll((Scaleform::WaitCondition *)(v5 + 80));
    v7 = 0i64;
    v6 = *(volatile signed __int32 **)(v5 + 16);
    if ( v6 )
    {
      v2 = *(Scaleform::Waitable::HandlerArray **)(v5 + 16);
      _InterlockedExchangeAdd(v6, 1u);
      v7 = v2;
    }
    Scaleform::Mutex::Unlock((Scaleform::Mutex *)(v5 + 40));
    if ( v2 )
      Scaleform::Waitable::HandlerArray::CallWaitHandlers(v2);
    if ( v2 && !_InterlockedDecrement(&v2->RefCount.Value) )
    {
      DeleteCriticalSection(&v7->HandlersLock.cs);
      if ( v7->Handlers.Data.Data )
        ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v7);
    }
  }
}

// File Line: 341
// RVA: 0x953410
char __fastcall Scaleform::AcquireInterface_TryAcquireAll(Scaleform::AcquireInterface **pacquireList, unsigned int waitCount)
{
  __int64 v2; // rbx
  __int64 v3; // rbp
  Scaleform::AcquireInterface **v4; // rdi
  Scaleform::AcquireInterface **v5; // rsi
  __int64 v6; // rbx
  char result; // al
  signed __int64 v8; // rdi
  __int64 v9; // rcx

  v2 = 0i64;
  v3 = waitCount;
  v4 = pacquireList;
  if ( waitCount )
  {
    v5 = pacquireList;
    do
    {
      if ( !((unsigned __int8 (*)(void))(*v5)->vfptr->TryAcquire)() )
        break;
      v2 = (unsigned int)(v2 + 1);
      ++v5;
    }
    while ( (unsigned int)v2 < (unsigned int)v3 );
  }
  if ( (_DWORD)v2 == (_DWORD)v3 )
  {
    if ( (_DWORD)v3 )
    {
      v6 = v3;
      do
      {
        ((void (*)(void))(*v4)->vfptr->TryAcquireCommit)();
        ++v4;
        --v6;
      }
      while ( v6 );
    }
    result = 1;
  }
  else
  {
    if ( (_DWORD)v2 )
    {
      v8 = (signed __int64)&v4[v2];
      do
      {
        v9 = *(_QWORD *)(v8 - 8);
        v8 -= 8i64;
        (*(void (**)(void))(*(_QWORD *)v9 + 32i64))();
        LODWORD(v2) = v2 - 1;
      }
      while ( (_DWORD)v2 );
    }
    result = 0;
  }
  return result;
}

// File Line: 365
// RVA: 0x953530
__int64 __fastcall Scaleform::AcquireInterface::AcquireMultipleObjects(Scaleform::Waitable **pwaitList, unsigned int waitCount, unsigned int delay)
{
  unsigned int v3; // er14
  __int64 v4; // r12
  Scaleform::Waitable **v5; // rbx
  Scaleform::AcquireInterface **v6; // rax
  unsigned int v7; // er13
  __int64 v8; // rdi
  __int64 v9; // rsi
  unsigned __int8 v10; // di
  Scaleform::AcquireInterface **v11; // rcx
  unsigned int v12; // esi
  Scaleform::Waitable *v13; // rdi
  Scaleform::Waitable::HandlerArray *v14; // rax
  _RTL_CRITICAL_SECTION *v15; // r15
  Scaleform::ArrayDataBase<Scaleform::Waitable::HandlerStruct,Scaleform::AllocatorGH<Scaleform::Waitable::HandlerStruct,2>,Scaleform::ArrayConstPolicy<0,16,1> > *v16; // rdi
  unsigned __int64 v17; // rbx
  unsigned __int64 v18; // r8
  signed __int64 v19; // rbx
  signed __int64 v20; // rdx
  bool v21; // zf
  Scaleform::AcquireInterfaceVtbl *v22; // rdx
  signed __int64 v23; // r14
  Scaleform::Waitable *v24; // rdi
  Scaleform::Waitable::HandlerArray *v25; // rax
  _RTL_CRITICAL_SECTION *v26; // r15
  unsigned int v27; // ecx
  Scaleform::Waitable::HandlerArray *v28; // rbx
  unsigned __int64 v29; // rdx
  Scaleform::Waitable::HandlerStruct *v30; // r8
  __int64 v31; // rax
  signed __int64 v32; // rax
  unsigned __int64 v33; // r8
  unsigned __int64 v34; // rax
  signed __int64 v35; // r8
  signed __int64 v36; // rcx
  unsigned int v37; // ebx
  __int64 v38; // rdx
  unsigned int v39; // edx
  Scaleform::AcquireInterface_AcquireDesc v41; // [rsp+20h] [rbp-B8h]
  Scaleform::Event v42; // [rsp+40h] [rbp-98h]
  Scaleform::AcquireInterface **pacquireList; // [rsp+98h] [rbp-40h]
  char v44; // [rsp+A0h] [rbp-38h]
  Scaleform::Lock *vars0; // [rsp+1F0h] [rbp+118h]

  v42.StateWaitCondition.pImpl = (Scaleform::WaitConditionImpl *)-2i64;
  v3 = delay;
  v4 = waitCount;
  v5 = pwaitList;
  if ( waitCount <= 0x20 )
    v6 = (Scaleform::AcquireInterface **)&v44;
  else
    v6 = (Scaleform::AcquireInterface **)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(
                                           Scaleform::Memory::pGlobalHeap,
                                           8i64 * waitCount,
                                           0i64);
  pacquireList = v6;
  v7 = 0;
  if ( (_DWORD)v4 )
  {
    v8 = 0i64;
    v9 = v4;
    do
    {
      pacquireList[v8] = (Scaleform::AcquireInterface *)((__int64 (*)(void))v5[v8]->vfptr[2].__vecDelDtor)();
      ++v8;
      --v9;
    }
    while ( v9 );
  }
  if ( Scaleform::AcquireInterface_TryAcquireAll(pacquireList, v4) )
  {
    v10 = 1;
    goto LABEL_62;
  }
  if ( !v3 )
  {
    v10 = 0;
    goto LABEL_62;
  }
  v42.RefCount = 1;
  v42.pHandlers = 0i64;
  v42.vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Event::`vftable'{for `Scaleform::Waitable'};
  v42.vfptr = (Scaleform::AcquireInterfaceVtbl *)&Scaleform::Event::`vftable'{for `Scaleform::AcquireInterface'};
  Scaleform::Mutex::Mutex(&v42.StateMutex, 1, 0);
  Scaleform::WaitCondition::WaitCondition((Scaleform::WaitCondition *)&v42.StateMutex);
  v42.State = 0;
  v42.Temporary = 0;
  v41.pWaitList = v5;
  v41.WaitCount = v4;
  v41.pEvent = &v42;
  v11 = pacquireList;
  v41.pAcquireList = pacquireList;
  v12 = 0;
  if ( !(_DWORD)v4 )
  {
LABEL_44:
    if ( Scaleform::AcquireInterface_TryAcquireAll(v11, v4) )
    {
      Scaleform::AcquireInterface_AcquireDesc::RemoveHandlers(&v41, Scaleform::AcquireInterface_MultipleWaitHandler);
      v10 = 1;
    }
    else
    {
      v10 = 0;
      v37 = v3;
      if ( v3 != -1 )
        v7 = Scaleform::Timer::GetTicksMs();
      if ( Scaleform::Event::Wait(&v42, v3) )
      {
        while ( !Scaleform::AcquireInterface_TryAcquireAll(pacquireList, v4) )
        {
          if ( v3 != -1 )
          {
            v38 = timeGetTime();
            if ( TimerOverrideInstance )
              LODWORD(v38) = TimerOverrideInstance->vfptr->GetTicksMs(TimerOverrideInstance, v38);
            v39 = v38 - v7;
            if ( v39 >= v3 )
              goto LABEL_58;
            v37 = v3 - v39;
          }
          if ( !Scaleform::Event::Wait(&v42, v37) )
            goto LABEL_58;
        }
        v10 = 1;
      }
LABEL_58:
      Scaleform::AcquireInterface_AcquireDesc::RemoveHandlers(&v41, Scaleform::AcquireInterface_MultipleWaitHandler);
    }
    goto LABEL_59;
  }
  while ( 1 )
  {
    v13 = v5[v12];
    v14 = v13->pHandlers;
    if ( !v14 )
      break;
    v15 = &v14->HandlersLock.cs;
    vars0 = &v14->HandlersLock;
    EnterCriticalSection(&v14->HandlersLock.cs);
    v16 = (Scaleform::ArrayDataBase<Scaleform::Waitable::HandlerStruct,Scaleform::AllocatorGH<Scaleform::Waitable::HandlerStruct,2>,Scaleform::ArrayConstPolicy<0,16,1> > *)&v13->pHandlers->Handlers.Data.Data;
    v17 = v16->Size + 1;
    if ( v17 >= v16->Size )
    {
      if ( v17 <= v16->Policy.Capacity )
        goto LABEL_19;
      v18 = v17 + (v17 >> 2);
    }
    else
    {
      if ( v17 >= v16->Policy.Capacity >> 1 )
        goto LABEL_19;
      v18 = v16->Size + 1;
    }
    Scaleform::ArrayDataBase<Scaleform::Waitable::HandlerStruct,Scaleform::AllocatorGH<Scaleform::Waitable::HandlerStruct,2>,Scaleform::ArrayConstPolicy<0,16,1>>::Reserve(
      v16,
      v16,
      v18);
LABEL_19:
    v16->Size = v17;
    v19 = 16 * v17;
    v20 = (signed __int64)&v16->Data[-1];
    v21 = v19 + v20 == 0;
    v22 = (Scaleform::AcquireInterfaceVtbl *)(v19 + v20);
    v42.StateMutex.vfptr = v22;
    v42.StateMutex.pImpl = (Scaleform::MutexImpl *)v22;
    if ( !v21 )
    {
      v22->__vecDelDtor = (void *(__fastcall *)(Scaleform::AcquireInterface *, unsigned int))Scaleform::AcquireInterface_MultipleWaitHandler;
      v22->CanAcquire = (bool (__fastcall *)(Scaleform::AcquireInterface *))&v41;
    }
    LeaveCriticalSection(v15);
    if ( ++v12 >= v41.WaitCount )
    {
      v11 = pacquireList;
      goto LABEL_44;
    }
    v5 = v41.pWaitList;
  }
  if ( v12 )
  {
    v23 = v12;
    do
    {
      --v12;
      --v23;
      v24 = v5[v23];
      v25 = v24->pHandlers;
      if ( v25 )
      {
        v26 = &v25->HandlersLock.cs;
        v42.StateMutex.pHandlers = (Scaleform::Waitable::HandlerArray *)((char *)v25 + 32);
        EnterCriticalSection(&v25->HandlersLock.cs);
        v27 = 0;
        v28 = v24->pHandlers;
        v29 = v28->Handlers.Data.Size;
        if ( v29 )
        {
          v30 = v28->Handlers.Data.Data;
          v31 = 0i64;
          while ( 1 )
          {
            v32 = v31;
            if ( v30[v32].Handler == Scaleform::AcquireInterface_MultipleWaitHandler && v30[v32].pUserData == &v41 )
              break;
            v31 = ++v27;
            if ( v27 >= v29 )
              goto LABEL_41;
          }
          v33 = v28->Handlers.Data.Size;
          if ( v33 == 1 )
          {
            v34 = v28->Handlers.Data.Policy.Capacity;
            if ( v34 & 0xFFFFFFFFFFFFFFFEui64 && !v34 )
            {
              if ( v28->Handlers.Data.Data )
              {
                ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
                v28->Handlers.Data.Data = 0i64;
              }
              v28->Handlers.Data.Policy.Capacity = 0i64;
            }
            v28->Handlers.Data.Size = 0i64;
          }
          else
          {
            v35 = v33 - v27 - 1;
            v36 = (signed __int64)&v28->Handlers.Data.Data[v27];
            memmove((void *)v36, (const void *)(v36 + 16), 16 * v35);
            --v28->Handlers.Data.Size;
          }
        }
LABEL_41:
        LeaveCriticalSection(v26);
        v5 = v41.pWaitList;
      }
    }
    while ( v12 );
  }
  v10 = 0;
LABEL_59:
  v42.vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Event::`vftable'{for `Scaleform::Waitable'};
  v42.vfptr = (Scaleform::AcquireInterfaceVtbl *)&Scaleform::Event::`vftable'{for `Scaleform::AcquireInterface'};
  Scaleform::WaitCondition::~WaitCondition((Scaleform::WaitCondition *)&v42.StateMutex);
  Scaleform::Mutex::~Mutex(&v42.StateMutex);
  v42.vfptr = (Scaleform::AcquireInterfaceVtbl *)&Scaleform::AcquireInterface::`vftable';
  v42.vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Waitable::`vftable';
  if ( v42.pHandlers )
    Scaleform::Waitable::HandlerArray::Release(v42.pHandlers);
  v42.vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable';
LABEL_62:
  if ( pacquireList != (Scaleform::AcquireInterface **)&v44 )
    ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
  return v10;
}

// File Line: 425
// RVA: 0x953300
void __fastcall Scaleform::AcquireInterface_OneOfMultipleWaitHandler(void *pdata)
{
  _DWORD *v1; // rsi
  Scaleform::Waitable::HandlerArray *v2; // rbx
  unsigned int v3; // edi
  __int64 v4; // rcx
  __int64 v5; // rax
  __int64 v6; // rdi
  volatile signed __int32 *v7; // rax
  Scaleform::Waitable::HandlerArray *v8; // [rsp+40h] [rbp+8h]

  v1 = pdata;
  v2 = 0i64;
  v3 = 0;
  if ( *((_DWORD *)pdata + 2) )
  {
    while ( 1 )
    {
      v4 = *(_QWORD *)(*(_QWORD *)v1 + 8i64 * v3);
      v5 = (*(__int64 (__cdecl **)(__int64))(*(_QWORD *)v4 + 16i64))(v4);
      if ( (*(unsigned __int8 (__fastcall **)(__int64))(*(_QWORD *)v5 + 8i64))(v5) )
        break;
      if ( ++v3 >= v1[2] )
        return;
    }
    v6 = *((_QWORD *)v1 + 2);
    Scaleform::Mutex::DoLock((Scaleform::Mutex *)(v6 + 40));
    *(_BYTE *)(v6 + 32) = 1;
    *(_BYTE *)(v6 + 33) = 1;
    Scaleform::WaitCondition::NotifyAll((Scaleform::WaitCondition *)(v6 + 80));
    v8 = 0i64;
    v7 = *(volatile signed __int32 **)(v6 + 16);
    if ( v7 )
    {
      v2 = *(Scaleform::Waitable::HandlerArray **)(v6 + 16);
      _InterlockedExchangeAdd(v7, 1u);
      v8 = v2;
    }
    Scaleform::Mutex::Unlock((Scaleform::Mutex *)(v6 + 40));
    if ( v2 )
      Scaleform::Waitable::HandlerArray::CallWaitHandlers(v2);
    if ( v2 && !_InterlockedDecrement(&v2->RefCount.Value) )
    {
      DeleteCriticalSection(&v8->HandlersLock.cs);
      if ( v8->Handlers.Data.Data )
        ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v8);
    }
  }
}

// File Line: 444
// RVA: 0x9534C0
signed __int64 __fastcall Scaleform::AcquireInterface_TryAcquireOne(Scaleform::Waitable **pwaitList, unsigned int waitCount)
{
  unsigned int v2; // ebx
  unsigned int v3; // ebp
  Scaleform::Waitable **v4; // rdi
  __int64 v5; // rsi

  v2 = 0;
  v3 = waitCount;
  v4 = pwaitList;
  if ( !waitCount )
    return 0xFFFFFFFFi64;
  while ( 1 )
  {
    v5 = ((__int64 (*)(void))(*v4)->vfptr[2].__vecDelDtor)();
    if ( (*(unsigned __int8 (__fastcall **)(__int64))(*(_QWORD *)v5 + 16i64))(v5) )
      break;
    ++v2;
    ++v4;
    if ( v2 >= v3 )
      return 0xFFFFFFFFi64;
  }
  (*(void (__fastcall **)(__int64))(*(_QWORD *)v5 + 24i64))(v5);
  return v2;
}

// File Line: 464
// RVA: 0x9539C0
signed __int64 __fastcall Scaleform::AcquireInterface::AcquireOneOfMultipleObjects(Scaleform::Waitable **pwaitList, unsigned int waitCount, unsigned int delay)
{
  unsigned int v3; // er14
  unsigned int v4; // er13
  Scaleform::Waitable **v5; // r12
  unsigned int v6; // er15
  unsigned int v7; // ebx
  Scaleform::Waitable **v8; // rdi
  __int64 v9; // rsi
  Scaleform::Waitable **v11; // rcx
  unsigned int v12; // esi
  Scaleform::Waitable *v13; // rdi
  Scaleform::Waitable::HandlerArray *v14; // rax
  _RTL_CRITICAL_SECTION *v15; // r12
  Scaleform::ArrayDataBase<Scaleform::Waitable::HandlerStruct,Scaleform::AllocatorGH<Scaleform::Waitable::HandlerStruct,2>,Scaleform::ArrayConstPolicy<0,16,1> > *v16; // rdi
  unsigned __int64 v17; // rbx
  unsigned __int64 v18; // r8
  signed __int64 v19; // rbx
  signed __int64 v20; // rdx
  bool v21; // zf
  _QWORD *v22; // rdx
  signed __int64 v23; // rdi
  Scaleform::Waitable *v24; // rbx
  Scaleform::Waitable::HandlerArray *v25; // rax
  _RTL_CRITICAL_SECTION *v26; // r14
  unsigned int v27; // ecx
  Scaleform::Waitable::HandlerArray *v28; // rbx
  unsigned __int64 v29; // rdx
  Scaleform::Waitable::HandlerStruct *v30; // r8
  __int64 v31; // rax
  signed __int64 v32; // rax
  unsigned __int64 v33; // r8
  unsigned __int64 v34; // rax
  signed __int64 v35; // r8
  signed __int64 v36; // rcx
  unsigned int v37; // ebx
  unsigned int v38; // ebx
  unsigned int v39; // edi
  __int64 v40; // rdx
  unsigned int v41; // edx
  Scaleform::AcquireInterface_AcquireDesc v42; // [rsp+20h] [rbp-79h]
  Scaleform::Event v43; // [rsp+40h] [rbp-59h]
  _QWORD *v44; // [rsp+A0h] [rbp+7h]
  _QWORD *v45; // [rsp+A8h] [rbp+Fh]
  Scaleform::Lock *v46; // [rsp+B0h] [rbp+17h]
  __int64 v47; // [rsp+B8h] [rbp+1Fh]
  Scaleform::Waitable **v48; // [rsp+100h] [rbp+67h]

  v48 = pwaitList;
  v47 = -2i64;
  v3 = delay;
  v4 = waitCount;
  v5 = pwaitList;
  v6 = 0;
  v7 = 0;
  if ( waitCount )
  {
    v8 = pwaitList;
    while ( 1 )
    {
      v9 = ((__int64 (*)(void))(*v8)->vfptr[2].__vecDelDtor)();
      if ( (*(unsigned __int8 (__fastcall **)(__int64))(*(_QWORD *)v9 + 16i64))(v9) )
        break;
      ++v7;
      ++v8;
      if ( v7 >= v4 )
        goto LABEL_8;
    }
    (*(void (__fastcall **)(__int64))(*(_QWORD *)v9 + 24i64))(v9);
    if ( v7 != -1 )
      return v7;
  }
LABEL_8:
  if ( !v3 )
    return 0xFFFFFFFFi64;
  v43.RefCount = 1;
  v43.pHandlers = 0i64;
  v43.vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Event::`vftable'{for `Scaleform::Waitable'};
  v43.vfptr = (Scaleform::AcquireInterfaceVtbl *)&Scaleform::Event::`vftable'{for `Scaleform::AcquireInterface'};
  Scaleform::Mutex::Mutex(&v43.StateMutex, 1, 0);
  Scaleform::WaitCondition::WaitCondition(&v43.StateWaitCondition);
  v43.State = 0;
  v43.Temporary = 0;
  v11 = v5;
  v42.pWaitList = v5;
  v42.WaitCount = v4;
  v42.pEvent = &v43;
  v42.pAcquireList = 0i64;
  v12 = 0;
  if ( !v4 )
  {
LABEL_43:
    v37 = Scaleform::AcquireInterface_TryAcquireOne(v5, v4);
    if ( v37 == -1 )
    {
      v38 = v3;
      if ( v3 != -1 )
        v6 = Scaleform::Timer::GetTicksMs();
      v39 = Scaleform::AcquireInterface_TryAcquireOne(v5, v4);
      if ( v39 == -1 && Scaleform::Event::Wait(&v43, v3) )
      {
        do
        {
          v39 = Scaleform::AcquireInterface_TryAcquireOne(v5, v4);
          if ( v39 != -1 )
            break;
          if ( v3 != -1 )
          {
            v40 = timeGetTime();
            if ( TimerOverrideInstance )
              LODWORD(v40) = TimerOverrideInstance->vfptr->GetTicksMs(TimerOverrideInstance, v40);
            v41 = v40 - v6;
            if ( v41 >= v3 )
              break;
            v38 = v3 - v41;
          }
        }
        while ( Scaleform::Event::Wait(&v43, v38) );
      }
      Scaleform::AcquireInterface_AcquireDesc::RemoveHandlers(
        &v42,
        Scaleform::AcquireInterface_OneOfMultipleWaitHandler);
      v6 = v39;
    }
    else
    {
      Scaleform::AcquireInterface_AcquireDesc::RemoveHandlers(
        &v42,
        Scaleform::AcquireInterface_OneOfMultipleWaitHandler);
      v6 = v37;
    }
    goto LABEL_57;
  }
  while ( 1 )
  {
    v13 = v11[v12];
    v14 = v13->pHandlers;
    if ( !v14 )
      break;
    v15 = &v14->HandlersLock.cs;
    EnterCriticalSection(&v14->HandlersLock.cs);
    v16 = (Scaleform::ArrayDataBase<Scaleform::Waitable::HandlerStruct,Scaleform::AllocatorGH<Scaleform::Waitable::HandlerStruct,2>,Scaleform::ArrayConstPolicy<0,16,1> > *)&v13->pHandlers->Handlers.Data.Data;
    v17 = v16->Size + 1;
    if ( v17 >= v16->Size )
    {
      if ( v17 <= v16->Policy.Capacity )
        goto LABEL_18;
      v18 = v17 + (v17 >> 2);
    }
    else
    {
      if ( v17 >= v16->Policy.Capacity >> 1 )
        goto LABEL_18;
      v18 = v16->Size + 1;
    }
    Scaleform::ArrayDataBase<Scaleform::Waitable::HandlerStruct,Scaleform::AllocatorGH<Scaleform::Waitable::HandlerStruct,2>,Scaleform::ArrayConstPolicy<0,16,1>>::Reserve(
      v16,
      v16,
      v18);
LABEL_18:
    v16->Size = v17;
    v19 = 16 * v17;
    v20 = (signed __int64)&v16->Data[-1];
    v21 = v19 + v20 == 0;
    v22 = (_QWORD *)(v19 + v20);
    v45 = v22;
    v44 = v22;
    if ( !v21 )
    {
      *v22 = Scaleform::AcquireInterface_OneOfMultipleWaitHandler;
      v22[1] = &v42;
    }
    LeaveCriticalSection(v15);
    if ( ++v12 >= v42.WaitCount )
    {
      v5 = v48;
      goto LABEL_43;
    }
    v11 = v42.pWaitList;
  }
  if ( v12 )
  {
    v23 = v12;
    do
    {
      --v12;
      --v23;
      v24 = v11[v23];
      v25 = v24->pHandlers;
      if ( v25 )
      {
        v26 = &v25->HandlersLock.cs;
        v46 = &v25->HandlersLock;
        EnterCriticalSection(&v25->HandlersLock.cs);
        v27 = 0;
        v28 = v24->pHandlers;
        v29 = v28->Handlers.Data.Size;
        if ( v29 )
        {
          v30 = v28->Handlers.Data.Data;
          v31 = 0i64;
          while ( 1 )
          {
            v32 = v31;
            if ( v30[v32].Handler == Scaleform::AcquireInterface_OneOfMultipleWaitHandler && v30[v32].pUserData == &v42 )
              break;
            v31 = ++v27;
            if ( v27 >= v29 )
              goto LABEL_39;
          }
          v33 = v28->Handlers.Data.Size;
          if ( v33 == 1 )
          {
            v34 = v28->Handlers.Data.Policy.Capacity;
            if ( v34 & 0xFFFFFFFFFFFFFFFEui64 && !v34 )
            {
              if ( v28->Handlers.Data.Data )
              {
                ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
                v28->Handlers.Data.Data = 0i64;
              }
              v28->Handlers.Data.Policy.Capacity = 0i64;
            }
            v28->Handlers.Data.Size = 0i64;
          }
          else
          {
            v35 = v33 - v27 - 1;
            v36 = (signed __int64)&v28->Handlers.Data.Data[v27];
            memmove((void *)v36, (const void *)(v36 + 16), 16 * v35);
            --v28->Handlers.Data.Size;
          }
        }
LABEL_39:
        LeaveCriticalSection(v26);
        v11 = v42.pWaitList;
      }
    }
    while ( v12 );
  }
LABEL_57:
  v43.vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Event::`vftable'{for `Scaleform::Waitable'};
  v43.vfptr = (Scaleform::AcquireInterfaceVtbl *)&Scaleform::Event::`vftable'{for `Scaleform::AcquireInterface'};
  Scaleform::WaitCondition::~WaitCondition(&v43.StateWaitCondition);
  Scaleform::Mutex::~Mutex(&v43.StateMutex);
  v43.vfptr = (Scaleform::AcquireInterfaceVtbl *)&Scaleform::AcquireInterface::`vftable';
  v43.vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Waitable::`vftable';
  if ( v43.pHandlers )
    Scaleform::Waitable::HandlerArray::Release(v43.pHandlers);
  return v6;
}

// File Line: 529
// RVA: 0x93B8C0
void __fastcall Scaleform::Event::Event(Scaleform::Event *this, bool setInitially, bool multiWait)
{
  bool v3; // bl
  Scaleform::Event *v4; // rdi

  v3 = setInitially;
  v4 = this;
  Scaleform::Waitable::Waitable((Scaleform::Waitable *)&this->vfptr, multiWait);
  v4->vfptr = (Scaleform::AcquireInterfaceVtbl *)&Scaleform::AcquireInterface::`vftable';
  v4->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Event::`vftable'{for `Scaleform::Waitable'};
  v4->vfptr = (Scaleform::AcquireInterfaceVtbl *)&Scaleform::Event::`vftable'{for `Scaleform::AcquireInterface'};
  Scaleform::Mutex::Mutex(&v4->StateMutex, 1, 0);
  Scaleform::WaitCondition::WaitCondition(&v4->StateWaitCondition);
  v4->State = v3;
  v4->Temporary = 0;
}

// File Line: 536
// RVA: 0x949F70
void __fastcall Scaleform::Event::~Event(Scaleform::Event *this)
{
  Scaleform::Event *v1; // rbx
  Scaleform::Waitable::HandlerArray *v2; // rcx

  v1 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Event::`vftable'{for `Scaleform::Waitable'};
  this->vfptr = (Scaleform::AcquireInterfaceVtbl *)&Scaleform::Event::`vftable'{for `Scaleform::AcquireInterface'};
  Scaleform::WaitCondition::~WaitCondition(&this->StateWaitCondition);
  Scaleform::Mutex::~Mutex(&v1->StateMutex);
  v1->vfptr = (Scaleform::AcquireInterfaceVtbl *)&Scaleform::AcquireInterface::`vftable';
  v1->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Waitable::`vftable';
  v2 = v1->pHandlers;
  if ( v2 )
    Scaleform::Waitable::HandlerArray::Release(v2);
  v1->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable';
}

// File Line: 541
// RVA: 0x9C2360
__int64 __fastcall Scaleform::Event::Wait(Scaleform::Event *this, unsigned int delay)
{
  unsigned int v2; // esi
  Scaleform::Event *v3; // rdi
  Scaleform::Mutex *v4; // rbx
  volatile bool v5; // al
  volatile bool v6; // bl
  Scaleform::Mutex *v8; // [rsp+40h] [rbp+8h]

  v2 = delay;
  v3 = this;
  v4 = &this->StateMutex;
  v8 = &this->StateMutex;
  Scaleform::Mutex::DoLock(&this->StateMutex);
  if ( v2 )
  {
    v5 = v3->State;
    if ( v2 == -1 )
    {
      if ( !v5 )
      {
        do
          Scaleform::WaitCondition::Wait(&v3->StateWaitCondition, v4, 0xFFFFFFFF);
        while ( !v3->State );
      }
    }
    else if ( !v5 )
    {
      Scaleform::WaitCondition::Wait(&v3->StateWaitCondition, v4, v2);
    }
  }
  v6 = v3->State;
  if ( v3->Temporary )
  {
    v3->Temporary = 0;
    v3->State = 0;
  }
  Scaleform::Mutex::Unlock(v8);
  return (unsigned __int8)v6;
}

// File Line: 574
// RVA: 0x9AF260
void __fastcall Scaleform::Event::SetEvent(Scaleform::Event *this)
{
  Scaleform::Event *v1; // rdi
  Scaleform::Waitable::HandlerArray *v2; // rbx
  volatile signed __int32 *v3; // rax

  v1 = this;
  Scaleform::Mutex::DoLock(&this->StateMutex);
  v1->State = 1;
  v1->Temporary = 0;
  Scaleform::WaitCondition::NotifyAll(&v1->StateWaitCondition);
  v2 = 0i64;
  v3 = &v1->pHandlers->RefCount.Value;
  if ( v3 )
  {
    v2 = v1->pHandlers;
    _InterlockedExchangeAdd(v3, 1u);
  }
  Scaleform::Mutex::Unlock(&v1->StateMutex);
  if ( v2 )
    Scaleform::Waitable::HandlerArray::CallWaitHandlers(v2);
  if ( v2 )
    Scaleform::Waitable::HandlerArray::Release(v2);
}

// File Line: 589
// RVA: 0x9ABA40
void __fastcall Scaleform::Event::ResetEvent(Scaleform::Event *this)
{
  Scaleform::Event *v1; // rdi
  Scaleform::Mutex *v2; // rbx

  v1 = this;
  v2 = &this->StateMutex;
  Scaleform::Mutex::DoLock(&this->StateMutex);
  v1->State = 0;
  v1->Temporary = 0;
  Scaleform::Mutex::Unlock(v2);
}

// File Line: 599
// RVA: 0x9A1DC0
void __fastcall Scaleform::Event::PulseEvent(Scaleform::Event *this)
{
  Scaleform::Event *v1; // rdi
  Scaleform::Waitable::HandlerArray *v2; // rbx
  volatile signed __int32 *v3; // rax

  v1 = this;
  Scaleform::Mutex::DoLock(&this->StateMutex);
  v1->State = 1;
  v1->Temporary = 1;
  Scaleform::WaitCondition::NotifyAll(&v1->StateWaitCondition);
  v2 = 0i64;
  v3 = &v1->pHandlers->RefCount.Value;
  if ( v3 )
  {
    v2 = v1->pHandlers;
    _InterlockedExchangeAdd(v3, 1u);
  }
  Scaleform::Mutex::Unlock(&v1->StateMutex);
  if ( v2 )
    Scaleform::Waitable::HandlerArray::CallWaitHandlers(v2);
  if ( v2 )
    Scaleform::Waitable::HandlerArray::Release(v2);
}

// File Line: 613
// RVA: 0x997D70
__int64 __fastcall Scaleform::Event::IsSignaled(Scaleform::Event *this)
{
  return (unsigned __int8)this->State;
}

// File Line: 625
// RVA: 0x95DB20
__int64 __fastcall Scaleform::Thread::CanAcquire(Scaleform::Thread *this)
{
  return (*((__int64 (__fastcall **)(void **))this[-1].ThreadHandle + 1))(&this[-1].ThreadHandle);
}

// File Line: 633
// RVA: 0x9BAF40
char __fastcall Scaleform::Event::TryAcquireCommit(Scaleform::Event *this)
{
  Scaleform::Event *v1; // rbx
  Scaleform::Mutex *v3; // [rsp+40h] [rbp+8h]

  v1 = this;
  v3 = (Scaleform::Mutex *)&this->pHandlers;
  Scaleform::Mutex::DoLock((Scaleform::Mutex *)&this->pHandlers);
  if ( BYTE1(v1->RefCount) )
  {
    BYTE1(v1->RefCount) = 0;
    LOBYTE(v1->RefCount) = 0;
  }
  Scaleform::Mutex::Unlock(v3);
  return 1;
}

// File Line: 653
// RVA: 0x9442A0
void __fastcall Scaleform::Semaphore::Semaphore(Scaleform::Semaphore *this, int maxValue, bool multiWait)
{
  int v3; // ebx
  Scaleform::Semaphore *v4; // rdi

  v3 = maxValue;
  v4 = this;
  Scaleform::Waitable::Waitable((Scaleform::Waitable *)&this->vfptr, multiWait);
  v4->vfptr = (Scaleform::AcquireInterfaceVtbl *)&Scaleform::AcquireInterface::`vftable';
  v4->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Semaphore::`vftable'{for `Scaleform::Waitable'};
  v4->vfptr = (Scaleform::AcquireInterfaceVtbl *)&Scaleform::Semaphore::`vftable'{for `Scaleform::AcquireInterface'};
  Scaleform::Mutex::Mutex(&v4->ValueMutex, 1, 0);
  Scaleform::WaitCondition::WaitCondition(&v4->ValueWaitCondition);
  v4->MaxValue = v3;
  v4->Value = 0;
}

// File Line: 660
// RVA: 0x94C9D0
void __fastcall Scaleform::Semaphore::~Semaphore(Scaleform::Semaphore *this)
{
  Scaleform::Semaphore *v1; // rbx
  Scaleform::Waitable::HandlerArray *v2; // rcx

  v1 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Semaphore::`vftable'{for `Scaleform::Waitable'};
  this->vfptr = (Scaleform::AcquireInterfaceVtbl *)&Scaleform::Semaphore::`vftable'{for `Scaleform::AcquireInterface'};
  Scaleform::WaitCondition::~WaitCondition(&this->ValueWaitCondition);
  Scaleform::Mutex::~Mutex(&v1->ValueMutex);
  v1->vfptr = (Scaleform::AcquireInterfaceVtbl *)&Scaleform::AcquireInterface::`vftable';
  v1->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Waitable::`vftable';
  v2 = v1->pHandlers;
  if ( v2 )
    Scaleform::Waitable::HandlerArray::Release(v2);
  v1->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable';
}

// File Line: 682
// RVA: 0x99C7D0
char __fastcall Scaleform::Semaphore::ObtainSemaphore(Scaleform::Semaphore *this, int count, unsigned int delay)
{
  unsigned int v3; // ebp
  int v4; // esi
  Scaleform::Semaphore *v5; // rdi
  Scaleform::Mutex *v7; // rbx
  char v8; // bl
  unsigned int v9; // er14
  __int64 v10; // rdx
  unsigned int v11; // edx
  Scaleform::Mutex *v12; // [rsp+50h] [rbp+8h]

  v3 = delay;
  v4 = count;
  v5 = this;
  if ( count > this->MaxValue )
    return 0;
  v7 = &this->ValueMutex;
  v12 = &this->ValueMutex;
  Scaleform::Mutex::DoLock(&this->ValueMutex);
  if ( v4 + v5->Value <= v5->MaxValue )
    goto LABEL_8;
  if ( !v3 )
    goto LABEL_17;
  if ( v3 != -1 )
  {
    v9 = timeGetTime();
    if ( TimerOverrideInstance )
      v9 = TimerOverrideInstance->vfptr->GetTicksMs(TimerOverrideInstance, v9);
    if ( Scaleform::WaitCondition::Wait(&v5->ValueWaitCondition, v7, v3) )
    {
      while ( v4 + v5->Value > v5->MaxValue )
      {
        v10 = timeGetTime();
        if ( TimerOverrideInstance )
          LODWORD(v10) = TimerOverrideInstance->vfptr->GetTicksMs(TimerOverrideInstance, v10);
        v11 = v10 - v9;
        if ( v11 >= v3 || !Scaleform::WaitCondition::Wait(&v5->ValueWaitCondition, v7, v3 - v11) )
          goto LABEL_17;
      }
      goto LABEL_8;
    }
LABEL_17:
    v8 = 0;
    goto LABEL_18;
  }
  while ( v4 + v5->Value > v5->MaxValue )
    Scaleform::WaitCondition::Wait(&v5->ValueWaitCondition, v7, 0xFFFFFFFF);
LABEL_8:
  v5->Value += v4;
  v8 = 1;
LABEL_18:
  Scaleform::Mutex::Unlock(v12);
  return v8;
}

// File Line: 736
// RVA: 0x9A83D0
char __fastcall Scaleform::Semaphore::ReleaseSemaphore(Scaleform::Semaphore *this, int count)
{
  int v2; // esi
  Scaleform::Semaphore *v3; // rdi
  Scaleform::Waitable::HandlerArray *v4; // rbx
  Scaleform::WaitCondition *v5; // rcx
  volatile signed __int32 *v6; // rax

  v2 = count;
  v3 = this;
  if ( count )
  {
    Scaleform::Mutex::DoLock(&this->ValueMutex);
    v4 = 0i64;
    if ( v3->Value - v2 < 0 )
      v3->Value = 0;
    else
      v3->Value -= v2;
    v5 = &v3->ValueWaitCondition;
    if ( v2 == 1 )
      Scaleform::WaitCondition::Notify(v5);
    else
      Scaleform::WaitCondition::NotifyAll(v5);
    v6 = &v3->pHandlers->RefCount.Value;
    if ( v6 )
    {
      v4 = v3->pHandlers;
      _InterlockedExchangeAdd(v6, 1u);
    }
    Scaleform::Mutex::Unlock(&v3->ValueMutex);
    if ( v4 )
      Scaleform::Waitable::HandlerArray::CallWaitHandlers(v4);
    if ( v4 )
      Scaleform::Waitable::HandlerArray::Release(v4);
  }
  return 1;
}

// File Line: 770
// RVA: 0x94EFF0
__int64 __fastcall Scaleform::Semaphore::operator++(Scaleform::Semaphore *this, int __formal)
{
  Scaleform::Semaphore *v2; // rdi
  Scaleform::Mutex *v3; // rbx
  volatile unsigned int v4; // ebx
  Scaleform::Mutex *v6; // [rsp+40h] [rbp+8h]

  v2 = this;
  v3 = &this->ValueMutex;
  v6 = &this->ValueMutex;
  Scaleform::Mutex::DoLock(&this->ValueMutex);
  while ( v2->Value >= v2->MaxValue )
    Scaleform::WaitCondition::Wait(&v2->ValueWaitCondition, v3, 0xFFFFFFFF);
  v4 = ++v2->Value;
  Scaleform::Mutex::Unlock(v6);
  return v4;
}

// File Line: 780
// RVA: 0x94F070
__int64 __fastcall Scaleform::Semaphore::operator--(Scaleform::Semaphore *this, int __formal)
{
  Scaleform::Semaphore *v2; // rdi
  Scaleform::Waitable::HandlerArray *v3; // rbx
  volatile signed __int32 *v4; // rax
  volatile unsigned int v5; // ebx
  Scaleform::Waitable::HandlerArray *v7; // [rsp+40h] [rbp+8h]

  v2 = this;
  Scaleform::Mutex::DoLock(&this->ValueMutex);
  if ( v2->Value > 0 )
    --v2->Value;
  Scaleform::WaitCondition::Notify(&v2->ValueWaitCondition);
  v3 = 0i64;
  v7 = 0i64;
  v4 = &v2->pHandlers->RefCount.Value;
  if ( v4 )
  {
    v3 = v2->pHandlers;
    _InterlockedExchangeAdd(v4, 1u);
    v7 = v3;
  }
  Scaleform::Mutex::Unlock(&v2->ValueMutex);
  if ( v3 )
    Scaleform::Waitable::HandlerArray::CallWaitHandlers(v3);
  v5 = v2->Value;
  if ( v7 )
    Scaleform::Waitable::HandlerArray::Release(v7);
  return v5;
}

// File Line: 795
// RVA: 0x94F260
__int64 __fastcall Scaleform::Semaphore::operator+=(Scaleform::Semaphore *this, int count)
{
  int v2; // esi
  Scaleform::Semaphore *v3; // rdi
  Scaleform::Mutex *v4; // rbx
  volatile unsigned int v5; // ebx
  Scaleform::Mutex *v7; // [rsp+40h] [rbp+8h]

  v2 = count;
  v3 = this;
  v4 = &this->ValueMutex;
  v7 = &this->ValueMutex;
  Scaleform::Mutex::DoLock(&this->ValueMutex);
  while ( v2 + v3->Value > v3->MaxValue )
    Scaleform::WaitCondition::Wait(&v3->ValueWaitCondition, v4, 0xFFFFFFFF);
  v3->Value += v2;
  v5 = v3->Value;
  Scaleform::Mutex::Unlock(v7);
  return v5;
}

// File Line: 805
// RVA: 0x94F3F0
__int64 __fastcall Scaleform::Semaphore::operator-=(Scaleform::Semaphore *this, int count)
{
  int v2; // esi
  Scaleform::Semaphore *v3; // rdi
  Scaleform::Waitable::HandlerArray *v4; // rbx
  volatile signed __int32 *v5; // rax
  volatile unsigned int v6; // ebx
  Scaleform::Waitable::HandlerArray *v8; // [rsp+40h] [rbp+8h]

  v2 = count;
  v3 = this;
  Scaleform::Mutex::DoLock(&this->ValueMutex);
  v4 = 0i64;
  if ( v3->Value - v2 < 0 )
    v3->Value = 0;
  else
    v3->Value -= v2;
  Scaleform::WaitCondition::NotifyAll(&v3->ValueWaitCondition);
  v8 = 0i64;
  v5 = &v3->pHandlers->RefCount.Value;
  if ( v5 )
  {
    v4 = v3->pHandlers;
    _InterlockedExchangeAdd(v5, 1u);
    v8 = v4;
  }
  Scaleform::Mutex::Unlock(&v3->ValueMutex);
  if ( v4 )
    Scaleform::Waitable::HandlerArray::CallWaitHandlers(v4);
  v6 = v3->Value;
  if ( v8 )
    Scaleform::Waitable::HandlerArray::Release(v8);
  return v6;
}

// File Line: 824
// RVA: 0x95DB30
bool __fastcall Scaleform::Semaphore::CanAcquire(Scaleform::Semaphore *this)
{
  return this->RefCount - *((_DWORD *)&this->RefCount + 1) > 0;
}

// File Line: 826
// RVA: 0x9BADB0
char __fastcall Scaleform::Semaphore::TryAcquire(Scaleform::Semaphore *this)
{
  Scaleform::Semaphore *v1; // rbx
  Scaleform::Mutex *v3; // [rsp+40h] [rbp+8h]

  v1 = this;
  if ( this->RefCount >= 1 )
  {
    v3 = (Scaleform::Mutex *)&this->pHandlers;
    Scaleform::Mutex::DoLock((Scaleform::Mutex *)&this->pHandlers);
    if ( *((_DWORD *)&v1->RefCount + 1) + 1 <= v1->RefCount )
    {
      ++*((_DWORD *)&v1->RefCount + 1);
      Scaleform::Mutex::Unlock(v3);
      return 1;
    }
    Scaleform::Mutex::Unlock(v3);
  }
  return 0;
}

// File Line: 830
// RVA: 0x9BAE80
char __fastcall Scaleform::Semaphore::TryAcquireCancel(Scaleform::Semaphore *this)
{
  Scaleform::Semaphore *v1; // rdi
  Scaleform::Waitable::HandlerArray *v2; // rbx
  volatile signed __int32 *v3; // rax

  v1 = this;
  Scaleform::Mutex::DoLock((Scaleform::Mutex *)&this->pHandlers);
  v2 = 0i64;
  if ( *((_DWORD *)&v1->RefCount + 1) - 1 < 0 )
    *((_DWORD *)&v1->RefCount + 1) = 0;
  else
    --*((_DWORD *)&v1->RefCount + 1);
  Scaleform::WaitCondition::Notify((Scaleform::WaitCondition *)&v1->ValueMutex.pHandlers);
  v3 = (volatile signed __int32 *)v1[-1].ValueWaitCondition.pImpl;
  if ( v3 )
  {
    v2 = (Scaleform::Waitable::HandlerArray *)v1[-1].ValueWaitCondition.pImpl;
    _InterlockedExchangeAdd(v3, 1u);
  }
  Scaleform::Mutex::Unlock((Scaleform::Mutex *)&v1->pHandlers);
  if ( v2 )
    Scaleform::Waitable::HandlerArray::CallWaitHandlers(v2);
  if ( v2 )
    Scaleform::Waitable::HandlerArray::Release(v2);
  return 1;
}

// File Line: 835
// RVA: 0x997D80
bool __fastcall Scaleform::Semaphore::IsSignaled(Scaleform::Semaphore *this)
{
  return this->MaxValue - this->Value > 0;
}

// File Line: 881
// RVA: 0x944320
void __fastcall Scaleform::SemaphoreWaitableIncrement::SemaphoreWaitableIncrement(Scaleform::SemaphoreWaitableIncrement *this, Scaleform::Semaphore *psemaphore, int count)
{
  int v3; // esi
  Scaleform::Semaphore *v4; // rdi
  Scaleform::SemaphoreWaitableIncrement *v5; // rbx
  Scaleform::Waitable::HandlerArray *v6; // rax

  v3 = count;
  v4 = psemaphore;
  v5 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::Waitable,2>::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Waitable::`vftable';
  v6 = (Scaleform::Waitable::HandlerArray *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                              Scaleform::Memory::pGlobalHeap,
                                              72i64);
  if ( v6 )
    Scaleform::Waitable::HandlerArray::HandlerArray(v6);
  v5->pHandlers = v6;
  v5->vfptr = (Scaleform::AcquireInterfaceVtbl *)&Scaleform::AcquireInterface::`vftable';
  v5->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::SemaphoreWaitableIncrement::`vftable'{for `Scaleform::Waitable'};
  v5->vfptr = (Scaleform::AcquireInterfaceVtbl *)&Scaleform::SemaphoreWaitableIncrement::`vftable'{for `Scaleform::AcquireInterface'};
  v5->pSemaphore = v4;
  v5->Count = v3;
  Scaleform::Waitable::AddWaitHandler((Scaleform::Waitable *)&v4->vfptr, Scaleform::Waitable::CallWaitHandlers, v5);
}

// File Line: 888
// RVA: 0x94CA50
void __fastcall Scaleform::SemaphoreWaitableIncrement::~SemaphoreWaitableIncrement(Scaleform::SemaphoreWaitableIncrement *this)
{
  Scaleform::SemaphoreWaitableIncrement *v1; // rbx
  Scaleform::Waitable::HandlerArray *v2; // rcx

  v1 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::SemaphoreWaitableIncrement::`vftable'{for `Scaleform::Waitable'};
  this->vfptr = (Scaleform::AcquireInterfaceVtbl *)&Scaleform::SemaphoreWaitableIncrement::`vftable'{for `Scaleform::AcquireInterface'};
  Scaleform::Waitable::RemoveWaitHandler(
    (Scaleform::Waitable *)&this->pSemaphore->vfptr,
    Scaleform::Waitable::CallWaitHandlers,
    this);
  v1->vfptr = (Scaleform::AcquireInterfaceVtbl *)&Scaleform::AcquireInterface::`vftable';
  v1->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Waitable::`vftable';
  v2 = v1->pHandlers;
  if ( v2 )
    Scaleform::Waitable::HandlerArray::Release(v2);
  v1->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable';
}

// File Line: 894
// RVA: 0x95DB40
bool __fastcall Scaleform::SemaphoreWaitableIncrement::CanAcquire(Scaleform::SemaphoreWaitableIncrement *this)
{
  __int64 v1; // rdx
  bool result; // al

  v1 = *(_QWORD *)&this->RefCount;
  if ( v1 )
    result = *(_DWORD *)(v1 + 32) - *(_DWORD *)(v1 + 36) >= SLODWORD(this->pHandlers);
  else
    result = 0;
  return result;
}

// File Line: 899
// RVA: 0x9BAE10
char __fastcall Scaleform::SemaphoreWaitableIncrement::TryAcquire(Scaleform::SemaphoreWaitableIncrement *this)
{
  __int64 v1; // rbx
  int v2; // edi
  Scaleform::Mutex *v4; // [rsp+40h] [rbp+8h]

  v1 = *(_QWORD *)&this->RefCount;
  if ( v1 )
  {
    v2 = (int)this->pHandlers;
    if ( v2 <= *(_DWORD *)(v1 + 32) )
    {
      v4 = (Scaleform::Mutex *)(v1 + 40);
      Scaleform::Mutex::DoLock((Scaleform::Mutex *)(v1 + 40));
      if ( v2 + *(_DWORD *)(v1 + 36) <= *(_DWORD *)(v1 + 32) )
      {
        *(_DWORD *)(v1 + 36) += v2;
        Scaleform::Mutex::Unlock(v4);
        return 1;
      }
      Scaleform::Mutex::Unlock(v4);
    }
  }
  return 0;
}

// File Line: 904
// RVA: 0x9BAF90
bool __fastcall Scaleform::SemaphoreWaitableIncrement::TryAcquireCommit(Scaleform::SemaphoreWaitableIncrement *this)
{
  return *(_QWORD *)&this->RefCount != 0i64;
}

// File Line: 909
// RVA: 0x9BAF20
bool __fastcall Scaleform::SemaphoreWaitableIncrement::TryAcquireCancel(Scaleform::SemaphoreWaitableIncrement *this)
{
  __int64 v1; // rax

  v1 = *(_QWORD *)&this->RefCount;
  if ( v1 )
    LOBYTE(v1) = Scaleform::Semaphore::ReleaseSemaphore(*(Scaleform::Semaphore **)&this->RefCount, (int)this->pHandlers);
  return v1;
}

// File Line: 916
// RVA: 0x997D90
bool __fastcall Scaleform::SemaphoreWaitableIncrement::IsSignaled(Scaleform::SemaphoreWaitableIncrement *this)
{
  Scaleform::Semaphore *v1; // rdx
  bool result; // al

  v1 = this->pSemaphore;
  if ( v1 )
    result = v1->MaxValue - v1->Value >= this->Count;
  else
    result = 0;
  return result;
}

// File Line: 927
// RVA: 0x96A930
void __fastcall Scaleform::Semaphore::CreateWaitableIncrement(Scaleform::Semaphore *this, int count)
{
  int v2; // ebx
  Scaleform::Semaphore *v3; // rdi
  Scaleform::SemaphoreWaitableIncrement *v4; // rax

  v2 = count;
  v3 = this;
  v4 = (Scaleform::SemaphoreWaitableIncrement *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                                  Scaleform::Memory::pGlobalHeap,
                                                  48i64);
  if ( v4 )
    Scaleform::SemaphoreWaitableIncrement::SemaphoreWaitableIncrement(v4, v3, v2);
}

