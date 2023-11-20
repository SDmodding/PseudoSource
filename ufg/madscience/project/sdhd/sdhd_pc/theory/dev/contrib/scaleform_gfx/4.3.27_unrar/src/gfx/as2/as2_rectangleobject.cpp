// File Line: 30
// RVA: 0x700BF0
bool __fastcall Scaleform::GFx::AS2::IsRectValid(Scaleform::Render::Rect<double> *r)
{
  bool result; // al
  long double v2; // [rsp+8h] [rbp+8h]
  long double v3; // [rsp+8h] [rbp+8h]
  long double v4; // [rsp+8h] [rbp+8h]

  result = 0;
  if ( (*(_QWORD *)&r->x1 & 0x7FF0000000000000i64) != 9218868437227405312i64
    || !(*(_QWORD *)&r->x1 & 0xFFFFFFFFFFFFFi64) )
  {
    v2 = r->y1;
    if ( (*(_QWORD *)&v2 & 0x7FF0000000000000i64) != 9218868437227405312i64 || !(*(_QWORD *)&v2 & 0xFFFFFFFFFFFFFi64) )
    {
      v3 = r->x2;
      if ( (*(_QWORD *)&v3 & 0x7FF0000000000000i64) != 9218868437227405312i64 || !(*(_QWORD *)&v3 & 0xFFFFFFFFFFFFFi64) )
      {
        v4 = r->y2;
        if ( (*(_QWORD *)&v4 & 0x7FF0000000000000i64) != 9218868437227405312i64
          || !(*(_QWORD *)&v4 & 0xFFFFFFFFFFFFFi64) )
        {
          result = 1;
        }
      }
    }
  }
  return result;
}

// File Line: 35
// RVA: 0x723360
void __fastcall Scaleform::GFx::AS2::ValidateRect(Scaleform::Render::Rect<double> *r)
{
  long double v1; // [rsp+8h] [rbp+8h]
  long double v2; // [rsp+8h] [rbp+8h]
  long double v3; // [rsp+8h] [rbp+8h]

  if ( (*(_QWORD *)&r->x1 & 0x7FF0000000000000i64) == 9218868437227405312i64 && *(_QWORD *)&r->x1 & 0xFFFFFFFFFFFFFi64 )
    r->x1 = 0.0;
  v1 = r->x2;
  if ( (*(_QWORD *)&v1 & 0x7FF0000000000000i64) == 9218868437227405312i64 && *(_QWORD *)&v1 & 0xFFFFFFFFFFFFFi64 )
    r->x2 = 0.0;
  v2 = r->y1;
  if ( (*(_QWORD *)&v2 & 0x7FF0000000000000i64) == 9218868437227405312i64 && *(_QWORD *)&v2 & 0xFFFFFFFFFFFFFi64 )
    r->y1 = 0.0;
  v3 = r->y2;
  if ( (*(_QWORD *)&v3 & 0x7FF0000000000000i64) == 9218868437227405312i64 )
  {
    if ( *(_QWORD *)&v3 & 0xFFFFFFFFFFFFFi64 )
      r->y2 = 0.0;
  }
}

// File Line: 44
// RVA: 0x1587AB0
__int64 Scaleform::GFx::AS2::_dynamic_initializer_for__Rectangle_DefaultParams__()
{
  stru_142094470.T.Type = 4;
  stru_142094470.NV.Int32Value = 0;
  stru_142094490.T.Type = 4;
  stru_142094490.NV.Int32Value = 0;
  unk_1420944B0 = 4;
  unk_1420944B8 = 0;
  return atexit(Scaleform::GFx::AS2::_dynamic_atexit_destructor_for__Rectangle_DefaultParams__);
}

// File Line: 53
// RVA: 0x1587B00
__int64 Scaleform::GFx::AS2::_dynamic_initializer_for__Rectangle_NaNParams__()
{
  long double v0; // xmm0_8
  long double v1; // xmm0_8
  long double v2; // xmm0_8
  long double v3; // xmm0_8

  v0 = Scaleform::GFx::NumberUtil::NaN();
  Rectangle_NaNParams[0].T.Type = 3;
  qword_14243A478 = *(_QWORD *)&v0;
  v1 = Scaleform::GFx::NumberUtil::NaN();
  stru_14243A490.T.Type = 3;
  stru_14243A490.NV.NumberValue = v1;
  v2 = Scaleform::GFx::NumberUtil::NaN();
  stru_14243A4B0.T.Type = 3;
  stru_14243A4B0.NV.NumberValue = v2;
  v3 = Scaleform::GFx::NumberUtil::NaN();
  byte_14243A4D0 = 3;
  qword_14243A4D8 = *(_QWORD *)&v3;
  return atexit(Scaleform::GFx::AS2::_dynamic_atexit_destructor_for__Rectangle_NaNParams__);
}

// File Line: 64
// RVA: 0x6ED9F0
void __fastcall Scaleform::GFx::AS2::GFxObject_GetRectangleProperties(Scaleform::GFx::AS2::Environment *penv, Scaleform::GFx::AS2::Object *pobj, Scaleform::GFx::AS2::Value *params)
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
  Scaleform::GFx::ASString result; // [rsp+40h] [rbp+8h]

  v3 = params;
  v4 = &penv->StringContext;
  v5 = (char *)&pobj->vfptr;
  v6 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(&penv->StringContext, &result, "x");
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
  v9 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v4, &result, "y");
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
  v11 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v4, &result, "width");
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
  v13 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v4, &result, "height");
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
}

// File Line: 92
// RVA: 0x70BFF0
Scaleform::GFx::AS2::Value *__fastcall Scaleform::GFx::AS2::Rectangle_ComputeTopLeft(Scaleform::GFx::AS2::Value *result, Scaleform::GFx::AS2::Environment *penv, Scaleform::Render::Rect<double> *r)
{
  Scaleform::Render::Rect<double> *v3; // rbp
  Scaleform::GFx::AS2::Environment *v4; // rsi
  Scaleform::GFx::AS2::Value *v5; // rdi
  Scaleform::GFx::AS2::PointObject *v6; // rbx
  Scaleform::GFx::AS2::PointObject *v7; // rax
  Scaleform::GFx::AS2::PointObject *v8; // rax
  long double v9; // xmm1_8
  unsigned int v10; // eax
  Scaleform::Render::Point<double> pt; // [rsp+30h] [rbp-28h]

  v3 = r;
  v4 = penv;
  v5 = result;
  v6 = 0i64;
  v7 = (Scaleform::GFx::AS2::PointObject *)penv->StringContext.pContext->pHeap->vfptr->Alloc(
                                             (Scaleform::MemoryHeap *)result,
                                             96ui64,
                                             0i64);
  if ( v7 )
  {
    Scaleform::GFx::AS2::PointObject::PointObject(v7, v4);
    v6 = v8;
  }
  v9 = v3->y1;
  pt.x = v3->x1;
  pt.y = v9;
  Scaleform::GFx::AS2::PointObject::SetProperties(v6, v4, &pt);
  Scaleform::GFx::AS2::Value::Value(v5, (Scaleform::GFx::AS2::Object *)&v6->vfptr);
  if ( v6 )
  {
    v10 = v6->RefCount;
    if ( v10 & 0x3FFFFFF )
    {
      v6->RefCount = v10 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v6->vfptr);
    }
  }
  return v5;
}

// File Line: 103
// RVA: 0x70BE40
Scaleform::GFx::AS2::Value *__fastcall Scaleform::GFx::AS2::Rectangle_ComputeBottomRight(Scaleform::GFx::AS2::Value *result, Scaleform::GFx::AS2::Environment *penv, Scaleform::Render::Rect<double> *r)
{
  Scaleform::Render::Rect<double> *v3; // rbp
  Scaleform::GFx::AS2::Environment *v4; // rsi
  Scaleform::GFx::AS2::Value *v5; // rdi
  Scaleform::GFx::AS2::PointObject *v6; // rbx
  Scaleform::GFx::AS2::PointObject *v7; // rax
  Scaleform::GFx::AS2::PointObject *v8; // rax
  long double v9; // xmm1_8
  unsigned int v10; // eax
  Scaleform::Render::Point<double> pt; // [rsp+30h] [rbp-28h]

  v3 = r;
  v4 = penv;
  v5 = result;
  v6 = 0i64;
  v7 = (Scaleform::GFx::AS2::PointObject *)penv->StringContext.pContext->pHeap->vfptr->Alloc(
                                             (Scaleform::MemoryHeap *)result,
                                             96ui64,
                                             0i64);
  if ( v7 )
  {
    Scaleform::GFx::AS2::PointObject::PointObject(v7, v4);
    v6 = v8;
  }
  v9 = v3->y2;
  pt.x = v3->x2;
  pt.y = v9;
  Scaleform::GFx::AS2::PointObject::SetProperties(v6, v4, &pt);
  Scaleform::GFx::AS2::Value::Value(v5, (Scaleform::GFx::AS2::Object *)&v6->vfptr);
  if ( v6 )
  {
    v10 = v6->RefCount;
    if ( v10 & 0x3FFFFFF )
    {
      v6->RefCount = v10 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v6->vfptr);
    }
  }
  return v5;
}

// File Line: 114
// RVA: 0x70BF10
Scaleform::GFx::AS2::Value *__fastcall Scaleform::GFx::AS2::Rectangle_ComputeSize(Scaleform::GFx::AS2::Value *result, Scaleform::GFx::AS2::Environment *penv, Scaleform::Render::Rect<double> *r)
{
  Scaleform::Render::Rect<double> *v3; // rsi
  Scaleform::GFx::AS2::Environment *v4; // rbp
  Scaleform::GFx::AS2::Value *v5; // rdi
  Scaleform::GFx::AS2::PointObject *v6; // rbx
  Scaleform::GFx::AS2::PointObject *v7; // rax
  Scaleform::GFx::AS2::PointObject *v8; // rax
  long double v9; // xmm1_8
  unsigned int v10; // eax
  Scaleform::Render::Point<double> pt; // [rsp+30h] [rbp-28h]

  v3 = r;
  v4 = penv;
  v5 = result;
  v6 = 0i64;
  v7 = (Scaleform::GFx::AS2::PointObject *)penv->StringContext.pContext->pHeap->vfptr->Alloc(
                                             (Scaleform::MemoryHeap *)result,
                                             96ui64,
                                             0i64);
  if ( v7 )
  {
    Scaleform::GFx::AS2::PointObject::PointObject(v7, v4);
    v6 = v8;
  }
  v9 = v3->y2 - v3->y1;
  pt.x = v3->x2 - v3->x1;
  pt.y = v9;
  Scaleform::GFx::AS2::PointObject::SetProperties(v6, v4, &pt);
  Scaleform::GFx::AS2::Value::Value(v5, (Scaleform::GFx::AS2::Object *)&v6->vfptr);
  if ( v6 )
  {
    v10 = v6->RefCount;
    if ( v10 & 0x3FFFFFF )
    {
      v6->RefCount = v10 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v6->vfptr);
    }
  }
  return v5;
}

// File Line: 168
// RVA: 0x6CB6A0
void __fastcall Scaleform::GFx::AS2::RectangleObject::RectangleObject(Scaleform::GFx::AS2::RectangleObject *this, Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::Environment *v2; // rdi
  Scaleform::GFx::AS2::RectangleObject *v3; // rsi
  Scaleform::GFx::AS2::Object *v4; // rax

  v2 = penv;
  v3 = this;
  Scaleform::GFx::AS2::Object::Object((Scaleform::GFx::AS2::Object *)&this->vfptr, penv);
  v3->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::RectangleObject::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
  v3->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::RectangleObject::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  v4 = Scaleform::GFx::AS2::GlobalContext::GetPrototype(v2->StringContext.pContext, ASBuiltin_Rectangle);
  Scaleform::GFx::AS2::Object::Set__proto__((Scaleform::GFx::AS2::Object *)&v3->vfptr, &v2->StringContext, v4);
  Scaleform::GFx::AS2::RectangleObject::SetProperties(v3, &v2->StringContext, Rectangle_DefaultParams);
}

// File Line: 177
// RVA: 0x6F2310
char __fastcall Scaleform::GFx::AS2::RectangleObject::GetMember(Scaleform::GFx::AS2::RectangleObject *this, Scaleform::GFx::AS2::Environment *penv, Scaleform::GFx::ASString *name, Scaleform::GFx::AS2::Value *val)
{
  Scaleform::GFx::AS2::Value *v4; // r15
  Scaleform::GFx::ASString *v5; // r12
  Scaleform::GFx::AS2::Environment *v6; // rsi
  Scaleform::GFx::AS2::RectangleObject *v7; // r14
  const char *v8; // rdi
  __int64 v9; // rbx
  __int64 v10; // r10
  char v11; // al
  __int64 v13; // rcx
  char v14; // al
  __int64 v15; // rcx
  char v16; // al
  __int64 v17; // rcx
  char v18; // al
  __int64 v19; // rcx
  char v20; // al
  Scaleform::GFx::AS2::Value *v21; // rax
  Scaleform::GFx::AS2::Value *v22; // rax
  char v23; // al
  Scaleform::GFx::AS2::Value *v24; // rax
  Scaleform::GFx::AS2::Value v; // [rsp+28h] [rbp-48h]
  Scaleform::Render::Rect<double> r; // [rsp+48h] [rbp-28h]

  v4 = val;
  v5 = name;
  v6 = penv;
  v7 = this;
  v8 = name->pNode->pData;
  v9 = 0i64;
  v10 = 0i64;
  while ( 1 )
  {
    v11 = v8[v10++];
    if ( v11 != aLeft_0[v10 - 1] )
      break;
    if ( v10 == 5 )
    {
      r.x1 = 0.0;
      Scaleform::GFx::AS2::RectangleObject::GetProperties(
        (Scaleform::GFx::AS2::RectangleObject *)((char *)this - 32),
        penv,
        &r);
      v.T.Type = 3;
      v.V.pStringNode = *(Scaleform::GFx::ASStringNode **)&r.x1;
      Scaleform::GFx::AS2::Value::operator=(v4, &v, (__int64)v8);
LABEL_5:
      if ( v.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v);
      return 1;
    }
  }
  v13 = 0i64;
  while ( 1 )
  {
    v14 = v8[v13++];
    if ( v14 != aRight_0[v13 - 1] )
      break;
    if ( v13 == 6 )
    {
      r.x2 = 0.0;
      Scaleform::GFx::AS2::RectangleObject::GetProperties(
        (Scaleform::GFx::AS2::RectangleObject *)((char *)v7 - 32),
        penv,
        &r);
      v.T.Type = 3;
      v.V.pStringNode = *(Scaleform::GFx::ASStringNode **)&r.x2;
      Scaleform::GFx::AS2::Value::operator=(v4, &v, (__int64)v8);
      goto LABEL_5;
    }
  }
  v15 = 0i64;
  while ( 1 )
  {
    v16 = v8[v15++];
    if ( v16 != aTop_2[v15 - 1] )
      break;
    if ( v15 == 4 )
    {
      r.y1 = 0.0;
      Scaleform::GFx::AS2::RectangleObject::GetProperties(
        (Scaleform::GFx::AS2::RectangleObject *)((char *)v7 - 32),
        penv,
        &r);
      v.T.Type = 3;
      v.V.pStringNode = *(Scaleform::GFx::ASStringNode **)&r.y1;
      Scaleform::GFx::AS2::Value::operator=(v4, &v, (__int64)v8);
      goto LABEL_5;
    }
  }
  v17 = 0i64;
  while ( 1 )
  {
    v18 = v8[v17++];
    if ( v18 != aBottom[v17 - 1] )
      break;
    if ( v17 == 7 )
    {
      r.y2 = 0.0;
      Scaleform::GFx::AS2::RectangleObject::GetProperties(
        (Scaleform::GFx::AS2::RectangleObject *)((char *)v7 - 32),
        penv,
        &r);
      v.T.Type = 3;
      v.V.pStringNode = *(Scaleform::GFx::ASStringNode **)&r.y2;
      Scaleform::GFx::AS2::Value::operator=(v4, &v, (__int64)v8);
      goto LABEL_5;
    }
  }
  v19 = 0i64;
  while ( 1 )
  {
    v20 = v8[v19++];
    if ( v20 != aTopleft[v19 - 1] )
      break;
    if ( v19 == 8 )
    {
      *(_OWORD *)&v.T.Type = 0ui64;
      *((_OWORD *)&v.NV + 1) = 0ui64;
      Scaleform::GFx::AS2::RectangleObject::GetProperties(
        (Scaleform::GFx::AS2::RectangleObject *)((char *)v7 - 32),
        penv,
        (Scaleform::Render::Rect<double> *)&v);
      r = (Scaleform::Render::Rect<double>)v;
      v21 = Scaleform::GFx::AS2::Rectangle_ComputeTopLeft(&v, v6, &r);
      Scaleform::GFx::AS2::Value::operator=(v4, v21, (__int64)v8);
      goto LABEL_5;
    }
  }
  if ( !strcmp(name->pNode->pData, "bottomRight") )
  {
    *(_OWORD *)&v.T.Type = 0ui64;
    *((_OWORD *)&v.NV + 1) = 0ui64;
    Scaleform::GFx::AS2::RectangleObject::GetProperties(
      (Scaleform::GFx::AS2::RectangleObject *)((char *)v7 - 32),
      v6,
      (Scaleform::Render::Rect<double> *)&v);
    r = (Scaleform::Render::Rect<double>)v;
    v22 = Scaleform::GFx::AS2::Rectangle_ComputeBottomRight(&v, v6, &r);
    Scaleform::GFx::AS2::Value::operator=(v4, v22, (__int64)v8);
    goto LABEL_5;
  }
  while ( 1 )
  {
    v23 = v8[v9++];
    if ( v23 != aSize[v9 - 1] )
      return ((__int64 (__fastcall *)(Scaleform::GFx::AS2::RectangleObject *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, signed __int64))v7->vfptr[3].~RefCountBaseGC<323>)(
               v7,
               &v6->StringContext,
               v5,
               v4,
               -2i64);
    if ( v9 == 5 )
    {
      *(_OWORD *)&v.T.Type = 0ui64;
      *((_OWORD *)&v.NV + 1) = 0ui64;
      Scaleform::GFx::AS2::RectangleObject::GetProperties(
        (Scaleform::GFx::AS2::RectangleObject *)((char *)v7 - 32),
        v6,
        (Scaleform::Render::Rect<double> *)&v);
      r = (Scaleform::Render::Rect<double>)v;
      v24 = Scaleform::GFx::AS2::Rectangle_ComputeSize(&v, v6, &r);
      Scaleform::GFx::AS2::Value::operator=(v4, v24, (__int64)v8);
      goto LABEL_5;
    }
  }
}

// File Line: 237
// RVA: 0x718040
char __fastcall Scaleform::GFx::AS2::RectangleObject::SetMember(Scaleform::GFx::AS2::RectangleObject *this, Scaleform::GFx::AS2::Environment *penv, Scaleform::GFx::ASString *name, Scaleform::GFx::AS2::Value *val, Scaleform::GFx::AS2::PropFlags *flags)
{
  Scaleform::GFx::AS2::Value *v5; // r14
  Scaleform::GFx::ASString *v6; // r13
  Scaleform::GFx::AS2::Environment *v7; // rsi
  Scaleform::GFx::AS2::RectangleObject *v8; // r15
  __int64 v10; // rbx
  const char *v11; // rdi
  __int64 v12; // rcx
  char v13; // al
  __int64 v14; // rcx
  char v15; // al
  __int64 v16; // rcx
  char v17; // al
  double v18; // xmm0_8
  __int64 v19; // rcx
  char v20; // al
  __int64 v21; // rcx
  char v22; // al
  Scaleform::GFx::AS2::Object *v23; // rax
  Scaleform::GFx::AS2::Object *v24; // rax
  double v25; // xmm1_8
  char v26; // al
  Scaleform::GFx::AS2::Object *v27; // rax
  Scaleform::Render::Point<double> pt; // [rsp+30h] [rbp-30h]
  Scaleform::Render::Rect<double> r; // [rsp+40h] [rbp-20h]

  v5 = val;
  v6 = name;
  v7 = penv;
  v8 = this;
  if ( flags->Flags & 4 )
    return 0;
  v10 = 0i64;
  v11 = name->pNode->pData;
  v12 = 0i64;
  while ( 1 )
  {
    v13 = v11[v12++];
    if ( v13 != aLeft_0[v12 - 1] )
      break;
    if ( v12 == 5 )
    {
      r.y1 = 0.0;
      r.x2 = 0.0;
      r.y2 = 0.0;
      Scaleform::GFx::AS2::RectangleObject::GetProperties(
        (Scaleform::GFx::AS2::RectangleObject *)((char *)v8 - 32),
        penv,
        &r);
      r.x1 = Scaleform::GFx::AS2::Value::ToNumber(v5, v7);
      goto LABEL_33;
    }
  }
  v14 = 0i64;
  while ( 1 )
  {
    v15 = v11[v14++];
    if ( v15 != aTop_2[v14 - 1] )
      break;
    if ( v14 == 4 )
    {
      r.x1 = 0.0;
      r.x2 = 0.0;
      r.y2 = 0.0;
      Scaleform::GFx::AS2::RectangleObject::GetProperties(
        (Scaleform::GFx::AS2::RectangleObject *)((char *)v8 - 32),
        penv,
        &r);
      r.y1 = Scaleform::GFx::AS2::Value::ToNumber(v5, v7);
      goto LABEL_33;
    }
  }
  v16 = 0i64;
  while ( 1 )
  {
    v17 = v11[v16++];
    if ( v17 != aRight_0[v16 - 1] )
      break;
    if ( v16 == 6 )
    {
      r.x1 = 0.0;
      r.y1 = 0.0;
      r.y2 = 0.0;
      Scaleform::GFx::AS2::RectangleObject::GetProperties(
        (Scaleform::GFx::AS2::RectangleObject *)((char *)v8 - 32),
        penv,
        &r);
      v18 = Scaleform::GFx::AS2::Value::ToNumber(v5, v7);
      goto LABEL_32;
    }
  }
  v19 = 0i64;
  while ( 1 )
  {
    v20 = v11[v19++];
    if ( v20 != aBottom[v19 - 1] )
      break;
    if ( v19 == 7 )
    {
      r.x1 = 0.0;
      r.y1 = 0.0;
      r.x2 = 0.0;
      Scaleform::GFx::AS2::RectangleObject::GetProperties(
        (Scaleform::GFx::AS2::RectangleObject *)((char *)v8 - 32),
        penv,
        &r);
      r.y2 = Scaleform::GFx::AS2::Value::ToNumber(v5, v7);
      goto LABEL_33;
    }
  }
  v21 = 0i64;
  while ( 1 )
  {
    v22 = v11[v21++];
    if ( v22 != aTopleft[v21 - 1] )
      break;
    if ( v21 == 8 )
    {
      r.x1 = 0.0;
      r.y1 = 0.0;
      r.x2 = 0.0;
      r.y2 = 0.0;
      Scaleform::GFx::AS2::RectangleObject::GetProperties(
        (Scaleform::GFx::AS2::RectangleObject *)((char *)v8 - 32),
        penv,
        &r);
      v23 = Scaleform::GFx::AS2::Value::ToObject(v5, v7);
      if ( v23 )
      {
        Scaleform::GFx::AS2::GFxObject_GetPointProperties(v7, v23, &pt);
        *(Scaleform::Render::Point<double> *)&r.x1 = pt;
      }
      goto LABEL_33;
    }
  }
  if ( !strcmp(v11, "bottomRight") )
  {
    r.x1 = 0.0;
    r.y1 = 0.0;
    r.x2 = 0.0;
    r.y2 = 0.0;
    Scaleform::GFx::AS2::RectangleObject::GetProperties(
      (Scaleform::GFx::AS2::RectangleObject *)((char *)v8 - 32),
      v7,
      &r);
    v24 = Scaleform::GFx::AS2::Value::ToObject(v5, v7);
    if ( !v24 )
      goto LABEL_33;
    Scaleform::GFx::AS2::GFxObject_GetPointProperties(v7, v24, &pt);
    v18 = pt.x;
    v25 = pt.y;
  }
  else
  {
    do
    {
      v26 = v11[v10++];
      if ( v26 != aSize[v10 - 1] )
        return Scaleform::GFx::AS2::Object::SetMember((Scaleform::GFx::AS2::Object *)&v8->vfptr, v7, v6, v5, flags);
    }
    while ( v10 != 5 );
    r.x1 = 0.0;
    r.y1 = 0.0;
    r.x2 = 0.0;
    r.y2 = 0.0;
    Scaleform::GFx::AS2::RectangleObject::GetProperties(
      (Scaleform::GFx::AS2::RectangleObject *)((char *)v8 - 32),
      v7,
      &r);
    v27 = Scaleform::GFx::AS2::Value::ToObject(v5, v7);
    if ( !v27 )
      goto LABEL_33;
    Scaleform::GFx::AS2::GFxObject_GetPointProperties(v7, v27, &pt);
    v18 = pt.x + r.x1;
    v25 = r.y1 + pt.y;
  }
  r.y2 = v25;
LABEL_32:
  r.x2 = v18;
LABEL_33:
  Scaleform::GFx::AS2::RectangleObject::SetProperties((Scaleform::GFx::AS2::RectangleObject *)((char *)v8 - 32), v7, &r);
  return 1;
}

// File Line: 308
// RVA: 0x6F4B20
void __fastcall Scaleform::GFx::AS2::RectangleObject::GetProperties(Scaleform::GFx::AS2::RectangleObject *this, Scaleform::GFx::AS2::ASStringContext *psc, Scaleform::GFx::AS2::Value *params)
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
  Scaleform::GFx::ASString result; // [rsp+40h] [rbp+8h]

  v3 = params;
  v4 = psc;
  v5 = (char *)&this->vfptr;
  v6 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &result, "x");
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
  v9 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v4, &result, "y");
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
  v11 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v4, &result, "width");
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
  v13 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v4, &result, "height");
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
}

// File Line: 316
// RVA: 0x6F4C40
void __fastcall Scaleform::GFx::AS2::RectangleObject::GetProperties(Scaleform::GFx::AS2::RectangleObject *this, Scaleform::GFx::AS2::Environment *penv, Scaleform::Render::Rect<double> *r)
{
  Scaleform::Render::Rect<double> *v3; // rbp
  Scaleform::GFx::AS2::Environment *v4; // rsi
  Scaleform::GFx::AS2::RectangleObject *v5; // rbx
  Scaleform::GFx::AS2::ASStringContext *v6; // rdi
  signed __int64 v7; // rbx
  Scaleform::GFx::ASString *v8; // rax
  Scaleform::GFx::ASStringNode *v9; // rcx
  bool v10; // zf
  Scaleform::GFx::ASString *v11; // rax
  Scaleform::GFx::ASStringNode *v12; // rcx
  Scaleform::GFx::ASString *v13; // rax
  Scaleform::GFx::ASStringNode *v14; // rcx
  Scaleform::GFx::ASString *v15; // rax
  Scaleform::GFx::ASStringNode *v16; // rcx
  double v17; // xmm7_8
  double v18; // xmm8_8
  double v19; // xmm6_8
  long double v20; // xmm0_8
  Scaleform::GFx::AS2::Value ptr; // [rsp+40h] [rbp-C8h]
  Scaleform::GFx::AS2::Value v22; // [rsp+60h] [rbp-A8h]
  Scaleform::GFx::AS2::Value v23; // [rsp+80h] [rbp-88h]
  Scaleform::GFx::AS2::Value v24; // [rsp+A0h] [rbp-68h]
  Scaleform::GFx::ASString result; // [rsp+110h] [rbp+8h]

  v3 = r;
  v4 = penv;
  v5 = this;
  v6 = &penv->StringContext;
  `eh vector constructor iterator'(&ptr, 0x20ui64, 4, (void (__fastcall *)(void *))Scaleform::GFx::AS2::Value::Value);
  v7 = (signed __int64)&v5->vfptr;
  v8 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v6, &result, "x");
  (*(void (__fastcall **)(signed __int64, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, char *, void (__fastcall *)(Scaleform::GFx::AS2::Value *)))(*(_QWORD *)v7 + 88i64))(
    v7,
    v6,
    v8,
    &ptr.T.Type,
    Scaleform::GFx::AS2::Value::~Value);
  v9 = result.pNode;
  v10 = result.pNode->RefCount == 1;
  --v9->RefCount;
  if ( v10 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v9);
  v11 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v6, &result, "y");
  (*(void (__fastcall **)(signed __int64, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))(*(_QWORD *)v7 + 88i64))(
    v7,
    v6,
    v11,
    &v22);
  v12 = result.pNode;
  v10 = result.pNode->RefCount == 1;
  --v12->RefCount;
  if ( v10 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v12);
  v13 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v6, &result, "width");
  (*(void (__fastcall **)(signed __int64, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))(*(_QWORD *)v7 + 88i64))(
    v7,
    v6,
    v13,
    &v23);
  v14 = result.pNode;
  v10 = result.pNode->RefCount == 1;
  --v14->RefCount;
  if ( v10 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v14);
  v15 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v6, &result, "height");
  (*(void (__fastcall **)(signed __int64, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))(*(_QWORD *)v7 + 88i64))(
    v7,
    v6,
    v15,
    &v24);
  v16 = result.pNode;
  v10 = result.pNode->RefCount == 1;
  --v16->RefCount;
  if ( v10 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v16);
  v17 = Scaleform::GFx::AS2::Value::ToNumber(&v24, v4);
  v18 = Scaleform::GFx::AS2::Value::ToNumber(&v23, v4);
  v19 = Scaleform::GFx::AS2::Value::ToNumber(&v22, v4);
  v20 = Scaleform::GFx::AS2::Value::ToNumber(&ptr, v4);
  v3->x1 = v20;
  v3->y1 = v19;
  v3->x2 = v18 + v20;
  v3->y2 = v19 + v17;
  `eh vector destructor iterator'(&ptr, 0x20ui64, 4, (void (__fastcall *)(void *))Scaleform::GFx::AS2::Value::~Value);
}

// File Line: 333
// RVA: 0x71AB40
void __fastcall Scaleform::GFx::AS2::RectangleObject::SetProperties(Scaleform::GFx::AS2::RectangleObject *this, Scaleform::GFx::AS2::ASStringContext *psc, Scaleform::GFx::AS2::Value *params)
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
  char v15; // [rsp+50h] [rbp+8h]
  Scaleform::GFx::ASString result; // [rsp+60h] [rbp+18h]

  v3 = params;
  v4 = psc;
  v5 = (char *)&this->vfptr;
  v6 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &result, "x");
  v15 = 0;
  (*(void (__fastcall **)(char *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, char *))(*(_QWORD *)v5 + 80i64))(
    v5,
    v4,
    v6,
    v3,
    &v15);
  v7 = result.pNode;
  v8 = result.pNode->RefCount == 1;
  --v7->RefCount;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v7);
  v9 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v4, &result, "y");
  v15 = 0;
  (*(void (__fastcall **)(char *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, char *))(*(_QWORD *)v5 + 80i64))(
    v5,
    v4,
    v9,
    v3 + 1,
    &v15);
  v10 = result.pNode;
  v8 = result.pNode->RefCount == 1;
  --v10->RefCount;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v10);
  v11 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v4, &result, "width");
  v15 = 0;
  (*(void (__fastcall **)(char *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, char *))(*(_QWORD *)v5 + 80i64))(
    v5,
    v4,
    v11,
    v3 + 2,
    &v15);
  v12 = result.pNode;
  v8 = result.pNode->RefCount == 1;
  --v12->RefCount;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v12);
  v13 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v4, &result, "height");
  v15 = 0;
  (*(void (__fastcall **)(char *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, char *))(*(_QWORD *)v5 + 80i64))(
    v5,
    v4,
    v13,
    v3 + 3,
    &v15);
  v14 = result.pNode;
  v8 = result.pNode->RefCount == 1;
  --v14->RefCount;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v14);
}

// File Line: 341
// RVA: 0x71ACA0
void __fastcall Scaleform::GFx::AS2::RectangleObject::SetProperties(Scaleform::GFx::AS2::RectangleObject *this, Scaleform::GFx::AS2::Environment *penv, Scaleform::Render::Rect<double> *r)
{
  Scaleform::Render::Rect<double> *v3; // rsi
  Scaleform::GFx::AS2::ASStringContext *v4; // rbx
  long double v5; // xmm0_8
  char *v6; // rdi
  Scaleform::GFx::ASString *v7; // rax
  Scaleform::GFx::ASStringNode *v8; // rcx
  bool v9; // zf
  Scaleform::GFx::ASStringNode *v10; // xmm0_8
  Scaleform::GFx::ASString *v11; // rax
  Scaleform::GFx::ASStringNode *v12; // rcx
  long double v13; // xmm0_8
  Scaleform::GFx::ASString *v14; // rax
  Scaleform::GFx::ASStringNode *v15; // rcx
  long double v16; // xmm0_8
  Scaleform::GFx::ASString *v17; // rax
  Scaleform::GFx::ASStringNode *v18; // rcx
  Scaleform::GFx::AS2::Value v19; // [rsp+38h] [rbp-28h]
  char v20; // [rsp+80h] [rbp+20h]
  Scaleform::GFx::ASString result; // [rsp+88h] [rbp+28h]

  v3 = r;
  v4 = &penv->StringContext;
  v5 = r->x1;
  v19.T.Type = 3;
  v19.NV.NumberValue = v5;
  v6 = (char *)&this->vfptr;
  v7 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(&penv->StringContext, &result, "x");
  v20 = 0;
  (*(void (__fastcall **)(char *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, char *))(*(_QWORD *)v6 + 80i64))(
    v6,
    v4,
    v7,
    &v19,
    &v20);
  v8 = result.pNode;
  v9 = result.pNode->RefCount == 1;
  --v8->RefCount;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v8);
  if ( v19.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v19);
  v10 = *(Scaleform::GFx::ASStringNode **)&v3->y1;
  v19.T.Type = 3;
  v19.V.pStringNode = v10;
  v11 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v4, &result, "y");
  v20 = 0;
  (*(void (__fastcall **)(char *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, char *))(*(_QWORD *)v6 + 80i64))(
    v6,
    v4,
    v11,
    &v19,
    &v20);
  v12 = result.pNode;
  v9 = result.pNode->RefCount == 1;
  --v12->RefCount;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v12);
  if ( v19.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v19);
  v13 = v3->x2 - v3->x1;
  v19.T.Type = 3;
  v19.NV.NumberValue = v13;
  v14 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v4, &result, "width");
  v20 = 0;
  (*(void (__fastcall **)(char *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, char *))(*(_QWORD *)v6 + 80i64))(
    v6,
    v4,
    v14,
    &v19,
    &v20);
  v15 = result.pNode;
  v9 = result.pNode->RefCount == 1;
  --v15->RefCount;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v15);
  if ( v19.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v19);
  v16 = v3->y2 - v3->y1;
  v19.T.Type = 3;
  v19.NV.NumberValue = v16;
  v17 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v4, &result, "height");
  v20 = 0;
  (*(void (__fastcall **)(char *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, char *))(*(_QWORD *)v6 + 80i64))(
    v6,
    v4,
    v17,
    &v19,
    &v20);
  v18 = result.pNode;
  v9 = result.pNode->RefCount == 1;
  --v18->RefCount;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v18);
  if ( v19.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v19);
}

// File Line: 377
// RVA: 0x6CB730
void __fastcall Scaleform::GFx::AS2::RectangleProto::RectangleProto(Scaleform::GFx::AS2::RectangleProto *this, Scaleform::GFx::AS2::ASStringContext *psc, Scaleform::GFx::AS2::Object *pprototype, Scaleform::GFx::AS2::FunctionRef *constructor)
{
  Scaleform::GFx::AS2::ASStringContext *v4; // rbx
  Scaleform::GFx::AS2::RectangleProto *v5; // rsi
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
  Scaleform::GFx::AS2::PropFlags flags; // [rsp+30h] [rbp-40h]
  Scaleform::GFx::ASString result; // [rsp+38h] [rbp-38h]
  __int64 v23; // [rsp+40h] [rbp-30h]
  Scaleform::GFx::AS2::Value val; // [rsp+48h] [rbp-28h]

  v23 = -2i64;
  v4 = psc;
  v5 = this;
  Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::RectangleObject,Scaleform::GFx::AS2::Environment>::Prototype<Scaleform::GFx::AS2::RectangleObject,Scaleform::GFx::AS2::Environment>(
    (Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::RectangleObject,Scaleform::GFx::AS2::Environment> *)&this->vfptr,
    psc,
    pprototype,
    constructor);
  v5->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::RectangleProto::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
  v5->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::RectangleProto::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  v5->vfptr = (Scaleform::GFx::AS2::GASPrototypeBaseVtbl *)&Scaleform::GFx::AS2::RectangleProto::`vftable';
  flags.Flags = 6;
  Scaleform::GFx::AS2::GASPrototypeBase::InitFunctionMembers(
    (Scaleform::GFx::AS2::GASPrototypeBase *)&v5->vfptr,
    (Scaleform::GFx::AS2::Object *)&v5->vfptr,
    v4,
    Scaleform::GFx::AS2::RectangleProto::FunctionTable,
    &flags);
  flags.Flags = 2;
  val.T.Type = 4;
  val.NV.Int32Value = 0;
  v6 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v4, &result, "left");
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
  v9 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v4, &result, "top");
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
  v11 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v4, &result, "right");
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
  v13 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v4, &result, "bottom");
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
  v15 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v4, &result, "topLeft");
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
  v17 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v4, &result, "bottomRight");
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
  v19 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v4, &result, "size");
  Scaleform::GFx::AS2::Object::SetMemberRaw((Scaleform::GFx::AS2::Object *)&v5->vfptr, v4, v19, &val, &flags);
  v20 = result.pNode;
  v8 = result.pNode->RefCount == 1;
  --v20->RefCount;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v20);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
}

// File Line: 396
// RVA: 0x6B4DD0
void __fastcall Scaleform::GFx::AS2::RectangleProto::Clone(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rdi
  Scaleform::GFx::AS2::ObjectInterface *v2; // rcx
  __int64 v3; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v4; // rax
  Scaleform::GFx::AS2::RectangleObject *v5; // rbx
  Scaleform::GFx::AS2::RectangleObject *v6; // rsi
  Scaleform::GFx::AS2::RectangleObject *v7; // rax
  Scaleform::GFx::AS2::RectangleObject *v8; // rax
  unsigned int v9; // eax
  char ptr; // [rsp+40h] [rbp-98h]

  v1 = fn;
  v2 = fn->ThisPtr;
  if ( v2 && (*(unsigned int (**)(void))&v2->vfptr->gap8[8])() == 17 )
  {
    v4 = v1->ThisPtr;
    v5 = 0i64;
    v6 = (Scaleform::GFx::AS2::RectangleObject *)&v4[-2];
    if ( !v4 )
      v6 = 0i64;
    v7 = (Scaleform::GFx::AS2::RectangleObject *)((__int64 (__fastcall *)(__int64, signed __int64))v1->Env->StringContext.pContext->pHeap->vfptr->Alloc)(
                                                   v3,
                                                   96i64);
    if ( v7 )
    {
      Scaleform::GFx::AS2::RectangleObject::RectangleObject(v7, v1->Env);
      v5 = v8;
    }
    `eh vector constructor iterator'(&ptr, 0x20ui64, 4, (void (__fastcall *)(void *))Scaleform::GFx::AS2::Value::Value);
    Scaleform::GFx::AS2::RectangleObject::GetProperties(v6, &v1->Env->StringContext, (Scaleform::GFx::AS2::Value *)&ptr);
    Scaleform::GFx::AS2::RectangleObject::SetProperties(v5, &v1->Env->StringContext, (Scaleform::GFx::AS2::Value *)&ptr);
    Scaleform::GFx::AS2::Value::SetAsObject(v1->Result, (Scaleform::GFx::AS2::Object *)&v5->vfptr);
    `eh vector destructor iterator'(&ptr, 0x20ui64, 4, (void (__fastcall *)(void *))Scaleform::GFx::AS2::Value::~Value);
    if ( v5 )
    {
      v9 = v5->RefCount;
      if ( v9 & 0x3FFFFFF )
      {
        v5->RefCount = v9 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v5->vfptr);
      }
    }
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      v1->Env,
      "Error: Null or invalid 'this' is used for a method of %s class.\n",
      "Rectangle");
  }
}

// File Line: 413
// RVA: 0x6B4F30
void __fastcall Scaleform::GFx::AS2::RectangleProto::Contains(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rbx
  unsigned int v2; // er9
  Scaleform::GFx::AS2::Environment *v3; // rdx
  char v4; // di
  Scaleform::GFx::AS2::Value *v5; // r8
  unsigned int v6; // er8
  Scaleform::GFx::AS2::Environment *v7; // r9
  Scaleform::GFx::AS2::Value *v8; // rdx
  Scaleform::GFx::AS2::ObjectInterface *v9; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v10; // rax
  Scaleform::GFx::AS2::RectangleObject *v11; // rcx
  double v12; // xmm6_8
  double v13; // xmm0_8
  Scaleform::GFx::AS2::Value *v14; // rbx
  Scaleform::GFx::AS2::Value *v15; // rbx
  Scaleform::Render::Rect<double> r; // [rsp+28h] [rbp-80h]
  Scaleform::GFx::AS2::Value v17; // [rsp+48h] [rbp-60h]
  Scaleform::GFx::AS2::Value v18; // [rsp+68h] [rbp-40h]

  v1 = fn;
  if ( fn->NArgs <= 1 )
  {
    v15 = fn->Result;
    Scaleform::GFx::AS2::Value::DropRefs(fn->Result);
    v15->T.Type = 2;
    v15->V.BooleanValue = 0;
  }
  else
  {
    v2 = fn->FirstArgBottomIndex;
    v3 = fn->Env;
    v4 = 0;
    v5 = 0i64;
    if ( v2 <= 32 * ((unsigned int)v3->Stack.Pages.Data.Size - 1)
             + (unsigned int)((_QWORD)((char *)v3->Stack.pCurrent - (char *)v3->Stack.pPageStart) >> 5) )
      v5 = &v3->Stack.Pages.Data.Data[v2 >> 5]->Values[v2 & 0x1F];
    Scaleform::GFx::AS2::Value::Value(&v18, v5);
    v6 = v1->FirstArgBottomIndex - 1;
    v7 = v1->Env;
    v8 = 0i64;
    if ( v6 <= 32 * ((unsigned int)v7->Stack.Pages.Data.Size - 1)
             + (unsigned int)((_QWORD)((char *)v7->Stack.pCurrent - (char *)v7->Stack.pPageStart) >> 5) )
      v8 = &v7->Stack.Pages.Data.Data[v6 >> 5]->Values[v6 & 0x1F];
    Scaleform::GFx::AS2::Value::Value(&v17, v8);
    v9 = v1->ThisPtr;
    if ( v9 && (*(unsigned int (__cdecl **)(Scaleform::GFx::AS2::ObjectInterface *))&v9->vfptr->gap8[8])(v9) == 17 )
    {
      v10 = v1->ThisPtr;
      v11 = (Scaleform::GFx::AS2::RectangleObject *)&v10[-2];
      if ( !v10 )
        v11 = 0i64;
      r.x1 = 0.0;
      r.y1 = 0.0;
      r.x2 = 0.0;
      r.y2 = 0.0;
      Scaleform::GFx::AS2::RectangleObject::GetProperties(v11, v1->Env, &r);
      v12 = Scaleform::GFx::AS2::Value::ToNumber(&v18, v1->Env);
      v13 = Scaleform::GFx::AS2::Value::ToNumber(&v17, v1->Env);
      if ( (*(_QWORD *)&v12 & 0x7FF0000000000000i64) == 9218868437227405312i64 && *(_QWORD *)&v12 & 0xFFFFFFFFFFFFFi64
        || (*(_QWORD *)&v13 & 0x7FF0000000000000i64) == 9218868437227405312i64 && *(_QWORD *)&v13 & 0xFFFFFFFFFFFFFi64 )
      {
        v14 = v1->Result;
        Scaleform::GFx::AS2::Value::DropRefs(v14);
        v14->V.BooleanValue = 0;
      }
      else
      {
        if ( v12 == r.x2 )
          v12 = v12 + 1.0;
        if ( v13 == r.y2 )
          v13 = v13 + 1.0;
        if ( v12 <= r.x2 && v12 >= r.x1 && v13 <= r.y2 && v13 >= r.y1 )
          v4 = 1;
        v14 = v1->Result;
        Scaleform::GFx::AS2::Value::DropRefs(v14);
        v14->V.BooleanValue = v4;
      }
      v14->T.Type = 2;
    }
    else
    {
      Scaleform::GFx::AS2::Environment::LogScriptError(
        v1->Env,
        "Error: Null or invalid 'this' is used for a method of %s class.\n",
        "Rectangle");
    }
    if ( v17.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v17);
    if ( v18.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v18);
  }
}

// File Line: 455
// RVA: 0x6B51A0
void __fastcall Scaleform::GFx::AS2::RectangleProto::ContainsPoint(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rsi
  unsigned int v2; // er10
  Scaleform::GFx::AS2::Environment *v3; // r9
  char v4; // bp
  Scaleform::GFx::AS2::Value *v5; // rcx
  Scaleform::GFx::AS2::PointObject *v6; // r14
  Scaleform::GFx::AS2::ObjectInterface *v7; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v8; // rax
  Scaleform::GFx::AS2::RectangleObject *v9; // rbx
  Scaleform::GFx::AS2::Environment *v10; // rbx
  double v11; // xmm7_8
  double v12; // xmm6_8
  Scaleform::GFx::AS2::Value *v13; // rbx
  Scaleform::Render::Point<double> pt; // [rsp+38h] [rbp-B0h]
  Scaleform::Render::Rect<double> r; // [rsp+48h] [rbp-A0h]
  char ptr; // [rsp+70h] [rbp-78h]
  char v17; // [rsp+90h] [rbp-58h]

  v1 = fn;
  if ( fn->NArgs > 0 )
  {
    v2 = fn->FirstArgBottomIndex;
    v3 = fn->Env;
    v4 = 0;
    v5 = 0i64;
    if ( v2 <= 32 * ((unsigned int)v3->Stack.Pages.Data.Size - 1)
             + (unsigned int)((_QWORD)((char *)v3->Stack.pCurrent - (char *)v3->Stack.pPageStart) >> 5) )
      v5 = &v3->Stack.Pages.Data.Data[v2 >> 5]->Values[v2 & 0x1F];
    v6 = (Scaleform::GFx::AS2::PointObject *)Scaleform::GFx::AS2::Value::ToObject(v5, v3);
    if ( v6 )
    {
      v7 = v1->ThisPtr;
      if ( v7 && (*(unsigned int (**)(void))&v7->vfptr->gap8[8])() == 17 )
      {
        v8 = v1->ThisPtr;
        v9 = (Scaleform::GFx::AS2::RectangleObject *)&v8[-2];
        if ( !v8 )
          v9 = 0i64;
        r.x1 = 0.0;
        r.y1 = 0.0;
        r.x2 = 0.0;
        r.y2 = 0.0;
        `eh vector constructor iterator'(
          &ptr,
          0x20ui64,
          2,
          (void (__fastcall *)(void *))Scaleform::GFx::AS2::Value::Value);
        Scaleform::GFx::AS2::RectangleObject::GetProperties(v9, v1->Env, &r);
        v10 = v1->Env;
        ((void (__fastcall *)(Scaleform::GFx::AS2::ObjectInterfaceVtbl **, Scaleform::GFx::AS2::ASStringContext *, Scaleform::Ptr<Scaleform::GFx::ASSupport> *, char *, void (__fastcall *)(Scaleform::GFx::AS2::Value *)))v6->vfptr->GetMemberRaw)(
          &v6->vfptr,
          &v10->StringContext,
          &v10->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[33].pASSupport,
          &ptr,
          Scaleform::GFx::AS2::Value::~Value);
        v6->vfptr->GetMemberRaw(
          (Scaleform::GFx::AS2::ObjectInterface *)&v6->vfptr,
          &v10->StringContext,
          (Scaleform::GFx::ASString *)&v10->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[33].AVMVersion,
          (Scaleform::GFx::AS2::Value *)&v17);
        if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterfaceVtbl **))&v6->vfptr->gap8[8])(&v6->vfptr) == 16
          || ptr && ptr != 10 && v17 && v17 != 10 )
        {
          Scaleform::GFx::AS2::PointObject::GetProperties(v6, v1->Env, &pt);
          v11 = pt.x;
          if ( Scaleform::GFx::NumberUtil::IsNaN(pt.x) || (v12 = pt.y, Scaleform::GFx::NumberUtil::IsNaN(pt.y)) )
          {
            v13 = v1->Result;
            Scaleform::GFx::AS2::Value::DropRefs(v1->Result);
            v13->V.BooleanValue = 0;
          }
          else
          {
            if ( v11 == r.x2 )
              v11 = v11 + 1.0;
            if ( v12 == r.y2 )
              v12 = v12 + 1.0;
            if ( v11 <= r.x2 && v11 >= r.x1 && v12 <= r.y2 && v12 >= r.y1 )
              v4 = 1;
            v13 = v1->Result;
            Scaleform::GFx::AS2::Value::DropRefs(v1->Result);
            v13->V.BooleanValue = v4;
          }
          v13->T.Type = 2;
        }
        `eh vector destructor iterator'(
          &ptr,
          0x20ui64,
          2,
          (void (__fastcall *)(void *))Scaleform::GFx::AS2::Value::~Value);
      }
      else
      {
        Scaleform::GFx::AS2::Environment::LogScriptError(
          v1->Env,
          "Error: Null or invalid 'this' is used for a method of %s class.\n",
          "Rectangle");
      }
    }
  }
}

// File Line: 503
// RVA: 0x6B5610
void __fastcall Scaleform::GFx::AS2::RectangleProto::ContainsRectangle(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rbx
  unsigned int v2; // er10
  Scaleform::GFx::AS2::Environment *v3; // r9
  char v4; // di
  Scaleform::GFx::AS2::Value *v5; // rcx
  Scaleform::GFx::AS2::Object *v6; // rbp
  Scaleform::GFx::AS2::ObjectInterface *v7; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v8; // rax
  Scaleform::GFx::AS2::RectangleObject *v9; // rsi
  double v10; // xmm6_8
  double v11; // xmm7_8
  double v12; // xmm8_8
  double v13; // xmm3_8
  Scaleform::GFx::AS2::Value *v14; // rbx
  Scaleform::Render::Rect<double> r; // [rsp+30h] [rbp-E8h]
  __int64 v16; // [rsp+50h] [rbp-C8h]
  Scaleform::GFx::AS2::Value ptr; // [rsp+60h] [rbp-B8h]
  Scaleform::GFx::AS2::Value v18; // [rsp+80h] [rbp-98h]
  Scaleform::GFx::AS2::Value v19; // [rsp+A0h] [rbp-78h]
  Scaleform::GFx::AS2::Value v20; // [rsp+C0h] [rbp-58h]

  v16 = -2i64;
  v1 = fn;
  if ( fn->NArgs > 0 )
  {
    v2 = fn->FirstArgBottomIndex;
    v3 = fn->Env;
    v4 = 0;
    v5 = 0i64;
    if ( v2 <= 32 * ((unsigned int)v3->Stack.Pages.Data.Size - 1)
             + (unsigned int)((_QWORD)((char *)v3->Stack.pCurrent - (char *)v3->Stack.pPageStart) >> 5) )
      v5 = &v3->Stack.Pages.Data.Data[v2 >> 5]->Values[v2 & 0x1F];
    v6 = Scaleform::GFx::AS2::Value::ToObject(v5, v3);
    if ( v6 )
    {
      v7 = v1->ThisPtr;
      if ( v7 && (*(unsigned int (**)(void))&v7->vfptr->gap8[8])() == 17 )
      {
        v8 = v1->ThisPtr;
        v9 = (Scaleform::GFx::AS2::RectangleObject *)&v8[-2];
        if ( !v8 )
          v9 = 0i64;
        r.x1 = 0.0;
        r.y1 = 0.0;
        r.x2 = 0.0;
        r.y2 = 0.0;
        `eh vector constructor iterator'(
          &ptr,
          0x20ui64,
          4,
          (void (__fastcall *)(void *))Scaleform::GFx::AS2::Value::Value);
        Scaleform::GFx::AS2::RectangleObject::GetProperties(v9, v1->Env, &r);
        Scaleform::GFx::AS2::GFxObject_GetRectangleProperties(v1->Env, v6, &ptr);
        if ( ptr.T.Type
          && ptr.T.Type != 10
          && v18.T.Type
          && v18.T.Type != 10
          && v19.T.Type
          && v19.T.Type != 10
          && v20.T.Type
          && v20.T.Type != 10 )
        {
          v10 = Scaleform::GFx::AS2::Value::ToNumber(&v20, v1->Env);
          v11 = Scaleform::GFx::AS2::Value::ToNumber(&v19, v1->Env);
          v12 = Scaleform::GFx::AS2::Value::ToNumber(&v18, v1->Env);
          v13 = Scaleform::GFx::AS2::Value::ToNumber(&ptr, v1->Env);
          if ( r.x2 >= v11 + v13 && r.y2 >= v12 + v10 && r.x1 <= v13 && r.y1 <= v12 )
            v4 = 1;
          v14 = v1->Result;
          Scaleform::GFx::AS2::Value::DropRefs(v14);
          v14->T.Type = 2;
          v14->V.BooleanValue = v4;
        }
        `eh vector destructor iterator'(
          &ptr,
          0x20ui64,
          4,
          (void (__fastcall *)(void *))Scaleform::GFx::AS2::Value::~Value);
      }
      else
      {
        Scaleform::GFx::AS2::Environment::LogScriptError(
          v1->Env,
          "Error: Null or invalid 'this' is used for a method of %s class.\n",
          "Rectangle");
      }
    }
  }
}

// File Line: 539
// RVA: 0x6B58A0
void __fastcall Scaleform::GFx::AS2::RectangleProto::Equals(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rbx
  bool v2; // si
  unsigned int v3; // er10
  Scaleform::GFx::AS2::Environment *v4; // r9
  Scaleform::GFx::AS2::RectangleObject *v5; // rbp
  Scaleform::GFx::AS2::Value *v6; // rcx
  Scaleform::GFx::AS2::Object *v7; // rax
  Scaleform::GFx::AS2::RectangleObject *v8; // rdi
  Scaleform::GFx::AS2::ObjectInterface *v9; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v10; // rax
  unsigned int v11; // eax
  Scaleform::GFx::AS2::Value *v12; // rbx
  Scaleform::Render::Rect<double> r; // [rsp+28h] [rbp-50h]
  Scaleform::Render::Rect<double> v14; // [rsp+48h] [rbp-30h]

  v1 = fn;
  v2 = 0;
  if ( fn->NArgs > 0 )
  {
    v3 = fn->FirstArgBottomIndex;
    v4 = fn->Env;
    v5 = 0i64;
    v6 = 0i64;
    if ( v3 <= 32 * ((unsigned int)v4->Stack.Pages.Data.Size - 1)
             + (unsigned int)((_QWORD)((char *)v4->Stack.pCurrent - (char *)v4->Stack.pPageStart) >> 5) )
      v6 = &v4->Stack.Pages.Data.Data[v3 >> 5]->Values[v3 & 0x1F];
    v7 = Scaleform::GFx::AS2::Value::ToObject(v6, v4);
    v8 = (Scaleform::GFx::AS2::RectangleObject *)v7;
    if ( v7 )
    {
      if ( (*(unsigned int (__cdecl **)(Scaleform::GFx::AS2::ObjectInterfaceVtbl **))&v7->vfptr->gap8[8])(&v7->vfptr) == 17 )
      {
        v9 = v1->ThisPtr;
        if ( !v9 || (*(unsigned int (__cdecl **)(Scaleform::GFx::AS2::ObjectInterface *))&v9->vfptr->gap8[8])(v9) != 17 )
        {
          Scaleform::GFx::AS2::Environment::LogScriptError(
            v1->Env,
            "Error: Null or invalid 'this' is used for a method of %s class.\n",
            "Rectangle");
          return;
        }
        v10 = v1->ThisPtr;
        if ( v10 )
          v5 = (Scaleform::GFx::AS2::RectangleObject *)&v10[-2];
        v8->RefCount = (v8->RefCount + 1) & 0x8FFFFFFF;
        r.x1 = 0.0;
        r.y1 = 0.0;
        r.x2 = 0.0;
        r.y2 = 0.0;
        v14.x1 = 0.0;
        v14.y1 = 0.0;
        v14.x2 = 0.0;
        v14.y2 = 0.0;
        Scaleform::GFx::AS2::RectangleObject::GetProperties(v5, v1->Env, &r);
        Scaleform::GFx::AS2::RectangleObject::GetProperties(v8, v1->Env, &v14);
        if ( Scaleform::GFx::AS2::IsRectValid(&r) && Scaleform::GFx::AS2::IsRectValid(&v14) )
          v2 = r.x1 == v14.x1 && r.x2 == v14.x2 && r.y1 == v14.y1 && r.y2 == v14.y2;
        v11 = v8->RefCount;
        if ( v11 & 0x3FFFFFF )
        {
          v8->RefCount = v11 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v8->vfptr);
        }
      }
    }
  }
  v12 = v1->Result;
  Scaleform::GFx::AS2::Value::DropRefs(v12);
  v12->T.Type = 2;
  v12->V.BooleanValue = v2;
}

// File Line: 566
// RVA: 0x6B5B60
void __fastcall Scaleform::GFx::AS2::RectangleProto::Inflate(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rbx
  char v2; // di
  Scaleform::GFx::AS2::RectangleObject *v3; // rsi
  unsigned int v4; // er9
  Scaleform::GFx::AS2::Environment *v5; // r8
  Scaleform::GFx::AS2::Value *v6; // rdx
  unsigned int v7; // edx
  Scaleform::GFx::AS2::Environment *v8; // r9
  Scaleform::GFx::AS2::Value *v9; // r8
  Scaleform::GFx::AS2::ObjectInterface *v10; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v11; // rax
  double v12; // xmm6_8
  long double v13; // xmm0_8
  Scaleform::Render::Rect<double> r; // [rsp+20h] [rbp-21h]
  Scaleform::GFx::AS2::Value v15; // [rsp+40h] [rbp-1h]
  Scaleform::GFx::AS2::Value v16; // [rsp+60h] [rbp+1Fh]

  v1 = fn;
  v16.T.Type = 0;
  v2 = 0;
  v15.T.Type = 0;
  v3 = 0i64;
  if ( fn->NArgs > 0 )
  {
    v4 = fn->FirstArgBottomIndex;
    v5 = fn->Env;
    v6 = 0i64;
    if ( v4 <= 32 * ((unsigned int)v5->Stack.Pages.Data.Size - 1)
             + (unsigned int)((_QWORD)((char *)v5->Stack.pCurrent - (char *)v5->Stack.pPageStart) >> 5) )
      v6 = &v5->Stack.Pages.Data.Data[v4 >> 5]->Values[v4 & 0x1F];
    Scaleform::GFx::AS2::Value::operator=(&v16, v6);
    if ( v1->NArgs > 1 )
    {
      v7 = v1->FirstArgBottomIndex - 1;
      v8 = v1->Env;
      v9 = 0i64;
      if ( v7 <= 32 * ((unsigned int)v8->Stack.Pages.Data.Size - 1)
               + (unsigned int)((_QWORD)((char *)v8->Stack.pCurrent - (char *)v8->Stack.pPageStart) >> 5) )
        v9 = &v8->Stack.Pages.Data.Data[v7 >> 5]->Values[v7 & 0x1F];
      Scaleform::GFx::AS2::Value::operator=(&v15, v9);
      v2 = v15.T.Type;
    }
  }
  v10 = v1->ThisPtr;
  if ( v10 && (*(unsigned int (**)(void))&v10->vfptr->gap8[8])() == 17 )
  {
    v11 = v1->ThisPtr;
    if ( v11 )
      v3 = (Scaleform::GFx::AS2::RectangleObject *)&v11[-2];
    *(_OWORD *)&r.x1 = 0ui64;
    *(_OWORD *)&r.x2 = 0ui64;
    Scaleform::GFx::AS2::RectangleObject::GetProperties(v3, v1->Env, &r);
    v12 = Scaleform::GFx::AS2::Value::ToNumber(&v15, v1->Env);
    v13 = Scaleform::GFx::AS2::Value::ToNumber(&v16, v1->Env);
    r.x1 = r.x1 - v13;
    r.x2 = r.x2 + v13;
    r.y1 = r.y1 - v12;
    r.y2 = r.y2 + v12;
    Scaleform::GFx::AS2::RectangleObject::SetProperties(v3, v1->Env, &r);
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      v1->Env,
      "Error: Null or invalid 'this' is used for a method of %s class.\n",
      "Rectangle");
  }
  if ( (unsigned __int8)v2 >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v15);
  if ( v16.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v16);
}

// File Line: 592
// RVA: 0x6B5E30
void __fastcall Scaleform::GFx::AS2::RectangleProto::InflatePoint(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rbx
  Scaleform::GFx::AS2::ObjectInterface *v2; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rdi
  Scaleform::GFx::AS2::Value *v4; // r9
  Scaleform::GFx::AS2::RectangleObject *v5; // rdi
  Scaleform::GFx::AS2::Environment *v6; // rdx
  unsigned __int64 v7; // r8
  Scaleform::GFx::AS2::Object *v8; // rax
  Scaleform::GFx::AS2::Environment *v9; // rdx
  Scaleform::GFx::AS2::Object *v10; // rsi
  Scaleform::GFx::AS2::Environment *v11; // rdx
  Scaleform::Render::Point<double> pt; // [rsp+20h] [rbp-38h]
  Scaleform::Render::Rect<double> r; // [rsp+30h] [rbp-28h]

  v1 = fn;
  if ( fn->NArgs > 0 )
  {
    v2 = fn->ThisPtr;
    if ( v2 && (*(unsigned int (**)(void))&v2->vfptr->gap8[8])() == 17 )
    {
      v3 = v1->ThisPtr;
      v4 = 0i64;
      if ( v3 )
        v5 = (Scaleform::GFx::AS2::RectangleObject *)&v3[-2];
      else
        v5 = 0i64;
      v6 = v1->Env;
      v7 = (unsigned int)v1->FirstArgBottomIndex;
      if ( (unsigned int)v7 <= 32 * (LODWORD(v6->Stack.Pages.Data.Size) - 1)
                             + (unsigned int)((_QWORD)((char *)v6->Stack.pCurrent - (char *)v6->Stack.pPageStart) >> 5) )
        v4 = &v6->Stack.Pages.Data.Data[v7 >> 5]->Values[v1->FirstArgBottomIndex & 0x1F];
      v8 = Scaleform::GFx::AS2::Value::ToObject(v4, v6);
      v9 = v1->Env;
      v10 = v8;
      if ( v8 )
      {
        *(_OWORD *)&r.x1 = 0ui64;
        *(_OWORD *)&r.x2 = 0ui64;
        Scaleform::GFx::AS2::RectangleObject::GetProperties(v5, v9, &r);
        Scaleform::GFx::AS2::GFxObject_GetPointProperties(v1->Env, v10, &pt);
        v11 = v1->Env;
        r.x1 = r.x1 - pt.x;
        r.x2 = r.x2 + pt.x;
        r.y1 = r.y1 - pt.y;
        r.y2 = r.y2 + pt.y;
        Scaleform::GFx::AS2::RectangleObject::SetProperties(v5, v11, &r);
      }
      else
      {
        Scaleform::GFx::AS2::RectangleObject::SetProperties(v5, &v9->StringContext, Rectangle_NaNParams);
      }
    }
    else
    {
      Scaleform::GFx::AS2::Environment::LogScriptError(
        v1->Env,
        "Error: Null or invalid 'this' is used for a method of %s class.\n",
        "Rectangle");
    }
  }
}

// File Line: 621
// RVA: 0x6B5FB0
void __fastcall Scaleform::GFx::AS2::RectangleProto::Intersection(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rbx
  double v2; // xmm11_8
  double v3; // xmm10_8
  double v4; // xmm9_8
  double v5; // xmm8_8
  Scaleform::GFx::AS2::ObjectInterface *v6; // rcx
  __int64 v7; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v8; // rax
  Scaleform::GFx::AS2::RectangleObject *v9; // rdi
  Scaleform::GFx::AS2::RectangleObject *v10; // rsi
  unsigned int v11; // er10
  Scaleform::GFx::AS2::Environment *v12; // rdx
  Scaleform::GFx::AS2::Value *v13; // r9
  Scaleform::GFx::AS2::Object *v14; // r14
  double v15; // xmm6_8
  double v16; // xmm12_8
  double v17; // xmm15_8
  double v18; // xmm13_8
  double v19; // xmm14_8
  double v20; // xmm12_8
  Scaleform::GFx::AS2::RectangleObject *v21; // rax
  Scaleform::GFx::AS2::RectangleObject *v22; // rax
  unsigned int v23; // eax
  Scaleform::Render::Rect<double> v24; // [rsp+30h] [rbp-A8h]
  Scaleform::Render::Rect<double> r; // [rsp+50h] [rbp-88h]
  Scaleform::Render::Rect<double> ptr; // [rsp+70h] [rbp-68h]
  Scaleform::GFx::AS2::Value v27; // [rsp+98h] [rbp-40h]
  Scaleform::GFx::AS2::Value v28; // [rsp+B8h] [rbp-20h]
  Scaleform::GFx::AS2::Value v29; // [rsp+D8h] [rbp+0h]
  void *v30; // [rsp+1C8h] [rbp+F0h]
  Scaleform::GFx::AS2::RectangleObject *v31; // [rsp+1D0h] [rbp+F8h]

  r.y2 = -3.595386269724631e308/*NaN*/;
  v1 = fn;
  v2 = 0.0;
  v24.x1 = 0.0;
  v3 = 0.0;
  v24.y1 = 0.0;
  v4 = 0.0;
  v24.x2 = 0.0;
  v5 = 0.0;
  v24.y2 = 0.0;
  v6 = fn->ThisPtr;
  if ( v6 && (*(unsigned int (**)(void))&v6->vfptr->gap8[8])() == 17 )
  {
    v8 = v1->ThisPtr;
    v9 = 0i64;
    v10 = (Scaleform::GFx::AS2::RectangleObject *)&v8[-2];
    if ( !v8 )
      v10 = 0i64;
    if ( v1->NArgs > 0 )
    {
      v11 = v1->FirstArgBottomIndex;
      v12 = v1->Env;
      v13 = 0i64;
      if ( v11 <= 32 * ((unsigned int)v12->Stack.Pages.Data.Size - 1)
                + (unsigned int)((_QWORD)((char *)v12->Stack.pCurrent - (char *)v12->Stack.pPageStart) >> 5) )
        v13 = &v12->Stack.Pages.Data.Data[v11 >> 5]->Values[v11 & 0x1F];
      v14 = Scaleform::GFx::AS2::Value::ToObject(v13, v12);
      if ( v14 )
      {
        r.x1 = 0.0;
        r.y1 = 0.0;
        r.x2 = 0.0;
        r.y2 = 0.0;
        `eh vector constructor iterator'(
          &ptr.y1,
          0x20ui64,
          4,
          (void (__fastcall *)(void *))Scaleform::GFx::AS2::Value::Value);
        Scaleform::GFx::AS2::RectangleObject::GetProperties(v10, v1->Env, &r);
        Scaleform::GFx::AS2::GFxObject_GetRectangleProperties(v1->Env, v14, (Scaleform::GFx::AS2::Value *)&ptr.y1);
        v15 = Scaleform::GFx::AS2::Value::ToNumber(&v29, v1->Env);
        v16 = Scaleform::GFx::AS2::Value::ToNumber(&v28, v1->Env);
        v17 = Scaleform::GFx::AS2::Value::ToNumber(&v27, v1->Env);
        v18 = Scaleform::GFx::AS2::Value::ToNumber((Scaleform::GFx::AS2::Value *)&ptr.y1, v1->Env);
        v19 = v17 + v15;
        v20 = v16 + v18;
        ptr.x1 = v18;
        ptr.y1 = v17;
        r.y1 = v20;
        r.x2 = v17 + v15;
        if ( !Scaleform::GFx::AS2::IsRectValid(&ptr) )
          goto LABEL_39;
        if ( r.y2 >= v17 && v19 >= r.y1 && v20 >= r.x1 && r.x2 >= v18 )
        {
          if ( r.x1 <= v18 )
          {
            v2 = v18;
            v24.x1 = v18;
          }
          else
          {
            v2 = r.x1;
            v24.x1 = r.x1;
          }
          if ( r.x2 <= v20 )
          {
            v4 = r.x2;
            v24.x2 = r.x2;
          }
          else
          {
            v4 = v20;
            v24.x2 = v20;
          }
          if ( r.y1 <= v17 )
          {
            v3 = v17;
            v24.y1 = v17;
          }
          else
          {
            v3 = r.y1;
            v24.y1 = r.y1;
          }
          if ( r.y2 <= v19 )
          {
            v5 = r.y2;
            v24.y2 = r.y2;
          }
          else
          {
            v5 = v17 + v15;
            v24.y2 = v17 + v15;
          }
        }
        if ( !Scaleform::GFx::AS2::IsRectValid(&v24) || v4 - v2 == 0.0 || v5 - v3 == 0.0 )
        {
LABEL_39:
          v24.y2 = 0.0;
          v24.x2 = 0.0;
          v24.y1 = 0.0;
          v24.x1 = 0.0;
        }
        `eh vector destructor iterator'(
          &ptr.y1,
          0x20ui64,
          4,
          (void (__fastcall *)(void *))Scaleform::GFx::AS2::Value::~Value);
      }
    }
    v30 = v1->Env->StringContext.pContext->pHeap;
    v21 = (Scaleform::GFx::AS2::RectangleObject *)(*(__int64 (__fastcall **)(__int64, signed __int64))(*(_QWORD *)v30 + 80i64))(
                                                    v7,
                                                    96i64);
    v31 = v21;
    if ( v21 )
    {
      Scaleform::GFx::AS2::RectangleObject::RectangleObject(v21, v1->Env);
      v9 = v22;
    }
    v30 = v9;
    Scaleform::GFx::AS2::RectangleObject::SetProperties(v9, v1->Env, &v24);
    Scaleform::GFx::AS2::Value::SetAsObject(v1->Result, (Scaleform::GFx::AS2::Object *)&v9->vfptr);
    if ( v9 )
    {
      v23 = v9->RefCount;
      if ( v23 & 0x3FFFFFF )
      {
        v9->RefCount = v23 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v9->vfptr);
      }
    }
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      v1->Env,
      "Error: Null or invalid 'this' is used for a method of %s class.\n",
      "Rectangle");
  }
}

// File Line: 669
// RVA: 0x6B63A0
void __fastcall Scaleform::GFx::AS2::RectangleProto::Intersects(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rbx
  Scaleform::GFx::AS2::ObjectInterface *v2; // rcx
  char v3; // di
  Scaleform::GFx::AS2::ObjectInterface *v4; // rax
  Scaleform::GFx::AS2::Value *v5; // r9
  Scaleform::GFx::AS2::RectangleObject *v6; // rsi
  unsigned int v7; // er10
  Scaleform::GFx::AS2::Environment *v8; // rdx
  Scaleform::GFx::AS2::Object *v9; // r14
  double v10; // xmm12_8
  double v11; // xmm10_8
  double v12; // xmm13_8
  double v13; // xmm11_8
  double v14; // xmm12_8
  double v15; // xmm10_8
  double v16; // xmm9_8
  double v17; // xmm8_8
  double v18; // xmm7_8
  double v19; // xmm6_8
  Scaleform::GFx::AS2::Value *v20; // rbx
  Scaleform::Render::Rect<double> v21; // [rsp+30h] [rbp-B8h]
  Scaleform::Render::Rect<double> r; // [rsp+50h] [rbp-98h]
  Scaleform::Render::Rect<double> ptr; // [rsp+70h] [rbp-78h]
  Scaleform::GFx::AS2::Value v24; // [rsp+A8h] [rbp-40h]
  Scaleform::GFx::AS2::Value v25; // [rsp+C8h] [rbp-20h]
  Scaleform::GFx::AS2::Value v26; // [rsp+E8h] [rbp+0h]

  ptr.y1 = -3.595386269724631e308/*NaN*/;
  v1 = fn;
  v2 = fn->ThisPtr;
  if ( v2 && (*(unsigned int (**)(void))&v2->vfptr->gap8[8])() == 17 )
  {
    v3 = 0;
    v4 = v1->ThisPtr;
    v5 = 0i64;
    v6 = (Scaleform::GFx::AS2::RectangleObject *)&v4[-2];
    if ( !v4 )
      v6 = 0i64;
    if ( v1->NArgs > 0 )
    {
      v7 = v1->FirstArgBottomIndex;
      v8 = v1->Env;
      if ( v7 <= 32 * ((unsigned int)v8->Stack.Pages.Data.Size - 1)
               + (unsigned int)((_QWORD)((char *)v8->Stack.pCurrent - (char *)v8->Stack.pPageStart) >> 5) )
        v5 = &v8->Stack.Pages.Data.Data[v7 >> 5]->Values[v7 & 0x1F];
      v9 = Scaleform::GFx::AS2::Value::ToObject(v5, v8);
      if ( v9 )
      {
        r.x1 = 0.0;
        r.y1 = 0.0;
        r.x2 = 0.0;
        r.y2 = 0.0;
        `eh vector constructor iterator'(
          &ptr.y2,
          0x20ui64,
          4,
          (void (__fastcall *)(void *))Scaleform::GFx::AS2::Value::Value);
        Scaleform::GFx::AS2::RectangleObject::GetProperties(v6, v1->Env, &r);
        Scaleform::GFx::AS2::GFxObject_GetRectangleProperties(v1->Env, v9, (Scaleform::GFx::AS2::Value *)&ptr.y2);
        v10 = Scaleform::GFx::AS2::Value::ToNumber(&v26, v1->Env);
        v11 = Scaleform::GFx::AS2::Value::ToNumber(&v25, v1->Env);
        v12 = Scaleform::GFx::AS2::Value::ToNumber(&v24, v1->Env);
        v13 = Scaleform::GFx::AS2::Value::ToNumber((Scaleform::GFx::AS2::Value *)&ptr.y2, v1->Env);
        v14 = v10 + v12;
        v15 = v11 + v13;
        ptr.y1 = v12;
        r.y2 = v15;
        ptr.x1 = v14;
        v16 = 0.0;
        v21.x1 = 0.0;
        v17 = 0.0;
        v21.y1 = 0.0;
        v18 = 0.0;
        v21.x2 = 0.0;
        v19 = 0.0;
        v21.y2 = 0.0;
        if ( !Scaleform::GFx::AS2::IsRectValid(&r) || !Scaleform::GFx::AS2::IsRectValid(&ptr) )
          goto LABEL_36;
        if ( r.y2 >= v12 && v14 >= r.y1 && v15 >= r.x1 && r.x2 >= v13 )
        {
          if ( r.x1 <= v13 )
          {
            v16 = v13;
            v21.x1 = v13;
          }
          else
          {
            v16 = r.x1;
            v21.x1 = r.x1;
          }
          if ( r.x2 <= v15 )
          {
            v18 = r.x2;
            v21.x2 = r.x2;
          }
          else
          {
            v18 = v15;
            v21.x2 = v15;
          }
          if ( r.y1 <= v12 )
          {
            v17 = v12;
            v21.y1 = v12;
          }
          else
          {
            v17 = r.y1;
            v21.y1 = r.y1;
          }
          if ( r.y2 <= v14 )
          {
            v19 = r.y2;
            v21.y2 = r.y2;
          }
          else
          {
            v19 = v14;
            v21.y2 = v14;
          }
        }
        v3 = 1;
        if ( !Scaleform::GFx::AS2::IsRectValid(&v21) || v18 - v16 == 0.0 || v19 - v17 == 0.0 )
LABEL_36:
          v3 = 0;
        `eh vector destructor iterator'(
          &ptr.y2,
          0x20ui64,
          4,
          (void (__fastcall *)(void *))Scaleform::GFx::AS2::Value::~Value);
      }
    }
    v20 = v1->Result;
    Scaleform::GFx::AS2::Value::DropRefs(v20);
    v20->T.Type = 2;
    v20->V.BooleanValue = v3;
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      v1->Env,
      "Error: Null or invalid 'this' is used for a method of %s class.\n",
      "Rectangle");
  }
}

// File Line: 714
// RVA: 0x6B6720
void __fastcall Scaleform::GFx::AS2::RectangleProto::IsEmpty(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rbx
  Scaleform::GFx::AS2::ObjectInterface *v2; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rax
  Scaleform::GFx::AS2::RectangleObject *v4; // rdi
  double v5; // xmm0_8
  double v6; // xmm0_8
  double v7; // xmm6_8
  bool v8; // di
  Scaleform::GFx::AS2::Value *v9; // rbx
  char ptr; // [rsp+40h] [rbp-98h]
  Scaleform::GFx::AS2::Value v11; // [rsp+60h] [rbp-78h]
  Scaleform::GFx::AS2::Value v12; // [rsp+80h] [rbp-58h]
  Scaleform::GFx::AS2::Value v13; // [rsp+A0h] [rbp-38h]

  v1 = fn;
  v2 = fn->ThisPtr;
  if ( v2 && (*(unsigned int (**)(void))&v2->vfptr->gap8[8])() == 17 )
  {
    v3 = v1->ThisPtr;
    if ( v3 )
      v4 = (Scaleform::GFx::AS2::RectangleObject *)&v3[-2];
    else
      v4 = 0i64;
    `eh vector constructor iterator'(&ptr, 0x20ui64, 4, (void (__fastcall *)(void *))Scaleform::GFx::AS2::Value::Value);
    Scaleform::GFx::AS2::RectangleObject::GetProperties(v4, &v1->Env->StringContext, (Scaleform::GFx::AS2::Value *)&ptr);
    v5 = Scaleform::GFx::AS2::Value::ToNumber(&v12, v1->Env);
    v8 = 1;
    if ( (*(_QWORD *)&v5 & 0x7FF0000000000000i64) != 9218868437227405312i64 || !(*(_QWORD *)&v5 & 0xFFFFFFFFFFFFFi64) )
    {
      v6 = Scaleform::GFx::AS2::Value::ToNumber(&v13, v1->Env);
      if ( (*(_QWORD *)&v6 & 0x7FF0000000000000i64) != 9218868437227405312i64 || !(*(_QWORD *)&v6 & 0xFFFFFFFFFFFFFi64) )
      {
        Scaleform::GFx::AS2::Value::ToNumber((Scaleform::GFx::AS2::Value *)&ptr, v1->Env);
        Scaleform::GFx::AS2::Value::ToNumber(&v11, v1->Env);
        v7 = Scaleform::GFx::AS2::Value::ToNumber(&v13, v1->Env);
        if ( Scaleform::GFx::AS2::Value::ToNumber(&v12, v1->Env) > 0.0 && v7 > 0.0 )
          v8 = 0;
      }
    }
    v9 = v1->Result;
    Scaleform::GFx::AS2::Value::DropRefs(v9);
    v9->T.Type = 2;
    v9->V.BooleanValue = v8;
    `eh vector destructor iterator'(&ptr, 0x20ui64, 4, (void (__fastcall *)(void *))Scaleform::GFx::AS2::Value::~Value);
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      v1->Env,
      "Error: Null or invalid 'this' is used for a method of %s class.\n",
      "Rectangle");
  }
}

// File Line: 744
// RVA: 0x6B68F0
void __fastcall Scaleform::GFx::AS2::RectangleProto::Offset(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rbx
  Scaleform::GFx::AS2::ObjectInterface *v2; // rcx
  char v3; // si
  Scaleform::GFx::AS2::RectangleObject *v4; // rdi
  unsigned int v5; // er9
  Scaleform::GFx::AS2::Environment *v6; // r8
  Scaleform::GFx::AS2::Value *v7; // rdx
  unsigned int v8; // edx
  Scaleform::GFx::AS2::Environment *v9; // r9
  Scaleform::GFx::AS2::Value *v10; // r8
  Scaleform::GFx::AS2::ObjectInterface *v11; // rax
  double v12; // xmm6_8
  long double v13; // xmm0_8
  double v14; // xmm6_8
  long double v15; // xmm0_8
  Scaleform::GFx::AS2::Value v; // [rsp+30h] [rbp-C8h]
  Scaleform::GFx::AS2::Value v17; // [rsp+50h] [rbp-A8h]
  Scaleform::GFx::AS2::Value v18; // [rsp+70h] [rbp-88h]
  char ptr; // [rsp+98h] [rbp-60h]
  Scaleform::GFx::AS2::Value v20; // [rsp+B8h] [rbp-40h]

  *((_QWORD *)&v18.NV + 3) = -2i64;
  v1 = fn;
  v2 = fn->ThisPtr;
  if ( v2 && (*(unsigned int (**)(void))&v2->vfptr->gap8[8])() == 17 )
  {
    v18.T.Type = 0;
    v3 = 0;
    v17.T.Type = 0;
    v4 = 0i64;
    if ( v1->NArgs > 0 )
    {
      v5 = v1->FirstArgBottomIndex;
      v6 = v1->Env;
      v7 = 0i64;
      if ( v5 <= 32 * ((unsigned int)v6->Stack.Pages.Data.Size - 1)
               + (unsigned int)((_QWORD)((char *)v6->Stack.pCurrent - (char *)v6->Stack.pPageStart) >> 5) )
        v7 = &v6->Stack.Pages.Data.Data[v5 >> 5]->Values[v5 & 0x1F];
      Scaleform::GFx::AS2::Value::operator=(&v18, v7);
      if ( v1->NArgs > 1 )
      {
        v8 = v1->FirstArgBottomIndex - 1;
        v9 = v1->Env;
        v10 = 0i64;
        if ( v8 <= 32 * ((unsigned int)v9->Stack.Pages.Data.Size - 1)
                 + (unsigned int)((_QWORD)((char *)v9->Stack.pCurrent - (char *)v9->Stack.pPageStart) >> 5) )
          v10 = &v9->Stack.Pages.Data.Data[v8 >> 5]->Values[v8 & 0x1F];
        Scaleform::GFx::AS2::Value::operator=(&v17, v10);
        v3 = v17.T.Type;
      }
    }
    v11 = v1->ThisPtr;
    if ( v11 )
      v4 = (Scaleform::GFx::AS2::RectangleObject *)&v11[-2];
    `eh vector constructor iterator'(&ptr, 0x20ui64, 4, (void (__fastcall *)(void *))Scaleform::GFx::AS2::Value::Value);
    Scaleform::GFx::AS2::RectangleObject::GetProperties(v4, &v1->Env->StringContext, (Scaleform::GFx::AS2::Value *)&ptr);
    v12 = Scaleform::GFx::AS2::Value::ToNumber((Scaleform::GFx::AS2::Value *)&ptr, v1->Env);
    v13 = Scaleform::GFx::AS2::Value::ToNumber(&v18, v1->Env);
    v.T.Type = 3;
    v.NV.NumberValue = v12 + v13;
    Scaleform::GFx::AS2::Value::operator=((Scaleform::GFx::AS2::Value *)&ptr, &v);
    if ( v.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v);
    v14 = Scaleform::GFx::AS2::Value::ToNumber(&v20, v1->Env);
    v15 = Scaleform::GFx::AS2::Value::ToNumber(&v17, v1->Env);
    v.T.Type = 3;
    v.NV.NumberValue = v14 + v15;
    Scaleform::GFx::AS2::Value::operator=(&v20, &v);
    if ( v.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v);
    Scaleform::GFx::AS2::RectangleObject::SetProperties(v4, &v1->Env->StringContext, (Scaleform::GFx::AS2::Value *)&ptr);
    `eh vector destructor iterator'(&ptr, 0x20ui64, 4, (void (__fastcall *)(void *))Scaleform::GFx::AS2::Value::~Value);
    if ( (unsigned __int8)v3 >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v17);
    if ( v18.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v18);
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      v1->Env,
      "Error: Null or invalid 'this' is used for a method of %s class.\n",
      "Rectangle");
  }
}

// File Line: 773
// RVA: 0x6B6B60
void __fastcall Scaleform::GFx::AS2::RectangleProto::OffsetPoint(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rsi
  Scaleform::GFx::AS2::ObjectInterface *v2; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // r14
  Scaleform::GFx::AS2::Value *v4; // r9
  Scaleform::GFx::AS2::RectangleObject *v5; // r14
  unsigned int v6; // er10
  Scaleform::GFx::AS2::Environment *v7; // rdx
  Scaleform::GFx::AS2::Object *v8; // rdi
  long double v9; // xmm0_8
  Scaleform::GFx::AS2::Environment *v10; // rbx
  signed __int64 v11; // rdi
  long double v12; // xmm0_8
  double v13; // xmm6_8
  long double v14; // xmm0_8
  double v15; // xmm6_8
  long double v16; // xmm0_8
  Scaleform::GFx::AS2::Value v; // [rsp+30h] [rbp-B8h]
  Scaleform::GFx::AS2::Value ptr; // [rsp+50h] [rbp-98h]
  Scaleform::GFx::AS2::Value params; // [rsp+70h] [rbp-78h]
  Scaleform::GFx::AS2::Value v20; // [rsp+98h] [rbp-50h]
  __int64 v21; // [rsp+F8h] [rbp+10h]

  v21 = -2i64;
  v1 = fn;
  if ( fn->NArgs > 0 )
  {
    v2 = fn->ThisPtr;
    if ( v2 && (*(unsigned int (**)(void))&v2->vfptr->gap8[8])() == 17 )
    {
      v3 = v1->ThisPtr;
      v4 = 0i64;
      if ( v3 )
        v5 = (Scaleform::GFx::AS2::RectangleObject *)&v3[-2];
      else
        v5 = 0i64;
      v6 = v1->FirstArgBottomIndex;
      v7 = v1->Env;
      if ( v6 <= 32 * ((unsigned int)v7->Stack.Pages.Data.Size - 1)
               + (unsigned int)((_QWORD)((char *)v7->Stack.pCurrent - (char *)v7->Stack.pPageStart) >> 5) )
        v4 = &v7->Stack.Pages.Data.Data[v6 >> 5]->Values[v6 & 0x1F];
      v8 = Scaleform::GFx::AS2::Value::ToObject(v4, v7);
      `eh vector constructor iterator'(
        &params.NV.8,
        0x20ui64,
        4,
        (void (__fastcall *)(void *))Scaleform::GFx::AS2::Value::Value);
      if ( !v8 )
      {
        Scaleform::GFx::AS2::RectangleObject::GetProperties(
          v5,
          &v1->Env->StringContext,
          (Scaleform::GFx::AS2::Value *)((char *)&params + 8));
        v.T.Type = 3;
        v.V.pStringNode = COERCE_SCALEFORM__GFX__ASSTRINGNODE__(Scaleform::GFx::NumberUtil::NaN());
        Scaleform::GFx::AS2::Value::operator=((Scaleform::GFx::AS2::Value *)((char *)&params + 8), &v);
        if ( v.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&v);
        v9 = Scaleform::GFx::NumberUtil::NaN();
        v.T.Type = 3;
        v.NV.NumberValue = v9;
        Scaleform::GFx::AS2::Value::operator=(&v20, &v);
        if ( v.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&v);
        Scaleform::GFx::AS2::RectangleObject::SetProperties(
          v5,
          &v1->Env->StringContext,
          (Scaleform::GFx::AS2::Value *)((char *)&params + 8));
LABEL_25:
        `eh vector destructor iterator'(
          &params.NV.8,
          0x20ui64,
          4,
          (void (__fastcall *)(void *))Scaleform::GFx::AS2::Value::~Value);
        return;
      }
      `eh vector constructor iterator'(
        &ptr,
        0x20ui64,
        2,
        (void (__fastcall *)(void *))Scaleform::GFx::AS2::Value::Value);
      v10 = v1->Env;
      v11 = (signed __int64)&v8->vfptr;
      (*(void (__fastcall **)(signed __int64, Scaleform::GFx::AS2::ASStringContext *, Scaleform::Ptr<Scaleform::GFx::ASSupport> *, Scaleform::GFx::AS2::Value *, void (__fastcall *)(Scaleform::GFx::AS2::Value *)))(*(_QWORD *)v11 + 88i64))(
        v11,
        &v10->StringContext,
        &v10->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[33].pASSupport,
        &ptr,
        Scaleform::GFx::AS2::Value::~Value);
      (*(void (__fastcall **)(signed __int64, Scaleform::GFx::AS2::ASStringContext *, char *, Scaleform::GFx::AS2::Value *))(*(_QWORD *)v11 + 88i64))(
        v11,
        &v10->StringContext,
        &v10->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[33].AVMVersion,
        &params);
      if ( (*(unsigned int (__fastcall **)(signed __int64))(*(_QWORD *)v11 + 16i64))(v11) != 16
        && (!ptr.T.Type || ptr.T.Type == 10 || !params.T.Type || params.T.Type == 10) )
      {
        Scaleform::GFx::AS2::RectangleObject::GetProperties(
          v5,
          &v1->Env->StringContext,
          (Scaleform::GFx::AS2::Value *)((char *)&params + 8));
        v.T.Type = 3;
        v.V.pStringNode = COERCE_SCALEFORM__GFX__ASSTRINGNODE__(Scaleform::GFx::NumberUtil::NaN());
        Scaleform::GFx::AS2::Value::operator=((Scaleform::GFx::AS2::Value *)((char *)&params + 8), &v);
        if ( v.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&v);
        v12 = Scaleform::GFx::NumberUtil::NaN();
        v.T.Type = 3;
        v.NV.NumberValue = v12;
        Scaleform::GFx::AS2::Value::operator=(&v20, &v);
        if ( v.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&v);
        Scaleform::GFx::AS2::RectangleObject::SetProperties(
          v5,
          &v1->Env->StringContext,
          (Scaleform::GFx::AS2::Value *)((char *)&params + 8));
        `eh vector destructor iterator'(
          &ptr,
          0x20ui64,
          2,
          (void (__fastcall *)(void *))Scaleform::GFx::AS2::Value::~Value);
        goto LABEL_25;
      }
      Scaleform::GFx::AS2::RectangleObject::GetProperties(
        v5,
        &v1->Env->StringContext,
        (Scaleform::GFx::AS2::Value *)((char *)&params + 8));
      v13 = Scaleform::GFx::AS2::Value::ToNumber(&ptr, v1->Env);
      v14 = Scaleform::GFx::AS2::Value::ToNumber((Scaleform::GFx::AS2::Value *)((char *)&params + 8), v1->Env);
      v.T.Type = 3;
      v.NV.NumberValue = v13 + v14;
      Scaleform::GFx::AS2::Value::operator=((Scaleform::GFx::AS2::Value *)((char *)&params + 8), &v);
      if ( v.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v);
      v15 = Scaleform::GFx::AS2::Value::ToNumber(&params, v1->Env);
      v16 = Scaleform::GFx::AS2::Value::ToNumber(&v20, v1->Env);
      v.T.Type = 3;
      v.NV.NumberValue = v15 + v16;
      Scaleform::GFx::AS2::Value::operator=(&v20, &v);
      if ( v.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v);
      Scaleform::GFx::AS2::RectangleObject::SetProperties(
        v5,
        &v1->Env->StringContext,
        (Scaleform::GFx::AS2::Value *)((char *)&params + 8));
      `eh vector destructor iterator'(
        &ptr,
        0x20ui64,
        2,
        (void (__fastcall *)(void *))Scaleform::GFx::AS2::Value::~Value);
      `eh vector destructor iterator'(
        &params.NV.8,
        0x20ui64,
        4,
        (void (__fastcall *)(void *))Scaleform::GFx::AS2::Value::~Value);
    }
    else
    {
      Scaleform::GFx::AS2::Environment::LogScriptError(
        v1->Env,
        "Error: Null or invalid 'this' is used for a method of %s class.\n",
        "Rectangle");
    }
  }
}

// File Line: 817
// RVA: 0x6B6F80
void __fastcall Scaleform::GFx::AS2::RectangleProto::SetEmpty(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rbx
  Scaleform::GFx::AS2::ObjectInterface *v2; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rax
  Scaleform::GFx::AS2::RectangleObject *v4; // rcx
  Scaleform::GFx::AS2::Environment *v5; // rdx
  Scaleform::Render::Rect<double> r; // [rsp+20h] [rbp-28h]

  v1 = fn;
  v2 = fn->ThisPtr;
  if ( v2 && (*(unsigned int (**)(void))&v2->vfptr->gap8[8])() == 17 )
  {
    v3 = v1->ThisPtr;
    if ( v3 )
      v4 = (Scaleform::GFx::AS2::RectangleObject *)&v3[-2];
    else
      v4 = 0i64;
    v5 = v1->Env;
    r.x1 = 0.0;
    r.y1 = 0.0;
    r.x2 = 0.0;
    r.y2 = 0.0;
    Scaleform::GFx::AS2::RectangleObject::SetProperties(v4, v5, &r);
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      v1->Env,
      "Error: Null or invalid 'this' is used for a method of %s class.\n",
      "Rectangle");
  }
}

// File Line: 828
// RVA: 0x6B7000
void __fastcall Scaleform::GFx::AS2::RectangleProto::ToString(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rbx
  Scaleform::GFx::AS2::ObjectInterface *v2; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rax
  Scaleform::GFx::AS2::RectangleObject *v4; // rdi
  Scaleform::GFx::ASString *v5; // rsi
  Scaleform::GFx::AS2::Value *v6; // rbx
  Scaleform::GFx::ASStringNode *v7; // rax
  Scaleform::GFx::ASStringNode *v8; // rcx
  bool v9; // zf
  Scaleform::GFx::ASString result; // [rsp+18h] [rbp-69h]
  void (__fastcall *pDtor)(void *); // [rsp+20h] [rbp-61h]
  Scaleform::GFx::ASString v12; // [rsp+28h] [rbp-59h]
  Scaleform::GFx::ASString v13; // [rsp+30h] [rbp-51h]
  __int64 v14; // [rsp+38h] [rbp-49h]
  char ptr; // [rsp+48h] [rbp-39h]
  Scaleform::GFx::AS2::Value v16; // [rsp+68h] [rbp-19h]
  Scaleform::GFx::AS2::Value v17; // [rsp+88h] [rbp+7h]
  Scaleform::GFx::AS2::Value v18; // [rsp+A8h] [rbp+27h]
  Scaleform::String str; // [rsp+E8h] [rbp+67h]
  Scaleform::GFx::ASString vars0; // [rsp+F0h] [rbp+6Fh]

  v14 = -2i64;
  v1 = fn;
  v2 = fn->ThisPtr;
  if ( v2 && (*(unsigned int (**)(void))&v2->vfptr->gap8[8])() == 17 )
  {
    v3 = v1->ThisPtr;
    if ( v3 )
    {
      v4 = (Scaleform::GFx::AS2::RectangleObject *)&v3[-2];
      if ( v3 != (Scaleform::GFx::AS2::ObjectInterface *)32 )
      {
        pDtor = (void (__fastcall *)(void *))Scaleform::GFx::AS2::Value::~Value;
        `eh vector constructor iterator'(
          &ptr,
          0x20ui64,
          4,
          (void (__fastcall *)(void *))Scaleform::GFx::AS2::Value::Value);
        Scaleform::GFx::AS2::RectangleObject::GetProperties(
          v4,
          &v1->Env->StringContext,
          (Scaleform::GFx::AS2::Value *)&ptr);
        Scaleform::GFx::AS2::Value::ToString((Scaleform::GFx::AS2::Value *)&ptr, &result, v1->Env, 6);
        Scaleform::GFx::AS2::Value::ToString(&v16, (Scaleform::GFx::ASString *)&pDtor, v1->Env, 6);
        Scaleform::GFx::AS2::Value::ToString(&v17, &v12, v1->Env, 6);
        Scaleform::GFx::AS2::Value::ToString(&v18, &v13, v1->Env, 6);
        Scaleform::String::String(&str);
        Scaleform::String::AppendString(&str, "(x=", -1i64);
        Scaleform::String::AppendString(&str, result.pNode->pData, -1i64);
        Scaleform::String::AppendString(&str, ", y=", -1i64);
        Scaleform::String::AppendString(&str, *(const char **)pDtor, -1i64);
        Scaleform::String::AppendString(&str, ", width=", -1i64);
        Scaleform::String::AppendString(&str, v12.pNode->pData, -1i64);
        Scaleform::String::AppendString(&str, ", height=", -1i64);
        Scaleform::String::AppendString(&str, v13.pNode->pData, -1i64);
        Scaleform::String::AppendString(&str, ")", -1i64);
        v5 = Scaleform::GFx::AS2::Environment::CreateString(v1->Env, &vars0, &str);
        v6 = v1->Result;
        if ( v6->T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(v6);
        v6->T.Type = 5;
        v7 = v5->pNode;
        v6->NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)v5->pNode;
        ++v7->RefCount;
        v8 = vars0.pNode;
        v9 = vars0.pNode->RefCount == 1;
        --v8->RefCount;
        if ( v9 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v8);
        if ( _InterlockedExchangeAdd(
               (volatile signed __int32 *)((str.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8),
               0xFFFFFFFF) == 1 )
          ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
        `eh vector destructor iterator'(
          &result,
          8ui64,
          4,
          (void (__fastcall *)(void *))Scaleform::GFx::ASString::~ASString);
        `eh vector destructor iterator'(
          &ptr,
          0x20ui64,
          4,
          (void (__fastcall *)(void *))Scaleform::GFx::AS2::Value::~Value);
      }
    }
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      v1->Env,
      "Error: Null or invalid 'this' is used for a method of %s class.\n",
      "Rectangle");
  }
}rror: Null or invalid 'this' is used for a method of %s class.\n",
      "Rectangle")

// File Line: 863
// RVA: 0x6B7280
void __fastcall Scaleform::GFx::AS2::RectangleProto::Union(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rbx
  Scaleform::GFx::AS2::ObjectInterface *v2; // rcx
  __int64 v3; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v4; // rax
  Scaleform::GFx::AS2::Value *v5; // rsi
  Scaleform::GFx::AS2::RectangleObject *v6; // r14
  Scaleform::GFx::AS2::RectangleObject *v7; // rax
  Scaleform::GFx::AS2::RectangleObject *v8; // rax
  Scaleform::GFx::AS2::RectangleObject *v9; // rdi
  long double v10; // xmm8_8
  long double v11; // xmm7_8
  long double v12; // xmm6_8
  unsigned int v13; // er9
  Scaleform::GFx::AS2::Environment *v14; // rdx
  Scaleform::GFx::AS2::Object *v15; // rsi
  double v16; // xmm8_8
  double v17; // xmm7_8
  double v18; // xmm6_8
  double v19; // xmm0_8
  double v20; // xmm0_8
  unsigned int v21; // eax
  Scaleform::Render::Rect<double> v22; // [rsp+30h] [rbp-A8h]
  Scaleform::Render::Rect<double> r; // [rsp+50h] [rbp-88h]
  Scaleform::Render::Rect<double> ptr; // [rsp+70h] [rbp-68h]
  Scaleform::GFx::AS2::Value v25; // [rsp+98h] [rbp-40h]
  Scaleform::GFx::AS2::Value v26; // [rsp+B8h] [rbp-20h]
  Scaleform::GFx::AS2::Value v27; // [rsp+D8h] [rbp+0h]
  double v28; // [rsp+158h] [rbp+80h]
  Scaleform::GFx::AS2::RectangleObject *v29; // [rsp+160h] [rbp+88h]

  r.y2 = -3.595386269724631e308/*NaN*/;
  v1 = fn;
  v2 = fn->ThisPtr;
  if ( v2 && (*(unsigned int (**)(void))&v2->vfptr->gap8[8])() == 17 )
  {
    v4 = v1->ThisPtr;
    v5 = 0i64;
    v6 = (Scaleform::GFx::AS2::RectangleObject *)&v4[-2];
    if ( !v4 )
      v6 = 0i64;
    v28 = *(double *)&v1->Env->StringContext.pContext->pHeap;
    v7 = (Scaleform::GFx::AS2::RectangleObject *)(*(__int64 (__fastcall **)(__int64, signed __int64))(**(_QWORD **)&v28 + 80i64))(
                                                   v3,
                                                   96i64);
    v29 = v7;
    if ( v7 )
    {
      Scaleform::GFx::AS2::RectangleObject::RectangleObject(v7, v1->Env);
      v9 = v8;
    }
    else
    {
      v9 = 0i64;
    }
    v29 = v9;
    Scaleform::GFx::AS2::Value::SetAsObject(v1->Result, (Scaleform::GFx::AS2::Object *)&v9->vfptr);
    if ( v1->NArgs <= 0 )
    {
      Scaleform::GFx::AS2::RectangleObject::SetProperties(v9, &v1->Env->StringContext, Rectangle_NaNParams);
    }
    else
    {
      v10 = Scaleform::GFx::NumberUtil::NaN();
      v11 = Scaleform::GFx::NumberUtil::NaN();
      v12 = Scaleform::GFx::NumberUtil::NaN();
      v22.x1 = Scaleform::GFx::NumberUtil::NaN();
      v22.y1 = v12;
      v22.x2 = v11;
      v22.y2 = v10;
      v13 = v1->FirstArgBottomIndex;
      v14 = v1->Env;
      if ( v13 <= 32 * ((unsigned int)v14->Stack.Pages.Data.Size - 1)
                + (unsigned int)((_QWORD)((char *)v14->Stack.pCurrent - (char *)v14->Stack.pPageStart) >> 5) )
        v5 = &v14->Stack.Pages.Data.Data[v13 >> 5]->Values[v13 & 0x1F];
      v15 = Scaleform::GFx::AS2::Value::ToObject(v5, v14);
      if ( v15 )
      {
        *(_OWORD *)&r.x1 = 0ui64;
        r.x2 = 0.0;
        r.y2 = 0.0;
        `eh vector constructor iterator'(
          &ptr.y1,
          0x20ui64,
          4,
          (void (__fastcall *)(void *))Scaleform::GFx::AS2::Value::Value);
        Scaleform::GFx::AS2::RectangleObject::GetProperties(v6, v1->Env, &r);
        Scaleform::GFx::AS2::GFxObject_GetRectangleProperties(v1->Env, v15, (Scaleform::GFx::AS2::Value *)&ptr.y1);
        v16 = Scaleform::GFx::AS2::Value::ToNumber(&v27, v1->Env);
        v17 = Scaleform::GFx::AS2::Value::ToNumber(&v26, v1->Env);
        v18 = Scaleform::GFx::AS2::Value::ToNumber(&v25, v1->Env);
        ptr.x1 = Scaleform::GFx::AS2::Value::ToNumber((Scaleform::GFx::AS2::Value *)&ptr.y1, v1->Env);
        ptr.y1 = v18;
        r.y1 = v17 + ptr.x1;
        r.x2 = v16 + v18;
        Scaleform::GFx::AS2::ValidateRect(&r);
        Scaleform::GFx::AS2::ValidateRect(&ptr);
        if ( r.x1 <= ptr.x1 )
          v22.x1 = r.x1;
        else
          v22.x1 = ptr.x1;
        if ( r.x2 <= r.y1 )
          v22.x2 = r.y1;
        else
          v22.x2 = r.x2;
        if ( r.y1 <= ptr.y1 )
          v22.y1 = r.y1;
        else
          v22.y1 = ptr.y1;
        if ( r.y2 <= r.x2 )
          v22.y2 = r.x2;
        else
          v22.y2 = r.y2;
        v19 = Scaleform::GFx::AS2::Value::ToNumber((Scaleform::GFx::AS2::Value *)&ptr.y1, v1->Env);
        v28 = v19;
        if ( (*(_QWORD *)&v19 & 0x7FF0000000000000i64) == 9218868437227405312i64 && *(_QWORD *)&v19 & 0xFFFFFFFFFFFFFi64 )
          v22.x1 = Scaleform::GFx::NumberUtil::NaN();
        v20 = Scaleform::GFx::AS2::Value::ToNumber(&v25, v1->Env);
        v28 = v20;
        if ( (*(_QWORD *)&v20 & 0x7FF0000000000000i64) == 9218868437227405312i64 && *(_QWORD *)&v20 & 0xFFFFFFFFFFFFFi64 )
          v22.y1 = Scaleform::GFx::NumberUtil::NaN();
        `eh vector destructor iterator'(
          &ptr.y1,
          0x20ui64,
          4,
          (void (__fastcall *)(void *))Scaleform::GFx::AS2::Value::~Value);
      }
      Scaleform::GFx::AS2::RectangleObject::SetProperties(v9, v1->Env, &v22);
    }
    if ( v9 )
    {
      v21 = v9->RefCount;
      if ( v21 & 0x3FFFFFF )
      {
        v9->RefCount = v21 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v9->vfptr);
      }
    }
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      v1->Env,
      "Error: Null or invalid 'this' is used for a method of %s class.\n",
      "Rectangle");
  }
}

// File Line: 911
// RVA: 0x6F9E60
void __fastcall Scaleform::GFx::AS2::RectangleCtorFunction::GlobalCtor(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rdi
  Scaleform::GFx::AS2::Value *v2; // rsi
  Scaleform::GFx::AS2::ObjectInterface *v3; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v4; // rbx
  Scaleform::GFx::AS2::RectangleObject *v5; // rbx
  Scaleform::GFx::AS2::RectangleObject *v6; // rax
  Scaleform::GFx::AS2::RectangleObject *v7; // rax
  unsigned int v8; // er8
  Scaleform::GFx::AS2::Environment *v9; // r9
  Scaleform::GFx::AS2::Value *v10; // rdx
  unsigned int v11; // edx
  Scaleform::GFx::AS2::Environment *v12; // r9
  Scaleform::GFx::AS2::Value *v13; // r8
  unsigned int v14; // edx
  Scaleform::GFx::AS2::Environment *v15; // r9
  Scaleform::GFx::AS2::Value *v16; // r8
  unsigned int v17; // edx
  Scaleform::GFx::AS2::Environment *v18; // r8
  unsigned int v19; // eax
  char ptr; // [rsp+40h] [rbp-98h]
  Scaleform::GFx::AS2::Value v21; // [rsp+60h] [rbp-78h]
  Scaleform::GFx::AS2::Value v22; // [rsp+80h] [rbp-58h]
  Scaleform::GFx::AS2::Value v23; // [rsp+A0h] [rbp-38h]

  v1 = fn;
  v2 = 0i64;
  v3 = fn->ThisPtr;
  if ( !v3
    || (*(unsigned int (**)(void))&v3->vfptr->gap8[8])() != 17
    || ((unsigned __int8 (*)(void))v1->ThisPtr->vfptr->IsBuiltinPrototype)() )
  {
    v6 = (Scaleform::GFx::AS2::RectangleObject *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::ObjectInterface *, signed __int64))v1->Env->StringContext.pContext->pHeap->vfptr->Alloc)(
                                                   v3,
                                                   96i64);
    if ( v6 )
    {
      Scaleform::GFx::AS2::RectangleObject::RectangleObject(v6, v1->Env);
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
      v5 = (Scaleform::GFx::AS2::RectangleObject *)&v4[-2];
      if ( v5 )
        v5->RefCount = (v5->RefCount + 1) & 0x8FFFFFFF;
    }
    else
    {
      v5 = 0i64;
    }
  }
  Scaleform::GFx::AS2::Value::SetAsObject(v1->Result, (Scaleform::GFx::AS2::Object *)&v5->vfptr);
  if ( v1->NArgs > 0 )
  {
    `eh vector constructor iterator'(&ptr, 0x20ui64, 4, (void (__fastcall *)(void *))Scaleform::GFx::AS2::Value::Value);
    v8 = v1->FirstArgBottomIndex;
    v9 = v1->Env;
    v10 = 0i64;
    if ( v8 <= 32 * ((unsigned int)v9->Stack.Pages.Data.Size - 1)
             + (unsigned int)((_QWORD)((char *)v9->Stack.pCurrent - (char *)v9->Stack.pPageStart) >> 5) )
      v10 = &v9->Stack.Pages.Data.Data[v8 >> 5]->Values[v8 & 0x1F];
    Scaleform::GFx::AS2::Value::operator=((Scaleform::GFx::AS2::Value *)&ptr, v10, (__int64)v1);
    if ( v1->NArgs > 1 )
    {
      v11 = v1->FirstArgBottomIndex - 1;
      v12 = v1->Env;
      v13 = 0i64;
      if ( v11 <= 32 * ((unsigned int)v12->Stack.Pages.Data.Size - 1)
                + (unsigned int)((_QWORD)((char *)v12->Stack.pCurrent - (char *)v12->Stack.pPageStart) >> 5) )
        v13 = &v12->Stack.Pages.Data.Data[v11 >> 5]->Values[v11 & 0x1F];
      Scaleform::GFx::AS2::Value::operator=(&v21, v13, (__int64)v1);
      if ( v1->NArgs > 2 )
      {
        v14 = v1->FirstArgBottomIndex - 2;
        v15 = v1->Env;
        v16 = 0i64;
        if ( v14 <= 32 * ((unsigned int)v15->Stack.Pages.Data.Size - 1)
                  + (unsigned int)((_QWORD)((char *)v15->Stack.pCurrent - (char *)v15->Stack.pPageStart) >> 5) )
          v16 = &v15->Stack.Pages.Data.Data[v14 >> 5]->Values[v14 & 0x1F];
        Scaleform::GFx::AS2::Value::operator=(&v22, v16, (__int64)v1);
        if ( v1->NArgs > 3 )
        {
          v17 = v1->FirstArgBottomIndex - 3;
          v18 = v1->Env;
          if ( v17 <= 32 * ((unsigned int)v18->Stack.Pages.Data.Size - 1)
                    + (unsigned int)((_QWORD)((char *)v18->Stack.pCurrent - (char *)v18->Stack.pPageStart) >> 5) )
            v2 = &v18->Stack.Pages.Data.Data[v17 >> 5]->Values[v17 & 0x1F];
          Scaleform::GFx::AS2::Value::operator=(&v23, v2, (__int64)v1);
        }
      }
    }
    Scaleform::GFx::AS2::RectangleObject::SetProperties(v5, &v1->Env->StringContext, (Scaleform::GFx::AS2::Value *)&ptr);
    `eh vector destructor iterator'(&ptr, 0x20ui64, 4, (void (__fastcall *)(void *))Scaleform::GFx::AS2::Value::~Value);
  }
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

// File Line: 944
// RVA: 0x6E07C0
void __fastcall Scaleform::GFx::AS2::RectangleCtorFunction::CreateNewObject(Scaleform::GFx::AS2::RectangleCtorFunction *this, Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::Environment *v2; // rbx
  Scaleform::GFx::AS2::RectangleObject *v3; // rax

  v2 = penv;
  v3 = (Scaleform::GFx::AS2::RectangleObject *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::RectangleCtorFunction *, signed __int64))penv->StringContext.pContext->pHeap->vfptr->Alloc)(
                                                 this,
                                                 96i64);
  if ( v3 )
    Scaleform::GFx::AS2::RectangleObject::RectangleObject(v3, v2);
}

// File Line: 949
// RVA: 0x70E830
Scaleform::GFx::AS2::FunctionRef *__fastcall Scaleform::GFx::AS2::RectangleCtorFunction::Register(Scaleform::GFx::AS2::FunctionRef *result, Scaleform::GFx::AS2::GlobalContext *pgc)
{
  Scaleform::GFx::AS2::GlobalContext *v2; // rsi
  Scaleform::GFx::AS2::FunctionRef *v3; // rdi
  Scaleform::GFx::AS2::Object *v4; // rax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v5; // rcx
  Scaleform::GFx::AS2::FunctionObject *v6; // rbx
  Scaleform::GFx::AS2::Object *v7; // r15
  unsigned int v8; // eax
  Scaleform::GFx::AS2::RectangleProto *v9; // rbx
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
    v6[1].vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)Scaleform::GFx::AS2::RectangleCtorFunction::GlobalCtor;
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
    v6->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::RectangleCtorFunction::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
    v6->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::RectangleCtorFunction::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  }
  else
  {
    v6 = 0i64;
  }
  v3->Flags = 0;
  v3->Function = v6;
  v3->pLocalFrame = 0i64;
  objproto.pObject = (Scaleform::GFx::AS2::Object *)v2->pHeap;
  v9 = (Scaleform::GFx::AS2::RectangleProto *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::RefCountBaseGC<323> *, signed __int64, _QWORD))objproto.pObject->vfptr[3].Finalize_GC)(
                                                v5,
                                                160i64,
                                                0i64);
  v20 = (Scaleform::MemoryHeap *)v9;
  if ( v9 )
  {
    v10 = Scaleform::GFx::AS2::GlobalContext::GetPrototype(v2, ASBuiltin_Object);
    Scaleform::GFx::AS2::RectangleProto::RectangleProto(v9, &psc, v10, v3);
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
    ASBuiltin_Rectangle,
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
    (Scaleform::GFx::ASString *)&v2->pMovieRoot->pASMovieRoot.pObject[10].AVMVersion,
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

