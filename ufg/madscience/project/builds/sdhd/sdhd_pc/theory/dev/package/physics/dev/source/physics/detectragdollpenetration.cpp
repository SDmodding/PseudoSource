// File Line: 19
// RVA: 0x98AD0
void __fastcall DetectRagdollPenetration::DetectRagdollPenetration(DetectRagdollPenetration *this, DetectRagdollPenetration::Setup *setup)
{
  DetectRagdollPenetration *v2; // rbx
  int v3; // esi
  int v4; // eax
  int v5; // eax
  int v6; // er9
  int v7; // edx
  DetectRagdollPenetration::BonePenetrationStatus *v8; // rax
  __int64 v9; // rcx
  hkResult result; // [rsp+68h] [rbp+10h]

  v2 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable';
  this->vfptr = (hkBaseObjectVtbl *)&hkReferencedObject::`vftable';
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&DetectRagdollPenetration::`vftable';
  this->m_setup = *setup;
  this->m_boneStates.m_data = 0i64;
  this->m_boneStates.m_size = 0;
  this->m_boneStates.m_capacityAndFlags = 2147483648;
  v3 = this->m_setup.m_ragdollSkeleton->m_bones.m_size;
  this->m_numBones = v3;
  v4 = this->m_boneStates.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v4 < v3 )
  {
    v5 = 2 * v4;
    v6 = v3;
    if ( v3 < v5 )
      v6 = v5;
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &this->m_boneStates,
      v6,
      4);
  }
  v7 = v3 - v2->m_boneStates.m_size;
  v8 = &v2->m_boneStates.m_data[v2->m_boneStates.m_size];
  v9 = v7;
  if ( v7 > 0 )
  {
    do
    {
      if ( v8 )
        *v8 = 1;
      ++v8;
      --v9;
    }
    while ( v9 );
  }
  v2->m_boneStates.m_size = v3;
  v2->m_ragdollIsOut.m_bool = 0;
}

// File Line: 57
// RVA: 0xB7A40
hkBool *__fastcall DetectRagdollPenetration::detectPenetration(DetectRagdollPenetration *this, hkBool *result, hkaPose *ragdollPoseIn, DetectRagdollPenetration::Output *output)
{
  DetectRagdollPenetration::Output *v4; // r15
  hkaPose *v5; // rdi
  hkBool *v6; // r13
  DetectRagdollPenetration *v7; // rbx
  int v8; // esi
  signed __int16 v9; // r14
  __int64 v10; // r8
  hkQsTransformf *v11; // rax
  __m128 v12; // xmm6
  hkQsTransformf *v13; // rax
  __m128 v14; // xmm2
  signed __int16 v15; // r14
  __int64 v16; // r12
  __int128 *v17; // rax
  __int128 *v18; // rax
  hkaRagdollRaycastInterface *v19; // rcx
  hkaRagdollRaycastInterfaceVtbl *v20; // rax
  __int128 v21; // xmm6
  __int128 v22; // xmm7
  __int64 v23; // rax
  bool v24; // zf
  signed __int64 v25; // rcx
  int v26; // edx
  __int64 v27; // rcx
  int v28; // eax
  int v29; // edi
  __int64 v30; // rsi
  __int64 v31; // rdx
  DetectRagdollPenetration::BonePenetrationStatus *v32; // rax
  int v33; // edx
  float v34; // er9
  __int64 v35; // r8
  __int64 v36; // rcx
  DetectRagdollPenetration::BonePenetrationStatus *v37; // rax
  hkAabb newAabb; // [rsp+18h] [rbp-59h]
  __int128 v40; // [rsp+38h] [rbp-39h]
  __int128 v41; // [rsp+48h] [rbp-29h]
  __int128 v42; // [rsp+58h] [rbp-19h]
  __int128 v43; // [rsp+68h] [rbp-9h]
  char v44; // [rsp+D8h] [rbp+67h]
  hkBool *v45; // [rsp+E0h] [rbp+6Fh]
  __int64 v46; // [rsp+F0h] [rbp+7Fh]

  v4 = output;
  v5 = ragdollPoseIn;
  v6 = result;
  v7 = this;
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
        v10 = v7->m_setup.m_ragdollSkeleton->m_parentIndices.m_data[v9];
        if ( v7->m_boneStates.m_data[v10] )
        {
          if ( v5->m_boneFlags.m_data[(signed __int16)v10] & 2 )
            v11 = hkaPose::calculateBoneModelSpace(v5, (signed __int16)v10);
          else
            v11 = &v5->m_modelPose.m_data[(signed __int16)v10];
          v12 = v11->m_translation.m_quad;
          if ( v5->m_boneFlags.m_data[v8] & 2 )
            v13 = hkaPose::calculateBoneModelSpace(v5, v8);
          else
            v13 = &v5->m_modelPose.m_data[v8];
          v14 = v13->m_translation.m_quad;
          newAabb.m_min.m_quad = _mm_min_ps(_mm_min_ps(newAabb.m_min.m_quad, v12), v13->m_translation.m_quad);
          newAabb.m_max.m_quad = _mm_max_ps(_mm_max_ps(newAabb.m_max.m_quad, v12), v14);
        }
        v8 = ++v9;
      }
      while ( v9 < v7->m_numBones );
      v8 = 1;
    }
    if ( hkAabb::isValid(&newAabb) )
      hkpAabbPhantom::setAabb(v7->m_setup.m_ragdollPhantom, &newAabb);
    v15 = 1;
    if ( v7->m_numBones > 1 )
    {
      do
      {
        v16 = v7->m_setup.m_ragdollSkeleton->m_parentIndices.m_data[v15];
        if ( v7->m_boneStates.m_data[v16] )
        {
          v17 = (__int128 *)(v5->m_boneFlags.m_data[(signed __int16)v16] & 2 ? hkaPose::calculateBoneModelSpace(
                                                                                 v5,
                                                                                 (signed __int16)v16) : &v5->m_modelPose.m_data[(signed __int16)v16]);
          v41 = *v17;
          v18 = (__int128 *)(v5->m_boneFlags.m_data[v8] & 2 ? hkaPose::calculateBoneModelSpace(v5, v8) : &v5->m_modelPose.m_data[v8]);
          v40 = *v18;
          v19 = v7->m_setup.m_raycastInterface;
          v20 = v19->vfptr;
          newAabb.m_max.m_quad.m128_u64[1] = (unsigned __int64)&v43;
          newAabb.m_max.m_quad.m128_u64[0] = (unsigned __int64)&v42;
          newAabb.m_min.m_quad.m128_u64[1] = (unsigned __int64)&v40;
          ((void (__fastcall *)(hkaRagdollRaycastInterface *, char *, hkpAabbPhantom *, __int128 *))v20->castRay)(
            v19,
            &v44,
            v7->m_setup.m_ragdollPhantom,
            &v41);
          if ( v44 )
          {
            v21 = v42;
            v22 = v43;
            if ( v4->m_penetrations.m_size == (v4->m_penetrations.m_capacityAndFlags & 0x3FFFFFFF) )
              hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v4, 48);
            v23 = v4->m_penetrations.m_size;
            v24 = &v4->m_penetrations.m_data[v23] == 0;
            v25 = (signed __int64)&v4->m_penetrations.m_data[v23];
            v46 = v25;
            newAabb.m_min.m_quad.m128_u64[0] = v25;
            if ( !v24 )
            {
              *(_WORD *)v25 = v16;
              *(_WORD *)(v25 + 2) = v15;
              *(_OWORD *)(v25 + 16) = v21;
              *(_OWORD *)(v25 + 32) = v22;
            }
            ++v4->m_penetrations.m_size;
          }
        }
        v8 = ++v15;
      }
      while ( v15 < v7->m_numBones );
    }
  }
  v26 = 0;
  if ( v7->m_boneStates.m_size > 0 )
  {
    v27 = 0i64;
    do
    {
      v7->m_boneStates.m_data[v27] = 0;
      ++v26;
      ++v27;
    }
    while ( v26 < v7->m_boneStates.m_size );
  }
  v28 = v4->m_penetrations.m_size;
  if ( v28 )
  {
    v29 = 0;
    if ( v28 > 0 )
    {
      v30 = 0i64;
      do
      {
        v31 = v4->m_penetrations.m_data[v30].m_boneBeginIndex;
        v32 = v7->m_boneStates.m_data;
        if ( v32[v31] != 2 )
          v32[v31] = 1;
        newAabb.m_min.m_quad.m128_u64[0] = 0i64;
        newAabb.m_min.m_quad.m128_u64[1] = 0x8000000000000000i64;
        hkaSkeletonUtils::getDescendants(
          v7->m_setup.m_ragdollSkeleton,
          v31,
          (hkArray<short,hkContainerHeapAllocator> *)&newAabb,
          0);
        v33 = 0;
        v34 = newAabb.m_min.m_quad.m128_f32[2];
        if ( newAabb.m_min.m_quad.m128_i32[2] > 0 )
        {
          v35 = 0i64;
          do
          {
            v36 = *(signed __int16 *)(newAabb.m_min.m_quad.m128_u64[0] + v35);
            v37 = v7->m_boneStates.m_data;
            if ( v37[v36] != 2 )
            {
              v37[v36] = 2;
              v34 = newAabb.m_min.m_quad.m128_f32[2];
            }
            ++v33;
            v35 += 2i64;
          }
          while ( v33 < SLODWORD(v34) );
        }
        newAabb.m_min.m_quad.m128_i32[2] = 0;
        if ( newAabb.m_min.m_quad.m128_i32[3] >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            (void *)newAabb.m_min.m_quad.m128_u64[0],
            2 * (newAabb.m_min.m_quad.m128_i32[3] & 0x3FFFFFFF));
        newAabb.m_min.m_quad.m128_u64[0] = 0i64;
        newAabb.m_min.m_quad.m128_i32[3] = 2147483648;
        ++v29;
        ++v30;
      }
      while ( v29 < v4->m_penetrations.m_size );
      v6 = v45;
    }
    v6->m_bool = 1;
  }
  else
  {
    v7->m_ragdollIsOut.m_bool = 1;
    v6->m_bool = 0;
  }
  return v6;
}

