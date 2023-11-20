// File Line: 73
// RVA: 0x1BA2E0
hkaPose *__fastcall hkaPose::operator=(hkaPose *this, hkaPose *other)
{
  hkaPose *v2; // rbx
  hkaPose *v3; // rdi
  int v4; // ecx
  __int64 v5; // rax
  hkQsTransformf *v6; // r8
  __int64 v7; // rdx
  signed __int64 v8; // rax
  char *v9; // rcx
  __int128 v10; // xmm0
  int v11; // eax
  __int64 v12; // rax
  hkQsTransformf *v13; // r8
  __int64 v14; // rdx
  signed __int64 v15; // rax
  char *v16; // rcx
  __int128 v17; // xmm0
  __int64 v18; // rax
  unsigned int *v19; // rcx
  __int64 v20; // rdx
  char *v21; // r8
  unsigned int v22; // eax
  signed __int64 v23; // rax
  signed __int64 v24; // r11
  float *v25; // r10
  float *v26; // rdi
  signed __int64 v27; // rdx
  signed __int64 v28; // rcx
  signed __int64 v29; // r8
  unsigned __int64 v30; // r9
  int v31; // eax
  signed __int64 v32; // r10
  signed __int64 v33; // rcx
  signed __int64 v34; // rdx
  int v35; // eax
  int v37; // [rsp+30h] [rbp+8h]

  v2 = this;
  v3 = other;
  this->m_skeleton = other->m_skeleton;
  v4 = this->m_localPose.m_capacityAndFlags;
  if ( (v4 & 0x3FFFFFFF) < other->m_localPose.m_size )
  {
    if ( v4 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v2->m_localPose.m_data,
        48 * (v4 & 0x3FFFFFFF));
    v37 = 48 * v3->m_localPose.m_size;
    v2->m_localPose.m_data = (hkQsTransformf *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                                 (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                                                 &v37);
    v2->m_localPose.m_capacityAndFlags = v37 / 48;
  }
  v5 = v3->m_localPose.m_size;
  v6 = v2->m_localPose.m_data;
  v2->m_localPose.m_size = v5;
  v7 = v5;
  if ( (signed int)v5 > 0 )
  {
    v8 = (signed __int64)&v6->m_rotation;
    v9 = (char *)((char *)v3->m_localPose.m_data - (char *)v6);
    do
    {
      v10 = *(_OWORD *)&v9[v8 - 16];
      v8 += 48i64;
      *(_OWORD *)(v8 - 64) = v10;
      *(_OWORD *)(v8 - 48) = *(_OWORD *)&v9[v8 - 48];
      *(_OWORD *)(v8 - 32) = *(_OWORD *)&v9[v8 - 32];
      --v7;
    }
    while ( v7 );
  }
  v11 = v2->m_modelPose.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v11 < v3->m_modelPose.m_size )
  {
    if ( v2->m_modelPose.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v2->m_modelPose.m_data,
        48 * v11);
    v37 = 48 * v3->m_modelPose.m_size;
    v2->m_modelPose.m_data = (hkQsTransformf *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                                 (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                                                 &v37);
    v2->m_modelPose.m_capacityAndFlags = v37 / 48;
  }
  v12 = v3->m_modelPose.m_size;
  v13 = v2->m_modelPose.m_data;
  v2->m_modelPose.m_size = v12;
  v14 = v12;
  if ( (signed int)v12 > 0 )
  {
    v15 = (signed __int64)&v13->m_rotation;
    v16 = (char *)((char *)v3->m_modelPose.m_data - (char *)v13);
    do
    {
      v17 = *(_OWORD *)&v16[v15 - 16];
      v15 += 48i64;
      *(_OWORD *)(v15 - 64) = v17;
      *(_OWORD *)(v15 - 48) = *(_OWORD *)&v16[v15 - 48];
      *(_OWORD *)(v15 - 32) = *(_OWORD *)&v16[v15 - 32];
      --v14;
    }
    while ( v14 );
  }
  if ( (v2->m_boneFlags.m_capacityAndFlags & 0x3FFFFFFF) < v3->m_boneFlags.m_size )
  {
    if ( v2->m_boneFlags.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v2->m_boneFlags.m_data,
        4 * v2->m_boneFlags.m_capacityAndFlags);
    v37 = 4 * v3->m_boneFlags.m_size;
    v2->m_boneFlags.m_data = (unsigned int *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                               (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                                               &v37);
    v2->m_boneFlags.m_capacityAndFlags = v37 / 4;
  }
  v18 = v3->m_boneFlags.m_size;
  v19 = v2->m_boneFlags.m_data;
  v2->m_boneFlags.m_size = v18;
  v20 = v18;
  if ( (signed int)v18 > 0 )
  {
    v21 = (char *)((char *)v3->m_boneFlags.m_data - (char *)v19);
    do
    {
      v22 = *(unsigned int *)((char *)v19 + (_QWORD)v21);
      ++v19;
      *(v19 - 1) = v22;
      --v20;
    }
    while ( v20 );
  }
  v2->m_modelInSync.m_bool = v3->m_modelInSync.m_bool;
  v2->m_localInSync.m_bool = v3->m_localInSync.m_bool;
  if ( (v2->m_floatSlotValues.m_capacityAndFlags & 0x3FFFFFFF) < v3->m_floatSlotValues.m_size )
  {
    if ( v2->m_floatSlotValues.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v2->m_floatSlotValues.m_data,
        4 * v2->m_floatSlotValues.m_capacityAndFlags);
    v37 = 4 * v3->m_floatSlotValues.m_size;
    v2->m_floatSlotValues.m_data = (float *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                                              &v37);
    v2->m_floatSlotValues.m_capacityAndFlags = v37 / 4;
  }
  v23 = v3->m_floatSlotValues.m_size;
  v24 = 0i64;
  v2->m_floatSlotValues.m_size = v23;
  v25 = v3->m_floatSlotValues.m_data;
  v26 = v2->m_floatSlotValues.m_data;
  v27 = v23;
  if ( v23 >= 4 )
  {
    v28 = (signed __int64)(v26 + 1);
    v29 = (char *)v25 - (char *)v26;
    v30 = ((unsigned __int64)(v23 - 4) >> 2) + 1;
    v24 = 4 * v30;
    do
    {
      v31 = *(_DWORD *)(v29 + v28 - 4);
      v28 += 16i64;
      *(_DWORD *)(v28 - 20) = v31;
      *(_DWORD *)(v28 - 16) = *(_DWORD *)(v29 + v28 - 16);
      *(_DWORD *)(v28 - 12) = *(_DWORD *)(v29 + v28 - 12);
      *(_DWORD *)(v28 - 8) = *(_DWORD *)(v29 + v28 - 8);
      --v30;
    }
    while ( v30 );
  }
  if ( v24 < v27 )
  {
    v32 = (char *)v25 - (char *)v26;
    v33 = (signed __int64)&v26[v24];
    v34 = v27 - v24;
    do
    {
      v35 = *(_DWORD *)(v33 + v32);
      v33 += 4i64;
      *(_DWORD *)(v33 - 4) = v35;
      --v34;
    }
    while ( v34 );
  }
  return v2;
}

