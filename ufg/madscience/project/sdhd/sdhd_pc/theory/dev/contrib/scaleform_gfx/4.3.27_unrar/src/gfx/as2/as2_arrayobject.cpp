// File Line: 34
// RVA: 0x6D24E0
void __fastcall Scaleform::GFx::AS2::RecursionGuard::~RecursionGuard(Scaleform::GFx::AS2::RecursionGuard *this)
{
  --this->ThisPtr->RecursionCount;
}

// File Line: 64
// RVA: 0x6DE330
__int64 __fastcall Scaleform::GFx::AS2::ArraySortFunctor::Compare(
        Scaleform::GFx::AS2::ArraySortFunctor *this,
        Scaleform::GFx::AS2::Value *a,
        Scaleform::GFx::AS2::Value *b)
{
  Scaleform::GFx::AS2::Value *v4; // r15
  Scaleform::GFx::AS2::Value *v5; // r14
  unsigned int v6; // edi
  Scaleform::GFx::AS2::Environment *Env; // rbx
  Scaleform::GFx::ASStringNode *pCurrent; // rcx
  Scaleform::GFx::AS2::Environment *v9; // rbx
  Scaleform::GFx::ASStringNode *v10; // rcx
  int v11; // edx
  int v12; // r14d
  Scaleform::GFx::AS2::Environment *v13; // rbx
  Scaleform::GFx::AS2::Value *v14; // rcx
  int v15; // ebx
  char v16; // al
  unsigned int RefCount; // edx
  unsigned int v18; // eax
  char v19; // al
  unsigned int v20; // edx
  unsigned int v21; // eax
  double v22; // xmm6_8
  double v23; // xmm7_8
  __int64 v24; // rbx
  bool v25; // r12
  const char *pData; // rcx
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v28; // zf
  bool v29; // bl
  const char *v30; // rcx
  Scaleform::GFx::ASStringNode *v31; // rcx
  int Flags; // eax
  bool v33; // di
  const char *v34; // rbx
  unsigned int Length; // eax
  const char *v36; // rdx
  const char *v37; // rcx
  signed __int64 v38; // rdx
  unsigned __int8 v39; // al
  Scaleform::GFx::ASStringNode *v40; // rcx
  Scaleform::GFx::ASStringNode *v41; // rcx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v43; // [rsp+8h] [rbp-71h]
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v44; // [rsp+8h] [rbp-71h]
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v45; // [rsp+10h] [rbp-69h]
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v46; // [rsp+10h] [rbp-69h]
  char v47; // [rsp+18h] [rbp-61h]
  char v48; // [rsp+18h] [rbp-61h]
  char v49; // [rsp+18h] [rbp-61h]
  char v50; // [rsp+18h] [rbp-61h]
  void **v51; // [rsp+28h] [rbp-51h] BYREF
  Scaleform::GFx::AS2::Value v52; // [rsp+30h] [rbp-49h] BYREF
  Scaleform::GFx::AS2::Value v53; // [rsp+50h] [rbp-29h] BYREF
  __int64 v54; // [rsp+70h] [rbp-9h]
  Scaleform::GFx::ASString result; // [rsp+E0h] [rbp+67h] BYREF
  char *tailptr[4]; // [rsp+E8h] [rbp+6Fh] BYREF

  v54 = -2i64;
  v53.T.Type = 0;
  v4 = &v53;
  if ( a )
    v4 = a;
  v5 = &v53;
  if ( b )
    v5 = b;
  v6 = 0;
  if ( this->Func.Function )
  {
    v52.T.Type = 0;
    Env = this->Env;
    if ( ++Env->Stack.pCurrent >= Env->Stack.pPageEnd )
      Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&Env->Stack);
    pCurrent = (Scaleform::GFx::ASStringNode *)Env->Stack.pCurrent;
    result.pNode = pCurrent;
    tailptr[0] = (char *)pCurrent;
    if ( pCurrent )
      Scaleform::GFx::AS2::Value::Value((Scaleform::GFx::AS2::Value *)pCurrent, v5);
    v9 = this->Env;
    if ( ++v9->Stack.pCurrent >= v9->Stack.pPageEnd )
      Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&v9->Stack);
    v10 = (Scaleform::GFx::ASStringNode *)v9->Stack.pCurrent;
    result.pNode = v10;
    tailptr[0] = (char *)v10;
    if ( v10 )
      Scaleform::GFx::AS2::Value::Value((Scaleform::GFx::AS2::Value *)v10, v4);
    v11 = this->Env->Stack.pCurrent - this->Env->Stack.pPageStart + 32 * this->Env->Stack.Pages.Data.Size - 32;
    *(_QWORD *)&v52.T.Type = &v52;
    v12 = 2;
    LODWORD(v51) = 2;
    HIDWORD(v51) = v11;
    ((void (__fastcall *)(Scaleform::GFx::AS2::FunctionObject *, void ***, Scaleform::GFx::AS2::LocalFrame *, _QWORD))this->Func.Function->vfptr[3].Finalize_GC)(
      this->Func.Function,
      &v51,
      this->Func.pLocalFrame,
      0i64);
    v13 = this->Env;
    do
    {
      v14 = v13->Stack.pCurrent;
      if ( v14->T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(v14);
      if ( --v13->Stack.pCurrent < v13->Stack.pPageStart )
        Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(&v13->Stack);
      --v12;
    }
    while ( v12 );
    if ( *(_QWORD *)&v52.T.Type )
    {
      v15 = Scaleform::GFx::AS2::Value::ToInt32(*(Scaleform::GFx::AS2::Value **)&v52.T.Type, this->Env);
      if ( (this->Flags & 2) != 0 )
        v15 = -v15;
      v51 = &Scaleform::GFx::AS2::FnCall::`vftable;
      v16 = v48;
      if ( (v48 & 2) == 0 )
      {
        if ( v44 )
        {
          RefCount = v44->RefCount;
          if ( (RefCount & 0x3FFFFFF) != 0 )
          {
            v44->RefCount = RefCount - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v44);
            v16 = v49;
          }
        }
      }
      if ( (v16 & 1) == 0 )
      {
        if ( v46 )
        {
          v18 = v46->RefCount;
          if ( (v18 & 0x3FFFFFF) != 0 )
          {
            v46->RefCount = v18 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v46);
          }
        }
      }
      v51 = &Scaleform::GFx::LogBase<Scaleform::GFx::AS2::FnCall>::`vftable;
      if ( v52.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v52);
LABEL_74:
      v6 = v15;
      goto LABEL_90;
    }
    v51 = &Scaleform::GFx::AS2::FnCall::`vftable;
    v19 = v47;
    if ( (v47 & 2) == 0 )
    {
      if ( v43 )
      {
        v20 = v43->RefCount;
        if ( (v20 & 0x3FFFFFF) != 0 )
        {
          v43->RefCount = v20 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v43);
          v19 = v50;
        }
      }
    }
    if ( (v19 & 1) == 0 )
    {
      if ( v45 )
      {
        v21 = v45->RefCount;
        if ( (v21 & 0x3FFFFFF) != 0 )
        {
          v45->RefCount = v21 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v45);
        }
      }
    }
    v51 = &Scaleform::GFx::LogBase<Scaleform::GFx::AS2::FnCall>::`vftable;
    if ( v52.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v52);
  }
  else
  {
    v22 = 0.0;
    v23 = 0.0;
    if ( (this->Flags & 0x10) != 0 )
    {
      v24 = 0x3FF680000000000i64;
      if ( (unsigned __int8)(v4->T.Type - 3) > 1u )
      {
        Scaleform::GFx::AS2::Value::ToString(v4, &result, this->Env, -1);
        pData = result.pNode->pData;
        v25 = 0;
        if ( result.pNode->pData )
        {
          if ( *pData <= 0x39u )
          {
            if ( _bittest64(&v24, *pData) )
            {
              v22 = Scaleform::SFstrtod(pData, tailptr);
              if ( !tailptr[0] || !*tailptr[0] )
                v25 = 1;
            }
          }
        }
        pNode = result.pNode;
        v28 = result.pNode->RefCount-- == 1;
        if ( v28 )
          Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      }
      else
      {
        v22 = Scaleform::GFx::AS2::Value::ToNumber(v4, this->Env);
        v25 = 1;
      }
      if ( (unsigned __int8)(v5->T.Type - 3) > 1u )
      {
        Scaleform::GFx::AS2::Value::ToString(v5, &result, this->Env, -1);
        v30 = result.pNode->pData;
        v29 = 0;
        if ( result.pNode->pData )
        {
          if ( *v30 <= 0x39u )
          {
            if ( _bittest64(&v24, *v30) )
            {
              v23 = Scaleform::SFstrtod(v30, tailptr);
              if ( !tailptr[0] || !*tailptr[0] )
                v29 = 1;
            }
          }
        }
        v31 = result.pNode;
        v28 = result.pNode->RefCount-- == 1;
        if ( v28 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v31);
      }
      else
      {
        v23 = Scaleform::GFx::AS2::Value::ToNumber(v5, this->Env);
        v29 = 1;
      }
      if ( v25 && v29 )
      {
        v15 = 0;
        if ( v23 > v22 )
          v15 = -1;
        if ( v22 > v23 )
          v15 = 1;
        if ( (this->Flags & 2) != 0 )
          v15 = -v15;
        goto LABEL_74;
      }
    }
    Scaleform::GFx::AS2::Value::ToString(v4, (Scaleform::GFx::ASString *)tailptr, this->Env, -1);
    Scaleform::GFx::AS2::Value::ToString(v5, &result, this->Env, -1);
    Flags = this->Flags;
    if ( (Flags & 0x400) != 0 )
    {
      v33 = (Flags & 1) == 0;
      v34 = result.pNode->pData;
      Length = Scaleform::GFx::ASConstString::GetLength(&result);
      v6 = Scaleform::GFx::ASConstString::LocaleCompare_CaseCheck(
             (Scaleform::GFx::ASConstString *)tailptr,
             v34,
             Length,
             v33);
    }
    else
    {
      v36 = result.pNode->pData;
      v37 = *(const char **)tailptr[0];
      if ( (Flags & 1) != 0 )
      {
        v6 = Scaleform::String::CompareNoCase(v37, v36);
      }
      else
      {
        v38 = v36 - v37;
        while ( 1 )
        {
          v39 = *v37;
          if ( *v37 != v37[v38] )
            break;
          ++v37;
          if ( !v39 )
            goto LABEL_84;
        }
        v6 = v39 < (unsigned int)v37[v38] ? -1 : 1;
      }
    }
LABEL_84:
    if ( (this->Flags & 2) != 0 )
      v6 = -v6;
    v40 = result.pNode;
    v28 = result.pNode->RefCount-- == 1;
    if ( v28 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v40);
    v41 = (Scaleform::GFx::ASStringNode *)tailptr[0];
    v28 = (*((_DWORD *)tailptr[0] + 6))-- == 1;
    if ( v28 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v41);
  }
LABEL_90:
  if ( v53.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v53);
  return v6;
}

// File Line: 187
// RVA: 0x6C71B0
void __fastcall Scaleform::GFx::AS2::ArraySortOnFunctor::ArraySortOnFunctor(
        Scaleform::GFx::AS2::ArraySortOnFunctor *this,
        Scaleform::GFx::AS2::ObjectInterface *pThis,
        Scaleform::ArrayCC<Scaleform::GFx::ASString,323,Scaleform::ArrayDefaultPolicy> *fieldArray,
        Scaleform::Array<int,2,Scaleform::ArrayDefaultPolicy> *flagsArray,
        Scaleform::GFx::AS2::Environment *env,
        Scaleform::Log *log)
{
  Scaleform::Array<Scaleform::GFx::AS2::ArraySortFunctor,2,Scaleform::ArrayDefaultPolicy> *p_FunctorArray; // r14
  unsigned int v10; // esi
  __int64 v11; // rbx
  int v12; // ecx
  __int64 v13; // rbx
  Scaleform::GFx::AS2::FunctionRefBase orig; // [rsp+50h] [rbp-58h] BYREF
  Scaleform::GFx::AS2::Environment *v15; // [rsp+68h] [rbp-40h]
  Scaleform::Log *v16; // [rsp+70h] [rbp-38h]

  this->This = pThis;
  this->FieldArray = fieldArray;
  this->Env = env;
  this->LogPtr = log;
  p_FunctorArray = &this->FunctorArray;
  this->FunctorArray.Data.Data = 0i64;
  this->FunctorArray.Data.Size = 0i64;
  this->FunctorArray.Data.Policy.Capacity = 0i64;
  Scaleform::ArrayData<Scaleform::GFx::AS2::ArraySortFunctor,Scaleform::AllocatorGH<Scaleform::GFx::AS2::ArraySortFunctor,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &this->FunctorArray.Data,
    flagsArray->Data.Size);
  v10 = 0;
  if ( this->FunctorArray.Data.Size )
  {
    v11 = 0i64;
    do
    {
      v12 = flagsArray->Data.Data[v11];
      memset(&orig, 0, 17);
      v15 = env;
      v16 = log;
      v13 = (__int64)&p_FunctorArray->Data.Data[v11];
      *(_QWORD *)v13 = pThis;
      *(_DWORD *)(v13 + 8) = v12;
      Scaleform::GFx::AS2::FunctionRefBase::Assign((Scaleform::GFx::AS2::FunctionRefBase *)(v13 + 16), &orig);
      *(_QWORD *)(v13 + 40) = env;
      *(_QWORD *)(v13 + 48) = log;
      orig.Function = 0i64;
      orig.pLocalFrame = 0i64;
      v11 = ++v10;
    }
    while ( v10 < this->FunctorArray.Data.Size );
  }
}

// File Line: 202
// RVA: 0x6DE7F0
__int64 __fastcall Scaleform::GFx::AS2::ArraySortOnFunctor::Compare(
        Scaleform::GFx::AS2::ArraySortOnFunctor *this,
        Scaleform::GFx::AS2::Value *a,
        Scaleform::GFx::AS2::Value *b)
{
  Scaleform::GFx::AS2::Value *v4; // r13
  Scaleform::GFx::AS2::Value *v5; // r12
  __int64 v6; // r15
  Scaleform::GFx::AS2::Environment *Env; // rdx
  Scaleform::GFx::CharacterHandle *pCharHandle; // rcx
  Scaleform::GFx::DisplayObject *v9; // rax
  Scaleform::GFx::DisplayObject *v10; // rcx
  char *v11; // rcx
  __int64 v12; // rax
  Scaleform::GFx::AS2::ObjectInterface *v13; // rdi
  Scaleform::GFx::AS2::Object *v14; // rax
  Scaleform::GFx::AS2::Environment *v15; // rdx
  Scaleform::GFx::CharacterHandle *v16; // rcx
  Scaleform::GFx::DisplayObject *v17; // rax
  Scaleform::GFx::DisplayObject *v18; // rcx
  char *v19; // rcx
  __int64 v20; // rax
  Scaleform::GFx::AS2::ObjectInterface *v21; // rbx
  Scaleform::GFx::AS2::Object *v22; // rax
  Scaleform::GFx::ASString *v23; // r14
  unsigned int v24; // ebx
  __int64 v26; // [rsp+20h] [rbp-98h]
  Scaleform::GFx::AS2::Value ba; // [rsp+28h] [rbp-90h] BYREF
  Scaleform::GFx::AS2::Value aa; // [rsp+48h] [rbp-70h] BYREF
  _BYTE v29[40]; // [rsp+68h] [rbp-50h] BYREF
  Scaleform::GFx::AS2::ASStringContext *p_StringContext; // [rsp+C0h] [rbp+8h]

  v26 = -2i64;
  v29[0] = 0;
  v4 = (Scaleform::GFx::AS2::Value *)v29;
  if ( a )
    v4 = a;
  v5 = (Scaleform::GFx::AS2::Value *)v29;
  if ( b )
    v5 = b;
  p_StringContext = &this->Env->StringContext;
  v6 = 0i64;
  if ( !this->FunctorArray.Data.Size )
    return 0i64;
  while ( 1 )
  {
    Env = this->Env;
    if ( v4->T.Type == 7 )
    {
      if ( Env )
      {
        pCharHandle = v4->V.pCharHandle;
        if ( pCharHandle )
        {
          v9 = Scaleform::GFx::CharacterHandle::ResolveCharacter(pCharHandle, Env->Target->pASRoot->pMovieImpl);
          if ( v9 )
          {
            v10 = 0i64;
            if ( SLOBYTE(v9->Scaleform::GFx::DisplayObjectBase::Flags) < 0 )
              v10 = v9;
            if ( v10 )
            {
              v11 = (char *)v10 + 4 * (unsigned __int8)v10->AvmObjOffset;
              v12 = (*(__int64 (__fastcall **)(char *, Scaleform::GFx::DisplayObject *))(*(_QWORD *)v11 + 8i64))(
                      v11,
                      v9);
              if ( v12 )
              {
                v13 = (Scaleform::GFx::AS2::ObjectInterface *)(v12 + 8);
                goto LABEL_18;
              }
            }
          }
        }
      }
    }
    else
    {
      v14 = Scaleform::GFx::AS2::Value::ToObject(v4, Env);
      if ( v14 )
      {
        v13 = &v14->Scaleform::GFx::AS2::ObjectInterface;
        goto LABEL_18;
      }
    }
    v13 = 0i64;
LABEL_18:
    v15 = this->Env;
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
      if ( SLOBYTE(v17->Scaleform::GFx::DisplayObjectBase::Flags) < 0 )
        v18 = v17;
      if ( !v18
        || (v19 = (char *)v18 + 4 * (unsigned __int8)v18->AvmObjOffset,
            (v20 = (*(__int64 (__fastcall **)(char *, Scaleform::GFx::DisplayObject *))(*(_QWORD *)v19 + 8i64))(
                     v19,
                     v17)) == 0) )
      {
LABEL_29:
        v21 = 0i64;
        goto LABEL_30;
      }
      v21 = (Scaleform::GFx::AS2::ObjectInterface *)(v20 + 8);
    }
    else
    {
      v22 = Scaleform::GFx::AS2::Value::ToObject(v5, v15);
      if ( !v22 )
        goto LABEL_29;
      v21 = &v22->Scaleform::GFx::AS2::ObjectInterface;
    }
LABEL_30:
    if ( v13 && v21 )
      break;
LABEL_39:
    v6 = (unsigned int)(v6 + 1);
    if ( (unsigned int)v6 >= this->FunctorArray.Data.Size )
      return 0i64;
  }
  aa.T.Type = 0;
  ba.T.Type = 0;
  v23 = &this->FieldArray->Data.Data[v6];
  if ( !((unsigned __int8 (__fastcall *)(Scaleform::GFx::AS2::ObjectInterface *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, __int64))v13->vfptr->GetMemberRaw)(
          v13,
          p_StringContext,
          v23,
          &aa,
          v26)
    || !v21->vfptr->GetMemberRaw(v21, p_StringContext, v23, &ba)
    || (v24 = Scaleform::GFx::AS2::ArraySortFunctor::Compare(&this->FunctorArray.Data.Data[(unsigned int)v6], &aa, &ba)) == 0 )
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
void __fastcall Scaleform::GFx::AS2::ArrayObject::ArrayObject(
        Scaleform::GFx::AS2::ArrayObject *this,
        Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::Object *Prototype; // rax

  Scaleform::GFx::AS2::Object::Object(this, penv);
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::ArrayObject::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::ArrayObject::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  this->LogPtr = (Scaleform::Log *const)((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *))penv->Target->vfptr[76].__vecDelDtor)(penv->Target);
  this->Elements.Data.Data = 0i64;
  this->Elements.Data.Size = 0i64;
  this->Elements.Data.Policy.Capacity = 0i64;
  Scaleform::StringLH::StringLH(&this->StringValue);
  this->RecursionCount = 0;
  this->LengthValueOverriden = 0;
  Prototype = Scaleform::GFx::AS2::GlobalContext::GetPrototype(penv->StringContext.pContext, ASBuiltin_Array);
  Scaleform::GFx::AS2::Object::Set__proto__(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    &penv->StringContext,
    Prototype);
}

// File Line: 247
// RVA: 0x6C6FC0
void __fastcall Scaleform::GFx::AS2::ArrayObject::ArrayObject(
        Scaleform::GFx::AS2::ArrayObject *this,
        Scaleform::GFx::AS2::ASStringContext *psc)
{
  Scaleform::GFx::AS2::Object *Prototype; // rax

  Scaleform::GFx::AS2::Object::Object(this, psc);
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::ArrayObject::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::ArrayObject::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  this->LogPtr = 0i64;
  this->Elements.Data.Data = 0i64;
  this->Elements.Data.Size = 0i64;
  this->Elements.Data.Policy.Capacity = 0i64;
  Scaleform::StringLH::StringLH(&this->StringValue);
  this->RecursionCount = 0;
  this->LengthValueOverriden = 0;
  Prototype = Scaleform::GFx::AS2::GlobalContext::GetPrototype(psc->pContext, ASBuiltin_Array);
  Scaleform::GFx::AS2::Object::Set__proto__(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    Prototype);
}

// File Line: 259
// RVA: 0x6D0CA0
void __fastcall Scaleform::GFx::AS2::ArrayObject::~ArrayObject(Scaleform::GFx::AS2::ArrayObject *this)
{
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::ArrayObject::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::ArrayObject::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  Scaleform::GFx::AS2::ArrayObject::Resize(this, 0);
  if ( !_InterlockedDecrement((volatile signed __int32 *)((this->StringValue.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, this->Elements.Data.Data);
  Scaleform::GFx::AS2::Object::~Object(this);
}

// File Line: 265
// RVA: 0x6E8980
void __fastcall Scaleform::GFx::AS2::ArrayObject::ExecuteForEachChild_GC(
        Scaleform::GFx::AS2::ArrayObject *this,
        Scaleform::GFx::AS2::RefCountCollector<323> *prcc,
        Scaleform::GFx::AS2::RefCountBaseGC<323>::OperationGC operation)
{
  int v3; // r8d

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
void __fastcall Scaleform::GFx::AS2::ArrayObject::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseFunctor>(
        Scaleform::GFx::AS2::ArrayObject *this,
        Scaleform::GFx::AS2::RefCountCollector<323> *prcc)
{
  unsigned __int64 Size; // rdi
  unsigned __int64 i; // rbx
  Scaleform::GFx::AS2::Value *v6; // rcx

  Scaleform::GFx::AS2::Object::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseFunctor>(this, prcc);
  Size = this->Elements.Data.Size;
  for ( i = 0i64; i < Size; ++i )
  {
    v6 = this->Elements.Data.Data[i];
    if ( v6 )
      Scaleform::GFx::AS2::Value::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseFunctor>(v6, prcc);
  }
}

// File Line: 284
// RVA: 0x6E98A0
void __fastcall Scaleform::GFx::AS2::ArrayObject::Finalize_GC(Scaleform::GFx::AS2::ArrayObject *this)
{
  unsigned __int64 v2; // rdi
  unsigned __int64 Size; // rsi
  int v4; // ebp
  Scaleform::GFx::AS2::Value *v5; // rcx
  unsigned int Type; // eax
  Scaleform::GFx::ASStringHash_GC<Scaleform::GFx::AS2::Object::Watchpoint> *pWatchpoints; // rcx

  v2 = 0i64;
  Size = this->Elements.Data.Size;
  if ( Size )
  {
    v4 = 863;
    do
    {
      v5 = this->Elements.Data.Data[v2];
      if ( v5 )
      {
        Type = (unsigned __int8)v5->T.Type;
        if ( (unsigned __int8)Type > 9u || !_bittest(&v4, Type) )
          Scaleform::GFx::AS2::Value::DropRefs(v5);
      }
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, this->Elements.Data.Data[v2++]);
    }
    while ( v2 < Size );
  }
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, this->Elements.Data.Data);
  if ( !_InterlockedDecrement((volatile signed __int32 *)((this->StringValue.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::~HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>((Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)&this->Members);
  pWatchpoints = this->pWatchpoints;
  if ( pWatchpoints )
  {
    Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::~HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>(&pWatchpoints->mHash);
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, this->pWatchpoints);
  }
}

// File Line: 310
// RVA: 0x711420
void __fastcall Scaleform::GFx::AS2::ArrayObject::Resize(Scaleform::GFx::AS2::ArrayObject *this, int size)
{
  unsigned __int64 v2; // rbx
  unsigned __int64 v4; // rbp
  unsigned __int64 i; // rsi
  Scaleform::GFx::AS2::Value **Data; // rax
  Scaleform::GFx::AS2::Value *v7; // rdi
  unsigned __int64 v8; // r8

  v2 = this->Elements.Data.Size;
  if ( size < 0 )
    size = 0;
  v4 = size;
  for ( i = size; i < v2; ++i )
  {
    Data = this->Elements.Data.Data;
    v7 = Data[i];
    if ( v7 )
    {
      if ( v7->T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(Data[i]);
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v7);
    }
  }
  if ( v4 >= this->Elements.Data.Size )
  {
    if ( v4 <= this->Elements.Data.Policy.Capacity )
      goto LABEL_15;
    v8 = v4 + (v4 >> 2);
  }
  else
  {
    if ( v4 >= this->Elements.Data.Policy.Capacity >> 1 )
      goto LABEL_15;
    v8 = v4;
  }
  Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
    (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,2>,Scaleform::ArrayDefaultPolicy> *)&this->Elements,
    &this->Elements,
    v8);
LABEL_15:
  for ( this->Elements.Data.Size = v4; v2 < v4; this->Elements.Data.Data[v2 - 1] = 0i64 )
    ++v2;
}

// File Line: 327
// RVA: 0x71FB40
void __fastcall Scaleform::GFx::AS2::ArrayObject::ShallowCopyFrom(
        Scaleform::GFx::AS2::ArrayObject *this,
        Scaleform::GFx::AS2::ArrayObject *ao)
{
  unsigned __int64 Size; // r8
  unsigned __int64 i; // rax

  Scaleform::ArrayData<Scaleform::GFx::AS2::PagedStack<Scaleform::Ptr<Scaleform::GFx::AS2::FunctionObject>,32>::Page *,Scaleform::AllocatorLH<Scaleform::GFx::AS2::PagedStack<Scaleform::Ptr<Scaleform::GFx::AS2::FunctionObject>,32>::Page *,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &this->Elements.Data,
    ao->Elements.Data.Size);
  Size = this->Elements.Data.Size;
  for ( i = 0i64; i < Size; this->Elements.Data.Data[i - 1] = ao->Elements.Data.Data[i - 1] )
    ++i;
}

// File Line: 336
// RVA: 0x702C10
void __fastcall Scaleform::GFx::AS2::ArrayObject::MakeDeepCopy(
        Scaleform::GFx::AS2::ArrayObject *this,
        Scaleform::MemoryHeap *pheap)
{
  unsigned __int64 v4; // rbx
  unsigned __int64 Size; // rsi
  Scaleform::GFx::AS2::Value *v6; // rax
  Scaleform::GFx::AS2::Value *v7; // rax
  Scaleform::GFx::AS2::Value *v8; // rcx

  v4 = 0i64;
  Size = this->Elements.Data.Size;
  if ( Size )
  {
    do
    {
      if ( this->Elements.Data.Data[v4] )
      {
        v6 = (Scaleform::GFx::AS2::Value *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))pheap->vfptr->Alloc)(
                                             pheap,
                                             32i64);
        if ( v6 )
        {
          Scaleform::GFx::AS2::Value::Value(v6, this->Elements.Data.Data[v4]);
          v8 = v7;
        }
        else
        {
          v8 = 0i64;
        }
        this->Elements.Data.Data[v4] = v8;
      }
      ++v4;
    }
    while ( v4 < Size );
  }
}

// File Line: 348
// RVA: 0x702CA0
void __fastcall Scaleform::GFx::AS2::ArrayObject::MakeDeepCopyFrom(
        Scaleform::GFx::AS2::ArrayObject *this,
        Scaleform::MemoryHeap *pheap,
        Scaleform::GFx::AS2::ArrayObject *ao)
{
  Scaleform::ArrayLH<Scaleform::GFx::AS2::Value *,2,Scaleform::ArrayDefaultPolicy> *p_Elements; // r15
  unsigned __int64 v7; // rbx
  unsigned __int64 Size; // rdi
  Scaleform::GFx::AS2::Value *v9; // rax
  Scaleform::GFx::AS2::Value *v10; // rax
  Scaleform::GFx::AS2::Value *v11; // rcx

  p_Elements = &this->Elements;
  Scaleform::ArrayData<Scaleform::GFx::AS2::PagedStack<Scaleform::Ptr<Scaleform::GFx::AS2::FunctionObject>,32>::Page *,Scaleform::AllocatorLH<Scaleform::GFx::AS2::PagedStack<Scaleform::Ptr<Scaleform::GFx::AS2::FunctionObject>,32>::Page *,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &this->Elements.Data,
    ao->Elements.Data.Size);
  v7 = 0i64;
  Size = this->Elements.Data.Size;
  if ( Size )
  {
    do
    {
      if ( ao->Elements.Data.Data[v7] )
      {
        v9 = (Scaleform::GFx::AS2::Value *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))pheap->vfptr->Alloc)(
                                             pheap,
                                             32i64);
        if ( v9 )
        {
          Scaleform::GFx::AS2::Value::Value(v9, ao->Elements.Data.Data[v7]);
          v11 = v10;
        }
        else
        {
          v11 = 0i64;
        }
        p_Elements->Data.Data[v7] = v11;
      }
      ++v7;
    }
    while ( v7 < Size );
  }
}

// File Line: 361
// RVA: 0x6E2500
void __fastcall Scaleform::GFx::AS2::ArrayObject::DetachAll(Scaleform::GFx::AS2::ArrayObject *this)
{
  if ( this->Elements.Data.Size && (this->Elements.Data.Policy.Capacity & 0xFFFFFFFFFFFFFFFEui64) != 0 )
  {
    if ( this->Elements.Data.Data )
    {
      ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      this->Elements.Data.Data = 0i64;
    }
    this->Elements.Data.Policy.Capacity = 0i64;
    this->Elements.Data.Size = 0i64;
  }
  else
  {
    this->Elements.Data.Size = 0i64;
  }
}

// File Line: 366
// RVA: 0x7010F0
void __fastcall Scaleform::GFx::AS2::ArrayObject::JoinToString(
        Scaleform::GFx::AS2::ArrayObject *this,
        Scaleform::GFx::AS2::Environment *pEnv,
        Scaleform::StringBuffer *pbuffer,
        const char *pDelimiter)
{
  unsigned int v8; // ebx
  __int64 v9; // rdi
  Scaleform::GFx::AS2::Value **Data; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::ASString v13; // [rsp+20h] [rbp-48h] BYREF
  __int64 v14; // [rsp+28h] [rbp-40h]
  Scaleform::GFx::AS2::Value v15; // [rsp+30h] [rbp-38h] BYREF
  Scaleform::GFx::ASString result; // [rsp+70h] [rbp+8h] BYREF

  v14 = -2i64;
  Scaleform::StringBuffer::Clear(pbuffer);
  v15.T.Type = 0;
  v8 = 0;
  if ( this->Elements.Data.Size )
  {
    v9 = 0i64;
    do
    {
      if ( v8 )
        Scaleform::StringBuffer::AppendString(pbuffer, pDelimiter, -1i64);
      Data = this->Elements.Data.Data;
      if ( Data[v9] )
      {
        Scaleform::GFx::AS2::Value::ToString(Data[v9], &result, pEnv, -1);
        Scaleform::StringBuffer::AppendString(pbuffer, result.pNode->pData, -1i64);
        pNode = result.pNode;
      }
      else
      {
        Scaleform::GFx::AS2::Value::ToString(&v15, &v13, pEnv, -1);
        Scaleform::StringBuffer::AppendString(pbuffer, v13.pNode->pData, -1i64);
        pNode = v13.pNode;
      }
      if ( pNode->RefCount-- == 1 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      v9 = ++v8;
    }
    while ( v8 < this->Elements.Data.Size );
  }
}

// File Line: 388
// RVA: 0x6DEDF0
void __fastcall Scaleform::GFx::AS2::ArrayObject::Concat(
        Scaleform::GFx::AS2::ArrayObject *this,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::AS2::Value *val)
{
  Scaleform::MemoryHeap *pHeap; // r14
  Scaleform::GFx::AS2::Object *v6; // rax
  Scaleform::GFx::AS2::Object *v7; // rsi
  Scaleform::GFx::AS2::RefCountBaseGC<323> *pPrev; // rax
  unsigned __int64 Size; // r15
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v10; // rdi
  __int64 v11; // r15
  Scaleform::GFx::AS2::Value *v12; // rax
  Scaleform::GFx::AS2::Value *v13; // rax
  Scaleform::GFx::AS2::Value *v14; // rdx
  Scaleform::GFx::AS2::Value *v15; // rax
  Scaleform::GFx::AS2::Value *v16; // rax
  Scaleform::GFx::AS2::Value *v17; // rbp
  unsigned __int64 v18; // rax
  unsigned __int64 v19; // rsi
  unsigned __int64 v20; // r8
  Scaleform::GFx::AS2::Value **v21; // rcx
  Scaleform::MemoryHeap *messageType; // [rsp+60h] [rbp+8h] BYREF
  Scaleform::GFx::AS2::ArrayObject *v23; // [rsp+78h] [rbp+20h]

  v23 = this;
  if ( ++this->RecursionCount >= 255 )
  {
    LODWORD(messageType) = 212992;
    Scaleform::Log::LogMessageById(
      (Scaleform::GFx::LogState *)this->LogPtr,
      (Scaleform::LogMessageId)&messageType,
      "256 levels of recursion is reached\n");
    goto LABEL_24;
  }
  pHeap = penv->StringContext.pContext->pHeap;
  messageType = pHeap;
  v6 = Scaleform::GFx::AS2::Value::ToObject(val, penv);
  v7 = v6;
  if ( v6
    && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v6->Scaleform::GFx::AS2::ObjectInterface::vfptr->gap8[8])(&v6->Scaleform::GFx::AS2::ObjectInterface) == 7 )
  {
    pPrev = v7[1].pPrev;
    if ( pPrev )
    {
      Size = this->Elements.Data.Size;
      Scaleform::GFx::AS2::ArrayObject::Resize(this, (_DWORD)pPrev + Size);
      v10 = 0i64;
      if ( v7[1].pPrev )
      {
        v11 = 8i64 * (unsigned int)Size;
        do
        {
          v12 = (Scaleform::GFx::AS2::Value *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))pHeap->vfptr->Alloc)(
                                                pHeap,
                                                32i64);
          if ( v12 )
          {
            Scaleform::GFx::AS2::Value::Value(
              v12,
              (Scaleform::GFx::AS2::Value *)(&v7[1].pRCC->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::$8D47FECC8062B48992CD8F53EA11C4BE::vfptr)[(_QWORD)v10]);
            v14 = v13;
          }
          else
          {
            v14 = 0i64;
          }
          *(Scaleform::GFx::AS2::Value **)((char *)&this->Elements.Data.Data[(_QWORD)v10] + v11) = v14;
          v10 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)((char *)v10 + 1);
        }
        while ( v10 < v7[1].pPrev );
      }
    }
    goto LABEL_24;
  }
  v15 = (Scaleform::GFx::AS2::Value *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))pHeap->vfptr->Alloc)(
                                        pHeap,
                                        32i64);
  if ( v15 )
  {
    Scaleform::GFx::AS2::Value::Value(v15, val);
    v17 = v16;
  }
  else
  {
    v17 = 0i64;
  }
  v18 = this->Elements.Data.Size;
  v19 = v18 + 1;
  if ( v18 + 1 >= v18 )
  {
    if ( v19 <= this->Elements.Data.Policy.Capacity )
      goto LABEL_22;
    v20 = v19 + (v19 >> 2);
  }
  else
  {
    if ( v19 >= this->Elements.Data.Policy.Capacity >> 1 )
      goto LABEL_22;
    v20 = v18 + 1;
  }
  Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
    (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,2>,Scaleform::ArrayDefaultPolicy> *)&this->Elements,
    &this->Elements,
    v20);
LABEL_22:
  this->Elements.Data.Size = v19;
  v21 = &this->Elements.Data.Data[v19 - 1];
  if ( v21 )
    *v21 = v17;
LABEL_24:
  --this->RecursionCount;
}21 = &this->Elements.Data.Data[v19 - 1];
  if ( v21 )
    *v21 = v

// File Line: 415
// RVA: 0x70AA80
void __fastcall Scaleform::GFx::AS2::ArrayObject::PushBack(
        Scaleform::GFx::AS2::ArrayObject *this,
        Scaleform::GFx::AS2::Value *val)
{
  Scaleform::GFx::AS2::Value *v4; // rax
  Scaleform::GFx::AS2::Object *v5; // rax
  Scaleform::GFx::AS2::Object *v6; // rsi
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,2>,Scaleform::ArrayDefaultPolicy> *p_Elements; // rbx
  unsigned __int64 v8; // rdi
  unsigned __int64 v9; // r8
  Scaleform::Ptr<Scaleform::GFx::AS2::Object> *v10; // rcx
  int v11; // [rsp+60h] [rbp+18h] BYREF
  Scaleform::GFx::AS2::Value *v12; // [rsp+68h] [rbp+20h]

  v11 = 323;
  v4 = (Scaleform::GFx::AS2::Value *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::GFx::AS2::ArrayObject *, __int64, int *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
                                       Scaleform::Memory::pGlobalHeap,
                                       this,
                                       32i64,
                                       &v11,
                                       -2i64);
  v12 = v4;
  if ( v4 )
  {
    Scaleform::GFx::AS2::Value::Value(v4, val);
    v6 = v5;
  }
  else
  {
    v6 = 0i64;
  }
  p_Elements = (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,2>,Scaleform::ArrayDefaultPolicy> *)&this->Elements;
  v8 = p_Elements->Size + 1;
  if ( v8 >= p_Elements->Size )
  {
    if ( v8 <= p_Elements->Policy.Capacity )
      goto LABEL_10;
    v9 = v8 + (v8 >> 2);
  }
  else
  {
    if ( v8 >= p_Elements->Policy.Capacity >> 1 )
      goto LABEL_10;
    v9 = p_Elements->Size + 1;
  }
  Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
    p_Elements,
    p_Elements,
    v9);
LABEL_10:
  p_Elements->Size = v8;
  v10 = &p_Elements->Data[v8 - 1];
  if ( v10 )
    v10->pObject = v6;
}

// File Line: 420
// RVA: 0x70AB40
void __fastcall Scaleform::GFx::AS2::ArrayObject::PushBack(Scaleform::GFx::AS2::ArrayObject *this)
{
  unsigned __int64 Size; // rax
  Scaleform::ArrayLH<Scaleform::GFx::AS2::Value *,2,Scaleform::ArrayDefaultPolicy> *p_Elements; // rbx
  unsigned __int64 v3; // rdi
  unsigned __int64 v4; // r8
  Scaleform::GFx::AS2::Value **Data; // rcx
  Scaleform::GFx::AS2::Value **v6; // rcx

  Size = this->Elements.Data.Size;
  p_Elements = &this->Elements;
  v3 = Size + 1;
  if ( Size + 1 >= Size )
  {
    if ( v3 <= this->Elements.Data.Policy.Capacity )
      goto LABEL_7;
    v4 = v3 + (v3 >> 2);
  }
  else
  {
    if ( v3 >= this->Elements.Data.Policy.Capacity >> 1 )
      goto LABEL_7;
    v4 = Size + 1;
  }
  Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
    (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,2>,Scaleform::ArrayDefaultPolicy> *)&this->Elements,
    &this->Elements,
    v4);
LABEL_7:
  Data = p_Elements->Data.Data;
  p_Elements->Data.Size = v3;
  v6 = &Data[v3 - 1];
  if ( v6 )
    *v6 = 0i64;
}

// File Line: 433
// RVA: 0x70FF90
void __fastcall Scaleform::GFx::AS2::ArrayObject::RemoveElements(
        Scaleform::GFx::AS2::ArrayObject *this,
        int start,
        int count)
{
  __int64 v3; // r15
  __int64 v6; // rsi
  __int64 v7; // rbp
  Scaleform::GFx::AS2::Value **Data; // rax
  Scaleform::GFx::AS2::Value *v9; // rbx
  int v10; // r9d
  __int64 v11; // r8
  Scaleform::GFx::AS2::Value **v12; // rdx
  __int64 v13; // rcx
  Scaleform::GFx::AS2::Value *v14; // rax
  unsigned __int64 Size; // rbx
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,2>,Scaleform::ArrayDefaultPolicy> *p_Elements; // rdi
  unsigned __int64 v17; // rbx
  unsigned __int64 v18; // r8

  v3 = count;
  if ( this->Elements.Data.Size )
  {
    if ( count > 0 )
    {
      v6 = start;
      v7 = count;
      do
      {
        Data = this->Elements.Data.Data;
        v9 = Data[v6];
        if ( v9 )
        {
          if ( v9->T.Type >= 5u )
            Scaleform::GFx::AS2::Value::DropRefs(Data[v6]);
          Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v9);
        }
        ++v6;
        --v7;
      }
      while ( v7 );
    }
    v10 = start + v3;
    if ( start + (int)v3 < SLODWORD(this->Elements.Data.Size) )
    {
      v11 = v10;
      do
      {
        v12 = this->Elements.Data.Data;
        v13 = -8 * v3 + v11 * 8;
        ++v10;
        v14 = v12[v11++];
        *(Scaleform::GFx::AS2::Value **)((char *)v12 + v13) = v14;
        this->Elements.Data.Data[v11 - 1] = 0i64;
      }
      while ( v10 < SLODWORD(this->Elements.Data.Size) );
    }
    Size = this->Elements.Data.Size;
    p_Elements = (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,2>,Scaleform::ArrayDefaultPolicy> *)&this->Elements;
    v17 = Size - v3;
    if ( v17 >= p_Elements->Size )
    {
      if ( v17 > p_Elements->Policy.Capacity )
      {
        v18 = v17 + (v17 >> 2);
        goto LABEL_17;
      }
    }
    else if ( v17 < p_Elements->Policy.Capacity >> 1 )
    {
      v18 = v17;
LABEL_17:
      Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        p_Elements,
        p_Elements,
        v18);
    }
    p_Elements->Size = v17;
  }
}

// File Line: 451
// RVA: 0x6FD7E0
void __fastcall Scaleform::GFx::AS2::ArrayObject::InsertEmpty(
        Scaleform::GFx::AS2::ArrayObject *this,
        int start,
        int count)
{
  int Size; // ebx
  __int64 v4; // rsi
  __int64 v5; // r14
  __int64 v7; // r9
  __int64 v8; // r8
  __int64 i; // r10
  __int64 v10; // rax
  __int64 v11; // rax

  Size = this->Elements.Data.Size;
  v4 = count;
  v5 = start;
  Scaleform::ArrayData<Scaleform::GFx::AS2::PagedStack<Scaleform::Ptr<Scaleform::GFx::AS2::FunctionObject>,32>::Page *,Scaleform::AllocatorLH<Scaleform::GFx::AS2::PagedStack<Scaleform::Ptr<Scaleform::GFx::AS2::FunctionObject>,32>::Page *,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &this->Elements.Data,
    Size + count);
  v7 = v4;
  if ( Size )
  {
    v8 = LODWORD(this->Elements.Data.Size) - 1;
    for ( i = (int)v5 + (int)v4;
          v8 >= i;
          this->Elements.Data.Data[v8 + 1] = *(Scaleform::GFx::AS2::Value **)((char *)this->Elements.Data.Data + v10) )
    {
      v10 = -8 * v4 + 8 * v8--;
    }
  }
  if ( (int)v4 > 0 )
  {
    v11 = v5;
    do
    {
      this->Elements.Data.Data[v11++] = 0i64;
      --v7;
    }
    while ( v7 );
  }
}

// File Line: 469
// RVA: 0x708510
void __fastcall Scaleform::GFx::AS2::ArrayObject::PopFront(Scaleform::GFx::AS2::ArrayObject *this)
{
  Scaleform::GFx::AS2::Value **Data; // rax
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,2>,Scaleform::ArrayDefaultPolicy> *p_Elements; // rbx
  Scaleform::GFx::AS2::Value *v4; // rsi
  unsigned int v5; // r8d
  __int64 v6; // r9
  __int64 v7; // rcx
  Scaleform::GFx::AS2::Object *pObject; // rax
  unsigned __int64 v9; // rdi
  unsigned __int64 v10; // r8

  if ( this->Elements.Data.Size )
  {
    Data = this->Elements.Data.Data;
    p_Elements = (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,2>,Scaleform::ArrayDefaultPolicy> *)&this->Elements;
    v4 = *Data;
    if ( *Data )
    {
      if ( v4->T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(*Data);
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v4);
    }
    v5 = 1;
    if ( this->Elements.Data.Size > 1 )
    {
      v6 = 1i64;
      do
      {
        v7 = v5++ - 1;
        pObject = p_Elements->Data[v6].pObject;
        v6 = v5;
        p_Elements->Data[v7].pObject = pObject;
      }
      while ( v5 < this->Elements.Data.Size );
    }
    p_Elements->Data[this->Elements.Data.Size - 1].pObject = 0i64;
    v9 = this->Elements.Data.Size - 1;
    if ( v9 >= p_Elements->Size )
    {
      if ( v9 > p_Elements->Policy.Capacity )
      {
        v10 = v9 + (v9 >> 2);
        goto LABEL_14;
      }
    }
    else if ( v9 < p_Elements->Policy.Capacity >> 1 )
    {
      v10 = v9;
LABEL_14:
      Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        p_Elements,
        p_Elements,
        v10);
    }
    p_Elements->Size = v9;
  }
}

// File Line: 483
// RVA: 0x714490
void __fastcall Scaleform::GFx::AS2::ArrayObject::SetElement(
        Scaleform::GFx::AS2::ArrayObject *this,
        int i,
        Scaleform::GFx::AS2::Value *val)
{
  __int64 v5; // rdi
  Scaleform::GFx::AS2::Value *v6; // rax
  Scaleform::GFx::AS2::Value *v7; // rcx
  int v8; // [rsp+58h] [rbp+10h] BYREF
  Scaleform::GFx::AS2::Value *v9; // [rsp+68h] [rbp+20h]

  if ( i >= 0 && i < SLODWORD(this->Elements.Data.Size) )
  {
    this->LengthValueOverriden = 0;
    v5 = i;
    if ( !this->Elements.Data.Data[v5] )
    {
      v8 = 323;
      v6 = (Scaleform::GFx::AS2::Value *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::GFx::AS2::ArrayObject *, __int64, int *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
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
      this->Elements.Data.Data[v5] = v7;
    }
    Scaleform::GFx::AS2::Value::operator=(this->Elements.Data.Data[v5], val);
  }
}

// File Line: 492
// RVA: 0x714530
void __fastcall Scaleform::GFx::AS2::ArrayObject::SetElementSafe(
        Scaleform::GFx::AS2::ArrayObject *this,
        int idx,
        Scaleform::GFx::AS2::Value *val)
{
  __int64 v4; // rdi
  __int64 v6; // rdi
  Scaleform::GFx::AS2::Value *v7; // rax
  Scaleform::GFx::AS2::Value *v8; // rcx
  int v9; // [rsp+58h] [rbp+10h] BYREF
  Scaleform::GFx::AS2::Value *v10; // [rsp+68h] [rbp+20h]

  v4 = idx;
  this->LengthValueOverriden = 0;
  if ( idx >= SLODWORD(this->Elements.Data.Size) )
    Scaleform::GFx::AS2::ArrayObject::Resize(this, idx + 1);
  v6 = v4;
  if ( !this->Elements.Data.Data[v6] )
  {
    v9 = 323;
    v7 = (Scaleform::GFx::AS2::Value *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::GFx::AS2::ArrayObject *, __int64, int *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
                                         Scaleform::Memory::pGlobalHeap,
                                         this,
                                         32i64,
                                         &v9,
                                         -2i64);
    v8 = v7;
    v10 = v7;
    if ( v7 )
      v7->T.Type = 0;
    else
      v8 = 0i64;
    this->Elements.Data.Data[v6] = v8;
  }
  Scaleform::GFx::AS2::Value::operator=(this->Elements.Data.Data[v6], val);
}

// File Line: 519
// RVA: 0x6BC3A0
void __fastcall Scaleform::GFx::AS2::ArrayObject::ArrayConcat(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rdi
  Scaleform::GFx::AS2::ArrayObject *v4; // rsi
  int i; // edi
  unsigned int v6; // r9d
  Scaleform::GFx::AS2::Environment *Env; // rdx
  Scaleform::GFx::AS2::Value *v8; // r8
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::Value val; // [rsp+38h] [rbp-30h] BYREF

  ThisPtr = fn->ThisPtr;
  if ( ThisPtr
    && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(ThisPtr) == 7 )
  {
    v3 = fn->ThisPtr;
    if ( v3 )
      v3 -= 2;
    BYTE4(v3[8].pProto.pObject) = 0;
    v4 = (Scaleform::GFx::AS2::ArrayObject *)Scaleform::GFx::AS2::Environment::OperatorNew(
                                               fn->Env,
                                               fn->Env->StringContext.pContext->pGlobal.pObject,
                                               (Scaleform::GFx::ASString *)&fn->Env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[8].RefCount,
                                               0,
                                               -1);
    if ( v4 )
    {
      Scaleform::GFx::AS2::Value::Value(&val, (Scaleform::GFx::AS2::Object *)v3);
      Scaleform::GFx::AS2::ArrayObject::Concat(v4, fn->Env, &val);
      if ( val.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&val);
      for ( i = 0; i < fn->NArgs; ++i )
      {
        v6 = fn->FirstArgBottomIndex - i;
        Env = fn->Env;
        v8 = 0i64;
        if ( v6 <= 32 * ((unsigned int)Env->Stack.Pages.Data.Size - 1)
                 + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
          v8 = &Env->Stack.Pages.Data.Data[v6 >> 5]->Values[v6 & 0x1F];
        Scaleform::GFx::AS2::ArrayObject::Concat(v4, Env, v8);
      }
    }
    Scaleform::GFx::AS2::Value::SetAsObject(fn->Result, v4);
    if ( v4 )
    {
      RefCount = v4->RefCount;
      if ( (RefCount & 0x3FFFFFF) != 0 )
      {
        v4->RefCount = RefCount - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v4);
      }
    }
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      fn->Env,
      "Error: Null or invalid this is used for a method of %s class.\n",
      "Array");
  }
}

// File Line: 539
// RVA: 0x6BC520
void __fastcall Scaleform::GFx::AS2::ArrayObject::ArrayJoin(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rsi
  Scaleform::GFx::AS2::Value *v4; // rdi
  Scaleform::GFx::AS2::ArrayObject *v5; // rsi
  unsigned int FirstArgBottomIndex; // r9d
  Scaleform::GFx::AS2::Environment *Env; // r8
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v9; // zf
  char *pData; // r8
  Scaleform::GFx::ASString *v11; // rdi
  Scaleform::GFx::AS2::Value *v12; // rbx
  Scaleform::GFx::ASStringNode *v13; // rax
  Scaleform::GFx::ASStringNode *v14; // rcx
  Scaleform::StringBuffer pbuffer; // [rsp+28h] [rbp-40h] BYREF
  Scaleform::GFx::ASString result; // [rsp+70h] [rbp+8h] BYREF

  ThisPtr = fn->ThisPtr;
  if ( ThisPtr
    && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(ThisPtr) == 7 )
  {
    v3 = fn->ThisPtr;
    v4 = 0i64;
    if ( v3 )
      v5 = (Scaleform::GFx::AS2::ArrayObject *)&v3[-2];
    else
      v5 = 0i64;
    v5->LengthValueOverriden = 0;
    Scaleform::StringBuffer::StringBuffer(&pbuffer, fn->Env->StringContext.pContext->pHeap);
    if ( fn->NArgs )
    {
      FirstArgBottomIndex = fn->FirstArgBottomIndex;
      Env = fn->Env;
      if ( FirstArgBottomIndex <= 32 * ((unsigned int)Env->Stack.Pages.Data.Size - 1)
                                + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
        v4 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
      Scaleform::GFx::AS2::Value::ToString(v4, &result, Env, -1);
      Scaleform::GFx::AS2::ArrayObject::JoinToString(v5, fn->Env, &pbuffer, result.pNode->pData);
      pNode = result.pNode;
      v9 = result.pNode->RefCount-- == 1;
      if ( v9 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    }
    else
    {
      Scaleform::GFx::AS2::ArrayObject::JoinToString(v5, fn->Env, &pbuffer, ",");
    }
    pData = &customCaption;
    if ( pbuffer.pData )
      pData = pbuffer.pData;
    v11 = Scaleform::GFx::AS2::Environment::CreateString(fn->Env, &result, pData, pbuffer.Size);
    v12 = fn->Result;
    if ( v12->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(v12);
    v12->T.Type = 5;
    v13 = v11->pNode;
    v12->NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)v11->pNode;
    ++v13->RefCount;
    v14 = result.pNode;
    v9 = result.pNode->RefCount-- == 1;
    if ( v9 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v14);
    Scaleform::ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayDataBase<int,Scaleform::AllocatorGH<int,2>,Scaleform::ArrayDefaultPolicy> *)&pbuffer);
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      fn->Env,
      "Error: Null or invalid this is used for a method of %s class.\n",
      "Array");
  }
}

// File Line: 560
// RVA: 0x6A50D0
void __fastcall Scaleform::GFx::AS2::ArrayObject::ArrayPop(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rdi
  int vfptr; // eax
  Scaleform::GFx::AS2::Value *v5; // rdx
  Scaleform::GFx::AS2::Value *Result; // rbx
  Scaleform::GFx::AS2::Value *v7; // rbx

  ThisPtr = fn->ThisPtr;
  if ( ThisPtr
    && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(ThisPtr) == 7 )
  {
    v3 = fn->ThisPtr;
    if ( v3 )
      v3 -= 2;
    vfptr = (int)v3[7].vfptr;
    BYTE4(v3[8].pProto.pObject) = 0;
    if ( vfptr )
    {
      v5 = (Scaleform::GFx::AS2::Value *)*((_QWORD *)v3[6].pProto.pObject + vfptr - 1);
      if ( v5 )
      {
        Scaleform::GFx::AS2::Value::operator=(fn->Result, v5);
      }
      else
      {
        Result = fn->Result;
        Scaleform::GFx::AS2::Value::DropRefs(Result);
        Result->T.Type = 0;
      }
      if ( v3[7].vfptr )
        Scaleform::GFx::AS2::ArrayObject::Resize((Scaleform::GFx::AS2::ArrayObject *)v3, LODWORD(v3[7].vfptr) - 1);
    }
    else
    {
      v7 = fn->Result;
      Scaleform::GFx::AS2::Value::DropRefs(v7);
      v7->T.Type = 0;
    }
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      fn->Env,
      "Error: Null or invalid this is used for a method of %s class.\n",
      "Array");
  }
}

// File Line: 580
// RVA: 0x6A51A0
void __fastcall Scaleform::GFx::AS2::ArrayObject::ArrayPush(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rcx
  Scaleform::GFx::AS2::ArrayObject *v3; // rsi
  int v4; // edi
  Scaleform::GFx::AS2::Environment *Env; // r8
  Scaleform::GFx::AS2::Value *v6; // rdx
  unsigned int v7; // r9d
  Scaleform::GFx::AS2::Value *Result; // rbx
  unsigned __int64 Size; // rdi

  ThisPtr = fn->ThisPtr;
  if ( ThisPtr
    && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(ThisPtr) == 7 )
  {
    v3 = (Scaleform::GFx::AS2::ArrayObject *)fn->ThisPtr;
    if ( v3 )
      v3 = (Scaleform::GFx::AS2::ArrayObject *)((char *)v3 - 32);
    v4 = 0;
    for ( v3->LengthValueOverriden = 0; v4 < fn->NArgs; ++v4 )
    {
      Env = fn->Env;
      v6 = 0i64;
      v7 = fn->FirstArgBottomIndex - v4;
      if ( v7 <= 32 * (LODWORD(Env->Stack.Pages.Data.Size) - 1)
               + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
        v6 = &Env->Stack.Pages.Data.Data[(unsigned __int64)v7 >> 5]->Values[v7 & 0x1F];
      Scaleform::GFx::AS2::ArrayObject::PushBack(v3, v6);
    }
    Result = fn->Result;
    Size = v3->Elements.Data.Size;
    if ( Result->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(Result);
    Result->NV.Int32Value = Size;
    Result->T.Type = 4;
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      fn->Env,
      "Error: Null or invalid this is used for a method of %s class.\n",
      "Array");
  }
}

// File Line: 594
// RVA: 0x6A5290
void __fastcall Scaleform::GFx::AS2::ArrayObject::ArrayReverse(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // r11
  __int64 v4; // rdx
  Scaleform::GFx::AS2::ObjectInterface *v5; // r11
  int vfptr; // eax
  __int64 v7; // r10
  Scaleform::GFx::AS2::Object *pObject; // rax
  Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *v9; // r8
  Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl **v10; // r9
  Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl **v11; // rcx

  ThisPtr = fn->ThisPtr;
  if ( ThisPtr
    && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(ThisPtr) == 7 )
  {
    v3 = fn->ThisPtr;
    v4 = 0i64;
    if ( v3 )
      v5 = v3 - 2;
    else
      v5 = 0i64;
    vfptr = (int)v5[7].vfptr;
    BYTE4(v5[8].pProto.pObject) = 0;
    v7 = --vfptr;
    if ( vfptr > 0 )
    {
      do
      {
        pObject = v5[6].pProto.pObject;
        v9 = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)*((_QWORD *)&pObject->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr
                                                             + v4);
        v10 = &pObject->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr
            + v7;
        v11 = &pObject->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr
            + v4++;
        --v7;
        *v11 = *v10;
        *v10 = v9;
      }
      while ( v4 < v7 );
    }
    Scaleform::GFx::AS2::Value::SetAsObject(fn->Result, (Scaleform::GFx::AS2::Object *)v5);
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      fn->Env,
      "Error: Null or invalid this is used for a method of %s class.\n",
      "Array");
  }
}

// File Line: 608
// RVA: 0x6A5350
void __fastcall Scaleform::GFx::AS2::ArrayObject::ArrayShift(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rdi
  Scaleform::GFx::AS2::Value *v4; // rbx
  Scaleform::GFx::AS2::Value **pObject; // rax
  Scaleform::GFx::AS2::Value *Result; // rbx

  ThisPtr = fn->ThisPtr;
  if ( ThisPtr
    && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(ThisPtr) == 7 )
  {
    v3 = fn->ThisPtr;
    if ( v3 )
      v3 -= 2;
    if ( LODWORD(v3[7].vfptr) )
    {
      pObject = (Scaleform::GFx::AS2::Value **)v3[6].pProto.pObject;
      BYTE4(v3[8].pProto.pObject) = 0;
      if ( *pObject )
      {
        Scaleform::GFx::AS2::Value::operator=(fn->Result, *pObject);
      }
      else
      {
        Result = fn->Result;
        Scaleform::GFx::AS2::Value::DropRefs(Result);
        Result->T.Type = 0;
      }
      Scaleform::GFx::AS2::ArrayObject::PopFront((Scaleform::GFx::AS2::ArrayObject *)v3);
    }
    else
    {
      v4 = fn->Result;
      Scaleform::GFx::AS2::Value::DropRefs(v4);
      v4->T.Type = 0;
    }
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      fn->Env,
      "Error: Null or invalid this is used for a method of %s class.\n",
      "Array");
  }
}

// File Line: 627
// RVA: 0x6A54E0
void __fastcall Scaleform::GFx::AS2::ArrayObject::ArraySlice(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rsi
  Scaleform::GFx::AS2::ObjectInterface *v4; // rsi
  Scaleform::GFx::AS2::ObjectInterfaceVtbl *v5; // rbx
  Scaleform::GFx::AS2::ObjectInterfaceVtbl *vfptr; // rbp
  unsigned int FirstArgBottomIndex; // r10d
  Scaleform::GFx::AS2::Environment *Env; // rdx
  Scaleform::GFx::AS2::Value *v9; // r9
  unsigned int v10; // r9d
  Scaleform::GFx::AS2::Environment *v11; // rdx
  Scaleform::GFx::AS2::Value *v12; // r10
  Scaleform::GFx::AS2::ArrayObject *v13; // rdi
  Scaleform::GFx::AS2::Value *v14; // rdx
  unsigned int RefCount; // eax

  ThisPtr = fn->ThisPtr;
  if ( ThisPtr
    && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(ThisPtr) == 7 )
  {
    v3 = fn->ThisPtr;
    if ( v3 )
      v4 = v3 - 2;
    else
      v4 = 0i64;
    BYTE4(v4[8].pProto.pObject) = 0;
    LODWORD(v5) = 0;
    vfptr = v4[7].vfptr;
    if ( fn->NArgs >= 1 )
    {
      FirstArgBottomIndex = fn->FirstArgBottomIndex;
      Env = fn->Env;
      v9 = 0i64;
      if ( FirstArgBottomIndex <= 32 * ((unsigned int)Env->Stack.Pages.Data.Size - 1)
                                + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
        v9 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
      LODWORD(v5) = Scaleform::GFx::AS2::Value::ToInt32(v9, Env);
      if ( (int)v5 < 0 )
      {
        LODWORD(v5) = LODWORD(v4[7].vfptr) + (_DWORD)v5;
        if ( (int)v5 < 0 )
          LODWORD(v5) = 0;
      }
      if ( (int)v5 > (int)v4[7].vfptr )
        v5 = v4[7].vfptr;
    }
    if ( fn->NArgs >= 2 )
    {
      v10 = fn->FirstArgBottomIndex - 1;
      v11 = fn->Env;
      v12 = 0i64;
      if ( v10 <= 32 * ((unsigned int)v11->Stack.Pages.Data.Size - 1)
                + (unsigned int)(v11->Stack.pCurrent - v11->Stack.pPageStart) )
        v12 = &v11->Stack.Pages.Data.Data[v10 >> 5]->Values[v10 & 0x1F];
      LODWORD(vfptr) = Scaleform::GFx::AS2::Value::ToInt32(v12, v11);
      if ( (int)vfptr < 0 )
      {
        LODWORD(vfptr) = LODWORD(v4[7].vfptr) + (_DWORD)vfptr;
        if ( (int)vfptr < 0 )
          LODWORD(vfptr) = 0;
      }
      if ( (int)vfptr > (int)v4[7].vfptr )
        LODWORD(vfptr) = v4[7].vfptr;
    }
    v13 = (Scaleform::GFx::AS2::ArrayObject *)Scaleform::GFx::AS2::Environment::OperatorNew(
                                                fn->Env,
                                                fn->Env->StringContext.pContext->pGlobal.pObject,
                                                (Scaleform::GFx::ASString *)&fn->Env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[8].RefCount,
                                                0,
                                                -1);
    if ( v13 )
    {
      v5 = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)(int)v5;
      if ( (int)v5 < (__int64)(int)vfptr )
      {
        do
        {
          v14 = (Scaleform::GFx::AS2::Value *)*((_QWORD *)&v4[6].pProto.pObject->vfptr + (_QWORD)v5);
          if ( v14 )
            Scaleform::GFx::AS2::ArrayObject::PushBack(v13, v14);
          else
            Scaleform::GFx::AS2::ArrayObject::PushBack(v13);
          v5 = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)((char *)v5 + 1);
        }
        while ( (__int64)v5 < (int)vfptr );
      }
    }
    Scaleform::GFx::AS2::Value::SetAsObject(fn->Result, v13);
    if ( v13 )
    {
      RefCount = v13->RefCount;
      if ( (RefCount & 0x3FFFFFF) != 0 )
      {
        v13->RefCount = RefCount - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v13);
      }
    }
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      fn->Env,
      "Error: Null or invalid this is used for a method of %s class.\n",
      "Array");
  }
}

// File Line: 671
// RVA: 0x6A56F0
void __fastcall Scaleform::GFx::AS2::ArrayObject::ArraySort(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rax
  Scaleform::GFx::AS2::ArrayObject *v4; // r12
  Scaleform::GFx::AS2::FunctionObject *v5; // r15
  Scaleform::GFx::AS2::LocalFrame *v6; // r13
  int v7; // r14d
  unsigned int FirstArgBottomIndex; // r9d
  Scaleform::GFx::AS2::Environment *Env; // r8
  Scaleform::GFx::AS2::Value *v10; // r10
  Scaleform::GFx::AS2::Value *v11; // r10
  Scaleform::GFx::AS2::Value *v12; // r10
  Scaleform::GFx::AS2::FunctionRef *v13; // rax
  char Flags; // al
  Scaleform::GFx::AS2::FunctionObject *Function; // rcx
  unsigned int RefCount; // edx
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // rcx
  unsigned int v18; // eax
  unsigned int v19; // r8d
  Scaleform::GFx::AS2::Environment *v20; // r10
  Scaleform::GFx::AS2::Value *v21; // r9
  Scaleform::GFx::AS2::ArrayObject *v22; // rax
  Scaleform::GFx::AS2::ArrayObject *v23; // rbx
  Scaleform::Log *LogPtr; // rsi
  int v25; // esi
  __int64 v26; // r14
  Scaleform::GFx::AS2::Value *v27; // rdi
  char v28; // di
  Scaleform::GFx::AS2::FunctionObject *v29; // rcx
  unsigned int v30; // eax
  Scaleform::GFx::AS2::Object *v31; // rdx
  Scaleform::GFx::AS2::LocalFrame *v32; // rcx
  unsigned int v33; // eax
  unsigned int v34; // eax
  char v35; // bl
  unsigned int v36; // eax
  unsigned int v37; // eax
  Scaleform::GFx::AS2::FunctionRefBase v38; // [rsp+30h] [rbp-49h] BYREF
  Scaleform::GFx::AS2::ArraySortFunctor v39; // [rsp+48h] [rbp-31h] BYREF
  Scaleform::GFx::AS2::FunctionRef result; // [rsp+80h] [rbp+7h] BYREF
  __int64 v41; // [rsp+98h] [rbp+1Fh]
  char v42; // [rsp+E0h] [rbp+67h]
  Scaleform::GFx::AS2::Environment *v43; // [rsp+E8h] [rbp+6Fh]

  v41 = -2i64;
  ThisPtr = fn->ThisPtr;
  if ( !ThisPtr
    || (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(ThisPtr) != 7 )
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      fn->Env,
      "Error: Null or invalid this is used for a method of %s class.\n",
      "Array");
    return;
  }
  v3 = fn->ThisPtr;
  v4 = (Scaleform::GFx::AS2::ArrayObject *)&v3[-2];
  if ( !v3 )
    v4 = 0i64;
  v4->LengthValueOverriden = 0;
  v5 = 0i64;
  memset(&v38, 0, 17);
  v6 = 0i64;
  v7 = 0;
  v42 = 0;
  if ( fn->NArgs >= 1 )
  {
    FirstArgBottomIndex = fn->FirstArgBottomIndex;
    Env = fn->Env;
    v10 = 0i64;
    if ( FirstArgBottomIndex <= 32 * ((unsigned int)Env->Stack.Pages.Data.Size - 1)
                              + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
      v10 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
    if ( v10->T.Type == 8 || v10->T.Type == 11 )
    {
      v12 = 0i64;
      if ( FirstArgBottomIndex <= 32 * ((unsigned int)Env->Stack.Pages.Data.Size - 1)
                                + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
        v12 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
      v13 = Scaleform::GFx::AS2::Value::ToFunction(v12, &result, Env);
      Scaleform::GFx::AS2::FunctionRefBase::Assign(&v38, v13);
      Flags = result.Flags;
      if ( (result.Flags & 2) == 0 )
      {
        Function = result.Function;
        if ( result.Function )
        {
          RefCount = result.Function->RefCount;
          if ( (RefCount & 0x3FFFFFF) != 0 )
          {
            result.Function->RefCount = RefCount - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(Function);
            Flags = result.Flags;
          }
        }
      }
      result.Function = 0i64;
      if ( (Flags & 1) == 0 )
      {
        pLocalFrame = result.pLocalFrame;
        if ( result.pLocalFrame )
        {
          v18 = result.pLocalFrame->RefCount;
          if ( (v18 & 0x3FFFFFF) != 0 )
          {
            result.pLocalFrame->RefCount = v18 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pLocalFrame);
          }
        }
      }
      result.pLocalFrame = 0i64;
      v6 = v38.pLocalFrame;
      v5 = v38.Function;
    }
    else
    {
      v11 = 0i64;
      if ( FirstArgBottomIndex <= 32 * ((unsigned int)Env->Stack.Pages.Data.Size - 1)
                                + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
        v11 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
      v7 = Scaleform::GFx::AS2::Value::ToInt32(v11, fn->Env);
      v42 = v7;
    }
  }
  if ( v5 && fn->NArgs >= 2 )
  {
    v19 = fn->FirstArgBottomIndex - 1;
    v20 = fn->Env;
    v21 = 0i64;
    if ( v19 <= 32 * ((unsigned int)v20->Stack.Pages.Data.Size - 1)
              + (unsigned int)(v20->Stack.pCurrent - v20->Stack.pPageStart) )
      v21 = &v20->Stack.Pages.Data.Data[v19 >> 5]->Values[v19 & 0x1F];
    v7 = Scaleform::GFx::AS2::Value::ToInt32(v21, fn->Env);
    v42 = v7;
  }
  v22 = (Scaleform::GFx::AS2::ArrayObject *)Scaleform::GFx::AS2::Environment::OperatorNew(
                                              fn->Env,
                                              fn->Env->StringContext.pContext->pGlobal.pObject,
                                              (Scaleform::GFx::ASString *)&fn->Env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[8].RefCount,
                                              0,
                                              -1);
  v23 = v22;
  if ( v22 )
  {
    Scaleform::GFx::AS2::ArrayObject::ShallowCopyFrom(v22, v4);
    LogPtr = v4->LogPtr;
    v43 = fn->Env;
    v39.This = &v23->Scaleform::GFx::AS2::ObjectInterface;
    v39.Flags = v7;
    v39.Func.Flags = 0;
    v39.Func.Function = v5;
    if ( v5 )
      v5->RefCount = (v5->RefCount + 1) & 0x8FFFFFFF;
    v39.Func.pLocalFrame = 0i64;
    if ( v6 )
      Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(&v39.Func, v6, v38.Flags & 1);
    v39.Env = v43;
    v39.LogPtr = LogPtr;
    if ( !Scaleform::GFx::AS2::ArrayObject::Sort<Scaleform::GFx::AS2::ArraySortFunctor>(v23, &v39) )
      Scaleform::GFx::AS2::Environment::LogScriptError(fn->Env, "Array.sort - sorting failed, check your sort functor");
    if ( (v7 & 4) != 0 && (v25 = 1, SLODWORD(v23->Elements.Data.Size) > 1) )
    {
      v26 = 1i64;
      while ( Scaleform::GFx::AS2::ArraySortFunctor::Compare(
                &v39,
                v23->Elements.Data.Data[v26 - 1],
                v23->Elements.Data.Data[v26]) )
      {
        ++v25;
        ++v26;
        if ( v25 >= SLODWORD(v23->Elements.Data.Size) )
        {
          LOBYTE(v7) = v42;
          goto LABEL_53;
        }
      }
      v27 = fn->Result;
      if ( v27->T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(v27);
      v27->T.Type = 4;
      v27->NV.Int32Value = 0;
      if ( v23->Elements.Data.Size && (v23->Elements.Data.Policy.Capacity & 0xFFFFFFFFFFFFFFFEui64) != 0 )
      {
        if ( v23->Elements.Data.Data )
        {
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
          v23->Elements.Data.Data = 0i64;
        }
        v23->Elements.Data.Policy.Capacity = 0i64;
      }
      v23->Elements.Data.Size = 0i64;
      v28 = v39.Func.Flags;
      if ( (v39.Func.Flags & 2) != 0 )
        goto LABEL_60;
      v29 = v39.Func.Function;
      if ( !v39.Func.Function )
        goto LABEL_60;
      v30 = v39.Func.Function->RefCount;
      if ( (v30 & 0x3FFFFFF) == 0 )
        goto LABEL_60;
    }
    else
    {
LABEL_53:
      if ( (v7 & 8) != 0 )
      {
        Scaleform::GFx::AS2::ArrayObject::MakeDeepCopy(v23, fn->Env->StringContext.pContext->pHeap);
        v31 = v23;
      }
      else
      {
        Scaleform::GFx::AS2::ArrayObject::ShallowCopyFrom(v4, v23);
        Scaleform::GFx::AS2::ArrayObject::DetachAll(v23);
        v31 = v4;
      }
      Scaleform::GFx::AS2::Value::SetAsObject(fn->Result, v31);
      v28 = v39.Func.Flags;
      if ( (v39.Func.Flags & 2) != 0 )
        goto LABEL_60;
      v29 = v39.Func.Function;
      if ( !v39.Func.Function )
        goto LABEL_60;
      v30 = v39.Func.Function->RefCount;
      if ( (v30 & 0x3FFFFFF) == 0 )
        goto LABEL_60;
    }
    v39.Func.Function->RefCount = v30 - 1;
    Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v29);
LABEL_60:
    v39.Func.Function = 0i64;
    if ( (v28 & 1) == 0 )
    {
      v32 = v39.Func.pLocalFrame;
      if ( v39.Func.pLocalFrame )
      {
        v33 = v39.Func.pLocalFrame->RefCount;
        if ( (v33 & 0x3FFFFFF) != 0 )
        {
          v39.Func.pLocalFrame->RefCount = v33 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v32);
        }
      }
    }
    v39.Func.pLocalFrame = 0i64;
  }
  if ( v23 )
  {
    v34 = v23->RefCount;
    if ( (v34 & 0x3FFFFFF) != 0 )
    {
      v23->RefCount = v34 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v23);
    }
  }
  v35 = v38.Flags;
  if ( (v38.Flags & 2) == 0 )
  {
    if ( v5 )
    {
      v36 = v5->RefCount;
      if ( (v36 & 0x3FFFFFF) != 0 )
      {
        v5->RefCount = v36 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v5);
      }
    }
  }
  v38.Function = 0i64;
  if ( (v35 & 1) == 0 && v6 )
  {
    v37 = v6->RefCount;
    if ( (v37 & 0x3FFFFFF) != 0 )
    {
      v6->RefCount = v37 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v6);
    }
  }
  v38.pLocalFrame = 0i64;
}

// File Line: 745
// RVA: 0x6A5C00
void __fastcall Scaleform::GFx::AS2::ArrayObject::ArraySortOn(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rcx
  __int64 v3; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v4; // rax
  __int64 v5; // rbx
  Scaleform::GFx::AS2::Object *v6; // r12
  __int64 v7; // rdi
  Scaleform::GFx::ASMovieRootBase *pObject; // rax
  __int64 v9; // rax
  Scaleform::GFx::AS2::Value *v10; // rbx
  Scaleform::GFx::ASStringNode *pMovieImpl; // r13
  unsigned int FirstArgBottomIndex; // r10d
  Scaleform::GFx::AS2::Environment *Env; // r9
  Scaleform::GFx::AS2::Value *v14; // r8
  Scaleform::GFx::AS2::Object *v15; // rax
  Scaleform::GFx::AS2::Object *v16; // r15
  signed int i; // esi
  Scaleform::GFx::AS2::Value *v18; // rcx
  Scaleform::GFx::ASString *v19; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v21; // zf
  Scaleform::GFx::ASStringNode **v22; // rdx
  Scaleform::GFx::AS2::Value *v23; // rax
  Scaleform::GFx::ASString *v24; // rax
  Scaleform::GFx::ASStringNode *v25; // rcx
  int v26; // esi
  unsigned __int64 Size; // rcx
  unsigned __int64 v28; // rbx
  unsigned __int64 v29; // r8
  int *v30; // rdx
  unsigned int v31; // r8d
  Scaleform::GFx::AS2::Environment *v32; // r10
  Scaleform::GFx::AS2::Value *v33; // r9
  Scaleform::GFx::AS2::Object *v34; // rax
  Scaleform::GFx::AS2::Object *v35; // r13
  signed int v36; // esi
  __int64 v37; // r12
  __int64 v38; // r15
  Scaleform::GFx::AS2::Value *v39; // rcx
  int *Data; // rbx
  unsigned int v41; // r8d
  Scaleform::GFx::AS2::Environment *v42; // r10
  Scaleform::GFx::AS2::Value *v43; // r9
  int v44; // eax
  int v45; // r8d
  __int64 v46; // rdx
  Scaleform::GFx::AS2::Object *v47; // rax
  Scaleform::GFx::AS2::ArrayObject *v48; // r15
  unsigned __int64 pPrev; // rbx
  unsigned __int64 v50; // r8
  $8D47FECC8062B48992CD8F53EA11C4BE *v51; // rdx
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,2>,Scaleform::ArrayDefaultPolicy> *v52; // rcx
  unsigned __int64 j; // rdx
  unsigned __int64 v54; // rcx
  unsigned int v55; // ebx
  char v56; // al
  int v57; // ebx
  __int64 v58; // r12
  Scaleform::GFx::AS2::Value *v59; // rbx
  Scaleform::GFx::AS2::Object *v60; // rdx
  unsigned __int64 v61; // r12
  unsigned __int64 v62; // r8
  unsigned __int64 v63; // rdx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v64; // r8
  unsigned int RefCount; // eax
  Scaleform::GFx::ASStringNode *v66; // rcx
  __int64 v67; // rsi
  __int64 k; // rbx
  Scaleform::GFx::ASStringNode *v69; // rcx
  Scaleform::ArrayDataBase<int,Scaleform::AllocatorGH<int,2>,Scaleform::ArrayDefaultPolicy> pheapAddr; // [rsp+30h] [rbp-D0h] BYREF
  Scaleform::Array<Scaleform::GFx::AS2::ArraySortFunctor,2,Scaleform::ArrayDefaultPolicy> *p_FunctorArray; // [rsp+48h] [rbp-B8h]
  Scaleform::GFx::AS2::ObjectInterface **p_This; // [rsp+50h] [rbp-B0h]
  Scaleform::ArrayData<Scaleform::GFx::AS2::ArraySortFunctor,Scaleform::AllocatorGH<Scaleform::GFx::AS2::ArraySortFunctor,2>,Scaleform::ArrayDefaultPolicy> *p_a; // [rsp+58h] [rbp-A8h]
  Scaleform::GFx::AS2::ObjectInterface *This; // [rsp+60h] [rbp-A0h] BYREF
  Scaleform::ArrayCC<Scaleform::GFx::ASString,323,Scaleform::ArrayDefaultPolicy> *FieldArray; // [rsp+68h] [rbp-98h]
  Scaleform::GFx::AS2::Environment *v76; // [rsp+70h] [rbp-90h]
  Scaleform::Log *LogPtr; // [rsp+78h] [rbp-88h]
  Scaleform::ArrayData<Scaleform::GFx::AS2::ArraySortFunctor,Scaleform::AllocatorGH<Scaleform::GFx::AS2::ArraySortFunctor,2>,Scaleform::ArrayDefaultPolicy> a; // [rsp+80h] [rbp-80h] BYREF
  Scaleform::GFx::AS2::ArraySortOnFunctor v79; // [rsp+98h] [rbp-68h] BYREF
  Scaleform::Alg::ArrayAdaptor<Scaleform::GFx::AS2::Value *> v80; // [rsp+D0h] [rbp-30h] BYREF
  Scaleform::GFx::AS2::ArraySortOnFunctor v81; // [rsp+E0h] [rbp-20h] BYREF
  __int64 v82; // [rsp+118h] [rbp+18h]
  __int64 v83; // [rsp+120h] [rbp+20h]
  char v84; // [rsp+180h] [rbp+80h]
  Scaleform::GFx::ASStringNode *v85; // [rsp+188h] [rbp+88h]
  Scaleform::GFx::AS2::Object *obj; // [rsp+190h] [rbp+90h]
  Scaleform::GFx::ASString result; // [rsp+198h] [rbp+98h] BYREF

  v83 = -2i64;
  ThisPtr = fn->ThisPtr;
  if ( !ThisPtr
    || (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(ThisPtr) != 7 )
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      fn->Env,
      "Error: Null or invalid this is used for a method of %s class.\n",
      "Array");
    return;
  }
  v4 = fn->ThisPtr;
  v5 = 0i64;
  v6 = (Scaleform::GFx::AS2::Object *)&v4[-2];
  if ( !v4 )
    v6 = 0i64;
  obj = v6;
  v7 = ((__int64 (__fastcall *)(__int64, __int64))fn->Env->StringContext.pContext->pHeap->vfptr->Alloc)(v3, 32i64);
  if ( v7 )
  {
    pObject = fn->Env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject;
    result.pNode = (Scaleform::GFx::ASStringNode *)v7;
    *(_QWORD *)v7 = 0i64;
    *(_QWORD *)(v7 + 8) = 0i64;
    *(_QWORD *)(v7 + 16) = 0i64;
    v9 = *(_QWORD *)&pObject[7].AVMVersion;
    *(_QWORD *)(v7 + 24) = v9;
    ++*(_DWORD *)(v9 + 24);
  }
  else
  {
    v7 = 0i64;
  }
  v82 = v7;
  memset(&pheapAddr, 0, sizeof(pheapAddr));
  v84 = 0;
  if ( fn->NArgs )
  {
    BYTE4(v6[1].pProto.pObject) = 0;
    pMovieImpl = (Scaleform::GFx::ASStringNode *)fn->Env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[17].pMovieImpl;
    v85 = pMovieImpl;
    ++pMovieImpl->RefCount;
    if ( fn->NArgs >= 1 )
    {
      FirstArgBottomIndex = fn->FirstArgBottomIndex;
      Env = fn->Env;
      v14 = 0i64;
      if ( FirstArgBottomIndex <= 32 * ((unsigned int)Env->Stack.Pages.Data.Size - 1)
                                + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
        v14 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
      v15 = Scaleform::GFx::AS2::Value::ToObject(v14, fn->Env);
      v16 = v15;
      if ( v15
        && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v15->Scaleform::GFx::AS2::ObjectInterface::vfptr->gap8[8])(&v15->Scaleform::GFx::AS2::ObjectInterface) == 7 )
      {
        for ( i = 0; i < (signed int)v16[1].RootIndex; ++v5 )
        {
          v18 = (Scaleform::GFx::AS2::Value *)(&v16[1].pRCC->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::$8D47FECC8062B48992CD8F53EA11C4BE::vfptr)[v5];
          if ( v18 )
          {
            v19 = Scaleform::GFx::AS2::Value::ToString(v18, &result, fn->Env, -1);
            Scaleform::ArrayBase<Scaleform::ArrayDataCC<Scaleform::GFx::ASString,Scaleform::AllocatorLH<Scaleform::GFx::ASString,323>,Scaleform::ArrayDefaultPolicy>>::PushBack(
              (Scaleform::ArrayBase<Scaleform::ArrayDataCC<Scaleform::GFx::ASString,Scaleform::AllocatorLH<Scaleform::GFx::ASString,323>,Scaleform::ArrayDefaultPolicy> > *)v7,
              v19);
            pNode = result.pNode;
            v21 = result.pNode->RefCount-- == 1;
            if ( v21 )
              Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
          }
          else
          {
            Scaleform::ArrayDataBase<Scaleform::GFx::ASString,Scaleform::AllocatorLH<Scaleform::GFx::ASString,323>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
              (Scaleform::ArrayDataBase<Scaleform::GFx::ASString,Scaleform::AllocatorLH<Scaleform::GFx::ASString,323>,Scaleform::ArrayDefaultPolicy> *)v7,
              (const void *)v7,
              *(_QWORD *)(v7 + 8) + 1i64);
            v22 = (Scaleform::GFx::ASStringNode **)(*(_QWORD *)v7 + 8 * (*(_QWORD *)(v7 + 8) - 1i64));
            p_a = (Scaleform::ArrayData<Scaleform::GFx::AS2::ArraySortFunctor,Scaleform::AllocatorGH<Scaleform::GFx::AS2::ArraySortFunctor,2>,Scaleform::ArrayDefaultPolicy> *)v22;
            p_This = (Scaleform::GFx::AS2::ObjectInterface **)v22;
            if ( v22 )
            {
              *v22 = pMovieImpl;
              ++pMovieImpl->RefCount;
            }
          }
          ++i;
        }
      }
      else
      {
        v23 = Scaleform::GFx::AS2::FnCall::Arg(fn, 0);
        v24 = Scaleform::GFx::AS2::Value::ToString(v23, &result, fn->Env, -1);
        Scaleform::ArrayBase<Scaleform::ArrayDataCC<Scaleform::GFx::ASString,Scaleform::AllocatorLH<Scaleform::GFx::ASString,323>,Scaleform::ArrayDefaultPolicy>>::PushBack(
          (Scaleform::ArrayBase<Scaleform::ArrayDataCC<Scaleform::GFx::ASString,Scaleform::AllocatorLH<Scaleform::GFx::ASString,323>,Scaleform::ArrayDefaultPolicy> > *)v7,
          v24);
        v25 = result.pNode;
        v21 = result.pNode->RefCount-- == 1;
        if ( v21 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v25);
      }
    }
    v26 = 0;
    if ( *(int *)(v7 + 8) > 0 )
    {
      Size = pheapAddr.Size;
      do
      {
        v28 = Size + 1;
        if ( Size + 1 >= Size )
        {
          if ( v28 > pheapAddr.Policy.Capacity )
          {
            v29 = v28 + (v28 >> 2);
            goto LABEL_32;
          }
        }
        else if ( v28 < pheapAddr.Policy.Capacity >> 1 )
        {
          v29 = Size + 1;
LABEL_32:
          Scaleform::ArrayDataBase<Scaleform::GFx::`anonymous namespace::Range,Scaleform::AllocatorGH<Scaleform::GFx::`anonymous namespace::Range,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            &pheapAddr,
            &pheapAddr,
            v29);
        }
        Size = v28;
        pheapAddr.Size = v28;
        v30 = &pheapAddr.Data[v28 - 1];
        if ( v30 )
        {
          *v30 = 0;
          Size = pheapAddr.Size;
        }
        ++v26;
      }
      while ( v26 < *(_DWORD *)(v7 + 8) );
    }
    if ( fn->NArgs >= 2 )
    {
      v31 = fn->FirstArgBottomIndex - 1;
      v32 = fn->Env;
      v33 = 0i64;
      if ( v31 <= 32 * ((unsigned int)v32->Stack.Pages.Data.Size - 1)
                + (unsigned int)(v32->Stack.pCurrent - v32->Stack.pPageStart) )
        v33 = &v32->Stack.Pages.Data.Data[v31 >> 5]->Values[v31 & 0x1F];
      v34 = Scaleform::GFx::AS2::Value::ToObject(v33, fn->Env);
      v35 = v34;
      if ( v34
        && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v34->Scaleform::GFx::AS2::ObjectInterface::vfptr->gap8[8])(&v34->Scaleform::GFx::AS2::ObjectInterface) == 7 )
      {
        v36 = 0;
        if ( (int)v35[1].RootIndex > 0 )
        {
          v37 = 0i64;
          v38 = 0i64;
          do
          {
            if ( v36 >= *(_DWORD *)(v7 + 8) )
              break;
            v39 = (Scaleform::GFx::AS2::Value *)(&v35[1].pRCC->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::$8D47FECC8062B48992CD8F53EA11C4BE::vfptr)[v38];
            if ( v39 )
            {
              Data = pheapAddr.Data;
              Data[v37] = Scaleform::GFx::AS2::Value::ToInt32(v39, fn->Env);
            }
            ++v36;
            ++v38;
            ++v37;
          }
          while ( v36 < (signed int)v35[1].RootIndex );
          v6 = obj;
        }
      }
      else
      {
        v41 = fn->FirstArgBottomIndex - 1;
        v42 = fn->Env;
        v43 = 0i64;
        if ( v41 <= 32 * ((unsigned int)v42->Stack.Pages.Data.Size - 1)
                  + (unsigned int)(v42->Stack.pCurrent - v42->Stack.pPageStart) )
          v43 = &v42->Stack.Pages.Data.Data[v41 >> 5]->Values[v41 & 0x1F];
        v44 = Scaleform::GFx::AS2::Value::ToInt32(v43, fn->Env);
        v84 = v44;
        v45 = 0;
        if ( *(int *)(v7 + 8) > 0 )
        {
          v46 = 0i64;
          do
          {
            pheapAddr.Data[v46] = v44;
            ++v45;
            ++v46;
          }
          while ( v45 < *(_DWORD *)(v7 + 8) );
        }
      }
      pMovieImpl = v85;
    }
    v47 = Scaleform::GFx::AS2::Environment::OperatorNew(
            fn->Env,
            fn->Env->StringContext.pContext->pGlobal.pObject,
            (Scaleform::GFx::ASString *)&fn->Env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[8].RefCount,
            0,
            -1);
    v48 = (Scaleform::GFx::AS2::ArrayObject *)v47;
    result.pNode = (Scaleform::GFx::ASStringNode *)v47;
    if ( !v47 )
    {
LABEL_96:
      if ( v48 )
      {
        RefCount = v48->RefCount;
        if ( (RefCount & 0x3FFFFFF) != 0 )
        {
          v48->RefCount = RefCount - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v48);
        }
      }
      v21 = pMovieImpl->RefCount-- == 1;
      if ( v21 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pMovieImpl);
      goto LABEL_101;
    }
    pPrev = (unsigned __int64)v6[1].pPrev;
    if ( (Scaleform::GFx::AS2::RefCountBaseGC<323> *)pPrev >= v47[1].pPrev )
    {
      if ( pPrev <= *(_QWORD *)&v47[1].RefCount )
        goto LABEL_63;
      v50 = pPrev + (pPrev >> 2);
      v51 = &v47[1].8;
      v52 = (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,2>,Scaleform::ArrayDefaultPolicy> *)&v47[1].8;
    }
    else
    {
      if ( pPrev >= *(_QWORD *)&v47[1].RefCount >> 1 )
        goto LABEL_63;
      v50 = (unsigned __int64)v6[1].pPrev;
      v51 = &v47[1].8;
      v52 = (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,2>,Scaleform::ArrayDefaultPolicy> *)&v47[1].8;
    }
    Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      v52,
      v51,
      v50);
LABEL_63:
    v48->Elements.Data.Size = pPrev;
    for ( j = 0i64; j < pPrev; ++j )
      v48->Elements.Data.Data[j] = (Scaleform::GFx::AS2::Value *)(&v6[1].pRCC->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::$8D47FECC8062B48992CD8F53EA11C4BE::vfptr)[j];
    Scaleform::GFx::AS2::ArraySortOnFunctor::ArraySortOnFunctor(
      &v79,
      &v48->Scaleform::GFx::AS2::ObjectInterface,
      (Scaleform::ArrayCC<Scaleform::GFx::ASString,323,Scaleform::ArrayDefaultPolicy> *)v7,
      (Scaleform::Array<int,2,Scaleform::ArrayDefaultPolicy> *)&pheapAddr,
      fn->Env,
      (Scaleform::Log *)v6[1].Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr);
    v54 = v48->Elements.Data.Size;
    if ( v54 )
    {
      v80.Data = v48->Elements.Data.Data;
      v55 = v54;
      v80.Size = (unsigned int)v54;
      p_This = &This;
      This = v79.This;
      FieldArray = v79.FieldArray;
      v76 = v79.Env;
      LogPtr = v79.LogPtr;
      p_a = &a;
      Scaleform::ArrayData<Scaleform::GFx::AS2::ArraySortFunctor,Scaleform::AllocatorGH<Scaleform::GFx::AS2::ArraySortFunctor,2>,Scaleform::ArrayDefaultPolicy>::ArrayData<Scaleform::GFx::AS2::ArraySortFunctor,Scaleform::AllocatorGH<Scaleform::GFx::AS2::ArraySortFunctor,2>,Scaleform::ArrayDefaultPolicy>(
        &a,
        &v79.FunctorArray.Data);
      p_This = &This;
      p_a = (Scaleform::ArrayData<Scaleform::GFx::AS2::ArraySortFunctor,Scaleform::AllocatorGH<Scaleform::GFx::AS2::ArraySortFunctor,2>,Scaleform::ArrayDefaultPolicy> *)&v81;
      v81.This = This;
      v81.FieldArray = FieldArray;
      v81.Env = v76;
      v81.LogPtr = LogPtr;
      p_FunctorArray = &v81.FunctorArray;
      Scaleform::ArrayData<Scaleform::GFx::AS2::ArraySortFunctor,Scaleform::AllocatorGH<Scaleform::GFx::AS2::ArraySortFunctor,2>,Scaleform::ArrayDefaultPolicy>::ArrayData<Scaleform::GFx::AS2::ArraySortFunctor,Scaleform::AllocatorGH<Scaleform::GFx::AS2::ArraySortFunctor,2>,Scaleform::ArrayDefaultPolicy>(
        &v81.FunctorArray.Data,
        &a);
      Scaleform::Alg::QuickSortSlicedSafe<Scaleform::Alg::ArrayAdaptor<Scaleform::GFx::AS2::Value *>,Scaleform::GFx::AS2::ArraySortOnFunctor>(
        &v80,
        0i64,
        v55,
        &v81);
      p_FunctorArray = (Scaleform::Array<Scaleform::GFx::AS2::ArraySortFunctor,2,Scaleform::ArrayDefaultPolicy> *)&a;
      Scaleform::ConstructorMov<Scaleform::GFx::AS2::ArraySortFunctor>::DestructArray(a.Data, a.Size);
      if ( a.Data )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
    }
    v56 = v84;
    if ( (v84 & 4) != 0 )
    {
      v57 = 1;
      if ( SLODWORD(v48->Elements.Data.Size) > 1 )
      {
        v58 = 1i64;
        while ( Scaleform::GFx::AS2::ArraySortOnFunctor::Compare(
                  &v79,
                  v48->Elements.Data.Data[v58 - 1],
                  v48->Elements.Data.Data[v58]) )
        {
          ++v57;
          ++v58;
          if ( v57 >= SLODWORD(v48->Elements.Data.Size) )
          {
            v56 = v84;
            goto LABEL_77;
          }
        }
        v59 = fn->Result;
        if ( v59->T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(fn->Result);
        v59->T.Type = 4;
        v59->NV.Int32Value = 0;
        goto LABEL_94;
      }
    }
LABEL_77:
    if ( (v56 & 8) != 0 )
    {
      Scaleform::GFx::AS2::ArrayObject::MakeDeepCopy(v48, fn->Env->StringContext.pContext->pHeap);
      v60 = v48;
LABEL_93:
      Scaleform::GFx::AS2::Value::SetAsObject(fn->Result, v60);
LABEL_94:
      Scaleform::ConstructorMov<Scaleform::GFx::AS2::ArraySortFunctor>::DestructArray(
        v79.FunctorArray.Data.Data,
        v79.FunctorArray.Data.Size);
      if ( v79.FunctorArray.Data.Data )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      goto LABEL_96;
    }
    v61 = v48->Elements.Data.Size;
    if ( (Scaleform::GFx::AS2::RefCountBaseGC<323> *)v61 >= obj[1].pPrev )
    {
      if ( v61 > *(_QWORD *)&obj[1].RefCount )
      {
        v62 = v61 + (v61 >> 2);
        goto LABEL_84;
      }
    }
    else if ( v61 < *(_QWORD *)&obj[1].RefCount >> 1 )
    {
      v62 = v48->Elements.Data.Size;
LABEL_84:
      Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,2>,Scaleform::ArrayDefaultPolicy> *)&obj[1].8,
        &obj[1].8,
        v62);
    }
    obj[1].pPrev = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)v61;
    v63 = 0i64;
    v64 = obj[1].pPrev;
    if ( v64 )
    {
      do
      {
        (&obj[1].pRCC->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::$8D47FECC8062B48992CD8F53EA11C4BE::vfptr)[v63] = (Scaleform::RefCountImplCoreVtbl *)v48->Elements.Data.Data[v63];
        ++v63;
      }
      while ( v63 < (unsigned __int64)v64 );
    }
    if ( v48->Elements.Data.Size && (v48->Elements.Data.Policy.Capacity & 0xFFFFFFFFFFFFFFFEui64) != 0 )
    {
      if ( v48->Elements.Data.Data )
      {
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        v48->Elements.Data.Data = 0i64;
      }
      v48->Elements.Data.Policy.Capacity = 0i64;
    }
    v48->Elements.Data.Size = 0i64;
    v60 = obj;
    goto LABEL_93;
  }
  v10 = fn->Result;
  Scaleform::GFx::AS2::Value::DropRefs(v10);
  v10->T.Type = 0;
LABEL_101:
  if ( pheapAddr.Data )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  if ( v7 )
  {
    v66 = *(Scaleform::GFx::ASStringNode **)(v7 + 24);
    v21 = v66->RefCount-- == 1;
    if ( v21 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v66);
    v67 = *(_QWORD *)(v7 + 8);
    for ( k = *(_QWORD *)v7 + 8 * (v67 - 1); v67; --v67 )
    {
      v69 = *(Scaleform::GFx::ASStringNode **)k;
      v21 = (*(_DWORD *)(*(_QWORD *)k + 24i64))-- == 1;
      if ( v21 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v69);
      k -= 8i64;
    }
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, *(void **)v7);
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, (void *)v7);
  }
}QWORD *)(v7 + 8);
    for ( k = *(_QWORD *)v7 + 8 * (v67 - 1); v67; --v67 )
    {
      v69 = *(Scaleform::GFx::ASStringNode **)k;
      v21 = (*(_DWORD *)(*(_QWORD *)k + 24i64))-- == 1;
      if ( v21 )
        Scaleform::GFx::AS

// File Line: 879
// RVA: 0x6A64B0
void __fastcall Scaleform::GFx::AS2::ArrayObject::ArraySplice(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // r14
  Scaleform::GFx::AS2::ObjectInterface *v4; // r14
  Scaleform::GFx::AS2::Value *Result; // rbx
  unsigned int FirstArgBottomIndex; // r10d
  Scaleform::GFx::AS2::Environment *Env; // rdx
  Scaleform::GFx::AS2::Value *v8; // r9
  Scaleform::GFx::AS2::ObjectInterfaceVtbl *v9; // rsi
  Scaleform::GFx::AS2::ObjectInterfaceVtbl *vfptr; // r12
  int v11; // r12d
  unsigned int v12; // r9d
  Scaleform::GFx::AS2::Environment *v13; // rdx
  Scaleform::GFx::AS2::Value *v14; // r10
  int v15; // eax
  Scaleform::GFx::AS2::ObjectInterfaceVtbl *v16; // rcx
  Scaleform::GFx::AS2::ArrayObject *v17; // rbp
  __int64 v18; // r15
  __int64 v19; // rdi
  Scaleform::GFx::AS2::Value *v20; // rdx
  int NArgs; // r8d
  int v22; // edi
  int v23; // esi
  unsigned int v24; // edx
  Scaleform::GFx::AS2::Environment *v25; // r9
  Scaleform::GFx::AS2::Value *v26; // r8
  unsigned int RefCount; // eax

  ThisPtr = fn->ThisPtr;
  if ( ThisPtr
    && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(ThisPtr) == 7 )
  {
    v3 = fn->ThisPtr;
    if ( v3 )
      v4 = v3 - 2;
    else
      v4 = 0i64;
    if ( fn->NArgs )
    {
      BYTE4(v4[8].pProto.pObject) = 0;
      FirstArgBottomIndex = fn->FirstArgBottomIndex;
      Env = fn->Env;
      v8 = 0i64;
      if ( FirstArgBottomIndex <= 32 * ((unsigned int)Env->Stack.Pages.Data.Size - 1)
                                + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
        v8 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
      LODWORD(v9) = Scaleform::GFx::AS2::Value::ToInt32(v8, Env);
      if ( (int)v9 < 0 )
      {
        LODWORD(v9) = LODWORD(v4[7].vfptr) + (_DWORD)v9;
        if ( (int)v9 < 0 )
          LODWORD(v9) = 0;
      }
      vfptr = v4[7].vfptr;
      if ( (int)v9 > (int)vfptr )
        v9 = v4[7].vfptr;
      v11 = (_DWORD)vfptr - (_DWORD)v9;
      if ( fn->NArgs >= 2 )
      {
        v12 = fn->FirstArgBottomIndex - 1;
        v13 = fn->Env;
        v14 = 0i64;
        if ( v12 <= 32 * ((unsigned int)v13->Stack.Pages.Data.Size - 1)
                  + (unsigned int)(v13->Stack.pCurrent - v13->Stack.pPageStart) )
          v14 = &v13->Stack.Pages.Data.Data[v12 >> 5]->Values[v12 & 0x1F];
        v15 = Scaleform::GFx::AS2::Value::ToInt32(v14, v13);
        if ( v15 < 0 )
          v15 = 0;
        v11 = v15;
        v16 = v4[7].vfptr;
        if ( (int)v9 + v15 >= (int)v16 )
          v11 = (_DWORD)v16 - (_DWORD)v9;
      }
      v17 = (Scaleform::GFx::AS2::ArrayObject *)Scaleform::GFx::AS2::Environment::OperatorNew(
                                                  fn->Env,
                                                  fn->Env->StringContext.pContext->pGlobal.pObject,
                                                  (Scaleform::GFx::ASString *)&fn->Env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[8].RefCount,
                                                  0,
                                                  -1);
      if ( v17 )
      {
        v18 = v11;
        if ( v11 > 0 )
        {
          v19 = 8i64 * (int)v9;
          do
          {
            v20 = *(Scaleform::GFx::AS2::Value **)((char *)&v4[6].pProto.pObject->vfptr + v19);
            if ( v20 )
              Scaleform::GFx::AS2::ArrayObject::PushBack(v17, v20);
            else
              Scaleform::GFx::AS2::ArrayObject::PushBack(v17);
            v19 += 8i64;
            --v18;
          }
          while ( v18 );
        }
        Scaleform::GFx::AS2::Value::SetAsObject(fn->Result, v17);
        if ( v11 )
          Scaleform::GFx::AS2::ArrayObject::RemoveElements((Scaleform::GFx::AS2::ArrayObject *)v4, (int)v9, v11);
        NArgs = fn->NArgs;
        if ( NArgs >= 3 )
        {
          Scaleform::GFx::AS2::ArrayObject::InsertEmpty((Scaleform::GFx::AS2::ArrayObject *)v4, (int)v9, NArgs - 2);
          v22 = 2;
          if ( fn->NArgs > 2 )
          {
            v23 = (_DWORD)v9 - 2;
            do
            {
              v24 = fn->FirstArgBottomIndex - v22;
              v25 = fn->Env;
              v26 = 0i64;
              if ( v24 <= 32 * ((unsigned int)v25->Stack.Pages.Data.Size - 1)
                        + (unsigned int)(v25->Stack.pCurrent - v25->Stack.pPageStart) )
                v26 = &v25->Stack.Pages.Data.Data[v24 >> 5]->Values[v24 & 0x1F];
              Scaleform::GFx::AS2::ArrayObject::SetElement((Scaleform::GFx::AS2::ArrayObject *)v4, v23 + v22++, v26);
            }
            while ( v22 < fn->NArgs );
          }
        }
      }
      if ( v17 )
      {
        RefCount = v17->RefCount;
        if ( (RefCount & 0x3FFFFFF) != 0 )
        {
          v17->RefCount = RefCount - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v17);
        }
      }
    }
    else
    {
      Result = fn->Result;
      Scaleform::GFx::AS2::Value::DropRefs(Result);
      Result->T.Type = 0;
    }
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      fn->Env,
      "Error: Null or invalid this is used for a method of %s class.\n",
      "Array");
  }
}

// File Line: 943
// RVA: 0x6A6770
void __fastcall Scaleform::GFx::AS2::ArrayObject::ArrayToString(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rbx
  Scaleform::GFx::ASMovieRootBase *pObject; // rsi
  Scaleform::GFx::AS2::Value *v5; // rdi
  Scaleform::GFx::ASStringNode *v6; // rax
  char *pData; // r8
  Scaleform::GFx::ASString *v8; // rsi
  Scaleform::GFx::AS2::Value *Result; // rdi
  Scaleform::GFx::ASStringNode *pNode; // rax
  Scaleform::GFx::ASStringNode *v11; // rcx
  Scaleform::StringBuffer pbuffer; // [rsp+28h] [rbp-40h] BYREF
  Scaleform::GFx::ASString messageType; // [rsp+70h] [rbp+8h] BYREF
  Scaleform::GFx::AS2::ObjectInterface *v15; // [rsp+78h] [rbp+10h]

  ThisPtr = fn->ThisPtr;
  if ( ThisPtr
    && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(ThisPtr) == 7 )
  {
    v3 = fn->ThisPtr;
    if ( v3 )
      v3 -= 2;
    v15 = v3;
    if ( (int)++LODWORD(v3[8].pProto.pObject) < 255 )
    {
      Scaleform::StringBuffer::StringBuffer(&pbuffer, fn->Env->StringContext.pContext->pHeap);
      Scaleform::GFx::AS2::ArrayObject::JoinToString((Scaleform::GFx::AS2::ArrayObject *)v3, fn->Env, &pbuffer, ",");
      pData = &customCaption;
      if ( pbuffer.pData )
        pData = pbuffer.pData;
      v8 = Scaleform::GFx::AS2::Environment::CreateString(fn->Env, &messageType, pData, pbuffer.Size);
      Result = fn->Result;
      if ( Result->T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(Result);
      Result->T.Type = 5;
      pNode = v8->pNode;
      Result->NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)v8->pNode;
      ++pNode->RefCount;
      v11 = messageType.pNode;
      if ( messageType.pNode->RefCount-- == 1 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v11);
      Scaleform::ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayDataBase<int,Scaleform::AllocatorGH<int,2>,Scaleform::ArrayDefaultPolicy> *)&pbuffer);
    }
    else
    {
      LODWORD(messageType.pNode) = 212992;
      Scaleform::Log::LogMessageById(
        (Scaleform::GFx::LogState *)v3[6].vfptr,
        (Scaleform::LogMessageId)&messageType,
        "256 levels of recursion is reached\n");
      pObject = fn->Env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject;
      v5 = fn->Result;
      if ( v5->T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(v5);
      v5->T.Type = 5;
      v6 = *(Scaleform::GFx::ASStringNode **)&pObject[7].AVMVersion;
      v5->V.pStringNode = v6;
      ++v6->RefCount;
    }
    --LODWORD(v3[8].pProto.pObject);
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      fn->Env,
      "Error: Null or invalid this is used for a method of %s class.\n",
      "Array");
  }
}

// File Line: 963
// RVA: 0x6A68F0
void __fastcall Scaleform::GFx::AS2::ArrayObject::ArrayUnshift(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rcx
  Scaleform::GFx::AS2::ArrayObject *v3; // rsi
  int NArgs; // r8d
  int i; // ebx
  Scaleform::GFx::AS2::Environment *Env; // rdx
  Scaleform::GFx::AS2::Value *v7; // r8
  unsigned int v8; // r9d
  Scaleform::GFx::AS2::Value *Result; // rbx
  unsigned __int64 Size; // rsi

  ThisPtr = fn->ThisPtr;
  if ( ThisPtr
    && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(ThisPtr) == 7 )
  {
    v3 = (Scaleform::GFx::AS2::ArrayObject *)fn->ThisPtr;
    if ( v3 )
      v3 = (Scaleform::GFx::AS2::ArrayObject *)((char *)v3 - 32);
    v3->LengthValueOverriden = 0;
    NArgs = fn->NArgs;
    if ( NArgs > 0 )
    {
      Scaleform::GFx::AS2::ArrayObject::InsertEmpty(v3, 0, NArgs);
      for ( i = 0; i < fn->NArgs; ++i )
      {
        Env = fn->Env;
        v7 = 0i64;
        v8 = fn->FirstArgBottomIndex - i;
        if ( v8 <= 32 * (LODWORD(Env->Stack.Pages.Data.Size) - 1)
                 + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
          v7 = &Env->Stack.Pages.Data.Data[(unsigned __int64)v8 >> 5]->Values[v8 & 0x1F];
        Scaleform::GFx::AS2::ArrayObject::SetElement(v3, i, v7);
      }
    }
    Result = fn->Result;
    Size = v3->Elements.Data.Size;
    if ( Result->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(fn->Result);
    Result->NV.Int32Value = Size;
    Result->T.Type = 4;
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      fn->Env,
      "Error: Null or invalid this is used for a method of %s class.\n",
      "Array");
  }
}

// File Line: 990
// RVA: 0x6A69F0
// attributes: thunk
void __fastcall Scaleform::GFx::AS2::ArrayObject::ArrayValueOf(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ArrayObject::ArrayToString(fn);
}

// File Line: 1060
// RVA: 0x7152C0
char __fastcall Scaleform::GFx::AS2::ArrayObject::SetMember(
        Scaleform::GFx::AS2::ArrayObject *this,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS2::Value *val,
        Scaleform::GFx::AS2::PropFlags *flags)
{
  Scaleform::GFx::ASMovieRootBase *pObject; // rdi
  Scaleform::GFx::ASStringNode *pNode; // r9
  bool v11; // zf
  int v12; // eax
  const char *pData; // rcx
  char v14; // al
  int v15; // eax
  __int64 v16; // rcx
  __int64 v17; // rdi
  __int64 v18; // rdi
  _BYTE *v19; // rax
  _BYTE *v20; // rcx

  pObject = penv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject;
  if ( penv->StringContext.SWFVersion <= 6u )
  {
    if ( !name->pNode->pLower )
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(name->pNode);
    pNode = name->pNode;
    v11 = *(Scaleform::GFx::ASStringNode **)(*(_QWORD *)&pObject[38].AVMVersion + 16i64) == name->pNode->pLower;
  }
  else
  {
    pNode = name->pNode;
    v11 = *(Scaleform::GFx::ASStringNode **)&pObject[38].AVMVersion == name->pNode;
  }
  if ( v11 )
  {
    v12 = Scaleform::GFx::AS2::Value::ToInt32(val, 0i64);
    if ( v12 < 0 )
      v12 = 0;
    Scaleform::GFx::AS2::ArrayObject::Resize((Scaleform::GFx::AS2::ArrayObject *)((char *)this - 32), v12);
    BYTE4(this->Elements.Data.Data) = 1;
    return Scaleform::GFx::AS2::Object::SetMember(this, penv, name, val, flags);
  }
  pData = pNode->pData;
  v14 = *pNode->pData;
  if ( v14 )
  {
    while ( (unsigned __int8)(v14 - 48) <= 9u )
    {
      v14 = *++pData;
      if ( !*pData )
        goto LABEL_15;
    }
    if ( *pData )
      return Scaleform::GFx::AS2::Object::SetMember(this, penv, name, val, flags);
  }
LABEL_15:
  v15 = atol(pNode->pData);
  v17 = v15;
  if ( v15 < 0 )
    return Scaleform::GFx::AS2::Object::SetMember(this, penv, name, val, flags);
  BYTE4(this->Elements.Data.Data) = 0;
  if ( v15 >= SLODWORD(this->pWatchpoints) )
    Scaleform::GFx::AS2::ArrayObject::Resize((Scaleform::GFx::AS2::ArrayObject *)((char *)this - 32), v15 + 1);
  v18 = 8 * v17;
  if ( !*(_QWORD *)(v18 + *(_QWORD *)&this->ResolveHandler.Flags) )
  {
    v19 = (_BYTE *)((__int64 (__fastcall *)(__int64, __int64))penv->StringContext.pContext->pHeap->vfptr->Alloc)(
                     v16,
                     32i64);
    v20 = v19;
    if ( v19 )
      *v19 = 0;
    else
      v20 = 0i64;
    *(_QWORD *)(v18 + *(_QWORD *)&this->ResolveHandler.Flags) = v20;
  }
  Scaleform::GFx::AS2::Value::operator=(
    *(Scaleform::GFx::AS2::Value **)(*(_QWORD *)&this->ResolveHandler.Flags + v18),
    val);
  return 1;
}

// File Line: 1094
// RVA: 0x6F3740
bool __fastcall Scaleform::GFx::AS2::ArrayObject::GetMemberRaw(
        Scaleform::GFx::AS2::ArrayObject *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS2::Value *val)
{
  const char *pData; // rcx
  char v9; // al
  const char *v10; // r10
  int v11; // eax
  Scaleform::GFx::AS2::Value *v12; // rdx
  bool result; // al
  Scaleform::GFx::ASMovieRootBase *pObject; // rsi
  bool v15; // zf
  Scaleform::GFx::ASStringHash_GC<Scaleform::GFx::AS2::Object::Watchpoint> *pWatchpoints; // rsi

  pData = name->pNode->pData;
  v9 = *pData;
  v10 = pData;
  if ( !*pData )
    goto LABEL_6;
  while ( (unsigned __int8)(v9 - 48) <= 9u )
  {
    v9 = *++v10;
    if ( !v9 )
      goto LABEL_6;
  }
  if ( !*v10 )
  {
LABEL_6:
    v11 = atol(pData);
    if ( v11 >= 0 )
    {
      if ( v11 < SLODWORD(this->pWatchpoints)
        && (v12 = *(Scaleform::GFx::AS2::Value **)(*(_QWORD *)&this->ResolveHandler.Flags + 8i64 * v11)) != 0i64 )
      {
        Scaleform::GFx::AS2::Value::operator=(val, v12);
        return 1;
      }
      else
      {
        Scaleform::GFx::AS2::Value::DropRefs(val);
        val->T.Type = 0;
        return 1;
      }
    }
  }
  pObject = psc->pContext->pMovieRoot->pASMovieRoot.pObject;
  if ( psc->SWFVersion <= 6u )
  {
    if ( !name->pNode->pLower )
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(name->pNode);
    v15 = *(Scaleform::GFx::ASStringNode **)(*(_QWORD *)&pObject[38].AVMVersion + 16i64) == name->pNode->pLower;
  }
  else
  {
    v15 = *(Scaleform::GFx::ASStringNode **)&pObject[38].AVMVersion == name->pNode;
  }
  if ( !v15 || BYTE4(this->Elements.Data.Data) && !this->pWatchpoints )
    return Scaleform::GFx::AS2::Object::GetMemberRaw(this, psc, name, val);
  pWatchpoints = this->pWatchpoints;
  if ( val->T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(val);
  val->T.Type = 4;
  val->NV.Int32Value = (int)pWatchpoints;
  result = 1;
  BYTE4(this->Elements.Data.Data) = 0;
  return result;
}

// File Line: 1126
// RVA: 0x6E1EC0
bool __fastcall Scaleform::GFx::AS2::ArrayObject::DeleteMember(
        Scaleform::GFx::AS2::ArrayObject *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        Scaleform::GFx::ASString *name)
{
  const char *pData; // rcx
  char v7; // al
  int v8; // eax
  Scaleform::GFx::AS2::Value val; // [rsp+28h] [rbp-30h] BYREF

  if ( !name->pNode->Size || !isdigit(*name->pNode->pData) )
    return Scaleform::GFx::AS2::Object::DeleteMember(this, psc, name);
  pData = name->pNode->pData;
  v7 = *pData;
  if ( *pData )
  {
    while ( (unsigned __int8)(v7 - 48) <= 9u )
    {
      v7 = *++pData;
      if ( !*pData )
        goto LABEL_8;
    }
    if ( *pData )
      return 0;
  }
LABEL_8:
  v8 = atol(name->pNode->pData);
  if ( v8 < 0 )
    return 0;
  val.T.Type = 0;
  Scaleform::GFx::AS2::ArrayObject::SetElement((Scaleform::GFx::AS2::ArrayObject *)((char *)this - 32), v8, &val);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  return 1;
}

// File Line: 1144
// RVA: 0x723E50
void __fastcall Scaleform::GFx::AS2::ArrayObject::VisitMembers(
        Scaleform::GFx::AS2::ArrayObject *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        Scaleform::GFx::AS2::ObjectInterface::MemberVisitor *pvisitor,
        unsigned int visitFlags,
        Scaleform::GFx::AS2::ObjectInterface *instance)
{
  Scaleform::GFx::ASStringHash_GC<Scaleform::GFx::AS2::Object::Watchpoint> *pWatchpoints; // r14
  unsigned __int64 v9; // rbp
  unsigned __int64 i; // rbx
  Scaleform::GFx::AS2::Value *v11; // r8
  Scaleform::GFx::ASString *v12; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::StringDataPtr result; // [rsp+38h] [rbp-90h] BYREF
  Scaleform::LongFormatter v16; // [rsp+50h] [rbp-78h] BYREF
  Scaleform::GFx::ASString v17; // [rsp+D0h] [rbp+8h] BYREF

  Scaleform::GFx::AS2::Object::VisitMembers(this, psc, pvisitor, visitFlags, instance);
  pWatchpoints = this->pWatchpoints;
  v9 = (unsigned __int64)pWatchpoints;
  if ( (unsigned __int64)pWatchpoints > 7 )
    v9 = 8i64;
  for ( i = 0i64; i < v9; ++i )
  {
    v11 = *(Scaleform::GFx::AS2::Value **)(*(_QWORD *)&this->ResolveHandler.Flags + 8 * i);
    if ( v11 )
      pvisitor->vfptr->Visit(
        pvisitor,
        (Scaleform::GFx::ASString *)(&psc->pContext->pMovieRoot->pASMovieRoot.pObject[36].pMovieImpl + (int)i),
        v11,
        0);
  }
  for ( ; i < (unsigned __int64)pWatchpoints; ++i )
  {
    if ( *(_QWORD *)(*(_QWORD *)&this->ResolveHandler.Flags + 8 * i) )
    {
      Scaleform::LongFormatter::LongFormatter(&v16, i);
      Scaleform::LongFormatter::Convert(&v16);
      Scaleform::LongFormatter::GetResult(&v16, &result);
      v12 = Scaleform::GFx::AS2::ASStringContext::CreateString(psc, &v17, result.pStr, result.Size);
      pvisitor->vfptr->Visit(
        pvisitor,
        v12,
        *(Scaleform::GFx::AS2::Value **)(*(_QWORD *)&this->ResolveHandler.Flags + 8 * i),
        0);
      pNode = v17.pNode;
      if ( v17.pNode->RefCount-- == 1 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      v16.Scaleform::String::InitStruct::vfptr = (Scaleform::String::InitStructVtbl *)&Scaleform::String::InitStruct::`vftable;
      Scaleform::Formatter::~Formatter(&v16);
    }
  }
}

// File Line: 1177
// RVA: 0x6F68F0
char *__fastcall Scaleform::GFx::AS2::ArrayObject::GetTextValue(
        Scaleform::GFx::AS2::ArrayObject *this,
        Scaleform::GFx::AS2::Environment *pEnv)
{
  unsigned __int64 *p_Size; // rbx
  char *v5; // rdi
  Scaleform::StringBuffer pbuffer; // [rsp+28h] [rbp-40h] BYREF
  int v8; // [rsp+70h] [rbp+8h] BYREF
  unsigned __int64 *v9; // [rsp+80h] [rbp+18h]

  p_Size = &this[-1].Elements.Data.Size;
  v9 = &this[-1].Elements.Data.Size;
  if ( (int)++*((_DWORD *)&this[-1].Elements.Data.Size + 34) < 255 )
  {
    Scaleform::StringBuffer::StringBuffer(&pbuffer, pEnv->StringContext.pContext->pHeap);
    Scaleform::GFx::AS2::ArrayObject::JoinToString((Scaleform::GFx::AS2::ArrayObject *)p_Size, pEnv, &pbuffer, ",");
    Scaleform::String::operator=((Scaleform::String *)&this->LogPtr, &pbuffer);
    v5 = (char *)(((unsigned __int64)this->LogPtr & 0xFFFFFFFFFFFFFFFCui64) + 12);
    Scaleform::ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayDataBase<int,Scaleform::AllocatorGH<int,2>,Scaleform::ArrayDefaultPolicy> *)&pbuffer);
  }
  else
  {
    v8 = 212992;
    Scaleform::Log::LogMessageById(
      (Scaleform::GFx::LogState *)p_Size[12],
      (Scaleform::LogMessageId)&v8,
      "256 levels of recursion is reached\n");
    v5 = &customCaption;
  }
  --*((_DWORD *)p_Size + 34);
  return v5;
}

// File Line: 1194
// RVA: 0x6FCFC0
void __fastcall Scaleform::GFx::AS2::ArrayObject::InitArray(
        Scaleform::GFx::AS2::ArrayObject *this,
        Scaleform::GFx::AS2::FnCall *fn)
{
  int v3; // ebx
  Scaleform::GFx::AS2::ObjectInterface *v4; // r14
  Scaleform::GFx::ASString *v5; // r11
  unsigned int v6; // r8d
  Scaleform::GFx::AS2::Environment *Env; // r10
  __int64 v8; // r9
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS2::Value v11; // [rsp+38h] [rbp-40h] BYREF
  char v12; // [rsp+88h] [rbp+10h] BYREF
  Scaleform::GFx::ASString result; // [rsp+90h] [rbp+18h] BYREF

  v11.T.Type = 0;
  v3 = 0;
  if ( fn->NArgs > 0 )
  {
    v4 = &this->Scaleform::GFx::AS2::ObjectInterface;
    do
    {
      v11.T.Type = 4;
      v11.NV.Int32Value = v3;
      v5 = Scaleform::GFx::AS2::Value::ToString(&v11, &result, fn->Env, -1);
      v12 = 0;
      v6 = fn->FirstArgBottomIndex - v3;
      Env = fn->Env;
      v8 = 0i64;
      if ( v6 <= 32 * ((unsigned int)Env->Stack.Pages.Data.Size - 1)
               + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
        v8 = (__int64)&Env->Stack.Pages.Data.Data[v6 >> 5]->Values[v6 & 0x1F];
      v4->vfptr->SetMember(v4, Env, v5, (Scaleform::GFx::AS2::Value *)v8, (Scaleform::GFx::AS2::PropFlags *)&v12);
      pNode = result.pNode;
      if ( result.pNode->RefCount-- == 1 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      ++v3;
    }
    while ( v3 < fn->NArgs );
  }
}

// File Line: 1205
// RVA: 0x6FB350
bool __fastcall Scaleform::GFx::AS2::ArrayObject::HasMember(
        Scaleform::GFx::AS2::ArrayObject *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        Scaleform::GFx::ASString *name,
        bool inclPrototypes)
{
  const char *pData; // rcx
  char v9; // al
  const char *v10; // r10
  int v11; // eax
  char *v12; // rdx
  char v13; // al
  bool result; // al

  pData = name->pNode->pData;
  v9 = *pData;
  v10 = pData;
  if ( *pData )
  {
    while ( (unsigned __int8)(v9 - 48) <= 9u )
    {
      v9 = *++v10;
      if ( !v9 )
        goto LABEL_6;
    }
    if ( *v10 )
      return Scaleform::GFx::AS2::Object::HasMember(this, psc, name, inclPrototypes);
  }
LABEL_6:
  v11 = atol(pData);
  if ( v11 < 0 )
    return Scaleform::GFx::AS2::Object::HasMember(this, psc, name, inclPrototypes);
  result = 0;
  if ( v11 < SLODWORD(this->pWatchpoints) )
  {
    v12 = *(char **)(*(_QWORD *)&this->ResolveHandler.Flags + 8i64 * v11);
    if ( v12 )
    {
      v13 = *v12;
      if ( *v12 )
      {
        if ( v13 != 10 && v13 != 1 )
          return 1;
      }
    }
  }
  return result;
}

// File Line: 1226
// RVA: 0x6C6EC0
void __fastcall Scaleform::GFx::AS2::ArrayCtorFunction::ArrayCtorFunction(
        Scaleform::GFx::AS2::ArrayCtorFunction *this,
        Scaleform::GFx::AS2::ASStringContext *psc)
{
  __int64 v4; // rbx
  __int64 v5; // rax
  Scaleform::GFx::AS2::NameNumber *v6; // rdx
  int Number; // ecx
  Scaleform::GFx::ASString *v8; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS2::Value v11; // [rsp+38h] [rbp-50h] BYREF
  char v12; // [rsp+A0h] [rbp+18h] BYREF
  Scaleform::GFx::ASString result; // [rsp+A8h] [rbp+20h] BYREF

  Scaleform::GFx::AS2::CFunctionObject::CFunctionObject(this, psc, Scaleform::GFx::AS2::ArrayCtorFunction::GlobalCtor);
  this->Scaleform::GFx::AS2::CFunctionObject::Scaleform::GFx::AS2::FunctionObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::ArrayCtorFunction::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
  this->Scaleform::GFx::AS2::CFunctionObject::Scaleform::GFx::AS2::FunctionObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::ArrayCtorFunction::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  v4 = 0i64;
  if ( GASArrayConstTable[0].Name )
  {
    v5 = 0i64;
    v6 = GASArrayConstTable;
    do
    {
      v12 = 3;
      Number = GASArrayConstTable[v5].Number;
      v11.T.Type = 4;
      v11.NV.Int32Value = Number;
      v8 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &result, v6->Name);
      this->Scaleform::GFx::AS2::CFunctionObject::Scaleform::GFx::AS2::FunctionObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr->SetMemberRaw(
        &this->Scaleform::GFx::AS2::ObjectInterface,
        psc,
        v8,
        &v11,
        (Scaleform::GFx::AS2::PropFlags *)&v12);
      pNode = result.pNode;
      if ( result.pNode->RefCount-- == 1 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
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
  Scaleform::GFx::AS2::Value *v2; // rsi
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v4; // rbx
  Scaleform::GFx::AS2::ArrayObject *v5; // rbx
  Scaleform::GFx::AS2::ArrayObject *v6; // rax
  Scaleform::GFx::AS2::ArrayObject *v7; // rax
  int NArgs; // eax
  unsigned int FirstArgBottomIndex; // r10d
  Scaleform::GFx::AS2::Environment *Env; // r9
  Scaleform::GFx::AS2::Value *v11; // r8
  int v12; // eax
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::Value v14; // [rsp+38h] [rbp-40h] BYREF
  Scaleform::MemoryHeap *pHeap; // [rsp+80h] [rbp+8h] BYREF
  Scaleform::GFx::AS2::ArrayObject *v16; // [rsp+88h] [rbp+10h]
  Scaleform::GFx::AS2::ArrayObject *v17; // [rsp+90h] [rbp+18h]

  v2 = 0i64;
  v16 = 0i64;
  ThisPtr = fn->ThisPtr;
  if ( ThisPtr
    && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(ThisPtr) == 7
    && !fn->ThisPtr->vfptr->IsBuiltinPrototype(fn->ThisPtr) )
  {
    v4 = fn->ThisPtr;
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
  else
  {
    pHeap = fn->Env->StringContext.pContext->pHeap;
    v6 = (Scaleform::GFx::AS2::ArrayObject *)pHeap->vfptr->Alloc((Scaleform::MemoryHeap *)ThisPtr, 144ui64, 0i64);
    v17 = v6;
    if ( v6 )
    {
      Scaleform::GFx::AS2::ArrayObject::ArrayObject(v6, fn->Env);
      v5 = v7;
    }
    else
    {
      v5 = 0i64;
    }
  }
  v16 = v5;
  LOBYTE(pHeap) = 1;
  v14.T.Type = 4;
  v14.NV.Int32Value = 0;
  v5->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr->SetMember(
    &v5->Scaleform::GFx::AS2::ObjectInterface,
    fn->Env,
    (Scaleform::GFx::ASString *)&fn->Env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[38].AVMVersion,
    &v14,
    (Scaleform::GFx::AS2::PropFlags *)&pHeap);
  if ( v14.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v14);
  NArgs = fn->NArgs;
  if ( NArgs )
  {
    if ( NArgs != 1 )
      goto LABEL_21;
    FirstArgBottomIndex = fn->FirstArgBottomIndex;
    Env = fn->Env;
    v11 = 0i64;
    if ( FirstArgBottomIndex <= 32 * ((unsigned int)Env->Stack.Pages.Data.Size - 1)
                              + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
      v11 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
    if ( (unsigned __int8)(v11->T.Type - 3) <= 1u )
    {
      if ( FirstArgBottomIndex <= 32 * ((unsigned int)Env->Stack.Pages.Data.Size - 1)
                                + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
        v2 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
      v12 = Scaleform::GFx::AS2::Value::ToInt32(v2, fn->Env);
      Scaleform::GFx::AS2::ArrayObject::Resize(v5, v12);
    }
    else
    {
LABEL_21:
      Scaleform::GFx::AS2::ArrayObject::InitArray(v5, fn);
    }
  }
  Scaleform::GFx::AS2::Value::SetAsObject(fn->Result, v5);
  RefCount = v5->RefCount;
  if ( (RefCount & 0x3FFFFFF) != 0 )
  {
    v5->RefCount = RefCount - 1;
    Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v5);
  }
}

// File Line: 1264
// RVA: 0x6E19D0
void __fastcall Scaleform::GFx::AS2::ArrayCtorFunction::DeclareArray(Scaleform::MemoryHeap *fn)
{
  Scaleform::GFx::AS2::ArrayObject *v2; // rax
  Scaleform::GFx::AS2::ArrayObject *v3; // rax
  Scaleform::GFx::AS2::ArrayObject *v4; // rbx
  char Flags; // al
  Scaleform::GFx::AS2::FunctionObject *Function; // rcx
  unsigned int RefCount; // edx
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // rcx
  unsigned int v9; // eax
  unsigned int v10; // eax
  Scaleform::GFx::AS2::FunctionRef result; // [rsp+38h] [rbp-40h] BYREF
  Scaleform::GFx::AS2::Value v12; // [rsp+50h] [rbp-28h] BYREF
  Scaleform::MemoryHeap *v13; // [rsp+80h] [rbp+8h] BYREF
  Scaleform::GFx::AS2::ArrayObject *v14; // [rsp+88h] [rbp+10h]

  v13 = *(Scaleform::MemoryHeap **)(*((_QWORD *)fn->pAutoRelease + 29) + 48i64);
  v2 = (Scaleform::GFx::AS2::ArrayObject *)v13->vfptr->Alloc(fn, 144ui64, 0i64);
  v14 = v2;
  if ( v2 )
  {
    Scaleform::GFx::AS2::ArrayObject::ArrayObject(v2, (Scaleform::GFx::AS2::Environment *)fn->pAutoRelease);
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
  v4->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr->SetMember(
    &v4->Scaleform::GFx::AS2::ObjectInterface,
    (Scaleform::GFx::AS2::Environment *)fn->pAutoRelease,
    (Scaleform::GFx::ASString *)(*(_QWORD *)(*(_QWORD *)(*((_QWORD *)fn->pAutoRelease + 29) + 40i64) + 24i64) + 1552i64),
    &v12,
    (Scaleform::GFx::AS2::PropFlags *)&v13);
  if ( v12.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v12);
  Scaleform::GFx::AS2::Environment::GetConstructor(
    (Scaleform::GFx::AS2::Environment *)fn->pAutoRelease,
    &result,
    ASBuiltin_Array);
  Scaleform::GFx::AS2::ObjectInterface::Set_constructor(
    &v4->Scaleform::GFx::AS2::ObjectInterface,
    (Scaleform::GFx::AS2::ASStringContext *)((char *)fn->pAutoRelease + 232),
    &result);
  if ( fn->Info.Desc.Flags )
    Scaleform::GFx::AS2::ArrayObject::InitArray(v4, (Scaleform::GFx::AS2::FnCall *)fn);
  Scaleform::GFx::AS2::Value::SetAsObject((Scaleform::GFx::AS2::Value *)fn->pPrev, v4);
  Flags = result.Flags;
  if ( (result.Flags & 2) == 0 )
  {
    Function = result.Function;
    if ( result.Function )
    {
      RefCount = result.Function->RefCount;
      if ( (RefCount & 0x3FFFFFF) != 0 )
      {
        result.Function->RefCount = RefCount - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(Function);
        Flags = result.Flags;
      }
    }
  }
  result.Function = 0i64;
  if ( (Flags & 1) == 0 )
  {
    pLocalFrame = result.pLocalFrame;
    if ( result.pLocalFrame )
    {
      v9 = result.pLocalFrame->RefCount;
      if ( (v9 & 0x3FFFFFF) != 0 )
      {
        result.pLocalFrame->RefCount = v9 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pLocalFrame);
      }
    }
  }
  result.pLocalFrame = 0i64;
  v10 = v4->RefCount;
  if ( (v10 & 0x3FFFFFF) != 0 )
  {
    v4->RefCount = v10 - 1;
    Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v4);
  }
}

// File Line: 1286
// RVA: 0x6E02B0
void __fastcall Scaleform::GFx::AS2::ArrayCtorFunction::CreateNewObject(
        Scaleform::GFx::AS2::ArrayCtorFunction *this,
        Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::ArrayObject *v3; // rax

  v3 = (Scaleform::GFx::AS2::ArrayObject *)penv->StringContext.pContext->pHeap->vfptr->Alloc(this, 144i64, 0i64);
  if ( v3 )
    Scaleform::GFx::AS2::ArrayObject::ArrayObject(v3, penv);
}

// File Line: 1291
// RVA: 0x70C0C0
Scaleform::GFx::AS2::FunctionRef *__fastcall Scaleform::GFx::AS2::ArrayCtorFunction::Register(
        Scaleform::GFx::AS2::FunctionRef *result,
        Scaleform::GFx::AS2::GlobalContext *pgc)
{
  Scaleform::GFx::AS2::ArrayCtorFunction *v4; // rax
  __int64 v5; // rcx
  Scaleform::GFx::AS2::FunctionObject *v6; // rax
  __int64 v7; // rdi
  Scaleform::GFx::AS2::Object *Prototype; // rbx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v9; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::Object *pObject; // rbx
  Scaleform::GFx::ASStringNode *Function; // rax
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // rdx
  int v14; // eax
  Scaleform::GFx::AS2::ASStringContext psc; // [rsp+48h] [rbp-38h] BYREF
  Scaleform::GFx::AS2::Value v17; // [rsp+58h] [rbp-28h] BYREF
  Scaleform::Ptr<Scaleform::GFx::AS2::Object> objproto; // [rsp+C8h] [rbp+48h] BYREF
  __int64 flags; // [rsp+D0h] [rbp+50h] BYREF
  void *pHeap; // [rsp+D8h] [rbp+58h]

  psc.pContext = pgc;
  psc.SWFVersion = 8;
  objproto.pObject = (Scaleform::GFx::AS2::Object *)pgc->pHeap;
  v4 = (Scaleform::GFx::AS2::ArrayCtorFunction *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::FunctionRef *, __int64, _QWORD))objproto.pObject->vfptr[3].Finalize_GC)(
                                                   result,
                                                   104i64,
                                                   0i64);
  flags = (__int64)v4;
  if ( v4 )
    Scaleform::GFx::AS2::ArrayCtorFunction::ArrayCtorFunction(v4, &psc);
  else
    v6 = 0i64;
  result->Flags = 0;
  result->Function = v6;
  result->pLocalFrame = 0i64;
  pHeap = pgc->pHeap;
  v7 = (*(__int64 (__fastcall **)(__int64, __int64, _QWORD))(*(_QWORD *)pHeap + 80i64))(v5, 208i64, 0i64);
  if ( v7 )
  {
    Prototype = Scaleform::GFx::AS2::GlobalContext::GetPrototype(pgc, ASBuiltin_Object);
    Scaleform::GFx::AS2::Object::Object((Scaleform::GFx::AS2::Object *)v7, &psc);
    *(_QWORD *)v7 = &Scaleform::GFx::AS2::ArrayObject::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
    *(_QWORD *)(v7 + 32) = &Scaleform::GFx::AS2::ArrayObject::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
    *(_QWORD *)(v7 + 96) = 0i64;
    objproto.pObject = (Scaleform::GFx::AS2::Object *)(v7 + 104);
    flags = v7 + 104;
    *(_QWORD *)(v7 + 104) = 0i64;
    *(_QWORD *)(v7 + 112) = 0i64;
    *(_QWORD *)(v7 + 120) = 0i64;
    Scaleform::StringLH::StringLH((Scaleform::StringLH *)(v7 + 128));
    *(_DWORD *)(v7 + 136) = 0;
    *(_BYTE *)(v7 + 140) = 0;
    if ( !*(_QWORD *)(v7 + 40) )
    {
      LOBYTE(objproto.pObject) = 3;
      v17.T.Type = 10;
      (*(void (__fastcall **)(__int64, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::MovieImpl **, Scaleform::GFx::AS2::Value *, Scaleform::Ptr<Scaleform::GFx::AS2::Object> *))(*(_QWORD *)(v7 + 32) + 80i64))(
        v7 + 32,
        &psc,
        &psc.pContext->pMovieRoot->pASMovieRoot.pObject[23].pMovieImpl,
        &v17,
        &objproto);
      if ( v17.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v17);
    }
    if ( Prototype )
      Prototype->RefCount = (Prototype->RefCount + 1) & 0x8FFFFFFF;
    v9 = *(Scaleform::GFx::AS2::RefCountBaseGC<323> **)(v7 + 40);
    if ( v9 )
    {
      RefCount = v9->RefCount;
      if ( (RefCount & 0x3FFFFFF) != 0 )
      {
        v9->RefCount = RefCount - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v9);
      }
    }
    *(_QWORD *)(v7 + 40) = Prototype;
    flags = v7 + 144;
    *(_QWORD *)(v7 + 144) = &Scaleform::GFx::AS2::GASPrototypeBase::`vftable;
    *(_BYTE *)(v7 + 168) = 0;
    *(_QWORD *)(v7 + 152) = 0i64;
    *(_QWORD *)(v7 + 160) = 0i64;
    *(_BYTE *)(v7 + 192) = 0;
    *(_QWORD *)(v7 + 176) = 0i64;
    *(_QWORD *)(v7 + 184) = 0i64;
    *(_QWORD *)(v7 + 200) = 0i64;
    *(_QWORD *)v7 = &Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::ArrayObject,Scaleform::GFx::AS2::Environment>::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
    *(_QWORD *)(v7 + 32) = &Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::ArrayObject,Scaleform::GFx::AS2::Environment>::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
    *(_QWORD *)(v7 + 144) = &Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::ArrayObject,Scaleform::GFx::AS2::Environment>::`vftable;
    Scaleform::GFx::AS2::GASPrototypeBase::Init(
      (Scaleform::GFx::AS2::GASPrototypeBase *)(v7 + 144),
      (Scaleform::GFx::AS2::Object *)v7,
      &psc,
      result);
    *(_QWORD *)v7 = &Scaleform::GFx::AS2::ArrayProto::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
    *(_QWORD *)(v7 + 32) = &Scaleform::GFx::AS2::ArrayProto::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
    *(_QWORD *)(v7 + 144) = &Scaleform::GFx::AS2::ArrayProto::`vftable;
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
  pHeap = &objproto;
  if ( v7 )
    *(_DWORD *)(v7 + 24) = (*(_DWORD *)(v7 + 24) + 1) & 0x8FFFFFFF;
  objproto.pObject = (Scaleform::GFx::AS2::Object *)v7;
  Scaleform::GFx::AS2::GlobalContext::SetPrototype(
    pgc,
    ASBuiltin_Array,
    (Scaleform::Ptr<Scaleform::GFx::AS2::Object>)&objproto);
  pObject = pgc->pGlobal.pObject;
  v17.T.Type = 8;
  v17.V.FunctionValue.Flags = 0;
  Function = (Scaleform::GFx::ASStringNode *)result->Function;
  v17.V.pStringNode = Function;
  if ( Function )
  {
    ++Function->RefCount;
    Function->RefCount &= 0x8FFFFFFF;
  }
  v17.V.FunctionValue.pLocalFrame = 0i64;
  pLocalFrame = result->pLocalFrame;
  if ( pLocalFrame )
    Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(&v17.V.FunctionValue, pLocalFrame, result->Flags & 1);
  LOBYTE(objproto.pObject) = 0;
  pObject->Scaleform::GFx::AS2::ObjectInterface::vfptr->SetMemberRaw(
    &pObject->Scaleform::GFx::AS2::ObjectInterface,
    &psc,
    (Scaleform::GFx::ASString *)&pgc->pMovieRoot->pASMovieRoot.pObject[8].RefCount,
    &v17,
    (Scaleform::GFx::AS2::PropFlags *)&objproto);
  if ( v17.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v17);
  if ( v7 )
  {
    v14 = *(_DWORD *)(v7 + 24);
    if ( (v14 & 0x3FFFFFF) != 0 )
    {
      *(_DWORD *)(v7 + 24) = v14 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v7);
    }
  }
  return result;
}

