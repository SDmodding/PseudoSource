// File Line: 32
// RVA: 0x9470F0
void __fastcall Scaleform::Waitable::Waitable(Scaleform::Waitable *this, bool enable)
{
  Scaleform::Waitable::HandlerArray *v3; // rax

  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::Waitable,2>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Waitable::`vftable;
  if ( enable )
  {
    v3 = (Scaleform::Waitable::HandlerArray *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                                Scaleform::Memory::pGlobalHeap,
                                                72i64);
    if ( v3 )
      Scaleform::Waitable::HandlerArray::HandlerArray(v3);
  }
  else
  {
    v3 = 0i64;
  }
  this->pHandlers = v3;
}

// File Line: 41
// RVA: 0x94DB70
void __fastcall Scaleform::Waitable::~Waitable(Scaleform::Waitable *this)
{
  Scaleform::Waitable::HandlerArray *pHandlers; // rcx

  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Waitable::`vftable;
  pHandlers = this->pHandlers;
  if ( pHandlers )
    Scaleform::Waitable::HandlerArray::Release(pHandlers);
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
}

// File Line: 47
// RVA: 0x9551C0
bool __fastcall Scaleform::Waitable::AddWaitHandler(
        Scaleform::Waitable *this,
        void (__fastcall *handler)(void *),
        void *pdata)
{
  Scaleform::Waitable::HandlerArray *pHandlers; // rax
  _RTL_CRITICAL_SECTION *p_cs; // rsi
  Scaleform::Array<Scaleform::Waitable::HandlerStruct,2,Scaleform::ArrayConstPolicy<0,16,1> > *p_Handlers; // rdi
  unsigned __int64 v9; // rbx
  unsigned __int64 v10; // r8
  Scaleform::Waitable::HandlerStruct *v11; // rdx

  pHandlers = this->pHandlers;
  if ( !pHandlers )
    return (char)pHandlers;
  p_cs = &pHandlers->HandlersLock.cs;
  EnterCriticalSection(&pHandlers->HandlersLock.cs);
  p_Handlers = &this->pHandlers->Handlers;
  v9 = p_Handlers->Data.Size + 1;
  if ( v9 >= p_Handlers->Data.Size )
  {
    if ( v9 > p_Handlers->Data.Policy.Capacity )
    {
      v10 = v9 + (v9 >> 2);
      goto LABEL_7;
    }
  }
  else if ( v9 < p_Handlers->Data.Policy.Capacity >> 1 )
  {
    v10 = p_Handlers->Data.Size + 1;
LABEL_7:
    Scaleform::ArrayDataBase<Scaleform::Waitable::HandlerStruct,Scaleform::AllocatorGH<Scaleform::Waitable::HandlerStruct,2>,Scaleform::ArrayConstPolicy<0,16,1>>::Reserve(
      &p_Handlers->Data,
      p_Handlers,
      v10);
  }
  p_Handlers->Data.Size = v9;
  v11 = &p_Handlers->Data.Data[v9 - 1];
  if ( v11 )
  {
    v11->Handler = handler;
    v11->pUserData = pdata;
  }
  LeaveCriticalSection(p_cs);
  LOBYTE(pHandlers) = 1;
  return (char)pHandlers;
}

// File Line: 68
// RVA: 0x9AA710
Scaleform::Waitable::HandlerArray *__fastcall Scaleform::Waitable::RemoveWaitHandler(
        Scaleform::Waitable *this,
        void (__fastcall *handler)(void *),
        void *pdata)
{
  Scaleform::Waitable::HandlerArray *result; // rax
  unsigned __int8 v7; // bp
  _RTL_CRITICAL_SECTION *p_cs; // r14
  unsigned int v9; // ecx
  Scaleform::Waitable::HandlerArray *pHandlers; // rdi
  unsigned __int64 Size; // rdx
  __int64 v12; // rax
  __int64 v13; // rax
  unsigned __int64 v14; // r8
  __int64 v15; // r8
  __int64 v16; // rcx

  result = this->pHandlers;
  if ( result )
  {
    v7 = 0;
    p_cs = &result->HandlersLock.cs;
    EnterCriticalSection(&result->HandlersLock.cs);
    v9 = 0;
    pHandlers = this->pHandlers;
    Size = pHandlers->Handlers.Data.Size;
    if ( Size )
    {
      v12 = 0i64;
      while ( 1 )
      {
        v13 = (__int64)&pHandlers->Handlers.Data.Data[v12];
        if ( *(void (__fastcall **)(void *))v13 == handler && *(void **)(v13 + 8) == pdata )
          break;
        v12 = ++v9;
        if ( v9 >= Size )
          goto LABEL_12;
      }
      v14 = pHandlers->Handlers.Data.Size;
      if ( v14 == 1 )
      {
        Scaleform::ArrayData<Scaleform::Waitable::HandlerStruct,Scaleform::AllocatorGH<Scaleform::Waitable::HandlerStruct,2>,Scaleform::ArrayConstPolicy<0,16,1>>::Resize(
          &pHandlers->Handlers.Data,
          0i64);
      }
      else
      {
        v15 = v14 - v9 - 1;
        v16 = (__int64)&pHandlers->Handlers.Data.Data[v9];
        memmove((void *)v16, (const void *)(v16 + 16), 16 * v15);
        --pHandlers->Handlers.Data.Size;
      }
      v7 = 1;
    }
LABEL_12:
    LeaveCriticalSection(p_cs);
    return (Scaleform::Waitable::HandlerArray *)v7;
  }
  return result;
}

// File Line: 89
// RVA: 0x9A78D0
void __fastcall Scaleform::Waitable::HandlerArray::Release(Scaleform::Waitable::HandlerArray *this)
{
  if ( !_InterlockedDecrement(&this->RefCount.Value) && this )
  {
    DeleteCriticalSection(&this->HandlersLock.cs);
    if ( this->Handlers.Data.Data )
      ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, this);
  }
}

// File Line: 95
// RVA: 0x95DA20
void __fastcall Scaleform::Waitable::HandlerArray::CallWaitHandlers(Scaleform::Waitable::HandlerArray *this)
{
  Scaleform::Lock *p_HandlersLock; // rbx
  unsigned __int64 Size; // rax
  unsigned __int64 v4; // rdi
  __int64 v5; // rsi
  Scaleform::ArrayData<Scaleform::Waitable::HandlerStruct,Scaleform::AllocatorGH<Scaleform::Waitable::HandlerStruct,2>,Scaleform::ArrayConstPolicy<0,16,1> > v6; // [rsp+28h] [rbp-20h] BYREF

  p_HandlersLock = &this->HandlersLock;
  EnterCriticalSection(&this->HandlersLock.cs);
  Size = this->Handlers.Data.Size;
  if ( Size )
  {
    if ( Size == 1 )
    {
      this->Handlers.Data.Data->Handler(this->Handlers.Data.Data->pUserData);
    }
    else
    {
      v4 = 0i64;
      memset(&v6, 0, sizeof(v6));
      Scaleform::ArrayData<Scaleform::Waitable::HandlerStruct,Scaleform::AllocatorGH<Scaleform::Waitable::HandlerStruct,2>,Scaleform::ArrayConstPolicy<0,16,1>>::Append(
        &v6,
        this->Handlers.Data.Data,
        this->Handlers.Data.Size);
      if ( v6.Size )
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
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
    }
  }
  LeaveCriticalSection(&p_HandlersLock->cs);
}

// File Line: 120
// RVA: 0x95DB10
void __fastcall Scaleform::Waitable::CallWaitHandlers(_QWORD *hdata)
{
  Scaleform::Waitable::HandlerArray *v1; // rcx

  v1 = (Scaleform::Waitable::HandlerArray *)hdata[2];
  if ( v1 )
    Scaleform::Waitable::HandlerArray::CallWaitHandlers(v1);
}

// File Line: 127
// RVA: 0x952D30
bool __fastcall Scaleform::Waitable::Acquire(Scaleform::Waitable *this, unsigned int delay)
{
  int v3; // esi
  Scaleform::Waitable **v4; // rbx
  __int64 v5; // rdi
  Scaleform::Waitable **pWaitList; // rcx
  unsigned int v7; // esi
  Scaleform::Waitable *v8; // rdi
  Scaleform::Waitable::HandlerArray *pHandlers; // rax
  _RTL_CRITICAL_SECTION *p_cs; // r14
  Scaleform::ArrayDataBase<Scaleform::Waitable::HandlerStruct,Scaleform::AllocatorGH<Scaleform::Waitable::HandlerStruct,2>,Scaleform::ArrayConstPolicy<0,16,1> > *p_Data; // rdi
  unsigned __int64 v12; // rbx
  unsigned __int64 v13; // r8
  __int64 v14; // rbx
  __int64 v15; // rdx
  bool v16; // zf
  _QWORD *v17; // rdx
  Scaleform::Waitable **v18; // rbx
  __int64 v19; // rdi
  unsigned int v20; // r15d
  int v21; // ebx
  Scaleform::Waitable **v22; // rdi
  __int64 v23; // r14
  Scaleform::Waitable **v24; // rdi
  __int64 Time; // rdx
  unsigned int v26; // edx
  __int64 v27; // rdi
  Scaleform::Waitable *v28; // rbx
  Scaleform::Waitable::HandlerArray *v29; // rax
  _RTL_CRITICAL_SECTION *v30; // r14
  unsigned int v31; // ecx
  Scaleform::Waitable::HandlerArray *v32; // rbx
  unsigned __int64 Size; // rdx
  Scaleform::Waitable::HandlerStruct *Data; // r8
  __int64 v35; // rax
  __int64 v36; // rax
  unsigned __int64 v37; // r8
  unsigned __int64 Capacity; // rax
  __int64 v39; // r8
  __int64 v40; // rcx
  Scaleform::AcquireInterface_AcquireDesc v42; // [rsp+20h] [rbp-79h] BYREF
  Scaleform::Event v43; // [rsp+40h] [rbp-59h] BYREF
  Scaleform::Lock *p_HandlersLock; // [rsp+A0h] [rbp+7h]
  _QWORD *v45; // [rsp+A8h] [rbp+Fh]
  __int64 v46; // [rsp+B0h] [rbp+17h]
  unsigned int TicksMs; // [rsp+100h] [rbp+67h]
  Scaleform::Waitable *v48; // [rsp+110h] [rbp+77h] BYREF
  _QWORD *v49; // [rsp+118h] [rbp+7Fh]

  v46 = -2i64;
  v48 = this;
  v3 = 0;
  v4 = &v48;
  do
  {
    v5 = ((__int64 (__fastcall *)(Scaleform::Waitable *))(*v4)->vfptr[2].__vecDelDtor)(*v4);
    if ( (*(unsigned __int8 (__fastcall **)(__int64))(*(_QWORD *)v5 + 16i64))(v5) )
    {
      (*(void (__fastcall **)(__int64))(*(_QWORD *)v5 + 24i64))(v5);
      return v3 == 0;
    }
    ++v3;
    ++v4;
  }
  while ( !v3 );
  if ( !delay )
  {
    v3 = -1;
    return v3 == 0;
  }
  v43.RefCount = 1;
  v43.pHandlers = 0i64;
  v43.Scaleform::Waitable::Scaleform::RefCountBase<Scaleform::Waitable,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Event::`vftable{for `Scaleform::Waitable};
  v43.Scaleform::AcquireInterface::vfptr = (Scaleform::AcquireInterfaceVtbl *)&Scaleform::Event::`vftable{for `Scaleform::AcquireInterface};
  Scaleform::Mutex::Mutex(&v43.StateMutex, 1, 0);
  Scaleform::WaitCondition::WaitCondition(&v43.StateWaitCondition);
  v43.State = 0;
  v43.Temporary = 0;
  pWaitList = &v48;
  v42.pWaitList = &v48;
  v42.WaitCount = 1;
  v42.pEvent = &v43;
  v42.pAcquireList = 0i64;
  v7 = 0;
  while ( 1 )
  {
    v8 = pWaitList[v7];
    pHandlers = v8->pHandlers;
    if ( !pHandlers )
      break;
    p_cs = &pHandlers->HandlersLock.cs;
    EnterCriticalSection(&pHandlers->HandlersLock.cs);
    p_Data = &v8->pHandlers->Handlers.Data;
    v12 = p_Data->Size + 1;
    if ( v12 >= p_Data->Size )
    {
      if ( v12 <= p_Data->Policy.Capacity )
        goto LABEL_16;
      v13 = v12 + (v12 >> 2);
    }
    else
    {
      if ( v12 >= p_Data->Policy.Capacity >> 1 )
        goto LABEL_16;
      v13 = p_Data->Size + 1;
    }
    Scaleform::ArrayDataBase<Scaleform::Waitable::HandlerStruct,Scaleform::AllocatorGH<Scaleform::Waitable::HandlerStruct,2>,Scaleform::ArrayConstPolicy<0,16,1>>::Reserve(
      p_Data,
      p_Data,
      v13);
LABEL_16:
    p_Data->Size = v12;
    v14 = 16 * v12;
    v15 = (__int64)&p_Data->Data[-1];
    v16 = v14 + v15 == 0;
    v17 = (_QWORD *)(v14 + v15);
    v49 = v17;
    v45 = v17;
    if ( !v16 )
    {
      *v17 = Scaleform::AcquireInterface_OneOfMultipleWaitHandler;
      v17[1] = &v42;
    }
    LeaveCriticalSection(p_cs);
    if ( ++v7 >= v42.WaitCount )
    {
      v3 = 0;
      v18 = &v48;
      do
      {
        v19 = ((__int64 (__fastcall *)(Scaleform::Waitable *))(*v18)->vfptr[2].__vecDelDtor)(*v18);
        if ( (*(unsigned __int8 (__fastcall **)(__int64))(*(_QWORD *)v19 + 16i64))(v19) )
        {
          (*(void (__fastcall **)(__int64))(*(_QWORD *)v19 + 24i64))(v19);
          Scaleform::AcquireInterface_AcquireDesc::RemoveHandlers(
            &v42,
            Scaleform::AcquireInterface_OneOfMultipleWaitHandler);
          Scaleform::Event::~Event(&v43);
          return v3 == 0;
        }
        ++v3;
        ++v18;
      }
      while ( !v3 );
      TicksMs = 0;
      v20 = delay;
      if ( delay != -1 )
        TicksMs = Scaleform::Timer::GetTicksMs();
      v21 = 0;
      v22 = &v48;
      do
      {
        v23 = ((__int64 (__fastcall *)(Scaleform::Waitable *))(*v22)->vfptr[2].__vecDelDtor)(*v22);
        if ( (*(unsigned __int8 (__fastcall **)(__int64))(*(_QWORD *)v23 + 16i64))(v23) )
          goto LABEL_31;
        ++v21;
        ++v22;
      }
      while ( !v21 );
      v21 = -1;
      if ( Scaleform::Event::Wait(&v43, delay) )
      {
LABEL_33:
        v21 = 0;
        v24 = &v48;
        while ( 1 )
        {
          v23 = ((__int64 (__fastcall *)(Scaleform::Waitable *))(*v24)->vfptr[2].__vecDelDtor)(*v24);
          if ( (*(unsigned __int8 (__fastcall **)(__int64))(*(_QWORD *)v23 + 16i64))(v23) )
            break;
          ++v21;
          ++v24;
          if ( v21 )
          {
            v21 = -1;
            if ( delay != -1 )
            {
              Time = timeGetTime();
              if ( TimerOverrideInstance )
                LODWORD(Time) = TimerOverrideInstance->vfptr->GetTicksMs(TimerOverrideInstance, Time);
              v26 = Time - TicksMs;
              if ( v26 >= delay )
                goto LABEL_44;
              v20 = delay - v26;
            }
            if ( Scaleform::Event::Wait(&v43, v20) )
              goto LABEL_33;
            goto LABEL_44;
          }
        }
LABEL_31:
        (*(void (__fastcall **)(__int64))(*(_QWORD *)v23 + 24i64))(v23);
      }
LABEL_44:
      Scaleform::AcquireInterface_AcquireDesc::RemoveHandlers(
        &v42,
        Scaleform::AcquireInterface_OneOfMultipleWaitHandler);
      Scaleform::Event::~Event(&v43);
      v3 = v21;
      return v3 == 0;
    }
    pWaitList = v42.pWaitList;
  }
  if ( v7 )
  {
    v27 = v7;
    do
    {
      --v7;
      v28 = pWaitList[--v27];
      v29 = v28->pHandlers;
      if ( v29 )
      {
        v30 = &v29->HandlersLock.cs;
        p_HandlersLock = &v29->HandlersLock;
        EnterCriticalSection(&v29->HandlersLock.cs);
        v31 = 0;
        v32 = v28->pHandlers;
        Size = v32->Handlers.Data.Size;
        if ( Size )
        {
          Data = v32->Handlers.Data.Data;
          v35 = 0i64;
          while ( 1 )
          {
            v36 = v35;
            if ( Data[v36].Handler == Scaleform::AcquireInterface_OneOfMultipleWaitHandler
              && Data[v36].pUserData == &v42 )
            {
              break;
            }
            v35 = ++v31;
            if ( v31 >= Size )
              goto LABEL_62;
          }
          v37 = v32->Handlers.Data.Size;
          if ( v37 == 1 )
          {
            Capacity = v32->Handlers.Data.Policy.Capacity;
            if ( (Capacity & 0xFFFFFFFFFFFFFFFEui64) != 0 && !Capacity )
            {
              if ( v32->Handlers.Data.Data )
              {
                ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
                v32->Handlers.Data.Data = 0i64;
              }
              v32->Handlers.Data.Policy.Capacity = 0i64;
            }
            v32->Handlers.Data.Size = 0i64;
          }
          else
          {
            v39 = v37 - v31 - 1;
            v40 = (__int64)&v32->Handlers.Data.Data[v31];
            memmove((void *)v40, (const void *)(v40 + 16), 16 * v39);
            --v32->Handlers.Data.Size;
          }
        }
LABEL_62:
        LeaveCriticalSection(v30);
        pWaitList = v42.pWaitList;
      }
    }
    while ( v7 );
  }
  v43.Scaleform::Waitable::Scaleform::RefCountBase<Scaleform::Waitable,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Event::`vftable{for `Scaleform::Waitable};
  v43.Scaleform::AcquireInterface::vfptr = (Scaleform::AcquireInterfaceVtbl *)&Scaleform::Event::`vftable{for `Scaleform::AcquireInterface};
  Scaleform::WaitCondition::~WaitCondition(&v43.StateWaitCondition);
  Scaleform::Mutex::~Mutex(&v43.StateMutex);
  v43.Scaleform::AcquireInterface::vfptr = (Scaleform::AcquireInterfaceVtbl *)&Scaleform::AcquireInterface::`vftable;
  v43.Scaleform::Waitable::Scaleform::RefCountBase<Scaleform::Waitable,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Waitable::`vftable;
  if ( v43.pHandlers )
    Scaleform::Waitable::HandlerArray::Release(v43.pHandlers);
  v43.Scaleform::Waitable::Scaleform::RefCountBase<Scaleform::Waitable,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  v3 = 0;
  return v3 == 0;
}

// File Line: 145
// RVA: 0x9C2700
void __fastcall Scaleform::Waitable_SingleWaitHandler(Scaleform::Event **hdata)
{
  if ( ((unsigned __int8 (__fastcall *)(Scaleform::Event *))(*hdata)->Scaleform::Waitable::Scaleform::RefCountBase<Scaleform::Waitable,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr[1].__vecDelDtor)(*hdata) )
    Scaleform::Event::PulseEvent(hdata[1]);
}

// File Line: 154
// RVA: 0x9C2410
char __fastcall Scaleform::Waitable::Wait(Scaleform::Waitable *this, unsigned int delay)
{
  unsigned int TicksMs; // r15d
  char v6; // r14
  unsigned int v7; // edi
  __int64 Time; // rdx
  unsigned int v9; // edx
  __int64 pdata; // [rsp+8h] [rbp-41h] BYREF
  Scaleform::Event v11; // [rsp+20h] [rbp-29h] BYREF

  if ( ((unsigned __int8 (__fastcall *)(Scaleform::Waitable *))this->vfptr[1].__vecDelDtor)(this) )
    return 1;
  if ( !delay )
    return 0;
  v11.RefCount = 1;
  TicksMs = 0;
  v11.pHandlers = 0i64;
  v11.Scaleform::AcquireInterface::vfptr = (Scaleform::AcquireInterfaceVtbl *)&Scaleform::Event::`vftable{for `Scaleform::AcquireInterface};
  Scaleform::Mutex::Mutex(&v11.StateMutex, 1, 0);
  Scaleform::WaitCondition::WaitCondition(&v11.StateWaitCondition);
  v11.State = 0;
  v11.Temporary = 0;
  if ( Scaleform::Waitable::AddWaitHandler(this, Scaleform::Waitable_SingleWaitHandler, &pdata) )
  {
    if ( ((unsigned __int8 (__fastcall *)(Scaleform::Waitable *))this->vfptr[1].__vecDelDtor)(this) )
    {
      Scaleform::Waitable::RemoveWaitHandler(this, Scaleform::Waitable_SingleWaitHandler, &pdata);
      v6 = 1;
    }
    else
    {
      v6 = 0;
      v7 = delay;
      if ( delay != -1 )
        TicksMs = Scaleform::Timer::GetTicksMs();
      if ( Scaleform::Event::Wait(&v11, delay) )
      {
        while ( !((unsigned __int8 (__fastcall *)(Scaleform::Waitable *))this->vfptr[1].__vecDelDtor)(this) )
        {
          if ( delay != -1 )
          {
            Time = timeGetTime();
            if ( TimerOverrideInstance )
              LODWORD(Time) = TimerOverrideInstance->vfptr->GetTicksMs(TimerOverrideInstance, Time);
            v9 = Time - TicksMs;
            if ( v9 >= delay )
              goto LABEL_21;
            v7 = delay - v9;
          }
          if ( !Scaleform::Event::Wait(&v11, v7) )
            goto LABEL_21;
        }
        v6 = 1;
      }
LABEL_21:
      Scaleform::Waitable::RemoveWaitHandler(this, Scaleform::Waitable_SingleWaitHandler, &pdata);
    }
  }
  else
  {
    v6 = 0;
  }
  v11.Scaleform::AcquireInterface::vfptr = (Scaleform::AcquireInterfaceVtbl *)&Scaleform::Event::`vftable{for `Scaleform::AcquireInterface};
  Scaleform::WaitCondition::~WaitCondition(&v11.StateWaitCondition);
  Scaleform::Mutex::~Mutex(&v11.StateMutex);
  v11.Scaleform::AcquireInterface::vfptr = (Scaleform::AcquireInterfaceVtbl *)&Scaleform::AcquireInterface::`vftable;
  v11.Scaleform::Waitable::Scaleform::RefCountBase<Scaleform::Waitable,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Waitable::`vftable;
  if ( v11.pHandlers )
    Scaleform::Waitable::HandlerArray::Release(v11.pHandlers);
  return v6;
}

// File Line: 215
// RVA: 0x97FC10
Scaleform::DefaultAcquireInterface *__fastcall Scaleform::DefaultAcquireInterface::GetDefaultAcquireInterface()
{
  if ( (_S2_12 & 1) == 0 )
  {
    _S2_12 |= 1u;
    stru_1424523F8.vfptr = (Scaleform::AcquireInterfaceVtbl *)&Scaleform::DefaultAcquireInterface::`vftable;
    atexit(Scaleform::DefaultAcquireInterface::GetDefaultAcquireInterface_::_2_::_dynamic_atexit_destructor_for__di__);
  }
  return &stru_1424523F8;
}

// File Line: 296
// RVA: 0x948CD0
void __fastcall Scaleform::AcquireInterface_AcquireList::~AcquireInterface_AcquireList(
        Scaleform::AcquireInterface_AcquireList *this)
{
  if ( this->pList != this->StaticList )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
}

// File Line: 321
// RVA: 0x9A9CC0
void __fastcall Scaleform::AcquireInterface_AcquireDesc::RemoveHandlers(
        Scaleform::AcquireInterface_AcquireDesc *this,
        void (__fastcall *handler)(void *))
{
  __int64 i; // rdi
  Scaleform::Waitable *v5; // rsi
  Scaleform::Waitable::HandlerArray *pHandlers; // rax
  _RTL_CRITICAL_SECTION *p_cs; // rbp
  unsigned int v8; // ecx
  Scaleform::Waitable::HandlerArray *v9; // rsi
  unsigned __int64 Size; // rdx
  __int64 v11; // rax
  Scaleform::Waitable::HandlerStruct *Data; // r8
  __int64 v13; // rax
  unsigned __int64 v14; // r8
  __int64 v15; // r8
  __int64 v16; // rcx

  for ( i = 0i64; (unsigned int)i < this->WaitCount; i = (unsigned int)(i + 1) )
  {
    v5 = this->pWaitList[i];
    pHandlers = v5->pHandlers;
    if ( pHandlers )
    {
      p_cs = &pHandlers->HandlersLock.cs;
      EnterCriticalSection(&pHandlers->HandlersLock.cs);
      v8 = 0;
      v9 = v5->pHandlers;
      Size = v9->Handlers.Data.Size;
      if ( Size )
      {
        v11 = 0i64;
        Data = v9->Handlers.Data.Data;
        while ( 1 )
        {
          v13 = v11;
          if ( Data[v13].Handler == handler && Data[v13].pUserData == this )
            break;
          v11 = ++v8;
          if ( v8 >= Size )
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
          v16 = (__int64)&v9->Handlers.Data.Data[v8];
          memmove((void *)v16, (const void *)(v16 + 16), 16 * v15);
          --v9->Handlers.Data.Size;
        }
      }
LABEL_12:
      LeaveCriticalSection(p_cs);
    }
  }
}

// File Line: 329
// RVA: 0x9531F0
void __fastcall Scaleform::AcquireInterface_MultipleWaitHandler(_QWORD *pdata)
{
  Scaleform::Waitable::HandlerArray *v2; // rbx
  unsigned int v3; // edi
  __int64 v4; // rcx
  __int64 v5; // rdi
  volatile signed __int32 *v6; // rax
  Scaleform::Waitable::HandlerArray *v7; // [rsp+40h] [rbp+8h]

  v2 = 0i64;
  v3 = 0;
  if ( *((_DWORD *)pdata + 2) )
  {
    while ( 1 )
    {
      v4 = *(_QWORD *)(pdata[3] + 8i64 * v3);
      if ( !(*(unsigned __int8 (__fastcall **)(__int64))(*(_QWORD *)v4 + 8i64))(v4) )
        break;
      if ( ++v3 >= *((_DWORD *)pdata + 2) )
        goto LABEL_4;
    }
  }
  else
  {
LABEL_4:
    v5 = pdata[2];
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
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v7);
    }
  }
}

// File Line: 341
// RVA: 0x953410
char __fastcall Scaleform::AcquireInterface_TryAcquireAll(
        Scaleform::AcquireInterface **pacquireList,
        unsigned int waitCount)
{
  __int64 v2; // rbx
  __int64 v3; // rbp
  Scaleform::AcquireInterface **v4; // rdi
  Scaleform::AcquireInterface **v5; // rsi
  __int64 v6; // rbx
  Scaleform::AcquireInterface **v8; // rdi
  __int64 v9; // rcx

  v2 = 0i64;
  v3 = waitCount;
  v4 = pacquireList;
  if ( waitCount )
  {
    v5 = pacquireList;
    do
    {
      if ( !(*v5)->vfptr->TryAcquire(*v5) )
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
        (*v4)->vfptr->TryAcquireCommit(*v4);
        ++v4;
        --v6;
      }
      while ( v6 );
    }
    return 1;
  }
  else
  {
    if ( (_DWORD)v2 )
    {
      v8 = &v4[v2];
      do
      {
        v9 = (__int64)*--v8;
        (*(void (__fastcall **)(__int64))(*(_QWORD *)v9 + 32i64))(v9);
        LODWORD(v2) = v2 - 1;
      }
      while ( (_DWORD)v2 );
    }
    return 0;
  }
}

// File Line: 365
// RVA: 0x953530
__int64 __fastcall Scaleform::AcquireInterface::AcquireMultipleObjects(
        Scaleform::Waitable **pwaitList,
        unsigned int waitCount,
        unsigned int delay)
{
  __int64 v4; // r12
  Scaleform::AcquireInterface **v6; // rax
  unsigned int TicksMs; // r13d
  __int64 v8; // rdi
  __int64 v9; // rsi
  unsigned __int8 v10; // di
  Scaleform::AcquireInterface **v11; // rcx
  unsigned int v12; // esi
  Scaleform::Waitable *v13; // rdi
  Scaleform::Waitable::HandlerArray *pHandlers; // rax
  _RTL_CRITICAL_SECTION *p_cs; // r15
  Scaleform::ArrayDataBase<Scaleform::Waitable::HandlerStruct,Scaleform::AllocatorGH<Scaleform::Waitable::HandlerStruct,2>,Scaleform::ArrayConstPolicy<0,16,1> > *p_Data; // rdi
  unsigned __int64 v17; // rbx
  unsigned __int64 v18; // r8
  __int64 v19; // rbx
  __int64 v20; // rdx
  bool v21; // zf
  Scaleform::AcquireInterfaceVtbl *v22; // rdx
  __int64 v23; // r14
  Scaleform::Waitable *v24; // rdi
  Scaleform::Waitable::HandlerArray *v25; // rax
  _RTL_CRITICAL_SECTION *v26; // r15
  unsigned int v27; // ecx
  Scaleform::Waitable::HandlerArray *v28; // rbx
  unsigned __int64 Size; // rdx
  Scaleform::Waitable::HandlerStruct *Data; // r8
  __int64 v31; // rax
  __int64 v32; // rax
  unsigned __int64 v33; // r8
  unsigned __int64 Capacity; // rax
  __int64 v35; // r8
  __int64 v36; // rcx
  unsigned int v37; // ebx
  __int64 Time; // rdx
  unsigned int v39; // edx
  Scaleform::AcquireInterface_AcquireDesc v41; // [rsp+20h] [rbp-B8h] BYREF
  Scaleform::Event v42; // [rsp+40h] [rbp-98h] BYREF
  Scaleform::AcquireInterface **pacquireList; // [rsp+98h] [rbp-40h]
  char v44[224]; // [rsp+A0h] [rbp-38h] BYREF
  Scaleform::Lock *p_HandlersLock; // [rsp+1F0h] [rbp+118h]

  v42.StateWaitCondition.pImpl = (Scaleform::WaitConditionImpl *)-2i64;
  v4 = waitCount;
  if ( waitCount <= 0x20 )
    v6 = (Scaleform::AcquireInterface **)v44;
  else
    v6 = (Scaleform::AcquireInterface **)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(
                                           Scaleform::Memory::pGlobalHeap,
                                           8i64 * waitCount,
                                           0i64);
  pacquireList = v6;
  TicksMs = 0;
  if ( (_DWORD)v4 )
  {
    v8 = 0i64;
    v9 = v4;
    do
    {
      pacquireList[v8] = (Scaleform::AcquireInterface *)((__int64 (__fastcall *)(Scaleform::Waitable *))pwaitList[v8]->vfptr[2].__vecDelDtor)(pwaitList[v8]);
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
  if ( !delay )
  {
    v10 = 0;
    goto LABEL_62;
  }
  v42.RefCount = 1;
  v42.pHandlers = 0i64;
  v42.Scaleform::Waitable::Scaleform::RefCountBase<Scaleform::Waitable,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Event::`vftable{for `Scaleform::Waitable};
  v42.Scaleform::AcquireInterface::vfptr = (Scaleform::AcquireInterfaceVtbl *)&Scaleform::Event::`vftable{for `Scaleform::AcquireInterface};
  Scaleform::Mutex::Mutex(&v42.StateMutex, 1, 0);
  Scaleform::WaitCondition::WaitCondition((Scaleform::WaitCondition *)&v42.StateMutex);
  v42.State = 0;
  v42.Temporary = 0;
  v41.pWaitList = pwaitList;
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
      Scaleform::AcquireInterface_AcquireDesc::RemoveHandlers(
        &v41,
        (void (__fastcall *)(void *))Scaleform::AcquireInterface_MultipleWaitHandler);
      v10 = 1;
    }
    else
    {
      v10 = 0;
      v37 = delay;
      if ( delay != -1 )
        TicksMs = Scaleform::Timer::GetTicksMs();
      if ( Scaleform::Event::Wait(&v42, delay) )
      {
        while ( !Scaleform::AcquireInterface_TryAcquireAll(pacquireList, v4) )
        {
          if ( delay != -1 )
          {
            Time = timeGetTime();
            if ( TimerOverrideInstance )
              LODWORD(Time) = TimerOverrideInstance->vfptr->GetTicksMs(TimerOverrideInstance, Time);
            v39 = Time - TicksMs;
            if ( v39 >= delay )
              goto LABEL_58;
            v37 = delay - v39;
          }
          if ( !Scaleform::Event::Wait(&v42, v37) )
            goto LABEL_58;
        }
        v10 = 1;
      }
LABEL_58:
      Scaleform::AcquireInterface_AcquireDesc::RemoveHandlers(
        &v41,
        (void (__fastcall *)(void *))Scaleform::AcquireInterface_MultipleWaitHandler);
    }
    goto LABEL_59;
  }
  while ( 1 )
  {
    v13 = pwaitList[v12];
    pHandlers = v13->pHandlers;
    if ( !pHandlers )
      break;
    p_cs = &pHandlers->HandlersLock.cs;
    p_HandlersLock = &pHandlers->HandlersLock;
    EnterCriticalSection(&pHandlers->HandlersLock.cs);
    p_Data = &v13->pHandlers->Handlers.Data;
    v17 = p_Data->Size + 1;
    if ( v17 >= p_Data->Size )
    {
      if ( v17 <= p_Data->Policy.Capacity )
        goto LABEL_19;
      v18 = v17 + (v17 >> 2);
    }
    else
    {
      if ( v17 >= p_Data->Policy.Capacity >> 1 )
        goto LABEL_19;
      v18 = p_Data->Size + 1;
    }
    Scaleform::ArrayDataBase<Scaleform::Waitable::HandlerStruct,Scaleform::AllocatorGH<Scaleform::Waitable::HandlerStruct,2>,Scaleform::ArrayConstPolicy<0,16,1>>::Reserve(
      p_Data,
      p_Data,
      v18);
LABEL_19:
    p_Data->Size = v17;
    v19 = 16 * v17;
    v20 = (__int64)&p_Data->Data[-1];
    v21 = v19 + v20 == 0;
    v22 = (Scaleform::AcquireInterfaceVtbl *)(v19 + v20);
    v42.StateMutex.vfptr = v22;
    v42.StateMutex.pImpl = (Scaleform::MutexImpl *)v22;
    if ( !v21 )
    {
      v22->__vecDelDtor = (void *(__fastcall *)(Scaleform::AcquireInterface *, unsigned int))Scaleform::AcquireInterface_MultipleWaitHandler;
      v22->CanAcquire = (bool (__fastcall *)(Scaleform::AcquireInterface *))&v41;
    }
    LeaveCriticalSection(p_cs);
    if ( ++v12 >= v41.WaitCount )
    {
      v11 = pacquireList;
      goto LABEL_44;
    }
    pwaitList = v41.pWaitList;
  }
  if ( v12 )
  {
    v23 = v12;
    do
    {
      --v12;
      v24 = pwaitList[--v23];
      v25 = v24->pHandlers;
      if ( v25 )
      {
        v26 = &v25->HandlersLock.cs;
        v42.StateMutex.pHandlers = (Scaleform::Waitable::HandlerArray *)&v25->HandlersLock;
        EnterCriticalSection(&v25->HandlersLock.cs);
        v27 = 0;
        v28 = v24->pHandlers;
        Size = v28->Handlers.Data.Size;
        if ( Size )
        {
          Data = v28->Handlers.Data.Data;
          v31 = 0i64;
          while ( 1 )
          {
            v32 = v31;
            if ( (void (__fastcall *)(_QWORD *))Data[v32].Handler == Scaleform::AcquireInterface_MultipleWaitHandler
              && Data[v32].pUserData == &v41 )
            {
              break;
            }
            v31 = ++v27;
            if ( v27 >= Size )
              goto LABEL_41;
          }
          v33 = v28->Handlers.Data.Size;
          if ( v33 == 1 )
          {
            Capacity = v28->Handlers.Data.Policy.Capacity;
            if ( (Capacity & 0xFFFFFFFFFFFFFFFEui64) != 0 && !Capacity )
            {
              if ( v28->Handlers.Data.Data )
              {
                ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
                v28->Handlers.Data.Data = 0i64;
              }
              v28->Handlers.Data.Policy.Capacity = 0i64;
            }
            v28->Handlers.Data.Size = 0i64;
          }
          else
          {
            v35 = v33 - v27 - 1;
            v36 = (__int64)&v28->Handlers.Data.Data[v27];
            memmove((void *)v36, (const void *)(v36 + 16), 16 * v35);
            --v28->Handlers.Data.Size;
          }
        }
LABEL_41:
        LeaveCriticalSection(v26);
        pwaitList = v41.pWaitList;
      }
    }
    while ( v12 );
  }
  v10 = 0;
LABEL_59:
  v42.Scaleform::Waitable::Scaleform::RefCountBase<Scaleform::Waitable,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Event::`vftable{for `Scaleform::Waitable};
  v42.Scaleform::AcquireInterface::vfptr = (Scaleform::AcquireInterfaceVtbl *)&Scaleform::Event::`vftable{for `Scaleform::AcquireInterface};
  Scaleform::WaitCondition::~WaitCondition((Scaleform::WaitCondition *)&v42.StateMutex);
  Scaleform::Mutex::~Mutex(&v42.StateMutex);
  v42.Scaleform::AcquireInterface::vfptr = (Scaleform::AcquireInterfaceVtbl *)&Scaleform::AcquireInterface::`vftable;
  v42.Scaleform::Waitable::Scaleform::RefCountBase<Scaleform::Waitable,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Waitable::`vftable;
  if ( v42.pHandlers )
    Scaleform::Waitable::HandlerArray::Release(v42.pHandlers);
  v42.Scaleform::Waitable::Scaleform::RefCountBase<Scaleform::Waitable,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
LABEL_62:
  if ( pacquireList != (Scaleform::AcquireInterface **)v44 )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  return v10;
}

// File Line: 425
// RVA: 0x953300
void __fastcall Scaleform::AcquireInterface_OneOfMultipleWaitHandler(_DWORD *pdata)
{
  Scaleform::Waitable::HandlerArray *v2; // rbx
  unsigned int v3; // edi
  __int64 v4; // rcx
  __int64 v5; // rax
  __int64 v6; // rdi
  volatile signed __int32 *v7; // rax
  Scaleform::Waitable::HandlerArray *v8; // [rsp+40h] [rbp+8h]

  v2 = 0i64;
  v3 = 0;
  if ( pdata[2] )
  {
    while ( 1 )
    {
      v4 = *(_QWORD *)(*(_QWORD *)pdata + 8i64 * v3);
      v5 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v4 + 16i64))(v4);
      if ( (*(unsigned __int8 (__fastcall **)(__int64))(*(_QWORD *)v5 + 8i64))(v5) )
        break;
      if ( ++v3 >= pdata[2] )
        return;
    }
    v6 = *((_QWORD *)pdata + 2);
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
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v8);
    }
  }
}

// File Line: 444
// RVA: 0x9534C0
__int64 __fastcall Scaleform::AcquireInterface_TryAcquireOne(Scaleform::Waitable **pwaitList, unsigned int waitCount)
{
  unsigned int v2; // ebx
  __int64 v5; // rsi

  v2 = 0;
  if ( !waitCount )
    return 0xFFFFFFFFi64;
  while ( 1 )
  {
    v5 = ((__int64 (__fastcall *)(_QWORD))(*pwaitList)->vfptr[2].__vecDelDtor)(*pwaitList);
    if ( (*(unsigned __int8 (__fastcall **)(__int64))(*(_QWORD *)v5 + 16i64))(v5) )
      break;
    ++v2;
    ++pwaitList;
    if ( v2 >= waitCount )
      return 0xFFFFFFFFi64;
  }
  (*(void (__fastcall **)(__int64))(*(_QWORD *)v5 + 24i64))(v5);
  return v2;
}

// File Line: 464
// RVA: 0x9539C0
__int64 __fastcall Scaleform::AcquireInterface::AcquireOneOfMultipleObjects(
        Scaleform::Waitable **pwaitList,
        unsigned int waitCount,
        unsigned int delay)
{
  Scaleform::Waitable **v5; // r12
  unsigned int TicksMs; // r15d
  unsigned int v7; // ebx
  Scaleform::Waitable **v8; // rdi
  __int64 v9; // rsi
  Scaleform::Waitable **v11; // rcx
  unsigned int v12; // esi
  Scaleform::Waitable *v13; // rdi
  Scaleform::Waitable::HandlerArray *pHandlers; // rax
  _RTL_CRITICAL_SECTION *p_cs; // r12
  Scaleform::ArrayDataBase<Scaleform::Waitable::HandlerStruct,Scaleform::AllocatorGH<Scaleform::Waitable::HandlerStruct,2>,Scaleform::ArrayConstPolicy<0,16,1> > *p_Data; // rdi
  unsigned __int64 v17; // rbx
  unsigned __int64 v18; // r8
  __int64 v19; // rbx
  __int64 v20; // rdx
  bool v21; // zf
  _QWORD *v22; // rdx
  __int64 v23; // rdi
  Scaleform::Waitable *v24; // rbx
  Scaleform::Waitable::HandlerArray *v25; // rax
  _RTL_CRITICAL_SECTION *v26; // r14
  unsigned int v27; // ecx
  Scaleform::Waitable::HandlerArray *v28; // rbx
  unsigned __int64 Size; // rdx
  Scaleform::Waitable::HandlerStruct *Data; // r8
  __int64 v31; // rax
  __int64 v32; // rax
  unsigned __int64 v33; // r8
  unsigned __int64 Capacity; // rax
  __int64 v35; // r8
  __int64 v36; // rcx
  unsigned int v37; // ebx
  unsigned int v38; // ebx
  unsigned int v39; // edi
  __int64 Time; // rdx
  unsigned int v41; // edx
  Scaleform::AcquireInterface_AcquireDesc v42; // [rsp+20h] [rbp-79h] BYREF
  Scaleform::Event v43; // [rsp+40h] [rbp-59h] BYREF
  _QWORD *v44; // [rsp+A0h] [rbp+7h]
  _QWORD *v45; // [rsp+A8h] [rbp+Fh]
  Scaleform::Lock *p_HandlersLock; // [rsp+B0h] [rbp+17h]
  __int64 v47; // [rsp+B8h] [rbp+1Fh]

  v47 = -2i64;
  v5 = pwaitList;
  TicksMs = 0;
  v7 = 0;
  if ( waitCount )
  {
    v8 = pwaitList;
    while ( 1 )
    {
      v9 = ((__int64 (__fastcall *)(Scaleform::Waitable *))(*v8)->vfptr[2].__vecDelDtor)(*v8);
      if ( (*(unsigned __int8 (__fastcall **)(__int64))(*(_QWORD *)v9 + 16i64))(v9) )
        break;
      ++v7;
      ++v8;
      if ( v7 >= waitCount )
        goto LABEL_8;
    }
    (*(void (__fastcall **)(__int64))(*(_QWORD *)v9 + 24i64))(v9);
    if ( v7 != -1 )
      return v7;
  }
LABEL_8:
  if ( !delay )
    return 0xFFFFFFFFi64;
  v43.RefCount = 1;
  v43.pHandlers = 0i64;
  v43.Scaleform::Waitable::Scaleform::RefCountBase<Scaleform::Waitable,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Event::`vftable{for `Scaleform::Waitable};
  v43.Scaleform::AcquireInterface::vfptr = (Scaleform::AcquireInterfaceVtbl *)&Scaleform::Event::`vftable{for `Scaleform::AcquireInterface};
  Scaleform::Mutex::Mutex(&v43.StateMutex, 1, 0);
  Scaleform::WaitCondition::WaitCondition(&v43.StateWaitCondition);
  v43.State = 0;
  v43.Temporary = 0;
  v11 = v5;
  v42.pWaitList = v5;
  v42.WaitCount = waitCount;
  v42.pEvent = &v43;
  v42.pAcquireList = 0i64;
  v12 = 0;
  if ( !waitCount )
  {
LABEL_43:
    v37 = Scaleform::AcquireInterface_TryAcquireOne(v5, waitCount);
    if ( v37 == -1 )
    {
      v38 = delay;
      if ( delay != -1 )
        TicksMs = Scaleform::Timer::GetTicksMs();
      v39 = Scaleform::AcquireInterface_TryAcquireOne(v5, waitCount);
      if ( v39 == -1 && Scaleform::Event::Wait(&v43, delay) )
      {
        do
        {
          v39 = Scaleform::AcquireInterface_TryAcquireOne(v5, waitCount);
          if ( v39 != -1 )
            break;
          if ( delay != -1 )
          {
            Time = timeGetTime();
            if ( TimerOverrideInstance )
              LODWORD(Time) = TimerOverrideInstance->vfptr->GetTicksMs(TimerOverrideInstance, Time);
            v41 = Time - TicksMs;
            if ( v41 >= delay )
              break;
            v38 = delay - v41;
          }
        }
        while ( Scaleform::Event::Wait(&v43, v38) );
      }
      Scaleform::AcquireInterface_AcquireDesc::RemoveHandlers(
        &v42,
        (void (__fastcall *)(void *))Scaleform::AcquireInterface_OneOfMultipleWaitHandler);
      TicksMs = v39;
    }
    else
    {
      Scaleform::AcquireInterface_AcquireDesc::RemoveHandlers(
        &v42,
        (void (__fastcall *)(void *))Scaleform::AcquireInterface_OneOfMultipleWaitHandler);
      TicksMs = v37;
    }
    goto LABEL_57;
  }
  while ( 1 )
  {
    v13 = v11[v12];
    pHandlers = v13->pHandlers;
    if ( !pHandlers )
      break;
    p_cs = &pHandlers->HandlersLock.cs;
    EnterCriticalSection(&pHandlers->HandlersLock.cs);
    p_Data = &v13->pHandlers->Handlers.Data;
    v17 = p_Data->Size + 1;
    if ( v17 >= p_Data->Size )
    {
      if ( v17 <= p_Data->Policy.Capacity )
        goto LABEL_18;
      v18 = v17 + (v17 >> 2);
    }
    else
    {
      if ( v17 >= p_Data->Policy.Capacity >> 1 )
        goto LABEL_18;
      v18 = p_Data->Size + 1;
    }
    Scaleform::ArrayDataBase<Scaleform::Waitable::HandlerStruct,Scaleform::AllocatorGH<Scaleform::Waitable::HandlerStruct,2>,Scaleform::ArrayConstPolicy<0,16,1>>::Reserve(
      p_Data,
      p_Data,
      v18);
LABEL_18:
    p_Data->Size = v17;
    v19 = 16 * v17;
    v20 = (__int64)&p_Data->Data[-1];
    v21 = v19 + v20 == 0;
    v22 = (_QWORD *)(v19 + v20);
    v45 = v22;
    v44 = v22;
    if ( !v21 )
    {
      *v22 = Scaleform::AcquireInterface_OneOfMultipleWaitHandler;
      v22[1] = &v42;
    }
    LeaveCriticalSection(p_cs);
    if ( ++v12 >= v42.WaitCount )
    {
      v5 = pwaitList;
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
      v24 = v11[--v23];
      v25 = v24->pHandlers;
      if ( v25 )
      {
        v26 = &v25->HandlersLock.cs;
        p_HandlersLock = &v25->HandlersLock;
        EnterCriticalSection(&v25->HandlersLock.cs);
        v27 = 0;
        v28 = v24->pHandlers;
        Size = v28->Handlers.Data.Size;
        if ( Size )
        {
          Data = v28->Handlers.Data.Data;
          v31 = 0i64;
          while ( 1 )
          {
            v32 = v31;
            if ( (void (__fastcall *)(_DWORD *))Data[v32].Handler == Scaleform::AcquireInterface_OneOfMultipleWaitHandler
              && Data[v32].pUserData == &v42 )
            {
              break;
            }
            v31 = ++v27;
            if ( v27 >= Size )
              goto LABEL_39;
          }
          v33 = v28->Handlers.Data.Size;
          if ( v33 == 1 )
          {
            Capacity = v28->Handlers.Data.Policy.Capacity;
            if ( (Capacity & 0xFFFFFFFFFFFFFFFEui64) != 0 && !Capacity )
            {
              if ( v28->Handlers.Data.Data )
              {
                ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
                v28->Handlers.Data.Data = 0i64;
              }
              v28->Handlers.Data.Policy.Capacity = 0i64;
            }
            v28->Handlers.Data.Size = 0i64;
          }
          else
          {
            v35 = v33 - v27 - 1;
            v36 = (__int64)&v28->Handlers.Data.Data[v27];
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
  v43.Scaleform::Waitable::Scaleform::RefCountBase<Scaleform::Waitable,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Event::`vftable{for `Scaleform::Waitable};
  v43.Scaleform::AcquireInterface::vfptr = (Scaleform::AcquireInterfaceVtbl *)&Scaleform::Event::`vftable{for `Scaleform::AcquireInterface};
  Scaleform::WaitCondition::~WaitCondition(&v43.StateWaitCondition);
  Scaleform::Mutex::~Mutex(&v43.StateMutex);
  v43.Scaleform::AcquireInterface::vfptr = (Scaleform::AcquireInterfaceVtbl *)&Scaleform::AcquireInterface::`vftable;
  v43.Scaleform::Waitable::Scaleform::RefCountBase<Scaleform::Waitable,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Waitable::`vftable;
  if ( v43.pHandlers )
    Scaleform::Waitable::HandlerArray::Release(v43.pHandlers);
  return TicksMs;
}

// File Line: 529
// RVA: 0x93B8C0
void __fastcall Scaleform::Event::Event(Scaleform::Event *this, volatile bool setInitially, bool multiWait)
{
  Scaleform::Waitable::Waitable(this, multiWait);
  this->Scaleform::AcquireInterface::vfptr = (Scaleform::AcquireInterfaceVtbl *)&Scaleform::AcquireInterface::`vftable;
  this->Scaleform::Waitable::Scaleform::RefCountBase<Scaleform::Waitable,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Event::`vftable{for `Scaleform::Waitable};
  this->Scaleform::AcquireInterface::vfptr = (Scaleform::AcquireInterfaceVtbl *)&Scaleform::Event::`vftable{for `Scaleform::AcquireInterface};
  Scaleform::Mutex::Mutex(&this->StateMutex, 1, 0);
  Scaleform::WaitCondition::WaitCondition(&this->StateWaitCondition);
  this->State = setInitially;
  this->Temporary = 0;
}

// File Line: 536
// RVA: 0x949F70
void __fastcall Scaleform::Event::~Event(Scaleform::Event *this)
{
  Scaleform::Waitable::HandlerArray *pHandlers; // rcx

  this->Scaleform::Waitable::Scaleform::RefCountBase<Scaleform::Waitable,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Event::`vftable{for `Scaleform::Waitable};
  this->Scaleform::AcquireInterface::vfptr = (Scaleform::AcquireInterfaceVtbl *)&Scaleform::Event::`vftable{for `Scaleform::AcquireInterface};
  Scaleform::WaitCondition::~WaitCondition(&this->StateWaitCondition);
  Scaleform::Mutex::~Mutex(&this->StateMutex);
  this->Scaleform::AcquireInterface::vfptr = (Scaleform::AcquireInterfaceVtbl *)&Scaleform::AcquireInterface::`vftable;
  this->Scaleform::Waitable::Scaleform::RefCountBase<Scaleform::Waitable,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Waitable::`vftable;
  pHandlers = this->pHandlers;
  if ( pHandlers )
    Scaleform::Waitable::HandlerArray::Release(pHandlers);
  this->Scaleform::Waitable::Scaleform::RefCountBase<Scaleform::Waitable,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
}

// File Line: 541
// RVA: 0x9C2360
_BOOL8 __fastcall Scaleform::Event::Wait(Scaleform::Event *this, unsigned int delay)
{
  Scaleform::Mutex *p_StateMutex; // rbx
  volatile bool State; // al
  volatile bool v6; // bl
  Scaleform::Mutex *v8; // [rsp+40h] [rbp+8h]

  p_StateMutex = &this->StateMutex;
  v8 = &this->StateMutex;
  Scaleform::Mutex::DoLock(&this->StateMutex);
  if ( delay )
  {
    State = this->State;
    if ( delay == -1 )
    {
      if ( !State )
      {
        do
          Scaleform::WaitCondition::Wait(&this->StateWaitCondition, p_StateMutex, 0xFFFFFFFF);
        while ( !this->State );
      }
    }
    else if ( !State )
    {
      Scaleform::WaitCondition::Wait(&this->StateWaitCondition, p_StateMutex, delay);
    }
  }
  v6 = this->State;
  if ( this->Temporary )
  {
    this->Temporary = 0;
    this->State = 0;
  }
  Scaleform::Mutex::Unlock(v8);
  return v6;
}

// File Line: 574
// RVA: 0x9AF260
void __fastcall Scaleform::Event::SetEvent(Scaleform::Event *this)
{
  Scaleform::Waitable::HandlerArray *v2; // rbx
  Scaleform::Waitable::HandlerArray *pHandlers; // rax

  Scaleform::Mutex::DoLock(&this->StateMutex);
  this->State = 1;
  this->Temporary = 0;
  Scaleform::WaitCondition::NotifyAll(&this->StateWaitCondition);
  v2 = 0i64;
  pHandlers = this->pHandlers;
  if ( pHandlers )
  {
    v2 = this->pHandlers;
    _InterlockedExchangeAdd(&pHandlers->RefCount.Value, 1u);
  }
  Scaleform::Mutex::Unlock(&this->StateMutex);
  if ( v2 )
    Scaleform::Waitable::HandlerArray::CallWaitHandlers(v2);
  if ( v2 )
    Scaleform::Waitable::HandlerArray::Release(v2);
}

// File Line: 589
// RVA: 0x9ABA40
void __fastcall Scaleform::Event::ResetEvent(Scaleform::Event *this)
{
  Scaleform::Mutex *p_StateMutex; // rbx

  p_StateMutex = &this->StateMutex;
  Scaleform::Mutex::DoLock(&this->StateMutex);
  this->State = 0;
  this->Temporary = 0;
  Scaleform::Mutex::Unlock(p_StateMutex);
}

// File Line: 599
// RVA: 0x9A1DC0
void __fastcall Scaleform::Event::PulseEvent(Scaleform::Event *this)
{
  Scaleform::Waitable::HandlerArray *v2; // rbx
  Scaleform::Waitable::HandlerArray *pHandlers; // rax

  Scaleform::Mutex::DoLock(&this->StateMutex);
  this->State = 1;
  this->Temporary = 1;
  Scaleform::WaitCondition::NotifyAll(&this->StateWaitCondition);
  v2 = 0i64;
  pHandlers = this->pHandlers;
  if ( pHandlers )
  {
    v2 = this->pHandlers;
    _InterlockedExchangeAdd(&pHandlers->RefCount.Value, 1u);
  }
  Scaleform::Mutex::Unlock(&this->StateMutex);
  if ( v2 )
    Scaleform::Waitable::HandlerArray::CallWaitHandlers(v2);
  if ( v2 )
    Scaleform::Waitable::HandlerArray::Release(v2);
}

// File Line: 613
// RVA: 0x997D70
_BOOL8 __fastcall Scaleform::Event::IsSignaled(Scaleform::Event *this)
{
  return this->State;
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
  Scaleform::Mutex *p_pHandlers; // [rsp+40h] [rbp+8h]

  p_pHandlers = (Scaleform::Mutex *)&this->pHandlers;
  Scaleform::Mutex::DoLock((Scaleform::Mutex *)&this->pHandlers);
  if ( BYTE1(this->RefCount) )
  {
    BYTE1(this->RefCount) = 0;
    LOBYTE(this->RefCount) = 0;
  }
  Scaleform::Mutex::Unlock(p_pHandlers);
  return 1;
}

// File Line: 653
// RVA: 0x9442A0
void __fastcall Scaleform::Semaphore::Semaphore(Scaleform::Semaphore *this, int maxValue, bool multiWait)
{
  Scaleform::Waitable::Waitable(this, multiWait);
  this->Scaleform::AcquireInterface::vfptr = (Scaleform::AcquireInterfaceVtbl *)&Scaleform::AcquireInterface::`vftable;
  this->Scaleform::Waitable::Scaleform::RefCountBase<Scaleform::Waitable,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Semaphore::`vftable{for `Scaleform::Waitable};
  this->Scaleform::AcquireInterface::vfptr = (Scaleform::AcquireInterfaceVtbl *)&Scaleform::Semaphore::`vftable{for `Scaleform::AcquireInterface};
  Scaleform::Mutex::Mutex(&this->ValueMutex, 1, 0);
  Scaleform::WaitCondition::WaitCondition(&this->ValueWaitCondition);
  this->MaxValue = maxValue;
  this->Value = 0;
}

// File Line: 660
// RVA: 0x94C9D0
void __fastcall Scaleform::Semaphore::~Semaphore(Scaleform::Semaphore *this)
{
  Scaleform::Waitable::HandlerArray *pHandlers; // rcx

  this->Scaleform::Waitable::Scaleform::RefCountBase<Scaleform::Waitable,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Semaphore::`vftable{for `Scaleform::Waitable};
  this->Scaleform::AcquireInterface::vfptr = (Scaleform::AcquireInterfaceVtbl *)&Scaleform::Semaphore::`vftable{for `Scaleform::AcquireInterface};
  Scaleform::WaitCondition::~WaitCondition(&this->ValueWaitCondition);
  Scaleform::Mutex::~Mutex(&this->ValueMutex);
  this->Scaleform::AcquireInterface::vfptr = (Scaleform::AcquireInterfaceVtbl *)&Scaleform::AcquireInterface::`vftable;
  this->Scaleform::Waitable::Scaleform::RefCountBase<Scaleform::Waitable,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Waitable::`vftable;
  pHandlers = this->pHandlers;
  if ( pHandlers )
    Scaleform::Waitable::HandlerArray::Release(pHandlers);
  this->Scaleform::Waitable::Scaleform::RefCountBase<Scaleform::Waitable,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
}

// File Line: 682
// RVA: 0x99C7D0
char __fastcall Scaleform::Semaphore::ObtainSemaphore(Scaleform::Semaphore *this, int count, unsigned int delay)
{
  Scaleform::Mutex *p_ValueMutex; // rbx
  char v8; // bl
  unsigned int Time; // r14d
  __int64 v10; // rdx
  unsigned int v11; // edx
  Scaleform::Mutex *v12; // [rsp+50h] [rbp+8h]

  if ( count > this->MaxValue )
    return 0;
  p_ValueMutex = &this->ValueMutex;
  v12 = &this->ValueMutex;
  Scaleform::Mutex::DoLock(&this->ValueMutex);
  if ( count + this->Value <= this->MaxValue )
    goto LABEL_8;
  if ( !delay )
    goto LABEL_17;
  if ( delay != -1 )
  {
    Time = timeGetTime();
    if ( TimerOverrideInstance )
      Time = TimerOverrideInstance->vfptr->GetTicksMs(TimerOverrideInstance, Time);
    if ( Scaleform::WaitCondition::Wait(&this->ValueWaitCondition, p_ValueMutex, delay) )
    {
      while ( count + this->Value > this->MaxValue )
      {
        v10 = timeGetTime();
        if ( TimerOverrideInstance )
          LODWORD(v10) = TimerOverrideInstance->vfptr->GetTicksMs(TimerOverrideInstance, v10);
        v11 = v10 - Time;
        if ( v11 >= delay || !Scaleform::WaitCondition::Wait(&this->ValueWaitCondition, p_ValueMutex, delay - v11) )
          goto LABEL_17;
      }
      goto LABEL_8;
    }
LABEL_17:
    v8 = 0;
    goto LABEL_18;
  }
  while ( count + this->Value > this->MaxValue )
    Scaleform::WaitCondition::Wait(&this->ValueWaitCondition, p_ValueMutex, 0xFFFFFFFF);
LABEL_8:
  this->Value += count;
  v8 = 1;
LABEL_18:
  Scaleform::Mutex::Unlock(v12);
  return v8;
}

// File Line: 736
// RVA: 0x9A83D0
char __fastcall Scaleform::Semaphore::ReleaseSemaphore(Scaleform::Semaphore *this, int count)
{
  Scaleform::Waitable::HandlerArray *v4; // rbx
  Scaleform::WaitCondition *p_ValueWaitCondition; // rcx
  Scaleform::Waitable::HandlerArray *pHandlers; // rax

  if ( count )
  {
    Scaleform::Mutex::DoLock(&this->ValueMutex);
    v4 = 0i64;
    if ( this->Value - count < 0 )
      this->Value = 0;
    else
      this->Value -= count;
    p_ValueWaitCondition = &this->ValueWaitCondition;
    if ( count == 1 )
      Scaleform::WaitCondition::Notify(p_ValueWaitCondition);
    else
      Scaleform::WaitCondition::NotifyAll(p_ValueWaitCondition);
    pHandlers = this->pHandlers;
    if ( pHandlers )
    {
      v4 = this->pHandlers;
      _InterlockedExchangeAdd(&pHandlers->RefCount.Value, 1u);
    }
    Scaleform::Mutex::Unlock(&this->ValueMutex);
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
  Scaleform::Mutex *p_ValueMutex; // rbx
  volatile unsigned int v4; // ebx
  Scaleform::Mutex *v6; // [rsp+40h] [rbp+8h]

  p_ValueMutex = &this->ValueMutex;
  v6 = &this->ValueMutex;
  Scaleform::Mutex::DoLock(&this->ValueMutex);
  while ( this->Value >= this->MaxValue )
    Scaleform::WaitCondition::Wait(&this->ValueWaitCondition, p_ValueMutex, 0xFFFFFFFF);
  v4 = ++this->Value;
  Scaleform::Mutex::Unlock(v6);
  return v4;
}

// File Line: 780
// RVA: 0x94F070
__int64 __fastcall Scaleform::Semaphore::operator--(Scaleform::Semaphore *this, int __formal)
{
  Scaleform::Waitable::HandlerArray *v3; // rbx
  Scaleform::Waitable::HandlerArray *pHandlers; // rax
  volatile unsigned int Value; // ebx
  Scaleform::Waitable::HandlerArray *v7; // [rsp+40h] [rbp+8h]

  Scaleform::Mutex::DoLock(&this->ValueMutex);
  if ( this->Value > 0 )
    --this->Value;
  Scaleform::WaitCondition::Notify(&this->ValueWaitCondition);
  v3 = 0i64;
  v7 = 0i64;
  pHandlers = this->pHandlers;
  if ( pHandlers )
  {
    v3 = this->pHandlers;
    _InterlockedExchangeAdd(&pHandlers->RefCount.Value, 1u);
    v7 = v3;
  }
  Scaleform::Mutex::Unlock(&this->ValueMutex);
  if ( v3 )
    Scaleform::Waitable::HandlerArray::CallWaitHandlers(v3);
  Value = this->Value;
  if ( v7 )
    Scaleform::Waitable::HandlerArray::Release(v7);
  return Value;
}

// File Line: 795
// RVA: 0x94F260
__int64 __fastcall Scaleform::Semaphore::operator+=(Scaleform::Semaphore *this, int count)
{
  Scaleform::Mutex *p_ValueMutex; // rbx
  volatile unsigned int Value; // ebx
  Scaleform::Mutex *v7; // [rsp+40h] [rbp+8h]

  p_ValueMutex = &this->ValueMutex;
  v7 = &this->ValueMutex;
  Scaleform::Mutex::DoLock(&this->ValueMutex);
  while ( count + this->Value > this->MaxValue )
    Scaleform::WaitCondition::Wait(&this->ValueWaitCondition, p_ValueMutex, 0xFFFFFFFF);
  this->Value += count;
  Value = this->Value;
  Scaleform::Mutex::Unlock(v7);
  return Value;
}

// File Line: 805
// RVA: 0x94F3F0
__int64 __fastcall Scaleform::Semaphore::operator-=(Scaleform::Semaphore *this, int count)
{
  Scaleform::Waitable::HandlerArray *v4; // rbx
  Scaleform::Waitable::HandlerArray *pHandlers; // rax
  volatile unsigned int Value; // ebx
  Scaleform::Waitable::HandlerArray *v8; // [rsp+40h] [rbp+8h]

  Scaleform::Mutex::DoLock(&this->ValueMutex);
  v4 = 0i64;
  if ( this->Value - count < 0 )
    this->Value = 0;
  else
    this->Value -= count;
  Scaleform::WaitCondition::NotifyAll(&this->ValueWaitCondition);
  v8 = 0i64;
  pHandlers = this->pHandlers;
  if ( pHandlers )
  {
    v4 = this->pHandlers;
    _InterlockedExchangeAdd(&pHandlers->RefCount.Value, 1u);
    v8 = v4;
  }
  Scaleform::Mutex::Unlock(&this->ValueMutex);
  if ( v4 )
    Scaleform::Waitable::HandlerArray::CallWaitHandlers(v4);
  Value = this->Value;
  if ( v8 )
    Scaleform::Waitable::HandlerArray::Release(v8);
  return Value;
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
  Scaleform::Mutex *p_pHandlers; // [rsp+40h] [rbp+8h]

  if ( this->RefCount >= 1 )
  {
    p_pHandlers = (Scaleform::Mutex *)&this->pHandlers;
    Scaleform::Mutex::DoLock((Scaleform::Mutex *)&this->pHandlers);
    if ( *((_DWORD *)&this->RefCount + 1) + 1 <= this->RefCount )
    {
      ++*((_DWORD *)&this->RefCount + 1);
      Scaleform::Mutex::Unlock(p_pHandlers);
      return 1;
    }
    Scaleform::Mutex::Unlock(p_pHandlers);
  }
  return 0;
}

// File Line: 830
// RVA: 0x9BAE80
char __fastcall Scaleform::Semaphore::TryAcquireCancel(Scaleform::Semaphore *this)
{
  Scaleform::Waitable::HandlerArray *v2; // rbx
  Scaleform::WaitConditionImpl *pImpl; // rax

  Scaleform::Mutex::DoLock((Scaleform::Mutex *)&this->pHandlers);
  v2 = 0i64;
  if ( *((_DWORD *)&this->RefCount + 1) - 1 < 0 )
    *((_DWORD *)&this->RefCount + 1) = 0;
  else
    --*((_DWORD *)&this->RefCount + 1);
  Scaleform::WaitCondition::Notify((Scaleform::WaitCondition *)&this->ValueMutex.pHandlers);
  pImpl = this[-1].ValueWaitCondition.pImpl;
  if ( pImpl )
  {
    v2 = (Scaleform::Waitable::HandlerArray *)this[-1].ValueWaitCondition.pImpl;
    _InterlockedExchangeAdd((volatile signed __int32 *)pImpl, 1u);
  }
  Scaleform::Mutex::Unlock((Scaleform::Mutex *)&this->pHandlers);
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
void __fastcall Scaleform::SemaphoreWaitableIncrement::SemaphoreWaitableIncrement(
        Scaleform::SemaphoreWaitableIncrement *this,
        Scaleform::Semaphore *psemaphore,
        int count)
{
  Scaleform::Waitable::HandlerArray *v6; // rax

  this->Scaleform::Waitable::Scaleform::RefCountBase<Scaleform::Waitable,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->Scaleform::Waitable::Scaleform::RefCountBase<Scaleform::Waitable,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->Scaleform::Waitable::Scaleform::RefCountBase<Scaleform::Waitable,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable;
  this->Scaleform::Waitable::Scaleform::RefCountBase<Scaleform::Waitable,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::Waitable,2>::`vftable;
  this->Scaleform::Waitable::Scaleform::RefCountBase<Scaleform::Waitable,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Waitable::`vftable;
  v6 = (Scaleform::Waitable::HandlerArray *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                              Scaleform::Memory::pGlobalHeap,
                                              72i64);
  if ( v6 )
    Scaleform::Waitable::HandlerArray::HandlerArray(v6);
  this->pHandlers = v6;
  this->Scaleform::AcquireInterface::vfptr = (Scaleform::AcquireInterfaceVtbl *)&Scaleform::AcquireInterface::`vftable;
  this->Scaleform::Waitable::Scaleform::RefCountBase<Scaleform::Waitable,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::SemaphoreWaitableIncrement::`vftable{for `Scaleform::Waitable};
  this->Scaleform::AcquireInterface::vfptr = (Scaleform::AcquireInterfaceVtbl *)&Scaleform::SemaphoreWaitableIncrement::`vftable{for `Scaleform::AcquireInterface};
  this->pSemaphore = psemaphore;
  this->Count = count;
  Scaleform::Waitable::AddWaitHandler(psemaphore, Scaleform::Waitable::CallWaitHandlers, this);
}

// File Line: 888
// RVA: 0x94CA50
void __fastcall Scaleform::SemaphoreWaitableIncrement::~SemaphoreWaitableIncrement(
        Scaleform::SemaphoreWaitableIncrement *this)
{
  Scaleform::Waitable::HandlerArray *pHandlers; // rcx

  this->Scaleform::Waitable::Scaleform::RefCountBase<Scaleform::Waitable,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::SemaphoreWaitableIncrement::`vftable{for `Scaleform::Waitable};
  this->Scaleform::AcquireInterface::vfptr = (Scaleform::AcquireInterfaceVtbl *)&Scaleform::SemaphoreWaitableIncrement::`vftable{for `Scaleform::AcquireInterface};
  Scaleform::Waitable::RemoveWaitHandler(this->pSemaphore, Scaleform::Waitable::CallWaitHandlers, this);
  this->Scaleform::AcquireInterface::vfptr = (Scaleform::AcquireInterfaceVtbl *)&Scaleform::AcquireInterface::`vftable;
  this->Scaleform::Waitable::Scaleform::RefCountBase<Scaleform::Waitable,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Waitable::`vftable;
  pHandlers = this->pHandlers;
  if ( pHandlers )
    Scaleform::Waitable::HandlerArray::Release(pHandlers);
  this->Scaleform::Waitable::Scaleform::RefCountBase<Scaleform::Waitable,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
}

// File Line: 894
// RVA: 0x95DB40
bool __fastcall Scaleform::SemaphoreWaitableIncrement::CanAcquire(Scaleform::SemaphoreWaitableIncrement *this)
{
  __int64 v1; // rdx

  v1 = *(_QWORD *)&this->RefCount;
  return v1 && *(_DWORD *)(v1 + 32) - *(_DWORD *)(v1 + 36) >= SLODWORD(this->pHandlers);
}

// File Line: 899
// RVA: 0x9BAE10
char __fastcall Scaleform::SemaphoreWaitableIncrement::TryAcquire(Scaleform::SemaphoreWaitableIncrement *this)
{
  __int64 v1; // rbx
  int pHandlers; // edi
  Scaleform::Mutex *v4; // [rsp+40h] [rbp+8h]

  v1 = *(_QWORD *)&this->RefCount;
  if ( v1 )
  {
    pHandlers = (int)this->pHandlers;
    if ( pHandlers <= *(_DWORD *)(v1 + 32) )
    {
      v4 = (Scaleform::Mutex *)(v1 + 40);
      Scaleform::Mutex::DoLock((Scaleform::Mutex *)(v1 + 40));
      if ( pHandlers + *(_DWORD *)(v1 + 36) <= *(_DWORD *)(v1 + 32) )
      {
        *(_DWORD *)(v1 + 36) += pHandlers;
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
  Scaleform::Semaphore *pSemaphore; // rdx

  pSemaphore = this->pSemaphore;
  return pSemaphore && pSemaphore->MaxValue - pSemaphore->Value >= this->Count;
}

// File Line: 927
// RVA: 0x96A930
void __fastcall Scaleform::Semaphore::CreateWaitableIncrement(Scaleform::Semaphore *this, int count)
{
  Scaleform::SemaphoreWaitableIncrement *v4; // rax

  v4 = (Scaleform::SemaphoreWaitableIncrement *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                                  Scaleform::Memory::pGlobalHeap,
                                                  48i64);
  if ( v4 )
    Scaleform::SemaphoreWaitableIncrement::SemaphoreWaitableIncrement(v4, this, count);
}

