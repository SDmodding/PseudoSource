// File Line: 16
// RVA: 0xCF2B60
void __fastcall hkpBvShape::hkpBvShape(hkpBvShape *this, hkpShape *boundingVolumeShape, hkpShape *childShape)
{
  hkpBvShape *v3; // rbx

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  *(_DWORD *)&this->m_type.m_storage = 1054;
  this->m_userData = 0i64;
  this->m_boundingVolumeShape = boundingVolumeShape;
  v3 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkpBvShape::`vftable;
  this->m_childShape.m_childShape = childShape;
  this->m_childShape.vfptr = (hkpShapeContainerVtbl *)&hkpSingleShapeContainer::`vftable;
  hkReferencedObject::addReference((hkReferencedObject *)&childShape->vfptr);
  hkReferencedObject::addReference((hkReferencedObject *)&v3->m_boundingVolumeShape->vfptr);
}

// File Line: 31
// RVA: 0xCF2BC0
void __fastcall hkpBvShape::hkpBvShape(hkpBvShape *this, hkFinishLoadedObjectFlag flag)
{
  hkpBvShape *v2; // rbx

  v2 = this;
  hkpShape::hkpShape((hkpShape *)&this->vfptr, flag);
  v2->vfptr = (hkBaseObjectVtbl *)&hkpBvShape::`vftable;
  v2->m_childShape.vfptr = (hkpShapeContainerVtbl *)&hkpSingleShapeContainer::`vftable;
  v2->m_type.m_storage = 30;
}

// File Line: 39
// RVA: 0xCF2C00
void __fastcall hkpBvShape::~hkpBvShape(hkpBvShape *this)
{
  hkpBvShape *v1; // rbx
  hkReferencedObject *v2; // rcx

  v1 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkpBvShape::`vftable;
  hkReferencedObject::removeReference((hkReferencedObject *)&this->m_boundingVolumeShape->vfptr);
  v2 = (hkReferencedObject *)&v1->m_childShape.m_childShape->vfptr;
  v1->m_childShape.vfptr = (hkpShapeContainerVtbl *)&hkpSingleShapeContainer::`vftable;
  if ( v2 )
    hkReferencedObject::removeReference(v2);
  v1->m_childShape.vfptr = (hkpShapeContainerVtbl *)&hkpShapeContainer::`vftable;
  v1->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 46
// RVA: 0xCF2C70
void __usercall hkpBvShape::getAabb(hkpBvShape *this@<rcx>, hkTransformf *localToWorld@<rdx>, float tolerance@<xmm2>, hkAabb *out@<r9>, __int64 a5@<r8>)
{
  ((void (__fastcall *)(hkpShape *, hkTransformf *, __int64, hkAabb *))this->m_boundingVolumeShape->vfptr[2].__vecDelDtor)(
    this->m_boundingVolumeShape,
    localToWorld,
    a5,
    out);
}

// File Line: 51
// RVA: 0xCF2C90
hkBool *__fastcall hkpBvShape::castRay(hkpBvShape *this, hkBool *result, hkpShapeRayCastInput *input, hkpShapeRayCastOutput *results)
{
  hkpBvShape *v4; // rbp
  hkpShapeRayCastOutput *v5; // rbx
  hkpShapeRayCastInput *v6; // rsi
  hkBool *v7; // rdi
  _QWORD *v8; // rax
  _QWORD *v9; // rcx
  _QWORD *v10; // r9
  unsigned __int64 v11; // rax
  signed __int64 v12; // rcx
  _QWORD *v13; // r8
  _QWORD *v14; // rcx
  unsigned __int64 v15; // rax
  signed __int64 v16; // rcx

  v4 = this;
  v5 = results;
  v6 = input;
  v7 = result;
  v8 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = (_QWORD *)v8[1];
  v10 = v8;
  if ( (unsigned __int64)v9 < v8[3] )
  {
    *v9 = "TtrcBvShape";
    v11 = __rdtsc();
    v12 = (signed __int64)(v9 + 2);
    *(_DWORD *)(v12 - 8) = v11;
    v10[1] = v12;
  }
  ++v5->m_shapeKeyIndex;
  ((void (__fastcall *)(hkpShape *, hkBool *, hkpShapeRayCastInput *, hkpShapeRayCastOutput *))v4->m_childShape.m_childShape->vfptr[2].__first_virtual_table_function__)(
    v4->m_childShape.m_childShape,
    v7,
    v6,
    v5);
  --v5->m_shapeKeyIndex;
  if ( v7->m_bool )
    v5->m_shapeKeys[v5->m_shapeKeyIndex] = 0;
  v13 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v14 = (_QWORD *)v13[1];
  if ( (unsigned __int64)v14 < v13[3] )
  {
    *v14 = "Et";
    v15 = __rdtsc();
    v16 = (signed __int64)(v14 + 2);
    *(_DWORD *)(v16 - 8) = v15;
    v13[1] = v16;
  }
  return v7;
}

// File Line: 72
// RVA: 0xCF2D70
void __fastcall hkpBvShape::castRayWithCollector(hkpBvShape *this, hkpShapeRayCastInput *input, hkpCdBody *cdBody, hkpRayHitCollector *collector)
{
  hkpBvShape *v4; // rbp
  hkpRayHitCollector *v5; // rdi
  hkpCdBody *v6; // rbx
  hkpShapeRayCastInput *v7; // rsi
  _QWORD *v8; // rax
  _QWORD *v9; // rcx
  _QWORD *v10; // r10
  unsigned __int64 v11; // rax
  signed __int64 v12; // rcx
  __int64 v13; // rax
  __int64 v14; // rcx
  _QWORD *v15; // r8
  _QWORD *v16; // rcx
  unsigned __int64 v17; // rax
  signed __int64 v18; // rcx
  __int64 v19; // [rsp+20h] [rbp-28h]
  int v20; // [rsp+28h] [rbp-20h]
  __int64 v21; // [rsp+30h] [rbp-18h]
  hkpCdBody *v22; // [rsp+38h] [rbp-10h]

  v4 = this;
  v5 = collector;
  v6 = cdBody;
  v7 = input;
  v8 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = (_QWORD *)v8[1];
  v10 = v8;
  if ( (unsigned __int64)v9 < v8[3] )
  {
    *v9 = "TtrcBvShape";
    v11 = __rdtsc();
    v12 = (signed __int64)(v9 + 2);
    *(_DWORD *)(v12 - 8) = v11;
    v10[1] = v12;
  }
  v13 = (__int64)v6->m_motion;
  v14 = (__int64)v4->m_childShape.m_childShape;
  v22 = v6;
  v21 = v13;
  v19 = v14;
  v20 = 0;
  (*(void (__fastcall **)(__int64, hkpShapeRayCastInput *, __int64 *, hkpRayHitCollector *, __int64, _QWORD, __int64, hkpCdBody *))(*(_QWORD *)v14 + 48i64))(
    v14,
    v7,
    &v19,
    v5,
    v14,
    *(_QWORD *)&v20,
    v13,
    v6);
  v15 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v16 = (_QWORD *)v15[1];
  if ( (unsigned __int64)v16 < v15[3] )
  {
    *v16 = "Et";
    v17 = __rdtsc();
    v18 = (signed __int64)(v16 + 2);
    *(_DWORD *)(v18 - 8) = v17;
    v15[1] = v18;
  }
}

// File Line: 92
// RVA: 0xCF2C60
hkpSingleShapeContainer *__fastcall hkpBvShape::getContainer(hkpBvShape *this)
{
  return &this->m_childShape;
}

