// File Line: 34
// RVA: 0x1597600
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl_sensors::Accelerometer_0_bool_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243F648 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_sensors::Accelerometer,0,bool>::Method = Scaleform::GFx::AS3::Instances::fl_sensors::Accelerometer::mutedGet;
  return result;
}

// File Line: 35
// RVA: 0x1599850
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc1_Scaleform::GFx::AS3::Instances::fl_sensors::Accelerometer_1_Scaleform::GFx::AS3::Value_const__double_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243F658 = v1;
  Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_sensors::Accelerometer,1,Scaleform::GFx::AS3::Value const,double>::Method = Scaleform::GFx::AS3::Instances::fl_sensors::Accelerometer::setRequestedUpdateInterval;
  return result;
}

// File Line: 44
// RVA: 0x894770
void __fastcall Scaleform::GFx::AS3::Instances::fl_sensors::Accelerometer::Accelerometer(
        Scaleform::GFx::AS3::Instances::fl_sensors::Accelerometer *this,
        Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::GFx::AS3::VM *VMRef; // rbx
  Scaleform::GFx::StateBag *vecDelDtor; // rcx
  int AccelerometerId; // ebx
  Scaleform::Ptr<Scaleform::GFx::AccelerometerInterface> result; // [rsp+50h] [rbp+18h] BYREF

  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::EventDispatcher(this, t);
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl_sensors::Accelerometer::`vftable;
  this->AccelerometerId = Scaleform::GFx::AS3::Instances::fl_sensors::Accelerometer::AccelerometerIdCount++;
  VMRef = this->VMRef;
  Scaleform::GFx::AS3::MovieRoot::AddToAccelerometers(
    (Scaleform::GFx::AS3::MovieRoot *)VMRef[1].vfptr,
    (Scaleform::GFx::AS2::Object *)this);
  vecDelDtor = (Scaleform::GFx::StateBag *)VMRef[1].vfptr[2].__vecDelDtor;
  AccelerometerId = this->AccelerometerId;
  Scaleform::GFx::StateBag::GetAccelerometerInterface(vecDelDtor + 2, &result);
  if ( result.pObject )
    result.pObject->vfptr[1].__vecDelDtor(result.pObject, AccelerometerId);
  if ( result.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)result.pObject);
}

// File Line: 53
// RVA: 0x9217A0
void __fastcall Scaleform::GFx::AS3::Instances::fl_sensors::Accelerometer::mutedGet(
        Scaleform::GFx::AS3::Instances::fl_sensors::Accelerometer *this,
        bool *result)
{
  char v3; // di
  Scaleform::Ptr<Scaleform::GFx::AccelerometerInterface> resulta; // [rsp+40h] [rbp+8h] BYREF

  Scaleform::GFx::StateBag::GetAccelerometerInterface(
    (Scaleform::GFx::StateBag *)this->VMRef[1].vfptr[2].__vecDelDtor + 2,
    &resulta);
  if ( resulta.pObject )
  {
    v3 = ((__int64 (__fastcall *)(Scaleform::GFx::AccelerometerInterface *))resulta.pObject->vfptr[3].__vecDelDtor)(resulta.pObject);
    if ( resulta.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)resulta.pObject);
    *result = v3;
  }
  else
  {
    *result = 0;
  }
}

// File Line: 60
// RVA: 0x926650
void __fastcall Scaleform::GFx::AS3::Instances::fl_sensors::Accelerometer::setRequestedUpdateInterval(
        Scaleform::GFx::AS3::Instances::fl_sensors::Accelerometer *this,
        Scaleform::GFx::AS3::Value *result,
        long double interval)
{
  bool v4; // di
  void *(__fastcall *vecDelDtor)(Scaleform::GFx::AS3::VM *, unsigned int); // rcx
  unsigned int v6; // edi
  unsigned int AccelerometerId; // ebx
  Scaleform::GFx::AS3::Value v8; // [rsp+28h] [rbp-30h] BYREF
  Scaleform::Ptr<Scaleform::GFx::AccelerometerInterface> resulta; // [rsp+70h] [rbp+18h] BYREF
  unsigned int v10; // [rsp+78h] [rbp+20h] BYREF

  v8.Flags = 4;
  v8.Bonus.pWeakProxy = 0i64;
  v8.value.VNumber = interval;
  v4 = Scaleform::GFx::AS3::Value::Convert2Int32(&v8, (Scaleform::GFx::AS3::CheckResult *)&resulta, (int *)&v10)->Result;
  if ( (v8.Flags & 0x1F) > 9 )
  {
    if ( (v8.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v8);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v8);
  }
  if ( v4 )
  {
    vecDelDtor = this->VMRef[1].vfptr[2].__vecDelDtor;
    v6 = v10;
    AccelerometerId = this->AccelerometerId;
    Scaleform::GFx::StateBag::GetAccelerometerInterface((Scaleform::GFx::StateBag *)vecDelDtor + 2, &resulta);
    if ( resulta.pObject )
      ((void (__fastcall *)(Scaleform::GFx::AccelerometerInterface *, _QWORD, _QWORD))resulta.pObject->vfptr[5].__vecDelDtor)(
        resulta.pObject,
        AccelerometerId,
        v6);
    if ( resulta.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)resulta.pObject);
  }
}

// File Line: 77
// RVA: 0x8A3180
void __fastcall Scaleform::GFx::AS3::Instances::fl_sensors::Accelerometer::~Accelerometer(
        Scaleform::GFx::AS3::Instances::fl_sensors::Accelerometer *this)
{
  Scaleform::GFx::AS3::VM *VMRef; // rdi
  Scaleform::GFx::StateBag *vecDelDtor; // rcx
  int AccelerometerId; // edi
  Scaleform::Ptr<Scaleform::GFx::AccelerometerInterface> result; // [rsp+48h] [rbp+10h] BYREF

  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl_sensors::Accelerometer::`vftable;
  VMRef = this->VMRef;
  if ( !VMRef->InDestructor )
  {
    if ( !VMRef[1].vfptr )
      Scaleform::GFx::AS3::MovieRoot::RemoveFromAccelerometers(0i64, this);
    vecDelDtor = (Scaleform::GFx::StateBag *)VMRef[1].vfptr[2].__vecDelDtor;
    if ( vecDelDtor )
    {
      AccelerometerId = this->AccelerometerId;
      Scaleform::GFx::StateBag::GetAccelerometerInterface(vecDelDtor + 2, &result);
      if ( result.pObject )
        result.pObject->vfptr[2].__vecDelDtor(result.pObject, AccelerometerId);
      if ( result.pObject )
        Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)result.pObject);
    }
  }
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::~EventDispatcher(this);
}

// File Line: 129
// RVA: 0x8EAC40
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl_sensors::Accelerometer::MakeObject(
        Scaleform::GFx::AS3::InstanceTraits::fl_sensors::Accelerometer *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::InstanceTraits::fl_sensors::Accelerometer *t)
{
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_sensors::Accelerometer> *Instance; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_sensors::Accelerometer> resulta; // [rsp+48h] [rbp+20h] BYREF

  Instance = Scaleform::GFx::AS3::InstanceTraits::fl_sensors::Accelerometer::MakeInstance(&resulta, t);
  Scaleform::GFx::AS3::Value::Pick(result, Instance->pV);
}

// File Line: 147
// RVA: 0x9211B0
void __fastcall Scaleform::GFx::AS3::Classes::fl_sensors::Accelerometer::isSupportedGet(
        Scaleform::GFx::AS3::Classes::fl_sensors::Accelerometer *this,
        bool *result)
{
  char v3; // di
  Scaleform::Ptr<Scaleform::GFx::AccelerometerInterface> resulta; // [rsp+40h] [rbp+8h] BYREF

  Scaleform::GFx::StateBag::GetAccelerometerInterface(
    (Scaleform::GFx::StateBag *)this->pTraits.pObject->pVM[1].vfptr[2].__vecDelDtor + 2,
    &resulta);
  if ( resulta.pObject )
  {
    v3 = ((__int64 (__fastcall *)(Scaleform::GFx::AccelerometerInterface *))resulta.pObject->vfptr[4].__vecDelDtor)(resulta.pObject);
    if ( resulta.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)resulta.pObject);
    *result = v3;
  }
  else
  {
    *result = 0;
  }
}

// File Line: 160
// RVA: 0x15975D0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Classes::fl_sensors::Accelerometer_0_bool_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243F668 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_sensors::Accelerometer,0,bool>::Method = Scaleform::GFx::AS3::Classes::fl_sensors::Accelerometer::isSupportedGet;
  return result;
}

// File Line: 183
// RVA: 0x87DBA0
Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *__fastcall Scaleform::GFx::AS3::ClassTraits::fl_sensors::Accelerometer::MakeClassTraits(
        Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *result,
        Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::MemoryHeap *MHeap; // rsi
  Scaleform::GFx::AS3::ClassTraits::fl_events::EventDispatcher *v5; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *v6; // rdi
  Scaleform::GFx::AS3::InstanceTraits::fl_events::EventDispatcher *v7; // rax
  Scaleform::GFx::AS3::InstanceTraits::fl_events::EventDispatcher *v8; // rdi
  Scaleform::GFx::AS3::Class *v9; // rax
  Scaleform::GFx::AS3::Class *v10; // rdi

  MHeap = vm->MHeap;
  v5 = (Scaleform::GFx::AS3::ClassTraits::fl_events::EventDispatcher *)MHeap->vfptr->Alloc(MHeap, 208ui64, 0i64);
  v6 = v5;
  if ( v5 )
  {
    Scaleform::GFx::AS3::ClassTraits::fl_events::EventDispatcher::EventDispatcher(
      v5,
      vm,
      &Scaleform::GFx::AS3::fl_sensors::AccelerometerCI);
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_sensors::Accelerometer::`vftable;
  }
  else
  {
    v6 = 0i64;
  }
  result->pV = v6;
  v7 = (Scaleform::GFx::AS3::InstanceTraits::fl_events::EventDispatcher *)MHeap->vfptr->Alloc(MHeap, 240ui64, 0i64);
  v8 = v7;
  if ( v7 )
  {
    Scaleform::GFx::AS3::InstanceTraits::fl_events::EventDispatcher::EventDispatcher(
      v7,
      vm,
      &Scaleform::GFx::AS3::fl_sensors::AccelerometerCI);
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl_sensors::Accelerometer::`vftable;
  }
  else
  {
    v8 = 0i64;
  }
  Scaleform::GFx::AS3::ClassTraits::Traits::SetInstanceTraits(
    result->pV,
    (Scaleform::Pickable<Scaleform::GFx::AS3::InstanceTraits::Traits>)v8);
  v9 = (Scaleform::GFx::AS3::Class *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))MHeap->vfptr->Alloc)(
                                       MHeap,
                                       72i64);
  v10 = v9;
  if ( v9 )
  {
    Scaleform::GFx::AS3::Class::Class(v9, result->pV);
    v10->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Classes::fl_sensors::Accelerometer::`vftable;
  }
  return result;
}

