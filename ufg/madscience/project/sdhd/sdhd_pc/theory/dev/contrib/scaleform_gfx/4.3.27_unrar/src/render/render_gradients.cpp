// File Line: 39
// RVA: 0x93CEB0
void __fastcall Scaleform::Render::GradientData::GradientData(
        Scaleform::Render::GradientData *this,
        Scaleform::Render::GradientType type,
        unsigned __int16 recordCount,
        bool linearRgb)
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
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::GradientData::`vftable;
  if ( this->pRecords )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
}

// File Line: 53
// RVA: 0x9B32F0
bool __fastcall Scaleform::Render::GradientData::SetRecordCount(
        Scaleform::Render::GradientData *this,
        unsigned __int16 count,
        bool tmpHeap)
{
  __int64 v5; // rax
  Scaleform::MemoryHeapVtbl *vfptr; // rax
  Scaleform::Render::GradientRecord *v7; // rsi
  unsigned __int16 RecordCount; // ax
  Scaleform::Render::GradientRecord *v9; // rdx
  __int64 v10; // r8
  signed __int64 v11; // rcx
  char *v12; // rcx

  if ( count == this->RecordCount )
  {
    LOBYTE(v5) = 1;
  }
  else
  {
    vfptr = Scaleform::Memory::pGlobalHeap->vfptr;
    if ( tmpHeap )
      v5 = (__int64)vfptr->Alloc(Scaleform::Memory::pGlobalHeap, 8i64 * count, 0i64);
    else
      v5 = (__int64)vfptr->AllocAutoHeap(Scaleform::Memory::pGlobalHeap, this, 8i64 * count, 0i64);
    v7 = (Scaleform::Render::GradientRecord *)v5;
    if ( v5 )
    {
      if ( this->pRecords )
      {
        RecordCount = this->RecordCount;
        if ( count < RecordCount )
          RecordCount = count;
        if ( RecordCount )
        {
          v9 = v7;
          v10 = RecordCount;
          do
          {
            v11 = (char *)v9++ - (char *)v7;
            v12 = (char *)this->pRecords + v11;
            v9[-1].Ratio = *v12;
            v9[-1].ColorV.Raw = *((_DWORD *)v12 + 1);
            --v10;
          }
          while ( v10 );
        }
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, this->pRecords);
      }
      this->pRecords = v7;
      this->RecordCount = count;
      LOBYTE(v5) = 1;
    }
  }
  return v5;
}

// File Line: 80
// RVA: 0x9B10E0
void __fastcall Scaleform::Render::GradientData::SetLerp(
        Scaleform::Render::GradientData *this,
        Scaleform::Render::GradientData *data1,
        Scaleform::Render::GradientData *data2,
        float morphRatio)
{
  unsigned __int16 i; // r11
  __int64 v8; // r10
  unsigned int Raw; // eax
  unsigned int v10; // ecx
  int v11; // edx
  int v12; // eax
  Scaleform::Render::GradientRecord *pRecords; // rcx
  float Ratio; // xmm1_4
  unsigned __int8 v15; // [rsp+53h] [rbp+Bh]
  unsigned __int8 v16; // [rsp+5Bh] [rbp+13h]
  unsigned int v17; // [rsp+68h] [rbp+20h]

  this->Type = data1->Type;
  Scaleform::Render::GradientData::SetRecordCount(this, data1->RecordCount, 1);
  for ( i = 0; i < this->RecordCount; pRecords[v8].ColorV.Raw = v17 )
  {
    v8 = i;
    Raw = data1->pRecords[i].ColorV.Raw;
    v10 = data2->pRecords[i++].ColorV.Raw;
    v15 = HIBYTE(Raw);
    v16 = HIBYTE(v10);
    BYTE2(v17) = (int)(float)((float)((float)((float)((float)BYTE2(v10) - (float)BYTE2(Raw)) * morphRatio)
                                    + (float)BYTE2(Raw))
                            + 0.5);
    BYTE1(v17) = (int)(float)((float)((float)((float)((float)BYTE1(v10) - (float)BYTE1(Raw)) * morphRatio)
                                    + (float)BYTE1(Raw))
                            + 0.5);
    v11 = (unsigned __int8)Raw;
    v12 = (unsigned __int8)v10;
    pRecords = this->pRecords;
    LOBYTE(v17) = (int)(float)((float)((float)((float)((float)v12 - (float)v11) * morphRatio) + (float)v11) + 0.5);
    HIBYTE(v17) = (int)(float)((float)((float)((float)((float)v16 - (float)v15) * morphRatio) + (float)v15) + 0.5);
    Ratio = (float)(unsigned __int8)data1->pRecords[v8].Ratio;
    pRecords[v8].Ratio = (int)(float)((float)((float)((float)(unsigned __int8)data2->pRecords[v8].Ratio - Ratio)
                                            * morphRatio)
                                    + Ratio);
  }
  this->FocalRatio = (float)((float)(data2->FocalRatio - data1->FocalRatio) * morphRatio) + data1->FocalRatio;
}

// File Line: 140
// RVA: 0x95C0F0
__int64 __fastcall Scaleform::Render::GradientData::CalcImageSize(Scaleform::Render::GradientData *this)
{
  unsigned int RecordCount; // edi
  unsigned int v2; // r11d
  __int64 v3; // rbp
  float v4; // xmm1_4
  Scaleform::Render::GradientRecord *pRecords; // rax
  unsigned __int8 *p_Green; // r8
  unsigned __int8 *p_Red; // r10
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
  __int64 v44; // rax

  RecordCount = this->RecordCount;
  v2 = 1;
  v3 = 1i64;
  v4 = 0.0;
  if ( RecordCount <= 1 )
    return 64i64;
  if ( (int)(RecordCount - 1) >= 4 )
  {
    pRecords = this->pRecords;
    p_Green = (unsigned __int8 *)&pRecords[2].ColorV.Channels.Green;
    p_Red = (unsigned __int8 *)&pRecords[1].ColorV.Channels.Red;
    v8 = (unsigned __int8 *)&pRecords->ColorV.Channels.Green;
    LODWORD(pRecords) = ((RecordCount - 5) >> 2) + 1;
    v9 = (unsigned int)pRecords;
    v2 = 4 * (_DWORD)pRecords + 1;
    v3 = 4i64 * (unsigned int)pRecords + 1;
    do
    {
      v10 = (float)*(p_Green - 13) - (float)*(p_Red - 14);
      if ( v10 > 0.0 )
      {
        v11 = 1.0 / v10;
        v12 = (float)(int)abs32(v8[1] - *(p_Green - 7)) * (float)(1.0 / v10);
        if ( v12 > v4 )
          v4 = v12;
        v13 = (float)(int)abs32(*v8 - *(p_Green - 8)) * v11;
        if ( v13 > v4 )
          v4 = v13;
        v14 = (float)(int)abs32(*(v8 - 1) - *(p_Green - 9)) * v11;
        if ( v14 > v4 )
          v4 = v14;
        v15 = (float)(int)abs32(v8[2] - *(p_Green - 6)) * v11;
        if ( v15 > v4 )
          v4 = v15;
      }
      v16 = (float)*(p_Green - 5) - (float)*(p_Red - 6);
      if ( v16 > 0.0 )
      {
        v17 = 1.0 / v16;
        v18 = (float)(int)abs32(*p_Red - p_Green[1]) * (float)(1.0 / v16);
        if ( v18 > v4 )
          v4 = v18;
        v19 = (float)(int)abs32(*(p_Red - 1) - *p_Green) * v17;
        if ( v19 > v4 )
          v4 = v19;
        v20 = (float)(int)abs32(*(p_Red - 2) - *(p_Green - 1)) * v17;
        if ( v20 > v4 )
          v4 = v20;
        v21 = (float)(int)abs32(p_Red[1] - p_Green[2]) * v17;
        if ( v21 > v4 )
          v4 = v21;
      }
      v22 = (float)p_Green[3] - (float)p_Red[2];
      if ( v22 > 0.0 )
      {
        v23 = 1.0 / v22;
        v24 = (float)(int)abs32(v8[17] - p_Green[9]) * (float)(1.0 / v22);
        if ( v24 > v4 )
          v4 = v24;
        v25 = (float)(int)abs32(v8[16] - p_Green[8]) * v23;
        if ( v25 > v4 )
          v4 = v25;
        v26 = (float)(int)abs32(v8[15] - p_Green[7]) * v23;
        if ( v26 > v4 )
          v4 = v26;
        v27 = (float)(int)abs32(v8[18] - p_Green[10]) * v23;
        if ( v27 > v4 )
          v4 = v27;
      }
      v28 = (float)p_Green[11] - (float)p_Red[10];
      if ( v28 > 0.0 )
      {
        v29 = 1.0 / v28;
        v30 = (float)(int)abs32(v8[25] - p_Green[17]) * (float)(1.0 / v28);
        if ( v30 > v4 )
          v4 = v30;
        v31 = (float)(int)abs32(v8[24] - p_Green[16]) * v29;
        if ( v31 > v4 )
          v4 = v31;
        v32 = (float)(int)abs32(v8[23] - p_Green[15]) * v29;
        if ( v32 > v4 )
          v4 = v32;
        v33 = (float)(int)abs32(v8[26] - p_Green[18]) * v29;
        if ( v33 > v4 )
          v4 = v33;
      }
      p_Green += 32;
      v8 += 32;
      p_Red += 32;
      --v9;
    }
    while ( v9 );
  }
  if ( v2 < RecordCount )
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
        v39 = (float)(int)abs32((unsigned __int8)v34[v36].ColorV.Channels.Red - (unsigned __int8)v35[1])
            * (float)(1.0 / v37);
        if ( v39 > v4 )
          v4 = v39;
        v40 = (float)(int)abs32((unsigned __int8)v34[v36].ColorV.Channels.Green - (unsigned __int8)*v35) * v38;
        if ( v40 > v4 )
          v4 = v40;
        v41 = (float)(int)abs32((unsigned __int8)v34[v36].ColorV.Channels.Blue - (unsigned __int8)*(v35 - 1)) * v38;
        if ( v41 > v4 )
          v4 = v41;
        v42 = (float)(int)abs32((unsigned __int8)v34[v36].ColorV.Channels.Alpha - (unsigned __int8)v35[2]) * v38;
        if ( v42 > v4 )
          v4 = v42;
      }
      ++v2;
      v35 += 8;
    }
    while ( v2 < RecordCount );
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
  v44 = (unsigned int)(int)fsqrt((float)(v4 + 0.18000001) * 5.0);
  if ( (unsigned int)v44 >= 0x12 )
    v44 = 17i64;
  return Scaleform::Render::GradientData::ImageSizeTable[v44];
}

// File Line: 221
// RVA: 0x9CE9A0
Scaleform::Render::GradientRamp::ColorType *__fastcall Scaleform::Render::GradientRamp::applyGammaDir(
        Scaleform::Render::GradientRamp::ColorType *result,
        Scaleform::Render::Color *c,
        float gamma)
{
  __int16 Alpha; // di
  __m128 v6; // xmm0
  int v7; // ecx
  __m128 v8; // xmm0
  int v9; // ecx
  __m128 v10; // xmm0
  int v11; // ecx

  Alpha = (unsigned __int8)c->Channels.Alpha;
  v6 = (__m128)COERCE_UNSIGNED_INT((float)(unsigned __int8)c->Channels.Red);
  v6.m128_f32[0] = (float)(powf(v6.m128_f32[0] * 0.0039215689, gamma) * 65535.0) + 0.5;
  v7 = (int)v6.m128_f32[0];
  if ( (int)v6.m128_f32[0] != 0x80000000 && (float)v7 != v6.m128_f32[0] )
    v6.m128_f32[0] = (float)(v7 - (_mm_movemask_ps(_mm_unpacklo_ps(v6, v6)) & 1));
  result->r = (int)v6.m128_f32[0];
  v8 = (__m128)COERCE_UNSIGNED_INT((float)(unsigned __int8)c->Channels.Green);
  v8.m128_f32[0] = (float)(powf(v8.m128_f32[0] * 0.0039215689, gamma) * 65535.0) + 0.5;
  v9 = (int)v8.m128_f32[0];
  if ( (int)v8.m128_f32[0] != 0x80000000 && (float)v9 != v8.m128_f32[0] )
    v8.m128_f32[0] = (float)(v9 - (_mm_movemask_ps(_mm_unpacklo_ps(v8, v8)) & 1));
  result->g = (int)v8.m128_f32[0];
  v10 = (__m128)COERCE_UNSIGNED_INT((float)(unsigned __int8)c->Channels.Blue);
  v10.m128_f32[0] = (float)(powf(v10.m128_f32[0] * 0.0039215689, gamma) * 65535.0) + 0.5;
  v11 = (int)v10.m128_f32[0];
  if ( (int)v10.m128_f32[0] != 0x80000000 && (float)v11 != v10.m128_f32[0] )
    v10.m128_f32[0] = (float)(v11 - (_mm_movemask_ps(_mm_unpacklo_ps(v10, v10)) & 1));
  result->b = (int)v10.m128_f32[0];
  result->a = Alpha | (Alpha << 8);
  return result;
}

// File Line: 241
// RVA: 0x9CF540
void __fastcall Scaleform::Render::GradientRamp::blendColors(
        char *c,
        Scaleform::Render::GradientRamp::ColorType *c1,
        Scaleform::Render::GradientRamp::ColorType *c2,
        int ratio,
        int maxRatio,
        float gamma)
{
  __m128 v10; // xmm0
  int v11; // ecx
  __m128 v12; // xmm0
  int v13; // ecx
  __m128 v14; // xmm0
  int v15; // ecx

  v10 = (__m128)COERCE_UNSIGNED_INT((float)(unsigned __int16)(c1->r + ratio * (c2->r - c1->r) / maxRatio));
  v10.m128_f32[0] = (float)(powf(v10.m128_f32[0] * 0.000015259022, gamma) * 255.0) + 0.5;
  v11 = (int)v10.m128_f32[0];
  if ( (int)v10.m128_f32[0] != 0x80000000 && (float)v11 != v10.m128_f32[0] )
    v10.m128_f32[0] = (float)(v11 - (_mm_movemask_ps(_mm_unpacklo_ps(v10, v10)) & 1));
  *c = (int)v10.m128_f32[0];
  v12 = (__m128)COERCE_UNSIGNED_INT((float)(unsigned __int16)(c1->g + ratio * (c2->g - c1->g) / maxRatio));
  v12.m128_f32[0] = (float)(powf(v12.m128_f32[0] * 0.000015259022, gamma) * 255.0) + 0.5;
  v13 = (int)v12.m128_f32[0];
  if ( (int)v12.m128_f32[0] != 0x80000000 && (float)v13 != v12.m128_f32[0] )
    v12.m128_f32[0] = (float)(v13 - (_mm_movemask_ps(_mm_unpacklo_ps(v12, v12)) & 1));
  c[1] = (int)v12.m128_f32[0];
  v14 = (__m128)COERCE_UNSIGNED_INT((float)(unsigned __int16)(c1->b + ratio * (c2->b - c1->b) / maxRatio));
  v14.m128_f32[0] = (float)(powf(v14.m128_f32[0] * 0.000015259022, gamma) * 255.0) + 0.5;
  v15 = (int)v14.m128_f32[0];
  if ( (int)v14.m128_f32[0] != 0x80000000 && (float)v15 != v14.m128_f32[0] )
    v14.m128_f32[0] = (float)(v15 - (_mm_movemask_ps(_mm_unpacklo_ps(v14, v14)) & 1));
  c[2] = (int)v14.m128_f32[0];
  c[3] = LOBYTE(c1->a) + ratio * (c2->a - c1->a) / (maxRatio | (maxRatio << 8));
}

// File Line: 264
// RVA: 0x93D1E0
void __fastcall Scaleform::Render::GradientRamp::GradientRamp(
        Scaleform::Render::GradientRamp *this,
        Scaleform::Render::GradientRecord *records,
        unsigned int recordCount,
        float gamma)
{
  Scaleform::Render::GradientRecord *v4; // r9
  int v6; // edx
  unsigned int Ratio; // r15d
  __int64 v8; // rcx
  Scaleform::Render::GradientRamp *v9; // rdi
  Scaleform::Render::GradientRecord *v10; // rcx
  Scaleform::Render::Color *p_ColorV; // rdi
  unsigned int v12; // r12d
  char r_high; // di^1
  char a_high; // r9^1
  char b_high; // r10^1
  char g_high; // r11^1
  unsigned int v17; // edx
  int v18; // r8d
  __int64 v19; // rbx
  int v20; // esi
  int v21; // r11d
  int v22; // edi
  int v23; // r14d
  char r; // cl
  int v25; // r12d
  __int64 v26; // r10
  int v27; // r9d
  int v28; // r15d
  int v29; // eax
  int v30; // eax
  int v31; // eax
  int v32; // eax
  __int64 v33; // rbx
  int v34; // esi
  int maxRatio; // r12d
  __int64 v36; // r14
  bool v37; // zf
  int v38; // edx
  char *v39; // rdi
  __int64 j; // rcx
  int v41; // eax
  Scaleform::Render::GradientRamp *v42; // rdi
  __int64 i; // rcx
  char c[4]; // [rsp+30h] [rbp-69h] BYREF
  Scaleform::Render::GradientRamp::ColorType result; // [rsp+38h] [rbp-61h] BYREF
  unsigned int v46; // [rsp+40h] [rbp-59h]
  Scaleform::Render::GradientRamp::ColorType c2; // [rsp+48h] [rbp-51h] BYREF
  unsigned int v48; // [rsp+50h] [rbp-49h]
  int v49; // [rsp+54h] [rbp-45h]
  int v50; // [rsp+58h] [rbp-41h]
  int v51; // [rsp+5Ch] [rbp-3Dh]
  int v52; // [rsp+60h] [rbp-39h]
  char v53; // [rsp+68h] [rbp-31h] BYREF
  int v54; // [rsp+6Ch] [rbp-2Dh]
  Scaleform::Render::GradientRecord *v55; // [rsp+70h] [rbp-29h]
  __int64 v56; // [rsp+78h] [rbp-21h]
  Scaleform::Render::Color *v57; // [rsp+80h] [rbp-19h]
  Scaleform::Render::GradientRamp::ColorType v58; // [rsp+88h] [rbp-11h]
  char v59; // [rsp+101h] [rbp+68h]
  char v60; // [rsp+109h] [rbp+70h]
  char v61; // [rsp+111h] [rbp+78h]

  v4 = records;
  if ( !recordCount || !records )
  {
    v53 = 0;
    v54 = -16777216;
    recordCount = 1;
    v4 = (Scaleform::Render::GradientRecord *)&v53;
  }
  c[0] = v4->ColorV.Channels.Red;
  c[1] = v4->ColorV.Channels.Green;
  c[2] = v4->ColorV.Channels.Blue;
  c[3] = v4->ColorV.Channels.Alpha;
  if ( recordCount <= 1 )
  {
    v41 = *(_DWORD *)c;
    v42 = this;
    for ( i = 256i64; i; --i )
    {
      *(_DWORD *)v42->Ramp = v41;
      v42 = (Scaleform::Render::GradientRamp *)((char *)v42 + 4);
    }
    return;
  }
  v6 = *(_DWORD *)c;
  Ratio = (unsigned __int8)v4->Ratio;
  if ( v4->Ratio )
  {
    v8 = (unsigned __int8)v4->Ratio;
    v9 = this;
    while ( v8 )
    {
      *(_DWORD *)v9->Ramp = v6;
      v9 = (Scaleform::Render::GradientRamp *)((char *)v9 + 4);
      --v8;
    }
  }
  v10 = v4 + 1;
  p_ColorV = &v4[1].ColorV;
  v55 = v4 + 1;
  v57 = &v4[1].ColorV;
  v56 = recordCount - 1;
  do
  {
    v12 = (unsigned __int8)v10->Ratio;
    if ( v12 < Ratio )
      v12 = Ratio;
    v46 = v12;
    Scaleform::Render::GradientRamp::applyGammaDir(&result, p_ColorV - 2, gamma);
    Scaleform::Render::GradientRamp::applyGammaDir(&c2, p_ColorV, gamma);
    r_high = HIBYTE(c2.r);
    a_high = HIBYTE(c2.a);
    b_high = HIBYTE(c2.b);
    g_high = HIBYTE(c2.g);
    v17 = v12 - Ratio;
    v58 = c2;
    v61 = HIBYTE(c2.a);
    v59 = HIBYTE(c2.b);
    v60 = HIBYTE(c2.g);
    if ( gamma == 1.0 )
    {
      if ( Ratio >= v12 )
        goto LABEL_23;
      v18 = (v17 - 1) | ((v17 - 1) << 8);
      if ( v18 < 1 )
        v18 = 1;
      v49 = c2.a - result.a;
      v19 = 4 * Ratio;
      v20 = 0;
      v50 = c2.b - result.b;
      v21 = v49;
      v22 = v50;
      v23 = 0;
      v52 = c2.g - result.g;
      r = result.r;
      v25 = 0;
      v26 = v17;
      v51 = c2.r - result.r;
      v27 = 0;
      v48 = v17 + Ratio;
      v28 = v52;
      do
      {
        v29 = v27;
        v27 += v51;
        c[0] = r + v29 / v18;
        v30 = v25;
        v25 += v28;
        c[1] = LOBYTE(result.g) + v30 / v18;
        v31 = v23;
        v23 += v22;
        c[2] = LOBYTE(result.b) + v31 / v18;
        v32 = v20;
        v20 += v21;
        c[3] = LOBYTE(result.a) + v32 / v18;
        *(_DWORD *)&this->Ramp[v19] = *(_DWORD *)c;
        v19 = (unsigned int)(v19 + 4);
        --v26;
      }
      while ( v26 );
      r_high = HIBYTE(v58.r);
      Ratio = v48;
    }
    else
    {
      if ( Ratio >= v12 )
        goto LABEL_23;
      v33 = 4 * Ratio;
      v34 = 0;
      maxRatio = v17 - 1;
      Ratio += v17;
      v36 = v17;
      do
      {
        Scaleform::Render::GradientRamp::blendColors(c, &result, &c2, v34++, maxRatio, 1.0 / gamma);
        *(_DWORD *)&this->Ramp[v33] = *(_DWORD *)c;
        v33 = (unsigned int)(v33 + 4);
        --v36;
      }
      while ( v36 );
    }
    g_high = v60;
    b_high = v59;
    a_high = v61;
    v12 = v46;
LABEL_23:
    c[0] = r_high;
    v10 = v55 + 1;
    p_ColorV = v57 + 2;
    v37 = v56-- == 1;
    c[1] = g_high;
    c[2] = b_high;
    v57 += 2;
    c[3] = a_high;
    ++v55;
  }
  while ( !v37 );
  if ( v12 < 0x100 )
  {
    v38 = *(_DWORD *)c;
    v39 = &this->Ramp[4 * v12];
    for ( j = 256 - v12; j; --j )
    {
      *(_DWORD *)v39 = v38;
      v39 += 4;
    }
  }
}

// File Line: 365
// RVA: 0x992730
void __fastcall Scaleform::Render::FocalRadialGradient::Init(
        Scaleform::Render::FocalRadialGradient *this,
        float r,
        float fx,
        float fy)
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
void __fastcall Scaleform::Render::GradientImage::GradientImage(
        Scaleform::Render::GradientImage *this,
        Scaleform::Render::PrimitiveFillManager *mng,
        Scaleform::Render::GradientData *data,
        float morphRatio)
{
  unsigned int v5; // eax

  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountVImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountVImpl,3>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseV<Scaleform::Render::Image,3>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::ImageBase::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::Image::`vftable;
  this->pTexture.Value = 0i64;
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
      v5 = Scaleform::Render::GradientData::CalcImageSize(data);
      this->Size.Height = v5;
      this->Size.Width = v5;
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
  Scaleform::Render::PrimitiveFillManager *pManager; // rcx
  Scaleform::Render::GradientData *pObject; // rcx
  Scaleform::Render::GradientImage *key; // [rsp+48h] [rbp+10h] BYREF

  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::GradientImage::`vftable;
  pManager = this->pManager;
  if ( pManager )
  {
    key = this;
    Scaleform::HashSetBase<Scaleform::Render::GradientImage *,Scaleform::Render::GradientImage::PtrHashFunctor,Scaleform::Render::GradientImage::PtrHashFunctor,Scaleform::AllocatorLH<Scaleform::Render::GradientImage *,2>,Scaleform::HashsetCachedEntry<Scaleform::Render::GradientImage *,Scaleform::Render::GradientImage::PtrHashFunctor>>::RemoveAlt<Scaleform::Render::GradientImage *>(
      &pManager->Gradients,
      &key);
  }
  pObject = this->pData.pObject;
  if ( pObject && !_InterlockedDecrement(&pObject->RefCount) )
    pObject->vfptr->__vecDelDtor(pObject, 1u);
  Scaleform::Render::Image::~Image(this);
}

// File Line: 437
// RVA: 0x96AE30
char __fastcall Scaleform::Render::GradientImage::Decode(
        Scaleform::Render::GradientImage *this,
        Scaleform::Render::ImageData *pdest,
        void (__fastcall *copyScanline)(char *, const char *, unsigned __int64, Scaleform::Render::Palette *, void *),
        void *arg)
{
  unsigned int v7; // edi
  Scaleform::Render::ImagePlane *pPlanes; // rdx
  char *pData; // r14
  Scaleform::Render::GradientData *pObject; // r13
  Scaleform::Render::GradientData *pMorphTo; // r8
  float v12; // xmm3_4
  __int64 v13; // r8
  unsigned int Height; // ecx
  __int64 v15; // rsi
  int v16; // ebx
  unsigned int Width; // edx
  __int64 v18; // rcx
  Scaleform::Render::GradientRecord **p_pRecords; // rdi
  void (__fastcall *v20)(char *, Scaleform::Render::GradientRecord **, _QWORD, _QWORD, void *); // rdi
  signed int v21; // eax
  float v22; // xmm7_4
  float v23; // xmm8_4
  unsigned int v24; // esi
  int v25; // ebx
  float v26; // xmm9_4
  float v27; // xmm13_4
  float v28; // xmm14_4
  float v29; // xmm11_4
  float v30; // xmm12_4
  void (__fastcall *v31)(char *, Scaleform::Render::GradientRecord **, _QWORD, _QWORD, void *); // r14
  int v32; // edx
  _DWORD *v33; // rdi
  __m128 v34; // xmm0
  __m128 v35; // xmm1
  int v36; // ecx
  int v37; // eax
  float v38; // xmm0_4
  float v39; // xmm2_4
  __m128 v40; // xmm3
  int v41; // ecx
  int v42; // eax
  __int64 v43; // rdi
  Scaleform::Render::ImagePlane p; // [rsp+30h] [rbp-98h] BYREF
  Scaleform::Render::GradientData v46; // [rsp+50h] [rbp-78h] BYREF
  Scaleform::Render::GradientRamp v47; // [rsp+468h] [rbp+3A0h] BYREF
  unsigned __int64 Pitch; // [rsp+948h] [rbp+880h]
  char *v49; // [rsp+950h] [rbp+888h]
  void (__fastcall *v50)(char *, Scaleform::Render::GradientRecord **, _QWORD, _QWORD, void *); // [rsp+958h] [rbp+890h]

  *(_QWORD *)&v46.LinearRGB = -2i64;
  v7 = 0;
  memset(&p, 0, sizeof(p));
  if ( pdest->RawPlaneCount )
  {
    pPlanes = pdest->pPlanes;
    p.Width = pPlanes->Width;
    p.Height = pPlanes->Height;
    Pitch = pPlanes->Pitch;
    p.Pitch = Pitch;
    p.DataSize = pPlanes->DataSize;
    pData = pPlanes->pData;
    p.pData = pData;
  }
  else
  {
    Scaleform::Render::ImagePlane::GetMipLevel(&pdest->pPlanes[0 % 0u], pdest->Format, 0 / 0u, &p, 0 % 0u);
    pData = p.pData;
    Pitch = p.Pitch;
  }
  pObject = this->pData.pObject;
  if ( pObject )
  {
    pMorphTo = pObject->pMorphTo;
    v46.RefCount = 1;
    v46.vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::GradientData::`vftable;
    *(_DWORD *)&v46.LinearRGB = 0;
    v46.pRecords = 0i64;
    v46.FocalRatio = 0.0;
    v46.pMorphTo = 0i64;
    if ( pMorphTo )
    {
      Scaleform::Render::GradientData::SetLerp(&v46, pObject, pMorphTo, this->MorphRatio);
      pObject = &v46;
    }
    if ( pObject->LinearRGB )
      v12 = FLOAT_2_1700001;
    else
      v12 = *(float *)&FLOAT_1_0;
    Scaleform::Render::GradientRamp::GradientRamp(&v47, pObject->pRecords, pObject->RecordCount, v12);
    Height = this->Size.Height;
    v15 = Pitch * (Height - 1);
    if ( pObject->Type )
    {
      v16 = *(_DWORD *)&v47.Ramp[1020];
      Width = this->Size.Width;
      if ( Width )
      {
        v18 = Width;
        p_pRecords = &v46.pRecords;
        while ( v18 )
        {
          *(_DWORD *)p_pRecords = v16;
          p_pRecords = (Scaleform::Render::GradientRecord **)((char *)p_pRecords + 4);
          --v18;
        }
      }
      v20 = v50;
      v50(pData, &v46.pRecords, 4 * Width, 0i64, arg);
      v20(&pData[v15], &v46.pRecords, 4 * this->Size.Width, 0i64, arg);
      v21 = this->Size.Width;
      v22 = (float)v21 * 0.5;
      v23 = v22 - 1.0;
      v24 = v21 - 1;
      LODWORD(v46.pRecords) = v16;
      *(_DWORD *)((char *)&v46.RecordCount + (unsigned int)(4 * v21) + 2) = v16;
      if ( pObject->Type == 2 )
        Scaleform::Render::FocalRadialGradient::Init(
          (Scaleform::Render::FocalRadialGradient *)&p.pData,
          v23,
          pObject->FocalRatio * v23,
          0.0);
      v49 = &pData[Pitch];
      v25 = 1;
      if ( v24 > 1 )
      {
        v26 = 1.0 / v23;
        v27 = *(float *)&v46.RefCount;
        v28 = *((float *)&v46.vfptr + 1);
        v29 = *(float *)&v46.vfptr;
        v30 = *((float *)&p.pData + 1);
        v31 = v50;
        do
        {
          v32 = 1;
          v33 = (_DWORD *)&v46.pRecords + 1;
          if ( pObject->Type == 1 )
          {
            do
            {
              v34 = 0i64;
              v34.m128_f32[0] = (float)((float)((float)((float)v32 - v22) + 0.5)
                                      * (float)((float)((float)v32 - v22) + 0.5))
                              + (float)((float)((float)((float)v25 - v22) + 0.5)
                                      * (float)((float)((float)v25 - v22) + 0.5));
              v35 = _mm_sqrt_ps(v34);
              v35.m128_f32[0] = (float)((float)(v35.m128_f32[0] * 256.0) * v26) + 0.5;
              v36 = (int)v35.m128_f32[0];
              if ( (int)v35.m128_f32[0] != 0x80000000 && (float)v36 != v35.m128_f32[0] )
                v35.m128_f32[0] = (float)(v36 - (_mm_movemask_ps(_mm_unpacklo_ps(v35, v35)) & 1));
              v37 = (int)v35.m128_f32[0];
              if ( (int)v35.m128_f32[0] > 255 )
                v37 = 255;
              *v33 = *(_DWORD *)&v47.Ramp[4 * v37];
              ++v32;
              ++v33;
            }
            while ( v32 < v24 );
          }
          else
          {
            do
            {
              v39 = (float)((float)((float)v32 - v22) + 0.5) - v30;
              v40 = 0i64;
              v38 = (float)((float)((float)v25 - v22) + 0.5) - v29;
              v40.m128_f32[0] = (float)((float)((float)((float)(fsqrt(COERCE_FLOAT(COERCE_UNSIGNED_INT(
                                                                                     (float)((float)((float)(v39 * v39) + (float)(v38 * v38))
                                                                                           * v28)
                                                                                   - (float)((float)((float)(v29 * v39) - (float)(v30 * v38))
                                                                                           * (float)((float)(v29 * v39) - (float)(v30 * v38)))) & _xmm))
                                                              + (float)((float)(v30 * v39) + (float)(v29 * v38)))
                                                      * v27)
                                              * 256.0)
                                      * v26)
                              + 0.5;
              v41 = (int)v40.m128_f32[0];
              if ( (int)v40.m128_f32[0] != 0x80000000 && (float)v41 != v40.m128_f32[0] )
                v40.m128_f32[0] = (float)(v41 - (_mm_movemask_ps(_mm_unpacklo_ps(v40, v40)) & 1));
              v42 = (int)v40.m128_f32[0];
              if ( (int)v40.m128_f32[0] > 255 )
                v42 = 255;
              *v33 = *(_DWORD *)&v47.Ramp[4 * v42];
              ++v32;
              ++v33;
            }
            while ( v32 < v24 );
          }
          v43 = (__int64)v49;
          v31(v49, &v46.pRecords, 4 * this->Size.Width, 0i64, arg);
          v49 = (char *)(Pitch + v43);
          ++v25;
          v13 = 255i64;
        }
        while ( v25 < v24 );
      }
    }
    else if ( Height )
    {
      do
      {
        copyScanline(pData, v47.Ramp, 4 * this->Size.Width, 0i64, arg);
        ++v7;
      }
      while ( v7 < this->Size.Height );
    }
    v46.vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::GradientData::`vftable;
    if ( v46.pRecords )
      ((void (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::Render::GradientRecord *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
        Scaleform::Memory::pGlobalHeap,
        v46.pRecords,
        v13);
    v46.vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  }
  else
  {
    LODWORD(v46.pRecords) = 0;
    copyScanline(pData, (const char *)&v46.pRecords, 4ui64, 0i64, arg);
  }
  return 1;
} (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  }
  else
  {
    LODWORD(v46.pRecord

// File Line: 538
// RVA: 0x98DA30
Scaleform::Render::Texture *__fastcall Scaleform::Render::GradientImage::GetTexture(
        Scaleform::Render::GradientImage *this,
        Scaleform::Render::TextureManager *pmanager)
{
  Scaleform::Render::TextureManager *pObject; // rax
  Scaleform::Render::Texture *result; // rax
  Scaleform::RefCountImplCoreVtbl *vfptr; // rdi
  unsigned int v7; // eax

  if ( this->pTexture.Value )
  {
    pObject = (Scaleform::Render::TextureManager *)this->pTexture.Value->pManagerLocks.pObject;
    if ( pObject )
      pObject = (Scaleform::Render::TextureManager *)pObject->Scaleform::Render::ImageUpdateSync::vfptr;
    if ( pObject == pmanager )
      return this->pTexture.Value;
  }
  if ( !pmanager )
    return 0i64;
  this->pTexture.Value = 0i64;
  vfptr = pmanager->Scaleform::RefCountBase<Scaleform::Render::TextureManager,72>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,72>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr;
  v7 = ((__int64 (__fastcall *)(Scaleform::Render::GradientImage *))this->vfptr[4].__vecDelDtor)(this);
  result = (Scaleform::Render::Texture *)((__int64 (__fastcall *)(Scaleform::Render::TextureManager *, _QWORD, __int64, Scaleform::Render::Size<unsigned long> *, int, Scaleform::Render::GradientImage *, _QWORD))vfptr[1].__vecDelDtor)(
                                           pmanager,
                                           v7,
                                           1i64,
                                           &this->Size,
                                           1,
                                           this,
                                           0i64);
  this->pTexture.Value = result;
  return result;
}

