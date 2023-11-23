// File Line: 136
// RVA: 0xA02B40
void __fastcall Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUniform0(
        Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair> *this,
        Scaleform::Render::D3D1x::ShaderPair *sd,
        unsigned int var,
        const float *v,
        unsigned int n,
        unsigned int index)
{
  __int64 v6; // rdi
  __int64 v10; // rbp
  Scaleform::Render::D3D1x::UniformVar *Uniforms; // r10
  Scaleform::Render::D3D1x::UniformVar *v12; // rdx

  v6 = var;
  v10 = var;
  Uniforms = sd->pVDesc->Uniforms;
  if ( Uniforms[v10].Size )
    memmove(
      &this->UniformData[Uniforms[v10].ShadowOffset
                       + (unsigned __int64)(index * (unsigned __int8)Uniforms[v10].ElementSize)],
      v,
      4i64 * n);
  v12 = sd->pFDesc->Uniforms;
  if ( v12[v10].Size )
    memmove(
      &this->UniformData[v12[v10].ShadowOffset + (unsigned __int64)(index * (unsigned __int8)v12[v10].ElementSize)],
      v,
      4i64 * n);
  this->UniformSet[v6] = 1;
}

// File Line: 160
// RVA: 0xA02C10
void __fastcall Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUniform(
        Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair> *this,
        Scaleform::Render::D3D1x::ShaderPair *sd,
        unsigned int var,
        const float *v,
        unsigned int n,
        unsigned int index,
        unsigned int batch)
{
  Scaleform::Render::D3D1x::VertexShaderDesc *pVDesc; // rcx
  Scaleform::Render::D3D1x::BatchVar *BatchUniforms; // r9
  __int64 v12; // rdx
  char Offset; // r11
  __int64 v14; // r8
  Scaleform::Render::D3D1x::FragShaderDesc *pFDesc; // r9
  Scaleform::Render::D3D1x::BatchVar *v16; // rax
  char v17; // r11
  __int64 Array; // r8

  pVDesc = sd->pVDesc;
  BatchUniforms = pVDesc->BatchUniforms;
  v12 = var;
  Offset = BatchUniforms[v12].Offset;
  if ( Offset < 0 )
  {
    pFDesc = sd->pFDesc;
    v16 = pFDesc->BatchUniforms;
    v17 = v16[v12].Offset;
    if ( v17 < 0 )
    {
      Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUniform0(
        this,
        sd,
        var,
        v,
        n,
        index);
    }
    else
    {
      Array = (unsigned int)v16[var].Array;
      Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUniform0(
        this,
        sd,
        Array,
        v,
        n,
        batch * (unsigned __int8)pFDesc->Uniforms[Array].BatchSize + index + v17);
    }
  }
  else
  {
    v14 = (unsigned int)BatchUniforms[var].Array;
    Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUniform0(
      this,
      sd,
      v14,
      v,
      n,
      index + batch * (unsigned __int8)pVDesc->Uniforms[v14].BatchSize + Offset);
  }
}

// File Line: 195
// RVA: 0xA01FF0
void __fastcall Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetMatrix(
        Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair> *this,
        Scaleform::Render::D3D1x::ShaderPair *sd,
        unsigned int var,
        Scaleform::Render::Matrix2x4<float> *m1,
        Scaleform::Render::MatrixPoolImpl::HMatrix *m2,
        Scaleform::Render::MatrixState *Matrices,
        unsigned int index,
        unsigned int batch)
{
  Scaleform::Render::MatrixPoolImpl::DataHeader *pHeader; // r11
  __int64 v12; // rax
  Scaleform::Render::Matrix4x4<float> *UVP; // rax
  Scaleform::Render::Matrix3x4<float> v14; // [rsp+40h] [rbp-78h] BYREF
  Scaleform::Render::Matrix4x4<float> v15; // [rsp+70h] [rbp-48h] BYREF

  pHeader = m2->pHandle->pHeader;
  v12 = pHeader->Format & 0xF;
  if ( (pHeader->Format & 0x10) != 0 )
  {
    Scaleform::Render::Matrix3x4<float>::MultiplyMatrix(
      &v14,
      (Scaleform::Render::Matrix3x4<float> *)&pHeader[(unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[v12].Offsets[4]
                                                    + 1],
      m1);
    UVP = Scaleform::Render::MatrixState::GetUVP(Matrices);
    Scaleform::Render::Matrix4x4<float>::MultiplyMatrix(&v15, UVP, &v14);
    Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUniform(
      this,
      sd,
      var,
      (const float *)&v15,
      0x10u,
      index,
      batch);
  }
  else
  {
    Scaleform::Render::Matrix2x4<float>::SetToAppend(
      (Scaleform::Render::Matrix2x4<float> *)&v14,
      m1,
      (Scaleform::Render::Matrix2x4<float> *)&pHeader[(unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[v12].Offsets[4]
                                                    + 1],
      &Matrices->UserView);
    Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUniform(
      this,
      sd,
      var,
      (const float *)&v14,
      8u,
      2 * index,
      batch);
  }
}

// File Line: 212
// RVA: 0xA00BD0
void __fastcall Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetCxform(
        Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair> *this,
        Scaleform::Render::D3D1x::ShaderPair *sd,
        Scaleform::Render::Cxform *cx,
        unsigned int index,
        unsigned int batch)
{
  Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUniform(
    this,
    sd,
    5u,
    (const float *)cx,
    4u,
    index,
    batch);
  Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUniform(
    this,
    sd,
    4u,
    cx->M[1],
    4u,
    index,
    batch);
}

// File Line: 221
// RVA: 0x9FF050
__int64 __fastcall Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::GetUniformSize(
        Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair> *this,
        Scaleform::Render::D3D1x::ShaderPair *sd,
        unsigned int i)
{
  Scaleform::Render::D3D1x::VertexShaderDesc *pVDesc; // r9
  __int64 v4; // rcx
  __int64 v5; // r10
  Scaleform::Render::D3D1x::BatchVar *v6; // r8
  __int64 v8; // rcx
  Scaleform::Render::D3D1x::UniformVar *Uniforms; // rax
  Scaleform::Render::D3D1x::FragShaderDesc *pFDesc; // rdx
  Scaleform::Render::D3D1x::BatchVar *v11; // r8

  pVDesc = sd->pVDesc;
  v4 = i;
  v5 = i;
  v6 = &pVDesc->BatchUniforms[v5];
  if ( v6->Array <= 25 )
    return (unsigned __int8)pVDesc->Uniforms[v6->Array].ElementSize * (unsigned int)(unsigned __int8)v6->Size;
  v8 = v4;
  Uniforms = pVDesc->Uniforms;
  if ( Uniforms[v8].Location >= 0 )
    return (unsigned int)Uniforms[v8].Size;
  pFDesc = sd->pFDesc;
  v11 = &pFDesc->BatchUniforms[v5];
  if ( v11->Array <= 25 )
    return (unsigned __int8)pFDesc->Uniforms[v11->Array].ElementSize * (unsigned int)(unsigned __int8)v11->Size;
  Uniforms = pFDesc->Uniforms;
  if ( Uniforms[v8].Location >= 0 )
    return (unsigned int)Uniforms[v8].Size;
  return 0i64;
}

// File Line: 240
// RVA: 0xA02CF0
void __fastcall Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUserUniforms(
        Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair> *this,
        Scaleform::Render::D3D1x::ShaderPair *sd,
        Scaleform::Render::MatrixPoolImpl::HMatrix *m,
        unsigned int batch)
{
  Scaleform::Render::MatrixPoolImpl::DataHeader *pHeader; // rdx
  __int64 v8; // rsi
  signed int v9; // ebx
  char *v10; // r14
  char v11; // bp
  unsigned int UniformSize; // eax
  __int64 n; // rdi
  Scaleform::Render::Texture *v14; // rcx
  const float *v15; // r9
  int Height; // eax
  int v17[4]; // [rsp+40h] [rbp-48h] BYREF

  pHeader = m->pHandle->pHeader;
  if ( (pHeader->Format & 8) != 0 )
    v8 = (__int64)&pHeader[(unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[pHeader->Format & 0xF].Offsets[3]
                         + 1];
  else
    v8 = 0i64;
  v9 = 0;
  v10 = Scaleform::Render::D3D1x::Uniform::UniformFlags;
  do
  {
    v11 = *v10;
    if ( (*v10 & 1) == 0 )
    {
      UniformSize = Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::GetUniformSize(
                      this,
                      sd,
                      v9);
      n = UniformSize;
      if ( UniformSize )
      {
        if ( (v11 & 2) != 0 && UniformSize <= 4 && (v14 = this->Textures[0]) != 0i64 )
        {
          v15 = (const float *)v17;
          Height = v14->ImgSize.Height;
          *(float *)v17 = (float)(1.0 / (float)(int)v14->ImgSize.Width) * *(float *)v8;
          v17[2] = *(_DWORD *)(v8 + 8);
          *(float *)&v17[1] = (float)(1.0 / (float)Height) * *(float *)(v8 + 4);
          v17[3] = *(_DWORD *)(v8 + 12);
        }
        else
        {
          v15 = (const float *)v8;
        }
        Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUniform(
          this,
          sd,
          v9,
          v15,
          n,
          0,
          batch);
        v8 += 4 * n;
      }
    }
    ++v9;
    ++v10;
  }
  while ( v9 < 26 );
}

// File Line: 323
// RVA: 0x9FBB00
void __fastcall Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::~StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>(
        Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture> *this)
{
  Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture> *v1; // rbx

  v1 = this;
  this->vfptr = (Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>Vtbl *)&Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::`vftable;
  Scaleform::HashSet<Scaleform::HashNode<Scaleform::Render::SourceFormatHash,Scaleform::Render::ResultFormat,Scaleform::FixedSizeHash<Scaleform::Render::SourceFormatHash>>,Scaleform::HashNode<Scaleform::Render::SourceFormatHash,Scaleform::Render::ResultFormat,Scaleform::FixedSizeHash<Scaleform::Render::SourceFormatHash>>::NodeHashF,Scaleform::HashNode<Scaleform::Render::SourceFormatHash,Scaleform::Render::ResultFormat,Scaleform::FixedSizeHash<Scaleform::Render::SourceFormatHash>>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Render::SourceFormatHash,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::Render::SourceFormatHash,Scaleform::Render::ResultFormat,Scaleform::FixedSizeHash<Scaleform::Render::SourceFormatHash>>,Scaleform::HashNode<Scaleform::Render::SourceFormatHash,Scaleform::Render::ResultFormat,Scaleform::FixedSizeHash<Scaleform::Render::SourceFormatHash>>::NodeHashF>>::~HashSet<Scaleform::HashNode<Scaleform::Render::SourceFormatHash,Scaleform::Render::ResultFormat,Scaleform::FixedSizeHash<Scaleform::Render::SourceFormatHash>>,Scaleform::HashNode<Scaleform::Render::SourceFormatHash,Scaleform::Render::ResultFormat,Scaleform::FixedSizeHash<Scaleform::Render::SourceFormatHash>>::NodeHashF,Scaleform::HashNode<Scaleform::Render::SourceFormatHash,Scaleform::Render::ResultFormat,Scaleform::FixedSizeHash<Scaleform::Render::SourceFormatHash>>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Render::SourceFormatHash,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::Render::SourceFormatHash,Scaleform::Render::ResultFormat,Scaleform::FixedSizeHash<Scaleform::Render::SourceFormatHash>>,Scaleform::HashNode<Scaleform::Render::SourceFormatHash,Scaleform::Render::ResultFormat,Scaleform::FixedSizeHash<Scaleform::Render::SourceFormatHash>>::NodeHashF>>(&this->VertexFormatComputedHash.mHash);
  v1 = (Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture> *)((char *)v1 + 8);
  Scaleform::Render::PagedItemBuffer<Scaleform::Render::MultiKeyCollection<Scaleform::Render::VertexElement,Scaleform::Render::VertexFormat,32,8>::ValueItem,8>::freePages(
    (Scaleform::Render::PagedItemBuffer<Scaleform::Render::MultiKeyCollection<Scaleform::Render::VertexElement,Scaleform::Render::VertexFormat,32,8>::ValueItem,8> *)&v1->VFormats.KeyBuffer.pLast,
    0);
  Scaleform::Render::PagedItemBuffer<Scaleform::Render::VertexElement,32>::~PagedItemBuffer<Scaleform::Render::VertexElement,32>((Scaleform::Render::PagedItemBuffer<Scaleform::Render::ContextImpl::EntryChange,63> *)v1);
}

// File Line: 339
// RVA: 0xA03080
int __fastcall Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::StaticShaderForFill(
        Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture> *this,
        Scaleform::Render::PrimitiveFill *pfill,
        unsigned int *fillflags,
        unsigned int batchType)
{
  Scaleform::Render::PrimitiveFillType v8; // ebp
  Scaleform::Render::PrimitiveFillType Type; // edx
  int v10; // eax
  int v11; // eax
  int v12; // ecx
  int v13; // edi

  v8 = this->Profiler->vfptr->GetFillType(this->Profiler, pfill->Data.Type);
  if ( (unsigned int)(v8 - 5) > 1 )
    return Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::StaticShaderForFill(
             this,
             v8,
             fillflags,
             batchType);
  Type = pfill->Data.Type;
  if ( (unsigned int)(Type - 5) > 3 && Type < PrimFill_UVTexture )
    return Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::StaticShaderForFill(
             this,
             v8,
             fillflags,
             batchType);
  if ( ((int (__fastcall *)(Scaleform::Render::Texture *))pfill->Data.Textures[0].pObject->vfptr[4].__vecDelDtor)(pfill->Data.Textures[0].pObject) < 200
    || ((int (__fastcall *)(Scaleform::Render::Texture *))pfill->Data.Textures[0].pObject->vfptr[4].__vecDelDtor)(pfill->Data.Textures[0].pObject) > 202 )
  {
    return Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::StaticShaderForFill(
             this,
             v8,
             fillflags,
             batchType);
  }
  v10 = ((__int64 (__fastcall *)(Scaleform::Render::Texture *))pfill->Data.Textures[0].pObject->vfptr[4].__vecDelDtor)(pfill->Data.Textures[0].pObject)
      - 200;
  if ( v10 )
  {
    v11 = v10 - 1;
    if ( !v11 )
    {
      if ( !`Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::StaticShaderForFill::`14::warned )
        `Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::StaticShaderForFill::`14::warned = (unsigned int)Scaleform::Render::Texture::GetPlaneCount(pfill->Data.Textures[0].pObject) != 4;
      v12 = 270336;
      goto LABEL_18;
    }
    if ( v11 == 1 )
    {
      if ( !`Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::StaticShaderForFill::`18::warned )
        `Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::StaticShaderForFill::`18::warned = (unsigned int)Scaleform::Render::Texture::GetPlaneCount(pfill->Data.Textures[0].pObject) != 1;
      v12 = 278528;
      goto LABEL_18;
    }
  }
  else if ( !`Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::StaticShaderForFill::`10::warned )
  {
    `Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::StaticShaderForFill::`10::warned = (unsigned int)Scaleform::Render::Texture::GetPlaneCount(pfill->Data.Textures[0].pObject) != 3;
  }
  v12 = 0x40000;
LABEL_18:
  if ( v8 == PrimFill_Texture_EAlpha )
    v12 += 32;
  if ( v12 != 133120 )
  {
    if ( (*(_BYTE *)fillflags & 0xC) == 12 )
    {
      v12 += 256;
    }
    else if ( (*fillflags & 8) != 0 )
    {
      v12 += 16;
    }
  }
  v13 = batchType - 1;
  if ( v13 )
  {
    if ( v13 == 1 )
      v12 += 4;
  }
  else
  {
    v12 += 2;
  }
  if ( (*fillflags & 1) != 0 )
    ++v12;
  if ( (*fillflags & 0x10) != 0 )
    v12 += 8;
  return v12;
}

// File Line: 414
// RVA: 0xA03200
__int64 __fastcall Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::StaticShaderForFill(
        Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture> *this,
        Scaleform::Render::PrimitiveFillType fill,
        unsigned int *fillflags,
        unsigned int batchType)
{
  unsigned int v4; // ecx
  int v5; // r9d
  int v6; // eax
  bool v7; // zf
  __int64 result; // rax

  switch ( fill )
  {
    case PrimFill_VColor:
      v4 = 65537;
      goto LABEL_13;
    case PrimFill_VColor_EAlpha:
      v4 = 65569;
      goto LABEL_13;
    case PrimFill_Texture:
      v4 = 1;
      goto LABEL_13;
    case PrimFill_Texture_EAlpha:
      v4 = 33;
      goto LABEL_13;
    case PrimFill_Texture_VColor:
      v4 = 1025;
      goto LABEL_13;
    case PrimFill_Texture_VColor_EAlpha:
      v4 = 1057;
      goto LABEL_13;
    case PrimFill_2Texture:
      v4 = 513;
      goto LABEL_13;
    case PrimFill_2Texture_EAlpha:
      v4 = 545;
      goto LABEL_13;
    case PrimFill_UVTexture:
      v4 = 135168;
      goto LABEL_13;
    case PrimFill_UVTextureAlpha_VColor:
      *fillflags |= 8u;
      v4 = 133120;
      goto LABEL_17;
    default:
      *fillflags &= ~8u;
      v4 = 0x20000;
LABEL_13:
      if ( (*(_BYTE *)fillflags & 0xC) == 12 )
      {
        v4 += 256;
      }
      else if ( (*fillflags & 8) != 0 )
      {
        v4 += 16;
      }
LABEL_17:
      v5 = batchType - 1;
      if ( v5 )
      {
        if ( v5 == 1 )
          v4 += 4;
      }
      else
      {
        v4 += 2;
      }
      v6 = *fillflags;
      if ( (*fillflags & 1) != 0 )
        ++v4;
      if ( (v6 & 2) != 0 )
        v4 += 64;
      v7 = (v6 & 0x10) == 0;
      result = v4 + 8;
      if ( v7 )
        return v4;
      return result;
  }
}

// File Line: 542
// RVA: 0xA09B50
void __fastcall Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::MapVertexFormat(
        Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture> *this,
        __int64 fill,
        Scaleform::Render::VertexFormat *sourceFormat,
        Scaleform::Render::VertexFormat **single,
        Scaleform::Render::VertexFormat **batch,
        Scaleform::Render::VertexFormat **instanced,
        int flags)
{
  Scaleform::Render::PrimitiveFillType v10; // eax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::Render::SourceFormatHash,Scaleform::Render::ResultFormat,Scaleform::FixedSizeHash<Scaleform::Render::SourceFormatHash> >,Scaleform::HashNode<Scaleform::Render::SourceFormatHash,Scaleform::Render::ResultFormat,Scaleform::FixedSizeHash<Scaleform::Render::SourceFormatHash> >::NodeHashF,Scaleform::HashNode<Scaleform::Render::SourceFormatHash,Scaleform::Render::ResultFormat,Scaleform::FixedSizeHash<Scaleform::Render::SourceFormatHash> >::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Render::SourceFormatHash,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::Render::SourceFormatHash,Scaleform::Render::ResultFormat,Scaleform::FixedSizeHash<Scaleform::Render::SourceFormatHash> >,Scaleform::HashNode<Scaleform::Render::SourceFormatHash,Scaleform::Render::ResultFormat,Scaleform::FixedSizeHash<Scaleform::Render::SourceFormatHash> >::NodeHashF> >::TableType *pTable; // r9
  char v12; // r15
  Scaleform::Render::PrimitiveFillType v13; // r10d
  __int64 v14; // rdx
  __int64 v15; // rcx
  __int64 v16; // rax
  __int64 v17; // rax
  __int64 v18; // r8
  __int64 v19; // rdx
  __int64 v20; // rcx
  unsigned __int64 *v21; // rcx
  Scaleform::Render::VertexFormat *v22; // rdx
  Scaleform::Render::VertexFormat *v23; // rcx
  unsigned int v24; // esi
  Scaleform::Render::D3D1x::ShaderDesc::ShaderType v25; // ebx
  Scaleform::Render::D3D1x::ShaderDesc::ShaderVersion v26; // eax
  Scaleform::Render::D3D1x::VertexShaderDesc *Desc; // rax
  Scaleform::Render::D3D1x::VertexShaderDesc *v28; // r12
  Scaleform::Render::VertexFormat **v29; // rax
  int v30; // r13d
  unsigned int v31; // ebx
  unsigned int v32; // r9d
  int v33; // edi
  int v34; // r11d
  Scaleform::Render::VertexElement *p_keys; // rdx
  $3C54659889F1EB765F9D24AEEC355797 *v36; // r8
  unsigned int *p_Attr; // r10
  int v38; // edi
  $3C54659889F1EB765F9D24AEEC355797 *v39; // r8
  Scaleform::Render::VertexElement *v40; // rdx
  Scaleform::Render::VertexElement *pElements; // rcx
  unsigned int Attribute; // eax
  unsigned int v43; // r9d
  int v44; // eax
  unsigned int v45; // r9d
  unsigned int v46; // ecx
  Scaleform::Render::VertexElement *v47; // rsi
  Scaleform::Render::MultiKeyCollection<Scaleform::Render::VertexElement,Scaleform::Render::VertexFormat,32,8> *v48; // rsi
  Scaleform::Render::VertexFormat *v49; // rdx
  unsigned int v50; // ecx
  Scaleform::Render::VertexFormat *v51; // rdx
  __int64 *v52; // r14
  unsigned int v53; // ecx
  __int64 v54; // rdx
  __int64 v55; // rcx
  __int64 v56; // rax
  unsigned int v57; // eax
  Scaleform::Render::VertexFormat *v58; // rdx
  __int64 *v59; // rcx
  unsigned int v60; // ecx
  Scaleform::Render::VertexElement keys; // [rsp+20h] [rbp-81h] BYREF
  __int64 v62[7]; // [rsp+28h] [rbp-79h]
  Scaleform::HashNode<Scaleform::Render::SourceFormatHash,Scaleform::Render::ResultFormat,Scaleform::FixedSizeHash<Scaleform::Render::SourceFormatHash> >::NodeRef ppnewKeys; // [rsp+60h] [rbp-41h] BYREF
  int v64[2]; // [rsp+70h] [rbp-31h] BYREF
  Scaleform::Render::VertexFormat *v65; // [rsp+78h] [rbp-29h]
  Scaleform::Render::VertexFormat *v66; // [rsp+80h] [rbp-21h] BYREF
  Scaleform::Render::VertexFormat *v67; // [rsp+88h] [rbp-19h]
  __int64 v68; // [rsp+90h] [rbp-11h]
  void *pmemAddr; // [rsp+98h] [rbp-9h]
  Scaleform::Render::VertexElement *v70; // [rsp+F0h] [rbp+4Fh] BYREF
  unsigned int v71; // [rsp+F8h] [rbp+57h]
  int v72; // [rsp+100h] [rbp+5Fh]
  Scaleform::Render::VertexFormat **v73; // [rsp+108h] [rbp+67h]

  v73 = single;
  v70 = (Scaleform::Render::VertexElement *)this;
  v10 = this->Profiler->vfptr->GetFillType(this->Profiler, (Scaleform::Render::PrimitiveFillType)fill);
  pTable = this->VertexFormatComputedHash.mHash.pTable;
  v12 = flags;
  v13 = v10;
  v64[0] = v10;
  v64[1] = flags;
  v65 = sourceFormat;
  pmemAddr = &this->VertexFormatComputedHash;
  if ( pTable )
  {
    v14 = 16i64;
    v15 = 5381i64;
    do
    {
      v16 = *((unsigned __int8 *)&ppnewKeys.pSecond + v14-- + 7);
      v17 = 65599 * v15 + v16;
      v15 = v17;
    }
    while ( v14 );
    v18 = v17 & pTable->SizeMask;
    v19 = v18;
    v20 = (__int64)&pTable[1] + 56 * v18;
    if ( *(_QWORD *)v20 != -2i64 && *(_QWORD *)(v20 + 8) == v18 )
    {
      while ( *(_QWORD *)(v20 + 8) != v18
           || v13 != *(_DWORD *)(v20 + 16)
           || sourceFormat != *(Scaleform::Render::VertexFormat **)(v20 + 24)
           || flags != *(_DWORD *)(v20 + 20) )
      {
        v19 = *(_QWORD *)v20;
        if ( *(_QWORD *)v20 == -1i64 )
          goto LABEL_15;
        v20 = (__int64)&pTable[1] + 56 * v19;
      }
      if ( v19 >= 0 )
      {
        v21 = &pTable[2].EntryCount + 7 * v19;
        if ( v21 )
        {
          v66 = (Scaleform::Render::VertexFormat *)v21[2];
          v67 = (Scaleform::Render::VertexFormat *)v21[3];
          v22 = v67;
          v23 = (Scaleform::Render::VertexFormat *)v21[4];
          *single = v66;
          *batch = v22;
          *instanced = v23;
          return;
        }
      }
    }
  }
LABEL_15:
  v24 = 1;
  switch ( v13 )
  {
    case PrimFill_VColor:
      v25 = ST_Vertex;
      break;
    case PrimFill_VColor_EAlpha:
      v25 = ST_VertexEAlpha;
      break;
    case PrimFill_Texture:
      v25 = ST_base_Mul;
      break;
    case PrimFill_Texture_EAlpha:
      v25 = ST_TexTGEAlpha;
      break;
    case PrimFill_Texture_VColor:
      v25 = ST_TexTGVertex;
      break;
    case PrimFill_Texture_VColor_EAlpha:
      v25 = ST_TexTGVertexEAlpha;
      break;
    case PrimFill_2Texture:
      v25 = ST_TexTGTexTG;
      break;
    case PrimFill_2Texture_EAlpha:
      v25 = ST_TexTGTexTGEAlpha;
      break;
    case PrimFill_UVTexture:
      v25 = ST_TexUV;
      break;
    case PrimFill_UVTextureAlpha_VColor:
      v25 = ST_Text;
      break;
    default:
      v25 = ST_start_base_text;
      break;
  }
  v26 = this->vfptr->GetShaderVersion(this);
  Desc = Scaleform::Render::D3D1x::VertexShaderDesc::GetDesc(v25, v26);
  v28 = Desc;
  if ( !Desc )
  {
    *instanced = 0i64;
    v29 = batch;
    *single = 0i64;
    *v29 = 0i64;
    return;
  }
  v30 = -1;
  v31 = 0;
  v32 = 4;
  v33 = 0;
  v34 = 0;
  v71 = 4;
  v72 = -1;
  if ( Desc->NumAttribs > 0 )
  {
    p_keys = &keys;
    v36 = &keys.4;
    p_Attr = &Desc->Attributes[0].Attr;
    while ( (*p_Attr & 0xFF0F) == 4612 )
    {
      v38 = v33 + 1;
      p_keys->Offset = v31;
      v72 = v38;
      if ( (v12 & 0x20) != 0 )
      {
        v36->Attribute = 4625;
        v39 = v36 + 2;
        v30 = v31 + 1;
        v39->Attribute = 8721;
      }
      else
      {
        v36->Attribute = 8721;
        v39 = v36 + 2;
        v30 = v31 + 2;
        v39->Attribute = 4625;
      }
      v32 = v71;
      v40 = p_keys + 1;
      v33 = v38 + 1;
      v40->Offset = v31 + 3;
      p_keys = v40 + 1;
      v36 = v39 + 2;
      v31 += 4;
LABEL_51:
      ++v34;
      p_Attr += 8;
      if ( v34 >= v28->NumAttribs )
        goto LABEL_52;
    }
    pElements = sourceFormat->pElements;
    Attribute = pElements->Attribute;
    if ( !Attribute )
    {
LABEL_39:
      *instanced = 0i64;
      *v73 = 0i64;
      *batch = 0i64;
      return;
    }
    while ( (Attribute & 0xFF00) != (*p_Attr & 0xFF00) )
    {
      Attribute = pElements[1].Attribute;
      ++pElements;
      if ( !Attribute )
        goto LABEL_39;
    }
    *p_keys = *pElements;
    p_keys->Offset = v31;
    v43 = pElements->Attribute;
    v44 = v43 & 0xFFF;
    if ( (v12 & 4) != 0 )
    {
      if ( v44 == 532 )
      {
        v45 = v43 & 0xFFFFF000 | 0x251;
LABEL_45:
        v36->Attribute = v45;
      }
    }
    else if ( v44 == 593 )
    {
      v45 = v43 & 0xFFFFF000 | 0x214;
      goto LABEL_45;
    }
    v46 = VertexTypeSizes_44[((unsigned __int8)pElements->Attribute >> 4) - 1];
    if ( v46 < v71 )
      v46 = v71;
    v32 = v46;
    v71 = v46;
    v12 = flags;
    v31 += (p_keys->Attribute & 0xF) * VertexTypeSizes_44[((unsigned __int8)p_keys->Attribute >> 4) - 1];
    if ( (flags & 2) != 0 )
      v31 = (v31 + 3) & 0xFFFFFFFC;
    ++v33;
    v36 += 2;
    ++p_keys;
    goto LABEL_51;
  }
LABEL_52:
  if ( (v12 & 1) != 0 )
    v24 = v32;
  flags = v24;
  v47 = v70;
  *((_QWORD *)&keys + v33) = 0i64;
  v48 = (Scaleform::Render::MultiKeyCollection<Scaleform::Render::VertexElement,Scaleform::Render::VertexFormat,32,8> *)&v47[1];
  ppnewKeys.pFirst = (Scaleform::Render::SourceFormatHash *)&keys;
  v49 = Scaleform::Render::MultiKeyCollection<Scaleform::Render::VertexElement,Scaleform::Render::VertexFormat,32,8>::Find(
          v48,
          &keys,
          v33 + 1);
  if ( !v49 )
  {
    v49 = Scaleform::Render::MultiKeyCollection<Scaleform::Render::VertexElement,Scaleform::Render::VertexFormat,32,8>::Add(
            v48,
            (Scaleform::Render::VertexElement **)&ppnewKeys,
            &keys,
            v33 + 1);
    if ( v49 )
    {
      v50 = ~(flags - 1) & (v31 + flags - 1);
      v49->pElements = (Scaleform::Render::VertexElement *)ppnewKeys.pFirst;
      v49->Size = v50;
    }
    else
    {
      v49 = 0i64;
    }
  }
  *v73 = v49;
  if ( (v12 & 8) != 0 )
  {
    *(&keys.Offset + 2 * v33) = 0;
    *(&keys.Attribute + 2 * v33) = 66673;
    v70 = &keys;
    v62[v33] = 0i64;
    v51 = Scaleform::Render::MultiKeyCollection<Scaleform::Render::VertexElement,Scaleform::Render::VertexFormat,32,8>::Find(
            v48,
            &keys,
            v33 + 2);
    if ( !v51 )
    {
      v51 = Scaleform::Render::MultiKeyCollection<Scaleform::Render::VertexElement,Scaleform::Render::VertexFormat,32,8>::Add(
              v48,
              &v70,
              &keys,
              v33 + 2);
      if ( !v51 )
      {
        v52 = (__int64 *)instanced;
        *instanced = 0i64;
        goto LABEL_65;
      }
      v53 = ~(flags - 1) & (v31 + flags - 1);
      v51->pElements = v70;
      v51->Size = v53;
    }
    v52 = (__int64 *)instanced;
    *instanced = v51;
  }
  else
  {
    v52 = (__int64 *)instanced;
    *instanced = 0i64;
  }
LABEL_65:
  if ( (v12 & 0x10) != 0 )
  {
    v59 = (__int64 *)batch;
    *batch = 0i64;
    goto LABEL_80;
  }
  if ( v30 < 0 )
  {
    *(&keys.Attribute + 2 * v33) = 66593;
    v57 = v31;
    if ( (v12 & 0x20) != 0 )
      v57 = v31 + 3;
    *(&keys.Offset + 2 * v33) = v57;
    v31 += (*(&keys.Attribute + 2 * v33) & 0xF)
         * VertexTypeSizes_44[((unsigned __int8)*(&keys.Attribute + 2 * v33) >> 4) - 1];
    if ( (v12 & 2) != 0 )
      v31 = (v31 + 3) & 0xFFFFFFFC;
  }
  else
  {
    v54 = v72;
    v55 = v33 - 1;
    if ( v55 >= v72 )
    {
      do
      {
        v56 = *((_QWORD *)&keys + v55--);
        v62[v55 + 1] = v56;
      }
      while ( v55 >= v54 );
    }
    *(&keys.Attribute + 2 * v54) = 66593;
    *(&keys.Offset + 2 * v54) = v30;
  }
  v62[v33] = 0i64;
  v70 = &keys;
  v58 = Scaleform::Render::MultiKeyCollection<Scaleform::Render::VertexElement,Scaleform::Render::VertexFormat,32,8>::Find(
          v48,
          &keys,
          v33 + 2);
  if ( v58 )
    goto LABEL_78;
  v58 = Scaleform::Render::MultiKeyCollection<Scaleform::Render::VertexElement,Scaleform::Render::VertexFormat,32,8>::Add(
          v48,
          &v70,
          &keys,
          v33 + 2);
  if ( v58 )
  {
    v60 = ~(flags - 1) & (v31 + flags - 1);
    v58->pElements = v70;
    v58->Size = v60;
LABEL_78:
    v59 = (__int64 *)batch;
    *batch = v58;
    goto LABEL_80;
  }
  v59 = (__int64 *)batch;
  *batch = 0i64;
LABEL_80:
  v66 = *v73;
  v67 = (Scaleform::Render::VertexFormat *)*v59;
  v68 = *v52;
  ppnewKeys.pFirst = (Scaleform::Render::SourceFormatHash *)v64;
  ppnewKeys.pSecond = (Scaleform::Render::ResultFormat *)&v66;
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::Render::SourceFormatHash,Scaleform::Render::ResultFormat,Scaleform::FixedSizeHash<Scaleform::Render::SourceFormatHash>>,Scaleform::HashNode<Scaleform::Render::SourceFormatHash,Scaleform::Render::ResultFormat,Scaleform::FixedSizeHash<Scaleform::Render::SourceFormatHash>>::NodeHashF,Scaleform::HashNode<Scaleform::Render::SourceFormatHash,Scaleform::Render::ResultFormat,Scaleform::FixedSizeHash<Scaleform::Render::SourceFormatHash>>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Render::SourceFormatHash,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::Render::SourceFormatHash,Scaleform::Render::ResultFormat,Scaleform::FixedSizeHash<Scaleform::Render::SourceFormatHash>>,Scaleform::HashNode<Scaleform::Render::SourceFormatHash,Scaleform::Render::ResultFormat,Scaleform::FixedSizeHash<Scaleform::Render::SourceFormatHash>>::NodeHashF>>::Set<Scaleform::HashNode<Scaleform::Render::SourceFormatHash,Scaleform::Render::ResultFormat,Scaleform::FixedSizeHash<Scaleform::Render::SourceFormatHash>>::NodeRef>(
    (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::Render::SourceFormatHash,Scaleform::Render::ResultFormat,Scaleform::FixedSizeHash<Scaleform::Render::SourceFormatHash> >,Scaleform::HashNode<Scaleform::Render::SourceFormatHash,Scaleform::Render::ResultFormat,Scaleform::FixedSizeHash<Scaleform::Render::SourceFormatHash> >::NodeHashF,Scaleform::HashNode<Scaleform::Render::SourceFormatHash,Scaleform::Render::ResultFormat,Scaleform::FixedSizeHash<Scaleform::Render::SourceFormatHash> >::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Render::SourceFormatHash,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::Render::SourceFormatHash,Scaleform::Render::ResultFormat,Scaleform::FixedSizeHash<Scaleform::Render::SourceFormatHash> >,Scaleform::HashNode<Scaleform::Render::SourceFormatHash,Scaleform::Render::ResultFormat,Scaleform::FixedSizeHash<Scaleform::Render::SourceFormatHash> >::NodeHashF> > *)pmemAddr,
    pmemAddr,
    &ppnewKeys);
}

// File Line: 695
// RVA: 0xA02130
Scaleform::Render::D3D1x::ShaderPair *__fastcall Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::SetPrimitiveFill(
        Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture> *this,
        Scaleform::Render::PrimitiveFill *pfill,
        unsigned int *fillFlags,
        unsigned int batchType)
{
  unsigned int *v6; // rdi
  __int64 v7; // r15
  unsigned int v8; // r13d
  unsigned int v9; // ebx
  Scaleform::Render::MatrixPoolImpl::HMatrix *v10; // rdi
  Scaleform::Render::MatrixPoolImpl::DataHeader *pHeader; // rdx
  Scaleform::Render::Cxform *v12; // r8
  float v13; // xmm0_4
  unsigned int v14; // r9d
  Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture> *v15; // rsi
  Scaleform::Render::D3D1x::ShaderDesc::ShaderType v16; // ebx
  Scaleform::Render::D3D1x::ShaderInterface *v17; // rdi
  Scaleform::Render::D3D1x::ShaderPair *p_CurShaders; // rsi
  unsigned __int8 *v19; // rax
  __m128i v20; // xmm2
  Scaleform::Render::D3D1x::VertexShaderDesc *pVDesc; // rcx
  __m128i v22; // xmm3
  float v23; // xmm0_4
  float v24; // xmm1_4
  Scaleform::Render::D3D1x::BatchVar *BatchUniforms; // rax
  float v26; // xmm1_4
  char Offset; // dl
  float v28; // xmm2_4
  float v29; // xmm3_4
  __int64 Array; // rax
  int v31; // r10d
  Scaleform::Render::D3D1x::BatchVar *v32; // rdx
  char v33; // al
  Scaleform::Render::D3D1x::UniformVar *Uniforms; // r8
  unsigned __int64 v35; // rcx
  Scaleform::Render::D3D1x::UniformVar *v36; // r8
  unsigned __int64 v37; // rcx
  Scaleform::Render::D3D1x::UniformVar *v38; // rax
  __int64 ShadowOffset; // rax
  Scaleform::Render::D3D1x::UniformVar *v40; // rcx
  __int64 v41; // rax
  __int128 v42; // xmm0
  __int128 v43; // xmm1
  Scaleform::Render::Texture *pObject; // rbx
  __int128 v45; // xmm0
  __int128 v46; // xmm1
  Scaleform::Render::Texture *v47; // r9
  unsigned int TextureCount; // eax
  unsigned int v49; // ebx
  Scaleform::Render::MatrixPoolImpl::HMatrix *v50; // r14
  Scaleform::Render::D3D1x::VertexShaderDesc *v51; // rcx
  Scaleform::Render::D3D1x::BatchVar *v52; // rax
  unsigned __int8 v53; // dl
  unsigned __int16 v54; // r12
  Scaleform::Render::D3D1x::UniformVar *v55; // rax
  __int16 v56; // dx
  Scaleform::Render::D3D1x::FragShaderDesc *pFDesc; // rdx
  Scaleform::Render::D3D1x::BatchVar *v58; // rcx
  unsigned __int8 v59; // r8
  Scaleform::Render::D3D1x::UniformVar *v60; // rcx
  __int16 Size; // dx
  unsigned int batch; // r13d
  __int64 v63; // r14
  unsigned int v64; // r12d
  Scaleform::Render::MatrixPoolImpl::HMatrix *v65; // rbx
  Scaleform::Render::MatrixPoolImpl::HMatrix *v66; // rax
  Scaleform::Render::ProfileViews *Profiler; // rcx
  unsigned __int8 *v68; // rax
  __m128i v69; // xmm2
  Scaleform::Render::D3D1x::VertexShaderDesc *v70; // rcx
  __m128i v71; // xmm3
  float v72; // xmm0_4
  float v73; // xmm1_4
  Scaleform::Render::D3D1x::BatchVar *v74; // rax
  float v75; // xmm1_4
  char v76; // dl
  float v77; // xmm2_4
  float v78; // xmm3_4
  __int64 v79; // rax
  int v80; // r10d
  Scaleform::Render::D3D1x::BatchVar *v81; // rdx
  char v82; // al
  Scaleform::Render::D3D1x::UniformVar *v83; // r8
  unsigned __int64 v84; // rcx
  Scaleform::Render::D3D1x::UniformVar *v85; // r8
  unsigned __int64 v86; // rcx
  Scaleform::Render::D3D1x::UniformVar *v87; // rax
  __int64 v88; // rax
  Scaleform::Render::D3D1x::UniformVar *v89; // rcx
  __int64 v90; // rax
  Scaleform::Render::MatrixPoolImpl::DataHeader *v91; // rdx
  Scaleform::Render::Cxform *v92; // r8
  Scaleform::Render::Cxform *v93; // rbx
  unsigned int v94; // ebx
  int v95; // r15d
  __int64 v96; // r14
  __int64 v97; // rax
  int v98; // xmm1_4
  Scaleform::Render::MatrixPoolImpl::EntryHandle *pHandle; // rax
  Scaleform::Render::Matrix2x4<float> *v100; // rdx
  Scaleform::Render::MatrixPoolImpl::HMatrix *v102; // [rsp+8h] [rbp-49h]
  __int64 v103; // [rsp+10h] [rbp-41h]
  Scaleform::Render::D3D1x::ShaderPair v104[2]; // [rsp+18h] [rbp-39h] BYREF
  Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture> *v105; // [rsp+98h] [rbp+47h]
  char v106[8]; // [rsp+A0h] [rbp+4Fh] BYREF
  unsigned int *v107; // [rsp+A8h] [rbp+57h]
  Scaleform::Render::VertexFormat *pformat; // [rsp+B8h] [rbp+67h]
  unsigned int vars0; // [rsp+C0h] [rbp+6Fh]
  Scaleform::Render::MatrixState *retaddr; // [rsp+C8h] [rbp+77h]
  Scaleform::Render::MatrixPoolImpl::HMatrix *m; // [rsp+D0h] [rbp+7Fh]
  Scaleform::Render::D3D1x::ShaderInterface *v112; // [rsp+D8h] [rbp+87h] BYREF
  unsigned int *v113; // [rsp+E0h] [rbp+8Fh]

  v113 = fillFlags;
  m = (Scaleform::Render::MatrixPoolImpl::HMatrix *)this;
  v6 = fillFlags;
  v7 = this->Profiler->vfptr->GetFillType(this->Profiler, pfill->Data.Type);
  if ( (*(_BYTE *)v6 & 0x20) == 0 && Scaleform::Render::PrimitiveFillData::RequiresBlend(&pfill->Data) )
    *v6 |= 0x20u;
  v8 = vars0;
  if ( (*(_BYTE *)v6 & 0x28) != 40 )
  {
    v9 = 0;
    if ( vars0 )
    {
      v10 = m;
      while ( 1 )
      {
        pHeader = v10->pHandle->pHeader;
        v12 = (pHeader->Format & 1) != 0
            ? (Scaleform::Render::Cxform *)&pHeader[(unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[pHeader->Format & 0xF].Offsets[0]
                                                  + 1]
            : &Scaleform::Render::Cxform::Identity;
        v105->Profiler->vfptr->GetCxform(v105->Profiler, (Scaleform::Render::Cxform *)v104, v12);
        if ( Scaleform::Render::Cxform::operator!=(
               (Scaleform::Render::Cxform *)v104,
               &Scaleform::Render::Cxform::Identity) )
        {
          break;
        }
        ++v9;
        v10 += 2;
        if ( v9 >= v8 )
        {
          v6 = v107;
          goto LABEL_15;
        }
      }
      v6 = v107;
      v13 = *((float *)&v104[0].pVDesc + 1);
      *v107 |= 8u;
      if ( v13 < 1.0 )
        *v6 |= 0x20u;
    }
  }
LABEL_15:
  v14 = batchType;
  v15 = v105;
  v16 = Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::StaticShaderForFill(
          v105,
          pfill,
          v6,
          v14);
  v15->Profiler->vfptr->SetFillFlags(v15->Profiler, *v6);
  v17 = v112;
  Scaleform::Render::D3D1x::ShaderInterface::SetStaticShader(v112, v16, pformat);
  p_CurShaders = &v17->CurShaders;
  if ( Scaleform::Render::PrimitiveFill::IsSolid(v7) )
  {
    LODWORD(v112) = pfill->Data.SolidColor.Raw;
    v19 = (unsigned __int8 *)((__int64 (__fastcall *)(Scaleform::Render::ProfileViews *, char *, Scaleform::Render::D3D1x::ShaderInterface **))v105->Profiler->vfptr->GetColor)(
                               v105->Profiler,
                               v106,
                               &v112);
    v20 = _mm_cvtsi32_si128(*v19);
    pVDesc = v17->CurShaders.pVDesc;
    v22 = _mm_cvtsi32_si128(v19[3]);
    v23 = (float)v19[2] * 0.0039215689;
    v24 = (float)v19[1];
    BatchUniforms = pVDesc->BatchUniforms;
    v26 = v24 * 0.0039215689;
    Offset = BatchUniforms[5].Offset;
    v28 = _mm_cvtepi32_ps(v20).m128_f32[0] * 0.0039215689;
    v29 = _mm_cvtepi32_ps(v22).m128_f32[0] * 0.0039215689;
    if ( Offset >= 0 )
    {
      Array = (unsigned int)BatchUniforms[5].Array;
      v31 = Offset;
LABEL_20:
      Uniforms = pVDesc->Uniforms;
      if ( Uniforms[Array].Size )
      {
        v35 = Uniforms[Array].ShadowOffset
            + (unsigned __int64)(v31 * (unsigned int)(unsigned __int8)Uniforms[Array].ElementSize);
        v17->UniformData[v35] = v23;
        v17->UniformData[v35 + 1] = v26;
        v17->UniformData[v35 + 2] = v28;
        v17->UniformData[v35 + 3] = v29;
      }
      v36 = v17->CurShaders.pFDesc->Uniforms;
      if ( v36[Array].Size )
      {
        v37 = v36[Array].ShadowOffset + (unsigned __int64)(v31 * (unsigned int)(unsigned __int8)v36[Array].ElementSize);
        v17->UniformData[v37] = v23;
        v17->UniformData[v37 + 1] = v26;
        v17->UniformData[v37 + 2] = v28;
        v17->UniformData[v37 + 3] = v29;
      }
      v17->UniformSet[(unsigned int)Array] = 1;
      goto LABEL_33;
    }
    v32 = v17->CurShaders.pFDesc->BatchUniforms;
    v33 = v32[5].Offset;
    if ( v33 >= 0 )
    {
      v31 = v33;
      Array = (unsigned int)v32[5].Array;
      goto LABEL_20;
    }
    v38 = pVDesc->Uniforms;
    if ( v38[5].Size )
    {
      ShadowOffset = v38[5].ShadowOffset;
      v17->UniformData[ShadowOffset] = v23;
      v17->UniformData[ShadowOffset + 1] = v26;
      v17->UniformData[ShadowOffset + 2] = v28;
      v17->UniformData[ShadowOffset + 3] = v29;
    }
    v40 = v17->CurShaders.pFDesc->Uniforms;
    if ( v40[5].Size )
    {
      v41 = v40[5].ShadowOffset;
      v17->UniformData[v41] = v23;
      v17->UniformData[v41 + 1] = v26;
      v17->UniformData[v41 + 2] = v28;
      v17->UniformData[v41 + 3] = v29;
    }
    v17->UniformSet[5] = 1;
  }
  else if ( (int)v7 >= 5 )
  {
    v42 = *(_OWORD *)&p_CurShaders->pVS;
    v43 = *(_OWORD *)&v17->CurShaders.pFS;
    pObject = pfill->Data.Textures[0].pObject;
    LOBYTE(v112) = pfill->Data.FillModes[0].Fill;
    *(_OWORD *)&v104[0].pVS = v42;
    *(_OWORD *)&v104[0].pFS = v43;
    v104[0].pVFormat = v17->CurShaders.pVFormat;
    Scaleform::Render::D3D1x::ShaderInterface::SetTexture(
      v17,
      v104,
      0x14u,
      pObject,
      (Scaleform::Render::ImageFillMode)&v112,
      0);
    if ( (unsigned int)(v7 - 9) <= 1 )
    {
      v45 = *(_OWORD *)&p_CurShaders->pVS;
      v46 = *(_OWORD *)&v17->CurShaders.pFS;
      v47 = pfill->Data.Textures[1].pObject;
      LOBYTE(v112) = pfill->Data.FillModes[1].Fill;
      TextureCount = (unsigned __int8)pObject->TextureCount;
      *(_OWORD *)&v104[0].pVS = v45;
      *(_OWORD *)&v104[0].pFS = v46;
      LODWORD(v104[0].pFS) = TextureCount;
      v104[0].pVFormat = v17->CurShaders.pVFormat;
      Scaleform::Render::D3D1x::ShaderInterface::SetTexture(
        v17,
        v104,
        0x14u,
        v47,
        (Scaleform::Render::ImageFillMode)&v112,
        TextureCount);
    }
  }
LABEL_33:
  if ( (_DWORD)v7 == 13 )
  {
    v49 = 0;
    if ( v8 )
    {
      v50 = m;
      do
      {
        Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUserUniforms(
          v17,
          &v17->CurShaders,
          v50,
          v49++);
        v50 += 2;
      }
      while ( v49 < v8 );
    }
  }
  v51 = v17->CurShaders.pVDesc;
  v52 = v51->BatchUniforms;
  if ( v52[21].Offset >= 0 && (v53 = v52[21].Size) != 0 )
  {
    v54 = v53;
  }
  else
  {
    v55 = v51->Uniforms;
    if ( v55[21].Location < 0 || (v56 = v55[21].Size, v56 <= 0) )
    {
      pFDesc = v17->CurShaders.pFDesc;
      v58 = pFDesc->BatchUniforms;
      if ( v58[21].Offset >= 0 && (v59 = v58[21].Size) != 0 )
      {
        v54 = v59;
      }
      else
      {
        v60 = pFDesc->Uniforms;
        if ( v60[21].Location < 0 || (Size = v60[21].Size, Size <= 0) )
          v54 = 0;
        else
          v54 = Size / (unsigned __int8)v55[21].ElementSize;
      }
    }
    else
    {
      v54 = v56 / (unsigned __int8)v55[21].ElementSize;
    }
  }
  batch = 0;
  v63 = v7;
  v64 = v54 >> 1;
  if ( vars0 )
  {
    v65 = m;
    v66 = m;
    do
    {
      Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetMatrix(
        v17,
        &v17->CurShaders,
        0xDu,
        (Scaleform::Render::Matrix2x4<float> *)&v65[1].pHandle[24],
        v66,
        retaddr,
        0,
        batch);
      if ( v63 != 1 )
      {
        if ( (*(_BYTE *)v107 & 8) != 0 )
        {
          v91 = v65->pHandle->pHeader;
          if ( (v91->Format & 1) != 0 )
            v92 = (Scaleform::Render::Cxform *)&v91[(unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[v91->Format & 0xF].Offsets[0]
                                                  + 1];
          else
            v92 = &Scaleform::Render::Cxform::Identity;
          v93 = v105->Profiler->vfptr->GetCxform(v105->Profiler, v104, v92);
          Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUniform(
            v17,
            &v17->CurShaders,
            5u,
            (const float *)v93,
            4u,
            0,
            batch);
          Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUniform(
            v17,
            &v17->CurShaders,
            4u,
            v93->M[1],
            4u,
            0,
            batch);
        }
        goto LABEL_72;
      }
      *(_WORD *)((char *)&v112 + 1) = 0x8000;
      LOBYTE(v112) = 0;
      Profiler = v105->Profiler;
      BYTE3(v112) = 0x80;
      v68 = (unsigned __int8 *)((__int64 (__fastcall *)(Scaleform::Render::ProfileViews *, char *, Scaleform::Render::D3D1x::ShaderInterface **))Profiler->vfptr->GetColor)(
                                 Profiler,
                                 v106,
                                 &v112);
      v69 = _mm_cvtsi32_si128(*v68);
      v70 = v17->CurShaders.pVDesc;
      v71 = _mm_cvtsi32_si128(v68[3]);
      v72 = (float)v68[2] * 0.0039215689;
      v73 = (float)v68[1];
      v74 = v70->BatchUniforms;
      v75 = v73 * 0.0039215689;
      v76 = v74[5].Offset;
      v77 = _mm_cvtepi32_ps(v69).m128_f32[0] * 0.0039215689;
      v78 = _mm_cvtepi32_ps(v71).m128_f32[0] * 0.0039215689;
      if ( v76 < 0 )
      {
        v81 = v17->CurShaders.pFDesc->BatchUniforms;
        v82 = v81[5].Offset;
        if ( v82 < 0 )
        {
          v87 = v70->Uniforms;
          if ( v87[5].Size )
          {
            v88 = v87[5].ShadowOffset;
            v17->UniformData[v88] = v72;
            v17->UniformData[v88 + 1] = v75;
            v17->UniformData[v88 + 2] = v77;
            v17->UniformData[v88 + 3] = v78;
          }
          v89 = v17->CurShaders.pFDesc->Uniforms;
          if ( v89[5].Size )
          {
            v90 = v89[5].ShadowOffset;
            v17->UniformData[v90] = v72;
            v17->UniformData[v90 + 1] = v75;
            v17->UniformData[v90 + 2] = v77;
            v17->UniformData[v90 + 3] = v78;
          }
          v17->UniformSet[5] = 1;
          goto LABEL_72;
        }
        v80 = v82;
        v79 = (unsigned int)v81[5].Array;
      }
      else
      {
        v79 = (unsigned int)v74[5].Array;
        v80 = v76;
      }
      v83 = v70->Uniforms;
      if ( v83[v79].Size )
      {
        v84 = v83[v79].ShadowOffset + (unsigned __int64)(v80 * (unsigned int)(unsigned __int8)v83[v79].ElementSize);
        v17->UniformData[v84] = v72;
        v17->UniformData[v84 + 1] = v75;
        v17->UniformData[v84 + 2] = v77;
        v17->UniformData[v84 + 3] = v78;
      }
      v85 = v17->CurShaders.pFDesc->Uniforms;
      if ( v85[v79].Size )
      {
        v86 = v85[v79].ShadowOffset + (unsigned __int64)(v80 * (unsigned int)(unsigned __int8)v85[v79].ElementSize);
        v17->UniformData[v86] = v72;
        v17->UniformData[v86 + 1] = v75;
        v17->UniformData[v86 + 2] = v77;
        v17->UniformData[v86 + 3] = v78;
      }
      v17->UniformSet[(unsigned int)v79] = 1;
LABEL_72:
      v94 = 0;
      v95 = 1;
      if ( v64 )
      {
        v96 = 1i64;
        do
        {
          v95 = __ROL4__(v95, 1);
          v97 = (__int64)&m[1].pHandle[24];
          *(_OWORD *)&v104[0].pVS = *(_OWORD *)v97;
          v104[0].pFS = *(Scaleform::Render::D3D1x::FragShader **)(v97 + 16);
          LODWORD(v104[0].pFDesc) = *(_DWORD *)(v97 + 24);
          v98 = *(_DWORD *)(v97 + 28);
          pHandle = m->pHandle;
          HIDWORD(v104[0].pFDesc) = v98;
          if ( ((unsigned __int8)v95 & pHandle->pHeader->Format) != 0 )
            v100 = (Scaleform::Render::Matrix2x4<float> *)&pHandle->pHeader[(unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[0].Offsets[4 * (pHandle->pHeader->Format & 0xF) + v96 + (pHandle->pHeader->Format & 0xF)]
                                                                          + 1];
          else
            v100 = &Scaleform::Render::Matrix2x4<float>::Identity;
          Scaleform::Render::Matrix2x4<float>::Append((Scaleform::Render::Matrix2x4<float> *)v104, v100);
          Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUniform(
            v17,
            &v17->CurShaders,
            0x15u,
            (const float *)v104,
            8u,
            2 * v94++,
            batch);
          ++v96;
        }
        while ( v94 < v64 );
        v63 = v103;
      }
      ++batch;
      v66 = v102 + 2;
      v65 = m + 2;
      m += 2;
    }
    while ( batch < vars0 );
  }
  return &v17->CurShaders;
}

// File Line: 788
// RVA: 0xA014A0
bool __fastcall Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::SetFilterFill(
        Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture> *this,
        Scaleform::Render::Matrix2x4<float> *mvp,
        Scaleform::Render::Cxform *cx,
        Scaleform::Render::Filter *filter,
        Scaleform::Ptr<Scaleform::Render::RenderTarget> *targets,
        unsigned int *shaders,
        unsigned int pass,
        unsigned int passCount,
        Scaleform::Render::VertexFormat *pvf,
        Scaleform::Render::D3D1x::ShaderInterface *psi)
{
  __int64 v10; // rbx
  unsigned int *v11; // r12
  Scaleform::Render::D3D1x::ShaderInterface *v12; // rdi
  bool result; // al
  Scaleform::Render::D3D1x::ShaderPair *p_CurShaders; // rsi
  Scaleform::Render::RenderTarget *pObject; // rcx
  unsigned int v18; // eax
  bool v19; // cf
  bool v20; // zf
  Scaleform::RefCountImplCoreVtbl *vfptr; // rax
  Scaleform::Render::Texture *v22; // rax
  __int128 v23; // xmm1
  Scaleform::Render::Texture *v24; // r13
  Scaleform::Render::VertexFormat *pVFormat; // xmm0_8
  float v26; // xmm7_4
  float x1; // xmm2_4
  float v28; // xmm3_4
  float v29; // xmm4_4
  Scaleform::Render::FilterType Type; // eax
  __m128 RefCount; // xmm3
  int v32; // ecx
  float Height; // xmm1_4
  __m128 v34; // xmm1
  int v35; // ecx
  float v36; // xmm2_4
  float v37; // xmm7_4
  float v38; // xmm2_4
  float v39; // xmm0_4
  int v40; // xmm0_4
  float v41; // xmm0_4
  Scaleform::Render::RenderTarget *v42; // rcx
  Scaleform::Render::Texture *v43; // rbx
  float v44; // xmm1_4
  __int128 v45; // xmm1
  Scaleform::Render::Texture *v46; // rax
  __int128 v47; // xmm1
  Scaleform::Render::VertexFormat *v48; // xmm0_8
  Scaleform::RefCountBase<Scaleform::Render::Filter,2> v49; // xmm0
  __int128 v50; // xmm3
  float v51; // xmm9_4
  float v52; // xmm7_4
  float v53; // xmm6_4
  float v54; // xmm5_4
  Scaleform::RefCountBase<Scaleform::Render::Filter,2> v55; // xmm4
  __int128 v56; // xmm8
  float v57; // xmm1_4
  char v58; // bl
  Scaleform::Render::Texture *v59; // rax
  __int128 v60; // xmm1
  Scaleform::Render::Texture *v61; // r12
  Scaleform::Render::FilterType v62; // ecx
  __int32 v63; // ecx
  __int32 v64; // ecx
  __int32 v65; // ecx
  float Width; // xmm4_4
  float v67; // xmm1_4
  int v68; // eax
  float v69; // xmm0_4
  float v70; // xmm3_4
  float v71; // xmm5_4
  float v72; // xmm1_4
  float v73; // xmm0_4
  Scaleform::Render::D3D1x::ShaderPair v; // [rsp+40h] [rbp-C0h] BYREF
  float v75[2]; // [rsp+70h] [rbp-90h] BYREF
  __int64 v76; // [rsp+78h] [rbp-88h]
  float v77[2]; // [rsp+80h] [rbp-80h] BYREF
  __int64 v78; // [rsp+88h] [rbp-78h]
  float v79[4]; // [rsp+90h] [rbp-70h] BYREF
  __int128 v80; // [rsp+A0h] [rbp-60h]
  __int128 v81; // [rsp+B0h] [rbp-50h]
  float v82; // [rsp+C0h] [rbp-40h]
  float v83; // [rsp+C4h] [rbp-3Ch]
  float v84; // [rsp+C8h] [rbp-38h]
  float v85; // [rsp+CCh] [rbp-34h]
  float v86[4]; // [rsp+D0h] [rbp-30h] BYREF

  v10 = pass;
  v11 = shaders;
  v12 = psi;
  result = Scaleform::Render::D3D1x::ShaderInterface::SetStaticShader(
             psi,
             (Scaleform::Render::D3D1x::ShaderDesc::ShaderType)shaders[pass],
             pvf);
  if ( result )
  {
    if ( !v12->PrimitiveOpen )
    {
      v12->PrimitiveOpen = 1;
      *(_QWORD *)v12->UniformSet = 0i64;
      *(_QWORD *)&v12->UniformSet[8] = 0i64;
      *(_QWORD *)&v12->UniformSet[16] = 0i64;
      *(_WORD *)&v12->UniformSet[24] = 0;
      v12->Textures[0] = 0i64;
      v12->Textures[1] = 0i64;
      v12->Textures[2] = 0i64;
      v12->Textures[3] = 0i64;
    }
    p_CurShaders = &v12->CurShaders;
    Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUniform(
      v12,
      &v12->CurShaders,
      0xDu,
      (const float *)mvp,
      8u,
      0,
      0);
    pObject = targets->pObject;
    v18 = v11[v10] - 655360;
    v19 = v18 < 0x19801;
    v20 = v18 == 104449;
    vfptr = targets->pObject->vfptr;
    LOBYTE(shaders) = v19 || v20;
    v22 = (Scaleform::Render::Texture *)((__int64 (__fastcall *)(Scaleform::Render::RenderTarget *))vfptr[3].__vecDelDtor)(pObject);
    v23 = *(_OWORD *)&v12->CurShaders.pFS;
    v24 = v22;
    *(_OWORD *)&v.pVS = *(_OWORD *)&v12->CurShaders.pVS;
    *(_OWORD *)&v.pFS = v23;
    pVFormat = v12->CurShaders.pVFormat;
    LOBYTE(pass) = 3;
    v.pVFormat = pVFormat;
    Scaleform::Render::D3D1x::ShaderInterface::SetTexture(
      v12,
      &v,
      0x14u,
      v22,
      (Scaleform::Render::ImageFillMode)&pass,
      0);
    v26 = 0.0;
    x1 = (float)targets->pObject->ViewRect.x1;
    v28 = (float)(targets->pObject->ViewRect.y2 - targets->pObject->ViewRect.y1) / (float)(int)v24->ImgSize.Height;
    *(float *)&v23 = (float)(targets->pObject->ViewRect.x2 - targets->pObject->ViewRect.x1)
                   / (float)(int)v24->ImgSize.Width;
    v29 = (float)targets->pObject->ViewRect.y1 * v28;
    *((float *)&v.pFS + 1) = v28;
    *((float *)&v.pFDesc + 1) = v29;
    LODWORD(v.pVS) = v23;
    *((float *)&v.pVS + 1) = *(float *)&v23 * 0.0;
    *(float *)&v.pVDesc = *(float *)&v23 * 0.0;
    *((float *)&v.pVDesc + 1) = x1 * *(float *)&v23;
    *(float *)&v.pFS = v28 * 0.0;
    *(float *)&v.pFDesc = v28 * 0.0;
    Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUniform(
      v12,
      &v12->CurShaders,
      0x15u,
      (const float *)&v,
      8u,
      0,
      0);
    Type = filter->Type;
    if ( Type <= Filter_GradientBevel )
    {
      Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetCxform(
        v12,
        &v12->CurShaders,
        cx,
        0,
        0);
      RefCount = (__m128)(unsigned int)filter[1].RefCount;
      RefCount.m128_f32[0] = RefCount.m128_f32[0] * 0.050000001;
      v32 = (int)RefCount.m128_f32[0];
      Height = (float)(int)v24->ImgSize.Height;
      v75[0] = 1.0 / (float)(int)v24->ImgSize.Width;
      v75[1] = 1.0 / Height;
      if ( (int)RefCount.m128_f32[0] != 0x80000000 && (float)v32 != RefCount.m128_f32[0] )
        RefCount.m128_f32[0] = (float)(v32 - (_mm_movemask_ps(_mm_unpacklo_ps(RefCount, RefCount)) & 1));
      if ( RefCount.m128_f32[0] < 1.0 )
        RefCount.m128_i32[0] = (int)FLOAT_1_0;
      v34 = (__m128)*((unsigned int *)&filter[1].RefCount + 1);
      v34.m128_f32[0] = v34.m128_f32[0] * 0.050000001;
      v35 = (int)v34.m128_f32[0];
      if ( (int)v34.m128_f32[0] != 0x80000000 && (float)v35 != v34.m128_f32[0] )
        v34.m128_f32[0] = (float)(v35 - (_mm_movemask_ps(_mm_unpacklo_ps(v34, v34)) & 1));
      if ( v34.m128_f32[0] < 1.0 )
        v34.m128_i32[0] = (int)FLOAT_1_0;
      if ( v11[v10] - 0x80000 <= 1 )
      {
        if ( (v10 & 1) == 0 )
        {
          v75[1] = 0.0;
          v39 = 1.0 / RefCount.m128_f32[0];
          v36 = (float)(RefCount.m128_f32[0] - 1.0) * 0.5;
LABEL_25:
          *((float *)&v.pVDesc + 1) = v39;
          if ( (_DWORD)v10 == passCount - 1 )
            v40 = (int)filter[2].vfptr;
          else
            v40 = (int)FLOAT_1_0;
          LODWORD(v.pVDesc) = v40;
          v41 = FLOAT_1_0eN12;
          if ( v36 < 1.0e-12 )
            v36 = FLOAT_1_0eN12;
          *(float *)&v.pVS = v36;
          if ( v26 >= 1.0e-12 )
            v41 = v26;
          *((float *)&v.pVS + 1) = v41;
          Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUniform(
            v12,
            &v12->CurShaders,
            8u,
            (const float *)&v,
            4u,
            0,
            0);
          Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUniform(
            v12,
            &v12->CurShaders,
            0x16u,
            v75,
            2u,
            0,
            0);
          if ( (_BYTE)shaders )
          {
            Scaleform::Render::Color::GetRGBAFloat(
              (Scaleform::Render::Color *)&filter[2].vfptr + 1,
              (float *)&v,
              (float *)&v.pVS + 1,
              (float *)&v.pVDesc,
              (float *)&v.pVDesc + 1);
            Scaleform::Render::Color::GetRGBAFloat(
              (Scaleform::Render::Color *)&filter[2].RefCount,
              (float *)&v.pFS,
              (float *)&v.pFS + 1,
              (float *)&v.pFDesc,
              (float *)&v.pFDesc + 1);
            v42 = targets[2].pObject;
            v77[0] = *(float *)&filter[1].Type * -0.050000001;
            v77[1] = *(float *)&filter[1].Frozen * -0.050000001;
            if ( v42 )
            {
              v43 = (Scaleform::Render::Texture *)((__int64 (__fastcall *)(Scaleform::Render::RenderTarget *))v42->vfptr[3].__vecDelDtor)(v42);
              v44 = (float)(int)v43->ImgSize.Height;
              *(float *)&shaders = 1.0 / (float)((float)(int)v43->ImgSize.Width * v75[0]);
              *((float *)&shaders + 1) = 1.0 / (float)(v44 * v75[1]);
              Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUniform(
                v12,
                &v12->CurShaders,
                0x13u,
                (const float *)&shaders,
                2u,
                0,
                0);
              v45 = *(_OWORD *)&v12->CurShaders.pFS;
              *(_OWORD *)v79 = *(_OWORD *)&p_CurShaders->pVS;
              LOBYTE(pass) = 3;
              *(_QWORD *)&v81 = v12->CurShaders.pVFormat;
              v80 = v45;
              Scaleform::Render::D3D1x::ShaderInterface::SetTexture(
                v12,
                (Scaleform::Render::D3D1x::ShaderPair *)v79,
                0x12u,
                v43,
                (Scaleform::Render::ImageFillMode)&pass,
                0);
            }
            Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUniform(
              v12,
              &v12->CurShaders,
              0xEu,
              v77,
              2u,
              0,
              0);
            if ( filter->Type == Filter_Bevel )
              Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUniform(
                v12,
                &v12->CurShaders,
                0x11u,
                (const float *)&v.pFS,
                4u,
                0,
                0);
            if ( (unsigned int)(filter->Type - 4) <= 1 )
            {
              v46 = (Scaleform::Render::Texture *)(*(__int64 (__fastcall **)(_QWORD, Scaleform::Render::TextureManager *))(**(_QWORD **)&filter[3].RefCount + 168i64))(
                                                    *(_QWORD *)&filter[3].RefCount,
                                                    v24->pManagerLocks.pObject->pManager);
              v47 = *(_OWORD *)&v12->CurShaders.pFS;
              *(_OWORD *)v79 = *(_OWORD *)&p_CurShaders->pVS;
              v80 = v47;
              v48 = v12->CurShaders.pVFormat;
              LOBYTE(pass) = 3;
              *(_QWORD *)&v81 = v48;
              Scaleform::Render::D3D1x::ShaderInterface::SetTexture(
                v12,
                (Scaleform::Render::D3D1x::ShaderPair *)v79,
                9u,
                v46,
                (Scaleform::Render::ImageFillMode)&pass,
                0);
            }
            else
            {
              Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUniform(
                v12,
                &v12->CurShaders,
                0x10u,
                (const float *)&v,
                4u,
                0,
                0);
            }
          }
          goto LABEL_63;
        }
        v38 = v34.m128_f32[0];
        v75[0] = 0.0;
      }
      else
      {
        if ( (_DWORD)v10 == passCount - 1 && (_DWORD)v10 )
        {
          v36 = 0.0;
          v26 = (float)(v34.m128_f32[0] - 1.0) * 0.5;
LABEL_24:
          v39 = 1.0 / v34.m128_f32[0];
          goto LABEL_25;
        }
        v37 = v34.m128_f32[0];
        v38 = RefCount.m128_f32[0];
        v34.m128_f32[0] = v34.m128_f32[0] * RefCount.m128_f32[0];
        v26 = (float)(v37 - 1.0) * 0.5;
      }
      v36 = (float)(v38 - 1.0) * 0.5;
      goto LABEL_24;
    }
    if ( Type == Filter_ColorMatrix )
    {
      v49 = filter[1].Scaleform::RefCountBase<Scaleform::Render::Filter,2>;
      v50 = *(_OWORD *)&filter[2].RefCount;
      *(Scaleform::RefCountBase<Scaleform::Render::Filter,2> *)v79 = v49;
      v81 = v50;
      v51 = cx->M[0][3];
      v52 = cx->M[0][0];
      v53 = cx->M[0][1];
      v54 = cx->M[0][2];
      v80 = *(_OWORD *)&filter[1].Type;
      v55 = filter[3].Scaleform::RefCountBase<Scaleform::Render::Filter,2>;
      v56 = *(_OWORD *)&filter[3].Type;
      v79[0] = (float)(*(float *)&v49.vfptr * v52) * v51;
      *(_OWORD *)v86 = v56;
      v79[2] = (float)(*(float *)&v49.RefCount * v54) * v51;
      *(float *)&v81 = (float)(*(float *)&v50 * v52) * v51;
      *(float *)&v80 = (float)(*(float *)&v80 * v52) * v51;
      v82 = (float)(*(float *)&v55.vfptr * v52) * v51;
      v79[1] = (float)(*((float *)&v49.vfptr + 1) * v53) * v51;
      *((float *)&v80 + 2) = (float)(*((float *)&v80 + 2) * v54) * v51;
      v79[3] = *((float *)&v49.RefCount + 1) * v51;
      *((float *)&v80 + 1) = (float)(*((float *)&v80 + 1) * v53) * v51;
      *((float *)&v81 + 2) = (float)(*((float *)&v50 + 2) * v54) * v51;
      *((float *)&v80 + 3) = *((float *)&v80 + 3) * v51;
      *((float *)&v81 + 1) = (float)(*((float *)&v50 + 1) * v53) * v51;
      v84 = (float)(*(float *)&v55.RefCount * v54) * v51;
      *((float *)&v81 + 3) = *((float *)&v50 + 3) * v51;
      v83 = (float)(*((float *)&v55.vfptr + 1) * v53) * v51;
      v85 = *((float *)&v55.RefCount + 1) * v51;
      v86[0] = (float)((float)(cx->M[1][0] * 0.0039215689) + (float)((float)(*(float *)&v56 * v52) * v51)) * v51;
      v57 = cx->M[1][2];
      v86[1] = (float)((float)(cx->M[1][1] * 0.0039215689) + (float)((float)(*((float *)&v56 + 1) * v53) * v51)) * v51;
      *(float *)&v49.vfptr = cx->M[1][3];
      v86[2] = (float)((float)(v57 * 0.0039215689) + (float)((float)(*((float *)&v56 + 2) * v54) * v51)) * v51;
      v86[3] = (float)((float)(*(float *)&v49.vfptr * 0.0039215689) + (float)(*((float *)&v56 + 3) * v51)) * v51;
      Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUniform(
        v12,
        &v12->CurShaders,
        4u,
        v86,
        4u,
        0,
        0);
      Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUniform(
        v12,
        &v12->CurShaders,
        5u,
        v79,
        0x10u,
        0,
        0);
LABEL_63:
      Scaleform::Render::D3D1x::ShaderInterface::Finish(v12, 1u);
      return 1;
    }
    if ( Type != Filter_DisplacementMap )
      goto LABEL_63;
    v58 = 3;
    if ( !LODWORD(filter[2].vfptr) )
      v58 = 2;
    v59 = (Scaleform::Render::Texture *)(*((__int64 (__fastcall **)(Scaleform::RefCountImplCoreVtbl *, _QWORD))filter[1].vfptr->__vecDelDtor
                                         + 21))(
                                          filter[1].vfptr,
                                          0i64);
    LOBYTE(pass) = v58;
    v60 = *(_OWORD *)&v12->CurShaders.pFS;
    v61 = v59;
    *(_OWORD *)v79 = *(_OWORD *)&p_CurShaders->pVS;
    v80 = v60;
    *(_QWORD *)&v81 = v12->CurShaders.pVFormat;
    Scaleform::Render::D3D1x::ShaderInterface::SetTexture(
      v12,
      (Scaleform::Render::D3D1x::ShaderPair *)v79,
      0xBu,
      v59,
      (Scaleform::Render::ImageFillMode)&pass,
      0);
    v62 = filter[1].Type;
    *(_QWORD *)v77 = 0i64;
    v78 = 0i64;
    *(_QWORD *)v75 = 0i64;
    v76 = 0i64;
    v.pVS = 0i64;
    v.pVDesc = 0i64;
    shaders = 0i64;
    v63 = v62 - 1;
    if ( v63 )
    {
      v64 = v63 - 1;
      if ( !v64 )
      {
        v77[1] = 1.0;
        goto LABEL_53;
      }
      v65 = v64 - 2;
      if ( !v65 )
      {
        LODWORD(v78) = 1065353216;
        goto LABEL_53;
      }
      if ( v65 == 4 )
      {
        HIDWORD(v78) = 1065353216;
        goto LABEL_53;
      }
    }
    v77[0] = 1.0;
LABEL_53:
    if ( *(_DWORD *)&filter[1].Frozen != 1 )
    {
      switch ( *(_DWORD *)&filter[1].Frozen )
      {
        case 2:
          v75[1] = 1.0;
          goto LABEL_61;
        case 4:
          LODWORD(v76) = 1065353216;
          goto LABEL_61;
        case 8:
          HIDWORD(v76) = 1065353216;
          goto LABEL_61;
      }
    }
    v75[0] = 1.0;
LABEL_61:
    Width = (float)(int)v24->ImgSize.Width;
    v67 = (float)(int)v61->ImgSize.Height;
    v68 = v24->ImgSize.Height;
    v69 = 1.0 / (float)(int)v61->ImgSize.Width;
    v70 = v69 * *(float *)&filter[1].RefCount;
    *(float *)&v.pVS = v69 * Width;
    *(float *)&v.pVDesc = v70;
    v71 = 1.0 / v67;
    v72 = *(float *)&filter[2].RefCount;
    *((float *)&v.pVDesc + 1) = v71 * *((float *)&filter[1].RefCount + 1);
    *((float *)&v.pVS + 1) = v71 * (float)v68;
    v73 = *((float *)&filter[2].vfptr + 1) / Width;
    *((float *)&shaders + 1) = v72 / (float)v68;
    *(float *)&shaders = v73;
    Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUniform(
      v12,
      &v12->CurShaders,
      2u,
      v77,
      4u,
      0,
      0);
    Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUniform(
      v12,
      &v12->CurShaders,
      3u,
      v75,
      4u,
      0,
      0);
    Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUniform(
      v12,
      &v12->CurShaders,
      0xAu,
      (const float *)&v,
      4u,
      0,
      0);
    Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUniform(
      v12,
      &v12->CurShaders,
      0xFu,
      (const float *)&shaders,
      2u,
      0,
      0);
    if ( LODWORD(filter[2].vfptr) == 3 )
    {
      Scaleform::Render::Color::GetRGBAFloat(
        (Scaleform::Render::Color *)&filter[2].RefCount + 1,
        (float *)&v,
        (float *)&v.pVS + 1,
        (float *)&v.pVDesc,
        (float *)&v.pVDesc + 1);
      Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUniform(
        v12,
        &v12->CurShaders,
        1u,
        (const float *)&v,
        4u,
        0,
        0);
    }
    goto LABEL_63;
  }
  return result;
}

// File Line: 995
// RVA: 0x9FED20
__int64 __fastcall Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::GetFilterPasses(
        Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture> *this,
        Scaleform::Render::Filter *filter,
        char fillFlags,
        unsigned int *passes)
{
  Scaleform::Render::FilterType Type; // eax
  unsigned int vfptr_high; // r8d
  char v7; // bl
  unsigned int v8; // r10d
  int v9; // eax
  unsigned int *v10; // rdi
  __int64 i; // rcx
  int v12; // edi
  int vfptr; // eax
  unsigned int *v14; // rcx
  unsigned int v15; // eax
  int v16; // eax
  int v17; // edx
  int v19; // eax
  unsigned int v20; // eax

  Type = filter->Type;
  if ( Type > Filter_GradientBevel )
  {
    if ( Type == Filter_ColorMatrix )
    {
      vfptr_high = 1;
      *passes = 393216;
      if ( (fillFlags & 1) != 0 )
      {
        *passes = 393217;
        return 1i64;
      }
    }
    else if ( Type == Filter_DisplacementMap )
    {
      *passes = 786432;
      vfptr_high = 1;
      if ( LODWORD(filter[2].vfptr) == 2 )
      {
        *passes = 851968;
        return 1i64;
      }
      if ( LODWORD(filter[2].vfptr) == 3 )
      {
        *passes = 786688;
        return 1i64;
      }
    }
    else
    {
      return 0;
    }
  }
  else
  {
    vfptr_high = HIDWORD(filter[1].vfptr);
    v7 = 0;
    if ( (float)(*((float *)&filter[1].RefCount + 1) * *(float *)&filter[1].RefCount) >= 12800.0 )
    {
      vfptr_high *= 2;
      v7 = 1;
    }
    v8 = 0;
    if ( vfptr_high != 1 )
    {
      v8 = vfptr_high - 1;
      v9 = 557056;
      v10 = passes;
      if ( v7 )
        v9 = 0x80000;
      for ( i = v8; i; --i )
        *v10++ = v9;
    }
    v12 = (__int64)filter[1].vfptr & 7;
    if ( (unsigned int)(v12 - 1) > 4 )
    {
      v19 = 0x8000;
      if ( v7 )
        v19 = 0;
      v20 = v19 + 0x80000;
      passes[v8] = v20;
      if ( (fillFlags & 1) != 0 )
      {
        passes[v8] = v20 + 1;
        return vfptr_high;
      }
    }
    else
    {
      if ( (unsigned __int64)((__int64)filter[1].vfptr & 7) <= 2 )
      {
        passes[v8] = 655360;
      }
      else
      {
        switch ( v12 )
        {
          case 3:
            passes[v8] = 753664;
            break;
          case 4:
            passes[v8] = 671744;
            break;
          case 5:
            passes[v8] = 729088;
            break;
        }
      }
      vfptr = (int)filter[1].vfptr;
      if ( (vfptr & 0x20) != 0 )
      {
        v14 = &passes[v8];
        v15 = *v14;
        if ( (*v14 & 0x10000) != 0 || v12 == 4 )
        {
          v16 = v15 + 2048;
          *v14 = v16;
        }
        else
        {
          v16 = v15 + 1024;
          *v14 = v16;
        }
      }
      else if ( (vfptr & 0x80u) != 0 || v12 == 1 && (vfptr & 0x40) != 0 && (vfptr & 0x10) == 0 )
      {
        v14 = &passes[v8];
        v16 = *v14 + 512;
        *v14 = v16;
      }
      else
      {
        v14 = &passes[v8];
        v16 = *v14;
      }
      v17 = (int)filter[1].vfptr;
      if ( (v17 & 0x40) != 0 || (v17 & 0x10) != 0 )
        v16 += 4096;
      *v14 = v16;
      if ( (fillFlags & 1) != 0 )
      {
        *v14 = v16 + 1;
        return vfptr_high;
      }
    }
  }
  return vfptr_high;
}

// File Line: 1151
// RVA: 0xA00F30
char __fastcall Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::SetDrawableCopyPixelsFill(
        Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture> *this,
        Scaleform::Render::Texture **tex,
        Scaleform::Render::Matrix2x4<float> *texgen,
        Scaleform::Render::Size<int> texsize,
        Scaleform::Render::Matrix2x4<float> *mvp,
        bool mergeAlpha,
        bool destAlpha,
        Scaleform::Render::VertexFormat *pvf,
        Scaleform::Render::D3D1x::ShaderInterface *psi)
{
  Scaleform::Render::D3D1x::ShaderDesc::ShaderType v10; // edx
  char result; // al

  v10 = ST_start_DrawableCopyPixels;
  if ( tex[2] )
    v10 = ST_DrawableCopyPixelsAlpha;
  if ( destAlpha )
  {
    if ( mergeAlpha )
      v10 += 64;
  }
  else
  {
    v10 += 32;
  }
  result = Scaleform::Render::D3D1x::ShaderInterface::SetStaticShader(psi, v10, pvf);
  if ( result )
  {
    if ( !psi->PrimitiveOpen )
    {
      psi->PrimitiveOpen = 1;
      *(_QWORD *)psi->UniformSet = 0i64;
      *(_QWORD *)&psi->UniformSet[8] = 0i64;
      *(_QWORD *)&psi->UniformSet[16] = 0i64;
      *(_WORD *)&psi->UniformSet[24] = 0;
      psi->Textures[0] = 0i64;
      psi->Textures[1] = 0i64;
      psi->Textures[2] = 0i64;
      psi->Textures[3] = 0i64;
    }
    return Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::DrawableFinish(
             this,
             (tex[2] != 0i64) + 2,
             tex,
             texgen);
  }
  return result;
}

// File Line: 1174
// RVA: 0xA01180
char __fastcall Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::SetDrawableMergeFill(
        Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture> *this,
        Scaleform::Render::Texture **tex,
        Scaleform::Render::Matrix2x4<float> *texgen,
        Scaleform::Render::Size<int> texsize,
        Scaleform::Render::Matrix4x4<float> *cxmul,
        Scaleform::Render::VertexFormat *pvf,
        Scaleform::Render::D3D1x::ShaderInterface *psi)
{
  char result; // al

  result = Scaleform::Render::D3D1x::ShaderInterface::SetStaticShader(psi, ST_start_DrawableMerge, pvf);
  if ( result )
  {
    if ( !psi->PrimitiveOpen )
    {
      psi->PrimitiveOpen = 1;
      *(_QWORD *)psi->UniformSet = 0i64;
      *(_QWORD *)&psi->UniformSet[8] = 0i64;
      *(_QWORD *)&psi->UniformSet[16] = 0i64;
      *(_WORD *)&psi->UniformSet[24] = 0;
      psi->Textures[0] = 0i64;
      psi->Textures[1] = 0i64;
      psi->Textures[2] = 0i64;
      psi->Textures[3] = 0i64;
    }
    Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUniform(
      psi,
      &psi->CurShaders,
      5u,
      (const float *)cxmul,
      0x10u,
      0,
      0);
    Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUniform(
      psi,
      &psi->CurShaders,
      6u,
      (const float *)&cxmul[1],
      0x10u,
      0,
      0);
    return Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::DrawableFinish(
             this,
             2u,
             tex,
             texgen);
  }
  return result;
}

// File Line: 1192
// RVA: 0xA01050
char __fastcall Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::SetDrawableCxform(
        Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture> *this,
        Scaleform::Render::Texture **tex,
        Scaleform::Render::Matrix2x4<float> *texgen,
        Scaleform::Render::Size<int> texsize,
        Scaleform::Render::Cxform *cx,
        Scaleform::Render::VertexFormat *pvf,
        Scaleform::Render::D3D1x::ShaderInterface *psi)
{
  char result; // al

  result = Scaleform::Render::D3D1x::ShaderInterface::SetStaticShader(psi, ST_TexTGCxform, pvf);
  if ( result )
  {
    if ( !psi->PrimitiveOpen )
    {
      psi->PrimitiveOpen = 1;
      *(_QWORD *)psi->UniformSet = 0i64;
      *(_QWORD *)&psi->UniformSet[8] = 0i64;
      *(_QWORD *)&psi->UniformSet[16] = 0i64;
      *(_WORD *)&psi->UniformSet[24] = 0;
      psi->Textures[0] = 0i64;
      psi->Textures[1] = 0i64;
      psi->Textures[2] = 0i64;
      psi->Textures[3] = 0i64;
    }
    Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetCxform(
      psi,
      &psi->CurShaders,
      cx,
      0,
      0);
    return Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::DrawableFinish(
             this,
             1u,
             tex,
             texgen);
  }
  return result;
}

// File Line: 1207
// RVA: 0xA00E20
char __fastcall Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::SetDrawableCompare(
        Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture> *this,
        Scaleform::Render::Texture **tex,
        Scaleform::Render::Matrix2x4<float> *texgen,
        Scaleform::Render::Size<int> texsize,
        Scaleform::Render::VertexFormat *pvf,
        Scaleform::Render::D3D1x::ShaderInterface *psi)
{
  char result; // al

  result = Scaleform::Render::D3D1x::ShaderInterface::SetStaticShader(psi, ST_start_DrawableCompare, pvf);
  if ( result )
  {
    if ( !psi->PrimitiveOpen )
    {
      psi->PrimitiveOpen = 1;
      *(_QWORD *)psi->UniformSet = 0i64;
      *(_QWORD *)&psi->UniformSet[8] = 0i64;
      *(_QWORD *)&psi->UniformSet[16] = 0i64;
      *(_WORD *)&psi->UniformSet[24] = 0;
      psi->Textures[0] = 0i64;
      psi->Textures[1] = 0i64;
      psi->Textures[2] = 0i64;
      psi->Textures[3] = 0i64;
    }
    return Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::DrawableFinish(
             this,
             2u,
             tex,
             texgen);
  }
  return result;
}

// File Line: 1220
// RVA: 0xA01310
char __fastcall Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::SetDrawablePaletteMap(
        Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture> *this,
        Scaleform::Render::Texture **tex,
        Scaleform::Render::Matrix2x4<float> *texgen,
        Scaleform::Render::Size<int> texsize,
        Scaleform::Render::Matrix2x4<float> *mvp,
        Scaleform::Render::Texture *paletteMap,
        Scaleform::Render::VertexFormat *pvf,
        Scaleform::Render::D3D1x::ShaderInterface *psi)
{
  char result; // al
  __int128 v13; // xmm0
  __int128 v14; // xmm1
  char v15; // [rsp+40h] [rbp-48h] BYREF
  Scaleform::Render::Size<int> v16; // [rsp+48h] [rbp-40h]
  Scaleform::Render::D3D1x::ShaderPair v17; // [rsp+50h] [rbp-38h] BYREF

  result = Scaleform::Render::D3D1x::ShaderInterface::SetStaticShader(psi, ST_start_DrawablePaletteMap, pvf);
  if ( result )
  {
    if ( !psi->PrimitiveOpen )
    {
      psi->PrimitiveOpen = 1;
      *(_QWORD *)psi->UniformSet = 0i64;
      *(_QWORD *)&psi->UniformSet[8] = 0i64;
      *(_QWORD *)&psi->UniformSet[16] = 0i64;
      *(_WORD *)&psi->UniformSet[24] = 0;
      psi->Textures[0] = 0i64;
      psi->Textures[1] = 0i64;
      psi->Textures[2] = 0i64;
      psi->Textures[3] = 0i64;
    }
    v13 = *(_OWORD *)&psi->CurShaders.pVS;
    v14 = *(_OWORD *)&psi->CurShaders.pFS;
    v15 = 1;
    *(_OWORD *)&v17.pVS = v13;
    *(_OWORD *)&v17.pFS = v14;
    v17.pVFormat = psi->CurShaders.pVFormat;
    Scaleform::Render::D3D1x::ShaderInterface::SetTexture(
      psi,
      &v17,
      0x12u,
      paletteMap,
      (Scaleform::Render::ImageFillMode)&v15,
      0);
    v16 = **(Scaleform::Render::Size<int> **)&texsize;
    return Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::DrawableFinish(
             this,
             1u,
             tex,
             texgen);
  }
  return result;
}

// File Line: 1238
// RVA: 0x9FE540
char __fastcall Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::DrawableFinish(
        Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture> *this,
        unsigned int srcCount,
        Scaleform::Render::Texture **tex,
        Scaleform::Render::Matrix2x4<float> *texgen)
{
  float v7; // xmm1_4
  float v8; // xmm9_4
  float v9; // xmm6_4
  float v10; // xmm10_4
  float v11; // xmm11_4
  float v12; // xmm7_4
  unsigned int v13; // xmm0_4
  float v14; // xmm0_4
  unsigned int i; // ebx
  __int128 v16; // xmm0
  __int128 index; // xmm1
  Scaleform::Render::Texture *v18; // r9
  Scaleform::Render::D3D1x::ShaderPair n[2]; // [rsp+18h] [rbp-79h] BYREF
  int *retaddr; // [rsp+F8h] [rbp+67h]
  __int64 v22; // [rsp+100h] [rbp+6Fh]
  Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair> *v23; // [rsp+108h] [rbp+77h]
  int v24; // [rsp+110h] [rbp+7Fh] BYREF

  v7 = *(float *)v22;
  v8 = *(float *)(v22 + 4);
  v9 = *(float *)(v22 + 12);
  v10 = *(float *)(v22 + 16);
  v11 = *(float *)(v22 + 20);
  v12 = *(float *)(v22 + 28);
  LODWORD(n[0].pVDesc) = *(_DWORD *)(v22 + 8);
  v13 = *(_DWORD *)(v22 + 24);
  n[0].pVS = (Scaleform::Render::D3D1x::VertexShader *)__PAIR64__(LODWORD(v8), LODWORD(v7));
  *((float *)&n[0].pVDesc + 1) = v9;
  n[0].pFS = (Scaleform::Render::D3D1x::FragShader *)__PAIR64__(LODWORD(v11), LODWORD(v10));
  n[0].pFDesc = (Scaleform::Render::D3D1x::FragShaderDesc *)__PAIR64__(LODWORD(v12), v13);
  if ( (v24 & 2) != 0 )
  {
    LODWORD(n[0].pFDesc) = 0;
    LODWORD(n[0].pVDesc) = 0;
    *(float *)&n[0].pVS = v7 + (float)(v8 * 0.0);
    *((float *)&n[0].pVS + 1) = (float)(v7 * 0.0) - (float)(v8 * 1.0);
    v9 = (float)(v9 + (float)((float)(v7 * 0.0) + v8)) + (float)((float)(v7 * 0.0) + (float)(v8 * 0.0));
    *(float *)&n[0].pFS = v10 + (float)(v11 * 0.0);
    *((float *)&n[0].pVDesc + 1) = v9;
    v12 = (float)(v12 + (float)((float)(v10 * 0.0) + v11)) + (float)((float)(v10 * 0.0) + (float)(v11 * 0.0));
    *((float *)&n[0].pFS + 1) = (float)(v10 * 0.0) - (float)(v11 * 1.0);
    *((float *)&n[0].pFDesc + 1) = v12;
  }
  if ( (v24 & 1) != 0 )
  {
    v14 = (float)retaddr[1];
    *((float *)&n[0].pVDesc + 1) = v9 + (float)(-1.0 / (float)*retaddr);
    *((float *)&n[0].pFDesc + 1) = v12 + (float)(1.0 / v14);
  }
  Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUniform(
    v23,
    (Scaleform::Render::D3D1x::ShaderPair *)&v23[1].UniformData[2],
    0xDu,
    (const float *)n,
    8u,
    0,
    0);
  for ( i = 0; i < srcCount; ++tex )
  {
    v16 = *(_OWORD *)&v23[1].UniformData[2];
    index = *(_OWORD *)&v23[1].UniformData[6];
    v18 = *tex;
    LOBYTE(v24) = 1;
    *(_OWORD *)&n[0].pVS = v16;
    *(_OWORD *)&n[0].pFS = index;
    n[0].pVFormat = *(Scaleform::Render::VertexFormat **)&v23[1].UniformData[10];
    Scaleform::Render::D3D1x::ShaderInterface::SetTexture(
      (Scaleform::Render::D3D1x::ShaderInterface *)v23,
      n,
      0x14u,
      v18,
      (Scaleform::Render::ImageFillMode)&v24,
      index);
    Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUniform(
      v23,
      (Scaleform::Render::D3D1x::ShaderPair *)&v23[1].UniformData[2],
      0x15u,
      (const float *)texgen++,
      8u,
      2 * i++,
      0);
  }
  Scaleform::Render::D3D1x::ShaderInterface::Finish((Scaleform::Render::D3D1x::ShaderInterface *)v23, 1u);
  return 1;
}

// File Line: 1268
// RVA: 0xA00890
void __fastcall Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::SetBlendFill(
        Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture> *this,
        Scaleform::Render::BlendMode mode,
        Scaleform::Render::Matrix2x4<float> *mvp,
        Scaleform::Render::Cxform *cx,
        Scaleform::Render::Texture **ptextures,
        Scaleform::Render::Matrix2x4<float> *texgen,
        Scaleform::Render::VertexFormat *pvf,
        Scaleform::Render::D3D1x::ShaderInterface *psi)
{
  Scaleform::Render::Texture **v8; // rsi
  unsigned int v10; // r14d
  int v11; // eax
  Scaleform::Render::D3D1x::ShaderDesc::ShaderType v14; // edx
  char v15; // cl
  Scaleform::Render::D3D1x::ShaderInterface *v16; // rbx
  Scaleform::Render::D3D1x::ShaderPair *p_CurShaders; // rdi
  Scaleform::Render::Matrix2x4<float> *v18; // r15
  Scaleform::Render::Texture *v19; // r9
  __int128 v20; // xmm1
  Scaleform::Render::VertexFormat *pVFormat; // xmm0_8
  Scaleform::Render::Texture *v22; // r9
  __int128 v23; // xmm1
  Scaleform::Render::Texture *v24; // r9
  __int128 v25; // xmm1
  Scaleform::Render::VertexFormat *v26; // xmm0_8
  Scaleform::Render::D3D1x::ShaderPair v27; // [rsp+40h] [rbp-58h] BYREF
  char v28; // [rsp+A8h] [rbp+10h] BYREF

  v8 = ptextures;
  v10 = 18;
  v11 = mode - 2;
  v14 = ST_start_base_text;
  switch ( v11 )
  {
    case 0:
      if ( ptextures[2] )
      {
        v14 = ST_BlendLayer;
      }
      else
      {
        if ( !`Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::SetBlendFill::`12::warned )
          `Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::SetBlendFill::`12::warned = ptextures[1] != 0i64;
        v14 = ST_TexTGCxformAc;
        v10 = 20;
      }
      break;
    case 3:
      v14 = ST_start_blends;
      break;
    case 4:
      v14 = ST_BlendDarken;
      break;
    case 5:
      v14 = ST_BlendDifference;
      break;
    case 11:
      v14 = ST_BlendOverlay;
      break;
    case 12:
      v14 = ST_BlendHardlight;
      break;
    default:
      v15 = `Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::SetBlendFill::`5::warned;
      if ( !`Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::SetBlendFill::`5::warned )
        v15 = 1;
      `Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::SetBlendFill::`5::warned = v15;
      break;
  }
  v16 = psi;
  Scaleform::Render::D3D1x::ShaderInterface::SetStaticShader(psi, v14, pvf);
  if ( !v16->PrimitiveOpen )
  {
    v16->PrimitiveOpen = 1;
    *(_QWORD *)v16->UniformSet = 0i64;
    *(_QWORD *)&v16->UniformSet[8] = 0i64;
    *(_QWORD *)&v16->UniformSet[16] = 0i64;
    *(_WORD *)&v16->UniformSet[24] = 0;
    v16->Textures[0] = 0i64;
    v16->Textures[1] = 0i64;
    v16->Textures[2] = 0i64;
    v16->Textures[3] = 0i64;
  }
  p_CurShaders = &v16->CurShaders;
  Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUniform(
    v16,
    &v16->CurShaders,
    0xDu,
    (const float *)mvp,
    8u,
    0,
    0);
  v18 = texgen;
  Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUniform(
    v16,
    &v16->CurShaders,
    0x15u,
    (const float *)texgen,
    8u,
    0,
    0);
  v19 = *v8;
  v20 = *(_OWORD *)&v16->CurShaders.pFS;
  *(_OWORD *)&v27.pVS = *(_OWORD *)&v16->CurShaders.pVS;
  *(_OWORD *)&v27.pFS = v20;
  pVFormat = v16->CurShaders.pVFormat;
  v28 = 1;
  v27.pVFormat = pVFormat;
  Scaleform::Render::D3D1x::ShaderInterface::SetTexture(v16, &v27, v10, v19, (Scaleform::Render::ImageFillMode)&v28, 0);
  if ( v8[1] )
  {
    Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUniform(
      v16,
      &v16->CurShaders,
      0x15u,
      (const float *)&v18[1],
      8u,
      2u,
      0);
    v22 = v8[1];
    v23 = *(_OWORD *)&v16->CurShaders.pFS;
    *(_OWORD *)&v27.pVS = *(_OWORD *)&p_CurShaders->pVS;
    *(_OWORD *)&v27.pFS = v23;
    v27.pVFormat = v16->CurShaders.pVFormat;
    v28 = 1;
    Scaleform::Render::D3D1x::ShaderInterface::SetTexture(v16, &v27, 7u, v22, (Scaleform::Render::ImageFillMode)&v28, 0);
  }
  if ( v8[2] )
  {
    Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUniform(
      v16,
      &v16->CurShaders,
      0x15u,
      (const float *)&v18[2],
      8u,
      2u,
      0);
    v24 = v8[2];
    v25 = *(_OWORD *)&v16->CurShaders.pFS;
    *(_OWORD *)&v27.pVS = *(_OWORD *)&p_CurShaders->pVS;
    *(_OWORD *)&v27.pFS = v25;
    v26 = v16->CurShaders.pVFormat;
    v28 = 1;
    v27.pVFormat = v26;
    Scaleform::Render::D3D1x::ShaderInterface::SetTexture(v16, &v27, 0, v24, (Scaleform::Render::ImageFillMode)&v28, 0);
  }
  if ( mode == Blend_Layer )
    Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetCxform(
      v16,
      &v16->CurShaders,
      cx,
      0,
      0);
  Scaleform::Render::D3D1x::ShaderInterface::Finish(v16, 1u);
}

