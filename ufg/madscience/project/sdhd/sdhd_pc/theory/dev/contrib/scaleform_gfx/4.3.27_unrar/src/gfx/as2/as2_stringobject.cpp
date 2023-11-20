// File Line: 29
// RVA: 0x6CBCF0
void __fastcall Scaleform::GFx::AS2::StringObject::StringObject(Scaleform::GFx::AS2::StringObject *this, Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::Environment *v2; // rbx
  Scaleform::GFx::AS2::StringObject *v3; // rsi
  Scaleform::GFx::ASStringNode *v4; // r8
  Scaleform::GFx::AS2::Object *v5; // rax

  v2 = penv;
  v3 = this;
  Scaleform::GFx::AS2::Object::Object((Scaleform::GFx::AS2::Object *)&this->vfptr, penv);
  v3->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::StringObject::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
  v3->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::StringObject::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  v4 = *(Scaleform::GFx::ASStringNode **)&v2->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[7].AVMVersion;
  v3->sValue.pNode = v4;
  ++v4->RefCount;
  v5 = Scaleform::GFx::AS2::GlobalContext::GetPrototype(v2->StringContext.pContext, ASBuiltin_String);
  v3->vfptr->Set__proto__((Scaleform::GFx::AS2::ObjectInterface *)&v3->vfptr, &v2->StringContext, v5);
}

// File Line: 45
// RVA: 0x6F6A30
Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *__fastcall Scaleform::GFx::AS2::StringObject::GetTextValue(Scaleform::GFx::AS2::StringObject *this, Scaleform::GFx::AS2::Environment *__formal)
{
  return this->ResolveHandler.pLocalFrame->vfptr;
}

// File Line: 50
// RVA: 0x6F3FE0
bool __fastcall Scaleform::GFx::AS2::StringObject::GetMemberRaw(Scaleform::GFx::AS2::StringObject *this, Scaleform::GFx::AS2::ASStringContext *psc, Scaleform::GFx::ASString *name, Scaleform::GFx::AS2::Value *val)
{
  Scaleform::GFx::AS2::Value *v4; // rbx
  Scaleform::GFx::ASString *v5; // rdi
  Scaleform::GFx::AS2::ASStringContext *v6; // r14
  Scaleform::GFx::ASMovieRootBase *v7; // rsi
  Scaleform::GFx::AS2::StringObject *v8; // rbp
  bool v9; // zf
  unsigned int v10; // edi

  v4 = val;
  v5 = name;
  v6 = psc;
  v7 = psc->pContext->pMovieRoot->pASMovieRoot.pObject;
  v8 = this;
  if ( psc->SWFVersion <= 6u )
  {
    if ( !name->pNode->pLower )
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(name->pNode);
    v9 = *(Scaleform::GFx::ASStringNode **)(*(_QWORD *)&v7[38].AVMVersion + 16i64) == v5->pNode->pLower;
  }
  else
  {
    v9 = *(Scaleform::GFx::ASStringNode **)&v7[38].AVMVersion == name->pNode;
  }
  if ( !v9 )
    return Scaleform::GFx::AS2::Object::GetMemberRaw((Scaleform::GFx::AS2::Object *)&v8->vfptr, v6, v5, v4) != 0;
  if ( !Scaleform::GFx::AS2::Object::GetMemberRaw((Scaleform::GFx::AS2::Object *)&v8->vfptr, v6, v5, v4)
    || v4->T.Type == 10 )
  {
    v10 = Scaleform::GFx::ASConstString::GetLength((Scaleform::GFx::ASConstString *)&v8->ResolveHandler.pLocalFrame);
    if ( v4->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(v4);
    v4->T.Type = 4;
    v4->NV.Int32Value = v10;
  }
  return 1;
}

// File Line: 66
// RVA: 0x71D190
void __fastcall Scaleform::GFx::AS2::StringObject::SetValue(Scaleform::GFx::AS2::StringObject *this, Scaleform::GFx::AS2::Environment *penv, Scaleform::GFx::AS2::Value *v)
{
  Scaleform::GFx::AS2::StringObject *v3; // rbx
  Scaleform::GFx::ASStringNode *v4; // rcx
  bool v5; // zf
  Scaleform::GFx::ASString result; // [rsp+40h] [rbp+8h]

  v3 = this;
  Scaleform::GFx::AS2::Value::ToString(v, &result, penv, -1);
  Scaleform::GFx::ASString::operator=(&v3->sValue, result.pNode->pData);
  v4 = result.pNode;
  v5 = result.pNode->RefCount == 1;
  --v4->RefCount;
  if ( v5 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v4);
}

// File Line: 72
// RVA: 0x6F7360
Scaleform::GFx::AS2::Value *__fastcall Scaleform::GFx::AS2::StringObject::GetValue(Scaleform::GFx::AS2::StringObject *this, Scaleform::GFx::AS2::Value *result)
{
  Scaleform::GFx::ASStringNode *v2; // rax

  result->T.Type = 5;
  v2 = this->sValue.pNode;
  result->V.pStringNode = v2;
  ++v2->RefCount;
  return result;
}

// File Line: 79
// RVA: 0x6AFC80
void __fastcall Scaleform::GFx::AS2::StringProto::StringCharAt(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rbx
  Scaleform::GFx::AS2::ObjectInterface *v2; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rax
  Scaleform::GFx::AS2::Value *v4; // r9
  signed __int64 v5; // rax
  Scaleform::GFx::ASConstString *v6; // rsi
  unsigned int v7; // er10
  Scaleform::GFx::AS2::Environment *v8; // rdx
  signed int v9; // edi
  unsigned int v10; // eax
  Scaleform::GFx::ASStringNode *v11; // rdi
  Scaleform::GFx::ASStringNode *v12; // rcx
  bool v13; // zf
  Scaleform::GFx::ASStringNode *v14; // rcx
  Scaleform::GFx::AS2::Value *v15; // rbx
  Scaleform::GFx::ASStringNode *v16; // rcx
  Scaleform::GFx::ASString v17; // [rsp+40h] [rbp+8h]
  Scaleform::GFx::ASString result; // [rsp+48h] [rbp+10h]

  v1 = fn;
  v2 = fn->ThisPtr;
  if ( v2 && (*(unsigned int (__cdecl **)(Scaleform::GFx::AS2::ObjectInterface *))&v2->vfptr->gap8[8])(v2) == 8 )
  {
    v3 = v1->ThisPtr;
    v4 = 0i64;
    if ( v3 )
      v5 = (signed __int64)&v3[-2];
    else
      v5 = 0i64;
    v6 = (Scaleform::GFx::ASConstString *)(v5 + 96);
    v17.pNode = *(Scaleform::GFx::ASStringNode **)&v1->Env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[7].AVMVersion;
    ++v17.pNode->RefCount;
    v7 = v1->FirstArgBottomIndex;
    v8 = v1->Env;
    if ( v7 <= 32 * ((unsigned int)v8->Stack.Pages.Data.Size - 1)
             + (unsigned int)((_QWORD)((char *)v8->Stack.pCurrent - (char *)v8->Stack.pPageStart) >> 5) )
      v4 = &v8->Stack.Pages.Data.Data[v7 >> 5]->Values[v7 & 0x1F];
    v9 = (signed int)Scaleform::GFx::AS2::Value::ToNumber(v4, v8);
    if ( v9 >= 0 && v9 < (signed int)Scaleform::GFx::ASConstString::GetLength(v6) )
    {
      v10 = Scaleform::GFx::ASConstString::GetCharAt(v6, v9);
      v11 = Scaleform::GFx::ASString::AppendChar(&v17, &result, v10)->pNode;
      ++v11->RefCount;
      v12 = v17.pNode;
      v13 = v17.pNode->RefCount == 1;
      --v12->RefCount;
      if ( v13 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v12);
      v17.pNode = v11;
      v14 = result.pNode;
      v13 = result.pNode->RefCount == 1;
      --v14->RefCount;
      if ( v13 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v14);
    }
    v15 = v1->Result;
    if ( v15->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(v15);
    v15->T.Type = 5;
    v15->NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)v17.pNode;
    ++v17.pNode->RefCount;
    v16 = v17.pNode;
    v13 = v17.pNode->RefCount == 1;
    --v16->RefCount;
    if ( v13 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v16);
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      v1->Env,
      "Error: Null or invalid this is used for a method of %s class.\n",
      "String");
  }
}

// File Line: 96
// RVA: 0x6AFFD0
void __fastcall Scaleform::GFx::AS2::StringProto::StringCharCodeAt(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rbx
  Scaleform::GFx::AS2::ObjectInterface *v2; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rax
  Scaleform::GFx::AS2::Value *v4; // r9
  signed __int64 v5; // rax
  Scaleform::GFx::ASConstString *v6; // rsi
  Scaleform::GFx::AS2::Environment *v7; // rdx
  unsigned __int64 v8; // r8
  signed int v9; // edi
  signed int v10; // eax
  double v11; // xmm0_8
  Scaleform::GFx::AS2::Value *v12; // rbx

  v1 = fn;
  v2 = fn->ThisPtr;
  if ( v2 && (*(unsigned int (**)(void))&v2->vfptr->gap8[8])() == 8 )
  {
    v3 = v1->ThisPtr;
    v4 = 0i64;
    if ( v3 )
      v5 = (signed __int64)&v3[-2];
    else
      v5 = 0i64;
    v6 = (Scaleform::GFx::ASConstString *)(v5 + 96);
    if ( v1->NArgs < 1 )
      goto LABEL_18;
    v7 = v1->Env;
    v8 = (unsigned int)v1->FirstArgBottomIndex;
    if ( (unsigned int)v8 <= 32 * (LODWORD(v7->Stack.Pages.Data.Size) - 1)
                           + (unsigned int)((_QWORD)((char *)v7->Stack.pCurrent - (char *)v7->Stack.pPageStart) >> 5) )
      v4 = &v7->Stack.Pages.Data.Data[v8 >> 5]->Values[v1->FirstArgBottomIndex & 0x1F];
    v9 = (signed int)Scaleform::GFx::AS2::Value::ToNumber(v4, v7);
    if ( v9 < 0 || v9 >= (signed int)Scaleform::GFx::ASConstString::GetLength(v6) )
    {
LABEL_18:
      v11 = Scaleform::GFx::NumberUtil::NaN();
      v12 = v1->Result;
      if ( v12->T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(v12);
      v12->NV.NumberValue = v11;
      v12->T.Type = 3;
    }
    else
    {
      v10 = Scaleform::GFx::ASConstString::GetCharAt(v6, v9);
      Scaleform::GFx::AS2::Value::SetNumber(v1->Result, (double)v10);
    }
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      v1->Env,
      "Error: Null or invalid this is used for a method of %s class.\n",
      "String");
  }
}

// File Line: 116
// RVA: 0x6B0180
void __fastcall Scaleform::GFx::AS2::StringProto::StringConcat(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rdi
  Scaleform::GFx::AS2::ObjectInterface *v2; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rax
  int i; // ebx
  unsigned int v5; // er9
  Scaleform::GFx::AS2::Environment *v6; // r8
  Scaleform::GFx::AS2::Value *v7; // r10
  Scaleform::GFx::ASStringNode *v8; // rcx
  bool v9; // zf
  char *v10; // r8
  Scaleform::GFx::ASString *v11; // rsi
  Scaleform::GFx::AS2::Value *v12; // rbx
  Scaleform::GFx::ASStringNode *v13; // rax
  Scaleform::GFx::ASStringNode *v14; // rcx
  Scaleform::StringBuffer v15; // [rsp+28h] [rbp-40h]
  Scaleform::GFx::ASString result; // [rsp+70h] [rbp+8h]

  v1 = fn;
  v2 = fn->ThisPtr;
  if ( v2 && (*(unsigned int (__cdecl **)(Scaleform::GFx::AS2::ObjectInterface *))&v2->vfptr->gap8[8])(v2) == 8 )
  {
    v3 = v1->ThisPtr;
    if ( v3 )
      v3 -= 2;
    Scaleform::StringBuffer::StringBuffer(
      &v15,
      (const char *)v3[6].vfptr->__vecDelDtor,
      LODWORD(v3[6].vfptr->GetMember),
      Scaleform::Memory::pGlobalHeap);
    for ( i = 0; i < v1->NArgs; ++i )
    {
      v5 = v1->FirstArgBottomIndex - i;
      v6 = v1->Env;
      v7 = 0i64;
      if ( v5 <= 32 * ((unsigned int)v6->Stack.Pages.Data.Size - 1)
               + (unsigned int)((_QWORD)((char *)v6->Stack.pCurrent - (char *)v6->Stack.pPageStart) >> 5) )
        v7 = &v6->Stack.Pages.Data.Data[v5 >> 5]->Values[v5 & 0x1F];
      Scaleform::GFx::AS2::Value::ToString(v7, &result, v6, -1);
      Scaleform::StringBuffer::AppendString(&v15, result.pNode->pData, -1i64);
      v8 = result.pNode;
      v9 = result.pNode->RefCount == 1;
      --v8->RefCount;
      if ( v9 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v8);
    }
    v10 = &customWorldMapCaption;
    if ( v15.pData )
      v10 = v15.pData;
    v11 = Scaleform::GFx::AS2::Environment::CreateString(v1->Env, &result, v10, v15.Size);
    v12 = v1->Result;
    if ( v12->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(v1->Result);
    v12->T.Type = 5;
    v13 = v11->pNode;
    v12->NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)v11->pNode;
    ++v13->RefCount;
    v14 = result.pNode;
    v9 = result.pNode->RefCount == 1;
    --v14->RefCount;
    if ( v9 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v14);
    Scaleform::ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayDataBase<int,Scaleform::AllocatorGH<int,2>,Scaleform::ArrayDefaultPolicy> *)&v15);
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      v1->Env,
      "Error: Null or invalid this is used for a method of %s class.\n",
      "String");
  }
}

// File Line: 134
// RVA: 0x6B0490
void __fastcall Scaleform::GFx::AS2::StringProto::StringIndexOf(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rsi
  Scaleform::GFx::AS2::ObjectInterface *v2; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rax
  signed int v4; // edi
  signed __int64 v5; // rbx
  Scaleform::GFx::AS2::Value *v6; // rbx
  unsigned int v7; // er9
  Scaleform::GFx::AS2::Environment *v8; // r8
  Scaleform::GFx::AS2::Value *v9; // r10
  Scaleform::GFx::AS2::Value *v10; // rbx
  signed int v11; // er14
  Scaleform::GFx::AS2::Value *v12; // rax
  unsigned int v13; // ebp
  unsigned int v14; // eax
  unsigned int v15; // ebx
  unsigned int v16; // eax
  Scaleform::GFx::ASStringNode *v17; // rcx
  bool v18; // zf
  Scaleform::GFx::ASString result; // [rsp+20h] [rbp-38h]
  __int64 v20; // [rsp+28h] [rbp-30h]
  char *putf8Buffer; // [rsp+60h] [rbp+8h]
  char *v22; // [rsp+68h] [rbp+10h]
  char *v23; // [rsp+70h] [rbp+18h]
  char *v24; // [rsp+78h] [rbp+20h]

  v20 = -2i64;
  v1 = fn;
  v2 = fn->ThisPtr;
  if ( v2 && (*(unsigned int (**)(void))&v2->vfptr->gap8[8])() == 8 )
  {
    v3 = v1->ThisPtr;
    v4 = 0;
    v5 = (signed __int64)&v3[-2];
    if ( !v3 )
      v5 = 0i64;
    if ( v1->NArgs >= 1 )
    {
      v7 = v1->FirstArgBottomIndex;
      v8 = v1->Env;
      v9 = 0i64;
      if ( v7 <= 32 * ((unsigned int)v8->Stack.Pages.Data.Size - 1)
               + (unsigned int)((_QWORD)((char *)v8->Stack.pCurrent - (char *)v8->Stack.pPageStart) >> 5) )
        v9 = &v8->Stack.Pages.Data.Data[v7 >> 5]->Values[v7 & 0x1F];
      Scaleform::GFx::AS2::Value::ToString(v9, &result, v8, -1);
      if ( Scaleform::GFx::ASConstString::GetLength((Scaleform::GFx::ASConstString *)&result.pNode) )
      {
        putf8Buffer = (char *)result.pNode->pData;
        v22 = **(char ***)(v5 + 96);
        v11 = 0;
        if ( v1->NArgs > 1 )
        {
          v12 = Scaleform::GFx::AS2::FnCall::Arg(v1, 1);
          v11 = (signed int)Scaleform::GFx::AS2::Value::ToNumber(v12, v1->Env);
        }
        v13 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&putf8Buffer);
        if ( !v13 )
          --putf8Buffer;
        while ( 1 )
        {
          v14 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&v22);
          if ( !v14 )
          {
            --v22;
            v10 = v1->Result;
            if ( v10->T.Type >= 5u )
              Scaleform::GFx::AS2::Value::DropRefs(v1->Result);
            v10->V.pStringNode = (Scaleform::GFx::ASStringNode *)-4616189618054758400i64;
            goto LABEL_38;
          }
          if ( v4 >= v11 && v14 == v13 )
            break;
LABEL_32:
          ++v4;
        }
        v23 = v22;
        v24 = putf8Buffer;
        do
        {
          v15 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&v23);
          if ( !v15 )
            --v23;
          v16 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&v24);
          if ( !v16 )
            --v24;
          if ( !v15 )
            break;
          if ( !v16 )
            goto LABEL_34;
        }
        while ( v15 == v16 );
        if ( !v16 )
        {
LABEL_34:
          Scaleform::GFx::AS2::Value::SetInt(v1->Result, v4);
          goto LABEL_39;
        }
        if ( v15 )
          goto LABEL_32;
        Scaleform::GFx::AS2::Value::SetInt(v1->Result, 0xFFFFFFFF);
      }
      else
      {
        v10 = v1->Result;
        if ( v10->T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(v1->Result);
        v10->V.pStringNode = 0i64;
LABEL_38:
        v10->T.Type = 3;
      }
LABEL_39:
      v17 = result.pNode;
      v18 = result.pNode->RefCount == 1;
      --v17->RefCount;
      if ( v18 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v17);
    }
    else
    {
      v6 = v1->Result;
      if ( v6->T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(v1->Result);
      v6->T.Type = 3;
      v6->V.pStringNode = (Scaleform::GFx::ASStringNode *)-4616189618054758400i64;
    }
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      v1->Env,
      "Error: Null or invalid this is used for a method of %s class.\n",
      "String");
  }
}

// File Line: 199
// RVA: 0x6B0770
void __fastcall Scaleform::GFx::AS2::StringProto::StringLastIndexOf(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rsi
  Scaleform::GFx::AS2::ObjectInterface *v2; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rax
  signed int v4; // edi
  signed __int64 v5; // rax
  Scaleform::GFx::AS2::Value *v6; // rbx
  unsigned int v7; // er9
  Scaleform::GFx::AS2::Environment *v8; // r8
  Scaleform::GFx::AS2::Value *v9; // r10
  signed int v10; // er14
  double v11; // xmm6_8
  Scaleform::GFx::AS2::Value *v12; // rbx
  signed int v13; // er12
  Scaleform::GFx::AS2::Value *v14; // rax
  unsigned int v15; // er15
  unsigned int v16; // eax
  unsigned int v17; // ebx
  unsigned int v18; // eax
  Scaleform::GFx::AS2::Value *v19; // rbx
  Scaleform::GFx::ASStringNode *v20; // rcx
  bool v21; // zf
  Scaleform::GFx::ASStringNode *v22; // rcx
  Scaleform::GFx::ASString result; // [rsp+20h] [rbp-30h]
  Scaleform::GFx::ASConstString v24; // [rsp+28h] [rbp-28h]
  __int64 v25; // [rsp+30h] [rbp-20h]
  char *putf8Buffer; // [rsp+90h] [rbp+40h]
  char *v27; // [rsp+98h] [rbp+48h]
  char *v28; // [rsp+A0h] [rbp+50h]
  char *v29; // [rsp+A8h] [rbp+58h]

  v25 = -2i64;
  v1 = fn;
  v2 = fn->ThisPtr;
  if ( v2 && (*(unsigned int (**)(void))&v2->vfptr->gap8[8])() == 8 )
  {
    v3 = v1->ThisPtr;
    v4 = 0;
    if ( v3 )
      v5 = (signed __int64)&v3[-2];
    else
      v5 = 0i64;
    if ( v1->NArgs >= 1 )
    {
      v24.pNode = *(Scaleform::GFx::ASStringNode **)(v5 + 96);
      ++v24.pNode->RefCount;
      v7 = v1->FirstArgBottomIndex;
      v8 = v1->Env;
      v9 = 0i64;
      if ( v7 <= 32 * ((unsigned int)v8->Stack.Pages.Data.Size - 1)
               + (unsigned int)((_QWORD)((char *)v8->Stack.pCurrent - (char *)v8->Stack.pPageStart) >> 5) )
        v9 = &v8->Stack.Pages.Data.Data[v7 >> 5]->Values[v7 & 0x1F];
      v10 = -1;
      Scaleform::GFx::AS2::Value::ToString(v9, &result, v8, -1);
      if ( Scaleform::GFx::ASConstString::GetLength((Scaleform::GFx::ASConstString *)&result.pNode) )
      {
        v27 = (char *)v24.pNode->pData;
        putf8Buffer = (char *)result.pNode->pData;
        v13 = 0x7FFFFFF;
        if ( v1->NArgs > 1 )
        {
          v14 = Scaleform::GFx::AS2::FnCall::Arg(v1, 1);
          v13 = (signed int)Scaleform::GFx::AS2::Value::ToNumber(v14, v1->Env);
        }
        v15 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&putf8Buffer);
        if ( !v15 )
          --putf8Buffer;
        while ( 1 )
        {
          v16 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&v27);
          if ( !v16 )
            break;
          if ( v4 <= v13 && v16 == v15 )
          {
            v28 = v27;
            v29 = putf8Buffer;
            do
            {
              v17 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&v28);
              if ( !v17 )
                --v28;
              v18 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&v29);
              if ( !v18 )
                --v29;
              if ( !v17 )
                break;
              if ( !v18 )
                goto LABEL_32;
            }
            while ( v17 == v18 );
            if ( v18 )
              goto LABEL_33;
LABEL_32:
            v10 = v4;
LABEL_33:
            if ( !v17 )
              goto LABEL_36;
          }
          ++v4;
        }
        --v27;
LABEL_36:
        v19 = v1->Result;
        if ( v19->T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(v1->Result);
        v19->T.Type = 4;
        v19->NV.Int32Value = v10;
      }
      else
      {
        v11 = (double)(signed int)Scaleform::GFx::ASConstString::GetLength(&v24);
        v12 = v1->Result;
        if ( v12->T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(v1->Result);
        v12->T.Type = 3;
        v12->NV.NumberValue = v11;
      }
      v20 = result.pNode;
      v21 = result.pNode->RefCount == 1;
      --v20->RefCount;
      if ( v21 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v20);
      v22 = v24.pNode;
      v21 = v24.pNode->RefCount == 1;
      --v22->RefCount;
      if ( v21 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v22);
    }
    else
    {
      v6 = v1->Result;
      if ( v6->T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(v1->Result);
      v6->T.Type = 3;
      v6->V.pStringNode = (Scaleform::GFx::ASStringNode *)-4616189618054758400i64;
    }
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      v1->Env,
      "Error: Null or invalid this is used for a method of %s class.\n",
      "String");
  }
}

// File Line: 264
// RVA: 0x6B0DB0
void __fastcall Scaleform::GFx::AS2::StringProto::StringSlice(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rbx
  Scaleform::GFx::AS2::ObjectInterface *v2; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // r14
  Scaleform::GFx::AS2::Value *v4; // rbp
  Scaleform::GFx::ASString *v5; // r14
  int v6; // esi
  int v7; // edi
  unsigned int v8; // er10
  Scaleform::GFx::AS2::Environment *v9; // rdx
  Scaleform::GFx::AS2::Value *v10; // r9
  unsigned int v11; // er9
  Scaleform::GFx::AS2::Environment *v12; // rdx
  signed int v13; // edi
  Scaleform::GFx::ASMovieRootBase *v14; // rdi
  Scaleform::GFx::AS2::Value *v15; // rbx
  Scaleform::GFx::ASStringNode *v16; // rax
  Scaleform::GFx::ASString *v17; // rdi
  Scaleform::GFx::AS2::Value *v18; // rbx
  Scaleform::GFx::ASStringNode *v19; // rax
  Scaleform::GFx::ASStringNode *v20; // rcx
  bool v21; // zf
  Scaleform::GFx::ASString result; // [rsp+50h] [rbp+8h]

  v1 = fn;
  v2 = fn->ThisPtr;
  if ( !v2 || (*(unsigned int (__cdecl **)(Scaleform::GFx::AS2::ObjectInterface *))&v2->vfptr->gap8[8])(v2) != 8 )
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      v1->Env,
      "Error: Null or invalid this is used for a method of %s class.\n",
      "String");
    return;
  }
  v3 = v1->ThisPtr;
  v4 = 0i64;
  if ( v3 )
    v5 = (Scaleform::GFx::ASString *)&v3[-2];
  else
    v5 = 0i64;
  v6 = 0;
  v7 = -1;
  if ( v1->NArgs >= 1 )
  {
    v8 = v1->FirstArgBottomIndex;
    v9 = v1->Env;
    v10 = 0i64;
    if ( v8 <= 32 * ((unsigned int)v9->Stack.Pages.Data.Size - 1)
             + (unsigned int)((_QWORD)((char *)v9->Stack.pCurrent - (char *)v9->Stack.pPageStart) >> 5) )
      v10 = &v9->Stack.Pages.Data.Data[v8 >> 5]->Values[v8 & 0x1F];
    v6 = (signed int)Scaleform::GFx::AS2::Value::ToNumber(v10, v9);
    if ( v6 < 0 )
      v6 += Scaleform::GFx::ASConstString::GetLength((Scaleform::GFx::ASConstString *)&v5[12].pNode);
  }
  if ( v1->NArgs >= 2 )
  {
    v11 = v1->FirstArgBottomIndex - 1;
    v12 = v1->Env;
    if ( v11 <= 32 * ((unsigned int)v12->Stack.Pages.Data.Size - 1)
              + (unsigned int)((_QWORD)((char *)v12->Stack.pCurrent - (char *)v12->Stack.pPageStart) >> 5) )
      v4 = &v12->Stack.Pages.Data.Data[v11 >> 5]->Values[v11 & 0x1F];
    v13 = (signed int)Scaleform::GFx::AS2::Value::ToNumber(v4, v12);
    if ( v13 < 0 )
      v13 += Scaleform::GFx::ASConstString::GetLength((Scaleform::GFx::ASConstString *)&v5[12].pNode);
    if ( v13 < v6 )
    {
      v14 = v1->Env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject;
      v15 = v1->Result;
      if ( v15->T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(v15);
      v15->T.Type = 5;
      v16 = *(Scaleform::GFx::ASStringNode **)&v14[7].AVMVersion;
      v15->V.pStringNode = v16;
      ++v16->RefCount;
      return;
    }
    v7 = v13 - v6;
  }
  v17 = Scaleform::GFx::AS2::StringProto::StringSubstring(&result, v5 + 12, v6, v7);
  v18 = v1->Result;
  if ( v18->T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(v18);
  v18->T.Type = 5;
  v19 = v17->pNode;
  v18->NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)v17->pNode;
  ++v19->RefCount;
  v20 = result.pNode;
  v21 = result.pNode->RefCount == 1;
  --v20->RefCount;
  if ( v21 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v20);
}

// File Line: 293
// RVA: 0x6B1010
void __fastcall Scaleform::GFx::AS2::StringProto::StringSplit(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rdi
  Scaleform::GFx::AS2::ObjectInterface *v2; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rax
  Scaleform::GFx::ASString *v4; // rbp
  Scaleform::GFx::ASStringNode *v5; // rbx
  const char *v6; // rsi
  unsigned int v7; // er9
  Scaleform::GFx::AS2::Environment *v8; // r8
  Scaleform::GFx::AS2::Value *v9; // r10
  Scaleform::GFx::ASStringNode *v10; // rsi
  bool v11; // zf
  Scaleform::GFx::ASStringNode *v12; // rcx
  int limit; // eax
  unsigned int v14; // er9
  Scaleform::GFx::AS2::Environment *v15; // rdx
  Scaleform::GFx::AS2::Value *v16; // r10
  Scaleform::GFx::AS2::ArrayObject *v17; // rcx
  unsigned int v18; // eax
  Scaleform::Ptr<Scaleform::GFx::AS2::ArrayObject> v19; // [rsp+70h] [rbp+8h]
  Scaleform::GFx::ASStringNode *v20; // [rsp+78h] [rbp+10h]
  Scaleform::GFx::ASString result; // [rsp+80h] [rbp+18h]

  v1 = fn;
  v2 = fn->ThisPtr;
  if ( v2 && (*(unsigned int (**)(void))&v2->vfptr->gap8[8])() == 8 )
  {
    v3 = v1->ThisPtr;
    v4 = (Scaleform::GFx::ASString *)&v3[-2];
    if ( !v3 )
      v4 = 0i64;
    v5 = *(Scaleform::GFx::ASStringNode **)&v1->Env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[7].AVMVersion;
    v20 = v5;
    ++v5->RefCount;
    v6 = 0i64;
    if ( v1->NArgs >= 1 )
    {
      v7 = v1->FirstArgBottomIndex;
      v8 = v1->Env;
      v9 = 0i64;
      if ( v7 <= 32 * ((unsigned int)v8->Stack.Pages.Data.Size - 1)
               + (unsigned int)((_QWORD)((char *)v8->Stack.pCurrent - (char *)v8->Stack.pPageStart) >> 5) )
        v9 = &v8->Stack.Pages.Data.Data[v7 >> 5]->Values[v7 & 0x1F];
      v10 = Scaleform::GFx::AS2::Value::ToString(v9, &result, v8, -1)->pNode;
      ++v10->RefCount;
      v11 = v5->RefCount-- == 1;
      if ( v11 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v5);
      v5 = v10;
      v20 = v10;
      v12 = result.pNode;
      v11 = result.pNode->RefCount == 1;
      --v12->RefCount;
      if ( v11 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v12);
      v6 = v10->pData;
    }
    limit = 0x3FFFFFFF;
    if ( v1->NArgs >= 2 )
    {
      v14 = v1->FirstArgBottomIndex - 1;
      v15 = v1->Env;
      v16 = 0i64;
      if ( v14 <= 32 * ((unsigned int)v15->Stack.Pages.Data.Size - 1)
                + (unsigned int)((_QWORD)((char *)v15->Stack.pCurrent - (char *)v15->Stack.pPageStart) >> 5) )
        v16 = &v15->Stack.Pages.Data.Data[v14 >> 5]->Values[v14 & 0x1F];
      limit = (signed int)Scaleform::GFx::AS2::Value::ToNumber(v16, v15);
      if ( limit < 0 )
        limit = 0;
    }
    Scaleform::GFx::AS2::StringProto::StringSplit(&v19, v1->Env, v4 + 12, v6, limit);
    Scaleform::GFx::AS2::Value::SetAsObject(v1->Result, (Scaleform::GFx::AS2::Object *)&v19.pObject->vfptr);
    v17 = v19.pObject;
    if ( v19.pObject )
    {
      v18 = v19.pObject->RefCount;
      if ( v18 & 0x3FFFFFF )
      {
        v19.pObject->RefCount = v18 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v17->vfptr);
      }
    }
    v11 = v5->RefCount-- == 1;
    if ( v11 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v5);
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      v1->Env,
      "Error: Null or invalid this is used for a method of %s class.\n",
      "String");
  }
}

// File Line: 319
// RVA: 0x720BB0
Scaleform::Ptr<Scaleform::GFx::AS2::ArrayObject> *__fastcall Scaleform::GFx::AS2::StringProto::StringSplit(Scaleform::Ptr<Scaleform::GFx::AS2::ArrayObject> *result, Scaleform::GFx::AS2::Environment *penv, Scaleform::GFx::ASString *str, const char *delimiters, int limit)
{
  char *v5; // r14
  char ***v6; // rdi
  Scaleform::Ptr<Scaleform::GFx::AS2::ArrayObject> *v7; // r13
  Scaleform::GFx::AS2::ASStringContext *v8; // rsi
  Scaleform::GFx::ASStringNode *v9; // rcx
  char *v10; // rax
  int v11; // edx
  unsigned int v12; // edi
  Scaleform::GFx::ASString *v13; // rax
  Scaleform::GFx::ASStringNode *v14; // rcx
  bool v15; // zf
  int v16; // er15
  const char *v17; // r12
  char *v18; // rbx
  char *v19; // r14
  unsigned int v20; // esi
  unsigned int v21; // edi
  Scaleform::GFx::ASStringNode *v22; // rbx
  Scaleform::GFx::ASString *v23; // rax
  Scaleform::GFx::ASStringNode *v24; // rcx
  Scaleform::GFx::ASString *v25; // rax
  Scaleform::GFx::ASStringNode *v26; // rcx
  Scaleform::GFx::ASString *v27; // rax
  Scaleform::GFx::AS2::ASStringContext *psc; // [rsp+30h] [rbp-D0h]
  Scaleform::GFx::ASString resulta; // [rsp+38h] [rbp-C8h]
  int v31; // [rsp+40h] [rbp-C0h]
  Scaleform::GFx::ASString v32; // [rsp+48h] [rbp-B8h]
  Scaleform::GFx::ASString v33; // [rsp+50h] [rbp-B0h]
  Scaleform::GFx::AS2::Value val; // [rsp+58h] [rbp-A8h]
  Scaleform::GFx::AS2::Value v35; // [rsp+78h] [rbp-88h]
  Scaleform::GFx::AS2::Value v36; // [rsp+98h] [rbp-68h]
  Scaleform::GFx::AS2::Value v37; // [rsp+B8h] [rbp-48h]
  Scaleform::GFx::AS2::Value v38; // [rsp+D8h] [rbp-28h]
  __int64 v39; // [rsp+F8h] [rbp-8h]
  char *putf8Buffer; // [rsp+158h] [rbp+58h]
  char *v41; // [rsp+160h] [rbp+60h]
  Scaleform::String stra; // [rsp+168h] [rbp+68h]

  stra.pData = (Scaleform::String::DataDesc *)delimiters;
  v39 = -2i64;
  v5 = (char *)delimiters;
  v6 = (char ***)str;
  v7 = result;
  v31 = 0;
  v8 = &penv->StringContext;
  psc = &penv->StringContext;
  result->pObject = (Scaleform::GFx::AS2::ArrayObject *)Scaleform::GFx::AS2::Environment::OperatorNew(
                                                          penv,
                                                          penv->StringContext.pContext->pGlobal.pObject,
                                                          (Scaleform::GFx::ASString *)&penv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[8].RefCount,
                                                          0,
                                                          -1);
  v31 = 1;
  v9 = (Scaleform::GFx::ASStringNode *)*v6;
  v10 = **v6;
  putf8Buffer = **v6;
  v11 = limit;
  if ( limit < 0 )
    v11 = 0;
  limit = v11;
  if ( v5 )
  {
    if ( *v5 )
    {
      v16 = 0;
      v17 = v10;
      do
      {
        v41 = v5;
        resulta.pNode = (Scaleform::GFx::ASStringNode *)v10;
        v18 = 0i64;
        while ( 1 )
        {
          v19 = v10;
          v20 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&putf8Buffer);
          if ( !v20 )
            --putf8Buffer;
          v21 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&v41);
          if ( !v21 )
            --v41;
          v10 = putf8Buffer;
          if ( !v18 )
            v18 = putf8Buffer;
          if ( !v20 )
            break;
          if ( !v21 )
            goto LABEL_28;
          if ( v20 != v21 )
          {
            v10 = v18;
            putf8Buffer = v18;
            break;
          }
        }
        if ( v21 )
        {
          v22 = resulta.pNode;
          goto LABEL_35;
        }
LABEL_28:
        if ( v16 >= limit )
          return v7;
        v22 = resulta.pNode;
        v23 = Scaleform::GFx::AS2::StringProto::CreateStringFromCStr(&v33, psc, v17, (const char *)resulta.pNode);
        v36.T.Type = 5;
        v36.NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)v23->pNode;
        ++v36.V.pStringNode->RefCount;
        Scaleform::GFx::AS2::ArrayObject::PushBack(v7->pObject, &v36);
        if ( v36.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&v36);
        v24 = v33.pNode;
        v15 = v33.pNode->RefCount == 1;
        --v24->RefCount;
        if ( v15 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v24);
        v17 = v19;
        v10 = v19;
        putf8Buffer = v19;
        ++v16;
LABEL_35:
        v5 = (char *)stra.pData;
      }
      while ( v20 );
      if ( v16 < limit )
      {
        if ( v21 )
        {
          v27 = Scaleform::GFx::AS2::StringProto::CreateStringFromCStr(&v32, psc, v17, 0i64);
          v37.T.Type = 5;
          v37.NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)v27->pNode;
          ++v37.V.pStringNode->RefCount;
          Scaleform::GFx::AS2::ArrayObject::PushBack(v7->pObject, &v37);
          if ( v37.T.Type >= 5u )
            Scaleform::GFx::AS2::Value::DropRefs(&v37);
          v26 = v32.pNode;
        }
        else
        {
          v25 = Scaleform::GFx::AS2::StringProto::CreateStringFromCStr(
                  (Scaleform::GFx::ASString *)&psc,
                  psc,
                  v17,
                  (const char *)v22);
          v38.T.Type = 5;
          v38.NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)v25->pNode;
          ++v38.V.pStringNode->RefCount;
          Scaleform::GFx::AS2::ArrayObject::PushBack(v7->pObject, &v38);
          if ( v38.T.Type >= 5u )
            Scaleform::GFx::AS2::Value::DropRefs(&v38);
          v26 = (Scaleform::GFx::ASStringNode *)psc;
        }
        v15 = v26->RefCount-- == 1;
        if ( v15 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v26);
      }
    }
    else
    {
      Scaleform::String::String(&stra);
      while ( 1 )
      {
        v12 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&putf8Buffer);
        if ( !v12 )
          break;
        Scaleform::String::Clear(&stra);
        Scaleform::String::AppendChar(&stra, v12);
        v13 = Scaleform::GFx::AS2::ASStringContext::CreateString(v8, &resulta, &stra);
        v35.T.Type = 5;
        v35.NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)v13->pNode;
        ++v35.V.pStringNode->RefCount;
        Scaleform::GFx::AS2::ArrayObject::PushBack(v7->pObject, &v35);
        if ( v35.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&v35);
        v14 = resulta.pNode;
        v15 = resulta.pNode->RefCount == 1;
        --v14->RefCount;
        if ( v15 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v14);
      }
      --putf8Buffer;
      if ( !_InterlockedDecrement((volatile signed __int32 *)((stra.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
    }
  }
  else
  {
    val.T.Type = 5;
    val.V.pStringNode = v9;
    ++v9->RefCount;
    Scaleform::GFx::AS2::ArrayObject::PushBack(v7->pObject, &val);
    if ( val.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&val);
  }
  return v7;
}

// File Line: 411
// RVA: 0x720EF0
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::AS2::StringProto::StringSubstring(Scaleform::GFx::ASString *result, Scaleform::GFx::ASString *self, int start, int length)
{
  int v4; // ebx
  int v5; // esi
  Scaleform::GFx::ASString *v6; // r14
  Scaleform::GFx::ASString *v7; // rdi
  int v8; // ecx

  v4 = length;
  v5 = start;
  v6 = self;
  v7 = result;
  if ( length )
  {
    if ( start < 0 )
      v5 = 0;
    v8 = Scaleform::GFx::ASConstString::GetLength((Scaleform::GFx::ASConstString *)&self->pNode);
    if ( v5 < v8 )
    {
      if ( v4 < 0 || v5 + v4 > v8 )
        v4 = v8 - v5;
      Scaleform::GFx::ASString::Substring(v6, v7, v5, v5 + v4);
    }
    else
    {
      Scaleform::GFx::ASStringManager::CreateEmptyString(v6->pNode->pManager, v7);
    }
  }
  else
  {
    Scaleform::GFx::ASStringManager::CreateEmptyString(self->pNode->pManager, result);
  }
  return v7;
}

// File Line: 431
// RVA: 0x6E17C0
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::AS2::StringProto::CreateStringFromCStr(Scaleform::GFx::ASString *result, Scaleform::GFx::AS2::ASStringContext *psc, const char *start, const char *end)
{
  Scaleform::GFx::ASString *v4; // rbx
  signed __int64 v5; // rax
  Scaleform::GFx::ASStringNode *v6; // rcx

  v4 = result;
  if ( end )
  {
    LODWORD(v5) = (_DWORD)end - (_DWORD)start;
  }
  else
  {
    v5 = -1i64;
    do
      ++v5;
    while ( start[v5] );
  }
  if ( (signed int)v5 < 1 )
  {
    v6 = *(Scaleform::GFx::ASStringNode **)&psc->pContext->pMovieRoot->pASMovieRoot.pObject[7].AVMVersion;
    v4->pNode = v6;
    ++v6->RefCount;
  }
  else
  {
    Scaleform::GFx::AS2::ASStringContext::CreateString(psc, result, start, (signed int)v5);
  }
  return v4;
}

// File Line: 442
// RVA: 0x6B1700
void __fastcall Scaleform::GFx::AS2::StringProto::StringSubstr(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rbx
  Scaleform::GFx::AS2::ObjectInterface *v2; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rax
  Scaleform::GFx::ASString *v4; // rbp
  int v5; // edi
  int v6; // esi
  unsigned int v7; // er10
  Scaleform::GFx::AS2::Environment *v8; // rdx
  Scaleform::GFx::AS2::Value *v9; // r9
  unsigned int v10; // er9
  Scaleform::GFx::AS2::Environment *v11; // rdx
  Scaleform::GFx::AS2::Value *v12; // r10
  Scaleform::GFx::ASString *v13; // rdi
  Scaleform::GFx::AS2::Value *v14; // rbx
  Scaleform::GFx::ASStringNode *v15; // rax
  Scaleform::GFx::ASStringNode *v16; // rcx
  bool v17; // zf
  Scaleform::GFx::ASString result; // [rsp+50h] [rbp+8h]

  v1 = fn;
  v2 = fn->ThisPtr;
  if ( v2 && (*(unsigned int (__cdecl **)(Scaleform::GFx::AS2::ObjectInterface *))&v2->vfptr->gap8[8])(v2) == 8 )
  {
    v3 = v1->ThisPtr;
    v4 = (Scaleform::GFx::ASString *)&v3[-2];
    if ( !v3 )
      v4 = 0i64;
    v5 = 0;
    v6 = -1;
    if ( v1->NArgs >= 1 )
    {
      v7 = v1->FirstArgBottomIndex;
      v8 = v1->Env;
      v9 = 0i64;
      if ( v7 <= 32 * ((unsigned int)v8->Stack.Pages.Data.Size - 1)
               + (unsigned int)((_QWORD)((char *)v8->Stack.pCurrent - (char *)v8->Stack.pPageStart) >> 5) )
        v9 = &v8->Stack.Pages.Data.Data[v7 >> 5]->Values[v7 & 0x1F];
      v5 = (signed int)Scaleform::GFx::AS2::Value::ToNumber(v9, v8);
      if ( v5 < 0 )
        v5 += Scaleform::GFx::ASConstString::GetLength((Scaleform::GFx::ASConstString *)&v4[12].pNode);
    }
    if ( v1->NArgs >= 2 )
    {
      v10 = v1->FirstArgBottomIndex - 1;
      v11 = v1->Env;
      v12 = 0i64;
      if ( v10 <= 32 * ((unsigned int)v11->Stack.Pages.Data.Size - 1)
                + (unsigned int)((_QWORD)((char *)v11->Stack.pCurrent - (char *)v11->Stack.pPageStart) >> 5) )
        v12 = &v11->Stack.Pages.Data.Data[v10 >> 5]->Values[v10 & 0x1F];
      v6 = (signed int)Scaleform::GFx::AS2::Value::ToNumber(v12, v11);
      if ( v6 < 0 )
        v6 = 0;
    }
    v13 = Scaleform::GFx::AS2::StringProto::StringSubstring(&result, v4 + 12, v5, v6);
    v14 = v1->Result;
    if ( v14->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(v14);
    v14->T.Type = 5;
    v15 = v13->pNode;
    v14->NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)v13->pNode;
    ++v15->RefCount;
    v16 = result.pNode;
    v17 = result.pNode->RefCount == 1;
    --v16->RefCount;
    if ( v17 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v16);
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      v1->Env,
      "Error: Null or invalid this is used for a method of %s class.\n",
      "String");
  }
}

// File Line: 470
// RVA: 0x6B19B0
void __fastcall Scaleform::GFx::AS2::StringProto::StringSubstring(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rbx
  Scaleform::GFx::AS2::ObjectInterface *v2; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rax
  Scaleform::GFx::ASString *v4; // rbp
  int v5; // edi
  int v6; // esi
  unsigned int v7; // er10
  Scaleform::GFx::AS2::Environment *v8; // rdx
  Scaleform::GFx::AS2::Value *v9; // r9
  unsigned int v10; // er9
  Scaleform::GFx::AS2::Environment *v11; // rdx
  Scaleform::GFx::AS2::Value *v12; // r10
  signed int v13; // esi
  int v14; // eax
  Scaleform::GFx::ASString *v15; // rdi
  Scaleform::GFx::AS2::Value *v16; // rbx
  Scaleform::GFx::ASStringNode *v17; // rax
  Scaleform::GFx::ASStringNode *v18; // rcx
  bool v19; // zf
  Scaleform::GFx::ASString result; // [rsp+50h] [rbp+8h]

  v1 = fn;
  v2 = fn->ThisPtr;
  if ( v2 && (*(unsigned int (__cdecl **)(Scaleform::GFx::AS2::ObjectInterface *))&v2->vfptr->gap8[8])(v2) == 8 )
  {
    v3 = v1->ThisPtr;
    v4 = (Scaleform::GFx::ASString *)&v3[-2];
    if ( !v3 )
      v4 = 0i64;
    v5 = 0;
    v6 = -1;
    if ( v1->NArgs >= 1 )
    {
      v7 = v1->FirstArgBottomIndex;
      v8 = v1->Env;
      v9 = 0i64;
      if ( v7 <= 32 * ((unsigned int)v8->Stack.Pages.Data.Size - 1)
               + (unsigned int)((_QWORD)((char *)v8->Stack.pCurrent - (char *)v8->Stack.pPageStart) >> 5) )
        v9 = &v8->Stack.Pages.Data.Data[v7 >> 5]->Values[v7 & 0x1F];
      v5 = (signed int)Scaleform::GFx::AS2::Value::ToNumber(v9, v8);
    }
    if ( v1->NArgs >= 2 )
    {
      v10 = v1->FirstArgBottomIndex - 1;
      v11 = v1->Env;
      v12 = 0i64;
      if ( v10 <= 32 * ((unsigned int)v11->Stack.Pages.Data.Size - 1)
                + (unsigned int)((_QWORD)((char *)v11->Stack.pCurrent - (char *)v11->Stack.pPageStart) >> 5) )
        v12 = &v11->Stack.Pages.Data.Data[v10 >> 5]->Values[v10 & 0x1F];
      v13 = (signed int)Scaleform::GFx::AS2::Value::ToNumber(v12, v11);
      if ( v13 < v5 )
      {
        if ( v5 >= (signed int)Scaleform::GFx::ASConstString::GetLength((Scaleform::GFx::ASConstString *)&v4[12].pNode) )
        {
          Scaleform::GFx::AS2::Value::SetString(
            v1->Result,
            (Scaleform::GFx::ASString *)&v1->Env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[7].AVMVersion);
          return;
        }
        v14 = v5;
        v5 = v13;
        v13 = v14;
      }
      if ( v5 < 0 )
        v5 = 0;
      v6 = v13 - v5;
    }
    v15 = Scaleform::GFx::AS2::StringProto::StringSubstring(&result, v4 + 12, v5, v6);
    v16 = v1->Result;
    if ( v16->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(v16);
    v16->T.Type = 5;
    v17 = v15->pNode;
    v16->NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)v15->pNode;
    ++v17->RefCount;
    v18 = result.pNode;
    v19 = result.pNode->RefCount == 1;
    --v18->RefCount;
    if ( v19 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v18);
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      v1->Env,
      "Error: Null or invalid this is used for a method of %s class.\n",
      "String");
  }
}

// File Line: 519
// RVA: 0x6B1C90
void __fastcall Scaleform::GFx::AS2::StringProto::StringToLowerCase(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rbx
  Scaleform::GFx::AS2::ObjectInterface *v2; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rax
  Scaleform::GFx::ASString *v4; // rcx
  Scaleform::GFx::ASString *v5; // rdi
  Scaleform::GFx::AS2::Value *v6; // rbx
  Scaleform::GFx::ASStringNode *v7; // rax
  Scaleform::GFx::ASStringNode *v8; // rcx
  bool v9; // zf
  Scaleform::GFx::ASString result; // [rsp+40h] [rbp+8h]

  v1 = fn;
  v2 = fn->ThisPtr;
  if ( v2 && (*(unsigned int (__cdecl **)(Scaleform::GFx::AS2::ObjectInterface *))&v2->vfptr->gap8[8])(v2) == 8 )
  {
    v3 = v1->ThisPtr;
    if ( v3 )
      v4 = (Scaleform::GFx::ASString *)&v3[-2];
    else
      v4 = 0i64;
    v5 = Scaleform::GFx::ASString::ToLower(v4 + 12, &result);
    v6 = v1->Result;
    if ( v6->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(v6);
    v6->T.Type = 5;
    v7 = v5->pNode;
    v6->NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)v5->pNode;
    ++v7->RefCount;
    v8 = result.pNode;
    v9 = result.pNode->RefCount == 1;
    --v8->RefCount;
    if ( v9 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v8);
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      v1->Env,
      "Error: Null or invalid this is used for a method of %s class.\n",
      "String");
  }
}

// File Line: 527
// RVA: 0x6B1FB0
void __fastcall Scaleform::GFx::AS2::StringProto::StringValueOf(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rbx
  Scaleform::GFx::AS2::ObjectInterface *v2; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rax
  signed __int64 v4; // rdi
  Scaleform::GFx::AS2::Value *v5; // rbx
  Scaleform::GFx::ASStringNode *v6; // rax

  v1 = fn;
  v2 = fn->ThisPtr;
  if ( v2 && (*(unsigned int (**)(void))&v2->vfptr->gap8[8])() == 8 )
  {
    v3 = v1->ThisPtr;
    if ( v3 )
      v4 = (signed __int64)&v3[-2];
    else
      v4 = 0i64;
    v5 = v1->Result;
    if ( v5->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(v5);
    v5->T.Type = 5;
    v6 = *(Scaleform::GFx::ASStringNode **)(v4 + 96);
    v5->V.pStringNode = v6;
    ++v6->RefCount;
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      v1->Env,
      "Error: Null or invalid this is used for a method of %s class.\n",
      "String");
  }
}

// File Line: 535
// RVA: 0x6B1F10
void __fastcall Scaleform::GFx::AS2::StringProto::StringToUpperCase(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rbx
  Scaleform::GFx::AS2::ObjectInterface *v2; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rax
  Scaleform::GFx::ASString *v4; // rcx
  Scaleform::GFx::ASString *v5; // rdi
  Scaleform::GFx::AS2::Value *v6; // rbx
  Scaleform::GFx::ASStringNode *v7; // rax
  Scaleform::GFx::ASStringNode *v8; // rcx
  bool v9; // zf
  Scaleform::GFx::ASString result; // [rsp+40h] [rbp+8h]

  v1 = fn;
  v2 = fn->ThisPtr;
  if ( v2 && (*(unsigned int (__cdecl **)(Scaleform::GFx::AS2::ObjectInterface *))&v2->vfptr->gap8[8])(v2) == 8 )
  {
    v3 = v1->ThisPtr;
    if ( v3 )
      v4 = (Scaleform::GFx::ASString *)&v3[-2];
    else
      v4 = 0i64;
    v5 = Scaleform::GFx::ASString::ToUpper(v4 + 12, &result);
    v6 = v1->Result;
    if ( v6->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(v6);
    v6->T.Type = 5;
    v7 = v5->pNode;
    v6->NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)v5->pNode;
    ++v7->RefCount;
    v8 = result.pNode;
    v9 = result.pNode->RefCount == 1;
    --v8->RefCount;
    if ( v9 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v8);
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      v1->Env,
      "Error: Null or invalid this is used for a method of %s class.\n",
      "String");
  }
}

// File Line: 555
// RVA: 0x6B0B60
void __fastcall Scaleform::GFx::AS2::StringProto::StringLocaleCompare(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rdi
  Scaleform::GFx::AS2::Value *v2; // rbx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v4; // rax
  Scaleform::GFx::AS2::Value *v5; // rbx
  Scaleform::GFx::ASConstString *v6; // rbp
  unsigned int v7; // er9
  Scaleform::GFx::AS2::Environment *v8; // r8
  Scaleform::GFx::AS2::Value *v9; // r10
  char v10; // si
  unsigned int v11; // er9
  Scaleform::GFx::AS2::Environment *v12; // rdx
  const char *v13; // rbx
  unsigned int v14; // eax
  signed int v15; // esi
  Scaleform::GFx::AS2::Value *v16; // rbx
  Scaleform::GFx::ASStringNode *v17; // rcx
  bool v18; // zf
  Scaleform::GFx::ASString result; // [rsp+40h] [rbp+8h]

  v1 = fn;
  v2 = fn->Result;
  Scaleform::GFx::AS2::Value::DropRefs(fn->Result);
  v2->T.Type = 0;
  if ( v1->Env->StringContext.pContext->GFxExtensions.Value == 1 )
  {
    v3 = v1->ThisPtr;
    if ( v3 && (*(unsigned int (__cdecl **)(Scaleform::GFx::AS2::ObjectInterface *))&v3->vfptr->gap8[8])(v3) == 8 )
    {
      v4 = v1->ThisPtr;
      v5 = 0i64;
      v6 = (Scaleform::GFx::ASConstString *)&v4[-2];
      if ( !v4 )
        v6 = 0i64;
      if ( v1->NArgs >= 1 )
      {
        v7 = v1->FirstArgBottomIndex;
        v8 = v1->Env;
        v9 = 0i64;
        if ( v7 <= 32 * ((unsigned int)v8->Stack.Pages.Data.Size - 1)
                 + (unsigned int)((_QWORD)((char *)v8->Stack.pCurrent - (char *)v8->Stack.pPageStart) >> 5) )
          v9 = &v8->Stack.Pages.Data.Data[v7 >> 5]->Values[v7 & 0x1F];
        Scaleform::GFx::AS2::Value::ToString(v9, &result, v8, -1);
        v10 = 1;
        if ( v1->NArgs >= 2 )
        {
          v11 = v1->FirstArgBottomIndex - 1;
          v12 = v1->Env;
          if ( v11 <= 32 * ((unsigned int)v12->Stack.Pages.Data.Size - 1)
                    + (unsigned int)((_QWORD)((char *)v12->Stack.pCurrent - (char *)v12->Stack.pPageStart) >> 5) )
            v5 = &v12->Stack.Pages.Data.Data[v11 >> 5]->Values[v11 & 0x1F];
          v10 = Scaleform::GFx::AS2::Value::ToBool(v5, v12) == 0;
        }
        v13 = result.pNode->pData;
        v14 = Scaleform::GFx::ASConstString::GetLength((Scaleform::GFx::ASConstString *)&result.pNode);
        v15 = Scaleform::GFx::ASConstString::LocaleCompare_CaseCheck(v6 + 12, v13, v14, v10);
        v16 = v1->Result;
        if ( v16->T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(v1->Result);
        v16->T.Type = 3;
        v16->NV.NumberValue = (double)v15;
        v17 = result.pNode;
        v18 = result.pNode->RefCount == 1;
        --v17->RefCount;
        if ( v18 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v17);
      }
    }
    else
    {
      Scaleform::GFx::AS2::Environment::LogScriptError(
        v1->Env,
        "Error: Null or invalid this is used for a method of %s class.\n",
        "String");
    }
  }
}

// File Line: 615
// RVA: 0x6B2450
void __fastcall Scaleform::GFx::AS2::StringCtorFunction::StringFromCharCode(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rbx
  int i; // edi
  unsigned int v3; // er9
  Scaleform::GFx::AS2::Environment *v4; // rdx
  Scaleform::GFx::AS2::Value *v5; // r10
  long double v6; // xmm0_8
  char *v7; // r8
  Scaleform::GFx::ASString *v8; // rdi
  Scaleform::GFx::AS2::Value *v9; // rbx
  Scaleform::GFx::ASStringNode *v10; // rax
  Scaleform::GFx::ASStringNode *v11; // rcx
  bool v12; // zf
  Scaleform::StringBuffer v13; // [rsp+28h] [rbp-40h]
  Scaleform::GFx::ASString result; // [rsp+70h] [rbp+8h]

  v1 = fn;
  Scaleform::StringBuffer::StringBuffer(&v13, Scaleform::Memory::pGlobalHeap);
  for ( i = 0; i < v1->NArgs; ++i )
  {
    v3 = v1->FirstArgBottomIndex - i;
    v4 = v1->Env;
    v5 = 0i64;
    if ( v3 <= 32 * ((unsigned int)v4->Stack.Pages.Data.Size - 1)
             + (unsigned int)((_QWORD)((char *)v4->Stack.pCurrent - (char *)v4->Stack.pPageStart) >> 5) )
      v5 = &v4->Stack.Pages.Data.Data[v3 >> 5]->Values[v3 & 0x1F];
    v6 = Scaleform::GFx::AS2::Value::ToNumber(v5, v4);
    Scaleform::StringBuffer::AppendChar(&v13, (signed int)v6);
  }
  v7 = &customWorldMapCaption;
  if ( v13.pData )
    v7 = v13.pData;
  v8 = Scaleform::GFx::AS2::Environment::CreateString(v1->Env, &result, v7, v13.Size);
  v9 = v1->Result;
  if ( v9->T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(v9);
  v9->T.Type = 5;
  v10 = v8->pNode;
  v9->NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)v8->pNode;
  ++v10->RefCount;
  v11 = result.pNode;
  v12 = result.pNode->RefCount == 1;
  --v11->RefCount;
  if ( v12 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v11);
  Scaleform::ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayDataBase<int,Scaleform::AllocatorGH<int,2>,Scaleform::ArrayDefaultPolicy> *)&v13);
}

// File Line: 631
// RVA: 0x6E0810
Scaleform::GFx::AS2::Object *__fastcall Scaleform::GFx::AS2::StringCtorFunction::CreateNewObject(Scaleform::GFx::AS2::StringCtorFunction *this, Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::Environment *v2; // rbx
  Scaleform::GFx::AS2::ASStringContext *v3; // rdi
  Scaleform::GFx::AS2::StringObject *v4; // rax
  __int64 v5; // rax
  __int64 v6; // rbx
  Scaleform::GFx::AS2::Value v8; // [rsp+38h] [rbp-30h]
  Scaleform::MemoryHeap *v9; // [rsp+78h] [rbp+10h]
  Scaleform::GFx::AS2::StringObject *v10; // [rsp+80h] [rbp+18h]

  v2 = penv;
  v3 = &penv->StringContext;
  v9 = penv->StringContext.pContext->pHeap;
  v4 = (Scaleform::GFx::AS2::StringObject *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::StringCtorFunction *, signed __int64))v9->vfptr->Alloc)(
                                              this,
                                              104i64);
  v10 = v4;
  if ( v4 )
  {
    Scaleform::GFx::AS2::StringObject::StringObject(v4, v2);
    v6 = v5;
  }
  else
  {
    v6 = 0i64;
  }
  v8.T.Type = 10;
  LOBYTE(v9) = 0;
  (*(void (__fastcall **)(__int64, Scaleform::GFx::AS2::ASStringContext *, char *, Scaleform::GFx::AS2::Value *, Scaleform::MemoryHeap **))(*(_QWORD *)(v6 + 32) + 80i64))(
    v6 + 32,
    v3,
    &v3->pContext->pMovieRoot->pASMovieRoot.pObject[38].AVMVersion,
    &v8,
    &v9);
  if ( v8.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v8);
  return (Scaleform::GFx::AS2::Object *)v6;
}

// File Line: 638
// RVA: 0x6FA100
void __usercall Scaleform::GFx::AS2::StringCtorFunction::GlobalCtor(Scaleform::GFx::AS2::FnCall *fn@<rcx>, __int64 a2@<rdx>, __int64 a3@<rdi>)
{
  Scaleform::GFx::AS2::FnCall *v3; // rbx
  Scaleform::GFx::AS2::Value *v4; // rsi
  Scaleform::GFx::AS2::ObjectInterface *v5; // rcx
  __int64 v6; // rdx
  Scaleform::GFx::AS2::ObjectInterface *v7; // rax
  Scaleform::GFx::AS2::Value *v8; // rax
  Scaleform::GFx::AS2::Value *v9; // rax
  __int64 v10; // rdi
  Scaleform::GFx::ASMovieRootBase *v11; // rcx
  Scaleform::GFx::ASStringNode *v12; // rax
  Scaleform::GFx::ASMovieRootBase *v13; // rdi
  Scaleform::GFx::AS2::Value *v14; // rbx
  Scaleform::GFx::ASStringNode *v15; // rax
  unsigned int v16; // er9
  Scaleform::GFx::AS2::Environment *v17; // r8
  Scaleform::GFx::ASString *v18; // rdi
  Scaleform::GFx::AS2::Value *v19; // rbx
  Scaleform::GFx::ASStringNode *v20; // rax
  Scaleform::GFx::ASStringNode *v21; // rcx
  bool v22; // zf
  Scaleform::GFx::AS2::Value v23; // [rsp+30h] [rbp-68h]
  Scaleform::GFx::AS2::Value v; // [rsp+50h] [rbp-48h]
  Scaleform::GFx::AS2::Value v25; // [rsp+70h] [rbp-28h]
  Scaleform::GFx::ASString result; // [rsp+A0h] [rbp+8h]

  v3 = fn;
  v4 = 0i64;
  v5 = fn->ThisPtr;
  if ( !v5
    || (*(unsigned int (__cdecl **)(Scaleform::GFx::AS2::ObjectInterface *, __int64))&v5->vfptr->gap8[8])(v5, a2) != 8
    || ((unsigned __int8 (__cdecl *)(Scaleform::GFx::AS2::ObjectInterface *, __int64))v3->ThisPtr->vfptr->IsBuiltinPrototype)(
         v3->ThisPtr,
         v6) )
  {
    if ( v3->NArgs )
    {
      v16 = v3->FirstArgBottomIndex;
      v17 = v3->Env;
      if ( v16 <= 32 * ((unsigned int)v17->Stack.Pages.Data.Size - 1)
                + (unsigned int)((_QWORD)((char *)v17->Stack.pCurrent - (char *)v17->Stack.pPageStart) >> 5) )
        v4 = &v17->Stack.Pages.Data.Data[v16 >> 5]->Values[v16 & 0x1F];
      v18 = Scaleform::GFx::AS2::Value::ToString(v4, &result, v17, -1);
      v19 = v3->Result;
      if ( v19->T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(v19);
      v19->T.Type = 5;
      v20 = v18->pNode;
      v19->NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)v18->pNode;
      ++v20->RefCount;
      v21 = result.pNode;
      v22 = result.pNode->RefCount == 1;
      --v21->RefCount;
      if ( v22 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v21);
    }
    else
    {
      v13 = v3->Env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject;
      v14 = v3->Result;
      if ( v14->T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(v14);
      v14->T.Type = 5;
      v15 = *(Scaleform::GFx::ASStringNode **)&v13[7].AVMVersion;
      v14->V.pStringNode = v15;
      ++v15->RefCount;
    }
  }
  else
  {
    v7 = v3->ThisPtr;
    if ( v7 )
      v4 = (Scaleform::GFx::AS2::Value *)&v7[-2];
    if ( v3->NArgs <= 0 )
    {
      v11 = v3->Env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject;
      v23.T.Type = 5;
      v12 = *(Scaleform::GFx::ASStringNode **)&v11[7].AVMVersion;
      v23.V.pStringNode = v12;
      ++v12->RefCount;
      v9 = &v23;
      v10 = 2i64;
    }
    else
    {
      v8 = Scaleform::GFx::AS2::FnCall::Arg(v3, 0);
      Scaleform::GFx::AS2::Value::Value(&v25, v8, a3);
      v10 = 1i64;
    }
    Scaleform::GFx::AS2::Value::Value(&v, v9, v10);
    if ( v10 & 2 )
    {
      v10 = (unsigned int)v10 & 0xFFFFFFFD;
      if ( v23.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v23);
    }
    if ( v10 & 1 )
    {
      v10 = (unsigned int)v10 & 0xFFFFFFFE;
      if ( v25.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v25);
    }
    (*(void (__fastcall **)(Scaleform::GFx::AS2::Value *, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::AS2::Value *))(*(_QWORD *)&v4->T.Type + 24i64))(
      v4,
      v3->Env,
      &v);
    Scaleform::GFx::AS2::Value::operator=(v3->Result, &v, v10);
    if ( v.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v);
  }
}

// File Line: 657
// RVA: 0x70ECB0
Scaleform::GFx::AS2::FunctionRef *__fastcall Scaleform::GFx::AS2::StringCtorFunction::Register(Scaleform::GFx::AS2::FunctionRef *result, Scaleform::GFx::AS2::GlobalContext *pgc)
{
  Scaleform::GFx::AS2::GlobalContext *v2; // r14
  Scaleform::GFx::AS2::FunctionRef *v3; // rdi
  Scaleform::GFx::AS2::Object *v4; // rax
  __int64 v5; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v6; // rbx
  Scaleform::GFx::AS2::Object *v7; // r15
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v8; // rcx
  unsigned int v9; // eax
  __int64 v10; // rbx
  Scaleform::GFx::AS2::Object *v11; // r15
  __int64 v12; // rax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v13; // rcx
  unsigned int v14; // eax
  Scaleform::MemoryHeap *v15; // r15
  Scaleform::GFx::ASSupport *v16; // rsi
  Scaleform::GFx::ASStringNode *v17; // rcx
  bool v18; // zf
  Scaleform::GFx::AS2::Object *v19; // rsi
  Scaleform::GFx::ASStringNode *v20; // rax
  Scaleform::GFx::AS2::LocalFrame *v21; // rdx
  int v22; // eax
  Scaleform::GFx::AS2::ASStringContext psc; // [rsp+48h] [rbp-38h]
  Scaleform::GFx::AS2::Value v25; // [rsp+58h] [rbp-28h]
  Scaleform::Ptr<Scaleform::GFx::AS2::Object> objproto; // [rsp+C8h] [rbp+48h]
  Scaleform::MemoryHeap *flags; // [rsp+D0h] [rbp+50h]
  Scaleform::Ptr<Scaleform::GFx::AS2::Object> *v28; // [rsp+D8h] [rbp+58h]

  v2 = pgc;
  v3 = result;
  psc.pContext = pgc;
  psc.SWFVersion = 8;
  flags = pgc->pHeap;
  v4 = (Scaleform::GFx::AS2::Object *)flags->vfptr->Alloc((Scaleform::MemoryHeap *)result, 104ui64, 0i64);
  v6 = (Scaleform::GFx::AS2::ObjectInterface *)v4;
  v28 = (Scaleform::Ptr<Scaleform::GFx::AS2::Object> *)v4;
  if ( v4 )
  {
    Scaleform::GFx::AS2::Object::Object(v4, &psc);
    v6->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::FunctionObject::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
    v6[2].vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::FunctionObject::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
    v6->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::CFunctionObject::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
    v6[2].vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::CFunctionObject::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
    v6[6].vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)Scaleform::GFx::AS2::StringCtorFunction::GlobalCtor;
    v7 = Scaleform::GFx::AS2::GlobalContext::GetPrototype(psc.pContext, ASBuiltin_Function);
    if ( !v6[2].pProto.pObject )
    {
      LOBYTE(objproto.pObject) = 3;
      v25.T.Type = 10;
      v6[2].vfptr->SetMemberRaw(
        v6 + 2,
        &psc,
        (Scaleform::GFx::ASString *)&psc.pContext->pMovieRoot->pASMovieRoot.pObject[23].pMovieImpl,
        &v25,
        (Scaleform::GFx::AS2::PropFlags *)&objproto);
      if ( v25.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v25);
    }
    if ( v7 )
      v7->RefCount = (v7->RefCount + 1) & 0x8FFFFFFF;
    v8 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v6[2].pProto.pObject->vfptr;
    if ( v8 )
    {
      v9 = v8->RefCount;
      if ( v9 & 0x3FFFFFF )
      {
        v8->RefCount = v9 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v8);
      }
    }
    v6[2].pProto.pObject = v7;
    v6->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::StringCtorFunction::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
    v6[2].vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::StringCtorFunction::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
    Scaleform::GFx::AS2::NameFunction::AddConstMembers(
      v6 + 2,
      &psc,
      Scaleform::GFx::AS2::StringCtorFunction::StaticFunctionTable,
      7);
  }
  else
  {
    v6 = 0i64;
  }
  v3->Flags = 0;
  v3->Function = (Scaleform::GFx::AS2::FunctionObject *)v6;
  v3->pLocalFrame = 0i64;
  v28 = (Scaleform::Ptr<Scaleform::GFx::AS2::Object> *)v2->pHeap;
  v10 = ((__int64 (__fastcall *)(__int64, signed __int64, _QWORD))v28->pObject->pWatchpoints)(v5, 168i64, 0i64);
  if ( v10 )
  {
    v11 = Scaleform::GFx::AS2::GlobalContext::GetPrototype(v2, ASBuiltin_Object);
    Scaleform::GFx::AS2::Object::Object((Scaleform::GFx::AS2::Object *)v10, &psc);
    *(_QWORD *)v10 = &Scaleform::GFx::AS2::StringObject::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
    *(_QWORD *)(v10 + 32) = &Scaleform::GFx::AS2::StringObject::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
    v12 = *(_QWORD *)&psc.pContext->pMovieRoot->pASMovieRoot.pObject[7].AVMVersion;
    *(_QWORD *)(v10 + 96) = v12;
    ++*(_DWORD *)(v12 + 24);
    if ( !*(_QWORD *)(v10 + 40) )
    {
      LOBYTE(objproto.pObject) = 3;
      v25.T.Type = 10;
      (*(void (__fastcall **)(__int64, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::MovieImpl **, Scaleform::GFx::AS2::Value *, Scaleform::Ptr<Scaleform::GFx::AS2::Object> *))(*(_QWORD *)(v10 + 32) + 80i64))(
        v10 + 32,
        &psc,
        &psc.pContext->pMovieRoot->pASMovieRoot.pObject[23].pMovieImpl,
        &v25,
        &objproto);
      if ( v25.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v25);
    }
    if ( v11 )
      v11->RefCount = (v11->RefCount + 1) & 0x8FFFFFFF;
    v13 = *(Scaleform::GFx::AS2::RefCountBaseGC<323> **)(v10 + 40);
    if ( v13 )
    {
      v14 = v13->RefCount;
      if ( v14 & 0x3FFFFFF )
      {
        v13->RefCount = v14 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v13);
      }
    }
    *(_QWORD *)(v10 + 40) = v11;
    v15 = (Scaleform::MemoryHeap *)(v10 + 104);
    flags = v15;
    v15->vfptr = (Scaleform::MemoryHeapVtbl *)&Scaleform::GFx::AS2::GASPrototypeBase::`vftable;
    LOBYTE(v15->SelfSize) = 0;
    v15->pPrev = 0i64;
    v15->pNext = 0i64;
    *(_BYTE *)(v10 + 152) = 0;
    *(_QWORD *)(v10 + 136) = 0i64;
    *(_QWORD *)(v10 + 144) = 0i64;
    *(_QWORD *)(v10 + 160) = 0i64;
    *(_QWORD *)v10 = &Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::StringObject,Scaleform::GFx::AS2::Environment>::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
    *(_QWORD *)(v10 + 32) = &Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::StringObject,Scaleform::GFx::AS2::Environment>::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
    v15->vfptr = (Scaleform::MemoryHeapVtbl *)&Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::StringObject,Scaleform::GFx::AS2::Environment>::`vftable;
    Scaleform::GFx::AS2::GASPrototypeBase::Init(
      (Scaleform::GFx::AS2::GASPrototypeBase *)(v10 + 104),
      (Scaleform::GFx::AS2::Object *)v10,
      &psc,
      v3);
    *(_QWORD *)v10 = &Scaleform::GFx::AS2::StringProto::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
    *(_QWORD *)(v10 + 32) = &Scaleform::GFx::AS2::StringProto::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
    v15->vfptr = (Scaleform::MemoryHeapVtbl *)&Scaleform::GFx::AS2::StringProto::`vftable;
    v16 = psc.pContext->pMovieRoot->pASMovieRoot.pObject[24].pASSupport.pObject;
    ++LODWORD(v16[1].vfptr);
    v17 = *(Scaleform::GFx::ASStringNode **)(v10 + 96);
    v18 = v17->RefCount-- == 1;
    if ( v18 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v17);
    *(_QWORD *)(v10 + 96) = v16;
    LOBYTE(flags) = 1;
    Scaleform::GFx::AS2::GASPrototypeBase::InitFunctionMembers(
      (Scaleform::GFx::AS2::GASPrototypeBase *)(v10 + 104),
      (Scaleform::GFx::AS2::Object *)v10,
      &psc,
      GAS_StringFunctionTable,
      (Scaleform::GFx::AS2::PropFlags *)&flags);
  }
  else
  {
    v10 = 0i64;
  }
  flags = (Scaleform::MemoryHeap *)v10;
  v28 = &objproto;
  if ( v10 )
    *(_DWORD *)(v10 + 24) = (*(_DWORD *)(v10 + 24) + 1) & 0x8FFFFFFF;
  objproto.pObject = (Scaleform::GFx::AS2::Object *)v10;
  Scaleform::GFx::AS2::GlobalContext::SetPrototype(
    v2,
    ASBuiltin_String,
    (Scaleform::Ptr<Scaleform::GFx::AS2::Object>)&objproto);
  v19 = v2->pGlobal.pObject;
  v25.T.Type = 8;
  v25.V.FunctionValue.Flags = 0;
  v20 = (Scaleform::GFx::ASStringNode *)v3->Function;
  v25.V.pStringNode = v20;
  if ( v20 )
  {
    ++v20->RefCount;
    v20->RefCount &= 0x8FFFFFFF;
  }
  v25.V.FunctionValue.pLocalFrame = 0i64;
  v21 = v3->pLocalFrame;
  if ( v21 )
    Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(
      (Scaleform::GFx::AS2::FunctionRefBase *)&v25.NV.8,
      v21,
      v3->Flags & 1);
  LOBYTE(objproto.pObject) = 0;
  v19->vfptr->SetMemberRaw(
    (Scaleform::GFx::AS2::ObjectInterface *)&v19->vfptr,
    &psc,
    (Scaleform::GFx::ASString *)&v2->pMovieRoot->pASMovieRoot.pObject[8].pMovieImpl,
    &v25,
    (Scaleform::GFx::AS2::PropFlags *)&objproto);
  if ( v25.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v25);
  if ( v10 )
  {
    v22 = *(_DWORD *)(v10 + 24);
    if ( v22 & 0x3FFFFFF )
    {
      *(_DWORD *)(v10 + 24) = v22 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v10);
    }
  }
  return v3;
}

