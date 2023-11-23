// File Line: 126
// RVA: 0x889410
void __fastcall Scaleform::GFx::ReadBlurFilter<Scaleform::GFx::Stream>(
        Scaleform::GFx::Stream *ps,
        Scaleform::Render::BlurFilterParams *params,
        float *angle,
        float *distance,
        char readConstants,
        Scaleform::Render::FilterType type,
        unsigned int passesMask)
{
  float *v7; // r14
  float *v8; // rbp
  char v11; // r12
  int v12; // edi
  __int64 Pos; // rdx
  __int64 v14; // rbp
  Scaleform::Render::GradientData *v15; // rax
  Scaleform::GFx::Resource *v16; // rax
  Scaleform::GFx::Resource *v17; // rsi
  __int64 v18; // r13
  __int64 v19; // rbp
  __int64 v20; // r12
  Scaleform::GFx::ResourceVtbl *vfptr; // r14
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
  Scaleform::Render::RenderBuffer *pObject; // rcx
  __int64 v35; // rdx
  char v36; // cl
  __int64 v37; // rdx
  char v38; // cl
  __int64 v39; // r9
  int v40; // r8d
  __int64 v41; // r9
  int v42; // r8d
  __int64 v43; // r9
  int v44; // r8d
  __int64 v45; // r9
  int v46; // r8d
  __int64 v47; // r9
  unsigned __int16 v48; // r8
  __int64 v49; // rdx
  unsigned int v50; // ecx
  unsigned int v51; // eax
  int v52; // [rsp+90h] [rbp+8h]

  v7 = distance;
  v8 = angle;
  v11 = readConstants;
  v12 = 0;
  if ( (readConstants & 0x10) != 0 )
  {
    ps->UnusedBits = 0;
    if ( (signed int)(ps->DataSize - ps->Pos) < 1 )
      Scaleform::GFx::Stream::PopulateBuffer(ps, 1);
    Pos = ps->Pos;
    v14 = (unsigned __int8)ps->pBuffer[Pos];
    ps->Pos = Pos + 1;
    v15 = (Scaleform::Render::GradientData *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                               Scaleform::Memory::pGlobalHeap,
                                               48i64);
    if ( v15 )
    {
      Scaleform::Render::GradientData::GradientData(v15, GradientLinear, v14, 0);
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
        vfptr = v17[1].vfptr;
        ps->UnusedBits = 0;
        if ( (signed int)(ps->DataSize - ps->Pos) < 1 )
          Scaleform::GFx::Stream::PopulateBuffer(ps, 1);
        v22 = ps->Pos;
        v23 = ps->pBuffer[v22];
        ps->Pos = v22 + 1;
        BYTE2(v52) = v23;
        ps->UnusedBits = 0;
        if ( (signed int)(ps->DataSize - (v22 + 1)) < 1 )
          Scaleform::GFx::Stream::PopulateBuffer(ps, 1);
        v24 = ps->Pos;
        v25 = ps->pBuffer[v24];
        ps->Pos = v24 + 1;
        BYTE1(v52) = v25;
        ps->UnusedBits = 0;
        if ( (signed int)(ps->DataSize - (v24 + 1)) < 1 )
          Scaleform::GFx::Stream::PopulateBuffer(ps, 1);
        v26 = ps->Pos;
        v27 = ps->pBuffer[v26];
        ps->Pos = v26 + 1;
        LOBYTE(v52) = v27;
        ps->UnusedBits = 0;
        if ( (signed int)(ps->DataSize - (v26 + 1)) < 1 )
          Scaleform::GFx::Stream::PopulateBuffer(ps, 1);
        v28 = ps->Pos;
        v29 = ps->pBuffer[v28];
        ps->Pos = v28 + 1;
        HIBYTE(v52) = v29;
        *(_DWORD *)((char *)&vfptr->__vecDelDtor + v19 + 4) = v52;
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
        ps->UnusedBits = 0;
        if ( (signed int)(ps->DataSize - ps->Pos) < 1 )
          Scaleform::GFx::Stream::PopulateBuffer(ps, 1);
        v32 = ps->Pos;
        v33 = ps->pBuffer[v32];
        ps->Pos = v32 + 1;
        *((_BYTE *)&v17[1].vfptr->__vecDelDtor + v30) = v33;
        v30 += 8i64;
        --v31;
      }
      while ( v31 );
    }
    if ( v17 )
      Scaleform::Render::RenderBuffer::AddRef(v17);
    pObject = (Scaleform::Render::RenderBuffer *)params->Gradient.pObject;
    if ( pObject )
      Scaleform::RefCountImpl::Release(pObject);
    params->Gradient.pObject = (Scaleform::Render::GradientData *)v17;
    if ( v17 )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v17);
    v7 = distance;
    v8 = angle;
  }
  if ( (v11 & 1) != 0 )
  {
    Scaleform::GFx::Stream::ReadRgb(ps, params->Colors);
    ps->UnusedBits = 0;
    if ( (signed int)(ps->DataSize - ps->Pos) < 1 )
      Scaleform::GFx::Stream::PopulateBuffer(ps, 1);
    v35 = ps->Pos;
    v36 = ps->pBuffer[v35];
    ps->Pos = v35 + 1;
    params->Colors[0].Channels.Alpha = v36;
    if ( (v11 & 2) != 0 )
    {
      Scaleform::GFx::Stream::ReadRgb(ps, &params->Colors[1]);
      ps->UnusedBits = 0;
      if ( (signed int)(ps->DataSize - ps->Pos) < 1 )
        Scaleform::GFx::Stream::PopulateBuffer(ps, 1);
      v37 = ps->Pos;
      v38 = ps->pBuffer[v37];
      ps->Pos = v37 + 1;
      params->Colors[1].Channels.Alpha = v38;
    }
  }
  ps->UnusedBits = 0;
  if ( (signed int)(ps->DataSize - ps->Pos) < 4 )
    Scaleform::GFx::Stream::PopulateBuffer(ps, 4);
  v39 = ps->Pos;
  v40 = (unsigned __int8)ps->pBuffer[v39] | (((unsigned __int8)ps->pBuffer[(unsigned int)(v39 + 1)] | (((unsigned __int8)ps->pBuffer[(unsigned int)(v39 + 2)] | ((unsigned __int8)ps->pBuffer[(unsigned int)(v39 + 3)] << 8)) << 8)) << 8);
  ps->Pos = v39 + 4;
  params->BlurX = (float)((float)v40 * 0.000015258789) * 20.0;
  ps->UnusedBits = 0;
  if ( (signed int)(ps->DataSize - ps->Pos) < 4 )
    Scaleform::GFx::Stream::PopulateBuffer(ps, 4);
  v41 = ps->Pos;
  v42 = (unsigned __int8)ps->pBuffer[v41] | (((unsigned __int8)ps->pBuffer[(unsigned int)(v41 + 1)] | (((unsigned __int8)ps->pBuffer[(unsigned int)(v41 + 2)] | ((unsigned __int8)ps->pBuffer[(unsigned int)(v41 + 3)] << 8)) << 8)) << 8);
  ps->Pos = v41 + 4;
  params->BlurY = (float)((float)v42 * 0.000015258789) * 20.0;
  if ( (v11 & 4) != 0 )
  {
    ps->UnusedBits = 0;
    if ( (signed int)(ps->DataSize - ps->Pos) < 4 )
      Scaleform::GFx::Stream::PopulateBuffer(ps, 4);
    v43 = ps->Pos;
    v44 = (unsigned __int8)ps->pBuffer[v43] | (((unsigned __int8)ps->pBuffer[(unsigned int)(v43 + 1)] | (((unsigned __int8)ps->pBuffer[(unsigned int)(v43 + 2)] | ((unsigned __int8)ps->pBuffer[(unsigned int)(v43 + 3)] << 8)) << 8)) << 8);
    ps->Pos = v43 + 4;
    *v8 = (float)v44 * 0.000015258789;
    ps->UnusedBits = 0;
    if ( (signed int)(ps->DataSize - ps->Pos) < 4 )
      Scaleform::GFx::Stream::PopulateBuffer(ps, 4);
    v45 = ps->Pos;
    v46 = (unsigned __int8)ps->pBuffer[v45] | (((unsigned __int8)ps->pBuffer[(unsigned int)(v45 + 1)] | (((unsigned __int8)ps->pBuffer[(unsigned int)(v45 + 2)] | ((unsigned __int8)ps->pBuffer[(unsigned int)(v45 + 3)] << 8)) << 8)) << 8);
    ps->Pos = v45 + 4;
    *v7 = (float)v46 * 0.000015258789;
  }
  if ( (v11 & 8) != 0 )
  {
    ps->UnusedBits = 0;
    if ( (signed int)(ps->DataSize - ps->Pos) < 2 )
      Scaleform::GFx::Stream::PopulateBuffer(ps, 2);
    v47 = ps->Pos;
    v48 = (unsigned __int8)ps->pBuffer[v47] | ((unsigned __int8)ps->pBuffer[(unsigned int)(v47 + 1)] << 8);
    ps->Pos = v47 + 2;
    params->Strength = (float)v48 * 0.00390625;
  }
  ps->UnusedBits = 0;
  if ( (signed int)(ps->DataSize - ps->Pos) < 1 )
    Scaleform::GFx::Stream::PopulateBuffer(ps, 1);
  v49 = ps->Pos;
  v50 = (unsigned __int8)ps->pBuffer[v49];
  ps->Pos = v49 + 1;
  if ( passesMask == 248 )
  {
    v51 = v50 >> 3;
  }
  else
  {
    if ( (v50 & 0x80u) != 0 )
      v12 = 32;
    if ( (v50 & 0x40) != 0 )
      v12 |= 0x10u;
    if ( (v50 & 0x20) == 0 )
      v12 |= 0x40u;
    if ( passesMask <= 0xF && (v50 & 0x10) != 0 )
      v12 |= 0x80u;
    v51 = passesMask & v50;
  }
  params->Passes = v51;
  params->Mode = type | v12;
}

// File Line: 204
// RVA: 0x884510
__int64 __fastcall Scaleform::GFx::LoadFilters<Scaleform::GFx::StreamContext>(
        Scaleform::GFx::StreamContext *ps,
        Scaleform::Render::FilterSet *filters)
{
  Scaleform::Render::FilterSet *v2; // rsi
  unsigned __int64 CurByteIndex; // rdx
  char v5; // r15
  unsigned int v6; // r13d
  Scaleform::MemoryHeap *v7; // r12
  unsigned __int64 v8; // rcx
  int v9; // edx
  int v10; // r14d
  __int64 v11; // rbx
  Scaleform::Render::ShadowFilter *v12; // rax
  __int64 v13; // rax
  float y; // xmm2_4
  Scaleform::Render::GradientData *pObject; // rax
  float v16; // xmm2_4
  Scaleform::Render::GradientData *v17; // rax
  Scaleform::Render::BevelFilter *v18; // rax
  __int64 v19; // rax
  int type; // ebx
  Scaleform::Render::GradientFilter *v21; // rax
  __int64 v22; // rax
  unsigned __int64 v23; // rax
  const char *pData; // rdx
  int v25; // r8d
  int v26; // ecx
  Scaleform::Render::ColorMatrixFilter *v27; // rax
  __int64 v28; // rax
  unsigned __int8 *v29; // r9
  __int64 v30; // r10
  unsigned __int64 v31; // r8
  unsigned __int64 v32; // r8
  unsigned __int64 v33; // r8
  unsigned __int64 v34; // r8
  unsigned __int64 v35; // r8
  unsigned __int64 v36; // r8
  unsigned __int64 v37; // r8
  unsigned __int64 v38; // r8
  unsigned __int64 v39; // r8
  unsigned __int64 v40; // r8
  unsigned int CurBitIndex; // ecx
  unsigned __int64 v42; // rax
  Scaleform::Render::BlurFilterParams params; // [rsp+68h] [rbp-31h] BYREF
  int v45; // [rsp+100h] [rbp+67h]
  int v46; // [rsp+100h] [rbp+67h]
  int v47; // [rsp+100h] [rbp+67h]
  int v48; // [rsp+100h] [rbp+67h]
  int v49; // [rsp+100h] [rbp+67h]
  int v50; // [rsp+100h] [rbp+67h]
  int v51; // [rsp+100h] [rbp+67h]
  int v52; // [rsp+100h] [rbp+67h]
  int v53; // [rsp+100h] [rbp+67h]
  int v54; // [rsp+100h] [rbp+67h]
  float distance; // [rsp+110h] [rbp+77h] BYREF
  float angle; // [rsp+118h] [rbp+7Fh] BYREF

  v2 = filters;
  if ( ps->CurBitIndex )
    ++ps->CurByteIndex;
  ps->CurBitIndex = 0;
  CurByteIndex = ps->CurByteIndex;
  v5 = ps->pData[CurByteIndex];
  ps->CurByteIndex = CurByteIndex + 1;
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
    if ( ps->CurBitIndex )
      ++ps->CurByteIndex;
    ps->CurBitIndex = 0;
    v8 = ps->CurByteIndex;
    v9 = (unsigned __int8)ps->pData[v8];
    ps->CurByteIndex = v8 + 1;
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
          ps,
          &params,
          &angle,
          &distance,
          0xDu,
          Filter_Shadow,
          0x1Fu);
        v12 = (Scaleform::Render::ShadowFilter *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))v7->vfptr->Alloc)(
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
        Scaleform::GFx::ReadBlurFilter<Scaleform::GFx::StreamContext>(ps, &params, 0i64, 0i64, 0, Filter_Blur, 0xF8u);
        v11 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))v7->vfptr->Alloc)(v7, 80i64);
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
          *(_DWORD *)(v11 + 24) = params.Mode;
          *(_DWORD *)(v11 + 28) = params.Passes;
          *(float *)(v11 + 32) = params.BlurX;
          *(float *)(v11 + 36) = params.BlurY;
          y = params.Offset.y;
          *(float *)(v11 + 40) = params.Offset.x;
          *(float *)(v11 + 44) = y;
          *(float *)(v11 + 48) = params.Strength;
          *(_DWORD *)(v11 + 52) = params.Colors[0].Raw;
          *(_DWORD *)(v11 + 56) = params.Colors[1].Raw;
          pObject = params.Gradient.pObject;
          if ( params.Gradient.pObject )
          {
            Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)params.Gradient.pObject);
            pObject = params.Gradient.pObject;
          }
          *(_QWORD *)(v11 + 64) = pObject;
          *(_QWORD *)(v11 + 72) = 0i64;
          *(_QWORD *)v11 = &Scaleform::Render::BlurFilter::`vftable;
          v2 = filters;
        }
        else
        {
          v11 = 0i64;
        }
        break;
      case 2:
        Scaleform::GFx::ReadBlurFilter<Scaleform::GFx::StreamContext>(ps, &params, 0i64, 0i64, 9u, Filter_Glow, 0x1Fu);
        v11 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))v7->vfptr->Alloc)(v7, 80i64);
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
          *(_DWORD *)(v11 + 24) = params.Mode;
          *(_DWORD *)(v11 + 28) = params.Passes;
          *(float *)(v11 + 32) = params.BlurX;
          *(float *)(v11 + 36) = params.BlurY;
          v16 = params.Offset.y;
          *(float *)(v11 + 40) = params.Offset.x;
          *(float *)(v11 + 44) = v16;
          *(float *)(v11 + 48) = params.Strength;
          *(_DWORD *)(v11 + 52) = params.Colors[0].Raw;
          *(_DWORD *)(v11 + 56) = params.Colors[1].Raw;
          v17 = params.Gradient.pObject;
          if ( params.Gradient.pObject )
          {
            Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)params.Gradient.pObject);
            v17 = params.Gradient.pObject;
          }
          *(_QWORD *)(v11 + 64) = v17;
          *(_QWORD *)(v11 + 72) = 0i64;
          *(_QWORD *)v11 = &Scaleform::Render::GlowFilter::`vftable;
          v2 = filters;
        }
        else
        {
          v11 = 0i64;
        }
        break;
      case 3:
        Scaleform::GFx::ReadBlurFilter<Scaleform::GFx::StreamContext>(
          ps,
          &params,
          &angle,
          &distance,
          0xFu,
          Filter_Bevel,
          0xFu);
        v18 = (Scaleform::Render::BevelFilter *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))v7->vfptr->Alloc)(
                                                  v7,
                                                  80i64);
        if ( v18 )
        {
          Scaleform::Render::BevelFilter::BevelFilter(v18, &params, angle, distance);
          v11 = v19;
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
          ps,
          &params,
          &angle,
          &distance,
          0x1Cu,
          (Scaleform::Render::FilterType)type,
          0xFu);
        v21 = (Scaleform::Render::GradientFilter *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))v7->vfptr->Alloc)(
                                                     v7,
                                                     88i64);
        if ( v21 )
        {
          Scaleform::Render::GradientFilter::GradientFilter(
            v21,
            (Scaleform::Render::FilterType)type,
            &params,
            angle,
            distance);
          v11 = v22;
        }
        else
        {
          v11 = 0i64;
        }
        break;
      case 5:
        if ( ps->CurBitIndex )
          ++ps->CurByteIndex;
        ps->CurBitIndex = 0;
        v23 = ps->CurByteIndex;
        pData = ps->pData;
        v25 = (unsigned __int8)ps->pData[v23++];
        ps->CurByteIndex = v23;
        ps->CurBitIndex = 0;
        v26 = (unsigned __int8)pData[v23];
        ps->CurByteIndex = v23 + 1;
        v10 = 4 * v25 * v26 + 13;
        break;
      case 6:
        v27 = (Scaleform::Render::ColorMatrixFilter *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))v7->vfptr->Alloc)(
                                                        v7,
                                                        104i64);
        if ( v27 )
        {
          Scaleform::Render::ColorMatrixFilter::ColorMatrixFilter(v27);
          v11 = v28;
        }
        else
        {
          v11 = 0i64;
        }
        if ( v11 )
          Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)v11);
        v29 = (unsigned __int8 *)&`Scaleform::GFx::LoadFilters<Scaleform::GFx::StreamContext>::`10::Index[1];
        v30 = 2i64;
        do
        {
          if ( ps->CurBitIndex )
            ++ps->CurByteIndex;
          ps->CurBitIndex = 0;
          v31 = ps->CurByteIndex;
          v45 = (unsigned __int8)ps->pData[v31] | (((unsigned __int8)ps->pData[v31 + 1] | (*(unsigned __int16 *)&ps->pData[v31 + 2] << 8)) << 8);
          ps->CurByteIndex = v31 + 4;
          *(_DWORD *)(v11 + 4i64 * *(v29 - 1) + 24) = v45;
          if ( ps->CurBitIndex )
            ++ps->CurByteIndex;
          ps->CurBitIndex = 0;
          v32 = ps->CurByteIndex;
          v46 = (unsigned __int8)ps->pData[v32] | (((unsigned __int8)ps->pData[v32 + 1] | (*(unsigned __int16 *)&ps->pData[v32 + 2] << 8)) << 8);
          ps->CurByteIndex = v32 + 4;
          *(_DWORD *)(v11 + 4i64 * *v29 + 24) = v46;
          if ( ps->CurBitIndex )
            ++ps->CurByteIndex;
          ps->CurBitIndex = 0;
          v33 = ps->CurByteIndex;
          v47 = (unsigned __int8)ps->pData[v33] | (((unsigned __int8)ps->pData[v33 + 1] | (*(unsigned __int16 *)&ps->pData[v33 + 2] << 8)) << 8);
          ps->CurByteIndex = v33 + 4;
          *(_DWORD *)(v11 + 4i64 * v29[1] + 24) = v47;
          if ( ps->CurBitIndex )
            ++ps->CurByteIndex;
          ps->CurBitIndex = 0;
          v34 = ps->CurByteIndex;
          v48 = (unsigned __int8)ps->pData[v34] | (((unsigned __int8)ps->pData[v34 + 1] | (*(unsigned __int16 *)&ps->pData[v34 + 2] << 8)) << 8);
          ps->CurByteIndex = v34 + 4;
          *(_DWORD *)(v11 + 4i64 * v29[2] + 24) = v48;
          if ( ps->CurBitIndex )
            ++ps->CurByteIndex;
          ps->CurBitIndex = 0;
          v35 = ps->CurByteIndex;
          v49 = (unsigned __int8)ps->pData[v35] | (((unsigned __int8)ps->pData[v35 + 1] | (*(unsigned __int16 *)&ps->pData[v35 + 2] << 8)) << 8);
          ps->CurByteIndex = v35 + 4;
          *(_DWORD *)(v11 + 4i64 * v29[3] + 24) = v49;
          if ( ps->CurBitIndex )
            ++ps->CurByteIndex;
          ps->CurBitIndex = 0;
          v36 = ps->CurByteIndex;
          v50 = (unsigned __int8)ps->pData[v36] | (((unsigned __int8)ps->pData[v36 + 1] | (*(unsigned __int16 *)&ps->pData[v36 + 2] << 8)) << 8);
          ps->CurByteIndex = v36 + 4;
          *(_DWORD *)(v11 + 4i64 * v29[4] + 24) = v50;
          if ( ps->CurBitIndex )
            ++ps->CurByteIndex;
          ps->CurBitIndex = 0;
          v37 = ps->CurByteIndex;
          v51 = (unsigned __int8)ps->pData[v37] | (((unsigned __int8)ps->pData[v37 + 1] | (*(unsigned __int16 *)&ps->pData[v37 + 2] << 8)) << 8);
          ps->CurByteIndex = v37 + 4;
          *(_DWORD *)(v11 + 4i64 * v29[5] + 24) = v51;
          if ( ps->CurBitIndex )
            ++ps->CurByteIndex;
          ps->CurBitIndex = 0;
          v38 = ps->CurByteIndex;
          v52 = (unsigned __int8)ps->pData[v38] | (((unsigned __int8)ps->pData[v38 + 1] | (*(unsigned __int16 *)&ps->pData[v38 + 2] << 8)) << 8);
          ps->CurByteIndex = v38 + 4;
          *(_DWORD *)(v11 + 4i64 * v29[6] + 24) = v52;
          if ( ps->CurBitIndex )
            ++ps->CurByteIndex;
          ps->CurBitIndex = 0;
          v39 = ps->CurByteIndex;
          v53 = (unsigned __int8)ps->pData[v39] | (((unsigned __int8)ps->pData[v39 + 1] | (*(unsigned __int16 *)&ps->pData[v39 + 2] << 8)) << 8);
          ps->CurByteIndex = v39 + 4;
          *(_DWORD *)(v11 + 4i64 * v29[7] + 24) = v53;
          if ( ps->CurBitIndex )
            ++ps->CurByteIndex;
          ps->CurBitIndex = 0;
          v40 = ps->CurByteIndex;
          v54 = (unsigned __int8)ps->pData[v40] | (((unsigned __int8)ps->pData[v40 + 1] | (*(unsigned __int16 *)&ps->pData[v40 + 2] << 8)) << 8);
          ps->CurByteIndex = v40 + 4;
          *(_DWORD *)(v11 + 4i64 * v29[8] + 24) = v54;
          v29 += 10;
          --v30;
        }
        while ( v30 );
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
      CurBitIndex = ps->CurBitIndex;
      v42 = ps->CurByteIndex;
      do
      {
        --v10;
        if ( CurBitIndex )
          ++v42;
        CurBitIndex = 0;
        ++v42;
      }
      while ( v10 );
      ps->CurBitIndex = 0;
      ps->CurByteIndex = v42;
    }
    if ( params.Gradient.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)params.Gradient.pObject);
    if ( v11 )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v11);
  }
  return v6;
}

