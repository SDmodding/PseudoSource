// File Line: 136
// RVA: 0xA02B40
void __fastcall Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUniform0(Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair> *this, Scaleform::Render::D3D1x::ShaderPair *sd, unsigned int var, const float *v, unsigned int n, unsigned int index)
{
  __int64 v6; // rdi
  const float *v7; // r14
  Scaleform::Render::D3D1x::ShaderPair *v8; // rsi
  Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair> *v9; // rbx
  signed __int64 v10; // rbp
  Scaleform::Render::D3D1x::UniformVar *v11; // r10
  Scaleform::Render::D3D1x::UniformVar *v12; // rdx

  v6 = var;
  v7 = v;
  v8 = sd;
  v9 = this;
  v10 = var;
  v11 = sd->pVDesc->Uniforms;
  if ( v11[v10].Size )
    memmove(
      &this->UniformData[v11[v10].ShadowOffset + (unsigned __int64)(index * (unsigned __int8)v11[v10].ElementSize)],
      v,
      4i64 * n);
  v12 = v8->pFDesc->Uniforms;
  if ( v12[v10].Size )
    memmove(
      &v9->UniformData[v12[v10].ShadowOffset + (unsigned __int64)(index * (unsigned __int8)v12[v10].ElementSize)],
      v7,
      4i64 * n);
  v9->UniformSet[v6] = 1;
}

// File Line: 160
// RVA: 0xA02C10
void __fastcall Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUniform(Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair> *this, Scaleform::Render::D3D1x::ShaderPair *sd, unsigned int var, const float *v, unsigned int n, unsigned int index, unsigned int batch)
{
  Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair> *v7; // rdi
  Scaleform::Render::D3D1x::VertexShaderDesc *v8; // rcx
  const float *v9; // rbx
  Scaleform::Render::D3D1x::BatchVar *v10; // r9
  Scaleform::Render::D3D1x::ShaderPair *v11; // r10
  signed __int64 v12; // rdx
  char v13; // r11
  Scaleform::Render::D3D1x::FragShaderDesc *v14; // r9
  Scaleform::Render::D3D1x::BatchVar *v15; // rax
  char v16; // r11

  v7 = this;
  v8 = sd->pVDesc;
  v9 = v;
  v10 = v8->BatchUniforms;
  v11 = sd;
  v12 = var;
  v13 = v10[v12].Offset;
  if ( v13 < 0 )
  {
    v14 = v11->pFDesc;
    v15 = v14->BatchUniforms;
    v16 = v15[v12].Offset;
    if ( v16 < 0 )
      Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUniform0(
        v7,
        v11,
        var,
        v9,
        n,
        index);
    else
      Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUniform0(
        v7,
        v11,
        v15[v12].Array,
        v9,
        n,
        batch * (unsigned __int8)v14->Uniforms[v15[v12].Array].BatchSize + index + v16);
  }
  else
  {
    Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUniform0(
      v7,
      v11,
      v10[v12].Array,
      v9,
      n,
      index + batch * (unsigned __int8)v8->Uniforms[v10[v12].Array].BatchSize + v13);
  }
}

// File Line: 195
// RVA: 0xA01FF0
void __fastcall Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetMatrix(Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair> *this, Scaleform::Render::D3D1x::ShaderPair *sd, unsigned int var, Scaleform::Render::Matrix2x4<float> *m1, Scaleform::Render::MatrixPoolImpl::HMatrix *m2, Scaleform::Render::MatrixState *Matrices, unsigned int index, unsigned int batch)
{
  unsigned int v8; // edi
  Scaleform::Render::D3D1x::ShaderPair *v9; // rsi
  Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair> *v10; // rbp
  Scaleform::Render::MatrixPoolImpl::DataHeader *v11; // r11
  __int64 v12; // rax
  Scaleform::Render::Matrix4x4<float> *v13; // rax
  Scaleform::Render::Matrix3x4<float> v14; // [rsp+40h] [rbp-78h]
  Scaleform::Render::Matrix4x4<float> v15; // [rsp+70h] [rbp-48h]

  v8 = var;
  v9 = sd;
  v10 = this;
  v11 = m2->pHandle->pHeader;
  v12 = v11->Format & 0xF;
  if ( v11->Format & 0x10 )
  {
    Scaleform::Render::Matrix3x4<float>::MultiplyMatrix(
      &v14,
      (Scaleform::Render::Matrix3x4<float> *)&v11[(unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[v12].Offsets[4]
                                                + 1],
      m1);
    v13 = Scaleform::Render::MatrixState::GetUVP(Matrices);
    Scaleform::Render::Matrix4x4<float>::MultiplyMatrix(&v15, v13, &v14);
    Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUniform(
      v10,
      v9,
      v8,
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
      (Scaleform::Render::Matrix2x4<float> *)&v11[(unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[v12].Offsets[4]
                                                + 1],
      &Matrices->UserView);
    Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUniform(
      v10,
      v9,
      v8,
      (const float *)&v14,
      8u,
      2 * index,
      batch);
  }
}

// File Line: 212
// RVA: 0xA00BD0
void __fastcall Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetCxform(Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair> *this, Scaleform::Render::D3D1x::ShaderPair *sd, Scaleform::Render::Cxform *cx, unsigned int index, unsigned int batch)
{
  unsigned int v5; // esi
  Scaleform::Render::Cxform *v6; // rdi
  Scaleform::Render::D3D1x::ShaderPair *v7; // rbp
  Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair> *v8; // r14

  v5 = index;
  v6 = cx;
  v7 = sd;
  v8 = this;
  Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUniform(
    this,
    sd,
    5u,
    (const float *)cx,
    4u,
    index,
    batch);
  Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUniform(
    v8,
    v7,
    4u,
    v6->M[1],
    4u,
    v5,
    batch);
}

// File Line: 221
// RVA: 0x9FF050
__int64 __fastcall Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::GetUniformSize(Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair> *this, Scaleform::Render::D3D1x::ShaderPair *sd, unsigned int i)
{
  Scaleform::Render::D3D1x::VertexShaderDesc *v3; // r9
  signed __int64 v4; // rcx
  Scaleform::Render::D3D1x::BatchVar *v5; // rax
  signed __int64 v6; // r10
  signed __int64 v7; // r8
  char v8; // al
  signed __int64 v10; // rcx
  Scaleform::Render::D3D1x::UniformVar *v11; // rax
  Scaleform::Render::D3D1x::FragShaderDesc *v12; // rdx
  Scaleform::Render::D3D1x::BatchVar *v13; // rax
  signed __int64 v14; // r8
  char v15; // al

  v3 = sd->pVDesc;
  v4 = i;
  v5 = v3->BatchUniforms;
  v6 = i;
  v7 = (signed __int64)&v5[v6];
  v8 = v5[v6].Array;
  if ( v8 <= 25 )
    return (unsigned __int8)v3->Uniforms[v8].ElementSize * (unsigned int)*(unsigned __int8 *)(v7 + 2);
  v10 = v4;
  v11 = v3->Uniforms;
  if ( v11[v10].Location >= 0 )
    return (unsigned int)v11[v10].Size;
  v12 = sd->pFDesc;
  v13 = v12->BatchUniforms;
  v14 = (signed __int64)&v13[v6];
  v15 = v13[v6].Array;
  if ( v15 <= 25 )
    return (unsigned __int8)v12->Uniforms[v15].ElementSize * (unsigned int)*(unsigned __int8 *)(v14 + 2);
  v11 = v12->Uniforms;
  if ( v11[v10].Location >= 0 )
    return (unsigned int)v11[v10].Size;
  return 0i64;
}

// File Line: 240
// RVA: 0xA02CF0
void __fastcall Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUserUniforms(Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair> *this, Scaleform::Render::D3D1x::ShaderPair *sd, Scaleform::Render::MatrixPoolImpl::HMatrix *m, int batch)
{
  Scaleform::Render::D3D1x::ShaderPair *v4; // r12
  Scaleform::Render::MatrixPoolImpl::DataHeader *v5; // rdx
  int v6; // er13
  Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair> *v7; // r15
  signed __int64 v8; // rsi
  signed int v9; // ebx
  char *v10; // r14
  char v11; // bp
  unsigned int v12; // eax
  __int64 n; // rdi
  Scaleform::Render::Texture *v14; // rcx
  const float *v15; // r9
  signed int v16; // eax
  float v17; // [rsp+40h] [rbp-48h]
  float v18; // [rsp+44h] [rbp-44h]
  int v19; // [rsp+48h] [rbp-40h]
  int v20; // [rsp+4Ch] [rbp-3Ch]

  v4 = sd;
  v5 = m->pHandle->pHeader;
  v6 = batch;
  v7 = this;
  if ( v5->Format & 8 )
    v8 = (signed __int64)&v5[(unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[v5->Format & 0xF].Offsets[3]
                           + 1];
  else
    v8 = 0i64;
  v9 = 0;
  v10 = Scaleform::Render::D3D1x::Uniform::UniformFlags;
  do
  {
    v11 = *v10;
    if ( !(*v10 & 1) )
    {
      v12 = Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::GetUniformSize(
              v7,
              v4,
              v9);
      n = v12;
      if ( v12 )
      {
        if ( v11 & 2 && (unsigned int)n <= 4 && (v14 = v7->Textures[0]) != 0i64 )
        {
          v15 = &v17;
          v16 = v14->ImgSize.Height;
          v17 = (float)(1.0 / (float)(signed int)v14->ImgSize.Width) * *(float *)v8;
          v19 = *(_DWORD *)(v8 + 8);
          v18 = (float)(1.0 / (float)v16) * *(float *)(v8 + 4);
          v20 = *(_DWORD *)(v8 + 12);
        }
        else
        {
          v15 = (const float *)v8;
        }
        Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUniform(
          v7,
          v4,
          v9,
          v15,
          n,
          0,
          v6);
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
void __fastcall Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::~StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>(Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture> *this)
{
  Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture> *v1; // rbx

  v1 = this;
  this->vfptr = (Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>Vtbl *)&Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::`vftable';
  Scaleform::HashSet<Scaleform::HashNode<Scaleform::Render::SourceFormatHash,Scaleform::Render::ResultFormat,Scaleform::FixedSizeHash<Scaleform::Render::SourceFormatHash>>,Scaleform::HashNode<Scaleform::Render::SourceFormatHash,Scaleform::Render::ResultFormat,Scaleform::FixedSizeHash<Scaleform::Render::SourceFormatHash>>::NodeHashF,Scaleform::HashNode<Scaleform::Render::SourceFormatHash,Scaleform::Render::ResultFormat,Scaleform::FixedSizeHash<Scaleform::Render::SourceFormatHash>>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Render::SourceFormatHash,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::Render::SourceFormatHash,Scaleform::Render::ResultFormat,Scaleform::FixedSizeHash<Scaleform::Render::SourceFormatHash>>,Scaleform::HashNode<Scaleform::Render::SourceFormatHash,Scaleform::Render::ResultFormat,Scaleform::FixedSizeHash<Scaleform::Render::SourceFormatHash>>::NodeHashF>>::~HashSet<Scaleform::HashNode<Scaleform::Render::SourceFormatHash,Scaleform::Render::ResultFormat,Scaleform::FixedSizeHash<Scaleform::Render::SourceFormatHash>>,Scaleform::HashNode<Scaleform::Render::SourceFormatHash,Scaleform::Render::ResultFormat,Scaleform::FixedSizeHash<Scaleform::Render::SourceFormatHash>>::NodeHashF,Scaleform::HashNode<Scaleform::Render::SourceFormatHash,Scaleform::Render::ResultFormat,Scaleform::FixedSizeHash<Scaleform::Render::SourceFormatHash>>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Render::SourceFormatHash,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::Render::SourceFormatHash,Scaleform::Render::ResultFormat,Scaleform::FixedSizeHash<Scaleform::Render::SourceFormatHash>>,Scaleform::HashNode<Scaleform::Render::SourceFormatHash,Scaleform::Render::ResultFormat,Scaleform::FixedSizeHash<Scaleform::Render::SourceFormatHash>>::NodeHashF>>(&this->VertexFormatComputedHash.mHash);
  v1 = (Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture> *)((char *)v1 + 8);
  Scaleform::Render::PagedItemBuffer<Scaleform::Render::MultiKeyCollection<Scaleform::Render::VertexElement,Scaleform::Render::VertexFormat,32,8>::ValueItem,8>::freePages(
    (Scaleform::Render::PagedItemBuffer<Scaleform::Render::MultiKeyCollection<Scaleform::Render::VertexElement,Scaleform::Render::VertexFormat,32,8>::ValueItem,8> *)&v1->VFormats.KeyBuffer.pLast,
    0);
  Scaleform::Render::PagedItemBuffer<Scaleform::Render::VertexElement,32>::~PagedItemBuffer<Scaleform::Render::VertexElement,32>((Scaleform::Render::PagedItemBuffer<Scaleform::Render::ContextImpl::EntryChange,63> *)v1);
}

// File Line: 339
// RVA: 0xA03080
signed int __fastcall Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::StaticShaderForFill(Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture> *this, Scaleform::Render::PrimitiveFill *pfill, unsigned int *fillflags, unsigned int batchType)
{
  Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture> *v4; // r14
  Scaleform::Render::PrimitiveFill *v5; // rbx
  unsigned int v6; // edi
  unsigned int *v7; // rsi
  Scaleform::Render::PrimitiveFillType v8; // ebp
  signed int v9; // edx
  int v10; // eax
  int v11; // eax
  signed int v12; // ecx
  unsigned int v13; // edx
  int v14; // edi

  v4 = this;
  v5 = pfill;
  v6 = batchType;
  v7 = fillflags;
  v8 = (unsigned int)this->Profiler->vfptr->GetFillType(this->Profiler, pfill->Data.Type);
  if ( (unsigned int)(v8 - 5) > 1 )
    return Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::StaticShaderForFill(
             v4,
             v8,
             v7,
             v6);
  v9 = v5->Data.Type;
  if ( (unsigned int)(v9 - 5) > 3 && v9 < 11 )
    return Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::StaticShaderForFill(
             v4,
             v8,
             v7,
             v6);
  if ( ((signed int (*)(void))v5->Data.Textures[0].pObject->vfptr[4].__vecDelDtor)() < 200
    || ((signed int (*)(void))v5->Data.Textures[0].pObject->vfptr[4].__vecDelDtor)() > 202 )
  {
    return Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::StaticShaderForFill(
             v4,
             v8,
             v7,
             v6);
  }
  v10 = (unsigned __int64)((__int64 (*)(void))v5->Data.Textures[0].pObject->vfptr[4].__vecDelDtor)() - 200;
  if ( v10 )
  {
    v11 = v10 - 1;
    if ( !v11 )
    {
      if ( !`Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::StaticShaderForFill'::`14'::warned )
        `Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::StaticShaderForFill'::`14'::warned = (unsigned int)Scaleform::Render::Texture::GetPlaneCount(v5->Data.Textures[0].pObject) != 4;
      v12 = 270336;
      goto LABEL_18;
    }
    if ( v11 == 1 )
    {
      if ( !`Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::StaticShaderForFill'::`18'::warned )
        `Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::StaticShaderForFill'::`18'::warned = (unsigned int)Scaleform::Render::Texture::GetPlaneCount(v5->Data.Textures[0].pObject) != 1;
      v12 = 278528;
      goto LABEL_18;
    }
  }
  else if ( !`Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::StaticShaderForFill'::`10'::warned )
  {
    `Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::StaticShaderForFill'::`10'::warned = (unsigned int)Scaleform::Render::Texture::GetPlaneCount(v5->Data.Textures[0].pObject) != 3;
  }
  v12 = 0x40000;
LABEL_18:
  if ( v8 == 6 )
    v12 += 32;
  if ( v12 != 133120 )
  {
    v13 = *v7;
    if ( (*(_BYTE *)v7 & 0xC) == 12 )
    {
      v12 += 256;
    }
    else if ( v13 & 8 )
    {
      v12 += 16;
    }
  }
  v14 = v6 - 1;
  if ( v14 )
  {
    if ( v14 == 1 )
      v12 += 4;
  }
  else
  {
    v12 += 2;
  }
  if ( *v7 & 1 )
    ++v12;
  if ( *v7 & 0x10 )
    v12 += 8;
  return v12;
}

// File Line: 414
// RVA: 0xA03200
__int64 __fastcall Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::StaticShaderForFill(Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture> *this, Scaleform::Render::PrimitiveFillType fill, unsigned int *fillflags, unsigned int batchType)
{
  unsigned int v4; // ecx
  unsigned int v5; // er9
  unsigned int v6; // eax
  bool v7; // zf
  __int64 result; // rax

  switch ( 0x40000000 )
  {
    case 0:
      v4 = 65537;
      goto LABEL_13;
    case 1:
      v4 = 65569;
      goto LABEL_13;
    case 2:
      v4 = 1;
      goto LABEL_13;
    case 3:
      v4 = 33;
      goto LABEL_13;
    case 4:
      v4 = 1025;
      goto LABEL_13;
    case 5:
      v4 = 1057;
      goto LABEL_13;
    case 6:
      v4 = 513;
      goto LABEL_13;
    case 7:
      v4 = 545;
      goto LABEL_13;
    case 8:
      v4 = 135168;
      goto LABEL_13;
    case 9:
      *fillflags |= 8u;
      v4 = 133120;
      break;
    default:
      *fillflags &= 0xFFFFFFF7;
      v4 = 0x20000;
LABEL_13:
      if ( (*(_BYTE *)fillflags & 0xC) == 12 )
      {
        v4 += 256;
      }
      else if ( *fillflags & 8 )
      {
        v4 += 16;
      }
      break;
  }
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
  if ( *fillflags & 1 )
    ++v4;
  if ( v6 & 2 )
    v4 += 64;
  v7 = (v6 & 0x10) == 0;
  result = v4 + 8;
  if ( v7 )
    result = v4;
  return result;
}

// File Line: 542
// RVA: 0xA09B50
void __fastcall Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::MapVertexFormat(Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture> *this, __int64 fill, Scaleform::Render::VertexFormat *sourceFormat, Scaleform::Render::VertexFormat **single, Scaleform::Render::VertexFormat **batch, Scaleform::Render::VertexFormat **instanced, unsigned int flags)
{
  Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture> *v7; // rdi
  Scaleform::Render::VertexFormat **v8; // r13
  Scaleform::Render::VertexFormat *v9; // r14
  Scaleform::Render::PrimitiveFillType v10; // eax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::Render::SourceFormatHash,Scaleform::Render::ResultFormat,Scaleform::FixedSizeHash<Scaleform::Render::SourceFormatHash> >,Scaleform::HashNode<Scaleform::Render::SourceFormatHash,Scaleform::Render::ResultFormat,Scaleform::FixedSizeHash<Scaleform::Render::SourceFormatHash> >::NodeHashF,Scaleform::HashNode<Scaleform::Render::SourceFormatHash,Scaleform::Render::ResultFormat,Scaleform::FixedSizeHash<Scaleform::Render::SourceFormatHash> >::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Render::SourceFormatHash,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::Render::SourceFormatHash,Scaleform::Render::ResultFormat,Scaleform::FixedSizeHash<Scaleform::Render::SourceFormatHash> >,Scaleform::HashNode<Scaleform::Render::SourceFormatHash,Scaleform::Render::ResultFormat,Scaleform::FixedSizeHash<Scaleform::Render::SourceFormatHash> >::NodeHashF> >::TableType *v11; // r9
  char v12; // r15
  Scaleform::Render::PrimitiveFillType v13; // er10
  signed __int64 v14; // rdx
  signed __int64 v15; // rcx
  __int64 v16; // rax
  signed __int64 v17; // rax
  signed __int64 v18; // r8
  signed __int64 v19; // rdx
  signed __int64 v20; // rcx
  signed __int64 v21; // rcx
  Scaleform::Render::VertexFormat *v22; // rdx
  Scaleform::Render::VertexFormat *v23; // rcx
  signed __int64 v24; // rdx
  unsigned int v25; // esi
  Scaleform::Render::D3D1x::ShaderDesc::ShaderType v26; // ebx
  Scaleform::Render::D3D1x::ShaderDesc::ShaderVersion v27; // eax
  Scaleform::Render::D3D1x::VertexShaderDesc *v28; // rax
  Scaleform::Render::D3D1x::VertexShaderDesc *v29; // r12
  Scaleform::Render::VertexFormat **v30; // rax
  int v31; // er13
  unsigned int v32; // ebx
  signed int v33; // er9
  int v34; // edi
  signed int v35; // er11
  Scaleform::Render::VertexElement *v36; // rdx
  $3C54659889F1EB765F9D24AEEC355797 *v37; // r8
  unsigned int *v38; // r10
  int v39; // edi
  $3C54659889F1EB765F9D24AEEC355797 *v40; // r8
  Scaleform::Render::VertexElement *v41; // rdx
  Scaleform::Render::VertexElement *v42; // rcx
  unsigned int v43; // eax
  unsigned int v44; // er9
  int v45; // eax
  unsigned int v46; // er9
  unsigned int v47; // ecx
  Scaleform::Render::VertexElement *v48; // rsi
  Scaleform::Render::MultiKeyCollection<Scaleform::Render::VertexElement,Scaleform::Render::VertexFormat,32,8> *v49; // rsi
  Scaleform::Render::VertexFormat *v50; // rdx
  unsigned int v51; // ecx
  Scaleform::Render::VertexFormat *v52; // rdx
  Scaleform::Render::VertexFormat **v53; // r14
  unsigned int v54; // ecx
  signed __int64 v55; // rdx
  signed __int64 v56; // rcx
  __int64 v57; // rax
  int v58; // eax
  Scaleform::Render::VertexFormat *v59; // rdx
  Scaleform::Render::VertexFormat **v60; // rcx
  unsigned int v61; // ecx
  Scaleform::Render::VertexElement keys; // [rsp+20h] [rbp-81h]
  __int64 v63; // [rsp+28h] [rbp-79h]
  __int64 v64[6]; // [rsp+30h] [rbp-71h]
  Scaleform::Render::VertexElement *ppnewKeys; // [rsp+60h] [rbp-41h]
  __int128 *v66; // [rsp+68h] [rbp-39h]
  Scaleform::Render::PrimitiveFillType v67; // [rsp+70h] [rbp-31h]
  unsigned int v68; // [rsp+74h] [rbp-2Dh]
  Scaleform::Render::VertexFormat *v69; // [rsp+78h] [rbp-29h]
  __int128 v70; // [rsp+80h] [rbp-21h]
  Scaleform::Render::VertexFormat *v71; // [rsp+90h] [rbp-11h]
  void *pmemAddr; // [rsp+98h] [rbp-9h]
  Scaleform::Render::VertexElement *v73; // [rsp+F0h] [rbp+4Fh]
  unsigned int v74; // [rsp+F8h] [rbp+57h]
  int v75; // [rsp+100h] [rbp+5Fh]
  Scaleform::Render::VertexFormat **v76; // [rsp+108h] [rbp+67h]

  v76 = single;
  v73 = (Scaleform::Render::VertexElement *)this;
  v7 = this;
  v8 = single;
  v9 = sourceFormat;
  v10 = (unsigned int)this->Profiler->vfptr->GetFillType(this->Profiler, (Scaleform::Render::PrimitiveFillType)fill);
  v11 = v7->VertexFormatComputedHash.mHash.pTable;
  v12 = flags;
  v13 = v10;
  v67 = v10;
  v68 = flags;
  v69 = v9;
  pmemAddr = &v7->VertexFormatComputedHash;
  if ( v11 )
  {
    v14 = 16i64;
    v15 = 5381i64;
    do
    {
      v16 = *((unsigned __int8 *)&v66 + v14-- + 7);
      v17 = 65599 * v15 + v16;
      v15 = v17;
    }
    while ( v14 );
    v18 = v17 & v11->SizeMask;
    v19 = v18;
    v20 = (signed __int64)&v11[1] + 56 * v18;
    if ( *(_QWORD *)v20 != -2i64 && *(_QWORD *)(v20 + 8) == v18 )
    {
      while ( *(_QWORD *)(v20 + 8) != v18
           || v13 != *(_DWORD *)(v20 + 16)
           || v9 != *(Scaleform::Render::VertexFormat **)(v20 + 24)
           || flags != *(_DWORD *)(v20 + 20) )
      {
        v19 = *(_QWORD *)v20;
        if ( *(_QWORD *)v20 == -1i64 )
          goto LABEL_15;
        v20 = (signed __int64)&v11[1] + 56 * v19;
      }
      if ( v19 >= 0 )
      {
        v21 = (signed __int64)&v11[2] + 56 * v19;
        if ( v21 )
        {
          v70 = *(_OWORD *)(v21 + 16);
          v22 = (Scaleform::Render::VertexFormat *)*((_QWORD *)&v70 + 1);
          v23 = *(Scaleform::Render::VertexFormat **)(v21 + 32);
          *v8 = (Scaleform::Render::VertexFormat *)v70;
          *batch = v22;
          *instanced = v23;
          return;
        }
      }
    }
  }
LABEL_15:
  v24 = 0i64;
  v25 = 1;
  switch ( v13 )
  {
    case 3:
      v26 = 65537;
      break;
    case 4:
      v26 = 65569;
      break;
    case 5:
      v26 = 1;
      break;
    case 6:
      v26 = 33;
      break;
    case 7:
      v26 = 1025;
      break;
    case 8:
      v26 = 1057;
      break;
    case 9:
      v26 = 513;
      break;
    case 10:
      v26 = 545;
      break;
    case 11:
      v26 = 135168;
      break;
    case 12:
      v26 = 133120;
      v24 = 8i64;
      break;
    default:
      v26 = 0x20000;
      break;
  }
  if ( v24 & 1 )
    ++v26;
  if ( v24 & 2 )
    v26 += 64;
  if ( v24 & 0x10 )
    v26 += 8;
  v27 = ((unsigned int (__fastcall *)(Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture> *, signed __int64, signed __int64))v7->vfptr->GetShaderVersion)(
          v7,
          v24,
          5368709120i64);
  v28 = Scaleform::Render::D3D1x::VertexShaderDesc::GetDesc(v26, v27);
  v29 = v28;
  if ( !v28 )
  {
    *instanced = 0i64;
    v30 = batch;
    *v8 = 0i64;
    *v30 = 0i64;
    return;
  }
  v31 = -1;
  v32 = 0;
  v33 = 4;
  v34 = 0;
  v35 = 0;
  v74 = 4;
  v75 = -1;
  if ( v28->NumAttribs > 0 )
  {
    v36 = &keys;
    v37 = &keys.4;
    v38 = &v28->Attributes[0].Attr;
    while ( (*v38 & 0xFF0F) == 4612 )
    {
      v39 = v34 + 1;
      v36->Offset = v32;
      v75 = v39;
      if ( v12 & 0x20 )
      {
        v37->Attribute = 4625;
        v40 = v37 + 2;
        v31 = v32 + 1;
        v40->Attribute = 8721;
      }
      else
      {
        v37->Attribute = 8721;
        v40 = v37 + 2;
        v31 = v32 + 2;
        v40->Attribute = 4625;
      }
      v33 = v74;
      v41 = v36 + 1;
      v34 = v39 + 1;
      v41->Offset = v32 + 3;
      v36 = v41 + 1;
      v37 = v40 + 2;
      v32 += 4;
LABEL_57:
      ++v35;
      v38 += 8;
      if ( v35 >= v29->NumAttribs )
        goto LABEL_58;
    }
    v42 = v9->pElements;
    v43 = v42->Attribute;
    if ( !v43 )
    {
LABEL_45:
      *instanced = 0i64;
      *v76 = 0i64;
      *batch = 0i64;
      return;
    }
    while ( (v43 & 0xFF00) != (*v38 & 0xFF00) )
    {
      v43 = v42[1].Attribute;
      ++v42;
      if ( !v43 )
        goto LABEL_45;
    }
    *v36 = *v42;
    v36->Offset = v32;
    v44 = v42->Attribute;
    v45 = v42->Attribute & 0xFFF;
    if ( v12 & 4 )
    {
      if ( v45 == 532 )
      {
        v46 = v44 & 0xFFFFF251 | 0x251;
LABEL_51:
        v37->Attribute = v46;
        goto LABEL_52;
      }
    }
    else if ( v45 == 593 )
    {
      v46 = v44 & 0xFFFFF214 | 0x214;
      goto LABEL_51;
    }
LABEL_52:
    v47 = VertexTypeSizes_44[((unsigned __int8)v42->Attribute >> 4) - 1];
    if ( v47 < v74 )
      v47 = v74;
    v33 = v47;
    v74 = v47;
    v12 = flags;
    v32 += (v36->Attribute & 0xF) * VertexTypeSizes_44[((unsigned __int8)v36->Attribute >> 4) - 1];
    if ( flags & 2 )
      v32 = (v32 + 3) & 0xFFFFFFFC;
    ++v34;
    v37 += 2;
    ++v36;
    goto LABEL_57;
  }
LABEL_58:
  if ( v12 & 1 )
    v25 = v33;
  flags = v25;
  v48 = v73;
  *((_QWORD *)&keys + v34) = 0i64;
  v49 = (Scaleform::Render::MultiKeyCollection<Scaleform::Render::VertexElement,Scaleform::Render::VertexFormat,32,8> *)&v48[1];
  ppnewKeys = &keys;
  v50 = Scaleform::Render::MultiKeyCollection<Scaleform::Render::VertexElement,Scaleform::Render::VertexFormat,32,8>::Find(
          v49,
          &keys,
          v34 + 1);
  if ( !v50 )
  {
    v50 = Scaleform::Render::MultiKeyCollection<Scaleform::Render::VertexElement,Scaleform::Render::VertexFormat,32,8>::Add(
            v49,
            &ppnewKeys,
            &keys,
            v34 + 1);
    if ( v50 )
    {
      v51 = ~(flags - 1) & (v32 + flags - 1);
      v50->pElements = ppnewKeys;
      v50->Size = v51;
    }
    else
    {
      v50 = 0i64;
    }
  }
  *v76 = v50;
  if ( v12 & 8 )
  {
    *(&keys.Offset + 2 * v34) = 0;
    *(&keys.Attribute + 2 * v34) = 66673;
    v73 = &keys;
    *(&v63 + v34) = 0i64;
    v52 = Scaleform::Render::MultiKeyCollection<Scaleform::Render::VertexElement,Scaleform::Render::VertexFormat,32,8>::Find(
            v49,
            &keys,
            v34 + 2);
    if ( !v52 )
    {
      v52 = Scaleform::Render::MultiKeyCollection<Scaleform::Render::VertexElement,Scaleform::Render::VertexFormat,32,8>::Add(
              v49,
              &v73,
              &keys,
              v34 + 2);
      if ( !v52 )
      {
        v53 = instanced;
        *instanced = 0i64;
        goto LABEL_71;
      }
      v54 = ~(flags - 1) & (v32 + flags - 1);
      v52->pElements = v73;
      v52->Size = v54;
    }
    v53 = instanced;
    *instanced = v52;
  }
  else
  {
    v53 = instanced;
    *instanced = 0i64;
  }
LABEL_71:
  if ( v12 & 0x10 )
  {
    v60 = batch;
    *batch = 0i64;
    goto LABEL_86;
  }
  if ( v31 < 0 )
  {
    *(&keys.Attribute + 2 * v34) = 66593;
    v58 = v32;
    if ( v12 & 0x20 )
      v58 = v32 + 3;
    *(&keys.Offset + 2 * v34) = v58;
    v32 += (*(&keys.Attribute + 2 * v34) & 0xF)
         * VertexTypeSizes_44[((unsigned __int8)*(&keys.Attribute + 2 * v34) >> 4) - 1];
    if ( v12 & 2 )
      v32 = (v32 + 3) & 0xFFFFFFFC;
  }
  else
  {
    v55 = v75;
    v56 = v34 - 1;
    if ( v56 >= v75 )
    {
      do
      {
        v57 = *((_QWORD *)&keys + v56--);
        v64[v56] = v57;
      }
      while ( v56 >= v55 );
    }
    *(&keys.Attribute + 2 * v55) = 66593;
    *(&keys.Offset + 2 * v55) = v31;
  }
  *(&v63 + v34) = 0i64;
  v73 = &keys;
  v59 = Scaleform::Render::MultiKeyCollection<Scaleform::Render::VertexElement,Scaleform::Render::VertexFormat,32,8>::Find(
          v49,
          &keys,
          v34 + 2);
  if ( v59 )
    goto LABEL_84;
  v59 = Scaleform::Render::MultiKeyCollection<Scaleform::Render::VertexElement,Scaleform::Render::VertexFormat,32,8>::Add(
          v49,
          &v73,
          &keys,
          v34 + 2);
  if ( v59 )
  {
    v61 = ~(flags - 1) & (v32 + flags - 1);
    v59->pElements = v73;
    v59->Size = v61;
LABEL_84:
    v60 = batch;
    *batch = v59;
    goto LABEL_86;
  }
  v60 = batch;
  *batch = 0i64;
LABEL_86:
  *(_QWORD *)&v70 = *v76;
  *((_QWORD *)&v70 + 1) = *v60;
  v71 = *v53;
  ppnewKeys = (Scaleform::Render::VertexElement *)&v67;
  v66 = &v70;
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::Render::SourceFormatHash,Scaleform::Render::ResultFormat,Scaleform::FixedSizeHash<Scaleform::Render::SourceFormatHash>>,Scaleform::HashNode<Scaleform::Render::SourceFormatHash,Scaleform::Render::ResultFormat,Scaleform::FixedSizeHash<Scaleform::Render::SourceFormatHash>>::NodeHashF,Scaleform::HashNode<Scaleform::Render::SourceFormatHash,Scaleform::Render::ResultFormat,Scaleform::FixedSizeHash<Scaleform::Render::SourceFormatHash>>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Render::SourceFormatHash,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::Render::SourceFormatHash,Scaleform::Render::ResultFormat,Scaleform::FixedSizeHash<Scaleform::Render::SourceFormatHash>>,Scaleform::HashNode<Scaleform::Render::SourceFormatHash,Scaleform::Render::ResultFormat,Scaleform::FixedSizeHash<Scaleform::Render::SourceFormatHash>>::NodeHashF>>::Set<Scaleform::HashNode<Scaleform::Render::SourceFormatHash,Scaleform::Render::ResultFormat,Scaleform::FixedSizeHash<Scaleform::Render::SourceFormatHash>>::NodeRef>(
    (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::Render::SourceFormatHash,Scaleform::Render::ResultFormat,Scaleform::FixedSizeHash<Scaleform::Render::SourceFormatHash> >,Scaleform::HashNode<Scaleform::Render::SourceFormatHash,Scaleform::Render::ResultFormat,Scaleform::FixedSizeHash<Scaleform::Render::SourceFormatHash> >::NodeHashF,Scaleform::HashNode<Scaleform::Render::SourceFormatHash,Scaleform::Render::ResultFormat,Scaleform::FixedSizeHash<Scaleform::Render::SourceFormatHash> >::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Render::SourceFormatHash,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::Render::SourceFormatHash,Scaleform::Render::ResultFormat,Scaleform::FixedSizeHash<Scaleform::Render::SourceFormatHash> >,Scaleform::HashNode<Scaleform::Render::SourceFormatHash,Scaleform::Render::ResultFormat,Scaleform::FixedSizeHash<Scaleform::Render::SourceFormatHash> >::NodeHashF> > *)pmemAddr,
    pmemAddr,
    (Scaleform::HashNode<Scaleform::Render::SourceFormatHash,Scaleform::Render::ResultFormat,Scaleform::FixedSizeHash<Scaleform::Render::SourceFormatHash> >::NodeRef *)&ppnewKeys);
}

// File Line: 695
// RVA: 0xA02130
Scaleform::Render::D3D1x::ShaderPair *__fastcall Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::SetPrimitiveFill(Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture> *this, Scaleform::Render::PrimitiveFill *pfill, unsigned int *fillFlags, unsigned int batchType)
{
  Scaleform::Render::PrimitiveFill *v4; // r14
  unsigned int v5; // esi
  unsigned int *v6; // rdi
  __int64 v7; // r15
  unsigned int v8; // er13
  unsigned int v9; // ebx
  Scaleform::Render::MatrixPoolImpl::HMatrix *v10; // rdi
  Scaleform::Render::MatrixPoolImpl::DataHeader *v11; // rdx
  Scaleform::Render::Cxform *v12; // r8
  float v13; // xmm0_4
  unsigned int v14; // er9
  Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture> *v15; // rsi
  Scaleform::Render::D3D1x::ShaderDesc::ShaderType v16; // ebx
  Scaleform::Render::D3D1x::ShaderInterface *v17; // rdi
  Scaleform::Render::D3D1x::ShaderPair *v18; // rsi
  unsigned __int8 *v19; // rax
  __m128i v20; // xmm2
  Scaleform::Render::D3D1x::VertexShaderDesc *v21; // rcx
  __m128i v22; // xmm3
  float v23; // xmm0_4
  float v24; // xmm1_4
  Scaleform::Render::D3D1x::BatchVar *v25; // rax
  float v26; // xmm1_4
  char v27; // dl
  float v28; // xmm2_4
  float v29; // xmm3_4
  __int64 v30; // rax
  int v31; // er10
  Scaleform::Render::D3D1x::BatchVar *v32; // rdx
  char v33; // al
  Scaleform::Render::D3D1x::UniformVar *v34; // r8
  unsigned __int64 v35; // rcx
  Scaleform::Render::D3D1x::UniformVar *v36; // r8
  unsigned __int64 v37; // rcx
  Scaleform::Render::D3D1x::UniformVar *v38; // rax
  __int64 v39; // rax
  Scaleform::Render::D3D1x::UniformVar *v40; // rcx
  __int64 v41; // rax
  __int128 v42; // xmm0
  __int128 v43; // xmm1
  Scaleform::Render::Texture *v44; // rbx
  __int128 v45; // xmm0
  __int128 v46; // xmm1
  Scaleform::Render::Texture *v47; // r9
  unsigned int v48; // eax
  unsigned int v49; // ebx
  Scaleform::Render::MatrixPoolImpl::HMatrix *v50; // r14
  Scaleform::Render::D3D1x::VertexShaderDesc *v51; // rcx
  Scaleform::Render::D3D1x::BatchVar *v52; // rax
  unsigned __int8 v53; // dl
  int v54; // er12
  Scaleform::Render::D3D1x::UniformVar *v55; // rax
  __int16 v56; // dx
  Scaleform::Render::D3D1x::FragShaderDesc *v57; // rdx
  Scaleform::Render::D3D1x::BatchVar *v58; // rcx
  unsigned __int8 v59; // r8
  Scaleform::Render::D3D1x::UniformVar *v60; // rcx
  __int16 v61; // dx
  unsigned int v62; // er13
  __int64 v63; // r14
  unsigned int v64; // er12
  signed __int64 v65; // rbx
  Scaleform::Render::MatrixPoolImpl::HMatrix *v66; // rax
  Scaleform::Render::ProfileViews *v67; // rcx
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
  int v80; // er10
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
  __int64 v91; // rdx
  Scaleform::Render::Cxform *v92; // r8
  Scaleform::Render::Cxform *v93; // rbx
  unsigned int v94; // ebx
  signed int v95; // er15
  signed __int64 v96; // r14
  signed __int64 v97; // rax
  float v98; // xmm1_4
  Scaleform::Render::MatrixPoolImpl::EntryHandle *v99; // rax
  Scaleform::Render::Matrix2x4<float> *v100; // rdx
  Scaleform::Render::MatrixPoolImpl::HMatrix *v102; // [rsp+8h] [rbp-49h]
  __int64 v103; // [rsp+10h] [rbp-41h]
  Scaleform::Render::Cxform v104; // [rsp+18h] [rbp-39h]
  unsigned int batch[2]; // [rsp+38h] [rbp-19h]
  Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture> *v106; // [rsp+98h] [rbp+47h]
  char v107; // [rsp+A0h] [rbp+4Fh]
  unsigned int *v108; // [rsp+A8h] [rbp+57h]
  Scaleform::Render::VertexFormat *pformat; // [rsp+B8h] [rbp+67h]
  unsigned int vars0; // [rsp+C0h] [rbp+6Fh]
  Scaleform::Render::MatrixState *retaddr; // [rsp+C8h] [rbp+77h]
  Scaleform::Render::MatrixPoolImpl::HMatrix *m; // [rsp+D0h] [rbp+7Fh]
  Scaleform::Render::D3D1x::ShaderInterface *v113; // [rsp+D8h] [rbp+87h]
  unsigned int *v114; // [rsp+E0h] [rbp+8Fh]

  v114 = fillFlags;
  m = (Scaleform::Render::MatrixPoolImpl::HMatrix *)this;
  v4 = pfill;
  v5 = batchType;
  v6 = fillFlags;
  v7 = this->Profiler->vfptr->GetFillType(this->Profiler, pfill->Data.Type);
  if ( !(*(_BYTE *)v6 & 0x20) && Scaleform::Render::PrimitiveFillData::RequiresBlend(&v4->Data) )
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
        v11 = v10->pHandle->pHeader;
        v12 = (Scaleform::Render::Cxform *)(v11->Format & 1 ? &v11[(unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[v11->Format & 0xF].Offsets[0]
                                                                 + 1] : &Scaleform::Render::Cxform::Identity);
        v106->Profiler->vfptr->GetCxform(v106->Profiler, &v104, v12);
        if ( Scaleform::Render::Cxform::operator!=(&v104, &Scaleform::Render::Cxform::Identity) )
          break;
        ++v9;
        v10 += 2;
        if ( v9 >= v8 )
        {
          v6 = v108;
          goto LABEL_15;
        }
      }
      v6 = v108;
      v13 = v104.M[0][3];
      *v6 |= 8u;
      if ( v13 < 1.0 )
        *v6 |= 0x20u;
    }
  }
LABEL_15:
  v14 = v5;
  v15 = v106;
  v16 = Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::StaticShaderForFill(
          v106,
          v4,
          v6,
          v14);
  v15->Profiler->vfptr->SetFillFlags(v15->Profiler, *v6);
  v17 = v113;
  Scaleform::Render::D3D1x::ShaderInterface::SetStaticShader(v113, v16, pformat);
  v18 = &v17->CurShaders;
  if ( Scaleform::Render::PrimitiveFill::IsSolid((Scaleform::Render::PrimitiveFillType)v7) )
  {
    LODWORD(v113) = v4->Data.SolidColor.Raw;
    v19 = (unsigned __int8 *)((__int64 (__fastcall *)(Scaleform::Render::ProfileViews *, char *, Scaleform::Render::D3D1x::ShaderInterface **))v106->Profiler->vfptr->GetColor)(
                               v106->Profiler,
                               &v107,
                               &v113);
    v20 = _mm_cvtsi32_si128(*v19);
    v21 = v17->CurShaders.pVDesc;
    v22 = _mm_cvtsi32_si128(v19[3]);
    v23 = (float)v19[2] * 0.0039215689;
    v24 = (float)v19[1];
    v25 = v21->BatchUniforms;
    v26 = v24 * 0.0039215689;
    v27 = v25[5].Offset;
    v28 = COERCE_FLOAT(_mm_cvtepi32_ps(v20)) * 0.0039215689;
    v29 = COERCE_FLOAT(_mm_cvtepi32_ps(v22)) * 0.0039215689;
    if ( v27 >= 0 )
    {
      v30 = (unsigned int)v25[5].Array;
      v31 = v27;
LABEL_20:
      v34 = v21->Uniforms;
      if ( v34[v30].Size )
      {
        v35 = v34[v30].ShadowOffset + (unsigned __int64)(v31 * (unsigned int)(unsigned __int8)v34[v30].ElementSize);
        v17->UniformData[v35] = v23;
        v17->UniformData[v35 + 1] = v26;
        v17->UniformData[v35 + 2] = v28;
        v17->UniformData[v35 + 3] = v29;
      }
      v36 = v17->CurShaders.pFDesc->Uniforms;
      if ( v36[v30].Size )
      {
        v37 = v36[v30].ShadowOffset + (unsigned __int64)(v31 * (unsigned int)(unsigned __int8)v36[v30].ElementSize);
        v17->UniformData[v37] = v23;
        v17->UniformData[v37 + 1] = v26;
        v17->UniformData[v37 + 2] = v28;
        v17->UniformData[v37 + 3] = v29;
      }
      v17->UniformSet[(unsigned int)v30] = 1;
      goto LABEL_33;
    }
    v32 = v17->CurShaders.pFDesc->BatchUniforms;
    v33 = v32[5].Offset;
    if ( v33 >= 0 )
    {
      v31 = v33;
      v30 = (unsigned int)v32[5].Array;
      goto LABEL_20;
    }
    v38 = v21->Uniforms;
    if ( v38[5].Size )
    {
      v39 = v38[5].ShadowOffset;
      v17->UniformData[v39] = v23;
      v17->UniformData[v39 + 1] = v26;
      v17->UniformData[v39 + 2] = v28;
      v17->UniformData[v39 + 3] = v29;
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
  else if ( (signed int)v7 >= 5 )
  {
    v42 = *(_OWORD *)&v18->pVS;
    v43 = *(_OWORD *)&v17->CurShaders.pFS;
    v44 = v4->Data.Textures[0].pObject;
    LOBYTE(v113) = v4->Data.FillModes[0].Fill;
    *(_OWORD *)&v104.M[0][0] = v42;
    *(_OWORD *)&v104.M[1][0] = v43;
    *(_QWORD *)batch = v17->CurShaders.pVFormat;
    Scaleform::Render::D3D1x::ShaderInterface::SetTexture(
      v17,
      (Scaleform::Render::D3D1x::ShaderPair *)&v104,
      0x14u,
      v44,
      (Scaleform::Render::ImageFillMode)&v113,
      0);
    if ( (unsigned int)(v7 - 9) <= 1 )
    {
      v45 = *(_OWORD *)&v18->pVS;
      v46 = *(_OWORD *)&v17->CurShaders.pFS;
      v47 = v4->Data.Textures[1].pObject;
      LOBYTE(v113) = v4->Data.FillModes[1].Fill;
      v48 = (unsigned __int8)v44->TextureCount;
      *(_OWORD *)&v104.M[0][0] = v45;
      *(_OWORD *)&v104.M[1][0] = v46;
      LODWORD(v104.M[1][0]) = v48;
      *(_QWORD *)batch = v17->CurShaders.pVFormat;
      Scaleform::Render::D3D1x::ShaderInterface::SetTexture(
        v17,
        (Scaleform::Render::D3D1x::ShaderPair *)&v104,
        0x14u,
        v47,
        (Scaleform::Render::ImageFillMode)&v113,
        v48);
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
          (Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair> *)v17->UniformData,
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
    LOWORD(v54) = v53;
  }
  else
  {
    v55 = v51->Uniforms;
    if ( v55[21].Location < 0 || (v56 = v55[21].Size, v56 <= 0) )
    {
      v57 = v17->CurShaders.pFDesc;
      v58 = v57->BatchUniforms;
      if ( v58[21].Offset >= 0 && (v59 = v58[21].Size) != 0 )
      {
        LOWORD(v54) = v59;
      }
      else
      {
        v60 = v57->Uniforms;
        if ( v60[21].Location < 0 || (v61 = v60[21].Size, v61 <= 0) )
          LOWORD(v54) = 0;
        else
          v54 = v61 / (signed int)(unsigned __int8)v55[21].ElementSize | 0x20000;
      }
    }
    else
    {
      v54 = v56 / (signed int)(unsigned __int8)v55[21].ElementSize | 0x10000;
    }
  }
  v62 = 0;
  v63 = v7;
  v64 = (unsigned __int16)v54 >> 1;
  if ( vars0 )
  {
    v65 = (signed __int64)m;
    v66 = m;
    do
    {
      Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetMatrix(
        (Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair> *)v17->UniformData,
        &v17->CurShaders,
        0xDu,
        (Scaleform::Render::Matrix2x4<float> *)(*(_QWORD *)(v65 + 8) + 192i64),
        v66,
        retaddr,
        0,
        v62);
      if ( v63 != 1 )
      {
        if ( *(_BYTE *)v108 & 8 )
        {
          v91 = **(_QWORD **)v65;
          if ( *(_BYTE *)(v91 + 15) & 1 )
            v92 = (Scaleform::Render::Cxform *)(v91
                                              + 16
                                              * (unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[*(_BYTE *)(v91 + 15) & 0xF].Offsets[0]
                                              + 16i64);
          else
            v92 = &Scaleform::Render::Cxform::Identity;
          v93 = v106->Profiler->vfptr->GetCxform(v106->Profiler, &v104, v92);
          Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUniform(
            (Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair> *)v17->UniformData,
            &v17->CurShaders,
            5u,
            (const float *)v93,
            4u,
            0,
            v62);
          Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUniform(
            (Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair> *)v17->UniformData,
            &v17->CurShaders,
            4u,
            v93->M[1],
            4u,
            0,
            v62);
        }
        goto LABEL_72;
      }
      *(_WORD *)((char *)&v113 + 1) = -32768;
      LOBYTE(v113) = 0;
      v67 = v106->Profiler;
      BYTE3(v113) = -128;
      v68 = (unsigned __int8 *)((__int64 (__fastcall *)(Scaleform::Render::ProfileViews *, char *, Scaleform::Render::D3D1x::ShaderInterface **))v67->vfptr->GetColor)(
                                 v67,
                                 &v107,
                                 &v113);
      v69 = _mm_cvtsi32_si128(*v68);
      v70 = v17->CurShaders.pVDesc;
      v71 = _mm_cvtsi32_si128(v68[3]);
      v72 = (float)v68[2] * 0.0039215689;
      v73 = (float)v68[1];
      v74 = v70->BatchUniforms;
      v75 = v73 * 0.0039215689;
      v76 = v74[5].Offset;
      v77 = COERCE_FLOAT(_mm_cvtepi32_ps(v69)) * 0.0039215689;
      v78 = COERCE_FLOAT(_mm_cvtepi32_ps(v71)) * 0.0039215689;
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
          v97 = (signed __int64)&m[1].pHandle[24];
          *(_OWORD *)&v104.M[0][0] = *(_OWORD *)v97;
          *(_QWORD *)&v104.M[1][0] = *(_QWORD *)(v97 + 16);
          v104.M[1][2] = *(float *)(v97 + 24);
          v98 = *(float *)(v97 + 28);
          v99 = m->pHandle;
          v104.M[1][3] = v98;
          if ( (unsigned __int8)v95 & v99->pHeader->Format )
            v100 = (Scaleform::Render::Matrix2x4<float> *)&v99->pHeader[(unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[0].Offsets[4 * (v99->pHeader->Format & 0xF) + v96 + (v99->pHeader->Format & 0xF)]
                                                                      + 1];
          else
            v100 = &Scaleform::Render::Matrix2x4<float>::Identity;
          Scaleform::Render::Matrix2x4<float>::Append((Scaleform::Render::Matrix2x4<float> *)&v104, v100);
          Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUniform(
            (Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair> *)v17->UniformData,
            &v17->CurShaders,
            0x15u,
            (const float *)&v104,
            8u,
            2 * v94++,
            v62);
          ++v96;
        }
        while ( v94 < v64 );
        v63 = v103;
      }
      ++v62;
      v66 = v102 + 2;
      v65 = (signed __int64)&m[2];
      m += 2;
    }
    while ( v62 < vars0 );
  }
  return &v17->CurShaders;
}

// File Line: 788
// RVA: 0xA014A0
bool __fastcall Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::SetFilterFill(Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture> *this, Scaleform::Render::Matrix2x4<float> *mvp, Scaleform::Render::Cxform *cx, Scaleform::Render::Filter *filter, Scaleform::Ptr<Scaleform::Render::RenderTarget> *targets, unsigned int *shaders, unsigned int pass, unsigned int passCount, Scaleform::Render::VertexFormat *pvf, Scaleform::Render::D3D1x::ShaderInterface *psi)
{
  __int64 v10; // rbx
  unsigned int *v11; // r12
  Scaleform::Render::D3D1x::ShaderInterface *v12; // rdi
  Scaleform::Render::Matrix2x4<float> *v13; // r13
  Scaleform::Render::Filter *v14; // r14
  bool result; // al
  Scaleform::Render::D3D1x::ShaderPair *v16; // rsi
  unsigned int v17; // eax
  bool v18; // cf
  bool v19; // zf
  Scaleform::RefCountImplCoreVtbl *v20; // rax
  Scaleform::Render::Texture *v21; // rax
  __int128 v22; // xmm1
  Scaleform::Render::Texture *v23; // r13
  __int64 v24; // xmm0_8
  float v25; // xmm7_4
  float v26; // xmm2_4
  float v27; // xmm3_4
  float v28; // xmm4_4
  signed int v29; // eax
  __m128 v30; // xmm3
  signed int v31; // ecx
  float v32; // xmm1_4
  __m128 v33; // xmm1
  signed int v34; // ecx
  float v35; // xmm2_4
  float v36; // xmm7_4
  float v37; // xmm2_4
  float v38; // xmm0_4
  float v39; // xmm0_4
  float v40; // xmm0_4
  Scaleform::Render::RenderTarget *v41; // rcx
  Scaleform::Render::Texture *v42; // rbx
  float v43; // xmm1_4
  __int128 v44; // xmm1
  Scaleform::Render::Texture *v45; // rax
  __int128 v46; // xmm1
  Scaleform::Render::VertexFormat *v47; // xmm0_8
  Scaleform::RefCountBase<Scaleform::Render::Filter,2> v48; // xmm0
  __int128 v49; // xmm3
  float v50; // xmm9_4
  float v51; // xmm7_4
  float v52; // xmm6_4
  float v53; // xmm5_4
  __int128 v54; // xmm2
  __int128 v55; // xmm4
  __int128 v56; // xmm8
  float v57; // xmm1_4
  char v58; // bl
  Scaleform::Render::Texture *v59; // rax
  __int128 v60; // xmm1
  Scaleform::Render::Texture *v61; // r12
  Scaleform::Render::FilterType v62; // ecx
  int v63; // ecx
  int v64; // ecx
  int v65; // ecx
  float v66; // xmm4_4
  float v67; // xmm3_4
  float v68; // xmm1_4
  signed int v69; // eax
  float v70; // xmm0_4
  float v71; // xmm3_4
  float v72; // xmm5_4
  float v73; // xmm1_4
  float v74; // xmm0_4
  float v[4]; // [rsp+40h] [rbp-C0h]
  float pa[4]; // [rsp+50h] [rbp-B0h]
  __int64 v77; // [rsp+60h] [rbp-A0h]
  float v78[2]; // [rsp+70h] [rbp-90h]
  __int64 v79; // [rsp+78h] [rbp-88h]
  float v80[2]; // [rsp+80h] [rbp-80h]
  __int64 v81; // [rsp+88h] [rbp-78h]
  float v82[4]; // [rsp+90h] [rbp-70h]
  __int128 v83; // [rsp+A0h] [rbp-60h]
  __int128 v84; // [rsp+B0h] [rbp-50h]
  __int128 v85; // [rsp+C0h] [rbp-40h]
  float v86[4]; // [rsp+D0h] [rbp-30h]
  Scaleform::Render::Cxform *v87; // [rsp+160h] [rbp+60h]

  v87 = cx;
  v10 = pass;
  v11 = shaders;
  v12 = psi;
  v13 = mvp;
  v14 = filter;
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
    v16 = &v12->CurShaders;
    Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUniform(
      (Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair> *)v12->UniformData,
      &v12->CurShaders,
      0xDu,
      (const float *)v13,
      8u,
      0,
      0);
    v17 = v11[v10] - 655360;
    v18 = v17 < 0x19801;
    v19 = v17 == 104449;
    v20 = targets->pObject->vfptr;
    LOBYTE(shaders) = v18 || v19;
    v21 = (Scaleform::Render::Texture *)((__int64 (*)(void))v20[3].__vecDelDtor)();
    v22 = *(_OWORD *)&v12->CurShaders.pFS;
    v23 = v21;
    *(_OWORD *)v = *(_OWORD *)&v12->CurShaders.pVS;
    *(_OWORD *)pa = v22;
    v24 = (__int64)v12->CurShaders.pVFormat;
    LOBYTE(pass) = 3;
    v77 = v24;
    Scaleform::Render::D3D1x::ShaderInterface::SetTexture(
      v12,
      (Scaleform::Render::D3D1x::ShaderPair *)v,
      0x14u,
      v21,
      (Scaleform::Render::ImageFillMode)&pass,
      0);
    v25 = 0.0;
    v26 = (float)targets->pObject->ViewRect.x1;
    v27 = (float)(targets->pObject->ViewRect.y2 - targets->pObject->ViewRect.y1)
        / (float)(signed int)v23->ImgSize.Height;
    *(float *)&v22 = (float)(targets->pObject->ViewRect.x2 - targets->pObject->ViewRect.x1)
                   / (float)(signed int)v23->ImgSize.Width;
    v28 = (float)targets->pObject->ViewRect.y1 * v27;
    pa[1] = (float)(targets->pObject->ViewRect.y2 - targets->pObject->ViewRect.y1)
          / (float)(signed int)v23->ImgSize.Height;
    pa[3] = v28;
    LODWORD(v[0]) = v22;
    v[1] = *(float *)&v22 * 0.0;
    v[2] = *(float *)&v22 * 0.0;
    v[3] = v26 * *(float *)&v22;
    pa[0] = v27 * 0.0;
    pa[2] = v27 * 0.0;
    Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUniform(
      (Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair> *)v12->UniformData,
      &v12->CurShaders,
      0x15u,
      v,
      8u,
      0,
      0);
    v29 = v14->Type;
    if ( v29 <= 5 )
    {
      Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetCxform(
        (Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair> *)v12->UniformData,
        &v12->CurShaders,
        v87,
        0,
        0);
      v30 = (__m128)(unsigned int)v14[1].RefCount;
      v30.m128_f32[0] = v30.m128_f32[0] * 0.050000001;
      v31 = (signed int)v30.m128_f32[0];
      v32 = (float)(signed int)v23->ImgSize.Height;
      v78[0] = 1.0 / (float)(signed int)v23->ImgSize.Width;
      v78[1] = 1.0 / v32;
      if ( (signed int)v30.m128_f32[0] != 0x80000000 && (float)v31 != v30.m128_f32[0] )
        v30.m128_f32[0] = (float)(v31 - (_mm_movemask_ps(_mm_unpacklo_ps(v30, v30)) & 1));
      if ( v30.m128_f32[0] < 1.0 )
        v30.m128_i32[0] = (signed int)FLOAT_1_0;
      v33 = (__m128)*((unsigned int *)&v14[1].RefCount + 1);
      v33.m128_f32[0] = v33.m128_f32[0] * 0.050000001;
      v34 = (signed int)v33.m128_f32[0];
      if ( (signed int)v33.m128_f32[0] != 0x80000000 && (float)v34 != v33.m128_f32[0] )
        v33.m128_f32[0] = (float)(v34 - (_mm_movemask_ps(_mm_unpacklo_ps(v33, v33)) & 1));
      if ( v33.m128_f32[0] < 1.0 )
        v33.m128_i32[0] = (signed int)FLOAT_1_0;
      if ( v11[v10] - 0x80000 <= 1 )
      {
        if ( !(v10 & 1) )
        {
          v78[1] = 0.0;
          v38 = 1.0 / v30.m128_f32[0];
          v35 = (float)(v30.m128_f32[0] - 1.0) * 0.5;
LABEL_25:
          v[3] = v38;
          if ( (_DWORD)v10 == passCount - 1 )
            v39 = *(float *)&v14[2].vfptr;
          else
            v39 = *(float *)&FLOAT_1_0;
          v[2] = v39;
          v40 = FLOAT_1_0eN12;
          if ( v35 < 1.0e-12 )
            v35 = FLOAT_1_0eN12;
          v[0] = v35;
          if ( v25 >= 1.0e-12 )
            v40 = v25;
          v[1] = v40;
          Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUniform(
            (Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair> *)v12->UniformData,
            &v12->CurShaders,
            8u,
            v,
            4u,
            0,
            0);
          Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUniform(
            (Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair> *)v12->UniformData,
            &v12->CurShaders,
            0x16u,
            v78,
            2u,
            0,
            0);
          if ( (_BYTE)shaders )
          {
            Scaleform::Render::Color::GetRGBAFloat(
              (Scaleform::Render::Color *)&v14[2].vfptr + 1,
              v,
              &v[1],
              &v[2],
              &v[3]);
            Scaleform::Render::Color::GetRGBAFloat(
              (Scaleform::Render::Color *)&v14[2].RefCount,
              pa,
              &pa[1],
              &pa[2],
              &pa[3]);
            v41 = targets[2].pObject;
            v80[0] = *(float *)&v14[1].Type * -0.050000001;
            v80[1] = *(float *)&v14[1].Frozen * -0.050000001;
            if ( v41 )
            {
              v42 = (Scaleform::Render::Texture *)((__int64 (*)(void))v41->vfptr[3].__vecDelDtor)();
              v43 = (float)(signed int)v42->ImgSize.Height;
              *(float *)&shaders = 1.0 / (float)((float)(signed int)v42->ImgSize.Width * v78[0]);
              *((float *)&shaders + 1) = 1.0 / (float)(v43 * v78[1]);
              Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUniform(
                (Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair> *)v12->UniformData,
                &v12->CurShaders,
                0x13u,
                (const float *)&shaders,
                2u,
                0,
                0);
              v44 = *(_OWORD *)&v12->CurShaders.pFS;
              *(_OWORD *)v82 = *(_OWORD *)&v16->pVS;
              LOBYTE(pass) = 3;
              *(_QWORD *)&v84 = v12->CurShaders.pVFormat;
              v83 = v44;
              Scaleform::Render::D3D1x::ShaderInterface::SetTexture(
                v12,
                (Scaleform::Render::D3D1x::ShaderPair *)v82,
                0x12u,
                v42,
                (Scaleform::Render::ImageFillMode)&pass,
                0);
            }
            Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUniform(
              (Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair> *)v12->UniformData,
              &v12->CurShaders,
              0xEu,
              v80,
              2u,
              0,
              0);
            if ( v14->Type == 3 )
              Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUniform(
                (Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair> *)v12->UniformData,
                &v12->CurShaders,
                0x11u,
                pa,
                4u,
                0,
                0);
            if ( (unsigned int)(v14->Type - 4) <= 1 )
            {
              v45 = (Scaleform::Render::Texture *)(*(__int64 (__fastcall **)(_QWORD, Scaleform::Render::TextureManager *))(**(_QWORD **)&v14[3].RefCount + 168i64))(
                                                    *(_QWORD *)&v14[3].RefCount,
                                                    v23->pManagerLocks.pObject->pManager);
              v46 = *(_OWORD *)&v12->CurShaders.pFS;
              *(_OWORD *)v82 = *(_OWORD *)&v16->pVS;
              v83 = v46;
              v47 = v12->CurShaders.pVFormat;
              LOBYTE(pass) = 3;
              *(_QWORD *)&v84 = v47;
              Scaleform::Render::D3D1x::ShaderInterface::SetTexture(
                v12,
                (Scaleform::Render::D3D1x::ShaderPair *)v82,
                9u,
                v45,
                (Scaleform::Render::ImageFillMode)&pass,
                0);
            }
            else
            {
              Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUniform(
                (Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair> *)v12->UniformData,
                &v12->CurShaders,
                0x10u,
                v,
                4u,
                0,
                0);
            }
          }
          goto LABEL_63;
        }
        v37 = v33.m128_f32[0];
        v78[0] = 0.0;
      }
      else
      {
        if ( (_DWORD)v10 == passCount - 1 && (_DWORD)v10 )
        {
          v35 = 0.0;
          v25 = (float)(v33.m128_f32[0] - 1.0) * 0.5;
LABEL_24:
          v38 = 1.0 / v33.m128_f32[0];
          goto LABEL_25;
        }
        v36 = v33.m128_f32[0];
        v37 = v30.m128_f32[0];
        v33.m128_f32[0] = v33.m128_f32[0] * v30.m128_f32[0];
        v25 = (float)(v36 - 1.0) * 0.5;
      }
      v35 = (float)(v37 - 1.0) * 0.5;
      goto LABEL_24;
    }
    if ( v29 == 8 )
    {
      v48 = v14[1].0;
      v49 = *(_OWORD *)&v14[2].RefCount;
      *(Scaleform::RefCountBase<Scaleform::Render::Filter,2> *)v82 = v48;
      v84 = v49;
      v50 = v87->M[0][3];
      v51 = v87->M[0][0];
      v52 = v87->M[0][1];
      v53 = v87->M[0][2];
      v54 = *(_OWORD *)&v14[1].Type;
      v83 = v54;
      v55 = (__int128)v14[3].0;
      v56 = *(_OWORD *)&v14[3].Type;
      v82[0] = (float)(*(float *)&v48.vfptr * v51) * v50;
      v85 = v55;
      *(_OWORD *)v86 = v56;
      v82[2] = (float)(*(float *)&v48.RefCount * v53) * v50;
      *(float *)&v84 = (float)(*(float *)&v49 * v51) * v50;
      *(float *)&v83 = (float)(*(float *)&v54 * v51) * v50;
      *(float *)&v85 = (float)(*(float *)&v55 * v51) * v50;
      v82[1] = (float)(v82[1] * v52) * v50;
      *((float *)&v83 + 2) = (float)(*((float *)&v54 + 2) * v53) * v50;
      v82[3] = *((float *)&v48.RefCount + 1) * v50;
      *((float *)&v83 + 1) = (float)(*((float *)&v83 + 1) * v52) * v50;
      *((float *)&v84 + 2) = (float)(*((float *)&v49 + 2) * v53) * v50;
      *((float *)&v83 + 3) = *((float *)&v54 + 3) * v50;
      *((float *)&v84 + 1) = (float)(*((float *)&v84 + 1) * v52) * v50;
      *((float *)&v85 + 2) = (float)(*((float *)&v55 + 2) * v53) * v50;
      *((float *)&v84 + 3) = *((float *)&v49 + 3) * v50;
      *((float *)&v85 + 1) = (float)(*((float *)&v85 + 1) * v52) * v50;
      *((float *)&v85 + 3) = *((float *)&v55 + 3) * v50;
      v86[0] = (float)((float)(v87->M[1][0] * 0.0039215689) + (float)((float)(*(float *)&v56 * v51) * v50)) * v50;
      v57 = v87->M[1][2];
      v86[1] = (float)((float)(v87->M[1][1] * 0.0039215689) + (float)((float)(v86[1] * v52) * v50)) * v50;
      *(float *)&v48.vfptr = v87->M[1][3];
      v86[2] = (float)((float)(v57 * 0.0039215689) + (float)((float)(*((float *)&v56 + 2) * v53) * v50)) * v50;
      v86[3] = (float)((float)(*(float *)&v48.vfptr * 0.0039215689) + (float)(*((float *)&v56 + 3) * v50)) * v50;
      Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUniform(
        (Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair> *)v12->UniformData,
        &v12->CurShaders,
        4u,
        v86,
        4u,
        0,
        0);
      Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUniform(
        (Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair> *)v12->UniformData,
        &v12->CurShaders,
        5u,
        v82,
        0x10u,
        0,
        0);
LABEL_63:
      Scaleform::Render::D3D1x::ShaderInterface::Finish(v12, 1u);
      return 1;
    }
    if ( v29 != 10 )
      goto LABEL_63;
    v58 = 3;
    if ( !LODWORD(v14[2].vfptr) )
      v58 = 2;
    v59 = (Scaleform::Render::Texture *)(*((__int64 (__fastcall **)(Scaleform::RefCountImplCoreVtbl *, _QWORD))v14[1].vfptr->__vecDelDtor
                                         + 21))(
                                          v14[1].vfptr,
                                          0i64);
    LOBYTE(pass) = v58;
    v60 = *(_OWORD *)&v12->CurShaders.pFS;
    v61 = v59;
    *(_OWORD *)v82 = *(_OWORD *)&v16->pVS;
    v83 = v60;
    *(_QWORD *)&v84 = v12->CurShaders.pVFormat;
    Scaleform::Render::D3D1x::ShaderInterface::SetTexture(
      v12,
      (Scaleform::Render::D3D1x::ShaderPair *)v82,
      0xBu,
      v59,
      (Scaleform::Render::ImageFillMode)&pass,
      0);
    v62 = v14[1].Type;
    *(_QWORD *)v80 = 0i64;
    v81 = 0i64;
    *(_QWORD *)v78 = 0i64;
    v79 = 0i64;
    *(_QWORD *)v = 0i64;
    *(_QWORD *)&v[2] = 0i64;
    shaders = 0i64;
    v63 = v62 - 1;
    if ( v63 )
    {
      v64 = v63 - 1;
      if ( !v64 )
      {
        v80[1] = 1.0;
        goto LABEL_53;
      }
      v65 = v64 - 2;
      if ( !v65 )
      {
        LODWORD(v81) = 1065353216;
        goto LABEL_53;
      }
      if ( v65 == 4 )
      {
        HIDWORD(v81) = 1065353216;
        goto LABEL_53;
      }
    }
    v80[0] = 1.0;
LABEL_53:
    if ( *(_DWORD *)&v14[1].Frozen != 1 )
    {
      switch ( *(_DWORD *)&v14[1].Frozen )
      {
        case 2:
          v78[1] = 1.0;
          goto LABEL_61;
        case 4:
          LODWORD(v79) = 1065353216;
          goto LABEL_61;
        case 8:
          HIDWORD(v79) = 1065353216;
          goto LABEL_61;
      }
    }
    v78[0] = 1.0;
LABEL_61:
    v66 = (float)(signed int)v23->ImgSize.Width;
    v67 = 1.0 / (float)(signed int)v61->ImgSize.Width;
    v68 = (float)(signed int)v61->ImgSize.Height;
    v69 = v23->ImgSize.Height;
    v70 = v67;
    v71 = v67 * *(float *)&v14[1].RefCount;
    v[0] = v70 * v66;
    v[2] = v71;
    v72 = 1.0 / v68;
    v73 = *(float *)&v14[2].RefCount;
    v[3] = v72 * *((float *)&v14[1].RefCount + 1);
    v[1] = v72 * (float)v69;
    v74 = *((float *)&v14[2].vfptr + 1) / v66;
    *((float *)&shaders + 1) = v73 / (float)v69;
    *(float *)&shaders = v74;
    Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUniform(
      (Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair> *)v12->UniformData,
      &v12->CurShaders,
      2u,
      v80,
      4u,
      0,
      0);
    Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUniform(
      (Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair> *)v12->UniformData,
      &v12->CurShaders,
      3u,
      v78,
      4u,
      0,
      0);
    Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUniform(
      (Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair> *)v12->UniformData,
      &v12->CurShaders,
      0xAu,
      v,
      4u,
      0,
      0);
    Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUniform(
      (Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair> *)v12->UniformData,
      &v12->CurShaders,
      0xFu,
      (const float *)&shaders,
      2u,
      0,
      0);
    if ( LODWORD(v14[2].vfptr) == 3 )
    {
      Scaleform::Render::Color::GetRGBAFloat((Scaleform::Render::Color *)&v14[2].RefCount + 1, v, &v[1], &v[2], &v[3]);
      Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUniform(
        (Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair> *)v12->UniformData,
        &v12->CurShaders,
        1u,
        v,
        4u,
        0,
        0);
    }
    goto LABEL_63;
  }
  return result;
}aleform::Render::Color::GetRGBAFloat((Scaleform::Render::Color *)&v

// File Line: 995
// RVA: 0x9FED20
signed __int64 __fastcall Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::GetFilterPasses(Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture> *this, Scaleform::Render::Filter *filter, unsigned int fillFlags, unsigned int *passes)
{
  Scaleform::Render::FilterType v4; // eax
  char v5; // si
  unsigned int v6; // er8
  char v7; // bl
  unsigned int v8; // er10
  signed int v9; // eax
  unsigned int *v10; // rdi
  __int64 i; // rcx
  int v12; // edi
  int v13; // eax
  unsigned int *v14; // rcx
  unsigned int v15; // eax
  int v16; // eax
  int v17; // edx
  signed int v19; // eax
  int v20; // eax

  v4 = filter->Type;
  v5 = fillFlags;
  if ( (signed int)v4 > 5 )
  {
    if ( v4 == 8 )
    {
      v6 = 1;
      *passes = 393216;
      if ( v5 & 1 )
      {
        *passes = 393217;
        return 1i64;
      }
    }
    else if ( v4 == 10 )
    {
      *passes = 786432;
      v6 = 1;
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
      v6 = 0;
    }
  }
  else
  {
    v6 = HIDWORD(filter[1].vfptr);
    v7 = 0;
    if ( (float)(*((float *)&filter[1].RefCount + 1) * *(float *)&filter[1].RefCount) >= 12800.0 )
    {
      v6 *= 2;
      v7 = 1;
    }
    v8 = 0;
    if ( v6 != 1 )
    {
      v8 = v6 - 1;
      v9 = 557056;
      v10 = passes;
      if ( v7 )
        v9 = 0x80000;
      for ( i = v8; i; --i )
      {
        *v10 = v9;
        ++v10;
      }
    }
    v12 = (_QWORD)filter[1].vfptr & 7;
    if ( (unsigned int)(v12 - 1) > 4 )
    {
      v19 = 0x8000;
      if ( v7 )
        v19 = 0;
      v20 = v19 + 0x80000;
      passes[v8] = v20;
      if ( v5 & 1 )
      {
        passes[v8] = v20 + 1;
        return v6;
      }
    }
    else
    {
      if ( v12 <= 2 )
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
      v13 = (int)filter[1].vfptr;
      if ( v13 & 0x20 )
      {
        v14 = &passes[v8];
        v15 = passes[v8];
        if ( _bittest((const signed int *)&v15, 0x10u) || v12 == 4 )
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
      else if ( (v13 & 0x80u) == 0 && (v12 != 1 || !(v13 & 0x40) || v13 & 0x10) )
      {
        v14 = &passes[v8];
        v16 = passes[v8];
      }
      else
      {
        v14 = &passes[v8];
        v16 = passes[v8] + 512;
        *v14 = v16;
      }
      v17 = (int)filter[1].vfptr;
      if ( v17 & 0x40 || v17 & 0x10 )
        v16 += 4096;
      *v14 = v16;
      if ( v5 & 1 )
      {
        *v14 = v16 + 1;
        return v6;
      }
    }
  }
  return v6;
}

// File Line: 1151
// RVA: 0xA00F30
char __fastcall Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::SetDrawableCopyPixelsFill(Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture> *this, Scaleform::Render::Texture **tex, Scaleform::Render::Matrix2x4<float> *texgen, Scaleform::Render::Size<int> texsize, Scaleform::Render::Matrix2x4<float> *mvp, bool mergeAlpha, bool destAlpha, Scaleform::Render::VertexFormat *pvf, Scaleform::Render::D3D1x::ShaderInterface *psi)
{
  Scaleform::Render::Texture **v9; // rdi
  Scaleform::Render::D3D1x::ShaderDesc::ShaderType v10; // edx
  int *v11; // rsi
  Scaleform::Render::Matrix2x4<float> *v12; // rbp
  Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture> *v13; // r14
  Scaleform::Render::D3D1x::ShaderInterface *v14; // rbx
  char result; // al
  bool v16; // zf
  Scaleform::Render::Size<int> v17; // [rsp+68h] [rbp+10h]

  v9 = tex;
  v10 = 917504;
  v11 = (int *)texsize;
  v12 = texgen;
  if ( v9[2] )
    v10 = 917632;
  v13 = this;
  if ( destAlpha )
  {
    if ( mergeAlpha )
      v10 += 64;
  }
  else
  {
    v10 += 32;
  }
  v14 = psi;
  result = Scaleform::Render::D3D1x::ShaderInterface::SetStaticShader(psi, v10, pvf);
  if ( result )
  {
    if ( !v14->PrimitiveOpen )
    {
      v14->PrimitiveOpen = 1;
      *(_QWORD *)v14->UniformSet = 0i64;
      *(_QWORD *)&v14->UniformSet[8] = 0i64;
      *(_QWORD *)&v14->UniformSet[16] = 0i64;
      *(_WORD *)&v14->UniformSet[24] = 0;
      v14->Textures[0] = 0i64;
      v14->Textures[1] = 0i64;
      v14->Textures[2] = 0i64;
      v14->Textures[3] = 0i64;
    }
    v16 = v9[2] == 0i64;
    v17.Width = *v11;
    v17.Height = v11[1];
    result = Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::DrawableFinish(
               v13,
               !v16 + 2,
               v9,
               v12);
  }
  return result;
}

// File Line: 1174
// RVA: 0xA01180
char __fastcall Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::SetDrawableMergeFill(Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture> *this, Scaleform::Render::Texture **tex, Scaleform::Render::Matrix2x4<float> *texgen, Scaleform::Render::Size<int> texsize, Scaleform::Render::Matrix4x4<float> *cxmul, Scaleform::Render::VertexFormat *pvf, Scaleform::Render::D3D1x::ShaderInterface *psi)
{
  Scaleform::Render::Matrix2x4<float> *v7; // rbp
  Scaleform::Render::Texture **v8; // r15
  Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture> *v9; // r12
  int *v10; // r14
  char result; // al
  int v12; // eax
  Scaleform::Render::Size<int> texsizea; // [rsp+40h] [rbp-58h]
  Scaleform::Render::Matrix2x4<float> mvpOriginal; // [rsp+50h] [rbp-48h]

  v7 = texgen;
  v8 = tex;
  v9 = this;
  v10 = (int *)texsize;
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
      (Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair> *)psi->UniformData,
      &psi->CurShaders,
      5u,
      (const float *)cxmul,
      0x10u,
      0,
      0);
    Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUniform(
      (Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair> *)psi->UniformData,
      &psi->CurShaders,
      6u,
      (const float *)&cxmul[1],
      0x10u,
      0,
      0);
    v12 = *v10;
    *(_OWORD *)&mvpOriginal.M[0][0] = _xmm_bf800000000000000000000040000000;
    *(_OWORD *)&mvpOriginal.M[1][0] = _xmm;
    texsizea.Width = v12;
    texsizea.Height = v10[1];
    result = Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::DrawableFinish(
               v9,
               2u,
               v8,
               v7);
  }
  return result;
}

// File Line: 1192
// RVA: 0xA01050
char __fastcall Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::SetDrawableCxform(Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture> *this, Scaleform::Render::Texture **tex, Scaleform::Render::Matrix2x4<float> *texgen, Scaleform::Render::Size<int> texsize, Scaleform::Render::Cxform *cx, Scaleform::Render::VertexFormat *pvf, Scaleform::Render::D3D1x::ShaderInterface *psi)
{
  Scaleform::Render::Matrix2x4<float> *v7; // rsi
  Scaleform::Render::Texture **v8; // rbp
  Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture> *v9; // r14
  int *v10; // rdi
  char result; // al
  int v12; // eax
  Scaleform::Render::Size<int> texsizea; // [rsp+40h] [rbp-38h]
  Scaleform::Render::Matrix2x4<float> v14; // [rsp+50h] [rbp-28h]

  v7 = texgen;
  v8 = tex;
  v9 = this;
  v10 = (int *)texsize;
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
      (Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair> *)psi->UniformData,
      &psi->CurShaders,
      cx,
      0,
      0);
    texsizea.Width = *v10;
    v12 = v10[1];
    *(_OWORD *)&v14.M[0][0] = _xmm_bf800000000000000000000040000000;
    *(_OWORD *)&v14.M[1][0] = _xmm;
    texsizea.Height = v12;
    result = Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::DrawableFinish(
               v9,
               1u,
               v8,
               v7);
  }
  return result;
}

// File Line: 1207
// RVA: 0xA00E20
char __fastcall Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::SetDrawableCompare(Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture> *this, Scaleform::Render::Texture **tex, Scaleform::Render::Matrix2x4<float> *texgen, Scaleform::Render::Size<int> texsize, Scaleform::Render::VertexFormat *pvf, Scaleform::Render::D3D1x::ShaderInterface *psi)
{
  Scaleform::Render::Matrix2x4<float> *v6; // rsi
  Scaleform::Render::Texture **v7; // rbp
  Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture> *v8; // r14
  int *v9; // rdi
  char result; // al
  int v11; // eax
  Scaleform::Render::Size<int> v12; // [rsp+40h] [rbp-38h]
  Scaleform::Render::Matrix2x4<float> v13; // [rsp+50h] [rbp-28h]

  v6 = texgen;
  v7 = tex;
  v8 = this;
  v9 = (int *)texsize;
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
    v12.Width = *v9;
    v11 = v9[1];
    *(_OWORD *)&v13.M[0][0] = _xmm_bf800000000000000000000040000000;
    *(_OWORD *)&v13.M[1][0] = _xmm;
    v12.Height = v11;
    result = Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::DrawableFinish(
               v8,
               2u,
               v7,
               v6);
  }
  return result;
}

// File Line: 1220
// RVA: 0xA01310
char __fastcall Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::SetDrawablePaletteMap(Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture> *this, Scaleform::Render::Texture **tex, Scaleform::Render::Matrix2x4<float> *texgen, Scaleform::Render::Size<int> texsize, Scaleform::Render::Matrix2x4<float> *mvp, Scaleform::Render::Texture *paletteMap, Scaleform::Render::VertexFormat *pvf, Scaleform::Render::D3D1x::ShaderInterface *psi)
{
  Scaleform::Render::Matrix2x4<float> *v8; // rsi
  Scaleform::Render::Texture **v9; // rbp
  Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture> *v10; // r14
  int *v11; // rdi
  char result; // al
  __int128 v13; // xmm0
  __int128 v14; // xmm1
  char v15; // [rsp+40h] [rbp-48h]
  Scaleform::Render::Size<int> v16; // [rsp+48h] [rbp-40h]
  __int128 v17; // [rsp+50h] [rbp-38h]
  __int128 v18; // [rsp+60h] [rbp-28h]
  Scaleform::Render::VertexFormat *v19; // [rsp+70h] [rbp-18h]

  v8 = texgen;
  v9 = tex;
  v10 = this;
  v11 = (int *)texsize;
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
    v17 = v13;
    v18 = v14;
    v19 = psi->CurShaders.pVFormat;
    Scaleform::Render::D3D1x::ShaderInterface::SetTexture(
      psi,
      (Scaleform::Render::D3D1x::ShaderPair *)&v17,
      0x12u,
      paletteMap,
      (Scaleform::Render::ImageFillMode)&v15,
      0);
    v16.Width = *v11;
    v16.Height = v11[1];
    result = Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::DrawableFinish(
               v10,
               1u,
               v9,
               v8);
  }
  return result;
}

// File Line: 1238
// RVA: 0x9FE540
char __fastcall Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::DrawableFinish(Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture> *this, unsigned int srcCount, Scaleform::Render::Texture **tex, Scaleform::Render::Matrix2x4<float> *texgen)
{
  Scaleform::Render::Matrix2x4<float> *v4; // r14
  Scaleform::Render::Texture **v5; // r15
  unsigned int v6; // er12
  float v7; // xmm1_4
  float v8; // xmm9_4
  float v9; // xmm6_4
  float v10; // xmm10_4
  float v11; // xmm11_4
  float v12; // xmm7_4
  unsigned int v13; // xmm0_4
  float v14; // xmm0_4
  unsigned int v15; // ebx
  __int128 v16; // xmm0
  __int128 v17; // xmm1
  Scaleform::Render::Texture *v18; // r9
  unsigned int n[4]; // [rsp+18h] [rbp-79h]
  unsigned int index[4]; // [rsp+28h] [rbp-69h]
  __int64 v22; // [rsp+38h] [rbp-59h]
  signed int *retaddr; // [rsp+F8h] [rbp+67h]
  __int64 v24; // [rsp+100h] [rbp+6Fh]
  Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair> *v25; // [rsp+108h] [rbp+77h]
  int v26; // [rsp+110h] [rbp+7Fh]

  v4 = texgen;
  v5 = tex;
  v6 = srcCount;
  v7 = *(float *)v24;
  v8 = *(float *)(v24 + 4);
  v9 = *(float *)(v24 + 12);
  v10 = *(float *)(v24 + 16);
  v11 = *(float *)(v24 + 20);
  v12 = *(float *)(v24 + 28);
  n[2] = *(_DWORD *)(v24 + 8);
  v13 = *(_DWORD *)(v24 + 24);
  *(float *)n = v7;
  *(float *)&n[1] = v8;
  *(float *)&n[3] = v9;
  *(float *)index = v10;
  *(float *)&index[1] = v11;
  index[2] = v13;
  *(float *)&index[3] = v12;
  if ( v26 & 2 )
  {
    index[2] = 0;
    n[2] = 0;
    *(float *)n = v7 + (float)(v8 * 0.0);
    *(float *)&n[1] = (float)(v7 * 0.0) - (float)(v8 * 1.0);
    v9 = (float)(v9 + (float)((float)(v7 * 0.0) + v8)) + (float)((float)(v7 * 0.0) + (float)(v8 * 0.0));
    *(float *)index = v10 + (float)(v11 * 0.0);
    *(float *)&n[3] = v9;
    v12 = (float)(v12 + (float)((float)(v10 * 0.0) + v11)) + (float)((float)(v10 * 0.0) + (float)(v11 * 0.0));
    *(float *)&index[1] = (float)(v10 * 0.0) - (float)(v11 * 1.0);
    *(float *)&index[3] = v12;
  }
  if ( v26 & 1 )
  {
    v14 = (float)retaddr[1];
    *(float *)&n[3] = v9 + (float)(-1.0 / (float)*retaddr);
    *(float *)&index[3] = v12 + (float)(1.0 / v14);
  }
  Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUniform(
    v25,
    (Scaleform::Render::D3D1x::ShaderPair *)&v25[1].UniformData[2],
    0xDu,
    (const float *)n,
    8u,
    0,
    0);
  v15 = 0;
  if ( v6 )
  {
    do
    {
      v16 = *(_OWORD *)&v25[1].UniformData[2];
      v17 = *(_OWORD *)&v25[1].UniformData[6];
      v18 = *v5;
      LOBYTE(v26) = 1;
      *(_OWORD *)n = v16;
      *(_OWORD *)index = v17;
      v22 = *(_QWORD *)&v25[1].UniformData[10];
      Scaleform::Render::D3D1x::ShaderInterface::SetTexture(
        (Scaleform::Render::D3D1x::ShaderInterface *)v25,
        (Scaleform::Render::D3D1x::ShaderPair *)n,
        0x14u,
        v18,
        (Scaleform::Render::ImageFillMode)&v26,
        v17);
      Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUniform(
        v25,
        (Scaleform::Render::D3D1x::ShaderPair *)&v25[1].UniformData[2],
        0x15u,
        (const float *)v4,
        8u,
        2 * v15++,
        0);
      ++v4;
      ++v5;
    }
    while ( v15 < v6 );
  }
  Scaleform::Render::D3D1x::ShaderInterface::Finish((Scaleform::Render::D3D1x::ShaderInterface *)v25, 1u);
  return 1;
}

// File Line: 1268
// RVA: 0xA00890
void __fastcall Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::SetBlendFill(Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture> *this, Scaleform::Render::BlendMode mode, Scaleform::Render::Matrix2x4<float> *mvp, Scaleform::Render::Cxform *cx, Scaleform::Render::Texture **ptextures, Scaleform::Render::Matrix2x4<float> *texgen, Scaleform::Render::VertexFormat *pvf, Scaleform::Render::D3D1x::ShaderInterface *psi)
{
  Scaleform::Render::Texture **v8; // rsi
  Scaleform::Render::BlendMode v9; // ebp
  unsigned int v10; // er14
  __int32 v11; // eax
  Scaleform::Render::Cxform *v12; // r12
  Scaleform::Render::Matrix2x4<float> *v13; // r15
  Scaleform::Render::D3D1x::ShaderDesc::ShaderType v14; // edx
  char v15; // cl
  Scaleform::Render::D3D1x::ShaderInterface *v16; // rbx
  __int128 *v17; // rdi
  Scaleform::Render::Matrix2x4<float> *v18; // r15
  Scaleform::Render::Texture *v19; // r9
  __int128 v20; // xmm1
  __int64 v21; // xmm0_8
  Scaleform::Render::Texture *v22; // r9
  __int128 v23; // xmm1
  Scaleform::Render::Texture *v24; // r9
  __int128 v25; // xmm1
  __int64 v26; // xmm0_8
  __int128 v27; // [rsp+40h] [rbp-58h]
  __int128 v28; // [rsp+50h] [rbp-48h]
  __int64 v29; // [rsp+60h] [rbp-38h]
  char v30; // [rsp+A8h] [rbp+10h]

  v8 = ptextures;
  v9 = mode;
  v10 = 18;
  v11 = mode - 2;
  v12 = cx;
  v13 = mvp;
  v14 = 0x20000;
  switch ( v11 )
  {
    case 0:
      if ( ptextures[2] )
      {
        v14 = 1441793;
      }
      else
      {
        if ( !`Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::SetBlendFill'::`12'::warned )
          `Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::SetBlendFill'::`12'::warned = ptextures[1] != 0i64;
        v14 = 257;
        v10 = 20;
      }
      break;
    case 3:
      v14 = 1441792;
      break;
    case 4:
      v14 = 1441808;
      break;
    case 5:
      v14 = 1441794;
      break;
    case 11:
      v14 = 1441800;
      break;
    case 12:
      v14 = 1441796;
      break;
    default:
      v15 = `Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::SetBlendFill'::`5'::warned;
      if ( !`Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::SetBlendFill'::`5'::warned )
        v15 = 1;
      `Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::SetBlendFill'::`5'::warned = v15;
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
  v17 = (__int128 *)&v16->CurShaders;
  Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUniform(
    (Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair> *)v16->UniformData,
    &v16->CurShaders,
    0xDu,
    (const float *)v13,
    8u,
    0,
    0);
  v18 = texgen;
  Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUniform(
    (Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair> *)v16->UniformData,
    &v16->CurShaders,
    0x15u,
    (const float *)texgen,
    8u,
    0,
    0);
  v19 = *v8;
  v20 = *(_OWORD *)&v16->CurShaders.pFS;
  v27 = *(_OWORD *)&v16->CurShaders.pVS;
  v28 = v20;
  v21 = (__int64)v16->CurShaders.pVFormat;
  v30 = 1;
  v29 = v21;
  Scaleform::Render::D3D1x::ShaderInterface::SetTexture(
    v16,
    (Scaleform::Render::D3D1x::ShaderPair *)&v27,
    v10,
    v19,
    (Scaleform::Render::ImageFillMode)&v30,
    0);
  if ( v8[1] )
  {
    Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUniform(
      (Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair> *)v16->UniformData,
      &v16->CurShaders,
      0x15u,
      (const float *)&v18[1],
      8u,
      2u,
      0);
    v22 = v8[1];
    v23 = *(_OWORD *)&v16->CurShaders.pFS;
    v27 = *v17;
    v28 = v23;
    v29 = (__int64)v16->CurShaders.pVFormat;
    v30 = 1;
    Scaleform::Render::D3D1x::ShaderInterface::SetTexture(
      v16,
      (Scaleform::Render::D3D1x::ShaderPair *)&v27,
      7u,
      v22,
      (Scaleform::Render::ImageFillMode)&v30,
      0);
  }
  if ( v8[2] )
  {
    Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUniform(
      (Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair> *)v16->UniformData,
      &v16->CurShaders,
      0x15u,
      (const float *)&v18[2],
      8u,
      2u,
      0);
    v24 = v8[2];
    v25 = *(_OWORD *)&v16->CurShaders.pFS;
    v27 = *v17;
    v28 = v25;
    v26 = (__int64)v16->CurShaders.pVFormat;
    v30 = 1;
    v29 = v26;
    Scaleform::Render::D3D1x::ShaderInterface::SetTexture(
      v16,
      (Scaleform::Render::D3D1x::ShaderPair *)&v27,
      0,
      v24,
      (Scaleform::Render::ImageFillMode)&v30,
      0);
  }
  if ( v9 == 2 )
    Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetCxform(
      (Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair> *)v16->UniformData,
      &v16->CurShaders,
      v12,
      0,
      0);
  Scaleform::Render::D3D1x::ShaderInterface::Finish(v16, 1u);
}

