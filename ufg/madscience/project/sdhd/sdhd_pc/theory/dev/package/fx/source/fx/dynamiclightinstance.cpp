// File Line: 23
// RVA: 0x1C3230
void __fastcall Render::DynamicLightInstance::~DynamicLightInstance(Render::DynamicLightInstance *this)
{
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v3; // rax
  UFG::qNode<UFG::qSafePointerBase<Render::LightSafePointer>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<Render::LightSafePointer>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance> *v6; // rcx
  UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance> *v7; // rax

  this->vfptr = (Render::FXComponentInstanceVtbl *)&Render::DynamicLightInstance::`vftable;
  Render::DynamicLightInstance::Deactivate(this, 0);
  Inventory = `UFG::qGetResourceInventory<Render::DynamicLightSettings>::`2::result;
  if ( !`UFG::qGetResourceInventory<Render::DynamicLightSettings>::`2::result )
  {
    v3 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v3, 0xD6CD7114);
    `UFG::qGetResourceInventory<Render::DynamicLightSettings>::`2::result = Inventory;
  }
  UFG::qResourceHandle::Close(&this->mSettingsHandle, Inventory);
  UFG::qResourceHandle::~qResourceHandle(&this->mSettingsHandle);
  this->mLight.vfptr = (UFG::qSafePointerNode<Render::LightSafePointer>Vtbl *)&UFG::qSafePointerNode<Render::LightSafePointer>::`vftable;
  UFG::qSafePointerNode<UFG::DynamicCoverCorner>::SetAllPointersToNull((UFG::qSafePointerNode<UFG::ParkourHandle> *)&this->mLight);
  UFG::qList<UFG::qSafePointerBase<CanAttackConditionGroup>,UFG::qSafePointerNodeList,1,0>::DeleteNodes((UFG::qList<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList,1,0> *)&this->mLight.m_SafePointerList);
  mPrev = this->mLight.m_SafePointerList.mNode.mPrev;
  mNext = this->mLight.m_SafePointerList.mNode.mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->mLight.m_SafePointerList.mNode.mPrev = &this->mLight.m_SafePointerList.mNode;
  this->mLight.m_SafePointerList.mNode.mNext = &this->mLight.m_SafePointerList.mNode;
  this->vfptr = (Render::FXComponentInstanceVtbl *)&Render::FXComponentInstance::`vftable;
  v6 = this->mPrev;
  v7 = this->mNext;
  v6->mNext = v7;
  v7->mPrev = v6;
  this->mPrev = &this->UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance>;
  this->mNext = &this->UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance>;
}

// File Line: 28
// RVA: 0x1CE370
void __fastcall Render::DynamicLightInstance::Init(Render::DynamicLightInstance *this, unsigned int settingsId)
{
  bool v2; // zf
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v5; // rax
  UFG::qResourceInventory *v6; // rax
  unsigned int mSettingsId; // edi
  UFG::qResourceWarehouse *v8; // rax

  v2 = this->mSettingsHandle.mData == 0i64;
  this->mSettingsId = settingsId;
  if ( !v2 )
  {
    Inventory = `UFG::qGetResourceInventory<Render::DynamicLightSettings>::`2::result;
    if ( !`UFG::qGetResourceInventory<Render::DynamicLightSettings>::`2::result )
    {
      v5 = UFG::qResourceWarehouse::Instance();
      Inventory = UFG::qResourceWarehouse::GetInventory(v5, 0xD6CD7114);
      `UFG::qGetResourceInventory<Render::DynamicLightSettings>::`2::result = Inventory;
    }
    UFG::qResourceHandle::Close(&this->mSettingsHandle, Inventory);
  }
  v6 = `UFG::qGetResourceInventory<Render::DynamicLightSettings>::`2::result;
  mSettingsId = this->mSettingsId;
  if ( !`UFG::qGetResourceInventory<Render::DynamicLightSettings>::`2::result )
  {
    v8 = UFG::qResourceWarehouse::Instance();
    v6 = UFG::qResourceWarehouse::GetInventory(v8, 0xD6CD7114);
    `UFG::qGetResourceInventory<Render::DynamicLightSettings>::`2::result = v6;
  }
  UFG::qResourceHandle::Init(&this->mSettingsHandle, 0xD6CD7114, mSettingsId, v6);
  this->mIsFlickeringLightOn = 0;
  *(_QWORD *)&this->mFlickerLastChangeTime = 0i64;
  *(_QWORD *)&this->mFlickerOnColor.x = 0i64;
  *(_QWORD *)&this->mFlickerOnColor.z = 0i64;
  *(_QWORD *)&this->mFlickerOffColor.y = 0i64;
  this->mRadius = 0.0;
}

// File Line: 45
// RVA: 0x1C5620
void __fastcall Render::DynamicLightInstance::Activate(Render::DynamicLightInstance *this)
{
  UFG::qResourceInventory *Inventory; // rax
  unsigned int mSettingsId; // ebx
  UFG::qResourceWarehouse *v4; // rax
  UFG::qResourceData *mData; // rsi
  __int64 v6; // rbx
  float v7; // xmm6_4
  float v8; // xmm0_4
  float v9; // xmm1_4
  float v10; // xmm0_4
  Render::Light *p_light; // rsi
  __int64 size; // rdi
  unsigned int v13; // ebx
  unsigned int v14; // edx

  if ( !this->mIsActive )
  {
    if ( !this->mSettingsHandle.mData )
    {
      Inventory = `UFG::qGetResourceInventory<Render::DynamicLightSettings>::`2::result;
      mSettingsId = this->mSettingsId;
      if ( !`UFG::qGetResourceInventory<Render::DynamicLightSettings>::`2::result )
      {
        v4 = UFG::qResourceWarehouse::Instance();
        Inventory = UFG::qResourceWarehouse::GetInventory(v4, 0xD6CD7114);
        `UFG::qGetResourceInventory<Render::DynamicLightSettings>::`2::result = Inventory;
      }
      UFG::qResourceHandle::Init(&this->mSettingsHandle, 0xD6CD7114, mSettingsId, Inventory);
    }
    mData = this->mSettingsHandle.mData;
    if ( mData )
    {
      v6 = 0i64;
      *(_WORD *)&this->mIsActive = 1;
      this->mTimeOfFirstUpdate = 0.0;
      this->mLight.light.mType = 0;
      *(_QWORD *)&this->mLight.light.mColor.x = 0i64;
      this->mLight.light.mColor.z = 0.0;
      v7 = *(float *)&mData[2].mDebugName[16];
      v8 = UFG::qRandom(1.0, (unsigned int *)&UFG::qDefaultSeed);
      v9 = *(float *)&mData[2].mDebugName[20];
      *(_WORD *)&this->mLight.light.mShadowFlags = 0;
      this->mLight.light.mTextureUID = -1;
      v10 = (float)(v8 * (float)(v9 - v7)) + v7;
      this->mRadius = v10;
      this->mLight.light.mDecayRadius = v10;
      for ( this->mLight.light.mClipPlaneCount = BYTE6(mData[3].mResourceHandles.mNode.mPrev);
            (unsigned int)v6 < BYTE6(mData[3].mResourceHandles.mNode.mPrev);
            v6 = (unsigned int)(v6 + 1) )
      {
        this->mLight.light.mClipPlanes[v6] = *((_BYTE *)&mData[3].mResourceHandles.mNode.mPrev + v6);
      }
      this->mLight.light.mLightID = -1;
      p_light = &this->mLight.light;
      size = Render::gDynamicLightManager.mLights.size;
      v13 = Render::gDynamicLightManager.mLights.size + 1;
      if ( Render::gDynamicLightManager.mLights.size + 1 > Render::gDynamicLightManager.mLights.capacity )
      {
        if ( Render::gDynamicLightManager.mLights.capacity )
          v14 = 2 * Render::gDynamicLightManager.mLights.capacity;
        else
          v14 = 1;
        for ( ; v14 < v13; v14 *= 2 )
          ;
        if ( v14 <= 2 )
          v14 = 2;
        if ( v14 - v13 > 0x10000 )
          v14 = Render::gDynamicLightManager.mLights.size + 65537;
        UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(
          (UFG::qArray<UFG::qReflectInventoryBase *,0> *)&Render::gDynamicLightManager,
          v14,
          "qArray.Add");
      }
      Render::gDynamicLightManager.mLights.size = v13;
      Render::gDynamicLightManager.mLights.p[size] = p_light;
    }
  }
}

// File Line: 83
// RVA: 0x1CA950
void __fastcall Render::DynamicLightInstance::Deactivate(Render::DynamicLightInstance *this, bool willLoopImmediately)
{
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v4; // rax
  __int64 v5; // rcx
  Render::Light *p_light; // rbx
  Render::Light **i; // rax

  if ( this->mIsActive )
  {
    this->mIsActive = 0;
    Inventory = `UFG::qGetResourceInventory<Render::DynamicLightSettings>::`2::result;
    if ( !`UFG::qGetResourceInventory<Render::DynamicLightSettings>::`2::result )
    {
      v4 = UFG::qResourceWarehouse::Instance();
      Inventory = UFG::qResourceWarehouse::GetInventory(v4, 0xD6CD7114);
      `UFG::qGetResourceInventory<Render::DynamicLightSettings>::`2::result = Inventory;
    }
    UFG::qResourceHandle::Close(&this->mSettingsHandle, Inventory);
    *(_QWORD *)&this->mLight.light.mColor.x = 0i64;
    this->mLight.light.mColor.z = 0.0;
    if ( this->mIsSuspended )
    {
      this->mIsSuspended = 0;
    }
    else
    {
      v5 = 0i64;
      if ( Render::gDynamicLightManager.mLights.size )
      {
        p_light = &this->mLight.light;
        for ( i = Render::gDynamicLightManager.mLights.p; *i != p_light; ++i )
        {
          v5 = (unsigned int)(v5 + 1);
          if ( (unsigned int)v5 >= Render::gDynamicLightManager.mLights.size )
            return;
        }
        if ( Render::gDynamicLightManager.mLights.size <= 1
          || (Render::gDynamicLightManager.mLights.p[v5] = Render::gDynamicLightManager.mLights.p[Render::gDynamicLightManager.mLights.size
                                                                                                - 1],
              Render::gDynamicLightManager.mLights.size <= 1) )
        {
          Render::gDynamicLightManager.mLights.size = 0;
        }
        else
        {
          --Render::gDynamicLightManager.mLights.size;
        }
      }
    }
  }
}

// File Line: 98
// RVA: 0x1D17D0
void __fastcall Render::DynamicLightInstance::Loop(Render::DynamicLightInstance *this)
{
  UFG::qResourceData *mData; // rbx
  float v2; // xmm6_4

  mData = this->mSettingsHandle.mData;
  if ( mData )
  {
    v2 = *(float *)&mData[2].mDebugName[16];
    this->mRadius = (float)(UFG::qRandom(1.0, (unsigned int *)&UFG::qDefaultSeed)
                          * (float)(*(float *)&mData[2].mDebugName[20] - v2))
                  + v2;
  }
}

// File Line: 118
// RVA: 0x1DB8B0
void __fastcall Render::DynamicLightInstance::UpdateLight(
        Render::DynamicLightInstance *this,
        UFG::qVector3 *cam_pos,
        float sim_time)
{
  UFG::qResourceInventory *Inventory; // rax
  unsigned int mSettingsId; // edi
  UFG::qResourceWarehouse *v8; // rax
  Render::DynamicLightSettings *mData; // rdi
  float y; // xmm7_4
  float v11; // xmm9_4
  __m128 y_low; // xmm2
  float v13; // xmm0_4
  float x; // xmm1_4
  float v15; // xmm6_4
  Render::FXInstance *mContainer; // rax
  unsigned int mAnimType; // ecx
  unsigned int v18; // ecx
  float z; // xmm0_4
  UFG::qVector3 *updated; // rax
  UFG::qVector3 *v21; // rax
  float v22; // xmm0_4
  float v23; // xmm1_4
  char v24; // al
  UFG::qVector3 result; // [rsp+20h] [rbp-68h] BYREF
  UFG::qVector3 v26; // [rsp+30h] [rbp-58h] BYREF

  if ( !this->mSettingsHandle.mData )
  {
    Inventory = `UFG::qGetResourceInventory<Render::DynamicLightSettings>::`2::result;
    mSettingsId = this->mSettingsId;
    if ( !`UFG::qGetResourceInventory<Render::DynamicLightSettings>::`2::result )
    {
      v8 = UFG::qResourceWarehouse::Instance();
      Inventory = UFG::qResourceWarehouse::GetInventory(v8, 0xD6CD7114);
      `UFG::qGetResourceInventory<Render::DynamicLightSettings>::`2::result = Inventory;
    }
    UFG::qResourceHandle::Init(&this->mSettingsHandle, 0xD6CD7114, mSettingsId, Inventory);
  }
  mData = (Render::DynamicLightSettings *)this->mSettingsHandle.mData;
  if ( mData )
  {
    y = 0.0;
    if ( this->mTimeOfFirstUpdate == 0.0 )
      this->mTimeOfFirstUpdate = sim_time;
    v11 = (float)(sim_time - this->mStartTime) / (float)(this->mEndTime - this->mStartTime);
    Render::FXComponentInstance::GetBasis(this, &this->mLight.light.mTransform);
    y_low = (__m128)LODWORD(this->mLight.light.mTransform.v3.y);
    v13 = this->mLight.light.mTransform.v3.z - cam_pos->z;
    x = *(float *)&FLOAT_1_0;
    v15 = *(float *)&FLOAT_1_0;
    y_low.m128_f32[0] = (float)((float)((float)(y_low.m128_f32[0] - cam_pos->y) * (float)(y_low.m128_f32[0] - cam_pos->y))
                              + (float)((float)(this->mLight.light.mTransform.v3.x - cam_pos->x)
                                      * (float)(this->mLight.light.mTransform.v3.x - cam_pos->x)))
                      + (float)(v13 * v13);
    if ( _mm_sqrt_ps(y_low).m128_f32[0] > fade_in_distance_threshold )
    {
      mContainer = this->mContainer;
      if ( mContainer )
      {
        if ( mContainer->mLoop )
        {
          v15 = (float)(sim_time - this->mTimeOfFirstUpdate) / fade_in_duration;
          if ( v15 <= 0.0 )
          {
            v15 = 0.0;
          }
          else if ( v15 >= 1.0 )
          {
            v15 = *(float *)&FLOAT_1_0;
          }
        }
      }
    }
    mAnimType = mData->mAnimType;
    if ( mAnimType )
    {
      v18 = mAnimType - 1;
      if ( v18 )
      {
        if ( v18 == 1 )
        {
          updated = Render::DynamicLightInstance::UpdateFlickering(this, &result, mData, sim_time);
          x = updated->x;
          y = updated->y;
          z = updated->z;
        }
        else
        {
          z = 0.0;
        }
      }
      else
      {
        v21 = Render::DynamicLightInstance::ComputeLightColor(this, &v26, mData, v11);
        x = v21->x;
        y = v21->y;
        z = v21->z;
      }
    }
    else
    {
      x = mData->mColorKeys[0].x;
      y = mData->mColorKeys[0].y;
      z = mData->mColorKeys[0].z;
    }
    this->mLight.light.mColor.x = x * v15;
    this->mLight.light.mColor.y = y * v15;
    this->mLight.light.mColor.z = z * v15;
    Render::DynamicLightInstance::ComputeSize(this, &result, mData, v11);
    this->mLight.light.mDecayRadius = result.x * this->mRadius;
    this->mLight.light.mDecayPower = mData->mDecayPower;
    this->mLight.light.mSpecular = mData->mSpecular;
    if ( mData->mType == 1 )
    {
      v22 = result.z;
      v23 = result.y;
      v24 = 1;
      if ( mData->mLightshafts )
        v24 = 4;
      this->mLight.light.mType = v24;
      this->mLight.light.mShadowFlags = mData->mShadow;
      this->mLight.light.mShadowNear = mData->mShadowNear;
      this->mLight.light.mTextureUID = mData->mTextureUID;
      this->mLight.light.mFovHalfOuter = v22 * mData->mConeOuter;
      this->mLight.light.mFovHalfInner = v23 * mData->mConeInner;
    }
    else
    {
      this->mLight.light.mType = 0;
    }
    this->mLight.light.mTexDistAttenUID = -1;
  }
}

// File Line: 236
// RVA: 0x1DB5A0
UFG::qVector3 *__fastcall Render::DynamicLightInstance::UpdateFlickering(
        Render::DynamicLightInstance *this,
        UFG::qVector3 *result,
        Render::DynamicLightSettings *lfx,
        float sim_time)
{
  float v7; // xmm0_4
  bool v8; // zf
  float v9; // xmm9_4
  float v10; // xmm10_4
  float v11; // xmm11_4
  float v12; // xmm6_4
  float v13; // xmm7_4
  float v14; // xmm8_4
  float v15; // xmm0_4
  float x; // xmm9_4
  float y; // xmm10_4
  float z; // xmm11_4
  float v19; // xmm6_4
  float v20; // xmm7_4
  float v21; // xmm8_4
  float v22; // xmm0_4
  float mFlickerLastChangeTime; // xmm2_4
  float v24; // xmm1_4
  float v25; // xmm12_4
  UFG::qVector3 *v26; // rax
  float v27; // xmm5_4
  float v28; // xmm2_4
  float v29; // xmm4_4
  float v30; // xmm1_4
  float v31; // xmm3_4
  float v32; // xmm0_4

  if ( sim_time > this->mFlickerChangeTime )
  {
    this->mIsFlickeringLightOn = !this->mIsFlickeringLightOn;
    v7 = UFG::qRandom(1.0, (unsigned int *)&UFG::qDefaultSeed);
    v8 = !this->mIsFlickeringLightOn;
    this->mFlickerLastChangeTime = this->mFlickerChangeTime;
    if ( v8 )
    {
      this->mFlickerChangeTime = (float)((float)((float)(lfx->mMaxFlickerOffTime - lfx->mMinFlickerOffTime) * v7)
                                       + lfx->mMinFlickerOffTime)
                               + sim_time;
      x = lfx->mColorKeys[3].x;
      y = lfx->mColorKeys[3].y;
      z = lfx->mColorKeys[3].z;
      v19 = lfx->mColorKeys[2].x;
      v20 = lfx->mColorKeys[2].y;
      v21 = lfx->mColorKeys[2].z;
      v22 = UFG::qRandom(1.0, (unsigned int *)&UFG::qDefaultSeed);
      this->mFlickerOffColor.x = (float)((float)(x - v19) * v22) + v19;
      this->mFlickerOffColor.y = (float)((float)(y - v20) * v22) + v20;
      this->mFlickerOffColor.z = (float)((float)(z - v21) * v22) + v21;
    }
    else
    {
      this->mFlickerChangeTime = (float)((float)((float)(lfx->mMaxFlickerOnTime - lfx->mMinFlickerOnTime) * v7)
                                       + lfx->mMinFlickerOnTime)
                               + sim_time;
      v9 = lfx->mColorKeys[1].x;
      v10 = lfx->mColorKeys[1].y;
      v11 = lfx->mColorKeys[1].z;
      v12 = lfx->mColorKeys[0].x;
      v13 = lfx->mColorKeys[0].y;
      v14 = lfx->mColorKeys[0].z;
      v15 = UFG::qRandom(1.0, (unsigned int *)&UFG::qDefaultSeed);
      this->mFlickerOnColor.x = (float)((float)(v9 - v12) * v15) + v12;
      this->mFlickerOnColor.y = (float)((float)(v10 - v13) * v15) + v13;
      this->mFlickerOnColor.z = (float)((float)(v11 - v14) * v15) + v14;
    }
  }
  mFlickerLastChangeTime = this->mFlickerLastChangeTime;
  v24 = this->mFlickerChangeTime - mFlickerLastChangeTime;
  if ( v24 == 0.0 || (v25 = (float)(sim_time - mFlickerLastChangeTime) / v24, v25 >= 1.0) )
    v25 = *(float *)&FLOAT_1_0;
  v26 = result;
  if ( this->mIsFlickeringLightOn )
  {
    v27 = this->mFlickerOffColor.x;
    v28 = this->mFlickerOnColor.x;
    v29 = this->mFlickerOffColor.y;
    v30 = this->mFlickerOnColor.y;
    v31 = this->mFlickerOffColor.z;
    v32 = this->mFlickerOnColor.z;
  }
  else
  {
    v27 = this->mFlickerOnColor.x;
    v28 = this->mFlickerOffColor.x;
    v29 = this->mFlickerOnColor.y;
    v30 = this->mFlickerOffColor.y;
    v31 = this->mFlickerOnColor.z;
    v32 = this->mFlickerOffColor.z;
  }
  result->z = v31 + (float)((float)(v32 - v31) * v25);
  result->y = v29 + (float)((float)(v30 - v29) * v25);
  result->x = v27 + (float)((float)(v28 - v27) * v25);
  return v26;
}

// File Line: 282
// RVA: 0x1C8B60
UFG::qVector3 *__fastcall Render::DynamicLightInstance::ComputeLightColor(
        Render::DynamicLightInstance *this,
        UFG::qVector3 *result,
        Render::DynamicLightSettings *lfx,
        float lifetime)
{
  float v4; // xmm1_4
  float x; // xmm4_4
  float y; // xmm5_4
  float z; // xmm6_4
  float v8; // xmm0_4
  float v9; // xmm3_4
  float v10; // xmm1_4
  float v11; // xmm3_4
  float v12; // xmm0_4
  float v13; // xmm3_4
  UFG::qVector3 *v14; // rax

  v4 = lfx->mColorKeyPositions[0];
  if ( lifetime >= v4 )
  {
    v8 = lfx->mColorKeyPositions[1];
    if ( lifetime >= v8 )
    {
      v10 = lfx->mColorKeyPositions[2];
      if ( lifetime >= v10 )
      {
        v12 = lfx->mColorKeyPositions[3];
        if ( lifetime >= v12 )
        {
          x = lfx->mColorKeys[3].x;
          y = lfx->mColorKeys[3].y;
          z = lfx->mColorKeys[3].z;
        }
        else
        {
          v13 = (float)(lifetime - v10) / (float)(v12 - v10);
          x = lfx->mColorKeys[2].x + (float)((float)(lfx->mColorKeys[3].x - lfx->mColorKeys[2].x) * v13);
          y = lfx->mColorKeys[2].y + (float)((float)(lfx->mColorKeys[3].y - lfx->mColorKeys[2].y) * v13);
          z = lfx->mColorKeys[2].z + (float)((float)(lfx->mColorKeys[3].z - lfx->mColorKeys[2].z) * v13);
        }
      }
      else
      {
        v11 = (float)(lifetime - v8) / (float)(v10 - v8);
        x = lfx->mColorKeys[1].x + (float)((float)(lfx->mColorKeys[2].x - lfx->mColorKeys[1].x) * v11);
        y = lfx->mColorKeys[1].y + (float)((float)(lfx->mColorKeys[2].y - lfx->mColorKeys[1].y) * v11);
        z = lfx->mColorKeys[1].z + (float)((float)(lfx->mColorKeys[2].z - lfx->mColorKeys[1].z) * v11);
      }
    }
    else
    {
      v9 = (float)(lifetime - v4) / (float)(v8 - v4);
      x = lfx->mColorKeys[0].x + (float)((float)(lfx->mColorKeys[1].x - lfx->mColorKeys[0].x) * v9);
      y = lfx->mColorKeys[0].y + (float)((float)(lfx->mColorKeys[1].y - lfx->mColorKeys[0].y) * v9);
      z = lfx->mColorKeys[0].z + (float)((float)(lfx->mColorKeys[1].z - lfx->mColorKeys[0].z) * v9);
    }
  }
  else
  {
    x = lfx->mColorKeys[0].x;
    y = lfx->mColorKeys[0].y;
    z = lfx->mColorKeys[0].z;
  }
  result->z = z;
  result->x = x;
  v14 = result;
  result->y = y;
  return v14;
}

// File Line: 325
// RVA: 0x1C8D10
UFG::qVector3 *__fastcall Render::DynamicLightInstance::ComputeSize(
        Render::DynamicLightInstance *this,
        UFG::qVector3 *result,
        Render::DynamicLightSettings *settings,
        float dTime)
{
  float v4; // xmm1_4
  UFG::qVector3 *v6; // rax
  float v7; // xmm0_4
  float v8; // xmm3_4
  float v9; // xmm6_4
  float v10; // xmm0_4
  float v11; // xmm4_4
  float v12; // xmm1_4
  float v13; // xmm3_4
  float v14; // xmm6_4
  float v15; // xmm0_4
  float v16; // xmm4_4
  float v17; // xmm0_4
  float z; // xmm3_4
  float v19; // xmm6_4
  float v20; // xmm0_4
  float v21; // xmm4_4

  v4 = settings->mSizeKeyPositions[0];
  if ( dTime >= v4 )
  {
    v7 = settings->mSizeKeyPositions[1];
    if ( dTime >= v7 )
    {
      v12 = settings->mSizeKeyPositions[2];
      if ( dTime >= v12 )
      {
        v17 = settings->mSizeKeyPositions[3];
        if ( dTime >= v17 )
        {
          *result = settings->mSizeKeys[3];
          return result;
        }
        else
        {
          z = settings->mSizeKeys[2].z;
          v6 = result;
          v19 = (float)(dTime - v12) / (float)(v17 - v12);
          v20 = (float)(settings->mSizeKeys[3].z - z) * v19;
          v21 = settings->mSizeKeys[2].y + (float)((float)(settings->mSizeKeys[3].y - settings->mSizeKeys[2].y) * v19);
          result->x = settings->mSizeKeys[2].x
                    + (float)((float)(settings->mSizeKeys[3].x - settings->mSizeKeys[2].x) * v19);
          result->y = v21;
          result->z = z + v20;
        }
      }
      else
      {
        v13 = settings->mSizeKeys[1].z;
        v6 = result;
        v14 = (float)(dTime - v7) / (float)(v12 - v7);
        v15 = (float)(settings->mSizeKeys[2].z - v13) * v14;
        v16 = settings->mSizeKeys[1].y + (float)((float)(settings->mSizeKeys[2].y - settings->mSizeKeys[1].y) * v14);
        result->x = settings->mSizeKeys[1].x
                  + (float)((float)(settings->mSizeKeys[2].x - settings->mSizeKeys[1].x) * v14);
        result->y = v16;
        result->z = v13 + v15;
      }
    }
    else
    {
      v8 = settings->mSizeKeys[0].z;
      v6 = result;
      v9 = (float)(dTime - v4) / (float)(v7 - v4);
      v10 = (float)(settings->mSizeKeys[1].z - v8) * v9;
      v11 = settings->mSizeKeys[0].y + (float)((float)(settings->mSizeKeys[1].y - settings->mSizeKeys[0].y) * v9);
      result->x = settings->mSizeKeys[0].x + (float)((float)(settings->mSizeKeys[1].x - settings->mSizeKeys[0].x) * v9);
      result->y = v11;
      result->z = v8 + v10;
    }
  }
  else
  {
    *result = settings->mSizeKeys[0];
    return result;
  }
  return v6;
}

// File Line: 353
// RVA: 0x1D8C20
// attributes: thunk
void __fastcall Render::DynamicLightInstance::Update(
        Render::DynamicLightInstance *this,
        UFG::qVector3 *cam_pos,
        float sim_time)
{
  Render::DynamicLightInstance::UpdateLight(this, cam_pos, sim_time);
}

// File Line: 358
// RVA: 0x1C8180
void __fastcall Render::DynamicLightInstance::ChatlineLiveUpdate(Render::DynamicLightInstance *this)
{
  UFG::qResourceData *mData; // rsi
  unsigned int size; // edi
  __int64 v4; // rbx
  __int64 v5; // rdx
  Render::Light **p; // rax
  Render::Light *p_light; // rcx
  unsigned int v8; // ebp
  unsigned int v9; // edx
  float v10; // xmm6_4

  mData = this->mSettingsHandle.mData;
  if ( mData )
  {
    size = Render::gDynamicLightManager.mLights.size;
    v4 = 0i64;
    v5 = 0i64;
    if ( Render::gDynamicLightManager.mLights.size )
    {
      p = Render::gDynamicLightManager.mLights.p;
      p_light = &this->mLight.light;
      while ( *p != p_light )
      {
        v5 = (unsigned int)(v5 + 1);
        ++p;
        if ( (unsigned int)v5 >= Render::gDynamicLightManager.mLights.size )
          goto LABEL_11;
      }
      if ( Render::gDynamicLightManager.mLights.size <= 1
        || (Render::gDynamicLightManager.mLights.p[v5] = Render::gDynamicLightManager.mLights.p[Render::gDynamicLightManager.mLights.size
                                                                                              - 1],
            Render::gDynamicLightManager.mLights.size <= 1) )
      {
        size = 0;
        Render::gDynamicLightManager.mLights.size = 0;
      }
      else
      {
        size = --Render::gDynamicLightManager.mLights.size;
      }
    }
LABEL_11:
    v8 = size + 1;
    if ( size + 1 > Render::gDynamicLightManager.mLights.capacity )
    {
      if ( Render::gDynamicLightManager.mLights.capacity )
        v9 = 2 * Render::gDynamicLightManager.mLights.capacity;
      else
        v9 = 1;
      for ( ; v9 < v8; v9 *= 2 )
        ;
      if ( v9 <= 2 )
        v9 = 2;
      if ( v9 - v8 > 0x10000 )
        v9 = size + 65537;
      UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(
        (UFG::qArray<UFG::qReflectInventoryBase *,0> *)&Render::gDynamicLightManager,
        v9,
        "qArray.Add");
    }
    Render::gDynamicLightManager.mLights.size = size + 1;
    Render::gDynamicLightManager.mLights.p[size] = &this->mLight.light;
    v10 = *(float *)&mData[2].mDebugName[16];
    this->mRadius = (float)(UFG::qRandom(1.0, (unsigned int *)&UFG::qDefaultSeed)
                          * (float)(*(float *)&mData[2].mDebugName[20] - v10))
                  + v10;
    this->mLight.light.mClipPlaneCount = BYTE6(mData[3].mResourceHandles.mNode.mPrev);
    if ( BYTE6(mData[3].mResourceHandles.mNode.mPrev) )
    {
      do
      {
        this->mLight.light.mClipPlanes[v4] = *((_BYTE *)&mData[3].mResourceHandles.mNode.mPrev + v4);
        v4 = (unsigned int)(v4 + 1);
      }
      while ( (unsigned int)v4 < BYTE6(mData[3].mResourceHandles.mNode.mPrev) );
    }
  }
}

