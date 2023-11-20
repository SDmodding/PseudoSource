// File Line: 46
// RVA: 0xAC0E0
void __fastcall UFG::RayCastData::Init(UFG::RayCastData *this, UFG::qVector3 *rayStart, UFG::qVector3 *rayEnd, unsigned int collisionFilter)
{
  __m128 v4; // xmm0
  __m128 v5; // xmm3
  __m128 v6; // xmm2

  this->mInput.m_from.m_quad = _mm_unpacklo_ps(
                                 _mm_unpacklo_ps((__m128)LODWORD(rayStart->x), (__m128)LODWORD(rayStart->z)),
                                 _mm_unpacklo_ps((__m128)LODWORD(rayStart->y), (__m128)0i64));
  v4 = (__m128)LODWORD(rayEnd->z);
  v5 = (__m128)LODWORD(rayEnd->x);
  v6 = _mm_unpacklo_ps((__m128)LODWORD(rayEnd->y), (__m128)0i64);
  this->mInput.m_filterInfo = collisionFilter;
  this->mInput.m_to.m_quad = _mm_unpacklo_ps(_mm_unpacklo_ps(v5, v4), v6);
  this->mInput.m_enableShapeCollectionFilter.m_bool = 1;
  this->hit = 0;
  this->mHavokRigidBody = 0i64;
  this->mHavokPhantom = 0i64;
}

// File Line: 59
// RVA: 0xAC0B0
void __fastcall UFG::RayCastData::Init(UFG::RayCastData *this, hkVector4f *rayStart, hkVector4f *rayEnd, unsigned int collisionFilter)
{
  __m128 v4; // xmm1

  this->mInput.m_from = (hkVector4f)rayStart->m_quad;
  v4 = rayEnd->m_quad;
  this->mInput.m_filterInfo = collisionFilter;
  this->mInput.m_to.m_quad = v4;
  this->mInput.m_enableShapeCollectionFilter.m_bool = 1;
  this->hit = 0;
  this->mHavokRigidBody = 0i64;
  this->mHavokPhantom = 0i64;
}

// File Line: 92
// RVA: 0x99E30
void __fastcall UFG::ShapeCasterCollector::ShapeCasterCollector(UFG::ShapeCasterCollector *this, float radius, unsigned int collisionFilter, UFG::ShapeCasterCollector::PhantomBehaviour simpleOrCached)
{
  UFG::ShapeCasterCollector::PhantomBehaviour v4; // esi
  unsigned int v5; // ebp
  UFG::ShapeCasterCollector *v6; // rdi
  UFG::qList<UFG::ShapeCasterCollector::HitInfo,UFG::ShapeCasterCollector::HitInfo,1,0> *v7; // ST28_8
  signed __int64 v8; // rbx
  char v9; // dl
  __int64 v10; // rax
  char v11; // cl
  _QWORD **v12; // rax
  hkpSphereShape *v13; // rax
  hkpShape *v14; // rax
  char v15; // al

  v4 = simpleOrCached;
  v5 = collisionFilter;
  v6 = this;
  this->vfptr = (UFG::ShapeCasterCollectorVtbl *)&UFG::ShapeCasterCollector::`vftable';
  v7 = &this->mHitList;
  v7->mNode.mPrev = &v7->mNode;
  v7->mNode.mNext = &v7->mNode;
  this->mPhantom = 0i64;
  this->mShape = 0i64;
  this->mRadius = radius;
  v8 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
  v9 = ++*(_BYTE *)(v8 + 80);
  v10 = v9;
  *(_DWORD *)(v8 + 4 * v10) = 3;
  *(_QWORD *)(v8 + 8 * v10 + 16) = "hkpSphereShape";
  *(_QWORD *)(v8 + 8 * v10 + 48) = 0i64;
  v11 = *(_BYTE *)(v8 + 81);
  if ( v9 > v11 )
    v11 = v9;
  *(_BYTE *)(v8 + 0x51) = v11;
  v12 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v13 = (hkpSphereShape *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v12[11] + 8i64))(v12[11], 56i64);
  if ( v13 )
    hkpSphereShape::hkpSphereShape(v13, radius);
  else
    v14 = 0i64;
  v6->mShape = v14;
  v15 = *(_BYTE *)(v8 + 80);
  if ( v15 > 0 )
  {
    *(_BYTE *)(v8 + 80) = v15 - 1;
  }
  else
  {
    *(_BYTE *)(v8 + 80) = 0;
    *(_DWORD *)v8 = 3;
    *(_QWORD *)(v8 + 16) = 0i64;
    *(_QWORD *)(v8 + 48) = 0i64;
  }
  UFG::ShapeCasterCollector::ShapeCasterH(v6, v5, v4);
}

// File Line: 153
// RVA: 0xB28B0
void __fastcall UFG::ShapeCasterCollector::ShapeCasterH(UFG::ShapeCasterCollector *this, unsigned int collisionFilter, UFG::ShapeCasterCollector::PhantomBehaviour simpleOrCached)
{
  unsigned int v3; // ebp
  UFG::ShapeCasterCollector *v4; // rsi
  _QWORD *v5; // rax
  signed __int64 v6; // rbx
  char v7; // dl
  __int64 v8; // rax
  char v9; // cl
  _QWORD **v10; // rax
  hkpSimpleShapePhantom *v11; // rax
  hkpShapePhantom *v12; // rax
  char v13; // dl
  __int64 v14; // rax
  char v15; // cl
  _QWORD **v16; // rax
  hkpCachingShapePhantom *v17; // rax
  char v18; // al
  hkTransformf transform; // [rsp+30h] [rbp-48h]

  v3 = collisionFilter;
  v4 = this;
  transform.m_rotation.m_col0 = (hkVector4f)::transform.m_quad;
  transform.m_rotation.m_col1 = (hkVector4f)direction.m_quad;
  transform.m_rotation.m_col2 = (hkVector4f)stru_141A71280.m_quad;
  transform.m_translation = 0i64;
  v5 = NtCurrentTeb()->Reserved1[11];
  if ( simpleOrCached )
  {
    v6 = v5[tls_index] + 16i64;
    v13 = ++*(_BYTE *)(v6 + 80);
    v14 = v13;
    *(_DWORD *)(v6 + 4 * v14) = 3;
    *(_QWORD *)(v6 + 8 * v14 + 16) = "hkpCachingShapePhantom";
    *(_QWORD *)(v6 + 8 * v14 + 48) = 0i64;
    v15 = *(_BYTE *)(v6 + 81);
    if ( v13 > v15 )
      v15 = v13;
    *(_BYTE *)(v6 + 81) = v15;
    v16 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v17 = (hkpCachingShapePhantom *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v16[11] + 8i64))(
                                      v16[11],
                                      448i64);
    if ( v17 )
      hkpCachingShapePhantom::hkpCachingShapePhantom(v17, v4->mShape, &transform, v3);
    else
      v12 = 0i64;
  }
  else
  {
    v6 = v5[tls_index] + 16i64;
    v7 = ++*(_BYTE *)(v6 + 80);
    v8 = v7;
    *(_DWORD *)(v6 + 4 * v8) = 3;
    *(_QWORD *)(v6 + 8 * v8 + 16) = "hkpSimpleShapePhantom";
    *(_QWORD *)(v6 + 8 * v8 + 48) = 0i64;
    v9 = *(_BYTE *)(v6 + 81);
    if ( v7 > v9 )
      v9 = v7;
    *(_BYTE *)(v6 + 81) = v9;
    v10 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v11 = (hkpSimpleShapePhantom *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v10[11] + 8i64))(
                                     v10[11],
                                     448i64);
    if ( v11 )
      hkpSimpleShapePhantom::hkpSimpleShapePhantom(v11, v4->mShape, &transform, v3);
    else
      v12 = 0i64;
  }
  v4->mPhantom = v12;
  v18 = *(_BYTE *)(v6 + 80);
  if ( v18 > 0 )
  {
    *(_BYTE *)(v6 + 80) = v18 - 1;
  }
  else
  {
    *(_BYTE *)(v6 + 80) = 0;
    *(_QWORD *)(v6 + 48) = 0i64;
    *(_QWORD *)(v6 + 16) = 0i64;
    *(_DWORD *)v6 = 3;
  }
  hkReferencedObject::removeReference((hkReferencedObject *)&v4->mShape->vfptr);
}

// File Line: 179
// RVA: 0x9D2D0
void __fastcall UFG::ShapeCasterCollector::~ShapeCasterCollector(UFG::ShapeCasterCollector *this)
{
  UFG::ShapeCasterCollector *v1; // rbx
  hkpShapePhantom *v2; // rcx
  UFG::qList<UFG::qReflectField,UFG::qReflectField,1,0> *v3; // rbx
  UFG::qNode<UFG::qReflectField,UFG::qReflectField> *v4; // rcx
  UFG::qNode<UFG::qReflectField,UFG::qReflectField> *v5; // rax

  v1 = this;
  this->vfptr = (UFG::ShapeCasterCollectorVtbl *)&UFG::ShapeCasterCollector::`vftable';
  v2 = this->mPhantom;
  if ( v2 )
  {
    if ( v2->m_world )
      hkpWorld::removePhantom(v2->m_world, (hkpPhantom *)&v2->vfptr);
    hkReferencedObject::removeReference((hkReferencedObject *)&v1->mPhantom->vfptr);
    v1->mPhantom = 0i64;
  }
  v3 = (UFG::qList<UFG::qReflectField,UFG::qReflectField,1,0> *)&v1->mHitList;
  UFG::qList<UFG::FractureConnectivity::Connection,UFG::FractureConnectivity::Connection,1,0>::DeleteNodes(v3);
  UFG::qList<UFG::FractureConnectivity::Connection,UFG::FractureConnectivity::Connection,1,0>::DeleteNodes(v3);
  v4 = v3->mNode.mPrev;
  v5 = v3->mNode.mNext;
  v4->mNext = v5;
  v5->mPrev = v4;
  v3->mNode.mPrev = &v3->mNode;
  v3->mNode.mNext = &v3->mNode;
}

// File Line: 196
// RVA: 0xA0750
void __fastcall UFG::ShapeCasterCollector::AddHit(UFG::ShapeCasterCollector *this, hkpRootCdPoint *pt, bool oneHitPerRigidBody)
{
  hkpRootCdPoint *v3; // r14
  UFG::ShapeCasterCollector *v4; // r13
  hkpCollidable *v5; // rax
  hkpShape *v6; // rbp
  __int64 v7; // rsi
  hkpWorldObject *v8; // rdi
  signed int v9; // er15
  hkpCollidable *v10; // rax
  UFG::qNode<UFG::ShapeCasterCollector::HitInfo,UFG::ShapeCasterCollector::HitInfo> *v11; // rax
  UFG::qList<UFG::ShapeCasterCollector::HitInfo,UFG::ShapeCasterCollector::HitInfo,1,0> *v12; // rcx
  char *v13; // rax
  char *v14; // rbx
  float v15; // xmm0_4
  float v16; // xmm1_4
  float v17; // xmm0_4
  float v18; // xmm1_4
  unsigned __int64 v19; // r8
  signed int v20; // edx
  signed __int64 v21; // rcx
  __int64 v22; // rax
  __int64 v23; // rcx
  UFG::qNode<UFG::ShapeCasterCollector::HitInfo,UFG::ShapeCasterCollector::HitInfo> *v24; // rcx
  unsigned __int64 v25; // rax
  __int64 v26; // rax

  v3 = pt;
  v4 = this;
  v5 = pt->m_rootCollidableA;
  v6 = v5->m_shape;
  v7 = 0i64;
  if ( v5->m_broadPhaseHandle.m_type == 1 )
    v8 = (hkpWorldObject *)((char *)v5 + v5->m_ownerOffset);
  else
    v8 = 0i64;
  v9 = pt->m_shapeKeyA;
  if ( v8
    || ((v10 = pt->m_rootCollidableB, v10->m_broadPhaseHandle.m_type != 1) ? (v8 = 0i64) : (v8 = (hkpWorldObject *)((char *)v10 + v10->m_ownerOffset)),
        v6 = v10->m_shape,
        v9 = pt->m_shapeKeyB,
        v8) )
  {
    if ( oneHitPerRigidBody
      && (v11 = this->mHitList.mNode.mNext,
          v12 = &this->mHitList,
          v11 != (UFG::qNode<UFG::ShapeCasterCollector::HitInfo,UFG::ShapeCasterCollector::HitInfo> *)v12) )
    {
      while ( (hkpWorldObject *)v11[2].mNext != v8 )
      {
        v11 = v11->mNext;
        if ( v11 == (UFG::qNode<UFG::ShapeCasterCollector::HitInfo,UFG::ShapeCasterCollector::HitInfo> *)v12 )
          goto LABEL_13;
      }
    }
    else
    {
LABEL_13:
      v13 = UFG::qMalloc(0x68ui64, "HitInfo", 0i64);
      v14 = v13;
      if ( v13 )
      {
        *(_QWORD *)v13 = v13;
        *((_QWORD *)v13 + 1) = v13;
      }
      else
      {
        v14 = 0i64;
      }
      v15 = v3->m_contact.m_position.m_quad.m128_f32[1];
      v16 = v3->m_contact.m_position.m_quad.m128_f32[2];
      *((_DWORD *)v14 + 4) = v3->m_contact.m_position.m_quad.m128_i32[0];
      *((float *)v14 + 5) = v15;
      *((float *)v14 + 6) = v16;
      v17 = v3->m_contact.m_separatingNormal.m_quad.m128_f32[1];
      v18 = v3->m_contact.m_separatingNormal.m_quad.m128_f32[2];
      *((_DWORD *)v14 + 7) = LODWORD(v3->m_contact.m_separatingNormal.m_quad.m128_f32[0]);
      *((float *)v14 + 8) = v17;
      *((float *)v14 + 9) = v18;
      *((_QWORD *)v14 + 5) = v8;
      *((_QWORD *)v14 + 6) = v3->m_rootCollidableA;
      *((_DWORD *)v14 + 14) = v3->m_shapeKeyA;
      *((_QWORD *)v14 + 8) = v3->m_rootCollidableB;
      *((_DWORD *)v14 + 18) = v3->m_shapeKeyB;
      *((_QWORD *)v14 + 10) = 0i64;
      *((_QWORD *)v14 + 11) = UFG::PhysicsPropertyManager::GetObjectPropertiesHandleUid(v8, v6, v9);
      if ( v9 != -1
        && v6->m_type.m_storage == 9
        && (v19 = v6[2].m_userData) != 0
        && !((*(_BYTE *)(v19 + 41) - 1) & 0xFD)
        && ((v20 = (v9 & 0x7FFFFFFFu) >> (32 - *(_BYTE *)(v19 + 232)), v9 < 0) ? (v21 = *(_QWORD *)(v19 + 256)
                                                                                      + 80i64 * v20) : (v21 = *(_QWORD *)(v19 + 240) + 144i64 * v20),
            (v22 = *(_QWORD *)(v21 + 16)) != 0) )
      {
        v23 = *(_QWORD *)(v22 + 8);
      }
      else
      {
        v23 = 0i64;
      }
      *((_QWORD *)v14 + 12) = v23;
      v24 = v4->mHitList.mNode.mNext;
      v4->mHitList.mNode.mNext = (UFG::qNode<UFG::ShapeCasterCollector::HitInfo,UFG::ShapeCasterCollector::HitInfo> *)v14;
      *(_QWORD *)v14 = (char *)v4 + 8;
      *((_QWORD *)v14 + 1) = v24;
      v24->mPrev = (UFG::qNode<UFG::ShapeCasterCollector::HitInfo,UFG::ShapeCasterCollector::HitInfo> *)v14;
      v25 = v8->m_userData;
      if ( v25 )
      {
        v26 = *(_QWORD *)(v25 + 24);
        if ( v26 )
          v7 = *(_QWORD *)(v26 + 40);
        *((_QWORD *)v14 + 10) = v7;
      }
    }
  }
}

// File Line: 262
// RVA: 0xA9800
__int64 __fastcall UFG::ShapeCasterCollector::GetCollisionFilter(UFG::ShapeCasterCollector *this)
{
  return this->mPhantom->m_collidable.m_broadPhaseHandle.m_collisionFilterInfo;
}

// File Line: 276
// RVA: 0x9E070
UFG::AsyncShapeCasterCollector *__fastcall UFG::AsyncShapeCasterCollector::operator=(UFG::AsyncShapeCasterCollector *this, UFG::AsyncShapeCasterCollector *rhs)
{
  UFG::AsyncShapeCasterCollector *v2; // rbx
  hkpShape *v3; // rcx
  UFG::AsyncShapeCasterCollector *v4; // rdi
  hkReferencedObject *v5; // rcx
  hkReferencedObject *v6; // rcx
  void (__fastcall *v7)(UFG::AsyncShapeCasterCollector *); // rax

  v2 = this;
  v3 = this->mShape;
  v4 = rhs;
  if ( v3 )
    hkReferencedObject::removeReference((hkReferencedObject *)&v3->vfptr);
  v5 = (hkReferencedObject *)&v2->mPhantom->vfptr;
  v2->mShape = v4->mShape;
  if ( v5 )
    hkReferencedObject::removeReference(v5);
  v6 = (hkReferencedObject *)&v4->mPhantom->vfptr;
  v2->mPhantom = (hkpShapePhantom *)v6;
  hkReferencedObject::addReference(v6);
  v2->mRadius = v4->mRadius;
  v2->m_from = v4->m_from;
  v2->m_to = v4->m_to;
  v7 = v4->mShapecastCallback;
  v2->mHit = 0;
  v2->mShapecastCallback = v7;
  return v2;
}

