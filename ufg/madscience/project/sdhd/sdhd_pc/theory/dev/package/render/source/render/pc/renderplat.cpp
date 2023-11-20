// File Line: 117
// RVA: 0x15878A0
__int64 UFG::_dynamic_initializer_for__gScreenMinimizedEvent__()
{
  UFG::ChannelObj::ChannelObj(
    &UFG::gScreenMinimizedEvent,
    "ScreenMinimizedEvent",
    "This is an event that gets generated when the screen is minimized.");
  return atexit(UFG::_dynamic_atexit_destructor_for__gScreenMinimizedEvent__);
}

// File Line: 118
// RVA: 0x15878D0
__int64 UFG::_dynamic_initializer_for__gScreenRestoredEvent__()
{
  UFG::ChannelObj::ChannelObj(
    &UFG::gScreenRestoredEvent,
    "ScreenRestoredEvent",
    "This is an event that gets generated when the screen is restored.");
  return atexit(UFG::_dynamic_atexit_destructor_for__gScreenRestoredEvent__);
}

// File Line: 162
// RVA: 0x1587890
void dynamic_initializer_for__gOutputParams__()
{
  Render::RenderOutputParams::RenderOutputParams(&gOutputParams);
}

// File Line: 177
// RVA: 0x15879B0
__int64 dynamic_initializer_for__sDXGIMutex__()
{
  UFG::qMutex::qMutex(&sDXGIMutex, &customWorldMapCaption);
  return atexit(dynamic_atexit_destructor_for__sDXGIMutex__);
}

// File Line: 187
// RVA: 0x1587990
__int64 dynamic_initializer_for__sAvailableDXGIAdapters__()
{
  return atexit(dynamic_atexit_destructor_for__sAvailableDXGIAdapters__);
}

// File Line: 197
// RVA: 0x15879A0
__int64 dynamic_initializer_for__sAvailableDXGIOutputs__()
{
  return atexit(dynamic_atexit_destructor_for__sAvailableDXGIOutputs__);
}

// File Line: 213
// RVA: 0x15879E0
__int64 dynamic_initializer_for__sPendingCommandBuilders__()
{
  return atexit(dynamic_atexit_destructor_for__sPendingCommandBuilders__);
}

// File Line: 214
// RVA: 0x1587A00
__int64 dynamic_initializer_for__sPendingCommandBuildersMutex__()
{
  UFG::qMutex::qMutex(&sPendingCommandBuildersMutex, &customWorldMapCaption);
  return atexit(dynamic_atexit_destructor_for__sPendingCommandBuildersMutex__);
}

// File Line: 250
// RVA: 0x69E660
void __fastcall Stereo3D::~Stereo3D(Stereo3D *this)
{
  this->vfptr = (Stereo3DVtbl *)&Stereo3D::`vftable';
}

// File Line: 313
// RVA: 0x69F9C0
signed __int64 __fastcall NVStereo3D::Init(NVStereo3D *this)
{
  NVStereo3D *v1; // rbx
  char pIsStereoEnabled; // [rsp+30h] [rbp+8h]

  v1 = this;
  *(_WORD *)&this->mNV3DVision = 256;
  if ( NvAPI_Stereo_IsEnabled(&pIsStereoEnabled) || !pIsStereoEnabled )
    return 2147500037i64;
  NvAPI_Stereo_SetDriverMode(NVAPI_STEREO_DRIVER_MODE_DIRECT);
  NvAPI_Stereo_CreateConfigurationProfileRegistryKey(0);
  v1->mNV3DVision = 1;
  return 0i64;
}

// File Line: 349
// RVA: 0x6A0440
signed __int64 __fastcall NVStereo3D::InitStereo3D(NVStereo3D *this, ID3D11Device *pDevice, HWND__ *hwnd)
{
  HWND__ *v3; // rsi
  NVStereo3D *v4; // rbx
  signed __int64 result; // rax

  v3 = hwnd;
  v4 = this;
  if ( !this->mNV3DVision )
    return 2147500037i64;
  if ( NvAPI_Stereo_CreateHandleFromIUnknown((IUnknown *)pDevice, &this->mStereoHandle) )
  {
    v4->mNV3DVision = 0;
    result = 2147500037i64;
  }
  else
  {
    NvAPI_Stereo_SetActiveEye(v4->mStereoHandle, NVAPI_STEREO_EYE_MONO);
    NvAPI_Stereo_SetNotificationMessage(v4->mStereoHandle, (unsigned __int64)v3, 0xBB8ui64);
    result = 0i64;
  }
  return result;
}

// File Line: 378
// RVA: 0x6A22F0
_BOOL8 __fastcall NVStereo3D::Stereo3DAvailable(NVStereo3D *this)
{
  return this->mNV3DVision;
}

// File Line: 384
// RVA: 0x69ED40
signed __int64 __fastcall NVStereo3D::CreateStereoSwapChain(NVStereo3D *this, IDXGIFactory1 *pIDXGIFactory, ID3D11Device *pd3d11Device, DXGI_SWAP_CHAIN_DESC *pRequestedSwapChainDesc, IDXGISwapChain **ppSwapChain)
{
  unsigned int v5; // ebx

  if ( !this->mNV3DVision )
    return 2147500037i64;
  v5 = 0;
  if ( (NvAPI_D3D1x_CreateSwapChain(
          this->mStereoHandle,
          &pRequestedSwapChainDesc->BufferDesc.Width,
          (unsigned int **)ppSwapChain,
          NVAPI_STEREO_SWAPCHAIN_STEREO) & 0x80000000) != 0 )
    v5 = -2147467259;
  return v5;
}

// File Line: 404
// RVA: 0x6A2040
void __fastcall NVStereo3D::SelectEye(NVStereo3D *this, Render::eStereoRenderEye eye)
{
  if ( eye )
  {
    if ( eye == 1 )
      NvAPI_Stereo_SetActiveEye(this->mStereoHandle, NVAPI_STEREO_EYE_RIGHT);
  }
  else
  {
    NvAPI_Stereo_SetActiveEye(this->mStereoHandle, NVAPI_STEREO_EYE_LEFT);
  }
}

// File Line: 420
// RVA: 0x69EC70
void __fastcall NVStereo3D::CopyToEye(NVStereo3D *this, Render::eStereoRenderEye eye, ID3D11DeviceContext *pD3DContext, ID3D11Resource *pDstResource, ID3D11Resource *pSrcResource, const int pixelConvergence)
{
  ID3D11Resource *v6; // rsi
  ID3D11DeviceContext *v7; // rdi
  Render::eStereoRenderEye v8; // ebx
  IUnknownVtbl *v9; // r10
  int v10; // eax
  __int64 v11; // r9
  char v12[12]; // [rsp+50h] [rbp-28h]
  int v13; // [rsp+5Ch] [rbp-1Ch]
  int v14; // [rsp+60h] [rbp-18h]
  int v15; // [rsp+64h] [rbp-14h]

  v6 = pDstResource;
  v7 = pD3DContext;
  v8 = eye;
  ((void (*)(void))this->vfptr->SelectEye)();
  v9 = v7->vfptr;
  v15 = 1;
  if ( v8 )
  {
    v11 = (unsigned int)pixelConvergence;
    *(_QWORD *)v12 = 0i64;
    *(_DWORD *)&v12[8] = 0;
    v10 = gScreenWidth - pixelConvergence;
  }
  else
  {
    *(_QWORD *)&v12[4] = 0i64;
    v10 = gScreenWidth - pixelConvergence;
    v11 = 0i64;
    *(_DWORD *)v12 = pixelConvergence;
  }
  v13 = v10;
  v14 = gScreenHeight;
  ((void (__fastcall *)(ID3D11DeviceContext *, ID3D11Resource *, _QWORD, __int64, _DWORD, _DWORD, ID3D11Resource *, _DWORD, char *))v9[15].AddRef)(
    v7,
    v6,
    0i64,
    v11,
    0,
    0,
    pSrcResource,
    0,
    v12);
}

// File Line: 449
// RVA: 0x69F230
void __fastcall NVStereo3D::Enable(NVStereo3D *this)
{
  NvAPI_Stereo_Enable();
}

// File Line: 455
// RVA: 0x69EDA0
void __fastcall NVStereo3D::Disable(NVStereo3D *this)
{
  NvAPI_Stereo_Disable();
}

// File Line: 494
// RVA: 0x69E5E0
void __fastcall AMDStereo3D::AMDStereo3D(AMDStereo3D *this)
{
  AMDStereo3D *v1; // rbx

  v1 = this;
  this->vfptr = (Stereo3DVtbl *)&Stereo3D::`vftable';
  this->vfptr = (Stereo3DVtbl *)&AMDStereo3D::`vftable';
  AMD_HD3D::AMD_HD3D(&this->mHD3D);
  *(_WORD *)&v1->mAMDHD3D = 0;
}

// File Line: 512
// RVA: 0x69F9B0
__int64 __fastcall AMDStereo3D::Init(AMDStereo3D *this)
{
  *(_WORD *)&this->mAMDHD3D = 257;
  return 0i64;
}

// File Line: 523
// RVA: 0x6A0430
HRESULT __fastcall AMDStereo3D::InitStereo3D(AMDStereo3D *this, ID3D11Device *pDevice, HWND__ *hwnd)
{
  return AMD_HD3D::OpenStereoInterface(&this->mHD3D, pDevice);
}

// File Line: 529
// RVA: 0x6A22E0
_BOOL8 __fastcall Scaleform::MemoryFile::IsValid(TargetPlayHoldTask *this, float timeDelta)
{
  return this->mHold;
}

// File Line: 535
// RVA: 0x69ED30
HRESULT __fastcall AMDStereo3D::CreateStereoSwapChain(AMDStereo3D *this, IDXGIFactory1 *pIDXGIFactory, ID3D11Device *pd3d11Device, DXGI_SWAP_CHAIN_DESC *pRequestedSwapChainDesc, IDXGISwapChain **ppSwapChain)
{
  return AMD_HD3D::CreateStereoSwapChain(
           &this->mHD3D,
           pIDXGIFactory,
           pd3d11Device,
           pRequestedSwapChainDesc,
           ppSwapChain);
}

// File Line: 541
// RVA: 0x6A2020
void __fastcall AMDStereo3D::SelectEye(AMDStereo3D *this, Render::eStereoRenderEye eye)
{
  if ( eye )
  {
    if ( eye == 1 )
      _(&this->mHD3D);
  }
  else
  {
    _(&this->mHD3D);
  }
}

// File Line: 557
// RVA: 0x69EBB0
void __fastcall AMDStereo3D::CopyToEye(AMDStereo3D *this, Render::eStereoRenderEye eye, ID3D11DeviceContext *pD3DContext, ID3D11Resource *pDstResource, ID3D11Resource *pSrcResource, const int pixelConvergence)
{
  IUnknownVtbl *v6; // r10
  int v7; // ST38_4
  int v8; // ST28_4
  int v9; // ST20_4
  int v10; // [rsp+50h] [rbp-28h]
  __int64 v11; // [rsp+54h] [rbp-24h]
  int v12; // [rsp+5Ch] [rbp-1Ch]
  int v13; // [rsp+60h] [rbp-18h]
  int v14; // [rsp+64h] [rbp-14h]

  if ( eye )
  {
    if ( eye == 1 )
      AMD_HD3D::UpdateRightQuadBuffer(&this->mHD3D, pD3DContext, pDstResource, pSrcResource, pixelConvergence);
  }
  else
  {
    v6 = pD3DContext->vfptr;
    v10 = pixelConvergence;
    v12 = gScreenWidth - pixelConvergence;
    v11 = 0i64;
    v13 = gScreenHeight;
    v7 = 0;
    v8 = 0;
    v9 = 0;
    v14 = 1;
    ((void (__fastcall *)(ID3D11DeviceContext *, ID3D11Resource *, _QWORD, _QWORD, int, int, ID3D11Resource *, int, int *))v6[15].AddRef)(
      pD3DContext,
      pDstResource,
      0i64,
      0i64,
      v9,
      v8,
      pSrcResource,
      v7,
      &v10);
  }
}

// File Line: 583
// RVA: 0x69F220
void __fastcall AMDStereo3D::Enable(AMDStereo3D *this)
{
  AMD_HD3D::Enable(&this->mHD3D);
}

// File Line: 589
// RVA: 0x69ED90
void __fastcall AMDStereo3D::Disable(AMDStereo3D *this)
{
  AMD_HD3D::Disable(&this->mHD3D);
}

// File Line: 595
// RVA: 0x6A0CD0
void __fastcall AMDStereo3D::Release(AMDStereo3D *this)
{
  AMD_HD3D::~AMD_HD3D(&this->mHD3D);
}

// File Line: 624
// RVA: 0x69E9E0
void __fastcall Render::CommitPendingCommandBuilders(Render *this)
{
  UFG::qNode<Illusion::AsyncCommandBuilder,Illusion::AsyncCommandBuilder> **i; // rax
  _QWORD *v2; // rdx
  UFG::qNode<Illusion::AsyncCommandBuilder,Illusion::AsyncCommandBuilder> *v3; // rcx
  UFG::qNode<Illusion::AsyncCommandBuilder,Illusion::AsyncCommandBuilder> *v4; // rax

  UFG::qMutex::Lock((LPCRITICAL_SECTION)&sPendingCommandBuildersMutex);
  for ( i = &sPendingCommandBuilders.mNode.mNext[-1].mNext;
        &sPendingCommandBuilders.mNode.mNext[-1].mNext != (UFG::qNode<Illusion::AsyncCommandBuilder,Illusion::AsyncCommandBuilder> **)((char *)&sPendingCommandBuilders - 8);
        i = &sPendingCommandBuilders.mNode.mNext[-1].mNext )
  {
    v2 = i + 1;
    v3 = i[1];
    v4 = i[2];
    v3->mNext = v4;
    v4->mPrev = v3;
    *v2 = v2;
    v2[1] = v2;
    Illusion::AsyncCommandBuilder::FinalizeAsyncCommandBuilding((Illusion::AsyncCommandBuilder *)(v2 - 1));
  }
  Illusion::BufferD3DResourceInventory::SyncLoadTasks(&Illusion::gBufferD3DResourceInventory);
  Illusion::TextureD3DResourceInventory::SyncLoadTasks(&Illusion::gTextureD3DResourceInventory);
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&sPendingCommandBuildersMutex);
}

// File Line: 640
// RVA: 0x6A2670
void __fastcall Render::UpdateUIViewportScalesBasedOnAspectRatio(Render *this)
{
  if ( gDisplayAspectRatio <= 1.7777778 )
  {
    LODWORD(Render::gScreenViewportScaleH) = (_DWORD)FLOAT_1_0;
    Render::gScreenViewportScaleV = gDisplayAspectRatio * 0.5625;
  }
  else if ( gDisplayAspectRatio <= 5.3333335 )
  {
    if ( gDisplayAspectRatio <= 3.5555556 )
    {
      Render::gScreenViewportScaleH = 1.7777778 / gDisplayAspectRatio;
      LODWORD(Render::gScreenViewportScaleV) = (_DWORD)FLOAT_1_0;
    }
    else
    {
      Render::gScreenViewportScaleH = 0.33333299;
      Render::gScreenViewportScaleV = 0.33333299 / (float)(1.7777778 / gDisplayAspectRatio);
    }
  }
  else
  {
    Render::gScreenViewportScaleH = 16.0 / (float)(gDisplayAspectRatio * 9.0);
    LODWORD(Render::gScreenViewportScaleV) = (_DWORD)FLOAT_1_0;
  }
}

// File Line: 681
// RVA: 0x6A2770
Render::WndProc

// File Line: 839
// RVA: 0x69F950
void __fastcall Render::GetWindowRectAndStyle(tagRECT *rc, unsigned int *dwStyle, unsigned int *dwStyleEx, int client_w, int client_h)
{
  unsigned int *v5; // rbx
  unsigned int *v6; // rdi
  tagRECT *v7; // rsi

  *dwStyle = 13565952;
  v5 = dwStyleEx;
  v6 = dwStyle;
  *dwStyleEx = 0;
  v7 = rc;
  SetRect(rc, 0, 0, client_w, client_h);
  AdjustWindowRectEx(v7, *v6, 0, *v5);
}

// File Line: 849
// RVA: 0x6A2250
void __fastcall Render::SetWindow(int width, int height)
{
  int v2; // edi
  int yBottom; // ebx
  tagRECT rc; // [rsp+30h] [rbp-28h]
  tagRECT Rect; // [rsp+40h] [rbp-18h]

  v2 = width;
  yBottom = height;
  GetWindowRect(ghWnd, &Rect);
  SetRect(&rc, 0, 0, v2, yBottom);
  AdjustWindowRectEx(&rc, 0xCF0000u, 0, 0);
  MoveWindow(ghWnd, Rect.left, Rect.top, rc.right - rc.left, rc.bottom - rc.top, 1);
}

// File Line: 868
// RVA: 0x6A0650
signed __int64 __fastcall Render::InitWindow(Render::RenderInitParams *params)
{
  unsigned int v1; // ebx
  Render::RenderInitParams *v2; // rdi
  HMODULE v3; // rax
  HICON__ *v4; // rax
  unsigned int v5; // ebx
  HMODULE v6; // rax
  HICON__ *v7; // rax
  int v9; // er9
  __int64 yBottom; // rcx
  HWND v11; // rax
  tagRECT rc; // [rsp+60h] [rbp-78h]
  tagRECT Rect; // [rsp+70h] [rbp-68h]
  WNDCLASSEXA v14; // [rsp+80h] [rbp-58h]

  v1 = (unsigned __int16)params->mIconResourceId;
  v2 = params;
  v14.lpfnWndProc = Render::WndProc;
  v14.cbSize = 80;
  v14.style = 11;
  v14.hInstance = gInstance;
  *(_QWORD *)&v14.cbClsExtra = 0i64;
  v3 = GetModuleHandleA(0i64);
  v4 = LoadIconA(v3, (LPCSTR)v1);
  v5 = (unsigned __int16)v2->mCursorResourceId;
  v14.hIcon = v4;
  v6 = GetModuleHandleA(0i64);
  v7 = LoadCursorA(v6, (LPCSTR)v5);
  _mm_store_si128((__m128i *)&v14.hbrBackground, _mm_load_si128((const __m128i *)&_xmm));
  v14.lpszClassName = "TheoryWindowClassPC64";
  v14.hIconSm = 0i64;
  v14.hCursor = v7;
  if ( !RegisterClassExA(&v14) )
    return 0i64;
  *(_OWORD *)&gOutputParams.mDisplayMode.mBackBufferWidth = *(_OWORD *)&v2->mRenderOutputParams.mDisplayMode.mBackBufferWidth;
  v9 = _mm_cvtsi128_si32(*(__m128i *)&gOutputParams.mDisplayMode.mBackBufferWidth);
  *(_OWORD *)&gOutputParams.mDisplayMode.mAdapterUID = *(_OWORD *)&v2->mRenderOutputParams.mDisplayMode.mAdapterUID;
  *(_OWORD *)&gOutputParams.mEnableFullscreen = *(_OWORD *)&v2->mRenderOutputParams.mEnableFullscreen;
  *(_OWORD *)&gOutputParams.mShadowFilter = *(_OWORD *)&v2->mRenderOutputParams.mShadowFilter;
  *(_OWORD *)&gOutputParams.mFPSLimiter = *(_OWORD *)&v2->mRenderOutputParams.mFPSLimiter;
  *(_OWORD *)&gOutputParams.mLODSetting = *(_OWORD *)&v2->mRenderOutputParams.mLODSetting;
  *(_QWORD *)&gOutputParams.mTextureFilterQuality = *(_QWORD *)&v2->mRenderOutputParams.mTextureFilterQuality;
  if ( !v9 )
    goto LABEL_11;
  yBottom = *(_QWORD *)&gOutputParams.mDisplayMode.mBackBufferWidth >> 32;
  if ( gOutputParams.mDisplayMode.mBackBufferHeight )
  {
    gScreenHeight = yBottom;
  }
  else
  {
LABEL_11:
    v9 = g_MainViewWidth;
    LODWORD(yBottom) = g_MainViewHeight;
    gScreenHeight = g_MainViewHeight;
    gOutputParams.mDisplayMode.mBackBufferWidth = g_MainViewWidth;
    gOutputParams.mDisplayMode.mBackBufferHeight = g_MainViewHeight;
  }
  gScreenWidth = v9;
  g_Fullscreen = gOutputParams.mEnableFullscreen;
  g_PrevFullscreen = gOutputParams.mEnableFullscreen == 0;
  SetRect(&rc, 0, 0, v9, yBottom);
  AdjustWindowRectEx(&rc, 0xCF0000u, 0, 0);
  v11 = CreateWindowExA(
          0,
          "TheoryWindowClassPC64",
          v2->mTitleName,
          0xCF0000u,
          2147483648,
          2147483648,
          rc.right - rc.left,
          rc.bottom - rc.top,
          0i64,
          0i64,
          gInstance,
          0i64);
  ghWnd = v11;
  if ( !v11 )
    return 0i64;
  GetClientRect(v11, &Rect);
  ShowWindow(ghWnd, gCmdShow);
  return 1i64;
}

// File Line: 1053
// RVA: 0x69F270
void __fastcall Render::EnumerateAdaptersAndOutputs(Render *this)
{
  unsigned int v1; // er15
  int v2; // er14
  unsigned int v3; // esi
  unsigned __int64 v4; // rax
  unsigned __int64 v5; // rdi
  unsigned int v6; // ebx
  unsigned int v7; // edx
  OutputInfo *v8; // rax
  unsigned __int64 v9; // rcx
  __int64 v10; // rdi
  unsigned int v11; // ebx
  unsigned int v12; // edx
  char *v13; // rdx
  AdapterInfo *v14; // rcx
  signed __int64 v15; // rax
  __int128 v16; // xmm0
  __int64 v17; // rdx
  __int128 v18; // [rsp+30h] [rbp-D0h]
  __int128 v19; // [rsp+40h] [rbp-C0h]
  __int128 v20; // [rsp+50h] [rbp-B0h]
  __int128 v21; // [rsp+60h] [rbp-A0h]
  tagRECT v22; // [rsp+70h] [rbp-90h]
  __int128 v23; // [rsp+80h] [rbp-80h]
  __int128 v24; // [rsp+90h] [rbp-70h]
  UFG::allocator::free_link *v25; // [rsp+A0h] [rbp-60h]
  char Src; // [rsp+B0h] [rbp-50h]
  int v27; // [rsp+1E0h] [rbp+E0h]
  __int64 v28; // [rsp+1E8h] [rbp+E8h]
  unsigned int v29; // [rsp+1F0h] [rbp+F0h]
  unsigned int v30; // [rsp+1F4h] [rbp+F4h]
  unsigned int v31; // [rsp+1F8h] [rbp+F8h]
  __int64 v32; // [rsp+240h] [rbp+140h]
  __int64 v33; // [rsp+248h] [rbp+148h]

  v1 = 0;
  v2 = 0;
  if ( sDXGIFactory->vfptr[4].QueryInterface((IUnknown *)sDXGIFactory, 0i64, (void **)&v32) != -2005270526 )
  {
    do
    {
      if ( (*(signed int (__fastcall **)(__int64, GUID *, _QWORD))(*(_QWORD *)v32 + 72i64))(
             v32,
             &GUID_9b7e4c0f_342c_4106_a19f_4f2704f689f0,
             0i64) >= 0 )
      {
        (*(void (__fastcall **)(__int64, char *))(*(_QWORD *)v32 + 80i64))(v32, &Src);
        v28 = v32;
        v30 = sAvailableDXGIOutputs.size;
        v29 = v1;
        v3 = 0;
        if ( (*(unsigned int (__fastcall **)(__int64, _QWORD, __int64 *))(*(_QWORD *)v32 + 56i64))(v32, 0i64, &v33) != -2005270526 )
        {
          do
          {
            (*(void (__fastcall **)(__int64, __int128 *))(*(_QWORD *)v33 + 56i64))(v33, &v18);
            *(_QWORD *)&v24 = v33;
            *((_QWORD *)&v24 + 1) = sAvailableDXGIAdapters.size;
            v25 = 0i64;
            if ( v27 != 1 )
            {
              (*(void (__fastcall **)(__int64, signed __int64, signed __int64, char *, _QWORD))(*(_QWORD *)v33 + 64i64))(
                v33,
                28i64,
                3i64,
                (char *)&v24 + 12,
                0i64);
              if ( HIDWORD(v24) )
              {
                v4 = 28i64 * HIDWORD(v24);
                if ( !is_mul_ok(HIDWORD(v24), 0x1Cui64) )
                  v4 = -1i64;
                v25 = UFG::qMalloc(v4, UFG::gGlobalNewName, 0i64);
                (*(void (__fastcall **)(__int64, signed __int64, signed __int64, char *, UFG::allocator::free_link *))(*(_QWORD *)v33 + 64i64))(
                  v33,
                  28i64,
                  3i64,
                  (char *)&v24 + 12,
                  v25);
                v2 += HIDWORD(v24);
              }
            }
            v5 = sAvailableDXGIOutputs.size;
            v6 = sAvailableDXGIOutputs.size + 1;
            if ( sAvailableDXGIOutputs.size + 1 > sAvailableDXGIOutputs.capacity )
            {
              if ( sAvailableDXGIOutputs.capacity )
                v7 = 2 * sAvailableDXGIOutputs.capacity;
              else
                v7 = 1;
              for ( ; v7 < v6; v7 *= 2 )
                ;
              if ( v7 - v6 > 0x10000 )
                v7 = sAvailableDXGIOutputs.size + 65537;
              UFG::qArray<OutputInfo,0>::Reallocate(&sAvailableDXGIOutputs, v7, "qArray.Add");
            }
            v8 = sAvailableDXGIOutputs.p;
            sAvailableDXGIOutputs.size = v6;
            ++v3;
            v9 = v5;
            *(_OWORD *)sAvailableDXGIOutputs.p[v9].mOutputDesc.DeviceName = v18;
            *(_OWORD *)&v8[v9].mOutputDesc.DeviceName[8] = v19;
            *(_OWORD *)&v8[v9].mOutputDesc.DeviceName[16] = v20;
            *(_OWORD *)&v8[v9].mOutputDesc.DeviceName[24] = v21;
            v8[v9].mOutputDesc.DesktopCoordinates = v22;
            *(_OWORD *)&v8[v9].mOutputDesc.AttachedToDesktop = v23;
            *(_OWORD *)&v8[v9].mOutputInterface = v24;
            v8[v9].mpValidDisplayModes = (DXGI_MODE_DESC *)v25;
          }
          while ( (*(unsigned int (__fastcall **)(__int64, _QWORD, __int64 *))(*(_QWORD *)v32 + 56i64))(v32, v3, &v33) != -2005270526 );
        }
        v10 = sAvailableDXGIAdapters.size;
        v31 = v3;
        v11 = sAvailableDXGIAdapters.size + 1;
        if ( sAvailableDXGIAdapters.size + 1 > sAvailableDXGIAdapters.capacity )
        {
          if ( sAvailableDXGIAdapters.capacity )
            v12 = 2 * sAvailableDXGIAdapters.capacity;
          else
            v12 = 1;
          for ( ; v12 < v11; v12 *= 2 )
            ;
          if ( v12 - v11 > 0x10000 )
            v12 = sAvailableDXGIAdapters.size + 65537;
          UFG::qArray<AdapterInfo,0>::Reallocate(&sAvailableDXGIAdapters, v12, "qArray.Add");
        }
        v13 = &Src;
        sAvailableDXGIAdapters.size = v11;
        v14 = &sAvailableDXGIAdapters.p[v10];
        if ( ((unsigned __int8)v14 | (unsigned __int8)&Src) & 0xF )
        {
          memmove(v14, &Src, 0x150ui64);
        }
        else
        {
          v15 = 2i64;
          do
          {
            v16 = *(_OWORD *)v13;
            v14 = (AdapterInfo *)((char *)v14 + 128);
            v13 += 128;
            *(_OWORD *)&v14[-1].mAdapterDesc.Description[104] = v16;
            *(_OWORD *)&v14[-1].mAdapterDesc.Description[112] = *((_OWORD *)v13 - 7);
            *(_OWORD *)&v14[-1].mAdapterDesc.Description[120] = *((_OWORD *)v13 - 6);
            *(_OWORD *)&v14[-1].mAdapterDesc.VendorId = *((_OWORD *)v13 - 5);
            *(_OWORD *)&v14[-1].mAdapterDesc.DedicatedVideoMemory = *((_OWORD *)v13 - 4);
            *(_OWORD *)&v14[-1].mAdapterDesc.SharedSystemMemory = *((_OWORD *)v13 - 3);
            *(_OWORD *)&v14[-1].mAdapterDesc.Flags = *((_OWORD *)v13 - 2);
            *(_OWORD *)&v14[-1].mAdapterIndex = *((_OWORD *)v13 - 1);
            --v15;
          }
          while ( v15 );
          *(_OWORD *)v14->mAdapterDesc.Description = *(_OWORD *)v13;
          *(_OWORD *)&v14->mAdapterDesc.Description[8] = *((_OWORD *)v13 + 1);
          *(_OWORD *)&v14->mAdapterDesc.Description[16] = *((_OWORD *)v13 + 2);
          *(_OWORD *)&v14->mAdapterDesc.Description[24] = *((_OWORD *)v13 + 3);
          *(_OWORD *)&v14->mAdapterDesc.Description[32] = *((_OWORD *)v13 + 4);
        }
      }
      ++v1;
    }
    while ( sDXGIFactory->vfptr[4].QueryInterface((IUnknown *)sDXGIFactory, (_GUID *)v1, (void **)&v32) != -2005270526 );
    if ( v2 )
    {
      v17 = sAvailableDXGIOutputs.p->mNumValidDisplayModes - 1;
      gMonitorNativeDisplayAspectRatio = (float)(signed int)sAvailableDXGIOutputs.p->mpValidDisplayModes[v17].Width
                                       / (float)(signed int)sAvailableDXGIOutputs.p->mpValidDisplayModes[v17].Height;
    }
  }
}

// File Line: 1179
// RVA: 0x6A0CE0
void __fastcall Render::ReleaseAdaptersAndOutputs(Render *this)
{
  OutputInfo *v1; // rcx
  unsigned int v2; // edi
  unsigned __int64 v3; // rbx
  IDXGIOutput *v4; // rdx
  unsigned int v5; // edx
  AdapterInfo *v6; // rax
  unsigned int v7; // ebx
  __int64 v8; // rdi
  IDXGIAdapter1 *v9; // rcx

  v1 = sAvailableDXGIOutputs.p;
  v2 = 0;
  if ( sAvailableDXGIOutputs.size )
  {
    do
    {
      v3 = v2;
      v4 = v1[v3].mOutputInterface;
      if ( v4 )
      {
        v4->vfptr->Release((IUnknown *)&v1[v3].mOutputInterface->vfptr);
        sAvailableDXGIOutputs.p[v3].mOutputInterface = 0i64;
        v1 = sAvailableDXGIOutputs.p;
      }
      if ( v1[v3].mpValidDisplayModes )
      {
        operator delete[](v1[v3].mpValidDisplayModes);
        v1 = sAvailableDXGIOutputs.p;
      }
      ++v2;
    }
    while ( v2 < sAvailableDXGIOutputs.size );
  }
  if ( v1 )
    operator delete[](v1);
  v5 = sAvailableDXGIAdapters.size;
  v6 = sAvailableDXGIAdapters.p;
  sAvailableDXGIOutputs.p = 0i64;
  *(_QWORD *)&sAvailableDXGIOutputs.size = 0i64;
  v7 = 0;
  if ( sAvailableDXGIAdapters.size )
  {
    do
    {
      v8 = v7;
      v9 = v6[v8].mAdapterInterface;
      if ( v9 )
      {
        ((void (*)(void))v9->vfptr->Release)();
        sAvailableDXGIAdapters.p[v8].mAdapterInterface = 0i64;
        v6 = sAvailableDXGIAdapters.p;
        v5 = sAvailableDXGIAdapters.size;
      }
      ++v7;
    }
    while ( v7 < v5 );
  }
  if ( v6 )
    operator delete[](v6);
  sAvailableDXGIAdapters.p = 0i64;
  *(_QWORD *)&sAvailableDXGIAdapters.size = 0i64;
}

// File Line: 1234
// RVA: 0x6A1EB0
void __fastcall Render::SelectDXGIAdapterAndOutput(Render *this)
{
  unsigned int v1; // ebx
  unsigned int v2; // eax
  unsigned int *v3; // rcx
  __int64 v4; // rdi
  IDXGIAdapter1 *v5; // rax
  IDXGIOutput *v6; // rcx
  const unsigned __int16 *v7; // rax

  v1 = 0;
  sDXGIAdapter = 0i64;
  sDXGIOutput = 0i64;
  sSelectedOutputIndex = 0;
  v2 = 0;
  if ( sAvailableDXGIAdapters.size )
  {
    v3 = &sAvailableDXGIAdapters.p->mNumOutputs;
    while ( *v3 <= 0 )
    {
      ++v2;
      v3 += 84;
      if ( v2 >= sAvailableDXGIAdapters.size )
        return;
    }
    v4 = v2;
    v5 = sAvailableDXGIAdapters.p[v4].mAdapterInterface;
    sSelectedOutputIndex = sAvailableDXGIAdapters.p[v4].mStartOutputIndex;
    sDXGIAdapter = v5;
    v6 = sAvailableDXGIOutputs.p[sSelectedOutputIndex].mOutputInterface;
    sAvailableDXGIAdapters.p[v4].mAdapterDesc.Description[127] = 0;
    sDXGIOutput = v6;
    UFG::qWideStringCopy(Render::gVideoCardDesc, sAvailableDXGIAdapters.p[v4].mAdapterDesc.Description);
    Render::gVideoMemory = sAvailableDXGIAdapters.p[v4].mAdapterDesc.DedicatedVideoMemory;
    gOutputParams.mDisplayMode.mAdapterUID = UFG::qDataHash32(
                                               &sAvailableDXGIAdapters.p[v4].mAdapterDesc.VendorId,
                                               0x10ui64,
                                               0xFFFFFFFF);
    gOutputParams.mDisplayMode.mMonitorUID = UFG::qDataHash32(
                                               &sAvailableDXGIOutputs.p[sSelectedOutputIndex],
                                               0x58ui64,
                                               0xFFFFFFFF);
    if ( LOWORD(sAvailableDXGIAdapters.p[v4].mAdapterDesc.VendorId) == 4098 )
    {
      v7 = s_LegacyATIDevices;
      while ( LOWORD(sAvailableDXGIAdapters.p[v4].mAdapterDesc.DeviceId) != *v7 )
      {
        ++v1;
        ++v7;
        if ( v1 >= 0xE2 )
        {
          gOutputParams.mDeviceType = 2;
          return;
        }
      }
      gOutputParams.mDeviceType = 1;
    }
  }
}

// File Line: 1346
// RVA: 0x69EDB0
__int64 __fastcall Render::DisplayModesInternal(Render::DisplayMode *filter, Render::DisplayMode *outDisplayModes, bool setDXGIMode)
{
  Render::DisplayMode *v3; // r13
  unsigned int v4; // ebx
  unsigned __int64 v5; // rax
  UFG::allocator::free_link *v6; // rax
  OutputInfo *v7; // r14
  unsigned int v8; // er12
  UFG::allocator::free_link *v9; // r10
  signed __int64 v10; // rax
  DXGI_MODE_DESC *v11; // r15
  DXGI_MODE_DESC *v12; // rdx
  unsigned int v13; // eax
  Render::eDisplayScalingModes v14; // eax
  Render::eScanlineMode v15; // eax
  char v16; // di
  unsigned int v17; // er8
  signed __int64 v18; // r9
  signed int v19; // ebp
  signed __int64 v20; // r11
  unsigned int v21; // esi
  _DWORD *v22; // rcx
  int v23; // eax
  signed __int64 v24; // r11
  signed __int64 v25; // rcx
  signed int v26; // eax
  signed __int64 v27; // rcx
  Render::DisplayMode *v29; // [rsp+68h] [rbp+10h]
  bool v30; // [rsp+70h] [rbp+18h]
  signed __int64 v31; // [rsp+78h] [rbp+20h]

  v30 = setDXGIMode;
  v29 = outDisplayModes;
  v3 = filter;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&sDXGIMutex);
  v4 = 0;
  v5 = 28i64 * sAvailableDXGIOutputs.p[sSelectedOutputIndex].mNumValidDisplayModes;
  if ( !is_mul_ok(sAvailableDXGIOutputs.p[sSelectedOutputIndex].mNumValidDisplayModes, 0x1Cui64) )
    v5 = -1i64;
  v6 = UFG::qMalloc(v5, UFG::gGlobalNewName, 0i64);
  v7 = sAvailableDXGIOutputs.p;
  v8 = 0;
  v9 = v6;
  v10 = 120i64 * sSelectedOutputIndex;
  v31 = v10;
  if ( *(unsigned int *)((char *)&sAvailableDXGIOutputs.p->mNumValidDisplayModes + v10) <= 0 )
    goto LABEL_40;
  v11 = sDXGIMode;
  do
  {
    v12 = &(*(DXGI_MODE_DESC **)((char *)&v7->mpValidDisplayModes + v10))[v8];
    if ( v3->mBackBufferWidth && v3->mBackBufferWidth != v12->Width )
      goto LABEL_39;
    v13 = v3->mBackBufferHeight;
    if ( v13 )
    {
      if ( v13 != v12->Height )
        goto LABEL_39;
    }
    v14 = v3->mScaling;
    if ( v14 != -1 && v14 != v12->Scaling )
      goto LABEL_39;
    v15 = v3->mScanlineMode;
    if ( v15 != -1 && v15 != v12->ScanlineOrdering )
      goto LABEL_39;
    v16 = 0;
    v17 = 0;
    v18 = 0i64;
    v19 = -1;
    v20 = -1i64;
    if ( !v4 )
      goto LABEL_30;
    v21 = v12->Width;
    v22 = (_DWORD *)((char *)&v9[2].mNext + 4);
    while ( 1 )
    {
      if ( v21 != *(v22 - 5) || v12->Height != *(v22 - 4) || v12->ScanlineOrdering != *v22 )
        goto LABEL_24;
      if ( (float)((float)(signed int)v12->RefreshRate.Numerator / (float)(signed int)v12->RefreshRate.Denominator) < (float)((float)(signed int)*(v22 - 3) / (float)(signed int)*(v22 - 2)) )
        goto LABEL_39;
      v23 = v22[1];
      if ( (v23 || v12->Scaling == DXGI_MODE_SCALING_UNSPECIFIED) && (v23 != 2 || v12->Scaling != 1) )
        break;
      v16 = 1;
LABEL_24:
      ++v17;
      ++v18;
      v22 += 7;
      if ( v17 >= v4 )
        goto LABEL_27;
    }
    v19 = v17;
    v20 = v18;
LABEL_27:
    if ( !v16 )
    {
      if ( v19 != -1 )
      {
        v24 = 28 * v20;
        *(_DWORD *)((char *)&v9->mNext + v24) = v21;
        *(_DWORD *)((char *)&v9->mNext + v24 + 4) = v12->Height;
        *(_DWORD *)((char *)&v9[1].mNext + v24) = v12->RefreshRate.Numerator;
        *(_DWORD *)((char *)&v9[1].mNext + v24 + 4) = v12->RefreshRate.Denominator;
        *(_DWORD *)((char *)&v9[2].mNext + v24) = *(_DWORD *)v12->Format;
        *(_DWORD *)((char *)&v9[2].mNext + v24 + 4) = v12->ScanlineOrdering;
        *(_DWORD *)((char *)&v9[3].mNext + v24) = v12->Scaling;
        goto LABEL_31;
      }
LABEL_30:
      v25 = 28i64 * v4;
      *(_DWORD *)((char *)&v9->mNext + v25) = v12->Width;
      *(_DWORD *)((char *)&v9->mNext + v25 + 4) = v12->Height;
      *(_DWORD *)((char *)&v9[1].mNext + v25) = v12->RefreshRate.Numerator;
      *(_DWORD *)((char *)&v9[1].mNext + v25 + 4) = v12->RefreshRate.Denominator;
      *(_DWORD *)((char *)&v9[2].mNext + v25) = *(_DWORD *)v12->Format;
      *(_DWORD *)((char *)&v9[2].mNext + v25 + 4) = v12->ScanlineOrdering;
      *(_DWORD *)((char *)&v9[3].mNext + v25) = v12->Scaling;
LABEL_31:
      if ( v29 )
      {
        v26 = v19;
        if ( v19 == -1 )
          v26 = v4;
        v27 = v26;
        v29[v27].mBackBufferWidth = v12->Width;
        v29[v27].mBackBufferHeight = v12->Height;
        v29[v27].mRefreshRateNumerator = v12->RefreshRate.Numerator;
        v29[v27].mRefreshRateDenominator = v12->RefreshRate.Denominator;
        v29[v27].mAdapterUID = gOutputParams.mDisplayMode.mAdapterUID;
        v29[v27].mMonitorUID = gOutputParams.mDisplayMode.mMonitorUID;
        v29[v27].mScaling = v12->Scaling;
        v29[v27].mScanlineMode = v12->ScanlineOrdering;
      }
      v7 = sAvailableDXGIOutputs.p;
      if ( v30 )
        v11 = v12;
      sDXGIMode = v11;
      if ( v19 == -1 )
        ++v4;
    }
LABEL_39:
    v10 = v31;
    ++v8;
  }
  while ( v8 < *(unsigned int *)((char *)&v7->mNumValidDisplayModes + v31) );
LABEL_40:
  operator delete[](v9);
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&sDXGIMutex);
  return v4;
}

// File Line: 1443
// RVA: 0x69F890
__int64 __fastcall Render::GetDisplayModeCount(Render::DisplayMode *filter)
{
  return Render::DisplayModesInternal(filter, 0i64, 0);
}

// File Line: 1449
// RVA: 0x69F880
void __fastcall Render::GetDisplayModeArray(Render::DisplayMode *filter, Render::DisplayMode *outDisplayModes)
{
  Render::DisplayModesInternal(filter, outDisplayModes, 0);
}

// File Line: 1454
// RVA: 0x6A2730
bool __fastcall Render::ValidateDisplaySettings(Render::RenderOutputParams *settings)
{
  bool result; // al

  if ( *(_QWORD *)&settings->mDisplayMode.mAdapterUID == *(_QWORD *)&gOutputParams.mDisplayMode.mAdapterUID )
    result = (unsigned int)Render::DisplayModesInternal(&settings->mDisplayMode, 0i64, 0) == 1;
  else
    result = 0;
  return result;
}

// File Line: 1471
// RVA: 0x69E7C0
void __fastcall Render::ApplyDisplaySettings(Render::RenderOutputParams *settings)
{
  Render::RenderOutputParams *v1; // rbx
  char v2; // cl
  bool v3; // zf
  char v4; // cl
  char v5; // cl
  char v6; // cl
  char v7; // cl
  char v8; // dl
  __m128i v9; // xmm2
  __int64 v10; // xmm1_8
  char v11; // al
  Render::DisplayMode outDisplayModes; // [rsp+20h] [rbp-28h]

  v1 = settings;
  if ( Render::DisplayModesInternal(&settings->mDisplayMode, 0i64, 0) == 1 )
  {
    Render::DisplayModesInternal(&v1->mDisplayMode, &outDisplayModes, 1);
    Illusion::SetDefaultTextureFilterQuality(v1->mTextureFilterQuality);
    v2 = sbEventResizeShadows;
    if ( v1->mShadowRes != gOutputParams.mShadowRes )
      v2 = 1;
    v3 = v1->mAAQuality == gOutputParams.mAAQuality;
    sbEventResizeShadows = v2;
    v4 = sbEventResizeBuffers;
    if ( !v3 )
      v4 = 1;
    if ( v1->mSSAO != gOutputParams.mSSAO )
      v4 = 1;
    v3 = v1->mTextureDetailLevel == gOutputParams.mTextureDetailLevel;
    sbEventResizeBuffers = v4;
    v5 = sbEventChangeTexturePack;
    if ( !v3 )
      v5 = 1;
    v3 = v1->mLODSetting == gOutputParams.mLODSetting;
    sbEventChangeTexturePack = v5;
    v6 = sbEventChangeLODSetting;
    if ( !v3 )
      v6 = 1;
    sbEventChangeLODSetting = v6;
    v7 = 0;
    if ( v1->mDisplayMode.mBackBufferHeight != gOutputParams.mDisplayMode.mBackBufferHeight
      || v1->mDisplayMode.mBackBufferWidth != gOutputParams.mDisplayMode.mBackBufferWidth
      || g_Fullscreen != v1->mEnableFullscreen )
    {
      v7 = 1;
    }
    v8 = v7;
    v3 = gOutputParams.mEnableLowResBuffer == v1->mEnableLowResBuffer;
    *(_OWORD *)&gOutputParams.mDisplayMode.mBackBufferWidth = *(_OWORD *)&v1->mDisplayMode.mBackBufferWidth;
    if ( !v3 )
      v8 = 1;
    *(_OWORD *)&gOutputParams.mDisplayMode.mAdapterUID = *(_OWORD *)&v1->mDisplayMode.mAdapterUID;
    *(_OWORD *)&gOutputParams.mEnableFullscreen = *(_OWORD *)&v1->mEnableFullscreen;
    v9 = _mm_srli_si128(*(__m128i *)&gOutputParams.mEnableFullscreen, 3);
    *(_OWORD *)&gOutputParams.mShadowFilter = *(_OWORD *)&v1->mShadowFilter;
    *(_OWORD *)&gOutputParams.mFPSLimiter = *(_OWORD *)&v1->mFPSLimiter;
    *(_OWORD *)&gOutputParams.mLODSetting = *(_OWORD *)&v1->mLODSetting;
    v10 = *(_QWORD *)&v1->mTextureFilterQuality;
    gOutputParams.mDisplayMode.mRefreshRateNumerator = outDisplayModes.mRefreshRateNumerator;
    *(_QWORD *)&gOutputParams.mTextureFilterQuality = v10;
    gOutputParams.mDisplayMode.mRefreshRateDenominator = outDisplayModes.mRefreshRateDenominator;
    g_Fullscreen = v1->mEnableFullscreen;
    g_signalEnable3D = v1->mEnable3D;
    if ( g_signalEnable3D != g_enable3D )
      v8 = 1;
    g_interAxialDistance = v1->mInterAxialDistance;
    Render::gEnableCloudVolumes = v1->mEnableCloudVolumes;
    UFG::gEnableHalfResolutionGbuffer = _mm_cvtsi128_si32(v9);
    v11 = sbEventResizeSwapChain;
    if ( v8 )
      v11 = 1;
    sbEventResizeSwapChain = v11;
  }
}

// File Line: 1535
// RVA: 0x69F820
void __fastcall Render::GetCurrentDisplaySettings(Render::RenderOutputParams *outSettings)
{
  *(_OWORD *)&outSettings->mDisplayMode.mBackBufferWidth = *(_OWORD *)&gOutputParams.mDisplayMode.mBackBufferWidth;
  *(_OWORD *)&outSettings->mDisplayMode.mAdapterUID = *(_OWORD *)&gOutputParams.mDisplayMode.mAdapterUID;
  *(_OWORD *)&outSettings->mEnableFullscreen = *(_OWORD *)&gOutputParams.mEnableFullscreen;
  *(_OWORD *)&outSettings->mShadowFilter = *(_OWORD *)&gOutputParams.mShadowFilter;
  *(_OWORD *)&outSettings->mFPSLimiter = *(_OWORD *)&gOutputParams.mFPSLimiter;
  *(_OWORD *)&outSettings->mLODSetting = *(_OWORD *)&gOutputParams.mLODSetting;
  *(_QWORD *)&outSettings->mTextureFilterQuality = *(_QWORD *)&gOutputParams.mTextureFilterQuality;
}

// File Line: 1541
// RVA: 0x69F8A0
float __fastcall Render::GetExtraWideAspectCorrectedFOV(float inputFOV)
{
  float v1; // xmm6_4
  float v2; // xmm1_4
  float v3; // xmm2_4
  float v4; // xmm0_4
  float v5; // xmm2_4

  v1 = inputFOV;
  if ( inputFOV <= 1.085 )
    v2 = FLOAT_1_085;
  else
    v2 = inputFOV;
  v3 = powf(1.085 / v2, gExtraWideAspectFOVCorrectionPOW);
  v4 = *(float *)&FLOAT_1_0;
  v5 = (float)(v3 * (float)((float)((float)(gDisplayAspectRatio * 0.5625) - 1.0) * gExtraWideAspectFOVCorrection)) + 1.0;
  if ( v5 >= 1.0 )
    v4 = v5;
  return v4 * v1;
}

// File Line: 1547
// RVA: 0x6A2080
void __fastcall Render::SetInitialDisplayMode(Render *this)
{
  OutputInfo *v1; // rdx
  bool v2; // bl
  char v3; // al
  Render::DisplayMode filter; // [rsp+20h] [rbp-28h]

  if ( (unsigned int)Render::DisplayModesInternal(&gOutputParams.mDisplayMode, 0i64, 0) == 1 )
  {
    Render::ApplyDisplaySettings(&gOutputParams);
  }
  else
  {
    filter.mScanlineMode = 1;
    *(_QWORD *)&filter.mRefreshRateNumerator = 0i64;
    *(_QWORD *)&filter.mAdapterUID = 0i64;
    filter.mScaling = 0;
    v1 = &sAvailableDXGIOutputs.p[sSelectedOutputIndex];
    if ( v1->mOutputDesc.AttachedToDesktop )
    {
      filter.mBackBufferWidth = v1->mOutputDesc.DesktopCoordinates.right - v1->mOutputDesc.DesktopCoordinates.left;
      filter.mBackBufferHeight = v1->mOutputDesc.DesktopCoordinates.bottom - v1->mOutputDesc.DesktopCoordinates.top;
    }
    else
    {
      *(_QWORD *)&filter.mBackBufferWidth = 0i64;
    }
    if ( !(unsigned int)Render::DisplayModesInternal(&filter, 0i64, 1) )
    {
      *(_QWORD *)&filter.mBackBufferWidth = 0i64;
      if ( !(unsigned int)Render::DisplayModesInternal(&filter, 0i64, 1) )
      {
        filter.mScaling = -1;
        if ( !(unsigned int)Render::DisplayModesInternal(&filter, 0i64, 1) )
        {
          filter.mScanlineMode = -1;
          Render::DisplayModesInternal(&filter, 0i64, 1);
        }
      }
    }
  }
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&sDXGIMutex);
  if ( sDXGIMode )
  {
    v2 = sDXGIMode->Height != gOutputParams.mDisplayMode.mBackBufferHeight
      || sDXGIMode->Width != gOutputParams.mDisplayMode.mBackBufferWidth;
    gOutputParams.mDisplayMode.mBackBufferWidth = sDXGIMode->Width;
    gOutputParams.mDisplayMode.mBackBufferHeight = sDXGIMode->Height;
    gOutputParams.mDisplayMode.mRefreshRateNumerator = sDXGIMode->RefreshRate.Numerator;
    gOutputParams.mDisplayMode.mRefreshRateDenominator = sDXGIMode->RefreshRate.Denominator;
    gOutputParams.mDisplayMode.mScaling = sDXGIMode->Scaling;
    gOutputParams.mDisplayMode.mScanlineMode = sDXGIMode->ScanlineOrdering;
    Render::ApplyDisplaySettings(&gOutputParams);
    v3 = sbEventResizeSwapChain;
    if ( v2 )
      v3 = 1;
    sbEventResizeSwapChain = v3;
  }
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&sDXGIMutex);
}

// File Line: 1627
// RVA: 0x6A0E00
void __fastcall Render::ReleaseD3D(Render *this)
{
  _QWORD *v1; // rbx
  signed __int64 v2; // rdi
  __int64 v3; // rcx
  __int64 v4; // rcx
  __int64 v5; // rcx

  Render::ReleaseAdaptersAndOutputs(this);
  if ( sDXGIFactory )
  {
    ((void (*)(void))sDXGIFactory->vfptr->Release)();
    sDXGIFactory = 0i64;
  }
  if ( sDXGIDevice )
  {
    ((void (*)(void))sDXGIDevice->vfptr->Release)();
    sDXGIDevice = 0i64;
  }
  if ( sContext )
  {
    ((void (*)(void))sContext->vfptr->Release)();
    sContext = 0i64;
  }
  if ( sDevice )
  {
    ((void (*)(void))sDevice->vfptr->Release)();
    sDevice = 0i64;
  }
  if ( sStereo3D )
  {
    ((void (*)(void))sStereo3D->vfptr->Release)();
    sStereo3D = 0i64;
  }
  sDXGIMode = 0i64;
  sDXGIPrevMode = 0i64;
  v1 = 0i64;
  v2 = 2i64;
  do
  {
    v3 = v1[675836757];
    if ( v3 )
    {
      (*(void (**)(void))(*(_QWORD *)v3 + 16i64))();
      v1[675836757] = 0i64;
    }
    v4 = v1[675836759];
    if ( v4 )
    {
      (*(void (**)(void))(*(_QWORD *)v4 + 16i64))();
      v1[675836759] = 0i64;
    }
    v5 = v1[675836761];
    if ( v5 )
    {
      (*(void (**)(void))(*(_QWORD *)v5 + 16i64))();
      v1[675836761] = 0i64;
    }
    ++v1;
    --v2;
  }
  while ( v2 );
}

// File Line: 1646
// RVA: 0x69FA10
char __fastcall Render::InitD3D(Render *a1)
{
  Render *v1; // rcx
  Render *v2; // rcx
  Render *v3; // rcx
  char v4; // di
  UFG::allocator::free_link *v5; // rcx
  UFG::allocator::free_link *v6; // rax
  UFG::allocator::free_link *v7; // rax
  float v8; // xmm0_4
  __int64 v9; // rdi
  signed __int64 v10; // rsi
  NV_GET_CURRENT_SLI_STATE pSliState; // [rsp+58h] [rbp-240h]
  NvPhysicalGpuHandle__ *nvGPUHandle; // [rsp+80h] [rbp-218h]
  unsigned int pGpuCount; // [rsp+2A0h] [rbp+8h]
  int v15; // [rsp+2A8h] [rbp+10h]
  UFG::allocator::free_link *v16; // [rsp+2B0h] [rbp+18h]

  Render::ReleaseD3D(a1);
  CreateDXGIFactory1_0(&GUID_770aae78_f26f_4dba_a829_253c83d1b387, (void **)&sDXGIFactory);
  Render::EnumerateAdaptersAndOutputs(v1);
  if ( !sAvailableDXGIOutputs.size )
    goto LABEL_32;
  Render::SelectDXGIAdapterAndOutput(v2);
  Render::SetInitialDisplayMode(v3);
  v4 = 0;
  if ( (unsigned int)NvAPI_Initialize() || NvAPI_EnumPhysicalGPUs(&nvGPUHandle, &pGpuCount) || pGpuCount <= 0 )
  {
    v6 = UFG::qMalloc(0x30ui64, UFG::gGlobalNewName, 0i64);
    v16 = v6;
    if ( v6 )
    {
      AMDStereo3D::AMDStereo3D((AMDStereo3D *)v6);
      v5 = v7;
    }
    else
    {
      v5 = 0i64;
    }
  }
  else
  {
    v5 = UFG::qMalloc(0x18ui64, UFG::gGlobalNewName, 0i64);
    v16 = v5;
    if ( v5 )
    {
      v5->mNext = (UFG::allocator::free_link *)&Stereo3D::`vftable';
      v5->mNext = (UFG::allocator::free_link *)&NVStereo3D::`vftable';
      LOWORD(v5[2].mNext) = 0;
    }
    else
    {
      v5 = 0i64;
    }
    v4 = 1;
  }
  sStereo3D = (Stereo3D *)v5;
  ((void (*)(void))v5->mNext[1].mNext)();
  if ( (signed int)D3D11CreateDevice_0(sDXGIAdapter, 0i64, 0i64, 32i64, 0i64, 0, 7, &sDevice, &v15, &sContext, -2i64) < 0 )
    goto LABEL_32;
  if ( v15 < 40960 )
    return 0;
  gOutputParams.mFeatureLevel = v15 < 0xB000 ? (unsigned __int8)(v15 >= 41216) : 2;
  if ( v4 )
  {
    pSliState.version = 65564;
    if ( NvAPI_D3D_GetCurrentSLIState((IUnknown *)sDevice, &pSliState) == NVAPI_OK )
    {
      v8 = *(float *)&FLOAT_1_0;
      if ( (float)(signed int)pSliState.maxNumAFRGroups >= 1.0 )
        v8 = (float)(signed int)pSliState.maxNumAFRGroups;
      gNumGPUs = (signed int)v8;
      if ( pSliState.maxNumAFRGroups > 4 )
        gNumGPUs = 4;
    }
  }
  else
  {
    gNumGPUs = 1;
  }
  sStereo3D->vfptr->InitStereo3D(sStereo3D, sDevice, ghWnd);
  if ( ((__int64 (__fastcall *)(ID3D11Device *, GUID *, IDXGIDevice1 **))sDevice->vfptr->QueryInterface)(
         sDevice,
         &GUID_77db970f_6276_48ba_ba28_070143b4392c,
         &sDXGIDevice) < 0 )
  {
LABEL_32:
    Render::ReleaseD3D(v2);
    return 0;
  }
  v9 = 0i64;
  v10 = 2i64;
  do
  {
    *(_QWORD *)&pGpuCount = 0i64;
    pGpuCount = 3;
    ((void (__fastcall *)(ID3D11Device *, unsigned int *, ID3D11Query **))sDevice->vfptr->OMSetRenderTargets)(
      sDevice,
      &pGpuCount,
      &sQueryGPUTimeStampDisjoint[v9]);
    pGpuCount = 2;
    ((void (__fastcall *)(ID3D11Device *, unsigned int *, ID3D11Query **))sDevice->vfptr->OMSetRenderTargets)(
      sDevice,
      &pGpuCount,
      &sQueryGPUTimeStart[v9]);
    ((void (__fastcall *)(ID3D11Device *, unsigned int *, ID3D11Query **))sDevice->vfptr->OMSetRenderTargets)(
      sDevice,
      &pGpuCount,
      &sQueryGPUTimeEnd[v9]);
    ++v9;
    --v10;
  }
  while ( v10 );
  gQuereyGPUwriteIndex = 1;
  gQuereyGPUreadIndex = 0;
  return 1;
}

// File Line: 1832
// RVA: 0x6A0F60
void __fastcall Render::ReleaseSwapChain(Render *this)
{
  IDXGISwapChain *v1; // rcx

  v1 = sDXGISwapChain;
  if ( sDXGISwapChain )
  {
    ((void (__fastcall *)(IDXGISwapChain *, _QWORD, _QWORD))sDXGISwapChain->vfptr[3].AddRef)(sDXGISwapChain, 0i64, 0i64);
    v1 = sDXGISwapChain;
  }
  if ( sPresentRenderTargetView )
  {
    sPresentRenderTargetView->vfptr->Release((IUnknown *)sPresentRenderTargetView);
    v1 = sDXGISwapChain;
    sPresentRenderTargetView = 0i64;
  }
  if ( gPresentBuffer )
  {
    gPresentBuffer->vfptr->Release((IUnknown *)gPresentBuffer);
    v1 = sDXGISwapChain;
    gPresentBuffer = 0i64;
  }
  if ( v1 )
  {
    ((void (*)(void))v1->vfptr->Release)();
    sDXGISwapChain = 0i64;
  }
}

// File Line: 1844
// RVA: 0x6A04D0
char __fastcall Render::InitSwapChain(__int64 fullscreen)
{
  char v1; // bl
  Render *v2; // rcx
  __int64 v4; // [rsp+30h] [rbp-50h]
  __int64 v5; // [rsp+38h] [rbp-48h]
  __int64 v6; // [rsp+40h] [rbp-40h]
  __int64 v7; // [rsp+48h] [rbp-38h]
  __int64 v8; // [rsp+50h] [rbp-30h]
  __int64 v9; // [rsp+58h] [rbp-28h]
  HWND v10; // [rsp+60h] [rbp-20h]
  _BOOL8 v11; // [rsp+68h] [rbp-18h]
  __int64 v12; // [rsp+70h] [rbp-10h]

  v1 = fullscreen;
  Render::ReleaseSwapChain((Render *)fullscreen);
  v6 = 0i64;
  v7 = 0i64;
  v9 = 0i64;
  v12 = 0i64;
  v4 = __PAIR__(gScreenHeight, gScreenWidth);
  LODWORD(v6) = 28;
  *(__int64 *)((char *)&v7 + 4) = 1i64;
  v10 = ghWnd;
  v11 = v1 == 0;
  v5 = *(_QWORD *)&gOutputParams.mDisplayMode.mRefreshRateNumerator;
  HIDWORD(v8) = 32;
  LODWORD(v9) = 2;
  LODWORD(v12) = 2;
  g_stereoSwapChain = 0;
  if ( !g_enable3D
    || sStereo3D->vfptr->CreateStereoSwapChain(
         sStereo3D,
         sDXGIFactory,
         sDevice,
         (DXGI_SWAP_CHAIN_DESC *)&v4,
         &sDXGISwapChain) )
  {
    if ( ((signed int (__fastcall *)(IDXGIFactory1 *, ID3D11Device *, __int64 *, IDXGISwapChain **))sDXGIFactory->vfptr[3].AddRef)(
           sDXGIFactory,
           sDevice,
           &v4,
           &sDXGISwapChain) < 0 )
      goto $D3D_ERROR_HANDLER_0;
  }
  else
  {
    g_stereoSwapChain = 1;
  }
  if ( ((signed int (__fastcall *)(IDXGISwapChain *, _QWORD, GUID *, ID3D11Texture2D **))sDXGISwapChain->vfptr[3].QueryInterface)(
         sDXGISwapChain,
         0i64,
         &GUID_6f15aaf2_d208_4e89_9ab4_489535d34f9c,
         &gPresentBuffer) >= 0
    && ((signed int (__fastcall *)(ID3D11Device *, ID3D11Texture2D *, _QWORD, ID3D11RenderTargetView **))sDevice->vfptr->Draw)(
         sDevice,
         gPresentBuffer,
         0i64,
         &sPresentRenderTargetView) >= 0 )
  {
    return 1;
  }
$D3D_ERROR_HANDLER_0:
  Render::ReleaseSwapChain(v2);
  return 0;
}

// File Line: 1908
// RVA: 0x6A03A0
void __fastcall Render::InitEngineCB(Render::RenderInitParams *params)
{
  char v1; // bl
  Render *v2; // rcx

  Render::InitWindow(params);
  v1 = 0;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&sDXGIMutex);
  if ( Render::InitD3D(v2) )
  {
    v1 = 0;
    if ( Render::InitSwapChain(0i64) )
      v1 = 1;
  }
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&sDXGIMutex);
  if ( v1 )
  {
    Illusion::EnginePlat::SetDevice((hkProcessContext *)&Illusion::gEnginePlat, (hkVisualDebugger *)sDevice);
    Illusion::EnginePlat::SetContext(&Illusion::gEnginePlat, sContext);
    Illusion::gEnginePlat.mMaxGpuFramesInFlight = gNumGPUs + 1;
  }
}

// File Line: 1939
// RVA: 0x69FD10
void __fastcall Render::InitEngine(Render::RenderInitParams *params)
{
  Render::RenderInitParams *v1; // r14
  Illusion *v2; // rcx
  ID3D11DeviceContext *v3; // rax
  Illusion *v4; // rcx
  Render *v5; // rcx
  unsigned int v6; // edi
  unsigned int v7; // ebx
  UFG::allocator::free_link *v8; // rax
  int v9; // edi
  unsigned int v10; // ebx
  Illusion::FrameWriteMemoryPlat *v11; // rsi
  int v12; // edi
  unsigned int v13; // ebx
  Illusion::FrameWriteMemoryPlat *v14; // rsi
  unsigned int v15; // ebx
  unsigned int v16; // ebx
  Render *v17; // rcx
  Render *v18; // rcx
  int v19; // [rsp+20h] [rbp-C8h]
  __int64 v20; // [rsp+24h] [rbp-C4h]
  __int64 v21; // [rsp+2Ch] [rbp-BCh]
  int v22; // [rsp+34h] [rbp-B4h]
  UFG::qVRAMemoryHandle handle; // [rsp+38h] [rbp-B0h]
  UFG::qString v24; // [rsp+60h] [rbp-88h]
  int v25; // [rsp+8Ch] [rbp-5Ch]
  int v26; // [rsp+90h] [rbp-58h]
  __int128 v27; // [rsp+98h] [rbp-50h]
  __int128 v28; // [rsp+A8h] [rbp-40h]
  __int64 v29; // [rsp+B8h] [rbp-30h]
  __int64 v30; // [rsp+C0h] [rbp-28h]
  __int64 v31; // [rsp+C8h] [rbp-20h]
  __int64 v32; // [rsp+D0h] [rbp-18h]
  __int64 v33; // [rsp+D8h] [rbp-10h]
  __int64 v34; // [rsp+E0h] [rbp-8h]
  int v35; // [rsp+E8h] [rbp+0h]
  char v36; // [rsp+ECh] [rbp+4h]
  UFG::qString v37; // [rsp+F8h] [rbp+10h]
  __int64 v38; // [rsp+120h] [rbp+38h]
  int v39; // [rsp+128h] [rbp+40h]
  int v40; // [rsp+12Ch] [rbp+44h]
  int v41; // [rsp+130h] [rbp+48h]
  __int64 v42; // [rsp+134h] [rbp+4Ch]
  int v43; // [rsp+13Ch] [rbp+54h]
  int v44; // [rsp+140h] [rbp+58h]
  __int128 v45; // [rsp+148h] [rbp+60h]
  __int128 v46; // [rsp+158h] [rbp+70h]
  __int64 v47; // [rsp+168h] [rbp+80h]
  __int64 v48; // [rsp+170h] [rbp+88h]
  __int64 v49; // [rsp+178h] [rbp+90h]
  __int64 v50; // [rsp+180h] [rbp+98h]
  __int64 v51; // [rsp+188h] [rbp+A0h]
  __int64 v52; // [rsp+190h] [rbp+A8h]
  int v53; // [rsp+198h] [rbp+B0h]
  char v54; // [rsp+19Ch] [rbp+B4h]
  UFG::qString v55; // [rsp+1A8h] [rbp+C0h]
  __int64 v56; // [rsp+1D0h] [rbp+E8h]
  int v57; // [rsp+1D8h] [rbp+F0h]
  int v58; // [rsp+1DCh] [rbp+F4h]
  int v59; // [rsp+1E0h] [rbp+F8h]
  __int64 v60; // [rsp+1E4h] [rbp+FCh]
  int v61; // [rsp+1ECh] [rbp+104h]
  int v62; // [rsp+1F0h] [rbp+108h]
  __int128 v63; // [rsp+1F8h] [rbp+110h]
  __int128 v64; // [rsp+208h] [rbp+120h]
  __int64 v65; // [rsp+218h] [rbp+130h]
  __int64 v66; // [rsp+220h] [rbp+138h]
  __int64 v67; // [rsp+228h] [rbp+140h]
  __int64 v68; // [rsp+230h] [rbp+148h]
  __int64 v69; // [rsp+238h] [rbp+150h]
  __int64 v70; // [rsp+240h] [rbp+158h]
  int v71; // [rsp+248h] [rbp+160h]
  char v72; // [rsp+24Ch] [rbp+164h]
  UFG::qString v73; // [rsp+258h] [rbp+170h]
  __int64 v74; // [rsp+280h] [rbp+198h]
  int v75; // [rsp+288h] [rbp+1A0h]
  int v76; // [rsp+28Ch] [rbp+1A4h]
  int v77; // [rsp+290h] [rbp+1A8h]
  __int64 v78; // [rsp+294h] [rbp+1ACh]
  int v79; // [rsp+29Ch] [rbp+1B4h]
  int v80; // [rsp+2A0h] [rbp+1B8h]
  __int128 v81; // [rsp+2A8h] [rbp+1C0h]
  __int128 v82; // [rsp+2B8h] [rbp+1D0h]
  __int64 v83; // [rsp+2C8h] [rbp+1E0h]
  __int64 v84; // [rsp+2D0h] [rbp+1E8h]
  __int64 v85; // [rsp+2D8h] [rbp+1F0h]
  __int64 v86; // [rsp+2E0h] [rbp+1F8h]
  __int64 v87; // [rsp+2E8h] [rbp+200h]
  __int64 v88; // [rsp+2F0h] [rbp+208h]
  int v89; // [rsp+2F8h] [rbp+210h]
  char v90; // [rsp+2FCh] [rbp+214h]
  __int64 v91; // [rsp+308h] [rbp+220h]

  v91 = -2i64;
  v1 = params;
  Illusion::AddRenderThreadCommand(RTCMD_CALLBACK, Render::InitEngineCB, params, 0i64);
  Illusion::WaitForRenderThread(v2);
  v3 = Illusion::EnginePlat::AllocDeferredContextBlocking(&Illusion::gEnginePlat);
  v4 = (Illusion *)*((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index);
  *((_QWORD *)v4 + 13) = v3;
  Illusion::RenderStateInit(v4);
  Illusion::OcclusionPlat::InitBank(&Illusion::gOcclusionPlat, 0x280u, 1u);
  MainThreadID = GetCurrentThreadId();
  gDisplayAspectRatio = (float)gScreenWidth / (float)gScreenHeight;
  Render::UpdateUIViewportScalesBasedOnAspectRatio(v5);
  CurrFrameBuffer = 0;
  Render::SetFrameMemoryNumBuffers(2u);
  v6 = 0;
  do
  {
    v7 = (v1->mFrameMemoryTotalBytes >> 1) & 0x7FFFFF80;
    v8 = UFG::qMalloc(v7, "FrameMemoryBuffer", 0x8000ui64);
    Render::SetFrameMemory(v6, v8, v7);
    Render::SetFrameMemoryOverflow(v6++, 0i64, 0);
  }
  while ( v6 < 2 );
  v9 = (v1->mFrameWriteMemoryTotalBytes >> 1) & 0x7FFFFF80;
  Illusion::gFrameWriteMemoryPlat.mBufferSize = (v1->mFrameWriteMemoryTotalBytes >> 1) & 0x7FFFFF80;
  Illusion::gFrameWriteMemoryPlat.mNumFrameMemoryBuffers = 2;
  UFG::qVRAMemoryHandle::qVRAMemoryHandle(&handle);
  v10 = 0;
  v11 = &Illusion::gFrameWriteMemoryPlat;
  do
  {
    v21 = 0i64;
    v22 = 0;
    v19 = v9;
    v20 = 0x300000002i64;
    LODWORD(v21) = 0x10000;
    ((void (__fastcall *)(ID3D11Device *, int *, _QWORD, Illusion::FrameWriteMemoryPlat *, _QWORD, _QWORD, _QWORD))UFG::gD3D11Device->vfptr->VSSetConstantBuffers)(
      UFG::gD3D11Device,
      &v19,
      0i64,
      v11,
      *(_QWORD *)&v19,
      *(__int64 *)((char *)&v20 + 4),
      BYTE4(v21));
    Illusion::FrameWriteMemoryPlat::Lock(&Illusion::gFrameWriteMemoryPlat, v10);
    Render::SetFrameWriteMemory(
      v10,
      Illusion::gFrameWriteMemoryPlat.mLockData,
      &handle,
      Illusion::gFrameWriteMemoryPlat.mBufferSize);
    Render::SetFrameWriteMemoryOverflow(v10, 0i64, &handle, 0);
    Illusion::FrameWriteMemoryPlat::Unlock(&Illusion::gFrameWriteMemoryPlat);
    ++v10;
    v11 = (Illusion::FrameWriteMemoryPlat *)((char *)v11 + 8);
  }
  while ( v10 < 2 );
  v12 = (v1->mPrimitiveFrameWriteMemoryTotalBytes >> 1) & 0x7FFFFF80;
  Illusion::gPrimitiveFrameWriteMemoryPlat.mBufferSize = (v1->mPrimitiveFrameWriteMemoryTotalBytes >> 1) & 0x7FFFFF80;
  Illusion::gPrimitiveFrameWriteMemoryPlat.mNumFrameMemoryBuffers = 2;
  v13 = 0;
  v14 = &Illusion::gPrimitiveFrameWriteMemoryPlat;
  do
  {
    v21 = 0i64;
    v22 = 0;
    v19 = v12;
    v20 = 12884901890i64;
    LODWORD(v21) = 0x10000;
    ((void (__fastcall *)(ID3D11Device *, int *, _QWORD, Illusion::FrameWriteMemoryPlat *, _QWORD, _QWORD, _QWORD))UFG::gD3D11Device->vfptr->VSSetConstantBuffers)(
      UFG::gD3D11Device,
      &v19,
      0i64,
      v14,
      *(_QWORD *)&v19,
      *(__int64 *)((char *)&v20 + 4),
      BYTE4(v21));
    Illusion::FrameWriteMemoryPlat::Lock(&Illusion::gPrimitiveFrameWriteMemoryPlat, v13);
    Render::SetPrimitiveFrameWriteMemory(
      v13,
      Illusion::gPrimitiveFrameWriteMemoryPlat.mLockData,
      &handle,
      Illusion::gPrimitiveFrameWriteMemoryPlat.mBufferSize);
    Render::SetPrimitiveFrameWriteMemoryOverflow(v13, 0i64, &handle, 0);
    Illusion::FrameWriteMemoryPlat::Unlock(&Illusion::gPrimitiveFrameWriteMemoryPlat);
    ++v13;
    v14 = (Illusion::FrameWriteMemoryPlat *)((char *)v14 + 8);
  }
  while ( v13 < 2 );
  v15 = 0;
  do
  {
    Render::SetFramePatchMemory(v15, 0i64, &handle, 0);
    Render::SetFramePatchMemoryOverflow(v15++, 0i64, &handle, 0);
  }
  while ( v15 < 2 );
  v16 = 0;
  do
  {
    Render::SetFrameIndexMemory(v16, 0i64, &handle, 0);
    Render::SetFrameIndexMemoryOverflow(v16++, 0i64, &handle, 0);
  }
  while ( v16 < 2 );
  Render::SwapFrameMemoryBuffers(v17);
  UFG::qString::qString(&v73, "BackBuffer");
  v78 = 1i64;
  v74 = 0i64;
  v75 = 1;
  v76 = 1;
  v77 = -1;
  v79 = 0;
  v80 = 1;
  _mm_store_si128((__m128i *)&v81, (__m128i)0i64);
  _mm_store_si128((__m128i *)&v82, (__m128i)0i64);
  v83 = 0i64;
  v84 = 0i64;
  v85 = 0i64;
  v86 = 0i64;
  v87 = 0i64;
  v88 = 0i64;
  v89 = 0;
  v90 = 0;
  v74 = __PAIR__(gScreenHeight, gScreenWidth);
  LOBYTE(v77) = 0;
  v79 = 19;
  BackBufferTarget = Illusion::CreateTarget((Illusion::CreateTargetParams *)&v73);
  UFG::qString::qString(&v55, "PresentBuffer");
  v60 = 1i64;
  v56 = 0i64;
  v57 = 1;
  v58 = 1;
  v59 = -1;
  v61 = 0;
  v62 = 1;
  _mm_store_si128((__m128i *)&v63, (__m128i)0i64);
  _mm_store_si128((__m128i *)&v64, (__m128i)0i64);
  v65 = 0i64;
  v66 = 0i64;
  v67 = 0i64;
  v68 = 0i64;
  v69 = 0i64;
  v70 = 0i64;
  v71 = 0;
  v72 = 0;
  v56 = __PAIR__(gScreenHeight, gScreenWidth);
  LOBYTE(v59) = 0;
  v61 = 0x40000;
  PresentBufferTarget = Illusion::CreateTarget((Illusion::CreateTargetParams *)&v55);
  UFG::qString::qString(&v37, "LeftEye");
  v42 = 1i64;
  v38 = 0i64;
  v39 = 1;
  v40 = 1;
  v41 = -1;
  v43 = 0;
  v44 = 1;
  _mm_store_si128((__m128i *)&v45, (__m128i)0i64);
  _mm_store_si128((__m128i *)&v46, (__m128i)0i64);
  v47 = 0i64;
  v48 = 0i64;
  v49 = 0i64;
  v50 = 0i64;
  v51 = 0i64;
  v52 = 0i64;
  v53 = 0;
  v54 = 0;
  v38 = __PAIR__(gScreenHeight, gScreenWidth);
  LOBYTE(v41) = 0;
  v43 = 19;
  LeftEyeTarget = Illusion::CreateTarget((Illusion::CreateTargetParams *)&v37);
  UFG::qString::qString(&v24, "RightEye");
  *(_QWORD *)&v24.mStringHashUpper32 = 1i64;
  *(_QWORD *)&v24.mMagic = 0i64;
  v24.mData = (char *)4294967297i64;
  v24.mStringHash32 = -1;
  v25 = 0;
  v26 = 1;
  _mm_store_si128((__m128i *)&v27, (__m128i)0i64);
  _mm_store_si128((__m128i *)&v28, (__m128i)0i64);
  v29 = 0i64;
  v30 = 0i64;
  v31 = 0i64;
  v32 = 0i64;
  v33 = 0i64;
  v34 = 0i64;
  v35 = 0;
  v36 = 0;
  v24.mMagic = gScreenWidth;
  v24.mLength = gScreenHeight;
  LOBYTE(v24.mStringHash32) = 0;
  v25 = 19;
  RightEyeTarget = Illusion::CreateTarget((Illusion::CreateTargetParams *)&v24);
  Render::InitVertexDeclarations(v18);
  Render::Skinning::Init(&Render::Skinning::gSkinning);
  UFG::qString::~qString(&v24);
  UFG::qString::~qString(&v37);
  UFG::qString::~qString(&v55);
  UFG::qString::~qString(&v73);
  UFG::qVRAMemoryHandle::~qVRAMemoryHandle(&handle);
}

// File Line: 2145
// RVA: 0x69F930
Illusion::OcclusionPlat *__fastcall Render::GetOcclusionSystem()
{
  return &Illusion::gOcclusionPlat;
}

// File Line: 2151
// RVA: 0x69F810
Illusion::Target *__fastcall Render::GetBackBufferTarget()
{
  return BackBufferTarget;
}

// File Line: 2157
// RVA: 0x69F940
Illusion::Target *__fastcall Render::GetPresentBufferTarget()
{
  return PresentBufferTarget;
}

// File Line: 2163
// RVA: 0x69F7F0
Illusion::Target *__fastcall Render::Get3DTarget(Render::eStereoRenderEye eye)
{
  if ( eye == STEREO_EYE_LEFT )
    return LeftEyeTarget;
  if ( eye == 1 )
    return RightEyeTarget;
  return 0i64;
}

// File Line: 2178
// RVA: 0x6A2240
void __fastcall Render::SetVSyncEnable(Render::VSyncMode newVal)
{
  gEnableVsync = newVal;
}

// File Line: 2200
// RVA: 0x6A23C0
void Render::DisplayCalibration::UpdatePlat(void)
{
  unsigned int v0; // eax
  bool v1; // cl
  float v2; // xmm0_4
  float v3; // xmm10_4
  float v4; // xmm8_4
  unsigned int v5; // esi
  signed int v6; // ebx
  float *v7; // rcx
  float v8; // xmm0_4
  float *v9; // rdi
  float v10; // xmm0_4
  char v11; // [rsp+30h] [rbp-40B8h]
  unsigned int v12; // [rsp+3Ch] [rbp-40ACh]
  __int128 v13; // [rsp+1050h] [rbp-3098h]
  __int64 v14; // [rsp+1060h] [rbp-3088h]
  char v15; // [rsp+106Ch] [rbp-307Ch]
  __int64 v16; // [rsp+40F0h] [rbp+8h]
  UFG::qMutex *v17; // [rsp+40F8h] [rbp+10h]

  v0 = _S1_30;
  if ( _S1_30 & 1 )
  {
    v1 = sGammaControlEnabled;
  }
  else
  {
    v0 = _S1_30 | 1;
    _S1_30 |= 1u;
    v1 = gEnableGammaControl;
    sGammaControlEnabled = gEnableGammaControl;
  }
  if ( v0 & 2 )
  {
    v2 = sDeviceBrightness;
  }
  else
  {
    _S1_30 = v0 | 2;
    v2 = Render::DisplayCalibration::msBrightness;
    sDeviceBrightness = Render::DisplayCalibration::msBrightness;
  }
  v3 = Render::DisplayCalibration::msGamma;
  if ( Render::DisplayCalibration::msBrightness != v2
    || g_ForceDisplayCalibrationUpdate == 1
    || v1 != gEnableGammaControl )
  {
    sDeviceBrightness = Render::DisplayCalibration::msBrightness;
    sGammaControlEnabled = gEnableGammaControl;
    v4 = (float)(Render::DisplayCalibration::msBrightness - 1.0) * Render::DisplayCalibration::BlackLevel1.r;
    if ( sDXGISwapChain )
    {
      v17 = &sDXGIMutex;
      UFG::qMutex::Lock((LPCRITICAL_SECTION)&sDXGIMutex);
      if ( !((unsigned int (__fastcall *)(IDXGISwapChain *, __int64 *))sDXGISwapChain->vfptr[5].QueryInterface)(
              sDXGISwapChain,
              &v16)
        && !(*(unsigned int (__fastcall **)(__int64, char *))(*(_QWORD *)v16 + 104i64))(v16, &v11) )
      {
        v13 = _xmm;
        v14 = 0i64;
        v5 = v12;
        if ( v12 >= 2 )
        {
          v6 = 0;
          if ( gEnableGammaControl )
          {
            if ( v12 )
            {
              v9 = (float *)&v15;
              do
              {
                v10 = powf((float)v6 * (float)(1.0 / (float)(signed int)(v5 - 1)), v3) + v4;
                if ( v10 <= 0.0 )
                {
                  v10 = 0.0;
                }
                else if ( v10 >= 1.0 )
                {
                  v10 = *(float *)&FLOAT_1_0;
                }
                *(v9 - 1) = v10;
                *v9 = v10;
                v9[1] = v10;
                ++v6;
                v9 += 3;
              }
              while ( v6 < v5 );
            }
          }
          else if ( v12 )
          {
            v7 = (float *)&v15;
            do
            {
              v8 = (float)v6 * (float)(1.0 / (float)(signed int)(v5 - 1));
              if ( v8 <= 0.0 )
              {
                v8 = 0.0;
              }
              else if ( v8 >= 1.0 )
              {
                v8 = *(float *)&FLOAT_1_0;
              }
              *(v7 - 1) = v8;
              *v7 = v8;
              v7[1] = v8;
              ++v6;
              v7 += 3;
            }
            while ( v6 < v5 );
          }
          (*(void (__fastcall **)(__int64, __int128 *))(*(_QWORD *)v16 + 112i64))(v16, &v13);
          g_ForceDisplayCalibrationUpdate = 0;
        }
      }
      UFG::qMutex::Unlock((LPCRITICAL_SECTION)&sDXGIMutex);
    }
  }
}

// File Line: 2280
// RVA: 0x69E970
void __fastcall Render::BeginRenderToDevice(unsigned int *param)
{
  Render::DisplayCalibration::UpdatePlat();
  Render::RenderToDeviceStartTicks = UFG::qGetTicks();
}

// File Line: 2286
// RVA: 0x69F240
void __fastcall Render::EndRenderToDevice(unsigned int *param)
{
  unsigned __int64 v1; // rax

  v1 = UFG::qGetTicks();
  RenderDrawQueueCPUTime = UFG::qGetTickTime(Render::RenderToDeviceStartTicks, v1);
}

// File Line: 2291
// RVA: 0x69EA90
void __fastcall Render::ConvergeFunction(unsigned int *param)
{
  Illusion::Target *v1; // rax
  __int64 v2; // r10
  __int64 v3; // r9
  __int64 v4; // r11
  _QWORD *v5; // rax
  __int64 v6; // rax
  __int64 v7; // [rsp+50h] [rbp-28h]
  int v8; // [rsp+58h] [rbp-20h]
  int v9; // [rsp+5Ch] [rbp-1Ch]
  int v10; // [rsp+60h] [rbp-18h]
  int v11; // [rsp+64h] [rbp-14h]

  if ( (_DWORD)param )
  {
    if ( (_DWORD)param == 1 )
      v1 = RightEyeTarget;
    else
      v1 = 0i64;
  }
  else
  {
    v1 = LeftEyeTarget;
  }
  v2 = *(_QWORD *)(*(_QWORD *)&v1->mTargetTexture[0][1].mMipMapBias + 136i64);
  v3 = (unsigned int)(signed int)(float)((float)((float)gOutputParams.m3DConvergence * 0.1) * 32.0);
  v4 = *(_QWORD *)(*(_QWORD *)&BackBufferTarget->mTargetTexture[0][1].mMipMapBias + 136i64);
  v11 = 1;
  if ( (_DWORD)param )
  {
    v7 = 0i64;
    v9 = gScreenWidth - v3;
    v8 = 0;
    v10 = gScreenHeight;
    v6 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index);
  }
  else
  {
    v9 = gScreenWidth;
    v10 = gScreenHeight;
    v5 = NtCurrentTeb()->Reserved1[11];
    LODWORD(v7) = v3;
    v6 = v5[tls_index];
    *(__int64 *)((char *)&v7 + 4) = 0i64;
    v3 = 0i64;
  }
  (*(void (__fastcall **)(_QWORD, __int64, _QWORD, __int64, _DWORD, _DWORD, __int64, _DWORD, __int64 *))(**(_QWORD **)(v6 + 104) + 368i64))(
    *(_QWORD *)(v6 + 104),
    v2,
    0i64,
    v3,
    0,
    0,
    v4,
    0,
    &v7);
}

// File Line: 2329
// RVA: 0x6A08A0
void __fastcall Render::PerformFlip(unsigned int syncInterval)
{
  unsigned int v1; // edi
  _QWORD *v2; // rax
  __int64 v3; // rcx
  int v4; // ST28_4
  ID3D11DeviceContext **v5; // rbx
  __int64 v6; // ST28_8
  int v7; // ebx
  Render *v8; // rcx
  Render *v9; // rcx
  Render *v10; // rcx

  v1 = syncInterval;
  if ( g_Fullscreen )
  {
    v2 = NtCurrentTeb()->Reserved1[11];
    if ( g_enable3D )
    {
      v4 = 0;
      v5 = (ID3D11DeviceContext **)(v2[tls_index] + 104i64);
      sStereo3D->vfptr->CopyToEye(
        sStereo3D,
        0i64,
        *v5,
        (ID3D11Resource *)gPresentBuffer,
        *(ID3D11Resource **)(*(_QWORD *)&LeftEyeTarget->mTargetTexture[0][1].mMipMapBias + 136i64),
        v4);
      LODWORD(v6) = 0;
      sStereo3D->vfptr->CopyToEye(
        sStereo3D,
        STEREO_EYE_RIGHT,
        *v5,
        (ID3D11Resource *)gPresentBuffer,
        *(ID3D11Resource **)(*(_QWORD *)&RightEyeTarget->mTargetTexture[0][1].mMipMapBias + 136i64),
        v6);
    }
    else
    {
      v3 = *(_QWORD *)(v2[tls_index] + 104i64);
      (*(void (__fastcall **)(__int64, ID3D11Texture2D *, _QWORD))(*(_QWORD *)v3 + 376i64))(
        v3,
        gPresentBuffer,
        *(_QWORD *)(*(_QWORD *)&BackBufferTarget->mTargetTexture[0][1].mMipMapBias + 136i64));
    }
  }
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&sDXGIMutex);
  v7 = ((__int64 (__fastcall *)(IDXGISwapChain *, _QWORD, _QWORD))sDXGISwapChain->vfptr[2].Release)(
         sDXGISwapChain,
         v1,
         0i64);
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&sDXGIMutex);
  if ( !((v7 + 0x7785FFFB) & 0xFFFFFFFD) )
  {
    UFG::qMutex::Lock((LPCRITICAL_SECTION)&sDXGIMutex);
    Render::ReleaseSwapChain(v8);
    Render::ReleaseD3D(v9);
    Render::InitD3D(v10);
    Render::InitSwapChain(0i64);
    UFG::qMutex::Unlock((LPCRITICAL_SECTION)&sDXGIMutex);
  }
  Illusion::Engine::RenderThreadProcessDeleteQueue(&Illusion::gEngine);
}

// File Line: 2392
// RVA: 0x6A1D20
void __fastcall Render::RenderThreadWindowsMsgProc(bool *quitMsgReceived)
{
  bool *v1; // rbx
  tagMSG Msg; // [rsp+30h] [rbp-38h]

  v1 = quitMsgReceived;
  if ( PeekMessageA(&Msg, 0i64, 0, 0, 1u) )
  {
    while ( Msg.message != 18 )
    {
      TranslateMessage(&Msg);
      DispatchMessageA(&Msg);
      if ( !PeekMessageA(&Msg, 0i64, 0, 0, 1u) )
        goto LABEL_4;
    }
    PostQuitMessage(Msg.wParam);
    if ( v1 )
      *v1 = 1;
  }
  else
  {
LABEL_4:
    if ( v1 )
      *v1 = 0;
  }
}

// File Line: 2418
// RVA: 0x6A1510
void __fastcall Render::RenderThreadSwapChainEventTriggers(bool *resizeEvent)
{
  bool *v1; // rbx
  Render::RenderCallbacks *v2; // rax
  int v3; // esi
  int v4; // edi
  float v5; // xmm2_4
  bool v6; // al
  int v7; // eax
  char v8; // cl
  Render *v9; // rcx
  Render::RenderCallbacks *v10; // rax
  Render::RenderCallbacks *v11; // rax
  Render::RenderCallbacks *v12; // rax
  Render::RenderCallbacks *v13; // rax
  char v14; // al
  bool v15; // cl
  char v16; // al
  char v17; // al
  IDXGISwapChain *v18; // rcx
  bool v19; // r8
  _BOOL8 v20; // rdx
  IDXGIOutput *v21; // r8
  tagRECT Rect; // [rsp+30h] [rbp-B8h]
  UFG::qString v23; // [rsp+40h] [rbp-A8h]
  __int64 v24; // [rsp+68h] [rbp-80h]
  int v25; // [rsp+70h] [rbp-78h]
  int v26; // [rsp+74h] [rbp-74h]
  __int128 v27; // [rsp+78h] [rbp-70h]
  __int128 v28; // [rsp+88h] [rbp-60h]
  __int64 v29; // [rsp+98h] [rbp-50h]
  __int64 v30; // [rsp+A0h] [rbp-48h]
  __int64 v31; // [rsp+A8h] [rbp-40h]
  __int64 v32; // [rsp+B0h] [rbp-38h]
  __int64 v33; // [rsp+B8h] [rbp-30h]
  __int64 v34; // [rsp+C0h] [rbp-28h]
  int v35; // [rsp+C8h] [rbp-20h]
  char v36; // [rsp+CCh] [rbp-1Ch]
  UFG::qString v37; // [rsp+D8h] [rbp-10h]
  __int64 v38; // [rsp+100h] [rbp+18h]
  int v39; // [rsp+108h] [rbp+20h]
  int v40; // [rsp+10Ch] [rbp+24h]
  int v41; // [rsp+110h] [rbp+28h]
  __int64 v42; // [rsp+114h] [rbp+2Ch]
  int v43; // [rsp+11Ch] [rbp+34h]
  int v44; // [rsp+120h] [rbp+38h]
  __int128 v45; // [rsp+128h] [rbp+40h]
  __int128 v46; // [rsp+138h] [rbp+50h]
  __int64 v47; // [rsp+148h] [rbp+60h]
  __int64 v48; // [rsp+150h] [rbp+68h]
  __int64 v49; // [rsp+158h] [rbp+70h]
  __int64 v50; // [rsp+160h] [rbp+78h]
  __int64 v51; // [rsp+168h] [rbp+80h]
  __int64 v52; // [rsp+170h] [rbp+88h]
  int v53; // [rsp+178h] [rbp+90h]
  char v54; // [rsp+17Ch] [rbp+94h]
  UFG::qString v55; // [rsp+188h] [rbp+A0h]
  __int64 v56; // [rsp+1B0h] [rbp+C8h]
  int v57; // [rsp+1B8h] [rbp+D0h]
  int v58; // [rsp+1BCh] [rbp+D4h]
  int v59; // [rsp+1C0h] [rbp+D8h]
  __int64 v60; // [rsp+1C4h] [rbp+DCh]
  int v61; // [rsp+1CCh] [rbp+E4h]
  int v62; // [rsp+1D0h] [rbp+E8h]
  __int128 v63; // [rsp+1D8h] [rbp+F0h]
  __int128 v64; // [rsp+1E8h] [rbp+100h]
  __int64 v65; // [rsp+1F8h] [rbp+110h]
  __int64 v66; // [rsp+200h] [rbp+118h]
  __int64 v67; // [rsp+208h] [rbp+120h]
  __int64 v68; // [rsp+210h] [rbp+128h]
  __int64 v69; // [rsp+218h] [rbp+130h]
  __int64 v70; // [rsp+220h] [rbp+138h]
  int v71; // [rsp+228h] [rbp+140h]
  char v72; // [rsp+22Ch] [rbp+144h]
  UFG::qString v73; // [rsp+238h] [rbp+150h]
  __int64 v74; // [rsp+260h] [rbp+178h]
  int v75; // [rsp+268h] [rbp+180h]
  int v76; // [rsp+26Ch] [rbp+184h]
  int v77; // [rsp+270h] [rbp+188h]
  __int64 v78; // [rsp+274h] [rbp+18Ch]
  int v79; // [rsp+27Ch] [rbp+194h]
  int v80; // [rsp+280h] [rbp+198h]
  __int128 v81; // [rsp+288h] [rbp+1A0h]
  __int128 v82; // [rsp+298h] [rbp+1B0h]
  __int64 v83; // [rsp+2A8h] [rbp+1C0h]
  __int64 v84; // [rsp+2B0h] [rbp+1C8h]
  __int64 v85; // [rsp+2B8h] [rbp+1D0h]
  __int64 v86; // [rsp+2C0h] [rbp+1D8h]
  __int64 v87; // [rsp+2C8h] [rbp+1E0h]
  __int64 v88; // [rsp+2D0h] [rbp+1E8h]
  int v89; // [rsp+2D8h] [rbp+1F0h]
  char v90; // [rsp+2DCh] [rbp+1F4h]
  __int64 v91; // [rsp+2E8h] [rbp+200h]
  UFG::qString result; // [rsp+2F0h] [rbp+208h]
  char v93; // [rsp+318h] [rbp+230h]
  int v94; // [rsp+350h] [rbp+268h]

  v91 = -2i64;
  v1 = resizeEvent;
  if ( resizeEvent )
    *resizeEvent = 0;
  if ( sbEventResizeBuffers != 1 )
  {
LABEL_9:
    if ( !sbEventResizeSwapChain )
      goto LABEL_33;
    goto LABEL_10;
  }
  if ( !sbEventResizeSwapChain )
  {
    if ( Render::GetRenderCallbacks()->mResizeRenderBuffersFunc )
    {
      v2 = Render::GetRenderCallbacks();
      v2->mResizeRenderBuffersFunc();
    }
    sbEventResizeBuffers = 0;
    if ( v1 )
      *v1 = 1;
    goto LABEL_9;
  }
LABEL_10:
  Illusion::IEnginePlat::WaitUntilGPUDone((Illusion::IEnginePlat *)&Illusion::gEngine);
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&sDXGIMutex);
  if ( !sDXGIMode || sbEventManualWindowSizing )
  {
    GetClientRect(ghWnd, &Rect);
    v3 = Rect.right - Rect.left;
    v4 = Rect.bottom - Rect.top;
    v5 = (float)(Rect.right - Rect.left);
    if ( (float)(v5 / (float)(Rect.bottom - Rect.top)) > 7.1111112 )
      v4 = (signed int)(float)(v5 * 0.140625);
  }
  else
  {
    v3 = sDXGIMode->Width;
    v4 = sDXGIMode->Height;
  }
  Render::SetWindow(v3, v4);
  if ( sPresentRenderTargetView )
  {
    ((void (*)(void))sPresentRenderTargetView->vfptr->Release)();
    sPresentRenderTargetView = 0i64;
  }
  if ( gPresentBuffer )
  {
    ((void (*)(void))gPresentBuffer->vfptr->Release)();
    gPresentBuffer = 0i64;
  }
  Illusion::DeleteTarget(BackBufferTarget, 1);
  Illusion::DeleteTarget(PresentBufferTarget, 1);
  Illusion::DeleteTarget(LeftEyeTarget, 1);
  Illusion::DeleteTarget(RightEyeTarget, 1);
  gScreenWidth = v3;
  gScreenHeight = v4;
  if ( g_signalNewSwapChain )
  {
    Render::InitSwapChain(g_Fullscreen);
    g_signalNewSwapChain = 0;
  }
  else
  {
    ((void (__fastcall *)(IDXGISwapChain *, signed __int64, _QWORD, _QWORD, signed int, signed int))sDXGISwapChain->vfptr[4].AddRef)(
      sDXGISwapChain,
      2i64,
      (unsigned int)v3,
      (unsigned int)v4,
      28,
      2);
    ((void (__fastcall *)(IDXGISwapChain *, _QWORD, GUID *, ID3D11Texture2D **))sDXGISwapChain->vfptr[3].QueryInterface)(
      sDXGISwapChain,
      0i64,
      &GUID_6f15aaf2_d208_4e89_9ab4_489535d34f9c,
      &gPresentBuffer);
    ((void (__fastcall *)(ID3D11Device *, ID3D11Texture2D *, _QWORD, ID3D11RenderTargetView **))sDevice->vfptr->Draw)(
      sDevice,
      gPresentBuffer,
      0i64,
      &sPresentRenderTargetView);
  }
  ((void (__fastcall *)(IDXGISwapChain *, char *))sDXGISwapChain->vfptr[4].QueryInterface)(sDXGISwapChain, &v93);
  v6 = g_Fullscreen;
  if ( g_Fullscreen == g_PrevFullscreen )
  {
    v6 = v94 == 0;
    g_Fullscreen = v94 == 0;
    gOutputParams.mEnableFullscreen = v94 == 0;
  }
  g_renderMouse = 0;
  if ( v6 )
  {
    UFG::qGetRegistryValue(&result, "HKEY_CURRENT_USER\\Control Panel\\Mouse\\MouseTrails", "0", 0);
    v7 = UFG::qStringCompareInsensitive(result.mData, "0", -1);
    v8 = g_renderMouse;
    if ( v7 )
      v8 = 1;
    g_renderMouse = v8;
    UFG::qString::~qString(&result);
  }
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&sDXGIMutex);
  gDisplayAspectRatio = (float)v3 / (float)v4;
  Render::UpdateUIViewportScalesBasedOnAspectRatio(v9);
  UFG::qString::qString(&v23, "BackBuffer");
  *(_QWORD *)((char *)&v27 + 4) = 1i64;
  v24 = 0i64;
  v26 = 1;
  LODWORD(v27) = -1;
  v25 = 1;
  _mm_store_si128((__m128i *)&v27, (__m128i)0i64);
  _mm_store_si128((__m128i *)&v28, (__m128i)0i64);
  v29 = 0i64;
  v30 = 0i64;
  v31 = 0i64;
  v32 = 0i64;
  v33 = 0i64;
  v34 = 0i64;
  v35 = 0;
  v36 = 0;
  v24 = (unsigned int)gScreenWidth;
  LOBYTE(v27) = 0;
  HIDWORD(v24) = 19;
  BackBufferTarget = Illusion::CreateTarget((Illusion::CreateTargetParams *)&v23);
  UFG::qString::qString(&v55, "PresentBuffer");
  v60 = 1i64;
  v56 = 0i64;
  v57 = 1;
  v58 = 1;
  v59 = -1;
  v61 = 0;
  v62 = 1;
  _mm_store_si128((__m128i *)&v63, (__m128i)0i64);
  _mm_store_si128((__m128i *)&v64, (__m128i)0i64);
  v65 = 0i64;
  v66 = 0i64;
  v67 = 0i64;
  v68 = 0i64;
  v69 = 0i64;
  v70 = 0i64;
  v71 = 0;
  v72 = 0;
  v56 = __PAIR__(gScreenHeight, gScreenWidth);
  LOBYTE(v59) = 0;
  v61 = 0x40000;
  PresentBufferTarget = Illusion::CreateTarget((Illusion::CreateTargetParams *)&v55);
  UFG::qString::qString(&v73, "LeftEye");
  v78 = 1i64;
  v74 = 0i64;
  v75 = 1;
  v76 = 1;
  v77 = -1;
  v79 = 0;
  v80 = 1;
  _mm_store_si128((__m128i *)&v81, (__m128i)0i64);
  _mm_store_si128((__m128i *)&v82, (__m128i)0i64);
  v83 = 0i64;
  v84 = 0i64;
  v85 = 0i64;
  v86 = 0i64;
  v87 = 0i64;
  v88 = 0i64;
  v89 = 0;
  v90 = 0;
  v74 = __PAIR__(gScreenHeight, gScreenWidth);
  LOBYTE(v77) = 0;
  v79 = 19;
  LeftEyeTarget = Illusion::CreateTarget((Illusion::CreateTargetParams *)&v73);
  UFG::qString::qString(&v37, "RightEye");
  v42 = 1i64;
  v38 = 0i64;
  v39 = 1;
  v40 = 1;
  v41 = -1;
  v43 = 0;
  v44 = 1;
  _mm_store_si128((__m128i *)&v45, (__m128i)0i64);
  _mm_store_si128((__m128i *)&v46, (__m128i)0i64);
  v47 = 0i64;
  v48 = 0i64;
  v49 = 0i64;
  v50 = 0i64;
  v51 = 0i64;
  v52 = 0i64;
  v53 = 0;
  v54 = 0;
  v38 = __PAIR__(gScreenHeight, gScreenWidth);
  LOBYTE(v41) = 0;
  v43 = 19;
  RightEyeTarget = Illusion::CreateTarget((Illusion::CreateTargetParams *)&v37);
  if ( Render::GetRenderCallbacks()->mResizeRenderBuffersFunc )
  {
    v10 = Render::GetRenderCallbacks();
    v10->mResizeRenderBuffersFunc();
  }
  sbEventResizeBuffers = 0;
  sbEventResizeSwapChain = 0;
  sbEventManualWindowSizing = 0;
  if ( v1 )
    *v1 = 1;
  UFG::qString::~qString(&v37);
  UFG::qString::~qString(&v73);
  UFG::qString::~qString(&v55);
  UFG::qString::~qString(&v23);
LABEL_33:
  if ( sbEventResizeShadows )
  {
    if ( Render::GetRenderCallbacks()->mResizeShadowsFunc )
    {
      v11 = Render::GetRenderCallbacks();
      v11->mResizeShadowsFunc();
    }
    sbEventResizeShadows = 0;
    if ( v1 )
      *v1 = 1;
  }
  if ( sbEventChangeTexturePack )
  {
    if ( Render::GetRenderCallbacks()->mChangeTexturePackFunc )
    {
      v12 = Render::GetRenderCallbacks();
      v12->mChangeTexturePackFunc();
    }
    sbEventChangeTexturePack = 0;
  }
  if ( sbEventChangeLODSetting )
  {
    if ( Render::GetRenderCallbacks()->mChangeLODSettingFunc )
    {
      v13 = Render::GetRenderCallbacks();
      v13->mChangeLODSettingFunc();
    }
    sbEventChangeLODSetting = 0;
  }
  v14 = ((__int64 (*)(void))sStereo3D->vfptr->Stereo3DAvailable)();
  v15 = g_signalEnable3D;
  if ( !v14 )
    v15 = 0;
  g_signalEnable3D = v15;
  if ( g_Fullscreen != g_PrevFullscreen || sDXGIMode != sDXGIPrevMode || v15 != g_enable3D )
  {
    if ( g_Fullscreen )
    {
      v16 = g_ForceDisplayCalibrationUpdate;
      if ( g_Fullscreen != g_PrevFullscreen )
        v16 = 1;
      g_ForceDisplayCalibrationUpdate = v16;
    }
    v17 = g_signalNewSwapChain;
    if ( v15 != g_enable3D )
      v17 = 1;
    g_signalNewSwapChain = v17;
    if ( v15 && g_Fullscreen )
      ((void (*)(void))sStereo3D->vfptr->Enable)();
    else
      ((void (*)(void))sStereo3D->vfptr->Disable)();
    UFG::qMutex::Lock((LPCRITICAL_SECTION)&sDXGIMutex);
    v18 = sDXGISwapChain;
    if ( sDXGISwapChain )
    {
      v19 = g_Fullscreen;
      if ( g_Fullscreen )
      {
        if ( sDXGIMode )
        {
          ((void (*)(void))sDXGISwapChain->vfptr[4].Release)();
          v19 = g_Fullscreen;
          v18 = sDXGISwapChain;
        }
        v20 = v19;
        v21 = sDXGIOutput;
      }
      else
      {
        v21 = 0i64;
        v20 = 0i64;
      }
      ((void (__fastcall *)(IDXGISwapChain *, _BOOL8, IDXGIOutput *))v18->vfptr[3].AddRef)(v18, v20, v21);
    }
    g_enable3D = g_signalEnable3D;
    g_PrevFullscreen = g_Fullscreen;
    sDXGIPrevMode = sDXGIMode;
    UFG::qMutex::Unlock((LPCRITICAL_SECTION)&sDXGIMutex);
  }
}

// File Line: 2663
// RVA: 0x1587830
__int64 Render::_dynamic_initializer_for__gFrameTimes__()
{
  __int64 result; // rax

  result = 0i64;
  Render::gFrameTimes[0].mGPUStartTime = 0i64;
  qword_142439C08 = 0i64;
  qword_142439C10 = 0i64;
  qword_142439C18 = 0i64;
  qword_142439C20 = 0i64;
  qword_142439C28 = 0i64;
  qword_142439C30 = 0i64;
  qword_142439C38 = 0i64;
  qword_142439C40 = 0i64;
  qword_142439C48 = 0i64;
  qword_142439C50 = 0i64;
  qword_142439C58 = 0i64;
  return result;
}

// File Line: 2700
// RVA: 0x6A14F0
void __fastcall Render::RenderThreadDelayedTextureProcess(Render *this)
{
  Illusion::TextureD3DResourceInventory::ProcessSyncCopies(&Illusion::gTextureD3DResourceInventory);
}

// File Line: 2705
// RVA: 0x6A14D0
void __fastcall Render::RenderThreadDelayedD3DObjectDeletion(Render *this)
{
  Illusion::TextureD3DResourceInventory::ProcessQueuedUnLoads(&Illusion::gTextureD3DResourceInventory);
  Illusion::BufferD3DResourceInventory::ProcessQueuedUnLoads(&Illusion::gBufferD3DResourceInventory);
}

// File Line: 2711
// RVA: 0x6A1500
void __fastcall Render::RenderThreadGetOcclusionQueryResults(Render *this)
{
  Illusion::OcclusionPlat::GetQueryResultsForFrame(&Illusion::gOcclusionPlat);
}

// File Line: 2716
// RVA: 0x6A0FF0
__int64 __usercall Render::RenderFrame@<rax>(float ftime@<xmm0>, Render *a2@<rcx>)
{
  __int32 v2; // esi
  int v3; // ebx
  char *v4; // rax
  Render *v5; // rcx
  Render *v6; // rcx
  char *v7; // rax
  char *v8; // r8
  __int64 v9; // rcx
  Illusion *v10; // rcx
  Illusion *v11; // rcx
  Render::RenderCallbacks *v12; // rax
  unsigned __int8 v13; // bp
  __int64 v14; // rdi
  __int64 v15; // rbx
  unsigned __int64 v16; // rax
  Render *v17; // rcx
  Illusion *v18; // rcx
  UFG::qList<Illusion::RenderPhase,Illusion::RenderPhase,1,0> *v19; // rax
  unsigned __int32 v20; // ebx
  unsigned __int64 v21; // rax
  float i; // xmm0_4
  unsigned __int64 v23; // rax
  char v25; // [rsp+98h] [rbp+10h]
  char data0; // [rsp+A0h] [rbp+18h]
  char *v27; // [rsp+A8h] [rbp+20h]

  Render::CommitPendingCommandBuilders(a2);
  UFG::qTaskManager::Sync(&UFG::gTaskManager);
  v2 = 0;
  v3 = Render::g_DefragMovesUsedCount;
  if ( Render::g_DefragMovesUsedCount > 0 && Render::g_DefragMovesFinishedCount == Render::g_DefragMovesUsedCount )
  {
    if ( Render::g_DoDefragPrints == 1 )
      UFG::qPrintf(
        "Defrag starting move callbacks on %d moves at 0x%08x, frame[%d]\n",
        (unsigned int)Render::g_DefragMovesUsedCount,
        Render::g_DefragMoves,
        Illusion::gEngine.mFrameCount);
    UFG::qVRAMemoryPools::MovesCompleted(Render::g_DefragMoves, v3, 0i64);
    Render::g_DefragMovesUsedCount = 0;
    Render::g_DefragMovesFinishedCount = 0;
  }
  Illusion::Engine::BeginFrame(&Illusion::gEngine);
  v4 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x10u, 8u);
  v27 = v4;
  if ( v4 )
  {
    *(_QWORD *)v4 = 0i64;
    *((_QWORD *)v4 + 1) = Render::BeginRenderToDevice;
  }
  else
  {
    v4 = 0i64;
  }
  Illusion::RenderQueueSystem::FlushRenderCommand(17, 0, v4);
  Render::gRenderFrame = 0.0;
  Illusion::FrameWriteMemoryPlat::Lock(&Illusion::gFrameWriteMemoryPlat, Render::FrameMemoryBufferIndex);
  UFG::qLinearAllocator::Init(
    Illusion::gEngine.FrameWriteMemory,
    (char *)Illusion::gFrameWriteMemoryPlat.mLockData,
    Illusion::gFrameWriteMemoryPlat.mBufferSize,
    0i64,
    0i64);
  Illusion::FrameWriteMemoryPlat::Lock(&Illusion::gPrimitiveFrameWriteMemoryPlat, Render::FrameMemoryBufferIndex);
  UFG::qLinearAllocator::Init(
    Illusion::gEngine.PrimitiveFrameWriteMemory,
    (char *)Illusion::gPrimitiveFrameWriteMemoryPlat.mLockData,
    Illusion::gPrimitiveFrameWriteMemoryPlat.mBufferSize,
    0i64,
    0i64);
  if ( g_enable3D && g_Fullscreen )
  {
    g_interAxialDistance = (float)((float)gOutputParams.m3DDepth * 0.1) * 0.1;
    Render::RenderWorldEye(ftime, 0);
    Render::RenderWorldEye(ftime, STEREO_EYE_RIGHT);
  }
  else
  {
    gCurrentEye = 0;
    Render::RenderWorld(ftime);
  }
  Illusion::FrameWriteMemoryPlat::Unlock(&Illusion::gFrameWriteMemoryPlat);
  Illusion::FrameWriteMemoryPlat::Unlock(&Illusion::gPrimitiveFrameWriteMemoryPlat);
  Render::ScheduleNewDefragMoves(v5);
  Render::DoDefragMoves(v6);
  v7 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x10u, 8u);
  v8 = v7;
  v27 = v7;
  if ( v7 )
  {
    *(_QWORD *)v7 = BackBufferTarget;
    *((_QWORD *)v7 + 1) = Render::EndRenderToDevice;
  }
  else
  {
    v8 = 0i64;
  }
  Illusion::RenderQueueSystem::FlushRenderCommand(17, 0, v8);
  Illusion::Engine::EndFrame(&Illusion::gEngine);
  v9 = *(_QWORD *)(*((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 104i64);
  (*(void (__fastcall **)(__int64, _QWORD, ID3D11CommandList **))(*(_QWORD *)v9 + 912i64))(
    v9,
    0i64,
    &sMainThreadCommandList);
  if ( sMainThreadCommandList )
    Illusion::AddRenderThreadCommand(RTCMD_EXECUTE_DEFERRED_COMMANDS, &sMainThreadCommandList, 0i64, 0i64);
  Illusion::WaitForRenderThread(v10);
  Illusion::AddRenderThreadCommand(RTCMD_CALLBACK, Render::RenderThreadGetOcclusionQueryResults, 0i64, 0i64);
  Illusion::AddRenderThreadCommand(RTCMD_CALLBACK, Render::RenderThreadDelayedTextureProcess, 0i64, 0i64);
  Illusion::AddRenderThreadCommand(RTCMD_CALLBACK, Render::RenderThreadDelayedD3DObjectDeletion, 0i64, 0i64);
  Illusion::AddRenderThreadCommand(RTCMD_CALLBACK, Render::RenderThreadWindowsMsgProc, &data0, 0i64);
  Illusion::AddRenderThreadCommand(RTCMD_CALLBACK, Render::RenderThreadSwapChainEventTriggers, &v25, 0i64);
  if ( Render::GetRenderCallbacks()->mRenderThreadSyncPointFunc )
  {
    v12 = Render::GetRenderCallbacks();
    Illusion::AddRenderThreadCommand(RTCMD_CALLBACK, v12->mRenderThreadSyncPointFunc, &v25, 0i64);
  }
  Illusion::WaitForRenderThread(v11);
  v13 = 1;
  if ( data0 )
    v13 = 0;
  v14 = (LOBYTE(Illusion::gEngine.mFrameCount) + 1) & 3;
  v15 = Illusion::gEngine.mFrameCount & 3;
  v16 = UFG::qGetTicks();
  Render::gFrameTimes[v15].mCPUTimeMs = UFG::qGetTickTime(Render::gFrameTimes[v15].mCPUStartTime, v16) * 1000.0;
  Render::gFrameTimes[v14].mCPUStartTime = UFG::qGetTicks();
  UFG::qVRAMemoryPools::ServiceDeletes();
  Render::SwapFrameMemoryBuffers(v17);
  gGPUIndex = (gGPUIndex + 1) % gNumGPUs;
  Illusion::WaitForRenderThread(v18);
  if ( v25 || data0 )
  {
    Illusion::RenderQueuePlat::ClearFlushedRenderPhases();
  }
  else
  {
    v19 = Illusion::RenderQueuePlat::GetRenderPhasesForNextFrame();
    Illusion::AddRenderThreadCommand(RTCMD_SUBMIT, v19, 0i64, 0i64);
    v20 = gOutputParams.mFPSLimiter % 5;
    LOBYTE(v2) = gOutputParams.mEnableVSync != 0;
    if ( v2 > gOutputParams.mFPSLimiter % 5 )
      v20 = v2;
    if ( gGovernMaxFrameRate && !v20 )
    {
      if ( !(_S2_11 & 1) )
      {
        _S2_11 |= 1u;
        prevTick = UFG::qGetTicks();
      }
      v21 = UFG::qGetTicks();
      for ( i = UFG::qGetTickTime(prevTick, v21); i < 0.0083333338; i = UFG::qGetTickTime(prevTick, v23) )
      {
        UFG::qSleep(i < 0.006333333767950535);
        v23 = UFG::qGetTicks();
      }
      prevTick = UFG::qGetTicks();
    }
    Illusion::AddRenderThreadCommand(RTCMD_CALLBACK, Render::PerformFlip, (void *)v20, 0i64);
  }
  Illusion::AddRenderThreadCommand(RTCMD_END_OF_FRAME, 0i64, 0i64, 0i64);
  return v13;
}

// File Line: 3118
// RVA: 0x6A2300
void __fastcall Render::StreamingLoopProcessQueuedOperations(bool bBlocking, bool bProcessUnloads)
{
  bool v2; // di
  bool v3; // bl
  void *v4; // rbx
  Illusion *v5; // rcx

  v2 = bProcessUnloads;
  v3 = bBlocking;
  Illusion::BufferD3DResourceInventory::ProcessQueuedLoads(&Illusion::gBufferD3DResourceInventory, bBlocking);
  Illusion::TextureD3DResourceInventory::ProcessQueuedLoads(&Illusion::gTextureD3DResourceInventory, v3);
  if ( v2 )
  {
    v4 = UFG::qGetCurrentThreadID();
    if ( v4 == (void *)UFG::qGetMainThreadID() )
    {
      Illusion::Engine::WaitUntilSafeToDelete(&Illusion::gEngine);
      Illusion::AddRenderThreadCommand(RTCMD_CALLBACK, Render::RenderThreadDelayedTextureProcess, 0i64, 0i64);
      Illusion::AddRenderThreadCommand(RTCMD_CALLBACK, Render::RenderThreadDelayedD3DObjectDeletion, 0i64, 0i64);
      Illusion::WaitForRenderThread(v5);
    }
    else
    {
      Illusion::TextureD3DResourceInventory::ProcessSyncCopies(&Illusion::gTextureD3DResourceInventory);
      Illusion::TextureD3DResourceInventory::ProcessQueuedUnLoads(&Illusion::gTextureD3DResourceInventory);
      Illusion::BufferD3DResourceInventory::ProcessQueuedUnLoads(&Illusion::gBufferD3DResourceInventory);
    }
  }
}

// File Line: 3146
// RVA: 0x69F7E0
void __fastcall Render::ForceLoadTextureResources(unsigned int uid)
{
  Illusion::TextureD3DResourceInventory::ForceLoad(&Illusion::gTextureD3DResourceInventory, uid);
}

// File Line: 3151
// RVA: 0x6A2070
void __fastcall Render::SetHighPriorityLoad(unsigned int uid)
{
  Illusion::TextureD3DResourceInventory::SetHighPriority(&Illusion::gTextureD3DResourceInventory, uid);
}

// File Line: 3157
// RVA: 0x69E780
void __fastcall Render::AcquireDeferredContextForThread(Render *this)
{
  *(_QWORD *)(*((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 104i64) = Illusion::EnginePlat::AllocDeferredContextBlocking(&Illusion::gEnginePlat);
}

// File Line: 3164
// RVA: 0x6A0F30
void __fastcall Render::ReleaseDeferredContextForThread(Render *this)
{
  Illusion::EnginePlat::ReleaseDeferredContext(
    &Illusion::gEnginePlat,
    *(ID3D11DeviceContext **)(*((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 104i64));
}

// File Line: 3171
// RVA: 0x69F670
void __fastcall Render::ExecuteDeferredContextForThread(Render *this)
{
  __int64 v1; // rax
  Illusion *v2; // rcx
  __int64 param; // [rsp+30h] [rbp+8h]

  v1 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index);
  param = 0i64;
  (*(void (__fastcall **)(_QWORD, _QWORD, __int64 *))(**(_QWORD **)(v1 + 104) + 912i64))(
    *(_QWORD *)(v1 + 104),
    0i64,
    &param);
  Illusion::AddRenderThreadCommand(RTCMD_EXECUTE_DEFERRED_COMMANDS, &param, 0i64, 0i64);
  Illusion::WaitForRenderThread(v2);
}

// File Line: 3182
// RVA: 0x69F870
__int64 __fastcall Render::GetCurrentGPUIndex()
{
  return (unsigned int)gGPUIndex;
}

// File Line: 3187
// RVA: 0x69F920
__int64 __fastcall Render::GetGPUCount()
{
  return (unsigned int)gNumGPUs;
}

// File Line: 3197
// RVA: 0x1587900
__int64 Render::_dynamic_initializer_for__g_DefragMoves__()
{
  `eh vector constructor iterator'(
    Render::g_DefragMoves,
    0x40ui64,
    25,
    (void (__fastcall *)(void *))UFG::qVRAMemoryMoveOrder::qVRAMemoryMoveOrder);
  return atexit(Render::_dynamic_atexit_destructor_for__g_DefragMoves__);
}

// File Line: 3205
// RVA: 0x6A2210
void __fastcall Render::SetVRAMDefragPerFrameLimits(bool inLoadScreen)
{
  if ( inLoadScreen )
  {
    Render::g_DefragTotalMovesPerFrame = 25;
    Render::g_DefragTotalBytesPerFrame = 0x1900000;
  }
  else
  {
    Render::g_DefragTotalMovesPerFrame = 10;
    Render::g_DefragTotalBytesPerFrame = 0x500000;
  }
}

// File Line: 3242
// RVA: 0x6A1DB0
void __fastcall Render::ScheduleNewDefragMoves(Render *this)
{
  int v1; // eax
  int v2; // ebp
  char **v3; // rbx
  char *v4; // rsi
  char *v5; // rdi
  unsigned int v6; // eax
  __int64 v7; // [rsp+20h] [rbp-18h]
  __int64 v8; // [rsp+28h] [rbp-10h]

  if ( !Render::g_DefragMovesUsedCount && Render::g_EnableVRAMDefragmentation == 1 )
  {
    v1 = UFG::qVRAMemoryPools::GetDefragmentMoves(
           Render::g_DefragMoves,
           Render::g_DefragTotalMovesPerFrame,
           Render::g_DefragTotalBytesPerFrame);
    Render::g_DefragMovesUsedCount = v1;
    if ( Render::g_DoDefragPrints == 1 )
    {
      v2 = Render::g_DefragMovesFinishedCount;
      if ( Render::g_DefragMovesFinishedCount < v1 )
      {
        v3 = &Render::g_DefragMoves[(signed __int64)Render::g_DefragMovesFinishedCount].mTargetHandle.mData;
        do
        {
          v4 = v3[4];
          v5 = *v3;
          v6 = UFG::qVRAMemoryHandle::GetAllocatedSize(&Render::g_DefragMoves[(signed __int64)v2].mSourceHandle);
          LODWORD(v8) = Illusion::gEngine.mFrameCount;
          LODWORD(v7) = v6;
          UFG::qPrintf(
            " - Scheduling defrag from 0x%08x to 0x%08x of %8d(0x%08x) bytes, frame[%d]\n",
            v4,
            v5,
            v6,
            v7,
            v8);
          ++v2;
          v3 += 8;
        }
        while ( v2 < Render::g_DefragMovesUsedCount );
      }
    }
  }
}

// File Line: 3270
// RVA: 0x69F0A0
void __fastcall Render::DoDefragMoves(Render *this)
{
  int v1; // esi
  unsigned int v2; // edi
  char **v3; // r14
  unsigned int v4; // eax
  char *v5; // rbp
  char *v6; // r15
  unsigned int v7; // eax
  unsigned int v8; // er12
  unsigned int v9; // er13
  unsigned int v10; // ebx
  __int64 v11; // [rsp+20h] [rbp-38h]
  __int64 v12; // [rsp+28h] [rbp-30h]

  v1 = Render::g_DefragMovesFinishedCount;
  if ( Render::g_DefragMovesFinishedCount < Render::g_DefragMovesUsedCount )
  {
    v2 = 0;
    if ( Render::g_DefragMovesFinishedCount < Render::g_DefragMovesUsedCount )
    {
      v3 = &Render::g_DefragMoves[(signed __int64)Render::g_DefragMovesFinishedCount].mTargetHandle.mData;
      v4 = Render::g_DefragCurrentMoveProgress;
      do
      {
        if ( v2 >= Render::g_DefragTotalBytesPerFrame )
          break;
        v5 = &v3[4][v4];
        v6 = &(*v3)[v4];
        v7 = UFG::qVRAMemoryHandle::GetAllocatedSize(&Render::g_DefragMoves[(signed __int64)v1].mSourceHandle);
        v8 = v7 - Render::g_DefragCurrentMoveProgress;
        v9 = v7 - Render::g_DefragCurrentMoveProgress + v2;
        if ( v9 <= Render::g_DefragTotalBytesPerFrame )
        {
          if ( Render::g_DoDefragPrints == 1 )
          {
            LODWORD(v12) = Illusion::gEngine.mFrameCount;
            LODWORD(v11) = v7 - Render::g_DefragCurrentMoveProgress;
            UFG::qPrintf(
              " - Doing         defrag from 0x%08x to 0x%08x of %8d(0x%08x) bytes, frame[%d]\n",
              v5,
              v6,
              v8,
              v11,
              v12);
          }
          Render::FastMemMove(v6, v5, v8);
          v4 = 0;
          ++Render::g_DefragMovesFinishedCount;
          v2 = v9;
        }
        else
        {
          v10 = Render::g_DefragTotalBytesPerFrame - v2;
          if ( Render::g_DoDefragPrints == 1 )
          {
            LODWORD(v12) = Illusion::gEngine.mFrameCount;
            LODWORD(v11) = Render::g_DefragTotalBytesPerFrame - v2;
            UFG::qPrintf(
              " - Doing partial defrag from 0x%08x to 0x%08x of %8d(0x%08x) bytes, frame[%d]\n",
              v5,
              v6,
              v10,
              v11,
              v12);
          }
          Render::FastMemMove(v6, v5, v10);
          v2 += v10;
          v4 = v10 + Render::g_DefragCurrentMoveProgress;
        }
        ++v1;
        v3 += 8;
        Render::g_DefragCurrentMoveProgress = v4;
      }
      while ( v1 < Render::g_DefragMovesUsedCount );
    }
  }
}

// File Line: 3313
// RVA: 0x69F6D0
void __fastcall Render::FastMemMove(void *dest, const void *source, unsigned int countBytes)
{
  __int64 v3; // r8
  _BYTE *v4; // r10
  unsigned int v5; // er9
  char *v6; // r11
  char *v7; // rdx
  char *i; // rcx
  __int64 v9; // rax
  char *v10; // rcx
  char *v11; // rdx
  __int64 v12; // rax

  v3 = countBytes >> 3;
  v4 = dest;
  v5 = (unsigned int)v3 >> 4;
  if ( dest <= source || (v6 = (char *)source + 8 * v3, dest >= v6) )
  {
    if ( v5 )
    {
      v10 = (char *)dest + 16;
      v11 = (char *)((_BYTE *)source - v4);
      do
      {
        v12 = *(_QWORD *)&v11[(_QWORD)v10 - 16];
        v10 += 128;
        *((_QWORD *)v10 - 18) = v12;
        *((_QWORD *)v10 - 17) = *(_QWORD *)&v10[(_QWORD)v11 - 136];
        *((_QWORD *)v10 - 16) = *(_QWORD *)&v10[(_QWORD)v11 - 128];
        *((_QWORD *)v10 - 15) = *(_QWORD *)&v10[(_QWORD)v11 - 120];
        *((_QWORD *)v10 - 14) = *(_QWORD *)&v11[(_QWORD)v10 - 112];
        *((_QWORD *)v10 - 13) = *(_QWORD *)&v11[(_QWORD)v10 - 104];
        *((_QWORD *)v10 - 12) = *(_QWORD *)&v11[(_QWORD)v10 - 96];
        *((_QWORD *)v10 - 11) = *(_QWORD *)&v11[(_QWORD)v10 - 88];
        *((_QWORD *)v10 - 10) = *(_QWORD *)&v11[(_QWORD)v10 - 80];
        *((_QWORD *)v10 - 9) = *(_QWORD *)&v11[(_QWORD)v10 - 72];
        *((_QWORD *)v10 - 8) = *(_QWORD *)&v11[(_QWORD)v10 - 64];
        *((_QWORD *)v10 - 7) = *(_QWORD *)&v11[(_QWORD)v10 - 56];
        *((_QWORD *)v10 - 6) = *(_QWORD *)&v11[(_QWORD)v10 - 48];
        *((_QWORD *)v10 - 5) = *(_QWORD *)&v11[(_QWORD)v10 - 40];
        *((_QWORD *)v10 - 4) = *(_QWORD *)&v11[(_QWORD)v10 - 32];
        *((_QWORD *)v10 - 3) = *(_QWORD *)&v11[(_QWORD)v10 - 24];
        --v5;
      }
      while ( v5 );
    }
  }
  else
  {
    v7 = v6 - 8;
    for ( i = (char *)dest + 8 * v3 - 8; (_DWORD)v3; LODWORD(v3) = v3 - 1 )
    {
      v9 = *(_QWORD *)v7;
      i -= 8;
      v7 -= 8;
      *((_QWORD *)i + 1) = v9;
    }
  }
}

// File Line: 3390
// RVA: 0x69E990
void __fastcall CloseEngineCB(Render *a1)
{
  Render *v1; // rcx

  Render::ReleaseSwapChain(a1);
  Render::ReleaseD3D(v1);
}

// File Line: 3396
// RVA: 0x69E9B0
signed __int64 __fastcall CloseRenderEngine()
{
  Illusion *v0; // rcx

  Illusion::AddRenderThreadCommand(RTCMD_CALLBACK, CloseEngineCB, 0i64, 0i64);
  Illusion::WaitForRenderThread(v0);
  return 1i64;
}

