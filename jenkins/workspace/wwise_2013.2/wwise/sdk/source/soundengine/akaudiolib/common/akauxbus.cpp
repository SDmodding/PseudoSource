// File Line: 41
// RVA: 0xA88F30
CAkAuxBus *__fastcall CAkAuxBus::Create(unsigned int in_ulID)
{
  CAkBus *v2; // rax
  CAkBus *v3; // rbx
  __m128 v4; // xmm0

  v2 = (CAkBus *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x158ui64);
  v3 = v2;
  if ( !v2 )
    return 0i64;
  CAkBus::CAkBus(v2, in_ulID);
  v3->vfptr = (CAkIndexableVtbl *)&CAkAuxBus::`vftable;
  v4 = _mm_shuffle_ps((__m128)(unsigned int)FLOAT_1_0, (__m128)(unsigned int)FLOAT_1_0, 0);
  *(__m128 *)&v3[1].vfptr = v4;
  *(__m128 *)&v3[1].key = v4;
  if ( (unsigned int)CAkBus::Init(v3) != 1 )
  {
    v3->vfptr->Release(v3);
    return 0i64;
  }
  return (CAkAuxBus *)v3;
}

// File Line: 56
// RVA: 0xA88FC0
__int64 __fastcall SSConversion::get_type(CAkAuxBus *this)
{
  return 12i64;
}

