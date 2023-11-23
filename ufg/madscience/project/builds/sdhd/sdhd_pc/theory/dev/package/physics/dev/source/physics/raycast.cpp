// File Line: 46
// RVA: 0xAC0E0
void __fastcall UFG::RayCastData::Init(
        UFG::RayCastData *this,
        UFG::qVector3 *rayStart,
        UFG::qVector3 *rayEnd,
        unsigned int collisionFilter)
{
  __m128 z_low; // xmm0
  __m128 x_low; // xmm3
  __m128 v6; // xmm2

  this->mInput.m_from.m_quad = _mm_unpacklo_ps(
                                 _mm_unpacklo_ps((__m128)LODWORD(rayStart->x), (__m128)LODWORD(rayStart->z)),
                                 _mm_unpacklo_ps((__m128)LODWORD(rayStart->y), (__m128)0i64));
  z_low = (__m128)LODWORD(rayEnd->z);
  x_low = (__m128)LODWORD(rayEnd->x);
  v6 = _mm_unpacklo_ps((__m128)LODWORD(rayEnd->y), (__m128)0i64);
  this->mInput.m_filterInfo = collisionFilter;
  this->mInput.m_to.m_quad = _mm_unpacklo_ps(_mm_unpacklo_ps(x_low, z_low), v6);
  this->mInput.m_enableShapeCollectionFilter.m_bool = 1;
  this->hit = 0;
  this->mHavokRigidBody = 0i64;
  this->mHavokPhantom = 0i64;
}

// File Line: 59
// RVA: 0xAC0B0
void __fastcall UFG::RayCastData::Init(
        UFG::RayCastData *this,
        hkVector4f *rayStart,
        hkVector4f *rayEnd,
        unsigned int collisionFilter)
{
  __m128 m_quad; // xmm1

  this->mInput.m_from = (hkVector4f)rayStart->m_quad;
  m_quad = rayEnd->m_quad;
  this->mInput.m_filterInfo = collisionFilter;
  this->mInput.m_to.m_quad = m_quad;
  this->mInput.m_enableShapeCollectionFilter.m_bool = 1;
  this->hit = 0;
  this->mHavokRigidBody = 0i64;
  this->mHavokPhantom = 0i64;
}

// File Line: 92
// RVA: 0x99E30
void __fastcall UFG::ShapeCasterCollector::ShapeCasterCollector(
        UFG::ShapeCasterCollector *this,
        float radius,
        unsigned int collisionFilter,
        UFG::ShapeCasterCollector::PhantomBehaviour simpleOrCached)
{
  __int64 v7; // rbx
  char v8; // dl
  char v9; // cl
  _QWORD **Value; // rax
  hkpSphereShape *v11; // rax
  hkpShape *v12; // rax
  char v13; // al

  this->vfptr = (UFG::ShapeCasterCollectorVtbl *)&UFG::ShapeCasterCollector::`vftable;
  this->mHitList.mNode.mPrev = &this->mHitList.mNode;
  this->mHitList.mNode.mNext = &this->mHitList.mNode;
  this->mPhantom = 0i64;
  this->mShape = 0i64;
  this->mRadius = radius;
  v7 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
  v8 = ++*(_BYTE *)(v7 + 80);
  *(_DWORD *)(v7 + 4i64 * v8) = 3;
  *(_QWORD *)(v7 + 8i64 * v8 + 16) = "hkpSphereShape";
  *(_QWORD *)(v7 + 8i64 * v8 + 48) = 0i64;
  v9 = *(_BYTE *)(v7 + 81);
  if ( v8 > v9 )
    v9 = v8;
  *(_BYTE *)(v7 + 0x51) = v9;
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v11 = (hkpSphereShape *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 56i64);
  if ( v11 )
    hkpSphereShape::hkpSphereShape(v11, radius);
  else
    v12 = 0i64;
  this->mShape = v12;
  v13 = *(_BYTE *)(v7 + 80);
  if ( v13 > 0 )
  {
    *(_BYTE *)(v7 + 80) = v13 - 1;
  }
  else
  {
    *(_BYTE *)(v7 + 80) = 0;
    *(_DWORD *)v7 = 3;
    *(_QWORD *)(v7 + 16) = 0i64;
    *(_QWORD *)(v7 + 48) = 0i64;
  }
  UFG::ShapeCasterCollector::ShapeCasterH(this, collisionFilter, simpleOrCached);
}

// File Line: 153
// RVA: 0xB28B0
void __fastcall UFG::ShapeCasterCollector::ShapeCasterH(
        UFG::ShapeCasterCollector *this,
        unsigned int collisionFilter,
        UFG::ShapeCasterCollector::PhantomBehaviour simpleOrCached)
{
  _QWORD *v5; // rax
  __int64 v6; // rbx
  char v7; // dl
  char v8; // cl
  _QWORD **v9; // rax
  hkpSimpleShapePhantom *v10; // rax
  hkpShapePhantom *v11; // rax
  char v12; // dl
  char v13; // cl
  _QWORD **Value; // rax
  hkpCachingShapePhantom *v15; // rax
  char v16; // al
  hkTransformf transform; // [rsp+30h] [rbp-48h] BYREF

  transform.m_rotation.m_col0 = (hkVector4f)::transform.m_quad;
  transform.m_rotation.m_col1 = (hkVector4f)direction.m_quad;
  transform.m_rotation.m_col2 = (hkVector4f)stru_141A71280.m_quad;
  transform.m_translation = 0i64;
  v5 = NtCurrentTeb()->Reserved1[11];
  if ( simpleOrCached )
  {
    v6 = v5[tls_index] + 16i64;
    v12 = ++*(_BYTE *)(v6 + 80);
    *(_DWORD *)(v6 + 4i64 * v12) = 3;
    *(_QWORD *)(v6 + 8i64 * v12 + 16) = "hkpCachingShapePhantom";
    *(_QWORD *)(v6 + 8i64 * v12 + 48) = 0i64;
    v13 = *(_BYTE *)(v6 + 81);
    if ( v12 > v13 )
      v13 = v12;
    *(_BYTE *)(v6 + 81) = v13;
    Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v15 = (hkpCachingShapePhantom *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(
                                      Value[11],
                                      448i64);
    if ( v15 )
      hkpCachingShapePhantom::hkpCachingShapePhantom(v15, this->mShape, &transform, collisionFilter);
    else
      v11 = 0i64;
  }
  else
  {
    v6 = v5[tls_index] + 16i64;
    v7 = ++*(_BYTE *)(v6 + 80);
    *(_DWORD *)(v6 + 4i64 * v7) = 3;
    *(_QWORD *)(v6 + 8i64 * v7 + 16) = "hkpSimpleShapePhantom";
    *(_QWORD *)(v6 + 8i64 * v7 + 48) = 0i64;
    v8 = *(_BYTE *)(v6 + 81);
    if ( v7 > v8 )
      v8 = v7;
    *(_BYTE *)(v6 + 81) = v8;
    v9 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v10 = (hkpSimpleShapePhantom *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v9[11] + 8i64))(v9[11], 448i64);
    if ( v10 )
      hkpSimpleShapePhantom::hkpSimpleShapePhantom(v10, this->mShape, &transform, collisionFilter);
    else
      v11 = 0i64;
  }
  this->mPhantom = v11;
  v16 = *(_BYTE *)(v6 + 80);
  if ( v16 > 0 )
  {
    *(_BYTE *)(v6 + 80) = v16 - 1;
  }
  else
  {
    *(_BYTE *)(v6 + 80) = 0;
    *(_QWORD *)(v6 + 48) = 0i64;
    *(_QWORD *)(v6 + 16) = 0i64;
    *(_DWORD *)v6 = 3;
  }
  hkReferencedObject::removeReference(this->mShape);
}

// File Line: 179
// RVA: 0x9D2D0
void __fastcall UFG::ShapeCasterCollector::~ShapeCasterCollector(UFG::ShapeCasterCollector *this)
{
  hkpShapePhantom *mPhantom; // rcx
  UFG::qList<UFG::qReflectField,UFG::qReflectField,1,0> *p_mHitList; // rbx
  UFG::qNode<UFG::qReflectField,UFG::qReflectField> *mPrev; // rcx
  UFG::qNode<UFG::qReflectField,UFG::qReflectField> *mNext; // rax

  this->vfptr = (UFG::ShapeCasterCollectorVtbl *)&UFG::ShapeCasterCollector::`vftable;
  mPhantom = this->mPhantom;
  if ( mPhantom )
  {
    if ( mPhantom->m_world )
      hkpWorld::removePhantom(mPhantom->m_world, mPhantom);
    hkReferencedObject::removeReference(this->mPhantom);
    this->mPhantom = 0i64;
  }
  p_mHitList = (UFG::qList<UFG::qReflectField,UFG::qReflectField,1,0> *)&this->mHitList;
  UFG::qList<UFG::FractureConnectivity::Connection,UFG::FractureConnectivity::Connection,1,0>::DeleteNodes(p_mHitList);
  UFG::qList<UFG::FractureConnectivity::Connection,UFG::FractureConnectivity::Connection,1,0>::DeleteNodes(p_mHitList);
  mPrev = p_mHitList->mNode.mPrev;
  mNext = p_mHitList->mNode.mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  p_mHitList->mNode.mPrev = &p_mHitList->mNode;
  p_mHitList->mNode.mNext = &p_mHitList->mNode;
}

// File Line: 196
// RVA: 0xA0750
void __fastcall UFG::ShapeCasterCollector::AddHit(
        UFG::ShapeCasterCollector *this,
        hkpRootCdPoint *pt,
        bool oneHitPerRigidBody)
{
  hkpCollidable *m_rootCollidableA; // rax
  hkpShape *m_shape; // rbp
  __int64 v7; // rsi
  hkpWorldObject *v8; // rdi
  int m_shapeKeyA; // r15d
  hkpCollidable *m_rootCollidableB; // rax
  UFG::qNode<UFG::ShapeCasterCollector::HitInfo,UFG::ShapeCasterCollector::HitInfo> *v11; // rax
  UFG::qList<UFG::ShapeCasterCollector::HitInfo,UFG::ShapeCasterCollector::HitInfo,1,0> *p_mHitList; // rcx
  char *v13; // rax
  char *v14; // rbx
  int v15; // xmm0_4
  int v16; // xmm1_4
  int v17; // xmm0_4
  int v18; // xmm1_4
  unsigned __int64 m_userData; // r8
  signed int v20; // edx
  __int64 v21; // rcx
  __int64 v22; // rax
  __int64 v23; // rcx
  UFG::qNode<UFG::ShapeCasterCollector::HitInfo,UFG::ShapeCasterCollector::HitInfo> *mNext; // rcx
  unsigned __int64 v25; // rax
  __int64 v26; // rax

  m_rootCollidableA = pt->m_rootCollidableA;
  m_shape = m_rootCollidableA->m_shape;
  v7 = 0i64;
  if ( m_rootCollidableA->m_broadPhaseHandle.m_type == 1 )
    v8 = (hkpWorldObject *)((char *)m_rootCollidableA + m_rootCollidableA->m_ownerOffset);
  else
    v8 = 0i64;
  m_shapeKeyA = pt->m_shapeKeyA;
  if ( v8
    || ((m_rootCollidableB = pt->m_rootCollidableB, m_rootCollidableB->m_broadPhaseHandle.m_type != 1)
      ? (v8 = 0i64)
      : (v8 = (hkpWorldObject *)((char *)m_rootCollidableB + m_rootCollidableB->m_ownerOffset)),
        m_shape = m_rootCollidableB->m_shape,
        m_shapeKeyA = pt->m_shapeKeyB,
        v8) )
  {
    if ( !oneHitPerRigidBody
      || (v11 = this->mHitList.mNode.mNext,
          p_mHitList = &this->mHitList,
          v11 == (UFG::qNode<UFG::ShapeCasterCollector::HitInfo,UFG::ShapeCasterCollector::HitInfo> *)p_mHitList) )
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
      v15 = pt->m_contact.m_position.m_quad.m128_i32[1];
      v16 = pt->m_contact.m_position.m_quad.m128_i32[2];
      *((_DWORD *)v14 + 4) = pt->m_contact.m_position.m_quad.m128_i32[0];
      *((_DWORD *)v14 + 5) = v15;
      *((_DWORD *)v14 + 6) = v16;
      v17 = pt->m_contact.m_separatingNormal.m_quad.m128_i32[1];
      v18 = pt->m_contact.m_separatingNormal.m_quad.m128_i32[2];
      *((_DWORD *)v14 + 7) = pt->m_contact.m_separatingNormal.m_quad.m128_i32[0];
      *((_DWORD *)v14 + 8) = v17;
      *((_DWORD *)v14 + 9) = v18;
      *((_QWORD *)v14 + 5) = v8;
      *((_QWORD *)v14 + 6) = pt->m_rootCollidableA;
      *((_DWORD *)v14 + 14) = pt->m_shapeKeyA;
      *((_QWORD *)v14 + 8) = pt->m_rootCollidableB;
      *((_DWORD *)v14 + 18) = pt->m_shapeKeyB;
      *((_QWORD *)v14 + 10) = 0i64;
      *((_QWORD *)v14 + 11) = UFG::PhysicsPropertyManager::GetObjectPropertiesHandleUid(v8, m_shape, m_shapeKeyA);
      if ( m_shapeKeyA != -1
        && m_shape->m_type.m_storage == 9
        && (m_userData = m_shape[2].m_userData) != 0
        && ((*(_BYTE *)(m_userData + 41) - 1) & 0xFD) == 0
        && ((v20 = (m_shapeKeyA & 0x7FFFFFFFu) >> (32 - *(_BYTE *)(m_userData + 232)), m_shapeKeyA < 0)
          ? (v21 = *(_QWORD *)(m_userData + 256) + 80i64 * v20)
          : (v21 = *(_QWORD *)(m_userData + 240) + 144i64 * v20),
            (v22 = *(_QWORD *)(v21 + 16)) != 0) )
      {
        v23 = *(_QWORD *)(v22 + 8);
      }
      else
      {
        v23 = 0i64;
      }
      *((_QWORD *)v14 + 12) = v23;
      mNext = this->mHitList.mNode.mNext;
      this->mHitList.mNode.mNext = (UFG::qNode<UFG::ShapeCasterCollector::HitInfo,UFG::ShapeCasterCollector::HitInfo> *)v14;
      *(_QWORD *)v14 = &this->mHitList;
      *((_QWORD *)v14 + 1) = mNext;
      mNext->mPrev = (UFG::qNode<UFG::ShapeCasterCollector::HitInfo,UFG::ShapeCasterCollector::HitInfo> *)v14;
      v25 = v8->m_userData;
      if ( v25 )
      {
        v26 = *(_QWORD *)(v25 + 24);
        if ( v26 )
          v7 = *(_QWORD *)(v26 + 40);
        *((_QWORD *)v14 + 10) = v7;
      }
    }
    else
    {
      while ( (hkpWorldObject *)v11[2].mNext != v8 )
      {
        v11 = v11->mNext;
        if ( v11 == (UFG::qNode<UFG::ShapeCasterCollector::HitInfo,UFG::ShapeCasterCollector::HitInfo> *)p_mHitList )
          goto LABEL_13;
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
UFG::AsyncShapeCasterCollector *__fastcall UFG::AsyncShapeCasterCollector::operator=(
        UFG::AsyncShapeCasterCollector *this,
        UFG::AsyncShapeCasterCollector *rhs)
{
  hkpShape *mShape; // rcx
  hkpShapePhantom *mPhantom; // rcx
  hkpShapePhantom *v6; // rcx
  void (__fastcall *mShapecastCallback)(UFG::AsyncShapeCasterCollector *); // rax

  mShape = this->mShape;
  if ( mShape )
    hkReferencedObject::removeReference(mShape);
  mPhantom = this->mPhantom;
  this->mShape = rhs->mShape;
  if ( mPhantom )
    hkReferencedObject::removeReference(mPhantom);
  v6 = rhs->mPhantom;
  this->mPhantom = v6;
  hkReferencedObject::addReference(v6);
  this->mRadius = rhs->mRadius;
  this->m_from = rhs->m_from;
  this->m_to = rhs->m_to;
  mShapecastCallback = rhs->mShapecastCallback;
  this->mHit = 0;
  this->mShapecastCallback = mShapecastCallback;
  return this;
}

