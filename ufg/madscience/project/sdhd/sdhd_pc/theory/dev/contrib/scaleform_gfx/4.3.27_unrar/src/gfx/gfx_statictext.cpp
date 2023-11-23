// File Line: 57
// RVA: 0x8F9CF0
void __fastcall Scaleform::GFx::StaticTextRecord::Read(
        Scaleform::GFx::StaticTextRecord *this,
        Scaleform::GFx::Stream *in,
        int glyphCount,
        unsigned int glyphBits,
        int advanceBits)
{
  __int64 v5; // r15
  __int64 v9; // rdi
  int v10; // r14d
  int v11; // r14d
  Scaleform::GFx::StaticTextRecord::GlyphEntry *Data; // rbx
  int UInt; // eax

  v5 = glyphCount;
  Scaleform::ArrayData<Scaleform::GFx::StaticTextRecord::GlyphEntry,Scaleform::AllocatorLH<Scaleform::GFx::StaticTextRecord::GlyphEntry,258>,Scaleform::ArrayDefaultPolicy>::Resize(
    &this->Glyphs.Data,
    glyphCount);
  v9 = 0i64;
  v10 = __ROL4__(1, advanceBits);
  if ( v5 > 0 )
  {
    v11 = __ROR4__(v10, 1);
    do
    {
      Data = this->Glyphs.Data.Data;
      Data[v9].GlyphIndex = Scaleform::GFx::Stream::ReadUInt(in, glyphBits);
      UInt = Scaleform::GFx::Stream::ReadUInt(in, advanceBits);
      if ( (v11 & UInt) != 0 )
        UInt |= -1 << advanceBits;
      this->Glyphs.Data.Data[v9++].GlyphAdvance = (float)UInt;
    }
    while ( v9 < v5 );
  }
}

// File Line: 68
// RVA: 0x8D6570
float __fastcall Scaleform::GFx::StaticTextRecord::GetCumulativeAdvance(Scaleform::GFx::StaticTextRecord *this)
{
  unsigned __int64 Size; // r8
  unsigned __int64 v2; // rdx
  float v4; // xmm1_4
  Scaleform::GFx::StaticTextRecord::GlyphEntry *Data; // rcx
  __m128 v6; // xmm4
  __m128 GlyphAdvance_low; // xmm0
  __m128 v8; // xmm2
  __m128 v9; // xmm3
  __m128 v10; // xmm1
  __m128 v11; // xmm1

  Size = this->Glyphs.Data.Size;
  v2 = 0i64;
  v4 = 0.0;
  if ( Size )
  {
    if ( Size >= 8 )
    {
      Data = this->Glyphs.Data.Data;
      v6 = 0i64;
      do
      {
        GlyphAdvance_low = (__m128)LODWORD(Data[v2 + 2].GlyphAdvance);
        v8 = _mm_unpacklo_ps((__m128)LODWORD(Data[v2 + 1].GlyphAdvance), (__m128)LODWORD(Data[v2 + 3].GlyphAdvance));
        v9 = (__m128)LODWORD(Data[v2].GlyphAdvance);
        v10 = (__m128)LODWORD(Data[v2 + 7].GlyphAdvance);
        v2 += 8i64;
        v6 = _mm_add_ps(
               _mm_add_ps(v6, _mm_unpacklo_ps(_mm_unpacklo_ps(v9, GlyphAdvance_low), v8)),
               _mm_unpacklo_ps(
                 _mm_unpacklo_ps(
                   (__m128)*((unsigned int *)&Data[v2 - 3] - 1),
                   (__m128)*((unsigned int *)&Data[v2 - 1] - 1)),
                 _mm_unpacklo_ps((__m128)*((unsigned int *)&Data[v2 - 2] - 1), v10)));
      }
      while ( v2 < Size - (Size & 7) );
      v11 = _mm_add_ps(_mm_movehl_ps(v6, v6), v6);
      v4 = v11.m128_f32[0] + _mm_shuffle_ps(v11, v11, 245).m128_f32[0];
    }
    for ( ; v2 < Size; ++v2 )
      v4 = v4 + this->Glyphs.Data.Data[v2].GlyphAdvance;
  }
  return v4;
}

// File Line: 78
// RVA: 0x8BC180
void __fastcall Scaleform::GFx::StaticTextRecordList::Clear(Scaleform::GFx::StaticTextRecordList *this)
{
  unsigned __int64 Size; // rbp
  unsigned __int64 i; // rbx
  Scaleform::GFx::StaticTextRecord *v4; // rsi

  Size = this->Records.Data.Size;
  for ( i = 0i64; i < Size; ++i )
  {
    v4 = this->Records.Data.Data[i];
    if ( v4 )
    {
      Scaleform::GFx::StaticTextRecord::~StaticTextRecord(this->Records.Data.Data[i]);
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v4);
    }
  }
  if ( this->Records.Data.Size && (this->Records.Data.Policy.Capacity & 0xFFFFFFFFFFFFFFFEui64) != 0 )
  {
    if ( this->Records.Data.Data )
    {
      ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      this->Records.Data.Data = 0i64;
    }
    this->Records.Data.Policy.Capacity = 0i64;
  }
  this->Records.Data.Size = 0i64;
}

// File Line: 85
// RVA: 0x8B1D80
Scaleform::GFx::StaticTextRecord *__fastcall Scaleform::GFx::StaticTextRecordList::AddRecord(
        Scaleform::GFx::StaticTextRecordList *this)
{
  _QWORD *v2; // rax
  _QWORD *v3; // rbx
  __int64 v4; // rax
  unsigned __int64 Size; // rax
  unsigned __int64 v6; // rsi
  unsigned __int64 v7; // r8
  Scaleform::GFx::StaticTextRecord **v8; // rax
  int v10; // [rsp+58h] [rbp+10h] BYREF
  _QWORD *v11; // [rsp+60h] [rbp+18h]
  __int64 v12; // [rsp+68h] [rbp+20h]

  v10 = 258;
  v2 = (_QWORD *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::GFx::StaticTextRecordList *, __int64, int *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
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
    v4 = (__int64)(v2 + 3);
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
  Size = this->Records.Data.Size;
  v6 = Size + 1;
  if ( Size + 1 >= Size )
  {
    if ( v6 <= this->Records.Data.Policy.Capacity )
      goto LABEL_11;
    v7 = v6 + (v6 >> 2);
  }
  else
  {
    if ( v6 >= this->Records.Data.Policy.Capacity >> 1 )
      goto LABEL_11;
    v7 = Size + 1;
  }
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ButtonActionBase>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ButtonActionBase>,258>,Scaleform::ArrayDefaultPolicy>::Reserve(
    (Scaleform::ArrayDataBase<Scaleform::GFx::StaticTextRecord::GlyphEntry,Scaleform::AllocatorLH<Scaleform::GFx::StaticTextRecord::GlyphEntry,258>,Scaleform::ArrayDefaultPolicy> *)this,
    this,
    v7);
LABEL_11:
  this->Records.Data.Size = v6;
  v8 = &this->Records.Data.Data[v6 - 1];
  if ( v8 )
    *v8 = (Scaleform::GFx::StaticTextRecord *)v3;
  return (Scaleform::GFx::StaticTextRecord *)v3;
}

// File Line: 101
// RVA: 0x8F9660
// bad sp value at call has been detected, the output may be wrong!
void __fastcall Scaleform::GFx::StaticTextDef::Read(
        Scaleform::GFx::StaticTextDef *this,
        Scaleform::GFx::LoadProcess *p,
        Scaleform::GFx::TagType tagType)
{
  Scaleform::GFx::SWFProcessInfo *pAltStream; // rsi
  double x2; // xmm1_8
  __int64 Pos; // rdx
  int v7; // ecx
  int v8; // r13d
  __int64 v9; // rdx
  unsigned int v10; // ecx
  unsigned int v11; // r14d
  char v12; // di
  float v13; // xmm9_4
  __int64 v14; // r15
  float v15; // xmm6_4
  float v16; // xmm7_4
  float v17; // xmm10_4
  __int64 v18; // rdx
  int v19; // ecx
  __int64 v20; // r12
  int v21; // edi
  char v22; // r14
  char v23; // r13
  char v24; // r12
  __int64 v25; // r8
  unsigned __int16 v26; // cx
  unsigned int v27; // edi
  Scaleform::GFx::Resource *v28; // rcx
  __int64 v29; // rdi
  Scaleform::GFx::ResourceLibBase *v30; // rcx
  Scaleform::GFx::Resource *v31; // rdi
  Scaleform::GFx::ResourceLibBase *v32; // rcx
  __int64 v33; // rdx
  char v34; // cl
  __int64 v35; // r9
  __int16 v36; // r8
  __int64 v37; // r9
  __int16 v38; // r8
  bool v39; // zf
  __int64 v40; // r9
  unsigned __int16 v41; // r8
  __int64 v42; // rdi
  Scaleform::GFx::StaticTextRecord *v43; // rax
  Scaleform::GFx::StaticTextRecord *v44; // rdi
  Scaleform::GFx::Resource *pResource; // r14
  Scaleform::GFx::ResourceLibBase *pLib; // rcx
  __int64 v47; // rbx
  Scaleform::GFx::ResourceLibBase *v48; // rcx
  Scaleform::Render::Color pc; // [rsp+0h] [rbp-7Dh] BYREF
  Scaleform::GFx::ResourceHandle::HandleType HType; // [rsp+4h] [rbp-79h]
  Scaleform::GFx::Resource *v51; // [rsp+Ch] [rbp-71h]
  int v52; // [rsp+14h] [rbp-69h]
  Scaleform::GFx::ResourceHandle phandle; // [rsp+1Ch] [rbp-61h] BYREF
  Scaleform::GFx::ResourceId rid[2]; // [rsp+2Ch] [rbp-51h] BYREF
  __int64 v55; // [rsp+34h] [rbp-49h]
  int v56; // [rsp+3Ch] [rbp-41h]
  __int64 v57; // [rsp+E4h] [rbp+67h]
  __int64 v58; // [rsp+ECh] [rbp+6Fh]
  int v59; // [rsp+F4h] [rbp+77h]
  char v60; // [rsp+FCh] [rbp+7Fh]

  v55 = -2i64;
  pAltStream = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  if ( !pAltStream )
    pAltStream = &p->ProcessInfo;
  Scaleform::GFx::Stream::ReadRect(&pAltStream->Stream, &this->TextRect);
  x2 = this->TextRect.x2;
  *(double *)&rid[0].Id = this->TextRect.y2;
  *(double *)&phandle.pResource = x2;
  Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
    &pAltStream->Stream,
    "  TextRect = { l: %f, t: %f, r: %f, b: %f }\n");
  Scaleform::GFx::Stream::ReadMatrix(&pAltStream->Stream, &this->MatrixPriv);
  Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(&pAltStream->Stream, "  mat:\n");
  pAltStream->Stream.UnusedBits = 0;
  if ( (signed int)(pAltStream->Stream.DataSize - pAltStream->Stream.Pos) < 1 )
    Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 1);
  Pos = pAltStream->Stream.Pos;
  v7 = (unsigned __int8)pAltStream->Stream.pBuffer[Pos];
  pAltStream->Stream.Pos = Pos + 1;
  v8 = v7;
  v52 = v7;
  pAltStream->Stream.UnusedBits = 0;
  if ( (signed int)(pAltStream->Stream.DataSize - (Pos + 1)) < 1 )
    Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 1);
  v9 = pAltStream->Stream.Pos;
  v10 = (unsigned __int8)pAltStream->Stream.pBuffer[v9];
  pAltStream->Stream.Pos = v9 + 1;
  v11 = v10;
  HIDWORD(v55) = v10;
  Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(&pAltStream->Stream, "begin text records\n");
  v12 = 0;
  v13 = 0.0;
  LOWORD(v55) = 0;
  HType = RH_Pointer;
  v14 = 0i64;
  v51 = 0i64;
  v15 = 0.0;
  v16 = 0.0;
  v17 = 0.0;
  while ( 1 )
  {
    pAltStream->Stream.UnusedBits = 0;
    if ( (signed int)(pAltStream->Stream.DataSize - pAltStream->Stream.Pos) < 1 )
      Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 1);
    v18 = pAltStream->Stream.Pos;
    v19 = (unsigned __int8)pAltStream->Stream.pBuffer[v18];
    pAltStream->Stream.Pos = v18 + 1;
    v20 = (unsigned int)v19;
    if ( !(_BYTE)v19 )
      break;
    if ( v12 )
    {
      v12 = 0;
      v60 = 0;
      if ( v15 >= 0.0 || v17 <= 0.0 )
      {
        v43 = Scaleform::GFx::StaticTextRecordList::AddRecord((Scaleform::GFx::StaticTextRecordList *)(v57 + 80));
        v44 = v43;
        if ( v43 )
        {
          v17 = v15;
          v43->Offset.x = v16;
          v43->Offset.y = v15;
          if ( HType == RH_Pointer && v14 )
          {
            _InterlockedExchangeAdd((volatile signed __int32 *)(v14 + 8), 1u);
            v14 = (__int64)v51;
          }
          if ( v43->pFont.HType == RH_Pointer )
          {
            pResource = v43->pFont.pResource;
            if ( pResource )
            {
              if ( !_InterlockedDecrement(&pResource->RefCount.Value) )
              {
                pLib = pResource->pLib;
                if ( pLib )
                {
                  pLib->vfptr[1].__vecDelDtor(pLib, (unsigned int)pResource);
                  pResource->pLib = 0i64;
                }
                pResource->vfptr->__vecDelDtor(pResource, 1u);
              }
              v14 = (__int64)v51;
            }
            v11 = HIDWORD(v55);
          }
          v44->pFont.HType = HType;
          v44->pFont.pResource = (Scaleform::GFx::Resource *)v14;
          v44->TextHeight = v13;
          v44->ColorV = pc;
          v44->FontId = v55;
          Scaleform::GFx::StaticTextRecord::Read(v44, &pAltStream->Stream, v20, v8, v11);
          v16 = v16 + Scaleform::GFx::StaticTextRecord::GetCumulativeAdvance(v44);
        }
        Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
          &pAltStream->Stream,
          "  GlyphRecords: count = %d\n");
        v12 = v60;
      }
      else
      {
        Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
          &pAltStream->Stream,
          "  Negative Y-offset, 16-bit value rollover, skipping the line...\n");
        if ( (int)v20 > 0 )
        {
          v42 = v20;
          do
          {
            Scaleform::GFx::Stream::ReadUInt(&pAltStream->Stream, v8);
            Scaleform::GFx::Stream::ReadUInt(&pAltStream->Stream, v11);
            --v42;
          }
          while ( v42 );
          v12 = v60;
        }
      }
    }
    else
    {
      v60 = 1;
      v21 = v19 >> 3;
      LOBYTE(v21) = (v19 >> 3) & 1;
      v56 = v21;
      v22 = (v19 >> 2) & 1;
      v23 = (v19 >> 1) & 1;
      v24 = v19 & 1;
      Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(&pAltStream->Stream, "  text style change\n");
      if ( (_BYTE)v21 )
      {
        pAltStream->Stream.UnusedBits = 0;
        if ( (signed int)(pAltStream->Stream.DataSize - pAltStream->Stream.Pos) < 2 )
          Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
        v25 = pAltStream->Stream.Pos;
        LOWORD(v55) = (unsigned __int8)pAltStream->Stream.pBuffer[v25] | ((unsigned __int8)pAltStream->Stream.pBuffer[(unsigned int)(v25 + 1)] << 8);
        v26 = v55;
        pAltStream->Stream.Pos = v25 + 2;
        v27 = v26;
        Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(&pAltStream->Stream, "  HasFont: font id = %d\n");
        phandle.HType = RH_Pointer;
        phandle.pResource = 0i64;
        rid[0].Id = v27;
        Scaleform::GFx::MovieDataDef::LoadTaskData::GetResourceHandle(
          *(Scaleform::GFx::MovieDataDef::LoadTaskData **)(v58 + 56),
          &phandle,
          rid);
        v28 = phandle.pResource;
        if ( phandle.HType == RH_Pointer && phandle.pResource )
        {
          _InterlockedExchangeAdd(&phandle.pResource->RefCount.Value, 1u);
          v14 = (__int64)v51;
          v28 = phandle.pResource;
        }
        if ( HType == RH_Pointer && v14 )
        {
          if ( !_InterlockedDecrement((volatile signed __int32 *)(v14 + 8)) )
          {
            v29 = (__int64)v51;
            v30 = v51->pLib;
            if ( v30 )
            {
              v30->vfptr[1].__vecDelDtor(v30, (unsigned int)v51);
              *(_QWORD *)(v29 + 16) = 0i64;
            }
            (**(void (__fastcall ***)(__int64, __int64))v29)(v29, 1i64);
          }
          v28 = phandle.pResource;
        }
        HType = phandle.HType;
        v14 = (__int64)v28;
        v51 = v28;
        if ( phandle.HType == RH_Pointer && v28 )
        {
          if ( !_InterlockedDecrement(&v28->RefCount.Value) )
          {
            v31 = phandle.pResource;
            v32 = phandle.pResource->pLib;
            if ( v32 )
            {
              v32->vfptr[1].__vecDelDtor(v32, (unsigned int)phandle.pResource);
              v31->pLib = 0i64;
            }
            v31->vfptr->__vecDelDtor(v31, 1u);
          }
          v14 = (__int64)v51;
        }
        LOBYTE(v21) = v56;
      }
      if ( v22 )
      {
        Scaleform::GFx::Stream::ReadRgb(&pAltStream->Stream, &pc);
        if ( v59 != 11 )
        {
          pAltStream->Stream.UnusedBits = 0;
          if ( (signed int)(pAltStream->Stream.DataSize - pAltStream->Stream.Pos) < 1 )
            Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 1);
          v33 = pAltStream->Stream.Pos;
          v34 = pAltStream->Stream.pBuffer[v33];
          pAltStream->Stream.Pos = v33 + 1;
          pc.Channels.Alpha = v34;
        }
        Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(&pAltStream->Stream, "  HasColor\n");
      }
      if ( v24 )
      {
        pAltStream->Stream.UnusedBits = 0;
        if ( (signed int)(pAltStream->Stream.DataSize - pAltStream->Stream.Pos) < 2 )
          Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
        v35 = pAltStream->Stream.Pos;
        v36 = (unsigned __int8)pAltStream->Stream.pBuffer[v35] | ((unsigned __int8)pAltStream->Stream.pBuffer[(unsigned int)(v35 + 1)] << 8);
        pAltStream->Stream.Pos = v35 + 2;
        v16 = (float)v36;
        Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(&pAltStream->Stream, "  XOffset = %g\n");
      }
      if ( v23 )
      {
        pAltStream->Stream.UnusedBits = 0;
        if ( (signed int)(pAltStream->Stream.DataSize - pAltStream->Stream.Pos) < 2 )
          Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
        v37 = pAltStream->Stream.Pos;
        v38 = (unsigned __int8)pAltStream->Stream.pBuffer[v37] | ((unsigned __int8)pAltStream->Stream.pBuffer[(unsigned int)(v37 + 1)] << 8);
        pAltStream->Stream.Pos = v37 + 2;
        v15 = (float)v38;
        Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(&pAltStream->Stream, "  YOffset = %g\n");
      }
      v39 = (_BYTE)v21 == 0;
      v8 = v52;
      v11 = HIDWORD(v55);
      v12 = v60;
      if ( !v39 )
      {
        pAltStream->Stream.UnusedBits = 0;
        if ( (signed int)(pAltStream->Stream.DataSize - pAltStream->Stream.Pos) < 2 )
          Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
        v40 = pAltStream->Stream.Pos;
        v41 = (unsigned __int8)pAltStream->Stream.pBuffer[v40] | ((unsigned __int8)pAltStream->Stream.pBuffer[(unsigned int)(v40 + 1)] << 8);
        pAltStream->Stream.Pos = v40 + 2;
        v13 = (float)v41;
        Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(&pAltStream->Stream, "  TextHeight = %g\n");
        v12 = v60;
      }
    }
  }
  Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(&pAltStream->Stream, "end text records\n");
  if ( HType == RH_Pointer && v14 && !_InterlockedDecrement((volatile signed __int32 *)(v14 + 8)) )
  {
    v47 = (__int64)v51;
    v48 = v51->pLib;
    if ( v48 )
    {
      v48->vfptr[1].__vecDelDtor(v48, (unsigned int)v51);
      *(_QWORD *)(v47 + 16) = 0i64;
    }
    (**(void (__fastcall ***)(__int64, __int64))v47)(v47, 1i64);
  }
}+ 16) = 0i64;
    }
    (**(void (__fastcall ***)(__int64, __int64))v47)(v47, 1i64);
  }
}

// File Line: 247
// RVA: 0x8C5030
bool __fastcall Scaleform::GFx::StaticTextDef::DefPointTestLocal(
        Scaleform::GFx::StaticTextDef *this,
        Scaleform::Render::Point<float> *pt,
        bool testShape,
        Scaleform::GFx::DisplayObjectBase *pinst)
{
  float y; // xmm0_4
  bool result; // al

  result = 0;
  if ( pt->x <= this->TextRect.x2 && pt->x >= this->TextRect.x1 )
  {
    y = pt->y;
    if ( y <= this->TextRect.y2 && y >= this->TextRect.y1 )
      return 1;
  }
  return result;
}

// File Line: 259
// RVA: 0x89CFE0
void __fastcall Scaleform::GFx::StaticTextCharacter::StaticTextCharacter(
        Scaleform::GFx::StaticTextCharacter *this,
        Scaleform::GFx::StaticTextDef *pdef,
        Scaleform::GFx::MovieDefImpl *pbindingDefImpl,
        Scaleform::GFx::ASMovieRootBase *pasRoot)
{
  Scaleform::GFx::StaticTextCharacter *v6; // rsi
  float x1; // xmm3_4
  float y1; // xmm0_4
  float x2; // xmm1_4
  float y2; // xmm2_4
  unsigned int v11; // r12d
  __int64 v12; // rcx
  Scaleform::GFx::StaticTextRecord *v13; // r13
  Scaleform::GFx::Resource *pObject; // r15
  Scaleform::GFx::ImportData *volatile Value; // rsi
  Scaleform::GFx::MovieDefImpl *v16; // rbx
  unsigned int v17; // r15d
  __int64 v18; // rdi
  __int64 v19; // rdi
  Scaleform::Log *v20; // r14
  Scaleform::Render::Text::LineBuffer *v21; // r14
  Scaleform::GFx::Resource *vfptr; // rdi
  unsigned __int64 v23; // rsi
  Scaleform::Render::Text::LineBuffer::Line *inserted; // rax
  __int64 v25; // rdi
  bool v26; // zf
  int v27; // eax
  float y; // xmm2_4
  float x; // xmm3_4
  int v30; // xmm1_4
  float TextHeight; // xmm4_4
  float v32; // xmm3_4
  float v33; // xmm2_4
  int v34; // eax
  float v35; // xmm6_4
  float v36; // xmm2_4
  float v37; // xmm3_4
  __int64 v38; // rsi
  Scaleform::Render::Text::LineBuffer::FormatDataEntry *FormatData; // rdx
  __int64 v40; // r8
  unsigned int v41; // r12d
  __int64 v42; // r9
  unsigned int v43; // r15d
  float v44; // r10d
  Scaleform::GFx::Resource *v45; // rbx
  unsigned int v46; // edi
  int GlyphAdvance; // eax
  float v48; // xmm1_4
  int v49; // eax
  unsigned int v50; // edi
  int v51; // eax
  float v52; // xmm6_4
  int v53; // ecx
  int v54; // edx
  int v55; // ecx
  int v56; // eax
  float v57; // xmm2_4
  float v58; // xmm1_4
  Scaleform::GFx::Resource *v59; // rdi
  Scaleform::GFx::ResourceLibBase *pLib; // rcx
  Scaleform::Log *v61; // rdi
  Scaleform::GFx::Resource *v62; // rdi
  Scaleform::GFx::ResourceLibBase *v63; // rcx
  Scaleform::Render::Rect<float> pr; // [rsp+30h] [rbp-98h] BYREF
  unsigned int v65; // [rsp+40h] [rbp-88h]
  unsigned int v66; // [rsp+44h] [rbp-84h]
  Scaleform::Render::Text::LineBuffer *p_TextGlyphRecords; // [rsp+48h] [rbp-80h]
  void *v68; // [rsp+50h] [rbp-78h]
  Scaleform::Render::Matrix2x4<float> MatrixPriv; // [rsp+58h] [rbp-70h] BYREF
  Scaleform::Render::Matrix2x4<float> m; // [rsp+78h] [rbp-50h] BYREF
  Scaleform::Ptr<Scaleform::Log> v71; // [rsp+98h] [rbp-30h] BYREF
  int Raw; // [rsp+A0h] [rbp-28h]
  Scaleform::GFx::ResourceBindData result; // [rsp+A8h] [rbp-20h] BYREF
  float v74; // [rsp+B8h] [rbp-10h]
  unsigned __int64 Size; // [rsp+C0h] [rbp-8h]
  Scaleform::Ptr<Scaleform::Log> v76; // [rsp+C8h] [rbp+0h] BYREF
  __int64 v77; // [rsp+D0h] [rbp+8h]
  Scaleform::Render::Text::LineBuffer *v78; // [rsp+D8h] [rbp+10h]
  unsigned int v79; // [rsp+F0h] [rbp+28h]
  unsigned int v80; // [rsp+F8h] [rbp+30h]
  Scaleform::GFx::StaticTextCharacter *v81; // [rsp+1C8h] [rbp+100h]
  Scaleform::GFx::StaticTextDef *v82; // [rsp+1D0h] [rbp+108h]
  Scaleform::GFx::MovieDefImpl *v83; // [rsp+1D8h] [rbp+110h]
  Scaleform::GFx::InteractiveObject *v84; // [rsp+1E8h] [rbp+120h]
  int *vars0; // [rsp+1F0h] [rbp+128h]

  v77 = -2i64;
  v6 = this;
  v74 = *(float *)vars0;
  MatrixPriv.M[0][0] = v74;
  Scaleform::GFx::DisplayObjectBase::DisplayObjectBase(this, pasRoot, v84, (unsigned int *)&MatrixPriv);
  v6->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::GFx::DisplayObject::`vftable{for `Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>};
  v6->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>Vtbl *)&Scaleform::GFx::DisplayObject::`vftable{for `Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>};
  v6->pNameHandle.pObject = 0i64;
  v6->pScrollRect = 0i64;
  v6->pMaskCharacter = 0i64;
  v6->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags |= 0x100u;
  v6->Scaleform::GFx::DisplayObject::Flags = 10;
  v6->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::GFx::StaticTextCharacter::`vftable{for `Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>};
  v6->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>Vtbl *)&Scaleform::GFx::StaticTextCharacter::`vftable{for `Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>};
  if ( pdef )
    _InterlockedExchangeAdd(&pdef->RefCount.Value, 1u);
  v6->pDef.pObject = pdef;
  *(_QWORD *)&v6->OrigMatrix.M[0][0] = 1065353216i64;
  *(_QWORD *)&v6->OrigMatrix.M[0][2] = 0i64;
  v6->OrigMatrix.M[1][0] = 0.0;
  *(_QWORD *)&v6->OrigMatrix.M[1][1] = 1065353216i64;
  v6->OrigMatrix.M[1][3] = 0.0;
  p_TextGlyphRecords = &v6->TextGlyphRecords;
  Scaleform::Render::Text::LineBuffer::LineBuffer(&v6->TextGlyphRecords);
  Scaleform::Render::Text::TextFilter::TextFilter(&v6->Filter);
  v6->pHighlight = 0i64;
  v6->Flags = 0;
  MatrixPriv = pdef->MatrixPriv;
  m = MatrixPriv;
  Scaleform::Render::Matrix2x4<float>::SetInverse(&MatrixPriv, &m);
  Scaleform::Render::Matrix2x4<float>::EncloseTransform(&MatrixPriv, &pr, &pdef->TextRect);
  LODWORD(vars0) = 0;
  x1 = pr.x1;
  if ( pr.x1 >= 0.0 )
  {
    x1 = 0.0;
    pr.x1 = 0.0;
  }
  y1 = pr.y1;
  if ( pr.y1 >= 0.0 )
  {
    y1 = 0.0;
    pr.y1 = 0.0;
  }
  x2 = pr.x2;
  if ( pr.x2 <= 0.0 )
  {
    x2 = 0.0;
    pr.x2 = 0.0;
  }
  y2 = pr.y2;
  if ( pr.y2 <= 0.0 )
  {
    y2 = 0.0;
    pr.y2 = 0.0;
  }
  v11 = 0;
  v66 = 0;
  Size = pdef->TextRecords.Records.Data.Size;
  v12 = 0i64;
  *(_QWORD *)&MatrixPriv.M[1][0] = 0i64;
  if ( (_DWORD)Size )
  {
    while ( 1 )
    {
      v13 = pdef->TextRecords.Records.Data.Data[v12];
      Scaleform::GFx::ResourceBinding::GetResourceData(
        &pbindingDefImpl->pBindData.pObject->ResourceBinding,
        &result,
        &v13->pFont);
      pObject = result.pResource.pObject;
      *(_QWORD *)&MatrixPriv.M[0][2] = result.pResource.pObject;
      if ( !result.pResource.pObject )
        break;
      if ( (pdef->Flags & 2) == 0 )
      {
        Value = pbindingDefImpl->pBindData.pObject->pDataDef.pObject->pData.pObject->BindData.pImports.Value;
        if ( Value )
        {
          v16 = v83;
          do
          {
            v17 = 0;
            if ( Value->Imports.Data.Size )
            {
              v18 = 0i64;
              do
              {
                v19 = v18;
                if ( Value->Imports.Data.Data[v19].BindIndex == v13->pFont.BindIndex )
                {
                  v20 = Scaleform::GFx::StateBag::GetLog(&v16->Scaleform::GFx::StateBag, &v76)->pObject;
                  if ( v76.pObject )
                    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v76.pObject);
                  if ( v20 )
                    Scaleform::Log::LogWarning(
                      v20,
                      "Static text uses imported font! FontId = %d, import name = %s",
                      v13->FontId,
                      (const char *)((Value->Imports.Data.Data[v19].SymbolName.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64)
                                   + 12));
                }
                v18 = ++v17;
              }
              while ( v17 < Value->Imports.Data.Size );
            }
            Value = Value->pNext.Value;
          }
          while ( Value );
          pObject = *(Scaleform::GFx::Resource **)&MatrixPriv.M[0][2];
          v11 = v66;
        }
      }
      v21 = (Scaleform::Render::Text::LineBuffer *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                                     Scaleform::Memory::pGlobalHeap,
                                                     64i64);
      p_TextGlyphRecords = v21;
      v68 = v21;
      if ( v21 )
      {
        vfptr = (Scaleform::GFx::Resource *)pObject[1].vfptr;
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
        if ( vfptr )
          Scaleform::Render::RenderBuffer::AddRef(vfptr);
        *(_QWORD *)&v21->Geom.VisibleRect.x1 = vfptr;
        v21->Lines.Data.Data = (Scaleform::Render::Text::LineBuffer::Line **)&Scaleform::GFx::FontHandle::`vftable;
        *(_QWORD *)&v21->Geom.VisibleRect.x2 = 0i64;
      }
      else
      {
        v21 = 0i64;
        p_TextGlyphRecords = 0i64;
      }
      v78 = v21;
      v23 = v13->Glyphs.Data.Size;
      *(_QWORD *)&m.M[0][0] = v23;
      if ( (unsigned int)v23 > 0xFF || (HIDWORD(pObject[1].vfptr->GetResourceReport) & 0x2000) != 0 )
        inserted = Scaleform::Render::Text::LineBuffer::InsertNewLine(p_TextGlyphRecords, v11, v23, 2u, Line32);
      else
        inserted = Scaleform::Render::Text::LineBuffer::InsertNewLine(p_TextGlyphRecords, v11, v23, 2u, Line8);
      v25 = (__int64)inserted;
      v68 = inserted;
      v26 = (inserted->MemSize & 0x80000000) == 0;
      v27 = (int)vars0;
      if ( v26 )
      {
        *(_DWORD *)(v25 + 8) = (_DWORD)vars0;
      }
      else
      {
        *(_DWORD *)(v25 + 8) &= 0xFF000000;
        *(_DWORD *)(v25 + 8) |= v27 & 0xFFFFFF;
        v27 = (int)vars0;
      }
      LODWORD(vars0) = v23 + v27;
      y = v13->Offset.y;
      x = v13->Offset.x;
      v30 = LODWORD(pr.y1) ^ _xmm[0];
      if ( (HIDWORD(pObject[1].vfptr->GetResourceReport) & 0x2000) != 0 )
      {
        TextHeight = v13->TextHeight;
        v32 = x + COERCE_FLOAT(LODWORD(pr.x1) ^ _xmm[0]);
        v33 = (float)(y - TextHeight) + *(float *)&v30;
        v34 = (int)TextHeight;
        if ( *(int *)v25 >= 0 )
          *(_WORD *)(v25 + 38) = v34;
        else
          *(_WORD *)(v25 + 26) = v34;
        v35 = *((float *)&pObject[1].vfptr->GetResourceTypeCode + 1) * (float)(TextHeight * 0.0009765625)
            + v13->TextHeight;
      }
      else
      {
        v32 = x + COERCE_FLOAT(LODWORD(pr.x1) ^ _xmm[0]);
        v33 = *(float *)&v30 + y;
        v35 = 0.0;
      }
      if ( v33 <= 0.0 )
        v36 = v33 - 0.5;
      else
        v36 = v33 + 0.5;
      if ( v32 <= 0.0 )
        v37 = v32 - 0.5;
      else
        v37 = v32 + 0.5;
      *(_DWORD *)(v25 + 12) = (int)v37;
      *(_DWORD *)(v25 + 16) = (int)v36;
      if ( *(int *)v25 >= 0 )
        *(_QWORD *)(v25 + 20) = 0i64;
      else
        *(_DWORD *)(v25 + 20) = 0;
      v38 = v25 + 30;
      if ( *(int *)v25 >= 0 )
        v38 = v25 + 42;
      FormatData = Scaleform::Render::Text::LineBuffer::Line::GetFormatData((Scaleform::Render::Text::LineBuffer::Line *)v25);
      *(_QWORD *)&MatrixPriv.M[1][2] = FormatData;
      v41 = 0;
      v79 = 0;
      v65 = 0;
      v80 = 0;
      v42 = 0i64;
      v43 = 0;
      v44 = m.M[0][0];
      if ( LODWORD(m.M[0][0]) )
      {
        v45 = (Scaleform::GFx::Resource *)p_TextGlyphRecords;
        v46 = 0;
        do
        {
          *(_DWORD *)(v38 + 8i64 * v41) = 0;
          *(_DWORD *)(v38 + 8i64 * v41 + 4) = 4096;
          v40 = v43;
          *(_WORD *)(v38 + 8i64 * v41) = v13->Glyphs.Data.Data[v43].GlyphIndex;
          GlyphAdvance = (int)v13->Glyphs.Data.Data[v43].GlyphAdvance;
          if ( GlyphAdvance < 0 )
          {
            *(_WORD *)(v38 + 8i64 * v41 + 2) = abs32(GlyphAdvance);
            *(_WORD *)(v38 + 8i64 * v41 + 6) = 64;
            FormatData = *(Scaleform::Render::Text::LineBuffer::FormatDataEntry **)&MatrixPriv.M[1][2];
          }
          else
          {
            *(_WORD *)(v38 + 8i64 * v41 + 2) = GlyphAdvance;
            *(_WORD *)(v38 + 8i64 * v41 + 6) = 0;
          }
          v42 = (unsigned int)((int)v13->Glyphs.Data.Data[v43].GlyphAdvance + v42);
          v65 = v42;
          v48 = v13->TextHeight * 0.050000001;
          if ( v48 < 256.0 && (v49 = (int)(float)(v48 * 16.0), (v49 & 0xF) != 0) )
          {
            *(_WORD *)(v38 + 8i64 * v41 + 6) |= 0x10u;
          }
          else
          {
            *(_WORD *)(v38 + 8i64 * v41 + 6) &= ~0x10u;
            v49 = (int)v48;
          }
          *(_WORD *)(v38 + 8i64 * v41 + 4) = v49 & 0xFFF | 0x1000;
          if ( !v43 )
          {
            *(_WORD *)(v38 + 8i64 * v41 + 6) |= 0x4000u;
            *(_WORD *)(v38 + 8i64 * v41 + 6) |= 0x2000u;
            FormatData[v46].pFont = (Scaleform::Render::Text::FontHandle *)v45;
            v50 = v46 + 1;
            Scaleform::Render::RenderBuffer::AddRef(v45);
            Raw = v13->ColorV.Raw;
            v51 = Raw;
            *(_WORD *)(v38 + 8i64 * v41 + 6) |= 0x4000u;
            *(_WORD *)(v38 + 8i64 * v41 + 6) |= 0x1000u;
            FormatData = *(Scaleform::Render::Text::LineBuffer::FormatDataEntry **)&MatrixPriv.M[1][2];
            *(_DWORD *)(*(_QWORD *)&MatrixPriv.M[1][2] + 8i64 * v50) = v51;
            v46 = v50 + 1;
            v80 = v46;
            v42 = v65;
            v44 = m.M[0][0];
          }
          ++v43;
          if ( v38 && v41 < LODWORD(v44) )
            ++v41;
        }
        while ( v43 < LODWORD(v44) );
        v79 = v41;
        v25 = (__int64)v68;
        v21 = p_TextGlyphRecords;
      }
      if ( (*(_DWORD *)(*(_QWORD *)(*(_QWORD *)&MatrixPriv.M[0][2] + 24i64) + 28i64) & 0x2000) != 0 )
      {
        if ( v35 <= 0.0 )
          v52 = v35 - 0.5;
        else
          v52 = v35 + 0.5;
        v53 = (int)v52;
        if ( (int)v42 < 0 )
          v42 = 0i64;
        if ( *(int *)v25 >= 0 )
        {
          *(_DWORD *)(v25 + 20) = v42;
          *(_DWORD *)(v25 + 24) = v53;
        }
        else
        {
          *(_WORD *)(v25 + 20) = v42;
          *(_WORD *)(v25 + 22) = v53;
        }
        if ( *(int *)v25 >= 0 )
          *(float *)(v25 + 32) = v44;
        else
          *(_BYTE *)(v25 + 11) = LOBYTE(v44);
        v40 = *(unsigned int *)(v25 + 16);
        if ( *(int *)v25 >= 0 )
          v54 = *(_DWORD *)(v25 + 24);
        else
          v54 = *(unsigned __int16 *)(v25 + 22);
        if ( *(int *)v25 >= 0 )
          v56 = *(_DWORD *)(v25 + 20);
        else
          v56 = *(unsigned __int16 *)(v25 + 20);
        v55 = *(_DWORD *)(v25 + 12);
        v57 = (float)(v55 + v56);
        v58 = (float)(v54 + v40);
        if ( pr.x1 >= v57 )
          pr.x1 = (float)(v55 + v56);
        if ( pr.y1 >= v58 )
          pr.y1 = (float)(v54 + v40);
        if ( v57 >= pr.x2 )
          pr.x2 = (float)(v55 + v56);
        if ( v58 >= pr.y2 )
          pr.y2 = (float)(v54 + v40);
      }
      if ( v21 )
        Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v21);
      v59 = result.pResource.pObject;
      if ( result.pResource.pObject && !_InterlockedDecrement(&result.pResource.pObject->RefCount.Value) )
      {
        pLib = v59->pLib;
        if ( pLib )
        {
          ((void (__fastcall *)(Scaleform::GFx::ResourceLibBase *, Scaleform::GFx::Resource *, __int64, __int64))pLib->vfptr[1].__vecDelDtor)(
            pLib,
            v59,
            v40,
            v42);
          v59->pLib = 0i64;
        }
        v59->vfptr->__vecDelDtor(v59, 1u);
      }
      v11 = v66 + 1;
      v66 = v11;
      v12 = ++*(_QWORD *)&MatrixPriv.M[1][0];
      pbindingDefImpl = v83;
      pdef = v82;
      if ( v11 >= (unsigned int)Size )
      {
        y2 = pr.y2;
        x2 = pr.x2;
        y1 = pr.y1;
        x1 = pr.x1;
        v6 = v81;
        goto LABEL_116;
      }
    }
    v61 = Scaleform::GFx::StateBag::GetLog(&pbindingDefImpl->Scaleform::GFx::StateBag, &v71)->pObject;
    if ( v71.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v71.pObject);
    if ( v61 )
      Scaleform::Log::LogError(v61, "Text style with undefined font; FontId = %d", v13->FontId);
    v62 = result.pResource.pObject;
    if ( result.pResource.pObject && !_InterlockedDecrement(&result.pResource.pObject->RefCount.Value) )
    {
      v63 = v62->pLib;
      if ( v63 )
      {
        v63->vfptr[1].__vecDelDtor(v63, (unsigned int)v62);
        v62->pLib = 0i64;
      }
      v62->vfptr->__vecDelDtor(v62, 1u);
    }
  }
  else
  {
LABEL_116:
    v6->TextGlyphRecords.Geom.VisibleRect.x1 = x1;
    v6->TextGlyphRecords.Geom.VisibleRect.y1 = y1;
    v6->TextGlyphRecords.Geom.VisibleRect.x2 = x2;
    v6->TextGlyphRecords.Geom.VisibleRect.y2 = y2;
    v6->TextGlyphRecords.Geom.Flags |= 4u;
    Scaleform::Render::Text::TextFilter::SetDefaultShadow(&v6->Filter);
    pdef->Flags |= 2u;
    Scaleform::GFx::StaticTextCharacter::RecreateVisibleTextLayout(v6);
  }
}

// File Line: 417
// RVA: 0x8A7CE0
void __fastcall Scaleform::GFx::StaticTextCharacter::~StaticTextCharacter(Scaleform::GFx::StaticTextCharacter *this)
{
  Scaleform::GFx::StaticTextCharacter::HighlightDesc *pHighlight; // rdi
  Scaleform::Render::RenderBuffer *pObject; // rcx
  Scaleform::GFx::StaticTextDef *v4; // rdi
  Scaleform::GFx::ResourceLibBase *pLib; // rcx

  this->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::GFx::StaticTextCharacter::`vftable{for `Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>};
  this->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>Vtbl *)&Scaleform::GFx::StaticTextCharacter::`vftable{for `Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>};
  pHighlight = this->pHighlight;
  if ( pHighlight )
  {
    Scaleform::Memory::pGlobalHeap->vfptr->Free(
      Scaleform::Memory::pGlobalHeap,
      pHighlight->HighlightManager.Highlighters.Data.Data);
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, pHighlight);
  }
  pObject = (Scaleform::Render::RenderBuffer *)this->Filter.ShadowParams.Gradient.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  Scaleform::RefCountNTSImplCore::~RefCountNTSImplCore(&this->Filter);
  Scaleform::Render::Text::LineBuffer::~LineBuffer(&this->TextGlyphRecords);
  v4 = this->pDef.pObject;
  if ( v4 && !_InterlockedDecrement(&v4->RefCount.Value) )
  {
    pLib = v4->pLib;
    if ( pLib )
    {
      pLib->vfptr[1].__vecDelDtor(pLib, (unsigned int)v4);
      v4->pLib = 0i64;
    }
    v4->vfptr->__vecDelDtor(v4, 1u);
  }
  Scaleform::GFx::DisplayObject::~DisplayObject(this);
}

// File Line: 440
// RVA: 0x909690
void __fastcall Scaleform::GFx::StaticTextCharacter::SetMatrix(
        Scaleform::GFx::StaticTextCharacter *this,
        Scaleform::Render::Matrix2x4<float> *m)
{
  float *pObject; // rax
  float v3; // xmm7_4
  float v4; // xmm6_4
  float v5; // xmm8_4
  float v6; // xmm5_4
  float v7; // xmm3_4
  float v8; // xmm4_4
  float v9; // xmm2_4
  float v10; // xmm0_4
  Scaleform::Render::Matrix2x4<float> mt; // [rsp+20h] [rbp-58h] BYREF

  this->OrigMatrix = *m;
  pObject = (float *)this->pDef.pObject;
  v3 = m->M[0][0];
  v4 = m->M[0][1];
  v5 = m->M[1][0];
  v6 = m->M[1][1];
  v7 = m->M[0][3];
  v8 = m->M[1][3];
  mt.M[0][2] = m->M[0][2];
  mt.M[0][3] = v7;
  mt.M[1][0] = v5;
  mt.M[1][3] = v8;
  *(_QWORD *)&mt.M[0][0] = __PAIR64__(LODWORD(v4), LODWORD(v3));
  *(_QWORD *)&mt.M[1][1] = LODWORD(v6);
  mt.M[0][0] = (float)(v4 * pObject[16]) + (float)(v3 * pObject[12]);
  mt.M[1][0] = (float)(v6 * pObject[16]) + (float)(v5 * pObject[12]);
  mt.M[0][1] = (float)(v3 * pObject[13]) + (float)(v4 * pObject[17]);
  v9 = v5 * pObject[13];
  v10 = v6 * pObject[17];
  mt.M[0][2] = 0.0;
  mt.M[1][1] = v9 + v10;
  mt.M[0][3] = v7 + (float)((float)(v4 * pObject[19]) + (float)(v3 * pObject[15]));
  mt.M[1][3] = v8 + (float)((float)(v5 * pObject[15]) + (float)(v6 * pObject[19]));
  Scaleform::GFx::DisplayObject::SetMatrix(this, &mt);
}

// File Line: 448
// RVA: 0x8DAFC0
Scaleform::Render::Matrix2x4<float> *__fastcall Scaleform::GFx::StaticTextCharacter::GetMatrix(
        Scaleform::GFx::StaticTextCharacter *this)
{
  return &this->OrigMatrix;
}

// File Line: 453
// RVA: 0x907190
void __fastcall Scaleform::GFx::StaticTextCharacter::SetFilters(
        Scaleform::GFx::StaticTextCharacter *this,
        Scaleform::Render::FilterSet *filters)
{
  unsigned int i; // ebx
  Scaleform::Render::Filter *Filter; // rax
  Scaleform::Render::Text::TextFilter v6; // [rsp+30h] [rbp-68h] BYREF

  if ( filters )
  {
    Scaleform::Render::Text::TextFilter::TextFilter(&v6);
    for ( i = 0;
          i < (unsigned int)BasicArrayImplementation<hkDataArrayImpl *>::getSize((BasicArrayImplementation<hkDataObjectImpl *> *)filters);
          ++i )
    {
      Filter = Scaleform::Render::FilterSet::GetFilter(filters, i);
      Scaleform::Render::Text::TextFilter::LoadFilterDesc(&v6, Filter);
    }
    this->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[85].__vecDelDtor(
      this,
      (unsigned int)&v6);
    if ( v6.ShadowParams.Gradient.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v6.ShadowParams.Gradient.pObject);
    Scaleform::RefCountNTSImplCore::~RefCountNTSImplCore(&v6);
  }
}

// File Line: 467
// RVA: 0x8C2980
Scaleform::Ptr<Scaleform::Render::TreeNode> *__fastcall Scaleform::GFx::StaticTextCharacter::CreateRenderNode(
        Scaleform::GFx::StaticTextCharacter *this,
        Scaleform::Ptr<Scaleform::Render::TreeNode> *result,
        Scaleform::Render::ContextImpl::Context *context)
{
  Scaleform::Render::TreeText::NodeData *v5; // rax
  Scaleform::Render::ContextImpl::EntryData *v6; // rdi
  Scaleform::Render::TreeNode *EntryHelper; // rax

  v5 = (Scaleform::Render::TreeText::NodeData *)context->pHeap->vfptr->Alloc(context->pHeap, 176i64, 0i64);
  v6 = v5;
  if ( v5 )
    Scaleform::Render::TreeText::NodeData::NodeData(v5);
  EntryHelper = (Scaleform::Render::TreeNode *)Scaleform::Render::ContextImpl::Context::createEntryHelper(context, v6);
  if ( EntryHelper )
    ++EntryHelper->RefCount;
  result->pObject = EntryHelper;
  if ( EntryHelper )
  {
    if ( EntryHelper->RefCount-- == 1 )
      Scaleform::Render::ContextImpl::Entry::destroyHelper(EntryHelper);
  }
  return result;
}

// File Line: 473
// RVA: 0x8FE2D0
void __fastcall Scaleform::GFx::StaticTextCharacter::RecreateVisibleTextLayout(
        Scaleform::GFx::StaticTextCharacter *this)
{
  Scaleform::Render::TreeText *RenderNode; // rdi
  Scaleform::GFx::StaticTextCharacter::HighlightDesc *pHighlight; // rcx
  float y2; // xmm3_4
  float x2; // xmm2_4
  float y1; // xmm1_4
  Scaleform::Render::TextFieldParam params; // [rsp+20h] [rbp-D8h] BYREF
  __int64 v8; // [rsp+60h] [rbp-98h]
  Scaleform::Render::TextLayout::Builder bld; // [rsp+70h] [rbp-88h] BYREF

  v8 = -2i64;
  RenderNode = (Scaleform::Render::TreeText *)Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
  Scaleform::Render::TextLayout::Builder::Builder(&bld, Scaleform::Memory::pGlobalHeap);
  pHighlight = this->pHighlight;
  if ( pHighlight && !pHighlight->HighlightManager.Valid )
  {
    Scaleform::Render::Text::Highlighter::UpdateGlyphIndices(&pHighlight->HighlightManager, 0i64);
    this->pHighlight->HighlightManager.Valid = 1;
  }
  params.TextParam.pFont = 0i64;
  *(_QWORD *)&params.TextParam.GlyphIndex = 0i64;
  *(_DWORD *)&params.TextParam.BlurY = 0x100000;
  params.ShadowParam.pFont = 0i64;
  *(_QWORD *)&params.ShadowParam.GlyphIndex = 0i64;
  *(_DWORD *)&params.ShadowParam.BlurY = 0x100000;
  *(_QWORD *)&params.ShadowColor = 0i64;
  params.ShadowOffsetY = 0.0;
  Scaleform::Render::Text::LoadTextFieldParamFromTextFilter(&params, &this->Filter);
  if ( (this->pDef.pObject->Flags & 1) != 0 )
  {
    params.TextParam.Flags |= 3u;
    params.ShadowParam.Flags |= 3u;
  }
  Scaleform::Render::Text::LineBuffer::CreateVisibleTextLayout(
    &this->TextGlyphRecords,
    &bld,
    &this->pHighlight->HighlightManager,
    &params);
  y2 = this->TextGlyphRecords.Geom.VisibleRect.y2;
  x2 = this->TextGlyphRecords.Geom.VisibleRect.x2;
  y1 = this->TextGlyphRecords.Geom.VisibleRect.y1;
  bld.Param.ShadowOffsetY = this->TextGlyphRecords.Geom.VisibleRect.x1;
  *(&bld.Param.ShadowOffsetY + 1) = y1;
  bld.Bounds.x1 = x2;
  bld.Bounds.y1 = y2;
  Scaleform::Render::TreeText::SetLayout(RenderNode, &bld);
  Scaleform::Render::TextLayout::Builder::~Builder(&bld);
}

// File Line: 994
// RVA: 0x86DC10
void __fastcall Scaleform::GFx::GFx_DefineTextLoader(Scaleform::GFx::LoadProcess *p, Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::SWFProcessInfo *pAltStream; // rbx
  __int64 Pos; // r8
  unsigned __int16 v6; // bp
  __int64 v7; // rax
  Scaleform::GFx::StaticTextDef *v8; // rbx
  Scaleform::GFx::ResourceLibBase *pLib; // rcx
  Scaleform::GFx::ResourceId rid; // [rsp+70h] [rbp+8h] BYREF
  Scaleform::MemoryHeap *pHeap; // [rsp+78h] [rbp+10h]
  __int64 v12; // [rsp+80h] [rbp+18h]
  __int64 v13; // [rsp+88h] [rbp+20h]

  pAltStream = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  if ( !pAltStream )
    pAltStream = &p->ProcessInfo;
  pAltStream->Stream.UnusedBits = 0;
  if ( (signed int)(pAltStream->Stream.DataSize - pAltStream->Stream.Pos) < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
  Pos = pAltStream->Stream.Pos;
  v6 = (unsigned __int8)pAltStream->Stream.pBuffer[Pos] | ((unsigned __int8)pAltStream->Stream.pBuffer[(unsigned int)(Pos + 1)] << 8);
  pAltStream->Stream.Pos = Pos + 2;
  pHeap = p->pLoadData.pObject->pHeap;
  v7 = ((__int64 (__fastcall *)(Scaleform::GFx::LoadProcess *, __int64))pHeap->vfptr->Alloc)(p, 112i64);
  v8 = (Scaleform::GFx::StaticTextDef *)v7;
  v12 = v7;
  if ( v7 )
  {
    *(_QWORD *)v7 = &Scaleform::GFx::Resource::`vftable;
    *(_DWORD *)(v7 + 8) = 1;
    *(_QWORD *)(v7 + 16) = 0i64;
    *(_QWORD *)v7 = &Scaleform::GFx::CharacterDef::`vftable;
    *(_DWORD *)(v7 + 24) = 0x40000;
    *(_QWORD *)v7 = &Scaleform::GFx::StaticTextDef::`vftable;
    *(_QWORD *)(v7 + 32) = 0i64;
    *(_QWORD *)(v7 + 40) = 0i64;
    *(_QWORD *)(v7 + 48) = 1065353216i64;
    *(_QWORD *)(v7 + 56) = 0i64;
    *(_DWORD *)(v7 + 64) = 0;
    *(_QWORD *)(v7 + 68) = 1065353216i64;
    *(_DWORD *)(v7 + 76) = 0;
    v13 = v7 + 80;
    *(_QWORD *)(v7 + 80) = 0i64;
    *(_QWORD *)(v7 + 88) = 0i64;
    *(_QWORD *)(v7 + 96) = 0i64;
    *(_BYTE *)(v7 + 104) = 0;
  }
  else
  {
    v8 = 0i64;
  }
  Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
    (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>,
    "TextCharacter, id = %d\n",
    v6);
  Scaleform::GFx::StaticTextDef::Read(v8, p, tagInfo->TagType);
  if ( p->LoadState == LS_LoadingRoot )
  {
    rid.Id = v6;
    Scaleform::GFx::MovieDataDef::LoadTaskData::AddResource(p->pLoadData.pObject, (Scaleform::GFx::ResourceId)&rid, v8);
  }
  if ( v8 && !_InterlockedDecrement(&v8->RefCount.Value) )
  {
    pLib = v8->pLib;
    if ( pLib )
    {
      pLib->vfptr[1].__vecDelDtor(pLib, (unsigned int)v8);
      v8->pLib = 0i64;
    }
    v8->vfptr->__vecDelDtor(v8, 1u);
  }
}

