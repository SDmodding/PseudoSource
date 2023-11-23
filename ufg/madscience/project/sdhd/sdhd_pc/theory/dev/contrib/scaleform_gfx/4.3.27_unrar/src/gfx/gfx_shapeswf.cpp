// File Line: 67
// RVA: 0x8F6730
void __fastcall Scaleform::GFx::FillStyleSwfReader::Read(
        Scaleform::GFx::FillStyleSwfReader *this,
        Scaleform::GFx::LoadProcess *p,
        int tagType)
{
  Scaleform::GFx::SWFProcessInfo *pAltStream; // rbx
  __int64 Pos; // rcx
  int Blue; // r12d
  Scaleform::GFx::SWFProcessInfo *v9; // rcx
  Scaleform::GFx::SWFProcessInfo *p_ProcessInfo; // rbx
  __int64 v11; // r8
  char v12; // dl
  Scaleform::Render::FillStyleType *FillStyle; // rbx
  Scaleform::Render::RenderBuffer *pObject; // rcx
  Scaleform::GFx::SWFProcessInfo *v15; // rcx
  float v16; // xmm8_4
  float v17; // xmm12_4
  float v18; // xmm10_4
  float v19; // xmm13_4
  float v20; // xmm11_4
  float v21; // xmm9_4
  float v22; // xmm8_4
  Scaleform::GFx::SWFProcessInfo *v23; // rbx
  __int64 v24; // rdx
  char v25; // cl
  bool v26; // r13
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
  int v39; // r13d
  Scaleform::GFx::SWFProcessInfo *v40; // rbx
  __int64 v41; // rcx
  char v42; // r15
  Scaleform::GFx::SWFProcessInfo *v43; // rcx
  Scaleform::GFx::SWFProcessInfo *v44; // rbx
  __int64 v45; // rdx
  char v46; // cl
  Scaleform::GFx::SWFProcessInfo *v47; // rbx
  __int64 v48; // r9
  __int16 v49; // r8
  Scaleform::Render::ComplexFill *v50; // rcx
  unsigned int U16; // ebx
  Scaleform::GFx::SWFProcessInfo *v52; // rcx
  Scaleform::Render::ComplexFill *v53; // rax
  Scaleform::Render::ComplexFill *v54; // rax
  Scaleform::Render::ComplexFill *v55; // r13
  Scaleform::Render::FillStyleType *v56; // r15
  Scaleform::Render::RenderBuffer *v57; // rcx
  Scaleform::Render::ComplexFill *v58; // rcx
  char ResourceHandle; // al
  Scaleform::GFx::Resource *pResource; // rsi
  Scaleform::GFx::ResourceHandle::HandleType HType; // r15d
  Scaleform::Render::Image *vfptr; // rbx
  Scaleform::Render::ComplexFill *v63; // rdi
  Scaleform::Render::Image *v64; // rcx
  Scaleform::GFx::TempBindData *pTempBindData; // rcx
  Scaleform::Render::FillStyleType *v66; // rdi
  Scaleform::Render::RenderBuffer *v67; // rcx
  Scaleform::GFx::Resource *v68; // rbx
  Scaleform::GFx::ResourceLibBase *pLib; // rcx
  Scaleform::GFx::ResourceId rid; // [rsp+20h] [rbp-A8h] BYREF
  Scaleform::LogMessageId id[2]; // [rsp+28h] [rbp-A0h] BYREF
  Scaleform::GFx::ResourceHandle phandle; // [rsp+30h] [rbp-98h] BYREF
  _BYTE v73[48]; // [rsp+40h] [rbp-88h] BYREF
  _OWORD m[13]; // [rsp+70h] [rbp-58h] BYREF
  Scaleform::Render::Color pc[2]; // [rsp+150h] [rbp+88h] BYREF
  int v76; // [rsp+158h] [rbp+90h]
  Scaleform::Render::Color v77; // [rsp+160h] [rbp+98h] BYREF

  *(_QWORD *)&v73[40] = -2i64;
  pAltStream = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  if ( !pAltStream )
    pAltStream = &p->ProcessInfo;
  pAltStream->Stream.UnusedBits = 0;
  if ( (signed int)(pAltStream->Stream.DataSize - pAltStream->Stream.Pos) < 1 )
    Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 1);
  Pos = pAltStream->Stream.Pos;
  pc[0].Channels.Blue = pAltStream->Stream.pBuffer[Pos];
  Blue = (unsigned __int8)pc[0].Channels.Blue;
  pAltStream->Stream.Pos = Pos + 1;
  Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
    (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>,
    "  FillStyle read type = 0x%X\n");
  if ( !(_BYTE)Blue )
  {
    if ( tagType > 22 )
    {
      p_ProcessInfo = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
      if ( !p_ProcessInfo )
        p_ProcessInfo = &p->ProcessInfo;
      Scaleform::GFx::Stream::ReadRgb(&p_ProcessInfo->Stream, pc);
      p_ProcessInfo->Stream.UnusedBits = 0;
      if ( (signed int)(p_ProcessInfo->Stream.DataSize - p_ProcessInfo->Stream.Pos) < 1 )
        Scaleform::GFx::Stream::PopulateBuffer(&p_ProcessInfo->Stream, 1);
      v11 = p_ProcessInfo->Stream.Pos;
      v12 = p_ProcessInfo->Stream.pBuffer[v11];
      p_ProcessInfo->Stream.Pos = v11 + 1;
      pc[0].Channels.Alpha = v12;
    }
    else
    {
      v9 = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
      if ( !v9 )
        v9 = &p->ProcessInfo;
      Scaleform::GFx::Stream::ReadRgb(&v9->Stream, pc);
    }
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
      (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>,
      "  color: ");
    this->FillStyle->Color = (unsigned int)pc[0];
    FillStyle = this->FillStyle;
    pObject = (Scaleform::Render::RenderBuffer *)this->FillStyle->pFill.pObject;
    if ( pObject )
      Scaleform::RefCountImpl::Release(pObject);
    FillStyle->pFill.pObject = 0i64;
    return;
  }
  if ( (Blue & 0x10) != 0 )
  {
    *(_OWORD *)&v73[8] = _xmm;
    *(__m128 *)&v73[24] = _xmm;
    v15 = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
    if ( !v15 )
      v15 = &p->ProcessInfo;
    Scaleform::GFx::Stream::ReadMatrix(&v15->Stream, (Scaleform::Render::Matrix2x4<float> *)&v73[8]);
    if ( (_BYTE)Blue == 16 )
      v16 = 0.0;
    else
      v16 = FLOAT_0_5;
    *(_OWORD *)&v73[32] = _xmm;
    m[0] = _xmm;
    Scaleform::Render::Matrix2x4<float>::SetInverse(
      (Scaleform::Render::Matrix2x4<float> *)&v73[32],
      (Scaleform::Render::Matrix2x4<float> *)&v73[8]);
    v17 = (float)(*(float *)m * 0.0) + (float)(*(float *)&v73[32] * 0.000030517578);
    v18 = (float)(*(float *)m * 0.000030517578) + (float)(*(float *)&v73[32] * 0.0);
    v19 = (float)(*((float *)m + 1) * 0.0) + (float)(*(float *)&v73[36] * 0.000030517578);
    v20 = (float)(*((float *)m + 1) * 0.000030517578) + (float)(*(float *)&v73[36] * 0.0);
    v21 = (float)((float)(*((float *)m + 3) * 0.0) + (float)(*(float *)&v73[44] * 0.000030517578)) + 0.5;
    v22 = v16 + (float)((float)(*((float *)m + 3) * 0.000030517578) + (float)(*(float *)&v73[44] * 0.0));
    v23 = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
    if ( !v23 )
      v23 = &p->ProcessInfo;
    v23->Stream.UnusedBits = 0;
    if ( (signed int)(v23->Stream.DataSize - v23->Stream.Pos) < 1 )
      Scaleform::GFx::Stream::PopulateBuffer(&v23->Stream, 1);
    v24 = v23->Stream.Pos;
    v25 = v23->Stream.pBuffer[v24];
    v23->Stream.Pos = v24 + 1;
    v26 = (v25 & 0x10) != 0;
    *(_WORD *)&v77.Channels.Blue = v25 & 0xF;
    rid.Id = v25 & 0xF;
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
      (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>,
      "  gradients: numGradients = %d\n");
    v27 = (Scaleform::Render::ComplexFill *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
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
    v30 = this->FillStyle;
    v31 = (Scaleform::Render::RenderBuffer *)this->FillStyle->pFill.pObject;
    if ( v31 )
      Scaleform::RefCountImpl::Release(v31);
    v30->pFill.pObject = v29;
    if ( Blue != 16 )
    {
      if ( Blue == 18 )
      {
        v32 = GradientRadial;
        goto LABEL_39;
      }
      if ( Blue == 19 )
      {
        v32 = GradientFocalPoint;
LABEL_39:
        v33 = (Scaleform::Render::GradientData *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                                   Scaleform::Memory::pGlobalHeap,
                                                   48i64);
        *(_QWORD *)&id[0].Id = v33;
        if ( v33 )
        {
          Scaleform::Render::GradientData::GradientData(v33, v32, v77.Raw, v26);
          v35 = v34;
        }
        else
        {
          v35 = 0i64;
        }
        v36 = this->FillStyle->pFill.pObject;
        v37 = (Scaleform::Render::RenderBuffer *)v36->pGradient.pObject;
        if ( v37 )
          Scaleform::RefCountImpl::Release(v37);
        v36->pGradient.pObject = v35;
        v38 = 0i64;
        if ( (int)rid.Id > 0 )
        {
          v39 = v76;
          do
          {
            v40 = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
            if ( !v40 )
              v40 = &p->ProcessInfo;
            v40->Stream.UnusedBits = 0;
            if ( (signed int)(v40->Stream.DataSize - v40->Stream.Pos) < 1 )
              Scaleform::GFx::Stream::PopulateBuffer(&v40->Stream, 1);
            v41 = v40->Stream.Pos;
            v42 = v40->Stream.pBuffer[v41];
            v40->Stream.Pos = v41 + 1;
            if ( v39 > 22 )
            {
              v44 = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
              if ( !v44 )
                v44 = &p->ProcessInfo;
              Scaleform::GFx::Stream::ReadRgb(&v44->Stream, &v77);
              v44->Stream.UnusedBits = 0;
              if ( (signed int)(v44->Stream.DataSize - v44->Stream.Pos) < 1 )
                Scaleform::GFx::Stream::PopulateBuffer(&v44->Stream, 1);
              v45 = v44->Stream.Pos;
              v46 = v44->Stream.pBuffer[v45];
              v44->Stream.Pos = v45 + 1;
              v77.Channels.Alpha = v46;
            }
            else
            {
              v43 = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
              if ( !v43 )
                v43 = &p->ProcessInfo;
              Scaleform::GFx::Stream::ReadRgb(&v43->Stream, &v77);
            }
            this->FillStyle->pFill.pObject->pGradient.pObject->pRecords[v38].ColorV = v77;
            this->FillStyle->pFill.pObject->pGradient.pObject->pRecords[v38].Ratio = v42;
            v38 = (unsigned int)(v38 + 1);
          }
          while ( (int)v38 < (int)rid.Id );
          LOBYTE(Blue) = pc[0].Channels.Blue;
        }
        if ( (_BYTE)Blue == 19 )
        {
          v47 = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
          if ( !v47 )
            v47 = &p->ProcessInfo;
          v47->Stream.UnusedBits = 0;
          if ( (signed int)(v47->Stream.DataSize - v47->Stream.Pos) < 2 )
            Scaleform::GFx::Stream::PopulateBuffer(&v47->Stream, 2);
          v48 = v47->Stream.Pos;
          v49 = (unsigned __int8)v47->Stream.pBuffer[v48] | ((unsigned __int8)v47->Stream.pBuffer[(unsigned int)(v48 + 1)] << 8);
          v47->Stream.Pos = v48 + 2;
          this->FillStyle->pFill.pObject->pGradient.pObject->FocalRatio = (float)v49 * 0.00390625;
        }
        v50 = this->FillStyle->pFill.pObject;
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
    v32 = GradientLinear;
    goto LABEL_39;
  }
  if ( (Blue & 0x40) != 0 )
  {
    U16 = Scaleform::GFx::LoadProcess::ReadU16(p);
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
      (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>,
      "  BitmapChar = %d\n");
    *(_OWORD *)((char *)m + 8) = _xmm;
    *(__m128 *)((char *)&m[1] + 8) = _xmm;
    v52 = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
    if ( !v52 )
      v52 = &p->ProcessInfo;
    Scaleform::GFx::Stream::ReadMatrix(&v52->Stream, (Scaleform::Render::Matrix2x4<float> *)((char *)m + 8));
    phandle.HType = RH_Pointer;
    phandle.pResource = 0i64;
    *(_OWORD *)v73 = _xmm;
    *(__m128 *)&v73[16] = _xmm;
    Scaleform::Render::Matrix2x4<float>::SetInverse(
      (Scaleform::Render::Matrix2x4<float> *)v73,
      (Scaleform::Render::Matrix2x4<float> *)((char *)m + 8));
    v53 = (Scaleform::Render::ComplexFill *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(
                                              Scaleform::Memory::pGlobalHeap,
                                              80i64,
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
    v56 = this->FillStyle;
    v57 = (Scaleform::Render::RenderBuffer *)this->FillStyle->pFill.pObject;
    if ( v57 )
      Scaleform::RefCountImpl::Release(v57);
    v56->pFill.pObject = v55;
    v58 = this->FillStyle->pFill.pObject;
    *(_OWORD *)&v58->ImageMatrix.M[0][0] = *(_OWORD *)v73;
    *(_OWORD *)&v58->ImageMatrix.M[1][0] = *(_OWORD *)&v73[16];
    switch ( Blue )
    {
      case @:
        v58->FillMode.Fill = 2;
        break;
      case A:
        v58->FillMode.Fill = 3;
        break;
      case B:
        v58->FillMode.Fill = 0;
        break;
      case C:
        v58->FillMode.Fill = 1;
        break;
    }
    rid.Id = U16;
    ResourceHandle = Scaleform::GFx::MovieDataDef::LoadTaskData::GetResourceHandle(p->pLoadData.pObject, &phandle, &rid);
    pResource = phandle.pResource;
    HType = phandle.HType;
    if ( ResourceHandle && phandle.HType == RH_Pointer && phandle.pResource )
    {
      if ( (((__int64 (__fastcall *)(Scaleform::GFx::Resource *))phandle.pResource->vfptr->GetResourceTypeCode)(phandle.pResource) & 0xFF00) == 256 )
      {
        vfptr = (Scaleform::Render::Image *)pResource[1].vfptr;
        v63 = this->FillStyle->pFill.pObject;
        if ( vfptr )
          ((void (__fastcall *)(Scaleform::GFx::ResourceVtbl *))vfptr->vfptr[1].__vecDelDtor)(pResource[1].vfptr);
        v64 = v63->pImage.pObject;
        if ( v64 )
          ((void (__fastcall *)(Scaleform::Render::Image *))v64->vfptr[2].__vecDelDtor)(v64);
        v63->pImage.pObject = vfptr;
      }
    }
    else
    {
      this->FillStyle->Color = -5776071;
      if ( HType == RH_Index )
      {
        this->FillStyle->pFill.pObject->BindIndex = phandle.BindIndex;
        pTempBindData = p->pTempBindData;
        if ( pTempBindData && (((_BYTE)Blue - 64) & 0xFD) == 0 )
          Scaleform::HashSet<unsigned int,Scaleform::FixedSizeHash<unsigned int>,Scaleform::FixedSizeHash<unsigned int>,Scaleform::AllocatorLH<unsigned int,2>,Scaleform::HashsetCachedEntry<unsigned int,Scaleform::FixedSizeHash<unsigned int>>>::Add<unsigned int>(
            &pTempBindData->FillStyleImageWrap,
            &this->FillStyle->pFill.pObject->BindIndex);
      }
      else
      {
        v66 = this->FillStyle;
        v67 = (Scaleform::Render::RenderBuffer *)this->FillStyle->pFill.pObject;
        if ( v67 )
          Scaleform::RefCountImpl::Release(v67);
        v66->pFill.pObject = 0i64;
        if ( U16 != 0xFFFF )
        {
          id[0].Id = 135168;
          Scaleform::LogDebugMessage(
            (Scaleform::LogMessageId)id,
            "An image with resource id %d is not found in resource table.",
            U16);
        }
      }
    }
    if ( HType == RH_Pointer && pResource && !_InterlockedDecrement(&pResource->RefCount.Value) )
    {
      v68 = phandle.pResource;
      pLib = phandle.pResource->pLib;
      if ( pLib )
      {
        pLib->vfptr[1].__vecDelDtor(pLib, (unsigned int)phandle.pResource);
        v68->pLib = 0i64;
      }
      v68->vfptr->__vecDelDtor(v68, 1u);
    }
  }
}esource);
        v68->pLib = 0i64;
      }
      v68->vfptr->__vecDelDtor(v68, 1u);
    }
  }
}

// File Line: 302
// RVA: 0x8BDD50
__int64 __fastcall Scaleform::GFx::StrokeStyleSwfReader::ConvertSwfLineStyles(__int16 swfLineStyle)
{
  unsigned int v1; // edx

  v1 = (swfLineStyle & 1) != 0;
  if ( (swfLineStyle & 2) != 0 )
    v1 |= 2u;
  if ( (swfLineStyle & 4) != 0 )
    v1 |= 4u;
  if ( (swfLineStyle & 6) == 6 )
    v1 = 6;
  if ( (swfLineStyle & 0x10) != 0 )
    v1 |= 0x10u;
  if ( (swfLineStyle & 0x20) != 0 )
    v1 |= 0x20u;
  if ( (swfLineStyle & 0x40) != 0 )
    v1 |= 0x40u;
  if ( (swfLineStyle & 0x80u) != 0 )
    v1 |= 0x80u;
  if ( (swfLineStyle & 0x100) != 0 )
    v1 |= 0x100u;
  if ( (swfLineStyle & 0x200) != 0 )
    v1 |= 0x200u;
  if ( (swfLineStyle & 8) != 0 )
    v1 |= 8u;
  return v1;
}

// File Line: 333
// RVA: 0x8F9DA0
void __fastcall Scaleform::GFx::StrokeStyleSwfReader::Read(
        Scaleform::GFx::StrokeStyleSwfReader *this,
        Scaleform::GFx::LoadProcess *p,
        int tagType)
{
  Scaleform::GFx::SWFProcessInfo *pAltStream; // rbx
  __int64 Pos; // r9
  unsigned __int16 v8; // r8
  int v9; // r15d
  float v10; // xmm6_4
  __int16 v11; // bp
  Scaleform::GFx::SWFProcessInfo *p_ProcessInfo; // rbx
  __int64 v13; // r8
  unsigned int v14; // ebp
  Scaleform::Render::StrokeStyleType *StrokeStyle; // rbx
  Scaleform::GFx::Resource *v16; // rax
  Scaleform::Render::RenderBuffer *pObject; // rcx
  Scaleform::GFx::ResourceVtbl *vfptr; // rax
  Scaleform::GFx::SWFProcessInfo *v19; // rcx
  Scaleform::GFx::SWFProcessInfo *v20; // rbx
  __int64 v21; // rdx
  char v22; // cl
  Scaleform::Render::StrokeStyleType *v23; // rbx
  Scaleform::Render::RenderBuffer *v24; // rcx
  unsigned int v25; // [rsp+28h] [rbp-50h] BYREF
  Scaleform::GFx::Resource *v26; // [rsp+30h] [rbp-48h]
  Scaleform::GFx::FillStyleSwfReader v27; // [rsp+80h] [rbp+8h] BYREF
  Scaleform::Render::Color pc; // [rsp+90h] [rbp+18h] BYREF

  pAltStream = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  if ( !pAltStream )
    pAltStream = &p->ProcessInfo;
  pAltStream->Stream.UnusedBits = 0;
  if ( (signed int)(pAltStream->Stream.DataSize - pAltStream->Stream.Pos) < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
  Pos = pAltStream->Stream.Pos;
  v8 = (unsigned __int8)pAltStream->Stream.pBuffer[Pos] | ((unsigned __int8)pAltStream->Stream.pBuffer[(unsigned int)(Pos + 1)] << 8);
  pAltStream->Stream.Pos = Pos + 2;
  v9 = v8;
  v10 = FLOAT_3_0;
  v11 = 0;
  if ( tagType == 83 )
  {
    p_ProcessInfo = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
    if ( !p_ProcessInfo )
      p_ProcessInfo = &p->ProcessInfo;
    p_ProcessInfo->Stream.UnusedBits = 0;
    if ( (signed int)(p_ProcessInfo->Stream.DataSize - p_ProcessInfo->Stream.Pos) < 2 )
      Scaleform::GFx::Stream::PopulateBuffer(&p_ProcessInfo->Stream, 2);
    v13 = p_ProcessInfo->Stream.Pos;
    v11 = (unsigned __int8)p_ProcessInfo->Stream.pBuffer[v13] | ((unsigned __int8)p_ProcessInfo->Stream.pBuffer[(unsigned int)(v13 + 1)] << 8);
    p_ProcessInfo->Stream.Pos = v13 + 2;
    if ( (v11 & 0x20) != 0 )
      v10 = (float)Scaleform::GFx::LoadProcess::ReadU16(p) * 0.00390625;
  }
  v14 = Scaleform::GFx::StrokeStyleSwfReader::ConvertSwfLineStyles(v11);
  if ( (v14 & 8) != 0 )
  {
    v26 = 0i64;
    v27.FillStyle = (Scaleform::Render::FillStyleType *)&v25;
    Scaleform::GFx::FillStyleSwfReader::Read(&v27, p, tagType);
    this->StrokeStyle->Color = v25;
    this->StrokeStyle->Miter = v10;
    this->StrokeStyle->Width = (float)v9;
    StrokeStyle = this->StrokeStyle;
    v16 = v26;
    if ( v26 )
    {
      Scaleform::Render::RenderBuffer::AddRef(v26);
      v16 = v26;
    }
    pObject = (Scaleform::Render::RenderBuffer *)StrokeStyle->pFill.pObject;
    if ( pObject )
    {
      Scaleform::RefCountImpl::Release(pObject);
      v16 = v26;
    }
    StrokeStyle->pFill.pObject = (Scaleform::Render::ComplexFill *)v16;
    if ( v26 )
    {
      vfptr = v26[1].vfptr;
      if ( vfptr && WORD1(vfptr->GetResourceTypeCode) )
        this->StrokeStyle->Color = *((_DWORD *)vfptr->GetResourceReport + 1);
    }
    else
    {
      this->StrokeStyle->Color = v25;
    }
    if ( v26 )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v26);
  }
  else
  {
    if ( tagType > 22 )
    {
      v20 = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
      if ( !v20 )
        v20 = &p->ProcessInfo;
      Scaleform::GFx::Stream::ReadRgb(&v20->Stream, &pc);
      v20->Stream.UnusedBits = 0;
      if ( (signed int)(v20->Stream.DataSize - v20->Stream.Pos) < 1 )
        Scaleform::GFx::Stream::PopulateBuffer(&v20->Stream, 1);
      v21 = v20->Stream.Pos;
      v22 = v20->Stream.pBuffer[v21];
      v20->Stream.Pos = v21 + 1;
      pc.Channels.Alpha = v22;
    }
    else
    {
      v19 = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
      if ( !v19 )
        v19 = &p->ProcessInfo;
      Scaleform::GFx::Stream::ReadRgb(&v19->Stream, &pc);
    }
    this->StrokeStyle->Color = pc.Raw;
    this->StrokeStyle->Miter = v10;
    v23 = this->StrokeStyle;
    v24 = (Scaleform::Render::RenderBuffer *)this->StrokeStyle->pFill.pObject;
    if ( v24 )
      Scaleform::RefCountImpl::Release(v24);
    v23->pFill.pObject = 0i64;
    this->StrokeStyle->Width = (float)v9;
  }
  this->StrokeStyle->Units = 0.050000001;
  this->StrokeStyle->Flags = v14;
}

// File Line: 433
// RVA: 0x89DD90
void __fastcall Scaleform::GFx::SwfShapeDecoder::SwfShapeDecoder(
        Scaleform::GFx::SwfShapeDecoder *this,
        Scaleform::Render::ShapePosInfo *pos,
        const char *shapeData,
        float sfactor)
{
  unsigned int v5; // edx
  unsigned int v6; // edx
  unsigned int v7; // edx
  unsigned int v8; // edx
  unsigned int v9; // edx
  unsigned __int64 CurByteIndex; // rcx
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
          CurByteIndex = this->Stream.CurByteIndex;
          v11 = this->Stream.pData[CurByteIndex];
          this->Stream.CurBitIndex = 0;
          v6 = v11 & 0xF;
          this->Stream.CurByteIndex = CurByteIndex + 1;
          break;
        case 5u:
          v12 = this->Stream.CurByteIndex;
          v13 = this->Stream.pData[v12];
          v14 = (unsigned __int8)this->Stream.pData[v12 + 1];
          this->Stream.CurBitIndex = 1;
          v6 = (v14 >> 7) | (2 * (v13 & 7));
          this->Stream.CurByteIndex = v12 + 1;
          break;
        case 6u:
          v15 = this->Stream.CurByteIndex;
          v16 = this->Stream.pData[v15];
          v17 = (unsigned __int8)this->Stream.pData[v15 + 1];
          this->Stream.CurBitIndex = 2;
          v6 = (v17 >> 6) | (4 * (v16 & 3));
          this->Stream.CurByteIndex = v15 + 1;
          break;
        case 7u:
          v18 = this->Stream.CurByteIndex;
          v19 = this->Stream.pData[v18];
          v20 = (unsigned __int8)this->Stream.pData[v18 + 1];
          this->Stream.CurBitIndex = 3;
          v6 = (v20 >> 5) | (8 * (v19 & 1));
          this->Stream.CurByteIndex = v18 + 1;
          break;
        default:
          v6 = 0;
          break;
      }
      this->Pos->NumFillBits = v6;
      switch ( this->Stream.CurBitIndex )
      {
        case 0u:
          v21 = (unsigned __int8)this->Stream.pData[this->Stream.CurByteIndex];
          this->Stream.CurBitIndex = 4;
          this->Pos->NumStrokeBits = v21 >> 4;
          break;
        case 1u:
          v22 = (unsigned __int8)this->Stream.pData[this->Stream.CurByteIndex];
          this->Stream.CurBitIndex = 5;
          this->Pos->NumStrokeBits = (v22 >> 3) & 0xF;
          break;
        case 2u:
          v23 = (unsigned __int8)this->Stream.pData[this->Stream.CurByteIndex];
          this->Stream.CurBitIndex = 6;
          this->Pos->NumStrokeBits = (v23 >> 2) & 0xF;
          break;
        case 3u:
          v24 = (unsigned __int8)this->Stream.pData[this->Stream.CurByteIndex];
          this->Stream.CurBitIndex = 7;
          this->Pos->NumStrokeBits = (v24 >> 1) & 0xF;
          break;
        case 4u:
          v25 = this->Stream.CurByteIndex;
          v26 = this->Stream.pData[v25];
          this->Stream.CurBitIndex = 0;
          this->Stream.CurByteIndex = v25 + 1;
          this->Pos->NumStrokeBits = v26 & 0xF;
          break;
        case 5u:
          v27 = this->Stream.CurByteIndex;
          v28 = this->Stream.pData[v27];
          v29 = (unsigned __int8)this->Stream.pData[v27 + 1];
          this->Stream.CurBitIndex = 1;
          this->Stream.CurByteIndex = v27 + 1;
          this->Pos->NumStrokeBits = (v29 >> 7) | (2 * (v28 & 7));
          break;
        case 6u:
          v30 = this->Stream.CurByteIndex;
          v31 = this->Stream.pData[v30];
          v32 = (unsigned __int8)this->Stream.pData[v30 + 1];
          this->Stream.CurBitIndex = 2;
          this->Stream.CurByteIndex = v30 + 1;
          this->Pos->NumStrokeBits = (v32 >> 6) | (4 * (v31 & 3));
          break;
        case 7u:
          v33 = this->Stream.CurByteIndex;
          v34 = this->Stream.pData[v33];
          v35 = (unsigned __int8)this->Stream.pData[v33 + 1];
          this->Stream.CurBitIndex = 3;
          this->Stream.CurByteIndex = v33 + 1;
          this->Pos->NumStrokeBits = (v35 >> 5) | (8 * (v34 & 1));
          break;
        default:
          this->Pos->NumStrokeBits = 0;
          break;
      }
    }
    this->Pos->LastY = 0;
    this->Pos->LastX = 0;
    this->Pos->Stroke = 0;
    this->Pos->Fill1 = 0;
    this->Pos->Fill0 = 0;
    this->Pos->Initialized = 1;
  }
}

// File Line: 472
// RVA: 0x8A7FB0
void __fastcall Scaleform::GFx::SwfShapeDecoder::~SwfShapeDecoder(Scaleform::GFx::SwfShapeDecoder *this)
{
  this->Pos->Pos = this->Stream.CurBitIndex & 7 | (8
                                                 * (this->Pos->NumStrokeBits & 0xF | (16
                                                                                    * ((16
                                                                                      * LODWORD(this->Stream.CurByteIndex)) | this->Pos->NumFillBits & 0xF))));
}

// File Line: 488
// RVA: 0x8FB500
__int64 __fastcall Scaleform::GFx::SwfShapeDecoder::ReadEdge(
        Scaleform::GFx::SwfShapeDecoder *this,
        Scaleform::GFx::SwfShapeDecoder::Edge *edge)
{
  unsigned int UInt; // esi
  unsigned int CurBitIndex; // r8d
  int v6; // r9d
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
  int v25; // r15d
  unsigned int v26; // ebp
  unsigned int v27; // r14d
  unsigned int v28; // r12d
  unsigned int v29; // r8d
  __int64 result; // rax
  int LastY; // edx
  unsigned int v32; // edx
  unsigned int v33; // edx
  unsigned int v34; // edx
  unsigned int v35; // edx
  unsigned int v36; // edx
  unsigned __int64 CurByteIndex; // rcx
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
  unsigned int v48; // r8d
  unsigned int v49; // ebp
  int v50; // r9d
  unsigned int v51; // r14d
  int v52; // r12d
  unsigned int v53; // edx
  unsigned __int64 v54; // r9
  int v55; // r8d

  ++this->Stream.CurBitIndex;
  UInt = 0;
  if ( this->Stream.CurBitIndex >= 8 )
  {
    ++this->Stream.CurByteIndex;
    this->Stream.CurBitIndex = 0;
  }
  CurBitIndex = this->Stream.CurBitIndex;
  v6 = (unsigned __int8)this->Stream.pData[this->Stream.CurByteIndex] & (1 << (7 - CurBitIndex));
  this->Stream.CurBitIndex = CurBitIndex + 1;
  if ( CurBitIndex + 1 >= 8 )
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
        CurByteIndex = this->Stream.CurByteIndex;
        v38 = this->Stream.pData[CurByteIndex];
        this->Stream.CurBitIndex = 0;
        v33 = v38 & 0xF;
        this->Stream.CurByteIndex = CurByteIndex + 1;
        break;
      case 5u:
        v39 = this->Stream.CurByteIndex;
        v40 = this->Stream.pData[v39];
        v41 = (unsigned __int8)this->Stream.pData[v39 + 1];
        this->Stream.CurBitIndex = 1;
        v33 = (v41 >> 7) | (2 * (v40 & 7));
        this->Stream.CurByteIndex = v39 + 1;
        break;
      case 6u:
        v42 = this->Stream.CurByteIndex;
        v43 = this->Stream.pData[v42];
        v44 = (unsigned __int8)this->Stream.pData[v42 + 1];
        this->Stream.CurBitIndex = 2;
        v33 = (v44 >> 6) | (4 * (v43 & 3));
        this->Stream.CurByteIndex = v42 + 1;
        break;
      case 7u:
        v45 = this->Stream.CurByteIndex;
        v46 = this->Stream.pData[v45];
        v47 = (unsigned __int8)this->Stream.pData[v45 + 1];
        this->Stream.CurBitIndex = 3;
        v33 = (v47 >> 5) | (8 * (v46 & 1));
        this->Stream.CurByteIndex = v45 + 1;
        break;
      default:
        v33 = 0;
        break;
    }
    v48 = this->Stream.CurBitIndex;
    v49 = v33 + 2;
    v50 = (unsigned __int8)this->Stream.pData[this->Stream.CurByteIndex] & (1 << (7 - v48));
    this->Stream.CurBitIndex = v48 + 1;
    if ( v48 + 1 >= 8 )
    {
      this->Stream.CurBitIndex = 0;
      ++this->Stream.CurByteIndex;
    }
    edge->Curve = 0;
    v51 = 0;
    if ( v50 )
    {
      v52 = 1 << (v33 + 1);
      UInt = Scaleform::GFx::StreamContext::ReadUInt(&this->Stream, v49);
      if ( (v52 & UInt) != 0 )
        UInt |= -1 << v49;
      v51 = Scaleform::GFx::StreamContext::ReadUInt(&this->Stream, v49);
      if ( (v51 & v52) == 0 )
        goto LABEL_49;
    }
    else
    {
      v53 = this->Stream.CurBitIndex;
      v54 = this->Stream.CurByteIndex;
      v55 = (unsigned __int8)this->Stream.pData[v54] & (1 << (7 - v53));
      this->Stream.CurBitIndex = v53 + 1;
      if ( v53 + 1 >= 8 )
      {
        this->Stream.CurBitIndex = 0;
        this->Stream.CurByteIndex = v54 + 1;
      }
      if ( !v55 )
      {
        UInt = Scaleform::GFx::StreamContext::ReadUInt(&this->Stream, v49);
        if ( _bittest((const int *)&UInt, (unsigned __int8)(v49 - 1)) )
          UInt |= -1 << v49;
        goto LABEL_49;
      }
      v51 = Scaleform::GFx::StreamContext::ReadUInt(&this->Stream, v49);
      if ( !_bittest((const int *)&v51, (unsigned __int8)(v49 - 1)) )
      {
LABEL_49:
        result = 1i64;
        edge->Ax = UInt + this->Pos->LastX;
        edge->Ay = v51 + this->Pos->LastY;
        this->Pos->LastX += UInt;
        this->Pos->LastY += v51;
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
      v14 = this->Stream.pData[v13];
      this->Stream.CurBitIndex = 0;
      v9 = v14 & 0xF;
      this->Stream.CurByteIndex = v13 + 1;
      break;
    case 5u:
      v15 = this->Stream.CurByteIndex;
      v16 = this->Stream.pData[v15];
      v17 = (unsigned __int8)this->Stream.pData[v15 + 1];
      this->Stream.CurBitIndex = 1;
      v9 = (v17 >> 7) | (2 * (v16 & 7));
      this->Stream.CurByteIndex = v15 + 1;
      break;
    case 6u:
      v18 = this->Stream.CurByteIndex;
      v19 = this->Stream.pData[v18];
      v20 = (unsigned __int8)this->Stream.pData[v18 + 1];
      this->Stream.CurBitIndex = 2;
      v9 = (v20 >> 6) | (4 * (v19 & 3));
      this->Stream.CurByteIndex = v18 + 1;
      break;
    case 7u:
      v21 = this->Stream.CurByteIndex;
      v22 = this->Stream.pData[v21];
      v23 = (unsigned __int8)this->Stream.pData[v21 + 1];
      this->Stream.CurBitIndex = 3;
      v9 = (v23 >> 5) | (8 * (v22 & 1));
      this->Stream.CurByteIndex = v21 + 1;
      break;
    default:
      v9 = 0;
      break;
  }
  v24 = v9 + 2;
  v25 = 1 << (v9 + 1);
  v26 = Scaleform::GFx::StreamContext::ReadUInt(&this->Stream, v9 + 2);
  if ( (v25 & v26) != 0 )
    v26 |= -1 << v24;
  v27 = Scaleform::GFx::StreamContext::ReadUInt(&this->Stream, v24);
  if ( (v25 & v27) != 0 )
    v27 |= -1 << v24;
  v28 = Scaleform::GFx::StreamContext::ReadUInt(&this->Stream, v24);
  if ( (v25 & v28) != 0 )
    v28 |= -1 << v24;
  v29 = Scaleform::GFx::StreamContext::ReadUInt(&this->Stream, v24);
  if ( (v25 & v29) != 0 )
    v29 |= -1 << v24;
  edge->Cx = v26 + this->Pos->LastX;
  edge->Cy = v27 + this->Pos->LastY;
  result = 2i64;
  this->Pos->LastX += v28 + v26;
  this->Pos->LastY += v29 + v27;
  edge->Ax = this->Pos->LastX;
  LastY = this->Pos->LastY;
  edge->Curve = 1;
  edge->Ay = LastY;
  return result;
} + this->Pos->LastX;
  edge->Cy = v27 + this->Pos->LastY;
  result = 2i64;
  this->Pos->LastX += v28 + 

// File Line: 557
// RVA: 0x8FC6E0
__int64 __fastcall Scaleform::GFx::SwfShapeDecoder::ReadNonEdgeRec(
        Scaleform::GFx::SwfShapeDecoder *this,
        unsigned int retVal)
{
  unsigned int v4; // edi
  unsigned int v5; // edi
  unsigned int v6; // edi
  unsigned int v7; // edi
  char v8; // di
  unsigned __int64 CurByteIndex; // rax
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
  int v37; // r14d
  int UInt; // r8d
  int v39; // eax
  unsigned int NumFillBits; // edx
  unsigned int v41; // eax
  unsigned int v42; // edx
  signed int v43; // eax
  unsigned int NumStrokeBits; // edx
  signed int v45; // eax
  unsigned __int64 v46; // rax
  const char *pData; // r10
  unsigned int v48; // ecx
  unsigned int v49; // r9d
  unsigned __int64 v50; // rax
  int v51; // r9d
  unsigned __int64 v52; // rdx
  unsigned __int64 v53; // rax
  int v54; // ecx
  int v55; // r8d
  int v56; // r8d
  unsigned __int64 v57; // rdx
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
  __int64 result; // rax
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

  if ( ++this->Stream.CurBitIndex >= 8 )
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
      CurByteIndex = this->Stream.CurByteIndex;
      v10 = this->Stream.pData[CurByteIndex];
      LODWORD(CurByteIndex) = (unsigned __int8)this->Stream.pData[CurByteIndex + 1];
      this->Stream.CurBitIndex = 1;
      v11 = 2 * (v10 & 0xF);
      v12 = (unsigned int)CurByteIndex >> 7;
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
      if ( (v5 & 1) != 0 )
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
            v24 = this->Stream.pData[v23];
            this->Stream.CurBitIndex = 0;
            v20 = v24 & 0x1F;
            this->Stream.CurByteIndex = v23 + 1;
            break;
          case 4u:
            v25 = this->Stream.CurByteIndex;
            v26 = this->Stream.pData[v25];
            v27 = (unsigned __int8)this->Stream.pData[v25 + 1];
            this->Stream.CurBitIndex = 1;
            v20 = (v27 >> 7) | (2 * (v26 & 0xF));
            this->Stream.CurByteIndex = v25 + 1;
            break;
          case 5u:
            v28 = this->Stream.CurByteIndex;
            v29 = this->Stream.pData[v28];
            v30 = (unsigned __int8)this->Stream.pData[v28 + 1];
            this->Stream.CurBitIndex = 2;
            v20 = (v30 >> 6) | (4 * (v29 & 7));
            this->Stream.CurByteIndex = v28 + 1;
            break;
          case 6u:
            v31 = this->Stream.CurByteIndex;
            v32 = this->Stream.pData[v31];
            v33 = (unsigned __int8)this->Stream.pData[v31 + 1];
            this->Stream.CurBitIndex = 3;
            v20 = (v33 >> 5) | (8 * (v32 & 3));
            this->Stream.CurByteIndex = v31 + 1;
            break;
          case 7u:
            v34 = this->Stream.CurByteIndex;
            v35 = this->Stream.pData[v34];
            v36 = (unsigned __int8)this->Stream.pData[v34 + 1];
            this->Stream.CurBitIndex = 4;
            v20 = (v36 >> 4) | (16 * (v35 & 1));
            this->Stream.CurByteIndex = v34 + 1;
            break;
          default:
            v20 = 0;
            break;
        }
        v37 = 1 << (v20 - 1);
        UInt = Scaleform::GFx::StreamContext::ReadUInt(&this->Stream, v20);
        if ( (v37 & UInt) != 0 )
          UInt |= -1 << v20;
        this->Pos->LastX = UInt;
        v39 = Scaleform::GFx::StreamContext::ReadUInt(&this->Stream, v20);
        if ( (v37 & v39) != 0 )
          v39 |= -1 << v20;
        this->Pos->LastY = v39;
      }
      if ( (v5 & 2) != 0 )
      {
        NumFillBits = this->Pos->NumFillBits;
        if ( NumFillBits )
        {
          v41 = Scaleform::GFx::StreamContext::ReadUInt(&this->Stream, NumFillBits);
          if ( v41 )
            v41 += this->Pos->FillBase;
          this->Pos->Fill0 = v41;
        }
      }
      if ( (v5 & 4) != 0 )
      {
        v42 = this->Pos->NumFillBits;
        if ( v42 )
        {
          v43 = Scaleform::GFx::StreamContext::ReadUInt(&this->Stream, v42);
          if ( v43 > 0 )
            v43 += this->Pos->FillBase;
          this->Pos->Fill1 = v43;
        }
      }
      if ( (v5 & 8) != 0 )
      {
        NumStrokeBits = this->Pos->NumStrokeBits;
        if ( NumStrokeBits )
        {
          v45 = Scaleform::GFx::StreamContext::ReadUInt(&this->Stream, NumStrokeBits);
          if ( v45 > 0 )
            v45 += this->Pos->StrokeBase;
          this->Pos->Stroke = v45;
        }
      }
      if ( (v5 & 0x10) != 0 )
      {
        this->Pos->Stroke = 0;
        this->Pos->Fill1 = 0;
        this->Pos->Fill0 = 0;
        if ( this->Stream.CurBitIndex )
          ++this->Stream.CurByteIndex;
        this->Stream.CurBitIndex = 0;
        v46 = this->Stream.CurByteIndex;
        pData = this->Stream.pData;
        v48 = (unsigned __int8)this->Stream.pData[v46];
        this->Stream.CurByteIndex = v46 + 1;
        v49 = v48;
        if ( (_BYTE)v48 )
        {
          v50 = this->Stream.CurByteIndex;
          this->Stream.CurBitIndex = 0;
          v51 = (unsigned __int8)pData[v50];
          this->Stream.CurBitIndex = 0;
          this->Stream.CurByteIndex = v50 + 1;
          v52 = v50 + 2;
          LODWORD(v50) = (unsigned __int8)pData[v50 + 1] << 8;
          this->Stream.CurBitIndex = 0;
          this->Stream.CurByteIndex = v52;
          v49 = (unsigned __int8)pData[v52] | v50 | (v51 << 16);
          this->Stream.CurByteIndex = v52 + 1;
        }
        if ( this->Stream.CurBitIndex )
          ++this->Stream.CurByteIndex;
        v53 = this->Stream.CurByteIndex;
        this->Stream.CurBitIndex = 0;
        v54 = (unsigned __int8)pData[v53];
        this->Stream.CurByteIndex = v53 + 1;
        v55 = v54;
        if ( v54 == 255 )
        {
          this->Stream.CurBitIndex = 0;
          v56 = (unsigned __int8)pData[v53 + 1];
          this->Stream.CurByteIndex = v53 + 2;
          v57 = v53 + 3;
          this->Stream.CurBitIndex = 0;
          v58 = (unsigned __int8)pData[v53 + 2];
          this->Stream.CurByteIndex = v57;
          this->Stream.CurBitIndex = 0;
          v59 = (unsigned __int8)pData[v57];
          this->Stream.CurByteIndex = v57 + 1;
          v55 = v59 | (v58 << 8) | (v56 << 16);
        }
        this->Pos->FillBase = v49;
        this->Pos->StrokeBase = v55;
        switch ( this->Stream.CurBitIndex )
        {
          case 0u:
            v60 = (unsigned __int8)this->Stream.pData[this->Stream.CurByteIndex];
            this->Stream.CurBitIndex = 4;
            v61 = v60 >> 4;
            break;
          case 1u:
            v62 = (unsigned __int8)this->Stream.pData[this->Stream.CurByteIndex];
            this->Stream.CurBitIndex = 5;
            v61 = (v62 >> 3) & 0xF;
            break;
          case 2u:
            v63 = (unsigned __int8)this->Stream.pData[this->Stream.CurByteIndex];
            this->Stream.CurBitIndex = 6;
            v61 = (v63 >> 2) & 0xF;
            break;
          case 3u:
            v64 = (unsigned __int8)this->Stream.pData[this->Stream.CurByteIndex];
            this->Stream.CurBitIndex = 7;
            v61 = (v64 >> 1) & 0xF;
            break;
          case 4u:
            v65 = this->Stream.CurByteIndex;
            v66 = this->Stream.pData[v65];
            this->Stream.CurBitIndex = 0;
            v61 = v66 & 0xF;
            this->Stream.CurByteIndex = v65 + 1;
            break;
          case 5u:
            v67 = this->Stream.CurByteIndex;
            v68 = this->Stream.pData[v67];
            v69 = (unsigned __int8)this->Stream.pData[v67 + 1];
            this->Stream.CurBitIndex = 1;
            v61 = (v69 >> 7) | (2 * (v68 & 7));
            this->Stream.CurByteIndex = v67 + 1;
            break;
          case 6u:
            v70 = this->Stream.CurByteIndex;
            v71 = this->Stream.pData[v70];
            v72 = (unsigned __int8)this->Stream.pData[v70 + 1];
            this->Stream.CurBitIndex = 2;
            v61 = (v72 >> 6) | (4 * (v71 & 3));
            this->Stream.CurByteIndex = v70 + 1;
            break;
          case 7u:
            v73 = this->Stream.CurByteIndex;
            v74 = this->Stream.pData[v73];
            v75 = (unsigned __int8)this->Stream.pData[v73 + 1];
            this->Stream.CurBitIndex = 3;
            v61 = (v75 >> 5) | (8 * (v74 & 1));
            this->Stream.CurByteIndex = v73 + 1;
            break;
          default:
            v61 = 0;
            break;
        }
        this->Pos->NumFillBits = v61;
        switch ( this->Stream.CurBitIndex )
        {
          case 0u:
            v76 = (unsigned __int8)this->Stream.pData[this->Stream.CurByteIndex];
            this->Stream.CurBitIndex = 4;
            result = 2i64;
            this->Pos->NumStrokeBits = v76 >> 4;
            break;
          case 1u:
            v78 = (unsigned __int8)this->Stream.pData[this->Stream.CurByteIndex];
            this->Stream.CurBitIndex = 5;
            result = 2i64;
            this->Pos->NumStrokeBits = (v78 >> 3) & 0xF;
            break;
          case 2u:
            v79 = (unsigned __int8)this->Stream.pData[this->Stream.CurByteIndex];
            this->Stream.CurBitIndex = 6;
            result = 2i64;
            this->Pos->NumStrokeBits = (v79 >> 2) & 0xF;
            break;
          case 3u:
            v80 = (unsigned __int8)this->Stream.pData[this->Stream.CurByteIndex];
            this->Stream.CurBitIndex = 7;
            result = 2i64;
            this->Pos->NumStrokeBits = (v80 >> 1) & 0xF;
            break;
          case 4u:
            v81 = this->Stream.CurByteIndex;
            v82 = this->Stream.pData[v81];
            this->Stream.CurBitIndex = 0;
            this->Stream.CurByteIndex = v81 + 1;
            this->Pos->NumStrokeBits = v82 & 0xF;
            result = 2i64;
            break;
          case 5u:
            v83 = this->Stream.CurByteIndex;
            v84 = this->Stream.pData[v83];
            v85 = (unsigned __int8)this->Stream.pData[v83 + 1];
            this->Stream.CurBitIndex = 1;
            v86 = (v85 >> 7) | (2 * (v84 & 7));
            this->Stream.CurByteIndex = v83 + 1;
            result = 2i64;
            this->Pos->NumStrokeBits = v86;
            break;
          case 6u:
            v87 = this->Stream.CurByteIndex;
            v88 = this->Stream.pData[v87];
            v89 = (unsigned __int8)this->Stream.pData[v87 + 1];
            this->Stream.CurBitIndex = 2;
            v90 = (v89 >> 6) | (4 * (v88 & 3));
            this->Stream.CurByteIndex = v87 + 1;
            result = 2i64;
            this->Pos->NumStrokeBits = v90;
            break;
          case 7u:
            v91 = this->Stream.CurByteIndex;
            v92 = this->Stream.pData[v91];
            v93 = (unsigned __int8)this->Stream.pData[v91 + 1];
            this->Stream.CurBitIndex = 3;
            v94 = (v93 >> 5) | (8 * (v92 & 1));
            this->Stream.CurByteIndex = v91 + 1;
            result = 2i64;
            this->Pos->NumStrokeBits = v94;
            break;
          default:
            result = 2i64;
            this->Pos->NumStrokeBits = 0;
            break;
        }
      }
      else
      {
        result = retVal;
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
__int64 __fastcall Scaleform::GFx::ShapeSwfReader::ReadFillStyles(
        Scaleform::GFx::ShapeSwfReader *this,
        Scaleform::GFx::LoadProcess *p,
        int tagType)
{
  Scaleform::GFx::SWFProcessInfo *pAltStream; // rbx
  unsigned int DataSize; // eax
  __int64 Pos; // rdx
  unsigned int v9; // ecx
  unsigned int U16; // ebp
  Scaleform::GFx::SWFProcessInfo *p_ProcessInfo; // rax
  unsigned int v12; // r15d
  int Size; // r12d
  unsigned int i; // esi
  Scaleform::GFx::SWFProcessInfo *v15; // rax
  Scaleform::Render::FillStyleType *FillStyle; // rbx
  Scaleform::Render::ComplexFill *pObject; // rax
  Scaleform::Render::ComplexFill *v18; // rcx
  Scaleform::GFx::FillStyleSwfReader v20; // [rsp+50h] [rbp+8h] BYREF

  pAltStream = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  if ( !pAltStream )
    pAltStream = &p->ProcessInfo;
  DataSize = pAltStream->Stream.DataSize;
  pAltStream->Stream.UnusedBits = 0;
  if ( (int)(DataSize - pAltStream->Stream.Pos) < 1 )
    Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 1);
  Pos = pAltStream->Stream.Pos;
  v9 = (unsigned __int8)pAltStream->Stream.pBuffer[Pos];
  pAltStream->Stream.Pos = Pos + 1;
  U16 = v9;
  if ( tagType > 2 && v9 == 255 )
    U16 = Scaleform::GFx::LoadProcess::ReadU16(p);
  p_ProcessInfo = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  if ( !p_ProcessInfo )
    p_ProcessInfo = &p->ProcessInfo;
  v12 = p_ProcessInfo->Stream.Pos + p_ProcessInfo->Stream.FilePos - p_ProcessInfo->Stream.DataSize;
  Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
    (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>,
    "  GFx_ReadFillStyles: count = %d\n");
  Size = this->FillStyles.Data.Size;
  if ( U16 )
    Scaleform::ArrayData<Scaleform::Render::FillStyleType,Scaleform::AllocatorGH<Scaleform::Render::FillStyleType,259>,Scaleform::ArrayDefaultPolicy>::Resize(
      &this->FillStyles.Data,
      Size + U16);
  for ( i = 0; i < U16; ++i )
  {
    v15 = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
    if ( !v15 )
      v15 = &p->ProcessInfo;
    v15->Stream.UnusedBits = 0;
    v20.FillStyle = &this->FillStyles.Data.Data[i + Size];
    FillStyle = v20.FillStyle;
    Scaleform::GFx::FillStyleSwfReader::Read(&v20, p, tagType);
    pObject = FillStyle->pFill.pObject;
    if ( pObject && (pObject->pImage.pObject || pObject->BindIndex != -1) )
      this->Shape->Flags |= 1u;
    v18 = FillStyle->pFill.pObject;
    if ( v18 && v18->BindIndex != -1 )
      this->Shape->Flags |= 4u;
  }
  return v12;
}

// File Line: 725
// RVA: 0x8FD6E0
__int64 __fastcall Scaleform::GFx::ShapeSwfReader::ReadStrokeStyles(
        Scaleform::GFx::ShapeSwfReader *this,
        Scaleform::GFx::LoadProcess *p,
        Scaleform::GFx::TagType tagType)
{
  Scaleform::GFx::SWFProcessInfo *pAltStream; // rbx
  unsigned int DataSize; // eax
  __int64 Pos; // rdx
  unsigned int v8; // ebp
  Scaleform::GFx::SWFProcessInfo *p_ProcessInfo; // rbx
  unsigned int v10; // eax
  __int64 v11; // r10
  Scaleform::GFx::SWFProcessInfo *v12; // rax
  int Size; // r12d
  unsigned int v14; // r15d
  unsigned int v15; // esi
  int v16; // r15d
  Scaleform::GFx::SWFProcessInfo *v17; // rax
  Scaleform::Render::StrokeStyleType *StrokeStyle; // rbx
  Scaleform::Render::ComplexFill *pObject; // rax
  Scaleform::Render::ComplexFill *v20; // rcx
  unsigned int v22; // [rsp+60h] [rbp+8h]
  Scaleform::GFx::StrokeStyleSwfReader v23; // [rsp+68h] [rbp+10h] BYREF
  Scaleform::GFx::TagType tagTypea; // [rsp+70h] [rbp+18h]

  tagTypea = tagType;
  pAltStream = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  if ( !pAltStream )
    pAltStream = &p->ProcessInfo;
  DataSize = pAltStream->Stream.DataSize;
  pAltStream->Stream.UnusedBits = 0;
  if ( (int)(DataSize - pAltStream->Stream.Pos) < 1 )
    Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 1);
  Pos = pAltStream->Stream.Pos;
  v8 = (unsigned __int8)pAltStream->Stream.pBuffer[Pos];
  pAltStream->Stream.Pos = Pos + 1;
  Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
    (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>,
    "  GFx_ReadStrokeStyles: count = %d\n");
  if ( v8 == 255 )
  {
    p_ProcessInfo = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
    if ( !p_ProcessInfo )
      p_ProcessInfo = &p->ProcessInfo;
    v10 = p_ProcessInfo->Stream.DataSize;
    p_ProcessInfo->Stream.UnusedBits = 0;
    if ( (int)(v10 - p_ProcessInfo->Stream.Pos) < 2 )
      Scaleform::GFx::Stream::PopulateBuffer(&p_ProcessInfo->Stream, 2);
    v11 = p_ProcessInfo->Stream.Pos;
    v8 = (unsigned __int16)((unsigned __int8)p_ProcessInfo->Stream.pBuffer[v11] | ((unsigned __int8)p_ProcessInfo->Stream.pBuffer[(unsigned int)(v11 + 1)] << 8));
    p_ProcessInfo->Stream.Pos = v11 + 2;
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
      (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>,
      "  GFx_ReadStrokeStyles: count2 = %d\n");
  }
  v12 = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  if ( !v12 )
    v12 = &p->ProcessInfo;
  Size = this->StrokeStyles.Data.Size;
  v14 = v12->Stream.Pos + v12->Stream.FilePos - v12->Stream.DataSize;
  v22 = v14;
  Scaleform::ArrayData<Scaleform::Render::StrokeStyleType,Scaleform::AllocatorGH<Scaleform::Render::StrokeStyleType,259>,Scaleform::ArrayDefaultPolicy>::Resize(
    &this->StrokeStyles.Data,
    Size + v8);
  v15 = 0;
  if ( !v8 )
    return v14;
  v16 = tagTypea;
  do
  {
    v17 = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
    if ( !v17 )
      v17 = &p->ProcessInfo;
    v17->Stream.UnusedBits = 0;
    v23.StrokeStyle = &this->StrokeStyles.Data.Data[v15 + Size];
    StrokeStyle = v23.StrokeStyle;
    Scaleform::GFx::StrokeStyleSwfReader::Read(&v23, p, v16);
    pObject = StrokeStyle->pFill.pObject;
    if ( pObject && (pObject->pImage.pObject || pObject->BindIndex != -1) )
      this->Shape->Flags |= 1u;
    v20 = StrokeStyle->pFill.pObject;
    if ( v20 )
    {
      if ( v20->BindIndex != -1 )
        this->Shape->Flags |= 4u;
    }
    ++v15;
  }
  while ( v15 < v8 );
  return v22;
}

// File Line: 760
// RVA: 0x8F8780
bool __fastcall Scaleform::GFx::ShapeSwfReader::Read(
        Scaleform::GFx::ShapeSwfReader *this,
        Scaleform::GFx::LoadProcess *p,
        Scaleform::GFx::TagType tagType,
        unsigned int lenInBytes)
{
  Scaleform::GFx::SWFProcessInfo *pAltStream; // r14
  int v9; // eax
  char v10; // di
  int v11; // ebx
  float v12; // r12d
  char *v13; // rax
  char *v14; // rsi
  unsigned int v16; // r14d
  unsigned int v17; // r13d
  unsigned int v18; // r15d
  int v19; // r12d
  int v20; // esi
  bool v21; // di
  unsigned int DataSize; // r10d
  unsigned int Pos; // r8d
  unsigned int v24; // edx
  char v25; // r9
  int v26; // r11d
  unsigned __int8 v27; // dl
  unsigned int v28; // eax
  char v29; // r14
  unsigned int v30; // edi
  int v31; // esi
  signed int v32; // eax
  Scaleform::GFx::ShapeSwfReader *v33; // r12
  signed int v34; // r13d
  int FillStyles; // r15d
  signed int v36; // esi
  int StrokeStyles; // edi
  signed int v38; // r14d
  int vfptr; // edx
  bool v40; // cc
  __int64 v41; // r12
  int v42; // edi
  int pLog; // edx
  float x1; // esi
  unsigned int v45; // edx
  int v46; // r8d
  char v47; // dl
  unsigned int v48; // edi
  unsigned int v49; // r13d
  int v50; // esi
  unsigned int v51; // r12d
  unsigned int v52; // r15d
  unsigned int v53; // r14d
  unsigned int v54; // edi
  unsigned int v55; // esi
  int v56; // r15d
  unsigned int v57; // eax
  unsigned int x1_low; // r9d
  char *v59; // rsi
  bool v60; // di
  unsigned int oldSize; // [rsp+40h] [rbp-80h]
  int v62; // [rsp+44h] [rbp-7Ch]
  __int64 bitcount; // [rsp+48h] [rbp-78h]
  Scaleform::Render::Rect<float> pr; // [rsp+50h] [rbp-70h] BYREF
  Scaleform::Render::Rect<float> v65; // [rsp+60h] [rbp-60h] BYREF
  Scaleform::GFx::Stream v66; // [rsp+70h] [rbp-50h] BYREF
  __int64 v67; // [rsp+2E0h] [rbp+220h]
  Scaleform::GFx::ShapeSwfReader *p_FileName; // [rsp+370h] [rbp+2B0h]
  Scaleform::GFx::LoadProcess *pa; // [rsp+378h] [rbp+2B8h]
  Scaleform::GFx::TagType tagTypea; // [rsp+380h] [rbp+2C0h]
  unsigned int v71; // [rsp+388h] [rbp+2C8h]
  int v72; // [rsp+390h] [rbp+2D0h]

  v67 = -2i64;
  *(_QWORD *)&v65.x2 = this->pAllocator;
  if ( !*(_QWORD *)&v65.x2 )
    *(_QWORD *)&v65.x2 = p->pLoadData.pObject->pPathAllocator;
  pAltStream = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  if ( !pAltStream )
    pAltStream = &p->ProcessInfo;
  this->Shape->Flags = 0;
  v9 = 0;
  v10 = v72;
  if ( (_BYTE)v72 )
  {
    v11 = pAltStream->Stream.FilePos + pAltStream->Stream.Pos - pAltStream->Stream.DataSize;
    this->Shape->Flags |= 0x10u;
    pr = 0i64;
    Scaleform::GFx::Stream::ReadRect(&pAltStream->Stream, &pr);
    this->Shape->vfptr[12].__vecDelDtor(this->Shape, (unsigned int)&pr);
    if ( ((tagType - 75) & 0xFFFFFFF7) != 0 )
    {
      this->Shape->vfptr[14].__vecDelDtor(this->Shape, (unsigned int)&pr);
    }
    else
    {
      v65 = 0i64;
      Scaleform::GFx::Stream::ReadRect(&pAltStream->Stream, &v65);
      this->Shape->vfptr[14].__vecDelDtor(this->Shape, (unsigned int)&v65);
      pAltStream->Stream.UnusedBits = 0;
      if ( (signed int)(pAltStream->Stream.DataSize - pAltStream->Stream.Pos) < 1 )
        Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 1);
      ++pAltStream->Stream.Pos;
    }
    Scaleform::GFx::ShapeSwfReader::ReadFillStyles(this, p, tagType);
    Scaleform::GFx::ShapeSwfReader::ReadStrokeStyles(this, p, tagType);
    v9 = pAltStream->Stream.FilePos + pAltStream->Stream.Pos - pAltStream->Stream.DataSize - v11;
  }
  LODWORD(v12) = lenInBytes - v9;
  pr.x1 = v12;
  *((float *)&bitcount + 1) = v12;
  v13 = (char *)Scaleform::GFx::PathAllocator::AllocMemoryBlock(
                  *(Scaleform::GFx::PathAllocator **)&v65.x2,
                  LODWORD(v12),
                  LODWORD(v12));
  v14 = v13;
  *(_QWORD *)&pr.x2 = v13;
  if ( !v13 )
  {
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogWarning(
      &pAltStream->Stream,
      "Corrupted shape detected in file %s",
      (const char *)((pAltStream->Stream.FileName.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12));
    return 0;
  }
  pAltStream->Stream.UnusedBits = 0;
  Scaleform::GFx::Stream::ReadToBuffer(&pAltStream->Stream, v13, LODWORD(v12));
  if ( tagTypea == Tag_DefineFont3 )
    this->Shape->Flags |= 2u;
  Scaleform::GFx::Stream::Stream(
    &v66,
    v14,
    LODWORD(v12),
    p->pLoadData.pObject->pHeap,
    pAltStream->Stream.pLog,
    pAltStream->Stream.pParseControl);
  p->pAltStream = &v66;
  v66.UnusedBits = 0;
  LODWORD(bitcount) = Scaleform::GFx::Stream::ReadUInt(&v66, 4u);
  LODWORD(v65.x1) = Scaleform::GFx::Stream::ReadUInt(&v66, 4u);
  if ( v10 )
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
      &v66,
      "  ShapeCharacter read: nfillbits = %d, nlinebits = %d\n");
  v16 = 0;
  LODWORD(v66.vfptr) = 0;
  LODWORD(v66.pLog) = 0;
  v17 = 0;
  oldSize = 0;
  v18 = 0;
  v71 = 0;
  v19 = 0;
  v62 = 0;
  v20 = 0;
  v72 = 0;
  v21 = 0;
  DataSize = v66.DataSize;
  Pos = v66.Pos;
  while ( 1 )
  {
    if ( v66.UnusedBits )
    {
      v25 = v66.UnusedBits - 1;
      v66.UnusedBits = v25;
      v26 = (unsigned __int8)v66.CurrentByte >> v25;
      v27 = ((1 << v25) - 1) & v66.CurrentByte;
    }
    else
    {
      v66.UnusedBits = 0;
      if ( (int)(DataSize - Pos) < 1 )
      {
        Scaleform::GFx::Stream::PopulateBuffer(&v66, 1);
        DataSize = v66.DataSize;
        Pos = v66.Pos;
      }
      v24 = (unsigned __int8)v66.pBuffer[Pos++];
      v66.Pos = Pos;
      v66.CurrentByte = v24;
      v25 = 7;
      v66.UnusedBits = 7;
      v26 = v24 >> 7;
      v27 = v24 & 0x7F;
    }
    v66.CurrentByte = v27;
    if ( v26 )
    {
      if ( v25 )
      {
        v66.UnusedBits = v25 - 1;
        v46 = v27 >> (v25 - 1);
        v47 = ((1 << (v25 - 1)) - 1) & v27;
      }
      else
      {
        v66.UnusedBits = 0;
        if ( (int)(DataSize - Pos) < 1 )
        {
          Scaleform::GFx::Stream::PopulateBuffer(&v66, 1);
          Pos = v66.Pos;
        }
        v45 = (unsigned __int8)v66.pBuffer[Pos];
        v66.Pos = Pos + 1;
        v66.CurrentByte = v45;
        v66.UnusedBits = 7;
        v46 = v45 >> 7;
        v47 = v45 & 0x7F;
      }
      v66.CurrentByte = v47;
      v62 = v19 + 1;
      if ( v46 )
      {
        v54 = Scaleform::GFx::Stream::ReadUInt(&v66, 4u) + 2;
        v55 = 0;
        if ( Scaleform::GFx::Stream::ReadUInt1(&v66) )
        {
          v16 = Scaleform::GFx::Stream::ReadUInt(&v66, v54);
          v56 = 1 << (v54 - 1);
          if ( (v56 & v16) != 0 )
            v16 |= -1 << v54;
          v55 = Scaleform::GFx::Stream::ReadUInt(&v66, v54);
          if ( (v56 & v55) != 0 )
            v55 |= -1 << v54;
          v18 = v71;
        }
        else if ( Scaleform::GFx::Stream::ReadUInt1(&v66) )
        {
          v55 = Scaleform::GFx::Stream::ReadUInt(&v66, v54);
          if ( _bittest((const int *)&v55, (unsigned __int8)(v54 - 1)) )
            v55 |= -1 << v54;
        }
        else
        {
          v16 = Scaleform::GFx::Stream::ReadUInt(&v66, v54);
          if ( _bittest((const int *)&v16, (unsigned __int8)(v54 - 1)) )
            v16 |= -1 << v54;
        }
        if ( (v66.ParseFlags & 0x10) != 0 )
          Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
            &v66,
            "  ShapeCharacter read: straight edge = %4g %4g - %4g %4g\n");
        v17 += v16;
        v18 += v55;
      }
      else
      {
        v48 = Scaleform::GFx::Stream::ReadUInt(&v66, 4u) + 2;
        v49 = Scaleform::GFx::Stream::ReadUInt(&v66, v48);
        v50 = 1 << (v48 - 1);
        if ( (v50 & v49) != 0 )
          v49 |= -1 << v48;
        v51 = Scaleform::GFx::Stream::ReadUInt(&v66, v48);
        if ( (v50 & v51) != 0 )
          v51 |= -1 << v48;
        v52 = Scaleform::GFx::Stream::ReadUInt(&v66, v48);
        if ( (v50 & v52) != 0 )
          v52 |= -1 << v48;
        v53 = Scaleform::GFx::Stream::ReadUInt(&v66, v48);
        if ( (v50 & v53) != 0 )
          v53 |= -1 << v48;
        if ( (v66.ParseFlags & 0x10) != 0 )
          Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
            &v66,
            "  ShapeCharacter read: curved edge   = %4g %4g - %4g %4g - %4g %4g\n");
        v17 = v52 + v49 + oldSize;
        v18 = v53 + v51 + v71;
      }
      v71 = v18;
      oldSize = v17;
      goto LABEL_106;
    }
    v28 = Scaleform::GFx::Stream::ReadUInt(&v66, 5u);
    v29 = v28;
    if ( !v28 )
      goto LABEL_110;
    if ( (v28 & 1) != 0 )
    {
      if ( v19 > 0 )
      {
        v19 = 0;
        v62 = 0;
        v72 = v20 + 1;
      }
      v30 = Scaleform::GFx::Stream::ReadUInt(&v66, 5u);
      v17 = Scaleform::GFx::Stream::ReadUInt(&v66, v30);
      oldSize = v17;
      v31 = 1 << (v30 - 1);
      if ( (v31 & v17) != 0 )
      {
        v17 |= -1 << v30;
        oldSize = v17;
      }
      v18 = Scaleform::GFx::Stream::ReadUInt(&v66, v30);
      v71 = v18;
      if ( (v31 & v18) != 0 )
      {
        v18 |= -1 << v30;
        v71 = v18;
      }
      if ( (v66.ParseFlags & 0x10) != 0 )
        Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(&v66, "  ShapeCharacter read: moveto %4g %4g\n");
      v20 = v72;
    }
    v32 = bitcount;
    if ( (v29 & 2) != 0 && (int)bitcount > 0 )
    {
      if ( v19 > 0 )
      {
        v19 = 0;
        v62 = 0;
        v72 = ++v20;
      }
      Scaleform::GFx::Stream::ReadUInt(&v66, bitcount);
      if ( (v66.ParseFlags & 0x10) != 0 )
        Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(&v66, "  ShapeCharacter read: fill0 = %d\n");
      v32 = bitcount;
    }
    if ( (v29 & 4) != 0 && v32 > 0 )
    {
      if ( v19 > 0 )
      {
        v19 = 0;
        v62 = 0;
        v72 = ++v20;
      }
      Scaleform::GFx::Stream::ReadUInt(&v66, v32);
      if ( (v66.ParseFlags & 0x10) != 0 )
        Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(&v66, "  ShapeCharacter read: fill1 = %d\n");
    }
    if ( (v29 & 8) != 0 && SLODWORD(v65.x1) > 0 )
    {
      if ( v19 > 0 )
      {
        v19 = 0;
        v62 = 0;
        v72 = ++v20;
      }
      Scaleform::GFx::Stream::ReadUInt(&v66, LODWORD(v65.x1));
      if ( (v66.ParseFlags & 0x10) != 0 )
        Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(&v66, "  ShapeCharacter read: line = %d\n");
    }
    if ( (v29 & 0x10) != 0 )
      break;
LABEL_106:
    DataSize = v66.DataSize;
    Pos = v66.Pos;
    v57 = v66.Pos + v66.FilePos - v66.DataSize;
    v21 = v57 > HIDWORD(bitcount);
    if ( v57 > HIDWORD(bitcount) )
      goto LABEL_110;
    v20 = v72;
    v19 = v62;
    v16 = 0;
  }
  Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(&v66, "  ShapeCharacter read: more fill styles\n");
  if ( v20 > 0 )
    v20 = 0;
  v72 = v20;
  if ( v19 > 0 )
  {
    v62 = 0;
    v72 = v20 + 1;
  }
  v33 = p_FileName;
  v66.vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::Stream>Vtbl *)p_FileName->FillStyles.Data.Size;
  v66.pLog = (Scaleform::Log *)p_FileName->StrokeStyles.Data.Size;
  v34 = v66.Pos + v66.FilePos - v66.DataSize;
  FillStyles = Scaleform::GFx::ShapeSwfReader::ReadFillStyles(p_FileName, pa, tagTypea);
  v36 = v66.Pos + v66.FilePos - v66.DataSize;
  StrokeStyles = Scaleform::GFx::ShapeSwfReader::ReadStrokeStyles(v33, pa, tagTypea);
  v38 = v66.Pos + v66.FilePos - v66.DataSize;
  if ( v36 == FillStyles )
  {
    v41 = *(_QWORD *)&pr.x2;
  }
  else
  {
    if ( FillStyles > v36 || (unsigned int)v36 > HIDWORD(bitcount) )
    {
      v21 = 1;
      goto LABEL_111;
    }
    vfptr = (int)v66.vfptr;
    v40 = SLODWORD(v33->FillStyles.Data.Size) <= SLODWORD(v66.vfptr);
    v41 = *(_QWORD *)&pr.x2;
    if ( !v40 )
    {
      *(_BYTE *)(v34 + *(_QWORD *)&pr.x2) = -1;
      *(_BYTE *)(v34 + v41 + 1) = BYTE2(vfptr);
      *(_BYTE *)(v34 + v41 + 2) = BYTE1(vfptr);
      *(_BYTE *)(v34 + v41 + 3) = vfptr;
      FillStyles = v34 + 4;
    }
    v42 = StrokeStyles - v36;
    memmove((void *)(v41 + FillStyles), (const void *)(v41 + v36), v42);
    StrokeStyles = FillStyles + v42;
    v36 = FillStyles;
  }
  if ( StrokeStyles == v38 )
    goto LABEL_73;
  if ( StrokeStyles <= v38 && (unsigned int)v38 <= HIDWORD(bitcount) )
  {
    pLog = (int)v66.pLog;
    if ( SLODWORD(p_FileName->StrokeStyles.Data.Size) > SLODWORD(v66.pLog) )
    {
      *(_BYTE *)(v36 + v41) = -1;
      *(_BYTE *)(v36 + v41 + 1) = BYTE2(pLog);
      *(_BYTE *)(v36 + v41 + 2) = BYTE1(pLog);
      *(_BYTE *)(v36 + v41 + 3) = pLog;
      StrokeStyles = v36 + 4;
    }
    x1 = pr.x1;
    memmove((void *)(v41 + StrokeStyles), (const void *)(v41 + v38), (unsigned int)(LODWORD(pr.x1) - v38));
    LODWORD(pr.x1) = StrokeStyles - v38 + LODWORD(x1);
LABEL_73:
    Scaleform::GFx::Stream::SetPosition(&v66, StrokeStyles);
    LODWORD(bitcount) = Scaleform::GFx::Stream::ReadUInt(&v66, 4u);
    LODWORD(v65.x1) = Scaleform::GFx::Stream::ReadUInt(&v66, 4u);
    v18 = v71;
    v17 = oldSize;
    goto LABEL_106;
  }
  v21 = 1;
LABEL_110:
  v33 = p_FileName;
LABEL_111:
  x1_low = LODWORD(pr.x1);
  if ( v21 || LODWORD(pr.x1) >= 0x200000 )
  {
    v21 = 1;
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogWarning(
      &v66,
      "Corrupted shape detected in file %s",
      (const char *)((*(_QWORD *)(bitcount + 48) & 0xFFFFFFFFFFFFFFFCui64) + 12));
    v59 = *(char **)&pr.x2;
    **(_WORD **)&pr.x2 = 0;
    if ( oldSize > 2 )
    {
      x1_low = 2;
      goto LABEL_117;
    }
  }
  else
  {
    v59 = *(char **)&pr.x2;
    if ( oldSize > LODWORD(pr.x1) )
LABEL_117:
      Scaleform::GFx::PathAllocator::ReallocLastBlock(*(Scaleform::GFx::PathAllocator **)&v65.x2, v59, oldSize, x1_low);
  }
  v33->Shape->Paths = v59;
  pa->pAltStream = 0i64;
  v60 = !v21;
  v66.vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::Stream>Vtbl *)&Scaleform::GFx::Stream::`vftable;
  p_FileName = (Scaleform::GFx::ShapeSwfReader *)&v66.FileName;
  if ( !_InterlockedDecrement((volatile signed __int32 *)((v66.FileName.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  if ( v66.pInput.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v66.pInput.pObject);
  return v60;
}

// File Line: 1233
// RVA: 0x8BD910
void __fastcall Scaleform::GFx::ShapeDataBase::ComputeBound(
        Scaleform::GFx::ShapeDataBase *this,
        Scaleform::Render::Rect<float> *r)
{
  Scaleform::RefCountImplCoreVtbl *vfptr; // rax
  Scaleform::RefCountImplCoreVtbl *v5; // rax
  float y1; // xmm1_4
  float x2; // xmm0_4
  float y2; // xmm1_4
  Scaleform::Render::Rect<float> bounds; // [rsp+30h] [rbp-39h] BYREF
  int v10[4]; // [rsp+40h] [rbp-29h] BYREF
  Scaleform::Render::ShapePosInfo pos; // [rsp+50h] [rbp-19h] BYREF
  float coord[6]; // [rsp+88h] [rbp+1Fh] BYREF
  Scaleform::Render::Matrix2x4<float> trans; // [rsp+A0h] [rbp+37h] BYREF

  vfptr = this->vfptr;
  *(_OWORD *)&trans.M[0][0] = _xmm;
  *(__m128 *)&trans.M[1][0] = _xmm;
  bounds = (Scaleform::Render::Rect<float>)_xmm_f149f2caf149f2ca7149f2ca7149f2ca;
  pos.Pos = ((__int64 (__fastcall *)(Scaleform::GFx::ShapeDataBase *))vfptr[6].__vecDelDtor)(this);
  v5 = this->vfptr;
  LODWORD(pos.Sfactor) = (_DWORD)FLOAT_1_0;
  memset(&pos.StartX, 0, 44);
  pos.Initialized = 0;
  if ( ((unsigned int (__fastcall *)(Scaleform::GFx::ShapeDataBase *, Scaleform::Render::ShapePosInfo *, float *, int *))v5[8].__vecDelDtor)(
         this,
         &pos,
         coord,
         v10) )
  {
    do
    {
      if ( (v10[0] == 0) == (v10[1] == 0) )
        this->vfptr[10].__vecDelDtor(this, (unsigned int)&pos);
      else
        Scaleform::Render::ExpandBoundsToPath<Scaleform::Render::Matrix2x4<float>>(this, &trans, &pos, coord, &bounds);
    }
    while ( ((unsigned int (__fastcall *)(Scaleform::GFx::ShapeDataBase *, Scaleform::Render::ShapePosInfo *, float *, int *))this->vfptr[8].__vecDelDtor)(
              this,
              &pos,
              coord,
              v10) );
  }
  y1 = bounds.y1;
  r->x1 = bounds.x1;
  x2 = bounds.x2;
  r->y1 = y1;
  y2 = bounds.y2;
  r->x2 = x2;
  r->y2 = y2;
}

// File Line: 1239
// RVA: 0x8C4E80
__int64 __fastcall Scaleform::GFx::ShapeDataBase::DefPointTestLocal(
        Scaleform::GFx::ShapeDataBase *this,
        Scaleform::Render::ShapeMeshProvider *pshapeMeshProvider,
        Scaleform::Render::Point<float> *pt,
        bool testShape,
        Scaleform::GFx::DisplayObjectBase *pinst)
{
  Scaleform::Render::Scale9GridInfo *v9; // rbx
  Scaleform::Render::Scale9GridInfo *v10; // rax
  Scaleform::Render::Rect<float> *v11; // rax
  float y2; // xmm3_4
  float x2; // xmm1_4
  float y1; // xmm4_4
  float x1; // xmm2_4
  float y; // xmm0_4
  Scaleform::Render::TransformerBase *p_trans; // rdx
  unsigned __int8 v18; // di
  Scaleform::Render::Rect<float> bounds; // [rsp+30h] [rbp-40h] BYREF
  void **v21; // [rsp+40h] [rbp-30h] BYREF
  Scaleform::Render::Scale9GridInfo *v22; // [rsp+48h] [rbp-28h]
  Scaleform::Render::TransformerBase trans; // [rsp+50h] [rbp-20h] BYREF
  Scaleform::Render::Matrix2x4<float> *v24; // [rsp+58h] [rbp-18h]
  Scaleform::Render::Rect<float> result; // [rsp+60h] [rbp-10h] BYREF

  v9 = 0i64;
  if ( pinst && (pinst->Flags & 1) != 0 )
  {
    Scaleform::GFx::DisplayObjectBase::CreateScale9Grid(pinst);
    v9 = v10;
  }
  pshapeMeshProvider->Scaleform::Render::MeshProvider_KeySupport::Scaleform::Render::MeshProvider_RCImpl::Scaleform::Render::MeshProvider::vfptr->GetIdentityBounds(
    &pshapeMeshProvider->Scaleform::Render::MeshProvider,
    &bounds);
  if ( v9 )
  {
    v11 = Scaleform::Render::Scale9GridInfo::AdjustBounds(v9, &result, &bounds);
    y2 = v11->y2;
    x2 = v11->x2;
    y1 = v11->y1;
    x1 = v11->x1;
    bounds.x1 = v11->x1;
    bounds.y1 = y1;
    bounds.x2 = x2;
    bounds.y2 = y2;
  }
  else
  {
    y2 = bounds.y2;
    x2 = bounds.x2;
    y1 = bounds.y1;
    x1 = bounds.x1;
  }
  if ( pt->x > x2 || pt->x < x1 || (y = pt->y, y > y2) || y < y1 )
  {
    v18 = 0;
  }
  else if ( testShape )
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
      p_trans = (Scaleform::Render::TransformerBase *)&v21;
    }
    else
    {
      *(_QWORD *)&result.x1 = &Scaleform::Render::TransformerWrapper<Scaleform::Render::Matrix2x4<float>>::`vftable;
      *(_QWORD *)&result.x2 = &Scaleform::Render::Matrix2x4<float>::Identity;
      v24 = &Scaleform::Render::Matrix2x4<float>::Identity;
      p_trans = &trans;
    }
    *(_QWORD *)&result.x1 = &Scaleform::Render::TransformerBase::`vftable;
    v18 = Scaleform::Render::HitTestFill<Scaleform::Render::TransformerBase>(this, p_trans, pt->x, pt->y);
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
__int64 __fastcall Scaleform::GFx::ShapeDataBase::ReadPathInfo(
        Scaleform::GFx::ShapeDataBase *this,
        Scaleform::Render::ShapePosInfo *pos,
        float *coord,
        unsigned int *styles)
{
  float v7; // xmm3_4
  unsigned int v8; // r9d
  char CurBitIndex; // r10
  int CurByteIndex; // r11d
  Scaleform::GFx::SwfShapeDecoder v12; // [rsp+28h] [rbp-30h] BYREF

  if ( (this->Flags & 2) != 0 )
    v7 = FLOAT_0_050000001;
  else
    v7 = *(float *)&FLOAT_1_0;
  Scaleform::GFx::SwfShapeDecoder::SwfShapeDecoder(&v12, pos, this->Paths, v7);
  v8 = 1;
  while ( 1 )
  {
    CurBitIndex = v12.Stream.CurBitIndex;
    CurByteIndex = v12.Stream.CurByteIndex;
    if ( ((unsigned __int8)(1 << (7 - LOBYTE(v12.Stream.CurBitIndex))) & v12.Stream.pData[v12.Stream.CurByteIndex]) != 0 )
      break;
    v8 = Scaleform::GFx::SwfShapeDecoder::ReadNonEdgeRec(&v12, v8);
    if ( !v8 )
    {
      CurBitIndex = v12.Stream.CurBitIndex;
      CurByteIndex = v12.Stream.CurByteIndex;
      goto LABEL_9;
    }
  }
  *styles = pos->Fill0;
  styles[1] = pos->Fill1;
  styles[2] = pos->Stroke;
  *coord = (float)pos->LastX * pos->Sfactor;
  coord[1] = (float)pos->LastY * pos->Sfactor;
LABEL_9:
  v12.Pos->Pos = CurBitIndex & 7 | (8
                                  * (v12.Pos->NumStrokeBits & 0xF | (16
                                                                   * ((16 * CurByteIndex) | v12.Pos->NumFillBits & 0xF))));
  return v8;
}

// File Line: 1322
// RVA: 0x8FB3C0
__int64 __fastcall Scaleform::GFx::ShapeDataBase::ReadEdge(
        Scaleform::GFx::ShapeDataBase *this,
        Scaleform::Render::ShapePosInfo *pos,
        float *coord)
{
  float v5; // xmm3_4
  Scaleform::Render::PathEdgeType v6; // r9d
  Scaleform::GFx::SwfShapeDecoder::Edge edge; // [rsp+28h] [rbp-50h] BYREF
  Scaleform::GFx::SwfShapeDecoder v9; // [rsp+40h] [rbp-38h] BYREF

  if ( (this->Flags & 2) != 0 )
    v5 = FLOAT_0_050000001;
  else
    v5 = *(float *)&FLOAT_1_0;
  Scaleform::GFx::SwfShapeDecoder::SwfShapeDecoder(&v9, pos, this->Paths, v5);
  v6 = Edge_EndPath;
  if ( ((unsigned __int8)(1 << (7 - LOBYTE(v9.Stream.CurBitIndex))) & v9.Stream.pData[v9.Stream.CurByteIndex]) != 0 )
  {
    v6 = Scaleform::GFx::SwfShapeDecoder::ReadEdge(&v9, &edge);
    if ( v6 == Edge_QuadTo )
    {
      *coord = (float)edge.Cx * pos->Sfactor;
      coord[1] = (float)edge.Cy * pos->Sfactor;
      coord[2] = (float)edge.Ax * pos->Sfactor;
      coord[3] = (float)edge.Ay * pos->Sfactor;
    }
    else
    {
      *coord = (float)edge.Ax * pos->Sfactor;
      coord[1] = (float)edge.Ay * pos->Sfactor;
    }
  }
  v9.Pos->Pos = v9.Stream.CurBitIndex & 7 | (8
                                           * (v9.Pos->NumStrokeBits & 0xF | (16
                                                                           * ((16 * LODWORD(v9.Stream.CurByteIndex)) | v9.Pos->NumFillBits & 0xF))));
  return (unsigned int)v6;
}

// File Line: 1348
// RVA: 0x8F6350
_BOOL8 __fastcall Scaleform::GFx::ConstShapeNoStyles::Read(
        Scaleform::GFx::ConstShapeNoStyles *this,
        Scaleform::GFx::LoadProcess *p,
        Scaleform::GFx::TagType tagType,
        unsigned int lenInBytes,
        bool withStyle)
{
  Scaleform::GFx::PathAllocator *pPathAllocator; // r10
  bool v6; // bl
  Scaleform::GFx::ShapeSwfReader v8; // [rsp+40h] [rbp-40h] BYREF

  pPathAllocator = p->pLoadData.pObject->pPathAllocator;
  v8.Shape = this;
  v8.pAllocator = pPathAllocator;
  memset(&v8.FillStyles, 0, 48);
  v6 = Scaleform::GFx::ShapeSwfReader::Read(&v8, p, tagType, lenInBytes, withStyle);
  Scaleform::ArrayDataBase<Scaleform::Render::StrokeStyleType,Scaleform::AllocatorGH<Scaleform::Render::StrokeStyleType,259>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::Render::StrokeStyleType,Scaleform::AllocatorGH<Scaleform::Render::StrokeStyleType,259>,Scaleform::ArrayDefaultPolicy>(&v8.StrokeStyles.Data);
  Scaleform::ArrayDataBase<Scaleform::Render::FillStyleType,Scaleform::AllocatorGH<Scaleform::Render::FillStyleType,259>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::Render::FillStyleType,Scaleform::AllocatorGH<Scaleform::Render::FillStyleType,259>,Scaleform::ArrayDefaultPolicy>(&v8.FillStyles.Data);
  return v6;
}

// File Line: 1354
// RVA: 0x8BCAD0
Scaleform::GFx::ShapeDataBase *__fastcall Scaleform::GFx::ConstShapeNoStyles::Clone(
        Scaleform::GFx::ConstShapeNoStyles *this)
{
  Scaleform::GFx::ShapeDataBase *result; // rax
  int v3; // [rsp+48h] [rbp+10h] BYREF
  Scaleform::GFx::ShapeDataBase *v4; // [rsp+50h] [rbp+18h]

  v3 = 71;
  result = (Scaleform::GFx::ShapeDataBase *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::GFx::ConstShapeNoStyles *, __int64, int *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
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
  result->Paths = this->Paths;
  result->Flags = this->Flags;
  result->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::ConstShapeNoStyles::`vftable;
  return result;
}

// File Line: 1361
// RVA: 0x895200
void __fastcall Scaleform::GFx::ConstShapeWithStyles::ConstShapeWithStyles(
        Scaleform::GFx::ConstShapeWithStyles *this,
        Scaleform::GFx::ConstShapeWithStyles *o)
{
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
  *(_QWORD *)&this->RectBound.x1 = 0i64;
  *(_QWORD *)&this->RectBound.x2 = 0i64;
  *(_QWORD *)&this->Bound.x1 = 0i64;
  *(_QWORD *)&this->Bound.x2 = 0i64;
}

// File Line: 1369
// RVA: 0x8A37D0
void __fastcall Scaleform::GFx::ConstShapeWithStyles::~ConstShapeWithStyles(Scaleform::GFx::ConstShapeWithStyles *this)
{
  char *Styles; // rbx
  unsigned int v3; // esi
  unsigned int i; // edi
  Scaleform::Render::RenderBuffer *v5; // rcx
  Scaleform::Render::RenderBuffer *v6; // rcx
  Scaleform::Render::RenderBuffer *v7; // rcx

  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::ConstShapeWithStyles::`vftable;
  Styles = this->Styles;
  v3 = 0;
  for ( i = 0; i < this->FillStylesNum; Styles += 16 )
  {
    v5 = (Scaleform::Render::RenderBuffer *)*((_QWORD *)Styles + 1);
    if ( v5 )
      Scaleform::RefCountImpl::Release(v5);
    ++i;
  }
  if ( this->StrokeStylesNum )
  {
    do
    {
      v6 = (Scaleform::Render::RenderBuffer *)*((_QWORD *)Styles + 4);
      if ( v6 )
        Scaleform::RefCountImpl::Release(v6);
      v7 = (Scaleform::Render::RenderBuffer *)*((_QWORD *)Styles + 3);
      if ( v7 )
        Scaleform::RefCountImpl::Release(v7);
      ++v3;
      Styles += 40;
    }
    while ( v3 < this->StrokeStylesNum );
  }
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, this->Styles);
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
}

// File Line: 1384
// RVA: 0x8BCB80
void __fastcall Scaleform::GFx::ConstShapeWithStyles::Clone(Scaleform::GFx::ConstShapeWithStyles *this)
{
  Scaleform::GFx::ConstShapeWithStyles *v2; // rax
  int v3; // [rsp+48h] [rbp+10h] BYREF
  Scaleform::GFx::ConstShapeWithStyles *v4; // [rsp+50h] [rbp+18h]

  v3 = 71;
  v2 = (Scaleform::GFx::ConstShapeWithStyles *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::GFx::ConstShapeWithStyles *, __int64, int *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
                                                 Scaleform::Memory::pGlobalHeap,
                                                 this,
                                                 80i64,
                                                 &v3,
                                                 -2i64);
  v4 = v2;
  if ( v2 )
    Scaleform::GFx::ConstShapeWithStyles::ConstShapeWithStyles(v2, this);
}

// File Line: 1390
// RVA: 0x8D7CC0
void __fastcall Scaleform::GFx::ConstShapeWithStyles::GetFillStyle(
        Scaleform::GFx::ConstShapeWithStyles *this,
        unsigned int idx,
        Scaleform::Render::FillStyleType *p)
{
  char *v4; // rbx
  Scaleform::GFx::Resource *v5; // rcx
  Scaleform::Render::RenderBuffer *pObject; // rcx

  v4 = &this->Styles[16 * idx - 16];
  p->Color = *(_DWORD *)v4;
  v5 = (Scaleform::GFx::Resource *)*((_QWORD *)v4 + 1);
  if ( v5 )
    Scaleform::Render::RenderBuffer::AddRef(v5);
  pObject = (Scaleform::Render::RenderBuffer *)p->pFill.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  p->pFill.pObject = (Scaleform::Render::ComplexFill *)*((_QWORD *)v4 + 1);
}

// File Line: 1397
// RVA: 0x8DE760
void __fastcall Scaleform::GFx::ConstShapeWithStyles::GetStrokeStyle(
        Scaleform::GFx::ConstShapeWithStyles *this,
        unsigned int idx,
        Scaleform::Render::StrokeStyleType *p)
{
  Scaleform::Render::StrokeStyleType::operator=(
    p,
    (Scaleform::Render::StrokeStyleType *)&this->Styles[40 * idx - 40 + 16 * this->FillStylesNum]);
}

// File Line: 1403
// RVA: 0x8F6420
__int64 __fastcall Scaleform::GFx::ConstShapeWithStyles::Read(
        Scaleform::GFx::ConstShapeWithStyles *this,
        Scaleform::GFx::LoadProcess *p,
        Scaleform::GFx::TagType tagType,
        unsigned int lenInBytes,
        bool withStyle)
{
  Scaleform::GFx::PathAllocator *pPathAllocator; // r10
  unsigned int v8; // r15d
  unsigned __int8 v9; // si
  unsigned int Size; // r8d
  unsigned int v11; // ecx
  char *v12; // rsi
  unsigned int i; // edi
  Scaleform::Render::FillStyleType *v14; // rbx
  Scaleform::GFx::Resource *pObject; // rcx
  Scaleform::Render::StrokeStyleType *Data; // r14
  char *v17; // rbx
  Scaleform::GFx::Resource *v18; // rcx
  Scaleform::GFx::Resource *v19; // rcx
  unsigned __int64 v20; // rdi
  Scaleform::Render::FillStyleType *v21; // rdx
  Scaleform::Render::FillStyleType *v22; // rbx
  Scaleform::Render::RenderBuffer *v23; // rcx
  Scaleform::GFx::ShapeSwfReader v25; // [rsp+40h] [rbp-40h] BYREF

  pPathAllocator = p->pLoadData.pObject->pPathAllocator;
  v25.Shape = this;
  v25.pAllocator = pPathAllocator;
  v8 = 0;
  memset(&v25.FillStyles, 0, 48);
  if ( Scaleform::GFx::ShapeSwfReader::Read(&v25, p, tagType, lenInBytes, withStyle) )
  {
    Size = v25.FillStyles.Data.Size;
    this->FillStylesNum = v25.FillStyles.Data.Size;
    v11 = v25.StrokeStyles.Data.Size;
    this->StrokeStylesNum = v25.StrokeStyles.Data.Size;
    if ( Size || v11 )
    {
      v12 = (char *)p->pLoadData.pObject->pHeap->vfptr->Alloc(
                      p->pLoadData.pObject->pHeap,
                      16i64 * Size + 40i64 * v11,
                      0i64);
      this->Styles = v12;
      for ( i = 0; i < this->FillStylesNum; ++i )
      {
        v14 = &v25.FillStyles.Data.Data[i];
        if ( v12 )
        {
          *(_DWORD *)v12 = v14->Color;
          pObject = (Scaleform::GFx::Resource *)v14->pFill.pObject;
          if ( pObject )
            Scaleform::Render::RenderBuffer::AddRef(pObject);
          *((_QWORD *)v12 + 1) = v14->pFill.pObject;
        }
        v12 += 16;
      }
      if ( this->StrokeStylesNum )
      {
        do
        {
          Data = v25.StrokeStyles.Data.Data;
          v17 = &v12[40 * v8];
          if ( v17 )
          {
            *(float *)v17 = v25.StrokeStyles.Data.Data[v8].Width;
            *((_DWORD *)v17 + 1) = LODWORD(Data[v8].Units);
            *((_DWORD *)v17 + 2) = Data[v8].Flags;
            *((_DWORD *)v17 + 3) = LODWORD(Data[v8].Miter);
            *((_DWORD *)v17 + 4) = Data[v8].Color;
            v18 = (Scaleform::GFx::Resource *)Data[v8].pFill.pObject;
            if ( v18 )
              Scaleform::Render::RenderBuffer::AddRef(v18);
            *((_QWORD *)v17 + 3) = Data[v8].pFill.pObject;
            v19 = (Scaleform::GFx::Resource *)Data[v8].pDashes.pObject;
            if ( v19 )
              Scaleform::Render::RenderBuffer::AddRef(v19);
            *((_QWORD *)v17 + 4) = Data[v8].pDashes.pObject;
          }
          ++v8;
        }
        while ( v8 < this->StrokeStylesNum );
      }
    }
    else
    {
      this->Styles = 0i64;
    }
    v9 = 1;
  }
  else
  {
    v9 = 0;
  }
  Scaleform::ArrayDataBase<Scaleform::Render::StrokeStyleType,Scaleform::AllocatorGH<Scaleform::Render::StrokeStyleType,259>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::Render::StrokeStyleType,Scaleform::AllocatorGH<Scaleform::Render::StrokeStyleType,259>,Scaleform::ArrayDefaultPolicy>(&v25.StrokeStyles.Data);
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
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  return v9;
}form::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pG

// File Line: 1436
// RVA: 0x90C5B0
void __fastcall Scaleform::GFx::ConstShapeWithStyles::SetStyles(
        Scaleform::GFx::ConstShapeWithStyles *this,
        unsigned int fillStyleCount,
        Scaleform::Render::FillStyleType *fillStyles,
        unsigned int strokeStyleCount,
        Scaleform::Render::StrokeStyleType *strokeStyles)
{
  __int64 v5; // rbx
  __int64 v7; // rdi
  char *v9; // rbx
  unsigned int i; // esi
  Scaleform::Render::ComplexFill *pObject; // rcx
  Scaleform::Render::ComplexFill *v12; // rax
  __int64 v13; // rax
  __int64 v14; // rdi
  Scaleform::Render::RenderBuffer *v15; // rcx
  unsigned __int64 v16; // r15
  char *v17; // rdi
  char *v18; // rsi
  Scaleform::GFx::Resource *v19; // rcx
  Scaleform::GFx::Resource *v20; // rcx
  Scaleform::Render::ComplexFill *v21; // rax
  __int64 v22; // rax
  __int64 v23; // r14
  Scaleform::Render::RenderBuffer *v24; // rcx
  char *v25; // [rsp+20h] [rbp-48h]
  __int64 v26; // [rsp+28h] [rbp-40h]
  int v27; // [rsp+78h] [rbp+10h] BYREF

  v26 = -2i64;
  v5 = strokeStyleCount;
  v7 = fillStyleCount;
  if ( this->Styles )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  this->FillStylesNum = v7;
  this->StrokeStylesNum = v5;
  if ( (_DWORD)v7 || (_DWORD)v5 )
  {
    v9 = (char *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                   Scaleform::Memory::pGlobalHeap,
                   this,
                   16 * v7 + 40 * v5,
                   0i64);
    this->Styles = v9;
    v25 = v9;
    for ( i = 0; i < this->FillStylesNum; ++i )
    {
      if ( v9 )
      {
        *(_DWORD *)v9 = fillStyles[i].Color;
        pObject = fillStyles[i].pFill.pObject;
        if ( pObject )
          Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)pObject);
        *((_QWORD *)v9 + 1) = fillStyles[i].pFill.pObject;
      }
      if ( *((_QWORD *)v9 + 1) )
      {
        v27 = 71;
        v12 = (Scaleform::Render::ComplexFill *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::GFx::ConstShapeWithStyles *, __int64, int *, char *, __int64, char *))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
                                                  Scaleform::Memory::pGlobalHeap,
                                                  this,
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
    }
    v16 = 0i64;
    if ( this->StrokeStylesNum )
    {
      v17 = v9 + 4;
      v18 = (char *)((char *)strokeStyles - v9);
      do
      {
        if ( v17 != (char *)4 )
        {
          *((_DWORD *)v17 - 1) = *(_DWORD *)&v17[(_QWORD)v18 - 4];
          *(_DWORD *)v17 = *(_DWORD *)&v17[(_QWORD)v18];
          *((_DWORD *)v17 + 1) = *(_DWORD *)&v17[(_QWORD)v18 + 4];
          *((_DWORD *)v17 + 2) = *(_DWORD *)&v17[(_QWORD)v18 + 8];
          *((_DWORD *)v17 + 3) = *(_DWORD *)&v17[(_QWORD)v18 + 12];
          v19 = *(Scaleform::GFx::Resource **)&v17[(_QWORD)v18 + 20];
          if ( v19 )
            Scaleform::Render::RenderBuffer::AddRef(v19);
          *(_QWORD *)(v17 + 20) = *(_QWORD *)&v17[(_QWORD)v18 + 20];
          v20 = *(Scaleform::GFx::Resource **)&v17[(_QWORD)v18 + 28];
          if ( v20 )
            Scaleform::Render::RenderBuffer::AddRef(v20);
          *(_QWORD *)(v17 + 28) = *(_QWORD *)&v17[(_QWORD)v18 + 28];
        }
        if ( *((_QWORD *)v9 + 3) )
        {
          v27 = 71;
          v21 = (Scaleform::Render::ComplexFill *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::GFx::ConstShapeWithStyles *, __int64, int *, char *))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
                                                    Scaleform::Memory::pGlobalHeap,
                                                    this,
                                                    80i64,
                                                    &v27,
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
        v17 += 40;
      }
      while ( v16 < this->StrokeStylesNum );
    }
  }
  else
  {
    this->Styles = 0i64;
  }
}

// File Line: 1471
// RVA: 0x8B8140
void __fastcall Scaleform::GFx::ConstShapeWithStyles::BindResourcesInStyles(
        Scaleform::GFx::ConstShapeWithStyles *this,
        Scaleform::GFx::ResourceBinding *resourceBinding)
{
  Scaleform::GFx::ConstShapeWithStyles *v3; // rbp
  char *Styles; // r12
  Scaleform::GFx::Resource *v5; // rdi
  unsigned int i; // r15d
  char *v7; // r14
  __int64 v8; // rax
  unsigned int v9; // r8d
  Scaleform::GFx::ResourceBindData *v10; // rsi
  Scaleform::GFx::Resource *pObject; // rdi
  Scaleform::GFx::ResourceLibBase *pLib; // rcx
  Scaleform::GFx::ResourceVtbl *vfptr; // rsi
  __int64 v14; // rbp
  __int64 v15; // rcx
  Scaleform::Render::RenderBuffer *v16; // rcx
  unsigned __int64 v17; // r15
  Scaleform::Render::RenderBuffer **v18; // rsi
  Scaleform::Render::RenderBuffer *v19; // rax
  unsigned int v20; // r8d
  Scaleform::GFx::ResourceBindData *v21; // r14
  Scaleform::GFx::Resource *v22; // rdi
  Scaleform::GFx::ResourceLibBase *v23; // rcx
  Scaleform::GFx::ResourceVtbl *v24; // r14
  Scaleform::Render::RenderBuffer *v25; // rbp
  __int64 v26; // rcx
  Scaleform::GFx::Resource *v27; // rbx
  Scaleform::GFx::ResourceLibBase *v28; // rcx
  Scaleform::GFx::ResourceBindData pdata; // [rsp+28h] [rbp-40h] BYREF

  v3 = this;
  Styles = this->Styles;
  v5 = 0i64;
  pdata.pResource.pObject = 0i64;
  pdata.pBinding = 0i64;
  for ( i = 0; i < v3->FillStylesNum; ++i )
  {
    v7 = &Styles[16 * i];
    v8 = *((_QWORD *)v7 + 1);
    if ( v8 && *(_DWORD *)(v8 + 68) != -1 )
    {
      v9 = *(_DWORD *)(v8 + 68);
      if ( resourceBinding->Frozen && v9 < resourceBinding->ResourceCount )
      {
        v10 = &resourceBinding->pResources[v9];
        if ( v10->pResource.pObject )
          _InterlockedExchangeAdd(&v10->pResource.pObject->RefCount.Value, 1u);
        if ( pdata.pResource.pObject && !_InterlockedDecrement(&pdata.pResource.pObject->RefCount.Value) )
        {
          pObject = pdata.pResource.pObject;
          pLib = pdata.pResource.pObject->pLib;
          if ( pLib )
          {
            pLib->vfptr[1].__vecDelDtor(pLib, (unsigned int)pdata.pResource.pObject);
            pObject->pLib = 0i64;
          }
          pObject->vfptr->__vecDelDtor(pObject, 1u);
        }
        v5 = v10->pResource.pObject;
        pdata = *v10;
      }
      else
      {
        Scaleform::GFx::ResourceBinding::GetResourceData_Locked(resourceBinding, &pdata, v9);
        v5 = pdata.pResource.pObject;
      }
      if ( v5
        && (((__int64 (__fastcall *)(Scaleform::GFx::Resource *))v5->vfptr->GetResourceTypeCode)(v5) & 0xFF00) == 256 )
      {
        vfptr = v5[1].vfptr;
        v14 = *((_QWORD *)v7 + 1);
        if ( vfptr )
          (*((void (__fastcall **)(Scaleform::GFx::ResourceVtbl *))vfptr->__vecDelDtor + 1))(v5[1].vfptr);
        v15 = *(_QWORD *)(v14 + 16);
        if ( v15 )
          (*(void (__fastcall **)(__int64))(*(_QWORD *)v15 + 16i64))(v15);
        *(_QWORD *)(v14 + 16) = vfptr;
        *(_DWORD *)(*((_QWORD *)v7 + 1) + 68i64) = -1;
        v3 = this;
      }
      else
      {
        v16 = (Scaleform::Render::RenderBuffer *)*((_QWORD *)v7 + 1);
        if ( v16 )
          Scaleform::RefCountImpl::Release(v16);
        *((_QWORD *)v7 + 1) = 0i64;
        *(_DWORD *)v7 = -5776071;
      }
    }
  }
  v17 = 0i64;
  if ( v3->StrokeStylesNum )
  {
    v18 = (Scaleform::Render::RenderBuffer **)&Styles[16 * v3->FillStylesNum + 24];
    do
    {
      v19 = *v18;
      if ( *v18 && *((_DWORD *)&v19[1].Type + 1) != -1 )
      {
        v20 = *((_DWORD *)&v19[1].Type + 1);
        if ( resourceBinding->Frozen && v20 < resourceBinding->ResourceCount )
        {
          v21 = &resourceBinding->pResources[v20];
          if ( v21->pResource.pObject )
            _InterlockedExchangeAdd(&v21->pResource.pObject->RefCount.Value, 1u);
          if ( pdata.pResource.pObject && !_InterlockedDecrement(&pdata.pResource.pObject->RefCount.Value) )
          {
            v22 = pdata.pResource.pObject;
            v23 = pdata.pResource.pObject->pLib;
            if ( v23 )
            {
              v23->vfptr[1].__vecDelDtor(v23, (unsigned int)pdata.pResource.pObject);
              v22->pLib = 0i64;
            }
            v22->vfptr->__vecDelDtor(v22, 1u);
          }
          v5 = v21->pResource.pObject;
          pdata = *v21;
        }
        else
        {
          Scaleform::GFx::ResourceBinding::GetResourceData_Locked(resourceBinding, &pdata, v20);
          v5 = pdata.pResource.pObject;
        }
        if ( v5
          && (((__int64 (__fastcall *)(Scaleform::GFx::Resource *))v5->vfptr->GetResourceTypeCode)(v5) & 0xFF00) == 256 )
        {
          v24 = v5[1].vfptr;
          v25 = *v18;
          if ( v24 )
            (*((void (__fastcall **)(Scaleform::GFx::ResourceVtbl *))v24->__vecDelDtor + 1))(v5[1].vfptr);
          v26 = *(_QWORD *)&v25->Type;
          if ( v26 )
            (*(void (__fastcall **)(__int64))(*(_QWORD *)v26 + 16i64))(v26);
          *(_QWORD *)&v25->Type = v24;
          *((_DWORD *)&(*v18)[1].Type + 1) = -1;
          v3 = this;
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
      v28->vfptr[1].__vecDelDtor(v28, (unsigned int)pdata.pResource.pObject);
      v27->pLib = 0i64;
    }
    v27->vfptr->__vecDelDtor(v27, 1u);
  }
}

// File Line: 1517
// RVA: 0x89DCB0
void __fastcall Scaleform::GFx::SwfShapeCharacterDef::SwfShapeCharacterDef(
        Scaleform::GFx::SwfShapeCharacterDef *this,
        Scaleform::GFx::Resource *shp)
{
  Scaleform::Render::ShapeMeshProvider *v4; // rdi
  Scaleform::Render::ShapeMeshProvider *v5; // rax
  Scaleform::Render::ShapeMeshProvider *v6; // rax
  Scaleform::Render::ShapeMeshProvider *pObject; // rcx
  int v8; // [rsp+58h] [rbp+10h] BYREF
  Scaleform::Render::ShapeMeshProvider *v9; // [rsp+60h] [rbp+18h]

  this->vfptr = (Scaleform::GFx::ResourceVtbl *)&Scaleform::GFx::Resource::`vftable;
  this->RefCount.Value = 1;
  v4 = 0i64;
  this->pLib = 0i64;
  this->vfptr = (Scaleform::GFx::ResourceVtbl *)&Scaleform::GFx::CharacterDef::`vftable;
  this->Id.Id = 0x40000;
  this->vfptr = (Scaleform::GFx::ResourceVtbl *)&Scaleform::GFx::ShapeBaseCharacterDef::`vftable;
  this->pShapeMeshProvider.pObject = 0i64;
  this->vfptr = (Scaleform::GFx::ResourceVtbl *)&Scaleform::GFx::SwfShapeCharacterDef::`vftable;
  if ( shp )
    Scaleform::Render::RenderBuffer::AddRef(shp);
  this->pShape.pObject = (Scaleform::GFx::ShapeDataBase *)shp;
  v8 = 2;
  v5 = (Scaleform::Render::ShapeMeshProvider *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::GFx::SwfShapeCharacterDef *, __int64, int *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
                                                 Scaleform::Memory::pGlobalHeap,
                                                 this,
                                                 144i64,
                                                 &v8,
                                                 -2i64);
  v9 = v5;
  if ( v5 )
  {
    Scaleform::Render::ShapeMeshProvider::ShapeMeshProvider(v5, this->pShape.pObject, 0i64);
    v4 = v6;
  }
  pObject = this->pShapeMeshProvider.pObject;
  if ( pObject )
    pObject->Scaleform::Render::MeshProvider_KeySupport::Scaleform::Render::MeshProvider_RCImpl::Scaleform::Render::MeshProvider::vfptr->Release(&pObject->Scaleform::Render::MeshProvider);
  this->pShapeMeshProvider.pObject = v4;
}

// File Line: 1522
// RVA: 0x8D55B0
Scaleform::Render::Rect<float> *__fastcall Scaleform::GFx::SwfShapeCharacterDef::GetBoundsLocal(
        Scaleform::GFx::SwfShapeCharacterDef *this,
        Scaleform::Render::Rect<float> *result,
        float __formal)
{
  int *v5; // rax
  float v7; // [rsp+20h] [rbp-28h] BYREF
  float v8; // [rsp+24h] [rbp-24h]
  float v9; // [rsp+28h] [rbp-20h]
  float v10; // [rsp+2Ch] [rbp-1Ch]
  int v11[6]; // [rsp+30h] [rbp-18h] BYREF

  this->pShape.pObject->vfptr[11].__vecDelDtor(this->pShape.pObject, (unsigned int)&v7);
  if ( v7 >= v9 || v8 >= v10 )
  {
    v5 = (int *)this->pShapeMeshProvider.pObject->vfptr->GetIdentityBounds(
                  &this->pShapeMeshProvider.pObject->Scaleform::Render::MeshProvider,
                  v11);
  }
  else
  {
    *(float *)v11 = v7;
    *(float *)&v11[1] = v8;
    *(float *)&v11[2] = v9;
    v5 = v11;
    *(float *)&v11[3] = v10;
  }
  LODWORD(result->x1) = *v5;
  LODWORD(result->y1) = v5[1];
  *(_QWORD *)&result->x2 = *((_QWORD *)v5 + 1);
  return result;
}

// File Line: 1529
// RVA: 0x8DD560
Scaleform::Render::Rect<float> *__fastcall Scaleform::GFx::SwfShapeCharacterDef::GetRectBoundsLocal(
        Scaleform::GFx::SwfShapeCharacterDef *this,
        Scaleform::Render::Rect<float> *result,
        float mr)
{
  int *v5; // rax
  float v7; // [rsp+20h] [rbp-38h] BYREF
  float v8; // [rsp+24h] [rbp-34h]
  float v9; // [rsp+28h] [rbp-30h]
  float v10; // [rsp+2Ch] [rbp-2Ch]
  int v11[4]; // [rsp+30h] [rbp-28h] BYREF

  this->pShape.pObject->vfptr[13].__vecDelDtor(this->pShape.pObject, (unsigned int)&v7);
  if ( v7 >= v9 || v8 >= v10 )
  {
    v5 = (int *)((__int64 (__fastcall *)(Scaleform::GFx::SwfShapeCharacterDef *, int *))this->vfptr[1].GetResourceReport)(
                  this,
                  v11);
  }
  else
  {
    *(float *)v11 = v7;
    *(float *)&v11[1] = v8;
    *(float *)&v11[2] = v9;
    v5 = v11;
    *(float *)&v11[3] = v10;
  }
  LODWORD(result->x1) = *v5;
  LODWORD(result->y1) = v5[1];
  *(_QWORD *)&result->x2 = *((_QWORD *)v5 + 1);
  return result;
}

// File Line: 1535
// RVA: 0x8B84D0
Scaleform::Ptr<Scaleform::Render::ShapeMeshProvider> *__fastcall Scaleform::GFx::SwfShapeCharacterDef::BindResourcesInStyles(
        Scaleform::GFx::SwfShapeCharacterDef *this,
        Scaleform::Ptr<Scaleform::Render::ShapeMeshProvider> *result,
        Scaleform::GFx::ResourceBinding *resourceBinding)
{
  Scaleform::Render::ShapeMeshProvider *v6; // rbp
  Scaleform::Render::ShapeDataInterface *v7; // rsi
  Scaleform::Render::ShapeMeshProvider *v8; // rax
  Scaleform::Render::ShapeMeshProvider *v9; // rax
  int v11; // [rsp+88h] [rbp+20h] BYREF

  v6 = 0i64;
  v7 = (Scaleform::Render::ShapeDataInterface *)((__int64 (__fastcall *)(Scaleform::GFx::ShapeDataBase *))this->pShape.pObject->vfptr[16].__vecDelDtor)(this->pShape.pObject);
  v7->vfptr[17].__vecDelDtor(v7, (unsigned int)resourceBinding);
  v11 = 2;
  v8 = (Scaleform::Render::ShapeMeshProvider *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                                                 Scaleform::Memory::pGlobalHeap,
                                                 this,
                                                 144i64,
                                                 &v11);
  if ( v8 )
  {
    Scaleform::Render::ShapeMeshProvider::ShapeMeshProvider(v8, v7, 0i64);
    v6 = v9;
  }
  result->pObject = v6;
  Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v7);
  return result;
}

// File Line: 1544
// RVA: 0x897860
void __fastcall Scaleform::GFx::ImageShapeCharacterDef::ImageShapeCharacterDef(
        Scaleform::GFx::ImageShapeCharacterDef *this,
        Scaleform::GFx::ImageResource *pimage,
        Scaleform::GFx::ImageCreator *imgCreator,
        bool bilinear)
{
  Scaleform::Render::ShapeMeshProvider *v7; // r14
  Scaleform::Render::ShapeDataFloat *v8; // rax
  Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *v9; // rax
  Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *v10; // r15
  char *v11; // rsi
  Scaleform::Render::ImageBase *v12; // rbx
  Scaleform::MemoryHeap *v13; // rax
  __int64 v14; // rcx
  __int64 v15; // rcx
  __int64 v16; // rdi
  bool v17; // zf
  __int64 v18; // rdi
  float StartX; // xmm1_4
  Scaleform::Render::ShapeMeshProvider *v20; // rax
  __int64 v21; // rax
  __int64 v22; // rdi
  Scaleform::Render::RenderBuffer *pObject; // rcx
  Scaleform::Render::ShapeMeshProvider *v24; // rax
  Scaleform::Render::ShapeMeshProvider *v25; // rax
  Scaleform::Render::ShapeMeshProvider *v26; // rcx
  Scaleform::Render::Rect<float> pr; // [rsp+20h] [rbp-A8h] BYREF
  Scaleform::LogMessageId v28; // [rsp+30h] [rbp-98h] BYREF
  int v29; // [rsp+34h] [rbp-94h] BYREF
  int v30; // [rsp+38h] [rbp-90h] BYREF
  Scaleform::LogMessageId id; // [rsp+3Ch] [rbp-8Ch] BYREF
  Scaleform::LogMessageId v32; // [rsp+40h] [rbp-88h] BYREF
  char *v33; // [rsp+48h] [rbp-80h]
  Scaleform::Render::ShapeDataFloat *v34; // [rsp+50h] [rbp-78h] BYREF
  char *v35; // [rsp+58h] [rbp-70h] BYREF
  int v36[2]; // [rsp+60h] [rbp-68h] BYREF
  Scaleform::MemoryHeap *v37; // [rsp+68h] [rbp-60h]
  Scaleform::Render::Rect<float> r; // [rsp+70h] [rbp-58h] BYREF
  __int64 v39; // [rsp+80h] [rbp-48h]
  __int64 v40; // [rsp+88h] [rbp-40h]
  __int64 v41; // [rsp+90h] [rbp-38h]
  Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *v42; // [rsp+98h] [rbp-30h]
  Scaleform::Render::Matrix2x4<float> v43; // [rsp+A8h] [rbp-20h] BYREF
  __int64 v44; // [rsp+C8h] [rbp+0h]
  __int64 v45; // [rsp+D0h] [rbp+8h]
  __int64 v46; // [rsp+130h] [rbp+68h] BYREF
  char v47; // [rsp+140h] [rbp+78h]

  v45 = -2i64;
  this->vfptr = (Scaleform::GFx::ResourceVtbl *)&Scaleform::GFx::Resource::`vftable;
  this->RefCount.Value = 1;
  v7 = 0i64;
  this->pLib = 0i64;
  this->vfptr = (Scaleform::GFx::ResourceVtbl *)&Scaleform::GFx::CharacterDef::`vftable;
  this->Id.Id = 0x40000;
  this->vfptr = (Scaleform::GFx::ResourceVtbl *)&Scaleform::GFx::ShapeBaseCharacterDef::`vftable;
  this->pShapeMeshProvider.pObject = 0i64;
  this->vfptr = (Scaleform::GFx::ResourceVtbl *)&Scaleform::GFx::ImageShapeCharacterDef::`vftable;
  this->pShape.pObject = 0i64;
  LODWORD(v46) = 71;
  v8 = (Scaleform::Render::ShapeDataFloat *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                                              Scaleform::Memory::pGlobalHeap,
                                              this,
                                              128i64,
                                              &v46);
  v34 = v8;
  if ( v8 )
  {
    Scaleform::Render::ShapeDataFloat::ShapeDataFloat(v8);
    v10 = v9;
  }
  else
  {
    v10 = 0i64;
  }
  v42 = v10;
  v35 = 0i64;
  LODWORD(v34) = 71;
  v11 = (char *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(Scaleform::Memory::pGlobalHeap, this, 80i64, &v34);
  v33 = v11;
  if ( v11 )
  {
    *(_QWORD *)v11 = &Scaleform::RefCountImplCore::`vftable;
    *((_DWORD *)v11 + 2) = 1;
    *(_QWORD *)v11 = &Scaleform::RefCountImpl::`vftable;
    *(_QWORD *)v11 = &Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,71>::`vftable;
    *(_QWORD *)v11 = &Scaleform::RefCountBase<Scaleform::Render::ComplexFill,71>::`vftable;
    *(_QWORD *)v11 = &Scaleform::Render::ComplexFill::`vftable;
    *((_QWORD *)v11 + 2) = 0i64;
    *((_QWORD *)v11 + 3) = 0i64;
    *((_QWORD *)v11 + 4) = 1065353216i64;
    *((_QWORD *)v11 + 5) = 0i64;
    *((_DWORD *)v11 + 12) = 0;
    *(_QWORD *)(v11 + 52) = 1065353216i64;
    *((_DWORD *)v11 + 15) = 0;
    v11[64] = 0;
    *((_DWORD *)v11 + 17) = -1;
  }
  else
  {
    v11 = 0i64;
  }
  v35 = v11;
  if ( !pimage )
  {
    v32.Id = 135168;
    Scaleform::LogDebugMessage((Scaleform::LogMessageId)&v32, "Image is null in ImageShapeCharacterDef ctor.");
    goto LABEL_41;
  }
  v12 = 0i64;
  v33 = 0i64;
  if ( ((unsigned int (__fastcall *)(Scaleform::Render::ImageBase *))pimage->pImage->vfptr[3].__vecDelDtor)(pimage->pImage) )
  {
    v12 = pimage->pImage;
    if ( v12 )
      ((void (__fastcall *)(Scaleform::Render::ImageBase *))v12->vfptr[1].__vecDelDtor)(pimage->pImage);
    v33 = (char *)v12;
  }
  else if ( imgCreator )
  {
    v13 = Scaleform::Memory::pGlobalHeap->vfptr->GetAllocHeap(Scaleform::Memory::pGlobalHeap, this);
    v36[0] = 3;
    v37 = v13;
    LODWORD(r.x1) = 1;
    LODWORD(r.y1) = 1;
    *(_QWORD *)&r.x2 = 0i64;
    v39 = 0i64;
    v40 = 0i64;
    v41 = 0i64;
    v12 = (Scaleform::Render::ImageBase *)((__int64 (__fastcall *)(Scaleform::GFx::ImageCreator *, int *, Scaleform::Render::ImageBase *))imgCreator->vfptr[4].__vecDelDtor)(
                                            imgCreator,
                                            v36,
                                            pimage->pImage);
    v33 = (char *)v12;
  }
  else
  {
    id.Id = 135168;
    Scaleform::LogDebugMessage((Scaleform::LogMessageId)&id, "ImageCreator is null in ImageShapeCharacterDef ctor");
  }
  if ( v12 )
    ((void (__fastcall *)(Scaleform::Render::ImageBase *))v12->vfptr[1].__vecDelDtor)(v12);
  v14 = *((_QWORD *)v11 + 2);
  if ( v14 )
    (*(void (__fastcall **)(__int64))(*(_QWORD *)v14 + 16i64))(v14);
  *((_QWORD *)v11 + 2) = v12;
  if ( v12 )
  {
    *((_QWORD *)v11 + 4) = 1028443341i64;
    *((_QWORD *)v11 + 5) = 0i64;
    *((_DWORD *)v11 + 12) = 0;
    *(_QWORD *)(v11 + 52) = 1028443341i64;
    *((_DWORD *)v11 + 15) = 0;
    v11[64] = 1;
    if ( v47 )
      v11[64] = 3;
    v12->vfptr[6].__vecDelDtor(v12, (unsigned int)&v35);
    *(_OWORD *)&v43.M[0][0] = _xmm;
    *(__m128 *)&v43.M[1][0] = _xmm;
    v12->vfptr[14].__vecDelDtor(v12, (unsigned int)&v43);
    pr = 0i64;
    r.x1 = (float)(int)v35;
    r.y1 = (float)SHIDWORD(v35);
    r.x2 = (float)v36[0];
    r.y2 = (float)v36[1];
    Scaleform::Render::Matrix2x4<float>::EncloseTransform(&v43, &pr, &r);
    Scaleform::ArrayDataBase<Scaleform::Render::FillStyleType,Scaleform::AllocatorLH<Scaleform::Render::FillStyleType,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      &v10->Fills.Data,
      &v10->Fills,
      v10->Fills.Data.Size + 1);
    v15 = 16 * v10->Fills.Data.Size;
    v16 = (__int64)&v10->Fills.Data.Data[-1];
    v17 = v15 + v16 == 0;
    v18 = v15 + v16;
    v46 = v18;
    v33 = (char *)v18;
    if ( !v17 )
    {
      *(_DWORD *)v18 = (_DWORD)v34;
      Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)v11);
      *(_QWORD *)(v18 + 8) = v11;
    }
    Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::StartPath(
      v10,
      1u,
      0,
      0);
    Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::MoveTo(
      v10,
      0.0,
      0.0);
    Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::LineTo(
      v10,
      (float)(pr.x2 - pr.x1) * 20.0,
      0.0);
    Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::LineTo(
      v10,
      (float)(pr.x2 - pr.x1) * 20.0,
      (float)(pr.y2 - pr.y1) * 20.0);
    Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::LineTo(
      v10,
      0.0,
      (float)(pr.y2 - pr.y1) * 20.0);
    StartX = v10->StartX;
    if ( StartX != v10->LastX || v10->StartY != v10->LastY )
      Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::LineTo(
        v10,
        StartX,
        v10->StartY);
    Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::EndPath(v10);
    Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::EndShape(v10);
    v29 = 2;
    v20 = (Scaleform::Render::ShapeMeshProvider *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                                                    Scaleform::Memory::pGlobalHeap,
                                                    this,
                                                    144i64,
                                                    &v29);
    v46 = (__int64)v20;
    if ( v20 )
    {
      Scaleform::Render::ShapeMeshProvider::ShapeMeshProvider(v20, v10, 0i64);
      v22 = v21;
    }
    else
    {
      v22 = 0i64;
    }
    v44 = v22;
    Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)v10);
    pObject = (Scaleform::Render::RenderBuffer *)this->pShape.pObject;
    if ( pObject )
      Scaleform::RefCountImpl::Release(pObject);
    this->pShape.pObject = v10;
    v30 = 2;
    v24 = (Scaleform::Render::ShapeMeshProvider *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                                                    Scaleform::Memory::pGlobalHeap,
                                                    this,
                                                    144i64,
                                                    &v30);
    v46 = (__int64)v24;
    if ( v24 )
    {
      Scaleform::Render::ShapeMeshProvider::ShapeMeshProvider(v24, this->pShape.pObject, 0i64);
      v7 = v25;
    }
    v26 = this->pShapeMeshProvider.pObject;
    if ( v26 )
      v26->Scaleform::Render::MeshProvider_KeySupport::Scaleform::Render::MeshProvider_RCImpl::Scaleform::Render::MeshProvider::vfptr->Release(&v26->Scaleform::Render::MeshProvider);
    this->pShapeMeshProvider.pObject = v7;
    if ( v22 )
      (*(void (__fastcall **)(__int64))(*(_QWORD *)(v22 + 16) + 16i64))(v22 + 16);
    ((void (__fastcall *)(Scaleform::Render::ImageBase *))v12->vfptr[2].__vecDelDtor)(v12);
LABEL_41:
    if ( !v11 )
      goto LABEL_43;
    goto LABEL_42;
  }
  v28.Id = 135168;
  Scaleform::LogDebugMessage((Scaleform::LogMessageId)&v28, "Image is not created.");
LABEL_42:
  Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v11);
LABEL_43:
  if ( v10 )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v10);
}

// File Line: 1603
// RVA: 0x8C4DE0
char __fastcall Scaleform::GFx::ImageShapeCharacterDef::DefPointTestLocal(
        Scaleform::GFx::ImageShapeCharacterDef *this,
        Scaleform::Render::Point<float> *pt,
        __int64 testShape,
        Scaleform::GFx::DisplayObjectBase *pinst)
{
  char v6; // di
  float x; // xmm2_4
  float y; // xmm3_4
  int v10[6]; // [rsp+20h] [rbp-18h] BYREF

  v6 = testShape;
  ((void (__fastcall *)(Scaleform::Render::MeshProvider *, int *, __int64, Scaleform::GFx::DisplayObjectBase *))this->pShapeMeshProvider.pObject->vfptr->GetIdentityBounds)(
    &this->pShapeMeshProvider.pObject->Scaleform::Render::MeshProvider,
    v10,
    testShape,
    pinst);
  x = pt->x;
  if ( pt->x > *(float *)&v10[2] )
    return 0;
  if ( x < *(float *)v10 )
    return 0;
  y = pt->y;
  if ( y > *(float *)&v10[3] || y < *(float *)&v10[1] )
    return 0;
  if ( v6 )
    return Scaleform::Render::HitTestFill<Scaleform::Render::Matrix2x4<float>>(
             this->pShape.pObject,
             &Scaleform::Render::Matrix2x4<float>::Identity,
             x,
             y);
  return 1;
}

