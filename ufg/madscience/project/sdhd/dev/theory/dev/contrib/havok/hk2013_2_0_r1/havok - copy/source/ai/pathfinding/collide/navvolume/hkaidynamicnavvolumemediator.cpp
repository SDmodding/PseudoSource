// File Line: 29
// RVA: 0xBEA460
__m128i *__fastcall DynVolumeClosestPointCollector::processLeaf(DynVolumeClosestPointCollector *this, hkSimdFloat32 *result, unsigned int leafKey, hkAabb *cellAabb, hkVector4f *queryPoint, hkVector4f *closestPointOut, hkSimdFloat32 *closestDistanceSquared)
{
  __m128i *v7; // rbx
  signed __int64 v8; // r9
  DynVolumeClosestPointCollector *v9; // rdi
  hkaiStreamingCollection::InstanceInfo *v10; // r8
  __int64 v11; // rdx
  __int64 *v12; // rcx
  __int128 *v13; // rax
  __m128 v14; // xmm2
  __m128 v15; // xmm1
  __m128 v16; // xmm4
  __m128 v17; // xmm3
  __m128 v18; // xmm0
  __int64 v19; // rax
  unsigned int v20; // eax
  hkVector4f v21; // xmm3
  __m128 v22; // xmm1
  __m128 v23; // xmm1
  __m128i v24; // xmm2
  __m128 v26; // [rsp+20h] [rbp-68h]
  __int128 v27; // [rsp+30h] [rbp-58h]
  __m128 v28; // [rsp+40h] [rbp-48h]
  __int128 v29; // [rsp+50h] [rbp-38h]
  __int128 v30; // [rsp+60h] [rbp-28h]
  __int128 v31; // [rsp+70h] [rbp-18h]

  v7 = (__m128i *)result;
  v8 = 3i64 * (signed int)leafKey;
  v9 = this;
  v10 = this->m_collection->m_instances.m_data;
  v8 *= 2i64;
  v11 = *((_QWORD *)&v10->m_volumeInstancePtr + v8);
  v12 = (__int64 *)*((_QWORD *)&v10->m_volumeMediator + v8);
  if ( !v11 )
    goto LABEL_10;
  v13 = (__int128 *)v9->m_gcpInput;
  v14 = closestDistanceSquared->m_real;
  v15 = _mm_rsqrt_ps(closestDistanceSquared->m_real);
  v16 = _mm_cmpleps(closestDistanceSquared->m_real, (__m128)0i64);
  v17 = _mm_mul_ps(
          _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(closestDistanceSquared->m_real, v15), v15)),
          _mm_mul_ps(*(__m128 *)_xmm, v15));
  v27 = *v13;
  v28 = (__m128)v13[1];
  v29 = v13[2];
  v30 = v13[3];
  v31 = v13[4];
  v18 = queryPoint->m_quad;
  *(_QWORD *)&v31 = v11 + 112;
  v19 = *v12;
  *((_QWORD *)&v30 + 1) = v11;
  v28 = _mm_andnot_ps(v16, _mm_mul_ps(v17, v14));
  _mm_store_si128((__m128i *)&v26, (__m128i)v18);
  v20 = (*(__int64 (__fastcall **)(__int64 *, __int128 *, __m128 *))(v19 + 24))(v12, &v27, &v26);
  if ( v20 != -1 )
  {
    v21.m_quad = v26;
    v22 = _mm_sub_ps(v26, queryPoint->m_quad);
    v23 = _mm_mul_ps(v22, v22);
    v24 = (__m128i)_mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v23, v23, 85), _mm_shuffle_ps(v23, v23, 0)),
                     _mm_shuffle_ps(v23, v23, 170));
    if ( *(float *)v24.m128i_i32 < closestDistanceSquared->m_real.m128_f32[0] )
    {
      v9->m_bestKey = v20;
      *closestPointOut = (hkVector4f)v21.m_quad;
    }
    _mm_store_si128(v7, v24);
  }
  else
  {
LABEL_10:
    _mm_store_si128(v7, (__m128i)closestDistanceSquared->m_real);
  }
  return v7;
}

// File Line: 72
// RVA: 0xBEA2C0
void __fastcall hkaiDynamicNavVolumeMediator::hkaiDynamicNavVolumeMediator(hkaiDynamicNavVolumeMediator *this, hkaiStreamingCollection *collection, hkcdDynamicAabbTree *tree)
{
  hkcdDynamicAabbTree *v3; // rdi
  hkaiStreamingCollection *v4; // rsi
  hkaiDynamicNavVolumeMediator *v5; // rbx

  v3 = tree;
  v4 = collection;
  v5 = this;
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkaiDynamicNavVolumeMediator::`vftable;
  if ( collection )
    hkReferencedObject::addReference((hkReferencedObject *)&collection->vfptr);
  v5->m_collection.m_pntr = v4;
  if ( v3 )
    hkReferencedObject::addReference((hkReferencedObject *)&v3->vfptr);
  v5->m_aabbTree.m_pntr = v3;
}

// File Line: 79
// RVA: 0xBEA330
void __fastcall hkaiDynamicNavVolumeMediator::hkaiDynamicNavVolumeMediator(hkaiDynamicNavVolumeMediator *this, hkFinishLoadedObjectFlag f)
{
  this->vfptr = (hkBaseObjectVtbl *)&hkaiDynamicNavVolumeMediator::`vftable;
}

// File Line: 84
// RVA: 0xBEA350
void __fastcall hkaiDynamicNavVolumeMediator::~hkaiDynamicNavVolumeMediator(hkaiDynamicNavVolumeMediator *this)
{
  hkaiDynamicNavVolumeMediator *v1; // rbx
  hkcdDynamicAabbTree *v2; // rcx
  hkReferencedObject *v3; // rcx

  v1 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkaiDynamicNavVolumeMediator::`vftable;
  v2 = this->m_aabbTree.m_pntr;
  if ( v2 )
    hkReferencedObject::removeReference((hkReferencedObject *)&v2->vfptr);
  v1->m_aabbTree.m_pntr = 0i64;
  v3 = (hkReferencedObject *)&v1->m_collection.m_pntr->vfptr;
  if ( v3 )
    hkReferencedObject::removeReference(v3);
  v1->m_collection.m_pntr = 0i64;
  v1->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 89
// RVA: 0xBEA3B0
__int64 __fastcall hkaiDynamicNavVolumeMediator::getClosestPoint(hkaiDynamicNavVolumeMediator *this, hkaiNavVolumeMediator::GetClosestPointInput *gcpInput, hkVector4f *closestPointOut)
{
  hkaiStreamingCollection *v3; // rax
  hkcdDynamicAabbTree *v4; // rcx
  hkcdAabbTreeQueries::ClosestPointCollector collector; // [rsp+30h] [rbp-28h]
  hkaiStreamingCollection *v7; // [rsp+38h] [rbp-20h]
  hkaiNavVolumeMediator::GetClosestPointInput *v8; // [rsp+40h] [rbp-18h]
  unsigned int v9; // [rsp+48h] [rbp-10h]

  collector.vfptr = (hkcdAabbTreeQueries::ClosestPointCollectorVtbl *)&DynVolumeClosestPointCollector::`vftable;
  v3 = this->m_collection.m_pntr;
  v4 = this->m_aabbTree.m_pntr;
  v7 = v3;
  v8 = gcpInput;
  v9 = -1;
  hkcdDynamicAabbTree::getClosestPoint(v4, &gcpInput->m_position, &gcpInput->m_queryRadius, &collector, closestPointOut);
  return v9;
}

