// File Line: 34
// RVA: 0x6ED6D0
void __fastcall Scaleform::GFx::AS2::GFxObject_GetColorTransformProperties(Scaleform::GFx::AS2::Environment *penv, Scaleform::GFx::AS2::Object *pobj, Scaleform::GFx::AS2::Value *params)
{
  Scaleform::GFx::AS2::Value *v3; // rsi
  Scaleform::GFx::AS2::ASStringContext *v4; // rbx
  char *v5; // rdi
  Scaleform::GFx::ASString *v6; // rax
  Scaleform::GFx::ASStringNode *v7; // rcx
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
  Scaleform::GFx::ASString result; // [rsp+40h] [rbp+8h]

  v3 = params;
  v4 = &penv->StringContext;
  v5 = (char *)&pobj->vfptr;
  v6 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(&penv->StringContext, &result, "redMultiplier");
  (*(void (__fastcall **)(char *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, signed __int64))(*(_QWORD *)v5 + 88i64))(
    v5,
    v4,
    v6,
    v3,
    -2i64);
  v7 = result.pNode;
  v8 = result.pNode->RefCount == 1;
  --v7->RefCount;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v7);
  v9 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v4, &result, "greenMultiplier");
  (*(void (__fastcall **)(char *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))(*(_QWORD *)v5 + 88i64))(
    v5,
    v4,
    v9,
    v3 + 1);
  v10 = result.pNode;
  v8 = result.pNode->RefCount == 1;
  --v10->RefCount;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v10);
  v11 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v4, &result, "blueMultiplier");
  (*(void (__fastcall **)(char *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))(*(_QWORD *)v5 + 88i64))(
    v5,
    v4,
    v11,
    v3 + 2);
  v12 = result.pNode;
  v8 = result.pNode->RefCount == 1;
  --v12->RefCount;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v12);
  v13 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v4, &result, "alphaMultiplier");
  (*(void (__fastcall **)(char *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))(*(_QWORD *)v5 + 88i64))(
    v5,
    v4,
    v13,
    v3 + 3);
  v14 = result.pNode;
  v8 = result.pNode->RefCount == 1;
  --v14->RefCount;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v14);
  v15 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v4, &result, "redOffset");
  (*(void (__fastcall **)(char *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))(*(_QWORD *)v5 + 88i64))(
    v5,
    v4,
    v15,
    v3 + 4);
  v16 = result.pNode;
  v8 = result.pNode->RefCount == 1;
  --v16->RefCount;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v16);
  v17 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v4, &result, "greenOffset");
  (*(void (__fastcall **)(char *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))(*(_QWORD *)v5 + 88i64))(
    v5,
    v4,
    v17,
    v3 + 5);
  v18 = result.pNode;
  v8 = result.pNode->RefCount == 1;
  --v18->RefCount;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v18);
  v19 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v4, &result, "blueOffset");
  (*(void (__fastcall **)(char *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))(*(_QWORD *)v5 + 88i64))(
    v5,
    v4,
    v19,
    v3 + 6);
  v20 = result.pNode;
  v8 = result.pNode->RefCount == 1;
  --v20->RefCount;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v20);
  v21 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v4, &result, "alphaOffset");
  (*(void (__fastcall **)(char *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))(*(_QWORD *)v5 + 88i64))(
    v5,
    v4,
    v21,
    v3 + 7);
  v22 = result.pNode;
  v8 = result.pNode->RefCount == 1;
  --v22->RefCount;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v22);
}

// File Line: 51
// RVA: 0x6C80E0
void __fastcall Scaleform::GFx::AS2::ColorTransformObject::ColorTransformObject(Scaleform::GFx::AS2::ColorTransformObject *this, Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::Environment *v2; // rbx
  Scaleform::GFx::AS2::ColorTransformObject *v3; // rsi
  Scaleform::GFx::AS2::Object *v4; // rax

  v2 = penv;
  v3 = this;
  Scaleform::GFx::AS2::Object::Object((Scaleform::GFx::AS2::Object *)&this->vfptr, penv);
  v3->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::ColorTransformObject::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
  v3->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::ColorTransformObject::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  Scaleform::Render::Cxform::Cxform(&v3->mColorTransform);
  v4 = Scaleform::GFx::AS2::GlobalContext::GetPrototype(v2->StringContext.pContext, ASBuiltin_ColorTransform);
  Scaleform::GFx::AS2::Object::Set__proto__((Scaleform::GFx::AS2::Object *)&v3->vfptr, &v2->StringContext, v4);
}

// File Line: 76
// RVA: 0x6F19A0
char __fastcall Scaleform::GFx::AS2::ColorTransformObject::GetMember(Scaleform::GFx::AS2::ColorTransformObject *this, Scaleform::GFx::AS2::Environment *penv, Scaleform::GFx::ASString *name, Scaleform::GFx::AS2::Value *val)
{
  Scaleform::GFx::AS2::Value *v4; // rsi
  Scaleform::GFx::ASString *v5; // r14
  Scaleform::GFx::AS2::Environment *v6; // r15
  float *v7; // rbx
  const char *v8; // rdi
  __int64 v10; // rcx
  char v11; // al
  float v12; // xmm7_4
  Scaleform::GFx::AS2::Value v; // [rsp+8h] [rbp-69h]
  __int64 v14; // [rsp+28h] [rbp-49h]
  char v15; // [rsp+30h] [rbp-41h]
  char v16; // [rsp+50h] [rbp-21h]
  char v17; // [rsp+70h] [rbp-1h]

  v14 = -2i64;
  v4 = val;
  v5 = name;
  v6 = penv;
  v7 = (float *)this;
  v8 = name->pNode->pData;
  if ( !strcmp(name->pNode->pData, "redMultiplier") )
  {
    v.T.Type = 3;
    v.NV.NumberValue = v7[16];
    Scaleform::GFx::AS2::Value::operator=(v4, &v, (__int64)v8);
    goto LABEL_3;
  }
  if ( !strcmp(v8, "greenMultiplier") )
  {
    v.T.Type = 3;
    v.NV.NumberValue = v7[17];
    Scaleform::GFx::AS2::Value::operator=(v4, &v, (__int64)v8);
    goto LABEL_3;
  }
  if ( !strcmp(v8, "blueMultiplier") )
  {
    v.T.Type = 3;
    v.NV.NumberValue = v7[18];
    Scaleform::GFx::AS2::Value::operator=(v4, &v, (__int64)v8);
    goto LABEL_3;
  }
  if ( !strcmp(v8, "alphaMultiplier") )
  {
    v.T.Type = 3;
    v.NV.NumberValue = v7[19];
    Scaleform::GFx::AS2::Value::operator=(v4, &v, (__int64)v8);
    goto LABEL_3;
  }
  if ( !strcmp(v8, "redOffset") )
  {
    v.T.Type = 3;
    v.NV.NumberValue = v7[20];
    Scaleform::GFx::AS2::Value::operator=(v4, &v, (__int64)v8);
    goto LABEL_3;
  }
  if ( !strcmp(v8, "greenOffset") )
  {
    v.T.Type = 3;
    v.NV.NumberValue = v7[21];
    Scaleform::GFx::AS2::Value::operator=(v4, &v, (__int64)v8);
    goto LABEL_3;
  }
  if ( !strcmp(v8, "blueOffset") )
  {
    v.T.Type = 3;
    v.NV.NumberValue = v7[22];
    Scaleform::GFx::AS2::Value::operator=(v4, &v, (__int64)v8);
    goto LABEL_3;
  }
  if ( !strcmp(v8, "alphaOffset") )
  {
    v.T.Type = 3;
    v.NV.NumberValue = v7[23];
    Scaleform::GFx::AS2::Value::operator=(v4, &v, (__int64)v8);
LABEL_3:
    if ( v.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v);
    return 1;
  }
  v10 = 0i64;
  do
  {
    v11 = v8[v10++];
    if ( v11 != aRgb[v10 - 1] )
      return (*(__int64 (__fastcall **)(float *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))(*(_QWORD *)v7 + 88i64))(
               v7,
               &v6->StringContext,
               v5,
               v4);
  }
  while ( v10 != 4 );
  v15 = 0;
  v16 = 0;
  v17 = 0;
  Scaleform::GFx::NumberUtil::IsNaN(v7[20]);
  v12 = v7[21];
  if ( Scaleform::GFx::NumberUtil::IsNaN(v12) )
    v12 = 0.0;
  Scaleform::GFx::NumberUtil::IsNaN(v7[22]);
  Scaleform::GFx::AS2::Value::operator=(v4, &v, (unsigned int)(signed int)v12);
  if ( v.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v);
  return 1;
}

// File Line: 134
// RVA: 0x717380
bool __fastcall Scaleform::GFx::AS2::ColorTransformObject::SetMember(Scaleform::GFx::AS2::ColorTransformObject *this, Scaleform::GFx::AS2::Environment *penv, Scaleform::GFx::ASString *name, Scaleform::GFx::AS2::Value *val, Scaleform::GFx::AS2::PropFlags *flags)
{
  Scaleform::GFx::AS2::Environment *v5; // rbp
  Scaleform::GFx::AS2::ColorTransformObject *v6; // rbx
  const char *v7; // rdi
  Scaleform::GFx::AS2::Value *v8; // rsi
  Scaleform::GFx::ASString *v9; // r15
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
  signed int v27; // er14
  __int64 v28; // rcx
  char v29; // al
  signed int v30; // edi
  signed int v31; // er15
  long double v32; // xmm0_8
  long double v33; // xmm0_8

  v5 = penv;
  v6 = this;
  v7 = name->pNode->pData;
  v8 = val;
  v9 = name;
  if ( !strcmp(name->pNode->pData, "redMultiplier") )
  {
    v10 = Scaleform::GFx::AS2::Value::ToNumber(v8, v5);
    result = 1;
    v12 = v10;
    *(float *)&v6->ResolveHandler.pLocalFrame = v12;
  }
  else if ( !strcmp(v7, "greenMultiplier") )
  {
    v13 = Scaleform::GFx::AS2::Value::ToNumber(v8, v5);
    result = 1;
    v14 = v13;
    *((float *)&v6->ResolveHandler.pLocalFrame + 1) = v14;
  }
  else if ( !strcmp(v7, "blueMultiplier") )
  {
    v15 = Scaleform::GFx::AS2::Value::ToNumber(v8, v5);
    result = 1;
    v16 = v15;
    *(float *)&v6->ResolveHandler.Flags = v16;
  }
  else if ( !strcmp(v7, "alphaMultiplier") )
  {
    v17 = Scaleform::GFx::AS2::Value::ToNumber(v8, v5);
    result = 1;
    v18 = v17;
    *((float *)&v6->ResolveHandler.Flags + 1) = v18;
  }
  else if ( !strcmp(v7, "redOffset") )
  {
    v19 = Scaleform::GFx::AS2::Value::ToNumber(v8, v5);
    result = 1;
    v20 = v19;
    *(float *)&v6->pWatchpoints = v20;
  }
  else if ( !strcmp(v7, "greenOffset") )
  {
    v21 = Scaleform::GFx::AS2::Value::ToNumber(v8, v5);
    result = 1;
    v22 = v21;
    *((float *)&v6->pWatchpoints + 1) = v22;
  }
  else if ( !strcmp(v7, "blueOffset") )
  {
    v23 = Scaleform::GFx::AS2::Value::ToNumber(v8, v5);
    result = 1;
    v24 = v23;
    *(float *)&v6->ArePropertiesSet = v24;
  }
  else if ( !strcmp(v7, "alphaOffset") )
  {
    v25 = Scaleform::GFx::AS2::Value::ToNumber(v8, v5);
    result = 1;
    v26 = v25;
    *(float *)(&v6->IsListenerSet + 3) = v26;
  }
  else
  {
    v27 = 0;
    v28 = 0i64;
    do
    {
      v29 = v7[v28++];
      if ( v29 != aRgb[v28 - 1] )
        return Scaleform::GFx::AS2::Object::SetMember((Scaleform::GFx::AS2::Object *)&v6->vfptr, v5, v9, v8, flags);
    }
    while ( v28 != 4 );
    v6->ResolveHandler.pLocalFrame = 0i64;
    *(_DWORD *)&v6->ResolveHandler.Flags = 0;
    v30 = 0;
    v31 = 0;
    v32 = Scaleform::GFx::AS2::Value::ToNumber(v8, v5);
    if ( !Scaleform::GFx::NumberUtil::IsNaN(v32) )
    {
      v33 = Scaleform::GFx::AS2::Value::ToNumber(v8, v5);
      v31 = (unsigned __int8)(signed int)v33;
      v27 = (unsigned __int8)((unsigned int)(signed int)v33 >> 16);
      v30 = (unsigned __int8)((unsigned __int16)(signed int)v33 >> 8);
    }
    *(float *)&v6->pWatchpoints = (float)v27;
    *((float *)&v6->pWatchpoints + 1) = (float)v30;
    result = 1;
    *(float *)&v6->ArePropertiesSet = (float)v31;
  }
  return result;
}

// File Line: 217
// RVA: 0x6C8160
void __fastcall Scaleform::GFx::AS2::ColorTransformProto::ColorTransformProto(Scaleform::GFx::AS2::ColorTransformProto *this, Scaleform::GFx::AS2::ASStringContext *psc, Scaleform::GFx::AS2::Object *pprototype, Scaleform::GFx::AS2::FunctionRef *constructor)
{
  Scaleform::GFx::AS2::ASStringContext *v4; // rbx
  Scaleform::GFx::AS2::ColorTransformProto *v5; // rsi
  Scaleform::GFx::ASString *v6; // rax
  Scaleform::GFx::ASStringNode *v7; // rcx
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
  Scaleform::GFx::AS2::PropFlags flags; // [rsp+30h] [rbp-40h]
  Scaleform::GFx::ASString result; // [rsp+38h] [rbp-38h]
  __int64 v27; // [rsp+40h] [rbp-30h]
  Scaleform::GFx::AS2::Value val; // [rsp+48h] [rbp-28h]

  v27 = -2i64;
  v4 = psc;
  v5 = this;
  Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::ColorTransformObject,Scaleform::GFx::AS2::Environment>::Prototype<Scaleform::GFx::AS2::ColorTransformObject,Scaleform::GFx::AS2::Environment>(
    (Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::ColorTransformObject,Scaleform::GFx::AS2::Environment> *)&this->vfptr,
    psc,
    pprototype,
    constructor);
  v5->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::ColorTransformProto::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
  v5->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::ColorTransformProto::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  v5->vfptr = (Scaleform::GFx::AS2::GASPrototypeBaseVtbl *)&Scaleform::GFx::AS2::ColorTransformProto::`vftable';
  flags.Flags = 6;
  Scaleform::GFx::AS2::GASPrototypeBase::InitFunctionMembers(
    (Scaleform::GFx::AS2::GASPrototypeBase *)&v5->vfptr,
    (Scaleform::GFx::AS2::Object *)&v5->vfptr,
    v4,
    Scaleform::GFx::AS2::ColorTransformProto::FunctionTable,
    &flags);
  flags.Flags = 2;
  val.T.Type = 4;
  val.NV.Int32Value = 0;
  v6 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v4, &result, "redMultiplier");
  Scaleform::GFx::AS2::Object::SetMemberRaw((Scaleform::GFx::AS2::Object *)&v5->vfptr, v4, v6, &val, &flags);
  v7 = result.pNode;
  v8 = result.pNode->RefCount == 1;
  --v7->RefCount;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v7);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  flags.Flags = 2;
  val.T.Type = 4;
  val.NV.Int32Value = 0;
  v9 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v4, &result, "greenMultiplier");
  Scaleform::GFx::AS2::Object::SetMemberRaw((Scaleform::GFx::AS2::Object *)&v5->vfptr, v4, v9, &val, &flags);
  v10 = result.pNode;
  v8 = result.pNode->RefCount == 1;
  --v10->RefCount;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v10);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  flags.Flags = 2;
  val.T.Type = 4;
  val.NV.Int32Value = 0;
  v11 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v4, &result, "blueMultiplier");
  Scaleform::GFx::AS2::Object::SetMemberRaw((Scaleform::GFx::AS2::Object *)&v5->vfptr, v4, v11, &val, &flags);
  v12 = result.pNode;
  v8 = result.pNode->RefCount == 1;
  --v12->RefCount;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v12);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  flags.Flags = 2;
  val.T.Type = 4;
  val.NV.Int32Value = 0;
  v13 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v4, &result, "alphaMultiplier");
  Scaleform::GFx::AS2::Object::SetMemberRaw((Scaleform::GFx::AS2::Object *)&v5->vfptr, v4, v13, &val, &flags);
  v14 = result.pNode;
  v8 = result.pNode->RefCount == 1;
  --v14->RefCount;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v14);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  flags.Flags = 2;
  val.T.Type = 4;
  val.NV.Int32Value = 0;
  v15 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v4, &result, "redOffset");
  Scaleform::GFx::AS2::Object::SetMemberRaw((Scaleform::GFx::AS2::Object *)&v5->vfptr, v4, v15, &val, &flags);
  v16 = result.pNode;
  v8 = result.pNode->RefCount == 1;
  --v16->RefCount;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v16);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  flags.Flags = 2;
  val.T.Type = 4;
  val.NV.Int32Value = 0;
  v17 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v4, &result, "greenOffset");
  Scaleform::GFx::AS2::Object::SetMemberRaw((Scaleform::GFx::AS2::Object *)&v5->vfptr, v4, v17, &val, &flags);
  v18 = result.pNode;
  v8 = result.pNode->RefCount == 1;
  --v18->RefCount;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v18);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  flags.Flags = 2;
  val.T.Type = 4;
  val.NV.Int32Value = 0;
  v19 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v4, &result, "blueOffset");
  Scaleform::GFx::AS2::Object::SetMemberRaw((Scaleform::GFx::AS2::Object *)&v5->vfptr, v4, v19, &val, &flags);
  v20 = result.pNode;
  v8 = result.pNode->RefCount == 1;
  --v20->RefCount;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v20);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  flags.Flags = 2;
  val.T.Type = 4;
  val.NV.Int32Value = 0;
  v21 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v4, &result, "alphaOffset");
  Scaleform::GFx::AS2::Object::SetMemberRaw((Scaleform::GFx::AS2::Object *)&v5->vfptr, v4, v21, &val, &flags);
  v22 = result.pNode;
  v8 = result.pNode->RefCount == 1;
  --v22->RefCount;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v22);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  flags.Flags = 2;
  val.T.Type = 4;
  val.NV.Int32Value = 0;
  v23 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v4, &result, "rgb");
  Scaleform::GFx::AS2::Object::SetMemberRaw((Scaleform::GFx::AS2::Object *)&v5->vfptr, v4, v23, &val, &flags);
  v24 = result.pNode;
  v8 = result.pNode->RefCount == 1;
  --v24->RefCount;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v24);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
}

// File Line: 238
// RVA: 0x6B2550
void __fastcall Scaleform::GFx::AS2::ColorTransformProto::Concat(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rbx
  unsigned int v2; // er10
  Scaleform::GFx::AS2::Environment *v3; // r9
  Scaleform::Render::Cxform *v4; // rsi
  Scaleform::GFx::AS2::Value *v5; // rcx
  Scaleform::GFx::AS2::Object *v6; // rdi
  Scaleform::GFx::AS2::ObjectInterface *v7; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v8; // rax
  float v9; // xmm1_4
  float v10; // xmm1_4
  float v11; // xmm1_4
  float v12; // xmm1_4
  float v13; // xmm1_4
  float v14; // xmm1_4
  float v15; // xmm1_4
  float v16; // xmm1_4
  Scaleform::Render::Cxform c; // [rsp+30h] [rbp-138h]
  __int64 v18; // [rsp+50h] [rbp-118h]
  char ptr; // [rsp+60h] [rbp-108h]
  Scaleform::GFx::AS2::Value v20; // [rsp+80h] [rbp-E8h]
  Scaleform::GFx::AS2::Value v21; // [rsp+A0h] [rbp-C8h]
  Scaleform::GFx::AS2::Value v22; // [rsp+C0h] [rbp-A8h]
  Scaleform::GFx::AS2::Value v23; // [rsp+E0h] [rbp-88h]
  Scaleform::GFx::AS2::Value v24; // [rsp+100h] [rbp-68h]
  Scaleform::GFx::AS2::Value v25; // [rsp+120h] [rbp-48h]
  Scaleform::GFx::AS2::Value v26; // [rsp+140h] [rbp-28h]

  v18 = -2i64;
  v1 = fn;
  if ( fn->NArgs > 0 )
  {
    v2 = fn->FirstArgBottomIndex;
    v3 = fn->Env;
    v4 = 0i64;
    v5 = 0i64;
    if ( v2 <= 32 * ((unsigned int)v3->Stack.Pages.Data.Size - 1)
             + (unsigned int)((_QWORD)((char *)v3->Stack.pCurrent - (char *)v3->Stack.pPageStart) >> 5) )
      v5 = &v3->Stack.Pages.Data.Data[v2 >> 5]->Values[v2 & 0x1F];
    v6 = Scaleform::GFx::AS2::Value::ToObject(v5, v3);
    if ( v6 )
    {
      v7 = v1->ThisPtr;
      if ( v7 && (*(unsigned int (**)(void))&v7->vfptr->gap8[8])() == 18 )
      {
        v8 = v1->ThisPtr;
        if ( v8 )
          v4 = (Scaleform::Render::Cxform *)&v8[-2];
        if ( (*(unsigned int (**)(void))&v6->vfptr->gap8[8])() == 18 )
        {
          Scaleform::Render::Cxform::Prepend(v4 + 3, (Scaleform::Render::Cxform *)&v6[1]);
        }
        else
        {
          `eh vector constructor iterator'(
            &ptr,
            0x20ui64,
            8,
            (void (__fastcall *)(void *))Scaleform::GFx::AS2::Value::Value);
          Scaleform::GFx::AS2::GFxObject_GetColorTransformProperties(v1->Env, v6, (Scaleform::GFx::AS2::Value *)&ptr);
          Scaleform::Render::Cxform::Cxform(&c);
          v9 = Scaleform::GFx::AS2::Value::ToNumber((Scaleform::GFx::AS2::Value *)&ptr, v1->Env);
          c.M[0][0] = v9;
          v10 = Scaleform::GFx::AS2::Value::ToNumber(&v20, v1->Env);
          c.M[0][1] = v10;
          v11 = Scaleform::GFx::AS2::Value::ToNumber(&v21, v1->Env);
          c.M[0][2] = v11;
          v12 = Scaleform::GFx::AS2::Value::ToNumber(&v22, v1->Env);
          c.M[0][3] = v12;
          v13 = Scaleform::GFx::AS2::Value::ToNumber(&v23, v1->Env);
          c.M[1][0] = v13;
          v14 = Scaleform::GFx::AS2::Value::ToNumber(&v24, v1->Env);
          c.M[1][1] = v14;
          v15 = Scaleform::GFx::AS2::Value::ToNumber(&v25, v1->Env);
          c.M[1][2] = v15;
          v16 = Scaleform::GFx::AS2::Value::ToNumber(&v26, v1->Env);
          c.M[1][3] = v16;
          Scaleform::Render::Cxform::Prepend(v4 + 3, &c);
          `eh vector destructor iterator'(
            &ptr,
            0x20ui64,
            8,
            (void (__fastcall *)(void *))Scaleform::GFx::AS2::Value::~Value);
        }
      }
      else
      {
        Scaleform::GFx::AS2::Environment::LogScriptError(
          v1->Env,
          "Error: Null or invalid 'this' is used for a method of %s class.\n",
          "ColorTransform");
      }
    }
  }
}

// File Line: 280
// RVA: 0x6B27B0
void __fastcall Scaleform::GFx::AS2::ColorTransformProto::ToString(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rbx
  Scaleform::GFx::AS2::ObjectInterface *v2; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rax
  float *v4; // rdi
  char *v5; // r8
  Scaleform::GFx::ASString *v6; // rdi
  Scaleform::GFx::AS2::Value *v7; // rbx
  Scaleform::GFx::ASStringNode *v8; // rax
  bool v9; // zf
  Scaleform::StringBuffer v10; // [rsp+20h] [rbp-D8h]
  Scaleform::GFx::ASString result; // [rsp+50h] [rbp-A8h]
  Scaleform::GFx::ASString v12; // [rsp+58h] [rbp-A0h]
  Scaleform::GFx::ASString v13; // [rsp+60h] [rbp-98h]
  Scaleform::GFx::ASString v14; // [rsp+68h] [rbp-90h]
  Scaleform::GFx::ASString v15; // [rsp+70h] [rbp-88h]
  Scaleform::GFx::ASString v16; // [rsp+78h] [rbp-80h]
  Scaleform::GFx::ASString v17; // [rsp+80h] [rbp-78h]
  __int64 v18; // [rsp+88h] [rbp-70h]
  Scaleform::GFx::AS2::Value v19; // [rsp+90h] [rbp-68h]
  Scaleform::GFx::AS2::Value v20; // [rsp+B0h] [rbp-48h]
  Scaleform::GFx::AS2::Value v21; // [rsp+D0h] [rbp-28h]
  Scaleform::GFx::AS2::Value v22; // [rsp+F0h] [rbp-8h]
  Scaleform::GFx::AS2::Value v23; // [rsp+110h] [rbp+18h]
  Scaleform::GFx::AS2::Value ptr; // [rsp+130h] [rbp+38h]
  Scaleform::GFx::AS2::Value v25; // [rsp+150h] [rbp+58h]
  Scaleform::GFx::AS2::Value v26; // [rsp+170h] [rbp+78h]
  Scaleform::GFx::ASStringNode *retaddr; // [rsp+1A8h] [rbp+B0h]

  v18 = -2i64;
  v1 = fn;
  v2 = fn->ThisPtr;
  if ( v2 && (*(unsigned int (**)(void))&v2->vfptr->gap8[8])() == 18 )
  {
    v3 = v1->ThisPtr;
    if ( v3 )
      v4 = (float *)&v3[-2];
    else
      v4 = 0i64;
    v25.T.Type = 3;
    v25.NV.NumberValue = v4[24];
    Scaleform::GFx::AS2::Value::ToString(&v25, &result, v1->Env, 6);
    ptr.T.Type = 3;
    ptr.NV.NumberValue = v4[25];
    Scaleform::GFx::AS2::Value::ToString(&ptr, &v12, v1->Env, 6);
    v26.T.Type = 3;
    v26.NV.NumberValue = v4[26];
    Scaleform::GFx::AS2::Value::ToString(&v26, &v13, v1->Env, 6);
    v21.T.Type = 3;
    v21.NV.NumberValue = v4[27];
    Scaleform::GFx::AS2::Value::ToString(&v21, &v14, v1->Env, 6);
    v19.T.Type = 3;
    v19.NV.NumberValue = v4[28];
    Scaleform::GFx::AS2::Value::ToString(&v19, &v15, v1->Env, 6);
    v23.T.Type = 3;
    v23.NV.NumberValue = v4[29];
    Scaleform::GFx::AS2::Value::ToString(&v23, &v16, v1->Env, 6);
    v20.T.Type = 3;
    v20.NV.NumberValue = v4[30];
    Scaleform::GFx::AS2::Value::ToString(&v20, &v16, v1->Env, 6);
    v22.T.Type = 3;
    v22.NV.NumberValue = v4[31];
    Scaleform::GFx::AS2::Value::ToString(&v22, &v17, v1->Env, 6);
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
    v5 = &customWorldMapCaption;
    if ( v10.pData )
      v5 = v10.pData;
    v6 = Scaleform::GFx::AS2::Environment::CreateString(v1->Env, (Scaleform::GFx::ASString *)&retaddr, v5, v10.Size);
    v7 = v1->Result;
    if ( v7->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(v7);
    v7->T.Type = 5;
    v8 = v6->pNode;
    v7->NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)v6->pNode;
    ++v8->RefCount;
    v9 = retaddr->RefCount-- == 1;
    if ( v9 )
      Scaleform::GFx::ASStringNode::ReleaseNode(retaddr);
    Scaleform::ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayDataBase<int,Scaleform::AllocatorGH<int,2>,Scaleform::ArrayDefaultPolicy> *)&v10);
    `eh vector destructor iterator'(&result, 8ui64, 8, (void (__fastcall *)(void *))Scaleform::GFx::ASString::~ASString);
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      v1->Env,
      "Error: Null or invalid 'this' is used for a method of %s class.\n",
      "ColorTransform");
  }
}

// File Line: 324
// RVA: 0x6F9110
void __fastcall Scaleform::GFx::AS2::ColorTransformCtorFunction::GlobalCtor(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rdi
  Scaleform::GFx::AS2::ObjectInterface *v2; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rbx
  Scaleform::GFx::AS2::Value *v4; // rsi
  signed __int64 v5; // rbx
  unsigned int v6; // er10
  Scaleform::GFx::AS2::Environment *v7; // rdx
  Scaleform::GFx::AS2::Value *v8; // r9
  float v9; // xmm1_4
  unsigned int v10; // er10
  Scaleform::GFx::AS2::Environment *v11; // rdx
  Scaleform::GFx::AS2::Value *v12; // r9
  float v13; // xmm1_4
  unsigned int v14; // er10
  Scaleform::GFx::AS2::Environment *v15; // rdx
  Scaleform::GFx::AS2::Value *v16; // r9
  float v17; // xmm1_4
  unsigned int v18; // er10
  Scaleform::GFx::AS2::Environment *v19; // rdx
  Scaleform::GFx::AS2::Value *v20; // r9
  float v21; // xmm1_4
  unsigned int v22; // er10
  Scaleform::GFx::AS2::Environment *v23; // rdx
  Scaleform::GFx::AS2::Value *v24; // r9
  float v25; // xmm1_4
  unsigned int v26; // er10
  Scaleform::GFx::AS2::Environment *v27; // rdx
  Scaleform::GFx::AS2::Value *v28; // r9
  float v29; // xmm1_4
  unsigned int v30; // er10
  Scaleform::GFx::AS2::Environment *v31; // rdx
  Scaleform::GFx::AS2::Value *v32; // r9
  float v33; // xmm1_4
  unsigned int v34; // er9
  Scaleform::GFx::AS2::Environment *v35; // rdx
  float v36; // xmm1_4
  int v37; // eax

  v1 = fn;
  v2 = fn->ThisPtr;
  if ( v2 && (*(unsigned int (__cdecl **)(Scaleform::GFx::AS2::ObjectInterface *))&v2->vfptr->gap8[8])(v2) == 18 )
  {
    v3 = v1->ThisPtr;
    v4 = 0i64;
    if ( v3 )
    {
      v5 = (signed __int64)&v3[-2];
      if ( v5 )
        *(_DWORD *)(v5 + 24) = (*(_DWORD *)(v5 + 24) + 1) & 0x8FFFFFFF;
    }
    else
    {
      v5 = 0i64;
    }
    Scaleform::GFx::AS2::Value::SetAsObject(v1->Result, (Scaleform::GFx::AS2::Object *)v5);
    if ( v1->NArgs > 7 )
    {
      v6 = v1->FirstArgBottomIndex;
      v7 = v1->Env;
      v8 = 0i64;
      if ( v6 <= 32 * ((unsigned int)v7->Stack.Pages.Data.Size - 1)
               + (unsigned int)((_QWORD)((char *)v7->Stack.pCurrent - (char *)v7->Stack.pPageStart) >> 5) )
        v8 = &v7->Stack.Pages.Data.Data[v6 >> 5]->Values[v6 & 0x1F];
      v9 = Scaleform::GFx::AS2::Value::ToNumber(v8, v7);
      *(float *)(v5 + 96) = v9;
      v10 = v1->FirstArgBottomIndex - 1;
      v11 = v1->Env;
      v12 = 0i64;
      if ( v10 <= 32 * ((unsigned int)v11->Stack.Pages.Data.Size - 1)
                + (unsigned int)((_QWORD)((char *)v11->Stack.pCurrent - (char *)v11->Stack.pPageStart) >> 5) )
        v12 = &v11->Stack.Pages.Data.Data[v10 >> 5]->Values[v10 & 0x1F];
      v13 = Scaleform::GFx::AS2::Value::ToNumber(v12, v11);
      *(float *)(v5 + 100) = v13;
      v14 = v1->FirstArgBottomIndex - 2;
      v15 = v1->Env;
      v16 = 0i64;
      if ( v14 <= 32 * ((unsigned int)v15->Stack.Pages.Data.Size - 1)
                + (unsigned int)((_QWORD)((char *)v15->Stack.pCurrent - (char *)v15->Stack.pPageStart) >> 5) )
        v16 = &v15->Stack.Pages.Data.Data[v14 >> 5]->Values[v14 & 0x1F];
      v17 = Scaleform::GFx::AS2::Value::ToNumber(v16, v15);
      *(float *)(v5 + 104) = v17;
      v18 = v1->FirstArgBottomIndex - 3;
      v19 = v1->Env;
      v20 = 0i64;
      if ( v18 <= 32 * ((unsigned int)v19->Stack.Pages.Data.Size - 1)
                + (unsigned int)((_QWORD)((char *)v19->Stack.pCurrent - (char *)v19->Stack.pPageStart) >> 5) )
        v20 = &v19->Stack.Pages.Data.Data[v18 >> 5]->Values[v18 & 0x1F];
      v21 = Scaleform::GFx::AS2::Value::ToNumber(v20, v19);
      *(float *)(v5 + 108) = v21;
      v22 = v1->FirstArgBottomIndex - 4;
      v23 = v1->Env;
      v24 = 0i64;
      if ( v22 <= 32 * ((unsigned int)v23->Stack.Pages.Data.Size - 1)
                + (unsigned int)((_QWORD)((char *)v23->Stack.pCurrent - (char *)v23->Stack.pPageStart) >> 5) )
        v24 = &v23->Stack.Pages.Data.Data[v22 >> 5]->Values[v22 & 0x1F];
      v25 = Scaleform::GFx::AS2::Value::ToNumber(v24, v23);
      *(float *)(v5 + 112) = v25;
      v26 = v1->FirstArgBottomIndex - 5;
      v27 = v1->Env;
      v28 = 0i64;
      if ( v26 <= 32 * ((unsigned int)v27->Stack.Pages.Data.Size - 1)
                + (unsigned int)((_QWORD)((char *)v27->Stack.pCurrent - (char *)v27->Stack.pPageStart) >> 5) )
        v28 = &v27->Stack.Pages.Data.Data[v26 >> 5]->Values[v26 & 0x1F];
      v29 = Scaleform::GFx::AS2::Value::ToNumber(v28, v27);
      *(float *)(v5 + 116) = v29;
      v30 = v1->FirstArgBottomIndex - 6;
      v31 = v1->Env;
      v32 = 0i64;
      if ( v30 <= 32 * ((unsigned int)v31->Stack.Pages.Data.Size - 1)
                + (unsigned int)((_QWORD)((char *)v31->Stack.pCurrent - (char *)v31->Stack.pPageStart) >> 5) )
        v32 = &v31->Stack.Pages.Data.Data[v30 >> 5]->Values[v30 & 0x1F];
      v33 = Scaleform::GFx::AS2::Value::ToNumber(v32, v31);
      *(float *)(v5 + 120) = v33;
      v34 = v1->FirstArgBottomIndex - 7;
      v35 = v1->Env;
      if ( v34 <= 32 * ((unsigned int)v35->Stack.Pages.Data.Size - 1)
                + (unsigned int)((_QWORD)((char *)v35->Stack.pCurrent - (char *)v35->Stack.pPageStart) >> 5) )
        v4 = &v35->Stack.Pages.Data.Data[v34 >> 5]->Values[v34 & 0x1F];
      v36 = Scaleform::GFx::AS2::Value::ToNumber(v4, v35);
      *(float *)(v5 + 124) = v36;
    }
    if ( v5 )
    {
      v37 = *(_DWORD *)(v5 + 24);
      if ( v37 & 0x3FFFFFF )
      {
        *(_DWORD *)(v5 + 24) = v37 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v5);
      }
    }
  }
}

// File Line: 346
// RVA: 0x6E04A0
void __fastcall Scaleform::GFx::AS2::ColorTransformCtorFunction::CreateNewObject(Scaleform::GFx::AS2::ColorTransformCtorFunction *this, Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::Environment *v2; // rbx
  Scaleform::GFx::AS2::ColorTransformObject *v3; // rax

  v2 = penv;
  v3 = (Scaleform::GFx::AS2::ColorTransformObject *)penv->StringContext.pContext->pHeap->vfptr->Alloc(
                                                      (Scaleform::MemoryHeap *)this,
                                                      128ui64,
                                                      0i64);
  if ( v3 )
    Scaleform::GFx::AS2::ColorTransformObject::ColorTransformObject(v3, v2);
}

// File Line: 351
// RVA: 0x70D400
Scaleform::GFx::AS2::FunctionRef *__fastcall Scaleform::GFx::AS2::ColorTransformCtorFunction::Register(Scaleform::GFx::AS2::FunctionRef *result, Scaleform::GFx::AS2::GlobalContext *pgc)
{
  Scaleform::GFx::AS2::GlobalContext *v2; // rsi
  Scaleform::GFx::AS2::FunctionRef *v3; // rdi
  Scaleform::GFx::AS2::Object *v4; // rax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v5; // rcx
  Scaleform::GFx::AS2::FunctionObject *v6; // rbx
  Scaleform::GFx::AS2::Object *v7; // r15
  unsigned int v8; // eax
  Scaleform::GFx::AS2::ColorTransformProto *v9; // rbx
  Scaleform::GFx::AS2::Object *v10; // rax
  Scaleform::GFx::AS2::Object *v11; // rax
  Scaleform::GFx::AS2::Object *v12; // rbx
  Scaleform::GFx::ASStringNode *v13; // rax
  Scaleform::GFx::AS2::LocalFrame *v14; // rdx
  unsigned int v15; // eax
  Scaleform::GFx::AS2::ASStringContext psc; // [rsp+40h] [rbp-38h]
  Scaleform::GFx::AS2::Value v18; // [rsp+50h] [rbp-28h]
  Scaleform::Ptr<Scaleform::GFx::AS2::Object> objproto; // [rsp+B8h] [rbp+40h]
  Scaleform::MemoryHeap *v20; // [rsp+C0h] [rbp+48h]
  Scaleform::Ptr<Scaleform::GFx::AS2::Object> *v21; // [rsp+C8h] [rbp+50h]

  v2 = pgc;
  v3 = result;
  psc.pContext = pgc;
  psc.SWFVersion = 8;
  v20 = pgc->pHeap;
  v4 = (Scaleform::GFx::AS2::Object *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::FunctionRef *, signed __int64))v20->vfptr->Alloc)(
                                        result,
                                        104i64);
  v6 = (Scaleform::GFx::AS2::FunctionObject *)v4;
  v21 = (Scaleform::Ptr<Scaleform::GFx::AS2::Object> *)v4;
  if ( v4 )
  {
    Scaleform::GFx::AS2::Object::Object(v4, &psc);
    v6->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::FunctionObject::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
    v6->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::FunctionObject::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
    v6->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::CFunctionObject::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
    v6->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::CFunctionObject::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
    v6[1].vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)Scaleform::GFx::AS2::ColorTransformCtorFunction::GlobalCtor;
    v7 = Scaleform::GFx::AS2::GlobalContext::GetPrototype(psc.pContext, ASBuiltin_Function);
    if ( !v6->pProto.pObject )
    {
      LOBYTE(objproto.pObject) = 3;
      v18.T.Type = 10;
      v6->vfptr->SetMemberRaw(
        (Scaleform::GFx::AS2::ObjectInterface *)&v6->vfptr,
        &psc,
        (Scaleform::GFx::ASString *)&psc.pContext->pMovieRoot->pASMovieRoot.pObject[23].pMovieImpl,
        &v18,
        (Scaleform::GFx::AS2::PropFlags *)&objproto);
      if ( v18.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v18);
    }
    if ( v7 )
      v7->RefCount = (v7->RefCount + 1) & 0x8FFFFFFF;
    v5 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v6->pProto.pObject->vfptr;
    if ( v5 )
    {
      v8 = v5->RefCount;
      if ( v8 & 0x3FFFFFF )
      {
        v5->RefCount = v8 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v5);
      }
    }
    v6->pProto.pObject = v7;
    v6->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::ColorTransformCtorFunction::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
    v6->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::ColorTransformCtorFunction::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  }
  else
  {
    v6 = 0i64;
  }
  v3->Flags = 0;
  v3->Function = v6;
  v3->pLocalFrame = 0i64;
  objproto.pObject = (Scaleform::GFx::AS2::Object *)v2->pHeap;
  v9 = (Scaleform::GFx::AS2::ColorTransformProto *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::RefCountBaseGC<323> *, signed __int64, _QWORD))objproto.pObject->vfptr[3].Finalize_GC)(
                                                     v5,
                                                     192i64,
                                                     0i64);
  v20 = (Scaleform::MemoryHeap *)v9;
  if ( v9 )
  {
    v10 = Scaleform::GFx::AS2::GlobalContext::GetPrototype(v2, ASBuiltin_Object);
    Scaleform::GFx::AS2::ColorTransformProto::ColorTransformProto(v9, &psc, v10, v3);
    v12 = v11;
  }
  else
  {
    v12 = 0i64;
  }
  v20 = (Scaleform::MemoryHeap *)v12;
  v21 = &objproto;
  if ( v12 )
    v12->RefCount = (v12->RefCount + 1) & 0x8FFFFFFF;
  objproto.pObject = v12;
  Scaleform::GFx::AS2::GlobalContext::SetPrototype(
    v2,
    ASBuiltin_ColorTransform,
    (Scaleform::Ptr<Scaleform::GFx::AS2::Object>)&objproto);
  v18.T.Type = 8;
  v18.V.FunctionValue.Flags = 0;
  v13 = (Scaleform::GFx::ASStringNode *)v3->Function;
  v18.V.pStringNode = v13;
  if ( v13 )
  {
    ++v13->RefCount;
    v13->RefCount &= 0x8FFFFFFF;
  }
  v18.V.FunctionValue.pLocalFrame = 0i64;
  v14 = v3->pLocalFrame;
  if ( v14 )
    Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(
      (Scaleform::GFx::AS2::FunctionRefBase *)&v18.NV.8,
      v14,
      v3->Flags & 1);
  LOBYTE(objproto.pObject) = 0;
  v2->FlashGeomPackage->vfptr->SetMemberRaw(
    (Scaleform::GFx::AS2::ObjectInterface *)&v2->FlashGeomPackage->vfptr,
    &psc,
    (Scaleform::GFx::ASString *)&v2->pMovieRoot->pASMovieRoot.pObject[11],
    &v18,
    (Scaleform::GFx::AS2::PropFlags *)&objproto);
  if ( v18.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v18);
  if ( v12 )
  {
    v15 = v12->RefCount;
    if ( v15 & 0x3FFFFFF )
    {
      v12->RefCount = v15 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v12->vfptr);
    }
  }
  return v3;
}

