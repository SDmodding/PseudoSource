// File Line: 20
// RVA: 0x666CC0
void __fastcall UFG::AIVehicleAttachment::AIVehicleAttachment(
        UFG::AIVehicleAttachment *this,
        UFG::VehicleAttachment *pOwner,
        bool inGenerateObstacle)
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
  if ( this->mEnabled && this->mGenerateObstacle )
    UFG::AIVehicleAttachment::Disable(this);
}

// File Line: 32
// RVA: 0x677600
void __fastcall UFG::AIVehicleAttachment::Enable(UFG::AIVehicleAttachment *this)
{
  UFG::RigidBody *m_pPointer; // rcx
  __m128 x_low; // xmm6
  __m128 v4; // xmm7
  __m128 y_low; // xmm8
  __m128 v6; // xmm9
  __m128 z_low; // xmm10
  __m128 v8; // xmm11
  UFG::NavManager *v9; // rbp
  __int64 v10; // r8
  char v11; // dl
  char v12; // cl
  _QWORD **Value; // rax
  hkaiSimpleObstacleGenerator *v14; // rax
  __int64 v15; // rax
  __int64 v16; // rdi
  int v17; // r9d
  __m128 v18; // xmm4
  __m128 v19; // xmm3
  __m128 v20; // xmm3
  __m128 v21; // xmm3
  __m128 v22; // xmm4
  __m128 v23; // xmm3
  __m128 v24; // xmm3
  __m128 v25; // xmm3
  hkJobType v26; // edx
  UFG::qVector3 aabbMin; // [rsp+38h] [rbp-90h] BYREF
  UFG::qVector3 aabbMax; // [rsp+48h] [rbp-80h] BYREF
  hkaiSimpleObstacleGenerator *result; // [rsp+D0h] [rbp+8h] BYREF

  if ( !this->mEnabled && this->mGenerateObstacle )
  {
    m_pPointer = (UFG::RigidBody *)this->mpOwner->body.m_pPointer;
    if ( m_pPointer )
    {
      if ( !this->mpObstacle )
      {
        if ( !UFG::RigidBody::GetAabb(m_pPointer, &aabbMin, &aabbMax, LOCAL_AABB) )
          return;
        x_low = (__m128)LODWORD(aabbMin.x);
        v4 = (__m128)LODWORD(aabbMax.x);
        y_low = (__m128)LODWORD(aabbMin.y);
        v6 = (__m128)LODWORD(aabbMax.y);
        z_low = (__m128)LODWORD(aabbMin.z);
        v8 = (__m128)LODWORD(aabbMax.z);
        v9 = UFG::NavManager::ms_pInstance;
        v10 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
        v11 = ++*(_BYTE *)(v10 + 80);
        *(_DWORD *)(v10 + 4i64 * v11) = 1;
        *(_QWORD *)(v10 + 8i64 * v11 + 16) = "AI::AIVehicleAttachment::Enable";
        *(_QWORD *)(v10 + 8i64 * v11 + 48) = 0i64;
        v12 = *(_BYTE *)(v10 + 81);
        if ( v11 > v12 )
          v12 = v11;
        *(_BYTE *)(v10 + 81) = v12;
        Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v14 = (hkaiSimpleObstacleGenerator *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(
                                               Value[11],
                                               176i64);
        result = v14;
        if ( v14 )
        {
          hkaiSimpleObstacleGenerator::hkaiSimpleObstacleGenerator(v14);
          v16 = v15;
        }
        else
        {
          v16 = 0i64;
        }
        *(_WORD *)(v16 + 17) = 257;
        if ( (*(_DWORD *)(v16 + 124) & 0x3FFFFFFFu) < 8 )
        {
          v17 = 8;
          if ( 2 * (*(_DWORD *)(v16 + 124) & 0x3FFFFFFF) > 8 )
            v17 = 2 * (*(_DWORD *)(v16 + 124) & 0x3FFFFFFF);
          hkArrayUtil::_reserve((hkResult *)&result, &hkContainerHeapAllocator::s_alloc, (void *)(v16 + 112), v17, 32);
        }
        *(_DWORD *)(v16 + 120) = 8;
        v18 = _mm_unpacklo_ps(_mm_unpacklo_ps(x_low, z_low), _mm_unpacklo_ps(y_low, (__m128)0i64));
        *(__m128 *)*(_QWORD *)(v16 + 112) = v18;
        v19 = _mm_unpacklo_ps(_mm_unpacklo_ps(v4, z_low), _mm_unpacklo_ps(y_low, (__m128)0i64));
        *(__m128 *)(*(_QWORD *)(v16 + 112) + 16i64) = v19;
        *(__m128 *)(*(_QWORD *)(v16 + 112) + 32i64) = v19;
        v20 = _mm_unpacklo_ps(_mm_unpacklo_ps(v4, z_low), _mm_unpacklo_ps(v6, (__m128)0i64));
        *(__m128 *)(*(_QWORD *)(v16 + 112) + 48i64) = v20;
        *(__m128 *)(*(_QWORD *)(v16 + 112) + 64i64) = v20;
        v21 = _mm_unpacklo_ps(_mm_unpacklo_ps(x_low, z_low), _mm_unpacklo_ps(v6, (__m128)0i64));
        *(__m128 *)(*(_QWORD *)(v16 + 112) + 80i64) = v21;
        *(__m128 *)(*(_QWORD *)(v16 + 112) + 96i64) = v21;
        *(__m128 *)(*(_QWORD *)(v16 + 112) + 112i64) = v18;
        v22 = _mm_unpacklo_ps(_mm_unpacklo_ps(x_low, v8), _mm_unpacklo_ps(y_low, (__m128)0i64));
        *(__m128 *)(*(_QWORD *)(v16 + 112) + 128i64) = v22;
        v23 = _mm_unpacklo_ps(_mm_unpacklo_ps(v4, v8), _mm_unpacklo_ps(y_low, (__m128)0i64));
        *(__m128 *)(*(_QWORD *)(v16 + 112) + 144i64) = v23;
        *(__m128 *)(*(_QWORD *)(v16 + 112) + 160i64) = v23;
        v24 = _mm_unpacklo_ps(_mm_unpacklo_ps(v4, v8), _mm_unpacklo_ps(v6, (__m128)0i64));
        *(__m128 *)(*(_QWORD *)(v16 + 112) + 176i64) = v24;
        *(__m128 *)(*(_QWORD *)(v16 + 112) + 192i64) = v24;
        v25 = _mm_unpacklo_ps(_mm_unpacklo_ps(x_low, v8), _mm_unpacklo_ps(v6, (__m128)0i64));
        *(__m128 *)(*(_QWORD *)(v16 + 112) + 208i64) = v25;
        *(__m128 *)(*(_QWORD *)(v16 + 112) + 224i64) = v25;
        *(__m128 *)(*(_QWORD *)(v16 + 112) + 240i64) = v22;
        hkaiSimpleObstacleGenerator::calcAabb((hkaiSimpleObstacleGenerator *)v16);
        hkaiWorld::addObstacleGenerator((hkaiWorld *)v9[3].vfptr, (hkaiObstacleGenerator *)v16);
        HavokJobMemoryPoolTagger::onEndJob((HavokJobMemoryPoolTagger *)CustomHavokMemorySystem::mInstance, v26);
        this->mpObstacle = (hkaiSimpleObstacleGenerator *)v16;
        this->mIsStaticTimer = 0.0;
      }
      this->mEnabled = 1;
    }
  }
}

// File Line: 105
// RVA: 0x676920
void __fastcall UFG::AIVehicleAttachment::Disable(UFG::AIVehicleAttachment *this)
{
  UFG::NavManager *v2; // r9
  hkaiSimpleObstacleGenerator *mpObstacle; // rsi
  __int64 v4; // rdi
  char v5; // r8
  char v6; // dl
  char v7; // al

  if ( this->mEnabled && this->mGenerateObstacle )
  {
    v2 = UFG::NavManager::ms_pInstance;
    mpObstacle = this->mpObstacle;
    if ( mpObstacle )
    {
      v4 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
      v5 = ++*(_BYTE *)(v4 + 80);
      *(_DWORD *)(v4 + 4i64 * v5) = 1;
      *(_QWORD *)(v4 + 8i64 * v5 + 16) = "AI::AIVehicleAttachment::Disable";
      *(_QWORD *)(v4 + 8i64 * v5 + 48) = 0i64;
      v6 = *(_BYTE *)(v4 + 81);
      if ( v5 > v6 )
        v6 = v5;
      *(_BYTE *)(v4 + 81) = v6;
      hkaiWorld::removeObstacleGenerator((hkaiWorld *)v2[3].vfptr, mpObstacle);
      hkReferencedObject::removeReference(mpObstacle);
      this->mpObstacle = 0i64;
      v7 = *(_BYTE *)(v4 + 80);
      if ( v7 > 0 )
      {
        *(_BYTE *)(v4 + 80) = v7 - 1;
      }
      else
      {
        *(_BYTE *)(v4 + 80) = 0;
        *(_DWORD *)v4 = 3;
        *(_QWORD *)(v4 + 16) = 0i64;
        *(_QWORD *)(v4 + 48) = 0i64;
      }
    }
    this->mEnabled = 0;
  }
  if ( this->mpDynamicOutline )
  {
    ((void (__fastcall *)(UFG::NavManager *))UFG::NavManager::ms_pInstance->vfptr->RemoveDynamicOutline)(UFG::NavManager::ms_pInstance);
    this->mpDynamicOutline = 0i64;
    this->mIsStaticTimer = 0.0;
  }
}

// File Line: 151
// RVA: 0x68EE30
void __fastcall UFG::AIVehicleAttachment::Update(
        UFG::AIVehicleAttachment *this,
        UFG::qMatrix44 *targetTransform,
        float deltaTime)
{
  UFG::SimComponent *m_pPointer; // rcx
  UFG::NavManager *v7; // rsi
  UFG::SimObject *m_pSimObject; // rcx
  hkaiSimpleObstacleGenerator *mpObstacle; // rax
  __m128 x_low; // xmm2
  float v11; // xmm1_4
  bool v12; // al
  UFG::qVector3 result; // [rsp+38h] [rbp-60h] BYREF
  UFG::qVector3 aabbMax; // [rsp+48h] [rbp-50h] BYREF
  UFG::qVector3 aabbMin; // [rsp+58h] [rbp-40h] BYREF
  __int64 v16; // [rsp+68h] [rbp-30h]
  __int64 v17; // [rsp+70h] [rbp-28h]

  if ( this->mEnabled && this->mGenerateObstacle )
  {
    m_pPointer = this->mpOwner->body.m_pPointer;
    if ( m_pPointer )
    {
      v7 = UFG::NavManager::ms_pInstance;
      m_pSimObject = m_pPointer[2].m_pSimObject;
      mpObstacle = this->mpObstacle;
      if ( mpObstacle )
      {
        mpObstacle->m_transform.m_rotation.m_col0 = (hkVector4f)m_pSimObject[2].m_UnboundComponentHandles;
        mpObstacle->m_transform.m_rotation.m_col1 = *(hkVector4f *)&m_pSimObject[3].vfptr;
        mpObstacle->m_transform.m_rotation.m_col2 = *(hkVector4f *)&m_pSimObject[3].m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mNext;
        mpObstacle->m_transform.m_translation = *(hkVector4f *)&m_pSimObject[3].m_SafePointerWithCallbackList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::mNode.mNext;
      }
      UFG::RigidBody::GetVelocity((UFG::RigidBody *)this->mpOwner->body.m_pPointer, &result);
      x_low = (__m128)LODWORD(result.x);
      x_low.m128_f32[0] = (float)((float)(x_low.m128_f32[0] * x_low.m128_f32[0]) + (float)(result.y * result.y))
                        + (float)(result.z * result.z);
      v11 = _mm_sqrt_ps(x_low).m128_f32[0];
      v12 = UFG::AIVehicleAttachment::msSpeedToActivateSilhouetteThreshold > v11;
      if ( UFG::AIVehicleAttachment::msSpeedToActivateSilhouetteThreshold > v11 )
        this->mIsStaticTimer = deltaTime + this->mIsStaticTimer;
      if ( this->mpDynamicOutline )
      {
        if ( !v12 )
        {
          ((void (__fastcall *)(UFG::NavManager *))v7->vfptr->RemoveDynamicOutline)(v7);
          this->mpDynamicOutline = 0i64;
          this->mIsStaticTimer = 0.0;
        }
      }
      else if ( UFG::AIVehicleAttachment::msTimeToActivateSilhouette < this->mIsStaticTimer )
      {
        v17 = 0i64;
        v16 = 0i64;
        if ( UFG::RigidBody::GetAabb((UFG::RigidBody *)this->mpOwner->body.m_pPointer, &aabbMin, &aabbMax, LOCAL_AABB) )
          this->mpDynamicOutline = (UFG::NavDynamicOutline *)((__int64 (__fastcall *)(UFG::NavManager *, UFG::qMatrix44 *, UFG::qVector3 *, UFG::qVector3 *, _QWORD, _DWORD, __int64))v7->vfptr->AddDynamicOutline)(
                                                               v7,
                                                               targetTransform,
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

