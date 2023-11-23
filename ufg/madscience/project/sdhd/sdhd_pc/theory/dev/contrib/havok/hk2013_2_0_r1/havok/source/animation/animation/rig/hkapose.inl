// File Line: 73
// RVA: 0x1BA2E0
hkaPose *__fastcall hkaPose::operator=(hkaPose *this, hkaPose *other)
{
  int m_capacityAndFlags; // ecx
  __int64 m_size; // rax
  hkQsTransformf *m_data; // r8
  __int64 v7; // rdx
  hkQuaternionf *p_m_rotation; // rax
  char *v9; // rcx
  hkQuaternionf v10; // xmm0
  int v11; // eax
  __int64 v12; // rax
  hkQsTransformf *v13; // r8
  __int64 v14; // rdx
  hkQuaternionf *v15; // rax
  char *v16; // rcx
  hkQuaternionf v17; // xmm0
  __int64 v18; // rax
  unsigned int *v19; // rcx
  __int64 v20; // rdx
  char *v21; // r8
  unsigned int v22; // eax
  __int64 v23; // rax
  __int64 v24; // r11
  float *v25; // r10
  float *v26; // rdi
  __int64 v27; // rdx
  float *v28; // rcx
  signed __int64 v29; // r8
  unsigned __int64 v30; // r9
  int v31; // eax
  signed __int64 v32; // r10
  float *v33; // rcx
  __int64 v34; // rdx
  int v35; // eax
  int v37; // [rsp+30h] [rbp+8h] BYREF

  this->m_skeleton = other->m_skeleton;
  m_capacityAndFlags = this->m_localPose.m_capacityAndFlags;
  if ( (m_capacityAndFlags & 0x3FFFFFFF) < other->m_localPose.m_size )
  {
    if ( m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        this->m_localPose.m_data,
        48 * (m_capacityAndFlags & 0x3FFFFFFF));
    v37 = 48 * other->m_localPose.m_size;
    this->m_localPose.m_data = (hkQsTransformf *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                                   &hkContainerHeapAllocator::s_alloc,
                                                   &v37);
    this->m_localPose.m_capacityAndFlags = v37 / 48;
  }
  m_size = other->m_localPose.m_size;
  m_data = this->m_localPose.m_data;
  this->m_localPose.m_size = m_size;
  v7 = m_size;
  if ( (int)m_size > 0 )
  {
    p_m_rotation = &m_data->m_rotation;
    v9 = (char *)((char *)other->m_localPose.m_data - (char *)m_data);
    do
    {
      v10.m_vec.m_quad = *(__m128 *)((char *)&p_m_rotation[-1] + (_QWORD)v9);
      p_m_rotation += 3;
      p_m_rotation[-4] = (hkQuaternionf)v10.m_vec.m_quad;
      p_m_rotation[-3] = *(hkQuaternionf *)((char *)p_m_rotation + (_QWORD)v9 - 48);
      p_m_rotation[-2] = *(hkQuaternionf *)((char *)p_m_rotation + (_QWORD)v9 - 32);
      --v7;
    }
    while ( v7 );
  }
  v11 = this->m_modelPose.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v11 < other->m_modelPose.m_size )
  {
    if ( this->m_modelPose.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        this->m_modelPose.m_data,
        48 * v11);
    v37 = 48 * other->m_modelPose.m_size;
    this->m_modelPose.m_data = (hkQsTransformf *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                                   &hkContainerHeapAllocator::s_alloc,
                                                   &v37);
    this->m_modelPose.m_capacityAndFlags = v37 / 48;
  }
  v12 = other->m_modelPose.m_size;
  v13 = this->m_modelPose.m_data;
  this->m_modelPose.m_size = v12;
  v14 = v12;
  if ( (int)v12 > 0 )
  {
    v15 = &v13->m_rotation;
    v16 = (char *)((char *)other->m_modelPose.m_data - (char *)v13);
    do
    {
      v17.m_vec.m_quad = *(__m128 *)((char *)&v15[-1] + (_QWORD)v16);
      v15 += 3;
      v15[-4] = (hkQuaternionf)v17.m_vec.m_quad;
      v15[-3] = *(hkQuaternionf *)((char *)v15 + (_QWORD)v16 - 48);
      v15[-2] = *(hkQuaternionf *)((char *)v15 + (_QWORD)v16 - 32);
      --v14;
    }
    while ( v14 );
  }
  if ( (this->m_boneFlags.m_capacityAndFlags & 0x3FFFFFFF) < other->m_boneFlags.m_size )
  {
    if ( this->m_boneFlags.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        this->m_boneFlags.m_data,
        4 * this->m_boneFlags.m_capacityAndFlags);
    v37 = 4 * other->m_boneFlags.m_size;
    this->m_boneFlags.m_data = (unsigned int *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                                 &hkContainerHeapAllocator::s_alloc,
                                                 &v37);
    this->m_boneFlags.m_capacityAndFlags = v37 / 4;
  }
  v18 = other->m_boneFlags.m_size;
  v19 = this->m_boneFlags.m_data;
  this->m_boneFlags.m_size = v18;
  v20 = v18;
  if ( (int)v18 > 0 )
  {
    v21 = (char *)((char *)other->m_boneFlags.m_data - (char *)v19);
    do
    {
      v22 = *(unsigned int *)((char *)v19++ + (_QWORD)v21);
      *(v19 - 1) = v22;
      --v20;
    }
    while ( v20 );
  }
  this->m_modelInSync.m_bool = other->m_modelInSync.m_bool;
  this->m_localInSync.m_bool = other->m_localInSync.m_bool;
  if ( (this->m_floatSlotValues.m_capacityAndFlags & 0x3FFFFFFF) < other->m_floatSlotValues.m_size )
  {
    if ( this->m_floatSlotValues.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        this->m_floatSlotValues.m_data,
        4 * this->m_floatSlotValues.m_capacityAndFlags);
    v37 = 4 * other->m_floatSlotValues.m_size;
    this->m_floatSlotValues.m_data = (float *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                                &hkContainerHeapAllocator::s_alloc,
                                                &v37);
    this->m_floatSlotValues.m_capacityAndFlags = v37 / 4;
  }
  v23 = other->m_floatSlotValues.m_size;
  v24 = 0i64;
  this->m_floatSlotValues.m_size = v23;
  v25 = other->m_floatSlotValues.m_data;
  v26 = this->m_floatSlotValues.m_data;
  v27 = v23;
  if ( v23 >= 4 )
  {
    v28 = v26 + 1;
    v29 = (char *)v25 - (char *)v26;
    v30 = ((unsigned __int64)(v23 - 4) >> 2) + 1;
    v24 = 4 * v30;
    do
    {
      v31 = *(_DWORD *)((char *)v28 + v29 - 4);
      v28 += 4;
      *((_DWORD *)v28 - 5) = v31;
      *(v28 - 4) = *(float *)((char *)v28 + v29 - 16);
      *(v28 - 3) = *(float *)((char *)v28 + v29 - 12);
      *(v28 - 2) = *(float *)((char *)v28 + v29 - 8);
      --v30;
    }
    while ( v30 );
  }
  if ( v24 < v27 )
  {
    v32 = (char *)v25 - (char *)v26;
    v33 = &v26[v24];
    v34 = v27 - v24;
    do
    {
      v35 = *(_DWORD *)((char *)v33++ + v32);
      *((_DWORD *)v33 - 1) = v35;
      --v34;
    }
    while ( v34 );
  }
  return this;
}

