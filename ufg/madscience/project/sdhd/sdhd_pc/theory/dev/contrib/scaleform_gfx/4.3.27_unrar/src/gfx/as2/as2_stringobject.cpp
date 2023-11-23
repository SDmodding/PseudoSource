// File Line: 29
// RVA: 0x6CBCF0
void __fastcall Scaleform::GFx::AS2::StringObject::StringObject(
        Scaleform::GFx::AS2::StringObject *this,
        Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::ASStringNode *v4; // r8
  Scaleform::GFx::AS2::Object *Prototype; // rax

  Scaleform::GFx::AS2::Object::Object(this, penv);
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::StringObject::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::StringObject::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  v4 = *(Scaleform::GFx::ASStringNode **)&penv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[7].AVMVersion;
  this->sValue.pNode = v4;
  ++v4->RefCount;
  Prototype = Scaleform::GFx::AS2::GlobalContext::GetPrototype(penv->StringContext.pContext, ASBuiltin_String);
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr->Set__proto__(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    &penv->StringContext,
    Prototype);
}

// File Line: 45
// RVA: 0x6F6A30
Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *__fastcall Scaleform::GFx::AS2::StringObject::GetTextValue(
        Scaleform::GFx::AS2::StringObject *this,
        Scaleform::GFx::AS2::Environment *__formal)
{
  return this->ResolveHandler.pLocalFrame->vfptr;
}

// File Line: 50
// RVA: 0x6F3FE0
bool __fastcall Scaleform::GFx::AS2::StringObject::GetMemberRaw(
        Scaleform::GFx::AS2::StringObject *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS2::Value *val)
{
  Scaleform::GFx::ASMovieRootBase *pObject; // rsi
  bool v9; // zf
  int Length; // edi

  pObject = psc->pContext->pMovieRoot->pASMovieRoot.pObject;
  if ( psc->SWFVersion <= 6u )
  {
    if ( !name->pNode->pLower )
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(name->pNode);
    v9 = *(Scaleform::GFx::ASStringNode **)(*(_QWORD *)&pObject[38].AVMVersion + 16i64) == name->pNode->pLower;
  }
  else
  {
    v9 = *(Scaleform::GFx::ASStringNode **)&pObject[38].AVMVersion == name->pNode;
  }
  if ( !v9 )
    return Scaleform::GFx::AS2::Object::GetMemberRaw(this, psc, name, val) != 0;
  if ( !Scaleform::GFx::AS2::Object::GetMemberRaw(this, psc, name, val) || val->T.Type == 10 )
  {
    Length = Scaleform::GFx::ASConstString::GetLength((Scaleform::GFx::ASConstString *)&this->ResolveHandler.pLocalFrame);
    if ( val->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(val);
    val->T.Type = 4;
    val->NV.Int32Value = Length;
  }
  return 1;
}

// File Line: 66
// RVA: 0x71D190
void __fastcall Scaleform::GFx::AS2::StringObject::SetValue(
        Scaleform::GFx::AS2::StringObject *this,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::AS2::Value *v)
{
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::ASString result; // [rsp+40h] [rbp+8h] BYREF

  Scaleform::GFx::AS2::Value::ToString(v, &result, penv, -1);
  Scaleform::GFx::ASString::operator=(&this->sValue, result.pNode->pData);
  pNode = result.pNode;
  if ( result.pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}

// File Line: 72
// RVA: 0x6F7360
Scaleform::GFx::AS2::Value *__fastcall Scaleform::GFx::AS2::StringObject::GetValue(
        Scaleform::GFx::AS2::StringObject *this,
        Scaleform::GFx::AS2::Value *result)
{
  Scaleform::GFx::ASStringNode *pNode; // rax

  result->T.Type = 5;
  pNode = this->sValue.pNode;
  result->V.pStringNode = pNode;
  ++pNode->RefCount;
  return result;
}

// File Line: 79
// RVA: 0x6AFC80
void __fastcall Scaleform::GFx::AS2::StringProto::StringCharAt(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rax
  Scaleform::GFx::AS2::Value *v4; // r9
  Scaleform::GFx::ASConstString *v5; // rax
  Scaleform::GFx::ASConstString *v6; // rsi
  unsigned int FirstArgBottomIndex; // r10d
  Scaleform::GFx::AS2::Environment *Env; // rdx
  signed int v9; // edi
  unsigned int CharAt; // eax
  Scaleform::GFx::ASString *appended; // rax
  Scaleform::GFx::ASStringNode *pNode; // rdi
  Scaleform::GFx::ASStringNode *v13; // rcx
  bool v14; // zf
  Scaleform::GFx::ASStringNode *v15; // rcx
  Scaleform::GFx::AS2::Value *v16; // rbx
  Scaleform::GFx::ASStringNode *v17; // rcx
  Scaleform::GFx::ASString v18; // [rsp+40h] [rbp+8h] BYREF
  Scaleform::GFx::ASString result; // [rsp+48h] [rbp+10h] BYREF

  ThisPtr = fn->ThisPtr;
  if ( ThisPtr
    && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(ThisPtr) == 8 )
  {
    v3 = fn->ThisPtr;
    v4 = 0i64;
    if ( v3 )
      v5 = (Scaleform::GFx::ASConstString *)&v3[-2];
    else
      v5 = 0i64;
    v6 = v5 + 12;
    v18.pNode = *(Scaleform::GFx::ASStringNode **)&fn->Env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[7].AVMVersion;
    ++v18.pNode->RefCount;
    FirstArgBottomIndex = fn->FirstArgBottomIndex;
    Env = fn->Env;
    if ( FirstArgBottomIndex <= 32 * ((unsigned int)Env->Stack.Pages.Data.Size - 1)
                              + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
      v4 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
    v9 = (int)Scaleform::GFx::AS2::Value::ToNumber(v4, Env);
    if ( v9 >= 0 && v9 < (int)Scaleform::GFx::ASConstString::GetLength(v6) )
    {
      CharAt = Scaleform::GFx::ASConstString::GetCharAt(v6, v9);
      appended = Scaleform::GFx::ASString::AppendChar(&v18, &result, CharAt);
      pNode = appended->pNode;
      ++appended->pNode->RefCount;
      v13 = v18.pNode;
      v14 = v18.pNode->RefCount-- == 1;
      if ( v14 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v13);
      v18.pNode = pNode;
      v15 = result.pNode;
      v14 = result.pNode->RefCount-- == 1;
      if ( v14 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v15);
    }
    v16 = fn->Result;
    if ( v16->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(v16);
    v16->T.Type = 5;
    v16->NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)v18.pNode;
    ++v18.pNode->RefCount;
    v17 = v18.pNode;
    v14 = v18.pNode->RefCount-- == 1;
    if ( v14 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v17);
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      fn->Env,
      "Error: Null or invalid this is used for a method of %s class.\n",
      "String");
  }
}

// File Line: 96
// RVA: 0x6AFFD0
void __fastcall Scaleform::GFx::AS2::StringProto::StringCharCodeAt(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rax
  Scaleform::GFx::AS2::Value *v4; // r9
  Scaleform::GFx::ASConstString *v5; // rax
  Scaleform::GFx::ASConstString *v6; // rsi
  Scaleform::GFx::AS2::Environment *Env; // rdx
  unsigned __int64 FirstArgBottomIndex; // r8
  signed int v9; // edi
  int CharAt; // eax
  double v11; // xmm0_8
  Scaleform::GFx::AS2::Value *Result; // rbx

  ThisPtr = fn->ThisPtr;
  if ( ThisPtr
    && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(ThisPtr) == 8 )
  {
    v3 = fn->ThisPtr;
    v4 = 0i64;
    if ( v3 )
      v5 = (Scaleform::GFx::ASConstString *)&v3[-2];
    else
      v5 = 0i64;
    v6 = v5 + 12;
    if ( fn->NArgs < 1 )
      goto LABEL_12;
    Env = fn->Env;
    FirstArgBottomIndex = (unsigned int)fn->FirstArgBottomIndex;
    if ( (unsigned int)FirstArgBottomIndex <= 32 * (LODWORD(Env->Stack.Pages.Data.Size) - 1)
                                            + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
      v4 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[fn->FirstArgBottomIndex & 0x1F];
    v9 = (int)Scaleform::GFx::AS2::Value::ToNumber(v4, Env);
    if ( v9 < 0 || v9 >= (int)Scaleform::GFx::ASConstString::GetLength(v6) )
    {
LABEL_12:
      v11 = Scaleform::GFx::NumberUtil::NaN();
      Result = fn->Result;
      if ( Result->T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(Result);
      Result->NV.NumberValue = v11;
      Result->T.Type = 3;
    }
    else
    {
      CharAt = Scaleform::GFx::ASConstString::GetCharAt(v6, v9);
      Scaleform::GFx::AS2::Value::SetNumber(fn->Result, (double)CharAt);
    }
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      fn->Env,
      "Error: Null or invalid this is used for a method of %s class.\n",
      "String");
  }
}

// File Line: 116
// RVA: 0x6B0180
void __fastcall Scaleform::GFx::AS2::StringProto::StringConcat(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rax
  int i; // ebx
  unsigned int v5; // r9d
  Scaleform::GFx::AS2::Environment *Env; // r8
  Scaleform::GFx::AS2::Value *v7; // r10
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v9; // zf
  char *pData; // r8
  Scaleform::GFx::ASString *v11; // rsi
  Scaleform::GFx::AS2::Value *v12; // rbx
  Scaleform::GFx::ASStringNode *v13; // rax
  Scaleform::GFx::ASStringNode *v14; // rcx
  Scaleform::StringBuffer v15; // [rsp+28h] [rbp-40h] BYREF
  Scaleform::GFx::ASString result; // [rsp+70h] [rbp+8h] BYREF

  ThisPtr = fn->ThisPtr;
  if ( ThisPtr
    && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(ThisPtr) == 8 )
  {
    v3 = fn->ThisPtr;
    if ( v3 )
      v3 -= 2;
    Scaleform::StringBuffer::StringBuffer(
      &v15,
      (const char *)v3[6].vfptr->__vecDelDtor,
      LODWORD(v3[6].vfptr->GetMember),
      Scaleform::Memory::pGlobalHeap);
    for ( i = 0; i < fn->NArgs; ++i )
    {
      v5 = fn->FirstArgBottomIndex - i;
      Env = fn->Env;
      v7 = 0i64;
      if ( v5 <= 32 * ((unsigned int)Env->Stack.Pages.Data.Size - 1)
               + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
        v7 = &Env->Stack.Pages.Data.Data[v5 >> 5]->Values[v5 & 0x1F];
      Scaleform::GFx::AS2::Value::ToString(v7, &result, Env, -1);
      Scaleform::StringBuffer::AppendString(&v15, result.pNode->pData, -1i64);
      pNode = result.pNode;
      v9 = result.pNode->RefCount-- == 1;
      if ( v9 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    }
    pData = &customCaption;
    if ( v15.pData )
      pData = v15.pData;
    v11 = Scaleform::GFx::AS2::Environment::CreateString(fn->Env, &result, pData, v15.Size);
    v12 = fn->Result;
    if ( v12->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(fn->Result);
    v12->T.Type = 5;
    v13 = v11->pNode;
    v12->NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)v11->pNode;
    ++v13->RefCount;
    v14 = result.pNode;
    v9 = result.pNode->RefCount-- == 1;
    if ( v9 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v14);
    Scaleform::ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayDataBase<int,Scaleform::AllocatorGH<int,2>,Scaleform::ArrayDefaultPolicy> *)&v15);
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      fn->Env,
      "Error: Null or invalid this is used for a method of %s class.\n",
      "String");
  }
}

// File Line: 134
// RVA: 0x6B0490
void __fastcall Scaleform::GFx::AS2::StringProto::StringIndexOf(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rax
  signed int v4; // edi
  Scaleform::GFx::AS2::ObjectInterface *v5; // rbx
  Scaleform::GFx::AS2::Value *v6; // rbx
  unsigned int FirstArgBottomIndex; // r9d
  Scaleform::GFx::AS2::Environment *Env; // r8
  Scaleform::GFx::AS2::Value *v9; // r10
  Scaleform::GFx::AS2::Value *v10; // rbx
  int v11; // r14d
  Scaleform::GFx::AS2::Value *v12; // rax
  unsigned int Char_Advance0; // ebp
  unsigned int v14; // eax
  unsigned int v15; // ebx
  unsigned int v16; // eax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::ASString result; // [rsp+20h] [rbp-38h] BYREF
  __int64 v20; // [rsp+28h] [rbp-30h]
  char *putf8Buffer; // [rsp+60h] [rbp+8h] BYREF
  char *vecDelDtor; // [rsp+68h] [rbp+10h] BYREF
  char *v23; // [rsp+70h] [rbp+18h] BYREF
  char *v24; // [rsp+78h] [rbp+20h] BYREF

  v20 = -2i64;
  ThisPtr = fn->ThisPtr;
  if ( ThisPtr
    && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(ThisPtr) == 8 )
  {
    v3 = fn->ThisPtr;
    v4 = 0;
    v5 = v3 - 2;
    if ( !v3 )
      v5 = 0i64;
    if ( fn->NArgs >= 1 )
    {
      FirstArgBottomIndex = fn->FirstArgBottomIndex;
      Env = fn->Env;
      v9 = 0i64;
      if ( FirstArgBottomIndex <= 32 * ((unsigned int)Env->Stack.Pages.Data.Size - 1)
                                + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
        v9 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
      Scaleform::GFx::AS2::Value::ToString(v9, &result, Env, -1);
      if ( Scaleform::GFx::ASConstString::GetLength(&result) )
      {
        putf8Buffer = (char *)result.pNode->pData;
        vecDelDtor = (char *)v5[6].vfptr->__vecDelDtor;
        v11 = 0;
        if ( fn->NArgs > 1 )
        {
          v12 = Scaleform::GFx::AS2::FnCall::Arg(fn, 1);
          v11 = (int)Scaleform::GFx::AS2::Value::ToNumber(v12, fn->Env);
        }
        Char_Advance0 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&putf8Buffer);
        if ( !Char_Advance0 )
          --putf8Buffer;
        while ( 1 )
        {
          v14 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&vecDelDtor);
          if ( !v14 )
          {
            --vecDelDtor;
            v10 = fn->Result;
            if ( v10->T.Type >= 5u )
              Scaleform::GFx::AS2::Value::DropRefs(fn->Result);
            v10->V.pStringNode = (Scaleform::GFx::ASStringNode *)0xBFF0000000000000i64;
            goto LABEL_38;
          }
          if ( v4 >= v11 && v14 == Char_Advance0 )
            break;
LABEL_32:
          ++v4;
        }
        v23 = vecDelDtor;
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
          Scaleform::GFx::AS2::Value::SetInt(fn->Result, v4);
          goto LABEL_39;
        }
        if ( v15 )
          goto LABEL_32;
        Scaleform::GFx::AS2::Value::SetInt(fn->Result, 0xFFFFFFFF);
      }
      else
      {
        v10 = fn->Result;
        if ( v10->T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(fn->Result);
        v10->V.pStringNode = 0i64;
LABEL_38:
        v10->T.Type = 3;
      }
LABEL_39:
      pNode = result.pNode;
      if ( result.pNode->RefCount-- == 1 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    }
    else
    {
      v6 = fn->Result;
      if ( v6->T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(fn->Result);
      v6->T.Type = 3;
      v6->V.pStringNode = (Scaleform::GFx::ASStringNode *)0xBFF0000000000000i64;
    }
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      fn->Env,
      "Error: Null or invalid this is used for a method of %s class.\n",
      "String");
  }
}

// File Line: 199
// RVA: 0x6B0770
void __fastcall Scaleform::GFx::AS2::StringProto::StringLastIndexOf(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rax
  int v4; // edi
  Scaleform::GFx::AS2::ObjectInterface *v5; // rax
  Scaleform::GFx::AS2::Value *v6; // rbx
  unsigned int FirstArgBottomIndex; // r9d
  Scaleform::GFx::AS2::Environment *Env; // r8
  Scaleform::GFx::AS2::Value *v9; // r10
  int v10; // r14d
  double Length; // xmm6_8
  Scaleform::GFx::AS2::Value *v12; // rbx
  int v13; // r12d
  Scaleform::GFx::AS2::Value *v14; // rax
  unsigned int Char_Advance0; // r15d
  unsigned int v16; // eax
  unsigned int v17; // ebx
  unsigned int v18; // eax
  Scaleform::GFx::AS2::Value *v19; // rbx
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v21; // zf
  Scaleform::GFx::ASStringNode *v22; // rcx
  Scaleform::GFx::ASString result; // [rsp+20h] [rbp-30h] BYREF
  Scaleform::GFx::ASConstString v24; // [rsp+28h] [rbp-28h] BYREF
  __int64 v25; // [rsp+30h] [rbp-20h]
  char *putf8Buffer; // [rsp+90h] [rbp+40h] BYREF
  char *pData; // [rsp+98h] [rbp+48h] BYREF
  char *v28; // [rsp+A0h] [rbp+50h] BYREF
  char *v29; // [rsp+A8h] [rbp+58h] BYREF

  v25 = -2i64;
  ThisPtr = fn->ThisPtr;
  if ( ThisPtr
    && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(ThisPtr) == 8 )
  {
    v3 = fn->ThisPtr;
    v4 = 0;
    if ( v3 )
      v5 = v3 - 2;
    else
      v5 = 0i64;
    if ( fn->NArgs >= 1 )
    {
      v24.pNode = (Scaleform::GFx::ASStringNode *)v5[6].vfptr;
      ++v24.pNode->RefCount;
      FirstArgBottomIndex = fn->FirstArgBottomIndex;
      Env = fn->Env;
      v9 = 0i64;
      if ( FirstArgBottomIndex <= 32 * ((unsigned int)Env->Stack.Pages.Data.Size - 1)
                                + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
        v9 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
      v10 = -1;
      Scaleform::GFx::AS2::Value::ToString(v9, &result, Env, -1);
      if ( Scaleform::GFx::ASConstString::GetLength(&result) )
      {
        pData = (char *)v24.pNode->pData;
        putf8Buffer = (char *)result.pNode->pData;
        v13 = 0x7FFFFFF;
        if ( fn->NArgs > 1 )
        {
          v14 = Scaleform::GFx::AS2::FnCall::Arg(fn, 1);
          v13 = (int)Scaleform::GFx::AS2::Value::ToNumber(v14, fn->Env);
        }
        Char_Advance0 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&putf8Buffer);
        if ( !Char_Advance0 )
          --putf8Buffer;
        while ( 1 )
        {
          v16 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&pData);
          if ( !v16 )
            break;
          if ( v4 <= v13 && v16 == Char_Advance0 )
          {
            v28 = pData;
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
        --pData;
LABEL_36:
        v19 = fn->Result;
        if ( v19->T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(fn->Result);
        v19->T.Type = 4;
        v19->NV.Int32Value = v10;
      }
      else
      {
        Length = (double)(int)Scaleform::GFx::ASConstString::GetLength(&v24);
        v12 = fn->Result;
        if ( v12->T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(fn->Result);
        v12->T.Type = 3;
        v12->NV.NumberValue = Length;
      }
      pNode = result.pNode;
      v21 = result.pNode->RefCount-- == 1;
      if ( v21 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      v22 = v24.pNode;
      v21 = v24.pNode->RefCount-- == 1;
      if ( v21 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v22);
    }
    else
    {
      v6 = fn->Result;
      if ( v6->T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(fn->Result);
      v6->T.Type = 3;
      v6->V.pStringNode = (Scaleform::GFx::ASStringNode *)0xBFF0000000000000i64;
    }
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      fn->Env,
      "Error: Null or invalid this is used for a method of %s class.\n",
      "String");
  }
}

// File Line: 264
// RVA: 0x6B0DB0
void __fastcall Scaleform::GFx::AS2::StringProto::StringSlice(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // r14
  Scaleform::GFx::AS2::Value *v4; // rbp
  Scaleform::GFx::ASString *v5; // r14
  int v6; // esi
  int v7; // edi
  unsigned int FirstArgBottomIndex; // r10d
  Scaleform::GFx::AS2::Environment *Env; // rdx
  Scaleform::GFx::AS2::Value *v10; // r9
  unsigned int v11; // r9d
  Scaleform::GFx::AS2::Environment *v12; // rdx
  int v13; // edi
  Scaleform::GFx::ASMovieRootBase *pObject; // rdi
  Scaleform::GFx::AS2::Value *v15; // rbx
  Scaleform::GFx::ASStringNode *v16; // rax
  Scaleform::GFx::ASString *v17; // rdi
  Scaleform::GFx::AS2::Value *v18; // rbx
  Scaleform::GFx::ASStringNode *pNode; // rax
  Scaleform::GFx::ASStringNode *v20; // rcx
  Scaleform::GFx::ASString result; // [rsp+50h] [rbp+8h] BYREF

  ThisPtr = fn->ThisPtr;
  if ( !ThisPtr
    || (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(ThisPtr) != 8 )
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      fn->Env,
      "Error: Null or invalid this is used for a method of %s class.\n",
      "String");
    return;
  }
  v3 = fn->ThisPtr;
  v4 = 0i64;
  if ( v3 )
    v5 = (Scaleform::GFx::ASString *)&v3[-2];
  else
    v5 = 0i64;
  v6 = 0;
  v7 = -1;
  if ( fn->NArgs >= 1 )
  {
    FirstArgBottomIndex = fn->FirstArgBottomIndex;
    Env = fn->Env;
    v10 = 0i64;
    if ( FirstArgBottomIndex <= 32 * ((unsigned int)Env->Stack.Pages.Data.Size - 1)
                              + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
      v10 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
    v6 = (int)Scaleform::GFx::AS2::Value::ToNumber(v10, Env);
    if ( v6 < 0 )
      v6 += Scaleform::GFx::ASConstString::GetLength(v5 + 12);
  }
  if ( fn->NArgs >= 2 )
  {
    v11 = fn->FirstArgBottomIndex - 1;
    v12 = fn->Env;
    if ( v11 <= 32 * ((unsigned int)v12->Stack.Pages.Data.Size - 1)
              + (unsigned int)(v12->Stack.pCurrent - v12->Stack.pPageStart) )
      v4 = &v12->Stack.Pages.Data.Data[v11 >> 5]->Values[v11 & 0x1F];
    v13 = (int)Scaleform::GFx::AS2::Value::ToNumber(v4, v12);
    if ( v13 < 0 )
      v13 += Scaleform::GFx::ASConstString::GetLength(v5 + 12);
    if ( v13 < v6 )
    {
      pObject = fn->Env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject;
      v15 = fn->Result;
      if ( v15->T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(v15);
      v15->T.Type = 5;
      v16 = *(Scaleform::GFx::ASStringNode **)&pObject[7].AVMVersion;
      v15->V.pStringNode = v16;
      ++v16->RefCount;
      return;
    }
    v7 = v13 - v6;
  }
  v17 = Scaleform::GFx::AS2::StringProto::StringSubstring(&result, v5 + 12, v6, v7);
  v18 = fn->Result;
  if ( v18->T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(v18);
  v18->T.Type = 5;
  pNode = v17->pNode;
  v18->NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)v17->pNode;
  ++pNode->RefCount;
  v20 = result.pNode;
  if ( result.pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v20);
}

// File Line: 293
// RVA: 0x6B1010
void __fastcall Scaleform::GFx::AS2::StringProto::StringSplit(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rax
  Scaleform::GFx::ASString *v4; // rbp
  Scaleform::GFx::ASStringNode *v5; // rbx
  const char *v6; // rsi
  unsigned int FirstArgBottomIndex; // r9d
  Scaleform::GFx::AS2::Environment *Env; // r8
  Scaleform::GFx::AS2::Value *v9; // r10
  Scaleform::GFx::ASString *v10; // rax
  const char **p_pData; // rsi
  bool v12; // zf
  Scaleform::GFx::ASStringNode *pNode; // rcx
  int limit; // eax
  unsigned int v15; // r9d
  Scaleform::GFx::AS2::Environment *v16; // rdx
  Scaleform::GFx::AS2::Value *v17; // r10
  Scaleform::GFx::AS2::ArrayObject *pObject; // rcx
  unsigned int RefCount; // eax
  Scaleform::Ptr<Scaleform::GFx::AS2::ArrayObject> v20; // [rsp+70h] [rbp+8h] BYREF
  Scaleform::GFx::ASStringNode *v21; // [rsp+78h] [rbp+10h]
  Scaleform::GFx::ASString result; // [rsp+80h] [rbp+18h] BYREF

  ThisPtr = fn->ThisPtr;
  if ( ThisPtr
    && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(ThisPtr) == 8 )
  {
    v3 = fn->ThisPtr;
    v4 = (Scaleform::GFx::ASString *)&v3[-2];
    if ( !v3 )
      v4 = 0i64;
    v5 = *(Scaleform::GFx::ASStringNode **)&fn->Env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[7].AVMVersion;
    v21 = v5;
    ++v5->RefCount;
    v6 = 0i64;
    if ( fn->NArgs >= 1 )
    {
      FirstArgBottomIndex = fn->FirstArgBottomIndex;
      Env = fn->Env;
      v9 = 0i64;
      if ( FirstArgBottomIndex <= 32 * ((unsigned int)Env->Stack.Pages.Data.Size - 1)
                                + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
        v9 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
      v10 = Scaleform::GFx::AS2::Value::ToString(v9, &result, Env, -1);
      p_pData = &v10->pNode->pData;
      ++v10->pNode->RefCount;
      v12 = v5->RefCount-- == 1;
      if ( v12 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v5);
      v5 = (Scaleform::GFx::ASStringNode *)p_pData;
      v21 = (Scaleform::GFx::ASStringNode *)p_pData;
      pNode = result.pNode;
      v12 = result.pNode->RefCount-- == 1;
      if ( v12 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      v6 = *p_pData;
    }
    limit = 0x3FFFFFFF;
    if ( fn->NArgs >= 2 )
    {
      v15 = fn->FirstArgBottomIndex - 1;
      v16 = fn->Env;
      v17 = 0i64;
      if ( v15 <= 32 * ((unsigned int)v16->Stack.Pages.Data.Size - 1)
                + (unsigned int)(v16->Stack.pCurrent - v16->Stack.pPageStart) )
        v17 = &v16->Stack.Pages.Data.Data[v15 >> 5]->Values[v15 & 0x1F];
      limit = (int)Scaleform::GFx::AS2::Value::ToNumber(v17, v16);
      if ( limit < 0 )
        limit = 0;
    }
    Scaleform::GFx::AS2::StringProto::StringSplit(&v20, fn->Env, v4 + 12, v6, limit);
    Scaleform::GFx::AS2::Value::SetAsObject(fn->Result, v20.pObject);
    pObject = v20.pObject;
    if ( v20.pObject )
    {
      RefCount = v20.pObject->RefCount;
      if ( (RefCount & 0x3FFFFFF) != 0 )
      {
        v20.pObject->RefCount = RefCount - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pObject);
      }
    }
    v12 = v5->RefCount-- == 1;
    if ( v12 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v5);
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      fn->Env,
      "Error: Null or invalid this is used for a method of %s class.\n",
      "String");
  }
}

// File Line: 319
// RVA: 0x720BB0
Scaleform::Ptr<Scaleform::GFx::AS2::ArrayObject> *__fastcall Scaleform::GFx::AS2::StringProto::StringSplit(
        Scaleform::Ptr<Scaleform::GFx::AS2::ArrayObject> *result,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::ASString *str,
        Scaleform::String::DataDesc *delimiters,
        int limit)
{
  char *v5; // r14
  Scaleform::GFx::AS2::ASStringContext *p_StringContext; // rsi
  Scaleform::GFx::ASStringNode *pNode; // rcx
  char *pData; // rax
  int v11; // edx
  unsigned int v12; // edi
  Scaleform::GFx::ASString *v13; // rax
  Scaleform::GFx::ASStringNode *v14; // rcx
  bool v15; // zf
  int v16; // r15d
  const char *v17; // r12
  char *v18; // rbx
  char *v19; // r14
  unsigned int Char_Advance0; // esi
  unsigned int v21; // edi
  Scaleform::GFx::ASStringNode *v22; // rbx
  Scaleform::GFx::ASString *v23; // rax
  Scaleform::GFx::ASStringNode *v24; // rcx
  Scaleform::GFx::ASString *StringFromCStr; // rax
  Scaleform::GFx::ASStringNode *v26; // rcx
  Scaleform::GFx::ASString *v27; // rax
  Scaleform::GFx::AS2::ASStringContext *psc; // [rsp+30h] [rbp-D0h] BYREF
  Scaleform::GFx::ASString resulta; // [rsp+38h] [rbp-C8h] BYREF
  int v31; // [rsp+40h] [rbp-C0h]
  Scaleform::GFx::ASString v32; // [rsp+48h] [rbp-B8h] BYREF
  Scaleform::GFx::ASString v33; // [rsp+50h] [rbp-B0h] BYREF
  Scaleform::GFx::AS2::Value val; // [rsp+58h] [rbp-A8h] BYREF
  Scaleform::GFx::AS2::Value v35; // [rsp+78h] [rbp-88h] BYREF
  Scaleform::GFx::AS2::Value v36; // [rsp+98h] [rbp-68h] BYREF
  Scaleform::GFx::AS2::Value v37; // [rsp+B8h] [rbp-48h] BYREF
  Scaleform::GFx::AS2::Value v38; // [rsp+D8h] [rbp-28h] BYREF
  __int64 v39; // [rsp+F8h] [rbp-8h]
  char *putf8Buffer; // [rsp+158h] [rbp+58h] BYREF
  char *v41; // [rsp+160h] [rbp+60h] BYREF
  Scaleform::String stra; // [rsp+168h] [rbp+68h] BYREF

  stra.pData = delimiters;
  v39 = -2i64;
  v5 = (char *)delimiters;
  v31 = 0;
  p_StringContext = &penv->StringContext;
  psc = &penv->StringContext;
  result->pObject = (Scaleform::GFx::AS2::ArrayObject *)Scaleform::GFx::AS2::Environment::OperatorNew(
                                                          penv,
                                                          penv->StringContext.pContext->pGlobal.pObject,
                                                          (Scaleform::GFx::ASString *)&penv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[8].RefCount,
                                                          0,
                                                          -1);
  v31 = 1;
  pNode = str->pNode;
  pData = (char *)str->pNode->pData;
  putf8Buffer = pData;
  v11 = limit;
  if ( limit < 0 )
    v11 = 0;
  limit = v11;
  if ( v5 )
  {
    if ( *v5 )
    {
      v16 = 0;
      v17 = pData;
      do
      {
        v41 = v5;
        resulta.pNode = (Scaleform::GFx::ASStringNode *)pData;
        v18 = 0i64;
        while ( 1 )
        {
          v19 = pData;
          Char_Advance0 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&putf8Buffer);
          if ( !Char_Advance0 )
            --putf8Buffer;
          v21 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&v41);
          if ( !v21 )
            --v41;
          pData = putf8Buffer;
          if ( !v18 )
            v18 = putf8Buffer;
          if ( !Char_Advance0 )
            break;
          if ( !v21 )
            goto LABEL_28;
          if ( Char_Advance0 != v21 )
          {
            pData = v18;
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
          return result;
        v22 = resulta.pNode;
        v23 = Scaleform::GFx::AS2::StringProto::CreateStringFromCStr(&v33, psc, v17, (const char *)resulta.pNode);
        v36.T.Type = 5;
        v36.NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)v23->pNode;
        ++v36.V.pStringNode->RefCount;
        Scaleform::GFx::AS2::ArrayObject::PushBack(result->pObject, &v36);
        if ( v36.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&v36);
        v24 = v33.pNode;
        v15 = v33.pNode->RefCount-- == 1;
        if ( v15 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v24);
        v17 = v19;
        pData = v19;
        putf8Buffer = v19;
        ++v16;
LABEL_35:
        v5 = (char *)stra.pData;
      }
      while ( Char_Advance0 );
      if ( v16 < limit )
      {
        if ( v21 )
        {
          v27 = Scaleform::GFx::AS2::StringProto::CreateStringFromCStr(&v32, psc, v17, 0i64);
          v37.T.Type = 5;
          v37.NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)v27->pNode;
          ++v37.V.pStringNode->RefCount;
          Scaleform::GFx::AS2::ArrayObject::PushBack(result->pObject, &v37);
          if ( v37.T.Type >= 5u )
            Scaleform::GFx::AS2::Value::DropRefs(&v37);
          v26 = v32.pNode;
        }
        else
        {
          StringFromCStr = Scaleform::GFx::AS2::StringProto::CreateStringFromCStr(
                             (Scaleform::GFx::ASString *)&psc,
                             psc,
                             v17,
                             (const char *)v22);
          v38.T.Type = 5;
          v38.NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)StringFromCStr->pNode;
          ++v38.V.pStringNode->RefCount;
          Scaleform::GFx::AS2::ArrayObject::PushBack(result->pObject, &v38);
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
        v13 = Scaleform::GFx::AS2::ASStringContext::CreateString(p_StringContext, &resulta, &stra);
        v35.T.Type = 5;
        v35.NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)v13->pNode;
        ++v35.V.pStringNode->RefCount;
        Scaleform::GFx::AS2::ArrayObject::PushBack(result->pObject, &v35);
        if ( v35.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&v35);
        v14 = resulta.pNode;
        v15 = resulta.pNode->RefCount-- == 1;
        if ( v15 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v14);
      }
      --putf8Buffer;
      if ( !_InterlockedDecrement((volatile signed __int32 *)((stra.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
    }
  }
  else
  {
    val.T.Type = 5;
    val.V.pStringNode = pNode;
    ++pNode->RefCount;
    Scaleform::GFx::AS2::ArrayObject::PushBack(result->pObject, &val);
    if ( val.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&val);
  }
  return result;
}

// File Line: 411
// RVA: 0x720EF0
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::AS2::StringProto::StringSubstring(
        Scaleform::GFx::ASString *result,
        Scaleform::GFx::ASString *self,
        int start,
        int length)
{
  int v4; // ebx
  int v5; // esi
  signed int v8; // ecx

  v4 = length;
  v5 = start;
  if ( length )
  {
    if ( start < 0 )
      v5 = 0;
    v8 = Scaleform::GFx::ASConstString::GetLength(self);
    if ( v5 < v8 )
    {
      if ( v4 < 0 || v5 + v4 > v8 )
        v4 = v8 - v5;
      Scaleform::GFx::ASString::Substring(self, result, v5, v5 + v4);
    }
    else
    {
      Scaleform::GFx::ASStringManager::CreateEmptyString(self->pNode->pManager, result);
    }
  }
  else
  {
    Scaleform::GFx::ASStringManager::CreateEmptyString(self->pNode->pManager, result);
  }
  return result;
}

// File Line: 431
// RVA: 0x6E17C0
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::AS2::StringProto::CreateStringFromCStr(
        Scaleform::GFx::ASString *result,
        Scaleform::GFx::AS2::ASStringContext *psc,
        const char *start,
        const char *end)
{
  __int64 v5; // rax
  Scaleform::GFx::ASStringNode *v6; // rcx

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
  if ( (int)v5 < 1 )
  {
    v6 = *(Scaleform::GFx::ASStringNode **)&psc->pContext->pMovieRoot->pASMovieRoot.pObject[7].AVMVersion;
    result->pNode = v6;
    ++v6->RefCount;
  }
  else
  {
    Scaleform::GFx::AS2::ASStringContext::CreateString(psc, result, start, (int)v5);
  }
  return result;
}

// File Line: 442
// RVA: 0x6B1700
void __fastcall Scaleform::GFx::AS2::StringProto::StringSubstr(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rax
  Scaleform::GFx::ASString *v4; // rbp
  int v5; // edi
  int v6; // esi
  unsigned int FirstArgBottomIndex; // r10d
  Scaleform::GFx::AS2::Environment *Env; // rdx
  Scaleform::GFx::AS2::Value *v9; // r9
  unsigned int v10; // r9d
  Scaleform::GFx::AS2::Environment *v11; // rdx
  Scaleform::GFx::AS2::Value *v12; // r10
  Scaleform::GFx::ASString *v13; // rdi
  Scaleform::GFx::AS2::Value *v14; // rbx
  Scaleform::GFx::ASStringNode *pNode; // rax
  Scaleform::GFx::ASStringNode *v16; // rcx
  Scaleform::GFx::ASString result; // [rsp+50h] [rbp+8h] BYREF

  ThisPtr = fn->ThisPtr;
  if ( ThisPtr
    && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(ThisPtr) == 8 )
  {
    v3 = fn->ThisPtr;
    v4 = (Scaleform::GFx::ASString *)&v3[-2];
    if ( !v3 )
      v4 = 0i64;
    v5 = 0;
    v6 = -1;
    if ( fn->NArgs >= 1 )
    {
      FirstArgBottomIndex = fn->FirstArgBottomIndex;
      Env = fn->Env;
      v9 = 0i64;
      if ( FirstArgBottomIndex <= 32 * ((unsigned int)Env->Stack.Pages.Data.Size - 1)
                                + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
        v9 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
      v5 = (int)Scaleform::GFx::AS2::Value::ToNumber(v9, Env);
      if ( v5 < 0 )
        v5 += Scaleform::GFx::ASConstString::GetLength(v4 + 12);
    }
    if ( fn->NArgs >= 2 )
    {
      v10 = fn->FirstArgBottomIndex - 1;
      v11 = fn->Env;
      v12 = 0i64;
      if ( v10 <= 32 * ((unsigned int)v11->Stack.Pages.Data.Size - 1)
                + (unsigned int)(v11->Stack.pCurrent - v11->Stack.pPageStart) )
        v12 = &v11->Stack.Pages.Data.Data[v10 >> 5]->Values[v10 & 0x1F];
      v6 = (int)Scaleform::GFx::AS2::Value::ToNumber(v12, v11);
      if ( v6 < 0 )
        v6 = 0;
    }
    v13 = Scaleform::GFx::AS2::StringProto::StringSubstring(&result, v4 + 12, v5, v6);
    v14 = fn->Result;
    if ( v14->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(v14);
    v14->T.Type = 5;
    pNode = v13->pNode;
    v14->NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)v13->pNode;
    ++pNode->RefCount;
    v16 = result.pNode;
    if ( result.pNode->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v16);
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      fn->Env,
      "Error: Null or invalid this is used for a method of %s class.\n",
      "String");
  }
}

// File Line: 470
// RVA: 0x6B19B0
void __fastcall Scaleform::GFx::AS2::StringProto::StringSubstring(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rax
  Scaleform::GFx::ASString *v4; // rbp
  int v5; // edi
  int v6; // esi
  unsigned int FirstArgBottomIndex; // r10d
  Scaleform::GFx::AS2::Environment *Env; // rdx
  Scaleform::GFx::AS2::Value *v9; // r9
  unsigned int v10; // r9d
  Scaleform::GFx::AS2::Environment *v11; // rdx
  Scaleform::GFx::AS2::Value *v12; // r10
  int v13; // esi
  int v14; // eax
  Scaleform::GFx::ASString *v15; // rdi
  Scaleform::GFx::AS2::Value *v16; // rbx
  Scaleform::GFx::ASStringNode *pNode; // rax
  Scaleform::GFx::ASStringNode *v18; // rcx
  Scaleform::GFx::ASString result; // [rsp+50h] [rbp+8h] BYREF

  ThisPtr = fn->ThisPtr;
  if ( ThisPtr
    && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(ThisPtr) == 8 )
  {
    v3 = fn->ThisPtr;
    v4 = (Scaleform::GFx::ASString *)&v3[-2];
    if ( !v3 )
      v4 = 0i64;
    v5 = 0;
    v6 = -1;
    if ( fn->NArgs >= 1 )
    {
      FirstArgBottomIndex = fn->FirstArgBottomIndex;
      Env = fn->Env;
      v9 = 0i64;
      if ( FirstArgBottomIndex <= 32 * ((unsigned int)Env->Stack.Pages.Data.Size - 1)
                                + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
        v9 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
      v5 = (int)Scaleform::GFx::AS2::Value::ToNumber(v9, Env);
    }
    if ( fn->NArgs >= 2 )
    {
      v10 = fn->FirstArgBottomIndex - 1;
      v11 = fn->Env;
      v12 = 0i64;
      if ( v10 <= 32 * ((unsigned int)v11->Stack.Pages.Data.Size - 1)
                + (unsigned int)(v11->Stack.pCurrent - v11->Stack.pPageStart) )
        v12 = &v11->Stack.Pages.Data.Data[v10 >> 5]->Values[v10 & 0x1F];
      v13 = (int)Scaleform::GFx::AS2::Value::ToNumber(v12, v11);
      if ( v13 < v5 )
      {
        if ( v5 >= (int)Scaleform::GFx::ASConstString::GetLength(v4 + 12) )
        {
          Scaleform::GFx::AS2::Value::SetString(
            fn->Result,
            (Scaleform::GFx::ASString *)&fn->Env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[7].AVMVersion);
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
    v16 = fn->Result;
    if ( v16->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(v16);
    v16->T.Type = 5;
    pNode = v15->pNode;
    v16->NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)v15->pNode;
    ++pNode->RefCount;
    v18 = result.pNode;
    if ( result.pNode->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v18);
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      fn->Env,
      "Error: Null or invalid this is used for a method of %s class.\n",
      "String");
  }
}

// File Line: 519
// RVA: 0x6B1C90
void __fastcall Scaleform::GFx::AS2::StringProto::StringToLowerCase(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rax
  Scaleform::GFx::ASString *v4; // rcx
  Scaleform::GFx::ASString *v5; // rdi
  Scaleform::GFx::AS2::Value *v6; // rbx
  Scaleform::GFx::ASStringNode *pNode; // rax
  Scaleform::GFx::ASStringNode *v8; // rcx
  Scaleform::GFx::ASString result; // [rsp+40h] [rbp+8h] BYREF

  ThisPtr = fn->ThisPtr;
  if ( ThisPtr
    && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(ThisPtr) == 8 )
  {
    v3 = fn->ThisPtr;
    if ( v3 )
      v4 = (Scaleform::GFx::ASString *)&v3[-2];
    else
      v4 = 0i64;
    v5 = Scaleform::GFx::ASString::ToLower(v4 + 12, &result);
    v6 = fn->Result;
    if ( v6->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(v6);
    v6->T.Type = 5;
    pNode = v5->pNode;
    v6->NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)v5->pNode;
    ++pNode->RefCount;
    v8 = result.pNode;
    if ( result.pNode->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v8);
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      fn->Env,
      "Error: Null or invalid this is used for a method of %s class.\n",
      "String");
  }
}

// File Line: 527
// RVA: 0x6B1FB0
void __fastcall Scaleform::GFx::AS2::StringProto::StringValueOf(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rax
  Scaleform::GFx::AS2::ObjectInterface *v4; // rdi
  Scaleform::GFx::AS2::Value *Result; // rbx
  Scaleform::GFx::ASStringNode *vfptr; // rax

  ThisPtr = fn->ThisPtr;
  if ( ThisPtr
    && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(ThisPtr) == 8 )
  {
    v3 = fn->ThisPtr;
    if ( v3 )
      v4 = v3 - 2;
    else
      v4 = 0i64;
    Result = fn->Result;
    if ( Result->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(Result);
    Result->T.Type = 5;
    vfptr = (Scaleform::GFx::ASStringNode *)v4[6].vfptr;
    Result->V.pStringNode = vfptr;
    ++vfptr->RefCount;
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      fn->Env,
      "Error: Null or invalid this is used for a method of %s class.\n",
      "String");
  }
}

// File Line: 535
// RVA: 0x6B1F10
void __fastcall Scaleform::GFx::AS2::StringProto::StringToUpperCase(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rax
  Scaleform::GFx::ASString *v4; // rcx
  Scaleform::GFx::ASString *v5; // rdi
  Scaleform::GFx::AS2::Value *v6; // rbx
  Scaleform::GFx::ASStringNode *pNode; // rax
  Scaleform::GFx::ASStringNode *v8; // rcx
  Scaleform::GFx::ASString result; // [rsp+40h] [rbp+8h] BYREF

  ThisPtr = fn->ThisPtr;
  if ( ThisPtr
    && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(ThisPtr) == 8 )
  {
    v3 = fn->ThisPtr;
    if ( v3 )
      v4 = (Scaleform::GFx::ASString *)&v3[-2];
    else
      v4 = 0i64;
    v5 = Scaleform::GFx::ASString::ToUpper(v4 + 12, &result);
    v6 = fn->Result;
    if ( v6->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(v6);
    v6->T.Type = 5;
    pNode = v5->pNode;
    v6->NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)v5->pNode;
    ++pNode->RefCount;
    v8 = result.pNode;
    if ( result.pNode->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v8);
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      fn->Env,
      "Error: Null or invalid this is used for a method of %s class.\n",
      "String");
  }
}

// File Line: 555
// RVA: 0x6B0B60
void __fastcall Scaleform::GFx::AS2::StringProto::StringLocaleCompare(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Value *v2; // rbx
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v4; // rax
  Scaleform::GFx::AS2::Value *v5; // rbx
  Scaleform::GFx::ASConstString *v6; // rbp
  unsigned int FirstArgBottomIndex; // r9d
  Scaleform::GFx::AS2::Environment *Env; // r8
  Scaleform::GFx::AS2::Value *v9; // r10
  bool v10; // si
  unsigned int v11; // r9d
  Scaleform::GFx::AS2::Environment *v12; // rdx
  const char *pData; // rbx
  unsigned int Length; // eax
  int v15; // esi
  Scaleform::GFx::AS2::Value *v16; // rbx
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::ASString result; // [rsp+40h] [rbp+8h] BYREF

  v2 = fn->Result;
  Scaleform::GFx::AS2::Value::DropRefs(v2);
  v2->T.Type = 0;
  if ( fn->Env->StringContext.pContext->GFxExtensions.Value == 1 )
  {
    ThisPtr = fn->ThisPtr;
    if ( ThisPtr
      && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(ThisPtr) == 8 )
    {
      v4 = fn->ThisPtr;
      v5 = 0i64;
      v6 = (Scaleform::GFx::ASConstString *)&v4[-2];
      if ( !v4 )
        v6 = 0i64;
      if ( fn->NArgs >= 1 )
      {
        FirstArgBottomIndex = fn->FirstArgBottomIndex;
        Env = fn->Env;
        v9 = 0i64;
        if ( FirstArgBottomIndex <= 32 * ((unsigned int)Env->Stack.Pages.Data.Size - 1)
                                  + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
          v9 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
        Scaleform::GFx::AS2::Value::ToString(v9, &result, Env, -1);
        v10 = 1;
        if ( fn->NArgs >= 2 )
        {
          v11 = fn->FirstArgBottomIndex - 1;
          v12 = fn->Env;
          if ( v11 <= 32 * ((unsigned int)v12->Stack.Pages.Data.Size - 1)
                    + (unsigned int)(v12->Stack.pCurrent - v12->Stack.pPageStart) )
            v5 = &v12->Stack.Pages.Data.Data[v11 >> 5]->Values[v11 & 0x1F];
          v10 = !Scaleform::GFx::AS2::Value::ToBool(v5, v12);
        }
        pData = result.pNode->pData;
        Length = Scaleform::GFx::ASConstString::GetLength(&result);
        v15 = Scaleform::GFx::ASConstString::LocaleCompare_CaseCheck(v6 + 12, pData, Length, v10);
        v16 = fn->Result;
        if ( v16->T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(fn->Result);
        v16->T.Type = 3;
        v16->NV.NumberValue = (double)v15;
        pNode = result.pNode;
        if ( result.pNode->RefCount-- == 1 )
          Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      }
    }
    else
    {
      Scaleform::GFx::AS2::Environment::LogScriptError(
        fn->Env,
        "Error: Null or invalid this is used for a method of %s class.\n",
        "String");
    }
  }
}

// File Line: 615
// RVA: 0x6B2450
void __fastcall Scaleform::GFx::AS2::StringCtorFunction::StringFromCharCode(Scaleform::GFx::AS2::FnCall *fn)
{
  int i; // edi
  unsigned int v3; // r9d
  Scaleform::GFx::AS2::Environment *Env; // rdx
  Scaleform::GFx::AS2::Value *v5; // r10
  long double v6; // xmm0_8
  char *pData; // r8
  Scaleform::GFx::ASString *v8; // rdi
  Scaleform::GFx::AS2::Value *v9; // rbx
  Scaleform::GFx::ASStringNode *pNode; // rax
  Scaleform::GFx::ASStringNode *v11; // rcx
  Scaleform::StringBuffer v13; // [rsp+28h] [rbp-40h] BYREF
  Scaleform::GFx::ASString result; // [rsp+70h] [rbp+8h] BYREF

  Scaleform::StringBuffer::StringBuffer(&v13, Scaleform::Memory::pGlobalHeap);
  for ( i = 0; i < fn->NArgs; ++i )
  {
    v3 = fn->FirstArgBottomIndex - i;
    Env = fn->Env;
    v5 = 0i64;
    if ( v3 <= 32 * ((unsigned int)Env->Stack.Pages.Data.Size - 1)
             + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
      v5 = &Env->Stack.Pages.Data.Data[v3 >> 5]->Values[v3 & 0x1F];
    v6 = Scaleform::GFx::AS2::Value::ToNumber(v5, Env);
    Scaleform::StringBuffer::AppendChar(&v13, (int)v6);
  }
  pData = &customCaption;
  if ( v13.pData )
    pData = v13.pData;
  v8 = Scaleform::GFx::AS2::Environment::CreateString(fn->Env, &result, pData, v13.Size);
  v9 = fn->Result;
  if ( v9->T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(v9);
  v9->T.Type = 5;
  pNode = v8->pNode;
  v9->NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)v8->pNode;
  ++pNode->RefCount;
  v11 = result.pNode;
  if ( result.pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v11);
  Scaleform::ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayDataBase<int,Scaleform::AllocatorGH<int,2>,Scaleform::ArrayDefaultPolicy> *)&v13);
}

// File Line: 631
// RVA: 0x6E0810
Scaleform::GFx::AS2::Object *__fastcall Scaleform::GFx::AS2::StringCtorFunction::CreateNewObject(
        Scaleform::GFx::AS2::StringCtorFunction *this,
        Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::ASStringContext *p_StringContext; // rdi
  Scaleform::GFx::AS2::StringObject *v4; // rax
  __int64 v5; // rax
  __int64 v6; // rbx
  Scaleform::GFx::AS2::Value v8; // [rsp+38h] [rbp-30h] BYREF
  Scaleform::MemoryHeap *pHeap; // [rsp+78h] [rbp+10h] BYREF
  Scaleform::GFx::AS2::StringObject *v10; // [rsp+80h] [rbp+18h]

  p_StringContext = &penv->StringContext;
  pHeap = penv->StringContext.pContext->pHeap;
  v4 = (Scaleform::GFx::AS2::StringObject *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::StringCtorFunction *, __int64))pHeap->vfptr->Alloc)(
                                              this,
                                              104i64);
  v10 = v4;
  if ( v4 )
  {
    Scaleform::GFx::AS2::StringObject::StringObject(v4, penv);
    v6 = v5;
  }
  else
  {
    v6 = 0i64;
  }
  v8.T.Type = 10;
  LOBYTE(pHeap) = 0;
  (*(void (__fastcall **)(__int64, Scaleform::GFx::AS2::ASStringContext *, char *, Scaleform::GFx::AS2::Value *, Scaleform::MemoryHeap **))(*(_QWORD *)(v6 + 32) + 80i64))(
    v6 + 32,
    p_StringContext,
    &p_StringContext->pContext->pMovieRoot->pASMovieRoot.pObject[38].AVMVersion,
    &v8,
    &pHeap);
  if ( v8.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v8);
  return (Scaleform::GFx::AS2::Object *)v6;
}

// File Line: 638
// RVA: 0x6FA100
void __fastcall Scaleform::GFx::AS2::StringCtorFunction::GlobalCtor(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Value *v2; // rsi
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v4; // rax
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::Page *v5; // rax
  Scaleform::GFx::AS2::Value *v6; // rax
  char v7; // di
  Scaleform::GFx::ASMovieRootBase *pObject; // rcx
  Scaleform::GFx::ASMovieRootBase *v9; // rdi
  Scaleform::GFx::AS2::Value *v10; // rbx
  Scaleform::GFx::ASStringNode *v11; // rax
  unsigned int FirstArgBottomIndex; // r9d
  Scaleform::GFx::AS2::Environment *Env; // r8
  Scaleform::GFx::ASString *v14; // rdi
  Scaleform::GFx::AS2::Value *v15; // rbx
  Scaleform::GFx::ASStringNode *pNode; // rax
  Scaleform::GFx::ASStringNode *v17; // rcx
  Scaleform::GFx::AS2::Value v19; // [rsp+30h] [rbp-68h] BYREF
  Scaleform::GFx::AS2::Value v; // [rsp+50h] [rbp-48h] BYREF
  Scaleform::GFx::AS2::Value v21; // [rsp+70h] [rbp-28h] BYREF
  Scaleform::GFx::ASString result; // [rsp+A0h] [rbp+8h] BYREF

  v2 = 0i64;
  ThisPtr = fn->ThisPtr;
  if ( ThisPtr
    && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(ThisPtr) == 8
    && !fn->ThisPtr->vfptr->IsBuiltinPrototype(fn->ThisPtr) )
  {
    v4 = fn->ThisPtr;
    if ( v4 )
      v2 = (Scaleform::GFx::AS2::Value *)&v4[-2];
    if ( fn->NArgs <= 0 )
    {
      pObject = fn->Env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject;
      v19.T.Type = 5;
      v19.V.pStringNode = *(Scaleform::GFx::ASStringNode **)&pObject[7].AVMVersion;
      ++v19.V.pStringNode->RefCount;
      v6 = &v19;
      v7 = 2;
    }
    else
    {
      v5 = Scaleform::GFx::AS2::FnCall::Arg(fn, 0);
      Scaleform::GFx::AS2::Value::Value(&v21, v5->Values);
      v7 = 1;
    }
    Scaleform::GFx::AS2::Value::Value(&v, v6);
    if ( (v7 & 2) != 0 )
    {
      v7 &= ~2u;
      if ( v19.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v19);
    }
    if ( (v7 & 1) != 0 && v21.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v21);
    (*(void (__fastcall **)(Scaleform::GFx::AS2::Value *, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::AS2::Value *))(*(_QWORD *)&v2->T.Type + 24i64))(
      v2,
      fn->Env,
      &v);
    Scaleform::GFx::AS2::Value::operator=(fn->Result, &v);
    if ( v.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v);
  }
  else if ( fn->NArgs )
  {
    FirstArgBottomIndex = fn->FirstArgBottomIndex;
    Env = fn->Env;
    if ( FirstArgBottomIndex <= 32 * ((unsigned int)Env->Stack.Pages.Data.Size - 1)
                              + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
      v2 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
    v14 = Scaleform::GFx::AS2::Value::ToString(v2, &result, Env, -1);
    v15 = fn->Result;
    if ( v15->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(v15);
    v15->T.Type = 5;
    pNode = v14->pNode;
    v15->NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)v14->pNode;
    ++pNode->RefCount;
    v17 = result.pNode;
    if ( result.pNode->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v17);
  }
  else
  {
    v9 = fn->Env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject;
    v10 = fn->Result;
    if ( v10->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(v10);
    v10->T.Type = 5;
    v11 = *(Scaleform::GFx::ASStringNode **)&v9[7].AVMVersion;
    v10->V.pStringNode = v11;
    ++v11->RefCount;
  }
}

// File Line: 657
// RVA: 0x70ECB0
Scaleform::MemoryHeap *__fastcall Scaleform::GFx::AS2::StringCtorFunction::Register(
        Scaleform::MemoryHeap *result,
        Scaleform::GFx::AS2::GlobalContext *pgc)
{
  Scaleform::GFx::AS2::Object *v4; // rax
  __int64 v5; // rcx
  Scaleform::GFx::AS2::FunctionObject *v6; // rbx
  Scaleform::GFx::AS2::Object *Prototype; // r15
  Scaleform::GFx::AS2::RefCountBaseGC<323> *pObject; // rcx
  unsigned int RefCount; // eax
  __int64 v10; // rbx
  Scaleform::GFx::AS2::Object *v11; // r15
  __int64 v12; // rax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v13; // rcx
  unsigned int v14; // eax
  Scaleform::GFx::ASSupport *v15; // rsi
  Scaleform::GFx::ASStringNode *v16; // rcx
  Scaleform::GFx::AS2::Object *v18; // rsi
  Scaleform::GFx::ASStringNode *vfptr; // rax
  Scaleform::GFx::AS2::LocalFrame *pPrev; // rdx
  int v21; // eax
  Scaleform::GFx::AS2::ASStringContext psc; // [rsp+48h] [rbp-38h] BYREF
  Scaleform::GFx::AS2::Value v24; // [rsp+58h] [rbp-28h] BYREF
  Scaleform::Ptr<Scaleform::GFx::AS2::Object> objproto; // [rsp+C8h] [rbp+48h] BYREF
  Scaleform::MemoryHeap *flags; // [rsp+D0h] [rbp+50h] BYREF
  void *pHeap; // [rsp+D8h] [rbp+58h]

  psc.pContext = pgc;
  psc.SWFVersion = 8;
  flags = pgc->pHeap;
  v4 = (Scaleform::GFx::AS2::Object *)flags->vfptr->Alloc(result, 104ui64, 0i64);
  v6 = (Scaleform::GFx::AS2::FunctionObject *)v4;
  pHeap = v4;
  if ( v4 )
  {
    Scaleform::GFx::AS2::Object::Object(v4, &psc);
    v6->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::FunctionObject::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
    v6->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::FunctionObject::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
    v6->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::CFunctionObject::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
    v6->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::CFunctionObject::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
    v6[1].Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)Scaleform::GFx::AS2::StringCtorFunction::GlobalCtor;
    Prototype = Scaleform::GFx::AS2::GlobalContext::GetPrototype(psc.pContext, ASBuiltin_Function);
    if ( !v6->pProto.pObject )
    {
      LOBYTE(objproto.pObject) = 3;
      v24.T.Type = 10;
      v6->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr->SetMemberRaw(
        &v6->Scaleform::GFx::AS2::ObjectInterface,
        &psc,
        (Scaleform::GFx::ASString *)&psc.pContext->pMovieRoot->pASMovieRoot.pObject[23].pMovieImpl,
        &v24,
        (Scaleform::GFx::AS2::PropFlags *)&objproto);
      if ( v24.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v24);
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
    v6->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::StringCtorFunction::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
    v6->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::StringCtorFunction::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
    Scaleform::GFx::AS2::NameFunction::AddConstMembers(
      &v6->Scaleform::GFx::AS2::ObjectInterface,
      &psc,
      Scaleform::GFx::AS2::StringCtorFunction::StaticFunctionTable,
      7);
  }
  else
  {
    v6 = 0i64;
  }
  LOBYTE(result->pNext) = 0;
  result->vfptr = (Scaleform::MemoryHeapVtbl *)v6;
  result->pPrev = 0i64;
  pHeap = pgc->pHeap;
  v10 = (*(__int64 (__fastcall **)(__int64, __int64, _QWORD))(*(_QWORD *)pHeap + 80i64))(v5, 168i64, 0i64);
  if ( v10 )
  {
    v11 = Scaleform::GFx::AS2::GlobalContext::GetPrototype(pgc, ASBuiltin_Object);
    Scaleform::GFx::AS2::Object::Object((Scaleform::GFx::AS2::Object *)v10, &psc);
    *(_QWORD *)v10 = &Scaleform::GFx::AS2::StringObject::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
    *(_QWORD *)(v10 + 32) = &Scaleform::GFx::AS2::StringObject::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
    v12 = *(_QWORD *)&psc.pContext->pMovieRoot->pASMovieRoot.pObject[7].AVMVersion;
    *(_QWORD *)(v10 + 96) = v12;
    ++*(_DWORD *)(v12 + 24);
    if ( !*(_QWORD *)(v10 + 40) )
    {
      LOBYTE(objproto.pObject) = 3;
      v24.T.Type = 10;
      (*(void (__fastcall **)(__int64, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::MovieImpl **, Scaleform::GFx::AS2::Value *, Scaleform::Ptr<Scaleform::GFx::AS2::Object> *))(*(_QWORD *)(v10 + 32) + 80i64))(
        v10 + 32,
        &psc,
        &psc.pContext->pMovieRoot->pASMovieRoot.pObject[23].pMovieImpl,
        &v24,
        &objproto);
      if ( v24.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v24);
    }
    if ( v11 )
      v11->RefCount = (v11->RefCount + 1) & 0x8FFFFFFF;
    v13 = *(Scaleform::GFx::AS2::RefCountBaseGC<323> **)(v10 + 40);
    if ( v13 )
    {
      v14 = v13->RefCount;
      if ( (v14 & 0x3FFFFFF) != 0 )
      {
        v13->RefCount = v14 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v13);
      }
    }
    *(_QWORD *)(v10 + 40) = v11;
    flags = (Scaleform::MemoryHeap *)(v10 + 104);
    *(_QWORD *)(v10 + 104) = &Scaleform::GFx::AS2::GASPrototypeBase::`vftable;
    *(_BYTE *)(v10 + 128) = 0;
    *(_QWORD *)(v10 + 112) = 0i64;
    *(_QWORD *)(v10 + 120) = 0i64;
    *(_BYTE *)(v10 + 152) = 0;
    *(_QWORD *)(v10 + 136) = 0i64;
    *(_QWORD *)(v10 + 144) = 0i64;
    *(_QWORD *)(v10 + 160) = 0i64;
    *(_QWORD *)v10 = &Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::StringObject,Scaleform::GFx::AS2::Environment>::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
    *(_QWORD *)(v10 + 32) = &Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::StringObject,Scaleform::GFx::AS2::Environment>::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
    *(_QWORD *)(v10 + 104) = &Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::StringObject,Scaleform::GFx::AS2::Environment>::`vftable;
    Scaleform::GFx::AS2::GASPrototypeBase::Init(
      (Scaleform::GFx::AS2::GASPrototypeBase *)(v10 + 104),
      (Scaleform::GFx::AS2::Object *)v10,
      &psc,
      (Scaleform::GFx::AS2::FunctionRef *)result);
    *(_QWORD *)v10 = &Scaleform::GFx::AS2::StringProto::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
    *(_QWORD *)(v10 + 32) = &Scaleform::GFx::AS2::StringProto::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
    *(_QWORD *)(v10 + 104) = &Scaleform::GFx::AS2::StringProto::`vftable;
    v15 = psc.pContext->pMovieRoot->pASMovieRoot.pObject[24].pASSupport.pObject;
    ++LODWORD(v15[1].vfptr);
    v16 = *(Scaleform::GFx::ASStringNode **)(v10 + 96);
    if ( v16->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v16);
    *(_QWORD *)(v10 + 96) = v15;
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
  pHeap = &objproto;
  if ( v10 )
    *(_DWORD *)(v10 + 24) = (*(_DWORD *)(v10 + 24) + 1) & 0x8FFFFFFF;
  objproto.pObject = (Scaleform::GFx::AS2::Object *)v10;
  Scaleform::GFx::AS2::GlobalContext::SetPrototype(
    pgc,
    ASBuiltin_String,
    (Scaleform::Ptr<Scaleform::GFx::AS2::Object>)&objproto);
  v18 = pgc->pGlobal.pObject;
  v24.T.Type = 8;
  v24.V.FunctionValue.Flags = 0;
  vfptr = (Scaleform::GFx::ASStringNode *)result->vfptr;
  v24.V.pStringNode = vfptr;
  if ( vfptr )
  {
    ++vfptr->RefCount;
    vfptr->RefCount &= 0x8FFFFFFF;
  }
  v24.V.FunctionValue.pLocalFrame = 0i64;
  pPrev = (Scaleform::GFx::AS2::LocalFrame *)result->pPrev;
  if ( pPrev )
    Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(&v24.V.FunctionValue, pPrev, (__int64)result->pNext & 1);
  LOBYTE(objproto.pObject) = 0;
  v18->Scaleform::GFx::AS2::ObjectInterface::vfptr->SetMemberRaw(
    &v18->Scaleform::GFx::AS2::ObjectInterface,
    &psc,
    (Scaleform::GFx::ASString *)&pgc->pMovieRoot->pASMovieRoot.pObject[8].pMovieImpl,
    &v24,
    (Scaleform::GFx::AS2::PropFlags *)&objproto);
  if ( v24.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v24);
  if ( v10 )
  {
    v21 = *(_DWORD *)(v10 + 24);
    if ( (v21 & 0x3FFFFFF) != 0 )
    {
      *(_DWORD *)(v10 + 24) = v21 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v10);
    }
  }
  return result;
}

