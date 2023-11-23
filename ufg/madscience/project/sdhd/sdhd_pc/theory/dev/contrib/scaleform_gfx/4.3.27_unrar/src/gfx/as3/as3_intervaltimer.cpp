// File Line: 27
// RVA: 0x77F020
void __fastcall Scaleform::GFx::AS3::IntervalTimer::IntervalTimer(
        Scaleform::GFx::AS3::IntervalTimer *this,
        Scaleform::GFx::AS3::Value *function,
        unsigned int delay,
        bool timeOut)
{
  Scaleform::GFx::AS3::Value::V2U v5; // r8
  Scaleform::GFx::AS3::Value::V1U v6; // r8

  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,323>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::GFx::ASIntervalTimerIntf,323>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::ASIntervalTimerIntf::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::AS3::IntervalTimer::`vftable;
  this->Function.Flags = function->Flags;
  this->Function.Bonus.pWeakProxy = function->Bonus.pWeakProxy;
  this->Function.value = function->value;
  if ( (function->Flags & 0x1F) > 9 )
  {
    if ( (function->Flags & 0x200) != 0 )
    {
      ++function->Bonus.pWeakProxy->RefCount;
    }
    else if ( (function->Flags & 0x1F) == 10 )
    {
      ++function->value.VS._1.VStr->RefCount;
    }
    else if ( (function->Flags & 0x1F) > 0xA )
    {
      if ( (function->Flags & 0x1F) <= 0xF )
      {
        v6 = function->value.VS._1;
        if ( v6.VStr )
          v6.VStr->Size = (v6.VStr->Size + 1) & 0x8FBFFFFF;
      }
      else if ( (function->Flags & 0x1F) <= 0x11 )
      {
        v5.VObj = (Scaleform::GFx::AS3::Object *)function->value.VS._2;
        if ( v5.VObj )
          v5.VObj->RefCount = (v5.VObj->RefCount + 1) & 0x8FBFFFFF;
      }
    }
  }
  this->TimerObj.pObject = 0i64;
  this->Params.Data.Data = 0i64;
  this->Params.Data.Size = 0i64;
  this->Params.Data.Policy.Capacity = 0i64;
  *(_QWORD *)&this->CurrentCount = 0i64;
  this->Interval = 1000 * delay;
  this->InvokeTime = 0i64;
  this->Id = 0;
  this->Active = 1;
  this->Timeout = timeOut;
}

// File Line: 35
// RVA: 0x77F150
void __fastcall Scaleform::GFx::AS3::IntervalTimer::IntervalTimer(
        Scaleform::GFx::AS3::IntervalTimer *this,
        Scaleform::GFx::AS3::Instances::fl_utils::Timer *timerObj,
        unsigned int delay,
        unsigned int curCount,
        unsigned int repeatCount)
{
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,323>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::GFx::ASIntervalTimerIntf,323>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::ASIntervalTimerIntf::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::AS3::IntervalTimer::`vftable;
  this->Function.Flags = 0;
  this->Function.Bonus.pWeakProxy = 0i64;
  this->TimerObj.pObject = timerObj;
  if ( timerObj )
    timerObj->RefCount = (timerObj->RefCount + 1) & 0x8FBFFFFF;
  this->Params.Data.Data = 0i64;
  this->Params.Data.Size = 0i64;
  this->Params.Data.Policy.Capacity = 0i64;
  this->CurrentCount = curCount;
  this->RepeatCount = repeatCount;
  this->Interval = 1000 * delay;
  this->InvokeTime = 0i64;
  this->Id = 0;
  *(_WORD *)&this->Active = 1;
}

// File Line: 39
// RVA: 0x818270
void __fastcall Scaleform::GFx::AS3::IntervalTimer::SetArguments(
        Scaleform::GFx::AS3::IntervalTimer *this,
        unsigned int num,
        Scaleform::GFx::AS3::Value *argArr)
{
  Scaleform::ArrayLH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *p_Params; // rdi
  Scaleform::GFx::AS3::Value::VU *p_value; // rbx
  __int64 i; // rsi
  __int64 v6; // rdx
  int VInt; // ecx
  Scaleform::GFx::AS3::Value::V1U VObj; // rcx

  if ( num )
  {
    p_Params = &this->Params;
    p_value = &argArr->value;
    for ( i = num; i; --i )
    {
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
        &p_Params->Data,
        p_Params,
        p_Params->Data.Size + 1);
      v6 = (__int64)&p_Params->Data.Data[p_Params->Data.Size - 1];
      if ( !v6 )
        goto LABEL_16;
      *(_DWORD *)v6 = p_value[-1].VS._1.VInt;
      *(_QWORD *)(v6 + 8) = p_value[-1].VS._2.VObj;
      *(_QWORD *)(v6 + 16) = p_value->VS._1.VStr;
      *(_QWORD *)(v6 + 24) = p_value->VS._2.VObj;
      VInt = p_value[-1].VS._1.VInt;
      if ( (VInt & 0x1Fu) <= 9 )
        goto LABEL_16;
      if ( (VInt & 0x200) != 0 )
      {
        ++LODWORD(p_value[-1].VS._2.VObj->vfptr);
      }
      else if ( (p_value[-1].VS._1.VInt & 0x1F) == 10 )
      {
        ++p_value->VS._1.VStr->RefCount;
      }
      else if ( (p_value[-1].VS._1.VInt & 0x1Fu) > 0xA )
      {
        if ( (p_value[-1].VS._1.VInt & 0x1Fu) <= 0xF )
        {
          VObj = p_value->VS._1;
LABEL_13:
          if ( VObj.VStr )
            VObj.VStr->Size = (VObj.VStr->Size + 1) & 0x8FBFFFFF;
          goto LABEL_16;
        }
        if ( (p_value[-1].VS._1.VInt & 0x1Fu) <= 0x11 )
        {
          VObj = (Scaleform::GFx::AS3::Value::V1U)p_value->VS._2.VObj;
          goto LABEL_13;
        }
      }
LABEL_16:
      p_value += 2;
    }
  }
}

// File Line: 47
// RVA: 0x8217B0
void __fastcall Scaleform::GFx::AS3::IntervalTimer::Start(
        Scaleform::GFx::AS3::IntervalTimer *this,
        Scaleform::GFx::MovieImpl *proot)
{
  this->InvokeTime = proot->TimeElapsed + this->Interval;
}

// File Line: 55
// RVA: 0x7F7060
char __fastcall Scaleform::GFx::AS3::IntervalTimer::Invoke(
        Scaleform::GFx::AS3::IntervalTimer *this,
        Scaleform::GFx::MovieImpl *proot,
        float frameTime)
{
  char v4; // al
  Scaleform::GFx::ASMovieRootBase *pObject; // rdi
  unsigned __int64 TimeElapsed; // rsi
  Scaleform::GFx::AS3::Instances::fl_utils::Timer *v7; // rcx
  unsigned int RepeatCount; // eax
  Scaleform::GFx::AS3::VM *vfptr; // rdi
  bool v10; // zf
  unsigned int v11; // eax
  float v12; // xmm6_4
  unsigned __int64 v13; // rax
  unsigned int NextInterval; // eax
  Scaleform::GFx::AS3::Value result; // [rsp+40h] [rbp-1h] BYREF
  Scaleform::GFx::AS3::Value _this; // [rsp+60h] [rbp+1Fh] BYREF

  v4 = 0;
  if ( this->Active )
  {
    pObject = proot->pASMovieRoot.pObject;
    TimeElapsed = proot->TimeElapsed;
    if ( TimeElapsed >= this->InvokeTime )
    {
      v7 = this->TimerObj.pObject;
      if ( v7 )
      {
        RepeatCount = this->RepeatCount;
        if ( !RepeatCount || this->CurrentCount < RepeatCount )
        {
          ++this->CurrentCount;
          Scaleform::GFx::AS3::Instances::fl_utils::Timer::ExecuteEvent(v7);
        }
      }
      else
      {
        _this.Flags = 0;
        _this.Bonus.pWeakProxy = 0i64;
        result.Flags = 0;
        result.Bonus.pWeakProxy = 0i64;
        vfptr = (Scaleform::GFx::AS3::VM *)pObject[2].vfptr;
        Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(
          vfptr,
          &this->Function,
          &_this,
          &result,
          this->Params.Data.Size,
          this->Params.Data.Data,
          0);
        if ( vfptr->HandleException )
          Scaleform::GFx::AS3::VM::OutputAndIgnoreException(vfptr);
        if ( (result.Flags & 0x1F) > 9 )
        {
          if ( (result.Flags & 0x200) != 0 )
          {
            v10 = result.Bonus.pWeakProxy->RefCount-- == 1;
            if ( v10 )
              ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
            memset(&result.Bonus, 0, 24);
            result.Flags &= 0xFFFFFDE0;
          }
          else
          {
            Scaleform::GFx::AS3::Value::ReleaseInternal(&result);
          }
        }
        if ( (_this.Flags & 0x1F) > 9 )
        {
          if ( (_this.Flags & 0x200) != 0 )
          {
            v10 = _this.Bonus.pWeakProxy->RefCount-- == 1;
            if ( v10 )
              ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
            memset(&_this.Bonus, 0, 24);
            _this.Flags &= 0xFFFFFDE0;
          }
          else
          {
            Scaleform::GFx::AS3::Value::ReleaseInternal(&_this);
          }
        }
      }
      if ( this->Timeout || (v11 = this->RepeatCount) != 0 && this->CurrentCount >= v11 )
      {
        this->Active = 0;
      }
      else
      {
        v12 = frameTime * 1000000.0;
        v13 = 0i64;
        if ( (float)(frameTime * 1000000.0) >= 9.223372e18 )
        {
          v12 = v12 - 9.223372e18;
          if ( v12 < 9.223372e18 )
            v13 = 0x8000000000000000ui64;
        }
        NextInterval = Scaleform::GFx::AS3::IntervalTimer::GetNextInterval(
                         this,
                         TimeElapsed,
                         v13 + (unsigned int)(int)v12);
        if ( NextInterval )
          this->InvokeTime += NextInterval;
        else
          this->InvokeTime = TimeElapsed;
      }
      return 1;
    }
  }
  return v4;
}

// File Line: 104
// RVA: 0x7ECD10
__int64 __fastcall Scaleform::GFx::AS3::IntervalTimer::GetNextInterval(
        Scaleform::GFx::AS3::IntervalTimer *this,
        unsigned __int64 currentTime,
        unsigned __int64 frameTime)
{
  unsigned int RepeatCount; // eax
  unsigned int Interval; // ecx

  RepeatCount = this->RepeatCount;
  if ( RepeatCount && this->CurrentCount >= RepeatCount )
    return 0i64;
  Interval = this->Interval;
  if ( 10 * Interval < frameTime )
    Interval = (unsigned int)frameTime / 0xA;
  if ( !Interval )
    return 0i64;
  else
    return Interval * ((Interval + (_DWORD)currentTime - LODWORD(this->InvokeTime)) / Interval);
}

// File Line: 119
// RVA: 0x7B4A30
void __fastcall Scaleform::GFx::AS3::IntervalTimer::Clear(Scaleform::GFx::AS3::IntervalTimer *this)
{
  Scaleform::GFx::AS3::Instances::fl_utils::Timer *pObject; // rcx
  unsigned int RefCount; // eax

  this->Active = 0;
  pObject = this->TimerObj.pObject;
  if ( pObject )
  {
    if ( ((unsigned __int8)pObject & 1) != 0 )
    {
      this->TimerObj.pObject = (Scaleform::GFx::AS3::Instances::fl_utils::Timer *)((char *)pObject - 1);
      this->TimerObj.pObject = 0i64;
    }
    else
    {
      RefCount = pObject->RefCount;
      if ( (RefCount & 0x3FFFFF) != 0 )
      {
        pObject->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
      }
      this->TimerObj.pObject = 0i64;
    }
  }
}

// File Line: 125
// RVA: 0x7B4C00
char __fastcall Scaleform::GFx::AS3::IntervalTimer::ClearFor(
        Scaleform::GFx::AS3::IntervalTimer *this,
        Scaleform::GFx::MovieImpl *proot,
        Scaleform::GFx::MovieDefImpl *defimpl)
{
  Scaleform::GFx::MovieImpl *v5; // r8
  Scaleform::GFx::AS3::Value *p_Function; // rdx
  unsigned int v7; // ecx
  Scaleform::GFx::AS3::Traits *ValueTraits; // rax
  __int64 v9; // rax
  Scaleform::GFx::AS3::Instances::fl_utils::Timer *pObject; // rcx
  __int64 v12; // rax

  v5 = proot;
  p_Function = &this->Function;
  v7 = this->Function.Flags & 0x1F;
  if ( (v7 - 12 <= 3 || v7 == 10) && !p_Function->value.VS._1.VStr
    || (ValueTraits = Scaleform::GFx::AS3::VM::GetValueTraits(
                        (Scaleform::GFx::AS3::VM *)v5->pASMovieRoot.pObject[2].vfptr,
                        p_Function),
        (v9 = ((__int64 (__fastcall *)(Scaleform::GFx::AS3::Traits *))ValueTraits->vfptr[2].~RefCountBaseGC<328>)(ValueTraits)) == 0)
    || *(Scaleform::GFx::MovieDefImpl **)(*(_QWORD *)(v9 + 152) + 368i64) != defimpl )
  {
    pObject = this->TimerObj.pObject;
    if ( !pObject )
      return 0;
    v12 = ((__int64 (__fastcall *)(Scaleform::GFx::AS3::Traits *, Scaleform::GFx::AS3::Value *, Scaleform::GFx::MovieImpl *))pObject->pTraits.pObject->Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Scaleform::GFx::AS3::Instances::fl::Object::Scaleform::GFx::AS3::Instance::Scaleform::GFx::AS3::Object::vfptr[2].~RefCountBaseGC<328>)(
            pObject->pTraits.pObject,
            p_Function,
            v5);
    if ( !v12 || *(Scaleform::GFx::MovieDefImpl **)(*(_QWORD *)(v12 + 152) + 368i64) != defimpl )
      return 0;
  }
  ((void (__fastcall *)(Scaleform::GFx::AS3::IntervalTimer *))this->vfptr[4].__vecDelDtor)(this);
  return 1;
}

