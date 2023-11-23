// File Line: 19
// RVA: 0x98AD0
void __fastcall DetectRagdollPenetration::DetectRagdollPenetration(
        DetectRagdollPenetration *this,
        DetectRagdollPenetration::Setup *setup)
{
  int m_size; // esi
  int v4; // eax
  int v5; // eax
  int v6; // r9d
  int v7; // edx
  DetectRagdollPenetration::BonePenetrationStatus *v8; // rax
  __int64 v9; // rcx
  hkResult result; // [rsp+68h] [rbp+10h] BYREF

  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
  this->vfptr = (hkBaseObjectVtbl *)&hkReferencedObject::`vftable;
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&DetectRagdollPenetration::`vftable;
  this->m_setup = *setup;
  this->m_boneStates.m_data = 0i64;
  this->m_boneStates.m_size = 0;
  this->m_boneStates.m_capacityAndFlags = 0x80000000;
  m_size = this->m_setup.m_ragdollSkeleton->m_bones.m_size;
  this->m_numBones = m_size;
  v4 = this->m_boneStates.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v4 < m_size )
  {
    v5 = 2 * v4;
    v6 = m_size;
    if ( m_size < v5 )
      v6 = v5;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &this->m_boneStates, v6, 4);
  }
  v7 = m_size - this->m_boneStates.m_size;
  v8 = &this->m_boneStates.m_data[this->m_boneStates.m_size];
  v9 = v7;
  if ( v7 > 0 )
  {
    do
    {
      if ( v8 )
        *v8 = HK_YESP;
      ++v8;
      --v9;
    }
    while ( v9 );
  }
  this->m_boneStates.m_size = m_size;
  this->m_ragdollIsOut.m_bool = 0;
}

// File Line: 57
// RVA: 0xB7A40
hkBool *__fastcall DetectRagdollPenetration::detectPenetration(
        DetectRagdollPenetration *this,
        hkBool *result,
        hkaPose *ragdollPoseIn,
        DetectRagdollPenetration::Output *output)
{
  int v8; // esi
  __int16 v9; // r14
  __int64 v10; // r8
  hkQsTransformf *v11; // rax
  __m128 m_quad; // xmm6
  hkQsTransformf *v13; // rax
  __m128 v14; // xmm2
  __int16 v15; // r14
  __int64 v16; // r12
  __int128 *v17; // rax
  __int128 *v18; // rax
  __int128 v19; // xmm6
  __int128 v20; // xmm7
  __int64 m_size; // rax
  bool v22; // zf
  DetectRagdollPenetration::BonePenetration *v23; // rcx
  int v24; // edx
  __int64 v25; // rcx
  int v26; // eax
  int v27; // edi
  __int64 v28; // rsi
  __int64 m_boneBeginIndex; // rdx
  DetectRagdollPenetration::BonePenetrationStatus *m_data; // rax
  int v31; // edx
  int v32; // r9d
  __int64 v33; // r8
  __int64 v34; // rcx
  DetectRagdollPenetration::BonePenetrationStatus *v35; // rax
  hkAabb newAabb; // [rsp+18h] [rbp-59h] BYREF
  __int128 v38; // [rsp+38h] [rbp-39h] BYREF
  __int128 v39; // [rsp+48h] [rbp-29h] BYREF
  __int128 v40; // [rsp+58h] [rbp-19h] BYREF
  __int128 v41[5]; // [rsp+68h] [rbp-9h] BYREF
  char v42[8]; // [rsp+D8h] [rbp+67h] BYREF
  hkBool *v43; // [rsp+E0h] [rbp+6Fh]
  DetectRagdollPenetration::BonePenetration *v44; // [rsp+F0h] [rbp+7Fh]

  output->m_penetrations.m_size = 0;
  v8 = 1;
  if ( !this->m_ragdollIsOut.m_bool )
  {
    newAabb.m_min = (hkVector4f)xmmword_141A712A0;
    newAabb.m_max.m_quad = _mm_xor_ps(
                             (__m128)xmmword_141A712A0,
                             (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0));
    v9 = 1;
    if ( this->m_numBones > 1 )
    {
      do
      {
        v10 = this->m_setup.m_ragdollSkeleton->m_parentIndices.m_data[v9];
        if ( this->m_boneStates.m_data[v10] )
        {
          if ( (ragdollPoseIn->m_boneFlags.m_data[(__int16)v10] & 2) != 0 )
            v11 = hkaPose::calculateBoneModelSpace(ragdollPoseIn, (__int16)v10);
          else
            v11 = &ragdollPoseIn->m_modelPose.m_data[(__int16)v10];
          m_quad = v11->m_translation.m_quad;
          if ( (ragdollPoseIn->m_boneFlags.m_data[v8] & 2) != 0 )
            v13 = hkaPose::calculateBoneModelSpace(ragdollPoseIn, v8);
          else
            v13 = &ragdollPoseIn->m_modelPose.m_data[v8];
          v14 = v13->m_translation.m_quad;
          newAabb.m_min.m_quad = _mm_min_ps(_mm_min_ps(newAabb.m_min.m_quad, m_quad), v13->m_translation.m_quad);
          newAabb.m_max.m_quad = _mm_max_ps(_mm_max_ps(newAabb.m_max.m_quad, m_quad), v14);
        }
        v8 = ++v9;
      }
      while ( v9 < this->m_numBones );
      v8 = 1;
    }
    if ( hkAabb::isValid(&newAabb) )
      hkpAabbPhantom::setAabb(this->m_setup.m_ragdollPhantom, &newAabb);
    v15 = 1;
    if ( this->m_numBones > 1 )
    {
      do
      {
        v16 = this->m_setup.m_ragdollSkeleton->m_parentIndices.m_data[v15];
        if ( this->m_boneStates.m_data[v16] )
        {
          v17 = (__int128 *)((ragdollPoseIn->m_boneFlags.m_data[(__int16)v16] & 2) != 0
                           ? hkaPose::calculateBoneModelSpace(ragdollPoseIn, (__int16)v16)
                           : &ragdollPoseIn->m_modelPose.m_data[(__int16)v16]);
          v39 = *v17;
          v18 = (__int128 *)((ragdollPoseIn->m_boneFlags.m_data[v8] & 2) != 0
                           ? hkaPose::calculateBoneModelSpace(ragdollPoseIn, v8)
                           : &ragdollPoseIn->m_modelPose.m_data[v8]);
          v38 = *v18;
          this->m_setup.m_raycastInterface->vfptr->castRay(
            this->m_setup.m_raycastInterface,
            (hkBool *)v42,
            this->m_setup.m_ragdollPhantom,
            (hkVector4f *)&v39,
            (hkVector4f *)&v38,
            (hkVector4f *)&v40,
            (hkVector4f *)v41);
          if ( v42[0] )
          {
            v19 = v40;
            v20 = v41[0];
            if ( output->m_penetrations.m_size == (output->m_penetrations.m_capacityAndFlags & 0x3FFFFFFF) )
              hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, output, 48);
            m_size = output->m_penetrations.m_size;
            v22 = &output->m_penetrations.m_data[m_size] == 0;
            v23 = &output->m_penetrations.m_data[m_size];
            v44 = v23;
            newAabb.m_min.m_quad.m128_u64[0] = (unsigned __int64)v23;
            if ( !v22 )
            {
              v23->m_boneBeginIndex = v16;
              v23->m_boneEndIndex = v15;
              v23->m_penetrationPoint = (hkVector4f)v19;
              v23->m_penetrationNormal = (hkVector4f)v20;
            }
            ++output->m_penetrations.m_size;
          }
        }
        v8 = ++v15;
      }
      while ( v15 < this->m_numBones );
    }
  }
  v24 = 0;
  if ( this->m_boneStates.m_size > 0 )
  {
    v25 = 0i64;
    do
    {
      this->m_boneStates.m_data[v25] = HK_NOP;
      ++v24;
      ++v25;
    }
    while ( v24 < this->m_boneStates.m_size );
  }
  v26 = output->m_penetrations.m_size;
  if ( v26 )
  {
    v27 = 0;
    if ( v26 > 0 )
    {
      v28 = 0i64;
      do
      {
        m_boneBeginIndex = output->m_penetrations.m_data[v28].m_boneBeginIndex;
        m_data = this->m_boneStates.m_data;
        if ( m_data[m_boneBeginIndex] != HK_YESP_DESCENDANT )
          m_data[m_boneBeginIndex] = HK_YESP;
        newAabb.m_min.m_quad.m128_u64[0] = 0i64;
        newAabb.m_min.m_quad.m128_u64[1] = 0x8000000000000000ui64;
        hkaSkeletonUtils::getDescendants(
          this->m_setup.m_ragdollSkeleton,
          m_boneBeginIndex,
          (hkArray<short,hkContainerHeapAllocator> *)&newAabb,
          0);
        v31 = 0;
        v32 = newAabb.m_min.m_quad.m128_i32[2];
        if ( newAabb.m_min.m_quad.m128_i32[2] > 0 )
        {
          v33 = 0i64;
          do
          {
            v34 = *(__int16 *)(newAabb.m_min.m_quad.m128_u64[0] + v33);
            v35 = this->m_boneStates.m_data;
            if ( v35[v34] != HK_YESP_DESCENDANT )
            {
              v35[v34] = HK_YESP_DESCENDANT;
              v32 = newAabb.m_min.m_quad.m128_i32[2];
            }
            ++v31;
            v33 += 2i64;
          }
          while ( v31 < v32 );
        }
        newAabb.m_min.m_quad.m128_i32[2] = 0;
        if ( newAabb.m_min.m_quad.m128_i32[3] >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            &hkContainerHeapAllocator::s_alloc,
            (void *)newAabb.m_min.m_quad.m128_u64[0],
            2 * (newAabb.m_min.m_quad.m128_i32[3] & 0x3FFFFFFF));
        newAabb.m_min.m_quad.m128_u64[0] = 0i64;
        newAabb.m_min.m_quad.m128_i32[3] = 0x80000000;
        ++v27;
        ++v28;
      }
      while ( v27 < output->m_penetrations.m_size );
      result = v43;
    }
    result->m_bool = 1;
  }
  else
  {
    this->m_ragdollIsOut.m_bool = 1;
    result->m_bool = 0;
  }
  return result;
}

