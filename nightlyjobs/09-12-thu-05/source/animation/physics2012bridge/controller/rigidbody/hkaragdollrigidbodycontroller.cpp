// File Line: 14
// RVA: 0xC52350
void __fastcall hkaRagdollRigidBodyController::hkaRagdollRigidBodyController(hkaRagdollRigidBodyController *this, hkaRagdollInstance *ragdoll)
{
  int v2; // ebx
  hkaRagdollRigidBodyController *v3; // r15
  hkaRagdollInstance *v4; // rbp
  int v5; // eax
  int v6; // eax
  int v7; // er9
  __int64 v8; // rcx
  __int64 v9; // rdx
  _DWORD *v10; // rax
  hkaKeyFrameHierarchyUtility::ControlData *v11; // rax
  int v12; // er14
  int v13; // eax
  int v14; // eax
  int v15; // eax
  int v16; // er9
  __int64 v17; // rdx
  __int16 *v18; // rdi
  __int64 v19; // rcx
  hkaSkeleton *v20; // rax
  __int64 v21; // r9
  int *v22; // rdi
  __int64 v23; // r10
  __int64 v24; // rcx
  int v25; // edx
  int v26; // eax
  int v27; // eax
  int v28; // er9
  __int64 v29; // rdx
  __int16 *v30; // rdi
  __int64 v31; // rcx
  hkaSkeleton *v32; // rax
  __int64 v33; // rdx
  __int16 v34; // ax
  int v35; // eax
  int v36; // eax
  int v37; // er9
  hkResult result; // [rsp+A0h] [rbp+8h]

  this->m_controlDataPalette.m_capacityAndFlags = 2147483648;
  v2 = 0;
  this->m_controlDataPalette.m_data = 0i64;
  this->m_controlDataPalette.m_size = 0;
  this->m_bodyIndexToPaletteIndex.m_data = 0i64;
  this->m_bodyIndexToPaletteIndex.m_size = 0;
  this->m_bodyIndexToPaletteIndex.m_capacityAndFlags = 2147483648;
  this->m_bodyData.m_controlDataIndices = 0i64;
  this->m_bodyData.m_boneWeights = 0i64;
  this->m_internalData.m_data = 0i64;
  this->m_internalData.m_size = 0;
  this->m_internalData.m_capacityAndFlags = 2147483648;
  this->m_ragdollInstance = ragdoll;
  v3 = this;
  this->m_rbParentIndices.m_data = 0i64;
  this->m_rbParentIndices.m_size = 0;
  this->m_rbParentIndices.m_capacityAndFlags = 2147483648;
  v4 = ragdoll;
  hkReferencedObject::addReference((hkReferencedObject *)&ragdoll->vfptr);
  v5 = v3->m_controlDataPalette.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v5 < 1 )
  {
    v6 = 2 * v5;
    v7 = 1;
    if ( v6 > 1 )
      v7 = v6;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v3, v7, 48);
  }
  v8 = v3->m_controlDataPalette.m_size;
  v9 = 1 - (signed int)v8;
  if ( 1 - (signed int)v8 > 0 )
  {
    v10 = (_DWORD *)&v3->m_controlDataPalette.m_data[v8].m_accelerationGain;
    do
    {
      if ( v10 != (_DWORD *)8 )
      {
        *(v10 - 2) = 1043207291;
        *(v10 - 1) = 0;
        *v10 = 1065353216;
        v10[1] = 1058642330;
        v10[2] = 1028443341;
        v10[3] = 1068708659;
        v10[4] = 1072064102;
        v10[5] = 1036831949;
        v10[6] = 1050253722;
        v10[7] = 1050253722;
        v10[8] = 1022739087;
        v10[9] = 1036831949;
      }
      v10 += 12;
      --v9;
    }
    while ( v9 );
  }
  v3->m_controlDataPalette.m_size = 1;
  v11 = v3->m_controlDataPalette.m_data;
  v11->m_hierarchyGain = FLOAT_0_17;
  v11->m_velocityDamping = 0.0;
  LODWORD(v11->m_accelerationGain) = (_DWORD)FLOAT_1_0;
  v11->m_velocityGain = FLOAT_0_60000002;
  v11->m_positionGain = FLOAT_0_050000001;
  v11->m_positionMaxLinearVelocity = FLOAT_1_4;
  v11->m_positionMaxAngularVelocity = FLOAT_1_8;
  v11->m_snapGain = FLOAT_0_1;
  v11->m_snapMaxLinearVelocity = FLOAT_0_30000001;
  v11->m_snapMaxAngularVelocity = FLOAT_0_30000001;
  v11->m_snapMaxLinearDistance = FLOAT_0_029999999;
  v11->m_snapMaxAngularDistance = FLOAT_0_1;
  v12 = v4->m_rigidBodies.m_size;
  v13 = v3->m_rbParentIndices.m_capacityAndFlags;
  if ( v12 == v4->m_skeleton.m_pntr->m_bones.m_size )
  {
    v26 = v13 & 0x3FFFFFFF;
    if ( v26 < v12 )
    {
      v27 = 2 * v26;
      v28 = v4->m_rigidBodies.m_size;
      if ( v12 < v27 )
        v28 = v27;
      hkArrayUtil::_reserve(
        &result,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &v3->m_rbParentIndices,
        v28,
        2);
    }
    v29 = v3->m_rbParentIndices.m_size;
    v30 = &v3->m_rbParentIndices.m_data[v29];
    v31 = v12 - (signed int)v29;
    if ( v12 - (signed int)v29 > 0 )
    {
      while ( v31 )
      {
        *v30 = -1;
        ++v30;
        --v31;
      }
    }
    v3->m_rbParentIndices.m_size = v12;
    v32 = v4->m_skeleton.m_pntr;
    if ( v32->m_bones.m_size > 0 )
    {
      v33 = 0i64;
      do
      {
        ++v2;
        v34 = v32->m_parentIndices.m_data[v33];
        ++v33;
        v3->m_rbParentIndices.m_data[v33 - 1] = v34;
        v32 = v4->m_skeleton.m_pntr;
      }
      while ( v2 < v32->m_bones.m_size );
    }
  }
  else
  {
    v14 = v13 & 0x3FFFFFFF;
    if ( v14 < v12 )
    {
      v15 = 2 * v14;
      v16 = v4->m_rigidBodies.m_size;
      if ( v12 < v15 )
        v16 = v15;
      hkArrayUtil::_reserve(
        &result,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &v3->m_rbParentIndices,
        v16,
        2);
    }
    v17 = v3->m_rbParentIndices.m_size;
    v18 = &v3->m_rbParentIndices.m_data[v17];
    v19 = v12 - (signed int)v17;
    if ( v12 - (signed int)v17 > 0 )
    {
      while ( v19 )
      {
        *v18 = -1;
        ++v18;
        --v19;
      }
    }
    v3->m_rbParentIndices.m_size = v12;
    v20 = v4->m_skeleton.m_pntr;
    if ( v20->m_bones.m_size > 0 )
    {
      v21 = 0i64;
      do
      {
        v22 = v4->m_boneToRigidBodyMap.m_data;
        v23 = v22[v21];
        if ( (signed int)v23 >= 0 )
        {
          LODWORD(v24) = v2;
          LOWORD(v25) = -1;
          do
          {
            v24 = v20->m_parentIndices.m_data[(signed int)v24];
            if ( (signed int)v24 < 0 )
              break;
            v25 = v22[v24];
          }
          while ( v25 < 0 );
          v3->m_rbParentIndices.m_data[v23] = v25;
        }
        v20 = v4->m_skeleton.m_pntr;
        ++v2;
        ++v21;
      }
      while ( v2 < v20->m_bones.m_size );
    }
  }
  v3->m_bodyData.m_numRigidBodies = v12;
  v3->m_bodyData.m_rigidBodies = v4->m_rigidBodies.m_data;
  v3->m_bodyData.m_parentIndices = v3->m_rbParentIndices.m_data;
  v35 = v3->m_internalData.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v35 < v12 )
  {
    v36 = 2 * v35;
    v37 = v12;
    if ( v12 < v36 )
      v37 = v36;
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v3->m_internalData,
      v37,
      64);
  }
  v3->m_internalData.m_size = v12;
  hkaKeyFrameHierarchyUtility::initialize(&v3->m_bodyData, v3->m_internalData.m_data);
}

// File Line: 65
// RVA: 0xC52730
void __fastcall hkaRagdollRigidBodyController::~hkaRagdollRigidBodyController(hkaRagdollRigidBodyController *this)
{
  hkaRagdollRigidBodyController *v1; // rbx
  int v2; // er8
  int v3; // er8
  int v4; // er8
  int v5; // eax

  v1 = this;
  hkReferencedObject::removeReference((hkReferencedObject *)&this->m_ragdollInstance->vfptr);
  v2 = v1->m_rbParentIndices.m_capacityAndFlags;
  v1->m_rbParentIndices.m_size = 0;
  if ( v2 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_rbParentIndices.m_data,
      2 * (v2 & 0x3FFFFFFF));
  v1->m_rbParentIndices.m_data = 0i64;
  v1->m_rbParentIndices.m_capacityAndFlags = 2147483648;
  v3 = v1->m_internalData.m_capacityAndFlags;
  v1->m_internalData.m_size = 0;
  if ( v3 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_internalData.m_data,
      v3 << 6);
  v1->m_internalData.m_data = 0i64;
  v1->m_internalData.m_capacityAndFlags = 2147483648;
  v4 = v1->m_bodyIndexToPaletteIndex.m_capacityAndFlags;
  v1->m_bodyIndexToPaletteIndex.m_size = 0;
  if ( v4 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_bodyIndexToPaletteIndex.m_data,
      4 * v4);
  v1->m_bodyIndexToPaletteIndex.m_data = 0i64;
  v1->m_bodyIndexToPaletteIndex.m_capacityAndFlags = 2147483648;
  v5 = v1->m_controlDataPalette.m_capacityAndFlags;
  v1->m_controlDataPalette.m_size = 0;
  if ( v5 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_controlDataPalette.m_data,
      48 * (v5 & 0x3FFFFFFF));
  v1->m_controlDataPalette.m_capacityAndFlags = 2147483648;
  v1->m_controlDataPalette.m_data = 0i64;
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
  if ( (signed int)v2 >= 0 )
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
void __fastcall hkaRagdollRigidBodyController::driveToPose(hkaRagdollRigidBodyController *this, float deltaTime, hkQsTransformf *poseLocal, hkQsTransformf *worldFromModel, hkaKeyFrameHierarchyUtility::Output *stressOut)
{
  int v5; // er15
  hkaKeyFrameHierarchyUtility::WorkElem *v6; // rax
  hkQuaternionf v7; // xmm2
  hkVector4f v8; // xmm0
  int v9; // esi
  hkQsTransformf *v10; // rbp
  hkaRagdollRigidBodyController *v11; // rbx
  int *v12; // rax
  hkaRagdollInstance *v13; // rdx
  hkLifoAllocator *v14; // rax
  hkQsTransformf *v15; // rdi
  int v16; // edx
  char *v17; // rcx
  signed int v18; // er14
  __int64 v19; // r9
  hkVector4f *v20; // rdx
  signed __int64 v21; // rax
  signed __int64 v22; // rcx
  hkaKeyFrameHierarchyUtility::ControlData *v23; // r9
  signed int v24; // ebx
  hkLifoAllocator *v25; // rax
  int v26; // er8
  hkaKeyFrameHierarchyUtility::ControlData *v27; // r9
  hkaKeyFrameHierarchyUtility::KeyFrameData pose; // [rsp+30h] [rbp-68h]

  v5 = this->m_bodyData.m_numRigidBodies;
  v6 = this->m_internalData.m_data;
  v7.m_vec.m_quad = (__m128)worldFromModel->m_rotation;
  pose.m_worldFromRoot.m_translation = worldFromModel->m_translation;
  v8.m_quad = (__m128)worldFromModel->m_scale;
  v9 = 0;
  v10 = poseLocal;
  v11 = this;
  pose.m_internalReferencePose = v6;
  pose.m_worldFromRoot.m_scale = (hkVector4f)v8.m_quad;
  pose.m_worldFromRoot.m_rotation = (hkQuaternionf)v7.m_vec.m_quad;
  if ( this->m_bodyIndexToPaletteIndex.m_size == v5 )
    v12 = this->m_bodyIndexToPaletteIndex.m_data;
  else
    v12 = 0i64;
  v13 = this->m_ragdollInstance;
  this->m_bodyData.m_controlDataIndices = v12;
  if ( v13->m_rigidBodies.m_size == v13->m_skeleton.m_pntr->m_bones.m_size )
  {
    v27 = this->m_controlDataPalette.m_data;
    pose.m_desiredPoseLocalSpace = poseLocal;
    hkaKeyFrameHierarchyUtility::applyKeyFrame(deltaTime, &pose, &this->m_bodyData, v27, stressOut);
  }
  else
  {
    if ( v5 )
    {
      v14 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v15 = (hkQsTransformf *)v14->m_cur;
      v16 = (48 * v5 + 127) & 0xFFFFFF80;
      v17 = (char *)v15 + v16;
      if ( v16 > v14->m_slabSize || v17 > v14->m_end )
        v15 = (hkQsTransformf *)hkLifoAllocator::allocateFromNewSlab(v14, v16);
      else
        v14->m_cur = v17;
    }
    else
    {
      v15 = 0i64;
    }
    v18 = v5 | 0x80000000;
    if ( v11->m_ragdollInstance->m_skeleton.m_pntr->m_bones.m_size > 0 )
    {
      v19 = 0i64;
      v20 = &v10->m_scale;
      do
      {
        v21 = v11->m_ragdollInstance->m_boneToRigidBodyMap.m_data[v19];
        if ( (signed int)v21 >= 0 )
        {
          v22 = v21;
          v15[v22].m_translation = (hkVector4f)v20[-2].m_quad;
          v15[v22].m_rotation.m_vec = (hkVector4f)v20[-1].m_quad;
          v15[v22].m_scale = (hkVector4f)v20->m_quad;
        }
        ++v9;
        ++v19;
        v20 += 3;
      }
      while ( v9 < v11->m_ragdollInstance->m_skeleton.m_pntr->m_bones.m_size );
    }
    v23 = v11->m_controlDataPalette.m_data;
    pose.m_desiredPoseLocalSpace = v15;
    hkaKeyFrameHierarchyUtility::applyKeyFrame(deltaTime, &pose, &v11->m_bodyData, v23, stressOut);
    v24 = (48 * v5 + 127) & 0xFFFFFF80;
    v25 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v26 = (v24 + 15) & 0xFFFFFFF0;
    if ( v24 > v25->m_slabSize || (char *)v15 + v26 != v25->m_cur || v25->m_firstNonLifoEnd == v15 )
      hkLifoAllocator::slowBlockFree(v25, v15, v26);
    else
      v25->m_cur = v15;
    if ( v18 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v15,
        48 * (v18 & 0x3FFFFFFF));
  }
}

// File Line: 123
// RVA: 0xC52AE0
void __fastcall hkaRagdollRigidBodyController::setBoneWeights(hkaRagdollRigidBodyController *this, const float *boneWeights)
{
  this->m_bodyData.m_boneWeights = boneWeights;
}

