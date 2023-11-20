// File Line: 38
// RVA: 0x1589BC0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl_external::ExtensionContext_0_Scaleform::GFx::AS3::SPtr_Scaleform::GFx::AS3::Instances::fl::Object___::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243D740 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_external::ExtensionContext,0,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Object>>::Method = (void (__fastcall *const )(Scaleform::GFx::AS3::Instances::fl_external::ExtensionContext *, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Object> *))_;
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
  Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_external::ExtensionContext,1,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Value const &>::Method = (void (__fastcall *const )(Scaleform::GFx::AS3::Instances::fl_external::ExtensionContext *, Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Value *))_;
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
  Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Instances::fl_external::ExtensionContext,2,Scaleform::GFx::AS3::Value,unsigned int,Scaleform::GFx::AS3::Value const *>::Method = (void (__fastcall *const )(Scaleform::GFx::AS3::Instances::fl_external::ExtensionContext *, Scaleform::GFx::AS3::Value *, unsigned int, Scaleform::GFx::AS3::Value *))_;
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
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_external::ExtensionContext,3,Scaleform::GFx::AS3::Value const>::Method = (void (__fastcall *const )(Scaleform::GFx::AS3::Instances::fl_external::ExtensionContext *, Scaleform::GFx::AS3::Value *))_;
  return result;
}

// File Line: 50
// RVA: 0x77CEB0
void __fastcall Scaleform::GFx::AS3::Instances::fl_external::ExtensionContext::ExtensionContext(Scaleform::GFx::AS3::Instances::fl_external::ExtensionContext *this, Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::GFx::AS3::InstanceTraits::Traits *v2; // rbx
  Scaleform::GFx::AS3::Instances::fl_external::ExtensionContext *v3; // rdi
  Scaleform::GFx::AS3::StringManager *v4; // rax
  Scaleform::GFx::ASStringNode *v5; // rcx
  Scaleform::GFx::AS3::StringManager *v6; // rax
  Scaleform::GFx::ASStringNode *v7; // rcx

  v2 = t;
  v3 = this;
  Scaleform::GFx::AS3::Instance::Instance((Scaleform::GFx::AS3::Instance *)&this->vfptr, t);
  v3->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl::Object::`vftable';
  v3->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::`vftable';
  v3->VMRef = v2->pVM;
  v3->pImpl.pObject = 0i64;
  v3->pImpl.Owner = 1;
  v3->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl_external::ExtensionContext::`vftable';
  v4 = v3->pTraits.pObject->pVM->StringManagerRef;
  v5 = v4->Builtins[0].pNode;
  v3->ExtensionID.pNode = v4->Builtins[0].pNode;
  ++v5->RefCount;
  v6 = v3->pTraits.pObject->pVM->StringManagerRef;
  v7 = v6->Builtins[0].pNode;
  v3->ContextID.pNode = v6->Builtins[0].pNode;
  ++v7->RefCount;
}

// File Line: 181
// RVA: 0x78A8E0
void __fastcall Scaleform::GFx::AS3::Instances::fl_external::ExtensionContext::~ExtensionContext(Scaleform::GFx::AS3::Instances::fl_external::ExtensionContext *this)
{
  Scaleform::GFx::AS3::Instances::fl_external::ExtensionContext *v1; // rbx
  Scaleform::GFx::ASStringNode *v2; // rcx
  bool v3; // zf
  Scaleform::GFx::ASStringNode *v4; // rcx

  v1 = this;
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl_external::ExtensionContext::`vftable';
  v2 = this->ContextID.pNode;
  v3 = v2->RefCount-- == 1;
  if ( v3 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v2);
  v4 = v1->ExtensionID.pNode;
  v3 = v4->RefCount-- == 1;
  if ( v3 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v4);
  v1->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::`vftable';
  Scaleform::AutoPtr<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::EventDispatcherImpl>::~AutoPtr<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::EventDispatcherImpl>(&v1->pImpl);
  v1->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instance::`vftable';
  Scaleform::GFx::AS3::Traits::DestructTail(
    (Scaleform::GFx::AS3::Traits *)((_QWORD)v1->pTraits.pObject & 0xFFFFFFFFFFFFFFFEui64),
    (Scaleform::GFx::AS3::Object *)&v1->vfptr);
  Scaleform::GFx::AS3::Object::~Object((Scaleform::GFx::AS3::Object *)&v1->vfptr);
}

// File Line: 217
// RVA: 0x7FF550
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl_external::ExtensionContext::MakeObject(Scaleform::GFx::AS3::InstanceTraits::fl_external::ExtensionContext *this, Scaleform::GFx::AS3::Value *result, Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::GFx::AS3::Value *v3; // rbx
  Scaleform::GFx::AS3::Object **v4; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_external::ExtensionContext> resulta; // [rsp+48h] [rbp+20h]

  v3 = result;
  v4 = (Scaleform::GFx::AS3::Object **)Scaleform::GFx::AS3::InstanceTraits::fl_external::ExtensionContext::MakeInstance(
                                         &resulta,
                                         (Scaleform::GFx::AS3::InstanceTraits::fl_external::ExtensionContext *)t);
  Scaleform::GFx::AS3::Value::Pick(v3, *v4);
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
  Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Classes::fl_external::ExtensionContext,0,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_external::ExtensionContext>,Scaleform::GFx::ASString const &,Scaleform::GFx::ASString const &>::Method = (void (__fastcall *const )(Scaleform::GFx::AS3::Classes::fl_external::ExtensionContext *, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_external::ExtensionContext> *, Scaleform::GFx::ASString *, Scaleform::GFx::ASString *))_;
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
  Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl_external::ExtensionContext,1,Scaleform::GFx::ASString,Scaleform::GFx::ASString const &>::Method = (void (__fastcall *const )(Scaleform::GFx::AS3::Classes::fl_external::ExtensionContext *, Scaleform::GFx::ASString *, Scaleform::GFx::ASString *))_;
  return result;
}

// File Line: 305
// RVA: 0x73C740
Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *__fastcall Scaleform::GFx::AS3::ClassTraits::fl_external::ExtensionContext::MakeClassTraits(Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *result, Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::GFx::AS3::VM *v2; // rbp
  Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *v3; // rdi
  Scaleform::MemoryHeap *v4; // rsi
  Scaleform::GFx::AS3::ClassTraits::Traits *v5; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *v6; // rbx
  Scaleform::GFx::AS3::InstanceTraits::CTraits *v7; // rax
  Scaleform::GFx::AS3::InstanceTraits::CTraits *v8; // rbx
  Scaleform::GFx::AS3::Class *v9; // rax
  Scaleform::GFx::AS3::Class *v10; // rbx

  v2 = vm;
  v3 = result;
  v4 = vm->MHeap;
  v5 = (Scaleform::GFx::AS3::ClassTraits::Traits *)v4->vfptr->Alloc(v4, 208ui64, 0i64);
  v6 = v5;
  if ( v5 )
  {
    Scaleform::GFx::AS3::ClassTraits::Traits::Traits(v5, v2, &Scaleform::GFx::AS3::fl_external::ExtensionContextCI);
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl::Object::`vftable';
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_events::EventDispatcher::`vftable';
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_external::ExtensionContext::`vftable';
  }
  else
  {
    v6 = 0i64;
  }
  v3->pV = v6;
  v7 = (Scaleform::GFx::AS3::InstanceTraits::CTraits *)v4->vfptr->Alloc(v4, 240ui64, 0i64);
  v8 = v7;
  if ( v7 )
  {
    Scaleform::GFx::AS3::InstanceTraits::CTraits::CTraits(v7, v2, &Scaleform::GFx::AS3::fl_external::ExtensionContextCI);
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl::Object::`vftable';
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl_events::EventDispatcher::`vftable';
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl_external::ExtensionContext::`vftable';
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
    v10->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Classes::fl_external::ExtensionContext::`vftable';
  }
  return v3;
}

