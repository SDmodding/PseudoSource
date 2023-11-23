// File Line: 24
// RVA: 0xA9A50
UFG::ComponentIDDesc *__fastcall UFG::MultiBodyComponent::GetDesc(UFG::MultiBodyComponent *this)
{
  return &UFG::MultiBodyComponent::_TypeIDesc;
}

// File Line: 25
// RVA: 0x1458DC0
__int64 dynamic_initializer_for__UFG::MultiBodyComponent::s_MultiBodyComponentList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::MultiBodyComponent::s_MultiBodyComponentList__);
}

// File Line: 30
// RVA: 0xAA330
bool __fastcall UFG::MultiBody::GetKeyframe(
        hkaPose *pose,
        hkaSkeleton *skel,
        hkQsTransformf *creatureRoot,
        const unsigned __int16 followBoneIndex,
        UFG::qMatrix44 *qrootTransform,
        bool pivotAtOrigin,
        hkVector4f *nextPosition,
        hkQuaternionf *nextOrientation)
{
  hkQsTransformf *v12; // rax
  __m128 m_quad; // xmm6
  __m128 v14; // xmm9
  hkQsTransformf *v15; // rcx
  __m128i inserted; // xmm0
  __m128 v17; // xmm5
  __m128 v18; // xmm4
  __m128 v19; // xmm7
  __m128 v20; // xmm3
  __m128 v21; // xmm1
  __m128 v22; // xmm2
  __m128 v23; // xmm10
  __m128 v24; // xmm2
  __m128 v25; // xmm11
  __m128 v26; // xmm10
  __m128 v27; // xmm0
  __m128 v28; // xmm7
  __m128 v29; // xmm11
  __m128 v30; // xmm11
  hkQuaternionf *v31; // rbx
  __m128 v32; // xmm1
  __m128 v33; // xmm4
  __m128 v34; // xmm7
  __m128 v35; // xmm2
  __m128 v36; // xmm6
  __m128 v37; // xmm5
  __m128 v38; // xmm2
  __m128 v39; // xmm3
  __m128 v40; // xmm1
  __m128 v41; // xmm3
  hkQsTransformf *v42; // rax
  hkQuaternionf v43; // xmm4
  __m128 v44; // xmm7
  __m128 v45; // xmm1
  __m128 v46; // xmm2
  __m128 v47; // xmm6
  __m128 v48; // xmm5
  __m128 v49; // xmm2
  __m128 v50; // xmm3
  __m128 v51; // xmm0
  __m128 v52; // xmm7
  __m128 v53; // xmm3
  bool result; // al
  __m128 v55; // xmm0
  __m128 v56; // xmm2
  __m128 v57; // xmm1
  __m128 v58; // xmm2
  hkVector4f direction; // [rsp+20h] [rbp-138h] BYREF
  hkQuaternionf quat; // [rsp+30h] [rbp-128h] BYREF
  hkVector4f v61; // [rsp+40h] [rbp-118h]
  hkTransformf v62; // [rsp+50h] [rbp-108h] BYREF
  hkQsTransformf v63; // [rsp+90h] [rbp-C8h] BYREF
  hkTransformf transform; // [rsp+C0h] [rbp-98h] BYREF

  if ( pose )
  {
    if ( pivotAtOrigin )
    {
      hkTransformf::set4x4ColumnMajor(&transform, &qrootTransform->v0.x);
      hkQsTransformf::setFromTransformNoScale(&v63, &transform);
      if ( (pose->m_boneFlags.m_data[followBoneIndex] & 2) != 0 )
        v12 = hkaPose::calculateBoneModelSpace(pose, followBoneIndex);
      else
        v12 = &pose->m_modelPose.m_data[followBoneIndex];
      m_quad = v12->m_translation.m_quad;
      v14 = v12->m_rotation.m_vec.m_quad;
      v15 = &skel->m_referencePose.m_data[followBoneIndex];
      direction.m_quad = (__m128)v15->m_translation;
      quat.m_vec.m_quad = (__m128)v15->m_rotation;
      v61.m_quad = (__m128)v15->m_scale;
      hkVector4f::setRotatedInverseDir(&v62.m_rotation.m_col0, &quat, &direction);
      inserted = _mm_insert_epi16((__m128i)0i64, 0x8000u, 1);
      v17 = _mm_shuffle_ps(v14, v14, 255);
      v18 = _mm_shuffle_ps(v14, v14, 201);
      v19 = _mm_xor_ps((__m128)_mm_shuffle_epi32(inserted, 64), quat.m_vec.m_quad);
      v20 = _mm_xor_ps((__m128)_mm_shuffle_epi32(inserted, 0), v62.m_rotation.m_col0.m_quad);
      v21 = _mm_mul_ps(v20, v14);
      v22 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v20, v20, 201), v14), _mm_mul_ps(v20, v18));
      v23 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v21, v21, 85), _mm_shuffle_ps(v21, v21, 0)),
                    _mm_shuffle_ps(v21, v21, 170)),
                  v14),
                _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v17, v17), (__m128)xmmword_141A711B0), v20)),
              _mm_mul_ps(_mm_shuffle_ps(v22, v22, 201), v17));
      v24 = _mm_shuffle_ps(v19, v19, 255);
      v25 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v19, v19, 201), v14), _mm_mul_ps(v19, v18));
      v26 = _mm_add_ps(_mm_add_ps(v23, v23), m_quad);
      v27 = _mm_mul_ps(v19, v17);
      v28 = _mm_mul_ps(v19, v14);
      v29 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v25, v25, 201), v27), _mm_mul_ps(v14, v24));
      v30 = _mm_shuffle_ps(
              v29,
              _mm_unpackhi_ps(
                v29,
                _mm_sub_ps(
                  _mm_mul_ps(v24, v17),
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v28, v28, 85), _mm_shuffle_ps(v28, v28, 0)),
                    _mm_shuffle_ps(v28, v28, 170)))),
              196);
      v31 = nextOrientation;
      v32 = _mm_mul_ps(v63.m_rotation.m_vec.m_quad, v26);
      v33 = _mm_shuffle_ps(v63.m_rotation.m_vec.m_quad, v63.m_rotation.m_vec.m_quad, 201);
      v34 = _mm_shuffle_ps(v63.m_rotation.m_vec.m_quad, v63.m_rotation.m_vec.m_quad, 255);
      v35 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v26, v26, 201), v63.m_rotation.m_vec.m_quad), _mm_mul_ps(v26, v33));
      v36 = _mm_mul_ps(v63.m_rotation.m_vec.m_quad, v30);
      v37 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v32, v32, 85), _mm_shuffle_ps(v32, v32, 0)),
                    _mm_shuffle_ps(v32, v32, 170)),
                  v63.m_rotation.m_vec.m_quad),
                _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v34, v34), (__m128)xmmword_141A711B0), v26)),
              _mm_mul_ps(_mm_shuffle_ps(v35, v35, 201), v34));
      v38 = _mm_shuffle_ps(v30, v30, 255);
      v39 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v30, v30, 201), v63.m_rotation.m_vec.m_quad), _mm_mul_ps(v30, v33));
      v40 = _mm_mul_ps(v63.m_rotation.m_vec.m_quad, v38);
      nextPosition->m_quad = _mm_add_ps(_mm_add_ps(v37, v37), v63.m_translation.m_quad);
      v41 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v39, v39, 201), _mm_mul_ps(v30, v34)), v40);
      nextOrientation->m_vec.m_quad = _mm_shuffle_ps(
                                        v41,
                                        _mm_unpackhi_ps(
                                          v41,
                                          _mm_sub_ps(
                                            _mm_mul_ps(v38, v34),
                                            _mm_add_ps(
                                              _mm_add_ps(_mm_shuffle_ps(v36, v36, 85), _mm_shuffle_ps(v36, v36, 0)),
                                              _mm_shuffle_ps(v36, v36, 170)))),
                                        196);
    }
    else
    {
      if ( (pose->m_boneFlags.m_data[followBoneIndex] & 2) != 0 )
        v42 = hkaPose::calculateBoneModelSpace(pose, followBoneIndex);
      else
        v42 = &pose->m_modelPose.m_data[followBoneIndex];
      v43.m_vec.m_quad = (__m128)creatureRoot->m_rotation;
      v44 = v42->m_rotation.m_vec.m_quad;
      v31 = nextOrientation;
      v45 = _mm_mul_ps(v42->m_translation.m_quad, v43.m_vec.m_quad);
      v46 = _mm_sub_ps(
              _mm_mul_ps(_mm_shuffle_ps(v42->m_translation.m_quad, v42->m_translation.m_quad, 201), v43.m_vec.m_quad),
              _mm_mul_ps(_mm_shuffle_ps(v43.m_vec.m_quad, v43.m_vec.m_quad, 201), v42->m_translation.m_quad));
      v47 = _mm_shuffle_ps(v43.m_vec.m_quad, v43.m_vec.m_quad, 255);
      v48 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v45, v45, 85), _mm_shuffle_ps(v45, v45, 0)),
                    _mm_shuffle_ps(v45, v45, 170)),
                  v43.m_vec.m_quad),
                _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v47, v47), (__m128)xmmword_141A711B0), v42->m_translation.m_quad)),
              _mm_mul_ps(_mm_shuffle_ps(v46, v46, 201), v47));
      v49 = _mm_shuffle_ps(v44, v44, 255);
      v50 = _mm_sub_ps(
              _mm_mul_ps(_mm_shuffle_ps(v44, v44, 201), v43.m_vec.m_quad),
              _mm_mul_ps(_mm_shuffle_ps(v43.m_vec.m_quad, v43.m_vec.m_quad, 201), v44));
      nextPosition->m_quad = _mm_add_ps(_mm_add_ps(v48, v48), creatureRoot->m_translation.m_quad);
      v51 = _mm_mul_ps(v44, v47);
      v52 = _mm_mul_ps(v44, v43.m_vec.m_quad);
      v53 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v50, v50, 201), v51), _mm_mul_ps(v43.m_vec.m_quad, v49));
      nextOrientation->m_vec.m_quad = _mm_shuffle_ps(
                                        v53,
                                        _mm_unpackhi_ps(
                                          v53,
                                          _mm_sub_ps(
                                            _mm_mul_ps(v49, v47),
                                            _mm_add_ps(
                                              _mm_add_ps(_mm_shuffle_ps(v52, v52, 85), _mm_shuffle_ps(v52, v52, 0)),
                                              _mm_shuffle_ps(v52, v52, 170)))),
                                        196);
    }
    goto LABEL_13;
  }
  if ( qrootTransform )
  {
    hkTransformf::set4x4ColumnMajor(&v62, &qrootTransform->v0.x);
    v31 = nextOrientation;
    *nextPosition = v62.m_translation;
    hkQuaternionf::set(nextOrientation, &v62.m_rotation);
LABEL_13:
    result = 1;
    v55 = _mm_mul_ps(v31->m_vec.m_quad, v31->m_vec.m_quad);
    v56 = _mm_add_ps(_mm_shuffle_ps(v55, v55, 78), v55);
    v57 = _mm_add_ps(_mm_shuffle_ps(v56, v56, 177), v56);
    v58 = _mm_rsqrt_ps(v57);
    v31->m_vec.m_quad = _mm_mul_ps(
                          _mm_mul_ps(
                            _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v58, v57), v58)),
                            _mm_mul_ps(*(__m128 *)_xmm, v58)),
                          v31->m_vec.m_quad);
    return result;
  }
  return 0;
}

// File Line: 90
// RVA: 0x98CA0
void __fastcall UFG::MultiBodyComponent::MultiBodyComponent(UFG::MultiBodyComponent *this, unsigned int name_uid)
{
  UFG::qNode<UFG::MultiBodyComponent,UFG::MultiBodyComponent> *mPrev; // rax

  UFG::SimComponent::SimComponent(this, name_uid);
  this->mPrev = &this->UFG::qNode<UFG::MultiBodyComponent,UFG::MultiBodyComponent>;
  this->mNext = &this->UFG::qNode<UFG::MultiBodyComponent,UFG::MultiBodyComponent>;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::MultiBodyComponent::`vftable;
  this->mBodies.p = 0i64;
  *(_QWORD *)&this->mBodies.size = 0i64;
  this->mConstraints.p = 0i64;
  *(_QWORD *)&this->mConstraints.size = 0i64;
  this->mFlags = 0;
  UFG::SimComponent::AddType(this, UFG::MultiBodyComponent::_MultiBodyComponentTypeUID, "MultiBodyComponent");
  mPrev = UFG::MultiBodyComponent::s_MultiBodyComponentList.mNode.mPrev;
  UFG::MultiBodyComponent::s_MultiBodyComponentList.mNode.mPrev->mNext = &this->UFG::qNode<UFG::MultiBodyComponent,UFG::MultiBodyComponent>;
  this->mPrev = mPrev;
  this->mNext = (UFG::qNode<UFG::MultiBodyComponent,UFG::MultiBodyComponent> *)&UFG::MultiBodyComponent::s_MultiBodyComponentList;
  UFG::MultiBodyComponent::s_MultiBodyComponentList.mNode.mPrev = &this->UFG::qNode<UFG::MultiBodyComponent,UFG::MultiBodyComponent>;
}

// File Line: 98
// RVA: 0x9C5A0
void __fastcall UFG::MultiBodyComponent::~MultiBodyComponent(UFG::MultiBodyComponent *this)
{
  UFG::qNode<UFG::MultiBodyComponent,UFG::MultiBodyComponent> *v2; // rsi
  UFG::qNode<UFG::MultiBodyComponent,UFG::MultiBodyComponent> *mPrev; // rcx
  UFG::qNode<UFG::MultiBodyComponent,UFG::MultiBodyComponent> *mNext; // rax
  UFG::qSafePointer<UFG::Constraint,UFG::Constraint> *p; // rcx
  UFG::Constraint **p_m_pPointer; // rbx
  UFG::qSafePointer<UFG::SimComponent,UFG::RigidBody> *v7; // rcx
  UFG::SimComponent **v8; // rbx
  UFG::qNode<UFG::MultiBodyComponent,UFG::MultiBodyComponent> *v9; // rcx
  UFG::qNode<UFG::MultiBodyComponent,UFG::MultiBodyComponent> *v10; // rax

  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::MultiBodyComponent::`vftable;
  if ( this == UFG::MultiBodyComponent::s_MultiBodyComponentpCurrentIterator )
    UFG::MultiBodyComponent::s_MultiBodyComponentpCurrentIterator = (UFG::MultiBodyComponent *)&this->mPrev[-4];
  v2 = &this->UFG::qNode<UFG::MultiBodyComponent,UFG::MultiBodyComponent>;
  mPrev = this->mPrev;
  mNext = v2->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  p = this->mConstraints.p;
  if ( p )
  {
    p_m_pPointer = &p[-1].m_pPointer;
    `eh vector destructor iterator(
      p,
      0x18ui64,
      (int)p[-1].m_pPointer,
      (void (__fastcall *)(void *))UFG::qSafePointer<AnimationGroup,AnimationGroup>::~qSafePointer<AnimationGroup,AnimationGroup>);
    operator delete[](p_m_pPointer);
  }
  this->mConstraints.p = 0i64;
  *(_QWORD *)&this->mConstraints.size = 0i64;
  v7 = this->mBodies.p;
  if ( v7 )
  {
    v8 = &v7[-1].m_pPointer;
    `eh vector destructor iterator(
      v7,
      0x18ui64,
      (int)v7[-1].m_pPointer,
      (void (__fastcall *)(void *))UFG::qSafePointer<UFG::SimComponent,UFG::HealthComponent>::~qSafePointer<UFG::SimComponent,UFG::HealthComponent>);
    operator delete[](v8);
  }
  this->mBodies.p = 0i64;
  *(_QWORD *)&this->mBodies.size = 0i64;
  v9 = v2->mPrev;
  v10 = v2->mNext;
  v9->mNext = v10;
  v10->mPrev = v9;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::SimComponent::~SimComponent(this);
}

// File Line: 106
// RVA: 0xB4A10
char __fastcall UFG::MultiBodyComponent::UpdateCollisionFiltersForConstraints(UFG::MultiBodyComponent *this)
{
  char v2; // bl
  char v3; // r12
  unsigned __int64 size; // rbp
  unsigned __int64 v5; // rax
  char *v6; // rax
  char *v7; // r15
  char *v8; // rdi
  __int64 i; // rcx
  __int64 v10; // r14
  UFG::Constraint *m_pPointer; // r11
  UFG::qReflectObject *mData; // rcx
  int v13; // esi
  __int64 v14; // r9
  int v15; // ebx
  __int64 v16; // r10
  unsigned int v17; // eax
  __int64 v18; // rdx
  hkpConstraintInstance *mConstraintInstance; // r11
  UFG::SimComponent **p_m_pPointer; // rdi
  UFG::SimObject *m_pSimObject; // r8
  unsigned __int64 v22; // rax
  char *v23; // r13
  int v24; // eax
  char *v25; // rcx
  unsigned __int64 v26; // rdx
  UFG::Stack *mAssignedSystemGroups; // rdi
  unsigned int v29; // edx
  __int64 v30; // rsi
  signed __int64 v31; // r12
  int v32; // r14d
  __int64 v33; // rax
  int v34; // ebp
  UFG::SimComponent *v35; // rbx
  UFG::SimObject *v36; // rax
  int mPrev_high; // edi
  __int64 v38; // rdx
  UFG::SimComponent *v39; // rdx
  int v40; // ecx
  int v41; // ecx
  int v42; // eax
  int v43; // ecx
  UFG::SimObject *v44; // rax
  hkpEntity *v45; // rdx
  hkpWorld *m_world; // rcx
  UFG::qReflectHandleBase v47; // [rsp+28h] [rbp-70h] BYREF
  char v49; // [rsp+A8h] [rbp+10h]
  int v50; // [rsp+B0h] [rbp+18h]
  unsigned __int64 v51; // [rsp+B8h] [rbp+20h]

  v2 = 1;
  v49 = 1;
  v3 = 0;
  size = this->mBodies.size;
  v51 = size;
  v5 = 4 * size;
  if ( !is_mul_ok(size, 4ui64) )
    v5 = -1i64;
  v6 = UFG::qMalloc(v5, UFG::gGlobalNewName, 0i64);
  v7 = v6;
  if ( (_DWORD)size )
  {
    v8 = v6;
    for ( i = (unsigned int)size; i; --i )
    {
      *(_DWORD *)v8 = -1;
      v8 += 4;
    }
  }
  v10 = 0i64;
  if ( !this->mConstraints.size )
    return v2;
  do
  {
    m_pPointer = this->mConstraints.p[v10].m_pPointer;
    mData = 0i64;
    if ( m_pPointer->mDefinition.mData )
      mData = m_pPointer->mDefinition.mData;
    if ( BYTE4(mData[1].mBaseNode.mParent) )
    {
      v3 = 1;
      v13 = -1;
      v14 = -1i64;
      v15 = -1;
      v16 = -1i64;
      v17 = 0;
      v18 = 0i64;
      if ( (_DWORD)size )
      {
        mConstraintInstance = m_pPointer->mConstraintInstance;
        p_m_pPointer = &this->mBodies.p->m_pPointer;
        do
        {
          m_pSimObject = (*p_m_pPointer)[2].m_pSimObject;
          if ( m_pSimObject == (UFG::SimObject *)mConstraintInstance->m_entities[0] )
          {
            v13 = v17;
            v14 = v18;
          }
          else if ( m_pSimObject == (UFG::SimObject *)mConstraintInstance->m_entities[1] )
          {
            v15 = v17;
            v16 = v18;
          }
          if ( v14 != -1 && v16 != -1 )
            break;
          ++v17;
          ++v18;
          p_m_pPointer += 3;
        }
        while ( v17 < (unsigned int)size );
      }
      if ( *(_DWORD *)&v7[4 * v14] == -1 )
      {
        *(_DWORD *)&v7[4 * v14] = v15;
        v2 = v49;
      }
      else if ( *(_DWORD *)&v7[4 * v16] == -1 )
      {
        *(_DWORD *)&v7[4 * v16] = v13;
        v2 = v49;
      }
      else
      {
        v2 = 0;
        v49 = 0;
      }
    }
    v10 = (unsigned int)(v10 + 1);
  }
  while ( (unsigned int)v10 < this->mConstraints.size );
  if ( !v2 || !v3 )
    return v2;
  v22 = 4 * size;
  if ( !is_mul_ok(size, 4ui64) )
    v22 = -1i64;
  v23 = UFG::qMalloc(v22, UFG::gGlobalNewName, 0i64);
  v24 = 1;
  if ( (_DWORD)size )
  {
    v25 = v23;
    v26 = size;
    do
    {
      *(_DWORD *)v25 = v24++;
      v25 += 4;
      --v26;
    }
    while ( v26 );
    if ( v24 > 16 )
      return 0;
  }
  mAssignedSystemGroups = UFG::BasePhysicsSystem::mInstance->mCollisionFilter->mAssignedSystemGroups;
  v29 = mAssignedSystemGroups->mBuffer[--mAssignedSystemGroups->mHead];
  if ( !(_DWORD)size )
    return v2;
  v50 = (unsigned __int16)v29 << 6;
  v30 = 0i64;
  v31 = v23 - v7;
  do
  {
    v32 = *(_DWORD *)&v7[v31];
    v33 = *(int *)v7;
    if ( (_DWORD)v33 == -1 )
      v34 = 0;
    else
      v34 = *(_DWORD *)&v23[4 * v33];
    v35 = this->mBodies.p[v30].m_pPointer;
    v36 = v35[2].m_pSimObject;
    if ( v36 )
    {
      mPrev_high = *(_DWORD *)&v36->m_Flags & 0x1F;
    }
    else
    {
      mPrev_high = HIDWORD(v35[4].m_SafePointerList.mNode.mPrev);
      if ( mPrev_high == -1 )
      {
        UFG::qReflectHandleBase::qReflectHandleBase(&v47);
        v47.mTypeUID = UFG::qStringHash64("UFG::PhysicsObjectProperties", 0xFFFFFFFFFFFFFFFFui64);
        v38 = *(_QWORD *)&v35[2].m_Flags;
        if ( v38 )
          UFG::qReflectHandleBase::operator=(&v47, (UFG::qReflectHandleBase *)(v38 + 224));
        if ( v47.mData )
        {
          mPrev_high = (int)v47.mData[2].mBaseNode.mChildren[0];
          UFG::qReflectHandleBase::~qReflectHandleBase(&v47);
        }
        else
        {
          UFG::qReflectHandleBase::~qReflectHandleBase(&v47);
          LOBYTE(mPrev_high) = 0;
        }
      }
      else
      {
        LOBYTE(mPrev_high) = mPrev_high & 0x1F;
      }
    }
    v39 = this->mBodies.p[v30].m_pPointer;
    v40 = 0;
    if ( v34 != -1 )
      v40 = v34;
    v41 = 32 * (v50 | v40);
    v42 = 0;
    if ( v32 != -1 )
      v42 = v32;
    v43 = mPrev_high & 0x1F | (32 * (v42 | v41));
    HIDWORD(v39[4].m_SafePointerList.mNode.mPrev) = v43;
    v44 = v39[2].m_pSimObject;
    if ( v44 && *(_DWORD *)&v44->m_Flags != v43 )
    {
      *(_DWORD *)&v44->m_Flags = v43;
      v45 = (hkpEntity *)v39[2].m_pSimObject;
      m_world = v45->m_world;
      if ( m_world )
        hkpWorld::updateCollisionFilterOnEntity(
          m_world,
          v45,
          HK_UPDATE_FILTER_ON_ENTITY_FULL_CHECK,
          HK_UPDATE_COLLECTION_FILTER_PROCESS_SHAPE_COLLECTIONS);
    }
    v7 += 4;
    ++v30;
    --v51;
  }
  while ( v51 );
  return v49;
}

