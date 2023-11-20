// File Line: 20
// RVA: 0x666CC0
void __fastcall UFG::AIVehicleAttachment::AIVehicleAttachment(UFG::AIVehicleAttachment *this, UFG::VehicleAttachment *pOwner, bool inGenerateObstacle)
{
  this->mpOwner = pOwner;
  this->mGenerateObstacle = inGenerateObstacle;
  this->mpObstacle = 0i64;
  this->mEnabled = 0;
  this->mIsStaticTimer = 0.0;
  this->mpDynamicOutline = 0i64;
}

// File Line: 24
// RVA: 0x66C020
void __fastcall UFG::AIVehicleAttachment::~AIVehicleAttachment(UFG::AIVehicleAttachment *this)
{
  if ( this->mEnabled )
    JUMPOUT(this->mGenerateObstacle, 0, UFG::AIVehicleAttachment::Disable);
}

// File Line: 32
// RVA: 0x677600
void __fastcall UFG::AIVehicleAttachment::Enable(UFG::AIVehicleAttachment *this)
{
  UFG::AIVehicleAttachment *v1; // rbx
  UFG::RigidBody *v2; // rcx
  __m128 v3; // xmm6
  __m128 v4; // xmm7
  __m128 v5; // xmm8
  __m128 v6; // xmm9
  __m128 v7; // xmm10
  __m128 v8; // xmm11
  UFG::NavManager *v9; // rbp
  signed __int64 v10; // r8
  char v11; // dl
  __int64 v12; // rax
  char v13; // cl
  _QWORD **v14; // rax
  hkaiSimpleObstacleGenerator *v15; // rax
  __int64 v16; // rax
  __int64 v17; // rdi
  int v18; // eax
  int v19; // eax
  int v20; // er9
  __m128 v21; // xmm4
  __m128 v22; // xmm3
  __m128 v23; // xmm3
  __m128 v24; // xmm3
  __m128 v25; // xmm4
  __m128 v26; // xmm3
  __m128 v27; // xmm3
  __m128 v28; // xmm3
  hkJobType v29; // edx
  UFG::qVector3 aabbMin; // [rsp+38h] [rbp-90h]
  UFG::qVector3 aabbMax; // [rsp+48h] [rbp-80h]
  hkaiSimpleObstacleGenerator *result; // [rsp+D0h] [rbp+8h]

  v1 = this;
  if ( !this->mEnabled )
  {
    if ( this->mGenerateObstacle )
    {
      v2 = (UFG::RigidBody *)this->mpOwner->body.m_pPointer;
      if ( v2 )
      {
        if ( !v1->mpObstacle )
        {
          if ( !UFG::RigidBody::GetAabb(v2, &aabbMin, &aabbMax, LOCAL_AABB) )
            return;
          v3 = (__m128)LODWORD(aabbMin.x);
          v4 = (__m128)LODWORD(aabbMax.x);
          v5 = (__m128)LODWORD(aabbMin.y);
          v6 = (__m128)LODWORD(aabbMax.y);
          v7 = (__m128)LODWORD(aabbMin.z);
          v8 = (__m128)LODWORD(aabbMax.z);
          v9 = UFG::NavManager::ms_pInstance;
          v10 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
          v11 = ++*(_BYTE *)(v10 + 80);
          v12 = v11;
          *(_DWORD *)(v10 + 4 * v12) = 1;
          *(_QWORD *)(v10 + 8 * v12 + 16) = "AI::AIVehicleAttachment::Enable";
          *(_QWORD *)(v10 + 8 * v12 + 48) = 0i64;
          v13 = *(_BYTE *)(v10 + 81);
          if ( v11 > v13 )
            v13 = v11;
          *(_BYTE *)(v10 + 81) = v13;
          v14 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
          v15 = (hkaiSimpleObstacleGenerator *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v14[11] + 8i64))(
                                                 v14[11],
                                                 176i64);
          result = v15;
          if ( v15 )
          {
            hkaiSimpleObstacleGenerator::hkaiSimpleObstacleGenerator(v15);
            v17 = v16;
          }
          else
          {
            v17 = 0i64;
          }
          *(_WORD *)(v17 + 17) = 257;
          v18 = *(_DWORD *)(v17 + 124) & 0x3FFFFFFF;
          if ( v18 < 8 )
          {
            v19 = 2 * v18;
            v20 = 8;
            if ( v19 > 8 )
              v20 = v19;
            hkArrayUtil::_reserve(
              (hkResult *)&result,
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
              (void *)(v17 + 112),
              v20,
              32);
          }
          *(_DWORD *)(v17 + 120) = 8;
          v21 = _mm_unpacklo_ps(_mm_unpacklo_ps(v3, v7), _mm_unpacklo_ps(v5, (__m128)0i64));
          *(__m128 *)*(_QWORD *)(v17 + 112) = v21;
          v22 = _mm_unpacklo_ps(_mm_unpacklo_ps(v4, v7), _mm_unpacklo_ps(v5, (__m128)0i64));
          *(__m128 *)(*(_QWORD *)(v17 + 112) + 16i64) = v22;
          *(__m128 *)(*(_QWORD *)(v17 + 112) + 32i64) = v22;
          v23 = _mm_unpacklo_ps(_mm_unpacklo_ps(v4, v7), _mm_unpacklo_ps(v6, (__m128)0i64));
          *(__m128 *)(*(_QWORD *)(v17 + 112) + 48i64) = v23;
          *(__m128 *)(*(_QWORD *)(v17 + 112) + 64i64) = v23;
          v24 = _mm_unpacklo_ps(_mm_unpacklo_ps(v3, v7), _mm_unpacklo_ps(v6, (__m128)0i64));
          *(__m128 *)(*(_QWORD *)(v17 + 112) + 80i64) = v24;
          *(__m128 *)(*(_QWORD *)(v17 + 112) + 96i64) = v24;
          *(__m128 *)(*(_QWORD *)(v17 + 112) + 112i64) = v21;
          v25 = _mm_unpacklo_ps(_mm_unpacklo_ps(v3, v8), _mm_unpacklo_ps(v5, (__m128)0i64));
          *(__m128 *)(*(_QWORD *)(v17 + 112) + 128i64) = v25;
          v26 = _mm_unpacklo_ps(_mm_unpacklo_ps(v4, v8), _mm_unpacklo_ps(v5, (__m128)0i64));
          *(__m128 *)(*(_QWORD *)(v17 + 112) + 144i64) = v26;
          *(__m128 *)(*(_QWORD *)(v17 + 112) + 160i64) = v26;
          v27 = _mm_unpacklo_ps(_mm_unpacklo_ps(v4, v8), _mm_unpacklo_ps(v6, (__m128)0i64));
          *(__m128 *)(*(_QWORD *)(v17 + 112) + 176i64) = v27;
          *(__m128 *)(*(_QWORD *)(v17 + 112) + 192i64) = v27;
          v28 = _mm_unpacklo_ps(_mm_unpacklo_ps(v3, v8), _mm_unpacklo_ps(v6, (__m128)0i64));
          *(__m128 *)(*(_QWORD *)(v17 + 112) + 208i64) = v28;
          *(__m128 *)(*(_QWORD *)(v17 + 112) + 224i64) = v28;
          *(__m128 *)(*(_QWORD *)(v17 + 112) + 240i64) = v25;
          hkaiSimpleObstacleGenerator::calcAabb((hkaiSimpleObstacleGenerator *)v17);
          hkaiWorld::addObstacleGenerator((hkaiWorld *)v9[3].vfptr, (hkaiObstacleGenerator *)v17);
          HavokJobMemoryPoolTagger::onEndJob((HavokJobMemoryPoolTagger *)CustomHavokMemorySystem::mInstance, v29);
          v1->mpObstacle = (hkaiSimpleObstacleGenerator *)v17;
          v1->mIsStaticTimer = 0.0;
        }
        v1->mEnabled = 1;
      }
    }
  }
}

// File Line: 105
// RVA: 0x676920
void __fastcall UFG::AIVehicleAttachment::Disable(UFG::AIVehicleAttachment *this)
{
  UFG::AIVehicleAttachment *v1; // rbx
  UFG::NavManager *v2; // r9
  hkaiSimpleObstacleGenerator *v3; // rsi
  signed __int64 v4; // rdi
  char v5; // r8
  __int64 v6; // rax
  char v7; // dl
  char v8; // al

  v1 = this;
  if ( this->mEnabled && this->mGenerateObstacle )
  {
    v2 = UFG::NavManager::ms_pInstance;
    v3 = this->mpObstacle;
    if ( v3 )
    {
      v4 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
      v5 = ++*(_BYTE *)(v4 + 80);
      v6 = v5;
      *(_DWORD *)(v4 + 4 * v6) = 1;
      *(_QWORD *)(v4 + 8 * v6 + 16) = "AI::AIVehicleAttachment::Disable";
      *(_QWORD *)(v4 + 8 * v6 + 48) = 0i64;
      v7 = *(_BYTE *)(v4 + 81);
      if ( v5 > v7 )
        v7 = v5;
      *(_BYTE *)(v4 + 81) = v7;
      hkaiWorld::removeObstacleGenerator((hkaiWorld *)v2[3].vfptr, (hkaiObstacleGenerator *)&v3->vfptr);
      hkReferencedObject::removeReference((hkReferencedObject *)&v3->vfptr);
      v1->mpObstacle = 0i64;
      v8 = *(_BYTE *)(v4 + 80);
      if ( v8 > 0 )
      {
        *(_BYTE *)(v4 + 80) = v8 - 1;
      }
      else
      {
        *(_BYTE *)(v4 + 80) = 0;
        *(_DWORD *)v4 = 3;
        *(_QWORD *)(v4 + 16) = 0i64;
        *(_QWORD *)(v4 + 48) = 0i64;
      }
    }
    v1->mEnabled = 0;
  }
  if ( v1->mpDynamicOutline )
  {
    ((void (*)(void))UFG::NavManager::ms_pInstance->vfptr->RemoveDynamicOutline)();
    v1->mpDynamicOutline = 0i64;
    v1->mIsStaticTimer = 0.0;
  }
}

// File Line: 151
// RVA: 0x68EE30
void __fastcall UFG::AIVehicleAttachment::Update(UFG::AIVehicleAttachment *this, UFG::qMatrix44 *targetTransform, float deltaTime)
{
  float v3; // xmm6_4
  UFG::qMatrix44 *v4; // rbp
  UFG::AIVehicleAttachment *v5; // rbx
  UFG::SimComponent *v6; // rcx
  UFG::NavManager *v7; // rsi
  UFG::SimObject *v8; // rcx
  hkaiSimpleObstacleGenerator *v9; // rax
  __m128 v10; // xmm2
  float v11; // xmm1_4
  bool v12; // al
  UFG::qVector3 result; // [rsp+38h] [rbp-60h]
  UFG::qVector3 aabbMax; // [rsp+48h] [rbp-50h]
  UFG::qVector3 aabbMin; // [rsp+58h] [rbp-40h]
  __int64 v16; // [rsp+68h] [rbp-30h]
  __int64 v17; // [rsp+70h] [rbp-28h]

  v3 = deltaTime;
  v4 = targetTransform;
  v5 = this;
  if ( this->mEnabled )
  {
    if ( this->mGenerateObstacle )
    {
      v6 = this->mpOwner->body.m_pPointer;
      if ( v6 )
      {
        v7 = UFG::NavManager::ms_pInstance;
        v8 = v6[2].m_pSimObject;
        v9 = v5->mpObstacle;
        if ( v9 )
        {
          v9->m_transform.m_rotation.m_col0 = (hkVector4f)v8[2].m_UnboundComponentHandles;
          v9->m_transform.m_rotation.m_col1 = *(hkVector4f *)&v8[3].vfptr;
          v9->m_transform.m_rotation.m_col2 = *(hkVector4f *)&v8[3].m_SafePointerList.mNode.mNext;
          v9->m_transform.m_translation = *(hkVector4f *)&v8[3].m_SafePointerWithCallbackList.mNode.mNext;
        }
        UFG::RigidBody::GetVelocity((UFG::RigidBody *)v5->mpOwner->body.m_pPointer, &result);
        v10 = (__m128)LODWORD(result.x);
        v10.m128_f32[0] = (float)((float)(v10.m128_f32[0] * v10.m128_f32[0]) + (float)(result.y * result.y))
                        + (float)(result.z * result.z);
        LODWORD(v11) = (unsigned __int128)_mm_sqrt_ps(v10);
        v12 = UFG::AIVehicleAttachment::msSpeedToActivateSilhouetteThreshold > v11;
        if ( UFG::AIVehicleAttachment::msSpeedToActivateSilhouetteThreshold > v11 )
          v5->mIsStaticTimer = v3 + v5->mIsStaticTimer;
        if ( v5->mpDynamicOutline )
        {
          if ( !v12 )
          {
            ((void (__fastcall *)(UFG::NavManager *))v7->vfptr->RemoveDynamicOutline)(v7);
            v5->mpDynamicOutline = 0i64;
            v5->mIsStaticTimer = 0.0;
          }
        }
        else if ( UFG::AIVehicleAttachment::msTimeToActivateSilhouette < v5->mIsStaticTimer )
        {
          v17 = 0i64;
          v16 = 0i64;
          if ( UFG::RigidBody::GetAabb((UFG::RigidBody *)v5->mpOwner->body.m_pPointer, &aabbMin, &aabbMax, LOCAL_AABB) )
            v5->mpDynamicOutline = (UFG::NavDynamicOutline *)((__int64 (__fastcall *)(UFG::NavManager *, UFG::qMatrix44 *, UFG::qVector3 *, UFG::qVector3 *, _QWORD, _DWORD, signed __int64))v7->vfptr->AddDynamicOutline)(
                                                               v7,
                                                               v4,
                                                               &aabbMin,
                                                               &aabbMax,
                                                               0i64,
                                                               0,
                                                               -2i64);
          v17 = 0i64;
          v16 = 0i64;
        }
      }
    }
  }
}

