// File Line: 45
// RVA: 0x77E8D0
void __fastcall Scaleform::GFx::AS3::Instances::fl_display::GraphicsGradientFill::GraphicsGradientFill(Scaleform::GFx::AS3::Instances::fl_display::GraphicsGradientFill *this, Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::GFx::ASString *v2; // rbx

  v2 = (Scaleform::GFx::ASString *)this;
  Scaleform::GFx::AS3::Instance::Instance((Scaleform::GFx::AS3::Instance *)&this->vfptr, t);
  v2->pNode = (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::Instances::fl::Object::`vftable';
  v2->pNode = (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::Instances::fl_display::GraphicsGradientFill::`vftable';
  v2[7].pNode = 0i64;
  v2[8].pNode = 0i64;
  v2[9].pNode = 0i64;
  Scaleform::GFx::AS3::DefaultValue<Scaleform::GFx::ASString const &>(
    v2 + 10,
    (Scaleform::GFx::AS3::StringManager *)v2[5].pNode[3].pManager->StringSet.pTable);
  v2[11].pNode = 0i64;
  v2[12].pNode = 0i64;
  Scaleform::GFx::AS3::DefaultValue<Scaleform::GFx::ASString const &>(
    v2 + 13,
    (Scaleform::GFx::AS3::StringManager *)v2[5].pNode[3].pManager->StringSet.pTable);
  Scaleform::GFx::AS3::DefaultValue<Scaleform::GFx::ASString const &>(
    v2 + 14,
    (Scaleform::GFx::AS3::StringManager *)v2[5].pNode[3].pManager->StringSet.pTable);
}

// File Line: 53
// RVA: 0x7975D0
void __fastcall Scaleform::GFx::AS3::Instances::fl_display::GraphicsGradientFill::AS3Constructor(Scaleform::GFx::AS3::Instances::fl_display::GraphicsGradientFill *this, unsigned int argc, Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Instances::fl_display::GraphicsGradientFill *v3; // rdi
  Scaleform::GFx::AS3::Instances::fl::Array *v4; // rcx
  unsigned int v5; // eax
  Scaleform::GFx::AS3::Instances::fl::Array *v6; // rcx
  unsigned int v7; // eax
  Scaleform::GFx::AS3::Instances::fl::Array *v8; // rcx
  unsigned int v9; // eax
  Scaleform::GFx::AS3::Instances::fl_geom::Matrix *v10; // rcx
  unsigned int v11; // eax
  const char *v12; // rdx
  __int64 v13; // rcx
  char v14; // al
  __int64 v15; // rcx
  char v16; // al
  Scaleform::GFx::AS3::VM::Error *v17; // rax
  Scaleform::GFx::ASStringNode *v18; // rcx
  bool v19; // zf
  unsigned int v20; // esi
  Scaleform::GFx::AS3::Instances::fl::XMLList *v21; // rdx
  Scaleform::GFx::AS3::Traits *v22; // rax
  Scaleform::GFx::AS3::VM::Error *v23; // rax
  Scaleform::GFx::AS3::Value *v24; // r12
  Scaleform::GFx::AS3::Instances::fl::XMLList *v25; // rdx
  Scaleform::GFx::AS3::Traits *v26; // rax
  Scaleform::GFx::AS3::VM::Error *v27; // rax
  Scaleform::GFx::AS3::Instances::fl::XMLList *v28; // rdx
  Scaleform::GFx::AS3::Traits *v29; // rax
  Scaleform::GFx::AS3::VM::Error *v30; // rax
  const char *v31; // rdx
  __int64 v32; // rcx
  char v33; // al
  __int64 v34; // rcx
  char v35; // al
  __int64 v36; // rcx
  char v37; // al
  Scaleform::GFx::AS3::VM::Error *v38; // rax
  const char *v39; // r8
  __int64 v40; // rcx
  char v41; // al
  Scaleform::GFx::AS3::VM::Error *v42; // rax
  Scaleform::GFx::AS3::VM::Error v43; // [rsp+30h] [rbp-58h]
  Scaleform::GFx::AS3::CheckResult result; // [rsp+90h] [rbp+8h]
  unsigned int v45; // [rsp+98h] [rbp+10h]
  Scaleform::GFx::AS3::Value *v46; // [rsp+A0h] [rbp+18h]
  long double *v47; // [rsp+A8h] [rbp+20h]

  v46 = argv;
  v45 = argc;
  v3 = this;
  Scaleform::GFx::ASString::operator=(&this->type, "linear");
  v4 = v3->colors.pObject;
  if ( v4 )
  {
    if ( (unsigned __int8)v4 & 1 )
    {
      v3->colors.pObject = (Scaleform::GFx::AS3::Instances::fl::Array *)((char *)v4 - 1);
    }
    else
    {
      v5 = v4->RefCount;
      if ( v5 & 0x3FFFFF )
      {
        v4->RefCount = v5 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v4->vfptr);
      }
    }
    v3->colors.pObject = 0i64;
  }
  v6 = v3->alphas.pObject;
  if ( v6 )
  {
    if ( (unsigned __int8)v6 & 1 )
    {
      v3->alphas.pObject = (Scaleform::GFx::AS3::Instances::fl::Array *)((char *)v6 - 1);
    }
    else
    {
      v7 = v6->RefCount;
      if ( v7 & 0x3FFFFF )
      {
        v6->RefCount = v7 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v6->vfptr);
      }
    }
    v3->alphas.pObject = 0i64;
  }
  v8 = v3->ratios.pObject;
  if ( v8 )
  {
    if ( (unsigned __int8)v8 & 1 )
    {
      v3->ratios.pObject = (Scaleform::GFx::AS3::Instances::fl::Array *)((char *)v8 - 1);
    }
    else
    {
      v9 = v8->RefCount;
      if ( v9 & 0x3FFFFF )
      {
        v8->RefCount = v9 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v8->vfptr);
      }
    }
    v3->ratios.pObject = 0i64;
  }
  v10 = v3->matrix.pObject;
  if ( v10 )
  {
    if ( (unsigned __int8)v10 & 1 )
    {
      v3->matrix.pObject = (Scaleform::GFx::AS3::Instances::fl_geom::Matrix *)((char *)v10 - 1);
    }
    else
    {
      v11 = v10->RefCount;
      if ( v11 & 0x3FFFFF )
      {
        v10->RefCount = v11 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v10->vfptr);
      }
    }
    v3->matrix.pObject = 0i64;
  }
  Scaleform::GFx::ASString::operator=(&v3->spreadMethod, "pad");
  Scaleform::GFx::ASString::operator=(&v3->interpolationMethod, "rgb");
  v47 = &v3->focalPointRatio;
  v3->focalPointRatio = 0.0;
  if ( v45 >= 1 )
  {
    if ( !Scaleform::GFx::AS3::Value::Convert2String(v46, &result, &v3->type)->Result )
      return;
    v12 = v3->type.pNode->pData;
    v13 = 0i64;
    while ( 1 )
    {
      v14 = v12[v13++];
      if ( v14 != aLinear[v13 - 1] )
        break;
      if ( v13 == 7 )
        goto LABEL_38;
    }
    v15 = 0i64;
    while ( 1 )
    {
      v16 = v12[v15++];
      if ( v16 != aRadial[v15 - 1] )
        break;
      if ( v15 == 7 )
        goto LABEL_38;
    }
    Scaleform::GFx::AS3::VM::Error::Error(&v43, eInvalidEnumError, v3->pTraits.pObject->pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      v3->pTraits.pObject->pVM,
      v17,
      &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
    goto LABEL_36;
  }
LABEL_38:
  v20 = v45;
  if ( v45 >= 2 )
  {
    v21 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)v46[1].value.VS._1.VStr;
    if ( v21 )
    {
      v22 = v21->pTraits.pObject;
      if ( v22->TraitsType != 7 || !(~(LOBYTE(v22->Flags) >> 5) & 1) )
      {
        Scaleform::GFx::AS3::VM::Error::Error(&v43, eCheckTypeFailedError, v3->pTraits.pObject->pVM);
        Scaleform::GFx::AS3::VM::ThrowErrorInternal(
          v3->pTraits.pObject->pVM,
          v23,
          &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
        goto LABEL_36;
      }
    }
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v3->colors,
      v21);
  }
  v24 = v46;
  if ( v20 >= 3 )
  {
    v25 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)v46[2].value.VS._1.VStr;
    if ( v25 )
    {
      v26 = v25->pTraits.pObject;
      if ( v26->TraitsType != 7 || !(~(LOBYTE(v26->Flags) >> 5) & 1) )
      {
        Scaleform::GFx::AS3::VM::Error::Error(&v43, eCheckTypeFailedError, v3->pTraits.pObject->pVM);
        Scaleform::GFx::AS3::VM::ThrowErrorInternal(
          v3->pTraits.pObject->pVM,
          v27,
          &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
        goto LABEL_36;
      }
    }
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v3->alphas,
      v25);
  }
  if ( v20 >= 4 )
  {
    v28 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)v24[3].value.VS._1.VStr;
    if ( v28 )
    {
      v29 = v28->pTraits.pObject;
      if ( v29->TraitsType != 7 || !(~(LOBYTE(v29->Flags) >> 5) & 1) )
      {
        Scaleform::GFx::AS3::VM::Error::Error(&v43, eCheckTypeFailedError, v3->pTraits.pObject->pVM);
        Scaleform::GFx::AS3::VM::ThrowErrorInternal(
          v3->pTraits.pObject->pVM,
          v30,
          &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
        goto LABEL_36;
      }
    }
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v3->ratios,
      v28);
  }
  if ( v20 >= 5 )
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v3->matrix,
      (Scaleform::GFx::AS3::Instances::fl::XMLList *)v24[4].value.VS._1.VStr);
  if ( v20 >= 6 )
  {
    if ( !Scaleform::GFx::AS3::Value::Convert2String(
            v24 + 5,
            (Scaleform::GFx::AS3::CheckResult *)&v45,
            &v3->spreadMethod)->Result )
      return;
    v31 = v3->spreadMethod.pNode->pData;
    v32 = 0i64;
    while ( 1 )
    {
      v33 = v31[v32++];
      if ( v33 != aPad[v32 - 1] )
        break;
      if ( v32 == 4 )
        goto LABEL_73;
    }
    v34 = 0i64;
    while ( 1 )
    {
      v35 = v31[v34++];
      if ( v35 != aReflect[v34 - 1] )
        break;
      if ( v34 == 8 )
        goto LABEL_73;
    }
    v36 = 0i64;
    while ( 1 )
    {
      v37 = v31[v36++];
      if ( v37 != aRepeat_1[v36 - 1] )
        break;
      if ( v36 == 7 )
        goto LABEL_73;
    }
    Scaleform::GFx::AS3::VM::Error::Error(&v43, eInvalidEnumError, v3->pTraits.pObject->pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      v3->pTraits.pObject->pVM,
      v38,
      &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
    goto LABEL_36;
  }
LABEL_73:
  if ( v20 >= 7 )
  {
    if ( !Scaleform::GFx::AS3::Value::Convert2String(
            v24 + 6,
            (Scaleform::GFx::AS3::CheckResult *)&v45,
            &v3->interpolationMethod)->Result )
      return;
    v39 = v3->interpolationMethod.pNode->pData;
    v40 = 0i64;
    while ( 1 )
    {
      v41 = v39[v40++];
      if ( v41 != aRgb[v40 - 1] )
        break;
      if ( v40 == 4 )
        goto LABEL_81;
    }
    if ( strcmp(v39, "linearRGB") )
    {
      Scaleform::GFx::AS3::VM::Error::Error(&v43, eInvalidEnumError, v3->pTraits.pObject->pVM);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(
        v3->pTraits.pObject->pVM,
        v42,
        &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
LABEL_36:
      v18 = v43.Message.pNode;
      v19 = v43.Message.pNode->RefCount == 1;
      --v18->RefCount;
      if ( v19 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v18);
      return;
    }
  }
LABEL_81:
  if ( v20 >= 8 )
    Scaleform::GFx::AS3::Value::Convert2Number(v24 + 7, (Scaleform::GFx::AS3::CheckResult *)&v45, v47);
}

// File Line: 190
// RVA: 0x7FF820
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl_display::GraphicsGradientFill::MakeObject(Scaleform::GFx::AS3::InstanceTraits::fl_display::GraphicsGradientFill *this, Scaleform::GFx::AS3::Value *result, Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::GFx::AS3::Value *v3; // rbx
  Scaleform::GFx::AS3::Object **v4; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_display::GraphicsGradientFill> resulta; // [rsp+48h] [rbp+20h]

  v3 = result;
  v4 = (Scaleform::GFx::AS3::Object **)Scaleform::GFx::AS3::InstanceTraits::fl_display::GraphicsGradientFill::MakeInstance(
                                         &resulta,
                                         (Scaleform::GFx::AS3::InstanceTraits::fl_display::GraphicsGradientFill *)t);
  Scaleform::GFx::AS3::Value::Pick(v3, *v4);
}

// File Line: 212
// RVA: 0x752350
Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *__fastcall Scaleform::GFx::AS3::ClassTraits::fl_display::GraphicsGradientFill::MakeClassTraits(Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *result, Scaleform::GFx::AS3::VM *vm)
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
    Scaleform::GFx::AS3::ClassTraits::Traits::Traits(v5, v2, &Scaleform::GFx::AS3::fl_display::GraphicsGradientFillCI);
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl::Object::`vftable';
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_display::GraphicsGradientFill::`vftable';
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
    Scaleform::GFx::AS3::InstanceTraits::CTraits::CTraits(
      v7,
      v2,
      &Scaleform::GFx::AS3::fl_display::GraphicsGradientFillCI);
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl::Object::`vftable';
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl_display::GraphicsGradientFill::`vftable';
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

