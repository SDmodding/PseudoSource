// File Line: 44
// RVA: 0x77E980
void __fastcall Scaleform::GFx::AS3::Instances::fl_display::GraphicsStroke::GraphicsStroke(
        Scaleform::GFx::AS3::Instances::fl_display::GraphicsStroke *this,
        Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::GFx::AS3::Instance::Instance(this, t);
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl::Object::`vftable;
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl_display::GraphicsStroke::`vftable;
  Scaleform::GFx::AS3::DefaultValue<Scaleform::GFx::ASString const &>(
    &this->caps,
    this->pTraits.pObject->pVM->StringManagerRef);
  this->fill.pObject = 0i64;
  Scaleform::GFx::AS3::DefaultValue<Scaleform::GFx::ASString const &>(
    &this->joints,
    this->pTraits.pObject->pVM->StringManagerRef);
  this->miterLimit = 0.0;
  this->pixelHinting = 0;
  Scaleform::GFx::AS3::DefaultValue<Scaleform::GFx::ASString const &>(
    &this->scaleMode,
    this->pTraits.pObject->pVM->StringManagerRef);
  this->thickness = 0.0;
}

// File Line: 52
// RVA: 0x797E20
void __fastcall Scaleform::GFx::AS3::Instances::fl_display::GraphicsStroke::AS3Constructor(
        Scaleform::GFx::AS3::Instances::fl_display::GraphicsStroke *this,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  const char *pData; // rbx
  __int64 v7; // rcx
  char v8; // al
  __int64 v9; // rcx
  char v10; // al
  Scaleform::GFx::AS3::VM::Error *v11; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  const char *v14; // rdx
  __int64 v15; // rcx
  char v16; // al
  __int64 v17; // rcx
  char v18; // al
  __int64 v19; // rcx
  char v20; // al
  const char *v21; // rdx
  __int64 v22; // rcx
  char v23; // al
  __int64 v24; // rcx
  char v25; // al
  __int64 v26; // rcx
  char v27; // al
  bool v28; // al
  Scaleform::GFx::AS3::VM::Error v29; // [rsp+30h] [rbp-38h] BYREF
  Scaleform::GFx::AS3::CheckResult result; // [rsp+78h] [rbp+10h] BYREF

  Scaleform::GFx::ASString::operator=(&this->scaleMode, "normal");
  Scaleform::GFx::ASString::operator=(&this->caps, "none");
  Scaleform::GFx::ASString::operator=(&this->joints, "round");
  this->miterLimit = 3.0;
  this->thickness = Scaleform::GFx::NumberUtil::NaN();
  if ( argc && !Scaleform::GFx::AS3::Value::Convert2Number(argv, &result, &this->thickness)->Result )
    return;
  if ( argc > 1 )
    this->pixelHinting = Scaleform::GFx::AS3::Value::Convert2Boolean(argv + 1);
  if ( argc <= 2 )
    goto LABEL_19;
  if ( !Scaleform::GFx::AS3::Value::Convert2String(argv + 2, &result, &this->scaleMode)->Result )
    return;
  pData = this->scaleMode.pNode->pData;
  v7 = 0i64;
  while ( 1 )
  {
    v8 = pData[v7++];
    if ( v8 != aNormal_0[v7 - 1] )
      break;
    if ( v7 == 7 )
      goto LABEL_19;
  }
  v9 = 0i64;
  while ( 1 )
  {
    v10 = pData[v9++];
    if ( v10 != aNone[v9 - 1] )
      break;
    if ( v9 == 5 )
      goto LABEL_19;
  }
  if ( !strcmp(pData, "vertical") || !strcmp(pData, "horizontal") )
  {
LABEL_19:
    if ( argc <= 3 )
    {
LABEL_34:
      if ( argc <= 4 )
      {
LABEL_49:
        v28 = argc > 5 && !Scaleform::GFx::AS3::Value::Convert2Number(argv + 5, &result, &this->miterLimit)->Result;
        if ( !v28 && argc > 6 )
          Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
            (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&this->fill,
            (Scaleform::GFx::AS3::Instances::fl::XMLList *)argv[6].value.VS._1.VStr);
        return;
      }
      if ( !Scaleform::GFx::AS3::Value::Convert2String(argv + 4, &result, &this->joints)->Result )
        return;
      v21 = this->joints.pNode->pData;
      v22 = 0i64;
      while ( 1 )
      {
        v23 = v21[v22++];
        if ( v23 != aBevel[v22 - 1] )
          break;
        if ( v22 == 6 )
          goto LABEL_49;
      }
      v24 = 0i64;
      while ( 1 )
      {
        v25 = v21[v24++];
        if ( v25 != aMiter[v24 - 1] )
          break;
        if ( v24 == 6 )
          goto LABEL_49;
      }
      v26 = 0i64;
      while ( 1 )
      {
        v27 = v21[v26++];
        if ( v27 != aRound[v26 - 1] )
          break;
        if ( v26 == 6 )
          goto LABEL_49;
      }
    }
    else
    {
      if ( !Scaleform::GFx::AS3::Value::Convert2String(argv + 3, &result, &this->caps)->Result )
        return;
      v14 = this->caps.pNode->pData;
      v15 = 0i64;
      while ( 1 )
      {
        v16 = v14[v15++];
        if ( v16 != aNone[v15 - 1] )
          break;
        if ( v15 == 5 )
          goto LABEL_34;
      }
      v17 = 0i64;
      while ( 1 )
      {
        v18 = v14[v17++];
        if ( v18 != aRound[v17 - 1] )
          break;
        if ( v17 == 6 )
          goto LABEL_34;
      }
      v19 = 0i64;
      while ( 1 )
      {
        v20 = v14[v19++];
        if ( v20 != aSquare[v19 - 1] )
          break;
        if ( v19 == 7 )
          goto LABEL_34;
      }
    }
  }
  Scaleform::GFx::AS3::VM::Error::Error(&v29, 2008, this->pTraits.pObject->pVM);
  Scaleform::GFx::AS3::VM::ThrowErrorInternal(
    this->pTraits.pObject->pVM,
    v11,
    &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
  pNode = v29.Message.pNode;
  if ( v29.Message.pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}

// File Line: 138
// RVA: 0x7FF8B0
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl_display::GraphicsStroke::MakeObject(
        Scaleform::GFx::AS3::InstanceTraits::fl_display::GraphicsStroke *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::InstanceTraits::fl_display::GraphicsStroke *t)
{
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_display::GraphicsStroke> *Instance; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_display::GraphicsStroke> resulta; // [rsp+48h] [rbp+20h] BYREF

  Instance = Scaleform::GFx::AS3::InstanceTraits::fl_display::GraphicsStroke::MakeInstance(&resulta, t);
  Scaleform::GFx::AS3::Value::Pick(result, Instance->pV);
}

// File Line: 160
// RVA: 0x737C80
Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *__fastcall Scaleform::GFx::AS3::ClassTraits::fl_display::GraphicsStroke::MakeClassTraits(
        Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *result,
        Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::MemoryHeap *MHeap; // rsi
  Scaleform::GFx::AS3::ClassTraits::Traits *v5; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *v6; // rbx
  Scaleform::GFx::AS3::InstanceTraits::CTraits *v7; // rax
  Scaleform::GFx::AS3::InstanceTraits::CTraits *v8; // rbx
  Scaleform::GFx::AS3::Class *v9; // rax

  MHeap = vm->MHeap;
  v5 = (Scaleform::GFx::AS3::ClassTraits::Traits *)MHeap->vfptr->Alloc(MHeap, 208ui64, 0i64);
  v6 = v5;
  if ( v5 )
  {
    Scaleform::GFx::AS3::ClassTraits::Traits::Traits(v5, vm, &Scaleform::GFx::AS3::fl_display::GraphicsStrokeCI);
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl::Object::`vftable;
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_display::GraphicsStroke::`vftable;
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
    Scaleform::GFx::AS3::InstanceTraits::CTraits::CTraits(v7, vm, &Scaleform::GFx::AS3::fl_display::GraphicsStrokeCI);
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl::Object::`vftable;
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl_display::GraphicsStroke::`vftable;
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
  if ( v9 )
    Scaleform::GFx::AS3::Class::Class(v9, result->pV);
  return result;
}

