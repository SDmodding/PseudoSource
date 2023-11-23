// File Line: 29
// RVA: 0xBEA460
hkSimdFloat32 *__fastcall DynVolumeClosestPointCollector::processLeaf(
        DynVolumeClosestPointCollector *this,
        hkSimdFloat32 *result,
        int leafKey,
        hkAabb *cellAabb,
        hkVector4f *queryPoint,
        hkVector4f *closestPointOut,
        hkSimdFloat32 *closestDistanceSquared)
{
  __int64 v8; // r9
  hkaiStreamingCollection::InstanceInfo *m_data; // r8
  __int64 v11; // rdx
  __int64 *v12; // rcx
  __int128 *m_gcpInput; // rax
  __m128 m_real; // xmm2
  __m128 v15; // xmm1
  __m128 v16; // xmm4
  __m128 v17; // xmm3
  __m128 m_quad; // xmm0
  __int64 v19; // rax
  unsigned int v20; // eax
  hkVector4f v21; // xmm3
  __m128 v22; // xmm1
  __m128 v23; // xmm1
  hkSimdFloat32 v24; // xmm2
  __m128 v26; // [rsp+20h] [rbp-68h] BYREF
  __int128 v27; // [rsp+30h] [rbp-58h] BYREF
  __m128 v28; // [rsp+40h] [rbp-48h]
  __int128 v29; // [rsp+50h] [rbp-38h]
  __int128 v30; // [rsp+60h] [rbp-28h]
  __int128 v31; // [rsp+70h] [rbp-18h]

  v8 = 3i64 * leafKey;
  m_data = this->m_collection->m_instances.m_data;
  v8 *= 2i64;
  v11 = *((_QWORD *)&m_data->m_volumeInstancePtr + v8);
  v12 = (__int64 *)*((_QWORD *)&m_data->m_volumeMediator + v8);
  if ( !v11 )
    goto LABEL_6;
  m_gcpInput = (__int128 *)this->m_gcpInput;
  m_real = closestDistanceSquared->m_real;
  v15 = _mm_rsqrt_ps(closestDistanceSquared->m_real);
  v16 = _mm_cmple_ps(closestDistanceSquared->m_real, (__m128)0i64);
  v17 = _mm_mul_ps(
          _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(closestDistanceSquared->m_real, v15), v15)),
          _mm_mul_ps(*(__m128 *)_xmm, v15));
  v27 = *m_gcpInput;
  v28 = (__m128)m_gcpInput[1];
  v29 = m_gcpInput[2];
  v30 = m_gcpInput[3];
  v31 = m_gcpInput[4];
  m_quad = queryPoint->m_quad;
  *(_QWORD *)&v31 = v11 + 112;
  v19 = *v12;
  *((_QWORD *)&v30 + 1) = v11;
  v28 = _mm_andnot_ps(v16, _mm_mul_ps(v17, m_real));
  v26 = m_quad;
  v20 = (*(__int64 (__fastcall **)(__int64 *, __int128 *, __m128 *))(v19 + 24))(v12, &v27, &v26);
  if ( v20 == -1 )
  {
LABEL_6:
    *result = (hkSimdFloat32)closestDistanceSquared->m_real;
  }
  else
  {
    v21.m_quad = v26;
    v22 = _mm_sub_ps(v26, queryPoint->m_quad);
    v23 = _mm_mul_ps(v22, v22);
    v24.m_real = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v23, v23, 85), _mm_shuffle_ps(v23, v23, 0)),
                   _mm_shuffle_ps(v23, v23, 170));
    if ( v24.m_real.m128_f32[0] < closestDistanceSquared->m_real.m128_f32[0] )
    {
      this->m_bestKey = v20;
      *closestPointOut = (hkVector4f)v21.m_quad;
    }
    *result = (hkSimdFloat32)v24.m_real;
  }
  return result;
}

// File Line: 72
// RVA: 0xBEA2C0
void __fastcall hkaiDynamicNavVolumeMediator::hkaiDynamicNavVolumeMediator(
        hkaiDynamicNavVolumeMediator *this,
        hkaiStreamingCollection *collection,
        hkcdDynamicAabbTree *tree)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkaiDynamicNavVolumeMediator::`vftable;
  if ( collection )
    hkReferencedObject::addReference(collection);
  this->m_collection.m_pntr = collection;
  if ( tree )
    hkReferencedObject::addReference(tree);
  this->m_aabbTree.m_pntr = tree;
}

// File Line: 79
// RVA: 0xBEA330
void __fastcall hkaiDynamicNavVolumeMediator::hkaiDynamicNavVolumeMediator(
        hkaiDynamicNavVolumeMediator *this,
        hkFinishLoadedObjectFlag f)
{
  this->vfptr = (hkBaseObjectVtbl *)&hkaiDynamicNavVolumeMediator::`vftable;
}

// File Line: 84
// RVA: 0xBEA350
void __fastcall hkaiDynamicNavVolumeMediator::~hkaiDynamicNavVolumeMediator(hkaiDynamicNavVolumeMediator *this)
{
  hkcdDynamicAabbTree *m_pntr; // rcx
  hkaiStreamingCollection *v3; // rcx

  this->vfptr = (hkBaseObjectVtbl *)&hkaiDynamicNavVolumeMediator::`vftable;
  m_pntr = this->m_aabbTree.m_pntr;
  if ( m_pntr )
    hkReferencedObject::removeReference(m_pntr);
  this->m_aabbTree.m_pntr = 0i64;
  v3 = this->m_collection.m_pntr;
  if ( v3 )
    hkReferencedObject::removeReference(v3);
  this->m_collection.m_pntr = 0i64;
  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 89
// RVA: 0xBEA3B0
__int64 __fastcall hkaiDynamicNavVolumeMediator::getClosestPoint(
        hkaiDynamicNavVolumeMediator *this,
        hkaiNavVolumeMediator::GetClosestPointInput *gcpInput,
        hkVector4f *closestPointOut)
{
  hkaiStreamingCollection *m_pntr; // rax
  hkcdDynamicAabbTree *v4; // rcx
  hkcdAabbTreeQueries::ClosestPointCollector collector; // [rsp+30h] [rbp-28h] BYREF
  hkaiStreamingCollection *v7; // [rsp+38h] [rbp-20h]
  hkaiNavVolumeMediator::GetClosestPointInput *v8; // [rsp+40h] [rbp-18h]
  unsigned int v9; // [rsp+48h] [rbp-10h]

  collector.vfptr = (hkcdAabbTreeQueries::ClosestPointCollectorVtbl *)&DynVolumeClosestPointCollector::`vftable;
  m_pntr = this->m_collection.m_pntr;
  v4 = this->m_aabbTree.m_pntr;
  v7 = m_pntr;
  v8 = gcpInput;
  v9 = -1;
  hkcdDynamicAabbTree::getClosestPoint(v4, &gcpInput->m_position, &gcpInput->m_queryRadius, &collector, closestPointOut);
  return v9;
}

