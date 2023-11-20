// File Line: 39
// RVA: 0x93CEB0
void __fastcall Scaleform::Render::GradientData::GradientData(Scaleform::Render::GradientData *this, Scaleform::Render::GradientType type, unsigned __int16 recordCount, bool linearRgb)
{
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,257>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::Render::GradientData,257>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::GradientData::`vftable;
  this->LinearRGB = linearRgb;
  this->Type = type;
  this->RecordCount = 0;
  this->pRecords = 0i64;
  this->FocalRatio = 0.0;
  this->pMorphTo = 0i64;
  Scaleform::Render::GradientData::SetRecordCount(this, recordCount, 0);
}

// File Line: 46
// RVA: 0x94AB60
void __fastcall Scaleform::Render::GradientData::~GradientData(Scaleform::Render::GradientData *this)
{
  Scaleform::Render::GradientData *v1; // rbx

  v1 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::GradientData::`vftable;
  if ( this->pRecords )
    ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  v1->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
}

// File Line: 53
// RVA: 0x9B32F0
bool __fastcall Scaleform::Render::GradientData::SetRecordCount(Scaleform::Render::GradientData *this, unsigned __int16 count, bool tmpHeap)
{
  unsigned __int16 v3; // di
  Scaleform::Render::GradientData *v4; // rbx
  __int64 v5; // rax
  Scaleform::MemoryHeapVtbl *v6; // rax
  Scaleform::Render::GradientRecord *v7; // rsi
  unsigned __int16 v8; // ax
  Scaleform::Render::GradientRecord *v9; // rdx
  __int64 v10; // r8
  signed __int64 v11; // rcx
  char *v12; // rcx

  v3 = count;
  v4 = this;
  if ( count == this->RecordCount )
  {
    LOBYTE(v5) = 1;
  }
  else
  {
    v6 = Scaleform::Memory::pGlobalHeap->vfptr;
    if ( tmpHeap )
      v5 = (__int64)v6->Alloc(Scaleform::Memory::pGlobalHeap, 8i64 * count, 0i64);
    else
      v5 = (__int64)v6->AllocAutoHeap(Scaleform::Memory::pGlobalHeap, this, 8i64 * count, 0i64);
    v7 = (Scaleform::Render::GradientRecord *)v5;
    if ( v5 )
    {
      if ( v4->pRecords )
      {
        v8 = v4->RecordCount;
        if ( v3 < v8 )
          v8 = v3;
        if ( v8 )
        {
          v9 = v7;
          v10 = v8;
          do
          {
            v11 = (char *)v9 - (char *)v7;
            ++v9;
            v12 = (char *)v4->pRecords + v11;
            v9[-1].Ratio = *v12;
            v9[-1].ColorV.Raw = *((_DWORD *)v12 + 1);
            --v10;
          }
          while ( v10 );
        }
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v4->pRecords);
      }
      v4->pRecords = v7;
      v4->RecordCount = v3;
      LOBYTE(v5) = 1;
    }
  }
  return v5;
}

// File Line: 80
// RVA: 0x9B10E0
void __fastcall Scaleform::Render::GradientData::SetLerp(Scaleform::Render::GradientData *this, Scaleform::Render::GradientData *data1, Scaleform::Render::GradientData *data2, float morphRatio)
{
  Scaleform::Render::GradientData *v4; // rdi
  Scaleform::Render::GradientData *v5; // rsi
  Scaleform::Render::GradientData *v6; // rbx
  unsigned __int16 i; // r11
  __int64 v8; // r10
  unsigned int v9; // eax
  unsigned int v10; // ecx
  signed int v11; // edx
  signed int v12; // eax
  Scaleform::Render::GradientRecord *v13; // rcx
  float v14; // xmm1_4
  unsigned int v15; // [rsp+50h] [rbp+8h]
  unsigned int v16; // [rsp+58h] [rbp+10h]
  unsigned int v17; // [rsp+68h] [rbp+20h]

  v4 = data1;
  v5 = data2;
  this->Type = data1->Type;
  v6 = this;
  Scaleform::Render::GradientData::SetRecordCount(this, data1->RecordCount, 1);
  for ( i = 0; i < v6->RecordCount; v13[v8].ColorV.Raw = v17 )
  {
    v8 = i;
    v9 = v4->pRecords[i].ColorV.Raw;
    v10 = v5->pRecords[i++].ColorV.Raw;
    v15 = v9;
    v16 = v10;
    BYTE2(v17) = (signed int)(float)((float)((float)((float)((float)BYTE2(v10) - (float)BYTE2(v9)) * morphRatio)
                                           + (float)BYTE2(v9))
                                   + 0.5);
    BYTE1(v17) = (signed int)(float)((float)((float)((float)((float)BYTE1(v16) - (float)BYTE1(v15)) * morphRatio)
                                           + (float)BYTE1(v15))
                                   + 0.5);
    v11 = (unsigned __int8)v9;
    v12 = (unsigned __int8)v10;
    v13 = v6->pRecords;
    LOBYTE(v17) = (signed int)(float)((float)((float)((float)((float)v12 - (float)v11) * morphRatio) + (float)v11) + 0.5);
    HIBYTE(v17) = (signed int)(float)((float)((float)((float)((float)HIBYTE(v16) - (float)HIBYTE(v15)) * morphRatio)
                                            + (float)HIBYTE(v15))
                                    + 0.5);
    v14 = (float)(unsigned __int8)v4->pRecords[v8].Ratio;
    v13[v8].Ratio = (signed int)(float)((float)((float)((float)(unsigned __int8)v5->pRecords[v8].Ratio - v14)
                                              * morphRatio)
                                      + v14);
  }
  v6->FocalRatio = (float)((float)(v5->FocalRatio - v4->FocalRatio) * morphRatio) + v4->FocalRatio;
}

// File Line: 140
// RVA: 0x95C0F0
signed __int64 __fastcall Scaleform::Render::GradientData::CalcImageSize(Scaleform::Render::GradientData *this)
{
  unsigned int v1; // edi
  unsigned int v2; // er11
  signed __int64 v3; // rbp
  float v4; // xmm1_4
  Scaleform::Render::GradientRecord *v5; // rax
  unsigned __int8 *v6; // r8
  unsigned __int8 *v7; // r10
  unsigned __int8 *v8; // r9
  __int64 v9; // rbx
  float v10; // xmm2_4
  float v11; // xmm3_4
  float v12; // xmm0_4
  float v13; // xmm0_4
  float v14; // xmm0_4
  float v15; // xmm0_4
  float v16; // xmm2_4
  float v17; // xmm3_4
  float v18; // xmm0_4
  float v19; // xmm0_4
  float v20; // xmm0_4
  float v21; // xmm0_4
  float v22; // xmm2_4
  float v23; // xmm3_4
  float v24; // xmm0_4
  float v25; // xmm0_4
  float v26; // xmm0_4
  float v27; // xmm0_4
  float v28; // xmm2_4
  float v29; // xmm3_4
  float v30; // xmm0_4
  float v31; // xmm0_4
  float v32; // xmm0_4
  float v33; // xmm0_4
  Scaleform::Render::GradientRecord *v34; // r10
  char *v35; // r8
  __int64 v36; // r9
  float v37; // xmm2_4
  float v38; // xmm3_4
  float v39; // xmm0_4
  float v40; // xmm0_4
  float v41; // xmm0_4
  float v42; // xmm0_4
  float v43; // xmm2_4
  signed __int64 v44; // rax

  v1 = this->RecordCount;
  v2 = 1;
  v3 = 1i64;
  v4 = 0.0;
  if ( v1 <= 1 )
    return 64i64;
  if ( (signed int)(v1 - 1) >= 4 )
  {
    v5 = this->pRecords;
    v6 = (unsigned __int8 *)&v5[2].ColorV.Channels.Green;
    v7 = (unsigned __int8 *)&v5[1].ColorV.Channels.Red;
    v8 = (unsigned __int8 *)&v5->ColorV.Channels.Green;
    LODWORD(v5) = ((v1 - 5) >> 2) + 1;
    v9 = (unsigned int)v5;
    v2 = 4 * (_DWORD)v5 + 1;
    v3 = 4i64 * (unsigned int)v5 + 1;
    do
    {
      v10 = (float)*(v6 - 13) - (float)*(v7 - 14);
      if ( v10 > 0.0 )
      {
        v11 = 1.0 / v10;
        v12 = (float)(signed int)abs(v8[1] - *(v6 - 7)) * (float)(1.0 / v10);
        if ( v12 > v4 )
          v4 = v12;
        v13 = (float)(signed int)abs(*v8 - *(v6 - 8)) * v11;
        if ( v13 > v4 )
          v4 = v13;
        v14 = (float)(signed int)abs(*(v8 - 1) - *(v6 - 9)) * v11;
        if ( v14 > v4 )
          v4 = v14;
        v15 = (float)(signed int)abs(v8[2] - *(v6 - 6)) * v11;
        if ( v15 > v4 )
          v4 = v15;
      }
      v16 = (float)*(v6 - 5) - (float)*(v7 - 6);
      if ( v16 > 0.0 )
      {
        v17 = 1.0 / v16;
        v18 = (float)(signed int)abs(*v7 - v6[1]) * (float)(1.0 / v16);
        if ( v18 > v4 )
          v4 = v18;
        v19 = (float)(signed int)abs(*(v7 - 1) - *v6) * v17;
        if ( v19 > v4 )
          v4 = v19;
        v20 = (float)(signed int)abs(*(v7 - 2) - *(v6 - 1)) * v17;
        if ( v20 > v4 )
          v4 = v20;
        v21 = (float)(signed int)abs(v7[1] - v6[2]) * v17;
        if ( v21 > v4 )
          v4 = v21;
      }
      v22 = (float)v6[3] - (float)v7[2];
      if ( v22 > 0.0 )
      {
        v23 = 1.0 / v22;
        v24 = (float)(signed int)abs(v8[17] - v6[9]) * (float)(1.0 / v22);
        if ( v24 > v4 )
          v4 = v24;
        v25 = (float)(signed int)abs(v8[16] - v6[8]) * v23;
        if ( v25 > v4 )
          v4 = v25;
        v26 = (float)(signed int)abs(v8[15] - v6[7]) * v23;
        if ( v26 > v4 )
          v4 = v26;
        v27 = (float)(signed int)abs(v8[18] - v6[10]) * v23;
        if ( v27 > v4 )
          v4 = v27;
      }
      v28 = (float)v6[11] - (float)v7[10];
      if ( v28 > 0.0 )
      {
        v29 = 1.0 / v28;
        v30 = (float)(signed int)abs(v8[25] - v6[17]) * (float)(1.0 / v28);
        if ( v30 > v4 )
          v4 = v30;
        v31 = (float)(signed int)abs(v8[24] - v6[16]) * v29;
        if ( v31 > v4 )
          v4 = v31;
        v32 = (float)(signed int)abs(v8[23] - v6[15]) * v29;
        if ( v32 > v4 )
          v4 = v32;
        v33 = (float)(signed int)abs(v8[26] - v6[18]) * v29;
        if ( v33 > v4 )
          v4 = v33;
      }
      v6 += 32;
      v8 += 32;
      v7 += 32;
      --v9;
    }
    while ( v9 );
  }
  if ( v2 < v1 )
  {
    v34 = this->pRecords;
    v35 = &v34[v3].ColorV.Channels.Green;
    do
    {
      v36 = v2 - 1;
      v37 = (float)(unsigned __int8)*(v35 - 5) - (float)(unsigned __int8)v34[v36].Ratio;
      if ( v37 > 0.0 )
      {
        v38 = 1.0 / v37;
        v39 = (float)(signed int)abs((unsigned __int8)v34[v36].ColorV.Channels.Red - (unsigned __int8)v35[1])
            * (float)(1.0 / v37);
        if ( v39 > v4 )
          v4 = v39;
        v40 = (float)(signed int)abs((unsigned __int8)v34[v36].ColorV.Channels.Green - (unsigned __int8)*v35) * v38;
        if ( v40 > v4 )
          v4 = v40;
        v41 = (float)(signed int)abs((unsigned __int8)v34[v36].ColorV.Channels.Blue - (unsigned __int8)*(v35 - 1)) * v38;
        if ( v41 > v4 )
          v4 = v41;
        v42 = (float)(signed int)abs((unsigned __int8)v34[v36].ColorV.Channels.Alpha - (unsigned __int8)v35[2]) * v38;
        if ( v42 > v4 )
          v4 = v42;
      }
      ++v2;
      v35 += 8;
    }
    while ( v2 < v1 );
  }
  if ( v4 == 0.0 )
    return 64i64;
  if ( this->LinearRGB )
    v4 = v4 * 1.5;
  if ( this->Type == 2 )
  {
    LODWORD(v43) = LODWORD(this->FocalRatio) & _xmm;
    if ( v43 > 0.5 )
      v4 = v4 / (float)(1.01 - v43);
  }
  if ( v4 < 0.0 )
    v4 = 0.0;
  v44 = (unsigned int)(signed int)fsqrt((float)(v4 + 0.18000001) * 5.0);
  if ( (unsigned int)v44 >= 0x12 )
    v44 = 17i64;
  return Scaleform::Render::GradientData::ImageSizeTable[v44];
}

// File Line: 221
// RVA: 0x9CE9A0
Scaleform::Render::GradientRamp::ColorType *__fastcall Scaleform::Render::GradientRamp::applyGammaDir(Scaleform::Render::GradientRamp::ColorType *result, Scaleform::Render::Color *c, float gamma)
{
  __int16 v3; // di
  Scaleform::Render::Color *v4; // rsi
  Scaleform::Render::GradientRamp::ColorType *v5; // rbx
  __m128 v6; // xmm0
  signed int v7; // ecx
  __m128 v8; // xmm0
  signed int v9; // ecx
  __m128 v10; // xmm0
  signed int v11; // ecx

  v3 = (unsigned __int8)c->Channels.Alpha;
  v4 = c;
  v5 = result;
  v6 = (__m128)COERCE_UNSIGNED_INT((float)(unsigned __int8)c->Channels.Red);
  v6.m128_f32[0] = (float)(powf(v6.m128_f32[0] * 0.0039215689, gamma) * 65535.0) + 0.5;
  v7 = (signed int)v6.m128_f32[0];
  if ( (signed int)v6.m128_f32[0] != 0x80000000 && (float)v7 != v6.m128_f32[0] )
    v6.m128_f32[0] = (float)(v7 - (_mm_movemask_ps(_mm_unpacklo_ps(v6, v6)) & 1));
  v5->r = (signed int)v6.m128_f32[0];
  v8 = (__m128)COERCE_UNSIGNED_INT((float)(unsigned __int8)v4->Channels.Green);
  v8.m128_f32[0] = (float)(powf(v8.m128_f32[0] * 0.0039215689, gamma) * 65535.0) + 0.5;
  v9 = (signed int)v8.m128_f32[0];
  if ( (signed int)v8.m128_f32[0] != 0x80000000 && (float)v9 != v8.m128_f32[0] )
    v8.m128_f32[0] = (float)(v9 - (_mm_movemask_ps(_mm_unpacklo_ps(v8, v8)) & 1));
  v5->g = (signed int)v8.m128_f32[0];
  v10 = (__m128)COERCE_UNSIGNED_INT((float)(unsigned __int8)v4->Channels.Blue);
  v10.m128_f32[0] = (float)(powf(v10.m128_f32[0] * 0.0039215689, gamma) * 65535.0) + 0.5;
  v11 = (signed int)v10.m128_f32[0];
  if ( (signed int)v10.m128_f32[0] != 0x80000000 && (float)v11 != v10.m128_f32[0] )
    v10.m128_f32[0] = (float)(v11 - (_mm_movemask_ps(_mm_unpacklo_ps(v10, v10)) & 1));
  v5->b = (signed int)v10.m128_f32[0];
  v5->a = v3 | (v3 << 8);
  return v5;
}

// File Line: 241
// RVA: 0x9CF540
void __fastcall Scaleform::Render::GradientRamp::blendColors(char *c, Scaleform::Render::GradientRamp::ColorType *c1, Scaleform::Render::GradientRamp::ColorType *c2, int ratio, int maxRatio, float gamma)
{
  Scaleform::Render::GradientRamp::ColorType *v6; // rbx
  int v7; // ebp
  Scaleform::Render::GradientRamp::ColorType *v8; // r14
  char *v9; // rsi
  __m128 v10; // xmm0
  signed int v11; // ecx
  __m128 v12; // xmm0
  signed int v13; // ecx
  __m128 v14; // xmm0
  signed int v15; // ecx

  v6 = c1;
  v7 = ratio;
  v8 = c2;
  v9 = c;
  v10 = (__m128)COERCE_UNSIGNED_INT((float)(unsigned __int16)(c1->r + (unsigned int)(ratio * (c2->r - c1->r) / maxRatio)));
  v10.m128_f32[0] = (float)(powf(v10.m128_f32[0] * 0.000015259022, gamma) * 255.0) + 0.5;
  v11 = (signed int)v10.m128_f32[0];
  if ( (signed int)v10.m128_f32[0] != 0x80000000 && (float)v11 != v10.m128_f32[0] )
    v10.m128_f32[0] = (float)(v11 - (_mm_movemask_ps(_mm_unpacklo_ps(v10, v10)) & 1));
  *v9 = (signed int)v10.m128_f32[0];
  v12 = (__m128)COERCE_UNSIGNED_INT((float)(unsigned __int16)(v6->g + (unsigned int)(v7 * (v8->g - v6->g) / maxRatio)));
  v12.m128_f32[0] = (float)(powf(v12.m128_f32[0] * 0.000015259022, gamma) * 255.0) + 0.5;
  v13 = (signed int)v12.m128_f32[0];
  if ( (signed int)v12.m128_f32[0] != 0x80000000 && (float)v13 != v12.m128_f32[0] )
    v12.m128_f32[0] = (float)(v13 - (_mm_movemask_ps(_mm_unpacklo_ps(v12, v12)) & 1));
  v9[1] = (signed int)v12.m128_f32[0];
  v14 = (__m128)COERCE_UNSIGNED_INT((float)(unsigned __int16)(v6->b + (unsigned int)(v7 * (v8->b - v6->b) / maxRatio)));
  v14.m128_f32[0] = (float)(powf(v14.m128_f32[0] * 0.000015259022, gamma) * 255.0) + 0.5;
  v15 = (signed int)v14.m128_f32[0];
  if ( (signed int)v14.m128_f32[0] != 0x80000000 && (float)v15 != v14.m128_f32[0] )
    v14.m128_f32[0] = (float)(v15 - (_mm_movemask_ps(_mm_unpacklo_ps(v14, v14)) & 1));
  v9[2] = (signed int)v14.m128_f32[0];
  v9[3] = LOBYTE(v6->a) + (unsigned int)(v7 * (v8->a - v6->a) / (maxRatio | (maxRatio << 8)));
}

// File Line: 264
// RVA: 0x93D1E0
void __fastcall Scaleform::Render::GradientRamp::GradientRamp(Scaleform::Render::GradientRamp *this, Scaleform::Render::GradientRecord *records, unsigned int recordCount, float gamma)
{
  Scaleform::Render::GradientRecord *v4; // r9
  Scaleform::Render::GradientRamp *v5; // r13
  int v6; // edx
  unsigned int v7; // er15
  unsigned int v8; // er12
  __int64 v9; // rcx
  Scaleform::Render::GradientRamp *v10; // rdi
  Scaleform::Render::GradientRecord *v11; // rcx
  Scaleform::Render::Color *v12; // rdi
  char v13; // di^1
  char v14; // r9^1
  char v15; // r10^1
  char v16; // r11^1
  unsigned int v17; // edx
  int v18; // er8
  __int64 v19; // rbx
  int v20; // esi
  int v21; // er11
  int v22; // edi
  int v23; // er14
  char v24; // cl
  int v25; // er12
  __int64 v26; // r10
  int v27; // er9
  int v28; // er15
  int v29; // eax
  int v30; // eax
  int v31; // eax
  int v32; // eax
  __int64 v33; // rbx
  int v34; // esi
  int maxRatio; // er12
  __int64 v36; // r14
  bool v37; // zf
  char *v38; // rdi
  __int64 j; // rcx
  int v40; // eax
  Scaleform::Render::GradientRamp *v41; // rdi
  signed __int64 i; // rcx
  char c[4]; // [rsp+30h] [rbp-69h]
  Scaleform::Render::GradientRamp::ColorType result; // [rsp+38h] [rbp-61h]
  unsigned int v45; // [rsp+40h] [rbp-59h]
  Scaleform::Render::GradientRamp::ColorType c2; // [rsp+48h] [rbp-51h]
  unsigned int v47; // [rsp+50h] [rbp-49h]
  int v48; // [rsp+54h] [rbp-45h]
  int v49; // [rsp+58h] [rbp-41h]
  int v50; // [rsp+5Ch] [rbp-3Dh]
  int v51; // [rsp+60h] [rbp-39h]
  char v52; // [rsp+68h] [rbp-31h]
  int v53; // [rsp+6Ch] [rbp-2Dh]
  Scaleform::Render::GradientRecord *v54; // [rsp+70h] [rbp-29h]
  __int64 v55; // [rsp+78h] [rbp-21h]
  Scaleform::Render::Color *v56; // [rsp+80h] [rbp-19h]
  Scaleform::Render::GradientRamp::ColorType v57; // [rsp+88h] [rbp-11h]
  unsigned __int16 v58; // [rsp+100h] [rbp+67h]
  unsigned __int16 v59; // [rsp+108h] [rbp+6Fh]
  unsigned __int16 v60; // [rsp+110h] [rbp+77h]

  v4 = records;
  v5 = this;
  if ( !recordCount || !records )
  {
    v52 = 0;
    v53 = -16777216;
    recordCount = 1;
    v4 = (Scaleform::Render::GradientRecord *)&v52;
  }
  c[0] = v4->ColorV.Channels.Red;
  c[1] = v4->ColorV.Channels.Green;
  c[2] = v4->ColorV.Channels.Blue;
  c[3] = v4->ColorV.Channels.Alpha;
  if ( recordCount <= 1 )
  {
    v40 = *(_DWORD *)c;
    v41 = this;
    for ( i = 256i64; i; --i )
    {
      *(_DWORD *)v41->Ramp = v40;
      v41 = (Scaleform::Render::GradientRamp *)((char *)v41 + 4);
    }
    return;
  }
  v6 = *(_DWORD *)c;
  v7 = (unsigned __int8)v4->Ratio;
  v8 = 0;
  if ( v4->Ratio )
  {
    v9 = (unsigned __int8)v4->Ratio;
    v10 = v5;
    while ( v9 )
    {
      *(_DWORD *)v10->Ramp = v6;
      v10 = (Scaleform::Render::GradientRamp *)((char *)v10 + 4);
      --v9;
    }
  }
  if ( recordCount <= 1 )
  {
LABEL_27:
    v38 = &v5->Ramp[4 * v8];
    for ( j = 256 - v8; j; --j )
    {
      *(_DWORD *)v38 = v6;
      v38 += 4;
    }
    return;
  }
  v11 = v4 + 1;
  v12 = &v4[1].ColorV;
  v54 = v4 + 1;
  v56 = &v4[1].ColorV;
  v55 = recordCount - 1;
  do
  {
    v8 = (unsigned __int8)v11->Ratio;
    if ( v8 < v7 )
      v8 = v7;
    v45 = v8;
    Scaleform::Render::GradientRamp::applyGammaDir(&result, v12 - 2, gamma);
    Scaleform::Render::GradientRamp::applyGammaDir(&c2, v12, gamma);
    v13 = HIBYTE(c2.r);
    v14 = HIBYTE(c2.a);
    v15 = HIBYTE(c2.b);
    v16 = HIBYTE(c2.g);
    v17 = v8 - v7;
    v57 = c2;
    v60 = c2.a;
    v58 = c2.b;
    v59 = c2.g;
    if ( gamma == 1.0 )
    {
      if ( v7 >= v8 )
        goto LABEL_24;
      v18 = (v17 - 1) | ((v17 - 1) << 8);
      if ( v18 < 1 )
        v18 = 1;
      v48 = c2.a - result.a;
      v19 = 4 * v7;
      v20 = 0;
      v49 = c2.b - result.b;
      v21 = c2.a - result.a;
      v22 = c2.b - result.b;
      v23 = 0;
      v51 = c2.g - result.g;
      v24 = result.r;
      v25 = 0;
      v26 = v17;
      v50 = c2.r - result.r;
      v27 = 0;
      v47 = v17 + v7;
      v28 = c2.g - result.g;
      do
      {
        v29 = v27;
        v27 += v50;
        c[0] = v24 + (unsigned int)(v29 / v18);
        v30 = v25;
        v25 += v28;
        c[1] = LOBYTE(result.g) + (unsigned int)(v30 / v18);
        v31 = v23;
        v23 += v22;
        c[2] = LOBYTE(result.b) + (unsigned int)(v31 / v18);
        v32 = v20;
        v20 += v21;
        c[3] = LOBYTE(result.a) + (unsigned int)(v32 / v18);
        *(_DWORD *)&v5->Ramp[v19] = *(_DWORD *)c;
        v19 = (unsigned int)(v19 + 4);
        --v26;
      }
      while ( v26 );
      v13 = HIBYTE(v57.r);
      v7 = v47;
    }
    else
    {
      if ( v7 >= v8 )
        goto LABEL_24;
      v33 = 4 * v7;
      v34 = 0;
      maxRatio = v17 - 1;
      v7 += v17;
      v36 = v17;
      do
      {
        Scaleform::Render::GradientRamp::blendColors(c, &result, &c2, v34++, maxRatio, 1.0 / gamma);
        *(_DWORD *)&v5->Ramp[v33] = *(_DWORD *)c;
        v33 = (unsigned int)(v33 + 4);
        --v36;
      }
      while ( v36 );
    }
    v16 = HIBYTE(v59);
    v15 = HIBYTE(v58);
    v14 = HIBYTE(v60);
    v8 = v45;
LABEL_24:
    c[0] = v13;
    v11 = v54 + 1;
    v12 = v56 + 2;
    v37 = v55-- == 1;
    c[1] = v16;
    c[2] = v15;
    v56 += 2;
    c[3] = v14;
    ++v54;
  }
  while ( !v37 );
  if ( v8 < 0x100 )
  {
    v6 = *(_DWORD *)c;
    goto LABEL_27;
  }
}

// File Line: 365
// RVA: 0x992730
void __fastcall Scaleform::Render::FocalRadialGradient::Init(Scaleform::Render::FocalRadialGradient *this, float r, float fx, float fy)
{
  float v4; // xmm5_4
  float v5; // xmm2_4
  float v6; // xmm3_4

  this->FocusX = fx;
  this->FocusY = fy;
  this->Radius = r;
  this->Radius2 = r * r;
  v4 = (float)(r * r) - (float)((float)(fx * fx) + (float)(fy * fy));
  if ( v4 == 0.0 )
  {
    if ( fx != 0.0 )
    {
      if ( fx >= 0.0 )
        v5 = fx - 1.0;
      else
        v5 = fx + 1.0;
      this->FocusX = v5;
    }
    if ( fy != 0.0 )
    {
      if ( fy >= 0.0 )
        v6 = fy - 1.0;
      else
        v6 = fy + 1.0;
      this->FocusY = v6;
    }
    v4 = (float)(r * r) - (float)((float)(this->FocusX * this->FocusX) + (float)(this->FocusY * this->FocusY));
  }
  this->Multiplier = r / v4;
}

// File Line: 412
// RVA: 0x93D100
void __fastcall Scaleform::Render::GradientImage::GradientImage(Scaleform::Render::GradientImage *this, Scaleform::Render::PrimitiveFillManager *mng, Scaleform::Render::GradientData *data, float morphRatio)
{
  Scaleform::Render::GradientImage *v4; // rbx
  Scaleform::Render::Texture *volatile v5; // rt1
  Scaleform::Render::Texture *volatile v6; // rax
  unsigned int v7; // eax

  v4 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountVImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountVImpl,3>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseV<Scaleform::Render::Image,3>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::ImageBase::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::Image::`vftable;
  this->pTexture.Value = 0i64;
  v5 = this->pTexture.Value;
  v6 = this->pTexture.Value;
  this->pUpdateSync = 0i64;
  this->pInverseMatrix = 0i64;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::GradientImage::`vftable;
  this->pManager = mng;
  if ( data )
    _InterlockedExchangeAdd(&data->RefCount, 1u);
  this->pData.pObject = data;
  this->Size.Width = 1;
  this->Size.Height = 1;
  this->MorphRatio = morphRatio;
  if ( data )
  {
    if ( data->Type )
    {
      v7 = Scaleform::Render::GradientData::CalcImageSize(data);
      v4->Size.Height = v7;
      v4->Size.Width = v7;
    }
    else
    {
      this->Size.Width = 256;
      this->Size.Height = 1;
    }
  }
}

// File Line: 430
// RVA: 0x94ABB0
void __fastcall Scaleform::Render::GradientImage::~GradientImage(Scaleform::Render::GradientImage *this)
{
  Scaleform::Render::GradientImage *v1; // rbx
  Scaleform::Render::PrimitiveFillManager *v2; // rcx
  Scaleform::Render::GradientData *v3; // rcx
  Scaleform::Render::GradientImage *key; // [rsp+48h] [rbp+10h]

  v1 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::GradientImage::`vftable;
  v2 = this->pManager;
  if ( v2 )
  {
    key = v1;
    Scaleform::HashSetBase<Scaleform::Render::GradientImage *,Scaleform::Render::GradientImage::PtrHashFunctor,Scaleform::Render::GradientImage::PtrHashFunctor,Scaleform::AllocatorLH<Scaleform::Render::GradientImage *,2>,Scaleform::HashsetCachedEntry<Scaleform::Render::GradientImage *,Scaleform::Render::GradientImage::PtrHashFunctor>>::RemoveAlt<Scaleform::Render::GradientImage *>(
      (Scaleform::HashSetBase<Scaleform::Render::GradientImage *,Scaleform::Render::GradientImage::PtrHashFunctor,Scaleform::Render::GradientImage::PtrHashFunctor,Scaleform::AllocatorLH<Scaleform::Render::GradientImage *,2>,Scaleform::HashsetCachedEntry<Scaleform::Render::GradientImage *,Scaleform::Render::GradientImage::PtrHashFunctor> > *)&v2->Gradients.pTable,
      &key);
  }
  v3 = v1->pData.pObject;
  if ( v3 && !_InterlockedDecrement(&v3->RefCount) && v3 )
    v3->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v3->vfptr, 1u);
  Scaleform::Render::Image::~Image((Scaleform::Render::Image *)&v1->vfptr);
}

// File Line: 437
// RVA: 0x96AE30
char __fastcall Scaleform::Render::GradientImage::Decode(Scaleform::Render::GradientImage *this, Scaleform::Render::ImageData *pdest, void (__fastcall *copyScanline)(char *, const char *, unsigned __int64, Scaleform::Render::Palette *, void *), void *arg)
{
  void *v4; // r12
  void (__fastcall *v5)(char *, const char *, unsigned __int64, Scaleform::Render::Palette *, void *); // rbx
  Scaleform::Render::GradientImage *v6; // r15
  unsigned int v7; // edi
  unsigned __int16 v8; // ax
  Scaleform::Render::ImagePlane *v9; // rdx
  char *v10; // r14
  Scaleform::Render::GradientData *v11; // r13
  Scaleform::Render::GradientData *v12; // r8
  float v13; // xmm3_4
  signed __int64 v14; // r8
  unsigned int v15; // ecx
  __int64 v16; // rsi
  int v17; // ebx
  unsigned int v18; // edx
  __int64 v19; // rcx
  Scaleform::Render::GradientRecord **v20; // rdi
  void (__fastcall *v21)(char *, Scaleform::Render::GradientRecord **, _QWORD, _QWORD, void *); // rdi
  signed int v22; // eax
  float v23; // xmm7_4
  float v24; // xmm8_4
  unsigned int v25; // esi
  signed int v26; // ebx
  float v27; // xmm9_4
  float v28; // xmm13_4
  float v29; // xmm14_4
  float v30; // xmm11_4
  float v31; // xmm12_4
  void (__fastcall *v32)(char *, Scaleform::Render::GradientRecord **, _QWORD, _QWORD, void *); // r14
  signed int v33; // edx
  _DWORD *v34; // rdi
  __m128 v35; // xmm0
  __m128 v36; // xmm1
  signed int v37; // ecx
  signed int v38; // eax
  float v39; // xmm0_4
  float v40; // xmm2_4
  __m128 v41; // xmm3
  signed int v42; // ecx
  signed int v43; // eax
  __int64 v44; // rdi
  Scaleform::Render::ImagePlane p; // [rsp+30h] [rbp-98h]
  Scaleform::Render::GradientData v47; // [rsp+50h] [rbp-78h]
  Scaleform::Render::GradientRamp v48; // [rsp+468h] [rbp+3A0h]
  unsigned __int64 v49; // [rsp+948h] [rbp+880h]
  char *v50; // [rsp+950h] [rbp+888h]
  void (__fastcall *v51)(char *, Scaleform::Render::GradientRecord **, _QWORD, _QWORD, void *); // [rsp+958h] [rbp+890h]

  *(_QWORD *)&v47.LinearRGB = -2i64;
  v4 = arg;
  v5 = copyScanline;
  v6 = this;
  v7 = 0;
  *(_QWORD *)&p.Width = 0i64;
  p.Pitch = 0i64;
  p.DataSize = 0i64;
  p.pData = 0i64;
  v8 = pdest->RawPlaneCount;
  if ( v8 <= 0u )
  {
    Scaleform::Render::ImagePlane::GetMipLevel(&pdest->pPlanes[0u % v8], pdest->Format, 0u / v8, &p, 0u % v8);
    v10 = p.pData;
    v49 = p.Pitch;
  }
  else
  {
    v9 = pdest->pPlanes;
    p.Width = v9->Width;
    p.Height = v9->Height;
    v49 = v9->Pitch;
    p.Pitch = v49;
    p.DataSize = v9->DataSize;
    v10 = v9->pData;
    p.pData = v9->pData;
  }
  v11 = v6->pData.pObject;
  if ( v11 )
  {
    v12 = v11->pMorphTo;
    v47.RefCount = 1;
    v47.vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::GradientData::`vftable;
    *(_DWORD *)&v47.LinearRGB = 0;
    v47.pRecords = 0i64;
    v47.FocalRatio = 0.0;
    v47.pMorphTo = 0i64;
    if ( v12 )
    {
      Scaleform::Render::GradientData::SetLerp(&v47, v11, v12, v6->MorphRatio);
      v11 = &v47;
    }
    if ( v11->LinearRGB )
      v13 = FLOAT_2_1700001;
    else
      v13 = *(float *)&FLOAT_1_0;
    Scaleform::Render::GradientRamp::GradientRamp(&v48, v11->pRecords, v11->RecordCount, v13);
    v15 = v6->Size.Height;
    v16 = v49 * (v15 - 1);
    if ( v11->Type )
    {
      v17 = *(_DWORD *)&v48.Ramp[1020];
      v18 = v6->Size.Width;
      if ( v18 )
      {
        v19 = v18;
        v20 = &v47.pRecords;
        while ( v19 )
        {
          *(_DWORD *)v20 = v17;
          v20 = (Scaleform::Render::GradientRecord **)((char *)v20 + 4);
          --v19;
        }
      }
      v21 = v51;
      v51(v10, &v47.pRecords, 4 * v18, 0i64, v4);
      v21(&v10[v16], &v47.pRecords, 4 * v6->Size.Width, 0i64, v4);
      v22 = v6->Size.Width;
      v23 = (float)v22 * 0.5;
      v24 = v23 - 1.0;
      v25 = v22 - 1;
      LODWORD(v47.pRecords) = v17;
      *(_DWORD *)((char *)&v47.RecordCount + (unsigned int)(4 * v22) + 2) = v17;
      if ( v11->Type == 2 )
        Scaleform::Render::FocalRadialGradient::Init(
          (Scaleform::Render::FocalRadialGradient *)&p.pData,
          v24,
          v11->FocalRatio * v24,
          0.0);
      v50 = &v10[v49];
      v26 = 1;
      if ( v25 > 1 )
      {
        v27 = 1.0 / v24;
        LODWORD(v14) = 255;
        v28 = *(float *)&v47.RefCount;
        v29 = *((float *)&v47.vfptr + 1);
        v30 = *(float *)&v47.vfptr;
        v31 = *((float *)&p.pData + 1);
        v32 = v51;
        do
        {
          v33 = 1;
          v34 = (_DWORD *)((char *)&v47.pRecords + 4);
          if ( v11->Type == 1 )
          {
            do
            {
              v35 = 0i64;
              v35.m128_f32[0] = (float)((float)((float)((float)v33 - v23) + 0.5)
                                      * (float)((float)((float)v33 - v23) + 0.5))
                              + (float)((float)((float)((float)v26 - v23) + 0.5)
                                      * (float)((float)((float)v26 - v23) + 0.5));
              v36 = _mm_sqrt_ps(v35);
              v36.m128_f32[0] = (float)((float)(v36.m128_f32[0] * 256.0) * v27) + 0.5;
              v37 = (signed int)v36.m128_f32[0];
              if ( (signed int)v36.m128_f32[0] != 0x80000000 && (float)v37 != v36.m128_f32[0] )
                v36.m128_f32[0] = (float)(v37 - (_mm_movemask_ps(_mm_unpacklo_ps(v36, v36)) & 1));
              v38 = (signed int)v36.m128_f32[0];
              if ( (signed int)v36.m128_f32[0] > (signed int)v14 )
                v38 = v14;
              *v34 = *(_DWORD *)&v48.Ramp[4 * v38];
              ++v33;
              ++v34;
            }
            while ( v33 < v25 );
          }
          else
          {
            do
            {
              v40 = (float)((float)((float)v33 - v23) + 0.5) - v31;
              v41 = 0i64;
              v39 = (float)((float)((float)v26 - v23) + 0.5) - v30;
              v41.m128_f32[0] = (float)((float)((float)((float)(fsqrt(COERCE_FLOAT(COERCE_UNSIGNED_INT(
                                                                                     (float)((float)((float)(v40 * v40) + (float)(v39 * v39))
                                                                                           * v29)
                                                                                   - (float)((float)((float)(v30 * v40) - (float)(v31 * v39))
                                                                                           * (float)((float)(v30 * v40) - (float)(v31 * v39)))) & _xmm))
                                                              + (float)((float)(v31 * v40) + (float)(v30 * v39)))
                                                      * v28)
                                              * 256.0)
                                      * v27)
                              + 0.5;
              v42 = (signed int)v41.m128_f32[0];
              if ( (signed int)v41.m128_f32[0] != 0x80000000 && (float)v42 != v41.m128_f32[0] )
                v41.m128_f32[0] = (float)(v42 - (_mm_movemask_ps(_mm_unpacklo_ps(v41, v41)) & 1));
              v43 = (signed int)v41.m128_f32[0];
              if ( (signed int)v41.m128_f32[0] > (signed int)v14 )
                v43 = v14;
              *v34 = *(_DWORD *)&v48.Ramp[4 * v43];
              ++v33;
              ++v34;
            }
            while ( v33 < v25 );
          }
          v44 = (__int64)v50;
          v32(v50, &v47.pRecords, 4 * v6->Size.Width, 0i64, v4);
          v50 = (char *)(v49 + v44);
          ++v26;
          v14 = 255i64;
        }
        while ( v26 < v25 );
      }
    }
    else if ( v15 )
    {
      do
      {
        v5(v10, v48.Ramp, 4 * v6->Size.Width, 0i64, v4);
        ++v7;
      }
      while ( v7 < v6->Size.Height );
    }
    v47.vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::GradientData::`vftable;
    if ( v47.pRecords )
      ((void (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::Render::GradientRecord *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
        Scaleform::Memory::pGlobalHeap,
        v47.pRecords,
        v14);
    v47.vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  }
  else
  {
    LODWORD(v47.pRecords) = 0;
    v5(v10, (const char *)&v47.pRecords, 4ui64, 0i64, v4);
  }
  return 1;
}

// File Line: 538
// RVA: 0x98DA30
Scaleform::Render::Texture *__fastcall Scaleform::Render::GradientImage::GetTexture(Scaleform::Render::GradientImage *this, Scaleform::Render::TextureManager *pmanager)
{
  Scaleform::Render::TextureManager *v2; // r14
  Scaleform::Render::GradientImage *v3; // rsi
  Scaleform::Render::TextureManager *v4; // rax
  Scaleform::Render::Texture *result; // rax
  Scaleform::RefCountImplCoreVtbl *v6; // rdi
  unsigned int v7; // eax

  v2 = pmanager;
  v3 = this;
  if ( this->pTexture.Value )
  {
    v4 = (Scaleform::Render::TextureManager *)this->pTexture.Value->pManagerLocks.pObject;
    if ( v4 )
      v4 = (Scaleform::Render::TextureManager *)v4->vfptr;
    if ( v4 == pmanager )
      return this->pTexture.Value;
  }
  if ( !pmanager )
    return 0i64;
  this->pTexture.Value = 0i64;
  v6 = pmanager->vfptr;
  v7 = ((__int64 (*)(void))this->vfptr[4].__vecDelDtor)();
  result = (Scaleform::Render::Texture *)((__int64 (__fastcall *)(Scaleform::Render::TextureManager *, _QWORD, signed __int64, Scaleform::Render::Size<unsigned long> *, signed int, Scaleform::Render::GradientImage *, _QWORD))v6[1].__vecDelDtor)(
                                           v2,
                                           v7,
                                           1i64,
                                           &v3->Size,
                                           1,
                                           v3,
                                           0i64);
  v3->pTexture.Value = result;
  return result;
}

