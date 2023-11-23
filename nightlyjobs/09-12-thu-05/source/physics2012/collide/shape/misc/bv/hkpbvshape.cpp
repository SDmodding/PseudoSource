// File Line: 16
// RVA: 0xCF2B60
void __fastcall hkpBvShape::hkpBvShape(hkpBvShape *this, hkpShape *boundingVolumeShape, hkpShape *childShape)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  *(_DWORD *)&this->m_type.m_storage = 1054;
  this->m_userData = 0i64;
  this->m_boundingVolumeShape = boundingVolumeShape;
  this->vfptr = (hkBaseObjectVtbl *)&hkpBvShape::`vftable;
  this->m_childShape.m_childShape = childShape;
  this->m_childShape.vfptr = (hkpShapeContainerVtbl *)&hkpSingleShapeContainer::`vftable;
  hkReferencedObject::addReference(childShape);
  hkReferencedObject::addReference(this->m_boundingVolumeShape);
}

// File Line: 31
// RVA: 0xCF2BC0
void __fastcall hkpBvShape::hkpBvShape(hkpBvShape *this, hkFinishLoadedObjectFlag flag)
{
  hkpShape::hkpShape(this, flag);
  this->vfptr = (hkBaseObjectVtbl *)&hkpBvShape::`vftable;
  this->m_childShape.vfptr = (hkpShapeContainerVtbl *)&hkpSingleShapeContainer::`vftable;
  this->m_type.m_storage = 30;
}

// File Line: 39
// RVA: 0xCF2C00
void __fastcall hkpBvShape::~hkpBvShape(hkpBvShape *this)
{
  hkpShape *m_childShape; // rcx

  this->vfptr = (hkBaseObjectVtbl *)&hkpBvShape::`vftable;
  hkReferencedObject::removeReference(this->m_boundingVolumeShape);
  m_childShape = this->m_childShape.m_childShape;
  this->m_childShape.vfptr = (hkpShapeContainerVtbl *)&hkpSingleShapeContainer::`vftable;
  if ( m_childShape )
    hkReferencedObject::removeReference(m_childShape);
  this->m_childShape.vfptr = (hkpShapeContainerVtbl *)&hkpShapeContainer::`vftable;
  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 46
// RVA: 0xCF2C70
void __fastcall hkpBvShape::getAabb(hkpBvShape *this, hkTransformf *localToWorld, float tolerance, hkAabb *out)
{
  __int64 v4; // r8

  ((void (__fastcall *)(hkpShape *, hkTransformf *, __int64, hkAabb *))this->m_boundingVolumeShape->vfptr[2].__vecDelDtor)(
    this->m_boundingVolumeShape,
    localToWorld,
    v4,
    out);
}

// File Line: 51
// RVA: 0xCF2C90
hkBool *__fastcall hkpBvShape::castRay(
        hkpBvShape *this,
        hkBool *result,
        hkpShapeRayCastInput *input,
        hkpShapeRayCastOutput *results)
{
  _QWORD *Value; // rax
  _QWORD *v9; // rcx
  _QWORD *v10; // r9
  unsigned __int64 v11; // rax
  _QWORD *v12; // rcx
  _QWORD *v13; // r8
  _QWORD *v14; // rcx
  unsigned __int64 v15; // rax
  _QWORD *v16; // rcx

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = (_QWORD *)Value[1];
  v10 = Value;
  if ( (unsigned __int64)v9 < Value[3] )
  {
    *v9 = "TtrcBvShape";
    v11 = __rdtsc();
    v12 = v9 + 2;
    *((_DWORD *)v12 - 2) = v11;
    v10[1] = v12;
  }
  ++results->m_shapeKeyIndex;
  ((void (__fastcall *)(hkpShape *, hkBool *, hkpShapeRayCastInput *, hkpShapeRayCastOutput *))this->m_childShape.m_childShape->vfptr[2].__first_virtual_table_function__)(
    this->m_childShape.m_childShape,
    result,
    input,
    results);
  --results->m_shapeKeyIndex;
  if ( result->m_bool )
    results->m_shapeKeys[results->m_shapeKeyIndex] = 0;
  v13 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v14 = (_QWORD *)v13[1];
  if ( (unsigned __int64)v14 < v13[3] )
  {
    *v14 = "Et";
    v15 = __rdtsc();
    v16 = v14 + 2;
    *((_DWORD *)v16 - 2) = v15;
    v13[1] = v16;
  }
  return result;
}

// File Line: 72
// RVA: 0xCF2D70
void __fastcall hkpBvShape::castRayWithCollector(
        hkpBvShape *this,
        hkpShapeRayCastInput *input,
        hkpCdBody *cdBody,
        hkpRayHitCollector *collector)
{
  _QWORD *Value; // rax
  _QWORD *v9; // rcx
  _QWORD *v10; // r10
  unsigned __int64 v11; // rax
  _QWORD *v12; // rcx
  const void *m_motion; // rax
  hkpShape *m_childShape; // rcx
  _QWORD *v15; // r8
  _QWORD *v16; // rcx
  unsigned __int64 v17; // rax
  _QWORD *v18; // rcx
  hkpShape *v19; // [rsp+20h] [rbp-28h] BYREF
  int v20; // [rsp+28h] [rbp-20h]
  const void *v21; // [rsp+30h] [rbp-18h]
  hkpCdBody *v22; // [rsp+38h] [rbp-10h]

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = (_QWORD *)Value[1];
  v10 = Value;
  if ( (unsigned __int64)v9 < Value[3] )
  {
    *v9 = "TtrcBvShape";
    v11 = __rdtsc();
    v12 = v9 + 2;
    *((_DWORD *)v12 - 2) = v11;
    v10[1] = v12;
  }
  m_motion = cdBody->m_motion;
  m_childShape = this->m_childShape.m_childShape;
  v22 = cdBody;
  v21 = m_motion;
  v19 = m_childShape;
  v20 = 0;
  ((void (__fastcall *)(hkpShape *, hkpShapeRayCastInput *, hkpShape **, hkpRayHitCollector *))m_childShape->vfptr[3].__vecDelDtor)(
    m_childShape,
    input,
    &v19,
    collector);
  v15 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v16 = (_QWORD *)v15[1];
  if ( (unsigned __int64)v16 < v15[3] )
  {
    *v16 = "Et";
    v17 = __rdtsc();
    v18 = v16 + 2;
    *((_DWORD *)v18 - 2) = v17;
    v15[1] = v18;
  }
}

// File Line: 92
// RVA: 0xCF2C60
hkpSingleShapeContainer *__fastcall hkpBvShape::getContainer(hkpBvShape *this)
{
  return &this->m_childShape;
}

