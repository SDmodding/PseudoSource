// File Line: 23
// RVA: 0x1C3230
void __fastcall Render::DynamicLightInstance::~DynamicLightInstance(Render::DynamicLightInstance *this)
{
  Render::DynamicLightInstance *v1; // rdi
  UFG::qResourceInventory *v2; // rax
  UFG::qResourceWarehouse *v3; // rax
  UFG::qList<UFG::qSafePointerBase<Render::LightSafePointer>,UFG::qSafePointerNodeList,1,0> *v4; // rbx
  UFG::qNode<UFG::qSafePointerBase<Render::LightSafePointer>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<Render::LightSafePointer>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance> *v7; // rdx
  UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance> *v8; // rcx
  UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance> *v9; // rax

  v1 = this;
  this->vfptr = (Render::FXComponentInstanceVtbl *)&Render::DynamicLightInstance::`vftable';
  Render::DynamicLightInstance::Deactivate(this, 0);
  v2 = `UFG::qGetResourceInventory<Render::DynamicLightSettings>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<Render::DynamicLightSettings>'::`2'::result )
  {
    v3 = UFG::qResourceWarehouse::Instance();
    v2 = UFG::qResourceWarehouse::GetInventory(v3, 0xD6CD7114);
    `UFG::qGetResourceInventory<Render::DynamicLightSettings>'::`2'::result = v2;
  }
  UFG::qResourceHandle::Close((UFG::qResourceHandle *)&v1->mSettingsHandle.mPrev, v2);
  UFG::qResourceHandle::~qResourceHandle((UFG::qResourceHandle *)&v1->mSettingsHandle.mPrev);
  v1->mLight.vfptr = (UFG::qSafePointerNode<Render::LightSafePointer>Vtbl *)&UFG::qSafePointerNode<Render::LightSafePointer>::`vftable';
  UFG::qSafePointerNode<UFG::DynamicCoverCorner>::SetAllPointersToNull((UFG::qSafePointerNode<UFG::ParkourHandle> *)&v1->mLight);
  v4 = &v1->mLight.m_SafePointerList;
  UFG::qList<UFG::qSafePointerBase<CanAttackConditionGroup>,UFG::qSafePointerNodeList,1,0>::DeleteNodes((UFG::qList<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList,1,0> *)&v1->mLight.m_SafePointerList);
  v5 = v1->mLight.m_SafePointerList.mNode.mPrev;
  v6 = v1->mLight.m_SafePointerList.mNode.mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v4->mNode.mPrev = &v4->mNode;
  v4->mNode.mNext = &v4->mNode;
  v1->vfptr = (Render::FXComponentInstanceVtbl *)&Render::FXComponentInstance::`vftable';
  v7 = (UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance> *)&v1->mPrev;
  v8 = v1->mPrev;
  v9 = v1->mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  v7->mPrev = v7;
  v7->mNext = v7;
}

// File Line: 28
// RVA: 0x1CE370
void __fastcall Render::DynamicLightInstance::Init(Render::DynamicLightInstance *this, unsigned int settingsId)
{
  bool v2; // zf
  Render::DynamicLightInstance *v3; // rbx
  UFG::qResourceInventory *v4; // rax
  UFG::qResourceWarehouse *v5; // rax
  UFG::qResourceInventory *v6; // rax
  unsigned int v7; // edi
  UFG::qResourceWarehouse *v8; // rax

  v2 = this->mSettingsHandle.mData == 0i64;
  v3 = this;
  this->mSettingsId = settingsId;
  if ( !v2 )
  {
    v4 = `UFG::qGetResourceInventory<Render::DynamicLightSettings>'::`2'::result;
    if ( !`UFG::qGetResourceInventory<Render::DynamicLightSettings>'::`2'::result )
    {
      v5 = UFG::qResourceWarehouse::Instance();
      v4 = UFG::qResourceWarehouse::GetInventory(v5, 0xD6CD7114);
      `UFG::qGetResourceInventory<Render::DynamicLightSettings>'::`2'::result = v4;
    }
    UFG::qResourceHandle::Close((UFG::qResourceHandle *)&v3->mSettingsHandle.mPrev, v4);
  }
  v6 = `UFG::qGetResourceInventory<Render::DynamicLightSettings>'::`2'::result;
  v7 = v3->mSettingsId;
  if ( !`UFG::qGetResourceInventory<Render::DynamicLightSettings>'::`2'::result )
  {
    v8 = UFG::qResourceWarehouse::Instance();
    v6 = UFG::qResourceWarehouse::GetInventory(v8, 0xD6CD7114);
    `UFG::qGetResourceInventory<Render::DynamicLightSettings>'::`2'::result = v6;
  }
  UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v3->mSettingsHandle.mPrev, 0xD6CD7114, v7, v6);
  v3->mIsFlickeringLightOn = 0;
  *(_QWORD *)&v3->mFlickerLastChangeTime = 0i64;
  *(_QWORD *)&v3->mFlickerOnColor.x = 0i64;
  *(_QWORD *)&v3->mFlickerOnColor.z = 0i64;
  *(_QWORD *)&v3->mFlickerOffColor.y = 0i64;
  v3->mRadius = 0.0;
}

// File Line: 45
// RVA: 0x1C5620
void __fastcall Render::DynamicLightInstance::Activate(Render::DynamicLightInstance *this)
{
  Render::DynamicLightInstance *v1; // rdi
  UFG::qResourceInventory *v2; // rax
  unsigned int v3; // ebx
  UFG::qResourceWarehouse *v4; // rax
  UFG::qResourceData *v5; // rsi
  __int64 v6; // rbx
  float v7; // xmm6_4
  float v8; // xmm0_4
  float v9; // xmm1_4
  float v10; // xmm0_4
  Render::Light *v11; // rsi
  __int64 v12; // rdi
  unsigned int v13; // ebx
  unsigned int v14; // edx

  v1 = this;
  if ( !this->mIsActive )
  {
    if ( !this->mSettingsHandle.mData )
    {
      v2 = `UFG::qGetResourceInventory<Render::DynamicLightSettings>'::`2'::result;
      v3 = this->mSettingsId;
      if ( !`UFG::qGetResourceInventory<Render::DynamicLightSettings>'::`2'::result )
      {
        v4 = UFG::qResourceWarehouse::Instance();
        v2 = UFG::qResourceWarehouse::GetInventory(v4, 0xD6CD7114);
        `UFG::qGetResourceInventory<Render::DynamicLightSettings>'::`2'::result = v2;
      }
      UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v1->mSettingsHandle.mPrev, 0xD6CD7114, v3, v2);
    }
    v5 = v1->mSettingsHandle.mData;
    if ( v5 )
    {
      v6 = 0i64;
      *(_WORD *)&v1->mIsActive = 1;
      v1->mTimeOfFirstUpdate = 0.0;
      v1->mLight.light.mType = 0;
      *(_QWORD *)&v1->mLight.light.mColor.x = 0i64;
      v1->mLight.light.mColor.z = 0.0;
      v7 = *(float *)&v5[2].mDebugName[16];
      v8 = UFG::qRandom(1.0, &UFG::qDefaultSeed);
      v9 = *(float *)&v5[2].mDebugName[20];
      *(_WORD *)&v1->mLight.light.mShadowFlags = 0;
      v1->mLight.light.mTextureUID = -1;
      v10 = (float)(v8 * (float)(v9 - v7)) + v7;
      v1->mRadius = v10;
      v1->mLight.light.mDecayRadius = v10;
      v1->mLight.light.mClipPlaneCount = BYTE6(v5[3].mResourceHandles.mNode.mPrev);
      if ( BYTE6(v5[3].mResourceHandles.mNode.mPrev) > 0u )
      {
        do
        {
          v1->mLight.light.mClipPlanes[v6] = *((_BYTE *)&v5[3].mResourceHandles.mNode.mPrev + v6);
          v6 = (unsigned int)(v6 + 1);
        }
        while ( (unsigned int)v6 < BYTE6(v5[3].mResourceHandles.mNode.mPrev) );
      }
      v1->mLight.light.mLightID = -1;
      v11 = &v1->mLight.light;
      v12 = Render::gDynamicLightManager.mLights.size;
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
      Render::gDynamicLightManager.mLights.p[v12] = v11;
    }
  }
}

// File Line: 83
// RVA: 0x1CA950
void __fastcall Render::DynamicLightInstance::Deactivate(Render::DynamicLightInstance *this, bool willLoopImmediately)
{
  Render::DynamicLightInstance *v2; // rbx
  UFG::qResourceInventory *v3; // rax
  UFG::qResourceWarehouse *v4; // rax
  __int64 v5; // rcx
  signed __int64 v6; // rbx
  Render::Light **v7; // rax

  v2 = this;
  if ( this->mIsActive )
  {
    this->mIsActive = 0;
    v3 = `UFG::qGetResourceInventory<Render::DynamicLightSettings>'::`2'::result;
    if ( !`UFG::qGetResourceInventory<Render::DynamicLightSettings>'::`2'::result )
    {
      v4 = UFG::qResourceWarehouse::Instance();
      v3 = UFG::qResourceWarehouse::GetInventory(v4, 0xD6CD7114);
      `UFG::qGetResourceInventory<Render::DynamicLightSettings>'::`2'::result = v3;
    }
    UFG::qResourceHandle::Close((UFG::qResourceHandle *)&v2->mSettingsHandle.mPrev, v3);
    *(_QWORD *)&v2->mLight.light.mColor.x = 0i64;
    v2->mLight.light.mColor.z = 0.0;
    if ( v2->mIsSuspended )
    {
      v2->mIsSuspended = 0;
    }
    else
    {
      v5 = 0i64;
      if ( Render::gDynamicLightManager.mLights.size )
      {
        v6 = (signed __int64)&v2->mLight.light;
        v7 = Render::gDynamicLightManager.mLights.p;
        while ( *v7 != (Render::Light *)v6 )
        {
          v5 = (unsigned int)(v5 + 1);
          ++v7;
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
  UFG::qResourceData *v1; // rbx
  float v2; // xmm6_4

  v1 = this->mSettingsHandle.mData;
  if ( v1 )
  {
    v2 = *(float *)&v1[2].mDebugName[16];
    this->mRadius = (float)(UFG::qRandom(1.0, &UFG::qDefaultSeed) * (float)(*(float *)&v1[2].mDebugName[20] - v2)) + v2;
  }
}

// File Line: 118
// RVA: 0x1DB8B0
void __fastcall Render::DynamicLightInstance::UpdateLight(Render::DynamicLightInstance *this, UFG::qVector3 *cam_pos, float sim_time)
{
  UFG::qVector3 *v3; // rsi
  float v4; // xmm8_4
  Render::DynamicLightInstance *v5; // rbx
  UFG::qResourceInventory *v6; // rax
  unsigned int v7; // edi
  UFG::qResourceWarehouse *v8; // rax
  Render::DynamicLightSettings *v9; // rdi
  float v10; // xmm7_4
  float v11; // xmm9_4
  __m128 v12; // xmm2
  float v13; // xmm0_4
  float v14; // xmm1_4
  float v15; // xmm6_4
  Render::FXInstance *v16; // rax
  unsigned int v17; // ecx
  int v18; // ecx
  float v19; // xmm0_4
  UFG::qVector3 *v20; // rax
  UFG::qVector3 *v21; // rax
  float v22; // xmm0_4
  float v23; // xmm1_4
  char v24; // al
  UFG::qVector3 result; // [rsp+20h] [rbp-68h]
  UFG::qVector3 v26; // [rsp+30h] [rbp-58h]

  v3 = cam_pos;
  v4 = sim_time;
  v5 = this;
  if ( !this->mSettingsHandle.mData )
  {
    v6 = `UFG::qGetResourceInventory<Render::DynamicLightSettings>'::`2'::result;
    v7 = this->mSettingsId;
    if ( !`UFG::qGetResourceInventory<Render::DynamicLightSettings>'::`2'::result )
    {
      v8 = UFG::qResourceWarehouse::Instance();
      v6 = UFG::qResourceWarehouse::GetInventory(v8, 0xD6CD7114);
      `UFG::qGetResourceInventory<Render::DynamicLightSettings>'::`2'::result = v6;
    }
    UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v5->mSettingsHandle.mPrev, 0xD6CD7114, v7, v6);
  }
  v9 = (Render::DynamicLightSettings *)v5->mSettingsHandle.mData;
  if ( v9 )
  {
    v10 = 0.0;
    if ( v5->mTimeOfFirstUpdate == 0.0 )
      v5->mTimeOfFirstUpdate = sim_time;
    v11 = (float)(sim_time - v5->mStartTime) / (float)(v5->mEndTime - v5->mStartTime);
    Render::FXComponentInstance::GetBasis((Render::FXComponentInstance *)&v5->vfptr, &v5->mLight.light.mTransform);
    v12 = (__m128)LODWORD(v5->mLight.light.mTransform.v3.y);
    v13 = v5->mLight.light.mTransform.v3.z - v3->z;
    v14 = *(float *)&FLOAT_1_0;
    v15 = *(float *)&FLOAT_1_0;
    v12.m128_f32[0] = (float)((float)((float)(v12.m128_f32[0] - v3->y) * (float)(v12.m128_f32[0] - v3->y))
                            + (float)((float)(v5->mLight.light.mTransform.v3.x - v3->x)
                                    * (float)(v5->mLight.light.mTransform.v3.x - v3->x)))
                    + (float)(v13 * v13);
    if ( COERCE_FLOAT(_mm_sqrt_ps(v12)) > fade_in_distance_threshold )
    {
      v16 = v5->mContainer;
      if ( v16 )
      {
        if ( v16->mLoop )
        {
          v15 = (float)(v4 - v5->mTimeOfFirstUpdate) / fade_in_duration;
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
    v17 = v9->mAnimType;
    if ( v17 )
    {
      v18 = v17 - 1;
      if ( v18 )
      {
        if ( v18 == 1 )
        {
          v20 = Render::DynamicLightInstance::UpdateFlickering(v5, &result, v9, v4);
          v14 = v20->x;
          v10 = v20->y;
          v19 = v20->z;
        }
        else
        {
          v19 = 0.0;
        }
      }
      else
      {
        v21 = Render::DynamicLightInstance::ComputeLightColor(v5, &v26, v9, v11);
        v14 = v21->x;
        v10 = v21->y;
        v19 = v21->z;
      }
    }
    else
    {
      v14 = v9->mColorKeys[0].x;
      v10 = v9->mColorKeys[0].y;
      v19 = v9->mColorKeys[0].z;
    }
    v5->mLight.light.mColor.x = v14 * v15;
    v5->mLight.light.mColor.y = v10 * v15;
    v5->mLight.light.mColor.z = v19 * v15;
    Render::DynamicLightInstance::ComputeSize(v5, &result, v9, v11);
    v5->mLight.light.mDecayRadius = result.x * v5->mRadius;
    v5->mLight.light.mDecayPower = v9->mDecayPower;
    v5->mLight.light.mSpecular = v9->mSpecular;
    if ( v9->mType == 1 )
    {
      v22 = result.z;
      v23 = result.y;
      v24 = 1;
      if ( v9->mLightshafts )
        v24 = 4;
      v5->mLight.light.mType = v24;
      v5->mLight.light.mShadowFlags = v9->mShadow;
      v5->mLight.light.mShadowNear = v9->mShadowNear;
      v5->mLight.light.mTextureUID = v9->mTextureUID;
      v5->mLight.light.mFovHalfOuter = v22 * v9->mConeOuter;
      v5->mLight.light.mFovHalfInner = v23 * v9->mConeInner;
    }
    else
    {
      v5->mLight.light.mType = 0;
    }
    v5->mLight.light.mTexDistAttenUID = -1;
  }
}

// File Line: 236
// RVA: 0x1DB5A0
UFG::qVector3 *__fastcall Render::DynamicLightInstance::UpdateFlickering(Render::DynamicLightInstance *this, UFG::qVector3 *result, Render::DynamicLightSettings *lfx, float sim_time)
{
  Render::DynamicLightSettings *v4; // rsi
  UFG::qVector3 *v5; // rdi
  Render::DynamicLightInstance *v6; // rbx
  float v7; // xmm0_4
  bool v8; // zf
  float v9; // xmm9_4
  float v10; // xmm10_4
  float v11; // xmm11_4
  float v12; // xmm6_4
  float v13; // xmm7_4
  float v14; // xmm8_4
  float v15; // xmm0_4
  float v16; // xmm9_4
  float v17; // xmm10_4
  float v18; // xmm11_4
  float v19; // xmm6_4
  float v20; // xmm7_4
  float v21; // xmm8_4
  float v22; // xmm0_4
  float v23; // xmm2_4
  float v24; // xmm1_4
  float v25; // xmm12_4
  UFG::qVector3 *v26; // rax
  float v27; // xmm5_4
  float v28; // xmm2_4
  float v29; // xmm4_4
  float v30; // xmm1_4
  float v31; // xmm3_4
  float v32; // xmm0_4

  v4 = lfx;
  v5 = result;
  v6 = this;
  if ( sim_time > this->mFlickerChangeTime )
  {
    this->mIsFlickeringLightOn = this->mIsFlickeringLightOn == 0;
    v7 = UFG::qRandom(1.0, &UFG::qDefaultSeed);
    v8 = v6->mIsFlickeringLightOn == 0;
    v6->mFlickerLastChangeTime = v6->mFlickerChangeTime;
    if ( v8 )
    {
      v6->mFlickerChangeTime = (float)((float)((float)(v4->mMaxFlickerOffTime - v4->mMinFlickerOffTime) * v7)
                                     + v4->mMinFlickerOffTime)
                             + sim_time;
      v16 = v4->mColorKeys[3].x;
      v17 = v4->mColorKeys[3].y;
      v18 = v4->mColorKeys[3].z;
      v19 = v4->mColorKeys[2].x;
      v20 = v4->mColorKeys[2].y;
      v21 = v4->mColorKeys[2].z;
      v22 = UFG::qRandom(1.0, &UFG::qDefaultSeed);
      v6->mFlickerOffColor.x = (float)((float)(v16 - v19) * v22) + v19;
      v6->mFlickerOffColor.y = (float)((float)(v17 - v20) * v22) + v20;
      v6->mFlickerOffColor.z = (float)((float)(v18 - v21) * v22) + v21;
    }
    else
    {
      v6->mFlickerChangeTime = (float)((float)((float)(v4->mMaxFlickerOnTime - v4->mMinFlickerOnTime) * v7)
                                     + v4->mMinFlickerOnTime)
                             + sim_time;
      v9 = v4->mColorKeys[1].x;
      v10 = v4->mColorKeys[1].y;
      v11 = v4->mColorKeys[1].z;
      v12 = v4->mColorKeys[0].x;
      v13 = v4->mColorKeys[0].y;
      v14 = v4->mColorKeys[0].z;
      v15 = UFG::qRandom(1.0, &UFG::qDefaultSeed);
      v6->mFlickerOnColor.x = (float)((float)(v9 - v12) * v15) + v12;
      v6->mFlickerOnColor.y = (float)((float)(v10 - v13) * v15) + v13;
      v6->mFlickerOnColor.z = (float)((float)(v11 - v14) * v15) + v14;
    }
  }
  v23 = v6->mFlickerLastChangeTime;
  v24 = v6->mFlickerChangeTime - v23;
  if ( v24 == 0.0 || (v25 = (float)(sim_time - v23) / v24, v25 >= 1.0) )
    v25 = *(float *)&FLOAT_1_0;
  v26 = v5;
  if ( v6->mIsFlickeringLightOn )
  {
    v27 = v6->mFlickerOffColor.x;
    v28 = v6->mFlickerOnColor.x;
    v29 = v6->mFlickerOffColor.y;
    v30 = v6->mFlickerOnColor.y;
    v31 = v6->mFlickerOffColor.z;
    v32 = v6->mFlickerOnColor.z;
  }
  else
  {
    v27 = v6->mFlickerOnColor.x;
    v28 = v6->mFlickerOffColor.x;
    v29 = v6->mFlickerOnColor.y;
    v30 = v6->mFlickerOffColor.y;
    v31 = v6->mFlickerOnColor.z;
    v32 = v6->mFlickerOffColor.z;
  }
  v5->z = v31 + (float)((float)(v32 - v31) * v25);
  v5->y = v29 + (float)((float)(v30 - v29) * v25);
  v5->x = v27 + (float)((float)(v28 - v27) * v25);
  return v26;
}

// File Line: 282
// RVA: 0x1C8B60
UFG::qVector3 *__fastcall Render::DynamicLightInstance::ComputeLightColor(Render::DynamicLightInstance *this, UFG::qVector3 *result, Render::DynamicLightSettings *lfx, float lifetime)
{
  float v4; // xmm1_4
  float v5; // xmm4_4
  float v6; // xmm5_4
  float v7; // xmm6_4
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
          v5 = lfx->mColorKeys[3].x;
          v6 = lfx->mColorKeys[3].y;
          v7 = lfx->mColorKeys[3].z;
        }
        else
        {
          v13 = (float)(lifetime - v10) / (float)(v12 - v10);
          v5 = lfx->mColorKeys[2].x + (float)((float)(lfx->mColorKeys[3].x - lfx->mColorKeys[2].x) * v13);
          v6 = lfx->mColorKeys[2].y + (float)((float)(lfx->mColorKeys[3].y - lfx->mColorKeys[2].y) * v13);
          v7 = lfx->mColorKeys[2].z + (float)((float)(lfx->mColorKeys[3].z - lfx->mColorKeys[2].z) * v13);
        }
      }
      else
      {
        v11 = (float)(lifetime - v8) / (float)(v10 - v8);
        v5 = lfx->mColorKeys[1].x + (float)((float)(lfx->mColorKeys[2].x - lfx->mColorKeys[1].x) * v11);
        v6 = lfx->mColorKeys[1].y + (float)((float)(lfx->mColorKeys[2].y - lfx->mColorKeys[1].y) * v11);
        v7 = lfx->mColorKeys[1].z + (float)((float)(lfx->mColorKeys[2].z - lfx->mColorKeys[1].z) * v11);
      }
    }
    else
    {
      v9 = (float)(lifetime - v4) / (float)(v8 - v4);
      v5 = lfx->mColorKeys[0].x + (float)((float)(lfx->mColorKeys[1].x - lfx->mColorKeys[0].x) * v9);
      v6 = lfx->mColorKeys[0].y + (float)((float)(lfx->mColorKeys[1].y - lfx->mColorKeys[0].y) * v9);
      v7 = lfx->mColorKeys[0].z + (float)((float)(lfx->mColorKeys[1].z - lfx->mColorKeys[0].z) * v9);
    }
  }
  else
  {
    v5 = lfx->mColorKeys[0].x;
    v6 = lfx->mColorKeys[0].y;
    v7 = lfx->mColorKeys[0].z;
  }
  result->z = v7;
  result->x = v5;
  v14 = result;
  result->y = v6;
  return v14;
}

// File Line: 325
// RVA: 0x1C8D10
UFG::qVector3 *__fastcall Render::DynamicLightInstance::ComputeSize(Render::DynamicLightInstance *this, UFG::qVector3 *result, Render::DynamicLightSettings *settings, float dTime)
{
  float v4; // xmm1_4
  float v5; // xmm6_4
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
  float v18; // xmm3_4
  float v19; // xmm6_4
  float v20; // xmm0_4
  float v21; // xmm4_4

  v4 = settings->mSizeKeyPositions[0];
  v5 = dTime;
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
          result->x = settings->mSizeKeys[3].x;
          result->y = settings->mSizeKeys[3].y;
          result->z = settings->mSizeKeys[3].z;
          v6 = result;
        }
        else
        {
          v18 = settings->mSizeKeys[2].z;
          v6 = result;
          v19 = (float)(v5 - v12) / (float)(v17 - v12);
          v20 = (float)(settings->mSizeKeys[3].z - v18) * v19;
          v21 = settings->mSizeKeys[2].y + (float)((float)(settings->mSizeKeys[3].y - settings->mSizeKeys[2].y) * v19);
          result->x = settings->mSizeKeys[2].x
                    + (float)((float)(settings->mSizeKeys[3].x - settings->mSizeKeys[2].x) * v19);
          result->y = v21;
          result->z = v18 + v20;
        }
      }
      else
      {
        v13 = settings->mSizeKeys[1].z;
        v6 = result;
        v14 = (float)(v5 - v7) / (float)(v12 - v7);
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
      v9 = (float)(v5 - v4) / (float)(v7 - v4);
      v10 = (float)(settings->mSizeKeys[1].z - v8) * v9;
      v11 = settings->mSizeKeys[0].y + (float)((float)(settings->mSizeKeys[1].y - settings->mSizeKeys[0].y) * v9);
      result->x = settings->mSizeKeys[0].x + (float)((float)(settings->mSizeKeys[1].x - settings->mSizeKeys[0].x) * v9);
      result->y = v11;
      result->z = v8 + v10;
    }
  }
  else
  {
    result->x = settings->mSizeKeys[0].x;
    result->y = settings->mSizeKeys[0].y;
    result->z = settings->mSizeKeys[0].z;
    v6 = result;
  }
  return v6;
}

// File Line: 353
// RVA: 0x1D8C20
void __fastcall Render::DynamicLightInstance::Update(Render::DynamicLightInstance *this, UFG::qVector3 *cam_pos, float sim_time)
{
  Render::DynamicLightInstance::UpdateLight(this, cam_pos, sim_time);
}

// File Line: 358
// RVA: 0x1C8180
void __fastcall Render::DynamicLightInstance::ChatlineLiveUpdate(Render::DynamicLightInstance *this)
{
  UFG::qResourceData *v1; // rsi
  Render::DynamicLightInstance *v2; // r14
  unsigned int v3; // edi
  __int64 v4; // rbx
  __int64 v5; // rdx
  Render::Light **v6; // rax
  Render::Light *v7; // rcx
  unsigned int v8; // ebp
  unsigned int v9; // edx
  float v10; // xmm6_4

  v1 = this->mSettingsHandle.mData;
  v2 = this;
  if ( v1 )
  {
    v3 = Render::gDynamicLightManager.mLights.size;
    v4 = 0i64;
    v5 = 0i64;
    if ( Render::gDynamicLightManager.mLights.size )
    {
      v6 = Render::gDynamicLightManager.mLights.p;
      v7 = &this->mLight.light;
      while ( *v6 != v7 )
      {
        v5 = (unsigned int)(v5 + 1);
        ++v6;
        if ( (unsigned int)v5 >= Render::gDynamicLightManager.mLights.size )
          goto LABEL_11;
      }
      if ( Render::gDynamicLightManager.mLights.size <= 1
        || (Render::gDynamicLightManager.mLights.p[v5] = Render::gDynamicLightManager.mLights.p[Render::gDynamicLightManager.mLights.size
                                                                                              - 1],
            Render::gDynamicLightManager.mLights.size <= 1) )
      {
        v3 = 0;
        Render::gDynamicLightManager.mLights.size = 0;
      }
      else
      {
        v3 = Render::gDynamicLightManager.mLights.size-- - 1;
      }
    }
LABEL_11:
    v8 = v3 + 1;
    if ( v3 + 1 > Render::gDynamicLightManager.mLights.capacity )
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
        v9 = v3 + 65537;
      UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(
        (UFG::qArray<UFG::qReflectInventoryBase *,0> *)&Render::gDynamicLightManager,
        v9,
        "qArray.Add");
    }
    Render::gDynamicLightManager.mLights.size = v3 + 1;
    Render::gDynamicLightManager.mLights.p[v3] = &v2->mLight.light;
    v10 = *(float *)&v1[2].mDebugName[16];
    v2->mRadius = (float)(UFG::qRandom(1.0, &UFG::qDefaultSeed) * (float)(*(float *)&v1[2].mDebugName[20] - v10)) + v10;
    v2->mLight.light.mClipPlaneCount = BYTE6(v1[3].mResourceHandles.mNode.mPrev);
    if ( BYTE6(v1[3].mResourceHandles.mNode.mPrev) > 0u )
    {
      do
      {
        v2->mLight.light.mClipPlanes[v4] = *((_BYTE *)&v1[3].mResourceHandles.mNode.mPrev + v4);
        v4 = (unsigned int)(v4 + 1);
      }
      while ( (unsigned int)v4 < BYTE6(v1[3].mResourceHandles.mNode.mPrev) );
    }
  }
}

