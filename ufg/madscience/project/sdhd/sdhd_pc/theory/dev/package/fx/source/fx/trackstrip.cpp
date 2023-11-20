// File Line: 45
// RVA: 0x146B960
__int64 Render::_dynamic_initializer_for__gTrackStripSettingsInventory__()
{
  UFG::qResourceInventory::qResourceInventory(
    (UFG::qResourceInventory *)&Render::gTrackStripSettingsInventory.vfptr,
    "TrackStripSettingsInventory",
    0x69CE5438u,
    0x86DE69F6,
    0,
    0);
  Render::gTrackStripSettingsInventory.vfptr = (UFG::qResourceInventoryVtbl *)&Render::TrackStripSettingsInventory::`vftable;
  return atexit(Render::_dynamic_atexit_destructor_for__gTrackStripSettingsInventory__);
}

// File Line: 76
// RVA: 0x146B820
__int64 Render::_dynamic_initializer_for__gPolyStripManager__()
{
  UFG::qFixedAllocator::qFixedAllocator(&Render::gPolyStripManager.mAllocator);
  stru_142366970.mNode.mPrev = (UFG::qNode<UFG::qReflectField,UFG::qReflectField> *)&stru_142366970;
  stru_142366970.mNode.mNext = (UFG::qNode<UFG::qReflectField,UFG::qReflectField> *)&stru_142366970;
  _mm_store_si128((__m128i *)&unk_142366980, (__m128i)0i64);
  return atexit(Render::_dynamic_atexit_destructor_for__gPolyStripManager__);
}

// File Line: 91
// RVA: 0x1CF900
void __fastcall Render::PolyStripManager::Init(Render::PolyStripManager *this, int stripCount)
{
  Render::PolyStripManager *v2; // rbp
  unsigned int v3; // eax
  unsigned int v4; // esi
  UFG::qResourceData *v5; // rax
  UFG::qResourceWarehouse *v6; // rax
  unsigned int v7; // eax
  int v8; // eax
  Illusion::Material *v9; // rbx
  int v10; // edi
  int v11; // eax
  int v12; // eax
  Illusion::Material *v13; // rbx
  int v14; // edi
  int v15; // eax
  unsigned int v16; // eax
  Illusion::Material *v17; // rbx
  unsigned int v18; // edi
  unsigned int v19; // eax
  Illusion::Material *v20; // rbx
  int v21; // eax
  UFG::qResourceWarehouse *v22; // rax

  v2 = this;
  UFG::qFixedAllocator::Init(&this->mAllocator, 2448 * stripCount, 2448, "PolyStripManager::mAllocator", 0i64);
  v3 = UFG::qStringHashUpper32("PolyStripManager.RasterState", 0xFFFFFFFF);
  v4 = v3;
  v5 = Illusion::Factory::NewRasterState("PolyStripManager.RasterState", v3, 0i64, 0i64, 0i64);
  v2->mRasterState = (Illusion::RasterState *)v5;
  LOBYTE(v5[1].mNode.mParent) = 1;
  v2->mRasterState->mZWriteEnabled = 0;
  v2->mRasterState->mZFunction = 3;
  v2->mRasterState->mCullMode = 0;
  v2->mRasterState->mSEnabled = 0;
  v2->mRasterState->mSRefMask = 0;
  v2->mRasterState->mSRefBits = 0;
  v2->mRasterState->mSPassOperation = 0;
  v2->mRasterState->mSFailOperation = 0;
  v2->mRasterState->mSZFailOperation = 0;
  v2->mRasterState->mSFunction = 7;
  v6 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v6, (UFG::qResourceData *)&v2->mRasterState->mNode);
  v7 = UFG::qStringHash32("PolyStripManager.Material", 0xFFFFFFFF);
  v2->mMaterial = Illusion::Factory::NewMaterial("PolyStripManager.Material", v7, 4u, 0i64, 0i64, 0i64);
  v8 = UFG::qStringHashUpper32("DR_Skidmarks", 0xFFFFFFFF);
  v9 = v2->mMaterial;
  v10 = v8;
  LOWORD(v9[1].mNode.mChild[0]) = 0;
  HIDWORD(v9[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v11 = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v9[1].mTypeUID = -1957338719;
  LODWORD(v9[1].mResourceHandles.mNode.mNext) = v10;
  LODWORD(v9[1].mNode.mParent) = v11;
  v12 = UFG::qStringHashUpper32("SkidMark", 0xFFFFFFFF);
  v13 = v2->mMaterial;
  v14 = v12;
  *(_WORD *)&v13[1].mDebugName[12] = 0;
  *(_DWORD *)&v13[1].mDebugName[8] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v15 = UFG::qStringHash32("texDiffuse", 0xFFFFFFFF);
  LODWORD(v13[1].mStateBlockMask.mFlags[1]) = -1958479169;
  LODWORD(v13[1].mStateBlockMask.mFlags[0]) = v14;
  *(_DWORD *)&v13[1].mDebugName[4] = v15;
  v16 = UFG::qStringHashUpper32("7bfbac9f-c4f4-4b09-ab85-4156ad1feb91", 0xFFFFFFFF);
  v17 = v2->mMaterial;
  v18 = v16;
  LOWORD(v17[1].mMaterialUser.mOffset) = 0;
  *(&v17[1].mNumParams + 1) = UFG::qStringHash32("sbDepthBiasSortLayer", 0xFFFFFFFF);
  v19 = UFG::qStringHash32("sbDepthBiasSortLayer", 0xFFFFFFFF);
  LODWORD(v17[2].mResourceHandles.mNode.mPrev) = 1292158962;
  v17[2].mNode.mUID = v18;
  v17[1].mNumParams = v19;
  v20 = v2->mMaterial;
  LOWORD(v20[2].mTypeUID) = 0;
  HIDWORD(v20[2].mResourceHandles.mNode.mNext) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  v21 = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  *((_DWORD *)&v20[2].0 + 22) = 1002903008;
  LODWORD(v20[2].mResourceHandles.mNode.mNext) = v21;
  *(_DWORD *)&v20[2].mDebugName[28] = v4;
  v22 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v22, (UFG::qResourceData *)&v2->mMaterial->mNode);
}

// File Line: 149
// RVA: 0x1C73B0
Render::PolyStrip *__fastcall Render::PolyStripManager::AllocStrip(Render::PolyStripManager *this)
{
  Render::PolyStripManager *v1; // rdi
  UFG::qNode<Render::PolyStrip,Render::PolyStrip> *v2; // rdx
  UFG::qNode<Render::PolyStrip,Render::PolyStrip> *v3; // rax
  UFG::qNode<Render::PolyStrip,Render::PolyStrip> *v4; // rcx
  UFG::qNode<Render::PolyStrip,Render::PolyStrip> *v5; // rax
  char *v6; // rbx
  unsigned int v7; // ecx
  UFG::qNode<Render::PolyStrip,Render::PolyStrip> *v8; // rdx
  UFG::qNode<Render::PolyStrip,Render::PolyStrip> *v10; // [rsp+40h] [rbp+8h]

  v1 = this;
  if ( !this->mAllocator.mFreeListHead )
  {
    v10 = this->mStrips.mNode.mPrev;
    v2 = v10->mPrev;
    v3 = v10->mNext;
    v2->mNext = v3;
    v3->mPrev = v2;
    v10->mPrev = v10;
    v10->mNext = v10;
    v4 = v10->mPrev;
    v5 = v10->mNext;
    v4->mNext = v5;
    v5->mPrev = v4;
    v10->mPrev = v10;
    v10->mNext = v10;
    v10->mPrev = (UFG::qNode<Render::PolyStrip,Render::PolyStrip> *)v1->mAllocator.mFreeListHead;
    v1->mAllocator.mFreeListHead = (char *)v10;
    --v1->mAllocator.mNumSlotsAllocated;
  }
  v6 = v1->mAllocator.mFreeListHead;
  if ( v6 )
  {
    v1->mAllocator.mFreeListHead = *(char **)v6;
    v7 = ++v1->mAllocator.mNumSlotsAllocated;
    if ( v1->mAllocator.mMostSlotsAllocated > v7 )
      v7 = v1->mAllocator.mMostSlotsAllocated;
    v1->mAllocator.mMostSlotsAllocated = v7;
  }
  else
  {
    UFG::qFixedAllocator::ReportFull(&v1->mAllocator);
  }
  if ( v6 )
  {
    *(_QWORD *)v6 = v6;
    *((_QWORD *)v6 + 1) = v6;
    *((_QWORD *)v6 + 2) = 0i64;
    *((_DWORD *)v6 + 606) = 0;
    *((_QWORD *)v6 + 305) = 0i64;
  }
  v8 = v1->mStrips.mNode.mNext;
  v1->mStrips.mNode.mNext = (UFG::qNode<Render::PolyStrip,Render::PolyStrip> *)v6;
  *(_QWORD *)v6 = (char *)v1 + 48;
  *((_QWORD *)v6 + 1) = v8;
  v8->mPrev = (UFG::qNode<Render::PolyStrip,Render::PolyStrip> *)v6;
  return (Render::PolyStrip *)v6;
}

// File Line: 186
// RVA: 0x1D4FB0
void __fastcall Render::PolyStripManager::Render(Render::PolyStripManager *this, Render::View *view, float simTime)
{
  Render::PolyStripManager *v3; // rbp
  Render::View *v4; // r15
  Illusion::StateValues *v5; // rax
  UFG::qNode<Render::PolyStrip,Render::PolyStrip> *v6; // rdi
  int v7; // er14
  Render::PolyStripManager *v8; // rsi
  float v9; // xmm6_4
  float v10; // xmm1_4
  char *v11; // rbx
  Illusion::StateValues *v12; // rax
  unsigned int v13; // er8
  Illusion::Material *v14; // rbx
  __int64 v15; // rax
  _WORD *v16; // rax
  Illusion::Material *v17; // rbx
  unsigned int v18; // er8
  __int64 v19; // rax
  _WORD *v20; // rax
  Illusion::Material *material; // ST20_8

  v3 = this;
  v4 = view;
  v5 = Render::View::GetStateValues(view);
  v5->mSetValueMask.mFlags[0] |= 0x200ui64;
  v5->mParamValues[9] = 0i64;
  v6 = v3->mStrips.mNode.mNext;
  if ( v6 != (UFG::qNode<Render::PolyStrip,Render::PolyStrip> *)&v3->mStrips )
  {
    do
    {
      v7 = (int)v6[151].mNext;
      v8 = (Render::PolyStripManager *)v6->mNext;
      if ( v7 )
      {
        v9 = *(float *)&FLOAT_1_0;
        v10 = *((float *)&v6[152].mNext + 1) + *(float *)&v6[152].mNext;
        if ( simTime <= v10 || (v9 = 1.0 - (float)((float)(simTime - v10) * 0.33333334), v9 > 0.0) )
        {
          v11 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x80u, 0x10u);
          *(float *)v11 = v9;
          v12 = Render::View::GetStateValues(v4);
          v13 = HIDWORD(v6[151].mNext);
          v12->mSetValueMask.mFlags[0] |= 0x8000ui64;
          v12->mParamValues[15] = v11;
          v14 = v3->mMaterial;
          if ( LODWORD(v14[1].mResourceHandles.mNode.mNext) != v13 )
          {
            UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v14[1].mNode.mChild[1], v14[1].mTypeUID, v13);
            v15 = v14->mMaterialUser.mOffset;
            if ( v15 )
              v16 = (_WORD *)((char *)&v14->mMaterialUser + v15);
            else
              v16 = 0i64;
            *v16 |= 0x20u;
          }
          v17 = v3->mMaterial;
          v18 = (unsigned int)v6[152].mPrev;
          if ( LODWORD(v17[1].mStateBlockMask.mFlags[0]) != v18 )
          {
            UFG::qResourceHandle::Init(
              (UFG::qResourceHandle *)&v17[1].mDebugName[20],
              v17[1].mStateBlockMask.mFlags[1],
              v18);
            v19 = v17->mMaterialUser.mOffset;
            if ( v19 )
              v20 = (_WORD *)((char *)&v17->mMaterialUser + v19);
            else
              v20 = 0i64;
            *v20 |= 0x20u;
          }
          material = v3->mMaterial;
          Render::View::DrawDebugPrim(v4, DebugPrim_Triangle, (Render::vDynamic *)&v6[7].mNext, v7);
        }
      }
      v6 = (UFG::qNode<Render::PolyStrip,Render::PolyStrip> *)v8;
    }
    while ( v8 != (Render::PolyStripManager *)&v3->mStrips );
  }
}

