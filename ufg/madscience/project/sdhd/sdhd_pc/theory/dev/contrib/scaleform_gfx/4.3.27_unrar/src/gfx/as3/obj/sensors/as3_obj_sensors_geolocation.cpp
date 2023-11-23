// File Line: 34
// RVA: 0x1598110
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl_sensors::Geolocation_0_bool_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243F618 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_sensors::Geolocation,0,bool>::Method = Scaleform::GFx::AS3::Instances::fl_sensors::Geolocation::mutedGet;
  return result;
}

// File Line: 35
// RVA: 0x1599D30
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc1_Scaleform::GFx::AS3::Instances::fl_sensors::Geolocation_1_Scaleform::GFx::AS3::Value_const__double_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243F628 = v1;
  Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_sensors::Geolocation,1,Scaleform::GFx::AS3::Value const,double>::Method = Scaleform::GFx::AS3::Instances::fl_sensors::Geolocation::setRequestedUpdateInterval;
  return result;
}

// File Line: 44
// RVA: 0x897190
void __fastcall Scaleform::GFx::AS3::Instances::fl_sensors::Geolocation::Geolocation(
        Scaleform::GFx::AS3::Instances::fl_sensors::Geolocation *this,
        Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::GFx::AS3::VM *VMRef; // rbx
  Scaleform::GFx::StateBag *vecDelDtor; // rcx
  int GeolocationId; // ebx
  Scaleform::Ptr<Scaleform::GFx::GeolocationInterface> result; // [rsp+50h] [rbp+18h] BYREF

  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::EventDispatcher(this, t);
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl_sensors::Geolocation::`vftable;
  this->GeolocationId = Scaleform::GFx::AS3::Instances::fl_sensors::Geolocation::GeolocationIdCount++;
  VMRef = this->VMRef;
  Scaleform::GFx::AS3::MovieRoot::AddToGeolocations(
    (Scaleform::GFx::AS3::MovieRoot *)VMRef[1].vfptr,
    (Scaleform::GFx::AS2::Object *)this);
  vecDelDtor = (Scaleform::GFx::StateBag *)VMRef[1].vfptr[2].__vecDelDtor;
  GeolocationId = this->GeolocationId;
  Scaleform::GFx::StateBag::GetGeolocationInterface(vecDelDtor + 2, &result);
  if ( result.pObject )
    result.pObject->vfptr[1].__vecDelDtor(result.pObject, GeolocationId);
  if ( result.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)result.pObject);
}

// File Line: 53
// RVA: 0x921820
void __fastcall Scaleform::GFx::AS3::Instances::fl_sensors::Geolocation::mutedGet(
        Scaleform::GFx::AS3::Instances::fl_sensors::Geolocation *this,
        bool *result)
{
  char v3; // di
  Scaleform::Ptr<Scaleform::GFx::GeolocationInterface> resulta; // [rsp+40h] [rbp+8h] BYREF

  Scaleform::GFx::StateBag::GetGeolocationInterface(
    (Scaleform::GFx::StateBag *)this->VMRef[1].vfptr[2].__vecDelDtor + 2,
    &resulta);
  if ( resulta.pObject )
  {
    v3 = ((__int64 (__fastcall *)(Scaleform::GFx::GeolocationInterface *))resulta.pObject->vfptr[3].__vecDelDtor)(resulta.pObject);
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
// RVA: 0x926710
void __fastcall Scaleform::GFx::AS3::Instances::fl_sensors::Geolocation::setRequestedUpdateInterval(
        Scaleform::GFx::AS3::Instances::fl_sensors::Geolocation *this,
        Scaleform::GFx::AS3::Value *result,
        long double interval)
{
  bool v4; // di
  void *(__fastcall *vecDelDtor)(Scaleform::GFx::AS3::VM *, unsigned int); // rcx
  unsigned int v6; // edi
  unsigned int GeolocationId; // ebx
  Scaleform::GFx::AS3::Value v8; // [rsp+28h] [rbp-30h] BYREF
  Scaleform::Ptr<Scaleform::GFx::GeolocationInterface> resulta; // [rsp+70h] [rbp+18h] BYREF
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
    GeolocationId = this->GeolocationId;
    Scaleform::GFx::StateBag::GetGeolocationInterface((Scaleform::GFx::StateBag *)vecDelDtor + 2, &resulta);
    if ( resulta.pObject )
      ((void (__fastcall *)(Scaleform::GFx::GeolocationInterface *, _QWORD, _QWORD))resulta.pObject->vfptr[5].__vecDelDtor)(
        resulta.pObject,
        GeolocationId,
        v6);
    if ( resulta.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)resulta.pObject);
  }
}

// File Line: 78
// RVA: 0x8A4CD0
void __fastcall Scaleform::GFx::AS3::Instances::fl_sensors::Geolocation::~Geolocation(
        Scaleform::GFx::AS3::Instances::fl_sensors::Geolocation *this)
{
  Scaleform::GFx::AS3::VM *VMRef; // rdi
  Scaleform::GFx::AS3::MovieRoot *vfptr; // rcx
  Scaleform::GFx::StateBag *vecDelDtor; // rcx
  int GeolocationId; // edi
  Scaleform::Ptr<Scaleform::GFx::GeolocationInterface> result; // [rsp+48h] [rbp+10h] BYREF

  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl_sensors::Geolocation::`vftable;
  VMRef = this->VMRef;
  if ( !VMRef->InDestructor )
  {
    vfptr = (Scaleform::GFx::AS3::MovieRoot *)VMRef[1].vfptr;
    if ( vfptr )
      Scaleform::GFx::AS3::MovieRoot::RemoveFromGeolocations(vfptr, this);
    vecDelDtor = (Scaleform::GFx::StateBag *)VMRef[1].vfptr[2].__vecDelDtor;
    if ( vecDelDtor )
    {
      GeolocationId = this->GeolocationId;
      Scaleform::GFx::StateBag::GetGeolocationInterface(vecDelDtor + 2, &result);
      if ( result.pObject )
        result.pObject->vfptr[2].__vecDelDtor(result.pObject, GeolocationId);
      if ( result.pObject )
        Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)result.pObject);
    }
  }
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::~EventDispatcher(this);
}

// File Line: 130
// RVA: 0x8EAE20
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl_sensors::Geolocation::MakeObject(
        Scaleform::GFx::AS3::InstanceTraits::fl_sensors::Geolocation *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::InstanceTraits::fl_sensors::Geolocation *t)
{
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_sensors::Geolocation> *Instance; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_sensors::Geolocation> resulta; // [rsp+48h] [rbp+20h] BYREF

  Instance = Scaleform::GFx::AS3::InstanceTraits::fl_sensors::Geolocation::MakeInstance(&resulta, t);
  Scaleform::GFx::AS3::Value::Pick(result, Instance->pV);
}

// File Line: 148
// RVA: 0x921230
void __fastcall Scaleform::GFx::AS3::Classes::fl_sensors::Geolocation::isSupportedGet(
        Scaleform::GFx::AS3::Classes::fl_sensors::Geolocation *this,
        bool *result)
{
  char v3; // di
  Scaleform::Ptr<Scaleform::GFx::GeolocationInterface> resulta; // [rsp+40h] [rbp+8h] BYREF

  Scaleform::GFx::StateBag::GetGeolocationInterface(
    (Scaleform::GFx::StateBag *)this->pTraits.pObject->pVM[1].vfptr[2].__vecDelDtor + 2,
    &resulta);
  if ( resulta.pObject )
  {
    v3 = ((__int64 (__fastcall *)(Scaleform::GFx::GeolocationInterface *))resulta.pObject->vfptr[4].__vecDelDtor)(resulta.pObject);
    if ( resulta.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)resulta.pObject);
    *result = v3;
  }
  else
  {
    *result = 0;
  }
}

// File Line: 161
// RVA: 0x15980E0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Classes::fl_sensors::Geolocation_0_bool_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243F638 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_sensors::Geolocation,0,bool>::Method = Scaleform::GFx::AS3::Classes::fl_sensors::Geolocation::isSupportedGet;
  return result;
}

// File Line: 184
// RVA: 0x8757B0
Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *__fastcall Scaleform::GFx::AS3::ClassTraits::fl_sensors::Geolocation::MakeClassTraits(
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
      &Scaleform::GFx::AS3::fl_sensors::GeolocationCI);
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_sensors::Geolocation::`vftable;
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
      &Scaleform::GFx::AS3::fl_sensors::GeolocationCI);
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl_sensors::Geolocation::`vftable;
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
    v10->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Classes::fl_sensors::Geolocation::`vftable;
  }
  return result;
}

