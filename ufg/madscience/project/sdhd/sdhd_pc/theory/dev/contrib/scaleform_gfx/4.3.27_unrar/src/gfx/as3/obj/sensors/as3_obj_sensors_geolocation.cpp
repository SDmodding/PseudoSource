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
  Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_sensors::Geolocation,1,Scaleform::GFx::AS3::Value const,double>::Method = (void (__fastcall *const )(Scaleform::GFx::AS3::Instances::fl_sensors::Geolocation *, Scaleform::GFx::AS3::Value *, long double))Scaleform::GFx::AS3::Instances::fl_sensors::Geolocation::setRequestedUpdateInterval;
  return result;
}

// File Line: 44
// RVA: 0x897190
void __fastcall Scaleform::GFx::AS3::Instances::fl_sensors::Geolocation::Geolocation(Scaleform::GFx::AS3::Instances::fl_sensors::Geolocation *this, Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::GFx::AS3::Instances::fl_sensors::Geolocation *v2; // rdi
  Scaleform::GFx::AS3::VM *v3; // rbx
  Scaleform::GFx::StateBag *v4; // rcx
  unsigned int v5; // ebx
  Scaleform::Ptr<Scaleform::GFx::GeolocationInterface> result; // [rsp+50h] [rbp+18h]

  v2 = this;
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::EventDispatcher(
    (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)&this->vfptr,
    t);
  v2->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl_sensors::Geolocation::`vftable';
  v2->GeolocationId = Scaleform::GFx::AS3::Instances::fl_sensors::Geolocation::GeolocationIdCount++;
  v3 = v2->VMRef;
  Scaleform::GFx::AS3::MovieRoot::AddToGeolocations((Scaleform::GFx::AS3::MovieRoot *)v3[1].vfptr, v2);
  v4 = (Scaleform::GFx::StateBag *)v3[1].vfptr[2].__vecDelDtor;
  v5 = v2->GeolocationId;
  Scaleform::GFx::StateBag::GetGeolocationInterface(v4 + 2, &result);
  if ( result.pObject )
    result.pObject->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)result.pObject, v5);
  if ( result.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)result.pObject);
}

// File Line: 53
// RVA: 0x921820
void __fastcall Scaleform::GFx::AS3::Instances::fl_sensors::Geolocation::mutedGet(Scaleform::GFx::AS3::Instances::fl_sensors::Geolocation *this, bool *result)
{
  bool *v2; // rbx
  char v3; // di
  Scaleform::Ptr<Scaleform::GFx::GeolocationInterface> resulta; // [rsp+40h] [rbp+8h]

  v2 = result;
  Scaleform::GFx::StateBag::GetGeolocationInterface(
    (Scaleform::GFx::StateBag *)this->VMRef[1].vfptr[2].__vecDelDtor + 2,
    &resulta);
  if ( resulta.pObject )
  {
    v3 = ((__int64 (__cdecl *)(Scaleform::GFx::GeolocationInterface *))resulta.pObject->vfptr[3].__vecDelDtor)(resulta.pObject);
    if ( resulta.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)resulta.pObject);
    *v2 = v3;
  }
  else
  {
    *v2 = 0;
  }
}

// File Line: 60
// RVA: 0x926710
void __usercall Scaleform::GFx::AS3::Instances::fl_sensors::Geolocation::setRequestedUpdateInterval(Scaleform::GFx::AS3::Instances::fl_sensors::Geolocation *this@<rcx>, Scaleform::GFx::AS3::Value *result@<rdx>, long double interval@<xmm2>, __int64 a4@<rdi>, __int64 a5@<rsi>)
{
  Scaleform::GFx::AS3::Instances::fl_sensors::Geolocation *v5; // rbx
  bool v6; // di
  Scaleform::GFx::StateBag *v7; // rcx
  unsigned int v8; // edi
  unsigned int v9; // ebx
  Scaleform::GFx::AS3::Value v10; // [rsp+28h] [rbp-30h]
  Scaleform::Ptr<Scaleform::GFx::GeolocationInterface> resulta; // [rsp+70h] [rbp+18h]
  unsigned int v12; // [rsp+78h] [rbp+20h]

  v5 = this;
  v10.Flags = 4;
  v10.Bonus.pWeakProxy = 0i64;
  v10.value.VNumber = interval;
  v6 = Scaleform::GFx::AS3::Value::Convert2Int32(
         &v10,
         (Scaleform::GFx::AS3::CheckResult *)&resulta,
         (int *)&v12,
         (__int64)this,
         a4,
         a5)->Result;
  if ( (v10.Flags & 0x1F) > 9 )
  {
    if ( (v10.Flags >> 9) & 1 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v10);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v10);
  }
  if ( v6 )
  {
    v7 = (Scaleform::GFx::StateBag *)v5->VMRef[1].vfptr[2].__vecDelDtor;
    v8 = v12;
    v9 = v5->GeolocationId;
    Scaleform::GFx::StateBag::GetGeolocationInterface(v7 + 2, &resulta);
    if ( resulta.pObject )
      ((void (__fastcall *)(Scaleform::GFx::GeolocationInterface *, _QWORD, _QWORD))resulta.pObject->vfptr[5].__vecDelDtor)(
        resulta.pObject,
        v9,
        v8);
    if ( resulta.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)resulta.pObject);
  }
}

// File Line: 78
// RVA: 0x8A4CD0
void __fastcall Scaleform::GFx::AS3::Instances::fl_sensors::Geolocation::~Geolocation(Scaleform::GFx::AS3::Instances::fl_sensors::Geolocation *this)
{
  Scaleform::GFx::AS3::Instances::fl_sensors::Geolocation *v1; // rbx
  Scaleform::GFx::AS3::VM *v2; // rdi
  Scaleform::GFx::AS3::MovieRoot *v3; // rcx
  Scaleform::GFx::StateBag *v4; // rcx
  unsigned int v5; // edi
  Scaleform::Ptr<Scaleform::GFx::GeolocationInterface> result; // [rsp+48h] [rbp+10h]

  v1 = this;
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl_sensors::Geolocation::`vftable';
  v2 = this->VMRef;
  if ( !v2->InDestructor )
  {
    v3 = (Scaleform::GFx::AS3::MovieRoot *)v2[1].vfptr;
    if ( v3 )
      Scaleform::GFx::AS3::MovieRoot::RemoveFromGeolocations(v3, v1);
    v4 = (Scaleform::GFx::StateBag *)v2[1].vfptr[2].__vecDelDtor;
    if ( v4 )
    {
      v5 = v1->GeolocationId;
      Scaleform::GFx::StateBag::GetGeolocationInterface(v4 + 2, &result);
      if ( result.pObject )
        result.pObject->vfptr[2].__vecDelDtor((Scaleform::RefCountImplCore *)result.pObject, v5);
      if ( result.pObject )
        Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)result.pObject);
    }
  }
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::~EventDispatcher((Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)&v1->vfptr);
}

// File Line: 130
// RVA: 0x8EAE20
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl_sensors::Geolocation::MakeObject(Scaleform::GFx::AS3::InstanceTraits::fl_sensors::Geolocation *this, Scaleform::GFx::AS3::Value *result, Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::GFx::AS3::Value *v3; // rbx
  Scaleform::GFx::AS3::Object **v4; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_sensors::Geolocation> resulta; // [rsp+48h] [rbp+20h]

  v3 = result;
  v4 = (Scaleform::GFx::AS3::Object **)Scaleform::GFx::AS3::InstanceTraits::fl_sensors::Geolocation::MakeInstance(
                                         &resulta,
                                         (Scaleform::GFx::AS3::InstanceTraits::fl_sensors::Geolocation *)t);
  Scaleform::GFx::AS3::Value::Pick(v3, *v4);
}

// File Line: 148
// RVA: 0x921230
void __fastcall Scaleform::GFx::AS3::Classes::fl_sensors::Geolocation::isSupportedGet(Scaleform::GFx::AS3::Classes::fl_sensors::Geolocation *this, bool *result)
{
  bool *v2; // rbx
  char v3; // di
  Scaleform::Ptr<Scaleform::GFx::GeolocationInterface> resulta; // [rsp+40h] [rbp+8h]

  v2 = result;
  Scaleform::GFx::StateBag::GetGeolocationInterface(
    (Scaleform::GFx::StateBag *)this->pTraits.pObject->pVM[1].vfptr[2].__vecDelDtor + 2,
    &resulta);
  if ( resulta.pObject )
  {
    v3 = ((__int64 (__cdecl *)(Scaleform::GFx::GeolocationInterface *))resulta.pObject->vfptr[4].__vecDelDtor)(resulta.pObject);
    if ( resulta.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)resulta.pObject);
    *v2 = v3;
  }
  else
  {
    *v2 = 0;
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
Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *__fastcall Scaleform::GFx::AS3::ClassTraits::fl_sensors::Geolocation::MakeClassTraits(Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *result, Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::GFx::AS3::VM *v2; // rbp
  Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *v3; // rbx
  Scaleform::MemoryHeap *v4; // rsi
  Scaleform::GFx::AS3::ClassTraits::fl_events::EventDispatcher *v5; // rax
  Scaleform::GFx::AS3::ClassTraits::fl_events::EventDispatcher *v6; // rdi
  Scaleform::GFx::AS3::InstanceTraits::fl_events::EventDispatcher *v7; // rax
  Scaleform::GFx::AS3::InstanceTraits::fl_events::EventDispatcher *v8; // rdi
  Scaleform::GFx::AS3::Class *v9; // rax
  Scaleform::GFx::AS3::Class *v10; // rdi

  v2 = vm;
  v3 = result;
  v4 = vm->MHeap;
  v5 = (Scaleform::GFx::AS3::ClassTraits::fl_events::EventDispatcher *)v4->vfptr->Alloc(v4, 208ui64, 0i64);
  v6 = v5;
  if ( v5 )
  {
    Scaleform::GFx::AS3::ClassTraits::fl_events::EventDispatcher::EventDispatcher(
      v5,
      v2,
      &Scaleform::GFx::AS3::fl_sensors::GeolocationCI);
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_sensors::Geolocation::`vftable';
  }
  else
  {
    v6 = 0i64;
  }
  v3->pV = (Scaleform::GFx::AS3::ClassTraits::Traits *)&v6->vfptr;
  v7 = (Scaleform::GFx::AS3::InstanceTraits::fl_events::EventDispatcher *)v4->vfptr->Alloc(v4, 240ui64, 0i64);
  v8 = v7;
  if ( v7 )
  {
    Scaleform::GFx::AS3::InstanceTraits::fl_events::EventDispatcher::EventDispatcher(
      v7,
      v2,
      &Scaleform::GFx::AS3::fl_sensors::GeolocationCI);
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl_sensors::Geolocation::`vftable';
  }
  else
  {
    v8 = 0i64;
  }
  Scaleform::GFx::AS3::ClassTraits::Traits::SetInstanceTraits(
    v3->pV,
    (Scaleform::Pickable<Scaleform::GFx::AS3::InstanceTraits::Traits>)v8);
  v9 = (Scaleform::GFx::AS3::Class *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))v4->vfptr->Alloc)(
                                       v4,
                                       72i64);
  v10 = v9;
  if ( v9 )
  {
    Scaleform::GFx::AS3::Class::Class(v9, v3->pV);
    v10->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Classes::fl_sensors::Geolocation::`vftable';
  }
  return v3;
}

