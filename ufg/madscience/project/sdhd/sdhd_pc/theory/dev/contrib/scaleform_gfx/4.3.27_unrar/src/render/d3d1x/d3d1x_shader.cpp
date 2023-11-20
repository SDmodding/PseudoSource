// File Line: 25
// RVA: 0xA098E0
char __fastcall Scaleform::Render::D3D1x::VertexShader::Init(Scaleform::Render::D3D1x::VertexShader *this, ID3D11Device *pdevice, Scaleform::Render::D3D1x::VertexShaderDesc *pd)
{
  Scaleform::Render::D3D1x::VertexShaderDesc *v3; // rbx
  Scaleform::Render::D3D1x::VertexShader *v4; // rdi
  __int64 v6; // r8
  signed __int64 v7; // rax
  signed __int64 v8; // r9

  v3 = pd;
  this->pDesc = pd;
  v4 = this;
  if ( ((signed int (__fastcall *)(ID3D11Device *, const char *, _QWORD, _QWORD, Scaleform::Ptr<ID3D11VertexShader> *))pdevice->vfptr->IASetVertexBuffers)(
         pdevice,
         pd->pBinary,
         pd->BinarySize,
         0i64,
         &this->pProg) < 0 )
    return 0;
  v6 = 0i64;
  v7 = (signed __int64)&v4->UniformOffset[1];
  v8 = 13i64;
  do
  {
    v7 += 8i64;
    v6 += 2i64;
    *(_DWORD *)(v7 - 12) = 16 * v3->Uniforms[v6 - 2].Location;
    *(_DWORD *)(v7 - 8) = 16 * v3->Uniforms[v6 - 1].Location;
    --v8;
  }
  while ( v8 );
  return 1;
}

// File Line: 71
// RVA: 0xA09850
char __fastcall Scaleform::Render::D3D1x::FragShader::Init(Scaleform::Render::D3D1x::FragShader *this, ID3D11Device *pdevice, Scaleform::Render::D3D1x::FragShaderDesc *pd)
{
  Scaleform::Render::D3D1x::FragShaderDesc *v3; // rbx
  Scaleform::Render::D3D1x::FragShader *v4; // rdi
  __int64 v6; // r8
  signed __int64 v7; // rax
  signed __int64 v8; // r9

  v3 = pd;
  this->pDesc = pd;
  v4 = this;
  if ( ((signed int (__fastcall *)(ID3D11Device *, const char *, _QWORD, _QWORD, Scaleform::Ptr<ID3D11PixelShader> *))pdevice->vfptr->DrawInstanced)(
         pdevice,
         pd->pBinary,
         pd->BinarySize,
         0i64,
         &this->pProg) < 0 )
    return 0;
  v6 = 0i64;
  v7 = (signed __int64)&v4->UniformOffset[1];
  v8 = 13i64;
  do
  {
    v7 += 8i64;
    v6 += 2i64;
    *(_DWORD *)(v7 - 12) = 16 * v3->Uniforms[v6 - 2].Location;
    *(_DWORD *)(v7 - 8) = 16 * v3->Uniforms[v6 - 1].Location;
    --v8;
  }
  while ( v8 );
  return 1;
}

// File Line: 113
// RVA: 0xA0A5A0
void __fastcall Scaleform::Render::D3D1x::VertexShader::Shutdown(Scaleform::Render::D3D1x::VertexShader *this)
{
  Scaleform::Render::D3D1x::VertexShader *v1; // rbx
  ID3D11VertexShader *v2; // rcx

  v1 = this;
  v2 = this->pProg.pObject;
  if ( v2 )
    ((void (*)(void))v2->vfptr->Release)();
  v1->pProg.pObject = 0i64;
}

// File Line: 138
// RVA: 0xA08FA0
void __fastcall Scaleform::Render::D3D1x::SysVertexFormat::SysVertexFormat(Scaleform::Render::D3D1x::SysVertexFormat *this, ID3D11Device *pdevice, Scaleform::Render::VertexFormat *vf, Scaleform::Render::D3D1x::VertexShaderDesc *pvdesc)
{
  Scaleform::Render::D3D1x::VertexShaderDesc *v4; // rbp
  ID3D11Device *v5; // r15
  Scaleform::Render::D3D1x::SysVertexFormat *v6; // rsi
  Scaleform::Ptr<ID3D11InputLayout> *v7; // r14
  $3C54659889F1EB765F9D24AEEC355797 *v8; // rcx
  unsigned int i; // eax
  unsigned __int16 v10; // di
  unsigned int v11; // eax
  int *v12; // r9
  __int64 v13; // r10
  int v14; // er8
  int v15; // edx
  __int64 v16; // rcx
  unsigned __int64 v17; // rax
  D3D11_INPUT_ELEMENT_DESC *v18; // rbx
  __int64 *v19; // rcx
  signed __int64 v20; // rax
  __int64 Src; // [rsp+40h] [rbp-138h]
  int v22; // [rsp+48h] [rbp-130h]
  int v23; // [rsp+4Ch] [rbp-12Ch]
  int v24; // [rsp+50h] [rbp-128h]
  int v25; // [rsp+54h] [rbp-124h]
  __int64 v26[29]; // [rsp+58h] [rbp-120h]
  unsigned __int16 v27; // [rsp+140h] [rbp-38h]

  v4 = pvdesc;
  v5 = pdevice;
  v6 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::Render::SystemVertexFormat,2>::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::SystemVertexFormat::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::D3D1x::SysVertexFormat::`vftable';
  v7 = &this->pVDecl;
  this->pVDecl.pObject = 0i64;
  v8 = &vf->pElements->4;
  for ( i = v8->Attribute; v8->Attribute; i = v8->Attribute )
  {
    if ( (i & 0xF00) == 256 )
      break;
    v8 += 2;
  }
  v10 = 0;
  v27 = 0;
  v11 = pvdesc->NumAttribs;
  if ( (signed int)v11 > 0 )
  {
    v12 = (int *)&pvdesc->Attributes[0].SemanticIndex;
    v13 = v11;
    do
    {
      v14 = v12[1];
      v15 = *v12;
      v16 = *((_QWORD *)v12 - 1);
      v17 = 32i64 * v10;
      v27 = v10 + 1;
      *(__int64 *)((char *)&Src + v17) = v16;
      *(int *)((char *)&v22 + v17) = v15;
      *(int *)((char *)&v23 + v17) = v14;
      *(int *)((char *)&v24 + v17) = 0;
      *(int *)((char *)&v25 + v17) = -1;
      v26[v17 / 8] = 0i64;
      v12 += 8;
      v10 = v27;
      --v13;
    }
    while ( v13 );
  }
  v18 = v6->VertexElements;
  memmove(v6->VertexElements, &Src, 32i64 * v10);
  v6->VertexElementCount = v10;
  if ( ((signed int (__fastcall *)(ID3D11Device *, __int64 *, _QWORD, const char *, _QWORD, Scaleform::Ptr<ID3D11InputLayout> *, signed __int64))v5->vfptr->IASetInputLayout)(
         v5,
         &Src,
         v10,
         v4->pBinary,
         v4->BinarySize,
         v7,
         -2i64) < 0 )
  {
    if ( v7->pObject )
      ((void (*)(void))v7->pObject->vfptr->Release)();
    v7->pObject = 0i64;
  }
  v19 = &Src;
  if ( ((unsigned __int8)v18 | (unsigned __int8)&Src) & 0xF )
  {
    memmove(v6->VertexElements, &Src, 0x100ui64);
  }
  else
  {
    v20 = 2i64;
    do
    {
      *(_OWORD *)&v18->SemanticName = *(_OWORD *)v19;
      *(_OWORD *)&v18->InputSlot = *((_OWORD *)v19 + 1);
      *(_OWORD *)&v18[1].SemanticName = *((_OWORD *)v19 + 2);
      *(_OWORD *)&v18[1].InputSlot = *((_OWORD *)v19 + 3);
      *(_OWORD *)&v18[2].SemanticName = *((_OWORD *)v19 + 4);
      *(_OWORD *)&v18[2].InputSlot = *((_OWORD *)v19 + 5);
      *(_OWORD *)&v18[3].SemanticName = *((_OWORD *)v19 + 6);
      v18 += 4;
      *(_OWORD *)&v18[-1].InputSlot = *((_OWORD *)v19 + 7);
      v19 += 16;
      --v20;
    }
    while ( v20 );
  }
}

// File Line: 167
// RVA: 0xA0A420
bool __fastcall Scaleform::Render::D3D1x::ShaderInterface::SetStaticShader(Scaleform::Render::D3D1x::ShaderInterface *this, Scaleform::Render::D3D1x::ShaderDesc::ShaderType shader, Scaleform::Render::VertexFormat *pformat)
{
  Scaleform::Render::VertexFormat *v3; // rbp
  Scaleform::Render::D3D1x::ShaderDesc::ShaderType v4; // edi
  Scaleform::Render::D3D1x::ShaderInterface *v5; // rsi
  Scaleform::Render::D3D1x::HAL *v6; // rbx
  Scaleform::Render::D3D1x::VertexShader *v7; // rax
  Scaleform::Render::D3D1x::FragShader *v8; // rax
  Scaleform::Render::D3D1x::SysVertexFormat *v9; // rax
  Scaleform::Render::SystemVertexFormat *v10; // rax
  Scaleform::Render::SystemVertexFormat *v11; // rbx
  Scaleform::Render::RenderBuffer *v12; // rcx
  Scaleform::Render::D3D1x::VertexShader *v13; // rax
  Scaleform::Render::D3D1x::FragShader *v14; // rcx
  bool result; // al

  v3 = pformat;
  v4 = shader;
  v5 = this;
  this->CurShaders.pVFormat = pformat;
  v6 = this->pHal;
  v7 = &v6->SManager.StaticVShaders[Scaleform::Render::D3D1x::VertexShaderDesc::GetShaderIndex(
                                      shader,
                                      v6->SManager.ShaderModel)];
  v5->CurShaders.pVS = v7;
  v5->CurShaders.pVDesc = v7->pDesc;
  v8 = &v5->pHal->SManager.StaticFShaders[(signed __int64)(signed int)Scaleform::Render::D3D1x::FragShaderDesc::GetShaderIndex(
                                                                        v4,
                                                                        v6->SManager.ShaderModel)];
  v5->CurShaders.pFS = v8;
  v5->CurShaders.pFDesc = v8->pDesc;
  if ( v3 && !v3->pSysFormat.pObject )
  {
    v9 = (Scaleform::Render::D3D1x::SysVertexFormat *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(
                                                        Scaleform::Memory::pGlobalHeap,
                                                        288ui64,
                                                        0i64);
    if ( v9 )
    {
      Scaleform::Render::D3D1x::SysVertexFormat::SysVertexFormat(v9, v5->pHal->pDevice, v3, v5->CurShaders.pVS->pDesc);
      v11 = v10;
    }
    else
    {
      v11 = 0i64;
    }
    v12 = (Scaleform::Render::RenderBuffer *)v3->pSysFormat.pObject;
    if ( v12 )
      Scaleform::RefCountImpl::Release(v12);
    v3->pSysFormat.pObject = v11;
  }
  v13 = v5->CurShaders.pVS;
  result = 0;
  if ( v13 )
  {
    v14 = v5->CurShaders.pFS;
    if ( v14 )
    {
      if ( v13->pProg.pObject && v14->pProg.pObject && v5->CurShaders.pVFormat )
        result = 1;
    }
  }
  return result;
}

// File Line: 181
// RVA: 0xA0A570
void __fastcall Scaleform::Render::D3D1x::ShaderInterface::SetTexture(Scaleform::Render::D3D1x::ShaderInterface *this, Scaleform::Render::D3D1x::ShaderPair *__formal, unsigned int var, Scaleform::Render::Texture *ptexture, __int64 fm, unsigned int index)
{
  ((void (__fastcall *)(Scaleform::Render::Texture *, _QWORD, __int64))ptexture->vfptr[12].__vecDelDtor)(
    ptexture,
    index + this->CurShaders.pFDesc->Uniforms[var].Location,
    fm);
}

// File Line: 226
// RVA: 0xA09530
void __fastcall Scaleform::Render::D3D1x::ShaderInterface::Finish(Scaleform::Render::D3D1x::ShaderInterface *this, unsigned int meshCount)
{
  _GUID *v2; // rdx
  __int64 v3; // r14
  Scaleform::Render::D3D1x::ShaderInterface *v4; // rbx
  __int64 v5; // rsi
  signed __int64 v6; // rdi
  unsigned __int64 v7; // r15
  Scaleform::Render::D3D1x::UniformVar *v8; // rcx
  __int64 v9; // r12
  __int64 v10; // r13
  ID3D11DeviceContext *v11; // rcx
  IUnknownVtbl *v12; // r10
  float *v13; // rdx
  __int64 v14; // rax
  Scaleform::Render::D3D1x::UniformVar *v15; // rcx
  __int64 v16; // r12
  ID3D11DeviceContext *v17; // rcx
  IUnknownVtbl *v18; // r10
  ID3D11DeviceContext *v19; // rdi
  ID3D11VertexShader *v20; // rdx
  Scaleform::Render::SystemVertexFormat *v21; // rcx
  ID3D11InputLayout *v22; // rsi
  ID3D11PixelShader *v23; // rdx
  Scaleform::Render::D3D1x::ShaderInterface *v24; // [rsp+18h] [rbp-19h]
  __int64 v25; // [rsp+20h] [rbp-11h]
  __int64 *v26; // [rsp+28h] [rbp-9h]
  ID3D11Buffer *v27; // [rsp+30h] [rbp-1h]
  Scaleform::Render::D3D1x::HAL *v28; // [rsp+38h] [rbp+7h]
  Scaleform::Render::D3D1x::ShaderInterface *v29; // [rsp+40h] [rbp+Fh]
  __int64 v30; // [rsp+48h] [rbp+17h]
  _GUID *v31; // [rsp+58h] [rbp+27h]
  Scaleform::Render::D3D1x::HAL *v32; // [rsp+60h] [rbp+2Fh]

  v2 = 0i64;
  v3 = 0i64;
  v32 = this->pHal;
  v28 = v32;
  v4 = this;
  this->PrimitiveOpen = 0;
  v29 = this;
  v31 = 0i64;
  v24 = this;
  v27 = 0i64;
  v5 = 0i64;
  v6 = 16i64;
  do
  {
    if ( !v4->UniformSet[v3] )
      goto LABEL_12;
    v7 = *(signed int *)((char *)&v4->CurShaders.pFS->pProg.pObject + v6);
    if ( (v7 & 0x80000000) != 0i64 )
    {
      v7 = *(signed int *)((char *)&v4->CurShaders.pVS->pDesc + v6);
      if ( (v7 & 0x80000000) != 0i64 )
        goto LABEL_12;
      v15 = v4->CurShaders.pVDesc->Uniforms;
      v16 = v15[v5].ShadowOffset;
      v10 = v15[v5].Size;
      if ( !v2 )
      {
        v27 = Scaleform::Render::D3D1x::HAL::getNextConstantBuffer(v28);
        v17 = v28->pDeviceContext;
        v26 = &v25;
        v18 = v17->vfptr;
        LODWORD(v25) = 0;
        ((void (__fastcall *)(ID3D11DeviceContext *, ID3D11Buffer *, _QWORD, signed __int64))v18[4].Release)(
          v17,
          v27,
          0i64,
          4i64);
      }
      v13 = &v24->UniformData[v16];
      v14 = v25;
    }
    else
    {
      v8 = v4->CurShaders.pFDesc->Uniforms;
      v9 = v8[v5].ShadowOffset;
      v10 = v8[v5].Size;
      if ( !v31 )
      {
        v31 = (_GUID *)Scaleform::Render::D3D1x::HAL::getNextConstantBuffer(v32);
        v11 = v32->pDeviceContext;
        v26 = &v30;
        v12 = v11->vfptr;
        LODWORD(v25) = 0;
        ((void (__fastcall *)(ID3D11DeviceContext *, _GUID *, _QWORD, signed __int64))v12[4].Release)(
          v11,
          v31,
          0i64,
          4i64);
      }
      v13 = &v29->UniformData[v9];
      v14 = v30;
    }
    memmove((void *)(v14 + 4 * (v7 >> 2)), v13, 4 * v10);
    v2 = (_GUID *)v27;
LABEL_12:
    v6 += 4i64;
    ++v3;
    ++v5;
  }
  while ( v6 < 120 );
  if ( v2 )
  {
    v28->pDeviceContext->vfptr[5].QueryInterface((IUnknown *)v28->pDeviceContext, v2, 0i64);
    ((void (__fastcall *)(ID3D11DeviceContext *, _QWORD, signed __int64, ID3D11Buffer **))v28->pDeviceContext->vfptr[2].AddRef)(
      v28->pDeviceContext,
      0i64,
      1i64,
      &v27);
  }
  if ( v31 )
  {
    v32->pDeviceContext->vfptr[5].QueryInterface((IUnknown *)v32->pDeviceContext, v31, 0i64);
    ((void (__fastcall *)(ID3D11DeviceContext *, _QWORD, signed __int64, _GUID **))v32->pDeviceContext->vfptr[5].AddRef)(
      v32->pDeviceContext,
      0i64,
      1i64,
      &v31);
  }
  *(_QWORD *)v4->UniformSet = 0i64;
  *(_QWORD *)&v4->UniformSet[8] = 0i64;
  *(_QWORD *)&v4->UniformSet[16] = 0i64;
  *(_WORD *)&v4->UniformSet[24] = 0;
  v19 = v4->pHal->pDeviceContext;
  v20 = v4->CurShaders.pVS->pProg.pObject;
  if ( v4->pLastVS != v20 )
  {
    ((void (__fastcall *)(ID3D11DeviceContext *, ID3D11VertexShader *, _QWORD, _QWORD))v19->vfptr[3].Release)(
      v4->pHal->pDeviceContext,
      v20,
      0i64,
      0i64);
    v4->pLastVS = v4->CurShaders.pVS->pProg.pObject;
  }
  v21 = v4->CurShaders.pVFormat->pSysFormat.pObject;
  v22 = (ID3D11InputLayout *)v21[1].vfptr;
  if ( v4->pLastDecl != v22 )
  {
    ((void (__fastcall *)(ID3D11DeviceContext *, Scaleform::RefCountImplCoreVtbl *))v19->vfptr[5].Release)(
      v19,
      v21[1].vfptr);
    v4->pLastDecl = v22;
  }
  v23 = v4->CurShaders.pFS->pProg.pObject;
  if ( v4->pLastFS != v23 )
  {
    ((void (__fastcall *)(ID3D11DeviceContext *, ID3D11PixelShader *, _QWORD, _QWORD))v19->vfptr[3].QueryInterface)(
      v19,
      v23,
      0i64,
      0i64);
    v4->pLastFS = v4->CurShaders.pFS->pProg.pObject;
  }
}

// File Line: 277
// RVA: 0xA093A0
void __fastcall Scaleform::Render::D3D1x::ShaderInterface::BeginScene(Scaleform::Render::D3D1x::ShaderInterface *this)
{
  Scaleform::Render::D3D1x::ShaderInterface *v1; // rdi
  ID3D11DeviceContext *v2; // rbx

  v1 = this;
  v2 = this->pHal->pDeviceContext;
  ((void (__fastcall *)(ID3D11DeviceContext *, _QWORD, _QWORD, _QWORD))v2->vfptr[23].QueryInterface)(
    this->pHal->pDeviceContext,
    0i64,
    0i64,
    0i64);
  ((void (__fastcall *)(ID3D11DeviceContext *, _QWORD, _QWORD, _QWORD))v2->vfptr[21].AddRef)(v2, 0i64, 0i64, 0i64);
  ((void (__fastcall *)(ID3D11DeviceContext *, _QWORD, _QWORD, _QWORD))v2->vfptr[7].Release)(v2, 0i64, 0i64, 0i64);
  ((void (__fastcall *)(ID3D11DeviceContext *, _QWORD, _QWORD, _QWORD))v2->vfptr[20].QueryInterface)(
    v2,
    0i64,
    0i64,
    0i64);
  v1->pLastVS = 0i64;
  v1->pLastDecl = 0i64;
  v1->pLastFS = 0i64;
}

// File Line: 293
// RVA: 0xA08EB0
void __fastcall Scaleform::Render::D3D1x::ShaderManager::ShaderManager(Scaleform::Render::D3D1x::ShaderManager *this, Scaleform::Render::ProfileViews *prof)
{
  Scaleform::Render::D3D1x::ShaderManager *v2; // rsi
  Scaleform::Render::MultiKeyCollection<Scaleform::Render::VertexElement,Scaleform::Render::VertexFormat,32,8> *v3; // rax

  v2 = this;
  this->vfptr = (Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>Vtbl *)&Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::`vftable';
  v3 = &this->VFormats;
  v3->KeyBuffer.pPages = 0i64;
  v3->KeyBuffer.pLast = 0i64;
  this->VFormats.ValueBuffer.pPages = 0i64;
  this->VFormats.ValueBuffer.pLast = 0i64;
  this->Profiler = prof;
  this->VertexFormatComputedHash.mHash.pTable = 0i64;
  this->vfptr = (Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>Vtbl *)&Scaleform::Render::D3D1x::ShaderManager::`vftable';
  `eh vector constructor iterator'(
    this->StaticFShaders,
    0x80ui64,
    1471,
    (void (__fastcall *)(void *))Scaleform::Render::D3D1x::FragShader::FragShader);
  `eh vector constructor iterator'(
    v2->StaticVShaders,
    0x78ui64,
    511,
    (void (__fastcall *)(void *))Scaleform::Render::D3D1x::VertexShader::VertexShader);
  v2->pDevice.pObject = 0i64;
  v2->ShaderModel = 0;
  memset(v2->StaticVShaders, 0, 0xEF88ui64);
  memset(v2->StaticFShaders, 0, 0x2DF80ui64);
}

// File Line: 299
// RVA: 0xA09840
bool __fastcall Scaleform::Render::D3D1x::ShaderManager::HasInstancingSupport(Scaleform::Render::D3D1x::ShaderManager *this)
{
  return this->ShaderModel >= 2;
}

// File Line: 312
// RVA: 0xA0A1B0
void __fastcall Scaleform::Render::D3D1x::ShaderManager::MapVertexFormat(Scaleform::Render::D3D1x::ShaderManager *this, Scaleform::Render::PrimitiveFillType fill, Scaleform::Render::VertexFormat *sourceFormat, Scaleform::Render::VertexFormat **single, Scaleform::Render::VertexFormat **batch, Scaleform::Render::VertexFormat **instanced)
{
  Scaleform::Render::VertexFormat **v6; // rbp
  Scaleform::Render::VertexFormat *v7; // rdi
  Scaleform::Render::PrimitiveFillType v8; // er14
  Scaleform::Render::D3D1x::ShaderManager *v9; // rsi
  signed int v10; // ebx
  int v12; // er9
  __int64 v13; // r10
  Scaleform::Render::VertexElement *v14; // r11
  $3C54659889F1EB765F9D24AEEC355797 *v15; // rax
  Scaleform::Render::VertexElement *v16; // rcx
  __int64 v17; // r8
  unsigned int v18; // edx
  unsigned int v19; // edx
  Scaleform::Render::VertexFormat sourceFormata; // [rsp+48h] [rbp-60h]
  __int64 v21[8]; // [rsp+60h] [rbp-48h]

  v6 = single;
  v7 = sourceFormat;
  v8 = fill;
  v9 = this;
  v10 = 0;
  sourceFormata.pElements = (Scaleform::Render::VertexElement *)v21;
  sourceFormata.pSysFormat.pObject = 0i64;
  v12 = 0;
  LODWORD(v13) = 0;
  v14 = v7->pElements;
  v15 = &v14->4;
  if ( v14->Attribute )
  {
    v16 = v7->pElements;
    v17 = 0i64;
    do
    {
      v18 = v15->Attribute;
      HIDWORD(v21[v17]) = ($3C54659889F1EB765F9D24AEEC355797)v15->Attribute;
      if ( (v18 & 0xF00) == 256 )
      {
        v19 = v18 & 0xFFFFFF6F | 0x60;
        HIDWORD(v21[v17]) = v19;
        LODWORD(v21[v17]) = v12 + v16->Offset;
        if ( (v19 & 0xF0) == 48 )
          v12 += 4;
      }
      else
      {
        LODWORD(v21[v17]) = v12 + v16->Offset;
      }
      v13 = (unsigned int)(v13 + 1);
      v17 = v13;
      v16 = &v14[v13];
      v15 = &v16->4;
    }
    while ( v16->Attribute );
  }
  v21[(unsigned int)v13] = 0i64;
  if ( v9->ShaderModel >= 2 )
    v10 = 8;
  Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::MapVertexFormat(
    (Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture> *)&v9->vfptr,
    (unsigned int)v8,
    &sourceFormata,
    v6,
    batch,
    instanced,
    v10 | 3);
  if ( sourceFormata.pSysFormat.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)sourceFormata.pSysFormat.pObject);
}

// File Line: 347
// RVA: 0xA09970
bool __fastcall Scaleform::Render::D3D1x::ShaderManager::Initialize(Scaleform::Render::D3D1x::ShaderManager *this, Scaleform::Render::D3D1x::HAL *phal)
{
  ID3D11Device *v2; // rdi
  Scaleform::Render::D3D1x::ShaderManager *v3; // rbx
  ID3D11Device *v4; // rcx
  int v5; // eax
  unsigned int v6; // edi
  bool result; // al
  Scaleform::Render::D3D1x::VertexShaderDesc **v8; // r14
  unsigned int v9; // esi
  Scaleform::Render::D3D1x::VertexShaderDesc *v10; // r8
  Scaleform::Render::D3D1x::FragShaderDesc **v11; // rsi
  Scaleform::Render::D3D1x::FragShaderDesc *v12; // r8

  v2 = phal->pDevice;
  v3 = this;
  if ( v2 )
    ((void (__fastcall *)(ID3D11Device *))v2->vfptr->AddRef)(phal->pDevice);
  v4 = v3->pDevice.pObject;
  if ( v4 )
    ((void (*)(void))v4->vfptr->Release)();
  v3->pDevice.pObject = v2;
  v3->ShaderModel = 3;
  v5 = ((__int64 (__fastcall *)(ID3D11Device *))v2->vfptr->GenerateMips)(v2);
  v6 = 0;
  if ( (v5 - 37120) & 0xFFFFFEFF )
  {
    if ( v5 == 37632 )
    {
      v3->ShaderModel = 1;
    }
    else if ( !((v5 - 40960) & 0xFFFFFEFF) )
    {
      v3->ShaderModel = 2;
    }
  }
  else
  {
    v3->ShaderModel = 0;
  }
  if ( v3->ShaderModel == 3
    && !Scaleform::Render::D3D1x::ShaderDesc::IsShaderVersionSupported(ShaderVersion_Count|ShaderVersion_D3D9SM30) )
  {
    v3->ShaderModel = 2;
  }
  if ( v3->ShaderModel == 2 && !Scaleform::Render::D3D1x::ShaderDesc::IsShaderVersionSupported(ShaderVersion_Count) )
    v3->ShaderModel = 1;
  if ( v3->ShaderModel == 1 && !Scaleform::Render::D3D1x::ShaderDesc::IsShaderVersionSupported(ShaderVersion_D3D9SM30) )
    v3->ShaderModel = 0;
  if ( v3->ShaderModel || (result = Scaleform::Render::D3D1x::ShaderDesc::IsShaderVersionSupported(0)) != 0 )
  {
    v8 = Scaleform::Render::D3D1x::VertexShaderDesc::Descs;
    v9 = 0;
    while ( 1 )
    {
      v10 = *v8;
      if ( *v8 )
      {
        if ( v10->Version == v3->ShaderModel
          && v10->pBinary
          && !Scaleform::Render::D3D1x::VertexShader::Init(&v3->StaticVShaders[v9], v3->pDevice.pObject, v10) )
        {
          break;
        }
      }
      ++v9;
      ++v8;
      if ( v9 >= 0x1FF )
      {
        v11 = Scaleform::Render::D3D1x::FragShaderDesc::Descs;
        while ( 1 )
        {
          v12 = *v11;
          if ( *v11 )
          {
            if ( v12->Version == v3->ShaderModel
              && v12->pBinary
              && !Scaleform::Render::D3D1x::FragShader::Init(
                    &v3->StaticFShaders[(unsigned __int64)v6],
                    v3->pDevice.pObject,
                    v12) )
            {
              break;
            }
          }
          ++v6;
          ++v11;
          if ( v6 >= 0x5BF )
            return 1;
        }
        break;
      }
    }
    result = 0;
  }
  return result;
}

// File Line: 457
// RVA: 0xA0A300
void __fastcall Scaleform::Render::D3D1x::ShaderManager::Reset(Scaleform::Render::D3D1x::ShaderManager *this)
{
  Scaleform::Render::D3D1x::ShaderManager *v1; // rbp
  Scaleform::Render::D3D1x::VertexShaderDesc **v2; // rdi
  Scaleform::Ptr<ID3D11VertexShader> *v3; // rbx
  signed __int64 v4; // rsi
  Scaleform::Render::D3D1x::FragShaderDesc **v5; // rdi
  signed __int64 v6; // rbx
  signed __int64 v7; // rsi
  ID3D11Device *v8; // rcx
  Scaleform::Render::PagedItemBuffer<Scaleform::Render::VertexElement,32>::Page *v9; // rbx
  Scaleform::Render::PagedItemBuffer<Scaleform::Render::VertexElement,32>::Page *v10; // rdx

  v1 = this;
  v2 = Scaleform::Render::D3D1x::VertexShaderDesc::Descs;
  v3 = &this->StaticVShaders[0].pProg;
  v4 = 511i64;
  do
  {
    if ( *v2 && (*v2)->pBinary )
    {
      if ( v3->pObject )
        ((void (*)(void))v3->pObject->vfptr->Release)();
      v3->pObject = 0i64;
    }
    ++v2;
    v3 += 15;
    --v4;
  }
  while ( v4 );
  v5 = Scaleform::Render::D3D1x::FragShaderDesc::Descs;
  v6 = (signed __int64)&v1->StaticFShaders[0].pProg;
  v7 = 1471i64;
  do
  {
    if ( *v5 && (*v5)->pBinary )
    {
      if ( *(_QWORD *)v6 )
        (*(void (**)(void))(**(_QWORD **)v6 + 16i64))();
      *(_QWORD *)v6 = 0i64;
    }
    ++v5;
    v6 += 128i64;
    --v7;
  }
  while ( v7 );
  v8 = v1->pDevice.pObject;
  if ( v8 )
    ((void (*)(void))v8->vfptr->Release)();
  v1->pDevice.pObject = 0i64;
  v9 = v1->VFormats.KeyBuffer.pPages;
  v10 = 0i64;
  if ( v9 )
  {
    do
    {
      if ( v10 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      v10 = v9;
      v9 = v9->pNext;
    }
    while ( v9 );
    if ( v10 )
    {
      ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      v10 = 0i64;
    }
  }
  v1->VFormats.KeyBuffer.pPages = v10;
  v1->VFormats.KeyBuffer.pLast = v10;
  Scaleform::Render::PagedItemBuffer<Scaleform::Render::MultiKeyCollection<Scaleform::Render::VertexElement,Scaleform::Render::VertexFormat,32,8>::ValueItem,8>::freePages(
    &v1->VFormats.ValueBuffer,
    0);
}

