// File Line: 39
// RVA: 0x1452C00
__int64 dynamic_initializer_for__UFG::qReflectObjectType_Render::rLight_UFG::qReflectObject_::sInventory__()
{
  unsigned __int64 v0; // rax
  UFG::qReflectWarehouse *v1; // rax

  v0 = UFG::qStringHash64("Render::rLight", 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectInventoryBase::qReflectInventoryBase(
    (UFG::qReflectInventoryBase *)&UFG::qReflectObjectType<Render::rLight,UFG::qReflectObject>::sInventory.vfptr,
    "Render::rLight",
    v0);
  UFG::qReflectObjectType<Render::rLight,UFG::qReflectObject>::sInventory.vfptr = (UFG::qReflectInventoryBaseVtbl *)&UFG::qReflectInventory<Render::rLight>::`vftable';
  UFG::qReflectInventory<Render::rLight>::OnAddToWarehouse(&UFG::qReflectObjectType<Render::rLight,UFG::qReflectObject>::sInventory);
  v1 = UFG::qReflectWarehouse::Instance();
  UFG::qReflectWarehouse::Add(
    v1,
    (UFG::qReflectInventoryBase *)&UFG::qReflectObjectType<Render::rLight,UFG::qReflectObject>::sInventory.vfptr);
  return atexit(dynamic_atexit_destructor_for__UFG::qReflectObjectType_Render::rLight_UFG::qReflectObject_::sInventory__);
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
  Render::RenderOutputParams *v1; // rbx

  v1 = this;
  UFG::qMemSet(this, 0, 0x68u);
  v1->mEnableFullscreen = 1;
  v1->mAAQuality = 0;
  v1->mSSAO = 0;
  v1->mEnableVSync = 1;
  v1->m3DConvergence = 10;
  v1->m3DDepth = 1;
  v1->mInterAxialDistance = 0.029999999;
  v1->mTimeStepSmoothingFrames = 5;
  v1->mShadowRes = 1;
  v1->mShadowFilter = 1;
  v1->mMotionBlur = 1;
  v1->mLODSetting = 2;
  v1->mGlobalSetting = 2;
  v1->mTextureFilterQuality = 2;
  v1->mTextureDetailLevel = 1;
  v1->mEnableCloudVolumes = 1;
}

// File Line: 119
// RVA: 0xB1E0
void __fastcall Render::RenderOutputParams::ChangeGlobalSetting(Render::RenderOutputParams *this, Render::eGlobalSetting globalSetting)
{
  __int32 v2; // edx
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
          this->mAAQuality = 2;
          this->mShadowRes = 2;
          this->mShadowFilter = 1;
          this->mMotionBlur = 2;
          this->mSSAO = 1;
          this->mLODSetting = 3;
          this->mGlobalSetting = 4;
          this->mTextureFilterQuality = 4;
          this->mTextureDetailLevel = 2;
          this->mEnableCloudVolumes = 1;
        }
      }
      else
      {
        this->mAAQuality = 1;
        this->mShadowRes = 2;
        this->mShadowFilter = 1;
        this->mMotionBlur = 1;
        this->mSSAO = 1;
        this->mLODSetting = 2;
        this->mGlobalSetting = 3;
        this->mTextureFilterQuality = 3;
        this->mTextureDetailLevel = 2;
        this->mEnableCloudVolumes = 1;
      }
    }
    else
    {
      this->mShadowRes = 1;
      this->mShadowFilter = 1;
      this->mMotionBlur = 1;
      this->mLODSetting = 2;
      this->mGlobalSetting = 2;
      this->mAAQuality = 0;
      this->mSSAO = 0;
      this->mTextureFilterQuality = 2;
      this->mTextureDetailLevel = 1;
      this->mEnableCloudVolumes = 1;
    }
  }
  else
  {
    this->mGlobalSetting = 1;
    *(_QWORD *)&this->mAAQuality = 0i64;
    *(_QWORD *)&this->mShadowFilter = 0i64;
    this->mLODSetting = 0;
    *(_QWORD *)&this->mTextureFilterQuality = 0i64;
    this->mEnableCloudVolumes = 0;
    this->mSSAO = 0;
  }
}

// File Line: 203
// RVA: 0xB100
void __fastcall Render::RenderInitParams::RenderInitParams(Render::RenderInitParams *this)
{
  Render::RenderInitParams *v1; // rbx

  v1 = this;
  Render::RenderOutputParams::SetDefault(&this->mRenderOutputParams);
  *(_QWORD *)&v1->mFrameMemoryTotalBytes = 0x100000i64;
  *(_QWORD *)&v1->mPrimitiveFrameWriteMemoryTotalBytes = 0i64;
  v1->mFrameIndexMemoryTotalBytes = 0;
  v1->mTitleName = "Theory [PC64-Ship]";
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
  *(_OWORD *)&Render::gRenderCallbacks.mRenderWorldFunc = *(_OWORD *)&render_callbacks->mRenderWorldFunc;
  *(_OWORD *)&Render::gRenderCallbacks.mResizeRenderBuffersFunc = *(_OWORD *)&render_callbacks->mResizeRenderBuffersFunc;
  *(_OWORD *)&Render::gRenderCallbacks.mChangeTexturePackFunc = *(_OWORD *)&render_callbacks->mChangeTexturePackFunc;
  *(_OWORD *)&Render::gRenderCallbacks.mRenderThreadSyncPointFunc = *(_OWORD *)&render_callbacks->mRenderThreadSyncPointFunc;
  *(_OWORD *)&Render::gRenderCallbacks.mRenderSimDebug = *(_OWORD *)&render_callbacks->mRenderSimDebug;
  *(_OWORD *)&Render::gRenderCallbacks.mRenderSimOcclusionQueries = *(_OWORD *)&render_callbacks->mRenderSimOcclusionQueries;
  *(_QWORD *)&Render::gRenderCallbacks.mbDisableSwapChainResizing = *(_QWORD *)&render_callbacks->mbDisableSwapChainResizing;
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
  Render::Timers::mCpuTimer_RenderSync.mPrev = (UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedCpuNode> *)&Render::Timers::mCpuTimer_RenderSync.mPrev;
  Render::Timers::mCpuTimer_RenderSync.mNext = (UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedCpuNode> *)&Render::Timers::mCpuTimer_RenderSync.mPrev;
  Render::Timers::mCpuTimer_RenderSync.mPrev = (UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveCpuNode> *)&Render::Timers::mCpuTimer_RenderSync.mPrev;
  Render::Timers::mCpuTimer_RenderSync.mNext = (UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveCpuNode> *)&Render::Timers::mCpuTimer_RenderSync.mPrev;
  Render::Timers::mCpuTimer_RenderSync.mPrev = (UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedGpuNode> *)&Render::Timers::mCpuTimer_RenderSync.mPrev;
  Render::Timers::mCpuTimer_RenderSync.mNext = (UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedGpuNode> *)&Render::Timers::mCpuTimer_RenderSync.mPrev;
  Render::Timers::mCpuTimer_RenderSync.mPrev = (UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveGpuNode> *)&Render::Timers::mCpuTimer_RenderSync.mPrev;
  Render::Timers::mCpuTimer_RenderSync.mNext = (UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveGpuNode> *)&Render::Timers::mCpuTimer_RenderSync.mPrev;
  return atexit(Render::Timers::_dynamic_atexit_destructor_for__mCpuTimer_RenderSync__);
}

// File Line: 248
// RVA: 0x14531E0
__int64 Render::Timers::_dynamic_initializer_for__mCpuTimer_WaitForGpu__()
{
  Render::Timers::mCpuTimer_WaitForGpu.mPrev = (UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedCpuNode> *)&Render::Timers::mCpuTimer_WaitForGpu.mPrev;
  Render::Timers::mCpuTimer_WaitForGpu.mNext = (UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedCpuNode> *)&Render::Timers::mCpuTimer_WaitForGpu.mPrev;
  Render::Timers::mCpuTimer_WaitForGpu.mPrev = (UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveCpuNode> *)&Render::Timers::mCpuTimer_WaitForGpu.mPrev;
  Render::Timers::mCpuTimer_WaitForGpu.mNext = (UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveCpuNode> *)&Render::Timers::mCpuTimer_WaitForGpu.mPrev;
  Render::Timers::mCpuTimer_WaitForGpu.mPrev = (UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedGpuNode> *)&Render::Timers::mCpuTimer_WaitForGpu.mPrev;
  Render::Timers::mCpuTimer_WaitForGpu.mNext = (UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedGpuNode> *)&Render::Timers::mCpuTimer_WaitForGpu.mPrev;
  Render::Timers::mCpuTimer_WaitForGpu.mPrev = (UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveGpuNode> *)&Render::Timers::mCpuTimer_WaitForGpu.mPrev;
  Render::Timers::mCpuTimer_WaitForGpu.mNext = (UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveGpuNode> *)&Render::Timers::mCpuTimer_WaitForGpu.mPrev;
  return atexit(Render::Timers::_dynamic_atexit_destructor_for__mCpuTimer_WaitForGpu__);
}

// File Line: 249
// RVA: 0x14530E0
__int64 Render::Timers::_dynamic_initializer_for__mCpuTimer_RenderWorld__()
{
  Render::Timers::mCpuTimer_RenderWorld.mPrev = (UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedCpuNode> *)&Render::Timers::mCpuTimer_RenderWorld.mPrev;
  Render::Timers::mCpuTimer_RenderWorld.mNext = (UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedCpuNode> *)&Render::Timers::mCpuTimer_RenderWorld.mPrev;
  Render::Timers::mCpuTimer_RenderWorld.mPrev = (UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveCpuNode> *)&Render::Timers::mCpuTimer_RenderWorld.mPrev;
  Render::Timers::mCpuTimer_RenderWorld.mNext = (UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveCpuNode> *)&Render::Timers::mCpuTimer_RenderWorld.mPrev;
  Render::Timers::mCpuTimer_RenderWorld.mPrev = (UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedGpuNode> *)&Render::Timers::mCpuTimer_RenderWorld.mPrev;
  Render::Timers::mCpuTimer_RenderWorld.mNext = (UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedGpuNode> *)&Render::Timers::mCpuTimer_RenderWorld.mPrev;
  Render::Timers::mCpuTimer_RenderWorld.mPrev = (UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveGpuNode> *)&Render::Timers::mCpuTimer_RenderWorld.mPrev;
  Render::Timers::mCpuTimer_RenderWorld.mNext = (UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveGpuNode> *)&Render::Timers::mCpuTimer_RenderWorld.mPrev;
  return atexit(Render::Timers::_dynamic_atexit_destructor_for__mCpuTimer_RenderWorld__);
}

// File Line: 250
// RVA: 0x1453060
__int64 Render::Timers::_dynamic_initializer_for__mCpuTimer_RenderThread__()
{
  Render::Timers::mCpuTimer_RenderThread.mPrev = (UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedCpuNode> *)&Render::Timers::mCpuTimer_RenderThread.mPrev;
  Render::Timers::mCpuTimer_RenderThread.mNext = (UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedCpuNode> *)&Render::Timers::mCpuTimer_RenderThread.mPrev;
  Render::Timers::mCpuTimer_RenderThread.mPrev = (UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveCpuNode> *)&Render::Timers::mCpuTimer_RenderThread.mPrev;
  Render::Timers::mCpuTimer_RenderThread.mNext = (UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveCpuNode> *)&Render::Timers::mCpuTimer_RenderThread.mPrev;
  Render::Timers::mCpuTimer_RenderThread.mPrev = (UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedGpuNode> *)&Render::Timers::mCpuTimer_RenderThread.mPrev;
  Render::Timers::mCpuTimer_RenderThread.mNext = (UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedGpuNode> *)&Render::Timers::mCpuTimer_RenderThread.mPrev;
  Render::Timers::mCpuTimer_RenderThread.mPrev = (UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveGpuNode> *)&Render::Timers::mCpuTimer_RenderThread.mPrev;
  Render::Timers::mCpuTimer_RenderThread.mNext = (UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveGpuNode> *)&Render::Timers::mCpuTimer_RenderThread.mPrev;
  return atexit(Render::Timers::_dynamic_atexit_destructor_for__mCpuTimer_RenderThread__);
}

// File Line: 251
// RVA: 0x1453160
__int64 Render::Timers::_dynamic_initializer_for__mCpuTimer_UpdateWorld__()
{
  Render::Timers::mCpuTimer_UpdateWorld.mPrev = (UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedCpuNode> *)&Render::Timers::mCpuTimer_UpdateWorld.mPrev;
  Render::Timers::mCpuTimer_UpdateWorld.mNext = (UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedCpuNode> *)&Render::Timers::mCpuTimer_UpdateWorld.mPrev;
  Render::Timers::mCpuTimer_UpdateWorld.mPrev = (UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveCpuNode> *)&Render::Timers::mCpuTimer_UpdateWorld.mPrev;
  Render::Timers::mCpuTimer_UpdateWorld.mNext = (UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveCpuNode> *)&Render::Timers::mCpuTimer_UpdateWorld.mPrev;
  Render::Timers::mCpuTimer_UpdateWorld.mPrev = (UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedGpuNode> *)&Render::Timers::mCpuTimer_UpdateWorld.mPrev;
  Render::Timers::mCpuTimer_UpdateWorld.mNext = (UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedGpuNode> *)&Render::Timers::mCpuTimer_UpdateWorld.mPrev;
  Render::Timers::mCpuTimer_UpdateWorld.mPrev = (UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveGpuNode> *)&Render::Timers::mCpuTimer_UpdateWorld.mPrev;
  Render::Timers::mCpuTimer_UpdateWorld.mNext = (UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveGpuNode> *)&Render::Timers::mCpuTimer_UpdateWorld.mPrev;
  return atexit(Render::Timers::_dynamic_atexit_destructor_for__mCpuTimer_UpdateWorld__);
}

// File Line: 492
// RVA: 0x1452D40
__int64 Render::_dynamic_initializer_for__FrameMemoryAllocators__()
{
  `eh vector constructor iterator'(
    Render::FrameMemoryAllocators,
    0x80ui64,
    4,
    (void (__fastcall *)(void *))UFG::qLinearAllocator::qLinearAllocator);
  return atexit(Render::_dynamic_atexit_destructor_for__FrameMemoryAllocators__);
}

// File Line: 498
// RVA: 0x1452E40
__int64 Render::_dynamic_initializer_for__FrameWriteMemoryAllocators__()
{
  `eh vector constructor iterator'(
    Render::FrameWriteMemoryAllocators,
    0x80ui64,
    4,
    (void (__fastcall *)(void *))UFG::qLinearAllocator::qLinearAllocator);
  return atexit(Render::_dynamic_atexit_destructor_for__FrameWriteMemoryAllocators__);
}

// File Line: 500
// RVA: 0x1452E80
__int64 Render::_dynamic_initializer_for__FrameWriteMemoryHandle__()
{
  `eh vector constructor iterator'(
    Render::FrameWriteMemoryHandle,
    0x20ui64,
    4,
    (void (__fastcall *)(void *))UFG::qVRAMemoryHandle::qVRAMemoryHandle);
  return atexit(Render::_dynamic_atexit_destructor_for__FrameWriteMemoryHandle__);
}

// File Line: 503
// RVA: 0x1452EC0
__int64 Render::_dynamic_initializer_for__FrameWriteMemoryHandleOverflow__()
{
  `eh vector constructor iterator'(
    Render::FrameWriteMemoryHandleOverflow,
    0x20ui64,
    4,
    (void (__fastcall *)(void *))UFG::qVRAMemoryHandle::qVRAMemoryHandle);
  return atexit(Render::_dynamic_atexit_destructor_for__FrameWriteMemoryHandleOverflow__);
}

// File Line: 506
// RVA: 0x1452F00
__int64 Render::_dynamic_initializer_for__PrimitiveFrameWriteMemoryAllocators__()
{
  `eh vector constructor iterator'(
    Render::PrimitiveFrameWriteMemoryAllocators,
    0x80ui64,
    4,
    (void (__fastcall *)(void *))UFG::qLinearAllocator::qLinearAllocator);
  return atexit(Render::_dynamic_atexit_destructor_for__PrimitiveFrameWriteMemoryAllocators__);
}

// File Line: 508
// RVA: 0x1452F40
__int64 Render::_dynamic_initializer_for__PrimitiveFrameWriteMemoryHandle__()
{
  `eh vector constructor iterator'(
    Render::PrimitiveFrameWriteMemoryHandle,
    0x20ui64,
    4,
    (void (__fastcall *)(void *))UFG::qVRAMemoryHandle::qVRAMemoryHandle);
  return atexit(Render::_dynamic_atexit_destructor_for__PrimitiveFrameWriteMemoryHandle__);
}

// File Line: 511
// RVA: 0x1452F80
__int64 Render::_dynamic_initializer_for__PrimitiveFrameWriteMemoryHandleOverflow__()
{
  `eh vector constructor iterator'(
    Render::PrimitiveFrameWriteMemoryHandleOverflow,
    0x20ui64,
    4,
    (void (__fastcall *)(void *))UFG::qVRAMemoryHandle::qVRAMemoryHandle);
  return atexit(Render::_dynamic_atexit_destructor_for__PrimitiveFrameWriteMemoryHandleOverflow__);
}

// File Line: 514
// RVA: 0x1452D80
__int64 Render::_dynamic_initializer_for__FramePatchMemoryAllocators__()
{
  `eh vector constructor iterator'(
    Render::FramePatchMemoryAllocators,
    0x80ui64,
    4,
    (void (__fastcall *)(void *))UFG::qLinearAllocator::qLinearAllocator);
  return atexit(Render::_dynamic_atexit_destructor_for__FramePatchMemoryAllocators__);
}

// File Line: 516
// RVA: 0x1452DC0
__int64 Render::_dynamic_initializer_for__FramePatchMemoryHandle__()
{
  `eh vector constructor iterator'(
    Render::FramePatchMemoryHandle,
    0x20ui64,
    4,
    (void (__fastcall *)(void *))UFG::qVRAMemoryHandle::qVRAMemoryHandle);
  return atexit(Render::_dynamic_atexit_destructor_for__FramePatchMemoryHandle__);
}

// File Line: 519
// RVA: 0x1452E00
__int64 Render::_dynamic_initializer_for__FramePatchMemoryHandleOverflow__()
{
  `eh vector constructor iterator'(
    Render::FramePatchMemoryHandleOverflow,
    0x20ui64,
    4,
    (void (__fastcall *)(void *))UFG::qVRAMemoryHandle::qVRAMemoryHandle);
  return atexit(Render::_dynamic_atexit_destructor_for__FramePatchMemoryHandleOverflow__);
}

// File Line: 522
// RVA: 0x1452C80
__int64 Render::_dynamic_initializer_for__FrameIndexMemoryAllocators__()
{
  `eh vector constructor iterator'(
    Render::FrameIndexMemoryAllocators,
    0x80ui64,
    4,
    (void (__fastcall *)(void *))UFG::qLinearAllocator::qLinearAllocator);
  return atexit(Render::_dynamic_atexit_destructor_for__FrameIndexMemoryAllocators__);
}

// File Line: 524
// RVA: 0x1452CC0
__int64 Render::_dynamic_initializer_for__FrameIndexMemoryHandle__()
{
  `eh vector constructor iterator'(
    Render::FrameIndexMemoryHandle,
    0x20ui64,
    4,
    (void (__fastcall *)(void *))UFG::qVRAMemoryHandle::qVRAMemoryHandle);
  return atexit(Render::_dynamic_atexit_destructor_for__FrameIndexMemoryHandle__);
}

// File Line: 527
// RVA: 0x1452D00
__int64 Render::_dynamic_initializer_for__FrameIndexMemoryHandleOverflow__()
{
  `eh vector constructor iterator'(
    Render::FrameIndexMemoryHandleOverflow,
    0x20ui64,
    4,
    (void (__fastcall *)(void *))UFG::qVRAMemoryHandle::qVRAMemoryHandle);
  return atexit(Render::_dynamic_atexit_destructor_for__FrameIndexMemoryHandleOverflow__);
}

// File Line: 532
// RVA: 0xBCA0
void __fastcall Render::SetFrameMemoryNumBuffers(unsigned int num_frame_memory_buffers)
{
  Render::FrameMemoryNumBuffers = num_frame_memory_buffers;
}

// File Line: 538
// RVA: 0xBC80
void __fastcall Render::SetFrameMemory(unsigned int index, void *memory, unsigned int size)
{
  __int64 v3; // rax

  v3 = index;
  Render::FrameMemoryBuffer[v3] = (char *)memory;
  Render::FrameMemoryBufferSize[v3] = size;
}

// File Line: 539
// RVA: 0xBCB0
void __fastcall Render::SetFrameMemoryOverflow(unsigned int index, void *memory, unsigned int size)
{
  __int64 v3; // rax

  v3 = index;
  Render::FrameMemoryBufferOverflow[v3] = (char *)memory;
  Render::FrameMemoryBufferOverflowSize[v3] = size;
}

// File Line: 541
// RVA: 0xBD90
void __fastcall Render::SetFrameWriteMemory(unsigned int index, void *memory, UFG::qVRAMemoryHandle *handle, unsigned int size)
{
  __int64 v4; // rbx
  unsigned int v5; // edi

  v4 = index;
  v5 = size;
  Render::FrameWriteMemoryBuffer[index] = (char *)memory;
  UFG::qVRAMemoryHandle::operator=(&Render::FrameWriteMemoryHandle[index], handle);
  Render::FrameWriteMemoryBufferSize[v4] = v5;
}

// File Line: 542
// RVA: 0xBDF0
void __fastcall Render::SetFrameWriteMemoryOverflow(unsigned int index, void *memory, UFG::qVRAMemoryHandle *handle, unsigned int size)
{
  __int64 v4; // rbx
  unsigned int v5; // edi

  v4 = index;
  v5 = size;
  Render::FrameWriteMemoryBufferOverflow[index] = (char *)memory;
  UFG::qVRAMemoryHandle::operator=(&Render::FrameWriteMemoryHandleOverflow[index], handle);
  Render::FrameWriteMemoryBufferOverflowSize[v4] = v5;
}

// File Line: 544
// RVA: 0xBE50
void __fastcall Render::SetPrimitiveFrameWriteMemory(unsigned int index, void *memory, UFG::qVRAMemoryHandle *handle, unsigned int size)
{
  __int64 v4; // rbx
  unsigned int v5; // edi

  v4 = index;
  v5 = size;
  Render::PrimitiveFrameWriteMemoryBuffer[index] = (char *)memory;
  UFG::qVRAMemoryHandle::operator=(&Render::PrimitiveFrameWriteMemoryHandle[index], handle);
  Render::PrimitiveFrameWriteMemoryBufferSize[v4] = v5;
}

// File Line: 545
// RVA: 0xBEB0
void __fastcall Render::SetPrimitiveFrameWriteMemoryOverflow(unsigned int index, void *memory, UFG::qVRAMemoryHandle *handle, unsigned int size)
{
  __int64 v4; // rbx
  unsigned int v5; // edi

  v4 = index;
  v5 = size;
  Render::PrimitiveFrameWriteMemoryBufferOverflow[index] = (char *)memory;
  UFG::qVRAMemoryHandle::operator=(&Render::PrimitiveFrameWriteMemoryHandleOverflow[index], handle);
  Render::PrimitiveFrameWriteMemoryBufferOverflowSize[v4] = v5;
}

// File Line: 547
// RVA: 0xBCD0
void __fastcall Render::SetFramePatchMemory(unsigned int index, void *memory, UFG::qVRAMemoryHandle *handle, unsigned int size)
{
  __int64 v4; // rbx
  unsigned int v5; // edi

  v4 = index;
  v5 = size;
  Render::FramePatchMemoryBuffer[index] = (char *)memory;
  UFG::qVRAMemoryHandle::operator=(&Render::FramePatchMemoryHandle[index], handle);
  Render::FramePatchMemoryBufferSize[v4] = v5;
}

// File Line: 548
// RVA: 0xBD30
void __fastcall Render::SetFramePatchMemoryOverflow(unsigned int index, void *memory, UFG::qVRAMemoryHandle *handle, unsigned int size)
{
  __int64 v4; // rbx
  unsigned int v5; // edi

  v4 = index;
  v5 = size;
  Render::FramePatchMemoryBufferOverflow[index] = (char *)memory;
  UFG::qVRAMemoryHandle::operator=(&Render::FramePatchMemoryHandleOverflow[index], handle);
  Render::FramePatchMemoryBufferOverflowSize[v4] = v5;
}

// File Line: 550
// RVA: 0xBBC0
void __fastcall Render::SetFrameIndexMemory(unsigned int index, void *memory, UFG::qVRAMemoryHandle *handle, unsigned int size)
{
  __int64 v4; // rbx
  unsigned int v5; // edi

  v4 = index;
  v5 = size;
  Render::FrameIndexMemoryBuffer[index] = (char *)memory;
  UFG::qVRAMemoryHandle::operator=(&Render::FrameIndexMemoryHandle[index], handle);
  Render::FrameIndexMemoryBufferSize[v4] = v5;
}

// File Line: 551
// RVA: 0xBC20
void __fastcall Render::SetFrameIndexMemoryOverflow(unsigned int index, void *memory, UFG::qVRAMemoryHandle *handle, unsigned int size)
{
  __int64 v4; // rbx
  unsigned int v5; // edi

  v4 = index;
  v5 = size;
  Render::FrameIndexMemoryBufferOverflow[index] = (char *)memory;
  UFG::qVRAMemoryHandle::operator=(&Render::FrameIndexMemoryHandleOverflow[index], handle);
  Render::FrameIndexMemoryBufferOverflowSize[v4] = v5;
}

// File Line: 556
// RVA: 0xBF60
void __fastcall Render::SwapFrameMemoryBuffers(Render *this)
{
  __int64 v1; // rdx
  __int64 v2; // r14
  __int64 v3; // rbx
  char *v4; // rbp
  char *v5; // rsi
  char *v6; // rdi
  unsigned int v7; // er13
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
  UFG::qVRAMemoryHandle v21; // [rsp+60h] [rbp-148h]
  UFG::qVRAMemoryHandle v22; // [rsp+80h] [rbp-128h]
  UFG::qVRAMemoryHandle v23; // [rsp+A0h] [rbp-108h]
  UFG::qVRAMemoryHandle v24; // [rsp+C0h] [rbp-E8h]
  UFG::qVRAMemoryHandle v25; // [rsp+E0h] [rbp-C8h]
  UFG::qVRAMemoryHandle v26; // [rsp+100h] [rbp-A8h]
  UFG::qVRAMemoryHandle v27; // [rsp+120h] [rbp-88h]
  UFG::qVRAMemoryHandle v28; // [rsp+140h] [rbp-68h]
  unsigned int v29; // [rsp+1B0h] [rbp+8h]
  unsigned int byte_size0; // [rsp+1B8h] [rbp+10h]
  unsigned int v31; // [rsp+1C0h] [rbp+18h]
  unsigned int v32; // [rsp+1C8h] [rbp+20h]

  v1 = (Render::FrameMemoryBufferIndex + 1) % Render::FrameMemoryNumBuffers;
  v2 = (Render::FrameMemoryBufferIndex + 1) % Render::FrameMemoryNumBuffers;
  buffer0 = Render::FrameMemoryBuffer[v1];
  byte_size0 = Render::FrameMemoryBufferSize[(unsigned int)v1];
  buffer1 = Render::FrameMemoryBufferOverflow[(unsigned int)v1];
  v29 = Render::FrameMemoryBufferOverflowSize[(unsigned int)v1];
  v3 = v1;
  UFG::qVRAMemoryHandle::qVRAMemoryHandle(&v28, &Render::FrameWriteMemoryHandle[v3]);
  UFG::qVRAMemoryHandle::qVRAMemoryHandle(&v26, &Render::FrameWriteMemoryHandleOverflow[v3]);
  UFG::qVRAMemoryHandle::qVRAMemoryHandle(&v27, &Render::PrimitiveFrameWriteMemoryHandle[v3]);
  UFG::qVRAMemoryHandle::qVRAMemoryHandle(&v25, &Render::PrimitiveFrameWriteMemoryHandleOverflow[v3]);
  v4 = Render::FramePatchMemoryBuffer[v2];
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
    v4 = v24.mData;
  v17 = v4;
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
  UFG::qList<Illusion::VertexStreamDescriptor,Illusion::VertexStreamDescriptor,1,0> *v1; // rax
  signed __int64 v2; // rsi
  Illusion::VertexStreamDescriptor *v3; // rbx
  Illusion::VertexDecl *v4; // rdi
  UFG::qResourceWarehouse *v5; // rax

  v1 = Illusion::VertexStreamDescriptor::GetStreamDescriptors();
  v2 = (signed __int64)&v1[-1].mNode.mNext;
  v3 = (Illusion::VertexStreamDescriptor *)&v1->mNode.mNext[-1].mNext;
  if ( v3 != (Illusion::VertexStreamDescriptor *)&v1[-1].mNode.mNext )
  {
    do
    {
      v4 = Illusion::Factory::NewVertexDecl(v3, 0i64, 0i64, 0i64);
      v5 = UFG::qResourceWarehouse::Instance();
      UFG::qResourceWarehouse::Add(v5, (UFG::qResourceData *)&v4->mNode);
      v3 = (Illusion::VertexStreamDescriptor *)&v3->mNext[-1].mNext;
    }
    while ( v3 != (Illusion::VertexStreamDescriptor *)v2 );
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
  bool *v2; // rdi
  Illusion::ViewportScissorState *v3; // rbx
  Illusion::Target *v4; // rsi
  int v5; // edx
  signed int v6; // er8
  int v7; // er9
  float v8; // xmm0_4
  signed int v9; // edx

  v2 = is_full_screen;
  v3 = vp_scissor;
  v4 = Render::GetBackBufferTarget();
  Illusion::SetFullscreenViewportScissor(v4, v3, 0);
  if ( Render::GetRenderFeatures()->mForceLetterBox )
  {
    v5 = v4->mHeight;
    v6 = (signed int)(float)((float)v4->mWidth * Render::gScreenViewportScaleH);
    v7 = v4->mWidth - v6;
    v8 = (float)v4->mHeight * Render::gScreenViewportScaleV;
    v3->mScissorWidth = v6;
    v3->mScissorHeight = (signed int)v8;
    v9 = (unsigned int)(v5 - (signed int)v8) >> 1;
    v7 = (unsigned int)v7 >> 1;
    v3->mScissorX = v7;
    v3->mScissorY = v9;
    v3->mViewPortX = (float)v7;
    v3->mViewPortY = (float)v9;
    v3->mViewPortWidth = (float)v6;
    v3->mViewPortHeight = (float)(signed int)v8;
    *v2 = 0;
  }
  else
  {
    *v2 = 1;
  }
}

// File Line: 819
// RVA: 0xB7B0
void __fastcall Render::RenderWorldEye(float delta_time, Render::eStereoRenderEye eye)
{
  Render::eStereoRenderEye v2; // edi
  UFG::BaseCameraComponent *v3; // rax
  signed __int64 v4; // rbx
  UFG::BaseCameraComponent *v5; // rcx
  UFG::Camera *v6; // rcx
  UFG::qMatrix44 *v7; // rax
  float v8; // xmm11_4
  float v9; // xmm12_4
  float v10; // xmm9_4
  float v11; // xmm7_4
  float v12; // xmm8_4
  float v13; // xmm5_4
  float v14; // xmm3_4
  float v15; // xmm4_4
  float v16; // xmm1_4
  float v17; // xmm15_4
  float v18; // xmm14_4
  float v19; // xmm0_4
  float v20; // xmm2_4
  UFG::BaseCameraComponent *v21; // rcx
  signed __int64 v22; // rcx
  UFG::qVector4 v23; // xmm1
  UFG::qVector4 v24; // xmm2
  UFG::qMatrix44 *v25; // rcx
  UFG::qVector4 v26; // xmm3
  UFG::BaseCameraComponent *v27; // rcx
  UFG::qVector4 v28; // xmm1
  UFG::qVector4 v29; // xmm2
  UFG::qVector4 v30; // xmm3
  UFG::qMatrix44 m; // [rsp+20h] [rbp-E0h]
  UFG::qMatrix44 v32; // [rsp+60h] [rbp-A0h]
  float v33; // [rsp+150h] [rbp+50h]
  float v34; // [rsp+158h] [rbp+58h]

  v33 = delta_time;
  v2 = eye;
  gCurrentEye = eye;
  if ( Render::gRenderCallbacks.mRenderWorldFunc )
  {
    if ( UFG::Director::Get()
      && (v3 = UFG::Director::Get()->mCurrentCamera) != 0i64
      && v3 != (UFG::BaseCameraComponent *)-80i64 )
    {
      v4 = 0i64;
      v5 = UFG::Director::Get()->mCurrentCamera;
      if ( v5 )
        v6 = &v5->mCamera;
      else
        v6 = 0i64;
      v7 = UFG::Camera::GetWorldView(v6);
      v8 = v7->v0.z;
      v9 = v7->v0.w;
      v10 = v7->v0.x;
      m.v0.y = v7->v0.y;
      m.v0.z = v8;
      m.v0.x = v10;
      m.v0.w = v9;
      v11 = v7->v1.z;
      v12 = v7->v1.w;
      v13 = v7->v1.x;
      m.v1.y = v7->v1.y;
      m.v1.x = v13;
      m.v1.z = v11;
      m.v1.w = v12;
      v14 = v7->v2.z;
      v15 = v7->v2.w;
      v16 = v7->v2.x;
      m.v2.y = v7->v2.y;
      m.v2.x = v16;
      m.v2.z = v14;
      m.v2.w = v15;
      v17 = v7->v3.y;
      v18 = v7->v3.x;
      v34 = v7->v3.z;
      v19 = v7->v3.w;
      v32.v1.y = m.v1.y;
      m.v3.x = v18;
      m.v3.y = v17;
      m.v3.z = v34;
      m.v3.w = v19;
      v32.v3.z = v34;
      v32.v0.x = v10;
      v32.v0.y = m.v0.y;
      v32.v0.z = v8;
      v32.v0.w = v9;
      v32.v1.x = v13;
      v32.v1.z = v11;
      v32.v1.w = v12;
      v32.v2.x = v16;
      v32.v2.y = m.v2.y;
      v32.v2.z = v14;
      v32.v2.w = v15;
      v32.v3.x = v18;
      v32.v3.y = v17;
      v32.v3.w = v19;
      UFG::Director::Get();
      v20 = g_interAxialDistance * 0.5;
      if ( v2 == 1 )
        LODWORD(v20) ^= _xmm[0];
      m.v3.x = v18 + v20;
      LODWORD(m.v3.w) = (_DWORD)FLOAT_1_0;
      m.v3.y = v17 + (float)(v20 * 0.0);
      m.v3.z = v34 + (float)(v20 * 0.0);
      v21 = UFG::Director::Get()->mCurrentCamera;
      if ( v21 )
        v22 = (signed __int64)&v21->mCamera;
      else
        v22 = 0i64;
      v23 = m.v1;
      v24 = m.v2;
      v25 = (UFG::qMatrix44 *)(v22 + 128);
      v26 = m.v3;
      v25[-1].v0 = m.v0;
      v25[-1].v1 = v23;
      v25[-1].v2 = v24;
      v25[-1].v3 = v26;
      UFG::qInverseAffine(v25, &m);
      Render::gRenderCallbacks.mRenderWorldFunc(v33, Render::gRenderCallbacks.mRenderParam);
      v27 = UFG::Director::Get()->mCurrentCamera;
      if ( v27 )
        v4 = (signed __int64)&v27->mCamera;
      v28 = v32.v1;
      v29 = v32.v2;
      v30 = v32.v3;
      *(UFG::qVector4 *)(v4 + 64) = v32.v0;
      *(UFG::qVector4 *)(v4 + 80) = v28;
      *(UFG::qVector4 *)(v4 + 96) = v29;
      *(UFG::qVector4 *)(v4 + 112) = v30;
      UFG::qInverseAffine((UFG::qMatrix44 *)(v4 + 128), &v32);
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
  bool result; // al

  if ( Render::gRenderCallbacks.mUpdateWorldFunc )
    result = Render::gRenderCallbacks.mUpdateWorldFunc(delta_time);
  else
    result = 1;
  return result;
}

