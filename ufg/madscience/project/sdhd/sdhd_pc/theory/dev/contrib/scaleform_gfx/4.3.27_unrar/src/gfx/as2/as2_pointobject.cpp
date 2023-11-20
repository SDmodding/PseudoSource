// File Line: 31
// RVA: 0x1587A30
__int64 Scaleform::GFx::AS2::_dynamic_initializer_for__Point_DefaultParams__()
{
  Point_DefaultParams[1].T.Type = 4;
  Point_DefaultParams[1].NV.Int32Value = 0;
  return atexit(Scaleform::GFx::AS2::_dynamic_atexit_destructor_for__Point_DefaultParams__);
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
  return atexit(Scaleform::GFx::AS2::_dynamic_atexit_destructor_for__Point_NanParams__);
}

// File Line: 54
// RVA: 0x6ED8E0
void __fastcall Scaleform::GFx::AS2::GFxObject_GetPointProperties(Scaleform::GFx::AS2::Environment *penv, Scaleform::GFx::AS2::Object *pobj, Scaleform::Render::Point<double> *pt)
{
  Scaleform::Render::Point<double> *v3; // rbp
  Scaleform::GFx::AS2::Object *v4; // rbx
  Scaleform::GFx::AS2::Environment *v5; // rsi
  long double v6; // xmm6_8
  Scaleform::GFx::AS2::Value ptr; // [rsp+40h] [rbp-58h]
  Scaleform::GFx::AS2::Value v8; // [rsp+60h] [rbp-38h]

  v3 = pt;
  v4 = pobj;
  v5 = penv;
  `eh vector constructor iterator'(&ptr, 0x20ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::AS2::Value::Value);
  ((void (__fastcall *)(Scaleform::GFx::AS2::ObjectInterfaceVtbl **, Scaleform::GFx::AS2::ASStringContext *, Scaleform::Ptr<Scaleform::GFx::ASSupport> *, Scaleform::GFx::AS2::Value *, void (__fastcall *)(Scaleform::GFx::AS2::Value *)))v4->vfptr->GetMemberRaw)(
    &v4->vfptr,
    &v5->StringContext,
    &v5->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[33].pASSupport,
    &ptr,
    Scaleform::GFx::AS2::Value::~Value);
  v4->vfptr->GetMemberRaw(
    (Scaleform::GFx::AS2::ObjectInterface *)&v4->vfptr,
    &v5->StringContext,
    (Scaleform::GFx::ASString *)&v5->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[33].AVMVersion,
    &v8);
  v6 = Scaleform::GFx::AS2::Value::ToNumber(&v8, v5);
  v3->x = Scaleform::GFx::AS2::Value::ToNumber(&ptr, v5);
  v3->y = v6;
  `eh vector destructor iterator'(&ptr, 0x20ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::AS2::Value::~Value);
}

// File Line: 67
// RVA: 0x6CB4C0
void __fastcall Scaleform::GFx::AS2::PointObject::PointObject(Scaleform::GFx::AS2::PointObject *this, Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::ASStringContext *v2; // rbx
  Scaleform::GFx::AS2::PointObject *v3; // rsi
  Scaleform::GFx::AS2::Object *v4; // rax
  char v5; // [rsp+58h] [rbp+10h]

  v2 = (Scaleform::GFx::AS2::ASStringContext *)penv;
  v3 = this;
  Scaleform::GFx::AS2::Object::Object((Scaleform::GFx::AS2::Object *)&this->vfptr, penv);
  v3->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::PointObject::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
  v3->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::PointObject::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  v2 = (Scaleform::GFx::AS2::ASStringContext *)((char *)v2 + 232);
  v4 = Scaleform::GFx::AS2::GlobalContext::GetPrototype(v2->pContext, ASBuiltin_Point);
  Scaleform::GFx::AS2::Object::Set__proto__((Scaleform::GFx::AS2::Object *)&v3->vfptr, v2, v4);
  v5 = 0;
  v3->vfptr->SetMemberRaw(
    (Scaleform::GFx::AS2::ObjectInterface *)&v3->vfptr,
    v2,
    (Scaleform::GFx::ASString *)&v2->pContext->pMovieRoot->pASMovieRoot.pObject[33].pASSupport,
    Point_DefaultParams,
    (Scaleform::GFx::AS2::PropFlags *)&v5);
  v5 = 0;
  v3->vfptr->SetMemberRaw(
    (Scaleform::GFx::AS2::ObjectInterface *)&v3->vfptr,
    v2,
    (Scaleform::GFx::ASString *)&v2->pContext->pMovieRoot->pASMovieRoot.pObject[33].AVMVersion,
    &Point_DefaultParams[1],
    (Scaleform::GFx::AS2::PropFlags *)&v5);
}

// File Line: 85
// RVA: 0x6F2260
char __usercall Scaleform::GFx::AS2::PointObject::GetMember@<al>(Scaleform::GFx::AS2::PointObject *this@<rcx>, Scaleform::GFx::AS2::Environment *penv@<rdx>, Scaleform::GFx::ASString *name@<r8>, Scaleform::GFx::AS2::Value *val@<r9>, __int64 a5@<rdi>)
{
  Scaleform::GFx::AS2::Value *v5; // rbx
  Scaleform::GFx::AS2::Environment *v6; // r9
  Scaleform::GFx::AS2::ASStringContext *v7; // rdx
  __m128d v8; // xmm1
  Scaleform::Render::Point<double> pt; // [rsp+28h] [rbp-40h]
  Scaleform::GFx::AS2::Value v; // [rsp+38h] [rbp-30h]

  v5 = val;
  v6 = penv;
  v7 = &penv->StringContext;
  if ( name->pNode != *(Scaleform::GFx::ASStringNode **)&v7->pContext->pMovieRoot->pASMovieRoot.pObject[38].AVMVersion )
    return ((__int64 (__fastcall *)(Scaleform::GFx::AS2::PointObject *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))this->vfptr[3].~RefCountBaseGC<323>)(
             this,
             v7,
             name,
             v5);
  Scaleform::GFx::AS2::PointObject::GetProperties((Scaleform::GFx::AS2::PointObject *)((char *)this - 32), v6, &pt);
  v8 = (__m128d)*(unsigned __int64 *)&pt.x;
  v8.m128d_f64[0] = v8.m128d_f64[0] * v8.m128d_f64[0] + pt.y * pt.y;
  v.T.Type = 3;
  v.V.pStringNode = (Scaleform::GFx::ASStringNode *)_mm_sqrt_pd(v8);
  Scaleform::GFx::AS2::Value::operator=(v5, &v, a5);
  if ( v.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v);
  return 1;
}

// File Line: 116
// RVA: 0x6F4A10
void __fastcall Scaleform::GFx::AS2::PointObject::GetProperties(Scaleform::GFx::AS2::PointObject *this, Scaleform::GFx::AS2::Environment *penv, Scaleform::Render::Point<double> *pt)
{
  Scaleform::Render::Point<double> *v3; // rbp
  Scaleform::GFx::AS2::Environment *v4; // rsi
  Scaleform::GFx::AS2::PointObject *v5; // rbx
  long double v6; // xmm6_8
  Scaleform::GFx::AS2::Value ptr; // [rsp+40h] [rbp-58h]
  Scaleform::GFx::AS2::Value v8; // [rsp+60h] [rbp-38h]

  v3 = pt;
  v4 = penv;
  v5 = this;
  `eh vector constructor iterator'(&ptr, 0x20ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::AS2::Value::Value);
  ((void (__fastcall *)(Scaleform::GFx::AS2::ObjectInterfaceVtbl **, Scaleform::GFx::AS2::ASStringContext *, Scaleform::Ptr<Scaleform::GFx::ASSupport> *, Scaleform::GFx::AS2::Value *, void (__fastcall *)(Scaleform::GFx::AS2::Value *)))v5->vfptr->GetMemberRaw)(
    &v5->vfptr,
    &v4->StringContext,
    &v4->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[33].pASSupport,
    &ptr,
    Scaleform::GFx::AS2::Value::~Value);
  v5->vfptr->GetMemberRaw(
    (Scaleform::GFx::AS2::ObjectInterface *)&v5->vfptr,
    &v4->StringContext,
    (Scaleform::GFx::ASString *)&v4->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[33].AVMVersion,
    &v8);
  v6 = Scaleform::GFx::AS2::Value::ToNumber(&v8, v4);
  v3->x = Scaleform::GFx::AS2::Value::ToNumber(&ptr, v4);
  v3->y = v6;
  `eh vector destructor iterator'(&ptr, 0x20ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::AS2::Value::~Value);
}

// File Line: 135
// RVA: 0x71AA60
void __fastcall Scaleform::GFx::AS2::PointObject::SetProperties(Scaleform::GFx::AS2::PointObject *this, Scaleform::GFx::AS2::Environment *penv, Scaleform::Render::Point<double> *pt)
{
  Scaleform::Render::Point<double> *v3; // rsi
  Scaleform::GFx::AS2::ASStringContext *v4; // rbx
  long double v5; // xmm0_8
  Scaleform::GFx::AS2::ObjectInterface *v6; // rdi
  Scaleform::GFx::ASStringNode *v7; // xmm0_8
  Scaleform::GFx::AS2::Value v8; // [rsp+38h] [rbp-30h]
  char v9; // [rsp+70h] [rbp+8h]

  v3 = pt;
  v4 = &penv->StringContext;
  v5 = pt->x;
  v8.T.Type = 3;
  v8.NV.NumberValue = v5;
  v9 = 0;
  v6 = (Scaleform::GFx::AS2::ObjectInterface *)&this->vfptr;
  this->vfptr->SetMemberRaw(
    (Scaleform::GFx::AS2::ObjectInterface *)&this->vfptr,
    &penv->StringContext,
    (Scaleform::GFx::ASString *)&penv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[33].pASSupport,
    &v8,
    (Scaleform::GFx::AS2::PropFlags *)&v9);
  if ( v8.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v8);
  v7 = *(Scaleform::GFx::ASStringNode **)&v3->y;
  v8.T.Type = 3;
  v8.V.pStringNode = v7;
  v9 = 0;
  v6->vfptr->SetMemberRaw(
    v6,
    v4,
    (Scaleform::GFx::ASString *)&v4->pContext->pMovieRoot->pASMovieRoot.pObject[33].AVMVersion,
    &v8,
    (Scaleform::GFx::AS2::PropFlags *)&v9);
  if ( v8.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v8);
}

// File Line: 161
// RVA: 0x6CB5B0
void __fastcall Scaleform::GFx::AS2::PointProto::PointProto(Scaleform::GFx::AS2::PointProto *this, Scaleform::GFx::AS2::ASStringContext *psc, Scaleform::GFx::AS2::Object *pprototype, Scaleform::GFx::AS2::FunctionRef *constructor)
{
  Scaleform::GFx::AS2::ASStringContext *v4; // rdi
  Scaleform::GFx::AS2::PointProto *v5; // rsi
  Scaleform::GFx::ASString *v6; // rax
  Scaleform::GFx::ASStringNode *v7; // rcx
  bool v8; // zf
  Scaleform::GFx::AS2::PropFlags flags; // [rsp+30h] [rbp-48h]
  Scaleform::GFx::ASString result; // [rsp+38h] [rbp-40h]
  __int64 v11; // [rsp+40h] [rbp-38h]
  Scaleform::GFx::AS2::Value val; // [rsp+48h] [rbp-30h]

  v11 = -2i64;
  v4 = psc;
  v5 = this;
  Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::PointObject,Scaleform::GFx::AS2::Environment>::Prototype<Scaleform::GFx::AS2::PointObject,Scaleform::GFx::AS2::Environment>(
    (Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::PointObject,Scaleform::GFx::AS2::Environment> *)&this->vfptr,
    psc,
    pprototype,
    constructor);
  v5->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::PointProto::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
  v5->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::PointProto::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  v5->vfptr = (Scaleform::GFx::AS2::GASPrototypeBaseVtbl *)&Scaleform::GFx::AS2::PointProto::`vftable';
  flags.Flags = 6;
  Scaleform::GFx::AS2::GASPrototypeBase::InitFunctionMembers(
    (Scaleform::GFx::AS2::GASPrototypeBase *)&v5->vfptr,
    (Scaleform::GFx::AS2::Object *)&v5->vfptr,
    v4,
    Scaleform::GFx::AS2::PointProto::FunctionTable,
    &flags);
  flags.Flags = 2;
  val.T.Type = 4;
  val.NV.Int32Value = 0;
  v6 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v4, &result, "length");
  Scaleform::GFx::AS2::Object::SetMemberRaw((Scaleform::GFx::AS2::Object *)&v5->vfptr, v4, v6, &val, &flags);
  v7 = result.pNode;
  v8 = result.pNode->RefCount == 1;
  --v7->RefCount;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v7);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
}

// File Line: 174
// RVA: 0x6A6EA0
void __fastcall Scaleform::GFx::AS2::PointProto::Add(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rsi
  Scaleform::GFx::AS2::PointObject *v2; // rax
  Scaleform::GFx::AS2::PointObject *v3; // rbx
  Scaleform::GFx::AS2::PointObject *v4; // rax
  Scaleform::GFx::AS2::PointObject *v5; // rbp
  unsigned int v6; // er10
  Scaleform::GFx::AS2::Environment *v7; // rdx
  Scaleform::GFx::AS2::Value *v8; // r9
  Scaleform::GFx::AS2::Object *v9; // rdi
  Scaleform::GFx::AS2::ObjectInterface *v10; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v11; // rax
  Scaleform::GFx::AS2::Environment *v12; // rdi
  unsigned int v13; // eax
  Scaleform::Render::Point<double> pt; // [rsp+38h] [rbp-40h]
  Scaleform::Render::Point<double> v15; // [rsp+48h] [rbp-30h]
  Scaleform::MemoryHeap *v16; // [rsp+80h] [rbp+8h]
  Scaleform::GFx::AS2::PointObject *v17; // [rsp+88h] [rbp+10h]

  v1 = fn;
  v16 = fn->Env->StringContext.pContext->pHeap;
  v2 = (Scaleform::GFx::AS2::PointObject *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::FnCall *, signed __int64))v16->vfptr->Alloc)(
                                             fn,
                                             96i64);
  v17 = v2;
  v3 = 0i64;
  if ( v2 )
  {
    Scaleform::GFx::AS2::PointObject::PointObject(v2, v1->Env);
    v5 = v4;
  }
  else
  {
    v5 = 0i64;
  }
  v17 = v5;
  if ( v1->NArgs <= 0 )
    goto LABEL_21;
  v6 = v1->FirstArgBottomIndex;
  v7 = v1->Env;
  v8 = 0i64;
  if ( v6 <= 32 * ((unsigned int)v7->Stack.Pages.Data.Size - 1)
           + (unsigned int)((_QWORD)((char *)v7->Stack.pCurrent - (char *)v7->Stack.pPageStart) >> 5) )
    v8 = &v7->Stack.Pages.Data.Data[v6 >> 5]->Values[v6 & 0x1F];
  v9 = Scaleform::GFx::AS2::Value::ToObject(v8, v7);
  if ( v9 )
  {
    v10 = v1->ThisPtr;
    if ( !v10 || (*(unsigned int (**)(void))&v10->vfptr->gap8[8])() != 16 )
    {
      Scaleform::GFx::AS2::Environment::LogScriptError(
        v1->Env,
        "Error: Null or invalid 'this' is used for a method of %s class.\n",
        "Point");
      goto LABEL_16;
    }
    v11 = v1->ThisPtr;
    if ( v11 )
      v3 = (Scaleform::GFx::AS2::PointObject *)&v11[-2];
    Scaleform::GFx::AS2::PointObject::GetProperties(v3, v1->Env, &pt);
    Scaleform::GFx::AS2::GFxObject_GetPointProperties(v1->Env, v9, &v15);
    pt.x = pt.x + v15.x;
    pt.y = pt.y + v15.y;
    Scaleform::GFx::AS2::PointObject::SetProperties(v5, v1->Env, &pt);
  }
  else
  {
LABEL_21:
    v12 = v1->Env;
    LOBYTE(v16) = 0;
    v5->vfptr->SetMemberRaw(
      (Scaleform::GFx::AS2::ObjectInterface *)&v5->vfptr,
      &v12->StringContext,
      (Scaleform::GFx::ASString *)&v12->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[33].pASSupport,
      Point_NanParams,
      (Scaleform::GFx::AS2::PropFlags *)&v16);
    LOBYTE(v16) = 0;
    v5->vfptr->SetMemberRaw(
      (Scaleform::GFx::AS2::ObjectInterface *)&v5->vfptr,
      &v12->StringContext,
      (Scaleform::GFx::ASString *)&v12->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[33].AVMVersion,
      (Scaleform::GFx::AS2::Value *)&byte_14243A450,
      (Scaleform::GFx::AS2::PropFlags *)&v16);
  }
  Scaleform::GFx::AS2::Value::SetAsObject(v1->Result, (Scaleform::GFx::AS2::Object *)&v5->vfptr);
LABEL_16:
  if ( v5 )
  {
    v13 = v5->RefCount;
    if ( v13 & 0x3FFFFFF )
    {
      v5->RefCount = v13 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v5->vfptr);
    }
  }
}

// File Line: 208
// RVA: 0x6A70D0
void __fastcall Scaleform::GFx::AS2::PointProto::Clone(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rsi
  Scaleform::GFx::AS2::ObjectInterface *v2; // rcx
  __int64 v3; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v4; // rax
  Scaleform::GFx::AS2::Object *v5; // rbp
  signed __int64 v6; // rbx
  Scaleform::GFx::AS2::PointObject *v7; // rax
  Scaleform::GFx::AS2::Object *v8; // rax
  signed __int64 v9; // rdi
  unsigned int v10; // eax
  Scaleform::GFx::AS2::Value ptr; // [rsp+40h] [rbp-58h]
  Scaleform::GFx::AS2::Value v12; // [rsp+60h] [rbp-38h]
  Scaleform::MemoryHeap *v13; // [rsp+A0h] [rbp+8h]
  Scaleform::GFx::AS2::PointObject *v14; // [rsp+A8h] [rbp+10h]

  v1 = fn;
  v2 = fn->ThisPtr;
  if ( v2 && (*(unsigned int (**)(void))&v2->vfptr->gap8[8])() == 16 )
  {
    v4 = v1->ThisPtr;
    v5 = 0i64;
    v6 = (signed __int64)&v4[-2];
    if ( !v4 )
      v6 = 0i64;
    v13 = v1->Env->StringContext.pContext->pHeap;
    v7 = (Scaleform::GFx::AS2::PointObject *)((__int64 (__fastcall *)(__int64, signed __int64))v13->vfptr->Alloc)(
                                               v3,
                                               96i64);
    v14 = v7;
    if ( v7 )
    {
      Scaleform::GFx::AS2::PointObject::PointObject(v7, v1->Env);
      v5 = v8;
    }
    v14 = (Scaleform::GFx::AS2::PointObject *)v5;
    v9 = (signed __int64)&v1->Env->StringContext;
    `eh vector constructor iterator'(&ptr, 0x20ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::AS2::Value::Value);
    (*(void (__fastcall **)(signed __int64, signed __int64, signed __int64, char *, void (__fastcall *)(Scaleform::GFx::AS2::Value *)))(*(_QWORD *)(v6 + 32) + 88i64))(
      v6 + 32,
      v9,
      *(_QWORD *)(*(_QWORD *)(*(_QWORD *)v9 + 40i64) + 24i64) + 1344i64,
      &ptr.T.Type,
      Scaleform::GFx::AS2::Value::~Value);
    (*(void (__fastcall **)(signed __int64, signed __int64, signed __int64, char *))(*(_QWORD *)(v6 + 32) + 88i64))(
      v6 + 32,
      v9,
      *(_QWORD *)(*(_QWORD *)(*(_QWORD *)v9 + 40i64) + 24i64) + 1352i64,
      &v12.T.Type);
    LOBYTE(v13) = 0;
    v5->vfptr->SetMemberRaw(
      (Scaleform::GFx::AS2::ObjectInterface *)&v5->vfptr,
      (Scaleform::GFx::AS2::ASStringContext *)v9,
      (Scaleform::GFx::ASString *)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)v9 + 40i64) + 24i64) + 1344i64),
      &ptr,
      (Scaleform::GFx::AS2::PropFlags *)&v13);
    LOBYTE(v13) = 0;
    v5->vfptr->SetMemberRaw(
      (Scaleform::GFx::AS2::ObjectInterface *)&v5->vfptr,
      (Scaleform::GFx::AS2::ASStringContext *)v9,
      (Scaleform::GFx::ASString *)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)v9 + 40i64) + 24i64) + 1352i64),
      &v12,
      (Scaleform::GFx::AS2::PropFlags *)&v13);
    Scaleform::GFx::AS2::Value::SetAsObject(v1->Result, v5);
    `eh vector destructor iterator'(&ptr, 0x20ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::AS2::Value::~Value);
    v10 = v5->RefCount;
    if ( v10 & 0x3FFFFFF )
    {
      v5->RefCount = v10 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v5->vfptr);
    }
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      v1->Env,
      "Error: Null or invalid 'this' is used for a method of %s class.\n",
      "Point");
  }
}

// File Line: 228
// RVA: 0x6A72D0
void __fastcall Scaleform::GFx::AS2::PointProto::Equals(Scaleform::GFx::AS2::FnCall *fn)
{
  bool v1; // di
  Scaleform::GFx::AS2::FnCall *v2; // rbx
  Scaleform::GFx::AS2::Environment *v3; // r9
  unsigned __int64 v4; // r8
  Scaleform::GFx::AS2::PointObject *v5; // rbp
  Scaleform::GFx::AS2::Value *v6; // rcx
  Scaleform::GFx::AS2::Object *v7; // rax
  Scaleform::GFx::AS2::Object *v8; // rsi
  Scaleform::GFx::AS2::ObjectInterface *v9; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v10; // rax
  Scaleform::GFx::AS2::Value *v11; // rbx
  Scaleform::Render::Point<double> pt; // [rsp+20h] [rbp-28h]
  Scaleform::Render::Point<double> v13; // [rsp+30h] [rbp-18h]

  v1 = 0;
  v2 = fn;
  if ( fn->NArgs <= 0 )
    goto LABEL_13;
  v3 = fn->Env;
  v4 = (unsigned int)fn->FirstArgBottomIndex;
  v5 = 0i64;
  v6 = 0i64;
  if ( (unsigned int)v4 <= 32 * (LODWORD(v3->Stack.Pages.Data.Size) - 1)
                         + (unsigned int)((_QWORD)((char *)v3->Stack.pCurrent - (char *)v3->Stack.pPageStart) >> 5) )
    v6 = &v3->Stack.Pages.Data.Data[v4 >> 5]->Values[v4 & 0x1F];
  v7 = Scaleform::GFx::AS2::Value::ToObject(v6, v3);
  v8 = v7;
  if ( !v7
    || (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterfaceVtbl **))&v7->vfptr->gap8[8])(&v7->vfptr) != 16 )
  {
    goto LABEL_13;
  }
  v9 = v2->ThisPtr;
  if ( v9 && (*(unsigned int (**)(void))&v9->vfptr->gap8[8])() == 16 )
  {
    v10 = v2->ThisPtr;
    if ( v10 )
      v5 = (Scaleform::GFx::AS2::PointObject *)&v10[-2];
    Scaleform::GFx::AS2::PointObject::GetProperties(v5, v2->Env, &pt);
    Scaleform::GFx::AS2::GFxObject_GetPointProperties(v2->Env, v8, &v13);
    v1 = pt.x == v13.x && pt.y == v13.y;
LABEL_13:
    v11 = v2->Result;
    Scaleform::GFx::AS2::Value::DropRefs(v11);
    v11->T.Type = 2;
    v11->V.BooleanValue = v1;
    return;
  }
  Scaleform::GFx::AS2::Environment::LogScriptError(
    v2->Env,
    "Error: Null or invalid 'this' is used for a method of %s class.\n",
    "Point");
}

// File Line: 255
// RVA: 0x6A7400
void __fastcall Scaleform::GFx::AS2::PointProto::Normalize(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rbx
  Scaleform::GFx::AS2::ObjectInterface *v2; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rax
  Scaleform::GFx::AS2::Value *v4; // rdx
  Scaleform::GFx::AS2::PointObject *v5; // rsi
  unsigned int v6; // er9
  Scaleform::GFx::AS2::Environment *v7; // r8
  double v8; // xmm8_8
  double v9; // xmm7_8
  long double v10; // xmm0_8
  Scaleform::GFx::AS2::Environment *v11; // rdi
  Scaleform::Render::Point<double> pt; // [rsp+38h] [rbp-70h]
  Scaleform::GFx::AS2::Value v13; // [rsp+48h] [rbp-60h]
  char v14; // [rsp+B0h] [rbp+8h]

  v1 = fn;
  v2 = fn->ThisPtr;
  if ( v2 && (*(unsigned int (**)(void))&v2->vfptr->gap8[8])() == 16 )
  {
    v3 = v1->ThisPtr;
    v4 = 0i64;
    v5 = (Scaleform::GFx::AS2::PointObject *)&v3[-2];
    if ( !v3 )
      v5 = 0i64;
    if ( v1->NArgs <= 0 )
    {
      v11 = v1->Env;
      v14 = 0;
      v5->vfptr->SetMemberRaw(
        (Scaleform::GFx::AS2::ObjectInterface *)&v5->vfptr,
        &v11->StringContext,
        (Scaleform::GFx::ASString *)&v11->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[33].pASSupport,
        Point_NanParams,
        (Scaleform::GFx::AS2::PropFlags *)&v14);
      v14 = 0;
      v5->vfptr->SetMemberRaw(
        (Scaleform::GFx::AS2::ObjectInterface *)&v5->vfptr,
        &v11->StringContext,
        (Scaleform::GFx::ASString *)&v11->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[33].AVMVersion,
        (Scaleform::GFx::AS2::Value *)&byte_14243A450,
        (Scaleform::GFx::AS2::PropFlags *)&v14);
    }
    else
    {
      v6 = v1->FirstArgBottomIndex;
      v7 = v1->Env;
      if ( v6 <= 32 * ((unsigned int)v7->Stack.Pages.Data.Size - 1)
               + (unsigned int)((_QWORD)((char *)v7->Stack.pCurrent - (char *)v7->Stack.pPageStart) >> 5) )
        v4 = &v7->Stack.Pages.Data.Data[v6 >> 5]->Values[v6 & 0x1F];
      Scaleform::GFx::AS2::Value::Value(&v13, v4);
      Scaleform::GFx::AS2::PointObject::GetProperties(v5, v1->Env, &pt);
      v8 = pt.y;
      v9 = pt.x;
      v10 = Scaleform::GFx::AS2::Value::ToNumber(&v13, v1->Env) / sqrt(v8 * v8 + v9 * v9);
      pt.x = v9 * v10;
      pt.y = v8 * v10;
      Scaleform::GFx::AS2::PointObject::SetProperties(v5, v1->Env, &pt);
      if ( v13.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v13);
    }
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      v1->Env,
      "Error: Null or invalid 'this' is used for a method of %s class.\n",
      "Point");
  }
}

// File Line: 279
// RVA: 0x6A7600
void __fastcall Scaleform::GFx::AS2::PointProto::Offset(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rbx
  Scaleform::GFx::AS2::ObjectInterface *v2; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rax
  Scaleform::GFx::AS2::Value *v4; // rdi
  Scaleform::GFx::AS2::PointObject *v5; // rbp
  char v6; // si
  unsigned int v7; // er9
  Scaleform::GFx::AS2::Environment *v8; // r8
  Scaleform::GFx::AS2::Value *v9; // rdx
  unsigned int v10; // edx
  Scaleform::GFx::AS2::Environment *v11; // r8
  double v12; // xmm6_8
  long double v13; // xmm0_8
  Scaleform::Render::Point<double> pt; // [rsp+28h] [rbp-70h]
  Scaleform::GFx::AS2::Value v15; // [rsp+38h] [rbp-60h]
  Scaleform::GFx::AS2::Value v16; // [rsp+58h] [rbp-40h]

  v1 = fn;
  v2 = fn->ThisPtr;
  if ( v2 && (*(unsigned int (__cdecl **)(Scaleform::GFx::AS2::ObjectInterface *))&v2->vfptr->gap8[8])(v2) == 16 )
  {
    v3 = v1->ThisPtr;
    v4 = 0i64;
    v5 = (Scaleform::GFx::AS2::PointObject *)&v3[-2];
    if ( !v3 )
      v5 = 0i64;
    v16.T.Type = 0;
    v6 = 0;
    v15.T.Type = 0;
    if ( v1->NArgs > 0 )
    {
      v7 = v1->FirstArgBottomIndex;
      v8 = v1->Env;
      v9 = 0i64;
      if ( v7 <= 32 * ((unsigned int)v8->Stack.Pages.Data.Size - 1)
               + (unsigned int)((_QWORD)((char *)v8->Stack.pCurrent - (char *)v8->Stack.pPageStart) >> 5) )
        v9 = &v8->Stack.Pages.Data.Data[v7 >> 5]->Values[v7 & 0x1F];
      Scaleform::GFx::AS2::Value::operator=(&v16, v9);
      if ( v1->NArgs > 1 )
      {
        v10 = v1->FirstArgBottomIndex - 1;
        v11 = v1->Env;
        if ( v10 <= 32 * ((unsigned int)v11->Stack.Pages.Data.Size - 1)
                  + (unsigned int)((_QWORD)((char *)v11->Stack.pCurrent - (char *)v11->Stack.pPageStart) >> 5) )
          v4 = &v11->Stack.Pages.Data.Data[v10 >> 5]->Values[v10 & 0x1F];
        Scaleform::GFx::AS2::Value::operator=(&v15, v4);
        v6 = v15.T.Type;
      }
    }
    Scaleform::GFx::AS2::PointObject::GetProperties(v5, v1->Env, &pt);
    v12 = Scaleform::GFx::AS2::Value::ToNumber(&v15, v1->Env);
    v13 = Scaleform::GFx::AS2::Value::ToNumber(&v16, v1->Env);
    pt.x = pt.x + v13;
    pt.y = pt.y + v12;
    Scaleform::GFx::AS2::PointObject::SetProperties(v5, v1->Env, &pt);
    if ( (unsigned __int8)v6 >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v15);
    if ( v16.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v16);
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      v1->Env,
      "Error: Null or invalid 'this' is used for a method of %s class.\n",
      "Point");
  }
}

// File Line: 303
// RVA: 0x6A77D0
void __fastcall Scaleform::GFx::AS2::PointProto::Subtract(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rsi
  Scaleform::GFx::AS2::PointObject *v2; // rax
  Scaleform::GFx::AS2::PointObject *v3; // rbx
  Scaleform::GFx::AS2::PointObject *v4; // rax
  Scaleform::GFx::AS2::PointObject *v5; // rbp
  unsigned int v6; // er10
  Scaleform::GFx::AS2::Environment *v7; // rdx
  Scaleform::GFx::AS2::Value *v8; // r9
  Scaleform::GFx::AS2::Object *v9; // rdi
  Scaleform::GFx::AS2::ObjectInterface *v10; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v11; // rax
  Scaleform::GFx::AS2::Environment *v12; // rdi
  unsigned int v13; // eax
  Scaleform::Render::Point<double> pt; // [rsp+38h] [rbp-40h]
  Scaleform::Render::Point<double> v15; // [rsp+48h] [rbp-30h]
  Scaleform::MemoryHeap *v16; // [rsp+80h] [rbp+8h]
  Scaleform::GFx::AS2::PointObject *v17; // [rsp+88h] [rbp+10h]

  v1 = fn;
  v16 = fn->Env->StringContext.pContext->pHeap;
  v2 = (Scaleform::GFx::AS2::PointObject *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::FnCall *, signed __int64))v16->vfptr->Alloc)(
                                             fn,
                                             96i64);
  v17 = v2;
  v3 = 0i64;
  if ( v2 )
  {
    Scaleform::GFx::AS2::PointObject::PointObject(v2, v1->Env);
    v5 = v4;
  }
  else
  {
    v5 = 0i64;
  }
  v17 = v5;
  if ( v1->NArgs <= 0 )
    goto LABEL_21;
  v6 = v1->FirstArgBottomIndex;
  v7 = v1->Env;
  v8 = 0i64;
  if ( v6 <= 32 * ((unsigned int)v7->Stack.Pages.Data.Size - 1)
           + (unsigned int)((_QWORD)((char *)v7->Stack.pCurrent - (char *)v7->Stack.pPageStart) >> 5) )
    v8 = &v7->Stack.Pages.Data.Data[v6 >> 5]->Values[v6 & 0x1F];
  v9 = Scaleform::GFx::AS2::Value::ToObject(v8, v7);
  if ( v9 )
  {
    v10 = v1->ThisPtr;
    if ( !v10 || (*(unsigned int (**)(void))&v10->vfptr->gap8[8])() != 16 )
    {
      Scaleform::GFx::AS2::Environment::LogScriptError(
        v1->Env,
        "Error: Null or invalid 'this' is used for a method of %s class.\n",
        "Point");
      goto LABEL_16;
    }
    v11 = v1->ThisPtr;
    if ( v11 )
      v3 = (Scaleform::GFx::AS2::PointObject *)&v11[-2];
    Scaleform::GFx::AS2::PointObject::GetProperties(v3, v1->Env, &pt);
    Scaleform::GFx::AS2::GFxObject_GetPointProperties(v1->Env, v9, &v15);
    pt.x = pt.x - v15.x;
    pt.y = pt.y - v15.y;
    Scaleform::GFx::AS2::PointObject::SetProperties(v5, v1->Env, &pt);
  }
  else
  {
LABEL_21:
    v12 = v1->Env;
    LOBYTE(v16) = 0;
    v5->vfptr->SetMemberRaw(
      (Scaleform::GFx::AS2::ObjectInterface *)&v5->vfptr,
      &v12->StringContext,
      (Scaleform::GFx::ASString *)&v12->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[33].pASSupport,
      Point_NanParams,
      (Scaleform::GFx::AS2::PropFlags *)&v16);
    LOBYTE(v16) = 0;
    v5->vfptr->SetMemberRaw(
      (Scaleform::GFx::AS2::ObjectInterface *)&v5->vfptr,
      &v12->StringContext,
      (Scaleform::GFx::ASString *)&v12->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[33].AVMVersion,
      (Scaleform::GFx::AS2::Value *)&byte_14243A450,
      (Scaleform::GFx::AS2::PropFlags *)&v16);
  }
  Scaleform::GFx::AS2::Value::SetAsObject(v1->Result, (Scaleform::GFx::AS2::Object *)&v5->vfptr);
LABEL_16:
  if ( v5 )
  {
    v13 = v5->RefCount;
    if ( v13 & 0x3FFFFFF )
    {
      v5->RefCount = v13 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v5->vfptr);
    }
  }
}

// File Line: 337
// RVA: 0x6A7A20
void __fastcall Scaleform::GFx::AS2::PointProto::ToString(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rsi
  Scaleform::GFx::AS2::ObjectInterface *v2; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rax
  signed __int64 v4; // rbx
  Scaleform::GFx::AS2::Environment *v5; // rdi
  Scaleform::GFx::ASString *v6; // r14
  Scaleform::GFx::AS2::Value *v7; // rdi
  Scaleform::GFx::ASStringNode *v8; // rax
  Scaleform::GFx::ASStringNode *v9; // rcx
  bool v10; // zf
  Scaleform::GFx::ASString result; // [rsp+38h] [rbp-70h]
  Scaleform::GFx::ASString v12; // [rsp+40h] [rbp-68h]
  Scaleform::GFx::AS2::Value ptr; // [rsp+50h] [rbp-58h]
  Scaleform::GFx::AS2::Value v14; // [rsp+70h] [rbp-38h]
  Scaleform::String str; // [rsp+B0h] [rbp+8h]
  Scaleform::GFx::ASString v16; // [rsp+B8h] [rbp+10h]

  v1 = fn;
  v2 = fn->ThisPtr;
  if ( v2 && (*(unsigned int (**)(void))&v2->vfptr->gap8[8])() == 16 )
  {
    v3 = v1->ThisPtr;
    if ( v3 )
    {
      v4 = (signed __int64)&v3[-2];
      if ( v3 != (Scaleform::GFx::AS2::ObjectInterface *)32 )
      {
        `eh vector constructor iterator'(
          &ptr,
          0x20ui64,
          2,
          (void (__fastcall *)(void *))Scaleform::GFx::AS2::Value::Value);
        v5 = v1->Env;
        (*(void (__fastcall **)(signed __int64, Scaleform::GFx::AS2::ASStringContext *, Scaleform::Ptr<Scaleform::GFx::ASSupport> *, char *, void (__fastcall *)(Scaleform::GFx::AS2::Value *)))(*(_QWORD *)(v4 + 32) + 88i64))(
          v4 + 32,
          &v5->StringContext,
          &v5->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[33].pASSupport,
          &ptr.T.Type,
          Scaleform::GFx::AS2::Value::~Value);
        (*(void (__fastcall **)(signed __int64, Scaleform::GFx::AS2::ASStringContext *, char *, Scaleform::GFx::AS2::Value *))(*(_QWORD *)(v4 + 32) + 88i64))(
          v4 + 32,
          &v5->StringContext,
          &v5->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[33].AVMVersion,
          &v14);
        Scaleform::GFx::AS2::Value::ToString(&ptr, &result, v1->Env, 6);
        Scaleform::GFx::AS2::Value::ToString(&v14, &v12, v1->Env, 6);
        Scaleform::String::String(&str);
        Scaleform::String::AppendString(&str, "(x=", -1i64);
        Scaleform::String::AppendString(&str, result.pNode->pData, -1i64);
        Scaleform::String::AppendString(&str, ", y=", -1i64);
        Scaleform::String::AppendString(&str, v12.pNode->pData, -1i64);
        Scaleform::String::AppendString(&str, ")", -1i64);
        v6 = Scaleform::GFx::AS2::Environment::CreateString(v1->Env, &v16, &str);
        v7 = v1->Result;
        if ( v7->T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(v1->Result);
        v7->T.Type = 5;
        v8 = v6->pNode;
        v7->NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)v6->pNode;
        ++v8->RefCount;
        v9 = v16.pNode;
        v10 = v16.pNode->RefCount == 1;
        --v9->RefCount;
        if ( v10 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v9);
        if ( _InterlockedExchangeAdd(
               (volatile signed __int32 *)((str.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8),
               0xFFFFFFFF) == 1 )
          ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
        `eh vector destructor iterator'(
          &result,
          8ui64,
          2,
          (void (__fastcall *)(void *))Scaleform::GFx::ASString::~ASString);
        `eh vector destructor iterator'(
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
      v1->Env,
      "Error: Null or invalid 'this' is used for a method of %s class.\n",
      "Point");
  }
}

// File Line: 389
// RVA: 0x6A7C90
void __fastcall Scaleform::GFx::AS2::PointCtorFunction::Distance(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rsi
  double v2; // xmm0_8
  Scaleform::GFx::AS2::Value *v3; // rbx
  unsigned int v4; // er10
  Scaleform::GFx::AS2::Environment *v5; // rdx
  Scaleform::GFx::AS2::Value *v6; // rbx
  Scaleform::GFx::AS2::Value *v7; // r9
  Scaleform::GFx::AS2::Object *v8; // rdi
  unsigned int v9; // er9
  Scaleform::GFx::AS2::Environment *v10; // r10
  Scaleform::GFx::AS2::Object *v11; // rax
  Scaleform::GFx::AS2::Object *v12; // r14
  signed __int64 v13; // rdi
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
  Scaleform::GFx::AS2::Value v31; // [rsp+30h] [rbp-B8h]
  Scaleform::GFx::AS2::Value v32; // [rsp+50h] [rbp-98h]
  __int64 v33; // [rsp+70h] [rbp-78h]
  Scaleform::GFx::AS2::Value v34; // [rsp+78h] [rbp-70h]
  Scaleform::GFx::AS2::Value v35; // [rsp+A8h] [rbp-40h]
  Scaleform::GFx::AS2::Value ptr; // [rsp+C8h] [rbp-20h]
  Scaleform::GFx::AS2::Value v37; // [rsp+E8h] [rbp+0h]

  v33 = -2i64;
  v1 = fn;
  v2 = Scaleform::GFx::NumberUtil::NaN();
  v3 = v1->Result;
  if ( v3->T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(v1->Result);
  v3->T.Type = 3;
  v3->NV.NumberValue = v2;
  if ( v1->NArgs > 1 )
  {
    v4 = v1->FirstArgBottomIndex;
    v5 = v1->Env;
    v6 = 0i64;
    v7 = 0i64;
    if ( v4 <= 32 * ((unsigned int)v5->Stack.Pages.Data.Size - 1)
             + (unsigned int)((_QWORD)((char *)v5->Stack.pCurrent - (char *)v5->Stack.pPageStart) >> 5) )
      v7 = &v5->Stack.Pages.Data.Data[v4 >> 5]->Values[v4 & 0x1F];
    v8 = Scaleform::GFx::AS2::Value::ToObject(v7, v5);
    v9 = v1->FirstArgBottomIndex - 1;
    v10 = v1->Env;
    if ( v9 <= 32 * ((unsigned int)v10->Stack.Pages.Data.Size - 1)
             + (unsigned int)((_QWORD)((char *)v10->Stack.pCurrent - (char *)v10->Stack.pPageStart) >> 5) )
      v6 = &v10->Stack.Pages.Data.Data[v9 >> 5]->Values[v9 & 0x1F];
    v11 = Scaleform::GFx::AS2::Value::ToObject(v6, v1->Env);
    v12 = v11;
    if ( v8 && v11 )
    {
      v13 = (signed __int64)&v8->vfptr;
      if ( (*(unsigned int (__fastcall **)(signed __int64))(*(_QWORD *)v13 + 16i64))(v13) == 16
        || (*(unsigned int (**)(void))&v12->vfptr->gap8[8])() == 16 )
      {
        `eh vector constructor iterator'(
          &ptr,
          0x20ui64,
          2,
          (void (__fastcall *)(void *))Scaleform::GFx::AS2::Value::Value);
        `eh vector constructor iterator'(
          &v34.NV + 1,
          0x20ui64,
          2,
          (void (__fastcall *)(void *))Scaleform::GFx::AS2::Value::Value);
        v15 = v1->Env;
        (*(void (__fastcall **)(signed __int64, Scaleform::GFx::AS2::ASStringContext *, Scaleform::Ptr<Scaleform::GFx::ASSupport> *, char *, void (__fastcall *)(Scaleform::GFx::AS2::Value *)))(*(_QWORD *)v13 + 88i64))(
          v13,
          &v15->StringContext,
          &v15->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[33].pASSupport,
          &ptr.T.Type,
          Scaleform::GFx::AS2::Value::~Value);
        (*(void (__fastcall **)(signed __int64, Scaleform::GFx::AS2::ASStringContext *, char *, Scaleform::GFx::AS2::Value *))(*(_QWORD *)v13 + 88i64))(
          v13,
          &v15->StringContext,
          &v15->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[33].AVMVersion,
          &v37);
        v16 = v1->Env;
        v12->vfptr->GetMemberRaw(
          (Scaleform::GFx::AS2::ObjectInterface *)&v12->vfptr,
          &v16->StringContext,
          (Scaleform::GFx::ASString *)&v16->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[33].pASSupport,
          (Scaleform::GFx::AS2::Value *)((char *)&v34 + 16));
        v12->vfptr->GetMemberRaw(
          (Scaleform::GFx::AS2::ObjectInterface *)&v12->vfptr,
          &v16->StringContext,
          (Scaleform::GFx::ASString *)&v16->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[33].AVMVersion,
          &v35);
        Scaleform::GFx::AS2::Value::Value(&v31, (Scaleform::GFx::AS2::Value *)((char *)&v34 + 16));
        v17 = v1->Env;
        v18 = Scaleform::GFx::AS2::Value::ToNumber(&v31, v1->Env);
        v19 = Scaleform::GFx::AS2::Value::ToNumber(&ptr, v17);
        if ( v31.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&v31);
        v31.T.Type = 3;
        v31.NV.NumberValue = v18 - v19;
        v20 = v1->Env;
        v21 = Scaleform::GFx::AS2::Value::ToNumber(&v31, v1->Env);
        v22 = Scaleform::GFx::AS2::Value::ToNumber(&v31, v20);
        v31.T.Type = 3;
        v31.NV.NumberValue = v22 * v21;
        Scaleform::GFx::AS2::Value::Value(&v32, &v35);
        v23 = v1->Env;
        v24 = Scaleform::GFx::AS2::Value::ToNumber(&v32, v1->Env);
        v25 = Scaleform::GFx::AS2::Value::ToNumber(&v37, v23);
        if ( v32.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&v32);
        v32.T.Type = 3;
        v32.NV.NumberValue = v24 - v25;
        v26 = v1->Env;
        v27 = Scaleform::GFx::AS2::Value::ToNumber(&v32, v1->Env);
        v28 = Scaleform::GFx::AS2::Value::ToNumber(&v32, v26);
        v32.T.Type = 3;
        v32.NV.NumberValue = v28 * v27;
        Scaleform::GFx::AS2::Value::Add(&v31, v1->Env, &v32);
        v29 = Scaleform::GFx::AS2::Value::ToNumber(&v31, v1->Env);
        v34.T.Type = 3;
        *((_QWORD *)&v32.NV + 3) = sqrt(v29);
        v30 = Scaleform::GFx::AS2::Value::ToNumber(&v34, v1->Env);
        Scaleform::GFx::AS2::Value::SetNumber(v1->Result, v30);
        if ( v32.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&v32);
        if ( v31.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&v31);
        `eh vector destructor iterator'(
          &v34.NV + 1,
          0x20ui64,
          2,
          (void (__fastcall *)(void *))Scaleform::GFx::AS2::Value::~Value);
        `eh vector destructor iterator'(
          &ptr,
          0x20ui64,
          2,
          (void (__fastcall *)(void *))Scaleform::GFx::AS2::Value::~Value);
      }
      else
      {
        v14 = v1->Result;
        Scaleform::GFx::AS2::Value::DropRefs(v1->Result);
        v14->T.Type = 0;
      }
    }
  }
}

// File Line: 432
// RVA: 0x6A80A0
void __fastcall Scaleform::GFx::AS2::PointCtorFunction::Interpolate(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rbp
  Scaleform::GFx::AS2::PointObject *v2; // rax
  Scaleform::GFx::AS2::Value *v3; // rbx
  Scaleform::GFx::AS2::PointObject *v4; // rax
  Scaleform::GFx::AS2::PointObject *v5; // rsi
  char v6; // di
  unsigned int v7; // er10
  Scaleform::GFx::AS2::Environment *v8; // rdx
  Scaleform::GFx::AS2::Value *v9; // r9
  Scaleform::GFx::AS2::Object *v10; // r15
  unsigned int v11; // er9
  Scaleform::GFx::AS2::Environment *v12; // r11
  Scaleform::GFx::AS2::Value *v13; // r10
  Scaleform::GFx::AS2::Object *v14; // r14
  unsigned int v15; // er8
  Scaleform::GFx::AS2::Environment *v16; // r9
  long double v17; // xmm0_8
  Scaleform::GFx::AS2::Environment *v18; // rdi
  unsigned int v19; // eax
  Scaleform::Render::Point<double> pt; // [rsp+38h] [rbp-70h]
  Scaleform::Render::Point<double> v21; // [rsp+48h] [rbp-60h]
  Scaleform::GFx::AS2::Value v22; // [rsp+58h] [rbp-50h]
  Scaleform::MemoryHeap *v23; // [rsp+B0h] [rbp+8h]
  Scaleform::GFx::AS2::PointObject *v24; // [rsp+B8h] [rbp+10h]

  v1 = fn;
  v23 = fn->Env->StringContext.pContext->pHeap;
  v2 = (Scaleform::GFx::AS2::PointObject *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::FnCall *, signed __int64))v23->vfptr->Alloc)(
                                             fn,
                                             96i64);
  v24 = v2;
  v3 = 0i64;
  if ( v2 )
  {
    Scaleform::GFx::AS2::PointObject::PointObject(v2, v1->Env);
    v5 = v4;
  }
  else
  {
    v5 = 0i64;
  }
  v24 = v5;
  v6 = 0;
  if ( v1->NArgs <= 2 )
    goto LABEL_23;
  v7 = v1->FirstArgBottomIndex;
  v8 = v1->Env;
  v9 = 0i64;
  if ( v7 <= 32 * ((unsigned int)v8->Stack.Pages.Data.Size - 1)
           + (unsigned int)((_QWORD)((char *)v8->Stack.pCurrent - (char *)v8->Stack.pPageStart) >> 5) )
    v9 = &v8->Stack.Pages.Data.Data[v7 >> 5]->Values[v7 & 0x1F];
  v10 = Scaleform::GFx::AS2::Value::ToObject(v9, v8);
  v11 = v1->FirstArgBottomIndex - 1;
  v12 = v1->Env;
  v13 = 0i64;
  if ( v11 <= 32 * ((unsigned int)v12->Stack.Pages.Data.Size - 1)
            + (unsigned int)((_QWORD)((char *)v12->Stack.pCurrent - (char *)v12->Stack.pPageStart) >> 5) )
    v13 = &v12->Stack.Pages.Data.Data[v11 >> 5]->Values[v11 & 0x1F];
  v14 = Scaleform::GFx::AS2::Value::ToObject(v13, v1->Env);
  v15 = v1->FirstArgBottomIndex - 2;
  v16 = v1->Env;
  if ( v15 <= 32 * ((unsigned int)v16->Stack.Pages.Data.Size - 1)
            + (unsigned int)((_QWORD)((char *)v16->Stack.pCurrent - (char *)v16->Stack.pPageStart) >> 5) )
    v3 = &v16->Stack.Pages.Data.Data[v15 >> 5]->Values[v15 & 0x1F];
  Scaleform::GFx::AS2::Value::Value(&v22, v3);
  if ( v10 && v14 )
  {
    Scaleform::GFx::AS2::GFxObject_GetPointProperties(v1->Env, v10, &pt);
    Scaleform::GFx::AS2::GFxObject_GetPointProperties(v1->Env, v14, &v21);
    v17 = Scaleform::GFx::AS2::Value::ToNumber(&v22, v1->Env);
    v21.x = (pt.x - v21.x) * v17 + v21.x;
    v21.y = (pt.y - v21.y) * v17 + v21.y;
    Scaleform::GFx::AS2::PointObject::SetProperties(v5, v1->Env, &v21);
    v6 = 1;
  }
  if ( v22.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v22);
  if ( !v6 )
  {
LABEL_23:
    v18 = v1->Env;
    LOBYTE(v23) = 0;
    v5->vfptr->SetMemberRaw(
      (Scaleform::GFx::AS2::ObjectInterface *)&v5->vfptr,
      &v18->StringContext,
      (Scaleform::GFx::ASString *)&v18->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[33].pASSupport,
      Point_NanParams,
      (Scaleform::GFx::AS2::PropFlags *)&v23);
    LOBYTE(v23) = 0;
    v5->vfptr->SetMemberRaw(
      (Scaleform::GFx::AS2::ObjectInterface *)&v5->vfptr,
      &v18->StringContext,
      (Scaleform::GFx::ASString *)&v18->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[33].AVMVersion,
      (Scaleform::GFx::AS2::Value *)&byte_14243A450,
      (Scaleform::GFx::AS2::PropFlags *)&v23);
  }
  Scaleform::GFx::AS2::Value::SetAsObject(v1->Result, (Scaleform::GFx::AS2::Object *)&v5->vfptr);
  if ( v5 )
  {
    v19 = v5->RefCount;
    if ( v19 & 0x3FFFFFF )
    {
      v5->RefCount = v19 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v5->vfptr);
    }
  }
}

// File Line: 470
// RVA: 0x6A8380
void __fastcall Scaleform::GFx::AS2::PointCtorFunction::Polar(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rbp
  Scaleform::GFx::AS2::PointObject *v2; // rax
  Scaleform::GFx::AS2::Value *v3; // rbx
  Scaleform::GFx::AS2::PointObject *v4; // rax
  Scaleform::GFx::AS2::PointObject *v5; // rsi
  unsigned int v6; // er9
  Scaleform::GFx::AS2::Environment *v7; // rdx
  Scaleform::GFx::AS2::Value *v8; // r8
  unsigned int v9; // edx
  Scaleform::GFx::AS2::Environment *v10; // r8
  double v11; // xmm8_8
  double v12; // xmm6_8
  double v13; // xmm7_8
  Scaleform::GFx::AS2::Environment *v14; // rdi
  unsigned int v15; // eax
  Scaleform::Render::Point<double> pt; // [rsp+38h] [rbp-A0h]
  Scaleform::GFx::AS2::Value v17; // [rsp+48h] [rbp-90h]
  Scaleform::GFx::AS2::Value v18; // [rsp+68h] [rbp-70h]
  Scaleform::MemoryHeap *v19; // [rsp+E0h] [rbp+8h]
  Scaleform::GFx::AS2::PointObject *v20; // [rsp+E8h] [rbp+10h]

  v1 = fn;
  v19 = fn->Env->StringContext.pContext->pHeap;
  v2 = (Scaleform::GFx::AS2::PointObject *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::FnCall *, signed __int64))v19->vfptr->Alloc)(
                                             fn,
                                             96i64);
  v20 = v2;
  v3 = 0i64;
  if ( v2 )
  {
    Scaleform::GFx::AS2::PointObject::PointObject(v2, v1->Env);
    v5 = v4;
  }
  else
  {
    v5 = 0i64;
  }
  v20 = v5;
  if ( v1->NArgs <= 1 )
  {
    v14 = v1->Env;
    LOBYTE(v19) = 0;
    v5->vfptr->SetMemberRaw(
      (Scaleform::GFx::AS2::ObjectInterface *)&v5->vfptr,
      &v14->StringContext,
      (Scaleform::GFx::ASString *)&v14->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[33].pASSupport,
      Point_NanParams,
      (Scaleform::GFx::AS2::PropFlags *)&v19);
    LOBYTE(v19) = 0;
    v5->vfptr->SetMemberRaw(
      (Scaleform::GFx::AS2::ObjectInterface *)&v5->vfptr,
      &v14->StringContext,
      (Scaleform::GFx::ASString *)&v14->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[33].AVMVersion,
      (Scaleform::GFx::AS2::Value *)&byte_14243A450,
      (Scaleform::GFx::AS2::PropFlags *)&v19);
  }
  else
  {
    v6 = v1->FirstArgBottomIndex;
    v7 = v1->Env;
    v8 = 0i64;
    if ( v6 <= 32 * ((unsigned int)v7->Stack.Pages.Data.Size - 1)
             + (unsigned int)((_QWORD)((char *)v7->Stack.pCurrent - (char *)v7->Stack.pPageStart) >> 5) )
      v8 = &v7->Stack.Pages.Data.Data[v6 >> 5]->Values[v6 & 0x1F];
    Scaleform::GFx::AS2::Value::Value(&v18, v8);
    v9 = v1->FirstArgBottomIndex - 1;
    v10 = v1->Env;
    if ( v9 <= 32 * ((unsigned int)v10->Stack.Pages.Data.Size - 1)
             + (unsigned int)((_QWORD)((char *)v10->Stack.pCurrent - (char *)v10->Stack.pPageStart) >> 5) )
      v3 = &v10->Stack.Pages.Data.Data[v9 >> 5]->Values[v9 & 0x1F];
    Scaleform::GFx::AS2::Value::Value(&v17, v3);
    v11 = Scaleform::GFx::AS2::Value::ToNumber(&v18, v1->Env);
    v12 = Scaleform::GFx::AS2::Value::ToNumber(&v17, v1->Env);
    v13 = sin(v12);
    pt.x = cos(v12) * v11;
    pt.y = v13 * v11;
    Scaleform::GFx::AS2::PointObject::SetProperties(v5, v1->Env, &pt);
    if ( v17.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v17);
    if ( v18.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v18);
  }
  Scaleform::GFx::AS2::Value::SetAsObject(v1->Result, (Scaleform::GFx::AS2::Object *)&v5->vfptr);
  if ( v5 )
  {
    v15 = v5->RefCount;
    if ( v15 & 0x3FFFFFF )
    {
      v5->RefCount = v15 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v5->vfptr);
    }
  }
}

// File Line: 497
// RVA: 0x6F9C00
void __fastcall Scaleform::GFx::AS2::PointCtorFunction::GlobalCtor(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rsi
  Scaleform::GFx::AS2::Value *v2; // rdi
  Scaleform::GFx::AS2::ObjectInterface *v3; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v4; // rbx
  Scaleform::GFx::AS2::Object *v5; // rbx
  Scaleform::GFx::AS2::PointObject *v6; // rax
  Scaleform::GFx::AS2::Object *v7; // rax
  unsigned int v8; // er8
  Scaleform::GFx::AS2::Environment *v9; // r9
  Scaleform::GFx::AS2::Value *v10; // rdx
  unsigned int v11; // edx
  Scaleform::GFx::AS2::Environment *v12; // r8
  Scaleform::GFx::AS2::Environment *v13; // rsi
  unsigned int v14; // eax
  char ptr; // [rsp+40h] [rbp-58h]
  Scaleform::GFx::AS2::Value v16; // [rsp+60h] [rbp-38h]
  Scaleform::MemoryHeap *v17; // [rsp+A0h] [rbp+8h]
  Scaleform::GFx::AS2::Object *v18; // [rsp+A8h] [rbp+10h]
  Scaleform::GFx::AS2::PointObject *v19; // [rsp+B0h] [rbp+18h]

  v1 = fn;
  v2 = 0i64;
  v18 = 0i64;
  v3 = fn->ThisPtr;
  if ( !v3
    || (*(unsigned int (**)(void))&v3->vfptr->gap8[8])() != 16
    || ((unsigned __int8 (*)(void))v1->ThisPtr->vfptr->IsBuiltinPrototype)() )
  {
    v17 = v1->Env->StringContext.pContext->pHeap;
    v6 = (Scaleform::GFx::AS2::PointObject *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::ObjectInterface *, signed __int64))v17->vfptr->Alloc)(
                                               v3,
                                               96i64);
    v19 = v6;
    if ( v6 )
    {
      Scaleform::GFx::AS2::PointObject::PointObject(v6, v1->Env);
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
      v5 = (Scaleform::GFx::AS2::Object *)&v4[-2];
      if ( v5 )
        v5->RefCount = (v5->RefCount + 1) & 0x8FFFFFFF;
    }
    else
    {
      v5 = 0i64;
    }
  }
  v18 = v5;
  Scaleform::GFx::AS2::Value::SetAsObject(v1->Result, v5);
  if ( v1->NArgs > 0 )
  {
    `eh vector constructor iterator'(&ptr, 0x20ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::AS2::Value::Value);
    v8 = v1->FirstArgBottomIndex;
    v9 = v1->Env;
    v10 = 0i64;
    if ( v8 <= 32 * ((unsigned int)v9->Stack.Pages.Data.Size - 1)
             + (unsigned int)((_QWORD)((char *)v9->Stack.pCurrent - (char *)v9->Stack.pPageStart) >> 5) )
      v10 = &v9->Stack.Pages.Data.Data[v8 >> 5]->Values[v8 & 0x1F];
    Scaleform::GFx::AS2::Value::operator=((Scaleform::GFx::AS2::Value *)&ptr, v10, 0i64);
    if ( v1->NArgs > 1 )
    {
      v11 = v1->FirstArgBottomIndex - 1;
      v12 = v1->Env;
      if ( v11 <= 32 * ((unsigned int)v12->Stack.Pages.Data.Size - 1)
                + (unsigned int)((_QWORD)((char *)v12->Stack.pCurrent - (char *)v12->Stack.pPageStart) >> 5) )
        v2 = &v12->Stack.Pages.Data.Data[v11 >> 5]->Values[v11 & 0x1F];
      Scaleform::GFx::AS2::Value::operator=(&v16, v2, (__int64)v2);
    }
    v13 = v1->Env;
    LOBYTE(v17) = 0;
    v5->vfptr->SetMemberRaw(
      (Scaleform::GFx::AS2::ObjectInterface *)&v5->vfptr,
      &v13->StringContext,
      (Scaleform::GFx::ASString *)&v13->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[33].pASSupport,
      (Scaleform::GFx::AS2::Value *)&ptr,
      (Scaleform::GFx::AS2::PropFlags *)&v17);
    LOBYTE(v17) = 0;
    v5->vfptr->SetMemberRaw(
      (Scaleform::GFx::AS2::ObjectInterface *)&v5->vfptr,
      &v13->StringContext,
      (Scaleform::GFx::ASString *)&v13->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[33].AVMVersion,
      &v16,
      (Scaleform::GFx::AS2::PropFlags *)&v17);
    `eh vector destructor iterator'(&ptr, 0x20ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::AS2::Value::~Value);
  }
  if ( v5 )
  {
    v14 = v5->RefCount;
    if ( v14 & 0x3FFFFFF )
    {
      v5->RefCount = v14 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v5->vfptr);
    }
  }
}

// File Line: 521
// RVA: 0x6E0770
void __fastcall Scaleform::GFx::AS2::PointCtorFunction::CreateNewObject(Scaleform::GFx::AS2::PointCtorFunction *this, Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::Environment *v2; // rbx
  Scaleform::GFx::AS2::PointObject *v3; // rax

  v2 = penv;
  v3 = (Scaleform::GFx::AS2::PointObject *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::PointCtorFunction *, signed __int64))penv->StringContext.pContext->pHeap->vfptr->Alloc)(
                                             this,
                                             96i64);
  if ( v3 )
    Scaleform::GFx::AS2::PointObject::PointObject(v3, v2);
}

// File Line: 526
// RVA: 0x70E580
Scaleform::GFx::AS2::FunctionRef *__fastcall Scaleform::GFx::AS2::PointCtorFunction::Register(Scaleform::GFx::AS2::FunctionRef *result, Scaleform::GFx::AS2::GlobalContext *pgc)
{
  Scaleform::GFx::AS2::GlobalContext *v2; // rsi
  Scaleform::GFx::AS2::FunctionRef *v3; // rdi
  Scaleform::GFx::AS2::Object *v4; // rax
  __int64 v5; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v6; // rbx
  Scaleform::GFx::AS2::Object *v7; // r15
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v8; // rcx
  unsigned int v9; // eax
  Scaleform::GFx::AS2::PointProto *v10; // rbx
  Scaleform::GFx::AS2::Object *v11; // rax
  Scaleform::GFx::AS2::Object *v12; // rax
  Scaleform::GFx::AS2::Object *v13; // rbx
  Scaleform::GFx::ASStringNode *v14; // rax
  Scaleform::GFx::AS2::LocalFrame *v15; // rdx
  unsigned int v16; // eax
  Scaleform::GFx::AS2::ASStringContext psc; // [rsp+40h] [rbp-38h]
  Scaleform::GFx::AS2::Value v19; // [rsp+50h] [rbp-28h]
  Scaleform::Ptr<Scaleform::GFx::AS2::Object> objproto; // [rsp+B8h] [rbp+40h]
  Scaleform::MemoryHeap *v21; // [rsp+C0h] [rbp+48h]
  Scaleform::Ptr<Scaleform::GFx::AS2::Object> *v22; // [rsp+C8h] [rbp+50h]

  v2 = pgc;
  v3 = result;
  psc.pContext = pgc;
  psc.SWFVersion = 8;
  v21 = pgc->pHeap;
  v4 = (Scaleform::GFx::AS2::Object *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::FunctionRef *, signed __int64))v21->vfptr->Alloc)(
                                        result,
                                        104i64);
  v6 = (Scaleform::GFx::AS2::ObjectInterface *)v4;
  v22 = (Scaleform::Ptr<Scaleform::GFx::AS2::Object> *)v4;
  if ( v4 )
  {
    Scaleform::GFx::AS2::Object::Object(v4, &psc);
    v6->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::FunctionObject::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
    v6[2].vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::FunctionObject::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
    v6->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::CFunctionObject::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
    v6[2].vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::CFunctionObject::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
    v6[6].vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)Scaleform::GFx::AS2::PointCtorFunction::GlobalCtor;
    v7 = Scaleform::GFx::AS2::GlobalContext::GetPrototype(psc.pContext, ASBuiltin_Function);
    if ( !v6[2].pProto.pObject )
    {
      LOBYTE(objproto.pObject) = 3;
      v19.T.Type = 10;
      v6[2].vfptr->SetMemberRaw(
        v6 + 2,
        &psc,
        (Scaleform::GFx::ASString *)&psc.pContext->pMovieRoot->pASMovieRoot.pObject[23].pMovieImpl,
        &v19,
        (Scaleform::GFx::AS2::PropFlags *)&objproto);
      if ( v19.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v19);
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
    v6->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::PointCtorFunction::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
    v6[2].vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::PointCtorFunction::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
    Scaleform::GFx::AS2::NameFunction::AddConstMembers(
      v6 + 2,
      &psc,
      Scaleform::GFx::AS2::PointCtorFunction::StaticFunctionTable,
      7);
  }
  else
  {
    v6 = 0i64;
  }
  v3->Flags = 0;
  v3->Function = (Scaleform::GFx::AS2::FunctionObject *)v6;
  v3->pLocalFrame = 0i64;
  objproto.pObject = (Scaleform::GFx::AS2::Object *)v2->pHeap;
  v10 = (Scaleform::GFx::AS2::PointProto *)((__int64 (__fastcall *)(__int64, signed __int64, _QWORD))objproto.pObject->vfptr[3].Finalize_GC)(
                                             v5,
                                             160i64,
                                             0i64);
  v21 = (Scaleform::MemoryHeap *)v10;
  if ( v10 )
  {
    v11 = Scaleform::GFx::AS2::GlobalContext::GetPrototype(v2, ASBuiltin_Object);
    Scaleform::GFx::AS2::PointProto::PointProto(v10, &psc, v11, v3);
    v13 = v12;
  }
  else
  {
    v13 = 0i64;
  }
  v21 = (Scaleform::MemoryHeap *)v13;
  v22 = &objproto;
  if ( v13 )
    v13->RefCount = (v13->RefCount + 1) & 0x8FFFFFFF;
  objproto.pObject = v13;
  Scaleform::GFx::AS2::GlobalContext::SetPrototype(
    v2,
    ASBuiltin_Point,
    (Scaleform::Ptr<Scaleform::GFx::AS2::Object>)&objproto);
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
  v2->FlashGeomPackage->vfptr->SetMemberRaw(
    (Scaleform::GFx::AS2::ObjectInterface *)&v2->FlashGeomPackage->vfptr,
    &psc,
    (Scaleform::GFx::ASString *)&v2->pMovieRoot->pASMovieRoot.pObject[10].pASSupport,
    &v19,
    (Scaleform::GFx::AS2::PropFlags *)&objproto);
  if ( v19.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v19);
  if ( v13 )
  {
    v16 = v13->RefCount;
    if ( v16 & 0x3FFFFFF )
    {
      v13->RefCount = v16 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v13->vfptr);
    }
  }
  return v3;
}

