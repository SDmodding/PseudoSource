// File Line: 59
// RVA: 0x9FE120
void __fastcall Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface>::DrawableCopyChannel(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *this, Scaleform::Render::Texture **tex, Scaleform::Render::Matrix2x4<float> *texgen, Scaleform::Render::Matrix4x4<float> *cxmul)
{
  ((void (__fastcall *)(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *, Scaleform::Render::Texture **, Scaleform::Render::Matrix2x4<float> *, Scaleform::Render::Matrix4x4<float> *))this->vfptr[55].__vecDelDtor)(
    this,
    tex,
    texgen,
    cxmul);
}

// File Line: 108
// RVA: 0x9FB3C0
void __fastcall Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface>::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface>(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *this, Scaleform::Render::ThreadCommandQueue *commandQueue)
{
  Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *v2; // rbx

  v2 = this;
  Scaleform::Render::HAL::HAL((Scaleform::Render::HAL *)&this->vfptr, commandQueue);
  v2->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface>::`vftable';
  v2->Shader.pVS = 0i64;
  v2->Shader.pVDesc = 0i64;
  v2->Shader.pFS = 0i64;
  v2->Shader.pFDesc = 0i64;
  v2->Shader.pVFormat = 0i64;
  Scaleform::Render::D3D1x::ShaderManager::ShaderManager(&v2->SManager, &v2->Profiler);
  v2->ShaderData.PrimitiveOpen = 0;
  v2->ShaderData.Textures[0] = 0i64;
  v2->ShaderData.Textures[1] = 0i64;
  v2->ShaderData.Textures[2] = 0i64;
  v2->ShaderData.Textures[3] = 0i64;
  *(_QWORD *)v2->ShaderData.UniformSet = 0i64;
  *(_QWORD *)&v2->ShaderData.UniformSet[8] = 0i64;
  *(_QWORD *)&v2->ShaderData.UniformSet[16] = 0i64;
  *(_WORD *)&v2->ShaderData.UniformSet[24] = 0;
  v2->ShaderData.pHal = (Scaleform::Render::D3D1x::HAL *)v2;
  v2->ShaderData.CurShaders.pVS = 0i64;
  v2->ShaderData.CurShaders.pVDesc = 0i64;
  v2->ShaderData.CurShaders.pFS = 0i64;
  v2->ShaderData.CurShaders.pFDesc = 0i64;
  v2->ShaderData.CurShaders.pVFormat = 0i64;
  v2->ShaderData.pLastVS = 0i64;
  v2->ShaderData.pLastFS = 0i64;
  v2->ShaderData.pLastDecl = 0i64;
  v2->MappedXY16iAlphaTexture[0] = 0i64;
  v2->MappedXY16iAlphaTexture[1] = 0i64;
  v2->MappedXY16iAlphaTexture[2] = 0i64;
  v2->MappedXY16iAlphaSolid[0] = 0i64;
  v2->MappedXY16iAlphaSolid[1] = 0i64;
  v2->MappedXY16iAlphaSolid[2] = 0i64;
}

// File Line: 115
// RVA: 0x9FCCC0
char __fastcall Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface>::BeginScene(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *this)
{
  Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *v1; // rbx
  char result; // al

  v1 = this;
  result = Scaleform::Render::HAL::BeginScene((Scaleform::Render::HAL *)&this->vfptr);
  if ( result )
  {
    _((AMD_HD3D *)&v1->SManager);
    Scaleform::Render::D3D1x::ShaderInterface::BeginScene(&v1->ShaderData);
    result = 1;
  }
  return result;
}

// File Line: 126
// RVA: 0x9FEC40
char __fastcall Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface>::EndScene(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *this)
{
  Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *v1; // rbx
  char result; // al

  v1 = this;
  result = Scaleform::Render::HAL::EndScene((Scaleform::Render::HAL *)&this->vfptr);
  if ( result )
  {
    _((AMD_HD3D *)&v1->SManager);
    result = 1;
  }
  return result;
}

// File Line: 136
// RVA: 0x9FEF50
signed __int64 __fastcall Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface>::GetMaximumBatchCount(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *this, Scaleform::Render::Primitive *prim)
{
  Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *v2; // r9
  signed __int64 result; // rax
  char v4; // dl
  Scaleform::Render::PrimitiveFill *v5; // r8
  unsigned int v6; // ebx
  Scaleform::Render::PrimitiveFillType v7; // ecx
  unsigned __int8 v8; // al

  v2 = this;
  if ( prim )
  {
    v5 = prim->pFill.pObject;
    v6 = 4;
    if ( prim->Meshes.Data.Data->M.pHandle->pHeader->Format & 0x10 )
      v6 = 6;
    if ( v5 )
    {
      v7 = v5->Data.Type;
      if ( (unsigned int)(v7 - 5) > 5 )
        v8 = 0;
      else
        v8 = ((unsigned int)(v7 - 9) <= 1) + 1;
      v6 += 2 * v8;
    }
    result = ((unsigned int (*)(void))v2->SManager.vfptr->GetNumberOfUniforms)() / v6;
    if ( (unsigned int)result > 0x18 )
      result = 24i64;
  }
  else
  {
    result = 1i64;
    v4 = `Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface>::GetMaximumBatchCount'::`6'::warned;
    if ( !`Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface>::GetMaximumBatchCount'::`6'::warned )
      v4 = 1;
    `Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface>::GetMaximumBatchCount'::`6'::warned = v4;
  }
  return result;
}

// File Line: 168
// RVA: 0xA053F0
void __fastcall Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface>::drawUncachedFilter(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *this, Scaleform::Render::HAL::FilterStackEntry *e)
{
  Scaleform::Render::HAL::FilterStackEntry *v2; // rbx
  Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *v3; // rdi
  unsigned int v4; // er13
  int v5; // er12
  int v6; // esi
  unsigned int v7; // er15
  Scaleform::Render::RenderTarget *v8; // rcx
  Scaleform::Render::RenderTarget *v9; // r8
  int v10; // edx
  __int64 v11; // rdx
  unsigned int v12; // er14
  Scaleform::Render::Filter *v13; // rbx
  signed int v14; // ecx
  __int64 v15; // rcx
  Scaleform::Render::RenderTarget *v16; // rbx
  unsigned int v17; // xmm3_4
  unsigned int v18; // xmm2_4
  float v19; // xmm1_4
  int v20; // ecx
  _OWORD *v21; // rax
  Scaleform::Render::RenderTarget *v22; // rbx
  Scaleform::Render::RenderTarget *v23; // rbx
  Scaleform::Render::RenderTarget *v24; // rcx
  Scaleform::Render::RenderTarget *v25; // rcx
  size_t v26; // rax
  Scaleform::Render::CacheablePrimitive **v27; // rbx
  char v28; // cl
  __int64 v29; // rdx
  Scaleform::Render::CacheablePrimitive *v30; // rbx
  Scaleform::Render::MatrixPoolImpl::DataHeader *v31; // rdx
  unsigned int v32; // eax
  bool v33; // bl
  unsigned int v34; // eax
  Scaleform::Render::RenderTarget **v35; // rbx
  signed __int64 v36; // rsi
  __int64 v37; // [rsp+30h] [rbp-D0h]
  __int64 v38; // [rsp+38h] [rbp-C8h]
  Scaleform::Render::RenderTarget *ptr; // [rsp+50h] [rbp-B0h]
  Scaleform::Render::RenderTarget *v40; // [rsp+58h] [rbp-A8h]
  Scaleform::Render::RenderTarget *v41; // [rsp+60h] [rbp-A0h]
  Scaleform::Render::RenderTarget *results; // [rsp+70h] [rbp-90h]
  Scaleform::Render::RenderTarget *v43; // [rsp+78h] [rbp-88h]
  Scaleform::Render::Filter *v44; // [rsp+80h] [rbp-80h]
  int v45; // [rsp+88h] [rbp-78h]
  int v46; // [rsp+8Ch] [rbp-74h]
  Scaleform::Render::Cxform *v47; // [rsp+90h] [rbp-70h]
  Scaleform::Render::FilterSet *v48; // [rsp+98h] [rbp-68h]
  unsigned int v49; // [rsp+A0h] [rbp-60h]
  int v50; // [rsp+A4h] [rbp-5Ch]
  Scaleform::Render::Matrix2x4<float> result; // [rsp+B0h] [rbp-50h]
  __int64 v52; // [rsp+D0h] [rbp-30h]
  Scaleform::Render::RenderTarget *v53; // [rsp+D8h] [rbp-28h]
  __int64 v54; // [rsp+E0h] [rbp-20h]
  __int16 v55; // [rsp+E8h] [rbp-18h]
  char v56; // [rsp+F0h] [rbp-10h]
  unsigned int passes; // [rsp+1B0h] [rbp+B0h]
  Scaleform::Render::CacheablePrimitive **v58; // [rsp+3D8h] [rbp+2D8h]
  char v59; // [rsp+3E0h] [rbp+2E0h]
  int v60; // [rsp+3E8h] [rbp+2E8h]

  v58 = (Scaleform::Render::CacheablePrimitive **)e;
  v52 = -2i64;
  v2 = e;
  v3 = this;
  v48 = e->pPrimitive.pObject->pFilters.pObject;
  v4 = BasicArrayImplementation<hkDataArrayImpl *>::getSize((BasicArrayImplementation<hkDataObjectImpl *> *)v48);
  v5 = 0;
  v44 = 0i64;
  v6 = 0;
  v7 = 0;
  if ( !v2->pPrimitive.pObject || !v2->pRenderTarget.pObject )
    return;
  `eh vector constructor iterator'(
    &ptr,
    8ui64,
    3,
    (void (__fastcall *)(void *))Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>);
  v8 = 0i64;
  ptr = 0i64;
  v40 = 0i64;
  v41 = 0i64;
  v9 = v2->pRenderTarget.pObject;
  v10 = v9->ViewRect.y2 - v9->ViewRect.y1;
  v45 = v9->ViewRect.x2 - v9->ViewRect.x1;
  v46 = v10;
  if ( v9 )
  {
    ((void (__fastcall *)(Scaleform::Render::RenderTarget *))v9->vfptr[1].__vecDelDtor)(v9);
    v8 = ptr;
  }
  if ( v8 )
    ((void (__cdecl *)(Scaleform::Render::RenderTarget *))v8->vfptr[2].__vecDelDtor)(v8);
  ptr = v2->pRenderTarget.pObject;
  ((void (__fastcall *)(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *))v3->vfptr[87].__vecDelDtor)(v3);
  v3->vfptr[78].__vecDelDtor((Scaleform::RefCountImplCore *)&v3->vfptr, 1u);
  Scaleform::Render::HAL::applyBlendMode((Scaleform::Render::HAL *)&v3->vfptr, 18i64, 1, 0);
  LOBYTE(v11) = 1;
  v3->vfptr[41].__vecDelDtor((Scaleform::RefCountImplCore *)&v3->vfptr, v11);
  v54 = 8i64;
  v55 = 0;
  `eh vector constructor iterator'(
    &v56,
    0x30ui64,
    3,
    (void (__fastcall *)(void *))Scaleform::Render::BlurFilterParams::BlurFilterParams);
  v12 = 0;
  v47 = &Scaleform::Render::Cxform::Identity;
  if ( v4 )
  {
    do
    {
      v13 = Scaleform::Render::FilterSet::GetFilter(v48, v12);
      v44 = v13;
      v7 = Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::GetFilterPasses(
             (Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture> *)&v3->SManager.vfptr,
             v13,
             v3->FillFlags,
             &passes);
      v59 = 0;
      v14 = v13->Type;
      if ( v14 >= 1 && v14 <= 5 )
      {
        v15 = (__int64)v41;
        if ( v41 )
        {
          v41->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v41->vfptr, 0);
          v15 = (__int64)v41;
        }
        if ( ptr )
        {
          ((void (__fastcall *)(Scaleform::Render::RenderTarget *))ptr->vfptr[1].__vecDelDtor)(ptr);
          v15 = (__int64)v41;
        }
        if ( v15 )
          (*(void (__cdecl **)(__int64))(*(_QWORD *)v15 + 16i64))(v15);
        v41 = ptr;
        v59 = 1;
      }
      v6 = 0;
      if ( v7 )
      {
        while ( 1 )
        {
          if ( v6 == v7 - 1 && v12 == v4 - 1 )
            goto LABEL_48;
          v16 = v40;
          if ( !v40 )
          {
            v16 = (Scaleform::Render::RenderTarget *)((__int64 (__fastcall *)(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *, int *, _QWORD))v3->vfptr[22].__vecDelDtor)(
                                                       v3,
                                                       &v45,
                                                       0i64);
            if ( v40 )
              ((void (__cdecl *)(Scaleform::Render::RenderTarget *))v40->vfptr[2].__vecDelDtor)(v40);
            v40 = v16;
            if ( !v16 )
              break;
          }
          *(float *)&v17 = (float)v16->ViewRect.y2;
          *(float *)&v18 = (float)v16->ViewRect.x2;
          v19 = (float)v16->ViewRect.y1;
          *(float *)&results = (float)v16->ViewRect.x1;
          *((float *)&results + 1) = v19;
          v43 = (Scaleform::Render::RenderTarget *)__PAIR__(v17, v18);
          v60 = 0;
          ((void (__fastcall *)(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *, Scaleform::Render::RenderTarget **, Scaleform::Render::RenderTarget *, _QWORD))v3->vfptr[24].__vecDelDtor)(
            v3,
            &results,
            v16,
            0i64);
          v20 = v16->BufferSize.Height;
          v49 = v16->BufferSize.Width;
          v50 = v20;
          v21 = (_OWORD *)v3->Matrices.pObject->vfptr[1].__vecDelDtor(
                            (Scaleform::RefCountImplCore *)&v3->Matrices.pObject->vfptr,
                            (unsigned int)&v49);
          *(_OWORD *)&result.M[0][0] = *v21;
          *(_OWORD *)&result.M[1][0] = v21[1];
          LODWORD(v38) = v7;
          LODWORD(v37) = v6;
          ((void (__fastcall *)(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *, Scaleform::Render::Matrix2x4<float> *, Scaleform::Render::Cxform *, Scaleform::Render::Filter *, Scaleform::Render::RenderTarget **, unsigned int *, __int64, __int64, Scaleform::Render::VertexFormat *, __int64 *))v3->vfptr[85].__vecDelDtor)(
            v3,
            &result,
            &Scaleform::Render::Cxform::Identity,
            v44,
            &ptr,
            &passes,
            v37,
            v38,
            v3->MappedXY16iAlphaTexture[1],
            &v54);
          if ( v59 && !v6 )
          {
            v22 = (Scaleform::Render::RenderTarget *)((__int64 (__fastcall *)(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *, int *, _QWORD))v3->vfptr[22].__vecDelDtor)(
                                                       v3,
                                                       &v45,
                                                       0i64);
            if ( ptr )
              ((void (*)(void))ptr->vfptr[2].__vecDelDtor)();
            ptr = v22;
            if ( !v22 )
            {
              v26 = MEMORY[0];
              v25 = 0i64;
              goto LABEL_45;
            }
          }
          v3->vfptr[25].__vecDelDtor((Scaleform::RefCountImplCore *)&v3->vfptr, 4u);
          v23 = ptr;
          if ( ptr )
          {
            ((void (__fastcall *)(Scaleform::Render::RenderTarget *))ptr->vfptr[1].__vecDelDtor)(ptr);
            v23 = ptr;
          }
          v53 = v23;
          v24 = v40;
          if ( v40 )
          {
            ((void (*)(void))v40->vfptr[1].__vecDelDtor)();
            v24 = v40;
          }
          if ( ptr )
          {
            ((void (__fastcall *)(Scaleform::Render::RenderTarget *))ptr->vfptr[2].__vecDelDtor)(ptr);
            v24 = v40;
          }
          ptr = v24;
          if ( v23 )
          {
            ((void (__fastcall *)(Scaleform::Render::RenderTarget *))v23->vfptr[1].__vecDelDtor)(v23);
            v24 = v40;
          }
          if ( v24 )
            ((void (*)(void))v24->vfptr[2].__vecDelDtor)();
          v40 = v23;
          if ( v23 )
            ((void (__fastcall *)(Scaleform::Render::RenderTarget *))v23->vfptr[2].__vecDelDtor)(v23);
          if ( ++v6 >= v7 )
            goto LABEL_48;
        }
        v25 = ptr;
        v26 = (size_t)ptr->vfptr;
LABEL_45:
        (*(void (__fastcall **)(Scaleform::Render::RenderTarget *, _QWORD))(v26 + 40))(v25, 0i64);
        if ( ptr )
          ((void (__cdecl *)(Scaleform::Render::RenderTarget *))ptr->vfptr[2].__vecDelDtor)(ptr);
        v12 = v4;
        ptr = 0i64;
      }
LABEL_48:
      ++v12;
    }
    while ( v12 < v4 );
  }
  if ( ptr
    && (((unsigned __int8 (__cdecl *)(Scaleform::Render::ProfileViews *))v3->Profiler.vfptr->IsFilterCachingEnabled)(&v3->Profiler)
     || v7 == 0) )
  {
    results = ptr;
    v43 = v41;
    LOBYTE(v5) = v7 == 0;
    v27 = v58;
    Scaleform::Render::CacheablePrimitive::SetCacheResults(
      *v58,
      (Scaleform::Render::CacheablePrimitive::CacheState)(v5 + 1),
      &results,
      2 - (v7 == 0));
    results->pRenderTargetData->CacheID = (unsigned __int64)*v58;
    if ( v43 )
      v43->pRenderTargetData->CacheID = (unsigned __int64)*v58;
  }
  else
  {
    v27 = v58;
    Scaleform::Render::CacheablePrimitive::SetCacheResults(*v58, 0, 0i64, 0);
  }
  v3->vfptr[25].__vecDelDtor((Scaleform::RefCountImplCore *)&v3->vfptr, 0);
  if ( v3->MaskStackTop )
  {
    v28 = (v3->HALState >> 6) & 1;
    if ( v3->StencilAvailable )
    {
      v29 = 5 - (unsigned int)(v28 != 0);
LABEL_60:
      v3->vfptr[78].__vecDelDtor((Scaleform::RefCountImplCore *)&v3->vfptr, v29);
      goto LABEL_61;
    }
    if ( v3->DepthBufferAvailable )
    {
      v29 = 7 - (unsigned int)(v28 != 0);
      goto LABEL_60;
    }
  }
LABEL_61:
  v3->vfptr[84].__vecDelDtor((Scaleform::RefCountImplCore *)&v3->vfptr, v3->CurrentSceneRasterMode);
  if ( v7 )
  {
    v30 = *v27;
    Scaleform::Render::operator*(
      &result,
      &v3->Matrices.pObject->UserView,
      (Scaleform::Render::Matrix2x4<float> *)&v30->PrimitiveArea.Data.Data->pHandle->pHeader[(unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[v30->PrimitiveArea.Data.Data->pHandle->pHeader->Format & 0xF].Offsets[4]
                                                                                           + 1]);
    v31 = v30->PrimitiveArea.Data.Data->pHandle->pHeader;
    if ( v31->Format & 1 )
      v47 = (Scaleform::Render::Cxform *)&v31[(unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[v31->Format & 0xF].Offsets[0]
                                            + 1];
    v32 = Scaleform::Render::HAL::getLastBlendModeOrDefault((Scaleform::Render::HAL *)&v3->vfptr);
    Scaleform::Render::HAL::applyBlendMode((Scaleform::Render::HAL *)&v3->vfptr, v32, 1, 1);
    LODWORD(v38) = v7;
    LODWORD(v37) = v6;
    ((void (__fastcall *)(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *, Scaleform::Render::Matrix2x4<float> *, Scaleform::Render::Cxform *, Scaleform::Render::Filter *, Scaleform::Render::RenderTarget **, unsigned int *, __int64, __int64, Scaleform::Render::VertexFormat *, __int64 *))v3->vfptr[85].__vecDelDtor)(
      v3,
      &result,
      v47,
      v44,
      &ptr,
      &passes,
      v37,
      v38,
      v3->MappedXY16iAlphaTexture[1],
      &v54);
    v33 = (v3->HALState >> 4) & 1;
    v34 = Scaleform::Render::HAL::getLastBlendModeOrDefault((Scaleform::Render::HAL *)&v3->vfptr);
    Scaleform::Render::HAL::applyBlendMode((Scaleform::Render::HAL *)&v3->vfptr, v34, 0, v33);
  }
  else
  {
    v3->vfptr[50].__vecDelDtor((Scaleform::RefCountImplCore *)&v3->vfptr, (unsigned int)*v27);
  }
  v35 = &ptr;
  v36 = 3i64;
  do
  {
    if ( *v35 )
      (*v35)->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)*v35, 0);
    ++v35;
    --v36;
  }
  while ( v36 );
  v3->AccumulatedStats.Filters += BasicArrayImplementation<hkDataArrayImpl *>::getSize((BasicArrayImplementation<hkDataObjectImpl *> *)v48);
  `eh vector destructor iterator'(
    &v56,
    0x30ui64,
    3,
    (void (__fastcall *)(void *))Scaleform::Render::BlurFilterParams::~BlurFilterParams);
  `eh vector destructor iterator'(
    &ptr,
    8ui64,
    3,
    (void (__fastcall *)(void *))ARefPtr<SSClassDescBase>::~ARefPtr<SSClassDescBase>);
}

// File Line: 341
// RVA: 0xA047A0
void __fastcall Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface>::drawCachedFilter(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *this, Scaleform::Render::FilterPrimitive *primitive)
{
  Scaleform::Render::FilterPrimitive *v2; // r14
  Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *v3; // rdi
  __int64 v4; // rdx
  int v5; // ecx
  signed int v6; // edx
  int v7; // edx
  Scaleform::Render::Texture *v8; // r12
  Scaleform::Render::MatrixPoolImpl::HMatrix *v9; // rbx
  float v10; // xmm5_4
  float v11; // xmm4_4
  float v12; // xmm3_4
  Scaleform::Render::MatrixPoolImpl::DataHeader *v13; // rdx
  Scaleform::Render::Cxform *v14; // r8
  char v15; // cl
  __int64 v16; // rdx
  unsigned int v17; // eax
  bool v18; // bl
  unsigned int v19; // eax
  Scaleform::Render::FilterSet *v20; // rbx
  int v21; // eax
  Scaleform::Render::Filter *v22; // rsi
  int v23; // er15
  Scaleform::Render::RenderTarget *v24; // rbx
  int v25; // ecx
  Scaleform::Render::RenderTarget *v26; // rbx
  __int64 v27; // rbx
  _OWORD *v28; // rax
  float *v29; // rbx
  signed __int64 v30; // rdi
  float v[2]; // [rsp+50h] [rbp-B0h]
  Scaleform::Render::RenderTarget *v32; // [rsp+58h] [rbp-A8h]
  __int64 v33; // [rsp+60h] [rbp-A0h]
  float v34; // [rsp+68h] [rbp-98h]
  float v35; // [rsp+6Ch] [rbp-94h]
  Scaleform::Render::Matrix2x4<float> result; // [rsp+70h] [rbp-90h]
  Scaleform::Render::VertexFormat *v37; // [rsp+90h] [rbp-70h]
  Scaleform::Render::RenderTarget *v38; // [rsp+A0h] [rbp-60h]
  __int64 v39; // [rsp+B0h] [rbp-50h]
  float v40; // [rsp+B8h] [rbp-48h]
  float v41; // [rsp+BCh] [rbp-44h]
  Scaleform::Render::RenderTarget *v42; // [rsp+C0h] [rbp-40h]
  __int64 v43; // [rsp+C8h] [rbp-38h]
  __int64 v44; // [rsp+D0h] [rbp-30h]
  __int64 v45; // [rsp+E0h] [rbp-20h]
  __int16 v46; // [rsp+E8h] [rbp-18h]
  char ptr; // [rsp+F0h] [rbp-10h]
  unsigned int passes; // [rsp+1B0h] [rbp+B0h]
  char v49; // [rsp+3E0h] [rbp+2E0h]
  int v50; // [rsp+3E8h] [rbp+2E8h]
  Scaleform::Render::RenderTarget *results; // [rsp+3F0h] [rbp+2F0h]
  Scaleform::Render::RenderTarget *v52; // [rsp+3F8h] [rbp+2F8h]

  v44 = -2i64;
  v2 = primitive;
  v3 = this;
  ((void (*)(void))this->vfptr[87].__vecDelDtor)();
  LOBYTE(v4) = 1;
  v3->vfptr[41].__vecDelDtor((Scaleform::RefCountImplCore *)&v3->vfptr, v4);
  v45 = 8i64;
  v46 = 0;
  `eh vector constructor iterator'(
    &ptr,
    0x30ui64,
    3,
    (void (__fastcall *)(void *))Scaleform::Render::BlurFilterParams::BlurFilterParams);
  if ( v2->Caching != 1 )
  {
    if ( v2->Caching != 2 )
      goto LABEL_41;
    v5 = v3->FillFlags | 0xC;
    if ( ((LOBYTE(v3->FillFlags) | 0xC) & 0xC) == 12 )
    {
      v6 = 257;
    }
    else
    {
      v6 = 1;
      if ( v5 & 8 )
        v6 = 17;
    }
    v7 = v6 + 2;
    if ( v5 & 1 )
      ++v7;
    if ( v5 & 2 )
      v7 += 64;
    if ( v5 & 0x10 )
      v7 += 8;
    Scaleform::Render::D3D1x::ShaderInterface::SetStaticShader(
      &v3->ShaderData,
      (Scaleform::Render::D3D1x::ShaderDesc::ShaderType)v7,
      v3->MappedXY16iAlphaTexture[1]);
    if ( !v3->ShaderData.PrimitiveOpen )
    {
      v3->ShaderData.PrimitiveOpen = 1;
      *(_QWORD *)v3->ShaderData.UniformSet = 0i64;
      *(_QWORD *)&v3->ShaderData.UniformSet[8] = 0i64;
      *(_QWORD *)&v3->ShaderData.UniformSet[16] = 0i64;
      *(_WORD *)&v3->ShaderData.UniformSet[24] = 0;
      v3->ShaderData.Textures[0] = 0i64;
      v3->ShaderData.Textures[1] = 0i64;
      v3->ShaderData.Textures[2] = 0i64;
      v3->ShaderData.Textures[3] = 0i64;
    }
    Scaleform::Render::CacheablePrimitive::GetCacheResults(
      (Scaleform::Render::CacheablePrimitive *)&v2->vfptr,
      &results,
      1u);
    v8 = (Scaleform::Render::Texture *)((__int64 (__cdecl *)(Scaleform::Render::RenderTarget *))results->vfptr[3].__vecDelDtor)(results);
    v9 = v2->PrimitiveArea.Data.Data;
    Scaleform::Render::operator*(
      &result,
      &v3->Matrices.pObject->UserView,
      (Scaleform::Render::Matrix2x4<float> *)&v9->pHandle->pHeader[(unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[v9->pHandle->pHeader->Format & 0xF].Offsets[4]
                                                                 + 1]);
    v10 = (float)results->ViewRect.y1;
    v11 = (float)results->ViewRect.x1;
    v12 = (float)(results->ViewRect.y2 - results->ViewRect.y1) / (float)(signed int)v8->ImgSize.Height;
    v[0] = (float)(results->ViewRect.x2 - results->ViewRect.x1) / (float)(signed int)v8->ImgSize.Width;
    v[1] = v[0] * 0.0;
    *(float *)&v32 = v[0] * 0.0;
    *((float *)&v32 + 1) = v11 * v[0];
    *(float *)&v33 = v12 * 0.0;
    *((float *)&v33 + 1) = v12;
    v34 = v12 * 0.0;
    v35 = v10 * v12;
    v13 = v9->pHandle->pHeader;
    if ( v13->Format & 1 )
      v14 = (Scaleform::Render::Cxform *)&v13[(unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[v13->Format & 0xF].Offsets[0]
                                            + 1];
    else
      v14 = &Scaleform::Render::Cxform::Identity;
    Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetCxform(
      (Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair> *)v3->ShaderData.UniformData,
      &v3->ShaderData.CurShaders,
      v14,
      0,
      0);
    Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUniform(
      (Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair> *)v3->ShaderData.UniformData,
      &v3->ShaderData.CurShaders,
      0xDu,
      (const float *)&result,
      8u,
      0,
      0);
    Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUniform(
      (Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair> *)v3->ShaderData.UniformData,
      &v3->ShaderData.CurShaders,
      0x15u,
      v,
      8u,
      0,
      0);
    *(_OWORD *)&result.M[0][0] = *(_OWORD *)&v3->ShaderData.CurShaders.pVS;
    *(_OWORD *)&result.M[1][0] = *(_OWORD *)&v3->ShaderData.CurShaders.pFS;
    v37 = v3->ShaderData.CurShaders.pVFormat;
    v49 = 3;
    Scaleform::Render::D3D1x::ShaderInterface::SetTexture(
      &v3->ShaderData,
      (Scaleform::Render::D3D1x::ShaderPair *)&result,
      0x14u,
      v8,
      (Scaleform::Render::ImageFillMode)&v49,
      0);
    Scaleform::Render::D3D1x::ShaderInterface::Finish(&v3->ShaderData, 1u);
    v3->vfptr[84].__vecDelDtor((Scaleform::RefCountImplCore *)&v3->vfptr, v3->CurrentSceneRasterMode);
    if ( !v3->MaskStackTop )
      goto LABEL_24;
    v15 = (v3->HALState >> 6) & 1;
    if ( v3->StencilAvailable )
    {
      v16 = 5 - (unsigned int)(v15 != 0);
    }
    else
    {
      if ( !v3->DepthBufferAvailable )
        goto LABEL_24;
      v16 = 7 - (unsigned int)(v15 != 0);
    }
    v3->vfptr[78].__vecDelDtor((Scaleform::RefCountImplCore *)&v3->vfptr, v16);
LABEL_24:
    v17 = Scaleform::Render::HAL::getLastBlendModeOrDefault((Scaleform::Render::HAL *)&v3->vfptr);
    Scaleform::Render::HAL::applyBlendMode((Scaleform::Render::HAL *)&v3->vfptr, v17, 1, 1);
    ((void (__fastcall *)(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *))v3->vfptr[88].__vecDelDtor)(v3);
    ((void (__fastcall *)(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *, signed __int64, signed __int64))v3->vfptr[95].__vecDelDtor)(
      v3,
      6i64,
      1i64);
    v18 = (v3->HALState >> 4) & 1;
    v19 = Scaleform::Render::HAL::getLastBlendModeOrDefault((Scaleform::Render::HAL *)&v3->vfptr);
    Scaleform::Render::HAL::applyBlendMode((Scaleform::Render::HAL *)&v3->vfptr, v19, 0, v18);
    results->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)results, 2u);
    if ( !((unsigned __int8 (*)(void))v3->Profiler.vfptr->IsFilterCachingEnabled)() )
      Scaleform::Render::CacheablePrimitive::SetCacheResults(
        (Scaleform::Render::CacheablePrimitive *)&v2->vfptr,
        0,
        0i64,
        0);
    goto LABEL_41;
  }
  v20 = v2->pFilters.pObject;
  v21 = BasicArrayImplementation<hkDataArrayImpl *>::getSize((BasicArrayImplementation<hkDataObjectImpl *> *)v2->pFilters.pObject);
  v22 = Scaleform::Render::FilterSet::GetFilter(v20, (unsigned int)(v21 - 1));
  v23 = Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::GetFilterPasses(
          (Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture> *)&v3->SManager.vfptr,
          v22,
          v3->FillFlags,
          &passes);
  `eh vector constructor iterator'(
    v,
    8ui64,
    3,
    (void (__fastcall *)(void *))Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>);
  *(_QWORD *)v = 0i64;
  v32 = 0i64;
  v33 = 0i64;
  Scaleform::Render::CacheablePrimitive::GetCacheResults((Scaleform::Render::CacheablePrimitive *)&v2->vfptr, &v42, 2u);
  v24 = v42;
  if ( v42 )
    ((void (__fastcall *)(Scaleform::Render::RenderTarget *))v42->vfptr[1].__vecDelDtor)(v42);
  if ( *(_QWORD *)v )
    (*(void (__cdecl **)(_QWORD))(**(_QWORD **)v + 16i64))(*(_QWORD *)v);
  *(_QWORD *)v = v24;
  v25 = v24->ViewRect.y2 - v24->ViewRect.y1;
  LODWORD(results) = v24->ViewRect.x2 - v24->ViewRect.x1;
  HIDWORD(results) = v25;
  v26 = (Scaleform::Render::RenderTarget *)((__int64 (__fastcall *)(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *, Scaleform::Render::RenderTarget **, _QWORD))v3->vfptr[22].__vecDelDtor)(
                                             v3,
                                             &results,
                                             0i64);
  if ( v32 )
    ((void (__cdecl *)(Scaleform::Render::RenderTarget *))v32->vfptr[2].__vecDelDtor)(v32);
  v32 = v26;
  v27 = v43;
  if ( v43 )
    (*(void (__fastcall **)(__int64))(*(_QWORD *)v43 + 8i64))(v43);
  if ( v33 )
    (*(void (__cdecl **)(__int64))(*(_QWORD *)v33 + 16i64))(v33);
  v33 = v27;
  v50 = 0;
  v39 = 0i64;
  v40 = (float)(signed int)results;
  v41 = (float)SHIDWORD(results);
  ((void (__fastcall *)(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *, __int64 *, Scaleform::Render::RenderTarget *, _QWORD, int *))v3->vfptr[24].__vecDelDtor)(
    v3,
    &v39,
    v32,
    0i64,
    &v50);
  v52 = results;
  v28 = (_OWORD *)v3->Matrices.pObject->vfptr[1].__vecDelDtor(
                    (Scaleform::RefCountImplCore *)&v3->Matrices.pObject->vfptr,
                    (unsigned int)&v52);
  *(_OWORD *)&result.M[0][0] = *v28;
  *(_OWORD *)&result.M[1][0] = v28[1];
  Scaleform::Render::HAL::applyBlendMode((Scaleform::Render::HAL *)&v3->vfptr, 1i64, 1, 1);
  ((void (__fastcall *)(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *, Scaleform::Render::Matrix2x4<float> *, Scaleform::Render::Cxform *, Scaleform::Render::Filter *, float *, unsigned int *, int, int, Scaleform::Render::VertexFormat *, __int64 *))v3->vfptr[85].__vecDelDtor)(
    v3,
    &result,
    &Scaleform::Render::Cxform::Identity,
    v22,
    v,
    &passes,
    v23 - 1,
    v23,
    v3->MappedXY16iAlphaTexture[1],
    &v45);
  v3->vfptr[25].__vecDelDtor((Scaleform::RefCountImplCore *)&v3->vfptr, 0);
  v38 = v32;
  Scaleform::Render::CacheablePrimitive::SetCacheResults(
    (Scaleform::Render::CacheablePrimitive *)&v2->vfptr,
    Cache_Count,
    &v38,
    1u);
  v38->pRenderTargetData->CacheID = (unsigned __int64)v2;
  v3->vfptr[50].__vecDelDtor((Scaleform::RefCountImplCore *)&v3->vfptr, (unsigned int)v2);
  v29 = v;
  v30 = 3i64;
  do
  {
    if ( *(_QWORD *)v29 )
      (*(void (__fastcall **)(_QWORD, _QWORD))(**(_QWORD **)v29 + 40i64))(*(_QWORD *)v29, 0i64);
    v29 += 2;
    --v30;
  }
  while ( v30 );
  `eh vector destructor iterator'(
    v,
    8ui64,
    3,
    (void (__fastcall *)(void *))ARefPtr<SSClassDescBase>::~ARefPtr<SSClassDescBase>);
LABEL_41:
  `eh vector destructor iterator'(
    &ptr,
    0x30ui64,
    3,
    (void (__fastcall *)(void *))Scaleform::Render::BlurFilterParams::~BlurFilterParams);
}

// File Line: 451
// RVA: 0xA04EC0
void __fastcall Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface>::drawFilter(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *this, Scaleform::Render::Matrix2x4<float> *mvp, Scaleform::Render::Cxform *cx, Scaleform::Render::Filter *filter, Scaleform::Ptr<Scaleform::Render::RenderTarget> *targets, unsigned int *shaders, unsigned int pass, unsigned int passCount, Scaleform::Render::VertexFormat *pvf, Scaleform::Render::BlurFilterState *__formal)
{
  Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *v10; // rbx

  v10 = this;
  Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::SetFilterFill(
    (Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture> *)&this->SManager.vfptr,
    mvp,
    cx,
    filter,
    targets,
    shaders,
    pass,
    passCount,
    pvf,
    &this->ShaderData);
  ((void (__fastcall *)(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *))v10->vfptr[88].__vecDelDtor)(v10);
  ((void (__fastcall *)(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *, signed __int64, signed __int64))v10->vfptr[95].__vecDelDtor)(
    v10,
    6i64,
    1i64);
}

// File Line: 459
// RVA: 0x9FFEA0
void __fastcall Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface>::PushBlendMode(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *this, Scaleform::Render::BlendPrimitive *prim)
{
  Scaleform::Render::BlendPrimitive *v2; // rsi
  Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *v3; // rdi
  Scaleform::Render::BlendMode v4; // er15
  unsigned int v5; // er13
  Scaleform::ArrayLH<Scaleform::Render::HAL::BlendStackEntry,2,Scaleform::ArrayConstPolicy<0,8,1> > *v6; // r14
  signed __int64 v7; // rcx
  signed __int64 v8; // rbx
  bool v9; // zf
  __int64 v10; // rbx
  signed __int64 v11; // rbx
  Scaleform::Render::HAL::BlendStackEntry *v12; // r12
  Scaleform::Render::MatrixPoolImpl::DataHeader *v13; // r14
  int v14; // eax
  __int64 v15; // r15
  signed int v16; // ecx
  __int64 v17; // rax
  __int64 v18; // rcx
  __int64 v19; // rax
  int v20; // xmm2_4
  float v21; // xmm3_4
  float v22; // xmm1_4
  signed int v23; // ecx
  __int64 v24; // r14
  __int64 v25; // rcx
  Scaleform::Render::BlendMode v26; // eax
  int v27; // er8
  __int64 v28; // rdx
  signed __int64 v29; // rcx
  signed __int64 v30; // rbx
  __int64 v31; // rdx
  __int64 v32; // rcx
  int v33; // xmm2_4
  float v34; // xmm3_4
  float v35; // xmm1_4
  signed int v36; // eax
  int v37; // [rsp+40h] [rbp-30h]
  int v38; // [rsp+44h] [rbp-2Ch]
  float v39; // [rsp+48h] [rbp-28h]
  float v40; // [rsp+4Ch] [rbp-24h]
  Scaleform::Render::BlendPrimitive *v41; // [rsp+50h] [rbp-20h]
  __int64 v42; // [rsp+58h] [rbp-18h]
  __int64 v43; // [rsp+60h] [rbp-10h]
  __int16 v44; // [rsp+68h] [rbp-8h]
  __int64 v45; // [rsp+B0h] [rbp+40h]
  __int64 v46; // [rsp+C0h] [rbp+50h]

  v2 = prim;
  v3 = this;
  if ( !(this->HALState & 8) )
  {
    _((AMD_HD3D *)this);
    return;
  }
  v4 = prim->BlendModeValue;
  Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)prim);
  v41 = v2;
  v5 = 0;
  v42 = 0i64;
  v43 = 0i64;
  v44 = 0;
  v6 = &v3->BlendModeStack;
  Scaleform::ArrayDataBase<Scaleform::Render::HAL::BlendStackEntry,Scaleform::AllocatorLH<Scaleform::Render::HAL::BlendStackEntry,2>,Scaleform::ArrayConstPolicy<0,8,1>>::ResizeNoConstruct(
    (Scaleform::ArrayDataBase<Scaleform::Render::HAL::BlendStackEntry,Scaleform::AllocatorLH<Scaleform::Render::HAL::BlendStackEntry,2>,Scaleform::ArrayConstPolicy<0,8,1> > *)&v3->BlendModeStack.Data.Data,
    &v3->BlendModeStack,
    v3->BlendModeStack.Data.Size + 1);
  v7 = 32 * v3->BlendModeStack.Data.Size;
  v8 = (signed __int64)&v3->BlendModeStack.Data.Data[-1];
  v9 = v7 + v8 == 0;
  v10 = v7 + v8;
  v45 = v10;
  v46 = v10;
  if ( !v9 )
  {
    Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)v2);
    *(_QWORD *)v10 = v2;
    *(_QWORD *)(v10 + 8) = 0i64;
    *(_QWORD *)(v10 + 16) = 0i64;
    *(_WORD *)(v10 + 24) = 0;
  }
  if ( !(v3->HALState & 0x300) )
  {
    v11 = v3->BlendModeStack.Data.Size;
    v12 = v6->Data.Data;
    if ( !Scaleform::Render::BlendState::IsTargetAllocationNeededForBlendMode(v2->BlendModeValue) )
    {
      v26 = v2->BlendModeValue;
      if ( v26 == 11 || v26 == 12 )
      {
        v27 = v3->BlendModeStack.Data.Size - 1;
        v28 = v27;
        if ( v27 >= 0 )
        {
          v29 = (signed __int64)&v6->Data.Data[v27];
          do
          {
            if ( *(_DWORD *)(*(_QWORD *)v29 + 80i64) == 2 )
              break;
            --v27;
            v29 -= 32i64;
            --v28;
          }
          while ( v28 >= 0 );
        }
        if ( !`Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface>::PushBlendMode'::`26'::warned )
          `Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface>::PushBlendMode'::`26'::warned = v27 < 0;
        if ( v27 < 0 )
        {
          v4 = 19;
          *((_BYTE *)&v12[v11] - 7) = 1;
        }
        else
        {
          v30 = (signed __int64)&v6->Data.Data[v27];
          v31 = ***(_QWORD ***)(*(_QWORD *)v30 + 48i64);
          v32 = 16
              * (unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[*(_BYTE *)(v31 + 15) & 0xF].Offsets[4];
          v33 = *(_DWORD *)(v32 + v31 + 44);
          v34 = *(float *)(v32 + v31 + 44) + *(float *)(v32 + v31 + 36);
          v35 = *(float *)(v32 + v31 + 28) + *(float *)(v32 + v31 + 16);
          v37 = *(_DWORD *)(v32 + v31 + 28);
          v38 = v33;
          v39 = v35;
          v40 = v34;
          v36 = -16777216;
          if ( v2->MaskPresent )
            v36 = 0;
          LODWORD(v45) = v36;
          LOBYTE(v5) = *(_BYTE *)(v30 + 24) != 0;
          ((void (__fastcall *)(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *, int *, _QWORD, _QWORD, __int64 *))v3->vfptr[24].__vecDelDtor)(
            v3,
            &v37,
            *(_QWORD *)(v30 + 16),
            v5,
            &v45);
          *(_BYTE *)(v30 + 24) = 1;
        }
      }
      goto LABEL_31;
    }
    if ( v2->Caching == Cache_Mesh )
    {
      v13 = v12[v11 - 1].pPrimitive.pObject->PrimitiveArea.Data.Data->pHandle->pHeader;
      v14 = (unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[v13->Format & 0xF].Offsets[4];
      v15 = v14 * 16;
      v16 = (signed int)*((float *)&v13[v14 + 2].pHandle + 1);
      LODWORD(v45) = (signed int)*(float *)&v13[v14 + 1].pHandle;
      HIDWORD(v45) = v16;
      v17 = ((__int64 (__fastcall *)(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *, __int64 *, bool))v3->vfptr[22].__vecDelDtor)(
              v3,
              &v45,
              v2->MaskPresent);
      v18 = v17;
      v46 = v17;
      v19 = *((_QWORD *)&v12[v11] - 3);
      if ( v19 )
      {
        (*(void (__fastcall **)(_QWORD))(*(_QWORD *)v19 + 16i64))(*((_QWORD *)&v12[v11] - 3));
        v18 = v46;
      }
      *((_QWORD *)&v12[v11] - 3) = v18;
      if ( v18 )
      {
        v20 = *(_DWORD *)((char *)&v13[2].DataPageOffset + v15);
        v21 = *(float *)((char *)&v13[2].DataPageOffset + v15) + *(float *)((char *)&v13[2].pHandle + v15 + 4);
        v22 = *(float *)((char *)&v13[1].DataPageOffset + v15) + *(float *)((char *)&v13[1].pHandle + v15);
        v37 = *(_DWORD *)((char *)&v13[1].DataPageOffset + v15);
        v38 = v20;
        v39 = v22;
        v40 = v21;
        LODWORD(v45) = 0;
        ((void (__fastcall *)(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *, int *, __int64, _QWORD, __int64 *))v3->vfptr[24].__vecDelDtor)(
          v3,
          &v37,
          v18,
          0i64,
          &v45);
      }
      if ( v2->BlendModeValue == 2 )
      {
        v23 = (signed int)*(float *)((char *)&v13[2].pHandle + v15 + 4);
        LODWORD(v45) = (signed int)*(float *)((char *)&v13[1].pHandle + v15);
        HIDWORD(v45) = v23;
        v24 = ((__int64 (__fastcall *)(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *, __int64 *, _QWORD))v3->vfptr[22].__vecDelDtor)(
                v3,
                &v45,
                0i64);
        v25 = *((_QWORD *)&v12[v11] - 2);
        if ( v25 )
          (*(void (**)(void))(*(_QWORD *)v25 + 16i64))();
        *((_QWORD *)&v12[v11] - 2) = v24;
      }
      v4 = 1;
LABEL_31:
      Scaleform::Render::HAL::applyBlendMode(
        (Scaleform::Render::HAL *)&v3->vfptr,
        (unsigned int)v4,
        0,
        (v3->HALState >> 4) & 1);
      goto LABEL_32;
    }
    v3->HALState |= 0x200u;
    v3->CacheableIndex = v3->BlendModeStack.Data.Size - 1;
    *(_DWORD *)(((__int64 (__fastcall *)(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *))v3->vfptr[64].__vecDelDtor)(v3)
              + 48) = 1;
  }
LABEL_32:
  Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v2);
}

// File Line: 550
// RVA: 0x9FF4F0
void __fastcall Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface>::PopBlendMode(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *this)
{
  Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *v1; // r15
  unsigned __int64 v2; // rbx
  Scaleform::Render::HAL::BlendStackEntry *v3; // rdi
  Scaleform::GFx::Resource *v4; // rcx
  Scaleform::Render::BlendPrimitive *v5; // r14
  __int64 v6; // rcx
  __int64 v7; // r13
  __int64 v8; // rcx
  __int64 v9; // r12
  char v10; // di
  unsigned int v11; // eax
  unsigned int v12; // esi
  Scaleform::Render::BlendMode v13; // ebx
  __int64 v14; // rdi
  signed __int64 v15; // rdi
  Scaleform::Render::HAL::RenderTargetEntry *v16; // rbx
  Scaleform::Render::RenderTarget *v17; // rcx
  __int64 v18; // rsi
  Scaleform::Render::RenderTarget *v19; // rbx
  Scaleform::Render::Cxform *v20; // rax
  char v21; // cl
  signed __int64 v22; // rdx
  signed __int64 v23; // r13
  Scaleform::Render::HAL::RenderTargetEntry *v24; // rbx
  Scaleform::Render::RenderTarget *v25; // rcx
  __int64 v26; // r13
  unsigned int v27; // xmm1_4
  unsigned int v28; // xmm0_4
  __int64 v29; // rax
  Scaleform::RefCountImplCoreVtbl *v30; // r14
  __int64 v31; // rax
  float v32; // xmm4_4
  float v33; // xmm3_4
  unsigned int v34; // ecx
  Scaleform::RefCountImplCoreVtbl *v35; // r14
  __int64 v36; // rax
  signed __int64 v37; // rcx
  __int64 v38; // [rsp+20h] [rbp-B9h]
  Scaleform::Render::BlendMode mode; // [rsp+30h] [rbp-A9h]
  Scaleform::Render::CacheablePrimitive *v40; // [rsp+38h] [rbp-A1h]
  __int64 v41; // [rsp+40h] [rbp-99h]
  Scaleform::Render::RenderTarget *results; // [rsp+50h] [rbp-89h]
  unsigned __int64 v43; // [rsp+58h] [rbp-81h]
  __int128 v44; // [rsp+60h] [rbp-79h]
  __m128 v45; // [rsp+70h] [rbp-69h]
  __int64 v46; // [rsp+80h] [rbp-59h]
  __int64 v47; // [rsp+88h] [rbp-51h]
  Scaleform::Render::BlendPrimitive *v48; // [rsp+90h] [rbp-49h]
  __int64 v49; // [rsp+98h] [rbp-41h]
  __int64 v50; // [rsp+A0h] [rbp-39h]
  char v51; // [rsp+A8h] [rbp-31h]
  char v52; // [rsp+A9h] [rbp-30h]
  __int64 v53; // [rsp+B0h] [rbp-29h]
  __int64 v54; // [rsp+B8h] [rbp-21h]
  Scaleform::Render::Matrix2x4<float> result; // [rsp+C0h] [rbp-19h]
  bool v56; // [rsp+140h] [rbp+67h]
  Scaleform::Render::RenderTarget *v57; // [rsp+148h] [rbp+6Fh]
  __int64 v58; // [rsp+150h] [rbp+77h]
  Scaleform::Render::BlendMode v59; // [rsp+158h] [rbp+7Fh]

  v54 = -2i64;
  v1 = this;
  if ( !(this->HALState & 8) )
  {
    _((AMD_HD3D *)this);
    return;
  }
  v2 = this->BlendModeStack.Data.Size;
  v3 = this->BlendModeStack.Data.Data;
  v4 = (Scaleform::GFx::Resource *)v3[v2 - 1].pPrimitive.pObject;
  if ( v4 )
    Scaleform::Render::RenderBuffer::AddRef(v4);
  v5 = v3[v2 - 1].pPrimitive.pObject;
  v40 = (Scaleform::Render::CacheablePrimitive *)&v3[v2 - 1].pPrimitive.pObject->vfptr;
  v48 = v3[v2 - 1].pPrimitive.pObject;
  v6 = *((_QWORD *)&v3[v2] - 3);
  if ( v6 )
    (*(void (**)(void))(*(_QWORD *)v6 + 8i64))();
  v7 = *((_QWORD *)&v3[v2] - 3);
  v41 = *((_QWORD *)&v3[v2] - 3);
  v49 = *((_QWORD *)&v3[v2] - 3);
  v8 = *((_QWORD *)&v3[v2] - 2);
  if ( v8 )
    (*(void (**)(void))(*(_QWORD *)v8 + 8i64))();
  v9 = *((_QWORD *)&v3[v2] - 2);
  v50 = *((_QWORD *)&v3[v2] - 2);
  LOBYTE(v58) = *((_BYTE *)&v3[v2] - 8);
  v51 = v58;
  v10 = *((_BYTE *)&v3[v2] - 7);
  v52 = v10;
  Scaleform::ArrayData<Scaleform::Render::HAL::BlendStackEntry,Scaleform::AllocatorLH<Scaleform::Render::HAL::BlendStackEntry,2>,Scaleform::ArrayConstPolicy<0,8,1>>::Resize(
    &v1->BlendModeStack.Data,
    v1->BlendModeStack.Data.Size - 1);
  v11 = v1->HALState;
  if ( !_bittest((const signed int *)&v11, 8u)
    && (!(v11 & 0x300) || v1->CacheableIndex >= (signed int)v1->BlendModeStack.Data.Size) )
  {
    v12 = Scaleform::Render::HAL::getLastBlendModeOrDefault((Scaleform::Render::HAL *)&v1->vfptr);
    mode = v12;
    v56 = (v1->HALState & 0x300) != 0;
    v1->CacheableIndex = -1;
    v13 = v5->BlendModeValue;
    v59 = v13;
    if ( !Scaleform::Render::BlendState::IsTargetAllocationNeededForBlendMode(v13) )
    {
      if ( (unsigned int)(v13 - 11) <= 1 )
      {
        if ( v10 )
          v12 = 1;
        else
          v1->vfptr[25].__vecDelDtor((Scaleform::RefCountImplCore *)&v1->vfptr, 0);
      }
      goto LABEL_90;
    }
    v14 = 0i64;
    v47 = 0i64;
    v46 = 0i64;
    if ( v56 )
    {
      Scaleform::Render::CacheablePrimitive::GetCacheResults(
        (Scaleform::Render::CacheablePrimitive *)&v5->vfptr,
        &results,
        2u);
      v19 = results;
      if ( results )
        ((void (__fastcall *)(Scaleform::Render::RenderTarget *))results->vfptr[1].__vecDelDtor)(results);
      v18 = v43;
      if ( v43 )
        (*(void (__fastcall **)(unsigned __int64))(*(_QWORD *)v43 + 8i64))(v43);
      v46 = v18;
LABEL_70:
      Scaleform::Render::operator*(
        &result,
        &v1->Matrices.pObject->UserView,
        (Scaleform::Render::Matrix2x4<float> *)&v5->PrimitiveArea.Data.Data->pHandle->pHeader[(unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[v5->PrimitiveArea.Data.Data->pHandle->pHeader->Format & 0xF].Offsets[4]
                                                                                            + 1]);
      v44 = _xmm;
      v45 = _xmm;
      v32 = (float)v19->ViewRect.y1;
      *((float *)&v44 + 3) = (float)v19->ViewRect.x1;
      v45.m128_f32[3] = v32;
      v33 = (float)(v19->ViewRect.y2 - v19->ViewRect.y1) / (float)(signed int)v19->BufferSize.Height;
      *(float *)&v44 = (float)(v19->ViewRect.x2 - v19->ViewRect.x1) / (float)(signed int)v19->BufferSize.Width;
      *((float *)&v44 + 1) = *(float *)&v44 * 0.0;
      *((float *)&v44 + 2) = *(float *)&v44 * 0.0;
      *((float *)&v44 + 3) = *((float *)&v44 + 3) * *(float *)&v44;
      v45.m128_f32[0] = v33 * 0.0;
      v45.m128_f32[1] = v33;
      v45.m128_f32[2] = v33 * 0.0;
      v45.m128_f32[3] = v32 * v33;
      v34 = 16;
      if ( v59 == 2 )
        v34 = 2;
      Scaleform::Render::HAL::applyBlendMode((Scaleform::Render::HAL *)&v1->vfptr, v34, 1, (v1->HALState >> 4) & 1);
      v35 = v1->vfptr;
      v36 = ((__int64 (__fastcall *)(Scaleform::Render::RenderTarget *))v19->vfptr[3].__vecDelDtor)(v19);
      LODWORD(v38) = 0;
      ((void (__fastcall *)(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *, __int64, Scaleform::Render::Matrix2x4<float> *, __int128 *, __int64))v35[58].__vecDelDtor)(
        v1,
        v36,
        &result,
        &v44,
        v38);
      v37 = (signed __int64)&v1->Profiler;
      if ( v56 )
      {
        v5 = (Scaleform::Render::BlendPrimitive *)v40;
        if ( !(*(unsigned __int8 (**)(void))(*(_QWORD *)v37 + 32i64))() )
          Scaleform::Render::CacheablePrimitive::SetCacheResults(v40, 0, 0i64, 0);
      }
      else
      {
        v58 = (__int64)v19->pRenderTargetData;
        v5 = (Scaleform::Render::BlendPrimitive *)v40;
        if ( (*(unsigned __int8 (**)(void))(*(_QWORD *)v37 + 32i64))() )
        {
          v57 = v19;
          Scaleform::Render::CacheablePrimitive::SetCacheResults(v40, Cache_Count, &v57, 1u);
          *(_QWORD *)(v58 + 24) = v40;
        }
      }
      if ( v14 )
        (*(void (__fastcall **)(__int64, _QWORD))(*(_QWORD *)v14 + 40i64))(v14, 0i64);
      if ( v18 )
        (*(void (__fastcall **)(__int64, _QWORD))(*(_QWORD *)v18 + 40i64))(v18, 0i64);
      v19->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v19->vfptr, 2u);
      if ( v18 )
        (*(void (__fastcall **)(__int64))(*(_QWORD *)v18 + 16i64))(v18);
      ((void (__fastcall *)(Scaleform::Render::RenderTarget *))v19->vfptr[2].__vecDelDtor)(v19);
      if ( v14 )
        (*(void (__fastcall **)(__int64))(*(_QWORD *)v14 + 16i64))(v14);
      v12 = mode;
LABEL_90:
      if ( v56 )
      {
        *(_DWORD *)(((__int64 (__fastcall *)(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *))v1->vfptr[64].__vecDelDtor)(v1)
                  + 48) = 0;
        v1->HALState &= 0xFFFFFCFF;
      }
      Scaleform::Render::HAL::applyBlendMode((Scaleform::Render::HAL *)&v1->vfptr, v12, 0, (v1->HALState >> 4) & 1);
      goto LABEL_93;
    }
    v15 = v1->RenderTargetStack.Data.Size;
    v16 = v1->RenderTargetStack.Data.Data;
    v17 = v16[v15 - 1].pRenderTarget.pObject;
    if ( v17 )
      ((void (*)(void))v17->vfptr[1].__vecDelDtor)();
    v14 = (__int64)v16[v15 - 1].pRenderTarget.pObject;
    v47 = v14;
    if ( v9 )
      (*(void (__fastcall **)(__int64))(*(_QWORD *)v9 + 8i64))(v9);
    v18 = v9;
    v46 = v9;
    if ( v14 )
      (*(void (__fastcall **)(__int64))(*(_QWORD *)v14 + 8i64))(v14);
    v19 = (Scaleform::Render::RenderTarget *)v14;
    if ( v7 )
    {
      if ( v59 != 2 )
        goto LABEL_26;
      if ( v9 )
      {
        if ( !(_BYTE)v58 )
        {
          v20 = Scaleform::Render::MatrixPoolImpl::HMatrix::GetCxform(v5->PrimitiveArea.Data.Data);
          if ( Scaleform::Render::Cxform::operator==(v20, &Scaleform::Render::Cxform::Identity) )
          {
            v21 = 1;
            goto LABEL_27;
          }
        }
LABEL_26:
        v21 = 0;
LABEL_27:
        LOBYTE(v57) = v21;
        v22 = 4i64;
        if ( v21 )
          v22 = 0i64;
        v1->vfptr[25].__vecDelDtor((Scaleform::RefCountImplCore *)&v1->vfptr, v22);
        if ( !(_BYTE)v57 )
        {
          v23 = v1->RenderTargetStack.Data.Size;
          v24 = v1->RenderTargetStack.Data.Data;
          v25 = v24[v23 - 1].pRenderTarget.pObject;
          if ( v25 )
            ((void (*)(void))v25->vfptr[1].__vecDelDtor)();
          v26 = (__int64)v24[v23 - 1].pRenderTarget.pObject;
          v53 = v26;
          v19 = (Scaleform::Render::RenderTarget *)((__int64 (__fastcall *)(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *, signed __int64, _QWORD))v1->vfptr[22].__vecDelDtor)(
                                                     v1,
                                                     v14 + 40,
                                                     0i64);
          if ( v14 )
            (*(void (__fastcall **)(__int64))(*(_QWORD *)v14 + 16i64))(v14);
          if ( !v19 )
          {
            Scaleform::Render::HAL::applyBlendMode(
              (Scaleform::Render::HAL *)&v1->vfptr,
              (unsigned int)mode,
              0,
              (v1->HALState >> 4) & 1);
            if ( v26 )
              (*(void (__fastcall **)(__int64))(*(_QWORD *)v26 + 16i64))(v26);
            v7 = v41;
            goto LABEL_58;
          }
          *(float *)&v27 = (float)(v19->ViewRect.y2 - v19->ViewRect.y1);
          *(float *)&v28 = (float)(v19->ViewRect.x2 - v19->ViewRect.x1);
          LODWORD(v57) = 0;
          results = 0i64;
          v43 = __PAIR__(v27, v28);
          ((void (__fastcall *)(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *, Scaleform::Render::RenderTarget **, Scaleform::Render::RenderTarget *, _QWORD, Scaleform::Render::RenderTarget **))v1->vfptr[24].__vecDelDtor)(
            v1,
            &results,
            v19,
            0i64,
            &v57);
          if ( !`Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface>::PopBlendMode'::`22'::warned )
            `Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface>::PopBlendMode'::`22'::warned = v59 != 2 && (!v26 || !(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v26 + 24i64))(v26));
          if ( v26 && (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v26 + 24i64))(v26)
            || v9 && (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v9 + 24i64))(v9) )
          {
            Scaleform::Render::HAL::applyBlendMode((Scaleform::Render::HAL *)&v1->vfptr, 16i64, 0, 1);
            if ( v9 && (_BYTE)v58 )
            {
              v57 = (Scaleform::Render::RenderTarget *)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v9 + 24i64))(v9);
              v29 = 0i64;
            }
            else
            {
              v29 = 0i64;
              v57 = 0i64;
            }
            if ( v59 != 2 )
              v29 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v26 + 24i64))(v26);
            v58 = v29;
            v30 = v1->vfptr;
            v31 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v14 + 24i64))(v14);
            ((void (__fastcall *)(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *, Scaleform::Render::CacheablePrimitive *, __int64, __int64, Scaleform::Render::RenderTarget *))v30[86].__vecDelDtor)(
              v1,
              v40,
              v31,
              v58,
              v57);
            v5 = (Scaleform::Render::BlendPrimitive *)v40;
          }
          v1->vfptr[25].__vecDelDtor((Scaleform::RefCountImplCore *)&v1->vfptr, 0);
          if ( v26 )
            (*(void (__fastcall **)(__int64))(*(_QWORD *)v26 + 16i64))(v26);
          v7 = v41;
        }
        goto LABEL_70;
      }
    }
    Scaleform::Render::HAL::applyBlendMode(
      (Scaleform::Render::HAL *)&v1->vfptr,
      (unsigned int)mode,
      0,
      (v1->HALState >> 4) & 1);
LABEL_58:
    if ( v9 )
      (*(void (__fastcall **)(__int64))(*(_QWORD *)v9 + 16i64))(v9);
    if ( v19 )
      ((void (__fastcall *)(Scaleform::Render::RenderTarget *))v19->vfptr[2].__vecDelDtor)(v19);
    if ( v14 )
      (*(void (__fastcall **)(__int64))(*(_QWORD *)v14 + 16i64))(v14);
  }
LABEL_93:
  if ( v9 )
    (*(void (__fastcall **)(__int64))(*(_QWORD *)v9 + 16i64))(v9);
  if ( v7 )
    (*(void (__fastcall **)(__int64))(*(_QWORD *)v7 + 16i64))(v7);
  if ( v5 )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v5);
}

// File Line: 704
// RVA: 0xA043D0
void __fastcall Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface>::drawBlendPrimitive(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *this, Scaleform::Render::BlendPrimitive *prim, Scaleform::Render::Texture *blendSource, Scaleform::Render::Texture *blendDest, Scaleform::Render::Texture *blendAlpha)
{
  Scaleform::Render::Texture *v5; // rdi
  Scaleform::Render::Texture *v6; // r14
  Scaleform::Render::BlendPrimitive *v7; // rsi
  Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *v8; // rbx
  Scaleform::Render::RenderTarget *v9; // r11
  int v10; // er9
  char *v11; // rax
  Scaleform::Render::MatrixPoolImpl::HMatrix *v12; // r8
  Scaleform::Render::MatrixPoolImpl::DataHeader *v13; // rdx
  Scaleform::Render::Cxform *v14; // rax
  Scaleform::Render::MatrixPoolImpl::DataHeader *v15; // r15
  __int64 v16; // r12
  float v17; // xmm5_4
  float v18; // xmm7_4
  float v19; // xmm3_4
  float v20; // xmm3_4
  float v21; // xmm5_4
  float v22; // xmm6_4
  float v23; // xmm3_4
  char texgen[40]; // [rsp+40h] [rbp-98h]
  char v25[24]; // [rsp+68h] [rbp-70h]
  __int128 v26; // [rsp+80h] [rbp-58h]
  int v27; // [rsp+90h] [rbp-48h]
  int v28; // [rsp+94h] [rbp-44h]
  Scaleform::Render::Texture *ptextures; // [rsp+98h] [rbp-40h]
  Scaleform::Render::Texture *v30; // [rsp+A0h] [rbp-38h]
  signed int *v31; // [rsp+A8h] [rbp-30h]
  __int64 v32; // [rsp+B0h] [rbp-28h]
  Scaleform::Render::Cxform v33; // [rsp+B8h] [rbp-20h]
  Scaleform::Render::HAL::RenderTargetEntry v34; // [rsp+D8h] [rbp+0h]
  int v35; // [rsp+438h] [rbp+360h]
  int v36; // [rsp+43Ch] [rbp+364h]
  signed int *retaddr; // [rsp+458h] [rbp+380h]

  v32 = -2i64;
  v5 = blendDest;
  v6 = blendSource;
  v7 = prim;
  v8 = this;
  v9 = this->RenderTargetStack.Data.Data[this->RenderTargetStack.Data.Size - 1].pRenderTarget.pObject;
  v10 = v9->ViewRect.y2 - v9->ViewRect.y1;
  v35 = v9->ViewRect.x2 - v9->ViewRect.x1;
  v36 = v10;
  v11 = (char *)this->Matrices.pObject->vfptr[1].__vecDelDtor(
                  (Scaleform::RefCountImplCore *)this->Matrices.pObject,
                  (unsigned int)&v35);
  *(_QWORD *)&v25[16] = *(_QWORD *)v11;
  v26 = *(_OWORD *)(v11 + 8);
  v27 = *((_DWORD *)v11 + 6);
  v28 = *((_DWORD *)v11 + 7);
  v12 = v7->PrimitiveArea.Data.Data;
  v13 = v12->pHandle->pHeader;
  if ( v13->Format & 1 )
    v14 = (Scaleform::Render::Cxform *)&v13[(unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[v13->Format & 0xF].Offsets[0]
                                          + 1];
  else
    v14 = &Scaleform::Render::Cxform::Identity;
  *(_OWORD *)&v33.M[0][0] = *(_OWORD *)&v14->M[0][0];
  *(_OWORD *)&v33.M[1][0] = *(_OWORD *)&v14->M[1][0];
  *(__m128 *)&v25[8] = _xmm;
  *(_OWORD *)&texgen[24] = _xmm;
  *(__m128 *)v25 = _xmm;
  v15 = v12->pHandle->pHeader;
  v16 = (unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[v15->Format & 0xF].Offsets[4];
  v17 = *((float *)&v15[v16 + 2].pHandle + 1);
  v18 = *(float *)&v15[v16 + 1].pHandle;
  ptextures = v6;
  v30 = v5;
  v31 = retaddr;
  v19 = v17 / (float)(signed int)v6->ImgSize.Height;
  *(float *)texgen = v18 / (float)(signed int)v6->ImgSize.Width;
  *(float *)&texgen[4] = *(float *)texgen * 0.0;
  *(float *)&texgen[8] = *(float *)texgen * 0.0;
  *(float *)&texgen[12] = *(float *)texgen * 0.0;
  *(float *)&texgen[16] = v19 * 0.0;
  *(float *)&texgen[20] = v19;
  *(float *)&texgen[24] = v19 * 0.0;
  *(float *)&texgen[28] = v19 * 0.0;
  if ( retaddr )
  {
    v20 = v17 / (float)retaddr[13];
    *(float *)&texgen[24] = v18 / (float)retaddr[12];
    *(float *)&texgen[28] = *(float *)&texgen[24] * 0.0;
    *(float *)&texgen[32] = *(float *)&texgen[24] * 0.0;
    *(float *)&texgen[36] = *(float *)&texgen[24] * 0.0;
    *(float *)v25 = v20 * 0.0;
    *(float *)&v25[4] = v20;
    *(float *)&v25[8] = v20 * 0.0;
    *(float *)&v25[12] = v20 * 0.0;
  }
  if ( v5 )
  {
    v21 = v17 / (float)(signed int)v5->ImgSize.Height;
    *(float *)&texgen[32] = v18 / (float)(signed int)v5->ImgSize.Width;
    *(float *)&texgen[36] = *(float *)&texgen[32] * 0.0;
    *(float *)v25 = *(float *)&texgen[32] * 0.0;
    v22 = v21 * 0.0;
    *(float *)&v25[8] = v21 * 0.0;
    *(float *)&v25[12] = v21;
    *(float *)&v25[16] = v21 * 0.0;
    Scaleform::Render::HAL::RenderTargetEntry::RenderTargetEntry(
      &v34,
      &v8->RenderTargetStack.Data.Data[v8->RenderTargetStack.Data.Size - 1]);
    v23 = (float)(*(float *)&v15[v16 + 2].DataPageOffset - (float)v34.OldViewRect.y1)
        / (float)(signed int)v5->ImgSize.Height;
    *(float *)&v25[4] = (float)(*(float *)&texgen[32] * 0.0)
                      + (float)((float)(*(float *)&v15[v16 + 1].DataPageOffset - (float)v34.OldViewRect.x1)
                              / (float)(signed int)v5->ImgSize.Width);
    *(float *)&v25[20] = v22 + v23;
    retaddr = (signed int *)&v34.OldMatrixState;
    if ( v34.OldMatrixState.S3DImpl.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v34.OldMatrixState.S3DImpl.pObject);
    Scaleform::RefCountImplCore::~RefCountImplCore((Scaleform::RefCountImplCore *)&v34.OldMatrixState.vfptr);
    if ( v34.pRenderTarget.pObject )
      ((void (*)(void))v34.pRenderTarget.pObject->vfptr[2].__vecDelDtor)();
  }
  Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::SetBlendFill(
    (Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture> *)&v8->SManager.vfptr,
    v7->BlendModeValue,
    (Scaleform::Render::Matrix2x4<float> *)&v25[16],
    &v33,
    &ptextures,
    (Scaleform::Render::Matrix2x4<float> *)texgen,
    v8->MappedXY16iAlphaTexture[1],
    &v8->ShaderData);
  ((void (__fastcall *)(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *))v8->vfptr[75].__vecDelDtor)(v8);
}

// File Line: 740
// RVA: 0x9FDCE0
void __fastcall Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface>::DrawProcessedPrimitive(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *this, Scaleform::Render::Primitive *pprimitive, Scaleform::Render::PrimitiveBatch *pstart, Scaleform::Render::PrimitiveBatch *pend)
{
  Scaleform::Render::PrimitiveBatch *v4; // rdi
  Scaleform::Render::PrimitiveBatch *v5; // rbp
  Scaleform::Render::Primitive *v6; // r13
  Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *v7; // rbx
  void *v8; // rsi
  unsigned int v9; // er12
  Scaleform::Render::PrimitiveBatch *v10; // rax
  Scaleform::Render::MeshCacheItem *v11; // rdi
  __int64 v12; // r8
  unsigned int meshCount; // er15
  unsigned int v14; // edx
  Scaleform::Render::D3D1x::ShaderPair *v15; // r14
  Scaleform::Render::D3D1x::FragShader *v16; // rcx
  __int64 v17; // rdx
  __int64 v18; // rax
  __int64 v19; // r8
  __int64 v20; // rdx
  Scaleform::Render::RenderSync *v21; // rax
  Scaleform::Render::Fence *v22; // rax
  Scaleform::Render::Fence *v23; // rsi
  Scaleform::Render::Fence *v24; // rcx
  Scaleform::Render::MeshCacheListSet *v25; // rdx
  Scaleform::Render::MeshCache **v26; // rcx
  Scaleform::Render::MeshCacheListSet *v27; // rdx
  void *v28; // [rsp+50h] [rbp-48h]
  unsigned int fillFlags; // [rsp+A0h] [rbp+8h]
  Scaleform::Render::PrimitiveBatch *v30; // [rsp+B8h] [rbp+20h]

  v30 = pend;
  v4 = pend;
  v5 = pstart;
  v6 = pprimitive;
  v7 = this;
  v8 = this->vfptr[60].__vecDelDtor((Scaleform::RefCountImplCore *)this, 9u);
  v28 = v8;
  (*(void (__fastcall **)(void *, const char *))(*(_QWORD *)v8 + 16i64))(v8, "HAL::DrawProcessedPrimitive");
  if ( v7->HALState & 8 )
  {
    if ( LODWORD(v6->Meshes.Data.Size) )
    {
      if ( !v5 )
        v5 = v6->Batches.Root.pNext;
      v9 = 0;
      if ( v5 != v4 )
      {
        v10 = v30;
        do
        {
          v11 = v5->MeshNode.pMeshItem;
          v12 = v5->MeshIndex;
          meshCount = v5->MeshCount;
          if ( v11 )
          {
            v14 = v7->FillFlags;
            fillFlags = v7->FillFlags;
            if ( meshCount )
              fillFlags = v6->Meshes.Data.Data->M.pHandle->pHeader->Format & 0x10 | v14;
            if ( !v7->ShaderData.PrimitiveOpen )
            {
              v7->ShaderData.PrimitiveOpen = 1;
              *(_QWORD *)v7->ShaderData.UniformSet = 0i64;
              *(_QWORD *)&v7->ShaderData.UniformSet[8] = 0i64;
              *(_QWORD *)&v7->ShaderData.UniformSet[16] = 0i64;
              *(_WORD *)&v7->ShaderData.UniformSet[24] = 0;
              v7->ShaderData.Textures[0] = 0i64;
              v7->ShaderData.Textures[1] = 0i64;
              v7->ShaderData.Textures[2] = 0i64;
              v7->ShaderData.Textures[3] = 0i64;
            }
            v15 = Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::SetPrimitiveFill(
                    (Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture> *)&v7->SManager.vfptr,
                    v6->pFill.pObject,
                    &fillFlags,
                    v5->Type,
                    v5->pFormat,
                    meshCount,
                    v7->Matrices.pObject,
                    &v6->Meshes.Data.Data[v12],
                    &v7->ShaderData);
            v7->Profiler.vfptr->SetBatch(&v7->Profiler, (Scaleform::Render::HAL *)&v7->vfptr, v6, v9);
            if ( v5->Type == 2 )
              ((void (__fastcall *)(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *, _QWORD, _QWORD))v7->vfptr[94].__vecDelDtor)(
                v7,
                v5->MeshCount,
                v11->IndexCount);
            else
              ((void (__fastcall *)(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *))v7->vfptr[93].__vecDelDtor)(v7);
            Scaleform::Render::D3D1x::ShaderInterface::Finish(&v7->ShaderData, meshCount);
            if ( v7->HALState & 0x20 )
            {
              if ( v15->pVS )
              {
                v16 = v15->pFS;
                if ( v16 )
                {
                  if ( v15->pVS->pProg.pObject && v16->pProg.pObject && v15->pVFormat )
                  {
                    v17 = fillFlags >> 5;
                    LOBYTE(v17) = v17 & 1;
                    v7->vfptr[41].__vecDelDtor((Scaleform::RefCountImplCore *)&v7->vfptr, v17);
                    v18 = ((__int64 (__fastcall *)(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *, Scaleform::Render::PrimitiveBatch *, Scaleform::Render::MeshCacheItem *))v7->vfptr[90].__vecDelDtor)(
                            v7,
                            v5,
                            v11);
                    v19 = v11->VertexCount;
                    v20 = v11->IndexCount;
                    if ( v5->Type == 2 )
                      ((void (__fastcall *)(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *, __int64, __int64, _QWORD, __int64, _QWORD))v7->vfptr[97].__vecDelDtor)(
                        v7,
                        v20,
                        v19,
                        v5->MeshCount,
                        v18,
                        0i64);
                    else
                      ((void (__fastcall *)(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *, __int64, __int64, _QWORD, __int64, _QWORD))v7->vfptr[96].__vecDelDtor)(
                        v7,
                        v20,
                        v19,
                        v11->MeshCount,
                        v18,
                        0i64);
                  }
                }
              }
            }
            if ( ((__int64 (__fastcall *)(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *))v7->vfptr[65].__vecDelDtor)(v7) )
            {
              v21 = (Scaleform::Render::RenderSync *)((__int64 (__fastcall *)(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *))v7->vfptr[65].__vecDelDtor)(v7);
              v22 = Scaleform::Render::RenderSync::InsertFence(v21);
              v23 = v22;
              if ( v22 )
                ++v22->RefCount;
              v24 = v11->GPUFence.pObject;
              if ( v24 )
                Scaleform::Render::Fence::Release(v24);
              v11->GPUFence.pObject = v23;
            }
            v25 = v11->pCacheList;
            v11->pPrev->pNext = v11->pNext;
            v11->pNext->pPrev = v11->pPrev;
            v11->pPrev = (Scaleform::Render::MeshCacheItem *)-1i64;
            v11->pNext = (Scaleform::Render::MeshCacheItem *)-1i64;
            v26 = &v25->pCache + 3 * ((signed int)v11->ListType + 1i64);
            *v26 = (Scaleform::Render::MeshCache *)((char *)*v26 - v11->AllocSize);
            v27 = v11->pCacheList;
            v11->ListType = 2;
            v11->pNext = v27->Slots[2].Root.pNext;
            v11->pPrev = (Scaleform::Render::MeshCacheItem *)&v27->Slots[2];
            v27->Slots[2].Root.pNext->pPrev = v11;
            v27->Slots[2].Root.pNext = v11;
            v27->Slots[2].Size += v11->AllocSize;
            v10 = v30;
          }
          v5 = v5->pNext;
          ++v9;
        }
        while ( v5 != v10 );
        v8 = v28;
      }
    }
  }
  else
  {
    _((AMD_HD3D *)v7);
  }
  (*(void (__fastcall **)(void *))(*(_QWORD *)v8 + 24i64))(v8);
}hile ( v5 != v10 );
        v8 = v28;
      }
    }
  }
 

// File Line: 814
// RVA: 0x9FD220
void __fastcall Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface>::DrawProcessedComplexMeshes(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *this, Scaleform::Render::ComplexMesh *complexMesh, Scaleform::Render::StrideArray<Scaleform::Render::MatrixPoolImpl::HMatrix> *matrices)
{
  Scaleform::Render::StrideArray<Scaleform::Render::MatrixPoolImpl::HMatrix> *v3; // rsi
  Scaleform::Render::ComplexMesh *v4; // rbp
  Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *v5; // r14
  void *v6; // r12
  __int64 v7; // rdi
  unsigned int *v8; // r15
  unsigned __int64 v9; // rbx
  signed __int64 v10; // rdi
  Scaleform::Render::D3D1x::ShaderManager *v11; // rax
  Scaleform::Render::D3D1x::ShaderPair *v12; // r13
  signed __int64 v13; // r12
  __int64 v14; // rax
  unsigned int v15; // ebp
  unsigned int v16; // ebx
  int v17; // ebx
  __int64 v18; // rsi
  __int64 v19; // rbp
  __int64 v20; // rax
  Scaleform::Render::Cxform *v21; // r8
  Scaleform::Render::PrimitiveFillType v22; // eax
  Scaleform::Render::PrimitiveFillType v23; // esi
  unsigned int v24; // ebp
  Scaleform::Render::VertexFormat *v25; // rbx
  Scaleform::Render::D3D1x::ShaderDesc::ShaderType v26; // eax
  __int64 v27; // rdx
  unsigned int v28; // ebx
  signed int v29; // eax
  unsigned int v30; // ebp
  Scaleform::Render::Matrix2x4<float> *v31; // r8
  __int64 v32; // rax
  Scaleform::Render::MatrixPoolImpl::HMatrix *m2; // rbx
  Scaleform::Render::MatrixState *Matrices; // rcx
  unsigned int v35; // esi
  unsigned __int8 *v36; // rax
  float v37; // xmm0_4
  float v38; // xmm1_4
  float v39; // xmm2_4
  float v40; // xmm3_4
  Scaleform::Render::D3D1x::VertexShaderDesc *v41; // r11
  Scaleform::Render::D3D1x::BatchVar *v42; // rax
  char v43; // r10
  signed __int64 v44; // rdx
  Scaleform::Render::D3D1x::UniformVar *v45; // r9
  int v46; // er8
  __int64 v47; // r10
  signed __int64 v48; // rdx
  unsigned __int64 v49; // rcx
  Scaleform::Render::D3D1x::UniformVar *v50; // r9
  unsigned __int64 v51; // rcx
  Scaleform::Render::D3D1x::FragShaderDesc *v52; // r8
  Scaleform::Render::D3D1x::BatchVar *v53; // rax
  char v54; // r10
  signed __int64 v55; // rdx
  int v56; // er9
  __int64 v57; // r10
  signed __int64 v58; // rdx
  Scaleform::Render::D3D1x::UniformVar *v59; // r8
  unsigned __int64 v60; // rcx
  Scaleform::Render::D3D1x::UniformVar *v61; // r8
  unsigned __int64 v62; // rcx
  Scaleform::Render::D3D1x::UniformVar *v63; // rax
  __int64 v64; // rax
  Scaleform::Render::D3D1x::UniformVar *v65; // rcx
  __int64 v66; // rax
  Scaleform::Render::MatrixPoolImpl::DataHeader *v67; // rdx
  Scaleform::Render::Cxform *v68; // r8
  const float *v69; // rbx
  unsigned int v70; // esi
  unsigned int v71; // er12
  __int64 v72; // rbp
  signed __int64 v73; // r14
  unsigned int *v74; // r15
  __int64 v75; // rax
  Scaleform::Render::Texture *v76; // rbx
  bool v77; // si
  unsigned int v78; // ebx
  unsigned int v79; // eax
  bool v80; // cf
  Scaleform::Render::RenderSync *v81; // rax
  Scaleform::Render::Fence *v82; // rax
  Scaleform::Render::Fence *v83; // rbx
  Scaleform::Render::Fence *v84; // rcx
  __int64 v85; // rdx
  signed __int64 v86; // rcx
  __int64 v87; // rdx
  char v88; // [rsp+40h] [rbp-148h]
  bool v89; // [rsp+41h] [rbp-147h]
  unsigned int fillflags; // [rsp+44h] [rbp-144h]
  unsigned int v91; // [rsp+48h] [rbp-140h]
  unsigned int meshCount; // [rsp+4Ch] [rbp-13Ch]
  unsigned int batchType; // [rsp+50h] [rbp-138h]
  unsigned int v94; // [rsp+54h] [rbp-134h]
  unsigned int v95; // [rsp+58h] [rbp-130h]
  Scaleform::Render::MeshCacheItem *v96; // [rsp+60h] [rbp-128h]
  int v97; // [rsp+68h] [rbp-120h]
  int v98; // [rsp+6Ch] [rbp-11Ch]
  unsigned int v99; // [rsp+70h] [rbp-118h]
  unsigned int *v100; // [rsp+78h] [rbp-110h]
  unsigned __int64 v101; // [rsp+80h] [rbp-108h]
  __int64 v102; // [rsp+88h] [rbp-100h]
  __int64 v103; // [rsp+90h] [rbp-F8h]
  char v104; // [rsp+98h] [rbp-F0h]
  void *v105; // [rsp+A0h] [rbp-E8h]
  Scaleform::Render::Matrix2x4<float> *v106; // [rsp+A8h] [rbp-E0h]
  unsigned __int64 v107; // [rsp+B0h] [rbp-D8h]
  Scaleform::Render::Matrix2x4<float> *v108; // [rsp+B8h] [rbp-D0h]
  __int64 v109; // [rsp+C0h] [rbp-C8h]
  Scaleform::Render::Cxform v110; // [rsp+D0h] [rbp-B8h]
  __int128 v111; // [rsp+F0h] [rbp-98h]
  __int128 v112; // [rsp+100h] [rbp-88h]
  __int64 v113; // [rsp+110h] [rbp-78h]
  Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *v114; // [rsp+190h] [rbp+8h]
  Scaleform::Render::ComplexMesh *v115; // [rsp+198h] [rbp+10h]
  Scaleform::Render::StrideArray<Scaleform::Render::MatrixPoolImpl::HMatrix> *v116; // [rsp+1A0h] [rbp+18h]
  unsigned __int8 v117; // [rsp+1A8h] [rbp+20h]

  v116 = matrices;
  v115 = complexMesh;
  v114 = this;
  v109 = -2i64;
  v3 = matrices;
  v4 = complexMesh;
  v5 = this;
  v6 = this->vfptr[60].__vecDelDtor((Scaleform::RefCountImplCore *)this, 10u);
  v105 = v6;
  (*(void (__fastcall **)(void *, const char *))(*(_QWORD *)v6 + 16i64))(v6, "HAL::DrawProcessedComplexMeshes");
  v7 = (__int64)v4->pCacheMeshItem;
  v96 = v4->pCacheMeshItem;
  if ( !(v5->HALState & 8) )
  {
    _((AMD_HD3D *)v5);
    goto LABEL_87;
  }
  if ( !v7 )
    goto LABEL_87;
  v8 = (unsigned int *)v4->FillRecords.Data.Data;
  v100 = (unsigned int *)v4->FillRecords.Data.Data;
  v107 = v4->FillRecords.Data.Size;
  v9 = v3->Size;
  v101 = v3->Size;
  meshCount = 1;
  v106 = v4->FillMatrixCache.Data.Data;
  v94 = 0;
  if ( !(_DWORD)v107 )
    goto LABEL_80;
  v10 = (signed __int64)&v5->ShaderData;
  v11 = &v5->SManager;
  v12 = &v5->ShaderData.CurShaders;
  v13 = (signed __int64)&v5->Profiler;
  do
  {
    if ( (unsigned int)v9 > 1
      && Scaleform::Render::D3D1x::ShaderManager::HasInstancingSupport(v11)
      && *((_QWORD *)v8 + 2) )
    {
      v14 = ((__int64 (__fastcall *)(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *))v5->vfptr[62].__vecDelDtor)(v5);
      v15 = *(_DWORD *)((*(__int64 (**)(void))(*(_QWORD *)(v14 + 8) + 16i64))() + 48);
      if ( (unsigned int)v9 < v15 )
        v15 = v9;
      meshCount = v15;
      batchType = 2;
      v91 = 1;
    }
    else
    {
      batchType = 0;
      v91 = 0;
      v5->vfptr[93].__vecDelDtor((Scaleform::RefCountImplCore *)&v5->vfptr, 0);
    }
    v16 = v5->FillFlags;
    fillflags = v5->FillFlags;
    if ( (_DWORD)v101 )
    {
      v17 = v3->pData->pHandle->pHeader->Format & 0x10 | v16;
      fillflags = v17;
      if ( (_DWORD)v101 )
      {
        v18 = 0i64;
        v19 = (unsigned int)v101;
        do
        {
          v20 = *(__int64 *)((char *)&v116->pData->pHandle + v116->StrideSize * v18);
          if ( *(_BYTE *)(*(_QWORD *)v20 + 15i64) & 1 )
            v21 = (Scaleform::Render::Cxform *)(*(_QWORD *)v20
                                              + 16
                                              * (unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[*(_BYTE *)(*(_QWORD *)v20 + 15i64) & 0xF].Offsets[0]
                                              + 16i64);
          else
            v21 = &Scaleform::Render::Cxform::Identity;
          (*(void (__fastcall **)(signed __int64, Scaleform::Render::Cxform *, Scaleform::Render::Cxform *))(*(_QWORD *)v13 + 96i64))(
            v13,
            &v110,
            v21);
          if ( !Scaleform::Render::Cxform::operator==(&v110, &Scaleform::Render::Cxform::Identity) )
          {
            v17 |= 8u;
            fillflags = v17;
          }
          if ( v110.M[0][3] < 1.0 )
          {
            v17 |= 0x20u;
            fillflags = v17;
          }
          ++v18;
          --v19;
        }
        while ( v19 );
        v10 = (signed __int64)&v5->ShaderData;
        v12 = &v5->ShaderData.CurShaders;
      }
    }
    v22 = (*(unsigned int (__fastcall **)(signed __int64, _QWORD))(*(_QWORD *)v13 + 72i64))(
            v13,
            *(unsigned int *)(*(_QWORD *)v8 + 16i64));
    v23 = v22;
    v24 = v91;
    v25 = *(Scaleform::Render::VertexFormat **)&v8[2 * v91 + 2];
    v26 = Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::StaticShaderForFill(
            (Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture> *)&v5->SManager.vfptr,
            v22,
            &fillflags,
            batchType);
    Scaleform::Render::D3D1x::ShaderInterface::SetStaticShader(
      (Scaleform::Render::D3D1x::ShaderInterface *)v10,
      v26,
      v25);
    if ( !*(_BYTE *)(v10 + 4416) )
    {
      *(_BYTE *)(v10 + 4416) = 1;
      *(_QWORD *)(v10 + 4352) = 0i64;
      *(_QWORD *)(v10 + 4360) = 0i64;
      *(_QWORD *)(v10 + 4368) = 0i64;
      *(_WORD *)(v10 + 4376) = 0;
      *(_QWORD *)(v10 + 4384) = 0i64;
      *(_QWORD *)(v10 + 4392) = 0i64;
      *(_QWORD *)(v10 + 4400) = 0i64;
      *(_QWORD *)(v10 + 4408) = 0i64;
    }
    (*(void (__fastcall **)(signed __int64, Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *, Scaleform::Render::ComplexMesh *, _QWORD))(*(_QWORD *)v13 + 112i64))(
      v13,
      v5,
      v115,
      v94);
    v103 = ((__int64 (__fastcall *)(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *, unsigned int *, _QWORD, Scaleform::Render::MeshCacheItem *))v5->vfptr[89].__vecDelDtor)(
             v5,
             v8,
             v24,
             v96);
    v28 = fillflags;
    LOBYTE(v27) = fillflags & 0x20
               || Scaleform::Render::PrimitiveFillData::RequiresBlend((Scaleform::Render::PrimitiveFillData *)(*(_QWORD *)v8 + 16i64));
    v5->vfptr[41].__vecDelDtor((Scaleform::RefCountImplCore *)&v5->vfptr, v27);
    (*(void (__fastcall **)(signed __int64, _QWORD))(*(_QWORD *)v13 + 104i64))(v13, v28);
    v29 = *(_DWORD *)(*(_QWORD *)v8 + 16i64);
    if ( v29 < 5 )
      v117 = 0;
    else
      v117 = ((unsigned int)(v29 - 9) <= 1) + 1;
    v89 = Scaleform::Render::PrimitiveFill::IsSolid(v23);
    v30 = 0;
    v95 = 0;
    LODWORD(v9) = v101;
    if ( (_DWORD)v101 )
    {
      v31 = &v115->VertexMatrix;
      v108 = &v115->VertexMatrix;
      v97 = v101 - 1;
      v32 = 0i64;
      v102 = 0i64;
      while ( 1 )
      {
        m2 = (Scaleform::Render::MatrixPoolImpl::HMatrix *)((char *)v116->pData + v116->StrideSize * v32);
        Matrices = v5->Matrices.pObject;
        v35 = v30 % meshCount;
        v99 = v30 % meshCount;
        Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetMatrix(
          (Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair> *)v10,
          v12,
          0xDu,
          v31,
          m2,
          Matrices,
          0,
          v30 % meshCount);
        if ( v89 )
        {
          v98 = *(_DWORD *)(*(_QWORD *)v8 + 20i64);
          v36 = (unsigned __int8 *)(*(__int64 (__fastcall **)(signed __int64, char *, int *))(*(_QWORD *)v13 + 80i64))(
                                     v13,
                                     &v104,
                                     &v98);
          v37 = (float)v36[2] * 0.0039215689;
          v38 = (float)v36[1] * 0.0039215689;
          v39 = (float)*v36 * 0.0039215689;
          v40 = (float)v36[3] * 0.0039215689;
          v41 = v12->pVDesc;
          v42 = v41->BatchUniforms;
          v43 = v42[5].Offset;
          if ( v43 < 0 )
          {
            v52 = v12->pFDesc;
            v53 = v52->BatchUniforms;
            v54 = v53[5].Offset;
            if ( v54 < 0 )
            {
              v63 = v41->Uniforms;
              if ( v63[5].Size )
              {
                v64 = v63[5].ShadowOffset;
                *(float *)(v10 + 4 * v64) = v37;
                *(float *)(v10 + 4 * v64 + 4) = v38;
                *(float *)(v10 + 4 * v64 + 8) = v39;
                *(float *)(v10 + 4 * v64 + 12) = v40;
              }
              v65 = v12->pFDesc->Uniforms;
              if ( v65[5].Size )
              {
                v66 = v65[5].ShadowOffset;
                *(float *)(v10 + 4 * v66) = v37;
                *(float *)(v10 + 4 * v66 + 4) = v38;
                *(float *)(v10 + 4 * v66 + 8) = v39;
                *(float *)(v10 + 4 * v66 + 12) = v40;
              }
              *(_BYTE *)(v10 + 4357) = 1;
            }
            else
            {
              v55 = (unsigned int)v53[5].Array;
              v56 = v54 + v35 * (unsigned __int8)v52->Uniforms[v55].BatchSize;
              v57 = (unsigned int)v55;
              v58 = v55;
              v59 = v41->Uniforms;
              if ( v59[v58].Size )
              {
                v60 = v59[v58].ShadowOffset
                    + (unsigned __int64)(v56 * (unsigned int)(unsigned __int8)v59[v58].ElementSize);
                *(float *)(v10 + 4 * v60) = v37;
                *(float *)(v10 + 4 * v60 + 4) = v38;
                *(float *)(v10 + 4 * v60 + 8) = v39;
                *(float *)(v10 + 4 * v60 + 12) = v40;
              }
              v61 = v12->pFDesc->Uniforms;
              if ( v61[v58].Size )
              {
                v62 = v61[v58].ShadowOffset
                    + (unsigned __int64)(v56 * (unsigned int)(unsigned __int8)v61[v58].ElementSize);
                *(float *)(v10 + 4 * v62) = v37;
                *(float *)(v10 + 4 * v62 + 4) = v38;
                *(float *)(v10 + 4 * v62 + 8) = v39;
                *(float *)(v10 + 4 * v62 + 12) = v40;
              }
              *(_BYTE *)(v57 + v10 + 4352) = 1;
            }
          }
          else
          {
            v44 = (unsigned int)v42[5].Array;
            v45 = v41->Uniforms;
            v46 = v43 + v35 * (unsigned __int8)v45[v44].BatchSize;
            v47 = (unsigned int)v44;
            v48 = v44;
            if ( v45[v48].Size )
            {
              v49 = v45[v48].ShadowOffset
                  + (unsigned __int64)(v46 * (unsigned int)(unsigned __int8)v45[v48].ElementSize);
              *(float *)(v10 + 4 * v49) = v37;
              *(float *)(v10 + 4 * v49 + 4) = v38;
              *(float *)(v10 + 4 * v49 + 8) = v39;
              *(float *)(v10 + 4 * v49 + 12) = v40;
            }
            v50 = v12->pFDesc->Uniforms;
            if ( v50[v48].Size )
            {
              v51 = v50[v48].ShadowOffset
                  + (unsigned __int64)(v46 * (unsigned int)(unsigned __int8)v50[v48].ElementSize);
              *(float *)(v10 + 4 * v51) = v37;
              *(float *)(v10 + 4 * v51 + 4) = v38;
              *(float *)(v10 + 4 * v51 + 8) = v39;
              *(float *)(v10 + 4 * v51 + 12) = v40;
            }
            *(_BYTE *)(v47 + v10 + 4352) = 1;
          }
          v117 = 0;
        }
        else if ( fillflags & 8 )
        {
          v67 = m2->pHandle->pHeader;
          if ( v67->Format & 1 )
            v68 = (Scaleform::Render::Cxform *)&v67[(unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[v67->Format & 0xF].Offsets[0]
                                                  + 1];
          else
            v68 = &Scaleform::Render::Cxform::Identity;
          v69 = (const float *)(*(__int64 (__fastcall **)(signed __int64, Scaleform::Render::Cxform *, Scaleform::Render::Cxform *))(*(_QWORD *)v13 + 96i64))(
                                 v13,
                                 &v110,
                                 v68);
          Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUniform(
            (Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair> *)v10,
            v12,
            5u,
            v69,
            4u,
            0,
            v35);
          Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUniform(
            (Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair> *)v10,
            v12,
            4u,
            v69 + 4,
            4u,
            0,
            v35);
        }
        v70 = 0;
        v71 = 0;
        if ( v117 )
        {
          v72 = 0i64;
          v73 = 32i64;
          v74 = v8 + 11;
          do
          {
            Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUniform(
              (Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair> *)v10,
              (Scaleform::Render::D3D1x::ShaderPair *)(v10 + 4432),
              0x15u,
              (const float *)&v106[*v74],
              8u,
              2 * v70,
              v99);
            v75 = *(_QWORD *)v100;
            v76 = *(Scaleform::Render::Texture **)(v73 + *(_QWORD *)v100);
            v111 = *(_OWORD *)(v10 + 4432);
            v112 = *(_OWORD *)(v10 + 4448);
            v113 = *(_QWORD *)(v10 + 4464);
            v88 = *(_BYTE *)(v75 + v72 + 24);
            Scaleform::Render::D3D1x::ShaderInterface::SetTexture(
              (Scaleform::Render::D3D1x::ShaderInterface *)v10,
              (Scaleform::Render::D3D1x::ShaderPair *)&v111,
              0x14u,
              v76,
              (Scaleform::Render::ImageFillMode)&v88,
              v71);
            v71 += (unsigned __int8)v76->TextureCount;
            ++v70;
            ++v72;
            ++v74;
            v73 += 8i64;
          }
          while ( v70 < v117 );
          v5 = v114;
          v8 = v100;
          v30 = v95;
        }
        v77 = v30 == v97;
        if ( batchType != 2 )
          break;
        if ( !((v30 + 1) % meshCount) && v30 || v77 )
        {
          v78 = meshCount;
          if ( v77 && (v30 + 1) % meshCount )
            v78 = (v30 + 1) % meshCount;
          ((void (__fastcall *)(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *, _QWORD, _QWORD))v5->vfptr[94].__vecDelDtor)(
            v5,
            v78,
            v8[7]);
          Scaleform::Render::D3D1x::ShaderInterface::Finish((Scaleform::Render::D3D1x::ShaderInterface *)v10, v78);
          ((void (__fastcall *)(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *, unsigned int *, _QWORD, Scaleform::Render::MeshCacheItem *))v5->vfptr[91].__vecDelDtor)(
            v5,
            v8,
            v91,
            v96);
          ((void (__fastcall *)(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *, _QWORD, _QWORD, _QWORD, __int64, _QWORD))v5->vfptr[97].__vecDelDtor)(
            v5,
            v8[7],
            v8[10],
            v78,
            v103 + v8[6],
            0i64);
          goto LABEL_73;
        }
LABEL_76:
        v95 = ++v30;
        v32 = v102++ + 1;
        LODWORD(v9) = v101;
        v12 = (Scaleform::Render::D3D1x::ShaderPair *)(v10 + 4432);
        v13 = (signed __int64)&v5->Profiler;
        v31 = v108;
        if ( v30 >= (unsigned int)v101 )
        {
          v12 = (Scaleform::Render::D3D1x::ShaderPair *)(v10 + 4432);
          v13 = (signed __int64)&v5->Profiler;
          goto LABEL_78;
        }
      }
      Scaleform::Render::D3D1x::ShaderInterface::Finish((Scaleform::Render::D3D1x::ShaderInterface *)v10, 1u);
      ((void (__fastcall *)(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *, unsigned int *, _QWORD, Scaleform::Render::MeshCacheItem *))v5->vfptr[91].__vecDelDtor)(
        v5,
        v8,
        v91,
        v96);
      ((void (__fastcall *)(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *, _QWORD, _QWORD, signed __int64, __int64, _QWORD))v5->vfptr[96].__vecDelDtor)(
        v5,
        v8[7],
        v8[10],
        1i64,
        v103 + v8[6],
        0i64);
LABEL_73:
      ++v5->AccumulatedStats.Primitives;
      if ( !v77 && !*(_BYTE *)(v10 + 4416) )
      {
        *(_BYTE *)(v10 + 4416) = 1;
        *(_QWORD *)(v10 + 4352) = 0i64;
        *(_QWORD *)(v10 + 4360) = 0i64;
        *(_QWORD *)(v10 + 4368) = 0i64;
        *(_WORD *)(v10 + 4376) = 0;
        *(_QWORD *)(v10 + 4384) = 0i64;
        *(_QWORD *)(v10 + 4392) = 0i64;
        *(_QWORD *)(v10 + 4400) = 0i64;
        *(_QWORD *)(v10 + 4408) = 0i64;
      }
      goto LABEL_76;
    }
LABEL_78:
    v79 = v94 + 1;
    v94 = v79;
    v8 += 14;
    v100 = v8;
    v80 = v79 < (unsigned int)v107;
    v3 = v116;
    v11 = &v5->SManager;
  }
  while ( v80 );
  v7 = (__int64)v96;
  v6 = v105;
LABEL_80:
  if ( ((__int64 (__fastcall *)(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *))v5->vfptr[65].__vecDelDtor)(v5) )
  {
    v81 = (Scaleform::Render::RenderSync *)((__int64 (__fastcall *)(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *))v5->vfptr[65].__vecDelDtor)(v5);
    v82 = Scaleform::Render::RenderSync::InsertFence(v81);
    v83 = v82;
    if ( v82 )
      ++v82->RefCount;
    v84 = *(Scaleform::Render::Fence **)(v7 + 80);
    if ( v84 )
      Scaleform::Render::Fence::Release(v84);
    *(_QWORD *)(v7 + 80) = v83;
  }
  v85 = *(_QWORD *)(v7 + 16);
  *(_QWORD *)(*(_QWORD *)v7 + 8i64) = *(_QWORD *)(v7 + 8);
  **(_QWORD **)(v7 + 8) = *(_QWORD *)v7;
  *(_QWORD *)v7 = -1i64;
  *(_QWORD *)(v7 + 8) = -1i64;
  v86 = 3 * (*(signed int *)(v7 + 24) + 1i64);
  *(_QWORD *)(v85 + 8 * v86) -= *(_QWORD *)(v7 + 64);
  v87 = *(_QWORD *)(v7 + 16);
  *(_DWORD *)(v7 + 24) = 2;
  *(_QWORD *)(v7 + 8) = *(_QWORD *)(v87 + 64);
  *(_QWORD *)v7 = v87 + 56;
  **(_QWORD **)(v87 + 64) = v7;
  *(_QWORD *)(v87 + 64) = v7;
  *(_QWORD *)(v87 + 72) += *(_QWORD *)(v7 + 64);
LABEL_87:
  (*(void (__fastcall **)(void *))(*(_QWORD *)v6 + 24i64))(v6);
}

// File Line: 942
// RVA: 0x9FE440
void __fastcall Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface>::DrawableCxform(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *this, Scaleform::Render::Texture **tex, Scaleform::Render::Matrix2x4<float> *texgen, Scaleform::Render::Cxform *cx)
{
  Scaleform::Render::Cxform *v4; // rbx
  Scaleform::Render::Matrix2x4<float> *v5; // rdi
  Scaleform::Render::Texture **v6; // rsi
  Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *v7; // r15
  void *v8; // ST48_8
  Scaleform::Render::RenderTarget *v9; // r8
  int v10; // ecx
  Scaleform::Render::Size<int> texsize; // [rsp+70h] [rbp+8h]

  v4 = cx;
  v5 = texgen;
  v6 = tex;
  v7 = this;
  v8 = this->vfptr[60].__vecDelDtor((Scaleform::RefCountImplCore *)this, 16u);
  (*(void (__fastcall **)(void *, const char *))(*(_QWORD *)v8 + 16i64))(v8, "HAL::DrawableCxform");
  v9 = v7->RenderTargetStack.Data.Data[v7->RenderTargetStack.Data.Size - 1].pRenderTarget.pObject;
  v10 = v9->ViewRect.y2 - v9->ViewRect.y1;
  texsize.Width = v9->ViewRect.x2 - v9->ViewRect.x1;
  texsize.Height = v10;
  Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::SetDrawableCxform(
    (Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture> *)&v7->SManager.vfptr,
    v6,
    v5,
    (Scaleform::Render::Size<int>)&texsize,
    v4,
    v7->MappedXY16iAlphaTexture[1],
    &v7->ShaderData,
    0);
  ((void (__fastcall *)(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *))v7->vfptr[75].__vecDelDtor)(v7);
  (*(void (__fastcall **)(void *))(*(_QWORD *)v8 + 24i64))(v8);
}

// File Line: 951
// RVA: 0x9FE040
void __fastcall Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface>::DrawableCompare(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *this, Scaleform::Render::Texture **tex, Scaleform::Render::Matrix2x4<float> *texgen)
{
  Scaleform::Render::Matrix2x4<float> *v3; // rbx
  Scaleform::Render::Texture **v4; // rdi
  Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *v5; // r14
  void *v6; // rsi
  Scaleform::Render::RenderTarget *v7; // r8
  int v8; // ecx
  Scaleform::Render::Size<int> texsize; // [rsp+70h] [rbp+8h]
  void *v10; // [rsp+88h] [rbp+20h]

  v3 = texgen;
  v4 = tex;
  v5 = this;
  v6 = this->vfptr[60].__vecDelDtor((Scaleform::RefCountImplCore *)this, 17u);
  v10 = v6;
  (*(void (__fastcall **)(void *, const char *))(*(_QWORD *)v6 + 16i64))(v6, "HAL::DrawableCompare");
  v7 = v5->RenderTargetStack.Data.Data[v5->RenderTargetStack.Data.Size - 1].pRenderTarget.pObject;
  v8 = v7->ViewRect.y2 - v7->ViewRect.y1;
  texsize.Width = v7->ViewRect.x2 - v7->ViewRect.x1;
  texsize.Height = v8;
  Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::SetDrawableCompare(
    (Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture> *)&v5->SManager.vfptr,
    v4,
    v3,
    (Scaleform::Render::Size<int>)&texsize,
    v5->MappedXY16iAlphaTexture[1],
    &v5->ShaderData,
    0);
  ((void (__fastcall *)(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *))v5->vfptr[75].__vecDelDtor)(v5);
  (*(void (__fastcall **)(void *))(*(_QWORD *)v6 + 24i64))(v6);
}

// File Line: 960
// RVA: 0x9FE7F0
void __fastcall Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface>::DrawableMerge(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *this, Scaleform::Render::Texture **tex, Scaleform::Render::Matrix2x4<float> *texgen, Scaleform::Render::Matrix4x4<float> *cxmul)
{
  Scaleform::Render::Matrix4x4<float> *v4; // rbx
  Scaleform::Render::Matrix2x4<float> *v5; // rdi
  Scaleform::Render::Texture **v6; // rsi
  Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *v7; // r15
  void *v8; // ST48_8
  Scaleform::Render::RenderTarget *v9; // r8
  int v10; // ecx
  Scaleform::Render::Size<int> texsize; // [rsp+70h] [rbp+8h]

  v4 = cxmul;
  v5 = texgen;
  v6 = tex;
  v7 = this;
  v8 = this->vfptr[60].__vecDelDtor((Scaleform::RefCountImplCore *)this, 19u);
  (*(void (__fastcall **)(void *, const char *))(*(_QWORD *)v8 + 16i64))(v8, "HAL::DrawableMerge");
  v9 = v7->RenderTargetStack.Data.Data[v7->RenderTargetStack.Data.Size - 1].pRenderTarget.pObject;
  v10 = v9->ViewRect.y2 - v9->ViewRect.y1;
  texsize.Width = v9->ViewRect.x2 - v9->ViewRect.x1;
  texsize.Height = v10;
  Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::SetDrawableMergeFill(
    (Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture> *)&v7->SManager.vfptr,
    v6,
    v5,
    (Scaleform::Render::Size<int>)&texsize,
    v4,
    v7->MappedXY16iAlphaTexture[1],
    &v7->ShaderData,
    0);
  ((void (__fastcall *)(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *))v7->vfptr[75].__vecDelDtor)(v7);
  (*(void (__fastcall **)(void *))(*(_QWORD *)v8 + 24i64))(v8);
}

// File Line: 970
// RVA: 0x9FE130
void __fastcall Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface>::DrawableCopyPixels(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *this, Scaleform::Render::Texture **tex, Scaleform::Render::Matrix2x4<float> *texgen, Scaleform::Render::Matrix2x4<float> *mvp, bool mergeAlpha, bool destAlpha)
{
  Scaleform::Render::Matrix2x4<float> *v6; // rbx
  Scaleform::Render::Matrix2x4<float> *v7; // rdi
  Scaleform::Render::Texture **v8; // rsi
  Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *v9; // r15
  void *v10; // ST58_8
  Scaleform::Render::RenderTarget *v11; // r8
  int v12; // ecx
  Scaleform::Render::Size<int> texsize; // [rsp+80h] [rbp+8h]

  v6 = mvp;
  v7 = texgen;
  v8 = tex;
  v9 = this;
  v10 = this->vfptr[60].__vecDelDtor((Scaleform::RefCountImplCore *)this, 18u);
  (*(void (__fastcall **)(void *, const char *))(*(_QWORD *)v10 + 16i64))(v10, "HAL::DrawableCopyPixels");
  v11 = v9->RenderTargetStack.Data.Data[v9->RenderTargetStack.Data.Size - 1].pRenderTarget.pObject;
  v12 = v11->ViewRect.y2 - v11->ViewRect.y1;
  texsize.Width = v11->ViewRect.x2 - v11->ViewRect.x1;
  texsize.Height = v12;
  Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::SetDrawableCopyPixelsFill(
    (Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture> *)&v9->SManager.vfptr,
    v8,
    v7,
    (Scaleform::Render::Size<int>)&texsize,
    v6,
    mergeAlpha,
    destAlpha,
    v9->MappedXY16iAlphaTexture[1],
    &v9->ShaderData,
    0);
  ((void (__fastcall *)(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *))v9->vfptr[75].__vecDelDtor)(v9);
  (*(void (__fastcall **)(void *))(*(_QWORD *)v10 + 24i64))(v10);
}

// File Line: 981
// RVA: 0x9FE8F0
void __fastcall Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface>::DrawablePaletteMap(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *this, Scaleform::Render::Texture **tex, Scaleform::Render::Matrix2x4<float> *texgen, Scaleform::Render::Matrix2x4<float> *mvp, unsigned int channelMask, const unsigned int *values)
{
  Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *v6; // r13
  void *v7; // rax
  void *v8; // r14
  signed int v9; // esi
  __int64 v10; // rax
  __int64 v11; // rdi
  __int64 v12; // rbx
  unsigned int v13; // eax
  __int64 v14; // rax
  Scaleform::Render::Texture *paletteMap; // r15
  __int64 v16; // r14
  signed int v17; // ebx
  const unsigned int *v18; // rdi
  unsigned int v19; // er12
  char *v20; // rax
  const unsigned int *v21; // rdx
  signed __int64 v22; // rcx
  unsigned int v23; // er8
  Scaleform::Render::RenderTarget *v24; // rdx
  int v25; // ecx
  void *v26; // [rsp+50h] [rbp-69h]
  Scaleform::Render::Size<int> texsize; // [rsp+58h] [rbp-61h]
  Scaleform::Render::ImageData v28; // [rsp+60h] [rbp-59h]
  __int64 v29; // [rsp+A0h] [rbp-19h]
  __int64 v30; // [rsp+A8h] [rbp-11h]
  void *v31; // [rsp+B0h] [rbp-9h]
  int v32; // [rsp+110h] [rbp+57h]
  int v33; // [rsp+114h] [rbp+5Bh]
  Scaleform::Render::Texture **texa; // [rsp+118h] [rbp+5Fh]
  Scaleform::Render::Matrix2x4<float> *texgena; // [rsp+120h] [rbp+67h]
  Scaleform::Render::Matrix2x4<float> *v36; // [rsp+128h] [rbp+6Fh]

  v36 = mvp;
  texgena = texgen;
  texa = tex;
  v29 = -2i64;
  v6 = this;
  v7 = this->vfptr[60].__vecDelDtor((Scaleform::RefCountImplCore *)this, 20u);
  v8 = v7;
  v26 = v7;
  v31 = v7;
  (*(void (__fastcall **)(void *, const char *))(*(_QWORD *)v7 + 16i64))(v7, "HAL::DrawablePaletteMap");
  *(_QWORD *)&v28.Format = 0i64;
  *(_DWORD *)&v28.Flags = 0x10000;
  v9 = 1;
  v28.pPlanes = &v28.Plane0;
  v28.pPalette.pObject = 0i64;
  *(_QWORD *)&v28.Plane0.Width = 0i64;
  v28.Plane0.Pitch = 0i64;
  v28.Plane0.DataSize = 0i64;
  v28.Plane0.pData = 0i64;
  v10 = ((__int64 (__fastcall *)(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *))v6->vfptr[61].__vecDelDtor)(v6);
  v11 = v10;
  v32 = 256;
  v33 = 4;
  v12 = *(_QWORD *)v10;
  v13 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v10 + 104i64))(v10);
  v14 = (*(__int64 (__fastcall **)(__int64, _QWORD, signed __int64, int *, signed int, _QWORD, _QWORD))(v12 + 8))(
          v11,
          v13,
          1i64,
          &v32,
          192,
          0i64,
          0i64);
  paletteMap = (Scaleform::Render::Texture *)v14;
  v30 = v14;
  if ( v14
    && (*(unsigned __int8 (__fastcall **)(__int64, Scaleform::Render::ImageData *, _QWORD, signed __int64))(*(_QWORD *)v14 + 104i64))(
         v14,
         &v28,
         0i64,
         1i64) )
  {
    v16 = 0i64;
    v17 = 0;
    v18 = values;
    v19 = channelMask;
    do
    {
      v20 = &v28.pPlanes->pData[v16 * v28.pPlanes->Pitch];
      if ( v9 & v19 )
      {
        v21 = v18;
        if ( ((unsigned __int8)v20 | (unsigned __int8)v18) & 0xF )
        {
          memmove(&v28.pPlanes->pData[v16 * v28.pPlanes->Pitch], v18, 0x400ui64);
        }
        else
        {
          v22 = 8i64;
          do
          {
            *(_OWORD *)v20 = *(_OWORD *)v21;
            *((_OWORD *)v20 + 1) = *((_OWORD *)v21 + 1);
            *((_OWORD *)v20 + 2) = *((_OWORD *)v21 + 2);
            *((_OWORD *)v20 + 3) = *((_OWORD *)v21 + 3);
            *((_OWORD *)v20 + 4) = *((_OWORD *)v21 + 4);
            *((_OWORD *)v20 + 5) = *((_OWORD *)v21 + 5);
            *((_OWORD *)v20 + 6) = *((_OWORD *)v21 + 6);
            v20 += 128;
            *((_OWORD *)v20 - 1) = *((_OWORD *)v21 + 7);
            v21 += 32;
            --v22;
          }
          while ( v22 );
        }
      }
      else
      {
        v23 = 0;
        do
        {
          v21 = (const unsigned int *)(v23 << v17);
          *(_DWORD *)v20 = (_DWORD)v21;
          v20 += 4;
          ++v23;
        }
        while ( v23 < 0x100 );
      }
      v17 += 8;
      v9 = __ROL4__(v9, 1);
      ++v16;
      v18 += 256;
    }
    while ( v17 < 32 );
    if ( paletteMap->vfptr[14].__vecDelDtor((Scaleform::RefCountImplCore *)&paletteMap->vfptr, (unsigned int)v21) )
    {
      Scaleform::Render::HAL::applyBlendMode((Scaleform::Render::HAL *)&v6->vfptr, 16i64, 1, 1);
      v24 = v6->RenderTargetStack.Data.Data[v6->RenderTargetStack.Data.Size - 1].pRenderTarget.pObject;
      v25 = v24->ViewRect.y2 - v24->ViewRect.y1;
      texsize.Width = v24->ViewRect.x2 - v24->ViewRect.x1;
      texsize.Height = v25;
      Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::SetDrawablePaletteMap(
        (Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture> *)&v6->SManager.vfptr,
        texa,
        texgena,
        (Scaleform::Render::Size<int>)&texsize,
        v36,
        paletteMap,
        v6->MappedXY16iAlphaTexture[1],
        &v6->ShaderData,
        0);
      ((void (__fastcall *)(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *))v6->vfptr[75].__vecDelDtor)(v6);
    }
    v8 = v26;
  }
  if ( paletteMap )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)paletteMap);
  Scaleform::Render::ImageData::freePlanes(&v28);
  if ( v28.pPalette.pObject && !_InterlockedDecrement(&v28.pPalette.pObject->RefCount.Value) )
    ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
  (*(void (__fastcall **)(void *))(*(_QWORD *)v8 + 24i64))(v8);
}

// File Line: 1019
// RVA: 0x9FE240
void __fastcall Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface>::DrawableCopyback(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *this, Scaleform::Render::Texture *source, Scaleform::Render::Matrix2x4<float> *mvpOriginal, Scaleform::Render::Matrix2x4<float> *texgen, unsigned int flagMask)
{
  Scaleform::Render::Matrix2x4<float> *v5; // r15
  Scaleform::Render::Matrix2x4<float> *v6; // rbp
  Scaleform::Render::Texture *v7; // r12
  Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *v8; // rsi
  void *v9; // r14
  float v[4]; // [rsp+50h] [rbp-58h]
  __int128 v11; // [rsp+60h] [rbp-48h]
  Scaleform::Render::VertexFormat *v12; // [rsp+70h] [rbp-38h]

  v5 = texgen;
  v6 = mvpOriginal;
  v7 = source;
  v8 = this;
  v9 = this->vfptr[60].__vecDelDtor((Scaleform::RefCountImplCore *)this, 22u);
  (*(void (__fastcall **)(void *, const char *))(*(_QWORD *)v9 + 16i64))(v9, "HAL::DrawableCopyback");
  Scaleform::Render::D3D1x::ShaderInterface::SetStaticShader(
    &v8->ShaderData,
    ST_BatchTexTG,
    v8->MappedXY16iAlphaTexture[1]);
  if ( !v8->ShaderData.PrimitiveOpen )
  {
    v8->ShaderData.PrimitiveOpen = 1;
    *(_QWORD *)v8->ShaderData.UniformSet = 0i64;
    *(_QWORD *)&v8->ShaderData.UniformSet[8] = 0i64;
    *(_QWORD *)&v8->ShaderData.UniformSet[16] = 0i64;
    *(_WORD *)&v8->ShaderData.UniformSet[24] = 0;
    v8->ShaderData.Textures[0] = 0i64;
    v8->ShaderData.Textures[1] = 0i64;
    v8->ShaderData.Textures[2] = 0i64;
    v8->ShaderData.Textures[3] = 0i64;
  }
  v[0] = v6->M[0][0];
  v[1] = v6->M[0][1];
  v[2] = v6->M[0][2];
  v[3] = v6->M[0][3];
  v11 = *(_OWORD *)&v6->M[1][0];
  Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUniform(
    (Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair> *)v8->ShaderData.UniformData,
    &v8->ShaderData.CurShaders,
    0xDu,
    v,
    8u,
    0,
    0);
  Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUniform(
    (Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair> *)v8->ShaderData.UniformData,
    &v8->ShaderData.CurShaders,
    0x15u,
    (const float *)v5,
    8u,
    0,
    0);
  *(_OWORD *)v = *(_OWORD *)&v8->ShaderData.CurShaders.pVS;
  v11 = *(_OWORD *)&v8->ShaderData.CurShaders.pFS;
  v12 = v8->ShaderData.CurShaders.pVFormat;
  LOBYTE(flagMask) = 0;
  Scaleform::Render::D3D1x::ShaderInterface::SetTexture(
    &v8->ShaderData,
    (Scaleform::Render::D3D1x::ShaderPair *)v,
    0x14u,
    v7,
    (Scaleform::Render::ImageFillMode)&flagMask,
    0);
  Scaleform::Render::D3D1x::ShaderInterface::Finish(&v8->ShaderData, 1u);
  ((void (__fastcall *)(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *))v8->vfptr[75].__vecDelDtor)(v8);
  (*(void (__fastcall **)(void *))(*(_QWORD *)v9 + 24i64))(v9);
}

// File Line: 1045
// RVA: 0xA05C30
char __fastcall Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface>::initHAL(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *this, Scaleform::Render::HALInitParams *params)
{
  Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *v2; // rbx
  char result; // al
  int v4; // ST30_4
  __int64 v5; // ST30_8

  v2 = this;
  result = Scaleform::Render::HAL::initHAL((Scaleform::Render::HAL *)&this->vfptr, params);
  if ( result )
  {
    v4 = 0;
    ((void (__fastcall *)(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *, signed __int64, Scaleform::Render::VertexFormat *, Scaleform::Render::VertexFormat **, Scaleform::Render::VertexFormat **, Scaleform::Render::VertexFormat **, int))v2->vfptr[66].__vecDelDtor)(
      v2,
      5i64,
      &Scaleform::Render::VertexXY16iAlpha::Format,
      v2->MappedXY16iAlphaTexture,
      &v2->MappedXY16iAlphaTexture[1],
      &v2->MappedXY16iAlphaTexture[2],
      v4);
    LODWORD(v5) = 0;
    ((void (__fastcall *)(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *, signed __int64, Scaleform::Render::VertexFormat *, Scaleform::Render::VertexFormat **, Scaleform::Render::VertexFormat **, Scaleform::Render::VertexFormat **, __int64))v2->vfptr[66].__vecDelDtor)(
      v2,
      2i64,
      &Scaleform::Render::VertexXY16iAlpha::Format,
      v2->MappedXY16iAlphaSolid,
      &v2->MappedXY16iAlphaSolid[1],
      &v2->MappedXY16iAlphaSolid[2],
      v5);
    result = 1;
  }
  return result;
}

// File Line: 1066
// RVA: 0xA06210
char __fastcall Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface>::shutdownHAL(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *this)
{
  Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *v1; // rbx
  char result; // al
  Scaleform::Render::VertexFormat **v3; // rbx
  signed __int64 v4; // rsi
  __int64 v5; // rdi
  Scaleform::Render::RenderBuffer *v6; // rcx
  Scaleform::Render::VertexFormat *v7; // rdi
  Scaleform::Render::RenderBuffer *v8; // rcx

  v1 = this;
  result = Scaleform::Render::HAL::shutdownHAL((Scaleform::Render::HAL *)&this->vfptr);
  if ( result )
  {
    v3 = v1->MappedXY16iAlphaSolid;
    v4 = 3i64;
    do
    {
      v5 = (__int64)*(v3 - 3);
      if ( v5 )
      {
        v6 = *(Scaleform::Render::RenderBuffer **)(v5 + 16);
        if ( v6 )
          Scaleform::RefCountImpl::Release(v6);
        *(_QWORD *)(v5 + 16) = 0i64;
      }
      v7 = *v3;
      *(v3 - 3) = 0i64;
      if ( v7 )
      {
        v8 = (Scaleform::Render::RenderBuffer *)v7->pSysFormat.pObject;
        if ( v8 )
          Scaleform::RefCountImpl::Release(v8);
        v7->pSysFormat.pObject = 0i64;
      }
      *v3 = 0i64;
      ++v3;
      --v4;
    }
    while ( v4 );
    result = 1;
  }
  return result;
}

// File Line: 1084
// RVA: 0xA04FA0
void __fastcall Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface>::drawMaskClearRectangles(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *this, Scaleform::Render::Matrix2x4<float> *matrices, unsigned __int64 count)
{
  unsigned __int64 v3; // rsi
  Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *v4; // r12
  void *v5; // r14
  signed __int64 v6; // rbx
  unsigned __int64 v7; // r13
  unsigned int v8; // er14
  unsigned int batch; // esi
  const float *v10; // rbp
  float v11; // xmm3_4
  float v12; // xmm2_4
  float v13; // xmm1_4
  float v14; // xmm0_4
  Scaleform::Render::D3D1x::VertexShaderDesc *v15; // rcx
  Scaleform::Render::D3D1x::BatchVar *v16; // rax
  char v17; // dl
  int v18; // er10
  __int64 v19; // rax
  Scaleform::Render::D3D1x::BatchVar *v20; // rdx
  char v21; // al
  Scaleform::Render::D3D1x::UniformVar *v22; // r8
  unsigned __int64 v23; // rcx
  Scaleform::Render::D3D1x::UniformVar *v24; // r8
  unsigned __int64 v25; // rcx
  Scaleform::Render::D3D1x::UniformVar *v26; // rax
  __int64 v27; // rax
  Scaleform::Render::D3D1x::UniformVar *v28; // rcx
  __int64 v29; // rax
  void *v30; // [rsp+40h] [rbp-68h]
  int v31; // [rsp+B0h] [rbp+8h]
  Scaleform::Render::Matrix2x4<float> *v32; // [rsp+B8h] [rbp+10h]
  unsigned __int64 v33; // [rsp+C0h] [rbp+18h]
  int v34; // [rsp+C8h] [rbp+20h]

  v33 = count;
  v32 = matrices;
  v3 = count;
  v4 = this;
  v5 = this->vfptr[60].__vecDelDtor((Scaleform::RefCountImplCore *)this, 8u);
  v30 = v5;
  (*(void (__fastcall **)(void *, const char *))(*(_QWORD *)v5 + 16i64))(v5, "HAL::drawMaskClearRectangles");
  v6 = (signed __int64)&v4->ShaderData;
  Scaleform::Render::D3D1x::ShaderInterface::SetStaticShader(
    &v4->ShaderData,
    ST_BatchSolid,
    v4->MappedXY16iAlphaSolid[1]);
  if ( !v4->ShaderData.PrimitiveOpen )
  {
    v4->ShaderData.PrimitiveOpen = 1;
    *(_QWORD *)v4->ShaderData.UniformSet = 0i64;
    *(_QWORD *)&v4->ShaderData.UniformSet[8] = 0i64;
    *(_QWORD *)&v4->ShaderData.UniformSet[16] = 0i64;
    *(_WORD *)&v4->ShaderData.UniformSet[24] = 0;
    v4->ShaderData.Textures[0] = 0i64;
    v4->ShaderData.Textures[1] = 0i64;
    v4->ShaderData.Textures[2] = 0i64;
    v4->ShaderData.Textures[3] = 0i64;
  }
  ((void (__fastcall *)(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *))v4->vfptr[87].__vecDelDtor)(v4);
  v7 = 0i64;
  if ( v3 )
  {
    v8 = 24;
    if ( (unsigned int)v3 < 0x18 )
      v8 = v3;
    while ( 1 )
    {
      if ( v7 && !v4->ShaderData.PrimitiveOpen )
      {
        v4->ShaderData.PrimitiveOpen = 1;
        *(_QWORD *)v4->ShaderData.UniformSet = 0i64;
        *(_QWORD *)&v4->ShaderData.UniformSet[8] = 0i64;
        *(_QWORD *)&v4->ShaderData.UniformSet[16] = 0i64;
        *(_WORD *)&v4->ShaderData.UniformSet[24] = 0;
        v4->ShaderData.Textures[0] = 0i64;
        v4->ShaderData.Textures[1] = 0i64;
        v4->ShaderData.Textures[2] = 0i64;
        v4->ShaderData.Textures[3] = 0i64;
      }
      batch = 0;
      if ( v8 )
        break;
LABEL_38:
      Scaleform::Render::D3D1x::ShaderInterface::Finish(&v4->ShaderData, v8);
      ((void (__fastcall *)(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *))v4->vfptr[88].__vecDelDtor)(v4);
      ((void (__fastcall *)(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *, _QWORD, _QWORD))v4->vfptr[95].__vecDelDtor)(
        v4,
        6 * v8,
        v8);
      v7 += v8;
      if ( v7 >= v33 )
      {
        v5 = v30;
        goto LABEL_40;
      }
    }
    v10 = (const float *)&v32[v7];
    while ( 1 )
    {
      Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUniform(
        (Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair> *)v4->ShaderData.UniformData,
        &v4->ShaderData.CurShaders,
        0xDu,
        v10,
        8u,
        0,
        batch);
      v34 = -16777089;
      ((void (__fastcall *)(Scaleform::Render::ProfileViews *, int *, int *))v4->Profiler.vfptr->GetClearColor)(
        &v4->Profiler,
        &v31,
        &v34);
      if ( BYTE2(v31) )
        v11 = (float)BYTE2(v31) * 0.0039215689;
      else
        v11 = 0.0;
      if ( BYTE1(v31) )
        v12 = (float)BYTE1(v31) * 0.0039215689;
      else
        v12 = 0.0;
      if ( (_BYTE)v31 )
        v13 = (float)(unsigned __int8)v31 * 0.0039215689;
      else
        v13 = 0.0;
      if ( HIBYTE(v31) )
        v14 = (float)HIBYTE(v31) * 0.0039215689;
      else
        v14 = 0.0;
      v15 = v4->ShaderData.CurShaders.pVDesc;
      v16 = v15->BatchUniforms;
      v17 = v16[5].Offset;
      if ( v17 < 0 )
      {
        v20 = v4->ShaderData.CurShaders.pFDesc->BatchUniforms;
        v21 = v20[5].Offset;
        if ( v21 < 0 )
        {
          v26 = v15->Uniforms;
          if ( v26[5].Size )
          {
            v27 = v26[5].ShadowOffset;
            *(float *)(v6 + 4 * v27) = v11;
            *(float *)(v6 + 4 * v27 + 4) = v12;
            *(float *)(v6 + 4 * v27 + 8) = v13;
            *(float *)(v6 + 4 * v27 + 12) = v14;
          }
          v28 = v4->ShaderData.CurShaders.pFDesc->Uniforms;
          if ( v28[5].Size )
          {
            v29 = v28[5].ShadowOffset;
            *(float *)(v6 + 4 * v29) = v11;
            *(float *)(v6 + 4 * v29 + 4) = v12;
            *(float *)(v6 + 4 * v29 + 8) = v13;
            *(float *)(v6 + 4 * v29 + 12) = v14;
          }
          v4->ShaderData.UniformSet[5] = 1;
          goto LABEL_37;
        }
        v18 = v21;
        v19 = (unsigned int)v20[5].Array;
      }
      else
      {
        v18 = v17;
        v19 = (unsigned int)v16[5].Array;
      }
      v22 = v15->Uniforms;
      if ( v22[v19].Size )
      {
        v23 = v22[v19].ShadowOffset + (unsigned __int64)(v18 * (unsigned int)(unsigned __int8)v22[v19].ElementSize);
        *(float *)(v6 + 4 * v23) = v11;
        *(float *)(v6 + 4 * v23 + 4) = v12;
        *(float *)(v6 + 4 * v23 + 8) = v13;
        *(float *)(v6 + 4 * v23 + 12) = v14;
      }
      v24 = v4->ShaderData.CurShaders.pFDesc->Uniforms;
      if ( v24[v19].Size )
      {
        v25 = v24[v19].ShadowOffset + (unsigned __int64)(v18 * (unsigned int)(unsigned __int8)v24[v19].ElementSize);
        *(float *)(v6 + 4 * v25) = v11;
        *(float *)(v6 + 4 * v25 + 4) = v12;
        *(float *)(v6 + 4 * v25 + 8) = v13;
        *(float *)(v6 + 4 * v25 + 12) = v14;
      }
      *(_BYTE *)((unsigned int)v19 + v6 + 4352) = 1;
LABEL_37:
      ++batch;
      v10 += 8;
      if ( batch >= v8 )
        goto LABEL_38;
    }
  }
LABEL_40:
  (*(void (__fastcall **)(void *))(*(_QWORD *)v5 + 24i64))(v5);
}

// File Line: 1133
// RVA: 0xA03780
void __fastcall Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface>::clearSolidRectangle(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *this, Scaleform::Render::Rect<int> *r, __int64 color, bool blend)
{
  bool v4; // bl
  Scaleform::Render::Color *v5; // r15
  Scaleform::Render::Rect<int> *v6; // rsi
  Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *v7; // rdi
  void *v8; // r14
  bool v9; // r9
  __int64 v10; // rdx
  float v11; // xmm3_4
  unsigned int v12; // xmm2_4
  float v13; // xmm1_4
  signed __int64 v14; // rbx
  Scaleform::Render::D3D1x::VertexShaderDesc *v15; // rcx
  Scaleform::Render::D3D1x::BatchVar *v16; // rax
  char v17; // dl
  int v18; // er10
  __int64 v19; // rax
  Scaleform::Render::D3D1x::BatchVar *v20; // rdx
  char v21; // al
  Scaleform::Render::D3D1x::UniformVar *v22; // r8
  float v23; // er13
  float v24; // er12
  float v25; // er15
  float v26; // er11
  unsigned __int64 v27; // rcx
  Scaleform::Render::D3D1x::UniformVar *v28; // r8
  unsigned __int64 v29; // rcx
  Scaleform::Render::D3D1x::UniformVar *v30; // rax
  float v31; // er8
  float v32; // er9
  float v33; // er10
  float v34; // er11
  __int64 v35; // rax
  Scaleform::Render::D3D1x::UniformVar *v36; // rcx
  __int64 v37; // rax
  float pr; // [rsp+48h] [rbp-41h]
  float pg; // [rsp+4Ch] [rbp-3Dh]
  float pb; // [rsp+50h] [rbp-39h]
  float pa; // [rsp+54h] [rbp-35h]
  Scaleform::Render::Matrix2x4<float> m0; // [rsp+60h] [rbp-29h]
  Scaleform::Render::Matrix2x4<float> v43; // [rsp+80h] [rbp-9h]
  char v44; // [rsp+F0h] [rbp+67h]
  Scaleform::Render::HAL::HALBlendState state; // [rsp+F8h] [rbp+6Fh]
  void *v46; // [rsp+100h] [rbp+77h]
  Scaleform::Render::Color v47; // [rsp+108h] [rbp+7Fh]

  v4 = blend;
  v5 = (Scaleform::Render::Color *)color;
  v6 = r;
  v7 = this;
  v8 = this->vfptr[60].__vecDelDtor((Scaleform::RefCountImplCore *)this, 5u);
  v46 = v8;
  (*(void (__fastcall **)(void *, const char *))(*(_QWORD *)v8 + 16i64))(v8, "HAL::clearSolidRectangle");
  Scaleform::Render::HAL::applyRasterMode((Scaleform::Render::HAL *)&v7->vfptr, 0);
  state = v7->CurrentBlendState;
  if ( v4 )
  {
    v9 = 1;
    v10 = 1i64;
  }
  else
  {
    v9 = 0;
    v10 = 16i64;
  }
  Scaleform::Render::HAL::applyBlendMode((Scaleform::Render::HAL *)&v7->vfptr, v10, 0, v9);
  v47 = (Scaleform::Render::Color)v5->Raw;
  *v5 = *(Scaleform::Render::Color *)((__int64 (__fastcall *)(Scaleform::Render::ProfileViews *, char *, Scaleform::Render::Color *))v7->Profiler.vfptr->GetClearColor)(
                                       &v7->Profiler,
                                       &v44,
                                       &v47);
  Scaleform::Render::Color::GetRGBAFloat(v5, &pr, &pg, &pb, &pa);
  v11 = (float)v6->y1;
  *(float *)&v12 = (float)(v6->y2 - v6->y1);
  v13 = (float)v6->x1;
  m0.M[0][0] = (float)(v6->x2 - v6->x1);
  *(_QWORD *)&m0.M[0][1] = 0i64;
  m0.M[0][3] = v13;
  m0.M[1][0] = 0.0;
  *(_QWORD *)&m0.M[1][1] = v12;
  m0.M[1][3] = v11;
  Scaleform::Render::Matrix2x4<float>::SetToAppend(&v43, &m0, &v7->Matrices.pObject->UserView);
  v14 = (signed __int64)&v7->ShaderData;
  Scaleform::Render::D3D1x::ShaderInterface::SetStaticShader(
    &v7->ShaderData,
    ST_BatchSolid,
    v7->MappedXY16iAlphaSolid[1]);
  if ( !v7->ShaderData.PrimitiveOpen )
  {
    v7->ShaderData.PrimitiveOpen = 1;
    *(_QWORD *)v7->ShaderData.UniformSet = 0i64;
    *(_QWORD *)&v7->ShaderData.UniformSet[8] = 0i64;
    *(_QWORD *)&v7->ShaderData.UniformSet[16] = 0i64;
    *(_WORD *)&v7->ShaderData.UniformSet[24] = 0;
    v7->ShaderData.Textures[0] = 0i64;
    v7->ShaderData.Textures[1] = 0i64;
    v7->ShaderData.Textures[2] = 0i64;
    v7->ShaderData.Textures[3] = 0i64;
  }
  Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUniform(
    (Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair> *)v7->ShaderData.UniformData,
    &v7->ShaderData.CurShaders,
    0xDu,
    (const float *)&v43,
    8u,
    0,
    0);
  v15 = v7->ShaderData.CurShaders.pVDesc;
  v16 = v15->BatchUniforms;
  v17 = v16[5].Offset;
  if ( v17 >= 0 )
  {
    v18 = v17;
    v19 = (unsigned int)v16[5].Array;
LABEL_10:
    v22 = v15->Uniforms;
    v23 = pr;
    v24 = pg;
    v25 = pb;
    v26 = pa;
    if ( v22[v19].Size )
    {
      v27 = v22[v19].ShadowOffset + (unsigned __int64)(v18 * (unsigned int)(unsigned __int8)v22[v19].ElementSize);
      *(float *)(v14 + 4 * v27) = pr;
      *(float *)(v14 + 4 * v27 + 4) = v24;
      *(float *)(v14 + 4 * v27 + 8) = v25;
      *(float *)(v14 + 4 * v27 + 12) = v26;
    }
    v28 = v7->ShaderData.CurShaders.pFDesc->Uniforms;
    if ( v28[v19].Size )
    {
      v29 = v28[v19].ShadowOffset + (unsigned __int64)(v18 * (unsigned int)(unsigned __int8)v28[v19].ElementSize);
      *(float *)(v14 + 4 * v29) = v23;
      *(float *)(v14 + 4 * v29 + 4) = v24;
      *(float *)(v14 + 4 * v29 + 8) = v25;
      *(float *)(v14 + 4 * v29 + 12) = v26;
    }
    *(_BYTE *)((unsigned int)v19 + v14 + 4352) = 1;
    goto LABEL_20;
  }
  v20 = v7->ShaderData.CurShaders.pFDesc->BatchUniforms;
  v21 = v20[5].Offset;
  if ( v21 >= 0 )
  {
    v18 = v21;
    v19 = (unsigned int)v20[5].Array;
    goto LABEL_10;
  }
  v30 = v15->Uniforms;
  v31 = pa;
  v32 = pb;
  v33 = pg;
  v34 = pr;
  if ( v30[5].Size )
  {
    v35 = v30[5].ShadowOffset;
    *(float *)(v14 + 4 * v35) = pr;
    *(float *)(v14 + 4 * v35 + 4) = v33;
    *(float *)(v14 + 4 * v35 + 8) = v32;
    *(float *)(v14 + 4 * v35 + 12) = v31;
  }
  v36 = v7->ShaderData.CurShaders.pFDesc->Uniforms;
  if ( v36[5].Size )
  {
    v37 = v36[5].ShadowOffset;
    *(float *)(v14 + 4 * v37) = v34;
    *(float *)(v14 + 4 * v37 + 4) = v33;
    *(float *)(v14 + 4 * v37 + 8) = v32;
    *(float *)(v14 + 4 * v37 + 12) = v31;
  }
  v7->ShaderData.UniformSet[5] = 1;
LABEL_20:
  Scaleform::Render::D3D1x::ShaderInterface::Finish(&v7->ShaderData, 1u);
  ((void (__fastcall *)(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *))v7->vfptr[75].__vecDelDtor)(v7);
  Scaleform::Render::HAL::applyBlendMode((Scaleform::Render::HAL *)&v7->vfptr, &state);
  Scaleform::Render::HAL::applyRasterMode((Scaleform::Render::HAL *)&v7->vfptr, v7->CurrentSceneRasterMode);
  (*(void (__fastcall **)(void *))(*(_QWORD *)v8 + 24i64))(v8);
}

// File Line: 1176
// RVA: 0xA05D40
void __fastcall Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface>::profilerDrawCacheablePrimArea(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *this, Scaleform::Render::CacheablePrimitive *prim)
{
  Scaleform::Render::CacheablePrimitive *v2; // rbp
  Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *v3; // rsi
  Scaleform::Render::ProfileViewsVtbl *v4; // rax
  Scaleform::Render::Color *v5; // rax
  signed __int64 v6; // rbx
  Scaleform::Render::D3D1x::VertexShaderDesc *v7; // rdx
  Scaleform::Render::D3D1x::BatchVar *v8; // rax
  char v9; // cl
  signed __int64 v10; // rax
  int v11; // er10
  Scaleform::Render::D3D1x::BatchVar *v12; // rcx
  char v13; // al
  Scaleform::Render::D3D1x::UniformVar *v14; // rdx
  float v15; // er15
  float v16; // er14
  float v17; // ebp
  float v18; // er11
  signed __int64 v19; // r9
  unsigned __int64 v20; // rcx
  Scaleform::Render::D3D1x::UniformVar *v21; // rdx
  unsigned __int64 v22; // rcx
  Scaleform::Render::D3D1x::UniformVar *v23; // rax
  float v24; // er8
  float v25; // er9
  float v26; // edx
  float v27; // er10
  __int64 v28; // rax
  Scaleform::Render::D3D1x::UniformVar *v29; // rcx
  __int64 v30; // rax
  float pr; // [rsp+40h] [rbp-58h]
  float pg; // [rsp+44h] [rbp-54h]
  float pb; // [rsp+48h] [rbp-50h]
  float pa; // [rsp+4Ch] [rbp-4Ch]
  Scaleform::Render::Matrix2x4<float> v35; // [rsp+50h] [rbp-48h]
  int v36; // [rsp+A0h] [rbp+8h]
  char v37; // [rsp+A8h] [rbp+10h]

  v2 = prim;
  v3 = this;
  (*(void (__fastcall **)(Scaleform::Render::ProfileViews *, signed __int64))&this->Profiler.vfptr->gap8[8])(
    &this->Profiler,
    2i64);
  v4 = v3->Profiler.vfptr;
  v36 = -1;
  v5 = (Scaleform::Render::Color *)((__int64 (__fastcall *)(Scaleform::Render::ProfileViews *, char *, int *))v4->GetColor)(
                                     &v3->Profiler,
                                     &v37,
                                     &v36);
  Scaleform::Render::Color::GetRGBAFloat(v5, &pr, &pg, &pb, &pa);
  v6 = (signed __int64)&v3->ShaderData;
  Scaleform::Render::D3D1x::ShaderInterface::SetStaticShader(
    &v3->ShaderData,
    ST_BatchSolid,
    v3->MappedXY16iAlphaSolid[1]);
  if ( !v3->ShaderData.PrimitiveOpen )
  {
    v3->ShaderData.PrimitiveOpen = 1;
    *(_QWORD *)v3->ShaderData.UniformSet = 0i64;
    *(_QWORD *)&v3->ShaderData.UniformSet[8] = 0i64;
    *(_QWORD *)&v3->ShaderData.UniformSet[16] = 0i64;
    *(_WORD *)&v3->ShaderData.UniformSet[24] = 0;
    v3->ShaderData.Textures[0] = 0i64;
    v3->ShaderData.Textures[1] = 0i64;
    v3->ShaderData.Textures[2] = 0i64;
    v3->ShaderData.Textures[3] = 0i64;
  }
  Scaleform::Render::Matrix2x4<float>::SetToAppend(
    &v35,
    (Scaleform::Render::Matrix2x4<float> *)&v2->PrimitiveArea.Data.Data->pHandle->pHeader[(unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[v2->PrimitiveArea.Data.Data->pHandle->pHeader->Format & 0xF].Offsets[4]
                                                                                        + 1],
    &v3->Matrices.pObject->UserView);
  Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUniform(
    (Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair> *)v3->ShaderData.UniformData,
    &v3->ShaderData.CurShaders,
    0xDu,
    (const float *)&v35,
    8u,
    0,
    0);
  v7 = v3->ShaderData.CurShaders.pVDesc;
  v8 = v7->BatchUniforms;
  v9 = v8[5].Offset;
  if ( v9 >= 0 )
  {
    v10 = (unsigned int)v8[5].Array;
    v11 = v9;
LABEL_7:
    v14 = v7->Uniforms;
    v15 = pr;
    v16 = pg;
    v17 = pb;
    v18 = pa;
    v19 = v10;
    if ( v14[v10].Size )
    {
      v20 = v14[v19].ShadowOffset + (unsigned __int64)(v11 * (unsigned int)(unsigned __int8)v14[v19].ElementSize);
      *(float *)(v6 + 4 * v20) = pr;
      *(float *)(v6 + 4 * v20 + 4) = v16;
      *(float *)(v6 + 4 * v20 + 8) = v17;
      *(float *)(v6 + 4 * v20 + 12) = v18;
    }
    v21 = v3->ShaderData.CurShaders.pFDesc->Uniforms;
    if ( v21[v19].Size )
    {
      v22 = v21[v19].ShadowOffset + (unsigned __int64)(v11 * (unsigned int)(unsigned __int8)v21[v19].ElementSize);
      *(float *)(v6 + 4 * v22) = v15;
      *(float *)(v6 + 4 * v22 + 4) = v16;
      *(float *)(v6 + 4 * v22 + 8) = v17;
      *(float *)(v6 + 4 * v22 + 12) = v18;
    }
    *(_BYTE *)((unsigned int)v10 + v6 + 4352) = 1;
    goto LABEL_17;
  }
  v12 = v3->ShaderData.CurShaders.pFDesc->BatchUniforms;
  v13 = v12[5].Offset;
  if ( v13 >= 0 )
  {
    v11 = v13;
    v10 = (unsigned int)v12[5].Array;
    goto LABEL_7;
  }
  v23 = v7->Uniforms;
  v24 = pb;
  v25 = pg;
  v26 = pa;
  v27 = pr;
  if ( v23[5].Size )
  {
    v28 = v23[5].ShadowOffset;
    *(float *)(v6 + 4 * v28) = pr;
    *(float *)(v6 + 4 * v28 + 4) = v25;
    *(float *)(v6 + 4 * v28 + 8) = v24;
    *(float *)(v6 + 4 * v28 + 12) = v26;
  }
  v29 = v3->ShaderData.CurShaders.pFDesc->Uniforms;
  if ( v29[5].Size )
  {
    v30 = v29[5].ShadowOffset;
    *(float *)(v6 + 4 * v30) = v27;
    *(float *)(v6 + 4 * v30 + 4) = v25;
    *(float *)(v6 + 4 * v30 + 8) = v24;
    *(float *)(v6 + 4 * v30 + 12) = v26;
  }
  v3->ShaderData.UniformSet[5] = 1;
LABEL_17:
  Scaleform::Render::D3D1x::ShaderInterface::Finish(&v3->ShaderData, 1u);
  ((void (__fastcall *)(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *))v3->vfptr[87].__vecDelDtor)(v3);
  ((void (__fastcall *)(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *, signed __int64, signed __int64))v3->vfptr[95].__vecDelDtor)(
    v3,
    6i64,
    1i64);
}

// File Line: 1195
// RVA: 0xA05CD0
void __fastcall Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface>::profilerApplyUniform(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *this, Scaleform::Render::ProfilerUniform uniform, unsigned int components, float *values)
{
  if ( uniform )
  {
    if ( uniform == 1 )
      Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUniform(
        (Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair> *)this->ShaderData.UniformData,
        &this->ShaderData.CurShaders,
        0xCu,
        values,
        components,
        0,
        0);
  }
  else
  {
    Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUniform(
      (Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair> *)this->ShaderData.UniformData,
      &this->ShaderData.CurShaders,
      0x17u,
      values,
      components,
      0,
      0);
  }
}

