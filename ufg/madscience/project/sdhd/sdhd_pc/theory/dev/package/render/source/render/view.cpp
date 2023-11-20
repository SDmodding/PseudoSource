// File Line: 65
// RVA: 0x159E0
Render::vDynamic *__fastcall `anonymous namespace::GetVertsCircle(unsigned int segCount, UFG::qColour *colour)
{
  UFG::qColour *v2; // rsi
  __int64 v3; // r15
  unsigned int v4; // eax
  Render::vDynamic *v5; // rbx
  unsigned int v6; // eax
  float v7; // xmm6_4
  float v8; // xmm7_4
  float *v9; // rdi
  unsigned __int64 v10; // rbp
  float v11; // xmm1_4
  __int64 v12; // rax
  int v13; // ecx
  Render::vDynamic *v14; // rdx

  v2 = colour;
  v3 = segCount;
  v4 = _S1_0;
  if ( !(_S1_0 & 1) )
  {
    v4 = _S1_0 | 1;
    _S1_0 |= 1u;
  }
  if ( !(v4 & 2) )
    _S1_0 = v4 | 2;
  v5 = &spVerts[1];
  v6 = sSegCountLast;
  if ( (_DWORD)v3 != sSegCountLast )
  {
    v7 = 0.0;
    v8 = 6.2831855 / (float)(signed int)segCount;
    if ( &spVerts[1] < &spVerts[segCount + 1] )
    {
      v9 = &spVerts[1].mPosition.z;
      v10 = ((unsigned __int64)((48 * (unsigned __int64)segCount - 1) * (unsigned __int128)0xAAAAAAAAAAAAAAABui64 >> 64) >> 5)
          + 1;
      do
      {
        *(v9 - 1) = sinf(v7) * -0.5;
        *v9 = cosf(v7) * 0.5;
        v7 = v7 + v8;
        v9 += 12;
        --v10;
      }
      while ( v10 );
    }
    v11 = spVerts[1].mPosition.z;
    v12 = (unsigned int)(v3 + 1);
    spVerts[v12].mPosition.y = spVerts[1].mPosition.y;
    spVerts[v12].mPosition.z = v11;
    v6 = v3;
    sSegCountLast = v3;
  }
  if ( v2->r != sColourLast.r
    || sColourLast.g != v2->g
    || sColourLast.b != v2->b
    || sColourLast.a != v2->a
    || (unsigned int)v3 > v6 )
  {
    v13 = (signed int)(float)(v2->r * 255.0) | (((signed int)(float)(v2->g * 255.0) | (((signed int)(float)(v2->b * 255.0) | ((signed int)(float)(v2->a * 255.0) << 8)) << 8)) << 8);
    v14 = &spVerts[v3 + 2];
    if ( &spVerts[1] < v14 )
    {
      do
      {
        v5->mColour = v13;
        ++v5;
      }
      while ( v5 < v14 );
    }
    sColourLast.r = v2->r;
    sColourLast.g = v2->g;
    sColourLast.b = v2->b;
    sColourLast.a = v2->a;
  }
  return spVerts;
}

// File Line: 249
// RVA: 0xD230
__int64 __fastcall `anonymous namespace::AngleToSegment(float angle, unsigned int segCount)
{
  __m128 v2; // xmm1
  signed int v3; // ecx
  signed int v5; // ecx

  v2 = 0i64;
  v2.m128_f32[0] = (float)((float)(signed int)segCount * angle) * 0.15915494;
  if ( v2.m128_f32[0] >= 0.0 )
  {
    v2.m128_f32[0] = v2.m128_f32[0] + 0.5;
    v5 = (signed int)v2.m128_f32[0];
    if ( (signed int)v2.m128_f32[0] != 0x80000000 && (float)v5 != v2.m128_f32[0] )
      v2.m128_f32[0] = (float)(v5 - (_mm_movemask_ps(_mm_unpacklo_ps(v2, v2)) & 1));
  }
  else
  {
    v2.m128_f32[0] = v2.m128_f32[0] - 0.5;
    v3 = (signed int)v2.m128_f32[0];
    if ( (signed int)v2.m128_f32[0] != 0x80000000 && (float)v3 != v2.m128_f32[0] )
      return (unsigned int)(signed int)(float)((_mm_movemask_ps(_mm_unpacklo_ps(v2, v2)) & 1 ^ 1) + v3);
  }
  return (unsigned int)(signed int)v2.m128_f32[0];
}

// File Line: 282
// RVA: 0x155F0
Render::vDynamic *__fastcall `anonymous namespace::GetVertsAxes()
{
  if ( !(_S3 & 1) )
    _S3 |= 1u;
  if ( !sAxesInit )
  {
    UFG::qMemSet(spAxesVerts, 0, 0x420u);
    *(_QWORD *)&spAxesVerts[0].mPosition.x = 1065353216i64;
    dword_14212B448 = 0;
    dword_14212B46C = (signed int)(float)(UFG::qColour::Red.r * 255.0) | (((signed int)(float)(UFG::qColour::Red.g
                                                                                             * 255.0) | (((signed int)(float)(UFG::qColour::Red.b * 255.0) | ((signed int)(float)(UFG::qColour::Red.a * 255.0) << 8)) << 8)) << 8);
    qword_14212B470 = 0i64;
    dword_14212B478 = 0;
    dword_14212B49C = (signed int)(float)(UFG::qColour::Red.r * 255.0) | (((signed int)(float)(UFG::qColour::Red.g
                                                                                             * 255.0) | (((signed int)(float)(UFG::qColour::Red.b * 255.0) | ((signed int)(float)(UFG::qColour::Red.a * 255.0) << 8)) << 8)) << 8);
    dword_14212B4A0 = 0;
    qword_14212B4A4 = 1065353216i64;
    dword_14212B4CC = (signed int)(float)(UFG::qColour::Green.r * 255.0) | (((signed int)(float)(UFG::qColour::Green.g
                                                                                               * 255.0) | (((signed int)(float)(UFG::qColour::Green.b * 255.0) | ((signed int)(float)(UFG::qColour::Green.a * 255.0) << 8)) << 8)) << 8);
    qword_14212B4D0 = 0i64;
    dword_14212B4D8 = 0;
    dword_14212B4FC = (signed int)(float)(UFG::qColour::Green.r * 255.0) | (((signed int)(float)(UFG::qColour::Green.g
                                                                                               * 255.0) | (((signed int)(float)(UFG::qColour::Green.b * 255.0) | ((signed int)(float)(UFG::qColour::Green.a * 255.0) << 8)) << 8)) << 8);
    qword_14212B500 = 0i64;
    dword_14212B508 = 1065353216;
    dword_14212B52C = (signed int)(float)(UFG::qColour::Blue.r * 255.0) | (((signed int)(float)(UFG::qColour::Blue.g
                                                                                              * 255.0) | (((signed int)(float)(UFG::qColour::Blue.b * 255.0) | ((signed int)(float)(UFG::qColour::Blue.a * 255.0) << 8)) << 8)) << 8);
    qword_14212B530 = 0i64;
    dword_14212B538 = 0;
    dword_14212B55C = (signed int)(float)(UFG::qColour::Blue.r * 255.0) | (((signed int)(float)(UFG::qColour::Blue.g
                                                                                              * 255.0) | (((signed int)(float)(UFG::qColour::Blue.b * 255.0) | ((signed int)(float)(UFG::qColour::Blue.a * 255.0) << 8)) << 8)) << 8);
    dword_14212B560 = 1040187392;
    qword_14212B564 = 1048576000i64;
    dword_14212B58C = (signed int)(float)(UFG::qColour::Red.r * 255.0) | (((signed int)(float)(UFG::qColour::Red.g
                                                                                             * 255.0) | (((signed int)(float)(UFG::qColour::Red.b * 255.0) | ((signed int)(float)(UFG::qColour::Red.a * 255.0) << 8)) << 8)) << 8);
    dword_14212B590 = -1107296256;
    dword_14212B594 = -1098907648;
    dword_14212B598 = 0;
    dword_14212B5BC = (signed int)(float)(UFG::qColour::Red.r * 255.0) | (((signed int)(float)(UFG::qColour::Red.g
                                                                                             * 255.0) | (((signed int)(float)(UFG::qColour::Red.b * 255.0) | ((signed int)(float)(UFG::qColour::Red.a * 255.0) << 8)) << 8)) << 8);
    dword_14212B5C0 = 1040187392;
    dword_14212B5C4 = -1098907648;
    dword_14212B5C8 = 0;
    dword_14212B5EC = (signed int)(float)(UFG::qColour::Red.r * 255.0) | (((signed int)(float)(UFG::qColour::Red.g
                                                                                             * 255.0) | (((signed int)(float)(UFG::qColour::Red.b * 255.0) | ((signed int)(float)(UFG::qColour::Red.a * 255.0) << 8)) << 8)) << 8);
    dword_14212B5F0 = -1107296256;
    qword_14212B5F4 = 1048576000i64;
    dword_14212B61C = (signed int)(float)(UFG::qColour::Red.r * 255.0) | (((signed int)(float)(UFG::qColour::Red.g
                                                                                             * 255.0) | (((signed int)(float)(UFG::qColour::Red.b * 255.0) | ((signed int)(float)(UFG::qColour::Red.a * 255.0) << 8)) << 8)) << 8);
    dword_14212B620 = 1040187392;
    qword_14212B624 = 1048576000i64;
    dword_14212B64C = (signed int)(float)(UFG::qColour::Green.r * 255.0) | (((signed int)(float)(UFG::qColour::Green.g
                                                                                               * 255.0) | (((signed int)(float)(UFG::qColour::Green.b * 255.0) | ((signed int)(float)(UFG::qColour::Green.a * 255.0) << 8)) << 8)) << 8);
    qword_14212B650 = 0i64;
    dword_14212B658 = 0;
    dword_14212B67C = (signed int)(float)(UFG::qColour::Green.r * 255.0) | (((signed int)(float)(UFG::qColour::Green.g
                                                                                               * 255.0) | (((signed int)(float)(UFG::qColour::Green.b * 255.0) | ((signed int)(float)(UFG::qColour::Green.a * 255.0) << 8)) << 8)) << 8);
    dword_14212B680 = -1107296256;
    qword_14212B684 = 1048576000i64;
    dword_14212B6AC = (signed int)(float)(UFG::qColour::Green.r * 255.0) | (((signed int)(float)(UFG::qColour::Green.g
                                                                                               * 255.0) | (((signed int)(float)(UFG::qColour::Green.b * 255.0) | ((signed int)(float)(UFG::qColour::Green.a * 255.0) << 8)) << 8)) << 8);
    qword_14212B6B0 = 0i64;
    dword_14212B6B8 = 0;
    dword_14212B6DC = (signed int)(float)(UFG::qColour::Green.r * 255.0) | (((signed int)(float)(UFG::qColour::Green.g
                                                                                               * 255.0) | (((signed int)(float)(UFG::qColour::Green.b * 255.0) | ((signed int)(float)(UFG::qColour::Green.a * 255.0) << 8)) << 8)) << 8);
    qword_14212B6E0 = 0i64;
    dword_14212B6E8 = 0;
    dword_14212B70C = (signed int)(float)(UFG::qColour::Green.r * 255.0) | (((signed int)(float)(UFG::qColour::Green.g
                                                                                               * 255.0) | (((signed int)(float)(UFG::qColour::Green.b * 255.0) | ((signed int)(float)(UFG::qColour::Green.a * 255.0) << 8)) << 8)) << 8);
    dword_14212B710 = 0;
    dword_14212B714 = -1098907648;
    dword_14212B718 = 0;
    dword_14212B73C = (signed int)(float)(UFG::qColour::Green.r * 255.0) | (((signed int)(float)(UFG::qColour::Green.g
                                                                                               * 255.0) | (((signed int)(float)(UFG::qColour::Green.b * 255.0) | ((signed int)(float)(UFG::qColour::Green.a * 255.0) << 8)) << 8)) << 8);
    dword_14212B740 = 1040187392;
    qword_14212B744 = 1048576000i64;
    dword_14212B76C = (signed int)(float)(UFG::qColour::Blue.r * 255.0) | (((signed int)(float)(UFG::qColour::Blue.g
                                                                                              * 255.0) | (((signed int)(float)(UFG::qColour::Blue.b * 255.0) | ((signed int)(float)(UFG::qColour::Blue.a * 255.0) << 8)) << 8)) << 8);
    dword_14212B770 = -1107296256;
    qword_14212B774 = 1048576000i64;
    dword_14212B79C = (signed int)(float)(UFG::qColour::Blue.r * 255.0) | (((signed int)(float)(UFG::qColour::Blue.g
                                                                                              * 255.0) | (((signed int)(float)(UFG::qColour::Blue.b * 255.0) | ((signed int)(float)(UFG::qColour::Blue.a * 255.0) << 8)) << 8)) << 8);
    dword_14212B7A0 = 1040187392;
    qword_14212B7A4 = 1048576000i64;
    dword_14212B7CC = (signed int)(float)(UFG::qColour::Blue.r * 255.0) | (((signed int)(float)(UFG::qColour::Blue.g
                                                                                              * 255.0) | (((signed int)(float)(UFG::qColour::Blue.b * 255.0) | ((signed int)(float)(UFG::qColour::Blue.a * 255.0) << 8)) << 8)) << 8);
    dword_14212B7D0 = -1107296256;
    dword_14212B7D4 = -1098907648;
    dword_14212B7D8 = 0;
    dword_14212B7FC = (signed int)(float)(UFG::qColour::Blue.r * 255.0) | (((signed int)(float)(UFG::qColour::Blue.g
                                                                                              * 255.0) | (((signed int)(float)(UFG::qColour::Blue.b * 255.0) | ((signed int)(float)(UFG::qColour::Blue.a * 255.0) << 8)) << 8)) << 8);
    dword_14212B800 = 1040187392;
    dword_14212B804 = -1098907648;
    dword_14212B808 = 0;
    dword_14212B82C = (signed int)(float)(UFG::qColour::Blue.r * 255.0) | (((signed int)(float)(UFG::qColour::Blue.g
                                                                                              * 255.0) | (((signed int)(float)(UFG::qColour::Blue.b * 255.0) | ((signed int)(float)(UFG::qColour::Blue.a * 255.0) << 8)) << 8)) << 8);
    dword_14212B830 = -1107296256;
    dword_14212B834 = -1098907648;
    dword_14212B838 = 0;
    dword_14212B85C = (signed int)(float)(UFG::qColour::Blue.r * 255.0) | (((signed int)(float)(UFG::qColour::Blue.g
                                                                                              * 255.0) | (((signed int)(float)(UFG::qColour::Blue.b * 255.0) | ((signed int)(float)(UFG::qColour::Blue.a * 255.0) << 8)) << 8)) << 8);
  }
  return spAxesVerts;
}

// File Line: 346
// RVA: 0x1453260
__int64 dynamic_initializer_for__Render::Poly::sModelHandle__()
{
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&Render::Poly::sModelHandle.mPrev);
  return atexit(dynamic_atexit_destructor_for__Render::Poly::sModelHandle__);
}

// File Line: 350
// RVA: 0xD740
void Render::Poly::DefaultModelInit(void)
{
  int v0; // edx
  unsigned int v1; // eax
  UFG::qResourceData *v2; // rax
  UFG::qResourceData *v3; // r14
  UFG::qBaseNodeRB *v4; // rcx
  _QWORD *v5; // rcx
  char *v6; // r15
  int v7; // edx
  unsigned int v8; // ebp
  Illusion::Buffer *v9; // rax
  UFG::qResourceData *v10; // rdi
  __int64 v11; // rax
  signed __int64 v12; // r8
  float v13; // xmm1_4
  float v14; // xmm2_4
  float v15; // xmm1_4
  float v16; // xmm2_4
  float v17; // xmm1_4
  float v18; // xmm2_4
  float v19; // xmm1_4
  float v20; // xmm2_4
  float v21; // xmm1_4
  float v22; // xmm2_4
  float v23; // xmm1_4
  float v24; // xmm2_4
  float v25; // xmm1_4
  float v26; // xmm2_4
  float v27; // xmm1_4
  float v28; // xmm2_4
  UFG::qResourceWarehouse *v29; // rax
  int v30; // edx
  unsigned int v31; // edi
  Illusion::Buffer *v32; // rax
  UFG::qResourceData *v33; // rbx
  __int64 v34; // rax
  _DWORD *v35; // rcx
  UFG::qResourceWarehouse *v36; // rax
  UFG::qResourceWarehouse *v37; // rax
  unsigned int v38; // ebx
  UFG::qResourceInventory *v39; // rax
  UFG::qResourceWarehouse *v40; // rax
  UFG::qString result; // [rsp+48h] [rbp-80h]
  UFG::qString v42; // [rsp+70h] [rbp-58h]

  UFG::qString::FormatEx(&v42, "DX10_PolyDefaultModel");
  v1 = v42.mStringHashUpper32;
  if ( v42.mStringHashUpper32 == -1 )
  {
    v1 = UFG::qStringHashUpper32(v42.mData, v42.mStringHashUpper32 | v0);
    v42.mStringHashUpper32 = v1;
  }
  Render::Poly::sModelUID = v1;
  v2 = Illusion::Factory::NewModel(v42.mData, v1, 1u, 0i64, 0i64, 0i64);
  v3 = v2;
  v4 = v2[2].mNode.mChild[0];
  if ( v4 )
    v5 = (_QWORD *)((char *)&v4[5].mUID + (_QWORD)v2);
  else
    v5 = 0i64;
  v6 = (char *)v5 + *v5;
  if ( !*v5 )
    v6 = 0i64;
  UFG::qString::FormatEx(&result, "PolyDefaultModel.VertexBuffer");
  v8 = result.mStringHash32;
  if ( result.mStringHash32 == -1 )
  {
    v8 = UFG::qStringHash32(result.mData, result.mStringHash32 | v7);
    result.mStringHash32 = v8;
  }
  v9 = Illusion::Factory::NewBuffer(result.mData, v8, 0xC0u, 0i64, result.mData, 0i64, 0i64);
  v10 = (UFG::qResourceData *)v9;
  v9->mBufferType = 0;
  v9->mElementByteSize = 48;
  v9->mNumElements = 4;
  v11 = v9->mData.mOffset;
  if ( v11 )
    v12 = (signed __int64)v10[1].mNode.mChild + v11;
  else
    v12 = 0i64;
  *(_QWORD *)(v12 + 48) = 0i64;
  *(_DWORD *)(v12 + 56) = 0;
  *(_QWORD *)v12 = 1065353216i64;
  *(_DWORD *)(v12 + 8) = 0;
  *(_DWORD *)(v12 + 96) = 1065353216;
  *(_QWORD *)(v12 + 100) = 1065353216i64;
  *(_DWORD *)(v12 + 144) = 0;
  *(_QWORD *)(v12 + 148) = 1065353216i64;
  *(_WORD *)(v12 + 60) = 0;
  *(_WORD *)(v12 + 62) = 0;
  *(_WORD *)(v12 + 12) = 15360;
  *(_WORD *)(v12 + 14) = 0;
  *(_WORD *)(v12 + 108) = 15360;
  *(_WORD *)(v12 + 110) = 15360;
  *(_WORD *)(v12 + 156) = 0;
  *(_WORD *)(v12 + 158) = 15360;
  *(_WORD *)(v12 + 64) = 0;
  *(_WORD *)(v12 + 66) = 0;
  *(_WORD *)(v12 + 16) = 15360;
  *(_WORD *)(v12 + 18) = 0;
  *(_WORD *)(v12 + 112) = 15360;
  *(_WORD *)(v12 + 114) = 15360;
  *(_WORD *)(v12 + 160) = 0;
  *(_WORD *)(v12 + 162) = 15360;
  *(_DWORD *)(v12 + 44) = -1;
  *(_DWORD *)(v12 + 92) = -1;
  *(_DWORD *)(v12 + 140) = -1;
  *(_DWORD *)(v12 + 188) = -1;
  v13 = UFG::qVector3::msAxisZ.y;
  v14 = UFG::qVector3::msAxisZ.z;
  *(float *)(v12 + 20) = UFG::qVector3::msAxisZ.x;
  *(float *)(v12 + 24) = v13;
  *(float *)(v12 + 28) = v14;
  v15 = UFG::qVector3::msAxisZ.y;
  v16 = UFG::qVector3::msAxisZ.z;
  *(float *)(v12 + 68) = UFG::qVector3::msAxisZ.x;
  *(float *)(v12 + 72) = v15;
  *(float *)(v12 + 76) = v16;
  v17 = UFG::qVector3::msAxisZ.y;
  v18 = UFG::qVector3::msAxisZ.z;
  *(float *)(v12 + 116) = UFG::qVector3::msAxisZ.x;
  *(float *)(v12 + 120) = v17;
  *(float *)(v12 + 124) = v18;
  v19 = UFG::qVector3::msAxisZ.y;
  v20 = UFG::qVector3::msAxisZ.z;
  *(float *)(v12 + 164) = UFG::qVector3::msAxisZ.x;
  *(float *)(v12 + 168) = v19;
  *(float *)(v12 + 172) = v20;
  v21 = UFG::qVector3::msAxisX.y;
  v22 = UFG::qVector3::msAxisX.z;
  *(float *)(v12 + 32) = UFG::qVector3::msAxisX.x;
  *(float *)(v12 + 36) = v21;
  *(float *)(v12 + 40) = v22;
  v23 = UFG::qVector3::msAxisX.y;
  v24 = UFG::qVector3::msAxisX.z;
  *(float *)(v12 + 80) = UFG::qVector3::msAxisX.x;
  *(float *)(v12 + 84) = v23;
  *(float *)(v12 + 88) = v24;
  v25 = UFG::qVector3::msAxisX.y;
  v26 = UFG::qVector3::msAxisX.z;
  *(float *)(v12 + 128) = UFG::qVector3::msAxisX.x;
  *(float *)(v12 + 132) = v25;
  *(float *)(v12 + 136) = v26;
  v27 = UFG::qVector3::msAxisX.y;
  v28 = UFG::qVector3::msAxisX.z;
  *(float *)(v12 + 176) = UFG::qVector3::msAxisX.x;
  *(float *)(v12 + 180) = v27;
  *(float *)(v12 + 184) = v28;
  v29 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v29, v10);
  *((_QWORD *)v6 + 28) = 3i64;
  *((_DWORD *)v6 + 58) = 2;
  *((_QWORD *)v6 + 30) = "DX10PolyDefaultModel";
  *((_DWORD *)v6 + 30) = v8;
  *((_DWORD *)v6 + 14) = Scaleform::Render::ShapeMeshProvider::GetLayerCount((hkDataClassDict *)&Render::gDynamicDescriptor);
  UFG::qString::~qString(&result);
  UFG::qString::FormatEx(&result, "DX10PolyDefaultModel.IndexBuffer");
  v31 = result.mStringHash32;
  if ( result.mStringHash32 == -1 )
  {
    v31 = UFG::qStringHash32(result.mData, result.mStringHash32 | v30);
    result.mStringHash32 = v31;
  }
  v32 = Illusion::Factory::NewBuffer(result.mData, v31, 0xCu, 0i64, result.mData, 0i64, 0i64);
  v33 = (UFG::qResourceData *)v32;
  v32->mBufferType = 1;
  v32->mElementByteSize = 2;
  v32->mNumElements = 6;
  v34 = v32->mData.mOffset;
  if ( v34 )
    v35 = (_DWORD *)((char *)v33[1].mNode.mChild + v34);
  else
    v35 = 0i64;
  *v35 = 0x10000;
  v35[1] = 131074;
  v35[2] = 196609;
  v36 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v36, v33);
  *((_DWORD *)v6 + 22) = v31;
  UFG::qString::~qString(&result);
  v37 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v37, v3);
  v38 = Render::Poly::sModelUID;
  v39 = `UFG::qGetResourceInventory<Illusion::Model>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Model>::`2::result )
  {
    v40 = UFG::qResourceWarehouse::Instance();
    v39 = UFG::qResourceWarehouse::GetInventory(v40, 0xA2ADCD77);
    `UFG::qGetResourceInventory<Illusion::Model>::`2::result = v39;
  }
  UFG::qResourceHandle::Init((UFG::qResourceHandle *)&Render::Poly::sModelHandle.mPrev, 0xA2ADCD77, v38, v39);
  UFG::qString::~qString(&v42);
}

// File Line: 483
// RVA: 0xC810
void __fastcall Render::Poly::Poly(Render::Poly *this, float x, float y, float w, float h, float z)
{
  this->mVertices = 0i64;
  Render::Poly::Init(this, x, y, w, h, z);
}

// File Line: 489
// RVA: 0x15C30
void __fastcall Render::Poly::Init(Render::Poly *this, float x, float y, float w, float h, float z)
{
  Render::Poly *v6; // rbx

  v6 = this;
  if ( !this->mVertices )
    this->mVertices = (Render::vDynamic *)UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0xC0u, 0x10u);
  Render::Poly::SetScreenPos(v6, x, y, w, h, z);
  Render::Poly::SetUVs(v6, 0.0, 0.0, 1.0, 1.0);
  if ( !v6->mVertices )
    Render::Poly::Init(v6, 0.0, 0.0, 1.0, 1.0, 0.0);
  v6->mVertices[1].mColour = -1;
  v6->mVertices->mColour = -1;
  v6->mVertices[2].mColour = -1;
  v6->mVertices[3].mColour = -1;
}

// File Line: 506
// RVA: 0x161F0
void __fastcall Render::Poly::SetColour(Render::Poly *this, UFG::qColour *colour)
{
  UFG::qColour *v2; // rdi
  Render::Poly *v3; // rbx
  int v4; // ecx

  v2 = colour;
  v3 = this;
  if ( !this->mVertices )
    Render::Poly::Init(this, 0.0, 0.0, 1.0, 1.0, 0.0);
  v4 = (signed int)(float)(v2->r * 255.0) | (((signed int)(float)(v2->g * 255.0) | (((signed int)(float)(v2->b * 255.0) | ((signed int)(float)(v2->a * 255.0) << 8)) << 8)) << 8);
  v3->mVertices[1].mColour = v4;
  v3->mVertices->mColour = v4;
  v3->mVertices[2].mColour = v4;
  v3->mVertices[3].mColour = v4;
}

// File Line: 535
// RVA: 0x162A0
void __fastcall Render::Poly::SetColours(Render::Poly *this, UFG::qColour *colour0, UFG::qColour *colour1, UFG::qColour *colour2, UFG::qColour *colour3)
{
  UFG::qColour *v5; // rdi
  UFG::qColour *v6; // rsi
  UFG::qColour *v7; // rbp
  Render::Poly *v8; // rbx

  v5 = colour2;
  v6 = colour1;
  v7 = colour0;
  v8 = this;
  if ( !this->mVertices )
    Render::Poly::Init(this, 0.0, 0.0, 1.0, 1.0, 0.0);
  v8->mVertices[1].mColour = (signed int)(float)(v7->r * 255.0) | (((signed int)(float)(v7->g * 255.0) | (((signed int)(float)(v7->b * 255.0) | ((signed int)(float)(v7->a * 255.0) << 8)) << 8)) << 8);
  v8->mVertices->mColour = (signed int)(float)(v6->r * 255.0) | (((signed int)(float)(v6->g * 255.0) | (((signed int)(float)(v6->b * 255.0) | ((signed int)(float)(v6->a * 255.0) << 8)) << 8)) << 8);
  v8->mVertices[2].mColour = (signed int)(float)(v5->r * 255.0) | (((signed int)(float)(v5->g * 255.0) | (((signed int)(float)(v5->b * 255.0) | ((signed int)(float)(v5->a * 255.0) << 8)) << 8)) << 8);
  v8->mVertices[3].mColour = (signed int)(float)(colour3->r * 255.0) | (((signed int)(float)(colour3->g * 255.0) | (((signed int)(float)(colour3->b * 255.0) | ((signed int)(float)(colour3->a * 255.0) << 8)) << 8)) << 8);
}

// File Line: 549
// RVA: 0x16440
void __fastcall Render::Poly::SetScreenPos(Render::Poly *this, UFG::qVector2 *p0, UFG::qVector2 *p1, UFG::qVector2 *p2, UFG::qVector2 *p3, float z)
{
  UFG::qVector2 *v6; // rdi
  UFG::qVector2 *v7; // rsi
  UFG::qVector2 *v8; // r14
  Render::Poly *v9; // rbx

  v6 = p2;
  v7 = p1;
  v8 = p0;
  v9 = this;
  if ( !this->mVertices )
    Render::Poly::Init(this, 0.0, 0.0, 1.0, 1.0, 0.0);
  v9->mVertices[1].mPosition.x = v8->x;
  v9->mVertices[1].mPosition.y = v8->y;
  v9->mVertices[1].mPosition.z = z;
  v9->mVertices->mPosition.x = v7->x;
  v9->mVertices->mPosition.y = v7->y;
  v9->mVertices->mPosition.z = z;
  v9->mVertices[2].mPosition.x = v6->x;
  v9->mVertices[2].mPosition.y = v6->y;
  v9->mVertices[2].mPosition.z = z;
  v9->mVertices[3].mPosition.x = p3->x;
  v9->mVertices[3].mPosition.y = p3->y;
  v9->mVertices[3].mPosition.z = z;
}

// File Line: 568
// RVA: 0x16520
void __fastcall Render::Poly::SetScreenPos(Render::Poly *this, float x, float y, float w, float h, float z)
{
  Render::Poly *v6; // rbx

  v6 = this;
  if ( !this->mVertices )
    Render::Poly::Init(this, 0.0, 0.0, 1.0, 1.0, 0.0);
  v6->mVertices[1].mPosition.x = x;
  v6->mVertices[1].mPosition.y = y;
  v6->mVertices[1].mPosition.z = z;
  v6->mVertices->mPosition.x = x + w;
  v6->mVertices->mPosition.y = y;
  v6->mVertices->mPosition.z = z;
  v6->mVertices[2].mPosition.x = x + w;
  v6->mVertices[2].mPosition.y = y + h;
  v6->mVertices[2].mPosition.z = z;
  v6->mVertices[3].mPosition.x = x;
  v6->mVertices[3].mPosition.y = y + h;
  v6->mVertices[3].mPosition.z = z;
}

// File Line: 582
// RVA: 0x16960
void __fastcall Render::Poly::SetUVs(Render::Poly *this, float u, float v, float u_width, float v_width)
{
  Render::Poly *v5; // rbx
  float v6; // xmm6_4
  float v7; // xmm8_4
  float v8; // xmm1_4
  unsigned int v9; // edx
  int v10; // er11
  float v11; // xmm0_4
  unsigned __int16 v12; // r11
  unsigned int v13; // edx
  unsigned int v14; // edx
  int v15; // er10
  unsigned __int16 v16; // r10
  unsigned int v17; // edx
  unsigned int v18; // edx
  int v19; // er9
  unsigned __int16 v20; // r9
  unsigned int v21; // edx
  unsigned int v22; // edx
  int v23; // er8
  unsigned __int16 v24; // r8
  unsigned int v25; // edx

  v5 = this;
  v6 = u;
  v7 = v;
  if ( !this->mVertices )
    Render::Poly::Init(this, 0.0, 0.0, 1.0, 1.0, 0.0);
  v8 = v + v_width;
  v9 = LODWORD(v6) & 0x7FFFFFFF;
  v10 = (LODWORD(v6) >> 16) & 0x8000;
  v11 = v6 + u_width;
  if ( (LODWORD(v6) & 0x7FFFFFFFu) <= 0x47FFEFFF )
  {
    if ( v9 >= 0x38800000 )
      v13 = v9 - 939524096;
    else
      v13 = (LODWORD(v6) & 0x7FFFFF | 0x800000u) >> (113 - (v9 >> 23));
    v12 = ((((v13 >> 13) & 1) + v13 + 4095) >> 13) | v10;
  }
  else
  {
    v12 = v10 | 0x7FFF;
  }
  v14 = LODWORD(v11) & 0x7FFFFFFF;
  v15 = (LODWORD(v11) >> 16) & 0x8000;
  if ( (LODWORD(v11) & 0x7FFFFFFFu) <= 0x47FFEFFF )
  {
    if ( v14 >= 0x38800000 )
      v17 = v14 - 939524096;
    else
      v17 = (LODWORD(v11) & 0x7FFFFF | 0x800000u) >> (113 - (v14 >> 23));
    v16 = ((((v17 >> 13) & 1) + v17 + 4095) >> 13) | v15;
  }
  else
  {
    v16 = v15 | 0x7FFF;
  }
  v18 = LODWORD(v) & 0x7FFFFFFF;
  v19 = (LODWORD(v) >> 16) & 0x8000;
  if ( (LODWORD(v) & 0x7FFFFFFFu) <= 0x47FFEFFF )
  {
    if ( v18 >= 0x38800000 )
      v21 = v18 - 939524096;
    else
      v21 = (LODWORD(v7) & 0x7FFFFF | 0x800000u) >> (113 - (v18 >> 23));
    v20 = ((((v21 >> 13) & 1) + v21 + 4095) >> 13) | v19;
  }
  else
  {
    v20 = v19 | 0x7FFF;
  }
  v22 = LODWORD(v8) & 0x7FFFFFFF;
  v23 = (LODWORD(v8) >> 16) & 0x8000;
  if ( (LODWORD(v8) & 0x7FFFFFFFu) <= 0x47FFEFFF )
  {
    if ( v22 >= 0x38800000 )
      v25 = v22 - 939524096;
    else
      v25 = (LODWORD(v8) & 0x7FFFFF | 0x800000u) >> (113 - (v22 >> 23));
    v24 = ((((v25 >> 13) & 1) + v25 + 4095) >> 13) | v23;
  }
  else
  {
    v24 = v23 | 0x7FFF;
  }
  v5->mVertices[1].mTexCoord0[0] = v12;
  v5->mVertices[1].mTexCoord0[1] = v20;
  v5->mVertices->mTexCoord0[0] = v16;
  v5->mVertices->mTexCoord0[1] = v20;
  v5->mVertices[2].mTexCoord0[0] = v16;
  v5->mVertices[2].mTexCoord0[1] = v24;
  v5->mVertices[3].mTexCoord0[0] = v12;
  v5->mVertices[3].mTexCoord0[1] = v24;
}

// File Line: 606
// RVA: 0x15540
Render::ViewSettings *__fastcall Render::ViewSettings::GetIdentity()
{
  if ( !(_S4 & 1) )
  {
    _S4 |= 1u;
    Render::ViewSettings::ViewSettings(
      &settings,
      &UFG::qMatrix44::msIdentity,
      &UFG::qMatrix44::msIdentity,
      -1,
      0.0,
      0.0);
  }
  return &settings;
}

// File Line: 618
// RVA: 0x15D30
void Render::View::InitShared(void)
{
  unsigned int v0; // eax
  int v1; // eax
  Illusion::Material *v2; // rbx
  int v3; // edi
  int v4; // eax
  Illusion::Material *v5; // rbx
  int v6; // eax
  Illusion::Material *v7; // rbx
  unsigned int v8; // eax
  Illusion::Material *v9; // rbx
  int v10; // eax
  Illusion::Material *v11; // rbx
  int v12; // eax
  UFG::qResourceWarehouse *v13; // rax
  Render::vDynamic *v14; // rax
  float *v15; // rcx

  Render::View::mScreenOffset = 0i64;
  v0 = UFG::qStringHash32("ViewPlat.Primitive", 0xFFFFFFFF);
  `anonymous namespace::gSimpleMaterial = Illusion::Factory::NewMaterial(
                                             "ViewPlat.Primitive",
                                             v0,
                                             5u,
                                             0i64,
                                             0i64,
                                             0i64);
  v1 = UFG::qStringHash32("SIMPLE", 0xFFFFFFFF);
  v2 = `anonymous namespace::gSimpleMaterial;
  v3 = v1;
  LOWORD(`anonymous namespace::gSimpleMaterial[1].mNode.mChild[0]) = 0;
  HIDWORD(v2[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v4 = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v2[1].mTypeUID = -1957338719;
  LODWORD(v2[1].mResourceHandles.mNode.mNext) = v3;
  LODWORD(v2[1].mNode.mParent) = v4;
  v5 = `anonymous namespace::gSimpleMaterial;
  *(_WORD *)&`anonymous namespace::gSimpleMaterial[1].mDebugName[12] = 0;
  *(_DWORD *)&v5[1].mDebugName[8] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v6 = UFG::qStringHash32("texDiffuse", 0xFFFFFFFF);
  LODWORD(v5[1].mStateBlockMask.mFlags[1]) = -1958479169;
  LODWORD(v5[1].mStateBlockMask.mFlags[0]) = -1324127765;
  *(_DWORD *)&v5[1].mDebugName[4] = v6;
  v7 = `anonymous namespace::gSimpleMaterial;
  LOWORD(`anonymous namespace::gSimpleMaterial[1].mMaterialUser.mOffset) = 0;
  *(&v7[1].mNumParams + 1) = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  v8 = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  LODWORD(v7[2].mResourceHandles.mNode.mPrev) = 315097330;
  v7[2].mNode.mUID = -1551679522;
  v7[1].mNumParams = v8;
  v9 = `anonymous namespace::gSimpleMaterial;
  LOWORD(`anonymous namespace::gSimpleMaterial[2].mTypeUID) = 0;
  HIDWORD(v9[2].mResourceHandles.mNode.mNext) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  v10 = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  *((_DWORD *)&v9[2].0 + 22) = 1002903008;
  *(_DWORD *)&v9[2].mDebugName[28] = 1660426324;
  LODWORD(v9[2].mResourceHandles.mNode.mNext) = v10;
  v11 = `anonymous namespace::gSimpleMaterial;
  LOWORD(`anonymous namespace::gSimpleMaterial[2].mStateBlockMask.mFlags[1]) = 0;
  HIDWORD(v11[2].mStateBlockMask.mFlags[0]) = UFG::qStringHash32("sbDepthBiasSortLayer", 0xFFFFFFFF);
  v12 = UFG::qStringHash32("sbDepthBiasSortLayer", 0xFFFFFFFF);
  LODWORD(v11[3].mNode.mChild[1]) = 1292158962;
  LODWORD(v11[2].mStateBlockMask.mFlags[0]) = v12;
  LODWORD(v11[3].mNode.mChild[0]) = 0;
  v13 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v13, (UFG::qResourceData *)&`anonymous namespace::gSimpleMaterial->mNode);
  v14 = `anonymous namespace::GetVertsCircle(0x40u, &UFG::qColour::White);
  if ( v14 )
  {
    v15 = &v14[1].mPosition.x;
    *(_QWORD *)&v14->mPosition.x = 0i64;
    v14->mPosition.z = 0.0;
    if ( &v14[1] < &v14[66] )
    {
      do
      {
        *v15 = 0.0;
        v15 += 12;
      }
      while ( v15 < &v14[66].mPosition.x );
    }
  }
}

// File Line: 664
// RVA: 0xC850
void __fastcall Render::View::View(Render::View *this, Render::ViewSettings *settings, Illusion::SubmitContext *submit_context)
{
  Render::View *v3; // rdi
  UFG::qMatrix44 *v4; // rcx
  UFG::qMatrix44 *v5; // r8
  UFG::qMatrix44 *v6; // rax
  UFG::qVector4 v7; // xmm1
  UFG::qVector4 v8; // xmm2
  UFG::qVector4 v9; // xmm3
  UFG::qMatrix44 *v10; // rdx
  float v11; // xmm0_4
  float v12; // xmm0_4
  float v13; // xmm0_4
  float v14; // xmm4_4
  float v15; // xmm0_4
  float v16; // xmm0_4
  float v17; // xmm4_4
  int v18; // xmm0_4
  float v19; // xmm0_4
  float v20; // xmm0_4
  int v21; // xmm0_4
  float v22; // xmm0_4
  int v23; // xmm0_4
  float v24; // xmm5_4
  __int128 v25; // xmm3
  __m128 v26; // xmm2
  float v27; // xmm4_4
  float v28; // xmm0_4
  __m128 v29; // xmm6
  float v30; // xmm4_4
  __m128 v31; // xmm2
  float v32; // xmm5_4
  float v33; // xmm0_4
  __m128 v34; // xmm6
  float v35; // xmm4_4
  __m128 v36; // xmm2
  float v37; // xmm5_4
  float v38; // xmm0_4
  __int128 v39; // xmm4
  float v40; // xmm5_4
  __m128 v41; // xmm2
  float v42; // xmm0_4
  float v43; // xmm5_4
  __m128 v44; // xmm6
  __m128 v45; // xmm2
  float v46; // xmm0_4
  __m128 v47; // xmm5
  __m128 v48; // xmm2
  float v49; // xmm0_4
  float v50; // xmm7_4
  UFG::qMatrix44 result; // [rsp+20h] [rbp-68h]

  v3 = this;
  this->mSettings = settings;
  this->mSubmitContext = submit_context;
  Render::ViewMetrics::Reset(&this->mViewMetrics);
  v4 = &v3->mSettings->mWorldView;
  v5 = &v3->mSettings->mProjection;
  v3->mLastBeginFrameCounter = 0;
  v6 = UFG::qMatrix44::operator*(v4, &result, v5);
  v7 = v6->v1;
  v8 = v6->v2;
  v9 = v6->v3;
  v3->mWorldViewProjection.v0 = v6->v0;
  v3->mWorldViewProjection.v1 = v7;
  v3->mWorldViewProjection.v2 = v8;
  v3->mWorldViewProjection.v3 = v9;
  v10 = &v3->mSettings->mWorldView;
  v3->mExtractedNearPlane = v3->mSettings->mProjection.v3.z / v3->mSettings->mProjection.v2.z;
  v3->mExtractedFarPlane = (float)(v10[1].v3.z - v10[1].v3.w) / (float)(v10[1].v2.z - v10[1].v2.w);
  UFG::qInverseAffine(&v3->mViewWorld, v10);
  v8.x = v3->mWorldViewProjection.v3.z;
  v7.x = v3->mWorldViewProjection.v2.z;
  v11 = v3->mWorldViewProjection.v1.z;
  v3->mFrustumPlanes[0].x = v3->mWorldViewProjection.v0.z;
  v3->mFrustumPlanes[0].y = v11;
  v3->mFrustumPlanes[0].z = v7.x;
  v3->mFrustumPlanes[0].w = v8.x;
  v8.x = v3->mWorldViewProjection.v2.w + v3->mWorldViewProjection.v2.x;
  v9.x = v3->mWorldViewProjection.v3.w + v3->mWorldViewProjection.v3.x;
  v12 = v3->mWorldViewProjection.v0.w + v3->mWorldViewProjection.v0.x;
  v3->mFrustumPlanes[1].y = v3->mWorldViewProjection.v1.w + v3->mWorldViewProjection.v1.x;
  v3->mFrustumPlanes[1].z = v8.x;
  v3->mFrustumPlanes[1].x = v12;
  v3->mFrustumPlanes[1].w = v9.x;
  v8.x = v3->mWorldViewProjection.v2.w - v3->mWorldViewProjection.v2.x;
  v9.x = v3->mWorldViewProjection.v3.w - v3->mWorldViewProjection.v3.x;
  v13 = v3->mWorldViewProjection.v0.w - v3->mWorldViewProjection.v0.x;
  v3->mFrustumPlanes[2].y = v3->mWorldViewProjection.v1.w - v3->mWorldViewProjection.v1.x;
  v3->mFrustumPlanes[2].z = v8.x;
  v3->mFrustumPlanes[2].x = v13;
  v3->mFrustumPlanes[2].w = v9.x;
  v8.x = v3->mWorldViewProjection.v2.w + v3->mWorldViewProjection.v2.y;
  v14 = v3->mWorldViewProjection.v3.w + v3->mWorldViewProjection.v3.y;
  v15 = v3->mWorldViewProjection.v0.w + v3->mWorldViewProjection.v0.y;
  v3->mFrustumPlanes[3].y = v3->mWorldViewProjection.v1.w + v3->mWorldViewProjection.v1.y;
  v3->mFrustumPlanes[3].z = v8.x;
  v3->mFrustumPlanes[3].x = v15;
  v3->mFrustumPlanes[3].w = v14;
  v9.x = v3->mWorldViewProjection.v3.w - v3->mWorldViewProjection.v3.y;
  v8.x = v3->mWorldViewProjection.v2.w - v3->mWorldViewProjection.v2.y;
  v16 = v3->mWorldViewProjection.v0.w - v3->mWorldViewProjection.v0.y;
  v3->mFrustumPlanes[4].y = v3->mWorldViewProjection.v1.w - v3->mWorldViewProjection.v1.y;
  v3->mFrustumPlanes[4].z = v8.x;
  v3->mFrustumPlanes[4].x = v16;
  v3->mFrustumPlanes[4].w = v9.x;
  v8.x = v3->mWorldViewProjection.v2.w - v3->mWorldViewProjection.v2.z;
  v7.x = v3->mWorldViewProjection.v1.w - v3->mWorldViewProjection.v1.z;
  v17 = v3->mWorldViewProjection.v3.w - v3->mWorldViewProjection.v3.z;
  v3->mFrustumPlanes[5].x = v3->mWorldViewProjection.v0.w - v3->mWorldViewProjection.v0.z;
  v3->mFrustumPlanes[5].y = v7.x;
  v3->mFrustumPlanes[5].z = v8.x;
  v3->mFrustumPlanes[5].w = v17;
  LODWORD(v8.x) = LODWORD(v3->mFrustumPlanes[0].y) ^ _xmm[0];
  LODWORD(v7.x) = LODWORD(v3->mFrustumPlanes[0].z) ^ _xmm[0];
  v18 = LODWORD(v3->mFrustumPlanes[0].w) ^ _xmm[0];
  LODWORD(v3->mFrustumPlanes[0].x) ^= _xmm[0];
  v3->mFrustumPlanes[0].y = v8.x;
  v3->mFrustumPlanes[0].z = v7.x;
  LODWORD(v3->mFrustumPlanes[0].w) = v18;
  LODWORD(v8.x) = LODWORD(v3->mFrustumPlanes[1].y) ^ _xmm[0];
  v7.x = v3->mFrustumPlanes[1].z;
  v19 = v3->mFrustumPlanes[1].w;
  LODWORD(v3->mFrustumPlanes[1].x) ^= _xmm[0];
  v3->mFrustumPlanes[1].y = v8.x;
  LODWORD(v3->mFrustumPlanes[1].z) = LODWORD(v7.x) ^ _xmm[0];
  LODWORD(v3->mFrustumPlanes[1].w) = LODWORD(v19) ^ _xmm[0];
  LODWORD(v8.x) = LODWORD(v3->mFrustumPlanes[2].y) ^ _xmm[0];
  LODWORD(v7.x) = LODWORD(v3->mFrustumPlanes[2].z) ^ _xmm[0];
  v20 = v3->mFrustumPlanes[2].w;
  LODWORD(v3->mFrustumPlanes[2].x) ^= _xmm[0];
  v3->mFrustumPlanes[2].y = v8.x;
  v3->mFrustumPlanes[2].z = v7.x;
  LODWORD(v3->mFrustumPlanes[2].w) = LODWORD(v20) ^ _xmm[0];
  LODWORD(v8.x) = LODWORD(v3->mFrustumPlanes[3].y) ^ _xmm[0];
  LODWORD(v7.x) = LODWORD(v3->mFrustumPlanes[3].z) ^ _xmm[0];
  v21 = LODWORD(v3->mFrustumPlanes[3].w) ^ _xmm[0];
  LODWORD(v3->mFrustumPlanes[3].x) ^= _xmm[0];
  v3->mFrustumPlanes[3].y = v8.x;
  v3->mFrustumPlanes[3].z = v7.x;
  LODWORD(v3->mFrustumPlanes[3].w) = v21;
  LODWORD(v8.x) = LODWORD(v3->mFrustumPlanes[4].y) ^ _xmm[0];
  v7.x = v3->mFrustumPlanes[4].z;
  v22 = v3->mFrustumPlanes[4].w;
  LODWORD(v3->mFrustumPlanes[4].x) ^= _xmm[0];
  v3->mFrustumPlanes[4].y = v8.x;
  LODWORD(v3->mFrustumPlanes[4].z) = LODWORD(v7.x) ^ _xmm[0];
  LODWORD(v3->mFrustumPlanes[4].w) = LODWORD(v22) ^ _xmm[0];
  LODWORD(v8.x) = LODWORD(v3->mFrustumPlanes[5].y) ^ _xmm[0];
  LODWORD(v7.x) = LODWORD(v3->mFrustumPlanes[5].z) ^ _xmm[0];
  v23 = LODWORD(v3->mFrustumPlanes[5].w) ^ _xmm[0];
  LODWORD(v3->mFrustumPlanes[5].x) ^= _xmm[0];
  v3->mFrustumPlanes[5].y = v8.x;
  v3->mFrustumPlanes[5].z = v7.x;
  LODWORD(v3->mFrustumPlanes[5].w) = v23;
  v24 = v3->mFrustumPlanes[0].y;
  v25 = LODWORD(v3->mFrustumPlanes[0].x);
  v26 = (__m128)v25;
  v27 = v3->mFrustumPlanes[0].z;
  v26.m128_f32[0] = (float)((float)(*(float *)&v25 * *(float *)&v25) + (float)(v24 * v24)) + (float)(v27 * v27);
  LODWORD(v28) = (unsigned __int128)_mm_sqrt_ps(v26);
  v7.x = (float)(1.0 / v28) * v3->mFrustumPlanes[0].w;
  v3->mFrustumPlanes[0].x = *(float *)&v25 * (float)(1.0 / v28);
  v3->mFrustumPlanes[0].y = v24 * (float)(1.0 / v28);
  v3->mFrustumPlanes[0].z = v27 * (float)(1.0 / v28);
  v3->mFrustumPlanes[0].w = v7.x;
  v29 = (__m128)LODWORD(v3->mFrustumPlanes[1].y);
  v30 = v3->mFrustumPlanes[1].x;
  v31 = v29;
  v32 = v3->mFrustumPlanes[1].z;
  v31.m128_f32[0] = (float)((float)(v29.m128_f32[0] * v29.m128_f32[0]) + (float)(v30 * v30)) + (float)(v32 * v32);
  LODWORD(v33) = (unsigned __int128)_mm_sqrt_ps(v31);
  *(float *)&v25 = (float)(1.0 / v33) * v3->mFrustumPlanes[1].w;
  v3->mFrustumPlanes[1].x = v30 * (float)(1.0 / v33);
  v3->mFrustumPlanes[1].y = v29.m128_f32[0] * (float)(1.0 / v33);
  v3->mFrustumPlanes[1].z = v32 * (float)(1.0 / v33);
  LODWORD(v3->mFrustumPlanes[1].w) = v25;
  v34 = (__m128)LODWORD(v3->mFrustumPlanes[2].y);
  v35 = v3->mFrustumPlanes[2].x;
  v36 = v34;
  v37 = v3->mFrustumPlanes[2].z;
  v36.m128_f32[0] = (float)((float)(v34.m128_f32[0] * v34.m128_f32[0]) + (float)(v35 * v35)) + (float)(v37 * v37);
  LODWORD(v38) = (unsigned __int128)_mm_sqrt_ps(v36);
  *(float *)&v25 = (float)(1.0 / v38) * v3->mFrustumPlanes[2].w;
  v3->mFrustumPlanes[2].x = v35 * (float)(1.0 / v38);
  v3->mFrustumPlanes[2].y = v34.m128_f32[0] * (float)(1.0 / v38);
  v3->mFrustumPlanes[2].z = v37 * (float)(1.0 / v38);
  LODWORD(v3->mFrustumPlanes[2].w) = v25;
  v34.m128_i32[0] = LODWORD(v3->mFrustumPlanes[3].y);
  v39 = LODWORD(v3->mFrustumPlanes[3].x);
  v40 = v3->mFrustumPlanes[3].z;
  v41 = (__m128)v39;
  v41.m128_f32[0] = (float)((float)(*(float *)&v39 * *(float *)&v39) + (float)(v34.m128_f32[0] * v34.m128_f32[0]))
                  + (float)(v40 * v40);
  LODWORD(v42) = (unsigned __int128)_mm_sqrt_ps(v41);
  *(float *)&v25 = (float)(1.0 / v42) * v3->mFrustumPlanes[3].w;
  v3->mFrustumPlanes[3].x = *(float *)&v39 * (float)(1.0 / v42);
  v3->mFrustumPlanes[3].y = v34.m128_f32[0] * (float)(1.0 / v42);
  v3->mFrustumPlanes[3].z = v40 * (float)(1.0 / v42);
  LODWORD(v3->mFrustumPlanes[3].w) = v25;
  *(float *)&v25 = v3->mFrustumPlanes[4].x;
  v43 = v3->mFrustumPlanes[4].z;
  v44 = (__m128)LODWORD(v3->mFrustumPlanes[4].y);
  v45 = v44;
  v45.m128_f32[0] = (float)((float)(v44.m128_f32[0] * v44.m128_f32[0]) + (float)(*(float *)&v25 * *(float *)&v25))
                  + (float)(v43 * v43);
  LODWORD(v46) = (unsigned __int128)_mm_sqrt_ps(v45);
  *(float *)&v39 = (float)(1.0 / v46) * v3->mFrustumPlanes[4].w;
  v3->mFrustumPlanes[4].x = (float)(1.0 / v46) * *(float *)&v25;
  v3->mFrustumPlanes[4].y = v44.m128_f32[0] * (float)(1.0 / v46);
  v3->mFrustumPlanes[4].z = v43 * (float)(1.0 / v46);
  LODWORD(v3->mFrustumPlanes[4].w) = v39;
  v47 = (__m128)LODWORD(v3->mFrustumPlanes[5].y);
  *(float *)&v25 = v3->mFrustumPlanes[5].x;
  v48 = v47;
  *(float *)&v39 = v3->mFrustumPlanes[5].z;
  v48.m128_f32[0] = (float)((float)(v47.m128_f32[0] * v47.m128_f32[0]) + (float)(*(float *)&v25 * *(float *)&v25))
                  + (float)(*(float *)&v39 * *(float *)&v39);
  LODWORD(v49) = (unsigned __int128)_mm_sqrt_ps(v48);
  v50 = (float)(1.0 / v49) * v3->mFrustumPlanes[5].w;
  v3->mFrustumPlanes[5].x = (float)(1.0 / v49) * *(float *)&v25;
  v3->mFrustumPlanes[5].y = v47.m128_f32[0] * (float)(1.0 / v49);
  v3->mFrustumPlanes[5].z = *(float *)&v39 * (float)(1.0 / v49);
  v3->mFrustumPlanes[5].w = v50;
  Render::ViewMetrics::Reset(&v3->mViewMetrics);
}

// File Line: 696
// RVA: 0xD2D0
void __fastcall Render::View::BeginTarget(Render::View *this, Illusion::Target *target, const char *description, unsigned int dest_slice_face, unsigned int dest_mip_level, Illusion::ViewportScissorState *vp_scissor, bool clear_on_resolve, bool ignore_resolve_depth, bool ps4_decompress_depth, bool d3d_disable_depth_copy)
{
  unsigned int v10; // er12
  const char *v11; // r13
  Illusion::Target *v12; // r14
  Render::View *v13; // rdi
  Illusion::SubmitContext *v14; // rbx
  int v15; // esi
  Illusion::ViewportScissorState *v16; // rbx
  Illusion::SubmitContext *v17; // rax
  int v18; // esi
  char *v19; // rax
  char *v20; // r9
  Illusion::SubmitContext *v21; // rax
  UFG::qMatrix44 *v22; // rbx
  unsigned __int16 v23; // ax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v24; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v25; // rax
  Render::cbViewTransformState v26; // [rsp+30h] [rbp-50h]

  v10 = dest_slice_face;
  v11 = description;
  v12 = target;
  v13 = this;
  v14 = this->mSubmitContext;
  UFG::qMemSet(v14->mStateValues.mParamValues, 0, 0x400u);
  v15 = 0;
  v14->mStateValues.mSetValueMask.mFlags[1] = 0i64;
  v14->mStateValues.mSetValueMask.mFlags[0] = 0i64;
  v16 = vp_scissor;
  if ( !vp_scissor )
  {
    v16 = (Illusion::ViewportScissorState *)UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x30u, 0x10u);
    Illusion::SetFullscreenViewportScissor(v12, v16, dest_mip_level);
  }
  v17 = v13->mSubmitContext;
  v17->mStateValues.mSetValueMask.mFlags[0] |= 0x1000ui64;
  v17->mStateValues.mParamValues[12] = v16;
  LOBYTE(v15) = clear_on_resolve != 0;
  v18 = (d3d_disable_depth_copy != 0 ? 8 : 0) | (ps4_decompress_depth != 0 ? 4 : 0) | (ignore_resolve_depth != 0 ? 2 : 0) | v15;
  v19 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x20u, 0x10u);
  v20 = v19;
  if ( v19 )
  {
    *(_QWORD *)v19 = v12;
    *((_DWORD *)v19 + 2) = v10;
    *((_DWORD *)v19 + 3) = dest_mip_level;
    *((_DWORD *)v19 + 4) = v18;
    *((_QWORD *)v19 + 3) = v11;
  }
  v21 = v13->mSubmitContext;
  v21->mStateValues.mSetValueMask.mFlags[0] |= 0x800ui64;
  v21->mStateValues.mParamValues[11] = v20;
  ((void (__fastcall *)(Illusion::SubmitContext *, signed __int64))v13->mSubmitContext->vfptr->AddRenderCommand)(
    v13->mSubmitContext,
    14i64);
  ((void (__fastcall *)(Illusion::SubmitContext *, signed __int64, _QWORD, Illusion::ViewportScissorState *, signed __int64))v13->mSubmitContext->vfptr->AddRenderCommand)(
    v13->mSubmitContext,
    9i64,
    0i64,
    v16,
    -2i64);
  Render::ViewMetrics::BeginTarget(&v13->mViewMetrics);
  v22 = &v13->mSettings->mProjection;
  v26.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v26;
  v26.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v26;
  v26.mCallback = 0i64;
  v26.mStateParamIndex = Render::cbViewTransformState::sStateParamIndex;
  *(_WORD *)&v26.mFlags = 1;
  if ( (_WORD)Render::cbViewTransformState::sStateParamIndex == -1 )
  {
    v23 = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbViewTransform");
    Render::cbViewTransformState::sStateParamIndex = v23;
    v26.mStateParamIndex = v23;
  }
  v26.mWorldViewProjection = &v13->mWorldViewProjection;
  v26.mViewWorld = &v13->mViewWorld;
  v26.mProjection = v22;
  v26.mScreenOffset = &Render::View::mScreenOffset;
  v26.mCached_Remote.m_Stream = 0i64;
  Render::cbViewTransformState::SetStateBlock(&v26, &v13->mSubmitContext->mStateValues);
  v24 = v26.mPrev;
  v25 = v26.mNext;
  v26.mPrev->mNext = v26.mNext;
  v25->mPrev = v24;
}

// File Line: 768
// RVA: 0x15510
void __fastcall Render::View::EndTarget(Render::View *this)
{
  Render::View *v1; // rbx

  v1 = this;
  Render::ViewMetrics::EndTarget(&this->mViewMetrics);
  v1->mSubmitContext->vfptr->AddRenderCommand(
    v1->mSubmitContext,
    15,
    0,
    v1->mSubmitContext->mStateValues.mParamValues[11]);
}

// File Line: 778
// RVA: 0xD1F0
void __fastcall Render::View::AddMetric_NumCompositeProcessed(Render::View *this, int count)
{
  this->mViewMetrics.mNumCompositeProcessed += count;
}

// File Line: 783
// RVA: 0xD1C0
void __fastcall Render::View::AddMetric_DrawComposite(Render::View *this, float time)
{
  this->mViewMetrics.mDrawComposite = time + this->mViewMetrics.mDrawComposite;
}

// File Line: 788
// RVA: 0xD1E0
void __fastcall Render::View::AddMetric_DrawScenery(Render::View *this, float time)
{
  this->mViewMetrics.mDrawScenery = time + this->mViewMetrics.mDrawScenery;
}

// File Line: 793
// RVA: 0xD220
void __fastcall Render::View::AddMetric_NumSkinnedModelsRendered(Render::View *this, int count)
{
  this->mViewMetrics.mNumSkinnedModelsRendered += count;
}

// File Line: 798
// RVA: 0xD210
void __fastcall Render::View::AddMetric_NumRigidModelsRendered(Render::View *this, int count)
{
  this->mViewMetrics.mNumRigidModelsRendered += count;
}

// File Line: 813
// RVA: 0xD200
void __fastcall Render::View::AddMetric_NumParticles(Render::View *this, int count)
{
  this->mViewMetrics.mNumParticles += count;
}

// File Line: 818
// RVA: 0x16020
void __fastcall Render::View::Metric_BeginTarget(Render::View *this)
{
  Render::ViewMetrics::BeginTarget(&this->mViewMetrics);
}

// File Line: 823
// RVA: 0x16030
void __fastcall Render::View::Metric_EndTarget(Render::View *this)
{
  Render::ViewMetrics::EndTarget(&this->mViewMetrics);
}

// File Line: 829
// RVA: 0x155C0
Illusion::StateValues *__fastcall Render::View::GetStateValues(Render::View *this)
{
  return &this->mSubmitContext->mStateValues;
}

// File Line: 835
// RVA: 0x155B0
Illusion::StateArgs *__fastcall Render::View::GetStateArgs(Render::View *this)
{
  return &this->mSubmitContext->mStateArgs;
}

// File Line: 840
// RVA: 0xD4D0
void __fastcall Render::View::Clear(Render::View *this, UFG::qColour *colour, unsigned int flags, float depth, unsigned int stencil)
{
  unsigned int v5; // esi
  UFG::qColour *v6; // rbx
  Render::View *v7; // rdi
  void *v8; // rbp
  char *v9; // rax
  char *v10; // r9

  v5 = flags;
  v6 = colour;
  v7 = this;
  v8 = this->mSubmitContext->mStateValues.mParamValues[11];
  v9 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x28u, 8u);
  v10 = v9;
  if ( v9 )
  {
    *(_QWORD *)v9 = v8;
    *((_DWORD *)v9 + 2) = LODWORD(v6->r);
    *((_DWORD *)v9 + 3) = LODWORD(v6->g);
    *((_DWORD *)v9 + 4) = LODWORD(v6->b);
    *((_DWORD *)v9 + 5) = LODWORD(v6->a);
    *((_DWORD *)v9 + 6) = v5;
    *((float *)v9 + 7) = depth;
    *((_DWORD *)v9 + 8) = stencil;
  }
  else
  {
    v10 = 0i64;
  }
  v7->mSubmitContext->vfptr->AddRenderCommand(v7->mSubmitContext, 16, 0, v10);
}

// File Line: 850
// RVA: 0x15F80
_BOOL8 __fastcall Render::View::IsInView(Render::View *this, Illusion::ModelHandle *model_handle, UFG::qMatrix44 *local_world, float *distance_from_near_plane)
{
  UFG::ModelData *v4; // rax
  Render::View *v5; // rbx
  float v6; // xmm1_4
  float v7; // xmm2_4
  float *v8; // rdi
  float v9; // xmm3_4
  int v10; // xmm1_4
  UFG::qVector3 max; // [rsp+20h] [rbp-28h]
  UFG::qVector3 min; // [rsp+30h] [rbp-18h]

  v4 = (UFG::ModelData *)model_handle->mData;
  v5 = this;
  v6 = *(float *)&v4->mModels.mData.mFlags;
  v7 = v4->mAABBMin.x;
  v8 = distance_from_near_plane;
  LODWORD(min.x) = v4->mModels.mData.mNumItems;
  min.y = v6;
  min.z = v7;
  v9 = v4->mAABBMax.x;
  v10 = v4->mLODBias;
  max.x = v4->mAABBMin.z;
  LODWORD(max.y) = v10;
  max.z = v9;
  TransformAABB(local_world, &min, &max);
  return (unsigned int)IntersectAABBFrustum(v5->mFrustumPlanes, &min, &max, v8) != 2;
}

// File Line: 866
// RVA: 0x15F60
_BOOL8 __fastcall Render::View::IsInView(Render::View *this, UFG::qVector3 *vmin, UFG::qVector3 *vmax, float *distance_from_near_plane)
{
  return (unsigned int)IntersectAABBFrustum(this->mFrustumPlanes, vmin, vmax, distance_from_near_plane) != 2;
}

// File Line: 875
// RVA: 0x155E0
__int64 __fastcall Render::View::GetTargetWidth(Render::View *this)
{
  return **(unsigned int **)this->mSubmitContext->mStateValues.mParamValues[11];
}

// File Line: 884
// RVA: 0x155D0
__int64 __fastcall Render::View::GetTargetHeight(Render::View *this)
{
  return *(unsigned int *)(*(_QWORD *)this->mSubmitContext->mStateValues.mParamValues[11] + 4i64);
}

// File Line: 917
// RVA: 0xEB70
void __fastcall Render::View::Draw(Render::View *this, Illusion::Primitive *prim, Illusion::Material *material, UFG::qMatrix44 *local_world)
{
  UFG::qMatrix44 *v4; // r14
  Illusion::Material *v5; // r12
  Illusion::Primitive *v6; // r13
  Render::View *v7; // rdi
  Illusion::StateArgs *v8; // rbx
  unsigned __int16 v9; // ax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v10; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v11; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v12; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v13; // rax
  UFG::qMatrix44 *v14; // r15
  unsigned __int16 v15; // ax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v16; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v17; // rax
  unsigned __int64 *v18; // rdx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v19; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v20; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v21; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v22; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v23; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v24; // rax
  Render::cbScreenProjectionState arg; // [rsp+10h] [rbp-21h]
  Render::cbLocalProjectionState v26; // [rsp+38h] [rbp+7h]

  v4 = local_world;
  v5 = material;
  v6 = prim;
  v7 = this;
  v8 = &this->mSubmitContext->mStateArgs;
  if ( local_world )
  {
    v14 = &this->mWorldViewProjection;
    Render::cbLocalTransformState::cbLocalTransformState(
      (Render::cbLocalTransformState *)&arg,
      &this->mSettings->mWorldView,
      &this->mWorldViewProjection,
      local_world);
    v26.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v26;
    v26.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v26;
    v26.mCallback = 0i64;
    v26.mStateParamIndex = Render::cbLocalProjectionState::sStateParamIndex;
    *(_WORD *)&v26.mFlags = 1;
    if ( (_WORD)Render::cbLocalProjectionState::sStateParamIndex == -1 )
    {
      v15 = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbLocalProjection");
      Render::cbLocalProjectionState::sStateParamIndex = v15;
      v26.mStateParamIndex = v15;
    }
    v26.mCached_Remote.m_Stream = 0i64;
    v26.mWorldViewProjection = v14;
    v26.mLocalWorld = v4;
    Illusion::StateArgs::Set<Render::cbLocalTransformState>(v8, (Render::cbLocalTransformState *)&arg);
    Illusion::StateArgs::Set<Render::cbLocalProjectionState>(v8, &v26);
    Illusion::SubmitContext::Draw(v7->mSubmitContext, v6, v5);
    v16 = v26.mPrev;
    v17 = v26.mNext;
    v26.mPrev->mNext = v26.mNext;
    v17->mPrev = v16;
    v26.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v26;
    v26.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v26;
    v26.mIsSet = 0;
    if ( (Illusion::StateArgs *)v8->mStateArgsCreateMask.mFlags[2 * (v26.mStateParamIndex + 3i64) + 1] == (Illusion::StateArgs *)((char *)v8 + 16 * (v26.mStateParamIndex + 3i64)) )
    {
      v18 = &v8->mStateArgsCreateMask.mFlags[(unsigned int)v26.mStateParamIndex >> 6];
      *v18 &= ~(1i64 << (v26.mStateParamIndex & 0x3F));
    }
    v19 = arg.mPrev;
    v20 = arg.mNext;
    arg.mPrev->mNext = arg.mNext;
    v20->mPrev = v19;
    arg.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
    arg.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
    arg.mIsSet = 0;
    if ( (Illusion::StateArgs *)v8->mStateArgsCreateMask.mFlags[2 * (arg.mStateParamIndex + 3i64) + 1] == (Illusion::StateArgs *)((char *)v8 + 16 * (arg.mStateParamIndex + 3i64)) )
      v8->mStateArgsCreateMask.mFlags[(unsigned int)arg.mStateParamIndex >> 6] &= ~(1i64 << (arg.mStateParamIndex & 0x3F));
    v21 = v26.mPrev;
    v22 = v26.mNext;
    v26.mPrev->mNext = v26.mNext;
    v22->mPrev = v21;
    v23 = arg.mPrev;
    v24 = arg.mNext;
    arg.mPrev->mNext = arg.mNext;
    v24->mPrev = v23;
  }
  else
  {
    arg.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
    arg.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
    arg.mCallback = 0i64;
    arg.mStateParamIndex = Render::cbScreenProjectionState::sStateParamIndex;
    *(_WORD *)&arg.mFlags = 1;
    if ( (_WORD)Render::cbScreenProjectionState::sStateParamIndex == -1 )
    {
      v9 = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbLocalTransform");
      Render::cbScreenProjectionState::sStateParamIndex = v9;
      arg.mStateParamIndex = v9;
    }
    Illusion::StateArgs::Set<Render::cbScreenProjectionState>(v8, &arg);
    Illusion::SubmitContext::Draw(v7->mSubmitContext, v6, v5);
    v10 = arg.mPrev;
    v11 = arg.mNext;
    arg.mPrev->mNext = arg.mNext;
    v11->mPrev = v10;
    arg.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
    arg.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
    arg.mIsSet = 0;
    if ( (Illusion::StateArgs *)v8->mStateArgsCreateMask.mFlags[2 * (arg.mStateParamIndex + 3i64) + 1] == (Illusion::StateArgs *)((char *)v8 + 16 * (arg.mStateParamIndex + 3i64)) )
      v8->mStateArgsCreateMask.mFlags[(unsigned int)arg.mStateParamIndex >> 6] &= ~(1i64 << (arg.mStateParamIndex & 0x3F));
    v12 = arg.mPrev;
    v13 = arg.mNext;
    arg.mPrev->mNext = arg.mNext;
    v13->mPrev = v12;
    arg.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
  }
}

// File Line: 953
// RVA: 0xE880
void __fastcall Render::View::Draw(Render::View *this, Render::Poly *poly, Illusion::Material *material, UFG::qMatrix44 *local_world)
{
  UFG::qMatrix44 *v4; // r14
  Illusion::Material *v5; // r13
  Render::Poly *v6; // r15
  Render::View *v7; // rsi
  Illusion::StateArgs *v8; // r12
  unsigned int v9; // ebx
  UFG::qResourceInventory *v10; // rax
  UFG::qResourceWarehouse *v11; // rax
  unsigned __int16 v12; // ax
  UFG::qResourceData *v13; // rcx
  unsigned int v14; // eax
  __int64 v15; // rdi
  __int64 v16; // r14
  UFG::qBaseNodeRB *v17; // rax
  signed __int64 v18; // rax
  signed __int64 v19; // rcx
  __int64 v20; // rax
  Illusion::Mesh *v21; // r8
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v22; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v23; // rax
  unsigned __int64 *v24; // rdx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v25; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v26; // rax
  Illusion::Primitive *v27; // rax
  Illusion::Primitive *v28; // rdi
  __m128i debug_name_override; // [rsp+28h] [rbp-19h]
  bool dupe_vertex_buffer[16]; // [rsp+38h] [rbp-9h]
  char v31; // [rsp+48h] [rbp+7h]
  Render::cbScreenProjectionState arg; // [rsp+58h] [rbp+17h]

  v4 = local_world;
  v5 = material;
  v6 = poly;
  v7 = this;
  v8 = &this->mSubmitContext->mStateArgs;
  if ( !(_S5 & 1) )
  {
    _S5 |= 1u;
    UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&vertex_decl_handle.mPrev);
    atexit(Render::View::Draw_::_2_::_dynamic_atexit_destructor_for__vertex_decl_handle__);
  }
  if ( !vertex_decl_handle.mData )
  {
    v9 = UFG::qStringHash32("VertexDecl.Dynamic", 0xFFFFFFFF);
    v10 = `UFG::qGetResourceInventory<Illusion::VertexDecl>::`2::result;
    if ( !`UFG::qGetResourceInventory<Illusion::VertexDecl>::`2::result )
    {
      v11 = UFG::qResourceWarehouse::Instance();
      v10 = UFG::qResourceWarehouse::GetInventory(v11, 0x3E5FDA3Eu);
      `UFG::qGetResourceInventory<Illusion::VertexDecl>::`2::result = v10;
    }
    UFG::qResourceHandle::Init((UFG::qResourceHandle *)&vertex_decl_handle.mPrev, 0x3E5FDA3Eu, v9, v10);
    Render::Poly::DefaultModelInit();
  }
  if ( v6->mVertices )
  {
    v27 = Illusion::Primitive::Create("Poly");
    v28 = v27;
    if ( v27
      && Illusion::Primitive::SetBuffers(
           v27,
           TRIANGLESTRIP,
           v6->mVertices,
           4,
           (Illusion::VertexDecl *)vertex_decl_handle.mData,
           0i64,
           0,
           1) )
    {
      Render::View::Draw(v7, v28, v5, v4);
    }
  }
  else if ( v4 )
  {
    Render::View::Draw(v7, &Render::Poly::sModelHandle, v4, 0);
  }
  else
  {
    arg.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
    arg.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
    arg.mCallback = 0i64;
    arg.mStateParamIndex = Render::cbScreenProjectionState::sStateParamIndex;
    *(_WORD *)&arg.mFlags = 1;
    if ( (_WORD)Render::cbScreenProjectionState::sStateParamIndex == -1 )
    {
      v12 = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbLocalTransform");
      Render::cbScreenProjectionState::sStateParamIndex = v12;
      arg.mStateParamIndex = v12;
    }
    Illusion::StateArgs::Set<Render::cbScreenProjectionState>(v8, &arg);
    debug_name_override = 0ui64;
    v13 = Render::Poly::sModelHandle.mData;
    v14 = (unsigned int)Render::Poly::sModelHandle.mData[2].mNode.mChild[1];
    if ( v14 )
    {
      v15 = 0i64;
      v16 = v14;
      while ( 1 )
      {
        v17 = v13[2].mNode.mChild[0];
        if ( v17 )
          v18 = (signed __int64)&v17[5].mUID + (_QWORD)v13;
        else
          v18 = 0i64;
        v19 = v15 + v18;
        v20 = *(_QWORD *)(v15 + v18);
        v21 = (Illusion::Mesh *)(v20 + v19);
        if ( !v20 )
          v21 = 0i64;
        _mm_store_si128((__m128i *)dupe_vertex_buffer, debug_name_override);
        debug_name_override = *(__m128i *)Illusion::SubmitContext::Draw(
                                            v7->mSubmitContext,
                                            (UFG::BitFlags128 *)&v31,
                                            v21,
                                            v5,
                                            (UFG::BitFlags128 *)dupe_vertex_buffer,
                                            v21);
        ++v7->mViewMetrics.mNumMeshsRendered;
        v15 += 8i64;
        if ( !--v16 )
          break;
        v13 = Render::Poly::sModelHandle.mData;
      }
    }
    v22 = arg.mPrev;
    v23 = arg.mNext;
    arg.mPrev->mNext = arg.mNext;
    v23->mPrev = v22;
    arg.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
    arg.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
    arg.mIsSet = 0;
    if ( (Illusion::StateArgs *)v8->mStateArgsCreateMask.mFlags[2 * (arg.mStateParamIndex + 3i64) + 1] == (Illusion::StateArgs *)((char *)v8 + 16 * (arg.mStateParamIndex + 3i64)) )
    {
      v24 = &v8->mStateArgsCreateMask.mFlags[(unsigned int)arg.mStateParamIndex >> 6];
      *v24 &= ~(1i64 << (arg.mStateParamIndex & 0x3F));
    }
    v25 = arg.mPrev;
    v26 = arg.mNext;
    arg.mPrev->mNext = arg.mNext;
    v26->mPrev = v25;
    arg.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
    arg.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
  }
}

// File Line: 1021
// RVA: 0xDDD0
UFG::BitFlags128 *__fastcall Render::View::Draw(Render::View *this, UFG::BitFlags128 *result, Illusion::Mesh *mesh, UFG::qMatrix44 *local_world)
{
  void (__fastcall *v4)(Illusion::StateArg *, Illusion::StateValues *); // rbx
  Illusion::Mesh *v5; // r12
  UFG::BitFlags128 *v6; // rsi
  Render::View *v7; // rdi
  Illusion::StateArgs *v8; // r14
  unsigned __int16 v9; // ax
  UFG::qMatrix44 *v10; // r13
  unsigned __int16 v11; // ax
  UFG::qMatrix44 *v12; // rcx
  UFG::qMatrix44 *v13; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v14; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v15; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v16; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v17; // rax
  Render::cbLocalProjectionState v19; // [rsp+30h] [rbp-79h]
  unsigned __int16 v20; // [rsp+68h] [rbp-41h]
  __int16 v21; // [rsp+6Ah] [rbp-3Fh]
  UFG::qMatrix44 *v22; // [rsp+70h] [rbp-39h]
  void (__fastcall *v23)(Illusion::StateArg *, Illusion::StateValues *); // [rsp+78h] [rbp-31h]
  __int64 v24; // [rsp+80h] [rbp-29h]
  Render::cbLocalTransformState arg; // [rsp+88h] [rbp-21h]
  __int64 v26; // [rsp+B0h] [rbp+7h]
  __int128 v27; // [rsp+B8h] [rbp+Fh]
  char v28; // [rsp+C8h] [rbp+1Fh]
  Illusion::Material *v29; // [rsp+118h] [rbp+6Fh]
  __int64 v30; // [rsp+120h] [rbp+77h]

  v26 = -2i64;
  v4 = (void (__fastcall *)(Illusion::StateArg *, Illusion::StateValues *))local_world;
  v5 = mesh;
  v6 = result;
  v7 = this;
  if ( mesh && local_world && v29 )
  {
    v8 = &this->mSubmitContext->mStateArgs;
    v19.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v19;
    v19.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v19;
    v19.mCallback = 0i64;
    LOWORD(v19.mPrev) = Render::cbLocalProjectionState::sStateParamIndex;
    WORD1(v19.mPrev) = 1;
    if ( (_WORD)Render::cbLocalProjectionState::sStateParamIndex == -1 )
    {
      v9 = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbLocalProjection");
      Render::cbLocalProjectionState::sStateParamIndex = v9;
      LOWORD(v19.mPrev) = v9;
    }
    *(_QWORD *)&v19.mStateParamIndex = 0i64;
    v19.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v7->mWorldViewProjection;
    v19.mCallback = v4;
    Render::cbLocalTransformState::cbLocalTransformState(
      &arg,
      &v7->mSettings->mWorldView,
      &v7->mWorldViewProjection,
      (UFG::qMatrix44 *)v4);
    v10 = &v7->mSettings->mWorldView;
    v19.mWorldViewProjection = (UFG::qMatrix44 *)&v19.mWorldViewProjection;
    v19.mLocalWorld = (UFG::qMatrix44 *)&v19.mWorldViewProjection;
    v19.mCached_Remote.m_Stream = 0i64;
    v20 = Render::cbLocalTransformInverseState::sStateParamIndex;
    v21 = 1;
    if ( (_WORD)Render::cbLocalTransformInverseState::sStateParamIndex == -1 )
    {
      v11 = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbLocalTransformInverse");
      Render::cbLocalTransformInverseState::sStateParamIndex = v11;
      v20 = v11;
    }
    v24 = 0i64;
    v22 = v10;
    v23 = v4;
    Illusion::StateArgs::Set<Render::cbLocalTransformState>(v8, &arg);
    Illusion::StateArgs::Set<Render::cbLocalProjectionState>(v8, &v19);
    Illusion::StateArgs::Set<Render::cbLocalTransformInverseState>(
      v8,
      (Render::cbLocalTransformInverseState *)&v19.mWorldViewProjection);
    v27 = *(_OWORD *)v30;
    Illusion::SubmitContext::Draw(v7->mSubmitContext, (UFG::BitFlags128 *)&v28, v5, v29, (UFG::BitFlags128 *)&v27, v5);
    Illusion::StateArgs::Clear<Render::cbLocalTransformInverseState>(v8, (Render::cbLocalTransformState *)&v19);
    Illusion::StateArgs::Clear<Render::cbLocalTransformInverseState>(v8, &arg);
    Illusion::StateArgs::Clear<Render::cbLocalTransformInverseState>(
      v8,
      (Render::cbLocalTransformState *)&v19.mWorldViewProjection);
    v12 = v19.mWorldViewProjection;
    v13 = v19.mLocalWorld;
    *(_QWORD *)&v19.mWorldViewProjection->v0.z = v19.mLocalWorld;
    *(_QWORD *)&v13->v0.x = v12;
    v19.mWorldViewProjection = (UFG::qMatrix44 *)&v19.mWorldViewProjection;
    v19.mLocalWorld = (UFG::qMatrix44 *)&v19.mWorldViewProjection;
    v14 = arg.mPrev;
    v15 = arg.mNext;
    arg.mPrev->mNext = arg.mNext;
    v15->mPrev = v14;
    arg.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
    arg.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
    v16 = v19.mPrev;
    v17 = v19.mNext;
    v19.mPrev->mNext = v19.mNext;
    v17->mPrev = v16;
    v19.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v19;
    v19.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v19;
    ++v7->mViewMetrics.mNumMeshsRendered;
    v6->mFlags[0] = *(_QWORD *)v30;
    v6->mFlags[1] = *(_QWORD *)(v30 + 8);
  }
  else
  {
    result->mFlags[0] = *(_QWORD *)v30;
    result->mFlags[1] = *(_QWORD *)(v30 + 8);
  }
  return v6;
}

// File Line: 1065
// RVA: 0xE420
__int64 __fastcall Render::View::Draw(Render::View *this, Illusion::ModelHandle *model_handle, UFG::qMatrix44 *local_world, bool do_clip)
{
  UFG::qMatrix44 *v4; // r14
  Render::View *v5; // rsi
  UFG::qResourceData *v6; // rbx
  unsigned int v7; // xmm2_4
  unsigned int v8; // xmm1_4
  unsigned int v9; // xmm3_4
  unsigned int v10; // xmm1_4
  Illusion::StateArgs *v11; // rdi
  unsigned __int16 v12; // ax
  UFG::qMatrix44 *v13; // r15
  unsigned __int16 v14; // ax
  unsigned int v15; // er13
  __int64 v16; // r14
  __int64 v17; // r15
  UFG::qBaseNodeRB *v18; // rax
  signed __int64 v19; // rcx
  signed __int64 v20; // rax
  __int64 v21; // rcx
  Illusion::Mesh *v22; // r8
  Illusion::Material *v23; // r9
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v24; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v25; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v26; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v27; // rax
  void (__fastcall *v28)(Illusion::StateArg *, Illusion::StateValues *); // rcx
  void (__fastcall **v29)(Illusion::StateArg *, Illusion::StateValues *); // rax
  void (__fastcall *v30)(Illusion::StateArg *, Illusion::StateValues *); // rcx
  void (__fastcall **v31)(Illusion::StateArg *, Illusion::StateValues *); // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v32; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v33; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v34; // rdx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v35; // rcx
  __m128i v37; // [rsp+30h] [rbp-81h]
  Render::cbLocalProjectionState v38; // [rsp+40h] [rbp-71h]
  UFG::qMatrix44 *v39; // [rsp+78h] [rbp-39h]
  __int64 v40; // [rsp+80h] [rbp-31h]
  __int128 v41; // [rsp+88h] [rbp-29h]
  Render::cbLocalTransformState arg; // [rsp+98h] [rbp-19h]
  __int64 v43; // [rsp+C0h] [rbp+Fh]
  char v44; // [rsp+C8h] [rbp+17h]
  float centre_distance_to_nearplan; // [rsp+110h] [rbp+5Fh]
  Illusion::Material *retaddr; // [rsp+128h] [rbp+77h]

  v43 = -2i64;
  v4 = local_world;
  v5 = this;
  v6 = model_handle->mData;
  if ( !local_world )
    return 0i64;
  if ( !v6 )
    return 0i64;
  ++this->mViewMetrics.mNumModelsProcessed;
  if ( do_clip )
  {
    v7 = (unsigned int)v6[1].mNode.mChild[0];
    v8 = HIDWORD(v6[1].mNode.mParent);
    v37.m128i_i32[0] = (int)v6[1].mNode.mParent;
    *(__int64 *)((char *)v37.m128i_i64 + 4) = __PAIR__(v7, v8);
    v9 = v6[1].mNode.mUID;
    v10 = HIDWORD(v6[1].mNode.mChild[1]);
    LODWORD(v41) = v6[1].mNode.mChild[1];
    *(_QWORD *)((char *)&v41 + 4) = __PAIR__(v9, v10);
    TransformAABB(local_world, (UFG::qVector3 *)&v37, (UFG::qVector3 *)&v41);
    if ( (unsigned int)IntersectAABBFrustum(
                         v5->mFrustumPlanes,
                         (UFG::qVector3 *)&v37,
                         (UFG::qVector3 *)&v41,
                         &centre_distance_to_nearplan) == 2 )
      return 0i64;
  }
  ++v5->mViewMetrics.mNumModelsRendered;
  v11 = &v5->mSubmitContext->mStateArgs;
  Render::cbLocalTransformState::cbLocalTransformState(&arg, &v5->mSettings->mWorldView, &v5->mWorldViewProjection, v4);
  v38.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v38;
  v38.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v38;
  v38.mCallback = 0i64;
  v38.mStateParamIndex = Render::cbLocalProjectionState::sStateParamIndex;
  v37.m128i_i16[1] = 1;
  if ( (_WORD)Render::cbLocalProjectionState::sStateParamIndex == -1 )
  {
    v12 = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbLocalProjection");
    Render::cbLocalProjectionState::sStateParamIndex = v12;
    v38.mStateParamIndex = v12;
  }
  v38.mNext = 0i64;
  v37.m128i_i64[1] = (__int64)&v5->mWorldViewProjection;
  v38.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)v4;
  v13 = &v5->mSettings->mWorldView;
  v38.mCallback = (void (__fastcall *)(Illusion::StateArg *, Illusion::StateValues *))&v38.mCallback;
  *(_QWORD *)&v38.mStateParamIndex = (char *)&v38 + 16;
  v38.mWorldViewProjection = 0i64;
  LOWORD(v38.mLocalWorld) = Render::cbLocalTransformInverseState::sStateParamIndex;
  WORD1(v38.mLocalWorld) = 1;
  if ( (_WORD)Render::cbLocalTransformInverseState::sStateParamIndex == -1 )
  {
    v14 = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbLocalTransformInverse");
    Render::cbLocalTransformInverseState::sStateParamIndex = v14;
    LOWORD(v38.mLocalWorld) = v14;
  }
  v40 = 0i64;
  v38.mCached_Remote.m_Stream = v13;
  v39 = v4;
  Illusion::StateArgs::Set<Render::cbLocalTransformState>(v11, &arg);
  Illusion::StateArgs::Set<Render::cbLocalProjectionState>(v11, &v38);
  Illusion::StateArgs::Set<Render::cbLocalTransformInverseState>(
    v11,
    (Render::cbLocalTransformInverseState *)&v38.mCallback);
  v37 = 0ui64;
  v15 = (unsigned int)v6[2].mNode.mChild[1];
  if ( v15 )
  {
    v16 = 0i64;
    v17 = v15;
    do
    {
      v18 = v6[2].mNode.mChild[0];
      if ( v18 )
        v19 = (signed __int64)v6[2].mNode.mChild + (_QWORD)v18;
      else
        v19 = 0i64;
      v20 = v16 + v19;
      v21 = *(_QWORD *)(v16 + v19);
      if ( v21 )
        v22 = (Illusion::Mesh *)(v21 + v20);
      else
        v22 = 0i64;
      v23 = (Illusion::Material *)v22->mMaterialHandle.mData;
      if ( retaddr )
        v23 = retaddr;
      _mm_store_si128((__m128i *)&v41, v37);
      v37 = *(__m128i *)Illusion::SubmitContext::Draw(
                          v5->mSubmitContext,
                          (UFG::BitFlags128 *)&v44,
                          v22,
                          v23,
                          (UFG::BitFlags128 *)&v41,
                          v22);
      ++v5->mViewMetrics.mNumMeshsRendered;
      v16 += 8i64;
      --v17;
    }
    while ( v17 );
  }
  v24 = arg.mPrev;
  v25 = arg.mNext;
  arg.mPrev->mNext = arg.mNext;
  v25->mPrev = v24;
  arg.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
  arg.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
  arg.mIsSet = 0;
  if ( (Illusion::StateArgs *)v11->mStateArgsCreateMask.mFlags[2 * (arg.mStateParamIndex + 3i64) + 1] == (Illusion::StateArgs *)((char *)v11 + 16 * (arg.mStateParamIndex + 3i64)) )
    v11->mStateArgsCreateMask.mFlags[(unsigned int)arg.mStateParamIndex >> 6] &= ~(1i64 << (arg.mStateParamIndex & 0x3F));
  v26 = v38.mPrev;
  v27 = v38.mNext;
  v38.mPrev->mNext = v38.mNext;
  v27->mPrev = v26;
  v38.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v38;
  v38.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v38;
  v37.m128i_i8[3] = 0;
  if ( (Illusion::StateArgs *)v11->mStateArgsCreateMask.mFlags[2 * (v38.mStateParamIndex + 3i64) + 1] == (Illusion::StateArgs *)((char *)v11 + 16 * (v38.mStateParamIndex + 3i64)) )
    v11->mStateArgsCreateMask.mFlags[(unsigned int)v38.mStateParamIndex >> 6] &= ~(1i64 << (v38.mStateParamIndex & 0x3F));
  v28 = v38.mCallback;
  v29 = *(void (__fastcall ***)(Illusion::StateArg *, Illusion::StateValues *))&v38.mStateParamIndex;
  *((_QWORD *)v38.mCallback + 1) = *(_QWORD *)&v38.mStateParamIndex;
  *v29 = v28;
  v38.mCallback = (void (__fastcall *)(Illusion::StateArg *, Illusion::StateValues *))&v38.mCallback;
  *(_QWORD *)&v38.mStateParamIndex = (char *)&v38 + 16;
  BYTE3(v38.mLocalWorld) = 0;
  if ( (Illusion::StateArgs *)v11->mStateArgsCreateMask.mFlags[2 * (SLOWORD(v38.mLocalWorld) + 3i64) + 1] == (Illusion::StateArgs *)((char *)v11 + 16 * (SLOWORD(v38.mLocalWorld) + 3i64)) )
    v11->mStateArgsCreateMask.mFlags[(unsigned int)SLOWORD(v38.mLocalWorld) >> 6] &= ~(1i64 << ((_QWORD)v38.mLocalWorld & 0x3F));
  v30 = v38.mCallback;
  v31 = *(void (__fastcall ***)(Illusion::StateArg *, Illusion::StateValues *))&v38.mStateParamIndex;
  *((_QWORD *)v38.mCallback + 1) = *(_QWORD *)&v38.mStateParamIndex;
  *v31 = v30;
  v38.mCallback = (void (__fastcall *)(Illusion::StateArg *, Illusion::StateValues *))&v38.mCallback;
  *(_QWORD *)&v38.mStateParamIndex = (char *)&v38 + 16;
  v32 = v38.mPrev;
  v33 = v38.mNext;
  v38.mPrev->mNext = v38.mNext;
  v33->mPrev = v32;
  v38.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v38;
  v38.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v38;
  v34 = arg.mPrev;
  v35 = arg.mNext;
  arg.mPrev->mNext = arg.mNext;
  v35->mPrev = v34;
  arg.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
  arg.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
  return v15;
}

// File Line: 1132
// RVA: 0xE030
__int64 __fastcall Render::View::Draw(Render::View *this, Illusion::rModel *rmodel, UFG::qMatrix44 *local_world, bool do_clip)
{
  UFG::qMatrix44 *v4; // r14
  Illusion::rModel *v5; // r13
  Render::View *v6; // rdi
  float v7; // xmm2_4
  float v8; // xmm1_4
  float v9; // xmm3_4
  float v10; // xmm1_4
  Illusion::StateArgs *v11; // rsi
  __int64 v12; // rbx
  unsigned __int16 v13; // ax
  UFG::qMatrix44 *v14; // r15
  unsigned __int16 v15; // ax
  float v16; // er9
  __int64 v17; // r15
  Illusion::rMesh *v18; // r14
  Illusion::rMaterial *v19; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v20; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v21; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v22; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v23; // rax
  void (__fastcall *v24)(Illusion::StateArg *, Illusion::StateValues *); // rcx
  void (__fastcall **v25)(Illusion::StateArg *, Illusion::StateValues *); // rax
  void (__fastcall *v26)(Illusion::StateArg *, Illusion::StateValues *); // rcx
  void (__fastcall **v27)(Illusion::StateArg *, Illusion::StateValues *); // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v28; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v29; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v30; // rdx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v31; // rcx
  __m128i v33; // [rsp+30h] [rbp-81h]
  Render::cbLocalProjectionState v34; // [rsp+40h] [rbp-71h]
  UFG::qMatrix44 *v35; // [rsp+78h] [rbp-39h]
  __int64 v36; // [rsp+80h] [rbp-31h]
  __int128 v37; // [rsp+88h] [rbp-29h]
  Render::cbLocalTransformState arg; // [rsp+98h] [rbp-19h]
  __int64 v39; // [rsp+C0h] [rbp+Fh]
  char v40; // [rsp+C8h] [rbp+17h]
  float centre_distance_to_nearplan; // [rsp+108h] [rbp+57h]
  Illusion::rMaterial *retaddr; // [rsp+128h] [rbp+77h]

  v39 = -2i64;
  v4 = local_world;
  v5 = rmodel;
  v6 = this;
  if ( !rmodel )
    return 0i64;
  if ( !local_world )
    return 0i64;
  ++this->mViewMetrics.mNumModelsProcessed;
  if ( do_clip )
  {
    v7 = rmodel->mAABBMin.z;
    v8 = rmodel->mAABBMin.y;
    v33.m128i_i32[0] = LODWORD(rmodel->mAABBMin.x);
    *(__int64 *)((char *)v33.m128i_i64 + 4) = __PAIR__(LODWORD(v7), LODWORD(v8));
    v9 = rmodel->mAABBMax.z;
    v10 = rmodel->mAABBMax.y;
    *(float *)&v37 = rmodel->mAABBMax.x;
    *(_QWORD *)((char *)&v37 + 4) = __PAIR__(LODWORD(v9), LODWORD(v10));
    TransformAABB(local_world, (UFG::qVector3 *)&v33, (UFG::qVector3 *)&v37);
    if ( (unsigned int)IntersectAABBFrustum(
                         v6->mFrustumPlanes,
                         (UFG::qVector3 *)&v33,
                         (UFG::qVector3 *)&v37,
                         &centre_distance_to_nearplan) == 2 )
      return 0i64;
  }
  ++v6->mViewMetrics.mNumModelsRendered;
  v11 = &v6->mSubmitContext->mStateArgs;
  Render::cbLocalTransformState::cbLocalTransformState(&arg, &v6->mSettings->mWorldView, &v6->mWorldViewProjection, v4);
  v34.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v34;
  v34.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v34;
  v12 = 0i64;
  v34.mCallback = 0i64;
  v34.mStateParamIndex = Render::cbLocalProjectionState::sStateParamIndex;
  v33.m128i_i16[1] = 1;
  if ( (_WORD)Render::cbLocalProjectionState::sStateParamIndex == -1 )
  {
    v13 = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbLocalProjection");
    Render::cbLocalProjectionState::sStateParamIndex = v13;
    v34.mStateParamIndex = v13;
  }
  v34.mNext = 0i64;
  v33.m128i_i64[1] = (__int64)&v6->mWorldViewProjection;
  v34.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)v4;
  v14 = &v6->mSettings->mWorldView;
  v34.mCallback = (void (__fastcall *)(Illusion::StateArg *, Illusion::StateValues *))&v34.mCallback;
  *(_QWORD *)&v34.mStateParamIndex = (char *)&v34 + 16;
  v34.mWorldViewProjection = 0i64;
  LOWORD(v34.mLocalWorld) = Render::cbLocalTransformInverseState::sStateParamIndex;
  WORD1(v34.mLocalWorld) = 1;
  if ( (_WORD)Render::cbLocalTransformInverseState::sStateParamIndex == -1 )
  {
    v15 = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbLocalTransformInverse");
    Render::cbLocalTransformInverseState::sStateParamIndex = v15;
    LOWORD(v34.mLocalWorld) = v15;
  }
  v36 = 0i64;
  v34.mCached_Remote.m_Stream = v14;
  v35 = v4;
  Illusion::StateArgs::Set<Render::cbLocalTransformState>(v11, &arg);
  Illusion::StateArgs::Set<Render::cbLocalProjectionState>(v11, &v34);
  Illusion::StateArgs::Set<Render::cbLocalTransformInverseState>(
    v11,
    (Render::cbLocalTransformInverseState *)&v34.mCallback);
  v33 = 0ui64;
  v16 = *(float *)&v5->mMeshes.mData.mNumItems;
  centre_distance_to_nearplan = v16;
  if ( v16 != 0.0 )
  {
    v17 = LODWORD(v16);
    do
    {
      v18 = &v5->mMeshes.mData.mItems[v12];
      v19 = (Illusion::rMaterial *)v18->mMaterial.mData;
      if ( !v19 )
        v19 = Illusion::rMaterial::GetDefault();
      if ( retaddr )
        v19 = retaddr;
      if ( v19 )
      {
        _mm_store_si128((__m128i *)&v37, v33);
        v33 = *(__m128i *)Illusion::SubmitContext::Draw(
                            v6->mSubmitContext,
                            (UFG::BitFlags128 *)&v40,
                            v18,
                            v19,
                            (UFG::BitFlags128 *)&v37,
                            v18);
        ++v6->mViewMetrics.mNumMeshsRendered;
      }
      ++v12;
      --v17;
    }
    while ( v17 );
    v16 = centre_distance_to_nearplan;
  }
  v20 = arg.mPrev;
  v21 = arg.mNext;
  arg.mPrev->mNext = arg.mNext;
  v21->mPrev = v20;
  arg.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
  arg.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
  arg.mIsSet = 0;
  if ( (Illusion::StateArgs *)v11->mStateArgsCreateMask.mFlags[2 * (arg.mStateParamIndex + 3i64) + 1] == (Illusion::StateArgs *)((char *)v11 + 16 * (arg.mStateParamIndex + 3i64)) )
    v11->mStateArgsCreateMask.mFlags[(unsigned int)arg.mStateParamIndex >> 6] &= ~(1i64 << (arg.mStateParamIndex & 0x3F));
  v22 = v34.mPrev;
  v23 = v34.mNext;
  v34.mPrev->mNext = v34.mNext;
  v23->mPrev = v22;
  v34.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v34;
  v34.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v34;
  v33.m128i_i8[3] = 0;
  if ( (Illusion::StateArgs *)v11->mStateArgsCreateMask.mFlags[2 * (v34.mStateParamIndex + 3i64) + 1] == (Illusion::StateArgs *)((char *)v11 + 16 * (v34.mStateParamIndex + 3i64)) )
    v11->mStateArgsCreateMask.mFlags[(unsigned int)v34.mStateParamIndex >> 6] &= ~(1i64 << (v34.mStateParamIndex & 0x3F));
  v24 = v34.mCallback;
  v25 = *(void (__fastcall ***)(Illusion::StateArg *, Illusion::StateValues *))&v34.mStateParamIndex;
  *((_QWORD *)v34.mCallback + 1) = *(_QWORD *)&v34.mStateParamIndex;
  *v25 = v24;
  v34.mCallback = (void (__fastcall *)(Illusion::StateArg *, Illusion::StateValues *))&v34.mCallback;
  *(_QWORD *)&v34.mStateParamIndex = (char *)&v34 + 16;
  BYTE3(v34.mLocalWorld) = 0;
  if ( (Illusion::StateArgs *)v11->mStateArgsCreateMask.mFlags[2 * (SLOWORD(v34.mLocalWorld) + 3i64) + 1] == (Illusion::StateArgs *)((char *)v11 + 16 * (SLOWORD(v34.mLocalWorld) + 3i64)) )
    v11->mStateArgsCreateMask.mFlags[(unsigned int)SLOWORD(v34.mLocalWorld) >> 6] &= ~(1i64 << ((_QWORD)v34.mLocalWorld & 0x3F));
  v26 = v34.mCallback;
  v27 = *(void (__fastcall ***)(Illusion::StateArg *, Illusion::StateValues *))&v34.mStateParamIndex;
  *((_QWORD *)v34.mCallback + 1) = *(_QWORD *)&v34.mStateParamIndex;
  *v27 = v26;
  v34.mCallback = (void (__fastcall *)(Illusion::StateArg *, Illusion::StateValues *))&v34.mCallback;
  *(_QWORD *)&v34.mStateParamIndex = (char *)&v34 + 16;
  v28 = v34.mPrev;
  v29 = v34.mNext;
  v34.mPrev->mNext = v34.mNext;
  v29->mPrev = v28;
  v34.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v34;
  v34.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v34;
  v30 = arg.mPrev;
  v31 = arg.mNext;
  arg.mPrev->mNext = arg.mNext;
  v31->mPrev = v30;
  arg.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
  arg.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
  return LODWORD(v16);
}

// File Line: 1205
// RVA: 0x14A40
void __fastcall Render::View::DrawInstanced(Render::View *this, Illusion::Mesh *mesh, Illusion::Buffer *instance_buf, unsigned int instance_count)
{
  unsigned int v4; // er15
  Illusion::Buffer *v5; // r12
  Illusion::Mesh *v6; // r14
  Render::View *v7; // rdi
  Illusion::StateArgs *v8; // rbx
  UFG::qMatrix44 *v9; // r13
  unsigned __int16 v10; // ax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v11; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v12; // rax
  unsigned __int64 *v13; // rdx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v14; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v15; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v16; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v17; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v18; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v19; // rax
  Render::cbLocalTransformState arg; // [rsp+20h] [rbp-49h]
  Render::cbLocalTransformInverseState v21; // [rsp+48h] [rbp-21h]
  UFG::qMatrix44 *retaddr; // [rsp+D8h] [rbp+6Fh]
  Illusion::Material *v23; // [rsp+E0h] [rbp+77h]
  char *v24; // [rsp+E8h] [rbp+7Fh]

  v4 = instance_count;
  v5 = instance_buf;
  v6 = mesh;
  v7 = this;
  v8 = &this->mSubmitContext->mStateArgs;
  Render::cbLocalTransformState::cbLocalTransformState(
    (Render::cbLocalTransformState *)&v21,
    &this->mSettings->mWorldView,
    &this->mWorldViewProjection,
    retaddr);
  v9 = &v7->mSettings->mWorldView;
  v21.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v21;
  v21.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v21;
  v21.mCallback = 0i64;
  v21.mStateParamIndex = Render::cbLocalTransformInverseState::sStateParamIndex;
  *(_WORD *)&v21.mFlags = 1;
  if ( (_WORD)Render::cbLocalTransformInverseState::sStateParamIndex == -1 )
  {
    v10 = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbLocalTransformInverse");
    Render::cbLocalTransformInverseState::sStateParamIndex = v10;
    v21.mStateParamIndex = v10;
  }
  v21.mCached_Remote.m_Stream = 0i64;
  v21.mWorldView = v9;
  v21.mLocalWorld = retaddr;
  Illusion::StateArgs::Set<Render::cbLocalTransformState>(v8, &arg);
  Illusion::StateArgs::Set<Render::cbLocalTransformInverseState>(v8, &v21);
  Illusion::SubmitContext::DrawInstanced(v7->mSubmitContext, v6, v5, v4, v23, 0i64, v6, v24);
  v11 = arg.mPrev;
  v12 = arg.mNext;
  arg.mPrev->mNext = arg.mNext;
  v12->mPrev = v11;
  arg.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
  arg.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
  arg.mIsSet = 0;
  if ( (Illusion::StateArgs *)v8->mStateArgsCreateMask.mFlags[2 * (arg.mStateParamIndex + 3i64) + 1] == (Illusion::StateArgs *)((char *)v8 + 16 * (arg.mStateParamIndex + 3i64)) )
  {
    v13 = &v8->mStateArgsCreateMask.mFlags[(unsigned int)arg.mStateParamIndex >> 6];
    *v13 &= ~(1i64 << (arg.mStateParamIndex & 0x3F));
  }
  v14 = v21.mPrev;
  v15 = v21.mNext;
  v21.mPrev->mNext = v21.mNext;
  v15->mPrev = v14;
  v21.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v21;
  v21.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v21;
  v21.mIsSet = 0;
  if ( (Illusion::StateArgs *)v8->mStateArgsCreateMask.mFlags[2 * (v21.mStateParamIndex + 3i64) + 1] == (Illusion::StateArgs *)((char *)v8 + 16 * (v21.mStateParamIndex + 3i64)) )
    v8->mStateArgsCreateMask.mFlags[(unsigned int)v21.mStateParamIndex >> 6] &= ~(1i64 << (v21.mStateParamIndex & 0x3F));
  v16 = v21.mPrev;
  v17 = v21.mNext;
  v21.mPrev->mNext = v21.mNext;
  v17->mPrev = v16;
  v18 = arg.mPrev;
  v19 = arg.mNext;
  arg.mPrev->mNext = arg.mNext;
  v19->mPrev = v18;
}

// File Line: 1231
// RVA: 0xD590
Illusion::Material *__fastcall Render::View::CreateSimpleMaterial(const unsigned int texture_name_uid, const unsigned int raster_state_uid, const unsigned int alpha_state_uid, bool depth_bias)
{
  Illusion::Material *v4; // rbx
  _WORD *v5; // rdi
  unsigned int v6; // esi
  bool v7; // r14
  unsigned int v8; // ebp
  __int64 v9; // rax
  _WORD *v10; // rax
  int v11; // eax
  __int64 v12; // rax
  unsigned int v13; // er8
  __int64 v14; // rax
  _WORD *v15; // rax
  __int64 v16; // rax
  __int64 v17; // rax
  _WORD *v18; // rax
  __int64 v19; // rax

  v4 = `anonymous namespace::gSimpleMaterial;
  v5 = 0i64;
  v6 = alpha_state_uid;
  v7 = depth_bias;
  v8 = raster_state_uid;
  if ( LODWORD(`anonymous namespace::gSimpleMaterial[1].mStateBlockMask.mFlags[0]) != texture_name_uid )
  {
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)&`anonymous namespace::gSimpleMaterial[1].mDebugName[20],
      `anonymous namespace::gSimpleMaterial[1].mStateBlockMask.mFlags[1],
      texture_name_uid);
    v9 = v4->mMaterialUser.mOffset;
    if ( v9 )
      v10 = (_WORD *)((char *)&v4->mMaterialUser + v9);
    else
      v10 = 0i64;
    *v10 |= 0x20u;
  }
  v11 = (int)v4[1].mResourceHandles.mNode.mNext;
  if ( v11 == 826356572 )
  {
    if ( v6 == 721849354 )
    {
      UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v4[1].mNode.mChild[1], v4[1].mTypeUID, 0x20D03CDDu);
      v12 = v4->mMaterialUser.mOffset;
      if ( v12 )
        *(_WORD *)((char *)&v4->mMaterialUser.mOffset + v12) |= 0x20u;
      else
        LOWORD(MEMORY[0]) = MEMORY[0] | 0x20;
      goto LABEL_24;
    }
  }
  else if ( v11 == 26403030 )
  {
    v13 = 685899938;
    if ( v7 )
      v13 = -1096278483;
    if ( LODWORD(v4[3].mNode.mChild[0]) != v13 )
    {
      UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v4[2].mNumParams, (unsigned int)v4[3].mNode.mChild[1], v13);
      v14 = v4->mMaterialUser.mOffset;
      if ( v14 )
        v15 = (_WORD *)((char *)&v4->mMaterialUser + v14);
      else
        v15 = 0i64;
      *v15 |= 0x20u;
    }
  }
  if ( !v6 )
  {
    v16 = *((_QWORD *)&v4[1].0 + 11);
    v6 = 0;
    if ( v16 )
      v6 = *(_DWORD *)(v16 + 108);
    if ( v6 == -1551679522 )
      v8 = -262489691;
  }
LABEL_24:
  if ( *(_DWORD *)&v4[2].mDebugName[28] != v8 )
  {
    UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v4[2].mDebugName[4], *((_DWORD *)&v4[2].0 + 22), v8);
    v17 = v4->mMaterialUser.mOffset;
    if ( v17 )
      v18 = (_WORD *)((char *)&v4->mMaterialUser + v17);
    else
      v18 = 0i64;
    *v18 |= 0x20u;
  }
  if ( v4[2].mNode.mUID != v6 )
  {
    UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v4[2], (unsigned int)v4[2].mResourceHandles.mNode.mPrev, v6);
    v19 = v4->mMaterialUser.mOffset;
    if ( v19 )
      v5 = (_WORD *)((char *)&v4->mMaterialUser + v19);
    *v5 |= 0x20u;
  }
  return v4;
}

// File Line: 1340
// RVA: 0x16040
UFG::qMatrix44 *__fastcall Render::View::ScaleToFit(Render::View *this, UFG::qMatrix44 *xform, float scale, float scale_adjust)
{
  float v4; // xmm6_4
  float v5; // xmm1_4
  __m128 v6; // xmm2
  float v7; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm0_4
  UFG::qVector4 v10; // xmm5
  UFG::qVector4 v11; // xmm4
  UFG::qVector4 v12; // xmm1
  UFG::qVector4 v13; // xmm2

  v4 = scale;
  if ( !(_S6 & 1) )
    _S6 |= 1u;
  if ( scale < 0.0 )
  {
    v5 = xform->v3.x - this->mViewWorld.v3.x;
    v6 = (__m128)LODWORD(xform->v3.y);
    v7 = xform->v3.z - this->mViewWorld.v3.z;
    v6.m128_f32[0] = (float)((float)((float)(v6.m128_f32[0] - this->mViewWorld.v3.y)
                                   * (float)(v6.m128_f32[0] - this->mViewWorld.v3.y))
                           + (float)(v5 * v5))
                   + (float)(v7 * v7);
    v8 = COERCE_FLOAT(_mm_sqrt_ps(v6)) * 0.034899496;
    v9 = FLOAT_0_000099999997;
    if ( v8 >= 0.000099999997 )
      v9 = v8;
    LODWORD(v4) = COERCE_UNSIGNED_INT((float)(v4 * scale_adjust) * v9) ^ _xmm[0];
  }
  v10 = xform->v1;
  v11 = xform->v2;
  v12 = xform->v3;
  v13 = xform->v0;
  sScaledXform.v0 = v13;
  sScaledXform.v1 = v10;
  sScaledXform.v2 = v11;
  sScaledXform.v3 = v12;
  sScaledXform.v0.x = v13.x * v4;
  sScaledXform.v0.y = sScaledXform.v0.y * v4;
  sScaledXform.v0.z = v13.z * v4;
  sScaledXform.v0.w = v13.w * v4;
  sScaledXform.v1.x = v10.x * v4;
  sScaledXform.v1.y = sScaledXform.v1.y * v4;
  sScaledXform.v1.z = v10.z * v4;
  sScaledXform.v1.w = v10.w * v4;
  sScaledXform.v2.x = v11.x * v4;
  sScaledXform.v2.y = sScaledXform.v2.y * v4;
  sScaledXform.v2.z = v11.z * v4;
  sScaledXform.v2.w = v11.w * v4;
  return &sScaledXform;
}

// File Line: 1366
// RVA: 0x16600
void __fastcall Render::View::SetSimpleMaterialShader(unsigned int shader_uid)
{
  Illusion::Material *v1; // rbx
  __int64 v2; // rax

  v1 = `anonymous namespace::gSimpleMaterial;
  if ( LODWORD(`anonymous namespace::gSimpleMaterial[1].mResourceHandles.mNode.mNext) != shader_uid )
  {
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)&`anonymous namespace::gSimpleMaterial[1].mNode.mChild[1],
      `anonymous namespace::gSimpleMaterial[1].mTypeUID,
      shader_uid);
    v2 = v1->mMaterialUser.mOffset;
    if ( v2 )
      *(_WORD *)((char *)&v1->mMaterialUser.mOffset + v2) |= 0x20u;
    else
      LOWORD(MEMORY[0]) = MEMORY[0] | 0x20;
  }
}

// File Line: 1374
// RVA: 0x13D80
void __fastcall Render::View::DrawGradient(Render::View *this, int x, int y, int width, int height, UFG::qColour *colour_left, UFG::qColour *colour_right)
{
  Render::View *v7; // rbx
  unsigned int **v8; // r10
  __m128i v9; // xmm0
  __m128i v10; // xmm1
  float v11; // xmm2_4
  float v12; // xmm9_4
  float v13; // xmm6_4
  float v14; // xmm8_4
  float v15; // xmm7_4
  UFG::qColour *v16; // r8
  UFG::qColour *v17; // rdx
  Illusion::Material *v18; // rax
  Render::Poly poly; // [rsp+80h] [rbp+8h]

  v7 = this;
  v8 = (unsigned int **)this->mSubmitContext->mStateValues.mParamValues[11];
  v9 = _mm_cvtsi32_si128(**v8);
  v10 = _mm_cvtsi32_si128((*v8)[1]);
  poly.mVertices = 0i64;
  v11 = 1.0 / COERCE_FLOAT(_mm_cvtepi32_ps(v9));
  *(float *)v9.m128i_i32 = 1.0 / COERCE_FLOAT(_mm_cvtepi32_ps(v10));
  v12 = (float)x * v11;
  v13 = (float)(x + width) * v11;
  v14 = (float)y * *(float *)v9.m128i_i32;
  v15 = (float)(y + height) * *(float *)v9.m128i_i32;
  Render::Poly::Init(&poly, 0.0, 0.0, 1.0, 1.0, 0.0);
  v16 = colour_right;
  v17 = colour_left;
  poly.mVertices[1].mPosition.x = v12;
  poly.mVertices[1].mPosition.y = v14;
  poly.mVertices[1].mPosition.z = 0.0;
  poly.mVertices->mPosition.x = v13;
  poly.mVertices->mPosition.y = v14;
  poly.mVertices->mPosition.z = 0.0;
  poly.mVertices[2].mPosition.x = v13;
  poly.mVertices[2].mPosition.y = v15;
  poly.mVertices[2].mPosition.z = 0.0;
  poly.mVertices[3].mPosition.x = v12;
  poly.mVertices[3].mPosition.y = v15;
  poly.mVertices[3].mPosition.z = 0.0;
  Render::Poly::SetColours(&poly, v17, v16, v16, v17);
  v18 = Render::View::CreateSimpleMaterial(0xB11369EB, 0x62F81854u, 0xA3833FDE, 0);
  Render::View::Draw(v7, &poly, v18, 0i64);
}

// File Line: 1402
// RVA: 0x13F50
void __fastcall Render::View::DrawIcon(Render::View *this, unsigned int textureUID, int posX, int posY, int width, int height, UFG::qColour *colour, const unsigned int alpha_state_uid)
{
  unsigned int v8; // ebx
  Render::View *v9; // rdi
  unsigned int **v10; // r10
  __m128i v11; // xmm1
  __m128i v12; // xmm2
  float v13; // xmm7_4
  float v14; // xmm8_4
  float v15; // xmm9_4
  float v16; // xmm6_4
  float v17; // xmm7_4
  float v18; // xmm8_4
  Illusion::Material *v19; // rax
  Render::Poly poly; // [rsp+30h] [rbp-88h]

  v8 = textureUID;
  v9 = this;
  if ( textureUID - 1 <= 0xFFFFFFFD )
  {
    v10 = (unsigned int **)this->mSubmitContext->mStateValues.mParamValues[11];
    v11 = _mm_cvtsi32_si128(**v10);
    v12 = _mm_cvtsi32_si128((*v10)[1]);
    poly.mVertices = 0i64;
    v13 = 1.0 / COERCE_FLOAT(_mm_cvtepi32_ps(v11));
    v14 = 1.0 / COERCE_FLOAT(_mm_cvtepi32_ps(v12));
    v15 = (float)posX * v13;
    v16 = (float)posY * v14;
    v17 = (float)(v13 * (float)width) + v15;
    v18 = (float)(v14 * (float)height) + v16;
    Render::Poly::Init(&poly, 0.0, 0.0, 1.0, 1.0, 0.0);
    poly.mVertices[1].mPosition.x = v15;
    poly.mVertices[1].mPosition.y = v16;
    poly.mVertices[1].mPosition.z = 0.0;
    poly.mVertices->mPosition.x = v17;
    poly.mVertices->mPosition.y = v16;
    poly.mVertices->mPosition.z = 0.0;
    poly.mVertices[2].mPosition.x = v17;
    poly.mVertices[2].mPosition.y = v18;
    poly.mVertices[2].mPosition.z = 0.0;
    poly.mVertices[3].mPosition.x = v15;
    poly.mVertices[3].mPosition.y = v18;
    poly.mVertices[3].mPosition.z = 0.0;
    Render::Poly::SetUVs(
      &poly,
      (float)(1.0 / (float)width) * 0.5,
      (float)(1.0 / (float)height) * 0.5,
      (float)(1.0 - (float)((float)(1.0 / (float)width) * 0.5)) - (float)((float)(1.0 / (float)width) * 0.5),
      (float)(1.0 - (float)((float)(1.0 / (float)height) * 0.5)) - (float)((float)(1.0 / (float)height) * 0.5));
    Render::Poly::SetColour(&poly, colour);
    v19 = Render::View::CreateSimpleMaterial(v8, 0x62F81854u, alpha_state_uid, 0);
    Render::View::Draw(v9, &poly, v19, 0i64);
  }
}

// File Line: 1452
// RVA: 0x14C50
void __fastcall Render::View::DrawSegment(Render::View *this, UFG::qVector3 *start, UFG::qVector3 *end, UFG::DrawInfo *info)
{
  UFG::qVector3 *v4; // r15
  Render::View *v5; // rsi
  UFG::qVector3 *v6; // r14
  UFG::DrawInfo *v7; // rbx
  char *v8; // rdi
  float v9; // xmm1_4
  unsigned int v10; // edx
  int v11; // er8
  float v12; // eax
  float v13; // xmm1_4
  int v14; // ecx
  float v15; // eax
  bool v16; // al
  void (__fastcall *pre_draw_callback)(Illusion::Material *, Render::View *, Illusion::StateValues *, Illusion::Primitive *, Illusion::StateArgs *); // ST30_8

  v4 = start;
  v5 = this;
  v6 = end;
  v7 = info;
  v8 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x60u, 0x10u);
  if ( v8 )
  {
    v9 = v4->z;
    v10 = 1660426324;
    v11 = (signed int)(float)(v7->mColour1.r * 255.0) | (((signed int)(float)(v7->mColour1.g * 255.0) | (((signed int)(float)(v7->mColour1.b * 255.0) | ((signed int)(float)(v7->mColour1.a * 255.0) << 8)) << 8)) << 8);
    v12 = v4->x;
    *((_DWORD *)v8 + 1) = LODWORD(v4->y);
    *(float *)v8 = v12;
    *((_DWORD *)v8 + 11) = v11;
    *((float *)v8 + 2) = v9;
    v13 = v6->z;
    v14 = (signed int)(float)(v7->mColour2.r * 255.0) | (((signed int)(float)(v7->mColour2.g * 255.0) | (((signed int)(float)(v7->mColour2.b * 255.0) | ((signed int)(float)(v7->mColour2.a * 255.0) << 8)) << 8)) << 8);
    v15 = v6->x;
    *((_DWORD *)v8 + 13) = LODWORD(v6->y);
    *((float *)v8 + 12) = v15;
    *((_DWORD *)v8 + 23) = v14;
    *((float *)v8 + 14) = v13;
    v16 = v7->mFaceCull;
    if ( v16 )
    {
      if ( v7->mDepthBuffer )
      {
        v10 = 543723269;
LABEL_9:
        Render::View::CreateSimpleMaterial(0xB11369EB, v10, v7->mAlphaBlend, v7->mDepthBias);
        pre_draw_callback = v7->mPreDrawCallback;
        Render::View::DrawDebugPrim(v5, DebugPrim_LineSegment, (Render::vDynamic *)v8, 2);
        return;
      }
      if ( v16 )
      {
        v10 = 206781021;
        goto LABEL_9;
      }
    }
    if ( v7->mDepthBuffer )
      v10 = 1099738947;
    goto LABEL_9;
  }
}

// File Line: 1469
// RVA: 0xF370
void __fastcall Render::View::DrawArrow(Render::View *this, UFG::qVector3 *p0, UFG::qVector3 *p1, UFG::DrawInfo *info, UFG::qMatrix44 *xform)
{
  Render::View *v5; // r14
  UFG::qVector3 *v6; // rsi
  UFG::qVector3 *v7; // rbp
  UFG::DrawInfo *v8; // rbx
  char *v9; // rax
  char *v10; // rdi
  __m128 v11; // xmm0
  __m128 v12; // xmm5
  float v13; // xmm13_4
  float v14; // xmm14_4
  float v15; // xmm15_4
  __m128 v16; // xmm1
  float v17; // xmm6_4
  float v18; // xmm8_4
  float v19; // xmm5_4
  float v20; // xmm10_4
  float v21; // xmm9_4
  float v22; // xmm11_4
  float v23; // xmm1_4
  float v24; // xmm8_4
  float v25; // xmm1_4
  float v26; // xmm5_4
  float v27; // xmm8_4
  float v28; // xmm0_4
  int v29; // ecx
  int v30; // ecx
  signed int v31; // eax
  float v32; // xmm0_4
  int v33; // ecx
  signed int v34; // eax
  float v35; // xmm0_4
  unsigned int v36; // edx
  float v37; // xmm0_4
  int v38; // ecx
  int v39; // ecx
  signed int v40; // eax
  float v41; // xmm0_4
  int v42; // ecx
  signed int v43; // eax
  float v44; // xmm0_4
  bool v45; // al
  void (__fastcall *pre_draw_callback)(Illusion::Material *, Render::View *, Illusion::StateValues *, Illusion::Primitive *, Illusion::StateArgs *); // ST30_8
  float v47; // [rsp+40h] [rbp-B8h]
  float v48; // [rsp+44h] [rbp-B4h]

  v5 = this;
  v6 = p1;
  v7 = p0;
  v8 = info;
  v9 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x120u, 0x10u);
  v10 = v9;
  if ( v9 )
  {
    v11 = (__m128)LODWORD(v6->y);
    v47 = v6->y;
    v12 = v11;
    v48 = v6->z;
    v13 = v7->y;
    v14 = v7->z;
    v12.m128_f32[0] = v11.m128_f32[0] - v13;
    v15 = v6->x;
    v16 = v12;
    v17 = v6->x - v7->x;
    v16.m128_f32[0] = (float)((float)(v12.m128_f32[0] * v12.m128_f32[0]) + (float)(v17 * v17))
                    + (float)((float)(v48 - v14) * (float)(v48 - v14));
    LODWORD(v18) = (unsigned __int128)_mm_sqrt_ps(v16);
    LODWORD(v19) = COERCE_UNSIGNED_INT(v11.m128_f32[0] - v13) ^ _xmm[0];
    v20 = v13 + (float)((float)((float)(v11.m128_f32[0] - v13) * 15.0) * 0.0625);
    v21 = v7->x + (float)((float)(v17 * 15.0) * 0.0625);
    v22 = v14 + (float)((float)((float)(v48 - v14) * 15.0) * 0.0625);
    v23 = (float)(v19 * v19) + (float)(v17 * v17);
    if ( v23 <= 0.0001 )
    {
      v26 = 0.0;
      v25 = v18 * 0.03125;
      v27 = 0.0;
    }
    else
    {
      v24 = (float)(v18 * 0.03125) / fsqrt(v23);
      v25 = v24 * v19;
      v26 = v24 * v17;
      v27 = v24 * 0.0;
    }
    v28 = v8->mColour1.r * 255.0;
    v29 = (signed int)(float)(v8->mColour1.g * 255.0) | (((signed int)(float)(v8->mColour1.b * 255.0) | ((signed int)(float)(v8->mColour1.a * 255.0) << 8)) << 8);
    *(float *)v9 = v7->x;
    *((float *)v9 + 1) = v13;
    *((float *)v9 + 2) = v14;
    *((_DWORD *)v9 + 11) = (signed int)v28 | (v29 << 8);
    v30 = ((signed int)(float)(v8->mColour1.b * 255.0) | ((signed int)(float)(v8->mColour1.a * 255.0) << 8)) << 8;
    v31 = (signed int)(float)(v8->mColour1.g * 255.0);
    v32 = v8->mColour1.r;
    *((float *)v10 + 12) = v21;
    *((float *)v10 + 13) = v20;
    *((float *)v10 + 14) = v22;
    *((_DWORD *)v10 + 23) = (signed int)(float)(v32 * 255.0) | ((v31 | v30) << 8);
    v33 = ((signed int)(float)(v8->mColour1.b * 255.0) | ((signed int)(float)(v8->mColour1.a * 255.0) << 8)) << 8;
    v34 = (signed int)(float)(v8->mColour1.g * 255.0);
    v35 = v8->mColour1.r;
    *((float *)v10 + 24) = v21 + v25;
    *((float *)v10 + 25) = v20 + v26;
    *((float *)v10 + 26) = v22 + v27;
    *((_DWORD *)v10 + 35) = (signed int)(float)(v35 * 255.0) | ((v34 | v33) << 8);
    v36 = 1660426324;
    v37 = v8->mColour1.r * 255.0;
    v38 = (signed int)(float)(v8->mColour1.g * 255.0) | (((signed int)(float)(v8->mColour1.b * 255.0) | ((signed int)(float)(v8->mColour1.a * 255.0) << 8)) << 8);
    *((float *)v10 + 36) = v15;
    *((float *)v10 + 37) = v47;
    *((float *)v10 + 38) = v48;
    *((_DWORD *)v10 + 47) = (signed int)v37 | (v38 << 8);
    v39 = ((signed int)(float)(v8->mColour1.b * 255.0) | ((signed int)(float)(v8->mColour1.a * 255.0) << 8)) << 8;
    v40 = (signed int)(float)(v8->mColour1.g * 255.0);
    v41 = v8->mColour1.r;
    *((float *)v10 + 48) = v21 - v25;
    *((float *)v10 + 49) = v20 - v26;
    *((float *)v10 + 50) = v22 - v27;
    *((_DWORD *)v10 + 59) = (signed int)(float)(v41 * 255.0) | ((v40 | v39) << 8);
    v42 = ((signed int)(float)(v8->mColour1.b * 255.0) | ((signed int)(float)(v8->mColour1.a * 255.0) << 8)) << 8;
    v43 = (signed int)(float)(v8->mColour1.g * 255.0);
    v44 = v8->mColour1.r;
    *((float *)v10 + 60) = v21;
    *((float *)v10 + 61) = v20;
    *((float *)v10 + 62) = v22;
    *((_DWORD *)v10 + 71) = (signed int)(float)(v44 * 255.0) | ((v43 | v42) << 8);
    v45 = v8->mFaceCull;
    if ( v45 )
    {
      if ( v8->mDepthBuffer )
      {
        v36 = 543723269;
LABEL_12:
        Render::View::CreateSimpleMaterial(0xB11369EB, v36, v8->mAlphaBlend, v8->mDepthBias);
        pre_draw_callback = v8->mPreDrawCallback;
        Render::View::DrawDebugPrim(v5, DebugPrim_LineStrip, (Render::vDynamic *)v10, 6);
        return;
      }
      if ( v45 )
      {
        v36 = 206781021;
        goto LABEL_12;
      }
    }
    if ( v8->mDepthBuffer )
      v36 = 1099738947;
    goto LABEL_12;
  }
}

// File Line: 1508
// RVA: 0x12C10
void __fastcall Render::View::DrawDebugPrimLineStrip(Render::View *this, UFG::qVector3 *line_points, const int num_points, UFG::DrawInfo *info, UFG::qMatrix44 *local_world)
{
  signed __int64 v5; // r14
  Render::View *v6; // r12
  UFG::qVector3 *v7; // r15
  unsigned int v8; // esi
  UFG::DrawInfo *v9; // rdi
  char *v10; // rax
  Render::vDynamic *v11; // rbp
  int v12; // ebx
  signed __int64 v13; // r9
  signed __int64 v14; // rax
  signed __int64 v15; // rcx
  unsigned __int64 v16; // rdx
  int v17; // xmm0_4
  int v18; // xmm1_4
  int v19; // xmm2_4
  int v20; // xmm1_4
  int v21; // xmm2_4
  int v22; // xmm1_4
  int v23; // xmm2_4
  int v24; // xmm1_4
  int v25; // xmm2_4
  signed __int64 v26; // rcx
  signed __int64 v27; // r8
  int *v28; // rdx
  int v29; // xmm0_4
  int v30; // xmm1_4
  int v31; // xmm2_4
  bool v32; // al
  unsigned int v33; // edx
  void (__fastcall *pre_draw_callback)(Illusion::Material *, Render::View *, Illusion::StateValues *, Illusion::Primitive *, Illusion::StateArgs *); // ST30_8

  v5 = num_points;
  v6 = this;
  v7 = line_points;
  v8 = 48 * num_points;
  v9 = info;
  v10 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 48 * num_points, 0x10u);
  v11 = (Render::vDynamic *)v10;
  if ( v10 )
  {
    v12 = (signed int)(float)(v9->mColour1.r * 255.0) | (((signed int)(float)(v9->mColour1.g * 255.0) | (((signed int)(float)(v9->mColour1.b * 255.0) | ((signed int)(float)(v9->mColour1.a * 255.0) << 8)) << 8)) << 8);
    UFG::qMemSet(v10, 0, v8);
    v13 = 0i64;
    if ( v5 >= 4 )
    {
      v14 = (signed __int64)&v11[1].mPosition.z;
      v15 = (signed __int64)&v7[1].z;
      v16 = ((unsigned __int64)(v5 - 4) >> 2) + 1;
      v13 = 4 * v16;
      do
      {
        v17 = *(_DWORD *)(v15 - 20);
        v18 = *(_DWORD *)(v15 - 16);
        v19 = *(_DWORD *)(v15 - 12);
        v14 += 192i64;
        v15 += 48i64;
        *(_DWORD *)(v14 - 248) = v17;
        *(_DWORD *)(v14 - 244) = v18;
        *(_DWORD *)(v14 - 240) = v19;
        *(_DWORD *)(v14 - 204) = v12;
        v20 = *(_DWORD *)(v15 - 52);
        v21 = *(_DWORD *)(v15 - 48);
        *(_DWORD *)(v14 - 200) = *(_DWORD *)(v15 - 56);
        *(_DWORD *)(v14 - 196) = v20;
        *(_DWORD *)(v14 - 192) = v21;
        *(_DWORD *)(v14 - 156) = v12;
        v22 = *(_DWORD *)(v15 - 40);
        v23 = *(_DWORD *)(v15 - 36);
        *(_DWORD *)(v14 - 152) = *(_DWORD *)(v15 - 44);
        *(_DWORD *)(v14 - 148) = v22;
        *(_DWORD *)(v14 - 144) = v23;
        *(_DWORD *)(v14 - 108) = v12;
        v24 = *(_DWORD *)(v15 - 28);
        v25 = *(_DWORD *)(v15 - 24);
        *(_DWORD *)(v14 - 104) = *(_DWORD *)(v15 - 32);
        *(_DWORD *)(v14 - 100) = v24;
        *(_DWORD *)(v14 - 96) = v25;
        *(_DWORD *)(v14 - 60) = v12;
        --v16;
      }
      while ( v16 );
    }
    if ( v13 < v5 )
    {
      v26 = (signed __int64)&v11[v13].mPosition.z;
      v27 = v5 - v13;
      v28 = (int *)&v7[v13].z;
      do
      {
        v29 = *(v28 - 2);
        v30 = *(v28 - 1);
        v31 = *v28;
        v26 += 48i64;
        v28 += 3;
        *(_DWORD *)(v26 - 56) = v29;
        *(_DWORD *)(v26 - 52) = v30;
        *(_DWORD *)(v26 - 48) = v31;
        *(_DWORD *)(v26 - 12) = v12;
        --v27;
      }
      while ( v27 );
    }
    v32 = v9->mFaceCull;
    v33 = 1660426324;
    if ( v32 )
    {
      if ( v9->mDepthBuffer )
      {
        v33 = 543723269;
LABEL_15:
        Render::View::CreateSimpleMaterial(0xB11369EB, v33, v9->mAlphaBlend, v9->mDepthBias);
        pre_draw_callback = v9->mPreDrawCallback;
        Render::View::DrawDebugPrim(v6, DebugPrim_LineStrip, v11, v5);
        return;
      }
      if ( v32 )
      {
        v33 = 206781021;
        goto LABEL_15;
      }
    }
    if ( v9->mDepthBuffer )
      v33 = 1099738947;
    goto LABEL_15;
  }
}

// File Line: 1541
// RVA: 0x10790
void __fastcall Render::View::DrawDebugConnectedPrimLineStrip(Render::View *this, UFG::qVector3 *line_points, const int num_points, UFG::qColour *colour, UFG::qMatrix44 *local_world, bool depth_test, bool alpha_test)
{
  signed __int64 v7; // rbp
  Render::View *v8; // r15
  UFG::qVector3 *v9; // r14
  UFG::qColour *v10; // rsi
  unsigned int v11; // ebx
  char *v12; // rax
  Render::vDynamic *v13; // rdi
  signed __int64 v14; // r10
  int v15; // er8
  signed __int64 v16; // rcx
  signed __int64 v17; // rdx
  unsigned __int64 v18; // r9
  int v19; // xmm0_4
  int v20; // xmm1_4
  int v21; // xmm0_4
  int v22; // xmm1_4
  int v23; // xmm0_4
  int v24; // xmm1_4
  int v25; // xmm0_4
  int v26; // xmm1_4
  signed __int64 v27; // rcx
  int *v28; // rdx
  signed __int64 v29; // r9
  int v30; // xmm0_4
  int v31; // xmm1_4
  float v32; // xmm0_4
  float v33; // xmm1_4
  unsigned int v34; // edx
  signed __int64 v35; // rcx
  unsigned int v36; // er8

  v7 = num_points;
  v8 = this;
  v9 = line_points;
  v10 = colour;
  v11 = 48 * (num_points + 1);
  v12 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 48 * (num_points + 1), 0x10u);
  v13 = (Render::vDynamic *)v12;
  if ( v12 )
  {
    UFG::qMemSet(v12, 0, v11);
    v14 = 0i64;
    v15 = (signed int)(float)(v10->r * 255.0) | (((signed int)(float)(v10->g * 255.0) | (((signed int)(float)(v10->b * 255.0) | ((signed int)(float)(v10->a * 255.0) << 8)) << 8)) << 8);
    if ( v7 >= 4 )
    {
      v16 = (signed __int64)&v13[1].mPosition.z;
      v17 = (signed __int64)&v9[1].z;
      v18 = ((unsigned __int64)(v7 - 4) >> 2) + 1;
      v14 = 4 * v18;
      do
      {
        v19 = *(_DWORD *)(v17 - 16);
        v20 = *(_DWORD *)(v17 - 12);
        *(_DWORD *)(v16 - 56) = *(_DWORD *)(v17 - 20);
        v16 += 192i64;
        v17 += 48i64;
        *(_DWORD *)(v16 - 244) = v19;
        *(_DWORD *)(v16 - 240) = v20;
        *(_DWORD *)(v16 - 204) = v15;
        v21 = *(_DWORD *)(v17 - 52);
        v22 = *(_DWORD *)(v17 - 48);
        *(_DWORD *)(v16 - 200) = *(_DWORD *)(v17 - 56);
        *(_DWORD *)(v16 - 196) = v21;
        *(_DWORD *)(v16 - 192) = v22;
        *(_DWORD *)(v16 - 156) = v15;
        v23 = *(_DWORD *)(v17 - 40);
        v24 = *(_DWORD *)(v17 - 36);
        *(_DWORD *)(v16 - 152) = *(_DWORD *)(v17 - 44);
        *(_DWORD *)(v16 - 148) = v23;
        *(_DWORD *)(v16 - 144) = v24;
        *(_DWORD *)(v16 - 108) = v15;
        v25 = *(_DWORD *)(v17 - 28);
        v26 = *(_DWORD *)(v17 - 24);
        *(_DWORD *)(v16 - 104) = *(_DWORD *)(v17 - 32);
        *(_DWORD *)(v16 - 100) = v25;
        *(_DWORD *)(v16 - 96) = v26;
        *(_DWORD *)(v16 - 60) = v15;
        --v18;
      }
      while ( v18 );
    }
    if ( v14 < v7 )
    {
      v27 = (signed __int64)&v13[v14].mPosition.z;
      v28 = (int *)(&v9->x + v14 + 2 * (v14 + 1));
      v29 = v7 - v14;
      do
      {
        v30 = *(v28 - 1);
        v31 = *v28;
        *(_DWORD *)(v27 - 8) = *(v28 - 2);
        v27 += 48i64;
        v28 += 3;
        *(_DWORD *)(v27 - 52) = v30;
        *(_DWORD *)(v27 - 48) = v31;
        *(_DWORD *)(v27 - 12) = v15;
        --v29;
      }
      while ( v29 );
    }
    v32 = v9->y;
    v33 = v9->z;
    v34 = 1660426324;
    v35 = v7;
    v13[v35].mPosition.x = v9->x;
    v13[v35].mPosition.y = v32;
    v13[v35].mPosition.z = v33;
    v13[v35].mColour = v15;
    v36 = 662883558;
    if ( alpha_test )
      v36 = -1551679522;
    if ( depth_test )
      v34 = 543723269;
    Render::View::CreateSimpleMaterial(0xB11369EB, v34, v36, 0);
    Render::View::DrawDebugPrim(v8, DebugPrim_LineStrip, v13, v7 + 1);
  }
}

// File Line: 1594
// RVA: 0xEE40
void __fastcall Render::View::DrawArc(Render::View *this, UFG::qMatrix44 *xform, UFG::DrawInfo *info, float angleRadsStart, float angleRadsEnd, unsigned int segCount)
{
  UFG::qMatrix44 *v6; // rbp
  Render::View *v7; // rsi
  float v8; // xmm7_4
  UFG::DrawInfo *v9; // rdi
  Render::vDynamic *v10; // r13
  float v11; // xmm6_4
  int v12; // ebx
  bool v13; // al
  unsigned int v14; // edx
  int v15; // er9
  void (__fastcall *pre_draw_callback)(Illusion::Material *, Render::View *, Illusion::StateValues *, Illusion::Primitive *, Illusion::StateArgs *); // ST30_8
  Render::View *v17; // rcx
  __int64 v18; // rbp
  int v19; // eax
  int v20; // esi
  void (__fastcall *v21)(Illusion::Material *, Render::View *, Illusion::StateValues *, Illusion::Primitive *, Illusion::StateArgs *); // ST30_8
  Render::vDynamic *v22; // r8
  void (__fastcall *v23)(Illusion::Material *, Render::View *, Illusion::StateValues *, Illusion::Primitive *, Illusion::StateArgs *); // ST30_8
  void (__fastcall *v24)(Illusion::Material *, Render::View *, Illusion::StateValues *, Illusion::Primitive *, Illusion::StateArgs *); // ST30_8
  Render::View *v25; // [rsp+90h] [rbp+8h]

  v25 = this;
  v6 = xform;
  v7 = this;
  v8 = angleRadsStart;
  v9 = info;
  v10 = `anonymous namespace::GetVertsCircle(segCount, &info->mColour1) + 1;
  if ( angleRadsStart >= 0.0 )
  {
    if ( angleRadsStart > 6.2831855 )
      v8 = angleRadsStart + -6.2831855;
  }
  else
  {
    v8 = angleRadsStart + 6.2831855;
  }
  v11 = angleRadsEnd;
  if ( angleRadsEnd >= 0.0 )
  {
    if ( angleRadsEnd > 6.2831855 )
      v11 = angleRadsEnd + -6.2831855;
  }
  else
  {
    v11 = angleRadsEnd + 6.2831855;
  }
  if ( v8 != 0.0 || v11 != 6.2831855 )
    v12 = (v11 <= v8) + 1;
  else
    v12 = 0;
  v13 = v9->mFaceCull;
  v14 = 1660426324;
  if ( !v13 )
    goto LABEL_33;
  if ( v9->mDepthBuffer )
  {
    v14 = 543723269;
    goto LABEL_20;
  }
  if ( v13 )
  {
    v14 = 206781021;
  }
  else
  {
LABEL_33:
    if ( v9->mDepthBuffer )
      v14 = 1099738947;
  }
LABEL_20:
  Render::View::CreateSimpleMaterial(0xB11369EB, v14, v9->mAlphaBlend, v9->mDepthBias);
  Render::View::ScaleToFit(v7, v6, v9->mScale, Fit_scale_adjust_9);
  if ( !v12 )
  {
    v15 = segCount + 1;
    pre_draw_callback = v9->mPreDrawCallback;
    v17 = v7;
LABEL_29:
    v22 = v10;
LABEL_30:
    Render::View::DrawDebugPrim(v17, DebugPrim_LineStrip, v22, v15);
    return;
  }
  v18 = (unsigned int)`anonymous namespace::AngleToSegment(v8, segCount);
  v19 = `anonymous namespace::AngleToSegment(v11, segCount);
  v20 = v19;
  if ( v12 == 1 )
  {
    if ( (_DWORD)v18 == v19 )
      return;
    v17 = v25;
    v21 = v9->mPreDrawCallback;
    v15 = v19 - v18 + 1;
    v22 = &v10[v18];
    goto LABEL_30;
  }
  if ( segCount > (unsigned int)v18 )
  {
    v23 = v9->mPreDrawCallback;
    Render::View::DrawDebugPrim(v25, DebugPrim_LineStrip, &v10[v18], segCount - v18 + 1);
  }
  if ( v20 )
  {
    v15 = v20 + 1;
    v17 = v25;
    v24 = v9->mPreDrawCallback;
    goto LABEL_29;
  }
}

// File Line: 1673
// RVA: 0xF060
void __fastcall Render::View::DrawArcSolid(Render::View *this, UFG::qMatrix44 *xform, UFG::DrawInfo *info, float angleRadsStart, float angleRadsEnd, unsigned int segCount)
{
  Render::View *v6; // r12
  UFG::DrawInfo *v7; // rbx
  float v8; // xmm7_4
  Render::vDynamic *v9; // rax
  Render::vDynamic *v10; // rbp
  float v11; // xmm6_4
  int v12; // esi
  unsigned int v13; // edx
  int v14; // er13
  bool v15; // al
  int v16; // er9
  Render::vDynamic *v17; // r8
  void (__fastcall *pre_draw_callback)(Illusion::Material *, Render::View *, Illusion::StateValues *, Illusion::Primitive *, Illusion::StateArgs *); // ST30_8
  Render::View *v19; // rcx
  __int64 v20; // r12
  int v21; // ebp
  Render::vDynamic *v22; // rcx
  signed __int64 v23; // rdi
  int v24; // xmm7_4
  int v25; // xmm6_4
  void (__fastcall *v26)(Illusion::Material *, Render::View *, Illusion::StateValues *, Illusion::Primitive *, Illusion::StateArgs *); // ST30_8
  int v27; // xmm7_4
  int v28; // xmm6_4
  void (__fastcall *v29)(Illusion::Material *, Render::View *, Illusion::StateValues *, Illusion::Primitive *, Illusion::StateArgs *); // ST30_8
  Render::View *v30; // r15
  void (__fastcall *v31)(Illusion::Material *, Render::View *, Illusion::StateValues *, Illusion::Primitive *, Illusion::StateArgs *); // ST30_8
  Render::vDynamic *vertices; // [rsp+48h] [rbp-60h]
  Render::View *v33; // [rsp+B0h] [rbp+8h]
  UFG::qMatrix44 *xforma; // [rsp+B8h] [rbp+10h]
  unsigned int angleRadsEnda; // [rsp+D0h] [rbp+28h]

  xforma = xform;
  v33 = this;
  v6 = this;
  v7 = info;
  v8 = angleRadsStart;
  v9 = `anonymous namespace::GetVertsCircle(segCount, &info->mColour1);
  v10 = v9;
  vertices = v9;
  if ( angleRadsStart >= 0.0 )
  {
    if ( angleRadsStart > 6.2831855 )
      v8 = angleRadsStart + -6.2831855;
  }
  else
  {
    v8 = angleRadsStart + 6.2831855;
  }
  v11 = angleRadsEnd;
  if ( angleRadsEnd >= 0.0 )
  {
    if ( angleRadsEnd > 6.2831855 )
      v11 = angleRadsEnd + -6.2831855;
  }
  else
  {
    v11 = angleRadsEnd + 6.2831855;
  }
  if ( v8 != 0.0 || v11 != 6.2831855 )
    v12 = (v11 <= v8) + 1;
  else
    v12 = 0;
  angleRadsEnda = v9[1].mColour;
  v13 = 1660426324;
  v14 = (signed int)(float)(v7->mColour2.r * 255.0) | (((signed int)(float)(v7->mColour2.g * 255.0) | (((signed int)(float)(v7->mColour2.b * 255.0) | ((signed int)(float)(v7->mColour2.a * 255.0) << 8)) << 8)) << 8);
  v15 = v7->mFaceCull;
  if ( !v15 )
    goto LABEL_33;
  if ( v7->mDepthBuffer )
  {
    v13 = 543723269;
    goto LABEL_20;
  }
  if ( v15 )
  {
    v13 = 206781021;
  }
  else
  {
LABEL_33:
    if ( v7->mDepthBuffer )
      v13 = 1099738947;
  }
LABEL_20:
  Render::View::CreateSimpleMaterial(0xB11369EB, v13, v7->mAlphaBlend, v7->mDepthBias);
  Render::View::ScaleToFit(v6, xforma, v7->mScale, Fit_scale_adjust_9);
  v10->mColour = v14;
  if ( !v12 )
  {
    v16 = segCount + 2;
    v17 = v10;
    pre_draw_callback = v7->mPreDrawCallback;
    v19 = v6;
LABEL_30:
    Render::View::DrawDebugPrim(v19, DebugPrim_TriangleFan, v17, v16);
    return;
  }
  v20 = (unsigned int)`anonymous namespace::AngleToSegment(v8, segCount);
  v21 = `anonymous namespace::AngleToSegment(v11, segCount);
  if ( (_DWORD)v20 == v21 )
    return;
  v22 = vertices;
  v23 = (signed __int64)&vertices[v20];
  if ( v12 == 1 )
  {
    v24 = *(_DWORD *)(v23 + 4);
    v25 = *(_DWORD *)(v23 + 8);
    *(_QWORD *)(v23 + 4) = 0i64;
    *(_DWORD *)(v23 + 44) = v14;
    v26 = v7->mPreDrawCallback;
    Render::View::DrawDebugPrim(v33, DebugPrim_TriangleFan, (Render::vDynamic *)v23, v21 - v20 + 2);
    *(_DWORD *)(v23 + 4) = v24;
    *(_DWORD *)(v23 + 8) = v25;
    *(_DWORD *)(v23 + 44) = angleRadsEnda;
    return;
  }
  if ( segCount <= (unsigned int)v20 )
  {
    v30 = v33;
  }
  else
  {
    v27 = *(_DWORD *)(v23 + 4);
    v28 = *(_DWORD *)(v23 + 8);
    *(_QWORD *)(v23 + 4) = 0i64;
    *(_DWORD *)(v23 + 44) = v14;
    v29 = v7->mPreDrawCallback;
    v30 = v33;
    Render::View::DrawDebugPrim(v33, DebugPrim_TriangleFan, (Render::vDynamic *)v23, segCount - v20 + 2);
    *(_DWORD *)(v23 + 4) = v27;
    *(_DWORD *)(v23 + 8) = v28;
    v22 = vertices;
    *(_DWORD *)(v23 + 44) = angleRadsEnda;
  }
  if ( v21 )
  {
    v17 = v22;
    v16 = v21 + 2;
    v31 = v7->mPreDrawCallback;
    v19 = v30;
    goto LABEL_30;
  }
}

// File Line: 1828
// RVA: 0x103B0
void __fastcall Render::View::DrawCircle(Render::View *this, UFG::qMatrix44 *xform, UFG::DrawInfo *info, unsigned int segCount)
{
  UFG::qMatrix44 *v4; // r15
  Render::View *v5; // r14
  unsigned int v6; // ebp
  UFG::DrawInfo *v7; // rdi
  Render::vDynamic *v8; // rax
  unsigned int v9; // edx
  Render::vDynamic *v10; // rsi
  bool v11; // al
  void (__fastcall *pre_draw_callback)(Illusion::Material *, Render::View *, Illusion::StateValues *, Illusion::Primitive *, Illusion::StateArgs *); // ST30_8

  v4 = xform;
  v5 = this;
  v6 = segCount;
  v7 = info;
  v8 = `anonymous namespace::GetVertsCircle(segCount, &info->mColour1);
  v9 = 1660426324;
  v10 = v8;
  v11 = v7->mFaceCull;
  if ( v11 )
  {
    if ( v7->mDepthBuffer )
    {
      v9 = 543723269;
      goto LABEL_8;
    }
    if ( v11 )
    {
      v9 = 206781021;
      goto LABEL_8;
    }
  }
  if ( v7->mDepthBuffer )
    v9 = 1099738947;
LABEL_8:
  Render::View::CreateSimpleMaterial(0xB11369EB, v9, v7->mAlphaBlend, v7->mDepthBias);
  Render::View::ScaleToFit(v5, v4, v7->mScale, Fit_scale_adjust_9);
  pre_draw_callback = v7->mPreDrawCallback;
  Render::View::DrawDebugPrim(v5, DebugPrim_LineStrip, v10 + 1, v6 + 1);
}

// File Line: 2141
// RVA: 0x114D0
void __fastcall Render::View::DrawDebugPrimCircle(Render::View *this, UFG::qVector3 *centre, UFG::qVector3 *normal, const float radius, UFG::qColour *colour, UFG::qMatrix44 *local_world, void (__fastcall *pre_draw_callback)(Illusion::Material *, Render::View *, Illusion::StateValues *, Illusion::Primitive *, Illusion::StateArgs *))
{
  UFG::qVector3 *v7; // rbx
  UFG::qVector3 *v8; // r12
  float v9; // xmm8_4
  char *v10; // r15
  float v11; // xmm4_4
  __m128 v12; // xmm2
  float v13; // xmm5_4
  __m128 v14; // xmm3
  float v15; // xmm1_4
  float v16; // xmm2_4
  float v17; // xmm4_4
  float v18; // xmm5_4
  float v19; // xmm7_4
  float v20; // xmm1_4
  __m128 v21; // xmm6
  signed int v22; // edi
  signed __int64 v23; // rbx
  float v24; // xmm3_4
  float v25; // xmm7_4
  __m128 v26; // xmm2
  float v27; // xmm8_4
  float v28; // xmm10_4
  float v29; // xmm9_4
  float v30; // xmm8_4
  float v31; // xmm10_4
  float v32; // xmm9_4
  float v33; // xmm3_4
  float v34; // xmm2_4
  unsigned int v35; // edx
  unsigned int v37; // edx
  UFG::qVector3 axis; // [rsp+58h] [rbp-D0h]
  UFG::qMatrix44 dest; // [rsp+70h] [rbp-B8h]
  Render::View *v41; // [rsp+130h] [rbp+8h]

  v41 = this;
  v7 = normal;
  v8 = centre;
  v9 = radius;
  v10 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x5D0u, 0x10u);
  if ( v10 )
  {
    v11 = v7->y;
    v12 = (__m128)LODWORD(v7->x);
    v13 = v7->z;
    v14 = v12;
    v14.m128_f32[0] = (float)((float)(v12.m128_f32[0] * v12.m128_f32[0]) + (float)(v11 * v11)) + (float)(v13 * v13);
    v15 = 0.0;
    if ( v14.m128_f32[0] != 0.0 )
      v15 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v14));
    v16 = v12.m128_f32[0] * v15;
    v17 = v11 * v15;
    v18 = v13 * v15;
    axis.x = v16;
    axis.y = v17;
    axis.z = v18;
    if ( v16 <= v17 || v16 <= v18 )
    {
      if ( v17 <= v16 || v17 <= v18 )
      {
        v19 = UFG::qVector3::msAxisX.x;
        v20 = UFG::qVector3::msAxisX.y;
        v21 = (__m128)LODWORD(UFG::qVector3::msAxisX.z);
      }
      else
      {
        v19 = UFG::qVector3::msAxisZ.x;
        v20 = UFG::qVector3::msAxisZ.y;
        v21 = (__m128)LODWORD(UFG::qVector3::msAxisZ.z);
      }
    }
    else
    {
      v19 = UFG::qVector3::msAxisY.x;
      v20 = UFG::qVector3::msAxisY.y;
      v21 = (__m128)LODWORD(UFG::qVector3::msAxisY.z);
    }
    v22 = 0;
    v23 = (signed __int64)(v10 + 8);
    v24 = (float)(v20 * v18) - (float)(v21.m128_f32[0] * v17);
    v21.m128_f32[0] = (float)(v21.m128_f32[0] * v16) - (float)(v19 * v18);
    v25 = (float)(v19 * v17) - (float)(v20 * v16);
    v26 = v21;
    v26.m128_f32[0] = (float)((float)(v21.m128_f32[0] * v21.m128_f32[0]) + (float)(v24 * v24)) + (float)(v25 * v25);
    v27 = v9 / COERCE_FLOAT(_mm_sqrt_ps(v26));
    v28 = v27;
    v29 = v27;
    v30 = v27 * v25;
    v31 = v28 * v21.m128_f32[0];
    v32 = v29 * v24;
    do
    {
      UFG::qRotationMatrixAxis(&dest, &axis, (float)v22 * 0.20943952);
      v33 = (float)((float)((float)(dest.v1.y * v31) + (float)(dest.v0.y * v32)) + (float)(dest.v2.y * v30)) + v8->y;
      v34 = (float)((float)((float)(dest.v1.z * v31) + (float)(dest.v0.z * v32)) + (float)(dest.v2.z * v30)) + v8->z;
      *(float *)(v23 - 8) = (float)((float)((float)(dest.v1.x * v31) + (float)(dest.v0.x * v32))
                                  + (float)(dest.v2.x * v30))
                          + v8->x;
      *(float *)(v23 - 4) = v33;
      *(float *)v23 = v34;
      *(_DWORD *)(v23 + 36) = (signed int)(float)(colour->r * 255.0) | (((signed int)(float)(colour->g * 255.0) | (((signed int)(float)(colour->b * 255.0) | ((signed int)(float)(colour->a * 255.0) << 8)) << 8)) << 8);
      v35 = 0;
      *(_WORD *)(v23 + 4) = (v35 + ((v35 >> 13) & 1) + 4095) >> 13;
      v37 = 0;
      ++v22;
      *(_WORD *)(v23 + 6) = (v37 + ((v37 >> 13) & 1) + 4095) >> 13;
      v23 += 48i64;
    }
    while ( v22 <= 30 );
    Render::View::CreateSimpleMaterial(0xB11369EB, 0x1502048u, 0x2782CCE6u, 0);
    Render::View::DrawDebugPrim(v41, DebugPrim_LineStrip, (Render::vDynamic *)v10, 31);
  }
}0x2782CCE6u, 0);
    Render::View::DrawDebugPrim(v4

// File Line: 2192
// RVA: 0x10490
void __fastcall Render::View::DrawCross(Render::View *this, UFG::qVector3 *vPosition, UFG::DrawInfo *info)
{
  float v3; // xmm5_4
  float v4; // xmm4_4
  UFG::DrawInfo *v5; // rdi
  UFG::qVector3 *v6; // rbx
  Render::View *v7; // rsi
  float v8; // xmm6_4
  float v9; // xmm1_4
  float v10; // xmm7_4
  float v11; // xmm6_4
  float v12; // xmm5_4
  float v13; // xmm4_4
  float v14; // xmm1_4
  float v15; // xmm10_4
  float v16; // xmm7_4
  float v17; // xmm5_4
  float v18; // xmm4_4
  float v19; // xmm1_4
  UFG::qVector3 end; // [rsp+28h] [rbp-29h]
  UFG::qVector3 start; // [rsp+34h] [rbp-1Dh]

  v3 = vPosition->x;
  v4 = vPosition->y;
  v5 = info;
  v6 = vPosition;
  v7 = this;
  v8 = info->mScale;
  v9 = vPosition->z;
  end.x = vPosition->x + (float)((float)(UFG::qVector3::msAxisX.x * v8) * 0.5);
  end.y = v4 + (float)((float)(UFG::qVector3::msAxisX.y * v8) * 0.5);
  start.x = v3 - (float)((float)(UFG::qVector3::msAxisX.x * v8) * 0.5);
  end.z = v9 + (float)((float)(UFG::qVector3::msAxisX.z * v8) * 0.5);
  start.y = v4 - (float)((float)(UFG::qVector3::msAxisX.y * v8) * 0.5);
  start.z = v9 - (float)((float)(UFG::qVector3::msAxisX.z * v8) * 0.5);
  Render::View::DrawSegment(
    this,
    (UFG::qVector3 *)((char *)&start + 8),
    (UFG::qVector3 *)((char *)&end + 8),
    info,
    &UFG::qMatrix44::msIdentity);
  v10 = v5->mScale;
  v11 = v6->x;
  v12 = v6->y;
  v13 = v6->z;
  v14 = v6->y;
  start.x = v6->x + (float)((float)(UFG::qVector3::msAxisY.x * v10) * 0.5);
  start.z = v13 + (float)((float)(UFG::qVector3::msAxisY.z * v10) * 0.5);
  start.y = v14 + (float)((float)(UFG::qVector3::msAxisY.y * v10) * 0.5);
  end.x = v11 - (float)((float)(UFG::qVector3::msAxisY.x * v10) * 0.5);
  end.y = v12 - (float)((float)(UFG::qVector3::msAxisY.y * v10) * 0.5);
  end.z = v13 - (float)((float)(UFG::qVector3::msAxisY.z * v10) * 0.5);
  Render::View::DrawSegment(v7, &end, &start, v5, &UFG::qMatrix44::msIdentity);
  v15 = v5->mScale;
  v16 = v6->x;
  v17 = v6->y;
  v18 = v6->z;
  v19 = v6->y;
  start.x = v6->x + (float)((float)(UFG::qVector3::msAxisZ.x * v15) * 0.5);
  start.y = v19 + (float)((float)(UFG::qVector3::msAxisZ.y * v15) * 0.5);
  start.z = v18 + (float)((float)(UFG::qVector3::msAxisZ.z * v15) * 0.5);
  end.x = v16 - (float)((float)(v15 * UFG::qVector3::msAxisZ.x) * 0.5);
  end.y = v17 - (float)((float)(v15 * UFG::qVector3::msAxisZ.y) * 0.5);
  end.z = v18 - (float)((float)(v15 * UFG::qVector3::msAxisZ.z) * 0.5);
  Render::View::DrawSegment(v7, &end, &start, v5, &UFG::qMatrix44::msIdentity);
}

// File Line: 2220
// RVA: 0xFF30
void __fastcall Render::View::DrawBox(Render::View *this, UFG::qVector3 *boxMin, UFG::qVector3 *boxMax, UFG::DrawInfo *info, UFG::qMatrix44 *xform)
{
  Render::View *v5; // r13
  UFG::qVector3 *v6; // r15
  UFG::qVector3 *v7; // r12
  UFG::DrawInfo *v8; // rbp
  char *v9; // r14
  bool v10; // al
  unsigned int v11; // edx
  float v12; // xmm1_4
  float v13; // xmm0_4
  int v14; // edi
  float v15; // xmm1_4
  float v16; // xmm0_4
  float v17; // xmm0_4
  float v18; // xmm2_4
  float v19; // xmm1_4
  float v20; // xmm0_4
  void (__fastcall *pre_draw_callback)(Illusion::Material *, Render::View *, Illusion::StateValues *, Illusion::Primitive *, Illusion::StateArgs *); // ST30_8
  float v22; // eax
  float *v23; // r8
  float v24; // xmm1_4
  float v25; // eax
  float v26; // xmm2_4
  float v27; // xmm1_4
  float v28; // xmm0_4
  float v29; // xmm2_4
  float v30; // xmm0_4
  void (__fastcall *v31)(Illusion::Material *, Render::View *, Illusion::StateValues *, Illusion::Primitive *, Illusion::StateArgs *); // ST30_8
  float v32; // eax
  float *v33; // r8
  float v34; // xmm1_4
  float v35; // eax
  float v36; // xmm2_4
  float v37; // eax
  float v38; // xmm0_4
  float v39; // xmm1_4
  float v40; // xmm2_4
  float v41; // xmm0_4
  float v42; // eax
  void (__fastcall *v43)(Illusion::Material *, Render::View *, Illusion::StateValues *, Illusion::Primitive *, Illusion::StateArgs *); // ST30_8
  float v44; // eax
  float *v45; // r8
  float v46; // xmm1_4
  float v47; // eax
  float v48; // xmm2_4
  float v49; // xmm0_4
  float v50; // xmm1_4
  float v51; // xmm2_4
  float v52; // xmm0_4
  void (__fastcall *v53)(Illusion::Material *, Render::View *, Illusion::StateValues *, Illusion::Primitive *, Illusion::StateArgs *); // ST30_8

  v5 = this;
  v6 = boxMax;
  v7 = boxMin;
  v8 = info;
  v9 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x300u, 0x10u);
  if ( v9 )
  {
    v10 = v8->mFaceCull;
    v11 = 1660426324;
    if ( v10 )
    {
      if ( v8->mDepthBuffer )
      {
        v11 = 543723269;
LABEL_9:
        Render::View::CreateSimpleMaterial(0xB11369EB, v11, v8->mAlphaBlend, v8->mDepthBias);
        v12 = v6->z;
        v13 = v6->y;
        v14 = (signed int)(float)(v8->mColour1.r * 255.0) | (((signed int)(float)(v8->mColour1.g * 255.0) | (((signed int)(float)(v8->mColour1.b * 255.0) | ((signed int)(float)(v8->mColour1.a * 255.0) << 8)) << 8)) << 8);
        *(float *)v9 = v6->x;
        *((_DWORD *)v9 + 11) = v14;
        *((float *)v9 + 1) = v13;
        *((float *)v9 + 2) = v12;
        v15 = v7->z;
        v16 = v6->y;
        *((_DWORD *)v9 + 12) = LODWORD(v6->x);
        *((float *)v9 + 14) = v15;
        *((_DWORD *)v9 + 23) = v14;
        *((float *)v9 + 13) = v16;
        v17 = v6->y;
        v18 = v7->z;
        *((_DWORD *)v9 + 24) = LODWORD(v7->x);
        *((float *)v9 + 25) = v17;
        *((_DWORD *)v9 + 35) = v14;
        *((float *)v9 + 26) = v18;
        v19 = v6->z;
        v20 = v6->y;
        *((_DWORD *)v9 + 36) = LODWORD(v7->x);
        *((float *)v9 + 38) = v19;
        *((_DWORD *)v9 + 47) = v14;
        *((float *)v9 + 37) = v20;
        pre_draw_callback = v8->mPreDrawCallback;
        Render::View::DrawDebugPrim(v5, DebugPrim_LineStrip, (Render::vDynamic *)v9, 4);
        v22 = v6->x;
        v23 = (float *)(v9 + 192);
        v24 = v7->z;
        v23[1] = v6->y;
        v23[2] = v24;
        *v23 = v22;
        *((_DWORD *)v23 + 11) = v14;
        v25 = v6->x;
        v26 = v7->z;
        *((_DWORD *)v9 + 61) = LODWORD(v7->y);
        *((float *)v9 + 62) = v26;
        *((_DWORD *)v9 + 71) = v14;
        *((float *)v9 + 60) = v25;
        v27 = v7->z;
        v28 = v7->y;
        *((_DWORD *)v9 + 72) = LODWORD(v7->x);
        *((float *)v9 + 73) = v28;
        *((float *)v9 + 74) = v27;
        *((_DWORD *)v9 + 83) = v14;
        v29 = v7->z;
        v30 = v6->y;
        *((_DWORD *)v9 + 84) = LODWORD(v7->x);
        *((_DWORD *)v9 + 95) = v14;
        *((float *)v9 + 85) = v30;
        *((float *)v9 + 86) = v29;
        v31 = v8->mPreDrawCallback;
        Render::View::DrawDebugPrim(v5, DebugPrim_LineStrip, (Render::vDynamic *)v9 + 4, 4);
        v32 = v6->x;
        v33 = (float *)(v9 + 384);
        v34 = v7->z;
        v33[1] = v7->y;
        v33[2] = v34;
        *v33 = v32;
        *((_DWORD *)v33 + 11) = v14;
        v35 = v6->x;
        v36 = v6->z;
        *((_DWORD *)v9 + 109) = LODWORD(v7->y);
        *((float *)v9 + 110) = v36;
        *((_DWORD *)v9 + 119) = v14;
        *((float *)v9 + 108) = v35;
        v37 = v7->x;
        v38 = v7->y;
        v39 = v6->z;
        *((_DWORD *)v9 + 131) = v14;
        *((float *)v9 + 120) = v37;
        *((float *)v9 + 121) = v38;
        *((float *)v9 + 122) = v39;
        v40 = v7->z;
        v41 = v7->y;
        v42 = v7->x;
        *((_DWORD *)v9 + 143) = v14;
        *((float *)v9 + 133) = v41;
        *((float *)v9 + 134) = v40;
        *((float *)v9 + 132) = v42;
        v43 = v8->mPreDrawCallback;
        Render::View::DrawDebugPrim(v5, DebugPrim_LineStrip, (Render::vDynamic *)v9 + 8, 4);
        v44 = v6->x;
        v45 = (float *)(v9 + 576);
        v46 = v6->z;
        v45[1] = v7->y;
        v45[2] = v46;
        *v45 = v44;
        *((_DWORD *)v45 + 11) = v14;
        v47 = v6->x;
        v48 = v6->z;
        *((_DWORD *)v9 + 157) = LODWORD(v6->y);
        *((float *)v9 + 158) = v48;
        *((_DWORD *)v9 + 167) = v14;
        *((float *)v9 + 156) = v47;
        v49 = v6->y;
        v50 = v6->z;
        *((_DWORD *)v9 + 168) = LODWORD(v7->x);
        *((float *)v9 + 169) = v49;
        *((float *)v9 + 170) = v50;
        *((_DWORD *)v9 + 179) = v14;
        v51 = v6->z;
        v52 = v7->y;
        *((_DWORD *)v9 + 180) = LODWORD(v7->x);
        *((float *)v9 + 181) = v52;
        *((float *)v9 + 182) = v51;
        *((_DWORD *)v9 + 191) = v14;
        v53 = v8->mPreDrawCallback;
        Render::View::DrawDebugPrim(v5, DebugPrim_LineStrip, (Render::vDynamic *)v9 + 12, 4);
        return;
      }
      if ( v10 )
      {
        v11 = 206781021;
        goto LABEL_9;
      }
    }
    if ( v8->mDepthBuffer )
      v11 = 1099738947;
    goto LABEL_9;
  }
}

// File Line: 2511
// RVA: 0x141A0
void __fastcall Render::View::DrawIcosahedronSolid(Render::View *this, UFG::qMatrix44 *xform, UFG::DrawInfo *info)
{
  UFG::qMatrix44 *v3; // rbp
  Render::View *v4; // rsi
  UFG::DrawInfo *v5; // rdi
  int v6; // ebx
  __m128 v7; // xmm0
  float v8; // xmm9_4
  float v9; // xmm8_4
  float v10; // xmm7_4
  float v11; // xmm9_4
  float v12; // xmm7_4
  float v13; // xmm6_4
  float v14; // xmm8_4
  char *v15; // rax
  signed __int64 v16; // rcx
  signed __int64 v17; // rax
  int v18; // ebx
  CB_ColourBiasScale *v19; // rdx
  char *v20; // rax
  float v21; // ecx
  float v22; // ecx
  Illusion::SubmitContext *v23; // rax
  bool v24; // al
  unsigned int v25; // edx
  Illusion::Material *v26; // rax
  Illusion::Material *v27; // rbx
  void (__fastcall *pre_draw_callback)(Illusion::Material *, Render::View *, Illusion::StateValues *, Illusion::Primitive *, Illusion::StateArgs *); // ST30_8

  v3 = xform;
  v4 = this;
  v5 = info;
  v6 = (signed int)(float)(info->mColour1.r * 255.0) | (((signed int)(float)(info->mColour1.g * 255.0) | (((signed int)(float)(info->mColour1.b * 255.0) | ((signed int)(float)(info->mColour1.a * 255.0) << 8)) << 8)) << 8);
  if ( !UFG::qLinearAllocator::InFrame(Illusion::gEngine.FrameMemory, spVerts_0) || sColourSolidV != v6 )
  {
    v7 = _mm_sqrt_ps((__m128)LODWORD(FLOAT_5_0));
    v7.m128_f32[0] = (float)(v7.m128_f32[0] * 2.0) + 10.0;
    v8 = 1.0 / (float)(COERCE_FLOAT(_mm_sqrt_ps(v7)) * 0.1545085);
    v9 = v8 * 0.5;
    v10 = v8 * 0.309017;
    v11 = (float)(v8 * 0.309017) * -0.5;
    v12 = v10 * 0.5;
    v13 = v9 * -0.5;
    v14 = v9 * 0.5;
    v15 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0xB40u, 0x10u);
    sColourSolidV = v6;
    *(_DWORD *)v15 = 0;
    spVerts_0 = (Render::vDynamic *)v15;
    *((float *)v15 + 1) = v12;
    *((float *)v15 + 2) = v13;
    *((float *)v15 + 12) = v12;
    *((float *)v15 + 13) = v14;
    *((_DWORD *)v15 + 14) = 0;
    *((_DWORD *)v15 + 26) = 0;
    *((float *)v15 + 24) = v11;
    *((float *)v15 + 25) = v14;
    *((_DWORD *)v15 + 36) = 0;
    *((float *)v15 + 37) = v12;
    *((float *)v15 + 38) = v14;
    *((_DWORD *)v15 + 50) = 0;
    *((float *)v15 + 48) = v11;
    *((float *)v15 + 49) = v14;
    *((float *)v15 + 60) = v12;
    *((_DWORD *)v15 + 62) = 0;
    *((float *)v15 + 61) = v14;
    *((float *)v15 + 73) = v12;
    *((float *)v15 + 74) = v14;
    *((_DWORD *)v15 + 72) = 0;
    *((_DWORD *)v15 + 84) = 0;
    *((float *)v15 + 85) = v11;
    *((float *)v15 + 86) = v14;
    *((float *)v15 + 96) = v13;
    *((_DWORD *)v15 + 97) = 0;
    *((float *)v15 + 98) = v12;
    *((float *)v15 + 109) = v12;
    *((float *)v15 + 110) = v14;
    *((_DWORD *)v15 + 108) = 0;
    *((_DWORD *)v15 + 121) = 0;
    *((float *)v15 + 120) = v14;
    *((float *)v15 + 122) = v12;
    *((float *)v15 + 133) = v11;
    *((_DWORD *)v15 + 132) = 0;
    *((float *)v15 + 134) = v14;
    *((float *)v15 + 145) = v12;
    *((float *)v15 + 146) = v13;
    *((_DWORD *)v15 + 144) = 0;
    *((_DWORD *)v15 + 156) = 0;
    *((float *)v15 + 157) = v11;
    *((float *)v15 + 158) = v13;
    *((float *)v15 + 168) = v14;
    *((_DWORD *)v15 + 169) = 0;
    *((float *)v15 + 170) = v11;
    *((float *)v15 + 181) = v12;
    *((float *)v15 + 182) = v13;
    *((_DWORD *)v15 + 180) = 0;
    *((_DWORD *)v15 + 193) = 0;
    *((float *)v15 + 192) = v13;
    *((float *)v15 + 194) = v11;
    *((float *)v15 + 205) = v11;
    *((_DWORD *)v15 + 204) = 0;
    *((float *)v15 + 206) = v13;
    *((float *)v15 + 217) = v11;
    *((float *)v15 + 218) = v14;
    *((_DWORD *)v15 + 216) = 0;
    *((_DWORD *)v15 + 230) = 0;
    *((float *)v15 + 228) = v12;
    *((float *)v15 + 229) = v13;
    *((float *)v15 + 240) = v11;
    *((_DWORD *)v15 + 242) = 0;
    *((float *)v15 + 241) = v13;
    *((float *)v15 + 253) = v11;
    *((float *)v15 + 254) = v13;
    *((_DWORD *)v15 + 252) = 0;
    *((_DWORD *)v15 + 266) = 0;
    *((float *)v15 + 264) = v11;
    *((float *)v15 + 265) = v13;
    *((float *)v15 + 276) = v12;
    *((_DWORD *)v15 + 278) = 0;
    *((float *)v15 + 277) = v13;
    *((float *)v15 + 288) = v11;
    *((float *)v15 + 289) = v14;
    *((_DWORD *)v15 + 290) = 0;
    *((_DWORD *)v15 + 301) = 0;
    *((float *)v15 + 300) = v13;
    *((float *)v15 + 302) = v12;
    *((float *)v15 + 312) = v13;
    *((_DWORD *)v15 + 313) = 0;
    *((float *)v15 + 314) = v11;
    *((float *)v15 + 324) = v11;
    *((float *)v15 + 325) = v13;
    *((_DWORD *)v15 + 326) = 0;
    *((_DWORD *)v15 + 337) = 0;
    *((float *)v15 + 336) = v13;
    *((float *)v15 + 338) = v11;
    *((float *)v15 + 348) = v13;
    *((_DWORD *)v15 + 349) = 0;
    *((float *)v15 + 350) = v12;
    *((float *)v15 + 360) = v12;
    *((float *)v15 + 361) = v14;
    *((_DWORD *)v15 + 362) = 0;
    *((_DWORD *)v15 + 373) = 0;
    *((float *)v15 + 372) = v14;
    *((float *)v15 + 374) = v11;
    *((float *)v15 + 384) = v14;
    *((_DWORD *)v15 + 385) = 0;
    *((float *)v15 + 386) = v12;
    *((float *)v15 + 396) = v12;
    *((float *)v15 + 397) = v13;
    *((_DWORD *)v15 + 398) = 0;
    *((_DWORD *)v15 + 409) = 0;
    *((float *)v15 + 408) = v14;
    *((float *)v15 + 410) = v12;
    *((float *)v15 + 420) = v14;
    *((_DWORD *)v15 + 421) = 0;
    *((float *)v15 + 422) = v11;
    *((float *)v15 + 433) = v12;
    *((float *)v15 + 434) = v14;
    *((_DWORD *)v15 + 432) = 0;
    *((_DWORD *)v15 + 445) = 0;
    *((float *)v15 + 444) = v13;
    *((float *)v15 + 446) = v12;
    *((float *)v15 + 456) = v11;
    *((_DWORD *)v15 + 458) = 0;
    *((float *)v15 + 457) = v14;
    *((float *)v15 + 469) = v12;
    *((float *)v15 + 470) = v14;
    *((_DWORD *)v15 + 468) = 0;
    *((_DWORD *)v15 + 482) = 0;
    *((float *)v15 + 480) = v12;
    *((float *)v15 + 481) = v14;
    *((float *)v15 + 492) = v14;
    *((_DWORD *)v15 + 493) = 0;
    *((float *)v15 + 494) = v12;
    *((float *)v15 + 505) = v12;
    *((float *)v15 + 506) = v13;
    *((_DWORD *)v15 + 504) = 0;
    *((_DWORD *)v15 + 518) = 0;
    *((float *)v15 + 516) = v11;
    *((float *)v15 + 517) = v14;
    *((float *)v15 + 528) = v13;
    *((_DWORD *)v15 + 529) = 0;
    *((float *)v15 + 530) = v11;
    *((float *)v15 + 541) = v12;
    *((float *)v15 + 542) = v13;
    *((_DWORD *)v15 + 540) = 0;
    *((_DWORD *)v15 + 553) = 0;
    v16 = 60i64;
    *((float *)v15 + 552) = v14;
    *((float *)v15 + 554) = v11;
    *((float *)v15 + 564) = v12;
    *((_DWORD *)v15 + 566) = 0;
    v17 = (signed __int64)(v15 + 44);
    *(float *)(v17 + 2216) = v14;
    *(float *)(v17 + 2264) = v11;
    *(float *)(v17 + 2268) = v13;
    *(_DWORD *)(v17 + 2260) = 0;
    *(_DWORD *)(v17 + 2312) = 0;
    *(float *)(v17 + 2308) = v13;
    *(float *)(v17 + 2316) = v11;
    *(float *)(v17 + 2356) = v11;
    *(_DWORD *)(v17 + 2364) = 0;
    *(float *)(v17 + 2360) = v13;
    *(float *)(v17 + 2408) = v11;
    *(float *)(v17 + 2412) = v13;
    *(_DWORD *)(v17 + 2404) = 0;
    *(_DWORD *)(v17 + 2460) = 0;
    *(float *)(v17 + 2452) = v12;
    *(float *)(v17 + 2456) = v13;
    *(float *)(v17 + 2500) = v14;
    *(_DWORD *)(v17 + 2504) = 0;
    *(float *)(v17 + 2508) = v11;
    *(float *)(v17 + 2552) = v11;
    *(float *)(v17 + 2556) = v14;
    *(_DWORD *)(v17 + 2548) = 0;
    *(_DWORD *)(v17 + 2604) = 0;
    *(float *)(v17 + 2596) = v11;
    *(float *)(v17 + 2600) = v13;
    *(float *)(v17 + 2644) = v13;
    *(_DWORD *)(v17 + 2648) = 0;
    *(float *)(v17 + 2652) = v12;
    *(float *)(v17 + 2696) = v11;
    *(float *)(v17 + 2700) = v14;
    *(_DWORD *)(v17 + 2692) = 0;
    *(_DWORD *)(v17 + 2744) = 0;
    *(float *)(v17 + 2740) = v14;
    *(float *)(v17 + 2748) = v12;
    *(float *)(v17 + 2788) = v12;
    *(_DWORD *)(v17 + 2796) = 0;
    *(float *)(v17 + 2792) = v13;
    do
    {
      *(_DWORD *)v17 = v6;
      v17 += 48i64;
      --v16;
    }
    while ( v16 );
  }
  v18 = (signed int)(float)(v5->mColour1.r * 255.0) | (((signed int)(float)(v5->mColour1.g * 255.0) | (((signed int)(float)(v5->mColour1.b * 255.0) | ((signed int)(float)(v5->mColour1.a * 255.0) << 8)) << 8)) << 8);
  if ( sColourSolidB == v18 && UFG::qLinearAllocator::InFrame(Illusion::gEngine.FrameMemory, pSolidColourBias) )
  {
    v19 = pSolidColourBias;
  }
  else
  {
    v20 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x20u, 0x10u);
    v21 = v5->mColour1.r;
    sColourSolidB = v18;
    *((float *)v20 + 4) = v21;
    v19 = (CB_ColourBiasScale *)v20;
    *((_DWORD *)v20 + 5) = LODWORD(v5->mColour1.g);
    v22 = v5->mColour1.b;
    pSolidColourBias = (CB_ColourBiasScale *)v20;
    *((float *)v20 + 6) = v22;
    *((_DWORD *)v20 + 7) = LODWORD(v5->mColour1.a);
    *(_QWORD *)v20 = 0i64;
    *((_QWORD *)v20 + 1) = 0i64;
  }
  v23 = v4->mSubmitContext;
  v23->mStateValues.mSetValueMask.mFlags[0] |= 0x4000ui64;
  v23->mStateValues.mParamValues[14] = v19;
  v24 = v5->mFaceCull;
  v25 = 1660426324;
  if ( v24 )
  {
    if ( v5->mDepthBuffer )
    {
      v25 = 543723269;
      goto LABEL_16;
    }
    if ( v24 )
    {
      v25 = 206781021;
      goto LABEL_16;
    }
  }
  if ( v5->mDepthBuffer )
    v25 = 1099738947;
LABEL_16:
  v26 = Render::View::CreateSimpleMaterial(0xB11369EB, v25, v5->mAlphaBlend, v5->mDepthBias);
  v26->mStateBlockMask.mFlags[0] |= 0x4000ui64;
  v27 = v26;
  Render::View::ScaleToFit(v4, v3, v5->mScale, Fit_scale_adjust_9);
  pre_draw_callback = v5->mPreDrawCallback;
  Render::View::DrawDebugPrim(v4, DebugPrim_Triangle, spVerts_0, 60);
  v27->mStateBlockMask.mFlags[0] &= 0xFFFFFFFFFFFFBFFFui64;
}

// File Line: 2620
// RVA: 0x14E00
void __fastcall Render::View::DrawSphere(Render::View *this, UFG::qMatrix44 *xform, UFG::DrawInfo *info)
{
  float v3; // xmm1_4
  bool v4; // bl
  bool v5; // r12
  UFG::DrawInfo *v6; // rdi
  UFG::qMatrix44 *v7; // r14
  float v8; // xmm0_4
  Render::View *v9; // r13
  float v10; // xmm1_4
  float v11; // xmm0_4
  __int128 v12; // xmm13
  float v13; // xmm0_4
  __m128 v14; // xmm14
  __int128 v15; // xmm15
  float v16; // xmm0_4
  float v17; // xmm1_4
  float v18; // xmm0_4
  float v19; // xmm1_4
  float v20; // xmm10_4
  __m128 v21; // xmm9
  float v22; // xmm11_4
  __m128 v23; // xmm2
  float v24; // xmm1_4
  float v25; // xmm9_4
  float v26; // xmm10_4
  float v27; // xmm11_4
  __m128 v28; // xmm8
  float v29; // xmm3_4
  __m128 v30; // xmm1
  __m128 v31; // xmm5
  __m128 v32; // xmm2
  float v33; // xmm4_4
  __m128 v34; // xmm3
  float v35; // xmm1_4
  float v36; // xmm4_4
  float v37; // xmm2_4
  float v38; // xmm3_4
  __m128 v39; // xmm12
  float v40; // xmm2_4
  __m128 v41; // xmm4
  float v42; // xmm1_4
  float v43; // xmm11_4
  float v44; // xmm12_4
  unsigned int v45; // esi
  Render::vDynamic *v46; // r15
  unsigned int v47; // edx
  float v48; // xmm9_4
  float v49; // xmm1_4
  float v50; // xmm4_4
  __m128 v51; // xmm3
  float v52; // xmm8_4
  float v53; // xmm14_4
  __m128 v54; // xmm2
  float v55; // xmm1_4
  float v56; // xmm3_4
  float v57; // xmm8_4
  float v58; // xmm4_4
  __int128 v59; // xmm5
  float v60; // xmm8_4
  __m128 v61; // xmm2
  float v62; // xmm8_4
  __m128 v63; // xmm3
  float v64; // xmm1_4
  float v65; // xmm2_4
  float v66; // xmm0_4
  float v67; // xmm2_4
  float v68; // xmm3_4
  __m128 v69; // xmm4
  __m128 v70; // xmm5
  float v71; // xmm7_4
  Render::vDynamic *v72; // r15
  signed int v73; // eax
  UFG::qMatrix44 xforma; // [rsp+40h] [rbp-C0h]
  float scale; // [rsp+80h] [rbp-80h]
  float v76; // [rsp+84h] [rbp-7Ch]
  float v77; // [rsp+88h] [rbp-78h]
  void (__fastcall *v78)(Illusion::Material *, Render::View *, Illusion::StateValues *, Illusion::Primitive *, Illusion::StateArgs *); // [rsp+90h] [rbp-70h]
  UFG::DrawInfo infoa; // [rsp+98h] [rbp-68h]
  bool v80; // [rsp+1B8h] [rbp+B8h]
  float v81; // [rsp+1C8h] [rbp+C8h]

  v3 = info->mColour2.g;
  v4 = info->mFaceCull;
  v5 = info->mDepthBuffer;
  v6 = info;
  v7 = xform;
  infoa.mColour2.r = info->mColour2.r;
  v8 = info->mColour2.b;
  infoa.mColour2.g = v3;
  v9 = this;
  infoa.mFaceCull = v4;
  v10 = info->mColour2.a;
  infoa.mColour2.b = v8;
  v11 = info->mScale;
  infoa.mDepthBuffer = v5;
  infoa.mAlphaBlend = 662883558;
  v12 = LODWORD(xform->v2.x);
  scale = v11;
  infoa.mScale = v11;
  v80 = info->mDepthBias;
  infoa.mDepthBias = info->mDepthBias;
  v13 = xform->v3.x;
  v14 = (__m128)LODWORD(xform->v2.y);
  v15 = LODWORD(xform->v2.z);
  v78 = info->mPreDrawCallback;
  infoa.mPreDrawCallback = v78;
  v81 = v13;
  v16 = xform->v3.y;
  infoa.mColour2.a = v10;
  v17 = info->mColour2.g;
  v77 = v16;
  v76 = xform->v3.z;
  v18 = info->mColour2.r;
  infoa.mColour1.g = v17;
  v19 = info->mColour2.a;
  infoa.mColour1.r = v18;
  infoa.mColour1.b = info->mColour2.b;
  infoa.mColour1.a = v19;
  Render::View::DrawCircle(this, xform, &infoa, 0x40u);
  v20 = v7->v1.y;
  v21 = (__m128)LODWORD(v7->v1.x);
  v22 = v7->v1.z;
  v23 = v21;
  v23.m128_f32[0] = (float)((float)(v21.m128_f32[0] * v21.m128_f32[0]) + (float)(v20 * v20)) + (float)(v22 * v22);
  if ( v23.m128_f32[0] == 0.0 )
    v24 = 0.0;
  else
    v24 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v23));
  v25 = v21.m128_f32[0] * v24;
  v26 = v20 * v24;
  v27 = v22 * v24;
  v28 = v14;
  xforma.v0.w = 0.0;
  xforma.v0.x = v25;
  xforma.v0.y = v26;
  xforma.v0.z = v27;
  v28.m128_f32[0] = (float)((float)(v14.m128_f32[0] * v14.m128_f32[0]) + (float)(*(float *)&v12 * *(float *)&v12))
                  + (float)(*(float *)&v15 * *(float *)&v15);
  if ( v28.m128_f32[0] == 0.0 )
    v29 = 0.0;
  else
    v29 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v28));
  v30 = v14;
  v32 = (__m128)v15;
  v30.m128_f32[0] = v14.m128_f32[0] * v29;
  v31 = v30;
  v31.m128_f32[0] = (float)((float)(v14.m128_f32[0] * v29) * v27) - (float)((float)(*(float *)&v15 * v29) * v26);
  v32.m128_f32[0] = (float)((float)(*(float *)&v15 * v29) * v25) - (float)((float)(*(float *)&v12 * v29) * v27);
  v33 = (float)((float)(*(float *)&v12 * v29) * v26) - (float)((float)(v14.m128_f32[0] * v29) * v25);
  v34 = v32;
  v34.m128_f32[0] = (float)((float)(v32.m128_f32[0] * v32.m128_f32[0]) + (float)(v31.m128_f32[0] * v31.m128_f32[0]))
                  + (float)(v33 * v33);
  if ( v34.m128_f32[0] == 0.0 )
    v35 = 0.0;
  else
    v35 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v34));
  v36 = v33 * v35;
  v37 = v32.m128_f32[0] * v35;
  v31.m128_f32[0] = v31.m128_f32[0] * v35;
  xforma.v1.w = 0.0;
  xforma.v1.z = v36;
  xforma.v1.y = v37;
  LODWORD(xforma.v1.x) = v31.m128_i32[0];
  v39 = v31;
  v38 = (float)(v36 * v26) - (float)(v37 * v27);
  v39.m128_f32[0] = (float)(v31.m128_f32[0] * v27) - (float)(v36 * v25);
  v40 = (float)(v37 * v25) - (float)(v31.m128_f32[0] * v26);
  v41 = v39;
  v41.m128_f32[0] = (float)((float)(v39.m128_f32[0] * v39.m128_f32[0]) + (float)(v38 * v38)) + (float)(v40 * v40);
  if ( v41.m128_f32[0] == 0.0 )
    v42 = 0.0;
  else
    v42 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v41));
  v43 = v77;
  xforma.v2.w = 0.0;
  xforma.v3.w = 1.0;
  xforma.v2.y = v39.m128_f32[0] * v42;
  v44 = v76;
  xforma.v3.x = v81;
  xforma.v3.z = v76;
  xforma.v2.x = v38 * v42;
  xforma.v2.z = v40 * v42;
  xforma.v3.y = v77;
  v45 = 206781021;
  v46 = `anonymous namespace::GetVertsCircle(0x40u, &infoa.mColour1);
  if ( v4 )
  {
    v47 = 206781021;
    if ( v5 )
      v47 = 543723269;
  }
  else
  {
    v47 = 1660426324;
    if ( v5 )
      v47 = 1099738947;
  }
  v48 = scale;
  Render::View::CreateSimpleMaterial(0xB11369EB, v47, 0x2782CCE6u, v80);
  Render::View::ScaleToFit(v9, &xforma, scale, Fit_scale_adjust_9);
  Render::View::DrawDebugPrim(v9, DebugPrim_LineStrip, v46 + 1, 65);
  if ( v28.m128_f32[0] == 0.0 )
    v49 = 0.0;
  else
    v49 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v28));
  v50 = v7->v0.y;
  v51 = (__m128)LODWORD(v7->v0.x);
  v52 = v7->v0.z;
  *(float *)&v12 = *(float *)&v12 * v49;
  v53 = v14.m128_f32[0] * v49;
  *(float *)&v15 = *(float *)&v15 * v49;
  xforma.v0.w = 0.0;
  v54 = v51;
  LODWORD(xforma.v0.x) = v12;
  xforma.v0.y = v53;
  LODWORD(xforma.v0.z) = v15;
  v54.m128_f32[0] = (float)((float)(v51.m128_f32[0] * v51.m128_f32[0]) + (float)(v50 * v50)) + (float)(v52 * v52);
  if ( v54.m128_f32[0] == 0.0 )
    v55 = 0.0;
  else
    v55 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v54));
  v56 = v51.m128_f32[0] * v55;
  v57 = v52 * v55;
  v58 = v50 * v55;
  v59 = v15;
  v61 = (__m128)v12;
  v61.m128_f32[0] = *(float *)&v12 * v57;
  *(float *)&v59 = (float)(*(float *)&v15 * v58) - (float)(v53 * v57);
  v60 = v53 * v56;
  v61.m128_f32[0] = v61.m128_f32[0] - (float)(*(float *)&v15 * v56);
  v63 = v61;
  v62 = v60 - (float)(*(float *)&v12 * v58);
  v63.m128_f32[0] = (float)((float)(v61.m128_f32[0] * v61.m128_f32[0]) + (float)(*(float *)&v59 * *(float *)&v59))
                  + (float)(v62 * v62);
  if ( v63.m128_f32[0] == 0.0 )
    v64 = 0.0;
  else
    v64 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v63));
  *(float *)&v59 = *(float *)&v59 * v64;
  v65 = v61.m128_f32[0] * v64;
  xforma.v1.w = 0.0;
  v69 = (__m128)v59;
  LODWORD(xforma.v1.x) = v59;
  xforma.v1.y = v65;
  xforma.v1.z = v62 * v64;
  v66 = v65 * *(float *)&v15;
  v67 = (float)(v65 * *(float *)&v12) - (float)(*(float *)&v59 * v53);
  v68 = (float)((float)(v62 * v64) * v53) - v66;
  v69.m128_f32[0] = (float)(*(float *)&v59 * *(float *)&v15) - (float)((float)(v62 * v64) * *(float *)&v12);
  v70 = v69;
  v70.m128_f32[0] = (float)((float)(v69.m128_f32[0] * v69.m128_f32[0]) + (float)(v68 * v68)) + (float)(v67 * v67);
  if ( v70.m128_f32[0] == 0.0 )
    v71 = 0.0;
  else
    v71 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v70));
  xforma.v3.x = v81;
  xforma.v3.y = v43;
  xforma.v3.z = v44;
  xforma.v2.w = 0.0;
  xforma.v3.w = 1.0;
  xforma.v2.x = v68 * v71;
  xforma.v2.y = v69.m128_f32[0] * v71;
  xforma.v2.z = v67 * v71;
  v72 = `anonymous namespace::GetVertsCircle(0x40u, &infoa.mColour1);
  if ( v4 )
  {
    v73 = 543723269;
  }
  else
  {
    v45 = 1660426324;
    v73 = 1099738947;
  }
  if ( v5 )
    v45 = v73;
  Render::View::CreateSimpleMaterial(0xB11369EB, v45, 0x2782CCE6u, v80);
  Render::View::ScaleToFit(v9, &xforma, v48, Fit_scale_adjust_9);
  Render::View::DrawDebugPrim(v9, DebugPrim_LineStrip, v72 + 1, 65);
  if ( UFG::qColour::Zero.r != v6->mColour1.r
    || UFG::qColour::Zero.g != v6->mColour1.g
    || UFG::qColour::Zero.b != v6->mColour1.b
    || UFG::qColour::Zero.a != v6->mColour1.a )
  {
    Render::View::DrawIcosahedronSolid(v9, v7, v6);
  }
}

// File Line: 2709
// RVA: 0x13A50
void __fastcall Render::View::DrawFrustum(Render::View *this, UFG::qVector4 *frustumPlanes, UFG::qColour *colour)
{
  UFG::qVector4 *v3; // r15
  UFG::qVector4 *v4; // r14
  UFG::qColour *v5; // r12
  UFG::ePlaneIntersect v6; // esi
  UFG::ePlaneIntersect v7; // er13
  UFG::ePlaneIntersect v8; // ebx
  UFG::ePlaneIntersect v9; // eax
  bool v10; // di
  bool v11; // r13
  bool v12; // r14
  bool v13; // si
  bool v14; // al
  float v15; // xmm1_4
  float v16; // xmm0_4
  float v17; // xmm1_4
  float v18; // xmm0_4
  float v19; // xmm0_4
  float v20; // xmm1_4
  float v21; // xmm1_4
  bool v22; // [rsp+40h] [rbp-C0h]
  UFG::DrawInfo info; // [rsp+48h] [rbp-B8h]
  UFG::qVector3 ray_pos; // [rsp+80h] [rbp-80h]
  UFG::qVector3 line_pos; // [rsp+8Ch] [rbp-74h]
  UFG::qVector3 v26; // [rsp+98h] [rbp-68h]
  UFG::qVector3 v27; // [rsp+A4h] [rbp-5Ch]
  UFG::qVector3 ray_dir; // [rsp+B0h] [rbp-50h]
  UFG::qVector3 line_dir; // [rsp+BCh] [rbp-44h]
  UFG::qVector3 v30; // [rsp+C8h] [rbp-38h]
  UFG::qVector3 v31; // [rsp+D4h] [rbp-2Ch]
  UFG::qVector3 hit_pos_p; // [rsp+E0h] [rbp-20h]
  UFG::qVector3 start; // [rsp+ECh] [rbp-14h]
  UFG::qVector3 v34; // [rsp+F8h] [rbp-8h]
  UFG::qVector3 v35; // [rsp+104h] [rbp+4h]
  UFG::qVector3 line_points; // [rsp+110h] [rbp+10h]
  UFG::qVector3 end; // [rsp+11Ch] [rbp+1Ch]
  UFG::qVector3 v38; // [rsp+128h] [rbp+28h]
  UFG::qVector3 v39; // [rsp+134h] [rbp+34h]
  Render::View *v40; // [rsp+180h] [rbp+80h]
  bool v41; // [rsp+188h] [rbp+88h]
  bool v42; // [rsp+198h] [rbp+98h]

  v40 = this;
  v3 = frustumPlanes;
  v4 = frustumPlanes + 1;
  v5 = colour;
  v6 = UFG::qIntersectPlanePlane(frustumPlanes + 4, frustumPlanes + 1, &ray_pos, &ray_dir);
  v7 = UFG::qIntersectPlanePlane(v3 + 4, v3 + 2, &line_pos, &line_dir);
  v8 = UFG::qIntersectPlanePlane(v3 + 3, v3 + 2, &v26, &v30);
  v9 = UFG::qIntersectPlanePlane(v3 + 3, v4, &v27, &v31);
  if ( v6 == 2 && v7 == 2 && v8 == 2 && v9 == 2 )
  {
    v10 = UFG::qIntersectDirLinePlane(&ray_pos, &ray_dir, v3, &hit_pos_p);
    v11 = UFG::qIntersectDirLinePlane(&ray_pos, &ray_dir, v3 + 5, &line_points);
    v41 = UFG::qIntersectDirLinePlane(&line_pos, &line_dir, v3, &start);
    v42 = UFG::qIntersectDirLinePlane(&line_pos, &line_dir, v3 + 5, &end);
    v22 = UFG::qIntersectDirLinePlane(&v26, &v30, v3, &v34);
    v12 = UFG::qIntersectDirLinePlane(&v26, &v30, v3 + 5, &v38);
    v13 = UFG::qIntersectDirLinePlane(&v27, &v31, v3, &v35);
    v14 = UFG::qIntersectDirLinePlane(&v27, &v31, v3 + 5, &v39);
    if ( v10 && v11 && v41 && v42 && v22 && v12 && v13 && v14 )
    {
      Render::View::DrawDebugConnectedPrimLineStrip(v40, &hit_pos_p, 4, v5, &UFG::qMatrix44::msIdentity, 1, 0);
      Render::View::DrawDebugConnectedPrimLineStrip(v40, &line_points, 4, v5, &UFG::qMatrix44::msIdentity, 1, 0);
      v15 = v5->g;
      info.mColour1.r = v5->r;
      v16 = v5->b;
      info.mColour1.g = v15;
      v17 = v5->a;
      info.mColour1.b = v16;
      v18 = v5->r;
      info.mAlphaBlend = 662883558;
      *(_WORD *)&info.mDepthBuffer = 257;
      info.mColour2.r = v18;
      v19 = v5->b;
      info.mColour1.a = v17;
      info.mDepthBias = 0;
      info.mPreDrawCallback = 0i64;
      v20 = v5->g;
      info.mColour2.b = v19;
      info.mColour2.g = v20;
      v21 = v5->a;
      LODWORD(info.mScale) = (_DWORD)FLOAT_1_0;
      info.mColour2.a = v21;
      Render::View::DrawSegment(v40, &hit_pos_p, &line_points, &info, &UFG::qMatrix44::msIdentity);
      Render::View::DrawSegment(v40, &start, &end, &info, &UFG::qMatrix44::msIdentity);
      Render::View::DrawSegment(v40, &v34, &v38, &info, &UFG::qMatrix44::msIdentity);
      Render::View::DrawSegment(v40, &v35, &v39, &info, &UFG::qMatrix44::msIdentity);
    }
  }
}

// File Line: 2791
// RVA: 0xE830
void __fastcall Render::View::Draw(Render::View *this, Render::Poly *poly, unsigned int texture_name_uid, UFG::qMatrix44 *local_world, const unsigned int raster_state_uid, const unsigned int alpha_state_uid)
{
  Render::Poly *v6; // rdi
  UFG::qMatrix44 *v7; // rbx
  Render::View *v8; // rsi
  Illusion::Material *v9; // rax

  v6 = poly;
  v7 = local_world;
  v8 = this;
  v9 = Render::View::CreateSimpleMaterial(texture_name_uid, raster_state_uid, alpha_state_uid, 0);
  Render::View::Draw(v8, v6, v9, v7);
}

// File Line: 2957
// RVA: 0x10A20
void __fastcall Render::View::DrawDebugPrim(Render::View *this, Render::DebugPrimType debug_prim_type, Render::vDynamic *vertices, int num_vertices)
{
  int v4; // esi
  Render::vDynamic *v5; // r14
  Render::View *v6; // r12
  Illusion::SubmitContext *v7; // rax
  signed __int64 v8; // r15
  Illusion::StateArgs *v9; // rbx
  Illusion::Material *v10; // r13
  unsigned int v11; // edi
  UFG::qResourceInventory *v12; // rax
  UFG::qResourceWarehouse *v13; // rax
  Illusion::Primitive *v14; // rdi
  unsigned int v15; // er15
  char *v16; // rax
  const void *v17; // rsi
  UFG::qMatrix44 *v18; // rsi
  unsigned __int16 v19; // ax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v20; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v21; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v22; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v23; // rax
  unsigned __int16 v24; // ax
  __int64 v25; // rcx
  bool *v26; // rax
  unsigned __int64 *v27; // rdx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v28; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v29; // rax
  __int64 v30; // rcx
  bool *v31; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v32; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v33; // rax
  Render::cbScreenProjectionState arg; // [rsp+10h] [rbp-59h]
  bool dupe_vertex_buffer[8]; // [rsp+38h] [rbp-31h]
  bool *v36; // [rsp+40h] [rbp-29h]
  __int64 v37; // [rsp+48h] [rbp-21h]
  unsigned __int16 v38; // [rsp+50h] [rbp-19h]
  __int16 v39; // [rsp+52h] [rbp-17h]
  UFG::qMatrix44 *v40; // [rsp+58h] [rbp-11h]
  UFG::qMatrix44 *v41; // [rsp+60h] [rbp-9h]
  __int64 v42; // [rsp+68h] [rbp-1h]
  Illusion::StateValues *v43; // [rsp+B8h] [rbp+4Fh]
  Illusion::Primitive::Type prim_type; // [rsp+C0h] [rbp+57h]
  int num_verticesa; // [rsp+D0h] [rbp+67h]
  Illusion::Material *v46; // [rsp+D8h] [rbp+6Fh]
  UFG::qMatrix44 *vars0; // [rsp+E0h] [rbp+77h]
  void (__fastcall *retaddr)(Illusion::Material *, Render::View *, signed __int64, Illusion::Primitive *, Illusion::StateArgs *); // [rsp+E8h] [rbp+7Fh]

  v4 = num_vertices;
  v5 = vertices;
  v6 = this;
  v7 = this->mSubmitContext;
  v8 = (signed __int64)&v7->mStateValues;
  v43 = &v7->mStateValues;
  v9 = &v7->mStateArgs;
  v10 = v46;
  if ( !v46 )
    v10 = `anonymous namespace::gSimpleMaterial;
  if ( !(_S7 & 1) )
  {
    _S7 |= 1u;
    UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&vertex_decl_handle_0.mPrev);
    atexit(Render::View::DrawDebugPrim_::_4_::_dynamic_atexit_destructor_for__vertex_decl_handle__);
  }
  if ( !vertex_decl_handle_0.mData )
  {
    v11 = UFG::qStringHash32("VertexDecl.Dynamic", 0xFFFFFFFF);
    v12 = `UFG::qGetResourceInventory<Illusion::VertexDecl>::`2::result;
    if ( !`UFG::qGetResourceInventory<Illusion::VertexDecl>::`2::result )
    {
      v13 = UFG::qResourceWarehouse::Instance();
      v12 = UFG::qResourceWarehouse::GetInventory(v13, 0x3E5FDA3Eu);
      `UFG::qGetResourceInventory<Illusion::VertexDecl>::`2::result = v12;
    }
    UFG::qResourceHandle::Init((UFG::qResourceHandle *)&vertex_decl_handle_0.mPrev, 0x3E5FDA3Eu, v11, v12);
  }
  v14 = Illusion::Primitive::Create("DrawDebugPrim");
  if ( v14 && v5 )
  {
    if ( UFG::qLinearAllocator::InFrame(Illusion::gEngine.FrameMemory, v5) )
    {
      v17 = v5;
    }
    else
    {
      v15 = 48 * v4;
      v16 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 48 * v4, 0x10u);
      v17 = v16;
      if ( !v16 )
        return;
      UFG::qMemCopy(v16, v5, v15);
      v8 = (signed __int64)v43;
    }
    if ( Illusion::Primitive::SetBuffers(
           v14,
           prim_type,
           v17,
           num_verticesa,
           (Illusion::VertexDecl *)vertex_decl_handle_0.mData,
           0i64,
           0,
           1) )
    {
      v18 = vars0;
      if ( vars0 )
      {
        Render::cbLocalTransformState::cbLocalTransformState(
          (Render::cbLocalTransformState *)&arg,
          &v6->mSettings->mWorldView,
          &v6->mWorldViewProjection,
          vars0);
        *(_QWORD *)dupe_vertex_buffer = dupe_vertex_buffer;
        v36 = dupe_vertex_buffer;
        v37 = 0i64;
        v38 = Render::cbLocalProjectionState::sStateParamIndex;
        v39 = 1;
        if ( (_WORD)Render::cbLocalProjectionState::sStateParamIndex == -1 )
        {
          v24 = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbLocalProjection");
          Render::cbLocalProjectionState::sStateParamIndex = v24;
          v38 = v24;
        }
        v42 = 0i64;
        v40 = &v6->mWorldViewProjection;
        v41 = v18;
        Illusion::StateArgs::Set<Render::cbLocalTransformState>(v9, (Render::cbLocalTransformState *)&arg);
        Illusion::StateArgs::Set<Render::cbLocalProjectionState>(
          v9,
          (Render::cbLocalProjectionState *)dupe_vertex_buffer);
        if ( retaddr )
          retaddr(v10, v6, v8, v14, v9);
        Illusion::SubmitContext::Draw(v6->mSubmitContext, v14, v10);
        v25 = *(_QWORD *)dupe_vertex_buffer;
        v26 = v36;
        *(_QWORD *)(*(_QWORD *)dupe_vertex_buffer + 8i64) = v36;
        *(_QWORD *)v26 = v25;
        *(_QWORD *)dupe_vertex_buffer = dupe_vertex_buffer;
        v36 = dupe_vertex_buffer;
        HIBYTE(v39) = 0;
        if ( (Illusion::StateArgs *)v9->mStateArgsCreateMask.mFlags[2 * ((signed __int16)v38 + 3i64) + 1] == (Illusion::StateArgs *)((char *)v9 + 16 * ((signed __int16)v38 + 3i64)) )
        {
          v27 = &v9->mStateArgsCreateMask.mFlags[(unsigned int)(signed __int16)v38 >> 6];
          *v27 &= ~(1i64 << (v38 & 0x3F));
        }
        v28 = arg.mPrev;
        v29 = arg.mNext;
        arg.mPrev->mNext = arg.mNext;
        v29->mPrev = v28;
        arg.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
        arg.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
        arg.mIsSet = 0;
        if ( (Illusion::StateArgs *)v9->mStateArgsCreateMask.mFlags[2 * (arg.mStateParamIndex + 3i64) + 1] == (Illusion::StateArgs *)((char *)v9 + 16 * (arg.mStateParamIndex + 3i64)) )
          v9->mStateArgsCreateMask.mFlags[(unsigned int)arg.mStateParamIndex >> 6] &= ~(1i64 << (arg.mStateParamIndex & 0x3F));
        v30 = *(_QWORD *)dupe_vertex_buffer;
        v31 = v36;
        *(_QWORD *)(*(_QWORD *)dupe_vertex_buffer + 8i64) = v36;
        *(_QWORD *)v31 = v30;
        v32 = arg.mPrev;
        v33 = arg.mNext;
        arg.mPrev->mNext = arg.mNext;
        v33->mPrev = v32;
      }
      else
      {
        arg.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
        arg.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
        arg.mCallback = 0i64;
        arg.mStateParamIndex = Render::cbScreenProjectionState::sStateParamIndex;
        *(_WORD *)&arg.mFlags = 1;
        if ( (_WORD)Render::cbScreenProjectionState::sStateParamIndex == -1 )
        {
          v19 = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbLocalTransform");
          Render::cbScreenProjectionState::sStateParamIndex = v19;
          arg.mStateParamIndex = v19;
        }
        Illusion::StateArgs::Set<Render::cbScreenProjectionState>(v9, &arg);
        if ( retaddr )
        {
          arg.mCallback = (void (__fastcall *)(Illusion::StateArg *, Illusion::StateValues *))v9;
          ((void (__fastcall *)(Illusion::Material *, Render::View *, signed __int64, Illusion::Primitive *))retaddr)(
            v10,
            v6,
            v8,
            v14);
        }
        Illusion::SubmitContext::Draw(v6->mSubmitContext, v14, v10);
        v20 = arg.mPrev;
        v21 = arg.mNext;
        arg.mPrev->mNext = arg.mNext;
        v21->mPrev = v20;
        arg.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
        arg.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
        arg.mIsSet = 0;
        if ( (Illusion::StateArgs *)v9->mStateArgsCreateMask.mFlags[2 * (arg.mStateParamIndex + 3i64) + 1] == (Illusion::StateArgs *)((char *)v9 + 16 * (arg.mStateParamIndex + 3i64)) )
          v9->mStateArgsCreateMask.mFlags[(unsigned int)arg.mStateParamIndex >> 6] &= ~(1i64 << (arg.mStateParamIndex & 0x3F));
        v22 = arg.mPrev;
        v23 = arg.mNext;
        arg.mPrev->mNext = arg.mNext;
        v23->mPrev = v22;
        arg.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
      }
    }
  }
}

// File Line: 3058
// RVA: 0x10E70
void __fastcall Render::View::DrawDebugPrimAABB(Render::View *this, UFG::qVector3 *min, UFG::qVector3 *max, UFG::qColour *colour)
{
  Render::View *v4; // r14
  UFG::qVector3 *v5; // rdi
  UFG::qVector3 *v6; // rbx
  UFG::qColour *v7; // rsi
  char *v8; // rbp
  float v9; // xmm1_4
  float v10; // xmm0_4
  float v11; // xmm1_4
  float v12; // xmm0_4
  float v13; // xmm1_4
  float v14; // xmm0_4
  float v15; // xmm0_4
  float v16; // xmm1_4
  float v17; // xmm0_4
  float v18; // xmm1_4
  float v19; // xmm0_4
  float v20; // xmm1_4
  float v21; // xmm0_4
  float v22; // xmm1_4
  float v23; // xmm0_4
  float v24; // xmm1_4
  float v25; // xmm0_4
  float v26; // xmm3_4
  float v27; // xmm2_4
  float v28; // xmm0_4
  float v29; // xmm2_4
  float v30; // xmm0_4
  float v31; // xmm2_4
  float v32; // xmm0_4
  float v33; // xmm1_4
  float v34; // xmm2_4
  float v35; // xmm1_4
  float v36; // xmm2_4
  float v37; // xmm1_4
  float v38; // xmm2_4
  float v39; // xmm1_4
  float v40; // xmm2_4
  float v41; // xmm1_4
  float v42; // xmm2_4
  float v43; // xmm1_4
  float v44; // xmm2_4
  float v45; // xmm2_4
  float v46; // xmm1_4
  float v47; // xmm2_4
  float v48; // xmm1_4
  float v49; // xmm1_4
  float v50; // xmm2_4
  float v51; // xmm1_4
  float v52; // xmm2_4
  float v53; // xmm1_4
  float v54; // xmm2_4
  float v55; // xmm1_4
  float v56; // xmm2_4
  signed __int64 v57; // r8
  int v58; // ebx
  signed __int64 v59; // r11
  unsigned int v60; // edx
  unsigned int v62; // edx
  Illusion::Material *v64; // rbx
  _WORD *v65; // rdi
  __int64 v66; // rax
  _WORD *v67; // rax
  __int64 v68; // rax
  _WORD *v69; // rax
  __int64 v70; // rax
  _WORD *v71; // rax
  __int64 v72; // rax

  v4 = this;
  v5 = max;
  v6 = min;
  v7 = colour;
  v8 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x480u, 0x10u);
  v9 = v6->y;
  v10 = v6->z;
  *(float *)v8 = v6->x;
  *((float *)v8 + 1) = v9;
  *((float *)v8 + 2) = v10;
  v11 = v6->y;
  v12 = v6->z;
  *((_DWORD *)v8 + 12) = LODWORD(v5->x);
  *((float *)v8 + 13) = v11;
  *((float *)v8 + 14) = v12;
  v13 = v6->y;
  v14 = v6->z;
  *((_DWORD *)v8 + 24) = LODWORD(v5->x);
  *((float *)v8 + 25) = v13;
  *((float *)v8 + 26) = v14;
  v15 = v5->y;
  v16 = v6->z;
  *((_DWORD *)v8 + 36) = LODWORD(v5->x);
  *((float *)v8 + 37) = v15;
  *((float *)v8 + 38) = v16;
  v17 = v5->y;
  v18 = v6->z;
  *((_DWORD *)v8 + 48) = LODWORD(v5->x);
  *((float *)v8 + 49) = v17;
  *((float *)v8 + 50) = v18;
  v19 = v5->y;
  v20 = v6->z;
  *((_DWORD *)v8 + 60) = LODWORD(v6->x);
  *((float *)v8 + 61) = v19;
  *((float *)v8 + 62) = v20;
  v21 = v5->y;
  v22 = v6->z;
  *((_DWORD *)v8 + 72) = LODWORD(v6->x);
  *((float *)v8 + 73) = v21;
  *((float *)v8 + 74) = v22;
  v23 = v6->y;
  v24 = v6->z;
  *((_DWORD *)v8 + 84) = LODWORD(v6->x);
  *((float *)v8 + 85) = v23;
  *((float *)v8 + 86) = v24;
  v25 = v5->z;
  v26 = v6->y;
  *((_DWORD *)v8 + 96) = LODWORD(v6->x);
  *((float *)v8 + 97) = v26;
  *((float *)v8 + 98) = v25;
  v27 = v6->y;
  v28 = v5->z;
  *((_DWORD *)v8 + 108) = LODWORD(v5->x);
  *((float *)v8 + 109) = v27;
  *((float *)v8 + 110) = v28;
  v29 = v6->y;
  v30 = v5->z;
  *((_DWORD *)v8 + 120) = LODWORD(v5->x);
  *((float *)v8 + 121) = v29;
  *((float *)v8 + 122) = v30;
  v31 = v5->y;
  v32 = v5->z;
  *((_DWORD *)v8 + 132) = LODWORD(v5->x);
  *((float *)v8 + 133) = v31;
  *((float *)v8 + 134) = v32;
  v33 = v5->x;
  v34 = v5->y;
  *((_DWORD *)v8 + 146) = LODWORD(v5->z);
  *((float *)v8 + 144) = v33;
  *((float *)v8 + 145) = v34;
  v35 = v6->x;
  v36 = v5->y;
  *((_DWORD *)v8 + 158) = LODWORD(v5->z);
  *((float *)v8 + 156) = v35;
  *((float *)v8 + 157) = v36;
  v37 = v6->x;
  v38 = v5->y;
  *((_DWORD *)v8 + 170) = LODWORD(v5->z);
  *((float *)v8 + 168) = v37;
  *((float *)v8 + 169) = v38;
  v39 = v6->x;
  v40 = v6->y;
  *((_DWORD *)v8 + 182) = LODWORD(v5->z);
  *((float *)v8 + 180) = v39;
  *((float *)v8 + 181) = v40;
  v41 = v6->x;
  v42 = v6->y;
  *((_DWORD *)v8 + 194) = LODWORD(v6->z);
  *((float *)v8 + 192) = v41;
  *((float *)v8 + 193) = v42;
  v43 = v6->x;
  v44 = v6->y;
  *((_DWORD *)v8 + 206) = LODWORD(v5->z);
  *((float *)v8 + 204) = v43;
  *((float *)v8 + 205) = v44;
  v45 = v6->y;
  v46 = v5->x;
  *((_DWORD *)v8 + 218) = LODWORD(v6->z);
  *((float *)v8 + 216) = v46;
  *((float *)v8 + 217) = v45;
  v47 = v6->y;
  v48 = v5->x;
  *((_DWORD *)v8 + 230) = LODWORD(v5->z);
  *((float *)v8 + 228) = v48;
  *((float *)v8 + 229) = v47;
  v49 = v5->x;
  v50 = v5->y;
  *((_DWORD *)v8 + 242) = LODWORD(v6->z);
  *((float *)v8 + 240) = v49;
  *((float *)v8 + 241) = v50;
  v51 = v5->x;
  v52 = v5->y;
  *((_DWORD *)v8 + 254) = LODWORD(v5->z);
  *((float *)v8 + 252) = v51;
  *((float *)v8 + 253) = v52;
  v53 = v6->x;
  v54 = v5->y;
  *((_DWORD *)v8 + 266) = LODWORD(v6->z);
  *((float *)v8 + 264) = v53;
  *((float *)v8 + 265) = v54;
  v55 = v6->x;
  v56 = v5->y;
  *((_DWORD *)v8 + 278) = LODWORD(v5->z);
  *((float *)v8 + 276) = v55;
  *((float *)v8 + 277) = v56;
  v57 = (signed __int64)(v8 + 12);
  v58 = (signed int)(float)(v7->r * 255.0) | (((signed int)(float)(v7->g * 255.0) | (((signed int)(float)(v7->b * 255.0) | ((signed int)(float)(v7->a * 255.0) << 8)) << 8)) << 8);
  v59 = 24i64;
  do
  {
    *(_DWORD *)(v57 + 32) = v58;
    v60 = 0;
    *(_WORD *)v57 = (v60 + ((v60 >> 13) & 1) + 4095) >> 13;
    v62 = 0;
    *(_WORD *)(v57 + 2) = (v62 + ((v62 >> 13) & 1) + 4095) >> 13;
    v57 += 48i64;
    --v59;
  }
  while ( v59 );
  v64 = `anonymous namespace::gSimpleMaterial;
  v65 = 0i64;
  if ( LODWORD(`anonymous namespace::gSimpleMaterial[1].mStateBlockMask.mFlags[0]) != -1324127765 )
  {
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)&`anonymous namespace::gSimpleMaterial[1].mDebugName[20],
      `anonymous namespace::gSimpleMaterial[1].mStateBlockMask.mFlags[1],
      0xB11369EB);
    v66 = v64->mMaterialUser.mOffset;
    if ( v66 )
      v67 = (_WORD *)((char *)&v64->mMaterialUser + v66);
    else
      v67 = 0i64;
    *v67 |= 0x20u;
  }
  if ( LODWORD(v64[1].mResourceHandles.mNode.mNext) == 26403030 && LODWORD(v64[3].mNode.mChild[0]) != 685899938 )
  {
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)&v64[2].mNumParams,
      (unsigned int)v64[3].mNode.mChild[1],
      0x28E200A2u);
    v68 = v64->mMaterialUser.mOffset;
    if ( v68 )
      v69 = (_WORD *)((char *)&v64->mMaterialUser + v68);
    else
      v69 = 0i64;
    *v69 |= 0x20u;
  }
  if ( *(_DWORD *)&v64[2].mDebugName[28] != 543723269 )
  {
    UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v64[2].mDebugName[4], *((_DWORD *)&v64[2].0 + 22), 0x20688F05u);
    v70 = v64->mMaterialUser.mOffset;
    if ( v70 )
      v71 = (_WORD *)((char *)&v64->mMaterialUser + v70);
    else
      v71 = 0i64;
    *v71 |= 0x20u;
  }
  if ( v64[2].mNode.mUID != 662883558 )
  {
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)&v64[2],
      (unsigned int)v64[2].mResourceHandles.mNode.mPrev,
      0x2782CCE6u);
    v72 = v64->mMaterialUser.mOffset;
    if ( v72 )
      v65 = (_WORD *)((char *)&v64->mMaterialUser + v72);
    *v65 |= 0x20u;
  }
  Render::View::DrawDebugPrim(v4, DebugPrim_LineSegment, (Render::vDynamic *)v8, 24);
}

// File Line: 3093
// RVA: 0x11970
void __fastcall Render::View::DrawDebugPrimCylinder(Render::View *this, UFG::qVector3 *min, UFG::qVector3 *max, const float radius)
{
  UFG::qVector3 *v4; // rdi
  UFG::qVector3 *v5; // rbx
  char *v6; // r15
  char *v7; // rsi
  char *v8; // r8
  __int128 v9; // xmm5
  float v10; // xmm3_4
  float v11; // xmm10_4
  float v12; // xmm10_4
  __m128 v13; // xmm2
  __m128 v14; // xmm6
  float v15; // xmm7_4
  float v16; // xmm8_4
  float v17; // xmm7_4
  float v18; // xmm8_4
  float v19; // xmm2_4
  float v20; // xmm2_4
  float v21; // xmm3_4
  float v22; // xmm5_4
  int v23; // xmm2_4
  int v24; // xmm5_4
  int v25; // xmm3_4
  __m128 v26; // xmm10
  float v27; // xmm11_4
  float v28; // xmm0_4
  float v29; // xmm3_4
  float v30; // xmm5_4
  float v31; // xmm12_4
  float v32; // xmm13_4
  __m128 v33; // xmm2
  float v34; // xmm14_4
  float v35; // xmm15_4
  float v36; // xmm10_4
  float v37; // xmm14_4
  float v38; // xmm2_4
  float v39; // xmm9_4
  __m128 v40; // xmm2
  float v41; // xmm0_4
  signed int v42; // er12
  float v43; // xmm0_4
  int v44; // er12
  signed int v45; // eax
  float v46; // xmm0_4
  int v47; // ecx
  int v48; // er12
  __m128 v49; // xmm8
  float v50; // xmm13_4
  float v51; // xmm14_4
  float v52; // xmm15_4
  signed __int64 v53; // rbx
  signed __int64 v54; // rsi
  signed __int64 v55; // rdi
  signed __int64 v56; // r15
  float v57; // xmm6_4
  float v58; // xmm0_4
  float v59; // xmm0_4
  __m128 v60; // xmm9
  __m128 v61; // xmm8
  __m128 v62; // xmm7
  __m128 v63; // xmm11
  __m128 v64; // xmm1
  unsigned int v65; // edx
  unsigned int v66; // eax
  unsigned int v67; // edx
  unsigned int v68; // edx
  unsigned int v69; // eax
  unsigned int v70; // edx
  float v71; // xmm1_4
  unsigned int v72; // edx
  __m128 v73; // xmm1
  __int16 v74; // ax
  unsigned int v75; // edx
  unsigned int v76; // edx
  signed __int16 v77; // ax
  unsigned int v78; // edx
  UFG::qVector3 *v79; // rdx
  unsigned int v80; // edx
  __m128 v81; // xmm1
  signed __int16 v82; // ax
  unsigned int v83; // edx
  unsigned int v84; // edx
  signed __int16 v85; // ax
  unsigned int v86; // edx
  int v87; // xmm0_4
  int v88; // xmm1_4
  float v89; // ecx
  __int16 v90; // ax
  int v91; // xmm0_4
  int v92; // xmm1_4
  int v93; // xmm2_4
  int v94; // xmm0_4
  int v95; // xmm0_4
  int v96; // xmm1_4
  int v97; // xmm0_4
  int v98; // xmm1_4
  int v99; // xmm2_4
  int v100; // xmm0_4
  Illusion::Material *v101; // rbx
  _WORD *v102; // r14
  __int64 v103; // rax
  _WORD *v104; // rax
  __int64 v105; // rax
  _WORD *v106; // rax
  __int64 v107; // rax
  _WORD *v108; // rax
  __int64 v109; // rax
  _WORD *v110; // rax
  void (__fastcall *v111)(Illusion::Material *, Render::View *, Illusion::StateValues *, Illusion::Primitive *, Illusion::StateArgs *); // rdi
  Render::View *v112; // r15
  Illusion::Material *v113; // rbx
  __int64 v114; // rax
  _WORD *v115; // rax
  __int64 v116; // rax
  _WORD *v117; // rax
  __int64 v118; // rax
  _WORD *v119; // rax
  __int64 v120; // rax
  _WORD *v121; // rax
  Illusion::Material *v122; // rbx
  __int64 v123; // rax
  _WORD *v124; // rax
  __int64 v125; // rax
  _WORD *v126; // rax
  __int64 v127; // rax
  _WORD *v128; // rax
  __int64 v129; // rax
  _WORD *v130; // rax
  Illusion::Material *v131; // rbx
  __int64 v132; // rax
  _WORD *v133; // rax
  __int64 v134; // rax
  _WORD *v135; // rax
  __int64 v136; // rax
  _WORD *v137; // rax
  __int64 v138; // rax
  Render::vDynamic *vertices; // [rsp+40h] [rbp-80h]
  char *v140; // [rsp+48h] [rbp-78h]
  UFG::qVector3 v141; // [rsp+50h] [rbp-70h]
  UFG::qVector3 offset; // [rsp+5Ch] [rbp-64h]
  unsigned int v143; // [rsp+68h] [rbp-58h]
  float v144; // [rsp+6Ch] [rbp-54h]
  __m128 v145; // [rsp+70h] [rbp-50h]
  __m128 v146; // [rsp+80h] [rbp-40h]
  __m128 v147; // [rsp+90h] [rbp-30h]
  Render::vDynamic *v148; // [rsp+B0h] [rbp-10h]
  Render::vDynamic *v149; // [rsp+B8h] [rbp-8h]
  UFG::qMatrix44 v150; // [rsp+C0h] [rbp+0h]
  __m128 v151; // [rsp+100h] [rbp+40h]
  __m128 v152; // [rsp+110h] [rbp+50h]
  __m128 v153; // [rsp+120h] [rbp+60h]
  __m128 v154; // [rsp+130h] [rbp+70h]
  UFG::qMatrix44 dest; // [rsp+150h] [rbp+90h]
  Render::View *v156; // [rsp+280h] [rbp+1C0h]
  UFG::qVector3 *v157; // [rsp+288h] [rbp+1C8h]
  UFG::qVector3 *v158; // [rsp+290h] [rbp+1D0h]
  float v159; // [rsp+298h] [rbp+1D8h]
  float *v160; // [rsp+2A0h] [rbp+1E0h]
  void (__fastcall *vars0)(Illusion::Material *, Render::View *, Illusion::StateValues *, Illusion::Primitive *, Illusion::StateArgs *); // [rsp+2B0h] [rbp+1F0h]

  v4 = max;
  v5 = min;
  v6 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x3F0u, 0x10u);
  HIDWORD(vertices) = HIDWORD(v6);
  v140 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x3F0u, 0x10u);
  v7 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x3F0u, 0x10u);
  v148 = (Render::vDynamic *)v7;
  v8 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x7E0u, 0x10u);
  v149 = (Render::vDynamic *)v8;
  v9 = LODWORD(v4->y);
  *(float *)&v9 = (float)(*(float *)&v9 - v5->y) * 0.5;
  v10 = (float)(v4->x - v5->x) * 0.5;
  v13 = (__m128)v9;
  v11 = v4->z - v5->z;
  v145.m128_f32[0] = v10;
  v12 = v11 * 0.5;
  LODWORD(offset.x) = v9;
  v144 = v12;
  v13.m128_f32[0] = (float)((float)(*(float *)&v9 * *(float *)&v9) + (float)(v10 * v10)) + (float)(v12 * v12);
  if ( v13.m128_f32[0] == 0.0 )
  {
    v14 = 0i64;
  }
  else
  {
    v14 = (__m128)(unsigned int)FLOAT_1_0;
    v14.m128_f32[0] = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v13));
  }
  v15 = v14.m128_f32[0];
  v16 = v14.m128_f32[0];
  v14.m128_f32[0] = v14.m128_f32[0] * v12;
  v17 = v15 * *(float *)&v9;
  v18 = v16 * v10;
  v19 = v14.m128_f32[0] * 0.0;
  if ( COERCE_FLOAT(LODWORD(v17) & _xmm) >= COERCE_FLOAT(v14.m128_i32[0] & _xmm) )
  {
    v22 = v17 - v19;
    v20 = v19 - v18;
    v21 = (float)(v18 * 0.0) - (float)(v17 * 0.0);
  }
  else
  {
    v20 = v19 - (float)(v18 * 0.0);
    v21 = v18 - (float)(v17 * 0.0);
    v22 = (float)(v17 * 0.0) - v14.m128_f32[0];
  }
  v26 = v14;
  v23 = LODWORD(v20) ^ _xmm[0];
  v24 = LODWORD(v22) ^ _xmm[0];
  v25 = LODWORD(v21) ^ _xmm[0];
  v26.m128_f32[0] = (float)(v14.m128_f32[0] * *(float *)&v23) - (float)(v17 * *(float *)&v25);
  v27 = (float)(v18 * *(float *)&v25) - (float)(v14.m128_f32[0] * *(float *)&v24);
  v28 = v18 * *(float *)&v23;
  v33 = v26;
  v29 = (float)(v17 * *(float *)&v24) - v28;
  LODWORD(v30) = COERCE_UNSIGNED_INT((float)(v17 * v29) - (float)(v14.m128_f32[0] * v27)) ^ _xmm[0];
  LODWORD(v31) = COERCE_UNSIGNED_INT((float)(v14.m128_f32[0] * v26.m128_f32[0]) - (float)(v18 * v29)) ^ _xmm[0];
  LODWORD(v32) = COERCE_UNSIGNED_INT((float)(v18 * v27) - (float)(v17 * v26.m128_f32[0])) ^ _xmm[0];
  v33.m128_f32[0] = (float)((float)(v26.m128_f32[0] * v26.m128_f32[0]) + (float)(v27 * v27)) + (float)(v29 * v29);
  if ( v33.m128_f32[0] == 0.0 )
    v34 = 0.0;
  else
    v34 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v33));
  v35 = v34 * v26.m128_f32[0];
  v36 = v34 * v27;
  v37 = v34 * v29;
  v38 = (float)((float)(v30 * v30) + (float)(v31 * v31)) + (float)(v32 * v32);
  if ( v38 == 0.0 )
    v39 = 0.0;
  else
    v39 = 1.0 / fsqrt(v38);
  v40 = 0i64;
  v40.m128_f32[0] = (float)1;
  v145 = v40;
  v145.m128_f32[0] = v39 * v30;
  v145.m128_f32[1] = v39 * v31;
  v146 = _mm_shuffle_ps(v40, v40, 81);
  v41 = v160[3];
  v147 = _mm_shuffle_ps(v40, v40, 69);
  v151 = _mm_shuffle_ps(v40, v40, 21);
  v147.m128_u64[0] = __PAIR__(LODWORD(v17), LODWORD(v18));
  v145.m128_u64[1] = COERCE_UNSIGNED_INT(v39 * v32);
  v42 = (signed int)(float)(v41 * 255.0);
  v43 = v160[2];
  v146.m128_u64[0] = __PAIR__(LODWORD(v36), LODWORD(v35));
  v44 = ((signed int)(float)(v43 * 255.0) | (v42 << 8)) << 8;
  v45 = (signed int)(float)(v160[1] * 255.0);
  v46 = *v160;
  v146.m128_u64[1] = LODWORD(v37);
  v47 = 0;
  v141.x = 0.0;
  v147.m128_u64[1] = v14.m128_u32[0];
  v48 = (signed int)(float)(v46 * 255.0) | ((v45 | v44) << 8);
  *(unsigned __int64 *)((char *)v145.m128_u64 + 4) = 0i64;
  v49 = v151;
  offset.z = 0.0;
  v141.z = 0.0;
  offset.y = 0.0;
  LODWORD(v160) = 0;
  v50 = v39 * v30;
  v51 = offset.x;
  v52 = v144;
  v143 = 0;
  v53 = (signed __int64)(v6 + 28);
  v54 = v7 - v6;
  LODWORD(vertices) = 0;
  v55 = (signed __int64)(v8 + 76);
  v141.y = 0.0;
  v56 = v140 - (char *)vertices;
  LODWORD(vertices) = 0;
  do
  {
    v57 = (float)v47 * 0.31415927;
    v58 = cosf(v57);
    offset.x = v58 * v159;
    v59 = sinf(v57);
    offset.z = 0.0;
    offset.y = v59 * v159;
    UFG::qTranslationMatrix(&dest, &offset);
    v60 = _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps((__m128)dest.v0, (__m128)dest.v0, 0), v145), (__m128)0i64),
                _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v0, (__m128)dest.v0, 85), v146)),
              _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v0, (__m128)dest.v0, 170), v147)),
            _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v0, (__m128)dest.v0, 255), v49));
    v61 = _mm_add_ps(
            _mm_mul_ps(v49, _mm_shuffle_ps((__m128)dest.v1, (__m128)dest.v1, 255)),
            _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps((__m128)dest.v1, (__m128)dest.v1, 0), v145), (__m128)0i64),
                _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v1, (__m128)dest.v1, 85), v146)),
              _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v1, (__m128)dest.v1, 170), v147)));
    v62 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(v147, _mm_shuffle_ps((__m128)dest.v2, (__m128)dest.v2, 170)),
              _mm_add_ps(
                _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps((__m128)dest.v2, (__m128)dest.v2, 0), v145), (__m128)0i64),
                _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v2, (__m128)dest.v2, 85), v146))),
            _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v2, (__m128)dest.v2, 255), v151));
    v63 = _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(v146, _mm_shuffle_ps((__m128)dest.v3, (__m128)dest.v3, 85)),
                _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps((__m128)dest.v3, (__m128)dest.v3, 0), v145), (__m128)0i64)),
              _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v3, (__m128)dest.v3, 170), v147)),
            _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v3, (__m128)dest.v3, 255), v151));
    UFG::qTranslationMatrix(&v150, v157);
    v152 = _mm_add_ps(
             _mm_add_ps(
               _mm_add_ps(
                 _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v60, v60, 0), (__m128)v150.v0), (__m128)0i64),
                 _mm_mul_ps(_mm_shuffle_ps(v60, v60, 85), (__m128)v150.v1)),
               _mm_mul_ps(_mm_shuffle_ps(v60, v60, 170), (__m128)v150.v2)),
             _mm_mul_ps(_mm_shuffle_ps(v60, v60, 255), (__m128)v150.v3));
    v153 = _mm_add_ps(
             _mm_add_ps(
               _mm_add_ps(
                 _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v61, v61, 0), (__m128)v150.v0), (__m128)0i64),
                 _mm_mul_ps(_mm_shuffle_ps(v61, v61, 85), (__m128)v150.v1)),
               _mm_mul_ps(_mm_shuffle_ps(v61, v61, 170), (__m128)v150.v2)),
             _mm_mul_ps(_mm_shuffle_ps(v61, v61, 255), (__m128)v150.v3));
    v154 = _mm_add_ps(
             _mm_add_ps(
               _mm_add_ps(
                 _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v62, v62, 0), (__m128)v150.v0), (__m128)0i64),
                 _mm_mul_ps(_mm_shuffle_ps(v62, v62, 85), (__m128)v150.v1)),
               _mm_mul_ps(_mm_shuffle_ps(v62, v62, 170), (__m128)v150.v2)),
             _mm_mul_ps(_mm_shuffle_ps(v62, v62, 255), (__m128)v150.v3));
    v64 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v63, v63, 170), (__m128)v150.v2),
              _mm_add_ps(
                _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v63, v63, 0), (__m128)v150.v0), (__m128)0i64),
                _mm_mul_ps(_mm_shuffle_ps(v63, v63, 85), (__m128)v150.v1))),
            _mm_mul_ps(_mm_shuffle_ps(v63, v63, 255), (__m128)v150.v3));
    *(_DWORD *)(v53 - 28) = v64.m128_i32[0];
    *(_DWORD *)(v53 - 24) = (unsigned __int128)_mm_shuffle_ps(v64, v64, 85);
    v65 = v145.m128_u32[1];
    *(_DWORD *)(v53 - 20) = (unsigned __int128)_mm_shuffle_ps(v64, v64, 170);
    *(_DWORD *)(v53 + 16) = v48;
    if ( v65 <= 0x47FFEFFF )
    {
      if ( v65 >= 0x38800000 )
        v67 = v65 - 939524096;
      else
        v67 = (v65 & 0x7FFFFF | 0x800000) >> (113 - (v65 >> 23));
      v66 = (v67 + ((v67 >> 13) & 1) + 4095) >> 13;
    }
    else
    {
      LOWORD(v66) = 0x7FFF;
    }
    v68 = LODWORD(v141.z);
    *(_WORD *)(v53 - 16) = v66;
    if ( v68 <= 0x47FFEFFF )
    {
      if ( v68 >= 0x38800000 )
        v70 = v68 - 939524096;
      else
        v70 = (v68 & 0x7FFFFF | 0x800000) >> (113 - (v68 >> 23));
      v69 = (v70 + ((v70 >> 13) & 1) + 4095) >> 13;
    }
    else
    {
      LOWORD(v69) = 0x7FFF;
    }
    *(_WORD *)(v53 - 14) = v69;
    v71 = v51 + v157->y;
    v141.x = v50 + v157->x;
    v141.y = v71;
    v141.z = v52 + v157->z;
    UFG::qTranslationMatrix(&v150, &v141);
    v152 = _mm_add_ps(
             _mm_add_ps(
               _mm_add_ps(
                 _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v60, v60, 0), (__m128)v150.v0), (__m128)0i64),
                 _mm_mul_ps(_mm_shuffle_ps(v60, v60, 85), (__m128)v150.v1)),
               _mm_mul_ps(_mm_shuffle_ps(v60, v60, 170), (__m128)v150.v2)),
             _mm_mul_ps(_mm_shuffle_ps(v60, v60, 255), (__m128)v150.v3));
    v153 = _mm_add_ps(
             _mm_add_ps(
               _mm_add_ps(
                 _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v61, v61, 0), (__m128)v150.v0), (__m128)0i64),
                 _mm_mul_ps(_mm_shuffle_ps(v61, v61, 85), (__m128)v150.v1)),
               _mm_mul_ps(_mm_shuffle_ps(v61, v61, 170), (__m128)v150.v2)),
             _mm_mul_ps(_mm_shuffle_ps(v61, v61, 255), (__m128)v150.v3));
    v154 = _mm_add_ps(
             _mm_add_ps(
               _mm_add_ps(
                 _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v62, v62, 0), (__m128)v150.v0), (__m128)0i64),
                 _mm_mul_ps(_mm_shuffle_ps(v62, v62, 85), (__m128)v150.v1)),
               _mm_mul_ps(_mm_shuffle_ps(v62, v62, 170), (__m128)v150.v2)),
             _mm_mul_ps(_mm_shuffle_ps(v62, v62, 255), (__m128)v150.v3));
    v72 = LODWORD(offset.y);
    v73 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v63, v63, 170), (__m128)v150.v2),
              _mm_add_ps(
                _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v63, v63, 0), (__m128)v150.v0), (__m128)0i64),
                _mm_mul_ps(_mm_shuffle_ps(v63, v63, 85), (__m128)v150.v1))),
            _mm_mul_ps(_mm_shuffle_ps(v63, v63, 255), (__m128)v150.v3));
    *(_DWORD *)(v53 + v56 - 28) = v73.m128_i32[0];
    *(_DWORD *)(v53 + v56 - 20) = (unsigned __int128)_mm_shuffle_ps(v73, v73, 170);
    *(_DWORD *)(v53 + v56 - 24) = (unsigned __int128)_mm_shuffle_ps(v73, v73, 85);
    *(_DWORD *)(v53 + v56 + 16) = v48;
    if ( v72 <= 0x47FFEFFF )
    {
      if ( v72 >= 0x38800000 )
        v75 = v72 - 939524096;
      else
        v75 = (v72 & 0x7FFFFF | 0x800000) >> (113 - (v72 >> 23));
      v74 = (unsigned __int16)v160 | ((v75 + ((v75 >> 13) & 1) + 4095) >> 13);
    }
    else
    {
      v74 = (unsigned __int16)v160 | 0x7FFF;
    }
    v76 = v143;
    *(_WORD *)(v53 + v56 - 16) = v74;
    if ( v76 <= 0x47FFEFFF )
    {
      if ( v76 >= 0x38800000 )
        v78 = v76 - 939524096;
      else
        v78 = (v76 & 0x7FFFFF | 0x800000) >> (113 - (v76 >> 23));
      v77 = (v78 + ((v78 >> 13) & 1) + 4095) >> 13;
    }
    else
    {
      v77 = 0x7FFF;
    }
    v79 = v158;
    *(_WORD *)(v53 + v56 - 14) = v77;
    UFG::qTranslationMatrix(&v150, v79);
    v80 = LODWORD(v141.y);
    v152 = _mm_add_ps(
             _mm_add_ps(
               _mm_add_ps(
                 _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v60, v60, 0), (__m128)v150.v0), (__m128)0i64),
                 _mm_mul_ps(_mm_shuffle_ps(v60, v60, 85), (__m128)v150.v1)),
               _mm_mul_ps(_mm_shuffle_ps(v60, v60, 170), (__m128)v150.v2)),
             _mm_mul_ps(_mm_shuffle_ps(v60, v60, 255), (__m128)v150.v3));
    v153 = _mm_add_ps(
             _mm_add_ps(
               _mm_add_ps(
                 _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v61, v61, 0), (__m128)v150.v0), (__m128)0i64),
                 _mm_mul_ps(_mm_shuffle_ps(v61, v61, 85), (__m128)v150.v1)),
               _mm_mul_ps(_mm_shuffle_ps(v61, v61, 170), (__m128)v150.v2)),
             _mm_mul_ps(_mm_shuffle_ps(v61, v61, 255), (__m128)v150.v3));
    v81 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v63, v63, 170), (__m128)v150.v2),
              _mm_add_ps(
                _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v63, v63, 0), (__m128)v150.v0), (__m128)0i64),
                _mm_mul_ps(_mm_shuffle_ps(v63, v63, 85), (__m128)v150.v1))),
            _mm_mul_ps(_mm_shuffle_ps(v63, v63, 255), (__m128)v150.v3));
    v154 = _mm_add_ps(
             _mm_add_ps(
               _mm_add_ps(
                 _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v62, v62, 0), (__m128)v150.v0), (__m128)0i64),
                 _mm_mul_ps(_mm_shuffle_ps(v62, v62, 85), (__m128)v150.v1)),
               _mm_mul_ps(_mm_shuffle_ps(v62, v62, 170), (__m128)v150.v2)),
             _mm_mul_ps(_mm_shuffle_ps(v62, v62, 255), (__m128)v150.v3));
    *(_DWORD *)(v53 + v54 - 28) = v81.m128_i32[0];
    *(_DWORD *)(v53 + v54 - 24) = (unsigned __int128)_mm_shuffle_ps(v81, v81, 85);
    *(_DWORD *)(v53 + v54 - 20) = (unsigned __int128)_mm_shuffle_ps(v81, v81, 170);
    *(_DWORD *)(v53 + v54 + 16) = v48;
    if ( v80 <= 0x47FFEFFF )
    {
      if ( v80 >= 0x38800000 )
        v83 = v80 - 939524096;
      else
        v83 = (v80 & 0x7FFFFF | 0x800000) >> (113 - (v80 >> 23));
      v82 = (v83 + ((v83 >> 13) & 1) + 4095) >> 13;
    }
    else
    {
      v82 = 0x7FFF;
    }
    v84 = v145.m128_u32[2];
    *(_WORD *)(v53 + v54 - 16) = v82;
    if ( v84 <= 0x47FFEFFF )
    {
      if ( v84 >= 0x38800000 )
        v86 = v84 - 939524096;
      else
        v86 = (v84 & 0x7FFFFF | 0x800000) >> (113 - (v84 >> 23));
      v85 = (v86 + ((v86 >> 13) & 1) + 4095) >> 13;
    }
    else
    {
      v85 = 0x7FFF;
    }
    *(_WORD *)(v53 + v54 - 14) = v85;
    v87 = *(_DWORD *)(v53 - 24);
    v88 = *(_DWORD *)(v53 - 20);
    *(_DWORD *)(v55 - 76) = *(_DWORD *)(v53 - 28);
    *(_DWORD *)(v55 - 72) = v87;
    v49 = v151;
    v89 = v141.x;
    v53 += 48i64;
    v55 += 96i64;
    *(_DWORD *)(v55 - 164) = v88;
    v47 = LODWORD(v89) + 1;
    *(_WORD *)(v55 - 160) = *(_WORD *)(v53 - 64);
    v90 = *(_WORD *)(v53 - 62);
    LODWORD(v141.x) = v47;
    *(_WORD *)(v55 - 158) = v90;
    *(_WORD *)(v55 - 156) = *(_WORD *)(v53 - 60);
    *(_WORD *)(v55 - 154) = *(_WORD *)(v53 - 58);
    v91 = *(_DWORD *)(v53 - 52);
    v92 = *(_DWORD *)(v53 - 48);
    *(_DWORD *)(v55 - 152) = *(_DWORD *)(v53 - 56);
    *(_DWORD *)(v55 - 148) = v91;
    *(_DWORD *)(v55 - 144) = v92;
    v93 = *(_DWORD *)(v53 - 40);
    v94 = *(_DWORD *)(v53 - 36);
    *(_DWORD *)(v55 - 140) = *(_DWORD *)(v53 - 44);
    *(_DWORD *)(v55 - 136) = v93;
    *(_DWORD *)(v55 - 132) = v94;
    *(_DWORD *)(v55 - 128) = *(_DWORD *)(v53 - 32);
    v95 = *(_DWORD *)(v53 + v54 - 72);
    v96 = *(_DWORD *)(v53 + v54 - 68);
    *(_DWORD *)(v55 - 124) = *(_DWORD *)(v53 + v54 - 76);
    *(_DWORD *)(v55 - 120) = v95;
    *(_DWORD *)(v55 - 116) = v96;
    *(_WORD *)(v55 - 112) = *(_WORD *)(v53 + v54 - 64);
    *(_WORD *)(v55 - 110) = *(_WORD *)(v53 + v54 - 62);
    *(_WORD *)(v55 - 108) = *(_WORD *)(v53 + v54 - 60);
    *(_WORD *)(v55 - 106) = *(_WORD *)(v53 + v54 - 58);
    v97 = *(_DWORD *)(v53 + v54 - 52);
    v98 = *(_DWORD *)(v53 + v54 - 48);
    *(_DWORD *)(v55 - 104) = *(_DWORD *)(v53 + v54 - 56);
    *(_DWORD *)(v55 - 100) = v97;
    *(_DWORD *)(v55 - 96) = v98;
    v99 = *(_DWORD *)(v53 + v54 - 40);
    v100 = *(_DWORD *)(v53 + v54 - 36);
    *(_DWORD *)(v55 - 92) = *(_DWORD *)(v53 + v54 - 44);
    *(_DWORD *)(v55 - 88) = v99;
    *(_DWORD *)(v55 - 84) = v100;
    *(_DWORD *)(v55 - 80) = *(_DWORD *)(v53 + v54 - 32);
  }
  while ( v47 <= 20 );
  v101 = `anonymous namespace::gSimpleMaterial;
  v102 = 0i64;
  if ( LODWORD(`anonymous namespace::gSimpleMaterial[1].mStateBlockMask.mFlags[0]) != -1324127765 )
  {
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)&`anonymous namespace::gSimpleMaterial[1].mDebugName[20],
      `anonymous namespace::gSimpleMaterial[1].mStateBlockMask.mFlags[1],
      0xB11369EB);
    v103 = v101->mMaterialUser.mOffset;
    if ( v103 )
      v104 = (_WORD *)((char *)&v101->mMaterialUser + v103);
    else
      v104 = 0i64;
    *v104 |= 0x20u;
  }
  if ( LODWORD(v101[1].mResourceHandles.mNode.mNext) == 26403030 && LODWORD(v101[3].mNode.mChild[0]) != 685899938 )
  {
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)&v101[2].mNumParams,
      (unsigned int)v101[3].mNode.mChild[1],
      0x28E200A2u);
    v105 = v101->mMaterialUser.mOffset;
    if ( v105 )
      v106 = (_WORD *)((char *)&v101->mMaterialUser + v105);
    else
      v106 = 0i64;
    *v106 |= 0x20u;
  }
  if ( *(_DWORD *)&v101[2].mDebugName[28] != 543723269 )
  {
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)&v101[2].mDebugName[4],
      *((_DWORD *)&v101[2].0 + 22),
      0x20688F05u);
    v107 = v101->mMaterialUser.mOffset;
    if ( v107 )
      v108 = (_WORD *)((char *)&v101->mMaterialUser + v107);
    else
      v108 = 0i64;
    *v108 |= 0x20u;
  }
  if ( v101[2].mNode.mUID != 662883558 )
  {
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)&v101[2],
      (unsigned int)v101[2].mResourceHandles.mNode.mPrev,
      0x2782CCE6u);
    v109 = v101->mMaterialUser.mOffset;
    if ( v109 )
      v110 = (_WORD *)((char *)&v101->mMaterialUser + v109);
    else
      v110 = 0i64;
    *v110 |= 0x20u;
  }
  v111 = vars0;
  v112 = v156;
  Render::View::DrawDebugPrim(v156, DebugPrim_LineStrip, vertices, 21);
  v113 = `anonymous namespace::gSimpleMaterial;
  if ( LODWORD(`anonymous namespace::gSimpleMaterial[1].mStateBlockMask.mFlags[0]) != -1324127765 )
  {
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)&`anonymous namespace::gSimpleMaterial[1].mDebugName[20],
      `anonymous namespace::gSimpleMaterial[1].mStateBlockMask.mFlags[1],
      0xB11369EB);
    v114 = v113->mMaterialUser.mOffset;
    if ( v114 )
      v115 = (_WORD *)((char *)&v113->mMaterialUser + v114);
    else
      v115 = 0i64;
    *v115 |= 0x20u;
  }
  if ( LODWORD(v113[1].mResourceHandles.mNode.mNext) == 26403030 && LODWORD(v113[3].mNode.mChild[0]) != 685899938 )
  {
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)&v113[2].mNumParams,
      (unsigned int)v113[3].mNode.mChild[1],
      0x28E200A2u);
    v116 = v113->mMaterialUser.mOffset;
    if ( v116 )
      v117 = (_WORD *)((char *)&v113->mMaterialUser + v116);
    else
      v117 = 0i64;
    *v117 |= 0x20u;
  }
  if ( *(_DWORD *)&v113[2].mDebugName[28] != 543723269 )
  {
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)&v113[2].mDebugName[4],
      *((_DWORD *)&v113[2].0 + 22),
      0x20688F05u);
    v118 = v113->mMaterialUser.mOffset;
    if ( v118 )
      v119 = (_WORD *)((char *)&v113->mMaterialUser + v118);
    else
      v119 = 0i64;
    *v119 |= 0x20u;
  }
  if ( v113[2].mNode.mUID != 662883558 )
  {
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)&v113[2],
      (unsigned int)v113[2].mResourceHandles.mNode.mPrev,
      0x2782CCE6u);
    v120 = v113->mMaterialUser.mOffset;
    if ( v120 )
      v121 = (_WORD *)((char *)&v113->mMaterialUser + v120);
    else
      v121 = 0i64;
    *v121 |= 0x20u;
  }
  Render::View::DrawDebugPrim(v112, DebugPrim_LineStrip, 0i64, 21);
  v122 = `anonymous namespace::gSimpleMaterial;
  if ( LODWORD(`anonymous namespace::gSimpleMaterial[1].mStateBlockMask.mFlags[0]) != -1324127765 )
  {
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)&`anonymous namespace::gSimpleMaterial[1].mDebugName[20],
      `anonymous namespace::gSimpleMaterial[1].mStateBlockMask.mFlags[1],
      0xB11369EB);
    v123 = v122->mMaterialUser.mOffset;
    if ( v123 )
      v124 = (_WORD *)((char *)&v122->mMaterialUser + v123);
    else
      v124 = 0i64;
    *v124 |= 0x20u;
  }
  if ( LODWORD(v122[1].mResourceHandles.mNode.mNext) == 26403030 && LODWORD(v122[3].mNode.mChild[0]) != 685899938 )
  {
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)&v122[2].mNumParams,
      (unsigned int)v122[3].mNode.mChild[1],
      0x28E200A2u);
    v125 = v122->mMaterialUser.mOffset;
    if ( v125 )
      v126 = (_WORD *)((char *)&v122->mMaterialUser + v125);
    else
      v126 = 0i64;
    *v126 |= 0x20u;
  }
  if ( *(_DWORD *)&v122[2].mDebugName[28] != 543723269 )
  {
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)&v122[2].mDebugName[4],
      *((_DWORD *)&v122[2].0 + 22),
      0x20688F05u);
    v127 = v122->mMaterialUser.mOffset;
    if ( v127 )
      v128 = (_WORD *)((char *)&v122->mMaterialUser + v127);
    else
      v128 = 0i64;
    *v128 |= 0x20u;
  }
  if ( v122[2].mNode.mUID != 662883558 )
  {
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)&v122[2],
      (unsigned int)v122[2].mResourceHandles.mNode.mPrev,
      0x2782CCE6u);
    v129 = v122->mMaterialUser.mOffset;
    if ( v129 )
      v130 = (_WORD *)((char *)&v122->mMaterialUser + v129);
    else
      v130 = 0i64;
    *v130 |= 0x20u;
  }
  Render::View::DrawDebugPrim(v112, DebugPrim_LineStrip, v148, 21);
  v131 = `anonymous namespace::gSimpleMaterial;
  if ( LODWORD(`anonymous namespace::gSimpleMaterial[1].mStateBlockMask.mFlags[0]) != -1324127765 )
  {
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)&`anonymous namespace::gSimpleMaterial[1].mDebugName[20],
      `anonymous namespace::gSimpleMaterial[1].mStateBlockMask.mFlags[1],
      0xB11369EB);
    v132 = v131->mMaterialUser.mOffset;
    if ( v132 )
      v133 = (_WORD *)((char *)&v131->mMaterialUser + v132);
    else
      v133 = 0i64;
    *v133 |= 0x20u;
  }
  if ( LODWORD(v131[1].mResourceHandles.mNode.mNext) == 26403030 && LODWORD(v131[3].mNode.mChild[0]) != 685899938 )
  {
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)&v131[2].mNumParams,
      (unsigned int)v131[3].mNode.mChild[1],
      0x28E200A2u);
    v134 = v131->mMaterialUser.mOffset;
    if ( v134 )
      v135 = (_WORD *)((char *)&v131->mMaterialUser + v134);
    else
      v135 = 0i64;
    *v135 |= 0x20u;
  }
  if ( *(_DWORD *)&v131[2].mDebugName[28] != 543723269 )
  {
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)&v131[2].mDebugName[4],
      *((_DWORD *)&v131[2].0 + 22),
      0x20688F05u);
    v136 = v131->mMaterialUser.mOffset;
    if ( v136 )
      v137 = (_WORD *)((char *)&v131->mMaterialUser + v136);
    else
      v137 = 0i64;
    *v137 |= 0x20u;
  }
  if ( v131[2].mNode.mUID != 662883558 )
  {
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)&v131[2],
      (unsigned int)v131[2].mResourceHandles.mNode.mPrev,
      0x2782CCE6u);
    v138 = v131->mMaterialUser.mOffset;
    if ( v138 )
      v102 = (_WORD *)((char *)&v131->mMaterialUser + v138);
    *v102 |= 0x20u;
  }
  vars0 = v111;
  Render::View::DrawDebugPrim(v112, DebugPrim_LineStrip, v149, 42);
}

// File Line: 3298
// RVA: 0x12E90
void __fastcall Render::View::DrawDebugPrimSphere(Render::View *this, UFG::qVector3 *centre, const float radius, UFG::qColour *colour, UFG::qMatrix44 *local_world, void (__fastcall *pre_draw_callback)(Illusion::Material *, Render::View *, Illusion::StateValues *, Illusion::Primitive *, Illusion::StateArgs *))
{
  UFG::qVector3 *v6; // r14
  UFG::qColour *v7; // rbx
  float v8; // xmm8_4
  char *v9; // rax
  char *v10; // rdi
  char *v11; // rax
  signed int v12; // ebp
  signed __int64 v13; // rsi
  int v14; // er15
  signed __int64 v15; // rbx
  signed __int64 v16; // rdi
  float v17; // xmm6_4
  float v18; // xmm7_4
  float v19; // xmm0_4
  float v20; // xmm3_4
  float v21; // eax
  float v22; // xmm2_4
  float v23; // xmm2_4
  float v24; // xmm1_4
  float v25; // xmm7_4
  float v26; // xmm0_4
  Render::vDynamic *vertices; // [rsp+70h] [rbp-88h]
  Render::vDynamic *v28; // [rsp+78h] [rbp-80h]
  Render::vDynamic *v29; // [rsp+80h] [rbp-78h]
  Render::View *v30; // [rsp+100h] [rbp+8h]

  v30 = this;
  v6 = centre;
  v7 = colour;
  v8 = radius;
  vertices = (Render::vDynamic *)UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x3F0u, 0x10u);
  v9 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x3F0u, 0x10u);
  v10 = v9;
  v28 = (Render::vDynamic *)v9;
  v11 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x3F0u, 0x10u);
  v29 = (Render::vDynamic *)v11;
  if ( vertices && v10 && v11 )
  {
    v12 = 0;
    v13 = v10 - (char *)vertices;
    v14 = (signed int)(float)(v7->r * 255.0) | (((signed int)(float)(v7->g * 255.0) | (((signed int)(float)(v7->b * 255.0) | ((signed int)(float)(v7->a * 255.0) << 8)) << 8)) << 8);
    v15 = (signed __int64)&vertices->mPosition.z;
    v16 = v11 - (char *)vertices;
    do
    {
      v17 = (float)v12 * 0.31415927;
      v18 = sinf(v17) * v8;
      v19 = cosf(v17);
      *(float *)v15 = v18;
      *(_DWORD *)(v15 - 8) = 0;
      v20 = v19 * v8;
      *(float *)(v15 - 4) = v19 * v8;
      v21 = v6->x;
      v22 = (float)(v19 * v8) + v6->y;
      *(float *)v15 = v18 + v6->z;
      *(float *)(v15 - 8) = v21;
      *(float *)(v15 - 4) = v22;
      *(_DWORD *)(v15 + 36) = v14;
      *(_WORD *)(v15 + 4) = 0;
      *(_WORD *)(v15 + 6) = 0;
      *(float *)(v13 + v15 - 8) = v19 * v8;
      *(float *)(v13 + v15) = v18;
      *(_DWORD *)(v13 + v15 - 4) = 0;
      v23 = v18 + v6->z;
      v24 = v6->y;
      *(float *)(v13 + v15 - 8) = (float)(v19 * v8) + v6->x;
      *(float *)(v13 + v15) = v23;
      *(float *)(v13 + v15 - 4) = v24;
      *(_DWORD *)(v13 + v15 + 36) = v14;
      *(_WORD *)(v13 + v15 + 4) = 0;
      *(_WORD *)(v13 + v15 + 6) = 0;
      *(float *)(v16 + v15 - 8) = v19 * v8;
      *(float *)(v16 + v15 - 4) = v18;
      *(_DWORD *)(v16 + v15) = 0;
      v25 = v18 + v6->y;
      v26 = v6->z;
      *(float *)(v16 + v15 - 8) = v20 + v6->x;
      *(float *)(v16 + v15 - 4) = v25;
      *(float *)(v16 + v15) = v26;
      *(_DWORD *)(v16 + v15 + 36) = v14;
      *(_WORD *)(v16 + v15 + 4) = 0;
      ++v12;
      *(_WORD *)(v16 + v15 + 6) = 0;
      v15 += 48i64;
    }
    while ( v12 <= 20 );
    Render::View::CreateSimpleMaterial(0xB11369EB, 0x20688F05u, 0x2782CCE6u, 0);
    Render::View::DrawDebugPrim(v30, DebugPrim_LineStrip, vertices, 21);
    Render::View::CreateSimpleMaterial(0xB11369EB, 0x20688F05u, 0x2782CCE6u, 0);
    Render::View::DrawDebugPrim(v30, DebugPrim_LineStrip, v28, 21);
    Render::View::CreateSimpleMaterial(0xB11369EB, 0x20688F05u, 0x2782CCE6u, 0);
    Render::View::DrawDebugPrim(v30, DebugPrim_LineStrip, v29, 21);
  }
}

// File Line: 3370
// RVA: 0x134E0
void __fastcall Render::View::DrawDebugPrimTri(Render::View *this, UFG::qVector3 *aVerts, UFG::qColour *colour, UFG::qMatrix44 *local_world)
{
  UFG::qVector3 *v4; // rbx
  Render::View *v5; // r14
  UFG::qColour *v6; // rsi
  char *v7; // rax
  Render::vDynamic *v8; // rdi
  float v9; // xmm6_4
  float v10; // xmm3_4
  float v11; // xmm9_4
  float v12; // xmm10_4
  float v13; // xmm4_4
  float v14; // xmm1_4
  float v15; // xmm2_4
  float v16; // xmm6_4
  float v17; // xmm3_4
  float v18; // xmm7_4
  float v19; // xmm0_4
  float v20; // xmm6_4
  float v21; // xmm2_4
  __m128 v22; // xmm5
  float v23; // xmm6_4
  __m128 v24; // xmm4
  float v25; // xmm7_4
  float v26; // xmm5_4
  float v27; // xmm6_4
  float v28; // xmm0_4
  float v29; // xmm1_4
  float v30; // xmm0_4
  float v31; // xmm1_4

  v4 = aVerts;
  v5 = this;
  v6 = colour;
  v7 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x90u, 0x10u);
  v8 = (Render::vDynamic *)v7;
  v22 = (__m128)LODWORD(v4[1].z);
  v9 = v4[1].x;
  v10 = v4[1].y;
  v11 = v4->y;
  v12 = v4->z;
  v13 = v4[2].x - v9;
  v14 = v4[2].z - v22.m128_f32[0];
  v15 = v4[2].y - v10;
  v22.m128_f32[0] = v22.m128_f32[0] - v12;
  v16 = v9 - v4->x;
  v17 = v10 - v11;
  v18 = (float)(v17 * v14) - (float)(v22.m128_f32[0] * v15);
  v19 = v16 * v14;
  v20 = v16 * v15;
  v21 = 0.0;
  v22.m128_f32[0] = (float)(v22.m128_f32[0] * v13) - v19;
  v23 = v20 - (float)(v17 * v13);
  v24 = v22;
  v24.m128_f32[0] = (float)((float)(v22.m128_f32[0] * v22.m128_f32[0]) + (float)(v18 * v18)) + (float)(v23 * v23);
  if ( v24.m128_f32[0] != 0.0 )
    v21 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v24));
  v25 = v18 * v21;
  v26 = v22.m128_f32[0] * v21;
  v27 = v23 * v21;
  if ( v7 )
  {
    *(float *)v7 = v4->x;
    *((float *)v7 + 1) = v11;
    *((float *)v7 + 2) = v12;
    *((_DWORD *)v7 + 11) = (signed int)(float)(v6->r * 255.0) | (((signed int)(float)(v6->g * 255.0) | (((signed int)(float)(v6->b * 255.0) | ((signed int)(float)(v6->a * 255.0) << 8)) << 8)) << 8);
    *((float *)v7 + 5) = v25;
    *((float *)v7 + 6) = v26;
    *((float *)v7 + 7) = v27;
    v28 = v4[1].y;
    v29 = v4[1].z;
    *((_DWORD *)v7 + 12) = LODWORD(v4[1].x);
    *((float *)v7 + 13) = v28;
    *((float *)v7 + 14) = v29;
    *((_DWORD *)v7 + 23) = (signed int)(float)(v6->r * 255.0) | (((signed int)(float)(v6->g * 255.0) | (((signed int)(float)(v6->b * 255.0) | ((signed int)(float)(v6->a * 255.0) << 8)) << 8)) << 8);
    *((float *)v7 + 17) = v25;
    *((float *)v7 + 18) = v26;
    *((float *)v7 + 19) = v27;
    v30 = v4[2].y;
    v31 = v4[2].z;
    *((_DWORD *)v7 + 24) = LODWORD(v4[2].x);
    *((float *)v7 + 25) = v30;
    *((float *)v7 + 26) = v31;
    *((_DWORD *)v7 + 35) = (signed int)(float)(v6->r * 255.0) | (((signed int)(float)(v6->g * 255.0) | (((signed int)(float)(v6->b * 255.0) | ((signed int)(float)(v6->a * 255.0) << 8)) << 8)) << 8);
    *((float *)v7 + 29) = v25;
    *((float *)v7 + 30) = v26;
    *((float *)v7 + 31) = v27;
    Render::View::CreateSimpleMaterial(0xB11369EB, 0x20688F05u, 0xA3833FDE, 0);
    Render::View::DrawDebugPrim(v5, DebugPrim_Triangle, v8, 3);
  }
}

// File Line: 3422
// RVA: 0x137D0
void __fastcall Render::View::DrawDebugPrimTriStrip(Render::View *this, UFG::qVector3 *points, int num_points, UFG::DrawInfo *info, UFG::qMatrix44 *local_world)
{
  signed __int64 v5; // r14
  Render::View *v6; // r12
  UFG::qVector3 *v7; // r15
  unsigned int v8; // esi
  UFG::DrawInfo *v9; // rdi
  char *v10; // rax
  Render::vDynamic *v11; // rbp
  int v12; // ebx
  signed __int64 v13; // r9
  signed __int64 v14; // rax
  signed __int64 v15; // rcx
  unsigned __int64 v16; // rdx
  int v17; // xmm0_4
  int v18; // xmm1_4
  int v19; // xmm2_4
  int v20; // xmm1_4
  int v21; // xmm2_4
  int v22; // xmm1_4
  int v23; // xmm2_4
  int v24; // xmm1_4
  int v25; // xmm2_4
  signed __int64 v26; // rcx
  signed __int64 v27; // r8
  int *v28; // rdx
  int v29; // xmm0_4
  int v30; // xmm1_4
  int v31; // xmm2_4
  bool v32; // al
  unsigned int v33; // edx
  void (__fastcall *pre_draw_callback)(Illusion::Material *, Render::View *, Illusion::StateValues *, Illusion::Primitive *, Illusion::StateArgs *); // ST30_8

  v5 = num_points;
  v6 = this;
  v7 = points;
  v8 = 48 * num_points;
  v9 = info;
  v10 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 48 * num_points, 0x10u);
  v11 = (Render::vDynamic *)v10;
  if ( v10 )
  {
    v12 = (signed int)(float)(v9->mColour1.r * 255.0) | (((signed int)(float)(v9->mColour1.g * 255.0) | (((signed int)(float)(v9->mColour1.b * 255.0) | ((signed int)(float)(v9->mColour1.a * 255.0) << 8)) << 8)) << 8);
    UFG::qMemSet(v10, 0, v8);
    v13 = 0i64;
    if ( v5 >= 4 )
    {
      v14 = (signed __int64)&v11[1].mPosition.z;
      v15 = (signed __int64)&v7[1].z;
      v16 = ((unsigned __int64)(v5 - 4) >> 2) + 1;
      v13 = 4 * v16;
      do
      {
        v17 = *(_DWORD *)(v15 - 20);
        v18 = *(_DWORD *)(v15 - 16);
        v19 = *(_DWORD *)(v15 - 12);
        v14 += 192i64;
        v15 += 48i64;
        *(_DWORD *)(v14 - 248) = v17;
        *(_DWORD *)(v14 - 244) = v18;
        *(_DWORD *)(v14 - 240) = v19;
        *(_DWORD *)(v14 - 204) = v12;
        v20 = *(_DWORD *)(v15 - 52);
        v21 = *(_DWORD *)(v15 - 48);
        *(_DWORD *)(v14 - 200) = *(_DWORD *)(v15 - 56);
        *(_DWORD *)(v14 - 196) = v20;
        *(_DWORD *)(v14 - 192) = v21;
        *(_DWORD *)(v14 - 156) = v12;
        v22 = *(_DWORD *)(v15 - 40);
        v23 = *(_DWORD *)(v15 - 36);
        *(_DWORD *)(v14 - 152) = *(_DWORD *)(v15 - 44);
        *(_DWORD *)(v14 - 148) = v22;
        *(_DWORD *)(v14 - 144) = v23;
        *(_DWORD *)(v14 - 108) = v12;
        v24 = *(_DWORD *)(v15 - 28);
        v25 = *(_DWORD *)(v15 - 24);
        *(_DWORD *)(v14 - 104) = *(_DWORD *)(v15 - 32);
        *(_DWORD *)(v14 - 100) = v24;
        *(_DWORD *)(v14 - 96) = v25;
        *(_DWORD *)(v14 - 60) = v12;
        --v16;
      }
      while ( v16 );
    }
    if ( v13 < v5 )
    {
      v26 = (signed __int64)&v11[v13].mPosition.z;
      v27 = v5 - v13;
      v28 = (int *)&v7[v13].z;
      do
      {
        v29 = *(v28 - 2);
        v30 = *(v28 - 1);
        v31 = *v28;
        v26 += 48i64;
        v28 += 3;
        *(_DWORD *)(v26 - 56) = v29;
        *(_DWORD *)(v26 - 52) = v30;
        *(_DWORD *)(v26 - 48) = v31;
        *(_DWORD *)(v26 - 12) = v12;
        --v27;
      }
      while ( v27 );
    }
    v32 = v9->mFaceCull;
    v33 = 1660426324;
    if ( v32 )
    {
      if ( v9->mDepthBuffer )
      {
        v33 = 543723269;
LABEL_15:
        Render::View::CreateSimpleMaterial(0xB11369EB, v33, v9->mAlphaBlend, v9->mDepthBias);
        pre_draw_callback = v9->mPreDrawCallback;
        Render::View::DrawDebugPrim(v6, DebugPrim_TriangleStrip, v11, v5);
        return;
      }
      if ( v32 )
      {
        v33 = 206781021;
        goto LABEL_15;
      }
    }
    if ( v9->mDepthBuffer )
      v33 = 1099738947;
    goto LABEL_15;
  }
}

// File Line: 3514
// RVA: 0xF8A0
void __fastcall Render::View::DrawAxes(Render::View *this, UFG::qMatrix44 *xform, float scale, bool depthBuffer)
{
  bool v4; // bl
  UFG::qMatrix44 *v5; // rdi
  Render::View *v6; // rsi
  float v7; // xmm6_4
  Render::vDynamic *v8; // rax
  unsigned int v9; // edx
  Render::vDynamic *v10; // r14
  __m128 v11; // xmm2
  float v12; // xmm1_4
  float v13; // xmm0_4
  float v14; // xmm0_4
  float v15; // xmm1_4
  float v16; // xmm14_4
  float v17; // xmm1_4
  float v18; // xmm2_4
  float v19; // xmm3_4
  float v20; // xmm4_4
  float v21; // xmm5_4
  float v22; // xmm6_4
  float v23; // xmm7_4
  float v24; // xmm8_4
  float v25; // xmm9_4
  float v26; // xmm10_4
  float v27; // xmm11_4
  float v28; // xmm12_4
  float v29; // xmm13_4
  float v30; // xmm0_4
  float v31; // xmm1_4
  UFG::qVector4 v32; // xmm0
  UFG::qVector4 v33; // xmm3
  UFG::qVector4 v34; // xmm4
  UFG::qVector4 v35; // xmm5
  float v36; // xmm2_4
  float v37; // xmm1_4
  float v38; // xmm1_4
  UFG::qVector4 v39; // xmm0
  UFG::qVector4 v40; // xmm3
  UFG::qVector4 v41; // xmm4
  float v42; // xmm2_4
  float v43; // xmm1_4
  UFG::qVector4 v44; // xmm5
  float v45; // xmm2_4
  UFG::qVector4 v46; // xmm0
  UFG::qVector4 v47; // xmm3
  float v48; // xmm1_4
  float v49; // xmm1_4
  UFG::qVector4 v50; // xmm4
  float v51; // xmm6_4
  float v52; // xmm6_4
  UFG::qMatrix44 v53; // [rsp+40h] [rbp-A8h]

  v4 = depthBuffer;
  v5 = xform;
  v6 = this;
  v7 = scale;
  v8 = `anonymous namespace::GetVertsAxes();
  v9 = 1660426324;
  v10 = v8;
  if ( v4 )
    v9 = 543723269;
  Render::View::CreateSimpleMaterial(0xB11369EB, v9, 0x2782CCE6u, 0);
  if ( scale >= 0.0 )
  {
    v16 = scale;
  }
  else
  {
    v11 = (__m128)LODWORD(v5->v3.y);
    v12 = v5->v3.x - v6->mViewWorld.v3.x;
    v13 = v5->v3.z - v6->mViewWorld.v3.z;
    v11.m128_f32[0] = (float)((float)((float)(v11.m128_f32[0] - v6->mViewWorld.v3.y)
                                    * (float)(v11.m128_f32[0] - v6->mViewWorld.v3.y))
                            + (float)(v12 * v12))
                    + (float)(v13 * v13);
    v14 = FLOAT_0_000099999997;
    v15 = COERCE_FLOAT(_mm_sqrt_ps(v11)) * 0.034899496;
    if ( v15 >= 0.000099999997 )
      v14 = v15;
    LODWORD(v16) = COERCE_UNSIGNED_INT((float)(Fit_scale_adjust_9 * v7) * v14) ^ _xmm[0];
  }
  v17 = v5->v3.y;
  v18 = v5->v0.x * v16;
  v19 = v5->v0.y * v16;
  v20 = v5->v0.z * v16;
  v21 = v5->v0.w * v16;
  v22 = v5->v1.x * v16;
  v23 = v5->v1.y * v16;
  v24 = v5->v1.z * v16;
  v25 = v5->v1.w * v16;
  v26 = v5->v2.x * v16;
  v27 = v5->v2.y * v16;
  v28 = v5->v2.z;
  v29 = v5->v2.w;
  v53.v3.x = v5->v3.x;
  v30 = v5->v3.z;
  v53.v3.y = v17;
  v31 = v5->v3.w;
  v53.v3.z = v30;
  v53.v3.w = v31;
  v53.v0.x = v18;
  v53.v0.y = v19;
  v53.v0.z = v20;
  v53.v0.w = v21;
  v53.v1.x = v22;
  v53.v1.y = v23;
  v53.v1.z = v24;
  v53.v1.w = v25;
  v53.v2.x = v26;
  v53.v2.y = v27;
  v53.v2.z = v28 * v16;
  v53.v2.w = v29 * v16;
  Render::View::DrawDebugPrim(v6, DebugPrim_LineSegment, v10, 6);
  v32 = v6->mViewWorld.v3;
  v33 = v6->mViewWorld.v0;
  v34 = v6->mViewWorld.v1;
  v53.v0 = v33;
  v53.v1 = v34;
  v35 = v6->mViewWorld.v2;
  v36 = (float)((float)(v16 * 1.5) * v5->v0.x) + v5->v3.x;
  v37 = (float)((float)(v16 * 1.5) * v5->v0.y) + v5->v3.y;
  v53.v2 = v35;
  v53.v3 = v32;
  v53.v3.x = v36;
  v53.v3.y = v37;
  v53.v3.w = 1.0;
  v32.x = (float)((float)(v16 * 1.5) * v5->v0.z) + v5->v3.z;
  v53.v0.x = v33.x * v16;
  v53.v3.z = v32.x;
  v53.v0.y = v53.v0.y * v16;
  v53.v1.x = v34.x * v16;
  v53.v2.x = v35.x * v16;
  v53.v0.w = v33.w * v16;
  v53.v0.z = v33.z * v16;
  v53.v1.y = v53.v1.y * v16;
  v53.v1.w = v34.w * v16;
  v53.v1.z = v34.z * v16;
  v53.v2.y = v53.v2.y * v16;
  v53.v2.w = v35.w * v16;
  v53.v2.z = v35.z * v16;
  Render::View::DrawDebugPrim(v6, DebugPrim_LineSegment, v10 + 6, 4);
  v38 = (float)(v16 * 1.5) * v5->v1.y;
  v39 = v6->mViewWorld.v3;
  v40 = v6->mViewWorld.v0;
  v41 = v6->mViewWorld.v1;
  v42 = (float)(v16 * 1.5) * v5->v1.x;
  v53.v0 = v40;
  v53.v1 = v41;
  v43 = v38 + v5->v3.y;
  v44 = v6->mViewWorld.v2;
  v45 = v42 + v5->v3.x;
  v53.v2 = v44;
  v53.v3 = v39;
  v53.v3.y = v43;
  v53.v3.w = 1.0;
  v39.x = (float)((float)(v16 * 1.5) * v5->v1.z) + v5->v3.z;
  v53.v3.x = v45;
  v53.v0.x = v40.x * v16;
  v53.v3.z = v39.x;
  v53.v0.z = v40.z * v16;
  v53.v0.y = v53.v0.y * v16;
  v53.v0.w = v40.w * v16;
  v53.v1.x = v41.x * v16;
  v53.v1.y = v53.v1.y * v16;
  v53.v1.z = v41.z * v16;
  v53.v1.w = v41.w * v16;
  v53.v2.x = v44.x * v16;
  v53.v2.y = v53.v2.y * v16;
  v53.v2.z = v44.z * v16;
  v53.v2.w = v44.w * v16;
  Render::View::DrawDebugPrim(v6, DebugPrim_LineSegment, v10 + 10, 6);
  v46 = v6->mViewWorld.v3;
  v47 = v6->mViewWorld.v1;
  v48 = (float)(v16 * 1.5) * v5->v2.x;
  v53.v0 = v6->mViewWorld.v0;
  v53.v1 = v47;
  v49 = v48 + v5->v3.x;
  v50 = v6->mViewWorld.v2;
  v53.v3 = v46;
  v53.v3.w = 1.0;
  v51 = (float)(v16 * 1.5) * v5->v2.z;
  v46.x = (float)(v16 * 1.5) * v5->v2.y;
  v53.v2 = v50;
  v46.x = v46.x + v5->v3.y;
  v52 = v51 + v5->v3.z;
  v53.v3.x = v49;
  v53.v3.y = v46.x;
  v53.v0.y = v53.v0.y * v16;
  v53.v0.z = v53.v0.z * v16;
  v53.v0.w = v53.v0.w * v16;
  v53.v1.y = v53.v1.y * v16;
  v53.v1.z = v47.z * v16;
  v53.v1.w = v47.w * v16;
  v53.v2.y = v53.v2.y * v16;
  v53.v3.z = v52;
  v53.v0.x = v53.v0.x * v16;
  v53.v1.x = v47.x * v16;
  v53.v2.x = v50.x * v16;
  v53.v2.w = v50.w * v16;
  v53.v2.z = v50.z * v16;
  Render::View::DrawDebugPrim(v6, DebugPrim_LineSegment, v10 + 16, 6);
}

