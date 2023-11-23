// File Line: 45
// RVA: 0x146B960
__int64 Render::_dynamic_initializer_for__gTrackStripSettingsInventory__()
{
  UFG::qResourceInventory::qResourceInventory(
    &Render::gTrackStripSettingsInventory,
    "TrackStripSettingsInventory",
    0x69CE5438u,
    0x86DE69F6,
    0,
    0);
  Render::gTrackStripSettingsInventory.vfptr = (UFG::qResourceInventoryVtbl *)&Render::TrackStripSettingsInventory::`vftable;
  return atexit((int (__fastcall *)())Render::_dynamic_atexit_destructor_for__gTrackStripSettingsInventory__);
}

// File Line: 76
// RVA: 0x146B820
__int64 Render::_dynamic_initializer_for__gPolyStripManager__()
{
  UFG::qFixedAllocator::qFixedAllocator(&Render::gPolyStripManager.mAllocator);
  stru_142366970.mNode.mPrev = (UFG::qNode<UFG::qReflectField,UFG::qReflectField> *)&stru_142366970;
  stru_142366970.mNode.mNext = (UFG::qNode<UFG::qReflectField,UFG::qReflectField> *)&stru_142366970;
  unk_142366980 = 0i64;
  return atexit((int (__fastcall *)())Render::_dynamic_atexit_destructor_for__gPolyStripManager__);
}

// File Line: 91
// RVA: 0x1CF900
void __fastcall Render::PolyStripManager::Init(Render::PolyStripManager *this, int stripCount)
{
  unsigned int v3; // esi
  Illusion::RasterState *v4; // rax
  UFG::qResourceWarehouse *v5; // rax
  unsigned int v6; // eax
  int v7; // eax
  Illusion::Material *mMaterial; // rbx
  int v9; // edi
  int v10; // eax
  int v11; // eax
  Illusion::Material *v12; // rbx
  int v13; // edi
  int v14; // eax
  unsigned int v15; // eax
  Illusion::Material *v16; // rbx
  unsigned int v17; // edi
  unsigned int v18; // eax
  Illusion::Material *v19; // rbx
  int v20; // eax
  UFG::qResourceWarehouse *v21; // rax

  UFG::qFixedAllocator::Init(&this->mAllocator, 2448 * stripCount, 2448, "PolyStripManager::mAllocator", 0i64);
  v3 = UFG::qStringHashUpper32("PolyStripManager.RasterState", -1);
  v4 = (Illusion::RasterState *)Illusion::Factory::NewRasterState("PolyStripManager.RasterState", v3, 0i64, 0i64, 0i64);
  this->mRasterState = v4;
  v4->mZEnabled = 1;
  this->mRasterState->mZWriteEnabled = 0;
  this->mRasterState->mZFunction = 3;
  this->mRasterState->mCullMode = 0;
  this->mRasterState->mSEnabled = 0;
  this->mRasterState->mSRefMask = 0;
  this->mRasterState->mSRefBits = 0;
  this->mRasterState->mSPassOperation = 0;
  this->mRasterState->mSFailOperation = 0;
  this->mRasterState->mSZFailOperation = 0;
  this->mRasterState->mSFunction = 7;
  v5 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v5, this->mRasterState);
  v6 = UFG::qStringHash32("PolyStripManager.Material", 0xFFFFFFFF);
  this->mMaterial = Illusion::Factory::NewMaterial("PolyStripManager.Material", v6, 4u, 0i64, 0i64, 0i64);
  v7 = UFG::qStringHashUpper32("DR_Skidmarks", -1);
  mMaterial = this->mMaterial;
  v9 = v7;
  LOWORD(mMaterial[1].mNode.mChild[0]) = 0;
  HIDWORD(mMaterial[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v10 = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  mMaterial[1].mTypeUID = -1957338719;
  LODWORD(mMaterial[1].mResourceHandles.UFG::qResourceData::mNode.mNext) = v9;
  LODWORD(mMaterial[1].mNode.mParent) = v10;
  v11 = UFG::qStringHashUpper32("SkidMark", -1);
  v12 = this->mMaterial;
  v13 = v11;
  *(_WORD *)&v12[1].mDebugName[12] = 0;
  *(_DWORD *)&v12[1].mDebugName[8] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v14 = UFG::qStringHash32("texDiffuse", 0xFFFFFFFF);
  LODWORD(v12[1].mStateBlockMask.mFlags[1]) = -1958479169;
  LODWORD(v12[1].mStateBlockMask.mFlags[0]) = v13;
  *(_DWORD *)&v12[1].mDebugName[4] = v14;
  v15 = UFG::qStringHashUpper32("7bfbac9f-c4f4-4b09-ab85-4156ad1feb91", -1);
  v16 = this->mMaterial;
  v17 = v15;
  LOWORD(v16[1].mMaterialUser.mOffset) = 0;
  *(&v16[1].mNumParams + 1) = UFG::qStringHash32("sbDepthBiasSortLayer", 0xFFFFFFFF);
  v18 = UFG::qStringHash32("sbDepthBiasSortLayer", 0xFFFFFFFF);
  LODWORD(v16[2].mResourceHandles.UFG::qResourceData::mNode.mPrev) = 1292158962;
  v16[2].mNode.mUID = v17;
  v16[1].mNumParams = v18;
  v19 = this->mMaterial;
  LOWORD(v19[2].mTypeUID) = 0;
  HIDWORD(v19[2].mResourceHandles.UFG::qResourceData::mNode.mNext) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  v20 = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  *((_DWORD *)&v19[2].UFG::qResourceData + 22) = 1002903008;
  LODWORD(v19[2].mResourceHandles.UFG::qResourceData::mNode.mNext) = v20;
  *(_DWORD *)&v19[2].mDebugName[28] = v3;
  v21 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v21, this->mMaterial);
}

// File Line: 149
// RVA: 0x1C73B0
Render::PolyStrip *__fastcall Render::PolyStripManager::AllocStrip(Render::PolyStripManager *this)
{
  UFG::qNode<Render::PolyStrip,Render::PolyStrip> *v2; // rdx
  UFG::qNode<Render::PolyStrip,Render::PolyStrip> *mNext; // rax
  UFG::qNode<Render::PolyStrip,Render::PolyStrip> *v4; // rcx
  UFG::qNode<Render::PolyStrip,Render::PolyStrip> *v5; // rax
  char *mFreeListHead; // rbx
  unsigned int mMostSlotsAllocated; // ecx
  UFG::qNode<Render::PolyStrip,Render::PolyStrip> *v8; // rdx
  UFG::qNode<Render::PolyStrip,Render::PolyStrip> *mPrev; // [rsp+40h] [rbp+8h]

  if ( !this->mAllocator.mFreeListHead )
  {
    mPrev = this->mStrips.mNode.mPrev;
    v2 = mPrev->mPrev;
    mNext = mPrev->mNext;
    v2->mNext = mNext;
    mNext->mPrev = v2;
    mPrev->mPrev = mPrev;
    mPrev->mNext = mPrev;
    v4 = mPrev->mPrev;
    v5 = mPrev->mNext;
    v4->mNext = v5;
    v5->mPrev = v4;
    mPrev->mPrev = mPrev;
    mPrev->mNext = mPrev;
    mPrev->mPrev = (UFG::qNode<Render::PolyStrip,Render::PolyStrip> *)this->mAllocator.mFreeListHead;
    this->mAllocator.mFreeListHead = (char *)mPrev;
    --this->mAllocator.mNumSlotsAllocated;
  }
  mFreeListHead = this->mAllocator.mFreeListHead;
  if ( mFreeListHead )
  {
    this->mAllocator.mFreeListHead = *(char **)mFreeListHead;
    mMostSlotsAllocated = ++this->mAllocator.mNumSlotsAllocated;
    if ( this->mAllocator.mMostSlotsAllocated > mMostSlotsAllocated )
      mMostSlotsAllocated = this->mAllocator.mMostSlotsAllocated;
    this->mAllocator.mMostSlotsAllocated = mMostSlotsAllocated;
  }
  else
  {
    UFG::qFixedAllocator::ReportFull(&this->mAllocator);
  }
  if ( mFreeListHead )
  {
    *(_QWORD *)mFreeListHead = mFreeListHead;
    *((_QWORD *)mFreeListHead + 1) = mFreeListHead;
    *((_QWORD *)mFreeListHead + 2) = 0i64;
    *((_DWORD *)mFreeListHead + 606) = 0;
    *((_QWORD *)mFreeListHead + 305) = 0i64;
  }
  v8 = this->mStrips.mNode.mNext;
  this->mStrips.mNode.mNext = (UFG::qNode<Render::PolyStrip,Render::PolyStrip> *)mFreeListHead;
  *(_QWORD *)mFreeListHead = &this->mStrips;
  *((_QWORD *)mFreeListHead + 1) = v8;
  v8->mPrev = (UFG::qNode<Render::PolyStrip,Render::PolyStrip> *)mFreeListHead;
  return (Render::PolyStrip *)mFreeListHead;
}

// File Line: 186
// RVA: 0x1D4FB0
void __fastcall Render::PolyStripManager::Render(Render::PolyStripManager *this, Render::View *view, float simTime)
{
  Illusion::StateValues *StateValues; // rax
  UFG::qNode<Render::PolyStrip,Render::PolyStrip> *mNext; // rdi
  int v7; // r14d
  Render::PolyStripManager *v8; // rsi
  float v9; // xmm6_4
  float v10; // xmm1_4
  char *v11; // rbx
  Illusion::StateValues *v12; // rax
  unsigned int mNext_high; // r8d
  Illusion::Material *mMaterial; // rbx
  __int64 mOffset; // rax
  _WORD *v16; // rax
  Illusion::Material *v17; // rbx
  unsigned int mPrev; // r8d
  __int64 v19; // rax
  _WORD *v20; // rax

  StateValues = Render::View::GetStateValues(view);
  StateValues->mSetValueMask.mFlags[0] |= 0x200ui64;
  StateValues->mParamValues[9] = 0i64;
  mNext = this->mStrips.mNode.mNext;
  if ( mNext != (UFG::qNode<Render::PolyStrip,Render::PolyStrip> *)&this->mStrips )
  {
    do
    {
      v7 = (int)mNext[151].mNext;
      v8 = (Render::PolyStripManager *)mNext->mNext;
      if ( v7 )
      {
        v9 = *(float *)&FLOAT_1_0;
        v10 = *((float *)&mNext[152].mNext + 1) + *(float *)&mNext[152].mNext;
        if ( simTime <= v10 || (v9 = 1.0 - (float)((float)(simTime - v10) * 0.33333334), v9 > 0.0) )
        {
          v11 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x80u, 0x10u);
          *(float *)v11 = v9;
          v12 = Render::View::GetStateValues(view);
          mNext_high = HIDWORD(mNext[151].mNext);
          v12->mSetValueMask.mFlags[0] |= 0x8000ui64;
          v12->mParamValues[15] = v11;
          mMaterial = this->mMaterial;
          if ( LODWORD(mMaterial[1].mResourceHandles.UFG::qResourceData::mNode.mNext) != mNext_high )
          {
            UFG::qResourceHandle::Init(
              (UFG::qResourceHandle *)&mMaterial[1].mNode.mChild[1],
              mMaterial[1].mTypeUID,
              mNext_high);
            mOffset = mMaterial->mMaterialUser.mOffset;
            if ( mOffset )
              v16 = (_WORD *)((char *)&mMaterial->mMaterialUser + mOffset);
            else
              v16 = 0i64;
            *v16 |= 0x20u;
          }
          v17 = this->mMaterial;
          mPrev = (unsigned int)mNext[152].mPrev;
          if ( LODWORD(v17[1].mStateBlockMask.mFlags[0]) != mPrev )
          {
            UFG::qResourceHandle::Init(
              (UFG::qResourceHandle *)&v17[1].mDebugName[20],
              v17[1].mStateBlockMask.mFlags[1],
              mPrev);
            v19 = v17->mMaterialUser.mOffset;
            if ( v19 )
              v20 = (_WORD *)((char *)&v17->mMaterialUser + v19);
            else
              v20 = 0i64;
            *v20 |= 0x20u;
          }
          Render::View::DrawDebugPrim(view, DebugPrim_Triangle, (Render::vDynamic *)&mNext[7].mNext, v7);
        }
      }
      mNext = (UFG::qNode<Render::PolyStrip,Render::PolyStrip> *)v8;
    }
    while ( v8 != (Render::PolyStripManager *)&this->mStrips );
  }
}

