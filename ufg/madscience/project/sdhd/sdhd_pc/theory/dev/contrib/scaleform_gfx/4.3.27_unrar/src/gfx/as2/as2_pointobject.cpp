// File Line: 31
// RVA: 0x1587A30
__int64 Scaleform::GFx::AS2::_dynamic_initializer_for__Point_DefaultParams__()
{
  Point_DefaultParams[1].T.Type = 4;
  Point_DefaultParams[1].NV.Int32Value = 0;
  return atexit((int (__fastcall *)())Scaleform::GFx::AS2::_dynamic_atexit_destructor_for__Point_DefaultParams__);
}

// File Line: 38
// RVA: 0x1587A60
__int64 Scaleform::GFx::AS2::_dynamic_initializer_for__Point_NanParams__()
{
  long double v0; // xmm0_8
  long double v1; // xmm0_8

  v0 = Scaleform::GFx::NumberUtil::NaN();
  Point_NanParams[0].T.Type = 3;
  qword_14243A438 = *(_QWORD *)&v0;
  v1 = Scaleform::GFx::NumberUtil::NaN();
  byte_14243A450 = 3;
  qword_14243A458 = *(_QWORD *)&v1;
  return atexit((int (__fastcall *)())Scaleform::GFx::AS2::_dynamic_atexit_destructor_for__Point_NanParams__);
}

// File Line: 54
// RVA: 0x6ED8E0
void __fastcall Scaleform::GFx::AS2::GFxObject_GetPointProperties(
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::AS2::Object *pobj,
        Scaleform::Render::Point<double> *pt)
{
  long double v6; // xmm6_8
  Scaleform::GFx::AS2::Value ptr; // [rsp+40h] [rbp-58h] BYREF
  Scaleform::GFx::AS2::Value v8; // [rsp+60h] [rbp-38h] BYREF

  `eh vector constructor iterator(&ptr, 0x20ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::AS2::Value::Value);
  ((void (__fastcall *)(Scaleform::GFx::AS2::ObjectInterface *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::Ptr<Scaleform::GFx::ASSupport> *, Scaleform::GFx::AS2::Value *, void (__fastcall *)(Scaleform::GFx::AS2::Value *)))pobj->Scaleform::GFx::AS2::ObjectInterface::vfptr->GetMemberRaw)(
    &pobj->Scaleform::GFx::AS2::ObjectInterface,
    &penv->StringContext,
    &penv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[33].pASSupport,
    &ptr,
    Scaleform::GFx::AS2::Value::~Value);
  pobj->Scaleform::GFx::AS2::ObjectInterface::vfptr->GetMemberRaw(
    &pobj->Scaleform::GFx::AS2::ObjectInterface,
    &penv->StringContext,
    (Scaleform::GFx::ASString *)&penv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[33].AVMVersion,
    &v8);
  v6 = Scaleform::GFx::AS2::Value::ToNumber(&v8, penv);
  pt->x = Scaleform::GFx::AS2::Value::ToNumber(&ptr, penv);
  pt->y = v6;
  `eh vector destructor iterator(&ptr, 0x20ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::AS2::Value::~Value);
}

// File Line: 67
// RVA: 0x6CB4C0
void __fastcall Scaleform::GFx::AS2::PointObject::PointObject(
        Scaleform::GFx::AS2::PointObject *this,
        Scaleform::GFx::AS2::ASStringContext *penv)
{
  Scaleform::GFx::AS2::ASStringContext *v2; // rbx
  Scaleform::GFx::AS2::Object *Prototype; // rax
  char v5; // [rsp+58h] [rbp+10h] BYREF

  v2 = penv;
  Scaleform::GFx::AS2::Object::Object(this, (Scaleform::GFx::AS2::Environment *)penv);
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::PointObject::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::PointObject::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  v2 = (Scaleform::GFx::AS2::ASStringContext *)((char *)v2 + 232);
  Prototype = Scaleform::GFx::AS2::GlobalContext::GetPrototype(v2->pContext, ASBuiltin_Point);
  Scaleform::GFx::AS2::Object::Set__proto__(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    v2,
    Prototype);
  v5 = 0;
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr->SetMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    v2,
    (Scaleform::GFx::ASString *)&v2->pContext->pMovieRoot->pASMovieRoot.pObject[33].pASSupport,
    Point_DefaultParams,
    (Scaleform::GFx::AS2::PropFlags *)&v5);
  v5 = 0;
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr->SetMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    v2,
    (Scaleform::GFx::ASString *)&v2->pContext->pMovieRoot->pASMovieRoot.pObject[33].AVMVersion,
    &Point_DefaultParams[1],
    (Scaleform::GFx::AS2::PropFlags *)&v5);
}

// File Line: 85
// RVA: 0x6F2260
char __fastcall Scaleform::GFx::AS2::PointObject::GetMember(
        Scaleform::GFx::AS2::PointObject *this,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS2::Value *val)
{
  Scaleform::GFx::AS2::ASStringContext *p_StringContext; // rdx
  __m128d v7; // xmm1
  Scaleform::Render::Point<double> pt; // [rsp+28h] [rbp-40h] BYREF
  Scaleform::GFx::AS2::Value v; // [rsp+38h] [rbp-30h] BYREF

  p_StringContext = &penv->StringContext;
  if ( name->pNode != *(Scaleform::GFx::ASStringNode **)&p_StringContext->pContext->pMovieRoot->pASMovieRoot.pObject[38].AVMVersion )
    return ((__int64 (__fastcall *)(Scaleform::GFx::AS2::PointObject *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr[3].~RefCountBaseGC<323>)(
             this,
             p_StringContext,
             name,
             val);
  Scaleform::GFx::AS2::PointObject::GetProperties((Scaleform::GFx::AS2::PointObject *)((char *)this - 32), penv, &pt);
  v7 = (__m128d)*(unsigned __int64 *)&pt.x;
  v7.m128d_f64[0] = v7.m128d_f64[0] * v7.m128d_f64[0] + pt.y * pt.y;
  v.T.Type = 3;
  v.V.pStringNode = (Scaleform::GFx::ASStringNode *)*(_OWORD *)&_mm_sqrt_pd(v7);
  Scaleform::GFx::AS2::Value::operator=(val, &v);
  if ( v.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v);
  return 1;
}

// File Line: 116
// RVA: 0x6F4A10
void __fastcall Scaleform::GFx::AS2::PointObject::GetProperties(
        Scaleform::GFx::AS2::PointObject *this,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::Render::Point<double> *pt)
{
  long double v6; // xmm6_8
  Scaleform::GFx::AS2::Value ptr; // [rsp+40h] [rbp-58h] BYREF
  Scaleform::GFx::AS2::Value v8; // [rsp+60h] [rbp-38h] BYREF

  `eh vector constructor iterator(&ptr, 0x20ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::AS2::Value::Value);
  ((void (__fastcall *)(Scaleform::GFx::AS2::ObjectInterface *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::Ptr<Scaleform::GFx::ASSupport> *, Scaleform::GFx::AS2::Value *, void (__fastcall *)(Scaleform::GFx::AS2::Value *)))this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr->GetMemberRaw)(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    &penv->StringContext,
    &penv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[33].pASSupport,
    &ptr,
    Scaleform::GFx::AS2::Value::~Value);
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr->GetMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    &penv->StringContext,
    (Scaleform::GFx::ASString *)&penv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[33].AVMVersion,
    &v8);
  v6 = Scaleform::GFx::AS2::Value::ToNumber(&v8, penv);
  pt->x = Scaleform::GFx::AS2::Value::ToNumber(&ptr, penv);
  pt->y = v6;
  `eh vector destructor iterator(&ptr, 0x20ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::AS2::Value::~Value);
}

// File Line: 135
// RVA: 0x71AA60
void __fastcall Scaleform::GFx::AS2::PointObject::SetProperties(
        Scaleform::GFx::AS2::PointObject *this,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::Render::Point<double> *pt)
{
  Scaleform::GFx::AS2::ASStringContext *p_StringContext; // rbx
  long double x; // xmm0_8
  Scaleform::GFx::AS2::ObjectInterface *v6; // rdi
  long double y; // xmm0_8
  Scaleform::GFx::AS2::Value v8; // [rsp+38h] [rbp-30h] BYREF
  char v9; // [rsp+70h] [rbp+8h] BYREF

  p_StringContext = &penv->StringContext;
  x = pt->x;
  v8.T.Type = 3;
  v8.NV.NumberValue = x;
  v9 = 0;
  v6 = &this->Scaleform::GFx::AS2::ObjectInterface;
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr->SetMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    &penv->StringContext,
    (Scaleform::GFx::ASString *)&penv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[33].pASSupport,
    &v8,
    (Scaleform::GFx::AS2::PropFlags *)&v9);
  if ( v8.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v8);
  y = pt->y;
  v8.T.Type = 3;
  v8.NV.NumberValue = y;
  v9 = 0;
  v6->vfptr->SetMemberRaw(
    v6,
    p_StringContext,
    (Scaleform::GFx::ASString *)&p_StringContext->pContext->pMovieRoot->pASMovieRoot.pObject[33].AVMVersion,
    &v8,
    (Scaleform::GFx::AS2::PropFlags *)&v9);
  if ( v8.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v8);
}

// File Line: 161
// RVA: 0x6CB5B0
void __fastcall Scaleform::GFx::AS2::PointProto::PointProto(
        Scaleform::GFx::AS2::PointProto *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        Scaleform::GFx::AS2::Object *pprototype,
        Scaleform::GFx::AS2::FunctionRef *constructor)
{
  Scaleform::GFx::ASString *v6; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS2::PropFlags flags; // [rsp+30h] [rbp-48h] BYREF
  Scaleform::GFx::ASString result; // [rsp+38h] [rbp-40h] BYREF
  __int64 v11; // [rsp+40h] [rbp-38h]
  Scaleform::GFx::AS2::Value val; // [rsp+48h] [rbp-30h] BYREF

  v11 = -2i64;
  Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::PointObject,Scaleform::GFx::AS2::Environment>::Prototype<Scaleform::GFx::AS2::PointObject,Scaleform::GFx::AS2::Environment>(
    this,
    psc,
    pprototype,
    constructor);
  this->Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::PointObject,Scaleform::GFx::AS2::Environment>::Scaleform::GFx::AS2::PointObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::PointProto::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
  this->Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::PointObject,Scaleform::GFx::AS2::Environment>::Scaleform::GFx::AS2::PointObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::PointProto::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  this->Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::PointObject,Scaleform::GFx::AS2::Environment>::Scaleform::GFx::AS2::GASPrototypeBase::vfptr = (Scaleform::GFx::AS2::GASPrototypeBaseVtbl *)&Scaleform::GFx::AS2::PointProto::`vftable;
  flags.Flags = 6;
  Scaleform::GFx::AS2::GASPrototypeBase::InitFunctionMembers(
    &this->Scaleform::GFx::AS2::GASPrototypeBase,
    this,
    psc,
    Scaleform::GFx::AS2::PointProto::FunctionTable,
    &flags);
  flags.Flags = 2;
  val.T.Type = 4;
  val.NV.Int32Value = 0;
  v6 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &result, "length");
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    v6,
    &val,
    &flags);
  pNode = result.pNode;
  if ( result.pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
}

// File Line: 174
// RVA: 0x6A6EA0
void __fastcall Scaleform::GFx::AS2::PointProto::Add(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::PointObject *v2; // rax
  Scaleform::GFx::AS2::PointObject *v3; // rbx
  Scaleform::GFx::AS2::PointObject *v4; // rax
  Scaleform::GFx::AS2::PointObject *v5; // rbp
  unsigned int FirstArgBottomIndex; // r10d
  Scaleform::GFx::AS2::Environment *Env; // rdx
  Scaleform::GFx::AS2::Value *v8; // r9
  Scaleform::GFx::AS2::Object *v9; // rdi
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v11; // rax
  Scaleform::GFx::AS2::Environment *v12; // rdi
  unsigned int RefCount; // eax
  Scaleform::Render::Point<double> pt; // [rsp+38h] [rbp-40h] BYREF
  Scaleform::Render::Point<double> v15; // [rsp+48h] [rbp-30h] BYREF
  Scaleform::MemoryHeap *pHeap; // [rsp+80h] [rbp+8h] BYREF
  Scaleform::GFx::AS2::PointObject *v17; // [rsp+88h] [rbp+10h]

  pHeap = fn->Env->StringContext.pContext->pHeap;
  v2 = (Scaleform::GFx::AS2::PointObject *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::FnCall *, __int64))pHeap->vfptr->Alloc)(
                                             fn,
                                             96i64);
  v17 = v2;
  v3 = 0i64;
  if ( v2 )
  {
    Scaleform::GFx::AS2::PointObject::PointObject(v2, fn->Env);
    v5 = v4;
  }
  else
  {
    v5 = 0i64;
  }
  v17 = v5;
  if ( fn->NArgs <= 0 )
    goto LABEL_14;
  FirstArgBottomIndex = fn->FirstArgBottomIndex;
  Env = fn->Env;
  v8 = 0i64;
  if ( FirstArgBottomIndex <= 32 * ((unsigned int)Env->Stack.Pages.Data.Size - 1)
                            + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
    v8 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
  v9 = Scaleform::GFx::AS2::Value::ToObject(v8, Env);
  if ( v9 )
  {
    ThisPtr = fn->ThisPtr;
    if ( !ThisPtr
      || (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(ThisPtr) != 16 )
    {
      Scaleform::GFx::AS2::Environment::LogScriptError(
        fn->Env,
        "Error: Null or invalid this is used for a method of %s class.\n",
        "Point");
      goto LABEL_16;
    }
    v11 = fn->ThisPtr;
    if ( v11 )
      v3 = (Scaleform::GFx::AS2::PointObject *)&v11[-2];
    Scaleform::GFx::AS2::PointObject::GetProperties(v3, fn->Env, &pt);
    Scaleform::GFx::AS2::GFxObject_GetPointProperties(fn->Env, v9, &v15);
    pt.x = pt.x + v15.x;
    pt.y = pt.y + v15.y;
    Scaleform::GFx::AS2::PointObject::SetProperties(v5, fn->Env, &pt);
  }
  else
  {
LABEL_14:
    v12 = fn->Env;
    LOBYTE(pHeap) = 0;
    v5->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr->SetMemberRaw(
      &v5->Scaleform::GFx::AS2::ObjectInterface,
      &v12->StringContext,
      (Scaleform::GFx::ASString *)&v12->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[33].pASSupport,
      Point_NanParams,
      (Scaleform::GFx::AS2::PropFlags *)&pHeap);
    LOBYTE(pHeap) = 0;
    v5->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr->SetMemberRaw(
      &v5->Scaleform::GFx::AS2::ObjectInterface,
      &v12->StringContext,
      (Scaleform::GFx::ASString *)&v12->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[33].AVMVersion,
      (Scaleform::GFx::AS2::Value *)&byte_14243A450,
      (Scaleform::GFx::AS2::PropFlags *)&pHeap);
  }
  Scaleform::GFx::AS2::Value::SetAsObject(fn->Result, v5);
LABEL_16:
  if ( v5 )
  {
    RefCount = v5->RefCount;
    if ( (RefCount & 0x3FFFFFF) != 0 )
    {
      v5->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v5);
    }
  }
}

// File Line: 208
// RVA: 0x6A70D0
void __fastcall Scaleform::GFx::AS2::PointProto::Clone(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rcx
  __int64 v3; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v4; // rax
  Scaleform::GFx::AS2::Object *v5; // rbp
  Scaleform::GFx::AS2::ObjectInterface *v6; // rbx
  Scaleform::GFx::AS2::PointObject *v7; // rax
  Scaleform::GFx::AS2::Object *v8; // rax
  Scaleform::GFx::AS2::ASStringContext *p_StringContext; // rdi
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::Value ptr; // [rsp+40h] [rbp-58h] BYREF
  Scaleform::GFx::AS2::Value v12; // [rsp+60h] [rbp-38h] BYREF
  Scaleform::MemoryHeap *pHeap; // [rsp+A0h] [rbp+8h] BYREF
  Scaleform::GFx::AS2::PointObject *v14; // [rsp+A8h] [rbp+10h]

  ThisPtr = fn->ThisPtr;
  if ( ThisPtr
    && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(ThisPtr) == 16 )
  {
    v4 = fn->ThisPtr;
    v5 = 0i64;
    v6 = v4 - 2;
    if ( !v4 )
      v6 = 0i64;
    pHeap = fn->Env->StringContext.pContext->pHeap;
    v7 = (Scaleform::GFx::AS2::PointObject *)((__int64 (__fastcall *)(__int64, __int64))pHeap->vfptr->Alloc)(v3, 96i64);
    v14 = v7;
    if ( v7 )
    {
      Scaleform::GFx::AS2::PointObject::PointObject(v7, fn->Env);
      v5 = v8;
    }
    v14 = (Scaleform::GFx::AS2::PointObject *)v5;
    p_StringContext = &fn->Env->StringContext;
    `eh vector constructor iterator(&ptr, 0x20ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::AS2::Value::Value);
    ((void (__fastcall *)(Scaleform::GFx::AS2::ObjectInterface *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::Ptr<Scaleform::GFx::ASSupport> *, char *, void (__fastcall *)(Scaleform::GFx::AS2::Value *)))v6[2].vfptr->GetMemberRaw)(
      &v6[2],
      p_StringContext,
      &p_StringContext->pContext->pMovieRoot->pASMovieRoot.pObject[33].pASSupport,
      &ptr.T.Type,
      Scaleform::GFx::AS2::Value::~Value);
    v6[2].vfptr->GetMemberRaw(
      v6 + 2,
      p_StringContext,
      (Scaleform::GFx::ASString *)&p_StringContext->pContext->pMovieRoot->pASMovieRoot.pObject[33].AVMVersion,
      &v12);
    LOBYTE(pHeap) = 0;
    v5->Scaleform::GFx::AS2::ObjectInterface::vfptr->SetMemberRaw(
      &v5->Scaleform::GFx::AS2::ObjectInterface,
      p_StringContext,
      (Scaleform::GFx::ASString *)&p_StringContext->pContext->pMovieRoot->pASMovieRoot.pObject[33].pASSupport,
      &ptr,
      (Scaleform::GFx::AS2::PropFlags *)&pHeap);
    LOBYTE(pHeap) = 0;
    v5->Scaleform::GFx::AS2::ObjectInterface::vfptr->SetMemberRaw(
      &v5->Scaleform::GFx::AS2::ObjectInterface,
      p_StringContext,
      (Scaleform::GFx::ASString *)&p_StringContext->pContext->pMovieRoot->pASMovieRoot.pObject[33].AVMVersion,
      &v12,
      (Scaleform::GFx::AS2::PropFlags *)&pHeap);
    Scaleform::GFx::AS2::Value::SetAsObject(fn->Result, v5);
    `eh vector destructor iterator(&ptr, 0x20ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::AS2::Value::~Value);
    RefCount = v5->RefCount;
    if ( (RefCount & 0x3FFFFFF) != 0 )
    {
      v5->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v5);
    }
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      fn->Env,
      "Error: Null or invalid this is used for a method of %s class.\n",
      "Point");
  }
}

// File Line: 228
// RVA: 0x6A72D0
void __fastcall Scaleform::GFx::AS2::PointProto::Equals(Scaleform::GFx::AS2::FnCall *fn)
{
  bool v1; // di
  Scaleform::GFx::AS2::Environment *Env; // r9
  unsigned __int64 FirstArgBottomIndex; // r8
  Scaleform::GFx::AS2::PointObject *v5; // rbp
  Scaleform::GFx::AS2::Value *v6; // rcx
  Scaleform::GFx::AS2::Object *v7; // rax
  Scaleform::GFx::AS2::Object *v8; // rsi
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v10; // rax
  Scaleform::GFx::AS2::Value *Result; // rbx
  Scaleform::Render::Point<double> pt; // [rsp+20h] [rbp-28h] BYREF
  Scaleform::Render::Point<double> v13; // [rsp+30h] [rbp-18h] BYREF

  v1 = 0;
  if ( fn->NArgs <= 0 )
    goto LABEL_13;
  Env = fn->Env;
  FirstArgBottomIndex = (unsigned int)fn->FirstArgBottomIndex;
  v5 = 0i64;
  v6 = 0i64;
  if ( (unsigned int)FirstArgBottomIndex <= 32 * (LODWORD(Env->Stack.Pages.Data.Size) - 1)
                                          + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
    v6 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
  v7 = Scaleform::GFx::AS2::Value::ToObject(v6, Env);
  v8 = v7;
  if ( !v7
    || (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v7->Scaleform::GFx::AS2::ObjectInterface::vfptr->gap8[8])(&v7->Scaleform::GFx::AS2::ObjectInterface) != 16 )
  {
    goto LABEL_13;
  }
  ThisPtr = fn->ThisPtr;
  if ( ThisPtr
    && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(ThisPtr) == 16 )
  {
    v10 = fn->ThisPtr;
    if ( v10 )
      v5 = (Scaleform::GFx::AS2::PointObject *)&v10[-2];
    Scaleform::GFx::AS2::PointObject::GetProperties(v5, fn->Env, &pt);
    Scaleform::GFx::AS2::GFxObject_GetPointProperties(fn->Env, v8, &v13);
    v1 = pt.x == v13.x && pt.y == v13.y;
LABEL_13:
    Result = fn->Result;
    Scaleform::GFx::AS2::Value::DropRefs(Result);
    Result->T.Type = 2;
    Result->V.BooleanValue = v1;
    return;
  }
  Scaleform::GFx::AS2::Environment::LogScriptError(
    fn->Env,
    "Error: Null or invalid this is used for a method of %s class.\n",
    "Point");
}

// File Line: 255
// RVA: 0x6A7400
void __fastcall Scaleform::GFx::AS2::PointProto::Normalize(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rax
  Scaleform::GFx::AS2::Value *v4; // rdx
  Scaleform::GFx::AS2::PointObject *v5; // rsi
  unsigned int FirstArgBottomIndex; // r9d
  Scaleform::GFx::AS2::Environment *v7; // r8
  double y; // xmm8_8
  double x; // xmm7_8
  long double v10; // xmm0_8
  Scaleform::GFx::AS2::Environment *Env; // rdi
  Scaleform::Render::Point<double> pt; // [rsp+38h] [rbp-70h] BYREF
  Scaleform::GFx::AS2::Value v13; // [rsp+48h] [rbp-60h] BYREF
  char v14; // [rsp+B0h] [rbp+8h] BYREF

  ThisPtr = fn->ThisPtr;
  if ( ThisPtr
    && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(ThisPtr) == 16 )
  {
    v3 = fn->ThisPtr;
    v4 = 0i64;
    v5 = (Scaleform::GFx::AS2::PointObject *)&v3[-2];
    if ( !v3 )
      v5 = 0i64;
    if ( fn->NArgs <= 0 )
    {
      Env = fn->Env;
      v14 = 0;
      v5->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr->SetMemberRaw(
        &v5->Scaleform::GFx::AS2::ObjectInterface,
        &Env->StringContext,
        (Scaleform::GFx::ASString *)&Env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[33].pASSupport,
        Point_NanParams,
        (Scaleform::GFx::AS2::PropFlags *)&v14);
      v14 = 0;
      v5->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr->SetMemberRaw(
        &v5->Scaleform::GFx::AS2::ObjectInterface,
        &Env->StringContext,
        (Scaleform::GFx::ASString *)&Env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[33].AVMVersion,
        (Scaleform::GFx::AS2::Value *)&byte_14243A450,
        (Scaleform::GFx::AS2::PropFlags *)&v14);
    }
    else
    {
      FirstArgBottomIndex = fn->FirstArgBottomIndex;
      v7 = fn->Env;
      if ( FirstArgBottomIndex <= 32 * ((unsigned int)v7->Stack.Pages.Data.Size - 1)
                                + (unsigned int)(v7->Stack.pCurrent - v7->Stack.pPageStart) )
        v4 = &v7->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
      Scaleform::GFx::AS2::Value::Value(&v13, v4);
      Scaleform::GFx::AS2::PointObject::GetProperties(v5, fn->Env, &pt);
      y = pt.y;
      x = pt.x;
      v10 = Scaleform::GFx::AS2::Value::ToNumber(&v13, fn->Env) / sqrt(y * y + x * x);
      pt.x = x * v10;
      pt.y = y * v10;
      Scaleform::GFx::AS2::PointObject::SetProperties(v5, fn->Env, &pt);
      if ( v13.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v13);
    }
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      fn->Env,
      "Error: Null or invalid this is used for a method of %s class.\n",
      "Point");
  }
}

// File Line: 279
// RVA: 0x6A7600
void __fastcall Scaleform::GFx::AS2::PointProto::Offset(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rax
  Scaleform::GFx::AS2::Value *v4; // rdi
  Scaleform::GFx::AS2::PointObject *v5; // rbp
  char Type; // si
  unsigned int FirstArgBottomIndex; // r9d
  Scaleform::GFx::AS2::Environment *Env; // r8
  Scaleform::GFx::AS2::Value *v9; // rdx
  unsigned int v10; // edx
  Scaleform::GFx::AS2::Environment *v11; // r8
  double v12; // xmm6_8
  long double v13; // xmm0_8
  Scaleform::Render::Point<double> pt; // [rsp+28h] [rbp-70h] BYREF
  Scaleform::GFx::AS2::Value v15; // [rsp+38h] [rbp-60h] BYREF
  Scaleform::GFx::AS2::Value v16; // [rsp+58h] [rbp-40h] BYREF

  ThisPtr = fn->ThisPtr;
  if ( ThisPtr
    && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(ThisPtr) == 16 )
  {
    v3 = fn->ThisPtr;
    v4 = 0i64;
    v5 = (Scaleform::GFx::AS2::PointObject *)&v3[-2];
    if ( !v3 )
      v5 = 0i64;
    v16.T.Type = 0;
    Type = 0;
    v15.T.Type = 0;
    if ( fn->NArgs > 0 )
    {
      FirstArgBottomIndex = fn->FirstArgBottomIndex;
      Env = fn->Env;
      v9 = 0i64;
      if ( FirstArgBottomIndex <= 32 * ((unsigned int)Env->Stack.Pages.Data.Size - 1)
                                + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
        v9 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
      Scaleform::GFx::AS2::Value::operator=(&v16, v9);
      if ( fn->NArgs > 1 )
      {
        v10 = fn->FirstArgBottomIndex - 1;
        v11 = fn->Env;
        if ( v10 <= 32 * ((unsigned int)v11->Stack.Pages.Data.Size - 1)
                  + (unsigned int)(v11->Stack.pCurrent - v11->Stack.pPageStart) )
          v4 = &v11->Stack.Pages.Data.Data[v10 >> 5]->Values[v10 & 0x1F];
        Scaleform::GFx::AS2::Value::operator=(&v15, v4);
        Type = v15.T.Type;
      }
    }
    Scaleform::GFx::AS2::PointObject::GetProperties(v5, fn->Env, &pt);
    v12 = Scaleform::GFx::AS2::Value::ToNumber(&v15, fn->Env);
    v13 = Scaleform::GFx::AS2::Value::ToNumber(&v16, fn->Env);
    pt.x = pt.x + v13;
    pt.y = pt.y + v12;
    Scaleform::GFx::AS2::PointObject::SetProperties(v5, fn->Env, &pt);
    if ( (unsigned __int8)Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v15);
    if ( v16.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v16);
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      fn->Env,
      "Error: Null or invalid this is used for a method of %s class.\n",
      "Point");
  }
}

// File Line: 303
// RVA: 0x6A77D0
void __fastcall Scaleform::GFx::AS2::PointProto::Subtract(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::PointObject *v2; // rax
  Scaleform::GFx::AS2::PointObject *v3; // rbx
  Scaleform::GFx::AS2::PointObject *v4; // rax
  Scaleform::GFx::AS2::PointObject *v5; // rbp
  unsigned int FirstArgBottomIndex; // r10d
  Scaleform::GFx::AS2::Environment *Env; // rdx
  Scaleform::GFx::AS2::Value *v8; // r9
  Scaleform::GFx::AS2::Object *v9; // rdi
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v11; // rax
  Scaleform::GFx::AS2::Environment *v12; // rdi
  unsigned int RefCount; // eax
  Scaleform::Render::Point<double> pt; // [rsp+38h] [rbp-40h] BYREF
  Scaleform::Render::Point<double> v15; // [rsp+48h] [rbp-30h] BYREF
  Scaleform::MemoryHeap *pHeap; // [rsp+80h] [rbp+8h] BYREF
  Scaleform::GFx::AS2::PointObject *v17; // [rsp+88h] [rbp+10h]

  pHeap = fn->Env->StringContext.pContext->pHeap;
  v2 = (Scaleform::GFx::AS2::PointObject *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::FnCall *, __int64))pHeap->vfptr->Alloc)(
                                             fn,
                                             96i64);
  v17 = v2;
  v3 = 0i64;
  if ( v2 )
  {
    Scaleform::GFx::AS2::PointObject::PointObject(v2, fn->Env);
    v5 = v4;
  }
  else
  {
    v5 = 0i64;
  }
  v17 = v5;
  if ( fn->NArgs <= 0 )
    goto LABEL_14;
  FirstArgBottomIndex = fn->FirstArgBottomIndex;
  Env = fn->Env;
  v8 = 0i64;
  if ( FirstArgBottomIndex <= 32 * ((unsigned int)Env->Stack.Pages.Data.Size - 1)
                            + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
    v8 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
  v9 = Scaleform::GFx::AS2::Value::ToObject(v8, Env);
  if ( v9 )
  {
    ThisPtr = fn->ThisPtr;
    if ( !ThisPtr
      || (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(ThisPtr) != 16 )
    {
      Scaleform::GFx::AS2::Environment::LogScriptError(
        fn->Env,
        "Error: Null or invalid this is used for a method of %s class.\n",
        "Point");
      goto LABEL_16;
    }
    v11 = fn->ThisPtr;
    if ( v11 )
      v3 = (Scaleform::GFx::AS2::PointObject *)&v11[-2];
    Scaleform::GFx::AS2::PointObject::GetProperties(v3, fn->Env, &pt);
    Scaleform::GFx::AS2::GFxObject_GetPointProperties(fn->Env, v9, &v15);
    pt.x = pt.x - v15.x;
    pt.y = pt.y - v15.y;
    Scaleform::GFx::AS2::PointObject::SetProperties(v5, fn->Env, &pt);
  }
  else
  {
LABEL_14:
    v12 = fn->Env;
    LOBYTE(pHeap) = 0;
    v5->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr->SetMemberRaw(
      &v5->Scaleform::GFx::AS2::ObjectInterface,
      &v12->StringContext,
      (Scaleform::GFx::ASString *)&v12->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[33].pASSupport,
      Point_NanParams,
      (Scaleform::GFx::AS2::PropFlags *)&pHeap);
    LOBYTE(pHeap) = 0;
    v5->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr->SetMemberRaw(
      &v5->Scaleform::GFx::AS2::ObjectInterface,
      &v12->StringContext,
      (Scaleform::GFx::ASString *)&v12->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[33].AVMVersion,
      (Scaleform::GFx::AS2::Value *)&byte_14243A450,
      (Scaleform::GFx::AS2::PropFlags *)&pHeap);
  }
  Scaleform::GFx::AS2::Value::SetAsObject(fn->Result, v5);
LABEL_16:
  if ( v5 )
  {
    RefCount = v5->RefCount;
    if ( (RefCount & 0x3FFFFFF) != 0 )
    {
      v5->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v5);
    }
  }
}

// File Line: 337
// RVA: 0x6A7A20
void __fastcall Scaleform::GFx::AS2::PointProto::ToString(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rax
  Scaleform::GFx::AS2::ObjectInterface *v4; // rbx
  Scaleform::GFx::AS2::Environment *Env; // rdi
  Scaleform::GFx::ASString *v6; // r14
  Scaleform::GFx::AS2::Value *v7; // rdi
  Scaleform::GFx::ASStringNode *pNode; // rax
  Scaleform::GFx::ASStringNode *v9; // rcx
  Scaleform::GFx::ASString result; // [rsp+38h] [rbp-70h] BYREF
  Scaleform::GFx::ASString v12; // [rsp+40h] [rbp-68h] BYREF
  Scaleform::GFx::AS2::Value ptr; // [rsp+50h] [rbp-58h] BYREF
  Scaleform::GFx::AS2::Value v14; // [rsp+70h] [rbp-38h] BYREF
  Scaleform::String str; // [rsp+B0h] [rbp+8h] BYREF
  Scaleform::GFx::ASString v16; // [rsp+B8h] [rbp+10h] BYREF

  ThisPtr = fn->ThisPtr;
  if ( ThisPtr
    && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(ThisPtr) == 16 )
  {
    v3 = fn->ThisPtr;
    if ( v3 )
    {
      v4 = v3 - 2;
      if ( v3 != (Scaleform::GFx::AS2::ObjectInterface *)32 )
      {
        `eh vector constructor iterator(
          &ptr,
          0x20ui64,
          2,
          (void (__fastcall *)(void *))Scaleform::GFx::AS2::Value::Value);
        Env = fn->Env;
        ((void (__fastcall *)(Scaleform::GFx::AS2::ObjectInterface *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::Ptr<Scaleform::GFx::ASSupport> *, Scaleform::GFx::AS2::Value *, void (__fastcall *)(Scaleform::GFx::AS2::Value *)))v4[2].vfptr->GetMemberRaw)(
          &v4[2],
          &Env->StringContext,
          &Env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[33].pASSupport,
          &ptr,
          Scaleform::GFx::AS2::Value::~Value);
        v4[2].vfptr->GetMemberRaw(
          v4 + 2,
          &Env->StringContext,
          (Scaleform::GFx::ASString *)&Env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[33].AVMVersion,
          &v14);
        Scaleform::GFx::AS2::Value::ToString(&ptr, &result, fn->Env, 6);
        Scaleform::GFx::AS2::Value::ToString(&v14, &v12, fn->Env, 6);
        Scaleform::String::String(&str);
        Scaleform::String::AppendString(&str, "(x=", -1i64);
        Scaleform::String::AppendString(&str, result.pNode->pData, -1i64);
        Scaleform::String::AppendString(&str, ", y=", -1i64);
        Scaleform::String::AppendString(&str, v12.pNode->pData, -1i64);
        Scaleform::String::AppendString(&str, ")", -1i64);
        v6 = Scaleform::GFx::AS2::Environment::CreateString(fn->Env, &v16, &str);
        v7 = fn->Result;
        if ( v7->T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(fn->Result);
        v7->T.Type = 5;
        pNode = v6->pNode;
        v7->NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)v6->pNode;
        ++pNode->RefCount;
        v9 = v16.pNode;
        if ( v16.pNode->RefCount-- == 1 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v9);
        if ( _InterlockedExchangeAdd(
               (volatile signed __int32 *)((str.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8),
               0xFFFFFFFF) == 1 )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        `eh vector destructor iterator(
          &result,
          8ui64,
          2,
          (void (__fastcall *)(void *))Scaleform::GFx::ASString::~ASString);
        `eh vector destructor iterator(
          &ptr,
          0x20ui64,
          2,
          (void (__fastcall *)(void *))Scaleform::GFx::AS2::Value::~Value);
      }
    }
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      fn->Env,
      "Error: Null or invalid this is used for a method of %s class.\n",
      "Point");
  }
}

// File Line: 389
// RVA: 0x6A7C90
void __fastcall Scaleform::GFx::AS2::PointCtorFunction::Distance(Scaleform::GFx::AS2::FnCall *fn)
{
  double v2; // xmm0_8
  Scaleform::GFx::AS2::Value *Result; // rbx
  unsigned int FirstArgBottomIndex; // r10d
  Scaleform::GFx::AS2::Environment *Env; // rdx
  Scaleform::GFx::AS2::Value *v6; // rbx
  Scaleform::GFx::AS2::Value *v7; // r9
  Scaleform::GFx::AS2::Object *v8; // rdi
  unsigned int v9; // r9d
  Scaleform::GFx::AS2::Environment *v10; // r10
  Scaleform::GFx::AS2::Object *v11; // rax
  Scaleform::GFx::AS2::Object *v12; // r14
  Scaleform::GFx::AS2::ObjectInterface *v13; // rdi
  Scaleform::GFx::AS2::Value *v14; // rbx
  Scaleform::GFx::AS2::Environment *v15; // rbx
  Scaleform::GFx::AS2::Environment *v16; // rdi
  Scaleform::GFx::AS2::Environment *v17; // rbx
  double v18; // xmm6_8
  double v19; // xmm7_8
  Scaleform::GFx::AS2::Environment *v20; // rbx
  double v21; // xmm6_8
  long double v22; // xmm0_8
  Scaleform::GFx::AS2::Environment *v23; // rbx
  double v24; // xmm6_8
  double v25; // xmm7_8
  Scaleform::GFx::AS2::Environment *v26; // rbx
  double v27; // xmm6_8
  long double v28; // xmm0_8
  double v29; // xmm0_8
  long double v30; // xmm0_8
  Scaleform::GFx::AS2::Value v31; // [rsp+30h] [rbp-B8h] BYREF
  Scaleform::GFx::AS2::Value v32; // [rsp+50h] [rbp-98h] BYREF
  __int64 v33; // [rsp+70h] [rbp-78h]
  Scaleform::GFx::AS2::Value v34; // [rsp+78h] [rbp-70h] BYREF
  Scaleform::GFx::AS2::Value v35; // [rsp+A8h] [rbp-40h] BYREF
  Scaleform::GFx::AS2::Value ptr; // [rsp+C8h] [rbp-20h] BYREF
  Scaleform::GFx::AS2::Value v37; // [rsp+E8h] [rbp+0h] BYREF

  v33 = -2i64;
  v2 = Scaleform::GFx::NumberUtil::NaN();
  Result = fn->Result;
  if ( Result->T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(fn->Result);
  Result->T.Type = 3;
  Result->NV.NumberValue = v2;
  if ( fn->NArgs > 1 )
  {
    FirstArgBottomIndex = fn->FirstArgBottomIndex;
    Env = fn->Env;
    v6 = 0i64;
    v7 = 0i64;
    if ( FirstArgBottomIndex <= 32 * ((unsigned int)Env->Stack.Pages.Data.Size - 1)
                              + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
      v7 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
    v8 = Scaleform::GFx::AS2::Value::ToObject(v7, Env);
    v9 = fn->FirstArgBottomIndex - 1;
    v10 = fn->Env;
    if ( v9 <= 32 * ((unsigned int)v10->Stack.Pages.Data.Size - 1)
             + (unsigned int)(v10->Stack.pCurrent - v10->Stack.pPageStart) )
      v6 = &v10->Stack.Pages.Data.Data[v9 >> 5]->Values[v9 & 0x1F];
    v11 = Scaleform::GFx::AS2::Value::ToObject(v6, fn->Env);
    v12 = v11;
    if ( v8 && v11 )
    {
      v13 = &v8->Scaleform::GFx::AS2::ObjectInterface;
      if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v13->vfptr->gap8[8])(v13) == 16
        || (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v12->Scaleform::GFx::AS2::ObjectInterface::vfptr->gap8[8])(&v12->Scaleform::GFx::AS2::ObjectInterface) == 16 )
      {
        `eh vector constructor iterator(
          &ptr,
          0x20ui64,
          2,
          (void (__fastcall *)(void *))Scaleform::GFx::AS2::Value::Value);
        `eh vector constructor iterator(
          &v34.NV + 1,
          0x20ui64,
          2,
          (void (__fastcall *)(void *))Scaleform::GFx::AS2::Value::Value);
        v15 = fn->Env;
        ((void (__fastcall *)(Scaleform::GFx::AS2::ObjectInterface *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::Ptr<Scaleform::GFx::ASSupport> *, Scaleform::GFx::AS2::Value *, void (__fastcall *)(Scaleform::GFx::AS2::Value *)))v13->vfptr->GetMemberRaw)(
          v13,
          &v15->StringContext,
          &v15->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[33].pASSupport,
          &ptr,
          Scaleform::GFx::AS2::Value::~Value);
        v13->vfptr->GetMemberRaw(
          v13,
          &v15->StringContext,
          (Scaleform::GFx::ASString *)&v15->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[33].AVMVersion,
          &v37);
        v16 = fn->Env;
        v12->Scaleform::GFx::AS2::ObjectInterface::vfptr->GetMemberRaw(
          &v12->Scaleform::GFx::AS2::ObjectInterface,
          &v16->StringContext,
          (Scaleform::GFx::ASString *)&v16->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[33].pASSupport,
          (Scaleform::GFx::AS2::Value *)(&v34.NV + 1));
        v12->Scaleform::GFx::AS2::ObjectInterface::vfptr->GetMemberRaw(
          &v12->Scaleform::GFx::AS2::ObjectInterface,
          &v16->StringContext,
          (Scaleform::GFx::ASString *)&v16->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[33].AVMVersion,
          &v35);
        Scaleform::GFx::AS2::Value::Value(&v31, (Scaleform::GFx::AS2::Value *)(&v34.NV + 1));
        v17 = fn->Env;
        v18 = Scaleform::GFx::AS2::Value::ToNumber(&v31, v17);
        v19 = Scaleform::GFx::AS2::Value::ToNumber(&ptr, v17);
        if ( v31.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&v31);
        v31.T.Type = 3;
        v31.NV.NumberValue = v18 - v19;
        v20 = fn->Env;
        v21 = Scaleform::GFx::AS2::Value::ToNumber(&v31, v20);
        v22 = Scaleform::GFx::AS2::Value::ToNumber(&v31, v20);
        v31.T.Type = 3;
        v31.NV.NumberValue = v22 * v21;
        Scaleform::GFx::AS2::Value::Value(&v32, &v35);
        v23 = fn->Env;
        v24 = Scaleform::GFx::AS2::Value::ToNumber(&v32, v23);
        v25 = Scaleform::GFx::AS2::Value::ToNumber(&v37, v23);
        if ( v32.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&v32);
        v32.T.Type = 3;
        v32.NV.NumberValue = v24 - v25;
        v26 = fn->Env;
        v27 = Scaleform::GFx::AS2::Value::ToNumber(&v32, v26);
        v28 = Scaleform::GFx::AS2::Value::ToNumber(&v32, v26);
        v32.T.Type = 3;
        v32.NV.NumberValue = v28 * v27;
        Scaleform::GFx::AS2::Value::Add(&v31, fn->Env, &v32);
        v29 = Scaleform::GFx::AS2::Value::ToNumber(&v31, fn->Env);
        v34.T.Type = 3;
        *((_QWORD *)&v32.NV + 3) = sqrt(v29);
        v30 = Scaleform::GFx::AS2::Value::ToNumber(&v34, fn->Env);
        Scaleform::GFx::AS2::Value::SetNumber(fn->Result, v30);
        if ( v32.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&v32);
        if ( v31.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&v31);
        `eh vector destructor iterator(
          &v34.NV + 1,
          0x20ui64,
          2,
          (void (__fastcall *)(void *))Scaleform::GFx::AS2::Value::~Value);
        `eh vector destructor iterator(
          &ptr,
          0x20ui64,
          2,
          (void (__fastcall *)(void *))Scaleform::GFx::AS2::Value::~Value);
      }
      else
      {
        v14 = fn->Result;
        Scaleform::GFx::AS2::Value::DropRefs(v14);
        v14->T.Type = 0;
      }
    }
  }
}

// File Line: 432
// RVA: 0x6A80A0
void __fastcall Scaleform::GFx::AS2::PointCtorFunction::Interpolate(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::PointObject *v2; // rax
  Scaleform::GFx::AS2::Value *v3; // rbx
  Scaleform::GFx::AS2::PointObject *v4; // rax
  Scaleform::GFx::AS2::PointObject *v5; // rsi
  char v6; // di
  unsigned int FirstArgBottomIndex; // r10d
  Scaleform::GFx::AS2::Environment *Env; // rdx
  Scaleform::GFx::AS2::Value *v9; // r9
  Scaleform::GFx::AS2::Object *v10; // r15
  unsigned int v11; // r9d
  Scaleform::GFx::AS2::Environment *v12; // r11
  Scaleform::GFx::AS2::Value *v13; // r10
  Scaleform::GFx::AS2::Object *v14; // r14
  unsigned int v15; // r8d
  Scaleform::GFx::AS2::Environment *v16; // r9
  long double v17; // xmm0_8
  Scaleform::GFx::AS2::Environment *v18; // rdi
  unsigned int RefCount; // eax
  Scaleform::Render::Point<double> pt; // [rsp+38h] [rbp-70h] BYREF
  Scaleform::Render::Point<double> v21; // [rsp+48h] [rbp-60h] BYREF
  Scaleform::GFx::AS2::Value v22; // [rsp+58h] [rbp-50h] BYREF
  Scaleform::MemoryHeap *pHeap; // [rsp+B0h] [rbp+8h] BYREF
  Scaleform::GFx::AS2::PointObject *v24; // [rsp+B8h] [rbp+10h]

  pHeap = fn->Env->StringContext.pContext->pHeap;
  v2 = (Scaleform::GFx::AS2::PointObject *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::FnCall *, __int64))pHeap->vfptr->Alloc)(
                                             fn,
                                             96i64);
  v24 = v2;
  v3 = 0i64;
  if ( v2 )
  {
    Scaleform::GFx::AS2::PointObject::PointObject(v2, fn->Env);
    v5 = v4;
  }
  else
  {
    v5 = 0i64;
  }
  v24 = v5;
  v6 = 0;
  if ( fn->NArgs <= 2 )
    goto LABEL_17;
  FirstArgBottomIndex = fn->FirstArgBottomIndex;
  Env = fn->Env;
  v9 = 0i64;
  if ( FirstArgBottomIndex <= 32 * ((unsigned int)Env->Stack.Pages.Data.Size - 1)
                            + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
    v9 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
  v10 = Scaleform::GFx::AS2::Value::ToObject(v9, Env);
  v11 = fn->FirstArgBottomIndex - 1;
  v12 = fn->Env;
  v13 = 0i64;
  if ( v11 <= 32 * ((unsigned int)v12->Stack.Pages.Data.Size - 1)
            + (unsigned int)(v12->Stack.pCurrent - v12->Stack.pPageStart) )
    v13 = &v12->Stack.Pages.Data.Data[v11 >> 5]->Values[v11 & 0x1F];
  v14 = Scaleform::GFx::AS2::Value::ToObject(v13, fn->Env);
  v15 = fn->FirstArgBottomIndex - 2;
  v16 = fn->Env;
  if ( v15 <= 32 * ((unsigned int)v16->Stack.Pages.Data.Size - 1)
            + (unsigned int)(v16->Stack.pCurrent - v16->Stack.pPageStart) )
    v3 = &v16->Stack.Pages.Data.Data[v15 >> 5]->Values[v15 & 0x1F];
  Scaleform::GFx::AS2::Value::Value(&v22, v3);
  if ( v10 && v14 )
  {
    Scaleform::GFx::AS2::GFxObject_GetPointProperties(fn->Env, v10, &pt);
    Scaleform::GFx::AS2::GFxObject_GetPointProperties(fn->Env, v14, &v21);
    v17 = Scaleform::GFx::AS2::Value::ToNumber(&v22, fn->Env);
    v21.x = (pt.x - v21.x) * v17 + v21.x;
    v21.y = (pt.y - v21.y) * v17 + v21.y;
    Scaleform::GFx::AS2::PointObject::SetProperties(v5, fn->Env, &v21);
    v6 = 1;
  }
  if ( v22.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v22);
  if ( !v6 )
  {
LABEL_17:
    v18 = fn->Env;
    LOBYTE(pHeap) = 0;
    v5->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr->SetMemberRaw(
      &v5->Scaleform::GFx::AS2::ObjectInterface,
      &v18->StringContext,
      (Scaleform::GFx::ASString *)&v18->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[33].pASSupport,
      Point_NanParams,
      (Scaleform::GFx::AS2::PropFlags *)&pHeap);
    LOBYTE(pHeap) = 0;
    v5->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr->SetMemberRaw(
      &v5->Scaleform::GFx::AS2::ObjectInterface,
      &v18->StringContext,
      (Scaleform::GFx::ASString *)&v18->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[33].AVMVersion,
      (Scaleform::GFx::AS2::Value *)&byte_14243A450,
      (Scaleform::GFx::AS2::PropFlags *)&pHeap);
  }
  Scaleform::GFx::AS2::Value::SetAsObject(fn->Result, v5);
  if ( v5 )
  {
    RefCount = v5->RefCount;
    if ( (RefCount & 0x3FFFFFF) != 0 )
    {
      v5->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v5);
    }
  }
}

// File Line: 470
// RVA: 0x6A8380
void __fastcall Scaleform::GFx::AS2::PointCtorFunction::Polar(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::PointObject *v2; // rax
  Scaleform::GFx::AS2::Value *v3; // rbx
  Scaleform::GFx::AS2::PointObject *v4; // rax
  Scaleform::GFx::AS2::PointObject *v5; // rsi
  unsigned int FirstArgBottomIndex; // r9d
  Scaleform::GFx::AS2::Environment *v7; // rdx
  Scaleform::GFx::AS2::Value *v8; // r8
  unsigned int v9; // edx
  Scaleform::GFx::AS2::Environment *v10; // r8
  double v11; // xmm8_8
  double v12; // xmm6_8
  double v13; // xmm7_8
  Scaleform::GFx::AS2::Environment *Env; // rdi
  unsigned int RefCount; // eax
  Scaleform::Render::Point<double> pt; // [rsp+38h] [rbp-A0h] BYREF
  Scaleform::GFx::AS2::Value v17; // [rsp+48h] [rbp-90h] BYREF
  Scaleform::GFx::AS2::Value v18; // [rsp+68h] [rbp-70h] BYREF
  Scaleform::MemoryHeap *pHeap; // [rsp+E0h] [rbp+8h] BYREF
  Scaleform::GFx::AS2::PointObject *v20; // [rsp+E8h] [rbp+10h]

  pHeap = fn->Env->StringContext.pContext->pHeap;
  v2 = (Scaleform::GFx::AS2::PointObject *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::FnCall *, __int64))pHeap->vfptr->Alloc)(
                                             fn,
                                             96i64);
  v20 = v2;
  v3 = 0i64;
  if ( v2 )
  {
    Scaleform::GFx::AS2::PointObject::PointObject(v2, fn->Env);
    v5 = v4;
  }
  else
  {
    v5 = 0i64;
  }
  v20 = v5;
  if ( fn->NArgs <= 1 )
  {
    Env = fn->Env;
    LOBYTE(pHeap) = 0;
    v5->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr->SetMemberRaw(
      &v5->Scaleform::GFx::AS2::ObjectInterface,
      &Env->StringContext,
      (Scaleform::GFx::ASString *)&Env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[33].pASSupport,
      Point_NanParams,
      (Scaleform::GFx::AS2::PropFlags *)&pHeap);
    LOBYTE(pHeap) = 0;
    v5->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr->SetMemberRaw(
      &v5->Scaleform::GFx::AS2::ObjectInterface,
      &Env->StringContext,
      (Scaleform::GFx::ASString *)&Env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[33].AVMVersion,
      (Scaleform::GFx::AS2::Value *)&byte_14243A450,
      (Scaleform::GFx::AS2::PropFlags *)&pHeap);
  }
  else
  {
    FirstArgBottomIndex = fn->FirstArgBottomIndex;
    v7 = fn->Env;
    v8 = 0i64;
    if ( FirstArgBottomIndex <= 32 * ((unsigned int)v7->Stack.Pages.Data.Size - 1)
                              + (unsigned int)(v7->Stack.pCurrent - v7->Stack.pPageStart) )
      v8 = &v7->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
    Scaleform::GFx::AS2::Value::Value(&v18, v8);
    v9 = fn->FirstArgBottomIndex - 1;
    v10 = fn->Env;
    if ( v9 <= 32 * ((unsigned int)v10->Stack.Pages.Data.Size - 1)
             + (unsigned int)(v10->Stack.pCurrent - v10->Stack.pPageStart) )
      v3 = &v10->Stack.Pages.Data.Data[v9 >> 5]->Values[v9 & 0x1F];
    Scaleform::GFx::AS2::Value::Value(&v17, v3);
    v11 = Scaleform::GFx::AS2::Value::ToNumber(&v18, fn->Env);
    v12 = Scaleform::GFx::AS2::Value::ToNumber(&v17, fn->Env);
    v13 = sin(v12);
    pt.x = cos(v12) * v11;
    pt.y = v13 * v11;
    Scaleform::GFx::AS2::PointObject::SetProperties(v5, fn->Env, &pt);
    if ( v17.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v17);
    if ( v18.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v18);
  }
  Scaleform::GFx::AS2::Value::SetAsObject(fn->Result, v5);
  if ( v5 )
  {
    RefCount = v5->RefCount;
    if ( (RefCount & 0x3FFFFFF) != 0 )
    {
      v5->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v5);
    }
  }
}

// File Line: 497
// RVA: 0x6F9C00
void __fastcall Scaleform::GFx::AS2::PointCtorFunction::GlobalCtor(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Value *v2; // rdi
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v4; // rbx
  Scaleform::GFx::AS2::Object *v5; // rbx
  Scaleform::GFx::AS2::PointObject *v6; // rax
  Scaleform::GFx::AS2::Object *v7; // rax
  unsigned int FirstArgBottomIndex; // r8d
  Scaleform::GFx::AS2::Environment *Env; // r9
  Scaleform::GFx::AS2::Value *v10; // rdx
  unsigned int v11; // edx
  Scaleform::GFx::AS2::Environment *v12; // r8
  Scaleform::GFx::AS2::Environment *v13; // rsi
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::Value ptr; // [rsp+40h] [rbp-58h] BYREF
  Scaleform::GFx::AS2::Value v16; // [rsp+60h] [rbp-38h] BYREF
  Scaleform::MemoryHeap *pHeap; // [rsp+A0h] [rbp+8h] BYREF
  Scaleform::GFx::AS2::Object *v18; // [rsp+A8h] [rbp+10h]
  Scaleform::GFx::AS2::PointObject *v19; // [rsp+B0h] [rbp+18h]

  v2 = 0i64;
  v18 = 0i64;
  ThisPtr = fn->ThisPtr;
  if ( ThisPtr
    && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(ThisPtr) == 16
    && !fn->ThisPtr->vfptr->IsBuiltinPrototype(fn->ThisPtr) )
  {
    v4 = fn->ThisPtr;
    if ( v4 )
    {
      v5 = (Scaleform::GFx::AS2::Object *)&v4[-2];
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
    v6 = (Scaleform::GFx::AS2::PointObject *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::ObjectInterface *, __int64))pHeap->vfptr->Alloc)(
                                               ThisPtr,
                                               96i64);
    v19 = v6;
    if ( v6 )
    {
      Scaleform::GFx::AS2::PointObject::PointObject(v6, (Scaleform::GFx::AS2::ASStringContext *)fn->Env);
      v5 = v7;
    }
    else
    {
      v5 = 0i64;
    }
  }
  v18 = v5;
  Scaleform::GFx::AS2::Value::SetAsObject(fn->Result, v5);
  if ( fn->NArgs > 0 )
  {
    `eh vector constructor iterator(&ptr, 0x20ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::AS2::Value::Value);
    FirstArgBottomIndex = fn->FirstArgBottomIndex;
    Env = fn->Env;
    v10 = 0i64;
    if ( FirstArgBottomIndex <= 32 * ((unsigned int)Env->Stack.Pages.Data.Size - 1)
                              + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
      v10 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
    Scaleform::GFx::AS2::Value::operator=(&ptr, v10);
    if ( fn->NArgs > 1 )
    {
      v11 = fn->FirstArgBottomIndex - 1;
      v12 = fn->Env;
      if ( v11 <= 32 * ((unsigned int)v12->Stack.Pages.Data.Size - 1)
                + (unsigned int)(v12->Stack.pCurrent - v12->Stack.pPageStart) )
        v2 = &v12->Stack.Pages.Data.Data[v11 >> 5]->Values[v11 & 0x1F];
      Scaleform::GFx::AS2::Value::operator=(&v16, v2);
    }
    v13 = fn->Env;
    LOBYTE(pHeap) = 0;
    v5->Scaleform::GFx::AS2::ObjectInterface::vfptr->SetMemberRaw(
      &v5->Scaleform::GFx::AS2::ObjectInterface,
      &v13->StringContext,
      (Scaleform::GFx::ASString *)&v13->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[33].pASSupport,
      &ptr,
      (Scaleform::GFx::AS2::PropFlags *)&pHeap);
    LOBYTE(pHeap) = 0;
    v5->Scaleform::GFx::AS2::ObjectInterface::vfptr->SetMemberRaw(
      &v5->Scaleform::GFx::AS2::ObjectInterface,
      &v13->StringContext,
      (Scaleform::GFx::ASString *)&v13->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[33].AVMVersion,
      &v16,
      (Scaleform::GFx::AS2::PropFlags *)&pHeap);
    `eh vector destructor iterator(&ptr, 0x20ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::AS2::Value::~Value);
  }
  if ( v5 )
  {
    RefCount = v5->RefCount;
    if ( (RefCount & 0x3FFFFFF) != 0 )
    {
      v5->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v5);
    }
  }
}unt = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v5);

// File Line: 521
// RVA: 0x6E0770
void __fastcall Scaleform::GFx::AS2::PointCtorFunction::CreateNewObject(
        Scaleform::GFx::AS2::PointCtorFunction *this,
        Scaleform::GFx::AS2::ASStringContext *penv)
{
  Scaleform::GFx::AS2::PointObject *v3; // rax

  v3 = (Scaleform::GFx::AS2::PointObject *)(*(__int64 (__fastcall **)(Scaleform::GFx::AS2::PointCtorFunction *, __int64))(**(_QWORD **)(*(_QWORD *)&penv[14].SWFVersion + 48i64) + 80i64))(
                                             this,
                                             96i64);
  if ( v3 )
    Scaleform::GFx::AS2::PointObject::PointObject(v3, penv);
}

// File Line: 526
// RVA: 0x70E580
Scaleform::GFx::AS2::FunctionRef *__fastcall Scaleform::GFx::AS2::PointCtorFunction::Register(
        Scaleform::GFx::AS2::FunctionRef *result,
        Scaleform::GFx::AS2::GlobalContext *pgc)
{
  Scaleform::GFx::AS2::Object *v4; // rax
  __int64 v5; // rcx
  Scaleform::GFx::AS2::FunctionObject *v6; // rbx
  Scaleform::GFx::AS2::Object *Prototype; // r15
  Scaleform::GFx::AS2::RefCountBaseGC<323> *pObject; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::PointProto *v10; // rbx
  Scaleform::GFx::AS2::Object *v11; // rax
  Scaleform::GFx::AS2::Object *v12; // rax
  Scaleform::GFx::AS2::Object *v13; // rbx
  Scaleform::GFx::ASStringNode *Function; // rax
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // rdx
  unsigned int v16; // eax
  Scaleform::GFx::AS2::ASStringContext psc; // [rsp+40h] [rbp-38h] BYREF
  Scaleform::GFx::AS2::Value v19; // [rsp+50h] [rbp-28h] BYREF
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
    v6[1].Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)Scaleform::GFx::AS2::PointCtorFunction::GlobalCtor;
    Prototype = Scaleform::GFx::AS2::GlobalContext::GetPrototype(psc.pContext, ASBuiltin_Function);
    if ( !v6->pProto.pObject )
    {
      LOBYTE(objproto.pObject) = 3;
      v19.T.Type = 10;
      v6->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr->SetMemberRaw(
        &v6->Scaleform::GFx::AS2::ObjectInterface,
        &psc,
        (Scaleform::GFx::ASString *)&psc.pContext->pMovieRoot->pASMovieRoot.pObject[23].pMovieImpl,
        &v19,
        (Scaleform::GFx::AS2::PropFlags *)&objproto);
      if ( v19.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v19);
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
    v6->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::PointCtorFunction::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
    v6->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::PointCtorFunction::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
    Scaleform::GFx::AS2::NameFunction::AddConstMembers(
      &v6->Scaleform::GFx::AS2::ObjectInterface,
      &psc,
      Scaleform::GFx::AS2::PointCtorFunction::StaticFunctionTable,
      7);
  }
  else
  {
    v6 = 0i64;
  }
  result->Flags = 0;
  result->Function = v6;
  result->pLocalFrame = 0i64;
  objproto.pObject = (Scaleform::GFx::AS2::Object *)pgc->pHeap;
  v10 = (Scaleform::GFx::AS2::PointProto *)((__int64 (__fastcall *)(__int64, __int64, _QWORD))objproto.pObject->vfptr[3].Finalize_GC)(
                                             v5,
                                             160i64,
                                             0i64);
  pHeap = (Scaleform::MemoryHeap *)v10;
  if ( v10 )
  {
    v11 = Scaleform::GFx::AS2::GlobalContext::GetPrototype(pgc, ASBuiltin_Object);
    Scaleform::GFx::AS2::PointProto::PointProto(v10, &psc, v11, result);
    v13 = v12;
  }
  else
  {
    v13 = 0i64;
  }
  pHeap = (Scaleform::MemoryHeap *)v13;
  p_objproto = &objproto;
  if ( v13 )
    v13->RefCount = (v13->RefCount + 1) & 0x8FFFFFFF;
  objproto.pObject = v13;
  Scaleform::GFx::AS2::GlobalContext::SetPrototype(
    pgc,
    ASBuiltin_Point,
    (Scaleform::Ptr<Scaleform::GFx::AS2::Object>)&objproto);
  v19.T.Type = 8;
  v19.V.FunctionValue.Flags = 0;
  Function = (Scaleform::GFx::ASStringNode *)result->Function;
  v19.V.pStringNode = Function;
  if ( Function )
  {
    ++Function->RefCount;
    Function->RefCount &= 0x8FFFFFFF;
  }
  v19.V.FunctionValue.pLocalFrame = 0i64;
  pLocalFrame = result->pLocalFrame;
  if ( pLocalFrame )
    Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(&v19.V.FunctionValue, pLocalFrame, result->Flags & 1);
  LOBYTE(objproto.pObject) = 0;
  pgc->FlashGeomPackage->vfptr->SetMemberRaw(
    &pgc->FlashGeomPackage->Scaleform::GFx::AS2::ObjectInterface,
    &psc,
    (Scaleform::GFx::ASString *)&pgc->pMovieRoot->pASMovieRoot.pObject[10].pASSupport,
    &v19,
    (Scaleform::GFx::AS2::PropFlags *)&objproto);
  if ( v19.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v19);
  if ( v13 )
  {
    v16 = v13->RefCount;
    if ( (v16 & 0x3FFFFFF) != 0 )
    {
      v13->RefCount = v16 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v13);
    }
  }
  return result;
}

