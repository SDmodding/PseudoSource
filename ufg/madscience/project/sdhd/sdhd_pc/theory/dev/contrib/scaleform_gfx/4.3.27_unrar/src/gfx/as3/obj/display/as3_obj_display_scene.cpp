// File Line: 37
// RVA: 0x158C860
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl_display::Scene_0_Scaleform::GFx::AS3::SPtr_Scaleform::GFx::AS3::Instances::fl::Array___::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243C410 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::Scene,0,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Array>>::Method = Scaleform::GFx::AS3::Instances::fl_display::Scene::labelsGet;
  return result;
}

// File Line: 38
// RVA: 0x158C800
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl_display::Scene_1_Scaleform::GFx::ASString_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243C420 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::Scene,1,Scaleform::GFx::ASString>::Method = Scaleform::GFx::AS3::Instances::fl_display::Scene::nameGet;
  return result;
}

// File Line: 39
// RVA: 0x158C830
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl_display::Scene_2_long_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243C430 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::Scene,2,long>::Method = Scaleform::GFx::AS3::Instances::fl_display::Scene::numFramesGet;
  return result;
}

// File Line: 54
// RVA: 0x850E30
Scaleform::GFx::AS3::Instances::fl_display::Scene::labelsGet

// File Line: 108
// RVA: 0x854F60
void __fastcall Scaleform::GFx::AS3::Instances::fl_display::Scene::nameGet(Scaleform::GFx::AS3::Instances::fl_display::Scene *this, Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::ASString *v2; // rbx
  Scaleform::GFx::MovieDataDef::SceneInfo *v3; // rdx
  Scaleform::GFx::ASStringNode *v4; // rdi
  Scaleform::GFx::ASStringNode *v5; // rcx
  bool v6; // zf
  Scaleform::GFx::ASStringNode *v7; // rcx
  Scaleform::GFx::ASString resulta; // [rsp+40h] [rbp+8h]

  v2 = result;
  v3 = this->SceneInfo;
  if ( v3 )
  {
    Scaleform::GFx::ASString::operator=<Scaleform::String>(v2, &v3->Name);
  }
  else
  {
    v4 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
           (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)this->pTraits.pObject->pVM->StringManagerRef->Builtins,
           &resulta)->pNode;
    ++v4->RefCount;
    v5 = v2->pNode;
    v6 = v2->pNode->RefCount == 1;
    --v5->RefCount;
    if ( v6 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v5);
    v2->pNode = v4;
    v7 = resulta.pNode;
    v6 = resulta.pNode->RefCount == 1;
    --v7->RefCount;
    if ( v6 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v7);
  }
}

// File Line: 119
// RVA: 0x8556C0
void __fastcall Scaleform::GFx::AS3::Instances::fl_display::Scene::numFramesGet(Scaleform::GFx::AS3::Instances::fl_display::Scene *this, int *result)
{
  Scaleform::GFx::MovieDataDef::SceneInfo *v2; // rax

  v2 = this->SceneInfo;
  if ( v2 )
    *result = v2->NumFrames;
  else
    *result = ((__int64 (*)(void))this->SpriteObj.pObject->pDef.pObject->vfptr[2].GetResourceTypeCode)();
}

// File Line: 177
// RVA: 0x7FFF40
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl_display::Scene::MakeObject(Scaleform::GFx::AS3::InstanceTraits::fl_display::Scene *this, Scaleform::GFx::AS3::Value *result, Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::GFx::AS3::Value *v3; // rbx
  Scaleform::GFx::AS3::Object **v4; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_display::Scene> resulta; // [rsp+48h] [rbp+20h]

  v3 = result;
  v4 = (Scaleform::GFx::AS3::Object **)Scaleform::GFx::AS3::InstanceTraits::fl_display::Scene::MakeInstance(
                                         &resulta,
                                         (Scaleform::GFx::AS3::InstanceTraits::fl_display::Scene *)t);
  Scaleform::GFx::AS3::Value::Pick(v3, *v4);
}

// File Line: 199
// RVA: 0x7320F0
Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *__fastcall Scaleform::GFx::AS3::ClassTraits::fl_display::Scene::MakeClassTraits(Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *result, Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::GFx::AS3::VM *v2; // rbp
  Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *v3; // rdi
  Scaleform::MemoryHeap *v4; // rsi
  Scaleform::GFx::AS3::ClassTraits::Traits *v5; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *v6; // rbx
  Scaleform::GFx::AS3::InstanceTraits::CTraits *v7; // rax
  Scaleform::GFx::AS3::InstanceTraits::CTraits *v8; // rbx
  Scaleform::GFx::AS3::Class *v9; // rax

  v2 = vm;
  v3 = result;
  v4 = vm->MHeap;
  v5 = (Scaleform::GFx::AS3::ClassTraits::Traits *)v4->vfptr->Alloc(v4, 208ui64, 0i64);
  v6 = v5;
  if ( v5 )
  {
    Scaleform::GFx::AS3::ClassTraits::Traits::Traits(v5, v2, &Scaleform::GFx::AS3::fl_display::SceneCI);
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl::Object::`vftable';
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_display::Scene::`vftable';
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
    Scaleform::GFx::AS3::InstanceTraits::CTraits::CTraits(v7, v2, &Scaleform::GFx::AS3::fl_display::SceneCI);
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl::Object::`vftable';
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl_display::Scene::`vftable';
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
  if ( v9 )
    Scaleform::GFx::AS3::Class::Class(v9, v3->pV);
  return v3;
}

