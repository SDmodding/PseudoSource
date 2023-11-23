// File Line: 237
// RVA: 0x6D1F90
void __fastcall Scaleform::GFx::AS2::ObjectInterface::MemberVisitor::~MemberVisitor(
        Scaleform::GFx::AS2::ObjectInterface::MemberVisitor *this)
{
  this->vfptr = (Scaleform::GFx::AS2::ObjectInterface::MemberVisitorVtbl *)&Scaleform::GFx::AS2::ObjectInterface::MemberVisitor::`vftable;
}

// File Line: 269
// RVA: 0x713490
_BOOL8 __fastcall Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
        Scaleform::GFx::AS2::ObjectInterface *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        const char *pname,
        Scaleform::GFx::AS2::Value *val)
{
  Scaleform::GFx::ASString *v7; // rax
  bool v8; // bl
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::ASString result; // [rsp+30h] [rbp-18h] BYREF
  __int64 v13; // [rsp+38h] [rbp-10h]
  char v14; // [rsp+50h] [rbp+8h] BYREF

  v13 = -2i64;
  v7 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &result, pname);
  v14 = 0;
  v8 = this->vfptr->SetMemberRaw(this, psc, v7, val, (Scaleform::GFx::AS2::PropFlags *)&v14);
  pNode = result.pNode;
  if ( result.pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  return v8;
}

// File Line: 313
// RVA: 0x71E090
void __fastcall Scaleform::GFx::AS2::ObjectInterface::Set__constructor__(
        Scaleform::GFx::AS2::ObjectInterface *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        Scaleform::GFx::AS2::FunctionRef *ctorFunc)
{
  Scaleform::GFx::ASStringNode *Function; // rax
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // rdx
  Scaleform::GFx::AS2::Value v7; // [rsp+38h] [rbp-30h] BYREF
  char v8; // [rsp+70h] [rbp+8h] BYREF

  v8 = 3;
  v7.T.Type = 8;
  v7.V.FunctionValue.Flags = 0;
  Function = (Scaleform::GFx::ASStringNode *)ctorFunc->Function;
  v7.V.pStringNode = Function;
  if ( Function )
  {
    ++Function->RefCount;
    Function->RefCount &= 0x8FFFFFFF;
  }
  v7.V.FunctionValue.pLocalFrame = 0i64;
  pLocalFrame = ctorFunc->pLocalFrame;
  if ( pLocalFrame )
    Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(&v7.V.FunctionValue, pLocalFrame, ctorFunc->Flags & 1);
  this->vfptr->SetMemberRaw(
    this,
    psc,
    (Scaleform::GFx::ASString *)&psc->pContext->pMovieRoot->pASMovieRoot.pObject[23].AVMVersion,
    &v7,
    (Scaleform::GFx::AS2::PropFlags *)&v8);
  if ( v7.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v7);
}

// File Line: 321
// RVA: 0x6F8930
Scaleform::GFx::AS2::FunctionRef *__fastcall Scaleform::GFx::AS2::ObjectInterface::Get__constructor__(
        Scaleform::GFx::AS2::ObjectInterface *this,
        Scaleform::GFx::AS2::FunctionRef *result,
        Scaleform::GFx::AS2::ASStringContext *psc)
{
  Scaleform::GFx::AS2::Value v5; // [rsp+30h] [rbp-28h] BYREF

  v5.T.Type = 0;
  if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::AS2::ObjectInterface *, Scaleform::GFx::AS2::ASStringContext *, char *, Scaleform::GFx::AS2::Value *, _DWORD, __int64))this->vfptr->GetMemberRaw)(
         this,
         psc,
         &psc->pContext->pMovieRoot->pASMovieRoot.pObject[23].AVMVersion,
         &v5,
         0,
         -2i64) )
  {
    Scaleform::GFx::AS2::Value::ToFunction(&v5, result, 0i64);
  }
  else
  {
    result->Flags = 0;
    result->Function = 0i64;
    result->pLocalFrame = 0i64;
  }
  if ( v5.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v5);
  return result;
}

// File Line: 330
// RVA: 0x71E3A0
void __fastcall Scaleform::GFx::AS2::ObjectInterface::Set_constructor(
        Scaleform::GFx::AS2::ObjectInterface *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        Scaleform::GFx::AS2::FunctionRef *ctorFunc)
{
  Scaleform::GFx::ASStringNode *Function; // rax
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // rdx
  Scaleform::GFx::AS2::Value v7; // [rsp+38h] [rbp-30h] BYREF
  char v8; // [rsp+70h] [rbp+8h] BYREF

  v8 = 3;
  v7.T.Type = 8;
  v7.V.FunctionValue.Flags = 0;
  Function = (Scaleform::GFx::ASStringNode *)ctorFunc->Function;
  v7.V.pStringNode = Function;
  if ( Function )
  {
    ++Function->RefCount;
    Function->RefCount &= 0x8FFFFFFF;
  }
  v7.V.FunctionValue.pLocalFrame = 0i64;
  pLocalFrame = ctorFunc->pLocalFrame;
  if ( pLocalFrame )
    Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(&v7.V.FunctionValue, pLocalFrame, ctorFunc->Flags & 1);
  this->vfptr->SetMemberRaw(
    this,
    psc,
    (Scaleform::GFx::ASString *)&psc->pContext->pMovieRoot->pASMovieRoot.pObject[23].pASSupport,
    &v7,
    (Scaleform::GFx::AS2::PropFlags *)&v8);
  if ( v7.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v7);
}

// File Line: 336
// RVA: 0x6F8A40
Scaleform::GFx::AS2::FunctionRef *__fastcall Scaleform::GFx::AS2::ObjectInterface::Get_constructor(
        Scaleform::GFx::AS2::ObjectInterface *this,
        Scaleform::GFx::AS2::FunctionRef *result,
        Scaleform::GFx::AS2::ASStringContext *psc)
{
  Scaleform::GFx::AS2::Value v5; // [rsp+30h] [rbp-28h] BYREF

  v5.T.Type = 0;
  if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::AS2::ObjectInterface *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::Ptr<Scaleform::GFx::ASSupport> *, Scaleform::GFx::AS2::Value *, _DWORD, __int64))this->vfptr->GetMemberRaw)(
         this,
         psc,
         &psc->pContext->pMovieRoot->pASMovieRoot.pObject[23].pASSupport,
         &v5,
         0,
         -2i64) )
  {
    Scaleform::GFx::AS2::Value::ToFunction(&v5, result, 0i64);
  }
  else
  {
    result->Flags = 0;
    result->Function = 0i64;
    result->pLocalFrame = 0i64;
  }
  if ( v5.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v5);
  return result;
}

// File Line: 482
// RVA: 0x71E2F0
void __fastcall Scaleform::GFx::AS2::Object::Set__proto__(
        Scaleform::GFx::AS2::Object *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        Scaleform::GFx::AS2::RefCountCollector<323> *protoObj)
{
  Scaleform::GFx::AS2::RefCountBaseGC<323> *pNext; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::Value v7; // [rsp+38h] [rbp-30h] BYREF
  char v8; // [rsp+70h] [rbp+8h] BYREF

  if ( !this->pRCC )
  {
    v8 = 3;
    v7.T.Type = 10;
    ((void (__fastcall *)(Scaleform::GFx::AS2::Object *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::MovieImpl **, Scaleform::GFx::AS2::Value *, char *))this->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr[3].Finalize_GC)(
      this,
      psc,
      &psc->pContext->pMovieRoot->pASMovieRoot.pObject[23].pMovieImpl,
      &v7,
      &v8);
    if ( v7.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v7);
  }
  if ( protoObj )
    LODWORD(protoObj->Roots.Size) = (LODWORD(protoObj->Roots.Size) + 1) & 0x8FFFFFFF;
  pNext = this->pNext;
  if ( pNext )
  {
    RefCount = pNext->RefCount;
    if ( (RefCount & 0x3FFFFFF) != 0 )
    {
      pNext->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pNext);
    }
  }
  this->pRCC = protoObj;
}

// File Line: 498
// RVA: 0x6E2CD0
bool __fastcall Scaleform::GFx::AS2::Object::DoesImplement(
        Scaleform::GFx::AS2::Object *this,
        Scaleform::GFx::AS2::Environment *__formal,
        Scaleform::GFx::AS2::Object *prototype)
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
  Scaleform::GFx::AS2::Value *p_Caller; // rcx
  Scaleform::GFx::AS2::LocalFrame *pObject; // rcx
  unsigned int RefCount; // eax

  this->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::LocalFrame::`vftable;
  p_Caller = &this->Caller;
  if ( p_Caller->T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(p_Caller);
  if ( this->Callee.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&this->Callee);
  pObject = this->PrevFrame.pObject;
  if ( pObject )
  {
    RefCount = pObject->RefCount;
    if ( (RefCount & 0x3FFFFFF) != 0 )
    {
      pObject->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pObject);
    }
  }
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::~HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>(&this->Variables.mHash);
  this->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::RefCountBaseGC<323>::`vftable;
}

