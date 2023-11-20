// File Line: 112
// RVA: 0x7B0C50
void __fastcall Scaleform::GFx::AS3::Instances::fl::XMLList::Apppend(Scaleform::GFx::AS3::Instances::fl::XMLList *this, Scaleform::GFx::AS3::Instances::fl::XML *v)
{
  Scaleform::GFx::AS3::Instances::fl::XML *v2; // rdi
  Scaleform::ArrayLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2,Scaleform::ArrayDefaultPolicy> *v3; // rbx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *v4; // rdx
  unsigned int v5; // eax

  v2 = v;
  if ( v )
    v->RefCount = (v->RefCount + 1) & 0x8FBFFFFF;
  v3 = &this->List;
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy> *)&this->List,
    &this->List,
    this->List.Data.Size + 1);
  v4 = &v3->Data.Data[v3->Data.Size - 1];
  if ( v4 )
  {
    v4->pObject = v2;
    if ( v2 )
      v2->RefCount = (v2->RefCount + 1) & 0x8FBFFFFF;
  }
  if ( v2 && !((unsigned __int8)v2 & 1) )
  {
    v5 = v2->RefCount;
    if ( v5 & 0x3FFFFF )
    {
      v2->RefCount = v5 - 1;
      Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v2->vfptr);
    }
  }
}

// File Line: 130
// RVA: 0x789CC0
void __fastcall Scaleform::GFx::AS3::Instances::fl::XMLList::CallBack::~CallBack(Scaleform::GFx::AS3::Instances::fl::XMLList::CallBack *this)
{
  this->vfptr = (Scaleform::GFx::AS3::Instances::fl::XMLList::CallBackVtbl *)&Scaleform::GFx::AS3::Instances::fl::XMLList::CallBack::`vftable;
}

// File Line: 383
// RVA: 0x7A8C80
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::AS3::Instances::fl::XMLList::AS3toXMLString(Scaleform::GFx::AS3::Instances::fl::XMLList *this, Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::ASString *v2; // rdi
  Scaleform::GFx::AS3::Instances::fl::XMLList *v3; // rbx

  v2 = result;
  v3 = this;
  Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
    (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)this->pTraits.pObject->pVM->StringManagerRef->Builtins,
    result);
  Scaleform::GFx::AS3::Instances::fl::XMLList::AS3toXMLString(v3, v2);
  return v2;
}

// File Line: 476
// RVA: 0x7FE260
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> *__fastcall Scaleform::GFx::AS3::InstanceTraits::fl::XMLList::MakeInstance(Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> *result, Scaleform::GFx::AS3::InstanceTraits::fl::XMLList *t)
{
  Scaleform::GFx::AS3::InstanceTraits::fl::XMLList *v2; // rsi
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> *v3; // rdi
  Scaleform::GFx::AS3::Instance *v4; // rax
  Scaleform::GFx::AS3::Instances::fl::XMLList *v5; // rbx
  Scaleform::ArrayLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2,Scaleform::ArrayDefaultPolicy> *v6; // rax
  int v8; // [rsp+50h] [rbp+8h]
  Scaleform::GFx::AS3::Instance *v9; // [rsp+58h] [rbp+10h]
  Scaleform::GFx::AS3::Instance *v10; // [rsp+60h] [rbp+18h]
  Scaleform::ArrayLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2,Scaleform::ArrayDefaultPolicy> *v11; // [rsp+68h] [rbp+20h]

  v2 = t;
  v3 = result;
  v8 = 337;
  v4 = (Scaleform::GFx::AS3::Instance *)t->pVM->MHeap->vfptr->Alloc(
                                          t->pVM->MHeap,
                                          t->MemSize,
                                          (Scaleform::AllocInfo *)&v8);
  v5 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)v4;
  v9 = v4;
  v10 = v4;
  if ( v4 )
  {
    Scaleform::GFx::AS3::Instance::Instance(v4, (Scaleform::GFx::AS3::InstanceTraits::Traits *)&v2->vfptr);
    v5->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl::Object::`vftable;
    v5->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl::XMLList::`vftable;
    v5->TargetObject.pObject = 0i64;
    v5->TargetProperty = 0i64;
    v5->TargetNamespace.pObject = 0i64;
    v6 = &v5->List;
    v11 = v6;
    v6->Data.Data = 0i64;
    v6->Data.Size = 0i64;
    v6->Data.Policy.Capacity = 0i64;
  }
  else
  {
    v5 = 0i64;
  }
  v3->pV = v5;
  return v3;
}

