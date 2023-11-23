// File Line: 59
// RVA: 0x9FE120
void __fastcall Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface>::DrawableCopyChannel(
        Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *this,
        Scaleform::Render::Texture **tex,
        Scaleform::Render::Matrix2x4<float> *texgen,
        Scaleform::Render::Matrix4x4<float> *cxmul)
{
  ((void (__fastcall *)(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *, Scaleform::Render::Texture **, Scaleform::Render::Matrix2x4<float> *, Scaleform::Render::Matrix4x4<float> *))this->vfptr[55].__vecDelDtor)(
    this,
    tex,
    texgen,
    cxmul);
}

// File Line: 108
// RVA: 0x9FB3C0
void __fastcall Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface>::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface>(
        Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *this,
        Scaleform::Render::ThreadCommandQueue *commandQueue)
{
  Scaleform::Render::HAL::HAL(this, commandQueue);
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface>::`vftable;
  this->Shader.pVS = 0i64;
  this->Shader.pVDesc = 0i64;
  this->Shader.pFS = 0i64;
  this->Shader.pFDesc = 0i64;
  this->Shader.pVFormat = 0i64;
  Scaleform::Render::D3D1x::ShaderManager::ShaderManager(&this->SManager, &this->Profiler);
  this->ShaderData.PrimitiveOpen = 0;
  this->ShaderData.Textures[0] = 0i64;
  this->ShaderData.Textures[1] = 0i64;
  this->ShaderData.Textures[2] = 0i64;
  this->ShaderData.Textures[3] = 0i64;
  *(_QWORD *)this->ShaderData.UniformSet = 0i64;
  *(_QWORD *)&this->ShaderData.UniformSet[8] = 0i64;
  *(_QWORD *)&this->ShaderData.UniformSet[16] = 0i64;
  *(_WORD *)&this->ShaderData.UniformSet[24] = 0;
  this->ShaderData.pHal = (Scaleform::Render::D3D1x::HAL *)this;
  this->ShaderData.CurShaders.pVS = 0i64;
  this->ShaderData.CurShaders.pVDesc = 0i64;
  this->ShaderData.CurShaders.pFS = 0i64;
  this->ShaderData.CurShaders.pFDesc = 0i64;
  this->ShaderData.CurShaders.pVFormat = 0i64;
  this->ShaderData.pLastVS = 0i64;
  this->ShaderData.pLastFS = 0i64;
  this->ShaderData.pLastDecl = 0i64;
  this->MappedXY16iAlphaTexture[0] = 0i64;
  this->MappedXY16iAlphaTexture[1] = 0i64;
  this->MappedXY16iAlphaTexture[2] = 0i64;
  this->MappedXY16iAlphaSolid[0] = 0i64;
  this->MappedXY16iAlphaSolid[1] = 0i64;
  this->MappedXY16iAlphaSolid[2] = 0i64;
}

// File Line: 115
// RVA: 0x9FCCC0
char __fastcall Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface>::BeginScene(
        Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *this)
{
  char result; // al

  result = Scaleform::Render::HAL::BeginScene(this);
  if ( result )
  {
    _((AMD_HD3D *)&this->SManager);
    Scaleform::Render::D3D1x::ShaderInterface::BeginScene(&this->ShaderData);
    return 1;
  }
  return result;
}

// File Line: 126
// RVA: 0x9FEC40
char __fastcall Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface>::EndScene(
        Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *this)
{
  char result; // al

  result = Scaleform::Render::HAL::EndScene(this);
  if ( result )
  {
    _((AMD_HD3D *)&this->SManager);
    return 1;
  }
  return result;
}

// File Line: 136
// RVA: 0x9FEF50
__int64 __fastcall Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface>::GetMaximumBatchCount(
        Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *this,
        Scaleform::Render::Primitive *prim)
{
  __int64 result; // rax
  char v4; // dl
  Scaleform::Render::PrimitiveFill *pObject; // r8
  unsigned int v6; // ebx
  Scaleform::Render::PrimitiveFillType Type; // ecx
  unsigned __int8 v8; // al

  if ( prim )
  {
    pObject = prim->pFill.pObject;
    v6 = 4;
    if ( (prim->Meshes.Data.Data->M.pHandle->pHeader->Format & 0x10) != 0 )
      v6 = 6;
    if ( pObject )
    {
      Type = pObject->Data.Type;
      if ( (unsigned int)(Type - 5) > 5 )
        v8 = 0;
      else
        v8 = ((unsigned int)(Type - 9) <= 1) + 1;
      v6 += 2 * v8;
    }
    result = this->SManager.vfptr->GetNumberOfUniforms(&this->SManager) / v6;
    if ( (unsigned int)result > 0x18 )
      return 24i64;
  }
  else
  {
    result = 1i64;
    v4 = `Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface>::GetMaximumBatchCount::`6::warned;
    if ( !`Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface>::GetMaximumBatchCount::`6::warned )
      v4 = 1;
    `Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface>::GetMaximumBatchCount::`6::warned = v4;
  }
  return result;
}

// File Line: 168
// RVA: 0xA053F0
void __fastcall Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface>::drawUncachedFilter(
        Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *this,
        Scaleform::Render::HAL::FilterStackEntry *e)
{
  unsigned int Size; // r13d
  int v5; // r12d
  int v6; // esi
  unsigned int FilterPasses; // r15d
  Scaleform::Render::RenderTarget *v8; // rcx
  Scaleform::Render::RenderTarget *v9; // r8
  int v10; // edx
  __int64 v11; // rdx
  unsigned int v12; // r14d
  Scaleform::Render::Filter *Filter; // rbx
  int Type; // ecx
  __int64 v15; // rcx
  Scaleform::Render::RenderTarget *v16; // rbx
  unsigned int v17; // xmm3_4
  unsigned int v18; // xmm2_4
  float y1; // xmm1_4
  int Height; // ecx
  Scaleform::Render::RenderTarget *v21; // rbx
  Scaleform::Render::RenderTarget *v22; // rbx
  Scaleform::Render::RenderTarget *v23; // rcx
  Scaleform::Render::RenderTarget *v24; // rcx
  size_t vfptr; // rax
  Scaleform::Render::HAL::FilterStackEntry *v26; // rbx
  __int64 v27; // rdx
  Scaleform::Render::FilterPrimitive *v28; // rbx
  Scaleform::Render::MatrixPoolImpl::DataHeader *pHeader; // rdx
  unsigned int LastBlendModeOrDefault; // eax
  bool v31; // bl
  unsigned int v32; // eax
  Scaleform::Render::RenderTarget **p_ptr; // rbx
  __int64 v34; // rsi
  Scaleform::Render::RenderTarget *ptr; // [rsp+50h] [rbp-B0h] BYREF
  Scaleform::Render::RenderTarget *v36; // [rsp+58h] [rbp-A8h]
  Scaleform::Render::RenderTarget *v37; // [rsp+60h] [rbp-A0h]
  Scaleform::Render::RenderTarget *results; // [rsp+70h] [rbp-90h] BYREF
  Scaleform::Render::RenderTarget *v39; // [rsp+78h] [rbp-88h]
  Scaleform::Render::Filter *v40; // [rsp+80h] [rbp-80h]
  int v41[2]; // [rsp+88h] [rbp-78h] BYREF
  Scaleform::Render::Cxform *i; // [rsp+90h] [rbp-70h]
  Scaleform::Render::FilterSet *pObject; // [rsp+98h] [rbp-68h]
  int v44[4]; // [rsp+A0h] [rbp-60h] BYREF
  Scaleform::Render::Matrix2x4<float> result; // [rsp+B0h] [rbp-50h] BYREF
  __int64 v46; // [rsp+D0h] [rbp-30h]
  Scaleform::Render::RenderTarget *v47; // [rsp+D8h] [rbp-28h]
  __int64 v48; // [rsp+E0h] [rbp-20h] BYREF
  __int16 v49; // [rsp+E8h] [rbp-18h]
  char v50[96]; // [rsp+F0h] [rbp-10h] BYREF
  unsigned int passes[12]; // [rsp+1B0h] [rbp+B0h] BYREF
  char v53; // [rsp+3E0h] [rbp+2E0h]
  int v54; // [rsp+3E8h] [rbp+2E8h] BYREF

  v46 = -2i64;
  pObject = e->pPrimitive.pObject->pFilters.pObject;
  Size = BasicArrayImplementation<hkDataArrayImpl *>::getSize((BasicArrayImplementation<hkDataObjectImpl *> *)pObject);
  v5 = 0;
  v40 = 0i64;
  v6 = 0;
  FilterPasses = 0;
  if ( !e->pPrimitive.pObject || !e->pRenderTarget.pObject )
    return;
  `eh vector constructor iterator(
    &ptr,
    8ui64,
    3,
    (void (__fastcall *)(void *))Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>);
  v8 = 0i64;
  ptr = 0i64;
  v36 = 0i64;
  v37 = 0i64;
  v9 = e->pRenderTarget.pObject;
  v10 = v9->ViewRect.y2 - v9->ViewRect.y1;
  v41[0] = v9->ViewRect.x2 - v9->ViewRect.x1;
  v41[1] = v10;
  if ( v9 )
  {
    ((void (__fastcall *)(Scaleform::Render::RenderTarget *))v9->vfptr[1].__vecDelDtor)(v9);
    v8 = ptr;
  }
  if ( v8 )
    ((void (__fastcall *)(Scaleform::Render::RenderTarget *))v8->vfptr[2].__vecDelDtor)(v8);
  ptr = e->pRenderTarget.pObject;
  ((void (__fastcall *)(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *))this->vfptr[87].__vecDelDtor)(this);
  this->vfptr[78].__vecDelDtor(this, 1u);
  Scaleform::Render::HAL::applyBlendMode(this, 18i64, 1, 0);
  LOBYTE(v11) = 1;
  this->vfptr[41].__vecDelDtor(this, v11);
  v48 = 8i64;
  v49 = 0;
  `eh vector constructor iterator(
    v50,
    0x30ui64,
    3,
    (void (__fastcall *)(void *))Scaleform::Render::BlurFilterParams::BlurFilterParams);
  v12 = 0;
  for ( i = &Scaleform::Render::Cxform::Identity; v12 < Size; ++v12 )
  {
    Filter = Scaleform::Render::FilterSet::GetFilter(pObject, v12);
    v40 = Filter;
    FilterPasses = Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::GetFilterPasses(
                     &this->SManager,
                     Filter,
                     this->FillFlags,
                     passes);
    v53 = 0;
    Type = Filter->Type;
    if ( Type >= 1 && Type <= 5 )
    {
      v15 = (__int64)v37;
      if ( v37 )
      {
        v37->vfptr[5].__vecDelDtor(v37, 0);
        v15 = (__int64)v37;
      }
      if ( ptr )
      {
        ((void (__fastcall *)(Scaleform::Render::RenderTarget *))ptr->vfptr[1].__vecDelDtor)(ptr);
        v15 = (__int64)v37;
      }
      if ( v15 )
        (*(void (__fastcall **)(__int64))(*(_QWORD *)v15 + 16i64))(v15);
      v37 = ptr;
      v53 = 1;
    }
    v6 = 0;
    if ( FilterPasses )
    {
      while ( 1 )
      {
        if ( v6 == FilterPasses - 1 && v12 == Size - 1 )
          goto LABEL_48;
        v16 = v36;
        if ( !v36 )
        {
          v16 = (Scaleform::Render::RenderTarget *)((__int64 (__fastcall *)(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *, int *, _QWORD))this->vfptr[22].__vecDelDtor)(
                                                     this,
                                                     v41,
                                                     0i64);
          if ( v36 )
            ((void (__fastcall *)(Scaleform::Render::RenderTarget *))v36->vfptr[2].__vecDelDtor)(v36);
          v36 = v16;
          if ( !v16 )
            break;
        }
        *(float *)&v17 = (float)v16->ViewRect.y2;
        *(float *)&v18 = (float)v16->ViewRect.x2;
        y1 = (float)v16->ViewRect.y1;
        *(float *)&results = (float)v16->ViewRect.x1;
        *((float *)&results + 1) = y1;
        v39 = (Scaleform::Render::RenderTarget *)__PAIR64__(v17, v18);
        v54 = 0;
        ((void (__fastcall *)(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *, Scaleform::Render::RenderTarget **, Scaleform::Render::RenderTarget *, _QWORD, int *))this->vfptr[24].__vecDelDtor)(
          this,
          &results,
          v16,
          0i64,
          &v54);
        Height = v16->BufferSize.Height;
        v44[0] = v16->BufferSize.Width;
        v44[1] = Height;
        result = *(Scaleform::Render::Matrix2x4<float> *)this->Matrices.pObject->Scaleform::Render::HAL::vfptr[1].__vecDelDtor(
                                                           this->Matrices.pObject,
                                                           v44);
        ((void (__fastcall *)(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *, Scaleform::Render::Matrix2x4<float> *, Scaleform::Render::Cxform *, Scaleform::Render::Filter *, Scaleform::Render::RenderTarget **, unsigned int *, int, unsigned int, Scaleform::Render::VertexFormat *, __int64 *))this->vfptr[85].__vecDelDtor)(
          this,
          &result,
          &Scaleform::Render::Cxform::Identity,
          v40,
          &ptr,
          passes,
          v6,
          FilterPasses,
          this->MappedXY16iAlphaTexture[1],
          &v48);
        if ( v53 && !v6 )
        {
          v21 = (Scaleform::Render::RenderTarget *)((__int64 (__fastcall *)(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *, int *, _QWORD))this->vfptr[22].__vecDelDtor)(
                                                     this,
                                                     v41,
                                                     0i64);
          if ( ptr )
            ((void (__fastcall *)(Scaleform::Render::RenderTarget *))ptr->vfptr[2].__vecDelDtor)(ptr);
          ptr = v21;
          if ( !v21 )
          {
            vfptr = MEMORY[0];
            v24 = 0i64;
            goto LABEL_45;
          }
        }
        this->vfptr[25].__vecDelDtor(this, 4u);
        v22 = ptr;
        if ( ptr )
        {
          ((void (__fastcall *)(Scaleform::Render::RenderTarget *))ptr->vfptr[1].__vecDelDtor)(ptr);
          v22 = ptr;
        }
        v47 = v22;
        v23 = v36;
        if ( v36 )
        {
          ((void (__fastcall *)(Scaleform::Render::RenderTarget *))v36->vfptr[1].__vecDelDtor)(v36);
          v23 = v36;
        }
        if ( ptr )
        {
          ((void (__fastcall *)(Scaleform::Render::RenderTarget *))ptr->vfptr[2].__vecDelDtor)(ptr);
          v23 = v36;
        }
        ptr = v23;
        if ( v22 )
        {
          ((void (__fastcall *)(Scaleform::Render::RenderTarget *))v22->vfptr[1].__vecDelDtor)(v22);
          v23 = v36;
        }
        if ( v23 )
          ((void (__fastcall *)(Scaleform::Render::RenderTarget *))v23->vfptr[2].__vecDelDtor)(v23);
        v36 = v22;
        if ( v22 )
          ((void (__fastcall *)(Scaleform::Render::RenderTarget *))v22->vfptr[2].__vecDelDtor)(v22);
        if ( ++v6 >= FilterPasses )
          goto LABEL_48;
      }
      v24 = ptr;
      vfptr = (size_t)ptr->vfptr;
LABEL_45:
      (*(void (__fastcall **)(Scaleform::Render::RenderTarget *, _QWORD))(vfptr + 40))(v24, 0i64);
      if ( ptr )
        ((void (__fastcall *)(Scaleform::Render::RenderTarget *))ptr->vfptr[2].__vecDelDtor)(ptr);
      v12 = Size;
      ptr = 0i64;
      continue;
    }
LABEL_48:
    ;
  }
  if ( ptr && (this->Profiler.Scaleform::Render::HAL::vfptr->IsFilterCachingEnabled(&this->Profiler) || !FilterPasses) )
  {
    results = ptr;
    v39 = v37;
    LOBYTE(v5) = FilterPasses == 0;
    v26 = e;
    Scaleform::Render::CacheablePrimitive::SetCacheResults(
      e->pPrimitive.pObject,
      (Scaleform::Render::CacheablePrimitive::CacheState)(v5 + 1),
      &results,
      2 - (FilterPasses == 0));
    results->pRenderTargetData->CacheID = (unsigned __int64)e->pPrimitive.pObject;
    if ( v39 )
      v39->pRenderTargetData->CacheID = (unsigned __int64)e->pPrimitive.pObject;
  }
  else
  {
    v26 = e;
    Scaleform::Render::CacheablePrimitive::SetCacheResults(e->pPrimitive.pObject, Cache_Mesh, 0i64, 0);
  }
  this->vfptr[25].__vecDelDtor(this, 0);
  if ( this->MaskStackTop )
  {
    if ( this->StencilAvailable )
    {
      v27 = 5 - (unsigned int)((this->HALState & 0x40) != 0);
LABEL_60:
      this->vfptr[78].__vecDelDtor(this, v27);
      goto LABEL_61;
    }
    if ( this->DepthBufferAvailable )
    {
      v27 = 7 - (unsigned int)((this->HALState & 0x40) != 0);
      goto LABEL_60;
    }
  }
LABEL_61:
  this->vfptr[84].__vecDelDtor(this, this->CurrentSceneRasterMode);
  if ( FilterPasses )
  {
    v28 = v26->pPrimitive.pObject;
    Scaleform::Render::operator*(
      &result,
      &this->Matrices.pObject->UserView,
      (Scaleform::Render::Matrix2x4<float> *)&v28->PrimitiveArea.Data.Data->pHandle->pHeader[(unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[v28->PrimitiveArea.Data.Data->pHandle->pHeader->Format & 0xF].Offsets[4]
                                                                                           + 1]);
    pHeader = v28->PrimitiveArea.Data.Data->pHandle->pHeader;
    if ( (pHeader->Format & 1) != 0 )
      i = (Scaleform::Render::Cxform *)&pHeader[(unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[pHeader->Format & 0xF].Offsets[0]
                                              + 1];
    LastBlendModeOrDefault = Scaleform::Render::HAL::getLastBlendModeOrDefault(this);
    Scaleform::Render::HAL::applyBlendMode(this, LastBlendModeOrDefault, 1, 1);
    ((void (__fastcall *)(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *, Scaleform::Render::Matrix2x4<float> *, Scaleform::Render::Cxform *, Scaleform::Render::Filter *, Scaleform::Render::RenderTarget **, unsigned int *, int, unsigned int, Scaleform::Render::VertexFormat *, __int64 *))this->vfptr[85].__vecDelDtor)(
      this,
      &result,
      i,
      v40,
      &ptr,
      passes,
      v6,
      FilterPasses,
      this->MappedXY16iAlphaTexture[1],
      &v48);
    v31 = (this->HALState & 0x10) != 0;
    v32 = Scaleform::Render::HAL::getLastBlendModeOrDefault(this);
    Scaleform::Render::HAL::applyBlendMode(this, v32, 0, v31);
  }
  else
  {
    this->vfptr[50].__vecDelDtor(this, (unsigned int)v26->pPrimitive.pObject);
  }
  p_ptr = &ptr;
  v34 = 3i64;
  do
  {
    if ( *p_ptr )
      (*p_ptr)->vfptr[5].__vecDelDtor(*p_ptr, 0);
    ++p_ptr;
    --v34;
  }
  while ( v34 );
  this->AccumulatedStats.Filters += BasicArrayImplementation<hkDataArrayImpl *>::getSize((BasicArrayImplementation<hkDataObjectImpl *> *)pObject);
  `eh vector destructor iterator(
    v50,
    0x30ui64,
    3,
    (void (__fastcall *)(void *))Scaleform::Render::BlurFilterParams::~BlurFilterParams);
  `eh vector destructor iterator(
    &ptr,
    8ui64,
    3,
    (void (__fastcall *)(void *))ARefPtr<SSClassDescBase>::~ARefPtr<SSClassDescBase>);
}

// File Line: 341
// RVA: 0xA047A0
void __fastcall Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface>::drawCachedFilter(
        Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *this,
        Scaleform::Render::FilterPrimitive *primitive)
{
  __int64 v4; // rdx
  Scaleform::Render::D3D1x::ShaderDesc::ShaderType v5; // edx
  Scaleform::Render::Texture *v6; // r12
  Scaleform::Render::MatrixPoolImpl::HMatrix *Data; // rbx
  float y1; // xmm5_4
  float x1; // xmm4_4
  float v10; // xmm3_4
  Scaleform::Render::MatrixPoolImpl::DataHeader *pHeader; // rdx
  Scaleform::Render::Cxform *v12; // r8
  __int64 v13; // rdx
  unsigned int LastBlendModeOrDefault; // eax
  bool v15; // bl
  unsigned int v16; // eax
  Scaleform::Render::FilterSet *pObject; // rbx
  int Size; // eax
  Scaleform::Render::Filter *Filter; // rsi
  int FilterPasses; // r15d
  Scaleform::Render::RenderTarget *v21; // rbx
  int v22; // ecx
  Scaleform::Render::RenderTarget *v23; // rbx
  __int64 v24; // rbx
  _OWORD *v25; // rax
  float *v26; // rbx
  __int64 v27; // rdi
  float v[2]; // [rsp+50h] [rbp-B0h] BYREF
  Scaleform::Render::RenderTarget *v29; // [rsp+58h] [rbp-A8h]
  __int64 v30; // [rsp+60h] [rbp-A0h]
  float v31; // [rsp+68h] [rbp-98h]
  float v32; // [rsp+6Ch] [rbp-94h]
  Scaleform::Render::D3D1x::ShaderPair result; // [rsp+70h] [rbp-90h] BYREF
  Scaleform::Render::RenderTarget *v34; // [rsp+A0h] [rbp-60h] BYREF
  __int64 v35; // [rsp+B0h] [rbp-50h] BYREF
  float v36; // [rsp+B8h] [rbp-48h]
  float v37; // [rsp+BCh] [rbp-44h]
  Scaleform::Render::RenderTarget *v38; // [rsp+C0h] [rbp-40h] BYREF
  __int64 v39; // [rsp+C8h] [rbp-38h]
  __int64 v40; // [rsp+D0h] [rbp-30h]
  __int64 v41; // [rsp+E0h] [rbp-20h] BYREF
  __int16 v42; // [rsp+E8h] [rbp-18h]
  char ptr[96]; // [rsp+F0h] [rbp-10h] BYREF
  unsigned int passes[12]; // [rsp+1B0h] [rbp+B0h] BYREF
  char v45; // [rsp+3E0h] [rbp+2E0h] BYREF
  int v46; // [rsp+3E8h] [rbp+2E8h] BYREF
  Scaleform::Render::RenderTarget *results; // [rsp+3F0h] [rbp+2F0h] BYREF
  Scaleform::Render::RenderTarget *v48; // [rsp+3F8h] [rbp+2F8h] BYREF

  v40 = -2i64;
  ((void (__fastcall *)(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *))this->vfptr[87].__vecDelDtor)(this);
  LOBYTE(v4) = 1;
  this->vfptr[41].__vecDelDtor(this, v4);
  v41 = 8i64;
  v42 = 0;
  `eh vector constructor iterator(
    ptr,
    0x30ui64,
    3,
    (void (__fastcall *)(void *))Scaleform::Render::BlurFilterParams::BlurFilterParams);
  if ( primitive->Caching != Cache_Glyph )
  {
    if ( primitive->Caching != Cache_Count )
      goto LABEL_37;
    v5 = ST_BatchTexTGCxformAc;
    if ( (this->FillFlags & 1) != 0 )
      v5 = ST_BatchTexTGCxformAcMul;
    if ( (this->FillFlags & 2) != 0 )
      v5 += 64;
    if ( (this->FillFlags & 0x10) != 0 )
      v5 += 8;
    Scaleform::Render::D3D1x::ShaderInterface::SetStaticShader(&this->ShaderData, v5, this->MappedXY16iAlphaTexture[1]);
    if ( !this->ShaderData.PrimitiveOpen )
    {
      this->ShaderData.PrimitiveOpen = 1;
      *(_QWORD *)this->ShaderData.UniformSet = 0i64;
      *(_QWORD *)&this->ShaderData.UniformSet[8] = 0i64;
      *(_QWORD *)&this->ShaderData.UniformSet[16] = 0i64;
      *(_WORD *)&this->ShaderData.UniformSet[24] = 0;
      this->ShaderData.Textures[0] = 0i64;
      this->ShaderData.Textures[1] = 0i64;
      this->ShaderData.Textures[2] = 0i64;
      this->ShaderData.Textures[3] = 0i64;
    }
    Scaleform::Render::CacheablePrimitive::GetCacheResults(primitive, &results, 1u);
    v6 = (Scaleform::Render::Texture *)((__int64 (__fastcall *)(Scaleform::Render::RenderTarget *))results->vfptr[3].__vecDelDtor)(results);
    Data = primitive->PrimitiveArea.Data.Data;
    Scaleform::Render::operator*(
      (Scaleform::Render::Matrix2x4<float> *)&result,
      &this->Matrices.pObject->UserView,
      (Scaleform::Render::Matrix2x4<float> *)&Data->pHandle->pHeader[(unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[Data->pHandle->pHeader->Format & 0xF].Offsets[4]
                                                                   + 1]);
    y1 = (float)results->ViewRect.y1;
    x1 = (float)results->ViewRect.x1;
    v10 = (float)(results->ViewRect.y2 - results->ViewRect.y1) / (float)(int)v6->ImgSize.Height;
    v[0] = (float)(results->ViewRect.x2 - results->ViewRect.x1) / (float)(int)v6->ImgSize.Width;
    v[1] = v[0] * 0.0;
    *(float *)&v29 = v[0] * 0.0;
    *((float *)&v29 + 1) = x1 * v[0];
    *(float *)&v30 = v10 * 0.0;
    *((float *)&v30 + 1) = v10;
    v31 = v10 * 0.0;
    v32 = y1 * v10;
    pHeader = Data->pHandle->pHeader;
    if ( (pHeader->Format & 1) != 0 )
      v12 = (Scaleform::Render::Cxform *)&pHeader[(unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[pHeader->Format & 0xF].Offsets[0]
                                                + 1];
    else
      v12 = &Scaleform::Render::Cxform::Identity;
    Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetCxform(
      &this->ShaderData,
      &this->ShaderData.CurShaders,
      v12,
      0,
      0);
    Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUniform(
      &this->ShaderData,
      &this->ShaderData.CurShaders,
      0xDu,
      (const float *)&result,
      8u,
      0,
      0);
    Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUniform(
      &this->ShaderData,
      &this->ShaderData.CurShaders,
      0x15u,
      v,
      8u,
      0,
      0);
    result = this->ShaderData.CurShaders;
    v45 = 3;
    Scaleform::Render::D3D1x::ShaderInterface::SetTexture(
      &this->ShaderData,
      &result,
      0x14u,
      v6,
      (Scaleform::Render::ImageFillMode)&v45,
      0);
    Scaleform::Render::D3D1x::ShaderInterface::Finish(&this->ShaderData, 1u);
    this->vfptr[84].__vecDelDtor(this, this->CurrentSceneRasterMode);
    if ( !this->MaskStackTop )
      goto LABEL_20;
    if ( this->StencilAvailable )
    {
      v13 = 5 - (unsigned int)((this->HALState & 0x40) != 0);
    }
    else
    {
      if ( !this->DepthBufferAvailable )
        goto LABEL_20;
      v13 = 7 - (unsigned int)((this->HALState & 0x40) != 0);
    }
    this->vfptr[78].__vecDelDtor(this, v13);
LABEL_20:
    LastBlendModeOrDefault = Scaleform::Render::HAL::getLastBlendModeOrDefault(this);
    Scaleform::Render::HAL::applyBlendMode(this, LastBlendModeOrDefault, 1, 1);
    ((void (__fastcall *)(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *))this->vfptr[88].__vecDelDtor)(this);
    ((void (__fastcall *)(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *, __int64, __int64))this->vfptr[95].__vecDelDtor)(
      this,
      6i64,
      1i64);
    v15 = (this->HALState & 0x10) != 0;
    v16 = Scaleform::Render::HAL::getLastBlendModeOrDefault(this);
    Scaleform::Render::HAL::applyBlendMode(this, v16, 0, v15);
    results->vfptr[5].__vecDelDtor(results, 2u);
    if ( !this->Profiler.Scaleform::Render::HAL::vfptr->IsFilterCachingEnabled(&this->Profiler) )
      Scaleform::Render::CacheablePrimitive::SetCacheResults(primitive, Cache_Mesh, 0i64, 0);
    goto LABEL_37;
  }
  pObject = primitive->pFilters.pObject;
  Size = BasicArrayImplementation<hkDataArrayImpl *>::getSize((BasicArrayImplementation<hkDataObjectImpl *> *)pObject);
  Filter = Scaleform::Render::FilterSet::GetFilter(pObject, (unsigned int)(Size - 1));
  FilterPasses = Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::GetFilterPasses(
                   &this->SManager,
                   Filter,
                   this->FillFlags,
                   passes);
  `eh vector constructor iterator(
    v,
    8ui64,
    3,
    (void (__fastcall *)(void *))Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>);
  *(_QWORD *)v = 0i64;
  v29 = 0i64;
  v30 = 0i64;
  Scaleform::Render::CacheablePrimitive::GetCacheResults(primitive, &v38, 2u);
  v21 = v38;
  if ( v38 )
    ((void (__fastcall *)(Scaleform::Render::RenderTarget *))v38->vfptr[1].__vecDelDtor)(v38);
  if ( *(_QWORD *)v )
    (*(void (__fastcall **)(_QWORD))(**(_QWORD **)v + 16i64))(*(_QWORD *)v);
  *(_QWORD *)v = v21;
  v22 = v21->ViewRect.y2 - v21->ViewRect.y1;
  LODWORD(results) = v21->ViewRect.x2 - v21->ViewRect.x1;
  HIDWORD(results) = v22;
  v23 = (Scaleform::Render::RenderTarget *)((__int64 (__fastcall *)(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *, Scaleform::Render::RenderTarget **, _QWORD))this->vfptr[22].__vecDelDtor)(
                                             this,
                                             &results,
                                             0i64);
  if ( v29 )
    ((void (__fastcall *)(Scaleform::Render::RenderTarget *))v29->vfptr[2].__vecDelDtor)(v29);
  v29 = v23;
  v24 = v39;
  if ( v39 )
    (*(void (__fastcall **)(__int64))(*(_QWORD *)v39 + 8i64))(v39);
  if ( v30 )
    (*(void (__fastcall **)(__int64))(*(_QWORD *)v30 + 16i64))(v30);
  v30 = v24;
  v46 = 0;
  v35 = 0i64;
  v36 = (float)(int)results;
  v37 = (float)SHIDWORD(results);
  ((void (__fastcall *)(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *, __int64 *, Scaleform::Render::RenderTarget *, _QWORD, int *))this->vfptr[24].__vecDelDtor)(
    this,
    &v35,
    v29,
    0i64,
    &v46);
  v48 = results;
  v25 = this->Matrices.pObject->Scaleform::Render::HAL::vfptr[1].__vecDelDtor(this->Matrices.pObject, &v48);
  *(_OWORD *)&result.pVS = *v25;
  *(_OWORD *)&result.pFS = v25[1];
  Scaleform::Render::HAL::applyBlendMode(this, 1i64, 1, 1);
  ((void (__fastcall *)(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *, Scaleform::Render::D3D1x::ShaderPair *, Scaleform::Render::Cxform *, Scaleform::Render::Filter *, float *, unsigned int *, int, int, Scaleform::Render::VertexFormat *, __int64 *))this->vfptr[85].__vecDelDtor)(
    this,
    &result,
    &Scaleform::Render::Cxform::Identity,
    Filter,
    v,
    passes,
    FilterPasses - 1,
    FilterPasses,
    this->MappedXY16iAlphaTexture[1],
    &v41);
  this->vfptr[25].__vecDelDtor(this, 0);
  v34 = v29;
  Scaleform::Render::CacheablePrimitive::SetCacheResults(primitive, Cache_Count, &v34, 1u);
  v34->pRenderTargetData->CacheID = (unsigned __int64)primitive;
  this->vfptr[50].__vecDelDtor(this, (unsigned int)primitive);
  v26 = v;
  v27 = 3i64;
  do
  {
    if ( *(_QWORD *)v26 )
      (*(void (__fastcall **)(_QWORD, _QWORD))(**(_QWORD **)v26 + 40i64))(*(_QWORD *)v26, 0i64);
    v26 += 2;
    --v27;
  }
  while ( v27 );
  `eh vector destructor iterator(
    v,
    8ui64,
    3,
    (void (__fastcall *)(void *))ARefPtr<SSClassDescBase>::~ARefPtr<SSClassDescBase>);
LABEL_37:
  `eh vector destructor iterator(
    ptr,
    0x30ui64,
    3,
    (void (__fastcall *)(void *))Scaleform::Render::BlurFilterParams::~BlurFilterParams);
}

// File Line: 451
// RVA: 0xA04EC0
void __fastcall Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface>::drawFilter(
        Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *this,
        Scaleform::Render::Matrix2x4<float> *mvp,
        Scaleform::Render::Cxform *cx,
        Scaleform::Render::Filter *filter,
        Scaleform::Ptr<Scaleform::Render::RenderTarget> *targets,
        unsigned int *shaders,
        unsigned int pass,
        unsigned int passCount,
        Scaleform::Render::VertexFormat *pvf,
        Scaleform::Render::BlurFilterState *__formal)
{
  Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::SetFilterFill(
    &this->SManager,
    mvp,
    cx,
    filter,
    targets,
    shaders,
    pass,
    passCount,
    pvf,
    &this->ShaderData);
  ((void (__fastcall *)(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *))this->vfptr[88].__vecDelDtor)(this);
  ((void (__fastcall *)(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *, __int64, __int64))this->vfptr[95].__vecDelDtor)(
    this,
    6i64,
    1i64);
}

// File Line: 459
// RVA: 0x9FFEA0
void __fastcall Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface>::PushBlendMode(
        Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *this,
        Scaleform::GFx::Resource *prim)
{
  Scaleform::Render::BlendMode Value; // r15d
  unsigned int v5; // r13d
  Scaleform::ArrayLH<Scaleform::Render::HAL::BlendStackEntry,2,Scaleform::ArrayConstPolicy<0,8,1> > *p_BlendModeStack; // r14
  unsigned __int64 Size; // rcx
  Scaleform::Render::HAL::BlendStackEntry *v8; // rbx
  bool v9; // zf
  __int64 v10; // rbx
  unsigned __int64 v11; // rbx
  Scaleform::Render::HAL::BlendStackEntry *Data; // r12
  Scaleform::Render::MatrixPoolImpl::DataHeader *pHeader; // r14
  __int64 v14; // r15
  int v15; // ecx
  __int64 v16; // rcx
  Scaleform::Render::RenderTarget *pObject; // rax
  float v18; // xmm2_4
  float v19; // xmm3_4
  float v20; // xmm1_4
  int v21; // ecx
  __int64 v22; // r14
  Scaleform::Render::RenderTarget *v23; // rcx
  Scaleform::Render::BlendMode v24; // eax
  int v25; // r8d
  __int64 v26; // rdx
  __int64 v27; // rcx
  __int64 v28; // rbx
  __int64 v29; // rdx
  __int64 v30; // rcx
  float v31; // xmm2_4
  float v32; // xmm3_4
  float v33; // xmm1_4
  int v34; // eax
  int v35; // [rsp+40h] [rbp-30h] BYREF
  float v36; // [rsp+44h] [rbp-2Ch]
  float v37; // [rsp+48h] [rbp-28h]
  float v38; // [rsp+4Ch] [rbp-24h]
  Scaleform::GFx::Resource *v39; // [rsp+50h] [rbp-20h]
  __int64 v40; // [rsp+58h] [rbp-18h]
  __int64 v41; // [rsp+60h] [rbp-10h]
  __int16 v42; // [rsp+68h] [rbp-8h]
  __int64 v43; // [rsp+B0h] [rbp+40h] BYREF
  __int64 v44; // [rsp+C0h] [rbp+50h]

  if ( (this->HALState & 8) == 0 )
  {
    _((AMD_HD3D *)this);
    return;
  }
  Value = prim[3].RefCount.Value;
  Scaleform::Render::RenderBuffer::AddRef(prim);
  v39 = prim;
  v5 = 0;
  v40 = 0i64;
  v41 = 0i64;
  v42 = 0;
  p_BlendModeStack = &this->BlendModeStack;
  Scaleform::ArrayDataBase<Scaleform::Render::HAL::BlendStackEntry,Scaleform::AllocatorLH<Scaleform::Render::HAL::BlendStackEntry,2>,Scaleform::ArrayConstPolicy<0,8,1>>::ResizeNoConstruct(
    &this->BlendModeStack.Data,
    &this->BlendModeStack,
    this->BlendModeStack.Data.Size + 1);
  Size = this->BlendModeStack.Data.Size;
  v8 = this->BlendModeStack.Data.Data - 1;
  v9 = &v8[Size] == 0i64;
  v10 = (__int64)&v8[Size];
  v43 = v10;
  v44 = v10;
  if ( !v9 )
  {
    Scaleform::Render::RenderBuffer::AddRef(prim);
    *(_QWORD *)v10 = prim;
    *(_QWORD *)(v10 + 8) = 0i64;
    *(_QWORD *)(v10 + 16) = 0i64;
    *(_WORD *)(v10 + 24) = 0;
  }
  if ( (this->HALState & 0x300) == 0 )
  {
    v11 = this->BlendModeStack.Data.Size;
    Data = p_BlendModeStack->Data.Data;
    if ( !Scaleform::Render::BlendState::IsTargetAllocationNeededForBlendMode(prim[3].RefCount.Value) )
    {
      v24 = prim[3].RefCount.Value;
      if ( v24 == Blend_Alpha || v24 == Blend_Erase )
      {
        v25 = this->BlendModeStack.Data.Size - 1;
        v26 = v25;
        if ( v25 >= 0 )
        {
          v27 = (__int64)&p_BlendModeStack->Data.Data[v25];
          do
          {
            if ( *(_DWORD *)(*(_QWORD *)v27 + 80i64) == 2 )
              break;
            --v25;
            v27 -= 32i64;
            --v26;
          }
          while ( v26 >= 0 );
        }
        if ( !`Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface>::PushBlendMode::`26::warned )
          `Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface>::PushBlendMode::`26::warned = v25 < 0;
        if ( v25 < 0 )
        {
          Value = Blend_Ignore;
          Data[v11 - 1].NoLayerParent = 1;
        }
        else
        {
          v28 = (__int64)&p_BlendModeStack->Data.Data[v25];
          v29 = ***(_QWORD ***)(*(_QWORD *)v28 + 48i64);
          v30 = 16
              * (unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[*(_BYTE *)(v29 + 15) & 0xF].Offsets[4];
          v31 = *(float *)(v30 + v29 + 44);
          v32 = v31 + *(float *)(v30 + v29 + 36);
          v33 = *(float *)(v30 + v29 + 28) + *(float *)(v30 + v29 + 16);
          v35 = *(_DWORD *)(v30 + v29 + 28);
          v36 = v31;
          v37 = v33;
          v38 = v32;
          v34 = -16777216;
          if ( LOBYTE(prim[3].vfptr) )
            v34 = 0;
          LODWORD(v43) = v34;
          LOBYTE(v5) = *(_BYTE *)(v28 + 24) != 0;
          ((void (__fastcall *)(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *, int *, _QWORD, _QWORD, __int64 *))this->vfptr[24].__vecDelDtor)(
            this,
            &v35,
            *(_QWORD *)(v28 + 16),
            v5,
            &v43);
          *(_BYTE *)(v28 + 24) = 1;
        }
      }
      goto LABEL_31;
    }
    if ( !LODWORD(prim[1].vfptr) )
    {
      pHeader = Data[v11 - 1].pPrimitive.pObject->PrimitiveArea.Data.Data->pHandle->pHeader;
      v14 = (unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[pHeader->Format & 0xF].Offsets[4];
      v15 = (int)*((float *)&pHeader[v14 + 2].pHandle + 1);
      LODWORD(v43) = (int)*(float *)&pHeader[v14 + 1].pHandle;
      HIDWORD(v43) = v15;
      v16 = ((__int64 (__fastcall *)(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *, __int64 *, _QWORD))this->vfptr[22].__vecDelDtor)(
              this,
              &v43,
              LOBYTE(prim[3].vfptr));
      v44 = v16;
      pObject = Data[v11 - 1].pRenderTarget.pObject;
      if ( pObject )
      {
        ((void (__fastcall *)(Scaleform::Render::RenderTarget *))pObject->vfptr[2].__vecDelDtor)(Data[v11 - 1].pRenderTarget.pObject);
        v16 = v44;
      }
      Data[v11 - 1].pRenderTarget.pObject = (Scaleform::Render::RenderTarget *)v16;
      if ( v16 )
      {
        v18 = *(float *)&pHeader[v14 + 2].DataPageOffset;
        v19 = v18 + *((float *)&pHeader[v14 + 2].pHandle + 1);
        v20 = *(float *)&pHeader[v14 + 1].DataPageOffset + *(float *)&pHeader[v14 + 1].pHandle;
        v35 = *(_DWORD *)&pHeader[v14 + 1].DataPageOffset;
        v36 = v18;
        v37 = v20;
        v38 = v19;
        LODWORD(v43) = 0;
        ((void (__fastcall *)(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *, int *, __int64, _QWORD, __int64 *))this->vfptr[24].__vecDelDtor)(
          this,
          &v35,
          v16,
          0i64,
          &v43);
      }
      if ( prim[3].RefCount.Value == 2 )
      {
        v21 = (int)*((float *)&pHeader[v14 + 2].pHandle + 1);
        LODWORD(v43) = (int)*(float *)&pHeader[v14 + 1].pHandle;
        HIDWORD(v43) = v21;
        v22 = ((__int64 (__fastcall *)(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *, __int64 *, _QWORD))this->vfptr[22].__vecDelDtor)(
                this,
                &v43,
                0i64);
        v23 = Data[v11 - 1].pLayerAlpha.pObject;
        if ( v23 )
          ((void (__fastcall *)(Scaleform::Render::RenderTarget *))v23->vfptr[2].__vecDelDtor)(v23);
        Data[v11 - 1].pLayerAlpha.pObject = (Scaleform::Render::RenderTarget *)v22;
      }
      Value = Blend_Normal;
LABEL_31:
      Scaleform::Render::HAL::applyBlendMode(this, (unsigned int)Value, 0, (this->HALState & 0x10) != 0);
      goto LABEL_32;
    }
    this->HALState |= 0x200u;
    this->CacheableIndex = this->BlendModeStack.Data.Size - 1;
    *(_DWORD *)(((__int64 (__fastcall *)(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *))this->vfptr[64].__vecDelDtor)(this)
              + 48) = 1;
  }
LABEL_32:
  Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)prim);
}L_32:
  Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)prim);
}

// File Line: 550
// RVA: 0x9FF4F0
void __fastcall Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface>::PopBlendMode(
        Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *this)
{
  unsigned __int64 Size; // rbx
  Scaleform::Render::HAL::BlendStackEntry *Data; // rdi
  Scaleform::GFx::Resource *pObject; // rcx
  __int64 v5; // r14
  Scaleform::Render::RenderTarget *v6; // rcx
  __int64 v7; // r13
  Scaleform::Render::RenderTarget *v8; // rcx
  __int64 v9; // r12
  char NoLayerParent; // di
  unsigned int HALState; // eax
  unsigned int LastBlendModeOrDefault; // esi
  unsigned int v13; // ebx
  __int64 v14; // rdi
  unsigned __int64 v15; // rdi
  Scaleform::Render::HAL::RenderTargetEntry *v16; // rbx
  Scaleform::Render::RenderTarget *v17; // rcx
  __int64 v18; // rsi
  Scaleform::Render::RenderTarget *v19; // rbx
  Scaleform::Render::Cxform *Cxform; // rax
  char v21; // cl
  __int64 v22; // rdx
  unsigned __int64 v23; // r13
  Scaleform::Render::HAL::RenderTargetEntry *v24; // rbx
  Scaleform::Render::RenderTarget *v25; // rcx
  __int64 v26; // r13
  unsigned int v27; // xmm1_4
  unsigned int v28; // xmm0_4
  __int64 v29; // rax
  Scaleform::RefCountImplCoreVtbl *v30; // r14
  __int64 v31; // rax
  float y1; // xmm4_4
  float v33; // xmm3_4
  unsigned int v34; // ecx
  Scaleform::RefCountImplCoreVtbl *vfptr; // r14
  __int64 v36; // rax
  Scaleform::Render::ProfileViews *p_Profiler; // rcx
  Scaleform::Render::BlendMode mode; // [rsp+30h] [rbp-A9h]
  Scaleform::Render::CacheablePrimitive *v39; // [rsp+38h] [rbp-A1h]
  __int64 v40; // [rsp+40h] [rbp-99h]
  Scaleform::Render::RenderTarget *results; // [rsp+50h] [rbp-89h] BYREF
  unsigned __int64 v42; // [rsp+58h] [rbp-81h]
  __int128 v43; // [rsp+60h] [rbp-79h] BYREF
  __m128 v44; // [rsp+70h] [rbp-69h]
  __int64 v45; // [rsp+80h] [rbp-59h]
  __int64 v46; // [rsp+88h] [rbp-51h]
  __int64 v47; // [rsp+90h] [rbp-49h]
  __int64 v48; // [rsp+98h] [rbp-41h]
  __int64 v49; // [rsp+A0h] [rbp-39h]
  char v50; // [rsp+A8h] [rbp-31h]
  char v51; // [rsp+A9h] [rbp-30h]
  __int64 v52; // [rsp+B0h] [rbp-29h]
  __int64 v53; // [rsp+B8h] [rbp-21h]
  Scaleform::Render::Matrix2x4<float> result; // [rsp+C0h] [rbp-19h] BYREF
  bool v55; // [rsp+140h] [rbp+67h]
  Scaleform::Render::RenderTarget *v56; // [rsp+148h] [rbp+6Fh] BYREF
  __int64 pRenderTargetData; // [rsp+150h] [rbp+77h]
  unsigned int v58; // [rsp+158h] [rbp+7Fh]

  v53 = -2i64;
  if ( (this->HALState & 8) == 0 )
  {
    _((AMD_HD3D *)this);
    return;
  }
  Size = this->BlendModeStack.Data.Size;
  Data = this->BlendModeStack.Data.Data;
  pObject = (Scaleform::GFx::Resource *)Data[Size - 1].pPrimitive.pObject;
  if ( pObject )
    Scaleform::Render::RenderBuffer::AddRef(pObject);
  v5 = (__int64)Data[Size - 1].pPrimitive.pObject;
  v39 = (Scaleform::Render::CacheablePrimitive *)v5;
  v47 = v5;
  v6 = Data[Size - 1].pRenderTarget.pObject;
  if ( v6 )
    ((void (__fastcall *)(Scaleform::Render::RenderTarget *))v6->vfptr[1].__vecDelDtor)(v6);
  v7 = (__int64)Data[Size - 1].pRenderTarget.pObject;
  v40 = v7;
  v48 = v7;
  v8 = Data[Size - 1].pLayerAlpha.pObject;
  if ( v8 )
    ((void (__fastcall *)(Scaleform::Render::RenderTarget *))v8->vfptr[1].__vecDelDtor)(v8);
  v9 = (__int64)Data[Size - 1].pLayerAlpha.pObject;
  v49 = v9;
  LOBYTE(pRenderTargetData) = Data[Size - 1].LayerAlphaCleared;
  v50 = pRenderTargetData;
  NoLayerParent = Data[Size - 1].NoLayerParent;
  v51 = NoLayerParent;
  Scaleform::ArrayData<Scaleform::Render::HAL::BlendStackEntry,Scaleform::AllocatorLH<Scaleform::Render::HAL::BlendStackEntry,2>,Scaleform::ArrayConstPolicy<0,8,1>>::Resize(
    &this->BlendModeStack.Data,
    this->BlendModeStack.Data.Size - 1);
  HALState = this->HALState;
  if ( (HALState & 0x100) == 0
    && ((HALState & 0x300) == 0 || this->CacheableIndex >= (int)this->BlendModeStack.Data.Size) )
  {
    LastBlendModeOrDefault = Scaleform::Render::HAL::getLastBlendModeOrDefault(this);
    mode = LastBlendModeOrDefault;
    v55 = (this->HALState & 0x300) != 0;
    this->CacheableIndex = -1;
    v13 = *(_DWORD *)(v5 + 80);
    v58 = v13;
    if ( !Scaleform::Render::BlendState::IsTargetAllocationNeededForBlendMode(v13) )
    {
      if ( v13 - 11 <= 1 )
      {
        if ( NoLayerParent )
          LastBlendModeOrDefault = 1;
        else
          this->vfptr[25].__vecDelDtor(this, 0);
      }
      goto LABEL_90;
    }
    v14 = 0i64;
    v46 = 0i64;
    v45 = 0i64;
    if ( v55 )
    {
      Scaleform::Render::CacheablePrimitive::GetCacheResults((Scaleform::Render::CacheablePrimitive *)v5, &results, 2u);
      v19 = results;
      if ( results )
        ((void (__fastcall *)(Scaleform::Render::RenderTarget *))results->vfptr[1].__vecDelDtor)(results);
      v18 = v42;
      if ( v42 )
        (*(void (__fastcall **)(unsigned __int64))(*(_QWORD *)v42 + 8i64))(v42);
      v45 = v18;
LABEL_70:
      Scaleform::Render::operator*(
        &result,
        &this->Matrices.pObject->UserView,
        (Scaleform::Render::Matrix2x4<float> *)(***(_QWORD ***)(v5 + 48)
                                              + 16
                                              * (unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[*(_BYTE *)(***(_QWORD ***)(v5 + 48) + 15i64) & 0xF].Offsets[4]
                                              + 16i64));
      v43 = _xmm;
      v44 = _xmm;
      y1 = (float)v19->ViewRect.y1;
      *((float *)&v43 + 3) = (float)v19->ViewRect.x1;
      v44.m128_f32[3] = y1;
      v33 = (float)(v19->ViewRect.y2 - v19->ViewRect.y1) / (float)(int)v19->BufferSize.Height;
      *(float *)&v43 = (float)(v19->ViewRect.x2 - v19->ViewRect.x1) / (float)(int)v19->BufferSize.Width;
      *((float *)&v43 + 1) = *(float *)&v43 * 0.0;
      *((float *)&v43 + 2) = *(float *)&v43 * 0.0;
      *((float *)&v43 + 3) = *((float *)&v43 + 3) * *(float *)&v43;
      v44.m128_f32[0] = v33 * 0.0;
      v44.m128_f32[1] = v33;
      v44.m128_f32[2] = v33 * 0.0;
      v44.m128_f32[3] = y1 * v33;
      v34 = 16;
      if ( v58 == 2 )
        v34 = 2;
      Scaleform::Render::HAL::applyBlendMode(this, v34, 1, (this->HALState & 0x10) != 0);
      vfptr = this->vfptr;
      v36 = ((__int64 (__fastcall *)(Scaleform::Render::RenderTarget *))v19->vfptr[3].__vecDelDtor)(v19);
      ((void (__fastcall *)(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *, __int64, Scaleform::Render::Matrix2x4<float> *, __int128 *, _DWORD))vfptr[58].__vecDelDtor)(
        this,
        v36,
        &result,
        &v43,
        0);
      p_Profiler = &this->Profiler;
      if ( v55 )
      {
        v5 = (__int64)v39;
        if ( !p_Profiler->vfptr->IsBlendCachingEnabled(p_Profiler) )
          Scaleform::Render::CacheablePrimitive::SetCacheResults(v39, Cache_Mesh, 0i64, 0);
      }
      else
      {
        pRenderTargetData = (__int64)v19->pRenderTargetData;
        v5 = (__int64)v39;
        if ( p_Profiler->vfptr->IsBlendCachingEnabled(p_Profiler) )
        {
          v56 = v19;
          Scaleform::Render::CacheablePrimitive::SetCacheResults(v39, Cache_Count, &v56, 1u);
          *(_QWORD *)(pRenderTargetData + 24) = v39;
        }
      }
      if ( v14 )
        (*(void (__fastcall **)(__int64, _QWORD))(*(_QWORD *)v14 + 40i64))(v14, 0i64);
      if ( v18 )
        (*(void (__fastcall **)(__int64, _QWORD))(*(_QWORD *)v18 + 40i64))(v18, 0i64);
      v19->vfptr[5].__vecDelDtor(v19, 2u);
      if ( v18 )
        (*(void (__fastcall **)(__int64))(*(_QWORD *)v18 + 16i64))(v18);
      ((void (__fastcall *)(Scaleform::Render::RenderTarget *))v19->vfptr[2].__vecDelDtor)(v19);
      if ( v14 )
        (*(void (__fastcall **)(__int64))(*(_QWORD *)v14 + 16i64))(v14);
      LastBlendModeOrDefault = mode;
LABEL_90:
      if ( v55 )
      {
        *(_DWORD *)(((__int64 (__fastcall *)(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *))this->vfptr[64].__vecDelDtor)(this)
                  + 48) = 0;
        this->HALState &= 0xFFFFFCFF;
      }
      Scaleform::Render::HAL::applyBlendMode(this, LastBlendModeOrDefault, 0, (this->HALState & 0x10) != 0);
      goto LABEL_93;
    }
    v15 = this->RenderTargetStack.Data.Size;
    v16 = this->RenderTargetStack.Data.Data;
    v17 = v16[v15 - 1].pRenderTarget.pObject;
    if ( v17 )
      ((void (__fastcall *)(Scaleform::Render::RenderTarget *))v17->vfptr[1].__vecDelDtor)(v17);
    v14 = (__int64)v16[v15 - 1].pRenderTarget.pObject;
    v46 = v14;
    if ( v9 )
      (*(void (__fastcall **)(__int64))(*(_QWORD *)v9 + 8i64))(v9);
    v18 = v9;
    v45 = v9;
    if ( v14 )
      (*(void (__fastcall **)(__int64))(*(_QWORD *)v14 + 8i64))(v14);
    v19 = (Scaleform::Render::RenderTarget *)v14;
    if ( v7 )
    {
      if ( v58 != 2 )
        goto LABEL_26;
      if ( v9 )
      {
        if ( !(_BYTE)pRenderTargetData )
        {
          Cxform = Scaleform::Render::MatrixPoolImpl::HMatrix::GetCxform(*(Scaleform::Render::MatrixPoolImpl::HMatrix **)(v5 + 48));
          if ( Scaleform::Render::Cxform::operator==(Cxform, &Scaleform::Render::Cxform::Identity) )
          {
            v21 = 1;
            goto LABEL_27;
          }
        }
LABEL_26:
        v21 = 0;
LABEL_27:
        LOBYTE(v56) = v21;
        v22 = 4i64;
        if ( v21 )
          v22 = 0i64;
        this->vfptr[25].__vecDelDtor(this, v22);
        if ( !(_BYTE)v56 )
        {
          v23 = this->RenderTargetStack.Data.Size;
          v24 = this->RenderTargetStack.Data.Data;
          v25 = v24[v23 - 1].pRenderTarget.pObject;
          if ( v25 )
            ((void (__fastcall *)(Scaleform::Render::RenderTarget *))v25->vfptr[1].__vecDelDtor)(v25);
          v26 = (__int64)v24[v23 - 1].pRenderTarget.pObject;
          v52 = v26;
          v19 = (Scaleform::Render::RenderTarget *)((__int64 (__fastcall *)(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *, __int64, _QWORD))this->vfptr[22].__vecDelDtor)(
                                                     this,
                                                     v14 + 40,
                                                     0i64);
          if ( v14 )
            (*(void (__fastcall **)(__int64))(*(_QWORD *)v14 + 16i64))(v14);
          if ( !v19 )
          {
            Scaleform::Render::HAL::applyBlendMode(this, (unsigned int)mode, 0, (this->HALState & 0x10) != 0);
            if ( v26 )
              (*(void (__fastcall **)(__int64))(*(_QWORD *)v26 + 16i64))(v26);
            v7 = v40;
            goto LABEL_58;
          }
          *(float *)&v27 = (float)(v19->ViewRect.y2 - v19->ViewRect.y1);
          *(float *)&v28 = (float)(v19->ViewRect.x2 - v19->ViewRect.x1);
          LODWORD(v56) = 0;
          results = 0i64;
          v42 = __PAIR64__(v27, v28);
          ((void (__fastcall *)(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *, Scaleform::Render::RenderTarget **, Scaleform::Render::RenderTarget *, _QWORD, Scaleform::Render::RenderTarget **))this->vfptr[24].__vecDelDtor)(
            this,
            &results,
            v19,
            0i64,
            &v56);
          if ( !`Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface>::PopBlendMode::`22::warned )
            `Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface>::PopBlendMode::`22::warned = v58 != 2 && (!v26 || !(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v26 + 24i64))(v26));
          if ( v26 && (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v26 + 24i64))(v26)
            || v9 && (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v9 + 24i64))(v9) )
          {
            Scaleform::Render::HAL::applyBlendMode(this, 16i64, 0, 1);
            if ( v9 && (_BYTE)pRenderTargetData )
            {
              v56 = (Scaleform::Render::RenderTarget *)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v9 + 24i64))(v9);
              v29 = 0i64;
            }
            else
            {
              v29 = 0i64;
              v56 = 0i64;
            }
            if ( v58 != 2 )
              v29 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v26 + 24i64))(v26);
            pRenderTargetData = v29;
            v30 = this->vfptr;
            v31 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v14 + 24i64))(v14);
            ((void (__fastcall *)(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *, Scaleform::Render::CacheablePrimitive *, __int64, __int64, Scaleform::Render::RenderTarget *))v30[86].__vecDelDtor)(
              this,
              v39,
              v31,
              pRenderTargetData,
              v56);
            v5 = (__int64)v39;
          }
          this->vfptr[25].__vecDelDtor(this, 0);
          if ( v26 )
            (*(void (__fastcall **)(__int64))(*(_QWORD *)v26 + 16i64))(v26);
          v7 = v40;
        }
        goto LABEL_70;
      }
    }
    Scaleform::Render::HAL::applyBlendMode(this, (unsigned int)mode, 0, (this->HALState & 0x10) != 0);
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
void __fastcall Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface>::drawBlendPrimitive(
        Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *this,
        Scaleform::Render::BlendPrimitive *prim,
        Scaleform::Render::Texture *blendSource,
        Scaleform::Render::Texture *blendDest,
        Scaleform::Render::Texture *blendAlpha)
{
  Scaleform::Render::RenderTarget *pObject; // r11
  int v10; // r9d
  Scaleform::Render::MatrixPoolImpl::HMatrix *Data; // r8
  Scaleform::Render::MatrixPoolImpl::DataHeader *pHeader; // rdx
  Scaleform::Render::Cxform *v13; // rax
  Scaleform::Render::MatrixPoolImpl::DataHeader *v14; // r15
  __int64 v15; // r12
  float v16; // xmm5_4
  float v17; // xmm7_4
  float v18; // xmm3_4
  float v19; // xmm3_4
  float v20; // xmm5_4
  float v21; // xmm6_4
  float v22; // xmm3_4
  char texgen[40]; // [rsp+40h] [rbp-98h] BYREF
  __m128 v24; // [rsp+68h] [rbp-70h]
  Scaleform::Render::Matrix2x4<float> mvp_8; // [rsp+78h] [rbp-60h] BYREF
  Scaleform::Render::Texture *ptextures[4]; // [rsp+98h] [rbp-40h] BYREF
  Scaleform::Render::Cxform v27; // [rsp+B8h] [rbp-20h] BYREF
  Scaleform::Render::HAL::RenderTargetEntry v28; // [rsp+D8h] [rbp+0h] BYREF
  int v29[6]; // [rsp+438h] [rbp+360h] BYREF
  Scaleform::Render::MatrixState *p_OldMatrixState; // [rsp+458h] [rbp+380h]

  ptextures[3] = (Scaleform::Render::Texture *)-2i64;
  pObject = this->RenderTargetStack.Data.Data[this->RenderTargetStack.Data.Size - 1].pRenderTarget.pObject;
  v10 = pObject->ViewRect.y2 - pObject->ViewRect.y1;
  v29[0] = pObject->ViewRect.x2 - pObject->ViewRect.x1;
  v29[1] = v10;
  mvp_8 = *(Scaleform::Render::Matrix2x4<float> *)this->Matrices.pObject->Scaleform::Render::HAL::vfptr[1].__vecDelDtor(
                                                    this->Matrices.pObject,
                                                    v29);
  Data = prim->PrimitiveArea.Data.Data;
  pHeader = Data->pHandle->pHeader;
  if ( (pHeader->Format & 1) != 0 )
    v13 = (Scaleform::Render::Cxform *)&pHeader[(unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[pHeader->Format & 0xF].Offsets[0]
                                              + 1];
  else
    v13 = &Scaleform::Render::Cxform::Identity;
  v27 = *v13;
  *(_QWORD *)&mvp_8.M[0][0] = _xmm.m128_u64[1];
  *(_OWORD *)&texgen[24] = _xmm;
  v24 = _xmm;
  v14 = Data->pHandle->pHeader;
  v15 = (unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[v14->Format & 0xF].Offsets[4];
  v16 = *((float *)&v14[v15 + 2].pHandle + 1);
  v17 = *(float *)&v14[v15 + 1].pHandle;
  ptextures[0] = blendSource;
  ptextures[1] = blendDest;
  ptextures[2] = (Scaleform::Render::Texture *)p_OldMatrixState;
  v18 = v16 / (float)(int)blendSource->ImgSize.Height;
  *(float *)texgen = v17 / (float)(int)blendSource->ImgSize.Width;
  *(float *)&texgen[4] = *(float *)texgen * 0.0;
  *(float *)&texgen[8] = *(float *)texgen * 0.0;
  *(float *)&texgen[12] = *(float *)texgen * 0.0;
  *(float *)&texgen[16] = v18 * 0.0;
  *(float *)&texgen[20] = v18;
  *(float *)&texgen[24] = v18 * 0.0;
  *(float *)&texgen[28] = v18 * 0.0;
  if ( p_OldMatrixState )
  {
    v19 = v16 / (float)SLODWORD(p_OldMatrixState->View3D.M[0][1]);
    *(float *)&texgen[24] = v17 / (float)SLODWORD(p_OldMatrixState->View3D.M[0][0]);
    *(float *)&texgen[28] = *(float *)&texgen[24] * 0.0;
    *(float *)&texgen[32] = *(float *)&texgen[24] * 0.0;
    *(float *)&texgen[36] = *(float *)&texgen[24] * 0.0;
    v24.m128_f32[0] = v19 * 0.0;
    v24.m128_f32[1] = v19;
    v24.m128_f32[2] = v19 * 0.0;
    v24.m128_f32[3] = v19 * 0.0;
  }
  if ( blendDest )
  {
    v20 = v16 / (float)(int)blendDest->ImgSize.Height;
    *(float *)&texgen[32] = v17 / (float)(int)blendDest->ImgSize.Width;
    *(float *)&texgen[36] = *(float *)&texgen[32] * 0.0;
    v24.m128_f32[0] = *(float *)&texgen[32] * 0.0;
    v21 = v20 * 0.0;
    v24.m128_f32[2] = v20 * 0.0;
    v24.m128_f32[3] = v20;
    mvp_8.M[0][0] = v20 * 0.0;
    Scaleform::Render::HAL::RenderTargetEntry::RenderTargetEntry(
      &v28,
      &this->RenderTargetStack.Data.Data[this->RenderTargetStack.Data.Size - 1]);
    v22 = (float)(*(float *)&v14[v15 + 2].DataPageOffset - (float)v28.OldViewRect.y1)
        / (float)(int)blendDest->ImgSize.Height;
    v24.m128_f32[1] = (float)(*(float *)&texgen[32] * 0.0)
                    + (float)((float)(*(float *)&v14[v15 + 1].DataPageOffset - (float)v28.OldViewRect.x1)
                            / (float)(int)blendDest->ImgSize.Width);
    mvp_8.M[0][1] = v21 + v22;
    p_OldMatrixState = &v28.OldMatrixState;
    if ( v28.OldMatrixState.S3DImpl.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v28.OldMatrixState.S3DImpl.pObject);
    Scaleform::RefCountImplCore::~RefCountImplCore(&v28.OldMatrixState);
    if ( v28.pRenderTarget.pObject )
      ((void (__fastcall *)(Scaleform::Render::RenderTarget *))v28.pRenderTarget.pObject->vfptr[2].__vecDelDtor)(v28.pRenderTarget.pObject);
  }
  Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::SetBlendFill(
    &this->SManager,
    prim->BlendModeValue,
    &mvp_8,
    &v27,
    ptextures,
    (Scaleform::Render::Matrix2x4<float> *)texgen,
    this->MappedXY16iAlphaTexture[1],
    &this->ShaderData);
  ((void (__fastcall *)(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *))this->vfptr[75].__vecDelDtor)(this);
}

// File Line: 740
// RVA: 0x9FDCE0
void __fastcall Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface>::DrawProcessedPrimitive(
        Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *this,
        Scaleform::Render::Primitive *pprimitive,
        Scaleform::Render::PrimitiveBatch *pstart,
        Scaleform::Render::PrimitiveBatch *pend)
{
  void *v8; // rsi
  unsigned int v9; // r12d
  Scaleform::Render::PrimitiveBatch *v10; // rax
  Scaleform::Render::MeshCacheItem *pMeshItem; // rdi
  __int64 MeshIndex; // r8
  unsigned int meshCount; // r15d
  unsigned int v14; // edx
  Scaleform::Render::D3D1x::ShaderPair *v15; // r14
  Scaleform::Render::D3D1x::FragShader *pFS; // rcx
  __int64 v17; // rdx
  __int64 v18; // rax
  __int64 VertexCount; // r8
  __int64 IndexCount; // rdx
  Scaleform::Render::RenderSync *v21; // rax
  Scaleform::Render::Fence *inserted; // rax
  Scaleform::Render::Fence *v23; // rsi
  Scaleform::Render::Fence *pObject; // rcx
  Scaleform::Render::MeshCacheListSet *pCacheList; // rdx
  unsigned __int64 *p_Size; // rcx
  Scaleform::Render::MeshCacheListSet *v27; // rdx
  void *v28; // [rsp+50h] [rbp-48h]
  unsigned int fillFlags; // [rsp+A0h] [rbp+8h] BYREF
  Scaleform::Render::PrimitiveBatch *v30; // [rsp+B8h] [rbp+20h]

  v30 = pend;
  v8 = this->vfptr[60].__vecDelDtor(this, 9i64);
  v28 = v8;
  (*(void (__fastcall **)(void *, const char *))(*(_QWORD *)v8 + 16i64))(v8, "HAL::DrawProcessedPrimitive");
  if ( (this->HALState & 8) != 0 )
  {
    if ( LODWORD(pprimitive->Meshes.Data.Size) )
    {
      if ( !pstart )
        pstart = pprimitive->Batches.Root.pNext;
      v9 = 0;
      if ( pstart != pend )
      {
        v10 = v30;
        do
        {
          pMeshItem = pstart->MeshNode.pMeshItem;
          MeshIndex = pstart->MeshIndex;
          meshCount = pstart->MeshCount;
          if ( pMeshItem )
          {
            v14 = this->FillFlags;
            fillFlags = v14;
            if ( meshCount )
              fillFlags = pprimitive->Meshes.Data.Data->M.pHandle->pHeader->Format & 0x10 | v14;
            if ( !this->ShaderData.PrimitiveOpen )
            {
              this->ShaderData.PrimitiveOpen = 1;
              *(_QWORD *)this->ShaderData.UniformSet = 0i64;
              *(_QWORD *)&this->ShaderData.UniformSet[8] = 0i64;
              *(_QWORD *)&this->ShaderData.UniformSet[16] = 0i64;
              *(_WORD *)&this->ShaderData.UniformSet[24] = 0;
              this->ShaderData.Textures[0] = 0i64;
              this->ShaderData.Textures[1] = 0i64;
              this->ShaderData.Textures[2] = 0i64;
              this->ShaderData.Textures[3] = 0i64;
            }
            v15 = Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::SetPrimitiveFill(
                    &this->SManager,
                    pprimitive->pFill.pObject,
                    &fillFlags,
                    pstart->Type,
                    pstart->pFormat,
                    meshCount,
                    this->Matrices.pObject,
                    &pprimitive->Meshes.Data.Data[MeshIndex],
                    &this->ShaderData);
            this->Profiler.Scaleform::Render::HAL::vfptr->SetBatch(&this->Profiler, this, pprimitive, v9);
            if ( pstart->Type == DP_Instanced )
              ((void (__fastcall *)(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *, _QWORD, _QWORD))this->vfptr[94].__vecDelDtor)(
                this,
                pstart->MeshCount,
                pMeshItem->IndexCount);
            else
              ((void (__fastcall *)(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *))this->vfptr[93].__vecDelDtor)(this);
            Scaleform::Render::D3D1x::ShaderInterface::Finish(&this->ShaderData, meshCount);
            if ( (this->HALState & 0x20) != 0 )
            {
              if ( v15->pVS )
              {
                pFS = v15->pFS;
                if ( pFS )
                {
                  if ( v15->pVS->pProg.pObject && pFS->pProg.pObject && v15->pVFormat )
                  {
                    v17 = fillFlags >> 5;
                    LOBYTE(v17) = (fillFlags & 0x20) != 0;
                    this->vfptr[41].__vecDelDtor(this, v17);
                    v18 = ((__int64 (__fastcall *)(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *, Scaleform::Render::PrimitiveBatch *, Scaleform::Render::MeshCacheItem *))this->vfptr[90].__vecDelDtor)(
                            this,
                            pstart,
                            pMeshItem);
                    VertexCount = pMeshItem->VertexCount;
                    IndexCount = pMeshItem->IndexCount;
                    if ( pstart->Type == DP_Instanced )
                      ((void (__fastcall *)(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *, __int64, __int64, _QWORD, __int64, _QWORD))this->vfptr[97].__vecDelDtor)(
                        this,
                        IndexCount,
                        VertexCount,
                        pstart->MeshCount,
                        v18,
                        0i64);
                    else
                      ((void (__fastcall *)(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *, __int64, __int64, _QWORD, __int64, _QWORD))this->vfptr[96].__vecDelDtor)(
                        this,
                        IndexCount,
                        VertexCount,
                        pMeshItem->MeshCount,
                        v18,
                        0i64);
                  }
                }
              }
            }
            if ( ((__int64 (__fastcall *)(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *))this->vfptr[65].__vecDelDtor)(this) )
            {
              v21 = (Scaleform::Render::RenderSync *)((__int64 (__fastcall *)(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *))this->vfptr[65].__vecDelDtor)(this);
              inserted = Scaleform::Render::RenderSync::InsertFence(v21);
              v23 = inserted;
              if ( inserted )
                ++inserted->RefCount;
              pObject = pMeshItem->GPUFence.pObject;
              if ( pObject )
                Scaleform::Render::Fence::Release(pObject);
              pMeshItem->GPUFence.pObject = v23;
            }
            pCacheList = pMeshItem->pCacheList;
            pMeshItem->pPrev->pNext = pMeshItem->pNext;
            pMeshItem->pNext->Scaleform::ListNode<Scaleform::Render::MeshCacheItem>::$A6A32721DD821860D2CFF437DFF6F231::pPrev = pMeshItem->pPrev;
            pMeshItem->pPrev = (Scaleform::Render::MeshCacheItem *)-1i64;
            pMeshItem->pNext = (Scaleform::Render::MeshCacheItem *)-1i64;
            p_Size = &pCacheList->Slots[pMeshItem->ListType].Size;
            *p_Size -= pMeshItem->AllocSize;
            v27 = pMeshItem->pCacheList;
            pMeshItem->ListType = MCL_ThisFrame;
            pMeshItem->pNext = v27->Slots[2].Root.pNext;
            pMeshItem->pPrev = (Scaleform::Render::MeshCacheItem *)&v27->Slots[2];
            v27->Slots[2].Root.pNext->pPrev = pMeshItem;
            v27->Slots[2].Root.pNext = pMeshItem;
            v27->Slots[2].Size += pMeshItem->AllocSize;
            v10 = v30;
          }
          pstart = pstart->pNext;
          ++v9;
        }
        while ( pstart != v10 );
        v8 = v28;
      }
    }
  }
  else
  {
    _((AMD_HD3D *)this);
  }
  (*(void (__fastcall **)(void *))(*(_QWORD *)v8 + 24i64))(v8);
}art != v10 );
        v8 = v28;
      }
    }
  }
  else
  {
    _((AMD_HD3D *)this);
  }
  (*(void (_

// File Line: 814
// RVA: 0x9FD220
void __fastcall Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface>::DrawProcessedComplexMeshes(
        Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *this,
        Scaleform::Render::ComplexMesh *complexMesh,
        Scaleform::Render::StrideArray<Scaleform::Render::MatrixPoolImpl::HMatrix> *matrices)
{
  Scaleform::Render::StrideArray<Scaleform::Render::MatrixPoolImpl::HMatrix> *v3; // rsi
  Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *v5; // r14
  void *v6; // r12
  Scaleform::Render::MeshCacheItem *pCacheMeshItem; // rdi
  Scaleform::Render::ComplexMesh::FillRecord *Data; // r15
  __int64 v9; // rbx
  Scaleform::Render::D3D1x::ShaderInterface *p_ShaderData; // rdi
  Scaleform::Render::D3D1x::ShaderManager *p_SManager; // rax
  Scaleform::Render::D3D1x::ShaderPair *p_CurShaders; // r13
  Scaleform::Render::ProfileViews *p_Profiler; // r12
  __int64 v14; // rax
  unsigned int v15; // ebp
  unsigned int v16; // ebx
  int v17; // ebx
  __int64 v18; // rsi
  __int64 v19; // rbp
  __int64 v20; // rax
  Scaleform::Render::Cxform *v21; // r8
  signed int v22; // esi
  unsigned int v23; // ebp
  Scaleform::Render::VertexFormat *v24; // rbx
  Scaleform::Render::D3D1x::ShaderDesc::ShaderType v25; // eax
  __int64 v26; // rdx
  unsigned int v27; // ebx
  int Type; // eax
  unsigned int v29; // ebp
  Scaleform::Render::Matrix2x4<float> *p_VertexMatrix; // r8
  __int64 v31; // rax
  Scaleform::Render::MatrixPoolImpl::HMatrix *m2; // rbx
  Scaleform::Render::MatrixState *Matrices; // rcx
  unsigned int v34; // esi
  unsigned __int8 *v35; // rax
  float v36; // xmm0_4
  float v37; // xmm1_4
  float v38; // xmm2_4
  float v39; // xmm3_4
  Scaleform::Render::D3D1x::VertexShaderDesc *pVDesc; // r11
  Scaleform::Render::D3D1x::BatchVar *BatchUniforms; // rax
  char Offset; // r10
  __int64 v43; // rdx
  Scaleform::Render::D3D1x::UniformVar *v44; // r9
  int v45; // r8d
  __int64 v46; // r10
  __int64 v47; // rdx
  unsigned __int64 v48; // rcx
  Scaleform::Render::D3D1x::UniformVar *v49; // r9
  unsigned __int64 v50; // rcx
  Scaleform::Render::D3D1x::FragShaderDesc *pFDesc; // r8
  Scaleform::Render::D3D1x::BatchVar *v52; // rax
  char v53; // r10
  __int64 Array; // rdx
  int v55; // r9d
  __int64 v56; // r10
  __int64 v57; // rdx
  Scaleform::Render::D3D1x::UniformVar *v58; // r8
  unsigned __int64 v59; // rcx
  Scaleform::Render::D3D1x::UniformVar *v60; // r8
  unsigned __int64 v61; // rcx
  Scaleform::Render::D3D1x::UniformVar *Uniforms; // rax
  __int64 ShadowOffset; // rax
  Scaleform::Render::D3D1x::UniformVar *v64; // rcx
  __int64 v65; // rax
  Scaleform::Render::MatrixPoolImpl::DataHeader *pHeader; // rdx
  Scaleform::Render::Cxform *v67; // r8
  const float *v68; // rbx
  unsigned int v69; // esi
  unsigned int v70; // r12d
  __int64 v71; // rbp
  __int64 v72; // r14
  unsigned int *FillMatrixIndex; // r15
  Scaleform::Render::PrimitiveFill *pObject; // rax
  Scaleform::Render::Texture *v75; // rbx
  bool v76; // si
  unsigned int v77; // edx
  unsigned int v78; // ebx
  Scaleform::Render::RenderSync *v79; // rax
  Scaleform::Render::Fence *inserted; // rax
  Scaleform::Render::Fence *v81; // rbx
  Scaleform::Render::Fence *v82; // rcx
  Scaleform::Render::MeshCacheListSet *pCacheList; // rdx
  __int64 v84; // rcx
  Scaleform::Render::MeshCacheListSet *v85; // rdx
  char Fill; // [rsp+40h] [rbp-148h] BYREF
  bool IsSolid; // [rsp+41h] [rbp-147h]
  unsigned int fillflags; // [rsp+44h] [rbp-144h] BYREF
  unsigned int v89; // [rsp+48h] [rbp-140h]
  unsigned int meshCount; // [rsp+4Ch] [rbp-13Ch]
  unsigned int batchType; // [rsp+50h] [rbp-138h]
  unsigned int v92; // [rsp+54h] [rbp-134h]
  unsigned int v93; // [rsp+58h] [rbp-130h]
  Scaleform::Render::MeshCacheItem *v94; // [rsp+60h] [rbp-128h]
  int v95; // [rsp+68h] [rbp-120h]
  unsigned int Raw; // [rsp+6Ch] [rbp-11Ch] BYREF
  unsigned int v97; // [rsp+70h] [rbp-118h]
  Scaleform::Render::ComplexMesh::FillRecord *v98; // [rsp+78h] [rbp-110h]
  __int64 v99; // [rsp+80h] [rbp-108h]
  __int64 v100; // [rsp+88h] [rbp-100h]
  __int64 v101; // [rsp+90h] [rbp-F8h]
  char v102[8]; // [rsp+98h] [rbp-F0h] BYREF
  void *v103; // [rsp+A0h] [rbp-E8h]
  Scaleform::Render::Matrix2x4<float> *v104; // [rsp+A8h] [rbp-E0h]
  unsigned __int64 Size; // [rsp+B0h] [rbp-D8h]
  Scaleform::Render::Matrix2x4<float> *v106; // [rsp+B8h] [rbp-D0h]
  __int64 v107; // [rsp+C0h] [rbp-C8h]
  Scaleform::Render::Cxform v108; // [rsp+D0h] [rbp-B8h] BYREF
  Scaleform::Render::D3D1x::ShaderPair CurShaders; // [rsp+F0h] [rbp-98h] BYREF
  unsigned __int8 v113; // [rsp+1A8h] [rbp+20h]

  v107 = -2i64;
  v3 = matrices;
  v5 = this;
  v6 = this->vfptr[60].__vecDelDtor(this, 10i64);
  v103 = v6;
  (*(void (__fastcall **)(void *, const char *))(*(_QWORD *)v6 + 16i64))(v6, "HAL::DrawProcessedComplexMeshes");
  pCacheMeshItem = complexMesh->pCacheMeshItem;
  v94 = pCacheMeshItem;
  if ( (v5->HALState & 8) == 0 )
  {
    _((AMD_HD3D *)v5);
    goto LABEL_87;
  }
  if ( !pCacheMeshItem )
    goto LABEL_87;
  Data = complexMesh->FillRecords.Data.Data;
  v98 = Data;
  Size = complexMesh->FillRecords.Data.Size;
  v9 = v3->Size;
  v99 = v9;
  meshCount = 1;
  v104 = complexMesh->FillMatrixCache.Data.Data;
  v92 = 0;
  if ( !(_DWORD)Size )
    goto LABEL_80;
  p_ShaderData = &v5->ShaderData;
  p_SManager = &v5->SManager;
  p_CurShaders = &v5->ShaderData.CurShaders;
  p_Profiler = &v5->Profiler;
  do
  {
    if ( (unsigned int)v9 > 1
      && Scaleform::Render::D3D1x::ShaderManager::HasInstancingSupport(p_SManager)
      && Data->pFormats[1] )
    {
      v14 = ((__int64 (__fastcall *)(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *))v5->vfptr[62].__vecDelDtor)(v5);
      v15 = *(_DWORD *)((*(__int64 (__fastcall **)(__int64))(*(_QWORD *)(v14 + 8) + 16i64))(v14 + 8) + 48);
      if ( (unsigned int)v9 < v15 )
        v15 = v9;
      meshCount = v15;
      batchType = 2;
      v89 = 1;
    }
    else
    {
      batchType = 0;
      v89 = 0;
      v5->vfptr[93].__vecDelDtor(v5, 0);
    }
    v16 = v5->FillFlags;
    fillflags = v16;
    if ( (_DWORD)v99 )
    {
      v17 = v3->pData->pHandle->pHeader->Format & 0x10 | v16;
      fillflags = v17;
      v18 = 0i64;
      v19 = (unsigned int)v99;
      do
      {
        v20 = *(__int64 *)((char *)&matrices->pData->pHandle + matrices->StrideSize * v18);
        if ( (*(_BYTE *)(*(_QWORD *)v20 + 15i64) & 1) != 0 )
          v21 = (Scaleform::Render::Cxform *)(*(_QWORD *)v20
                                            + 16
                                            * (unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[*(_BYTE *)(*(_QWORD *)v20 + 15i64) & 0xF].Offsets[0]
                                            + 16i64);
        else
          v21 = &Scaleform::Render::Cxform::Identity;
        p_Profiler->vfptr->GetCxform(p_Profiler, &v108, v21);
        if ( !Scaleform::Render::Cxform::operator==(&v108, &Scaleform::Render::Cxform::Identity) )
        {
          v17 |= 8u;
          fillflags = v17;
        }
        if ( v108.M[0][3] < 1.0 )
        {
          v17 |= 0x20u;
          fillflags = v17;
        }
        ++v18;
        --v19;
      }
      while ( v19 );
      p_ShaderData = &v5->ShaderData;
      p_CurShaders = &v5->ShaderData.CurShaders;
    }
    v22 = p_Profiler->vfptr->GetFillType(p_Profiler, Data->pFill.pObject->Data.Type);
    v23 = v89;
    v24 = Data->pFormats[v89];
    v25 = Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::StaticShaderForFill(
            &v5->SManager,
            (Scaleform::Render::PrimitiveFillType)v22,
            &fillflags,
            batchType);
    Scaleform::Render::D3D1x::ShaderInterface::SetStaticShader(p_ShaderData, v25, v24);
    if ( !p_ShaderData->PrimitiveOpen )
    {
      p_ShaderData->PrimitiveOpen = 1;
      *(_QWORD *)p_ShaderData->UniformSet = 0i64;
      *(_QWORD *)&p_ShaderData->UniformSet[8] = 0i64;
      *(_QWORD *)&p_ShaderData->UniformSet[16] = 0i64;
      *(_WORD *)&p_ShaderData->UniformSet[24] = 0;
      p_ShaderData->Textures[0] = 0i64;
      p_ShaderData->Textures[1] = 0i64;
      p_ShaderData->Textures[2] = 0i64;
      p_ShaderData->Textures[3] = 0i64;
    }
    p_Profiler->vfptr->SetBatch(p_Profiler, v5, complexMesh, v92);
    v101 = ((__int64 (__fastcall *)(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *, Scaleform::Render::ComplexMesh::FillRecord *, _QWORD, Scaleform::Render::MeshCacheItem *))v5->vfptr[89].__vecDelDtor)(
             v5,
             Data,
             v23,
             v94);
    v27 = fillflags;
    LOBYTE(v26) = (fillflags & 0x20) != 0
               || Scaleform::Render::PrimitiveFillData::RequiresBlend(&Data->pFill.pObject->Data);
    v5->vfptr[41].__vecDelDtor(v5, v26);
    p_Profiler->vfptr->SetFillFlags(p_Profiler, v27);
    Type = Data->pFill.pObject->Data.Type;
    if ( Type < 5 )
      v113 = 0;
    else
      v113 = ((unsigned int)(Type - 9) <= 1) + 1;
    IsSolid = Scaleform::Render::PrimitiveFill::IsSolid(v22);
    v29 = 0;
    v93 = 0;
    LODWORD(v9) = v99;
    if ( (_DWORD)v99 )
    {
      p_VertexMatrix = &complexMesh->VertexMatrix;
      v106 = &complexMesh->VertexMatrix;
      v95 = v99 - 1;
      v31 = 0i64;
      v100 = 0i64;
      while ( 1 )
      {
        m2 = (Scaleform::Render::MatrixPoolImpl::HMatrix *)((char *)matrices->pData + matrices->StrideSize * v31);
        Matrices = v5->Matrices.pObject;
        v34 = v29 % meshCount;
        v97 = v29 % meshCount;
        Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetMatrix(
          p_ShaderData,
          p_CurShaders,
          0xDu,
          p_VertexMatrix,
          m2,
          Matrices,
          0,
          v29 % meshCount);
        if ( IsSolid )
        {
          Raw = Data->pFill.pObject->Data.SolidColor.Raw;
          v35 = (unsigned __int8 *)((__int64 (__fastcall *)(Scaleform::Render::ProfileViews *, char *, unsigned int *))p_Profiler->vfptr->GetColor)(
                                     p_Profiler,
                                     v102,
                                     &Raw);
          v36 = (float)v35[2] * 0.0039215689;
          v37 = (float)v35[1] * 0.0039215689;
          v38 = (float)*v35 * 0.0039215689;
          v39 = (float)v35[3] * 0.0039215689;
          pVDesc = p_CurShaders->pVDesc;
          BatchUniforms = pVDesc->BatchUniforms;
          Offset = BatchUniforms[5].Offset;
          if ( Offset < 0 )
          {
            pFDesc = p_CurShaders->pFDesc;
            v52 = pFDesc->BatchUniforms;
            v53 = v52[5].Offset;
            if ( v53 < 0 )
            {
              Uniforms = pVDesc->Uniforms;
              if ( Uniforms[5].Size )
              {
                ShadowOffset = Uniforms[5].ShadowOffset;
                p_ShaderData->UniformData[ShadowOffset] = v36;
                p_ShaderData->UniformData[ShadowOffset + 1] = v37;
                p_ShaderData->UniformData[ShadowOffset + 2] = v38;
                p_ShaderData->UniformData[ShadowOffset + 3] = v39;
              }
              v64 = p_CurShaders->pFDesc->Uniforms;
              if ( v64[5].Size )
              {
                v65 = v64[5].ShadowOffset;
                p_ShaderData->UniformData[v65] = v36;
                p_ShaderData->UniformData[v65 + 1] = v37;
                p_ShaderData->UniformData[v65 + 2] = v38;
                p_ShaderData->UniformData[v65 + 3] = v39;
              }
              p_ShaderData->UniformSet[5] = 1;
            }
            else
            {
              Array = (unsigned int)v52[5].Array;
              v55 = v53 + v34 * (unsigned __int8)pFDesc->Uniforms[Array].BatchSize;
              v56 = (unsigned int)Array;
              v57 = Array;
              v58 = pVDesc->Uniforms;
              if ( v58[v57].Size )
              {
                v59 = v58[v57].ShadowOffset
                    + (unsigned __int64)(v55 * (unsigned int)(unsigned __int8)v58[v57].ElementSize);
                p_ShaderData->UniformData[v59] = v36;
                p_ShaderData->UniformData[v59 + 1] = v37;
                p_ShaderData->UniformData[v59 + 2] = v38;
                p_ShaderData->UniformData[v59 + 3] = v39;
              }
              v60 = p_CurShaders->pFDesc->Uniforms;
              if ( v60[v57].Size )
              {
                v61 = v60[v57].ShadowOffset
                    + (unsigned __int64)(v55 * (unsigned int)(unsigned __int8)v60[v57].ElementSize);
                p_ShaderData->UniformData[v61] = v36;
                p_ShaderData->UniformData[v61 + 1] = v37;
                p_ShaderData->UniformData[v61 + 2] = v38;
                p_ShaderData->UniformData[v61 + 3] = v39;
              }
              p_ShaderData->UniformSet[v56] = 1;
            }
          }
          else
          {
            v43 = (unsigned int)BatchUniforms[5].Array;
            v44 = pVDesc->Uniforms;
            v45 = Offset + v34 * (unsigned __int8)v44[v43].BatchSize;
            v46 = (unsigned int)v43;
            v47 = v43;
            if ( v44[v47].Size )
            {
              v48 = v44[v47].ShadowOffset
                  + (unsigned __int64)(v45 * (unsigned int)(unsigned __int8)v44[v47].ElementSize);
              p_ShaderData->UniformData[v48] = v36;
              p_ShaderData->UniformData[v48 + 1] = v37;
              p_ShaderData->UniformData[v48 + 2] = v38;
              p_ShaderData->UniformData[v48 + 3] = v39;
            }
            v49 = p_CurShaders->pFDesc->Uniforms;
            if ( v49[v47].Size )
            {
              v50 = v49[v47].ShadowOffset
                  + (unsigned __int64)(v45 * (unsigned int)(unsigned __int8)v49[v47].ElementSize);
              p_ShaderData->UniformData[v50] = v36;
              p_ShaderData->UniformData[v50 + 1] = v37;
              p_ShaderData->UniformData[v50 + 2] = v38;
              p_ShaderData->UniformData[v50 + 3] = v39;
            }
            p_ShaderData->UniformSet[v46] = 1;
          }
          v113 = 0;
        }
        else if ( (fillflags & 8) != 0 )
        {
          pHeader = m2->pHandle->pHeader;
          if ( (pHeader->Format & 1) != 0 )
            v67 = (Scaleform::Render::Cxform *)&pHeader[(unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[pHeader->Format & 0xF].Offsets[0]
                                                      + 1];
          else
            v67 = &Scaleform::Render::Cxform::Identity;
          v68 = (const float *)p_Profiler->vfptr->GetCxform(p_Profiler, &v108, v67);
          Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUniform(
            p_ShaderData,
            p_CurShaders,
            5u,
            v68,
            4u,
            0,
            v34);
          Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUniform(
            p_ShaderData,
            p_CurShaders,
            4u,
            v68 + 4,
            4u,
            0,
            v34);
        }
        v69 = 0;
        v70 = 0;
        if ( v113 )
        {
          v71 = 0i64;
          v72 = 4i64;
          FillMatrixIndex = Data->FillMatrixIndex;
          do
          {
            Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUniform(
              p_ShaderData,
              &p_ShaderData->CurShaders,
              0x15u,
              (const float *)&v104[*FillMatrixIndex],
              8u,
              2 * v69,
              v97);
            pObject = v98->pFill.pObject;
            v75 = (Scaleform::Render::Texture *)(&v98->pFill.pObject->vfptr)[v72];
            CurShaders = p_ShaderData->CurShaders;
            Fill = pObject->Data.FillModes[v71].Fill;
            Scaleform::Render::D3D1x::ShaderInterface::SetTexture(
              p_ShaderData,
              &CurShaders,
              0x14u,
              v75,
              (Scaleform::Render::ImageFillMode)&Fill,
              v70);
            v70 += (unsigned __int8)v75->TextureCount;
            ++v69;
            ++v71;
            ++FillMatrixIndex;
            ++v72;
          }
          while ( v69 < v113 );
          v5 = this;
          Data = v98;
          v29 = v93;
        }
        v76 = v29 == v95;
        if ( batchType != 2 )
          break;
        v77 = (v29 + 1) % meshCount;
        if ( !v77 && v29 || v29 == v95 )
        {
          v78 = meshCount;
          if ( v29 == v95 && v77 )
            v78 = (v29 + 1) % meshCount;
          ((void (__fastcall *)(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *, _QWORD, _QWORD))v5->vfptr[94].__vecDelDtor)(
            v5,
            v78,
            Data->IndexCount);
          Scaleform::Render::D3D1x::ShaderInterface::Finish(p_ShaderData, v78);
          ((void (__fastcall *)(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *, Scaleform::Render::ComplexMesh::FillRecord *, _QWORD, Scaleform::Render::MeshCacheItem *))v5->vfptr[91].__vecDelDtor)(
            v5,
            Data,
            v89,
            v94);
          ((void (__fastcall *)(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *, _QWORD, _QWORD, _QWORD, __int64, _QWORD))v5->vfptr[97].__vecDelDtor)(
            v5,
            Data->IndexCount,
            Data->VertexCount,
            v78,
            v101 + Data->IndexOffset,
            0i64);
          goto LABEL_73;
        }
LABEL_76:
        v93 = ++v29;
        v31 = ++v100;
        LODWORD(v9) = v99;
        p_CurShaders = &p_ShaderData->CurShaders;
        p_Profiler = &v5->Profiler;
        p_VertexMatrix = v106;
        if ( v29 >= (unsigned int)v99 )
        {
          p_CurShaders = &p_ShaderData->CurShaders;
          p_Profiler = &v5->Profiler;
          goto LABEL_78;
        }
      }
      Scaleform::Render::D3D1x::ShaderInterface::Finish(p_ShaderData, 1u);
      ((void (__fastcall *)(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *, Scaleform::Render::ComplexMesh::FillRecord *, _QWORD, Scaleform::Render::MeshCacheItem *))v5->vfptr[91].__vecDelDtor)(
        v5,
        Data,
        v89,
        v94);
      ((void (__fastcall *)(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *, _QWORD, _QWORD, __int64, __int64, _QWORD))v5->vfptr[96].__vecDelDtor)(
        v5,
        Data->IndexCount,
        Data->VertexCount,
        1i64,
        v101 + Data->IndexOffset,
        0i64);
LABEL_73:
      ++v5->AccumulatedStats.Primitives;
      if ( !v76 && !p_ShaderData->PrimitiveOpen )
      {
        p_ShaderData->PrimitiveOpen = 1;
        *(_QWORD *)p_ShaderData->UniformSet = 0i64;
        *(_QWORD *)&p_ShaderData->UniformSet[8] = 0i64;
        *(_QWORD *)&p_ShaderData->UniformSet[16] = 0i64;
        *(_WORD *)&p_ShaderData->UniformSet[24] = 0;
        p_ShaderData->Textures[0] = 0i64;
        p_ShaderData->Textures[1] = 0i64;
        p_ShaderData->Textures[2] = 0i64;
        p_ShaderData->Textures[3] = 0i64;
      }
      goto LABEL_76;
    }
LABEL_78:
    ++v92;
    v98 = ++Data;
    v3 = matrices;
    p_SManager = &v5->SManager;
  }
  while ( v92 < (unsigned int)Size );
  pCacheMeshItem = v94;
  v6 = v103;
LABEL_80:
  if ( ((__int64 (__fastcall *)(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *))v5->vfptr[65].__vecDelDtor)(v5) )
  {
    v79 = (Scaleform::Render::RenderSync *)((__int64 (__fastcall *)(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *))v5->vfptr[65].__vecDelDtor)(v5);
    inserted = Scaleform::Render::RenderSync::InsertFence(v79);
    v81 = inserted;
    if ( inserted )
      ++inserted->RefCount;
    v82 = pCacheMeshItem->GPUFence.pObject;
    if ( v82 )
      Scaleform::Render::Fence::Release(v82);
    pCacheMeshItem->GPUFence.pObject = v81;
  }
  pCacheList = pCacheMeshItem->pCacheList;
  pCacheMeshItem->pPrev->pNext = pCacheMeshItem->pNext;
  pCacheMeshItem->pNext->Scaleform::ListNode<Scaleform::Render::MeshCacheItem>::$A6A32721DD821860D2CFF437DFF6F231::pPrev = pCacheMeshItem->pPrev;
  pCacheMeshItem->pPrev = (Scaleform::Render::MeshCacheItem *)-1i64;
  pCacheMeshItem->pNext = (Scaleform::Render::MeshCacheItem *)-1i64;
  v84 = 3 * ((int)pCacheMeshItem->ListType + 1i64);
  *((_QWORD *)&pCacheList->pCache + v84) -= pCacheMeshItem->AllocSize;
  v85 = pCacheMeshItem->pCacheList;
  pCacheMeshItem->ListType = MCL_ThisFrame;
  pCacheMeshItem->pNext = v85->Slots[2].Root.pNext;
  pCacheMeshItem->pPrev = (Scaleform::Render::MeshCacheItem *)&v85->Slots[2];
  v85->Slots[2].Root.pNext->pPrev = pCacheMeshItem;
  v85->Slots[2].Root.pNext = pCacheMeshItem;
  v85->Slots[2].Size += pCacheMeshItem->AllocSize;
LABEL_87:
  (*(void (__fastcall **)(void *))(*(_QWORD *)v6 + 24i64))(v6);
}

// File Line: 942
// RVA: 0x9FE440
void __fastcall Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface>::DrawableCxform(
        Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *this,
        Scaleform::Render::Texture **tex,
        Scaleform::Render::Matrix2x4<float> *texgen,
        Scaleform::Render::Cxform *cx)
{
  Scaleform::Render::RenderTarget *pObject; // r8
  int v9; // ecx
  void *v10; // [rsp+48h] [rbp-20h]
  Scaleform::Render::Size<int> texsize; // [rsp+70h] [rbp+8h] BYREF

  v10 = this->vfptr[60].__vecDelDtor(this, 16i64);
  (*(void (__fastcall **)(void *, const char *))(*(_QWORD *)v10 + 16i64))(v10, "HAL::DrawableCxform");
  pObject = this->RenderTargetStack.Data.Data[this->RenderTargetStack.Data.Size - 1].pRenderTarget.pObject;
  v9 = pObject->ViewRect.y2 - pObject->ViewRect.y1;
  texsize.Width = pObject->ViewRect.x2 - pObject->ViewRect.x1;
  texsize.Height = v9;
  Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::SetDrawableCxform(
    &this->SManager,
    tex,
    texgen,
    (Scaleform::Render::Size<int>)&texsize,
    cx,
    this->MappedXY16iAlphaTexture[1],
    &this->ShaderData,
    0);
  ((void (__fastcall *)(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *))this->vfptr[75].__vecDelDtor)(this);
  (*(void (__fastcall **)(void *))(*(_QWORD *)v10 + 24i64))(v10);
}

// File Line: 951
// RVA: 0x9FE040
void __fastcall Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface>::DrawableCompare(
        Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *this,
        Scaleform::Render::Texture **tex,
        Scaleform::Render::Matrix2x4<float> *texgen)
{
  void *v6; // rsi
  Scaleform::Render::RenderTarget *pObject; // r8
  int v8; // ecx
  Scaleform::Render::Size<int> texsize; // [rsp+70h] [rbp+8h] BYREF
  void *v10; // [rsp+88h] [rbp+20h]

  v6 = this->vfptr[60].__vecDelDtor(this, 17i64);
  v10 = v6;
  (*(void (__fastcall **)(void *, const char *))(*(_QWORD *)v6 + 16i64))(v6, "HAL::DrawableCompare");
  pObject = this->RenderTargetStack.Data.Data[this->RenderTargetStack.Data.Size - 1].pRenderTarget.pObject;
  v8 = pObject->ViewRect.y2 - pObject->ViewRect.y1;
  texsize.Width = pObject->ViewRect.x2 - pObject->ViewRect.x1;
  texsize.Height = v8;
  Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::SetDrawableCompare(
    &this->SManager,
    tex,
    texgen,
    (Scaleform::Render::Size<int>)&texsize,
    this->MappedXY16iAlphaTexture[1],
    &this->ShaderData,
    0);
  ((void (__fastcall *)(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *))this->vfptr[75].__vecDelDtor)(this);
  (*(void (__fastcall **)(void *))(*(_QWORD *)v6 + 24i64))(v6);
}

// File Line: 960
// RVA: 0x9FE7F0
void __fastcall Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface>::DrawableMerge(
        Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *this,
        Scaleform::Render::Texture **tex,
        Scaleform::Render::Matrix2x4<float> *texgen,
        Scaleform::Render::Matrix4x4<float> *cxmul)
{
  Scaleform::Render::RenderTarget *pObject; // r8
  int v9; // ecx
  void *v10; // [rsp+48h] [rbp-20h]
  Scaleform::Render::Size<int> texsize; // [rsp+70h] [rbp+8h] BYREF

  v10 = this->vfptr[60].__vecDelDtor(this, 19i64);
  (*(void (__fastcall **)(void *, const char *))(*(_QWORD *)v10 + 16i64))(v10, "HAL::DrawableMerge");
  pObject = this->RenderTargetStack.Data.Data[this->RenderTargetStack.Data.Size - 1].pRenderTarget.pObject;
  v9 = pObject->ViewRect.y2 - pObject->ViewRect.y1;
  texsize.Width = pObject->ViewRect.x2 - pObject->ViewRect.x1;
  texsize.Height = v9;
  Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::SetDrawableMergeFill(
    &this->SManager,
    tex,
    texgen,
    (Scaleform::Render::Size<int>)&texsize,
    cxmul,
    this->MappedXY16iAlphaTexture[1],
    &this->ShaderData,
    0);
  ((void (__fastcall *)(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *))this->vfptr[75].__vecDelDtor)(this);
  (*(void (__fastcall **)(void *))(*(_QWORD *)v10 + 24i64))(v10);
}

// File Line: 970
// RVA: 0x9FE130
void __fastcall Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface>::DrawableCopyPixels(
        Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *this,
        Scaleform::Render::Texture **tex,
        Scaleform::Render::Matrix2x4<float> *texgen,
        Scaleform::Render::Matrix2x4<float> *mvp,
        bool mergeAlpha,
        bool destAlpha)
{
  Scaleform::Render::RenderTarget *pObject; // r8
  int v11; // ecx
  void *v12; // [rsp+58h] [rbp-20h]
  Scaleform::Render::Size<int> texsize; // [rsp+80h] [rbp+8h] BYREF

  v12 = this->vfptr[60].__vecDelDtor(this, 18i64);
  (*(void (__fastcall **)(void *, const char *))(*(_QWORD *)v12 + 16i64))(v12, "HAL::DrawableCopyPixels");
  pObject = this->RenderTargetStack.Data.Data[this->RenderTargetStack.Data.Size - 1].pRenderTarget.pObject;
  v11 = pObject->ViewRect.y2 - pObject->ViewRect.y1;
  texsize.Width = pObject->ViewRect.x2 - pObject->ViewRect.x1;
  texsize.Height = v11;
  Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::SetDrawableCopyPixelsFill(
    &this->SManager,
    tex,
    texgen,
    (Scaleform::Render::Size<int>)&texsize,
    mvp,
    mergeAlpha,
    destAlpha,
    this->MappedXY16iAlphaTexture[1],
    &this->ShaderData,
    0);
  ((void (__fastcall *)(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *))this->vfptr[75].__vecDelDtor)(this);
  (*(void (__fastcall **)(void *))(*(_QWORD *)v12 + 24i64))(v12);
}

// File Line: 981
// RVA: 0x9FE8F0
void __fastcall Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface>::DrawablePaletteMap(
        Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *this,
        Scaleform::Render::Texture **tex,
        Scaleform::Render::Matrix2x4<float> *texgen,
        Scaleform::Render::Matrix2x4<float> *mvp,
        unsigned int channelMask,
        const unsigned int *values)
{
  void *v7; // r14
  int v8; // esi
  __int64 v9; // rdi
  __int64 v10; // rbx
  unsigned int v11; // eax
  __int64 v12; // rax
  Scaleform::Render::Texture *paletteMap; // r15
  __int64 v14; // r14
  int v15; // ebx
  const unsigned int *v16; // rdi
  unsigned int v17; // r12d
  char *v18; // rax
  unsigned int *v19; // rdx
  __int64 v20; // rcx
  unsigned int i; // r8d
  Scaleform::Render::RenderTarget *pObject; // rdx
  int v23; // ecx
  void *v24; // [rsp+50h] [rbp-69h]
  Scaleform::Render::Size<int> texsize; // [rsp+58h] [rbp-61h] BYREF
  Scaleform::Render::ImageData v26; // [rsp+60h] [rbp-59h] BYREF
  __int64 v27; // [rsp+A0h] [rbp-19h]
  __int64 v28; // [rsp+A8h] [rbp-11h]
  void *v29; // [rsp+B0h] [rbp-9h]
  int v30; // [rsp+110h] [rbp+57h] BYREF
  int v31; // [rsp+114h] [rbp+5Bh]
  Scaleform::Render::Texture **texa; // [rsp+118h] [rbp+5Fh]
  Scaleform::Render::Matrix2x4<float> *texgena; // [rsp+120h] [rbp+67h]
  Scaleform::Render::Matrix2x4<float> *v34; // [rsp+128h] [rbp+6Fh]

  v34 = mvp;
  texgena = texgen;
  texa = tex;
  v27 = -2i64;
  v7 = this->vfptr[60].__vecDelDtor(this, 20i64);
  v24 = v7;
  v29 = v7;
  (*(void (__fastcall **)(void *, const char *))(*(_QWORD *)v7 + 16i64))(v7, "HAL::DrawablePaletteMap");
  *(_QWORD *)&v26.Format = 0i64;
  *(_DWORD *)&v26.Flags = 0x10000;
  v8 = 1;
  v26.pPlanes = &v26.Plane0;
  memset(&v26.pPalette, 0, 40);
  v9 = ((__int64 (__fastcall *)(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *))this->vfptr[61].__vecDelDtor)(this);
  v30 = 256;
  v31 = 4;
  v10 = *(_QWORD *)v9;
  v11 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v9 + 104i64))(v9);
  v12 = (*(__int64 (__fastcall **)(__int64, _QWORD, __int64, int *, int, _QWORD, _QWORD))(v10 + 8))(
          v9,
          v11,
          1i64,
          &v30,
          192,
          0i64,
          0i64);
  paletteMap = (Scaleform::Render::Texture *)v12;
  v28 = v12;
  if ( v12
    && (*(unsigned __int8 (__fastcall **)(__int64, Scaleform::Render::ImageData *, _QWORD, __int64))(*(_QWORD *)v12 + 104i64))(
         v12,
         &v26,
         0i64,
         1i64) )
  {
    v14 = 0i64;
    v15 = 0;
    v16 = values;
    v17 = channelMask;
    do
    {
      v18 = &v26.pPlanes->pData[v14 * v26.pPlanes->Pitch];
      if ( (v8 & v17) != 0 )
      {
        v19 = (unsigned int *)v16;
        if ( (((unsigned __int8)v18 | (unsigned __int8)v16) & 0xF) != 0 )
        {
          memmove(&v26.pPlanes->pData[v14 * v26.pPlanes->Pitch], v16, 0x400ui64);
        }
        else
        {
          v20 = 8i64;
          do
          {
            *(_OWORD *)v18 = *(_OWORD *)v19;
            *((_OWORD *)v18 + 1) = *((_OWORD *)v19 + 1);
            *((_OWORD *)v18 + 2) = *((_OWORD *)v19 + 2);
            *((_OWORD *)v18 + 3) = *((_OWORD *)v19 + 3);
            *((_OWORD *)v18 + 4) = *((_OWORD *)v19 + 4);
            *((_OWORD *)v18 + 5) = *((_OWORD *)v19 + 5);
            *((_OWORD *)v18 + 6) = *((_OWORD *)v19 + 6);
            v18 += 128;
            *((_OWORD *)v18 - 1) = *((_OWORD *)v19 + 7);
            v19 += 32;
            --v20;
          }
          while ( v20 );
        }
      }
      else
      {
        for ( i = 0; i < 0x100; ++i )
        {
          v19 = (unsigned int *)(i << v15);
          *(_DWORD *)v18 = (_DWORD)v19;
          v18 += 4;
        }
      }
      v15 += 8;
      v8 = __ROL4__(v8, 1);
      ++v14;
      v16 += 256;
    }
    while ( v15 < 32 );
    if ( paletteMap->vfptr[14].__vecDelDtor(paletteMap, (unsigned int)v19) )
    {
      Scaleform::Render::HAL::applyBlendMode(this, 16i64, 1, 1);
      pObject = this->RenderTargetStack.Data.Data[this->RenderTargetStack.Data.Size - 1].pRenderTarget.pObject;
      v23 = pObject->ViewRect.y2 - pObject->ViewRect.y1;
      texsize.Width = pObject->ViewRect.x2 - pObject->ViewRect.x1;
      texsize.Height = v23;
      Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::SetDrawablePaletteMap(
        &this->SManager,
        texa,
        texgena,
        (Scaleform::Render::Size<int>)&texsize,
        v34,
        paletteMap,
        this->MappedXY16iAlphaTexture[1],
        &this->ShaderData,
        0);
      ((void (__fastcall *)(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *))this->vfptr[75].__vecDelDtor)(this);
    }
    v7 = v24;
  }
  if ( paletteMap )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)paletteMap);
  Scaleform::Render::ImageData::freePlanes(&v26);
  if ( v26.pPalette.pObject && !_InterlockedDecrement(&v26.pPalette.pObject->RefCount.Value) )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  (*(void (__fastcall **)(void *))(*(_QWORD *)v7 + 24i64))(v7);
}

// File Line: 1019
// RVA: 0x9FE240
void __fastcall Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface>::DrawableCopyback(
        Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *this,
        Scaleform::Render::Texture *source,
        Scaleform::Render::Matrix2x4<float> *mvpOriginal,
        Scaleform::Render::Matrix2x4<float> *texgen,
        char flagMask)
{
  void *v9; // r14
  Scaleform::Render::D3D1x::ShaderPair v; // [rsp+50h] [rbp-58h] BYREF

  v9 = this->vfptr[60].__vecDelDtor(this, 22i64);
  (*(void (__fastcall **)(void *, const char *))(*(_QWORD *)v9 + 16i64))(v9, "HAL::DrawableCopyback");
  Scaleform::Render::D3D1x::ShaderInterface::SetStaticShader(
    &this->ShaderData,
    ST_BatchTexTG,
    this->MappedXY16iAlphaTexture[1]);
  if ( !this->ShaderData.PrimitiveOpen )
  {
    this->ShaderData.PrimitiveOpen = 1;
    *(_QWORD *)this->ShaderData.UniformSet = 0i64;
    *(_QWORD *)&this->ShaderData.UniformSet[8] = 0i64;
    *(_QWORD *)&this->ShaderData.UniformSet[16] = 0i64;
    *(_WORD *)&this->ShaderData.UniformSet[24] = 0;
    this->ShaderData.Textures[0] = 0i64;
    this->ShaderData.Textures[1] = 0i64;
    this->ShaderData.Textures[2] = 0i64;
    this->ShaderData.Textures[3] = 0i64;
  }
  v.pVS = *(Scaleform::Render::D3D1x::VertexShader **)&mvpOriginal->M[0][0];
  v.pVDesc = *(Scaleform::Render::D3D1x::VertexShaderDesc **)&mvpOriginal->M[0][2];
  *(_OWORD *)&v.pFS = *(_OWORD *)&mvpOriginal->M[1][0];
  Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUniform(
    &this->ShaderData,
    &this->ShaderData.CurShaders,
    0xDu,
    (const float *)&v,
    8u,
    0,
    0);
  Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUniform(
    &this->ShaderData,
    &this->ShaderData.CurShaders,
    0x15u,
    (const float *)texgen,
    8u,
    0,
    0);
  v = this->ShaderData.CurShaders;
  flagMask = 0;
  Scaleform::Render::D3D1x::ShaderInterface::SetTexture(
    &this->ShaderData,
    &v,
    0x14u,
    source,
    (Scaleform::Render::ImageFillMode)&flagMask,
    0);
  Scaleform::Render::D3D1x::ShaderInterface::Finish(&this->ShaderData, 1u);
  ((void (__fastcall *)(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *))this->vfptr[75].__vecDelDtor)(this);
  (*(void (__fastcall **)(void *))(*(_QWORD *)v9 + 24i64))(v9);
}

// File Line: 1045
// RVA: 0xA05C30
char __fastcall Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface>::initHAL(
        Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *this,
        Scaleform::Render::HALInitParams *params)
{
  char result; // al

  result = Scaleform::Render::HAL::initHAL(this, params);
  if ( result )
  {
    ((void (__fastcall *)(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *, __int64, Scaleform::Render::VertexFormat *, Scaleform::Render::VertexFormat **, Scaleform::Render::VertexFormat **, Scaleform::Render::VertexFormat **, _DWORD))this->vfptr[66].__vecDelDtor)(
      this,
      5i64,
      &Scaleform::Render::VertexXY16iAlpha::Format,
      this->MappedXY16iAlphaTexture,
      &this->MappedXY16iAlphaTexture[1],
      &this->MappedXY16iAlphaTexture[2],
      0);
    ((void (__fastcall *)(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *, __int64, Scaleform::Render::VertexFormat *, Scaleform::Render::VertexFormat **, Scaleform::Render::VertexFormat **, Scaleform::Render::VertexFormat **, _DWORD))this->vfptr[66].__vecDelDtor)(
      this,
      2i64,
      &Scaleform::Render::VertexXY16iAlpha::Format,
      this->MappedXY16iAlphaSolid,
      &this->MappedXY16iAlphaSolid[1],
      &this->MappedXY16iAlphaSolid[2],
      0);
    return 1;
  }
  return result;
}

// File Line: 1066
// RVA: 0xA06210
char __fastcall Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface>::shutdownHAL(
        Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *this)
{
  char result; // al
  Scaleform::Render::VertexFormat **MappedXY16iAlphaSolid; // rbx
  __int64 v4; // rsi
  __int64 v5; // rdi
  Scaleform::Render::RenderBuffer *v6; // rcx
  Scaleform::Render::VertexFormat *v7; // rdi
  Scaleform::Render::RenderBuffer *pObject; // rcx

  result = Scaleform::Render::HAL::shutdownHAL(this);
  if ( result )
  {
    MappedXY16iAlphaSolid = this->MappedXY16iAlphaSolid;
    v4 = 3i64;
    do
    {
      v5 = (__int64)*(MappedXY16iAlphaSolid - 3);
      if ( v5 )
      {
        v6 = *(Scaleform::Render::RenderBuffer **)(v5 + 16);
        if ( v6 )
          Scaleform::RefCountImpl::Release(v6);
        *(_QWORD *)(v5 + 16) = 0i64;
      }
      v7 = *MappedXY16iAlphaSolid;
      *(MappedXY16iAlphaSolid - 3) = 0i64;
      if ( v7 )
      {
        pObject = (Scaleform::Render::RenderBuffer *)v7->pSysFormat.pObject;
        if ( pObject )
          Scaleform::RefCountImpl::Release(pObject);
        v7->pSysFormat.pObject = 0i64;
      }
      *MappedXY16iAlphaSolid++ = 0i64;
      --v4;
    }
    while ( v4 );
    return 1;
  }
  return result;
}

// File Line: 1084
// RVA: 0xA04FA0
void __fastcall Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface>::drawMaskClearRectangles(
        Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *this,
        Scaleform::Render::Matrix2x4<float> *matrices,
        unsigned __int64 count)
{
  void *v5; // r14
  Scaleform::Render::D3D1x::ShaderInterface *p_ShaderData; // rbx
  unsigned __int64 v7; // r13
  unsigned int v8; // r14d
  unsigned int batch; // esi
  const float *v10; // rbp
  float v11; // xmm3_4
  float v12; // xmm2_4
  float v13; // xmm1_4
  float v14; // xmm0_4
  Scaleform::Render::D3D1x::VertexShaderDesc *pVDesc; // rcx
  Scaleform::Render::D3D1x::BatchVar *BatchUniforms; // rax
  char Offset; // dl
  int v18; // r10d
  __int64 Array; // rax
  Scaleform::Render::D3D1x::BatchVar *v20; // rdx
  char v21; // al
  Scaleform::Render::D3D1x::UniformVar *v22; // r8
  unsigned __int64 v23; // rcx
  Scaleform::Render::D3D1x::UniformVar *v24; // r8
  unsigned __int64 v25; // rcx
  Scaleform::Render::D3D1x::UniformVar *Uniforms; // rax
  __int64 ShadowOffset; // rax
  Scaleform::Render::D3D1x::UniformVar *v28; // rcx
  __int64 v29; // rax
  void *v30; // [rsp+40h] [rbp-68h]
  unsigned __int8 v31; // [rsp+B0h] [rbp+8h] BYREF
  unsigned __int8 v32; // [rsp+B1h] [rbp+9h]
  unsigned __int8 v33; // [rsp+B2h] [rbp+Ah]
  unsigned __int8 v34; // [rsp+B3h] [rbp+Bh]
  Scaleform::Render::Matrix2x4<float> *v35; // [rsp+B8h] [rbp+10h]
  unsigned __int64 v36; // [rsp+C0h] [rbp+18h]
  int v37; // [rsp+C8h] [rbp+20h] BYREF

  v36 = count;
  v35 = matrices;
  v5 = this->vfptr[60].__vecDelDtor(this, 8i64);
  v30 = v5;
  (*(void (__fastcall **)(void *, const char *))(*(_QWORD *)v5 + 16i64))(v5, "HAL::drawMaskClearRectangles");
  p_ShaderData = &this->ShaderData;
  Scaleform::Render::D3D1x::ShaderInterface::SetStaticShader(
    &this->ShaderData,
    ST_BatchSolid,
    this->MappedXY16iAlphaSolid[1]);
  if ( !this->ShaderData.PrimitiveOpen )
  {
    this->ShaderData.PrimitiveOpen = 1;
    *(_QWORD *)this->ShaderData.UniformSet = 0i64;
    *(_QWORD *)&this->ShaderData.UniformSet[8] = 0i64;
    *(_QWORD *)&this->ShaderData.UniformSet[16] = 0i64;
    *(_WORD *)&this->ShaderData.UniformSet[24] = 0;
    this->ShaderData.Textures[0] = 0i64;
    this->ShaderData.Textures[1] = 0i64;
    this->ShaderData.Textures[2] = 0i64;
    this->ShaderData.Textures[3] = 0i64;
  }
  ((void (__fastcall *)(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *))this->vfptr[87].__vecDelDtor)(this);
  v7 = 0i64;
  if ( count )
  {
    v8 = 24;
    if ( (unsigned int)count < 0x18 )
      v8 = count;
    while ( 1 )
    {
      if ( v7 && !this->ShaderData.PrimitiveOpen )
      {
        this->ShaderData.PrimitiveOpen = 1;
        *(_QWORD *)this->ShaderData.UniformSet = 0i64;
        *(_QWORD *)&this->ShaderData.UniformSet[8] = 0i64;
        *(_QWORD *)&this->ShaderData.UniformSet[16] = 0i64;
        *(_WORD *)&this->ShaderData.UniformSet[24] = 0;
        this->ShaderData.Textures[0] = 0i64;
        this->ShaderData.Textures[1] = 0i64;
        this->ShaderData.Textures[2] = 0i64;
        this->ShaderData.Textures[3] = 0i64;
      }
      batch = 0;
      if ( v8 )
        break;
LABEL_38:
      Scaleform::Render::D3D1x::ShaderInterface::Finish(&this->ShaderData, v8);
      ((void (__fastcall *)(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *))this->vfptr[88].__vecDelDtor)(this);
      ((void (__fastcall *)(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *, _QWORD, _QWORD))this->vfptr[95].__vecDelDtor)(
        this,
        6 * v8,
        v8);
      v7 += v8;
      if ( v7 >= v36 )
      {
        v5 = v30;
        goto LABEL_40;
      }
    }
    v10 = (const float *)&v35[v7];
    while ( 1 )
    {
      Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUniform(
        &this->ShaderData,
        &this->ShaderData.CurShaders,
        0xDu,
        v10,
        8u,
        0,
        batch);
      v37 = -16777089;
      ((void (__fastcall *)(Scaleform::Render::ProfileViews *, unsigned __int8 *, int *))this->Profiler.Scaleform::Render::HAL::vfptr->GetClearColor)(
        &this->Profiler,
        &v31,
        &v37);
      if ( v33 )
        v11 = (float)v33 * 0.0039215689;
      else
        v11 = 0.0;
      if ( v32 )
        v12 = (float)v32 * 0.0039215689;
      else
        v12 = 0.0;
      if ( v31 )
        v13 = (float)v31 * 0.0039215689;
      else
        v13 = 0.0;
      if ( v34 )
        v14 = (float)v34 * 0.0039215689;
      else
        v14 = 0.0;
      pVDesc = this->ShaderData.CurShaders.pVDesc;
      BatchUniforms = pVDesc->BatchUniforms;
      Offset = BatchUniforms[5].Offset;
      if ( Offset < 0 )
      {
        v20 = this->ShaderData.CurShaders.pFDesc->BatchUniforms;
        v21 = v20[5].Offset;
        if ( v21 < 0 )
        {
          Uniforms = pVDesc->Uniforms;
          if ( Uniforms[5].Size )
          {
            ShadowOffset = Uniforms[5].ShadowOffset;
            p_ShaderData->UniformData[ShadowOffset] = v11;
            p_ShaderData->UniformData[ShadowOffset + 1] = v12;
            p_ShaderData->UniformData[ShadowOffset + 2] = v13;
            p_ShaderData->UniformData[ShadowOffset + 3] = v14;
          }
          v28 = this->ShaderData.CurShaders.pFDesc->Uniforms;
          if ( v28[5].Size )
          {
            v29 = v28[5].ShadowOffset;
            p_ShaderData->UniformData[v29] = v11;
            p_ShaderData->UniformData[v29 + 1] = v12;
            p_ShaderData->UniformData[v29 + 2] = v13;
            p_ShaderData->UniformData[v29 + 3] = v14;
          }
          this->ShaderData.UniformSet[5] = 1;
          goto LABEL_37;
        }
        v18 = v21;
        Array = (unsigned int)v20[5].Array;
      }
      else
      {
        v18 = Offset;
        Array = (unsigned int)BatchUniforms[5].Array;
      }
      v22 = pVDesc->Uniforms;
      if ( v22[Array].Size )
      {
        v23 = v22[Array].ShadowOffset + (unsigned __int64)(v18 * (unsigned int)(unsigned __int8)v22[Array].ElementSize);
        p_ShaderData->UniformData[v23] = v11;
        p_ShaderData->UniformData[v23 + 1] = v12;
        p_ShaderData->UniformData[v23 + 2] = v13;
        p_ShaderData->UniformData[v23 + 3] = v14;
      }
      v24 = this->ShaderData.CurShaders.pFDesc->Uniforms;
      if ( v24[Array].Size )
      {
        v25 = v24[Array].ShadowOffset + (unsigned __int64)(v18 * (unsigned int)(unsigned __int8)v24[Array].ElementSize);
        p_ShaderData->UniformData[v25] = v11;
        p_ShaderData->UniformData[v25 + 1] = v12;
        p_ShaderData->UniformData[v25 + 2] = v13;
        p_ShaderData->UniformData[v25 + 3] = v14;
      }
      p_ShaderData->UniformSet[(unsigned int)Array] = 1;
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
void __fastcall Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface>::clearSolidRectangle(
        Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *this,
        Scaleform::Render::Rect<int> *r,
        Scaleform::Render::Color *color,
        bool blend)
{
  void *v8; // r14
  bool v9; // r9
  __int64 v10; // rdx
  float y1; // xmm3_4
  unsigned int v12; // xmm2_4
  float x1; // xmm1_4
  Scaleform::Render::D3D1x::ShaderInterface *p_ShaderData; // rbx
  Scaleform::Render::D3D1x::VertexShaderDesc *pVDesc; // rcx
  Scaleform::Render::D3D1x::BatchVar *BatchUniforms; // rax
  char Offset; // dl
  int v18; // r10d
  __int64 Array; // rax
  Scaleform::Render::D3D1x::BatchVar *v20; // rdx
  char v21; // al
  Scaleform::Render::D3D1x::UniformVar *Uniforms; // r8
  float v23; // r13d
  float v24; // r12d
  float v25; // r15d
  float v26; // r11d
  unsigned __int64 v27; // rcx
  Scaleform::Render::D3D1x::UniformVar *v28; // r8
  unsigned __int64 v29; // rcx
  Scaleform::Render::D3D1x::UniformVar *v30; // rax
  float v31; // r8d
  float v32; // r9d
  float v33; // r10d
  float v34; // r11d
  __int64 ShadowOffset; // rax
  Scaleform::Render::D3D1x::UniformVar *v36; // rcx
  __int64 v37; // rax
  float pr; // [rsp+48h] [rbp-41h] BYREF
  float pg; // [rsp+4Ch] [rbp-3Dh] BYREF
  float pb; // [rsp+50h] [rbp-39h] BYREF
  float pa[3]; // [rsp+54h] [rbp-35h] BYREF
  Scaleform::Render::Matrix2x4<float> m0; // [rsp+60h] [rbp-29h] BYREF
  Scaleform::Render::Matrix2x4<float> v43; // [rsp+80h] [rbp-9h] BYREF
  char v44; // [rsp+F0h] [rbp+67h] BYREF
  Scaleform::Render::HAL::HALBlendState state; // [rsp+F8h] [rbp+6Fh] BYREF
  void *v46; // [rsp+100h] [rbp+77h]
  Scaleform::Render::Color Raw; // [rsp+108h] [rbp+7Fh] BYREF

  v8 = this->vfptr[60].__vecDelDtor(this, 5i64);
  v46 = v8;
  (*(void (__fastcall **)(void *, const char *))(*(_QWORD *)v8 + 16i64))(v8, "HAL::clearSolidRectangle");
  Scaleform::Render::HAL::applyRasterMode(this, RasterMode_Solid);
  state = this->CurrentBlendState;
  if ( blend )
  {
    v9 = 1;
    v10 = 1i64;
  }
  else
  {
    v9 = 0;
    v10 = 16i64;
  }
  Scaleform::Render::HAL::applyBlendMode(this, v10, 0, v9);
  Raw = (Scaleform::Render::Color)color->Raw;
  *color = *(Scaleform::Render::Color *)((__int64 (__fastcall *)(Scaleform::Render::ProfileViews *, char *, Scaleform::Render::Color *))this->Profiler.Scaleform::Render::HAL::vfptr->GetClearColor)(
                                          &this->Profiler,
                                          &v44,
                                          &Raw);
  Scaleform::Render::Color::GetRGBAFloat(color, &pr, &pg, &pb, pa);
  y1 = (float)r->y1;
  *(float *)&v12 = (float)(r->y2 - r->y1);
  x1 = (float)r->x1;
  m0.M[0][0] = (float)(r->x2 - r->x1);
  *(_QWORD *)&m0.M[0][1] = 0i64;
  m0.M[0][3] = x1;
  m0.M[1][0] = 0.0;
  *(_QWORD *)&m0.M[1][1] = v12;
  m0.M[1][3] = y1;
  Scaleform::Render::Matrix2x4<float>::SetToAppend(&v43, &m0, &this->Matrices.pObject->UserView);
  p_ShaderData = &this->ShaderData;
  Scaleform::Render::D3D1x::ShaderInterface::SetStaticShader(
    &this->ShaderData,
    ST_BatchSolid,
    this->MappedXY16iAlphaSolid[1]);
  if ( !this->ShaderData.PrimitiveOpen )
  {
    this->ShaderData.PrimitiveOpen = 1;
    *(_QWORD *)this->ShaderData.UniformSet = 0i64;
    *(_QWORD *)&this->ShaderData.UniformSet[8] = 0i64;
    *(_QWORD *)&this->ShaderData.UniformSet[16] = 0i64;
    *(_WORD *)&this->ShaderData.UniformSet[24] = 0;
    this->ShaderData.Textures[0] = 0i64;
    this->ShaderData.Textures[1] = 0i64;
    this->ShaderData.Textures[2] = 0i64;
    this->ShaderData.Textures[3] = 0i64;
  }
  Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUniform(
    &this->ShaderData,
    &this->ShaderData.CurShaders,
    0xDu,
    (const float *)&v43,
    8u,
    0,
    0);
  pVDesc = this->ShaderData.CurShaders.pVDesc;
  BatchUniforms = pVDesc->BatchUniforms;
  Offset = BatchUniforms[5].Offset;
  if ( Offset >= 0 )
  {
    v18 = Offset;
    Array = (unsigned int)BatchUniforms[5].Array;
LABEL_10:
    Uniforms = pVDesc->Uniforms;
    v23 = pr;
    v24 = pg;
    v25 = pb;
    v26 = pa[0];
    if ( Uniforms[Array].Size )
    {
      v27 = Uniforms[Array].ShadowOffset
          + (unsigned __int64)(v18 * (unsigned int)(unsigned __int8)Uniforms[Array].ElementSize);
      p_ShaderData->UniformData[v27] = pr;
      p_ShaderData->UniformData[v27 + 1] = v24;
      p_ShaderData->UniformData[v27 + 2] = v25;
      p_ShaderData->UniformData[v27 + 3] = v26;
    }
    v28 = this->ShaderData.CurShaders.pFDesc->Uniforms;
    if ( v28[Array].Size )
    {
      v29 = v28[Array].ShadowOffset + (unsigned __int64)(v18 * (unsigned int)(unsigned __int8)v28[Array].ElementSize);
      p_ShaderData->UniformData[v29] = v23;
      p_ShaderData->UniformData[v29 + 1] = v24;
      p_ShaderData->UniformData[v29 + 2] = v25;
      p_ShaderData->UniformData[v29 + 3] = v26;
    }
    p_ShaderData->UniformSet[(unsigned int)Array] = 1;
    goto LABEL_20;
  }
  v20 = this->ShaderData.CurShaders.pFDesc->BatchUniforms;
  v21 = v20[5].Offset;
  if ( v21 >= 0 )
  {
    v18 = v21;
    Array = (unsigned int)v20[5].Array;
    goto LABEL_10;
  }
  v30 = pVDesc->Uniforms;
  v31 = pa[0];
  v32 = pb;
  v33 = pg;
  v34 = pr;
  if ( v30[5].Size )
  {
    ShadowOffset = v30[5].ShadowOffset;
    p_ShaderData->UniformData[ShadowOffset] = pr;
    p_ShaderData->UniformData[ShadowOffset + 1] = v33;
    p_ShaderData->UniformData[ShadowOffset + 2] = v32;
    p_ShaderData->UniformData[ShadowOffset + 3] = v31;
  }
  v36 = this->ShaderData.CurShaders.pFDesc->Uniforms;
  if ( v36[5].Size )
  {
    v37 = v36[5].ShadowOffset;
    p_ShaderData->UniformData[v37] = v34;
    p_ShaderData->UniformData[v37 + 1] = v33;
    p_ShaderData->UniformData[v37 + 2] = v32;
    p_ShaderData->UniformData[v37 + 3] = v31;
  }
  this->ShaderData.UniformSet[5] = 1;
LABEL_20:
  Scaleform::Render::D3D1x::ShaderInterface::Finish(&this->ShaderData, 1u);
  ((void (__fastcall *)(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *))this->vfptr[75].__vecDelDtor)(this);
  Scaleform::Render::HAL::applyBlendMode(this, &state);
  Scaleform::Render::HAL::applyRasterMode(this, this->CurrentSceneRasterMode);
  (*(void (__fastcall **)(void *))(*(_QWORD *)v8 + 24i64))(v8);
}

// File Line: 1176
// RVA: 0xA05D40
void __fastcall Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface>::profilerDrawCacheablePrimArea(
        Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *this,
        Scaleform::Render::CacheablePrimitive *prim)
{
  Scaleform::Render::ProfileViewsVtbl *vfptr; // rax
  Scaleform::Render::Color *v5; // rax
  Scaleform::Render::D3D1x::ShaderInterface *p_ShaderData; // rbx
  Scaleform::Render::D3D1x::VertexShaderDesc *pVDesc; // rdx
  Scaleform::Render::D3D1x::BatchVar *BatchUniforms; // rax
  char Offset; // cl
  __int64 Array; // rax
  int v11; // r10d
  Scaleform::Render::D3D1x::BatchVar *v12; // rcx
  char v13; // al
  Scaleform::Render::D3D1x::UniformVar *Uniforms; // rdx
  float v15; // r15d
  float v16; // r14d
  float v17; // ebp
  float v18; // r11d
  __int64 v19; // r9
  unsigned __int64 v20; // rcx
  Scaleform::Render::D3D1x::UniformVar *v21; // rdx
  unsigned __int64 v22; // rcx
  Scaleform::Render::D3D1x::UniformVar *v23; // rax
  float v24; // r8d
  float v25; // r9d
  float v26; // edx
  float v27; // r10d
  __int64 ShadowOffset; // rax
  Scaleform::Render::D3D1x::UniformVar *v29; // rcx
  __int64 v30; // rax
  float pr; // [rsp+40h] [rbp-58h] BYREF
  float pg; // [rsp+44h] [rbp-54h] BYREF
  float pb; // [rsp+48h] [rbp-50h] BYREF
  float pa; // [rsp+4Ch] [rbp-4Ch] BYREF
  Scaleform::Render::Matrix2x4<float> v35; // [rsp+50h] [rbp-48h] BYREF
  int v36; // [rsp+A0h] [rbp+8h] BYREF
  char v37; // [rsp+A8h] [rbp+10h] BYREF

  (*(void (__fastcall **)(Scaleform::Render::ProfileViews *, __int64))&this->Profiler.Scaleform::Render::HAL::vfptr->gap8[8])(
    &this->Profiler,
    2i64);
  vfptr = this->Profiler.Scaleform::Render::HAL::vfptr;
  v36 = -1;
  v5 = (Scaleform::Render::Color *)((__int64 (__fastcall *)(Scaleform::Render::ProfileViews *, char *, int *))vfptr->GetColor)(
                                     &this->Profiler,
                                     &v37,
                                     &v36);
  Scaleform::Render::Color::GetRGBAFloat(v5, &pr, &pg, &pb, &pa);
  p_ShaderData = &this->ShaderData;
  Scaleform::Render::D3D1x::ShaderInterface::SetStaticShader(
    &this->ShaderData,
    ST_BatchSolid,
    this->MappedXY16iAlphaSolid[1]);
  if ( !this->ShaderData.PrimitiveOpen )
  {
    this->ShaderData.PrimitiveOpen = 1;
    *(_QWORD *)this->ShaderData.UniformSet = 0i64;
    *(_QWORD *)&this->ShaderData.UniformSet[8] = 0i64;
    *(_QWORD *)&this->ShaderData.UniformSet[16] = 0i64;
    *(_WORD *)&this->ShaderData.UniformSet[24] = 0;
    this->ShaderData.Textures[0] = 0i64;
    this->ShaderData.Textures[1] = 0i64;
    this->ShaderData.Textures[2] = 0i64;
    this->ShaderData.Textures[3] = 0i64;
  }
  Scaleform::Render::Matrix2x4<float>::SetToAppend(
    &v35,
    (Scaleform::Render::Matrix2x4<float> *)&prim->PrimitiveArea.Data.Data->pHandle->pHeader[(unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[prim->PrimitiveArea.Data.Data->pHandle->pHeader->Format & 0xF].Offsets[4]
                                                                                          + 1],
    &this->Matrices.pObject->UserView);
  Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUniform(
    &this->ShaderData,
    &this->ShaderData.CurShaders,
    0xDu,
    (const float *)&v35,
    8u,
    0,
    0);
  pVDesc = this->ShaderData.CurShaders.pVDesc;
  BatchUniforms = pVDesc->BatchUniforms;
  Offset = BatchUniforms[5].Offset;
  if ( Offset >= 0 )
  {
    Array = (unsigned int)BatchUniforms[5].Array;
    v11 = Offset;
LABEL_7:
    Uniforms = pVDesc->Uniforms;
    v15 = pr;
    v16 = pg;
    v17 = pb;
    v18 = pa;
    v19 = Array;
    if ( Uniforms[Array].Size )
    {
      v20 = Uniforms[v19].ShadowOffset
          + (unsigned __int64)(v11 * (unsigned int)(unsigned __int8)Uniforms[v19].ElementSize);
      p_ShaderData->UniformData[v20] = pr;
      p_ShaderData->UniformData[v20 + 1] = v16;
      p_ShaderData->UniformData[v20 + 2] = v17;
      p_ShaderData->UniformData[v20 + 3] = v18;
    }
    v21 = this->ShaderData.CurShaders.pFDesc->Uniforms;
    if ( v21[v19].Size )
    {
      v22 = v21[v19].ShadowOffset + (unsigned __int64)(v11 * (unsigned int)(unsigned __int8)v21[v19].ElementSize);
      p_ShaderData->UniformData[v22] = v15;
      p_ShaderData->UniformData[v22 + 1] = v16;
      p_ShaderData->UniformData[v22 + 2] = v17;
      p_ShaderData->UniformData[v22 + 3] = v18;
    }
    p_ShaderData->UniformSet[(unsigned int)Array] = 1;
    goto LABEL_17;
  }
  v12 = this->ShaderData.CurShaders.pFDesc->BatchUniforms;
  v13 = v12[5].Offset;
  if ( v13 >= 0 )
  {
    v11 = v13;
    Array = (unsigned int)v12[5].Array;
    goto LABEL_7;
  }
  v23 = pVDesc->Uniforms;
  v24 = pb;
  v25 = pg;
  v26 = pa;
  v27 = pr;
  if ( v23[5].Size )
  {
    ShadowOffset = v23[5].ShadowOffset;
    p_ShaderData->UniformData[ShadowOffset] = pr;
    p_ShaderData->UniformData[ShadowOffset + 1] = v25;
    p_ShaderData->UniformData[ShadowOffset + 2] = v24;
    p_ShaderData->UniformData[ShadowOffset + 3] = v26;
  }
  v29 = this->ShaderData.CurShaders.pFDesc->Uniforms;
  if ( v29[5].Size )
  {
    v30 = v29[5].ShadowOffset;
    p_ShaderData->UniformData[v30] = v27;
    p_ShaderData->UniformData[v30 + 1] = v25;
    p_ShaderData->UniformData[v30 + 2] = v24;
    p_ShaderData->UniformData[v30 + 3] = v26;
  }
  this->ShaderData.UniformSet[5] = 1;
LABEL_17:
  Scaleform::Render::D3D1x::ShaderInterface::Finish(&this->ShaderData, 1u);
  ((void (__fastcall *)(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *))this->vfptr[87].__vecDelDtor)(this);
  ((void (__fastcall *)(Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *, __int64, __int64))this->vfptr[95].__vecDelDtor)(
    this,
    6i64,
    1i64);
}

// File Line: 1195
// RVA: 0xA05CD0
void __fastcall Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface>::profilerApplyUniform(
        Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *this,
        Scaleform::Render::ProfilerUniform uniform,
        unsigned int components,
        const float *values)
{
  if ( uniform )
  {
    if ( uniform == ProfileUniform_TextureMips )
      Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUniform(
        &this->ShaderData,
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
      &this->ShaderData,
      &this->ShaderData.CurShaders,
      0x17u,
      values,
      components,
      0,
      0);
  }
}

