// File Line: 117
// RVA: 0x15878A0
__int64 UFG::_dynamic_initializer_for__gScreenMinimizedEvent__()
{
  UFG::ChannelObj::ChannelObj(
    &UFG::gScreenMinimizedEvent,
    "ScreenMinimizedEvent",
    "This is an event that gets generated when the screen is minimized.");
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__gScreenMinimizedEvent__);
}

// File Line: 118
// RVA: 0x15878D0
__int64 UFG::_dynamic_initializer_for__gScreenRestoredEvent__()
{
  UFG::ChannelObj::ChannelObj(
    &UFG::gScreenRestoredEvent,
    "ScreenRestoredEvent",
    "This is an event that gets generated when the screen is restored.");
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__gScreenRestoredEvent__);
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
  UFG::qMutex::qMutex(&sDXGIMutex, &customCaption);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__sDXGIMutex__);
}

// File Line: 187
// RVA: 0x1587990
__int64 dynamic_initializer_for__sAvailableDXGIAdapters__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__sAvailableDXGIAdapters__);
}

// File Line: 197
// RVA: 0x15879A0
__int64 dynamic_initializer_for__sAvailableDXGIOutputs__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__sAvailableDXGIOutputs__);
}

// File Line: 213
// RVA: 0x15879E0
__int64 dynamic_initializer_for__sPendingCommandBuilders__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__sPendingCommandBuilders__);
}

// File Line: 214
// RVA: 0x1587A00
__int64 dynamic_initializer_for__sPendingCommandBuildersMutex__()
{
  UFG::qMutex::qMutex(&sPendingCommandBuildersMutex, &customCaption);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__sPendingCommandBuildersMutex__);
}

// File Line: 250
// RVA: 0x69E660
void __fastcall Stereo3D::~Stereo3D(Stereo3D *this)
{
  this->vfptr = (Stereo3DVtbl *)&Stereo3D::`vftable;
}

// File Line: 313
// RVA: 0x69F9C0
__int64 __fastcall NVStereo3D::Init(NVStereo3D *this)
{
  char pIsStereoEnabled; // [rsp+30h] [rbp+8h] BYREF

  *(_WORD *)&this->mNV3DVision = 256;
  if ( NvAPI_Stereo_IsEnabled(&pIsStereoEnabled) || !pIsStereoEnabled )
    return 2147500037i64;
  NvAPI_Stereo_SetDriverMode(NVAPI_STEREO_DRIVER_MODE_DIRECT);
  NvAPI_Stereo_CreateConfigurationProfileRegistryKey(NVAPI_STEREO_DEFAULT_REGISTRY_PROFILE);
  this->mNV3DVision = 1;
  return 0i64;
}

// File Line: 349
// RVA: 0x6A0440
__int64 __fastcall NVStereo3D::InitStereo3D(NVStereo3D *this, IUnknown *pDevice, HWND__ *hwnd)
{
  if ( !this->mNV3DVision )
    return 2147500037i64;
  if ( NvAPI_Stereo_CreateHandleFromIUnknown(pDevice, &this->mStereoHandle) )
  {
    this->mNV3DVision = 0;
    return 2147500037i64;
  }
  else
  {
    NvAPI_Stereo_SetActiveEye(this->mStereoHandle, NVAPI_STEREO_EYE_MONO);
    NvAPI_Stereo_SetNotificationMessage(this->mStereoHandle, (unsigned __int64)hwnd, 0xBB8ui64);
    return 0i64;
  }
}

// File Line: 378
// RVA: 0x6A22F0
_BOOL8 __fastcall NVStereo3D::Stereo3DAvailable(NVStereo3D *this)
{
  return this->mNV3DVision;
}

// File Line: 384
// RVA: 0x69ED40
__int64 __fastcall NVStereo3D::CreateStereoSwapChain(
        NVStereo3D *this,
        IDXGIFactory1 *pIDXGIFactory,
        ID3D11Device *pd3d11Device,
        DXGI_SWAP_CHAIN_DESC *pRequestedSwapChainDesc,
        IDXGISwapChain **ppSwapChain)
{
  unsigned int v5; // ebx

  if ( !this->mNV3DVision )
    return 2147500037i64;
  v5 = 0;
  if ( NvAPI_D3D1x_CreateSwapChain(
         this->mStereoHandle,
         &pRequestedSwapChainDesc->BufferDesc.Width,
         (unsigned int **)ppSwapChain,
         NVAPI_STEREO_SWAPCHAIN_STEREO) < NVAPI_OK )
    return (unsigned int)-2147467259;
  return v5;
}

// File Line: 404
// RVA: 0x6A2040
void __fastcall NVStereo3D::SelectEye(NVStereo3D *this, Render::eStereoRenderEye eye)
{
  if ( eye )
  {
    if ( eye == STEREO_EYE_RIGHT )
      NvAPI_Stereo_SetActiveEye(this->mStereoHandle, NVAPI_STEREO_EYE_RIGHT);
  }
  else
  {
    NvAPI_Stereo_SetActiveEye(this->mStereoHandle, NVAPI_STEREO_EYE_LEFT);
  }
}

// File Line: 420
// RVA: 0x69EC70
void __fastcall NVStereo3D::CopyToEye(
        NVStereo3D *this,
        Render::eStereoRenderEye eye,
        ID3D11DeviceContext *pD3DContext,
        ID3D11Resource *pDstResource,
        ID3D11Resource *pSrcResource,
        unsigned int pixelConvergence)
{
  IUnknownVtbl *vfptr; // r10
  int v10; // eax
  __int64 v11; // r9
  _BYTE v12[12]; // [rsp+50h] [rbp-28h] BYREF
  int v13; // [rsp+5Ch] [rbp-1Ch]
  int v14; // [rsp+60h] [rbp-18h]
  int v15; // [rsp+64h] [rbp-14h]

  ((void (__fastcall *)(NVStereo3D *))this->vfptr->SelectEye)(this);
  vfptr = pD3DContext->vfptr;
  v15 = 1;
  if ( eye )
  {
    v11 = pixelConvergence;
    memset(v12, 0, sizeof(v12));
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
  ((void (__fastcall *)(ID3D11DeviceContext *, ID3D11Resource *, _QWORD, __int64, _DWORD, _DWORD, ID3D11Resource *, _DWORD, _BYTE *))vfptr[15].AddRef)(
    pD3DContext,
    pDstResource,
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
// attributes: thunk
void __fastcall NVStereo3D::Enable(NVStereo3D *this)
{
  NvAPI_Stereo_Enable();
}

// File Line: 455
// RVA: 0x69EDA0
// attributes: thunk
void __fastcall NVStereo3D::Disable(NVStereo3D *this)
{
  NvAPI_Stereo_Disable();
}

// File Line: 494
// RVA: 0x69E5E0
void __fastcall AMDStereo3D::AMDStereo3D(AMDStereo3D *this)
{
  this->vfptr = (Stereo3DVtbl *)&Stereo3D::`vftable;
  this->vfptr = (Stereo3DVtbl *)&AMDStereo3D::`vftable;
  AMD_HD3D::AMD_HD3D(&this->mHD3D);
  *(_WORD *)&this->mAMDHD3D = 0;
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
HRESULT __fastcall AMDStereo3D::CreateStereoSwapChain(
        AMDStereo3D *this,
        IDXGIFactory1 *pIDXGIFactory,
        ID3D11Device *pd3d11Device,
        DXGI_SWAP_CHAIN_DESC *pRequestedSwapChainDesc,
        IDXGISwapChain **ppSwapChain)
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
void __fastcall AMDStereo3D::SelectEye(AMDStereo3D *this, unsigned int eye)
{
  if ( eye <= 1 )
    _(&this->mHD3D);
}

// File Line: 557
// RVA: 0x69EBB0
void __fastcall AMDStereo3D::CopyToEye(
        AMDStereo3D *this,
        Render::eStereoRenderEye eye,
        ID3D11DeviceContext *pD3DContext,
        ID3D11Resource *pDstResource,
        ID3D11Resource *pSrcResource,
        int pixelConvergence)
{
  IUnknownVtbl *vfptr; // r10
  int v7; // [rsp+50h] [rbp-28h] BYREF
  __int64 v8; // [rsp+54h] [rbp-24h]
  int v9; // [rsp+5Ch] [rbp-1Ch]
  int v10; // [rsp+60h] [rbp-18h]
  int v11; // [rsp+64h] [rbp-14h]

  if ( eye )
  {
    if ( eye == STEREO_EYE_RIGHT )
      AMD_HD3D::UpdateRightQuadBuffer(&this->mHD3D, pD3DContext, pDstResource, pSrcResource, pixelConvergence);
  }
  else
  {
    vfptr = pD3DContext->vfptr;
    v7 = pixelConvergence;
    v9 = gScreenWidth - pixelConvergence;
    v8 = 0i64;
    v10 = gScreenHeight;
    v11 = 1;
    ((void (__fastcall *)(ID3D11DeviceContext *, ID3D11Resource *, _QWORD, _QWORD, _DWORD, _DWORD, ID3D11Resource *, _DWORD, int *))vfptr[15].AddRef)(
      pD3DContext,
      pDstResource,
      0i64,
      0i64,
      0,
      0,
      pSrcResource,
      0,
      &v7);
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
void __fastcall Render::GetWindowRectAndStyle(
        tagRECT *rc,
        unsigned int *dwStyle,
        unsigned int *dwStyleEx,
        int client_w,
        int client_h)
{
  *dwStyle = 13565952;
  *dwStyleEx = 0;
  SetRect(rc, 0, 0, client_w, client_h);
  AdjustWindowRectEx(rc, *dwStyle, 0, *dwStyleEx);
}

// File Line: 849
// RVA: 0x6A2250
void __fastcall Render::SetWindow(int width, int height)
{
  tagRECT rc; // [rsp+30h] [rbp-28h] BYREF
  tagRECT Rect; // [rsp+40h] [rbp-18h] BYREF

  GetWindowRect(ghWnd, &Rect);
  SetRect(&rc, 0, 0, width, height);
  AdjustWindowRectEx(&rc, 0xCF0000u, 0, 0);
  MoveWindow(ghWnd, Rect.left, Rect.top, rc.right - rc.left, rc.bottom - rc.top, 1);
}

// File Line: 868
// RVA: 0x6A0650
signed __int64 __fastcall Render::InitWindow(Render::RenderInitParams *params)
{
  unsigned int mIconResourceId; // ebx
  HMODULE ModuleHandleA; // rax
  HICON__ *IconA; // rax
  unsigned int mCursorResourceId; // ebx
  HMODULE v6; // rax
  HICON__ *CursorA; // rax
  int v9; // r9d
  __int64 yBottom; // rcx
  HWND Window; // rax
  tagRECT rc; // [rsp+60h] [rbp-78h] BYREF
  tagRECT Rect; // [rsp+70h] [rbp-68h] BYREF
  WNDCLASSEXA v14; // [rsp+80h] [rbp-58h] BYREF

  mIconResourceId = (unsigned __int16)params->mIconResourceId;
  v14.lpfnWndProc = Render::WndProc;
  v14.cbSize = 80;
  v14.style = 11;
  v14.hInstance = gInstance;
  *(_QWORD *)&v14.cbClsExtra = 0i64;
  ModuleHandleA = GetModuleHandleA(0i64);
  IconA = LoadIconA(ModuleHandleA, (LPCSTR)mIconResourceId);
  mCursorResourceId = (unsigned __int16)params->mCursorResourceId;
  v14.hIcon = IconA;
  v6 = GetModuleHandleA(0i64);
  CursorA = LoadCursorA(v6, (LPCSTR)mCursorResourceId);
  *(__m128i *)&v14.hbrBackground = _mm_load_si128((const __m128i *)&_xmm);
  v14.lpszClassName = "TheoryWindowClassPC64";
  v14.hIconSm = 0i64;
  v14.hCursor = CursorA;
  if ( !RegisterClassExA(&v14) )
    return 0i64;
  gOutputParams = params->mRenderOutputParams;
  v9 = _mm_cvtsi128_si32(*(__m128i *)&gOutputParams.mDisplayMode.mBackBufferWidth);
  if ( v9
    && (yBottom = HIDWORD(*(_QWORD *)&gOutputParams.mDisplayMode.mBackBufferWidth),
        gOutputParams.mDisplayMode.mBackBufferHeight) )
  {
    gScreenHeight = gOutputParams.mDisplayMode.mBackBufferHeight;
  }
  else
  {
    v9 = g_MainViewWidth;
    LODWORD(yBottom) = g_MainViewHeight;
    gScreenHeight = g_MainViewHeight;
    gOutputParams.mDisplayMode.mBackBufferWidth = g_MainViewWidth;
    gOutputParams.mDisplayMode.mBackBufferHeight = g_MainViewHeight;
  }
  gScreenWidth = v9;
  g_Fullscreen = gOutputParams.mEnableFullscreen;
  g_PrevFullscreen = !gOutputParams.mEnableFullscreen;
  SetRect(&rc, 0, 0, v9, yBottom);
  AdjustWindowRectEx(&rc, 0xCF0000u, 0, 0);
  Window = CreateWindowExA(
             0,
             "TheoryWindowClassPC64",
             params->mTitleName,
             0xCF0000u,
             0x80000000,
             0x80000000,
             rc.right - rc.left,
             rc.bottom - rc.top,
             0i64,
             0i64,
             gInstance,
             0i64);
  ghWnd = Window;
  if ( !Window )
    return 0i64;
  GetClientRect(Window, &Rect);
  ShowWindow(ghWnd, gCmdShow);
  return 1i64;
}

// File Line: 1053
// RVA: 0x69F270
void __fastcall Render::EnumerateAdaptersAndOutputs(Render *this)
{
  unsigned int v1; // r15d
  int v2; // r14d
  unsigned int i; // esi
  unsigned __int64 v4; // rax
  unsigned __int64 v5; // rdi
  unsigned int v6; // ebx
  unsigned int v7; // edx
  OutputInfo *p; // rax
  unsigned __int64 v9; // rcx
  __int64 v10; // rdi
  unsigned int v11; // ebx
  unsigned int v12; // edx
  char *v13; // rdx
  AdapterInfo *v14; // rcx
  __int64 v15; // rax
  __int128 v16; // xmm0
  __int64 v17; // rdx
  __int128 v18[6]; // [rsp+30h] [rbp-D0h] BYREF
  __int128 v19; // [rsp+90h] [rbp-70h] BYREF
  UFG::allocator::free_link *v20; // [rsp+A0h] [rbp-60h]
  char Src[304]; // [rsp+B0h] [rbp-50h] BYREF
  int v22; // [rsp+1E0h] [rbp+E0h]
  __int64 v23; // [rsp+1E8h] [rbp+E8h]
  unsigned int v24; // [rsp+1F0h] [rbp+F0h]
  unsigned int size; // [rsp+1F4h] [rbp+F4h]
  unsigned int v26; // [rsp+1F8h] [rbp+F8h]
  __int64 v27; // [rsp+240h] [rbp+140h] BYREF
  __int64 v28; // [rsp+248h] [rbp+148h] BYREF

  v1 = 0;
  v2 = 0;
  if ( sDXGIFactory->vfptr[4].QueryInterface(sDXGIFactory, 0i64, (void **)&v27) != -2005270526 )
  {
    do
    {
      if ( (*(int (__fastcall **)(__int64, GUID *, _QWORD))(*(_QWORD *)v27 + 72i64))(
             v27,
             &GUID_9b7e4c0f_342c_4106_a19f_4f2704f689f0,
             0i64) >= 0 )
      {
        (*(void (__fastcall **)(__int64, char *))(*(_QWORD *)v27 + 80i64))(v27, Src);
        v23 = v27;
        size = sAvailableDXGIOutputs.size;
        v24 = v1;
        for ( i = 0;
              (*(unsigned int (__fastcall **)(__int64, _QWORD, __int64 *))(*(_QWORD *)v27 + 56i64))(v27, i, &v28) != -2005270526;
              p[v9].mpValidDisplayModes = (DXGI_MODE_DESC *)v20 )
        {
          (*(void (__fastcall **)(__int64, __int128 *))(*(_QWORD *)v28 + 56i64))(v28, v18);
          *(_QWORD *)&v19 = v28;
          *((_QWORD *)&v19 + 1) = sAvailableDXGIAdapters.size;
          v20 = 0i64;
          if ( v22 != 1 )
          {
            (*(void (__fastcall **)(__int64, __int64, __int64, char *, _QWORD))(*(_QWORD *)v28 + 64i64))(
              v28,
              28i64,
              3i64,
              (char *)&v19 + 12,
              0i64);
            if ( HIDWORD(v19) )
            {
              v4 = 28i64 * HIDWORD(v19);
              if ( !is_mul_ok(HIDWORD(v19), 0x1Cui64) )
                v4 = -1i64;
              v20 = UFG::qMalloc(v4, UFG::gGlobalNewName, 0i64);
              (*(void (__fastcall **)(__int64, __int64, __int64, char *, UFG::allocator::free_link *))(*(_QWORD *)v28 + 64i64))(
                v28,
                28i64,
                3i64,
                (char *)&v19 + 12,
                v20);
              v2 += HIDWORD(v19);
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
          p = sAvailableDXGIOutputs.p;
          sAvailableDXGIOutputs.size = v6;
          ++i;
          v9 = v5;
          *(_OWORD *)sAvailableDXGIOutputs.p[v9].mOutputDesc.DeviceName = v18[0];
          *(_OWORD *)&p[v9].mOutputDesc.DeviceName[8] = v18[1];
          *(_OWORD *)&p[v9].mOutputDesc.DeviceName[16] = v18[2];
          *(_OWORD *)&p[v9].mOutputDesc.DeviceName[24] = v18[3];
          p[v9].mOutputDesc.DesktopCoordinates = (tagRECT)v18[4];
          *(_OWORD *)&p[v9].mOutputDesc.AttachedToDesktop = v18[5];
          *(_OWORD *)&p[v9].mOutputInterface = v19;
        }
        v10 = sAvailableDXGIAdapters.size;
        v26 = i;
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
        v13 = Src;
        sAvailableDXGIAdapters.size = v11;
        v14 = &sAvailableDXGIAdapters.p[v10];
        if ( (((unsigned __int8)v14 | (unsigned __int8)Src) & 0xF) != 0 )
        {
          memmove(v14, Src, 0x150ui64);
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
    while ( sDXGIFactory->vfptr[4].QueryInterface(sDXGIFactory, (_GUID *)v1, (void **)&v27) != -2005270526 );
    if ( v2 )
    {
      v17 = sAvailableDXGIOutputs.p->mNumValidDisplayModes - 1;
      gMonitorNativeDisplayAspectRatio = (float)(int)sAvailableDXGIOutputs.p->mpValidDisplayModes[v17].Width
                                       / (float)(int)sAvailableDXGIOutputs.p->mpValidDisplayModes[v17].Height;
    }
  }
}

// File Line: 1179
// RVA: 0x6A0CE0
void __fastcall Render::ReleaseAdaptersAndOutputs(Render *this)
{
  OutputInfo *p; // rcx
  unsigned int i; // edi
  unsigned __int64 v3; // rbx
  IDXGIOutput *mOutputInterface; // rdx
  unsigned int size; // edx
  AdapterInfo *v6; // rax
  unsigned int j; // ebx
  __int64 v8; // rdi
  IDXGIAdapter1 *mAdapterInterface; // rcx

  p = sAvailableDXGIOutputs.p;
  for ( i = 0; i < sAvailableDXGIOutputs.size; ++i )
  {
    v3 = i;
    mOutputInterface = p[v3].mOutputInterface;
    if ( mOutputInterface )
    {
      mOutputInterface->vfptr->Release(p[v3].mOutputInterface);
      sAvailableDXGIOutputs.p[v3].mOutputInterface = 0i64;
      p = sAvailableDXGIOutputs.p;
    }
    if ( p[v3].mpValidDisplayModes )
    {
      operator delete[](p[v3].mpValidDisplayModes);
      p = sAvailableDXGIOutputs.p;
    }
  }
  if ( p )
    operator delete[](p);
  size = sAvailableDXGIAdapters.size;
  v6 = sAvailableDXGIAdapters.p;
  sAvailableDXGIOutputs.p = 0i64;
  *(_QWORD *)&sAvailableDXGIOutputs.size = 0i64;
  for ( j = 0; j < size; ++j )
  {
    v8 = j;
    mAdapterInterface = v6[v8].mAdapterInterface;
    if ( mAdapterInterface )
    {
      mAdapterInterface->vfptr->Release(mAdapterInterface);
      sAvailableDXGIAdapters.p[v8].mAdapterInterface = 0i64;
      v6 = sAvailableDXGIAdapters.p;
      size = sAvailableDXGIAdapters.size;
    }
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
  int v1; // ebx
  unsigned int v2; // eax
  unsigned int *i; // rcx
  __int64 v4; // rdi
  IDXGIAdapter1 *mAdapterInterface; // rax
  IDXGIOutput *mOutputInterface; // rcx
  const unsigned __int16 *j; // rax

  v1 = 0;
  sDXGIAdapter = 0i64;
  sDXGIOutput = 0i64;
  sSelectedOutputIndex = 0;
  v2 = 0;
  if ( sAvailableDXGIAdapters.size )
  {
    for ( i = &sAvailableDXGIAdapters.p->mNumOutputs; !*i; i += 84 )
    {
      if ( ++v2 >= sAvailableDXGIAdapters.size )
        return;
    }
    v4 = v2;
    mAdapterInterface = sAvailableDXGIAdapters.p[v4].mAdapterInterface;
    sSelectedOutputIndex = sAvailableDXGIAdapters.p[v4].mStartOutputIndex;
    sDXGIAdapter = mAdapterInterface;
    mOutputInterface = sAvailableDXGIOutputs.p[sSelectedOutputIndex].mOutputInterface;
    sAvailableDXGIAdapters.p[v4].mAdapterDesc.Description[127] = 0;
    sDXGIOutput = mOutputInterface;
    UFG::qWideStringCopy(Render::gVideoCardDesc, sAvailableDXGIAdapters.p[v4].mAdapterDesc.Description);
    Render::gVideoMemory = sAvailableDXGIAdapters.p[v4].mAdapterDesc.DedicatedVideoMemory;
    gOutputParams.mDisplayMode.mAdapterUID = UFG::qDataHash32(
                                               (char *)&sAvailableDXGIAdapters.p[v4].mAdapterDesc.VendorId,
                                               0x10ui64,
                                               0xFFFFFFFF);
    gOutputParams.mDisplayMode.mMonitorUID = UFG::qDataHash32(
                                               (char *)&sAvailableDXGIOutputs.p[sSelectedOutputIndex],
                                               0x58ui64,
                                               0xFFFFFFFF);
    if ( LOWORD(sAvailableDXGIAdapters.p[v4].mAdapterDesc.VendorId) == 4098 )
    {
      for ( j = s_LegacyATIDevices; LOWORD(sAvailableDXGIAdapters.p[v4].mAdapterDesc.DeviceId) != *j; ++j )
      {
        if ( (unsigned int)++v1 >= 0xE2 )
        {
          gOutputParams.mDeviceType = DEVICE_TYPE_CURRENT_AMD;
          return;
        }
      }
      gOutputParams.mDeviceType = DEVICE_TYPE_LEGACY_ATI;
    }
  }
}

// File Line: 1346
// RVA: 0x69EDB0
__int64 __fastcall Render::DisplayModesInternal(
        Render::DisplayMode *filter,
        Render::DisplayMode *outDisplayModes,
        bool setDXGIMode)
{
  unsigned int v4; // ebx
  unsigned __int64 v5; // rax
  UFG::allocator::free_link *v6; // rax
  OutputInfo *p; // r14
  unsigned int v8; // r12d
  UFG::allocator::free_link *v9; // r10
  __int64 v10; // rax
  DXGI_MODE_DESC *v11; // r15
  __int64 v12; // rdx
  unsigned int mBackBufferHeight; // eax
  Render::eDisplayScalingModes mScaling; // eax
  Render::eScanlineMode mScanlineMode; // eax
  char v16; // di
  unsigned int v17; // r8d
  __int64 v18; // r9
  int v19; // ebp
  __int64 v20; // r11
  unsigned int v21; // esi
  _DWORD *v22; // rcx
  int v23; // eax
  __int64 v24; // r11
  __int64 v25; // rcx
  int v26; // eax
  __int64 v27; // rcx
  __int64 v31; // [rsp+78h] [rbp+20h]

  UFG::qMutex::Lock((LPCRITICAL_SECTION)&sDXGIMutex);
  v4 = 0;
  v5 = 28i64 * sAvailableDXGIOutputs.p[sSelectedOutputIndex].mNumValidDisplayModes;
  if ( !is_mul_ok(sAvailableDXGIOutputs.p[sSelectedOutputIndex].mNumValidDisplayModes, 0x1Cui64) )
    v5 = -1i64;
  v6 = UFG::qMalloc(v5, UFG::gGlobalNewName, 0i64);
  p = sAvailableDXGIOutputs.p;
  v8 = 0;
  v9 = v6;
  v10 = 120i64 * sSelectedOutputIndex;
  v31 = v10;
  if ( !*(unsigned int *)((char *)&sAvailableDXGIOutputs.p->mNumValidDisplayModes + v10) )
    goto LABEL_40;
  v11 = sDXGIMode;
  do
  {
    v12 = (__int64)&(*(DXGI_MODE_DESC **)((char *)&p->mpValidDisplayModes + v10))[v8];
    if ( filter->mBackBufferWidth && filter->mBackBufferWidth != *(_DWORD *)v12 )
      goto LABEL_39;
    mBackBufferHeight = filter->mBackBufferHeight;
    if ( mBackBufferHeight )
    {
      if ( mBackBufferHeight != *(_DWORD *)(v12 + 4) )
        goto LABEL_39;
    }
    mScaling = filter->mScaling;
    if ( mScaling != SCALING_MODE_NOTFILTERED && mScaling != *(_DWORD *)(v12 + 24) )
      goto LABEL_39;
    mScanlineMode = filter->mScanlineMode;
    if ( mScanlineMode != SCANLINE_MODE_NOTFILTERED && mScanlineMode != *(_DWORD *)(v12 + 20) )
      goto LABEL_39;
    v16 = 0;
    v17 = 0;
    v18 = 0i64;
    v19 = -1;
    v20 = -1i64;
    if ( !v4 )
      goto LABEL_30;
    v21 = *(_DWORD *)v12;
    v22 = (_DWORD *)&v9[2].mNext + 1;
    while ( 1 )
    {
      if ( v21 != *(v22 - 5) || *(_DWORD *)(v12 + 4) != *(v22 - 4) || *(_DWORD *)(v12 + 20) != *v22 )
        goto LABEL_24;
      if ( (float)((float)*(int *)(v12 + 8) / (float)*(int *)(v12 + 12)) < (float)((float)(int)*(v22 - 3)
                                                                                 / (float)(int)*(v22 - 2)) )
        goto LABEL_39;
      v23 = v22[1];
      if ( (v23 || !*(_DWORD *)(v12 + 24)) && (v23 != 2 || *(_DWORD *)(v12 + 24) != 1) )
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
        *(_DWORD *)((char *)&v9->mNext + v24 + 4) = *(_DWORD *)(v12 + 4);
        *(_DWORD *)((char *)&v9[1].mNext + v24) = *(_DWORD *)(v12 + 8);
        *(_DWORD *)((char *)&v9[1].mNext + v24 + 4) = *(_DWORD *)(v12 + 12);
        *(_DWORD *)((char *)&v9[2].mNext + v24) = *(_DWORD *)(v12 + 16);
        *(_DWORD *)((char *)&v9[2].mNext + v24 + 4) = *(_DWORD *)(v12 + 20);
        *(_DWORD *)((char *)&v9[3].mNext + v24) = *(_DWORD *)(v12 + 24);
        goto LABEL_31;
      }
LABEL_30:
      v25 = 28i64 * v4;
      *(_DWORD *)((char *)&v9->mNext + v25) = *(_DWORD *)v12;
      *(_DWORD *)((char *)&v9->mNext + v25 + 4) = *(_DWORD *)(v12 + 4);
      *(_DWORD *)((char *)&v9[1].mNext + v25) = *(_DWORD *)(v12 + 8);
      *(_DWORD *)((char *)&v9[1].mNext + v25 + 4) = *(_DWORD *)(v12 + 12);
      *(_DWORD *)((char *)&v9[2].mNext + v25) = *(_DWORD *)(v12 + 16);
      *(_DWORD *)((char *)&v9[2].mNext + v25 + 4) = *(_DWORD *)(v12 + 20);
      *(_DWORD *)((char *)&v9[3].mNext + v25) = *(_DWORD *)(v12 + 24);
LABEL_31:
      if ( outDisplayModes )
      {
        v26 = v19;
        if ( v19 == -1 )
          v26 = v4;
        v27 = v26;
        outDisplayModes[v27].mBackBufferWidth = *(_DWORD *)v12;
        outDisplayModes[v27].mBackBufferHeight = *(_DWORD *)(v12 + 4);
        outDisplayModes[v27].mRefreshRateNumerator = *(_DWORD *)(v12 + 8);
        outDisplayModes[v27].mRefreshRateDenominator = *(_DWORD *)(v12 + 12);
        outDisplayModes[v27].mAdapterUID = gOutputParams.mDisplayMode.mAdapterUID;
        outDisplayModes[v27].mMonitorUID = gOutputParams.mDisplayMode.mMonitorUID;
        outDisplayModes[v27].mScaling = *(_DWORD *)(v12 + 24);
        outDisplayModes[v27].mScanlineMode = *(_DWORD *)(v12 + 20);
      }
      p = sAvailableDXGIOutputs.p;
      if ( setDXGIMode )
        v11 = (DXGI_MODE_DESC *)v12;
      sDXGIMode = v11;
      if ( v19 == -1 )
        ++v4;
    }
LABEL_39:
    v10 = v31;
    ++v8;
  }
  while ( v8 < *(unsigned int *)((char *)&p->mNumValidDisplayModes + v31) );
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
  return settings->mDisplayMode.mAdapterUID == gOutputParams.mDisplayMode.mAdapterUID
      && settings->mDisplayMode.mMonitorUID == gOutputParams.mDisplayMode.mMonitorUID
      && (unsigned int)Render::DisplayModesInternal(&settings->mDisplayMode, 0i64, 0) == 1;
}

// File Line: 1471
// RVA: 0x69E7C0
void __fastcall Render::ApplyDisplaySettings(Render::RenderOutputParams *settings)
{
  char v2; // cl
  bool v3; // zf
  bool v4; // cl
  char v5; // cl
  char v6; // cl
  char v7; // cl
  char v8; // dl
  __m128i v9; // xmm2
  __int64 v10; // xmm1_8
  char v11; // al
  Render::DisplayMode outDisplayModes; // [rsp+20h] [rbp-28h] BYREF

  if ( Render::DisplayModesInternal(&settings->mDisplayMode, 0i64, 0) == 1 )
  {
    Render::DisplayModesInternal(&settings->mDisplayMode, &outDisplayModes, 1);
    Illusion::SetDefaultTextureFilterQuality(settings->mTextureFilterQuality);
    v2 = sbEventResizeShadows;
    if ( settings->mShadowRes != gOutputParams.mShadowRes )
      v2 = 1;
    v3 = settings->mAAQuality == gOutputParams.mAAQuality;
    sbEventResizeShadows = v2;
    v4 = sbEventResizeBuffers;
    if ( !v3 )
      v4 = 1;
    if ( settings->mSSAO != gOutputParams.mSSAO )
      v4 = 1;
    v3 = settings->mTextureDetailLevel == gOutputParams.mTextureDetailLevel;
    sbEventResizeBuffers = v4;
    v5 = sbEventChangeTexturePack;
    if ( !v3 )
      v5 = 1;
    v3 = settings->mLODSetting == gOutputParams.mLODSetting;
    sbEventChangeTexturePack = v5;
    v6 = sbEventChangeLODSetting;
    if ( !v3 )
      v6 = 1;
    sbEventChangeLODSetting = v6;
    v7 = 0;
    if ( settings->mDisplayMode.mBackBufferHeight != gOutputParams.mDisplayMode.mBackBufferHeight
      || settings->mDisplayMode.mBackBufferWidth != gOutputParams.mDisplayMode.mBackBufferWidth
      || g_Fullscreen != settings->mEnableFullscreen )
    {
      v7 = 1;
    }
    v8 = v7;
    v3 = gOutputParams.mEnableLowResBuffer == settings->mEnableLowResBuffer;
    *(_OWORD *)&gOutputParams.mDisplayMode.mBackBufferWidth = *(_OWORD *)&settings->mDisplayMode.mBackBufferWidth;
    if ( !v3 )
      v8 = 1;
    *(_OWORD *)&gOutputParams.mDisplayMode.mAdapterUID = *(_OWORD *)&settings->mDisplayMode.mAdapterUID;
    *(_OWORD *)&gOutputParams.mEnableFullscreen = *(_OWORD *)&settings->mEnableFullscreen;
    v9 = _mm_srli_si128(*(__m128i *)&gOutputParams.mEnableFullscreen, 3);
    *(_OWORD *)&gOutputParams.mShadowFilter = *(_OWORD *)&settings->mShadowFilter;
    *(_OWORD *)&gOutputParams.mFPSLimiter = *(_OWORD *)&settings->mFPSLimiter;
    *(_OWORD *)&gOutputParams.mLODSetting = *(_OWORD *)&settings->mLODSetting;
    v10 = *(_QWORD *)&settings->mTextureFilterQuality;
    gOutputParams.mDisplayMode.mRefreshRateNumerator = outDisplayModes.mRefreshRateNumerator;
    *(_QWORD *)&gOutputParams.mTextureFilterQuality = v10;
    gOutputParams.mDisplayMode.mRefreshRateDenominator = outDisplayModes.mRefreshRateDenominator;
    g_Fullscreen = settings->mEnableFullscreen;
    g_signalEnable3D = settings->mEnable3D;
    if ( g_signalEnable3D != g_enable3D )
      v8 = 1;
    g_interAxialDistance = settings->mInterAxialDistance;
    Render::gEnableCloudVolumes = settings->mEnableCloudVolumes;
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
  *outSettings = gOutputParams;
}

// File Line: 1541
// RVA: 0x69F8A0
float __fastcall Render::GetExtraWideAspectCorrectedFOV(float inputFOV)
{
  float v2; // xmm1_4
  float v3; // xmm2_4
  float v4; // xmm0_4
  float v5; // xmm2_4

  if ( inputFOV <= 1.085 )
    v2 = FLOAT_1_085;
  else
    v2 = inputFOV;
  v3 = powf(1.085 / v2, gExtraWideAspectFOVCorrectionPOW);
  v4 = *(float *)&FLOAT_1_0;
  v5 = (float)(v3 * (float)((float)((float)(gDisplayAspectRatio * 0.5625) - 1.0) * gExtraWideAspectFOVCorrection)) + 1.0;
  if ( v5 >= 1.0 )
    v4 = v5;
  return v4 * inputFOV;
}

// File Line: 1547
// RVA: 0x6A2080
void __fastcall Render::SetInitialDisplayMode(Render *this)
{
  OutputInfo *v1; // rdx
  bool v2; // bl
  char v3; // al
  Render::DisplayMode filter; // [rsp+20h] [rbp-28h] BYREF

  if ( (unsigned int)Render::DisplayModesInternal(&gOutputParams.mDisplayMode, 0i64, 0) == 1 )
  {
    Render::ApplyDisplaySettings(&gOutputParams);
  }
  else
  {
    filter.mScanlineMode = SCANLINE_MODE_PROGRESSIVE;
    memset(&filter.mRefreshRateNumerator, 0, 20);
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
        filter.mScaling = SCALING_MODE_NOTFILTERED;
        if ( !(unsigned int)Render::DisplayModesInternal(&filter, 0i64, 1) )
        {
          filter.mScanlineMode = SCANLINE_MODE_NOTFILTERED;
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
    *(DXGI_RATIONAL *)&gOutputParams.mDisplayMode.mRefreshRateNumerator = sDXGIMode->RefreshRate;
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
  __int64 v1; // rbx
  __int64 v2; // rdi
  ID3D11Query *v3; // rcx
  ID3D11Query *v4; // rcx
  ID3D11Query *v5; // rcx

  Render::ReleaseAdaptersAndOutputs(this);
  if ( sDXGIFactory )
  {
    sDXGIFactory->vfptr->Release(sDXGIFactory);
    sDXGIFactory = 0i64;
  }
  if ( sDXGIDevice )
  {
    sDXGIDevice->vfptr->Release(sDXGIDevice);
    sDXGIDevice = 0i64;
  }
  if ( sContext )
  {
    sContext->vfptr->Release(sContext);
    sContext = 0i64;
  }
  if ( sDevice )
  {
    ((void (__fastcall *)(ID3D11Device *))sDevice->vfptr->Release)(sDevice);
    sDevice = 0i64;
  }
  if ( sStereo3D )
  {
    sStereo3D->vfptr->Release(sStereo3D);
    sStereo3D = 0i64;
  }
  sDXGIMode = 0i64;
  sDXGIPrevMode = 0i64;
  v1 = 0i64;
  v2 = 2i64;
  do
  {
    v3 = sQueryGPUTimeStampDisjoint[v1];
    if ( v3 )
    {
      v3->vfptr->Release(v3);
      sQueryGPUTimeStampDisjoint[v1] = 0i64;
    }
    v4 = sQueryGPUTimeStart[v1];
    if ( v4 )
    {
      v4->vfptr->Release(v4);
      sQueryGPUTimeStart[v1] = 0i64;
    }
    v5 = sQueryGPUTimeEnd[v1];
    if ( v5 )
    {
      v5->vfptr->Release(v5);
      sQueryGPUTimeEnd[v1] = 0i64;
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
  float maxNumAFRGroups; // xmm0_4
  __int64 v9; // rdi
  __int64 v10; // rsi
  NV_GET_CURRENT_SLI_STATE pSliState; // [rsp+58h] [rbp-240h] BYREF
  NvPhysicalGpuHandle__ *nvGPUHandle; // [rsp+80h] [rbp-218h] BYREF
  unsigned int pGpuCount; // [rsp+2A0h] [rbp+8h] BYREF
  int v15; // [rsp+2A4h] [rbp+Ch]
  int v16; // [rsp+2A8h] [rbp+10h] BYREF
  UFG::allocator::free_link *v17; // [rsp+2B0h] [rbp+18h]

  Render::ReleaseD3D(a1);
  CreateDXGIFactory1_0(&GUID_770aae78_f26f_4dba_a829_253c83d1b387, (void **)&sDXGIFactory);
  Render::EnumerateAdaptersAndOutputs(v1);
  if ( !sAvailableDXGIOutputs.size )
    goto $D3D_ERROR_HANDLER;
  Render::SelectDXGIAdapterAndOutput(v2);
  Render::SetInitialDisplayMode(v3);
  v4 = 0;
  if ( (unsigned int)NvAPI_Initialize() || NvAPI_EnumPhysicalGPUs(&nvGPUHandle, &pGpuCount) || !pGpuCount )
  {
    v6 = UFG::qMalloc(0x30ui64, UFG::gGlobalNewName, 0i64);
    v17 = v6;
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
    v17 = v5;
    if ( v5 )
    {
      v5->mNext = (UFG::allocator::free_link *)&Stereo3D::`vftable;
      v5->mNext = (UFG::allocator::free_link *)&NVStereo3D::`vftable;
      LOWORD(v5[2].mNext) = 0;
    }
    else
    {
      v5 = 0i64;
    }
    v4 = 1;
  }
  sStereo3D = (Stereo3D *)v5;
  ((void (__fastcall *)(UFG::allocator::free_link *))v5->mNext[1].mNext)(v5);
  if ( (int)D3D11CreateDevice_0(sDXGIAdapter, 0i64, 0i64, 32i64, 0i64, 0, 7, &sDevice, &v16, &sContext, -2i64) < 0 )
    goto $D3D_ERROR_HANDLER;
  if ( v16 < 40960 )
    return 0;
  gOutputParams.mFeatureLevel = v16 < 0xB000 ? v16 >= 41216 : FEATURE_LEVEL_D3D11_0;
  if ( v4 )
  {
    pSliState.version = 65564;
    if ( NvAPI_D3D_GetCurrentSLIState((IUnknown *)sDevice, &pSliState) == NVAPI_OK )
    {
      maxNumAFRGroups = *(float *)&FLOAT_1_0;
      if ( (float)(int)pSliState.maxNumAFRGroups >= 1.0 )
        maxNumAFRGroups = (float)(int)pSliState.maxNumAFRGroups;
      gNumGPUs = (int)maxNumAFRGroups;
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
$D3D_ERROR_HANDLER:
    Render::ReleaseD3D(v2);
    return 0;
  }
  v9 = 0i64;
  v10 = 2i64;
  do
  {
    v15 = 0;
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
      &sQueryGPUTimeEnd[v9++]);
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
    sPresentRenderTargetView->vfptr->Release(sPresentRenderTargetView);
    v1 = sDXGISwapChain;
    sPresentRenderTargetView = 0i64;
  }
  if ( gPresentBuffer )
  {
    gPresentBuffer->vfptr->Release(gPresentBuffer);
    v1 = sDXGISwapChain;
    gPresentBuffer = 0i64;
  }
  if ( v1 )
  {
    v1->vfptr->Release(v1);
    sDXGISwapChain = 0i64;
  }
}

// File Line: 1844
// RVA: 0x6A04D0
char __fastcall Render::InitSwapChain(Render *fullscreen)
{
  char v1; // bl
  Render *v2; // rcx
  __int64 v4[3]; // [rsp+30h] [rbp-50h] BYREF
  int v5; // [rsp+48h] [rbp-38h]
  __int64 v6; // [rsp+4Ch] [rbp-34h]
  int v7; // [rsp+54h] [rbp-2Ch]
  __int64 v8; // [rsp+58h] [rbp-28h]
  HWND v9; // [rsp+60h] [rbp-20h]
  _BOOL8 v10; // [rsp+68h] [rbp-18h]
  __int64 v11; // [rsp+70h] [rbp-10h]

  v1 = (char)fullscreen;
  Render::ReleaseSwapChain(fullscreen);
  v5 = 0;
  v4[0] = __PAIR64__(gScreenHeight, gScreenWidth);
  v4[2] = 28i64;
  v6 = 1i64;
  v9 = ghWnd;
  v10 = v1 == 0;
  v4[1] = *(_QWORD *)&gOutputParams.mDisplayMode.mRefreshRateNumerator;
  v7 = 32;
  v8 = 2i64;
  v11 = 2i64;
  g_stereoSwapChain = 0;
  if ( !g_enable3D
    || sStereo3D->vfptr->CreateStereoSwapChain(
         sStereo3D,
         sDXGIFactory,
         sDevice,
         (DXGI_SWAP_CHAIN_DESC *)v4,
         &sDXGISwapChain) )
  {
    if ( ((int (__fastcall *)(IDXGIFactory1 *, ID3D11Device *, __int64 *, IDXGISwapChain **))sDXGIFactory->vfptr[3].AddRef)(
           sDXGIFactory,
           sDevice,
           v4,
           &sDXGISwapChain) < 0 )
      goto $D3D_ERROR_HANDLER_0;
  }
  else
  {
    g_stereoSwapChain = 1;
  }
  if ( ((int (__fastcall *)(IDXGISwapChain *, _QWORD, GUID *, ID3D11Texture2D **))sDXGISwapChain->vfptr[3].QueryInterface)(
         sDXGISwapChain,
         0i64,
         &GUID_6f15aaf2_d208_4e89_9ab4_489535d34f9c,
         &gPresentBuffer) >= 0
    && ((int (__fastcall *)(ID3D11Device *, ID3D11Texture2D *, _QWORD, ID3D11RenderTargetView **))sDevice->vfptr->Draw)(
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
  bool v1; // bl
  Render *v2; // rcx

  Render::InitWindow(params);
  v1 = 0;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&sDXGIMutex);
  if ( Render::InitD3D(v2) )
    v1 = Render::InitSwapChain(0i64) != 0;
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
  Illusion *v2; // rcx
  ID3D11DeviceContext *v3; // rax
  Illusion *v4; // rcx
  Render *v5; // rcx
  unsigned int i; // edi
  unsigned int v7; // ebx
  char *v8; // rax
  int v9; // edi
  unsigned int v10; // ebx
  Illusion::FrameWriteMemoryPlat *v11; // rsi
  int v12; // edi
  unsigned int v13; // ebx
  Illusion::FrameWriteMemoryPlat *v14; // rsi
  unsigned int j; // ebx
  unsigned int k; // ebx
  Render *v17; // rcx
  Render *v18; // rcx
  int v19; // [rsp+20h] [rbp-C8h] BYREF
  __int64 v20; // [rsp+24h] [rbp-C4h]
  __int64 v21; // [rsp+2Ch] [rbp-BCh]
  int v22; // [rsp+34h] [rbp-B4h]
  UFG::qVRAMemoryHandle handle; // [rsp+38h] [rbp-B0h] BYREF
  char v24[44]; // [rsp+60h] [rbp-88h] BYREF
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
  Illusion::CreateTargetParams v37; // [rsp+F8h] [rbp+10h] BYREF
  Illusion::CreateTargetParams v38; // [rsp+1A8h] [rbp+C0h] BYREF
  Illusion::CreateTargetParams v39; // [rsp+258h] [rbp+170h] BYREF
  __int64 v40; // [rsp+308h] [rbp+220h]

  v40 = -2i64;
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
  for ( i = 0; i < 2; ++i )
  {
    v7 = (params->mFrameMemoryTotalBytes >> 1) & 0x7FFFFF80;
    v8 = (char *)UFG::qMalloc(v7, "FrameMemoryBuffer", 0x8000ui64);
    Render::SetFrameMemory(i, v8, v7);
    Render::SetFrameMemoryOverflow(i, 0i64, 0);
  }
  v9 = (params->mFrameWriteMemoryTotalBytes >> 1) & 0x7FFFFF80;
  Illusion::gFrameWriteMemoryPlat.mBufferSize = v9;
  Illusion::gFrameWriteMemoryPlat.mNumFrameMemoryBuffers = 2;
  UFG::qVRAMemoryHandle::qVRAMemoryHandle(&handle);
  v10 = 0;
  v11 = &Illusion::gFrameWriteMemoryPlat;
  do
  {
    v22 = 0;
    v19 = v9;
    v20 = 0x300000002i64;
    v21 = 0x10000i64;
    ((void (__fastcall *)(ID3D11Device *, int *, _QWORD, Illusion::FrameWriteMemoryPlat *))UFG::gD3D11Device->vfptr->VSSetConstantBuffers)(
      UFG::gD3D11Device,
      &v19,
      0i64,
      v11);
    Illusion::FrameWriteMemoryPlat::Lock(&Illusion::gFrameWriteMemoryPlat, v10);
    Render::SetFrameWriteMemory(
      v10,
      (char *)Illusion::gFrameWriteMemoryPlat.mLockData,
      &handle,
      Illusion::gFrameWriteMemoryPlat.mBufferSize);
    Render::SetFrameWriteMemoryOverflow(v10, 0i64, &handle, 0);
    Illusion::FrameWriteMemoryPlat::Unlock(&Illusion::gFrameWriteMemoryPlat);
    ++v10;
    v11 = (Illusion::FrameWriteMemoryPlat *)((char *)v11 + 8);
  }
  while ( v10 < 2 );
  v12 = (params->mPrimitiveFrameWriteMemoryTotalBytes >> 1) & 0x7FFFFF80;
  Illusion::gPrimitiveFrameWriteMemoryPlat.mBufferSize = v12;
  Illusion::gPrimitiveFrameWriteMemoryPlat.mNumFrameMemoryBuffers = 2;
  v13 = 0;
  v14 = &Illusion::gPrimitiveFrameWriteMemoryPlat;
  do
  {
    v22 = 0;
    v19 = v12;
    v20 = 0x300000002i64;
    v21 = 0x10000i64;
    ((void (__fastcall *)(ID3D11Device *, int *, _QWORD, Illusion::FrameWriteMemoryPlat *))UFG::gD3D11Device->vfptr->VSSetConstantBuffers)(
      UFG::gD3D11Device,
      &v19,
      0i64,
      v14);
    Illusion::FrameWriteMemoryPlat::Lock(&Illusion::gPrimitiveFrameWriteMemoryPlat, v13);
    Render::SetPrimitiveFrameWriteMemory(
      v13,
      (char *)Illusion::gPrimitiveFrameWriteMemoryPlat.mLockData,
      &handle,
      Illusion::gPrimitiveFrameWriteMemoryPlat.mBufferSize);
    Render::SetPrimitiveFrameWriteMemoryOverflow(v13, 0i64, &handle, 0);
    Illusion::FrameWriteMemoryPlat::Unlock(&Illusion::gPrimitiveFrameWriteMemoryPlat);
    ++v13;
    v14 = (Illusion::FrameWriteMemoryPlat *)((char *)v14 + 8);
  }
  while ( v13 < 2 );
  for ( j = 0; j < 2; ++j )
  {
    Render::SetFramePatchMemory(j, 0i64, &handle, 0);
    Render::SetFramePatchMemoryOverflow(j, 0i64, &handle, 0);
  }
  for ( k = 0; k < 2; ++k )
  {
    Render::SetFrameIndexMemory(k, 0i64, &handle, 0);
    Render::SetFrameIndexMemoryOverflow(k, 0i64, &handle, 0);
  }
  Render::SwapFrameMemoryBuffers(v17);
  UFG::qString::qString(&v39.name, "BackBuffer");
  *(_QWORD *)&v39.num_mrt = 1i64;
  v39.depth = 1;
  v39.array_size = 1;
  *(_DWORD *)v39.mrt_formats = -256;
  v39.num_mips = 1;
  memset(v39.textures, 0, 85);
  *(_QWORD *)&v39.width = __PAIR64__(gScreenHeight, gScreenWidth);
  v39.target_flags = 19;
  BackBufferTarget = Illusion::CreateTarget(&v39);
  UFG::qString::qString(&v38.name, "PresentBuffer");
  *(_QWORD *)&v38.num_mrt = 1i64;
  v38.depth = 1;
  v38.array_size = 1;
  *(_DWORD *)v38.mrt_formats = -256;
  v38.num_mips = 1;
  memset(v38.textures, 0, 85);
  *(_QWORD *)&v38.width = __PAIR64__(gScreenHeight, gScreenWidth);
  v38.target_flags = 0x40000;
  PresentBufferTarget = Illusion::CreateTarget(&v38);
  UFG::qString::qString(&v37.name, "LeftEye");
  *(_QWORD *)&v37.num_mrt = 1i64;
  v37.depth = 1;
  v37.array_size = 1;
  *(_DWORD *)v37.mrt_formats = -256;
  v37.num_mips = 1;
  memset(v37.textures, 0, 85);
  *(_QWORD *)&v37.width = __PAIR64__(gScreenHeight, gScreenWidth);
  v37.target_flags = 19;
  LeftEyeTarget = Illusion::CreateTarget(&v37);
  UFG::qString::qString((UFG::qString *)v24, "RightEye");
  *(_QWORD *)&v24[36] = 1i64;
  *(_QWORD *)&v24[24] = 0x100000001i64;
  *(_DWORD *)&v24[32] = -256;
  v26 = 1;
  v27 = 0i64;
  v28 = 0i64;
  v29 = 0i64;
  v30 = 0i64;
  v31 = 0i64;
  v32 = 0i64;
  v33 = 0i64;
  v34 = 0i64;
  v35 = 0;
  v36 = 0;
  *(_DWORD *)&v24[16] = gScreenWidth;
  *(_DWORD *)&v24[20] = gScreenHeight;
  v25 = 19;
  RightEyeTarget = Illusion::CreateTarget((Illusion::CreateTargetParams *)v24);
  Render::InitVertexDeclarations(v18);
  Render::Skinning::Init(&Render::Skinning::gSkinning);
  UFG::qString::~qString((UFG::qString *)v24);
  UFG::qString::~qString(&v37.name);
  UFG::qString::~qString(&v38.name);
  UFG::qString::~qString(&v39.name);
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
  if ( eye == STEREO_EYE_RIGHT )
    return RightEyeTarget;
  return 0i64;
}

// File Line: 2178
// RVA: 0x6A2240
void __fastcall Render::SetVSyncEnable(int newVal)
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
  int v6; // ebx
  float *v7; // rcx
  float v8; // xmm0_4
  float *v9; // rdi
  float v10; // xmm0_4
  char v11[12]; // [rsp+30h] [rbp-40B8h] BYREF
  unsigned int v12; // [rsp+3Ch] [rbp-40ACh]
  __int128 v13; // [rsp+1050h] [rbp-3098h] BYREF
  __int64 v14; // [rsp+1060h] [rbp-3088h]
  char v15[12308]; // [rsp+106Ch] [rbp-307Ch] BYREF
  __int64 v16; // [rsp+40F0h] [rbp+8h] BYREF
  UFG::qMutex *v17; // [rsp+40F8h] [rbp+10h]

  v0 = _S1_30;
  if ( (_S1_30 & 1) != 0 )
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
  if ( (v0 & 2) != 0 )
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
  if ( Render::DisplayCalibration::msBrightness != v2 || g_ForceDisplayCalibrationUpdate || v1 != gEnableGammaControl )
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
        && !(*(unsigned int (__fastcall **)(__int64, char *))(*(_QWORD *)v16 + 104i64))(v16, v11) )
      {
        v13 = _xmm;
        v14 = 0i64;
        v5 = v12;
        if ( v12 >= 2 )
        {
          v6 = 0;
          if ( gEnableGammaControl )
          {
            v9 = (float *)v15;
            do
            {
              v10 = powf((float)v6 * (float)(1.0 / (float)(int)(v5 - 1)), v3) + v4;
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
          else
          {
            v7 = (float *)v15;
            do
            {
              v8 = (float)v6 * (float)(1.0 / (float)(int)(v5 - 1));
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
  unsigned __int64 Ticks; // rax

  Ticks = UFG::qGetTicks();
  RenderDrawQueueCPUTime = UFG::qGetTickTime(Render::RenderToDeviceStartTicks, Ticks);
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
  _BYTE v7[12]; // [rsp+50h] [rbp-28h] BYREF
  int v8; // [rsp+5Ch] [rbp-1Ch]
  int v9; // [rsp+60h] [rbp-18h]
  int v10; // [rsp+64h] [rbp-14h]

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
  v3 = (unsigned int)(int)(float)((float)((float)gOutputParams.m3DConvergence * 0.1) * 32.0);
  v4 = *(_QWORD *)(*(_QWORD *)&BackBufferTarget->mTargetTexture[0][1].mMipMapBias + 136i64);
  v10 = 1;
  if ( (_DWORD)param )
  {
    memset(v7, 0, sizeof(v7));
    v8 = gScreenWidth - v3;
    v9 = gScreenHeight;
    v6 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index);
  }
  else
  {
    v8 = gScreenWidth;
    v9 = gScreenHeight;
    v5 = NtCurrentTeb()->Reserved1[11];
    *(_DWORD *)v7 = (int)(float)((float)((float)gOutputParams.m3DConvergence * 0.1) * 32.0);
    v6 = v5[tls_index];
    *(_QWORD *)&v7[4] = 0i64;
    v3 = 0i64;
  }
  (*(void (__fastcall **)(_QWORD, __int64, _QWORD, __int64, _DWORD, _DWORD, __int64, _DWORD, _BYTE *))(**(_QWORD **)(v6 + 104) + 368i64))(
    *(_QWORD *)(v6 + 104),
    v2,
    0i64,
    v3,
    0,
    0,
    v4,
    0,
    v7);
}

// File Line: 2329
// RVA: 0x6A08A0
void __fastcall Render::PerformFlip(unsigned int syncInterval)
{
  _QWORD *v2; // rax
  __int64 v3; // rcx
  ID3D11DeviceContext **v4; // rbx
  int v5; // ebx
  Render *v6; // rcx
  Render *v7; // rcx
  Render *v8; // rcx

  if ( g_Fullscreen )
  {
    v2 = NtCurrentTeb()->Reserved1[11];
    if ( g_enable3D )
    {
      v4 = (ID3D11DeviceContext **)(v2[tls_index] + 104i64);
      sStereo3D->vfptr->CopyToEye(
        sStereo3D,
        STEREO_EYE_LEFT,
        *v4,
        gPresentBuffer,
        *(ID3D11Resource **)(*(_QWORD *)&LeftEyeTarget->mTargetTexture[0][1].mMipMapBias + 136i64),
        0);
      sStereo3D->vfptr->CopyToEye(
        sStereo3D,
        STEREO_EYE_RIGHT,
        *v4,
        gPresentBuffer,
        *(ID3D11Resource **)(*(_QWORD *)&RightEyeTarget->mTargetTexture[0][1].mMipMapBias + 136i64),
        0);
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
  v5 = ((__int64 (__fastcall *)(IDXGISwapChain *, _QWORD, _QWORD))sDXGISwapChain->vfptr[2].Release)(
         sDXGISwapChain,
         syncInterval,
         0i64);
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&sDXGIMutex);
  if ( ((v5 + 0x7785FFFB) & 0xFFFFFFFD) == 0 )
  {
    UFG::qMutex::Lock((LPCRITICAL_SECTION)&sDXGIMutex);
    Render::ReleaseSwapChain(v6);
    Render::ReleaseD3D(v7);
    Render::InitD3D(v8);
    Render::InitSwapChain(0i64);
    UFG::qMutex::Unlock((LPCRITICAL_SECTION)&sDXGIMutex);
  }
  Illusion::Engine::RenderThreadProcessDeleteQueue(&Illusion::gEngine);
}

// File Line: 2392
// RVA: 0x6A1D20
void __fastcall Render::RenderThreadWindowsMsgProc(bool *quitMsgReceived)
{
  tagMSG Msg; // [rsp+30h] [rbp-38h] BYREF

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
    if ( quitMsgReceived )
      *quitMsgReceived = 1;
  }
  else
  {
LABEL_4:
    if ( quitMsgReceived )
      *quitMsgReceived = 0;
  }
}

// File Line: 2418
// RVA: 0x6A1510
void __fastcall Render::RenderThreadSwapChainEventTriggers(bool *resizeEvent)
{
  Render::RenderCallbacks *RenderCallbacks; // rax
  int Width; // esi
  int Height; // edi
  float v5; // xmm2_4
  bool v6; // al
  int v7; // eax
  char v8; // cl
  Render *v9; // rcx
  Render::RenderCallbacks *v10; // rax
  Render::RenderCallbacks *v11; // rax
  Render::RenderCallbacks *v12; // rax
  Render::RenderCallbacks *v13; // rax
  bool v14; // al
  bool v15; // cl
  char v16; // al
  char v17; // al
  IDXGISwapChain *v18; // rcx
  bool v19; // r8
  _BOOL8 v20; // rdx
  IDXGIOutput *v21; // r8
  tagRECT Rect; // [rsp+30h] [rbp-B8h] BYREF
  UFG::qString v23; // [rsp+40h] [rbp-A8h] BYREF
  int v24; // [rsp+68h] [rbp-80h]
  int v25; // [rsp+6Ch] [rbp-7Ch]
  int v26; // [rsp+70h] [rbp-78h]
  int v27; // [rsp+74h] [rbp-74h]
  __int128 v28; // [rsp+78h] [rbp-70h]
  __int128 v29; // [rsp+88h] [rbp-60h]
  __int64 v30; // [rsp+98h] [rbp-50h]
  __int64 v31; // [rsp+A0h] [rbp-48h]
  __int64 v32; // [rsp+A8h] [rbp-40h]
  __int64 v33; // [rsp+B0h] [rbp-38h]
  __int64 v34; // [rsp+B8h] [rbp-30h]
  __int64 v35; // [rsp+C0h] [rbp-28h]
  int v36; // [rsp+C8h] [rbp-20h]
  char v37; // [rsp+CCh] [rbp-1Ch]
  Illusion::CreateTargetParams v38; // [rsp+D8h] [rbp-10h] BYREF
  Illusion::CreateTargetParams v39; // [rsp+188h] [rbp+A0h] BYREF
  Illusion::CreateTargetParams v40; // [rsp+238h] [rbp+150h] BYREF
  __int64 v41; // [rsp+2E8h] [rbp+200h]
  UFG::qString result; // [rsp+2F0h] [rbp+208h] BYREF
  char v43[56]; // [rsp+318h] [rbp+230h] BYREF
  int v44; // [rsp+350h] [rbp+268h]

  v41 = -2i64;
  if ( resizeEvent )
    *resizeEvent = 0;
  if ( !sbEventResizeBuffers )
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
      RenderCallbacks = Render::GetRenderCallbacks();
      RenderCallbacks->mResizeRenderBuffersFunc();
    }
    sbEventResizeBuffers = 0;
    if ( resizeEvent )
      *resizeEvent = 1;
    goto LABEL_9;
  }
LABEL_10:
  Illusion::IEnginePlat::WaitUntilGPUDone(&Illusion::gEngine);
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&sDXGIMutex);
  if ( !sDXGIMode || sbEventManualWindowSizing )
  {
    GetClientRect(ghWnd, &Rect);
    Width = Rect.right - Rect.left;
    Height = Rect.bottom - Rect.top;
    v5 = (float)(Rect.right - Rect.left);
    if ( (float)(v5 / (float)(Rect.bottom - Rect.top)) > 7.1111112 )
      Height = (int)(float)(v5 * 0.140625);
  }
  else
  {
    Width = sDXGIMode->Width;
    Height = sDXGIMode->Height;
  }
  Render::SetWindow(Width, Height);
  if ( sPresentRenderTargetView )
  {
    sPresentRenderTargetView->vfptr->Release(sPresentRenderTargetView);
    sPresentRenderTargetView = 0i64;
  }
  if ( gPresentBuffer )
  {
    gPresentBuffer->vfptr->Release(gPresentBuffer);
    gPresentBuffer = 0i64;
  }
  Illusion::DeleteTarget((AMD_HD3D *)BackBufferTarget, 1);
  Illusion::DeleteTarget((AMD_HD3D *)PresentBufferTarget, 1);
  Illusion::DeleteTarget((AMD_HD3D *)LeftEyeTarget, 1);
  Illusion::DeleteTarget((AMD_HD3D *)RightEyeTarget, 1);
  gScreenWidth = Width;
  gScreenHeight = Height;
  if ( g_signalNewSwapChain )
  {
    Render::InitSwapChain((Render *)g_Fullscreen);
    g_signalNewSwapChain = 0;
  }
  else
  {
    ((void (__fastcall *)(IDXGISwapChain *, __int64, _QWORD, _QWORD, int, int))sDXGISwapChain->vfptr[4].AddRef)(
      sDXGISwapChain,
      2i64,
      (unsigned int)Width,
      (unsigned int)Height,
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
  ((void (__fastcall *)(IDXGISwapChain *, char *))sDXGISwapChain->vfptr[4].QueryInterface)(sDXGISwapChain, v43);
  v6 = g_Fullscreen;
  if ( g_Fullscreen == g_PrevFullscreen )
  {
    v6 = v44 == 0;
    g_Fullscreen = v44 == 0;
    gOutputParams.mEnableFullscreen = v44 == 0;
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
  gDisplayAspectRatio = (float)Width / (float)Height;
  Render::UpdateUIViewportScalesBasedOnAspectRatio(v9);
  UFG::qString::qString(&v23, "BackBuffer");
  v27 = 1;
  v26 = 1;
  v28 = 0i64;
  v29 = 0i64;
  v30 = 0i64;
  v31 = 0i64;
  v32 = 0i64;
  v33 = 0i64;
  v34 = 0i64;
  v35 = 0i64;
  v36 = 0;
  v37 = 0;
  v24 = gScreenWidth;
  LOBYTE(v28) = 0;
  v25 = 19;
  BackBufferTarget = Illusion::CreateTarget((Illusion::CreateTargetParams *)&v23);
  UFG::qString::qString(&v39.name, "PresentBuffer");
  *(_QWORD *)&v39.num_mrt = 1i64;
  v39.depth = 1;
  v39.array_size = 1;
  *(_DWORD *)v39.mrt_formats = -256;
  v39.num_mips = 1;
  memset(v39.textures, 0, 85);
  *(_QWORD *)&v39.width = __PAIR64__(gScreenHeight, gScreenWidth);
  v39.target_flags = 0x40000;
  PresentBufferTarget = Illusion::CreateTarget(&v39);
  UFG::qString::qString(&v40.name, "LeftEye");
  *(_QWORD *)&v40.num_mrt = 1i64;
  v40.depth = 1;
  v40.array_size = 1;
  *(_DWORD *)v40.mrt_formats = -256;
  v40.num_mips = 1;
  memset(v40.textures, 0, 85);
  *(_QWORD *)&v40.width = __PAIR64__(gScreenHeight, gScreenWidth);
  v40.target_flags = 19;
  LeftEyeTarget = Illusion::CreateTarget(&v40);
  UFG::qString::qString(&v38.name, "RightEye");
  *(_QWORD *)&v38.num_mrt = 1i64;
  v38.depth = 1;
  v38.array_size = 1;
  *(_DWORD *)v38.mrt_formats = -256;
  v38.num_mips = 1;
  memset(v38.textures, 0, 85);
  *(_QWORD *)&v38.width = __PAIR64__(gScreenHeight, gScreenWidth);
  v38.target_flags = 19;
  RightEyeTarget = Illusion::CreateTarget(&v38);
  if ( Render::GetRenderCallbacks()->mResizeRenderBuffersFunc )
  {
    v10 = Render::GetRenderCallbacks();
    v10->mResizeRenderBuffersFunc();
  }
  sbEventResizeBuffers = 0;
  sbEventResizeSwapChain = 0;
  sbEventManualWindowSizing = 0;
  if ( resizeEvent )
    *resizeEvent = 1;
  UFG::qString::~qString(&v38.name);
  UFG::qString::~qString(&v40.name);
  UFG::qString::~qString(&v39.name);
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
    if ( resizeEvent )
      *resizeEvent = 1;
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
  v14 = sStereo3D->vfptr->Stereo3DAvailable(sStereo3D);
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
      sStereo3D->vfptr->Enable(sStereo3D);
    else
      sStereo3D->vfptr->Disable(sStereo3D);
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
_BOOL8 __fastcall Render::RenderFrame(float ftime)
{
  Render *v1; // rcx
  __int32 v2; // esi
  unsigned int v3; // ebx
  char *v4; // rax
  Render *v5; // rcx
  Render *v6; // rcx
  char *v7; // rax
  char *v8; // r8
  __int64 v9; // rcx
  Illusion *v10; // rcx
  Illusion *v11; // rcx
  Render::RenderCallbacks *RenderCallbacks; // rax
  bool v13; // bp
  __int64 v14; // rdi
  __int64 v15; // rbx
  unsigned __int64 Ticks; // rax
  Render *v17; // rcx
  Illusion *v18; // rcx
  UFG::qList<Illusion::RenderPhase,Illusion::RenderPhase,1,0> *RenderPhasesForNextFrame; // rax
  unsigned __int32 v20; // ebx
  unsigned __int64 v21; // rax
  float i; // xmm0_4
  unsigned __int64 v23; // rax
  char v25; // [rsp+98h] [rbp+10h] BYREF
  char data0; // [rsp+A0h] [rbp+18h] BYREF
  char *v27; // [rsp+A8h] [rbp+20h]

  Render::CommitPendingCommandBuilders(v1);
  UFG::qTaskManager::Sync(&UFG::gTaskManager);
  v2 = 0;
  v3 = Render::g_DefragMovesUsedCount;
  if ( Render::g_DefragMovesUsedCount > 0 && Render::g_DefragMovesFinishedCount == Render::g_DefragMovesUsedCount )
  {
    if ( Render::g_DoDefragPrints )
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
    Render::RenderWorldEye(ftime, STEREO_EYE_LEFT);
    Render::RenderWorldEye(ftime, STEREO_EYE_RIGHT);
  }
  else
  {
    gCurrentEye = STEREO_EYE_LEFT;
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
    RenderCallbacks = Render::GetRenderCallbacks();
    Illusion::AddRenderThreadCommand(RTCMD_CALLBACK, RenderCallbacks->mRenderThreadSyncPointFunc, &v25, 0i64);
  }
  Illusion::WaitForRenderThread(v11);
  v13 = data0 == 0;
  v14 = (LOBYTE(Illusion::gEngine.mFrameCount) + 1) & 3;
  v15 = Illusion::gEngine.mFrameCount & 3;
  Ticks = UFG::qGetTicks();
  Render::gFrameTimes[v15].mCPUTimeMs = UFG::qGetTickTime(Render::gFrameTimes[v15].mCPUStartTime, Ticks) * 1000.0;
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
    RenderPhasesForNextFrame = Illusion::RenderQueuePlat::GetRenderPhasesForNextFrame();
    Illusion::AddRenderThreadCommand(RTCMD_SUBMIT, RenderPhasesForNextFrame, 0i64, 0i64);
    v20 = gOutputParams.mFPSLimiter % 5;
    LOBYTE(v2) = gOutputParams.mEnableVSync;
    if ( v2 > gOutputParams.mFPSLimiter % 5 )
      v20 = v2;
    if ( gGovernMaxFrameRate && !v20 )
    {
      if ( (_S2_11 & 1) == 0 )
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
  void *CurrentThreadID; // rbx
  Illusion *v5; // rcx

  Illusion::BufferD3DResourceInventory::ProcessQueuedLoads(&Illusion::gBufferD3DResourceInventory, bBlocking);
  Illusion::TextureD3DResourceInventory::ProcessQueuedLoads(&Illusion::gTextureD3DResourceInventory, bBlocking);
  if ( bProcessUnloads )
  {
    CurrentThreadID = UFG::qGetCurrentThreadID();
    if ( CurrentThreadID == (void *)UFG::qGetMainThreadID() )
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
  __int64 param; // [rsp+30h] [rbp+8h] BYREF

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
  `eh vector constructor iterator(
    (char *)Render::g_DefragMoves,
    0x40ui64,
    25,
    (void (__fastcall *)(void *))UFG::qVRAMemoryMoveOrder::qVRAMemoryMoveOrder);
  return atexit((int (__fastcall *)())Render::_dynamic_atexit_destructor_for__g_DefragMoves__);
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
  int DefragmentMoves; // eax
  int v2; // ebp
  char **p_mData; // rbx
  char *v4; // rsi
  char *v5; // rdi
  unsigned int AllocatedSize; // eax
  __int64 v7; // [rsp+20h] [rbp-18h]
  __int64 v8; // [rsp+28h] [rbp-10h]

  if ( !Render::g_DefragMovesUsedCount && Render::g_EnableVRAMDefragmentation )
  {
    DefragmentMoves = UFG::qVRAMemoryPools::GetDefragmentMoves(
                        Render::g_DefragMoves,
                        Render::g_DefragTotalMovesPerFrame,
                        Render::g_DefragTotalBytesPerFrame);
    Render::g_DefragMovesUsedCount = DefragmentMoves;
    if ( Render::g_DoDefragPrints )
    {
      v2 = Render::g_DefragMovesFinishedCount;
      if ( Render::g_DefragMovesFinishedCount < DefragmentMoves )
      {
        p_mData = &Render::g_DefragMoves[(__int64)Render::g_DefragMovesFinishedCount].mTargetHandle.mData;
        do
        {
          v4 = p_mData[4];
          v5 = *p_mData;
          AllocatedSize = UFG::qVRAMemoryHandle::GetAllocatedSize(&Render::g_DefragMoves[(__int64)v2].mSourceHandle);
          LODWORD(v8) = Illusion::gEngine.mFrameCount;
          LODWORD(v7) = AllocatedSize;
          UFG::qPrintf(
            " - Scheduling defrag from 0x%08x to 0x%08x of %8d(0x%08x) bytes, frame[%d]\n",
            v4,
            v5,
            AllocatedSize,
            v7,
            v8);
          ++v2;
          p_mData += 8;
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
  char **p_mData; // r14
  unsigned int v4; // eax
  char *v5; // rbp
  char *v6; // r15
  unsigned int AllocatedSize; // eax
  unsigned int v8; // r12d
  unsigned int v9; // r13d
  unsigned int v10; // ebx
  __int64 v11; // [rsp+20h] [rbp-38h]
  __int64 v12; // [rsp+28h] [rbp-30h]

  v1 = Render::g_DefragMovesFinishedCount;
  if ( Render::g_DefragMovesFinishedCount < Render::g_DefragMovesUsedCount )
  {
    v2 = 0;
    if ( Render::g_DefragMovesFinishedCount < Render::g_DefragMovesUsedCount )
    {
      p_mData = &Render::g_DefragMoves[(__int64)Render::g_DefragMovesFinishedCount].mTargetHandle.mData;
      v4 = Render::g_DefragCurrentMoveProgress;
      do
      {
        if ( v2 >= Render::g_DefragTotalBytesPerFrame )
          break;
        v5 = &p_mData[4][v4];
        v6 = &(*p_mData)[v4];
        AllocatedSize = UFG::qVRAMemoryHandle::GetAllocatedSize(&Render::g_DefragMoves[(__int64)v1].mSourceHandle);
        v8 = AllocatedSize - Render::g_DefragCurrentMoveProgress;
        v9 = AllocatedSize - Render::g_DefragCurrentMoveProgress + v2;
        if ( v9 <= Render::g_DefragTotalBytesPerFrame )
        {
          if ( Render::g_DoDefragPrints )
          {
            LODWORD(v12) = Illusion::gEngine.mFrameCount;
            LODWORD(v11) = AllocatedSize - Render::g_DefragCurrentMoveProgress;
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
          if ( Render::g_DoDefragPrints )
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
        p_mData += 8;
        Render::g_DefragCurrentMoveProgress = v4;
      }
      while ( v1 < Render::g_DefragMovesUsedCount );
    }
  }
}

// File Line: 3313
// RVA: 0x69F6D0
void __fastcall Render::FastMemMove(char *dest, char *source, unsigned int countBytes)
{
  __int64 v3; // r8
  unsigned int v5; // r9d
  char *v6; // r11
  char *v7; // rdx
  char *i; // rcx
  __int64 v9; // rax
  char *v10; // rcx
  signed __int64 v11; // rdx
  __int64 v12; // rax

  v3 = countBytes >> 3;
  v5 = (unsigned int)v3 >> 4;
  if ( dest <= source || (v6 = &source[8 * v3], dest >= v6) )
  {
    if ( v5 )
    {
      v10 = dest + 16;
      v11 = source - dest;
      do
      {
        v12 = *(_QWORD *)&v10[v11 - 16];
        v10 += 128;
        *((_QWORD *)v10 - 18) = v12;
        *((_QWORD *)v10 - 17) = *(_QWORD *)&v10[v11 - 136];
        *((_QWORD *)v10 - 16) = *(_QWORD *)&v10[v11 - 128];
        *((_QWORD *)v10 - 15) = *(_QWORD *)&v10[v11 - 120];
        *((_QWORD *)v10 - 14) = *(_QWORD *)&v10[v11 - 112];
        *((_QWORD *)v10 - 13) = *(_QWORD *)&v10[v11 - 104];
        *((_QWORD *)v10 - 12) = *(_QWORD *)&v10[v11 - 96];
        *((_QWORD *)v10 - 11) = *(_QWORD *)&v10[v11 - 88];
        *((_QWORD *)v10 - 10) = *(_QWORD *)&v10[v11 - 80];
        *((_QWORD *)v10 - 9) = *(_QWORD *)&v10[v11 - 72];
        *((_QWORD *)v10 - 8) = *(_QWORD *)&v10[v11 - 64];
        *((_QWORD *)v10 - 7) = *(_QWORD *)&v10[v11 - 56];
        *((_QWORD *)v10 - 6) = *(_QWORD *)&v10[v11 - 48];
        *((_QWORD *)v10 - 5) = *(_QWORD *)&v10[v11 - 40];
        *((_QWORD *)v10 - 4) = *(_QWORD *)&v10[v11 - 32];
        *((_QWORD *)v10 - 3) = *(_QWORD *)&v10[v11 - 24];
        --v5;
      }
      while ( v5 );
    }
  }
  else
  {
    v7 = v6 - 8;
    for ( i = &dest[8 * v3 - 8]; (_DWORD)v3; LODWORD(v3) = v3 - 1 )
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
__int64 __fastcall CloseRenderEngine()
{
  Illusion *v0; // rcx

  Illusion::AddRenderThreadCommand(RTCMD_CALLBACK, CloseEngineCB, 0i64, 0i64);
  Illusion::WaitForRenderThread(v0);
  return 1i64;
}

