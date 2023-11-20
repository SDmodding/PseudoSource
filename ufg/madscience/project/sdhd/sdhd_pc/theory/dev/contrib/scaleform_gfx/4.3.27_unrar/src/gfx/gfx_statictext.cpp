// File Line: 57
// RVA: 0x8F9CF0
void __fastcall Scaleform::GFx::StaticTextRecord::Read(Scaleform::GFx::StaticTextRecord *this, Scaleform::GFx::Stream *in, int glyphCount, int glyphBits, int advanceBits)
{
  __int64 v5; // r15
  Scaleform::GFx::Stream *v6; // r12
  int v7; // er13
  Scaleform::GFx::StaticTextRecord *v8; // rsi
  __int64 i; // rdi
  Scaleform::GFx::StaticTextRecord::GlyphEntry *v10; // rbx
  signed int v11; // eax

  v5 = glyphCount;
  v6 = in;
  v7 = glyphBits;
  v8 = this;
  Scaleform::ArrayData<Scaleform::GFx::StaticTextRecord::GlyphEntry,Scaleform::AllocatorLH<Scaleform::GFx::StaticTextRecord::GlyphEntry,258>,Scaleform::ArrayDefaultPolicy>::Resize(
    &this->Glyphs.Data,
    glyphCount);
  for ( i = 0i64; i < v5; *((float *)&v8->Glyphs.Data.Data[i] - 1) = (float)v11 )
  {
    v10 = v8->Glyphs.Data.Data;
    v10[i].GlyphIndex = Scaleform::GFx::Stream::ReadUInt(v6, v7);
    v11 = Scaleform::GFx::Stream::ReadUInt(v6, advanceBits);
    if ( __ROR4__(__ROL4__(1, advanceBits), 1) & v11 )
      v11 |= -1 << advanceBits;
    ++i;
  }
}

// File Line: 68
// RVA: 0x8D6570
float __fastcall Scaleform::GFx::StaticTextRecord::GetCumulativeAdvance(Scaleform::GFx::StaticTextRecord *this)
{
  unsigned __int64 v1; // r8
  unsigned __int64 v2; // rdx
  Scaleform::GFx::StaticTextRecord *v3; // r9
  float v4; // xmm1_4
  Scaleform::GFx::StaticTextRecord::GlyphEntry *v5; // rcx
  __m128 v6; // xmm4
  __m128 v7; // xmm0
  __m128 v8; // xmm2
  __m128 v9; // xmm3
  __m128 v10; // xmm1
  __m128 v11; // xmm1

  v1 = this->Glyphs.Data.Size;
  v2 = 0i64;
  v3 = this;
  v4 = 0.0;
  if ( v1 )
  {
    if ( v1 >= 8 )
    {
      v5 = this->Glyphs.Data.Data;
      v6 = 0i64;
      do
      {
        v7 = (__m128)LODWORD(v5[v2 + 2].GlyphAdvance);
        v8 = _mm_unpacklo_ps((__m128)LODWORD(v5[v2 + 1].GlyphAdvance), (__m128)LODWORD(v5[v2 + 3].GlyphAdvance));
        v9 = (__m128)LODWORD(v5[v2].GlyphAdvance);
        v10 = (__m128)LODWORD(v5[v2 + 7].GlyphAdvance);
        v2 += 8i64;
        v6 = _mm_add_ps(
               _mm_add_ps(v6, _mm_unpacklo_ps(_mm_unpacklo_ps(v9, v7), v8)),
               _mm_unpacklo_ps(
                 _mm_unpacklo_ps((__m128)*((unsigned int *)&v5[v2 - 3] - 1), (__m128)*((unsigned int *)&v5[v2 - 1] - 1)),
                 _mm_unpacklo_ps((__m128)*((unsigned int *)&v5[v2 - 2] - 1), v10)));
      }
      while ( v2 < v1 - (v1 & 7) );
      v11 = _mm_add_ps(_mm_movehl_ps(v6, v6), v6);
      v4 = v11.m128_f32[0] + COERCE_FLOAT(_mm_shuffle_ps(v11, v11, 245));
    }
    for ( ; v2 < v1; ++v2 )
      v4 = v4 + v3->Glyphs.Data.Data[v2].GlyphAdvance;
  }
  return v4;
}

// File Line: 78
// RVA: 0x8BC180
void __fastcall Scaleform::GFx::StaticTextRecordList::Clear(Scaleform::GFx::StaticTextRecordList *this)
{
  unsigned __int64 v1; // rbp
  Scaleform::GFx::StaticTextRecordList *v2; // rdi
  unsigned __int64 v3; // rbx
  Scaleform::GFx::StaticTextRecord *v4; // rsi

  v1 = this->Records.Data.Size;
  v2 = this;
  v3 = 0i64;
  if ( v1 )
  {
    do
    {
      v4 = v2->Records.Data.Data[v3];
      if ( v4 )
      {
        Scaleform::GFx::StaticTextRecord::~StaticTextRecord(v2->Records.Data.Data[v3]);
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v4);
      }
      ++v3;
    }
    while ( v3 < v1 );
  }
  if ( v2->Records.Data.Size > 0 && v2->Records.Data.Policy.Capacity & 0xFFFFFFFFFFFFFFFEui64 )
  {
    if ( v2->Records.Data.Data )
    {
      ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      v2->Records.Data.Data = 0i64;
    }
    v2->Records.Data.Policy.Capacity = 0i64;
  }
  v2->Records.Data.Size = 0i64;
}

// File Line: 85
// RVA: 0x8B1D80
Scaleform::GFx::StaticTextRecord *__fastcall Scaleform::GFx::StaticTextRecordList::AddRecord(Scaleform::GFx::StaticTextRecordList *this)
{
  Scaleform::ArrayDataBase<Scaleform::GFx::StaticTextRecord::GlyphEntry,Scaleform::AllocatorLH<Scaleform::GFx::StaticTextRecord::GlyphEntry,258>,Scaleform::ArrayDefaultPolicy> *v1; // rdi
  _QWORD *v2; // rax
  _QWORD *v3; // rbx
  signed __int64 v4; // rax
  unsigned __int64 v5; // rax
  unsigned __int64 v6; // rsi
  unsigned __int64 v7; // r8
  Scaleform::GFx::StaticTextRecord::GlyphEntry *v8; // rax
  int v10; // [rsp+58h] [rbp+10h]
  _QWORD *v11; // [rsp+60h] [rbp+18h]
  __int64 v12; // [rsp+68h] [rbp+20h]

  v1 = (Scaleform::ArrayDataBase<Scaleform::GFx::StaticTextRecord::GlyphEntry,Scaleform::AllocatorLH<Scaleform::GFx::StaticTextRecord::GlyphEntry,258>,Scaleform::ArrayDefaultPolicy> *)this;
  v10 = 258;
  v2 = (_QWORD *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::GFx::StaticTextRecordList *, signed __int64, int *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
                   Scaleform::Memory::pGlobalHeap,
                   this,
                   64i64,
                   &v10,
                   -2i64);
  v3 = v2;
  v11 = v2;
  if ( v2 )
  {
    *v2 = 0i64;
    v2[1] = 0i64;
    v2[2] = 0i64;
    v4 = (signed __int64)(v2 + 3);
    v12 = v4;
    *(_DWORD *)v4 = 0;
    *(_QWORD *)(v4 + 8) = 0i64;
    *(_QWORD *)((char *)v3 + 44) = 0i64;
    *((_DWORD *)v3 + 13) = 1065353216;
    *((_WORD *)v3 + 28) = 0;
  }
  else
  {
    v3 = 0i64;
  }
  if ( !v3 )
    return (Scaleform::GFx::StaticTextRecord *)v3;
  v5 = v1->Size;
  v6 = v5 + 1;
  if ( v5 + 1 >= v5 )
  {
    if ( v6 <= v1->Policy.Capacity )
      goto LABEL_11;
    v7 = v6 + (v6 >> 2);
  }
  else
  {
    if ( v6 >= v1->Policy.Capacity >> 1 )
      goto LABEL_11;
    v7 = v5 + 1;
  }
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ButtonActionBase>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ButtonActionBase>,258>,Scaleform::ArrayDefaultPolicy>::Reserve(
    v1,
    v1,
    v7);
LABEL_11:
  v1->Size = v6;
  v8 = &v1->Data[v6 - 1];
  if ( v8 )
    *v8 = (Scaleform::GFx::StaticTextRecord::GlyphEntry)v3;
  return (Scaleform::GFx::StaticTextRecord *)v3;
}

// File Line: 101
// RVA: 0x8F9660
void __fastcall Scaleform::GFx::StaticTextDef::Read(Scaleform::GFx::StaticTextDef *this, Scaleform::GFx::LoadProcess *p, Scaleform::GFx::TagType tagType)
{
  Scaleform::GFx::StaticTextDef *v3; // rdi
  Scaleform::GFx::Stream *v4; // rsi
  double v5; // xmm1_8
  __m128d v6; // xmm3
  __m128d v7; // xmm2
  __int64 v8; // rdx
  int v9; // ecx
  int v10; // er13
  __int64 v11; // rdx
  unsigned int v12; // ecx
  unsigned int v13; // er14
  char v14; // di
  float v15; // xmm9_4
  __int64 v16; // r15
  float v17; // xmm6_4
  float v18; // xmm7_4
  float v19; // xmm10_4
  __int64 v20; // rdx
  signed int v21; // ecx
  __int64 v22; // r12
  int v23; // edi
  char v24; // r14
  char v25; // r13
  char v26; // r12
  __int64 v27; // r8
  unsigned __int16 v28; // cx
  unsigned int v29; // edi
  Scaleform::GFx::Resource *v30; // rcx
  __int64 v31; // rdi
  Scaleform::GFx::ResourceLibBase *v32; // rcx
  Scaleform::GFx::Resource *v33; // rdi
  Scaleform::GFx::ResourceLibBase *v34; // rcx
  __int64 v35; // rdx
  char v36; // cl
  __int64 v37; // r9
  __int16 v38; // r8
  __int64 v39; // r9
  __int16 v40; // r8
  bool v41; // zf
  __int64 v42; // r9
  unsigned __int16 v43; // r8
  __int64 v44; // rdi
  Scaleform::GFx::StaticTextRecord *v45; // rax
  Scaleform::GFx::StaticTextRecord *v46; // rdi
  Scaleform::GFx::Resource *v47; // r14
  Scaleform::GFx::ResourceLibBase *v48; // rcx
  __int64 v49; // rbx
  Scaleform::GFx::ResourceLibBase *v50; // rcx
  Scaleform::Render::Color pc; // [rsp+0h] [rbp-7Dh]
  Scaleform::GFx::ResourceHandle::HandleType v52; // [rsp+4h] [rbp-79h]
  Scaleform::GFx::Resource *v53; // [rsp+Ch] [rbp-71h]
  int v54; // [rsp+14h] [rbp-69h]
  Scaleform::GFx::ResourceHandle phandle; // [rsp+1Ch] [rbp-61h]
  Scaleform::GFx::ResourceId rid[2]; // [rsp+2Ch] [rbp-51h]
  __int64 v57; // [rsp+34h] [rbp-49h]
  int v58; // [rsp+3Ch] [rbp-41h]
  __int64 v59; // [rsp+E4h] [rbp+67h]
  __int64 v60; // [rsp+ECh] [rbp+6Fh]
  int v61; // [rsp+F4h] [rbp+77h]
  char v62; // [rsp+FCh] [rbp+7Fh]

  v57 = -2i64;
  v3 = this;
  v4 = p->pAltStream;
  if ( !v4 )
    v4 = &p->ProcessInfo.Stream;
  Scaleform::GFx::Stream::ReadRect(v4, &this->TextRect);
  v5 = v3->TextRect.x2;
  v6 = _mm_cvtps_pd((__m128)LODWORD(v3->TextRect.y1));
  v7 = _mm_cvtps_pd((__m128)LODWORD(v3->TextRect.x1));
  *(double *)&rid[0].Id = v3->TextRect.y2;
  *(double *)&phandle.8 = v5;
  Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
    (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&v4->vfptr,
    "  TextRect = { l: %f, t: %f, r: %f, b: %f }\n");
  Scaleform::GFx::Stream::ReadMatrix(v4, &v3->MatrixPriv);
  Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
    (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&v4->vfptr,
    "  mat:\n");
  v4->UnusedBits = 0;
  if ( (signed int)(v4->DataSize - v4->Pos) < 1 )
    Scaleform::GFx::Stream::PopulateBuffer(v4, 1);
  v8 = v4->Pos;
  v9 = (unsigned __int8)v4->pBuffer[v8];
  v4->Pos = v8 + 1;
  v10 = v9;
  v54 = v9;
  v4->UnusedBits = 0;
  if ( (signed int)(v4->DataSize - (v8 + 1)) < 1 )
    Scaleform::GFx::Stream::PopulateBuffer(v4, 1);
  v11 = v4->Pos;
  v12 = (unsigned __int8)v4->pBuffer[v11];
  v4->Pos = v11 + 1;
  v13 = v12;
  HIDWORD(v57) = v12;
  Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
    (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&v4->vfptr,
    "begin text records\n");
  v14 = 0;
  v15 = 0.0;
  LOWORD(v57) = 0;
  v52 = 0;
  v16 = 0i64;
  v53 = 0i64;
  v17 = 0.0;
  v18 = 0.0;
  v19 = 0.0;
  while ( 1 )
  {
    v4->UnusedBits = 0;
    if ( (signed int)(v4->DataSize - v4->Pos) < 1 )
      Scaleform::GFx::Stream::PopulateBuffer(v4, 1);
    v20 = v4->Pos;
    v21 = (unsigned __int8)v4->pBuffer[v20];
    v4->Pos = v20 + 1;
    v22 = (unsigned int)v21;
    if ( !(_BYTE)v21 )
      break;
    if ( v14 )
    {
      v14 = 0;
      v62 = 0;
      if ( v17 >= 0.0 || v19 <= 0.0 )
      {
        v45 = Scaleform::GFx::StaticTextRecordList::AddRecord((Scaleform::GFx::StaticTextRecordList *)(v59 + 80));
        v46 = v45;
        if ( v45 )
        {
          v19 = v17;
          v45->Offset.x = v18;
          v45->Offset.y = v17;
          if ( v52 == RH_Pointer && v16 )
          {
            _InterlockedExchangeAdd((volatile signed __int32 *)(v16 + 8), 1u);
            v16 = (__int64)v53;
          }
          if ( v45->pFont.HType == RH_Pointer )
          {
            v47 = v45->pFont.pResource;
            if ( v47 )
            {
              if ( !_InterlockedDecrement(&v47->RefCount.Value) )
              {
                v48 = v47->pLib;
                if ( v48 )
                {
                  v48->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v48->vfptr, (unsigned int)v47);
                  v47->pLib = 0i64;
                }
                v47->vfptr->__vecDelDtor(v47, 1u);
              }
              v16 = (__int64)v53;
            }
            v13 = HIDWORD(v57);
          }
          v46->pFont.HType = v52;
          v46->pFont.pResource = (Scaleform::GFx::Resource *)v16;
          v46->TextHeight = v15;
          v46->ColorV = pc;
          v46->FontId = v57;
          Scaleform::GFx::StaticTextRecord::Read(v46, v4, v22, v10, v13);
          v18 = v18 + Scaleform::GFx::StaticTextRecord::GetCumulativeAdvance(v46);
        }
        Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
          (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&v4->vfptr,
          "  GlyphRecords: count = %d\n");
        v14 = v62;
      }
      else
      {
        Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
          (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&v4->vfptr,
          "  Negative Y-offset, 16-bit value rollover, skipping the line...\n");
        if ( (signed int)v22 > 0 )
        {
          v44 = v22;
          do
          {
            Scaleform::GFx::Stream::ReadUInt(v4, v10);
            Scaleform::GFx::Stream::ReadUInt(v4, v13);
            --v44;
          }
          while ( v44 );
          v14 = v62;
        }
      }
    }
    else
    {
      v62 = 1;
      v23 = v21 >> 3;
      LOBYTE(v23) = (v21 >> 3) & 1;
      v58 = v23;
      v24 = (v21 >> 2) & 1;
      v25 = (v21 >> 1) & 1;
      v26 = v21 & 1;
      Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
        (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&v4->vfptr,
        "  text style change\n");
      if ( (_BYTE)v23 )
      {
        v4->UnusedBits = 0;
        if ( (signed int)(v4->DataSize - v4->Pos) < 2 )
          Scaleform::GFx::Stream::PopulateBuffer(v4, 2);
        v27 = v4->Pos;
        LOWORD(v57) = (unsigned __int8)v4->pBuffer[v27] | (unsigned __int16)((unsigned __int8)v4->pBuffer[(unsigned int)(v27 + 1)] << 8);
        v28 = v57;
        v4->Pos = v27 + 2;
        v29 = v28;
        Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
          (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&v4->vfptr,
          "  HasFont: font id = %d\n");
        phandle.HType = 0;
        phandle.pResource = 0i64;
        rid[0].Id = v29;
        Scaleform::GFx::MovieDataDef::LoadTaskData::GetResourceHandle(
          *(Scaleform::GFx::MovieDataDef::LoadTaskData **)(v60 + 56),
          &phandle,
          (__int64)rid);
        v30 = phandle.pResource;
        if ( phandle.HType == RH_Pointer && phandle.pResource )
        {
          _InterlockedExchangeAdd(&phandle.pResource->RefCount.Value, 1u);
          v16 = (__int64)v53;
          v30 = phandle.pResource;
        }
        if ( v52 == RH_Pointer && v16 )
        {
          if ( !_InterlockedDecrement((volatile signed __int32 *)(v16 + 8)) )
          {
            v31 = (__int64)v53;
            v32 = v53->pLib;
            if ( v32 )
            {
              v32->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v32->vfptr, (unsigned int)v53);
              *(_QWORD *)(v31 + 16) = 0i64;
            }
            (**(void (__fastcall ***)(__int64, signed __int64))v31)(v31, 1i64);
          }
          v30 = phandle.pResource;
        }
        v52 = phandle.HType;
        v16 = (__int64)v30;
        v53 = v30;
        if ( phandle.HType == RH_Pointer && v30 )
        {
          if ( !_InterlockedDecrement(&v30->RefCount.Value) )
          {
            v33 = phandle.pResource;
            v34 = phandle.pResource->pLib;
            if ( v34 )
            {
              v34->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v34->vfptr, (unsigned int)phandle.pResource);
              v33->pLib = 0i64;
            }
            v33->vfptr->__vecDelDtor(v33, 1u);
          }
          v16 = (__int64)v53;
        }
        LOBYTE(v23) = v58;
      }
      if ( v24 )
      {
        Scaleform::GFx::Stream::ReadRgb(v4, &pc);
        if ( v61 != 11 )
        {
          v4->UnusedBits = 0;
          if ( (signed int)(v4->DataSize - v4->Pos) < 1 )
            Scaleform::GFx::Stream::PopulateBuffer(v4, 1);
          v35 = v4->Pos;
          v36 = v4->pBuffer[v35];
          v4->Pos = v35 + 1;
          pc.Channels.Alpha = v36;
        }
        Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
          (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&v4->vfptr,
          "  HasColor\n");
      }
      if ( v26 )
      {
        v4->UnusedBits = 0;
        if ( (signed int)(v4->DataSize - v4->Pos) < 2 )
          Scaleform::GFx::Stream::PopulateBuffer(v4, 2);
        v37 = v4->Pos;
        v38 = (unsigned __int8)v4->pBuffer[v37] | (unsigned __int16)((unsigned __int8)v4->pBuffer[(unsigned int)(v37 + 1)] << 8);
        v4->Pos = v37 + 2;
        v18 = (float)v38;
        Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
          (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&v4->vfptr,
          "  XOffset = %g\n");
      }
      if ( v25 )
      {
        v4->UnusedBits = 0;
        if ( (signed int)(v4->DataSize - v4->Pos) < 2 )
          Scaleform::GFx::Stream::PopulateBuffer(v4, 2);
        v39 = v4->Pos;
        v40 = (unsigned __int8)v4->pBuffer[v39] | (unsigned __int16)((unsigned __int8)v4->pBuffer[(unsigned int)(v39 + 1)] << 8);
        v4->Pos = v39 + 2;
        v17 = (float)v40;
        Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
          (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&v4->vfptr,
          "  YOffset = %g\n");
      }
      v41 = (_BYTE)v23 == 0;
      v10 = v54;
      v13 = HIDWORD(v57);
      v14 = v62;
      if ( !v41 )
      {
        v4->UnusedBits = 0;
        if ( (signed int)(v4->DataSize - v4->Pos) < 2 )
          Scaleform::GFx::Stream::PopulateBuffer(v4, 2);
        v42 = v4->Pos;
        v43 = (unsigned __int8)v4->pBuffer[v42] | (unsigned __int16)((unsigned __int8)v4->pBuffer[(unsigned int)(v42 + 1)] << 8);
        v4->Pos = v42 + 2;
        v15 = (float)v43;
        Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
          (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&v4->vfptr,
          "  TextHeight = %g\n");
        v14 = v62;
      }
    }
  }
  Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
    (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&v4->vfptr,
    "end text records\n");
  if ( v52 == RH_Pointer && v16 && !_InterlockedDecrement((volatile signed __int32 *)(v16 + 8)) )
  {
    v49 = (__int64)v53;
    v50 = v53->pLib;
    if ( v50 )
    {
      v50->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v50->vfptr, (unsigned int)v53);
      *(_QWORD *)(v49 + 16) = 0i64;
    }
    (**(void (__fastcall ***)(__int64, signed __int64))v49)(v49, 1i64);
  }
}

// File Line: 247
// RVA: 0x8C5030
bool __fastcall Scaleform::GFx::StaticTextDef::DefPointTestLocal(Scaleform::GFx::StaticTextDef *this, Scaleform::Render::Point<float> *pt, bool testShape, Scaleform::GFx::DisplayObjectBase *pinst)
{
  float v4; // xmm0_4
  bool result; // al

  result = 0;
  if ( pt->x <= this->TextRect.x2 && pt->x >= this->TextRect.x1 )
  {
    v4 = pt->y;
    if ( v4 <= this->TextRect.y2 && v4 >= this->TextRect.y1 )
      result = 1;
  }
  return result;
}

// File Line: 259
// RVA: 0x89CFE0
void __fastcall Scaleform::GFx::StaticTextCharacter::StaticTextCharacter(Scaleform::GFx::StaticTextCharacter *this, Scaleform::GFx::StaticTextDef *pdef, Scaleform::GFx::MovieDefImpl *pbindingDefImpl, Scaleform::GFx::ASMovieRootBase *pasRoot)
{
  Scaleform::GFx::MovieDefImpl *v4; // rdi
  Scaleform::GFx::StaticTextDef *v5; // r14
  Scaleform::GFx::StaticTextCharacter *v6; // rsi
  float v7; // xmm3_4
  float v8; // xmm0_4
  float v9; // xmm1_4
  float v10; // xmm2_4
  unsigned int v11; // er12
  __int64 v12; // rcx
  Scaleform::GFx::StaticTextRecord *v13; // r13
  Scaleform::GFx::Resource *v14; // r15
  Scaleform::GFx::ImportData *volatile v15; // rsi
  Scaleform::GFx::StateBag *v16; // rbx
  unsigned int v17; // er15
  signed __int64 v18; // rdi
  signed __int64 v19; // rdi
  Scaleform::Log *v20; // r14
  Scaleform::Render::Text::LineBuffer *v21; // r14
  Scaleform::GFx::Resource *v22; // rdi
  unsigned __int64 v23; // rsi
  Scaleform::Render::Text::LineBuffer::Line *v24; // rax
  __int64 v25; // rdi
  bool v26; // zf
  int v27; // eax
  float v28; // xmm2_4
  float v29; // xmm3_4
  int v30; // xmm1_4
  float v31; // xmm4_4
  double v32; // xmm5_8
  float v33; // xmm3_4
  float v34; // xmm2_4
  signed int v35; // eax
  float v36; // xmm6_4
  float v37; // xmm2_4
  float v38; // xmm3_4
  int v39; // et1
  signed __int64 v40; // rsi
  Scaleform::Render::Text::LineBuffer::FormatDataEntry *v41; // rdx
  __int64 v42; // r8
  unsigned int v43; // er12
  __int64 v44; // r9
  unsigned int v45; // er15
  float v46; // er10
  Scaleform::GFx::Resource *v47; // rbx
  unsigned int v48; // edi
  __int64 v49; // r14
  signed int v50; // eax
  float v51; // xmm1_4
  signed int v52; // eax
  unsigned int v53; // edi
  int v54; // eax
  float v55; // xmm6_4
  signed int v56; // ecx
  int v57; // edx
  int v58; // ecx
  int v59; // eax
  float v60; // xmm2_4
  float v61; // xmm1_4
  Scaleform::GFx::Resource *v62; // rdi
  Scaleform::GFx::ResourceLibBase *v63; // rcx
  Scaleform::Log *v64; // rdi
  Scaleform::GFx::Resource *v65; // rdi
  Scaleform::GFx::ResourceLibBase *v66; // rcx
  Scaleform::Render::Rect<float> pr; // [rsp+30h] [rbp-98h]
  unsigned int v68; // [rsp+40h] [rbp-88h]
  unsigned int v69; // [rsp+44h] [rbp-84h]
  Scaleform::Render::Text::LineBuffer *v70; // [rsp+48h] [rbp-80h]
  void *v71; // [rsp+50h] [rbp-78h]
  Scaleform::GFx::ResourceId v72; // [rsp+58h] [rbp-70h]
  __int64 v73; // [rsp+5Ch] [rbp-6Ch]
  float v74; // [rsp+64h] [rbp-64h]
  __int128 v75; // [rsp+68h] [rbp-60h]
  Scaleform::Render::Matrix2x4<float> m; // [rsp+78h] [rbp-50h]
  Scaleform::Ptr<Scaleform::Log> v77; // [rsp+98h] [rbp-30h]
  int v78; // [rsp+A0h] [rbp-28h]
  Scaleform::GFx::ResourceBindData result; // [rsp+A8h] [rbp-20h]
  unsigned int v80; // [rsp+B8h] [rbp-10h]
  unsigned __int64 v81; // [rsp+C0h] [rbp-8h]
  Scaleform::Ptr<Scaleform::Log> v82; // [rsp+C8h] [rbp+0h]
  __int64 v83; // [rsp+D0h] [rbp+8h]
  Scaleform::Render::Text::LineBuffer *v84; // [rsp+D8h] [rbp+10h]
  unsigned int v85; // [rsp+F0h] [rbp+28h]
  unsigned int v86; // [rsp+F8h] [rbp+30h]
  Scaleform::GFx::StaticTextCharacter *v87; // [rsp+1C8h] [rbp+100h]
  Scaleform::GFx::StaticTextDef *v88; // [rsp+1D0h] [rbp+108h]
  Scaleform::GFx::StateBag *v89; // [rsp+1D8h] [rbp+110h]
  Scaleform::GFx::InteractiveObject *v90; // [rsp+1E8h] [rbp+120h]
  unsigned int *vars0; // [rsp+1F0h] [rbp+128h]

  v83 = -2i64;
  v4 = pbindingDefImpl;
  v5 = pdef;
  v6 = this;
  v80 = *vars0;
  v72.Id = v80;
  Scaleform::GFx::DisplayObjectBase::DisplayObjectBase(
    (Scaleform::GFx::DisplayObjectBase *)&this->vfptr,
    pasRoot,
    v90,
    (__int64)&v72);
  v6->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::GFx::DisplayObject::`vftable{for `Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>};
  v6->vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>Vtbl *)&Scaleform::GFx::DisplayObject::`vftable{for `Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>};
  v6->pNameHandle.pObject = 0i64;
  v6->pScrollRect = 0i64;
  v6->pMaskCharacter = 0i64;
  v6->Flags |= 0x100u;
  v6->Flags = 10;
  v6->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::GFx::StaticTextCharacter::`vftable{for `Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>};
  v6->vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>Vtbl *)&Scaleform::GFx::StaticTextCharacter::`vftable{for `Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>};
  if ( v5 )
    _InterlockedExchangeAdd(&v5->RefCount.Value, 1u);
  v6->pDef.pObject = v5;
  *(_QWORD *)&v6->OrigMatrix.M[0][0] = 1065353216i64;
  *(_QWORD *)&v6->OrigMatrix.M[0][2] = 0i64;
  v6->OrigMatrix.M[1][0] = 0.0;
  *(_QWORD *)&v6->OrigMatrix.M[1][1] = 1065353216i64;
  v6->OrigMatrix.M[1][3] = 0.0;
  v70 = &v6->TextGlyphRecords;
  Scaleform::Render::Text::LineBuffer::LineBuffer(&v6->TextGlyphRecords);
  Scaleform::Render::Text::TextFilter::TextFilter(&v6->Filter);
  v6->pHighlight = 0i64;
  v6->Flags = 0;
  v72.Id = LODWORD(v5->MatrixPriv.M[0][0]);
  *(float *)&v73 = v5->MatrixPriv.M[0][1];
  *(__int64 *)((char *)&v73 + 4) = *(_QWORD *)&v5->MatrixPriv.M[0][2];
  v75 = *(_OWORD *)&v5->MatrixPriv.M[1][0];
  LODWORD(m.M[0][0]) = v72;
  *(_QWORD *)&m.M[0][1] = v73;
  m.M[0][3] = v74;
  *(_OWORD *)&m.M[1][0] = v75;
  Scaleform::Render::Matrix2x4<float>::SetInverse((Scaleform::Render::Matrix2x4<float> *)&v72, &m);
  Scaleform::Render::Matrix2x4<float>::EncloseTransform((Scaleform::Render::Matrix2x4<float> *)&v72, &pr, &v5->TextRect);
  LODWORD(vars0) = 0;
  v7 = pr.x1;
  if ( pr.x1 >= 0.0 )
  {
    v7 = 0.0;
    pr.x1 = 0.0;
  }
  v8 = pr.y1;
  if ( pr.y1 >= 0.0 )
  {
    v8 = 0.0;
    pr.y1 = 0.0;
  }
  v9 = pr.x2;
  if ( pr.x2 <= 0.0 )
  {
    v9 = 0.0;
    pr.x2 = 0.0;
  }
  v10 = pr.y2;
  if ( pr.y2 <= 0.0 )
  {
    v10 = 0.0;
    pr.y2 = 0.0;
  }
  v11 = 0;
  v69 = 0;
  v81 = v5->TextRecords.Records.Data.Size;
  v12 = 0i64;
  *(_QWORD *)&v75 = 0i64;
  if ( (_DWORD)v81 )
  {
    while ( 1 )
    {
      v13 = v5->TextRecords.Records.Data.Data[v12];
      Scaleform::GFx::ResourceBinding::GetResourceData(
        &v4->pBindData.pObject->ResourceBinding,
        &result,
        (Scaleform::GFx::ResourceHandle *)&v13->pFont.HType);
      v14 = result.pResource.pObject;
      *(__int64 *)((char *)&v73 + 4) = (__int64)result.pResource.pObject;
      if ( !result.pResource.pObject )
        break;
      if ( !(v5->Flags & 2) )
      {
        v15 = v4->pBindData.pObject->pDataDef.pObject->pData.pObject->BindData.pImports.Value;
        if ( v15 )
        {
          v16 = v89;
          do
          {
            v17 = 0;
            if ( v15->Imports.Data.Size > 0 )
            {
              v18 = 0i64;
              do
              {
                v19 = v18;
                if ( v15->Imports.Data.Data[v19].BindIndex == v13->pFont.BindIndex )
                {
                  v20 = Scaleform::GFx::StateBag::GetLog(v16 + 3, &v82)->pObject;
                  if ( v82.pObject )
                    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v82.pObject);
                  if ( v20 )
                    Scaleform::Log::LogWarning(
                      v20,
                      "Static text uses imported font! FontId = %d, import name = %s",
                      v13->FontId,
                      (v15->Imports.Data.Data[v19].SymbolName.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12);
                }
                v18 = ++v17;
              }
              while ( v17 < v15->Imports.Data.Size );
            }
            v15 = v15->pNext.Value;
          }
          while ( v15 );
          v14 = *(Scaleform::GFx::Resource **)((char *)&v73 + 4);
          v11 = v69;
        }
      }
      v21 = (Scaleform::Render::Text::LineBuffer *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                                     Scaleform::Memory::pGlobalHeap,
                                                     64i64);
      v70 = v21;
      v71 = v21;
      if ( v21 )
      {
        v22 = (Scaleform::GFx::Resource *)v14[1].vfptr;
        v21->Lines.Data.Data = (Scaleform::Render::Text::LineBuffer::Line **)&Scaleform::RefCountImplCore::`vftable;
        LODWORD(v21->Lines.Data.Size) = 1;
        v21->Lines.Data.Data = (Scaleform::Render::Text::LineBuffer::Line **)&Scaleform::RefCountImpl::`vftable;
        v21->Lines.Data.Data = (Scaleform::Render::Text::LineBuffer::Line **)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,74>::`vftable;
        v21->Lines.Data.Data = (Scaleform::Render::Text::LineBuffer::Line **)&Scaleform::RefCountBase<Scaleform::Render::Text::FontHandle,74>::`vftable;
        v21->Lines.Data.Data = (Scaleform::Render::Text::LineBuffer::Line **)&Scaleform::Render::Text::FontHandle::`vftable;
        v21->Lines.Data.Policy.Capacity = 0i64;
        *((_DWORD *)&v21->Lines + 6) = 0;
        Scaleform::StringLH::StringLH((Scaleform::StringLH *)&v21->Geom);
        *(&v21->Geom.FirstVisibleLinePos + 2) = 1065353216;
        if ( v22 )
          Scaleform::Render::RenderBuffer::AddRef(v22);
        *(_QWORD *)&v21->Geom.VisibleRect.x1 = v22;
        v21->Lines.Data.Data = (Scaleform::Render::Text::LineBuffer::Line **)&Scaleform::GFx::FontHandle::`vftable;
        *(_QWORD *)&v21->Geom.VisibleRect.x2 = 0i64;
      }
      else
      {
        v21 = 0i64;
        v70 = 0i64;
      }
      v84 = v21;
      v23 = v13->Glyphs.Data.Size;
      *(_QWORD *)&m.M[0][0] = v23;
      if ( (unsigned int)v23 > 0xFF || (HIDWORD(v14[1].vfptr->GetResourceReport) >> 13) & 1 )
        v24 = Scaleform::Render::Text::LineBuffer::InsertNewLine(v70, v11, v23, 2u, Line32);
      else
        v24 = Scaleform::Render::Text::LineBuffer::InsertNewLine(v70, v11, v23, 2u, 0);
      v25 = (__int64)v24;
      v71 = v24;
      v26 = (v24->MemSize & 0x80000000) == 0;
      v27 = (signed int)vars0;
      if ( v26 )
      {
        *(_DWORD *)(v25 + 8) = (_DWORD)vars0;
      }
      else
      {
        *(_DWORD *)(v25 + 8) &= 0xFF000000;
        *(_DWORD *)(v25 + 8) |= v27 & 0xFFFFFF;
        v27 = (signed int)vars0;
      }
      LODWORD(vars0) = v23 + v27;
      v28 = v13->Offset.y;
      v29 = v13->Offset.x;
      v30 = LODWORD(pr.y1) ^ _xmm[0];
      if ( (HIDWORD(v14[1].vfptr->GetResourceReport) >> 13) & 1 )
      {
        v31 = v13->TextHeight;
        v32 = (float)(v13->TextHeight * 0.0009765625);
        v33 = v29 + COERCE_FLOAT(LODWORD(pr.x1) ^ _xmm[0]);
        v34 = (float)(v28 - v31) + *(float *)&v30;
        v35 = (signed int)v31;
        if ( *(_DWORD *)v25 >= 0 )
          *(_WORD *)(v25 + 38) = v35;
        else
          *(_WORD *)(v25 + 26) = v35;
        v36 = *((float *)&v14[1].vfptr->GetResourceTypeCode + 1) * v32 + v13->TextHeight;
      }
      else
      {
        v33 = v29 + COERCE_FLOAT(LODWORD(pr.x1) ^ _xmm[0]);
        v34 = *(float *)&v30 + v28;
        v36 = 0.0;
      }
      if ( v34 <= 0.0 )
        v37 = v34 - 0.5;
      else
        v37 = v34 + 0.5;
      if ( v33 <= 0.0 )
        v38 = v33 - 0.5;
      else
        v38 = v33 + 0.5;
      v39 = *(_DWORD *)v25;
      *(_DWORD *)(v25 + 12) = (signed int)v38;
      *(_DWORD *)(v25 + 16) = (signed int)v37;
      if ( *(_DWORD *)v25 >= 0 )
        *(_QWORD *)(v25 + 20) = 0i64;
      else
        *(_DWORD *)(v25 + 20) = 0;
      v40 = v25 + 30;
      if ( *(_DWORD *)v25 >= 0 )
        v40 = v25 + 42;
      v41 = Scaleform::Render::Text::LineBuffer::Line::GetFormatData((Scaleform::Render::Text::LineBuffer::Line *)v25);
      *((_QWORD *)&v75 + 1) = v41;
      v43 = 0;
      v85 = 0;
      v68 = 0;
      v86 = 0;
      v44 = 0i64;
      v45 = 0;
      v46 = m.M[0][0];
      if ( LODWORD(m.M[0][0]) )
      {
        v47 = (Scaleform::GFx::Resource *)v70;
        v48 = 0;
        do
        {
          v49 = v43;
          *(_DWORD *)(v40 + 8 * v49) = 0;
          *(_DWORD *)(v40 + 8 * v49 + 4) = 4096;
          v42 = v45;
          *(_WORD *)(v40 + 8 * v49) = v13->Glyphs.Data.Data[v45].GlyphIndex;
          v50 = (signed int)v13->Glyphs.Data.Data[v45].GlyphAdvance;
          if ( v50 < 0 )
          {
            *(_WORD *)(v40 + 8i64 * v43 + 2) = abs((_WORD)v50);
            *(_WORD *)(v40 + 8i64 * v43 + 6) = 64;
            v41 = (Scaleform::Render::Text::LineBuffer::FormatDataEntry *)*((_QWORD *)&v75 + 1);
          }
          else
          {
            *(_WORD *)(v40 + 8i64 * v43 + 2) = v50;
            *(_WORD *)(v40 + 8i64 * v43 + 6) = 0;
          }
          v44 = (unsigned int)((signed int)v13->Glyphs.Data.Data[v45].GlyphAdvance + v44);
          v68 = v44;
          v51 = v13->TextHeight * 0.050000001;
          if ( v51 < 256.0 && (v52 = (signed int)(float)(v51 * 16.0), v52 & 0xF) )
          {
            *(_WORD *)(v40 + 8i64 * v43 + 6) |= 0x10u;
          }
          else
          {
            *(_WORD *)(v40 + 8i64 * v43 + 6) &= 0xFFEFu;
            v52 = (signed int)v51;
          }
          *(_WORD *)(v40 + 8i64 * v43 + 4) = v52 & 0xFFF | 0x1000;
          if ( !v45 )
          {
            *(_WORD *)(v40 + 8i64 * v43 + 6) |= 0x4000u;
            *(_WORD *)(v40 + 8i64 * v43 + 6) |= 0x2000u;
            v41[v48].pFont = (Scaleform::Render::Text::FontHandle *)v47;
            v53 = v48 + 1;
            Scaleform::Render::RenderBuffer::AddRef(v47);
            v78 = v13->ColorV.Raw;
            v54 = v78;
            *(_WORD *)(v40 + 8i64 * v43 + 6) |= 0x4000u;
            *(_WORD *)(v40 + 8i64 * v43 + 6) |= 0x1000u;
            v41 = (Scaleform::Render::Text::LineBuffer::FormatDataEntry *)*((_QWORD *)&v75 + 1);
            *(_DWORD *)(*((_QWORD *)&v75 + 1) + 8i64 * v53) = v54;
            v48 = v53 + 1;
            v86 = v48;
            v44 = v68;
            v46 = m.M[0][0];
          }
          ++v45;
          if ( v40 && v43 < LODWORD(v46) )
            ++v43;
        }
        while ( v45 < LODWORD(v46) );
        v85 = v43;
        v25 = (__int64)v71;
        v21 = v70;
      }
      if ( (*(_DWORD *)(*(_QWORD *)(*(__int64 *)((char *)&v73 + 4) + 24) + 28i64) >> 13) & 1 )
      {
        if ( v36 <= 0.0 )
          v55 = v36 - 0.5;
        else
          v55 = v36 + 0.5;
        v56 = (signed int)v55;
        if ( (signed int)v44 < 0 )
          v44 = 0i64;
        if ( *(_DWORD *)v25 >= 0 )
        {
          *(_DWORD *)(v25 + 20) = v44;
          *(_DWORD *)(v25 + 24) = v56;
        }
        else
        {
          *(_WORD *)(v25 + 20) = v44;
          *(_WORD *)(v25 + 22) = v56;
        }
        if ( *(_DWORD *)v25 >= 0 )
          *(float *)(v25 + 32) = v46;
        else
          *(_BYTE *)(v25 + 11) = LOBYTE(v46);
        v42 = *(unsigned int *)(v25 + 16);
        if ( *(_DWORD *)v25 >= 0 )
          v57 = *(_DWORD *)(v25 + 24);
        else
          v57 = *(unsigned __int16 *)(v25 + 22);
        if ( *(_DWORD *)v25 >= 0 )
          v59 = *(_DWORD *)(v25 + 20);
        else
          v59 = *(unsigned __int16 *)(v25 + 20);
        v58 = *(_DWORD *)(v25 + 12);
        v60 = (float)(v58 + v59);
        v61 = (float)(v57 + v42);
        if ( pr.x1 >= v60 )
          pr.x1 = (float)(v58 + v59);
        if ( pr.y1 >= v61 )
          pr.y1 = (float)(v57 + v42);
        if ( v60 >= pr.x2 )
          pr.x2 = (float)(v58 + v59);
        if ( v61 >= pr.y2 )
          pr.y2 = (float)(v57 + v42);
      }
      if ( v21 )
        Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v21);
      v62 = result.pResource.pObject;
      if ( result.pResource.pObject
        && _InterlockedExchangeAdd(&result.pResource.pObject->RefCount.Value, 0xFFFFFFFF) == 1 )
      {
        v63 = v62->pLib;
        if ( v63 )
        {
          ((void (__fastcall *)(Scaleform::GFx::ResourceLibBase *, Scaleform::GFx::Resource *, __int64, __int64))v63->vfptr[1].__vecDelDtor)(
            v63,
            v62,
            v42,
            v44);
          v62->pLib = 0i64;
        }
        v62->vfptr->__vecDelDtor(v62, 1u);
      }
      v11 = v69 + 1;
      v69 = v11;
      v12 = v75 + 1;
      *(_QWORD *)&v75 = v75 + 1;
      v4 = (Scaleform::GFx::MovieDefImpl *)v89;
      v5 = v88;
      if ( v11 >= (unsigned int)v81 )
      {
        v10 = pr.y2;
        v9 = pr.x2;
        v8 = pr.y1;
        v7 = pr.x1;
        v6 = v87;
        goto LABEL_116;
      }
    }
    v64 = Scaleform::GFx::StateBag::GetLog((Scaleform::GFx::StateBag *)&v4->vfptr, &v77)->pObject;
    if ( v77.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v77.pObject);
    if ( v64 )
      Scaleform::Log::LogError(v64, "Text style with undefined font; FontId = %d", v13->FontId);
    v65 = result.pResource.pObject;
    if ( result.pResource.pObject && _InterlockedExchangeAdd(&result.pResource.pObject->RefCount.Value, 0xFFFFFFFF) == 1 )
    {
      v66 = v65->pLib;
      if ( v66 )
      {
        v66->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v66->vfptr, (unsigned int)v65);
        v65->pLib = 0i64;
      }
      v65->vfptr->__vecDelDtor(v65, 1u);
    }
  }
  else
  {
LABEL_116:
    v6->TextGlyphRecords.Geom.VisibleRect.x1 = v7;
    v6->TextGlyphRecords.Geom.VisibleRect.y1 = v8;
    v6->TextGlyphRecords.Geom.VisibleRect.x2 = v9;
    v6->TextGlyphRecords.Geom.VisibleRect.y2 = v10;
    v6->TextGlyphRecords.Geom.Flags |= 4u;
    Scaleform::Render::Text::TextFilter::SetDefaultShadow(&v6->Filter);
    v5->Flags |= 2u;
    Scaleform::GFx::StaticTextCharacter::RecreateVisibleTextLayout(v6);
  }
}

// File Line: 417
// RVA: 0x8A7CE0
void __fastcall Scaleform::GFx::StaticTextCharacter::~StaticTextCharacter(Scaleform::GFx::StaticTextCharacter *this)
{
  Scaleform::GFx::StaticTextCharacter *v1; // rbx
  Scaleform::GFx::StaticTextCharacter::HighlightDesc *v2; // rdi
  Scaleform::Render::RenderBuffer *v3; // rcx
  Scaleform::GFx::StaticTextDef *v4; // rdi
  Scaleform::GFx::ResourceLibBase *v5; // rcx

  v1 = this;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::GFx::StaticTextCharacter::`vftable{for `Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>};
  this->vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>Vtbl *)&Scaleform::GFx::StaticTextCharacter::`vftable{for `Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>};
  v2 = this->pHighlight;
  if ( v2 )
  {
    Scaleform::Memory::pGlobalHeap->vfptr->Free(
      Scaleform::Memory::pGlobalHeap,
      v2->HighlightManager.Highlighters.Data.Data);
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v2);
  }
  v3 = (Scaleform::Render::RenderBuffer *)v1->Filter.ShadowParams.Gradient.pObject;
  if ( v3 )
    Scaleform::RefCountImpl::Release(v3);
  Scaleform::RefCountNTSImplCore::~RefCountNTSImplCore((Scaleform::RefCountNTSImplCore *)&v1->Filter.vfptr);
  Scaleform::Render::Text::LineBuffer::~LineBuffer(&v1->TextGlyphRecords);
  v4 = v1->pDef.pObject;
  if ( v4 && !_InterlockedDecrement(&v4->RefCount.Value) )
  {
    v5 = v4->pLib;
    if ( v5 )
    {
      v5->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v5->vfptr, (unsigned int)v4);
      v4->pLib = 0i64;
    }
    v4->vfptr->__vecDelDtor((Scaleform::GFx::Resource *)&v4->vfptr, 1u);
  }
  Scaleform::GFx::DisplayObject::~DisplayObject((Scaleform::GFx::DisplayObject *)&v1->vfptr);
}

// File Line: 440
// RVA: 0x909690
void __fastcall Scaleform::GFx::StaticTextCharacter::SetMatrix(Scaleform::GFx::StaticTextCharacter *this, Scaleform::Render::Matrix2x4<float> *m)
{
  float *v2; // rax
  float v3; // xmm7_4
  float v4; // xmm6_4
  float v5; // xmm8_4
  float v6; // xmm5_4
  float v7; // xmm3_4
  float v8; // xmm4_4
  float v9; // xmm0_4
  float v10; // xmm2_4
  float v11; // xmm0_4
  Scaleform::Render::Matrix2x4<float> mt; // [rsp+20h] [rbp-58h]

  this->OrigMatrix = *m;
  v2 = (float *)this->pDef.pObject;
  v3 = m->M[0][0];
  v4 = m->M[0][1];
  v5 = m->M[1][0];
  v6 = m->M[1][1];
  v7 = m->M[0][3];
  v8 = m->M[1][3];
  mt.M[0][2] = m->M[0][2];
  v9 = m->M[1][2];
  mt.M[0][3] = v7;
  mt.M[1][0] = v5;
  mt.M[1][3] = v8;
  *(_QWORD *)&mt.M[0][0] = __PAIR__(LODWORD(v4), LODWORD(v3));
  *(_QWORD *)&mt.M[1][1] = LODWORD(v6);
  mt.M[0][0] = (float)(v4 * v2[16]) + (float)(v3 * v2[12]);
  mt.M[1][0] = (float)(v6 * v2[16]) + (float)(v5 * v2[12]);
  mt.M[0][1] = (float)(v3 * v2[13]) + (float)(v4 * v2[17]);
  v10 = v5 * v2[13];
  v11 = v6 * v2[17];
  mt.M[0][2] = 0.0;
  mt.M[1][1] = v10 + v11;
  mt.M[0][3] = v7 + (float)((float)(v4 * v2[19]) + (float)(v3 * v2[15]));
  mt.M[1][3] = v8 + (float)((float)(v5 * v2[15]) + (float)(v6 * v2[19]));
  Scaleform::GFx::DisplayObject::SetMatrix((Scaleform::GFx::DisplayObject *)&this->vfptr, &mt);
}

// File Line: 448
// RVA: 0x8DAFC0
Scaleform::Render::Matrix2x4<float> *__fastcall Scaleform::GFx::StaticTextCharacter::GetMatrix(Scaleform::GFx::StaticTextCharacter *this)
{
  return &this->OrigMatrix;
}

// File Line: 453
// RVA: 0x907190
void __fastcall Scaleform::GFx::StaticTextCharacter::SetFilters(Scaleform::GFx::StaticTextCharacter *this, Scaleform::Render::FilterSet *filters)
{
  Scaleform::Render::FilterSet *v2; // rdi
  Scaleform::GFx::StaticTextCharacter *v3; // rsi
  unsigned int v4; // ebx
  Scaleform::Render::Filter *v5; // rax
  Scaleform::Render::Text::TextFilter v6; // [rsp+30h] [rbp-68h]

  if ( filters )
  {
    v2 = filters;
    v3 = this;
    Scaleform::Render::Text::TextFilter::TextFilter(&v6);
    v4 = 0;
    if ( (unsigned int)BasicArrayImplementation<hkDataArrayImpl *>::getSize((BasicArrayImplementation<hkDataObjectImpl *> *)v2) )
    {
      do
      {
        v5 = Scaleform::Render::FilterSet::GetFilter(v2, v4);
        Scaleform::Render::Text::TextFilter::LoadFilterDesc(&v6, v5);
        ++v4;
      }
      while ( v4 < (unsigned int)BasicArrayImplementation<hkDataArrayImpl *>::getSize((BasicArrayImplementation<hkDataObjectImpl *> *)v2) );
    }
    v3->vfptr[85].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v3->vfptr, (unsigned int)&v6);
    if ( v6.ShadowParams.Gradient.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v6.ShadowParams.Gradient.pObject);
    Scaleform::RefCountNTSImplCore::~RefCountNTSImplCore((Scaleform::RefCountNTSImplCore *)&v6.vfptr);
  }
}

// File Line: 467
// RVA: 0x8C2980
Scaleform::Ptr<Scaleform::Render::TreeNode> *__fastcall Scaleform::GFx::StaticTextCharacter::CreateRenderNode(Scaleform::GFx::StaticTextCharacter *this, Scaleform::Ptr<Scaleform::Render::TreeNode> *result, Scaleform::Render::ContextImpl::Context *context)
{
  Scaleform::Render::ContextImpl::Context *v3; // rsi
  Scaleform::Ptr<Scaleform::Render::TreeNode> *v4; // rbx
  Scaleform::Render::TreeText::NodeData *v5; // rax
  Scaleform::Render::ContextImpl::EntryData *v6; // rdi
  Scaleform::Render::ContextImpl::Entry *v7; // rax
  bool v8; // zf

  v3 = context;
  v4 = result;
  v5 = (Scaleform::Render::TreeText::NodeData *)context->pHeap->vfptr->Alloc(context->pHeap, 176ui64, 0i64);
  v6 = (Scaleform::Render::ContextImpl::EntryData *)&v5->vfptr;
  if ( v5 )
    Scaleform::Render::TreeText::NodeData::NodeData(v5);
  v7 = Scaleform::Render::ContextImpl::Context::createEntryHelper(v3, v6);
  if ( v7 )
    ++v7->RefCount;
  v4->pObject = (Scaleform::Render::TreeNode *)v7;
  if ( v7 )
  {
    v8 = v7->RefCount-- == 1;
    if ( v8 )
      Scaleform::Render::ContextImpl::Entry::destroyHelper(v7);
  }
  return v4;
}

// File Line: 473
// RVA: 0x8FE2D0
void __fastcall Scaleform::GFx::StaticTextCharacter::RecreateVisibleTextLayout(Scaleform::GFx::StaticTextCharacter *this)
{
  Scaleform::GFx::StaticTextCharacter *v1; // rbx
  Scaleform::Render::TreeText *v2; // rdi
  Scaleform::Render::Text::Highlighter *v3; // rcx
  float v4; // xmm3_4
  float v5; // xmm2_4
  float v6; // xmm1_4
  Scaleform::Render::TextFieldParam params; // [rsp+20h] [rbp-D8h]
  __int64 v8; // [rsp+60h] [rbp-98h]
  Scaleform::Render::TextLayout::Builder bld; // [rsp+70h] [rbp-88h]

  v8 = -2i64;
  v1 = this;
  v2 = (Scaleform::Render::TreeText *)Scaleform::GFx::DisplayObjectBase::GetRenderNode((Scaleform::GFx::DisplayObjectBase *)&this->vfptr);
  Scaleform::Render::TextLayout::Builder::Builder(&bld, Scaleform::Memory::pGlobalHeap);
  v3 = &v1->pHighlight->HighlightManager;
  if ( v3 && !v3->Valid )
  {
    Scaleform::Render::Text::Highlighter::UpdateGlyphIndices(v3, 0i64);
    v1->pHighlight->HighlightManager.Valid = 1;
  }
  params.TextParam.pFont = 0i64;
  *(_QWORD *)&params.TextParam.GlyphIndex = 0i64;
  *(_DWORD *)&params.TextParam.BlurY = 0x100000;
  params.ShadowParam.pFont = 0i64;
  *(_QWORD *)&params.ShadowParam.GlyphIndex = 0i64;
  *(_DWORD *)&params.ShadowParam.BlurY = 0x100000;
  *(_QWORD *)&params.ShadowColor = 0i64;
  params.ShadowOffsetY = 0.0;
  Scaleform::Render::Text::LoadTextFieldParamFromTextFilter(&params, &v1->Filter);
  if ( v1->pDef.pObject->Flags & 1 )
  {
    params.TextParam.Flags |= 3u;
    params.ShadowParam.Flags |= 3u;
  }
  Scaleform::Render::Text::LineBuffer::CreateVisibleTextLayout(
    &v1->TextGlyphRecords,
    &bld,
    &v1->pHighlight->HighlightManager,
    &params);
  v4 = v1->TextGlyphRecords.Geom.VisibleRect.y2;
  v5 = v1->TextGlyphRecords.Geom.VisibleRect.x2;
  v6 = v1->TextGlyphRecords.Geom.VisibleRect.y1;
  bld.Param.ShadowOffsetY = v1->TextGlyphRecords.Geom.VisibleRect.x1;
  *(&bld.Param.ShadowOffsetY + 1) = v6;
  bld.Bounds.x1 = v5;
  bld.Bounds.y1 = v4;
  Scaleform::Render::TreeText::SetLayout(v2, &bld);
  Scaleform::Render::TextLayout::Builder::~Builder(&bld);
}

// File Line: 994
// RVA: 0x86DC10
void __fastcall Scaleform::GFx::GFx_DefineTextLoader(Scaleform::GFx::LoadProcess *p, Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::TagInfo *v2; // r14
  Scaleform::GFx::LoadProcess *v3; // rsi
  Scaleform::GFx::Stream *v4; // rbx
  __int64 v5; // r8
  unsigned int v6; // ebp
  __int64 v7; // rax
  __int64 v8; // rbx
  int v9; // et1
  __int64 v10; // rax
  _QWORD *v11; // rax
  __int64 v12; // rcx
  Scaleform::GFx::ResourceId rid; // [rsp+70h] [rbp+8h]
  Scaleform::MemoryHeap *v14; // [rsp+78h] [rbp+10h]
  __int64 v15; // [rsp+80h] [rbp+18h]
  _QWORD *v16; // [rsp+88h] [rbp+20h]

  v2 = tagInfo;
  v3 = p;
  v4 = p->pAltStream;
  if ( !v4 )
    v4 = &p->ProcessInfo.Stream;
  v4->UnusedBits = 0;
  if ( (signed int)(v4->DataSize - v4->Pos) < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(v4, 2);
  v5 = v4->Pos;
  LOWORD(v6) = (unsigned __int8)v4->pBuffer[v5] | (unsigned __int16)((unsigned __int8)v4->pBuffer[(unsigned int)(v5 + 1)] << 8);
  v4->Pos = v5 + 2;
  v14 = v3->pLoadData.pObject->pHeap;
  v7 = ((__int64 (__fastcall *)(Scaleform::GFx::LoadProcess *, signed __int64))v14->vfptr->Alloc)(p, 112i64);
  v8 = v7;
  v15 = v7;
  if ( v7 )
  {
    *(_QWORD *)v7 = &Scaleform::GFx::Resource::`vftable;
    v9 = *(_DWORD *)(v7 + 8);
    v10 = *(unsigned int *)(v7 + 8);
    *(_DWORD *)(v8 + 8) = 1;
    *(_QWORD *)(v8 + 16) = 0i64;
    *(_QWORD *)v8 = &Scaleform::GFx::CharacterDef::`vftable;
    *(_DWORD *)(v8 + 24) = 0x40000;
    *(_QWORD *)v8 = &Scaleform::GFx::StaticTextDef::`vftable;
    *(_QWORD *)(v8 + 32) = 0i64;
    *(_QWORD *)(v8 + 40) = 0i64;
    *(_QWORD *)(v8 + 48) = 1065353216i64;
    *(_QWORD *)(v8 + 56) = 0i64;
    *(_DWORD *)(v8 + 64) = 0;
    *(_QWORD *)(v8 + 68) = 1065353216i64;
    *(_DWORD *)(v8 + 76) = 0;
    v11 = (_QWORD *)(v8 + 80);
    v16 = v11;
    *v11 = 0i64;
    v11[1] = 0i64;
    v11[2] = 0i64;
    *(_BYTE *)(v8 + 104) = 0;
  }
  else
  {
    v8 = 0i64;
  }
  v6 = (unsigned __int16)v6;
  Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
    (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&v3->vfptr,
    "TextCharacter, id = %d\n",
    (unsigned __int16)v6);
  Scaleform::GFx::StaticTextDef::Read((Scaleform::GFx::StaticTextDef *)v8, v3, v2->TagType);
  if ( v3->LoadState == LS_LoadingRoot )
  {
    rid.Id = v6;
    Scaleform::GFx::MovieDataDef::LoadTaskData::AddResource(
      v3->pLoadData.pObject,
      (Scaleform::GFx::ResourceId)&rid,
      (Scaleform::GFx::Resource *)v8);
  }
  if ( v8 && !_InterlockedDecrement((volatile signed __int32 *)(v8 + 8)) )
  {
    v12 = *(_QWORD *)(v8 + 16);
    if ( v12 )
    {
      (*(void (__fastcall **)(__int64, __int64))(*(_QWORD *)v12 + 8i64))(v12, v8);
      *(_QWORD *)(v8 + 16) = 0i64;
    }
    (**(void (__fastcall ***)(__int64, signed __int64))v8)(v8, 1i64);
  }
}

