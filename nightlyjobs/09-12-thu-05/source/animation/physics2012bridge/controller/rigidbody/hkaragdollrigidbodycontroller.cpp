// File Line: 14
// RVA: 0xC52350
void __fastcall hkaRagdollRigidBodyController::hkaRagdollRigidBodyController(
        hkaRagdollRigidBodyController *this,
        hkaRagdollInstance *ragdoll)
{
  int v2; // ebx
  __int64 m_size; // rcx
  __int64 v6; // rdx
  float *p_m_accelerationGain; // rax
  hkaKeyFrameHierarchyUtility::ControlData *m_data; // rax
  int v9; // r14d
  int m_capacityAndFlags; // eax
  int v11; // eax
  int v12; // eax
  int v13; // r9d
  __int64 v14; // rdx
  __int16 *v15; // rdi
  __int64 v16; // rcx
  hkaSkeleton *v17; // rax
  __int64 v18; // r9
  int *v19; // rdi
  __int64 v20; // r10
  __int64 v21; // rcx
  int v22; // edx
  int v23; // eax
  int v24; // eax
  int v25; // r9d
  __int64 v26; // rdx
  __int16 *v27; // rdi
  __int64 v28; // rcx
  hkaSkeleton *m_pntr; // rax
  __int64 v30; // rdx
  __int16 v31; // ax
  int v32; // eax
  int v33; // eax
  int v34; // r9d
  hkResult result; // [rsp+A0h] [rbp+8h] BYREF

  this->m_controlDataPalette.m_capacityAndFlags = 0x80000000;
  v2 = 0;
  this->m_controlDataPalette.m_data = 0i64;
  this->m_controlDataPalette.m_size = 0;
  this->m_bodyIndexToPaletteIndex.m_data = 0i64;
  this->m_bodyIndexToPaletteIndex.m_size = 0;
  this->m_bodyIndexToPaletteIndex.m_capacityAndFlags = 0x80000000;
  this->m_bodyData.m_controlDataIndices = 0i64;
  this->m_bodyData.m_boneWeights = 0i64;
  this->m_internalData.m_data = 0i64;
  this->m_internalData.m_size = 0;
  this->m_internalData.m_capacityAndFlags = 0x80000000;
  this->m_ragdollInstance = ragdoll;
  this->m_rbParentIndices.m_data = 0i64;
  this->m_rbParentIndices.m_size = 0;
  this->m_rbParentIndices.m_capacityAndFlags = 0x80000000;
  hkReferencedObject::addReference(ragdoll);
  if ( (this->m_controlDataPalette.m_capacityAndFlags & 0x3FFFFFFF) == 0 )
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, this, 1, 48);
  m_size = this->m_controlDataPalette.m_size;
  v6 = 1 - (int)m_size;
  if ( 1 - (int)m_size > 0 )
  {
    p_m_accelerationGain = &this->m_controlDataPalette.m_data[m_size].m_accelerationGain;
    do
    {
      if ( p_m_accelerationGain != (float *)8 )
      {
        *(p_m_accelerationGain - 2) = 0.17;
        *(p_m_accelerationGain - 1) = 0.0;
        *p_m_accelerationGain = 1.0;
        p_m_accelerationGain[1] = 0.60000002;
        p_m_accelerationGain[2] = 0.050000001;
        p_m_accelerationGain[3] = 1.4;
        p_m_accelerationGain[4] = 1.8;
        p_m_accelerationGain[5] = 0.1;
        p_m_accelerationGain[6] = 0.30000001;
        p_m_accelerationGain[7] = 0.30000001;
        p_m_accelerationGain[8] = 0.029999999;
        p_m_accelerationGain[9] = 0.1;
      }
      p_m_accelerationGain += 12;
      --v6;
    }
    while ( v6 );
  }
  this->m_controlDataPalette.m_size = 1;
  m_data = this->m_controlDataPalette.m_data;
  m_data->m_hierarchyGain = FLOAT_0_17;
  m_data->m_velocityDamping = 0.0;
  LODWORD(m_data->m_accelerationGain) = (_DWORD)FLOAT_1_0;
  m_data->m_velocityGain = FLOAT_0_60000002;
  m_data->m_positionGain = FLOAT_0_050000001;
  m_data->m_positionMaxLinearVelocity = FLOAT_1_4;
  m_data->m_positionMaxAngularVelocity = FLOAT_1_8;
  m_data->m_snapGain = FLOAT_0_1;
  m_data->m_snapMaxLinearVelocity = FLOAT_0_30000001;
  m_data->m_snapMaxAngularVelocity = FLOAT_0_30000001;
  m_data->m_snapMaxLinearDistance = FLOAT_0_029999999;
  m_data->m_snapMaxAngularDistance = FLOAT_0_1;
  v9 = ragdoll->m_rigidBodies.m_size;
  m_capacityAndFlags = this->m_rbParentIndices.m_capacityAndFlags;
  if ( v9 == ragdoll->m_skeleton.m_pntr->m_bones.m_size )
  {
    v23 = m_capacityAndFlags & 0x3FFFFFFF;
    if ( v23 < v9 )
    {
      v24 = 2 * v23;
      v25 = ragdoll->m_rigidBodies.m_size;
      if ( v9 < v24 )
        v25 = v24;
      hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &this->m_rbParentIndices, v25, 2);
    }
    v26 = this->m_rbParentIndices.m_size;
    v27 = &this->m_rbParentIndices.m_data[v26];
    v28 = v9 - (int)v26;
    if ( v9 - (int)v26 > 0 )
    {
      while ( v28 )
      {
        *v27++ = -1;
        --v28;
      }
    }
    this->m_rbParentIndices.m_size = v9;
    m_pntr = ragdoll->m_skeleton.m_pntr;
    if ( m_pntr->m_bones.m_size > 0 )
    {
      v30 = 0i64;
      do
      {
        ++v2;
        v31 = m_pntr->m_parentIndices.m_data[v30++];
        this->m_rbParentIndices.m_data[v30 - 1] = v31;
        m_pntr = ragdoll->m_skeleton.m_pntr;
      }
      while ( v2 < m_pntr->m_bones.m_size );
    }
  }
  else
  {
    v11 = m_capacityAndFlags & 0x3FFFFFFF;
    if ( v11 < v9 )
    {
      v12 = 2 * v11;
      v13 = ragdoll->m_rigidBodies.m_size;
      if ( v9 < v12 )
        v13 = v12;
      hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &this->m_rbParentIndices, v13, 2);
    }
    v14 = this->m_rbParentIndices.m_size;
    v15 = &this->m_rbParentIndices.m_data[v14];
    v16 = v9 - (int)v14;
    if ( v9 - (int)v14 > 0 )
    {
      while ( v16 )
      {
        *v15++ = -1;
        --v16;
      }
    }
    this->m_rbParentIndices.m_size = v9;
    v17 = ragdoll->m_skeleton.m_pntr;
    if ( v17->m_bones.m_size > 0 )
    {
      v18 = 0i64;
      do
      {
        v19 = ragdoll->m_boneToRigidBodyMap.m_data;
        v20 = v19[v18];
        if ( (int)v20 >= 0 )
        {
          LODWORD(v21) = v2;
          LOWORD(v22) = -1;
          do
          {
            v21 = v17->m_parentIndices.m_data[(int)v21];
            if ( (int)v21 < 0 )
              break;
            v22 = v19[v21];
          }
          while ( v22 < 0 );
          this->m_rbParentIndices.m_data[v20] = v22;
        }
        v17 = ragdoll->m_skeleton.m_pntr;
        ++v2;
        ++v18;
      }
      while ( v2 < v17->m_bones.m_size );
    }
  }
  this->m_bodyData.m_numRigidBodies = v9;
  this->m_bodyData.m_rigidBodies = ragdoll->m_rigidBodies.m_data;
  this->m_bodyData.m_parentIndices = this->m_rbParentIndices.m_data;
  v32 = this->m_internalData.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v32 < v9 )
  {
    v33 = 2 * v32;
    v34 = v9;
    if ( v9 < v33 )
      v34 = v33;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &this->m_internalData, v34, 64);
  }
  this->m_internalData.m_size = v9;
  hkaKeyFrameHierarchyUtility::initialize(&this->m_bodyData, this->m_internalData.m_data);
}

// File Line: 65
// RVA: 0xC52730
void __fastcall hkaRagdollRigidBodyController::~hkaRagdollRigidBodyController(hkaRagdollRigidBodyController *this)
{
  int m_capacityAndFlags; // r8d
  int v3; // r8d
  int v4; // r8d
  int v5; // eax

  hkReferencedObject::removeReference(this->m_ragdollInstance);
  m_capacityAndFlags = this->m_rbParentIndices.m_capacityAndFlags;
  this->m_rbParentIndices.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_rbParentIndices.m_data,
      2 * (m_capacityAndFlags & 0x3FFFFFFF));
  this->m_rbParentIndices.m_data = 0i64;
  this->m_rbParentIndices.m_capacityAndFlags = 0x80000000;
  v3 = this->m_internalData.m_capacityAndFlags;
  this->m_internalData.m_size = 0;
  if ( v3 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_internalData.m_data,
      v3 << 6);
  this->m_internalData.m_data = 0i64;
  this->m_internalData.m_capacityAndFlags = 0x80000000;
  v4 = this->m_bodyIndexToPaletteIndex.m_capacityAndFlags;
  this->m_bodyIndexToPaletteIndex.m_size = 0;
  if ( v4 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_bodyIndexToPaletteIndex.m_data,
      4 * v4);
  this->m_bodyIndexToPaletteIndex.m_data = 0i64;
  this->m_bodyIndexToPaletteIndex.m_capacityAndFlags = 0x80000000;
  v5 = this->m_controlDataPalette.m_capacityAndFlags;
  this->m_controlDataPalette.m_size = 0;
  if ( v5 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_controlDataPalette.m_data,
      48 * (v5 & 0x3FFFFFFF));
  this->m_controlDataPalette.m_capacityAndFlags = 0x80000000;
  this->m_controlDataPalette.m_data = 0i64;
}

// File Line: 70
// RVA: 0xC52A70
void __fastcall hkaRagdollRigidBodyController::reinitialize(hkaRagdollRigidBodyController *this)
{
  hkaKeyFrameHierarchyUtility::initialize(&this->m_bodyData, this->m_internalData.m_data);
}

// File Line: 75
// RVA: 0xC52A90
void __fastcall hkaRagdollRigidBodyController::reinitialize(hkaRagdollRigidBodyController *this, int boneIndex)
{
  __int64 v2; // r8

  v2 = this->m_ragdollInstance->m_boneToRigidBodyMap.m_data[boneIndex];
  if ( (int)v2 >= 0 )
    hkaKeyFrameHierarchyUtility::initialize(this->m_bodyData.m_rigidBodies[v2], &this->m_internalData.m_data[v2]);
}

// File Line: 84
// RVA: 0xC52AD0
hkaRagdollInstance *__fastcall hkaRagdollRigidBodyController::getRagdollInstance(hkaRagdollRigidBodyController *this)
{
  return this->m_ragdollInstance;
}

// File Line: 89
// RVA: 0xC52840
void __fastcall hkaRagdollRigidBodyController::driveToPose(
        hkaRagdollRigidBodyController *this,
        float deltaTime,
        hkQsTransformf *poseLocal,
        hkQsTransformf *worldFromModel,
        hkaKeyFrameHierarchyUtility::Output *stressOut)
{
  int m_numRigidBodies; // r15d
  hkaKeyFrameHierarchyUtility::WorkElem *m_data; // rax
  hkQuaternionf v7; // xmm2
  hkVector4f v8; // xmm0
  int v9; // esi
  int *v12; // rax
  hkaRagdollInstance *m_ragdollInstance; // rdx
  hkLifoAllocator *Value; // rax
  hkQsTransformf *m_cur; // rdi
  int v16; // edx
  char *v17; // rcx
  __int64 v18; // r9
  hkVector4f *p_m_scale; // rdx
  __int64 v20; // rax
  __int64 v21; // rcx
  hkaKeyFrameHierarchyUtility::ControlData *v22; // r9
  signed int v23; // ebx
  hkLifoAllocator *v24; // rax
  int v25; // r8d
  hkaKeyFrameHierarchyUtility::ControlData *v26; // r9
  hkaKeyFrameHierarchyUtility::KeyFrameData pose; // [rsp+30h] [rbp-68h] BYREF

  m_numRigidBodies = this->m_bodyData.m_numRigidBodies;
  m_data = this->m_internalData.m_data;
  v7.m_vec.m_quad = (__m128)worldFromModel->m_rotation;
  pose.m_worldFromRoot.m_translation = worldFromModel->m_translation;
  v8.m_quad = (__m128)worldFromModel->m_scale;
  v9 = 0;
  pose.m_internalReferencePose = m_data;
  pose.m_worldFromRoot.m_scale = (hkVector4f)v8.m_quad;
  pose.m_worldFromRoot.m_rotation = (hkQuaternionf)v7.m_vec.m_quad;
  if ( this->m_bodyIndexToPaletteIndex.m_size == m_numRigidBodies )
    v12 = this->m_bodyIndexToPaletteIndex.m_data;
  else
    v12 = 0i64;
  m_ragdollInstance = this->m_ragdollInstance;
  this->m_bodyData.m_controlDataIndices = v12;
  if ( m_ragdollInstance->m_rigidBodies.m_size == m_ragdollInstance->m_skeleton.m_pntr->m_bones.m_size )
  {
    v26 = this->m_controlDataPalette.m_data;
    pose.m_desiredPoseLocalSpace = poseLocal;
    hkaKeyFrameHierarchyUtility::applyKeyFrame(deltaTime, &pose, &this->m_bodyData, v26, stressOut);
  }
  else
  {
    if ( m_numRigidBodies )
    {
      Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      m_cur = (hkQsTransformf *)Value->m_cur;
      v16 = (48 * m_numRigidBodies + 127) & 0xFFFFFF80;
      v17 = (char *)m_cur + v16;
      if ( v16 > Value->m_slabSize || v17 > Value->m_end )
        m_cur = (hkQsTransformf *)hkLifoAllocator::allocateFromNewSlab(Value, v16);
      else
        Value->m_cur = v17;
    }
    else
    {
      m_cur = 0i64;
    }
    if ( this->m_ragdollInstance->m_skeleton.m_pntr->m_bones.m_size > 0 )
    {
      v18 = 0i64;
      p_m_scale = &poseLocal->m_scale;
      do
      {
        v20 = this->m_ragdollInstance->m_boneToRigidBodyMap.m_data[v18];
        if ( (int)v20 >= 0 )
        {
          v21 = v20;
          m_cur[v21].m_translation = (hkVector4f)p_m_scale[-2].m_quad;
          m_cur[v21].m_rotation.m_vec = (hkVector4f)p_m_scale[-1].m_quad;
          m_cur[v21].m_scale = (hkVector4f)p_m_scale->m_quad;
        }
        ++v9;
        ++v18;
        p_m_scale += 3;
      }
      while ( v9 < this->m_ragdollInstance->m_skeleton.m_pntr->m_bones.m_size );
    }
    v22 = this->m_controlDataPalette.m_data;
    pose.m_desiredPoseLocalSpace = m_cur;
    hkaKeyFrameHierarchyUtility::applyKeyFrame(deltaTime, &pose, &this->m_bodyData, v22, stressOut);
    v23 = (48 * m_numRigidBodies + 127) & 0xFFFFFF80;
    v24 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v25 = (v23 + 15) & 0xFFFFFFF0;
    if ( v23 > v24->m_slabSize || (char *)m_cur + v25 != v24->m_cur || v24->m_firstNonLifoEnd == m_cur )
      hkLifoAllocator::slowBlockFree(v24, m_cur, v25);
    else
      v24->m_cur = m_cur;
  }
}

// File Line: 123
// RVA: 0xC52AE0
void __fastcall hkaRagdollRigidBodyController::setBoneWeights(
        hkaRagdollRigidBodyController *this,
        const float *boneWeights)
{
  this->m_bodyData.m_boneWeights = boneWeights;
}

