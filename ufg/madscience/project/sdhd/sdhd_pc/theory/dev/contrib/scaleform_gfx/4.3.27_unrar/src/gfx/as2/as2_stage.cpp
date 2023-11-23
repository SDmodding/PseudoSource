// File Line: 59
// RVA: 0x6CBA40
void __fastcall Scaleform::GFx::AS2::StageCtorFunction::StageCtorFunction(
        Scaleform::GFx::AS2::StageCtorFunction *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        Scaleform::GFx::MovieImpl *movieRoot)
{
  Scaleform::GFx::AS2::ObjectInterface *v6; // rsi
  Scaleform::GFx::ASString *v7; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v9; // zf
  Scaleform::GFx::ASString *v10; // rax
  Scaleform::GFx::ASStringNode *v11; // rcx
  Scaleform::GFx::ASString *v12; // rax
  Scaleform::GFx::ASStringNode *v13; // rcx
  Scaleform::GFx::AS2::Value val; // [rsp+38h] [rbp-28h] BYREF
  Scaleform::GFx::AS2::PropFlags flags; // [rsp+98h] [rbp+38h] BYREF
  Scaleform::GFx::ASString result; // [rsp+A0h] [rbp+40h] BYREF

  Scaleform::GFx::AS2::CFunctionObject::CFunctionObject(this, psc, Scaleform::GFx::AS2::StageCtorFunction::GlobalCtor);
  this->Scaleform::GFx::AS2::CFunctionObject::Scaleform::GFx::AS2::FunctionObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::StageCtorFunction::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
  v6 = &this->Scaleform::GFx::AS2::ObjectInterface;
  this->Scaleform::GFx::AS2::CFunctionObject::Scaleform::GFx::AS2::FunctionObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::StageCtorFunction::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  this->pMovieRoot = movieRoot;
  if ( this != (Scaleform::GFx::AS2::StageCtorFunction *)-32i64 )
    Scaleform::GFx::AS2::NameFunction::AddConstMembers(
      &this->Scaleform::GFx::AS2::ObjectInterface,
      psc,
      GAS_AsBcFunctionTable,
      1);
  Scaleform::GFx::AS2::AsBroadcaster::InitializeInstance(psc, &this->Scaleform::GFx::AS2::ObjectInterface);
  val.T.Type = 10;
  flags.Flags = 0;
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    (Scaleform::GFx::ASString *)&psc->pContext->pMovieRoot->pASMovieRoot.pObject[33],
    &val,
    &flags);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  val.T.Type = 10;
  flags.Flags = 0;
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    (Scaleform::GFx::ASString *)&psc->pContext->pMovieRoot->pASMovieRoot.pObject[33].RefCount,
    &val,
    &flags);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  val.T.Type = 10;
  v7 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &result, "scaleMode");
  flags.Flags = 0;
  v6->vfptr->SetMemberRaw(&this->Scaleform::GFx::AS2::ObjectInterface, psc, v7, &val, &flags);
  pNode = result.pNode;
  v9 = result.pNode->RefCount-- == 1;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  val.T.Type = 10;
  v10 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &result, "align");
  flags.Flags = 0;
  v6->vfptr->SetMemberRaw(&this->Scaleform::GFx::AS2::ObjectInterface, psc, v10, &val, &flags);
  v11 = result.pNode;
  v9 = result.pNode->RefCount-- == 1;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v11);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  val.T.Type = 2;
  val.V.BooleanValue = 1;
  v12 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &result, "showMenu");
  flags.Flags = 0;
  v6->vfptr->SetMemberRaw(&this->Scaleform::GFx::AS2::ObjectInterface, psc, v12, &val, &flags);
  v13 = result.pNode;
  v9 = result.pNode->RefCount-- == 1;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v13);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
}

// File Line: 72
// RVA: 0x6F3C90
char __fastcall Scaleform::GFx::AS2::StageCtorFunction::GetMemberRaw(
        Scaleform::GFx::AS2::StageCtorFunction *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS2::Value *val)
{
  Scaleform::GFx::ASMovieRootBase *pObject; // rbp
  Scaleform::GFx::ASStringNode *pNode; // r8
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
  Scaleform::GFx::ASString result; // [rsp+58h] [rbp+10h] BYREF

  pObject = psc->pContext->pMovieRoot->pASMovieRoot.pObject;
  if ( psc->SWFVersion <= 6u )
  {
    if ( !name->pNode->pLower )
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(name->pNode);
    pNode = name->pNode;
    v10 = pObject[33].vfptr[2].__vecDelDtor == (void *(__fastcall *)(Scaleform::RefCountImplCore *, unsigned int))name->pNode->pLower;
  }
  else
  {
    pNode = name->pNode;
    v10 = pObject[33].vfptr == (Scaleform::RefCountImplCoreVtbl *)pNode;
  }
  if ( v10 )
  {
    v11 = *(float *)(*(_QWORD *)&this->ResolveHandler.Flags + 248i64)
        - *(float *)(*(_QWORD *)&this->ResolveHandler.Flags + 240i64);
LABEL_8:
    if ( val->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(val);
    val->T.Type = 4;
    val->NV.Int32Value = (int)(float)(v11 * 0.050000001);
    return 1;
  }
  v13 = psc->pContext->pMovieRoot->pASMovieRoot.pObject;
  if ( psc->SWFVersion <= 6u )
  {
    if ( !pNode->pLower )
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(pNode);
    v14 = *(Scaleform::GFx::ASStringNode **)(*(_QWORD *)&v13[33].RefCount + 16i64) == name->pNode->pLower;
  }
  else
  {
    v14 = *(_QWORD *)&v13[33].RefCount == (_QWORD)pNode;
  }
  if ( v14 )
  {
    v11 = *(float *)(*(_QWORD *)&this->ResolveHandler.Flags + 252i64)
        - *(float *)(*(_QWORD *)&this->ResolveHandler.Flags + 244i64);
    goto LABEL_8;
  }
  v15 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &result, "scaleMode");
  v16 = v15;
  if ( psc->SWFVersion <= 6u )
  {
    if ( !v15->pNode->pLower )
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(v15->pNode);
    if ( !name->pNode->pLower )
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(name->pNode);
    v17 = v16->pNode->pLower == name->pNode->pLower;
  }
  else
  {
    v17 = v15->pNode == name->pNode;
  }
  v18 = v17;
  v19 = result.pNode;
  v10 = result.pNode->RefCount-- == 1;
  if ( v10 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v19);
  if ( v18 )
  {
    v20 = (*(__int64 (__fastcall **)(_QWORD))(**(_QWORD **)&this->ResolveHandler.Flags + 120i64))(*(_QWORD *)&this->ResolveHandler.Flags);
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
    v23 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &result, v22);
    if ( val->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(val);
    val->T.Type = 5;
    v24 = v23->pNode;
    val->NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)v23->pNode;
    ++v24->RefCount;
LABEL_39:
    v25 = result.pNode;
    v10 = result.pNode->RefCount-- == 1;
    if ( v10 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v25);
    return 1;
  }
  v26 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &result, "align");
  v27 = v26;
  if ( psc->SWFVersion <= 6u )
  {
    if ( !v26->pNode->pLower )
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(v26->pNode);
    if ( !name->pNode->pLower )
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(name->pNode);
    v28 = v27->pNode->pLower == name->pNode->pLower;
  }
  else
  {
    v28 = v26->pNode == name->pNode;
  }
  v29 = v28;
  v30 = result.pNode;
  v10 = result.pNode->RefCount-- == 1;
  if ( v10 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v30);
  if ( v29 )
  {
    switch ( (*(unsigned int (__fastcall **)(_QWORD))(**(_QWORD **)&this->ResolveHandler.Flags + 136i64))(*(_QWORD *)&this->ResolveHandler.Flags) )
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
        v31 = &customCaption;
        break;
    }
    v32 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &result, v31);
    Scaleform::GFx::AS2::Value::SetString(val, v32);
    goto LABEL_39;
  }
  return Scaleform::GFx::AS2::Object::GetMemberRaw(this, psc, name, val);
}

// File Line: 118
// RVA: 0x6E0F80
Scaleform::GFx::AS2::Value *__fastcall Scaleform::GFx::AS2::StageCtorFunction::CreateRectangleObject(
        Scaleform::GFx::AS2::Value *result,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::Render::Rect<float> *rect)
{
  Scaleform::GFx::AS2::RectangleObject *v6; // rbp
  long double y2; // xmm3_8
  long double x2; // xmm2_8
  long double y1; // xmm1_8
  unsigned int RefCount; // eax
  Scaleform::Render::Rect<double> r; // [rsp+40h] [rbp-38h] BYREF

  result->T.Type = 0;
  v6 = (Scaleform::GFx::AS2::RectangleObject *)Scaleform::GFx::AS2::Environment::OperatorNew(
                                                 penv,
                                                 penv->StringContext.pContext->FlashGeomPackage,
                                                 (Scaleform::GFx::ASString *)&penv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[10].AVMVersion,
                                                 0,
                                                 -1);
  y2 = rect->y2;
  x2 = rect->x2;
  y1 = rect->y1;
  r.x1 = rect->x1;
  r.y1 = y1;
  r.x2 = x2;
  r.y2 = y2;
  Scaleform::GFx::AS2::RectangleObject::SetProperties(v6, penv, &r);
  Scaleform::GFx::AS2::Value::SetAsObject(result, v6);
  if ( v6 )
  {
    RefCount = v6->RefCount;
    if ( (RefCount & 0x3FFFFFF) != 0 )
    {
      v6->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v6);
    }
  }
  return result;
}

// File Line: 140
// RVA: 0x6F26B0
char __fastcall Scaleform::GFx::AS2::StageCtorFunction::GetMember(
        Scaleform::GFx::AS2::StageCtorFunction *this,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS2::Value *val)
{
  Scaleform::GFx::AS2::ASStringContext *p_StringContext; // rdi
  Scaleform::GFx::ASString *v9; // rax
  Scaleform::GFx::ASString *v10; // rsi
  bool v11; // zf
  bool v12; // si
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::MovieImpl *v14; // rcx
  Scaleform::GFx::AS2::Value *v15; // rax
  Scaleform::GFx::ASString *v17; // rax
  Scaleform::GFx::ASString *v18; // rsi
  bool v19; // zf
  bool v20; // si
  Scaleform::GFx::ASStringNode *v21; // rcx
  Scaleform::GFx::MovieImpl *pMovieImpl; // rcx
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
  Scaleform::Render::Rect<float> rect; // [rsp+30h] [rbp-30h] BYREF
  Scaleform::GFx::AS2::Value v38; // [rsp+40h] [rbp-20h] BYREF
  Scaleform::GFx::ASString result; // [rsp+98h] [rbp+38h] BYREF

  p_StringContext = &penv->StringContext;
  if ( penv->StringContext.pContext->GFxExtensions.Value != 1 )
    return ((__int64 (__fastcall *)(Scaleform::GFx::AS2::StageCtorFunction *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, __int64))this->Scaleform::GFx::AS2::CFunctionObject::Scaleform::GFx::AS2::FunctionObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr[3].~RefCountBaseGC<323>)(
             this,
             p_StringContext,
             name,
             val,
             -2i64);
  v9 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(p_StringContext, &result, "visibleRect");
  v10 = v9;
  if ( p_StringContext->SWFVersion <= 6u )
  {
    if ( !v9->pNode->pLower )
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(v9->pNode);
    if ( !name->pNode->pLower )
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(name->pNode);
    v11 = v10->pNode->pLower == name->pNode->pLower;
  }
  else
  {
    v11 = v9->pNode == name->pNode;
  }
  v12 = v11;
  pNode = result.pNode;
  v11 = result.pNode->RefCount-- == 1;
  if ( v11 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  if ( !v12 )
  {
    v17 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(p_StringContext, &result, "safeRect");
    v18 = v17;
    if ( p_StringContext->SWFVersion <= 6u )
    {
      if ( !v17->pNode->pLower )
        Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(v17->pNode);
      if ( !name->pNode->pLower )
        Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(name->pNode);
      v19 = v18->pNode->pLower == name->pNode->pLower;
    }
    else
    {
      v19 = v17->pNode == name->pNode;
    }
    v20 = v19;
    v21 = result.pNode;
    v11 = result.pNode->RefCount-- == 1;
    if ( v11 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v21);
    if ( v20 )
    {
      pMovieImpl = penv->Target->pASRoot->pMovieImpl;
      pMovieImpl->Scaleform::GFx::Movie::Scaleform::RefCountBase<Scaleform::GFx::Movie,327>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,327>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr[19].__vecDelDtor(
        pMovieImpl,
        (unsigned int)&rect);
      if ( rect.x1 >= rect.x2 || rect.y1 >= rect.y2 )
      {
        v23 = penv->Target->pASRoot->pMovieImpl;
        v24 = (__int64)v23->Scaleform::GFx::Movie::Scaleform::RefCountBase<Scaleform::GFx::Movie,327>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,327>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr[18].__vecDelDtor(
                         v23,
                         (unsigned int)&v38);
        v25 = *(float *)(v24 + 12);
        v26 = *(float *)(v24 + 8);
        v27 = *(float *)(v24 + 4);
        rect.x1 = *(float *)v24;
        rect.y1 = v27;
        rect.x2 = v26;
        rect.y2 = v25;
      }
      v28 = Scaleform::GFx::AS2::StageCtorFunction::CreateRectangleObject(&v38, penv, &rect);
      Scaleform::GFx::AS2::Value::operator=(val, v28);
      goto LABEL_13;
    }
    v29 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(p_StringContext, &result, "originalRect");
    v30 = v29;
    if ( p_StringContext->SWFVersion <= 6u )
    {
      if ( !v29->pNode->pLower )
        Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(v29->pNode);
      if ( !name->pNode->pLower )
        Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(name->pNode);
      v31 = v30->pNode->pLower == name->pNode->pLower;
    }
    else
    {
      v31 = v29->pNode == name->pNode;
    }
    v32 = v31;
    v33 = result.pNode;
    v11 = result.pNode->RefCount-- == 1;
    if ( v11 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v33);
    if ( v32 )
    {
      v34 = penv->Target->pASRoot->pMovieImpl;
      v35 = ((__int64 (__fastcall *)(Scaleform::GFx::MovieImpl *))v34->Scaleform::GFx::Movie::Scaleform::RefCountBase<Scaleform::GFx::Movie,327>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,327>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr[1].__vecDelDtor)(v34);
      (*(void (__fastcall **)(__int64, Scaleform::Render::Rect<float> *))(*(_QWORD *)v35 + 80i64))(v35, &rect);
      v36 = Scaleform::GFx::AS2::StageCtorFunction::CreateRectangleObject(&v38, penv, &rect);
      Scaleform::GFx::AS2::Value::operator=(val, v36);
      goto LABEL_13;
    }
    return ((__int64 (__fastcall *)(Scaleform::GFx::AS2::StageCtorFunction *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, __int64))this->Scaleform::GFx::AS2::CFunctionObject::Scaleform::GFx::AS2::FunctionObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr[3].~RefCountBaseGC<323>)(
             this,
             p_StringContext,
             name,
             val,
             -2i64);
  }
  v14 = penv->Target->pASRoot->pMovieImpl;
  v14->Scaleform::GFx::Movie::Scaleform::RefCountBase<Scaleform::GFx::Movie,327>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,327>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr[18].__vecDelDtor(
    v14,
    (unsigned int)&rect);
  v15 = Scaleform::GFx::AS2::StageCtorFunction::CreateRectangleObject(&v38, penv, &rect);
  Scaleform::GFx::AS2::Value::operator=(val, v15);
LABEL_13:
  if ( v38.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v38);
  return 1;
}

// File Line: 168
// RVA: 0x7183D0
char __fastcall Scaleform::GFx::AS2::StageCtorFunction::SetMember(
        Scaleform::GFx::AS2::StageCtorFunction *this,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS2::Value *val,
        Scaleform::GFx::AS2::PropFlags *flags)
{
  Scaleform::GFx::AS2::ASStringContext *p_StringContext; // rdi
  Scaleform::GFx::ASString *v10; // rax
  Scaleform::GFx::ASString *v11; // rsi
  bool v12; // zf
  bool v13; // si
  Scaleform::GFx::ASStringNode *pNode; // rcx
  int v15; // r15d
  Scaleform::GFx::ASString *v16; // rbx
  Scaleform::GFx::ASStringNode *v17; // rcx
  bool v18; // bl
  Scaleform::GFx::ASStringNode *v19; // rcx
  unsigned int v20; // edi
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
  unsigned int Length; // r15d
  unsigned int CharAt; // r14d
  unsigned int v41; // ebx
  Scaleform::GFx::ASStringNode *v42; // rcx
  Scaleform::GFx::ASString v43; // [rsp+30h] [rbp-10h] BYREF
  __int64 v44; // [rsp+38h] [rbp-8h]
  Scaleform::GFx::ASString result; // [rsp+78h] [rbp+38h] BYREF

  v44 = -2i64;
  p_StringContext = &penv->StringContext;
  v10 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(&penv->StringContext, &result, "scaleMode");
  v11 = v10;
  if ( p_StringContext->SWFVersion <= 6u )
  {
    if ( !v10->pNode->pLower )
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(v10->pNode);
    if ( !name->pNode->pLower )
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(name->pNode);
    v12 = v11->pNode->pLower == name->pNode->pLower;
  }
  else
  {
    v12 = v10->pNode == name->pNode;
  }
  v13 = v12;
  pNode = result.pNode;
  v12 = result.pNode->RefCount-- == 1;
  if ( v12 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  if ( v13 )
  {
    Scaleform::GFx::AS2::Value::ToString(val, &result, penv, -1);
    v15 = (*(__int64 (__fastcall **)(_QWORD))(**(_QWORD **)&this->ResolveHandler.Flags + 120i64))(*(_QWORD *)&this->ResolveHandler.Flags);
    v16 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(p_StringContext, &v43, "noScale");
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
    v12 = v43.pNode->RefCount-- == 1;
    if ( v12 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v19);
    if ( v18 )
    {
      v20 = 0;
    }
    else
    {
      v21 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(p_StringContext, &v43, "exactFit");
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
      v12 = v43.pNode->RefCount-- == 1;
      if ( v12 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v24);
      if ( v23 )
      {
        v20 = 2;
      }
      else
      {
        v25 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(p_StringContext, &v43, "noBorder");
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
        v12 = v43.pNode->RefCount-- == 1;
        if ( v12 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v28);
        v20 = 1;
        if ( v27 )
          v20 = 3;
      }
    }
    (*(void (__fastcall **)(_QWORD, _QWORD))(**(_QWORD **)&this->ResolveHandler.Flags + 112i64))(
      *(_QWORD *)&this->ResolveHandler.Flags,
      v20);
    if ( v15 != v20 && !v20 )
      Scaleform::GFx::AS2::StageCtorFunction::NotifyOnResize(
        (Scaleform::GFx::AS2::StageCtorFunction *)((char *)this - 32),
        penv);
    v29 = result.pNode;
    v12 = result.pNode->RefCount-- == 1;
    if ( v12 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v29);
    return 1;
  }
  v31 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(p_StringContext, &result, "align");
  v32 = v31;
  if ( p_StringContext->SWFVersion <= 6u )
  {
    if ( !v31->pNode->pLower )
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(v31->pNode);
    if ( !name->pNode->pLower )
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(name->pNode);
    v33 = v32->pNode->pLower == name->pNode->pLower;
  }
  else
  {
    v33 = v31->pNode == name->pNode;
  }
  v34 = v33;
  v35 = result.pNode;
  v12 = result.pNode->RefCount-- == 1;
  if ( v12 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v35);
  if ( !v34 )
    return Scaleform::GFx::AS2::Object::SetMember(this, penv, name, val, flags);
  v36 = Scaleform::GFx::AS2::Value::ToString(val, &v43, penv, -1);
  Scaleform::GFx::ASString::ToUpper(v36, &result);
  v37 = v43.pNode;
  v12 = v43.pNode->RefCount-- == 1;
  if ( v12 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v37);
  v38 = 0;
  Length = Scaleform::GFx::ASConstString::GetLength(&result);
  if ( !Length )
    goto LABEL_76;
  CharAt = Scaleform::GFx::ASConstString::GetCharAt(&result, 0);
  v41 = 1;
  if ( Length >= 2 )
    v38 = Scaleform::GFx::ASConstString::GetCharAt(&result, 1u);
  if ( CharAt == 84 )
  {
    if ( v38 != 76 )
    {
      if ( v38 != 82 )
        goto LABEL_77;
      goto LABEL_67;
    }
    goto LABEL_62;
  }
  if ( CharAt != 76 )
  {
    if ( CharAt == 82 )
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
    if ( CharAt == 66 )
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
  (*(void (__fastcall **)(_QWORD, _QWORD))(**(_QWORD **)&this->ResolveHandler.Flags + 128i64))(
    *(_QWORD *)&this->ResolveHandler.Flags,
    v41);
  v42 = result.pNode;
  v12 = result.pNode->RefCount-- == 1;
  if ( !v12 )
    return 1;
  Scaleform::GFx::ASStringNode::ReleaseNode(v42);
  return 1;
}

// File Line: 229
// RVA: 0x719FF0
char __fastcall Scaleform::GFx::AS2::StageCtorFunction::SetMemberRaw(
        Scaleform::GFx::AS2::StageCtorFunction *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS2::Value *val,
        Scaleform::GFx::AS2::PropFlags *flags)
{
  Scaleform::GFx::ASMovieRootBase *pObject; // rdi
  Scaleform::GFx::ASStringNode *pNode; // r10
  bool v11; // zf
  Scaleform::GFx::ASMovieRootBase *v12; // rdi
  bool v13; // zf

  pObject = psc->pContext->pMovieRoot->pASMovieRoot.pObject;
  if ( psc->SWFVersion <= 6u )
  {
    if ( !name->pNode->pLower )
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(name->pNode);
    pNode = name->pNode;
    v11 = pObject[33].vfptr[2].__vecDelDtor == (void *(__fastcall *)(Scaleform::RefCountImplCore *, unsigned int))name->pNode->pLower;
  }
  else
  {
    pNode = name->pNode;
    v11 = pObject[33].vfptr == (Scaleform::RefCountImplCoreVtbl *)name->pNode;
  }
  if ( v11 )
    return 1;
  v12 = psc->pContext->pMovieRoot->pASMovieRoot.pObject;
  if ( psc->SWFVersion <= 6u )
  {
    if ( !pNode->pLower )
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(pNode);
    v13 = *(Scaleform::GFx::ASStringNode **)(*(_QWORD *)&v12[33].RefCount + 16i64) == name->pNode->pLower;
  }
  else
  {
    v13 = *(_QWORD *)&v12[33].RefCount == (_QWORD)pNode;
  }
  if ( v13 )
    return 1;
  else
    return Scaleform::GFx::AS2::Object::SetMemberRaw(this, psc, name, val, flags);
}

// File Line: 240
// RVA: 0x704950
void __fastcall Scaleform::GFx::AS2::StageCtorFunction::NotifyOnResize(
        Scaleform::GFx::AS2::StageCtorFunction *this,
        Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::MovieImpl *pMovieImpl; // rcx
  Scaleform::GFx::ASStringNode *pCurrent; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v6; // rdi
  Scaleform::GFx::ASString *v7; // r8
  int v8; // r9d
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v10; // zf
  Scaleform::GFx::AS2::Value *v11; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v12; // rbx
  Scaleform::GFx::ASString *v13; // r8
  Scaleform::GFx::ASStringNode *v14; // rcx
  Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback pcallback; // [rsp+28h] [rbp-48h] BYREF
  __int64 v16; // [rsp+30h] [rbp-40h]
  Scaleform::Render::Rect<float> rect; // [rsp+40h] [rbp-30h] BYREF
  Scaleform::GFx::AS2::Value result; // [rsp+50h] [rbp-20h] BYREF
  Scaleform::GFx::ASString v19; // [rsp+98h] [rbp+28h] BYREF
  Scaleform::GFx::ASStringNode *v20; // [rsp+A0h] [rbp+30h]

  if ( penv->StringContext.pContext->GFxExtensions.Value == 1 )
  {
    pMovieImpl = penv->Target->pASRoot->pMovieImpl;
    pMovieImpl->Scaleform::GFx::Movie::Scaleform::RefCountBase<Scaleform::GFx::Movie,327>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,327>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr[18].__vecDelDtor(
      pMovieImpl,
      (unsigned int)&rect);
    Scaleform::GFx::AS2::StageCtorFunction::CreateRectangleObject(&result, penv, &rect);
    if ( ++penv->Stack.pCurrent >= penv->Stack.pPageEnd )
      Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&penv->Stack);
    pCurrent = (Scaleform::GFx::ASStringNode *)penv->Stack.pCurrent;
    v19.pNode = pCurrent;
    v20 = pCurrent;
    if ( pCurrent )
      Scaleform::GFx::AS2::Value::Value((Scaleform::GFx::AS2::Value *)pCurrent, &result);
    if ( this )
      v6 = &this->Scaleform::GFx::AS2::ObjectInterface;
    else
      v6 = 0i64;
    v7 = Scaleform::GFx::AS2::Environment::CreateConstString(penv, &v19, "onResize");
    v8 = penv->Stack.pCurrent - penv->Stack.pPageStart + 32 * penv->Stack.Pages.Data.Size - 32;
    if ( v6 )
    {
      pcallback.vfptr = (Scaleform::GFx::AS2::AsBroadcaster::InvokeCallbackVtbl *)`Scaleform::GFx::AS2::AsBroadcaster::BroadcastMessage::`4::LocalInvokeCallback::`vftable;
      LODWORD(v16) = 1;
      HIDWORD(v16) = v8;
      Scaleform::GFx::AS2::AsBroadcaster::BroadcastMessageWithCallback(penv, v6, v7, &pcallback);
      pcallback.vfptr = (Scaleform::GFx::AS2::AsBroadcaster::InvokeCallbackVtbl *)&Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback::`vftable;
    }
    pNode = v19.pNode;
    v10 = v19.pNode->RefCount-- == 1;
    if ( v10 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    v11 = penv->Stack.pCurrent;
    if ( v11->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(v11);
    if ( --penv->Stack.pCurrent < penv->Stack.pPageStart )
      Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(&penv->Stack);
    if ( result.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&result);
  }
  else
  {
    v12 = &this->Scaleform::GFx::AS2::ObjectInterface;
    if ( !this )
      v12 = 0i64;
    v13 = Scaleform::GFx::AS2::Environment::CreateConstString(penv, &v19, "onResize");
    if ( v12 )
    {
      pcallback.vfptr = (Scaleform::GFx::AS2::AsBroadcaster::InvokeCallbackVtbl *)`Scaleform::GFx::AS2::AsBroadcaster::BroadcastMessage::`4::LocalInvokeCallback::`vftable;
      v16 = 0i64;
      Scaleform::GFx::AS2::AsBroadcaster::BroadcastMessageWithCallback(penv, v12, v13, &pcallback);
      pcallback.vfptr = (Scaleform::GFx::AS2::AsBroadcaster::InvokeCallbackVtbl *)&Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback::`vftable;
    }
    v14 = v19.pNode;
    v10 = v19.pNode->RefCount-- == 1;
    if ( v10 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v14);
  }
}

// File Line: 259
// RVA: 0x704B20
void __fastcall Scaleform::GFx::AS2::StageCtorFunction::NotifyOnResize(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::StageCtorFunction *v2; // rax
  Scaleform::GFx::AS2::Value v3; // [rsp+28h] [rbp-30h] BYREF

  v3.T.Type = 0;
  if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::AS2::ObjectInterface *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::MovieImpl **, Scaleform::GFx::AS2::Value *, __int64))fn->Env->StringContext.pContext->pGlobal.pObject->vfptr->GetMemberRaw)(
         &fn->Env->StringContext.pContext->pGlobal.pObject->Scaleform::GFx::AS2::ObjectInterface,
         &fn->Env->StringContext,
         &fn->Env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[11].pMovieImpl,
         &v3,
         -2i64) )
  {
    if ( v3.T.Type != 11 )
    {
      v2 = (Scaleform::GFx::AS2::StageCtorFunction *)Scaleform::GFx::AS2::Value::ToObject(&v3, fn->Env);
      if ( v2 )
      {
        if ( v2 != (Scaleform::GFx::AS2::StageCtorFunction *)-32i64 )
          Scaleform::GFx::AS2::StageCtorFunction::NotifyOnResize(v2, fn->Env);
      }
    }
  }
  if ( v3.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v3);
}

// File Line: 286
// RVA: 0x70EAC0
Scaleform::GFx::AS2::FunctionRef *__fastcall Scaleform::GFx::AS2::StageCtorFunction::Register(
        Scaleform::GFx::AS2::FunctionRef *result,
        Scaleform::GFx::AS2::GlobalContext *pgc)
{
  Scaleform::GFx::AS2::StageCtorFunction *v4; // rax
  Scaleform::MemoryHeap *v5; // rcx
  Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::StageObject,Scaleform::GFx::AS2::Environment> *v6; // rbx
  Scaleform::GFx::AS2::Object *Prototype; // rax
  Scaleform::GFx::AS2::Object *pObject; // r14
  Scaleform::GFx::ASStringNode *Function; // rax
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // rdx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::ASStringContext psc; // [rsp+40h] [rbp-30h] BYREF
  Scaleform::GFx::AS2::Value v14; // [rsp+50h] [rbp-20h] BYREF
  Scaleform::MemoryHeap *flags; // [rsp+A8h] [rbp+38h] BYREF
  Scaleform::MemoryHeap *pHeap; // [rsp+B0h] [rbp+40h]
  Scaleform::MemoryHeap **p_flags; // [rsp+B8h] [rbp+48h]

  psc.pContext = pgc;
  psc.SWFVersion = 8;
  flags = pgc->pHeap;
  v4 = (Scaleform::GFx::AS2::StageCtorFunction *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::FunctionRef *, __int64))flags->vfptr->Alloc)(
                                                   result,
                                                   112i64);
  pHeap = (Scaleform::MemoryHeap *)v4;
  if ( v4 )
    Scaleform::GFx::AS2::StageCtorFunction::StageCtorFunction(v4, &psc, pgc->pMovieRoot);
  result->Flags = 0;
  result->Function = v4;
  result->pLocalFrame = 0i64;
  pHeap = pgc->pHeap;
  v6 = (Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::StageObject,Scaleform::GFx::AS2::Environment> *)pHeap->vfptr->Alloc(v5, 160ui64, 0i64);
  p_flags = (Scaleform::MemoryHeap **)v6;
  if ( v6 )
  {
    Prototype = Scaleform::GFx::AS2::GlobalContext::GetPrototype(pgc, ASBuiltin_Object);
    Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::StageObject,Scaleform::GFx::AS2::Environment>::Prototype<Scaleform::GFx::AS2::StageObject,Scaleform::GFx::AS2::Environment>(
      v6,
      &psc,
      Prototype,
      result);
    v6->Scaleform::GFx::AS2::StageObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::StageProto::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
    v6->Scaleform::GFx::AS2::StageObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::StageProto::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
    v6->Scaleform::GFx::AS2::GASPrototypeBase::vfptr = (Scaleform::GFx::AS2::GASPrototypeBaseVtbl *)&Scaleform::GFx::AS2::StageProto::`vftable;
    LOBYTE(flags) = 1;
    Scaleform::GFx::AS2::GASPrototypeBase::InitFunctionMembers(
      &v6->Scaleform::GFx::AS2::GASPrototypeBase,
      v6,
      &psc,
      GFx_StageFunctionTable,
      (Scaleform::GFx::AS2::PropFlags *)&flags);
  }
  else
  {
    v6 = 0i64;
  }
  pHeap = (Scaleform::MemoryHeap *)v6;
  p_flags = &flags;
  if ( v6 )
    v6->RefCount = (v6->RefCount + 1) & 0x8FFFFFFF;
  flags = (Scaleform::MemoryHeap *)v6;
  Scaleform::GFx::AS2::GlobalContext::SetPrototype(
    pgc,
    ASBuiltin_Stage,
    (Scaleform::Ptr<Scaleform::GFx::AS2::Object>)&flags);
  pObject = pgc->pGlobal.pObject;
  v14.T.Type = 8;
  v14.V.FunctionValue.Flags = 0;
  Function = (Scaleform::GFx::ASStringNode *)result->Function;
  v14.V.pStringNode = Function;
  if ( Function )
  {
    ++Function->RefCount;
    Function->RefCount &= 0x8FFFFFFF;
  }
  v14.V.FunctionValue.pLocalFrame = 0i64;
  pLocalFrame = result->pLocalFrame;
  if ( pLocalFrame )
    Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(&v14.V.FunctionValue, pLocalFrame, result->Flags & 1);
  LOBYTE(flags) = 0;
  pObject->Scaleform::GFx::AS2::ObjectInterface::vfptr->SetMemberRaw(
    &pObject->Scaleform::GFx::AS2::ObjectInterface,
    &psc,
    (Scaleform::GFx::ASString *)&pgc->pMovieRoot->pASMovieRoot.pObject[11].pMovieImpl,
    &v14,
    (Scaleform::GFx::AS2::PropFlags *)&flags);
  if ( v14.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v14);
  if ( v6 )
  {
    RefCount = v6->RefCount;
    if ( (RefCount & 0x3FFFFFF) != 0 )
    {
      v6->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v6);
    }
  }
  return result;
}

