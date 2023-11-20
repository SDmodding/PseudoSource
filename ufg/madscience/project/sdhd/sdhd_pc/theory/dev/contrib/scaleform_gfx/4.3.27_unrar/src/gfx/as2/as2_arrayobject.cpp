// File Line: 34
// RVA: 0x6D24E0
void __fastcall Scaleform::GFx::AS2::RecursionGuard::~RecursionGuard(Scaleform::GFx::AS2::RecursionGuard *this)
{
  --this->ThisPtr->RecursionCount;
}

// File Line: 64
// RVA: 0x6DE330
__int64 __fastcall Scaleform::GFx::AS2::ArraySortFunctor::Compare(Scaleform::GFx::AS2::ArraySortFunctor *this, Scaleform::GFx::AS2::Value *a, Scaleform::GFx::AS2::Value *b)
{
  Scaleform::GFx::AS2::ArraySortFunctor *v3; // rsi
  Scaleform::GFx::AS2::Value *v4; // r15
  Scaleform::GFx::AS2::Value *v5; // r14
  unsigned int v6; // edi
  Scaleform::GFx::AS2::Environment *v7; // rbx
  Scaleform::GFx::ASStringNode *v8; // rcx
  Scaleform::GFx::AS2::Environment *v9; // rbx
  Scaleform::GFx::ASStringNode *v10; // rcx
  int v11; // edx
  Scaleform::GFx::AS2::ObjectInterface *v12; // rax
  signed int v13; // er14
  Scaleform::GFx::AS2::Environment *v14; // rbx
  Scaleform::GFx::AS2::Value *v15; // rcx
  int v16; // ebx
  char v17; // al
  unsigned int v18; // edx
  char v19; // ST18_1
  unsigned int v20; // eax
  char v21; // al
  unsigned int v22; // edx
  char v23; // ST18_1
  unsigned int v24; // eax
  double v25; // xmm6_8
  double v26; // xmm7_8
  signed __int64 v27; // rbx
  bool v28; // r12
  const char *v29; // rcx
  Scaleform::GFx::ASStringNode *v30; // rcx
  bool v31; // zf
  bool v32; // bl
  const char *v33; // rcx
  Scaleform::GFx::ASStringNode *v34; // rcx
  int v35; // eax
  bool v36; // di
  const char *v37; // rbx
  unsigned int v38; // eax
  const char *v39; // rdx
  const char *v40; // rcx
  signed __int64 v41; // rdx
  unsigned __int8 v42; // al
  Scaleform::GFx::ASStringNode *v43; // rcx
  Scaleform::GFx::ASStringNode *v44; // rcx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v46; // [rsp+8h] [rbp-71h]
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v47; // [rsp+8h] [rbp-71h]
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v48; // [rsp+10h] [rbp-69h]
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v49; // [rsp+10h] [rbp-69h]
  char v50; // [rsp+18h] [rbp-61h]
  char v51; // [rsp+18h] [rbp-61h]
  void **v52; // [rsp+28h] [rbp-51h]
  Scaleform::GFx::AS2::Value v53; // [rsp+30h] [rbp-49h]
  Scaleform::GFx::AS2::Value v54; // [rsp+50h] [rbp-29h]
  __int64 v55; // [rsp+70h] [rbp-9h]
  Scaleform::GFx::ASString result; // [rsp+E0h] [rbp+67h]
  char *tailptr; // [rsp+E8h] [rbp+6Fh]

  v55 = -2i64;
  v3 = this;
  v54.T.Type = 0;
  v4 = &v54;
  if ( a )
    v4 = a;
  v5 = &v54;
  if ( b )
    v5 = b;
  v6 = 0;
  if ( this->Func.Function )
  {
    v53.T.Type = 0;
    v7 = this->Env;
    ++v7->Stack.pCurrent;
    if ( v7->Stack.pCurrent >= v7->Stack.pPageEnd )
      Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&v7->Stack);
    v8 = (Scaleform::GFx::ASStringNode *)v7->Stack.pCurrent;
    result.pNode = v8;
    tailptr = (char *)v8;
    if ( v8 )
      Scaleform::GFx::AS2::Value::Value((Scaleform::GFx::AS2::Value *)v8, v5, 0i64);
    v9 = v3->Env;
    ++v9->Stack.pCurrent;
    if ( v9->Stack.pCurrent >= v9->Stack.pPageEnd )
      Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&v9->Stack);
    v10 = (Scaleform::GFx::ASStringNode *)v9->Stack.pCurrent;
    result.pNode = v10;
    tailptr = (char *)v10;
    if ( v10 )
      Scaleform::GFx::AS2::Value::Value((Scaleform::GFx::AS2::Value *)v10, v4, 0i64);
    v11 = ((_QWORD)((char *)v3->Env->Stack.pCurrent - (char *)v3->Env->Stack.pPageStart) >> 5)
        + 32 * v3->Env->Stack.Pages.Data.Size
        - 32;
    v12 = v3->This;
    *(_QWORD *)&v53.T.Type = &v53;
    v13 = 2;
    LODWORD(v52) = 2;
    HIDWORD(v52) = v11;
    ((void (__fastcall *)(Scaleform::GFx::AS2::FunctionObject *, void ***, Scaleform::GFx::AS2::LocalFrame *, _QWORD))v3->Func.Function->vfptr[3].Finalize_GC)(
      v3->Func.Function,
      &v52,
      v3->Func.pLocalFrame,
      0i64);
    v14 = v3->Env;
    do
    {
      v15 = v14->Stack.pCurrent;
      if ( v15->T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(v15);
      --v14->Stack.pCurrent;
      if ( v14->Stack.pCurrent < v14->Stack.pPageStart )
        Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(&v14->Stack);
      --v13;
    }
    while ( v13 );
    if ( *(_QWORD *)&v53.T.Type )
    {
      v16 = Scaleform::GFx::AS2::Value::ToInt32(*(Scaleform::GFx::AS2::Value **)&v53.T.Type, v3->Env);
      if ( v3->Flags & 2 )
        v16 = -v16;
      v52 = &Scaleform::GFx::AS2::FnCall::`vftable';
      v17 = v51;
      if ( !(v51 & 2) )
      {
        if ( v47 )
        {
          v18 = v47->RefCount;
          if ( v18 & 0x3FFFFFF )
          {
            v47->RefCount = v18 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v47);
            v17 = v19;
          }
        }
      }
      if ( !(v17 & 1) )
      {
        if ( v49 )
        {
          v20 = v49->RefCount;
          if ( v20 & 0x3FFFFFF )
          {
            v49->RefCount = v20 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v49);
          }
        }
      }
      v52 = &Scaleform::GFx::LogBase<Scaleform::GFx::AS2::FnCall>::`vftable';
      if ( v53.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v53);
LABEL_74:
      v6 = v16;
      goto LABEL_90;
    }
    v52 = &Scaleform::GFx::AS2::FnCall::`vftable';
    v21 = v50;
    if ( !(v50 & 2) )
    {
      if ( v46 )
      {
        v22 = v46->RefCount;
        if ( v22 & 0x3FFFFFF )
        {
          v46->RefCount = v22 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v46);
          v21 = v23;
        }
      }
    }
    if ( !(v21 & 1) )
    {
      if ( v48 )
      {
        v24 = v48->RefCount;
        if ( v24 & 0x3FFFFFF )
        {
          v48->RefCount = v24 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v48);
        }
      }
    }
    v52 = &Scaleform::GFx::LogBase<Scaleform::GFx::AS2::FnCall>::`vftable';
    if ( v53.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v53);
  }
  else
  {
    v25 = 0.0;
    v26 = 0.0;
    if ( this->Flags & 0x10 )
    {
      v27 = 288063250384289792i64;
      if ( (unsigned __int8)(v4->T.Type - 3) > 1u )
      {
        Scaleform::GFx::AS2::Value::ToString(v4, &result, this->Env, -1);
        v29 = result.pNode->pData;
        v28 = 0;
        if ( result.pNode->pData )
        {
          if ( *v29 <= 0x39u )
          {
            if ( _bittest64(&v27, *v29) )
            {
              v25 = Scaleform::SFstrtod(v29, &tailptr);
              if ( !tailptr || !*tailptr )
                v28 = 1;
            }
          }
        }
        v30 = result.pNode;
        v31 = result.pNode->RefCount == 1;
        --v30->RefCount;
        if ( v31 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v30);
      }
      else
      {
        v25 = Scaleform::GFx::AS2::Value::ToNumber(v4, this->Env);
        v28 = 1;
      }
      if ( (unsigned __int8)(v5->T.Type - 3) > 1u )
      {
        Scaleform::GFx::AS2::Value::ToString(v5, &result, v3->Env, -1);
        v33 = result.pNode->pData;
        v32 = 0;
        if ( result.pNode->pData )
        {
          if ( *v33 <= 0x39u )
          {
            if ( _bittest64(&v27, *v33) )
            {
              v26 = Scaleform::SFstrtod(v33, &tailptr);
              if ( !tailptr || !*tailptr )
                v32 = 1;
            }
          }
        }
        v34 = result.pNode;
        v31 = result.pNode->RefCount == 1;
        --v34->RefCount;
        if ( v31 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v34);
      }
      else
      {
        v26 = Scaleform::GFx::AS2::Value::ToNumber(v5, v3->Env);
        v32 = 1;
      }
      if ( v28 && v32 )
      {
        v16 = 0;
        if ( v26 > v25 )
          v16 = -1;
        if ( v25 > v26 )
          v16 = 1;
        if ( v3->Flags & 2 )
          v16 = -v16;
        goto LABEL_74;
      }
    }
    Scaleform::GFx::AS2::Value::ToString(v4, (Scaleform::GFx::ASString *)&tailptr, v3->Env, -1);
    Scaleform::GFx::AS2::Value::ToString(v5, &result, v3->Env, -1);
    v35 = v3->Flags;
    if ( _bittest(&v35, 0xAu) )
    {
      v36 = ~(_BYTE)v35 & 1;
      v37 = result.pNode->pData;
      v38 = Scaleform::GFx::ASConstString::GetLength((Scaleform::GFx::ASConstString *)&result.pNode);
      v6 = Scaleform::GFx::ASConstString::LocaleCompare_CaseCheck(
             (Scaleform::GFx::ASConstString *)&tailptr,
             v37,
             v38,
             v36);
    }
    else
    {
      v39 = result.pNode->pData;
      v40 = *(const char **)tailptr;
      if ( v35 & 1 )
      {
        v6 = Scaleform::String::CompareNoCase(v40, v39);
      }
      else
      {
        v41 = v39 - v40;
        while ( 1 )
        {
          v42 = *v40;
          if ( *v40 != v40[v41] )
            break;
          ++v40;
          if ( !v42 )
            goto LABEL_84;
        }
        v6 = -(v42 < v40[v41]) | 1;
      }
    }
LABEL_84:
    if ( v3->Flags & 2 )
      v6 = -v6;
    v43 = result.pNode;
    v31 = result.pNode->RefCount == 1;
    --v43->RefCount;
    if ( v31 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v43);
    v44 = (Scaleform::GFx::ASStringNode *)tailptr;
    v31 = *((_DWORD *)tailptr + 6) == 1;
    --v44->RefCount;
    if ( v31 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v44);
  }
LABEL_90:
  if ( v54.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v54);
  return v6;
}

// File Line: 187
// RVA: 0x6C71B0
void __fastcall Scaleform::GFx::AS2::ArraySortOnFunctor::ArraySortOnFunctor(Scaleform::GFx::AS2::ArraySortOnFunctor *this, Scaleform::GFx::AS2::ObjectInterface *pThis, Scaleform::ArrayCC<Scaleform::GFx::ASString,323,Scaleform::ArrayDefaultPolicy> *fieldArray, Scaleform::Array<int,2,Scaleform::ArrayDefaultPolicy> *flagsArray, Scaleform::GFx::AS2::Environment *env, Scaleform::Log *log)
{
  Scaleform::Array<int,2,Scaleform::ArrayDefaultPolicy> *v6; // r13
  Scaleform::GFx::AS2::ObjectInterface *v7; // rbp
  Scaleform::GFx::AS2::ArraySortOnFunctor *v8; // rdi
  Scaleform::Array<Scaleform::GFx::AS2::ArraySortFunctor,2,Scaleform::ArrayDefaultPolicy> *v9; // r14
  unsigned int v10; // esi
  __int64 v11; // rbx
  int v12; // ecx
  signed __int64 v13; // rbx
  Scaleform::GFx::AS2::FunctionRefBase orig; // [rsp+50h] [rbp-58h]
  Scaleform::GFx::AS2::Environment *v15; // [rsp+68h] [rbp-40h]
  Scaleform::Log *v16; // [rsp+70h] [rbp-38h]

  v6 = flagsArray;
  v7 = pThis;
  v8 = this;
  this->This = pThis;
  this->FieldArray = fieldArray;
  this->Env = env;
  this->LogPtr = log;
  v9 = &this->FunctorArray;
  v9->Data.Data = 0i64;
  v9->Data.Size = 0i64;
  v9->Data.Policy.Capacity = 0i64;
  Scaleform::ArrayData<Scaleform::GFx::AS2::ArraySortFunctor,Scaleform::AllocatorGH<Scaleform::GFx::AS2::ArraySortFunctor,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &this->FunctorArray.Data,
    flagsArray->Data.Size);
  v10 = 0;
  if ( v8->FunctorArray.Data.Size )
  {
    v11 = 0i64;
    do
    {
      v12 = v6->Data.Data[v11];
      orig.Flags = 0;
      orig.Function = 0i64;
      orig.pLocalFrame = 0i64;
      v15 = env;
      v16 = log;
      v13 = (signed __int64)&v9->Data.Data[v11];
      *(_QWORD *)v13 = v7;
      *(_DWORD *)(v13 + 8) = v12;
      Scaleform::GFx::AS2::FunctionRefBase::Assign((Scaleform::GFx::AS2::FunctionRefBase *)(v13 + 16), &orig);
      *(_QWORD *)(v13 + 40) = env;
      *(_QWORD *)(v13 + 48) = log;
      orig.Function = 0i64;
      orig.pLocalFrame = 0i64;
      v11 = ++v10;
    }
    while ( v10 < v8->FunctorArray.Data.Size );
  }
}

// File Line: 202
// RVA: 0x6DE7F0
__int64 __fastcall Scaleform::GFx::AS2::ArraySortOnFunctor::Compare(Scaleform::GFx::AS2::ArraySortOnFunctor *this, Scaleform::GFx::AS2::Value *a, Scaleform::GFx::AS2::Value *b)
{
  Scaleform::GFx::AS2::ArraySortOnFunctor *v3; // rbp
  Scaleform::GFx::AS2::Value *v4; // r13
  Scaleform::GFx::AS2::Value *v5; // r12
  __int64 v6; // r15
  Scaleform::GFx::AS2::Environment *v7; // rdx
  Scaleform::GFx::CharacterHandle *v8; // rcx
  Scaleform::GFx::DisplayObject *v9; // rax
  Scaleform::GFx::DisplayObject *v10; // rcx
  signed __int64 v11; // rcx
  __int64 v12; // rax
  signed __int64 v13; // rdi
  Scaleform::GFx::AS2::Object *v14; // rax
  Scaleform::GFx::AS2::Environment *v15; // rdx
  Scaleform::GFx::CharacterHandle *v16; // rcx
  Scaleform::GFx::DisplayObject *v17; // rax
  Scaleform::GFx::DisplayObject *v18; // rcx
  signed __int64 v19; // rcx
  __int64 v20; // rax
  signed __int64 v21; // rbx
  Scaleform::GFx::AS2::Object *v22; // rax
  signed __int64 v23; // r14
  unsigned int v24; // ebx
  signed __int64 v26; // [rsp+20h] [rbp-98h]
  Scaleform::GFx::AS2::Value ba; // [rsp+28h] [rbp-90h]
  Scaleform::GFx::AS2::Value aa; // [rsp+48h] [rbp-70h]
  char v29; // [rsp+68h] [rbp-50h]
  char *v30; // [rsp+C0h] [rbp+8h]

  v26 = -2i64;
  v3 = this;
  v29 = 0;
  v4 = (Scaleform::GFx::AS2::Value *)&v29;
  if ( a )
    v4 = a;
  v5 = (Scaleform::GFx::AS2::Value *)&v29;
  if ( b )
    v5 = b;
  v30 = (char *)&this->Env->StringContext;
  v6 = 0i64;
  if ( !this->FunctorArray.Data.Size )
    return 0i64;
  while ( 1 )
  {
    v7 = v3->Env;
    if ( v4->T.Type == 7 )
    {
      if ( v7 )
      {
        v8 = v4->V.pCharHandle;
        if ( v8 )
        {
          v9 = Scaleform::GFx::CharacterHandle::ResolveCharacter(v8, v7->Target->pASRoot->pMovieImpl);
          if ( v9 )
          {
            v10 = 0i64;
            if ( SLOBYTE(v9->Flags) < 0 )
              v10 = v9;
            if ( v10 )
            {
              v11 = (signed __int64)v10 + 4 * (unsigned __int8)v10->AvmObjOffset;
              v12 = (*(__int64 (__fastcall **)(signed __int64, Scaleform::GFx::DisplayObject *))(*(_QWORD *)v11 + 8i64))(
                      v11,
                      v9);
              if ( v12 )
              {
                v13 = v12 + 8;
                goto LABEL_18;
              }
            }
          }
        }
      }
    }
    else
    {
      v14 = Scaleform::GFx::AS2::Value::ToObject(v4, v7);
      if ( v14 )
      {
        v13 = (signed __int64)&v14->vfptr;
        goto LABEL_18;
      }
    }
    v13 = 0i64;
LABEL_18:
    v15 = v3->Env;
    if ( v5->T.Type == 7 )
    {
      if ( !v15 )
        goto LABEL_29;
      v16 = v5->V.pCharHandle;
      if ( !v16 )
        goto LABEL_29;
      v17 = Scaleform::GFx::CharacterHandle::ResolveCharacter(v16, v15->Target->pASRoot->pMovieImpl);
      if ( !v17 )
        goto LABEL_29;
      v18 = 0i64;
      if ( SLOBYTE(v17->Flags) < 0 )
        v18 = v17;
      if ( !v18
        || (v19 = (signed __int64)v18 + 4 * (unsigned __int8)v18->AvmObjOffset,
            (v20 = (*(__int64 (__fastcall **)(signed __int64, Scaleform::GFx::DisplayObject *))(*(_QWORD *)v19 + 8i64))(
                     v19,
                     v17)) == 0) )
      {
LABEL_29:
        v21 = 0i64;
        goto LABEL_30;
      }
      v21 = v20 + 8;
    }
    else
    {
      v22 = Scaleform::GFx::AS2::Value::ToObject(v5, v15);
      if ( !v22 )
        goto LABEL_29;
      v21 = (signed __int64)&v22->vfptr;
    }
LABEL_30:
    if ( v13 )
    {
      if ( v21 )
        break;
    }
LABEL_39:
    v6 = (unsigned int)(v6 + 1);
    if ( (unsigned int)v6 >= v3->FunctorArray.Data.Size )
      return 0i64;
  }
  aa.T.Type = 0;
  ba.T.Type = 0;
  v23 = (signed __int64)&v3->FieldArray->Data.Data[v6];
  if ( !(*(unsigned __int8 (__fastcall **)(signed __int64, char *, signed __int64, Scaleform::GFx::AS2::Value *, signed __int64))(*(_QWORD *)v13 + 88i64))(
          v13,
          v30,
          v23,
          &aa,
          v26)
    || !(*(unsigned __int8 (__fastcall **)(signed __int64, char *, signed __int64, Scaleform::GFx::AS2::Value *))(*(_QWORD *)v21 + 88i64))(
          v21,
          v30,
          v23,
          &ba)
    || (v24 = Scaleform::GFx::AS2::ArraySortFunctor::Compare(&v3->FunctorArray.Data.Data[(unsigned int)v6], &aa, &ba)) == 0 )
  {
    if ( ba.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&ba);
    if ( aa.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&aa);
    goto LABEL_39;
  }
  if ( ba.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&ba);
  if ( aa.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&aa);
  return v24;
}

// File Line: 240
// RVA: 0x6C7060
void __fastcall Scaleform::GFx::AS2::ArrayObject::ArrayObject(Scaleform::GFx::AS2::ArrayObject *this, Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::Environment *v2; // rbx
  Scaleform::GFx::AS2::ArrayObject *v3; // rsi
  Scaleform::GFx::AS2::Object *v4; // rax
  signed __int64 v5; // [rsp+58h] [rbp+10h]

  v2 = penv;
  v3 = this;
  Scaleform::GFx::AS2::Object::Object((Scaleform::GFx::AS2::Object *)&this->vfptr, penv);
  v3->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::ArrayObject::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
  v3->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::ArrayObject::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  v3->LogPtr = (Scaleform::Log *const )((__int64 (__cdecl *)(Scaleform::GFx::InteractiveObject *))v2->Target->vfptr[76].__vecDelDtor)(v2->Target);
  v5 = (signed __int64)&v3->Elements;
  *(_OWORD *)v5 = 0ui64;
  *(_QWORD *)(v5 + 16) = 0i64;
  Scaleform::StringLH::StringLH(&v3->StringValue);
  v3->RecursionCount = 0;
  v3->LengthValueOverriden = 0;
  v4 = Scaleform::GFx::AS2::GlobalContext::GetPrototype(v2->StringContext.pContext, ASBuiltin_Array);
  Scaleform::GFx::AS2::Object::Set__proto__((Scaleform::GFx::AS2::Object *)&v3->vfptr, &v2->StringContext, v4);
}

// File Line: 247
// RVA: 0x6C6FC0
void __fastcall Scaleform::GFx::AS2::ArrayObject::ArrayObject(Scaleform::GFx::AS2::ArrayObject *this, Scaleform::GFx::AS2::ASStringContext *psc)
{
  Scaleform::GFx::AS2::ASStringContext *v2; // rdi
  Scaleform::GFx::AS2::ArrayObject *v3; // rsi
  Scaleform::GFx::AS2::Object *v4; // rax
  signed __int64 v5; // [rsp+58h] [rbp+10h]

  v2 = psc;
  v3 = this;
  Scaleform::GFx::AS2::Object::Object((Scaleform::GFx::AS2::Object *)&this->vfptr, psc);
  v3->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::ArrayObject::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
  v3->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::ArrayObject::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  v3->LogPtr = 0i64;
  v5 = (signed __int64)&v3->Elements;
  *(_OWORD *)v5 = 0ui64;
  *(_QWORD *)(v5 + 16) = 0i64;
  Scaleform::StringLH::StringLH(&v3->StringValue);
  v3->RecursionCount = 0;
  v3->LengthValueOverriden = 0;
  v4 = Scaleform::GFx::AS2::GlobalContext::GetPrototype(v2->pContext, ASBuiltin_Array);
  Scaleform::GFx::AS2::Object::Set__proto__((Scaleform::GFx::AS2::Object *)&v3->vfptr, v2, v4);
}

// File Line: 259
// RVA: 0x6D0CA0
void __fastcall Scaleform::GFx::AS2::ArrayObject::~ArrayObject(Scaleform::GFx::AS2::ArrayObject *this)
{
  Scaleform::GFx::AS2::ArrayObject *v1; // rbx

  v1 = this;
  this->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::ArrayObject::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
  this->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::ArrayObject::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  Scaleform::GFx::AS2::ArrayObject::Resize(this, 0);
  if ( !_InterlockedDecrement((volatile signed __int32 *)((v1->StringValue.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v1->Elements.Data.Data);
  Scaleform::GFx::AS2::Object::~Object((Scaleform::GFx::AS2::Object *)&v1->vfptr);
}

// File Line: 265
// RVA: 0x6E8980
void __fastcall Scaleform::GFx::AS2::ArrayObject::ExecuteForEachChild_GC(Scaleform::GFx::AS2::ArrayObject *this, Scaleform::GFx::AS2::RefCountCollector<323> *prcc, Scaleform::GFx::AS2::RefCountBaseGC<323>::OperationGC operation)
{
  __int32 v3; // er8

  if ( operation )
  {
    v3 = operation - 1;
    if ( v3 )
    {
      if ( v3 == 1 )
        Scaleform::GFx::AS2::ArrayObject::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::ScanInUseFunctor>(
          this,
          prcc);
    }
    else
    {
      Scaleform::GFx::AS2::ArrayObject::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::MarkInCycleFunctor>(
        this,
        prcc);
    }
  }
  else
  {
    Scaleform::GFx::AS2::ArrayObject::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseFunctor>(
      this,
      prcc);
  }
}

// File Line: 271
// RVA: 0x6BF830
void __fastcall Scaleform::GFx::AS2::ArrayObject::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseFunctor>(Scaleform::GFx::AS2::ArrayObject *this, Scaleform::GFx::AS2::RefCountCollector<323> *prcc)
{
  Scaleform::GFx::AS2::RefCountCollector<323> *v2; // rbp
  Scaleform::GFx::AS2::ArrayObject *v3; // rsi
  unsigned __int64 v4; // rdi
  unsigned __int64 v5; // rbx
  Scaleform::GFx::AS2::Value *v6; // rcx

  v2 = prcc;
  v3 = this;
  Scaleform::GFx::AS2::Object::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseFunctor>(
    (Scaleform::GFx::AS2::Object *)&this->vfptr,
    prcc);
  v4 = v3->Elements.Data.Size;
  v5 = 0i64;
  if ( v4 )
  {
    do
    {
      v6 = v3->Elements.Data.Data[v5];
      if ( v6 )
        Scaleform::GFx::AS2::Value::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseFunctor>(v6, v2);
      ++v5;
    }
    while ( v5 < v4 );
  }
}

// File Line: 284
// RVA: 0x6E98A0
void __fastcall Scaleform::GFx::AS2::ArrayObject::Finalize_GC(Scaleform::GFx::AS2::ArrayObject *this)
{
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *v1; // rbx
  unsigned __int64 v2; // rdi
  unsigned __int64 v3; // rsi
  signed int v4; // ebp
  Scaleform::GFx::AS2::Value *v5; // rcx
  unsigned int v6; // eax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *v7; // rcx

  v1 = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)this;
  v2 = 0i64;
  v3 = this->Elements.Data.Size;
  if ( v3 )
  {
    v4 = 863;
    do
    {
      v5 = (Scaleform::GFx::AS2::Value *)*(&v1[13].pTable->EntryCount + v2);
      if ( v5 )
      {
        v6 = (unsigned __int8)v5->T.Type;
        if ( (unsigned __int8)v6 > 9u || !_bittest(&v4, v6) )
          Scaleform::GFx::AS2::Value::DropRefs(v5);
      }
      Scaleform::Memory::pGlobalHeap->vfptr->Free(
        Scaleform::Memory::pGlobalHeap,
        (void *)*(&v1[13].pTable->EntryCount + v2++));
    }
    while ( v2 < v3 );
  }
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v1[13].pTable);
  if ( !_InterlockedDecrement((volatile signed __int32 *)(((_QWORD)v1[16].pTable & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::~HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>(v1 + 6);
  v7 = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)v1[10].pTable;
  if ( v7 )
  {
    Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::~HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>(v7);
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v1[10].pTable);
  }
}

// File Line: 310
// RVA: 0x711420
void __fastcall Scaleform::GFx::AS2::ArrayObject::Resize(Scaleform::GFx::AS2::ArrayObject *this, int size)
{
  unsigned __int64 v2; // rbx
  Scaleform::GFx::AS2::ArrayObject *v3; // r14
  unsigned __int64 v4; // rbp
  unsigned __int64 i; // rsi
  Scaleform::GFx::AS2::Value **v6; // rax
  Scaleform::GFx::AS2::Value *v7; // rdi
  unsigned __int64 v8; // r8

  v2 = this->Elements.Data.Size;
  if ( size < 0 )
    size = 0;
  v3 = this;
  v4 = size;
  for ( i = size; i < v2; ++i )
  {
    v6 = v3->Elements.Data.Data;
    v7 = v6[i];
    if ( v7 )
    {
      if ( v7->T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(v6[i]);
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v7);
    }
  }
  if ( v4 >= v3->Elements.Data.Size )
  {
    if ( v4 <= v3->Elements.Data.Policy.Capacity )
      goto LABEL_15;
    v8 = v4 + (v4 >> 2);
  }
  else
  {
    if ( v4 >= v3->Elements.Data.Policy.Capacity >> 1 )
      goto LABEL_15;
    v8 = v4;
  }
  Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
    (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,2>,Scaleform::ArrayDefaultPolicy> *)&v3->Elements,
    &v3->Elements,
    v8);
LABEL_15:
  for ( v3->Elements.Data.Size = v4; v2 < v4; v3->Elements.Data.Data[v2 - 1] = 0i64 )
    ++v2;
}

// File Line: 327
// RVA: 0x71FB40
void __fastcall Scaleform::GFx::AS2::ArrayObject::ShallowCopyFrom(Scaleform::GFx::AS2::ArrayObject *this, Scaleform::GFx::AS2::ArrayObject *ao)
{
  Scaleform::GFx::AS2::ArrayObject *v2; // rdi
  Scaleform::GFx::AS2::ArrayObject *v3; // rbx
  unsigned __int64 v4; // r8
  unsigned __int64 v5; // rax

  v2 = ao;
  v3 = this;
  Scaleform::ArrayData<Scaleform::GFx::AS2::PagedStack<Scaleform::Ptr<Scaleform::GFx::AS2::FunctionObject>,32>::Page *,Scaleform::AllocatorLH<Scaleform::GFx::AS2::PagedStack<Scaleform::Ptr<Scaleform::GFx::AS2::FunctionObject>,32>::Page *,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &this->Elements.Data,
    ao->Elements.Data.Size);
  v4 = v3->Elements.Data.Size;
  v5 = 0i64;
  if ( v4 )
  {
    do
    {
      ++v5;
      v3->Elements.Data.Data[v5 - 1] = v2->Elements.Data.Data[v5 - 1];
    }
    while ( v5 < v4 );
  }
}

// File Line: 336
// RVA: 0x702C10
void __fastcall Scaleform::GFx::AS2::ArrayObject::MakeDeepCopy(Scaleform::GFx::AS2::ArrayObject *this, Scaleform::MemoryHeap *pheap)
{
  Scaleform::MemoryHeap *v2; // r14
  Scaleform::GFx::AS2::ArrayObject *v3; // rdi
  unsigned __int64 v4; // rbx
  unsigned __int64 v5; // rsi
  Scaleform::GFx::AS2::Value *v6; // rax
  Scaleform::GFx::AS2::Value *v7; // rax
  Scaleform::GFx::AS2::Value *v8; // rcx

  v2 = pheap;
  v3 = this;
  v4 = 0i64;
  v5 = this->Elements.Data.Size;
  if ( v5 )
  {
    do
    {
      if ( v3->Elements.Data.Data[v4] )
      {
        v6 = (Scaleform::GFx::AS2::Value *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))v2->vfptr->Alloc)(
                                             v2,
                                             32i64);
        if ( v6 )
        {
          Scaleform::GFx::AS2::Value::Value(v6, v3->Elements.Data.Data[v4], (__int64)v3);
          v8 = v7;
        }
        else
        {
          v8 = 0i64;
        }
        v3->Elements.Data.Data[v4] = v8;
      }
      ++v4;
    }
    while ( v4 < v5 );
  }
}

// File Line: 348
// RVA: 0x702CA0
void __fastcall Scaleform::GFx::AS2::ArrayObject::MakeDeepCopyFrom(Scaleform::GFx::AS2::ArrayObject *this, Scaleform::MemoryHeap *pheap, Scaleform::GFx::AS2::ArrayObject *ao)
{
  Scaleform::GFx::AS2::ArrayObject *v3; // rsi
  Scaleform::MemoryHeap *v4; // r14
  Scaleform::GFx::AS2::ArrayObject *v5; // rdi
  Scaleform::ArrayLH<Scaleform::GFx::AS2::Value *,2,Scaleform::ArrayDefaultPolicy> *v6; // r15
  unsigned __int64 v7; // rbx
  unsigned __int64 v8; // rdi
  Scaleform::GFx::AS2::Value *v9; // rax
  Scaleform::GFx::AS2::Value *v10; // rax
  Scaleform::GFx::AS2::Value *v11; // rcx

  v3 = ao;
  v4 = pheap;
  v5 = this;
  v6 = &this->Elements;
  Scaleform::ArrayData<Scaleform::GFx::AS2::PagedStack<Scaleform::Ptr<Scaleform::GFx::AS2::FunctionObject>,32>::Page *,Scaleform::AllocatorLH<Scaleform::GFx::AS2::PagedStack<Scaleform::Ptr<Scaleform::GFx::AS2::FunctionObject>,32>::Page *,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &this->Elements.Data,
    ao->Elements.Data.Size);
  v7 = 0i64;
  v8 = v5->Elements.Data.Size;
  if ( v8 )
  {
    do
    {
      if ( v3->Elements.Data.Data[v7] )
      {
        v9 = (Scaleform::GFx::AS2::Value *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))v4->vfptr->Alloc)(
                                             v4,
                                             32i64);
        if ( v9 )
        {
          Scaleform::GFx::AS2::Value::Value(v9, v3->Elements.Data.Data[v7], v8);
          v11 = v10;
        }
        else
        {
          v11 = 0i64;
        }
        v6->Data.Data[v7] = v11;
      }
      ++v7;
    }
    while ( v7 < v8 );
  }
}

// File Line: 361
// RVA: 0x6E2500
void __fastcall Scaleform::GFx::AS2::ArrayObject::DetachAll(Scaleform::GFx::AS2::ArrayObject *this)
{
  Scaleform::GFx::AS2::ArrayObject *v1; // rbx

  v1 = this;
  if ( this->Elements.Data.Size && this->Elements.Data.Policy.Capacity & 0xFFFFFFFFFFFFFFFEui64 )
  {
    if ( this->Elements.Data.Data )
    {
      ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      v1->Elements.Data.Data = 0i64;
    }
    v1->Elements.Data.Policy.Capacity = 0i64;
    v1->Elements.Data.Size = 0i64;
  }
  else
  {
    this->Elements.Data.Size = 0i64;
  }
}

// File Line: 366
// RVA: 0x7010F0
void __fastcall Scaleform::GFx::AS2::ArrayObject::JoinToString(Scaleform::GFx::AS2::ArrayObject *this, Scaleform::GFx::AS2::Environment *pEnv, Scaleform::StringBuffer *pbuffer, const char *pDelimiter)
{
  const char *v4; // r14
  Scaleform::StringBuffer *v5; // rbp
  Scaleform::GFx::AS2::Environment *v6; // r15
  Scaleform::GFx::AS2::ArrayObject *v7; // rsi
  unsigned int v8; // ebx
  __int64 v9; // rdi
  Scaleform::GFx::AS2::Value **v10; // rax
  Scaleform::GFx::ASStringNode *v11; // rcx
  bool v12; // zf
  Scaleform::GFx::ASString v13; // [rsp+20h] [rbp-48h]
  __int64 v14; // [rsp+28h] [rbp-40h]
  Scaleform::GFx::AS2::Value v15; // [rsp+30h] [rbp-38h]
  Scaleform::GFx::ASString result; // [rsp+70h] [rbp+8h]

  v14 = -2i64;
  v4 = pDelimiter;
  v5 = pbuffer;
  v6 = pEnv;
  v7 = this;
  Scaleform::StringBuffer::Clear(pbuffer);
  v15.T.Type = 0;
  v8 = 0;
  if ( v7->Elements.Data.Size )
  {
    v9 = 0i64;
    do
    {
      if ( v8 )
        Scaleform::StringBuffer::AppendString(v5, v4, -1i64);
      v10 = v7->Elements.Data.Data;
      if ( v10[v9] )
      {
        Scaleform::GFx::AS2::Value::ToString(v10[v9], &result, v6, -1);
        Scaleform::StringBuffer::AppendString(v5, result.pNode->pData, -1i64);
        v11 = result.pNode;
      }
      else
      {
        Scaleform::GFx::AS2::Value::ToString(&v15, &v13, v6, -1);
        Scaleform::StringBuffer::AppendString(v5, v13.pNode->pData, -1i64);
        v11 = v13.pNode;
      }
      v12 = v11->RefCount-- == 1;
      if ( v12 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v11);
      v9 = ++v8;
    }
    while ( v8 < v7->Elements.Data.Size );
  }
}

// File Line: 388
// RVA: 0x6DEDF0
void __fastcall Scaleform::GFx::AS2::ArrayObject::Concat(Scaleform::GFx::AS2::ArrayObject *this, Scaleform::GFx::AS2::Environment *penv, Scaleform::GFx::AS2::Value *val)
{
  Scaleform::GFx::AS2::Value *v3; // rdi
  Scaleform::GFx::AS2::ArrayObject *v4; // rbx
  Scaleform::GFx::AS2::GlobalContext *v5; // rax
  Scaleform::MemoryHeap *v6; // r14
  Scaleform::GFx::AS2::Object *v7; // rax
  Scaleform::GFx::AS2::Object *v8; // rsi
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v9; // rax
  unsigned __int64 v10; // r15
  unsigned __int64 v11; // rdi
  signed __int64 v12; // r15
  Scaleform::GFx::AS2::Value *v13; // rax
  Scaleform::GFx::AS2::Value *v14; // rax
  Scaleform::GFx::AS2::Value *v15; // rdx
  Scaleform::GFx::AS2::Value *v16; // rax
  Scaleform::GFx::AS2::Value *v17; // rax
  Scaleform::GFx::AS2::Value *v18; // rbp
  unsigned __int64 v19; // rax
  unsigned __int64 v20; // rsi
  unsigned __int64 v21; // r8
  Scaleform::GFx::AS2::Value **v22; // rcx
  Scaleform::LogMessageId messageType; // [rsp+60h] [rbp+8h]
  Scaleform::GFx::AS2::ArrayObject *v24; // [rsp+78h] [rbp+20h]

  v3 = val;
  v4 = this;
  v24 = this;
  if ( ++this->RecursionCount >= 255 )
  {
    messageType.Id = 212992;
    Scaleform::Log::LogMessageById(
      (Scaleform::GFx::LogState *)this->LogPtr,
      (Scaleform::LogMessageId)&messageType,
      "256 levels of recursion is reached\n");
    goto LABEL_24;
  }
  v5 = penv->StringContext.pContext;
  v6 = v5->pHeap;
  *(_QWORD *)&messageType.Id = v5->pHeap;
  v7 = Scaleform::GFx::AS2::Value::ToObject(val, penv);
  v8 = v7;
  if ( v7
    && (*(unsigned int (__cdecl **)(Scaleform::GFx::AS2::ObjectInterfaceVtbl **))&v7->vfptr->gap8[8])(&v7->vfptr) == 7 )
  {
    v9 = v8[1].pPrev;
    if ( v9 )
    {
      v10 = v4->Elements.Data.Size;
      Scaleform::GFx::AS2::ArrayObject::Resize(v4, (_DWORD)v9 + v10);
      v11 = 0i64;
      if ( v8[1].pPrev )
      {
        v12 = 8i64 * (unsigned int)v10;
        do
        {
          v13 = (Scaleform::GFx::AS2::Value *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))v6->vfptr->Alloc)(
                                                v6,
                                                32i64);
          if ( v13 )
          {
            Scaleform::GFx::AS2::Value::Value(v13, (Scaleform::GFx::AS2::Value *)(&v8[1].pRCC->vfptr)[v11], v11);
            v15 = v14;
          }
          else
          {
            v15 = 0i64;
          }
          *(Scaleform::GFx::AS2::Value **)((char *)&v4->Elements.Data.Data[v11++] + v12) = v15;
        }
        while ( (Scaleform::GFx::AS2::RefCountBaseGC<323> *)v11 < v8[1].pPrev );
      }
    }
    goto LABEL_24;
  }
  v16 = (Scaleform::GFx::AS2::Value *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))v6->vfptr->Alloc)(
                                        v6,
                                        32i64);
  if ( v16 )
  {
    Scaleform::GFx::AS2::Value::Value(v16, v3, (__int64)v3);
    v18 = v17;
  }
  else
  {
    v18 = 0i64;
  }
  v19 = v4->Elements.Data.Size;
  v20 = v19 + 1;
  if ( v19 + 1 >= v19 )
  {
    if ( v20 <= v4->Elements.Data.Policy.Capacity )
      goto LABEL_22;
    v21 = v20 + (v20 >> 2);
  }
  else
  {
    if ( v20 >= v4->Elements.Data.Policy.Capacity >> 1 )
      goto LABEL_22;
    v21 = v19 + 1;
  }
  Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
    (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,2>,Scaleform::ArrayDefaultPolicy> *)&v4->Elements,
    &v4->Elements,
    v21);
LABEL_22:
  v4->Elements.Data.Size = v20;
  v22 = &v4->Elements.Data.Data[v20 - 1];
  if ( v22 )
    *v22 = v18;
LABEL_24:
  --v4->RecursionCount;
}

// File Line: 415
// RVA: 0x70AA80
void __fastcall Scaleform::GFx::AS2::ArrayObject::PushBack(Scaleform::GFx::AS2::ArrayObject *this, Scaleform::GFx::AS2::Value *val)
{
  Scaleform::GFx::AS2::Value *v2; // rdi
  Scaleform::GFx::AS2::ArrayObject *v3; // rbx
  Scaleform::GFx::AS2::Value *v4; // rax
  Scaleform::GFx::AS2::Object *v5; // rax
  Scaleform::GFx::AS2::Object *v6; // rsi
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,2>,Scaleform::ArrayDefaultPolicy> *v7; // rbx
  unsigned __int64 v8; // rdi
  unsigned __int64 v9; // r8
  Scaleform::Ptr<Scaleform::GFx::AS2::Object> *v10; // rcx
  int v11; // [rsp+60h] [rbp+18h]
  Scaleform::GFx::AS2::Value *v12; // [rsp+68h] [rbp+20h]

  v2 = val;
  v3 = this;
  v11 = 323;
  v4 = (Scaleform::GFx::AS2::Value *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::GFx::AS2::ArrayObject *, signed __int64, int *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
                                       Scaleform::Memory::pGlobalHeap,
                                       this,
                                       32i64,
                                       &v11,
                                       -2i64);
  v12 = v4;
  if ( v4 )
  {
    Scaleform::GFx::AS2::Value::Value(v4, v2, (__int64)v2);
    v6 = v5;
  }
  else
  {
    v6 = 0i64;
  }
  v7 = (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,2>,Scaleform::ArrayDefaultPolicy> *)&v3->Elements;
  v8 = v7->Size + 1;
  if ( v8 >= v7->Size )
  {
    if ( v8 <= v7->Policy.Capacity )
      goto LABEL_10;
    v9 = v8 + (v8 >> 2);
  }
  else
  {
    if ( v8 >= v7->Policy.Capacity >> 1 )
      goto LABEL_10;
    v9 = v7->Size + 1;
  }
  Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
    v7,
    v7,
    v9);
LABEL_10:
  v7->Size = v8;
  v10 = &v7->Data[v8 - 1];
  if ( v10 )
    v10->pObject = v6;
}

// File Line: 420
// RVA: 0x70AB40
void __fastcall Scaleform::GFx::AS2::ArrayObject::PushBack(Scaleform::GFx::AS2::ArrayObject *this)
{
  unsigned __int64 v1; // rax
  Scaleform::ArrayLH<Scaleform::GFx::AS2::Value *,2,Scaleform::ArrayDefaultPolicy> *v2; // rbx
  unsigned __int64 v3; // rdi
  unsigned __int64 v4; // r8
  Scaleform::GFx::AS2::Value **v5; // rcx
  Scaleform::GFx::AS2::Value **v6; // rcx

  v1 = this->Elements.Data.Size;
  v2 = &this->Elements;
  v3 = v1 + 1;
  if ( v1 + 1 >= v1 )
  {
    if ( v3 <= this->Elements.Data.Policy.Capacity )
      goto LABEL_7;
    v4 = v3 + (v3 >> 2);
  }
  else
  {
    if ( v3 >= this->Elements.Data.Policy.Capacity >> 1 )
      goto LABEL_7;
    v4 = v1 + 1;
  }
  Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
    (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,2>,Scaleform::ArrayDefaultPolicy> *)&this->Elements,
    &this->Elements,
    v4);
LABEL_7:
  v5 = v2->Data.Data;
  v2->Data.Size = v3;
  v6 = &v5[v3 - 1];
  if ( v6 )
    *v6 = 0i64;
}

// File Line: 433
// RVA: 0x70FF90
void __fastcall Scaleform::GFx::AS2::ArrayObject::RemoveElements(Scaleform::GFx::AS2::ArrayObject *this, int start, int count)
{
  __int64 v3; // r15
  int v4; // er12
  Scaleform::GFx::AS2::ArrayObject *v5; // rdi
  signed __int64 v6; // rsi
  __int64 v7; // rbp
  Scaleform::GFx::AS2::Value **v8; // rax
  Scaleform::GFx::AS2::Value *v9; // rbx
  int v10; // er9
  signed __int64 v11; // r8
  Scaleform::GFx::AS2::Value **v12; // rdx
  signed __int64 v13; // rcx
  Scaleform::GFx::AS2::Value *v14; // rax
  unsigned __int64 v15; // rbx
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,2>,Scaleform::ArrayDefaultPolicy> *v16; // rdi
  unsigned __int64 v17; // rbx
  unsigned __int64 v18; // r8

  v3 = count;
  v4 = start;
  v5 = this;
  if ( this->Elements.Data.Size )
  {
    if ( count > 0 )
    {
      v6 = start;
      v7 = count;
      do
      {
        v8 = v5->Elements.Data.Data;
        v9 = v8[v6];
        if ( v9 )
        {
          if ( v9->T.Type >= 5u )
            Scaleform::GFx::AS2::Value::DropRefs(v8[v6]);
          Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v9);
        }
        ++v6;
        --v7;
      }
      while ( v7 );
    }
    v10 = v4 + v3;
    if ( v4 + (signed int)v3 < SLODWORD(v5->Elements.Data.Size) )
    {
      v11 = v10;
      do
      {
        v12 = v5->Elements.Data.Data;
        v13 = -8 * v3 + v11 * 8;
        ++v10;
        v14 = v12[v11];
        ++v11;
        *(Scaleform::GFx::AS2::Value **)((char *)v12 + v13) = v14;
        v5->Elements.Data.Data[v11 - 1] = 0i64;
      }
      while ( v10 < SLODWORD(v5->Elements.Data.Size) );
    }
    v15 = v5->Elements.Data.Size;
    v16 = (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,2>,Scaleform::ArrayDefaultPolicy> *)&v5->Elements;
    v17 = v15 - v3;
    if ( v17 >= v16->Size )
    {
      if ( v17 > v16->Policy.Capacity )
      {
        v18 = v17 + (v17 >> 2);
        goto LABEL_17;
      }
    }
    else if ( v17 < v16->Policy.Capacity >> 1 )
    {
      v18 = v17;
LABEL_17:
      Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        v16,
        v16,
        v18);
      goto LABEL_18;
    }
LABEL_18:
    v16->Size = v17;
  }
}

// File Line: 451
// RVA: 0x6FD7E0
void __fastcall Scaleform::GFx::AS2::ArrayObject::InsertEmpty(Scaleform::GFx::AS2::ArrayObject *this, int start, int count)
{
  int v3; // ebx
  __int64 v4; // rsi
  signed __int64 v5; // r14
  Scaleform::GFx::AS2::ArrayObject *v6; // rbp
  __int64 v7; // r9
  __int64 v8; // r8
  __int64 i; // r10
  signed __int64 v10; // rax
  signed __int64 v11; // rax

  v3 = this->Elements.Data.Size;
  v4 = count;
  v5 = start;
  v6 = this;
  Scaleform::ArrayData<Scaleform::GFx::AS2::PagedStack<Scaleform::Ptr<Scaleform::GFx::AS2::FunctionObject>,32>::Page *,Scaleform::AllocatorLH<Scaleform::GFx::AS2::PagedStack<Scaleform::Ptr<Scaleform::GFx::AS2::FunctionObject>,32>::Page *,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &this->Elements.Data,
    v3 + count);
  v7 = v4;
  if ( v3 )
  {
    v8 = LODWORD(v6->Elements.Data.Size) - 1;
    for ( i = (signed int)v5 + (signed int)v4;
          v8 >= i;
          v6->Elements.Data.Data[v8 + 1] = *(Scaleform::GFx::AS2::Value **)((char *)v6->Elements.Data.Data + v10) )
    {
      v10 = -8 * v4 + 8 * v8--;
    }
  }
  if ( (signed int)v4 > 0 )
  {
    v11 = v5;
    do
    {
      ++v11;
      v6->Elements.Data.Data[v11 - 1] = 0i64;
      --v7;
    }
    while ( v7 );
  }
}

// File Line: 469
// RVA: 0x708510
void __fastcall Scaleform::GFx::AS2::ArrayObject::PopFront(Scaleform::GFx::AS2::ArrayObject *this)
{
  Scaleform::GFx::AS2::ArrayObject *v1; // rdi
  Scaleform::GFx::AS2::Value **v2; // rax
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,2>,Scaleform::ArrayDefaultPolicy> *v3; // rbx
  Scaleform::GFx::AS2::Value *v4; // rsi
  unsigned int v5; // er8
  signed __int64 v6; // r9
  __int64 v7; // rcx
  Scaleform::GFx::AS2::Object *v8; // rax
  unsigned __int64 v9; // rdi
  unsigned __int64 v10; // r8

  v1 = this;
  if ( this->Elements.Data.Size )
  {
    v2 = this->Elements.Data.Data;
    v3 = (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,2>,Scaleform::ArrayDefaultPolicy> *)&this->Elements;
    v4 = *v2;
    if ( *v2 )
    {
      if ( v4->T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(*v2);
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v4);
    }
    v5 = 1;
    if ( v1->Elements.Data.Size > 1 )
    {
      v6 = 1i64;
      do
      {
        v7 = v5++ - 1;
        v8 = v3->Data[v6].pObject;
        v6 = v5;
        v3->Data[v7].pObject = v8;
      }
      while ( v5 < v1->Elements.Data.Size );
    }
    v3->Data[v1->Elements.Data.Size - 1].pObject = 0i64;
    v9 = v1->Elements.Data.Size - 1;
    if ( v9 >= v3->Size )
    {
      if ( v9 > v3->Policy.Capacity )
      {
        v10 = v9 + (v9 >> 2);
        goto LABEL_14;
      }
    }
    else if ( v9 < v3->Policy.Capacity >> 1 )
    {
      v10 = v9;
LABEL_14:
      Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        v3,
        v3,
        v10);
      goto LABEL_15;
    }
LABEL_15:
    v3->Size = v9;
  }
}

// File Line: 483
// RVA: 0x714490
void __fastcall Scaleform::GFx::AS2::ArrayObject::SetElement(Scaleform::GFx::AS2::ArrayObject *this, int i, Scaleform::GFx::AS2::Value *val)
{
  Scaleform::GFx::AS2::Value *v3; // rsi
  Scaleform::GFx::AS2::ArrayObject *v4; // rbx
  unsigned __int64 v5; // rdi
  Scaleform::GFx::AS2::Value *v6; // rax
  Scaleform::GFx::AS2::Value *v7; // rcx
  int v8; // [rsp+58h] [rbp+10h]
  Scaleform::GFx::AS2::Value *v9; // [rsp+68h] [rbp+20h]

  if ( i >= 0 )
  {
    v3 = val;
    v4 = this;
    if ( i < SLODWORD(this->Elements.Data.Size) )
    {
      this->LengthValueOverriden = 0;
      v5 = i;
      if ( !this->Elements.Data.Data[v5] )
      {
        v8 = 323;
        v6 = (Scaleform::GFx::AS2::Value *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::GFx::AS2::ArrayObject *, signed __int64, int *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
                                             Scaleform::Memory::pGlobalHeap,
                                             this,
                                             32i64,
                                             &v8,
                                             -2i64);
        v7 = v6;
        v9 = v6;
        if ( v6 )
          v6->T.Type = 0;
        else
          v7 = 0i64;
        v4->Elements.Data.Data[v5] = v7;
      }
      Scaleform::GFx::AS2::Value::operator=(v4->Elements.Data.Data[v5], v3, v5 * 8);
    }
  }
}

// File Line: 492
// RVA: 0x714530
void __fastcall Scaleform::GFx::AS2::ArrayObject::SetElementSafe(Scaleform::GFx::AS2::ArrayObject *this, int idx, Scaleform::GFx::AS2::Value *val)
{
  Scaleform::GFx::AS2::Value *v3; // rsi
  __int64 v4; // rdi
  Scaleform::GFx::AS2::ArrayObject *v5; // rbx
  __int64 v6; // rdi
  Scaleform::GFx::AS2::Value *v7; // rax
  Scaleform::GFx::AS2::Value *v8; // rcx
  int v9; // [rsp+58h] [rbp+10h]
  Scaleform::GFx::AS2::Value *v10; // [rsp+68h] [rbp+20h]

  v3 = val;
  v4 = idx;
  v5 = this;
  this->LengthValueOverriden = 0;
  if ( idx >= SLODWORD(this->Elements.Data.Size) )
    Scaleform::GFx::AS2::ArrayObject::Resize(this, idx + 1);
  v6 = v4;
  if ( !v5->Elements.Data.Data[v6] )
  {
    v9 = 323;
    v7 = (Scaleform::GFx::AS2::Value *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::GFx::AS2::ArrayObject *, signed __int64, int *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
                                         Scaleform::Memory::pGlobalHeap,
                                         v5,
                                         32i64,
                                         &v9,
                                         -2i64);
    v8 = v7;
    v10 = v7;
    if ( v7 )
      v7->T.Type = 0;
    else
      v8 = 0i64;
    v5->Elements.Data.Data[v6] = v8;
  }
  Scaleform::GFx::AS2::Value::operator=(v5->Elements.Data.Data[v6], v3, v6 * 8);
}

// File Line: 519
// RVA: 0x6BC3A0
void __fastcall Scaleform::GFx::AS2::ArrayObject::ArrayConcat(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rbx
  Scaleform::GFx::AS2::ObjectInterface *v2; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rdi
  Scaleform::GFx::AS2::ArrayObject *v4; // rsi
  int i; // edi
  unsigned int v6; // er9
  Scaleform::GFx::AS2::Environment *v7; // rdx
  Scaleform::GFx::AS2::Value *v8; // r8
  unsigned int v9; // eax
  Scaleform::GFx::AS2::Value val; // [rsp+38h] [rbp-30h]

  v1 = fn;
  v2 = fn->ThisPtr;
  if ( v2 && (*(unsigned int (**)(void))&v2->vfptr->gap8[8])() == 7 )
  {
    v3 = v1->ThisPtr;
    if ( v3 )
      v3 -= 2;
    BYTE4(v3[8].pProto.pObject) = 0;
    v4 = (Scaleform::GFx::AS2::ArrayObject *)Scaleform::GFx::AS2::Environment::OperatorNew(
                                               v1->Env,
                                               v1->Env->StringContext.pContext->pGlobal.pObject,
                                               (Scaleform::GFx::ASString *)&v1->Env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[8].RefCount,
                                               0,
                                               -1);
    if ( v4 )
    {
      Scaleform::GFx::AS2::Value::Value(&val, (Scaleform::GFx::AS2::Object *)v3);
      Scaleform::GFx::AS2::ArrayObject::Concat(v4, v1->Env, &val);
      if ( val.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&val);
      for ( i = 0; i < v1->NArgs; ++i )
      {
        v6 = v1->FirstArgBottomIndex - i;
        v7 = v1->Env;
        v8 = 0i64;
        if ( v6 <= 32 * ((unsigned int)v7->Stack.Pages.Data.Size - 1)
                 + (unsigned int)((_QWORD)((char *)v7->Stack.pCurrent - (char *)v7->Stack.pPageStart) >> 5) )
          v8 = &v7->Stack.Pages.Data.Data[v6 >> 5]->Values[v6 & 0x1F];
        Scaleform::GFx::AS2::ArrayObject::Concat(v4, v7, v8);
      }
    }
    Scaleform::GFx::AS2::Value::SetAsObject(v1->Result, (Scaleform::GFx::AS2::Object *)&v4->vfptr);
    if ( v4 )
    {
      v9 = v4->RefCount;
      if ( v9 & 0x3FFFFFF )
      {
        v4->RefCount = v9 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v4->vfptr);
      }
    }
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      v1->Env,
      "Error: Null or invalid 'this' is used for a method of %s class.\n",
      "Array");
  }
}

// File Line: 539
// RVA: 0x6BC520
void __fastcall Scaleform::GFx::AS2::ArrayObject::ArrayJoin(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rbx
  Scaleform::GFx::AS2::ObjectInterface *v2; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rsi
  Scaleform::GFx::AS2::Value *v4; // rdi
  Scaleform::GFx::AS2::ArrayObject *v5; // rsi
  unsigned int v6; // er9
  Scaleform::GFx::AS2::Environment *v7; // r8
  Scaleform::GFx::ASStringNode *v8; // rcx
  bool v9; // zf
  char *v10; // r8
  Scaleform::GFx::ASString *v11; // rdi
  Scaleform::GFx::AS2::Value *v12; // rbx
  Scaleform::GFx::ASStringNode *v13; // rax
  Scaleform::GFx::ASStringNode *v14; // rcx
  Scaleform::StringBuffer pbuffer; // [rsp+28h] [rbp-40h]
  Scaleform::GFx::ASString result; // [rsp+70h] [rbp+8h]

  v1 = fn;
  v2 = fn->ThisPtr;
  if ( v2 && (*(unsigned int (__cdecl **)(Scaleform::GFx::AS2::ObjectInterface *))&v2->vfptr->gap8[8])(v2) == 7 )
  {
    v3 = v1->ThisPtr;
    v4 = 0i64;
    if ( v3 )
      v5 = (Scaleform::GFx::AS2::ArrayObject *)&v3[-2];
    else
      v5 = 0i64;
    v5->LengthValueOverriden = 0;
    Scaleform::StringBuffer::StringBuffer(&pbuffer, v1->Env->StringContext.pContext->pHeap);
    if ( v1->NArgs )
    {
      v6 = v1->FirstArgBottomIndex;
      v7 = v1->Env;
      if ( v6 <= 32 * ((unsigned int)v7->Stack.Pages.Data.Size - 1)
               + (unsigned int)((_QWORD)((char *)v7->Stack.pCurrent - (char *)v7->Stack.pPageStart) >> 5) )
        v4 = &v7->Stack.Pages.Data.Data[v6 >> 5]->Values[v6 & 0x1F];
      Scaleform::GFx::AS2::Value::ToString(v4, &result, v7, -1);
      Scaleform::GFx::AS2::ArrayObject::JoinToString(v5, v1->Env, &pbuffer, result.pNode->pData);
      v8 = result.pNode;
      v9 = result.pNode->RefCount == 1;
      --v8->RefCount;
      if ( v9 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v8);
    }
    else
    {
      Scaleform::GFx::AS2::ArrayObject::JoinToString(v5, v1->Env, &pbuffer, ",");
    }
    v10 = &customWorldMapCaption;
    if ( pbuffer.pData )
      v10 = pbuffer.pData;
    v11 = Scaleform::GFx::AS2::Environment::CreateString(v1->Env, &result, v10, pbuffer.Size);
    v12 = v1->Result;
    if ( v12->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(v12);
    v12->T.Type = 5;
    v13 = v11->pNode;
    v12->NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)v11->pNode;
    ++v13->RefCount;
    v14 = result.pNode;
    v9 = result.pNode->RefCount == 1;
    --v14->RefCount;
    if ( v9 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v14);
    Scaleform::ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayDataBase<int,Scaleform::AllocatorGH<int,2>,Scaleform::ArrayDefaultPolicy> *)&pbuffer);
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      v1->Env,
      "Error: Null or invalid 'this' is used for a method of %s class.\n",
      "Array");
  }
}

// File Line: 560
// RVA: 0x6A50D0
void __fastcall Scaleform::GFx::AS2::ArrayObject::ArrayPop(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rbx
  Scaleform::GFx::AS2::ObjectInterface *v2; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rdi
  int v4; // eax
  Scaleform::GFx::AS2::Value *v5; // rdx
  Scaleform::GFx::AS2::Value *v6; // rbx
  Scaleform::GFx::AS2::Value *v7; // rbx

  v1 = fn;
  v2 = fn->ThisPtr;
  if ( v2 && (*(unsigned int (**)(void))&v2->vfptr->gap8[8])() == 7 )
  {
    v3 = v1->ThisPtr;
    if ( v3 )
      v3 -= 2;
    v4 = (int)v3[7].vfptr;
    BYTE4(v3[8].pProto.pObject) = 0;
    if ( v4 )
    {
      v5 = (Scaleform::GFx::AS2::Value *)*((_QWORD *)&v3[6].pProto.pObject->vfptr + v4 - 1);
      if ( v5 )
      {
        Scaleform::GFx::AS2::Value::operator=(v1->Result, v5);
      }
      else
      {
        v6 = v1->Result;
        Scaleform::GFx::AS2::Value::DropRefs(v6);
        v6->T.Type = 0;
      }
      if ( v3[7].vfptr )
        Scaleform::GFx::AS2::ArrayObject::Resize((Scaleform::GFx::AS2::ArrayObject *)v3, LODWORD(v3[7].vfptr) - 1);
    }
    else
    {
      v7 = v1->Result;
      Scaleform::GFx::AS2::Value::DropRefs(v7);
      v7->T.Type = 0;
    }
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      v1->Env,
      "Error: Null or invalid 'this' is used for a method of %s class.\n",
      "Array");
  }
}

// File Line: 580
// RVA: 0x6A51A0
void __fastcall Scaleform::GFx::AS2::ArrayObject::ArrayPush(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rbx
  Scaleform::GFx::AS2::ObjectInterface *v2; // rcx
  Scaleform::GFx::AS2::ArrayObject *v3; // rsi
  int v4; // edi
  Scaleform::GFx::AS2::Environment *v5; // r8
  Scaleform::GFx::AS2::Value *v6; // rdx
  unsigned int v7; // er9
  Scaleform::GFx::AS2::Value *v8; // rbx
  unsigned __int64 v9; // rdi

  v1 = fn;
  v2 = fn->ThisPtr;
  if ( v2 && (*(unsigned int (**)(void))&v2->vfptr->gap8[8])() == 7 )
  {
    v3 = (Scaleform::GFx::AS2::ArrayObject *)v1->ThisPtr;
    if ( v3 )
      v3 = (Scaleform::GFx::AS2::ArrayObject *)((char *)v3 - 32);
    v4 = 0;
    for ( v3->LengthValueOverriden = 0; v4 < v1->NArgs; ++v4 )
    {
      v5 = v1->Env;
      v6 = 0i64;
      v7 = v1->FirstArgBottomIndex - v4;
      if ( v7 <= 32 * (LODWORD(v5->Stack.Pages.Data.Size) - 1)
               + (unsigned int)((_QWORD)((char *)v5->Stack.pCurrent - (char *)v5->Stack.pPageStart) >> 5) )
        v6 = &v5->Stack.Pages.Data.Data[(unsigned __int64)v7 >> 5]->Values[v7 & 0x1F];
      Scaleform::GFx::AS2::ArrayObject::PushBack(v3, v6);
    }
    v8 = v1->Result;
    v9 = v3->Elements.Data.Size;
    if ( v8->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(v8);
    v8->NV.Int32Value = v9;
    v8->T.Type = 4;
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      v1->Env,
      "Error: Null or invalid 'this' is used for a method of %s class.\n",
      "Array");
  }
}

// File Line: 594
// RVA: 0x6A5290
void __fastcall Scaleform::GFx::AS2::ArrayObject::ArrayReverse(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rbx
  Scaleform::GFx::AS2::ObjectInterface *v2; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // r11
  __int64 v4; // rdx
  signed __int64 v5; // r11
  int v6; // eax
  __int64 v7; // r10
  __int64 v8; // rax
  __int64 v9; // r8
  _QWORD *v10; // r9
  _QWORD *v11; // rcx

  v1 = fn;
  v2 = fn->ThisPtr;
  if ( v2 && (*(unsigned int (**)(void))&v2->vfptr->gap8[8])() == 7 )
  {
    v3 = v1->ThisPtr;
    v4 = 0i64;
    if ( v3 )
      v5 = (signed __int64)&v3[-2];
    else
      v5 = 0i64;
    v6 = *(_DWORD *)(v5 + 112);
    *(_BYTE *)(v5 + 140) = 0;
    v7 = --v6;
    if ( v6 > 0 )
    {
      do
      {
        v8 = *(_QWORD *)(v5 + 104);
        v9 = *(_QWORD *)(v8 + 8 * v4);
        v10 = (_QWORD *)(v8 + 8 * v7);
        v11 = (_QWORD *)(v8 + 8 * v4++);
        --v7;
        *v11 = *v10;
        *v10 = v9;
      }
      while ( v4 < v7 );
    }
    Scaleform::GFx::AS2::Value::SetAsObject(v1->Result, (Scaleform::GFx::AS2::Object *)v5);
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      v1->Env,
      "Error: Null or invalid 'this' is used for a method of %s class.\n",
      "Array");
  }
}

// File Line: 608
// RVA: 0x6A5350
void __fastcall Scaleform::GFx::AS2::ArrayObject::ArrayShift(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rbx
  Scaleform::GFx::AS2::ObjectInterface *v2; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rdi
  Scaleform::GFx::AS2::Value *v4; // rbx
  Scaleform::GFx::AS2::Value **v5; // rax
  Scaleform::GFx::AS2::Value *v6; // rbx

  v1 = fn;
  v2 = fn->ThisPtr;
  if ( v2 && (*(unsigned int (**)(void))&v2->vfptr->gap8[8])() == 7 )
  {
    v3 = v1->ThisPtr;
    if ( v3 )
      v3 -= 2;
    if ( LODWORD(v3[7].vfptr) )
    {
      v5 = (Scaleform::GFx::AS2::Value **)v3[6].pProto.pObject;
      BYTE4(v3[8].pProto.pObject) = 0;
      if ( *v5 )
      {
        Scaleform::GFx::AS2::Value::operator=(v1->Result, *v5);
      }
      else
      {
        v6 = v1->Result;
        Scaleform::GFx::AS2::Value::DropRefs(v6);
        v6->T.Type = 0;
      }
      Scaleform::GFx::AS2::ArrayObject::PopFront((Scaleform::GFx::AS2::ArrayObject *)v3);
    }
    else
    {
      v4 = v1->Result;
      Scaleform::GFx::AS2::Value::DropRefs(v4);
      v4->T.Type = 0;
    }
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      v1->Env,
      "Error: Null or invalid 'this' is used for a method of %s class.\n",
      "Array");
  }
}

// File Line: 627
// RVA: 0x6A54E0
void __fastcall Scaleform::GFx::AS2::ArrayObject::ArraySlice(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // r14
  Scaleform::GFx::AS2::ObjectInterface *v2; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rsi
  signed __int64 v4; // rsi
  __int64 v5; // rbx
  __int64 i; // rbp
  unsigned int v7; // er10
  Scaleform::GFx::AS2::Environment *v8; // rdx
  Scaleform::GFx::AS2::Value *v9; // r9
  unsigned int v10; // er9
  Scaleform::GFx::AS2::Environment *v11; // rdx
  Scaleform::GFx::AS2::Value *v12; // r10
  __int64 v13; // rax
  Scaleform::GFx::AS2::ArrayObject *v14; // rdi
  Scaleform::GFx::AS2::Value *v15; // rdx
  unsigned int v16; // eax

  v1 = fn;
  v2 = fn->ThisPtr;
  if ( v2 && (*(unsigned int (**)(void))&v2->vfptr->gap8[8])() == 7 )
  {
    v3 = v1->ThisPtr;
    if ( v3 )
      v4 = (signed __int64)&v3[-2];
    else
      v4 = 0i64;
    *(_BYTE *)(v4 + 140) = 0;
    LODWORD(v5) = 0;
    i = *(_QWORD *)(v4 + 112);
    if ( v1->NArgs >= 1 )
    {
      v7 = v1->FirstArgBottomIndex;
      v8 = v1->Env;
      v9 = 0i64;
      if ( v7 <= 32 * ((unsigned int)v8->Stack.Pages.Data.Size - 1)
               + (unsigned int)((_QWORD)((char *)v8->Stack.pCurrent - (char *)v8->Stack.pPageStart) >> 5) )
        v9 = &v8->Stack.Pages.Data.Data[v7 >> 5]->Values[v7 & 0x1F];
      LODWORD(v5) = Scaleform::GFx::AS2::Value::ToInt32(v9, v8);
      if ( (signed int)v5 < 0 )
      {
        LODWORD(v5) = *(_DWORD *)(v4 + 112) + v5;
        if ( (signed int)v5 < 0 )
          LODWORD(v5) = 0;
      }
      if ( (signed int)v5 > (signed int)*(_QWORD *)(v4 + 112) )
        v5 = *(_QWORD *)(v4 + 112);
    }
    if ( v1->NArgs >= 2 )
    {
      v10 = v1->FirstArgBottomIndex - 1;
      v11 = v1->Env;
      v12 = 0i64;
      if ( v10 <= 32 * ((unsigned int)v11->Stack.Pages.Data.Size - 1)
                + (unsigned int)((_QWORD)((char *)v11->Stack.pCurrent - (char *)v11->Stack.pPageStart) >> 5) )
        v12 = &v11->Stack.Pages.Data.Data[v10 >> 5]->Values[v10 & 0x1F];
      LODWORD(i) = Scaleform::GFx::AS2::Value::ToInt32(v12, v11);
      if ( (signed int)i < 0 )
      {
        LODWORD(i) = *(_DWORD *)(v4 + 112) + i;
        if ( (signed int)i < 0 )
          LODWORD(i) = 0;
      }
      v13 = *(_QWORD *)(v4 + 112);
      if ( (signed int)i > (signed int)v13 )
        LODWORD(i) = *(_QWORD *)(v4 + 112);
    }
    v14 = (Scaleform::GFx::AS2::ArrayObject *)Scaleform::GFx::AS2::Environment::OperatorNew(
                                                v1->Env,
                                                v1->Env->StringContext.pContext->pGlobal.pObject,
                                                (Scaleform::GFx::ASString *)&v1->Env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[8].RefCount,
                                                0,
                                                -1);
    if ( v14 )
    {
      v5 = (signed int)v5;
      for ( i = (signed int)i; v5 < i; ++v5 )
      {
        v15 = *(Scaleform::GFx::AS2::Value **)(*(_QWORD *)(v4 + 104) + 8 * v5);
        if ( v15 )
          Scaleform::GFx::AS2::ArrayObject::PushBack(v14, v15);
        else
          Scaleform::GFx::AS2::ArrayObject::PushBack(v14);
      }
    }
    Scaleform::GFx::AS2::Value::SetAsObject(v1->Result, (Scaleform::GFx::AS2::Object *)&v14->vfptr);
    if ( v14 )
    {
      v16 = v14->RefCount;
      if ( v16 & 0x3FFFFFF )
      {
        v14->RefCount = v16 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v14->vfptr);
      }
    }
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      v1->Env,
      "Error: Null or invalid 'this' is used for a method of %s class.\n",
      "Array");
  }
}

// File Line: 671
// RVA: 0x6A56F0
void __fastcall Scaleform::GFx::AS2::ArrayObject::ArraySort(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rdi
  Scaleform::GFx::AS2::ObjectInterface *v2; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rax
  Scaleform::GFx::AS2::ArrayObject *v4; // r12
  Scaleform::GFx::AS2::FunctionObject *v5; // r15
  Scaleform::GFx::AS2::LocalFrame *v6; // r13
  int v7; // er14
  unsigned int v8; // er9
  Scaleform::GFx::AS2::Environment *v9; // r8
  Scaleform::GFx::AS2::Value *v10; // r10
  Scaleform::GFx::AS2::Value *v11; // r10
  Scaleform::GFx::AS2::Value *v12; // r10
  Scaleform::GFx::AS2::FunctionRef *v13; // rax
  char v14; // al
  Scaleform::GFx::AS2::FunctionObject *v15; // rcx
  unsigned int v16; // edx
  Scaleform::GFx::AS2::LocalFrame *v17; // rcx
  unsigned int v18; // eax
  unsigned int v19; // er8
  Scaleform::GFx::AS2::Environment *v20; // r10
  Scaleform::GFx::AS2::Value *v21; // r9
  Scaleform::GFx::AS2::ArrayObject *v22; // rax
  Scaleform::GFx::AS2::ArrayObject *v23; // rbx
  Scaleform::Log *v24; // rsi
  signed int v25; // esi
  signed __int64 v26; // r14
  Scaleform::GFx::AS2::Value *v27; // rdi
  char v28; // di
  Scaleform::GFx::AS2::FunctionObject *v29; // rcx
  unsigned int v30; // eax
  Scaleform::GFx::AS2::Object *v31; // rdx
  Scaleform::GFx::AS2::FunctionObject *v32; // rcx
  unsigned int v33; // eax
  Scaleform::GFx::AS2::LocalFrame *v34; // rcx
  unsigned int v35; // eax
  unsigned int v36; // eax
  char v37; // bl
  unsigned int v38; // eax
  unsigned int v39; // eax
  Scaleform::GFx::AS2::FunctionRefBase v40; // [rsp+30h] [rbp-49h]
  Scaleform::GFx::AS2::ArraySortFunctor v41; // [rsp+48h] [rbp-31h]
  Scaleform::GFx::AS2::FunctionRef result; // [rsp+80h] [rbp+7h]
  __int64 v43; // [rsp+98h] [rbp+1Fh]
  int v44; // [rsp+E0h] [rbp+67h]
  Scaleform::GFx::AS2::Environment *v45; // [rsp+E8h] [rbp+6Fh]

  v43 = -2i64;
  v1 = fn;
  v2 = fn->ThisPtr;
  if ( v2 && (*(unsigned int (**)(void))&v2->vfptr->gap8[8])() == 7 )
  {
    v3 = v1->ThisPtr;
    v4 = (Scaleform::GFx::AS2::ArrayObject *)&v3[-2];
    if ( !v3 )
      v4 = 0i64;
    v4->LengthValueOverriden = 0;
    v40.Flags = 0;
    v5 = 0i64;
    v40.Function = 0i64;
    v6 = 0i64;
    v40.pLocalFrame = 0i64;
    v7 = 0;
    v44 = 0;
    if ( v1->NArgs >= 1 )
    {
      v8 = v1->FirstArgBottomIndex;
      v9 = v1->Env;
      v10 = 0i64;
      if ( v8 <= 32 * ((unsigned int)v9->Stack.Pages.Data.Size - 1)
               + (unsigned int)((_QWORD)((char *)v9->Stack.pCurrent - (char *)v9->Stack.pPageStart) >> 5) )
        v10 = &v9->Stack.Pages.Data.Data[v8 >> 5]->Values[v8 & 0x1F];
      if ( v10->T.Type == 8 || v10->T.Type == 11 )
      {
        v12 = 0i64;
        if ( v8 <= 32 * ((unsigned int)v9->Stack.Pages.Data.Size - 1)
                 + (unsigned int)((_QWORD)((char *)v9->Stack.pCurrent - (char *)v9->Stack.pPageStart) >> 5) )
          v12 = &v9->Stack.Pages.Data.Data[v8 >> 5]->Values[v8 & 0x1F];
        v13 = Scaleform::GFx::AS2::Value::ToFunction(v12, &result, v9);
        Scaleform::GFx::AS2::FunctionRefBase::Assign(&v40, (Scaleform::GFx::AS2::FunctionRefBase *)&v13->Function);
        v14 = result.Flags;
        if ( !(result.Flags & 2) )
        {
          v15 = result.Function;
          if ( result.Function )
          {
            v16 = result.Function->RefCount;
            if ( v16 & 0x3FFFFFF )
            {
              result.Function->RefCount = v16 - 1;
              Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v15->vfptr);
              v14 = result.Flags;
            }
          }
        }
        result.Function = 0i64;
        if ( !(v14 & 1) )
        {
          v17 = result.pLocalFrame;
          if ( result.pLocalFrame )
          {
            v18 = result.pLocalFrame->RefCount;
            if ( v18 & 0x3FFFFFF )
            {
              result.pLocalFrame->RefCount = v18 - 1;
              Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v17->vfptr);
            }
          }
        }
        result.pLocalFrame = 0i64;
        v6 = v40.pLocalFrame;
        v5 = v40.Function;
      }
      else
      {
        v11 = 0i64;
        if ( v8 <= 32 * ((unsigned int)v9->Stack.Pages.Data.Size - 1)
                 + (unsigned int)((_QWORD)((char *)v9->Stack.pCurrent - (char *)v9->Stack.pPageStart) >> 5) )
          v11 = &v9->Stack.Pages.Data.Data[v8 >> 5]->Values[v8 & 0x1F];
        v7 = Scaleform::GFx::AS2::Value::ToInt32(v11, v1->Env);
        v44 = v7;
      }
    }
    if ( v5 && v1->NArgs >= 2 )
    {
      v19 = v1->FirstArgBottomIndex - 1;
      v20 = v1->Env;
      v21 = 0i64;
      if ( v19 <= 32 * ((unsigned int)v20->Stack.Pages.Data.Size - 1)
                + (unsigned int)((_QWORD)((char *)v20->Stack.pCurrent - (char *)v20->Stack.pPageStart) >> 5) )
        v21 = &v20->Stack.Pages.Data.Data[v19 >> 5]->Values[v19 & 0x1F];
      v7 = Scaleform::GFx::AS2::Value::ToInt32(v21, v1->Env);
      v44 = v7;
    }
    v22 = (Scaleform::GFx::AS2::ArrayObject *)Scaleform::GFx::AS2::Environment::OperatorNew(
                                                v1->Env,
                                                v1->Env->StringContext.pContext->pGlobal.pObject,
                                                (Scaleform::GFx::ASString *)&v1->Env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[8].RefCount,
                                                0,
                                                -1);
    v23 = v22;
    if ( v22 )
    {
      Scaleform::GFx::AS2::ArrayObject::ShallowCopyFrom(v22, v4);
      v24 = v4->LogPtr;
      v45 = v1->Env;
      v41.This = (Scaleform::GFx::AS2::ObjectInterface *)&v23->vfptr;
      v41.Flags = v7;
      v41.Func.Flags = 0;
      v41.Func.Function = v5;
      if ( v5 )
        v5->RefCount = (v5->RefCount + 1) & 0x8FFFFFFF;
      v41.Func.pLocalFrame = 0i64;
      if ( v6 )
        Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(
          (Scaleform::GFx::AS2::FunctionRefBase *)&v41.Func.Function,
          v6,
          v40.Flags & 1);
      v41.Env = v45;
      v41.LogPtr = v24;
      if ( !Scaleform::GFx::AS2::ArrayObject::Sort<Scaleform::GFx::AS2::ArraySortFunctor>(v23, &v41) )
        Scaleform::GFx::AS2::Environment::LogScriptError(
          v1->Env,
          "Array.sort - sorting failed, check your sort functor");
      if ( v7 & 4 && (v25 = 1, SLODWORD(v23->Elements.Data.Size) > 1) )
      {
        v26 = 1i64;
        while ( Scaleform::GFx::AS2::ArraySortFunctor::Compare(
                  &v41,
                  v23->Elements.Data.Data[v26 - 1],
                  v23->Elements.Data.Data[v26]) )
        {
          ++v25;
          ++v26;
          if ( v25 >= SLODWORD(v23->Elements.Data.Size) )
          {
            LOBYTE(v7) = v44;
            goto LABEL_53;
          }
        }
        v27 = v1->Result;
        if ( v27->T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(v27);
        v27->T.Type = 4;
        v27->NV.Int32Value = 0;
        if ( v23->Elements.Data.Size && v23->Elements.Data.Policy.Capacity & 0xFFFFFFFFFFFFFFFEui64 )
        {
          if ( v23->Elements.Data.Data )
          {
            ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
            v23->Elements.Data.Data = 0i64;
          }
          v23->Elements.Data.Policy.Capacity = 0i64;
        }
        v23->Elements.Data.Size = 0i64;
        v28 = v41.Func.Flags;
        if ( !(v41.Func.Flags & 2) )
        {
          v29 = v41.Func.Function;
          if ( v41.Func.Function )
          {
            v30 = v41.Func.Function->RefCount;
            if ( v30 & 0x3FFFFFF )
            {
              v41.Func.Function->RefCount = v30 - 1;
              Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v29->vfptr);
            }
          }
        }
      }
      else
      {
LABEL_53:
        if ( v7 & 8 )
        {
          Scaleform::GFx::AS2::ArrayObject::MakeDeepCopy(v23, v1->Env->StringContext.pContext->pHeap);
          v31 = (Scaleform::GFx::AS2::Object *)&v23->vfptr;
        }
        else
        {
          Scaleform::GFx::AS2::ArrayObject::ShallowCopyFrom(v4, v23);
          Scaleform::GFx::AS2::ArrayObject::DetachAll(v23);
          v31 = (Scaleform::GFx::AS2::Object *)&v4->vfptr;
        }
        Scaleform::GFx::AS2::Value::SetAsObject(v1->Result, v31);
        v28 = v41.Func.Flags;
        if ( !(v41.Func.Flags & 2) )
        {
          v32 = v41.Func.Function;
          if ( v41.Func.Function )
          {
            v33 = v41.Func.Function->RefCount;
            if ( v33 & 0x3FFFFFF )
            {
              v41.Func.Function->RefCount = v33 - 1;
              Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v32->vfptr);
            }
          }
        }
      }
      v41.Func.Function = 0i64;
      if ( !(v28 & 1) )
      {
        v34 = v41.Func.pLocalFrame;
        if ( v41.Func.pLocalFrame )
        {
          v35 = v41.Func.pLocalFrame->RefCount;
          if ( v35 & 0x3FFFFFF )
          {
            v41.Func.pLocalFrame->RefCount = v35 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v34->vfptr);
          }
        }
      }
      v41.Func.pLocalFrame = 0i64;
    }
    if ( v23 )
    {
      v36 = v23->RefCount;
      if ( v36 & 0x3FFFFFF )
      {
        v23->RefCount = v36 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v23->vfptr);
      }
    }
    v37 = v40.Flags;
    if ( !(v40.Flags & 2) )
    {
      if ( v5 )
      {
        v38 = v5->RefCount;
        if ( v38 & 0x3FFFFFF )
        {
          v5->RefCount = v38 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v5->vfptr);
        }
      }
    }
    v40.Function = 0i64;
    if ( !(v37 & 1) && v6 )
    {
      v39 = v6->RefCount;
      if ( v39 & 0x3FFFFFF )
      {
        v6->RefCount = v39 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v6->vfptr);
      }
    }
    v40.pLocalFrame = 0i64;
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      v1->Env,
      "Error: Null or invalid 'this' is used for a method of %s class.\n",
      "Array");
  }
}

// File Line: 745
// RVA: 0x6A5C00
void __fastcall Scaleform::GFx::AS2::ArrayObject::ArraySortOn(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // r14
  Scaleform::GFx::AS2::ObjectInterface *v2; // rcx
  __int64 v3; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v4; // rax
  unsigned __int64 v5; // rbx
  signed __int64 v6; // r12
  __int64 v7; // rdi
  Scaleform::GFx::ASMovieRootBase *v8; // rax
  __int64 v9; // rax
  Scaleform::GFx::AS2::Value *v10; // rbx
  Scaleform::GFx::ASStringNode *v11; // r13
  unsigned int v12; // er10
  Scaleform::GFx::AS2::Environment *v13; // r9
  Scaleform::GFx::AS2::Value *v14; // r8
  Scaleform::GFx::AS2::Object *v15; // rax
  Scaleform::GFx::AS2::Object *v16; // r15
  signed int v17; // esi
  Scaleform::GFx::AS2::Value *v18; // rcx
  Scaleform::GFx::ASString *v19; // rax
  Scaleform::GFx::ASStringNode *v20; // rcx
  bool v21; // zf
  Scaleform::GFx::ASStringNode **v22; // rdx
  Scaleform::GFx::AS2::Value *v23; // rax
  Scaleform::GFx::ASString *v24; // rax
  Scaleform::GFx::ASStringNode *v25; // rcx
  int v26; // esi
  unsigned __int64 v27; // rcx
  unsigned __int64 v28; // r8
  int *v29; // rdx
  unsigned int v30; // er8
  Scaleform::GFx::AS2::Environment *v31; // r10
  Scaleform::GFx::AS2::Value *v32; // r9
  Scaleform::GFx::AS2::Object *v33; // rax
  Scaleform::GFx::AS2::Object *v34; // r13
  signed int v35; // esi
  __int64 v36; // r12
  __int64 v37; // r15
  Scaleform::GFx::AS2::Value *v38; // rcx
  int *v39; // rbx
  unsigned int v40; // er8
  Scaleform::GFx::AS2::Environment *v41; // r10
  Scaleform::GFx::AS2::Value *v42; // r9
  int v43; // eax
  int v44; // er8
  __int64 v45; // rdx
  Scaleform::GFx::AS2::Object *v46; // rax
  Scaleform::GFx::AS2::ArrayObject *v47; // r15
  unsigned __int64 v48; // rbx
  unsigned __int64 v49; // r8
  $8D47FECC8062B48992CD8F53EA11C4BE *v50; // rdx
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,2>,Scaleform::ArrayDefaultPolicy> *v51; // rcx
  unsigned __int64 v52; // rdx
  unsigned __int64 v53; // rcx
  unsigned int v54; // ebx
  char v55; // al
  signed int v56; // ebx
  signed __int64 v57; // r12
  Scaleform::GFx::AS2::Value *v58; // rbx
  Scaleform::GFx::AS2::Object *v59; // rdx
  unsigned __int64 v60; // r12
  unsigned __int64 v61; // r8
  unsigned __int64 v62; // rdx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v63; // r8
  unsigned int v64; // eax
  Scaleform::GFx::ASStringNode *v65; // rcx
  __int64 v66; // rsi
  signed __int64 i; // rbx
  Scaleform::GFx::ASStringNode *v68; // rcx
  Scaleform::ArrayDataBase<int,Scaleform::AllocatorGH<int,2>,Scaleform::ArrayDefaultPolicy> pheapAddr; // [rsp+30h] [rbp-D0h]
  Scaleform::ArrayData<Scaleform::GFx::AS2::ArraySortFunctor,Scaleform::AllocatorGH<Scaleform::GFx::AS2::ArraySortFunctor,2>,Scaleform::ArrayDefaultPolicy> *v70; // [rsp+48h] [rbp-B8h]
  __int128 *v71; // [rsp+50h] [rbp-B0h]
  Scaleform::ArrayData<Scaleform::GFx::AS2::ArraySortFunctor,Scaleform::AllocatorGH<Scaleform::GFx::AS2::ArraySortFunctor,2>,Scaleform::ArrayDefaultPolicy> *v72; // [rsp+58h] [rbp-A8h]
  __int128 v73; // [rsp+60h] [rbp-A0h]
  __int128 v74; // [rsp+70h] [rbp-90h]
  Scaleform::ArrayData<Scaleform::GFx::AS2::ArraySortFunctor,Scaleform::AllocatorGH<Scaleform::GFx::AS2::ArraySortFunctor,2>,Scaleform::ArrayDefaultPolicy> a; // [rsp+80h] [rbp-80h]
  Scaleform::GFx::AS2::ArraySortOnFunctor v76; // [rsp+98h] [rbp-68h]
  Scaleform::GFx::AS2::Value **v77; // [rsp+D0h] [rbp-30h]
  __int64 v78; // [rsp+D8h] [rbp-28h]
  __int128 v79; // [rsp+E0h] [rbp-20h]
  __int128 v80; // [rsp+F0h] [rbp-10h]
  Scaleform::ArrayData<Scaleform::GFx::AS2::ArraySortFunctor,Scaleform::AllocatorGH<Scaleform::GFx::AS2::ArraySortFunctor,2>,Scaleform::ArrayDefaultPolicy> v81; // [rsp+100h] [rbp+0h]
  __int64 v82; // [rsp+118h] [rbp+18h]
  __int64 v83; // [rsp+120h] [rbp+20h]
  int v84; // [rsp+180h] [rbp+80h]
  Scaleform::GFx::ASStringNode *v85; // [rsp+188h] [rbp+88h]
  Scaleform::GFx::AS2::Object *obj; // [rsp+190h] [rbp+90h]
  Scaleform::GFx::ASString result; // [rsp+198h] [rbp+98h]

  v83 = -2i64;
  v1 = fn;
  v2 = fn->ThisPtr;
  if ( !v2 || (*(unsigned int (**)(void))&v2->vfptr->gap8[8])() != 7 )
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      v1->Env,
      "Error: Null or invalid 'this' is used for a method of %s class.\n",
      "Array");
    return;
  }
  v4 = v1->ThisPtr;
  v5 = 0i64;
  v6 = (signed __int64)&v4[-2];
  if ( !v4 )
    v6 = 0i64;
  obj = (Scaleform::GFx::AS2::Object *)v6;
  v7 = ((__int64 (__fastcall *)(__int64, signed __int64))v1->Env->StringContext.pContext->pHeap->vfptr->Alloc)(
         v3,
         32i64);
  if ( v7 )
  {
    v8 = v1->Env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject;
    result.pNode = (Scaleform::GFx::ASStringNode *)v7;
    *(_QWORD *)v7 = 0i64;
    *(_QWORD *)(v7 + 8) = 0i64;
    *(_QWORD *)(v7 + 16) = 0i64;
    v9 = *(_QWORD *)&v8[7].AVMVersion;
    *(_QWORD *)(v7 + 24) = v9;
    ++*(_DWORD *)(v9 + 24);
  }
  else
  {
    v7 = 0i64;
  }
  v82 = v7;
  pheapAddr.Data = 0i64;
  pheapAddr.Size = 0i64;
  pheapAddr.Policy.Capacity = 0i64;
  v84 = 0;
  if ( v1->NArgs )
  {
    *(_BYTE *)(v6 + 140) = 0;
    v11 = (Scaleform::GFx::ASStringNode *)v1->Env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[17].pMovieImpl;
    v85 = v11;
    ++v11->RefCount;
    if ( v1->NArgs >= 1 )
    {
      v12 = v1->FirstArgBottomIndex;
      v13 = v1->Env;
      v14 = 0i64;
      if ( v12 <= 32 * ((unsigned int)v13->Stack.Pages.Data.Size - 1)
                + (unsigned int)((_QWORD)((char *)v13->Stack.pCurrent - (char *)v13->Stack.pPageStart) >> 5) )
        v14 = &v13->Stack.Pages.Data.Data[v12 >> 5]->Values[v12 & 0x1F];
      v15 = Scaleform::GFx::AS2::Value::ToObject(v14, v1->Env);
      v16 = v15;
      if ( v15 && (*(unsigned int (**)(void))&v15->vfptr->gap8[8])() == 7 )
      {
        v17 = 0;
        if ( (signed int)v16[1].RootIndex > 0 )
        {
          do
          {
            v18 = *(Scaleform::GFx::AS2::Value **)((char *)&v16[1].pRCC->vfptr + v5);
            if ( v18 )
            {
              v19 = Scaleform::GFx::AS2::Value::ToString(v18, &result, v1->Env, -1);
              Scaleform::ArrayBase<Scaleform::ArrayDataCC<Scaleform::GFx::ASString,Scaleform::AllocatorLH<Scaleform::GFx::ASString,323>,Scaleform::ArrayDefaultPolicy>>::PushBack(
                (Scaleform::ArrayBase<Scaleform::ArrayDataCC<Scaleform::GFx::ASString,Scaleform::AllocatorLH<Scaleform::GFx::ASString,323>,Scaleform::ArrayDefaultPolicy> > *)v7,
                v19);
              v20 = result.pNode;
              v21 = result.pNode->RefCount == 1;
              --v20->RefCount;
              if ( v21 )
                Scaleform::GFx::ASStringNode::ReleaseNode(v20);
            }
            else
            {
              Scaleform::ArrayDataBase<Scaleform::GFx::ASString,Scaleform::AllocatorLH<Scaleform::GFx::ASString,323>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
                (Scaleform::ArrayDataBase<Scaleform::GFx::ASString,Scaleform::AllocatorLH<Scaleform::GFx::ASString,323>,Scaleform::ArrayDefaultPolicy> *)v7,
                (const void *)v7,
                *(_QWORD *)(v7 + 8) + 1i64);
              v22 = (Scaleform::GFx::ASStringNode **)(*(_QWORD *)v7 + 8 * (*(_QWORD *)(v7 + 8) - 1i64));
              v72 = (Scaleform::ArrayData<Scaleform::GFx::AS2::ArraySortFunctor,Scaleform::AllocatorGH<Scaleform::GFx::AS2::ArraySortFunctor,2>,Scaleform::ArrayDefaultPolicy> *)v22;
              v71 = (__int128 *)v22;
              if ( v22 )
              {
                *v22 = v11;
                ++v11->RefCount;
              }
            }
            ++v17;
            v5 += 8i64;
          }
          while ( v17 < (signed int)v16[1].RootIndex );
          LODWORD(v5) = 0;
        }
      }
      else
      {
        v23 = Scaleform::GFx::AS2::FnCall::Arg(v1, 0);
        v24 = Scaleform::GFx::AS2::Value::ToString(v23, &result, v1->Env, -1);
        Scaleform::ArrayBase<Scaleform::ArrayDataCC<Scaleform::GFx::ASString,Scaleform::AllocatorLH<Scaleform::GFx::ASString,323>,Scaleform::ArrayDefaultPolicy>>::PushBack(
          (Scaleform::ArrayBase<Scaleform::ArrayDataCC<Scaleform::GFx::ASString,Scaleform::AllocatorLH<Scaleform::GFx::ASString,323>,Scaleform::ArrayDefaultPolicy> > *)v7,
          v24);
        v25 = result.pNode;
        v21 = result.pNode->RefCount == 1;
        --v25->RefCount;
        if ( v21 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v25);
      }
    }
    v26 = v5;
    if ( *(_DWORD *)(v7 + 8) > 0 )
    {
      v27 = pheapAddr.Size;
      do
      {
        v5 = v27 + 1;
        if ( v27 + 1 >= v27 )
        {
          if ( v5 > pheapAddr.Policy.Capacity )
          {
            v28 = v5 + (v5 >> 2);
            goto LABEL_32;
          }
        }
        else if ( v5 < pheapAddr.Policy.Capacity >> 1 )
        {
          v28 = v27 + 1;
LABEL_32:
          Scaleform::ArrayDataBase<Scaleform::GFx::`anonymous namespace'::Range,AllocatorGH<Scaleform::GFx::`anonymous namespace'::Range,2>::AllocatorGH<Scaleform::GFx::`anonymous namespace'::Range,2>,AllocatorGH<Scaleform::GFx::`anonymous namespace'::Range,2>::ArrayDefaultPolicy>::Reserve(
            &pheapAddr,
            &pheapAddr,
            v28);
          goto LABEL_33;
        }
LABEL_33:
        v27 = v5;
        pheapAddr.Size = v5;
        v29 = &pheapAddr.Data[v5 - 1];
        LODWORD(v5) = 0;
        if ( v29 )
        {
          *v29 = 0;
          v27 = pheapAddr.Size;
        }
        ++v26;
      }
      while ( v26 < *(_DWORD *)(v7 + 8) );
    }
    if ( v1->NArgs >= 2 )
    {
      v30 = v1->FirstArgBottomIndex - 1;
      v31 = v1->Env;
      v32 = 0i64;
      if ( v30 <= 32 * ((unsigned int)v31->Stack.Pages.Data.Size - 1)
                + (unsigned int)((_QWORD)((char *)v31->Stack.pCurrent - (char *)v31->Stack.pPageStart) >> 5) )
        v32 = &v31->Stack.Pages.Data.Data[v30 >> 5]->Values[v30 & 0x1F];
      v33 = Scaleform::GFx::AS2::Value::ToObject(v32, v1->Env);
      v34 = v33;
      if ( v33 && (*(unsigned int (**)(void))&v33->vfptr->gap8[8])() == 7 )
      {
        v35 = v5;
        if ( (signed int)v34[1].RootIndex > 0 )
        {
          v36 = 0i64;
          v37 = 0i64;
          do
          {
            if ( v35 >= *(_DWORD *)(v7 + 8) )
              break;
            v38 = (Scaleform::GFx::AS2::Value *)(&v34[1].pRCC->vfptr)[v37];
            if ( v38 )
            {
              v39 = pheapAddr.Data;
              v39[v36] = Scaleform::GFx::AS2::Value::ToInt32(v38, v1->Env);
            }
            ++v35;
            ++v37;
            ++v36;
          }
          while ( v35 < (signed int)v34[1].RootIndex );
          v6 = (signed __int64)obj;
        }
      }
      else
      {
        v40 = v1->FirstArgBottomIndex - 1;
        v41 = v1->Env;
        v42 = 0i64;
        if ( v40 <= 32 * ((unsigned int)v41->Stack.Pages.Data.Size - 1)
                  + (unsigned int)((_QWORD)((char *)v41->Stack.pCurrent - (char *)v41->Stack.pPageStart) >> 5) )
          v42 = &v41->Stack.Pages.Data.Data[v40 >> 5]->Values[v40 & 0x1F];
        v43 = Scaleform::GFx::AS2::Value::ToInt32(v42, v1->Env);
        v84 = v43;
        v44 = v5;
        if ( *(_DWORD *)(v7 + 8) > 0 )
        {
          v45 = 0i64;
          do
          {
            pheapAddr.Data[v45] = v43;
            ++v44;
            ++v45;
          }
          while ( v44 < *(_DWORD *)(v7 + 8) );
        }
      }
      v11 = v85;
    }
    v46 = Scaleform::GFx::AS2::Environment::OperatorNew(
            v1->Env,
            v1->Env->StringContext.pContext->pGlobal.pObject,
            (Scaleform::GFx::ASString *)&v1->Env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[8].RefCount,
            0,
            -1);
    v47 = (Scaleform::GFx::AS2::ArrayObject *)v46;
    result.pNode = (Scaleform::GFx::ASStringNode *)v46;
    if ( !v46 )
    {
LABEL_96:
      if ( v47 )
      {
        v64 = v47->RefCount;
        if ( v64 & 0x3FFFFFF )
        {
          v47->RefCount = v64 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v47->vfptr);
        }
      }
      v21 = v11->RefCount-- == 1;
      if ( v21 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v11);
      goto LABEL_101;
    }
    v48 = *(_QWORD *)(v6 + 112);
    if ( (Scaleform::GFx::AS2::RefCountBaseGC<323> *)v48 >= v46[1].pPrev )
    {
      if ( v48 <= *(_QWORD *)&v46[1].RefCount )
        goto LABEL_63;
      v49 = v48 + (v48 >> 2);
      v50 = &v46[1].8;
      v51 = (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,2>,Scaleform::ArrayDefaultPolicy> *)&v46[1].8;
    }
    else
    {
      if ( v48 >= *(_QWORD *)&v46[1].RefCount >> 1 )
        goto LABEL_63;
      v49 = *(_QWORD *)(v6 + 112);
      v50 = &v46[1].8;
      v51 = (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,2>,Scaleform::ArrayDefaultPolicy> *)&v46[1].8;
    }
    Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      v51,
      v50,
      v49);
LABEL_63:
    v47->Elements.Data.Size = v48;
    v52 = 0i64;
    if ( v48 )
    {
      do
      {
        v47->Elements.Data.Data[v52] = *(Scaleform::GFx::AS2::Value **)(*(_QWORD *)(v6 + 104) + 8 * v52);
        ++v52;
      }
      while ( v52 < v48 );
    }
    Scaleform::GFx::AS2::ArraySortOnFunctor::ArraySortOnFunctor(
      &v76,
      (Scaleform::GFx::AS2::ObjectInterface *)&v47->vfptr,
      (Scaleform::ArrayCC<Scaleform::GFx::ASString,323,Scaleform::ArrayDefaultPolicy> *)v7,
      (Scaleform::Array<int,2,Scaleform::ArrayDefaultPolicy> *)&pheapAddr,
      v1->Env,
      *(Scaleform::Log **)(v6 + 96));
    v53 = v47->Elements.Data.Size;
    if ( v53 )
    {
      v77 = v47->Elements.Data.Data;
      v54 = v53;
      v78 = (unsigned int)v53;
      v71 = &v73;
      v73 = *(_OWORD *)&v76.This;
      v74 = *(_OWORD *)&v76.Env;
      v72 = &a;
      Scaleform::ArrayData<Scaleform::GFx::AS2::ArraySortFunctor,Scaleform::AllocatorGH<Scaleform::GFx::AS2::ArraySortFunctor,2>,Scaleform::ArrayDefaultPolicy>::ArrayData<Scaleform::GFx::AS2::ArraySortFunctor,Scaleform::AllocatorGH<Scaleform::GFx::AS2::ArraySortFunctor,2>,Scaleform::ArrayDefaultPolicy>(
        &a,
        &v76.FunctorArray.Data);
      v71 = &v73;
      v72 = (Scaleform::ArrayData<Scaleform::GFx::AS2::ArraySortFunctor,Scaleform::AllocatorGH<Scaleform::GFx::AS2::ArraySortFunctor,2>,Scaleform::ArrayDefaultPolicy> *)&v79;
      v79 = v73;
      v80 = v74;
      v70 = &v81;
      Scaleform::ArrayData<Scaleform::GFx::AS2::ArraySortFunctor,Scaleform::AllocatorGH<Scaleform::GFx::AS2::ArraySortFunctor,2>,Scaleform::ArrayDefaultPolicy>::ArrayData<Scaleform::GFx::AS2::ArraySortFunctor,Scaleform::AllocatorGH<Scaleform::GFx::AS2::ArraySortFunctor,2>,Scaleform::ArrayDefaultPolicy>(
        &v81,
        &a);
      Scaleform::Alg::QuickSortSlicedSafe<Scaleform::Alg::ArrayAdaptor<Scaleform::GFx::AS2::Value *>,Scaleform::GFx::AS2::ArraySortOnFunctor>(
        (Scaleform::Alg::ArrayAdaptor<Scaleform::GFx::AS2::Value *> *)&v77,
        0i64,
        v54,
        (Scaleform::GFx::AS2::ArraySortOnFunctor *)&v79);
      v70 = &a;
      Scaleform::ConstructorMov<Scaleform::GFx::AS2::ArraySortFunctor>::DestructArray(a.Data, a.Size);
      if ( a.Data )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
    }
    v55 = v84;
    if ( v84 & 4 )
    {
      v56 = 1;
      if ( SLODWORD(v47->Elements.Data.Size) > 1 )
      {
        v57 = 1i64;
        while ( Scaleform::GFx::AS2::ArraySortOnFunctor::Compare(
                  &v76,
                  v47->Elements.Data.Data[v57 - 1],
                  v47->Elements.Data.Data[v57]) )
        {
          ++v56;
          ++v57;
          if ( v56 >= SLODWORD(v47->Elements.Data.Size) )
          {
            v55 = v84;
            goto LABEL_77;
          }
        }
        v58 = v1->Result;
        if ( v58->T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(v1->Result);
        v58->T.Type = 4;
        v58->NV.Int32Value = 0;
        goto LABEL_94;
      }
    }
LABEL_77:
    if ( v55 & 8 )
    {
      Scaleform::GFx::AS2::ArrayObject::MakeDeepCopy(v47, v1->Env->StringContext.pContext->pHeap);
      v59 = (Scaleform::GFx::AS2::Object *)&v47->vfptr;
LABEL_93:
      Scaleform::GFx::AS2::Value::SetAsObject(v1->Result, v59);
LABEL_94:
      Scaleform::ConstructorMov<Scaleform::GFx::AS2::ArraySortFunctor>::DestructArray(
        v76.FunctorArray.Data.Data,
        v76.FunctorArray.Data.Size);
      if ( v76.FunctorArray.Data.Data )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      goto LABEL_96;
    }
    v60 = v47->Elements.Data.Size;
    if ( (Scaleform::GFx::AS2::RefCountBaseGC<323> *)v60 >= obj[1].pPrev )
    {
      if ( v60 > *(_QWORD *)&obj[1].RefCount )
      {
        v61 = v60 + (v60 >> 2);
        goto LABEL_84;
      }
    }
    else if ( v60 < *(_QWORD *)&obj[1].RefCount >> 1 )
    {
      v61 = v47->Elements.Data.Size;
LABEL_84:
      Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,2>,Scaleform::ArrayDefaultPolicy> *)&obj[1].8,
        &obj[1].8,
        v61);
      goto LABEL_85;
    }
LABEL_85:
    obj[1].pPrev = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)v60;
    v62 = 0i64;
    v63 = obj[1].pPrev;
    if ( v63 )
    {
      do
      {
        (&obj[1].pRCC->vfptr)[v62] = (Scaleform::RefCountImplCoreVtbl *)v47->Elements.Data.Data[v62];
        ++v62;
      }
      while ( v62 < (unsigned __int64)v63 );
    }
    if ( v47->Elements.Data.Size && v47->Elements.Data.Policy.Capacity & 0xFFFFFFFFFFFFFFFEui64 )
    {
      if ( v47->Elements.Data.Data )
      {
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
        v47->Elements.Data.Data = 0i64;
      }
      v47->Elements.Data.Policy.Capacity = 0i64;
    }
    v47->Elements.Data.Size = 0i64;
    v59 = obj;
    goto LABEL_93;
  }
  v10 = v1->Result;
  Scaleform::GFx::AS2::Value::DropRefs(v1->Result);
  v10->T.Type = 0;
LABEL_101:
  if ( pheapAddr.Data )
    ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
  if ( v7 )
  {
    v65 = *(Scaleform::GFx::ASStringNode **)(v7 + 24);
    v21 = v65->RefCount-- == 1;
    if ( v21 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v65);
    v66 = *(_QWORD *)(v7 + 8);
    for ( i = *(_QWORD *)v7 + 8 * (v66 - 1); v66; --v66 )
    {
      v68 = *(Scaleform::GFx::ASStringNode **)i;
      v21 = *(_DWORD *)(*(_QWORD *)i + 24i64) == 1;
      --v68->RefCount;
      if ( v21 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v68);
      i -= 8i64;
    }
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, *(void **)v7);
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, (void *)v7);
  }
}

// File Line: 879
// RVA: 0x6A64B0
void __fastcall Scaleform::GFx::AS2::ArrayObject::ArraySplice(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rbx
  Scaleform::GFx::AS2::ObjectInterface *v2; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // r14
  signed __int64 v4; // r14
  Scaleform::GFx::AS2::Value *v5; // rbx
  unsigned int v6; // er10
  Scaleform::GFx::AS2::Environment *v7; // rdx
  Scaleform::GFx::AS2::Value *v8; // r9
  __int64 v9; // rsi
  __int64 v10; // r12
  int v11; // er12
  unsigned int v12; // er9
  Scaleform::GFx::AS2::Environment *v13; // rdx
  Scaleform::GFx::AS2::Value *v14; // r10
  int v15; // eax
  __int64 v16; // rcx
  Scaleform::GFx::AS2::ArrayObject *v17; // rbp
  __int64 v18; // r15
  signed __int64 v19; // rdi
  Scaleform::GFx::AS2::Value *v20; // rdx
  signed int v21; // er8
  signed int v22; // edi
  int v23; // esi
  unsigned int v24; // edx
  Scaleform::GFx::AS2::Environment *v25; // r9
  Scaleform::GFx::AS2::Value *v26; // r8
  unsigned int v27; // eax

  v1 = fn;
  v2 = fn->ThisPtr;
  if ( v2 && (*(unsigned int (**)(void))&v2->vfptr->gap8[8])() == 7 )
  {
    v3 = v1->ThisPtr;
    if ( v3 )
      v4 = (signed __int64)&v3[-2];
    else
      v4 = 0i64;
    if ( v1->NArgs )
    {
      *(_BYTE *)(v4 + 140) = 0;
      v6 = v1->FirstArgBottomIndex;
      v7 = v1->Env;
      v8 = 0i64;
      if ( v6 <= 32 * ((unsigned int)v7->Stack.Pages.Data.Size - 1)
               + (unsigned int)((_QWORD)((char *)v7->Stack.pCurrent - (char *)v7->Stack.pPageStart) >> 5) )
        v8 = &v7->Stack.Pages.Data.Data[v6 >> 5]->Values[v6 & 0x1F];
      LODWORD(v9) = Scaleform::GFx::AS2::Value::ToInt32(v8, v7);
      if ( (signed int)v9 < 0 )
      {
        LODWORD(v9) = *(_DWORD *)(v4 + 112) + v9;
        if ( (signed int)v9 < 0 )
          LODWORD(v9) = 0;
      }
      v10 = *(_QWORD *)(v4 + 112);
      if ( (signed int)v9 > (signed int)v10 )
        v9 = *(_QWORD *)(v4 + 112);
      v11 = v10 - v9;
      if ( v1->NArgs >= 2 )
      {
        v12 = v1->FirstArgBottomIndex - 1;
        v13 = v1->Env;
        v14 = 0i64;
        if ( v12 <= 32 * ((unsigned int)v13->Stack.Pages.Data.Size - 1)
                  + (unsigned int)((_QWORD)((char *)v13->Stack.pCurrent - (char *)v13->Stack.pPageStart) >> 5) )
          v14 = &v13->Stack.Pages.Data.Data[v12 >> 5]->Values[v12 & 0x1F];
        v15 = Scaleform::GFx::AS2::Value::ToInt32(v14, v13);
        if ( v15 < 0 )
          v15 = 0;
        v11 = v15;
        v16 = *(_QWORD *)(v4 + 112);
        if ( (signed int)v9 + v15 >= (signed int)v16 )
          v11 = v16 - v9;
      }
      v17 = (Scaleform::GFx::AS2::ArrayObject *)Scaleform::GFx::AS2::Environment::OperatorNew(
                                                  v1->Env,
                                                  v1->Env->StringContext.pContext->pGlobal.pObject,
                                                  (Scaleform::GFx::ASString *)&v1->Env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[8].RefCount,
                                                  0,
                                                  -1);
      if ( v17 )
      {
        v18 = v11;
        if ( v11 > 0 )
        {
          v19 = 8i64 * (signed int)v9;
          do
          {
            v20 = *(Scaleform::GFx::AS2::Value **)(v19 + *(_QWORD *)(v4 + 104));
            if ( v20 )
              Scaleform::GFx::AS2::ArrayObject::PushBack(v17, v20);
            else
              Scaleform::GFx::AS2::ArrayObject::PushBack(v17);
            v19 += 8i64;
            --v18;
          }
          while ( v18 );
        }
        Scaleform::GFx::AS2::Value::SetAsObject(v1->Result, (Scaleform::GFx::AS2::Object *)&v17->vfptr);
        if ( v11 )
          Scaleform::GFx::AS2::ArrayObject::RemoveElements((Scaleform::GFx::AS2::ArrayObject *)v4, v9, v11);
        v21 = v1->NArgs;
        if ( v21 >= 3 )
        {
          Scaleform::GFx::AS2::ArrayObject::InsertEmpty((Scaleform::GFx::AS2::ArrayObject *)v4, v9, v21 - 2);
          v22 = 2;
          if ( v1->NArgs > 2 )
          {
            v23 = v9 - 2;
            do
            {
              v24 = v1->FirstArgBottomIndex - v22;
              v25 = v1->Env;
              v26 = 0i64;
              if ( v24 <= 32 * ((unsigned int)v25->Stack.Pages.Data.Size - 1)
                        + (unsigned int)((_QWORD)((char *)v25->Stack.pCurrent - (char *)v25->Stack.pPageStart) >> 5) )
                v26 = &v25->Stack.Pages.Data.Data[v24 >> 5]->Values[v24 & 0x1F];
              Scaleform::GFx::AS2::ArrayObject::SetElement((Scaleform::GFx::AS2::ArrayObject *)v4, v23 + v22++, v26);
            }
            while ( v22 < v1->NArgs );
          }
        }
      }
      if ( v17 )
      {
        v27 = v17->RefCount;
        if ( v27 & 0x3FFFFFF )
        {
          v17->RefCount = v27 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v17->vfptr);
        }
      }
    }
    else
    {
      v5 = v1->Result;
      Scaleform::GFx::AS2::Value::DropRefs(v5);
      v5->T.Type = 0;
    }
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      v1->Env,
      "Error: Null or invalid 'this' is used for a method of %s class.\n",
      "Array");
  }
}

// File Line: 943
// RVA: 0x6A6770
void __fastcall Scaleform::GFx::AS2::ArrayObject::ArrayToString(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rdi
  Scaleform::GFx::AS2::ObjectInterface *v2; // rcx
  __int64 v3; // rbx
  Scaleform::GFx::ASMovieRootBase *v4; // rsi
  Scaleform::GFx::AS2::Value *v5; // rdi
  Scaleform::GFx::ASStringNode *v6; // rax
  char *v7; // r8
  Scaleform::GFx::ASString *v8; // rsi
  Scaleform::GFx::AS2::Value *v9; // rdi
  Scaleform::GFx::ASStringNode *v10; // rax
  Scaleform::GFx::ASStringNode *v11; // rcx
  bool v12; // zf
  Scaleform::StringBuffer pbuffer; // [rsp+28h] [rbp-40h]
  Scaleform::LogMessageId messageType; // [rsp+70h] [rbp+8h]
  __int64 v15; // [rsp+78h] [rbp+10h]

  v1 = fn;
  v2 = fn->ThisPtr;
  if ( v2 && (*(unsigned int (__cdecl **)(Scaleform::GFx::AS2::ObjectInterface *))&v2->vfptr->gap8[8])(v2) == 7 )
  {
    v3 = (__int64)v1->ThisPtr;
    if ( v3 )
      v3 -= 32i64;
    v15 = v3;
    if ( ++*(_DWORD *)(v3 + 136) < 255 )
    {
      Scaleform::StringBuffer::StringBuffer(&pbuffer, v1->Env->StringContext.pContext->pHeap);
      Scaleform::GFx::AS2::ArrayObject::JoinToString((Scaleform::GFx::AS2::ArrayObject *)v3, v1->Env, &pbuffer, ",");
      v7 = &customWorldMapCaption;
      if ( pbuffer.pData )
        v7 = pbuffer.pData;
      v8 = Scaleform::GFx::AS2::Environment::CreateString(
             v1->Env,
             (Scaleform::GFx::ASString *)&messageType,
             v7,
             pbuffer.Size);
      v9 = v1->Result;
      if ( v9->T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(v9);
      v9->T.Type = 5;
      v10 = v8->pNode;
      v9->NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)v8->pNode;
      ++v10->RefCount;
      v11 = *(Scaleform::GFx::ASStringNode **)&messageType.Id;
      v12 = *(_DWORD *)(*(_QWORD *)&messageType.Id + 24i64) == 1;
      --v11->RefCount;
      if ( v12 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v11);
      Scaleform::ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayDataBase<int,Scaleform::AllocatorGH<int,2>,Scaleform::ArrayDefaultPolicy> *)&pbuffer);
    }
    else
    {
      messageType.Id = 212992;
      Scaleform::Log::LogMessageById(
        *(Scaleform::GFx::LogState **)(v3 + 96),
        (Scaleform::LogMessageId)&messageType,
        "256 levels of recursion is reached\n");
      v4 = v1->Env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject;
      v5 = v1->Result;
      if ( v5->T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(v5);
      v5->T.Type = 5;
      v6 = *(Scaleform::GFx::ASStringNode **)&v4[7].AVMVersion;
      v5->V.pStringNode = v6;
      ++v6->RefCount;
    }
    --*(_DWORD *)(v3 + 136);
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      v1->Env,
      "Error: Null or invalid 'this' is used for a method of %s class.\n",
      "Array");
  }
}

// File Line: 963
// RVA: 0x6A68F0
void __fastcall Scaleform::GFx::AS2::ArrayObject::ArrayUnshift(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rdi
  Scaleform::GFx::AS2::ObjectInterface *v2; // rcx
  Scaleform::GFx::AS2::ArrayObject *v3; // rsi
  int v4; // er8
  int i; // ebx
  Scaleform::GFx::AS2::Environment *v6; // rdx
  Scaleform::GFx::AS2::Value *v7; // r8
  unsigned int v8; // er9
  Scaleform::GFx::AS2::Value *v9; // rbx
  unsigned __int64 v10; // rsi

  v1 = fn;
  v2 = fn->ThisPtr;
  if ( v2 && (*(unsigned int (**)(void))&v2->vfptr->gap8[8])() == 7 )
  {
    v3 = (Scaleform::GFx::AS2::ArrayObject *)v1->ThisPtr;
    if ( v3 )
      v3 = (Scaleform::GFx::AS2::ArrayObject *)((char *)v3 - 32);
    v3->LengthValueOverriden = 0;
    v4 = v1->NArgs;
    if ( v4 > 0 )
    {
      Scaleform::GFx::AS2::ArrayObject::InsertEmpty(v3, 0, v4);
      for ( i = 0; i < v1->NArgs; ++i )
      {
        v6 = v1->Env;
        v7 = 0i64;
        v8 = v1->FirstArgBottomIndex - i;
        if ( v8 <= 32 * (LODWORD(v6->Stack.Pages.Data.Size) - 1)
                 + (unsigned int)((_QWORD)((char *)v6->Stack.pCurrent - (char *)v6->Stack.pPageStart) >> 5) )
          v7 = &v6->Stack.Pages.Data.Data[(unsigned __int64)v8 >> 5]->Values[v8 & 0x1F];
        Scaleform::GFx::AS2::ArrayObject::SetElement(v3, i, v7);
      }
    }
    v9 = v1->Result;
    v10 = v3->Elements.Data.Size;
    if ( v9->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(v1->Result);
    v9->NV.Int32Value = v10;
    v9->T.Type = 4;
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      v1->Env,
      "Error: Null or invalid 'this' is used for a method of %s class.\n",
      "Array");
  }
}

// File Line: 990
// RVA: 0x6A69F0
void __fastcall Scaleform::GFx::AS2::ArrayObject::ArrayValueOf(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ArrayObject::ArrayToString(fn);
}

// File Line: 1060
// RVA: 0x7152C0
char __fastcall Scaleform::GFx::AS2::ArrayObject::SetMember(Scaleform::GFx::AS2::ArrayObject *this, Scaleform::GFx::AS2::Environment *penv, Scaleform::GFx::ASString *name, Scaleform::GFx::AS2::Value *val, Scaleform::GFx::AS2::PropFlags *flags)
{
  Scaleform::GFx::AS2::Value *v5; // r14
  Scaleform::GFx::ASString *v6; // rsi
  Scaleform::GFx::AS2::Environment *v7; // rbp
  Scaleform::GFx::AS2::ArrayObject *v8; // rbx
  Scaleform::GFx::ASMovieRootBase *v9; // rdi
  Scaleform::GFx::ASStringNode *v10; // r9
  bool v11; // zf
  int v12; // eax
  const char *v13; // rcx
  char v14; // al
  int v15; // eax
  __int64 v16; // rcx
  __int64 v17; // rdi
  __int64 v18; // rdi
  _BYTE *v19; // rax
  _BYTE *v20; // rcx

  v5 = val;
  v6 = name;
  v7 = penv;
  v8 = this;
  v9 = penv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject;
  if ( penv->StringContext.SWFVersion <= 6u )
  {
    if ( !name->pNode->pLower )
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(name->pNode);
    v10 = v6->pNode;
    v11 = *(Scaleform::GFx::ASStringNode **)(*(_QWORD *)&v9[38].AVMVersion + 16i64) == v6->pNode->pLower;
  }
  else
  {
    v10 = name->pNode;
    v11 = *(Scaleform::GFx::ASStringNode **)&v9[38].AVMVersion == name->pNode;
  }
  if ( v11 )
  {
    v12 = Scaleform::GFx::AS2::Value::ToInt32(v5, 0i64);
    if ( v12 < 0 )
      v12 = 0;
    Scaleform::GFx::AS2::ArrayObject::Resize((Scaleform::GFx::AS2::ArrayObject *)((char *)v8 - 32), v12);
    BYTE4(v8->Elements.Data.Data) = 1;
    return Scaleform::GFx::AS2::Object::SetMember((Scaleform::GFx::AS2::Object *)&v8->vfptr, v7, v6, v5, flags);
  }
  v13 = v10->pData;
  v14 = *v10->pData;
  if ( v14 )
  {
    while ( (unsigned __int8)(v14 - 48) <= 9u )
    {
      v14 = *++v13;
      if ( !*v13 )
        goto LABEL_15;
    }
    if ( *v13 )
      return Scaleform::GFx::AS2::Object::SetMember((Scaleform::GFx::AS2::Object *)&v8->vfptr, v7, v6, v5, flags);
  }
LABEL_15:
  v15 = atol(v10->pData);
  v17 = v15;
  if ( v15 < 0 )
    return Scaleform::GFx::AS2::Object::SetMember((Scaleform::GFx::AS2::Object *)&v8->vfptr, v7, v6, v5, flags);
  BYTE4(v8->Elements.Data.Data) = 0;
  if ( v15 >= SLODWORD(v8->pWatchpoints) )
    Scaleform::GFx::AS2::ArrayObject::Resize((Scaleform::GFx::AS2::ArrayObject *)((char *)v8 - 32), v15 + 1);
  v18 = 8 * v17;
  if ( !*(_QWORD *)(v18 + *(_QWORD *)&v8->ResolveHandler.Flags) )
  {
    v19 = (_BYTE *)((__int64 (__fastcall *)(__int64, signed __int64))v7->StringContext.pContext->pHeap->vfptr->Alloc)(
                     v16,
                     32i64);
    v20 = v19;
    if ( v19 )
      *v19 = 0;
    else
      v20 = 0i64;
    *(_QWORD *)(v18 + *(_QWORD *)&v8->ResolveHandler.Flags) = v20;
  }
  Scaleform::GFx::AS2::Value::operator=(
    *(Scaleform::GFx::AS2::Value **)(*(_QWORD *)&v8->ResolveHandler.Flags + v18),
    v5,
    v18);
  return 1;
}

// File Line: 1094
// RVA: 0x6F3740
bool __fastcall Scaleform::GFx::AS2::ArrayObject::GetMemberRaw(Scaleform::GFx::AS2::ArrayObject *this, Scaleform::GFx::AS2::ASStringContext *psc, Scaleform::GFx::ASString *name, Scaleform::GFx::AS2::Value *val)
{
  Scaleform::GFx::AS2::ArrayObject *v4; // rdi
  Scaleform::GFx::AS2::Value *v5; // rbx
  const char *v6; // rcx
  Scaleform::GFx::ASString *v7; // r14
  Scaleform::GFx::AS2::ASStringContext *v8; // r15
  char v9; // al
  const char *v10; // r10
  int v11; // eax
  Scaleform::GFx::AS2::Value *v12; // rdx
  bool result; // al
  Scaleform::GFx::ASMovieRootBase *v14; // rsi
  bool v15; // zf
  Scaleform::GFx::ASStringHash_GC<Scaleform::GFx::AS2::Object::Watchpoint> *v16; // rsi

  v4 = this;
  v5 = val;
  v6 = name->pNode->pData;
  v7 = name;
  v8 = psc;
  v9 = *v6;
  v10 = name->pNode->pData;
  if ( !*v6 )
    goto LABEL_6;
  while ( (unsigned __int8)(v9 - 48) <= 9u )
  {
    v9 = (v10++)[1];
    if ( !v9 )
      goto LABEL_6;
  }
  if ( !*v10 )
  {
LABEL_6:
    v11 = atol(v6);
    if ( v11 >= 0 )
    {
      if ( v11 < SLODWORD(v4->pWatchpoints)
        && (v12 = *(Scaleform::GFx::AS2::Value **)(*(_QWORD *)&v4->ResolveHandler.Flags + 8i64 * v11)) != 0i64 )
      {
        Scaleform::GFx::AS2::Value::operator=(v5, v12, (__int64)v4);
        result = 1;
      }
      else
      {
        Scaleform::GFx::AS2::Value::DropRefs(v5);
        v5->T.Type = 0;
        result = 1;
      }
      return result;
    }
  }
  v14 = v8->pContext->pMovieRoot->pASMovieRoot.pObject;
  if ( v8->SWFVersion <= 6u )
  {
    if ( !v7->pNode->pLower )
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(v7->pNode);
    v15 = *(Scaleform::GFx::ASStringNode **)(*(_QWORD *)&v14[38].AVMVersion + 16i64) == v7->pNode->pLower;
  }
  else
  {
    v15 = *(Scaleform::GFx::ASStringNode **)&v14[38].AVMVersion == v7->pNode;
  }
  if ( !v15 || BYTE4(v4->Elements.Data.Data) && !v4->pWatchpoints )
    return Scaleform::GFx::AS2::Object::GetMemberRaw((Scaleform::GFx::AS2::Object *)&v4->vfptr, v8, v7, v5);
  v16 = v4->pWatchpoints;
  if ( v5->T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(v5);
  v5->T.Type = 4;
  v5->NV.Int32Value = (signed int)v16;
  result = 1;
  BYTE4(v4->Elements.Data.Data) = 0;
  return result;
}

// File Line: 1126
// RVA: 0x6E1EC0
bool __fastcall Scaleform::GFx::AS2::ArrayObject::DeleteMember(Scaleform::GFx::AS2::ArrayObject *this, Scaleform::GFx::AS2::ASStringContext *psc, Scaleform::GFx::ASString *name)
{
  Scaleform::GFx::ASString *v3; // rbx
  Scaleform::GFx::AS2::ASStringContext *v4; // rsi
  Scaleform::GFx::AS2::ArrayObject *v5; // rdi
  const char *v6; // rcx
  char v7; // al
  int v8; // eax
  Scaleform::GFx::AS2::Value val; // [rsp+28h] [rbp-30h]

  v3 = name;
  v4 = psc;
  v5 = this;
  if ( !name->pNode->Size || !isdigit(*name->pNode->pData) )
    return Scaleform::GFx::AS2::Object::DeleteMember((Scaleform::GFx::AS2::Object *)&v5->vfptr, v4, v3);
  v6 = v3->pNode->pData;
  v7 = *v6;
  if ( *v6 )
  {
    while ( (unsigned __int8)(v7 - 48) <= 9u )
    {
      v7 = *++v6;
      if ( !*v6 )
        goto LABEL_8;
    }
    if ( *v6 )
      return 0;
  }
LABEL_8:
  v8 = atol(v3->pNode->pData);
  if ( v8 < 0 )
    return 0;
  val.T.Type = 0;
  Scaleform::GFx::AS2::ArrayObject::SetElement((Scaleform::GFx::AS2::ArrayObject *)((char *)v5 - 32), v8, &val);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  return 1;
}

// File Line: 1144
// RVA: 0x723E50
void __fastcall Scaleform::GFx::AS2::ArrayObject::VisitMembers(Scaleform::GFx::AS2::ArrayObject *this, Scaleform::GFx::AS2::ASStringContext *psc, Scaleform::GFx::AS2::ObjectInterface::MemberVisitor *pvisitor, unsigned int visitFlags, Scaleform::GFx::AS2::ObjectInterface *instance)
{
  Scaleform::GFx::AS2::ObjectInterface::MemberVisitor *v5; // rsi
  Scaleform::GFx::AS2::ASStringContext *v6; // r15
  Scaleform::GFx::AS2::ArrayObject *v7; // rdi
  unsigned __int64 v8; // r14
  unsigned __int64 v9; // rbp
  unsigned __int64 v10; // rbx
  Scaleform::GFx::AS2::Value *v11; // r8
  Scaleform::GFx::ASString *v12; // rax
  Scaleform::GFx::ASStringNode *v13; // rcx
  bool v14; // zf
  Scaleform::StringDataPtr result; // [rsp+38h] [rbp-90h]
  Scaleform::LongFormatter v16; // [rsp+50h] [rbp-78h]
  Scaleform::GFx::ASString v17; // [rsp+D0h] [rbp+8h]

  v5 = pvisitor;
  v6 = psc;
  v7 = this;
  Scaleform::GFx::AS2::Object::VisitMembers(
    (Scaleform::GFx::AS2::Object *)&this->vfptr,
    psc,
    pvisitor,
    visitFlags,
    instance);
  v8 = (unsigned __int64)v7->pWatchpoints;
  v9 = v8;
  if ( v8 > 7 )
    v9 = 8i64;
  v10 = 0i64;
  if ( v9 )
  {
    do
    {
      v11 = *(Scaleform::GFx::AS2::Value **)(*(_QWORD *)&v7->ResolveHandler.Flags + 8 * v10);
      if ( v11 )
        v5->vfptr->Visit(
          v5,
          (Scaleform::GFx::ASString *)&v6->pContext->pMovieRoot->pASMovieRoot.pObject[7].AVMVersion
        + (signed int)v10
        + 143,
          v11,
          0);
      ++v10;
    }
    while ( v10 < v9 );
  }
  for ( ; v10 < v8; ++v10 )
  {
    if ( *(_QWORD *)(*(_QWORD *)&v7->ResolveHandler.Flags + 8 * v10) )
    {
      Scaleform::LongFormatter::LongFormatter(&v16, v10);
      Scaleform::LongFormatter::Convert(&v16);
      Scaleform::LongFormatter::GetResult(&v16, &result);
      v12 = Scaleform::GFx::AS2::ASStringContext::CreateString(v6, &v17, result.pStr, result.Size);
      v5->vfptr->Visit(v5, v12, *(Scaleform::GFx::AS2::Value **)(*(_QWORD *)&v7->ResolveHandler.Flags + 8 * v10), 0);
      v13 = v17.pNode;
      v14 = v17.pNode->RefCount == 1;
      --v13->RefCount;
      if ( v14 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v13);
      v16.vfptr = (Scaleform::String::InitStructVtbl *)&Scaleform::String::InitStruct::`vftable';
      Scaleform::Formatter::~Formatter((Scaleform::Formatter *)&v16.vfptr);
    }
  }
}

// File Line: 1177
// RVA: 0x6F68F0
char *__fastcall Scaleform::GFx::AS2::ArrayObject::GetTextValue(Scaleform::GFx::AS2::ArrayObject *this, Scaleform::GFx::AS2::Environment *pEnv)
{
  Scaleform::GFx::AS2::Environment *v2; // rsi
  Scaleform::GFx::AS2::ArrayObject *v3; // rdi
  unsigned __int64 *v4; // rbx
  char *v5; // rdi
  Scaleform::StringBuffer pbuffer; // [rsp+28h] [rbp-40h]
  int v8; // [rsp+70h] [rbp+8h]
  unsigned __int64 *v9; // [rsp+80h] [rbp+18h]

  v2 = pEnv;
  v3 = this;
  v4 = &this[-1].Elements.Data.Size;
  v9 = &this[-1].Elements.Data.Size;
  ++*((_DWORD *)v4 + 34);
  if ( *((_DWORD *)&this[-1].Elements.Data.Size + 34) < 255 )
  {
    Scaleform::StringBuffer::StringBuffer(&pbuffer, pEnv->StringContext.pContext->pHeap);
    Scaleform::GFx::AS2::ArrayObject::JoinToString((Scaleform::GFx::AS2::ArrayObject *)v4, v2, &pbuffer, ",");
    Scaleform::String::operator=((Scaleform::String *)&v3->LogPtr, &pbuffer);
    v5 = (char *)(((_QWORD)v3->LogPtr & 0xFFFFFFFFFFFFFFFCui64) + 12);
    Scaleform::ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayDataBase<int,Scaleform::AllocatorGH<int,2>,Scaleform::ArrayDefaultPolicy> *)&pbuffer);
  }
  else
  {
    v8 = 212992;
    Scaleform::Log::LogMessageById(
      (Scaleform::GFx::LogState *)v4[12],
      (Scaleform::LogMessageId)&v8,
      "256 levels of recursion is reached\n");
    v5 = &customWorldMapCaption;
  }
  --*((_DWORD *)v4 + 34);
  return v5;
}

// File Line: 1194
// RVA: 0x6FCFC0
void __fastcall Scaleform::GFx::AS2::ArrayObject::InitArray(Scaleform::GFx::AS2::ArrayObject *this, Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v2; // rsi
  char v3; // di
  int v4; // ebx
  Scaleform::GFx::AS2::ObjectInterface *v5; // r14
  Scaleform::GFx::ASString *v6; // r11
  unsigned int v7; // er8
  Scaleform::GFx::AS2::Environment *v8; // r10
  signed __int64 v9; // r9
  Scaleform::GFx::ASStringNode *v10; // rcx
  bool v11; // zf
  Scaleform::GFx::AS2::Value v12; // [rsp+38h] [rbp-40h]
  char v13; // [rsp+88h] [rbp+10h]
  Scaleform::GFx::ASString result; // [rsp+90h] [rbp+18h]

  v2 = fn;
  v3 = 0;
  v12.T.Type = 0;
  v4 = 0;
  if ( fn->NArgs > 0 )
  {
    v5 = (Scaleform::GFx::AS2::ObjectInterface *)&this->vfptr;
    do
    {
      if ( (unsigned __int8)v3 >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v12);
      v3 = 4;
      v12.T.Type = 4;
      v12.NV.Int32Value = v4;
      v6 = Scaleform::GFx::AS2::Value::ToString(&v12, &result, v2->Env, -1);
      v13 = 0;
      v7 = v2->FirstArgBottomIndex - v4;
      v8 = v2->Env;
      v9 = 0i64;
      if ( v7 <= 32 * ((unsigned int)v8->Stack.Pages.Data.Size - 1)
               + (unsigned int)((_QWORD)((char *)v8->Stack.pCurrent - (char *)v8->Stack.pPageStart) >> 5) )
        v9 = (signed __int64)&v8->Stack.Pages.Data.Data[v7 >> 5]->Values[v7 & 0x1F];
      v5->vfptr->SetMember(v5, v8, v6, (Scaleform::GFx::AS2::Value *)v9, (Scaleform::GFx::AS2::PropFlags *)&v13);
      v10 = result.pNode;
      v11 = result.pNode->RefCount == 1;
      --v10->RefCount;
      if ( v11 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v10);
      ++v4;
    }
    while ( v4 < v2->NArgs );
  }
  if ( (unsigned __int8)v3 >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v12);
}

// File Line: 1205
// RVA: 0x6FB350
bool __fastcall Scaleform::GFx::AS2::ArrayObject::HasMember(Scaleform::GFx::AS2::ArrayObject *this, Scaleform::GFx::AS2::ASStringContext *psc, Scaleform::GFx::ASString *name, bool inclPrototypes)
{
  Scaleform::GFx::AS2::ArrayObject *v4; // rbx
  bool v5; // si
  const char *v6; // rcx
  Scaleform::GFx::ASString *v7; // rdi
  Scaleform::GFx::AS2::ASStringContext *v8; // rbp
  char v9; // al
  const char *v10; // r10
  int v11; // eax
  char *v12; // rdx
  char v13; // al
  bool result; // al

  v4 = this;
  v5 = inclPrototypes;
  v6 = name->pNode->pData;
  v7 = name;
  v8 = psc;
  v9 = *v6;
  v10 = name->pNode->pData;
  if ( *v6 )
  {
    while ( (unsigned __int8)(v9 - 48) <= 9u )
    {
      v9 = (v10++)[1];
      if ( !v9 )
        goto LABEL_6;
    }
    if ( *v10 )
      return Scaleform::GFx::AS2::Object::HasMember((Scaleform::GFx::AS2::Object *)&v4->vfptr, v8, v7, v5);
  }
LABEL_6:
  v11 = atol(v6);
  if ( v11 < 0 )
    return Scaleform::GFx::AS2::Object::HasMember((Scaleform::GFx::AS2::Object *)&v4->vfptr, v8, v7, v5);
  result = 0;
  if ( v11 < SLODWORD(v4->pWatchpoints) )
  {
    v12 = *(char **)(*(_QWORD *)&v4->ResolveHandler.Flags + 8i64 * v11);
    if ( v12 )
    {
      v13 = *v12;
      if ( *v12 )
      {
        if ( v13 != 10 && v13 != 1 )
          result = 1;
      }
    }
  }
  return result;
}

// File Line: 1226
// RVA: 0x6C6EC0
void __fastcall Scaleform::GFx::AS2::ArrayCtorFunction::ArrayCtorFunction(Scaleform::GFx::AS2::ArrayCtorFunction *this, Scaleform::GFx::AS2::ASStringContext *psc)
{
  Scaleform::GFx::AS2::ASStringContext *v2; // rsi
  Scaleform::GFx::AS2::ArrayCtorFunction *v3; // rdi
  __int64 v4; // rbx
  __int64 v5; // rax
  Scaleform::GFx::AS2::NameNumber *v6; // rdx
  int v7; // ecx
  Scaleform::GFx::ASString *v8; // rax
  Scaleform::GFx::ASStringNode *v9; // rcx
  bool v10; // zf
  Scaleform::GFx::AS2::Value v11; // [rsp+38h] [rbp-50h]
  char v12; // [rsp+A0h] [rbp+18h]
  Scaleform::GFx::ASString result; // [rsp+A8h] [rbp+20h]

  v2 = psc;
  v3 = this;
  Scaleform::GFx::AS2::CFunctionObject::CFunctionObject(
    (Scaleform::GFx::AS2::CFunctionObject *)&this->vfptr,
    psc,
    Scaleform::GFx::AS2::ArrayCtorFunction::GlobalCtor);
  v3->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::ArrayCtorFunction::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
  v3->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::ArrayCtorFunction::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  v4 = 0i64;
  if ( GASArrayConstTable[0].Name )
  {
    v5 = 0i64;
    v6 = GASArrayConstTable;
    do
    {
      v12 = 3;
      v7 = GASArrayConstTable[v5].Number;
      v11.T.Type = 4;
      v11.NV.Int32Value = v7;
      v8 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v2, &result, v6->Name);
      v3->vfptr->SetMemberRaw(
        (Scaleform::GFx::AS2::ObjectInterface *)&v3->vfptr,
        v2,
        v8,
        &v11,
        (Scaleform::GFx::AS2::PropFlags *)&v12);
      v9 = result.pNode;
      v10 = result.pNode->RefCount == 1;
      --v9->RefCount;
      if ( v10 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v9);
      if ( v11.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v11);
      v5 = ++v4;
      v6 = &GASArrayConstTable[v4];
    }
    while ( v6->Name );
  }
}

// File Line: 1235
// RVA: 0x6F8AE0
void __fastcall Scaleform::GFx::AS2::ArrayCtorFunction::GlobalCtor(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rdi
  Scaleform::GFx::AS2::Value *v2; // rsi
  Scaleform::GFx::AS2::ObjectInterface *v3; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v4; // rbx
  Scaleform::GFx::AS2::ArrayObject *v5; // rbx
  Scaleform::GFx::AS2::ArrayObject *v6; // rax
  Scaleform::GFx::AS2::ArrayObject *v7; // rax
  int v8; // eax
  unsigned int v9; // er10
  Scaleform::GFx::AS2::Environment *v10; // r9
  Scaleform::GFx::AS2::Value *v11; // r8
  int v12; // eax
  unsigned int v13; // eax
  Scaleform::GFx::AS2::Value v14; // [rsp+38h] [rbp-40h]
  Scaleform::MemoryHeap *v15; // [rsp+80h] [rbp+8h]
  Scaleform::GFx::AS2::ArrayObject *v16; // [rsp+88h] [rbp+10h]
  Scaleform::GFx::AS2::ArrayObject *v17; // [rsp+90h] [rbp+18h]

  v1 = fn;
  v2 = 0i64;
  v16 = 0i64;
  v3 = fn->ThisPtr;
  if ( !v3
    || (*(unsigned int (**)(void))&v3->vfptr->gap8[8])() != 7
    || ((unsigned __int8 (*)(void))v1->ThisPtr->vfptr->IsBuiltinPrototype)() )
  {
    v15 = v1->Env->StringContext.pContext->pHeap;
    v6 = (Scaleform::GFx::AS2::ArrayObject *)v15->vfptr->Alloc((Scaleform::MemoryHeap *)v3, 144ui64, 0i64);
    v17 = v6;
    if ( v6 )
    {
      Scaleform::GFx::AS2::ArrayObject::ArrayObject(v6, v1->Env);
      v5 = v7;
    }
    else
    {
      v5 = 0i64;
    }
  }
  else
  {
    v4 = v1->ThisPtr;
    if ( v4 )
    {
      v5 = (Scaleform::GFx::AS2::ArrayObject *)&v4[-2];
      if ( v5 )
        v5->RefCount = (v5->RefCount + 1) & 0x8FFFFFFF;
    }
    else
    {
      v5 = 0i64;
    }
  }
  v16 = v5;
  LOBYTE(v15) = 1;
  v14.T.Type = 4;
  v14.NV.Int32Value = 0;
  v5->vfptr->SetMember(
    (Scaleform::GFx::AS2::ObjectInterface *)&v5->vfptr,
    v1->Env,
    (Scaleform::GFx::ASString *)&v1->Env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[38].AVMVersion,
    &v14,
    (Scaleform::GFx::AS2::PropFlags *)&v15);
  if ( v14.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v14);
  v8 = v1->NArgs;
  if ( v8 )
  {
    if ( v8 != 1 )
      goto LABEL_26;
    v9 = v1->FirstArgBottomIndex;
    v10 = v1->Env;
    v11 = 0i64;
    if ( v9 <= 32 * ((unsigned int)v10->Stack.Pages.Data.Size - 1)
             + (unsigned int)((_QWORD)((char *)v10->Stack.pCurrent - (char *)v10->Stack.pPageStart) >> 5) )
      v11 = &v10->Stack.Pages.Data.Data[v9 >> 5]->Values[v9 & 0x1F];
    if ( (unsigned __int8)(v11->T.Type - 3) > 1u )
    {
LABEL_26:
      Scaleform::GFx::AS2::ArrayObject::InitArray(v5, v1);
    }
    else
    {
      if ( v9 <= 32 * ((unsigned int)v10->Stack.Pages.Data.Size - 1)
               + (unsigned int)((_QWORD)((char *)v10->Stack.pCurrent - (char *)v10->Stack.pPageStart) >> 5) )
        v2 = &v10->Stack.Pages.Data.Data[v9 >> 5]->Values[v9 & 0x1F];
      v12 = Scaleform::GFx::AS2::Value::ToInt32(v2, v1->Env);
      Scaleform::GFx::AS2::ArrayObject::Resize(v5, v12);
    }
  }
  Scaleform::GFx::AS2::Value::SetAsObject(v1->Result, (Scaleform::GFx::AS2::Object *)&v5->vfptr);
  v13 = v5->RefCount;
  if ( v13 & 0x3FFFFFF )
  {
    v5->RefCount = v13 - 1;
    Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v5->vfptr);
  }
}

// File Line: 1264
// RVA: 0x6E19D0
void __fastcall Scaleform::GFx::AS2::ArrayCtorFunction::DeclareArray(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rdi
  Scaleform::GFx::AS2::ArrayObject *v2; // rax
  Scaleform::GFx::AS2::ArrayObject *v3; // rax
  Scaleform::GFx::AS2::ArrayObject *v4; // rbx
  char v5; // al
  Scaleform::GFx::AS2::FunctionObject *v6; // rcx
  unsigned int v7; // edx
  Scaleform::GFx::AS2::LocalFrame *v8; // rcx
  unsigned int v9; // eax
  unsigned int v10; // eax
  Scaleform::GFx::AS2::FunctionRef result; // [rsp+38h] [rbp-40h]
  Scaleform::GFx::AS2::Value v12; // [rsp+50h] [rbp-28h]
  Scaleform::MemoryHeap *v13; // [rsp+80h] [rbp+8h]
  Scaleform::GFx::AS2::ArrayObject *v14; // [rsp+88h] [rbp+10h]

  v1 = fn;
  v13 = fn->Env->StringContext.pContext->pHeap;
  v2 = (Scaleform::GFx::AS2::ArrayObject *)v13->vfptr->Alloc((Scaleform::MemoryHeap *)fn, 144ui64, 0i64);
  v14 = v2;
  if ( v2 )
  {
    Scaleform::GFx::AS2::ArrayObject::ArrayObject(v2, v1->Env);
    v4 = v3;
  }
  else
  {
    v4 = 0i64;
  }
  v14 = v4;
  LOBYTE(v13) = 1;
  v12.T.Type = 4;
  v12.NV.Int32Value = 0;
  v4->vfptr->SetMember(
    (Scaleform::GFx::AS2::ObjectInterface *)&v4->vfptr,
    v1->Env,
    (Scaleform::GFx::ASString *)&v1->Env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[38].AVMVersion,
    &v12,
    (Scaleform::GFx::AS2::PropFlags *)&v13);
  if ( v12.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v12);
  Scaleform::GFx::AS2::Environment::GetConstructor(v1->Env, &result, ASBuiltin_Array);
  Scaleform::GFx::AS2::ObjectInterface::Set_constructor(
    (Scaleform::GFx::AS2::ObjectInterface *)&v4->vfptr,
    &v1->Env->StringContext,
    &result);
  if ( v1->NArgs )
    Scaleform::GFx::AS2::ArrayObject::InitArray(v4, v1);
  Scaleform::GFx::AS2::Value::SetAsObject(v1->Result, (Scaleform::GFx::AS2::Object *)&v4->vfptr);
  v5 = result.Flags;
  if ( !(result.Flags & 2) )
  {
    v6 = result.Function;
    if ( result.Function )
    {
      v7 = result.Function->RefCount;
      if ( v7 & 0x3FFFFFF )
      {
        result.Function->RefCount = v7 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v6->vfptr);
        v5 = result.Flags;
      }
    }
  }
  result.Function = 0i64;
  if ( !(v5 & 1) )
  {
    v8 = result.pLocalFrame;
    if ( result.pLocalFrame )
    {
      v9 = result.pLocalFrame->RefCount;
      if ( v9 & 0x3FFFFFF )
      {
        result.pLocalFrame->RefCount = v9 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v8->vfptr);
      }
    }
  }
  result.pLocalFrame = 0i64;
  v10 = v4->RefCount;
  if ( v10 & 0x3FFFFFF )
  {
    v4->RefCount = v10 - 1;
    Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v4->vfptr);
  }
}

// File Line: 1286
// RVA: 0x6E02B0
void __fastcall Scaleform::GFx::AS2::ArrayCtorFunction::CreateNewObject(Scaleform::GFx::AS2::ArrayCtorFunction *this, Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::Environment *v2; // rbx
  Scaleform::GFx::AS2::ArrayObject *v3; // rax

  v2 = penv;
  v3 = (Scaleform::GFx::AS2::ArrayObject *)penv->StringContext.pContext->pHeap->vfptr->Alloc(
                                             (Scaleform::MemoryHeap *)this,
                                             144ui64,
                                             0i64);
  if ( v3 )
    Scaleform::GFx::AS2::ArrayObject::ArrayObject(v3, v2);
}

// File Line: 1291
// RVA: 0x70C0C0
Scaleform::GFx::AS2::FunctionRef *__fastcall Scaleform::GFx::AS2::ArrayCtorFunction::Register(Scaleform::GFx::AS2::FunctionRef *result, Scaleform::GFx::AS2::GlobalContext *pgc)
{
  Scaleform::GFx::AS2::GlobalContext *v2; // r14
  Scaleform::GFx::AS2::FunctionRef *v3; // rsi
  Scaleform::GFx::AS2::ArrayCtorFunction *v4; // rax
  __int64 v5; // rcx
  Scaleform::GFx::AS2::FunctionObject *v6; // rax
  __int64 v7; // rdi
  Scaleform::GFx::AS2::Object *v8; // rbx
  Scaleform::GFx::AS2::Object *v9; // rcx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v10; // rcx
  unsigned int v11; // eax
  signed __int64 v12; // rbx
  Scaleform::GFx::AS2::Object *v13; // rbx
  Scaleform::GFx::ASStringNode *v14; // rax
  Scaleform::GFx::AS2::LocalFrame *v15; // rdx
  int v16; // eax
  Scaleform::GFx::AS2::ASStringContext psc; // [rsp+48h] [rbp-38h]
  Scaleform::GFx::AS2::Value v19; // [rsp+58h] [rbp-28h]
  Scaleform::Ptr<Scaleform::GFx::AS2::Object> objproto; // [rsp+C8h] [rbp+48h]
  __int64 flags; // [rsp+D0h] [rbp+50h]
  Scaleform::Ptr<Scaleform::GFx::AS2::Object> *v22; // [rsp+D8h] [rbp+58h]

  v2 = pgc;
  v3 = result;
  psc.pContext = pgc;
  psc.SWFVersion = 8;
  objproto.pObject = (Scaleform::GFx::AS2::Object *)pgc->pHeap;
  v4 = (Scaleform::GFx::AS2::ArrayCtorFunction *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::FunctionRef *, signed __int64, _QWORD))objproto.pObject->vfptr[3].Finalize_GC)(
                                                   result,
                                                   104i64,
                                                   0i64);
  flags = (__int64)v4;
  if ( v4 )
    Scaleform::GFx::AS2::ArrayCtorFunction::ArrayCtorFunction(v4, &psc);
  else
    v6 = 0i64;
  v3->Flags = 0;
  v3->Function = v6;
  v3->pLocalFrame = 0i64;
  v22 = (Scaleform::Ptr<Scaleform::GFx::AS2::Object> *)v2->pHeap;
  v7 = ((__int64 (__fastcall *)(__int64, signed __int64, _QWORD))v22->pObject->pWatchpoints)(v5, 208i64, 0i64);
  if ( v7 )
  {
    v8 = Scaleform::GFx::AS2::GlobalContext::GetPrototype(v2, ASBuiltin_Object);
    Scaleform::GFx::AS2::Object::Object((Scaleform::GFx::AS2::Object *)v7, &psc);
    *(_QWORD *)v7 = &Scaleform::GFx::AS2::ArrayObject::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
    *(_QWORD *)(v7 + 32) = &Scaleform::GFx::AS2::ArrayObject::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
    *(_QWORD *)(v7 + 96) = 0i64;
    v9 = (Scaleform::GFx::AS2::Object *)(v7 + 104);
    objproto.pObject = v9;
    flags = v7 + 104;
    v9->vfptr = 0i64;
    v9->pRCC = 0i64;
    v9->pPrev = 0i64;
    Scaleform::StringLH::StringLH((Scaleform::StringLH *)(v7 + 128));
    *(_DWORD *)(v7 + 136) = 0;
    *(_BYTE *)(v7 + 140) = 0;
    if ( !*(_QWORD *)(v7 + 40) )
    {
      LOBYTE(objproto.pObject) = 3;
      v19.T.Type = 10;
      (*(void (__fastcall **)(__int64, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::MovieImpl **, Scaleform::GFx::AS2::Value *, Scaleform::Ptr<Scaleform::GFx::AS2::Object> *))(*(_QWORD *)(v7 + 32) + 80i64))(
        v7 + 32,
        &psc,
        &psc.pContext->pMovieRoot->pASMovieRoot.pObject[23].pMovieImpl,
        &v19,
        &objproto);
      if ( v19.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v19);
    }
    if ( v8 )
      v8->RefCount = (v8->RefCount + 1) & 0x8FFFFFFF;
    v10 = *(Scaleform::GFx::AS2::RefCountBaseGC<323> **)(v7 + 40);
    if ( v10 )
    {
      v11 = v10->RefCount;
      if ( v11 & 0x3FFFFFF )
      {
        v10->RefCount = v11 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v10);
      }
    }
    *(_QWORD *)(v7 + 40) = v8;
    v12 = v7 + 144;
    flags = v12;
    *(_QWORD *)v12 = &Scaleform::GFx::AS2::GASPrototypeBase::`vftable';
    *(_BYTE *)(v12 + 24) = 0;
    *(_QWORD *)(v12 + 8) = 0i64;
    *(_QWORD *)(v12 + 16) = 0i64;
    *(_BYTE *)(v7 + 192) = 0;
    *(_QWORD *)(v7 + 176) = 0i64;
    *(_QWORD *)(v7 + 184) = 0i64;
    *(_QWORD *)(v7 + 200) = 0i64;
    *(_QWORD *)v7 = &Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::ArrayObject,Scaleform::GFx::AS2::Environment>::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
    *(_QWORD *)(v7 + 32) = &Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::ArrayObject,Scaleform::GFx::AS2::Environment>::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
    *(_QWORD *)v12 = &Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::ArrayObject,Scaleform::GFx::AS2::Environment>::`vftable';
    Scaleform::GFx::AS2::GASPrototypeBase::Init(
      (Scaleform::GFx::AS2::GASPrototypeBase *)(v7 + 144),
      (Scaleform::GFx::AS2::Object *)v7,
      &psc,
      v3);
    *(_QWORD *)v7 = &Scaleform::GFx::AS2::ArrayProto::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
    *(_QWORD *)(v7 + 32) = &Scaleform::GFx::AS2::ArrayProto::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
    *(_QWORD *)v12 = &Scaleform::GFx::AS2::ArrayProto::`vftable';
    LOBYTE(flags) = 1;
    Scaleform::GFx::AS2::GASPrototypeBase::InitFunctionMembers(
      (Scaleform::GFx::AS2::GASPrototypeBase *)(v7 + 144),
      (Scaleform::GFx::AS2::Object *)v7,
      &psc,
      GASArrayFunctionTable,
      (Scaleform::GFx::AS2::PropFlags *)&flags);
  }
  else
  {
    v7 = 0i64;
  }
  flags = v7;
  v22 = &objproto;
  if ( v7 )
    *(_DWORD *)(v7 + 24) = (*(_DWORD *)(v7 + 24) + 1) & 0x8FFFFFFF;
  objproto.pObject = (Scaleform::GFx::AS2::Object *)v7;
  Scaleform::GFx::AS2::GlobalContext::SetPrototype(
    v2,
    ASBuiltin_Array,
    (Scaleform::Ptr<Scaleform::GFx::AS2::Object>)&objproto);
  v13 = v2->pGlobal.pObject;
  v19.T.Type = 8;
  v19.V.FunctionValue.Flags = 0;
  v14 = (Scaleform::GFx::ASStringNode *)v3->Function;
  v19.V.pStringNode = v14;
  if ( v14 )
  {
    ++v14->RefCount;
    v14->RefCount &= 0x8FFFFFFF;
  }
  v19.V.FunctionValue.pLocalFrame = 0i64;
  v15 = v3->pLocalFrame;
  if ( v15 )
    Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(
      (Scaleform::GFx::AS2::FunctionRefBase *)&v19.NV.8,
      v15,
      v3->Flags & 1);
  LOBYTE(objproto.pObject) = 0;
  v13->vfptr->SetMemberRaw(
    (Scaleform::GFx::AS2::ObjectInterface *)&v13->vfptr,
    &psc,
    (Scaleform::GFx::ASString *)&v2->pMovieRoot->pASMovieRoot.pObject[8].RefCount,
    &v19,
    (Scaleform::GFx::AS2::PropFlags *)&objproto);
  if ( v19.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v19);
  if ( v7 )
  {
    v16 = *(_DWORD *)(v7 + 24);
    if ( v16 & 0x3FFFFFF )
    {
      *(_DWORD *)(v7 + 24) = v16 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v7);
    }
  }
  return v3;
}

