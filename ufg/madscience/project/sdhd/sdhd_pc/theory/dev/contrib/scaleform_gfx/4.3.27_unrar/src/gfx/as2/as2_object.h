// File Line: 237
// RVA: 0x6D1F90
void __fastcall Scaleform::GFx::AS2::ObjectInterface::MemberVisitor::~MemberVisitor(Scaleform::GFx::AS2::ObjectInterface::MemberVisitor *this)
{
  this->vfptr = (Scaleform::GFx::AS2::ObjectInterface::MemberVisitorVtbl *)&Scaleform::GFx::AS2::ObjectInterface::MemberVisitor::`vftable;
}

// File Line: 269
// RVA: 0x713490
_BOOL8 __fastcall Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(Scaleform::GFx::AS2::ObjectInterface *this, Scaleform::GFx::AS2::ASStringContext *psc, const char *pname, Scaleform::GFx::AS2::Value *val)
{
  Scaleform::GFx::AS2::Value *v4; // rbx
  Scaleform::GFx::AS2::ASStringContext *v5; // rdi
  Scaleform::GFx::AS2::ObjectInterface *v6; // rsi
  Scaleform::GFx::ASString *v7; // rax
  bool v8; // bl
  Scaleform::GFx::ASStringNode *v9; // rcx
  bool v10; // zf
  Scaleform::GFx::ASString result; // [rsp+30h] [rbp-18h]
  __int64 v13; // [rsp+38h] [rbp-10h]
  char v14; // [rsp+50h] [rbp+8h]

  v13 = -2i64;
  v4 = val;
  v5 = psc;
  v6 = this;
  v7 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &result, pname);
  v14 = 0;
  v8 = v6->vfptr->SetMemberRaw(v6, v5, v7, v4, (Scaleform::GFx::AS2::PropFlags *)&v14);
  v9 = result.pNode;
  v10 = result.pNode->RefCount == 1;
  --v9->RefCount;
  if ( v10 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v9);
  return v8;
}

// File Line: 313
// RVA: 0x71E090
void __fastcall Scaleform::GFx::AS2::ObjectInterface::Set__constructor__(Scaleform::GFx::AS2::ObjectInterface *this, Scaleform::GFx::AS2::ASStringContext *psc, Scaleform::GFx::AS2::FunctionRef *ctorFunc)
{
  Scaleform::GFx::AS2::ASStringContext *v3; // rbx
  Scaleform::GFx::AS2::ObjectInterface *v4; // rdi
  Scaleform::GFx::ASStringNode *v5; // rax
  Scaleform::GFx::AS2::LocalFrame *v6; // rdx
  Scaleform::GFx::AS2::Value v7; // [rsp+38h] [rbp-30h]
  char v8; // [rsp+70h] [rbp+8h]

  v3 = psc;
  v4 = this;
  v8 = 3;
  v7.T.Type = 8;
  v7.V.FunctionValue.Flags = 0;
  v5 = (Scaleform::GFx::ASStringNode *)ctorFunc->Function;
  v7.V.pStringNode = v5;
  if ( v5 )
  {
    ++v5->RefCount;
    v5->RefCount &= 0x8FFFFFFF;
  }
  v7.V.FunctionValue.pLocalFrame = 0i64;
  v6 = ctorFunc->pLocalFrame;
  if ( v6 )
    Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(
      (Scaleform::GFx::AS2::FunctionRefBase *)&v7.NV.8,
      v6,
      ctorFunc->Flags & 1);
  v4->vfptr->SetMemberRaw(
    v4,
    v3,
    (Scaleform::GFx::ASString *)&v3->pContext->pMovieRoot->pASMovieRoot.pObject[23].AVMVersion,
    &v7,
    (Scaleform::GFx::AS2::PropFlags *)&v8);
  if ( v7.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v7);
}

// File Line: 321
// RVA: 0x6F8930
Scaleform::GFx::AS2::FunctionRef *__fastcall Scaleform::GFx::AS2::ObjectInterface::Get__constructor__(Scaleform::GFx::AS2::ObjectInterface *this, Scaleform::GFx::AS2::FunctionRef *result, Scaleform::GFx::AS2::ASStringContext *psc)
{
  Scaleform::GFx::AS2::FunctionRef *v3; // rbx
  Scaleform::GFx::AS2::Value v5; // [rsp+30h] [rbp-28h]

  v3 = result;
  v5.T.Type = 0;
  if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::AS2::ObjectInterface *, Scaleform::GFx::AS2::ASStringContext *, char *, Scaleform::GFx::AS2::Value *, _DWORD, signed __int64))this->vfptr->GetMemberRaw)(
         this,
         psc,
         &psc->pContext->pMovieRoot->pASMovieRoot.pObject[23].AVMVersion,
         &v5,
         0,
         -2i64) )
  {
    Scaleform::GFx::AS2::Value::ToFunction(&v5, v3, 0i64);
  }
  else
  {
    v3->Flags = 0;
    v3->Function = 0i64;
    v3->pLocalFrame = 0i64;
  }
  if ( v5.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v5);
  return v3;
}

// File Line: 330
// RVA: 0x71E3A0
void __fastcall Scaleform::GFx::AS2::ObjectInterface::Set_constructor(Scaleform::GFx::AS2::ObjectInterface *this, Scaleform::GFx::AS2::ASStringContext *psc, Scaleform::GFx::AS2::FunctionRef *ctorFunc)
{
  Scaleform::GFx::AS2::ASStringContext *v3; // rbx
  Scaleform::GFx::AS2::ObjectInterface *v4; // rdi
  Scaleform::GFx::ASStringNode *v5; // rax
  Scaleform::GFx::AS2::LocalFrame *v6; // rdx
  Scaleform::GFx::AS2::Value v7; // [rsp+38h] [rbp-30h]
  char v8; // [rsp+70h] [rbp+8h]

  v3 = psc;
  v4 = this;
  v8 = 3;
  v7.T.Type = 8;
  v7.V.FunctionValue.Flags = 0;
  v5 = (Scaleform::GFx::ASStringNode *)ctorFunc->Function;
  v7.V.pStringNode = v5;
  if ( v5 )
  {
    ++v5->RefCount;
    v5->RefCount &= 0x8FFFFFFF;
  }
  v7.V.FunctionValue.pLocalFrame = 0i64;
  v6 = ctorFunc->pLocalFrame;
  if ( v6 )
    Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(
      (Scaleform::GFx::AS2::FunctionRefBase *)&v7.NV.8,
      v6,
      ctorFunc->Flags & 1);
  v4->vfptr->SetMemberRaw(
    v4,
    v3,
    (Scaleform::GFx::ASString *)&v3->pContext->pMovieRoot->pASMovieRoot.pObject[23].pASSupport,
    &v7,
    (Scaleform::GFx::AS2::PropFlags *)&v8);
  if ( v7.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v7);
}

// File Line: 336
// RVA: 0x6F8A40
Scaleform::GFx::AS2::FunctionRef *__fastcall Scaleform::GFx::AS2::ObjectInterface::Get_constructor(Scaleform::GFx::AS2::ObjectInterface *this, Scaleform::GFx::AS2::FunctionRef *result, Scaleform::GFx::AS2::ASStringContext *psc)
{
  Scaleform::GFx::AS2::FunctionRef *v3; // rbx
  Scaleform::GFx::AS2::Value v5; // [rsp+30h] [rbp-28h]

  v3 = result;
  v5.T.Type = 0;
  if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::AS2::ObjectInterface *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::Ptr<Scaleform::GFx::ASSupport> *, Scaleform::GFx::AS2::Value *, _DWORD, signed __int64))this->vfptr->GetMemberRaw)(
         this,
         psc,
         &psc->pContext->pMovieRoot->pASMovieRoot.pObject[23].pASSupport,
         &v5,
         0,
         -2i64) )
  {
    Scaleform::GFx::AS2::Value::ToFunction(&v5, v3, 0i64);
  }
  else
  {
    v3->Flags = 0;
    v3->Function = 0i64;
    v3->pLocalFrame = 0i64;
  }
  if ( v5.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v5);
  return v3;
}

// File Line: 482
// RVA: 0x71E2F0
void __fastcall Scaleform::GFx::AS2::Object::Set__proto__(Scaleform::GFx::AS2::Object *this, Scaleform::GFx::AS2::ASStringContext *psc, Scaleform::GFx::AS2::Object *protoObj)
{
  Scaleform::GFx::AS2::Object *v3; // rbx
  Scaleform::GFx::AS2::Object *v4; // rdi
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v5; // rcx
  unsigned int v6; // eax
  Scaleform::GFx::AS2::Value v7; // [rsp+38h] [rbp-30h]
  char v8; // [rsp+70h] [rbp+8h]

  v3 = protoObj;
  v4 = this;
  if ( !this->pRCC )
  {
    v8 = 3;
    v7.T.Type = 10;
    ((void (__fastcall *)(Scaleform::GFx::AS2::Object *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::MovieImpl **, Scaleform::GFx::AS2::Value *, char *))this->vfptr[3].Finalize_GC)(
      this,
      psc,
      &psc->pContext->pMovieRoot->pASMovieRoot.pObject[23].pMovieImpl,
      &v7,
      &v8);
    if ( v7.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v7);
  }
  if ( v3 )
    v3->RefCount = (v3->RefCount + 1) & 0x8FFFFFFF;
  v5 = v4->pNext;
  if ( v5 )
  {
    v6 = v5->RefCount;
    if ( v6 & 0x3FFFFFF )
    {
      v5->RefCount = v6 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v5);
    }
  }
  v4->pRCC = (Scaleform::GFx::AS2::RefCountCollector<323> *)v3;
}

// File Line: 498
// RVA: 0x6E2CD0
bool __fastcall Scaleform::GFx::AS2::Object::DoesImplement(Scaleform::GFx::AS2::Object *this, Scaleform::GFx::AS2::Environment *__formal, Scaleform::GFx::AS2::Object *prototype)
{
  return this == prototype;
}

// File Line: 612
// RVA: 0x700B40
_BOOL8 __fastcall Scaleform::GFx::AS2::CFunctionObject::IsNull(Scaleform::GFx::AS2::UserDefinedFunctionObject *this)
{
  return this->pContext.pObject == 0i64;
}

// File Line: 679
// RVA: 0x6D1E00
void __fastcall Scaleform::GFx::AS2::LocalFrame::~LocalFrame(Scaleform::GFx::AS2::LocalFrame *this)
{
  Scaleform::GFx::AS2::LocalFrame *v1; // rbx
  Scaleform::GFx::AS2::Value *v2; // rcx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v3; // rcx
  unsigned int v4; // eax

  v1 = this;
  this->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::LocalFrame::`vftable;
  v2 = &this->Caller;
  if ( v2->T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(v2);
  if ( v1->Callee.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v1->Callee);
  v3 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v1->PrevFrame.pObject->vfptr;
  if ( v3 )
  {
    v4 = v3->RefCount;
    if ( v4 & 0x3FFFFFF )
    {
      v3->RefCount = v4 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v3);
    }
  }
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::~HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>((Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)&v1->Variables.mHash.pTable);
  v1->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::RefCountBaseGC<323>::`vftable;
}

