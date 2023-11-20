// File Line: 44
// RVA: 0x77E980
void __fastcall Scaleform::GFx::AS3::Instances::fl_display::GraphicsStroke::GraphicsStroke(Scaleform::GFx::AS3::Instances::fl_display::GraphicsStroke *this, Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::GFx::AS3::Instances::fl_display::GraphicsStroke *v2; // rbx

  v2 = this;
  Scaleform::GFx::AS3::Instance::Instance((Scaleform::GFx::AS3::Instance *)&this->vfptr, t);
  v2->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl::Object::`vftable;
  v2->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl_display::GraphicsStroke::`vftable;
  Scaleform::GFx::AS3::DefaultValue<Scaleform::GFx::ASString const &>(
    &v2->caps,
    v2->pTraits.pObject->pVM->StringManagerRef);
  v2->fill.pObject = 0i64;
  Scaleform::GFx::AS3::DefaultValue<Scaleform::GFx::ASString const &>(
    &v2->joints,
    v2->pTraits.pObject->pVM->StringManagerRef);
  v2->miterLimit = 0.0;
  v2->pixelHinting = 0;
  Scaleform::GFx::AS3::DefaultValue<Scaleform::GFx::ASString const &>(
    &v2->scaleMode,
    v2->pTraits.pObject->pVM->StringManagerRef);
  v2->thickness = 0.0;
}

// File Line: 52
// RVA: 0x797E20
void __fastcall Scaleform::GFx::AS3::Instances::fl_display::GraphicsStroke::AS3Constructor(Scaleform::GFx::AS3::Instances::fl_display::GraphicsStroke *this, unsigned int argc, Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value *v3; // r13
  unsigned int v4; // ebp
  Scaleform::GFx::AS3::Instances::fl_display::GraphicsStroke *v5; // r15
  const char *v6; // rbx
  __int64 v7; // rcx
  char v8; // al
  __int64 v9; // rcx
  char v10; // al
  Scaleform::GFx::AS3::VM::Error *v11; // rax
  Scaleform::GFx::ASStringNode *v12; // rcx
  bool v13; // zf
  const char *v14; // rdx
  __int64 v15; // rcx
  char v16; // al
  __int64 v17; // rcx
  char v18; // al
  __int64 v19; // rcx
  char v20; // al
  Scaleform::GFx::AS3::VM::Error *v21; // rax
  const char *v22; // rdx
  __int64 v23; // rcx
  char v24; // al
  __int64 v25; // rcx
  char v26; // al
  __int64 v27; // rcx
  char v28; // al
  Scaleform::GFx::AS3::VM::Error *v29; // rax
  bool v30; // al
  Scaleform::GFx::AS3::VM::Error v31; // [rsp+30h] [rbp-38h]
  Scaleform::GFx::AS3::CheckResult result; // [rsp+78h] [rbp+10h]

  v3 = argv;
  v4 = argc;
  v5 = this;
  Scaleform::GFx::ASString::operator=(&this->scaleMode, "normal");
  Scaleform::GFx::ASString::operator=(&v5->caps, "none");
  Scaleform::GFx::ASString::operator=(&v5->joints, "round");
  v5->miterLimit = 3.0;
  v5->thickness = Scaleform::GFx::NumberUtil::NaN();
  if ( v4 && !Scaleform::GFx::AS3::Value::Convert2Number(v3, &result, &v5->thickness)->Result )
    return;
  if ( v4 > 1 )
    v5->pixelHinting = Scaleform::GFx::AS3::Value::Convert2Boolean(v3 + 1);
  if ( v4 <= 2 )
    goto LABEL_20;
  if ( !Scaleform::GFx::AS3::Value::Convert2String(v3 + 2, &result, &v5->scaleMode)->Result )
    return;
  v6 = v5->scaleMode.pNode->pData;
  v7 = 0i64;
  while ( 1 )
  {
    v8 = v6[v7++];
    if ( v8 != aNormal_0[v7 - 1] )
      break;
    if ( v7 == 7 )
      goto LABEL_20;
  }
  v9 = 0i64;
  while ( 1 )
  {
    v10 = v6[v9++];
    if ( v10 != aNone[v9 - 1] )
      break;
    if ( v9 == 5 )
      goto LABEL_20;
  }
  if ( !strcmp(v6, "vertical") || !strcmp(v6, "horizontal") )
  {
LABEL_20:
    if ( v4 <= 3 )
    {
LABEL_35:
      if ( v4 <= 4 )
      {
LABEL_50:
        v30 = v4 > 5 && !Scaleform::GFx::AS3::Value::Convert2Number(v3 + 5, &result, &v5->miterLimit)->Result;
        if ( !v30 && v4 > 6 )
          Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
            (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v5->fill,
            (Scaleform::GFx::AS3::Instances::fl::XMLList *)v3[6].value.VS._1.VStr);
        return;
      }
      if ( !Scaleform::GFx::AS3::Value::Convert2String(v3 + 4, &result, &v5->joints)->Result )
        return;
      v22 = v5->joints.pNode->pData;
      v23 = 0i64;
      while ( 1 )
      {
        v24 = v22[v23++];
        if ( v24 != aBevel[v23 - 1] )
          break;
        if ( v23 == 6 )
          goto LABEL_50;
      }
      v25 = 0i64;
      while ( 1 )
      {
        v26 = v22[v25++];
        if ( v26 != aMiter[v25 - 1] )
          break;
        if ( v25 == 6 )
          goto LABEL_50;
      }
      v27 = 0i64;
      while ( 1 )
      {
        v28 = v22[v27++];
        if ( v28 != aRound[v27 - 1] )
          break;
        if ( v27 == 6 )
          goto LABEL_50;
      }
      Scaleform::GFx::AS3::VM::Error::Error(&v31, eInvalidEnumError, v5->pTraits.pObject->pVM);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(
        v5->pTraits.pObject->pVM,
        v29,
        &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
    }
    else
    {
      if ( !Scaleform::GFx::AS3::Value::Convert2String(v3 + 3, &result, &v5->caps)->Result )
        return;
      v14 = v5->caps.pNode->pData;
      v15 = 0i64;
      while ( 1 )
      {
        v16 = v14[v15++];
        if ( v16 != aNone[v15 - 1] )
          break;
        if ( v15 == 5 )
          goto LABEL_35;
      }
      v17 = 0i64;
      while ( 1 )
      {
        v18 = v14[v17++];
        if ( v18 != aRound[v17 - 1] )
          break;
        if ( v17 == 6 )
          goto LABEL_35;
      }
      v19 = 0i64;
      while ( 1 )
      {
        v20 = v14[v19++];
        if ( v20 != aSquare[v19 - 1] )
          break;
        if ( v19 == 7 )
          goto LABEL_35;
      }
      Scaleform::GFx::AS3::VM::Error::Error(&v31, eInvalidEnumError, v5->pTraits.pObject->pVM);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(
        v5->pTraits.pObject->pVM,
        v21,
        &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
    }
  }
  else
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v31, eInvalidEnumError, v5->pTraits.pObject->pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      v5->pTraits.pObject->pVM,
      v11,
      &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
  }
  v12 = v31.Message.pNode;
  v13 = v31.Message.pNode->RefCount == 1;
  --v12->RefCount;
  if ( v13 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v12);
}

// File Line: 138
// RVA: 0x7FF8B0
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl_display::GraphicsStroke::MakeObject(Scaleform::GFx::AS3::InstanceTraits::fl_display::GraphicsStroke *this, Scaleform::GFx::AS3::Value *result, Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::GFx::AS3::Value *v3; // rbx
  Scaleform::GFx::AS3::Object **v4; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_display::GraphicsStroke> resulta; // [rsp+48h] [rbp+20h]

  v3 = result;
  v4 = (Scaleform::GFx::AS3::Object **)Scaleform::GFx::AS3::InstanceTraits::fl_display::GraphicsStroke::MakeInstance(
                                         &resulta,
                                         (Scaleform::GFx::AS3::InstanceTraits::fl_display::GraphicsStroke *)t);
  Scaleform::GFx::AS3::Value::Pick(v3, *v4);
}

// File Line: 160
// RVA: 0x737C80
Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *__fastcall Scaleform::GFx::AS3::ClassTraits::fl_display::GraphicsStroke::MakeClassTraits(Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *result, Scaleform::GFx::AS3::VM *vm)
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
    Scaleform::GFx::AS3::ClassTraits::Traits::Traits(v5, v2, &Scaleform::GFx::AS3::fl_display::GraphicsStrokeCI);
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl::Object::`vftable;
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_display::GraphicsStroke::`vftable;
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
    Scaleform::GFx::AS3::InstanceTraits::CTraits::CTraits(v7, v2, &Scaleform::GFx::AS3::fl_display::GraphicsStrokeCI);
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl::Object::`vftable;
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl_display::GraphicsStroke::`vftable;
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

