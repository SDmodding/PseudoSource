// File Line: 38
// RVA: 0x1589BC0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl_external::ExtensionContext_0_Scaleform::GFx::AS3::SPtr_Scaleform::GFx::AS3::Instances::fl::Object___::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243D740 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_external::ExtensionContext,0,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Object>>::Method = (void (__fastcall *const)(Scaleform::GFx::AS3::Instances::fl_external::ExtensionContext *, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Object> *))_;
  return result;
}

// File Line: 39
// RVA: 0x15906A0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc1_Scaleform::GFx::AS3::Instances::fl_external::ExtensionContext_1_Scaleform::GFx::AS3::Value_const__Scaleform::GFx::AS3::Value_const_____ptr64_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243D750 = v1;
  Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_external::ExtensionContext,1,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Value const &>::Method = (void (__fastcall *const)(Scaleform::GFx::AS3::Instances::fl_external::ExtensionContext *, Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Value *))_;
  return result;
}

// File Line: 40
// RVA: 0x1594F30
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc2_Scaleform::GFx::AS3::Instances::fl_external::ExtensionContext_2_Scaleform::GFx::AS3::Value_unsigned_int_Scaleform::GFx::AS3::Value_const_____ptr64_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243D760 = v1;
  Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Instances::fl_external::ExtensionContext,2,Scaleform::GFx::AS3::Value,unsigned int,Scaleform::GFx::AS3::Value const *>::Method = (void (__fastcall *const)(Scaleform::GFx::AS3::Instances::fl_external::ExtensionContext *, Scaleform::GFx::AS3::Value *, unsigned int, Scaleform::GFx::AS3::Value *))_;
  return result;
}

// File Line: 41
// RVA: 0x1589B90
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl_external::ExtensionContext_3_Scaleform::GFx::AS3::Value_const__::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243D770 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_external::ExtensionContext,3,Scaleform::GFx::AS3::Value const>::Method = (void (__fastcall *const)(Scaleform::GFx::AS3::Instances::fl_external::ExtensionContext *, Scaleform::GFx::AS3::Value *))_;
  return result;
}

// File Line: 50
// RVA: 0x77CEB0
void __fastcall Scaleform::GFx::AS3::Instances::fl_external::ExtensionContext::ExtensionContext(
        Scaleform::GFx::AS3::Instances::fl_external::ExtensionContext *this,
        Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::GFx::AS3::StringManager *StringManagerRef; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS3::StringManager *v6; // rax
  Scaleform::GFx::ASStringNode *v7; // rcx

  Scaleform::GFx::AS3::Instance::Instance(this, t);
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl::Object::`vftable;
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::`vftable;
  this->VMRef = t->pVM;
  this->pImpl.pObject = 0i64;
  this->pImpl.Owner = 1;
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl_external::ExtensionContext::`vftable;
  StringManagerRef = this->pTraits.pObject->pVM->StringManagerRef;
  pNode = StringManagerRef->Builtins[0].pNode;
  this->ExtensionID.pNode = StringManagerRef->Builtins[0].pNode;
  ++pNode->RefCount;
  v6 = this->pTraits.pObject->pVM->StringManagerRef;
  v7 = v6->Builtins[0].pNode;
  this->ContextID.pNode = v6->Builtins[0].pNode;
  ++v7->RefCount;
}

// File Line: 181
// RVA: 0x78A8E0
void __fastcall Scaleform::GFx::AS3::Instances::fl_external::ExtensionContext::~ExtensionContext(
        Scaleform::GFx::AS3::Instances::fl_external::ExtensionContext *this)
{
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v3; // zf
  Scaleform::GFx::ASStringNode *v4; // rcx

  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl_external::ExtensionContext::`vftable;
  pNode = this->ContextID.pNode;
  v3 = pNode->RefCount-- == 1;
  if ( v3 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  v4 = this->ExtensionID.pNode;
  v3 = v4->RefCount-- == 1;
  if ( v3 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v4);
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::`vftable;
  Scaleform::AutoPtr<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::EventDispatcherImpl>::~AutoPtr<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::EventDispatcherImpl>(&this->pImpl);
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instance::`vftable;
  Scaleform::GFx::AS3::Traits::DestructTail(
    (Scaleform::GFx::AS3::Traits *)((unsigned __int64)this->pTraits.pObject & 0xFFFFFFFFFFFFFFFEui64),
    this);
  Scaleform::GFx::AS3::Object::~Object(this);
}

// File Line: 217
// RVA: 0x7FF550
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl_external::ExtensionContext::MakeObject(
        Scaleform::GFx::AS3::InstanceTraits::fl_external::ExtensionContext *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::InstanceTraits::fl_external::ExtensionContext *t)
{
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_external::ExtensionContext> *Instance; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_external::ExtensionContext> resulta; // [rsp+48h] [rbp+20h] BYREF

  Instance = Scaleform::GFx::AS3::InstanceTraits::fl_external::ExtensionContext::MakeInstance(&resulta, t);
  Scaleform::GFx::AS3::Value::Pick(result, Instance->pV);
}

// File Line: 279
// RVA: 0x1594F00
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc2_Scaleform::GFx::AS3::Classes::fl_external::ExtensionContext_0_Scaleform::GFx::AS3::SPtr_Scaleform::GFx::AS3::Instances::fl_external::ExtensionContext__Scaleform::GFx::ASString_const_____ptr64_Scaleform::GFx::ASString_const_____ptr64_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243D780 = v1;
  Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Classes::fl_external::ExtensionContext,0,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_external::ExtensionContext>,Scaleform::GFx::ASString const &,Scaleform::GFx::ASString const &>::Method = (void (__fastcall *const)(Scaleform::GFx::AS3::Classes::fl_external::ExtensionContext *, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_external::ExtensionContext> *, Scaleform::GFx::ASString *, Scaleform::GFx::ASString *))_;
  return result;
}

// File Line: 280
// RVA: 0x1590670
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc1_Scaleform::GFx::AS3::Classes::fl_external::ExtensionContext_1_Scaleform::GFx::ASString_Scaleform::GFx::ASString_const_____ptr64_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243D790 = v1;
  Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl_external::ExtensionContext,1,Scaleform::GFx::ASString,Scaleform::GFx::ASString const &>::Method = (void (__fastcall *const)(Scaleform::GFx::AS3::Classes::fl_external::ExtensionContext *, Scaleform::GFx::ASString *, Scaleform::GFx::ASString *))_;
  return result;
}

// File Line: 305
// RVA: 0x73C740
Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *__fastcall Scaleform::GFx::AS3::ClassTraits::fl_external::ExtensionContext::MakeClassTraits(
        Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *result,
        Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::MemoryHeap *MHeap; // rsi
  Scaleform::GFx::AS3::ClassTraits::Traits *v5; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *v6; // rbx
  Scaleform::GFx::AS3::InstanceTraits::CTraits *v7; // rax
  Scaleform::GFx::AS3::InstanceTraits::CTraits *v8; // rbx
  Scaleform::GFx::AS3::Class *v9; // rax
  Scaleform::GFx::AS3::Class *v10; // rbx

  MHeap = vm->MHeap;
  v5 = (Scaleform::GFx::AS3::ClassTraits::Traits *)MHeap->vfptr->Alloc(MHeap, 208ui64, 0i64);
  v6 = v5;
  if ( v5 )
  {
    Scaleform::GFx::AS3::ClassTraits::Traits::Traits(v5, vm, &Scaleform::GFx::AS3::fl_external::ExtensionContextCI);
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl::Object::`vftable;
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_events::EventDispatcher::`vftable;
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_external::ExtensionContext::`vftable;
  }
  else
  {
    v6 = 0i64;
  }
  result->pV = v6;
  v7 = (Scaleform::GFx::AS3::InstanceTraits::CTraits *)MHeap->vfptr->Alloc(MHeap, 240ui64, 0i64);
  v8 = v7;
  if ( v7 )
  {
    Scaleform::GFx::AS3::InstanceTraits::CTraits::CTraits(v7, vm, &Scaleform::GFx::AS3::fl_external::ExtensionContextCI);
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl::Object::`vftable;
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl_events::EventDispatcher::`vftable;
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl_external::ExtensionContext::`vftable;
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
    v10->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Classes::fl_external::ExtensionContext::`vftable;
  }
  return result;
}

