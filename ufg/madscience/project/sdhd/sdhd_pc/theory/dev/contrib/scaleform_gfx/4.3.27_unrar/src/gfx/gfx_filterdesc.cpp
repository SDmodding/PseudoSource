// File Line: 126
// RVA: 0x889410
void __fastcall Scaleform::GFx::ReadBlurFilter<Scaleform::GFx::Stream>(Scaleform::GFx::Stream *ps, Scaleform::Render::BlurFilterParams *params, float *angle, float *distance, unsigned int readConstants, Scaleform::Render::FilterType type, unsigned int passesMask)
{
  float *v7; // r14
  float *v8; // rbp
  Scaleform::Render::BlurFilterParams *v9; // r15
  Scaleform::GFx::Stream *v10; // rbx
  char v11; // r12
  signed int v12; // edi
  __int64 v13; // rdx
  __int64 v14; // rbp
  Scaleform::Render::GradientData *v15; // rax
  Scaleform::GFx::Resource *v16; // rax
  Scaleform::GFx::Resource *v17; // rsi
  __int64 v18; // r13
  __int64 v19; // rbp
  __int64 v20; // r12
  Scaleform::GFx::ResourceVtbl *v21; // r14
  __int64 v22; // rdx
  char v23; // cl
  __int64 v24; // rdx
  char v25; // cl
  __int64 v26; // rdx
  char v27; // cl
  __int64 v28; // rdx
  char v29; // cl
  __int64 v30; // r14
  __int64 v31; // rbp
  __int64 v32; // rcx
  char v33; // dl
  Scaleform::Render::RenderBuffer *v34; // rcx
  __int64 v35; // rdx
  char v36; // cl
  __int64 v37; // rdx
  char v38; // cl
  __int64 v39; // r9
  int v40; // er8
  __int64 v41; // r9
  int v42; // er8
  __int64 v43; // r9
  int v44; // er8
  __int64 v45; // r9
  int v46; // er8
  __int64 v47; // r9
  unsigned __int16 v48; // r8
  __int64 v49; // rdx
  unsigned int v50; // ecx
  unsigned int v51; // eax
  int v52; // [rsp+90h] [rbp+8h]
  float *v53; // [rsp+A0h] [rbp+18h]
  float *v54; // [rsp+A8h] [rbp+20h]

  v54 = distance;
  v53 = angle;
  v7 = distance;
  v8 = angle;
  v9 = params;
  v10 = ps;
  v11 = readConstants;
  v12 = 0;
  if ( readConstants & 0x10 )
  {
    ps->UnusedBits = 0;
    if ( (signed int)(ps->DataSize - ps->Pos) < 1 )
      Scaleform::GFx::Stream::PopulateBuffer(ps, 1);
    v13 = v10->Pos;
    v14 = (unsigned __int8)v10->pBuffer[v13];
    v10->Pos = v13 + 1;
    v15 = (Scaleform::Render::GradientData *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                               Scaleform::Memory::pGlobalHeap,
                                               48i64);
    if ( v15 )
    {
      Scaleform::Render::GradientData::GradientData(v15, 0, v14, 0);
      v17 = v16;
    }
    else
    {
      v17 = 0i64;
    }
    v18 = v14;
    if ( (_DWORD)v14 )
    {
      v19 = 0i64;
      v20 = v18;
      do
      {
        v21 = v17[1].vfptr;
        v10->UnusedBits = 0;
        if ( (signed int)(v10->DataSize - v10->Pos) < 1 )
          Scaleform::GFx::Stream::PopulateBuffer(v10, 1);
        v22 = v10->Pos;
        v23 = v10->pBuffer[v22];
        v10->Pos = v22 + 1;
        BYTE2(v52) = v23;
        v10->UnusedBits = 0;
        if ( (signed int)(v10->DataSize - (v22 + 1)) < 1 )
          Scaleform::GFx::Stream::PopulateBuffer(v10, 1);
        v24 = v10->Pos;
        v25 = v10->pBuffer[v24];
        v10->Pos = v24 + 1;
        BYTE1(v52) = v25;
        v10->UnusedBits = 0;
        if ( (signed int)(v10->DataSize - (v24 + 1)) < 1 )
          Scaleform::GFx::Stream::PopulateBuffer(v10, 1);
        v26 = v10->Pos;
        v27 = v10->pBuffer[v26];
        v10->Pos = v26 + 1;
        LOBYTE(v52) = v27;
        v10->UnusedBits = 0;
        if ( (signed int)(v10->DataSize - (v26 + 1)) < 1 )
          Scaleform::GFx::Stream::PopulateBuffer(v10, 1);
        v28 = v10->Pos;
        v29 = v10->pBuffer[v28];
        v10->Pos = v28 + 1;
        HIBYTE(v52) = v29;
        *(_DWORD *)((char *)&v21->__vecDelDtor + v19 + 4) = v52;
        v19 += 8i64;
        --v20;
      }
      while ( v20 );
      v11 = readConstants;
    }
    if ( (_DWORD)v18 )
    {
      v30 = 0i64;
      v31 = v18;
      do
      {
        v10->UnusedBits = 0;
        if ( (signed int)(v10->DataSize - v10->Pos) < 1 )
          Scaleform::GFx::Stream::PopulateBuffer(v10, 1);
        v32 = v10->Pos;
        v33 = v10->pBuffer[v32];
        v10->Pos = v32 + 1;
        *((_BYTE *)&v17[1].vfptr->__vecDelDtor + v30) = v33;
        v30 += 8i64;
        --v31;
      }
      while ( v31 );
    }
    if ( v17 )
      Scaleform::Render::RenderBuffer::AddRef(v17);
    v34 = (Scaleform::Render::RenderBuffer *)v9->Gradient.pObject;
    if ( v34 )
      Scaleform::RefCountImpl::Release(v34);
    v9->Gradient.pObject = (Scaleform::Render::GradientData *)v17;
    if ( v17 )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v17);
    v7 = v54;
    v8 = v53;
  }
  if ( v11 & 1 )
  {
    Scaleform::GFx::Stream::ReadRgb(v10, v9->Colors);
    v10->UnusedBits = 0;
    if ( (signed int)(v10->DataSize - v10->Pos) < 1 )
      Scaleform::GFx::Stream::PopulateBuffer(v10, 1);
    v35 = v10->Pos;
    v36 = v10->pBuffer[v35];
    v10->Pos = v35 + 1;
    v9->Colors[0].Channels.Alpha = v36;
    if ( v11 & 2 )
    {
      Scaleform::GFx::Stream::ReadRgb(v10, &v9->Colors[1]);
      v10->UnusedBits = 0;
      if ( (signed int)(v10->DataSize - v10->Pos) < 1 )
        Scaleform::GFx::Stream::PopulateBuffer(v10, 1);
      v37 = v10->Pos;
      v38 = v10->pBuffer[v37];
      v10->Pos = v37 + 1;
      v9->Colors[1].Channels.Alpha = v38;
    }
  }
  v10->UnusedBits = 0;
  if ( (signed int)(v10->DataSize - v10->Pos) < 4 )
    Scaleform::GFx::Stream::PopulateBuffer(v10, 4);
  v39 = v10->Pos;
  v40 = (unsigned __int8)v10->pBuffer[v39] | (((unsigned __int8)v10->pBuffer[(unsigned int)(v39 + 1)] | (((unsigned __int8)v10->pBuffer[(unsigned int)(v39 + 2)] | ((unsigned __int8)v10->pBuffer[(unsigned int)(v39 + 3)] << 8)) << 8)) << 8);
  v10->Pos = v39 + 4;
  v9->BlurX = (float)((float)v40 * 0.000015258789) * 20.0;
  v10->UnusedBits = 0;
  if ( (signed int)(v10->DataSize - v10->Pos) < 4 )
    Scaleform::GFx::Stream::PopulateBuffer(v10, 4);
  v41 = v10->Pos;
  v42 = (unsigned __int8)v10->pBuffer[v41] | (((unsigned __int8)v10->pBuffer[(unsigned int)(v41 + 1)] | (((unsigned __int8)v10->pBuffer[(unsigned int)(v41 + 2)] | ((unsigned __int8)v10->pBuffer[(unsigned int)(v41 + 3)] << 8)) << 8)) << 8);
  v10->Pos = v41 + 4;
  v9->BlurY = (float)((float)v42 * 0.000015258789) * 20.0;
  if ( v11 & 4 )
  {
    v10->UnusedBits = 0;
    if ( (signed int)(v10->DataSize - v10->Pos) < 4 )
      Scaleform::GFx::Stream::PopulateBuffer(v10, 4);
    v43 = v10->Pos;
    v44 = (unsigned __int8)v10->pBuffer[v43] | (((unsigned __int8)v10->pBuffer[(unsigned int)(v43 + 1)] | (((unsigned __int8)v10->pBuffer[(unsigned int)(v43 + 2)] | ((unsigned __int8)v10->pBuffer[(unsigned int)(v43 + 3)] << 8)) << 8)) << 8);
    v10->Pos = v43 + 4;
    *v8 = (float)v44 * 0.000015258789;
    v10->UnusedBits = 0;
    if ( (signed int)(v10->DataSize - v10->Pos) < 4 )
      Scaleform::GFx::Stream::PopulateBuffer(v10, 4);
    v45 = v10->Pos;
    v46 = (unsigned __int8)v10->pBuffer[v45] | (((unsigned __int8)v10->pBuffer[(unsigned int)(v45 + 1)] | (((unsigned __int8)v10->pBuffer[(unsigned int)(v45 + 2)] | ((unsigned __int8)v10->pBuffer[(unsigned int)(v45 + 3)] << 8)) << 8)) << 8);
    v10->Pos = v45 + 4;
    *v7 = (float)v46 * 0.000015258789;
  }
  if ( v11 & 8 )
  {
    v10->UnusedBits = 0;
    if ( (signed int)(v10->DataSize - v10->Pos) < 2 )
      Scaleform::GFx::Stream::PopulateBuffer(v10, 2);
    v47 = v10->Pos;
    v48 = (unsigned __int8)v10->pBuffer[v47] | (unsigned __int16)((unsigned __int8)v10->pBuffer[(unsigned int)(v47 + 1)] << 8);
    v10->Pos = v47 + 2;
    v9->Strength = (float)v48 * 0.00390625;
  }
  v10->UnusedBits = 0;
  if ( (signed int)(v10->DataSize - v10->Pos) < 1 )
    Scaleform::GFx::Stream::PopulateBuffer(v10, 1);
  v49 = v10->Pos;
  v50 = (unsigned __int8)v10->pBuffer[v49];
  v10->Pos = v49 + 1;
  if ( passesMask == 248 )
  {
    v51 = v50 >> 3;
  }
  else
  {
    if ( (v50 & 0x80u) != 0 )
      v12 = 32;
    if ( v50 & 0x40 )
      v12 |= 0x10u;
    if ( !(v50 & 0x20) )
      v12 |= 0x40u;
    if ( passesMask <= 0xF && v50 & 0x10 )
      v12 |= 0x80u;
    v51 = passesMask & v50;
  }
  v9->Passes = v51;
  v9->Mode = type | v12;
}
      v12 |= 0x80u;
    v51 = passesMask & v50;
  }
  v9->Passes = v51;
  v9->Mode = type | v12;
}

// File Line: 204
// RVA: 0x884510
__int64 __fastcall Scaleform::GFx::LoadFilters<Scaleform::GFx::StreamContext>(Scaleform::GFx::StreamContext *ps, Scaleform::Render::FilterSet *filters)
{
  Scaleform::Render::FilterSet *v2; // rsi
  Scaleform::GFx::StreamContext *v3; // rdi
  unsigned __int64 v4; // rdx
  char v5; // r15
  unsigned int v6; // er13
  Scaleform::MemoryHeap *v7; // r12
  unsigned __int64 v8; // rcx
  int v9; // edx
  int v10; // er14
  __int64 v11; // rbx
  Scaleform::Render::ShadowFilter *v12; // rax
  __int64 v13; // rax
  signed __int64 v14; // ST58_8
  float v15; // xmm2_4
  Scaleform::Render::GradientData *v16; // rax
  signed __int64 v17; // ST58_8
  float v18; // xmm2_4
  Scaleform::Render::GradientData *v19; // rax
  Scaleform::Render::BevelFilter *v20; // rax
  __int64 v21; // rax
  int type; // ebx
  Scaleform::Render::GradientFilter *v23; // rax
  __int64 v24; // rax
  unsigned __int64 v25; // rax
  const char *v26; // rdx
  int v27; // er8
  int v28; // ecx
  Scaleform::Render::ColorMatrixFilter *v29; // rax
  __int64 v30; // rax
  unsigned __int8 *v31; // r9
  signed __int64 v32; // r10
  unsigned __int64 v33; // r8
  unsigned __int64 v34; // r8
  unsigned __int64 v35; // r8
  unsigned __int64 v36; // r8
  unsigned __int64 v37; // r8
  unsigned __int64 v38; // r8
  unsigned __int64 v39; // r8
  unsigned __int64 v40; // r8
  unsigned __int64 v41; // r8
  unsigned __int64 v42; // r8
  unsigned int v43; // ecx
  unsigned __int64 v44; // rax
  Scaleform::Render::BlurFilterParams params; // [rsp+68h] [rbp-31h]
  int v47; // [rsp+100h] [rbp+67h]
  int v48; // [rsp+100h] [rbp+67h]
  int v49; // [rsp+100h] [rbp+67h]
  int v50; // [rsp+100h] [rbp+67h]
  int v51; // [rsp+100h] [rbp+67h]
  int v52; // [rsp+100h] [rbp+67h]
  int v53; // [rsp+100h] [rbp+67h]
  int v54; // [rsp+100h] [rbp+67h]
  int v55; // [rsp+100h] [rbp+67h]
  int v56; // [rsp+100h] [rbp+67h]
  Scaleform::Render::FilterSet *v57; // [rsp+108h] [rbp+6Fh]
  float distance; // [rsp+110h] [rbp+77h]
  float angle; // [rsp+118h] [rbp+7Fh]

  v57 = filters;
  v2 = filters;
  v3 = ps;
  if ( ps->CurBitIndex )
    ++ps->CurByteIndex;
  ps->CurBitIndex = 0;
  v4 = ps->CurByteIndex;
  v5 = ps->pData[v4];
  ps->CurByteIndex = v4 + 1;
  v6 = 0;
  angle = 0.0;
  distance = 0.0;
  if ( v2 )
    v7 = Scaleform::Memory::pGlobalHeap->vfptr->GetAllocHeap(Scaleform::Memory::pGlobalHeap, v2);
  else
    v7 = Scaleform::Memory::pGlobalHeap;
  while ( v5 )
  {
    --v5;
    if ( v3->CurBitIndex )
      ++v3->CurByteIndex;
    v3->CurBitIndex = 0;
    v8 = v3->CurByteIndex;
    v9 = (unsigned __int8)v3->pData[v8];
    v3->CurByteIndex = v8 + 1;
    v10 = 0;
    v11 = 0i64;
    params.Mode = 0;
    params.Passes = 1;
    params.BlurX = 100.0;
    *(_QWORD *)&params.BlurY = 1120403456i64;
    params.Offset.y = 0.0;
    params.Strength = 1.0;
    params.Gradient.pObject = 0i64;
    *(_DWORD *)&params.Colors[0].Channels.Green = 16711680;
    params.Colors[0].Channels.Blue = 0;
    *(_WORD *)&params.Colors[1].Channels.Green = 0;
    params.Colors[1].Channels.Alpha = 0;
    switch ( v9 )
    {
      case 0:
        Scaleform::GFx::ReadBlurFilter<Scaleform::GFx::StreamContext>(
          v3,
          &params,
          &angle,
          &distance,
          0xDu,
          Filter_Shadow,
          0x1Fu);
        v12 = (Scaleform::Render::ShadowFilter *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))v7->vfptr->Alloc)(
                                                   v7,
                                                   80i64);
        if ( v12 )
        {
          Scaleform::Render::ShadowFilter::ShadowFilter(v12, &params, angle, distance);
          v11 = v13;
        }
        else
        {
          v11 = 0i64;
        }
        break;
      case 1:
        Scaleform::GFx::ReadBlurFilter<Scaleform::GFx::StreamContext>(v3, &params, 0i64, 0i64, 0, 0, 0xF8u);
        v11 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))v7->vfptr->Alloc)(v7, 80i64);
        if ( v11 )
        {
          *(_QWORD *)v11 = &Scaleform::RefCountImplCore::`vftable;
          *(_DWORD *)(v11 + 8) = 1;
          *(_QWORD *)v11 = &Scaleform::RefCountImpl::`vftable;
          *(_QWORD *)v11 = &Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable;
          *(_QWORD *)v11 = &Scaleform::RefCountBase<Scaleform::Render::Filter,2>::`vftable;
          *(_QWORD *)v11 = &Scaleform::Render::Filter::`vftable;
          *(_DWORD *)(v11 + 16) = 0;
          *(_BYTE *)(v11 + 20) = 0;
          *(_QWORD *)v11 = &Scaleform::Render::BlurFilterImpl::`vftable;
          v14 = v11 + 24;
          *(_DWORD *)v14 = params.Mode;
          *(_DWORD *)(v14 + 4) = params.Passes;
          *(float *)(v14 + 8) = params.BlurX;
          *(float *)(v14 + 12) = params.BlurY;
          v15 = params.Offset.y;
          *(float *)(v14 + 16) = params.Offset.x;
          *(float *)(v14 + 20) = v15;
          *(float *)(v14 + 24) = params.Strength;
          *(_DWORD *)(v14 + 28) = params.Colors[0].Raw;
          *(_DWORD *)(v14 + 32) = params.Colors[1].Raw;
          v16 = params.Gradient.pObject;
          if ( params.Gradient.pObject )
          {
            Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)params.Gradient.pObject);
            v16 = params.Gradient.pObject;
          }
          *(_QWORD *)(v11 + 64) = v16;
          *(_QWORD *)(v11 + 72) = 0i64;
          *(_QWORD *)v11 = &Scaleform::Render::BlurFilter::`vftable;
          v2 = v57;
        }
        else
        {
          v11 = 0i64;
        }
        break;
      case 2:
        Scaleform::GFx::ReadBlurFilter<Scaleform::GFx::StreamContext>(v3, &params, 0i64, 0i64, 9u, Filter_Glow, 0x1Fu);
        v11 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))v7->vfptr->Alloc)(v7, 80i64);
        if ( v11 )
        {
          *(_QWORD *)v11 = &Scaleform::RefCountImplCore::`vftable;
          *(_DWORD *)(v11 + 8) = 1;
          *(_QWORD *)v11 = &Scaleform::RefCountImpl::`vftable;
          *(_QWORD *)v11 = &Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable;
          *(_QWORD *)v11 = &Scaleform::RefCountBase<Scaleform::Render::Filter,2>::`vftable;
          *(_QWORD *)v11 = &Scaleform::Render::Filter::`vftable;
          *(_DWORD *)(v11 + 16) = 2;
          *(_BYTE *)(v11 + 20) = 0;
          *(_QWORD *)v11 = &Scaleform::Render::BlurFilterImpl::`vftable;
          v17 = v11 + 24;
          *(_DWORD *)v17 = params.Mode;
          *(_DWORD *)(v17 + 4) = params.Passes;
          *(float *)(v17 + 8) = params.BlurX;
          *(float *)(v17 + 12) = params.BlurY;
          v18 = params.Offset.y;
          *(float *)(v17 + 16) = params.Offset.x;
          *(float *)(v17 + 20) = v18;
          *(float *)(v17 + 24) = params.Strength;
          *(_DWORD *)(v17 + 28) = params.Colors[0].Raw;
          *(_DWORD *)(v17 + 32) = params.Colors[1].Raw;
          v19 = params.Gradient.pObject;
          if ( params.Gradient.pObject )
          {
            Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)params.Gradient.pObject);
            v19 = params.Gradient.pObject;
          }
          *(_QWORD *)(v11 + 64) = v19;
          *(_QWORD *)(v11 + 72) = 0i64;
          *(_QWORD *)v11 = &Scaleform::Render::GlowFilter::`vftable;
          v2 = v57;
        }
        else
        {
          v11 = 0i64;
        }
        break;
      case 3:
        Scaleform::GFx::ReadBlurFilter<Scaleform::GFx::StreamContext>(
          v3,
          &params,
          &angle,
          &distance,
          0xFu,
          Filter_Bevel,
          0xFu);
        v20 = (Scaleform::Render::BevelFilter *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))v7->vfptr->Alloc)(
                                                  v7,
                                                  80i64);
        if ( v20 )
        {
          Scaleform::Render::BevelFilter::BevelFilter(v20, &params, angle, distance);
          v11 = v21;
        }
        else
        {
          v11 = 0i64;
        }
        break;
      case 4:
      case 7:
        type = (v9 != 4) + 4;
        Scaleform::GFx::ReadBlurFilter<Scaleform::GFx::StreamContext>(
          v3,
          &params,
          &angle,
          &distance,
          0x1Cu,
          (Scaleform::Render::FilterType)type,
          0xFu);
        v23 = (Scaleform::Render::GradientFilter *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))v7->vfptr->Alloc)(
                                                     v7,
                                                     88i64);
        if ( v23 )
        {
          Scaleform::Render::GradientFilter::GradientFilter(
            v23,
            (Scaleform::Render::FilterType)type,
            &params,
            angle,
            distance);
          v11 = v24;
        }
        else
        {
          v11 = 0i64;
        }
        break;
      case 5:
        if ( v3->CurBitIndex )
          ++v3->CurByteIndex;
        v3->CurBitIndex = 0;
        v25 = v3->CurByteIndex;
        v26 = v3->pData;
        v27 = (unsigned __int8)v3->pData[v25++];
        v3->CurByteIndex = v25;
        v3->CurBitIndex = 0;
        v28 = (unsigned __int8)v26[v25];
        v3->CurByteIndex = v25 + 1;
        v10 = 4 * v27 * v28 + 13;
        break;
      case 6:
        v29 = (Scaleform::Render::ColorMatrixFilter *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64, _QWORD, _QWORD))v7->vfptr->Alloc)(
                                                        v7,
                                                        104i64,
                                                        0i64,
                                                        0i64);
        if ( v29 )
        {
          Scaleform::Render::ColorMatrixFilter::ColorMatrixFilter(v29);
          v11 = v30;
        }
        else
        {
          v11 = 0i64;
        }
        if ( v11 )
          Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)v11);
        v31 = (unsigned __int8 *)&`Scaleform::GFx::LoadFilters<Scaleform::GFx::StreamContext>::`10::Index[1];
        v32 = 2i64;
        do
        {
          if ( v3->CurBitIndex )
            ++v3->CurByteIndex;
          v3->CurBitIndex = 0;
          v33 = v3->CurByteIndex;
          v47 = (unsigned __int8)v3->pData[v33] | (((unsigned __int8)v3->pData[v33 + 1] | (*(unsigned __int16 *)&v3->pData[v33 + 2] << 8)) << 8);
          v3->CurByteIndex = v33 + 4;
          *(_DWORD *)(v11 + 4i64 * *(v31 - 1) + 24) = v47;
          if ( v3->CurBitIndex )
            ++v3->CurByteIndex;
          v3->CurBitIndex = 0;
          v34 = v3->CurByteIndex;
          v48 = (unsigned __int8)v3->pData[v34] | (((unsigned __int8)v3->pData[v34 + 1] | (*(unsigned __int16 *)&v3->pData[v34 + 2] << 8)) << 8);
          v3->CurByteIndex = v34 + 4;
          *(_DWORD *)(v11 + 4i64 * *v31 + 24) = v48;
          if ( v3->CurBitIndex )
            ++v3->CurByteIndex;
          v3->CurBitIndex = 0;
          v35 = v3->CurByteIndex;
          v49 = (unsigned __int8)v3->pData[v35] | (((unsigned __int8)v3->pData[v35 + 1] | (*(unsigned __int16 *)&v3->pData[v35 + 2] << 8)) << 8);
          v3->CurByteIndex = v35 + 4;
          *(_DWORD *)(v11 + 4i64 * v31[1] + 24) = v49;
          if ( v3->CurBitIndex )
            ++v3->CurByteIndex;
          v3->CurBitIndex = 0;
          v36 = v3->CurByteIndex;
          v50 = (unsigned __int8)v3->pData[v36] | (((unsigned __int8)v3->pData[v36 + 1] | (*(unsigned __int16 *)&v3->pData[v36 + 2] << 8)) << 8);
          v3->CurByteIndex = v36 + 4;
          *(_DWORD *)(v11 + 4i64 * v31[2] + 24) = v50;
          if ( v3->CurBitIndex )
            ++v3->CurByteIndex;
          v3->CurBitIndex = 0;
          v37 = v3->CurByteIndex;
          v51 = (unsigned __int8)v3->pData[v37] | (((unsigned __int8)v3->pData[v37 + 1] | (*(unsigned __int16 *)&v3->pData[v37 + 2] << 8)) << 8);
          v3->CurByteIndex = v37 + 4;
          *(_DWORD *)(v11 + 4i64 * v31[3] + 24) = v51;
          if ( v3->CurBitIndex )
            ++v3->CurByteIndex;
          v3->CurBitIndex = 0;
          v38 = v3->CurByteIndex;
          v52 = (unsigned __int8)v3->pData[v38] | (((unsigned __int8)v3->pData[v38 + 1] | (*(unsigned __int16 *)&v3->pData[v38 + 2] << 8)) << 8);
          v3->CurByteIndex = v38 + 4;
          *(_DWORD *)(v11 + 4i64 * v31[4] + 24) = v52;
          if ( v3->CurBitIndex )
            ++v3->CurByteIndex;
          v3->CurBitIndex = 0;
          v39 = v3->CurByteIndex;
          v53 = (unsigned __int8)v3->pData[v39] | (((unsigned __int8)v3->pData[v39 + 1] | (*(unsigned __int16 *)&v3->pData[v39 + 2] << 8)) << 8);
          v3->CurByteIndex = v39 + 4;
          *(_DWORD *)(v11 + 4i64 * v31[5] + 24) = v53;
          if ( v3->CurBitIndex )
            ++v3->CurByteIndex;
          v3->CurBitIndex = 0;
          v40 = v3->CurByteIndex;
          v54 = (unsigned __int8)v3->pData[v40] | (((unsigned __int8)v3->pData[v40 + 1] | (*(unsigned __int16 *)&v3->pData[v40 + 2] << 8)) << 8);
          v3->CurByteIndex = v40 + 4;
          *(_DWORD *)(v11 + 4i64 * v31[6] + 24) = v54;
          if ( v3->CurBitIndex )
            ++v3->CurByteIndex;
          v3->CurBitIndex = 0;
          v41 = v3->CurByteIndex;
          v55 = (unsigned __int8)v3->pData[v41] | (((unsigned __int8)v3->pData[v41 + 1] | (*(unsigned __int16 *)&v3->pData[v41 + 2] << 8)) << 8);
          v3->CurByteIndex = v41 + 4;
          *(_DWORD *)(v11 + 4i64 * v31[7] + 24) = v55;
          if ( v3->CurBitIndex )
            ++v3->CurByteIndex;
          v3->CurBitIndex = 0;
          v42 = v3->CurByteIndex;
          v56 = (unsigned __int8)v3->pData[v42] | (((unsigned __int8)v3->pData[v42 + 1] | (*(unsigned __int16 *)&v3->pData[v42 + 2] << 8)) << 8);
          v3->CurByteIndex = v42 + 4;
          *(_DWORD *)(v11 + 4i64 * v31[8] + 24) = v56;
          v31 += 10;
          --v32;
        }
        while ( v32 );
        *(float *)(v11 + 88) = *(float *)(v11 + 88) * 0.0039215689;
        *(float *)(v11 + 92) = *(float *)(v11 + 92) * 0.0039215689;
        *(float *)(v11 + 96) = *(float *)(v11 + 96) * 0.0039215689;
        *(float *)(v11 + 100) = *(float *)(v11 + 100) * 0.0039215689;
        ++v6;
        Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v11);
        break;
      default:
        break;
    }
    if ( v2 && v11 )
    {
      Scaleform::Render::FilterSet::AddFilter(v2, (Scaleform::Render::Filter *)v11);
      ++v6;
    }
    if ( v10 )
    {
      v43 = v3->CurBitIndex;
      v44 = v3->CurByteIndex;
      do
      {
        --v10;
        if ( v43 )
          ++v44;
        v43 = 0;
        ++v44;
      }
      while ( v10 );
      v3->CurBitIndex = 0;
      v3->CurByteIndex = v44;
    }
    if ( params.Gradient.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)params.Gradient.pObject);
    if ( v11 )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v11);
  }
  return v6;
}

