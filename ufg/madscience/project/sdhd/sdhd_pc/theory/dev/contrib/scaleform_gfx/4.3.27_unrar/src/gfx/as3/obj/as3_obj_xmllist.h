// File Line: 112
// RVA: 0x7B0C50
void __fastcall Scaleform::GFx::AS3::Instances::fl::XMLList::Apppend(
        Scaleform::GFx::AS3::Instances::fl::XMLList *this,
        Scaleform::GFx::AS3::Instances::fl::XML *v)
{
  Scaleform::ArrayLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2,Scaleform::ArrayDefaultPolicy> *p_List; // rbx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *v4; // rdx
  unsigned int RefCount; // eax

  if ( v )
    v->RefCount = (v->RefCount + 1) & 0x8FBFFFFF;
  p_List = &this->List;
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy> *)&this->List,
    &this->List,
    this->List.Data.Size + 1);
  v4 = &p_List->Data.Data[p_List->Data.Size - 1];
  if ( v4 )
  {
    v4->pObject = v;
    if ( v )
      v->RefCount = (v->RefCount + 1) & 0x8FBFFFFF;
  }
  if ( v && ((unsigned __int8)v & 1) == 0 )
  {
    RefCount = v->RefCount;
    if ( (RefCount & 0x3FFFFF) != 0 )
    {
      v->RefCount = RefCount - 1;
      Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v);
    }
  }
}

// File Line: 130
// RVA: 0x789CC0
void __fastcall Scaleform::GFx::AS3::Instances::fl::XMLList::CallBack::~CallBack(
        Scaleform::GFx::AS3::Instances::fl::XMLList::CallBack *this)
{
  this->vfptr = (Scaleform::GFx::AS3::Instances::fl::XMLList::CallBackVtbl *)&Scaleform::GFx::AS3::Instances::fl::XMLList::CallBack::`vftable;
}

// File Line: 383
// RVA: 0x7A8C80
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::AS3::Instances::fl::XMLList::AS3toXMLString(
        Scaleform::GFx::AS3::Instances::fl::XMLList *this,
        Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
    this->pTraits.pObject->pVM->StringManagerRef,
    result);
  Scaleform::GFx::AS3::Instances::fl::XMLList::AS3toXMLString(this, result);
  return result;
}

// File Line: 476
// RVA: 0x7FE260
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> *__fastcall Scaleform::GFx::AS3::InstanceTraits::fl::XMLList::MakeInstance(
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> *result,
        Scaleform::GFx::AS3::InstanceTraits::fl::XMLList *t)
{
  Scaleform::GFx::AS3::Instance *v4; // rax
  Scaleform::GFx::AS3::Instances::fl::XMLList *v5; // rbx
  int v7; // [rsp+50h] [rbp+8h] BYREF
  Scaleform::GFx::AS3::Instance *v8; // [rsp+58h] [rbp+10h]
  Scaleform::GFx::AS3::Instance *v9; // [rsp+60h] [rbp+18h]
  Scaleform::ArrayLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2,Scaleform::ArrayDefaultPolicy> *p_List; // [rsp+68h] [rbp+20h]

  v7 = 337;
  v4 = (Scaleform::GFx::AS3::Instance *)t->pVM->MHeap->vfptr->Alloc(t->pVM->MHeap, t->MemSize, &v7);
  v5 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)v4;
  v8 = v4;
  v9 = v4;
  if ( v4 )
  {
    Scaleform::GFx::AS3::Instance::Instance(v4, t);
    v5->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl::Object::`vftable;
    v5->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl::XMLList::`vftable;
    v5->TargetObject.pObject = 0i64;
    v5->TargetProperty = 0i64;
    v5->TargetNamespace.pObject = 0i64;
    p_List = &v5->List;
    v5->List.Data.Data = 0i64;
    v5->List.Data.Size = 0i64;
    v5->List.Data.Policy.Capacity = 0i64;
  }
  else
  {
    v5 = 0i64;
  }
  result->pV = v5;
  return result;
}

