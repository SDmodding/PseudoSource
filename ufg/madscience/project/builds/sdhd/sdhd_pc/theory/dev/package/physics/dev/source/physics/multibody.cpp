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
  return atexit(dynamic_atexit_destructor_for__UFG::MultiBodyComponent::s_MultiBodyComponentList__);
}

// File Line: 30
// RVA: 0xAA330
char __fastcall UFG::MultiBody::GetKeyframe(hkaPose *pose, hkaSkeleton *skel, hkQsTransformf *creatureRoot, const unsigned __int16 followBoneIndex, UFG::qMatrix44 *qrootTransform, const bool pivotAtOrigin, hkVector4f *nextPosition, hkQuaternionf *nextOrientation)
{
  unsigned __int16 v8; // di
  hkQsTransformf *v9; // rsi
  hkaSkeleton *v10; // rbp
  hkaPose *v11; // rbx
  hkQsTransformf *v12; // rax
  __m128 v13; // xmm6
  __m128 v14; // xmm9
  signed __int64 v15; // rcx
  __m128i v16; // xmm0
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
  __m128 v43; // xmm4
  __m128 v44; // xmm7
  __m128 v45; // xmm1
  __m128 v46; // xmm2
  __m128 v47; // xmm6
  __m128 v48; // xmm5
  __m128 v49; // xmm2
  __m128 v50; // xmm3
  __m128 v51; // xmm1
  __m128 v52; // xmm0
  __m128 v53; // xmm7
  __m128 v54; // xmm3
  char result; // al
  __m128 v56; // xmm0
  __m128 v57; // xmm2
  __m128 v58; // xmm1
  __m128 v59; // xmm2
  hkVector4f direction; // [rsp+20h] [rbp-138h]
  hkQuaternionf quat; // [rsp+30h] [rbp-128h]
  __int128 v62; // [rsp+40h] [rbp-118h]
  hkVector4f v63; // [rsp+50h] [rbp-108h]
  hkVector4f v64; // [rsp+80h] [rbp-D8h]
  hkQsTransformf v65; // [rsp+90h] [rbp-C8h]
  hkTransformf transform; // [rsp+C0h] [rbp-98h]

  v8 = followBoneIndex;
  v9 = creatureRoot;
  v10 = skel;
  v11 = pose;
  if ( pose )
  {
    if ( pivotAtOrigin )
    {
      hkTransformf::set4x4ColumnMajor(&transform, &qrootTransform->v0.x);
      hkQsTransformf::setFromTransformNoScale(&v65, &transform);
      if ( v11->m_boneFlags.m_data[v8] & 2 )
        v12 = hkaPose::calculateBoneModelSpace(v11, v8);
      else
        v12 = &v11->m_modelPose.m_data[v8];
      v13 = v12->m_translation.m_quad;
      v14 = v12->m_rotation.m_vec.m_quad;
      v15 = (signed __int64)&v10->m_referencePose.m_data[v8];
      direction.m_quad = *(__m128 *)v15;
      quat.m_vec.m_quad = *(__m128 *)(v15 + 16);
      v62 = *(_OWORD *)(v15 + 32);
      hkVector4f::setRotatedInverseDir(&v63, &quat, &direction);
      v16 = _mm_insert_epi16((__m128i)0i64, 0x8000u, 1);
      v17 = _mm_shuffle_ps(v14, v14, 255);
      v18 = _mm_shuffle_ps(v14, v14, 201);
      v19 = _mm_xor_ps((__m128)_mm_shuffle_epi32(v16, 64), quat.m_vec.m_quad);
      v20 = _mm_xor_ps((__m128)_mm_shuffle_epi32(v16, 0), v63.m_quad);
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
      v26 = _mm_add_ps(_mm_add_ps(v23, v23), v13);
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
      v32 = _mm_mul_ps(v65.m_rotation.m_vec.m_quad, v26);
      v33 = _mm_shuffle_ps(v65.m_rotation.m_vec.m_quad, v65.m_rotation.m_vec.m_quad, 201);
      v34 = _mm_shuffle_ps(v65.m_rotation.m_vec.m_quad, v65.m_rotation.m_vec.m_quad, 255);
      v35 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v26, v26, 201), v65.m_rotation.m_vec.m_quad), _mm_mul_ps(v26, v33));
      v36 = _mm_mul_ps(v65.m_rotation.m_vec.m_quad, v30);
      v37 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v32, v32, 85), _mm_shuffle_ps(v32, v32, 0)),
                    _mm_shuffle_ps(v32, v32, 170)),
                  v65.m_rotation.m_vec.m_quad),
                _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v34, v34), (__m128)xmmword_141A711B0), v26)),
              _mm_mul_ps(_mm_shuffle_ps(v35, v35, 201), v34));
      v38 = _mm_shuffle_ps(v30, v30, 255);
      v39 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v30, v30, 201), v65.m_rotation.m_vec.m_quad), _mm_mul_ps(v30, v33));
      v40 = _mm_mul_ps(v65.m_rotation.m_vec.m_quad, v38);
      nextPosition->m_quad = _mm_add_ps(_mm_add_ps(v37, v37), v65.m_translation.m_quad);
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
      if ( pose->m_boneFlags.m_data[followBoneIndex] & 2 )
        v42 = hkaPose::calculateBoneModelSpace(pose, followBoneIndex);
      else
        v42 = &pose->m_modelPose.m_data[followBoneIndex];
      v43 = v9->m_rotation.m_vec.m_quad;
      v44 = v42->m_rotation.m_vec.m_quad;
      v31 = nextOrientation;
      v45 = _mm_mul_ps(v42->m_translation.m_quad, v43);
      v46 = _mm_sub_ps(
              _mm_mul_ps(_mm_shuffle_ps(v42->m_translation.m_quad, v42->m_translation.m_quad, 201), v43),
              _mm_mul_ps(_mm_shuffle_ps(v43, v43, 201), v42->m_translation.m_quad));
      v47 = _mm_shuffle_ps(v9->m_rotation.m_vec.m_quad, v43, 255);
      v48 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v45, v45, 85), _mm_shuffle_ps(v45, v45, 0)),
                    _mm_shuffle_ps(v45, v45, 170)),
                  v43),
                _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v47, v47), (__m128)xmmword_141A711B0), v42->m_translation.m_quad)),
              _mm_mul_ps(_mm_shuffle_ps(v46, v46, 201), v47));
      v49 = _mm_shuffle_ps(v44, v44, 255);
      v50 = _mm_sub_ps(
              _mm_mul_ps(_mm_shuffle_ps(v44, v44, 201), v43),
              _mm_mul_ps(_mm_shuffle_ps(v9->m_rotation.m_vec.m_quad, v43, 201), v44));
      v51 = _mm_mul_ps(v9->m_rotation.m_vec.m_quad, v49);
      nextPosition->m_quad = _mm_add_ps(_mm_add_ps(v48, v48), v9->m_translation.m_quad);
      v52 = _mm_mul_ps(v44, v47);
      v53 = _mm_mul_ps(v44, v43);
      v54 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v50, v50, 201), v52), v51);
      nextOrientation->m_vec.m_quad = _mm_shuffle_ps(
                                        v54,
                                        _mm_unpackhi_ps(
                                          v54,
                                          _mm_sub_ps(
                                            _mm_mul_ps(v49, v47),
                                            _mm_add_ps(
                                              _mm_add_ps(_mm_shuffle_ps(v53, v53, 85), _mm_shuffle_ps(v53, v53, 0)),
                                              _mm_shuffle_ps(v53, v53, 170)))),
                                        196);
    }
    goto LABEL_13;
  }
  if ( qrootTransform )
  {
    hkTransformf::set4x4ColumnMajor((hkTransformf *)&v63, &qrootTransform->v0.x);
    v31 = nextOrientation;
    *nextPosition = (hkVector4f)v64.m_quad;
    hkQuaternionf::set(nextOrientation, (hkRotationf *)&v63);
LABEL_13:
    result = 1;
    v56 = _mm_mul_ps(v31->m_vec.m_quad, v31->m_vec.m_quad);
    v57 = _mm_add_ps(_mm_shuffle_ps(v56, v56, 78), v56);
    v58 = _mm_add_ps(_mm_shuffle_ps(v57, v57, 177), v57);
    v59 = _mm_rsqrt_ps(v58);
    v31->m_vec.m_quad = _mm_mul_ps(
                          _mm_mul_ps(
                            _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v59, v58), v59)),
                            _mm_mul_ps(*(__m128 *)_xmm, v59)),
                          v31->m_vec.m_quad);
    return result;
  }
  return 0;
}

// File Line: 90
// RVA: 0x98CA0
void __fastcall UFG::MultiBodyComponent::MultiBodyComponent(UFG::MultiBodyComponent *this, unsigned int name_uid)
{
  UFG::MultiBodyComponent *v2; // rdi
  UFG::qNode<UFG::MultiBodyComponent,UFG::MultiBodyComponent> *v3; // rbx
  UFG::qNode<UFG::MultiBodyComponent,UFG::MultiBodyComponent> *v4; // rax

  v2 = this;
  UFG::SimComponent::SimComponent((UFG::SimComponent *)&this->vfptr, name_uid);
  v3 = (UFG::qNode<UFG::MultiBodyComponent,UFG::MultiBodyComponent> *)&v2->mPrev;
  v3->mPrev = v3;
  v3->mNext = v3;
  v2->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::MultiBodyComponent::`vftable;
  v2->mBodies.p = 0i64;
  *(_QWORD *)&v2->mBodies.size = 0i64;
  v2->mConstraints.p = 0i64;
  *(_QWORD *)&v2->mConstraints.size = 0i64;
  v2->mFlags = 0;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v2->vfptr,
    UFG::MultiBodyComponent::_MultiBodyComponentTypeUID,
    "MultiBodyComponent");
  v4 = UFG::MultiBodyComponent::s_MultiBodyComponentList.mNode.mPrev;
  UFG::MultiBodyComponent::s_MultiBodyComponentList.mNode.mPrev->mNext = (UFG::qNode<UFG::MultiBodyComponent,UFG::MultiBodyComponent> *)&v2->mPrev;
  v3->mPrev = v4;
  v2->mNext = (UFG::qNode<UFG::MultiBodyComponent,UFG::MultiBodyComponent> *)&UFG::MultiBodyComponent::s_MultiBodyComponentList;
  UFG::MultiBodyComponent::s_MultiBodyComponentList.mNode.mPrev = (UFG::qNode<UFG::MultiBodyComponent,UFG::MultiBodyComponent> *)&v2->mPrev;
}

// File Line: 98
// RVA: 0x9C5A0
void __fastcall UFG::MultiBodyComponent::~MultiBodyComponent(UFG::MultiBodyComponent *this)
{
  UFG::MultiBodyComponent *v1; // rdi
  UFG::qNode<UFG::MultiBodyComponent,UFG::MultiBodyComponent> *v2; // rsi
  UFG::qNode<UFG::MultiBodyComponent,UFG::MultiBodyComponent> *v3; // rcx
  UFG::qNode<UFG::MultiBodyComponent,UFG::MultiBodyComponent> *v4; // rax
  UFG::qSafePointer<UFG::Constraint,UFG::Constraint> *v5; // rcx
  UFG::Constraint **v6; // rbx
  UFG::qSafePointer<UFG::SimComponent,UFG::RigidBody> *v7; // rcx
  UFG::SimComponent **v8; // rbx
  UFG::qNode<UFG::MultiBodyComponent,UFG::MultiBodyComponent> *v9; // rcx
  UFG::qNode<UFG::MultiBodyComponent,UFG::MultiBodyComponent> *v10; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::MultiBodyComponent::`vftable;
  if ( this == UFG::MultiBodyComponent::s_MultiBodyComponentpCurrentIterator )
    UFG::MultiBodyComponent::s_MultiBodyComponentpCurrentIterator = (UFG::MultiBodyComponent *)&this->mPrev[-4];
  v2 = (UFG::qNode<UFG::MultiBodyComponent,UFG::MultiBodyComponent> *)&this->mPrev;
  v3 = this->mPrev;
  v4 = v2->mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mPrev = v2;
  v2->mNext = v2;
  v5 = v1->mConstraints.p;
  if ( v5 )
  {
    v6 = &v5[-1].m_pPointer;
    `eh vector destructor iterator(
      v5,
      0x18ui64,
      (int)v5[-1].m_pPointer,
      (void (__fastcall *)(void *))UFG::qSafePointer<AnimationGroup,AnimationGroup>::~qSafePointer<AnimationGroup,AnimationGroup>);
    operator delete[](v6);
  }
  v1->mConstraints.p = 0i64;
  *(_QWORD *)&v1->mConstraints.size = 0i64;
  v7 = v1->mBodies.p;
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
  v1->mBodies.p = 0i64;
  *(_QWORD *)&v1->mBodies.size = 0i64;
  v9 = v2->mPrev;
  v10 = v2->mNext;
  v9->mNext = v10;
  v10->mPrev = v9;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::SimComponent::~SimComponent((UFG::SimComponent *)&v1->vfptr);
}

// File Line: 106
// RVA: 0xB4A10
char __fastcall UFG::MultiBodyComponent::UpdateCollisionFiltersForConstraints(UFG::MultiBodyComponent *this)
{
  UFG::MultiBodyComponent *v1; // r13
  char v2; // bl
  char v3; // r12
  unsigned __int64 v4; // rbp
  unsigned __int64 v5; // rax
  char *v6; // rax
  char *v7; // r15
  char *v8; // rdi
  __int64 i; // rcx
  __int64 v10; // r14
  UFG::Constraint *v11; // r11
  UFG::qReflectObject *v12; // rcx
  signed int v13; // esi
  signed __int64 v14; // r9
  signed int v15; // ebx
  signed __int64 v16; // r10
  unsigned int v17; // eax
  signed __int64 v18; // rdx
  hkpConstraintInstance *v19; // r11
  signed __int64 v20; // rdi
  hkpEntity *v21; // r8
  unsigned __int64 v22; // rax
  char *v23; // r13
  signed int v24; // eax
  char *v25; // rcx
  unsigned __int64 v26; // rdx
  UFG::Stack *v28; // rdi
  unsigned int v29; // edx
  int v30; // ecx
  __int64 v31; // rsi
  signed __int64 v32; // r12
  int v33; // er14
  __int64 v34; // rax
  int v35; // ebp
  UFG::SimComponent *v36; // rbx
  UFG::SimObject *v37; // rax
  int v38; // edi
  __int64 v39; // rdx
  UFG::SimComponent *v40; // rdx
  int v41; // ecx
  int v42; // ecx
  int v43; // eax
  int v44; // ecx
  UFG::SimObject *v45; // rax
  hkpEntity *v46; // rdx
  hkpWorld *v47; // rcx
  UFG::qReflectHandleBase v48; // [rsp+28h] [rbp-70h]
  UFG::MultiBodyComponent *v49; // [rsp+A0h] [rbp+8h]
  char v50; // [rsp+A8h] [rbp+10h]
  int v51; // [rsp+B0h] [rbp+18h]
  unsigned __int64 v52; // [rsp+B8h] [rbp+20h]

  v49 = this;
  v1 = this;
  v2 = 1;
  v50 = 1;
  v3 = 0;
  v4 = this->mBodies.size;
  v52 = v4;
  v5 = 4 * v4;
  if ( !is_mul_ok(v4, 4ui64) )
    v5 = -1i64;
  v6 = UFG::qMalloc(v5, UFG::gGlobalNewName, 0i64);
  v7 = v6;
  if ( (_DWORD)v4 )
  {
    v8 = v6;
    for ( i = (unsigned int)v4; i; --i )
    {
      *(_DWORD *)v8 = -1;
      v8 += 4;
    }
  }
  v10 = 0i64;
  if ( !v1->mConstraints.size )
    return v2;
  do
  {
    v11 = v1->mConstraints.p[v10].m_pPointer;
    v12 = 0i64;
    if ( v11->mDefinition.mData )
      v12 = v11->mDefinition.mData;
    if ( BYTE4(v12[1].mBaseNode.mParent) )
    {
      v3 = 1;
      v13 = -1;
      v14 = -1i64;
      v15 = -1;
      v16 = -1i64;
      v17 = 0;
      v18 = 0i64;
      if ( (_DWORD)v4 )
      {
        v19 = v11->mConstraintInstance;
        v20 = (signed __int64)&v1->mBodies.p->m_pPointer;
        do
        {
          v21 = *(hkpEntity **)(*(_QWORD *)v20 + 168i64);
          if ( v21 == v19->m_entities[0] )
          {
            v13 = v17;
            v14 = v18;
          }
          else if ( v21 == v19->m_entities[1] )
          {
            v15 = v17;
            v16 = v18;
          }
          if ( v14 != -1 && v16 != -1 )
            break;
          ++v17;
          ++v18;
          v20 += 24i64;
        }
        while ( v17 < (unsigned int)v4 );
      }
      if ( *(_DWORD *)&v7[4 * v14] == -1 )
      {
        *(_DWORD *)&v7[4 * v14] = v15;
        v2 = v50;
      }
      else if ( *(_DWORD *)&v7[4 * v16] == -1 )
      {
        *(_DWORD *)&v7[4 * v16] = v13;
        v2 = v50;
      }
      else
      {
        v2 = 0;
        v50 = 0;
      }
    }
    v10 = (unsigned int)(v10 + 1);
  }
  while ( (unsigned int)v10 < v1->mConstraints.size );
  if ( !v2 || !v3 )
    return v2;
  v22 = 4 * v4;
  if ( !is_mul_ok(v4, 4ui64) )
    v22 = -1i64;
  v23 = UFG::qMalloc(v22, UFG::gGlobalNewName, 0i64);
  v24 = 1;
  if ( (_DWORD)v4 )
  {
    v25 = v23;
    v26 = v4;
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
  v28 = UFG::BasePhysicsSystem::mInstance->mCollisionFilter->mAssignedSystemGroups;
  v29 = v28->mBuffer[v28->mHead-- - 1];
  if ( !(_DWORD)v4 )
    return v2;
  v30 = 0;
  if ( (unsigned __int16)v29 != -1 )
    v30 = (unsigned __int16)v29;
  v51 = v30 << 6;
  v31 = 0i64;
  v32 = v23 - v7;
  do
  {
    v33 = *(_DWORD *)&v7[v32];
    v34 = *(signed int *)v7;
    if ( (_DWORD)v34 == -1 )
      v35 = 0;
    else
      v35 = *(_DWORD *)&v23[4 * v34];
    v36 = v49->mBodies.p[v31].m_pPointer;
    v37 = v36[2].m_pSimObject;
    if ( v37 )
    {
      v38 = *(_DWORD *)&v37->m_Flags & 0x1F;
    }
    else
    {
      v38 = HIDWORD(v36[4].m_SafePointerList.mNode.mPrev);
      if ( v38 == -1 )
      {
        UFG::qReflectHandleBase::qReflectHandleBase(&v48);
        v48.mTypeUID = UFG::qStringHash64("UFG::PhysicsObjectProperties", 0xFFFFFFFFFFFFFFFFui64);
        v39 = *(_QWORD *)&v36[2].m_Flags;
        if ( v39 )
          UFG::qReflectHandleBase::operator=(&v48, (UFG::qReflectHandleBase *)(v39 + 224));
        if ( v48.mData )
        {
          v38 = (int)v48.mData[2].mBaseNode.mChildren[0];
          UFG::qReflectHandleBase::~qReflectHandleBase(&v48);
        }
        else
        {
          UFG::qReflectHandleBase::~qReflectHandleBase(&v48);
          LOBYTE(v38) = 0;
        }
      }
      else
      {
        LOBYTE(v38) = v38 & 0x1F;
      }
    }
    v40 = v49->mBodies.p[v31].m_pPointer;
    v41 = 0;
    if ( v35 != -1 )
      v41 = v35;
    v42 = 32 * (v51 | v41);
    v43 = 0;
    if ( v33 != -1 )
      v43 = v33;
    v44 = v38 & 0x1F | 32 * (v43 | v42);
    HIDWORD(v40[4].m_SafePointerList.mNode.mPrev) = v44;
    v45 = v40[2].m_pSimObject;
    if ( v45 && *(_DWORD *)&v45->m_Flags != v44 )
    {
      *(_DWORD *)&v45->m_Flags = v44;
      v46 = (hkpEntity *)v40[2].m_pSimObject;
      v47 = v46->m_world;
      if ( v47 )
        hkpWorld::updateCollisionFilterOnEntity(v47, v46, 0, HK_UPDATE_COLLECTION_FILTER_PROCESS_SHAPE_COLLECTIONS);
    }
    v7 += 4;
    ++v31;
    --v52;
  }
  while ( v52 );
  return v50;
}

