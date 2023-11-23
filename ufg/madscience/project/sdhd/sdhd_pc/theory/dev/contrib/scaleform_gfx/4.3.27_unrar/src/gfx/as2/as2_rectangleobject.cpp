// File Line: 30
// RVA: 0x700BF0
bool __fastcall Scaleform::GFx::AS2::IsRectValid(Scaleform::Render::Rect<double> *r)
{
  bool result; // al
  long double y1; // [rsp+8h] [rbp+8h]
  long double x2; // [rsp+8h] [rbp+8h]
  long double y2; // [rsp+8h] [rbp+8h]

  result = 0;
  if ( (*(_QWORD *)&r->x1 & 0x7FF0000000000000i64) != 0x7FF0000000000000i64
    || (*(_QWORD *)&r->x1 & 0xFFFFFFFFFFFFFi64) == 0 )
  {
    y1 = r->y1;
    if ( (*(_QWORD *)&y1 & 0x7FF0000000000000i64) != 0x7FF0000000000000i64 || (*(_QWORD *)&y1 & 0xFFFFFFFFFFFFFi64) == 0 )
    {
      x2 = r->x2;
      if ( (*(_QWORD *)&x2 & 0x7FF0000000000000i64) != 0x7FF0000000000000i64
        || (*(_QWORD *)&x2 & 0xFFFFFFFFFFFFFi64) == 0 )
      {
        y2 = r->y2;
        if ( (*(_QWORD *)&y2 & 0x7FF0000000000000i64) != 0x7FF0000000000000i64
          || (*(_QWORD *)&y2 & 0xFFFFFFFFFFFFFi64) == 0 )
        {
          return 1;
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
  long double x2; // [rsp+8h] [rbp+8h]
  long double y1; // [rsp+8h] [rbp+8h]
  long double y2; // [rsp+8h] [rbp+8h]

  if ( (*(_QWORD *)&r->x1 & 0x7FF0000000000000i64) == 0x7FF0000000000000i64
    && (*(_QWORD *)&r->x1 & 0xFFFFFFFFFFFFFi64) != 0 )
  {
    r->x1 = 0.0;
  }
  x2 = r->x2;
  if ( (*(_QWORD *)&x2 & 0x7FF0000000000000i64) == 0x7FF0000000000000i64 && (*(_QWORD *)&x2 & 0xFFFFFFFFFFFFFi64) != 0 )
    r->x2 = 0.0;
  y1 = r->y1;
  if ( (*(_QWORD *)&y1 & 0x7FF0000000000000i64) == 0x7FF0000000000000i64 && (*(_QWORD *)&y1 & 0xFFFFFFFFFFFFFi64) != 0 )
    r->y1 = 0.0;
  y2 = r->y2;
  if ( (*(_QWORD *)&y2 & 0x7FF0000000000000i64) == 0x7FF0000000000000i64 && (*(_QWORD *)&y2 & 0xFFFFFFFFFFFFFi64) != 0 )
    r->y2 = 0.0;
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
  return atexit((int (__fastcall *)())Scaleform::GFx::AS2::_dynamic_atexit_destructor_for__Rectangle_DefaultParams__);
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
  return atexit((int (__fastcall *)())Scaleform::GFx::AS2::_dynamic_atexit_destructor_for__Rectangle_NaNParams__);
}

// File Line: 64
// RVA: 0x6ED9F0
void __fastcall Scaleform::GFx::AS2::GFxObject_GetRectangleProperties(
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::AS2::Object *pobj,
        Scaleform::GFx::AS2::Value *params)
{
  Scaleform::GFx::AS2::ASStringContext *p_StringContext; // rbx
  Scaleform::GFx::AS2::ObjectInterface *v5; // rdi
  Scaleform::GFx::ASString *v6; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v8; // zf
  Scaleform::GFx::ASString *v9; // rax
  Scaleform::GFx::ASStringNode *v10; // rcx
  Scaleform::GFx::ASString *v11; // rax
  Scaleform::GFx::ASStringNode *v12; // rcx
  Scaleform::GFx::ASString *v13; // rax
  Scaleform::GFx::ASStringNode *v14; // rcx
  Scaleform::GFx::ASString result; // [rsp+40h] [rbp+8h] BYREF

  p_StringContext = &penv->StringContext;
  v5 = &pobj->Scaleform::GFx::AS2::ObjectInterface;
  v6 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(&penv->StringContext, &result, "x");
  ((void (__fastcall *)(Scaleform::GFx::AS2::ObjectInterface *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, __int64))v5->vfptr->GetMemberRaw)(
    v5,
    p_StringContext,
    v6,
    params,
    -2i64);
  pNode = result.pNode;
  v8 = result.pNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  v9 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(p_StringContext, &result, "y");
  v5->vfptr->GetMemberRaw(v5, p_StringContext, v9, params + 1);
  v10 = result.pNode;
  v8 = result.pNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v10);
  v11 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(p_StringContext, &result, "width");
  v5->vfptr->GetMemberRaw(v5, p_StringContext, v11, params + 2);
  v12 = result.pNode;
  v8 = result.pNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v12);
  v13 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(p_StringContext, &result, "height");
  v5->vfptr->GetMemberRaw(v5, p_StringContext, v13, params + 3);
  v14 = result.pNode;
  v8 = result.pNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v14);
}

// File Line: 92
// RVA: 0x70BFF0
Scaleform::MemoryHeap *__fastcall Scaleform::GFx::AS2::Rectangle_ComputeTopLeft(
        Scaleform::MemoryHeap *result,
        Scaleform::GFx::AS2::ASStringContext *penv,
        Scaleform::Render::Rect<double> *r)
{
  Scaleform::GFx::AS2::PointObject *v6; // rbx
  Scaleform::GFx::AS2::PointObject *v7; // rax
  Scaleform::GFx::AS2::PointObject *v8; // rax
  long double y1; // xmm1_8
  unsigned int RefCount; // eax
  Scaleform::Render::Point<double> pt; // [rsp+30h] [rbp-28h] BYREF

  v6 = 0i64;
  v7 = (Scaleform::GFx::AS2::PointObject *)(*(__int64 (__fastcall **)(Scaleform::MemoryHeap *, __int64, _QWORD))(**(_QWORD **)(*(_QWORD *)&penv[14].SWFVersion + 48i64) + 80i64))(
                                             result,
                                             96i64,
                                             0i64);
  if ( v7 )
  {
    Scaleform::GFx::AS2::PointObject::PointObject(v7, penv);
    v6 = v8;
  }
  y1 = r->y1;
  pt.x = r->x1;
  pt.y = y1;
  Scaleform::GFx::AS2::PointObject::SetProperties(v6, (Scaleform::GFx::AS2::Environment *)penv, &pt);
  Scaleform::GFx::AS2::Value::Value((Scaleform::GFx::AS2::Value *)result, (Scaleform::GFx::ASStringNode *)v6);
  if ( v6 )
  {
    RefCount = v6->RefCount;
    if ( (RefCount & 0x3FFFFFF) != 0 )
    {
      v6->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v6);
    }
  }
  return result;
}

// File Line: 103
// RVA: 0x70BE40
Scaleform::MemoryHeap *__fastcall Scaleform::GFx::AS2::Rectangle_ComputeBottomRight(
        Scaleform::MemoryHeap *result,
        Scaleform::GFx::AS2::ASStringContext *penv,
        Scaleform::Render::Rect<double> *r)
{
  Scaleform::GFx::AS2::PointObject *v6; // rbx
  Scaleform::GFx::AS2::PointObject *v7; // rax
  Scaleform::GFx::AS2::PointObject *v8; // rax
  long double y2; // xmm1_8
  unsigned int RefCount; // eax
  Scaleform::Render::Point<double> pt; // [rsp+30h] [rbp-28h] BYREF

  v6 = 0i64;
  v7 = (Scaleform::GFx::AS2::PointObject *)(*(__int64 (__fastcall **)(Scaleform::MemoryHeap *, __int64, _QWORD))(**(_QWORD **)(*(_QWORD *)&penv[14].SWFVersion + 48i64) + 80i64))(
                                             result,
                                             96i64,
                                             0i64);
  if ( v7 )
  {
    Scaleform::GFx::AS2::PointObject::PointObject(v7, penv);
    v6 = v8;
  }
  y2 = r->y2;
  pt.x = r->x2;
  pt.y = y2;
  Scaleform::GFx::AS2::PointObject::SetProperties(v6, (Scaleform::GFx::AS2::Environment *)penv, &pt);
  Scaleform::GFx::AS2::Value::Value((Scaleform::GFx::AS2::Value *)result, (Scaleform::GFx::ASStringNode *)v6);
  if ( v6 )
  {
    RefCount = v6->RefCount;
    if ( (RefCount & 0x3FFFFFF) != 0 )
    {
      v6->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v6);
    }
  }
  return result;
}

// File Line: 114
// RVA: 0x70BF10
Scaleform::MemoryHeap *__fastcall Scaleform::GFx::AS2::Rectangle_ComputeSize(
        Scaleform::MemoryHeap *result,
        Scaleform::GFx::AS2::ASStringContext *penv,
        Scaleform::Render::Rect<double> *r)
{
  Scaleform::GFx::AS2::PointObject *v6; // rbx
  Scaleform::GFx::AS2::PointObject *v7; // rax
  Scaleform::GFx::AS2::PointObject *v8; // rax
  long double v9; // xmm1_8
  unsigned int RefCount; // eax
  Scaleform::Render::Point<double> pt; // [rsp+30h] [rbp-28h] BYREF

  v6 = 0i64;
  v7 = (Scaleform::GFx::AS2::PointObject *)(*(__int64 (__fastcall **)(Scaleform::MemoryHeap *, __int64, _QWORD))(**(_QWORD **)(*(_QWORD *)&penv[14].SWFVersion + 48i64) + 80i64))(
                                             result,
                                             96i64,
                                             0i64);
  if ( v7 )
  {
    Scaleform::GFx::AS2::PointObject::PointObject(v7, penv);
    v6 = v8;
  }
  v9 = r->y2 - r->y1;
  pt.x = r->x2 - r->x1;
  pt.y = v9;
  Scaleform::GFx::AS2::PointObject::SetProperties(v6, (Scaleform::GFx::AS2::Environment *)penv, &pt);
  Scaleform::GFx::AS2::Value::Value((Scaleform::GFx::AS2::Value *)result, (Scaleform::GFx::ASStringNode *)v6);
  if ( v6 )
  {
    RefCount = v6->RefCount;
    if ( (RefCount & 0x3FFFFFF) != 0 )
    {
      v6->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v6);
    }
  }
  return result;
}

// File Line: 168
// RVA: 0x6CB6A0
void __fastcall Scaleform::GFx::AS2::RectangleObject::RectangleObject(
        Scaleform::GFx::AS2::RectangleObject *this,
        Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::Object *Prototype; // rax

  Scaleform::GFx::AS2::Object::Object(this, penv);
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::RectangleObject::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::RectangleObject::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  Prototype = Scaleform::GFx::AS2::GlobalContext::GetPrototype(penv->StringContext.pContext, ASBuiltin_Rectangle);
  Scaleform::GFx::AS2::Object::Set__proto__(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    &penv->StringContext,
    Prototype);
  Scaleform::GFx::AS2::RectangleObject::SetProperties(this, &penv->StringContext, Rectangle_DefaultParams);
}

// File Line: 177
// RVA: 0x6F2310
char __fastcall Scaleform::GFx::AS2::RectangleObject::GetMember(
        Scaleform::GFx::AS2::RectangleObject *this,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS2::Value *val)
{
  const char *pData; // rdi
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
  Scaleform::GFx::AS2::Value v; // [rsp+28h] [rbp-48h] BYREF
  Scaleform::Render::Rect<double> r; // [rsp+48h] [rbp-28h] BYREF

  pData = name->pNode->pData;
  v9 = 0i64;
  v10 = 0i64;
  while ( 1 )
  {
    v11 = pData[v10++];
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
      Scaleform::GFx::AS2::Value::operator=(val, &v);
LABEL_5:
      if ( v.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v);
      return 1;
    }
  }
  v13 = 0i64;
  while ( 1 )
  {
    v14 = pData[v13++];
    if ( v14 != aRight_0[v13 - 1] )
      break;
    if ( v13 == 6 )
    {
      r.x2 = 0.0;
      Scaleform::GFx::AS2::RectangleObject::GetProperties(
        (Scaleform::GFx::AS2::RectangleObject *)((char *)this - 32),
        penv,
        &r);
      v.T.Type = 3;
      v.V.pStringNode = *(Scaleform::GFx::ASStringNode **)&r.x2;
      Scaleform::GFx::AS2::Value::operator=(val, &v);
      goto LABEL_5;
    }
  }
  v15 = 0i64;
  while ( 1 )
  {
    v16 = pData[v15++];
    if ( v16 != aTop_2[v15 - 1] )
      break;
    if ( v15 == 4 )
    {
      r.y1 = 0.0;
      Scaleform::GFx::AS2::RectangleObject::GetProperties(
        (Scaleform::GFx::AS2::RectangleObject *)((char *)this - 32),
        penv,
        &r);
      v.T.Type = 3;
      v.V.pStringNode = *(Scaleform::GFx::ASStringNode **)&r.y1;
      Scaleform::GFx::AS2::Value::operator=(val, &v);
      goto LABEL_5;
    }
  }
  v17 = 0i64;
  while ( 1 )
  {
    v18 = pData[v17++];
    if ( v18 != aBottom[v17 - 1] )
      break;
    if ( v17 == 7 )
    {
      r.y2 = 0.0;
      Scaleform::GFx::AS2::RectangleObject::GetProperties(
        (Scaleform::GFx::AS2::RectangleObject *)((char *)this - 32),
        penv,
        &r);
      v.T.Type = 3;
      v.V.pStringNode = *(Scaleform::GFx::ASStringNode **)&r.y2;
      Scaleform::GFx::AS2::Value::operator=(val, &v);
      goto LABEL_5;
    }
  }
  v19 = 0i64;
  while ( 1 )
  {
    v20 = pData[v19++];
    if ( v20 != aTopleft[v19 - 1] )
      break;
    if ( v19 == 8 )
    {
      memset(&v, 0, sizeof(v));
      Scaleform::GFx::AS2::RectangleObject::GetProperties(
        (Scaleform::GFx::AS2::RectangleObject *)((char *)this - 32),
        penv,
        (Scaleform::Render::Rect<double> *)&v);
      r = (Scaleform::Render::Rect<double>)v;
      v21 = Scaleform::GFx::AS2::Rectangle_ComputeTopLeft(&v, penv, &r);
      Scaleform::GFx::AS2::Value::operator=(val, v21);
      goto LABEL_5;
    }
  }
  if ( !strcmp(name->pNode->pData, "bottomRight") )
  {
    memset(&v, 0, sizeof(v));
    Scaleform::GFx::AS2::RectangleObject::GetProperties(
      (Scaleform::GFx::AS2::RectangleObject *)((char *)this - 32),
      penv,
      (Scaleform::Render::Rect<double> *)&v);
    r = (Scaleform::Render::Rect<double>)v;
    v22 = Scaleform::GFx::AS2::Rectangle_ComputeBottomRight(&v, penv, &r);
    Scaleform::GFx::AS2::Value::operator=(val, v22);
    goto LABEL_5;
  }
  while ( 1 )
  {
    v23 = pData[v9++];
    if ( v23 != aSize[v9 - 1] )
      return ((__int64 (__fastcall *)(Scaleform::GFx::AS2::RectangleObject *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, __int64))this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr[3].~RefCountBaseGC<323>)(
               this,
               &penv->StringContext,
               name,
               val,
               -2i64);
    if ( v9 == 5 )
    {
      memset(&v, 0, sizeof(v));
      Scaleform::GFx::AS2::RectangleObject::GetProperties(
        (Scaleform::GFx::AS2::RectangleObject *)((char *)this - 32),
        penv,
        (Scaleform::Render::Rect<double> *)&v);
      r = (Scaleform::Render::Rect<double>)v;
      v24 = Scaleform::GFx::AS2::Rectangle_ComputeSize(&v, penv, &r);
      Scaleform::GFx::AS2::Value::operator=(val, v24);
      goto LABEL_5;
    }
  }
}

// File Line: 237
// RVA: 0x718040
char __fastcall Scaleform::GFx::AS2::RectangleObject::SetMember(
        Scaleform::GFx::AS2::RectangleObject *this,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS2::Value *val,
        Scaleform::GFx::AS2::PropFlags *flags)
{
  __int64 v10; // rbx
  const char *pData; // rdi
  __int64 v12; // rcx
  char v13; // al
  __int64 v14; // rcx
  char v15; // al
  __int64 v16; // rcx
  char v17; // al
  double x; // xmm0_8
  __int64 v19; // rcx
  char v20; // al
  __int64 v21; // rcx
  char v22; // al
  Scaleform::GFx::AS2::Object *v23; // rax
  Scaleform::GFx::AS2::Object *v24; // rax
  double y; // xmm1_8
  char v26; // al
  Scaleform::GFx::AS2::Object *v27; // rax
  Scaleform::Render::Point<double> pt; // [rsp+30h] [rbp-30h] BYREF
  Scaleform::Render::Rect<double> r; // [rsp+40h] [rbp-20h] BYREF

  if ( (flags->Flags & 4) != 0 )
    return 0;
  v10 = 0i64;
  pData = name->pNode->pData;
  v12 = 0i64;
  while ( 1 )
  {
    v13 = pData[v12++];
    if ( v13 != aLeft_0[v12 - 1] )
      break;
    if ( v12 == 5 )
    {
      memset(&r.y1, 0, 24);
      Scaleform::GFx::AS2::RectangleObject::GetProperties(
        (Scaleform::GFx::AS2::RectangleObject *)((char *)this - 32),
        penv,
        &r);
      r.x1 = Scaleform::GFx::AS2::Value::ToNumber(val, penv);
      goto LABEL_33;
    }
  }
  v14 = 0i64;
  while ( 1 )
  {
    v15 = pData[v14++];
    if ( v15 != aTop_2[v14 - 1] )
      break;
    if ( v14 == 4 )
    {
      r.x1 = 0.0;
      r.x2 = 0.0;
      r.y2 = 0.0;
      Scaleform::GFx::AS2::RectangleObject::GetProperties(
        (Scaleform::GFx::AS2::RectangleObject *)((char *)this - 32),
        penv,
        &r);
      r.y1 = Scaleform::GFx::AS2::Value::ToNumber(val, penv);
      goto LABEL_33;
    }
  }
  v16 = 0i64;
  while ( 1 )
  {
    v17 = pData[v16++];
    if ( v17 != aRight_0[v16 - 1] )
      break;
    if ( v16 == 6 )
    {
      r.x1 = 0.0;
      r.y1 = 0.0;
      r.y2 = 0.0;
      Scaleform::GFx::AS2::RectangleObject::GetProperties(
        (Scaleform::GFx::AS2::RectangleObject *)((char *)this - 32),
        penv,
        &r);
      x = Scaleform::GFx::AS2::Value::ToNumber(val, penv);
      goto LABEL_32;
    }
  }
  v19 = 0i64;
  while ( 1 )
  {
    v20 = pData[v19++];
    if ( v20 != aBottom[v19 - 1] )
      break;
    if ( v19 == 7 )
    {
      memset(&r, 0, 24);
      Scaleform::GFx::AS2::RectangleObject::GetProperties(
        (Scaleform::GFx::AS2::RectangleObject *)((char *)this - 32),
        penv,
        &r);
      r.y2 = Scaleform::GFx::AS2::Value::ToNumber(val, penv);
      goto LABEL_33;
    }
  }
  v21 = 0i64;
  while ( 1 )
  {
    v22 = pData[v21++];
    if ( v22 != aTopleft[v21 - 1] )
      break;
    if ( v21 == 8 )
    {
      memset(&r, 0, sizeof(r));
      Scaleform::GFx::AS2::RectangleObject::GetProperties(
        (Scaleform::GFx::AS2::RectangleObject *)((char *)this - 32),
        penv,
        &r);
      v23 = Scaleform::GFx::AS2::Value::ToObject(val, penv);
      if ( v23 )
      {
        Scaleform::GFx::AS2::GFxObject_GetPointProperties(penv, v23, &pt);
        r.x1 = pt.x;
        r.y1 = pt.y;
      }
      goto LABEL_33;
    }
  }
  if ( !strcmp(pData, "bottomRight") )
  {
    memset(&r, 0, sizeof(r));
    Scaleform::GFx::AS2::RectangleObject::GetProperties(
      (Scaleform::GFx::AS2::RectangleObject *)((char *)this - 32),
      penv,
      &r);
    v24 = Scaleform::GFx::AS2::Value::ToObject(val, penv);
    if ( !v24 )
      goto LABEL_33;
    Scaleform::GFx::AS2::GFxObject_GetPointProperties(penv, v24, &pt);
    x = pt.x;
    y = pt.y;
  }
  else
  {
    do
    {
      v26 = pData[v10++];
      if ( v26 != aSize[v10 - 1] )
        return Scaleform::GFx::AS2::Object::SetMember(this, penv, name, val, flags);
    }
    while ( v10 != 5 );
    memset(&r, 0, sizeof(r));
    Scaleform::GFx::AS2::RectangleObject::GetProperties(
      (Scaleform::GFx::AS2::RectangleObject *)((char *)this - 32),
      penv,
      &r);
    v27 = Scaleform::GFx::AS2::Value::ToObject(val, penv);
    if ( !v27 )
      goto LABEL_33;
    Scaleform::GFx::AS2::GFxObject_GetPointProperties(penv, v27, &pt);
    x = pt.x + r.x1;
    y = r.y1 + pt.y;
  }
  r.y2 = y;
LABEL_32:
  r.x2 = x;
LABEL_33:
  Scaleform::GFx::AS2::RectangleObject::SetProperties(
    (Scaleform::GFx::AS2::RectangleObject *)((char *)this - 32),
    penv,
    &r);
  return 1;
}

// File Line: 308
// RVA: 0x6F4B20
void __fastcall Scaleform::GFx::AS2::RectangleObject::GetProperties(
        Scaleform::GFx::AS2::RectangleObject *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        Scaleform::GFx::AS2::Value *params)
{
  Scaleform::GFx::AS2::ObjectInterface *v5; // rdi
  Scaleform::GFx::ASString *v6; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v8; // zf
  Scaleform::GFx::ASString *v9; // rax
  Scaleform::GFx::ASStringNode *v10; // rcx
  Scaleform::GFx::ASString *v11; // rax
  Scaleform::GFx::ASStringNode *v12; // rcx
  Scaleform::GFx::ASString *v13; // rax
  Scaleform::GFx::ASStringNode *v14; // rcx
  Scaleform::GFx::ASString result; // [rsp+40h] [rbp+8h] BYREF

  v5 = &this->Scaleform::GFx::AS2::ObjectInterface;
  v6 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &result, "x");
  ((void (__fastcall *)(Scaleform::GFx::AS2::ObjectInterface *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, __int64))v5->vfptr->GetMemberRaw)(
    v5,
    psc,
    v6,
    params,
    -2i64);
  pNode = result.pNode;
  v8 = result.pNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  v9 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &result, "y");
  v5->vfptr->GetMemberRaw(v5, psc, v9, params + 1);
  v10 = result.pNode;
  v8 = result.pNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v10);
  v11 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &result, "width");
  v5->vfptr->GetMemberRaw(v5, psc, v11, params + 2);
  v12 = result.pNode;
  v8 = result.pNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v12);
  v13 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &result, "height");
  v5->vfptr->GetMemberRaw(v5, psc, v13, params + 3);
  v14 = result.pNode;
  v8 = result.pNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v14);
}

// File Line: 316
// RVA: 0x6F4C40
void __fastcall Scaleform::GFx::AS2::RectangleObject::GetProperties(
        Scaleform::GFx::AS2::RectangleObject *this,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::Render::Rect<double> *r)
{
  Scaleform::GFx::AS2::ASStringContext *p_StringContext; // rdi
  Scaleform::GFx::AS2::ObjectInterface *v7; // rbx
  Scaleform::GFx::ASString *v8; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
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
  Scaleform::GFx::AS2::Value ptr; // [rsp+40h] [rbp-C8h] BYREF
  Scaleform::GFx::AS2::Value v22; // [rsp+60h] [rbp-A8h] BYREF
  Scaleform::GFx::AS2::Value v23; // [rsp+80h] [rbp-88h] BYREF
  Scaleform::GFx::AS2::Value v24; // [rsp+A0h] [rbp-68h] BYREF
  Scaleform::GFx::ASString result; // [rsp+110h] [rbp+8h] BYREF

  p_StringContext = &penv->StringContext;
  `eh vector constructor iterator(&ptr, 0x20ui64, 4, (void (__fastcall *)(void *))Scaleform::GFx::AS2::Value::Value);
  v7 = &this->Scaleform::GFx::AS2::ObjectInterface;
  v8 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(p_StringContext, &result, "x");
  ((void (__fastcall *)(Scaleform::GFx::AS2::ObjectInterface *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, void (__fastcall *)(Scaleform::GFx::AS2::Value *)))v7->vfptr->GetMemberRaw)(
    v7,
    p_StringContext,
    v8,
    &ptr,
    Scaleform::GFx::AS2::Value::~Value);
  pNode = result.pNode;
  v10 = result.pNode->RefCount-- == 1;
  if ( v10 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  v11 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(p_StringContext, &result, "y");
  v7->vfptr->GetMemberRaw(v7, p_StringContext, v11, &v22);
  v12 = result.pNode;
  v10 = result.pNode->RefCount-- == 1;
  if ( v10 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v12);
  v13 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(p_StringContext, &result, "width");
  v7->vfptr->GetMemberRaw(v7, p_StringContext, v13, &v23);
  v14 = result.pNode;
  v10 = result.pNode->RefCount-- == 1;
  if ( v10 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v14);
  v15 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(p_StringContext, &result, "height");
  v7->vfptr->GetMemberRaw(v7, p_StringContext, v15, &v24);
  v16 = result.pNode;
  v10 = result.pNode->RefCount-- == 1;
  if ( v10 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v16);
  v17 = Scaleform::GFx::AS2::Value::ToNumber(&v24, penv);
  v18 = Scaleform::GFx::AS2::Value::ToNumber(&v23, penv);
  v19 = Scaleform::GFx::AS2::Value::ToNumber(&v22, penv);
  v20 = Scaleform::GFx::AS2::Value::ToNumber(&ptr, penv);
  r->x1 = v20;
  r->y1 = v19;
  r->x2 = v18 + v20;
  r->y2 = v19 + v17;
  `eh vector destructor iterator(&ptr, 0x20ui64, 4, (void (__fastcall *)(void *))Scaleform::GFx::AS2::Value::~Value);
}

// File Line: 333
// RVA: 0x71AB40
void __fastcall Scaleform::GFx::AS2::RectangleObject::SetProperties(
        Scaleform::GFx::AS2::RectangleObject *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        Scaleform::GFx::AS2::Value *params)
{
  Scaleform::GFx::AS2::ObjectInterface *v5; // rdi
  Scaleform::GFx::ASString *v6; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v8; // zf
  Scaleform::GFx::ASString *v9; // rax
  Scaleform::GFx::ASStringNode *v10; // rcx
  Scaleform::GFx::ASString *v11; // rax
  Scaleform::GFx::ASStringNode *v12; // rcx
  Scaleform::GFx::ASString *v13; // rax
  Scaleform::GFx::ASStringNode *v14; // rcx
  char v15; // [rsp+50h] [rbp+8h] BYREF
  Scaleform::GFx::ASString result; // [rsp+60h] [rbp+18h] BYREF

  v5 = &this->Scaleform::GFx::AS2::ObjectInterface;
  v6 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &result, "x");
  v15 = 0;
  v5->vfptr->SetMemberRaw(v5, psc, v6, params, (Scaleform::GFx::AS2::PropFlags *)&v15);
  pNode = result.pNode;
  v8 = result.pNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  v9 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &result, "y");
  v15 = 0;
  v5->vfptr->SetMemberRaw(v5, psc, v9, params + 1, (Scaleform::GFx::AS2::PropFlags *)&v15);
  v10 = result.pNode;
  v8 = result.pNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v10);
  v11 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &result, "width");
  v15 = 0;
  v5->vfptr->SetMemberRaw(v5, psc, v11, params + 2, (Scaleform::GFx::AS2::PropFlags *)&v15);
  v12 = result.pNode;
  v8 = result.pNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v12);
  v13 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &result, "height");
  v15 = 0;
  v5->vfptr->SetMemberRaw(v5, psc, v13, params + 3, (Scaleform::GFx::AS2::PropFlags *)&v15);
  v14 = result.pNode;
  v8 = result.pNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v14);
}

// File Line: 341
// RVA: 0x71ACA0
void __fastcall Scaleform::GFx::AS2::RectangleObject::SetProperties(
        Scaleform::GFx::AS2::RectangleObject *this,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::Render::Rect<double> *r)
{
  Scaleform::GFx::AS2::ASStringContext *p_StringContext; // rbx
  long double x1; // xmm0_8
  Scaleform::GFx::AS2::ObjectInterface *v6; // rdi
  Scaleform::GFx::ASString *v7; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v9; // zf
  long double y1; // xmm0_8
  Scaleform::GFx::ASString *v11; // rax
  Scaleform::GFx::ASStringNode *v12; // rcx
  long double v13; // xmm0_8
  Scaleform::GFx::ASString *v14; // rax
  Scaleform::GFx::ASStringNode *v15; // rcx
  long double v16; // xmm0_8
  Scaleform::GFx::ASString *v17; // rax
  Scaleform::GFx::ASStringNode *v18; // rcx
  Scaleform::GFx::AS2::Value v19; // [rsp+38h] [rbp-28h] BYREF
  char v20; // [rsp+80h] [rbp+20h] BYREF
  Scaleform::GFx::ASString result; // [rsp+88h] [rbp+28h] BYREF

  p_StringContext = &penv->StringContext;
  x1 = r->x1;
  v19.T.Type = 3;
  v19.NV.NumberValue = x1;
  v6 = &this->Scaleform::GFx::AS2::ObjectInterface;
  v7 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(&penv->StringContext, &result, "x");
  v20 = 0;
  v6->vfptr->SetMemberRaw(v6, p_StringContext, v7, &v19, (Scaleform::GFx::AS2::PropFlags *)&v20);
  pNode = result.pNode;
  v9 = result.pNode->RefCount-- == 1;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  if ( v19.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v19);
  y1 = r->y1;
  v19.T.Type = 3;
  v19.NV.NumberValue = y1;
  v11 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(p_StringContext, &result, "y");
  v20 = 0;
  v6->vfptr->SetMemberRaw(v6, p_StringContext, v11, &v19, (Scaleform::GFx::AS2::PropFlags *)&v20);
  v12 = result.pNode;
  v9 = result.pNode->RefCount-- == 1;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v12);
  if ( v19.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v19);
  v13 = r->x2 - r->x1;
  v19.T.Type = 3;
  v19.NV.NumberValue = v13;
  v14 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(p_StringContext, &result, "width");
  v20 = 0;
  v6->vfptr->SetMemberRaw(v6, p_StringContext, v14, &v19, (Scaleform::GFx::AS2::PropFlags *)&v20);
  v15 = result.pNode;
  v9 = result.pNode->RefCount-- == 1;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v15);
  if ( v19.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v19);
  v16 = r->y2 - r->y1;
  v19.T.Type = 3;
  v19.NV.NumberValue = v16;
  v17 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(p_StringContext, &result, "height");
  v20 = 0;
  v6->vfptr->SetMemberRaw(v6, p_StringContext, v17, &v19, (Scaleform::GFx::AS2::PropFlags *)&v20);
  v18 = result.pNode;
  v9 = result.pNode->RefCount-- == 1;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v18);
  if ( v19.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v19);
}

// File Line: 377
// RVA: 0x6CB730
void __fastcall Scaleform::GFx::AS2::RectangleProto::RectangleProto(
        Scaleform::GFx::AS2::RectangleProto *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        Scaleform::GFx::AS2::Object *pprototype,
        Scaleform::GFx::AS2::FunctionRef *constructor)
{
  Scaleform::GFx::ASString *v6; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
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
  Scaleform::GFx::AS2::PropFlags flags; // [rsp+30h] [rbp-40h] BYREF
  Scaleform::GFx::ASString result; // [rsp+38h] [rbp-38h] BYREF
  __int64 v23; // [rsp+40h] [rbp-30h]
  Scaleform::GFx::AS2::Value val; // [rsp+48h] [rbp-28h] BYREF

  v23 = -2i64;
  Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::RectangleObject,Scaleform::GFx::AS2::Environment>::Prototype<Scaleform::GFx::AS2::RectangleObject,Scaleform::GFx::AS2::Environment>(
    this,
    psc,
    pprototype,
    constructor);
  this->Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::RectangleObject,Scaleform::GFx::AS2::Environment>::Scaleform::GFx::AS2::RectangleObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::RectangleProto::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
  this->Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::RectangleObject,Scaleform::GFx::AS2::Environment>::Scaleform::GFx::AS2::RectangleObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::RectangleProto::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  this->Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::RectangleObject,Scaleform::GFx::AS2::Environment>::Scaleform::GFx::AS2::GASPrototypeBase::vfptr = (Scaleform::GFx::AS2::GASPrototypeBaseVtbl *)&Scaleform::GFx::AS2::RectangleProto::`vftable;
  flags.Flags = 6;
  Scaleform::GFx::AS2::GASPrototypeBase::InitFunctionMembers(
    &this->Scaleform::GFx::AS2::GASPrototypeBase,
    this,
    psc,
    Scaleform::GFx::AS2::RectangleProto::FunctionTable,
    &flags);
  flags.Flags = 2;
  val.T.Type = 4;
  val.NV.Int32Value = 0;
  v6 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &result, "left");
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    v6,
    &val,
    &flags);
  pNode = result.pNode;
  v8 = result.pNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  flags.Flags = 2;
  val.T.Type = 4;
  val.NV.Int32Value = 0;
  v9 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &result, "top");
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    v9,
    &val,
    &flags);
  v10 = result.pNode;
  v8 = result.pNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v10);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  flags.Flags = 2;
  val.T.Type = 4;
  val.NV.Int32Value = 0;
  v11 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &result, "right");
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    v11,
    &val,
    &flags);
  v12 = result.pNode;
  v8 = result.pNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v12);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  flags.Flags = 2;
  val.T.Type = 4;
  val.NV.Int32Value = 0;
  v13 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &result, "bottom");
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    v13,
    &val,
    &flags);
  v14 = result.pNode;
  v8 = result.pNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v14);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  flags.Flags = 2;
  val.T.Type = 4;
  val.NV.Int32Value = 0;
  v15 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &result, "topLeft");
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    v15,
    &val,
    &flags);
  v16 = result.pNode;
  v8 = result.pNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v16);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  flags.Flags = 2;
  val.T.Type = 4;
  val.NV.Int32Value = 0;
  v17 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &result, "bottomRight");
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    v17,
    &val,
    &flags);
  v18 = result.pNode;
  v8 = result.pNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v18);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  flags.Flags = 2;
  val.T.Type = 4;
  val.NV.Int32Value = 0;
  v19 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &result, "size");
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    v19,
    &val,
    &flags);
  v20 = result.pNode;
  v8 = result.pNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v20);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
}

// File Line: 396
// RVA: 0x6B4DD0
void __fastcall Scaleform::GFx::AS2::RectangleProto::Clone(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rcx
  __int64 v3; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v4; // rax
  Scaleform::GFx::AS2::RectangleObject *v5; // rbx
  Scaleform::GFx::AS2::RectangleObject *v6; // rsi
  Scaleform::GFx::AS2::RectangleObject *v7; // rax
  Scaleform::GFx::AS2::RectangleObject *v8; // rax
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::Value ptr[4]; // [rsp+40h] [rbp-98h] BYREF

  ThisPtr = fn->ThisPtr;
  if ( ThisPtr
    && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(ThisPtr) == 17 )
  {
    v4 = fn->ThisPtr;
    v5 = 0i64;
    v6 = (Scaleform::GFx::AS2::RectangleObject *)&v4[-2];
    if ( !v4 )
      v6 = 0i64;
    v7 = (Scaleform::GFx::AS2::RectangleObject *)((__int64 (__fastcall *)(__int64, __int64))fn->Env->StringContext.pContext->pHeap->vfptr->Alloc)(
                                                   v3,
                                                   96i64);
    if ( v7 )
    {
      Scaleform::GFx::AS2::RectangleObject::RectangleObject(v7, fn->Env);
      v5 = v8;
    }
    `eh vector constructor iterator(ptr, 0x20ui64, 4, (void (__fastcall *)(void *))Scaleform::GFx::AS2::Value::Value);
    Scaleform::GFx::AS2::RectangleObject::GetProperties(v6, &fn->Env->StringContext, ptr);
    Scaleform::GFx::AS2::RectangleObject::SetProperties(v5, &fn->Env->StringContext, ptr);
    Scaleform::GFx::AS2::Value::SetAsObject(fn->Result, v5);
    `eh vector destructor iterator(ptr, 0x20ui64, 4, (void (__fastcall *)(void *))Scaleform::GFx::AS2::Value::~Value);
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
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      fn->Env,
      "Error: Null or invalid this is used for a method of %s class.\n",
      "Rectangle");
  }
}

// File Line: 413
// RVA: 0x6B4F30
void __fastcall Scaleform::GFx::AS2::RectangleProto::Contains(Scaleform::GFx::AS2::FnCall *fn)
{
  unsigned int FirstArgBottomIndex; // r9d
  Scaleform::GFx::AS2::Environment *Env; // rdx
  char v4; // di
  Scaleform::GFx::AS2::Value *v5; // r8
  unsigned int v6; // r8d
  Scaleform::GFx::AS2::Environment *v7; // r9
  Scaleform::GFx::AS2::Value *v8; // rdx
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v10; // rax
  Scaleform::GFx::AS2::RectangleObject *v11; // rcx
  double v12; // xmm6_8
  double v13; // xmm0_8
  Scaleform::GFx::AS2::Value *v14; // rbx
  Scaleform::GFx::AS2::Value *Result; // rbx
  Scaleform::Render::Rect<double> r; // [rsp+28h] [rbp-80h] BYREF
  Scaleform::GFx::AS2::Value v17; // [rsp+48h] [rbp-60h] BYREF
  Scaleform::GFx::AS2::Value v18; // [rsp+68h] [rbp-40h] BYREF

  if ( fn->NArgs <= 1 )
  {
    Result = fn->Result;
    Scaleform::GFx::AS2::Value::DropRefs(Result);
    Result->T.Type = 2;
    Result->V.BooleanValue = 0;
  }
  else
  {
    FirstArgBottomIndex = fn->FirstArgBottomIndex;
    Env = fn->Env;
    v4 = 0;
    v5 = 0i64;
    if ( FirstArgBottomIndex <= 32 * ((unsigned int)Env->Stack.Pages.Data.Size - 1)
                              + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
      v5 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
    Scaleform::GFx::AS2::Value::Value(&v18, v5);
    v6 = fn->FirstArgBottomIndex - 1;
    v7 = fn->Env;
    v8 = 0i64;
    if ( v6 <= 32 * ((unsigned int)v7->Stack.Pages.Data.Size - 1)
             + (unsigned int)(v7->Stack.pCurrent - v7->Stack.pPageStart) )
      v8 = &v7->Stack.Pages.Data.Data[v6 >> 5]->Values[v6 & 0x1F];
    Scaleform::GFx::AS2::Value::Value(&v17, v8);
    ThisPtr = fn->ThisPtr;
    if ( ThisPtr
      && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(ThisPtr) == 17 )
    {
      v10 = fn->ThisPtr;
      v11 = (Scaleform::GFx::AS2::RectangleObject *)&v10[-2];
      if ( !v10 )
        v11 = 0i64;
      memset(&r, 0, sizeof(r));
      Scaleform::GFx::AS2::RectangleObject::GetProperties(v11, fn->Env, &r);
      v12 = Scaleform::GFx::AS2::Value::ToNumber(&v18, fn->Env);
      v13 = Scaleform::GFx::AS2::Value::ToNumber(&v17, fn->Env);
      if ( (*(_QWORD *)&v12 & 0x7FF0000000000000i64) == 0x7FF0000000000000i64
        && (*(_QWORD *)&v12 & 0xFFFFFFFFFFFFFi64) != 0
        || (*(_QWORD *)&v13 & 0x7FF0000000000000i64) == 0x7FF0000000000000i64
        && (*(_QWORD *)&v13 & 0xFFFFFFFFFFFFFi64) != 0 )
      {
        v14 = fn->Result;
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
        v14 = fn->Result;
        Scaleform::GFx::AS2::Value::DropRefs(v14);
        v14->V.BooleanValue = v4;
      }
      v14->T.Type = 2;
    }
    else
    {
      Scaleform::GFx::AS2::Environment::LogScriptError(
        fn->Env,
        "Error: Null or invalid this is used for a method of %s class.\n",
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
  unsigned int FirstArgBottomIndex; // r10d
  Scaleform::GFx::AS2::Environment *Env; // r9
  char v4; // bp
  Scaleform::GFx::AS2::Value *v5; // rcx
  Scaleform::GFx::AS2::PointObject *v6; // r14
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v8; // rax
  Scaleform::GFx::AS2::RectangleObject *v9; // rbx
  Scaleform::GFx::AS2::Environment *v10; // rbx
  double x; // xmm7_8
  double y; // xmm6_8
  Scaleform::GFx::AS2::Value *Result; // rbx
  Scaleform::Render::Point<double> pt; // [rsp+38h] [rbp-B0h] BYREF
  Scaleform::Render::Rect<double> r; // [rsp+48h] [rbp-A0h] BYREF
  char ptr[32]; // [rsp+70h] [rbp-78h] BYREF
  char v17; // [rsp+90h] [rbp-58h] BYREF

  if ( fn->NArgs > 0 )
  {
    FirstArgBottomIndex = fn->FirstArgBottomIndex;
    Env = fn->Env;
    v4 = 0;
    v5 = 0i64;
    if ( FirstArgBottomIndex <= 32 * ((unsigned int)Env->Stack.Pages.Data.Size - 1)
                              + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
      v5 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
    v6 = (Scaleform::GFx::AS2::PointObject *)Scaleform::GFx::AS2::Value::ToObject(v5, Env);
    if ( v6 )
    {
      ThisPtr = fn->ThisPtr;
      if ( ThisPtr
        && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(ThisPtr) == 17 )
      {
        v8 = fn->ThisPtr;
        v9 = (Scaleform::GFx::AS2::RectangleObject *)&v8[-2];
        if ( !v8 )
          v9 = 0i64;
        memset(&r, 0, sizeof(r));
        `eh vector constructor iterator(
          ptr,
          0x20ui64,
          2,
          (void (__fastcall *)(void *))Scaleform::GFx::AS2::Value::Value);
        Scaleform::GFx::AS2::RectangleObject::GetProperties(v9, fn->Env, &r);
        v10 = fn->Env;
        ((void (__fastcall *)(Scaleform::GFx::AS2::ObjectInterface *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::Ptr<Scaleform::GFx::ASSupport> *, char *, void (__fastcall *)(Scaleform::GFx::AS2::Value *)))v6->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr->GetMemberRaw)(
          &v6->Scaleform::GFx::AS2::ObjectInterface,
          &v10->StringContext,
          &v10->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[33].pASSupport,
          ptr,
          Scaleform::GFx::AS2::Value::~Value);
        v6->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr->GetMemberRaw(
          &v6->Scaleform::GFx::AS2::ObjectInterface,
          &v10->StringContext,
          (Scaleform::GFx::ASString *)&v10->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[33].AVMVersion,
          (Scaleform::GFx::AS2::Value *)&v17);
        if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v6->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr->gap8[8])(&v6->Scaleform::GFx::AS2::ObjectInterface) == 16
          || ptr[0] && ptr[0] != 10 && v17 && v17 != 10 )
        {
          Scaleform::GFx::AS2::PointObject::GetProperties(v6, fn->Env, &pt);
          x = pt.x;
          if ( Scaleform::GFx::NumberUtil::IsNaN(pt.x) || (y = pt.y, Scaleform::GFx::NumberUtil::IsNaN(pt.y)) )
          {
            Result = fn->Result;
            Scaleform::GFx::AS2::Value::DropRefs(Result);
            Result->V.BooleanValue = 0;
          }
          else
          {
            if ( x == r.x2 )
              x = x + 1.0;
            if ( y == r.y2 )
              y = y + 1.0;
            if ( x <= r.x2 && x >= r.x1 && y <= r.y2 && y >= r.y1 )
              v4 = 1;
            Result = fn->Result;
            Scaleform::GFx::AS2::Value::DropRefs(Result);
            Result->V.BooleanValue = v4;
          }
          Result->T.Type = 2;
        }
        `eh vector destructor iterator(
          ptr,
          0x20ui64,
          2,
          (void (__fastcall *)(void *))Scaleform::GFx::AS2::Value::~Value);
      }
      else
      {
        Scaleform::GFx::AS2::Environment::LogScriptError(
          fn->Env,
          "Error: Null or invalid this is used for a method of %s class.\n",
          "Rectangle");
      }
    }
  }
}

// File Line: 503
// RVA: 0x6B5610
void __fastcall Scaleform::GFx::AS2::RectangleProto::ContainsRectangle(Scaleform::GFx::AS2::FnCall *fn)
{
  unsigned int FirstArgBottomIndex; // r10d
  Scaleform::GFx::AS2::Environment *Env; // r9
  char v4; // di
  Scaleform::GFx::AS2::Value *v5; // rcx
  Scaleform::GFx::AS2::Object *v6; // rbp
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v8; // rax
  Scaleform::GFx::AS2::RectangleObject *v9; // rsi
  double v10; // xmm6_8
  double v11; // xmm7_8
  double v12; // xmm8_8
  double v13; // xmm3_8
  Scaleform::GFx::AS2::Value *Result; // rbx
  Scaleform::Render::Rect<double> r; // [rsp+30h] [rbp-E8h] BYREF
  __int64 v16; // [rsp+50h] [rbp-C8h]
  Scaleform::GFx::AS2::Value ptr; // [rsp+60h] [rbp-B8h] BYREF
  Scaleform::GFx::AS2::Value v18; // [rsp+80h] [rbp-98h] BYREF
  Scaleform::GFx::AS2::Value v19; // [rsp+A0h] [rbp-78h] BYREF
  Scaleform::GFx::AS2::Value v20; // [rsp+C0h] [rbp-58h] BYREF

  v16 = -2i64;
  if ( fn->NArgs > 0 )
  {
    FirstArgBottomIndex = fn->FirstArgBottomIndex;
    Env = fn->Env;
    v4 = 0;
    v5 = 0i64;
    if ( FirstArgBottomIndex <= 32 * ((unsigned int)Env->Stack.Pages.Data.Size - 1)
                              + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
      v5 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
    v6 = Scaleform::GFx::AS2::Value::ToObject(v5, Env);
    if ( v6 )
    {
      ThisPtr = fn->ThisPtr;
      if ( ThisPtr
        && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(ThisPtr) == 17 )
      {
        v8 = fn->ThisPtr;
        v9 = (Scaleform::GFx::AS2::RectangleObject *)&v8[-2];
        if ( !v8 )
          v9 = 0i64;
        memset(&r, 0, sizeof(r));
        `eh vector constructor iterator(
          &ptr,
          0x20ui64,
          4,
          (void (__fastcall *)(void *))Scaleform::GFx::AS2::Value::Value);
        Scaleform::GFx::AS2::RectangleObject::GetProperties(v9, fn->Env, &r);
        Scaleform::GFx::AS2::GFxObject_GetRectangleProperties(fn->Env, v6, &ptr);
        if ( ptr.T.Type
          && ptr.T.Type != 10
          && v18.T.Type
          && v18.T.Type != 10
          && v19.T.Type
          && v19.T.Type != 10
          && v20.T.Type
          && v20.T.Type != 10 )
        {
          v10 = Scaleform::GFx::AS2::Value::ToNumber(&v20, fn->Env);
          v11 = Scaleform::GFx::AS2::Value::ToNumber(&v19, fn->Env);
          v12 = Scaleform::GFx::AS2::Value::ToNumber(&v18, fn->Env);
          v13 = Scaleform::GFx::AS2::Value::ToNumber(&ptr, fn->Env);
          if ( r.x2 >= v11 + v13 && r.y2 >= v12 + v10 && r.x1 <= v13 && r.y1 <= v12 )
            v4 = 1;
          Result = fn->Result;
          Scaleform::GFx::AS2::Value::DropRefs(Result);
          Result->T.Type = 2;
          Result->V.BooleanValue = v4;
        }
        `eh vector destructor iterator(
          &ptr,
          0x20ui64,
          4,
          (void (__fastcall *)(void *))Scaleform::GFx::AS2::Value::~Value);
      }
      else
      {
        Scaleform::GFx::AS2::Environment::LogScriptError(
          fn->Env,
          "Error: Null or invalid this is used for a method of %s class.\n",
          "Rectangle");
      }
    }
  }
}

// File Line: 539
// RVA: 0x6B58A0
void __fastcall Scaleform::GFx::AS2::RectangleProto::Equals(Scaleform::GFx::AS2::FnCall *fn)
{
  bool v2; // si
  unsigned int FirstArgBottomIndex; // r10d
  Scaleform::GFx::AS2::Environment *Env; // r9
  Scaleform::GFx::AS2::RectangleObject *v5; // rbp
  Scaleform::GFx::AS2::Value *v6; // rcx
  Scaleform::GFx::AS2::Object *v7; // rax
  Scaleform::GFx::AS2::RectangleObject *v8; // rdi
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v10; // rax
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::Value *Result; // rbx
  Scaleform::Render::Rect<double> r; // [rsp+28h] [rbp-50h] BYREF
  Scaleform::Render::Rect<double> v14; // [rsp+48h] [rbp-30h] BYREF

  v2 = 0;
  if ( fn->NArgs > 0 )
  {
    FirstArgBottomIndex = fn->FirstArgBottomIndex;
    Env = fn->Env;
    v5 = 0i64;
    v6 = 0i64;
    if ( FirstArgBottomIndex <= 32 * ((unsigned int)Env->Stack.Pages.Data.Size - 1)
                              + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
      v6 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
    v7 = Scaleform::GFx::AS2::Value::ToObject(v6, Env);
    v8 = (Scaleform::GFx::AS2::RectangleObject *)v7;
    if ( v7 )
    {
      if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v7->Scaleform::GFx::AS2::ObjectInterface::vfptr->gap8[8])(&v7->Scaleform::GFx::AS2::ObjectInterface) == 17 )
      {
        ThisPtr = fn->ThisPtr;
        if ( !ThisPtr
          || (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(ThisPtr) != 17 )
        {
          Scaleform::GFx::AS2::Environment::LogScriptError(
            fn->Env,
            "Error: Null or invalid this is used for a method of %s class.\n",
            "Rectangle");
          return;
        }
        v10 = fn->ThisPtr;
        if ( v10 )
          v5 = (Scaleform::GFx::AS2::RectangleObject *)&v10[-2];
        v8->RefCount = (v8->RefCount + 1) & 0x8FFFFFFF;
        memset(&r, 0, sizeof(r));
        memset(&v14, 0, sizeof(v14));
        Scaleform::GFx::AS2::RectangleObject::GetProperties(v5, fn->Env, &r);
        Scaleform::GFx::AS2::RectangleObject::GetProperties(v8, fn->Env, &v14);
        if ( Scaleform::GFx::AS2::IsRectValid(&r) && Scaleform::GFx::AS2::IsRectValid(&v14) )
          v2 = r.x1 == v14.x1 && r.x2 == v14.x2 && r.y1 == v14.y1 && r.y2 == v14.y2;
        RefCount = v8->RefCount;
        if ( (RefCount & 0x3FFFFFF) != 0 )
        {
          v8->RefCount = RefCount - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v8);
        }
      }
    }
  }
  Result = fn->Result;
  Scaleform::GFx::AS2::Value::DropRefs(Result);
  Result->T.Type = 2;
  Result->V.BooleanValue = v2;
}

// File Line: 566
// RVA: 0x6B5B60
void __fastcall Scaleform::GFx::AS2::RectangleProto::Inflate(Scaleform::GFx::AS2::FnCall *fn)
{
  bool BooleanValue; // di
  Scaleform::GFx::AS2::RectangleObject *v3; // rsi
  unsigned int FirstArgBottomIndex; // r9d
  Scaleform::GFx::AS2::Environment *Env; // r8
  Scaleform::GFx::AS2::Value *v6; // rdx
  unsigned int v7; // edx
  Scaleform::GFx::AS2::Environment *v8; // r9
  Scaleform::GFx::AS2::Value *v9; // r8
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v11; // rax
  double v12; // xmm6_8
  long double v13; // xmm0_8
  Scaleform::Render::Rect<double> r; // [rsp+20h] [rbp-29h] BYREF
  Scaleform::GFx::AS2::Value v15; // [rsp+40h] [rbp-9h] BYREF
  Scaleform::GFx::AS2::Value v16; // [rsp+60h] [rbp+17h] BYREF

  v16.V.BooleanValue = 0;
  BooleanValue = 0;
  v15.V.BooleanValue = 0;
  v3 = 0i64;
  if ( fn->NArgs > 0 )
  {
    FirstArgBottomIndex = fn->FirstArgBottomIndex;
    Env = fn->Env;
    v6 = 0i64;
    if ( FirstArgBottomIndex <= 32 * ((unsigned int)Env->Stack.Pages.Data.Size - 1)
                              + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
      v6 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
    Scaleform::GFx::AS2::Value::operator=((Scaleform::GFx::AS2::Value *)&v16.NV.8, v6);
    if ( fn->NArgs > 1 )
    {
      v7 = fn->FirstArgBottomIndex - 1;
      v8 = fn->Env;
      v9 = 0i64;
      if ( v7 <= 32 * ((unsigned int)v8->Stack.Pages.Data.Size - 1)
               + (unsigned int)(v8->Stack.pCurrent - v8->Stack.pPageStart) )
        v9 = &v8->Stack.Pages.Data.Data[v7 >> 5]->Values[v7 & 0x1F];
      Scaleform::GFx::AS2::Value::operator=((Scaleform::GFx::AS2::Value *)&v15.NV.8, v9);
      BooleanValue = v15.V.BooleanValue;
    }
  }
  ThisPtr = fn->ThisPtr;
  if ( ThisPtr
    && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(ThisPtr) == 17 )
  {
    v11 = fn->ThisPtr;
    if ( v11 )
      v3 = (Scaleform::GFx::AS2::RectangleObject *)&v11[-2];
    memset(&r.y1, 0, 24);
    *(_QWORD *)&v15.T.Type = 0i64;
    Scaleform::GFx::AS2::RectangleObject::GetProperties(v3, fn->Env, (Scaleform::Render::Rect<double> *)&r.y1);
    v12 = Scaleform::GFx::AS2::Value::ToNumber((Scaleform::GFx::AS2::Value *)&v15.NV.8, fn->Env);
    v13 = Scaleform::GFx::AS2::Value::ToNumber((Scaleform::GFx::AS2::Value *)&v16.NV.8, fn->Env);
    r.y1 = r.y1 - v13;
    r.y2 = r.y2 + v13;
    r.x2 = r.x2 - v12;
    *(double *)&v15.T.Type = *(double *)&v15.T.Type + v12;
    Scaleform::GFx::AS2::RectangleObject::SetProperties(v3, fn->Env, (Scaleform::Render::Rect<double> *)&r.y1);
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      fn->Env,
      "Error: Null or invalid this is used for a method of %s class.\n",
      "Rectangle");
  }
  if ( (unsigned __int8)BooleanValue >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)&v15.NV.8);
  if ( v16.V.BooleanValue >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)&v16.NV.8);
}

// File Line: 592
// RVA: 0x6B5E30
void __fastcall Scaleform::GFx::AS2::RectangleProto::InflatePoint(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rdi
  Scaleform::GFx::AS2::Value *v4; // r9
  Scaleform::GFx::AS2::RectangleObject *v5; // rdi
  Scaleform::GFx::AS2::Environment *Env; // rdx
  unsigned __int64 FirstArgBottomIndex; // r8
  Scaleform::GFx::AS2::Object *v8; // rax
  Scaleform::GFx::AS2::Environment *v9; // rdx
  Scaleform::GFx::AS2::Object *v10; // rsi
  Scaleform::GFx::AS2::Environment *v11; // rdx
  Scaleform::Render::Point<double> pt; // [rsp+20h] [rbp-38h] BYREF
  Scaleform::Render::Rect<double> r; // [rsp+30h] [rbp-28h] BYREF

  if ( fn->NArgs > 0 )
  {
    ThisPtr = fn->ThisPtr;
    if ( ThisPtr
      && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(ThisPtr) == 17 )
    {
      v3 = fn->ThisPtr;
      v4 = 0i64;
      if ( v3 )
        v5 = (Scaleform::GFx::AS2::RectangleObject *)&v3[-2];
      else
        v5 = 0i64;
      Env = fn->Env;
      FirstArgBottomIndex = (unsigned int)fn->FirstArgBottomIndex;
      if ( (unsigned int)FirstArgBottomIndex <= 32 * (LODWORD(Env->Stack.Pages.Data.Size) - 1)
                                              + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
        v4 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[fn->FirstArgBottomIndex & 0x1F];
      v8 = Scaleform::GFx::AS2::Value::ToObject(v4, Env);
      v9 = fn->Env;
      v10 = v8;
      if ( v8 )
      {
        memset(&r, 0, sizeof(r));
        Scaleform::GFx::AS2::RectangleObject::GetProperties(v5, v9, &r);
        Scaleform::GFx::AS2::GFxObject_GetPointProperties(fn->Env, v10, &pt);
        v11 = fn->Env;
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
        fn->Env,
        "Error: Null or invalid this is used for a method of %s class.\n",
        "Rectangle");
    }
  }
}

// File Line: 621
// RVA: 0x6B5FB0
void __fastcall Scaleform::GFx::AS2::RectangleProto::Intersection(Scaleform::GFx::AS2::FnCall *fn)
{
  double x1; // xmm11_8
  double y1; // xmm10_8
  double x2; // xmm9_8
  double y2; // xmm8_8
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rcx
  __int64 v7; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v8; // rax
  Scaleform::GFx::AS2::RectangleObject *v9; // rdi
  Scaleform::GFx::AS2::RectangleObject *v10; // rsi
  unsigned int FirstArgBottomIndex; // r10d
  Scaleform::GFx::AS2::Environment *Env; // rdx
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
  unsigned int RefCount; // eax
  Scaleform::Render::Rect<double> v24; // [rsp+30h] [rbp-A8h] BYREF
  Scaleform::Render::Rect<double> r; // [rsp+50h] [rbp-88h] BYREF
  Scaleform::Render::Rect<double> ptr; // [rsp+70h] [rbp-68h] BYREF
  Scaleform::GFx::AS2::Value v27; // [rsp+98h] [rbp-40h] BYREF
  Scaleform::GFx::AS2::Value v28; // [rsp+B8h] [rbp-20h] BYREF
  Scaleform::GFx::AS2::Value v29; // [rsp+D8h] [rbp+0h] BYREF
  Scaleform::MemoryHeap *pHeap; // [rsp+1C8h] [rbp+F0h]
  Scaleform::GFx::AS2::RectangleObject *v31; // [rsp+1D0h] [rbp+F8h]

  r.y2 = NAN;
  x1 = 0.0;
  memset(&v24, 0, sizeof(v24));
  y1 = 0.0;
  x2 = 0.0;
  y2 = 0.0;
  ThisPtr = fn->ThisPtr;
  if ( ThisPtr
    && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(ThisPtr) == 17 )
  {
    v8 = fn->ThisPtr;
    v9 = 0i64;
    v10 = (Scaleform::GFx::AS2::RectangleObject *)&v8[-2];
    if ( !v8 )
      v10 = 0i64;
    if ( fn->NArgs > 0 )
    {
      FirstArgBottomIndex = fn->FirstArgBottomIndex;
      Env = fn->Env;
      v13 = 0i64;
      if ( FirstArgBottomIndex <= 32 * ((unsigned int)Env->Stack.Pages.Data.Size - 1)
                                + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
        v13 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
      v14 = Scaleform::GFx::AS2::Value::ToObject(v13, Env);
      if ( v14 )
      {
        memset(&r, 0, sizeof(r));
        `eh vector constructor iterator(
          &ptr.y1,
          0x20ui64,
          4,
          (void (__fastcall *)(void *))Scaleform::GFx::AS2::Value::Value);
        Scaleform::GFx::AS2::RectangleObject::GetProperties(v10, fn->Env, &r);
        Scaleform::GFx::AS2::GFxObject_GetRectangleProperties(fn->Env, v14, (Scaleform::GFx::AS2::Value *)&ptr.y1);
        v15 = Scaleform::GFx::AS2::Value::ToNumber(&v29, fn->Env);
        v16 = Scaleform::GFx::AS2::Value::ToNumber(&v28, fn->Env);
        v17 = Scaleform::GFx::AS2::Value::ToNumber(&v27, fn->Env);
        v18 = Scaleform::GFx::AS2::Value::ToNumber((Scaleform::GFx::AS2::Value *)&ptr.y1, fn->Env);
        v19 = v17 + v15;
        v20 = v16 + v18;
        ptr.x1 = v18;
        ptr.y1 = v17;
        r.y1 = v20;
        r.x2 = v17 + v15;
        if ( !Scaleform::GFx::AS2::IsRectValid(&ptr) )
          goto LABEL_29;
        if ( r.y2 >= v17 && v19 >= r.y1 && v20 >= r.x1 && r.x2 >= v18 )
        {
          if ( r.x1 <= v18 )
          {
            x1 = v18;
            v24.x1 = v18;
          }
          else
          {
            x1 = r.x1;
            v24.x1 = r.x1;
          }
          if ( r.x2 <= v20 )
          {
            x2 = r.x2;
            v24.x2 = r.x2;
          }
          else
          {
            x2 = v20;
            v24.x2 = v20;
          }
          if ( r.y1 <= v17 )
          {
            y1 = v17;
            v24.y1 = v17;
          }
          else
          {
            y1 = r.y1;
            v24.y1 = r.y1;
          }
          if ( r.y2 <= v19 )
          {
            y2 = r.y2;
            v24.y2 = r.y2;
          }
          else
          {
            y2 = v17 + v15;
            v24.y2 = v17 + v15;
          }
        }
        if ( !Scaleform::GFx::AS2::IsRectValid(&v24) || x2 - x1 == 0.0 || y2 - y1 == 0.0 )
LABEL_29:
          memset(&v24, 0, sizeof(v24));
        `eh vector destructor iterator(
          &ptr.y1,
          0x20ui64,
          4,
          (void (__fastcall *)(void *))Scaleform::GFx::AS2::Value::~Value);
      }
    }
    pHeap = fn->Env->StringContext.pContext->pHeap;
    v21 = (Scaleform::GFx::AS2::RectangleObject *)((__int64 (__fastcall *)(__int64, __int64))pHeap->vfptr->Alloc)(
                                                    v7,
                                                    96i64);
    v31 = v21;
    if ( v21 )
    {
      Scaleform::GFx::AS2::RectangleObject::RectangleObject(v21, fn->Env);
      v9 = v22;
    }
    pHeap = (Scaleform::MemoryHeap *)v9;
    Scaleform::GFx::AS2::RectangleObject::SetProperties(v9, fn->Env, &v24);
    Scaleform::GFx::AS2::Value::SetAsObject(fn->Result, v9);
    if ( v9 )
    {
      RefCount = v9->RefCount;
      if ( (RefCount & 0x3FFFFFF) != 0 )
      {
        v9->RefCount = RefCount - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v9);
      }
    }
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      fn->Env,
      "Error: Null or invalid this is used for a method of %s class.\n",
      "Rectangle");
  }
}

// File Line: 669
// RVA: 0x6B63A0
void __fastcall Scaleform::GFx::AS2::RectangleProto::Intersects(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rcx
  char v3; // di
  Scaleform::GFx::AS2::ObjectInterface *v4; // rax
  Scaleform::GFx::AS2::Value *v5; // r9
  Scaleform::GFx::AS2::RectangleObject *v6; // rsi
  unsigned int FirstArgBottomIndex; // r10d
  Scaleform::GFx::AS2::Environment *Env; // rdx
  Scaleform::GFx::AS2::Object *v9; // r14
  double v10; // xmm12_8
  double v11; // xmm10_8
  double v12; // xmm13_8
  double v13; // xmm11_8
  double v14; // xmm12_8
  double v15; // xmm10_8
  double x1; // xmm9_8
  double y1; // xmm8_8
  double x2; // xmm7_8
  double y2; // xmm6_8
  Scaleform::GFx::AS2::Value *Result; // rbx
  Scaleform::Render::Rect<double> v21; // [rsp+30h] [rbp-B8h] BYREF
  Scaleform::Render::Rect<double> r; // [rsp+50h] [rbp-98h] BYREF
  Scaleform::Render::Rect<double> ptr; // [rsp+70h] [rbp-78h] BYREF
  Scaleform::GFx::AS2::Value v24; // [rsp+A8h] [rbp-40h] BYREF
  Scaleform::GFx::AS2::Value v25; // [rsp+C8h] [rbp-20h] BYREF
  Scaleform::GFx::AS2::Value v26; // [rsp+E8h] [rbp+0h] BYREF

  ptr.y1 = NAN;
  ThisPtr = fn->ThisPtr;
  if ( ThisPtr
    && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(ThisPtr) == 17 )
  {
    v3 = 0;
    v4 = fn->ThisPtr;
    v5 = 0i64;
    v6 = (Scaleform::GFx::AS2::RectangleObject *)&v4[-2];
    if ( !v4 )
      v6 = 0i64;
    if ( fn->NArgs > 0 )
    {
      FirstArgBottomIndex = fn->FirstArgBottomIndex;
      Env = fn->Env;
      if ( FirstArgBottomIndex <= 32 * ((unsigned int)Env->Stack.Pages.Data.Size - 1)
                                + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
        v5 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
      v9 = Scaleform::GFx::AS2::Value::ToObject(v5, Env);
      if ( v9 )
      {
        memset(&r, 0, sizeof(r));
        `eh vector constructor iterator(
          &ptr.y2,
          0x20ui64,
          4,
          (void (__fastcall *)(void *))Scaleform::GFx::AS2::Value::Value);
        Scaleform::GFx::AS2::RectangleObject::GetProperties(v6, fn->Env, &r);
        Scaleform::GFx::AS2::GFxObject_GetRectangleProperties(fn->Env, v9, (Scaleform::GFx::AS2::Value *)&ptr.y2);
        v10 = Scaleform::GFx::AS2::Value::ToNumber(&v26, fn->Env);
        v11 = Scaleform::GFx::AS2::Value::ToNumber(&v25, fn->Env);
        v12 = Scaleform::GFx::AS2::Value::ToNumber(&v24, fn->Env);
        v13 = Scaleform::GFx::AS2::Value::ToNumber((Scaleform::GFx::AS2::Value *)&ptr.y2, fn->Env);
        v14 = v10 + v12;
        v15 = v11 + v13;
        ptr.y1 = v12;
        r.y2 = v15;
        ptr.x1 = v14;
        x1 = 0.0;
        memset(&v21, 0, sizeof(v21));
        y1 = 0.0;
        x2 = 0.0;
        y2 = 0.0;
        if ( !Scaleform::GFx::AS2::IsRectValid(&r) || !Scaleform::GFx::AS2::IsRectValid(&ptr) )
          goto LABEL_30;
        if ( r.y2 >= v12 && v14 >= r.y1 && v15 >= r.x1 && r.x2 >= v13 )
        {
          if ( r.x1 <= v13 )
          {
            x1 = v13;
            v21.x1 = v13;
          }
          else
          {
            x1 = r.x1;
            v21.x1 = r.x1;
          }
          if ( r.x2 <= v15 )
          {
            x2 = r.x2;
            v21.x2 = r.x2;
          }
          else
          {
            x2 = v15;
            v21.x2 = v15;
          }
          if ( r.y1 <= v12 )
          {
            y1 = v12;
            v21.y1 = v12;
          }
          else
          {
            y1 = r.y1;
            v21.y1 = r.y1;
          }
          if ( r.y2 <= v14 )
          {
            y2 = r.y2;
            v21.y2 = r.y2;
          }
          else
          {
            y2 = v14;
            v21.y2 = v14;
          }
        }
        v3 = 1;
        if ( !Scaleform::GFx::AS2::IsRectValid(&v21) || x2 - x1 == 0.0 || y2 - y1 == 0.0 )
LABEL_30:
          v3 = 0;
        `eh vector destructor iterator(
          &ptr.y2,
          0x20ui64,
          4,
          (void (__fastcall *)(void *))Scaleform::GFx::AS2::Value::~Value);
      }
    }
    Result = fn->Result;
    Scaleform::GFx::AS2::Value::DropRefs(Result);
    Result->T.Type = 2;
    Result->V.BooleanValue = v3;
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      fn->Env,
      "Error: Null or invalid this is used for a method of %s class.\n",
      "Rectangle");
  }
}

// File Line: 714
// RVA: 0x6B6720
void __fastcall Scaleform::GFx::AS2::RectangleProto::IsEmpty(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rax
  Scaleform::GFx::AS2::RectangleObject *v4; // rdi
  double v5; // xmm0_8
  double v6; // xmm0_8
  double v7; // xmm6_8
  bool v8; // di
  Scaleform::GFx::AS2::Value *Result; // rbx
  Scaleform::GFx::AS2::Value ptr; // [rsp+40h] [rbp-98h] BYREF
  Scaleform::GFx::AS2::Value v11; // [rsp+60h] [rbp-78h] BYREF
  Scaleform::GFx::AS2::Value v12; // [rsp+80h] [rbp-58h] BYREF
  Scaleform::GFx::AS2::Value v13; // [rsp+A0h] [rbp-38h] BYREF

  ThisPtr = fn->ThisPtr;
  if ( ThisPtr
    && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(ThisPtr) == 17 )
  {
    v3 = fn->ThisPtr;
    if ( v3 )
      v4 = (Scaleform::GFx::AS2::RectangleObject *)&v3[-2];
    else
      v4 = 0i64;
    `eh vector constructor iterator(&ptr, 0x20ui64, 4, (void (__fastcall *)(void *))Scaleform::GFx::AS2::Value::Value);
    Scaleform::GFx::AS2::RectangleObject::GetProperties(v4, &fn->Env->StringContext, &ptr);
    v5 = Scaleform::GFx::AS2::Value::ToNumber(&v12, fn->Env);
    v8 = 1;
    if ( (*(_QWORD *)&v5 & 0x7FF0000000000000i64) != 0x7FF0000000000000i64 || (*(_QWORD *)&v5 & 0xFFFFFFFFFFFFFi64) == 0 )
    {
      v6 = Scaleform::GFx::AS2::Value::ToNumber(&v13, fn->Env);
      if ( (*(_QWORD *)&v6 & 0x7FF0000000000000i64) != 0x7FF0000000000000i64
        || (*(_QWORD *)&v6 & 0xFFFFFFFFFFFFFi64) == 0 )
      {
        Scaleform::GFx::AS2::Value::ToNumber(&ptr, fn->Env);
        Scaleform::GFx::AS2::Value::ToNumber(&v11, fn->Env);
        v7 = Scaleform::GFx::AS2::Value::ToNumber(&v13, fn->Env);
        if ( Scaleform::GFx::AS2::Value::ToNumber(&v12, fn->Env) > 0.0 && v7 > 0.0 )
          v8 = 0;
      }
    }
    Result = fn->Result;
    Scaleform::GFx::AS2::Value::DropRefs(Result);
    Result->T.Type = 2;
    Result->V.BooleanValue = v8;
    `eh vector destructor iterator(&ptr, 0x20ui64, 4, (void (__fastcall *)(void *))Scaleform::GFx::AS2::Value::~Value);
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      fn->Env,
      "Error: Null or invalid this is used for a method of %s class.\n",
      "Rectangle");
  }
}

// File Line: 744
// RVA: 0x6B68F0
void __fastcall Scaleform::GFx::AS2::RectangleProto::Offset(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rcx
  char Type; // si
  Scaleform::GFx::AS2::RectangleObject *v4; // rdi
  unsigned int FirstArgBottomIndex; // r9d
  Scaleform::GFx::AS2::Environment *Env; // r8
  Scaleform::GFx::AS2::Value *v7; // rdx
  unsigned int v8; // edx
  Scaleform::GFx::AS2::Environment *v9; // r9
  Scaleform::GFx::AS2::Value *v10; // r8
  Scaleform::GFx::AS2::ObjectInterface *v11; // rax
  double v12; // xmm6_8
  long double v13; // xmm0_8
  double v14; // xmm6_8
  long double v15; // xmm0_8
  Scaleform::GFx::AS2::Value v; // [rsp+30h] [rbp-C8h] BYREF
  Scaleform::GFx::AS2::Value v17; // [rsp+50h] [rbp-A8h] BYREF
  Scaleform::GFx::AS2::Value v18; // [rsp+70h] [rbp-88h] BYREF
  Scaleform::GFx::AS2::Value ptr; // [rsp+98h] [rbp-60h] BYREF
  Scaleform::GFx::AS2::Value v20; // [rsp+B8h] [rbp-40h] BYREF

  *((_QWORD *)&v18.NV + 3) = -2i64;
  ThisPtr = fn->ThisPtr;
  if ( ThisPtr
    && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(ThisPtr) == 17 )
  {
    v18.T.Type = 0;
    Type = 0;
    v17.T.Type = 0;
    v4 = 0i64;
    if ( fn->NArgs > 0 )
    {
      FirstArgBottomIndex = fn->FirstArgBottomIndex;
      Env = fn->Env;
      v7 = 0i64;
      if ( FirstArgBottomIndex <= 32 * ((unsigned int)Env->Stack.Pages.Data.Size - 1)
                                + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
        v7 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
      Scaleform::GFx::AS2::Value::operator=(&v18, v7);
      if ( fn->NArgs > 1 )
      {
        v8 = fn->FirstArgBottomIndex - 1;
        v9 = fn->Env;
        v10 = 0i64;
        if ( v8 <= 32 * ((unsigned int)v9->Stack.Pages.Data.Size - 1)
                 + (unsigned int)(v9->Stack.pCurrent - v9->Stack.pPageStart) )
          v10 = &v9->Stack.Pages.Data.Data[v8 >> 5]->Values[v8 & 0x1F];
        Scaleform::GFx::AS2::Value::operator=(&v17, v10);
        Type = v17.T.Type;
      }
    }
    v11 = fn->ThisPtr;
    if ( v11 )
      v4 = (Scaleform::GFx::AS2::RectangleObject *)&v11[-2];
    `eh vector constructor iterator(&ptr, 0x20ui64, 4, (void (__fastcall *)(void *))Scaleform::GFx::AS2::Value::Value);
    Scaleform::GFx::AS2::RectangleObject::GetProperties(v4, &fn->Env->StringContext, &ptr);
    v12 = Scaleform::GFx::AS2::Value::ToNumber(&ptr, fn->Env);
    v13 = Scaleform::GFx::AS2::Value::ToNumber(&v18, fn->Env);
    v.T.Type = 3;
    v.NV.NumberValue = v12 + v13;
    Scaleform::GFx::AS2::Value::operator=(&ptr, &v);
    if ( v.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v);
    v14 = Scaleform::GFx::AS2::Value::ToNumber(&v20, fn->Env);
    v15 = Scaleform::GFx::AS2::Value::ToNumber(&v17, fn->Env);
    v.T.Type = 3;
    v.NV.NumberValue = v14 + v15;
    Scaleform::GFx::AS2::Value::operator=(&v20, &v);
    if ( v.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v);
    Scaleform::GFx::AS2::RectangleObject::SetProperties(v4, &fn->Env->StringContext, &ptr);
    `eh vector destructor iterator(&ptr, 0x20ui64, 4, (void (__fastcall *)(void *))Scaleform::GFx::AS2::Value::~Value);
    if ( (unsigned __int8)Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v17);
    if ( v18.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v18);
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      fn->Env,
      "Error: Null or invalid this is used for a method of %s class.\n",
      "Rectangle");
  }
}

// File Line: 773
// RVA: 0x6B6B60
void __fastcall Scaleform::GFx::AS2::RectangleProto::OffsetPoint(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // r14
  Scaleform::GFx::AS2::Value *v4; // r9
  Scaleform::GFx::AS2::RectangleObject *v5; // r14
  unsigned int FirstArgBottomIndex; // r10d
  Scaleform::GFx::AS2::Environment *Env; // rdx
  Scaleform::GFx::AS2::Object *v8; // rdi
  long double v9; // xmm0_8
  Scaleform::GFx::AS2::Environment *v10; // rbx
  Scaleform::GFx::AS2::ObjectInterface *v11; // rdi
  long double v12; // xmm0_8
  double v13; // xmm6_8
  long double v14; // xmm0_8
  double v15; // xmm6_8
  long double v16; // xmm0_8
  Scaleform::GFx::AS2::Value v; // [rsp+30h] [rbp-B8h] BYREF
  Scaleform::GFx::AS2::Value ptr; // [rsp+50h] [rbp-98h] BYREF
  Scaleform::GFx::AS2::Value params; // [rsp+70h] [rbp-78h] BYREF
  Scaleform::GFx::AS2::Value v20; // [rsp+98h] [rbp-50h] BYREF
  __int64 v21; // [rsp+F8h] [rbp+10h]

  v21 = -2i64;
  if ( fn->NArgs > 0 )
  {
    ThisPtr = fn->ThisPtr;
    if ( ThisPtr
      && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(ThisPtr) == 17 )
    {
      v3 = fn->ThisPtr;
      v4 = 0i64;
      if ( v3 )
        v5 = (Scaleform::GFx::AS2::RectangleObject *)&v3[-2];
      else
        v5 = 0i64;
      FirstArgBottomIndex = fn->FirstArgBottomIndex;
      Env = fn->Env;
      if ( FirstArgBottomIndex <= 32 * ((unsigned int)Env->Stack.Pages.Data.Size - 1)
                                + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
        v4 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
      v8 = Scaleform::GFx::AS2::Value::ToObject(v4, Env);
      `eh vector constructor iterator(
        &params.NV.8,
        0x20ui64,
        4,
        (void (__fastcall *)(void *))Scaleform::GFx::AS2::Value::Value);
      if ( !v8 )
      {
        Scaleform::GFx::AS2::RectangleObject::GetProperties(
          v5,
          &fn->Env->StringContext,
          (Scaleform::GFx::AS2::Value *)&params.NV.8);
        v.T.Type = 3;
        v.V.pStringNode = COERCE_SCALEFORM_GFX_ASSTRINGNODE_(Scaleform::GFx::NumberUtil::NaN());
        Scaleform::GFx::AS2::Value::operator=((Scaleform::GFx::AS2::Value *)&params.NV.8, &v);
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
          &fn->Env->StringContext,
          (Scaleform::GFx::AS2::Value *)&params.NV.8);
LABEL_25:
        `eh vector destructor iterator(
          &params.NV.8,
          0x20ui64,
          4,
          (void (__fastcall *)(void *))Scaleform::GFx::AS2::Value::~Value);
        return;
      }
      `eh vector constructor iterator(
        &ptr,
        0x20ui64,
        2,
        (void (__fastcall *)(void *))Scaleform::GFx::AS2::Value::Value);
      v10 = fn->Env;
      v11 = &v8->Scaleform::GFx::AS2::ObjectInterface;
      ((void (__fastcall *)(Scaleform::GFx::AS2::ObjectInterface *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::Ptr<Scaleform::GFx::ASSupport> *, Scaleform::GFx::AS2::Value *, void (__fastcall *)(Scaleform::GFx::AS2::Value *)))v11->vfptr->GetMemberRaw)(
        v11,
        &v10->StringContext,
        &v10->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[33].pASSupport,
        &ptr,
        Scaleform::GFx::AS2::Value::~Value);
      v11->vfptr->GetMemberRaw(
        v11,
        &v10->StringContext,
        (Scaleform::GFx::ASString *)&v10->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[33].AVMVersion,
        &params);
      if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v11->vfptr->gap8[8])(v11) != 16
        && (!ptr.T.Type || ptr.T.Type == 10 || !params.T.Type || params.T.Type == 10) )
      {
        Scaleform::GFx::AS2::RectangleObject::GetProperties(
          v5,
          &fn->Env->StringContext,
          (Scaleform::GFx::AS2::Value *)&params.NV.8);
        v.T.Type = 3;
        v.V.pStringNode = COERCE_SCALEFORM_GFX_ASSTRINGNODE_(Scaleform::GFx::NumberUtil::NaN());
        Scaleform::GFx::AS2::Value::operator=((Scaleform::GFx::AS2::Value *)&params.NV.8, &v);
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
          &fn->Env->StringContext,
          (Scaleform::GFx::AS2::Value *)&params.NV.8);
        `eh vector destructor iterator(
          &ptr,
          0x20ui64,
          2,
          (void (__fastcall *)(void *))Scaleform::GFx::AS2::Value::~Value);
        goto LABEL_25;
      }
      Scaleform::GFx::AS2::RectangleObject::GetProperties(
        v5,
        &fn->Env->StringContext,
        (Scaleform::GFx::AS2::Value *)&params.NV.8);
      v13 = Scaleform::GFx::AS2::Value::ToNumber(&ptr, fn->Env);
      v14 = Scaleform::GFx::AS2::Value::ToNumber((Scaleform::GFx::AS2::Value *)&params.NV.8, fn->Env);
      v.T.Type = 3;
      v.NV.NumberValue = v13 + v14;
      Scaleform::GFx::AS2::Value::operator=((Scaleform::GFx::AS2::Value *)&params.NV.8, &v);
      if ( v.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v);
      v15 = Scaleform::GFx::AS2::Value::ToNumber(&params, fn->Env);
      v16 = Scaleform::GFx::AS2::Value::ToNumber(&v20, fn->Env);
      v.T.Type = 3;
      v.NV.NumberValue = v15 + v16;
      Scaleform::GFx::AS2::Value::operator=(&v20, &v);
      if ( v.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v);
      Scaleform::GFx::AS2::RectangleObject::SetProperties(
        v5,
        &fn->Env->StringContext,
        (Scaleform::GFx::AS2::Value *)&params.NV.8);
      `eh vector destructor iterator(
        &ptr,
        0x20ui64,
        2,
        (void (__fastcall *)(void *))Scaleform::GFx::AS2::Value::~Value);
      `eh vector destructor iterator(
        &params.NV.8,
        0x20ui64,
        4,
        (void (__fastcall *)(void *))Scaleform::GFx::AS2::Value::~Value);
    }
    else
    {
      Scaleform::GFx::AS2::Environment::LogScriptError(
        fn->Env,
        "Error: Null or invalid this is used for a method of %s class.\n",
        "Rectangle");
    }
  }
}

// File Line: 817
// RVA: 0x6B6F80
void __fastcall Scaleform::GFx::AS2::RectangleProto::SetEmpty(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rax
  Scaleform::GFx::AS2::RectangleObject *v4; // rcx
  Scaleform::GFx::AS2::Environment *Env; // rdx
  Scaleform::Render::Rect<double> r; // [rsp+20h] [rbp-28h] BYREF

  ThisPtr = fn->ThisPtr;
  if ( ThisPtr
    && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(ThisPtr) == 17 )
  {
    v3 = fn->ThisPtr;
    if ( v3 )
      v4 = (Scaleform::GFx::AS2::RectangleObject *)&v3[-2];
    else
      v4 = 0i64;
    Env = fn->Env;
    memset(&r, 0, sizeof(r));
    Scaleform::GFx::AS2::RectangleObject::SetProperties(v4, Env, &r);
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      fn->Env,
      "Error: Null or invalid this is used for a method of %s class.\n",
      "Rectangle");
  }
}

// File Line: 828
// RVA: 0x6B7000
void __fastcall Scaleform::GFx::AS2::RectangleProto::ToString(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rax
  Scaleform::GFx::AS2::RectangleObject *v4; // rdi
  Scaleform::GFx::ASString *v5; // rsi
  Scaleform::GFx::AS2::Value *v6; // rbx
  Scaleform::GFx::ASStringNode *pNode; // rax
  Scaleform::GFx::ASStringNode *v8; // rcx
  Scaleform::GFx::ASString result; // [rsp+18h] [rbp-69h] BYREF
  void (__fastcall *pDtor)(void *); // [rsp+20h] [rbp-61h] BYREF
  Scaleform::GFx::ASString v12; // [rsp+28h] [rbp-59h] BYREF
  Scaleform::GFx::ASString v13; // [rsp+30h] [rbp-51h] BYREF
  __int64 v14; // [rsp+38h] [rbp-49h]
  Scaleform::GFx::AS2::Value ptr; // [rsp+48h] [rbp-39h] BYREF
  Scaleform::GFx::AS2::Value v16; // [rsp+68h] [rbp-19h] BYREF
  Scaleform::GFx::AS2::Value v17; // [rsp+88h] [rbp+7h] BYREF
  Scaleform::GFx::AS2::Value v18; // [rsp+A8h] [rbp+27h] BYREF
  Scaleform::String str; // [rsp+E8h] [rbp+67h] BYREF
  Scaleform::GFx::ASString vars0; // [rsp+F0h] [rbp+6Fh] BYREF

  v14 = -2i64;
  ThisPtr = fn->ThisPtr;
  if ( ThisPtr
    && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(ThisPtr) == 17 )
  {
    v3 = fn->ThisPtr;
    if ( v3 )
    {
      v4 = (Scaleform::GFx::AS2::RectangleObject *)&v3[-2];
      if ( v3 != (Scaleform::GFx::AS2::ObjectInterface *)32 )
      {
        pDtor = (void (__fastcall *)(void *))Scaleform::GFx::AS2::Value::~Value;
        `eh vector constructor iterator(
          &ptr,
          0x20ui64,
          4,
          (void (__fastcall *)(void *))Scaleform::GFx::AS2::Value::Value);
        Scaleform::GFx::AS2::RectangleObject::GetProperties(v4, &fn->Env->StringContext, &ptr);
        Scaleform::GFx::AS2::Value::ToString(&ptr, &result, fn->Env, 6);
        Scaleform::GFx::AS2::Value::ToString(&v16, (Scaleform::GFx::ASString *)&pDtor, fn->Env, 6);
        Scaleform::GFx::AS2::Value::ToString(&v17, &v12, fn->Env, 6);
        Scaleform::GFx::AS2::Value::ToString(&v18, &v13, fn->Env, 6);
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
        v5 = Scaleform::GFx::AS2::Environment::CreateString(fn->Env, &vars0, &str);
        v6 = fn->Result;
        if ( v6->T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(v6);
        v6->T.Type = 5;
        pNode = v5->pNode;
        v6->NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)v5->pNode;
        ++pNode->RefCount;
        v8 = vars0.pNode;
        if ( vars0.pNode->RefCount-- == 1 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v8);
        if ( _InterlockedExchangeAdd(
               (volatile signed __int32 *)((str.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8),
               0xFFFFFFFF) == 1 )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        `eh vector destructor iterator(
          &result,
          8ui64,
          4,
          (void (__fastcall *)(void *))Scaleform::GFx::ASString::~ASString);
        `eh vector destructor iterator(
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
      fn->Env,
      "Error: Null or invalid this is used for a method of %s class.\n",
      "Rectangle");
  }
}ull or invalid this is used for a method of %s class.\n",

// File Line: 863
// RVA: 0x6B7280
void __fastcall Scaleform::GFx::AS2::RectangleProto::Union(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rcx
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
  unsigned int FirstArgBottomIndex; // r9d
  Scaleform::GFx::AS2::Environment *Env; // rdx
  Scaleform::GFx::AS2::Object *v15; // rsi
  double v16; // xmm8_8
  double v17; // xmm7_8
  double v18; // xmm6_8
  double v19; // xmm0_8
  double v20; // xmm0_8
  unsigned int RefCount; // eax
  Scaleform::Render::Rect<double> v22; // [rsp+30h] [rbp-A8h] BYREF
  Scaleform::Render::Rect<double> r; // [rsp+50h] [rbp-88h] BYREF
  Scaleform::Render::Rect<double> ptr; // [rsp+70h] [rbp-68h] BYREF
  Scaleform::GFx::AS2::Value v25; // [rsp+98h] [rbp-40h] BYREF
  Scaleform::GFx::AS2::Value v26; // [rsp+B8h] [rbp-20h] BYREF
  Scaleform::GFx::AS2::Value v27; // [rsp+D8h] [rbp+0h] BYREF
  Scaleform::MemoryHeap *pHeap; // [rsp+158h] [rbp+80h]
  Scaleform::GFx::AS2::RectangleObject *v29; // [rsp+160h] [rbp+88h]

  r.y2 = NAN;
  ThisPtr = fn->ThisPtr;
  if ( ThisPtr
    && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(ThisPtr) == 17 )
  {
    v4 = fn->ThisPtr;
    v5 = 0i64;
    v6 = (Scaleform::GFx::AS2::RectangleObject *)&v4[-2];
    if ( !v4 )
      v6 = 0i64;
    pHeap = fn->Env->StringContext.pContext->pHeap;
    v7 = (Scaleform::GFx::AS2::RectangleObject *)((__int64 (__fastcall *)(__int64, __int64))pHeap->vfptr->Alloc)(
                                                   v3,
                                                   96i64);
    v29 = v7;
    if ( v7 )
    {
      Scaleform::GFx::AS2::RectangleObject::RectangleObject(v7, fn->Env);
      v9 = v8;
    }
    else
    {
      v9 = 0i64;
    }
    v29 = v9;
    Scaleform::GFx::AS2::Value::SetAsObject(fn->Result, v9);
    if ( fn->NArgs <= 0 )
    {
      Scaleform::GFx::AS2::RectangleObject::SetProperties(v9, &fn->Env->StringContext, Rectangle_NaNParams);
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
      FirstArgBottomIndex = fn->FirstArgBottomIndex;
      Env = fn->Env;
      if ( FirstArgBottomIndex <= 32 * ((unsigned int)Env->Stack.Pages.Data.Size - 1)
                                + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
        v5 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
      v15 = Scaleform::GFx::AS2::Value::ToObject(v5, Env);
      if ( v15 )
      {
        memset(&r, 0, sizeof(r));
        `eh vector constructor iterator(
          &ptr.y1,
          0x20ui64,
          4,
          (void (__fastcall *)(void *))Scaleform::GFx::AS2::Value::Value);
        Scaleform::GFx::AS2::RectangleObject::GetProperties(v6, fn->Env, &r);
        Scaleform::GFx::AS2::GFxObject_GetRectangleProperties(fn->Env, v15, (Scaleform::GFx::AS2::Value *)&ptr.y1);
        v16 = Scaleform::GFx::AS2::Value::ToNumber(&v27, fn->Env);
        v17 = Scaleform::GFx::AS2::Value::ToNumber(&v26, fn->Env);
        v18 = Scaleform::GFx::AS2::Value::ToNumber(&v25, fn->Env);
        ptr.x1 = Scaleform::GFx::AS2::Value::ToNumber((Scaleform::GFx::AS2::Value *)&ptr.y1, fn->Env);
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
        v19 = Scaleform::GFx::AS2::Value::ToNumber((Scaleform::GFx::AS2::Value *)&ptr.y1, fn->Env);
        pHeap = *(Scaleform::MemoryHeap **)&v19;
        if ( (*(_QWORD *)&v19 & 0x7FF0000000000000i64) == 0x7FF0000000000000i64
          && (*(_QWORD *)&v19 & 0xFFFFFFFFFFFFFi64) != 0 )
        {
          v22.x1 = Scaleform::GFx::NumberUtil::NaN();
        }
        v20 = Scaleform::GFx::AS2::Value::ToNumber(&v25, fn->Env);
        pHeap = *(Scaleform::MemoryHeap **)&v20;
        if ( (*(_QWORD *)&v20 & 0x7FF0000000000000i64) == 0x7FF0000000000000i64
          && (*(_QWORD *)&v20 & 0xFFFFFFFFFFFFFi64) != 0 )
        {
          v22.y1 = Scaleform::GFx::NumberUtil::NaN();
        }
        `eh vector destructor iterator(
          &ptr.y1,
          0x20ui64,
          4,
          (void (__fastcall *)(void *))Scaleform::GFx::AS2::Value::~Value);
      }
      Scaleform::GFx::AS2::RectangleObject::SetProperties(v9, fn->Env, &v22);
    }
    if ( v9 )
    {
      RefCount = v9->RefCount;
      if ( (RefCount & 0x3FFFFFF) != 0 )
      {
        v9->RefCount = RefCount - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v9);
      }
    }
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      fn->Env,
      "Error: Null or invalid this is used for a method of %s class.\n",
      "Rectangle");
  }
}

// File Line: 911
// RVA: 0x6F9E60
void __fastcall Scaleform::GFx::AS2::RectangleCtorFunction::GlobalCtor(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Value *v2; // rsi
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v4; // rbx
  Scaleform::GFx::AS2::RectangleObject *v5; // rbx
  Scaleform::GFx::AS2::RectangleObject *v6; // rax
  Scaleform::GFx::AS2::RectangleObject *v7; // rax
  unsigned int FirstArgBottomIndex; // r8d
  Scaleform::GFx::AS2::Environment *Env; // r9
  Scaleform::GFx::AS2::Value *v10; // rdx
  unsigned int v11; // edx
  Scaleform::GFx::AS2::Environment *v12; // r9
  Scaleform::GFx::AS2::Value *v13; // r8
  unsigned int v14; // edx
  Scaleform::GFx::AS2::Environment *v15; // r9
  Scaleform::GFx::AS2::Value *v16; // r8
  unsigned int v17; // edx
  Scaleform::GFx::AS2::Environment *v18; // r8
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::Value ptr; // [rsp+40h] [rbp-98h] BYREF
  Scaleform::GFx::AS2::Value v21; // [rsp+60h] [rbp-78h] BYREF
  Scaleform::GFx::AS2::Value v22; // [rsp+80h] [rbp-58h] BYREF
  Scaleform::GFx::AS2::Value v23; // [rsp+A0h] [rbp-38h] BYREF

  v2 = 0i64;
  ThisPtr = fn->ThisPtr;
  if ( ThisPtr
    && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(ThisPtr) == 17
    && !fn->ThisPtr->vfptr->IsBuiltinPrototype(fn->ThisPtr) )
  {
    v4 = fn->ThisPtr;
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
  else
  {
    v6 = (Scaleform::GFx::AS2::RectangleObject *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::ObjectInterface *, __int64))fn->Env->StringContext.pContext->pHeap->vfptr->Alloc)(
                                                   ThisPtr,
                                                   96i64);
    if ( v6 )
    {
      Scaleform::GFx::AS2::RectangleObject::RectangleObject(v6, fn->Env);
      v5 = v7;
    }
    else
    {
      v5 = 0i64;
    }
  }
  Scaleform::GFx::AS2::Value::SetAsObject(fn->Result, v5);
  if ( fn->NArgs > 0 )
  {
    `eh vector constructor iterator(&ptr, 0x20ui64, 4, (void (__fastcall *)(void *))Scaleform::GFx::AS2::Value::Value);
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
      v13 = 0i64;
      if ( v11 <= 32 * ((unsigned int)v12->Stack.Pages.Data.Size - 1)
                + (unsigned int)(v12->Stack.pCurrent - v12->Stack.pPageStart) )
        v13 = &v12->Stack.Pages.Data.Data[v11 >> 5]->Values[v11 & 0x1F];
      Scaleform::GFx::AS2::Value::operator=(&v21, v13);
      if ( fn->NArgs > 2 )
      {
        v14 = fn->FirstArgBottomIndex - 2;
        v15 = fn->Env;
        v16 = 0i64;
        if ( v14 <= 32 * ((unsigned int)v15->Stack.Pages.Data.Size - 1)
                  + (unsigned int)(v15->Stack.pCurrent - v15->Stack.pPageStart) )
          v16 = &v15->Stack.Pages.Data.Data[v14 >> 5]->Values[v14 & 0x1F];
        Scaleform::GFx::AS2::Value::operator=(&v22, v16);
        if ( fn->NArgs > 3 )
        {
          v17 = fn->FirstArgBottomIndex - 3;
          v18 = fn->Env;
          if ( v17 <= 32 * ((unsigned int)v18->Stack.Pages.Data.Size - 1)
                    + (unsigned int)(v18->Stack.pCurrent - v18->Stack.pPageStart) )
            v2 = &v18->Stack.Pages.Data.Data[v17 >> 5]->Values[v17 & 0x1F];
          Scaleform::GFx::AS2::Value::operator=(&v23, v2);
        }
      }
    }
    Scaleform::GFx::AS2::RectangleObject::SetProperties(v5, &fn->Env->StringContext, &ptr);
    `eh vector destructor iterator(&ptr, 0x20ui64, 4, (void (__fastcall *)(void *))Scaleform::GFx::AS2::Value::~Value);
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
}

// File Line: 944
// RVA: 0x6E07C0
void __fastcall Scaleform::GFx::AS2::RectangleCtorFunction::CreateNewObject(
        Scaleform::GFx::AS2::RectangleCtorFunction *this,
        Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::RectangleObject *v3; // rax

  v3 = (Scaleform::GFx::AS2::RectangleObject *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::RectangleCtorFunction *, __int64))penv->StringContext.pContext->pHeap->vfptr->Alloc)(
                                                 this,
                                                 96i64);
  if ( v3 )
    Scaleform::GFx::AS2::RectangleObject::RectangleObject(v3, penv);
}

// File Line: 949
// RVA: 0x70E830
Scaleform::GFx::AS2::FunctionRef *__fastcall Scaleform::GFx::AS2::RectangleCtorFunction::Register(
        Scaleform::GFx::AS2::FunctionRef *result,
        Scaleform::GFx::AS2::GlobalContext *pgc)
{
  Scaleform::GFx::AS2::Object *v4; // rax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *pObject; // rcx
  Scaleform::GFx::AS2::FunctionObject *v6; // rbx
  Scaleform::GFx::AS2::Object *Prototype; // r15
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::RectangleProto *v9; // rbx
  Scaleform::GFx::AS2::Object *v10; // rax
  Scaleform::GFx::AS2::Object *v11; // rax
  Scaleform::GFx::AS2::Object *v12; // rbx
  Scaleform::GFx::ASStringNode *Function; // rax
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // rdx
  unsigned int v15; // eax
  Scaleform::GFx::AS2::ASStringContext psc; // [rsp+40h] [rbp-38h] BYREF
  Scaleform::GFx::AS2::Value v18; // [rsp+50h] [rbp-28h] BYREF
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
    v6[1].Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)Scaleform::GFx::AS2::RectangleCtorFunction::GlobalCtor;
    Prototype = Scaleform::GFx::AS2::GlobalContext::GetPrototype(psc.pContext, ASBuiltin_Function);
    if ( !v6->pProto.pObject )
    {
      LOBYTE(objproto.pObject) = 3;
      v18.T.Type = 10;
      v6->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr->SetMemberRaw(
        &v6->Scaleform::GFx::AS2::ObjectInterface,
        &psc,
        (Scaleform::GFx::ASString *)&psc.pContext->pMovieRoot->pASMovieRoot.pObject[23].pMovieImpl,
        &v18,
        (Scaleform::GFx::AS2::PropFlags *)&objproto);
      if ( v18.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v18);
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
    v6->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::RectangleCtorFunction::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
    v6->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::RectangleCtorFunction::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  }
  else
  {
    v6 = 0i64;
  }
  result->Flags = 0;
  result->Function = v6;
  result->pLocalFrame = 0i64;
  objproto.pObject = (Scaleform::GFx::AS2::Object *)pgc->pHeap;
  v9 = (Scaleform::GFx::AS2::RectangleProto *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::RefCountBaseGC<323> *, __int64, _QWORD))objproto.pObject->vfptr[3].Finalize_GC)(
                                                pObject,
                                                160i64,
                                                0i64);
  pHeap = (Scaleform::MemoryHeap *)v9;
  if ( v9 )
  {
    v10 = Scaleform::GFx::AS2::GlobalContext::GetPrototype(pgc, ASBuiltin_Object);
    Scaleform::GFx::AS2::RectangleProto::RectangleProto(v9, &psc, v10, result);
    v12 = v11;
  }
  else
  {
    v12 = 0i64;
  }
  pHeap = (Scaleform::MemoryHeap *)v12;
  p_objproto = &objproto;
  if ( v12 )
    v12->RefCount = (v12->RefCount + 1) & 0x8FFFFFFF;
  objproto.pObject = v12;
  Scaleform::GFx::AS2::GlobalContext::SetPrototype(
    pgc,
    ASBuiltin_Rectangle,
    (Scaleform::Ptr<Scaleform::GFx::AS2::Object>)&objproto);
  v18.T.Type = 8;
  v18.V.FunctionValue.Flags = 0;
  Function = (Scaleform::GFx::ASStringNode *)result->Function;
  v18.V.pStringNode = Function;
  if ( Function )
  {
    ++Function->RefCount;
    Function->RefCount &= 0x8FFFFFFF;
  }
  v18.V.FunctionValue.pLocalFrame = 0i64;
  pLocalFrame = result->pLocalFrame;
  if ( pLocalFrame )
    Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(&v18.V.FunctionValue, pLocalFrame, result->Flags & 1);
  LOBYTE(objproto.pObject) = 0;
  pgc->FlashGeomPackage->vfptr->SetMemberRaw(
    &pgc->FlashGeomPackage->Scaleform::GFx::AS2::ObjectInterface,
    &psc,
    (Scaleform::GFx::ASString *)&pgc->pMovieRoot->pASMovieRoot.pObject[10].AVMVersion,
    &v18,
    (Scaleform::GFx::AS2::PropFlags *)&objproto);
  if ( v18.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v18);
  if ( v12 )
  {
    v15 = v12->RefCount;
    if ( (v15 & 0x3FFFFFF) != 0 )
    {
      v12->RefCount = v15 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v12);
    }
  }
  return result;
}

