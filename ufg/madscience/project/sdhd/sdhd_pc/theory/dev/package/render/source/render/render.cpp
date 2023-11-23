// File Line: 39
// RVA: 0x1452C00
__int64 dynamic_initializer_for__UFG::qReflectObjectType_Render::rLight_UFG::qReflectObject_::sInventory__()
{
  unsigned __int64 v0; // rax
  UFG::qReflectWarehouse *v1; // rax

  v0 = UFG::qStringHash64("Render::rLight", 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectInventoryBase::qReflectInventoryBase(
    &UFG::qReflectObjectType<Render::rLight,UFG::qReflectObject>::sInventory,
    "Render::rLight",
    v0);
  UFG::qReflectObjectType<Render::rLight,UFG::qReflectObject>::sInventory.vfptr = (UFG::qReflectInventoryBaseVtbl *)&UFG::qReflectInventory<Render::rLight>::`vftable;
  UFG::qReflectInventory<Render::rLight>::OnAddToWarehouse(&UFG::qReflectObjectType<Render::rLight,UFG::qReflectObject>::sInventory);
  v1 = UFG::qReflectWarehouse::Instance();
  UFG::qReflectWarehouse::Add(v1, &UFG::qReflectObjectType<Render::rLight,UFG::qReflectObject>::sInventory);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::qReflectObjectType_Render::rLight_UFG::qReflectObject_::sInventory__);
}

// File Line: 66
// RVA: 0x1452FC0
void Render::_dynamic_initializer_for__gRenderCallbacks__()
{
  UFG::qMemSet(&Render::gRenderCallbacks, 0, 0x68u);
}

// File Line: 88
// RVA: 0xB140
void __fastcall Render::RenderOutputParams::RenderOutputParams(Render::RenderOutputParams *this)
{
  Render::RenderOutputParams::SetDefault(this);
}

// File Line: 94
// RVA: 0xBB40
void __fastcall Render::RenderOutputParams::SetDefault(Render::RenderOutputParams *this)
{
  UFG::qMemSet(this, 0, 0x68u);
  this->mEnableFullscreen = 1;
  this->mAAQuality = AA_QUALITY_NORMAL;
  this->mSSAO = SSAO_NORMAL;
  this->mEnableVSync = 1;
  this->m3DConvergence = 10;
  this->m3DDepth = 1;
  this->mInterAxialDistance = 0.029999999;
  this->mTimeStepSmoothingFrames = 5;
  this->mShadowRes = SHADOW_RES_NORMAL;
  this->mShadowFilter = SHADOW_FILTER_HIGH;
  this->mMotionBlur = MOTION_BLUR_NORMAL;
  this->mLODSetting = LOD_SETTING_HIGH;
  this->mGlobalSetting = GRAPHICS_NORMAL;
  this->mTextureFilterQuality = ANISOTROPICQUALITY_4;
  this->mTextureDetailLevel = TEXTURE_DETAIL_MEDIUM;
  this->mEnableCloudVolumes = 1;
}

// File Line: 119
// RVA: 0xB1E0
void __fastcall Render::RenderOutputParams::ChangeGlobalSetting(
        Render::RenderOutputParams *this,
        Render::eGlobalSetting globalSetting)
{
  int v2; // edx
  int v3; // edx
  int v4; // edx

  this->mGlobalSetting = globalSetting;
  v2 = globalSetting - 1;
  if ( v2 )
  {
    v3 = v2 - 1;
    if ( v3 )
    {
      v4 = v3 - 1;
      if ( v4 )
      {
        if ( v4 == 1 )
        {
          this->mAAQuality = AA_QUALITY_EXTREME;
          this->mShadowRes = SHADOW_RES_HIGH;
          this->mShadowFilter = SHADOW_FILTER_HIGH;
          this->mMotionBlur = MOTION_BLUR_HIGH;
          this->mSSAO = SSAO_HIGH;
          this->mLODSetting = LOD_SETTING_EXTREME;
          this->mGlobalSetting = GRAPHICS_EXTREME;
          this->mTextureFilterQuality = ANISOTROPICQUALITY_16;
          this->mTextureDetailLevel = TEXTURE_DETAIL_HIGH;
          this->mEnableCloudVolumes = 1;
        }
      }
      else
      {
        this->mAAQuality = AA_QUALITY_HIGH;
        this->mShadowRes = SHADOW_RES_HIGH;
        this->mShadowFilter = SHADOW_FILTER_HIGH;
        this->mMotionBlur = MOTION_BLUR_NORMAL;
        this->mSSAO = SSAO_HIGH;
        this->mLODSetting = LOD_SETTING_HIGH;
        this->mGlobalSetting = GRAPHICS_HIGH;
        this->mTextureFilterQuality = ANISOTROPICQUALITY_8;
        this->mTextureDetailLevel = TEXTURE_DETAIL_HIGH;
        this->mEnableCloudVolumes = 1;
      }
    }
    else
    {
      this->mShadowRes = SHADOW_RES_NORMAL;
      this->mShadowFilter = SHADOW_FILTER_HIGH;
      this->mMotionBlur = MOTION_BLUR_NORMAL;
      this->mLODSetting = LOD_SETTING_HIGH;
      this->mGlobalSetting = GRAPHICS_NORMAL;
      this->mAAQuality = AA_QUALITY_NORMAL;
      this->mSSAO = SSAO_NORMAL;
      this->mTextureFilterQuality = ANISOTROPICQUALITY_4;
      this->mTextureDetailLevel = TEXTURE_DETAIL_MEDIUM;
      this->mEnableCloudVolumes = 1;
    }
  }
  else
  {
    this->mGlobalSetting = GRAPHICS_LOW;
    *(_QWORD *)&this->mAAQuality = 0i64;
    *(_QWORD *)&this->mShadowFilter = 0i64;
    this->mLODSetting = LOD_SETTING_LOW;
    *(_QWORD *)&this->mTextureFilterQuality = 0i64;
    this->mEnableCloudVolumes = 0;
    this->mSSAO = SSAO_NORMAL;
  }
}

// File Line: 203
// RVA: 0xB100
void __fastcall Render::RenderInitParams::RenderInitParams(Render::RenderInitParams *this)
{
  Render::RenderOutputParams::SetDefault(&this->mRenderOutputParams);
  *(_QWORD *)&this->mFrameMemoryTotalBytes = 0x100000i64;
  *(_QWORD *)&this->mPrimitiveFrameWriteMemoryTotalBytes = 0i64;
  this->mFrameIndexMemoryTotalBytes = 0;
  this->mTitleName = "Theory [PC64-Ship]";
}

// File Line: 224
// RVA: 0xB0E0
void __fastcall Render::RenderCallbacks::RenderCallbacks(Render::RenderCallbacks *this)
{
  UFG::qMemSet(this, 0, 0x68u);
}

// File Line: 229
// RVA: 0xBF10
void __fastcall Render::SetRenderCallbacks(Render::RenderCallbacks *render_callbacks)
{
  Render::gRenderCallbacks = *render_callbacks;
}

// File Line: 234
// RVA: 0xB420
Render::RenderCallbacks *__fastcall Render::GetRenderCallbacks()
{
  return &Render::gRenderCallbacks;
}

// File Line: 247
// RVA: 0x1452FE0
__int64 Render::Timers::_dynamic_initializer_for__mCpuTimer_RenderSync__()
{
  Render::Timers::mCpuTimer_RenderSync.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedCpuNode>::mPrev = &Render::Timers::mCpuTimer_RenderSync.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedCpuNode>;
  Render::Timers::mCpuTimer_RenderSync.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedCpuNode>::mNext = &Render::Timers::mCpuTimer_RenderSync.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedCpuNode>;
  Render::Timers::mCpuTimer_RenderSync.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveCpuNode>::mPrev = &Render::Timers::mCpuTimer_RenderSync.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveCpuNode>;
  Render::Timers::mCpuTimer_RenderSync.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveCpuNode>::mNext = &Render::Timers::mCpuTimer_RenderSync.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveCpuNode>;
  Render::Timers::mCpuTimer_RenderSync.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedGpuNode>::mPrev = &Render::Timers::mCpuTimer_RenderSync.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedGpuNode>;
  Render::Timers::mCpuTimer_RenderSync.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedGpuNode>::mNext = &Render::Timers::mCpuTimer_RenderSync.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedGpuNode>;
  Render::Timers::mCpuTimer_RenderSync.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveGpuNode>::mPrev = &Render::Timers::mCpuTimer_RenderSync.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveGpuNode>;
  Render::Timers::mCpuTimer_RenderSync.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveGpuNode>::mNext = &Render::Timers::mCpuTimer_RenderSync.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveGpuNode>;
  return atexit((int (__fastcall *)())Render::Timers::_dynamic_atexit_destructor_for__mCpuTimer_RenderSync__);
}

// File Line: 248
// RVA: 0x14531E0
__int64 Render::Timers::_dynamic_initializer_for__mCpuTimer_WaitForGpu__()
{
  Render::Timers::mCpuTimer_WaitForGpu.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedCpuNode>::mPrev = &Render::Timers::mCpuTimer_WaitForGpu.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedCpuNode>;
  Render::Timers::mCpuTimer_WaitForGpu.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedCpuNode>::mNext = &Render::Timers::mCpuTimer_WaitForGpu.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedCpuNode>;
  Render::Timers::mCpuTimer_WaitForGpu.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveCpuNode>::mPrev = &Render::Timers::mCpuTimer_WaitForGpu.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveCpuNode>;
  Render::Timers::mCpuTimer_WaitForGpu.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveCpuNode>::mNext = &Render::Timers::mCpuTimer_WaitForGpu.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveCpuNode>;
  Render::Timers::mCpuTimer_WaitForGpu.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedGpuNode>::mPrev = &Render::Timers::mCpuTimer_WaitForGpu.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedGpuNode>;
  Render::Timers::mCpuTimer_WaitForGpu.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedGpuNode>::mNext = &Render::Timers::mCpuTimer_WaitForGpu.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedGpuNode>;
  Render::Timers::mCpuTimer_WaitForGpu.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveGpuNode>::mPrev = &Render::Timers::mCpuTimer_WaitForGpu.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveGpuNode>;
  Render::Timers::mCpuTimer_WaitForGpu.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveGpuNode>::mNext = &Render::Timers::mCpuTimer_WaitForGpu.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveGpuNode>;
  return atexit((int (__fastcall *)())Render::Timers::_dynamic_atexit_destructor_for__mCpuTimer_WaitForGpu__);
}

// File Line: 249
// RVA: 0x14530E0
__int64 Render::Timers::_dynamic_initializer_for__mCpuTimer_RenderWorld__()
{
  Render::Timers::mCpuTimer_RenderWorld.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedCpuNode>::mPrev = &Render::Timers::mCpuTimer_RenderWorld.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedCpuNode>;
  Render::Timers::mCpuTimer_RenderWorld.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedCpuNode>::mNext = &Render::Timers::mCpuTimer_RenderWorld.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedCpuNode>;
  Render::Timers::mCpuTimer_RenderWorld.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveCpuNode>::mPrev = &Render::Timers::mCpuTimer_RenderWorld.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveCpuNode>;
  Render::Timers::mCpuTimer_RenderWorld.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveCpuNode>::mNext = &Render::Timers::mCpuTimer_RenderWorld.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveCpuNode>;
  Render::Timers::mCpuTimer_RenderWorld.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedGpuNode>::mPrev = &Render::Timers::mCpuTimer_RenderWorld.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedGpuNode>;
  Render::Timers::mCpuTimer_RenderWorld.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedGpuNode>::mNext = &Render::Timers::mCpuTimer_RenderWorld.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedGpuNode>;
  Render::Timers::mCpuTimer_RenderWorld.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveGpuNode>::mPrev = &Render::Timers::mCpuTimer_RenderWorld.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveGpuNode>;
  Render::Timers::mCpuTimer_RenderWorld.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveGpuNode>::mNext = &Render::Timers::mCpuTimer_RenderWorld.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveGpuNode>;
  return atexit((int (__fastcall *)())Render::Timers::_dynamic_atexit_destructor_for__mCpuTimer_RenderWorld__);
}

// File Line: 250
// RVA: 0x1453060
__int64 Render::Timers::_dynamic_initializer_for__mCpuTimer_RenderThread__()
{
  Render::Timers::mCpuTimer_RenderThread.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedCpuNode>::mPrev = &Render::Timers::mCpuTimer_RenderThread.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedCpuNode>;
  Render::Timers::mCpuTimer_RenderThread.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedCpuNode>::mNext = &Render::Timers::mCpuTimer_RenderThread.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedCpuNode>;
  Render::Timers::mCpuTimer_RenderThread.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveCpuNode>::mPrev = &Render::Timers::mCpuTimer_RenderThread.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveCpuNode>;
  Render::Timers::mCpuTimer_RenderThread.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveCpuNode>::mNext = &Render::Timers::mCpuTimer_RenderThread.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveCpuNode>;
  Render::Timers::mCpuTimer_RenderThread.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedGpuNode>::mPrev = &Render::Timers::mCpuTimer_RenderThread.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedGpuNode>;
  Render::Timers::mCpuTimer_RenderThread.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedGpuNode>::mNext = &Render::Timers::mCpuTimer_RenderThread.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedGpuNode>;
  Render::Timers::mCpuTimer_RenderThread.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveGpuNode>::mPrev = &Render::Timers::mCpuTimer_RenderThread.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveGpuNode>;
  Render::Timers::mCpuTimer_RenderThread.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveGpuNode>::mNext = &Render::Timers::mCpuTimer_RenderThread.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveGpuNode>;
  return atexit((int (__fastcall *)())Render::Timers::_dynamic_atexit_destructor_for__mCpuTimer_RenderThread__);
}

// File Line: 251
// RVA: 0x1453160
__int64 Render::Timers::_dynamic_initializer_for__mCpuTimer_UpdateWorld__()
{
  Render::Timers::mCpuTimer_UpdateWorld.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedCpuNode>::mPrev = &Render::Timers::mCpuTimer_UpdateWorld.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedCpuNode>;
  Render::Timers::mCpuTimer_UpdateWorld.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedCpuNode>::mNext = &Render::Timers::mCpuTimer_UpdateWorld.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedCpuNode>;
  Render::Timers::mCpuTimer_UpdateWorld.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveCpuNode>::mPrev = &Render::Timers::mCpuTimer_UpdateWorld.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveCpuNode>;
  Render::Timers::mCpuTimer_UpdateWorld.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveCpuNode>::mNext = &Render::Timers::mCpuTimer_UpdateWorld.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveCpuNode>;
  Render::Timers::mCpuTimer_UpdateWorld.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedGpuNode>::mPrev = &Render::Timers::mCpuTimer_UpdateWorld.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedGpuNode>;
  Render::Timers::mCpuTimer_UpdateWorld.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedGpuNode>::mNext = &Render::Timers::mCpuTimer_UpdateWorld.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedGpuNode>;
  Render::Timers::mCpuTimer_UpdateWorld.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveGpuNode>::mPrev = &Render::Timers::mCpuTimer_UpdateWorld.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveGpuNode>;
  Render::Timers::mCpuTimer_UpdateWorld.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveGpuNode>::mNext = &Render::Timers::mCpuTimer_UpdateWorld.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveGpuNode>;
  return atexit((int (__fastcall *)())Render::Timers::_dynamic_atexit_destructor_for__mCpuTimer_UpdateWorld__);
}

// File Line: 492
// RVA: 0x1452D40
__int64 Render::_dynamic_initializer_for__FrameMemoryAllocators__()
{
  `eh vector constructor iterator(
    (char *)Render::FrameMemoryAllocators,
    0x80ui64,
    4,
    (void (__fastcall *)(void *))UFG::qLinearAllocator::qLinearAllocator);
  return atexit((int (__fastcall *)())Render::_dynamic_atexit_destructor_for__FrameMemoryAllocators__);
}

// File Line: 498
// RVA: 0x1452E40
__int64 Render::_dynamic_initializer_for__FrameWriteMemoryAllocators__()
{
  `eh vector constructor iterator(
    (char *)Render::FrameWriteMemoryAllocators,
    0x80ui64,
    4,
    (void (__fastcall *)(void *))UFG::qLinearAllocator::qLinearAllocator);
  return atexit((int (__fastcall *)())Render::_dynamic_atexit_destructor_for__FrameWriteMemoryAllocators__);
}

// File Line: 500
// RVA: 0x1452E80
__int64 Render::_dynamic_initializer_for__FrameWriteMemoryHandle__()
{
  `eh vector constructor iterator(
    (char *)Render::FrameWriteMemoryHandle,
    0x20ui64,
    4,
    (void (__fastcall *)(void *))UFG::qVRAMemoryHandle::qVRAMemoryHandle);
  return atexit((int (__fastcall *)())Render::_dynamic_atexit_destructor_for__FrameWriteMemoryHandle__);
}

// File Line: 503
// RVA: 0x1452EC0
__int64 Render::_dynamic_initializer_for__FrameWriteMemoryHandleOverflow__()
{
  `eh vector constructor iterator(
    (char *)Render::FrameWriteMemoryHandleOverflow,
    0x20ui64,
    4,
    (void (__fastcall *)(void *))UFG::qVRAMemoryHandle::qVRAMemoryHandle);
  return atexit((int (__fastcall *)())Render::_dynamic_atexit_destructor_for__FrameWriteMemoryHandleOverflow__);
}

// File Line: 506
// RVA: 0x1452F00
__int64 Render::_dynamic_initializer_for__PrimitiveFrameWriteMemoryAllocators__()
{
  `eh vector constructor iterator(
    (char *)Render::PrimitiveFrameWriteMemoryAllocators,
    0x80ui64,
    4,
    (void (__fastcall *)(void *))UFG::qLinearAllocator::qLinearAllocator);
  return atexit((int (__fastcall *)())Render::_dynamic_atexit_destructor_for__PrimitiveFrameWriteMemoryAllocators__);
}

// File Line: 508
// RVA: 0x1452F40
__int64 Render::_dynamic_initializer_for__PrimitiveFrameWriteMemoryHandle__()
{
  `eh vector constructor iterator(
    (char *)Render::PrimitiveFrameWriteMemoryHandle,
    0x20ui64,
    4,
    (void (__fastcall *)(void *))UFG::qVRAMemoryHandle::qVRAMemoryHandle);
  return atexit((int (__fastcall *)())Render::_dynamic_atexit_destructor_for__PrimitiveFrameWriteMemoryHandle__);
}

// File Line: 511
// RVA: 0x1452F80
__int64 Render::_dynamic_initializer_for__PrimitiveFrameWriteMemoryHandleOverflow__()
{
  `eh vector constructor iterator(
    (char *)Render::PrimitiveFrameWriteMemoryHandleOverflow,
    0x20ui64,
    4,
    (void (__fastcall *)(void *))UFG::qVRAMemoryHandle::qVRAMemoryHandle);
  return atexit((int (__fastcall *)())Render::_dynamic_atexit_destructor_for__PrimitiveFrameWriteMemoryHandleOverflow__);
}

// File Line: 514
// RVA: 0x1452D80
__int64 Render::_dynamic_initializer_for__FramePatchMemoryAllocators__()
{
  `eh vector constructor iterator(
    (char *)Render::FramePatchMemoryAllocators,
    0x80ui64,
    4,
    (void (__fastcall *)(void *))UFG::qLinearAllocator::qLinearAllocator);
  return atexit((int (__fastcall *)())Render::_dynamic_atexit_destructor_for__FramePatchMemoryAllocators__);
}

// File Line: 516
// RVA: 0x1452DC0
__int64 Render::_dynamic_initializer_for__FramePatchMemoryHandle__()
{
  `eh vector constructor iterator(
    (char *)Render::FramePatchMemoryHandle,
    0x20ui64,
    4,
    (void (__fastcall *)(void *))UFG::qVRAMemoryHandle::qVRAMemoryHandle);
  return atexit((int (__fastcall *)())Render::_dynamic_atexit_destructor_for__FramePatchMemoryHandle__);
}

// File Line: 519
// RVA: 0x1452E00
__int64 Render::_dynamic_initializer_for__FramePatchMemoryHandleOverflow__()
{
  `eh vector constructor iterator(
    (char *)Render::FramePatchMemoryHandleOverflow,
    0x20ui64,
    4,
    (void (__fastcall *)(void *))UFG::qVRAMemoryHandle::qVRAMemoryHandle);
  return atexit((int (__fastcall *)())Render::_dynamic_atexit_destructor_for__FramePatchMemoryHandleOverflow__);
}

// File Line: 522
// RVA: 0x1452C80
__int64 Render::_dynamic_initializer_for__FrameIndexMemoryAllocators__()
{
  `eh vector constructor iterator(
    (char *)Render::FrameIndexMemoryAllocators,
    0x80ui64,
    4,
    (void (__fastcall *)(void *))UFG::qLinearAllocator::qLinearAllocator);
  return atexit((int (__fastcall *)())Render::_dynamic_atexit_destructor_for__FrameIndexMemoryAllocators__);
}

// File Line: 524
// RVA: 0x1452CC0
__int64 Render::_dynamic_initializer_for__FrameIndexMemoryHandle__()
{
  `eh vector constructor iterator(
    (char *)Render::FrameIndexMemoryHandle,
    0x20ui64,
    4,
    (void (__fastcall *)(void *))UFG::qVRAMemoryHandle::qVRAMemoryHandle);
  return atexit((int (__fastcall *)())Render::_dynamic_atexit_destructor_for__FrameIndexMemoryHandle__);
}

// File Line: 527
// RVA: 0x1452D00
__int64 Render::_dynamic_initializer_for__FrameIndexMemoryHandleOverflow__()
{
  `eh vector constructor iterator(
    (char *)Render::FrameIndexMemoryHandleOverflow,
    0x20ui64,
    4,
    (void (__fastcall *)(void *))UFG::qVRAMemoryHandle::qVRAMemoryHandle);
  return atexit((int (__fastcall *)())Render::_dynamic_atexit_destructor_for__FrameIndexMemoryHandleOverflow__);
}

// File Line: 532
// RVA: 0xBCA0
void __fastcall Render::SetFrameMemoryNumBuffers(unsigned int num_frame_memory_buffers)
{
  Render::FrameMemoryNumBuffers = num_frame_memory_buffers;
}

// File Line: 538
// RVA: 0xBC80
void __fastcall Render::SetFrameMemory(unsigned int index, char *memory, unsigned int size)
{
  Render::FrameMemoryBuffer[index] = memory;
  Render::FrameMemoryBufferSize[index] = size;
}

// File Line: 539
// RVA: 0xBCB0
void __fastcall Render::SetFrameMemoryOverflow(unsigned int index, char *memory, unsigned int size)
{
  Render::FrameMemoryBufferOverflow[index] = memory;
  Render::FrameMemoryBufferOverflowSize[index] = size;
}

// File Line: 541
// RVA: 0xBD90
void __fastcall Render::SetFrameWriteMemory(
        unsigned int index,
        char *memory,
        UFG::qVRAMemoryHandle *handle,
        unsigned int size)
{
  __int64 v4; // rbx

  v4 = index;
  Render::FrameWriteMemoryBuffer[index] = memory;
  UFG::qVRAMemoryHandle::operator=(&Render::FrameWriteMemoryHandle[index], handle);
  Render::FrameWriteMemoryBufferSize[v4] = size;
}

// File Line: 542
// RVA: 0xBDF0
void __fastcall Render::SetFrameWriteMemoryOverflow(
        unsigned int index,
        char *memory,
        UFG::qVRAMemoryHandle *handle,
        unsigned int size)
{
  __int64 v4; // rbx

  v4 = index;
  Render::FrameWriteMemoryBufferOverflow[index] = memory;
  UFG::qVRAMemoryHandle::operator=(&Render::FrameWriteMemoryHandleOverflow[index], handle);
  Render::FrameWriteMemoryBufferOverflowSize[v4] = size;
}

// File Line: 544
// RVA: 0xBE50
void __fastcall Render::SetPrimitiveFrameWriteMemory(
        unsigned int index,
        char *memory,
        UFG::qVRAMemoryHandle *handle,
        unsigned int size)
{
  __int64 v4; // rbx

  v4 = index;
  Render::PrimitiveFrameWriteMemoryBuffer[index] = memory;
  UFG::qVRAMemoryHandle::operator=(&Render::PrimitiveFrameWriteMemoryHandle[index], handle);
  Render::PrimitiveFrameWriteMemoryBufferSize[v4] = size;
}

// File Line: 545
// RVA: 0xBEB0
void __fastcall Render::SetPrimitiveFrameWriteMemoryOverflow(
        unsigned int index,
        char *memory,
        UFG::qVRAMemoryHandle *handle,
        unsigned int size)
{
  __int64 v4; // rbx

  v4 = index;
  Render::PrimitiveFrameWriteMemoryBufferOverflow[index] = memory;
  UFG::qVRAMemoryHandle::operator=(&Render::PrimitiveFrameWriteMemoryHandleOverflow[index], handle);
  Render::PrimitiveFrameWriteMemoryBufferOverflowSize[v4] = size;
}

// File Line: 547
// RVA: 0xBCD0
void __fastcall Render::SetFramePatchMemory(
        unsigned int index,
        char *memory,
        UFG::qVRAMemoryHandle *handle,
        unsigned int size)
{
  __int64 v4; // rbx

  v4 = index;
  Render::FramePatchMemoryBuffer[index] = memory;
  UFG::qVRAMemoryHandle::operator=(&Render::FramePatchMemoryHandle[index], handle);
  Render::FramePatchMemoryBufferSize[v4] = size;
}

// File Line: 548
// RVA: 0xBD30
void __fastcall Render::SetFramePatchMemoryOverflow(
        unsigned int index,
        char *memory,
        UFG::qVRAMemoryHandle *handle,
        unsigned int size)
{
  __int64 v4; // rbx

  v4 = index;
  Render::FramePatchMemoryBufferOverflow[index] = memory;
  UFG::qVRAMemoryHandle::operator=(&Render::FramePatchMemoryHandleOverflow[index], handle);
  Render::FramePatchMemoryBufferOverflowSize[v4] = size;
}

// File Line: 550
// RVA: 0xBBC0
void __fastcall Render::SetFrameIndexMemory(
        unsigned int index,
        char *memory,
        UFG::qVRAMemoryHandle *handle,
        unsigned int size)
{
  __int64 v4; // rbx

  v4 = index;
  Render::FrameIndexMemoryBuffer[index] = memory;
  UFG::qVRAMemoryHandle::operator=(&Render::FrameIndexMemoryHandle[index], handle);
  Render::FrameIndexMemoryBufferSize[v4] = size;
}

// File Line: 551
// RVA: 0xBC20
void __fastcall Render::SetFrameIndexMemoryOverflow(
        unsigned int index,
        char *memory,
        UFG::qVRAMemoryHandle *handle,
        unsigned int size)
{
  __int64 v4; // rbx

  v4 = index;
  Render::FrameIndexMemoryBufferOverflow[index] = memory;
  UFG::qVRAMemoryHandle::operator=(&Render::FrameIndexMemoryHandleOverflow[index], handle);
  Render::FrameIndexMemoryBufferOverflowSize[v4] = size;
}

// File Line: 556
// RVA: 0xBF60
void __fastcall Render::SwapFrameMemoryBuffers(Render *this)
{
  __int64 v1; // rdx
  __int64 v2; // r14
  __int64 v3; // rbx
  char *mData; // rbp
  char *v5; // rsi
  char *v6; // rdi
  unsigned int v7; // r13d
  char *v8; // r12
  __int64 byte_size1; // r15
  unsigned __int64 v10; // rax
  UFG::qLinearAllocator *v11; // r14
  UFG::qLinearAllocator *v12; // rbp
  UFG::qLinearAllocator *v13; // rsi
  UFG::qLinearAllocator *v14; // rdi
  UFG::qLinearAllocator *v15; // rbx
  char *v16; // [rsp+30h] [rbp-178h]
  char *v17; // [rsp+38h] [rbp-170h]
  char *buffer0; // [rsp+40h] [rbp-168h]
  char *v19; // [rsp+48h] [rbp-160h]
  char *buffer1; // [rsp+50h] [rbp-158h]
  UFG::qVRAMemoryHandle v21; // [rsp+60h] [rbp-148h] BYREF
  UFG::qVRAMemoryHandle v22; // [rsp+80h] [rbp-128h] BYREF
  UFG::qVRAMemoryHandle v23; // [rsp+A0h] [rbp-108h] BYREF
  UFG::qVRAMemoryHandle v24; // [rsp+C0h] [rbp-E8h] BYREF
  UFG::qVRAMemoryHandle v25; // [rsp+E0h] [rbp-C8h] BYREF
  UFG::qVRAMemoryHandle v26; // [rsp+100h] [rbp-A8h] BYREF
  UFG::qVRAMemoryHandle v27; // [rsp+120h] [rbp-88h] BYREF
  UFG::qVRAMemoryHandle v28; // [rsp+140h] [rbp-68h] BYREF
  unsigned int v29; // [rsp+1B0h] [rbp+8h]
  unsigned int byte_size0; // [rsp+1B8h] [rbp+10h]
  unsigned int v31; // [rsp+1C0h] [rbp+18h]
  unsigned int v32; // [rsp+1C8h] [rbp+20h]

  v1 = (Render::FrameMemoryBufferIndex + 1) % Render::FrameMemoryNumBuffers;
  v2 = v1;
  buffer0 = Render::FrameMemoryBuffer[v1];
  byte_size0 = Render::FrameMemoryBufferSize[(unsigned int)v1];
  buffer1 = Render::FrameMemoryBufferOverflow[(unsigned int)v1];
  v29 = Render::FrameMemoryBufferOverflowSize[(unsigned int)v1];
  v3 = v1;
  UFG::qVRAMemoryHandle::qVRAMemoryHandle(&v28, &Render::FrameWriteMemoryHandle[v1]);
  UFG::qVRAMemoryHandle::qVRAMemoryHandle(&v26, &Render::FrameWriteMemoryHandleOverflow[v3]);
  UFG::qVRAMemoryHandle::qVRAMemoryHandle(&v27, &Render::PrimitiveFrameWriteMemoryHandle[v3]);
  UFG::qVRAMemoryHandle::qVRAMemoryHandle(&v25, &Render::PrimitiveFrameWriteMemoryHandleOverflow[v3]);
  mData = Render::FramePatchMemoryBuffer[v2];
  UFG::qVRAMemoryHandle::qVRAMemoryHandle(&v24, &Render::FramePatchMemoryHandle[v3]);
  v32 = Render::FramePatchMemoryBufferSize[v2];
  v5 = Render::FramePatchMemoryBufferOverflow[v2];
  UFG::qVRAMemoryHandle::qVRAMemoryHandle(&v22, &Render::FramePatchMemoryHandleOverflow[v3]);
  v31 = Render::FramePatchMemoryBufferOverflowSize[v2];
  v6 = Render::FrameIndexMemoryBuffer[v2];
  UFG::qVRAMemoryHandle::qVRAMemoryHandle(&v23, &Render::FrameIndexMemoryHandle[v3]);
  v7 = Render::FrameIndexMemoryBufferSize[v2];
  v8 = Render::FrameIndexMemoryBufferOverflow[v2];
  UFG::qVRAMemoryHandle::qVRAMemoryHandle(&v21, &Render::FrameIndexMemoryHandleOverflow[v3]);
  byte_size1 = Render::FrameIndexMemoryBufferOverflowSize[v2];
  if ( v24.mData )
    mData = v24.mData;
  v17 = mData;
  if ( v22.mData )
    v5 = v22.mData;
  v16 = v5;
  if ( v23.mData )
    v6 = v23.mData;
  v19 = v6;
  if ( v21.mData )
    v8 = v21.mData;
  Render::FrameMemoryBufferIndex = v2;
  v10 = (unsigned __int64)(unsigned int)v2 << 7;
  v11 = (UFG::qLinearAllocator *)((char *)Render::FrameMemoryAllocators + v10);
  v12 = (UFG::qLinearAllocator *)((char *)Render::FrameWriteMemoryAllocators + v10);
  v13 = (UFG::qLinearAllocator *)((char *)Render::PrimitiveFrameWriteMemoryAllocators + v10);
  v14 = (UFG::qLinearAllocator *)((char *)Render::FramePatchMemoryAllocators + v10);
  v15 = (UFG::qLinearAllocator *)((char *)Render::FrameIndexMemoryAllocators + v10);
  UFG::qLinearAllocator::Init(
    (UFG::qLinearAllocator *)((char *)Render::FrameMemoryAllocators + v10),
    buffer0,
    byte_size0,
    buffer1,
    v29);
  UFG::qLinearAllocator::Init(v14, v17, v32, v16, v31);
  UFG::qLinearAllocator::Init(v15, v19, v7, v8, byte_size1);
  UFG::qTaskManager::NextFrame(&UFG::gTaskManager, v11, 0);
  Illusion::gEngine.PrevFrameMemory = Illusion::gEngine.FrameMemory;
  Illusion::gEngine.FrameMemory = v11;
  Illusion::gEngine.FrameWriteMemory = v12;
  Illusion::gEngine.PrimitiveFrameWriteMemory = v13;
  Illusion::gEngine.FramePatchMemory = v14;
  Illusion::gEngine.FrameIndexMemory = v15;
  UFG::qVRAMemoryHandle::~qVRAMemoryHandle(&v21);
  UFG::qVRAMemoryHandle::~qVRAMemoryHandle(&v23);
  UFG::qVRAMemoryHandle::~qVRAMemoryHandle(&v22);
  UFG::qVRAMemoryHandle::~qVRAMemoryHandle(&v24);
  UFG::qVRAMemoryHandle::~qVRAMemoryHandle(&v25);
  UFG::qVRAMemoryHandle::~qVRAMemoryHandle(&v27);
  UFG::qVRAMemoryHandle::~qVRAMemoryHandle(&v26);
  UFG::qVRAMemoryHandle::~qVRAMemoryHandle(&v28);
}

// File Line: 660
// RVA: 0xB650
void __fastcall Render::InitVertexDeclarations(Render *this)
{
  UFG::qList<Illusion::VertexStreamDescriptor,Illusion::VertexStreamDescriptor,1,0> *StreamDescriptors; // rax
  Illusion::VertexStreamDescriptor *p_mNext; // rsi
  Illusion::VertexStreamDescriptor *v3; // rbx
  Illusion::VertexDecl *v4; // rdi
  UFG::qResourceWarehouse *v5; // rax

  StreamDescriptors = Illusion::VertexStreamDescriptor::GetStreamDescriptors();
  p_mNext = (Illusion::VertexStreamDescriptor *)&StreamDescriptors[-1].mNode.mNext;
  v3 = (Illusion::VertexStreamDescriptor *)&StreamDescriptors->mNode.mNext[-1].mNext;
  if ( v3 != (Illusion::VertexStreamDescriptor *)&StreamDescriptors[-1].mNode.mNext )
  {
    do
    {
      v4 = Illusion::Factory::NewVertexDecl(v3, 0i64, 0i64, 0i64);
      v5 = UFG::qResourceWarehouse::Instance();
      UFG::qResourceWarehouse::Add(v5, &v4->UFG::qResourceData);
      v3 = (Illusion::VertexStreamDescriptor *)&v3->mNext[-1].mNext;
    }
    while ( v3 != p_mNext );
  }
}

// File Line: 681
// RVA: 0xB460
void __fastcall Render::InitStateParams(Render *this)
{
  Illusion::StateSystem::AddParam(&Illusion::gStateSystem, "cbTimebase", 0);
  Illusion::StateSystem::AddParam(&Illusion::gStateSystem, "cbColourBiasScale", 0);
  Illusion::StateSystem::AddParam(&Illusion::gStateSystem, "cbShaderParams", 0);
  Illusion::StateSystem::AddParam(&Illusion::gStateSystem, "cbViewTransform", 0);
  Illusion::StateSystem::AddParam(&Illusion::gStateSystem, "texDiffuse", 1);
  Illusion::StateSystem::AddParam(&Illusion::gStateSystem, "texBump", 1);
  Illusion::StateSystem::AddParam(&Illusion::gStateSystem, "texSpecular", 1);
  Illusion::StateSystem::AddParam(&Illusion::gStateSystem, "texEmissive", 1);
  Illusion::StateSystem::AddParam(&Illusion::gStateSystem, "texDamage", 1);
  Illusion::StateSystem::AddParam(&Illusion::gStateSystem, "texBlendMask", 1);
  Illusion::StateSystem::AddParam(&Illusion::gStateSystem, "texDiffuse2", 1);
  Illusion::StateSystem::AddParam(&Illusion::gStateSystem, "texBump2", 1);
  Illusion::StateSystem::AddParam(&Illusion::gStateSystem, "texSpecular2", 1);
  Illusion::StateSystem::AddParam(&Illusion::gStateSystem, "texDetail", 1);
  Illusion::StateSystem::AddParam(&Illusion::gStateSystem, "texSphericalMap", 1);
  Illusion::StateSystem::AddParam(&Illusion::gStateSystem, "texDistAtten", 1);
  Illusion::StateSystem::AddParam(&Illusion::gStateSystem, "cbUberParams", 0);
  Illusion::StateSystem::AddParam(&Illusion::gStateSystem, "cbLightSet", 0);
  Illusion::StateSystem::AddParam(&Illusion::gStateSystem, "cbTextureCompColour", 0);
  Illusion::StateSystem::AddParam(&Illusion::gStateSystem, "cbClipPlanes", 0);
  Illusion::StateSystem::AddParam(&Illusion::gStateSystem, "cbDepthBiasSortLayer", 0);
  Illusion::StateSystem::AddParam(&Illusion::gStateSystem, "cbSceneryInstance", 0);
}

// File Line: 711
// RVA: 0xB790
void __fastcall Render::RenderWorld(float delta_time)
{
  if ( Render::gRenderCallbacks.mRenderWorldFunc )
    Render::gRenderCallbacks.mRenderWorldFunc(delta_time, Render::gRenderCallbacks.mRenderParam);
}

// File Line: 726
// RVA: 0xB3E0
float __fastcall Render::GetDisplayAspectRatio()
{
  if ( Render::GetRenderFeatures()->mForceLetterBox )
    return FLOAT_1_7777778;
  if ( g_Fullscreen )
    return gMonitorNativeDisplayAspectRatio;
  return gDisplayAspectRatio;
}

// File Line: 751
// RVA: 0xB2F0
void __fastcall Render::GetBackBufferViewportScissor(Illusion::ViewportScissorState *vp_scissor, bool *is_full_screen)
{
  Illusion::Target *BackBufferTarget; // rsi
  int mHeight; // edx
  int v6; // r8d
  int v7; // r9d
  float v8; // xmm0_4
  int v9; // edx

  BackBufferTarget = Render::GetBackBufferTarget();
  Illusion::SetFullscreenViewportScissor(BackBufferTarget, vp_scissor, 0);
  if ( Render::GetRenderFeatures()->mForceLetterBox )
  {
    mHeight = BackBufferTarget->mHeight;
    v6 = (int)(float)((float)BackBufferTarget->mWidth * Render::gScreenViewportScaleH);
    v7 = BackBufferTarget->mWidth - v6;
    v8 = (float)mHeight * Render::gScreenViewportScaleV;
    vp_scissor->mScissorWidth = v6;
    vp_scissor->mScissorHeight = (int)v8;
    v9 = (unsigned int)(mHeight - (int)v8) >> 1;
    v7 = (unsigned int)v7 >> 1;
    vp_scissor->mScissorX = v7;
    vp_scissor->mScissorY = v9;
    vp_scissor->mViewPortX = (float)v7;
    vp_scissor->mViewPortY = (float)v9;
    vp_scissor->mViewPortWidth = (float)v6;
    vp_scissor->mViewPortHeight = (float)(int)v8;
    *is_full_screen = 0;
  }
  else
  {
    *is_full_screen = 1;
  }
}

// File Line: 819
// RVA: 0xB7B0
void __fastcall Render::RenderWorldEye(float delta_time, Render::eStereoRenderEye eye)
{
  UFG::BaseCameraComponent *v3; // rax
  UFG::Camera *v4; // rbx
  UFG::BaseCameraComponent *mCurrentCamera; // rcx
  UFG::Camera *p_mCamera; // rcx
  UFG::qMatrix44 *WorldView; // rax
  float z; // xmm11_4
  float w; // xmm12_4
  float x; // xmm9_4
  float v11; // xmm7_4
  float v12; // xmm8_4
  float v13; // xmm5_4
  float v14; // xmm3_4
  float v15; // xmm4_4
  float v16; // xmm1_4
  float y; // xmm15_4
  float v18; // xmm14_4
  float v19; // xmm0_4
  float v20; // xmm2_4
  UFG::BaseCameraComponent *v21; // rcx
  UFG::Camera *v22; // rcx
  UFG::qVector4 v23; // xmm1
  UFG::qVector4 v24; // xmm2
  UFG::qMatrix44 *p_mTransformation; // rcx
  UFG::qVector4 v26; // xmm3
  UFG::BaseCameraComponent *v27; // rcx
  UFG::qVector4 v28; // xmm1
  UFG::qVector4 v29; // xmm2
  UFG::qVector4 v30; // xmm3
  UFG::qMatrix44 m; // [rsp+20h] [rbp-E0h] BYREF
  UFG::qMatrix44 v32; // [rsp+60h] [rbp-A0h] BYREF
  float v34; // [rsp+158h] [rbp+58h]

  gCurrentEye = eye;
  if ( Render::gRenderCallbacks.mRenderWorldFunc )
  {
    if ( UFG::Director::Get()
      && (v3 = UFG::Director::Get()->mCurrentCamera) != 0i64
      && v3 != (UFG::BaseCameraComponent *)-80i64 )
    {
      v4 = 0i64;
      mCurrentCamera = UFG::Director::Get()->mCurrentCamera;
      if ( mCurrentCamera )
        p_mCamera = &mCurrentCamera->mCamera;
      else
        p_mCamera = 0i64;
      WorldView = UFG::Camera::GetWorldView(p_mCamera);
      z = WorldView->v0.z;
      w = WorldView->v0.w;
      x = WorldView->v0.x;
      m.v0.y = WorldView->v0.y;
      m.v0.z = z;
      m.v0.x = x;
      m.v0.w = w;
      v11 = WorldView->v1.z;
      v12 = WorldView->v1.w;
      v13 = WorldView->v1.x;
      m.v1.y = WorldView->v1.y;
      m.v1.x = v13;
      m.v1.z = v11;
      m.v1.w = v12;
      v14 = WorldView->v2.z;
      v15 = WorldView->v2.w;
      v16 = WorldView->v2.x;
      m.v2.y = WorldView->v2.y;
      m.v2.x = v16;
      m.v2.z = v14;
      m.v2.w = v15;
      y = WorldView->v3.y;
      v18 = WorldView->v3.x;
      v34 = WorldView->v3.z;
      v19 = WorldView->v3.w;
      v32.v1.y = m.v1.y;
      m.v3.x = v18;
      m.v3.y = y;
      m.v3.z = v34;
      m.v3.w = v19;
      v32.v3.z = v34;
      v32.v0.x = x;
      v32.v0.y = m.v0.y;
      v32.v0.z = z;
      v32.v0.w = w;
      v32.v1.x = v13;
      v32.v1.z = v11;
      v32.v1.w = v12;
      v32.v2.x = v16;
      v32.v2.y = m.v2.y;
      v32.v2.z = v14;
      v32.v2.w = v15;
      v32.v3.x = v18;
      v32.v3.y = y;
      v32.v3.w = v19;
      UFG::Director::Get();
      v20 = g_interAxialDistance * 0.5;
      if ( eye == STEREO_EYE_RIGHT )
        LODWORD(v20) ^= _xmm[0];
      m.v3.x = v18 + v20;
      LODWORD(m.v3.w) = (_DWORD)FLOAT_1_0;
      m.v3.y = y + (float)(v20 * 0.0);
      m.v3.z = v34 + (float)(v20 * 0.0);
      v21 = UFG::Director::Get()->mCurrentCamera;
      if ( v21 )
        v22 = &v21->mCamera;
      else
        v22 = 0i64;
      v23 = m.v1;
      v24 = m.v2;
      p_mTransformation = &v22->mTransformation;
      v26 = m.v3;
      p_mTransformation[-1].v0 = m.v0;
      p_mTransformation[-1].v1 = v23;
      p_mTransformation[-1].v2 = v24;
      p_mTransformation[-1].v3 = v26;
      UFG::qInverseAffine(p_mTransformation, &m);
      Render::gRenderCallbacks.mRenderWorldFunc(delta_time, Render::gRenderCallbacks.mRenderParam);
      v27 = UFG::Director::Get()->mCurrentCamera;
      if ( v27 )
        v4 = &v27->mCamera;
      v28 = v32.v1;
      v29 = v32.v2;
      v30 = v32.v3;
      v4->mView.v0 = v32.v0;
      v4->mView.v1 = v28;
      v4->mView.v2 = v29;
      v4->mView.v3 = v30;
      UFG::qInverseAffine(&v4->mTransformation, &v32);
    }
    else
    {
      Render::gRenderCallbacks.mRenderWorldFunc(delta_time, Render::gRenderCallbacks.mRenderParam);
    }
  }
}

// File Line: 864
// RVA: 0xC2B0
bool __fastcall Render::UpdateGameSystems(float delta_time)
{
  return !Render::gRenderCallbacks.mUpdateWorldFunc || Render::gRenderCallbacks.mUpdateWorldFunc(delta_time);
}

