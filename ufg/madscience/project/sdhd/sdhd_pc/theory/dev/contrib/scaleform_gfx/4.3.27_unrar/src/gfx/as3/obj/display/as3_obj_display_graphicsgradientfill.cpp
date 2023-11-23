// File Line: 45
// RVA: 0x77E8D0
void __fastcall Scaleform::GFx::AS3::Instances::fl_display::GraphicsGradientFill::GraphicsGradientFill(
        Scaleform::GFx::AS3::Instances::fl_display::GraphicsGradientFill *this,
        Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::GFx::AS3::Instance::Instance(this, t);
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl::Object::`vftable;
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl_display::GraphicsGradientFill::`vftable;
  this->alphas.pObject = 0i64;
  this->colors.pObject = 0i64;
  this->focalPointRatio = 0.0;
  Scaleform::GFx::AS3::DefaultValue<Scaleform::GFx::ASString const &>(
    &this->interpolationMethod,
    this->pTraits.pObject->pVM->StringManagerRef);
  this->matrix.pObject = 0i64;
  this->ratios.pObject = 0i64;
  Scaleform::GFx::AS3::DefaultValue<Scaleform::GFx::ASString const &>(
    &this->spreadMethod,
    this->pTraits.pObject->pVM->StringManagerRef);
  Scaleform::GFx::AS3::DefaultValue<Scaleform::GFx::ASString const &>(
    &this->type,
    this->pTraits.pObject->pVM->StringManagerRef);
}

// File Line: 53
// RVA: 0x7975D0
void __fastcall Scaleform::GFx::AS3::Instances::fl_display::GraphicsGradientFill::AS3Constructor(
        Scaleform::GFx::AS3::Instances::fl_display::GraphicsGradientFill *this,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Instances::fl::Array *pObject; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::Instances::fl::Array *v6; // rcx
  unsigned int v7; // eax
  Scaleform::GFx::AS3::Instances::fl::Array *v8; // rcx
  unsigned int v9; // eax
  Scaleform::GFx::AS3::Instances::fl_geom::Matrix *v10; // rcx
  unsigned int v11; // eax
  const char *pData; // rdx
  __int64 v13; // rcx
  char v14; // al
  __int64 v15; // rcx
  char v16; // al
  Scaleform::GFx::AS3::VM::Error *v17; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  unsigned int v20; // esi
  Scaleform::GFx::AS3::Instances::fl::XMLList *VStr; // rdx
  Scaleform::GFx::AS3::Traits *v22; // rax
  Scaleform::GFx::AS3::Value *v23; // r12
  Scaleform::GFx::AS3::Instances::fl::XMLList *v24; // rdx
  Scaleform::GFx::AS3::Traits *v25; // rax
  Scaleform::GFx::AS3::Instances::fl::XMLList *v26; // rdx
  Scaleform::GFx::AS3::Traits *v27; // rax
  Scaleform::GFx::AS3::VM::Error *v28; // rax
  const char *v29; // rdx
  __int64 v30; // rcx
  char v31; // al
  __int64 v32; // rcx
  char v33; // al
  __int64 v34; // rcx
  char v35; // al
  const char *v36; // r8
  __int64 v37; // rcx
  char v38; // al
  Scaleform::GFx::AS3::VM::Error v39; // [rsp+30h] [rbp-58h] BYREF
  Scaleform::GFx::AS3::CheckResult result; // [rsp+90h] [rbp+8h] BYREF
  unsigned int v41; // [rsp+98h] [rbp+10h] BYREF
  Scaleform::GFx::AS3::Value *v42; // [rsp+A0h] [rbp+18h]
  long double *p_focalPointRatio; // [rsp+A8h] [rbp+20h]

  v42 = argv;
  v41 = argc;
  Scaleform::GFx::ASString::operator=(&this->type, "linear");
  pObject = this->colors.pObject;
  if ( pObject )
  {
    if ( ((unsigned __int8)pObject & 1) != 0 )
    {
      this->colors.pObject = (Scaleform::GFx::AS3::Instances::fl::Array *)((char *)pObject - 1);
    }
    else
    {
      RefCount = pObject->RefCount;
      if ( (RefCount & 0x3FFFFF) != 0 )
      {
        pObject->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
      }
    }
    this->colors.pObject = 0i64;
  }
  v6 = this->alphas.pObject;
  if ( v6 )
  {
    if ( ((unsigned __int8)v6 & 1) != 0 )
    {
      this->alphas.pObject = (Scaleform::GFx::AS3::Instances::fl::Array *)((char *)v6 - 1);
    }
    else
    {
      v7 = v6->RefCount;
      if ( (v7 & 0x3FFFFF) != 0 )
      {
        v6->RefCount = v7 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v6);
      }
    }
    this->alphas.pObject = 0i64;
  }
  v8 = this->ratios.pObject;
  if ( v8 )
  {
    if ( ((unsigned __int8)v8 & 1) != 0 )
    {
      this->ratios.pObject = (Scaleform::GFx::AS3::Instances::fl::Array *)((char *)v8 - 1);
    }
    else
    {
      v9 = v8->RefCount;
      if ( (v9 & 0x3FFFFF) != 0 )
      {
        v8->RefCount = v9 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v8);
      }
    }
    this->ratios.pObject = 0i64;
  }
  v10 = this->matrix.pObject;
  if ( v10 )
  {
    if ( ((unsigned __int8)v10 & 1) != 0 )
    {
      this->matrix.pObject = (Scaleform::GFx::AS3::Instances::fl_geom::Matrix *)((char *)v10 - 1);
    }
    else
    {
      v11 = v10->RefCount;
      if ( (v11 & 0x3FFFFF) != 0 )
      {
        v10->RefCount = v11 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v10);
      }
    }
    this->matrix.pObject = 0i64;
  }
  Scaleform::GFx::ASString::operator=(&this->spreadMethod, "pad");
  Scaleform::GFx::ASString::operator=(&this->interpolationMethod, "rgb");
  p_focalPointRatio = &this->focalPointRatio;
  this->focalPointRatio = 0.0;
  if ( v41 )
  {
    if ( !Scaleform::GFx::AS3::Value::Convert2String(v42, &result, &this->type)->Result )
      return;
    pData = this->type.pNode->pData;
    v13 = 0i64;
    while ( 1 )
    {
      v14 = pData[v13++];
      if ( v14 != aLinear[v13 - 1] )
        break;
      if ( v13 == 7 )
        goto LABEL_38;
    }
    v15 = 0i64;
    while ( 1 )
    {
      v16 = pData[v15++];
      if ( v16 != aRadial[v15 - 1] )
        break;
      if ( v15 == 7 )
        goto LABEL_38;
    }
LABEL_35:
    Scaleform::GFx::AS3::VM::Error::Error(&v39, 2008, this->pTraits.pObject->pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      this->pTraits.pObject->pVM,
      v17,
      &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
    goto LABEL_36;
  }
LABEL_38:
  v20 = v41;
  if ( v41 >= 2 )
  {
    VStr = (Scaleform::GFx::AS3::Instances::fl::XMLList *)v42[1].value.VS._1.VStr;
    if ( VStr )
    {
      v22 = VStr->pTraits.pObject;
      if ( v22->TraitsType != Traits_Array || (v22->Flags & 0x20) != 0 )
        goto LABEL_54;
    }
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&this->colors,
      VStr);
  }
  v23 = v42;
  if ( v20 >= 3 )
  {
    v24 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)v42[2].value.VS._1.VStr;
    if ( v24 )
    {
      v25 = v24->pTraits.pObject;
      if ( v25->TraitsType != Traits_Array || (v25->Flags & 0x20) != 0 )
        goto LABEL_54;
    }
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&this->alphas,
      v24);
  }
  if ( v20 >= 4 )
  {
    v26 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)v23[3].value.VS._1.VStr;
    if ( v26 )
    {
      v27 = v26->pTraits.pObject;
      if ( v27->TraitsType != Traits_Array || (v27->Flags & 0x20) != 0 )
      {
LABEL_54:
        Scaleform::GFx::AS3::VM::Error::Error(&v39, 1034, this->pTraits.pObject->pVM);
        Scaleform::GFx::AS3::VM::ThrowErrorInternal(
          this->pTraits.pObject->pVM,
          v28,
          &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
LABEL_36:
        pNode = v39.Message.pNode;
        if ( v39.Message.pNode->RefCount-- == 1 )
          Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
        return;
      }
    }
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&this->ratios,
      v26);
  }
  if ( v20 >= 5 )
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&this->matrix,
      (Scaleform::GFx::AS3::Instances::fl::XMLList *)v23[4].value.VS._1.VStr);
  if ( v20 >= 6 )
  {
    if ( !Scaleform::GFx::AS3::Value::Convert2String(
            v23 + 5,
            (Scaleform::GFx::AS3::CheckResult *)&v41,
            &this->spreadMethod)->Result )
      return;
    v29 = this->spreadMethod.pNode->pData;
    v30 = 0i64;
    while ( 1 )
    {
      v31 = v29[v30++];
      if ( v31 != aPad[v30 - 1] )
        break;
      if ( v30 == 4 )
        goto LABEL_73;
    }
    v32 = 0i64;
    while ( 1 )
    {
      v33 = v29[v32++];
      if ( v33 != aReflect[v32 - 1] )
        break;
      if ( v32 == 8 )
        goto LABEL_73;
    }
    v34 = 0i64;
    do
    {
      v35 = v29[v34++];
      if ( v35 != aRepeat_1[v34 - 1] )
        goto LABEL_35;
    }
    while ( v34 != 7 );
  }
LABEL_73:
  if ( v20 >= 7 )
  {
    if ( !Scaleform::GFx::AS3::Value::Convert2String(
            v23 + 6,
            (Scaleform::GFx::AS3::CheckResult *)&v41,
            &this->interpolationMethod)->Result )
      return;
    v36 = this->interpolationMethod.pNode->pData;
    v37 = 0i64;
    while ( 1 )
    {
      v38 = v36[v37++];
      if ( v38 != aRgb[v37 - 1] )
        break;
      if ( v37 == 4 )
        goto LABEL_80;
    }
    if ( strcmp(v36, "linearRGB") )
      goto LABEL_35;
  }
LABEL_80:
  if ( v20 >= 8 )
    Scaleform::GFx::AS3::Value::Convert2Number(v23 + 7, (Scaleform::GFx::AS3::CheckResult *)&v41, p_focalPointRatio);
}k;
      if ( v37 == 4 )
        goto LABEL_80;
    }
    if ( strcmp(v36, "linearRGB") )
      goto LABEL_35;
  }
LAB

// File Line: 190
// RVA: 0x7FF820
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl_display::GraphicsGradientFill::MakeObject(
        Scaleform::GFx::AS3::InstanceTraits::fl_display::GraphicsGradientFill *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::InstanceTraits::fl_display::GraphicsGradientFill *t)
{
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_display::GraphicsGradientFill> *Instance; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_display::GraphicsGradientFill> resulta; // [rsp+48h] [rbp+20h] BYREF

  Instance = Scaleform::GFx::AS3::InstanceTraits::fl_display::GraphicsGradientFill::MakeInstance(&resulta, t);
  Scaleform::GFx::AS3::Value::Pick(result, Instance->pV);
}

// File Line: 212
// RVA: 0x752350
Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *__fastcall Scaleform::GFx::AS3::ClassTraits::fl_display::GraphicsGradientFill::MakeClassTraits(
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
    Scaleform::GFx::AS3::ClassTraits::Traits::Traits(v5, vm, &Scaleform::GFx::AS3::fl_display::GraphicsGradientFillCI);
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl::Object::`vftable;
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_display::GraphicsGradientFill::`vftable;
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
    Scaleform::GFx::AS3::InstanceTraits::CTraits::CTraits(
      v7,
      vm,
      &Scaleform::GFx::AS3::fl_display::GraphicsGradientFillCI);
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl::Object::`vftable;
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl_display::GraphicsGradientFill::`vftable;
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

