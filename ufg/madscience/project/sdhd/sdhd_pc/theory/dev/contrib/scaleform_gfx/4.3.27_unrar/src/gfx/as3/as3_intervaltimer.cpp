// File Line: 27
// RVA: 0x77F020
void __fastcall Scaleform::GFx::AS3::IntervalTimer::IntervalTimer(Scaleform::GFx::AS3::IntervalTimer *this, Scaleform::GFx::AS3::Value *function, unsigned int delay, bool timeOut)
{
  unsigned int v4; // er10
  signed int v5; // eax
  Scaleform::GFx::AS3::Value::V2U v6; // r8
  long double v7; // r8
  Scaleform::ArrayLH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *v8; // [rsp+28h] [rbp+10h]

  v4 = delay;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,323>::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::GFx::ASIntervalTimerIntf,323>::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::ASIntervalTimerIntf::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::AS3::IntervalTimer::`vftable';
  this->Function.Flags = function->Flags;
  this->Function.Bonus.pWeakProxy = function->Bonus.pWeakProxy;
  this->Function.value = function->value;
  v5 = function->Flags & 0x1F;
  if ( v5 > 9 )
  {
    if ( (function->Flags >> 9) & 1 )
    {
      ++function->Bonus.pWeakProxy->RefCount;
    }
    else if ( v5 == 10 )
    {
      ++*(_DWORD *)(*(_QWORD *)&function->value.VNumber + 24i64);
    }
    else if ( v5 > 10 )
    {
      if ( v5 <= 15 )
      {
        v7 = function->value.VNumber;
        if ( v7 != 0.0 )
          *(_DWORD *)(*(_QWORD *)&v7 + 32i64) = (*(_DWORD *)(*(_QWORD *)&v7 + 32i64) + 1) & 0x8FBFFFFF;
      }
      else if ( v5 <= 17 )
      {
        v6.VObj = (Scaleform::GFx::AS3::Object *)function->value.VS._2;
        if ( v6.VObj )
          v6.VObj->RefCount = (v6.VObj->RefCount + 1) & 0x8FBFFFFF;
      }
    }
  }
  this->TimerObj.pObject = 0i64;
  v8 = &this->Params;
  *(_OWORD *)&v8->Data.Data = 0ui64;
  v8->Data.Policy.Capacity = 0i64;
  *(_QWORD *)&this->CurrentCount = 0i64;
  this->Interval = 1000 * v4;
  this->InvokeTime = 0i64;
  this->Id = 0;
  this->Active = 1;
  this->Timeout = timeOut;
}

// File Line: 35
// RVA: 0x77F150
void __fastcall Scaleform::GFx::AS3::IntervalTimer::IntervalTimer(Scaleform::GFx::AS3::IntervalTimer *this, Scaleform::GFx::AS3::Instances::fl_utils::Timer *timerObj, unsigned int delay, unsigned int curCount, unsigned int repeatCount)
{
  Scaleform::ArrayLH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *v5; // [rsp+28h] [rbp+10h]

  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,323>::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::GFx::ASIntervalTimerIntf,323>::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::ASIntervalTimerIntf::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::AS3::IntervalTimer::`vftable';
  this->Function.Flags = 0;
  this->Function.Bonus.pWeakProxy = 0i64;
  this->TimerObj.pObject = timerObj;
  if ( timerObj )
    timerObj->RefCount = (timerObj->RefCount + 1) & 0x8FBFFFFF;
  v5 = &this->Params;
  *(_OWORD *)&v5->Data.Data = 0ui64;
  v5->Data.Policy.Capacity = 0i64;
  this->CurrentCount = curCount;
  this->RepeatCount = repeatCount;
  this->Interval = 1000 * delay;
  this->InvokeTime = 0i64;
  this->Id = 0;
  *(_WORD *)&this->Active = 1;
}

// File Line: 39
// RVA: 0x818270
void __fastcall Scaleform::GFx::AS3::IntervalTimer::SetArguments(Scaleform::GFx::AS3::IntervalTimer *this, unsigned int num, Scaleform::GFx::AS3::Value *argArr)
{
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *v3; // rdi
  _QWORD *v4; // rbx
  __int64 v5; // rsi
  signed __int64 v6; // rdx
  int v7; // eax
  __int64 v8; // rcx

  if ( num )
  {
    v3 = (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *)&this->Params.Data.Data;
    v4 = (_QWORD *)&argArr->value.VNumber;
    v5 = num;
    do
    {
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
        v3,
        v3,
        v3->Size + 1);
      v6 = (signed __int64)&v3->Data[v3->Size - 1];
      if ( !v6 )
        goto LABEL_16;
      *(_DWORD *)v6 = *((_DWORD *)v4 - 4);
      *(_QWORD *)(v6 + 8) = *(v4 - 1);
      *(_QWORD *)(v6 + 16) = *v4;
      *(_QWORD *)(v6 + 24) = v4[1];
      v7 = *(_DWORD *)(v4 - 2) & 0x1F;
      if ( v7 <= 9 )
        goto LABEL_16;
      if ( (*((_DWORD *)v4 - 4) >> 9) & 1 )
      {
        ++*(_DWORD *)*(v4 - 1);
      }
      else if ( v7 == 10 )
      {
        ++*(_DWORD *)(*v4 + 24i64);
      }
      else if ( v7 > 10 )
      {
        if ( v7 <= 15 )
        {
          v8 = *v4;
LABEL_13:
          if ( v8 )
            *(_DWORD *)(v8 + 32) = (*(_DWORD *)(v8 + 32) + 1) & 0x8FBFFFFF;
          goto LABEL_16;
        }
        if ( v7 <= 17 )
        {
          v8 = v4[1];
          goto LABEL_13;
        }
      }
LABEL_16:
      v4 += 4;
      --v5;
    }
    while ( v5 );
  }
}

// File Line: 47
// RVA: 0x8217B0
void __fastcall Scaleform::GFx::AS3::IntervalTimer::Start(Scaleform::GFx::AS3::IntervalTimer *this, Scaleform::GFx::MovieImpl *proot)
{
  this->InvokeTime = proot->TimeElapsed + this->Interval;
}

// File Line: 55
// RVA: 0x7F7060
char __fastcall Scaleform::GFx::AS3::IntervalTimer::Invoke(Scaleform::GFx::AS3::IntervalTimer *this, Scaleform::GFx::MovieImpl *proot, float frameTime)
{
  Scaleform::GFx::AS3::IntervalTimer *v3; // rbx
  char v4; // al
  Scaleform::GFx::ASMovieRootBase *v5; // rdi
  unsigned __int64 v6; // rsi
  Scaleform::GFx::AS3::Instances::fl_utils::Timer *v7; // rcx
  unsigned int v8; // eax
  Scaleform::GFx::AS3::VM *v9; // rdi
  bool v10; // zf
  unsigned int v11; // eax
  float v12; // xmm6_4
  signed __int64 v13; // rax
  unsigned int v14; // eax
  Scaleform::GFx::AS3::Value result; // [rsp+40h] [rbp-1h]
  Scaleform::GFx::AS3::Value _this; // [rsp+60h] [rbp+1Fh]

  v3 = this;
  v4 = 0;
  if ( this->Active )
  {
    v5 = proot->pASMovieRoot.pObject;
    v6 = proot->TimeElapsed;
    if ( v6 >= this->InvokeTime )
    {
      v7 = this->TimerObj.pObject;
      if ( v7 )
      {
        v8 = v3->RepeatCount;
        if ( !v8 || v3->CurrentCount < v8 )
        {
          ++v3->CurrentCount;
          Scaleform::GFx::AS3::Instances::fl_utils::Timer::ExecuteEvent(v7);
        }
      }
      else
      {
        _this.Flags = 0;
        _this.Bonus.pWeakProxy = 0i64;
        result.Flags = 0;
        result.Bonus.pWeakProxy = 0i64;
        v9 = (Scaleform::GFx::AS3::VM *)v5[2].vfptr;
        Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(
          v9,
          &v3->Function,
          &_this,
          &result,
          v3->Params.Data.Size,
          v3->Params.Data.Data,
          0);
        if ( v9->HandleException )
          Scaleform::GFx::AS3::VM::OutputAndIgnoreException(v9);
        if ( (result.Flags & 0x1F) > 9 )
        {
          if ( (result.Flags >> 9) & 1 )
          {
            v10 = result.Bonus.pWeakProxy->RefCount-- == 1;
            if ( v10 )
              ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
            result.Bonus.pWeakProxy = 0i64;
            result.value = 0ui64;
            result.Flags &= 0xFFFFFDE0;
          }
          else
          {
            Scaleform::GFx::AS3::Value::ReleaseInternal(&result);
          }
        }
        if ( (_this.Flags & 0x1F) > 9 )
        {
          if ( (_this.Flags >> 9) & 1 )
          {
            v10 = _this.Bonus.pWeakProxy->RefCount-- == 1;
            if ( v10 )
              ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
            _this.Bonus.pWeakProxy = 0i64;
            _this.value = 0ui64;
            _this.Flags &= 0xFFFFFDE0;
          }
          else
          {
            Scaleform::GFx::AS3::Value::ReleaseInternal(&_this);
          }
        }
      }
      if ( v3->Timeout || (v11 = v3->RepeatCount) != 0 && v3->CurrentCount >= v11 )
      {
        v3->Active = 0;
      }
      else
      {
        v12 = frameTime * 1000000.0;
        v13 = 0i64;
        if ( (float)(frameTime * 1000000.0) >= 9.223372e18 )
        {
          v12 = v12 - 9.223372e18;
          if ( v12 < 9.223372e18 )
            v13 = 0x8000000000000000i64;
        }
        v14 = Scaleform::GFx::AS3::IntervalTimer::GetNextInterval(v3, v6, v13 + (unsigned int)(signed int)v12);
        if ( v14 )
          v3->InvokeTime += v14;
        else
          v3->InvokeTime = v6;
      }
      v4 = 1;
    }
  }
  return v4;
}

// File Line: 104
// RVA: 0x7ECD10
__int64 __fastcall Scaleform::GFx::AS3::IntervalTimer::GetNextInterval(Scaleform::GFx::AS3::IntervalTimer *this, unsigned __int64 currentTime, unsigned __int64 frameTime)
{
  unsigned int v3; // eax
  Scaleform::GFx::AS3::IntervalTimer *v4; // r9
  __int64 result; // rax
  unsigned int v6; // ecx

  v3 = this->RepeatCount;
  v4 = this;
  if ( v3 && this->CurrentCount >= v3 )
    goto LABEL_10;
  v6 = this->Interval;
  if ( 10 * v6 < frameTime )
    v6 = (unsigned int)frameTime / 0xA;
  if ( !v6 )
LABEL_10:
    result = 0i64;
  else
    result = v6 * ((v6 + (_DWORD)currentTime - LODWORD(v4->InvokeTime)) / v6);
  return result;
}

// File Line: 119
// RVA: 0x7B4A30
void __fastcall Scaleform::GFx::AS3::IntervalTimer::Clear(Scaleform::GFx::AS3::IntervalTimer *this)
{
  Scaleform::GFx::AS3::IntervalTimer *v1; // rbx
  Scaleform::GFx::AS3::Instances::fl_utils::Timer *v2; // rcx
  unsigned int v3; // eax

  v1 = this;
  this->Active = 0;
  v2 = this->TimerObj.pObject;
  if ( v2 )
  {
    if ( (unsigned __int8)v2 & 1 )
    {
      v1->TimerObj.pObject = (Scaleform::GFx::AS3::Instances::fl_utils::Timer *)((char *)v2 - 1);
      v1->TimerObj.pObject = 0i64;
    }
    else
    {
      v3 = v2->RefCount;
      if ( v3 & 0x3FFFFF )
      {
        v2->RefCount = v3 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v2->vfptr);
      }
      v1->TimerObj.pObject = 0i64;
    }
  }
}

// File Line: 125
// RVA: 0x7B4C00
char __fastcall Scaleform::GFx::AS3::IntervalTimer::ClearFor(Scaleform::GFx::AS3::IntervalTimer *this, Scaleform::GFx::MovieImpl *proot, Scaleform::GFx::MovieDefImpl *defimpl)
{
  Scaleform::GFx::AS3::IntervalTimer *v3; // rbx
  Scaleform::GFx::MovieDefImpl *v4; // rdi
  Scaleform::GFx::MovieImpl *v5; // r8
  Scaleform::GFx::AS3::Value *v6; // rdx
  unsigned int v7; // ecx
  Scaleform::GFx::AS3::Traits *v8; // rax
  __int64 v9; // rax
  Scaleform::GFx::AS3::Instances::fl_utils::Timer *v11; // rcx
  __int64 v12; // rax

  v3 = this;
  v4 = defimpl;
  v5 = proot;
  v6 = &this->Function;
  v7 = this->Function.Flags & 0x1F;
  if ( (v7 - 12 <= 3 || v7 == 10) && !*(_QWORD *)&v6->value.VNumber
    || (v8 = Scaleform::GFx::AS3::VM::GetValueTraits((Scaleform::GFx::AS3::VM *)v5->pASMovieRoot.pObject[2].vfptr, v6),
        (v9 = ((__int64 (__fastcall *)(Scaleform::GFx::AS3::Traits *))v8->vfptr[2].~RefCountBaseGC<328>)(v8)) == 0)
    || *(Scaleform::GFx::MovieDefImpl **)(*(_QWORD *)(v9 + 152) + 368i64) != v4 )
  {
    v11 = v3->TimerObj.pObject;
    if ( !v11 )
      return 0;
    v12 = ((__int64 (__fastcall *)(Scaleform::GFx::AS3::Traits *, Scaleform::GFx::AS3::Value *, Scaleform::GFx::MovieImpl *))v11->pTraits.pObject->vfptr[2].~RefCountBaseGC<328>)(
            v11->pTraits.pObject,
            v6,
            v5);
    if ( !v12 || *(Scaleform::GFx::MovieDefImpl **)(*(_QWORD *)(v12 + 152) + 368i64) != v4 )
      return 0;
  }
  ((void (__fastcall *)(Scaleform::GFx::AS3::IntervalTimer *))v3->vfptr[4].__vecDelDtor)(v3);
  return 1;
}

