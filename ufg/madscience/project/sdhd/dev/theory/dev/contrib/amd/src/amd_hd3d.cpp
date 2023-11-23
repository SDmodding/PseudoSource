// File Line: 27
// RVA: 0x15D8A70
__int64 dynamic_initializer_for__g_HD3D__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__g_HD3D__);
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
  HMODULE ModuleHandleW; // rax
  FARPROC ProcAddress; // rax
  int v6; // ebx
  IAmdDxExtQuadBufferStereo *v7; // rax
  IAmdDxExtQuadBufferStereo *mStereo; // rcx
  IAmdDxExt *mExtension; // rcx

  ModuleHandleW = GetModuleHandleW(L"atidxx64.dll");
  ProcAddress = GetProcAddress(ModuleHandleW, "AmdDxExtCreate11");
  if ( !ProcAddress )
  {
LABEL_4:
    v6 = -2147467259;
    goto LABEL_5;
  }
  v6 = ((__int64 (__fastcall *)(ID3D11Device *, IAmdDxExt **))ProcAddress)(pD3DDevice, &this->mExtension);
  if ( v6 >= 0 )
  {
    v7 = (IAmdDxExtQuadBufferStereo *)((__int64 (__fastcall *)(IAmdDxExt *, __int64))this->mExtension->vfptr[1].Release)(
                                        this->mExtension,
                                        2i64);
    this->mStereo = v7;
    if ( v7 )
      return (unsigned int)v6;
    goto LABEL_4;
  }
LABEL_5:
  mStereo = this->mStereo;
  if ( mStereo )
  {
    mStereo->vfptr->Release(mStereo);
    this->mStereo = 0i64;
  }
  mExtension = this->mExtension;
  if ( mExtension )
  {
    mExtension->vfptr->Release(mExtension);
    this->mExtension = 0i64;
  }
  return (unsigned int)v6;
}

// File Line: 116
// RVA: 0xEBFB80
__int64 __fastcall AMD_HD3D::CreateStereoSwapChain(
        AMD_HD3D *this,
        IDXGIFactory1 *pIDXGIFactory,
        ID3D11Device *pd3d11Device,
        DXGI_SWAP_CHAIN_DESC *pRequestedSwapChainDesc,
        IDXGISwapChain **ppSwapChain)
{
  __int64 result; // rax
  int v8; // eax
  IAmdDxExtQuadBufferStereo *mStereo; // rcx
  unsigned int v10; // edi
  unsigned int v11; // esi
  IAmdDxExt *mExtension; // rcx
  unsigned int v13; // r14d
  unsigned int Width; // r15d
  int v15; // r13d
  int v16; // esi
  IAmdDxExtQuadBufferStereo *v17; // rcx
  IAmdDxExtInterfaceVtbl *vfptr; // rax
  char *v19; // rax
  char *v20; // r12
  bool v21; // zf
  int v22; // esi
  _DWORD *v23; // rax
  int v24; // eax
  __int64 v25; // rcx
  IDXGISwapChain **v26; // rdi
  int v27; // eax
  IAmdDxExtQuadBufferStereo *v28; // rcx
  unsigned int v29; // esi
  unsigned int v30; // eax
  unsigned int Numerator; // [rsp+30h] [rbp-78h]
  unsigned int Denominator; // [rsp+34h] [rbp-74h]
  unsigned int v33; // [rsp+B0h] [rbp+8h] BYREF
  IDXGIFactory1 *v34; // [rsp+B8h] [rbp+10h]
  ID3D11Device *v35; // [rsp+C0h] [rbp+18h]
  unsigned int Height; // [rsp+C8h] [rbp+20h]

  v35 = pd3d11Device;
  v34 = pIDXGIFactory;
  this->mEnableStereo = 1;
  if ( pRequestedSwapChainDesc->Windowed )
  {
    this->mEnableStereo = 0;
    return 2147500037i64;
  }
  if ( !this->mStereo )
  {
    result = AMD_HD3D::OpenStereoInterface(this, pd3d11Device);
    if ( (int)result < 0 )
    {
      this->mEnableStereo = 0;
      return result;
    }
  }
  v8 = ((__int64 (__fastcall *)(IAmdDxExtQuadBufferStereo *, __int64))this->mStereo->vfptr[1].AddRef)(
         this->mStereo,
         1i64);
  mStereo = this->mStereo;
  v10 = 0;
  v11 = v8;
  if ( v8 >= 0 )
  {
    Height = pRequestedSwapChainDesc->BufferDesc.Height;
    v13 = *(_DWORD *)pRequestedSwapChainDesc->BufferDesc.Format;
    Numerator = pRequestedSwapChainDesc->BufferDesc.RefreshRate.Numerator;
    Denominator = pRequestedSwapChainDesc->BufferDesc.RefreshRate.Denominator;
    v33 = 0;
    Width = pRequestedSwapChainDesc->BufferDesc.Width;
    v15 = -1;
    v16 = ((__int64 (__fastcall *)(IAmdDxExtQuadBufferStereo *, _QWORD, _QWORD, unsigned int *, _QWORD))mStereo->vfptr[1].Release)(
            mStereo,
            v13,
            0i64,
            &v33,
            0i64);
    if ( v16 < 0 )
    {
      ((void (__fastcall *)(IAmdDxExtQuadBufferStereo *, _QWORD))this->mStereo->vfptr[1].AddRef)(this->mStereo, 0i64);
      AMD_HD3D::~AMD_HD3D(this);
      this->mEnableStereo = 0;
      return (unsigned int)v16;
    }
    if ( v33 )
    {
      v19 = AMemory::malloc_default(saturated_mul(v33, 0x1Cui64));
      v17 = this->mStereo;
      v20 = v19;
      v21 = v19 == 0i64;
      vfptr = v17->vfptr;
      if ( !v21 )
      {
        v22 = ((__int64 (__fastcall *)(IAmdDxExtQuadBufferStereo *, _QWORD, _QWORD, unsigned int *, char *))vfptr[1].Release)(
                v17,
                v13,
                0i64,
                &v33,
                v20);
        if ( v22 < 0 )
        {
          ((void (__fastcall *)(IAmdDxExtQuadBufferStereo *, _QWORD))this->mStereo->vfptr[1].AddRef)(
            this->mStereo,
            0i64);
          Illusion::ShaderParam::operator delete(v20);
          this->mEnableStereo = 0;
          AMD_HD3D::~AMD_HD3D(this);
          return (unsigned int)v22;
        }
        if ( !v33 )
          goto LABEL_38;
        v23 = v20 + 16;
        while ( 1 )
        {
          if ( *(v23 - 4) == Width && *(v23 - 3) == Height && *v23 == v13 )
          {
            v15 = v10;
            if ( *(v23 - 2) == Numerator && *(v23 - 1) == Denominator )
              break;
          }
          ++v10;
          v23 += 7;
          if ( v10 >= v33 )
          {
            v24 = -1;
            goto LABEL_29;
          }
        }
        v24 = v10;
LABEL_29:
        if ( v15 >= 0 )
        {
          if ( v24 >= 0 )
            v15 = v24;
          v25 = 28i64 * v15;
          pRequestedSwapChainDesc->BufferDesc.Width = *(_DWORD *)&v20[v25];
          pRequestedSwapChainDesc->BufferDesc.Height = *(_DWORD *)&v20[v25 + 4];
          pRequestedSwapChainDesc->BufferDesc.RefreshRate.Numerator = *(_DWORD *)&v20[v25 + 8];
          pRequestedSwapChainDesc->BufferDesc.RefreshRate.Denominator = *(_DWORD *)&v20[v25 + 12];
          *(_DWORD *)pRequestedSwapChainDesc->BufferDesc.Format = *(_DWORD *)&v20[v25 + 16];
          pRequestedSwapChainDesc->BufferDesc.ScanlineOrdering = *(_DWORD *)&v20[v25 + 20];
          pRequestedSwapChainDesc->BufferDesc.Scaling = *(_DWORD *)&v20[v25 + 24];
          Illusion::ShaderParam::operator delete(v20);
          v26 = ppSwapChain;
          v27 = ((__int64 (__fastcall *)(IDXGIFactory1 *, ID3D11Device *, DXGI_SWAP_CHAIN_DESC *, IDXGISwapChain **))v34->vfptr[3].AddRef)(
                  v34,
                  v35,
                  pRequestedSwapChainDesc,
                  ppSwapChain);
          v28 = this->mStereo;
          v29 = v27;
          if ( v27 < 0 )
          {
            ((void (__fastcall *)(IAmdDxExtQuadBufferStereo *, _QWORD))v28->vfptr[1].AddRef)(v28, 0i64);
            this->mEnableStereo = 0;
            AMD_HD3D::~AMD_HD3D(this);
            return v29;
          }
          v30 = ((__int64 (__fastcall *)(IAmdDxExtQuadBufferStereo *, IDXGISwapChain *))v28->vfptr[1].~IAmdDxExtInterface)(
                  v28,
                  *v26);
          this->mLineOffset = v30;
          if ( v30 )
          {
            this->mWidth = pRequestedSwapChainDesc->BufferDesc.Width;
            this->mHeight = pRequestedSwapChainDesc->BufferDesc.Height;
            return 0i64;
          }
          ((void (__fastcall *)(IAmdDxExtQuadBufferStereo *, _QWORD))this->mStereo->vfptr[1].AddRef)(
            this->mStereo,
            0i64);
          (*v26)->vfptr->Release(*v26);
          this->mEnableStereo = 0;
        }
        else
        {
LABEL_38:
          ((void (__fastcall *)(IAmdDxExtQuadBufferStereo *, _QWORD))this->mStereo->vfptr[1].AddRef)(
            this->mStereo,
            0i64);
          this->mEnableStereo = 0;
          Illusion::ShaderParam::operator delete(v20);
        }
        goto LABEL_39;
      }
    }
    else
    {
      v17 = this->mStereo;
      vfptr = v17->vfptr;
    }
    ((void (__fastcall *)(IAmdDxExtQuadBufferStereo *, _QWORD))vfptr[1].AddRef)(v17, 0i64);
    this->mEnableStereo = 0;
LABEL_39:
    AMD_HD3D::~AMD_HD3D(this);
    return 2147500037i64;
  }
  this->mEnableStereo = 0;
  if ( mStereo )
  {
    mStereo->vfptr->Release(mStereo);
    this->mStereo = 0i64;
  }
  mExtension = this->mExtension;
  if ( mExtension )
  {
    mExtension->vfptr->Release(mExtension);
    this->mExtension = 0i64;
  }
  this->mEnableStereo = 0;
  return v11;
}

// File Line: 273
// RVA: 0xEBFA10
void __fastcall AMD_HD3D::UpdateRightQuadBuffer(
        AMD_HD3D *this,
        ID3D11DeviceContext *pdeviceContext,
        ID3D11Resource *pBackBuffer,
        ID3D11Resource *pRightEyeTexture,
        unsigned int pixelConvergence)
{
  if ( this->mEnableStereo )
    ((void (__fastcall *)(ID3D11DeviceContext *, ID3D11Resource *, _QWORD, _QWORD, unsigned int, _DWORD, ID3D11Resource *, _DWORD, _QWORD))pdeviceContext->vfptr[15].AddRef)(
      pdeviceContext,
      pBackBuffer,
      0i64,
      pixelConvergence,
      this->mLineOffset,
      0,
      pRightEyeTexture,
      0,
      0i64);
}

// File Line: 293
// RVA: 0xEBFA60
void __fastcall AMD_HD3D::Enable(AMD_HD3D *this)
{
  if ( this->mStereo )
    ((void (__fastcall *)(IAmdDxExtQuadBufferStereo *, __int64))this->mStereo->vfptr[1].AddRef)(this->mStereo, 1i64);
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
  IAmdDxExtQuadBufferStereo *mStereo; // rcx
  IAmdDxExt *mExtension; // rcx

  mStereo = this->mStereo;
  if ( mStereo )
  {
    mStereo->vfptr->Release(mStereo);
    this->mStereo = 0i64;
  }
  mExtension = this->mExtension;
  if ( mExtension )
  {
    mExtension->vfptr->Release(mExtension);
    this->mExtension = 0i64;
  }
  this->mEnableStereo = 0;
}

