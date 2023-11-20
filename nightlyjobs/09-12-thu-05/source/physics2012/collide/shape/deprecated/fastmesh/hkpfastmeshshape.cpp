// File Line: 18
// RVA: 0xD17B90
void __fastcall hkpFastMeshShape::hkpFastMeshShape(hkpFastMeshShape *this, float radius, int numBitsForSubpartIndex)
{
  hkpFastMeshShape *v3; // rbx

  v3 = this;
  hkpMeshShape::hkpMeshShape((hkpMeshShape *)&this->vfptr, radius, numBitsForSubpartIndex);
  v3->vfptr = (hkBaseObjectVtbl *)&hkpFastMeshShape::`vftable'{for `hkpShape'};
  v3->vfptr = (hkpShapeContainerVtbl *)&hkpFastMeshShape::`vftable'{for `hkpShapeContainer'};
}

// File Line: 25
// RVA: 0xD17BD0
void __fastcall hkpFastMeshShape::hkpFastMeshShape(hkpFastMeshShape *this, hkFinishLoadedObjectFlag flag)
{
  hkpFastMeshShape *v2; // rbx
  int v3; // [rsp+38h] [rbp+10h]

  v3 = flag.m_finishing;
  v2 = this;
  hkpMeshShape::hkpMeshShape((hkpMeshShape *)&this->vfptr, flag);
  v2->vfptr = (hkBaseObjectVtbl *)&hkpFastMeshShape::`vftable'{for `hkpShape'};
  v2->vfptr = (hkpShapeContainerVtbl *)&hkpFastMeshShape::`vftable'{for `hkpShapeContainer'};
  if ( v3 )
    v2->m_type.m_storage = 27;
}

// File Line: 36
// RVA: 0xD17C10
hkpShape *__fastcall hkpFastMeshShape::getChildShape(hkpFastMeshShape *this, unsigned int key, char (*buffer)[512])
{
  __int64 v3; // rsi
  char (*v4)[512]; // rbx
  __m128 *v5; // rdi
  int v6; // er9
  unsigned __int16 *v7; // r11
  __int64 v8; // rcx
  __m128 *v9; // rbp
  __m128 *v10; // r8
  __m128 *v11; // r9
  __int16 v12; // cx
  float v13; // xmm0_4
  unsigned __int8 v14; // al
  hkpShape *result; // rax

  v3 = *(_QWORD *)&this->m_disableWelding.m_bool;
  v4 = buffer;
  v5 = (__m128 *)this;
  v6 = *(_DWORD *)(v3 + 8);
  v7 = (unsigned __int16 *)(*(_QWORD *)(v3 + 16) + key * *(_DWORD *)(v3 + 28));
  v8 = (signed int)(key & *(_DWORD *)(v3 + 32));
  v9 = (__m128 *)(*(_QWORD *)v3 + v6 * *v7);
  v10 = (__m128 *)(*(_QWORD *)v3 + v6 * v7[v8 + 1]);
  v11 = (__m128 *)(*(_QWORD *)v3 + v6 * v7[(v8 ^ 1) + 1]);
  if ( v5[4].m128_i32[0] )
    v12 = *(_WORD *)(v5[3].m128_u64[1] + 2i64 * (signed int)(key + *(_DWORD *)(v3 + 72)));
  else
    v12 = 0;
  if ( v4 )
  {
    v13 = v5[4].m128_f32[3];
    v14 = v5[4].m128_i8[8];
    *(_DWORD *)&(*v4)[8] = 0x1FFFF;
    *(_DWORD *)&(*v4)[16] = 1026;
    *(_QWORD *)&(*v4)[24] = 0i64;
    *(float *)&(*v4)[32] = v13;
    *(_WORD *)&(*v4)[40] = v12;
    *(_WORD *)&(*v4)[42] = v14;
    *(_OWORD *)&(*v4)[96] = 0i64;
    *(_QWORD *)v4 = &hkpTriangleShape::`vftable';
  }
  else
  {
    v4 = 0i64;
  }
  result = (hkpShape *)v4;
  *(__m128 *)&(*v4)[48] = _mm_mul_ps(v5[1], *v9);
  *(__m128 *)&(*v4)[64] = _mm_mul_ps(v5[1], *v10);
  *(__m128 *)&(*v4)[80] = _mm_mul_ps(*v11, v5[1]);
  return result;
}

