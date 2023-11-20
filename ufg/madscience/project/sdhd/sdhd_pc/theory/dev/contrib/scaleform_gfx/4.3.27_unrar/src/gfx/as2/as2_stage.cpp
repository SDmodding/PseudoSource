// File Line: 59
// RVA: 0x6CBA40
void __fastcall Scaleform::GFx::AS2::StageCtorFunction::StageCtorFunction(Scaleform::GFx::AS2::StageCtorFunction *this, Scaleform::GFx::AS2::ASStringContext *psc, Scaleform::GFx::MovieImpl *movieRoot)
{
  Scaleform::GFx::MovieImpl *v3; // rbx
  Scaleform::GFx::AS2::ASStringContext *v4; // rdi
  Scaleform::GFx::AS2::StageCtorFunction *v5; // r14
  signed __int64 v6; // rsi
  Scaleform::GFx::ASString *v7; // rax
  Scaleform::GFx::ASStringNode *v8; // rcx
  bool v9; // zf
  Scaleform::GFx::ASString *v10; // rax
  Scaleform::GFx::ASStringNode *v11; // rcx
  Scaleform::GFx::ASString *v12; // rax
  Scaleform::GFx::ASStringNode *v13; // rcx
  Scaleform::GFx::AS2::Value val; // [rsp+38h] [rbp-28h]
  Scaleform::GFx::AS2::PropFlags flags; // [rsp+98h] [rbp+38h]
  Scaleform::GFx::ASString result; // [rsp+A0h] [rbp+40h]

  v3 = movieRoot;
  v4 = psc;
  v5 = this;
  Scaleform::GFx::AS2::CFunctionObject::CFunctionObject(
    (Scaleform::GFx::AS2::CFunctionObject *)&this->vfptr,
    psc,
    Scaleform::GFx::AS2::StageCtorFunction::GlobalCtor);
  v5->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::StageCtorFunction::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
  v6 = (signed __int64)&v5->vfptr;
  v5->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::StageCtorFunction::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  v5->pMovieRoot = v3;
  if ( v5 != (Scaleform::GFx::AS2::StageCtorFunction *)-32i64 )
    Scaleform::GFx::AS2::NameFunction::AddConstMembers(
      (Scaleform::GFx::AS2::ObjectInterface *)&v5->vfptr,
      v4,
      GAS_AsBcFunctionTable,
      1);
  Scaleform::GFx::AS2::AsBroadcaster::InitializeInstance(v4, (Scaleform::GFx::AS2::ObjectInterface *)&v5->vfptr);
  val.T.Type = 10;
  flags.Flags = 0;
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)&v5->vfptr,
    v4,
    (Scaleform::GFx::ASString *)&v4->pContext->pMovieRoot->pASMovieRoot.pObject[33],
    &val,
    &flags);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  val.T.Type = 10;
  flags.Flags = 0;
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)&v5->vfptr,
    v4,
    (Scaleform::GFx::ASString *)&v4->pContext->pMovieRoot->pASMovieRoot.pObject[33].RefCount,
    &val,
    &flags);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  val.T.Type = 10;
  v7 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v4, &result, "scaleMode");
  flags.Flags = 0;
  (*(void (__fastcall **)(Scaleform::GFx::AS2::ObjectInterfaceVtbl **, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, Scaleform::GFx::AS2::PropFlags *))(*(_QWORD *)v6 + 80i64))(
    &v5->vfptr,
    v4,
    v7,
    &val,
    &flags);
  v8 = result.pNode;
  v9 = result.pNode->RefCount == 1;
  --v8->RefCount;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v8);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  val.T.Type = 10;
  v10 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v4, &result, "align");
  flags.Flags = 0;
  (*(void (__fastcall **)(Scaleform::GFx::AS2::ObjectInterfaceVtbl **, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, Scaleform::GFx::AS2::PropFlags *))(*(_QWORD *)v6 + 80i64))(
    &v5->vfptr,
    v4,
    v10,
    &val,
    &flags);
  v11 = result.pNode;
  v9 = result.pNode->RefCount == 1;
  --v11->RefCount;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v11);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  val.T.Type = 2;
  val.V.BooleanValue = 1;
  v12 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v4, &result, "showMenu");
  flags.Flags = 0;
  (*(void (__fastcall **)(Scaleform::GFx::AS2::ObjectInterfaceVtbl **, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, Scaleform::GFx::AS2::PropFlags *))(*(_QWORD *)v6 + 80i64))(
    &v5->vfptr,
    v4,
    v12,
    &val,
    &flags);
  v13 = result.pNode;
  v9 = result.pNode->RefCount == 1;
  --v13->RefCount;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v13);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
}

// File Line: 72
// RVA: 0x6F3C90
char __fastcall Scaleform::GFx::AS2::StageCtorFunction::GetMemberRaw(Scaleform::GFx::AS2::StageCtorFunction *this, Scaleform::GFx::AS2::ASStringContext *psc, Scaleform::GFx::ASString *name, Scaleform::GFx::AS2::Value *val)
{
  Scaleform::GFx::AS2::Value *v4; // rbx
  Scaleform::GFx::ASString *v5; // rdi
  Scaleform::GFx::AS2::ASStringContext *v6; // rsi
  Scaleform::GFx::AS2::StageCtorFunction *v7; // r15
  Scaleform::GFx::ASMovieRootBase *v8; // rbp
  Scaleform::GFx::ASStringNode *v9; // r8
  bool v10; // zf
  float v11; // xmm0_4
  Scaleform::GFx::ASMovieRootBase *v13; // rbp
  bool v14; // zf
  Scaleform::GFx::ASString *v15; // rax
  Scaleform::GFx::ASString *v16; // r14
  bool v17; // zf
  bool v18; // bp
  Scaleform::GFx::ASStringNode *v19; // rcx
  int v20; // eax
  int v21; // eax
  const char *v22; // r8
  Scaleform::GFx::ASString *v23; // rdi
  Scaleform::GFx::ASStringNode *v24; // rax
  Scaleform::GFx::ASStringNode *v25; // rcx
  Scaleform::GFx::ASString *v26; // rax
  Scaleform::GFx::ASString *v27; // r14
  bool v28; // zf
  bool v29; // bp
  Scaleform::GFx::ASStringNode *v30; // rcx
  const char *v31; // r8
  Scaleform::GFx::ASString *v32; // rax
  Scaleform::GFx::ASString result; // [rsp+58h] [rbp+10h]

  v4 = val;
  v5 = name;
  v6 = psc;
  v7 = this;
  v8 = psc->pContext->pMovieRoot->pASMovieRoot.pObject;
  if ( psc->SWFVersion <= 6u )
  {
    if ( !name->pNode->pLower )
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(name->pNode);
    v9 = v5->pNode;
    v10 = v8[33].vfptr[2].__vecDelDtor == (void *(__fastcall *)(Scaleform::RefCountImplCore *, unsigned int))v5->pNode->pLower;
  }
  else
  {
    v9 = name->pNode;
    v10 = v8[33].vfptr == (Scaleform::RefCountImplCoreVtbl *)v9;
  }
  if ( v10 )
  {
    v11 = *(float *)(*(_QWORD *)&v7->ResolveHandler.Flags + 248i64)
        - *(float *)(*(_QWORD *)&v7->ResolveHandler.Flags + 240i64);
LABEL_8:
    if ( v4->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(v4);
    v4->T.Type = 4;
    v4->NV.Int32Value = (signed int)(float)(v11 * 0.050000001);
    return 1;
  }
  v13 = v6->pContext->pMovieRoot->pASMovieRoot.pObject;
  if ( v6->SWFVersion <= 6u )
  {
    if ( !v9->pLower )
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(v9);
    v14 = *(Scaleform::GFx::ASStringNode **)(*(_QWORD *)&v13[33].RefCount + 16i64) == v5->pNode->pLower;
  }
  else
  {
    v14 = *(_QWORD *)&v13[33].RefCount == (_QWORD)v9;
  }
  if ( v14 )
  {
    v11 = *(float *)(*(_QWORD *)&v7->ResolveHandler.Flags + 252i64)
        - *(float *)(*(_QWORD *)&v7->ResolveHandler.Flags + 244i64);
    goto LABEL_8;
  }
  v15 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v6, &result, "scaleMode");
  v16 = v15;
  if ( v6->SWFVersion <= 6u )
  {
    if ( !v15->pNode->pLower )
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(v15->pNode);
    if ( !v5->pNode->pLower )
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(v5->pNode);
    v17 = v16->pNode->pLower == v5->pNode->pLower;
  }
  else
  {
    v17 = v15->pNode == v5->pNode;
  }
  v18 = v17;
  v19 = result.pNode;
  v10 = result.pNode->RefCount == 1;
  --v19->RefCount;
  if ( v10 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v19);
  if ( v18 )
  {
    v20 = (*(__int64 (__cdecl **)(_QWORD))(**(_QWORD **)&v7->ResolveHandler.Flags + 120i64))(*(_QWORD *)&v7->ResolveHandler.Flags);
    if ( v20 )
    {
      v21 = v20 - 2;
      if ( v21 )
      {
        if ( v21 == 1 )
          v22 = "noBorder";
        else
          v22 = "showAll";
      }
      else
      {
        v22 = "exactFit";
      }
    }
    else
    {
      v22 = "noScale";
    }
    v23 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v6, &result, v22);
    if ( v4->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(v4);
    v4->T.Type = 5;
    v24 = v23->pNode;
    v4->NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)v23->pNode;
    ++v24->RefCount;
LABEL_39:
    v25 = result.pNode;
    v10 = result.pNode->RefCount == 1;
    --v25->RefCount;
    if ( v10 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v25);
    return 1;
  }
  v26 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v6, &result, "align");
  v27 = v26;
  if ( v6->SWFVersion <= 6u )
  {
    if ( !v26->pNode->pLower )
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(v26->pNode);
    if ( !v5->pNode->pLower )
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(v5->pNode);
    v28 = v27->pNode->pLower == v5->pNode->pLower;
  }
  else
  {
    v28 = v26->pNode == v5->pNode;
  }
  v29 = v28;
  v30 = result.pNode;
  v10 = result.pNode->RefCount == 1;
  --v30->RefCount;
  if ( v10 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v30);
  if ( v29 )
  {
    switch ( (*(unsigned int (__cdecl **)(_QWORD))(**(_QWORD **)&v7->ResolveHandler.Flags + 136i64))(*(_QWORD *)&v7->ResolveHandler.Flags) )
    {
      case 1u:
        v31 = "T";
        break;
      case 2u:
        v31 = "B";
        break;
      case 3u:
        v31 = "L";
        break;
      case 4u:
        v31 = "R";
        break;
      case 5u:
        v31 = "LT";
        break;
      case 6u:
        v31 = "TR";
        break;
      case 7u:
        v31 = "LB";
        break;
      case 8u:
        v31 = "RB";
        break;
      default:
        v31 = &customWorldMapCaption;
        break;
    }
    v32 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v6, &result, v31);
    Scaleform::GFx::AS2::Value::SetString(v4, v32);
    goto LABEL_39;
  }
  return Scaleform::GFx::AS2::Object::GetMemberRaw((Scaleform::GFx::AS2::Object *)&v7->vfptr, v6, v5, v4);
}

// File Line: 118
// RVA: 0x6E0F80
Scaleform::GFx::AS2::Value *__fastcall Scaleform::GFx::AS2::StageCtorFunction::CreateRectangleObject(Scaleform::GFx::AS2::Value *result, Scaleform::GFx::AS2::Environment *penv, Scaleform::Render::Rect<float> *rect)
{
  Scaleform::Render::Rect<float> *v3; // rbx
  Scaleform::GFx::AS2::Environment *v4; // rdi
  Scaleform::GFx::AS2::Value *v5; // rsi
  Scaleform::GFx::AS2::RectangleObject *v6; // rbp
  long double v7; // xmm3_8
  long double v8; // xmm2_8
  long double v9; // xmm1_8
  unsigned int v10; // eax
  Scaleform::Render::Rect<double> r; // [rsp+40h] [rbp-38h]

  v3 = rect;
  v4 = penv;
  v5 = result;
  result->T.Type = 0;
  v6 = (Scaleform::GFx::AS2::RectangleObject *)Scaleform::GFx::AS2::Environment::OperatorNew(
                                                 penv,
                                                 penv->StringContext.pContext->FlashGeomPackage,
                                                 (Scaleform::GFx::ASString *)&penv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[10].AVMVersion,
                                                 0,
                                                 -1);
  v7 = v3->y2;
  v8 = v3->x2;
  v9 = v3->y1;
  r.x1 = v3->x1;
  r.y1 = v9;
  r.x2 = v8;
  r.y2 = v7;
  Scaleform::GFx::AS2::RectangleObject::SetProperties(v6, v4, &r);
  Scaleform::GFx::AS2::Value::SetAsObject(v5, (Scaleform::GFx::AS2::Object *)&v6->vfptr);
  if ( v6 )
  {
    v10 = v6->RefCount;
    if ( v10 & 0x3FFFFFF )
    {
      v6->RefCount = v10 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v6->vfptr);
    }
  }
  return v5;
}

// File Line: 140
// RVA: 0x6F26B0
char __fastcall Scaleform::GFx::AS2::StageCtorFunction::GetMember(Scaleform::GFx::AS2::StageCtorFunction *this, Scaleform::GFx::AS2::Environment *penv, Scaleform::GFx::ASString *name, Scaleform::GFx::AS2::Value *val)
{
  Scaleform::GFx::AS2::Value *v4; // r15
  Scaleform::GFx::ASString *v5; // rbx
  Scaleform::GFx::AS2::Environment *v6; // r14
  Scaleform::GFx::AS2::StageCtorFunction *v7; // r12
  Scaleform::GFx::AS2::ASStringContext *v8; // rdi
  Scaleform::GFx::ASString *v9; // rax
  Scaleform::GFx::ASString *v10; // rsi
  bool v11; // zf
  bool v12; // si
  Scaleform::GFx::ASStringNode *v13; // rcx
  Scaleform::GFx::MovieImpl *v14; // rcx
  Scaleform::GFx::AS2::Value *v15; // rax
  Scaleform::GFx::ASString *v17; // rax
  Scaleform::GFx::ASString *v18; // rsi
  bool v19; // zf
  bool v20; // si
  Scaleform::GFx::ASStringNode *v21; // rcx
  Scaleform::GFx::MovieImpl *v22; // rcx
  Scaleform::GFx::MovieImpl *v23; // rcx
  __int64 v24; // rax
  float v25; // xmm3_4
  float v26; // xmm2_4
  float v27; // xmm1_4
  Scaleform::GFx::AS2::Value *v28; // rax
  Scaleform::GFx::ASString *v29; // rax
  Scaleform::GFx::ASString *v30; // rsi
  bool v31; // zf
  bool v32; // si
  Scaleform::GFx::ASStringNode *v33; // rcx
  Scaleform::GFx::MovieImpl *v34; // rcx
  __int64 v35; // rax
  Scaleform::GFx::AS2::Value *v36; // rax
  Scaleform::Render::Rect<float> rect; // [rsp+30h] [rbp-30h]
  Scaleform::GFx::AS2::Value v38; // [rsp+40h] [rbp-20h]
  Scaleform::GFx::ASString result; // [rsp+98h] [rbp+38h]

  v4 = val;
  v5 = name;
  v6 = penv;
  v7 = this;
  v8 = &penv->StringContext;
  if ( penv->StringContext.pContext->GFxExtensions.Value != 1 )
    return ((__int64 (__fastcall *)(Scaleform::GFx::AS2::StageCtorFunction *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, signed __int64))v7->vfptr[3].~RefCountBaseGC<323>)(
             v7,
             v8,
             v5,
             v4,
             -2i64);
  v9 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v8, &result, "visibleRect");
  v10 = v9;
  if ( v8->SWFVersion <= 6u )
  {
    if ( !v9->pNode->pLower )
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(v9->pNode);
    if ( !v5->pNode->pLower )
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(v5->pNode);
    v11 = v10->pNode->pLower == v5->pNode->pLower;
  }
  else
  {
    v11 = v9->pNode == v5->pNode;
  }
  v12 = v11;
  v13 = result.pNode;
  v11 = result.pNode->RefCount == 1;
  --v13->RefCount;
  if ( v11 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v13);
  if ( !v12 )
  {
    v17 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v8, &result, "safeRect");
    v18 = v17;
    if ( v8->SWFVersion <= 6u )
    {
      if ( !v17->pNode->pLower )
        Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(v17->pNode);
      if ( !v5->pNode->pLower )
        Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(v5->pNode);
      v19 = v18->pNode->pLower == v5->pNode->pLower;
    }
    else
    {
      v19 = v17->pNode == v5->pNode;
    }
    v20 = v19;
    v21 = result.pNode;
    v11 = result.pNode->RefCount == 1;
    --v21->RefCount;
    if ( v11 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v21);
    if ( v20 )
    {
      v22 = v6->Target->pASRoot->pMovieImpl;
      v22->vfptr[19].__vecDelDtor((Scaleform::RefCountImplCore *)&v22->vfptr, (unsigned int)&rect);
      if ( rect.x1 >= rect.x2 || rect.y1 >= rect.y2 )
      {
        v23 = v6->Target->pASRoot->pMovieImpl;
        v24 = (__int64)v23->vfptr[18].__vecDelDtor((Scaleform::RefCountImplCore *)&v23->vfptr, (unsigned int)&v38);
        v25 = *(float *)(v24 + 12);
        v26 = *(float *)(v24 + 8);
        v27 = *(float *)(v24 + 4);
        rect.x1 = *(float *)v24;
        rect.y1 = v27;
        rect.x2 = v26;
        rect.y2 = v25;
      }
      v28 = Scaleform::GFx::AS2::StageCtorFunction::CreateRectangleObject(&v38, v6, &rect);
      Scaleform::GFx::AS2::Value::operator=(v4, v28, (__int64)v8);
      goto LABEL_13;
    }
    v29 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v8, &result, "originalRect");
    v30 = v29;
    if ( v8->SWFVersion <= 6u )
    {
      if ( !v29->pNode->pLower )
        Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(v29->pNode);
      if ( !v5->pNode->pLower )
        Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(v5->pNode);
      v31 = v30->pNode->pLower == v5->pNode->pLower;
    }
    else
    {
      v31 = v29->pNode == v5->pNode;
    }
    v32 = v31;
    v33 = result.pNode;
    v11 = result.pNode->RefCount == 1;
    --v33->RefCount;
    if ( v11 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v33);
    if ( v32 )
    {
      v34 = v6->Target->pASRoot->pMovieImpl;
      v35 = ((__int64 (__cdecl *)(Scaleform::GFx::MovieImpl *))v34->vfptr[1].__vecDelDtor)(v34);
      (*(void (__fastcall **)(__int64, Scaleform::Render::Rect<float> *))(*(_QWORD *)v35 + 80i64))(v35, &rect);
      v36 = Scaleform::GFx::AS2::StageCtorFunction::CreateRectangleObject(&v38, v6, &rect);
      Scaleform::GFx::AS2::Value::operator=(v4, v36, (__int64)v8);
      goto LABEL_13;
    }
    return ((__int64 (__fastcall *)(Scaleform::GFx::AS2::StageCtorFunction *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, signed __int64))v7->vfptr[3].~RefCountBaseGC<323>)(
             v7,
             v8,
             v5,
             v4,
             -2i64);
  }
  v14 = v6->Target->pASRoot->pMovieImpl;
  v14->vfptr[18].__vecDelDtor((Scaleform::RefCountImplCore *)&v14->vfptr, (unsigned int)&rect);
  v15 = Scaleform::GFx::AS2::StageCtorFunction::CreateRectangleObject(&v38, v6, &rect);
  Scaleform::GFx::AS2::Value::operator=(v4, v15, (__int64)v8);
LABEL_13:
  if ( v38.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v38);
  return 1;
}

// File Line: 168
// RVA: 0x7183D0
char __fastcall Scaleform::GFx::AS2::StageCtorFunction::SetMember(Scaleform::GFx::AS2::StageCtorFunction *this, Scaleform::GFx::AS2::Environment *penv, Scaleform::GFx::ASString *name, Scaleform::GFx::AS2::Value *val, Scaleform::GFx::AS2::PropFlags *flags)
{
  Scaleform::GFx::AS2::Value *v5; // r15
  Scaleform::GFx::ASString *v6; // rbx
  Scaleform::GFx::AS2::Environment *v7; // r14
  Scaleform::GFx::AS2::StageCtorFunction *v8; // r13
  Scaleform::GFx::AS2::ASStringContext *v9; // rdi
  Scaleform::GFx::ASString *v10; // rax
  Scaleform::GFx::ASString *v11; // rsi
  bool v12; // zf
  bool v13; // si
  Scaleform::GFx::ASStringNode *v14; // rcx
  int v15; // er15
  Scaleform::GFx::ASString *v16; // rbx
  Scaleform::GFx::ASStringNode *v17; // rcx
  bool v18; // bl
  Scaleform::GFx::ASStringNode *v19; // rcx
  __int64 v20; // rdi
  Scaleform::GFx::ASString *v21; // rbx
  Scaleform::GFx::ASStringNode *v22; // rcx
  bool v23; // bl
  Scaleform::GFx::ASStringNode *v24; // rcx
  Scaleform::GFx::ASString *v25; // rbx
  Scaleform::GFx::ASStringNode *v26; // rcx
  bool v27; // si
  Scaleform::GFx::ASStringNode *v28; // rcx
  Scaleform::GFx::ASStringNode *v29; // rcx
  Scaleform::GFx::ASString *v31; // rax
  Scaleform::GFx::ASString *v32; // rsi
  bool v33; // zf
  bool v34; // di
  Scaleform::GFx::ASStringNode *v35; // rcx
  Scaleform::GFx::ASString *v36; // rax
  Scaleform::GFx::ASStringNode *v37; // rcx
  unsigned int v38; // esi
  unsigned int v39; // er15
  unsigned int v40; // er14
  unsigned int v41; // ebx
  Scaleform::GFx::ASStringNode *v42; // rcx
  Scaleform::GFx::ASString v43; // [rsp+30h] [rbp-10h]
  __int64 v44; // [rsp+38h] [rbp-8h]
  Scaleform::GFx::ASString result; // [rsp+78h] [rbp+38h]

  v44 = -2i64;
  v5 = val;
  v6 = name;
  v7 = penv;
  v8 = this;
  v9 = &penv->StringContext;
  v10 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(&penv->StringContext, &result, "scaleMode");
  v11 = v10;
  if ( v9->SWFVersion <= 6u )
  {
    if ( !v10->pNode->pLower )
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(v10->pNode);
    if ( !v6->pNode->pLower )
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(v6->pNode);
    v12 = v11->pNode->pLower == v6->pNode->pLower;
  }
  else
  {
    v12 = v10->pNode == v6->pNode;
  }
  v13 = v12;
  v14 = result.pNode;
  v12 = result.pNode->RefCount == 1;
  --v14->RefCount;
  if ( v12 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v14);
  if ( v13 )
  {
    Scaleform::GFx::AS2::Value::ToString(v5, &result, v7, -1);
    v15 = (*(__int64 (**)(void))(**(_QWORD **)&v8->ResolveHandler.Flags + 120i64))();
    v16 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v9, &v43, "noScale");
    if ( !v16->pNode->pLower )
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(v16->pNode);
    v17 = result.pNode;
    if ( !result.pNode->pLower )
    {
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(result.pNode);
      v17 = result.pNode;
    }
    v18 = v16->pNode->pLower == v17->pLower;
    v19 = v43.pNode;
    v12 = v43.pNode->RefCount == 1;
    --v19->RefCount;
    if ( v12 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v19);
    if ( v18 )
    {
      v20 = 0i64;
    }
    else
    {
      v21 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v9, &v43, "exactFit");
      if ( !v21->pNode->pLower )
        Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(v21->pNode);
      v22 = result.pNode;
      if ( !result.pNode->pLower )
      {
        Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(result.pNode);
        v22 = result.pNode;
      }
      v23 = v21->pNode->pLower == v22->pLower;
      v24 = v43.pNode;
      v12 = v43.pNode->RefCount == 1;
      --v24->RefCount;
      if ( v12 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v24);
      if ( v23 )
      {
        v20 = 2i64;
      }
      else
      {
        v25 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v9, &v43, "noBorder");
        if ( !v25->pNode->pLower )
          Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(v25->pNode);
        v26 = result.pNode;
        if ( !result.pNode->pLower )
        {
          Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(result.pNode);
          v26 = result.pNode;
        }
        v27 = v25->pNode->pLower == v26->pLower;
        v28 = v43.pNode;
        v12 = v43.pNode->RefCount == 1;
        --v28->RefCount;
        if ( v12 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v28);
        v20 = 1i64;
        if ( v27 )
          v20 = 3i64;
      }
    }
    (*(void (__fastcall **)(_QWORD, _QWORD))(**(_QWORD **)&v8->ResolveHandler.Flags + 112i64))(
      *(_QWORD *)&v8->ResolveHandler.Flags,
      (unsigned int)v20);
    if ( v15 != (_DWORD)v20 && !(_DWORD)v20 )
      Scaleform::GFx::AS2::StageCtorFunction::NotifyOnResize(
        (Scaleform::GFx::AS2::StageCtorFunction *)((char *)v8 - 32),
        v7,
        v20);
    v29 = result.pNode;
    v12 = result.pNode->RefCount == 1;
    --v29->RefCount;
    if ( v12 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v29);
    return 1;
  }
  v31 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v9, &result, "align");
  v32 = v31;
  if ( v9->SWFVersion <= 6u )
  {
    if ( !v31->pNode->pLower )
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(v31->pNode);
    if ( !v6->pNode->pLower )
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(v6->pNode);
    v33 = v32->pNode->pLower == v6->pNode->pLower;
  }
  else
  {
    v33 = v31->pNode == v6->pNode;
  }
  v34 = v33;
  v35 = result.pNode;
  v12 = result.pNode->RefCount == 1;
  --v35->RefCount;
  if ( v12 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v35);
  if ( !v34 )
    return Scaleform::GFx::AS2::Object::SetMember((Scaleform::GFx::AS2::Object *)&v8->vfptr, v7, v6, v5, flags);
  v36 = Scaleform::GFx::AS2::Value::ToString(v5, &v43, v7, -1);
  Scaleform::GFx::ASString::ToUpper(v36, &result);
  v37 = v43.pNode;
  v12 = v43.pNode->RefCount == 1;
  --v37->RefCount;
  if ( v12 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v37);
  v38 = 0;
  v39 = Scaleform::GFx::ASConstString::GetLength((Scaleform::GFx::ASConstString *)&result.pNode);
  if ( v39 < 1 )
    goto LABEL_76;
  v40 = Scaleform::GFx::ASConstString::GetCharAt((Scaleform::GFx::ASConstString *)&result.pNode, 0);
  v41 = 1;
  if ( v39 >= 2 )
    v38 = Scaleform::GFx::ASConstString::GetCharAt((Scaleform::GFx::ASConstString *)&result.pNode, 1u);
  if ( v40 == 84 )
  {
    if ( v38 != 76 )
    {
      if ( v38 != 82 )
        goto LABEL_77;
      goto LABEL_67;
    }
    goto LABEL_62;
  }
  if ( v40 != 76 )
  {
    if ( v40 == 82 )
    {
      if ( v38 == 84 )
      {
LABEL_67:
        v41 = 6;
        goto LABEL_77;
      }
      if ( v38 != 66 )
      {
        v41 = 4;
        goto LABEL_77;
      }
      goto LABEL_74;
    }
    if ( v40 == 66 )
    {
      if ( v38 == 76 )
        goto LABEL_75;
      if ( v38 != 82 )
      {
        v41 = 2;
        goto LABEL_77;
      }
LABEL_74:
      v41 = 8;
      goto LABEL_77;
    }
LABEL_76:
    v41 = 0;
    goto LABEL_77;
  }
  if ( v38 != 84 )
  {
    if ( v38 != 66 )
    {
      v41 = 3;
      goto LABEL_77;
    }
LABEL_75:
    v41 = 7;
    goto LABEL_77;
  }
LABEL_62:
  v41 = 5;
LABEL_77:
  (*(void (__fastcall **)(_QWORD, _QWORD))(**(_QWORD **)&v8->ResolveHandler.Flags + 128i64))(
    *(_QWORD *)&v8->ResolveHandler.Flags,
    v41);
  v42 = result.pNode;
  v12 = result.pNode->RefCount == 1;
  --v42->RefCount;
  if ( !v12 )
    return 1;
  Scaleform::GFx::ASStringNode::ReleaseNode(v42);
  return 1;
}

// File Line: 229
// RVA: 0x719FF0
char __fastcall Scaleform::GFx::AS2::StageCtorFunction::SetMemberRaw(Scaleform::GFx::AS2::StageCtorFunction *this, Scaleform::GFx::AS2::ASStringContext *psc, Scaleform::GFx::ASString *name, Scaleform::GFx::AS2::Value *val, Scaleform::GFx::AS2::PropFlags *flags)
{
  Scaleform::GFx::AS2::Value *v5; // rbp
  Scaleform::GFx::ASString *v6; // rbx
  Scaleform::GFx::AS2::ASStringContext *v7; // rsi
  Scaleform::GFx::ASMovieRootBase *v8; // rdi
  Scaleform::GFx::AS2::StageCtorFunction *v9; // r14
  Scaleform::GFx::ASStringNode *v10; // r10
  bool v11; // zf
  Scaleform::GFx::ASMovieRootBase *v12; // rdi
  bool v13; // zf
  char result; // al

  v5 = val;
  v6 = name;
  v7 = psc;
  v8 = psc->pContext->pMovieRoot->pASMovieRoot.pObject;
  v9 = this;
  if ( psc->SWFVersion <= 6u )
  {
    if ( !name->pNode->pLower )
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(name->pNode);
    v10 = v6->pNode;
    v11 = v8[33].vfptr[2].__vecDelDtor == (void *(__fastcall *)(Scaleform::RefCountImplCore *, unsigned int))v6->pNode->pLower;
  }
  else
  {
    v10 = name->pNode;
    v11 = v8[33].vfptr == (Scaleform::RefCountImplCoreVtbl *)name->pNode;
  }
  if ( v11 )
    goto LABEL_17;
  v12 = v7->pContext->pMovieRoot->pASMovieRoot.pObject;
  if ( v7->SWFVersion <= 6u )
  {
    if ( !v10->pLower )
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(v10);
    v13 = *(Scaleform::GFx::ASStringNode **)(*(_QWORD *)&v12[33].RefCount + 16i64) == v6->pNode->pLower;
  }
  else
  {
    v13 = *(_QWORD *)&v12[33].RefCount == (_QWORD)v10;
  }
  if ( v13 )
LABEL_17:
    result = 1;
  else
    result = Scaleform::GFx::AS2::Object::SetMemberRaw((Scaleform::GFx::AS2::Object *)&v9->vfptr, v7, v6, v5, flags);
  return result;
}

// File Line: 240
// RVA: 0x704950
void __usercall Scaleform::GFx::AS2::StageCtorFunction::NotifyOnResize(Scaleform::GFx::AS2::StageCtorFunction *this@<rcx>, Scaleform::GFx::AS2::Environment *penv@<rdx>, __int64 a3@<rdi>)
{
  Scaleform::GFx::AS2::Environment *v3; // rsi
  Scaleform::GFx::AS2::StageCtorFunction *v4; // r14
  Scaleform::GFx::MovieImpl *v5; // rcx
  Scaleform::GFx::ASStringNode *v6; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v7; // rdi
  Scaleform::GFx::ASString *v8; // r8
  int v9; // er9
  Scaleform::GFx::ASStringNode *v10; // rcx
  bool v11; // zf
  Scaleform::GFx::AS2::Value *v12; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v13; // rbx
  Scaleform::GFx::ASString *v14; // r8
  Scaleform::GFx::ASStringNode *v15; // rcx
  Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback pcallback; // [rsp+28h] [rbp-48h]
  __int64 v17; // [rsp+30h] [rbp-40h]
  Scaleform::Render::Rect<float> rect; // [rsp+40h] [rbp-30h]
  Scaleform::GFx::AS2::Value result; // [rsp+50h] [rbp-20h]
  Scaleform::GFx::ASString v20; // [rsp+98h] [rbp+28h]
  Scaleform::GFx::ASStringNode *v21; // [rsp+A0h] [rbp+30h]

  v3 = penv;
  v4 = this;
  if ( penv->StringContext.pContext->GFxExtensions.Value == 1 )
  {
    v5 = penv->Target->pASRoot->pMovieImpl;
    v5->vfptr[18].__vecDelDtor((Scaleform::RefCountImplCore *)&v5->vfptr, (unsigned int)&rect);
    Scaleform::GFx::AS2::StageCtorFunction::CreateRectangleObject(&result, v3, &rect);
    ++v3->Stack.pCurrent;
    if ( v3->Stack.pCurrent >= v3->Stack.pPageEnd )
      Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&v3->Stack);
    v6 = (Scaleform::GFx::ASStringNode *)v3->Stack.pCurrent;
    v20.pNode = v6;
    v21 = v6;
    if ( v6 )
      Scaleform::GFx::AS2::Value::Value((Scaleform::GFx::AS2::Value *)v6, &result, a3);
    if ( v4 )
      v7 = (Scaleform::GFx::AS2::ObjectInterface *)&v4->vfptr;
    else
      v7 = 0i64;
    v8 = Scaleform::GFx::AS2::Environment::CreateConstString(v3, &v20, "onResize");
    v9 = ((_QWORD)((char *)v3->Stack.pCurrent - (char *)v3->Stack.pPageStart) >> 5)
       + 32 * v3->Stack.Pages.Data.Size
       - 32;
    if ( v7 )
    {
      pcallback.vfptr = (Scaleform::GFx::AS2::AsBroadcaster::InvokeCallbackVtbl *)`Scaleform::GFx::AS2::AsBroadcaster::BroadcastMessage::`4::LocalInvokeCallback::`vftable;
      LODWORD(v17) = 1;
      HIDWORD(v17) = v9;
      Scaleform::GFx::AS2::AsBroadcaster::BroadcastMessageWithCallback(v3, v7, v8, &pcallback);
      pcallback.vfptr = (Scaleform::GFx::AS2::AsBroadcaster::InvokeCallbackVtbl *)&Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback::`vftable;
    }
    v10 = v20.pNode;
    v11 = v20.pNode->RefCount == 1;
    --v10->RefCount;
    if ( v11 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v10);
    v12 = v3->Stack.pCurrent;
    if ( v12->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(v12);
    --v3->Stack.pCurrent;
    if ( v3->Stack.pCurrent < v3->Stack.pPageStart )
      Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(&v3->Stack);
    if ( result.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&result);
  }
  else
  {
    v13 = (Scaleform::GFx::AS2::ObjectInterface *)&this->vfptr;
    if ( !this )
      v13 = 0i64;
    v14 = Scaleform::GFx::AS2::Environment::CreateConstString(penv, &v20, "onResize");
    if ( v13 )
    {
      pcallback.vfptr = (Scaleform::GFx::AS2::AsBroadcaster::InvokeCallbackVtbl *)`Scaleform::GFx::AS2::AsBroadcaster::BroadcastMessage::`4::LocalInvokeCallback::`vftable;
      v17 = 0i64;
      Scaleform::GFx::AS2::AsBroadcaster::BroadcastMessageWithCallback(v3, v13, v14, &pcallback);
      pcallback.vfptr = (Scaleform::GFx::AS2::AsBroadcaster::InvokeCallbackVtbl *)&Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback::`vftable;
    }
    v15 = v20.pNode;
    v11 = v20.pNode->RefCount == 1;
    --v15->RefCount;
    if ( v11 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v15);
  }
}

// File Line: 259
// RVA: 0x704B20
void __usercall Scaleform::GFx::AS2::StageCtorFunction::NotifyOnResize(Scaleform::GFx::AS2::FnCall *fn@<rcx>, __int64 a2@<rdi>)
{
  Scaleform::GFx::AS2::FnCall *v2; // rbx
  Scaleform::GFx::AS2::StageCtorFunction *v3; // rax
  Scaleform::GFx::AS2::Value v4; // [rsp+28h] [rbp-30h]

  v2 = fn;
  v4.T.Type = 0;
  if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::AS2::ObjectInterfaceVtbl **, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::MovieImpl **, Scaleform::GFx::AS2::Value *, signed __int64))fn->Env->StringContext.pContext->pGlobal.pObject->vfptr->GetMemberRaw)(
         &fn->Env->StringContext.pContext->pGlobal.pObject->vfptr,
         &fn->Env->StringContext,
         &fn->Env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[11].pMovieImpl,
         &v4,
         -2i64) )
  {
    if ( v4.T.Type != 11 )
    {
      v3 = (Scaleform::GFx::AS2::StageCtorFunction *)Scaleform::GFx::AS2::Value::ToObject(&v4, v2->Env);
      if ( v3 )
      {
        if ( v3 != (Scaleform::GFx::AS2::StageCtorFunction *)-32i64 )
          Scaleform::GFx::AS2::StageCtorFunction::NotifyOnResize(v3, v2->Env, a2);
      }
    }
  }
  if ( v4.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v4);
}

// File Line: 286
// RVA: 0x70EAC0
Scaleform::GFx::AS2::FunctionRef *__fastcall Scaleform::GFx::AS2::StageCtorFunction::Register(Scaleform::GFx::AS2::FunctionRef *result, Scaleform::GFx::AS2::GlobalContext *pgc)
{
  Scaleform::GFx::AS2::GlobalContext *v2; // rsi
  Scaleform::GFx::AS2::FunctionRef *v3; // rdi
  Scaleform::GFx::AS2::StageCtorFunction *v4; // rax
  __int64 v5; // rcx
  Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::StageObject,Scaleform::GFx::AS2::Environment> *v6; // rbx
  Scaleform::GFx::AS2::Object *v7; // rax
  Scaleform::GFx::AS2::Object *v8; // r14
  Scaleform::GFx::ASStringNode *v9; // rax
  Scaleform::GFx::AS2::LocalFrame *v10; // rdx
  unsigned int v11; // eax
  Scaleform::GFx::AS2::ASStringContext psc; // [rsp+40h] [rbp-30h]
  Scaleform::GFx::AS2::Value v14; // [rsp+50h] [rbp-20h]
  Scaleform::MemoryHeap *flags; // [rsp+A8h] [rbp+38h]
  void *v16; // [rsp+B0h] [rbp+40h]
  Scaleform::MemoryHeap **v17; // [rsp+B8h] [rbp+48h]

  v2 = pgc;
  v3 = result;
  psc.pContext = pgc;
  psc.SWFVersion = 8;
  flags = pgc->pHeap;
  v4 = (Scaleform::GFx::AS2::StageCtorFunction *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::FunctionRef *, signed __int64))flags->vfptr->Alloc)(
                                                   result,
                                                   112i64);
  v16 = v4;
  if ( v4 )
    Scaleform::GFx::AS2::StageCtorFunction::StageCtorFunction(v4, &psc, v2->pMovieRoot);
  v3->Flags = 0;
  v3->Function = (Scaleform::GFx::AS2::FunctionObject *)&v4->vfptr;
  v3->pLocalFrame = 0i64;
  v16 = v2->pHeap;
  v6 = (Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::StageObject,Scaleform::GFx::AS2::Environment> *)(*(__int64 (__fastcall **)(__int64, signed __int64, _QWORD))(*(_QWORD *)v16 + 80i64))(v5, 160i64, 0i64);
  v17 = (Scaleform::MemoryHeap **)v6;
  if ( v6 )
  {
    v7 = Scaleform::GFx::AS2::GlobalContext::GetPrototype(v2, ASBuiltin_Object);
    Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::StageObject,Scaleform::GFx::AS2::Environment>::Prototype<Scaleform::GFx::AS2::StageObject,Scaleform::GFx::AS2::Environment>(
      v6,
      &psc,
      v7,
      v3);
    v6->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::StageProto::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
    v6->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::StageProto::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
    v6->vfptr = (Scaleform::GFx::AS2::GASPrototypeBaseVtbl *)&Scaleform::GFx::AS2::StageProto::`vftable;
    LOBYTE(flags) = 1;
    Scaleform::GFx::AS2::GASPrototypeBase::InitFunctionMembers(
      (Scaleform::GFx::AS2::GASPrototypeBase *)&v6->vfptr,
      (Scaleform::GFx::AS2::Object *)&v6->vfptr,
      &psc,
      GFx_StageFunctionTable,
      (Scaleform::GFx::AS2::PropFlags *)&flags);
  }
  else
  {
    v6 = 0i64;
  }
  v16 = v6;
  v17 = &flags;
  if ( v6 )
    v6->RefCount = (v6->RefCount + 1) & 0x8FFFFFFF;
  flags = (Scaleform::MemoryHeap *)v6;
  Scaleform::GFx::AS2::GlobalContext::SetPrototype(
    v2,
    ASBuiltin_Stage,
    (Scaleform::Ptr<Scaleform::GFx::AS2::Object>)&flags);
  v8 = v2->pGlobal.pObject;
  v14.T.Type = 8;
  v14.V.FunctionValue.Flags = 0;
  v9 = (Scaleform::GFx::ASStringNode *)v3->Function;
  v14.V.pStringNode = v9;
  if ( v9 )
  {
    ++v9->RefCount;
    v9->RefCount &= 0x8FFFFFFF;
  }
  v14.V.FunctionValue.pLocalFrame = 0i64;
  v10 = v3->pLocalFrame;
  if ( v10 )
    Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(
      (Scaleform::GFx::AS2::FunctionRefBase *)&v14.NV.8,
      v10,
      v3->Flags & 1);
  LOBYTE(flags) = 0;
  v8->vfptr->SetMemberRaw(
    (Scaleform::GFx::AS2::ObjectInterface *)&v8->vfptr,
    &psc,
    (Scaleform::GFx::ASString *)&v2->pMovieRoot->pASMovieRoot.pObject[11].pMovieImpl,
    &v14,
    (Scaleform::GFx::AS2::PropFlags *)&flags);
  if ( v14.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v14);
  if ( v6 )
  {
    v11 = v6->RefCount;
    if ( v11 & 0x3FFFFFF )
    {
      v6->RefCount = v11 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v6->vfptr);
    }
  }
  return v3;
}

