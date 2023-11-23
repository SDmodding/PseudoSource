// File Line: 34
// RVA: 0x6ED6D0
void __fastcall Scaleform::GFx::AS2::GFxObject_GetColorTransformProperties(
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::AS2::Object *pobj,
        Scaleform::GFx::AS2::Value *params)
{
  Scaleform::GFx::AS2::ASStringContext *p_StringContext; // rbx
  Scaleform::GFx::AS2::ObjectInterface *v5; // rdi
  Scaleform::GFx::ASString *v6; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v8; // zf
  Scaleform::GFx::ASString *v9; // rax
  Scaleform::GFx::ASStringNode *v10; // rcx
  Scaleform::GFx::ASString *v11; // rax
  Scaleform::GFx::ASStringNode *v12; // rcx
  Scaleform::GFx::ASString *v13; // rax
  Scaleform::GFx::ASStringNode *v14; // rcx
  Scaleform::GFx::ASString *v15; // rax
  Scaleform::GFx::ASStringNode *v16; // rcx
  Scaleform::GFx::ASString *v17; // rax
  Scaleform::GFx::ASStringNode *v18; // rcx
  Scaleform::GFx::ASString *v19; // rax
  Scaleform::GFx::ASStringNode *v20; // rcx
  Scaleform::GFx::ASString *v21; // rax
  Scaleform::GFx::ASStringNode *v22; // rcx
  Scaleform::GFx::ASString result; // [rsp+40h] [rbp+8h] BYREF

  p_StringContext = &penv->StringContext;
  v5 = &pobj->Scaleform::GFx::AS2::ObjectInterface;
  v6 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(&penv->StringContext, &result, "redMultiplier");
  ((void (__fastcall *)(Scaleform::GFx::AS2::ObjectInterface *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, __int64))v5->vfptr->GetMemberRaw)(
    v5,
    p_StringContext,
    v6,
    params,
    -2i64);
  pNode = result.pNode;
  v8 = result.pNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  v9 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(p_StringContext, &result, "greenMultiplier");
  v5->vfptr->GetMemberRaw(v5, p_StringContext, v9, params + 1);
  v10 = result.pNode;
  v8 = result.pNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v10);
  v11 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(p_StringContext, &result, "blueMultiplier");
  v5->vfptr->GetMemberRaw(v5, p_StringContext, v11, params + 2);
  v12 = result.pNode;
  v8 = result.pNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v12);
  v13 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(p_StringContext, &result, "alphaMultiplier");
  v5->vfptr->GetMemberRaw(v5, p_StringContext, v13, params + 3);
  v14 = result.pNode;
  v8 = result.pNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v14);
  v15 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(p_StringContext, &result, "redOffset");
  v5->vfptr->GetMemberRaw(v5, p_StringContext, v15, params + 4);
  v16 = result.pNode;
  v8 = result.pNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v16);
  v17 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(p_StringContext, &result, "greenOffset");
  v5->vfptr->GetMemberRaw(v5, p_StringContext, v17, params + 5);
  v18 = result.pNode;
  v8 = result.pNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v18);
  v19 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(p_StringContext, &result, "blueOffset");
  v5->vfptr->GetMemberRaw(v5, p_StringContext, v19, params + 6);
  v20 = result.pNode;
  v8 = result.pNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v20);
  v21 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(p_StringContext, &result, "alphaOffset");
  v5->vfptr->GetMemberRaw(v5, p_StringContext, v21, params + 7);
  v22 = result.pNode;
  v8 = result.pNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v22);
}

// File Line: 51
// RVA: 0x6C80E0
void __fastcall Scaleform::GFx::AS2::ColorTransformObject::ColorTransformObject(
        Scaleform::GFx::AS2::ColorTransformObject *this,
        Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::Object *Prototype; // rax

  Scaleform::GFx::AS2::Object::Object(this, penv);
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::ColorTransformObject::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::ColorTransformObject::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  Scaleform::Render::Cxform::Cxform(&this->mColorTransform);
  Prototype = Scaleform::GFx::AS2::GlobalContext::GetPrototype(penv->StringContext.pContext, ASBuiltin_ColorTransform);
  Scaleform::GFx::AS2::Object::Set__proto__(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    &penv->StringContext,
    Prototype);
}

// File Line: 76
// RVA: 0x6F19A0
char __fastcall Scaleform::GFx::AS2::ColorTransformObject::GetMember(
        Scaleform::GFx::AS2::ColorTransformObject *this,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS2::Value *val)
{
  const char *pData; // rdi
  __int64 v10; // rcx
  char v11; // al
  Scaleform::GFx::AS2::Value v; // [rsp+8h] [rbp-69h] BYREF
  __int64 v13; // [rsp+28h] [rbp-49h]
  char v14; // [rsp+30h] [rbp-41h]
  char v15; // [rsp+50h] [rbp-21h]
  char v16; // [rsp+70h] [rbp-1h]

  v13 = -2i64;
  pData = name->pNode->pData;
  if ( !strcmp(pData, "redMultiplier")
    || !strcmp(pData, "greenMultiplier")
    || !strcmp(pData, "blueMultiplier")
    || !strcmp(pData, "alphaMultiplier")
    || !strcmp(pData, "redOffset")
    || !strcmp(pData, "greenOffset")
    || !strcmp(pData, "blueOffset")
    || !strcmp(pData, "alphaOffset") )
  {
    Scaleform::GFx::AS2::Value::operator=(val, &v);
    if ( v.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v);
  }
  else
  {
    v10 = 0i64;
    do
    {
      v11 = pData[v10++];
      if ( v11 != aRgb[v10 - 1] )
        return ((__int64 (__fastcall *)(Scaleform::GFx::AS2::ColorTransformObject *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr[3].~RefCountBaseGC<323>)(
                 this,
                 &penv->StringContext,
                 name,
                 val);
    }
    while ( v10 != 4 );
    v14 = 0;
    v15 = 0;
    v16 = 0;
    Scaleform::GFx::NumberUtil::IsNaN(*(float *)&this->pWatchpoints);
    Scaleform::GFx::NumberUtil::IsNaN(*((float *)&this->pWatchpoints + 1));
    Scaleform::GFx::NumberUtil::IsNaN(*(float *)&this->ArePropertiesSet);
    Scaleform::GFx::AS2::Value::operator=(val, &v);
    if ( v.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v);
  }
  return 1;
}

// File Line: 134
// RVA: 0x717380
bool __fastcall Scaleform::GFx::AS2::ColorTransformObject::SetMember(
        Scaleform::GFx::AS2::ColorTransformObject *this,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS2::Value *val,
        Scaleform::GFx::AS2::PropFlags *flags)
{
  const char *pData; // rdi
  long double v10; // xmm0_8
  bool result; // al
  float v12; // xmm1_4
  long double v13; // xmm0_8
  float v14; // xmm1_4
  long double v15; // xmm0_8
  float v16; // xmm1_4
  long double v17; // xmm0_8
  float v18; // xmm1_4
  long double v19; // xmm0_8
  float v20; // xmm1_4
  long double v21; // xmm0_8
  float v22; // xmm1_4
  long double v23; // xmm0_8
  float v24; // xmm1_4
  long double v25; // xmm0_8
  float v26; // xmm1_4
  int v27; // r14d
  __int64 v28; // rcx
  char v29; // al
  int v30; // edi
  int v31; // r15d
  long double v32; // xmm0_8
  long double v33; // xmm0_8

  pData = name->pNode->pData;
  if ( !strcmp(pData, "redMultiplier") )
  {
    v10 = Scaleform::GFx::AS2::Value::ToNumber(val, penv);
    result = 1;
    v12 = v10;
    *(float *)&this->ResolveHandler.pLocalFrame = v12;
  }
  else if ( !strcmp(pData, "greenMultiplier") )
  {
    v13 = Scaleform::GFx::AS2::Value::ToNumber(val, penv);
    result = 1;
    v14 = v13;
    *((float *)&this->ResolveHandler.pLocalFrame + 1) = v14;
  }
  else if ( !strcmp(pData, "blueMultiplier") )
  {
    v15 = Scaleform::GFx::AS2::Value::ToNumber(val, penv);
    result = 1;
    v16 = v15;
    *(float *)&this->ResolveHandler.Flags = v16;
  }
  else if ( !strcmp(pData, "alphaMultiplier") )
  {
    v17 = Scaleform::GFx::AS2::Value::ToNumber(val, penv);
    result = 1;
    v18 = v17;
    *((float *)&this->ResolveHandler.Flags + 1) = v18;
  }
  else if ( !strcmp(pData, "redOffset") )
  {
    v19 = Scaleform::GFx::AS2::Value::ToNumber(val, penv);
    result = 1;
    v20 = v19;
    *(float *)&this->pWatchpoints = v20;
  }
  else if ( !strcmp(pData, "greenOffset") )
  {
    v21 = Scaleform::GFx::AS2::Value::ToNumber(val, penv);
    result = 1;
    v22 = v21;
    *((float *)&this->pWatchpoints + 1) = v22;
  }
  else if ( !strcmp(pData, "blueOffset") )
  {
    v23 = Scaleform::GFx::AS2::Value::ToNumber(val, penv);
    result = 1;
    v24 = v23;
    *(float *)&this->ArePropertiesSet = v24;
  }
  else if ( !strcmp(pData, "alphaOffset") )
  {
    v25 = Scaleform::GFx::AS2::Value::ToNumber(val, penv);
    result = 1;
    v26 = v25;
    *(float *)(&this->IsListenerSet + 3) = v26;
  }
  else
  {
    v27 = 0;
    v28 = 0i64;
    do
    {
      v29 = pData[v28++];
      if ( v29 != aRgb[v28 - 1] )
        return Scaleform::GFx::AS2::Object::SetMember(this, penv, name, val, flags);
    }
    while ( v28 != 4 );
    this->ResolveHandler.pLocalFrame = 0i64;
    *(_DWORD *)&this->ResolveHandler.Flags = 0;
    v30 = 0;
    v31 = 0;
    v32 = Scaleform::GFx::AS2::Value::ToNumber(val, penv);
    if ( !Scaleform::GFx::NumberUtil::IsNaN(v32) )
    {
      v33 = Scaleform::GFx::AS2::Value::ToNumber(val, penv);
      v31 = (unsigned __int8)(int)v33;
      v27 = (unsigned __int8)((unsigned int)(int)v33 >> 16);
      v30 = (unsigned __int8)((unsigned __int16)(int)v33 >> 8);
    }
    *(float *)&this->pWatchpoints = (float)v27;
    *((float *)&this->pWatchpoints + 1) = (float)v30;
    result = 1;
    *(float *)&this->ArePropertiesSet = (float)v31;
  }
  return result;
}

// File Line: 217
// RVA: 0x6C8160
void __fastcall Scaleform::GFx::AS2::ColorTransformProto::ColorTransformProto(
        Scaleform::GFx::AS2::ColorTransformProto *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        Scaleform::GFx::AS2::Object *pprototype,
        Scaleform::GFx::AS2::FunctionRef *constructor)
{
  Scaleform::GFx::ASString *v6; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v8; // zf
  Scaleform::GFx::ASString *v9; // rax
  Scaleform::GFx::ASStringNode *v10; // rcx
  Scaleform::GFx::ASString *v11; // rax
  Scaleform::GFx::ASStringNode *v12; // rcx
  Scaleform::GFx::ASString *v13; // rax
  Scaleform::GFx::ASStringNode *v14; // rcx
  Scaleform::GFx::ASString *v15; // rax
  Scaleform::GFx::ASStringNode *v16; // rcx
  Scaleform::GFx::ASString *v17; // rax
  Scaleform::GFx::ASStringNode *v18; // rcx
  Scaleform::GFx::ASString *v19; // rax
  Scaleform::GFx::ASStringNode *v20; // rcx
  Scaleform::GFx::ASString *v21; // rax
  Scaleform::GFx::ASStringNode *v22; // rcx
  Scaleform::GFx::ASString *v23; // rax
  Scaleform::GFx::ASStringNode *v24; // rcx
  Scaleform::GFx::AS2::PropFlags flags; // [rsp+30h] [rbp-40h] BYREF
  Scaleform::GFx::ASString result; // [rsp+38h] [rbp-38h] BYREF
  __int64 v27; // [rsp+40h] [rbp-30h]
  Scaleform::GFx::AS2::Value val; // [rsp+48h] [rbp-28h] BYREF

  v27 = -2i64;
  Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::ColorTransformObject,Scaleform::GFx::AS2::Environment>::Prototype<Scaleform::GFx::AS2::ColorTransformObject,Scaleform::GFx::AS2::Environment>(
    this,
    psc,
    pprototype,
    constructor);
  this->Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::ColorTransformObject,Scaleform::GFx::AS2::Environment>::Scaleform::GFx::AS2::ColorTransformObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::ColorTransformProto::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
  this->Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::ColorTransformObject,Scaleform::GFx::AS2::Environment>::Scaleform::GFx::AS2::ColorTransformObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::ColorTransformProto::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  this->Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::ColorTransformObject,Scaleform::GFx::AS2::Environment>::Scaleform::GFx::AS2::GASPrototypeBase::vfptr = (Scaleform::GFx::AS2::GASPrototypeBaseVtbl *)&Scaleform::GFx::AS2::ColorTransformProto::`vftable;
  flags.Flags = 6;
  Scaleform::GFx::AS2::GASPrototypeBase::InitFunctionMembers(
    &this->Scaleform::GFx::AS2::GASPrototypeBase,
    this,
    psc,
    Scaleform::GFx::AS2::ColorTransformProto::FunctionTable,
    &flags);
  flags.Flags = 2;
  val.T.Type = 4;
  val.NV.Int32Value = 0;
  v6 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &result, "redMultiplier");
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    v6,
    &val,
    &flags);
  pNode = result.pNode;
  v8 = result.pNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  flags.Flags = 2;
  val.T.Type = 4;
  val.NV.Int32Value = 0;
  v9 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &result, "greenMultiplier");
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    v9,
    &val,
    &flags);
  v10 = result.pNode;
  v8 = result.pNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v10);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  flags.Flags = 2;
  val.T.Type = 4;
  val.NV.Int32Value = 0;
  v11 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &result, "blueMultiplier");
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    v11,
    &val,
    &flags);
  v12 = result.pNode;
  v8 = result.pNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v12);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  flags.Flags = 2;
  val.T.Type = 4;
  val.NV.Int32Value = 0;
  v13 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &result, "alphaMultiplier");
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    v13,
    &val,
    &flags);
  v14 = result.pNode;
  v8 = result.pNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v14);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  flags.Flags = 2;
  val.T.Type = 4;
  val.NV.Int32Value = 0;
  v15 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &result, "redOffset");
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    v15,
    &val,
    &flags);
  v16 = result.pNode;
  v8 = result.pNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v16);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  flags.Flags = 2;
  val.T.Type = 4;
  val.NV.Int32Value = 0;
  v17 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &result, "greenOffset");
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    v17,
    &val,
    &flags);
  v18 = result.pNode;
  v8 = result.pNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v18);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  flags.Flags = 2;
  val.T.Type = 4;
  val.NV.Int32Value = 0;
  v19 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &result, "blueOffset");
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    v19,
    &val,
    &flags);
  v20 = result.pNode;
  v8 = result.pNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v20);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  flags.Flags = 2;
  val.T.Type = 4;
  val.NV.Int32Value = 0;
  v21 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &result, "alphaOffset");
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    v21,
    &val,
    &flags);
  v22 = result.pNode;
  v8 = result.pNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v22);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  flags.Flags = 2;
  val.T.Type = 4;
  val.NV.Int32Value = 0;
  v23 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &result, "rgb");
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    v23,
    &val,
    &flags);
  v24 = result.pNode;
  v8 = result.pNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v24);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
}

// File Line: 238
// RVA: 0x6B2550
void __fastcall Scaleform::GFx::AS2::ColorTransformProto::Concat(Scaleform::GFx::AS2::FnCall *fn)
{
  unsigned int FirstArgBottomIndex; // r10d
  Scaleform::GFx::AS2::Environment *Env; // r9
  Scaleform::Render::Cxform *v4; // rsi
  Scaleform::GFx::AS2::Value *v5; // rcx
  Scaleform::GFx::AS2::Object *v6; // rdi
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v8; // rax
  float v9; // xmm1_4
  float v10; // xmm1_4
  float v11; // xmm1_4
  float v12; // xmm1_4
  float v13; // xmm1_4
  float v14; // xmm1_4
  float v15; // xmm1_4
  float v16; // xmm1_4
  Scaleform::Render::Cxform c; // [rsp+30h] [rbp-138h] BYREF
  __int64 v18; // [rsp+50h] [rbp-118h]
  Scaleform::GFx::AS2::Value ptr; // [rsp+60h] [rbp-108h] BYREF
  Scaleform::GFx::AS2::Value v20; // [rsp+80h] [rbp-E8h] BYREF
  Scaleform::GFx::AS2::Value v21; // [rsp+A0h] [rbp-C8h] BYREF
  Scaleform::GFx::AS2::Value v22; // [rsp+C0h] [rbp-A8h] BYREF
  Scaleform::GFx::AS2::Value v23; // [rsp+E0h] [rbp-88h] BYREF
  Scaleform::GFx::AS2::Value v24; // [rsp+100h] [rbp-68h] BYREF
  Scaleform::GFx::AS2::Value v25; // [rsp+120h] [rbp-48h] BYREF
  Scaleform::GFx::AS2::Value v26; // [rsp+140h] [rbp-28h] BYREF

  v18 = -2i64;
  if ( fn->NArgs > 0 )
  {
    FirstArgBottomIndex = fn->FirstArgBottomIndex;
    Env = fn->Env;
    v4 = 0i64;
    v5 = 0i64;
    if ( FirstArgBottomIndex <= 32 * ((unsigned int)Env->Stack.Pages.Data.Size - 1)
                              + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
      v5 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
    v6 = Scaleform::GFx::AS2::Value::ToObject(v5, Env);
    if ( v6 )
    {
      ThisPtr = fn->ThisPtr;
      if ( ThisPtr
        && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(ThisPtr) == 18 )
      {
        v8 = fn->ThisPtr;
        if ( v8 )
          v4 = (Scaleform::Render::Cxform *)&v8[-2];
        if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v6->Scaleform::GFx::AS2::ObjectInterface::vfptr->gap8[8])(&v6->Scaleform::GFx::AS2::ObjectInterface) == 18 )
        {
          Scaleform::Render::Cxform::Prepend(v4 + 3, (Scaleform::Render::Cxform *)&v6[1]);
        }
        else
        {
          `eh vector constructor iterator(
            &ptr,
            0x20ui64,
            8,
            (void (__fastcall *)(void *))Scaleform::GFx::AS2::Value::Value);
          Scaleform::GFx::AS2::GFxObject_GetColorTransformProperties(fn->Env, v6, &ptr);
          Scaleform::Render::Cxform::Cxform(&c);
          v9 = Scaleform::GFx::AS2::Value::ToNumber(&ptr, fn->Env);
          c.M[0][0] = v9;
          v10 = Scaleform::GFx::AS2::Value::ToNumber(&v20, fn->Env);
          c.M[0][1] = v10;
          v11 = Scaleform::GFx::AS2::Value::ToNumber(&v21, fn->Env);
          c.M[0][2] = v11;
          v12 = Scaleform::GFx::AS2::Value::ToNumber(&v22, fn->Env);
          c.M[0][3] = v12;
          v13 = Scaleform::GFx::AS2::Value::ToNumber(&v23, fn->Env);
          c.M[1][0] = v13;
          v14 = Scaleform::GFx::AS2::Value::ToNumber(&v24, fn->Env);
          c.M[1][1] = v14;
          v15 = Scaleform::GFx::AS2::Value::ToNumber(&v25, fn->Env);
          c.M[1][2] = v15;
          v16 = Scaleform::GFx::AS2::Value::ToNumber(&v26, fn->Env);
          c.M[1][3] = v16;
          Scaleform::Render::Cxform::Prepend(v4 + 3, &c);
          `eh vector destructor iterator(
            &ptr,
            0x20ui64,
            8,
            (void (__fastcall *)(void *))Scaleform::GFx::AS2::Value::~Value);
        }
      }
      else
      {
        Scaleform::GFx::AS2::Environment::LogScriptError(
          fn->Env,
          "Error: Null or invalid this is used for a method of %s class.\n",
          "ColorTransform");
      }
    }
  }
}

// File Line: 280
// RVA: 0x6B27B0
void __fastcall Scaleform::GFx::AS2::ColorTransformProto::ToString(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rax
  float *v4; // rdi
  char *pData; // r8
  Scaleform::GFx::ASString *v6; // rdi
  Scaleform::GFx::AS2::Value *v7; // rbx
  Scaleform::GFx::ASStringNode *pNode; // rax
  Scaleform::StringBuffer v10; // [rsp+20h] [rbp-D8h] BYREF
  Scaleform::GFx::ASString result; // [rsp+50h] [rbp-A8h] BYREF
  Scaleform::GFx::ASString v12; // [rsp+58h] [rbp-A0h] BYREF
  Scaleform::GFx::ASString v13; // [rsp+60h] [rbp-98h] BYREF
  Scaleform::GFx::ASString v14; // [rsp+68h] [rbp-90h] BYREF
  Scaleform::GFx::ASString v15; // [rsp+70h] [rbp-88h] BYREF
  Scaleform::GFx::ASString v16; // [rsp+78h] [rbp-80h] BYREF
  Scaleform::GFx::ASString v17; // [rsp+80h] [rbp-78h] BYREF
  __int64 v18; // [rsp+88h] [rbp-70h]
  Scaleform::GFx::AS2::Value v19; // [rsp+90h] [rbp-68h] BYREF
  Scaleform::GFx::AS2::Value v20; // [rsp+B0h] [rbp-48h] BYREF
  Scaleform::GFx::AS2::Value v21; // [rsp+D0h] [rbp-28h] BYREF
  Scaleform::GFx::AS2::Value v22; // [rsp+F0h] [rbp-8h] BYREF
  Scaleform::GFx::AS2::Value v23; // [rsp+110h] [rbp+18h] BYREF
  Scaleform::GFx::AS2::Value ptr; // [rsp+130h] [rbp+38h] BYREF
  Scaleform::GFx::AS2::Value v25; // [rsp+150h] [rbp+58h] BYREF
  Scaleform::GFx::AS2::Value v26; // [rsp+170h] [rbp+78h] BYREF
  Scaleform::GFx::ASString retaddr; // [rsp+1A8h] [rbp+B0h] BYREF

  v18 = -2i64;
  ThisPtr = fn->ThisPtr;
  if ( ThisPtr
    && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(ThisPtr) == 18 )
  {
    v3 = fn->ThisPtr;
    if ( v3 )
      v4 = (float *)&v3[-2];
    else
      v4 = 0i64;
    v25.T.Type = 3;
    v25.NV.NumberValue = v4[24];
    Scaleform::GFx::AS2::Value::ToString(&v25, &result, fn->Env, 6);
    ptr.T.Type = 3;
    ptr.NV.NumberValue = v4[25];
    Scaleform::GFx::AS2::Value::ToString(&ptr, &v12, fn->Env, 6);
    v26.T.Type = 3;
    v26.NV.NumberValue = v4[26];
    Scaleform::GFx::AS2::Value::ToString(&v26, &v13, fn->Env, 6);
    v21.T.Type = 3;
    v21.NV.NumberValue = v4[27];
    Scaleform::GFx::AS2::Value::ToString(&v21, &v14, fn->Env, 6);
    v19.T.Type = 3;
    v19.NV.NumberValue = v4[28];
    Scaleform::GFx::AS2::Value::ToString(&v19, &v15, fn->Env, 6);
    v23.T.Type = 3;
    v23.NV.NumberValue = v4[29];
    Scaleform::GFx::AS2::Value::ToString(&v23, &v16, fn->Env, 6);
    v20.T.Type = 3;
    v20.NV.NumberValue = v4[30];
    Scaleform::GFx::AS2::Value::ToString(&v20, &v16, fn->Env, 6);
    v22.T.Type = 3;
    v22.NV.NumberValue = v4[31];
    Scaleform::GFx::AS2::Value::ToString(&v22, &v17, fn->Env, 6);
    Scaleform::StringBuffer::StringBuffer(&v10, Scaleform::Memory::pGlobalHeap);
    Scaleform::StringBuffer::AppendString(&v10, "(redMultiplier=", -1i64);
    Scaleform::StringBuffer::AppendString(&v10, result.pNode->pData, -1i64);
    Scaleform::StringBuffer::AppendString(&v10, ", greenMultiplier=", -1i64);
    Scaleform::StringBuffer::AppendString(&v10, v12.pNode->pData, -1i64);
    Scaleform::StringBuffer::AppendString(&v10, ", blueMultiplier=", -1i64);
    Scaleform::StringBuffer::AppendString(&v10, v13.pNode->pData, -1i64);
    Scaleform::StringBuffer::AppendString(&v10, ", alphaMultiplier=", -1i64);
    Scaleform::StringBuffer::AppendString(&v10, v14.pNode->pData, -1i64);
    Scaleform::StringBuffer::AppendString(&v10, ", redOffset=", -1i64);
    Scaleform::StringBuffer::AppendString(&v10, v15.pNode->pData, -1i64);
    Scaleform::StringBuffer::AppendString(&v10, ", greenOffset=", -1i64);
    Scaleform::StringBuffer::AppendString(&v10, v16.pNode->pData, -1i64);
    Scaleform::StringBuffer::AppendString(&v10, ", blueOffset=", -1i64);
    Scaleform::StringBuffer::AppendString(&v10, v16.pNode->pData, -1i64);
    Scaleform::StringBuffer::AppendString(&v10, ", alphaOffset=", -1i64);
    Scaleform::StringBuffer::AppendString(&v10, v17.pNode->pData, -1i64);
    Scaleform::StringBuffer::AppendString(&v10, ")", -1i64);
    pData = &customCaption;
    if ( v10.pData )
      pData = v10.pData;
    v6 = Scaleform::GFx::AS2::Environment::CreateString(fn->Env, &retaddr, pData, v10.Size);
    v7 = fn->Result;
    if ( v7->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(v7);
    v7->T.Type = 5;
    pNode = v6->pNode;
    v7->NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)v6->pNode;
    ++pNode->RefCount;
    if ( retaddr.pNode->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(retaddr.pNode);
    Scaleform::ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayDataBase<int,Scaleform::AllocatorGH<int,2>,Scaleform::ArrayDefaultPolicy> *)&v10);
    `eh vector destructor iterator(&result, 8ui64, 8, (void (__fastcall *)(void *))Scaleform::GFx::ASString::~ASString);
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      fn->Env,
      "Error: Null or invalid this is used for a method of %s class.\n",
      "ColorTransform");
  }
}

// File Line: 324
// RVA: 0x6F9110
void __fastcall Scaleform::GFx::AS2::ColorTransformCtorFunction::GlobalCtor(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rbx
  Scaleform::GFx::AS2::Value *v4; // rsi
  Scaleform::GFx::AS2::ObjectInterface *v5; // rbx
  unsigned int FirstArgBottomIndex; // r10d
  Scaleform::GFx::AS2::Environment *Env; // rdx
  Scaleform::GFx::AS2::Value *v8; // r9
  float v9; // xmm1_4
  unsigned int v10; // r10d
  Scaleform::GFx::AS2::Environment *v11; // rdx
  Scaleform::GFx::AS2::Value *v12; // r9
  float v13; // xmm1_4
  unsigned int v14; // r10d
  Scaleform::GFx::AS2::Environment *v15; // rdx
  Scaleform::GFx::AS2::Value *v16; // r9
  float v17; // xmm1_4
  unsigned int v18; // r10d
  Scaleform::GFx::AS2::Environment *v19; // rdx
  Scaleform::GFx::AS2::Value *v20; // r9
  float v21; // xmm1_4
  unsigned int v22; // r10d
  Scaleform::GFx::AS2::Environment *v23; // rdx
  Scaleform::GFx::AS2::Value *v24; // r9
  float v25; // xmm1_4
  unsigned int v26; // r10d
  Scaleform::GFx::AS2::Environment *v27; // rdx
  Scaleform::GFx::AS2::Value *v28; // r9
  float v29; // xmm1_4
  unsigned int v30; // r10d
  Scaleform::GFx::AS2::Environment *v31; // rdx
  Scaleform::GFx::AS2::Value *v32; // r9
  float v33; // xmm1_4
  unsigned int v34; // r9d
  Scaleform::GFx::AS2::Environment *v35; // rdx
  float v36; // xmm1_4
  int pObject; // eax

  ThisPtr = fn->ThisPtr;
  if ( ThisPtr
    && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(ThisPtr) == 18 )
  {
    v3 = fn->ThisPtr;
    v4 = 0i64;
    if ( v3 )
    {
      v5 = v3 - 2;
      if ( v5 )
        LODWORD(v5[1].pProto.pObject) = (LODWORD(v5[1].pProto.pObject) + 1) & 0x8FFFFFFF;
    }
    else
    {
      v5 = 0i64;
    }
    Scaleform::GFx::AS2::Value::SetAsObject(fn->Result, (Scaleform::GFx::AS2::Object *)v5);
    if ( fn->NArgs > 7 )
    {
      FirstArgBottomIndex = fn->FirstArgBottomIndex;
      Env = fn->Env;
      v8 = 0i64;
      if ( FirstArgBottomIndex <= 32 * ((unsigned int)Env->Stack.Pages.Data.Size - 1)
                                + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
        v8 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
      v9 = Scaleform::GFx::AS2::Value::ToNumber(v8, Env);
      *(float *)&v5[6].vfptr = v9;
      v10 = fn->FirstArgBottomIndex - 1;
      v11 = fn->Env;
      v12 = 0i64;
      if ( v10 <= 32 * ((unsigned int)v11->Stack.Pages.Data.Size - 1)
                + (unsigned int)(v11->Stack.pCurrent - v11->Stack.pPageStart) )
        v12 = &v11->Stack.Pages.Data.Data[v10 >> 5]->Values[v10 & 0x1F];
      v13 = Scaleform::GFx::AS2::Value::ToNumber(v12, v11);
      *((float *)&v5[6].vfptr + 1) = v13;
      v14 = fn->FirstArgBottomIndex - 2;
      v15 = fn->Env;
      v16 = 0i64;
      if ( v14 <= 32 * ((unsigned int)v15->Stack.Pages.Data.Size - 1)
                + (unsigned int)(v15->Stack.pCurrent - v15->Stack.pPageStart) )
        v16 = &v15->Stack.Pages.Data.Data[v14 >> 5]->Values[v14 & 0x1F];
      v17 = Scaleform::GFx::AS2::Value::ToNumber(v16, v15);
      *(float *)&v5[6].pProto.pObject = v17;
      v18 = fn->FirstArgBottomIndex - 3;
      v19 = fn->Env;
      v20 = 0i64;
      if ( v18 <= 32 * ((unsigned int)v19->Stack.Pages.Data.Size - 1)
                + (unsigned int)(v19->Stack.pCurrent - v19->Stack.pPageStart) )
        v20 = &v19->Stack.Pages.Data.Data[v18 >> 5]->Values[v18 & 0x1F];
      v21 = Scaleform::GFx::AS2::Value::ToNumber(v20, v19);
      *((float *)&v5[6].pProto.pObject + 1) = v21;
      v22 = fn->FirstArgBottomIndex - 4;
      v23 = fn->Env;
      v24 = 0i64;
      if ( v22 <= 32 * ((unsigned int)v23->Stack.Pages.Data.Size - 1)
                + (unsigned int)(v23->Stack.pCurrent - v23->Stack.pPageStart) )
        v24 = &v23->Stack.Pages.Data.Data[v22 >> 5]->Values[v22 & 0x1F];
      v25 = Scaleform::GFx::AS2::Value::ToNumber(v24, v23);
      *(float *)&v5[7].vfptr = v25;
      v26 = fn->FirstArgBottomIndex - 5;
      v27 = fn->Env;
      v28 = 0i64;
      if ( v26 <= 32 * ((unsigned int)v27->Stack.Pages.Data.Size - 1)
                + (unsigned int)(v27->Stack.pCurrent - v27->Stack.pPageStart) )
        v28 = &v27->Stack.Pages.Data.Data[v26 >> 5]->Values[v26 & 0x1F];
      v29 = Scaleform::GFx::AS2::Value::ToNumber(v28, v27);
      *((float *)&v5[7].vfptr + 1) = v29;
      v30 = fn->FirstArgBottomIndex - 6;
      v31 = fn->Env;
      v32 = 0i64;
      if ( v30 <= 32 * ((unsigned int)v31->Stack.Pages.Data.Size - 1)
                + (unsigned int)(v31->Stack.pCurrent - v31->Stack.pPageStart) )
        v32 = &v31->Stack.Pages.Data.Data[v30 >> 5]->Values[v30 & 0x1F];
      v33 = Scaleform::GFx::AS2::Value::ToNumber(v32, v31);
      *(float *)&v5[7].pProto.pObject = v33;
      v34 = fn->FirstArgBottomIndex - 7;
      v35 = fn->Env;
      if ( v34 <= 32 * ((unsigned int)v35->Stack.Pages.Data.Size - 1)
                + (unsigned int)(v35->Stack.pCurrent - v35->Stack.pPageStart) )
        v4 = &v35->Stack.Pages.Data.Data[v34 >> 5]->Values[v34 & 0x1F];
      v36 = Scaleform::GFx::AS2::Value::ToNumber(v4, v35);
      *((float *)&v5[7].pProto.pObject + 1) = v36;
    }
    if ( v5 )
    {
      pObject = (int)v5[1].pProto.pObject;
      if ( (pObject & 0x3FFFFFF) != 0 )
      {
        LODWORD(v5[1].pProto.pObject) = pObject - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v5);
      }
    }
  }
}

// File Line: 346
// RVA: 0x6E04A0
void __fastcall Scaleform::GFx::AS2::ColorTransformCtorFunction::CreateNewObject(
        Scaleform::GFx::AS2::ColorTransformCtorFunction *this,
        Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::ColorTransformObject *v3; // rax

  v3 = (Scaleform::GFx::AS2::ColorTransformObject *)penv->StringContext.pContext->pHeap->vfptr->Alloc(
                                                      this,
                                                      128i64,
                                                      0i64);
  if ( v3 )
    Scaleform::GFx::AS2::ColorTransformObject::ColorTransformObject(v3, penv);
}

// File Line: 351
// RVA: 0x70D400
Scaleform::GFx::AS2::FunctionRef *__fastcall Scaleform::GFx::AS2::ColorTransformCtorFunction::Register(
        Scaleform::GFx::AS2::FunctionRef *result,
        Scaleform::GFx::AS2::GlobalContext *pgc)
{
  Scaleform::GFx::AS2::Object *v4; // rax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *pObject; // rcx
  Scaleform::GFx::AS2::FunctionObject *v6; // rbx
  Scaleform::GFx::AS2::Object *Prototype; // r15
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::ColorTransformProto *v9; // rbx
  Scaleform::GFx::AS2::Object *v10; // rax
  Scaleform::GFx::AS2::Object *v11; // rax
  Scaleform::GFx::AS2::Object *v12; // rbx
  Scaleform::GFx::ASStringNode *Function; // rax
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // rdx
  unsigned int v15; // eax
  Scaleform::GFx::AS2::ASStringContext psc; // [rsp+40h] [rbp-38h] BYREF
  Scaleform::GFx::AS2::Value v18; // [rsp+50h] [rbp-28h] BYREF
  Scaleform::Ptr<Scaleform::GFx::AS2::Object> objproto; // [rsp+B8h] [rbp+40h] BYREF
  Scaleform::MemoryHeap *pHeap; // [rsp+C0h] [rbp+48h]
  Scaleform::Ptr<Scaleform::GFx::AS2::Object> *p_objproto; // [rsp+C8h] [rbp+50h]

  psc.pContext = pgc;
  psc.SWFVersion = 8;
  pHeap = pgc->pHeap;
  v4 = (Scaleform::GFx::AS2::Object *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::FunctionRef *, __int64))pHeap->vfptr->Alloc)(
                                        result,
                                        104i64);
  v6 = (Scaleform::GFx::AS2::FunctionObject *)v4;
  p_objproto = (Scaleform::Ptr<Scaleform::GFx::AS2::Object> *)v4;
  if ( v4 )
  {
    Scaleform::GFx::AS2::Object::Object(v4, &psc);
    v6->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::FunctionObject::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
    v6->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::FunctionObject::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
    v6->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::CFunctionObject::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
    v6->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::CFunctionObject::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
    v6[1].Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)Scaleform::GFx::AS2::ColorTransformCtorFunction::GlobalCtor;
    Prototype = Scaleform::GFx::AS2::GlobalContext::GetPrototype(psc.pContext, ASBuiltin_Function);
    if ( !v6->pProto.pObject )
    {
      LOBYTE(objproto.pObject) = 3;
      v18.T.Type = 10;
      v6->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr->SetMemberRaw(
        &v6->Scaleform::GFx::AS2::ObjectInterface,
        &psc,
        (Scaleform::GFx::ASString *)&psc.pContext->pMovieRoot->pASMovieRoot.pObject[23].pMovieImpl,
        &v18,
        (Scaleform::GFx::AS2::PropFlags *)&objproto);
      if ( v18.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v18);
    }
    if ( Prototype )
      Prototype->RefCount = (Prototype->RefCount + 1) & 0x8FFFFFFF;
    pObject = v6->pProto.pObject;
    if ( pObject )
    {
      RefCount = pObject->RefCount;
      if ( (RefCount & 0x3FFFFFF) != 0 )
      {
        pObject->RefCount = RefCount - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pObject);
      }
    }
    v6->pProto.pObject = Prototype;
    v6->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::ColorTransformCtorFunction::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
    v6->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::ColorTransformCtorFunction::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  }
  else
  {
    v6 = 0i64;
  }
  result->Flags = 0;
  result->Function = v6;
  result->pLocalFrame = 0i64;
  objproto.pObject = (Scaleform::GFx::AS2::Object *)pgc->pHeap;
  v9 = (Scaleform::GFx::AS2::ColorTransformProto *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::RefCountBaseGC<323> *, __int64, _QWORD))objproto.pObject->vfptr[3].Finalize_GC)(
                                                     pObject,
                                                     192i64,
                                                     0i64);
  pHeap = (Scaleform::MemoryHeap *)v9;
  if ( v9 )
  {
    v10 = Scaleform::GFx::AS2::GlobalContext::GetPrototype(pgc, ASBuiltin_Object);
    Scaleform::GFx::AS2::ColorTransformProto::ColorTransformProto(v9, &psc, v10, result);
    v12 = v11;
  }
  else
  {
    v12 = 0i64;
  }
  pHeap = (Scaleform::MemoryHeap *)v12;
  p_objproto = &objproto;
  if ( v12 )
    v12->RefCount = (v12->RefCount + 1) & 0x8FFFFFFF;
  objproto.pObject = v12;
  Scaleform::GFx::AS2::GlobalContext::SetPrototype(
    pgc,
    ASBuiltin_ColorTransform,
    (Scaleform::Ptr<Scaleform::GFx::AS2::Object>)&objproto);
  v18.T.Type = 8;
  v18.V.FunctionValue.Flags = 0;
  Function = (Scaleform::GFx::ASStringNode *)result->Function;
  v18.V.pStringNode = Function;
  if ( Function )
  {
    ++Function->RefCount;
    Function->RefCount &= 0x8FFFFFFF;
  }
  v18.V.FunctionValue.pLocalFrame = 0i64;
  pLocalFrame = result->pLocalFrame;
  if ( pLocalFrame )
    Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(&v18.V.FunctionValue, pLocalFrame, result->Flags & 1);
  LOBYTE(objproto.pObject) = 0;
  pgc->FlashGeomPackage->vfptr->SetMemberRaw(
    &pgc->FlashGeomPackage->Scaleform::GFx::AS2::ObjectInterface,
    &psc,
    (Scaleform::GFx::ASString *)&pgc->pMovieRoot->pASMovieRoot.pObject[11],
    &v18,
    (Scaleform::GFx::AS2::PropFlags *)&objproto);
  if ( v18.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v18);
  if ( v12 )
  {
    v15 = v12->RefCount;
    if ( (v15 & 0x3FFFFFF) != 0 )
    {
      v12->RefCount = v15 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v12);
    }
  }
  return result;
}

