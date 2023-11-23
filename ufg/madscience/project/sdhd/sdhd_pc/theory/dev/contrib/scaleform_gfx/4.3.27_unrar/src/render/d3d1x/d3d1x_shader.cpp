// File Line: 25
// RVA: 0xA098E0
char __fastcall Scaleform::Render::D3D1x::VertexShader::Init(
        Scaleform::Render::D3D1x::VertexShader *this,
        ID3D11Device *pdevice,
        Scaleform::Render::D3D1x::VertexShaderDesc *pd)
{
  __int64 v6; // r8
  int *v7; // rax
  __int64 v8; // r9

  this->pDesc = pd;
  if ( ((int (__fastcall *)(ID3D11Device *, const char *, _QWORD, _QWORD, Scaleform::Ptr<ID3D11VertexShader> *))pdevice->vfptr->IASetVertexBuffers)(
         pdevice,
         pd->pBinary,
         pd->BinarySize,
         0i64,
         &this->pProg) < 0 )
    return 0;
  v6 = 0i64;
  v7 = &this->UniformOffset[1];
  v8 = 13i64;
  do
  {
    v7 += 2;
    v6 += 2i64;
    *(v7 - 3) = 16 * pd->Uniforms[v6 - 2].Location;
    *(v7 - 2) = 16 * pd->Uniforms[v6 - 1].Location;
    --v8;
  }
  while ( v8 );
  return 1;
}

// File Line: 71
// RVA: 0xA09850
char __fastcall Scaleform::Render::D3D1x::FragShader::Init(
        Scaleform::Render::D3D1x::FragShader *this,
        ID3D11Device *pdevice,
        Scaleform::Render::D3D1x::FragShaderDesc *pd)
{
  __int64 v6; // r8
  int *v7; // rax
  __int64 v8; // r9

  this->pDesc = pd;
  if ( ((int (__fastcall *)(ID3D11Device *, const char *, _QWORD, _QWORD, Scaleform::Ptr<ID3D11PixelShader> *))pdevice->vfptr->DrawInstanced)(
         pdevice,
         pd->pBinary,
         pd->BinarySize,
         0i64,
         &this->pProg) < 0 )
    return 0;
  v6 = 0i64;
  v7 = &this->UniformOffset[1];
  v8 = 13i64;
  do
  {
    v7 += 2;
    v6 += 2i64;
    *(v7 - 3) = 16 * pd->Uniforms[v6 - 2].Location;
    *(v7 - 2) = 16 * pd->Uniforms[v6 - 1].Location;
    --v8;
  }
  while ( v8 );
  return 1;
}

// File Line: 113
// RVA: 0xA0A5A0
void __fastcall Scaleform::Render::D3D1x::VertexShader::Shutdown(Scaleform::Render::D3D1x::VertexShader *this)
{
  ID3D11VertexShader *pObject; // rcx

  pObject = this->pProg.pObject;
  if ( pObject )
    pObject->vfptr->Release(pObject);
  this->pProg.pObject = 0i64;
}

// File Line: 138
// RVA: 0xA08FA0
void __fastcall Scaleform::Render::D3D1x::SysVertexFormat::SysVertexFormat(
        Scaleform::Render::D3D1x::SysVertexFormat *this,
        ID3D11Device *pdevice,
        Scaleform::Render::VertexFormat *vf,
        Scaleform::Render::D3D1x::VertexShaderDesc *pvdesc)
{
  Scaleform::Ptr<ID3D11InputLayout> *p_pVDecl; // r14
  $3C54659889F1EB765F9D24AEEC355797 *v8; // rcx
  unsigned int i; // eax
  unsigned __int16 v10; // di
  int NumAttribs; // eax
  unsigned int *p_SemanticIndex; // r9
  __int64 v13; // r10
  unsigned int v14; // r8d
  unsigned int v15; // edx
  __int64 v16; // rcx
  __int64 v17; // rax
  D3D11_INPUT_ELEMENT_DESC *VertexElements; // rbx
  __int64 *v19; // rcx
  __int64 v20; // rax
  __int64 Src[32]; // [rsp+40h] [rbp-138h] BYREF
  unsigned __int16 v22; // [rsp+140h] [rbp-38h]

  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::Render::SystemVertexFormat,2>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::SystemVertexFormat::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::D3D1x::SysVertexFormat::`vftable;
  p_pVDecl = &this->pVDecl;
  this->pVDecl.pObject = 0i64;
  v8 = &vf->pElements->4;
  for ( i = v8->Attribute; v8->Attribute; i = v8->Attribute )
  {
    if ( (i & 0xF00) == 256 )
      break;
    v8 += 2;
  }
  v10 = 0;
  v22 = 0;
  NumAttribs = pvdesc->NumAttribs;
  if ( NumAttribs > 0 )
  {
    p_SemanticIndex = &pvdesc->Attributes[0].SemanticIndex;
    v13 = (unsigned int)NumAttribs;
    do
    {
      v14 = p_SemanticIndex[1];
      v15 = *p_SemanticIndex;
      v16 = *((_QWORD *)p_SemanticIndex - 1);
      v17 = 4i64 * v10;
      v22 = v10 + 1;
      Src[v17] = v16;
      LODWORD(Src[v17 + 1]) = v15;
      HIDWORD(Src[v17 + 1]) = v14;
      LODWORD(Src[v17 + 2]) = 0;
      HIDWORD(Src[v17 + 2]) = -1;
      Src[v17 + 3] = 0i64;
      p_SemanticIndex += 8;
      v10 = v22;
      --v13;
    }
    while ( v13 );
  }
  VertexElements = this->VertexElements;
  memmove(this->VertexElements, Src, 32i64 * v10);
  this->VertexElementCount = v10;
  if ( ((int (__fastcall *)(ID3D11Device *, __int64 *, _QWORD, const char *, _QWORD, Scaleform::Ptr<ID3D11InputLayout> *, __int64))pdevice->vfptr->IASetInputLayout)(
         pdevice,
         Src,
         v10,
         pvdesc->pBinary,
         pvdesc->BinarySize,
         p_pVDecl,
         -2i64) < 0 )
  {
    if ( p_pVDecl->pObject )
      p_pVDecl->pObject->vfptr->Release(p_pVDecl->pObject);
    p_pVDecl->pObject = 0i64;
  }
  v19 = Src;
  if ( (((unsigned __int8)VertexElements | (unsigned __int8)Src) & 0xF) != 0 )
  {
    memmove(this->VertexElements, Src, 0x100ui64);
  }
  else
  {
    v20 = 2i64;
    do
    {
      *(_OWORD *)&VertexElements->SemanticName = *(_OWORD *)v19;
      *(_OWORD *)&VertexElements->InputSlot = *((_OWORD *)v19 + 1);
      *(_OWORD *)&VertexElements[1].SemanticName = *((_OWORD *)v19 + 2);
      *(_OWORD *)&VertexElements[1].InputSlot = *((_OWORD *)v19 + 3);
      *(_OWORD *)&VertexElements[2].SemanticName = *((_OWORD *)v19 + 4);
      *(_OWORD *)&VertexElements[2].InputSlot = *((_OWORD *)v19 + 5);
      *(_OWORD *)&VertexElements[3].SemanticName = *((_OWORD *)v19 + 6);
      VertexElements += 4;
      *(_OWORD *)&VertexElements[-1].InputSlot = *((_OWORD *)v19 + 7);
      v19 += 16;
      --v20;
    }
    while ( v20 );
  }
}

// File Line: 167
// RVA: 0xA0A420
bool __fastcall Scaleform::Render::D3D1x::ShaderInterface::SetStaticShader(
        Scaleform::Render::D3D1x::ShaderInterface *this,
        Scaleform::Render::D3D1x::ShaderDesc::ShaderType shader,
        Scaleform::Render::VertexFormat *pformat)
{
  Scaleform::Render::D3D1x::HAL *pHal; // rbx
  Scaleform::Render::D3D1x::VertexShader *v7; // rax
  Scaleform::Render::D3D1x::FragShader *v8; // rax
  Scaleform::Render::D3D1x::SysVertexFormat *v9; // rax
  Scaleform::Render::SystemVertexFormat *v10; // rax
  Scaleform::Render::SystemVertexFormat *v11; // rbx
  Scaleform::Render::RenderBuffer *pObject; // rcx
  Scaleform::Render::D3D1x::VertexShader *pVS; // rax
  Scaleform::Render::D3D1x::FragShader *pFS; // rcx
  bool result; // al

  this->CurShaders.pVFormat = pformat;
  pHal = this->pHal;
  v7 = &pHal->SManager.StaticVShaders[Scaleform::Render::D3D1x::VertexShaderDesc::GetShaderIndex(
                                        shader,
                                        pHal->SManager.ShaderModel)];
  this->CurShaders.pVS = v7;
  this->CurShaders.pVDesc = v7->pDesc;
  v8 = &this->pHal->SManager.StaticFShaders[(__int64)(int)Scaleform::Render::D3D1x::FragShaderDesc::GetShaderIndex(
                                                            shader,
                                                            pHal->SManager.ShaderModel)];
  this->CurShaders.pFS = v8;
  this->CurShaders.pFDesc = v8->pDesc;
  if ( pformat && !pformat->pSysFormat.pObject )
  {
    v9 = (Scaleform::Render::D3D1x::SysVertexFormat *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(
                                                        Scaleform::Memory::pGlobalHeap,
                                                        288i64,
                                                        0i64);
    if ( v9 )
    {
      Scaleform::Render::D3D1x::SysVertexFormat::SysVertexFormat(
        v9,
        this->pHal->pDevice,
        pformat,
        this->CurShaders.pVS->pDesc);
      v11 = v10;
    }
    else
    {
      v11 = 0i64;
    }
    pObject = (Scaleform::Render::RenderBuffer *)pformat->pSysFormat.pObject;
    if ( pObject )
      Scaleform::RefCountImpl::Release(pObject);
    pformat->pSysFormat.pObject = v11;
  }
  pVS = this->CurShaders.pVS;
  result = 0;
  if ( pVS )
  {
    pFS = this->CurShaders.pFS;
    if ( pFS )
    {
      if ( pVS->pProg.pObject && pFS->pProg.pObject && this->CurShaders.pVFormat )
        return 1;
    }
  }
  return result;
}

// File Line: 181
// RVA: 0xA0A570
void __fastcall Scaleform::Render::D3D1x::ShaderInterface::SetTexture(
        Scaleform::Render::D3D1x::ShaderInterface *this,
        Scaleform::Render::D3D1x::ShaderPair *__formal,
        unsigned int var,
        Scaleform::Render::Texture *ptexture,
        __int64 fm,
        unsigned int index)
{
  ((void (__fastcall *)(Scaleform::Render::Texture *, _QWORD, __int64))ptexture->vfptr[12].__vecDelDtor)(
    ptexture,
    index + this->CurShaders.pFDesc->Uniforms[var].Location,
    fm);
}

// File Line: 226
// RVA: 0xA09530
void __fastcall Scaleform::Render::D3D1x::ShaderInterface::Finish(
        Scaleform::Render::D3D1x::ShaderInterface *this,
        unsigned int meshCount)
{
  _GUID *v2; // rdx
  __int64 v3; // r14
  __int64 v5; // rsi
  __int64 i; // rdi
  unsigned __int64 v7; // r15
  Scaleform::Render::D3D1x::UniformVar *v8; // rcx
  __int64 v9; // r12
  __int64 Size; // r13
  ID3D11DeviceContext *v11; // rcx
  IUnknownVtbl *v12; // r10
  float *v13; // rdx
  __int64 v14; // rax
  Scaleform::Render::D3D1x::UniformVar *Uniforms; // rcx
  __int64 ShadowOffset; // r12
  ID3D11DeviceContext *pDeviceContext; // rcx
  IUnknownVtbl *vfptr; // r10
  ID3D11DeviceContext *v19; // rdi
  ID3D11VertexShader *pObject; // rdx
  Scaleform::Render::SystemVertexFormat *v21; // rcx
  ID3D11InputLayout *v22; // rsi
  ID3D11PixelShader *v23; // rdx
  Scaleform::Render::D3D1x::ShaderInterface *v24; // [rsp+18h] [rbp-19h]
  __int64 v25; // [rsp+20h] [rbp-11h] BYREF
  __int64 *v26; // [rsp+28h] [rbp-9h]
  ID3D11Buffer *NextConstantBuffer; // [rsp+30h] [rbp-1h] BYREF
  Scaleform::Render::D3D1x::HAL *v28; // [rsp+38h] [rbp+7h]
  Scaleform::Render::D3D1x::ShaderInterface *v29; // [rsp+40h] [rbp+Fh]
  __int64 v30; // [rsp+48h] [rbp+17h] BYREF
  _GUID *v31; // [rsp+58h] [rbp+27h] BYREF
  Scaleform::Render::D3D1x::HAL *pHal; // [rsp+60h] [rbp+2Fh]

  v2 = 0i64;
  v3 = 0i64;
  pHal = this->pHal;
  v28 = pHal;
  this->PrimitiveOpen = 0;
  v29 = this;
  v31 = 0i64;
  v24 = this;
  NextConstantBuffer = 0i64;
  v5 = 0i64;
  for ( i = 16i64; i < 120; i += 4i64 )
  {
    if ( !this->UniformSet[v3] )
      goto LABEL_12;
    v7 = *(int *)((char *)&this->CurShaders.pFS->pProg.pObject + i);
    if ( (v7 & 0x80000000) != 0i64 )
    {
      v7 = *(int *)((char *)&this->CurShaders.pVS->pDesc + i);
      if ( (v7 & 0x80000000) != 0i64 )
        goto LABEL_12;
      Uniforms = this->CurShaders.pVDesc->Uniforms;
      ShadowOffset = Uniforms[v5].ShadowOffset;
      Size = Uniforms[v5].Size;
      if ( !v2 )
      {
        NextConstantBuffer = Scaleform::Render::D3D1x::HAL::getNextConstantBuffer(v28);
        pDeviceContext = v28->pDeviceContext;
        v26 = &v25;
        vfptr = pDeviceContext->vfptr;
        LODWORD(v25) = 0;
        ((void (__fastcall *)(ID3D11DeviceContext *, ID3D11Buffer *, _QWORD, __int64))vfptr[4].Release)(
          pDeviceContext,
          NextConstantBuffer,
          0i64,
          4i64);
      }
      v13 = &v24->UniformData[ShadowOffset];
      v14 = v25;
    }
    else
    {
      v8 = this->CurShaders.pFDesc->Uniforms;
      v9 = v8[v5].ShadowOffset;
      Size = v8[v5].Size;
      if ( !v31 )
      {
        v31 = (_GUID *)Scaleform::Render::D3D1x::HAL::getNextConstantBuffer(pHal);
        v11 = pHal->pDeviceContext;
        v26 = &v30;
        v12 = v11->vfptr;
        LODWORD(v25) = 0;
        ((void (__fastcall *)(ID3D11DeviceContext *, _GUID *, _QWORD, __int64))v12[4].Release)(v11, v31, 0i64, 4i64);
      }
      v13 = &v29->UniformData[v9];
      v14 = v30;
    }
    memmove((void *)(v14 + 4 * (v7 >> 2)), v13, 4 * Size);
    v2 = (_GUID *)NextConstantBuffer;
LABEL_12:
    ++v3;
    ++v5;
  }
  if ( v2 )
  {
    v28->pDeviceContext->vfptr[5].QueryInterface(v28->pDeviceContext, v2, 0i64);
    ((void (__fastcall *)(ID3D11DeviceContext *, _QWORD, __int64, ID3D11Buffer **))v28->pDeviceContext->vfptr[2].AddRef)(
      v28->pDeviceContext,
      0i64,
      1i64,
      &NextConstantBuffer);
  }
  if ( v31 )
  {
    pHal->pDeviceContext->vfptr[5].QueryInterface(pHal->pDeviceContext, v31, 0i64);
    ((void (__fastcall *)(ID3D11DeviceContext *, _QWORD, __int64, _GUID **))pHal->pDeviceContext->vfptr[5].AddRef)(
      pHal->pDeviceContext,
      0i64,
      1i64,
      &v31);
  }
  *(_QWORD *)this->UniformSet = 0i64;
  *(_QWORD *)&this->UniformSet[8] = 0i64;
  *(_QWORD *)&this->UniformSet[16] = 0i64;
  *(_WORD *)&this->UniformSet[24] = 0;
  v19 = this->pHal->pDeviceContext;
  pObject = this->CurShaders.pVS->pProg.pObject;
  if ( this->pLastVS != pObject )
  {
    ((void (__fastcall *)(ID3D11DeviceContext *, ID3D11VertexShader *, _QWORD, _QWORD))v19->vfptr[3].Release)(
      this->pHal->pDeviceContext,
      pObject,
      0i64,
      0i64);
    this->pLastVS = this->CurShaders.pVS->pProg.pObject;
  }
  v21 = this->CurShaders.pVFormat->pSysFormat.pObject;
  v22 = (ID3D11InputLayout *)v21[1].vfptr;
  if ( this->pLastDecl != v22 )
  {
    ((void (__fastcall *)(ID3D11DeviceContext *, Scaleform::RefCountImplCoreVtbl *))v19->vfptr[5].Release)(
      v19,
      v21[1].vfptr);
    this->pLastDecl = v22;
  }
  v23 = this->CurShaders.pFS->pProg.pObject;
  if ( this->pLastFS != v23 )
  {
    ((void (__fastcall *)(ID3D11DeviceContext *, ID3D11PixelShader *, _QWORD, _QWORD))v19->vfptr[3].QueryInterface)(
      v19,
      v23,
      0i64,
      0i64);
    this->pLastFS = this->CurShaders.pFS->pProg.pObject;
  }
}

// File Line: 277
// RVA: 0xA093A0
void __fastcall Scaleform::Render::D3D1x::ShaderInterface::BeginScene(Scaleform::Render::D3D1x::ShaderInterface *this)
{
  ID3D11DeviceContext *pDeviceContext; // rbx

  pDeviceContext = this->pHal->pDeviceContext;
  ((void (__fastcall *)(ID3D11DeviceContext *, _QWORD, _QWORD, _QWORD))pDeviceContext->vfptr[23].QueryInterface)(
    pDeviceContext,
    0i64,
    0i64,
    0i64);
  ((void (__fastcall *)(ID3D11DeviceContext *, _QWORD, _QWORD, _QWORD))pDeviceContext->vfptr[21].AddRef)(
    pDeviceContext,
    0i64,
    0i64,
    0i64);
  ((void (__fastcall *)(ID3D11DeviceContext *, _QWORD, _QWORD, _QWORD))pDeviceContext->vfptr[7].Release)(
    pDeviceContext,
    0i64,
    0i64,
    0i64);
  ((void (__fastcall *)(ID3D11DeviceContext *, _QWORD, _QWORD, _QWORD))pDeviceContext->vfptr[20].QueryInterface)(
    pDeviceContext,
    0i64,
    0i64,
    0i64);
  this->pLastVS = 0i64;
  this->pLastDecl = 0i64;
  this->pLastFS = 0i64;
}

// File Line: 293
// RVA: 0xA08EB0
void __fastcall Scaleform::Render::D3D1x::ShaderManager::ShaderManager(
        Scaleform::Render::D3D1x::ShaderManager *this,
        Scaleform::Render::ProfileViews *prof)
{
  this->vfptr = (Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>Vtbl *)&Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::`vftable;
  this->VFormats.KeyBuffer.pPages = 0i64;
  this->VFormats.KeyBuffer.pLast = 0i64;
  this->VFormats.ValueBuffer.pPages = 0i64;
  this->VFormats.ValueBuffer.pLast = 0i64;
  this->Profiler = prof;
  this->VertexFormatComputedHash.mHash.pTable = 0i64;
  this->vfptr = (Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>Vtbl *)&Scaleform::Render::D3D1x::ShaderManager::`vftable;
  `eh vector constructor iterator(
    this->StaticFShaders,
    0x80ui64,
    1471,
    (void (__fastcall *)(void *))Scaleform::Render::D3D1x::FragShader::FragShader);
  `eh vector constructor iterator(
    this->StaticVShaders,
    0x78ui64,
    511,
    (void (__fastcall *)(void *))Scaleform::Render::D3D1x::VertexShader::VertexShader);
  this->pDevice.pObject = 0i64;
  this->ShaderModel = ShaderVersion_D3D9SM20;
  memset(this->StaticVShaders, 0, sizeof(this->StaticVShaders));
  memset(this->StaticFShaders, 0, sizeof(this->StaticFShaders));
}

// File Line: 299
// RVA: 0xA09840
bool __fastcall Scaleform::Render::D3D1x::ShaderManager::HasInstancingSupport(
        Scaleform::Render::D3D1x::ShaderManager *this)
{
  return this->ShaderModel >= ShaderVersion_Count;
}

// File Line: 312
// RVA: 0xA0A1B0
void __fastcall Scaleform::Render::D3D1x::ShaderManager::MapVertexFormat(
        Scaleform::Render::D3D1x::ShaderManager *this,
        unsigned int fill,
        Scaleform::Render::VertexFormat *sourceFormat,
        Scaleform::Render::VertexFormat **single,
        Scaleform::Render::VertexFormat **batch,
        Scaleform::Render::VertexFormat **instanced)
{
  int v9; // ebx
  int v10; // r9d
  __int64 v11; // r10
  Scaleform::Render::VertexElement *pElements; // r11
  $3C54659889F1EB765F9D24AEEC355797 *v13; // rax
  Scaleform::Render::VertexElement *v14; // rcx
  __int64 v15; // r8
  unsigned int Attribute; // edx
  unsigned int v17; // edx
  Scaleform::Render::VertexFormat sourceFormata; // [rsp+48h] [rbp-60h] BYREF
  __int64 v19[8]; // [rsp+60h] [rbp-48h] BYREF

  v9 = 0;
  sourceFormata.pElements = (Scaleform::Render::VertexElement *)v19;
  sourceFormata.pSysFormat.pObject = 0i64;
  v10 = 0;
  LODWORD(v11) = 0;
  pElements = sourceFormat->pElements;
  v13 = &pElements->4;
  if ( pElements->Attribute )
  {
    v14 = sourceFormat->pElements;
    v15 = 0i64;
    do
    {
      Attribute = v13->Attribute;
      HIDWORD(v19[v15]) = ($3C54659889F1EB765F9D24AEEC355797)v13->Attribute;
      if ( (Attribute & 0xF00) == 256 )
      {
        v17 = Attribute & 0xFFFFFF0F | 0x60;
        HIDWORD(v19[v15]) = v17;
        LODWORD(v19[v15]) = v10 + v14->Offset;
        if ( (v17 & 0xF0) == 48 )
          v10 += 4;
      }
      else
      {
        LODWORD(v19[v15]) = v10 + v14->Offset;
      }
      v11 = (unsigned int)(v11 + 1);
      v15 = v11;
      v14 = &pElements[v11];
      v13 = &v14->4;
    }
    while ( v14->Attribute );
  }
  v19[(unsigned int)v11] = 0i64;
  if ( this->ShaderModel >= ShaderVersion_Count )
    v9 = 8;
  Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::MapVertexFormat(
    this,
    fill,
    &sourceFormata,
    single,
    batch,
    instanced,
    v9 | 3);
  if ( sourceFormata.pSysFormat.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)sourceFormata.pSysFormat.pObject);
}

// File Line: 347
// RVA: 0xA09970
bool __fastcall Scaleform::Render::D3D1x::ShaderManager::Initialize(
        Scaleform::Render::D3D1x::ShaderManager *this,
        Scaleform::Render::D3D1x::HAL *phal)
{
  ID3D11Device *pDevice; // rdi
  ID3D11Device *pObject; // rcx
  int v5; // eax
  unsigned int v6; // edi
  bool result; // al
  Scaleform::Render::D3D1x::VertexShaderDesc **v8; // r14
  unsigned int v9; // esi
  Scaleform::Render::D3D1x::VertexShaderDesc *v10; // r8
  Scaleform::Render::D3D1x::FragShaderDesc **i; // rsi
  Scaleform::Render::D3D1x::FragShaderDesc *v12; // r8

  pDevice = phal->pDevice;
  if ( pDevice )
    ((void (__fastcall *)(ID3D11Device *))pDevice->vfptr->AddRef)(phal->pDevice);
  pObject = this->pDevice.pObject;
  if ( pObject )
    ((void (__fastcall *)(ID3D11Device *))pObject->vfptr->Release)(pObject);
  this->pDevice.pObject = pDevice;
  this->ShaderModel = ShaderVersion_Count|ShaderVersion_D3D9SM30;
  v5 = ((__int64 (__fastcall *)(ID3D11Device *))pDevice->vfptr->GenerateMips)(pDevice);
  v6 = 0;
  if ( ((v5 - 37120) & 0xFFFFFEFF) != 0 )
  {
    if ( v5 == 37632 )
    {
      this->ShaderModel = ShaderVersion_D3D9SM30;
    }
    else if ( ((v5 - 40960) & 0xFFFFFEFF) == 0 )
    {
      this->ShaderModel = ShaderVersion_Count;
    }
  }
  else
  {
    this->ShaderModel = ShaderVersion_D3D9SM20;
  }
  if ( this->ShaderModel == (ShaderVersion_Count|ShaderVersion_D3D9SM30)
    && !Scaleform::Render::D3D1x::ShaderDesc::IsShaderVersionSupported(ShaderVersion_Count|ShaderVersion_D3D9SM30) )
  {
    this->ShaderModel = ShaderVersion_Count;
  }
  if ( this->ShaderModel == ShaderVersion_Count
    && !Scaleform::Render::D3D1x::ShaderDesc::IsShaderVersionSupported(ShaderVersion_Count) )
  {
    this->ShaderModel = ShaderVersion_D3D9SM30;
  }
  if ( this->ShaderModel == ShaderVersion_D3D9SM30
    && !Scaleform::Render::D3D1x::ShaderDesc::IsShaderVersionSupported(ShaderVersion_D3D9SM30) )
  {
    this->ShaderModel = ShaderVersion_D3D9SM20;
  }
  if ( this->ShaderModel
    || (result = Scaleform::Render::D3D1x::ShaderDesc::IsShaderVersionSupported(ShaderVersion_D3D9SM20)) )
  {
    v8 = Scaleform::Render::D3D1x::VertexShaderDesc::Descs;
    v9 = 0;
    while ( 1 )
    {
      v10 = *v8;
      if ( *v8 )
      {
        if ( v10->Version == this->ShaderModel
          && v10->pBinary
          && !Scaleform::Render::D3D1x::VertexShader::Init(&this->StaticVShaders[v9], this->pDevice.pObject, v10) )
        {
          break;
        }
      }
      ++v9;
      ++v8;
      if ( v9 >= 0x1FF )
      {
        for ( i = Scaleform::Render::D3D1x::FragShaderDesc::Descs; ; ++i )
        {
          v12 = *i;
          if ( *i )
          {
            if ( v12->Version == this->ShaderModel
              && v12->pBinary
              && !Scaleform::Render::D3D1x::FragShader::Init(
                    &this->StaticFShaders[(unsigned __int64)v6],
                    this->pDevice.pObject,
                    v12) )
            {
              break;
            }
          }
          if ( ++v6 >= 0x5BF )
            return 1;
        }
        return 0;
      }
    }
    return 0;
  }
  return result;
}

// File Line: 457
// RVA: 0xA0A300
void __fastcall Scaleform::Render::D3D1x::ShaderManager::Reset(Scaleform::Render::D3D1x::ShaderManager *this)
{
  Scaleform::Render::D3D1x::VertexShaderDesc **v2; // rdi
  Scaleform::Ptr<ID3D11VertexShader> *p_pProg; // rbx
  __int64 v4; // rsi
  Scaleform::Render::D3D1x::FragShaderDesc **v5; // rdi
  Scaleform::Ptr<ID3D11PixelShader> *v6; // rbx
  __int64 v7; // rsi
  ID3D11Device *pObject; // rcx
  Scaleform::Render::PagedItemBuffer<Scaleform::Render::VertexElement,32>::Page *pPages; // rbx
  Scaleform::Render::PagedItemBuffer<Scaleform::Render::VertexElement,32>::Page *v10; // rdx

  v2 = Scaleform::Render::D3D1x::VertexShaderDesc::Descs;
  p_pProg = &this->StaticVShaders[0].pProg;
  v4 = 511i64;
  do
  {
    if ( *v2 && (*v2)->pBinary )
    {
      if ( p_pProg->pObject )
        p_pProg->pObject->vfptr->Release(p_pProg->pObject);
      p_pProg->pObject = 0i64;
    }
    ++v2;
    p_pProg += 15;
    --v4;
  }
  while ( v4 );
  v5 = Scaleform::Render::D3D1x::FragShaderDesc::Descs;
  v6 = &this->StaticFShaders[0].pProg;
  v7 = 1471i64;
  do
  {
    if ( *v5 && (*v5)->pBinary )
    {
      if ( v6->pObject )
        v6->pObject->vfptr->Release(v6->pObject);
      v6->pObject = 0i64;
    }
    ++v5;
    v6 += 16;
    --v7;
  }
  while ( v7 );
  pObject = this->pDevice.pObject;
  if ( pObject )
    ((void (__fastcall *)(ID3D11Device *))pObject->vfptr->Release)(pObject);
  this->pDevice.pObject = 0i64;
  pPages = this->VFormats.KeyBuffer.pPages;
  v10 = 0i64;
  if ( pPages )
  {
    do
    {
      if ( v10 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      v10 = pPages;
      pPages = pPages->pNext;
    }
    while ( pPages );
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  }
  this->VFormats.KeyBuffer.pPages = 0i64;
  this->VFormats.KeyBuffer.pLast = 0i64;
  Scaleform::Render::PagedItemBuffer<Scaleform::Render::MultiKeyCollection<Scaleform::Render::VertexElement,Scaleform::Render::VertexFormat,32,8>::ValueItem,8>::freePages(
    &this->VFormats.ValueBuffer,
    0);
}

