// File Line: 27
// RVA: 0x15D8A70
__int64 dynamic_initializer_for__g_HD3D__()
{
  return atexit(dynamic_atexit_destructor_for__g_HD3D__);
}

// File Line: 34
// RVA: 0xEBF9F0
void __fastcall AMD_HD3D::AMD_HD3D(AMD_HD3D *this)
{
  this->mEnableStereo = 1;
  this->mStereo = 0i64;
  *(_QWORD *)&this->mLineOffset = 0i64;
  this->mHeight = 0;
  this->mExtension = 0i64;
}

// File Line: 55
// RVA: 0xEBFAE0
__int64 __fastcall AMD_HD3D::OpenStereoInterface(AMD_HD3D *this, ID3D11Device *pD3DDevice)
{
  AMD_HD3D *v2; // rdi
  ID3D11Device *v3; // rbx
  HMODULE v4; // rax
  FARPROC v5; // rax
  unsigned int v6; // ebx
  __int64 v7; // rax
  IAmdDxExtQuadBufferStereo *v8; // rcx
  IAmdDxExt *v9; // rcx

  v2 = this;
  v3 = pD3DDevice;
  v4 = GetModuleHandleW(L"atidxx64.dll");
  v5 = GetProcAddress(v4, "AmdDxExtCreate11");
  if ( !v5 )
  {
LABEL_4:
    v6 = -2147467259;
    goto LABEL_5;
  }
  v6 = ((__int64 (__fastcall *)(ID3D11Device *, IAmdDxExt **))v5)(v3, &v2->mExtension);
  if ( (v6 & 0x80000000) == 0 )
  {
    v7 = ((__int64 (__fastcall *)(IAmdDxExt *, signed __int64))v2->mExtension->vfptr[1].Release)(v2->mExtension, 2i64);
    v2->mStereo = (IAmdDxExtQuadBufferStereo *)v7;
    if ( v7 )
      return v6;
    goto LABEL_4;
  }
LABEL_5:
  v8 = v2->mStereo;
  if ( v8 )
  {
    ((void (*)(void))v8->vfptr->Release)();
    v2->mStereo = 0i64;
  }
  v9 = v2->mExtension;
  if ( v9 )
  {
    ((void (*)(void))v9->vfptr->Release)();
    v2->mExtension = 0i64;
  }
  return v6;
}

// File Line: 116
// RVA: 0xEBFB80
__int64 __fastcall AMD_HD3D::CreateStereoSwapChain(AMD_HD3D *this, IDXGIFactory1 *pIDXGIFactory, ID3D11Device *pd3d11Device, DXGI_SWAP_CHAIN_DESC *pRequestedSwapChainDesc, IDXGISwapChain **ppSwapChain)
{
  DXGI_SWAP_CHAIN_DESC *v5; // rbp
  AMD_HD3D *v6; // rbx
  __int64 result; // rax
  int v8; // eax
  IAmdDxExtQuadBufferStereo *v9; // rcx
  unsigned int v10; // edi
  unsigned int v11; // esi
  IAmdDxExt *v12; // rcx
  unsigned int v13; // er14
  DXGI_MODE_SCANLINE_ORDER v14; // eax
  DXGI_MODE_SCALING v15; // ST50_4
  unsigned int v16; // er15
  signed int v17; // er13
  unsigned int v18; // esi
  IAmdDxExtQuadBufferStereo *v19; // rcx
  IAmdDxExtInterfaceVtbl *v20; // rax
  char *v21; // rax
  char *v22; // r12
  bool v23; // zf
  unsigned int v24; // esi
  _DWORD *v25; // rax
  signed int v26; // eax
  signed __int64 v27; // rcx
  IDXGISwapChain **v28; // rdi
  int v29; // eax
  IAmdDxExtQuadBufferStereo *v30; // rcx
  unsigned int v31; // esi
  unsigned int v32; // eax
  unsigned int v33; // [rsp+30h] [rbp-78h]
  unsigned int v34; // [rsp+34h] [rbp-74h]
  unsigned int v35; // [rsp+B0h] [rbp+8h]
  IDXGIFactory1 *v36; // [rsp+B8h] [rbp+10h]
  ID3D11Device *v37; // [rsp+C0h] [rbp+18h]
  unsigned int v38; // [rsp+C8h] [rbp+20h]

  v37 = pd3d11Device;
  v36 = pIDXGIFactory;
  this->mEnableStereo = 1;
  v5 = pRequestedSwapChainDesc;
  v6 = this;
  if ( pRequestedSwapChainDesc->Windowed )
  {
    this->mEnableStereo = 0;
    return 2147500037i64;
  }
  if ( !this->mStereo )
  {
    result = AMD_HD3D::OpenStereoInterface(this, pd3d11Device);
    if ( (signed int)result < 0 )
    {
      v6->mEnableStereo = 0;
      return result;
    }
  }
  v8 = ((__int64 (__fastcall *)(IAmdDxExtQuadBufferStereo *, signed __int64))v6->mStereo->vfptr[1].AddRef)(
         v6->mStereo,
         1i64);
  v9 = v6->mStereo;
  v10 = 0;
  v11 = v8;
  if ( v8 >= 0 )
  {
    v38 = v5->BufferDesc.Height;
    v13 = *(_DWORD *)v5->BufferDesc.Format;
    v33 = v5->BufferDesc.RefreshRate.Numerator;
    v34 = v5->BufferDesc.RefreshRate.Denominator;
    v14 = v5->BufferDesc.ScanlineOrdering;
    v35 = 0;
    v15 = v5->BufferDesc.Scaling;
    v16 = v5->BufferDesc.Width;
    v17 = -1;
    v18 = ((__int64 (__fastcall *)(IAmdDxExtQuadBufferStereo *, _QWORD, _QWORD, unsigned int *, _QWORD))v9->vfptr[1].Release)(
            v9,
            v13,
            0i64,
            &v35,
            0i64);
    if ( (v18 & 0x80000000) != 0 )
    {
      ((void (__fastcall *)(IAmdDxExtQuadBufferStereo *, _QWORD))v6->mStereo->vfptr[1].AddRef)(v6->mStereo, 0i64);
      AMD_HD3D::~AMD_HD3D(v6);
      v6->mEnableStereo = 0;
      return v18;
    }
    if ( v35 )
    {
      v21 = AMemory::malloc_default(saturated_mul(v35, 0x1Cui64));
      v19 = v6->mStereo;
      v22 = v21;
      v23 = v21 == 0i64;
      v20 = v19->vfptr;
      if ( !v23 )
      {
        v24 = ((__int64 (__fastcall *)(IAmdDxExtQuadBufferStereo *, _QWORD, _QWORD, unsigned int *, char *))v20[1].Release)(
                v19,
                v13,
                0i64,
                &v35,
                v22);
        if ( (v24 & 0x80000000) != 0 )
        {
          ((void (__fastcall *)(IAmdDxExtQuadBufferStereo *, _QWORD))v6->mStereo->vfptr[1].AddRef)(v6->mStereo, 0i64);
          Illusion::ShaderParam::operator delete(v22);
          v6->mEnableStereo = 0;
          AMD_HD3D::~AMD_HD3D(v6);
          return v24;
        }
        if ( !v35 )
          goto LABEL_42;
        v25 = v22 + 16;
        while ( 1 )
        {
          if ( *(v25 - 4) == v16 && *(v25 - 3) == v38 && *v25 == v13 )
          {
            v17 = v10;
            if ( *(v25 - 2) == v33 && *(v25 - 1) == v34 )
              break;
          }
          ++v10;
          v25 += 7;
          if ( v10 >= v35 )
          {
            v26 = -1;
            goto LABEL_29;
          }
        }
        v26 = v10;
LABEL_29:
        if ( v17 >= 0 )
        {
          if ( v26 >= 0 )
            v17 = v26;
          v27 = 28i64 * v17;
          v5->BufferDesc.Width = *(_DWORD *)&v22[v27];
          v5->BufferDesc.Height = *(_DWORD *)&v22[v27 + 4];
          v5->BufferDesc.RefreshRate.Numerator = *(_DWORD *)&v22[v27 + 8];
          v5->BufferDesc.RefreshRate.Denominator = *(_DWORD *)&v22[v27 + 12];
          *(_DWORD *)v5->BufferDesc.Format = *(_DWORD *)&v22[v27 + 16];
          v5->BufferDesc.ScanlineOrdering = *(_DWORD *)&v22[v27 + 20];
          v5->BufferDesc.Scaling = *(_DWORD *)&v22[v27 + 24];
          Illusion::ShaderParam::operator delete(v22);
          v28 = ppSwapChain;
          v29 = ((__int64 (__fastcall *)(IDXGIFactory1 *, ID3D11Device *, DXGI_SWAP_CHAIN_DESC *, IDXGISwapChain **))v36->vfptr[3].AddRef)(
                  v36,
                  v37,
                  v5,
                  ppSwapChain);
          v30 = v6->mStereo;
          v31 = v29;
          if ( v29 < 0 )
          {
            ((void (__fastcall *)(IAmdDxExtQuadBufferStereo *, _QWORD))v30->vfptr[1].AddRef)(v30, 0i64);
            v6->mEnableStereo = 0;
            AMD_HD3D::~AMD_HD3D(v6);
            return v31;
          }
          v32 = ((__int64 (__fastcall *)(IAmdDxExtQuadBufferStereo *, IDXGISwapChain *))v30->vfptr[1].~IAmdDxExtInterface)(
                  v30,
                  *v28);
          v6->mLineOffset = v32;
          if ( v32 )
          {
            v6->mWidth = v5->BufferDesc.Width;
            v6->mHeight = v5->BufferDesc.Height;
            return 0i64;
          }
          ((void (__fastcall *)(IAmdDxExtQuadBufferStereo *, _QWORD))v6->mStereo->vfptr[1].AddRef)(v6->mStereo, 0i64);
          ((void (*)(void))(*v28)->vfptr->Release)();
          v6->mEnableStereo = 0;
        }
        else
        {
LABEL_42:
          ((void (__fastcall *)(IAmdDxExtQuadBufferStereo *, _QWORD))v6->mStereo->vfptr[1].AddRef)(v6->mStereo, 0i64);
          v6->mEnableStereo = 0;
          Illusion::ShaderParam::operator delete(v22);
        }
        goto LABEL_39;
      }
    }
    else
    {
      v19 = v6->mStereo;
      v20 = v19->vfptr;
    }
    ((void (__fastcall *)(IAmdDxExtQuadBufferStereo *, _QWORD))v20[1].AddRef)(v19, 0i64);
    v6->mEnableStereo = 0;
LABEL_39:
    AMD_HD3D::~AMD_HD3D(v6);
    return 2147500037i64;
  }
  v6->mEnableStereo = 0;
  if ( v9 )
  {
    ((void (*)(void))v9->vfptr->Release)();
    v6->mStereo = 0i64;
  }
  v12 = v6->mExtension;
  if ( v12 )
  {
    ((void (*)(void))v12->vfptr->Release)();
    v6->mExtension = 0i64;
  }
  v6->mEnableStereo = 0;
  return v11;
}

// File Line: 273
// RVA: 0xEBFA10
void __fastcall AMD_HD3D::UpdateRightQuadBuffer(AMD_HD3D *this, ID3D11DeviceContext *pdeviceContext, ID3D11Resource *pBackBuffer, ID3D11Resource *pRightEyeTexture, const int pixelConvergence)
{
  int v5; // ST38_4
  int v6; // ST28_4
  unsigned int v7; // ST20_4

  if ( this->mEnableStereo )
  {
    v5 = 0;
    v6 = 0;
    v7 = this->mLineOffset;
    ((void (__fastcall *)(ID3D11DeviceContext *, ID3D11Resource *, _QWORD, _QWORD, unsigned int, int, ID3D11Resource *, int, _QWORD))pdeviceContext->vfptr[15].AddRef)(
      pdeviceContext,
      pBackBuffer,
      0i64,
      (unsigned int)pixelConvergence,
      v7,
      v6,
      pRightEyeTexture,
      v5,
      0i64);
  }
}

// File Line: 293
// RVA: 0xEBFA60
void __fastcall AMD_HD3D::Enable(AMD_HD3D *this)
{
  if ( this->mStereo )
    ((void (__fastcall *)(IAmdDxExtQuadBufferStereo *, signed __int64))this->mStereo->vfptr[1].AddRef)(
      this->mStereo,
      1i64);
}

// File Line: 305
// RVA: 0xEBFA80
void __fastcall AMD_HD3D::Disable(AMD_HD3D *this)
{
  if ( this->mStereo )
    ((void (__fastcall *)(IAmdDxExtQuadBufferStereo *, _QWORD))this->mStereo->vfptr[1].AddRef)(this->mStereo, 0i64);
}

// File Line: 317
// RVA: 0xEBFAA0
void __fastcall AMD_HD3D::~AMD_HD3D(AMD_HD3D *this)
{
  AMD_HD3D *v1; // rbx
  IAmdDxExtQuadBufferStereo *v2; // rcx
  IAmdDxExt *v3; // rcx

  v1 = this;
  v2 = this->mStereo;
  if ( v2 )
  {
    ((void (*)(void))v2->vfptr->Release)();
    v1->mStereo = 0i64;
  }
  v3 = v1->mExtension;
  if ( v3 )
  {
    ((void (*)(void))v3->vfptr->Release)();
    v1->mExtension = 0i64;
  }
  v1->mEnableStereo = 0;
}

