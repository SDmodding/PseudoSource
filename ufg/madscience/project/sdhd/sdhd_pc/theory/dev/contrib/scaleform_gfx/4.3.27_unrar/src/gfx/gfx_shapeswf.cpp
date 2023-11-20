// File Line: 67
// RVA: 0x8F6730
void __fastcall Scaleform::GFx::FillStyleSwfReader::Read(Scaleform::GFx::FillStyleSwfReader *this, Scaleform::GFx::LoadProcess *p, Scaleform::GFx::TagType tagType)
{
  Scaleform::GFx::TagType v3; // er13
  Scaleform::GFx::LoadProcess *v4; // rdi
  Scaleform::GFx::FillStyleSwfReader *v5; // r14
  Scaleform::GFx::Stream *v6; // rbx
  __int64 v7; // rcx
  int v8; // er12
  Scaleform::GFx::Stream *v9; // rcx
  Scaleform::GFx::Stream *v10; // rbx
  __int64 v11; // r8
  char v12; // dl
  Scaleform::Render::Color *v13; // rbx
  Scaleform::Render::RenderBuffer *v14; // rcx
  Scaleform::GFx::Stream *v15; // rcx
  float v16; // xmm8_4
  float v17; // xmm12_4
  float v18; // xmm10_4
  float v19; // xmm13_4
  float v20; // xmm11_4
  float v21; // xmm9_4
  float v22; // xmm8_4
  Scaleform::GFx::Stream *v23; // rbx
  __int64 v24; // rdx
  char v25; // cl
  char v26; // r13
  Scaleform::Render::ComplexFill *v27; // rax
  Scaleform::Render::ComplexFill *v28; // rax
  Scaleform::Render::ComplexFill *v29; // r15
  Scaleform::Render::FillStyleType *v30; // rbx
  Scaleform::Render::RenderBuffer *v31; // rcx
  Scaleform::Render::GradientType v32; // ebx
  Scaleform::Render::GradientData *v33; // rax
  Scaleform::Render::GradientData *v34; // rax
  Scaleform::Render::GradientData *v35; // rsi
  Scaleform::Render::ComplexFill *v36; // rbx
  Scaleform::Render::RenderBuffer *v37; // rcx
  __int64 v38; // rsi
  signed int v39; // er13
  Scaleform::GFx::Stream *v40; // rbx
  __int64 v41; // rcx
  char v42; // r15
  Scaleform::GFx::Stream *v43; // rcx
  Scaleform::GFx::Stream *v44; // rbx
  __int64 v45; // rdx
  char v46; // cl
  Scaleform::GFx::Stream *v47; // rbx
  __int64 v48; // r9
  __int16 v49; // r8
  Scaleform::Render::ComplexFill *v50; // rcx
  unsigned int v51; // ebx
  Scaleform::GFx::Stream *v52; // rcx
  Scaleform::Render::ComplexFill *v53; // rax
  Scaleform::Render::ComplexFill *v54; // rax
  Scaleform::Render::ComplexFill *v55; // r13
  Scaleform::Render::FillStyleType *v56; // r15
  Scaleform::Render::RenderBuffer *v57; // rcx
  Scaleform::Render::ComplexFill *v58; // rcx
  char v59; // al
  Scaleform::GFx::Resource *v60; // rsi
  Scaleform::GFx::ResourceHandle::HandleType v61; // er15
  Scaleform::GFx::ResourceVtbl *v62; // rbx
  Scaleform::Render::ComplexFill *v63; // rdi
  Scaleform::Render::Image *v64; // rcx
  Scaleform::HashSet<unsigned int,Scaleform::FixedSizeHash<unsigned int>,Scaleform::FixedSizeHash<unsigned int>,Scaleform::AllocatorLH<unsigned int,2>,Scaleform::HashsetCachedEntry<unsigned int,Scaleform::FixedSizeHash<unsigned int> > > *v65; // rcx
  Scaleform::Render::FillStyleType *v66; // rdi
  Scaleform::Render::RenderBuffer *v67; // rcx
  Scaleform::GFx::Resource *v68; // rbx
  Scaleform::GFx::ResourceLibBase *v69; // rcx
  Scaleform::GFx::ResourceId rid; // [rsp+20h] [rbp-A8h]
  Scaleform::LogMessageId id[2]; // [rsp+28h] [rbp-A0h]
  Scaleform::GFx::ResourceHandle phandle; // [rsp+30h] [rbp-98h]
  Scaleform::Render::Matrix2x4<float> v73; // [rsp+40h] [rbp-88h]
  __int128 v74; // [rsp+60h] [rbp-68h]
  Scaleform::Render::Matrix2x4<float> m; // [rsp+70h] [rbp-58h]
  Scaleform::Render::Color pc[2]; // [rsp+150h] [rbp+88h]
  int v77; // [rsp+158h] [rbp+90h]
  Scaleform::Render::Color v78; // [rsp+160h] [rbp+98h]

  *((_QWORD *)&v74 + 1) = -2i64;
  v3 = tagType;
  v4 = p;
  v5 = this;
  v6 = p->pAltStream;
  if ( !v6 )
    v6 = &p->ProcessInfo.Stream;
  v6->UnusedBits = 0;
  if ( (signed int)(v6->DataSize - v6->Pos) < 1 )
    Scaleform::GFx::Stream::PopulateBuffer(v6, 1);
  v7 = v6->Pos;
  pc[0].Channels.Blue = v6->pBuffer[v7];
  v8 = (unsigned __int8)pc[0].Channels.Blue;
  v6->Pos = v7 + 1;
  Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
    (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&v4->vfptr,
    "  FillStyle read type = 0x%X\n");
  if ( !(_BYTE)v8 )
  {
    if ( (signed int)v3 > 22 )
    {
      v10 = v4->pAltStream;
      if ( !v10 )
        v10 = &v4->ProcessInfo.Stream;
      Scaleform::GFx::Stream::ReadRgb(v10, pc);
      v10->UnusedBits = 0;
      if ( (signed int)(v10->DataSize - v10->Pos) < 1 )
        Scaleform::GFx::Stream::PopulateBuffer(v10, 1);
      v11 = v10->Pos;
      v12 = v10->pBuffer[v11];
      v10->Pos = v11 + 1;
      pc[0].Channels.Alpha = v12;
    }
    else
    {
      v9 = v4->pAltStream;
      if ( !v9 )
        v9 = &v4->ProcessInfo.Stream;
      Scaleform::GFx::Stream::ReadRgb(v9, pc);
    }
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
      (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&v4->vfptr,
      "  color: ");
    v5->FillStyle->Color = (unsigned int)pc[0];
    v13 = (Scaleform::Render::Color *)v5->FillStyle;
    v14 = (Scaleform::Render::RenderBuffer *)v5->FillStyle->pFill.pObject;
    if ( v14 )
      Scaleform::RefCountImpl::Release(v14);
    *(_QWORD *)&v13[2].Channels.Blue = 0i64;
    return;
  }
  if ( v8 & 0x10 )
  {
    *(_OWORD *)&v73.M[0][2] = _xmm;
    *(__m128 *)&v73.M[1][2] = _xmm;
    v15 = v4->pAltStream;
    if ( !v15 )
      v15 = &v4->ProcessInfo.Stream;
    Scaleform::GFx::Stream::ReadMatrix(v15, (Scaleform::Render::Matrix2x4<float> *)((char *)&v73 + 8));
    if ( (_BYTE)v8 == 16 )
      v16 = 0.0;
    else
      v16 = FLOAT_0_5;
    v74 = _xmm;
    *(__m128 *)&m.M[0][0] = _xmm;
    Scaleform::Render::Matrix2x4<float>::SetInverse(
      (Scaleform::Render::Matrix2x4<float> *)&v74,
      (Scaleform::Render::Matrix2x4<float> *)((char *)&v73 + 8));
    v17 = (float)(m.M[0][0] * 0.0) + (float)(*(float *)&v74 * 0.000030517578);
    v18 = (float)(m.M[0][0] * 0.000030517578) + (float)(*(float *)&v74 * 0.0);
    v19 = (float)(m.M[0][1] * 0.0) + (float)(*((float *)&v74 + 1) * 0.000030517578);
    v20 = (float)(m.M[0][1] * 0.000030517578) + (float)(*((float *)&v74 + 1) * 0.0);
    v21 = (float)((float)(m.M[0][3] * 0.0) + (float)(*((float *)&v74 + 3) * 0.000030517578)) + 0.5;
    v22 = v16 + (float)((float)(m.M[0][3] * 0.000030517578) + (float)(*((float *)&v74 + 3) * 0.0));
    v23 = v4->pAltStream;
    if ( !v23 )
      v23 = &v4->ProcessInfo.Stream;
    v23->UnusedBits = 0;
    if ( (signed int)(v23->DataSize - v23->Pos) < 1 )
      Scaleform::GFx::Stream::PopulateBuffer(v23, 1);
    v24 = v23->Pos;
    v25 = v23->pBuffer[v24];
    v23->Pos = v24 + 1;
    v26 = 0;
    if ( v25 & 0x10 )
      v26 = 1;
    *(_WORD *)&v78.Channels.Blue = v25 & 0xF;
    rid.Id = v25 & 0xF;
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
      (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&v4->vfptr,
      "  gradients: numGradients = %d\n");
    v27 = (Scaleform::Render::ComplexFill *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                              Scaleform::Memory::pGlobalHeap,
                                              80i64);
    *(_QWORD *)&id[0].Id = v27;
    if ( v27 )
    {
      Scaleform::Render::ComplexFill::ComplexFill(v27);
      v29 = v28;
    }
    else
    {
      v29 = 0i64;
    }
    v30 = v5->FillStyle;
    v31 = (Scaleform::Render::RenderBuffer *)v5->FillStyle->pFill.pObject;
    if ( v31 )
      Scaleform::RefCountImpl::Release(v31);
    v30->pFill.pObject = v29;
    if ( v8 != 16 )
    {
      if ( v8 == 18 )
      {
        v32 = 1;
        goto LABEL_41;
      }
      if ( v8 == 19 )
      {
        v32 = 2;
LABEL_41:
        v33 = (Scaleform::Render::GradientData *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                                   Scaleform::Memory::pGlobalHeap,
                                                   48i64);
        *(_QWORD *)&id[0].Id = v33;
        if ( v33 )
        {
          Scaleform::Render::GradientData::GradientData(v33, v32, v78.Raw, v26 & 1);
          v35 = v34;
        }
        else
        {
          v35 = 0i64;
        }
        v36 = v5->FillStyle->pFill.pObject;
        v37 = (Scaleform::Render::RenderBuffer *)v36->pGradient.pObject;
        if ( v37 )
          Scaleform::RefCountImpl::Release(v37);
        v36->pGradient.pObject = v35;
        v38 = 0i64;
        if ( (signed int)rid.Id > 0 )
        {
          v39 = v77;
          do
          {
            v40 = v4->pAltStream;
            if ( !v40 )
              v40 = &v4->ProcessInfo.Stream;
            v40->UnusedBits = 0;
            if ( (signed int)(v40->DataSize - v40->Pos) < 1 )
              Scaleform::GFx::Stream::PopulateBuffer(v40, 1);
            v41 = v40->Pos;
            v42 = v40->pBuffer[v41];
            v40->Pos = v41 + 1;
            if ( v39 > 22 )
            {
              v44 = v4->pAltStream;
              if ( !v44 )
                v44 = &v4->ProcessInfo.Stream;
              Scaleform::GFx::Stream::ReadRgb(v44, &v78);
              v44->UnusedBits = 0;
              if ( (signed int)(v44->DataSize - v44->Pos) < 1 )
                Scaleform::GFx::Stream::PopulateBuffer(v44, 1);
              v45 = v44->Pos;
              v46 = v44->pBuffer[v45];
              v44->Pos = v45 + 1;
              v78.Channels.Alpha = v46;
            }
            else
            {
              v43 = v4->pAltStream;
              if ( !v43 )
                v43 = &v4->ProcessInfo.Stream;
              Scaleform::GFx::Stream::ReadRgb(v43, &v78);
            }
            v5->FillStyle->pFill.pObject->pGradient.pObject->pRecords[v38].ColorV = v78;
            v5->FillStyle->pFill.pObject->pGradient.pObject->pRecords[v38].Ratio = v42;
            v38 = (unsigned int)(v38 + 1);
          }
          while ( (signed int)v38 < (signed int)rid.Id );
          LOBYTE(v8) = pc[0].Channels.Blue;
        }
        if ( (_BYTE)v8 == 19 )
        {
          v47 = v4->pAltStream;
          if ( !v47 )
            v47 = &v4->ProcessInfo.Stream;
          v47->UnusedBits = 0;
          if ( (signed int)(v47->DataSize - v47->Pos) < 2 )
            Scaleform::GFx::Stream::PopulateBuffer(v47, 2);
          v48 = v47->Pos;
          v49 = (unsigned __int8)v47->pBuffer[v48] | (unsigned __int16)((unsigned __int8)v47->pBuffer[(unsigned int)(v48 + 1)] << 8);
          v47->Pos = v48 + 2;
          v5->FillStyle->pFill.pObject->pGradient.pObject->FocalRatio = (float)v49 * 0.00390625;
        }
        v50 = v5->FillStyle->pFill.pObject;
        v50->ImageMatrix.M[0][0] = v17;
        v50->ImageMatrix.M[0][1] = v19;
        v50->ImageMatrix.M[0][2] = 0.0;
        v50->ImageMatrix.M[0][3] = v21;
        v50->ImageMatrix.M[1][0] = v18;
        v50->ImageMatrix.M[1][1] = v20;
        v50->ImageMatrix.M[1][2] = 0.0;
        v50->ImageMatrix.M[1][3] = v22;
        return;
      }
    }
    v32 = 0;
    goto LABEL_41;
  }
  if ( v8 & 0x40 )
  {
    v51 = Scaleform::GFx::LoadProcess::ReadU16(v4);
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
      (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&v4->vfptr,
      "  BitmapChar = %d\n");
    *(_OWORD *)&m.M[0][2] = _xmm;
    *(__m128 *)&m.M[1][2] = _xmm;
    v52 = v4->pAltStream;
    if ( !v52 )
      v52 = &v4->ProcessInfo.Stream;
    Scaleform::GFx::Stream::ReadMatrix(v52, (Scaleform::Render::Matrix2x4<float> *)((char *)&m + 8));
    phandle.HType = 0;
    phandle.pResource = 0i64;
    *(_OWORD *)&v73.M[0][0] = _xmm;
    *(__m128 *)&v73.M[1][0] = _xmm;
    Scaleform::Render::Matrix2x4<float>::SetInverse(&v73, (Scaleform::Render::Matrix2x4<float> *)((char *)&m + 8));
    v53 = (Scaleform::Render::ComplexFill *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(
                                              Scaleform::Memory::pGlobalHeap,
                                              80ui64,
                                              0i64);
    *(_QWORD *)&pc[0].Channels.Blue = v53;
    if ( v53 )
    {
      Scaleform::Render::ComplexFill::ComplexFill(v53);
      v55 = v54;
    }
    else
    {
      v55 = 0i64;
    }
    v56 = v5->FillStyle;
    v57 = (Scaleform::Render::RenderBuffer *)v5->FillStyle->pFill.pObject;
    if ( v57 )
      Scaleform::RefCountImpl::Release(v57);
    v56->pFill.pObject = v55;
    v58 = v5->FillStyle->pFill.pObject;
    *(_OWORD *)&v58->ImageMatrix.M[0][0] = *(_OWORD *)&v73.M[0][0];
    *(_OWORD *)&v58->ImageMatrix.M[1][0] = *(_OWORD *)&v73.M[1][0];
    switch ( v8 )
    {
      case 64:
        v58->FillMode.Fill = 2;
        break;
      case 65:
        v58->FillMode.Fill = 3;
        break;
      case 66:
        v58->FillMode.Fill = 0;
        break;
      case 67:
        v58->FillMode.Fill = 1;
        break;
    }
    rid.Id = v51;
    v59 = Scaleform::GFx::MovieDataDef::LoadTaskData::GetResourceHandle(v4->pLoadData.pObject, &phandle, (__int64)&rid);
    v60 = phandle.pResource;
    v61 = phandle.HType;
    if ( v59 && phandle.HType == RH_Pointer && phandle.pResource )
    {
      if ( (phandle.pResource->vfptr->GetResourceTypeCode(phandle.pResource) & 0xFF00) == 256 )
      {
        v62 = v60[1].vfptr;
        v63 = v5->FillStyle->pFill.pObject;
        if ( v62 )
          (*((void (__fastcall **)(Scaleform::GFx::ResourceVtbl *))v62->__vecDelDtor + 1))(v60[1].vfptr);
        v64 = v63->pImage.pObject;
        if ( v64 )
          ((void (*)(void))v64->vfptr[2].__vecDelDtor)();
        v63->pImage.pObject = (Scaleform::Render::Image *)v62;
      }
    }
    else
    {
      v5->FillStyle->Color = -5776071;
      if ( v61 == 1 )
      {
        v5->FillStyle->pFill.pObject->BindIndex = phandle.BindIndex;
        v65 = (Scaleform::HashSet<unsigned int,Scaleform::FixedSizeHash<unsigned int>,Scaleform::FixedSizeHash<unsigned int>,Scaleform::AllocatorLH<unsigned int,2>,Scaleform::HashsetCachedEntry<unsigned int,Scaleform::FixedSizeHash<unsigned int> > > *)&v4->pTempBindData->FillStyleImageWrap.pTable;
        if ( v65 && !(((_BYTE)v8 - 64) & 0xFD) )
          Scaleform::HashSet<unsigned int,Scaleform::FixedSizeHash<unsigned int>,Scaleform::FixedSizeHash<unsigned int>,Scaleform::AllocatorLH<unsigned int,2>,Scaleform::HashsetCachedEntry<unsigned int,Scaleform::FixedSizeHash<unsigned int>>>::Add<unsigned int>(
            v65,
            &v5->FillStyle->pFill.pObject->BindIndex);
      }
      else
      {
        v66 = v5->FillStyle;
        v67 = (Scaleform::Render::RenderBuffer *)v5->FillStyle->pFill.pObject;
        if ( v67 )
          Scaleform::RefCountImpl::Release(v67);
        v66->pFill.pObject = 0i64;
        if ( v51 != 0xFFFF )
        {
          id[0].Id = 135168;
          Scaleform::LogDebugMessage(
            (Scaleform::LogMessageId)id,
            "An image with resource id %d is not found in resource table.",
            v51);
        }
      }
    }
    if ( v61 == RH_Pointer && v60 && !_InterlockedDecrement(&v60->RefCount.Value) )
    {
      v68 = phandle.pResource;
      v69 = phandle.pResource->pLib;
      if ( v69 )
      {
        v69->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v69->vfptr, (unsigned int)phandle.pResource);
        v68->pLib = 0i64;
      }
      v68->vfptr->__vecDelDtor(v68, 1u);
    }
  }
}

// File Line: 302
// RVA: 0x8BDD50
__int64 __fastcall Scaleform::GFx::StrokeStyleSwfReader::ConvertSwfLineStyles(unsigned int swfLineStyle)
{
  unsigned int v1; // edx

  v1 = 0;
  if ( swfLineStyle & 1 )
    v1 = 1;
  if ( swfLineStyle & 2 )
    v1 |= 2u;
  if ( swfLineStyle & 4 )
    v1 |= 4u;
  if ( (swfLineStyle & 6) == 6 )
    v1 = 6;
  if ( swfLineStyle & 0x10 )
    v1 |= 0x10u;
  if ( swfLineStyle & 0x20 )
    v1 |= 0x20u;
  if ( swfLineStyle & 0x40 )
    v1 |= 0x40u;
  if ( (swfLineStyle & 0x80u) != 0 )
    v1 |= 0x80u;
  if ( _bittest((const signed int *)&swfLineStyle, 8u) )
    v1 |= 0x100u;
  if ( _bittest((const signed int *)&swfLineStyle, 9u) )
    v1 |= 0x200u;
  if ( swfLineStyle & 8 )
    v1 |= 8u;
  return v1;
}

// File Line: 333
// RVA: 0x8F9DA0
void __fastcall Scaleform::GFx::StrokeStyleSwfReader::Read(Scaleform::GFx::StrokeStyleSwfReader *this, Scaleform::GFx::LoadProcess *p, Scaleform::GFx::TagType tagType)
{
  Scaleform::GFx::TagType v3; // er14
  Scaleform::GFx::LoadProcess *v4; // rdi
  Scaleform::GFx::StrokeStyleSwfReader *v5; // rsi
  Scaleform::GFx::Stream *v6; // rbx
  __int64 v7; // r9
  unsigned __int16 v8; // r8
  signed int v9; // er15
  float v10; // xmm6_4
  unsigned __int16 v11; // bp
  Scaleform::GFx::Stream *v12; // rbx
  __int64 v13; // r8
  unsigned int v14; // ebp
  Scaleform::Render::StrokeStyleType *v15; // rbx
  Scaleform::GFx::Resource *v16; // rax
  Scaleform::Render::RenderBuffer *v17; // rcx
  Scaleform::GFx::ResourceVtbl *v18; // rax
  Scaleform::GFx::Stream *v19; // rcx
  Scaleform::GFx::Stream *v20; // rbx
  __int64 v21; // rdx
  char v22; // cl
  Scaleform::Render::StrokeStyleType *v23; // rbx
  Scaleform::Render::RenderBuffer *v24; // rcx
  unsigned int v25; // [rsp+28h] [rbp-50h]
  Scaleform::GFx::Resource *v26; // [rsp+30h] [rbp-48h]
  Scaleform::GFx::FillStyleSwfReader v27; // [rsp+80h] [rbp+8h]
  Scaleform::Render::Color pc; // [rsp+90h] [rbp+18h]

  v3 = tagType;
  v4 = p;
  v5 = this;
  v6 = p->pAltStream;
  if ( !v6 )
    v6 = &p->ProcessInfo.Stream;
  v6->UnusedBits = 0;
  if ( (signed int)(v6->DataSize - v6->Pos) < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(v6, 2);
  v7 = v6->Pos;
  v8 = (unsigned __int8)v6->pBuffer[v7] | (unsigned __int16)((unsigned __int8)v6->pBuffer[(unsigned int)(v7 + 1)] << 8);
  v6->Pos = v7 + 2;
  v9 = v8;
  v10 = FLOAT_3_0;
  v11 = 0;
  if ( v3 == 83 )
  {
    v12 = v4->pAltStream;
    if ( !v12 )
      v12 = &v4->ProcessInfo.Stream;
    v12->UnusedBits = 0;
    if ( (signed int)(v12->DataSize - v12->Pos) < 2 )
      Scaleform::GFx::Stream::PopulateBuffer(v12, 2);
    v13 = v12->Pos;
    v11 = (unsigned __int8)v12->pBuffer[v13] | (unsigned __int16)((unsigned __int8)v12->pBuffer[(unsigned int)(v13 + 1)] << 8);
    v12->Pos = v13 + 2;
    if ( v11 & 0x20 )
      v10 = (float)Scaleform::GFx::LoadProcess::ReadU16(v4) * 0.00390625;
  }
  v14 = Scaleform::GFx::StrokeStyleSwfReader::ConvertSwfLineStyles(v11);
  if ( v14 & 8 )
  {
    v26 = 0i64;
    v27.FillStyle = (Scaleform::Render::FillStyleType *)&v25;
    Scaleform::GFx::FillStyleSwfReader::Read(&v27, v4, v3);
    v5->StrokeStyle->Color = v25;
    v5->StrokeStyle->Miter = v10;
    v5->StrokeStyle->Width = (float)v9;
    v15 = v5->StrokeStyle;
    v16 = v26;
    if ( v26 )
    {
      Scaleform::Render::RenderBuffer::AddRef(v26);
      v16 = v26;
    }
    v17 = (Scaleform::Render::RenderBuffer *)v15->pFill.pObject;
    if ( v17 )
    {
      Scaleform::RefCountImpl::Release(v17);
      v16 = v26;
    }
    v15->pFill.pObject = (Scaleform::Render::ComplexFill *)v16;
    if ( v26 )
    {
      v18 = v26[1].vfptr;
      if ( v18 && WORD1(v18->GetResourceTypeCode) )
        v5->StrokeStyle->Color = *((_DWORD *)v18->GetResourceReport + 1);
    }
    else
    {
      v5->StrokeStyle->Color = v25;
    }
    if ( v26 )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v26);
  }
  else
  {
    if ( (signed int)v3 > 22 )
    {
      v20 = v4->pAltStream;
      if ( !v20 )
        v20 = &v4->ProcessInfo.Stream;
      Scaleform::GFx::Stream::ReadRgb(v20, &pc);
      v20->UnusedBits = 0;
      if ( (signed int)(v20->DataSize - v20->Pos) < 1 )
        Scaleform::GFx::Stream::PopulateBuffer(v20, 1);
      v21 = v20->Pos;
      v22 = v20->pBuffer[v21];
      v20->Pos = v21 + 1;
      pc.Channels.Alpha = v22;
    }
    else
    {
      v19 = v4->pAltStream;
      if ( !v19 )
        v19 = &v4->ProcessInfo.Stream;
      Scaleform::GFx::Stream::ReadRgb(v19, &pc);
    }
    v5->StrokeStyle->Color = pc.Raw;
    v5->StrokeStyle->Miter = v10;
    v23 = v5->StrokeStyle;
    v24 = (Scaleform::Render::RenderBuffer *)v5->StrokeStyle->pFill.pObject;
    if ( v24 )
      Scaleform::RefCountImpl::Release(v24);
    v23->pFill.pObject = 0i64;
    v5->StrokeStyle->Width = (float)v9;
  }
  v5->StrokeStyle->Units = 0.050000001;
  v5->StrokeStyle->Flags = v14;
}

// File Line: 433
// RVA: 0x89DD90
void __fastcall Scaleform::GFx::SwfShapeDecoder::SwfShapeDecoder(Scaleform::GFx::SwfShapeDecoder *this, Scaleform::Render::ShapePosInfo *pos, const char *shapeData, float sfactor)
{
  Scaleform::GFx::SwfShapeDecoder *v4; // r9
  unsigned int v5; // edx
  unsigned int v6; // edx
  unsigned int v7; // edx
  unsigned int v8; // edx
  unsigned int v9; // edx
  unsigned __int64 v10; // rcx
  char v11; // dl
  unsigned __int64 v12; // rcx
  char v13; // dl
  unsigned int v14; // eax
  unsigned __int64 v15; // rcx
  char v16; // dl
  unsigned int v17; // eax
  unsigned __int64 v18; // rcx
  char v19; // dl
  unsigned int v20; // eax
  unsigned int v21; // edx
  unsigned int v22; // edx
  unsigned int v23; // edx
  unsigned int v24; // edx
  unsigned __int64 v25; // rcx
  char v26; // dl
  unsigned __int64 v27; // rcx
  char v28; // dl
  unsigned int v29; // eax
  unsigned __int64 v30; // rcx
  char v31; // dl
  unsigned int v32; // eax
  unsigned __int64 v33; // rcx
  char v34; // dl
  unsigned int v35; // eax

  this->Stream.pData = shapeData;
  this->Stream.DataSize = -1i64;
  this->Stream.CurByteIndex = 0i64;
  this->Stream.CurBitIndex = 0;
  this->Pos = pos;
  v4 = this;
  if ( pos->Initialized )
  {
    this->Stream.CurByteIndex = (unsigned __int64)pos->Pos >> 11;
    this->Stream.CurBitIndex = pos->Pos & 7;
  }
  else
  {
    pos->Sfactor = sfactor;
    this->Pos->StrokeBase = 0;
    this->Pos->FillBase = 0;
    if ( pos->Pos )
    {
      this->Pos->NumFillBits = (pos->Pos >> 7) & 0xF;
      this->Pos->NumStrokeBits = (pos->Pos >> 3) & 0xF;
      this->Stream.CurByteIndex = (unsigned __int64)pos->Pos >> 11;
      this->Stream.CurBitIndex = pos->Pos & 7;
    }
    else
    {
      switch ( this->Stream.CurBitIndex )
      {
        case 0u:
          v5 = (unsigned __int8)this->Stream.pData[this->Stream.CurByteIndex];
          this->Stream.CurBitIndex = 4;
          v6 = v5 >> 4;
          break;
        case 1u:
          v7 = (unsigned __int8)this->Stream.pData[this->Stream.CurByteIndex];
          this->Stream.CurBitIndex = 5;
          v6 = (v7 >> 3) & 0xF;
          break;
        case 2u:
          v8 = (unsigned __int8)this->Stream.pData[this->Stream.CurByteIndex];
          this->Stream.CurBitIndex = 6;
          v6 = (v8 >> 2) & 0xF;
          break;
        case 3u:
          v9 = (unsigned __int8)this->Stream.pData[this->Stream.CurByteIndex];
          this->Stream.CurBitIndex = 7;
          v6 = (v9 >> 1) & 0xF;
          break;
        case 4u:
          v10 = this->Stream.CurByteIndex;
          v11 = v4->Stream.pData[v10];
          v4->Stream.CurBitIndex = 0;
          v6 = v11 & 0xF;
          v4->Stream.CurByteIndex = v10 + 1;
          break;
        case 5u:
          v12 = this->Stream.CurByteIndex;
          v13 = v4->Stream.pData[v12];
          v14 = (unsigned __int8)v4->Stream.pData[v12 + 1];
          v4->Stream.CurBitIndex = 1;
          v6 = (v14 >> 7) | 2 * (v13 & 7);
          v4->Stream.CurByteIndex = v12 + 1;
          break;
        case 6u:
          v15 = this->Stream.CurByteIndex;
          v16 = v4->Stream.pData[v15];
          v17 = (unsigned __int8)v4->Stream.pData[v15 + 1];
          v4->Stream.CurBitIndex = 2;
          v6 = (v17 >> 6) | 4 * (v16 & 3);
          v4->Stream.CurByteIndex = v15 + 1;
          break;
        case 7u:
          v18 = this->Stream.CurByteIndex;
          v19 = v4->Stream.pData[v18];
          v20 = (unsigned __int8)v4->Stream.pData[v18 + 1];
          v4->Stream.CurBitIndex = 3;
          v6 = (v20 >> 5) | 8 * (v19 & 1);
          v4->Stream.CurByteIndex = v18 + 1;
          break;
        default:
          v6 = 0;
          break;
      }
      v4->Pos->NumFillBits = v6;
      switch ( v4->Stream.CurBitIndex )
      {
        case 0u:
          v21 = (unsigned __int8)v4->Stream.pData[v4->Stream.CurByteIndex];
          v4->Stream.CurBitIndex = 4;
          v4->Pos->NumStrokeBits = v21 >> 4;
          break;
        case 1u:
          v22 = (unsigned __int8)v4->Stream.pData[v4->Stream.CurByteIndex];
          v4->Stream.CurBitIndex = 5;
          v4->Pos->NumStrokeBits = (v22 >> 3) & 0xF;
          break;
        case 2u:
          v23 = (unsigned __int8)v4->Stream.pData[v4->Stream.CurByteIndex];
          v4->Stream.CurBitIndex = 6;
          v4->Pos->NumStrokeBits = (v23 >> 2) & 0xF;
          break;
        case 3u:
          v24 = (unsigned __int8)v4->Stream.pData[v4->Stream.CurByteIndex];
          v4->Stream.CurBitIndex = 7;
          v4->Pos->NumStrokeBits = (v24 >> 1) & 0xF;
          break;
        case 4u:
          v25 = v4->Stream.CurByteIndex;
          v26 = v4->Stream.pData[v25];
          v4->Stream.CurBitIndex = 0;
          v4->Stream.CurByteIndex = v25 + 1;
          v4->Pos->NumStrokeBits = v26 & 0xF;
          break;
        case 5u:
          v27 = v4->Stream.CurByteIndex;
          v28 = v4->Stream.pData[v27];
          v29 = (unsigned __int8)v4->Stream.pData[v27 + 1];
          v4->Stream.CurBitIndex = 1;
          v4->Stream.CurByteIndex = v27 + 1;
          v4->Pos->NumStrokeBits = (v29 >> 7) | 2 * (v28 & 7);
          break;
        case 6u:
          v30 = v4->Stream.CurByteIndex;
          v31 = v4->Stream.pData[v30];
          v32 = (unsigned __int8)v4->Stream.pData[v30 + 1];
          v4->Stream.CurBitIndex = 2;
          v4->Stream.CurByteIndex = v30 + 1;
          v4->Pos->NumStrokeBits = (v32 >> 6) | 4 * (v31 & 3);
          break;
        case 7u:
          v33 = v4->Stream.CurByteIndex;
          v34 = v4->Stream.pData[v33];
          v35 = (unsigned __int8)v4->Stream.pData[v33 + 1];
          v4->Stream.CurBitIndex = 3;
          v4->Stream.CurByteIndex = v33 + 1;
          v4->Pos->NumStrokeBits = (v35 >> 5) | 8 * (v34 & 1);
          break;
        default:
          v4->Pos->NumStrokeBits = 0;
          break;
      }
    }
    v4->Pos->LastY = 0;
    v4->Pos->LastX = 0;
    v4->Pos->Stroke = 0;
    v4->Pos->Fill1 = 0;
    v4->Pos->Fill0 = 0;
    v4->Pos->Initialized = 1;
  }
}

// File Line: 472
// RVA: 0x8A7FB0
void __fastcall Scaleform::GFx::SwfShapeDecoder::~SwfShapeDecoder(Scaleform::GFx::SwfShapeDecoder *this)
{
  this->Pos->Pos = this->Stream.CurBitIndex & 7 | 8
                                                * (this->Pos->NumStrokeBits & 0xF | 16
                                                                                  * (16
                                                                                   * LODWORD(this->Stream.CurByteIndex) | this->Pos->NumFillBits & 0xF));
}

// File Line: 488
// RVA: 0x8FB500
signed __int64 __fastcall Scaleform::GFx::SwfShapeDecoder::ReadEdge(Scaleform::GFx::SwfShapeDecoder *this, Scaleform::GFx::SwfShapeDecoder::Edge *edge)
{
  unsigned int v2; // esi
  Scaleform::GFx::SwfShapeDecoder::Edge *v3; // r13
  Scaleform::GFx::SwfShapeDecoder *v4; // rbx
  unsigned int v5; // er8
  int v6; // er9
  unsigned int v7; // eax
  unsigned int v8; // edx
  unsigned int v9; // edx
  unsigned int v10; // edx
  unsigned int v11; // edx
  unsigned int v12; // edx
  unsigned __int64 v13; // rcx
  char v14; // dl
  unsigned __int64 v15; // rcx
  char v16; // dl
  unsigned int v17; // eax
  unsigned __int64 v18; // rcx
  char v19; // dl
  unsigned int v20; // eax
  unsigned __int64 v21; // rcx
  char v22; // dl
  unsigned int v23; // eax
  unsigned int v24; // esi
  signed int v25; // er15
  unsigned int v26; // ebp
  unsigned int v27; // er14
  unsigned int v28; // er12
  unsigned int v29; // er8
  signed __int64 result; // rax
  int v31; // edx
  unsigned int v32; // edx
  unsigned int v33; // edx
  unsigned int v34; // edx
  unsigned int v35; // edx
  unsigned int v36; // edx
  unsigned __int64 v37; // rcx
  char v38; // dl
  unsigned __int64 v39; // rcx
  char v40; // dl
  unsigned int v41; // eax
  unsigned __int64 v42; // rcx
  char v43; // dl
  unsigned int v44; // eax
  unsigned __int64 v45; // rcx
  char v46; // dl
  unsigned int v47; // eax
  unsigned int v48; // er8
  unsigned int v49; // ebp
  int v50; // er9
  unsigned int v51; // er14
  signed int v52; // er12
  unsigned int v53; // edx
  unsigned __int64 v54; // r9
  int v55; // er8

  ++this->Stream.CurBitIndex;
  v2 = 0;
  v3 = edge;
  v4 = this;
  if ( this->Stream.CurBitIndex >= 8 )
  {
    ++this->Stream.CurByteIndex;
    this->Stream.CurBitIndex = 0;
  }
  v5 = this->Stream.CurBitIndex;
  v6 = (unsigned __int8)this->Stream.pData[this->Stream.CurByteIndex] & (1 << (7 - v5));
  this->Stream.CurBitIndex = v5 + 1;
  if ( v5 + 1 >= 8 )
  {
    this->Stream.CurBitIndex = 0;
    ++this->Stream.CurByteIndex;
  }
  v7 = this->Stream.CurBitIndex;
  if ( v6 )
  {
    switch ( v7 )
    {
      case 0u:
        v32 = (unsigned __int8)this->Stream.pData[this->Stream.CurByteIndex];
        this->Stream.CurBitIndex = 4;
        v33 = v32 >> 4;
        break;
      case 1u:
        v34 = (unsigned __int8)this->Stream.pData[this->Stream.CurByteIndex];
        this->Stream.CurBitIndex = 5;
        v33 = (v34 >> 3) & 0xF;
        break;
      case 2u:
        v35 = (unsigned __int8)this->Stream.pData[this->Stream.CurByteIndex];
        this->Stream.CurBitIndex = 6;
        v33 = (v35 >> 2) & 0xF;
        break;
      case 3u:
        v36 = (unsigned __int8)this->Stream.pData[this->Stream.CurByteIndex];
        this->Stream.CurBitIndex = 7;
        v33 = (v36 >> 1) & 0xF;
        break;
      case 4u:
        v37 = this->Stream.CurByteIndex;
        v38 = v4->Stream.pData[v37];
        v4->Stream.CurBitIndex = 0;
        v33 = v38 & 0xF;
        v4->Stream.CurByteIndex = v37 + 1;
        break;
      case 5u:
        v39 = this->Stream.CurByteIndex;
        v40 = v4->Stream.pData[v39];
        v41 = (unsigned __int8)v4->Stream.pData[v39 + 1];
        v4->Stream.CurBitIndex = 1;
        v33 = (v41 >> 7) | 2 * (v40 & 7);
        v4->Stream.CurByteIndex = v39 + 1;
        break;
      case 6u:
        v42 = this->Stream.CurByteIndex;
        v43 = v4->Stream.pData[v42];
        v44 = (unsigned __int8)v4->Stream.pData[v42 + 1];
        v4->Stream.CurBitIndex = 2;
        v33 = (v44 >> 6) | 4 * (v43 & 3);
        v4->Stream.CurByteIndex = v42 + 1;
        break;
      case 7u:
        v45 = this->Stream.CurByteIndex;
        v46 = v4->Stream.pData[v45];
        v47 = (unsigned __int8)v4->Stream.pData[v45 + 1];
        v4->Stream.CurBitIndex = 3;
        v33 = (v47 >> 5) | 8 * (v46 & 1);
        v4->Stream.CurByteIndex = v45 + 1;
        break;
      default:
        v33 = 0;
        break;
    }
    v48 = v4->Stream.CurBitIndex;
    v49 = v33 + 2;
    v50 = (unsigned __int8)v4->Stream.pData[v4->Stream.CurByteIndex] & (1 << (7 - v48));
    v4->Stream.CurBitIndex = v48 + 1;
    if ( v48 + 1 >= 8 )
    {
      v4->Stream.CurBitIndex = 0;
      ++v4->Stream.CurByteIndex;
    }
    v3->Curve = 0;
    v51 = 0;
    if ( v50 )
    {
      v52 = 1 << (v33 + 1);
      v2 = Scaleform::GFx::StreamContext::ReadUInt(&v4->Stream, v49);
      if ( v52 & v2 )
        v2 |= -1 << v49;
      v51 = Scaleform::GFx::StreamContext::ReadUInt(&v4->Stream, v49);
      if ( !(v51 & v52) )
        goto LABEL_49;
    }
    else
    {
      v53 = v4->Stream.CurBitIndex;
      v54 = v4->Stream.CurByteIndex;
      v55 = (unsigned __int8)v4->Stream.pData[v54] & (1 << (7 - v53));
      v4->Stream.CurBitIndex = v53 + 1;
      if ( v53 + 1 >= 8 )
      {
        v4->Stream.CurBitIndex = 0;
        v4->Stream.CurByteIndex = v54 + 1;
      }
      if ( !v55 )
      {
        v2 = Scaleform::GFx::StreamContext::ReadUInt(&v4->Stream, v49);
        if ( _bittest((const signed int *)&v2, (unsigned __int8)(v49 - 1)) )
          v2 |= -1 << v49;
        goto LABEL_49;
      }
      v51 = Scaleform::GFx::StreamContext::ReadUInt(&v4->Stream, v49);
      if ( !_bittest((const signed int *)&v51, (unsigned __int8)(v49 - 1)) )
      {
LABEL_49:
        result = 1i64;
        v3->Ax = v2 + v4->Pos->LastX;
        v3->Ay = v51 + v4->Pos->LastY;
        v4->Pos->LastX += v2;
        v4->Pos->LastY += v51;
        return result;
      }
    }
    v51 |= -1 << v49;
    goto LABEL_49;
  }
  switch ( v7 )
  {
    case 0u:
      v8 = (unsigned __int8)this->Stream.pData[this->Stream.CurByteIndex];
      this->Stream.CurBitIndex = 4;
      v9 = v8 >> 4;
      break;
    case 1u:
      v10 = (unsigned __int8)this->Stream.pData[this->Stream.CurByteIndex];
      this->Stream.CurBitIndex = 5;
      v9 = (v10 >> 3) & 0xF;
      break;
    case 2u:
      v11 = (unsigned __int8)this->Stream.pData[this->Stream.CurByteIndex];
      this->Stream.CurBitIndex = 6;
      v9 = (v11 >> 2) & 0xF;
      break;
    case 3u:
      v12 = (unsigned __int8)this->Stream.pData[this->Stream.CurByteIndex];
      this->Stream.CurBitIndex = 7;
      v9 = (v12 >> 1) & 0xF;
      break;
    case 4u:
      v13 = this->Stream.CurByteIndex;
      v14 = v4->Stream.pData[v13];
      v4->Stream.CurBitIndex = 0;
      v9 = v14 & 0xF;
      v4->Stream.CurByteIndex = v13 + 1;
      break;
    case 5u:
      v15 = this->Stream.CurByteIndex;
      v16 = v4->Stream.pData[v15];
      v17 = (unsigned __int8)v4->Stream.pData[v15 + 1];
      v4->Stream.CurBitIndex = 1;
      v9 = (v17 >> 7) | 2 * (v16 & 7);
      v4->Stream.CurByteIndex = v15 + 1;
      break;
    case 6u:
      v18 = this->Stream.CurByteIndex;
      v19 = v4->Stream.pData[v18];
      v20 = (unsigned __int8)v4->Stream.pData[v18 + 1];
      v4->Stream.CurBitIndex = 2;
      v9 = (v20 >> 6) | 4 * (v19 & 3);
      v4->Stream.CurByteIndex = v18 + 1;
      break;
    case 7u:
      v21 = this->Stream.CurByteIndex;
      v22 = v4->Stream.pData[v21];
      v23 = (unsigned __int8)v4->Stream.pData[v21 + 1];
      v4->Stream.CurBitIndex = 3;
      v9 = (v23 >> 5) | 8 * (v22 & 1);
      v4->Stream.CurByteIndex = v21 + 1;
      break;
    default:
      v9 = 0;
      break;
  }
  v24 = v9 + 2;
  v25 = 1 << (v9 + 1);
  v26 = Scaleform::GFx::StreamContext::ReadUInt(&v4->Stream, v9 + 2);
  if ( v25 & v26 )
    v26 |= -1 << v24;
  v27 = Scaleform::GFx::StreamContext::ReadUInt(&v4->Stream, v24);
  if ( v25 & v27 )
    v27 |= -1 << v24;
  v28 = Scaleform::GFx::StreamContext::ReadUInt(&v4->Stream, v24);
  if ( v25 & v28 )
    v28 |= -1 << v24;
  v29 = Scaleform::GFx::StreamContext::ReadUInt(&v4->Stream, v24);
  if ( v25 & v29 )
    v29 |= -1 << v24;
  v3->Cx = v26 + v4->Pos->LastX;
  v3->Cy = v27 + v4->Pos->LastY;
  result = 2i64;
  v4->Pos->LastX += v28 + v26;
  v4->Pos->LastY += v29 + v27;
  v3->Ax = v4->Pos->LastX;
  v31 = v4->Pos->LastY;
  v3->Curve = 1;
  v3->Ay = v31;
  return result;
}-1 << v24;
  v3->Cx = v26 + v4->Pos->LastX;
  v3->Cy = v27 + v4->Pos->LastY;
  result = 2i64;
  v4->Pos->LastX += v28 + v26;
  v4->Pos->LastY += v29 + v27;
  v3->Ax = v4->Pos->LastX;
  v31 = v4->Pos->LastY;
  v3->Curve = 1;
  v3->Ay = v31;
 

// File Line: 557
// RVA: 0x8FC6E0
signed __int64 __fastcall Scaleform::GFx::SwfShapeDecoder::ReadNonEdgeRec(Scaleform::GFx::SwfShapeDecoder *this, Scaleform::Render::ShapePathType retVal)
{
  Scaleform::Render::ShapePathType v2; // er15
  Scaleform::GFx::SwfShapeDecoder *v3; // rbx
  unsigned int v4; // edi
  unsigned int v5; // edi
  unsigned int v6; // edi
  unsigned int v7; // edi
  char v8; // di
  unsigned __int64 v9; // rax
  char v10; // di
  int v11; // edi
  unsigned int v12; // eax
  unsigned __int64 v13; // rax
  char v14; // di
  unsigned __int64 v15; // rax
  char v16; // di
  unsigned __int64 v17; // rax
  char v18; // di
  unsigned int v19; // esi
  unsigned int v20; // esi
  unsigned int v21; // esi
  unsigned int v22; // esi
  unsigned __int64 v23; // rcx
  char v24; // si
  unsigned __int64 v25; // rcx
  char v26; // si
  unsigned int v27; // eax
  unsigned __int64 v28; // rcx
  char v29; // si
  unsigned int v30; // eax
  unsigned __int64 v31; // rcx
  char v32; // si
  unsigned int v33; // eax
  unsigned __int64 v34; // rcx
  char v35; // si
  unsigned int v36; // eax
  signed int v37; // er14
  unsigned int v38; // er8
  unsigned int v39; // eax
  unsigned int v40; // edx
  unsigned int v41; // eax
  unsigned int v42; // edx
  signed int v43; // eax
  unsigned int v44; // edx
  signed int v45; // eax
  unsigned __int64 v46; // rax
  const char *v47; // r10
  unsigned int v48; // ecx
  unsigned int v49; // er9
  unsigned __int64 v50; // rax
  int v51; // er9
  signed __int64 v52; // rdx
  unsigned __int64 v53; // rax
  int v54; // ecx
  int v55; // er8
  int v56; // er8
  signed __int64 v57; // rdx
  int v58; // eax
  int v59; // ecx
  unsigned int v60; // edx
  unsigned int v61; // edx
  unsigned int v62; // edx
  unsigned int v63; // edx
  unsigned int v64; // edx
  unsigned __int64 v65; // rcx
  char v66; // dl
  unsigned __int64 v67; // rcx
  char v68; // dl
  unsigned int v69; // eax
  unsigned __int64 v70; // rcx
  char v71; // dl
  unsigned int v72; // eax
  unsigned __int64 v73; // rcx
  char v74; // dl
  unsigned int v75; // eax
  unsigned int v76; // edx
  signed __int64 result; // rax
  unsigned int v78; // edx
  unsigned int v79; // edx
  unsigned int v80; // edx
  unsigned __int64 v81; // rcx
  char v82; // dl
  unsigned __int64 v83; // rcx
  char v84; // dl
  unsigned int v85; // eax
  int v86; // edx
  unsigned __int64 v87; // rcx
  char v88; // dl
  unsigned int v89; // eax
  int v90; // edx
  unsigned __int64 v91; // rcx
  char v92; // dl
  unsigned int v93; // eax
  int v94; // edx

  ++this->Stream.CurBitIndex;
  v2 = retVal;
  v3 = this;
  if ( this->Stream.CurBitIndex >= 8 )
  {
    ++this->Stream.CurByteIndex;
    this->Stream.CurBitIndex = 0;
  }
  switch ( this->Stream.CurBitIndex )
  {
    case 0u:
      v4 = (unsigned __int8)this->Stream.pData[this->Stream.CurByteIndex];
      this->Stream.CurBitIndex = 5;
      v5 = v4 >> 3;
      goto LABEL_14;
    case 1u:
      v6 = (unsigned __int8)this->Stream.pData[this->Stream.CurByteIndex];
      this->Stream.CurBitIndex = 6;
      v5 = (v6 >> 2) & 0x1F;
      goto LABEL_14;
    case 2u:
      v7 = (unsigned __int8)this->Stream.pData[this->Stream.CurByteIndex];
      this->Stream.CurBitIndex = 7;
      v5 = (v7 >> 1) & 0x1F;
      goto LABEL_14;
    case 3u:
      v8 = this->Stream.pData[this->Stream.CurByteIndex];
      this->Stream.CurBitIndex = 0;
      v5 = v8 & 0x1F;
      goto LABEL_13;
    case 4u:
      v9 = this->Stream.CurByteIndex;
      v10 = this->Stream.pData[v9];
      LODWORD(v9) = (unsigned __int8)this->Stream.pData[v9 + 1];
      this->Stream.CurBitIndex = 1;
      v11 = 2 * (v10 & 0xF);
      v12 = (unsigned int)v9 >> 7;
      goto LABEL_12;
    case 5u:
      v13 = this->Stream.CurByteIndex;
      v14 = this->Stream.pData[v13];
      LODWORD(v13) = (unsigned __int8)this->Stream.pData[v13 + 1];
      this->Stream.CurBitIndex = 2;
      v11 = 4 * (v14 & 7);
      v12 = (unsigned int)v13 >> 6;
      goto LABEL_12;
    case 6u:
      v15 = this->Stream.CurByteIndex;
      v16 = this->Stream.pData[v15];
      LODWORD(v15) = (unsigned __int8)this->Stream.pData[v15 + 1];
      this->Stream.CurBitIndex = 3;
      v11 = 8 * (v16 & 3);
      v12 = (unsigned int)v15 >> 5;
      goto LABEL_12;
    case 7u:
      v17 = this->Stream.CurByteIndex;
      v18 = this->Stream.pData[v17];
      LODWORD(v17) = (unsigned __int8)this->Stream.pData[v17 + 1];
      this->Stream.CurBitIndex = 4;
      v11 = 16 * (v18 & 1);
      v12 = (unsigned int)v17 >> 4;
LABEL_12:
      v5 = v12 | v11;
LABEL_13:
      ++this->Stream.CurByteIndex;
LABEL_14:
      if ( !v5 )
        goto LABEL_76;
      if ( v5 & 1 )
      {
        switch ( this->Stream.CurBitIndex )
        {
          case 0u:
            v19 = (unsigned __int8)this->Stream.pData[this->Stream.CurByteIndex];
            this->Stream.CurBitIndex = 5;
            v20 = v19 >> 3;
            break;
          case 1u:
            v21 = (unsigned __int8)this->Stream.pData[this->Stream.CurByteIndex];
            this->Stream.CurBitIndex = 6;
            v20 = (v21 >> 2) & 0x1F;
            break;
          case 2u:
            v22 = (unsigned __int8)this->Stream.pData[this->Stream.CurByteIndex];
            this->Stream.CurBitIndex = 7;
            v20 = (v22 >> 1) & 0x1F;
            break;
          case 3u:
            v23 = this->Stream.CurByteIndex;
            v24 = v3->Stream.pData[v23];
            v3->Stream.CurBitIndex = 0;
            v20 = v24 & 0x1F;
            v3->Stream.CurByteIndex = v23 + 1;
            break;
          case 4u:
            v25 = this->Stream.CurByteIndex;
            v26 = v3->Stream.pData[v25];
            v27 = (unsigned __int8)v3->Stream.pData[v25 + 1];
            v3->Stream.CurBitIndex = 1;
            v20 = (v27 >> 7) | 2 * (v26 & 0xF);
            v3->Stream.CurByteIndex = v25 + 1;
            break;
          case 5u:
            v28 = this->Stream.CurByteIndex;
            v29 = v3->Stream.pData[v28];
            v30 = (unsigned __int8)v3->Stream.pData[v28 + 1];
            v3->Stream.CurBitIndex = 2;
            v20 = (v30 >> 6) | 4 * (v29 & 7);
            v3->Stream.CurByteIndex = v28 + 1;
            break;
          case 6u:
            v31 = this->Stream.CurByteIndex;
            v32 = v3->Stream.pData[v31];
            v33 = (unsigned __int8)v3->Stream.pData[v31 + 1];
            v3->Stream.CurBitIndex = 3;
            v20 = (v33 >> 5) | 8 * (v32 & 3);
            v3->Stream.CurByteIndex = v31 + 1;
            break;
          case 7u:
            v34 = this->Stream.CurByteIndex;
            v35 = v3->Stream.pData[v34];
            v36 = (unsigned __int8)v3->Stream.pData[v34 + 1];
            v3->Stream.CurBitIndex = 4;
            v20 = (v36 >> 4) | 16 * (v35 & 1);
            v3->Stream.CurByteIndex = v34 + 1;
            break;
          default:
            v20 = 0;
            break;
        }
        v37 = 1 << (v20 - 1);
        v38 = Scaleform::GFx::StreamContext::ReadUInt(&v3->Stream, v20);
        if ( v37 & v38 )
          v38 |= -1 << v20;
        v3->Pos->LastX = v38;
        v39 = Scaleform::GFx::StreamContext::ReadUInt(&v3->Stream, v20);
        if ( v37 & v39 )
          v39 |= -1 << v20;
        v3->Pos->LastY = v39;
      }
      if ( v5 & 2 )
      {
        v40 = v3->Pos->NumFillBits;
        if ( v40 )
        {
          v41 = Scaleform::GFx::StreamContext::ReadUInt(&v3->Stream, v40);
          if ( v41 )
            v41 += v3->Pos->FillBase;
          v3->Pos->Fill0 = v41;
        }
      }
      if ( v5 & 4 )
      {
        v42 = v3->Pos->NumFillBits;
        if ( v42 )
        {
          v43 = Scaleform::GFx::StreamContext::ReadUInt(&v3->Stream, v42);
          if ( v43 > 0 )
            v43 += v3->Pos->FillBase;
          v3->Pos->Fill1 = v43;
        }
      }
      if ( v5 & 8 )
      {
        v44 = v3->Pos->NumStrokeBits;
        if ( v44 )
        {
          v45 = Scaleform::GFx::StreamContext::ReadUInt(&v3->Stream, v44);
          if ( v45 > 0 )
            v45 += v3->Pos->StrokeBase;
          v3->Pos->Stroke = v45;
        }
      }
      if ( v5 & 0x10 )
      {
        v3->Pos->Stroke = 0;
        v3->Pos->Fill1 = 0;
        v3->Pos->Fill0 = 0;
        if ( v3->Stream.CurBitIndex )
          ++v3->Stream.CurByteIndex;
        v3->Stream.CurBitIndex = 0;
        v46 = v3->Stream.CurByteIndex;
        v47 = v3->Stream.pData;
        v48 = (unsigned __int8)v3->Stream.pData[v46];
        v3->Stream.CurByteIndex = v46 + 1;
        v49 = v48;
        if ( (_BYTE)v48 )
        {
          v50 = v3->Stream.CurByteIndex;
          v3->Stream.CurBitIndex = 0;
          v51 = (unsigned __int8)v47[v50];
          v3->Stream.CurBitIndex = 0;
          v3->Stream.CurByteIndex = v50 + 1;
          v52 = v50 + 2;
          LODWORD(v50) = (unsigned __int8)v47[v50 + 1] << 8;
          v3->Stream.CurBitIndex = 0;
          v3->Stream.CurByteIndex = v52;
          v49 = (unsigned __int8)v47[v52] | v50 | (v51 << 16);
          v3->Stream.CurByteIndex = v52 + 1;
        }
        if ( v3->Stream.CurBitIndex )
          ++v3->Stream.CurByteIndex;
        v53 = v3->Stream.CurByteIndex;
        v3->Stream.CurBitIndex = 0;
        v54 = (unsigned __int8)v47[v53];
        v3->Stream.CurByteIndex = v53 + 1;
        v55 = v54;
        if ( v54 == 255 )
        {
          v3->Stream.CurBitIndex = 0;
          v56 = (unsigned __int8)v47[v53 + 1];
          v3->Stream.CurByteIndex = v53 + 2;
          v57 = v53 + 3;
          v3->Stream.CurBitIndex = 0;
          v58 = (unsigned __int8)v47[v53 + 2];
          v3->Stream.CurByteIndex = v57;
          v3->Stream.CurBitIndex = 0;
          v59 = (unsigned __int8)v47[v57];
          v3->Stream.CurByteIndex = v57 + 1;
          v55 = v59 | (v58 << 8) | (v56 << 16);
        }
        v3->Pos->FillBase = v49;
        v3->Pos->StrokeBase = v55;
        switch ( v3->Stream.CurBitIndex )
        {
          case 0u:
            v60 = (unsigned __int8)v3->Stream.pData[v3->Stream.CurByteIndex];
            v3->Stream.CurBitIndex = 4;
            v61 = v60 >> 4;
            break;
          case 1u:
            v62 = (unsigned __int8)v3->Stream.pData[v3->Stream.CurByteIndex];
            v3->Stream.CurBitIndex = 5;
            v61 = (v62 >> 3) & 0xF;
            break;
          case 2u:
            v63 = (unsigned __int8)v3->Stream.pData[v3->Stream.CurByteIndex];
            v3->Stream.CurBitIndex = 6;
            v61 = (v63 >> 2) & 0xF;
            break;
          case 3u:
            v64 = (unsigned __int8)v3->Stream.pData[v3->Stream.CurByteIndex];
            v3->Stream.CurBitIndex = 7;
            v61 = (v64 >> 1) & 0xF;
            break;
          case 4u:
            v65 = v3->Stream.CurByteIndex;
            v66 = v3->Stream.pData[v65];
            v3->Stream.CurBitIndex = 0;
            v61 = v66 & 0xF;
            v3->Stream.CurByteIndex = v65 + 1;
            break;
          case 5u:
            v67 = v3->Stream.CurByteIndex;
            v68 = v3->Stream.pData[v67];
            v69 = (unsigned __int8)v3->Stream.pData[v67 + 1];
            v3->Stream.CurBitIndex = 1;
            v61 = (v69 >> 7) | 2 * (v68 & 7);
            v3->Stream.CurByteIndex = v67 + 1;
            break;
          case 6u:
            v70 = v3->Stream.CurByteIndex;
            v71 = v3->Stream.pData[v70];
            v72 = (unsigned __int8)v3->Stream.pData[v70 + 1];
            v3->Stream.CurBitIndex = 2;
            v61 = (v72 >> 6) | 4 * (v71 & 3);
            v3->Stream.CurByteIndex = v70 + 1;
            break;
          case 7u:
            v73 = v3->Stream.CurByteIndex;
            v74 = v3->Stream.pData[v73];
            v75 = (unsigned __int8)v3->Stream.pData[v73 + 1];
            v3->Stream.CurBitIndex = 3;
            v61 = (v75 >> 5) | 8 * (v74 & 1);
            v3->Stream.CurByteIndex = v73 + 1;
            break;
          default:
            v61 = 0;
            break;
        }
        v3->Pos->NumFillBits = v61;
        switch ( v3->Stream.CurBitIndex )
        {
          case 0u:
            v76 = (unsigned __int8)v3->Stream.pData[v3->Stream.CurByteIndex];
            v3->Stream.CurBitIndex = 4;
            result = 2i64;
            v3->Pos->NumStrokeBits = v76 >> 4;
            break;
          case 1u:
            v78 = (unsigned __int8)v3->Stream.pData[v3->Stream.CurByteIndex];
            v3->Stream.CurBitIndex = 5;
            result = 2i64;
            v3->Pos->NumStrokeBits = (v78 >> 3) & 0xF;
            break;
          case 2u:
            v79 = (unsigned __int8)v3->Stream.pData[v3->Stream.CurByteIndex];
            v3->Stream.CurBitIndex = 6;
            result = 2i64;
            v3->Pos->NumStrokeBits = (v79 >> 2) & 0xF;
            break;
          case 3u:
            v80 = (unsigned __int8)v3->Stream.pData[v3->Stream.CurByteIndex];
            v3->Stream.CurBitIndex = 7;
            result = 2i64;
            v3->Pos->NumStrokeBits = (v80 >> 1) & 0xF;
            break;
          case 4u:
            v81 = v3->Stream.CurByteIndex;
            v82 = v3->Stream.pData[v81];
            v3->Stream.CurBitIndex = 0;
            v3->Stream.CurByteIndex = v81 + 1;
            v3->Pos->NumStrokeBits = v82 & 0xF;
            result = 2i64;
            break;
          case 5u:
            v83 = v3->Stream.CurByteIndex;
            v84 = v3->Stream.pData[v83];
            v85 = (unsigned __int8)v3->Stream.pData[v83 + 1];
            v3->Stream.CurBitIndex = 1;
            v86 = (v85 >> 7) | 2 * (v84 & 7);
            v3->Stream.CurByteIndex = v83 + 1;
            result = 2i64;
            v3->Pos->NumStrokeBits = v86;
            break;
          case 6u:
            v87 = v3->Stream.CurByteIndex;
            v88 = v3->Stream.pData[v87];
            v89 = (unsigned __int8)v3->Stream.pData[v87 + 1];
            v3->Stream.CurBitIndex = 2;
            v90 = (v89 >> 6) | 4 * (v88 & 3);
            v3->Stream.CurByteIndex = v87 + 1;
            result = 2i64;
            v3->Pos->NumStrokeBits = v90;
            break;
          case 7u:
            v91 = v3->Stream.CurByteIndex;
            v92 = v3->Stream.pData[v91];
            v93 = (unsigned __int8)v3->Stream.pData[v91 + 1];
            v3->Stream.CurBitIndex = 3;
            v94 = (v93 >> 5) | 8 * (v92 & 1);
            v3->Stream.CurByteIndex = v91 + 1;
            result = 2i64;
            v3->Pos->NumStrokeBits = v94;
            break;
          default:
            result = 2i64;
            v3->Pos->NumStrokeBits = 0;
            break;
        }
      }
      else
      {
        result = (unsigned int)v2;
      }
      break;
    default:
LABEL_76:
      result = 0i64;
      break;
  }
  return result;
}

// File Line: 695
// RVA: 0x8FBEE0
__int64 __fastcall Scaleform::GFx::ShapeSwfReader::ReadFillStyles(Scaleform::GFx::ShapeSwfReader *this, Scaleform::GFx::LoadProcess *p, Scaleform::GFx::TagType tagType)
{
  Scaleform::GFx::Stream *v3; // rbx
  Scaleform::GFx::TagType v4; // er13
  Scaleform::GFx::LoadProcess *v5; // rdi
  Scaleform::GFx::ShapeSwfReader *v6; // r14
  unsigned int v7; // eax
  __int64 v8; // rdx
  unsigned int v9; // ecx
  unsigned int v10; // ebp
  Scaleform::GFx::SWFProcessInfo *v11; // rax
  unsigned int v12; // er15
  int v13; // er12
  unsigned int v14; // esi
  signed __int64 v15; // rax
  Scaleform::Render::FillStyleType *v16; // rbx
  Scaleform::Render::ComplexFill *v17; // rax
  Scaleform::Render::ComplexFill *v18; // rcx
  Scaleform::GFx::FillStyleSwfReader v20; // [rsp+50h] [rbp+8h]

  v3 = p->pAltStream;
  v4 = tagType;
  v5 = p;
  v6 = this;
  if ( !v3 )
    v3 = &p->ProcessInfo.Stream;
  v7 = v3->DataSize;
  v3->UnusedBits = 0;
  if ( (signed int)(v7 - v3->Pos) < 1 )
    Scaleform::GFx::Stream::PopulateBuffer(v3, 1);
  v8 = v3->Pos;
  v9 = (unsigned __int8)v3->pBuffer[v8];
  v3->Pos = v8 + 1;
  v10 = v9;
  if ( (signed int)v4 > 2 && v9 == 255 )
    v10 = Scaleform::GFx::LoadProcess::ReadU16(v5);
  v11 = (Scaleform::GFx::SWFProcessInfo *)v5->pAltStream;
  if ( !v11 )
    v11 = &v5->ProcessInfo;
  v12 = v11->Stream.Pos + v11->Stream.FilePos - v11->Stream.DataSize;
  Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
    (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&v5->vfptr,
    "  GFx_ReadFillStyles: count = %d\n");
  v13 = v6->FillStyles.Data.Size;
  if ( v10 )
    Scaleform::ArrayData<Scaleform::Render::FillStyleType,Scaleform::AllocatorGH<Scaleform::Render::FillStyleType,259>,Scaleform::ArrayDefaultPolicy>::Resize(
      &v6->FillStyles.Data,
      v13 + v10);
  v14 = 0;
  if ( v10 )
  {
    do
    {
      v15 = (signed __int64)v5->pAltStream;
      if ( !v15 )
        v15 = (signed __int64)&v5->ProcessInfo;
      *(_BYTE *)(v15 + 41) = 0;
      v20.FillStyle = &v6->FillStyles.Data.Data[v14 + v13];
      v16 = v20.FillStyle;
      Scaleform::GFx::FillStyleSwfReader::Read(&v20, v5, v4);
      v17 = v16->pFill.pObject;
      if ( v17 && (v17->pImage.pObject || v17->BindIndex != -1) )
        v6->Shape->Flags |= 1u;
      v18 = v16->pFill.pObject;
      if ( v18 && v18->BindIndex != -1 )
        v6->Shape->Flags |= 4u;
      ++v14;
    }
    while ( v14 < v10 );
  }
  return v12;
}

// File Line: 725
// RVA: 0x8FD6E0
__int64 __fastcall Scaleform::GFx::ShapeSwfReader::ReadStrokeStyles(Scaleform::GFx::ShapeSwfReader *this, Scaleform::GFx::LoadProcess *p, Scaleform::GFx::TagType tagType)
{
  Scaleform::GFx::Stream *v3; // rbx
  Scaleform::GFx::LoadProcess *v4; // rdi
  Scaleform::GFx::ShapeSwfReader *v5; // r14
  unsigned int v6; // eax
  __int64 v7; // rdx
  unsigned int v8; // ebp
  Scaleform::GFx::Stream *v9; // rbx
  unsigned int v10; // eax
  __int64 v11; // r10
  Scaleform::GFx::SWFProcessInfo *v12; // rax
  int v13; // er12
  unsigned int v14; // er15
  unsigned int v15; // esi
  Scaleform::GFx::TagType v16; // er15
  signed __int64 v17; // rax
  Scaleform::Render::StrokeStyleType *v18; // rax
  signed __int64 v19; // rbx
  __int64 v20; // rax
  __int64 v21; // rcx
  unsigned int v23; // [rsp+60h] [rbp+8h]
  Scaleform::GFx::StrokeStyleSwfReader v24; // [rsp+68h] [rbp+10h]
  Scaleform::GFx::TagType tagTypea; // [rsp+70h] [rbp+18h]

  tagTypea = tagType;
  v3 = p->pAltStream;
  v4 = p;
  v5 = this;
  if ( !v3 )
    v3 = &p->ProcessInfo.Stream;
  v6 = v3->DataSize;
  v3->UnusedBits = 0;
  if ( (signed int)(v6 - v3->Pos) < 1 )
    Scaleform::GFx::Stream::PopulateBuffer(v3, 1);
  v7 = v3->Pos;
  v8 = (unsigned __int8)v3->pBuffer[v7];
  v3->Pos = v7 + 1;
  Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
    (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&v4->vfptr,
    "  GFx_ReadStrokeStyles: count = %d\n");
  if ( v8 == 255 )
  {
    v9 = v4->pAltStream;
    if ( !v9 )
      v9 = &v4->ProcessInfo.Stream;
    v10 = v9->DataSize;
    v9->UnusedBits = 0;
    if ( (signed int)(v10 - v9->Pos) < 2 )
      Scaleform::GFx::Stream::PopulateBuffer(v9, 2);
    v11 = v9->Pos;
    v8 = (unsigned __int16)((unsigned __int8)v9->pBuffer[v11] | (unsigned __int16)((unsigned __int8)v9->pBuffer[(unsigned int)(v11 + 1)] << 8));
    v9->Pos = v11 + 2;
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
      (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&v4->vfptr,
      "  GFx_ReadStrokeStyles: count2 = %d\n");
  }
  v12 = (Scaleform::GFx::SWFProcessInfo *)v4->pAltStream;
  if ( !v12 )
    v12 = &v4->ProcessInfo;
  v13 = v5->StrokeStyles.Data.Size;
  v14 = v12->Stream.Pos + v12->Stream.FilePos - v12->Stream.DataSize;
  v23 = v12->Stream.Pos + v12->Stream.FilePos - v12->Stream.DataSize;
  Scaleform::ArrayData<Scaleform::Render::StrokeStyleType,Scaleform::AllocatorGH<Scaleform::Render::StrokeStyleType,259>,Scaleform::ArrayDefaultPolicy>::Resize(
    &v5->StrokeStyles.Data,
    v13 + v8);
  v15 = 0;
  if ( !v8 )
    return v14;
  v16 = tagTypea;
  do
  {
    v17 = (signed __int64)v4->pAltStream;
    if ( !v17 )
      v17 = (signed __int64)&v4->ProcessInfo;
    *(_BYTE *)(v17 + 41) = 0;
    v18 = v5->StrokeStyles.Data.Data;
    v19 = (signed __int64)&v18[v15 + v13];
    v24.StrokeStyle = &v18[v15 + v13];
    Scaleform::GFx::StrokeStyleSwfReader::Read(&v24, v4, v16);
    v20 = *(_QWORD *)(v19 + 24);
    if ( v20 && (*(_QWORD *)(v20 + 16) || *(_DWORD *)(v20 + 68) != -1) )
      v5->Shape->Flags |= 1u;
    v21 = *(_QWORD *)(v19 + 24);
    if ( v21 )
    {
      if ( *(_DWORD *)(v21 + 68) != -1 )
        v5->Shape->Flags |= 4u;
    }
    ++v15;
  }
  while ( v15 < v8 );
  return v23;
}

// File Line: 760
// RVA: 0x8F8780
bool __fastcall Scaleform::GFx::ShapeSwfReader::Read(Scaleform::GFx::ShapeSwfReader *this, Scaleform::GFx::LoadProcess *p, Scaleform::GFx::TagType tagType, unsigned int lenInBytes)
{
  unsigned int v4; // er12
  Scaleform::GFx::TagType v5; // esi
  Scaleform::GFx::LoadProcess *v6; // r13
  Scaleform::GFx::ShapeSwfReader *v7; // r15
  Scaleform::GFx::Stream *v8; // r14
  int v9; // eax
  char v10; // di
  int v11; // ebx
  float v12; // er12
  char *v13; // rax
  const char *v14; // rsi
  float v16; // xmm8_4
  unsigned int v17; // er14
  int v18; // er13
  int v19; // er15
  int v20; // er12
  int v21; // esi
  bool v22; // di
  unsigned int v23; // er10
  __int64 v24; // r8
  unsigned int v25; // edx
  char v26; // r9
  unsigned int v27; // er11
  unsigned __int8 v28; // dl
  unsigned int v29; // eax
  char v30; // r14
  unsigned int v31; // edi
  signed int v32; // esi
  signed int v33; // eax
  Scaleform::GFx::ShapeSwfReader *v34; // r12
  signed int v35; // er13
  int v36; // er15
  signed int v37; // esi
  int v38; // edi
  signed int v39; // er14
  int v40; // edx
  bool v41; // zf
  bool v42; // sf
  unsigned __int8 v43; // of
  __int64 v44; // r12
  __int64 v45; // rcx
  int v46; // edi
  int v47; // edx
  __int64 v48; // rcx
  float v49; // esi
  unsigned int v50; // edx
  unsigned int v51; // er8
  char v52; // dl
  unsigned int v53; // edi
  unsigned int v54; // er13
  signed int v55; // esi
  unsigned int v56; // er12
  unsigned int v57; // er15
  unsigned int v58; // er14
  unsigned int v59; // edi
  unsigned int v60; // esi
  signed int v61; // er15
  unsigned int v62; // eax
  __int64 v63; // r9
  char *v64; // rsi
  bool v65; // di
  unsigned __int64 v66; // rdx
  double plog; // [rsp+20h] [rbp-A0h]
  double pparseControl; // [rsp+28h] [rbp-98h]
  double v69; // [rsp+30h] [rbp-90h]
  double v70; // [rsp+38h] [rbp-88h]
  unsigned int oldSize; // [rsp+40h] [rbp-80h]
  int v72; // [rsp+44h] [rbp-7Ch]
  __int64 bitcount; // [rsp+48h] [rbp-78h]
  Scaleform::Render::Rect<float> pr; // [rsp+50h] [rbp-70h]
  Scaleform::Render::Rect<float> v75; // [rsp+60h] [rbp-60h]
  Scaleform::GFx::Stream v76; // [rsp+70h] [rbp-50h]
  __int64 v77; // [rsp+2E0h] [rbp+220h]
  Scaleform::GFx::ShapeSwfReader *v78; // [rsp+370h] [rbp+2B0h]
  Scaleform::GFx::LoadProcess *pa; // [rsp+378h] [rbp+2B8h]
  Scaleform::GFx::TagType tagTypea; // [rsp+380h] [rbp+2C0h]
  int v81; // [rsp+388h] [rbp+2C8h]
  int v82; // [rsp+390h] [rbp+2D0h]

  v77 = -2i64;
  v4 = lenInBytes;
  v5 = tagType;
  v6 = p;
  v7 = this;
  *(_QWORD *)&v75.x2 = this->pAllocator;
  if ( !*(_QWORD *)&v75.x2 )
    *(_QWORD *)&v75.x2 = p->pLoadData.pObject->pPathAllocator;
  v8 = p->pAltStream;
  if ( !v8 )
    v8 = &p->ProcessInfo.Stream;
  this->Shape->Flags = 0;
  v9 = 0;
  v10 = v82;
  if ( (_BYTE)v82 )
  {
    v11 = v8->FilePos + v8->Pos - v8->DataSize;
    this->Shape->Flags |= 0x10u;
    pr = 0i64;
    Scaleform::GFx::Stream::ReadRect(v8, &pr);
    v7->Shape->vfptr[12].__vecDelDtor((Scaleform::RefCountImplCore *)&v7->Shape->vfptr, (unsigned int)&pr);
    if ( (v5 - 75) & 0xFFFFFFF7 )
    {
      v7->Shape->vfptr[14].__vecDelDtor((Scaleform::RefCountImplCore *)&v7->Shape->vfptr, (unsigned int)&pr);
    }
    else
    {
      v75 = 0i64;
      Scaleform::GFx::Stream::ReadRect(v8, &v75);
      v7->Shape->vfptr[14].__vecDelDtor((Scaleform::RefCountImplCore *)&v7->Shape->vfptr, (unsigned int)&v75);
      v8->UnusedBits = 0;
      if ( (signed int)(v8->DataSize - v8->Pos) < 1 )
        Scaleform::GFx::Stream::PopulateBuffer(v8, 1);
      ++v8->Pos;
    }
    Scaleform::GFx::ShapeSwfReader::ReadFillStyles(v7, v6, v5);
    Scaleform::GFx::ShapeSwfReader::ReadStrokeStyles(v7, v6, v5);
    v9 = v8->FilePos + v8->Pos - v8->DataSize - v11;
  }
  LODWORD(v12) = v4 - v9;
  pr.x1 = v12;
  *((float *)&bitcount + 1) = v12;
  v13 = Scaleform::GFx::PathAllocator::AllocMemoryBlock(
          *(Scaleform::GFx::PathAllocator **)&v75.x2,
          LODWORD(v12),
          LODWORD(v12));
  v14 = v13;
  *(_QWORD *)&pr.x2 = v13;
  if ( !v13 )
  {
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogWarning(
      (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&v8->vfptr,
      "Corrupted shape detected in file %s",
      (v8->FileName.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12);
    return 0;
  }
  v8->UnusedBits = 0;
  Scaleform::GFx::Stream::ReadToBuffer(v8, v13, LODWORD(v12));
  v16 = *(float *)&FLOAT_1_0;
  if ( tagTypea == 75 )
  {
    v16 = FLOAT_0_050000001;
    v7->Shape->Flags |= 2u;
  }
  Scaleform::GFx::Stream::Stream(&v76, v14, LODWORD(v12), v6->pLoadData.pObject->pHeap, v8->pLog, v8->pParseControl);
  v6->pAltStream = &v76;
  v76.UnusedBits = 0;
  LODWORD(bitcount) = Scaleform::GFx::Stream::ReadUInt(&v76, 4u);
  LODWORD(v75.x1) = Scaleform::GFx::Stream::ReadUInt(&v76, 4u);
  if ( v10 )
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
      (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&v76.vfptr,
      "  ShapeCharacter read: nfillbits = %d, nlinebits = %d\n");
  v17 = 0;
  LODWORD(v76.vfptr) = 0;
  LODWORD(v76.pLog) = 0;
  v18 = 0;
  oldSize = 0;
  v19 = 0;
  v81 = 0;
  v20 = 0;
  v72 = 0;
  v21 = 0;
  v82 = 0;
  v22 = 0;
  v23 = v76.DataSize;
  LODWORD(v24) = v76.Pos;
  while ( 1 )
  {
    if ( v76.UnusedBits )
    {
      v26 = v76.UnusedBits - 1;
      v76.UnusedBits = v26;
      v27 = (unsigned int)(unsigned __int8)v76.CurrentByte >> v26;
      v28 = ((1 << v26) - 1) & v76.CurrentByte;
    }
    else
    {
      if ( (signed int)(v23 - v24) < 1 )
      {
        Scaleform::GFx::Stream::PopulateBuffer(&v76, 1);
        v23 = v76.DataSize;
        LODWORD(v24) = v76.Pos;
      }
      v25 = (unsigned __int8)v76.pBuffer[(unsigned int)v24];
      LODWORD(v24) = v24 + 1;
      v76.Pos = v24;
      v76.CurrentByte = v25;
      v26 = 7;
      v76.UnusedBits = 7;
      v27 = v25 >> 7;
      v28 = v25 & 0x7F;
    }
    v76.CurrentByte = v28;
    if ( v27 )
    {
      if ( v26 )
      {
        v76.UnusedBits = v26 - 1;
        v51 = (unsigned int)v28 >> (v26 - 1);
        v52 = ((1 << (v26 - 1)) - 1) & v28;
      }
      else
      {
        v76.UnusedBits = 0;
        if ( (signed int)(v23 - v24) < 1 )
        {
          Scaleform::GFx::Stream::PopulateBuffer(&v76, 1);
          LODWORD(v24) = v76.Pos;
        }
        v50 = (unsigned __int8)v76.pBuffer[(unsigned int)v24];
        v76.Pos = v24 + 1;
        v76.CurrentByte = v50;
        v76.UnusedBits = 7;
        v51 = v50 >> 7;
        v52 = v50 & 0x7F;
      }
      v76.CurrentByte = v52;
      v72 = v20 + 1;
      if ( v51 )
      {
        v59 = Scaleform::GFx::Stream::ReadUInt(&v76, 4u) + 2;
        v60 = 0;
        if ( Scaleform::GFx::Stream::ReadUInt1(&v76) )
        {
          v17 = Scaleform::GFx::Stream::ReadUInt(&v76, v59);
          v61 = 1 << (v59 - 1);
          if ( v61 & v17 )
            v17 |= -1 << v59;
          v60 = Scaleform::GFx::Stream::ReadUInt(&v76, v59);
          if ( v61 & v60 )
            v60 |= -1 << v59;
          v19 = v81;
        }
        else if ( Scaleform::GFx::Stream::ReadUInt1(&v76) )
        {
          v60 = Scaleform::GFx::Stream::ReadUInt(&v76, v59);
          if ( _bittest((const signed int *)&v60, (unsigned __int8)(v59 - 1)) )
            v60 |= -1 << v59;
        }
        else
        {
          v17 = Scaleform::GFx::Stream::ReadUInt(&v76, v59);
          if ( _bittest((const signed int *)&v17, (unsigned __int8)(v59 - 1)) )
            v17 |= -1 << v59;
        }
        if ( (v76.ParseFlags >> 4) & 1 )
        {
          pparseControl = (float)((float)(signed int)(v60 + v19) * v16);
          plog = (float)((float)(signed int)(v17 + v18) * v16);
          Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
            (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&v76.vfptr,
            "  ShapeCharacter read: straight edge = %4g %4g - %4g %4g\n");
        }
        v18 += v17;
        v19 += v60;
      }
      else
      {
        v53 = Scaleform::GFx::Stream::ReadUInt(&v76, 4u) + 2;
        v54 = Scaleform::GFx::Stream::ReadUInt(&v76, v53);
        v55 = 1 << (v53 - 1);
        if ( v55 & v54 )
          v54 |= -1 << v53;
        v56 = Scaleform::GFx::Stream::ReadUInt(&v76, v53);
        if ( v55 & v56 )
          v56 |= -1 << v53;
        v57 = Scaleform::GFx::Stream::ReadUInt(&v76, v53);
        if ( v55 & v57 )
          v57 |= -1 << v53;
        v58 = Scaleform::GFx::Stream::ReadUInt(&v76, v53);
        if ( v55 & v58 )
          v58 |= -1 << v53;
        if ( (v76.ParseFlags >> 4) & 1 )
        {
          v70 = (float)((float)(signed int)(v81 + v58 + v56) * v16);
          v69 = (float)((float)(signed int)(oldSize + v57 + v54) * v16);
          pparseControl = (float)((float)(signed int)(v56 + v81) * v16);
          plog = (float)((float)(signed int)(oldSize + v54) * v16);
          Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
            (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&v76.vfptr,
            "  ShapeCharacter read: curved edge   = %4g %4g - %4g %4g - %4g %4g\n");
        }
        v18 = v57 + v54 + oldSize;
        v19 = v58 + v56 + v81;
      }
      v81 = v19;
      oldSize = v18;
      goto LABEL_106;
    }
    v29 = Scaleform::GFx::Stream::ReadUInt(&v76, 5u);
    v30 = v29;
    if ( !v29 )
      goto LABEL_110;
    if ( v29 & 1 )
    {
      if ( v20 > 0 )
      {
        v20 = 0;
        v72 = 0;
        v82 = v21 + 1;
      }
      v31 = Scaleform::GFx::Stream::ReadUInt(&v76, 5u);
      v18 = Scaleform::GFx::Stream::ReadUInt(&v76, v31);
      oldSize = v18;
      v32 = 1 << (v31 - 1);
      if ( v32 & v18 )
      {
        v18 |= -1 << v31;
        oldSize = v18;
      }
      v19 = Scaleform::GFx::Stream::ReadUInt(&v76, v31);
      v81 = v19;
      if ( v32 & v19 )
      {
        v19 |= -1 << v31;
        v81 = v19;
      }
      if ( (v76.ParseFlags >> 4) & 1 )
        Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
          (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&v76.vfptr,
          "  ShapeCharacter read: moveto %4g %4g\n");
      v21 = v82;
    }
    v33 = bitcount;
    if ( v30 & 2 && (signed int)bitcount > 0 )
    {
      if ( v20 > 0 )
      {
        v20 = 0;
        v72 = 0;
        v82 = ++v21;
      }
      Scaleform::GFx::Stream::ReadUInt(&v76, bitcount);
      if ( (v76.ParseFlags >> 4) & 1 )
        Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
          (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&v76.vfptr,
          "  ShapeCharacter read: fill0 = %d\n");
      v33 = bitcount;
    }
    if ( v30 & 4 && v33 > 0 )
    {
      if ( v20 > 0 )
      {
        v20 = 0;
        v72 = 0;
        v82 = ++v21;
      }
      Scaleform::GFx::Stream::ReadUInt(&v76, v33);
      if ( (v76.ParseFlags >> 4) & 1 )
        Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
          (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&v76.vfptr,
          "  ShapeCharacter read: fill1 = %d\n");
    }
    if ( v30 & 8 && SLODWORD(v75.x1) > 0 )
    {
      if ( v20 > 0 )
      {
        v20 = 0;
        v72 = 0;
        v82 = ++v21;
      }
      Scaleform::GFx::Stream::ReadUInt(&v76, LODWORD(v75.x1));
      if ( (v76.ParseFlags >> 4) & 1 )
        Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
          (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&v76.vfptr,
          "  ShapeCharacter read: line = %d\n");
    }
    if ( v30 & 0x10 )
      break;
LABEL_106:
    v23 = v76.DataSize;
    v24 = v76.Pos;
    v62 = v76.Pos + v76.FilePos - v76.DataSize;
    v22 = v62 > HIDWORD(bitcount);
    if ( v62 > HIDWORD(bitcount) )
      goto LABEL_110;
    v21 = v82;
    v20 = v72;
    v17 = 0;
  }
  Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
    (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&v76.vfptr,
    "  ShapeCharacter read: more fill styles\n");
  if ( v21 > 0 )
    v21 = 0;
  v82 = v21;
  if ( v20 > 0 )
  {
    v72 = 0;
    v82 = v21 + 1;
  }
  v34 = v78;
  v76.vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::Stream>Vtbl *)v78->FillStyles.Data.Size;
  v76.pLog = (Scaleform::Log *)v78->StrokeStyles.Data.Size;
  v35 = v76.Pos + v76.FilePos - v76.DataSize;
  v36 = Scaleform::GFx::ShapeSwfReader::ReadFillStyles(v78, pa, tagTypea);
  v37 = v76.Pos + v76.FilePos - v76.DataSize;
  v38 = Scaleform::GFx::ShapeSwfReader::ReadStrokeStyles(v34, pa, tagTypea);
  v39 = v76.Pos + v76.FilePos - v76.DataSize;
  if ( v37 == v36 )
  {
    v44 = *(_QWORD *)&pr.x2;
  }
  else
  {
    if ( v36 > v37 || (unsigned int)v37 > HIDWORD(bitcount) )
    {
      v22 = 1;
      goto LABEL_111;
    }
    v40 = (int)v76.vfptr;
    v43 = __OFSUB__(v34->FillStyles.Data.Size, v76.vfptr);
    v41 = LODWORD(v34->FillStyles.Data.Size) == LODWORD(v76.vfptr);
    v42 = LODWORD(v34->FillStyles.Data.Size) - LODWORD(v76.vfptr) < 0;
    v44 = *(_QWORD *)&pr.x2;
    if ( !((unsigned __int8)(v42 ^ v43) | v41) )
    {
      v45 = v35;
      *(_BYTE *)(v45 + *(_QWORD *)&pr.x2) = -1;
      *(_BYTE *)(v45 + v44 + 1) = BYTE2(v40);
      *(_BYTE *)(v45 + v44 + 2) = BYTE1(v40);
      *(_BYTE *)(v45 + v44 + 3) = v40;
      v36 = v35 + 4;
    }
    v46 = v38 - v37;
    memmove((void *)(v44 + v36), (const void *)(v44 + v37), v46);
    v38 = v36 + v46;
    v37 = v36;
  }
  if ( v38 == v39 )
    goto LABEL_73;
  if ( v38 <= v39 && (unsigned int)v39 <= HIDWORD(bitcount) )
  {
    v47 = (int)v76.pLog;
    if ( SLODWORD(v78->StrokeStyles.Data.Size) > SLODWORD(v76.pLog) )
    {
      v48 = v37;
      *(_BYTE *)(v48 + v44) = -1;
      *(_BYTE *)(v48 + v44 + 1) = BYTE2(v47);
      *(_BYTE *)(v48 + v44 + 2) = BYTE1(v47);
      *(_BYTE *)(v48 + v44 + 3) = v47;
      v38 = v37 + 4;
    }
    v49 = pr.x1;
    memmove((void *)(v44 + v38), (const void *)(v44 + v39), (unsigned int)(LODWORD(pr.x1) - v39));
    LODWORD(pr.x1) = v38 - v39 + LODWORD(v49);
LABEL_73:
    Scaleform::GFx::Stream::SetPosition(&v76, v38);
    LODWORD(bitcount) = Scaleform::GFx::Stream::ReadUInt(&v76, 4u);
    LODWORD(v75.x1) = Scaleform::GFx::Stream::ReadUInt(&v76, 4u);
    v19 = v81;
    v18 = oldSize;
    goto LABEL_106;
  }
  v22 = 1;
LABEL_110:
  v34 = v78;
LABEL_111:
  v63 = LODWORD(pr.x1);
  if ( v22 || LODWORD(pr.x1) >= 0x200000 )
  {
    v22 = 1;
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogWarning(
      (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&v76.vfptr,
      "Corrupted shape detected in file %s",
      (*(_QWORD *)(bitcount + 48) & 0xFFFFFFFFFFFFFFFCui64) + 12,
      pr.x1,
      plog,
      pparseControl,
      v69,
      v70);
    v64 = *(char **)&pr.x2;
    **(_WORD **)&pr.x2 = 0;
    if ( oldSize > 2 )
    {
      LODWORD(v63) = 2;
      goto LABEL_117;
    }
  }
  else
  {
    v64 = *(char **)&pr.x2;
    if ( oldSize > LODWORD(pr.x1) )
LABEL_117:
      Scaleform::GFx::PathAllocator::ReallocLastBlock(*(Scaleform::GFx::PathAllocator **)&v75.x2, v64, oldSize, v63);
  }
  v34->Shape->Paths = v64;
  pa->pAltStream = 0i64;
  v65 = v22 == 0;
  v76.vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::Stream>Vtbl *)&Scaleform::GFx::Stream::`vftable;
  v78 = (Scaleform::GFx::ShapeSwfReader *)&v76.FileName;
  v66 = v76.FileName.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64;
  if ( !_InterlockedDecrement((volatile signed __int32 *)((v76.FileName.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__cdecl *)(Scaleform::MemoryHeap *, unsigned __int64, __int64, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
      Scaleform::Memory::pGlobalHeap,
      v66,
      v24,
      v63);
  if ( v76.pInput.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v76.pInput.pObject);
  return v65;
}bject )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v76.pInput.pObject);
  return v65;
}

// File Line: 1233
// RVA: 0x8BD910
void __fastcall Scaleform::GFx::ShapeDataBase::ComputeBound(Scaleform::GFx::ShapeDataBase *this, Scaleform::Render::Rect<float> *r)
{
  Scaleform::RefCountImplCoreVtbl *v2; // rax
  Scaleform::Render::Rect<float> *v3; // rdi
  Scaleform::GFx::ShapeDataBase *v4; // rbx
  Scaleform::RefCountImplCoreVtbl *v5; // rax
  float v6; // xmm1_4
  float v7; // xmm0_4
  float v8; // xmm1_4
  Scaleform::Render::Rect<float> bounds; // [rsp+30h] [rbp-39h]
  int v10; // [rsp+40h] [rbp-29h]
  int v11; // [rsp+44h] [rbp-25h]
  Scaleform::Render::ShapePosInfo pos; // [rsp+50h] [rbp-19h]
  float coord; // [rsp+88h] [rbp+1Fh]
  Scaleform::Render::Matrix2x4<float> trans; // [rsp+A0h] [rbp+37h]

  v2 = this->vfptr;
  v3 = r;
  v4 = this;
  *(_OWORD *)&trans.M[0][0] = _xmm;
  *(__m128 *)&trans.M[1][0] = _xmm;
  bounds = (Scaleform::Render::Rect<float>)_xmm_f149f2caf149f2ca7149f2ca7149f2ca;
  pos.Pos = ((__int64 (*)(void))v2[6].__vecDelDtor)();
  v5 = v4->vfptr;
  LODWORD(pos.Sfactor) = (_DWORD)FLOAT_1_0;
  *(_QWORD *)&pos.StartX = 0i64;
  *(_QWORD *)&pos.LastX = 0i64;
  *(_QWORD *)&pos.FillBase = 0i64;
  *(_QWORD *)&pos.NumFillBits = 0i64;
  *(_QWORD *)&pos.Fill0 = 0i64;
  pos.Stroke = 0;
  pos.Initialized = 0;
  if ( ((unsigned int (__fastcall *)(Scaleform::GFx::ShapeDataBase *, Scaleform::Render::ShapePosInfo *, float *, int *))v5[8].__vecDelDtor)(
         v4,
         &pos,
         &coord,
         &v10) )
  {
    do
    {
      if ( (v10 == 0) == (v11 == 0) )
        v4->vfptr[10].__vecDelDtor((Scaleform::RefCountImplCore *)&v4->vfptr, (unsigned int)&pos);
      else
        Scaleform::Render::ExpandBoundsToPath<Scaleform::Render::Matrix2x4<float>>(
          (Scaleform::Render::ShapeDataInterface *)&v4->vfptr,
          &trans,
          &pos,
          &coord,
          &bounds);
    }
    while ( ((unsigned int (__fastcall *)(Scaleform::GFx::ShapeDataBase *, Scaleform::Render::ShapePosInfo *, float *, int *))v4->vfptr[8].__vecDelDtor)(
              v4,
              &pos,
              &coord,
              &v10) );
  }
  v6 = bounds.y1;
  v3->x1 = bounds.x1;
  v7 = bounds.x2;
  v3->y1 = v6;
  v8 = bounds.y2;
  v3->x2 = v7;
  v3->y2 = v8;
}

// File Line: 1239
// RVA: 0x8C4E80
__int64 __fastcall Scaleform::GFx::ShapeDataBase::DefPointTestLocal(Scaleform::GFx::ShapeDataBase *this, Scaleform::Render::ShapeMeshProvider *pshapeMeshProvider, Scaleform::Render::Point<float> *pt, bool testShape, Scaleform::GFx::DisplayObjectBase *pinst)
{
  bool v5; // r14
  Scaleform::Render::Point<float> *v6; // rdi
  Scaleform::Render::ShapeMeshProvider *v7; // rsi
  Scaleform::GFx::ShapeDataBase *v8; // r15
  Scaleform::Render::Scale9GridInfo *v9; // rbx
  Scaleform::Render::Scale9GridInfo *v10; // rax
  Scaleform::Render::Rect<float> *v11; // rax
  float v12; // xmm3_4
  float v13; // xmm1_4
  float v14; // xmm4_4
  float v15; // xmm2_4
  float v16; // xmm0_4
  Scaleform::Render::TransformerBase *v17; // rdx
  unsigned __int8 v18; // di
  Scaleform::Render::Rect<float> bounds; // [rsp+30h] [rbp-40h]
  void **v21; // [rsp+40h] [rbp-30h]
  Scaleform::Render::Scale9GridInfo *v22; // [rsp+48h] [rbp-28h]
  Scaleform::Render::TransformerBase trans; // [rsp+50h] [rbp-20h]
  Scaleform::Render::Matrix2x4<float> *v24; // [rsp+58h] [rbp-18h]
  Scaleform::Render::Rect<float> result; // [rsp+60h] [rbp-10h]

  v5 = testShape;
  v6 = pt;
  v7 = pshapeMeshProvider;
  v8 = this;
  v9 = 0i64;
  if ( pinst && pinst->Flags & 1 )
  {
    Scaleform::GFx::DisplayObjectBase::CreateScale9Grid(pinst);
    v9 = v10;
  }
  v7->vfptr->GetIdentityBounds((Scaleform::Render::MeshProvider *)&v7->vfptr, &bounds);
  if ( v9 )
  {
    v11 = Scaleform::Render::Scale9GridInfo::AdjustBounds(v9, &result, &bounds);
    v12 = v11->y2;
    v13 = v11->x2;
    v14 = v11->y1;
    v15 = v11->x1;
    bounds.x1 = v11->x1;
    bounds.y1 = v14;
    bounds.x2 = v13;
    bounds.y2 = v12;
  }
  else
  {
    v12 = bounds.y2;
    v13 = bounds.x2;
    v14 = bounds.y1;
    v15 = bounds.x1;
  }
  if ( v6->x > v13 || v6->x < v15 || (v16 = v6->y, v16 > v12) || v16 < v14 )
  {
    v18 = 0;
  }
  else if ( v5 )
  {
    trans.vfptr = (Scaleform::Render::TransformerBaseVtbl *)&Scaleform::Render::TransformerWrapper<Scaleform::Render::Matrix2x4<float>>::`vftable;
    v24 = 0i64;
    v21 = &Scaleform::Render::TransformerWrapper<Scaleform::Render::Scale9GridInfo>::`vftable;
    v22 = 0i64;
    *(_QWORD *)&result.x1 = &Scaleform::Render::TransformerBase::`vftable;
    if ( v9 )
    {
      *(_QWORD *)&result.x1 = &Scaleform::Render::TransformerWrapper<Scaleform::Render::Scale9GridInfo>::`vftable;
      *(_QWORD *)&result.x2 = v9;
      v22 = v9;
      v17 = (Scaleform::Render::TransformerBase *)&v21;
    }
    else
    {
      *(_QWORD *)&result.x1 = &Scaleform::Render::TransformerWrapper<Scaleform::Render::Matrix2x4<float>>::`vftable;
      *(_QWORD *)&result.x2 = &Scaleform::Render::Matrix2x4<float>::Identity;
      v24 = &Scaleform::Render::Matrix2x4<float>::Identity;
      v17 = &trans;
    }
    *(_QWORD *)&result.x1 = &Scaleform::Render::TransformerBase::`vftable;
    v18 = Scaleform::Render::HitTestFill<Scaleform::Render::TransformerBase>(
            (Scaleform::Render::ShapeDataInterface *)&v8->vfptr,
            v17,
            v6->x,
            v6->y);
    v21 = &Scaleform::Render::TransformerBase::`vftable;
    trans.vfptr = (Scaleform::Render::TransformerBaseVtbl *)&Scaleform::Render::TransformerBase::`vftable;
  }
  else
  {
    v18 = 1;
  }
  if ( v9 )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v9);
  return v18;
}

// File Line: 1299
// RVA: 0x8FD1C0
__int64 __fastcall Scaleform::GFx::ShapeDataBase::ReadPathInfo(Scaleform::GFx::ShapeDataBase *this, Scaleform::Render::ShapePosInfo *pos, float *coord, unsigned int *styles)
{
  unsigned int *v4; // rdi
  float *v5; // rsi
  Scaleform::Render::ShapePosInfo *v6; // rbx
  float v7; // xmm3_4
  Scaleform::Render::ShapePathType v8; // er9
  char v9; // r10
  int v10; // er11
  Scaleform::GFx::SwfShapeDecoder v12; // [rsp+28h] [rbp-30h]

  v4 = styles;
  v5 = coord;
  v6 = pos;
  if ( this->Flags & 2 )
    v7 = FLOAT_0_050000001;
  else
    v7 = *(float *)&FLOAT_1_0;
  Scaleform::GFx::SwfShapeDecoder::SwfShapeDecoder(&v12, pos, this->Paths, v7);
  v8 = 1;
  while ( 1 )
  {
    v9 = v12.Stream.CurBitIndex;
    v10 = v12.Stream.CurByteIndex;
    if ( (unsigned __int8)(1 << (7 - LOBYTE(v12.Stream.CurBitIndex))) & v12.Stream.pData[v12.Stream.CurByteIndex] )
      break;
    v8 = (unsigned int)Scaleform::GFx::SwfShapeDecoder::ReadNonEdgeRec(&v12, v8);
    if ( v8 == Shape_EndShape )
    {
      v9 = v12.Stream.CurBitIndex;
      v10 = v12.Stream.CurByteIndex;
      goto LABEL_10;
    }
  }
  if ( v8 )
  {
    *v4 = v6->Fill0;
    v4[1] = v6->Fill1;
    v4[2] = v6->Stroke;
    *v5 = (float)v6->LastX * v6->Sfactor;
    v5[1] = (float)v6->LastY * v6->Sfactor;
  }
LABEL_10:
  v12.Pos->Pos = v9 & 7 | 8 * (v12.Pos->NumStrokeBits & 0xF | 16 * (16 * v10 | v12.Pos->NumFillBits & 0xF));
  return (unsigned int)v8;
}

// File Line: 1322
// RVA: 0x8FB3C0
__int64 __fastcall Scaleform::GFx::ShapeDataBase::ReadEdge(Scaleform::GFx::ShapeDataBase *this, Scaleform::Render::ShapePosInfo *pos, float *coord)
{
  float *v3; // rdi
  Scaleform::Render::ShapePosInfo *v4; // rbx
  float v5; // xmm3_4
  Scaleform::Render::PathEdgeType v6; // er9
  Scaleform::GFx::SwfShapeDecoder::Edge edge; // [rsp+28h] [rbp-50h]
  Scaleform::GFx::SwfShapeDecoder v9; // [rsp+40h] [rbp-38h]

  v3 = coord;
  v4 = pos;
  if ( this->Flags & 2 )
    v5 = FLOAT_0_050000001;
  else
    v5 = *(float *)&FLOAT_1_0;
  Scaleform::GFx::SwfShapeDecoder::SwfShapeDecoder(&v9, pos, this->Paths, v5);
  v6 = 0;
  if ( (unsigned __int8)(1 << (7 - LOBYTE(v9.Stream.CurBitIndex))) & v9.Stream.pData[v9.Stream.CurByteIndex] )
  {
    v6 = Scaleform::GFx::SwfShapeDecoder::ReadEdge(&v9, &edge);
    if ( v6 == 2 )
    {
      *v3 = (float)edge.Cx * v4->Sfactor;
      v3[1] = (float)edge.Cy * v4->Sfactor;
      v3[2] = (float)edge.Ax * v4->Sfactor;
      v3[3] = (float)edge.Ay * v4->Sfactor;
    }
    else
    {
      *v3 = (float)edge.Ax * v4->Sfactor;
      v3[1] = (float)edge.Ay * v4->Sfactor;
    }
  }
  v9.Pos->Pos = v9.Stream.CurBitIndex & 7 | 8
                                          * (v9.Pos->NumStrokeBits & 0xF | 16
                                                                         * (16 * LODWORD(v9.Stream.CurByteIndex) | v9.Pos->NumFillBits & 0xF));
  return (unsigned int)v6;
}

// File Line: 1348
// RVA: 0x8F6350
_BOOL8 __fastcall Scaleform::GFx::ConstShapeNoStyles::Read(Scaleform::GFx::ConstShapeNoStyles *this, Scaleform::GFx::LoadProcess *p, Scaleform::GFx::TagType tagType, unsigned int lenInBytes, bool withStyle)
{
  Scaleform::GFx::PathAllocator *v5; // r10
  bool v6; // bl
  Scaleform::GFx::ShapeSwfReader v8; // [rsp+40h] [rbp-40h]

  v5 = p->pLoadData.pObject->pPathAllocator;
  v8.Shape = (Scaleform::GFx::ShapeDataBase *)&this->vfptr;
  v8.pAllocator = v5;
  v8.FillStyles.Data.Data = 0i64;
  v8.FillStyles.Data.Size = 0i64;
  v8.FillStyles.Data.Policy.Capacity = 0i64;
  v8.StrokeStyles.Data.Data = 0i64;
  v8.StrokeStyles.Data.Size = 0i64;
  v8.StrokeStyles.Data.Policy.Capacity = 0i64;
  v6 = Scaleform::GFx::ShapeSwfReader::Read(&v8, p, tagType, lenInBytes, withStyle);
  Scaleform::ArrayDataBase<Scaleform::Render::StrokeStyleType,Scaleform::AllocatorGH<Scaleform::Render::StrokeStyleType,259>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::Render::StrokeStyleType,Scaleform::AllocatorGH<Scaleform::Render::StrokeStyleType,259>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayDataBase<Scaleform::Render::StrokeStyleType,Scaleform::AllocatorGH<Scaleform::Render::StrokeStyleType,259>,Scaleform::ArrayDefaultPolicy> *)&v8.StrokeStyles.Data.Data);
  Scaleform::ArrayDataBase<Scaleform::Render::FillStyleType,Scaleform::AllocatorGH<Scaleform::Render::FillStyleType,259>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::Render::FillStyleType,Scaleform::AllocatorGH<Scaleform::Render::FillStyleType,259>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayDataBase<Scaleform::Render::FillStyleType,Scaleform::AllocatorGH<Scaleform::Render::FillStyleType,259>,Scaleform::ArrayDefaultPolicy> *)&v8.FillStyles.Data.Data);
  return v6;
}

// File Line: 1354
// RVA: 0x8BCAD0
Scaleform::GFx::ShapeDataBase *__fastcall Scaleform::GFx::ConstShapeNoStyles::Clone(Scaleform::GFx::ConstShapeNoStyles *this)
{
  Scaleform::GFx::ConstShapeNoStyles *v1; // rbx
  Scaleform::GFx::ShapeDataBase *result; // rax
  int v3; // [rsp+48h] [rbp+10h]
  Scaleform::GFx::ShapeDataBase *v4; // [rsp+50h] [rbp+18h]

  v1 = this;
  v3 = 71;
  result = (Scaleform::GFx::ShapeDataBase *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::GFx::ConstShapeNoStyles *, signed __int64, int *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
                                              Scaleform::Memory::pGlobalHeap,
                                              this,
                                              32i64,
                                              &v3,
                                              -2i64);
  v4 = result;
  if ( !result )
    return 0i64;
  result->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  result->RefCount = 1;
  result->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  result->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,71>::`vftable;
  result->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::Render::ShapeDataInterface,71>::`vftable;
  result->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::ShapeDataInterface::`vftable;
  result->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::ShapeDataBase::`vftable;
  result->Paths = v1->Paths;
  result->Flags = v1->Flags;
  result->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::ConstShapeNoStyles::`vftable;
  return result;
}

// File Line: 1361
// RVA: 0x895200
void __fastcall Scaleform::GFx::ConstShapeWithStyles::ConstShapeWithStyles(Scaleform::GFx::ConstShapeWithStyles *this, Scaleform::GFx::ConstShapeWithStyles *o)
{
  Scaleform::GFx::ConstShapeWithStyles *v2; // rbx

  v2 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,71>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::Render::ShapeDataInterface,71>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::ShapeDataInterface::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::ShapeDataBase::`vftable;
  this->Paths = o->Paths;
  this->Flags = o->Flags;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::ConstShapeWithStyles::`vftable;
  this->Styles = 0i64;
  *(_QWORD *)&this->Bound.x1 = 0i64;
  *(_QWORD *)&this->Bound.x2 = 0i64;
  *(_QWORD *)&this->RectBound.x1 = 0i64;
  *(_QWORD *)&this->RectBound.x2 = 0i64;
  Scaleform::GFx::ConstShapeWithStyles::SetStyles(
    this,
    o->FillStylesNum,
    (Scaleform::Render::FillStyleType *)o->Styles,
    o->StrokeStylesNum,
    (Scaleform::Render::StrokeStyleType *)&o->Styles[16 * o->FillStylesNum]);
  *(_QWORD *)&v2->RectBound.x1 = 0i64;
  *(_QWORD *)&v2->RectBound.x2 = 0i64;
  *(_QWORD *)&v2->Bound.x1 = 0i64;
  *(_QWORD *)&v2->Bound.x2 = 0i64;
}

// File Line: 1369
// RVA: 0x8A37D0
void __fastcall Scaleform::GFx::ConstShapeWithStyles::~ConstShapeWithStyles(Scaleform::GFx::ConstShapeWithStyles *this)
{
  Scaleform::GFx::ConstShapeWithStyles *v1; // r14
  char *v2; // rbx
  unsigned int v3; // esi
  unsigned int v4; // edi
  Scaleform::Render::RenderBuffer *v5; // rcx
  Scaleform::Render::RenderBuffer *v6; // rcx
  Scaleform::Render::RenderBuffer *v7; // rcx

  v1 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::ConstShapeWithStyles::`vftable;
  v2 = this->Styles;
  v3 = 0;
  v4 = 0;
  if ( this->FillStylesNum )
  {
    do
    {
      v5 = (Scaleform::Render::RenderBuffer *)*((_QWORD *)v2 + 1);
      if ( v5 )
        Scaleform::RefCountImpl::Release(v5);
      ++v4;
      v2 += 16;
    }
    while ( v4 < v1->FillStylesNum );
  }
  if ( v1->StrokeStylesNum )
  {
    do
    {
      v6 = (Scaleform::Render::RenderBuffer *)*((_QWORD *)v2 + 4);
      if ( v6 )
        Scaleform::RefCountImpl::Release(v6);
      v7 = (Scaleform::Render::RenderBuffer *)*((_QWORD *)v2 + 3);
      if ( v7 )
        Scaleform::RefCountImpl::Release(v7);
      ++v3;
      v2 += 40;
    }
    while ( v3 < v1->StrokeStylesNum );
  }
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v1->Styles);
  Scaleform::RefCountImplCore::~RefCountImplCore((Scaleform::RefCountImplCore *)&v1->vfptr);
}

// File Line: 1384
// RVA: 0x8BCB80
void __fastcall Scaleform::GFx::ConstShapeWithStyles::Clone(Scaleform::GFx::ConstShapeWithStyles *this)
{
  Scaleform::GFx::ConstShapeWithStyles *v1; // rbx
  Scaleform::GFx::ConstShapeWithStyles *v2; // rax
  int v3; // [rsp+48h] [rbp+10h]
  Scaleform::GFx::ConstShapeWithStyles *v4; // [rsp+50h] [rbp+18h]

  v1 = this;
  v3 = 71;
  v2 = (Scaleform::GFx::ConstShapeWithStyles *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::GFx::ConstShapeWithStyles *, signed __int64, int *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
                                                 Scaleform::Memory::pGlobalHeap,
                                                 this,
                                                 80i64,
                                                 &v3,
                                                 -2i64);
  v4 = v2;
  if ( v2 )
    Scaleform::GFx::ConstShapeWithStyles::ConstShapeWithStyles(v2, v1);
}

// File Line: 1390
// RVA: 0x8D7CC0
void __fastcall Scaleform::GFx::ConstShapeWithStyles::GetFillStyle(Scaleform::GFx::ConstShapeWithStyles *this, unsigned int idx, Scaleform::Render::FillStyleType *p)
{
  Scaleform::Render::FillStyleType *v3; // rdi
  char *v4; // rbx
  Scaleform::GFx::Resource *v5; // rcx
  Scaleform::Render::RenderBuffer *v6; // rcx

  v3 = p;
  v4 = &this->Styles[16 * (idx - 1)];
  p->Color = *(_DWORD *)v4;
  v5 = (Scaleform::GFx::Resource *)*((_QWORD *)v4 + 1);
  if ( v5 )
    Scaleform::Render::RenderBuffer::AddRef(v5);
  v6 = (Scaleform::Render::RenderBuffer *)v3->pFill.pObject;
  if ( v6 )
    Scaleform::RefCountImpl::Release(v6);
  v3->pFill.pObject = (Scaleform::Render::ComplexFill *)*((_QWORD *)v4 + 1);
}

// File Line: 1397
// RVA: 0x8DE760
void __fastcall Scaleform::GFx::ConstShapeWithStyles::GetStrokeStyle(Scaleform::GFx::ConstShapeWithStyles *this, unsigned int idx, Scaleform::Render::StrokeStyleType *p)
{
  Scaleform::Render::StrokeStyleType::operator=(
    p,
    (Scaleform::Render::StrokeStyleType *)&this->Styles[40 * (idx - 1) + 16 * this->FillStylesNum]);
}

// File Line: 1403
// RVA: 0x8F6420
__int64 __fastcall Scaleform::GFx::ConstShapeWithStyles::Read(Scaleform::GFx::ConstShapeWithStyles *this, Scaleform::GFx::LoadProcess *p, Scaleform::GFx::TagType tagType, unsigned int lenInBytes, bool withStyle)
{
  Scaleform::GFx::LoadProcess *v5; // rbx
  Scaleform::GFx::ConstShapeWithStyles *v6; // r13
  Scaleform::GFx::PathAllocator *v7; // r10
  unsigned int v8; // er15
  unsigned __int8 v9; // si
  unsigned int v10; // er8
  unsigned int v11; // ecx
  __int64 v12; // rsi
  unsigned int i; // edi
  Scaleform::Render::FillStyleType *v14; // rbx
  Scaleform::GFx::Resource *v15; // rcx
  Scaleform::Render::StrokeStyleType *v16; // r14
  signed __int64 v17; // rbx
  Scaleform::GFx::Resource *v18; // rcx
  Scaleform::GFx::Resource *v19; // rcx
  unsigned __int64 v20; // rdi
  Scaleform::Render::FillStyleType *v21; // rdx
  Scaleform::Render::FillStyleType *v22; // rbx
  Scaleform::Render::RenderBuffer *v23; // rcx
  Scaleform::GFx::ShapeSwfReader v25; // [rsp+40h] [rbp-40h]

  v5 = p;
  v6 = this;
  v7 = p->pLoadData.pObject->pPathAllocator;
  v25.Shape = (Scaleform::GFx::ShapeDataBase *)&this->vfptr;
  v25.pAllocator = v7;
  v8 = 0;
  v25.FillStyles.Data.Data = 0i64;
  v25.FillStyles.Data.Size = 0i64;
  v25.FillStyles.Data.Policy.Capacity = 0i64;
  v25.StrokeStyles.Data.Data = 0i64;
  v25.StrokeStyles.Data.Size = 0i64;
  v25.StrokeStyles.Data.Policy.Capacity = 0i64;
  if ( Scaleform::GFx::ShapeSwfReader::Read(&v25, p, tagType, lenInBytes, withStyle) )
  {
    v10 = v25.FillStyles.Data.Size;
    v6->FillStylesNum = v25.FillStyles.Data.Size;
    v11 = v25.StrokeStyles.Data.Size;
    v6->StrokeStylesNum = v25.StrokeStyles.Data.Size;
    if ( v10 || v11 )
    {
      v12 = (__int64)v5->pLoadData.pObject->pHeap->vfptr->Alloc(
                       v5->pLoadData.pObject->pHeap,
                       16i64 * v10 + 40i64 * v11,
                       0i64);
      v6->Styles = (char *)v12;
      for ( i = 0; i < v6->FillStylesNum; ++i )
      {
        v14 = &v25.FillStyles.Data.Data[i];
        if ( v12 )
        {
          *(_DWORD *)v12 = v14->Color;
          v15 = (Scaleform::GFx::Resource *)v14->pFill.pObject;
          if ( v15 )
            Scaleform::Render::RenderBuffer::AddRef(v15);
          *(_QWORD *)(v12 + 8) = v14->pFill.pObject;
        }
        v12 += 16i64;
      }
      if ( v6->StrokeStylesNum )
      {
        do
        {
          v16 = v25.StrokeStyles.Data.Data;
          v17 = v12 + 40i64 * v8;
          if ( v17 )
          {
            *(float *)v17 = v25.StrokeStyles.Data.Data[v8].Width;
            *(float *)(v17 + 4) = v16[v8].Units;
            *(_DWORD *)(v17 + 8) = v16[v8].Flags;
            *(float *)(v17 + 12) = v16[v8].Miter;
            *(_DWORD *)(v17 + 16) = v16[v8].Color;
            v18 = (Scaleform::GFx::Resource *)v16[v8].pFill.pObject;
            if ( v18 )
              Scaleform::Render::RenderBuffer::AddRef(v18);
            *(_QWORD *)(v17 + 24) = v16[v8].pFill.pObject;
            v19 = (Scaleform::GFx::Resource *)v16[v8].pDashes.pObject;
            if ( v19 )
              Scaleform::Render::RenderBuffer::AddRef(v19);
            *(_QWORD *)(v17 + 32) = v16[v8].pDashes.pObject;
          }
          ++v8;
        }
        while ( v8 < v6->StrokeStylesNum );
      }
    }
    else
    {
      v6->Styles = 0i64;
    }
    v9 = 1;
  }
  else
  {
    v9 = 0;
  }
  Scaleform::ArrayDataBase<Scaleform::Render::StrokeStyleType,Scaleform::AllocatorGH<Scaleform::Render::StrokeStyleType,259>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::Render::StrokeStyleType,Scaleform::AllocatorGH<Scaleform::Render::StrokeStyleType,259>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayDataBase<Scaleform::Render::StrokeStyleType,Scaleform::AllocatorGH<Scaleform::Render::StrokeStyleType,259>,Scaleform::ArrayDefaultPolicy> *)&v25.StrokeStyles.Data.Data);
  v20 = v25.FillStyles.Data.Size;
  v21 = v25.FillStyles.Data.Data;
  v22 = &v25.FillStyles.Data.Data[v25.FillStyles.Data.Size - 1];
  if ( v25.FillStyles.Data.Size )
  {
    do
    {
      v23 = (Scaleform::Render::RenderBuffer *)v22->pFill.pObject;
      if ( v23 )
        Scaleform::RefCountImpl::Release(v23);
      --v22;
      --v20;
    }
    while ( v20 );
    v21 = v25.FillStyles.Data.Data;
  }
  if ( v21 )
    ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
  return v9;
}

// File Line: 1436
// RVA: 0x90C5B0
void __fastcall Scaleform::GFx::ConstShapeWithStyles::SetStyles(Scaleform::GFx::ConstShapeWithStyles *this, unsigned int fillStyleCount, Scaleform::Render::FillStyleType *fillStyles, unsigned int strokeStyleCount, Scaleform::Render::StrokeStyleType *strokeStyles)
{
  __int64 v5; // rbx
  Scaleform::Render::FillStyleType *v6; // r14
  __int64 v7; // rdi
  Scaleform::GFx::ConstShapeWithStyles *v8; // rbp
  char *v9; // rbx
  unsigned int v10; // esi
  Scaleform::GFx::Resource *v11; // rcx
  Scaleform::Render::ComplexFill *v12; // rax
  __int64 v13; // rax
  __int64 v14; // rdi
  Scaleform::Render::RenderBuffer *v15; // rcx
  unsigned __int64 v16; // r15
  signed __int64 v17; // rdi
  char *v18; // rsi
  Scaleform::GFx::Resource *v19; // rcx
  Scaleform::GFx::Resource *v20; // rcx
  Scaleform::Render::ComplexFill *v21; // rax
  __int64 v22; // rax
  __int64 v23; // r14
  Scaleform::Render::RenderBuffer *v24; // rcx
  char *v25; // [rsp+20h] [rbp-48h]
  signed __int64 v26; // [rsp+28h] [rbp-40h]
  int v27; // [rsp+78h] [rbp+10h]

  v26 = -2i64;
  v5 = strokeStyleCount;
  v6 = fillStyles;
  v7 = fillStyleCount;
  v8 = this;
  if ( this->Styles )
    ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
  v8->FillStylesNum = v7;
  v8->StrokeStylesNum = v5;
  if ( (_DWORD)v7 || (_DWORD)v5 )
  {
    v9 = (char *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                   Scaleform::Memory::pGlobalHeap,
                   v8,
                   16 * v7 + 40 * v5,
                   0i64);
    v8->Styles = v9;
    v25 = v9;
    v10 = 0;
    if ( v8->FillStylesNum )
    {
      do
      {
        if ( v9 )
        {
          *(_DWORD *)v9 = v6[v10].Color;
          v11 = (Scaleform::GFx::Resource *)v6[v10].pFill.pObject;
          if ( v11 )
            Scaleform::Render::RenderBuffer::AddRef(v11);
          *((_QWORD *)v9 + 1) = v6[v10].pFill.pObject;
        }
        if ( *((_QWORD *)v9 + 1) )
        {
          v27 = 71;
          v12 = (Scaleform::Render::ComplexFill *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::GFx::ConstShapeWithStyles *, signed __int64, int *, char *, signed __int64, char *))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
                                                    Scaleform::Memory::pGlobalHeap,
                                                    v8,
                                                    80i64,
                                                    &v27,
                                                    v25,
                                                    v26,
                                                    v9);
          if ( v12 )
          {
            Scaleform::Render::ComplexFill::ComplexFill(v12, *((Scaleform::Render::ComplexFill **)v9 + 1));
            v14 = v13;
          }
          else
          {
            v14 = 0i64;
          }
          v15 = (Scaleform::Render::RenderBuffer *)*((_QWORD *)v9 + 1);
          if ( v15 )
            Scaleform::RefCountImpl::Release(v15);
          *((_QWORD *)v9 + 1) = v14;
        }
        v9 += 16;
        v25 = v9;
        ++v10;
      }
      while ( v10 < v8->FillStylesNum );
    }
    v16 = 0i64;
    if ( v8->StrokeStylesNum )
    {
      v17 = (signed __int64)(v9 + 4);
      v18 = (char *)((char *)strokeStyles - v9);
      do
      {
        if ( v17 != 4 )
        {
          *(_DWORD *)(v17 - 4) = *(_DWORD *)&v18[v17 - 4];
          *(_DWORD *)v17 = *(_DWORD *)&v18[v17];
          *(_DWORD *)(v17 + 4) = *(_DWORD *)&v18[v17 + 4];
          *(_DWORD *)(v17 + 8) = *(_DWORD *)&v18[v17 + 8];
          *(_DWORD *)(v17 + 12) = *(_DWORD *)&v18[v17 + 12];
          v19 = *(Scaleform::GFx::Resource **)&v18[v17 + 20];
          if ( v19 )
            Scaleform::Render::RenderBuffer::AddRef(v19);
          *(_QWORD *)(v17 + 20) = *(_QWORD *)&v18[v17 + 20];
          v20 = *(Scaleform::GFx::Resource **)&v18[v17 + 28];
          if ( v20 )
            Scaleform::Render::RenderBuffer::AddRef(v20);
          *(_QWORD *)(v17 + 28) = *(_QWORD *)&v18[v17 + 28];
        }
        if ( *((_QWORD *)v9 + 3) )
        {
          v27 = 71;
          v21 = (Scaleform::Render::ComplexFill *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::GFx::ConstShapeWithStyles *, signed __int64, int *, signed __int64, signed __int64, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
                                                    Scaleform::Memory::pGlobalHeap,
                                                    v8,
                                                    80i64,
                                                    &v27,
                                                    v17 - 4,
                                                    v26,
                                                    v17 - 4);
          if ( v21 )
          {
            Scaleform::Render::ComplexFill::ComplexFill(v21, *((Scaleform::Render::ComplexFill **)v9 + 3));
            v23 = v22;
          }
          else
          {
            v23 = 0i64;
          }
          v24 = (Scaleform::Render::RenderBuffer *)*((_QWORD *)v9 + 3);
          if ( v24 )
            Scaleform::RefCountImpl::Release(v24);
          *((_QWORD *)v9 + 3) = v23;
        }
        ++v16;
        v17 += 40i64;
      }
      while ( v16 < v8->StrokeStylesNum );
    }
  }
  else
  {
    v8->Styles = 0i64;
  }
}

// File Line: 1471
// RVA: 0x8B8140
void __fastcall Scaleform::GFx::ConstShapeWithStyles::BindResourcesInStyles(Scaleform::GFx::ConstShapeWithStyles *this, Scaleform::GFx::ResourceBinding *resourceBinding)
{
  Scaleform::GFx::ResourceBinding *v2; // r13
  Scaleform::GFx::ConstShapeWithStyles *v3; // rbp
  char *v4; // r12
  Scaleform::GFx::Resource *v5; // rdi
  unsigned int v6; // er15
  signed __int64 v7; // r14
  __int64 v8; // rax
  unsigned int v9; // er8
  signed __int64 v10; // rsi
  Scaleform::GFx::Resource *v11; // rdi
  Scaleform::GFx::ResourceLibBase *v12; // rcx
  Scaleform::GFx::ResourceVtbl *v13; // rsi
  __int64 v14; // rbp
  __int64 v15; // rcx
  Scaleform::Render::RenderBuffer *v16; // rcx
  unsigned __int64 v17; // r15
  Scaleform::Render::RenderBuffer **v18; // rsi
  Scaleform::Render::RenderBuffer *v19; // rax
  unsigned int v20; // er8
  signed __int64 v21; // r14
  Scaleform::GFx::Resource *v22; // rdi
  Scaleform::GFx::ResourceLibBase *v23; // rcx
  Scaleform::GFx::ResourceVtbl *v24; // r14
  Scaleform::Render::RenderBuffer *v25; // rbp
  __int64 v26; // rcx
  Scaleform::GFx::Resource *v27; // rbx
  Scaleform::GFx::ResourceLibBase *v28; // rcx
  Scaleform::GFx::ResourceBindData pdata; // [rsp+28h] [rbp-40h]
  Scaleform::GFx::ConstShapeWithStyles *v30; // [rsp+70h] [rbp+8h]

  v30 = this;
  v2 = resourceBinding;
  v3 = this;
  v4 = this->Styles;
  v5 = 0i64;
  pdata.pResource.pObject = 0i64;
  pdata.pBinding = 0i64;
  v6 = 0;
  if ( this->FillStylesNum )
  {
    do
    {
      v7 = (signed __int64)&v4[16 * v6];
      v8 = *(_QWORD *)(v7 + 8);
      if ( v8 && *(_DWORD *)(v8 + 68) != -1 )
      {
        v9 = *(_DWORD *)(v8 + 68);
        if ( v2->Frozen && v9 < v2->ResourceCount )
        {
          v10 = (signed __int64)&v2->pResources[v9];
          if ( *(_QWORD *)v10 )
            _InterlockedExchangeAdd((volatile signed __int32 *)(*(_QWORD *)v10 + 8i64), 1u);
          if ( pdata.pResource.pObject && !_InterlockedDecrement(&pdata.pResource.pObject->RefCount.Value) )
          {
            v11 = pdata.pResource.pObject;
            v12 = pdata.pResource.pObject->pLib;
            if ( v12 )
            {
              v12->vfptr[1].__vecDelDtor(
                (Scaleform::RefCountImplCore *)&v12->vfptr,
                (unsigned int)pdata.pResource.pObject);
              v11->pLib = 0i64;
            }
            v11->vfptr->__vecDelDtor(v11, 1u);
          }
          v5 = *(Scaleform::GFx::Resource **)v10;
          pdata.pResource.pObject = *(Scaleform::GFx::Resource **)v10;
          pdata.pBinding = *(Scaleform::GFx::ResourceBinding **)(v10 + 8);
        }
        else
        {
          Scaleform::GFx::ResourceBinding::GetResourceData_Locked(v2, &pdata, v9);
          v5 = pdata.pResource.pObject;
        }
        if ( v5 && (v5->vfptr->GetResourceTypeCode(v5) & 0xFF00) == 256 )
        {
          v13 = v5[1].vfptr;
          v14 = *(_QWORD *)(v7 + 8);
          if ( v13 )
            (*((void (__fastcall **)(Scaleform::GFx::ResourceVtbl *))v13->__vecDelDtor + 1))(v5[1].vfptr);
          v15 = *(_QWORD *)(v14 + 16);
          if ( v15 )
            (*(void (__cdecl **)(__int64))(*(_QWORD *)v15 + 16i64))(v15);
          *(_QWORD *)(v14 + 16) = v13;
          *(_DWORD *)(*(_QWORD *)(v7 + 8) + 68i64) = -1;
          v3 = v30;
        }
        else
        {
          v16 = *(Scaleform::Render::RenderBuffer **)(v7 + 8);
          if ( v16 )
            Scaleform::RefCountImpl::Release(v16);
          *(_QWORD *)(v7 + 8) = 0i64;
          *(_DWORD *)v7 = -5776071;
        }
      }
      ++v6;
    }
    while ( v6 < v3->FillStylesNum );
  }
  v17 = 0i64;
  if ( v3->StrokeStylesNum )
  {
    v18 = (Scaleform::Render::RenderBuffer **)&v4[16 * v3->FillStylesNum + 24];
    do
    {
      v19 = *v18;
      if ( *v18 && *((_DWORD *)&v19[1].Type + 1) != -1 )
      {
        v20 = *((_DWORD *)&v19[1].Type + 1);
        if ( v2->Frozen && v20 < v2->ResourceCount )
        {
          v21 = (signed __int64)&v2->pResources[v20];
          if ( *(_QWORD *)v21 )
            _InterlockedExchangeAdd((volatile signed __int32 *)(*(_QWORD *)v21 + 8i64), 1u);
          if ( pdata.pResource.pObject && !_InterlockedDecrement(&pdata.pResource.pObject->RefCount.Value) )
          {
            v22 = pdata.pResource.pObject;
            v23 = pdata.pResource.pObject->pLib;
            if ( v23 )
            {
              v23->vfptr[1].__vecDelDtor(
                (Scaleform::RefCountImplCore *)&v23->vfptr,
                (unsigned int)pdata.pResource.pObject);
              v22->pLib = 0i64;
            }
            v22->vfptr->__vecDelDtor(v22, 1u);
          }
          v5 = *(Scaleform::GFx::Resource **)v21;
          pdata.pResource.pObject = *(Scaleform::GFx::Resource **)v21;
          pdata.pBinding = *(Scaleform::GFx::ResourceBinding **)(v21 + 8);
        }
        else
        {
          Scaleform::GFx::ResourceBinding::GetResourceData_Locked(v2, &pdata, v20);
          v5 = pdata.pResource.pObject;
        }
        if ( v5 && (v5->vfptr->GetResourceTypeCode(v5) & 0xFF00) == 256 )
        {
          v24 = v5[1].vfptr;
          v25 = *v18;
          if ( v24 )
            (*((void (__fastcall **)(Scaleform::GFx::ResourceVtbl *))v24->__vecDelDtor + 1))(v5[1].vfptr);
          v26 = *(_QWORD *)&v25->Type;
          if ( v26 )
            (*(void (__cdecl **)(__int64))(*(_QWORD *)v26 + 16i64))(v26);
          *(_QWORD *)&v25->Type = v24;
          *((_DWORD *)&(*v18)[1].Type + 1) = -1;
          v3 = v30;
        }
        else
        {
          if ( *v18 )
            Scaleform::RefCountImpl::Release(*v18);
          *v18 = 0i64;
          *((_DWORD *)v18 - 2) = -5776071;
        }
      }
      ++v17;
      v18 += 5;
    }
    while ( v17 < v3->StrokeStylesNum );
  }
  if ( v5 && !_InterlockedDecrement(&v5->RefCount.Value) )
  {
    v27 = pdata.pResource.pObject;
    v28 = pdata.pResource.pObject->pLib;
    if ( v28 )
    {
      v28->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v28->vfptr, (unsigned int)pdata.pResource.pObject);
      v27->pLib = 0i64;
    }
    v27->vfptr->__vecDelDtor(v27, 1u);
  }
}

// File Line: 1517
// RVA: 0x89DCB0
void __fastcall Scaleform::GFx::SwfShapeCharacterDef::SwfShapeCharacterDef(Scaleform::GFx::SwfShapeCharacterDef *this, Scaleform::GFx::ShapeDataBase *shp)
{
  Scaleform::GFx::ShapeDataBase *v2; // rsi
  Scaleform::GFx::SwfShapeCharacterDef *v3; // rbx
  volatile int v4; // et1
  __int64 v5; // rax
  Scaleform::Render::ShapeMeshProvider *v6; // rdi
  Scaleform::Render::ShapeMeshProvider *v7; // rax
  Scaleform::Render::ShapeMeshProvider *v8; // rax
  Scaleform::Render::ShapeMeshProvider *v9; // rcx
  int v10; // [rsp+58h] [rbp+10h]
  Scaleform::Render::ShapeMeshProvider *v11; // [rsp+60h] [rbp+18h]

  v2 = shp;
  v3 = this;
  this->vfptr = (Scaleform::GFx::ResourceVtbl *)&Scaleform::GFx::Resource::`vftable;
  v4 = this->RefCount.Value;
  v5 = (unsigned int)this->RefCount.Value;
  this->RefCount.Value = 1;
  v6 = 0i64;
  this->pLib = 0i64;
  this->vfptr = (Scaleform::GFx::ResourceVtbl *)&Scaleform::GFx::CharacterDef::`vftable;
  this->Id.Id = 0x40000;
  this->vfptr = (Scaleform::GFx::ResourceVtbl *)&Scaleform::GFx::ShapeBaseCharacterDef::`vftable;
  this->pShapeMeshProvider.pObject = 0i64;
  this->vfptr = (Scaleform::GFx::ResourceVtbl *)&Scaleform::GFx::SwfShapeCharacterDef::`vftable;
  if ( shp )
    Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)shp);
  v3->pShape.pObject = v2;
  v10 = 2;
  v7 = (Scaleform::Render::ShapeMeshProvider *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::GFx::SwfShapeCharacterDef *, signed __int64, int *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
                                                 Scaleform::Memory::pGlobalHeap,
                                                 v3,
                                                 144i64,
                                                 &v10,
                                                 -2i64);
  v11 = v7;
  if ( v7 )
  {
    Scaleform::Render::ShapeMeshProvider::ShapeMeshProvider(
      v7,
      (Scaleform::Render::ShapeDataInterface *)&v3->pShape.pObject->vfptr,
      0i64);
    v6 = v8;
  }
  v9 = v3->pShapeMeshProvider.pObject;
  if ( v9 )
    ((void (*)(void))v9->vfptr->Release)();
  v3->pShapeMeshProvider.pObject = v6;
}

// File Line: 1522
// RVA: 0x8D55B0
Scaleform::Render::Rect<float> *__fastcall Scaleform::GFx::SwfShapeCharacterDef::GetBoundsLocal(Scaleform::GFx::SwfShapeCharacterDef *this, Scaleform::Render::Rect<float> *result, float __formal)
{
  Scaleform::GFx::SwfShapeCharacterDef *v3; // rdi
  Scaleform::Render::Rect<float> *v4; // rbx
  int *v5; // rax
  float v6; // ecx
  float v8; // [rsp+20h] [rbp-28h]
  float v9; // [rsp+24h] [rbp-24h]
  float v10; // [rsp+28h] [rbp-20h]
  float v11; // [rsp+2Ch] [rbp-1Ch]
  float v12; // [rsp+30h] [rbp-18h]
  float v13; // [rsp+34h] [rbp-14h]
  float v14; // [rsp+38h] [rbp-10h]
  float v15; // [rsp+3Ch] [rbp-Ch]

  v3 = this;
  v4 = result;
  this->pShape.pObject->vfptr[11].__vecDelDtor((Scaleform::RefCountImplCore *)this->pShape.pObject, (unsigned int)&v8);
  if ( v8 >= v10 || v9 >= v11 )
  {
    v5 = (int *)v3->pShapeMeshProvider.pObject->vfptr->GetIdentityBounds(
                  (Scaleform::Render::MeshProvider *)&v3->pShapeMeshProvider.pObject->vfptr,
                  (Scaleform::Render::Rect<float> *)&v12);
  }
  else
  {
    v12 = v8;
    v13 = v9;
    v14 = v10;
    v5 = (int *)&v12;
    v15 = v11;
  }
  LODWORD(v4->x1) = *v5;
  LODWORD(v4->y1) = v5[1];
  v6 = *((float *)v5 + 2);
  LODWORD(v4->y2) = v5[3];
  v4->x2 = v6;
  return v4;
}

// File Line: 1529
// RVA: 0x8DD560
Scaleform::Render::Rect<float> *__fastcall Scaleform::GFx::SwfShapeCharacterDef::GetRectBoundsLocal(Scaleform::GFx::SwfShapeCharacterDef *this, Scaleform::Render::Rect<float> *result, float mr)
{
  Scaleform::GFx::SwfShapeCharacterDef *v3; // rdi
  Scaleform::Render::Rect<float> *v4; // rbx
  int *v5; // rax
  float v6; // ecx
  float v8; // [rsp+20h] [rbp-38h]
  float v9; // [rsp+24h] [rbp-34h]
  float v10; // [rsp+28h] [rbp-30h]
  float v11; // [rsp+2Ch] [rbp-2Ch]
  float v12; // [rsp+30h] [rbp-28h]
  float v13; // [rsp+34h] [rbp-24h]
  float v14; // [rsp+38h] [rbp-20h]
  float v15; // [rsp+3Ch] [rbp-1Ch]

  v3 = this;
  v4 = result;
  this->pShape.pObject->vfptr[13].__vecDelDtor((Scaleform::RefCountImplCore *)this->pShape.pObject, (unsigned int)&v8);
  if ( v8 >= v10 || v9 >= v11 )
  {
    v5 = (int *)((__int64 (__fastcall *)(Scaleform::GFx::SwfShapeCharacterDef *, float *))v3->vfptr[1].GetResourceReport)(
                  v3,
                  &v12);
  }
  else
  {
    v12 = v8;
    v13 = v9;
    v14 = v10;
    v5 = (int *)&v12;
    v15 = v11;
  }
  LODWORD(v4->x1) = *v5;
  LODWORD(v4->y1) = v5[1];
  v6 = *((float *)v5 + 2);
  LODWORD(v4->y2) = v5[3];
  v4->x2 = v6;
  return v4;
}

// File Line: 1535
// RVA: 0x8B84D0
Scaleform::Ptr<Scaleform::Render::ShapeMeshProvider> *__fastcall Scaleform::GFx::SwfShapeCharacterDef::BindResourcesInStyles(Scaleform::GFx::SwfShapeCharacterDef *this, Scaleform::Ptr<Scaleform::Render::ShapeMeshProvider> *result, Scaleform::GFx::ResourceBinding *resourceBinding)
{
  Scaleform::GFx::ResourceBinding *v3; // rbx
  Scaleform::Ptr<Scaleform::Render::ShapeMeshProvider> *v4; // r14
  Scaleform::GFx::SwfShapeCharacterDef *v5; // rdi
  Scaleform::Render::ShapeMeshProvider *v6; // rbp
  Scaleform::Render::ShapeDataInterface *v7; // rsi
  Scaleform::Render::ShapeMeshProvider *v8; // rax
  Scaleform::Render::ShapeMeshProvider *v9; // rax
  int v11; // [rsp+88h] [rbp+20h]

  v3 = resourceBinding;
  v4 = result;
  v5 = this;
  v6 = 0i64;
  v7 = (Scaleform::Render::ShapeDataInterface *)((__int64 (__cdecl *)(Scaleform::GFx::ShapeDataBase *, Scaleform::Ptr<Scaleform::Render::ShapeMeshProvider> *))this->pShape.pObject->vfptr[16].__vecDelDtor)(
                                                  this->pShape.pObject,
                                                  result);
  v7->vfptr[17].__vecDelDtor((Scaleform::RefCountImplCore *)&v7->vfptr, (unsigned int)v3);
  v11 = 2;
  v8 = (Scaleform::Render::ShapeMeshProvider *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                                                 Scaleform::Memory::pGlobalHeap,
                                                 v5,
                                                 144ui64,
                                                 (Scaleform::AllocInfo *)&v11);
  if ( v8 )
  {
    Scaleform::Render::ShapeMeshProvider::ShapeMeshProvider(v8, v7, 0i64);
    v6 = v9;
  }
  v4->pObject = v6;
  Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v7);
  return v4;
}

// File Line: 1544
// RVA: 0x897860
void __fastcall Scaleform::GFx::ImageShapeCharacterDef::ImageShapeCharacterDef(Scaleform::GFx::ImageShapeCharacterDef *this, Scaleform::GFx::ImageResource *pimage, Scaleform::GFx::ImageCreator *imgCreator, bool bilinear)
{
  Scaleform::GFx::ImageCreator *v4; // r13
  Scaleform::GFx::ImageResource *v5; // rdi
  Scaleform::GFx::ImageShapeCharacterDef *v6; // r12
  volatile int v7; // et1
  __int64 v8; // rax
  Scaleform::Render::ShapeMeshProvider *v9; // r14
  Scaleform::Render::ShapeDataFloat *v10; // rax
  Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *v11; // rax
  Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *v12; // r15
  char *v13; // rsi
  __int64 v14; // rbx
  Scaleform::MemoryHeap *v15; // rax
  __int64 v16; // rcx
  signed __int64 v17; // rcx
  signed __int64 v18; // rdi
  bool v19; // zf
  __int64 v20; // rdi
  float v21; // xmm1_4
  Scaleform::Render::ShapeMeshProvider *v22; // rax
  __int64 v23; // rax
  __int64 v24; // rdi
  Scaleform::Render::RenderBuffer *v25; // rcx
  Scaleform::Render::ShapeMeshProvider *v26; // rax
  Scaleform::Render::ShapeMeshProvider *v27; // rax
  Scaleform::Render::ShapeMeshProvider *v28; // rcx
  Scaleform::Render::Rect<float> pr; // [rsp+20h] [rbp-A8h]
  Scaleform::LogMessageId v30; // [rsp+30h] [rbp-98h]
  int v31; // [rsp+34h] [rbp-94h]
  int v32; // [rsp+38h] [rbp-90h]
  Scaleform::LogMessageId id; // [rsp+3Ch] [rbp-8Ch]
  Scaleform::LogMessageId v34; // [rsp+40h] [rbp-88h]
  char *v35; // [rsp+48h] [rbp-80h]
  Scaleform::Render::ShapeDataFloat *v36; // [rsp+50h] [rbp-78h]
  char *v37; // [rsp+58h] [rbp-70h]
  int v38; // [rsp+60h] [rbp-68h]
  int v39; // [rsp+64h] [rbp-64h]
  Scaleform::MemoryHeap *v40; // [rsp+68h] [rbp-60h]
  Scaleform::Render::Rect<float> r; // [rsp+70h] [rbp-58h]
  __int64 v42; // [rsp+80h] [rbp-48h]
  __int64 v43; // [rsp+88h] [rbp-40h]
  __int64 v44; // [rsp+90h] [rbp-38h]
  Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *v45; // [rsp+98h] [rbp-30h]
  Scaleform::Render::Matrix2x4<float> v46; // [rsp+A8h] [rbp-20h]
  __int64 v47; // [rsp+C8h] [rbp+0h]
  __int64 v48; // [rsp+D0h] [rbp+8h]
  __int64 v49; // [rsp+130h] [rbp+68h]
  char v50; // [rsp+140h] [rbp+78h]

  v48 = -2i64;
  v4 = imgCreator;
  v5 = pimage;
  v6 = this;
  this->vfptr = (Scaleform::GFx::ResourceVtbl *)&Scaleform::GFx::Resource::`vftable;
  v7 = this->RefCount.Value;
  v8 = (unsigned int)this->RefCount.Value;
  this->RefCount.Value = 1;
  v9 = 0i64;
  this->pLib = 0i64;
  this->vfptr = (Scaleform::GFx::ResourceVtbl *)&Scaleform::GFx::CharacterDef::`vftable;
  this->Id.Id = 0x40000;
  this->vfptr = (Scaleform::GFx::ResourceVtbl *)&Scaleform::GFx::ShapeBaseCharacterDef::`vftable;
  this->pShapeMeshProvider.pObject = 0i64;
  this->vfptr = (Scaleform::GFx::ResourceVtbl *)&Scaleform::GFx::ImageShapeCharacterDef::`vftable;
  this->pShape.pObject = 0i64;
  LODWORD(v49) = 71;
  v10 = (Scaleform::Render::ShapeDataFloat *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                                               Scaleform::Memory::pGlobalHeap,
                                               this,
                                               128ui64,
                                               (Scaleform::AllocInfo *)&v49);
  v36 = v10;
  if ( v10 )
  {
    Scaleform::Render::ShapeDataFloat::ShapeDataFloat(v10);
    v12 = v11;
  }
  else
  {
    v12 = 0i64;
  }
  v45 = v12;
  v37 = 0i64;
  LODWORD(v36) = 71;
  v13 = (char *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                  Scaleform::Memory::pGlobalHeap,
                  v6,
                  80ui64,
                  (Scaleform::AllocInfo *)&v36);
  v35 = v13;
  if ( v13 )
  {
    *(_QWORD *)v13 = &Scaleform::RefCountImplCore::`vftable;
    *((_DWORD *)v13 + 2) = 1;
    *(_QWORD *)v13 = &Scaleform::RefCountImpl::`vftable;
    *(_QWORD *)v13 = &Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,71>::`vftable;
    *(_QWORD *)v13 = &Scaleform::RefCountBase<Scaleform::Render::ComplexFill,71>::`vftable;
    *(_QWORD *)v13 = &Scaleform::Render::ComplexFill::`vftable;
    *((_QWORD *)v13 + 2) = 0i64;
    *((_QWORD *)v13 + 3) = 0i64;
    *((_QWORD *)v13 + 4) = 1065353216i64;
    *((_QWORD *)v13 + 5) = 0i64;
    *((_DWORD *)v13 + 12) = 0;
    *(_QWORD *)(v13 + 52) = 1065353216i64;
    *((_DWORD *)v13 + 15) = 0;
    v13[64] = 0;
    *((_DWORD *)v13 + 17) = -1;
  }
  else
  {
    v13 = 0i64;
  }
  v37 = v13;
  if ( !v5 )
  {
    v34.Id = 135168;
    Scaleform::LogDebugMessage((Scaleform::LogMessageId)&v34, "Image is null in ImageShapeCharacterDef ctor.");
    goto LABEL_41;
  }
  v14 = 0i64;
  v35 = 0i64;
  if ( ((unsigned int (*)(void))v5->pImage->vfptr[3].__vecDelDtor)() )
  {
    v14 = (__int64)v5->pImage;
    if ( v14 )
      (*(void (__fastcall **)(Scaleform::Render::ImageBase *))(*(_QWORD *)v14 + 8i64))(v5->pImage);
    v35 = (char *)v14;
  }
  else if ( v4 )
  {
    v15 = Scaleform::Memory::pGlobalHeap->vfptr->GetAllocHeap(Scaleform::Memory::pGlobalHeap, v6);
    v38 = 3;
    v40 = v15;
    LODWORD(r.x1) = 1;
    LODWORD(r.y1) = 1;
    *(_QWORD *)&r.x2 = 0i64;
    v42 = 0i64;
    v43 = 0i64;
    v44 = 0i64;
    v14 = ((__int64 (__fastcall *)(Scaleform::GFx::ImageCreator *, int *, Scaleform::Render::ImageBase *))v4->vfptr[4].__vecDelDtor)(
            v4,
            &v38,
            v5->pImage);
    v35 = (char *)v14;
  }
  else
  {
    id.Id = 135168;
    Scaleform::LogDebugMessage((Scaleform::LogMessageId)&id, "ImageCreator is null in ImageShapeCharacterDef ctor");
  }
  if ( v14 )
    (*(void (__fastcall **)(__int64))(*(_QWORD *)v14 + 8i64))(v14);
  v16 = *((_QWORD *)v13 + 2);
  if ( v16 )
    (*(void (**)(void))(*(_QWORD *)v16 + 16i64))();
  *((_QWORD *)v13 + 2) = v14;
  if ( v14 )
  {
    *((_QWORD *)v13 + 4) = 1028443341i64;
    *((_QWORD *)v13 + 5) = 0i64;
    *((_DWORD *)v13 + 12) = 0;
    *(_QWORD *)(v13 + 52) = 1028443341i64;
    *((_DWORD *)v13 + 15) = 0;
    v13[64] = 1;
    if ( v50 )
      v13[64] = 3;
    (*(void (__fastcall **)(__int64, char **))(*(_QWORD *)v14 + 48i64))(v14, &v37);
    *(_OWORD *)&v46.M[0][0] = _xmm;
    *(__m128 *)&v46.M[1][0] = _xmm;
    (*(void (__fastcall **)(__int64, Scaleform::Render::Matrix2x4<float> *))(*(_QWORD *)v14 + 112i64))(v14, &v46);
    pr = 0i64;
    r.x1 = (float)(signed int)v37;
    r.y1 = (float)SHIDWORD(v37);
    r.x2 = (float)v38;
    r.y2 = (float)v39;
    Scaleform::Render::Matrix2x4<float>::EncloseTransform(&v46, &pr, &r);
    Scaleform::ArrayDataBase<Scaleform::Render::FillStyleType,Scaleform::AllocatorLH<Scaleform::Render::FillStyleType,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      (Scaleform::ArrayDataBase<Scaleform::Render::FillStyleType,Scaleform::AllocatorLH<Scaleform::Render::FillStyleType,2>,Scaleform::ArrayDefaultPolicy> *)&v12->Fills.Data.Data,
      &v12->Fills,
      v12->Fills.Data.Size + 1);
    v17 = 16 * v12->Fills.Data.Size;
    v18 = (signed __int64)&v12->Fills.Data.Data[-1];
    v19 = v17 + v18 == 0;
    v20 = v17 + v18;
    v49 = v20;
    v35 = (char *)v20;
    if ( !v19 )
    {
      *(_DWORD *)v20 = (_DWORD)v36;
      Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)v13);
      *(_QWORD *)(v20 + 8) = v13;
    }
    Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::StartPath(
      v12,
      1u,
      0,
      0);
    Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::MoveTo(
      v12,
      0.0,
      0.0);
    Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::LineTo(
      v12,
      (float)(pr.x2 - pr.x1) * 20.0,
      0.0);
    Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::LineTo(
      v12,
      (float)(pr.x2 - pr.x1) * 20.0,
      (float)(pr.y2 - pr.y1) * 20.0);
    Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::LineTo(
      v12,
      0.0,
      (float)(pr.y2 - pr.y1) * 20.0);
    v21 = v12->StartX;
    if ( v21 != v12->LastX || v12->StartY != v12->LastY )
      Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::LineTo(
        v12,
        v21,
        v12->StartY);
    Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::EndPath(v12);
    Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::EndShape(v12);
    v31 = 2;
    v22 = (Scaleform::Render::ShapeMeshProvider *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                                                    Scaleform::Memory::pGlobalHeap,
                                                    v6,
                                                    144ui64,
                                                    (Scaleform::AllocInfo *)&v31);
    v49 = (__int64)v22;
    if ( v22 )
    {
      Scaleform::Render::ShapeMeshProvider::ShapeMeshProvider(
        v22,
        (Scaleform::Render::ShapeDataInterface *)&v12->vfptr,
        0i64);
      v24 = v23;
    }
    else
    {
      v24 = 0i64;
    }
    v47 = v24;
    Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)v12);
    v25 = (Scaleform::Render::RenderBuffer *)v6->pShape.pObject;
    if ( v25 )
      Scaleform::RefCountImpl::Release(v25);
    v6->pShape.pObject = (Scaleform::Render::ShapeDataInterface *)&v12->vfptr;
    v32 = 2;
    v26 = (Scaleform::Render::ShapeMeshProvider *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                                                    Scaleform::Memory::pGlobalHeap,
                                                    v6,
                                                    144ui64,
                                                    (Scaleform::AllocInfo *)&v32);
    v49 = (__int64)v26;
    if ( v26 )
    {
      Scaleform::Render::ShapeMeshProvider::ShapeMeshProvider(v26, v6->pShape.pObject, 0i64);
      v9 = v27;
    }
    v28 = v6->pShapeMeshProvider.pObject;
    if ( v28 )
      ((void (*)(void))v28->vfptr->Release)();
    v6->pShapeMeshProvider.pObject = v9;
    if ( v24 )
      (*(void (**)(void))(*(_QWORD *)(v24 + 16) + 16i64))();
    (*(void (__fastcall **)(__int64))(*(_QWORD *)v14 + 16i64))(v14);
LABEL_41:
    if ( !v13 )
      goto LABEL_43;
    goto LABEL_42;
  }
  v30.Id = 135168;
  Scaleform::LogDebugMessage((Scaleform::LogMessageId)&v30, "Image is not created.");
LABEL_42:
  Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v13);
LABEL_43:
  if ( v12 )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v12);
}

// File Line: 1603
// RVA: 0x8C4DE0
char __fastcall Scaleform::GFx::ImageShapeCharacterDef::DefPointTestLocal(Scaleform::GFx::ImageShapeCharacterDef *this, Scaleform::Render::Point<float> *pt, __int64 testShape, Scaleform::GFx::DisplayObjectBase *pinst)
{
  Scaleform::GFx::ImageShapeCharacterDef *v4; // rsi
  Scaleform::Render::Point<float> *v5; // rbx
  char v6; // di
  float v7; // xmm2_4
  float v8; // xmm3_4
  float v10; // [rsp+20h] [rbp-18h]
  float v11; // [rsp+24h] [rbp-14h]
  float v12; // [rsp+28h] [rbp-10h]
  float v13; // [rsp+2Ch] [rbp-Ch]

  v4 = this;
  v5 = pt;
  v6 = testShape;
  ((void (__fastcall *)(Scaleform::Render::MeshProviderVtbl **, float *, __int64, Scaleform::GFx::DisplayObjectBase *))this->pShapeMeshProvider.pObject->vfptr->GetIdentityBounds)(
    &this->pShapeMeshProvider.pObject->vfptr,
    &v10,
    testShape,
    pinst);
  v7 = v5->x;
  if ( v5->x > v12 )
    return 0;
  if ( v7 < v10 )
    return 0;
  v8 = v5->y;
  if ( v8 > v13 || v8 < v11 )
    return 0;
  if ( v6 )
    return Scaleform::Render::HitTestFill<Scaleform::Render::Matrix2x4<float>>(
             v4->pShape.pObject,
             &Scaleform::Render::Matrix2x4<float>::Identity,
             v7,
             v8);
  return 1;
}

